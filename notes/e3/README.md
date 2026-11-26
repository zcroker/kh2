# Function names from the E3 2014 PS3 debug build

`e3_names.tsv` and `apply_names.tsv` carry function names for `SLPM_666.75`
that were **read from debug information, not suggested by a model**.

## Where the names come from

The E3 2014 kiosk demo of *Kingdom Hearts HD 2.5 ReMIX* (PS3) shipped an
executable with its symbol table and full DWARF debug information intact: the
original developers' own function names, class names, parameter names and
source paths (`C:/hd25/kingdom2/yasui/libys/*.cpp` and so on). This is the same
build the project README already cites as the source of its symbols and file
layout. It holds 25,356 named functions.

Every name in these files is one of those symbols, copied character for
character. The `e3_mangled` column is the symbol as it appears in the PS3
executable and `e3_demangled` is `c++filt`'s reading of it. Nothing here was
written or guessed by a language model.

## What is inferred, and how sure it is

The names are real; what has to be worked out is **which PS2 function each
name belongs to**, because the PS3 build is PowerPC and its code moved. That
mapping was made by deterministic matchers, not by a model:

- call-graph alignment (the same callees in the same order on both sides);
- caller and callee set fingerprints;
- rare strings referenced by both functions;
- vtable slot pairing, and constructors paired by the vtable they store;
- locality: neighbours in the PS2 text against the DWARF compile unit;
- instruction-feature similarity for functions the above could not reach.

The 1,700 names the upstream registry already had (they occur exactly once in
the PS3 symbol table) are the anchors (`seed`). Each tier was scored by hiding
a share of known pairs and re-deriving them:

| tier | how it was matched | hold-out precision |
|---|---|---|
| `seed` | already in the registry, unique in the PS3 symbol table | anchor |
| `high` | vtable evidence, or two or more independent families agree | 97.8 % (218 right, 5 wrong) |
| `sim-high` | feature similarity, top score band | 97.2 to 97.5 % |
| `sim-vt-high` | vtable pairing | 97.9 % |
| `med`, `sim-med` and the other `sim-*` tiers | one family plus locality, or lower score bands | about 92 to 96 % |
| `sim-low`, `*-sandwich` | weak; position between two matched neighbours | lower, treat as hints |

So expect roughly 2 to 3 wrong names in every hundred of the applied set. A
wrong one is a real name attached to the wrong neighbour, usually a sibling
method of the same class.

## What was applied

`apply_names.tsv` is the input that was given to `tools/rename_fn.py`:
1,458 functions that had a placeholder name, in the `high`, `sim-high` and
`sim-vt-high` tiers only. Because `rename_fn.py` takes plain C identifiers,
`kn::Friend::checkHpRatio(...)` is written `kn__Friend__checkHpRatio`
(`::` becomes `__`); the evidence column of each row gives the full mangled
and demangled symbol. After the rename the build is still byte-identical to
`SLPM_666.75` (sha256 `d869ce4b…bc87`).

Left out of the applied set, and listed in `e3_names.tsv` only:

- overloaded methods, constructors and destructors whose plain identifier
  would not be unique (132);
- functions inside linked units that `rename_fn.py` could not resolve to a
  source by address (43), and two its validation step rejected;
- every lower tier.

## `e3_names.tsv` columns

`addr`, `tier`, `status`, `current_name` (in `functions.tsv` before this
change), `e3_mangled`, `e3_demangled`, `c_identifier`, `e3_params` (parameter
types and names from DWARF), `applied`.

`status` is one of:

- `new`: the registry had a placeholder (5,013; 1,458 of them applied);
- `same name`: the registry already had exactly this symbol (1,707);
- `conflict`: the registry has a different real name (86). Either side may be
  wrong; these are worth a look;
- `not in layout.tsv`: the address is a function start that `layout.tsv` does
  not list yet (830).

The full mapping output and its statistics are in
<https://github.com/sh1ftmaker/kh2> (`data/e3`, `docs/e3/mapping-stats.md`).
