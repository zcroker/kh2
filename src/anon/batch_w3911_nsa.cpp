#include "../common/types.h"
#define W2dc988_QCOPY(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
struct W2dc988Vec {
    f32 x, y, z, w;
    W2dc988Vec() {}
    W2dc988Vec(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    void AddXYZ(const W2dc988Vec& b) { asm volatile(".set noreorder\n\tlqc2 $vf1, %0\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0\n\t.set reorder" : "+m"(*this) : "r"(&b) : "memory"); }
    W2dc988Vec(const W2dc988Vec& o) { W2dc988_QCOPY(this, &o); }
    W2dc988Vec& operator=(const W2dc988Vec& o) { if (this != &o) W2dc988_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W2dc988Mtx {
    W2dc988Vec r0, r1, r2, r3;
    W2dc988Mtx() {}
    W2dc988Mtx(const W2dc988Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W2dc988Mtx& operator=(const W2dc988Mtx& o) {
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
    W2dc988Mtx operator*(const W2dc988Mtx& r) const
    {
        W2dc988Mtx d;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                     : : "r"(&d), "r"(this), "r"(&r) : "memory");
        return d;
    }
    // VU0 matrix * column vector.
    W2dc988Vec operator*(const W2dc988Vec& v) const {
        W2dc988Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
extern "C" {
struct Box2dc988 {
    W2dc988Vec min, max;
    Box2dc988(const W2dc988Vec& a, const W2dc988Vec& b);
};
void o2dc988_box(Box2dc988*, const W2dc988Vec&, const W2dc988Vec&) asm("_ZN2dk6AabboxC1ERKN2kn7FVectorES4_");
inline Box2dc988::Box2dc988(const W2dc988Vec& a, const W2dc988Vec& b) { o2dc988_box(this, a, b); }
struct Cam2dc988 { u32 vt; u8 pad[12]; W2dc988Mtx m; };
struct O2dc988 { u8 pad0[256]; u8 draw[32288 - 256]; u8 tex[0x8050 - 32288]; u64 gs; };
s32 o2dc988_visible(O2dc988*, Box2dc988*) asm("_ZN2Ti8MiniGame15bbox_is_visibleERKN2dk6AabboxE");
Cam2dc988* func_00106a60(s32);
W2dc988Mtx* func_00106a18(s32);
void func_0011b6a8(W2dc988Mtx*);
void o2dc988_rotateX(W2dc988Mtx*, f32) asm("_ZN2kn7FMatrix7rotateXEf");
s32 func_001344f8(void);
void func_002e6210(void*, s32, s32);
void func_002e5518(void*, W2dc988Mtx*, s32, u64);
}

// Minigame pot marker draw: skip when the bounding box is off screen, then
// draw with proj * camera * (translate(0,300,0) * rotateX(pi)).
void func_002dc988(s32 arg)
{
    O2dc988* o = (O2dc988*)arg;
    {
    W2dc988Vec mx(1000.0f, 20.0f, 1000.0f, 0.0f);
    W2dc988Vec mn(-1000.0f, -20.0f, -1000.0f, 0.0f);
    Box2dc988 box(mn, mx);
    W2dc988Mtx m;
    W2dc988Vec& t = m.r3;
    func_0011b6a8(&m);
    t = W2dc988Vec(0.0f, -300.0f, 0.0f, 0.0f);
    if (!o2dc988_visible(o, &box)) return;
    }
    Cam2dc988* cam = func_00106a60(1);
    W2dc988Mtx* pr = func_00106a18(1);
    W2dc988Mtx r;
    func_0011b6a8(&r);
    W2dc988Vec off(0.0f, 300.0f, 0.0f, 1.0f);
    W2dc988Vec unused; // never used; the original frame keeps a slot for it
    r.r3.AddXYZ(off);
    W2dc988Mtx p = *pr * cam->m;
    o2dc988_rotateX(&r, 3.1415927f);
    p = p * r;
    s32 tex = func_001344f8();
    func_002e6210(o->tex, tex, 0x3500);
    func_002e5518(o->draw, &p, tex, o->gs);
}
