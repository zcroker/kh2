#include "../common/types.h"
// Built with -g and -fno-strict-aliasing (_gnsa rule): -g keeps the prologue branch delay slot a nop.
// Partial inline asm: VU0 macro ops (lqc2/sqc2, vsub/vadd/vmulx/vdiv/vsqrt) and the
// 128-bit lq/sq copy, which gcc cannot emit from C.
struct V2cc7d0 {
    f32 x, y, z, w;
    V2cc7d0() {}
    V2cc7d0& operator=(const V2cc7d0& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2cc7d0 operator-(const V2cc7d0& b) const
    {
        V2cc7d0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2cc7d0 operator+(const V2cc7d0& b) const
    {
        V2cc7d0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2cc7d0 operator*(f32 k) const
    {
        V2cc7d0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    V2cc7d0 operator/(f32 k) const
    {
        V2cc7d0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.wxyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    V2cc7d0& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    f32 Length() const
    {
        f32 l;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(l) : "r"(this) : "$8");
        return l;
    }
} __attribute__((aligned(16)));
extern "C" {
struct Pt2cc7d0 { V2cc7d0 pos; V2cc7d0 tan; };
struct Path2cc7d0 { u8 pad0[8]; s32 count; u8 pad1[4]; u8 loop; u8 pad2[15]; f32 tension; u8 pad3[128 - 36]; Pt2cc7d0* pts; };
/* Builds the path tangents (Catmull-Rom style). Open paths get end tangents from the
   quadratic through the first/last three points, scaled to the tension length.
   Each point's tan.w keeps its index. */
void func_002cc7d0(Path2cc7d0* p)
{
    s32 i;
    if (p->count < 3) {
        p->pts[0].tan = p->pts[1].pos - p->pts[0].pos;
        p->pts[1].tan = p->pts[0].tan;
        p->loop = 0;
        return;
    }
    for (i = 0; i < p->count; i++) {
        if (!p->loop && i == 0) {
            Pt2cc7d0* q = p->pts;
            f32 l0, l1, s, u;
            V2cc7d0* c = &q[2].pos;
            V2cc7d0* a = &q[0].pos;
            V2cc7d0* b = &q[1].pos;
            V2cc7d0 m;
            V2cc7d0 d;
            d = *b - *a;
            l0 = d.Length();
            d = *c - *b;
            s = d.Length();
            s = l0 / (l0 + s);
            u = 1.0f - s;
            m = (*b - *a * u * u - *c * s * s) / ((s + s) * u);
            d = (m - *a) * 2.0f;
            V2cc7d0 v = *a * (u * -2.0f) + m * (2.0f - s * 4.0f) + *c * 2.0f * s;
            l1 = v.Length();
            d *= ((*c - *a) * p->tension).Length() / l1;
            p->pts[i].tan = d;
        } else if (!p->loop && i == p->count - 1) {
            Pt2cc7d0* q = &p->pts[i];
            f32 l0, l1, s, u;
            V2cc7d0* c = &q[0].pos;
            V2cc7d0* a = &q[-2].pos;
            V2cc7d0* b = &q[-1].pos;
            V2cc7d0 m;
            V2cc7d0 d;
            d = *b - *a;
            l0 = d.Length();
            d = *c - *b;
            s = d.Length();
            s = l0 / (l0 + s);
            u = 1.0f - s;
            m = (*b - *a * u * u - *c * s * s) / ((s + s) * u);
            d = (*c - m) * 2.0f;
            V2cc7d0 v = *a * (u * -2.0f) + m * (2.0f - s * 4.0f) + *c * 2.0f * s;
            l1 = v.Length();
            d *= ((*c - *a) * p->tension).Length() / l1;
            p->pts[i].tan = d;
        } else {
            s32 prev = i - 1;
            s32 next = i + 1;
            if (prev < 0) prev += p->count;
            if (next >= p->count) next -= p->count;
            p->pts[i].tan = (p->pts[next].pos - p->pts[prev].pos) * p->tension;
        }
        p->pts[i].tan.w = (f32)i;
    }
}
}
