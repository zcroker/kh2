// func_001632c0 (zl90 w2404, 2026-10-26): needs -g and -fno-strict-aliasing (_gnsa). VU0 macro asm and lq/sq copy asm only.
// The hit code is written out in all three paths; crossjump merges it, and the block frequencies then give dd/de and the temps the original registers.
#include "../common/types.h"
extern "C" {
struct V2404g {
    f32 x, y, z, w;
    V2404g() {}
    V2404g& operator=(const V2404g& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2404g operator+(const V2404g& o) const {
        V2404g r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    V2404g operator-(const V2404g& o) const {
        V2404g r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    V2404g operator*(f32 s) const {
        V2404g r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    V2404g operator/(f32 s) const {
        V2404g r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.wxyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    f32 dot(const V2404g& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
struct Sphere2404g { V2404g c; f32 r; };
struct Seg2404g { V2404g a, b; };
s32 func_001632c0(Sphere2404g* s, Seg2404g* l, V2404g* out)
{
    s32 ret = 0;
    f32 t;
    V2404g c, d, e;
    c = (l->a + l->b) * 0.5f;
    d = l->b - c;
    e = s->c - c;
    f32 dd = d.dot(d);
    if (dd < 1.17549435e-38f) return 0;
    f32 ee = e.dot(e);
    f32 de = d.dot(e);
    f32 h = ee - de * de / dd;
    f32 r2 = s->r * s->r;
    if (r2 < h) return 0;
    V2404g w, p;
    p = c + d * de / dd;
    if (dd < de) {
        w = s->c - l->b;
        if (w.dot(w) <= r2) { t = __builtin_sqrtf((r2 - h) / dd); *out = p - d * t; ret = 1; }
    } else if (de < -dd) {
        w = s->c - l->a;
        if (w.dot(w) <= r2) { t = __builtin_sqrtf((r2 - h) / dd); *out = p - d * t; ret = 1; }
    } else {
        t = __builtin_sqrtf((r2 - h) / dd); *out = p - d * t; ret = 1;
    }
    return ret;
}
}
