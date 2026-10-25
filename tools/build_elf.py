#!/usr/bin/env python3
from __future__ import annotations

import argparse
import csv
import json
import re
import subprocess
from dataclasses import dataclass
from pathlib import Path

from common import (
    GENERATED_DIR,
    REGISTRY_TSV,
    ROOT,
    SLPM_PATH,
    SymbolAlias,
    addr_to_file_offset,
    load_boundaries,
    load_elf_image,
    load_registry,
    load_symbol_aliases,
    load_units,
    mangle_cpp_signature,
    parse_elf_load_segments,
    parse_hex_addr,
    read_elf_vaddr,
    resolve_symbol_name,
    src_to_obj,
)

CACHE_PATH = ROOT / "out" / "generated" / "normalize_cache.json"
BUILD_INPUTS_CACHE_PATH = GENERATED_DIR / "build_inputs_cache.json"
CXX_SECTIONS_OUT = GENERATED_DIR / "cxx_sections.ld"
OBJECTS_MK_OUT = GENERATED_DIR / "objects.mk"
LAYOUT_STATUS_OUT = GENERATED_DIR / "layout_status.tsv"
SYMBOLS_LD_OUT = GENERATED_DIR / "symbols.ld"
FULL_LINKED_ELF = ROOT / "out" / "linked.tmp.elf"
INPUT_STAMP_SUFFIXES = {".c", ".cc", ".cp", ".cpp", ".cxx", ".h", ".hpp", ".s", ".S"}
SOURCE_SUFFIXES = {".c", ".cc", ".cp", ".cpp", ".cxx", ".s", ".S"}
HEADER_SUFFIXES = {".h", ".hpp"}

FUNC_ADDR_DECL_RE = re.compile(
    r"\b(func_([0-9a-fA-F]{8}))\s*\(([^{};]*)\)\s*(?:;|\{)"
)
D_ADDR_RE = re.compile(r"\b(D_([0-9a-fA-F]{8}))\b")
TYPE_KEYWORDS = {
    "void",
    "char",
    "short",
    "int",
    "long",
    "float",
    "double",
    "bool",
    "signed",
    "unsigned",
    "const",
    "volatile",
    "struct",
    "class",
    "enum",
}
TYPE_ALIASES = {
    "u8": "unsigned char",
    "u16": "unsigned short",
    "u32": "unsigned int",
    "u64": "unsigned long long",
    "s8": "signed char",
    "s16": "short",
    "s32": "int",
    "s64": "long long",
    "f32": "float",
    "f64": "double",
}
TYPE_KEYWORDS.update(TYPE_ALIASES.keys())


@dataclass(frozen=True)
class TextSym:
    addr: int
    size: int
    name: str
    foff: int = 0


@dataclass(frozen=True)
class ElfSection:
    name: str
    size: int
    flags: int


def parse_elf_function_symbols(path: Path, section_name: str | None = ".text") -> list[TextSym]:
    if not path.exists():
        return []
    data = path.read_bytes()
    if len(data) < 0x34 or data[:4] != b"\x7fELF":
        return []
    if data[4] != 1 or data[5] != 1:
        return []

    e_shoff = int.from_bytes(data[0x20:0x24], "little")
    e_shentsize = int.from_bytes(data[0x2E:0x30], "little")
    e_shnum = int.from_bytes(data[0x30:0x32], "little")
    e_shstrndx = int.from_bytes(data[0x32:0x34], "little")
    if (
        not e_shoff
        or not e_shentsize
        or not e_shnum
        or e_shstrndx >= e_shnum
        or e_shentsize < 0x28
    ):
        return []

    def sh_at(idx: int) -> tuple[int, int, int, int, int, int, int, int] | None:
        off = e_shoff + idx * e_shentsize
        if off + 0x28 > len(data):
            return None
        sh_name = int.from_bytes(data[off + 0x00 : off + 0x04], "little")
        sh_type = int.from_bytes(data[off + 0x04 : off + 0x08], "little")
        sh_addr = int.from_bytes(data[off + 0x0C : off + 0x10], "little")
        sh_offset = int.from_bytes(data[off + 0x10 : off + 0x14], "little")
        sh_size = int.from_bytes(data[off + 0x14 : off + 0x18], "little")
        sh_link = int.from_bytes(data[off + 0x18 : off + 0x1C], "little")
        sh_info = int.from_bytes(data[off + 0x1C : off + 0x20], "little")
        sh_entsize = int.from_bytes(data[off + 0x24 : off + 0x28], "little")
        return (sh_name, sh_type, sh_addr, sh_offset, sh_size, sh_link, sh_info, sh_entsize)

    shstr = sh_at(e_shstrndx)
    if shstr is None:
        return []
    _, _, _, shstr_off, shstr_size, _, _, _ = shstr
    if shstr_off + shstr_size > len(data):
        return []
    shstr_data = data[shstr_off : shstr_off + shstr_size]

    def sec_name(sh_name: int) -> str:
        if sh_name >= len(shstr_data):
            return ""
        end = shstr_data.find(b"\x00", sh_name)
        if end < 0:
            return ""
        return shstr_data[sh_name:end].decode("ascii", errors="ignore")

    text_idxs: set[int] | None = None
    text_idx = -1
    if section_name is not None:
        if section_name == ".text*":
            text_idxs = set()
            for i in range(e_shnum):
                sh = sh_at(i)
                if sh is None:
                    continue
                name = sec_name(sh[0])
                if name == ".text" or name.startswith(".text.") or name.startswith(".gnu.linkonce.t"):
                    text_idxs.add(i)
            if not text_idxs:
                return []
        else:
            for i in range(e_shnum):
                sh = sh_at(i)
                if sh is None:
                    continue
                if sec_name(sh[0]) == section_name:
                    text_idx = i
                    break
            if text_idx < 0:
                return []

    out: list[TextSym] = []
    for i in range(e_shnum):
        sh = sh_at(i)
        if sh is None:
            continue
        sh_name, sh_type, sh_addr, sh_off, sh_size, sh_link, _sh_info, sh_entsize = sh
        _ = sh_name
        if sh_type != 2 or sh_entsize < 16:
            continue
        if sh_off + sh_size > len(data):
            continue
        str_sh = sh_at(sh_link)
        if str_sh is None:
            continue
        _, _, _, str_off, str_size, _, _, _ = str_sh
        if str_off + str_size > len(data):
            continue
        strtab = data[str_off : str_off + str_size]
        for off in range(sh_off, sh_off + sh_size, sh_entsize):
            if off + 16 > len(data):
                break
            st_name = int.from_bytes(data[off + 0x00 : off + 0x04], "little")
            st_value = int.from_bytes(data[off + 0x04 : off + 0x08], "little")
            st_size = int.from_bytes(data[off + 0x08 : off + 0x0C], "little")
            st_info = data[off + 0x0C]
            st_shndx = int.from_bytes(data[off + 0x0E : off + 0x10], "little")
            if (st_info & 0x0F) != 2:
                continue
            if st_size <= 0:
                continue
            if text_idxs is not None and st_shndx not in text_idxs:
                continue
            if text_idxs is None and section_name is not None and st_shndx != text_idx:
                continue
            if st_shndx == 0:
                continue
            if st_name >= len(strtab):
                continue
            end = strtab.find(b"\x00", st_name)
            if end < 0:
                continue
            name = strtab[st_name:end].decode("ascii", errors="ignore")
            if not name:
                continue
            target_sh = sh_at(st_shndx)
            if target_sh is None:
                continue
            _, _, target_addr, target_off, target_size, _, _, _ = target_sh
            rel = st_value - target_addr
            if rel < 0 or rel + st_size > target_size:
                continue
            foff = target_off + rel
            out.append(TextSym(addr=st_value, size=st_size, name=name, foff=foff))
    out.sort(key=lambda x: (x.addr, x.size, x.name))
    return out


