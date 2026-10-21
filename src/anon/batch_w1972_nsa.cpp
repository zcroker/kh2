#include "../common/types.h"

struct W1972Vec {
    f32 x, y, z, w;
    W1972Vec() {}
    W1972Vec& operator=(const W1972Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct W1972Tgt {
    virtual void v0();
    virtual void v1();
    virtual W1972Vec pos();
};
struct W1972Obj {
    u8 pad0[32];
    W1972Vec p20;           // 0x20
    u8 pad30[2732 - 48];
    W1972Tgt* tgt;          // 0xaac
    f32 dist;               // 0xab0
    f32 f2740;              // 0xab4
};

extern f32 D_00349e10;

static inline W1972Vec w1972_sub(const W1972Vec& a, const W1972Vec& b) {
    W1972Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 w1972_norm(W1972Vec* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline W1972Vec w1972_scale(const W1972Vec& a, f32 s) {
    W1972Vec r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline void w1972_addto(W1972Vec& a, const W1972Vec& b) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&a), "r"(&b) : "memory");
}

extern "C" {
W1972Vec func_0016be98(W1972Obj*);
W1972Vec func_0017d538(f32, const W1972Vec&);

W1972Vec w1972_ctarget(W1972Obj* self) asm("_Z16ctarget_001c1df8jjjj");
W1972Vec w1972_ctarget(W1972Obj* self) {
    W1972Vec d;
    W1972Vec u;
    d = w1972_sub(self->tgt->pos(), func_0016be98(self));
    f32 len = w1972_norm(&d);
    f32 t = (len - self->dist) * 0.1f;
    f32 c;
    if (t < -20.0f) c = -20.0f;
    else if (20.0f < t) c = 20.0f;
    else c = t;
    self->p20 = w1972_scale(d, c);
    d = func_0017d538(1.5707964f, d);
    d.y = 0.0f;
    w1972_norm(&d);
    w1972_addto(self->p20, w1972_scale(d, self->f2740));
    return w1972_scale(self->p20, D_00349e10);
}
}
