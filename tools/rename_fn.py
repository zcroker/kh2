#!/usr/bin/env python3
"""Give placeholder-named functions real names, everywhere at once.

usage: tools/rename_fn.py [--check] [--no-validate] [--no-aliases] NAMES.tsv

NAMES.tsv rows: addr<TAB>new_name<TAB>evidence   (evidence is free text; '#' lines and a
header row starting with 'addr' are skipped).

For each row the function's current name in functions.tsv (func_ADDR, func_ADDR(args), or a
mangled placeholder such as _Z16wtarget_ADDRjjjj) is replaced by new_name:

  * functions.tsv: the row for ADDR becomes the plain new_name (also when the current name is a
    signature form func_ADDR(int) or a mangled placeholder _Z16wtarget_ADDRjjjj);
  * every file under src/ (.c .cpp .h .hpp .s .S): the placeholder identifier (and, unless
    --no-aliases, the generic func_ADDR alias for the same address) is replaced on word
    boundaries: definitions, declarations, calls, asm labels, .globl/.type/.ent/.end/.size,
    asm("...") alias strings, and mangled references (_Z13func_ADDR... -> _Z<n>new_name...).
    Section names (.text.func_ADDR, .gnu.linkonce.t.func_ADDR) are left alone; the build finds
    renamed asm functions through them (see tools/common.py and tools/build_elf.py).

Linkage is never changed: a function defined in a .cpp without extern "C" keeps C++ linkage, so
its object symbol becomes the mangled form of the new name. The build tools match a plain
registry name against such a symbol (build_elf.pick_obj_symbol) and provide mangled aliases for
C++ declarations of named functions (build_elf.collect_named_decl_aliases).

Refused: a new name that is not a plain C identifier (C++-mangled or qualified targets), a C/C++
keyword, a placeholder (func_/D_), a name functions.tsv already uses (for any address), a name
already used as an identifier in src/ code (comments and strings excluded; allowed only where it is
declared as an asm("...") alias of this same function), duplicate rows, and
current names that are not address placeholders.

--check only reports what would change. Without --no-validate, after writing it re-runs the
build's source resolution (common.load_registry) and reverts everything if any function would
now resolve to a different source file than before.
"""
from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import common  # noqa: E402

ROOT = common.ROOT
REGISTRY = common.REGISTRY_TSV
SRC = ROOT / "src"
SRC_SUFFIXES = {".c", ".cpp", ".h", ".hpp", ".s", ".S"}
IDENT_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
KEYWORDS = set("""
alignas alignof and and_eq asm auto bitand bitor bool break case catch char class compl const
constexpr const_cast continue decltype default delete do double dynamic_cast else enum explicit
export extern false float for friend goto if inline int long mutable namespace new noexcept not
not_eq nullptr operator or or_eq private protected public register reinterpret_cast return short
signed sizeof static static_assert static_cast struct switch template this throw true try typedef
typeid typename union unsigned using virtual void volatile wchar_t while xor xor_eq main
""".split())
# Section-name contexts are not renamed.
SECTION_LOOKBEHIND = r"(?<!\.text\.)(?<!\.linkonce\.t\.)"


@dataclass
class Row:
    lineno: int
    addr: int
    new: str
    evidence: str
    cur_text: str = ""          # functions.tsv name column as written
    reg_line: int = -1          # index into functions.tsv lines
    base: str = ""              # placeholder identifier, e.g. func_002f20d0 / wtarget_002f3cd8
    new_reg: str = ""           # new functions.tsv name column
    tokens: list[str] = field(default_factory=list)
    source: str = ""
    error: str = ""


def parse_mangled_simple(sym: str) -> tuple[str, str] | None:
    """_Z<n><ident><rest> -> (ident, rest); None for nested/other forms."""
    m = re.match(r"^_Z(\d+)", sym)
    if not m:
        return None
    n = int(m.group(1))
    ident = sym[m.end(): m.end() + n]
    if len(ident) != n or not IDENT_RE.match(ident):
        return None
    return ident, sym[m.end() + n:]


def strip_code(text: str, asm: bool) -> str:
    """Blank out comments and string/char literals (keeps offsets)."""
    out = list(text)
    i, n = 0, len(text)
    while i < n:
        c = text[i]
        if text.startswith("//", i) or (asm and c == "#" and not text.startswith("#include", i)):
            j = text.find("\n", i)
            j = n if j < 0 else j
            for k in range(i, j):
                out[k] = " "
            i = j
        elif text.startswith("/*", i):
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            for k in range(i, j):
                if out[k] != "\n":
                    out[k] = " "
            i = j
        elif c in "\"'":
            j = i + 1
            while j < n and text[j] != c and text[j] != "\n":
                j += 2 if text[j] == "\\" else 1
            j = min(j + 1, n)
            for k in range(i, j):
                out[k] = " "
            i = j
        else:
            i += 1
    return "".join(out)