def load_alloc_sections(path: Path) -> list[ElfSection]:
    if not path.exists():
        return []
    data = path.read_bytes()
    if len(data) < 0x34 or data[:4] != b"\x7fELF":
        return []
    if data[4] != 1 or data[5] != 1:
        return []

    e_shoff = int.from_bytes(data[0x20:0x24], "little")
    e_shentsize = int.from_bytes(data[0x2E:0x30], "little")
    e_shnum = int.from_bytes(data[0x30:0x32], "little")
    e_shstrndx = int.from_bytes(data[0x32:0x34], "little")
    if (
        not e_shoff
        or not e_shentsize
        or not e_shnum
        or e_shstrndx >= e_shnum
        or e_shentsize < 0x28
    ):
        return []

    def sh_at(idx: int) -> tuple[int, int, int, int, int, int, int, int] | None:
        off = e_shoff + idx * e_shentsize
        if off + 0x28 > len(data):
            return None
        sh_name = int.from_bytes(data[off + 0x00 : off + 0x04], "little")
        sh_type = int.from_bytes(data[off + 0x04 : off + 0x08], "little")
        sh_flags = int.from_bytes(data[off + 0x08 : off + 0x0C], "little")
        sh_addr = int.from_bytes(data[off + 0x0C : off + 0x10], "little")
        sh_offset = int.from_bytes(data[off + 0x10 : off + 0x14], "little")
        sh_size = int.from_bytes(data[off + 0x14 : off + 0x18], "little")
        sh_link = int.from_bytes(data[off + 0x18 : off + 0x1C], "little")
        sh_info = int.from_bytes(data[off + 0x1C : off + 0x20], "little")
        return (sh_name, sh_type, sh_flags, sh_addr, sh_offset, sh_size, sh_link, sh_info)

    shstr = sh_at(e_shstrndx)
    if shstr is None:
        return []
    _, _, _, _, shstr_off, shstr_size, _, _ = shstr
    if shstr_off + shstr_size > len(data):
        return []
    shstr_data = data[shstr_off : shstr_off + shstr_size]

    def sec_name(sh_name: int) -> str:
        if sh_name >= len(shstr_data):
            return ""
        end = shstr_data.find(b"\x00", sh_name)
        if end < 0:
            return ""
        return shstr_data[sh_name:end].decode("ascii", errors="ignore")

    out: list[ElfSection] = []
    for i in range(e_shnum):
        sh = sh_at(i)
        if sh is None:
            continue
        sh_name, _sh_type, sh_flags, _sh_addr, _sh_offset, sh_size, _sh_link, _sh_info = sh
        if sh_size <= 0 or (sh_flags & 0x2) == 0:
            continue
        name = sec_name(sh_name)
        if not name:
            continue
        out.append(ElfSection(name=name, size=sh_size, flags=sh_flags))
    return out


def load_text_symbols(path: Path) -> list[TextSym]:
    return parse_elf_function_symbols(path, None)


def load_obj_text_symbols(path: Path) -> list[TextSym]:
    return parse_elf_function_symbols(path, ".text*")


def pick_obj_symbol(obj_syms: list[TextSym], symbol: str, addr: int) -> TextSym | None:
    by_name = {s.name: s for s in obj_syms}
    if symbol:
        hit = by_name.get(symbol)
        if hit is not None:
            return hit
    token = f"func_{addr:08x}"
    matches = [s for s in obj_syms if token in s.name]
    if matches:
        matches.sort(key=lambda s: (s.addr, s.size, s.name))
        return matches[0]
    return None


