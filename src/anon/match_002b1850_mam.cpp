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
s32 func_002ac420(u8);
s32 func_002ac538(u8);
extern s32 D_0035f200;
extern Ent2b1* D_0035f630;
extern s32 D_00374c9c;
extern s32 D_00374ca0;
void func_002b1850(void) {
    Obj2b1* base = func_002766d0();
    s32 n = func_002892f8(D_0035f200);
    s32 i;
    for (i = 0; i < n; i++) func_00138c10(&base->items[i], 2);
    s32 j = 0;
    n = func_0028afa8(D_0035f200);
    for (i = 0; i < n; i++) {
        s32 found = -1;
        for (; j < 10; j++) {
            if (D_0035f630[j].flags & 0x1000000) {
                found = j;
                func_002891b8(D_0035f200, i)->p = &D_0035f630[j].rest;
                j++;
                break;
            }
        }
        if (found < 0) break;
        if ((D_0035f630[found].flags & 0x3000000) == 0x3000000 && func_002ac420(((u8*)&D_0035f630[found])[2])) {
            s32 a;
            if (func_002ac538(((u8*)&D_0035f630[found])[2])) a = D_00374ca0;
            else a = D_00374c9c;
            func_00138c10(&base->items[i], a);
        }
    }
}
}
