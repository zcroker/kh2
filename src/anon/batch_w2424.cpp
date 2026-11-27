#include "../common/types.h"
// batch w2424 (helper retry): 00118998 party move PMF pick.
extern "C" {
struct V118998b {
    f32 x, y, z, w;
    V118998b() {}
    V118998b& operator=(const V118998b& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V118998b operator-(const V118998b& b) const
    {
        V118998b r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    void zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct V118998 {
    f32 x, y, z, w;
    V118998() {}
    V118998& operator=(const V118998b& o)
    {
        if ((void*)this != (void*)&o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V118998b sub(const V118998& b) const
    {
        V118998b r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V118998& operator=(const V118998& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V118998 operator-(const V118998& b) const
    {
        V118998 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    void zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));

struct Tgt118998;
void func_00190128(Tgt118998*);
struct Tgt118998 {
    s32 f0, f4, f8, f12, f16;
    Tgt118998() { func_00190128(this); }
};
struct Model118998 { u8 pad0[268]; u32 f268; u8 pad1[352 - 272]; u32 f352; };
struct Lead118998 { u8 pad[1164]; void* f1164; };
struct Who118998 {
    u8 pad0[4];
    Model118998* model;
    u8 pad1[1576 - 8];
    f32 maxSpeed;
    u8 pad2[4];
    s32 f1584;
    s32 state;
    u8 pad3[1600 - 1592];
    V118998 from;
    V118998 to;
    V118998 dir;
};
struct Ent118998;
extern f32 D_00349e18;
Lead118998* func_00111e38(s32);
void func_00190878(Tgt118998*, s32, s32);
s32 func_001b58a8(void);
s32 func_0010f8c0(Model118998*);
s32 func_00118958(Who118998*);
void kn__Stitch__calc_move_target(Who118998*, s32);
void func_001168c0(Who118998*);
s32 func_00116d08(Who118998*);
void func_0017f488(void*, s32, f32, f32);
void func_0017f5e0(void*, s32, f32, f32, void*);
void func_001a1a50(void*, s32);
void func_0016ac38(Model118998*, s32, s32, s32, Lead118998*);
void* kn__Stitch__startEffect(Who118998*, s32, Model118998*, s32, s32, s32, s32, s32);
s32 func_00118998(Who118998* w, Ent118998* e, Tgt118998* t, s32* score, u8 check);  // 0x00118998: definition moved into src/anon/unit_00118958.cpp
}
