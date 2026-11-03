// 001628d8: ray vs triangle plane hit (VU0 dot products), then point-in-triangle test.
// Register pins: an empty-asm value held in t6 across the body (no code) pushes pp/&ray->dir
// to t4/t5 like the original; the closest plain C draft (coord/best/001628d8.cpp) had them in t5/t6.
#include "../common/types.h"
struct V1628 {
    f32 x, y, z, w;
    V1628() {}
    V1628& operator=(const V1628& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Ray1628 { V1628 pos; V1628 dir; };
static inline f32 dot(const V1628* a, const V1628* b) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
static inline V1628 mul(const V1628& v, f32 s) {
    V1628 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
    return r;
}
static inline V1628 add(const V1628& a, const V1628& b) {
    V1628 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
extern "C" {
s32 func_00162560(V1628**, V1628*);
s32 func_001628d8(Ray1628* ray, V1628** pp, V1628* n, V1628* out)
{
    register s32 k asm("$14");  // pin: occupies t6 (no code)
    asm("" : "=r"(k));
    f32 d = dot(n, &ray->dir);
    if (0.0f <= d) return 0;
    f32 a = dot(n, *pp);
    f32 b = dot(n, &ray->pos);
    f32 t = (a - b) / d;
    if (1.0f < t) return 0;
    if (t < 0.0f) return 0;
    *out = mul(ray->dir, t);
    *out = add(*out, ray->pos);
    out->w = 1.0f;
    asm("" : : "r"(k));
    return func_00162560(pp, out) != 0;
}
}
