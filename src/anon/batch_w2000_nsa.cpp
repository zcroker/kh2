#include "../common/types.h"
extern "C" {
struct VecE {
    f32 x, y, z, w;
    VecE() {}
    VecE(f32 a, f32 b, f32 c, f32 e) { x = a; y = b; z = c; w = e; }
    VecE operator+(const VecE& o) const {
        VecE r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    VecE operator*(f32 s) const {
        VecE r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    VecE& operator=(const VecE& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct PairE { VecE a; VecE b; };
struct ObjE { void* vt; u8 pad[44]; VecE p48; VecE p64; u8 pad2[4]; u8 m84[8]; f32 f5c; f32 f60; };
extern u8 D_00361da8[];
extern u8 D_00361e60[];
extern ObjE* D_00361e50;
extern f32 D_01e2be10;
extern f32 D_01e2be14;
void func_0031cc28(void*);
void func_002c6420(ObjE*);
void func_001903d0(s32*, PairE*);
s32 func_00106a18(s32);
f32 func_001070a0(s32);
s32 func_0016a020(s32);
void func_00162058(f32);
static inline f32 normE(VecE* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline void scaleE(VecE* d, const VecE* a, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(d), "r"(a), "f"(s) : "$8", "memory");
}
static inline void addE(VecE* d, const VecE* a, const VecE* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
void func_002cae60(ObjE* self, s32* a1, VecE* a2, f32 f);  // 0x2cae60: moved to src/anon/unit_002cac58.cpp


struct EntI { s32 a; s32 b; u8 type; u8 arg; u8 pad[2]; };
struct HdrI { u8 pad[10]; u8 n; u8 pad2[53]; EntI ent[1]; };
struct ObjI { u8 pad[144]; u8 b90; u8 pad1[23]; s32 i168; f32 cur; f32 prev; u8 pad2[8]; u8 sub[4]; u8 b192; u8 b193; u8 pad3[2]; s32 i196; };
HdrI* func_002e34d8(void*, s32);
void* func_0014abd8(void);
void func_0014aa58(void*, s32, s32);
void func_0014aa80(void*, s32, s32);
void* func_002d1260(void);
void func_002daa00(void*, u8);
void func_001991a8(s32, s32);
void func_002d7698(ObjI* self);  // 0x002d7698: definition moved into src/anon/unit_002d6f70.cpp
}