def load_rows(path: Path) -> list[Row]:
    rows: list[Row] = []
    for lineno, line in enumerate(path.read_text().splitlines(), start=1):
        s = line.strip()
        if not s or s.startswith("#") or s.lower().startswith("addr\t"):
            continue
        parts = line.split("\t")
        if len(parts) < 2:
            rows.append(Row(lineno, -1, "", "", error="expected addr<TAB>new_name<TAB>evidence"))
            continue
        try:
            addr = common.parse_hex_addr(parts[0])
        except ValueError:
            rows.append(Row(lineno, -1, parts[1].strip(), "", error=f"bad address {parts[0]!r}"))
            continue
        rows.append(Row(lineno, addr, parts[1].strip(), "\t".join(parts[2:]).strip()))
    return rows


def src_files() -> list[Path]:
    return sorted(p for p in SRC.rglob("*") if p.is_file() and p.suffix in SRC_SUFFIXES)


def build_subs(row: Row) -> list[tuple[re.Pattern, str]]:
    subs: list[tuple[re.Pattern, str]] = []
    for tok in row.tokens:
        # Mangled references embedding the placeholder: _Z13func_ADDR... -> _Z<n>new...
        subs.append((re.compile(SECTION_LOOKBEHIND + rf"(?<![A-Za-z0-9_])_Z{len(tok)}{re.escape(tok)}(?=[A-Za-z0-9_]|\b)"),
                     f"_Z{len(row.new)}{row.new}"))
        subs.append((re.compile(SECTION_LOOKBEHIND + rf"\b{re.escape(tok)}\b"), row.new))
    return subs


