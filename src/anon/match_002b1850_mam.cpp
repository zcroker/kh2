// w2486: 0 diffs (cmp2, branch-aware) ONLY with -O2 -fmove-all-movables (both -g0 and -g); 93 under plain -O2. Needs a new build suffix (e.g. _mam).
// New vs earlier drafts: m reuses n (one variable), &base->items[i] inside loop instead of walking it pointer.
#include "../common/types.h"
struct Item2b1 { u8 pad[408]; };
struct Obj2b1 { u8 pad[0xa998]; Item2b1 items[1]; };
struct Ent2b1 { u32 flags; u8 rest[32]; };
struct Res2b1 { u8 pad[408]; void* p; };
extern "C" {
Obj2b1* func_002766d0();
s32 func_002892f8(s32);
s32 func_0028afa8(s32);
Res2b1* func_002891b8(s32, s32);
void func_00138c10(Item2b1*, s32);
s32 Tz__JmNewInfo__isPuzzlePieceNew(u8);
s32 func_002ac538(u8);
extern s32 D_0035f200;
extern Ent2b1* D_0035f630;
extern s32 D_00374c9c;
extern s32 D_00374ca0;
void func_002b1850(void);  // 0x002b1850: definition moved into src/anon/unit_002b0950.cpp
}
