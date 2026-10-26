#include "../common/types.h"
// 002e4d30: rope physics step (VU0 macro asm helpers). Needs -fno-strict-aliasing.
extern "C" {
// VU0 macro-mode vector helpers (hand-written asm in the original math library)
struct V2e4d30 {
    f32 x, y, z, w;
    V2e4d30() {}
    V2e4d30(const V2e4d30& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V2e4d30 operator-(const V2e4d30& b) const
    {
        V2e4d30 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2e4d30 operator*(f32 k) const
    {
        V2e4d30 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    V2e4d30& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    V2e4d30& operator+=(const V2e4d30& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    f32 length() const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
    f32 dot(const V2e4d30& o) const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this), "r"(&o) : "$8");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct Node2e4d30 { V2e4d30 pos; V2e4d30 vel; u8 pad[32]; V2e4d30 force; u8 fixed; u8 pad2[15]; };
struct Spring2e4d30 { f32 k, damp, rest; };
struct Rope2e4d30 { u8 hdr[16]; Node2e4d30 n[41]; Spring2e4d30 s[40]; };
void func_002e4d30(Rope2e4d30* r)
{
    for (s32 i = 0; i < 41; i++) {
        Node2e4d30* n = &r->n[i];
        if (!n->fixed) {
            V2e4d30 v(n->vel);
            v *= -1.0f;
            f32 s = n->vel.length();
            v.normalize();
            n->force += v * (s * s) * 0.1f;
        }
    }
    s32 j;
    for (s32 i = 0; i < 40; i = j) {
        Spring2e4d30* sp = &r->s[i];
        Node2e4d30* p = &r->n[i];
        j = i + 1;
        Node2e4d30* q = &r->n[j];
        V2e4d30 d = p->pos - q->pos;
        V2e4d30 dv = p->vel - q->vel;
        f32 rest = sp->rest;
        f32 len = d.length();
        f32 inv = 1.0f / len;
        f32 f = -(dv.dot(d) * sp->damp * inv + (len - rest) * sp->k);
        V2e4d30 F = d * inv * f;
        V2e4d30 G = F * -1.0f;
        if (!p->fixed) p->force += F;
        if (!q->fixed) q->force += G;
    }
}
}