def registry_sources() -> dict[int, str]:
    return {a: e.source for a, e in common.load_registry(REGISTRY).items()}


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("names_tsv", type=Path)
    ap.add_argument("--check", action="store_true", help="report only; change nothing")
    ap.add_argument("--no-validate", action="store_true", help="skip the post-write source-resolution check")
    ap.add_argument("--no-aliases", action="store_true",
                    help="rename only the registry placeholder, not the generic func_ADDR alias")
    args = ap.parse_args()

    rows = load_rows(args.names_tsv)
    reg_lines = REGISTRY.read_text().splitlines(keepends=True)
    by_addr: dict[int, tuple[int, str]] = {}
    used_names: dict[str, int] = {}
    for i, line in enumerate(reg_lines):
        s = line.strip()
        if not s or s.startswith("#"):
            continue
        parts = s.split("\t")
        if len(parts) != 2:
            continue
        addr = common.parse_hex_addr(parts[1])
        by_addr[addr] = (i, parts[0].strip())
        try:
            sym = common.resolve_symbol_name(parts[0].strip())
        except ValueError:
            sym = parts[0].strip()
        used_names[sym] = addr
        q = common._symbol_to_qualified_name(sym)
        if q:
            used_names.setdefault(q.split("::")[-1], addr)

    files = src_files()
    texts = {p: p.read_text(errors="ignore") for p in files}
    idents_by_file: dict[Path, set[str]] = {}
    code_idents: set[str] = set()
    for p, t in texts.items():
        ids = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", strip_code(t, p.suffix in {".s", ".S"})))
        idents_by_file[p] = ids
        code_idents |= ids

    def alias_only_use(new: str, tokens: list[str]) -> bool:
        """True when every file using `new` as an identifier binds it to this very function with
        asm("<placeholder>") (e.g. `float fabsf(float) asm("func_002f8870");`)."""
        alts = "|".join(re.escape(t) for t in tokens)
        bind = re.compile(rf"\b{re.escape(new)}\s*\([^;{{}}]*\)\s*(?:__asm__|asm)\s*\(\s*\"(?:_Z\d+)?(?:{alts})")
        users = [p for p, ids in idents_by_file.items() if new in ids]
        return bool(users) and all(bind.search(texts[p]) for p in users)

    print("resolving current sources (common.load_registry)...", file=sys.stderr)
    before = registry_sources()

    seen_new: dict[str, int] = {}
    seen_addr: set[int] = set()
    for r in rows:
        if r.error:
            continue
        a8 = f"{r.addr:08x}"
        if r.addr in seen_addr:
            r.error = "duplicate address in input"
            continue
        seen_addr.add(r.addr)
        if not IDENT_RE.match(r.new) or r.new.startswith("_Z"):
            r.error = f"refused: {r.new!r} is not a plain C identifier (C++-mangled/qualified targets are not supported)"
            continue
        if r.new in KEYWORDS or re.match(r"^(func|D)_[0-9a-fA-F]{8}$", r.new):
            r.error = f"refused: {r.new!r} is a keyword or placeholder"
            continue
        if r.new in seen_new:
            r.error = f"refused: {r.new} also given for {seen_new[r.new]:08x} in the input"
            continue
        seen_new[r.new] = r.addr
        hit = by_addr.get(r.addr)
        if hit is None:
            r.error = "address not in functions.tsv"
            continue
        r.reg_line, r.cur_text = hit
        if r.new in used_names:
            other = used_names[r.new]
            r.error = ("already named so" if other == r.addr
                       else f"refused: {r.new} already exists in functions.tsv for {other:08x}")
            continue
        cur = r.cur_text
        m_sig = re.match(r"^([A-Za-z_][A-Za-z0-9_]*)\s*\((.*)\)$", cur)
        if IDENT_RE.match(cur) and not cur.startswith("_Z"):
            r.base, r.new_reg = cur, r.new
        elif m_sig:
            r.base, r.new_reg = m_sig.group(1), r.new
        else:
            mm = parse_mangled_simple(cur)
            if mm is None:
                r.error = f"refused: current name {cur!r} is not a simple placeholder form"
                continue
            # Written as the plain name: C callers then get PROVIDE(new_name) from functions.tsv,
            # C++ callers a mangled alias (build_elf.collect_named_decl_aliases), and the
            # definition is matched by its unmangled name (build_elf.pick_obj_symbol).
            r.base, r.new_reg = mm[0], r.new
        if not re.match(rf"^[A-Za-z][A-Za-z0-9_]*_{a8}$", r.base):
            r.error = f"refused: current name {cur!r} is not an address placeholder (already named?)"
            continue
        r.tokens = [r.base]
        if not args.no_aliases and r.base != f"func_{a8}":
            r.tokens.append(f"func_{a8}")
        if r.new in code_idents and not alias_only_use(r.new, r.tokens):
            r.error = f"refused: {r.new} is already used as an identifier in src/"
            continue
        r.source = before.get(r.addr, "")
        if not r.source:
            r.error = "refused: the build does not resolve a source for this address"
            continue

    ok = [r for r in rows if not r.error]
    bad = [r for r in rows if r.error]

    # Compute edits.
    new_texts: dict[Path, str] = {}
    per_row_files: dict[int, dict[str, int]] = {}
    for r in ok:
        subs = build_subs(r)
        counts: dict[str, int] = {}
        for p in files:
            t = new_texts.get(p, texts[p])
            if not any(tok in t for tok in r.tokens):
                continue
            total = 0
            for pat, rep in subs:
                t, n = pat.subn(rep, t)
                total += n
            if total:
                new_texts[p] = t
                counts[p.relative_to(ROOT).as_posix()] = total
        per_row_files[r.addr] = counts
        if r.source not in counts:
            print(f"warning: {r.addr:08x} {r.new}: definition file {r.source} has no occurrence", file=sys.stderr)

    for r in ok:
        c = per_row_files[r.addr]
        print(f"{'WOULD RENAME' if args.check else 'RENAME'} {r.addr:08x} {r.cur_text} -> {r.new_reg}"
              f"  [def {r.source}; {sum(c.values())} occurrences in {len(c)} files]")
    for r in bad:
        level = "SKIP" if r.error == "already named so" else "ERROR"
        print(f"{level} line {r.lineno} {r.addr:08x} {r.new}: {r.error}")
    print(f"{len(ok)} to rename, {len(bad)} refused/skipped, {len(new_texts)} source files touched")

    if args.check or not ok:
        return 0 if not [r for r in bad if not r.error.startswith("already")] else 1

    # Write.
    orig_reg = "".join(reg_lines)
    for r in ok:
        line = reg_lines[r.reg_line]
        name_col, rest = line.split("\t", 1)
        reg_lines[r.reg_line] = f"{r.new_reg}\t{rest}"
    for p, t in new_texts.items():
        p.write_text(t)
    REGISTRY.write_text("".join(reg_lines))

    if args.no_validate:
        return 0
    print("validating (common.load_registry)...", file=sys.stderr)
    try:
        after = registry_sources()
        problems = [f"{a:08x}: {before.get(a)} -> {after.get(a)}"
                    for a in sorted(set(before) | set(after)) if before.get(a) != after.get(a)]
    except Exception as e:  # noqa: BLE001
        problems = [f"load_registry failed: {e}"]
    if problems:
        for p, _t in new_texts.items():
            p.write_text(texts[p])
        REGISTRY.write_text(orig_reg)
        print("VALIDATION FAILED; all changes reverted:")
        for line in problems[:50]:
            print("  " + line)
        return 2
    print("validated: every function resolves to the same source file as before")
    return 0 if not [r for r in bad if not r.error.startswith("already")] else 1


if __name__ == "__main__":
    sys.exit(main())
