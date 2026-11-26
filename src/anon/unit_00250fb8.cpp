// Linked unit 0x00250fb8-0x00252fe8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/smenu_cana.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/campmenu.hpp"
#include "../tozawa/cmenu_data.hpp"
#include "../tozawa/menu_sound.hpp"
#include "tiny_auto80_solver_structs.hpp"

// 00250fb8 (was src/anon/batch_w256.cpp)
namespace n00250fb8 {
struct NoTail_w256 { ~NoTail_w256() {} };
/*AMBIG-MULTI*/ // 0017f268: moved to src/yasui/libys/motion.cpp


extern "C" u32 D_0035ee60;
extern "C" u32 D_0035ee68;
extern "C" u32 D_0035ee6c;
extern "C" u32 D_0035ee7c;
extern "C" u32 D_0035ee78;
extern "C" u32 D_0035ee80;
extern "C" u32 D_0035ee70;
extern "C" u32 D_0035ee74;
extern "C" u32 D_0035ee58;
extern "C" u32 D_0035ee5c;
s32 call4_w256(u32) asm("_Z16u_call4_00139d78jjjj");
s32 iscreated_w256(u32) asm("_ZN2Tz6Select9isCreatedEz");
/*TARGET 00250fb8*/
void func_00250fb8(void) asm("func_00250fb8");
void func_00250fb8(void) {
  NoTail_w256 nt;
  if (call4_w256(D_0035ee60)) return;
  if (call4_w256(D_0035ee68)) return;
  if (call4_w256(D_0035ee6c)) return;
  if (call4_w256(D_0035ee7c)) return;
  if (call4_w256(D_0035ee78)) return;
  if (call4_w256(D_0035ee80)) return;
  for (s32 i = 0; i < 4; i++) {
    if (call4_w256(D_0035ee70 + i * 432)) return;
    if (call4_w256(D_0035ee74 + i * 432)) return;
  }
  if (iscreated_w256(D_0035ee58)) return;
  iscreated_w256(D_0035ee5c);
}
}  // namespace n00250fb8

// 002510d0 (was src/tozawa/smenu_cana.cpp)
namespace Tz { // method 002510d0
extern u32 D_0035ee54 asm("D_0035ee54");
void func_002430d8(u32) asm("func_002430d8");
void func_00102448(u32, u32) asm("func_00102448");
void Tz__CANA__Setup() asm("Tz__CANA__Setup");
void func_00242678(u32) asm("func_00242678");
void YI__IMAGE_CACHE__Clear() asm("YI__IMAGE_CACHE__Clear");
// clear_64_entries_24
extern "C" u32 Tz__CANA__Control() asm("Tz__CANA__Control");
void Tz__CANA__Draw() asm("Tz__CANA__Draw");
/*TARGET 002510d0*/
void CANA::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    func_002430d8(D_0035ee54);
    func_00102448(s0, 1);
    Tz__CANA__Setup();
    func_00242678(17014);
    while (1) {
        YI__IMAGE_CACHE__Clear();  // clear_64_entries_24
        if (Tz__CANA__Control() != 0) {
            return;
        }
        Tz__CANA__Draw();
        func_00102448(s0, 0);
    }
}
}  // Tz

