# Linked units: how to convert a source file

A linked unit is one source file that the build compiles as one object and links whole at its
original address. The functions stay in source order inside one `.text`, and the linker resolves
every address. The build then copies the unit's whole range from the link into `kh2.elf`. It does
not place functions one by one, and it does not patch immediates (`retarget_local_data_refs`).

The list of units is `linked_units.tsv` at the repo root. The first unit is
`src/yasui/libys/mutex.cpp` (0x1c8d80-0x1c8e80, 6 functions, 3 globals in `.data` at 0x351eb8).

## What the build does with a unit

- `build_elf.py objects`: every `layout.tsv` function inside the range gets status `cxx` with the
  unit's source, whatever `functions.tsv` says. `objects.mk` gets
  `UNIT_FLAGS := -fno-function-sections <flags>` for the unit's object.
- `build_elf.py link-sections`: `cxx_sections.ld` gets `.kh2unit_<start>` with the object's `.text`
  at the start address, plus one section per entry in the `sections` column. No `.kh2cxx_<addr>`
  sections are made for addresses inside the unit.
- The unit's `.ctors` entry goes into the `.ctors` output section by itself (`kh2.ld`).
- `normalize`: makes sure that the linked `.kh2unit_<start>` is exactly `text_end - text_start`
  bytes, then copies that range. A size difference is a build error.
- If a unit changed, the build skips the fast link and runs the full link.

## Steps for the next file

1. Pick a range that one file owns completely. Good candidates: a range between two `.ctors`
   stubs where every function is already matched (see `~/re/kh2/research/split_plan.md`, section 4:
   0x2ead78-0x2eaf18, 0x2ee568-0x2ee888, 0x103f48-0x1042f8, 0x13a328-0x13a898).
   `text_end` is the end of the last function, including its alignment padding.
2. Find every function of the range in `src/` (`out/generated/layout_status.tsv` names the file).
   Write them into the unit's source file in address order.
3. Remove the old definitions from the other files. Leave a one-line comment that names the
   address and the new file. Keep any declaration that a caller in that file still needs.
   Callers in other files find the functions through `symbols.ld` (generated from `functions.tsv`
   and from the `func_XXXXXXXX` declarations), so they need no change.
4. Globals that the original file defined: define them in the unit. If the real name is not known,
   name them `D_XXXXXXXX`. Then other files that declare `extern ... D_XXXXXXXX` still link to them.
   Put each data section of the object (`.data`, `.bss`, `.rodata`, `.sdata`) in the `sections` column.
   Give its original address, for example `.data@00351eb8,.rodata@0032f000`.
5. If the file has globals with constructors, gcc makes the static initialiser and the
   `_GLOBAL__I_...` stub itself. Do not write them by hand.
6. Compile the file alone and compare it with the original range (example below). Only the
   relocated fields can differ. If gcc uses `gp` for globals and the original uses `lui`, put
   `-G0` in the `flags` column.
7. Add the row to `linked_units.tsv`, run `make`, and make sure that it prints `MATCHED!`.
   Then make sure that `cmp kh2.elf SLPM_666.75` is silent and `~/re/kh2/pct.sh` did not go down.

Compile one file alone (from the repo root, colima running):

```bash
docker run --rm --platform linux/amd64 -v "$PWD":/work -w /work kh2-local/ps2-compiler:3.2-ee-040921-objdiff sh -c "ee-g++ -O2 -g0 -G0 -x c++ -fno-exceptions -fno-rtti -fpermissive -c -o /tmp/u.o src/yasui/libys/mutex.cpp && ee-objdump -h -dr /tmp/u.o"
```

Show the original range: `~/re/kh2/dis.sh 1c8d80 256` (address in hex, size in decimal).

## Limits today

- Only functions are copied into `kh2.elf`. The data sections are linked at their real address so
  that the code's addresses come out right, but their bytes are not copied yet. Make sure that the
  data the unit defines is the same as the retail bytes (zero for mutex).
- `try.sh` copies a file to a temporary folder, so a named file with a local `#include` does not
  compile there. Use the compile command above for a unit.
- In objdiff, a unit's functions show the names from `functions.tsv` (for mutex: `ctarget_001c8db8`,
  `wtarget_001c8e00`, `func_001c8e60`). Other files still call them by those names.
- A helper that adds a function inside a unit's range has no effect: the unit owns the range.
- If an old worker copy still holds a function that moved into a unit, importing that worker
  brings back a second definition and the link fails. For mutex this is only possible for w1
  (`func_001c8de0` in `batch_w1.cpp`).
