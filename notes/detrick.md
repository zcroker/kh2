# Compiler tricks that turned out not to be needed

This change takes steering constructs out of the source wherever the build
stays byte-identical without them. Nothing else changes: `make` still ends in
`MATCHED!` (sha256 `d869ce4b…bc87`).

## What went

| construct | before | after |
|---|---|---|
| empty assembly statements (`asm("")`, `asm volatile("" ::: "memory")`, `asm("" : "+r"(x))`) | 370 | 298 |
| register pins (`register T x asm("$16")`) | 665 | 461 |
| `volatile` qualifiers | 9,275 | 8,400 |
| `__builtin_expect` | 49 | 37 |
| `nop`-only assembly statements | 27 | 1 |
| rows of `linked_units.tsv` with fewer switches | | 239 |

Switches dropped from linked units (the object is the same without them):
`-fno-strict-aliasing` 88, `-fno-builtin` 94, `-g` 58, `-fmove-all-movables`
14, `-frtti` 6, `-fno-schedule-insns` 5, `-fno-sched-interblock` 2,
`-fno-gcse` 1.

The 26 `nop` statements padded short loops; ee-as inserts that padding by
itself, so the source does not need to.

## How

**Mechanical (most of it).** For every construct in every source file: take
it out, compile the file with the build's own command, and compare the object
with the one from the untouched file (every loaded section, relocation and
symbol). Keep the removal only when they are identical. Groups are tried
first and halved on failure. A second pass rewrites runs of two to four
stores through `volatile` casts as the same stores, without `volatile`, in
whichever order compiles to the same object (the scheduler restores the
original order by itself). Switches of linked units are tested the same way.
A switch and a source construct can each be removable only while the other
is present, so the passes alternate, with a full `make` between them, until
nothing more goes. No model takes part in this.

**By hand (roughly 90 small functions).** Worker sessions (Claude) rewrote
functions that still needed a volatile cast, a pin or an empty assembly
statement, with one rule: the replacement must be code a programmer could
have written, never another trick. Each file was checked with the same object
comparison and the whole tree with `make`. What worked:

- stores through `volatile` casts become a struct with real member types,
  stores written in ascending (or the one matching) order;
- a pin disappears when the variable gets its real lifetime: the argument
  kept alive to the call that takes it (a method called with its `this`), a
  second group of calls given its own base variable, a pointer declared
  before the value read through it;
- an empty assembly statement disappears with early returns in place of one
  folded condition, a real `for` loop in place of labels, or a callee
  declared with the arguments it really takes.

## What is left, and why

Counting per function from the compiler's output (which source lines and
which pasted assembly end up in each function), 10,998 of 11,509 functions
are now free of these constructs or use only the assembly the game itself
had (vector-unit maths, 128-bit copies, assertion traps); it was 10,635
before. The rest resisted both passes:

- two variables that swap registers (`$17`/`$18`) with no source shape that
  flips them back: most of the remaining pins;
- the scheduler's order of unrelated stores or of an argument load;
- functions that need a pass-disabling switch (52 functions actually depend
  on one; the other functions of those units compile the same without);
- constants written as addresses where a symbol would add a relocation;
- the large hand-tuned rendering routines and the 47 game functions kept as
  assembly files.

`volatile` on hardware registers (`0x1000xxxx`, `0x1200xxxx`, `0xb000xxxx`)
and reads of `$gp` in Sony's RPC code are real and were left alone.

The tools (`detrick.py`, `attribute.py`, `quality.py`, `try_unit.py`) and the
per-function table are in <https://github.com/sh1ftmaker/kh2> (`tools/`,
`out/generated/quality.tsv` after a build).
