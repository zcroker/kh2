// Linked unit 0x0010b450-0x0010b7e0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include <stdarg.h>
#include "../naka/libkn/friend.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../../src/common/types.h"
extern "C" float fabsf(float);
#include "tiny_auto80_solver_structs.hpp"

// 0010b450 (was src/anon/tiny.cpp)
namespace n0010b450 {
void func_0010b550(void*) asm("_Z13func_0010b550Pv");
/*TARGET 0010b450*/
// 00109e90: moved to src/anon/unit_00109c30.cpp
void func_0010b450(BD_VALUE* bd) asm("_Z13func_0010b450P8BD_VALUE");
// 00109e90: moved to src/anon/unit_00109c30.cpp
void func_0010b450(BD_VALUE* bd) { func_0010b550(bd); }
}  // namespace n0010b450

// 0010b468 (was src/anon/batch_w85.cpp)
namespace n0010b468 {
// 128-bit vector with the engine's self-checking quadword copy
struct Vec4 {
    f32 x, y, z, w;
    Vec4& operator=(const Vec4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void vu_sub_to(void* d, const void* a, const void* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 vu_dot(const void* a, const void* b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
// position trail: records a new point once it moved 45 units from the last one
struct Trail10b { u8 moved; u8 changed; u8 p2[2]; s32 cur; u8 p8[8]; Vec4 pts[32]; };
/*TARGET 0010b468*/
u8 wtarget_0010b468(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_0010b468jjjj");
u8 wtarget_0010b468(u32 a0, u32 a1, u32, u32) {
    Trail10b* t = (Trail10b*)a0;
    const Vec4* v = (const Vec4*)a1;
    t->changed = 0;
    if (t->cur < 0) {
        s32 i;
        Vec4* p = t->pts;
        for (i = 31; i >= 0; i--) { *p = *v; p++; }
        t->cur = 0;
    } else {
        Vec4 d;
        vu_sub_to(&d, v, &t->pts[t->cur]);
        if (!(2025.0f <= vu_dot(&d, &d))) return t->changed;
        t->cur = (t->cur + 1) % 32;
        t->pts[t->cur] = *v;
        t->moved = 1;
    }
    t->changed = 1;
    asm volatile("" ::: "memory");
    return t->changed;
}
}  // namespace n0010b468

// 0010b550 (was src/anon/probe.cpp)
namespace n0010b550 {
struct Pair8 { u8 a; u8 b; u8 pad[2]; s32 c; };
/*TARGET 0010b550*/
void func_0010b550(Pair8* p) asm("func_0010b550");
void func_0010b550(Pair8* p) {
    p->a = 0;
    p->b = 0;
    p->c = -1;
}
}  // namespace n0010b550

// 0010b568 (was src/anon/batch_w66.cpp)
namespace n0010b568 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq vsubn(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 vlen2(const Vq& a) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a) : "$8", "memory");
    return r;
}
// 0010a4d0: moved to src/anon/unit_00109c30.cpp
// ---- 0010b568
void func_0010b468(u8*, Vq*) asm("func_0010b468");
void wtarget_0010b568(u8* a, Vq* b, f32 r) asm("_Z16wtarget_0010b568jjjj");
/*TARGET 0010b568*/
void wtarget_0010b568(u8* a, Vq* b, f32 r) asm("_Z16wtarget_0010b568jjjj");
void wtarget_0010b568(u8* a, Vq* b, f32 r) {
    f32 r2 = r * r;
    func_0010b468(a, b);
    Vq* p = (Vq*)(a + 16);
    for (s32 i = 0; i < 32; i++, p++) {
        Vq d;
        d = vsubn(*p, *b);
        if (r2 < vlen2(d)) *p = *b;
    }
}
}  // namespace n0010b568

// 0010b620 (was src/anon/batch_w86.cpp)
namespace n0010b620 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Obj { f32 f0; u32 pad[3]; QWord a; QWord b; };
#define F(q,i) (((f32*)&(q))[i])
void func_0010b620(Obj* o, const QWord* p, const QWord* q) asm("func_0010b620");
/*TARGET 0010b620*/
/*NOSYM*/ void func_0010b620(Obj* o, const QWord* p, const QWord* q);
void func_0010b620(Obj* o, const QWord* p, const QWord* q)
{
    o->a = Sub(*p, *q);
    o->f0 = F(o->a, 1);
    o->b = o->a;
    o->b.v[1] = 0;
    F(o->a, 3) = Normalize(&o->a);
    F(o->b, 3) = Normalize(&o->b);
}
}  // namespace n0010b620

// 0010b6e8 (was gap, never written)
namespace n0010b6e8 {
s32 func_0010b6e8(s32 id) asm("func_0010b6e8");
s32 func_0010b6e8(s32 id) {
    switch (id) {
    case 2: return 0;
    case 3: return 1;
    case 5: return 2;
    case 15: return 3;
    case 6: return 4;
    case 7: return 5;
    case 8: return 6;
    case 9: return 7;
    case 10: return 8;
    case 11: return 9;
    case 12: return 10;
    case 13: return 11;
    case 200: return 14;
    case 201: return 15;
    case 202: return 16;
    case 203: return 17;
    case 204: return 18;
    }
    return -1;
}
}

