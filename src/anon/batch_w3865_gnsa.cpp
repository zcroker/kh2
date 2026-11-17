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
void func_002cc7d0(Path2cc7d0* p);  // 0x002cc7d0: definition moved into src/taito/path.cpp
}
