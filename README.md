# Kingdom Hearts 2: Final Mix Decomp

This repo contains a (WIP) **matching decompilation** of Kingdom Hearts 2 Final Mix's
main ELF, nicknamed "dasein": C/C++ source that compiles back into a byte-for-byte
identical copy of the original executable.

It builds the current executable:

* SLPM\_666.75: sha256sum: `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`

> **About this fork.** This project is built on [GovanifY's original work](https://github.com/GovanifY/kh2)
> (the build system, tooling, recovered symbols and file layout, and the first several
> thousand matched functions). All credit for that foundation goes to GovanifY.
>
> **AI disclosure.** The work in this fork since October 2026 is being done by AI: Anthropic's
> Claude (via Claude Code) writes and tests the matching code and tooling, directed and
> reviewed by the repository owner. Every function is only accepted when the full rebuild
> is byte-identical to the original, but the source itself is machine-written, so names,
> types and structure may be less idiomatic than hand-written decomp code.
>
> This is an unofficial fan project, not affiliated with or endorsed by Square Enix or Sony.
> It contains no game data: you need your own copy of the game to build it.

## Status (October 2026)

| Measure | Progress |
|---|---|
| Functions matched | **9,377 / 11,286 (83.1%)** |
| Code matched (by size) | **50.9%** |
| Source-file chunks fully matched ("linked" groundwork) | 19 of 140, with 53 at 90% or more |

Every commit keeps the rebuilt `kh2.elf` byte-identical to the retail executable.

What's left is mostly the hard part: large functions, register-allocation near-misses,
Sony PS2 SDK library code (Runtime Library 3.0.0, built with an older compiler), and
hand-written assembly.

### Roadmap

1. **Linked build:** split the game back into its original source files (boundaries recovered
   from the static-initializer table) and build by compiling and linking them, the way
   finished decomps are built.
2. **Tooling:** [m2c](https://github.com/matt-kempster/m2c) for first drafts,
   [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) for near-misses,
   and shared headers for the game's data types.
3. **Remaining code:** deep work on large functions; matching the Sony SDK libraries with
   the compiler they were built with; keeping genuinely hand-written assembly as `.s` files.
4. **Data and names:** data sections as source; real names for functions (a set of
   machine-suggested names lives in `notes/function_names.tsv`).

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
