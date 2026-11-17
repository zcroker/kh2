#include "../common/types.h"
struct QVW2037a {
    f32 x, y, z, w;
    QVW2037a() {}
    QVW2037a(f32 v) { x = v; y = v; z = v; w = v; }
    QVW2037a(const QVW2037a& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct ObjW2037a {
    u8 pad0[0x588]; u32 flags;
    u8 pad1[0xaf0 - 0x58c]; u8 sub[0x24];
    f32 lim; f32 scale; f32 base; f32 mul;
};
static inline void vsubW2037a(QVW2037a* o, const QVW2037a* a, const QVW2037a* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(o), "r"(a), "r"(b) : "memory");
}
static inline void vaddW2037a(QVW2037a* o, const QVW2037a* a, const QVW2037a* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(o), "r"(a), "r"(b) : "memory");
}
static inline void vscaleW2037a(QVW2037a* o, const QVW2037a* a, const f32& s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(o), "r"(a), "f"(s) : "$8", "memory");
}
static inline f32 normalizeW2037a(QVW2037a* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline QVW2037a mulSW2037a(const QVW2037a* d, const f32& s, f32 t) {
    f32 c;
    if (t < (c = -1.0f) || (c = 1.0f) < t) t = c;
    QVW2037a s1, s2;
    vscaleW2037a(&s1, d, s);
    vscaleW2037a(&s2, &s1, t);
    return s2;
}
extern "C" {
extern f32 D_00349e10;
s32 func_001c0cd8(void*);
s32 func_002cf270(void*, s32);
void func_0016bda8(QVW2037a*, void*);
QVW2037a func_002d3fa8(ObjW2037a* a, ObjW2037a* b);  // 0x002d3fa8: definition moved into src/anon/unit_002d2498.cpp
}
