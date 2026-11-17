#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "tiny_auto80_solver_structs.hpp"

// ---- 001c4dc8 gap: message handler (75 = hit)
namespace n001c4dc8 {
u32 func_001c4160(void) asm("_Z13func_001c4160jjjj");
void func_001c42c0(void) asm("func_001c42c0");
s32 func_001c4170(void) asm("func_001c4170");
void func_001991a8(s32, s32) asm("func_001991a8");
extern s32 D_00351608 asm("D_00351608");
void func_001c4dc8(void* o, s32 msg) asm("func_001c4dc8");
void func_001c4dc8(void* o, s32 msg) {
    if (msg == 75 && func_001c4160()) {
        func_001c42c0();
        D_00351608++;
        if (func_001c4170() == 0) func_001991a8(157, 0);
    }
}
}  // namespace n001c4dc8

// ---- 001c4e30 from src/anon/batch_w290.cpp
namespace n001c4e30 {
struct W290V {
    f32 x, y, z, w;
    W290V() {}
    W290V(const W290V& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W290V& operator=(const W290V& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    f32 Length() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    f32 Normalize() {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    f32 LengthSq() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W290M { W290V r[4]; };
static inline W290V operator*(const W290M& m, const W290V& v) {
    W290V r;
    asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
static inline W290V operator-(const W290V& a, const W290V& b) {
    W290V r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline W290V operator+(const W290V& a, const W290V& b) {
    W290V r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct W290Fx { W290V pos; u8 p16[5]; s8 f21; u8 p22[26]; W290V v48; u8 p64[16]; u8 cnt; u8 idx; };
struct W290Q { f32 x, y, z, w; } __attribute__((aligned(16)));
extern W290V D_01d49590[] asm("D_01d49590");
extern W290M D_01d49610 asm("D_01d49610");
extern W290V D_00352a60 asm("D_00352a60");
s32 func_001c4160(W290Fx*) asm("func_001c4160");
void func_001c4188(W290Fx*, f32) asm("func_001c4188");
void func_001c4e30(W290Fx* o) asm("func_001c4e30");
void func_001c4e30(W290Fx* o) {
    W290V l;
    o->pos = o->v48 + D_01d49590[o->idx];
    l = D_01d49610 * o->v48;
    if (func_001c4160(o)) func_001c4188(o, (o->pos - D_00352a60).LengthSq());                           
    if (o->cnt) { o->cnt--; return; }
    if (l.z < 300.0f) { o->f21 = 0; return; }
    l = o->pos - D_00352a60;
    o->f21 = -128;
    f32 len = l.Normalize();
    if (len < 1200.0f) o->pos.y -= (1200.0f - len) * 0.5f;
}
}  // namespace n001c4e30

// ---- 001c4ff0 gap: falling piece update (pos += vel * dt, then fade out)
namespace n001c4ff0 {
struct V4ff0 { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline V4ff0 operator*(const V4ff0& a, f32 s) {
    V4ff0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline void addto(V4ff0& a, const V4ff0& b) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&a), "r"(&b) : "memory");
}
struct Obj4ff0 { V4ff0 pos; u8 p16[5]; u8 f21; u8 p22[42]; V4ff0 vel; u8 b80; u8 p81[3]; void* fn; };
extern f32 D_00349e10 asm("D_00349e10");
void func_001c4ff0(Obj4ff0* o) asm("func_001c4ff0");
void func_001c4ff0(Obj4ff0* o) {
    addto(o->pos, o->vel * D_00349e10);
    if (o->b80) { o->b80--; return; }
    o->f21 -= 16;
    if (o->f21 == 0) { o->f21 = 0; o->fn = 0; }
}
}  // namespace n001c4ff0

// ---- 001c5060 from src/anon/batch_w2440.cpp
namespace n001c5060 {
struct T16_w2440 { u32 w[4]; ~T16_w2440() {} } __attribute__((aligned(16)));
struct Arr_w2440 { T16_w2440 e[8]; };
struct W3_w2440 { u32 a; u32 b; f32 c; };
extern W3_w2440 D_01d49580 asm("D_01d49580");
extern W3_w2440 D_01d49658[30] asm("D_01d49658");
extern Arr_w2440 D_01d49590 asm("D_01d49590");
void wt_001c5060(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001c5060jjjj");
void wt_001c5060(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_01d49580.a = 0;
        D_01d49580.b = 1368;
        D_01d49580.c = 64.0f;
    }
    if (b == 0xffff && a == 1) {
        W3_w2440* p = D_01d49658;
        s32 i = 29;
        do { p->b = 0; i--; p++; } while (i != -1);
    }
    if (b == 0xffff && a == 0) {
        D_01d49590.~Arr_w2440();
    }
}
}  // namespace n001c5060

// ---- 001c5128 from src/anon/tiny_wrappers_more.cpp
namespace n001c5128 {
u32 func_001c5060(u32, u32, u32, u32) asm("_Z16wtarget_001c5060jjjj");
u32 func_001c5128(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c5128jjjj");
u32 func_001c5128(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001c5060(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n001c5128

// ---- 001c5148 gap: _GLOBAL__D_ stub
namespace n001c5148 {
u32 func_001c5060(u32, u32, u32, u32) asm("_Z16wtarget_001c5060jjjj");
u32 func_001c5148(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001c5148");
u32 func_001c5148(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001c5060(0, 0xffff, a2, a3);
}
}  // namespace n001c5148

