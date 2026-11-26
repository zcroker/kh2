#include "../common/types.h"
struct V4w282b {
    f32 x, y, z, w;
    V4w282b() {}
    V4w282b(const V4w282b& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4w282b& operator=(const V4w282b& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline V4w282b Lerp_w282(const V4w282b& a, const V4w282b& b, f32 t) {
    V4w282b r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
static inline V4w282b operator-(const V4w282b& a, const V4w282b& b) {
    V4w282b r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline V4w282b operator+(const V4w282b& a, const V4w282b& b) {
    V4w282b r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline V4w282b operator*(const V4w282b& a, f32 s) {
    V4w282b r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
struct O2bfe08 { u32 vt; u8 pad[12]; V4w282b m16; V4w282b m32; u8 pad2[36]; u32 f84; u8 pad3[4]; u32 f92; u32 f96; f32 f100; u8 pad4[8];
    V4w282b m112; V4w282b m128; V4w282b m144; V4w282b m160; V4w282b m176; V4w282b m192; };
extern "C" {
extern u8 D_00361da8[];
extern u8 D_00361a60[];
void worldmap__Camera__initialize(O2bfe08*);
void func_002bfe08(O2bfe08* o, V4w282b* a, V4w282b* b, f32 f);  // 0x002bfe08: definition moved into src/anon/unit_002bebd0.cpp
}
