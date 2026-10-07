#include "../common/types.h"

extern "C" {
u32 func_002b82f8(void) asm("_Z13func_002b82f8Pv");
s32 func_002b6708(s32, s32, s32, s32, s32, s32);
s32 func_003094b8(void*, s32, s32, void*, s32, void*, s32, s32, s32);
extern u8 D_01e22040[];
extern u32 D_01e21f40[];

s32 func_002b7d5c(s32 a, s32 b, s32 c, s32 d) {
    return func_002b6708(5, 32, a, b, c, d);
}

// Retry until the call succeeds (returns 0), then read the first result word.
u32 func_002b82f8(void) {
    s32 r;
    ;
    do {
        r = func_003094b8(D_01e22040, 2, 0, D_01e21f40, 256, D_01e21f40, 256, 0, 0);
    } while (r != 0);
    return D_01e21f40[0];
}
}
