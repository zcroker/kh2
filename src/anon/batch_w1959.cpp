#include "../common/types.h"
#define W1959QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1959V {
    f32 x, y, z, w;
    W1959V() {}
    W1959V(const W1959V& o) { W1959QCOPY(this, &o); }
    W1959V& operator=(const W1959V& o) { if (this != &o) W1959QCOPY(this, &o); return *this; }
    void sub(const W1959V& a, const W1959V& b) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&a), "r"(&b) : "memory");
    }
    W1959V operator-(const W1959V& b) const {
        W1959V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 length() const {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W1959Sphere { W1959V c; f32 r; };
struct W1959Item { u32 pad0; f32 r; u32 pad8[2]; W1959V c; };
static inline f32 w1959_dist(const W1959V& a, const W1959V& b) {
    W1959V x;
    x = a;
    W1959V y;
    y = b;
    return (y - x).length();
}
extern "C" {
extern W1959Item* D_0034aa90;
extern s32 D_0034aa94;
s32 func_00163268(W1959Sphere*, W1959V*, f32*);
s32 func_001632c0(W1959Sphere*, W1959V*, W1959V*);
s32 func_0015a8d0(W1959V* seg, W1959V* out) {
    W1959V a = seg[0];
    W1959V b = seg[1];
    W1959V q;
    W1959V d;
    d.sub(seg[1], seg[0]);
    f32 len = d.length();
    W1959Item* it = D_0034aa90;
    s32 found = 0;
    s32 i;
    for (i = 0; i < D_0034aa94; i++) {
        W1959Sphere s;
        W1959V x;
        W1959V y;
        f32 t;
        f32 r = it->r;
        s.c = it->c;
        s.r = r;
        if (func_00163268(&s, &a, &t)) continue;
        if (func_001632c0(&s, &a, &q)) {
            x = a;
            y = q;
            d.sub(y, x);
            if (d.length() < len) {
                b = q;
                *out = b;
                found = 1;
            }
        }
        it++;
    }
    return found;
}
}
