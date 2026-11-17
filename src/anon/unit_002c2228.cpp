// Linked unit 0x2c2228-0x2c3638: first part of the worldmap landing file (dk::WM_LANDING,
// vtable 0x361c20, kept as retail data): menu helpers, the C2/C1 constructor pair, the
// D2/D1/D0 destructors (gap code, written here) and the state setters. It stops before the
// whole-asm update function 0x2c3638 (src/anon/batch_w3953.s), which stays a separate function.
// Bodies come from the old split files named above each function; callees and globals are
// bound by asm label, one namespace per old file. Globals stay extern (symbols.ld).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../worldmap/menu.hpp"
#include "../worldmap/wm_landing_info.hpp"

namespace Tz { class Select { public: u32 isCursorMove(); u32 isSelectTopMove(); }; }

// ---- 002c2228 from src/anon/tiny_auto80_queue.cpp
namespace n002c2228 {
void func_0015ee90(...) asm("func_0015ee90");
void func_002c2228(u32 a0) asm("_Z13func_002c2228j");
void func_002c2228(u32 a0) {                         
    if (a0 != 0) {
        func_0015ee90(a0);
    }
}
}  // namespace n002c2228

// ---- 002c2248 from src/anon/tiny_auto80_queue.cpp
namespace n002c2248 {
void func_0015ee10(...) asm("func_0015ee10");
void func_002c2248(u32 a0) asm("_Z13func_002c2248j");
void func_002c2248(u32 a0) {                         
    if (a0 != 0) {
        func_0015ee10(a0);
    }
}
}  // namespace n002c2248

// ---- 002c2268 from src/anon/tiny_auto80_queue.cpp
namespace n002c2268 {
void func_00160fd0(...) asm("func_00160fd0");
void func_002c2268(u32 a0) asm("_Z13func_002c2268j");
void func_002c2268(u32 a0) {                         
    if (a0 != 0) {
        func_00160fd0(a0);
    }
}
}  // namespace n002c2268

// ---- 002c2288 from src/anon/tiny_auto80_queue.cpp
namespace n002c2288 {
void func_00161000(...) asm("func_00161000");
void func_002c2288(u32 a0) asm("_Z13func_002c2288j");
void func_002c2288(u32 a0) {
    if (a0 != 0) {
        func_00161000(a0);
    }
}
}  // namespace n002c2288

// ---- 002c22a8 from src/anon/tiny.cpp
namespace n002c22a8 {
void func_002c22a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002c22a8jjjj");
void func_002c22a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01e3u << 16);
    *(u32*)((u32)b + (-17152)) = (u32)a0;
}
}  // namespace n002c22a8

// ---- 002c22b8 from src/anon/batch_w16.cpp
namespace n002c22b8 {
u8 func_002fd248(u32, void*, u32, u32, void*) asm("func_002fd248");
extern u32* D_01e2bd00 asm("D_01e2bd00");
extern u8 D_00324bb0 asm("D_00324bb0");
u8 func_002c22b8(u32 a) asm("func_002c22b8");
u8 func_002c22b8(u32 a) {
    u32* p = D_01e2bd00;
    return func_002fd248(a, p + 2, p[1], 16, &D_00324bb0);
}
}  // namespace n002c22b8

// ---- 002c22f0 from src/anon/batch_w45.cpp
namespace n002c22f0 {
s32 func_00181500(u32) asm("func_00181500");
s32 func_002c22f0(u8* a0) asm("func_002c22f0");
s32 func_002c22f0(u8* a0) {
    s32 n = 0;
    u16* p = (u16*)(a0 + 4);
    for (s32 i = 2; i >= 0; i--) {
        u16 h = *p;
        p += 2;
        if (h && func_00181500(h)) n++;
    }
    return n;
}
}  // namespace n002c22f0

