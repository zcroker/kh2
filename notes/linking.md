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
- Compiler choice: game code uses ee-gcc 3.2. `src/sdk/*.c` rows use ee-gcc 2.9-991111 (`SDK_CC`).
- The `cc=NAME` token: put it in the `flags` column of a `src/sdk/*.c` row to build that row with
  `tools/compilers/NAME/bin/ee-gcc`. `objects.mk` then gets `UNIT_CC`. The token does not go to the compiler.
- Sony code built with ee-gcc 2.96 uses `cc=ee-gcc2.96`. Example: the SIF RPC client
  (`src/sdk/sifrpc_002f1b48.c`, `sifrpc_002f1da0.c`). Signs of 2.96: branch-likely, and a `while (i--);`
  delay loop unrolled by 4.
- `docker/ps2/prepare.sh` gets both old compilers from decomp.me's compiler releases into
  `tools/compilers/` (not committed).
- The link's `_gp` is not the game's 0x37a800. Setting it to 0x37a800 breaks the gp-relative references
  of game code that is linked far away. So a unit cannot use a real `-G8` small-data symbol. Write such a
  read through `$28` (`register int *gp asm("$28")`, or a one-load `asm`).
- Every row of `linked_units.tsv` is compiled and linked, also a row whose range holds no
  `layout.tsv` function at all (only never-written gap functions, for example between two
  whole-asm functions: `unit_001fd530.cpp`). Its object goes into the link order at its start address.
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

## Linking whole-asm functions (2026-11-18)

Decision: linking is closed out first. A function whose only source is a `.s` file (whole-function
assembly) is linked AS ASSEMBLY, as its own row in `linked_units.tsv`, and converted to C/C++ later.

- A `.s` row works like any other row, with these differences (`build_elf.py link-sections`):
  the unit section takes the object's `.text.*` sections in file order (every `.s` puts each function
  in its own `.section .text.func_ADDR`; the 20 zero bytes ee-as leaves in the plain `.text` are not
  part of the unit), and the rest of the range up to `text_end` is zero-filled (alignment nops).
  Code longer than the range stops the link ("cannot move location counter backwards").
  The `sections` and `flags` columns are `-`.
- One `.s` file that holds several functions from different places is split first: each function
  that gets linked moves to its own `asm_ADDR.s` next to the old file. The asm text moves unchanged.
  The new file keeps the old file's general header, the `.set` lines and the header entry of that
  function (the closest C drafts and the blockers: they are the notes for the later conversion).
- `text_end`: the next function or unit start when only alignment padding (< 8 bytes) lies between;
  otherwise the function's own end (an unwritten gap after it stays outside the unit).

Steps:
1. In a work folder copied from a built main: split the function out of its `.s` file if needed.
2. Add the row `src/.../asm_ADDR.s  START  END  -  -` to `linked_units.tsv` in address order.
3. `make`: `MATCHED!`, and `cmp kh2.elf SLPM_666.75` is silent.
4. Publish as usual, and log the function as linked whole asm (kind `whole asm linked in unit`, with the
   new file), so the conversion pass finds it. `.s` rows in `linked_units.tsv` list what is left.

Converting one later: write the C/C++ into the neighbouring unit's file (in address order), extend
that row's range over the function, delete the `.s` row and the `.s` file (or its block), rebuild.
