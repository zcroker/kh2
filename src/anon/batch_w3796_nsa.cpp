#include "../common/types.h"
// Built with -fno-strict-aliasing (_nsa rule), like its sibling 002d8150
// (batch_w3794_nsa.cpp): by-value vector temporaries share stack slots the
// way the original's do.
// Partial inline asm: 128-bit lq/sq copies and the VU0 macro ops (matrix *
// vector, cross product, normalize, scale, rigid inverse), which gcc cannot
// emit from C. No register pins.
#define Q7_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define Q7_MCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t" \
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" \
                     : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct W2d7af0Vec {
    f32 x, y, z, w;
    W2d7af0Vec() {}
    W2d7af0Vec(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    W2d7af0Vec(const W2d7af0Vec& o) { *this = o; }
    W2d7af0Vec& operator=(const W2d7af0Vec& o) { if (this != &o) Q7_QCOPY(this, &o); return *this; }
    W2d7af0Vec& operator*=(f32 s) { asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(s) : "$8", "memory"); return *this; }
    f32 Normalize() {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
            : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
static inline W2d7af0Vec Q7Cross(const W2d7af0Vec& a, const W2d7af0Vec& b) {
    W2d7af0Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct W2d7af0Mtx {
    W2d7af0Vec r0, r1, r2, r3;
    W2d7af0Mtx() {}
    W2d7af0Mtx(const W2d7af0Mtx& o) { Q7_MCOPY(this, &o); }
    W2d7af0Mtx& operator=(const W2d7af0Mtx& o) { if (this != &o) Q7_MCOPY(this, &o); return *this; }
    W2d7af0Vec operator*(const W2d7af0Vec& v) const {
        W2d7af0Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    // Inverse of a rigid transform: transpose the rotation, translation = -(R^T t).
    void InvertOrtho() {
        asm volatile(".set noreorder\n\tlq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
                     "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
                     "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
                     "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
                     "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
                     : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
extern "C" {
struct Seg2d7af0 {
    W2d7af0Vec a, b;
    Seg2d7af0() {}
    Seg2d7af0(const W2d7af0Vec& pa, const W2d7af0Vec& pb) { a = pa; b = pb; }
    void Set(W2d7af0Vec pa, W2d7af0Vec pb) { a = pa; b = pb; }
};
struct X2d7af0 { u8 pad[193]; u8 off; u8 pad2[14]; W2d7af0Mtx base; W2d7af0Mtx cur; u8 pad3[468 - 336]; f32 hi, lo; };
s32 func_00143dd0(Seg2d7af0*, W2d7af0Vec*, u16*, s32, s32);
W2d7af0Vec func_00143e50(u16, s32);
s32 func_002d8898(X2d7af0*);

// Ti minigame camera: drop the base matrix onto the ground (ray test from
// y=-150 to y=+250), rebuild its axes from the hit triangle's normal, store it
// as the current matrix, then probe left/right (x=-600/+600 at y=-80) and keep
// the hit points' local x as the lo/hi limits.
void func_002d7af0(X2d7af0* x)
{
    if (x->off) x->cur = x->base;
    W2d7af0Mtx m(x->base);
    W2d7af0Vec& up = m.r1;
    W2d7af0Vec& pos = m.r3;
    W2d7af0Vec hit;
    W2d7af0Vec p0, p1;
    Seg2d7af0 seg;
    u16 id;
    p0 = m * W2d7af0Vec(0.0f, -150.0f, 0.0f, 1.0f);
    p1 = m * W2d7af0Vec(0.0f, 250.0f, 0.0f, 1.0f);
    seg.Set(p0, p1);
    if (!func_00143dd0(&seg, &hit, &id, 1, 15)) {
        x->cur = m;
        return;
    }
    pos = hit;
    up = func_00143e50(id, 0);
    up *= -1.0f;
    m.r0 = Q7Cross(up, x->base.r2);
    m.r2 = Q7Cross(m.r0, up);
    m.r0.Normalize();
    up.Normalize();
    m.r2.Normalize();
    m.r0.w = 0.0f;
    m.r1.w = 0.0f;
    m.r2.w = 0.0f;
    x->cur = m;
    if (func_002d8898(x)) {
        W2d7af0Vec c = m * W2d7af0Vec(0.0f, -80.0f, 0.0f, 1.0f);
        W2d7af0Vec l = m * W2d7af0Vec(-600.0f, -80.0f, 0.0f, 1.0f);
        W2d7af0Vec r = m * W2d7af0Vec(600.0f, -80.0f, 0.0f, 1.0f);
        Seg2d7af0 sr(c, r), sl(c, l);
        W2d7af0Vec hl, hr;
        u16 id2;
        s32 a = func_00143dd0(&sr, &hr, &id2, 2, 15);
        s32 b = func_00143dd0(&sl, &hl, &id2, 2, 15);
        if (!a && !b) {
            x->hi = 0.0f;
            x->lo = 0.0f;
        } else {
            hl.w = 1.0f;
            hr.w = 1.0f;
            m.InvertOrtho();
            hl = m * hl;
            hr = m * hr;
            x->hi = hr.x;
            x->lo = hl.x;
        }
    }
}
}
