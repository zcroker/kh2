// YS::NPC (0x18aac0-0x18c8b8): constructor pair, update, routine actions, static init.
// Flags -g -fno-strict-aliasing (from the _gnsa old copy 0x18c258).
#include "../../common/types.h"
#include "../../anon/tiny_auto80_solver_structs.hpp"
#include "../../kn/fvector.hpp"
#include "../../anon/tiny_auto80_queue_structs.hpp"
#include "areadata.hpp"
#include "progress.hpp"
#include <stdarg.h>
#include "../../tozawa/menu_sound.hpp"
#include "../../anon/auto80_199_queue_decls.hpp"
#include "../../anon/auto80_199_queue_structs.hpp"
#include "../../harata/libdk/ft4.hpp"
#include "../../harata/libdk/sprite.hpp"
#include "../../harata/libdk/treasure_info.hpp"
#include "../../tozawa/cmenu_top.hpp"
#include "../../tozawa/help_gra.hpp"
#include "npc.hpp"

// ---- 0018aac0 gap: C2 copy of the YS::NPC constructor 0x18aba0 (never written before)
namespace n0018aac0 {
void func_001980d0(void*) asm("func_001980d0");
void func_0018c420(void*) asm("func_0018c420");
extern void* D_0034ee90[] asm("D_0034ee90");
void func_0018aac0(u8* p) asm("func_0018aac0");
void func_0018aac0(u8* p) {
    func_001980d0(p);
    *(void**)p = D_0034ee90;
    *(f32*)(p + 2596) = *(f32*)(p + 2592) = 0.0f;
    *(u32*)(p + 2608) = 0;
    func_0018c420(p + 2624);
    func_0018c420(p + 2720);
    *(f32*)(p + 2816) = 0.0f;
    *(u32*)(p + 1416) |= 8;
    *(u32*)(p + 1536) = (*(u32*)(p + 1536) & ~0x78) | 0x18;
    *(u32*)(p + 2824) = 0;
    *(u32*)(p + 2820) = 0;
    *(u32*)(p + 2828) = 0;
    *(f32*)(p + 2832) = 360.0f;
    *(f32*)(p + 2836) = 720.0f;
    *(f32*)(p + 2840) = 60.0f;
    *(f32*)(p + 2844) = 360.0f;
    *(f32*)(p + 2848) = 720.0f;
    *(f32*)(p + 2852) = 180.0f;
    *(f32*)(p + 2856) = 360.0f;
    *(f32*)(p + 2860) = 720.0f;
    *(f32*)(p + 2864) = 180.0f;
}
}  // namespace n0018aac0

// ---- 0018aba0 from src/anon/batch_w84.cpp
namespace n0018aba0 {
void func_001980d0(void*) asm("func_001980d0");
void func_0018c420(void*) asm("func_0018c420");
extern void* D_0034ee90[] asm("D_0034ee90");
void func_0018aba0(u8* p) asm("func_0018aba0");
void func_0018aba0(u8* p) {
    func_001980d0(p);
    *(void**)p = D_0034ee90;
    *(f32*)(p + 2596) = *(f32*)(p + 2592) = 0.0f;
    *(u32*)(p + 2608) = 0;
    func_0018c420(p + 2624);
    func_0018c420(p + 2720);
    *(f32*)(p + 2816) = 0.0f;
    *(u32*)(p + 1416) |= 8;
    *(u32*)(p + 1536) = (*(u32*)(p + 1536) & ~0x78) | 0x18;
    *(u32*)(p + 2824) = 0;
    *(u32*)(p + 2820) = 0;
    *(u32*)(p + 2828) = 0;
    *(f32*)(p + 2832) = 360.0f;
    *(f32*)(p + 2836) = 720.0f;
    *(f32*)(p + 2840) = 60.0f;
    *(f32*)(p + 2844) = 360.0f;
    *(f32*)(p + 2848) = 720.0f;
    *(f32*)(p + 2852) = 180.0f;
    *(f32*)(p + 2856) = 360.0f;
    *(f32*)(p + 2860) = 720.0f;
    *(f32*)(p + 2864) = 180.0f;
}
}  // namespace n0018aba0

