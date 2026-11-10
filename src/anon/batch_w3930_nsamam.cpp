#include "../common/types.h"
// func_001a7da8: spiral search for a free spot around s->pos (built with -fno-strict-aliasing -fmove-all-movables).
extern "C" {
struct V1a7da8 {
    f32 x, y, z, w;
    V1a7da8() {}
    V1a7da8(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V1a7da8(const V1a7da8& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct S1a7da8 {
    V1a7da8 pos;
    f32 bottom;
    f32 top;
    f32 angle;
    s32 count;
    s32 arg;
};
extern u32 D_003638d0;
f32 func_0017ce10(f32);
f32 func_002f8960(f32);
f32 func_002f87c0(f32);
s32 func_001a75d8(S1a7da8*, V1a7da8*, s32);
static inline void vmul(V1a7da8* r, const V1a7da8* a, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(r), "r"(a), "f"(s) : "$8");
}
static inline void vadd(V1a7da8* r, const V1a7da8* a, const V1a7da8* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(r), "r"(a), "r"(b));
}
static inline void vcpy(V1a7da8* d, const V1a7da8* s) {
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
V1a7da8 func_001a7da8(S1a7da8* s, f32 lo, f32 hi)
{
    V1a7da8 v;
    V1a7da8 p;
    V1a7da8 tsum;
    V1a7da8 tmul;
    while (s->top >= s->bottom) {
        f32 step = 0.7853981852531433f;
        f32 zero = 0.0f;
        f32 scale = 2.3283064365386963e-10f;
        f32 up = 20.0f;
        V1a7da8* pp = &p;
        V1a7da8* pm = &tmul;
        V1a7da8* pu = &tsum;
        s->count++;
        f32 a = func_0017ce10(s->angle + (f32)s->count * step);
        f32 sx = func_002f8960(a);
        f32 cz = func_002f87c0(a);
        v.x = sx; v.z = cz; v.y = zero; v.w = zero;
        vmul(pm, &v, s->top);
        vadd(pu, &s->pos, pm);
        vcpy(pp, pu);
        D_003638d0 *= 0x10dcd;
        p.y -= lo + (f32)D_003638d0 * scale * (hi - lo);
        vmul(pm, &v, s->top + up);
        vadd(pu, &s->pos, pm);
        vcpy(&v, pu);
        v.y = p.y - 100.0f;
        if (func_001a75d8(s, &v, s->arg)) return p;
        if (s->count >= 8) {
            s->count = 0;
            s->top -= 100.0f;
        }
    }
    return s->pos;
}
}
