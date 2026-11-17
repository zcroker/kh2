// Linked unit 0x00117778-0x00119bf8.
#include "../naka/libkn/stitch.hpp"
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 001182d0 (was src/anon/batch_w26.cpp)
namespace n001182d0 {
void* func_0010cce0(void*) asm("func_0010cce0");
s32 obj_is_culling(void*) asm("_ZN2YS3OBJ10is_cullingEv");
/*TARGET 001182d0*/
// Allocates a 288-byte object from the allocator and initialises it.
// 001024b0: moved to src/global/unit_001022c0.cpp

// Counts objects that are not culled.
s32 func_001182d0(void) asm("func_001182d0");
// Allocates a 288-byte object from the allocator and initialises it.
// 001024b0: moved to src/global/unit_001022c0.cpp

// Counts objects that are not culled.
s32 func_001182d0(void) {
    s32 n = 0;
    void* p = 0;
    while ((p = func_0010cce0(p)) != 0) {
        if (!obj_is_culling(p)) n++;
    }
    return n;
}
}  // namespace n001182d0

// 00118328 (was src/anon/tiny_auto80_queue.cpp)
namespace n00118328 {
u32 func_0010f6b8(...) asm("func_0010f6b8");
// count_reached_threshold
extern "C" u32 func_00111e38(...) asm("func_00111e38");
u32 func_001182d0(...) asm("func_001182d0");
/*TARGET 00118328*/
u32 func_00118328(u32 a0) asm("_Z13func_00118328j");
u32 func_00118328(u32 a0) {
    u32 s0 = a0;
    u32 r2 = func_00111e38(0u);
    u32 t7 = *(volatile u32*)((u32)s0 + (s32)(20));
    u32 v0 = ((u32(*)(u32, f32))func_0010f6b8)(r2, *(volatile f32*)((u32)t7 + (s32)(8)));
    u32 r15 = 0u;
    if (v0 != 0u) {
        v0 = func_001182d0();
        r15 = (u32)((s32)0 < (s32)v0);
    }
    return r15;
}
}  // namespace n00118328

// 00118378 (was src/anon/batch_w2043.cpp)
namespace n00118378 {
struct W2043b_Tg;
// 0x0010e130: definition moved into src/anon/unit_0010dee8.cpp


struct W2043b_Vq {
    f32 x, y, z, w;
    W2043b_Vq& operator=(const W2043b_Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline W2043b_Vq W2043b_vsub(const W2043b_Vq& a, const W2043b_Vq& b) {
    W2043b_Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 W2043b_vnormalize(W2043b_Vq* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct W2043b_TgVt { u8 pad[0x60]; s32 (*f60)(W2043b_Tg*); void (*f64)(W2043b_Tg*, void*); };
struct W2043b_Tg { W2043b_TgVt* vt; };
struct W2043b_Hdl { W2043b_Tg* p; u8 pad[0x1c]; };
struct W2043b_Res { W2043b_Vq a; W2043b_Vq b; };
struct W2043b_Ent { W2043b_Vq v; u8 pad[8]; u32 f18; };
struct W2043b_Obj { u8 p0[4]; u32 f4; u8 p1[0x620 - 8]; void* f620; s32 f624; };
void* func_00106a60(s32) asm("func_00106a60");
void func_00107368(void*, W2043b_Vq*) asm("func_00107368");
void* func_001050d8(u32) asm("func_001050d8");
void func_0018d238(void*, u32, u32, u32, u32, s32, s32) asm("func_0018d238");
void func_00190128(void*) asm("func_00190128");
void* func_00190730(W2043b_Hdl*, void*) asm("func_00190730");
s32 func_00112d90(W2043b_Hdl*) asm("func_00112d90");
s32 func_001901c0(W2043b_Hdl*) asm("func_001901c0");
s32 func_0018d940(void*, W2043b_Tg*) asm("func_0018d940");
s32 func_0019c410(W2043b_Tg*) asm("func_0019c410");
void* func_00112f88(W2043b_Hdl*) asm("func_00112f88");
void func_0018a818(W2043b_Res*, W2043b_Tg*, void*) asm("func_0018a818");
W2043b_Ent* func_0018db38(void*, W2043b_Tg*, u32, u32) asm("func_0018db38");
void func_0018ca10(W2043b_Ent*) asm("func_0018ca10");
void func_001a55a8(W2043b_Vq*, s32) asm("func_001a55a8");
/*TARGET 00118378*/
void func_00118378(W2043b_Obj* o, s32 a1) asm("func_00118378");
void func_00118378(W2043b_Obj* o, s32 a1) {
    W2043b_Vq base;
    W2043b_Vq dir;
    func_00107368(func_00106a60(1), &base);
    if (o->f620 == 0) {
        void* p = func_001050d8(208);
        func_0018d238(p, o->f4, 0, 1210, 0, -1, -1);
        o->f620 = p;
        o->f624 = a1;
    }
    void* n = 0;
    W2043b_Hdl it;
    func_00190128(&it);
    W2043b_Res r;
    r.a.w = 0;
    func_00190128(&it);
    while ((n = func_00190730(&it, n)) != 0) {
        if (!func_00112d90(&it)) continue;
        if (!func_001901c0(&it)) continue;
        W2043b_Tg* t = it.p;
        if (!func_0018d940(o->f620, t)) continue;
        if (func_0019c410(t)) continue;
        void* v = func_00112f88(&it);
        if (!v) continue;
        func_0018a818(&r, t, v);
        dir = W2043b_vsub(r.b, base);
        W2043b_vnormalize(&dir);
        W2043b_Ent* e = func_0018db38(o->f620, t, 0, 0);
        if (!e) continue;
        s32 f = (e->f18 & 1) ^ 1;
        e->v = dir;
        t->vt->f64(t, e);
        func_0018ca10(e);
        if (!f) continue;
        if (!t->vt->f60(t)) func_001a55a8(&r.b, 111);
    }
}
}  // namespace n00118378

