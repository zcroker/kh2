// Linked unit 0x0031b9e0: linkonce (template) copies of game code that the linker gathered after the
// toolchain libraries. One namespace per old matched source.
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../global/misc.hpp"


// 0031b9e0 (was src/anon/batch_w63.cpp)
namespace n0031b9e0 {
// 001837c0: moved to src/anon/unit_00183088.cpp

// Moves pos a fifth of the way towards vel, with gravity on y; returns pos.y < 0.
// 001cc888: moved to src/anon/unit_001cc868.cpp

struct F112 { u32 b0 : 1; u32 b1 : 2; u32 b3 : 4; u32 rest : 25; };
struct F116 { u32 c0 : 1; u32 c1 : 1; u32 c2 : 1; u32 rest : 29; };
/*TARGET 0031b9e0*/
// Resets state flags and clears six vectors to (0,0,0,1) with VU0 vf0.
void func_0031b9e0(u8* p) asm("func_0031b9e0");
// Resets state flags and clears six vectors to (0,0,0,1) with VU0 vf0.
void func_0031b9e0(u8* p) {
    F112* a = (F112*)(p + 112);
    F116* b = (F116*)(p + 116);
    *(u32*)(p + 104) = 0;
    *(u32*)(p + 108) = 0;
    *(u32*)(p + 120) = 0;
    *(u32*)(p + 124) = 0;
    *(u32*)(p + 128) = 0;
    a->b0 = 0;
    a->b1 = 2;
    a->b3 = 6;
    *(s16*)(p + 96) = -1;
    *(s16*)(p + 98) = -1;
    *(s16*)(p + 100) = -1;
    b->c0 = 0;
    b->c1 = 1;
    b->c2 = 0;
    asm volatile(".set noreorder\n\tsqc2 $vf0, 0(%0)\n\tsqc2 $vf0, 0(%1)\n\tsqc2 $vf0, 0(%2)\n\tsqc2 $vf0, 0(%3)\n\tsqc2 $vf0, 0(%4)\n\tsqc2 $vf0, 0(%5)\n\t.set reorder"
        : : "r"(p), "r"(p + 16), "r"(p + 32), "r"(p + 48), "r"(p + 64), "r"(p + 80) : "memory");
}
}  // namespace n0031b9e0

