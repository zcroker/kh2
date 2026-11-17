// Linked unit (extracted from the matched per-function sources).
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../harata/libdk/mapcolor.hpp"
#include "tiny_auto80_solver_structs.hpp"

// ---- 0x0015cb18 (src/anon/auto200_999.cpp)
namespace n0015cb18 {
extern u8 D_004f36a8 asm("D_004f36a8");
void func_0015cb18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   u32 a7) asm("func_0015cb18");
void func_0015cb18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   u32 a7) {
    u8 *p = (u8 *)&D_004f36a8;
    *(u8 *)a0 = p[0];
    *(u8 *)a1 = p[1];
    *(u8 *)a2 = p[2];
    *(u8 *)a3 = p[3];
}
}  // namespace n0015cb18

// ---- 0x0015cb48 (src/anon/tiny_auto80_solver.cpp)
namespace n0015cb48 {
extern u8 D_004f3700 asm("D_004f3700");
void func_0015cb48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0015cb48");
void func_0015cb48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u8* p = (u8*)&D_004f3700;
    *(u8*)a0 = p[0];
    *(u8*)a1 = p[1];
    *(u8*)a2 = p[2];
    *(u8*)a3 = p[3];
}
}  // namespace n0015cb48

// ---- 0x0015cb78 (src/anon/auto200_999.cpp)
namespace n0015cb78 {
extern u8 D_004f3700 asm("D_004f3700");
void dk_MapColor_getOnColorTable(u32, u32) asm(
    "_ZN2dk8MapColor15getOnColorTableEPhi");
void dk_MapColor_getOnColorTable(u32 a0, u32 a1) asm("_ZN2dk8MapColor15getOnColorTableEPhi");
void dk_MapColor_getOnColorTable(u32 a0, u32 a1) {
    u8 *p = (u8 *)((u32)&D_004f3700 + (a1 << 2));
    *(u8 *)a0 = p[4];
    a0 += 1;
    *(u8 *)a0 = p[5];
    a0 += 1;
    *(u8 *)a0 = p[6];
    *(u8 *)(a0 + 1) = p[7];
}
}  // namespace n0015cb78

// ---- 0x0015cbb8 (src/anon/batch_w10.cpp)
namespace n0015cbb8 {
extern struct { u8 a, b, c, d; } D_004f3700 asm("D_004f3700");
void func_0015cbb8(u8 a, u8 b, u8 c, u8 d) asm("func_0015cbb8");
void func_0015cbb8(u8 a, u8 b, u8 c, u8 d) {  // set_global_rgba
    D_004f3700.a = a;
    D_004f3700.b = b;
    D_004f3700.c = c;
    D_004f3700.d = d;
}
}  // namespace n0015cbb8

// ---- 0x0015cbe8 (gap, written here)
namespace n0015cbe8 {
extern struct { u8 a, b, c, d; } D_004f36a8 asm("D_004f36a8");
extern "C" void func_0015cbe8(u8 a, u8 b, u8 c, u8 d) {
    D_004f36a8.a = a;
    D_004f36a8.b = b;
    D_004f36a8.c = c;
    D_004f36a8.d = d;
}
}

// ---- 0x0015cc18 (src/anon/batch_w12.cpp)
namespace n0015cc18 {
struct Rgba { u8 r, g, b, a; };
extern Rgba D_004f3704[] asm("D_004f3704");
void func_0015cc18(s32 i, u8 r, u8 g, u8 b, u8 a) asm("func_0015cc18");
void func_0015cc18(s32 i, u8 r, u8 g, u8 b, u8 a) {
    Rgba* c = &D_004f3704[i];
    c->r = r; c->g = g; c->b = b; c->a = a;
}
}  // namespace n0015cc18

// ---- 0x0015cc50 (src/anon/tiny.cpp)
namespace n0015cc50 {
extern u32 D_004f3744 asm("D_004f3744");
u32 func_0015cc50(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0015cc50");
u32 func_0015cc50(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_004f3744;
}
}  // namespace n0015cc50

// ---- 0x0015cc60 (src/anon/tiny.cpp)
namespace n0015cc60 {
extern u32 D_004f36ec asm("D_004f36ec");
u32 func_0015cc60(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0015cc60");
u32 func_0015cc60(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_004f36ec;
}
}  // namespace n0015cc60

// ---- 0x0015cc70 (src/harata/libdk/mapcolor.cpp)
namespace n0015cc70 {
extern u32 D_004f3694 asm("D_004f3694");
// dk::MapColor::getFogDefault
void* getFogDefault() asm("_ZN2dk8MapColor13getFogDefaultEv");
void* getFogDefault() { return &D_004f3694; }
}

// ---- 0x0015cc80 (src/anon/batch_w44.cpp)
namespace n0015cc80 {
extern u8 D_00340eb0 asm("D_00340eb0");
s32 func_0015cc80(u8* p) asm("func_0015cc80");
s32 func_0015cc80(u8* p) {  // test_float12_zero_and_bits
    if (*(f32*)(p + 12) == 0.0f && *(f32*)(p + 16) == 255.0f && (*(u32*)p & 0xffffff) == 0x808080) {
        D_00340eb0 = 0;
        return 1;
    }
    D_00340eb0 = 1;
    return 0;
}
}  // namespace n0015cc80

// ---- 0x0015ccf0 (src/anon/batch_w65.cpp)
namespace n0015ccf0 {
struct FadeEnt { u32 pad[3]; u32 count; f32 alpha; };
extern FadeEnt D_004f3694 asm("D_004f3694");
extern FadeEnt D_004f36ec asm("D_004f36ec");
extern FadeEnt D_004f3744 asm("D_004f3744");
void wtarget_0015ccf0(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_0015ccf0jjjj");
void wtarget_0015ccf0(u32 a, u32 b, u32 c, u32 d) {
    if (b == 0xffff && a == 1) { D_004f3694.count = 0; D_004f3694.alpha = 255.0f; }
    if (b == 0xffff && a == 1) { D_004f36ec.count = 0; D_004f36ec.alpha = 255.0f; }
    if (b == 0xffff && a == 1) { D_004f3744.count = 0; D_004f3744.alpha = 255.0f; }
}
}  // namespace n0015ccf0

// ---- 0x0015cd90 (src/anon/tiny_wrappers_more.cpp)
namespace n0015cd90 {
u32 func_0015ccf0(u32, u32, u32, u32) asm("func_0015ccf0");
u32 func_0015cd90(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0015cd90");
u32 func_0015cd90(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0015ccf0(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n0015cd90