def compute_incremental_state(
    out_elf: Path,
) -> tuple[dict[int, object], dict[str, list[tuple[int, str]]], dict, dict, dict[str, list[int] | None], set[str], bool]:
    boundaries, _layout_sources, _symbol_map, by_source = load_cxx_rows()
    layout_state = {
        "layout_status": _path_stamp(LAYOUT_STATUS_OUT),
        "registry": _path_stamp(REGISTRY_TSV),
        "units": _path_stamp(ROOT / "linked_units.tsv"),
    }
    cache = _load_cache()
    incremental = (
        cache.get("layout_state") == layout_state
        and out_elf.exists()
        and out_elf.stat().st_size == SLPM_PATH.stat().st_size
    )
    current_stamps: dict[str, list[int] | None] = {}
    changed_sources: set[str] = set()
    for source in sorted(by_source.keys()):
        obj = ROOT / src_to_obj(source)
        current_stamps[source] = _path_stamp(obj)
        if not incremental:
            changed_sources.add(source)
            continue
        if cache.get("obj_stamps", {}).get(source) != current_stamps[source]:
            changed_sources.add(source)
    return boundaries, by_source, layout_state, cache, current_stamps, changed_sources, incremental


def _path_stamp(path: Path) -> list[int] | None:
    if not path.exists():
        return None
    st = path.stat()
    return [st.st_mtime_ns, st.st_size]


def _load_cache() -> dict:
    if not CACHE_PATH.exists():
        return {}
    try:
        return json.loads(CACHE_PATH.read_text())
    except Exception:
        return {}


def _save_cache(data: dict) -> None:
    CACHE_PATH.parent.mkdir(parents=True, exist_ok=True)
    CACHE_PATH.write_text(json.dumps(data, sort_keys=True))


def iter_build_inputs() -> list[Path]:
    inputs: list[Path] = []
    for base in (ROOT / "src", ROOT / "include"):
        if not base.exists():
            continue
        for path in base.rglob("*"):
            if path.is_file() and path.suffix in INPUT_STAMP_SUFFIXES:
                inputs.append(path)
    inputs.sort(key=lambda path: path.as_posix())
    return inputs


def invalidate_build_outputs(changed_paths: list[Path]) -> None:
    if not changed_paths:
        return

    changed_headers = any(path.suffix in HEADER_SUFFIXES for path in changed_paths)
    if changed_headers:
        build_root = ROOT / "out" / "build"
        if build_root.exists():
            for obj in build_root.rglob("*.o"):
                obj.unlink()
        return

    for path in changed_paths:
        if path.suffix not in SOURCE_SUFFIXES:
            continue
        rel = path.relative_to(ROOT)
        try:
            obj = ROOT / src_to_obj(rel.as_posix())
        except ValueError:
            if rel.suffix in {".cc", ".cp", ".cxx"}:
                obj = ROOT / "out" / "build" / rel.with_suffix(".o")
            else:
                raise
        if obj.exists():
            obj.unlink()


def write_inputs_stamp(out_path: Path) -> int:
    cached_files: dict[str, list[int] | None] = {}
    if BUILD_INPUTS_CACHE_PATH.exists():
        try:
            cached = json.loads(BUILD_INPUTS_CACHE_PATH.read_text())
            if isinstance(cached, dict) and isinstance(cached.get("files"), dict):
                cached_files = {
                    str(path): file_stamp
                    for path, file_stamp in cached["files"].items()
                }
        except Exception:
            cached_files = {}

    current_files: dict[str, list[int] | None] = {}
    changed_paths: list[Path] = []
    for path in iter_build_inputs():
        rel_path = path.relative_to(ROOT).as_posix()
        current_files[rel_path] = _path_stamp(path)
        if cached_files.get(rel_path) != current_files[rel_path]:
            changed_paths.append(path)
    for rel_path in cached_files.keys() - current_files.keys():
        changed_paths.append(ROOT / rel_path)

    if current_files == cached_files and out_path.exists():
        return 0

    invalidate_build_outputs(changed_paths)
    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.touch()
    BUILD_INPUTS_CACHE_PATH.write_text(
        json.dumps({"files": current_files}, indent=2, sort_keys=True) + "\n"
    )
    return 0


def _drop_param_name(p: str) -> str:
    m = re.match(r"^(.*?)([A-Za-z_][A-Za-z0-9_]*)$", p)
    if not m:
        return p
    head = m.group(1).rstrip()
    name = m.group(2)
    if name in TYPE_KEYWORDS:
        return p
    if head and (head[-1] in "*&" or any(k in head.split() for k in TYPE_KEYWORDS)):
        return head
    return p


def _normalize_param_type(param: str) -> str:
    p = param.strip()
    if not p:
        return ""
    p = p.split("=", 1)[0].strip()
    if not p:
        return ""
    p = re.sub(r"\s+", " ", p)
    if p == "unsigned":
        return "unsigned int"
    if p == "signed":
        return "int"

    p = _drop_param_name(p).strip()
    p = re.sub(r"(?<![A-Za-z0-9_])unsigned(?!\s+(?:char|short|int|long))", "unsigned int", p)
    p = re.sub(r"(?<![A-Za-z0-9_])signed(?!\s+(?:char|short|int|long))", "int", p)
    for alias, actual in TYPE_ALIASES.items():
        p = re.sub(rf"\b{alias}\b", actual, p)
    p = re.sub(r"\s+", " ", p)
    return _drop_param_name(p)


