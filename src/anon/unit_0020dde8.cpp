// Linked unit 0x0020dde8-0x0020e2e8 (after whole-asm 0x20d528): VU1/GS packet helpers and texture upload callers.
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned int w3728_u128 __attribute__((mode(TI)));
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 0020dde8 (was src/anon/tiny_jal_tail_wrappers.cpp)
namespace n0020dde8 {
u32 func_0020de08() asm("_Z13func_0020de08v");
u32 func_0020eac0() asm("_Z13func_0020eac0v");
/*TARGET 0020dde8*/
// 0x001dcd68: definition moved into src/anon/unit_001dbfd8.cpp

u32 func_0020dde8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0020dde8jjjj");
// 0x001dcd68: definition moved into src/anon/unit_001dbfd8.cpp

u32 func_0020dde8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_0020de08();
    return func_0020eac0();
}
}  // namespace n0020dde8

// 0020de08 (was src/anon/tiny_jal_wrappers.cpp)
namespace n0020de08 {
u32 func_002f35e8(u32, u32, u32, u32) asm("_Z13func_002f35e8jjjj");
/*TARGET 0020de08*/
// 0x001d76c8: definition moved into src/anon/unit_001d7458.cpp

u32 func_0020de08(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0020de08jjjj");
// 0x001d76c8: definition moved into src/anon/unit_001d7458.cpp

u32 func_0020de08(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r4 = (u32)((s32)0u + (2));
    r2 = func_002f35e8(r4, r5, r6, r7);
    r15 = (u32)(0x0036u << 16);
    *(u32*)((u32)r15 + (s32)(-28216)) = r2;
    return r2;
}
}  // namespace n0020de08

// 0020de30 (was src/anon/batch_w1877_nsa.cpp)
namespace n0020de30 {
// GS register packets: GIF tag (A+D, 7 regs) then data/address pairs.
struct GsPkt1877 {
    u64 dma[2];
    u64 tag0, tag1;
    u64 frame, frameAddr;
    u64 zbuf, zbufAddr;
    u64 test, testAddr;
    u64 r50, r58;
    u64 texa, texaAddr;
    u64 clamp, clampAddr;
    u64 fogcol, fogcolAddr;
};
extern GsPkt1877 D_01da8bb0 asm("D_01da8bb0");
extern GsPkt1877 D_01da8c40 asm("D_01da8c40");
extern u64 D_00352c00 asm("D_00352c00");
extern u32 D_00352bf4 asm("D_00352bf4");
// Transform the 8 box corners in place and compute their min/max.
// 001605a0: moved to src/harata/libdk/bgobj.cpp

void u_call0_0020de30() asm("_Z16u_call0_0020de30v");
/*TARGET 0020de30*/
void u_call0_0020de30() asm("_Z16u_call0_0020de30v");
void u_call0_0020de30() {
    GsPkt1877* p = &D_01da8bb0;
    p->tag0 = (7ULL << 60) | 0x8001;
    p->tag1 = 0xeeeeeee;
    p->frame = D_00352c00;
    p->frameAddr = 0x4c;
    p->zbuf = (u64)(s32)(D_00352bf4 | 0x31000000) | (1ULL << 32);
    p->zbufAddr = 0x4e;
    p->test = 0x7000d;
    p->testAddr = 0x47;
    p->r50 = 0x21;
    p->r58 = 0x14;
    p->clamp = 0;
    p->clampAddr = 8;
    p->texa = 1ULL << 39;
    p->texaAddr = 0x3b;
    p->fogcol = 0x808080;
    p->fogcolAddr = 0x3d;
    p = &D_01da8c40;
    p->tag0 = (7ULL << 60) | 0x8001;
    p->tag1 = 0xeeeeeee;
    p->frame = D_00352c00;
    p->frameAddr = 0x4c;
    p->zbuf = (u64)(s32)(D_00352bf4 | 0x31000000);
    p->zbufAddr = 0x4e;
    p->test = 0x7000d;
    p->testAddr = 0x47;
    p->r50 = 0x21;
    p->r58 = 0x14;
    p->clamp = 0;
    p->clampAddr = 8;
    p->texa = 1ULL << 39;
    p->texaAddr = 0x3b;
    p->fogcol = 0x808080;
    p->fogcolAddr = 0x3d;
}
}  // namespace n0020de30

// 0020df70 (was src/anon/batch_w3728.cpp)
namespace n0020df70 {
struct W3728_Tag { union { w3728_u128 q; struct { u32 x0; W3728_Tag* x4; W3728_Tag* x8; u32 xc; } w; }; };
extern W3728_Tag D_01dac450[289] asm("D_01dac450");
extern u8 D_01da8c40[] asm("D_01da8c40");
struct W3728_NoTail { ~W3728_NoTail() {} };
void func_0020e7a8(void*, s32, s32, s32) asm("func_0020e7a8");
void func_0020e800(void*, s32, s32, s32) asm("func_0020e800");
/*TARGET 0020df70*/
void u_call0_0020df70() asm("_Z16u_call0_0020df70v");
void u_call0_0020df70() {
    W3728_NoTail nt;
    register w3728_u128 v asm("$13") = 0x20000000;   // t5: the tag quadword
    W3728_Tag* p = D_01dac450;
    register s32 i asm("$12");                      // t4: loop counter
    for (i = 287; i >= 0; i--) {
        p->q = v;
        p->w.x4 = p + 1;
        p->w.x8 = p;
        asm volatile("");                           // keeps the decrement after the stores
        p++;
    }
    p->q = v;
    // the original issues lui a0 before the store and addiu a0 right after it
    register u8* a asm("$4");
    asm("lui %0,%%hi(D_01da8bb0)" : "=r"(a));
    p->w.x0 = 0x70000000;
    asm volatile("addiu %0,%0,%%lo(D_01da8bb0)" : "+r"(a));
    func_0020e7a8(a, 9, 0, 0);
    func_0020e800(D_01da8c40, 9, 15, 0);
}
}  // namespace n0020df70

// 0020dff0 (was src/anon/batch_w1785.cpp)
namespace n0020dff0 {
// 00109ea8: moved to src/anon/unit_00109c30.cpp

void sceGsSyncPath(s32, s32) asm("sceGsSyncPath");
void func_003058a0(s32) asm("func_003058a0");
void func_002f3918(void*, void*) asm("func_002f3918");
struct Pkt20 { u128 tag; u8 pad[112]; u64 rgb; u64 reg; };
extern Pkt20 D_01da8c40 asm("D_01da8c40");
extern u8 D_00359150[] asm("D_00359150");
extern void* D_003591c8 asm("D_003591c8");
/*TARGET 0020dff0*/
void func_0020dff0(void*) asm("_Z13func_0020dff0Pv");
void func_0020dff0(void*)
{
    u128 save = D_01da8c40.tag;
    D_01da8c40.tag = 0x70000008;
    D_01da8c40.rgb = D_00359150[0] | ((u64)D_00359150[1] << 8) | ((u64)D_00359150[2] << 16);
    D_01da8c40.reg = 61;
    sceGsSyncPath(0, 0);
    func_003058a0(0);
    func_002f3918(D_003591c8, &D_01da8c40);
    sceGsSyncPath(0, 0);
    D_01da8c40.tag = save;
}
}  // namespace n0020dff0

// 0020e0a0 (was src/anon/batch_w1772_nsa.cpp)
namespace n0020e0a0 {
void sceGsSyncPath(s32, s32) asm("sceGsSyncPath");
void FlushCache(s32) asm("FlushCache");
void func_002f3918(s32, void*) asm("func_002f3918");
extern s32 D_003591c8 asm("D_003591c8");
extern u64 D_01da8c40[] asm("D_01da8c40");
// GIF packet: 128-bit tag, GIFtag (NLOOP=1, EOP, NREG=2, REGS=A+D,A+D), two A+D pairs.
struct Pkt_w1772 { u128 tag; u64 a; u64 b; u64 c[4]; };
/*TARGET 0020e0a0*/
void func_0020e0a0(void) asm("func_0020e0a0");
void func_0020e0a0(void) {
    Pkt_w1772 k;
    k.tag = 0x70000003;
    u64* p = &k.a;
    u64* s = D_01da8c40;
    p[0] = 0x2000000000008001ULL;
    p[1] = 0xee;
    p[2] = s[8];
    p[3] = s[9];
    p[4] = s[6];
    p[5] = s[7];
    sceGsSyncPath(0, 0);
    FlushCache(0);
    func_002f3918(D_003591c8, &k);
    sceGsSyncPath(0, 0);
}
}  // namespace n0020e0a0

// 0020e138 (was src/anon/batch_w6.cpp)
namespace n0020e138 {
u32 func_002fea18(void) asm("func_002fea18");
/*TARGET 0020e138*/
// Seed the VU0 random generator.
void func_0020e138(void) asm("func_0020e138");
// Seed the VU0 random generator.
void func_0020e138(void) {
    register u32 s asm("$15") = func_002fea18();
    asm volatile("qmtc2 %0, $vf31\n\tvrxor R, $vf31x" : : "r"(s));
}
}  // namespace n0020e138

// 0020e160 (was gap)
namespace n0020e160 {
// Number of doublings of 1 needed to reach n (ceil log2).
s32 func_0020e160(s32 n) asm("func_0020e160");
s32 func_0020e160(s32 n) {
    s32 i = 1;
    s32 r = 0;
    while (i < n) { i <<= 1; r++; }
    return r;
}
}  // namespace n0020e160

// 0020e198 (was src/anon/batch_w3725.cpp)
namespace n0020e198 {
// func_0020e198: empty asm keeps the shifted value live so the srl is not tied to a1; see asm_review.tsv.
struct B1882 { u8 b[96]; };
struct BF4 { u32 :6; u32 f:26; };
struct BF28 { u32 :5; u32 f:14; u32 :13; };
struct T1882 {
    u8 p0[4]; union { u32 w4; BF4 bf4; }; u32 w8; u8 p12[6]; u8 b18; u8 b19; u16 h20; s16 h22; u16 h24; u8 p26[2]; union { u32 w28; BF28 bf28; }; u8 p32[8]; u8 b40; u8 b41; u8 b42; u8 b43;
};
struct O1882 { u8 p0[15]; u8 b15; T1882 t; };
extern u8 D_00359100[] asm("D_00359100");
void sceGsSetDefLoadImage(B1882*, s32, s32, u8, s32, s32, s32, s32) asm("sceGsSetDefLoadImage");
void sceGsSyncPath(s32, s32) asm("sceGsSyncPath");
void func_003058a0(s32) asm("func_003058a0");
void sceGsExecLoadImage(B1882*, u8*) asm("sceGsExecLoadImage");
/*TARGET 0020e198*/
void func_0020e198(O1882* o) asm("func_0020e198");
void func_0020e198(O1882* o) {
    T1882* t = &o->t;
    u8* p = 0;
    B1882 a, b;
    if (t->w8) {
        u8 a3 = D_00359100[t->b19];
        s16 a1 = t->h24 & 0x3fff;
        s32 a2, t0, t1;
        if (o->b15 == 111) {
            a2 = t->b40 >> 2; t0 = t->b42 << 4; t1 = t->b43 << 4;
        } else {
            a2 = t->h20 >> 6; t0 = 0; t1 = 0;
        }
        sceGsSetDefLoadImage(&a, a1, a2, a3, t0, t1, (s16)t->h20, t->h22);
        sceGsSyncPath(0, 0);
        func_003058a0(0);
        sceGsExecLoadImage(&a, p = (u8*)t + 48);
    }
    if (t->w4) {
        u8 i3 = t->b18;
        u32 w = t->w28 >> 5;
        u8 c3 = D_00359100[i3];
        u32 c1 = w & 0x3fff;
        s16 c3x = t->bf4.f;
        asm("" : "+r"(c1) : "r"(w));
        sceGsSetDefLoadImage(&b, c1, 1, c3, 0, 0, 16, c3x);
        sceGsSyncPath(0, 0);
        func_003058a0(0);
        p += t->w8;
        sceGsExecLoadImage(&b, p);
    }
}
}  // namespace n0020e198

