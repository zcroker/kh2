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
s32 func_00289b30(ListCur* o, s16* cur, s16* top);  // 0x00289b30: definition moved into src/anon/unit_00288b00.cpp
}
