#include "../common/types.h"
#define W1631_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1631Vec {
    f32 x, y, z, w;
    W1631Vec() {}
    W1631Vec(const W1631Vec& o) { W1631_QCOPY(this, &o); }
    W1631Vec& operator=(const W1631Vec& o) { if (this != &o) W1631_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
// VU0: d = v * s.
static inline W1631Vec operator*(const W1631Vec& v, f32 s) {
    W1631Vec d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(&v), "f"(s) : "$8", "memory");
    return d;
}
// VU0: v *= s.
static inline void W1631_scale(W1631Vec& v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "f"(s) : "$8", "memory");
}
// VU0: v += a.
static inline void W1631_add(W1631Vec& v, const W1631Vec& a) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "r"(&a) : "memory");
}
// VU0: v = clamp(v, lo, hi) per component.
static inline void W1631_clamp(W1631Vec& v, f32 lo, f32 hi) {
    asm volatile("mfc1 $8, %1\n\tmfc1 $9, %2\n\tlqc2 $vf1, 0(%0)\n\tqmtc2 $8, $vf2\n\tqmtc2 $9, $vf3\n\tvmaxx.wxyz $vf1, $vf1, $vf2x\n\tvminix.wxyz $vf1, $vf1, $vf3x\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "f"(lo), "f"(hi) : "$8", "$9", "memory");
}
struct W1631Light {
    u8 pad0[16];
    f32 range;          // 0x10
    u8 pad1[12];
    W1631Vec color;     // 0x20
    u8 off;             // 0x30
    u8 pad2[15];
};
extern "C" {
extern s32 D_0034a77c;          // light count
extern W1631Light* D_0034a790;  // light array
void func_00153540(W1631Vec*, u8, u8, u8, u8);
f32 func_00153610(f32);
s32 func_00163268(W1631Light*, W1631Vec*, f32*);

// Tints an RGBA colour (in place) by the first enabled light that reaches pos:
// col = clamp(col * (1 - k) + light.color * k), k from the distance ratio.
// Matches only with -g.
void func_001539c0(u8* rgba, W1631Vec* pos) {
    W1631Vec add;
    W1631Vec col;
    f32 t;
    s32 n = D_0034a77c;
    s32 i;
    f32 f;
    if (n == 0) return;
    t = 0.0f;
    f = 0.0f;
    func_00153540(&col, rgba[0], rgba[1], rgba[2], rgba[3]);
    for (i = 0; i < n; i++) {
        if (D_0034a790[i].off != 0) continue;
        if (!func_00163268(&D_0034a790[i], pos, &t)) continue;
        add = D_0034a790[i].color;
        t = t / D_0034a790[i].range;
        f = func_00153610(t);
        col = col * (1.0f - f);
        W1631_clamp(col, 0.0f, 1.0f);
        add = add * f;
        W1631_add(col, add);
        W1631_clamp(col, 0.0f, 1.0f);
        break;
    }
    W1631_clamp(col, 0.0f, 1.0f);
    W1631_scale(col, 255.0f);
    *rgba++ = (s32)col.x;
    *rgba++ = (s32)col.y;
    *rgba++ = (s32)col.z;
    *rgba = (s32)col.w;
}
}
