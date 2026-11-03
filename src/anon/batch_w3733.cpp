#include "../common/types.h"
extern "C" {
s32 func_00242618(s32, u8);

// Picks a mode for a selection value a and passes it to func_00242618 with e.
// k is pinned to t5 (the original keeps it there; unpinned gcc puts it in t6).
s32 func_00287df0(s32 a, u8 b, u8 c, s32 (*d)(void), u8 e) {
    register s32 k asm("$13");
    if (b != 0) k = 1;
    else if (a == -2) k = 3;
    else if ((u32)(a + 13) < 2) k = 1;
    else if (a == -4) { s32 t = c ? 5 : 4; k = t; }
    else {
        if ((u32)(a + 7) < 3) goto L;
        if ((u32)(a + 9) < 2) goto L;
        if ((u32)(a + 11) < 2) goto L;
        if (a < 0) return 0;
    L:
        k = 2;
        if (d) k = d() ? 2 : 4;
    }
    return func_00242618(k, e);
}
}
