// Linked unit 0x00133cf0-0x001345c0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"

// 00133cf0 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00133cf0 {
u32 func_00133598(u32, u32, u32, u32) asm("_Z13func_00133598jjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 00133cf0*/
// 0x00113688: definition moved into src/anon/unit_00113628.cpp

u32 func_00133cf0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133cf0jjjj");
// 0x00113688: definition moved into src/anon/unit_00113628.cpp

u32 func_00133cf0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133598((u32)&D_00347c88, a0, a1, a3);
}
}  // namespace n00133cf0

// 00133d18 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00133d18 {
u32 func_00133630(u32, u32, u32, u32) asm("_Z13func_00133630jjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 00133d18*/
u32 func_00133d18(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133d18jjjj");
u32 func_00133d18(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133630((u32)&D_00347c88, a1, a2, a3);
}
}  // namespace n00133d18

// 00133d38 (was src/anon/batch_w1784_g.cpp)
namespace n00133d38 {
u32* ctarget_002f35e8_w1784(u32) asm("_Z13func_002f35e8j");
// absolute alias: the C definition in sdk_w507.c links elsewhere
void FlushCache(s32) asm("FlushCache");
/*TARGET 00133d38*/
u32* func_00133d38(void) asm("func_00133d38");
u32* func_00133d38(void) {
    *(volatile u32*)0x1000e010 = 6;
    *(volatile u32*)0x1000e020 = 2;
    *(volatile u32*)0x10003c20 = 6;
    *(volatile u32*)0x10009010 = 0;
    *(volatile u32*)0x10009020 = 0;
    *(volatile u32*)0x10009030 = 0;
    *(volatile u32*)0x10009040 = 0;
    *(volatile u32*)0x10009050 = 0;
    u32* p = ctarget_002f35e8_w1784(1);
    *p = 0x45;
    FlushCache(0);
    asm volatile("sync.p");
    return p;
}
}  // namespace n00133d38

// 00133de8 (was src/anon/auto80_199_queue.cpp)
namespace n00133de8 {
/*TARGET 00133de8*/
void func_00133de8(void) asm("_Z13func_00133de8v");
void func_00133de8(void) {
    sceGsSyncPath(0, 0);
    func_00133d18();

    u32 v0 = func_00133d38();
    D_00347cac = v0;

    func_002f3918(v0, (u32)&D_0032a780);
    func_00134030();  // poll_timer_status

    D_00347cb4 = 0;
    D_00347cb0 = 0xFFFFFFFF;
}
}  // namespace n00133de8

// 00133e50 (was src/anon/auto80_199_queue.cpp)
namespace n00133e50 {
/*TARGET 00133e50*/
void func_00133e50(void) asm("_Z13func_00133e50v");
void func_00133e50(void) {
    u32 s0 = (u32)&D_00347c88;

    func_00133c60(s0, (u32)&D_0032a870, 0, 0, 0);  // forward_sub24_to_133980
    func_00133be8(s0, 0, 0, 0);  // forward_sub24_to_1338e8
    func_00133768(s0);
}
}  // namespace n00133e50

// 00133ea8 (was src/anon/auto80_199_queue.cpp)
namespace n00133ea8 {
/*TARGET 00133ea8*/
void func_00133ea8(void) asm("_Z13func_00133ea8v");
void func_00133ea8(void) {
    u32 s0 = (u32)&D_00347c88;

    func_00133c60(s0, (u32)&D_0032a870, 0, 0, 0);  // forward_sub24_to_133980
    func_00133be8(s0, 0, 0, 0);  // forward_sub24_to_1338e8
    func_00133690(s0);
    func_00133c60(s0, (u32)&D_0032a850, 0, 0, 0);  // forward_sub24_to_133980
}
}  // namespace n00133ea8

// 00133f20 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00133f20 {
u32 func_001336d8(u32, u32, u32, u32) asm("_Z13func_001336d8jjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 00133f20*/
u32 func_00133f20(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133f20jjjj");
u32 func_00133f20(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001336d8((u32)&D_00347c88, a1, a2, a3);
}
}  // namespace n00133f20

// 00133f40 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00133f40 {
u32 func_001336e8(u32, u32, u32, u32) asm("_Z13func_001336e8jjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 00133f40*/
u32 func_00133f40(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133f40jjjj");
u32 func_00133f40(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001336e8((u32)&D_00347c88, a1, a2, a3);
}
}  // namespace n00133f40

// 00133f60 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00133f60 {
u32 func_00133720(u32, u32, u32, u32) asm("_Z13func_00133720jjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 00133f60*/
u32 func_00133f60(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133f60jjjj");
u32 func_00133f60(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133720((u32)&D_00347c88, a1, a2, a3);
}
}  // namespace n00133f60

// 00133f80 (was src/anon/batch_w1774_g.cpp)
namespace n00133f80 {
void sceGsSyncPath(s32, s32) asm("sceGsSyncPath");
s32 func_00133d38(void) asm("func_00133d38");
void func_003058a0(s32) asm("func_003058a0");
s32 func_00133f60(void) asm("func_00133f60");
u32 func_001336f8(void*) asm("func_001336f8");
void func_002f3918(s32, u32) asm("func_002f3918");
extern s32 D_00347cac asm("D_00347cac");
extern volatile u8 D_00347cb4 asm("D_00347cb4");
extern u8 D_00347c88[] asm("D_00347c88");
/*TARGET 00133f80*/
/* sync.p is the EE pipeline barrier; gcc has no C form for it. */
s32 func_00133f80(void) asm("func_00133f80");
/* sync.p is the EE pipeline barrier; gcc has no C form for it. */
s32 func_00133f80(void) {
    sceGsSyncPath(0, 0);
    D_00347cac = func_00133d38();
    *(volatile u32*)0x10003010 = 1;
    asm volatile("sync.p");
    func_003058a0(0);
    D_00347cb4 = 1;
    s32 r = func_00133f60();
    asm volatile("sync.p");
    func_002f3918(D_00347cac, func_001336f8(D_00347c88) & 0xcfffffff);
    asm volatile("sync.p");
    return r;
}
}  // namespace n00133f80

// 00134020 (was src/anon/tiny_auto80.cpp)
namespace n00134020 {
/*TARGET 00134020*/
u32 func_00134020(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00134020jjjj");
u32 func_00134020(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)(0x0034u << 16);
    r2 = (u32)(*(volatile u8*)((u32)r15 + (s32)(31924)));
    r2 = (u32)(r2 & 0x00ffu);
    return r2;
}
}  // namespace n00134020

// 00134030 (was src/anon/batch_w68.cpp)
namespace n00134030 {
/*TARGET 00134030*/
/* ---- 00134030: wait for VIF1 / GIF / VU0 / IPU idle ---- */
s32 func_00134030(void) asm("func_00134030");
/* ---- 00134030: wait for VIF1 / GIF / VU0 / IPU idle ---- */
s32 func_00134030(void) {  // poll_timer_status
    if (*(volatile u32*)0x10009000 & 0x100) {
        // spin on COP0 condition (hand-written padding)
        asm volatile("1:\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tbc0f 1b\n\tnop");
    }
    while (*(volatile u32*)0x10003c00 & 0x1f000003) ;
    {
        u32 s;
        do { asm volatile("cfc2 %0, $vi29" : "=r"(s)); } while (s & 0x100);
    }
    while (*(volatile u32*)0x10003020 & 0xc00) ;
    return 0;
}
}  // namespace n00134030

// 001340e8 (was src/anon/batch_w44.cpp)
namespace n001340e8 {
extern "C" {
s32 func_001341e8(void*);
s32 func_00134020(void);
void func_00134030(void);
}
extern volatile u8 D_00347cb4 asm("D_00347cb4");
void f1340e8(void*) asm("_Z13func_001340e8Pv");
void f1340e8(void* p) {
    if (func_001341e8(p) >= 0) {
        while (func_00134020()) func_00134030();
    } else {
        func_00134030();  // poll_timer_status
        D_00347cb4 = 0;
    }
    *(volatile u32*)0x10003010 = 0;  // GIF_MODE
}
}  // namespace n001340e8
// 00134150 (was unwritten gap)
namespace n00134150 {
extern "C" {
s32 func_003061d0(s32);
s32 func_00305330(s32, s32 (*)(s32), s32);
s32 func_00306238(s32);
s32 func_00305350(s32, s32);
}
extern s32 D_00347cb0 asm("D_00347cb0");
extern volatile u8 D_00347cb4 asm("D_00347cb4");
s32 func_001341f8(s32) asm("func_001341f8");
void func_00134150(void) asm("func_00134150");
void func_00134150(void) {
    func_003061d0(1);
    *(volatile u32*)0x1000e010 = 2;
    D_00347cb0 = func_00305330(1, func_001341f8, -1);
    func_00306238(1);
}
void func_001341a0(void) asm("func_001341a0");
void func_001341a0(void) {
    func_003061d0(1);
    if (D_00347cb0 >= 0) func_00305350(1, D_00347cb0);
    D_00347cb0 = -1;
}
}  // namespace

// 001341e8 (was src/anon/tiny.cpp)
namespace n001341e8 {
/*TARGET 001341e8*/
u32 func_001341e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001341e8jjjj");
u32 func_001341e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0034u << 16);
    return (u32)(*(u32*)((u32)b + (31920)));
}
}  // namespace n001341e8

// 001341f8 (was unwritten gap)
namespace n001341f8 {
extern volatile u8 D_00347cb4 asm("D_00347cb4");
s32 func_001341f8(s32) asm("func_001341f8");
s32 func_001341f8(s32) {
    volatile u32* chcr = (volatile u32*)0x10009000;
    u32 t = (*chcr >> 28) & 7;
    if (t != 0 && t != 7) {
        *(volatile u32*)0x1000e010 = 2;
        *chcr |= 0x100;
    } else {
        D_00347cb4 = 0;
    }
    asm volatile("sync.l\n\tei");
    return 0;
}
}  // namespace

// 00134258 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00134258 {
u32 func_00133718(u32, u32, u32, u32) asm("_Z13func_00133718jjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 00134258*/
u32 func_00134258(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00134258jjjj");
u32 func_00134258(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133718((u32)&D_00347c88, a1, a2, a3);
}
}  // namespace n00134258

// 00134278 (was src/anon/batch_w1578_g.cpp)
namespace n00134278 {
s32 func_00134258(void) asm("func_00134258");
void func_00133f20(void) asm("func_00133f20");
/*TARGET 00134278*/
s32 func_00134278(void) asm("func_00134278");
s32 func_00134278(void) {
    s32 r = func_00134258();
    func_00133f20();
    return r;
}
}  // namespace n00134278

// 001342a8 (was src/anon/tiny_jal_tail_wrappers.cpp)
namespace n001342a8 {
u32 func_00133e50() asm("_Z13func_00133e50v");
u32 func_00133f40() asm("_Z13func_00133f40v");
/*TARGET 001342a8*/
u32 func_001342a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001342a8jjjj");
u32 func_001342a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_00133e50();
    return func_00133f40();
}
}  // namespace n001342a8

// 001342c8 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n001342c8 {
u32 func_00133b88(u32, u32, u32, u32) asm("_Z13func_00133b88jjjj");
// forward_sub24_to_133848
u32 func_001342c8(u32, u32, u32, u32) asm("_Z13func_001342c8jjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 001342c8*/
u32 func_001342c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001342c8jjjj");
u32 func_001342c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133b88((u32)&D_00347c88, a0, a1, a2);
}
}  // namespace n001342c8

// 001342f8 (was unwritten gap)
namespace n001342f8 {
extern u8 D_00347c88[] asm("D_00347c88");
void func_00133ba0(void*, u32, u32) asm("func_00133ba0");
void func_001342f8(u32 a, u32 b) asm("func_001342f8");
void func_001342f8(u32 a, u32 b) { func_00133ba0(D_00347c88, a, b); }
}  // namespace

// 00134320 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00134320 {
u32 func_00133bb8(u32, u32, u32, u32) asm("_Z13func_00133bb8jjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 00134320*/
u32 func_00134320(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00134320jjjj");
u32 func_00134320(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133bb8((u32)&D_00347c88, a0, 0x00000000u, 0x00000000u);  // forward_sub24_to_133848
}
}  // namespace n00134320

// 00134348 (was src/anon/tiny_auto80_solver.cpp)
namespace n00134348 {
// forward_sub24_to_133848
u32 func_00133c00(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00133c00jjjjjjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 00134348*/
u32 func_00134348(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00134348jjjjjjjj");
u32 func_00134348(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = r4;
    r6 = r5;
    r4 = (u32)&D_00347c88;
    r5 = r15;    r7 = 0u;
    r8 = 0u;
    return ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00133c00)(r4, r5, r6, r7, r8, r9, r10, r11);
}
}  // namespace n00134348

// 00134378 (was src/anon/tiny_auto80_solver.cpp)
namespace n00134378 {
u32 func_00133c18(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00133c18jjjjjjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 00134378*/
u32 func_00134378(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00134378jjjjjjjj");
u32 func_00134378(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = r4;
    r6 = r5;
    r4 = (u32)&D_00347c88;
    r5 = r15;    r7 = 0u;
    r8 = 0u;
    return ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00133c18)(r4, r5, r6, r7, r8, r9, r10, r11);
}
}  // namespace n00134378

// 001343a8 (was src/anon/tiny_auto80_solver.cpp)
namespace n001343a8 {
u32 func_00133c60(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00133c60jjjjjjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 001343a8*/
u32 func_001343a8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001343a8jjjjjjjj");
u32 func_001343a8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = r4;
    r6 = r5;
    r4 = (u32)&D_00347c88;
    r5 = r15;    r7 = 0u;
    r8 = 0u;
    return ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00133c60)(r4, r5, r6, r7, r8, r9, r10, r11);
}
}  // namespace n001343a8

// 001343d8 (was src/anon/tiny_auto80_solver.cpp)
namespace n001343d8 {
// forward_sub24_to_133980
u32 func_00133c78(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00133c78jjjjjjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 001343d8*/
u32 func_001343d8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001343d8jjjjjjjj");
u32 func_001343d8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = r4;
    r6 = r5;
    r4 = (u32)&D_00347c88;
    r5 = r15;    r7 = 0u;
    r8 = 0u;
    return ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00133c78)(r4, r5, r6, r7, r8, r9, r10, r11);
}
}  // namespace n001343d8

// 00134408 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00134408 {
u32 func_00133a18(u32, u32, u32, u32) asm("_Z13func_00133a18jjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 00134408*/
u32 func_00134408(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00134408jjjj");
u32 func_00134408(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133a18((u32)&D_00347c88, a1, a2, a3);
}
}  // namespace n00134408

// 00134428 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00134428 {
u32 func_00133ac8(u32, u32, u32, u32) asm("_Z13func_00133ac8jjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 00134428*/
u32 func_00134428(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00134428jjjj");
u32 func_00134428(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133ac8((u32)&D_00347c88, a0, a1, a3);
}
}  // namespace n00134428

// 00134450 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00134450 {
u32 func_00133ae8(u32, u32, u32, u32) asm("_Z13func_00133ae8jjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 00134450*/
u32 func_00134450(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00134450jjjj");
u32 func_00134450(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133ae8((u32)&D_00347c88, ((u32)(a0) & 0xffu), a2, a3);
}
}  // namespace n00134450

// 00134470 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00134470 {
u32 func_00133b78(u32, u32, u32, u32) asm("_Z13func_00133b78jjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 00134470*/
u32 func_00134470(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00134470jjjj");
u32 func_00134470(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133b78((u32)&D_00347c88, a1, a2, a3);
}
}  // namespace n00134470

// 00134490 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00134490 {
u32 func_00133bb8(u32, u32, u32, u32) asm("_Z13func_00133bb8jjjj");
extern u8 D_00347c88 asm("D_00347c88");
/*TARGET 00134490*/
u32 func_00134490(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00134490jjjj");
u32 func_00134490(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133bb8((u32)&D_00347c88, 0x00000000u, 0x11000000u, 0x13000000u);  // forward_sub24_to_133848
}
}  // namespace n00134490

// 001344b8 (was src/anon/batch_w18.cpp)
namespace n001344b8 {
// 0x001153e8: definition moved into src/anon/unit_00114a90.cpp

extern u8 D_00347c88[] asm("D_00347c88");
void func_00133bb8(void*, u32, u32, u32) asm("func_00133bb8");
/*TARGET 001344b8*/
// forward_sub24_to_133848
void func_001344b8(u32 a) asm("func_001344b8");
// forward_sub24_to_133848
void func_001344b8(u32 a) {
    func_00133bb8(D_00347c88, 0, a | 0x3000000, ((1024 - a) >> 1) | 0x2000000);  // forward_sub24_to_133848
}
}  // namespace n001344b8

// 001344f8 (was src/anon/tiny.cpp)
namespace n001344f8 {
extern u32 D_00347c88 asm("D_00347c88");
/*TARGET 001344f8*/
u32 func_001344f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001344f8jjjj");
u32 func_001344f8(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_data_347c88
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_00347c88;
}
}  // namespace n001344f8

// 00134508 (was src/anon/batch_w47.cpp)
namespace n00134508 {
void func_00134508(s32, s32) asm("_Z13func_00134508ii");
// 001044f0: moved to src/common/gumimenu.cpp

extern u8 D_00347c88[] asm("D_00347c88");
void func_00133570(void*) asm("func_00133570");
void func_00133590(void*) asm("func_00133590");
/*TARGET 00134508*/
void func_00134508(s32 a, s32 b) asm("_Z13func_00134508ii");
void func_00134508(s32 a, s32 b) {
    if (b == 0xffff && a == 1) func_00133570(D_00347c88);
    if (b == 0xffff && a == 0) func_00133590(D_00347c88);
}
}  // namespace n00134508

// 00134580 (was src/anon/tiny.cpp)
namespace n00134580 {
void func_00134508(s32, s32) asm("_Z13func_00134508ii");
/*TARGET 00134580*/
void func_00134580(BD_VALUE* bd) asm("_Z13func_00134580P8BD_VALUE");
void func_00134580(BD_VALUE* bd) { func_00134508(1, 0xffff); }
}  // namespace n00134580

// 001345a0 (was unwritten gap)
namespace n001345a0 {
void func_00134508(s32, s32) asm("_Z13func_00134508ii");
void func_001345a0(void) asm("func_001345a0");
void func_001345a0(void) { func_00134508(0, 0xffff); }
}  // namespace

