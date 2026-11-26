#include "../../src/common/types.h"
extern "C" {
// VU0 macro-mode vector helpers (hand-written asm in the original math library)
struct V10e810 {
    f32 x, y, z, w;
    V10e810() {}
    V10e810& operator=(const V10e810& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V10e810 operator-(const V10e810& b) const
    {
        V10e810 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V10e810 operator*(f32 k) const
    {
        V10e810 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    V10e810& operator+=(const V10e810& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    V10e810& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    V10e810 operator+(const V10e810& b) const
    {
        V10e810 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V10e810 cross(const V10e810& b) const
    {
        V10e810 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 dot(const V10e810& o) const
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
struct VecSet10e810 { f32 x; u8 pad[28]; V10e810 dir; };
struct Seg10e810 { V10e810 p, q; };
struct Fr10e810;
struct Fr10e810Vt { void* f[38]; s32 (*kind)(Fr10e810*); };
struct Who10e810;
struct Fr10e810 {
    Fr10e810Vt* vt;
    u8 pad0[280 - 4];
    f32 reach;
    u8 pad1[1360 - 284];
    V10e810 fwd;
    u8 pad2[1456 - 1376];
    f32 f1456;
    u8 pad3[1520 - 1460];
    u16 h1520;
    u8 pad4[1532 - 1522];
    f32 f1532;
    u64 bits;
    s32 f1544;
    u8 pad5[1584 - 1548];
    V10e810 up;
    u8 pad6[2064 - 1600];
    s32 f2064;
    u8 pad7[2912 - 2068];
    Who10e810* who;
    u8 pad8[2928 - 2916];
    s32 point;
    u8 pad9[4];
    s32 level;
    u32 flags;
    VecSet10e810 own;
    u8 pad10[3072 - 2992];
    V10e810 dir;
    u8 pad11[3288 - 3088];
    s32 f3288;
};
extern V10e810 D_00341720[];
extern Fr10e810* D_00341708;
extern u8 D_003a9040;
s32 f10e810_update(Fr10e810*, const VecSet10e810*) asm("func_0010e368");
s32 func_001917c0(void);
V10e810* f10e810_attach(Fr10e810*) asm("YS__OBJ__get_pos");
f32 f10e810_hi(Who10e810*, s32, s32, s32) asm("func_00114328");
f32 f10e810_lo(Who10e810*, s32, s32, s32) asm("func_001142e0");
f32 f10e810_dist(Fr10e810*, s32) asm("func_0010e7e0");
s32 func_0010e6e0(Fr10e810*, V10e810*, f32, f32, f32);
s32 func_00143f28(u16, s32);
s32 dk__Octree__intersectLineMap_2(Seg10e810*, V10e810*, V10e810*, s32);
void f10e810_warp(Fr10e810*, s32, f32) asm("func_0010cac8");
void f10e810_followMove(Fr10e810* o, const VecSet10e810* vs) asm("_ZN2kn6Friend10followMoveEPKNS_6VecSetE");
void f10e810_followMove(Fr10e810* o, const VecSet10e810* vs);  // 0x0010e810: definition moved into src/anon/unit_0010dee8.cpp
}