def collect_source_addr_aliases() -> list[SymbolAlias]:
    aliases: dict[str, int] = {}
    src_root = ROOT / "src"
    if not src_root.exists():
        return []

    source_paths: list[Path] = []
    for pattern in ("*.cpp", "*.c", "*.hpp", "*.h"):
        source_paths.extend(src_root.rglob(pattern))

    for src in sorted(set(source_paths)):
        text = src.read_text(errors="ignore")
        for dm in D_ADDR_RE.finditer(text):
            name = dm.group(1)
            addr = int(dm.group(2), 16)
            prev = aliases.get(name)
            if prev is not None and prev != addr:
                raise ValueError(f"source alias conflict for {name}: 0x{prev:08x} vs 0x{addr:08x}")
            aliases[name] = addr

        for m in FUNC_ADDR_DECL_RE.finditer(text):
            name = m.group(1)
            addr = int(m.group(2), 16)
            args_raw = m.group(3).strip()

            prev = aliases.get(name)
            if prev is not None and prev != addr:
                raise ValueError(f"source alias conflict for {name}: 0x{prev:08x} vs 0x{addr:08x}")
            aliases[name] = addr

            if not args_raw or args_raw == "void":
                sig = f"{name}()"
            else:
                params: list[str] = []
                ok = True
                for raw in args_raw.split(","):
                    t = _normalize_param_type(raw)
                    if not t:
                        ok = False
                        break
                    params.append(t)
                if not ok:
                    continue
                sig = f"{name}({','.join(params)})"

            try:
                mangled = mangle_cpp_signature(sig)
            except ValueError:
                continue

            prev = aliases.get(mangled)
            if prev is not None and prev != addr:
                raise ValueError(f"source alias conflict for {mangled}: 0x{prev:08x} vs 0x{addr:08x}")
            aliases[mangled] = addr

    out = [SymbolAlias(name=name, addr=addr) for name, addr in aliases.items()]
    out.sort(key=lambda x: (x.addr, x.name))
    return out


LIBGCC_ALIASES = (
    ("__divdi3", 0x003125C0),
    ("__udivdi3", 0x00312DB8),
    ("__umoddi3", 0x00313498),
    ("__muldi3", 0x00311AA0),
)


def write_symbols_ld(path: Path) -> int:
    by_name: dict[str, int] = {}
    for alias in load_symbol_aliases(REGISTRY_TSV):
        by_name[alias.name] = alias.addr
    for alias in collect_source_addr_aliases():
        prev = by_name.get(alias.name)
        if prev is not None and prev != alias.addr:
            raise ValueError(f"symbol alias conflict for {alias.name}: 0x{prev:08x} vs 0x{alias.addr:08x}")
        by_name[alias.name] = alias.addr

    aliases = [SymbolAlias(name=name, addr=addr) for name, addr in by_name.items()]
    aliases.sort(key=lambda x: (x.addr, x.name))
    lines = ["/* Auto-generated by tools/build_elf.py */\n"]
    for alias in aliases:
        lines.append(f"PROVIDE({alias.name} = 0x{alias.addr:08x});\n")
    # libgcc helpers the compiler calls implicitly (u64 / u64 etc.): bind them to
    # the game's own copies so -lgcc never links a second one.
    for name, addr in LIBGCC_ALIASES:
        lines.append(f"{name} = 0x{addr:08x};\n")
    path.write_text("".join(lines))
    return len(aliases)


def generate_layout_outputs() -> int:
    boundaries = load_boundaries()
    registry = load_registry(REGISTRY_TSV)
    units = load_units()

    GENERATED_DIR.mkdir(parents=True, exist_ok=True)

    objects: list[str] = []
    status_rows: list[str] = []
    cxx_objs_seen: set[str] = set()

    for boundary in boundaries:
        unit = next((u for u in units if u.contains(boundary.addr)), None)
        if unit is not None:
            # A linked unit owns every function in its range, whatever the registry says.
            if not (ROOT / unit.source).exists():
                raise FileNotFoundError(f"missing source for unit: {unit.source}")
            obj = src_to_obj(unit.source)
            if obj not in cxx_objs_seen:
                objects.append(obj)
                cxx_objs_seen.add(obj)
            status_rows.append(f"{boundary.addr:08x}\tcxx\t{unit.source}\n")
            continue
        entry = registry.get(boundary.addr)
        if entry is not None and entry.mode == "cxx":
            src = ROOT / entry.source
            if not src.exists():
                raise FileNotFoundError(f"missing source for 0x{boundary.addr:08x}: {src}")

            obj = src_to_obj(entry.source)
            if obj not in cxx_objs_seen:
                objects.append(obj)
                cxx_objs_seen.add(obj)
            status_rows.append(f"{boundary.addr:08x}\tcxx\t{entry.source}\n")
        else:
            status_rows.append(f"{boundary.addr:08x}\tasm\t\n")

    OBJECTS_MK_OUT.write_text(
        "# Auto-generated by tools/build_elf.py\n"
        + "ORDERED_OBJS :=\n"
        + "".join(f"ORDERED_OBJS += {obj}\n" for obj in objects)
        # Linked units are compiled whole (functions stay in source order in one .text).
        + "".join(f"{src_to_obj(u.source)}: UNIT_FLAGS := -fno-function-sections {u.flags}\n"
                  f"{src_to_obj(u.source)}: linked_units.tsv\n" for u in units)
    )
    LAYOUT_STATUS_OUT.write_text("addr\tmode\tsource\n" + "".join(status_rows))
    write_symbols_ld(SYMBOLS_LD_OUT)
    return 0


def load_layout_cxx_sources() -> dict[int, str]:
    path = LAYOUT_STATUS_OUT
    if not path.exists():
        raise FileNotFoundError(f"missing generated layout status: {path}")
    out: dict[int, str] = {}
    with path.open(newline="") as f:
        reader = csv.DictReader(f, delimiter="\t")
        for row in reader:
            if (row.get("mode") or "").strip().lower() != "cxx":
                continue
            addr_text = (row.get("addr") or "").strip()
            source = (row.get("source") or "").strip()
            if not addr_text or not source:
                continue
            out[parse_hex_addr(addr_text)] = source
    return out