// ---- 002c2358 from src/anon/auto80_199_queue.cpp
namespace n002c2358 {
u32 func_002c2358(u8* a0) asm("_Z13func_002c2358Ph");
u32 func_002c2358(u8* a0) {
    u8* s0 = a0;
    s32 s1 = 2;
    u32 s2 = 0;
loop:
    u16 t7 = *(u16*)(s0 + 4);
    if (t7 != 0) {
        u32 v0 = func_00181500(t7);
        if (v0 != 0) {
            t7 = *(u16*)(s0 + 6);
            if (t7 != 0) {
                v0 = func_00181500(t7);
                u32 t6 = s2 + 1;
                if (v0 != 0) {
                    s2 = t6;
                }
            }
        }
    }
    s1 = s1 - 1;
    if (s1 >= 0) {
        s0 = s0 + 4;
        goto loop;
    }
    return s2;
}
}  // namespace n002c2358

// ---- 002c23d8 from src/anon/tiny_wrappers_more.cpp
namespace n002c23d8 {
extern "C" u32 Tz_Jiminy_WMRead(u32, u32, u32, u32) asm("_ZN2Tz6Jiminy6WMReadEv");
u32 func_002c23d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002c23d8jjjj");
u32 func_002c23d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return Tz_Jiminy_WMRead(a0, a1, a2, a3);
}
}  // namespace n002c23d8

// ---- 002c23f0 from src/anon/auto80_199_queue.cpp
namespace n002c23f0 {
extern "C" void func_00274ee8(u32) asm("_ZN2Tz6Jiminy6WMInitEP9ALLOCATOR");
void func_00288b18(u32 a0) asm("_Z13func_00288b18j");
void func_002c23f0() asm("_Z13func_002c23f0v");
void func_002c23f0() {
    u32 v0 = func_00170b30(0x00100000u);                   
    D_00361c08 = v0;
    func_001036d0(v0, 0x00100000u);
    u32 s0 = func_00103570();
    func_00288b18(s0);
    func_0028c3f0(s0);
    func_0028c878(s0, 2);
    func_00274ee8(s0);
}
}  // namespace n002c23f0

// ---- 002c2458 from src/worldmap/menu.cpp
namespace n002c2458 {
void DestoryAllocator() asm("_ZN4MENU16DestoryAllocatorEv");
void WMExit() asm("_ZN2Tz6Jiminy6WMExitEv");
void Exit() asm("_ZN2Tz10MenuCursor4ExitEv");
void update() asm("_ZN2Tz8MenuItem6updateEv");
void End() asm("_ZN2Tz6Select3EndEv");
void FixFree(void*) asm("_ZN2YS10CACHE_BUFF7FixFreeEPv");
void Menu_exit() asm("_ZN8worldmap4Menu4exitEv");
void Menu_exit() {
    WMExit();
    Exit();
    update();
    End();
    DestoryAllocator();
    u32* global = reinterpret_cast<u32*>(0x360000);
    u32 ptr = global[7176 / 4];
    FixFree(reinterpret_cast<void*>(ptr));
    global[7176 / 4] = 0;
}
}  // namespace n002c2458

// ---- 002c24a8 from src/worldmap/menu.cpp
namespace n002c24a8 {
u32 StartJiminy(s32, s32) asm("_ZN2Tz8CampMenu11StartJiminyEii");
u32 func_002764b0(u32) asm("func_002764b0");
void Menu_toJiminy(s32 index) asm("_ZN8worldmap4Menu8toJiminyEi");
void Menu_toJiminy(s32 index) {
    if (index == -1) {
        StartJiminy(0, -1);
    } else {
        StartJiminy(0, (s32)func_002764b0((u32)index));
    }
}
}  // namespace n002c24a8

// ---- 002c24e0 from src/anon/tiny_auto80_queue.cpp
namespace n002c24e0 {
u32 func_002764b0(...) asm("func_002764b0");
void func_00294288(...) asm("func_00294288");
u32 func_00192048(...) asm("func_00192048");
void func_002c24e0(u32 a0) asm("_Z13func_002c24e0j");
void func_002c24e0(u32 a0) {
    u32 out0;
    u32 out1;
    u32 v0 = func_002764b0(a0);
    func_00294288(v0, (u32)&out0, (u32)&out1);
    func_00192048(out0);
}
}  // namespace n002c24e0

