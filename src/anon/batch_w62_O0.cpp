#include "../common/types.h"

extern "C" {
extern s32 D_01e21f40;
extern u8 D_01e22040[];
s32 func_003094b8(u8*, s32, s32, s32*, s32, s32*, s32, s32, s32);

// Byte-swaps a 32-bit word.
s32 func_002b8694(s32 x) {
    s32 b[4];
    b[0] = x & 0xff;
    b[1] = (x >> 8) & 0xff;
    b[2] = (x >> 16) & 0xff;
    b[3] = (x >> 24) & 0xff;
    return (b[0] << 24) | (b[1] << 16) | (b[2] << 8) | b[3];
}
}

// Retries the request until it is accepted; returns the value sent.
s32 func_002b8274(s32 x) {
    s32 r;
    D_01e21f40 = x;
    do {
        r = func_003094b8(D_01e22040, 1, 0, &D_01e21f40, 256, &D_01e21f40, 256, 0, 0);
    } while (r);
    return x;
}
