#include "../common/types.h"

extern "C" {

// ---- 00222f88: GS packet setup, then VU0 register preload (VU0 macro asm) ----
struct W2042A { u8 p0[0x20]; void* m20; u8 p24[4]; void* m28; u8 p2c[0x10]; s32 m3c; u64 m40; u64 m48; u16 m50; u16 p52; u16 m54; };
struct W2042P { u64 a0, a8, a10, a18, a20, a28, a30, a38, a40, a48, a50, a58, a60, a68; s32 b70, b74; u64 a78; s32 b80, b84; };
extern s32 D_01da8bf0;
extern s32 D_01da8bf4;
void* func_0020eaf8(s32);
void func_0020ebd8(s32);

void func_00222f88(W2042A* a);  // 0x00222f88: definition moved into src/anon/unit_00222aa8.cpp

// ---- 00184780 ----
struct W2042Vec {
    f32 x, y, z, w;
    W2042Vec() {}
    W2042Vec& operator=(const W2042Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W2042Seg { W2042Vec a, b; };
struct W2042Obj { u8 p0[0x5fc]; f32 r; u64 :3; s64 k:32; };
W2042Vec* func_0016c028(W2042Obj*);
s32 func_00143ae0(W2042Seg*, W2042Vec*, W2042Vec*, s32);

static inline f32 w2042_norm(W2042Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline W2042Vec w2042_mul(const W2042Vec& a, f32 s) {
    W2042Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline W2042Vec w2042_add(const W2042Vec& a, const W2042Vec& b) {
    W2042Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

// 00184780: moved to src/anon/unit_00183088.cpp

}