// ---- 002c2518 from src/anon/tiny_auto80_queue.cpp
namespace n002c2518 {
u32 func_002764b0(...) asm("func_002764b0");
void func_00294288(...) asm("func_00294288");
u32 func_00192048(...) asm("func_00192048");
void func_002c2518(u32 a0) asm("_Z13func_002c2518j");
void func_002c2518(u32 a0) {
    u32 out0;
    u32 out1;
    u32 v0 = func_002764b0(a0);
    func_00294288(v0, (u32)&out0, (u32)&out1);
    func_00192048(out1);
}
}  // namespace n002c2518

// ---- 002c2550 from src/anon/tiny_auto80_queue.cpp
namespace n002c2550 {
u32 func_001c3748(...) asm("func_001c3748");
u32 func_002c2550(u32 a0) asm("_Z13func_002c2550j");
u32 func_002c2550(u32 a0) {
    u32 count = 0;
    u32 cur = 0;

    while ((cur = func_001c3748(a0, cur)) != 0) {
        ++count;
    }

    return count;
}
}  // namespace n002c2550

// ---- 002c2598 from src/anon/batch_w36.cpp
namespace n002c2598 {
u32 func_00192048(u32) asm("func_00192048");
u8* func_001c3748(u32, u8*) asm("func_001c3748");
u32 func_002c2598(u32 a, s32 n) asm("func_002c2598");
u32 func_002c2598(u32 a, s32 n) {
    s32 i = 0;
    u8* v = 0;
    while ((v = func_001c3748(a, v)) != 0) {
        if (i == n) return func_00192048(*(u16*)(v + 4));
        i++;
    }
    return 0;
}
}  // namespace n002c2598

// ---- 002c2610 from src/anon/batch_w3724.cpp
namespace n002c2610 {
void* func_001c3748(s32, void*) asm("func_001c3748");
s32 u_tail4(u32, void*) asm("_Z16u_tail4_00192048jjjj");
s32 func_002c2610(s32 a0, s32 n) asm("func_002c2610");
s32 func_002c2610(s32 a0, s32 n) {
    register s32 nn asm("$17") = n; s32 i = 0; s32 aa = a0; register void* p asm("$5") = 0;
    while ((p = func_001c3748(aa, p)) != 0) {
        if (i == nn) { return u_tail4(((u16*)p)[3], p); }
        i++;
    }
    return 0;
}
}  // namespace n002c2610

// ---- 002c2688 from src/anon/batch_w45.cpp
namespace n002c2688 {
u32 func_001c3748(u32, u32) asm("func_001c3748");
u8 func_001c3888(u32) asm("func_001c3888");
u8 func_002c2688(u32 a0, s32 a1) asm("func_002c2688");
u8 func_002c2688(u32 a0, s32 a1) {
    u32 v = 0;
    s32 i = 0;
    while ((v = func_001c3748(a0, v)) != 0) {
        if (i == a1) return func_001c3888(v);
        i++;
    }
    return 0;
}
}  // namespace n002c2688

