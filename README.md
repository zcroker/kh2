# Kingdom Hearts 2: Final Mix Decomp

This repo contains a (WIP) **matching decompilation** of Kingdom Hearts 2 Final Mix's
main ELF, nicknamed "dasein": C/C++ source that compiles back into a byte-for-byte
identical copy of the original executable.

It builds the current executable:

* SLPM\_666.75: sha256sum: `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`

> [!IMPORTANT]
> This repository does **not** contain any game data: no executable, disc image or assets.
> A legally obtained copy of the game is required to build it. This repository is not a PC
> port or any other port. It is an unofficial fan project, not
> affiliated with or endorsed by Square Enix, Disney or Sony Interactive Entertainment.
> See [Legal](#legal).

> **About this fork.** This project is built on [GovanifY's original work](https://github.com/GovanifY/kh2)
> (the build system, tooling, recovered symbols and file layout, and the first several
> thousand matched functions). All credit for that foundation goes to GovanifY.
>
> **AI disclosure.** The work in this fork since October 2026 is being done by AI: Anthropic's
> Claude (via Claude Code) writes and tests the matching code and tooling, directed and
> reviewed by the repository owner. Every function is only accepted when the full rebuild
> is byte-identical to the original, but the source itself is machine-written, so names,
> types and structure may be less idiomatic than hand-written decomp code.

## Status (27 November 2026)

| Measure | Progress |
|---|---|
| Functions that compile to the original bytes | **11,509 / 11,509 (100%)** |
| Game code built from C/C++ source | **96.2%** |
| Game code still kept as hand-copied assembly (`.s` files) | 3.7% (139 files) |
| Game data (tables, strings, constants) built from source | not started |
| Functions with a real name | about 3,600 of 11,500 (about 30%) |

Every commit keeps the rebuilt `kh2.elf` byte-identical to the retail executable.

All code now compiles back to the original. But the project is not finished. The steps below are
what is left, in order.

### Roadmap

**Done: match all code.** Every function compiles to the same bytes as the original. The game's
code is grouped into its original source files ("linked units"), which the build compiles and links
whole.

Small jobs that are still open in this step:

* Convert the last 141 assembly files to C/C++. Some of these are Sony library code that needs
  the older compiler it was built with.
* Remove the remaining compiler tricks. Some functions still use register pins, empty `asm`
  statements or extra `volatile` words to make the compiler produce the original order. See
  `notes/detrick.md`.

**1. Data as source.** The game's tables, strings and constants are still copied from your copy
of the original executable. This step turns them into C/C++ structs, arrays and constants in the
source files, so that the build makes them itself. Some files already declare their data at the
right address, but the build does not use those bytes yet.

**2. A shiftable build.** Today every source file is placed at a fixed address, on top of a copy of
the original executable. If you add one instruction, everything after it moves and the addresses
break. This step makes the linker place everything and fix every address, so that code and data
can grow or shrink. Steps 1 and 2 must both be done before anybody can safely change the game.

**3. Names and types.** Make the code easy to read for people and for AI agents. About 70% of
functions still have placeholder names such as `func_0014ac18`, and much of the code reads
fields as raw offsets (`*(u32*)(p + 2904)`) instead of named struct members. This means naming
functions, variables and fields, and writing the game's real structs and classes. This is the
longest step.

* The E3 2014 PS3 debug build gives real names. `notes/e3/` has 7,636 name mappings. 1,458 are
  applied. The others need review, and about 2 to 3 in every 100 applied names can be wrong.
* `notes/function_names.tsv` holds a set of machine-suggested names that are not applied.

**4. Optional: a PC port.** Without a port, the rebuilt game runs only on a PS2 or a PS2 emulator.
A port is a separate, later project. It needs steps 1 to 3 first, and it will still need your own
copy of the game.

## Setup

In order to work on this project, you will need to put SLPM\_666.75 at the root
of this repo. It can be found readily available in the ISO of the game as a
regular file.

You will also need some dependencies although not many, namely: python3, docker
and git lfs. This repository was also made in mind with a UNIX shell and has
been tested and known to work on Linux and macOS. Hopefully, it should work on
WSL (Windows) with minimal tinkering.

You need to run `git lfs pull` in order to retrieve the compiler's archive from
the repo before running `make`.

## Workflow

When you decompile a new function, add a reference to the function and any
symbols it uses in `functions.tsv`. 
You can then implement the function in any file present in the `src/` folder and
it will be picked up automatically.


Once your function(s) are drafted, run `make`. This will generate the required
files to use [objdiff](https://github.com/encounter/objdiff), an automated
diffing tool.

Open your project repository in it and, on the left sidebar, filter by
incomplete to show objects which are not fully matching yet. You can then edit
your source files and objdiff will automatically rebuild and show you the
updated percentage as you do.

You can also, optionally, upload an online scratch to decomp.me from the tool,
to work collaboratively on a function.


## Symbols and file layout

_(From the original README.)_

Symbols and file layout have been mostly recovered from the E3 kiosk demo PS3 port
of KH2. While there is obvious drift in the overall logic, this should be a good
resource in order to try to name functions yet unknown in this repository. I
_highly_ encourage you to inspire yourself from those debug symbols XREFs,
function layouts, vtables etc in order to try to recover as much of the original
layout as possible.

I already recovered class definitions and file layout from said ELF. 

There are two exceptions to that

* `src/anon` is not an original folder and is used as a
placeholder until the original symbol for the function is written down. A lot of
those functions were automatically generated through symbolic CFG traversal
analysis of gcc and as such may not be very idiomatic C++, but they should be all 
matching.

* `nonmatchings`: This folder is not rigged up at all in the build system and is
  mostly used as a dump of functions that aren't yet matching.

## Legal

This is an unofficial, non-commercial fan project for preservation, education and
research. It is not affiliated with, endorsed by or sponsored by Square Enix, Disney or
Sony Interactive Entertainment.

Kingdom Hearts is a trademark of Disney Enterprises, Inc. and Square Enix Holdings Co., Ltd.
PlayStation is a trademark of Sony Interactive Entertainment Inc. All other trademarks
belong to their owners. Their use here identifies the game only.

### What this repository contains

* Source code written by contributors. When compiled, it produces the same machine code as
  the original program.
* Build tools, notes and a GCC compiler toolchain. GCC keeps its own license (GNU GPL).
* Rebuilt copies of library routines that the game links: parts of newlib and of GCC's runtime
  libraries (libgcc, libsupc++). Each file that holds them starts with a notice. That code keeps
  its original license (the newlib notices, or the GNU GPL with the GCC runtime library exception).

### What this repository does not contain

* The game's executable (`SLPM_666.75`), disc image, or any graphics, models, music, sound
  or other asset files.
* Leaked, stolen or confidential material from Square Enix, Sony or anyone else.

The build reads the executable from your own copy of the game. It does not download it,
and the build output stays on your computer. You must not distribute the executable that
you build.

### Rules for contributors and users

* Do not ask for, share or link to game files, disc images or download sites in issues,
  pull requests or discussions. We remove such content.
* Do not contribute leaked, stolen or confidential code or documents, and do not
  contribute work that you do not have the right to share.
* Contributions are accepted under the [MIT License](LICENSE).

### License

The MIT License covers only the original work of this project's contributors. It gives no
rights to the original game, its assets or the trademarks above. It does not cover the library code
that carries its own notice (see above).

### Contact

If you hold rights in the game and have a concern about this repository, open an issue
on this repository and we will respond promptly.