def load_symbol_map() -> dict[int, str]:
    out: dict[int, str] = {}
    if not REGISTRY_TSV.exists():
        return out
    for line in REGISTRY_TSV.read_text().splitlines():
        s = line.strip()
        if not s or s.startswith("#"):
            continue
        parts = s.split("\t")
        if len(parts) != 2:
            continue
        sym = parts[0].strip()
        addr_text = parts[1].strip()
        if not sym or not addr_text:
            continue
        try:
            addr = parse_hex_addr(addr_text)
            sym = resolve_symbol_name(sym)
        except ValueError:
            continue
        out[addr] = sym
    return out


def load_cxx_rows() -> tuple[dict[int, object], dict[int, str], dict[int, str], dict[str, list[tuple[int, str]]]]:
    boundaries = {b.addr: b for b in load_boundaries()}
    layout_sources = load_layout_cxx_sources()
    symbol_map = load_symbol_map()
    by_source: dict[str, list[tuple[int, str]]] = {}
    for addr, source in sorted(layout_sources.items()):
        if addr not in boundaries:
            continue
        by_source.setdefault(source, []).append((addr, symbol_map.get(addr, f"func_{addr:08x}")))
    return boundaries, layout_sources, symbol_map, by_source


def section_patterns(sym: str) -> list[str]:
    return [f".text.{sym}", f".gnu.linkonce.t.{sym}"]


def generate_link_sections() -> int:
    boundaries, _layout_sources, _symbol_map, by_source = load_cxx_rows()
    units = load_units()
    unit_sources = {u.source for u in units}
    obj_syms_cache: dict[Path, list[TextSym]] = {}
    placed: list[tuple[int, str]] = []

    lines = ["/* Auto-generated by tools/build_elf.py. */\n"]
    # Linked units: the object's whole .text at the unit start, other sections at their own address.
    for u in units:
        obj = src_to_obj(u.source)
        lines.append(f"  .kh2unit_{u.start:08x} 0x{u.start:08x} : {{\n    KEEP({obj}(.text))\n  }}\n")
        for sec, addr in u.sections:
            lines.append(f"  .kh2unit_{u.start:08x}{sec.replace('.', '_')} 0x{addr:08x} : {{\n"
                         f"    KEEP({obj}({sec}))\n  }}\n")

    for source, rows in sorted(by_source.items()):
        if source in unit_sources:
            continue
        obj = ROOT / src_to_obj(source)
        obj_syms = obj_syms_cache.get(obj)
        if obj_syms is None:
            obj_syms = load_obj_text_symbols(obj)
            obj_syms_cache[obj] = obj_syms

        for addr, symbol in sorted(rows):
            if addr not in boundaries:
                continue
            obj_sym = pick_obj_symbol(obj_syms, symbol, addr)
            if obj_sym is None:
                continue
            placed.append((addr, obj_sym.name))

    for addr, sym in placed:
        lines.append(f"  .kh2cxx_{addr:08x} 0x{addr:08x} : {{\n")
        for pattern in section_patterns(sym):
            lines.append(f"    KEEP(*({pattern}))\n")
        lines.append("  }\n")

    CXX_SECTIONS_OUT.parent.mkdir(parents=True, exist_ok=True)
    CXX_SECTIONS_OUT.write_text("".join(lines))
    return 0


def generate_objects_mk() -> int:
    return generate_layout_outputs()


def _is_fast_link_eligible_section(section: ElfSection) -> bool:
    return (
        section.name == ".reginfo"
        or section.name == ".text"
        or section.name.startswith(".text.")
        or section.name.startswith(".gnu.linkonce.t")
    )


def try_fast_link(linked_elf: Path, out_elf: Path, full_linked_elf: Path = FULL_LINKED_ELF) -> int:
    linked_elf = linked_elf if linked_elf.is_absolute() else ROOT / linked_elf
    out_elf = out_elf if out_elf.is_absolute() else ROOT / out_elf
    full_linked_elf = full_linked_elf if full_linked_elf.is_absolute() else ROOT / full_linked_elf
    boundaries, by_source, _layout_state, cache, _current_stamps, changed_sources, incremental = compute_incremental_state(out_elf)
    if not incremental or not changed_sources:
        return 1
    if not full_linked_elf.exists():
        return 1
    if not CXX_SECTIONS_OUT.exists() or not SYMBOLS_LD_OUT.exists():
        return 1
    if cache.get("cxx_sections_stamp") != _path_stamp(CXX_SECTIONS_OUT):
        return 1
    if cache.get("symbols_stamp") != _path_stamp(SYMBOLS_LD_OUT):
        return 1

    prev_linked_syms = {sym.name: sym for sym in load_text_symbols(full_linked_elf)}
    if not prev_linked_syms:
        return 1

    script_lines = [
        "_start = 0x0010001C;\n",
        "ENTRY(_start);\n",
        f"INCLUDE {SYMBOLS_LD_OUT.relative_to(ROOT).as_posix()}\n",
        "\n",
        "SECTIONS {\n",
    ]
    changed_objs: list[str] = []
    placed_any = False

    unit_sources = {u.source for u in load_units()}
    for source in sorted(changed_sources):
        if Path(source).suffix not in {".c", ".cc", ".cp", ".cpp", ".cxx"}:
            return 1
        if source in unit_sources:
            return 1
        obj = ROOT / src_to_obj(source)
        obj_syms = load_obj_text_symbols(obj)
        if not obj_syms:
            return 1
        alloc_sections = load_alloc_sections(obj)
        if any(not _is_fast_link_eligible_section(section) for section in alloc_sections):
            return 1

        tracked_by_name: dict[str, int] = {}
        for addr, symbol in sorted(by_source[source]):
            obj_sym = pick_obj_symbol(obj_syms, symbol, addr)
            if obj_sym is None:
                return 1
            tracked_by_name[obj_sym.name] = addr

        for sym in obj_syms:
            addr = tracked_by_name.get(sym.name)
            if addr is None:
                prev_sym = prev_linked_syms.get(sym.name)
                if prev_sym is None or prev_sym.size != sym.size:
                    return 1
                addr = prev_sym.addr
            script_lines.append(f"  .kh2fast_{addr:08x} 0x{addr:08x} : {{\n")
            for pattern in section_patterns(sym.name):
                script_lines.append(f"    KEEP(*({pattern}))\n")
            script_lines.append("  }\n")
            placed_any = True
        changed_objs.append(src_to_obj(source))

    if not placed_any:
        return 1

    script_lines.extend([
        "  .reginfo : { *(.reginfo) }\n",
        "  /DISCARD/ : {\n",
        "    *(.MIPS.abiflags)\n",
        "    *(.comment)\n",
        "    *(.pdr)\n",
        "    *(.mdebug*)\n",
        "    *(.gnu.attributes)\n",
        "  }\n",
        "}\n",
    ])

    linked_elf.parent.mkdir(parents=True, exist_ok=True)
    script_path = linked_elf.with_suffix(".fast.ld")
    script_path.write_text("".join(script_lines))

    cmd = [
        "/opt/ps2/gcc/bin/ee-ld",
        "--no-check-sections",
        "-T",
        str(script_path.relative_to(ROOT)),
        "-o",
        str(linked_elf.relative_to(ROOT)),
        *changed_objs,
        "-L/opt/ps2/gcc/lib/gcc-lib/ee/3.2-ee-040921",
        "-lgcc",
    ]
    proc = subprocess.run(cmd, cwd=ROOT)
    if proc.returncode != 0:
        return 1
    return normalize_final_elf(linked_elf, out_elf)


