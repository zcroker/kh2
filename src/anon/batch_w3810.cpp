#include "../common/types.h"
#define W1df2c0_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1df2c0Vec {
    f32 x, y, z, w;
    W1df2c0Vec() {}
    W1df2c0Vec(const W1df2c0Vec& o) { W1df2c0_QCOPY(this, &o); }
    W1df2c0Vec& operator=(const W1df2c0Vec& o) { if (this != &o) W1df2c0_QCOPY(this, &o); return *this; }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W1df2c0Mtx {
    W1df2c0Vec r0, r1, r2, r3;
    W1df2c0Mtx() {}
    W1df2c0Mtx(const W1df2c0Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W1df2c0Mtx& operator=(const W1df2c0Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * matrix (each column of b transformed by this).
    void mul(const W1df2c0Mtx& a, const W1df2c0Mtx& b) {
        W1df2c0Mtx& o = *this;
        asm volatile(".set noreorder\n\t"
                     "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                     : : "r"(&o), "r"(&a), "r"(&b) : "memory");
    }
    // VU0 matrix * column vector.
    W1df2c0Vec operator*(const W1df2c0Vec& v) const {
        W1df2c0Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
extern "C" {
struct Src1df2c0 { u8 pad[28]; f32 a[3], b[3], c[3]; };
struct Cam1df2c0 { s32 v; u8 pad[12]; };
struct O1df2c0 { u8 pad[64]; void* h; Src1df2c0* src; };
void func_00102180(Cam1df2c0*);
s32 func_00104190(void);
u8* func_00106a60(s32);
void func_0011b6a8(W1df2c0Mtx*);
void func_0011b7b0(W1df2c0Mtx*, W1df2c0Vec*);
W1df2c0Vec* func_001dc5f8(void*);
void func_0011bac8(W1df2c0Mtx*, W1df2c0Vec*);
W1df2c0Vec* func_001dc648(void*);
f32 func_0017ce10(f32);
W1df2c0Vec* func_001dc620(void*);
// View-relative transform: inverse camera view times local transform; writes position, normalised rotation axes and scale slots.
void func_001df2c0(O1df2c0* oo)
{
    register O1df2c0* o asm("$18") = oo; // pin: keeps o in s2 (global-alloc priority otherwise swaps it with mp)
    Src1df2c0* s = o->src;
    W1df2c0Vec pos, rot, scale;
    pos.x = s->a[0];
    pos.y = s->a[1];
    pos.z = s->a[2];
    rot.x = s->b[0];
    rot.y = s->b[1];
    rot.z = s->b[2];
    scale.x = s->c[0];
    scale.y = s->c[1];
    scale.z = s->c[2];
    W1df2c0Mtx view, r, m, prod;
    W1df2c0Mtx* vp = &view;
    pos.w = 1.0f;
    rot.w = 0.0f;
    scale.w = 0.0f;
    Cam1df2c0 cam;
    func_00102180(&cam);
    u8* p;
    if (cam.v == func_00104190()) p = func_00106a60(0);
    else p = func_00106a60(1);
    *vp = *(W1df2c0Mtx*)(p ? p + 16 : 0);
    W1df2c0Vec* r0 = &r.r0; W1df2c0Vec* r1 = &r.r1; W1df2c0Vec* r2 = &r.r2; W1df2c0Vec* r3 = &r.r3; W1df2c0Mtx* mp = &m; W1df2c0Vec* m3 = &m.r3;
    vp->invOrtho();
    func_0011b6a8(mp);
    func_0011b7b0(mp, &rot);
    *m3 = pos;
    m3->w = 1.0f;
    prod.mul(*vp, *mp);
    *(W1df2c0Mtx*)r0 = prod;
    *func_001dc5f8(o->h) = *r3;
    r0->normalize();
    r1->normalize();
    r2->normalize();
    r3->unit();
    func_0011bac8((W1df2c0Mtx*)r0, func_001dc648(o->h));
    func_001dc648(o->h)->x = func_0017ce10(func_001dc648(o->h)->x);
    func_001dc648(o->h)->y = func_0017ce10(func_001dc648(o->h)->y);
    func_001dc648(o->h)->z = func_0017ce10(func_001dc648(o->h)->z);
    *func_001dc620(o->h) = scale;
}




}
