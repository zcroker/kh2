#include "../common/types.h"

struct W1795V4 { f32 x, y, z, w;
  W1795V4() {}
  W1795V4& operator=(const W1795V4& o) { if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
// VU0 helpers: vector subtract, multiply and 3-component dot product.
static inline W1795V4 operator-(const W1795V4& a, const W1795V4& b) {
    W1795V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline W1795V4 operator*(const W1795V4& a, const W1795V4& b) {
    W1795V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 w1795_dot(const W1795V4& a, const W1795V4& b) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
struct W1795Ob { f32 f0, y, z, w; W1795V4 p; };
struct W1795Ob2 { u8 pad[0x1f]; u8 kind; };

extern "C" {
// Is b inside the ellipse around a (radii from the y/z sums)?
s32 func_0018a250(W1795Ob* a, W1795Ob* b) {
    W1795V4 m;
    W1795V4 s;
    f32 r = 1.0f / (a->y + b->y);
    s.z = r;
    s.y = 1.0f / (a->z + b->z);
    s.x = r;
    m = (b->p - a->p) * s;
    return w1795_dot(m, m) < 1.0f;
}

s32 func_0019c218(s32, W1795Ob2*);
s32 W1795_ctarget(s32) asm("_Z16ctarget_0019ba60jjjj");
s32 func_001b8f10(W1795Ob2* o, s32 a, s32* p) {
    switch (o->kind) {
    case 0: if (func_0019c218(a, o)) return 1; break;
    case 1: if (p) W1795_ctarget(*p); if (func_0019c218(*p, o)) return 1; break;
    case 2: if (p) W1795_ctarget(*p); if (func_0019c218(a, o) && func_0019c218(*p, o)) return 1; break;
    }
    return 0;
}
}
