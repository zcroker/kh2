#include "../common/types.h"
extern "C" {
struct W1779Vec {
    f32 x, y, z, w;
    W1779Vec() {}
    W1779Vec(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; w = 0; }
} __attribute__((aligned(16)));
struct W1779Src { s32 m0; f32 x, y, z; };
struct W1779B { u8 pad[0x68]; u32 flags; W1779Src* src; };
struct W1779A { u8 pad[0x1c0]; W1779Vec pos; };
struct W1779R { u8 pad[0x14]; f32 range; };
W1779R* func_002d73f0(W1779A*);
// VU0: d = a - b (xyzw)
static inline void w1779_vsub(W1779Vec* d, const W1779Vec* a, const W1779Vec* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
// VU0: length of xyz
static inline f32 w1779_vlen(const W1779Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
s32 func_002d8910(W1779A* a, W1779B* b) {
    W1779Vec d;
    W1779Src* s = b->src;
    W1779Vec v(s->x, s->y, s->z);
    w1779_vsub(&d, &a->pos, &v);
    f32 len = w1779_vlen(&d);
    if (func_002d73f0(a)->range < len) return 0;
    return b->flags & 1;
}
}
