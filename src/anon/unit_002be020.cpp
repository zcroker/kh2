#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/menu_sound.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../worldmap/libretto.hpp"
#include "../worldmap/rootwindow.hpp"
#include "../worldmap/messagewidget.hpp"
#include "../ohori/sebank.hpp"

// ---- 002be020 from src/anon/auto80_199_queue.cpp
namespace n002be020 {
u32 func_002be020(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002be020jjjjjjjj");
u32 func_002be020(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s17 = a0;
    u32 s19 = a1;
    u32 s18 = a2;

    worldmap__Libretto__leaveObj(s17);

    if (func_002be5b8(s17) == 0) {
        dk__Map__noDrawAll();
    }

    u32 s16 = func_001050d8(560);
    func_002c1f08(s16, s18 | 0x40000000);

    u32 off = s19 << 2;
    off = off + s17;
    *(u32*)(off + 44) = s16;

    return func_002edfa8(s17 + 8, s16);
}
}  // namespace n002be020

// ---- 002be0b0 from src/anon/batch_w51.cpp
namespace n002be0b0 {
typedef void (*VFn)(void*);
void func_002edfd8(void*, void*) asm("func_002edfd8");
s32 func_002be5b8(void*) asm("func_002be5b8");
void func_0015f548(void) asm("func_0015f548");
void func_001c8e90(void) asm("func_001c8e90");
void func_002be9b0(void) asm("func_002be9b0");
void worldmap__Libretto__leaveObj(u8* p, s32 i) asm("worldmap__Libretto__leaveObj");
void worldmap__Libretto__leaveObj(u8* p, s32 i) {
    u8** slot = (u8**)((u8*)(i * 4) + (u32)p + 44);
    if (*slot) {
        func_002edfd8(p + 8, *slot);
        if (*slot) (*(VFn*)(*(u8**)*slot + 4))(*slot);
        *slot = 0;
    }
    if (!func_002be5b8(p)) {
        func_0015f548();
        func_001c8e90();
        func_002be9b0();
    }
}
}  // namespace n002be0b0

// ---- 002be148 from src/worldmap/libretto.cpp
void worldmap__Libretto__leaveObj(...) asm("worldmap__Libretto__leaveObj");
namespace worldmap {
void Libretto::leaveAllObj() {
    s32 i = 0;
    do {
        worldmap__Libretto__leaveObj(this, (u32)i);
        i += 1;
    } while (i < 4);
}
}  // namespace worldmap

// ---- 002be190 from src/anon/batch_w81.cpp
namespace n002be190 {
u8* func_00168b38(u32, s32, u32) asm("func_00168b38");
void func_002eedc0(u32, u32, f32) asm("func_002eedc0");
void func_002eedd8(u32, u32, f32) asm("func_002eedd8");
void func_002be190(u8* o, s32 idx, u32* list, s32 n) asm("func_002be190");
void func_002be190(u8* o, s32 idx, u32* list, s32 n) {
    u32 t = ((u32*)(o + 44))[idx];
    func_002eedc0(t, *(u32*)(func_00168b38(*(u32*)(o + 104), -1, list[0]) + 8), 0.0f);
    s32 i;
    for (i = 1; i < n; i++) {
        func_002eedd8(t, *(u32*)(func_00168b38(*(u32*)(o + 104), -1, list[i]) + 8), 0.0f);
    }
}
}  // namespace n002be190

// ---- 002be258 from src/anon/auto80_199_queue.cpp
namespace n002be258 {
void func_002be258(u32 a0, u32 a1, u32 a2, s32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002be258jjjijjjj");
void func_002be258(u32 a0, u32 a1, u32 a2, s32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 off = a1 << 2;
    off = off + a0;

    u32 s19 = a0;
    u32 s18 = *(u32*)(off + 44);

    if (a3 <= 0) {
        return;
    }

    u32 s17 = a2;
    s32 s16 = a3;
    u32 a2v = *(u32*)s17;

L290:
    u32 h = func_00168b38(*(u32*)(s19 + 104), -1, a2v);
    s16 = s16 - 1;
    s17 = s17 + 4;
    func_002eedd8(s18, *(u32*)(h + 8), 0.0f);
    if (s16 != 0) {
        a2v = *(u32*)s17;
        goto L290;
    }
}
}  // namespace n002be258

// ---- 002be2d8 from src/anon/batch_w205.cpp
namespace n002be2d8 {
struct V205 { f32 x, y, z, w; };
struct O205 { char pad[544]; V205 v; };
void func_002be2d8(char* a0, s32 a1, V205* a2) asm("func_002be2d8");
void func_002be2d8(char* a0, s32 a1, V205* a2) {
    O205* o = *(O205**)(a0 + a1 * 4 + 44);
    o->v.x = a2->x;
    V205* q = &o->v;
    q->y = a2->y;
    q->z = a2->z;
    q->w = 1.0f;
}
}  // namespace n002be2d8

// ---- 002be318 from src/anon/tiny_auto80_queue.cpp
namespace n002be318 {
void func_002be318(u32 a0, u32 a1, kn::FVector* a2) asm("_Z13func_002be318jjPN2kn7FVectorE");
void func_002be318(u32 a0, u32 a1, kn::FVector* a2) {
    u32 p = (a1 << 2) + a0;
    kn::FVector* dst = (kn::FVector*)(*(u32*)(p + 44) + 0x210);
    *dst = *a2;
}
}  // namespace n002be318

// ---- 002be340 from src/anon/batch_w43.cpp
namespace n002be340 {
void* func_001050d8(u32) asm("func_001050d8");
void func_002bd998(void*, u32) asm("func_002bd998");
u8* func_00102c48(s32, s32, void*, s32) asm("func_00102c48");
void func_002be3a8(void) asm("func_002be3a8");
void task_end_002be3c8(void*) asm("_ZN8worldmap8Libretto14finalizeThreadEP4TASK");
void func_002be428(void) asm("func_002be428");
void func_00102c18(s32, s32, void*) asm("func_00102c18");
void func_002be340(u32 a) asm("func_002be340");
void func_002be340(u32 a) {
    void* o = func_001050d8(108);
    func_002bd998(o, a);
    u8* r = func_00102c48(1, 15000, (void*)func_002be3a8, 8192);
    *(void**)(r + 48) = (void*)task_end_002be3c8;
    func_00102c18(1, 61000, (void*)func_002be428);
}
}  // namespace n002be340

// ---- 002be3a8 from src/anon/tiny_wrappers_imp.cpp
namespace n002be3a8 {
u32 func_002bdb58(u32, u32, u32, u32) asm("_Z13func_002bdb58jjjj");
u32 func_002be3a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002be3a8jjjj");
u32 func_002be3a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r5 = r4;
    r15 = (u32)(0x0036u << 16);
    r4 = *(u32*)((u32)r15 + (s32)(6140));
    return func_002bdb58(r4, r5, r6, r7);
}
}  // namespace n002be3a8

// ---- 002be3c8 from src/anon/tiny_auto80_queue.cpp
namespace n002be3c8 {
u32 func_00105110(...) asm("func_00105110");
u32 func_002bdac8(...) asm("func_002bdac8");
void func_002be3c8(u32 a0) asm("_Z13func_002be3c8j");
void func_002be3c8(u32 a0) {
    u32 r4 = a0, r15, r16;
    r15 = (u32)(0x0036u << 16);
    r16 = *(u32*)((u32)r15 + (s32)(6140));
    r4 = r16;
    if (r16 != 0u) {
    u32 (*fp_call4_002bdac8)(u32) = (u32(*)(u32))func_002bdac8;
        ((void(*)(u32))fp_call4_002bdac8)(r4);
        r4 = r16;
    u32 (*fp_call4_00105110)(u32) = (u32(*)(u32))func_00105110;
        ((void(*)(u32))fp_call4_00105110)(r4);
    }
}
}  // namespace n002be3c8

// ---- 002be408 from src/anon/tiny_wrappers_imp.cpp
namespace n002be408 {
u32 worldmap__Libretto__parse(u32, u32, u32, u32) asm("_Z25worldmap__Libretto__parsejjjj");
u32 func_002be408(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002be408jjjj");
u32 func_002be408(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r5 = r4;
    r15 = (u32)(0x0036u << 16);
    r4 = *(u32*)((u32)r15 + (s32)(6140));
    return worldmap__Libretto__parse(r4, r5, r6, r7);
}
}  // namespace n002be408

// ---- 002be428 from src/anon/batch_w1521.cpp
namespace n002be428 {
u32 func_001024a8(...) asm("func_001024a8");
struct W1521Pos { s32 x, y; W1521Pos(s32 a, s32 b) : x(a), y(b) {} };
struct W1521Col { u8 r, g, b, a; W1521Col(s32 a0, s32 a1, s32 a2, s32 a3) : r(a0), g(a1), b(a2), a(a3) {} };
struct W1521Holder { s32 a, b; u8 sub[4]; };
void func_002ee040(void*) asm("func_002ee040");
void func_002ee0b0(void*, W1521Pos, W1521Col) asm("func_002ee0b0");
extern W1521Holder* D_003617fc asm("D_003617fc");
void func_002be428(void* a0) asm("func_002be428");
void func_002be428(void* a0) {
    if (D_003617fc == 0) {
        func_001024a8(a0);
        return;
    }
    func_002ee040(D_003617fc->sub);
    func_002ee0b0(D_003617fc->sub, W1521Pos(0, 0), W1521Col(128, 128, 128, 128));
}
}  // namespace n002be428

// ---- 002be4a0 from src/worldmap/libretto.cpp
namespace worldmap {
extern u32 D_003617fc asm("D_003617fc");
bool Libretto::isExec() { return D_003617fc != 0; }
}  // namespace worldmap

extern "C" const char D_00374fe8[] = "libretto/%s/wm%d.bar";
extern "C" const char D_00375000[] = "us";

// ---- 002be4b0 from src/anon/batch_w40.cpp
namespace n002be4b0 {
s32 func_00105c30(void) asm("func_00105c30");
void func_002fee78(u32*, const char*, const char*, u32) asm("func_002fee78");
void func_00170518(u32*, s32, u32) asm("func_00170518");
void func_00170888(u32) asm("func_00170888");
extern char D_00375000[] asm("D_00375000");
extern char D_00374fe8[] asm("D_00374fe8");
extern const char* D_0033caf4 asm("D_0033caf4");
void worldmap__Libretto__flush(u32* p) asm("worldmap__Libretto__flush");
void worldmap__Libretto__flush(u32* p) {
    const char* s = func_00105c30() == 8 ? D_00375000 : D_0033caf4;
    func_002fee78(p + 16, D_00374fe8, s, p[0]);
    func_00170518(p + 16, -200, 0);
    func_00170888(0);
}
}  // namespace n002be4b0

// ---- 002be520 from src/worldmap/libretto.cpp
void func_00170dd0(...) asm("func_00170dd0");
extern void* YS_CACHE_BUFF_Alloc(char const*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");
namespace worldmap {
void Libretto::waitFlush() {
    u8* s0 = (u8*)this;
    u32 t7 = *(u32*)(s0 + 4);
    func_00170dd0(*(u32*)(t7 + 16));
    s8 t = *(s8*)(s0 + 64);
    if (t != 0) {
        u32 v = (u32)YS_CACHE_BUFF_Alloc((char const*)(s0 + 64), -1);
        *(u32*)(s0 + 104) = v;
    }
}
}  // namespace worldmap

// ---- 002be568 from src/anon/batch_w24.cpp
namespace n002be568 {
void func_002baa60(u8*) asm("func_002baa60");
u32* func_00168b38(u32, s32, u32) asm("func_00168b38");
void func_002baa08(u32, u32, s32, s32) asm("func_002baa08");
void func_002be568(u8* p, u32 x) asm("func_002be568");
void func_002be568(u8* p, u32 x) {
    func_002baa60(p);
    u32* r = func_00168b38(*(u32*)(p + 104), -1, x);
    func_002baa08(r[2], r[3], 16383, 64);
}
}  // namespace n002be568

// ---- 002be5b8 from src/worldmap/libretto.cpp
namespace worldmap {
u32 Libretto::isExistObj() {
    s32 i = 0;
    u32* p = (u32*)(D_003617fc + 44);
    while (true) {
        if (*p != 0) {
            return 1;
        }
        p += 1;
        i += 1;
        if (i < 4) {
            continue;
        }
        return 0;
    }
}
}  // namespace worldmap

// ---- 002be5f8 from src/anon/tiny_auto80_queue.cpp
namespace n002be5f8 {
extern u32 D_003617fc asm("D_003617fc");
u32 func_002be5b8() asm("_Z13func_002be5b8v");
u32 func_002be5f8() asm("_Z13func_002be5f8v");
u32 func_002be5f8() {
    u32 t6 = D_003617fc;
    u32 v0 = 0;
    if (t6 != 0) {
        v0 = ((u32(*)(u32))func_002be5b8)(t6);
        v0 = (v0 != 0);
    }
    return v0;
}
}  // namespace n002be5f8

// ---- 002be630 from src/anon/batch_w1790_gnsa.cpp
namespace n002be630 {
struct W1790V4 { f32 x, y, z, w; };
void func_0017f488(int, int, float, float) asm("_Z13func_0017f488iiff");
s32 func_0016b740(s32) asm("func_0016b740");
void YS__OBJ__attach(u32, u32, u32, u32) asm("_Z15YS__OBJ__attachjjjj");
void wtarget_0016b070(u32, W1790V4*) asm("_Z16wtarget_0016b070jjjj");
void func_002fd188(void (*)()) asm("func_002fd188");
void D_002be6e8() asm("D_002be6e8");
extern s8 D_01e2bc20 asm("D_01e2bc20");
extern W1790V4 D_01e2bc30 asm("D_01e2bc30");
extern s32 D_0034e948 asm("D_0034e948");
void func_002be630(void) asm("func_002be630");
void func_002be630(void) {
    s32 v = func_0016b740(931);
    s32 o = D_0034e948;
    YS__OBJ__attach(o, v, 0x4002, 0);

    if (!D_01e2bc20) {
        D_01e2bc20 = 1;
        D_01e2bc30.x = D_01e2bc30.z = D_01e2bc30.w = 0.0f;
        D_01e2bc30.y = 3.14159274f;
        func_002fd188(D_002be6e8);
    }
    wtarget_0016b070(o, &D_01e2bc30);
    func_0017f488(o + 320, 156, 0.0f, 0.0f);
}
}  // namespace n002be630

// ---- 002be6e8 gap
namespace n002be6e8 {
void func_002be6e8(void) asm("func_002be6e8");
void func_002be6e8(void) {
}
}  // namespace n002be6e8

// ---- 002be6f0 from src/anon/tiny_auto80_fptr0.cpp
namespace n002be6f0 {
u32 func_002ba390() asm("_Z13func_002ba390v");
u32 func_002f1808() asm("_Z13func_002f1808v");
u32 func_002c23f0() asm("_Z13func_002c23f0v");
u32 func_002be6f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002be6f0jjjj");
u32 func_002be6f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r14, r15;
    r14 = (u32)((s32)0u + (1));
    r15 = (u32)(0x0036u << 16);
    *(u8*)((u32)r15 + (s32)(6144)) = (u8)r14;
    u32 (*fp_call0_002ba390)() = func_002ba390;
    r2 = fp_call0_002ba390();
    u32 (*fp_call0_002f1808)() = func_002f1808;
    r2 = fp_call0_002f1808();
    return func_002c23f0();
}
}  // namespace n002be6f0

// ---- 002be720 from src/anon/tiny_auto80_fptr0.cpp
namespace n002be720 {
u32 func_002c2458() asm("_Z13func_002c2458v");
u32 func_002f1850() asm("_Z13func_002f1850v");
u32 func_002be720(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002be720jjjj");
u32 func_002be720(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    u32 (*fp_call0_002f1850)() = func_002f1850;
    r2 = fp_call0_002f1850();
    u32 (*fp_call0_002c2458)() = func_002c2458;
    r2 = fp_call0_002c2458();
    r15 = (u32)(0x0036u << 16);
    *(u8*)((u32)r15 + (s32)(6144)) = (u8)0u;
    return r2;
}
}  // namespace n002be720

// ---- 002be750 from src/anon/batch_w1666.cpp
namespace n002be750 {
extern s8 D_00361800 asm("D_00361800");
u32 func_002be750(void) asm("func_002be750");
u32 func_002be750(void) { return D_00361800 != 0; }
}  // namespace n002be750

// ---- 002be760 from src/anon/tiny.cpp
namespace n002be760 {
void func_002be760(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002be760jjjj");
void func_002be760(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)((u32)a0 + (428)) = (u8)v;
}
}  // namespace n002be760

// ---- 002be770 from src/anon/batch_w27.cpp
namespace n002be770 {
void func_00185ed8(void*, u32, u32, u32) asm("func_00185ed8");
extern u32 D_00361810 asm("D_00361810");
void func_002be770(u8* p, u32 a, u32 b) asm("func_002be770");
void func_002be770(u8* p, u32 a, u32 b) {
    func_00185ed8(p, a, 4, b);
    *(void**)p = &D_00361810;
    *(u32*)(p + 1416) |= 0x40000000;
}
}  // namespace n002be770

// ---- 002be7b8 from src/anon/batch_w28.cpp
namespace n002be7b8 {
void func_00185ed8(void*, u32, u32, u32) asm("func_00185ed8");
extern u8 D_00361810[] asm("D_00361810");
void func_002be7b8(u8* p, u32 a, u32 b) asm("func_002be7b8");
void func_002be7b8(u8* p, u32 a, u32 b) {
    func_00185ed8(p, a, 4, b);
    *(void**)p = D_00361810;
    *(u32*)(p + 0x588) |= 0x40000000;
}
}  // namespace n002be7b8

// ---- 002be800 from src/anon/batch_w98.cpp
namespace n002be800 {
u8* func_001050d8(u32) asm("func_001050d8");
void func_002bf468(u8*, u8*, u32, f32) asm("func_002bf468");
void func_002c1aa0(u8*, u8*, u32, f32) asm("func_002c1aa0");
void func_002c54c8(u8*, u8*, u32, f32) asm("func_002c54c8");
u8* func_002c5ed8(u8*, u32, f32) asm("func_002c5ed8");
u8* worldmap__Obj__appear(u8* d, u32 a, f32 f) asm("worldmap__Obj__appear");
u8* worldmap__Obj__appear(u8* d, u32 a, f32 f) {
    switch (d[5]) {
    case 0:
        {
            u8* p = func_001050d8(2832);
            func_002bf468(p, d, a, f);
            return p;
        }
    case 1:
        {
            u8* p = func_001050d8(2800);
            func_002c1aa0(p, d, a, f);
            return p;
        }
    case 2:
        return func_002c5ed8(d, a, f);
    case 3:
        {
            u8* p = func_001050d8(2560);
            func_002c54c8(p, d, a, f);
            return p;
        }
    }
    return 0;
}
}  // namespace n002be800

// ---- 002be908 from src/anon/batch_w1756.cpp
namespace n002be908 {
void* YS__OBJ__Each(void*) asm("_Z13YS__OBJ__Eachjjjj");
void* func_002be908(void* p) asm("func_002be908");
void* func_002be908(void* p)
{
    while ((p = YS__OBJ__Each(p)) != 0) {
        if (*(u32*)((u8*)p + 0x588) & 0x40000000) return p;
    }
    return 0;
}
}  // namespace n002be908

// ---- 002be960 from src/anon/batch_w25.cpp
namespace n002be960 {
struct VObj { void (**vt)(...); };
VObj* func_002be908(VObj*) asm("func_002be908");
void func_002be960(void) asm("func_002be960");
void func_002be960(void) {
    VObj* o = 0;
    while ((o = func_002be908(o)) != 0) ((void (*)(VObj*))o->vt[32])(o);
}
}  // namespace n002be960

// ---- 002be9b0 from src/anon/batch_w34.cpp
namespace n002be9b0 {
void* func_002be908(void*) asm("func_002be908");
void func_002c1dc0(void) asm("func_002c1dc0");
typedef void (*VFn)(void*);
void func_002be9b0(void) asm("func_002be9b0");
void func_002be9b0(void) {
    void* o = 0;
    while ((o = func_002be908(o)) != 0) (*(VFn*)(*(u8**)o + 124))(o);
    func_002c1dc0();
}
}  // namespace n002be9b0

// ---- 002bea00 from src/anon/tiny.cpp
namespace n002bea00 {
void worldmap__Manager__readPackEnable(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z33worldmap__Manager__readPackEnablejjjj");
void worldmap__Manager__readPackEnable(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u8*)((u32)b + (6297)) = (u8)0;
}
}  // namespace n002bea00

// ---- 002bea10 from src/anon/tiny.cpp
namespace n002bea10 {
extern u32 D_00361899 asm("D_00361899");
void func_002bea10(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002bea10jjjj");
void func_002bea10(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_00361899 = (u8)v;
}
}  // namespace n002bea10

// model names (the .data table 0x3618a0 points to them)
extern "C" const char D_00375008[] = "obj/WM_CURSOR.mdlx";
extern "C" const char D_00375020[] = "obj/WM_SYMBOL_TT.mdlx";
extern "C" const char D_00375038[] = "obj/WM_SYMBOL_HB.mdlx";
extern "C" const char D_00375050[] = "obj/WM_SYMBOL_MU.mdlx";
extern "C" const char D_00375068[] = "obj/WM_SYMBOL_BB.mdlx";
extern "C" const char D_00375080[] = "obj/WM_SYMBOL_HE.mdlx";
extern "C" const char D_00375098[] = "obj/WM_SYMBOL_DC.mdlx";
extern "C" const char D_003750b0[] = "obj/WM_SYMBOL_LM.mdlx";
extern "C" const char D_003750c8[] = "obj/WM_SYMBOL_CA.mdlx";
extern "C" const char D_003750e0[] = "obj/WM_SYMBOL_NM.mdlx";
extern "C" const char D_003750f8[] = "obj/WM_SYMBOL_AL.mdlx";
extern "C" const char D_00375110[] = "obj/WM_SYMBOL_LK.mdlx";
extern "C" const char D_00375128[] = "obj/WM_SYMBOL_EH.mdlx";
extern "C" const char D_00375140[] = "obj/WM_GUMI_01.mdlx";
extern "C" const char D_00375158[] = "obj/WM_CURSOR.a.fm";
extern "C" const char D_00375170[] = "obj/WM_SYMBOL_TT.a.fm";
extern "C" const char D_00375188[] = "obj/WM_SYMBOL_HB.a.fm";
extern "C" const char D_003751a0[] = "obj/WM_SYMBOL_MU.a.fm";
extern "C" const char D_003751b8[] = "obj/WM_SYMBOL_BB.a.fm";
extern "C" const char D_003751d0[] = "obj/WM_SYMBOL_HE.a.fm";
extern "C" const char D_003751e8[] = "obj/WM_SYMBOL_DC.a.fm";
extern "C" const char D_00375200[] = "obj/WM_SYMBOL_LM.a.fm";
extern "C" const char D_00375218[] = "obj/WM_SYMBOL_CA.a.fm";
extern "C" const char D_00375230[] = "obj/WM_SYMBOL_NM.a.fm";
extern "C" const char D_00375248[] = "obj/WM_SYMBOL_AL.a.fm";
extern "C" const char D_00375260[] = "obj/WM_SYMBOL_LK.a.fm";
extern "C" const char D_00375278[] = "obj/WM_SYMBOL_EH.a.fm";
extern "C" const char D_00375290[] = "obj/WM_GUMI_01.a.fm";
extern "C" const char D_003752a8[] = "obj/WM_CURSOR.mset";
extern "C" const char D_003752c0[] = "obj/WM_SYMBOL_TT.mset";
extern "C" const char D_003752d8[] = "obj/WM_SYMBOL_HB.mset";
extern "C" const char D_003752f0[] = "obj/WM_SYMBOL_MU.mset";
extern "C" const char D_00375308[] = "obj/WM_SYMBOL_BB.mset";
extern "C" const char D_00375320[] = "obj/WM_SYMBOL_HE.mset";
extern "C" const char D_00375338[] = "obj/WM_SYMBOL_DC.mset";
extern "C" const char D_00375350[] = "obj/WM_SYMBOL_LM.mset";
extern "C" const char D_00375368[] = "obj/WM_SYMBOL_CA.mset";
extern "C" const char D_00375380[] = "obj/WM_SYMBOL_NM.mset";
extern "C" const char D_00375398[] = "obj/WM_SYMBOL_AL.mset";
extern "C" const char D_003753b0[] = "obj/WM_SYMBOL_LK.mset";
extern "C" const char D_003753c8[] = "obj/WM_SYMBOL_EH.mset";
extern "C" const char D_003753e0[] = "npack/worldobj.bar";

// ---- 002bea20 from src/anon/tiny_auto80_queue.cpp
namespace n002bea20 {
extern u8  func_003618a0 asm("func_003618a0");
extern u8  func_003753e0 asm("func_003753e0");
extern u8  D_00361899 asm("D_00361899");
void func_00170570(...) asm("func_00170570");
void func_002bea20() asm("_Z13func_002bea20v");
void func_002bea20() {
    if (D_00361899 != 1) {
        func_00170570((u32)&func_003753e0, (u32)&func_003618a0, 0);
    }
}
}  // namespace n002bea20

// ---- 002bea60 from src/anon/tiny_auto80_solver.cpp
namespace n002bea60 {
u32 func_0016fa98(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0016fa98jjjjjjjj");
u32 func_002c23d8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002c23d8jjjjjjjj");
u32 func_002f17e0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002f17e0jjjjjjjj");
u32 func_002bea60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002bea60jjjjjjjj");
u32 func_002bea60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r4 = (u32)((s32)0u + (6));
    r5 = 0u;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0016fa98)(r4, r5, r6, r7, r8, r9, r10, r11);
    r2 = ((u32(*)())func_002f17e0)();
    return ((u32(*)())func_002c23d8)();
}
}  // namespace n002bea60

// ---- 002bea88 from src/anon/batch_w230.cpp
namespace n002bea88 {
extern u8 D_00361898 asm("D_00361898");
struct W230Z { char p[0x4c]; f32 f; };
extern W230Z* D_00352130 asm("D_00352130");
void func_002be6f0(void) asm("func_002be6f0");
void func_001c8e90(void) asm("func_001c8e90");
void* func_002c6218(void) asm("func_002c6218");
void func_002c6190(void*) asm("func_002c6190");
void* func_001050d8(int) asm("func_001050d8");
void worldmap__RootWindow__RootWindow(void*) asm("worldmap__RootWindow__RootWindow");
void func_00191bf0(f32) asm("func_00191bf0");
void func_00191c30(f32) asm("func_00191c30");
void func_002c1dc0(void) asm("func_002c1dc0");
void func_002c1750(void) asm("func_002c1750");
void worldmap__Event__Event(int) asm("worldmap__Event__Event");
void func_002bea88(void) asm("func_002bea88");
void func_002bea88(void) {
  D_00361898 = 1;
  f32 k = 4.0f;
  func_002be6f0();
  func_001c8e90();
  func_002c6190(func_002c6218());
  worldmap__RootWindow__RootWindow(func_001050d8(160));
  func_00191bf0(k);
  func_00191c30(D_00352130->f * k + 500.0f);
  func_002c1dc0();
  func_002c1750();
  worldmap__Event__Event(0);
}
}  // namespace n002bea88

// ---- 002beb28 from src/anon/auto80_199_queue.cpp
namespace n002beb28 {
void func_002beb28() asm("_Z13func_002beb28v");
void func_002beb28() {
    u32 v0 = func_002c6218();
    v0 = func_002c61c0(v0);
    v0 = func_002bf2f8();
    if (v0 != 0) {
        u32 vt = *(u32*)v0;
        void (*fn)(u32) = (void (*)(u32))*(u32*)(vt + 4);
        fn(v0);
    }
    func_002be720();
    D_00361898 = 0;
}
}  // namespace n002beb28

// ---- 002beb80 gap
namespace n002beb80 {
extern u8 D_00361898 asm("D_00361898");
u8 func_002beb80(void) asm("func_002beb80");
u8 func_002beb80(void) {
    return D_00361898;
}
}  // namespace n002beb80

extern "C" const char D_00375400[] = "file/%s/wm_ws.2ld";

// ---- 002beb90 from src/anon/batch_w23.cpp
namespace n002beb90 {
extern u8 D_01e2bc40[] asm("D_01e2bc40");
extern u8 D_00375400[] asm("D_00375400");
extern u32 D_0033caf4 asm("D_0033caf4");
void func_002fee78(void*, void*, u32) asm("func_002fee78");
void* worldmap__Manager__get2ldFile(void) asm("worldmap__Manager__get2ldFile");
void* worldmap__Manager__get2ldFile(void) {
    func_002fee78(D_01e2bc40, D_00375400, D_0033caf4);
    return D_01e2bc40;
}
}  // namespace n002beb90

