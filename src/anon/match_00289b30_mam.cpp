// 00289b30 (w2493): 0 diffs ONLY with -O2 -fmove-all-movables (no build suffix for it yet). Plain -O2: loop.c finds lim-1 and the
// constant 1 'not desirable' to hoist (loop has 75 real insns, threshold ~60), giving 116 diffs. Twin 00289d28 matches with and without the flag.
#include "../common/types.h"
struct ListCur {
    s16 def_cur;
    u16 pad2;
    s16 rows;
    u8 pad6[12];
    s16 def_top;
    u16 pad20;
    s16 count;
    u8 pad24[12];
    u8 wrap;
};
extern "C" {
s32 func_0028b1c0(ListCur*, s32);
s32 func_00289b30(ListCur* o, s16* cur, s16* top) {
    s32 n = o->count;
    s32 lim = n;
    if (o->rows < n) lim = o->rows;
    u32 all = 0;
    s32 idx;
    for (s32 i = 0; i < n; i++) all |= 1 << i;
    u32 seen = 0;
    while (seen != all) {
        if (o->rows >= o->count) {
            if (*cur < lim - 1) (*cur)++;
            else if (o->wrap) *cur = 0;
        } else {
            if (*cur < o->rows - 1) (*cur)++;
            else if (o->wrap) {
                if (*top < o->count - o->rows) (*top)++;
                else { *top = 0; *cur = 0; }
            } else if (*top < o->count - o->rows) (*top)++;
        }
        idx = *top + *cur;
        if (!func_0028b1c0(o, idx)) break;
        seen |= 1 << idx;
    }
    if (seen == all) {
        *cur = o->def_cur;
        *top = o->def_top;
        idx = *top + *cur;
    }
    return idx;
}
}
