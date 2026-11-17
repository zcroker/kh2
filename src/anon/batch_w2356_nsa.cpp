#include "../common/types.h"

// ---- 001319d8: colour desaturation through a lazily built YIQ matrix ----
#define Q_COPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct CVec {
    f32 x, y, z, w;
    CVec() {}
    CVec(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    CVec(const CVec& o) { Q_COPY(this, &o); }
    CVec& operator=(const CVec& o) { if (this != &o) Q_COPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct CMtx { CVec r[4]; };
static inline void CApply(CVec& d, const CMtx& m, const CVec& v) {
    asm volatile("lqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                 : : "r"(&d), "r"(&v), "r"(&m) : "memory");
}
static inline void CClamp(CVec& v, f32 lo, f32 hi) {
    asm volatile("mfc1 $8, %1\n\tmfc1 $9, %2\n\tlqc2 $vf1, 0(%0)\n\tqmtc2 $8, $vf2\n\tqmtc2 $9, $vf3\n\tvmaxx.wxyz $vf1, $vf1, $vf2x\n\tvminix.wxyz $vf1, $vf1, $vf3x\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "f"(lo), "f"(hi) : "$8", "$9", "memory");
}
static inline void CScale(CVec& v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "f"(s) : "$8", "memory");
}
static inline void CAdd(CVec& d, const CVec& a, const CVec& b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&d), "r"(&a), "r"(&b) : "memory");
}
static inline u32 CPack(f32 r, f32 g, f32 b, f32 a) {
    return ((s32)a << 24) | ((s32)b << 16) | ((s32)g << 8) | (s32)r;
}
extern "C" {
extern s8 D_003b8a90;
extern CMtx D_003b8aa0;
void func_001320a8(void);
s32 func_002fd188(void (*)(void));
/* Desaturate an RGBA colour: t >= 1 gives grey (YIQ luma), t < 1 blends towards the original. */
u32 func_001319d8(u32 c, f32 t);  // 0x001319d8: definition moved into src/anon/unit_00131418.cpp
}

// ---- 00128750: animation curve channel evaluation ----
struct MKey { u16 type:2; u16 time:14; u16 v; u16 tin; u16 tout; };
struct MHdr { u8 pad[64]; s32 keyOff; s32 timeOff; s32 valOff; s32 tanOff; };
struct MObj { u32 x; MHdr* h; };
struct MCh { u16 idx; u16 ch:4; u16 pre:2; u16 post:2; u16 cnt:8; u16 start; };
extern "C" {
void func_001285f8(MObj*, f32, s32*, s32*);
f32 func_001286d0(f32 t, f32 t0, f32 p0, f32 m0, f32 t1, f32 p1, f32 m1);
/* Evaluate one animation curve channel at time t (lo/hi: bracketing time-table indices). */
f32 func_00128750(MObj* o, MCh* k, s32 lo, s32 hi, f32 t);  // 0x00128750: definition moved into src/anon/unit_00128480.cpp
}
