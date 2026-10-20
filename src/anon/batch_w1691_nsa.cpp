#include "../common/types.h"
// Uniform cubic B-spline point evaluation (needs -fno-strict-aliasing: the four freed
// basis-row temporaries are merged into one stack slot, which fixes the local layout).
inline void* operator new(unsigned int, void* p) { return p; }
#define W1691_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1691Vec {
    f32 x, y, z, w;
    W1691Vec() {}
    W1691Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1691Vec(const W1691Vec& o) { W1691_QCOPY(this, &o); }
    W1691Vec& operator=(const W1691Vec& o) { if (this != &o) W1691_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1691Mtx {
    W1691Vec r0, r1, r2, r3;
    W1691Mtx(const W1691Vec& a, const W1691Vec& b, const W1691Vec& c, const W1691Vec& d) : r0(a), r1(b), r2(c), r3(d) {}
    // VU0 matrix * column vector.
    W1691Vec operator*(const W1691Vec& v) const {
        W1691Vec o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct W1691Point { f32 x, y, z; };
extern "C" {
f32 func_0022f8f0(const W1691Vec* a, const W1691Vec* b); // vec4_dot
extern s8 D_01dadb60;         // basis-matrix init guard
extern W1691Mtx D_01dadb70;   // B-spline basis matrix
void func_00230d70(void);     // basis-matrix destructor (empty)
void func_002fd188(void (*)(void)); // atexit-style registration

// out = B-spline point at parameter t for control points p0..p3.
void func_0022fb98(W1691Point* out, f32 t, const W1691Point* p0, const W1691Point* p1, const W1691Point* p2, const W1691Point* p3) {
    if (!D_01dadb60) {
        W1691Vec r0(-1.0f / 6, 0.5f, -0.5f, 1.0f / 6);
        W1691Vec r1(0.5f, -1.0f, 0.5f, 0.0f);
        W1691Vec r2(-0.5f, 0.0f, 0.5f, 0.0f);
        W1691Vec r3(1.0f / 6, 2.0f / 3, 1.0f / 6, 0.0f);
        new (&D_01dadb70) W1691Mtx(r0, r1, r2, r3);
        D_01dadb60 = 1;
        func_002fd188(func_00230d70);
    }
    W1691Vec c(t * t * t, t * t, t, 1.0f);
    c = D_01dadb70 * c;
    W1691Vec px(p0->x, p1->x, p2->x, p3->x);
    W1691Vec py(p0->y, p1->y, p2->y, p3->y);
    W1691Vec pz(p0->z, p1->z, p2->z, p3->z);
    out->x = func_0022f8f0(&c, &px);
    out->y = func_0022f8f0(&c, &py);
    out->z = func_0022f8f0(&c, &pz);
}
}
