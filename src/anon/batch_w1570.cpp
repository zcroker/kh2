#include "../common/types.h"
// VU0 random float in [0,1) (the game's inline vrnext sequence).
static inline f32 vu0Rand_1ed140(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}
extern "C" {
struct A1ed140 { s32 id; s32 idx; f32 a, b, c; u8 flag; };
struct B1ed140 { u8 pad[12]; s32* off; };
f32 func_001ed130(f32, f32);
extern s32 D_01d9ea9c;
extern u8* D_01d9e6e0;
extern f32 D_01d9e360[];
void func_001ed140(u8* p, A1ed140* __restrict a, B1ed140* b) {
    f32* base;
    f32* d;
    if (D_01d9ea9c != 0) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (*(s32*)(p + 12) == 0) {
        f32 r = vu0Rand_1ed140();
        if (a->flag != 0) r = r + vu0Rand_1ed140();
        else r = r + r;
        base = (f32*)(p + *b->off + 160);
        *base = r;
    } else {
        if (a->id != *(s32*)(p + 12)) return;
        base = (f32*)(p + *b->off + 160);
    }
    if (a->idx != -1) d = (f32*)(p + a->idx + 160);
    else d = D_01d9e360;
    f32 t;
    t = *base; d[0] += func_001ed130(a->a, t);
    d[1] += func_001ed130(a->b, *base);
    d[2] += func_001ed130(a->c, *base);
}
}