// ---- 0018ac80 from src/anon/tiny_leaf_more.cpp
namespace n0018ac80 {
u32 func_0018ac80(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0018ac80jjjj");
u32 func_0018ac80(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r15 = (u32)(r5 >> 5);
    r14 = (u32)((s32)0u + (1));
    r15 = (u32)(r15 << 2);
    r5 = (u32)(r5 & 0x001fu);
    r4 = (u32)(r4 + r15);
    r14 = (u32)(r14 << (r5 & 31));
    r2 = *(u32*)((u32)r4 + (s32)(2820));
    r2 = (u32)(r2 & r14);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
}  // namespace n0018ac80

// ---- 0018aca8 from src/anon/tiny_auto80_solver.cpp
namespace n0018aca8 {
void func_0018aca8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0018aca8jjjjjjjj");
void func_0018aca8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0018aca8jjjjjjjj");
void func_0018aca8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 idx = a1 >> 5;
    a0 += 2820;
    idx <<= 2;
    a1 &= 31;
    a0 += idx;
    u32 val = *(u32*)a0;
    u32 mask = 1u << a1;
    val |= mask;
    *(u32*)a0 = val;
}
}  // namespace n0018aca8

// ---- 0018acd8 from src/anon/tiny_auto80_queue.cpp
namespace n0018acd8 {
void func_0018acd8(u32 a0, u32 a1) asm("_Z13func_0018acd8jj");
void func_0018acd8(u32 a0, u32 a1) {
    a0 = (u32)((s32)a0 + (2832));
    u32 end = (u32)((s32)a1 + (32));
    do {
        *(Pair_0018acd8*)((u32)a0 + (s32)(0)) = *(Pair_0018acd8*)((u32)a1 + (s32)(0));
        a1 = (u32)((s32)a1 + (16));
        a0 = (u32)((s32)a0 + (16));
    } while (a1 != end);
    *(u32*)((u32)a0 + (s32)(0)) = *(u32*)((u32)a1 + (s32)(0));
}
}  // namespace n0018acd8

// ---- 0018ad18 from src/anon/batch_w1822_nsa.cpp
namespace n0018ad18 {
struct W22Ent { u32 w; u32 x[3]; };
struct W22Sub8 { u8 pad[10]; u16 n; };
struct W22Q { u8 pad[8]; W22Sub8* s; };
struct W22R { u8 pad[0x24]; s32 f24; };
struct W22Bits {
    u32 w[1];
    bool Test(u32 i) { return (w[i >> 5] >> (i & 31)) & 1; }
    void Set(u32 i) { u32* q = &w[i >> 5]; *q |= 1 << (i & 31); }
};
struct W22P;
void func_00198450(W22P*) asm("func_00198450");
W22Ent* func_0019b308(W22Q*) asm("func_0019b308");
s32 func_0018c528(u8) asm("func_0018c528");
struct W22P {
    u8 pad[0x818]; W22Q* f818; W22R* f81c;
    u8 pad2[0xa40 - 0x820]; s32 a40; s32 a44; s32 a48;
    u8 pad3[0xb04 - 0xa4c]; W22Bits bits;
    void Init() {
        a44 = 0; a40 = 2; a48 = 0;
        W22Q* q = f818;
        s32 n = q->s->n;
        W22Ent* e = func_0019b308(q);
        for (s32 j = 0; j < n; j++) {
            if ((e[j].w & 0xff0000ff) == 0x04000000) a48 = func_0018c528(((u8*)&e[j])[1]);
        }
    }
};
void func_0018ad18(W22P* p) asm("func_0018ad18");
void func_0018ad18(W22P* p)
{
    func_00198450(p);
    if (p->f81c) {
        for (u32 i = 0; i < 7; i++) {
            if ((u8)((p->f81c->f24 >> i) & 1)) p->bits.Set(i);
        }
    }
    if (p->bits.Test(0)) p->Init();
}
}  // namespace n0018ad18

// ---- 0018ae30 gap: YS::NPC vtable slot (0x34ee9c), per-frame update (never written before)
namespace n0018ae30 {
void func_0018b110(u8*) asm("func_0018b110");
void func_0018b478(u8*) asm("func_0018b478");
s32 func_00191a50() asm("func_00191a50");
void func_001ad990(u8*, f32, f32, f32) asm("func_001ad990");
void func_0016a5b0(u8*) asm("func_0016a5b0");
static inline u8 nz(f32 v) { return v != 0.0f; }
void func_0018ae30(u8* p) asm("func_0018ae30");
void func_0018ae30(u8* p) {
    if ((*(u32*)(p + 2820) & 1) == 1) *(u32*)(p + 264) |= 4;
    else func_0018b478(p);
    func_0018b110(p);
    u8* t = *(u8**)(p + 2076);
    if (t && t[28] == 2) {
        u8* s = p + 2092;
        if (!nz(*(f32*)(s + 4)) && !func_00191a50() && !(*(u32*)(*(u8**)(p + 2072) + 4) & 8)) {
            if (++*(s32*)(p + 2828) >= 5) {
                if (!(*(u32*)(p + 2040) & 0x10)) {
                    f32 c = 10.0f;
                    func_001ad990(s, 1.0f, 0.0f, c);
                }
                *(u32*)(p + 2040) |= 0x10;
            }
        } else *(s32*)(p + 2828) = 0;
    }
    if (*(s32*)(p + 2828) || nz(*(f32*)(p + 2096))) *(u32*)(p + 264) |= 0x40;
    else *(u32*)(p + 264) &= ~0x40;
    func_0016a5b0(p);
}
}  // namespace n0018ae30

// ---- 0018af98 gap: YS::NPC vtable slot (0x34eea8), forwards to the base (never written before)
namespace n0018af98 {
void func_00198690(u8*) asm("func_00198690");
void func_0018af98(u8* p) asm("func_0018af98");
void func_0018af98(u8* p) { func_00198690(p); }
}  // namespace n0018af98

// ---- 0018afb0 gap: YS::NPC vtable slot (0x34eebc) (never written before)
namespace n0018afb0 {
struct VO { void** vt; };
void func_0018afb0(u8* p) asm("func_0018afb0");
void func_0018afb0(u8* p) {
    VO* o = *(VO**)(p + 12);
    ((void (*)(VO*, u8*, f32))o->vt[3])(o, p, 0.0f);
    *(u32*)(p + 264) |= 0x4000000;
    *(s32*)(p + 256) = -1;
    *(s32*)(p + 260) = -1;
}
}  // namespace n0018afb0

// ---- 0018b008 from src/anon/misc_1.cpp
namespace n0018b008 {
void func_0018b008(void* self) asm("_Z13func_0018b008Pv");
void func_0018b008(void* self) {}
}  // namespace n0018b008

// ---- 0018b010 from src/anon/batch_w1788.cpp
namespace n0018b010 {
struct W1788V4 {
    f32 x, y, z, w;
    W1788V4() {}
    W1788V4& operator=(const W1788V4& o) {
                                                            
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline W1788V4 operator-(const W1788V4& a, const W1788V4& b) {
    W1788V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 W1788_norm(W1788V4* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
W1788V4* func_0016c028() asm("func_0016c028");
void func_0018b008(void*, W1788V4*, void*, W1788V4*) asm("func_0018b008");
void func_0018b010(void* a, W1788V4* p, void* c) asm("func_0018b010");
void func_0018b010(void* a, W1788V4* p, void* c) {
    W1788V4 d;
    d = *p - *func_0016c028();
    W1788_norm(&d);
    func_0018b008(a, &d, c, p);
}
}  // namespace n0018b010

// ---- 0018b0c8 from src/anon/tiny_auto80_queue.cpp
namespace n0018b0c8 {
u32 func_0016c2b0(...) asm("func_0016c2b0");
u32 func_0018b010(...) asm("func_0018b010");
void func_0018b0c8(u32 a0, u32 a1, u32 a2) asm("_Z13func_0018b0c8jjj");
void func_0018b0c8(u32 a0, u32 a1, u32 a2) {
    u8 tmp[16];
    u32 s0 = a0;
    u32 s1 = a2;
    func_0016c2b0((u32)tmp);
    func_0018b010(s0, (u32)tmp, s1);
}
}  // namespace n0018b0c8

// ---- 0018b110 from src/anon/batch_w65.cpp
namespace n0018b110 {
s32 func_0018b198(void*) asm("func_0018b198");
void func_001ad9c8(void*) asm("func_001ad9c8");
void func_0016aeb8(void*, f32) asm("func_0016aeb8");
void func_001b0728(void*, void*, s32, f32) asm("func_001b0728");
void func_0018b110(u8* p) asm("func_0018b110");
void func_0018b110(u8* p) {
    if (!func_0018b198(p)) return;
    func_001ad9c8(p + 2592);                             
    func_0016aeb8(p, *(f32*)(p + 2564) + *(f32*)(p + 2568) * *(f32*)(p + 2592));
    if (func_0018b198(p)) return;
    if (*(u8*)(p + 2560)) {
        func_001b0728(p + 1184, p + 2576, 0, 20.0f);
        *(u8*)(p + 2560) = 0;
    }
}
}  // namespace n0018b110

// ---- 0018b198 from src/anon/tiny_auto80_queue.cpp
namespace n0018b198 {
u32 func_0018b198(u32 a0) asm("_Z13func_0018b198j");
u32 func_0018b198(u32 a0) {
    u32 r = 1u;
    if (*(f32*)((u32)a0 + (s32)(2596)) == 0.0f) {
        r = 0u;
    }
    return (u32)(r & 0xffu);
}
}  // namespace n0018b198

// ---- 0018b1b8 from src/anon/tiny_auto80_fptr4.cpp
namespace n0018b1b8 {
u32 func_0018c598(u32, u32, u32, u32) asm("_Z13func_0018c598jjjj");
u32 func_0018b1b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0018b1b8jjjj");
u32 func_0018b1b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r5 = r4;
    r4 = (u32)((s32)r4 + (2624));
    u32 (*fp_call4_0018c598)(u32, u32, u32, u32) = func_0018c598;
    r2 = fp_call4_0018c598(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0018b1b8

// ---- 0018b1d8 from src/anon/tiny_auto80_queue.cpp
namespace n0018b1d8 {
u32 func_0018b1d8(u32 a0) asm("_Z13func_0018b1d8j");
u32 func_0018b1d8(u32 a0) {
    u32 t7 = *(u32*)((u32)a0 + (s32)(2820));
    u32 t6 = (u32)(t7 & 0x0040u);
    t7 = (u32)(t7 & 0x0010u);
    u32 v0;
    v0 = 0u;
    if (t7 != 0u) goto L1;
    if (t6 == 0u) goto L2;
L1:
    v0 = 1u;
L2:
    return (u32)(v0 ^ 1u);
}
}  // namespace n0018b1d8

// ---- 0018b200 from src/anon/batch_w43.cpp
namespace n0018b200 {
s32 func_001883d8(u8*, void*) asm("func_001883d8");
void func_001880b0(u8*, void*) asm("func_001880b0");
void func_0018b200(u8* p) asm("func_0018b200");
void func_0018b200(u8* p) {
    u8* s = p + 768;
    if (*(u8*)(*(u8**)(p + 8) + 4) == 15) {
        if (func_001883d8(s, (u8*)"before_check")) func_001880b0(s, (u8*)"before_check");
    }
}
}  // namespace n0018b200

// ---- 0018b270 from src/anon/tiny_auto80_queue.cpp
namespace n0018b270 {
void func_0018b338(f32) asm("_Z13func_0018b338f");
void func_0018b270(void) asm("_Z13func_0018b270v");
void func_0018b270(void) {
    func_0018b338(0.0f);
}
}  // namespace n0018b270

// ---- 0018b288 from src/anon/batch_wcx.cpp
namespace n0018b288 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
V4* func_0016c028(u8*) asm("func_0016c028");
void func_0016aef0(u8*, V4*) asm("func_0016aef0");
s32 func_0019ba60(u8*) asm("func_0019ba60");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_0018b288(u8* p, V4* v, f32 x) asm("func_0018b288");
void func_0018b288(u8* p, V4* v, f32 x)
{
    if (!(*(u32*)(p + 2820) & 0x10)) {
        V4 d;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(v), "r"(func_0016c028(p)) : "memory");                          
        func_0016aef0(p, &d);
    }
    if ((*(u8**)(p + 8))[4] != 15) return;
    u8* o = *(u8**)(p + 2824);
    if (o && func_0019ba60(o)) func_0017f488(*(u8**)(p + 2824) + 320, 50, x, 0.0f);
}
}  // namespace n0018b288

// ---- 0018b338 from src/anon/batch_w265.cpp
namespace n0018b338 {
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001b0498(u8*) asm("func_001b0498");
void func_001b0700(u8*, f32) asm("func_001b0700");
void func_0018c438(u8*) asm("func_0018c438");
s32 func_001883d8(u8*, const char*) asm("func_001883d8");
void func_001880b0(u8*, const char*) asm("func_001880b0");
struct Q265g { u8 pad[8]; u8* t; u8 pad1[2620]; s32 a; u8 pad2[180]; f32 f2816; u32 b0 : 1; u32 rest : 31; Q265g* o; };
void func_0018b338(Q265g* p, f32 x) asm("func_0018b338");
void func_0018b338(Q265g* p, f32 x) {
    u8* q;
    if (p->t[4] != 15) return;
    { s32 a; if (p->b0) a = p->a; else a = 0; func_0017f488((u8*)p + 320, a, x, 0.0f); }
    if (p->o && func_0019ba60((u8*)p->o)) {
        s32 a; if (p->b0) a = p->a; else a = 0; func_0017f488((u8*)p->o + 320, a, x, 0.0f);
    }
    if (!p->b0) {
        q = (u8*)p + 1184;
        if (func_001b0498(q)) func_001b0700(q, 0.0f);                          
        *(s32*)((u8*)p + 2720) = 4;
        func_0018c438((u8*)p + 2624);
        p->f2816 = *(f32*)((u8*)p + 2840) + 60.0f;
    }
    p = (Q265g*)((u8*)p + 768);
    if (func_001883d8((u8*)p, "after_talk")) func_001880b0((u8*)p, "after_talk");
}
}  // namespace n0018b338

// ---- 0018b478 from src/anon/batch_w1646.cpp
namespace n0018b478 {
#define W1646_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1646Vec {
    f32 x, y, z, w;
    W1646Vec& operator=(const W1646Vec& o) { if (this != &o) W1646_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1646Hd { s32 f04; s32 f08; s32 f0c; };
struct W1646Act {
    s32 type;
    W1646Hd h;
    W1646Vec v10;
    s32 f20;
    u8 f24;
    f32 f28;
    f32 f2c;
    u8 f30;
    u8 f31;
    W1646Vec v40;
    f32 f50;
};
struct W1646Npc {
    u8 pad[0xa40];
    W1646Act act;
    W1646Act prev;
    f32 timer;
    u8 padb04[0xc];
    f32 fb10;
    f32 fb14;
    u8 padb18[4];
    f32 fb1c;
    f32 fb20;
};
static inline void w1646_vnorm(W1646Vec* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
}
static inline f32 w1646_vdot(const W1646Vec* a, const W1646Vec* b) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8", "memory");
    return d;
}
extern f32 D_00349e10 asm("D_00349e10");
s32 func_001c0cd8(W1646Npc*) asm("func_001c0cd8");
void func_0018c570(W1646Act*) asm("func_0018c570");
s32 func_0018bd50(W1646Npc*, s32) asm("func_0018bd50");
void func_0018c438(W1646Act*) asm("func_0018c438");
f32 w1646_angle(f32, f32) asm("_Z13func_001065a8jjjjjjjj");
W1646Npc* func_0018b8e0(W1646Npc*, s32*) asm("func_0018b8e0");
void func_0016af58(W1646Vec*, W1646Npc*) asm("func_0016af58");
void func_0018bb70(W1646Npc*, s32, W1646Npc*, u8, f32) asm("func_0018bb70");
void func_0018b7f8(W1646Npc*) asm("func_0018b7f8");
void func_0018b478(W1646Npc* o) asm("func_0018b478");
void func_0018b478(W1646Npc* o) {
    if (func_001c0cd8(o)) return;
    func_0018c570(&o->act);
    f32 t = o->timer;
    if (t > 0.0f) o->timer = t - D_00349e10;
    s32 type = o->act.type;
    if (type != 4) {
        if (o->prev.type != 4 || (t = o->timer) <= 0.0f) {
            if (func_0018bd50(o, 5)) {
                if (o->act.type != 0) o->prev = o->act;
                func_0018c438(&o->act);
                o->act.f50 = w1646_angle(o->fb10, o->fb14);
                o->act.type = 4;
                o->act.h.f04 = 2;
                o->act.f24 = 0;
                o->act.f31 = 1;
                return;
            }
            type = o->act.type;
        }
    }
    if ((u32)(type - 4) >= 2) {
        if (o->prev.type == 5 && !((t = o->timer) <= 0.0f)) return;
        s32 ids[2];
        W1646Npc* other = func_0018b8e0(o, ids);
        if (other) {
            if (o->act.type != 0) o->prev = o->act;
            W1646Vec va;
            W1646Vec vb;
            u8 front = 1;
            f32 ang = w1646_angle(o->fb1c, o->fb20);
            func_0016af58(&va, o);
            func_0016af58(&vb, other);
            f32 zero = 0.0f;
            vb.y = zero;
            va.y = zero;
            w1646_vnorm(&va);
            w1646_vnorm(&vb);
            if (zero <= w1646_vdot(&va, &vb)) front = 0;
            func_0018bb70(o, ids[0], other, 1, ang);
            func_0018bb70(other, ids[1], o, front, ang);
            return;
        }
    }
    if ((t = o->timer) <= 0.0f) {
        o->timer = 0.0f;
        func_0018b7f8(o);
    }
}
}  // namespace n0018b478

// ---- 0018b7f8 from src/anon/batch_w79.cpp
namespace n0018b7f8 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct Q16 {
    u128 v;
    Q16() {}
    Q16(const Q16& o) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    Q16& operator=(const Q16& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
Q16* func_0016c028(void*) asm("func_0016c028");
s32 func_0019b3d0(void*, Q16*) asm("func_0019b3d0");
void func_0018c438(void*) asm("func_0018c438");
s32 func_0019b308(void*) asm("func_0019b308");
void func_0018c650(void*, Q16*, u32, s32, s32, f32, f32) asm("func_0018c650");
void func_0018b7f8(u8* p) asm("func_0018b7f8");
void func_0018b7f8(u8* p) {
    Q16 pos = *func_0016c028(p);                          
    void* t;
    s32 id;
    ((f32*)&pos)[1] -= 10.0f;
    t = *(void**)(p + 2072);
    if (t == 0) return;
    id = func_0019b3d0(t, &pos);
    if (id == *(s32*)(p + 2608)) return;
    {
        u8* q = p + 2624;
        if (q[48] == 0) {
            func_0018c438(q);
            if (id != 0) {
                Q16* v = func_0016c028(p);                          
                void* tt = *(void**)(p + 2072);
                u32 k = *(u16*)(*(u8**)((u8*)tt + 8) + 10);
                func_0018c650(q, v, k, func_0019b308(tt), id, *(f32*)(p + 2856), *(f32*)(p + 2860));
            }
        }
    }
    *(s32*)(p + 2608) = id;
}
}  // namespace n0018b7f8

// ---- 0018b8e0 from src/anon/batch_w2370.cpp
namespace n0018b8e0 {
struct Obj_w2370 { u8 pad[0x588]; u32 flags; u8 pad2[0xa70 - 0x58c]; u8 busy; };
Obj_w2370* func_0018bc60(void*, s32) asm("func_0018bc60");
s32 func_0018bae8(void*, void*) asm("func_0018bae8");
Obj_w2370* func_0018b8e0(void* a, s32* out) asm("func_0018b8e0");
Obj_w2370* func_0018b8e0(void* a, s32* out) {
    Obj_w2370* p = func_0018bc60(a, 0);
    if (p == 0) return 0;
    if ((p->flags & 8) && !p->busy) {
        s32 x = func_0018bae8(a, p);
        s32 y = func_0018bae8(p, a);
        Obj_w2370* r;
        if (x && y) {
            out[0] = x;
            out[1] = y;
            r = p;
        } else r = 0;
        return r;
    }
}
}  // namespace n0018b8e0

// ---- 0018b988 from src/anon/auto80_199_queue.cpp
namespace n0018b988 {
void func_0018b988(u32 a0) asm("_Z13func_0018b988j");
void func_0018b988(u32 a0) {
    u32 s1 = a0;
    if (*(u8*)(a0 + 2672) != 0) return;

    u32 s2 = func_0018be00(a0, 0);
    if (s2 == 0) return;
    if ((*(u32*)(s2 + 1416) & 8) == 0) return;

    u32 s0 = func_0018bae8(s1, s2);
    u32 v0 = func_0018bae8(s2, s1);
    if (s0 != 0) return;
    if (v0 != 0) return;
    func_0018ba28(s1, s2);
}
}  // namespace n0018b988

// ---- 0018ba28 from src/anon/batch_w77.cpp
namespace n0018ba28 {
void func_0018c438(u8*) asm("func_0018c438");
void func_0018bfa0(u8*, u8*, f32) asm("func_0018bfa0");
void func_0018ba28(u8* a, u8* b) asm("func_0018ba28");
void func_0018ba28(u8* a, u8* b)
{
    u8* hi = a;
    u8* lo = b;
    if (!(*(f32*)(a + 28) > *(f32*)(b + 28))) {
        hi = b;
        lo = a;
    }
    f32 k = 120.0f;
    func_0018c438(hi + 2624);
    *(f32*)(hi + 2704) = k;
    hi[2673] = 1;
    *(u32*)(hi + 2628) = 1;
    *(u8**)(hi + 2636) = lo;
    hi[2660] = 0;
    *(u32*)(hi + 2624) = 3;
    func_0018bfa0(hi, lo, 200.0f);
    func_0018c438(lo + 2624);
    *(f32*)(lo + 2704) = k;
    lo[2673] = 1;
    *(u32*)(lo + 2624) = 7;
}
}  // namespace n0018ba28

// ---- 0018bae8 from src/anon/batch_w1545.cpp
namespace n0018bae8 {
struct W1545E18 { u8 used; u8 pad[3]; s32 id; u8 pad2[8]; };
struct W1545Hd { u8 pad[10]; u16 n; };
struct W1545H18 { u8 pad[8]; W1545Hd* hdr; };
struct W1545O18 { u8 pad[0x818]; W1545H18* h; };
s32 func_0016b740(s32) asm("func_0016b740");
W1545E18* func_0019b308(W1545H18*) asm("func_0019b308");
W1545E18* func_0018bae8(W1545O18* self, s32 key) asm("func_0018bae8");
W1545E18* func_0018bae8(W1545O18* self, s32 key) {
    W1545H18* a = self->h;
    u16 n = a->hdr->n;
    W1545E18* p = func_0019b308(a);
    for (s32 i = 0; i < n; i++) {
        if (p[i].used == 0 && func_0016b740(p[i].id) == key) return &p[i];
    }
    return 0;
}
}  // namespace n0018bae8

// ---- 0018bb70 from src/anon/auto80_199_queue.cpp
namespace n0018bb70 {
void func_0018bb70(u32 a0, u32 a1, u32 a2, u32 a3, float f12) asm("_Z13func_0018bb70jjjjf");
void func_0018bb70(u32 a0, u32 a1, u32 a2, u32 a3, float f12) {
    u32 s0 = a0;
    u32 s1 = a3 & 0xFF;
    u32 s2 = a2;
    u32 s3 = a1;

    func_0018c438(s0 + 2624);
    *(float*)(s0 + 2704) = f12;
    *(u8*)(s0 + 2673) = 1;
    *(u32*)(s0 + 2624) = 5;
    *(u32*)(s0 + 2636) = s2;
    *(u32*)(s0 + 2628) = 1;
    *(u8*)(s0 + 2660) = (u8)s1;
    *(u32*)(s0 + 2632) = func_0018c528(*(u8*)(s3 + 1));
}
}  // namespace n0018bb70

// ---- 0018bbf8 from src/anon/batch_w36.cpp
namespace n0018bbf8 {
u32 ctarget_0018bbf8(u32, u32, u32, u32) asm("_Z16ctarget_0018bbf8jjjj");
u32 func_0016c028(void) asm("func_0016c028");
u32 func_0018c490(u8*, u32) asm("func_0018c490");
void func_0018c480(u8*, u32) asm("func_0018c480");
u32 ctarget_0018bbf8(u32 a0, u32, u32, u32) {
    u8* q = (u8*)a0 + 2624;
    if (q[48]) return 0;
    u32 r = func_0018c490(q, func_0016c028());
    if (r) func_0018c480(q, 1);
    return r;
}
}  // namespace n0018bbf8

// ---- 0018bc60 from src/anon/batch_w83.cpp
namespace n0018bc60 {
struct Info32 {
    u32 f0, f4, f8, f12;
    u32 pad[4];
    Info32() { f12 = 0; }
};
void* func_0016bc20(void*, void*, s32) asm("func_0016bc20");
void func_0018a818(Info32*, void*, void*) asm("func_0018a818");
void* func_001b9bc8(void*) asm("func_001b9bc8");
s32 func_0016bff0(void*) asm("func_0016bff0");
s32 func_0018a550(Info32*, Info32*) asm("func_0018a550");
void* func_0018bc60(void* a, void* b) asm("func_0018bc60");
void* func_0018bc60(void* a, void* b) {
    void* v = func_0016bc20(a, b, -1);
    if (!v) return 0;
    Info32 i0;
    func_0018a818(&i0, a, v);
    void* it = 0;
    Info32 i1;
    while ((it = func_001b9bc8(it))) {
        if (func_0016bff0(it) == func_0016bff0(a)) continue;
        void* w = func_0016bc20(it, b, -1);
        if (!w) continue;
        func_0018a818(&i1, it, w);
        if (func_0018a550(&i0, &i1)) return it;
    }
    return 0;
}
}  // namespace n0018bc60

// ---- 0018bd50 from src/anon/batch_w66.cpp
namespace n0018bd50 {
struct S18b { u8 pad[12]; u32 f12; u8 pad2[16]; S18b() { f12 = 0; } };
u32 func_0016bc20(u32, u32, s32) asm("func_0016bc20");
void func_0018a818(S18b*, u32, u32) asm("func_0018a818");
s32 func_0018a550(S18b*, S18b*) asm("func_0018a550");
extern u32 D_0034e948 asm("D_0034e948");
s32 func_0018bd50(u32 a, u32 b) asm("func_0018bd50");
s32 func_0018bd50(u32 a, u32 b) {
    u32 v = func_0016bc20(a, b, -1);
    if (!v) return 0;
    S18b t1;
    func_0018a818(&t1, a, v);
    u32 s = D_0034e948;
    S18b t2;
    if (s) {
        u32 w = func_0016bc20(s, 1, -1);
        if (!w) return 0;
        func_0018a818(&t2, s, w);
        if (func_0018a550(&t1, &t2)) return 1;
    }
    return 0;
}
}  // namespace n0018bd50

// ---- 0018be00 from src/anon/batch_w1949.cpp
namespace n0018be00 {
struct W1949Vec {
    f32 x, y, z, w;
    W1949Vec() {}
    W1949Vec(const W1949Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct W1949Hit { s32 a; f32 b; s32 x8; s32 c; W1949Vec v; W1949Hit() { c = 0; } };
struct W1949Obj { u8 pad[0x850]; W1949Vec p; };
static inline void w1949_scalew(W1949Vec* v) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(v), "f"(v->w) : "$8", "memory");
}
static inline void w1949_add(W1949Vec* d, W1949Vec* s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(d), "r"(s) : "memory");
}
void* func_0016bc20(W1949Obj*, s32, s32) asm("func_0016bc20");
void func_0018a818(W1949Hit*, W1949Obj*, void*) asm("func_0018a818");
W1949Obj* func_001b9bc8(W1949Obj*) asm("func_001b9bc8");
s32 func_0016bff0(W1949Obj*) asm("func_0016bff0");
s32 func_0018a550(W1949Hit*, W1949Hit*) asm("func_0018a550");
void func_0018bfa0(W1949Obj*, W1949Obj*, f32) asm("func_0018bfa0");
W1949Obj* func_0018be00(W1949Obj* o, s32 k) asm("func_0018be00");
W1949Obj* func_0018be00(W1949Obj* o, s32 k) {
    void* h = func_0016bc20(o, k, -1);
    if (h == 0) return 0;
    W1949Hit a;
    func_0018a818(&a, o, h);
    a.b = a.b + a.b;
    W1949Vec t = o->p; w1949_scalew(&t); w1949_add(&a.v, &t);
    W1949Hit b;
    W1949Obj* e = 0;
    while ((e = func_001b9bc8(e)) != 0) {
        if (func_0016bff0(e) == func_0016bff0(o)) continue;
        h = func_0016bc20(e, k, -1);
        if (h == 0) continue;
        func_0018a818(&b, e, h);
        b.b = b.b + b.b;
        W1949Vec t2 = e->p; w1949_scalew(&t2); w1949_add(&b.v, &t2);
        if (func_0018a550(&a, &b)) { func_0018bfa0(o, e, b.b); return e; }
    }
    return 0;
}
}  // namespace n0018be00

// ---- 0018bfa0 from src/anon/batch_w286.cpp
namespace n0018bfa0 {
#define QCOPY_bfa0(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV_bfa0 {
    f32 x, y, z, w;
    QV_bfa0() {}
    QV_bfa0(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV_bfa0(const QV_bfa0& o) { QCOPY_bfa0(this, &o); }
    QV_bfa0& operator=(const QV_bfa0& o) { if (this != &o) QCOPY_bfa0(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline f32 normalize_bfa0(QV_bfa0* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline QV_bfa0 operator-(const QV_bfa0& a, const QV_bfa0& b) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QV_bfa0 operator+(const QV_bfa0& a, const QV_bfa0& b) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QV_bfa0 cross_bfa0(const QV_bfa0& a, const QV_bfa0& b) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void scale_bfa0(QV_bfa0* v, f32 k) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(v), "f"(k) : "$8", "memory");
}
struct Act_bfa0 { u8 pad[0xa80]; QV_bfa0 xa80; };
static inline QV_bfa0 operator*(const QV_bfa0& a, f32 k) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
#define QCOPY_b0a8(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV_b0a8 {
    f32 x, y, z, w;
    QV_b0a8() {}
    QV_b0a8(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV_b0a8(const QV_b0a8& o) { QCOPY_b0a8(this, &o); }
} __attribute__((aligned(16)));
QV_bfa0* func_0016c028(void*) asm("func_0016c028");
void func_0018bfa0(Act_bfa0* a, void* b, f32 dist) asm("func_0018bfa0");
void func_0018bfa0(Act_bfa0* a, void* b, f32 dist) {
  QV_bfa0 d = *func_0016c028(a) - *func_0016c028(b);                          
  normalize_bfa0(&d);
  QV_bfa0 c = cross_bfa0(d, QV_bfa0(0.0f, 1.0f, 0.0f, 0.0f));
  normalize_bfa0(&c);
  scale_bfa0(&c, dist);
  QV_bfa0 s = *func_0016c028(b) + c;
  QV_bfa0 t = s - *func_0016c028(a);                          
  normalize_bfa0(&t);
  a->xa80 = t;
}
}  // namespace n0018bfa0

// ---- 0018c150 from src/anon/batch_w78.cpp
namespace n0018c150 {
struct W78Vec {
    f32 x, y, z, w;
    W78Vec& operator=(const W78Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void vsub(W78Vec* d, const W78Vec* a, const W78Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
struct W78VecC { f32 x,y,z,w; W78VecC(const W78VecC& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); } } __attribute__((aligned(16)));
static inline W78Vec operator-(const W78Vec& a, const W78Vec& b) { W78Vec r; vsub(&r, &a, &b); return r; }
struct W78Hdr { u32 a, b, c, d; };
struct W78St {
    W78Hdr h;
    W78Vec v1;
    u32 x20; u8 x24; f32 x28, x2c; u8 x30, x31;
    W78Vec v2;
    f32 x50;
};
void func_0018c480(W78St*, s32) asm("func_0018c480");
void func_0018c438(W78St*) asm("func_0018c438");
void func_0018c150(u8* p) asm("func_0018c150");
void func_0018c150(u8* p) {
    W78St* s = (W78St*)(p + 2624);
    *(W78St*)(p + 2720) = *s;
    func_0018c480(s, 0);
    func_0018c438(s);
    s32 m = *(s32*)(p + 2624);
    f32 f;
    switch (m) {
    case 4: f = *(f32*)(p + 2840); break;
    case 5: f = *(f32*)(p + 2852); break;
    default: f = *(f32*)(p + 2864); break;
    }
    *(f32*)(p + 2816) = f;
}
}  // namespace n0018c150

// ---- 0018c240 from src/anon/batch_w1665.cpp
namespace n0018c240 {
u8* func_0018c240(u8* p) asm("func_0018c240");
u8* func_0018c240(u8* p) { return p + 2624; }
}  // namespace n0018c240

// ---- 0018c250 from src/yasui/libys/npc.cpp
namespace YS {
u8 NPC::is_rtn_change_dir() {
    return reinterpret_cast<const NPCLayout*>(this)->rtn_change_dir;
}
}  // namespace YS

// ---- 0018c258 from src/anon/sweep_0018c258_gnsa.cpp
namespace n0018c258 {
struct QW18c { f32 x, y, z, w;
    QW18c() {}
    QW18c(const QW18c& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QW18c& operator=(const QW18c& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline QW18c operator-(const QW18c& a, const QW18c& b) {
    QW18c r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Normalize18c(QW18c* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Obj18c {
    u8 p0[2624]; s32 kind; s32 mode; s32 p2632; Obj18c* tgt; QW18c v2640; u8 p1[2688 - 2656]; QW18c v2688;
};
void func_0016af58(QW18c*, Obj18c*) asm("func_0016af58");
QW18c* func_0016c028(Obj18c*) asm("func_0016c028");
s32 func_0018c458(s32*) asm("func_0018c458");
s32 ctarget_0019ba60_18c(Obj18c*) asm("_Z16ctarget_0019ba60jjjj");
extern Obj18c* D_0034e948 asm("D_0034e948");
QW18c func_0018c258(Obj18c* o) asm("func_0018c258");
QW18c func_0018c258(Obj18c* o) {
    QW18c dir;
    func_0016af58(&dir, o);
    if (func_0018c458(&o->kind) && o->mode) {
        QW18c pos(*func_0016c028(o));
        pos.y = 0.0f;
        if (o->kind == 3) {
            Obj18c* t = o->tgt;
            if (t && ctarget_0019ba60_18c(t)) return o->v2688;
        } else {
            switch (o->mode) {
            case 1: {
                Obj18c* t = o->tgt;
                if (t && ctarget_0019ba60_18c(t)) {
                    QW18c tp(*func_0016c028(t));
                    tp.y = 0.0f;
                    dir = tp - pos;
                    Normalize18c(&dir);
                }
                break;
            }
            case 3:
                dir = o->v2640 - pos;
                Normalize18c(&dir);
                break;
            case 2: {
                Obj18c* t = D_0034e948;
                if (t) {
                    QW18c tp(*func_0016c028(t));
                    tp.y = 0.0f;
                    dir = tp - pos;
                    Normalize18c(&dir);
                }
                break;
            }
            }
        }
    }
    return dir;
}
}  // namespace n0018c258

// ---- 0018c408 gap: C2 copy of 0x18c420 (never written before)
namespace n0018c408 {
void func_0018c438(void*) asm("_Z13func_0018c438Pv");
void func_0018c408(BD_VALUE* bd) asm("func_0018c408");
void func_0018c408(BD_VALUE* bd) { func_0018c438(bd); }
}  // namespace n0018c408

// ---- 0018c420 from src/anon/tiny.cpp
namespace n0018c420 {
void func_0018c438(void*) asm("_Z13func_0018c438Pv");
void func_0018c420(BD_VALUE* bd) asm("_Z13func_0018c420P8BD_VALUE");
void func_0018c420(BD_VALUE* bd) { func_0018c438(bd); }
}  // namespace n0018c420

// ---- 0018c438 (RTN_ACTION clear; store order written rotated to get the retail schedule under -g)
namespace n0018c438 {
void func_0018c438(u8* p) asm("_Z13func_0018c438jjjj");
void func_0018c438(u8* p) {
    p[48] = 0;
    *(u32*)(p + 0) = 0;
    *(u32*)(p + 4) = 0;
    *(u32*)(p + 12) = 0;
    *(u32*)(p + 32) = 0;
    p[49] = 0;
}
}  // namespace n0018c438

// ---- 0018c458 from src/anon/tiny_auto80_queue.cpp
namespace n0018c458 {
u32 func_0018c458(u32 a0) asm("_Z13func_0018c458j");
u32 func_0018c458(u32 a0) {
    u32 v0 = 0u;
    if (*(u8*)((u32)a0 + (s32)(49)) != 0u) goto L1;
    if (*(u32*)((u32)a0 + (s32)(32)) == 0u) goto L2;
L1:
    v0 = 1u;
L2:
    return v0;
}
}  // namespace n0018c458

// ---- 0018c480 from src/anon/tiny.cpp
namespace n0018c480 {
void func_0018c480(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0018c480jjjj");
void func_0018c480(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a2;
    (void)a3;
    u32 v = a1 & 0x00ffu;
    *(u8*)((u32)a0 + (48)) = (u8)v;
}
}  // namespace n0018c480

// ---- 0018c490 from src/anon/batch_w54.cpp
namespace n0018c490 {
f32 func_001db510(void*) asm("func_001db510");
s32 func_0018c490(u8* p) asm("func_0018c490");
s32 func_0018c490(u8* p) {
    s32 r = 1;
    if (!*(u8*)(p + 49)) {
        void* q = *(void**)(p + 32);
        r = 0;
        if (q) {
            bool lt = *(f32*)(p + 44) < 0.5f;
            f32 v = func_001db510(q);
            r = 1;
            if (lt) {
                if (!(*(f32*)(p + 40) <= v)) r = 0;
            } else {
                if (!(v <= *(f32*)(p + 40))) r = 0;
            }
        }
    }
    return r;
}
}  // namespace n0018c490

// ---- 0018c528 from src/anon/batch_w1744.cpp
namespace n0018c528 {
s32 func_0018c528(u32 a) asm("func_0018c528");
s32 func_0018c528(u32 a) {
    s32 r = 0;
    switch (a) {
    case 2: r = 287; break;
    case 0: case 1: r = 0; break;
    case 3: break;
    case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13:
        r = a + 279; break;
    }
    return r;
}
}  // namespace n0018c528

// ---- 0018c570 from src/anon/tiny_auto80_queue.cpp
namespace n0018c570 {
extern f32 D_00349e10 asm("D_00349e10");
void func_0018c570(u32 a0) asm("_Z13func_0018c570j");
void func_0018c570(u32 a0) {
    f32 f1 = *(f32*)((u32)a0 + (s32)(80));
    if (0.0f < f1) {
        f32 f0 = *(f32*)((u32)&D_00349e10 + (s32)(0));
        f0 = (f32)(f1 - f0);
        *(f32*)((u32)a0 + (s32)(80)) = f0;
    }
}
}  // namespace n0018c570

// ---- 0018c598 from src/anon/batch_w1791.cpp
namespace n0018c598 {
struct Uc4Tgt { u8 pad[0x154]; s32 state; u8 pad2[0xa4c - 0x158]; u32 id; };
struct Uc4 { s32 kind; u8 pad4[8]; Uc4Tgt* tgt; u8 pad10[0x20]; u8 on; u8 pad31[0x1f]; f32 time; };
s32 func_0018bd50(u32, s32) asm("func_0018bd50");
s32 func_0019ba60(Uc4Tgt*) asm("func_0019ba60");
u32 u_call4_0018c598(u32 a, u32 b, u32 c, u32 d) asm("_Z16u_call4_0018c598jjjj");
u32 u_call4_0018c598(u32 a, u32 b, u32 c, u32 d) {
    Uc4* u = (Uc4*)a;
    if (!u->on) return 1;
    if (u->time <= 0.0f) return 1;
    if (u->kind == 4 && !func_0018bd50(b, 5)) return 1;
    if (u->kind == 5 && (!func_0019ba60(u->tgt) || u->tgt->id != b || u->tgt->state == 50)) return 1;
    return 0;
}
}  // namespace n0018c598

// ---- 0018c650 from src/anon/batch_w318.cpp
namespace n0018c650 {
#define QCOPY318(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
struct Q318 {
    union { u32 v[4]; f32 f[4]; };
    Q318() {}
    Q318(f32 x, f32 y, f32 z, f32 w) { f[0] = x; f[1] = y; f[2] = z; f[3] = w; }
    Q318(const Q318& o) { QCOPY318(this, &o); }
    Q318& operator=(const Q318& o) {
        if (this != &o) QCOPY318(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct E318c { u8 b0, b1, b2, b3; union { f32 x; s32 ix; }; f32 y, z; };
struct H318 { u16 h0, h2; };
struct O318 { u8 pad[108]; H318* h; };
struct R318c { s32 a; s32 b; s32 c; s32 d; Q318 q; O318* obj; u8 b36; u8 pad[3]; f32 f40; f32 f44; u8 pad2[32]; f32 f80; };
u32 func_001064a8(int) asm("func_001064a8");
void func_0018c438(R318c*) asm("func_0018c438");
int func_0018c528(int) asm("func_0018c528");
int func_0016b740(s32) asm("func_0016b740");
f32 func_00106558(f32) asm("func_00106558");
f32 func_001db510(O318*, Q318) asm("func_001db510");
f32 func_001065a8(f32, f32) asm("func_001065a8");
int func_0018c650(R318c* o, Q318* v, int n, E318c* tab, O318* obj, f32 fa, f32 fb) asm("func_0018c650");
int func_0018c650(R318c* o, Q318* v, int n, E318c* tab, O318* obj, f32 fa, f32 fb) {
    E318c* sel = 0;
    int acc = 0;
    E318c* sp5 = 0;
    int r = (int)func_001064a8(100);                        
    for (int i = 0; i < n; i++) {
        if (tab[i].b0 == obj->h->h2) {
            if (tab[i].b1 == 3) sp5 = &tab[i];
            else {
                int w = tab[i].b2;
                if (r >= acc && r < acc + w) sel = &tab[i];
                acc += w;
            }
        }
    }
    if (sel) {
    func_0018c438(o);
    o->a = sel->b1 == 1 ? 6 : 2;
    o->c = func_0018c528(sel->b1);
    switch (sel->b3) {
    case 1:
        o->b = 1;
        o->d = func_0016b740(sel->ix);
        break;
    case 2:
        o->b = 2;
        break;
    case 3: {
        o->b = 3;
        o->q = Q318(sel->x, sel->y, sel->z, 0.0f);
        break;
    }
    case 0:
    default:
        o->b = 0;
    }
    o->b36 = 0;
    if (sp5 && func_001064a8(100) < sp5->b2) o->b36 = 1;
    o->obj = obj;
    o->f40 = func_00106558(1.0f);
    o->f44 = func_001db510(o->obj, *v);
    o->f80 = func_001065a8(fa, fb);
    return 1;
    }
    return 0;
}
}  // namespace n0018c650

// ---- 0018c868 from src/anon/batch_wcx2.cpp
namespace n0018c868 {
extern f32 D_01c60be8 asm("D_01c60be8");
void wtarget_0018c868(u32, u32, u32, u32) asm("_Z16wtarget_0018c868jjjj");
void wtarget_0018c868(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) D_01c60be8 = 0.34906584f;
}
}  // namespace n0018c868

// ---- 0018c898 from src/anon/tiny_wrappers_more.cpp
namespace n0018c898 {
u32 func_0018c868(u32, u32, u32, u32) asm("_Z13func_0018c868jjjj");
u32 func_0018c898(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0018c898jjjj");
u32 func_0018c898(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0018c868(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n0018c898
