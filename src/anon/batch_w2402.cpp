#include "../common/types.h"
struct V7b {
    f32 x, y, z, w;
    V7b() {}
    V7b(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V7b& operator=(const V7b& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct O7b {
    V7b pos;
    f32 f10, f14, f18;
    s32 cnt;
    s32 x20;
};
static inline V7b operator*(const V7b& a, f32 s) {
    V7b r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline V7b operator+(const V7b& a, const V7b& b) {
    V7b r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline __attribute__((always_inline)) f32 subh(f32 y, f32 h) { return y - h; }
extern "C" {
f32 func_0017ce10(f32);
f32 sinf(f32);
f32 cosf(f32);
s32 func_001a7610(const V7b&, V7b*, s32, f32, f32);
s32 func_001a75d8(O7b*, V7b*, s32);
/* near-miss: frame/slots right; 100.0f not hoisted twice (orig f24+f26 copy), temp slot order sum/scale swapped */
// 001a7b78: moved to src/yasui/libys/bg.cpp
}
