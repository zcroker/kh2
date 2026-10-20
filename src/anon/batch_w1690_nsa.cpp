#include "../common/types.h"
inline void* operator new(unsigned int, void* p) { return p; }
struct W1690Vec {
    f32 x, y, z, w;
    W1690Vec() {}
    W1690Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1690Vec(const W1690Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1690Vec& operator=(const W1690Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1690Mtx {
    W1690Vec r0, r1, r2, r3;
    W1690Mtx(const W1690Vec& a, const W1690Vec& b, const W1690Vec& c, const W1690Vec& d) : r0(a), r1(b), r2(c), r3(d) {}
    W1690Vec operator*(const W1690Vec& v) const {
        W1690Vec o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct W1690Pt { f32 x, y, z; };
extern "C" {
extern s8 D_01dadb10;
extern W1690Mtx D_01dadb20;
void func_00230d68(void);
void func_002fd188(void (*)(void));
f32 func_0022f8f0(const W1690Vec*, const W1690Vec*);
// Cubic Hermite interpolation: p0, p1 are the end points, t0, t1 the tangents.
// The basis matrix is a function-local static (guard D_01dadb10, empty atexit dtor func_00230d68).
void func_0022f928(W1690Pt* out, W1690Pt* p0, W1690Pt* p1, W1690Pt* t0, W1690Pt* t1, f32 t)
{
    if (!D_01dadb10) {
        W1690Vec r0(2.0f, -2.0f, 1.0f, 1.0f);
        W1690Vec r1(-3.0f, 3.0f, -2.0f, -1.0f);
        W1690Vec r2(0.0f, 0.0f, 1.0f, 0.0f);
        W1690Vec r3(1.0f, 0.0f, 0.0f, 0.0f);
        new (&D_01dadb20) W1690Mtx(r0, r1, r2, r3);
        D_01dadb10 = 1;
        func_002fd188(func_00230d68);
    }
    f32 t2 = t * t;
    W1690Vec v(t2 * t, t2, t, 1.0f);
    v = D_01dadb20 * v;
    W1690Vec x(p0->x, p1->x, t0->x, t1->x);
    W1690Vec y(p0->y, p1->y, t0->y, t1->y);
    W1690Vec z(p0->z, p1->z, t0->z, t1->z);
    out->x = func_0022f8f0(&v, &x);
    out->y = func_0022f8f0(&v, &y);
    out->z = func_0022f8f0(&v, &z);
}
}