// 0031ba78 (gap; copy of 0x0031b910, was src/anon/tiny.cpp)
namespace n0031ba78 {
extern u32 D_00348d58 asm("D_00348d58");
/*TARGET 0031ba78*/
void func_0031ba78(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031ba78");
void func_0031ba78(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8_d
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00348d58;
}
}  // namespace n0031ba78

// 0031ba88 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n0031ba88 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_00348d58 asm("D_00348d58");
/*TARGET 0031ba88*/
u32 func_0031ba88(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0031ba88jjjjjjjj");
u32 func_0031ba88(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348d58;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n0031ba88

// 0031baa8 (was src/anon/tiny.cpp)
namespace n0031baa8 {
extern u32 D_00348698 asm("D_00348698");
/*TARGET 0031baa8*/
void func_0031baa8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031baa8jjjj");
void func_0031baa8(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8_b
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00348698;
}
}  // namespace n0031baa8

// 0031bab8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0031bab8 {
// set_vtbl_367910
u32 func_0031baa8(u32, u32, u32, u32) asm("_Z13func_0031baa8jjjj");
extern u8 D_00349d90 asm("D_00349d90");
/*TARGET 0031bab8*/
u32 func_0031bab8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031bab8jjjj");
u32 func_0031bab8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00349d90;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0031baa8)(u32, u32, u32, u32) = func_0031baa8;
    r2 = fp_call4_0031baa8(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0031bab8

// 0031bae0 (was src/anon/batch_w10.cpp)
namespace n0031bae0 {
/*TARGET 0031bae0*/
// 64-byte (4 quadword) copy.
void func_0031bae0(void* d, void* s) asm("func_0031bae0");
// 64-byte (4 quadword) copy.
void func_0031bae0(void* d, void* s) {  // memcpy64
    asm volatile(
        ".set noreorder\n\t"
        "lq $8, 0(%1)\n\t"
        "lq $9, 16(%1)\n\t"
        "lq $10, 32(%1)\n\t"
        "lq $11, 48(%1)\n\t"
        "sq $8, 0(%0)\n\t"
        "sq $9, 16(%0)\n\t"
        "sq $10, 32(%0)\n\t"
        "sq $11, 48(%0)\n\t"
        ".set reorder"
        : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
}  // namespace n0031bae0

// 0031bb08 (was src/anon/tiny.cpp)
namespace n0031bb08 {
extern u32 D_00348698 asm("D_00348698");
/*TARGET 0031bb08*/
void func_0031bb08(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031bb08jjjj");
void func_0031bb08(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00348698;
}
}  // namespace n0031bb08

// 0031bb18 (gap; copy of 0x0031b910, was src/anon/tiny.cpp)
namespace n0031bb18 {
extern u32 D_00348698 asm("D_00348698");
/*TARGET 0031bb18*/
void func_0031bb18(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031bb18");
void func_0031bb18(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8_d
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00348698;
}
}  // namespace n0031bb18

// 0031bb28 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n0031bb28 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_00348698 asm("D_00348698");
/*TARGET 0031bb28*/
u32 func_0031bb28(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0031bb28jjjjjjjj");
u32 func_0031bb28(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n0031bb28

// 0031bb48 (gap; copy of 0x0031b910, was src/anon/tiny.cpp)
namespace n0031bb48 {
extern u32 D_00348698 asm("D_00348698");
/*TARGET 0031bb48*/
void func_0031bb48(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031bb48");
void func_0031bb48(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8_d
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00348698;
}
}  // namespace n0031bb48

// 0031bb58 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n0031bb58 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_00348698 asm("D_00348698");
/*TARGET 0031bb58*/
u32 func_0031bb58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0031bb58jjjjjjjj");
u32 func_0031bb58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n0031bb58

// 0031bb78 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n0031bb78 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_00348698 asm("D_00348698");
/*TARGET 0031bb78*/
u32 func_0031bb78(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0031bb78jjjjjjjj");
u32 func_0031bb78(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n0031bb78

// 0031bb98 (gap; copy of 0x0031b910, was src/anon/tiny.cpp)
namespace n0031bb98 {
extern u32 D_00348698 asm("D_00348698");
/*TARGET 0031bb98*/
void func_0031bb98(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031bb98");
void func_0031bb98(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8_d
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00348698;
}
}  // namespace n0031bb98

// 0031bba8 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n0031bba8 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_00348698 asm("D_00348698");
/*TARGET 0031bba8*/
u32 func_0031bba8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0031bba8jjjjjjjj");
u32 func_0031bba8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n0031bba8

// 0031bbc8 (was src/anon/tiny.cpp)
namespace n0031bbc8 {
extern u32 D_00348698 asm("D_00348698");
/*TARGET 0031bbc8*/
void func_0031bbc8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031bbc8jjjj");
void func_0031bbc8(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_348c08_b
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00348698;
}
}  // namespace n0031bbc8

// 0031bbd8 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n0031bbd8 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_00348698 asm("D_00348698");
/*TARGET 0031bbd8*/
u32 func_0031bbd8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0031bbd8jjjjjjjj");
u32 func_0031bbd8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n0031bbd8

// 0031bbf8 (gap; copy of 0x0031b910, was src/anon/tiny.cpp)
namespace n0031bbf8 {
extern u32 D_00348698 asm("D_00348698");
/*TARGET 0031bbf8*/
void func_0031bbf8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031bbf8");
void func_0031bbf8(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8_d
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00348698;
}
}  // namespace n0031bbf8

// 0031bc08 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n0031bc08 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_00348698 asm("D_00348698");
/*TARGET 0031bc08*/
u32 func_0031bc08(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0031bc08jjjjjjjj");
u32 func_0031bc08(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n0031bc08

// 0031bc28 (gap; copy of 0x0031b910, was src/anon/tiny.cpp)
namespace n0031bc28 {
extern u32 D_00348698 asm("D_00348698");
/*TARGET 0031bc28*/
void func_0031bc28(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031bc28");
void func_0031bc28(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8_d
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00348698;
}
}  // namespace n0031bc28

// 0031bc38 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n0031bc38 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_00348698 asm("D_00348698");
/*TARGET 0031bc38*/
u32 func_0031bc38(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0031bc38jjjjjjjj");
u32 func_0031bc38(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n0031bc38

// 0031bc58 (was src/anon/batch_w229.cpp)
namespace n0031bc58 {
void func_002361a0(void*) asm("func_002361a0");
void func_00239700(void*) asm("func_00239700");
extern u8 D_0034a548 asm("D_0034a548");
extern u8 D_00347e80 asm("D_00347e80");
extern u8 D_00347e60 asm("D_00347e60");
/*TARGET 0031bc58*/
void func_0031bc58(u32* t) asm("func_0031bc58");
void func_0031bc58(u32* t) {
    t[0] = (u32)&D_0034a548;
    t[0x30/4] = (u32)&D_00347e80;
    t[3] = 0;
    t[0x3c/4] = 0;
    func_002361a0((u8*)t + 0x50);
    func_00239700((u8*)t + 0x1f0);
    u8* e = (u8*)t + 0x348;
    int i = 12;
    do {
        *(u32*)(e + 12) = 0;
        *(u32*)e = (u32)&D_00347e60;
        func_00239700(e + 0x18);
        e += 0x198;
    } while (--i != -1);
}
}  // namespace n0031bc58

// 0031bcf8 (was src/anon/batch_w227.cpp)
namespace n0031bcf8 {
// 0x002bd998: definition moved into src/anon/unit_002bc978.cpp

extern void func_002361a0(void*) asm("func_002361a0");
extern void func_00239700(void*) asm("func_00239700");
extern u8 D_0034a5d0[] asm("D_0034a5d0");
extern u8 D_00347e80[] asm("D_00347e80");
extern u8 D_00347e60[] asm("D_00347e60");
/*TARGET 0031bcf8*/
void func_0031bcf8(u32* t) asm("func_0031bcf8");
void func_0031bcf8(u32* t) {
    t[0] = (u32)D_0034a5d0;
    t[12] = (u32)D_00347e80;
    t[3] = 0;
    t[15] = 0;
    func_002361a0((u8*)t + 80);
    func_00239700((u8*)t + 496);
    u32* s = (u32*)((u8*)t + 840);
    for (int i = 4; i != -1; i--) {
        s[3] = 0;
        s[0] = (u32)D_00347e60;
        func_00239700((u8*)s + 24);
        s = (u32*)((u8*)s + 408);
    }
}
}  // namespace n0031bcf8

// 0031bd98 (was src/anon/batch_w84.cpp)
namespace n0031bd98 {
extern void* D_00347e60[] asm("D_00347e60");
void func_00239700(void*) asm("func_00239700");
// 0x002e46d0: definition moved into src/anon/unit_002e3f58.cpp

extern void* D_0034a5b0[] asm("D_0034a5b0");
extern void* D_00347e80[] asm("D_00347e80");
void func_002361a0(void*) asm("func_002361a0");
/*TARGET 0031bd98*/
void func_0031bd98(u8* p) asm("func_0031bd98");
void func_0031bd98(u8* p) {
    *(u32*)p = (u32)D_0034a5b0;
    *(u32*)(p + 48) = (u32)D_00347e80;
    *(u32*)(p + 12) = 0;
    *(u32*)(p + 60) = 0;
    func_002361a0(p + 80);
    u8* e = p + 496;
    for (s32 i = 9; i != -1; i--) {
        *(u32*)(e + 12) = 0;
        *(void**)e = D_00347e60;
        func_00239700(e + 24);
        e += 408;
    }
    e = p + 4576;
    for (s32 i = 3; i != -1; i--) {
        *(u32*)(e + 12) = 0;
        *(void**)e = D_00347e60;
        func_00239700(e + 24);
        e += 408;
    }
    func_00239700(p + 6208);
    *(u32*)(p + 6552) = 0;
}
}  // namespace n0031bd98

// 0031be70 (was src/anon/batch_w41.cpp)
namespace n0031be70 {
extern void* D_00347f98[] asm("D_00347f98");
extern void* D_00347e60[] asm("D_00347e60");
extern void* D_0034a440[] asm("D_0034a440");
void func_0031a838(u8*) asm("func_0031a838");
void func_00239700(u8*) asm("func_00239700");
void func_0014b920(u8*) asm("func_0014b920");
/*TARGET 0031be70*/
void func_0031be70(u8* p) asm("func_0031be70");
void func_0031be70(u8* p) {
    *(void**)p = D_00347f98;
    func_0031a838(p + 12);
    *(void**)p = D_00347e60;
    func_00239700(p + 24);
    *(void**)p = D_0034a440;
    *(u32*)(p + 408) = 0;
    func_0014b920(p + 448);
    func_0014b920(p + 480);
}
}  // namespace n0031be70

// 0031bed8 (was src/anon/batch_w225.cpp)
namespace n0031bed8 {
void func_00239700(void*) asm("func_00239700");
extern u8 D_0034a660 asm("D_0034a660");
extern u8 D_00347e60 asm("D_00347e60");
/*TARGET 0031bed8*/
// 0x0022f528: definition moved into src/anon/unit_0022d358.cpp

void func_0031bed8(u8* t) asm("func_0031bed8");
// 0x0022f528: definition moved into src/anon/unit_0022d358.cpp

void func_0031bed8(u8* t) {
    *(u32*)t = (u32)&D_0034a660;
    *(u32*)(t + 0x30) = (u32)&D_00347e60;
    *(u32*)(t + 0xc) = 0;
    *(u32*)(t + 0x3c) = 0;
    func_00239700(t + 0x48);
    s32 i = 6;
    u8* p = t + 456;
    do { func_00239700(p); p += 344; } while (--i != -1);
}
}  // namespace n0031bed8

// 0031bf50 (was src/anon/batch_w39.cpp)
namespace n0031bf50 {
// 0x00302c28: definition moved into src/newlib/libc/findfp.c

// --- 0031bf50
// Constructor: two vtables (multiple inheritance), a member and a member array[7].
struct VT31b { u32 a[4]; };
extern VT31b D_0034a618 asm("D_0034a618");
extern VT31b D_00347e60 asm("D_00347e60");
void func_00239700(u8*) asm("func_00239700");
/*TARGET 0031bf50*/
void func_0031bf50(u8* p) asm("func_0031bf50");
void func_0031bf50(u8* p) {
    *(u32*)p = (u32)&D_0034a618;
    *(u32*)(p + 48) = (u32)&D_00347e60;
    *(u32*)(p + 12) = 0;
    *(u32*)(p + 60) = 0;
    func_00239700(p + 72);
    u8* q = p + 456;
    for (int i = 6; i != -1; i--, q += 344) func_00239700(q);
}
}  // namespace n0031bf50

// 0031bfc8 (was src/anon/auto200_999.cpp)
namespace n0031bfc8 {
void func_00239870(u32) asm("_Z13func_00239870j");
typedef void (*Fn_00322908)(u32, u32);
extern u32 D_00347f80 asm("D_00347f80");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
static inline u32 addr_D_00347e60() { return (u32)&D_00347e60; }
static inline u32 addr_D_00347f98() { return (u32)&D_00347f98; }
/*TARGET 0031bfc8*/
void func_0031bfc8(u32 self) asm("_Z13func_0031bfc8j");
void func_0031bfc8(u32 self) {
    u32 s16 = self;
    *(u32 *)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32 *)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32 *)(t + 20);
    Fn_00322908 fn = (Fn_00322908) * (u32 *)(*(u32 *)obj + 4);
    fn(obj, s16);
}
}  // namespace n0031bfc8

// 0031c028 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n0031c028 {
u32 func_00239870(u32, u32, u32, u32) asm("_Z13func_00239870jjjj");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
/*TARGET 0031c028*/
u32 func_0031c028(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031c028jjjj");
u32 func_0031c028(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0031c028

// 0031c068 (was src/anon/batch_w12.cpp)
namespace n0031c068 {
void dk__Sprite__draw(void*) asm("dk__Sprite__draw");
void func_0014b9a8(void*) asm("func_0014b9a8");
void dk__SpriteMessage__drawMessage(void*) asm("dk__SpriteMessage__drawMessage");
void ScisSpriteMessage_draw(u8*) asm("_ZN2dk17ScisSpriteMessage4drawEv");
/*TARGET 0031c068*/
// 002eaaf0: moved to src/anon/unit_002eaa68.cpp

void ScisSpriteMessage_draw(u8* self) asm("_ZN2dk17ScisSpriteMessage4drawEv");
// 002eaaf0: moved to src/anon/unit_002eaa68.cpp

void ScisSpriteMessage_draw(u8* self) {
    dk__Sprite__draw(self);
    func_0014b9a8(self + 448);
    dk__SpriteMessage__drawMessage(self);
    func_0014b9a8(self + 480);
}
}  // namespace n0031c068

// 0031c0a8 (gap; copy of 0x0031a840, was src/anon/tiny.cpp)
namespace n0031c0a8 {
extern u32 D_00347f98 asm("D_00347f98");
/*TARGET 0031c0a8*/
// 0x00316e10: definition moved into src/libgcc/ee-gthr.c

void func_0031c0a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031c0a8");
// 0x00316e10: definition moved into src/libgcc/ee-gthr.c

void func_0031c0a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00347f98;
}
}  // namespace n0031c0a8

// 0031c0b8 (was src/anon/batch_w31.cpp)
namespace n0031c0b8 {
extern void* D_00347f98[] asm("D_00347f98");
extern u8* D_00347f80 asm("D_00347f80");
// 0x002e8578: definition moved into src/anon/unit_002e7b10.cpp

typedef void (*VFn2)(void*, void*);
/*TARGET 0031c0b8*/
// 0x00314640: definition moved into src/libgcc/_unpack_sf.c

void func_0031c0b8(void** p) asm("func_0031c0b8");
// 0x00314640: definition moved into src/libgcc/_unpack_sf.c

void func_0031c0b8(void** p) {
    *p = D_00347f98;
    void* o = *(void**)(D_00347f80 + 20);
    (*(VFn2*)(*(u8**)o + 4))(o, p);
}
}  // namespace n0031c0b8

// 0031c0f8 (was src/anon/batch_w68.cpp)
namespace n0031c0f8 {
typedef void (*VF)(void*);
// 0x002f13b0: definition moved into src/anon/unit_002f12b0.cpp

/* ---- 0031c0f8: destructor body ---- */
extern void* D_0034a548 asm("D_0034a548");
extern void* D_00347e80 asm("D_00347e80");
extern void* D_00347f98 asm("D_00347f98");
extern void* D_00347f80_v asm("D_00347f80");
void func_00239870(void*) asm("func_00239870");
void func_002361d0(void*) asm("func_002361d0");
/*TARGET 0031c0f8*/
void func_0031c0f8(u8* o) asm("func_0031c0f8");
void func_0031c0f8(u8* o) {
    *(u32*)o = (u32)&D_0034a548;
    if (o + 840) {
        u8* p = o + 6144;
        u8* end = o + 840;
    loop:
        if (end == p) goto done;
        p -= 408;
        ((VF*)*(void**)p)[3](p);
        goto loop;
    }
done:
    func_00239870(o + 496);
    *(void**)(o + 48) = &D_00347e80;
    func_002361d0(o + 80);
    *(void**)o = *(void**)(o + 48) = &D_00347f98;
    void** m = *(void***)((u8*)D_00347f80_v + 20);
    ((void (**)(void*, void*))*m)[1](m, o);
}
}  // namespace n0031c0f8

// 0031c1b0 (was src/anon/batch_w64.cpp)
namespace n0031c1b0 {
typedef void (*VFn)(void*);
extern char D_00347f98[] asm("D_00347f98");
// 0x002feb28: definition moved into src/newlib/libc/signal.c

// ---------------------------------------------------------------------------
extern char D_0034a548[] asm("D_0034a548");
extern char D_00347e80[] asm("D_00347e80");
void func_00239870(u8*) asm("func_00239870");
void func_002361d0(u8*) asm("func_002361d0");
/*TARGET 0031c1b0*/
// Destructor: destroys the 13-element member array (408 bytes each) back to front.
void func_0031c1b0(u8* p) asm("func_0031c1b0");
// Destructor: destroys the 13-element member array (408 bytes each) back to front.
void func_0031c1b0(u8* p) {
    *(u32*)p = (u32)D_0034a548;
    if (p != (u8*)-840) {
        u8* e = p + 6144;
        for (;;) {
            if (p + 840 == e) break;
            e -= 408;
            (*(VFn*)(*(u8**)e + 12))(e);
        }
    }
    func_00239870(p + 496);
    *(void**)(p + 48) = D_00347e80;
    func_002361d0(p + 80);
    *(void**)(p + 48) = D_00347f98;
    *(void**)p = D_00347f98;
}
}  // namespace n0031c1b0

// 0031c248 (was src/anon/batch_w56.cpp)
namespace n0031c248 {
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0034a568[] asm("D_0034a568");
void func_00239870(void*) asm("func_00239870");
void func_0031a840(void*) asm("func_0031a840");
/*TARGET 0031c248*/
void func_0031c248(u8* p) asm("func_0031c248");
void func_0031c248(u8* p)
{
    *(void**)p = D_0034a568;
    *(void**)(p + 560) = D_00347e60;
    func_00239870(p + 584);
    u8* b = p + 48;
    *(void**)(p + 560) = D_00347f98;
    *(void**)b = D_00347e60;
    func_00239870(p + 72);
    func_0031a840(b);
    *(void**)p = D_00347f98;
}
}  // namespace n0031c248

// 0031c2c8 (was src/anon/batch_w228.cpp)
namespace n0031c2c8 {
struct Obj { void** vt; };
struct Hold { u32 pad[5]; Obj* o; };
extern char D_0034a568[] asm("D_0034a568");
extern char D_00347e60[] asm("D_00347e60");
extern char D_00347f98[] asm("D_00347f98");
extern Hold* D_00347f80 asm("D_00347f80");
void func_00239870(void*) asm("func_00239870");
void func_0031a840(void*) asm("func_0031a840");
/*TARGET 0031c2c8*/
// 0x002bd8f8: definition moved into src/anon/unit_002bc978.cpp

void func_0031c2c8(u32* p) asm("func_0031c2c8");
// 0x002bd8f8: definition moved into src/anon/unit_002bc978.cpp

void func_0031c2c8(u32* p) {
    p[0] = (u32)D_0034a568;
    p[140] = (u32)D_00347e60;
    func_00239870(p + 146);
    u32* q = p + 12;
    q[0] = (u32)D_00347e60;
    p[140] = (u32)D_00347f98;
    func_00239870(p + 18);
    func_0031a840(q);
    p[0] = (u32)D_00347f98;

    Obj* o = D_00347f80->o;
    ((void(*)(Obj*, void*))o->vt[1])(o, p);
}
}  // namespace n0031c2c8

// 0031c368 (was src/anon/batch_w83.cpp)
namespace n0031c368 {
// 0x002febb0: definition moved into src/newlib/libc/signal.c

// Elements of member arrays, destroyed through their vtables.
struct E408 { virtual void f0(); virtual void f4(); virtual void f8(); virtual void f12(); u8 pad[404]; };
struct VReg { virtual void f0(); virtual void f4(void*); };
union RegPtr { u8* p; u32 v; };
extern u32 D_0034a5b0[] asm("D_0034a5b0");
extern u32 D_00347e80[] asm("D_00347e80");
extern u32 D_00347f98[] asm("D_00347f98");
extern RegPtr D_00347f80 asm("D_00347f80");
void func_00239870(void*) asm("func_00239870");
void func_002361d0(void*) asm("func_002361d0");
/*TARGET 0031c368*/
void func_0031c368(u8* p) asm("func_0031c368");
void func_0031c368(u8* p) {
    *(u32*)p = (u32)D_0034a5b0;
    func_00239870(p + 6208);
    if (p + 4576) {
        E408* e = (E408*)(p + 6208);
        for (;;) {
            if ((E408*)(p + 4576) == e) break;
            --e;
            e->f12();
        }
    }
    if (p + 496) {
        E408* e = (E408*)(p + 4576);
        for (;;) {
            if ((E408*)(p + 496) == e) break;
            --e;
            e->f12();
        }
    }
    *(u32*)(p + 48) = (u32)D_00347e80;
    func_002361d0(p + 80);
    *(u32*)(p + 48) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
    (*(VReg**)(D_00347f80.p + 20))->f4(p);
}
}  // namespace n0031c368

// 0031c450 (was src/anon/batch_wcx2.cpp)
namespace n0031c450 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
struct E31c450;
struct EV31c450 { void* f[3]; void (*dtor)(E31c450*); };
struct E31c450 { EV31c450* vt; u8 pad[404]; };
struct O31c450 { u32 vt; u8 pad4[44]; u32 vt2; u8 pad34[28]; u8 m50[416]; E31c450 b[10]; E31c450 a[4]; u8 m1840[4]; };
extern u8 D_0034a5b0_31c450[] asm("D_0034a5b0");
extern u8 D_00347e80_31c450[] asm("D_00347e80");
extern u8 D_00347f98_31c450[] asm("D_00347f98");
void func_00239870(u8*) asm("func_00239870");
void func_002361d0(u8*) asm("func_002361d0");
static inline __attribute__((always_inline)) void DelA31c450(O31c450* o)
{
    if ((u8*)o + 4576 != 0) {
        E31c450* p = o->a + 4;
        E31c450* b = o->a;
        for (;;) {
            if (b == p) break;
            --p;
            p->vt->dtor(p);
        }
    }
}
static inline __attribute__((always_inline)) void DelB31c450(O31c450* o)
{
    if ((u8*)o + 496 != 0) {
        E31c450* p = o->b + 10;
        E31c450* b = o->b;
        for (;;) {
            if (b == p) break;
            --p;
            p->vt->dtor(p);
        }
    }
}
/*TARGET 0031c450*/
void func_0031c450(O31c450* o) asm("func_0031c450");
void func_0031c450(O31c450* o)
{
    o->vt = (u32)D_0034a5b0_31c450;
    func_00239870(o->m1840);
    DelA31c450(o);
    DelB31c450(o);
    o->vt2 = (u32)D_00347e80_31c450;
    func_002361d0(o->m50);
    o->vt2 = (u32)D_00347f98_31c450;
    o->vt = (u32)D_00347f98_31c450;
}
}  // namespace n0031c450

// 0031c518 (was src/anon/batch_wcx.cpp)
namespace n0031c518 {
typedef void (*VFn)(void*);
void func_00239870(u8*) asm("func_00239870");
extern u8 D_0034a5d0[] asm("D_0034a5d0");
extern u8 D_00347e80[] asm("D_00347e80");
extern u8 D_00347f98[] asm("D_00347f98");
extern u32 D_00347f80 asm("D_00347f80");
void func_002361d0(u8*) asm("func_002361d0");
typedef void (*FreeFn)(u8*, u8*);
/*TARGET 0031c518*/
void func_0031c518(u8* p) asm("func_0031c518");
void func_0031c518(u8* p)
{
    *(void**)p = D_0034a5d0;
    if (p != (u8*)-840) {
        u8* q = p + 2880;
        u8* a = p + 840;
    loop840:
        if (a == q) goto done840;
        q -= 408;
        (*(VFn*)(*(u8**)q + 12))(q);
        goto loop840;
    }
done840:
    func_00239870(p + 496);
    *(void**)(p + 48) = D_00347e80;
    func_002361d0(p + 80);
    *(u32*)(p + 48) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
    u8* al = *(u8**)(D_00347f80 + 20);
    (*(FreeFn*)(*(u8**)al + 4))(al, p);
}
}  // namespace n0031c518

// 0031c5d0 (was src/anon/batch_w227.cpp)
namespace n0031c5d0 {
extern void func_00239870(void*) asm("func_00239870");
extern void func_002361d0(void*) asm("func_002361d0");
extern u8 D_0034a5d0[] asm("D_0034a5d0");
extern u8 D_00347e80[] asm("D_00347e80");
extern u8 D_00347f98[] asm("D_00347f98");
/*TARGET 0031c5d0*/
void func_0031c5d0(u32* t) asm("func_0031c5d0");
void func_0031c5d0(u32* t) {
    t[0] = (u32)D_0034a5d0;
    if (t != (u32*)-840) {
        u8* p = (u8*)t + 2880;
        u8* q = (u8*)t + 840;
    top:
        if (q == p) goto out;
        p -= 408;
        ((void(*)(void*))(*(u32**)p)[3])(p);
        goto top;
    }
out:
    func_00239870((u8*)t + 496);
    t[12] = (u32)D_00347e80;
    func_002361d0((u8*)t + 80);
    t[12] = (u32)D_00347f98;
    t[0] = (u32)D_00347f98;
}
}  // namespace n0031c5d0

// 0031c668 (was src/anon/batch_w58.cpp)
namespace n0031c668 {
struct VObj { void** vt; };
typedef void (*VFn)(void*);
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
void func_00239870(void*) asm("func_00239870");
// Destructor: 7 344-byte members destroyed in reverse through their vtables.
extern u8 D_0034a618[] asm("D_0034a618");
/*TARGET 0031c668*/
void func_0031c668(u8* p) asm("func_0031c668");
void func_0031c668(u8* p) {
    *(void**)p = D_0034a618;
    if ((s32)p != -456) {
        u8* e = p + 2864;
        for (;;) {
            if (p + 456 == e) break;
            e -= 344;
            ((VFn)(*(VObj*)e).vt[0])(e);
        }
    }
    *(void**)(p + 48) = D_00347e60;
    func_00239870(p + 72);
    *(void**)(p + 48) = D_00347f98;
    *(void**)p = D_00347f98;
}
}  // namespace n0031c668

// 0031c6f8 (was src/anon/batch_wcx.cpp)
namespace n0031c6f8 {
typedef void (*VFn)(u8*);
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
extern u32 D_00347f80 asm("D_00347f80");
void func_00239870(u8*) asm("func_00239870");
typedef void (*FreeFn)(u8*, u8*);
extern u8 D_0034a618[] asm("D_0034a618");
/*TARGET 0031c6f8*/
void func_0031c6f8(u8* p) asm("func_0031c6f8");
void func_0031c6f8(u8* p)
{
    *(void**)p = D_0034a618;
    if (p != (u8*)-456) {
        u8* q = p + 2864;
        u8* a = p + 456;
    loop:
        if (a == q) goto done;
        q -= 344;
        (**(VFn**)q)(q);
        goto loop;
    }
done:
    *(void**)(p + 48) = D_00347e60;
    func_00239870(p + 72);
    *(u32*)(p + 48) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
    u8* al = *(u8**)(D_00347f80 + 20);
    (*(FreeFn*)(*(u8**)al + 4))(al, p);
}
}  // namespace n0031c6f8

// 0031c7a8 (was src/anon/batch_w59.cpp)
namespace n0031c7a8 {
extern u8 D_00347e60[] asm("D_00347e60");
// 0x00313bc0: definition moved into src/libgcc/_sf_to_usi.c

// --- 0031c7a8
// Destructor: destroy the 7-element member array (344-byte elements, virtual
// dtor) back to front, then the base subobjects.
extern u8 D_0034a660[] asm("D_0034a660");
extern u8 D_00347f98[] asm("D_00347f98");
void func_00239870(u8*) asm("func_00239870");
/*TARGET 0031c7a8*/
void func_0031c7a8(u8* p) asm("func_0031c7a8");
void func_0031c7a8(u8* p) {
    *(u32*)p = (u32)D_0034a660;
    if (p + 456) {
        u8* e = p + 2864;
        for (;;) {
            if (p + 456 == e) break;
            e -= 344;
            typedef void (*Fn)(u8*);
            (**(Fn**)e)(e);
        }
    }
    *(u32*)(p + 48) = (u32)D_00347e60;
    func_00239870(p + 72);
    *(u32*)(p + 48) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
}
}  // namespace n0031c7a8

// 0031c838 (was src/anon/batch_wcx.cpp)
namespace n0031c838 {
typedef void (*VFn)(u8*);
typedef void (*FreeFn)(u8*, u8*);
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
extern u32 D_00347f80 asm("D_00347f80");
void func_00239870(u8*) asm("func_00239870");
extern u8 D_0034a660[] asm("D_0034a660");
/*TARGET 0031c838*/
void func_0031c838(u8* p) asm("func_0031c838");
void func_0031c838(u8* p)
{
    *(void**)p = D_0034a660;
    if (p != (u8*)-456) {
        u8* q = p + 2864;
        u8* a = p + 456;
    loop:
        if (a == q) goto done;
        q -= 344;
        (**(VFn**)q)(q);
        goto loop;
    }
done:
    *(void**)(p + 48) = D_00347e60;
    func_00239870(p + 72);
    *(u32*)(p + 48) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
    u8* al = *(u8**)(D_00347f80 + 20);
    (*(FreeFn*)(*(u8**)al + 4))(al, p);
}
}  // namespace n0031c838

// 0031c8e8 (was src/anon/batch_w13.cpp)
namespace n0031c8e8 {
void func_00239870(void*) asm("func_00239870");
u8 func_0031a840(void*) asm("func_0031a840");
extern void (*D_0035e380[])(void) asm("D_0035e380");
extern u8 D_00347e60 asm("D_00347e60");
/*TARGET 0031c8e8*/
// 0x00304db0: definition moved into src/newlib/libc/s_isnan.c

u8 func_0031c8e8(void** p) asm("func_0031c8e8");
// 0x00304db0: definition moved into src/newlib/libc/s_isnan.c

u8 func_0031c8e8(void** p) {
    *p = &D_00347e60;
    func_00239870((u8*)p + 24);
    return func_0031a840(p);
}
}  // namespace n0031c8e8

// 0031c928 (was src/anon/batch_w25.cpp)
namespace n0031c928 {
struct VObj { void (**vt)(...); };
typedef void (*VFn)(void*, void*);
// 0x002edf28: definition moved into src/anon/unit_002ecdb0.cpp

extern u8 D_00347e60 asm("D_00347e60");
extern u8* D_00347f80 asm("D_00347f80");
void func_00239870(void*) asm("func_00239870");
void func_0031a840(void*) asm("func_0031a840");
/*TARGET 0031c928*/
void func_0031c928(u32* o) asm("func_0031c928");
void func_0031c928(u32* o) {
    o[0] = (u32)&D_00347e60;
    func_00239870(o + 6);
    func_0031a840(o);
    VObj* m = *(VObj**)(D_00347f80 + 20);
    ((VFn)m->vt[1])(m, o);
}
}  // namespace n0031c928

// 0031c980 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0031c980 {
// set_vtbl_3486a8_b
u32 func_0031cd50(u32, u32, u32, u32) asm("_Z13func_0031cd50jjjj");
extern u8 D_00347e40 asm("D_00347e40");
/*TARGET 0031c980*/
u32 func_0031c980(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031c980jjjj");
u32 func_0031c980(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347e40;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0031cd50)(u32, u32, u32, u32) = func_0031cd50;
    r2 = fp_call4_0031cd50(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0031c980

// 0031c9a8 (was src/anon/batch_w25.cpp)
namespace n0031c9a8 {
struct VObj { void (**vt)(...); };
typedef void (*VFn)(void*, void*);
extern u8 D_00347e40 asm("D_00347e40");
extern u8* D_00347f80 asm("D_00347f80");
void func_0031cd50(void*) asm("func_0031cd50");
/*TARGET 0031c9a8*/
void func_0031c9a8(u32* o) asm("func_0031c9a8");
void func_0031c9a8(u32* o) {
    o[0] = (u32)&D_00347e40;
    func_0031cd50(o);
    VObj* m = *(VObj**)(D_00347f80 + 20);
    ((VFn)m->vt[1])(m, o);
}
}  // namespace n0031c9a8

// 0031c9f8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0031c9f8 {
// set_vtbl_3486a8_b
u32 func_0031cd50(u32, u32, u32, u32) asm("_Z13func_0031cd50jjjj");
extern u8 D_00347e40 asm("D_00347e40");
/*TARGET 0031c9f8*/
u32 func_0031c9f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031c9f8jjjj");
u32 func_0031c9f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347e40;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0031cd50)(u32, u32, u32, u32) = func_0031cd50;
    r2 = fp_call4_0031cd50(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0031c9f8

// 0031ca20 (was src/anon/batch_w26.cpp)
namespace n0031ca20 {
// ee_intr_get_enable
void func_0031cd50(void*) asm("func_0031cd50");
extern u8 D_00347e40[] asm("D_00347e40");
extern u8* D_00347f80 asm("D_00347f80");
struct Obj { void (**vt)(Obj*); };
/*TARGET 0031ca20*/
// 0x002fdf30: definition moved into src/newlib/libc/mlock.c

void func_0031ca20(u8* o) asm("func_0031ca20");
// 0x002fdf30: definition moved into src/newlib/libc/mlock.c

void func_0031ca20(u8* o) {
    *(u8**)o = D_00347e40;
    func_0031cd50(o);
    Obj* m = *(Obj**)(D_00347f80 + 20);
    ((void (*)(Obj*, void*))m->vt[1])(m, o);
}
}  // namespace n0031ca20

// 0031ca70 (was src/anon/batch_wcx2.cpp)
namespace n0031ca70 {
struct AVt31ca70 { void* alloc; void (*free)(void* self, void* p); };
struct AO31ca70 { AVt31ca70* vt; };
struct H31ca70 { u8 pad[20]; AO31ca70* al; };
union HU31ca70 { H31ca70* h; u32 u; };
extern HU31ca70 D_00347f80_31ca70 asm("D_00347f80");
extern u8 D_0034a700_31ca70[] asm("D_0034a700");
extern u8 D_00347f98_31ca70[] asm("D_00347f98");
struct E31ca70 { u8 d[600]; };
void func_0031c9f8(E31ca70*) asm("func_0031c9f8");
void func_0031c980(E31ca70*) asm("func_0031c980");
void func_0031c8e8(E31ca70*) asm("func_0031c8e8");
struct MA31ca70 { u8 hdr[8]; E31ca70 e[16]; };
struct MB31ca70 { u8 hdr[8]; E31ca70 e[4]; };
struct O31ca70 { u32 vt; u8 pad[32]; MA31ca70 a; u8 p2[12]; MB31ca70 b; u8 p3[12]; MB31ca70 c; };
#define DEL31ca70(name, M, n, fn) \
static inline __attribute__((always_inline)) void name(M* m) \
{ \
    if (m->e != 0) { E31ca70* p = m->e + n; E31ca70* b = m->e; for (;;) { if (b == p) break; --p; fn(p); } } \
}
DEL31ca70(DelC31ca70, MB31ca70, 4, func_0031c9f8)
DEL31ca70(DelB31ca70, MB31ca70, 4, func_0031c980)
DEL31ca70(DelA31ca70, MA31ca70, 16, func_0031c8e8)
#undef DEL31ca70
/*TARGET 0031ca70*/
void func_0031ca70(O31ca70* o) asm("func_0031ca70");
void func_0031ca70(O31ca70* o)
{
    o->vt = (u32)D_0034a700_31ca70;
    DelC31ca70(&o->c);
    DelB31ca70(&o->b);
    DelA31ca70(&o->a);
    o->vt = (u32)D_00347f98_31ca70;
    AO31ca70* al = D_00347f80_31ca70.h->al;
    al->vt->free(al, o);
}
}  // namespace n0031ca70

// 0031cb58 (was src/anon/batch_w88.cpp)
namespace n0031cb58 {
void func_0031c9f8(u8*) asm("func_0031c9f8");
void func_0031c980(u8*) asm("func_0031c980");
void func_0031c8e8(u8*) asm("func_0031c8e8");
extern u8 D_0034a700[] asm("D_0034a700");
extern u8 D_00347f98[] asm("D_00347f98");
// 002ef258: moved to src/anon/unit_002ef1f8.cpp

static inline void Dtor1cb58a(u8* self) {
    if (self + 8 != 0) {
        u8* e = self + 2408;
    l:
        if (self + 8 != e) { e -= 600; func_0031c9f8(e); goto l; }
    }
}
static inline void Dtor1cb58b(u8* self) {
    if (self + 8 != 0) {
        u8* e = self + 2408;
    l:
        if (self + 8 != e) { e -= 600; func_0031c980(e); goto l; }
    }
}
static inline void Dtor1cb58c(u8* self) {
    if (self + 8 != 0) {
        u8* e = self + 9608;
    l:
        if (self + 8 != e) { e -= 600; func_0031c8e8(e); goto l; }
    }
}
/*TARGET 0031cb58*/
void func_0031cb58(u8* o) asm("func_0031cb58");
void func_0031cb58(u8* o) {
    *(u32*)o = (u32)D_0034a700;
    Dtor1cb58a(o + 12076);
    Dtor1cb58b(o + 9656);
    Dtor1cb58c(o + 36);
    *(u32*)o = (u32)D_00347f98;
}
}  // namespace n0031cb58

// 0031cc28 (was src/anon/misc_3.cpp)
namespace n0031cc28 {
/*TARGET 0031cc28*/
void func_0031cc28(void* self) asm("_ZN9W1637TabAIvE5ClearEv");  // the out-of-line W1637Tab Clear() of unit_00169398.cpp
void func_0031cc28(void* self) { *(s32*)((char*)self + 0) = 0; }
}  // namespace n0031cc28

// 0031cc30 (was src/anon/batch_w1829.cpp)
namespace n0031cc30 {
struct W1829Ent { u8 pad[0x1c4]; void* m4; s32 a2; s32 a1; s32 a5; s32 a6; u8 m1[64]; u8 m2[64]; };
struct W1829R { s32 head; s32 tail; W1829Ent e[16]; };
struct W1829Q { u8 pad[12]; W1829R r; };
void func_00192c90(void*, void*) asm("func_00192c90");
void func_00192b30(void*) asm("func_00192b30");
/*TARGET 0031cc30*/
/* 0031cc30: push an entry onto a 16-slot ring buffer (600-byte entries), copying one or two matrices. */
void func_0031cc30(W1829Q* q, s32 a1, s32 a2, void* a3, void* a4, s32 a5, s32 a6) asm("func_0031cc30");
/* 0031cc30: push an entry onto a 16-slot ring buffer (600-byte entries), copying one or two matrices. */
void func_0031cc30(W1829Q* q, s32 a1, s32 a2, void* a3, void* a4, s32 a5, s32 a6) {
    W1829R* r = &q->r;
    s32 h = r->head;
    s32 n = (h - r->tail + 16) % 16;
    if (n < 15) {
        r->head = (h + 1) % 16;
        W1829Ent* e = &r->e[h];
        func_00192c90(a3, e->m1);
        func_00192b30(a3);
        if (a4) {
            func_00192c90(a4, e->m2);
            func_00192b30(a4);
        }
        e->a2 = a2;
        e->m4 = a4;
        e->a1 = a1;
        e->a5 = a5;
        e->a6 = a6;
    }
}
}  // namespace n0031cc30

// 0031cd50 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n0031cd50 {
u32 func_00239870(u32, u32, u32, u32) asm("_Z13func_00239870jjjj");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
/*TARGET 0031cd50*/
u32 func_0031cd50(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031cd50jjjj");
u32 func_0031cd50(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0031cd50

// 0031cd90 (was src/anon/batch_w24.cpp)
namespace n0031cd90 {
extern void* D_00347f98[] asm("D_00347f98");
extern void* D_0035eb98[] asm("D_0035eb98");
void func_0023c098(u8*) asm("func_0023c098");
// set_vtbl_36eae8_then_call
void func_002369f0(u8*) asm("func_002369f0");
/*TARGET 0031cd90*/
// set_vtbl_36eac8_then_call
void func_0031cd90(u8* p) asm("func_0031cd90");
// set_vtbl_36eac8_then_call
void func_0031cd90(u8* p) {
    *(void**)p = D_0035eb98;
    func_0023c098(p + 48);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 24);  // set_vtbl_36eac8_then_call
    *(void**)p = D_00347f98;
}
}  // namespace n0031cd90

// 0031cdd8 (was src/anon/batch_w27.cpp)
namespace n0031cdd8 {
// 0x002ff918: definition moved into src/newlib/libc/strstr.c



extern u32 D_0035eb98 asm("D_0035eb98");
extern u32 D_00347f98 asm("D_00347f98");
void func_0023c098(void*) asm("func_0023c098");
// set_vtbl_36eae8_then_call
void func_002369f0(void*) asm("func_002369f0");
// set_vtbl_36eac8_then_call
void func_0023ee68(void*) asm("func_0023ee68");
/*TARGET 0031cdd8*/
void func_0031cdd8(u8* p) asm("func_0031cdd8");
void func_0031cdd8(u8* p) {
    *(void**)p = &D_0035eb98;
    func_0023c098(p + 48);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 24);  // set_vtbl_36eac8_then_call
    *(void**)p = &D_00347f98;
    func_0023ee68(p);
}
}  // namespace n0031cdd8

// 0031ce28 (gap; copy of 0x0031cd90, was src/anon/batch_w24.cpp)
namespace n0031ce28 {
extern void* D_00347f98[] asm("D_00347f98");
extern void* D_0035eb98[] asm("D_0035eb98");
void func_0023c098(u8*) asm("func_0023c098");
// set_vtbl_36eae8_then_call
void func_002369f0(u8*) asm("func_002369f0");
/*TARGET 0031ce28*/
// set_vtbl_36eac8_then_call
void func_0031ce28(u8* p) asm("func_0031ce28");
// set_vtbl_36eac8_then_call
void func_0031ce28(u8* p) {
    *(void**)p = D_0035eb98;
    func_0023c098(p + 48);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 24);  // set_vtbl_36eac8_then_call
    *(void**)p = D_00347f98;
}
}  // namespace n0031ce28

// 0031ce70 (was src/anon/batch_w28.cpp)
namespace n0031ce70 {
// fprintf_stream_va
void func_0023c098(void*) asm("func_0023c098");
// set_vtbl_36eae8_then_call
void func_002369f0(void*) asm("func_002369f0");
// set_vtbl_36eac8_then_call
void func_0023ee68(void*) asm("func_0023ee68");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8 D_00347f98[] asm("D_00347f98");
/*TARGET 0031ce70*/
// 0x00301550: definition moved into src/newlib/libc/vsprintf.c

void func_0031ce70(u8* p) asm("func_0031ce70");
// 0x00301550: definition moved into src/newlib/libc/vsprintf.c

void func_0031ce70(u8* p) {
    *(void**)p = D_0035eb98;
    func_0023c098(p + 48);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 24);  // set_vtbl_36eac8_then_call
    *(void**)p = D_00347f98;
    func_0023ee68(p);
}
}  // namespace n0031ce70

// 0031cec0 (was src/anon/batch_w35.cpp)
namespace n0031cec0 {
// 0x002f1808: definition moved into src/anon/unit_002f17e0.cpp

extern u8 D_0034a800[] asm("D_0034a800");
extern u8 D_00347e60[] asm("D_00347e60");
extern void* D_00347f98[] asm("D_00347f98");
void func_002361d0(void*) asm("func_002361d0");
void func_00239870(void*) asm("func_00239870");
/*TARGET 0031cec0*/
void func_0031cec0(u8* p) asm("func_0031cec0");
void func_0031cec0(u8* p) {
    *(void**)p = D_0034a800;
    func_002361d0(p + 416);
    *(void**)p = D_00347e60;
    func_00239870(p + 24);
    *(void***)p = D_00347f98;
}
}  // namespace n0031cec0

// 0031cf18 (was src/anon/batch_w38.cpp)
namespace n0031cf18 {
// 002f0af0: moved to src/naka/libkn/trapfunctions.cpp

extern void* D_0034a800[] asm("D_0034a800");
extern void* D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60 asm("D_00347e60");
void func_002361d0(void*) asm("func_002361d0");
void func_00239870(void*) asm("func_00239870");
typedef void (*VFn2)(void*, void*);
extern void* D_00347f80v asm("D_00347f80");
/*TARGET 0031cf18*/
// Destructor body: unwinds the vtables and unregisters from the manager.
void func_0031cf18(u8* p) asm("func_0031cf18");
// Destructor body: unwinds the vtables and unregisters from the manager.
void func_0031cf18(u8* p) {
    *(void**)p = D_0034a800;
    func_002361d0(p + 416);
    *(void**)p = &D_00347e60;
    func_00239870(p + 24);
    *(void**)p = D_00347f98;
    void** o = *(void***)((u8*)D_00347f80v + 20);
    (*(VFn2*)((u8*)*o + 4))(o, p);
}
}  // namespace n0031cf18

// 0031cf88 (was src/anon/batch_w66.cpp)
namespace n0031cf88 {
extern void* D_0034a820[] asm("D_0034a820");
extern void* D_00347f98[] asm("D_00347f98");
struct E408 { void** vt; u8 pad[404]; ~E408() { ((void (*)(E408*))vt[3])(this); } };
struct Base31 { u32 vt; ~Base31() { *(void**)this = D_00347f98; } };
struct Obj31c : Base31 {
    u8 pad[44];
    E408 a[6];
    E408 b[32];
    ~Obj31c() { *(void**)this = D_0034a820; }
};
/*TARGET 0031cf88*/
// 0x001e2898: definition moved into src/anon/unit_001e0cb8.cpp
void func_0031cf88(Obj31c* p) asm("func_0031cf88");
// 0x001e2898: definition moved into src/anon/unit_001e0cb8.cpp
void func_0031cf88(Obj31c* p) { p->~Obj31c(); }
}  // namespace n0031cf88

// 0031d030 (was src/anon/batch_w86.cpp)
namespace n0031d030 {
struct Elem;
typedef void (*EFn)(Elem*);
struct Elem { EFn* vt; u8 p4[404]; };
struct Obj { u32 vt; u8 p4[44]; Elem a[6]; Elem b[32]; };
struct Alloc;
typedef void (*AFn)(Alloc*, void*);
struct Alloc { AFn* vt; };
struct Sys { u8 p0[20]; Alloc* alloc; };
union SysP { Sys* p; u32 u; };
extern SysP g_sys asm("D_00347f80");
extern u8 D_0034a820[] asm("D_0034a820");
extern u8 D_00347f98[] asm("D_00347f98");
/*TARGET 0031d030*/
void func_0031d030(Obj* o) asm("func_0031d030");
void func_0031d030(Obj* o)
{
    o->vt = (u32)D_0034a820;
    if (o->b) {
        Elem* e = o->b + 32;
    nb:
        if (o->b != e) {
            --e;
            e->vt[3](e);
            goto nb;
        }
    }
    if (o->a) {
        Elem* e = o->a + 6;
    na:
        if (o->a != e) {
            --e;
            e->vt[3](e);
            goto na;
        }
    }
    o->vt = (u32)D_00347f98;
    g_sys.p->alloc->vt[1](g_sys.p->alloc, o);
}
}  // namespace n0031d030

// 0031d0f8 (was src/anon/batch_w83.cpp)
namespace n0031d0f8 {
struct E592 { virtual void f0(); virtual void f4(); virtual void f8(); virtual void f12(); u8 pad[588]; };
struct E412 { virtual void f0(); virtual void f4(); virtual void f8(); virtual void f12(); u8 pad[408]; };
extern u32 D_00347f98[] asm("D_00347f98");
extern u32 D_0034a848[] asm("D_0034a848");
extern u32 D_00348608[] asm("D_00348608");
void func_0031cec0(void*) asm("func_0031cec0");
/*TARGET 0031d0f8*/
void func_0031d0f8(u8* p) asm("func_0031d0f8");
void func_0031d0f8(u8* p) {
    *(u32*)p = (u32)D_0034a848;
    if (p + 2576) {
        E592* e = (E592*)(p + 5536);
        for (;;) {
            if ((E592*)(p + 2576) == e) break;
            --e;
            e->f12();
        }
    }
    if (p + 916) {
        E412* e = (E412*)(p + 2564);
        for (;;) {
            if ((E412*)(p + 916) == e) break;
            --e;
            e->f12();
        }
    }
    *(u32*)p = (u32)D_00348608;
    func_0031cec0(p + 64);
    *(u32*)p = (u32)D_00347f98;
}
}  // namespace n0031d0f8

// 0031d1b8 (was src/anon/batch_w88.cpp)
namespace n0031d1b8 {
void func_0031cec0(u8*) asm("func_0031cec0");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0034a848[] asm("D_0034a848");
extern u8 D_00348608[] asm("D_00348608");
extern u32 D_00347f80 asm("D_00347f80");
typedef void (*Dtor)(u8*);
typedef void (*VF31d1b8)(u8*, u8*);
/*TARGET 0031d1b8*/
void func_0031d1b8(u8* o) asm("func_0031d1b8");
void func_0031d1b8(u8* o) {
    *(u32*)o = (u32)D_0034a848;
    if (o + 2576 != 0) {
        u8* e = o + 5536;
    l1:
        if (o + 2576 != e) { e -= 592; (*(Dtor*)(*(u8**)e + 12))(e); goto l1; }
    }
    if (o + 916 != 0) {
        u8* e = o + 2564;
    l2:
        if (o + 916 != e) { e -= 412; (*(Dtor*)(*(u8**)e + 12))(e); goto l2; }
    }
    *(u32*)o = (u32)D_00348608;
    func_0031cec0(o + 64);
    *(u32*)o = (u32)D_00347f98;
    u8* m = *(u8**)(D_00347f80 + 20);
    (*(VF31d1b8*)(*(u8**)m + 4))(m, o);
}
}  // namespace n0031d1b8

// 0031d290 (was src/anon/batch_w109.cpp)
namespace n0031d290 {
// 0x002c14e8: definition moved into src/anon/unit_002c10e0.cpp

// ---- f9.cpp
extern void* D_0034a920[] asm("D_0034a920");
extern void* D_00348678[] asm("D_00348678");
extern void* D_003486d8[] asm("D_003486d8");
extern void* D_00347f98[] asm("D_00347f98");
extern void* D_00347e60[] asm("D_00347e60");
extern void* D_00348608[] asm("D_00348608");
void func_0031d6b0(u8*) asm("func_0031d6b0");
// set_vtbl_3486a8_c
void func_00239870(u8*) asm("func_00239870");
void func_0031cec0(u8*) asm("func_0031cec0");
typedef void (*Dtor31d290)(u8*);
#define DestroyArr31d290(B, E, SZ) \
    if ((B) != 0) { \
        u8* e = (E); \
        u8* b = (B); \
        for (;;) { \
            if (b == e) break; \
            e -= (SZ); \
            (*(Dtor31d290*)(*(u8**)e + 12))(e); \
        } \
    }
static inline __attribute__((always_inline)) void Body31d290(u8* p) {
    *(void***)p = D_0034a920;
    DestroyArr31d290(p + 13232, p + 15600, 592);
    *(void***)(p + 12896) = D_00348678;
    *(void***)(p + 12928) = D_003486d8;
    func_0031d6b0(p + 12928);  // set_vtbl_3486a8_c
    *(void***)(p + 12896) = D_00347f98;
    DestroyArr31d290(p + 6704, p + 12884, 412);
    DestroyArr31d290(p + 5008, p + 6704, 848);
    DestroyArr31d290(p + 4180, p + 4996, 408);
    DestroyArr31d290(p + 3364, p + 4180, 408);
    DestroyArr31d290(p + 2548, p + 3364, 408);
    DestroyArr31d290(p + 1732, p + 2548, 408);
    *(void***)(p + 1324) = D_00347e60;
    func_00239870(p + 1348);
    *(void***)(p + 1324) = D_00347f98;
    *(void***)(p + 916) = D_00347e60;
    func_00239870(p + 940);
    *(void***)(p + 916) = D_00347f98;
    *(void***)p = D_00348608;
    func_0031cec0(p + 64);
    *(void***)p = D_00347f98;
}
/*TARGET 0031d290*/
// Destructor: resets vtables and destroys the member object arrays (last to first).
void func_0031d290(u8* p) asm("func_0031d290");
// Destructor: resets vtables and destroys the member object arrays (last to first).
void func_0031d290(u8* p) {
    Body31d290(p);
}
}  // namespace n0031d290

// 0031d490 (was src/anon/batch_w109.cpp)
namespace n0031d490 {
// 0x002c14e8: definition moved into src/anon/unit_002c10e0.cpp

// ---- f9.cpp
extern void* D_0034a920[] asm("D_0034a920");
extern void* D_00348678[] asm("D_00348678");
extern void* D_003486d8[] asm("D_003486d8");
extern void* D_00347f98[] asm("D_00347f98");
extern void* D_00347e60[] asm("D_00347e60");
extern void* D_00348608[] asm("D_00348608");
void func_0031d6b0(u8*) asm("func_0031d6b0");
// set_vtbl_3486a8_c
void func_00239870(u8*) asm("func_00239870");
void func_0031cec0(u8*) asm("func_0031cec0");
typedef void (*Dtor31d290)(u8*);
#define DestroyArr31d290(B, E, SZ) \
    if ((B) != 0) { \
        u8* e = (E); \
        u8* b = (B); \
        for (;;) { \
            if (b == e) break; \
            e -= (SZ); \
            (*(Dtor31d290*)(*(u8**)e + 12))(e); \
        } \
    }
static inline __attribute__((always_inline)) void Body31d290(u8* p) {
    *(void***)p = D_0034a920;
    DestroyArr31d290(p + 13232, p + 15600, 592);
    *(void***)(p + 12896) = D_00348678;
    *(void***)(p + 12928) = D_003486d8;
    func_0031d6b0(p + 12928);  // set_vtbl_3486a8_c
    *(void***)(p + 12896) = D_00347f98;
    DestroyArr31d290(p + 6704, p + 12884, 412);
    DestroyArr31d290(p + 5008, p + 6704, 848);
    DestroyArr31d290(p + 4180, p + 4996, 408);
    DestroyArr31d290(p + 3364, p + 4180, 408);
    DestroyArr31d290(p + 2548, p + 3364, 408);
    DestroyArr31d290(p + 1732, p + 2548, 408);
    *(void***)(p + 1324) = D_00347e60;
    func_00239870(p + 1348);
    *(void***)(p + 1324) = D_00347f98;
    *(void***)(p + 916) = D_00347e60;
    func_00239870(p + 940);
    *(void***)(p + 916) = D_00347f98;
    *(void***)p = D_00348608;
    func_0031cec0(p + 64);
    *(void***)p = D_00347f98;
}
typedef void (*Free31d290)(u8*, u8*);
extern u8* D_00347f80 asm("D_00347f80");
/*TARGET 0031d490*/
// Deleting destructor: same, then frees through the global allocator.
void func_0031d490(u8* p) asm("func_0031d490");
// Deleting destructor: same, then frees through the global allocator.
void func_0031d490(u8* p) {
    Body31d290(p);
      // keeps the final vtable store ahead of the allocator lookup
    u8* a = *(u8**)(D_00347f80 + 20);
    (*(Free31d290*)(*(u8**)a + 4))(a, p);
}
}  // namespace n0031d490

// 0031d6b0 (was src/anon/tiny.cpp)
namespace n0031d6b0 {
extern u32 D_00348698 asm("D_00348698");
/*TARGET 0031d6b0*/
void func_0031d6b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031d6b0jjjj");
void func_0031d6b0(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8_c
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00348698;
}
}  // namespace n0031d6b0

// 0031d6c0 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n0031d6c0 {
u32 func_00239870(u32, u32, u32, u32) asm("_Z13func_00239870jjjj");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
/*TARGET 0031d6c0*/
u32 func_0031d6c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031d6c0jjjj");
u32 func_0031d6c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0031d6c0

// 0031d700 (was src/anon/auto200_999.cpp)
namespace n0031d700 {
void func_00239870(u32) asm("_Z13func_00239870j");
typedef void (*Fn_00322908)(u32, u32);
extern u32 D_00347f80 asm("D_00347f80");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
static inline u32 addr_D_00347e60() { return (u32)&D_00347e60; }
static inline u32 addr_D_00347f98() { return (u32)&D_00347f98; }
/*TARGET 0031d700*/
void func_0031d700(u32 self) asm("_Z13func_0031d700j");
void func_0031d700(u32 self) {
    u32 s16 = self;
    *(u32 *)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32 *)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32 *)(t + 20);
    Fn_00322908 fn = (Fn_00322908) * (u32 *)(*(u32 *)obj + 4);
    fn(obj, s16);
}
}  // namespace n0031d700

// 0031d760 (gap; copy of 0x0031a840, was src/anon/tiny.cpp)
namespace n0031d760 {
extern u32 D_00347f98 asm("D_00347f98");
/*TARGET 0031d760*/
// 0x00316e10: definition moved into src/libgcc/ee-gthr.c

void func_0031d760(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031d760");
// 0x00316e10: definition moved into src/libgcc/ee-gthr.c

void func_0031d760(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00347f98;
}
}  // namespace n0031d760

// 0031d770 (was src/anon/batch_w32.cpp)
namespace n0031d770 {
extern void* D_00347f98[] asm("D_00347f98");
extern void* D_00347f80 asm("D_00347f80");
// 0x00314b38: definition moved into src/libsupc++/eh_personality.cpp

struct VObj { void** vt; };
/*TARGET 0031d770*/
void func_0031d770(void** p) asm("func_0031d770");
void func_0031d770(void** p) {
    *(void**)p = D_00347f98;
    VObj* o = *(VObj**)((u8*)D_00347f80 + 0x14);
    ((void (*)(VObj*, void*))o->vt[1])(o, p);
}
}  // namespace n0031d770

// 0031d7b0 (gap; copy of 0x0031a840, was src/anon/tiny.cpp)
namespace n0031d7b0 {
extern u32 D_00347f98 asm("D_00347f98");
/*TARGET 0031d7b0*/
// 0x00316e10: definition moved into src/libgcc/ee-gthr.c

void func_0031d7b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031d7b0");
// 0x00316e10: definition moved into src/libgcc/ee-gthr.c

void func_0031d7b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00347f98;
}
}  // namespace n0031d7b0

// 0031d7c0 (was src/anon/batch_w33.cpp)
namespace n0031d7c0 {
// 0x00316f70: definition moved into src/libgcc/unwind-dw2.c

struct VObj31d { void** vt; };
struct Mgr31d { u8 pad[20]; VObj31d* o; };
extern void* D_00347f80 asm("D_00347f80");
extern void* D_00347f98[] asm("D_00347f98");
/*TARGET 0031d7c0*/
void func_0031d7c0(void** p) asm("func_0031d7c0");
void func_0031d7c0(void** p) {
    *p = D_00347f98;
    VObj31d* o = ((Mgr31d*)D_00347f80)->o;
    ((void (*)(VObj31d*, void*))o->vt[1])(o, p);
}
}  // namespace n0031d7c0

// 0031d800 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n0031d800 {
u32 func_00239870(u32, u32, u32, u32) asm("_Z13func_00239870jjjj");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
/*TARGET 0031d800*/
u32 func_0031d800(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031d800jjjj");
u32 func_0031d800(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0031d800

// 0031d840 (was src/anon/auto200_999.cpp)
namespace n0031d840 {
void func_00239870(u32) asm("_Z13func_00239870j");
typedef void (*Fn_00322908)(u32, u32);
extern u32 D_00347f80 asm("D_00347f80");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
static inline u32 addr_D_00347e60() { return (u32)&D_00347e60; }
static inline u32 addr_D_00347f98() { return (u32)&D_00347f98; }
/*TARGET 0031d840*/
void func_0031d840(u32 self) asm("_Z13func_0031d840j");
void func_0031d840(u32 self) {
    u32 s16 = self;
    *(u32 *)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32 *)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32 *)(t + 20);
    Fn_00322908 fn = (Fn_00322908) * (u32 *)(*(u32 *)obj + 4);
    fn(obj, s16);
}
}  // namespace n0031d840

// 0031d8a0 (was src/anon/batch_w58.cpp)
namespace n0031d8a0 {
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
void func_00239870(void*) asm("func_00239870");
extern u8 D_0034aad8[] asm("D_0034aad8");
void func_002361d0(void*) asm("func_002361d0");
/*TARGET 0031d8a0*/
void func_0031d8a0(u8* p) asm("func_0031d8a0");
void func_0031d8a0(u8* p) {
    *(void**)p = D_0034aad8;
    func_002361d0(p + 416);
    *(void**)p = D_00347e60;
    func_00239870(p + 24);
    *(void**)p = D_00347f98;
}
}  // namespace n0031d8a0

// 0031d8f8 (was src/anon/auto80_199_queue.cpp)
namespace n0031d8f8 {
/*TARGET 0031d8f8*/
// 0x003181a0: definition moved into src/libgcc/unwind-dw2.c

void func_0031d8f8(u32 self) asm("_Z13func_0031d8f8j");
// 0x003181a0: definition moved into src/libgcc/unwind-dw2.c

void func_0031d8f8(u32 self) {
    *(u32*)self = addr_D_0034aad8();
    func_002361d0(self + 416);
    *(u32*)self = addr_D_00347e60();
    func_00239870(self + 24);
    *(u32*)self = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_0031d8f8 fn = (Fn_0031d8f8)*(u32*)(*(u32*)obj + 4);
    fn(obj, self);
}
}  // namespace n0031d8f8

// 0031d968 (gap; copy of 0x0031a840, was src/anon/tiny.cpp)
namespace n0031d968 {
extern u32 D_00347f98 asm("D_00347f98");
/*TARGET 0031d968*/
// 0x00316e10: definition moved into src/libgcc/ee-gthr.c

void func_0031d968(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031d968");
// 0x00316e10: definition moved into src/libgcc/ee-gthr.c

void func_0031d968(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00347f98;
}
}  // namespace n0031d968

// 0031d978 (was src/anon/batch_w34.cpp)
namespace n0031d978 {
extern void* D_00347f98[] asm("D_00347f98");
extern void** D_00347f80 asm("D_00347f80");
/*TARGET 0031d978*/
void func_0031d978(void** p) asm("func_0031d978");
void func_0031d978(void** p) {
    *p = D_00347f98;
    void** o = (void**)D_00347f80[5];
    ((void (*)(void*, void*))((void**)*o)[1])(o, p);
}
}  // namespace n0031d978

// 0031d9b8 (was src/anon/auto80_199_queue.cpp)
namespace n0031d9b8 {
/*TARGET 0031d9b8*/
void func_0031d9b8(u32 self) asm("_Z13func_0031d9b8j");
void func_0031d9b8(u32 self) {
    *(u32*)self = addr_D_0034ab80();

    if (self != (u32)-440) {
        u32 end = self + 2848;
        u32 begin = self + 440;
        do {
            if (begin == end) {
                break;
            }
            end -= 344;
            Fn_0031d9b8 fn = (Fn_0031d9b8)*(u32*)(*(u32*)end + 0);
            fn(end);
        } while (1);
    }

    *(u32*)self = addr_D_00347e60();
    func_00239870(self + 24);
    *(u32*)self = addr_D_00347f98();
}
}  // namespace n0031d9b8

// 0031da48 (was src/anon/batch_w67.cpp)
namespace n0031da48 {
typedef void (*VFn)(void*);
extern u8 D_00347e60[] asm("D_00347e60");
typedef void (*VFn2)(void*, void*);
extern u8 D_00347f98[] asm("D_00347f98");
extern u8* D_00347f80 asm("D_00347f80");
void func_00239870(u8*) asm("func_00239870");
// 0x002ad110: definition moved into src/anon/unit_002a99c8.cpp

extern u8 D_0034ab80[] asm("D_0034ab80");
/*TARGET 0031da48*/
// 0031da48: destructor (seven 344-byte members with virtual destructors)
void func_0031da48(u8* o) asm("func_0031da48");
// 0031da48: destructor (seven 344-byte members with virtual destructors)
void func_0031da48(u8* o)
{
    *(u8**)o = D_0034ab80;
    if (o + 440) {
        u8* p = o + 2848;
        for (;;) {
            if (o + 440 == p) break;
            p -= 344;
            (**(VFn**)p)(p);
        }
    }
    *(u8**)o = D_00347e60;
    func_00239870(o + 24);
    *(u8**)o = D_00347f98;
    u8* m = *(u8**)(D_00347f80 + 20);
    (*(VFn2*)(*(u8**)m + 4))(m, o);
}
}  // namespace n0031da48

// 0031daf0 (was src/anon/auto80_199_queue.cpp)
namespace n0031daf0 {
/*TARGET 0031daf0*/
void func_0031daf0(u32 self) asm("_Z13func_0031daf0j");
void func_0031daf0(u32 self) {
    u32 s18 = self;
    u32 s16 = s18 + 880;
    s32 s17 = 3;
    s32 s19 = -1;

    func_0014ba90(s18);
    func_0013ee88(s18 + 336);
    func_0014b668(s18 + 624);

    do {
        func_0014b668(s16);
        s17 -= 1;
        s16 += 256;
    } while (s17 != s19);

    s16 = self + 1904;
    s17 = 3;
    s18 = (u32)-1;
    do {
        func_0014b668(s16);
        s17 -= 1;
        s16 += 256;
    } while (s17 != (s32)s18);
}
}  // namespace n0031daf0

// 0031db80 (was src/anon/batch_wcx2.cpp)
namespace n0031db80 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
// 0x002adfd0: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct AVt31db80 { void* alloc; void (*free)(void* self, void* p); };
struct AO31db80 { AVt31db80* vt; };
struct H31db80 { u8 pad[20]; AO31db80* al; };
union HU31db80 { H31db80* h; u32 u; };
extern HU31db80 D_00347f80_31db80 asm("D_00347f80");
extern u8 D_0034af08_31db80[] asm("D_0034af08");
extern u8 D_00349b40_31db80[] asm("D_00349b40");
extern u8 D_00347f98_31db80[] asm("D_00347f98");
struct E31db80;
struct EVt31db80 { void (*dtor)(E31db80*); };
struct E31db80 { EVt31db80* vt; u8 pad[252]; };
struct M31db80 { u32 vt; u8 pad[332]; u8 m336[288]; u8 m624[256]; E31db80 a[4]; E31db80 b[4]; };
struct O31db80 { u32 vt; u8 pad[44]; M31db80 m; };
/*TARGET 0031db80*/
void func_0031bbc8(u8*) asm("func_0031bbc8");
void func_0031b910(u8*) asm("func_0031b910");
void func_0031bb08(M31db80*) asm("func_0031bb08");
#define DELARR31db80(name, fld) \
static inline __attribute__((always_inline)) void name(M31db80* m) \
{ \
    if (m->fld != 0) { E31db80* p = m->fld + 4; E31db80* b = m->fld; for (;;) { if (b == p) break; --p; p->vt->dtor(p); } } \
}
DELARR31db80(DelB31db80, b)
DELARR31db80(DelA31db80, a)
static inline __attribute__((always_inline)) void DelM31db80(M31db80* m)
{
    DelB31db80(m);
    DelA31db80(m);
    func_0031bbc8(m->m624);
    func_0031b910(m->m336);
    m->vt = (u32)D_00349b40_31db80;
    func_0031bb08(m);
}

void func_0031db80(O31db80* o) asm("func_0031db80");
void func_0031db80(O31db80* o)
{
    o->vt = (u32)D_0034af08_31db80;
    DelM31db80(&o->m);
    o->vt = (u32)D_00347f98_31db80;
    AO31db80* al = D_00347f80_31db80.h->al;
    al->vt->free(al, o);
}
}  // namespace n0031db80

// 0031dc78 (was src/anon/batch_w89.cpp)
namespace n0031dc78 {
struct E256 { void (**vt)(E256*); u8 pad[252]; };
extern u8 D_0034af08[] asm("D_0034af08");
extern u8 D_00349b40[] asm("D_00349b40");
extern u8 D_00347f98[] asm("D_00347f98");
void func_0031bbc8(u8*) asm("func_0031bbc8");
// set_vtbl_348c08_b
void func_0031b910(u8*) asm("func_0031b910");
// set_vtbl_3486a8_d
void func_0031bb08(u8*) asm("func_0031bb08");
/*TARGET 0031dc78*/
// set_vtbl_3486a8
// Destructor body: own vtable, inlined member destructor (two arrays, members, base), base vtable.
void func_0031dc78(u8* o) asm("func_0031dc78");
// set_vtbl_3486a8
// Destructor body: own vtable, inlined member destructor (two arrays, members, base), base vtable.
void func_0031dc78(u8* o) {
    *(u32*)o = (u32)D_0034af08;
    u8* m = o + 48;
    if (m + 1904 != 0) {
        E256* p = (E256*)(m + 1904) + 4;
        E256* b = (E256*)(m + 1904);
    top1:
        if (b != p) { p--; p->vt[0](p); goto top1; }
    }
    if (m + 880 != 0) {
        E256* p = (E256*)(m + 880) + 4;
        E256* b = (E256*)(m + 880);
    top2:
        if (b != p) { p--; p->vt[0](p); goto top2; }
    }
    func_0031bbc8(m + 624);  // set_vtbl_348c08_b
    func_0031b910(m + 336);  // set_vtbl_3486a8_d
    *(u32*)m = (u32)D_00349b40;
    func_0031bb08(m);  // set_vtbl_3486a8
    *(u32*)o = (u32)D_00347f98;
}
}  // namespace n0031dc78

// 0031dd50 (was src/anon/auto80_199_queue.cpp)
namespace n0031dd50 {
/*TARGET 0031dd50*/
void func_0031dd50(u32 self) asm("_Z13func_0031dd50j");
void func_0031dd50(u32 self) {
    *(u8*)(self + 4) = 0;
    *(u32*)self = addr_D_0034b250();

    u32 s18 = self;
    u32 s16 = s18 + 1072;
    s32 s17 = 5;
    s32 s19 = -1;

    func_0014c5a0(s18 + 16);
    func_0014c5a0(s18 + 544);

    do {
        func_0014b668(s16);
        s17 -= 1;
        s16 += 256;
    } while (s17 != s19);

    s16 = s18 + 2608;
    s17 = 5;
    s19 = -1;
    do {
        func_0014b668(s16);
        s17 -= 1;
        s16 += 256;
    } while (s17 != s19);

    func_0014c050(s18 + 4144);
}
}  // namespace n0031dd50

// 0031ddf0 (gap)
namespace n0031ddf0 {
extern u32 D_0034b250 asm("D_0034b250");
extern u32 D_00348698 asm("D_00348698");
extern u32 D_0034b268 asm("D_0034b268");
typedef void (*DtorFn)(u8*);
/*TARGET 0031ddf0*/
// Destructor (0x31dee8 is the deleting one).
void func_0031ddf0(u8* a0) asm("func_0031ddf0");
void func_0031ddf0(u8* a0) {
    *(u32*)a0 = (u32)&D_0034b250;
    u8* end = a0 + 4144;
    *(u32*)end = (u32)&D_00348698;
    if (a0 + 2608) {
        u8* e = end;
    t1:
        if (a0 + 2608 != e) { e -= 256; (*(DtorFn*)*(u32*)e)(e); goto t1; }
    }
    if (a0 + 1072) {
        u8* e = a0 + 2608;
    t2:
        if (a0 + 1072 != e) { e -= 256; (*(DtorFn*)*(u32*)e)(e); goto t2; }
    }
    if (a0 + 544) {
        u8* e = a0 + 1072;
    t3:
        if (a0 + 544 != e) { e -= 528; (*(DtorFn*)*(u32*)e)(e); goto t3; }
    }
    *(u32*)(a0 + 16) = (u32)&D_00348698;
    *(u32*)a0 = (u32)&D_0034b268;
}
}  // namespace n0031ddf0

// 0031dee8 (was src/anon/batch_w253.cpp)
namespace n0031dee8 {
// 0x001bf270: definition moved into src/anon/unit_001bc568.cpp

extern u32 D_0034b250 asm("D_0034b250");
extern u32 D_00348698 asm("D_00348698");
extern u32 D_0034b268 asm("D_0034b268");
extern u32 D_0034b278 asm("D_0034b278");
struct VObj { void (**vt)(...); };
typedef void (*DtorFn)(u8*);
/*TARGET 0031dee8*/
void func_0031dee8(u8* a0) asm("func_0031dee8");
void func_0031dee8(u8* a0) {
    *(u32*)a0 = (u32)&D_0034b250;
    u8* end = a0 + 4144;
    *(u32*)end = (u32)&D_00348698;
    if (a0 + 2608) {
        u8* e = end;
    t1:
        if (a0 + 2608 != e) { e -= 256; (*(DtorFn*)*(u32*)e)(e); goto t1; }
    }
    if (a0 + 1072) {
        u8* e = a0 + 2608;
    t2:
        if (a0 + 1072 != e) { e -= 256; (*(DtorFn*)*(u32*)e)(e); goto t2; }
    }
    if (a0 + 544) {
        u8* e = a0 + 1072;
    t3:
        if (a0 + 544 != e) { e -= 528; (*(DtorFn*)*(u32*)e)(e); goto t3; }
    }
    *(u32*)(a0 + 16) = (u32)&D_00348698;
    *(u32*)a0 = (u32)&D_0034b268;
    VObj* o = (VObj*)D_0034b278;
    ((void (*)(VObj*, u8*))o->vt[1])(o, a0);
}
}  // namespace n0031dee8

// 0031dff8 (gap; copy of 0x0031b910, was src/anon/tiny.cpp)
namespace n0031dff8 {
extern u32 D_0034b268 asm("D_0034b268");
/*TARGET 0031dff8*/
void func_0031dff8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031dff8");
void func_0031dff8(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8_d
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_0034b268;
}
}  // namespace n0031dff8

// 0031e008 (was src/anon/batch_w14.cpp)
namespace n0031e008 {
extern u8 D_0034b268[] asm("D_0034b268");
extern void** D_0034b278 asm("D_0034b278");
/*TARGET 0031e008*/
// 0x00314b00: definition moved into src/libsupc++/eh_personality.cpp

void func_0031e008(u8* p) asm("func_0031e008");
// 0x00314b00: definition moved into src/libsupc++/eh_personality.cpp

void func_0031e008(u8* p) {
    *(u8**)p = D_0034b268;
    void** o = D_0034b278;
    (*(void (**)(void*, void*))(*(u8**)o + 4))(o, p);
}
}  // namespace n0031e008

// 0031e048 (gap)
namespace n0031e048 {
extern u8 D_00348698[] asm("D_00348698");
extern u8 D_00348d58[] asm("D_00348d58");
/*TARGET 0031e048*/
void func_0031e048(u8* p) asm("func_0031e048");
void func_0031e048(u8* p) {
    *(u8**)(p + 416) = D_00348698;
    *(u8**)(p + 144) = D_00348698;
    *(u8**)p = D_00348d58;
}
}  // namespace n0031e048

// 0031e068 (was src/anon/batch_w9.cpp)
namespace n0031e068 {
void func_00106420(void*) asm("func_00106420");
extern u8 D_00348d58[] asm("D_00348d58");
extern u8 D_00348698[] asm("D_00348698");
/*TARGET 0031e068*/
void func_0031e068(u8* p) asm("func_0031e068");
void func_0031e068(u8* p) {
    *(u8**)(p + 416) = D_00348698;
    *(u8**)(p + 144) = D_00348698;
    *(u8**)(p + 0) = D_00348d58;
    func_00106420(p);
}
}  // namespace n0031e068

// 0031e098 (gap)
namespace n0031e098 {
extern u8 D_00348698[] asm("D_00348698");
extern u8 D_00348d58[] asm("D_00348d58");
/*TARGET 0031e098*/
void func_0031e098(u8* p) asm("func_0031e098");
void func_0031e098(u8* p) {
    *(u8**)(p + 80) = D_00348698;
    *(u8**)p = D_00348d58;
}
}  // namespace n0031e098

// 0031e0b8 (was src/anon/batch_w10.cpp)
namespace n0031e0b8 {
void func_00106420(void*) asm("func_00106420");
extern u8 D_00348d58 asm("D_00348d58");
extern u8 D_00348698 asm("D_00348698");
/*TARGET 0031e0b8*/
void func_0031e0b8(u8* p) asm("func_0031e0b8");
void func_0031e0b8(u8* p) {
    *(void**)(p + 80) = &D_00348698;
    *(void**)p = &D_00348d58;
    func_00106420(p);
}
}  // namespace n0031e0b8

// 0031e0e8 (gap; copy of 0x001b0188, was src/anon/unit_001ada38.cpp)
namespace n0031e0e8 {
u32 func_00160268(u32, u32, u32, u32) asm("_Z13func_00160268jjjj");
extern u8 D_0034c720 asm("D_0034c720");
u32 func_0031e0e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031e0e8");
/*TARGET 0031e0e8*/
u32 func_0031e0e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031e0e8");
u32 func_0031e0e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_0034c720;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00160268)(u32, u32, u32, u32) = func_00160268;
    r2 = fp_call4_00160268(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0031e0e8

// 0031e110 (was src/anon/batch_w25.cpp)
namespace n0031e110 {
struct VObj { void (**vt)(...); };
typedef void (*VFn)(void*, void*);
extern u8 D_0034c720 asm("D_0034c720");
extern VObj* D_0034c738 asm("D_0034c738");
void func_00160268(void*) asm("func_00160268");
/*TARGET 0031e110*/
void func_0031e110(u32* o) asm("func_0031e110");
void func_0031e110(u32* o) {
    o[0] = (u32)&D_0034c720;
    func_00160268(o);
    VObj* m = D_0034c738;
    ((VFn)m->vt[1])(m, o);
}
}  // namespace n0031e110

// 0031e158 (was src/anon/batch_w239.cpp)
namespace n0031e158 {
// 0x001c97b0: definition moved into src/yasui/libys/sacrifice.cpp

void func_00108698(void*) asm("func_00108698");
void func_00144450(void*) asm("func_00144450");
void func_0011b6a8(void*) asm("func_0011b6a8");
/*TARGET 0031e158*/
void func_0031e158(u32* a) asm("func_0031e158");
void func_0031e158(u32* a) {  // obj_init_large
    u8* s = (u8*)a;
    a[0] = 0;
    func_00108698(s + 8);
    func_00144450(s + 208);
    *(u32*)(s + 244) = 0;
    *(u32*)(s + 240) = 0;
    *(f32*)(s + 264) = 2100.0f;
    s[232] = 0x80;
    s[233] = 0x80;
    s[234] = 0x80;
    s[235] = 0x80;
    *(u32*)(s + 248) = 0;
    *(u32*)(s + 252) = 0;
    *(u32*)(s + 256) = 0;
    *(u32*)(s + 260) = 0;
    s[269] = 0;
    *(u32*)(s + 272) = 0;
    *(u32*)(s + 276) = 0;
    *(u16*)(s + 280) = 0;
    *(u16*)(s + 282) = 0;
    s[286] = 0;
    s[287] = 0;
    *(u32*)(s + 288) = 0;
    s[271] = 0;
    s[270] = 0;
    func_0011b6a8(s + 64);
    func_0011b6a8(s + 128);
    *(u32*)(s + 248) = 2060;
}
}  // namespace n0031e158

// 0031e208 (was src/anon/batch_w41.cpp)
namespace n0031e208 {
/*TARGET 0031e208*/
void func_0031e208(u32, u8* p, u32* flags, u32 v, u8* src) asm("func_0031e208");
void func_0031e208(u32, u8* p, u32* flags, u32 v, u8* src) {  // gpr_field_update
    if (*(u64*)(p + 112) & 0x78) return;
    if (*flags & 0x800) {
        u8* d = p + 64;
        *(u16*)(p + 98) = v;
        if (d != src) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(src) : "$8", "memory");

    }
    if (*flags & 0x1000) {
        u8* d = p + 80;
        *(u16*)(p + 100) = v;
        if (d != src) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(src) : "$8", "memory");
    }
}
}  // namespace n0031e208
