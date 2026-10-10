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
void func_001e0e50(W333E48*);
s32 func_001e0fd0(W333E48*);
void func_001e0f90(W333E48*);
}

/* Random pick in [0, m): seed *= 69069; seed / ceil(2^32 / m). */
static inline s32 W333Rand(u32 m) {
    D_003638d0[0] *= 0x10dcd;
    return (u64)D_003638d0[0] / ((0x100000000ull + (m - 1)) / m);
}

extern "C" {

void func_001e1e40(W333O* o) {
    if (o->e00 < 0) o->e00 = func_002bc1e8(0x5b518);
    while (o->df4 <= o->de4) {
        for (s32 i = 0; i < o->n; i++) {
            W333E48* e = (W333E48*)(W333Rand(o->n) * sizeof(W333E48) + o->arru);
            if (e->w24 == 2) {
                func_001e0e50(e);
                break;
            }
        }
        o->de4 -= o->df4;
    }
    f32 de8 = o->de8;
    f32 v = o->df4 + D_00349e10[0] * -0.04f;
    o->df4 = v;
    if (de8 < 900.0f) { if (!(0.5f < v)) v = 0.5f; } else { if (!(0.15f < v)) v = 0.15f; }
    o->df4 = v;
    if (1560.0f < o->de8) {
        while (o->df8 <= o->dfc) {
            for (s32 i = 0; i < o->n; i++) {
                s32 idx = W333Rand(o->n);
                if (func_001e0fd0(&o->arr[idx])) {
                    func_001e0f90(&o->arr[idx]);
                    break;
                }
            }
            o->dfc -= o->df8;
        }
        o->dfc += D_00349e10[0];
        o->df8 += D_00349e10[0] * -0.05f;
        o->df8 = o->df8 < 0.01f ? 0.01f : (10.0f < o->df8 ? 10.0f : o->df8);
    }
}

}
