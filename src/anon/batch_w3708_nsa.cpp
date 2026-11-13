// Partial asm in func_002ebf50: arg registers pinned and addiu a2 hand-written so it follows the other arg moves (sched2 order). lq/sq and VU0 asm are hand-written in the original.
#include "../common/types.h"
struct Vec {
    f32 x, y, z, w;
    Vec() {}
    Vec(const Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    Vec& operator=(const Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline f32 vnorm(Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct Obj { u8 pad[16]; Vec v16; Vec v32; u8 pad2[256 - 48]; s32 w256; s32 w260; u8 pad3[1300 - 264]; u8 b1300; };
extern "C" {
extern void* D_003637d0;
void func_002eda90(void*, s32, f32);
Vec func_0017c030(Obj*, Vec*, u8);
Vec func_0017c030b(Obj*, const Vec&, u8) asm("func_0017c030");
void func_0017c4c8(Obj*, Vec);
void func_0017c4c8c(Obj*, Vec*) asm("func_0017c4c8");
void func_002eb778(Obj*, s32, s32, f32);
void fx0017c030(Vec*, Obj*, Vec*, u32) asm("func_0017c030");
static inline Vec get2ebf50(Obj* o, u8 k) { Vec t; Vec r; register Vec* a0 asm("$4") = &r; register Obj* a1 asm("$5") = o; register u32 a3 asm("$7") = k; register Vec* a2 asm("$6"); asm("la %0,%1" : "=r"(a2) : "m"(t), "r"(a0), "r"(a1), "r"(a3)); fx0017c030(a0, a1, a2, a3); return r; }
// 002ebf50: moved to src/anon/unit_002eaf38.cpp
}
