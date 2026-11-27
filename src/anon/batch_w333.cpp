#include "../common/types.h"

struct W333E48 { u8 pad[36]; s32 w24; u8 pad2[8]; };
struct W333O {
    u8 pad[0xdc8];
    union { W333E48* arr; u32 arru; };
    s32 n;          /* dcc */
    u8 pad2[0xde4 - 0xdd0];
    union { f32 de4; u32 de4u; };
    f32 de8;
    u8 pad3[0xdf4 - 0xdec];
    union { f32 df4; u32 df4u; };
    f32 df8;
    f32 dfc;
    s32 e00;
};

extern "C" {
extern u32 D_003638d0[];
extern f32 D_00349e10[];
s32 func_002bc1e8(s32);
void ryj__LASER__attack(W333E48*);
s32 func_001e0fd0(W333E48*);
void func_001e0f90(W333E48*);
}

/* Random pick in [0, m): seed *= 69069; seed / ceil(2^32 / m). */
static inline s32 W333Rand(u32 m) {
    D_003638d0[0] *= 0x10dcd;
    return (u64)D_003638d0[0] / ((0x100000000ull + (m - 1)) / m);
}

extern "C" {

void func_001e1e40(W333O* o);  // 0x001e1e40: definition moved into src/anon/unit_001e0cb8.cpp

}
