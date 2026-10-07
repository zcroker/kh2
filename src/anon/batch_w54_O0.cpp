#include "../common/types.h"

extern "C" {

s32 func_002b6708(s32, s32, ...);
s32 func_002b797c(s32 a, s32 b, s32 c) {
    return func_002b6708(4, 28, a, b, c);
}

s32 func_002b7f3c(s32 a, s32 b) {
    return func_002b6708(3, 48, a, b);
}

s32 func_003094b8(void*, s32, s32, void*, s32, void*, s32, s32, s32);
extern u8 D_01e22040[];
extern s32 D_01e21f40;
s32 func_002b84b8(void) {
    s32 r;
    do {
        r = func_003094b8(D_01e22040, 4, 0, &D_01e21f40, 256, &D_01e21f40, 256, 0, 0);
    } while (r != 0);
    return D_01e21f40;
}

}
