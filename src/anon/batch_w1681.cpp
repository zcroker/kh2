#include "../common/types.h"
extern "C" {
// 4x4 float matrix (16-byte aligned rows), copied with lq/sq.
struct W1681Mtx {
    f32 m[4][4];
    W1681Mtx() {}
    W1681Mtx(const W1681Mtx& o)
    {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W1681Mtx& operator=(const W1681Mtx& o)
    {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// 4-float vector copied with one lq/sq.
struct W1681Vec4 {
    f32 v[4];
    W1681Vec4& operator=(const W1681Vec4& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// result = r * l (each row of r transforms the rows of l)
static inline W1681Mtx W1681Mul(const W1681Mtx& l, const W1681Mtx& r)
{
    W1681Mtx d;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                 : : "r"(&d), "r"(&l), "r"(&r) : "memory");
    return d;
}
// Field types below reproduce the original's alias sets: the scheduler order of the
// inlined record copy depends on which members may alias each other.
struct W1681Handle { void* p; };
union W1681Value { s32 i; s32* p; };
struct W1681Range { s32* begin; s32* end; } __attribute__((aligned(8)));
// 256-byte camera record (see func_00106a18).
struct W1681Cam {
    W1681Mtx world;     // 0
    f32 f40;            // 64
    W1681Handle h44;    // 68
    void* p48;          // 72
    s32 i4c;            // 76
    W1681Value v50;     // 80
    void* p54;          // 84
    W1681Range r58;     // 88
    s32* p60;           // 96
    f32 f64, f68, f6c, f70, f74, f78;  // 100
    W1681Mtx view;      // 128 (func_00106ad0)
    W1681Mtx clip;      // 192 (func_00106ae0)
};
// 144-byte record (see func_00106a60).
struct W1681Rec {
    W1681Vec4 v0;       // 0
    W1681Mtx m;         // 16
    W1681Vec4 v50, v60, v70;
    f32 f80;            // 128
};
struct W1681Obj {
    u8 pad0[32];
    W1681Cam cam;       // 32
    W1681Rec rec;       // 288
    W1681Mtx worldMul;  // 432
    W1681Mtx viewMul;   // 496
    W1681Mtx clipMul;   // 560
};
W1681Cam* func_00106a18(s32);
W1681Rec* func_00106a60(s32);
W1681Mtx* W1681_camView(W1681Cam*) asm("_ZN2dk11ViewFrustum9setMatrixERKN2kn7FMatrixE");
W1681Mtx* W1681_camClip(W1681Cam*) asm("_ZN2kn10Projection19getViewClipGsMatrixEv");
void func_00146680(W1681Mtx*, const W1681Mtx*);
// Takes a snapshot of the current camera and the current record, and precomputes the products.
void func_00145cb0(W1681Obj* o)
{
    o->cam = *func_00106a18(1);
    W1681Mtx view(*W1681_camView(&o->cam));
    W1681Mtx clip(*W1681_camClip(&o->cam));
    W1681Rec* d = &o->rec;
    W1681Rec* r = func_00106a60(1);
    d->m = r->m;
    d->v50 = r->v50;
    d->v60 = r->v60;
    d->v70 = r->v70;
    d->f80 = r->f80;
    o->worldMul = W1681Mul(o->cam.world, d->m);
    func_00146680(&o->viewMul, &W1681Mul(view, d->m));
    func_00146680(&o->clipMul, &W1681Mul(clip, d->m));
}
}
