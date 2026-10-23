/* batch w2352 (default flags). */
#include "../common/types.h"

/* VU0 macro-mode vector helpers (hand-written asm in the original math library). */
struct V6a0 {
    f32 x, y, z, w;
    V6a0() {}
    V6a0& operator=(const V6a0& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V6a0 operator+(const V6a0& b) const
    {
        V6a0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V6a0 operator*(f32 k) const
    {
        V6a0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    V6a0& operator+=(const V6a0& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    void zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));

struct St6a0 { s32 f0; u32 state; };
struct O6a0 {
    u8 pad0[12];
    St6a0* st;
    u8 pad1[2940 - 16];
    u32 flags;          /* 2940 */
    u8 pad2[3072 - 2944];
    V6a0 dir;           /* 3072, w = zoom value */
    u8 pad3[3184 - 3088];
    V6a0 hist[6];       /* 3184: ring of recent directions */
    s32 hist_pos;       /* 3280 */
};

extern "C" {
f32 func_0010e7e0(O6a0*, s32);

/* 001106a0: smooth the look direction over the last six frames, then snap the zoom value (dir.w) to a level. */
void func_001106a0(O6a0* o)
{
    V6a0 v;
    s32 i;
    if (o->st && o->st->state == 2) return;
    if (o->flags & 0x10) v.zero();
    else v = o->dir * o->dir.w;
    if (o->hist_pos < 0) {
        for (i = 0; i < 5; i++) o->hist[i] = v;
        o->hist_pos = 5;
    }
    o->hist[o->hist_pos] = v;
    if (++o->hist_pos >= 6) o->hist_pos = 0;
    v.zero();
    for (i = 0; i < 6; i++) v += o->hist[i];
    v.w = v.normalize() / 6.0f;
    o->dir = (o->dir + v) * 0.5f;
    {
        f32 a = func_0010e7e0(o, 1);
        f32 b = func_0010e7e0(o, 2);
        if (o->dir.w < b) {
            if (o->dir.w < a * 0.5f) o->dir.w = 0.0f;
            else if (o->dir.w < (a + b) * 0.5f) o->dir.w = a;
            else o->dir.w = b;
        }
    }
    if (o->flags & 0x10) o->dir.w = func_0010e7e0(o, 1);
}
}
