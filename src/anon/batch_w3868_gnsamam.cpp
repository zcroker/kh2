// func_00164d60 (w3868): segment-to-polygon edge test, a sibling of func_00162c28 (batch_w3846_gnsa.cpp):
// project the point c onto each edge line, keep the hits inside the edge box (with the end points),
// return the nearest one. Needs -g, -fno-strict-aliasing and -fmove-all-movables (_gnsamam).
// Inline asm: VU0 macro ops and lq/sq 128-bit copies only (the sibling's helpers).
#include "../common/types.h"
inline void* operator new(unsigned int, void* p) { return p; }
extern "C" {
struct W3868V {
    f32 x, y, z, w;
    W3868V() {}
    W3868V(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    ~W3868V() {}
    W3868V& operator=(const W3868V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W3868V operator+(const W3868V& o) const {
        W3868V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W3868V operator-(const W3868V& o) const {
        W3868V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W3868V operator*(f32 s) const {
        W3868V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    f32 dot(const W3868V& o) const {
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
static inline __attribute__((always_inline)) f32 W3868Dist2(const W3868V& a, const W3868V& b) {
    f32 r;
    asm volatile("lqc2 $vf6, 0(%1)\n\tlqc2 $vf4, 0(%2)\n\tvsub.wxyz $vf5, $vf6, $vf4\n\tvmove.wxyz $vf4, $vf5\n\tvmul.xyz $vf5, $vf4, $vf5\n\tvaddy.x $vf5, $vf5, $vf5y\n\tvaddz.x $vf5, $vf5, $vf5z\n\tqmfc2 $2, $vf5\n\tmtc1 $2, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$2");
    return r;
}
struct W3868Line { W3868V o, d; };
struct W3868Poly { W3868V* v[4]; s32 n; };
extern s8 D_004f41a0;
extern W3868V D_004f41b0;
extern const s32 D_0034c780[];
extern const s32 D_0034c790[];
void func_001656b8(void);
void func_002fd188(void (*)(void));

static inline __attribute__((always_inline)) bool W3868InBox(const W3868V& p, const W3868V& lo, const W3868V& hi) {
    s32 o;
    o = p.x < lo.x; if (hi.x < p.x) { if ((o ^ 1) == 0) goto yes; } else if (o == 0) goto yes;
    o = p.y < lo.y; if (hi.y < p.y) { if ((o ^ 1) == 0) goto yes; } else if (o == 0) goto yes;
    o = p.z < lo.z; if (hi.z < p.z) { if ((o ^ 1) == 0) goto yes; } else if (o == 0) goto yes;
    o = 0; return o;
yes:
    o = 1; return o;
}
s32 func_00164d60(void* self, W3868Poly* p, W3868V* c, W3868V* out, W3868V* outA, W3868V* outB);  // 0x00164d60: definition moved into src/anon/unit_00164578.cpp
}