// 002c26f8 (gap, never written): C2 copy of the constructor 002c29d8, same body.
namespace n002c26f8 {
extern u8 D_00361c20[] asm("D_00361c20");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8 D_0035ebb8[] asm("D_0035ebb8");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_0035f380[] asm("D_0035f380");
extern u8 D_00347e40[] asm("D_00347e40");
extern u8* D_00361c10 asm("D_00361c10");
void func_0031a838(void*) asm("func_0031a838");
void func_0031a830(void*) asm("func_0031a830");
void func_002369a0(void*) asm("func_002369a0");
void func_0023c008(void*) asm("func_0023c008");
void func_0028d140(void*) asm("func_0028d140");
void func_00239700(void*) asm("func_00239700");
void func_002361a0(void*) asm("func_002361a0");
void func_0028b9b0(void*) asm("func_0028b9b0");
void func_00190128(void*) asm("func_00190128");
void func_00167f38(s32) asm("func_00167f38");
void func_002c5f48(void) asm("func_002c5f48");
struct Id3b2c29d8 { u8 a, b, c; void Fill(s32 v) { a = v; b = v; c = v; } };
struct Id3h2c29d8 { u16 a, b, c; void Fill(s32 v) { a = v; b = v; c = v; } };
void func_002c26f8(u8* t) asm("func_002c26f8");
void func_002c26f8(u8* t)
{
    *(u32*)(t + 28) = (u32)D_00347f98;
    *(u32*)(t + 0) = (u32)D_00361c20;
    *(u32*)(t + 12) = 0;
    *(u32*)(t + 24) = 0;
    func_0031a838(t + 40);
    *(u32*)(t + 28) = (u32)D_0035eb98;
    func_002369a0(t + 52);
    func_0023c008(t + 76);
    u32* s1 = (u32*)(t + 188);
    for (s32 i = 8; i != -1; i--) {
        s1[3] = 0;
        s1[0] = (u32)D_0035ebb8;
        s1 = (u32*)((u8*)s1 + 76);
    }
    *(u32*)(t + 872) = 0;
    func_0028d140(t + 876);
    u8* e = t + 1320;
    for (s32 i = 7; i != -1; i--) {
        *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
        *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        *(u32*)e = (u32)D_0035f380;
        e += 432;
    }
    u8* e2 = t + 4776;
    for (s32 i = 7; i != -1; i--) {
        *(u32*)e2 = (u32)D_00347f98; func_0031a838(e2 + 12);
        *(u32*)e2 = (u32)D_00347e60; func_00239700(e2 + 24);
        *(u32*)e2 = (u32)D_0035f380;
        e2 += 432;
    }
    *(u32*)(t + 8232) = 0; *(u32*)(t + 8236) = 0; *(u32*)(t + 8240) = 0; *(u32*)(t + 8244) = 0;
    *(u32*)(t + 8248) = 0; *(u32*)(t + 8252) = 0; *(u32*)(t + 8256) = 0; *(u32*)(t + 8260) = 0;
    u8* e3 = t + 8272;
    for (s32 i = 7; i != -1; i--) {
        *(u32*)(e3 + 0) = 0; *(u32*)(e3 + 4) = 0; *(u32*)(e3 + 8) = 0;
        func_002361a0(e3 + 16);
        func_0031a830(e3 + 432);
        ((Id3b2c29d8*)(e3 + 436))->Fill(0xffff);
        ((Id3h2c29d8*)(e3 + 440))->Fill(0xffff);
        func_0031a830(e3 + 432);
        e3 += 448;
    }
    u8* m1 = t + 11872;
    *(u32*)m1 = (u32)D_00347f98; func_0031a838(m1 + 12);
    *(u32*)m1 = (u32)D_00347e60; func_00239700(m1 + 24);
    *(u32*)(m1 + 408) = 0; *(void**)m1 = D_00347e40;
    func_0028b9b0(t + 12308);
    *(u32*)(t + 12360) = 0;
    u32* s2 = (u32*)(t + 12384);
    for (s32 i = 2; i != -1; i--) {
        s2[3] = 0;
        s2[0] = (u32)D_00347e60;
        func_00239700((u8*)s2 + 24);
        s2 = (u32*)((u8*)s2 + 408);
    }
    ((Id3b2c29d8*)(t + 13608))->Fill(0xffff);
    ((Id3h2c29d8*)(t + 13612))->Fill(0xffff);
    func_00190128(t + 13620);
    u8* m2 = t + 13648;
    *(u32*)m2 = (u32)D_00347f98; func_0031a838(m2 + 12);
    *(u32*)m2 = (u32)D_00347e60; func_00239700(m2 + 24);
    *(u32*)(m2 + 408) = 0; D_00361c10 = t; *(void**)m2 = D_00347e40;
    func_00167f38(3);
    func_002c5f48();
}
}  // namespace n002c26f8

