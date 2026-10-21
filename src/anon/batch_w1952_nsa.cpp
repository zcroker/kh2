#include "../common/types.h"
struct W1952V { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline __attribute__((always_inline)) void W1952Set(W1952V* d, const W1952V* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct W1952Vec { W1952V v; W1952Vec& operator=(const W1952Vec& o) { W1952Set(&v, &o.v); return *this; } };
struct W1952Seg { W1952Vec a, b; };
static inline __attribute__((always_inline)) W1952Vec operator-(const W1952Vec& a, const W1952Vec& b)
{ W1952Vec r; asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
static inline __attribute__((always_inline)) f32 W1952Len(const W1952Vec& a)
{ f32 r; asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a) : "$8", "memory"); return r; }
struct W1952Path {
    u8 pad[8];
    s32 n;            // 8
    u8 pad2[12];
    f32 t;            // 24
    u8 pad3[12];
    f32 len;          // 40
    u8 pad4[4];
    W1952Seg s0;      // 48
    W1952Seg s1;      // 80
};
extern "C" {
f32 func_002cdfb0(W1952Path*, s32*, f32*, W1952Vec*);
f32 func_002ce2a0(W1952Path*, s32*, f32*, W1952Vec*);
W1952Seg* func_002cb890(W1952Path*, s32);
W1952Vec func_002cd770(W1952Path*, W1952Seg*, W1952Seg*, f32);
f32 func_002ce6b8(W1952Path* p, W1952Vec* out, f32 lim) {
    s32 i;
    f32 f;
    f32 r = -1.0f;
    if (p->n >= 3) r = func_002cdfb0(p, &i, &f, out);
    if (r < 0.0f || r >= lim) r = func_002ce2a0(p, &i, &f, out);
    p->s0 = *func_002cb890(p, i);
    p->s1 = *func_002cb890(p, (i + 1) % p->n);
    p->t = (f32)i + f;
    W1952Vec d = p->s1.a - p->s0.a;
    p->len = W1952Len(d);
    W1952Vec q = func_002cd770(p, &p->s0, &p->s1, f);
    *out = q;
    return r;
}
}
