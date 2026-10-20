#include "../common/types.h"
// VU0 vector / matrix helpers (inline asm like the game's vector library).
struct W1685Vec {
    f32 x, y, z, w;
    W1685Vec() {}
    W1685Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1685Vec(const W1685Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1685Vec& operator=(const W1685Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32 length() const {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W1685Mtx {
    W1685Vec r[4];
    W1685Mtx() {}
    W1685Mtx(const W1685Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W1685Mtx& operator=(const W1685Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    // Point transform (w = 1).
    void applyPoint(W1685Vec& o, const W1685Vec& v) const {
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\tvmove.w $vf5, $vf0\n\tsqc2 $vf5, 0(%0)"
                     : : "r"(&o), "r"(this), "r"(&v) : "memory");
    }
} __attribute__((aligned(16)));
// Camera record from func_00106a60; the view matrix is its second base.
struct W1685CamHead { u8 pad[16]; } __attribute__((aligned(16)));
struct W1685Cam : W1685CamHead, W1685Mtx {};
// Object with a world position and a fade/angle state.
struct W1685Fade {
    W1685Vec pos;       // 0
    u8 pad16[24];
    s16 fade;           // 40
    s16 fadeMin;        // 42
    s16 angle;          // 44
};
f32 W1685_fixRadian(f32) asm("_ZN2YS4MATH9FixRadianEf");
extern "C" {
extern s32 D_003616ec;
W1685Cam* func_00106a60(s32);
f32 func_0017d160(W1685Vec, W1685Vec);

void func_002bb5f8(W1685Fade* p)
{
    W1685Vec fwd(0.0f, 0.0f, 1.0f, 1.0f);
    W1685Vec d;
    W1685Mtx m(*(W1685Mtx*)func_00106a60(0));
    W1685Mtx* pm = &m;
    pm->applyPoint(d, p->pos);
    f32 len = d.length();
    s32 v = (s32)(len * len / D_003616ec);
    if (v >= 16384) p->fade = 0;
    else p->fade = 16383 - v;
    if (p->fade < p->fadeMin) p->fade = p->fadeMin;
    if (p->fade > 16383) p->fade = 16383;
    d.normalize();
    d.y = 0.0f;
    f32 r;
    r = W1685_fixRadian(r = func_0017d160(fwd, d));
    // The angle starts at 0 and is also the zero for the first two tests.
    f32 angle = 0.0f;
    if (d.x < angle && d.z > angle) angle = 64.0f - r * 128.0f / 3.1415927f;
    else if (d.x > angle && d.z > angle) angle = r * 128.0f / 3.1415927f + 64.0f;
    else if (d.x < 0.0f && d.z < 0.0f) angle = 320.0f - r * 128.0f / 3.1415927f;
    else angle = r * 128.0f / 3.1415927f + 64.0f;
    p->angle = (s32)angle;
}
}
