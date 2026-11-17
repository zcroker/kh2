#include "../common/types.h"
struct W1980V80 {
    f32 x, y, z, w;
    W1980V80() {}
    W1980V80(const W1980V80& o) {
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    W1980V80 operator*(f32 s) const {
        W1980V80 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    W1980V80 operator+(const W1980V80& b) const {
        W1980V80 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1980V80 operator-(const W1980V80& b) const {
        W1980V80 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1980Col80 { u8 d[32]; };
struct W1980Obj80 { W1980V80 pos; W1980Col80 col; u8 pad[12]; void* eff; };
struct W1980ColList80 { s32 count; s32 pad[3]; W1980Col80 e[1]; };
struct W1980V81 {
    f32 x, y, z, w;
    W1980V81() {}
    W1980V81& operator=(const W1980V81& o) {
        if (this != &o) {
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        }
        return *this;
    }
    W1980V81 operator-(const W1980V81& b) const {
        W1980V81 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 normalize() {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                 : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    f32 dot(const W1980V81& b) const {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder"
                 : "=f"(r) : "r"(this), "r"(&b) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1980Ent81 { u8 a; u8 kind; u8 pad[66]; };
struct W1980List81 { s32 count; W1980Ent81 e[1]; };
struct W1980Tgt81 { f32 f0; f32 h; u8 pad[8]; W1980V81 pos; };
struct W1980Bits81 {
    u32 w[1];
    void set(u32 i) { u32* q = &w[i >> 5]; *q |= 1 << (i & 31); }
    void set2(s32 i) { w[(u32)i >> 5] |= 1 << (i & 31); }
};
struct W1980Self81 { u8 pad[0x30]; W1980V81 dir; void* ctx; W1980List81* list; u8 pad2[8]; W1980V81 pos; W1980Bits81 bits; };
extern "C" {
void func_00134408(void);
void func_00134428(s32, u64);
void func_00134450(s32);
void func_001342c8(void*, s32, s32);
extern u8 D_00340fd0;
extern u8 D_00341000;
extern u8 D_00341030;
extern u64 D_00340ed8[4];
void func_0010a918(s32 mode);  // 0010a918: moved to src/anon/unit_0010a918.cpp

s32 W1980Eff80_is_active(void*) asm("_ZN3ryj6EFFECT9is_activeEv");
W1980Obj80* func_002e97b8(W1980Obj80*);
s32 func_0018a550(W1980Col80*, W1980Col80*);
void func_0018a7d0(W1980Col80*, W1980Col80*, W1980V80*);
void func_002e9610(W1980Obj80*, const W1980V80&);
extern W1980ColList80 D_01e2bfb0;
// 002e93b0: moved to src/sugi/flare.cpp

s32 func_001a0920(W1980Ent81*, void*);
s32 func_001a0800(W1980Ent81*, void*, W1980Tgt81*, f32, f32, f32);
// 001cdbc8: moved to src/anon/unit_001cd660.cpp
void func_001cdbc8(W1980Self81* self, W1980Tgt81* t, s32 kind);
}