// 00251148 (was src/anon/batch_w108.cpp)
namespace n00251148 {
struct Heap251;
s32 func_002891e8(void*) asm("func_002891e8");
struct Heap251Vt {
    u8* (*alloc)(Heap251*, s32, s32);
};
struct Heap251 {
    Heap251Vt* vt;
};
struct Sys251 {
    u8 pad[20];
    Heap251* heap;
};
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8 D_0035ebb8[] asm("D_0035ebb8");
extern u8* D_0035ee60 asm("D_0035ee60");
extern u8* D_0035ee64 asm("D_0035ee64");
extern u32 D_0035ee58 asm("D_0035ee58");
extern Sys251* D_00347f80 asm("D_00347f80");
extern u8 D_00372608 asm("D_00372608");
extern u8 D_00372630 asm("D_00372630");
u8* func_0023ee30(s32) asm("func_0023ee30");
void func_0031a838(u8*) asm("func_0031a838");
void YI__IMAGE_FREEZE__IMAGE_FREEZE(u8*) asm("YI__IMAGE_FREEZE__IMAGE_FREEZE");
// obj_ctor_36eac8
void YI__LAYOUT__LAYOUT(u8*) asm("YI__LAYOUT__LAYOUT");
// obj_ctor_36eae8
void Tz__MenuUtil__CreateLay(u8*, s32, s32, s32, s32, s32, s32, s32, s32) asm("Tz__MenuUtil__CreateLay");
void Tz__Layout__SetImageCache(u8*) asm("Tz__Layout__SetImageCache");
s32 func_00252098(s32) asm("func_00252098");
void func_00288ce0(u32, s32, s32, s32, s32) asm("func_00288ce0");
void Tz__LayMsg__create(u8*, s32, u8*, void*, void*, s32, s32, s32) asm("Tz__LayMsg__create");
void func_0023f6c0(u8*, s32) asm("func_0023f6c0");
void func_00252180(void) asm("func_00252180");
s32 func_00252428(void) asm("func_00252428");
void func_00252320(void) asm("func_00252320");
void func_00252208(void) asm("func_00252208");
s32 func_00252148(s32) asm("func_00252148");
void Tz__Select__SetCurrent(u32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
s32 func_00252110(s32) asm("func_00252110");
void Tz__CANA__SetNewFlag(s32) asm("Tz__CANA__SetNewFlag");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 00251148*/
void Tz__CANA__Setup(void) asm("Tz__CANA__Setup");
void Tz__CANA__Setup(void)
{
    u8* o;
    u8* p;
    s32 i;
    s32 n;
    s32 sel;

    o = func_0023ee30(160);
    *(u8**)o = D_00347f98;
    func_0031a838(o + 12);
    *(u8**)o = D_0035eb98;
    YI__IMAGE_FREEZE__IMAGE_FREEZE(o + 24);  // obj_ctor_36eac8
    YI__LAYOUT__LAYOUT(o + 48);  // obj_ctor_36eae8
    D_0035ee60 = o;
    Tz__MenuUtil__CreateLay(o, 30002, 0, 0, 0, 1, 0, 0, 0);
    Tz__Layout__SetImageCache(D_0035ee60);
    n = 0;
    for (i = 0; i < 4; i++) {
        if (func_00252098(i)) {
            func_00288ce0(D_0035ee58, 0, n, 0, 0);
            n++;
        }
    }
    p = D_00347f80->heap->vt->alloc(D_00347f80->heap, 76, 0);
    *(u32*)(p + 12) = 0;
    *(u8**)p = D_0035ebb8;
    D_0035ee64 = p;
    Tz__LayMsg__create(p, 30003, D_0035ee60, &D_00372608, &D_00372630, -1, 0, 0);
    func_0023f6c0(D_0035ee64, 2);
    func_00252180();
    sel = func_00252428();
    func_00252320();
    func_00252208();
    Tz__Select__SetCurrent(D_0035ee58, func_00252148(sel), 0, -1, -1);
    Tz__CANA__SetNewFlag(func_00252110(func_002891e8((void*)D_0035ee58)));
    func_00287bd0(0, 0);
    func_00287cc0(0);
}
}  // namespace n00251148

// 00251318 (was src/anon/batch_w1579_g.cpp)
namespace n00251318 {
// 001e06b8: moved to src/anon/unit_001e0398.cpp
s32 func_00287bc0(void) asm("func_00287bc0");
void Tz__MenuBase__SaveMode(void) asm("Tz__MenuBase__SaveMode");
void func_00252020(void) asm("func_00252020");
s32 func_00287db0(void) asm("func_00287db0");
s32 func_00250fb8(void) asm("func_00250fb8");
void func_001039f8(void) asm("func_001039f8");
void func_00251780(void) asm("func_00251780");
void func_002513b0(void) asm("func_002513b0");
/*TARGET 00251318*/
u32 Tz__CANA__Control(void) asm("Tz__CANA__Control");
u32 Tz__CANA__Control(void) {
    s32 mode = func_00287bc0();
    Tz__MenuBase__SaveMode();
    func_00252020();
    if (func_00287db0() != 0) {
        if (func_00250fb8() == 0) {
            func_00252020();
            func_001039f8();
            return 1;
        }
        return 0;
    }
    switch (mode) {
    case 0: func_002513b0(); break;
    case 1: func_00251780(); break;
    }
    return 0;
}
}  // namespace n00251318

// 002513b0 (was src/anon/batch_wcx2.cpp)
namespace n002513b0 {
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
extern u32 D_0035ee60 asm("D_0035ee60");
struct O2513b0;
struct VT2513b0 { u8 pad[20]; void (*f20)(O2513b0*); };
struct O2513b0 { VT2513b0* vt; };
extern u32 D_0035ee58 asm("D_0035ee58");
extern O2513b0* D_0035ee68 asm("D_0035ee68");
s32 func_00287cd0() asm("func_00287cd0");
void func_00139d78_x9577(s32) asm("func_00139d78");
s32 func_00289380_x9578(s32) asm("func_00289380");
s32 func_00289310_x9579(s32) asm("func_00289310");
s32 func_0023f0c0_x9580(s32) asm("func_0023f0c0");
void func_0023f070(s32, s32, s32) asm("func_0023f070");
void func_002426a0(s32) asm("func_002426a0");
void func_00287c90(s32) asm("func_00287c90");
void Tz__CANA__UpdateGra() asm("Tz__CANA__UpdateGra");
s32 func_002891e8_x9585(s32) asm("func_002891e8");
s32 func_00252110(s32) asm("func_00252110");
void func_00251ec8(s32) asm("func_00251ec8");
s32 func_00287df0_x9589(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
s32 func_00252000() asm("func_00252000");
void func_00251fe0() asm("func_00251fe0");
void func_00252618() asm("func_00252618");
void func_00287da0() asm("func_00287da0");
s32 func_00252710(s32) asm("func_00252710");
void func_00251f40() asm("func_00251f40");
void Tz__CANA__SetupSel() asm("Tz__CANA__SetupSel");
void func_00287bd0(s32, s32) asm("func_00287bd0");
s32 func_00288040() asm("func_00288040");
void func_00288018() asm("func_00288018");
/*TARGET 002513b0*/
void func_002513b0() asm("func_002513b0");
void func_002513b0() {
    s32 a = func_00287cd0();
    func_00139d78_x9577(D_0035ee60);
    s32 r = func_00289380_x9578(D_0035ee58);
    if (r != -1 || func_00289310_x9579(D_0035ee58)) {
        if (func_0023f0c0_x9580(D_0035ee60) != 1) {
            func_0023f070(D_0035ee60, 1, -1);
            func_002426a0(0);
        }
    }
    if (!a && func_0023f0c0_x9580(D_0035ee60) == 1) {
        func_00287c90(1);
        Tz__CANA__UpdateGra();
        func_00251ec8(func_00252110(func_002891e8_x9585(D_0035ee58)));
    }
    if (!func_00242848(func_00287df0_x9589(r, func_00289310_x9579(D_0035ee58), 1, 0, 1))) {
        switch (r) {
        case -4: case -2:
            if (!func_00252000()) {
                func_00252618();
                func_00287da0();
            } else {
                func_00251fe0();
            }
            break;
        case -3: case -1:
            break;
        case 0: case 1: case 2: case 3:
            if (func_00252710(r)) {
                func_00251f40();
            } else {
                if (func_00252000()) D_0035ee68->vt->f20(D_0035ee68);
                Tz__CANA__SetupSel();
                func_00287bd0(1, 0);
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n002513b0

// 002515a0 (was src/anon/batch_w294.cpp)
namespace n002515a0 {
struct Sub { u8 pad[184]; u32 f184; void set8() { f184 |= 8; } };
struct Sc { u8 pad[24]; Sub sub; u8 pad2[405-24-188]; u8 f405; };
extern Sc* D_0035ee80 asm("D_0035ee80");
extern s32 D_0035ee60 asm("D_0035ee60");
extern void* D_0035ee5c asm("D_0035ee5c");
struct W { s32 v; };
extern W D_0035f3d4 asm("D_0035f3d4");
extern s32 D_003725c0[] asm("D_003725c0");
void func_0028d8c0(Sc*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void Tz__Select__SetItem(void*, s32, s32, s32, s32, s32, s16*, s16*) asm("Tz__Select__SetItem");
u8* func_002891b8(void*, s32) asm("func_002891b8");
s32 func_0023aa78(u8*) asm("func_0023aa78");
void Tz__Select__SetExOffset(void*, s32, s32, s32) asm("Tz__Select__SetExOffset");
void func_00139620(u8*) asm("func_00139620");
void func_0028dcc0(u8*, Sc*) asm("func_0028dcc0");
void Tz__Select__SetCurrent(void*, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_0028af28(void*, s32) asm("func_0028af28");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 002515a0*/
void Tz__CANA__SetupSel(void) asm("Tz__CANA__SetupSel");
void Tz__CANA__SetupSel(void) {
    s16 a[2][4];
    s32 i;
    for (i = 0; i < 2; i++) {
        for (s32 j = 0; j < 4; j++) {
            if (i == 1) a[1][j] = 11;
            else a[i][j] = 10;
        }
    }
    func_0028d8c0(D_0035ee80, 30013, 2, 2, D_0035ee60, 7, 8, 0);
    D_0035ee80->f405 = 1;
    D_0035ee80->sub.set8();
    s32 save = D_0035f3d4.v;
    D_0035f3d4.v = 30014;
    for (i = 0; i < 2; i++) {
        Tz__Select__SetItem(D_0035ee5c, i, 2, 2, D_0035ee60, D_003725c0[i], a[0], a[1]);
        u8* o = func_002891b8(D_0035ee5c, i);
        Tz__Select__SetExOffset(D_0035ee5c, i, 0, func_0023aa78(o + 24));
        func_00139620(o);
        *(s32*)(o + 432) = 2;
        func_0028dcc0(o, D_0035ee80);
    }
    D_0035f3d4.v = save;
    Tz__Select__SetCurrent(D_0035ee5c, 1, 1, 0, 2);
    func_0028af28(D_0035ee5c, 64);
    func_00287cc0(0);
}
}  // namespace n002515a0

// 00251780 (was src/anon/batch_w111.cpp)
namespace n00251780 {
extern void* D_0035ee58 asm("D_0035ee58");
extern void* D_0035ee5c asm("D_0035ee5c");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00289380(void*) asm("func_00289380");
s32 func_002519d0(void) asm("func_002519d0");
s32 func_00289310(void*) asm("func_00289310");
void func_00287f90(s32) asm("func_00287f90");
void func_00251a08(void) asm("func_00251a08");
void func_0028af18(void*, s32) asm("func_0028af18");
void func_00287bd0(s32, s32) asm("func_00287bd0");
s32 func_0028ae28(void*, s32) asm("func_0028ae28");
void func_0028ab20(void*) asm("func_0028ab20");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, void (*)(void), s32) asm("func_00287df0");
void func_0028aa40(void*) asm("func_0028aa40");
void func_002519b0(void) asm("func_002519b0");
s32 func_002891e8(void*) asm("func_002891e8");
s32 func_00252110(s32) asm("func_00252110");
void func_00287b08(s32) asm("func_00287b08");
void func_00252618(void) asm("func_00252618");
void func_00287da0(void) asm("func_00287da0");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
/*TARGET 00251780*/
// global_zero_4dwords
// Menu update: handles the confirm/close states and dispatches the chosen entry.
void func_00251780(void) asm("func_00251780");
// global_zero_4dwords
// Menu update: handles the confirm/close states and dispatches the chosen entry.
void func_00251780(void)
{
    s32 st = func_00287cd0();
    s32 sel = func_00289380(D_0035ee5c);
    if (st == 2) {
        if (func_002519d0()) {
            if (sel != -1 || func_00289310(D_0035ee5c)) {
                func_00287f90(0);
                func_00251a08();
            }
            return;
        }
        func_0028af18(D_0035ee5c, 115);
        func_00287bd0(0, 0);
        return;
    }
    if (sel != -1 || func_00289310(D_0035ee5c)) {
        if (!func_0028ae28(D_0035ee5c, 0)) func_0028ab20(D_0035ee5c);
    }
    if (st == 0 && func_0028ae28(D_0035ee5c, 0)) func_00287c90(1);
    func_00287df0(sel, func_00289310(D_0035ee5c), 0, 0, 1);
    switch (sel) {
    case -1:
        break;
    case -2:
    case 1:
        func_0028aa40(D_0035ee5c);
        func_002519b0();
        func_00287c90(1);
        break;
    case 0: {
        s32 k;
        switch (func_00252110(func_002891e8(D_0035ee58))) {
        case 0: k = 60; break;
        case 1: k = 61; break;
        case 2: k = 62; break;
        case 3: k = 63; break;
        default: k = -1; break;
        }
        func_00287b08(k);
        func_00252618();
        func_00287da0();
        break;
    }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n00251780

// 002519b0 (was src/anon/tiny_wrappers_imp.cpp)
namespace n002519b0 {
u32 func_0028dac8(u32, u32, u32, u32) asm("_Z13func_0028dac8jjjj");
/*TARGET 002519b0*/
// 0x00242fa0: definition moved into src/anon/unit_00242478.cpp

u32 func_002519b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002519b0jjjj");
// 0x00242fa0: definition moved into src/anon/unit_00242478.cpp

u32 func_002519b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0036u << 16);
    r5 = (u32)((s32)0u + (9));
    r4 = *(u32*)((u32)r15 + (s32)(-4480));
    return func_0028dac8(r4, r5, r6, r7);
}
}  // namespace n002519b0

// 002519d0 (was src/anon/batch_w15.cpp)
namespace n002519d0 {
extern u32 D_0035ee80 asm("D_0035ee80");
extern u32 D_0035ee5c asm("D_0035ee5c");
u8 func_00139d78_u8(u32) asm("func_00139d78");
u8 func_0028acc8(u32) asm("func_0028acc8");
/*TARGET 002519d0*/
int func_002519d0(void) asm("func_002519d0");
int func_002519d0(void) {
    int r = func_00139d78_u8(D_0035ee80);
    if (!r) r = func_0028acc8(D_0035ee5c);
    return r;
}
}  // namespace n002519d0

// 00251a08 (was src/anon/auto80_199_queue.cpp)
namespace n00251a08 {
/*TARGET 00251a08*/
void func_00251a08(void) asm("_Z13func_00251a08v");
void func_00251a08(void) {
    if (func_00139d78(D_0035ee80) != 0) {
        u32 p = D_0035ee80;
        u32 vt = *(u32*)p;
        ((void(*)(u32))(*(u32*)(vt + 20)))(p);
    }
    if (func_0028acc8(D_0035ee5c) != 0) {
        func_0028abe0(D_0035ee5c);
    }
}
}  // namespace n00251a08

// 00251a70 (was src/anon/batch_w1580_g.cpp)
namespace n00251a70 {
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00287cd0(void) asm("func_00287cd0");
struct VObj { void (**vt)(VObj*); };
extern void* D_0035ee58 asm("D_0035ee58");
extern void* D_0035ee5c asm("D_0035ee5c");
extern void* D_0035ee60 asm("D_0035ee60");
extern VObj* D_0035ee64 asm("D_0035ee64");
extern VObj* D_0035ee68 asm("D_0035ee68");
void func_0023f070(void*, s32, s32) asm("func_0023f070");
s32 func_0023f0c0(void*) asm("func_0023f0c0");
void func_002519b0(void) asm("func_002519b0");
void func_00251d80(void*, s32, s32) asm("func_00251d80");
s32 func_00251e90(s32) asm("func_00251e90");
void func_00251fe0(void) asm("func_00251fe0");
void func_00252020(void) asm("func_00252020");
s32 func_00252110(s32) asm("func_00252110");
s32 func_00287c50(void) asm("func_00287c50");
s32 func_00287db0(void) asm("func_00287db0");
void func_00288018(void) asm("func_00288018");
s32 func_002891d0(void*) asm("func_002891d0");
s32 func_002891e8(void*) asm("func_002891e8");
void func_0028aa40(void*) asm("func_0028aa40");
s32 func_0028acb8(void*) asm("func_0028acb8");
s32 func_0028acc8(void*) asm("func_0028acc8");
void Tz__MenuCursor__Create(s32, s32, s32, void*, s32, s32) asm("Tz__MenuCursor__Create");
void func_0028cdb8(s32) asm("func_0028cdb8");
void func_0028ce38(void) asm("func_0028ce38");
void Tz__MenuCursor__SetType(s32, s32) asm("Tz__MenuCursor__SetType");
void Tz__MenuCursor__SetParent(s32, s32) asm("Tz__MenuCursor__SetParent");
void func_0028cf98(s32, s32) asm("func_0028cf98");
s32 func_0028d008(s32) asm("func_0028d008");
/*TARGET 00251a70*/
// 0x0025b5e0: definition moved into src/anon/unit_002588e8.cpp

void Tz__CANA__Draw(void) asm("Tz__CANA__Draw");
// 0x0025b5e0: definition moved into src/anon/unit_002588e8.cpp

void Tz__CANA__Draw(void) {
    s32 mode = func_00287bc0();
    s32 st = func_00287cd0();
    if (func_00287db0()) {
        if (!func_00139d78(D_0035ee60)) return;
        if (func_0023f0c0(D_0035ee60) == 2) return;
        if (func_00139d78(D_0035ee60) && func_0023f0c0(D_0035ee60) != 2) {
            func_0023f070(D_0035ee60, 2, -1);
        }
        if (func_0028acc8(D_0035ee58) && !func_0028acb8(D_0035ee58)) {
            func_0028aa40(D_0035ee58);
        }
        if (func_0028acc8(D_0035ee5c) && !func_0028acb8(D_0035ee5c)) {
            func_0028aa40(D_0035ee5c);
        }
        if (D_0035ee64 && func_00139d78(D_0035ee64)) {
            D_0035ee64->vt[5](D_0035ee64);
        }
        if (D_0035ee68 && func_00139d78(D_0035ee68)) {
            D_0035ee68->vt[5](D_0035ee68);
        }
        func_00251fe0();
        func_002519b0();
        func_0028ce38();
        func_00288018();
        return;
    }
    func_00252020();
    s32 h = func_00252110(func_002891e8(D_0035ee58));
    void* obj = mode == 0 ? D_0035ee58 : D_0035ee5c;
    s32 idx = mode != 0;
    if (func_00139d78(D_0035ee60) && func_0023f0c0(D_0035ee60) == 1) {
        if (idx == 0) {
            if (!func_0028d008(idx)) {
                Tz__MenuCursor__Create(idx, 2, 2, D_0035ee60, 4, 6);
                func_0028cf98(idx, func_00251e90(h));
            }
        } else {
            if (!func_0028d008(idx)) {
                Tz__MenuCursor__Create(idx, 2, 2, D_0035ee60, 12, 12);
                Tz__MenuCursor__SetParent(idx, func_002891d0(obj));
            }
        }
    } else if (st == 2 && func_0028d008(idx)) {
        func_0028cdb8(idx);
    }
    if (func_00287c50()) {
        if (func_0028d008(0)) Tz__MenuCursor__SetType(0, idx);
    }
    func_00251d80(obj, mode, h);
}
}  // namespace n00251a70

// 00251d80 (was src/anon/batch_w8010.cpp)
namespace n00251d80 {
s32 func_002891e8(s32) asm("func_002891e8");
// 0x00246328: definition moved into src/anon/unit_00242478.cpp

// ---- 00251d80
s32 func_00289310(void*) asm("func_00289310");
s32 func_0028d008(s32) asm("func_0028d008");
s32 func_00251e90(s32) asm("func_00251e90");
void func_0028cf98(s32, s32) asm("func_0028cf98");
void func_00251ec8(s32) asm("func_00251ec8");
void Tz__CANA__SetNewFlag(s32) asm("Tz__CANA__SetNewFlag");
void Tz__CANA__UpdateGra() asm("Tz__CANA__UpdateGra");
s32 func_00252000() asm("func_00252000");
void func_00251fe0() asm("func_00251fe0");
void func_002890e0(void*, s32, s32, s32, s32) asm("func_002890e0");
void func_00289038(void*, s32, s32, s32, s32, s32, s32) asm("func_00289038");
s32 func_002891d0(void*) asm("func_002891d0");
void Tz__MenuCursor__SetParent(s32, s32) asm("Tz__MenuCursor__SetParent");
/*TARGET 00251d80*/
void func_00251d80(void* obj, s32 mode, s32 h) asm("func_00251d80");
void func_00251d80(void* obj, s32 mode, s32 h)
{
    if (!func_00289310(obj)) return;
    if (mode == 0) {
        if (func_0028d008(0)) {
            func_0028cf98(0, func_00251e90(h));
            func_00251ec8(h);
            Tz__CANA__SetNewFlag(h);
        }
        Tz__CANA__UpdateGra();
        if (func_00252000()) func_00251fe0();
        return;
    }
    func_002890e0(obj, 1, 2, 0, -1);
    s32 s = func_002891e8((s32)obj);
    func_00289038(obj, s, 1, 1, 2, 0, -1);
    s = func_002891d0(obj);
    Tz__MenuCursor__SetParent(1, s);
}
}  // namespace n00251d80

// 00251e90 (was src/anon/batch_w16.cpp)
namespace n00251e90 {
void Tz__MenuUtil__GetLaySeq(u32, void*, void*) asm("Tz__MenuUtil__GetLaySeq");
extern u32 D_0035ee60 asm("D_0035ee60");
extern u8 D_00372608[8] asm("D_00372608");
extern u8 D_00372610[][8] asm("D_00372610");
/*TARGET 00251e90*/
// 0x002424c0: definition moved into src/anon/unit_00242478.cpp

void func_00251e90(s32 i) asm("func_00251e90");
// 0x002424c0: definition moved into src/anon/unit_00242478.cpp

void func_00251e90(s32 i) {  // to_28dbf8_entry8_b
    Tz__MenuUtil__GetLaySeq(D_0035ee60, D_00372608, D_00372610[i]);
}
}  // namespace n00251e90

// 00251ec8 (was src/anon/batch_w36.cpp)
namespace n00251ec8 {
// fprintf_stream_va

extern u32 D_0035ee64 asm("D_0035ee64");
s32 func_00139d78(u32) asm("func_00139d78");
extern u32 D_00372668[] asm("D_00372668");
void func_0023f5b8(u32, u32, u32) asm("func_0023f5b8");
/*TARGET 00251ec8*/
void func_00251ec8(s32 i) asm("func_00251ec8");
void func_00251ec8(s32 i) {
    if (D_0035ee64 && func_00139d78(D_0035ee64)) {
        u32 v = D_00372668[i];
        func_0023f5b8(D_0035ee64, v, 0);
    }
}
}  // namespace n00251ec8

// 00251f40 (was src/anon/auto80_199_queue.cpp)
namespace n00251f40 {
/*TARGET 00251f40*/
void func_00251f40(void) asm("_Z13func_00251f40v");
void func_00251f40(void) {
    if (func_00139d78(D_0035ee68) == 0) {
        func_0028d980(D_0035ee68, 30022, 2, 2, D_0035ee60, 20, 21, -1, 0);

        u32 s0 = D_0035ee68;
        *(u32*)(s0 + 408) = func_00192048(18405);

        *(u32*)(D_0035ee68 + 432) = 2;

        u32 a = D_0035ee68 + 24;
        *(u32*)(a + 184) = *(u32*)(a + 184) | 8;

        *(u8*)(D_0035ee68 + 405) = 1;
    }
}
}  // namespace n00251f40

// 00251fe0 (was src/anon/tiny_wrappers_imp.cpp)
namespace n00251fe0 {
u32 func_0028dac8(u32, u32, u32, u32) asm("_Z13func_0028dac8jjjj");
/*TARGET 00251fe0*/
u32 func_00251fe0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00251fe0jjjj");
u32 func_00251fe0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0036u << 16);
    r5 = (u32)((s32)0u + (22));
    r4 = *(u32*)((u32)r15 + (s32)(-4504));
    return func_0028dac8(r4, r5, r6, r7);
}
}  // namespace n00251fe0

// 00252000 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00252000 {
u32 func_00139d78(u32, u32, u32, u32) asm("_Z13func_00139d78jjjj");
/*TARGET 00252000*/
// 0x00242810: definition moved into src/anon/unit_00242478.cpp


u32 func_00252000(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00252000jjjj");
// 0x00242810: definition moved into src/anon/unit_00242478.cpp


u32 func_00252000(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)(0x0036u << 16);
    r4 = *(u32*)((u32)r15 + (s32)(-4504));
    u32 (*fp_call4_00139d78)(u32, u32, u32, u32) = func_00139d78;
    r2 = fp_call4_00139d78(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00252000

// 00252020 (was src/anon/batch_w37.cpp)
namespace n00252020 {
extern void* D_0035ee5c asm("D_0035ee5c");
s32 func_002892f8(void*) asm("func_002892f8");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_00288e88(void*) asm("func_00288e88");
/*TARGET 00252020*/
void func_00252020(void) asm("func_00252020");
void func_00252020(void) {
    if (!D_0035ee5c) return;
    s32 r = func_002892f8(D_0035ee5c);
    if (func_0028acc8(D_0035ee5c)) return;
    if (!r) return;
    func_00288e88(D_0035ee5c);
}
}  // namespace n00252020

// 00252098 (was src/anon/auto80_199_queue.cpp)
namespace n00252098 {
/*TARGET 00252098*/
u32 func_00252098(u32 a0) asm("_Z13func_00252098j");
u32 func_00252098(u32 a0) {
    u32 s0 = a0;
    u32 v0 = 1;
    u32 t = D_003725d0[a0];
    if (t != 0) {
        v0 = func_001a6d08(t);
    }
    if (s0 == 1) {
        v0 = (v0 ^ 1) & 0xFF;
    }
    return v0;
}
}  // namespace n00252098

// 002520f0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002520f0 {
u32 func_00252098(u32, u32, u32, u32) asm("_Z13func_00252098jjjj");
/*TARGET 002520f0*/
u32 func_002520f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002520f0jjjj");
u32 func_002520f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)0u + (1));
    u32 (*fp_call4_00252098)(u32, u32, u32, u32) = func_00252098;
    r2 = fp_call4_00252098(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002520f0

// 00252110 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n00252110 {
u32 func_002520f0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002520f0jjjjjjjj");
/*TARGET 00252110*/
u32 func_00252110(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00252110jjjjjjjj");
u32 func_00252110(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16;
    r16 = r4;
    if ((s32)r4 > 0) {
        r2 = ((u32(*)())func_002520f0)();
        r15 = (u32)((s32)r16 + (1));
        if (r2 == 0u) r16 = r15;
    }
    r2 = r16;
    return r2;
}
}  // namespace n00252110

// 00252148 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n00252148 {
u32 func_002520f0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002520f0jjjjjjjj");
/*TARGET 00252148*/
u32 func_00252148(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00252148jjjjjjjj");
u32 func_00252148(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16;
    r16 = r4;
    if ((s32)r4 > 0) {
        r2 = ((u32(*)())func_002520f0)();
        r15 = (u32)((s32)r16 + (-1));
        if (r2 == 0u) r16 = r15;
    }
    r2 = r16;
    return r2;
}
}  // namespace n00252148

// 00252180 (was src/anon/auto80_199_queue.cpp)
namespace n00252180 {
u32 func_00252098(u32 a0) asm("_Z13func_00252098j");
/*TARGET 00252180*/
void func_00252180(void) asm("_Z13func_00252180v");
void func_00252180(void) {
    func_00139d78(D_0035ee6c);
    if (func_00252098(1) != 0) {
        Tz__LaySeq__create(D_0035ee6c, 30003, 1, 1, D_0035ee60, (u32)&D_00372608, (u32)&D_00372618, 26, 0);
        *(u8*)(D_0035ee6c + 405) = 1;
        u32 a = D_0035ee6c + 24;
        *(u32*)(a + 184) = *(u32*)(a + 184) | 8;
    }
}
}  // namespace n00252180

// 00252208 (was src/anon/batch_wcx2.cpp)
namespace n00252208 {
struct Sub30 { u8 pad[184]; u32 flags; void SetF() { flags |= 8; } };
struct Obj30 { u8 pad[24]; Sub30 sub; u8 pad2[405 - 24 - 188]; u8 on; u8 pad3[26]; void SetOn() { on = 1; } };
extern Obj30* D_0035ee70 asm("D_0035ee70");
extern u32 D_0035ee60 asm("D_0035ee60");
extern u8 D_00372608[] asm("D_00372608");
extern u8 D_00372610[][8] asm("D_00372610");
u8* func_001058e8(void) asm("func_001058e8");
s32 func_00252098(s32) asm("func_00252098");
void Tz__LaySeq__create(Obj30*, s32, s32, s32, u32, u8*, u8*, s32, s32) asm("Tz__LaySeq__create");
/*TARGET 00252208*/
void func_00252208(void) asm("func_00252208");
void func_00252208(void)
{
    u32* bits = (u32*)(func_001058e8() + 18904);
    for (s32 i = 0; i < 4; i++) {
        if (!func_00252098(i)) continue;
        u32 b = i + 8;
        if (bits[b >> 5] & (1 << (b & 31))) continue;
        Tz__LaySeq__create(&D_0035ee70[i], 30012, 2, 2, D_0035ee60, D_00372608, D_00372610[i], 23, 0);
        D_0035ee70[i].SetOn();
        Sub30* sb = &D_0035ee70[i].sub;
        sb->SetF();
    }
}
}  // namespace n00252208

// 00252320 (was src/anon/batch_w3714.cpp)
namespace n00252320 {
// 00252320: const on D_00372638 makes the lh an unchanging read, so it gets no
// anti-dependence on the outgoing stack-argument store (sw zero,0(sp)).
struct W2446Sub { u8 pad[184]; u32 flags; void SetF() { flags |= 8; } };
struct W2446Obj { u8 pad[24]; W2446Sub sub; u8 pad2[405 - 24 - 188]; u8 on; u8 pad3[26]; void SetOn() { on = 1; } };
extern W2446Obj* D_0035ee74 asm("D_0035ee74");
extern u32 D_0035ee60 asm("D_0035ee60");
extern u8 D_00372608[] asm("D_00372608");
extern u8 D_00372610[][8] asm("D_00372610");
extern u16 D_003725d8[] asm("D_003725d8");
extern const s16 D_00372638[] asm("D_00372638");
s32 func_001a6d08(u32) asm("func_001a6d08");
void Tz__LaySeq__create(W2446Obj*, s32, s32, s32, u32, u8*, u8*, s32, s32) asm("Tz__LaySeq__create");
/*TARGET 00252320*/
void func_00252320(void) asm("func_00252320");
void func_00252320(void)
{
    for (s32 i = 0; i < 4; i++) {
        if (!func_001a6d08(D_003725d8[i])) continue;
        u32 t = D_0035ee60;
        s32 v = D_00372638[i];
        Tz__LaySeq__create(&D_0035ee74[i], 30011, 2, 2, t, D_00372608, D_00372610[i], v, 0);
        D_0035ee74[i].SetOn();
        W2446Sub* sb = &D_0035ee74[i].sub;
        sb->SetF();
    }
}
}  // namespace n00252320

// 00252428 (was src/anon/batch_w3882.cpp)
namespace n00252428 {
struct Sub30 { u8 pad[184]; u32 flags; void SetF() { flags |= 8; } };
struct Obj30 { u8 pad[24]; Sub30 sub; u8 pad2[405 - 24 - 188]; u8 on; u8 pad3[26]; void SetOn() { on = 1; } };
struct Pair { u16 key; u16 val; };
extern Obj30* D_0035ee78 asm("D_0035ee78");
extern u32 D_0035ee60 asm("D_0035ee60");
extern u8 D_00372608[] asm("D_00372608");
extern u8 D_00372610[][8] asm("D_00372610");
extern Pair D_003725e8[] asm("D_003725e8");
// The two tables are read-only: their loads then never depend on the outgoing-argument store.
extern const s16 D_00372640[] asm("D_00372640");
extern const s16 D_00372648[] asm("D_00372648");
s32 func_001a6d08(u32) asm("func_001a6d08");
s32 func_00181500(u32) asm("func_00181500");
void Tz__LaySeq__create(Obj30*, s32, s32, s32, u32, u8*, u8*, s32, s32) asm("Tz__LaySeq__create");
/*TARGET 00252428*/
// Picks the value of the first table entry whose key func_00181500 accepts, then calls Tz__LaySeq__create with it.
s32 func_00252428(void) asm("func_00252428");
// Picks the value of the first table entry whose key func_00181500 accepts, then calls Tz__LaySeq__create with it.
s32 func_00252428(void)
{
    s32 r = 0;
    for (s32 i = 0; D_003725e8[i].key != 0; i++) {
        if (func_00181500(D_003725e8[i].key)) { r = D_003725e8[i].val; break; }
    }
    s16 n;
    if (func_001a6d08(120)) n = D_00372640[r]; else n = D_00372648[r];
    Tz__LaySeq__create(D_0035ee78, 30004, 1, 1, D_0035ee60, D_00372608, D_00372610[r], n, 0);
    D_0035ee78->SetOn();
    Sub30* sb = &D_0035ee78->sub;
    sb->SetF();
    return r;
}
}  // namespace n00252428

// 00252540 (was src/anon/batch_w80.cpp)
namespace n00252540 {
// ---- unit 14 (good252.cpp)
struct U14_CurSub { u8 pad[184]; u32 f184; };
struct U14_CurObj { u8 pad[24]; U14_CurSub sub; u8 pad2[392 - 212]; s32 f392; u8 pad3[405 - 396]; u8 f405; };
extern union { U14_CurObj* p; u32 u; } U14_D_0035ee7c_u asm("D_0035ee7c");
extern u32 D_0035ee58 asm("D_0035ee58");
extern u32 D_0035ee60 asm("D_0035ee60");
struct U14_CurPos { s16 x, f2, y; };
extern U14_CurPos D_00372650[] asm("D_00372650");
s32 func_00139d78(void*) asm("func_00139d78");
u32 func_002891e8(u32) asm("func_002891e8");
s32 func_00252110(u32) asm("func_00252110");
void func_0028da70(U14_CurObj*, s32) asm("func_0028da70");
void func_0028d8c0(U14_CurObj*, u32, u32, u32, u32, s32, s32, u32) asm("func_0028d8c0");
static inline void U14_w80_cur_setflag(U14_CurSub* s, u32 f) { s->f184 |= f; }
/*TARGET 00252540*/
void Tz__CANA__UpdateGra(void) asm("Tz__CANA__UpdateGra");
void Tz__CANA__UpdateGra(void) {
    s32 i = func_00252110(func_002891e8(D_0035ee58));
    if (!func_00139d78(U14_D_0035ee7c_u.p)) {
        func_0028d8c0(U14_D_0035ee7c_u.p, 30015, 3, 3, D_0035ee60, D_00372650[i].x, D_00372650[i].y, 0);
        U14_D_0035ee7c_u.p->f405 = 1;
        U14_w80_cur_setflag(&U14_D_0035ee7c_u.p->sub, 8);
    } else {
        func_0028da70(U14_D_0035ee7c_u.p, D_00372650[i].y);
        U14_D_0035ee7c_u.p->f392 = -1;
    }
}
}  // namespace n00252540

// 00252618 (was src/anon/batch_w53.cpp)
namespace n00252618 {
extern u32 D_0035ee58 asm("D_0035ee58");
extern u32 D_0035ee7c asm("D_0035ee7c");
struct E6 { s16 a; s16 b; s16 c; };
extern E6 D_00372650[] asm("D_00372650");
u32 func_002891e8(u32) asm("func_002891e8");
s32 func_00252110(u32) asm("func_00252110");
void func_0028dac8(u32, s32) asm("func_0028dac8");
/*TARGET 00252618*/
void func_00252618(void) asm("func_00252618");
void func_00252618(void) {
    s32 i = func_00252110(func_002891e8(D_0035ee58));
    func_0028dac8(D_0035ee7c, D_00372650[i].b);
}
}  // namespace n00252618

// 00252660 (was src/anon/batch_wcx.cpp)
namespace n00252660 {
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00138c10(u8*, s32) asm("func_00138c10");
// 0x0024c898: definition moved into src/anon/unit_0024ba58.cpp
u8* func_001058e8(void) asm("func_001058e8");
extern u8* D_0035ee70 asm("D_0035ee70");
/*TARGET 00252660*/
void Tz__CANA__SetNewFlag(s32 i) asm("Tz__CANA__SetNewFlag");
void Tz__CANA__SetNewFlag(s32 i)
{
    u32* bits = (u32*)(func_001058e8() + 18904);
    u32 k = i + 8;
    u32 m = 1 << (k & 31);
    u32 w = bits[k >> 5];
    if (!(w & m)) bits[k >> 5] = w | m;
    if (u_call4_00139d78(D_0035ee70 + i * 432)) {
        u8* o = D_0035ee70 + i * 432;
        if (*(s32*)(o + 388) != 24) func_00138c10(o, 24);
    }
}
}  // namespace n00252660

// 00252710 (was src/anon/batch_w63.cpp)
namespace n00252710 {
u32 func_00252110(void) asm("func_00252110");
s32 func_001a6d08(u8) asm("func_001a6d08");
extern u8 D_00372600[] asm("D_00372600");
/*TARGET 00252710*/
s32 func_00252710(void) asm("func_00252710");
s32 func_00252710(void) {
    s32 r = 0;
    u8 c = D_00372600[func_00252110()];
    if (c) r = func_001a6d08(c) != 0;
    return r;
}
}  // namespace n00252710

// 00252760 (was src/anon/batch_wcx2.cpp)
namespace n00252760 {
// 001091c8: moved to src/anon/unit_001085a8.cpp

// ---- 00252760
void func_00287b18(u32, u32) asm("func_00287b18");
union UG_00252760 { u32 i; u16 h; u8* p; };
extern UG_00252760 D_0035ee9c_2760 asm("D_0035ee9c");
extern UG_00252760 D_0035eea0_2760 asm("D_0035eea0");
extern UG_00252760 D_0035eea4_2760 asm("D_0035eea4");
extern UG_00252760 D_0035eea8_2760 asm("D_0035eea8");
extern u8* D_00347f80_2760 asm("D_00347f80");
struct VT_00252760 { void* (*f)(void*, u32, u32); };
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
void func_00239700(u8*) asm("func_00239700");
u8* func_00103eb0() asm("func_00103eb0");
void func_00252890() asm("func_00252890");
void func_00102818_2760(u32, u32, u32, void (*)(), u32) asm("TASK_MANAGER__create_thread");
/*TARGET 00252760*/
void Tz__ALCA__Init() asm("Tz__ALCA__Init");
void Tz__ALCA__Init() {
    func_00287b18(5, 3);
    D_0035ee9c_2760.i = 0;
    D_0035eea0_2760.h = 0;
    D_0035eea4_2760.i = 0;
    VT_00252760** al = *(VT_00252760***)(D_00347f80_2760 + 20);
    u8* o = (u8*)(*al)->f(al, 436, 0);
    *(u32*)(o + 12) = 0;
    *(u32*)o = (u32)D_00347e60;
    func_00239700(o + 24);
    *(u32*)(o + 408) = 0;
    *(u32*)o = (u32)D_00347e40;
    D_0035eea8_2760.p = o;
    func_00102818_2760(*(u32*)(func_00103eb0() + 4), 0, 2000, func_00252890, 4096);
}
}  // namespace n00252760

// 00252810 (was src/anon/auto80_199_queue.cpp)
namespace n00252810 {
/*TARGET 00252810*/
void func_00252810(void) asm("_Z13func_00252810v");
void func_00252810(void) {
    u32 p = D_0035ee9c;
    if (p != 0) {
        func_00106450(p);
        D_0035ee9c = 0;
    }

    p = D_0035eea8;
    if (p != 0) {
        u32 vt = *(u32*)p;
        ((void(*)(u32))(*(u32*)(vt + 16)))(p);
        D_0035eea8 = 0;
    }

    p = D_0035eea4;
    if (p != 0) {
        u32 vt = *(u32*)p;
        ((void(*)(u32))(*(u32*)(vt + 16)))(p);
        D_0035eea4 = 0;
    }
}
}  // namespace n00252810

// 00252890 (was src/anon/auto80_199_queue.cpp)
namespace n00252890 {
/*TARGET 00252890*/
void func_00252890(u32 a0) asm("_Z13func_00252890j");
void func_00252890(u32 a0) {
    u32 s0 = a0;
    func_002430d8(D_0035ee88);
    func_00102448(s0, 1);
    Tz__ALCA__PauseThread();
    while (1) {
        YI__IMAGE_CACHE__Clear();  // clear_64_entries_24
        if (func_00252ad8() != 0) {
            return;
        }
        func_00252f98();
        func_00102448(s0, 0);
    }
}
}  // namespace n00252890

// 00252900 (was src/anon/batch_w233.cpp)
namespace n00252900 {
// 0x001e26b8: definition moved into src/anon/unit_001e0cb8.cpp

extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u32* D_0035eea4 asm("D_0035eea4");
extern s16* D_0035ee9c asm("D_0035ee9c");
void func_002529a8() asm("func_002529a8");
u32* func_0023ee30(u32) asm("func_0023ee30");
void func_0031a838(u32*) asm("func_0031a838");
void YI__IMAGE_FREEZE__IMAGE_FREEZE(u32*) asm("YI__IMAGE_FREEZE__IMAGE_FREEZE");
// obj_ctor_36eac8
void YI__LAYOUT__LAYOUT(u32*) asm("YI__LAYOUT__LAYOUT");
// obj_ctor_36eae8
void Tz__MenuUtil__CreateLay(u32*, s32, s32, s32, s32, s32, s32, s32, s32) asm("Tz__MenuUtil__CreateLay");
void Tz__Layout__SetImageCache(u32*) asm("Tz__Layout__SetImageCache");
void Tz__ALCA__ChgMode() asm("Tz__ALCA__ChgMode");
/*TARGET 00252900*/
void Tz__ALCA__PauseThread() asm("Tz__ALCA__PauseThread");
void Tz__ALCA__PauseThread() {
    func_002529a8();
    u32* p = func_0023ee30(160);
    *p = (u32)D_00347f98;
    func_0031a838(p + 3);
    *p = (u32)D_0035eb98;
    YI__IMAGE_FREEZE__IMAGE_FREEZE(p + 6);  // obj_ctor_36eac8
    YI__LAYOUT__LAYOUT(p + 12);  // obj_ctor_36eae8
    D_0035eea4 = p;
    Tz__MenuUtil__CreateLay(p, 30002, 0, 0, D_0035ee9c[0], D_0035ee9c[1], 0, 0, 0);
    Tz__Layout__SetImageCache(D_0035eea4);
    Tz__ALCA__ChgMode();
}
}  // namespace n00252900

// 002529a8 (was src/anon/batch_w92.cpp)
namespace n002529a8 {
u32 func_00103570(void) asm("func_00103570");
s16* func_001063f0(u32, u32) asm("func_001063f0");
s32 func_001a6d08(s16) asm("func_001a6d08");
union P252 { s16* p; u32 u; s16 h; };
extern P252 D_0035ee9c asm("D_0035ee9c");
extern s16 D_0035eea0 asm("D_0035eea0");
extern u16* D_0035ee90[] asm("D_0035ee90");
extern s16 D_003726a8[] asm("D_003726a8");
/*TARGET 002529a8*/
void func_002529a8(void) asm("func_002529a8");
void func_002529a8(void) {
    s32 i;
    D_0035ee9c.p = func_001063f0(24, func_00103570());
    for (i = 0; i < 12; i++) D_0035ee9c.p[i] = -1;
    D_0035ee9c.p[0] = 0;
    s32 n = 1;
    for (i = 0; i < 3; i++) {
        if (func_001a6d08(D_003726a8[i])) {
            u16* t = D_0035ee90[i];
            D_0035ee9c.p[n++] = t[0];
            D_0035ee9c.p[n++] = t[2];
            D_0035ee9c.p[n++] = t[1];
        }
    }
    D_0035ee9c.p[n++] = 1;
    D_0035eea0 = n;
}
}  // namespace n002529a8

// 00252ad8 (was src/anon/batch_w1595.cpp)
namespace n00252ad8 {
// 0x00283b78: definition moved into src/anon/unit_00282c68.cpp

void func_001039f8() asm("func_001039f8");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00252ba8() asm("func_00252ba8");
void func_00252bf0() asm("func_00252bf0");
void func_00252c20() asm("func_00252c20");
s32 func_00287bc0() asm("func_00287bc0");
void Tz__MenuBase__SaveMode() asm("Tz__MenuBase__SaveMode");
s32 func_00287db0() asm("func_00287db0");
extern void* D_0035eea4 asm("D_0035eea4");
extern void* D_0035eea8 asm("D_0035eea8");
/*TARGET 00252ad8*/
s32 func_00252ad8(void) asm("func_00252ad8");
s32 func_00252ad8(void) {
    s32 s = func_00287bc0();
    Tz__MenuBase__SaveMode();
    if (func_00287db0()) {
        if ((D_0035eea4 && func_00139d78(D_0035eea4)) || func_00139d78(D_0035eea8)) return 0;
        func_001039f8();
        return 1;
    }
    switch (s) {
    case 0: func_00252ba8(); break;
    case 1: case 2: case 3: func_00252c20(); break;
    case 4: func_00252bf0(); break;
    }
    return 0;
}
}  // namespace n00252ad8

// 00252ba8 (was src/anon/tiny_auto80_queue.cpp)
namespace n00252ba8 {
extern u32 D_0035eea4 asm("D_0035eea4");
// set_global_byte1
extern "C" u32 func_0023f100(...) asm("func_0023f100");
void func_00252ce0(...) asm("func_00252ce0");
void Tz__ALCA__ChgMode(...) asm("Tz__ALCA__ChgMode");
void Tz__ALCA__SetMess(...) asm("Tz__ALCA__SetMess");
/*TARGET 00252ba8*/
void func_00252ba8() asm("_Z13func_00252ba8v");
void func_00252ba8() {
    if (func_0023f100(D_0035eea4) == (u32)-1) {
        func_00252ce0();
        Tz__ALCA__ChgMode();
        Tz__ALCA__SetMess();
    }
}
}  // namespace n00252ba8

// 00252bf0 (was src/anon/tiny_auto80_queue.cpp)
namespace n00252bf0 {
extern u32 D_0035eea4 asm("D_0035eea4");
// set_global_byte1
extern "C" u32 func_0023f100(...) asm("func_0023f100");
void func_00287da0(...) asm("_ZN2Tz8MenuBase7SetExitEv");
/*TARGET 00252bf0*/
void func_00252bf0() asm("_Z13func_00252bf0v");
void func_00252bf0() {
    if (func_0023f100(D_0035eea4) == (u32)-1) {
        func_00287da0();
    }
}
}  // namespace n00252bf0

// 00252c20 (was src/anon/batch_w81.cpp)
namespace n00252c20 {
// 0x00248828: definition moved into src/anon/unit_00247ff0.cpp

// --- 00252c20
extern u32 D_0035eea4 asm("D_0035eea4");
extern u8* D_0035ee90[] asm("D_0035ee90");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0023f100(u32) asm("func_0023f100");
s32 func_0023f0c0(u32) asm("func_0023f0c0");
void func_00252ce0(void) asm("func_00252ce0");
void Tz__ALCA__ChgMode(void) asm("Tz__ALCA__ChgMode");
void Tz__ALCA__SetMess(void) asm("Tz__ALCA__SetMess");
u8* func_00167f18(u32) asm("func_00167f18");
void func_00242618(u32, u32) asm("func_00242618");
void func_0023f108(u32) asm("func_0023f108");
/*TARGET 00252c20*/
void func_00252c20(void) asm("func_00252c20");
void func_00252c20(void) {
    s32 n = func_00287bc0();
    s16 id = *(s16*)(D_0035ee90[n - 1] + 4);
    if (func_0023f100(D_0035eea4) == -1) {
        func_00252ce0();
        Tz__ALCA__ChgMode();
        Tz__ALCA__SetMess();
    }
    if (func_0023f0c0(D_0035eea4) != id) return;
    if (!(*(u64*)(func_00167f18(0) + 8) & 4)) return;
    func_00242618(2, 1);
    func_0023f108(D_0035eea4);
}
}  // namespace n00252c20

// 00252ce0 (was src/anon/batch_wcx.cpp)
namespace n00252ce0 {
extern u8* D_0035eea4 asm("D_0035eea4");
extern s16 D_0035eea0 asm("D_0035eea0");
extern s16* D_0035ee9c asm("D_0035ee9c");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
s32 func_0023f100(u8*) asm("func_0023f100");
s32 func_0023f0c0(u8*) asm("func_0023f0c0");
void func_0023f0c8(u8*, s32) asm("func_0023f0c8");
/*TARGET 00252ce0*/
void func_00252ce0(void) asm("func_00252ce0");
void func_00252ce0(void)
{
    u_call4_00139d78(D_0035eea4);
    if (func_0023f100(D_0035eea4) != -1) return;
    s32 v = func_0023f0c0(D_0035eea4);
    s32 r = -1;
    for (s32 i = 0; i < D_0035eea0; i++) {
        if (v == D_0035ee9c[i]) { r = D_0035ee9c[i + 1]; break; }
    }
    if (r >= 0) func_0023f0c8(D_0035eea4, r);
}
}  // namespace n00252ce0

// 00252d88 (was src/anon/batch_w89.cpp)
namespace n00252d88 {
extern void* D_0035eea4 asm("D_0035eea4");
extern s16* D_0035ee90[3] asm("D_0035ee90");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0023f0c0(void*) asm("func_0023f0c0");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287bd0(s32, s32) asm("func_00287bd0");
/*TARGET 00252d88*/
void Tz__ALCA__ChgMode(void) asm("Tz__ALCA__ChgMode");
void Tz__ALCA__ChgMode(void) {
    s32 idx = 0;
    func_00139d78(D_0035eea4);
    s32 v = func_0023f0c0(D_0035eea4);
    if (v != 0) {
        if (v == 1) idx = 4;
        else {
            idx = -1;
            for (s32 i = 0; i < 3; i++) {
                s16* p = D_0035ee90[i];
                for (s32 j = 0; j < 3; j++) {
                    if (v == p[j]) { idx = i + 1; break; }
                }
                if (idx >= 0) break;
            }
        }
    }
    if (func_00287bc0() != idx) func_00287bd0(idx, 0);
}
}  // namespace n00252d88

// 00252e50 (was src/anon/batch_wcx2.cpp)
namespace n00252e50 {
extern u32 D_0035eea4 asm("D_0035eea4");
extern s16 D_0035eea0 asm("D_0035eea0");
extern s16* D_0035ee9c asm("D_0035ee9c");
extern u8* D_0035eea8 asm("D_0035eea8");
s16 func_0023f0c0(u32) asm("func_0023f0c0");
s32 func_00139d78(void*) asm("func_00139d78");
struct Obj3;
void func_00138c10(Obj3*, s32) asm("func_00138c10");
void func_0028d980(u8*, s32, s32, s32, u32, s32, s32, s32, s32) asm("func_0028d980");
u32 func_0023aa98(u8*) asm("func_0023aa98");
u32 func_0028dd90(u32) asm("func_0028dd90");
// mod10_classify_012
s32 func_00192048(s32) asm("func_00192048");
/*TARGET 00252e50*/
void Tz__ALCA__SetMess(void) asm("Tz__ALCA__SetMess");
void Tz__ALCA__SetMess(void)
{
    s16 v = func_0023f0c0(D_0035eea4);
    s32 idx = -1;
    for (s32 i = 0; i < D_0035eea0; i++) {
        if (v == D_0035ee9c[i]) {
            idx = i;
            break;
        }
    }
    if (idx == D_0035eea0 - 2) {
        func_00139d78(D_0035eea8);
        func_00138c10((Obj3*)D_0035eea8, 15);
        *(s32*)(D_0035eea8 + 392) = -1;
        return;
    }
    s32 code = idx >= D_0035eea0 - 4 ? 4101 : 4100;
    if (!func_00139d78(D_0035eea8)) {
        func_0028d980(D_0035eea8, 30012, 0, 0, D_0035eea4, 13, 14, code, 0);
        u32 x = func_0023aa98(D_0035eea8 + 24);
        u8* o = D_0035eea8;
        *(u32*)(o + 432) = func_0028dd90(x);
    } else if (func_00139d78(D_0035eea8)) {
        s32 r = func_00192048(code);
        if (*(s32*)(D_0035eea8 + 408) != r) *(s32*)(D_0035eea8 + 408) = r;
    }
}
}  // namespace n00252e50

// 00252f98 (was src/anon/tiny_auto80_queue.cpp)
namespace n00252f98 {
extern u32 D_0035eea8 asm("D_0035eea8");
u32 func_00287db0(...) asm("func_00287db0");
// 0x002251c8: definition moved into src/anon/unit_00224780.cpp

extern "C" u32 func_00139d78(...) asm("func_00139d78");
/*TARGET 00252f98*/
void func_00252f98() asm("_Z13func_00252f98v");
void func_00252f98() {
    if (func_00287db0() != 0) {
        if (func_00139d78(D_0035eea8) != 0) {
            u32 t7 = D_0035eea8;
            u32 t6 = *(u32*)t7;
            u32 t5 = *(u32*)(t6 + 20);
            ((void(*)(u32))t5)(t7);
        }
    }
}
}  // namespace n00252f98