// ---- 002c29d8 from src/anon/batch_w2415.cpp
namespace n002c29d8 {
extern u8 D_00361c20[] asm("D_00361c20");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8 D_0035ebb8[] asm("D_0035ebb8");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_0035f380[] asm("D_0035f380");
extern u8 D_00347e40[] asm("D_00347e40");
extern u8* D_00361c10 asm("D_00361c10");
void func_0031a838(void*) asm("func_0031a838");
void func_0031a830(void*) asm("func_0031a830");
void func_002369a0(void*) asm("func_002369a0");
void func_0023c008(void*) asm("func_0023c008");
void func_0028d140(void*) asm("func_0028d140");
void func_00239700(void*) asm("func_00239700");
void func_002361a0(void*) asm("func_002361a0");
void func_0028b9b0(void*) asm("func_0028b9b0");
void func_00190128(void*) asm("func_00190128");
void func_00167f38(s32) asm("func_00167f38");
void func_002c5f48(void) asm("func_002c5f48");
struct Id3b2c29d8 { u8 a, b, c; void Fill(s32 v) { a = v; b = v; c = v; } };
struct Id3h2c29d8 { u16 a, b, c; void Fill(s32 v) { a = v; b = v; c = v; } };
void func_002c29d8(u8* t) asm("func_002c29d8");
void func_002c29d8(u8* t)
{
    *(u32*)(t + 28) = (u32)D_00347f98;
    *(u32*)(t + 0) = (u32)D_00361c20;
    *(u32*)(t + 12) = 0;
    *(u32*)(t + 24) = 0;
    func_0031a838(t + 40);
    *(u32*)(t + 28) = (u32)D_0035eb98;
    func_002369a0(t + 52);
    func_0023c008(t + 76);
    u32* s1 = (u32*)(t + 188);
    for (s32 i = 8; i != -1; i--) {
        s1[3] = 0;
        s1[0] = (u32)D_0035ebb8;
        s1 = (u32*)((u8*)s1 + 76);
    }
    *(u32*)(t + 872) = 0;
    func_0028d140(t + 876);
    u8* e = t + 1320;
    for (s32 i = 7; i != -1; i--) {
        *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
        *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        *(u32*)e = (u32)D_0035f380;
        e += 432;
    }
    u8* e2 = t + 4776;
    for (s32 i = 7; i != -1; i--) {
        *(u32*)e2 = (u32)D_00347f98; func_0031a838(e2 + 12);
        *(u32*)e2 = (u32)D_00347e60; func_00239700(e2 + 24);
        *(u32*)e2 = (u32)D_0035f380;
        e2 += 432;
    }
    *(u32*)(t + 8232) = 0; *(u32*)(t + 8236) = 0; *(u32*)(t + 8240) = 0; *(u32*)(t + 8244) = 0;
    *(u32*)(t + 8248) = 0; *(u32*)(t + 8252) = 0; *(u32*)(t + 8256) = 0; *(u32*)(t + 8260) = 0;
    u8* e3 = t + 8272;
    for (s32 i = 7; i != -1; i--) {
        *(u32*)(e3 + 0) = 0; *(u32*)(e3 + 4) = 0; *(u32*)(e3 + 8) = 0;
        func_002361a0(e3 + 16);
        func_0031a830(e3 + 432);
        ((Id3b2c29d8*)(e3 + 436))->Fill(0xffff);
        ((Id3h2c29d8*)(e3 + 440))->Fill(0xffff);
        func_0031a830(e3 + 432);
        e3 += 448;
    }
    u8* m1 = t + 11872;
    *(u32*)m1 = (u32)D_00347f98; func_0031a838(m1 + 12);
    *(u32*)m1 = (u32)D_00347e60; func_00239700(m1 + 24);
    *(u32*)(m1 + 408) = 0; *(void**)m1 = D_00347e40;
    func_0028b9b0(t + 12308);
    *(u32*)(t + 12360) = 0;
    u32* s2 = (u32*)(t + 12384);
    for (s32 i = 2; i != -1; i--) {
        s2[3] = 0;
        s2[0] = (u32)D_00347e60;
        func_00239700((u8*)s2 + 24);
        s2 = (u32*)((u8*)s2 + 408);
    }
    ((Id3b2c29d8*)(t + 13608))->Fill(0xffff);
    ((Id3h2c29d8*)(t + 13612))->Fill(0xffff);
    func_00190128(t + 13620);
    u8* m2 = t + 13648;
    *(u32*)m2 = (u32)D_00347f98; func_0031a838(m2 + 12);
    *(u32*)m2 = (u32)D_00347e60; func_00239700(m2 + 24);
    *(u32*)(m2 + 408) = 0; D_00361c10 = t; *(void**)m2 = D_00347e40;
    func_00167f38(3);
    func_002c5f48();
}
}  // namespace n002c29d8

