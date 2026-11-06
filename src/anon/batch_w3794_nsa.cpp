#include "../common/types.h"
// Built with -fno-strict-aliasing (_nsa rule): the by-value temporaries share
// stack slots the way the original's do.
// Partial inline asm: 128-bit lq/sq copies and the VU0 macro ops (lqc2/sqc2,
// vmula/vmadd, vadd), which gcc cannot emit from C.
#define W2d8150_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W2d8150Vec {
    f32 x, y, z, w;
    W2d8150Vec() {}
    W2d8150Vec(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    W2d8150Vec& operator+=(const W2d8150Vec& b) { asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory"); return *this; }
    W2d8150Vec(const W2d8150Vec& o) { *this = o; }
    W2d8150Vec& operator=(const W2d8150Vec& o) { if (this != &o) W2d8150_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W2d8150Mtx {
    W2d8150Vec r0, r1, r2, r3;
    W2d8150Mtx() {}
    W2d8150Mtx(const W2d8150Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    // translation.xyz += v.xyz
    void AddTransXYZ(const W2d8150Vec& b) { asm volatile(".set noreorder\n\tlqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory"); }
    // VU0 matrix * column vector.
    W2d8150Vec operator*(const W2d8150Vec& v) const {
        W2d8150Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
extern "C" {
struct Seg2d8150 {
    W2d8150Vec a, b;
    void Set(W2d8150Vec pa, W2d8150Vec pb) { a = pa; b = pb; }
};
struct X2d8150 { u8 pad[193]; u8 off; u8 pad2[14]; W2d8150Vec r0, r1, r2; u8 pad3[468 - 256]; f32 hi, lo; };
s32 func_00143dd0(Seg2d8150*, W2d8150Vec*, u16*, s32, s32);
W2d8150Mtx c2d8150(X2d8150*, f32*, const W2d8150Mtx&, f32) asm("_Z16ctarget_002d8150jjjj");

// Camera matrix for the Ti minigame: copy the base matrix, clamp the height *y
// between lo+30 and hi-30, shift along the matrix x axis by it, drop onto the
// ground found by a ray test from y=-100 to y=+100, then take the rotation rows
// from x and add the height offset h.
W2d8150Mtx c2d8150(X2d8150* x, f32* y, const W2d8150Mtx& base, f32 h)
{
    W2d8150Mtx m(base);
    if (x->off) {
        *y = 0.0f;
        return m;
    }
    if (x->hi - 30.0f < x->lo + 30.0f) {
        *y = (x->hi + x->lo) * 0.5f;
    } else {
        if (*y < x->lo + 30.0f) *y = x->lo + 30.0f;
        if (x->hi - 30.0f < *y) *y = x->hi - 30.0f;
    }
    W2d8150Vec hit;
    W2d8150Vec p0, p1;
    Seg2d8150 seg;
    u16 id;
    W2d8150Vec d = m * W2d8150Vec(*y, 0.0f, 0.0f, 0.0f);
    m.AddTransXYZ(d);
    p0 = m * W2d8150Vec(0.0f, -100.0f, 0.0f, 1.0f);
    p1 = m * W2d8150Vec(0.0f, 100.0f, 0.0f, 1.0f);
    seg.Set(p0, p1);
    if (func_00143dd0(&seg, &hit, &id, 1, 15)) m.r3 = hit;
    W2d8150Vec t = m * W2d8150Vec(0.0f, h, 0.0f, 0.0f);
    m.r0 = x->r0;
    m.r1 = x->r1;
    m.r2 = x->r2;
    m.r3 += t;
    return m;
}
}