LOCAL_DATA_PREFIXES = (".sdata", ".rodata", ".lit4", ".lit8")
ORIG_GP = 0x0037A800  # the game's gp (main sets it); target of R_MIPS_GPREL16 immediates
_LO16_ACCESS_SIZE = {0x20: 1, 0x24: 1, 0x28: 1, 0x21: 2, 0x25: 2, 0x29: 2,
                     0x37: 8, 0x3F: 8, 0x1E: 16, 0x1F: 16}  # lb/lbu/sb, lh/lhu/sh, ld/sd, lq/sq; else 4


def retarget_local_data_refs(obj: Path, sym_name: str, code: bytes, orig_code: bytes, orig_image,
                             func_addr: int | None = None) -> bytes:
    """Compiler-generated anonymous data (float literal pools, string literals) is linked far from
    its original address, so its %hi/%lo pairs never match. For each HI16/LO16 pair in this function
    that targets a section symbol of .sdata/.rodata*/.lit*, take the original's immediates when the
    original instructions are otherwise identical AND the original address holds the same bytes.
    Switch jump tables are words with R_MIPS_32 relocations against this function's own text
    section: they count as the same bytes when every entry, relocated to the function's original
    address (func_addr), equals the original table."""
    data = obj.read_bytes()
    u32 = lambda o: int.from_bytes(data[o : o + 4], "little")
    shoff, shnum, shstrndx = u32(0x20), int.from_bytes(data[0x30:0x32], "little"), int.from_bytes(data[0x32:0x34], "little")
    secs = [tuple(u32(shoff + i * 40 + k * 4) for k in range(10)) for i in range(shnum)]
    shstr = secs[shstrndx][4]
    sname = lambda s: data[shstr + s[0] : data.index(b"\0", shstr + s[0])].decode()
    symtab = next(s for s in secs if s[1] == 2)
    strtab = secs[symtab[6]][4]
    syms = []
    for o in range(symtab[4], symtab[4] + symtab[5], 16):
        name = data[strtab + u32(o) : data.index(b"\0", strtab + u32(o))].decode()
        syms.append((name, u32(o + 4), data[o + 12], int.from_bytes(data[o + 14 : o + 16], "little")))
    func = next((s for s in syms if s[0] == sym_name and (s[2] & 0xF) == 2), None)
    if func is None:
        return code
    text_off, base, n = secs[func[3]][4], func[1], min(len(code), len(orig_code))
    w = lambda buf, x: int.from_bytes(buf[x : x + 4], "little")
    ow = lambda x: u32(text_off + base + x)
    sext = lambda v: v - 0x10000 if v & 0x8000 else v
    out = bytearray(code)

    def jump_table_matches(shndx: int, src: int, dst: int) -> bool:
        # R_MIPS_32 relocs in this data section, keyed by offset -> symbol index.
        if func_addr is None:
            return False
        words = {}
        for drel in (s for s in secs if s[1] == 9 and s[7] == shndx):
            for o in range(drel[4], drel[4] + drel[5], 8):
                if u32(o + 4) & 0xFF == 2:  # R_MIPS_32
                    words[u32(o)] = u32(o + 4) >> 8
        sec_off = secs[shndx][4]
        count = 0
        while (src + 4 * count) in words:
            sym = syms[words[src + 4 * count]]
            if (sym[2] & 0xF) != 3 or sym[3] != func[3]:  # next function's table starts here
                break
            label = u32(sec_off + src + 4 * count) - base + func_addr
            if read_elf_vaddr(orig_image, dst + 4 * count, 4) != label.to_bytes(4, "little"):
                return False
            count += 1
        return count > 0

    reginfo = next((sec for sec in secs if sname(sec) == ".reginfo"), None)
    gp0 = u32(reginfo[4] + 20) if reginfo and reginfo[5] >= 24 else 0
    patched_hi: dict = {}  # (r_sym, compiled lui word) -> original lui word, for retargeted pairs
    all_hi: list = []      # every HI16 against local data: (offset, r_sym)
    for rel in (s for s in secs if s[1] == 9 and s[7] == func[3]):  # SHT_REL for this text section
        hi = None
        pend: list = []  # HI16s since the last LO16 (gcc may duplicate a lui into a delay slot)
        for o in range(rel[4], rel[4] + rel[5], 8):
            r_off, r_type, r_sym = u32(o) - base, u32(o + 4) & 0xFF, u32(o + 4) >> 8
            if not 0 <= r_off <= n - 4:
                continue
            _name, _val, info, shndx = syms[r_sym]
            if (info & 0xF) != 3 or not sname(secs[shndx]).startswith(LOCAL_DATA_PREFIXES):
                continue
            if r_type == 7:  # R_MIPS_GPREL16: short literal in .sdata, addressed from gp
                # The link uses its own _gp; take the original immediate when the original
                # instruction is otherwise identical and gp + its offset holds the same string.
                x = r_off
                if not (w(orig_code, x) ^ ow(x)) & 0xFFFF0000:
                    sec = secs[shndx]
                    # gas stores the offset minus the object's gp0 (.reginfo ri_gp_value).
                    src = sext(ow(x) & 0xFFFF) + gp0
                    dst = ORIG_GP + sext(w(orig_code, x) & 0xFFFF)
                    end = data.find(b"\0", sec[4] + src)
                    want = data[sec[4] + src : end + 1] if 0 <= src and end >= 0 else b""
                    if want and read_elf_vaddr(orig_image, dst, len(want)) == want:
                        out[x : x + 4] = orig_code[x : x + 4]
                continue
            if r_type == 5:  # R_MIPS_HI16
                all_hi.append((r_off, r_sym))
                hi = (r_off, r_sym)
                pend.append(hi)
                continue
            extra, pend = [x for x, xs in pend[:-1] if xs == r_sym], []
            if r_type != 6 or hi is None or hi[1] != r_sym:  # R_MIPS_LO16 paired with the last HI16
                continue
            h, l = hi[0], r_off
            if any((w(orig_code, x) ^ ow(x)) & 0xFFFF0000 for x in (h, l)):
                continue
            src = ((ow(h) & 0xFFFF) << 16) + sext(ow(l) & 0xFFFF)
            dst = ((w(orig_code, h) & 0xFFFF) << 16) + sext(w(orig_code, l) & 0xFFFF)
            size = _LO16_ACCESS_SIZE.get(ow(l) >> 26, 4)
            sec = secs[shndx]
            want = data[sec[4] + src : sec[4] + src + size]
            if (len(want) != size or read_elf_vaddr(orig_image, dst, size) != want) \
                    and not jump_table_matches(shndx, src, dst):
                continue
            for x in (h, l):
                out[x : x + 4] = orig_code[x : x + 4]
            patched_hi[(r_sym, ow(h))] = w(orig_code, h)
            # Duplicates of this same lui (identical compiled and original instruction words
            # apart from the immediate, and the same immediates as the paired one) get it too.
            for x in extra:
                if (ow(x) == ow(h)) and ((w(orig_code, x) ^ w(orig_code, h)) & 0xFFFF0000) == 0 \
                        and (w(orig_code, x) & 0xFFFF) == (w(orig_code, h) & 0xFFFF):
                    out[x : x + 4] = orig_code[x : x + 4]
    # A lui that gcc duplicated into a delay slot can be attached by gas to an earlier %lo of the same
    # literal that belongs to a different lui (other register), so the pairing above misses it.
    # Give it the original immediate when an identical lui of the same literal was retargeted to it.
    for x, xs in all_hi:
        if out[x : x + 4] != orig_code[x : x + 4] and patched_hi.get((xs, ow(x))) == w(orig_code, x):
            out[x : x + 4] = orig_code[x : x + 4]
    return bytes(out)


