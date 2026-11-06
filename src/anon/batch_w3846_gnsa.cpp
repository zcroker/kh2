// func_00162c28 (w3846): sphere vs polygon (3 or 4 vertices) hit test. Needs -g and -fno-strict-aliasing (_gnsa).
// Inline asm: VU0 macro ops and lq/sq 128-bit copies only (same helpers as func_001632c0); the
// function-static epsilon vector is written as an explicit guard + atexit (func_002fd188) like func_0022fb98.
#include "../common/types.h"
inline void* operator new(unsigned int, void* p) { return p; }
extern "C" {
struct W3846V {
    f32 x, y, z, w;
    W3846V() {}
    W3846V(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    ~W3846V() {}
    W3846V& operator=(const W3846V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W3846V operator+(const W3846V& o) const {
        W3846V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W3846V operator-(const W3846V& o) const {
        W3846V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W3846V operator*(f32 s) const {
        W3846V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    f32 dot(const W3846V& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o) : "$8");
        return r;
    }
    f32 lenSq() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
static inline __attribute__((always_inline)) f32 W3846Dist2(const W3846V& a, const W3846V& b) {
    f32 r;
    asm volatile("lqc2 $vf6, 0(%1)\n\tlqc2 $vf4, 0(%2)\n\tvsub.wxyz $vf5, $vf6, $vf4\n\tvmove.wxyz $vf4, $vf5\n\tvmul.xyz $vf5, $vf4, $vf5\n\tvaddy.x $vf5, $vf5, $vf5y\n\tvaddz.x $vf5, $vf5, $vf5z\n\tqmfc2 $2, $vf5\n\tmtc1 $2, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$2");
    return r;
}
struct W3846Line { W3846V o, d; };
struct W3846Sphere { W3846V c; f32 r; };
struct W3846Poly { W3846V* v[4]; s32 n; };
extern s8 D_004f4180;
extern W3846V D_004f4190;
extern const s32 D_0034c780[];
extern const s32 D_0034c790[];
void func_00163520(void);
void func_002fd188(void (*)(void));

static inline __attribute__((always_inline)) bool W3846InBox(const W3846V& p, const W3846V& lo, const W3846V& hi) {
    s32 o;
    o = p.x < lo.x; if (hi.x < p.x) { if ((o ^ 1) == 0) goto yes; } else if (o == 0) goto yes;
    o = p.y < lo.y; if (hi.y < p.y) { if ((o ^ 1) == 0) goto yes; } else if (o == 0) goto yes;
    o = p.z < lo.z; if (hi.z < p.z) { if ((o ^ 1) == 0) goto yes; } else if (o == 0) goto yes;
    o = 0; return o;
yes:
    o = 1; return o;
}
s32 func_00162c28(W3846Sphere* s, W3846Poly* p, W3846V* out) {
    if (!D_004f4180) {
        new (&D_004f4190) W3846V(0.008f, 0.008f, 0.008f, 1.0f);
        D_004f4180 = 1;
        func_002fd188(func_00163520);
    }
    f32 r2 = s->r * s->r;
    s32 cnt = 0;
    W3846V buf[4];
    s32 n = p->n;
    const s32* next = n == 3 ? D_0034c780 : D_0034c790;
    s32 i;
    for (i = 0; i < n; i++) {
        W3846V* pa = p->v[i];
        W3846V* pb = p->v[next[i]];
        W3846V a; a = *pa;
        W3846V b; b = *pb;
        W3846Line l;
        l.o = a;
        l.d = b - a;
        l.d.w = 1.0f;
        l.o.w = 1.0f;
        *out = l.d * -((l.o - s->c).dot(l.d) / l.d.lenSq()) + l.o;
        if (W3846Dist2(s->c, *out) <= r2) {
            W3846V lo = a + D_004f4190;
            W3846V hi = b + D_004f4190;
            if (W3846InBox(*out, lo, hi)) buf[cnt++] = *out;
        }
    }
    if (cnt != 0) {
        if (cnt == 1) { *out = buf[0]; return 1; }
        f32 best = 99999991988224.0f;
        s32 idx = 0;
        for (s32 j = 0; j < cnt; j++) {
            f32 d = W3846Dist2(s->c, buf[j]);
            if (d < best) { best = d; idx = j; }
        }
        *out = buf[idx];
        return 1;
    }
    f32 best = r2;
    s32 idx = 4;
    for (s32 k = 0; k < n; k++) {
        f32 d = W3846Dist2(s->c, *p->v[k]);
        if (d <= best) { best = d; idx = k; }
    }
    if (idx != 4) { *out = *p->v[idx]; return 1; }
    return 0;
}
}