// 002c2cb8 / 002c2e88 / 002c3058 (gap, never written): D2, D1 and D0 destructors of the
// object built by 002c26f8/002c29d8 (vtable 0x361c20). Member arrays with virtual destructors
// (slot 3) are destroyed from the end, as gcc does for arrays.
namespace n002c2cb8 {
extern u8 D_00361c20[] asm("D_00361c20");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8* D_00361c10 asm("D_00361c10");
extern u8* D_00347f80 asm("D_00347f80");
void func_002c1750() asm("func_002c1750");
void YI_SEQUENCE_D1(u8*) asm("_ZN2YI8SEQUENCED1Ev");
void YI_IMAGE_D1(u8*) asm("_ZN2YI5IMAGED1Ev");
void func_0028ba80(u8*) asm("func_0028ba80");
void func_0023c098(u8*) asm("func_0023c098");
void func_002369f0(u8*) asm("func_002369f0");
typedef void (*VF)(u8*);
typedef void (*FreeFn)(u8*, u8*);
static inline void vdtor(u8* p) { ((VF)(*(void***)p)[3])(p); }
static inline void body(u8* t) __attribute__((always_inline));
static inline void body(u8* t)
{
    *(u8**)t = D_00361c20;
    if (D_00361c10 == t) D_00361c10 = 0;
    func_002c1750();
    *(u8**)(t + 13648) = D_00347e60;
    YI_SEQUENCE_D1(t + 13672);
    *(u8**)(t + 13648) = D_00347f98;
    {
        if (t + 12384 != 0) {
            u8* p = t + 13608;
            u8* b = t + 12384;
            top1:
            if (b == p) goto done1;
            p -= 408; vdtor(p);
            goto top1;
        done1:;
        }
    }
    func_0028ba80(t + 12308);
    *(u8**)(t + 11872) = D_00347e60;
    YI_SEQUENCE_D1(t + 11896);
    *(u8**)(t + 11872) = D_00347f98;
    {
        u8* b = t + 8272;
        if (b) {
            u8* p = t + 11856;
            top2:
            if (b == p) goto done2;
            p -= 448; YI_IMAGE_D1(p + 16);
            goto top2;
        done2:;
        }
    }
    {
        if (t + 4776 != 0) {
            u8* p = t + 8232;
            u8* b = t + 4776;
            top3:
            if (b == p) goto done3;
            p -= 432; vdtor(p);
            goto top3;
        done3:;
        }
    }
    {
        if (t + 1320 != 0) {
            u8* p = t + 4776;
            u8* b = t + 1320;
            top4:
            if (b == p) goto done4;
            p -= 432; vdtor(p);
            goto top4;
        done4:;
        }
    }
    *(u8**)(t + 876) = D_00347e60;
    YI_SEQUENCE_D1(t + 900);
    *(u8**)(t + 876) = D_00347f98;
    {
        if (t + 188 != 0) {
            u8* p = t + 872;
            u8* b = t + 188;
            top5:
            if (b == p) goto done5;
            p -= 76; vdtor(p);
            goto top5;
        done5:;
        }
    }
    *(u8**)(t + 28) = D_0035eb98;
    func_0023c098(t + 76);
    func_002369f0(t + 52);
    *(u8**)(t + 28) = D_00347f98;
    *(u8**)t = D_00347f98;
}
void func_002c2cb8(u8* t) asm("func_002c2cb8");
void func_002c2cb8(u8* t) { body(t); }
void func_002c2e88(u8* t) asm("func_002c2e88");
void func_002c2e88(u8* t) { body(t); }
void func_002c3058(u8* t) asm("func_002c3058");
void func_002c3058(u8* t)
{
    body(t);
    u8* a = *(u8**)(D_00347f80 + 20);
    ((FreeFn)(*(void***)a)[1])(a, t);
}
}  // namespace n002c2cb8