def normalize_final_elf(linked_elf: Path, out_elf: Path) -> int:
    if not linked_elf.exists():
        raise FileNotFoundError(f"missing linked ELF: {linked_elf}")
    if not SLPM_PATH.exists():
        raise FileNotFoundError(f"missing SLPM binary: {SLPM_PATH}")

    boundaries, by_source, layout_state, _cache, current_stamps, changed_sources, incremental = compute_incremental_state(out_elf)
    if incremental:
        try:
            out_data = bytearray(out_elf.read_bytes())
        except FileNotFoundError:
            incremental = False
            out_data = bytearray(SLPM_PATH.read_bytes())
    else:
        out_data = bytearray(SLPM_PATH.read_bytes())

    errors: list[str] = []
    orig_data = SLPM_PATH.read_bytes()
    orig_image = (orig_data, parse_elf_load_segments(orig_data))
    linked_syms: dict[str, TextSym] = {}
    if changed_sources:
        linked_image = load_elf_image(linked_elf)
        if linked_image is None:
            raise RuntimeError(f"could not read loadable image from {linked_elf}")
        _ = linked_image
        linked_syms = {s.name: s for s in load_text_symbols(linked_elf)}
        linked_data = linked_elf.read_bytes()
    else:
        linked_data = b""

    units = {u.source: u for u in load_units()}
    for source, rows in sorted(by_source.items()):
        if source not in changed_sources:
            continue
        unit = units.get(source)
        if unit is not None:
            # Linked unit: take its whole text range exactly as the linker placed it.
            size = unit.end - unit.start
            sec = next((x for x in load_alloc_sections(linked_elf) if x.name == f".kh2unit_{unit.start:08x}"), None)
            if sec is None or sec.size != size:
                msg = (f"normalize-unit: ERROR {source}: .text is 0x{sec.size if sec else 0:x} bytes, "
                       f"linked_units.tsv range is 0x{size:x}")
                print(msg)
                errors.append(msg)
                continue
            linked = read_elf_vaddr(linked_image, unit.start, size)
            if linked is None or len(linked) != size:
                msg = f"normalize-unit: ERROR {source}: no linked bytes for 0x{unit.start:08x}-0x{unit.end:08x}"
                print(msg)
                errors.append(msg)
                continue
            foff = addr_to_file_offset(unit.start)
            out_data[foff : foff + size] = linked
            continue
        rows.sort(key=lambda t: t[0])
        obj = ROOT / src_to_obj(source)
        obj_syms = load_obj_text_symbols(obj)
        if not obj_syms:
            msg = f"normalize-cxx-layout: ERROR {source}: no object text symbols"
            print(msg)
            errors.append(msg)
            continue
        ordered = list(obj_syms)
        ordered_i = 0
        used: set[str] = set()

        for addr, symbol in rows:
            b = boundaries[addr]
            obj_sym = pick_obj_symbol(obj_syms, symbol, addr)
            if obj_sym is None:
                if symbol:
                    msg = (
                        f"normalize-cxx-layout: ERROR {source} 0x{addr:08x}: "
                        f"symbol not found in object: {symbol}"
                    )
                    print(msg)
                    errors.append(msg)
                else:
                    while ordered_i < len(ordered) and ordered[ordered_i].name in used:
                        ordered_i += 1
                    if ordered_i < len(ordered):
                        obj_sym = ordered[ordered_i]
                        ordered_i += 1
                if obj_sym is None:
                    msg = (
                        f"normalize-cxx-layout: ERROR {source} 0x{addr:08x}: "
                        "no object symbol candidate"
                    )
                    print(msg)
                    errors.append(msg)
                    continue

            used.add(obj_sym.name)
            linked_sym = linked_syms.get(obj_sym.name)
            if linked_sym is None:
                msg = (
                    f"normalize-cxx-layout: ERROR {source} 0x{addr:08x}: "
                    f"symbol not found in linked ELF: {obj_sym.name}"
                )
                print(msg)
                errors.append(msg)
                continue

            compiled = linked_data[linked_sym.foff : linked_sym.foff + obj_sym.size]
            if len(compiled) != obj_sym.size:
                msg = (
                    f"normalize-cxx-layout: ERROR {source} 0x{addr:08x}: "
                    f"cannot read linked bytes for {obj_sym.name}"
                )
                print(msg)
                errors.append(msg)
                continue

            if obj_sym.size < b.size:
                pad = b.size - obj_sym.size
                norm = compiled + (b"\x00" * pad)
            elif obj_sym.size > b.size:
                norm = compiled[: b.size]
            else:
                norm = compiled

            foff = addr_to_file_offset(addr)
            norm = retarget_local_data_refs(obj, obj_sym.name, norm, orig_data[foff : foff + b.size], orig_image, addr)
            out_data[foff : foff + b.size] = norm

    if errors:
        print(f"normalize-cxx-layout: FAIL ({len(errors)} symbol resolution error(s))")
        return 1

    out_elf.parent.mkdir(parents=True, exist_ok=True)
    tmp_out = out_elf.with_name(out_elf.name + ".tmp")
    tmp_out.write_bytes(bytes(out_data))
    tmp_out.replace(out_elf)
    _save_cache({
        "layout_state": layout_state,
        "obj_stamps": current_stamps,
        "cxx_sections_stamp": _path_stamp(CXX_SECTIONS_OUT),
        "symbols_stamp": _path_stamp(SYMBOLS_LD_OUT),
    })
    return 0


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="ELF build helpers: generate layout outputs, linker sections, and normalize the final ELF"
    )
    sub = parser.add_subparsers(dest="cmd", required=True)

    sub.add_parser(
        "link-sections",
        help="emit out/generated/cxx_sections.ld for currently fitted C++ symbols",
    )
    sub.add_parser(
        "objects",
        help="emit out/generated/objects.mk, layout_status.tsv, and symbols.ld",
    )
    inputs_stamp = sub.add_parser(
        "inputs-stamp",
        help="emit a content hash for build inputs so top-level make notices source edits reliably",
    )
    inputs_stamp.add_argument("--out", required=True, help="output stamp path")
    fast_link = sub.add_parser(
        "fast-link",
        help="try relinking only changed source-backed C/C++ objects and fall back in the caller if unsafe",
    )
    fast_link.add_argument("--linked-elf", required=True, help="temporary partial linked ELF path")
    fast_link.add_argument("--out-elf", required=True, help="output ELF path")
    fast_link.add_argument(
        "--full-linked-elf",
        default=str(FULL_LINKED_ELF),
        help="previous full linked ELF with symbol table for fast-link address reuse",
    )

    normalize = sub.add_parser(
        "normalize",
        help="cut or pad compiled C++ functions to preserve original function boundaries in the final ELF",
    )
    normalize.add_argument("--linked-elf", required=True, help="temporary linked ELF (relaxed layout)")
    normalize.add_argument("--out-elf", required=True, help="output ELF path")
    return parser


def main() -> int:
    parser = build_parser()
    args = parser.parse_args()

    if args.cmd == "link-sections":
        return generate_link_sections()
    if args.cmd == "objects":
        return generate_objects_mk()
    if args.cmd == "inputs-stamp":
        return write_inputs_stamp(Path(args.out))
    if args.cmd == "fast-link":
        return try_fast_link(Path(args.linked_elf), Path(args.out_elf), Path(args.full_linked_elf))
    if args.cmd == "normalize":
        return normalize_final_elf(Path(args.linked_elf), Path(args.out_elf))
    parser.error(f"unknown command: {args.cmd}")
    return 2


if __name__ == "__main__":
    raise SystemExit(main())