// ---- 002c3240 from src/anon/tiny_auto80_fptr4.cpp
namespace n002c3240 {
extern u8 D_00375540 asm("D_00375540");
u32 func_002c3240(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002c3240jjjj");
u32 func_002c3240(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r14, r15;
    r15 = *(u32*)((u32)r4 + (s32)(8244));
    r14 = (u32)&D_00375540;
    r15 = (u32)(r15 << 2);
    r15 = (u32)(r15 + r5);
    r15 = (u32)(r15 << 1);
    r15 = (u32)(r15 + r14);
    r2 = (u32)(s32)(*(s16*)((u32)r15 + (s32)(0)));
    return r2;
}
}  // namespace n002c3240

// ---- 002c3268 from src/anon/tiny_auto80_fptr4.cpp
namespace n002c3268 {
extern u8 D_00375540 asm("D_00375540");
u32 func_002c3268(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002c3268jjjj");
u32 func_002c3268(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r2 = *(u32*)((u32)r4 + (s32)(8244));
    r15 = (u32)&D_00375540;
    r2 = (u32)(r2 << 3);
    r2 = (u32)(r2 + r15);
    return r2;
}
}  // namespace n002c3268

// ---- 002c3280 from src/anon/batch_w77.cpp
namespace n002c3280 {
struct Obj;
void func_00288b00(void*) asm("func_00288b00");
struct Obj {
    ~Obj() { func_00288b00(this); }
    static void operator delete(void*) asm("func_00288c20");
};
struct Self;
typedef void (*DelFn)(Self*);
struct Self { void** vt; };
void func_00170950(u32) asm("func_00170950");
void func_002c5f60(void) asm("func_002c5f60");
u32 func_002c6218(void) asm("func_002c6218");
void func_002c6280(u32, s32) asm("func_002c6280");
void func_002c5460(u8*) asm("func_002c5460");
void func_00167f38(s32) asm("func_00167f38");
s32 func_002c5120(u8*) asm("func_002c5120");
void func_001384a0(s32) asm("func_001384a0");
void func_0014f2b0(void) asm("func_0014f2b0");
void func_002c3280(u8* p) asm("func_002c3280");
void func_002c3280(u8* p)
{
    func_00170950(*(u32*)(p + 8232));
    func_002c5f60();
    func_002c6280(func_002c6218(), 2);
    switch (*(s32*)(p + 8240)) {
    case 0: break;
    case 1: func_002c5460(p + 13608); break;
    }
    func_00167f38(1);
    if (func_002c5120(p) && *(u32*)(p + 12368)) delete *(Obj**)(p + 12360);
    delete *(Obj**)(p + 872);
    if (p) ((DelFn)((Self*)p)->vt[4])((Self*)p);
    func_001384a0(0);
    func_0014f2b0();
}
}  // namespace n002c3280

// ---- 002c3368 from src/anon/batch_wcx2.cpp
namespace n002c3368 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
struct Vec4x { f32 a,b,c,d; } __attribute__((aligned(16)));
struct Ent54 { u8 b[432]; };
struct Lyt54 { u8 b[76]; };
struct Prm54 { u8 b[32]; };
struct Obj54 {
    u8 pad[188];
    Lyt54 lyt[9];
    u8 pad2[1320 - 188 - 9 * 76];
    Ent54 a[8];
    Ent54 b[8];
    u8 pad3[8244 - 4776 - 8 * 432];
    s32 st;
    u32 pad4;
    s32 na;
    s32 nb;
};
extern u8 D_003755b0[] asm("D_003755b0");
extern u8 D_003755b8[] asm("D_003755b8");
extern Prm54 D_00375638[] asm("D_00375638");
extern u8 D_01e2bd40[] asm("D_01e2bd40");
u32 func_002c3268(Obj54*) asm("func_002c3268");
void func_0028b4c0(Ent54*, u32) asm("func_0028b4c0");
void func_0028b4f0(Ent54*, u8*) asm("func_0028b4f0");
void func_0023f778__84943(Lyt54*, u32) asm("func_0023f778");
void func_0023f7a8__84943(Lyt54*, Prm54*) asm("func_0023f7a8");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00138c10__84943(u8*, s32) asm("func_00138c10");
void func_002cb0e8(u8*, u8*, f32) asm("func_002cb0e8");
void func_002c3368(Obj54* o) asm("func_002c3368");
void func_002c3368(Obj54* o)
{
    if (o->st != 2) o->st = 2;
    for (s32 i = 0; i < o->na; i++) {
        func_0028b4c0(&o->a[i], func_002c3268(o));                        
        func_0028b4f0(&o->a[i], D_003755b0);                        
    }
    for (s32 i = 0; i < o->nb; i++) {
        func_0028b4c0(&o->b[i], func_002c3268(o));                        
        func_0028b4f0(&o->b[i], D_003755b8);                        
    }
    for (s32 i = 0; i < 9; i++) {
        func_0023f778__84943(&o->lyt[i], func_002c3268(o));
        func_0023f7a8__84943(&o->lyt[i], &D_00375638[i]);
    }
    u8* t = (u8*)o + 11872;
    if (func_00139d78(t)) {
        func_00138c10__84943(t, 94);
        *(s32*)(t + 392) = 95;
    }
    func_002cb0e8((u8*)o + 13620, D_01e2bd40, 0.0f);
}
}  // namespace n002c3368

// ---- 002c34d0 from src/anon/batch_wcx2.cpp
namespace n002c34d0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
struct V62 {
    f32 x, y, z, w;
    V62() {}
    V62(const V62& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
struct Ent80 { u8 b[432]; };
struct Lyt80 { u8 b[76]; };
struct Prm80 { u8 b[32]; };
struct Obj80 {
    u8 pad[188];
    Lyt80 lyt[9];
    u8 pad2[1320 - 188 - 9 * 76];
    Ent80 a[8];
    Ent80 b[8];
    u8 pad3[8244 - 4776 - 8 * 432];
    s32 st;
    u32 pad4;
    s32 na;
    s32 nb;
};
extern u8 D_003755a0[] asm("D_003755a0");
extern u8 D_003755a8[] asm("D_003755a8");
extern Prm80 D_00375640[] asm("D_00375640");
extern u8 D_01e2bd30[] asm("D_01e2bd30");
u32 func_002c3268__99908(Obj80*) asm("func_002c3268");
void func_0028b4c0__99908(Ent80*, u32) asm("func_0028b4c0");
void func_0028b4f0__99908(Ent80*, u8*) asm("func_0028b4f0");
void func_0023f778__99908(Lyt80*, u32) asm("func_0023f778");
void func_0023f7a8__99908(Lyt80*, Prm80*) asm("func_0023f7a8");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00138c10__99908(u8*, s32) asm("func_00138c10");
void func_002cb0e8(u8*, u8*, f32) asm("func_002cb0e8");
void func_002c34d0(Obj80* o) asm("func_002c34d0");
void func_002c34d0(Obj80* o)
{
    if (o->st != 3) o->st = 3;
    for (s32 i = 0; i < o->na; i++) {
        func_0028b4c0__99908(&o->a[i], func_002c3268__99908(o));
        func_0028b4f0__99908(&o->a[i], D_003755a0);
    }
    for (s32 i = 0; i < o->nb; i++) {
        func_0028b4c0__99908(&o->b[i], func_002c3268__99908(o));
        func_0028b4f0__99908(&o->b[i], D_003755a8);
    }
    for (s32 i = 0; i < 9; i++) {
        func_0023f778__99908(&o->lyt[i], func_002c3268__99908(o));
        func_0023f7a8__99908(&o->lyt[i], &D_00375640[i]);
    }
    u8* t = (u8*)o + 11872;
    if (func_00139d78(t)) {
        func_00138c10__99908(t, 96);
        *(s32*)(t + 392) = 1;
    }
    func_002cb0e8((u8*)o + 13620, D_01e2bd30, 0.0f);
}
}  // namespace n002c34d0

