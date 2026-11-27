// Linked unit 0x00274460-0x002772c8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/jiminy.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
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
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/cmenu_stat.hpp"
#include "../tozawa/cmenu_ability.hpp"

// 00274460 (was gap, written for the unit): Jiminy menu exit (frees what 0x273fa0 made)
namespace n00274460 {
struct T32 { u8 d[32]; ~T32() {} } __attribute__((aligned(16)));
struct Ob;
typedef void (*ObFn)(Ob*);
struct Ob { ObFn* vt; };
struct Hp;
struct HpVt { void* a; void (*free)(Hp*, void*); };
struct Hp { HpVt* vt; };
extern s32 D_0035f138 asm("D_0035f138");
extern s32 D_0035f13c asm("D_0035f13c");
extern u32 D_0035f140 asm("D_0035f140");
extern s32 D_0035f144 asm("D_0035f144");
extern s8* D_0035f1fc asm("D_0035f1fc");
extern void* D_0035f200 asm("D_0035f200");
extern Ob* D_0035f204 asm("D_0035f204");
extern Ob* D_0035f208 asm("D_0035f208");
extern u8* D_0035f20c asm("D_0035f20c");
extern Ob* D_0035f210 asm("D_0035f210");
extern void* D_0035f214 asm("D_0035f214");
extern Ob* D_0035f218 asm("D_0035f218");
extern u8* D_0035f21c asm("D_0035f21c");
extern u8 D_0035f220 asm("D_0035f220");
extern u8 D_0035f221 asm("D_0035f221");
extern T32* D_0035f224 asm("D_0035f224");
extern s8 D_0035f228 asm("D_0035f228");
extern Hp* D_0032ba14 asm("D_0032ba14");
extern u8 D_00347e60[] asm("D_00347e60");
void func_0013aa38(s32) asm("func_0013aa38");
void JmInfoExit(void) asm("_ZN2Tz6JmInfo4ExitEv");
void func_002a2010(void) asm("func_002a2010");
void func_00294550(void) asm("func_00294550");
void func_00295810(void) asm("func_00295810");
void func_00296fd0(void) asm("func_00296fd0");
void func_00297d78(void) asm("func_00297d78");
void func_00299550(void) asm("func_00299550");
void func_0029a8e0(void) asm("func_0029a8e0");
void func_0029edf8(void) asm("func_0029edf8");
void Tz__JmDiagram__Exit(void) asm("Tz__JmDiagram__Exit");
void func_002a4d48(void) asm("func_002a4d48");
void func_002a6970(void) asm("func_002a6970");
void func_002a76d8(void) asm("func_002a76d8");
void func_002a8a00(void) asm("func_002a8a00");
void func_002a9d30(void) asm("func_002a9d30");
void func_002aceb0(void) asm("func_002aceb0");
void Tz__JmPuzzle__Exit(void) asm("Tz__JmPuzzle__Exit");
void SelectDtor(void*) asm("_ZN2Tz6SelectD1Ev");
void func_00288c20(void*) asm("func_00288c20");
void func_0028ba80(void*) asm("func_0028ba80");
void func_0031abd8(u8*) asm("func_0031abd8");
void func_0031acc0(u8*) asm("func_0031acc0");
void SeqDtor(u8*) asm("_ZN2YI8SEQUENCED1Ev");
void func_0031a840(u8*) asm("func_0031a840");
void LoadDataFree(void*) asm("func_00106420");
void func_0028d068(s32, s32) asm("_Z16wtarget_0028d068jjjj");
void Tz__SelHist__Exit(void) asm("Tz__SelHist__Exit");
void Tz__UnitLoad__Exit(void) asm("Tz__UnitLoad__Exit");
void func_00274460(void) asm("func_00274460");
void func_00274460(void) {
    if (D_0035f228 >= 0) func_0013aa38(D_0035f228);
    D_0035f228 = -1;
    if (!(D_0035f140 & 4)) JmInfoExit();
    func_002a2010();
    func_00294550();
    func_00295810();
    func_00296fd0();
    func_00297d78();
    func_00299550();
    func_0029a8e0();
    func_0029edf8();
    Tz__JmDiagram__Exit();
    func_002a4d48();
    func_002a6970();
    func_002a76d8();
    func_002a8a00();
    func_002a9d30();
    func_002aceb0();
    Tz__JmPuzzle__Exit();
    D_0035f144 = -1;
    if (D_0035f200) {
        void* s = D_0035f200;
        SelectDtor(s);
        func_00288c20(s);
        D_0035f200 = 0;
    }
    if (D_0035f210) {
        D_0035f210->vt[4](D_0035f210);
        D_0035f210 = 0;
    }
    if (D_0035f204) {
        D_0035f204->vt[4](D_0035f204);
        D_0035f204 = 0;
    }
    if (D_0035f208) {
        D_0035f208->vt[4](D_0035f208);
        D_0035f208 = 0;
    }
    if (D_0035f214) {
        void* l = D_0035f214;
        func_0028ba80(l);
        D_0032ba14->vt->free(D_0032ba14, l);
        D_0035f214 = 0;
    }
    if (D_0035f218) {
        D_0035f218->vt[4](D_0035f218);
        D_0035f218 = 0;
    }
    if (D_0035f20c) {
        u8* q = D_0035f20c;
        func_0031acc0(q + 1308);
        func_0031acc0(q + 872);
        func_0031acc0(q + 436);
        *(u32*)q = (u32)D_00347e60;
        SeqDtor(q + 24);
        func_0031a840(q);
        LoadDataFree(q);
        D_0035f20c = 0;
    }
    if (D_0035f1fc) {
        LoadDataFree(D_0035f1fc);
        D_0035f1fc = 0;
    }
    if (D_0035f21c) {
        u8* p = D_0035f21c;
        u8* e;
        if (p + 0xdca0) {
            e = p + 0x110a0; for (;;) { if (p + 0xdca0 == e) break; e -= 416; ((Ob*)e)->vt[0]((Ob*)e); }
        }
        if (p + 0xa998) {
            e = p + 0xdc98; for (;;) { if (p + 0xa998 == e) break; e -= 408; ((Ob*)e)->vt[3]((Ob*)e); }
        }
        if (p + 30360) {
            e = p + 0xa998; for (;;) { if (p + 30360 == e) break; e -= 408; ((Ob*)e)->vt[3]((Ob*)e); }
        }
        if (p + 17304) {
            e = p + 30360; for (;;) { if (p + 17304 == e) break; e -= 408; ((Ob*)e)->vt[3]((Ob*)e); }
        }
        if (p + 4248) {
            e = p + 17304; for (;;) { if (p + 4248 == e) break; e -= 408; ((Ob*)e)->vt[3]((Ob*)e); }
        }
        func_0031acc0(p + 3812);
        func_0031acc0(p + 3376);
        func_0031acc0(p + 2940);
        func_0031acc0(p + 2504);
        func_0031acc0(p + 2068);
        func_0031acc0(p + 1632);
        func_0031abd8(p + 1224);
        func_0031abd8(p + 816);
        func_0031abd8(p + 408);
        *(u32*)p = (u32)D_00347e60;
        SeqDtor(p + 24);
        func_0031a840(p);
        LoadDataFree(p);
        D_0035f21c = 0;
    }
    if (D_0035f224) {
        delete[] D_0035f224;
        D_0035f224 = 0;
    }
    func_0028d068(D_0035f13c, -1);
    D_0035f138 = D_0035f13c = -1;
    D_0035f220 = 0;
    D_0035f221 = 0;
    Tz__SelHist__Exit();
    Tz__UnitLoad__Exit();
}
}  // namespace n00274460

// 002748a0 (was src/anon/batch_w98.cpp)
namespace n002748a0 {
extern u8* D_0035f200 asm("D_0035f200");
extern u8* D_0035f204 asm("D_0035f204");
extern u8* D_0035f208 asm("D_0035f208");
extern u8* D_0035f218 asm("D_0035f218");
s32 func_0028acc8(u8*) asm("func_0028acc8");
s32 func_0028acb8(u8*) asm("func_0028acb8");
u8* func_002891b8(u8*, s32) asm("func_002891b8");
void func_0028aa40(u8*) asm("func_0028aa40");
s32 func_00139d78(u8*) asm("func_00139d78");
void func_00276300(void) asm("func_00276300");
void func_0028f7a0(void) asm("func_0028f7a0");
void func_0028d5d0(u8*) asm("func_0028d5d0");
void Tz__Jiminy__FadeOutHelp(void) asm("Tz__Jiminy__FadeOutHelp");
void func_002945a0(void) asm("func_002945a0");
void func_00295860(void) asm("func_00295860");
void func_00297008(void) asm("func_00297008");
void func_00297df8(void) asm("func_00297df8");
void func_002995a0(void) asm("func_002995a0");
void func_0029aa30(void) asm("func_0029aa30");
void func_0029ee30(void) asm("func_0029ee30");
void func_002a0780(void) asm("func_002a0780");
void func_002a2148(void) asm("func_002a2148");
void func_002a4df0(void) asm("func_002a4df0");
void func_002a6a10(void) asm("func_002a6a10");
void func_002a7758(void) asm("func_002a7758");
void func_002a8a80(void) asm("func_002a8a80");
void func_002aece8(void) asm("func_002aece8");
void func_00275c78(void) asm("func_00275c78");
static inline bool Busy274(u8* m) { return *(u32*)(m + 400) || *(u32*)(m + 396); }
/*TARGET 002748a0*/
// Per-frame update of the menu subsystems.
void func_002748a0(void) asm("func_002748a0");
// Per-frame update of the menu subsystems.
void func_002748a0(void) {
    if (func_0028acc8(D_0035f200) && !func_0028acb8(D_0035f200)) {
        if (!Busy274(func_002891b8(D_0035f200, 0))) func_0028aa40(D_0035f200);
    }
    if (func_00139d78(D_0035f204)) func_00276300();
    if (func_00139d78(D_0035f208)) (*(void (**)(u8*))(*(u8**)D_0035f208 + 20))(D_0035f208);
    func_0028f7a0();
    func_0028d5d0(D_0035f218);
    Tz__Jiminy__FadeOutHelp();
    func_002945a0();
    func_00295860();
    func_00297008();
    func_00297df8();
    func_002995a0();
    func_0029aa30();
    func_0029ee30();
    func_002a0780();
    func_002a2148();
    func_002a4df0();
    func_002a6a10();
    func_002a7758();
    func_002a8a80();
    func_002aece8();
    Tz__Jiminy__FadeOutHelp();
    func_00275c78();
}
}  // namespace n002748a0

// 002749f0 (was src/anon/batch_w83.cpp)
namespace n002749f0 {
struct VObj20 { virtual void f0(); virtual void f4(); virtual void f8(); virtual void f12(); virtual void f16(); virtual void f20(); };
s32 func_00139d78(void*) asm("func_00139d78");
// 0x0026af30: definition moved into src/anon/unit_0026a900.cpp

extern VObj20* D_0035f208 asm("D_0035f208");
extern void* D_0035f218 asm("D_0035f218");
void func_00274ac8(void) asm("func_00274ac8");
void Tz__SelHist__LeaveAll(void) asm("Tz__SelHist__LeaveAll");
void func_0028d620(void*) asm("func_0028d620");
void func_00276e28(void) asm("func_00276e28");
void func_002945a8(void) asm("func_002945a8");
void func_00295868(void) asm("func_00295868");
void func_00297010(void) asm("func_00297010");
void Tz__JmAlbum__LeaveAll(s32) asm("Tz__JmAlbum__LeaveAll");
void Tz__JmCollection__LeaveAll(void) asm("Tz__JmCollection__LeaveAll");
void func_0029aac0(s32) asm("func_0029aac0");
void Tz__JmAnsem__LeaveAll(void) asm("Tz__JmAnsem__LeaveAll");
void func_002a07f0(s32) asm("func_002a07f0");
void func_002a2150(void) asm("func_002a2150");
void func_002a4df8(void) asm("func_002a4df8");
void Tz__JmSynthe__LeaveAll(void) asm("Tz__JmSynthe__LeaveAll");
void Tz__JmMiniGame__LeaveAll(void) asm("Tz__JmMiniGame__LeaveAll");
void Tz__JmQuest__LeaveAll(void) asm("Tz__JmQuest__LeaveAll");
void func_002aecf0(s32) asm("func_002aecf0");
void func_00275cb8(void) asm("func_00275cb8");
void func_002763c8(void) asm("func_002763c8");
/*TARGET 002749f0*/
void Tz__Jiminy__LeaveAll(void) asm("Tz__Jiminy__LeaveAll");
void Tz__Jiminy__LeaveAll(void) {
    func_00274ac8();
    if (func_00139d78(D_0035f208)) D_0035f208->f20();
    Tz__SelHist__LeaveAll();
    func_0028d620(D_0035f218);
    func_00276e28();
    func_002945a8();
    func_00295868();
    func_00297010();
    Tz__JmAlbum__LeaveAll(-1);
    Tz__JmCollection__LeaveAll();
    func_0029aac0(-1);
    Tz__JmAnsem__LeaveAll();
    func_002a07f0(-1);
    func_002a2150();
    func_002a4df8();
    Tz__JmSynthe__LeaveAll();
    Tz__JmMiniGame__LeaveAll();
    Tz__JmQuest__LeaveAll();
    func_002aecf0(1);
    func_00275cb8();
    func_002763c8();
}
}  // namespace n002749f0

// 00274ac8 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00274ac8
extern u32 D_0035f204 asm("D_0035f204");
extern u32 D_0035f200 asm("D_0035f200");
extern u32 D_0035f214 asm("D_0035f214");
u32 func_00139d78(...) asm("func_00139d78");
u32 func_0028acc8(...) asm("func_0028acc8");
void func_0028abe0(...) asm("func_0028abe0");
u32 func_0028be58(...) asm("func_0028be58");
void func_0028be18(...) asm("func_0028be18");
void Tz__Jiminy__LeaveSeqTbl() asm("Tz__Jiminy__LeaveSeqTbl");
/*TARGET 00274ac8*/
void Tz_Jiminy_JmCommonLeave() asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
void Tz_Jiminy_JmCommonLeave() {
    if (func_0028acc8(D_0035f200) != 0) {
        func_0028abe0(D_0035f200);
    }

    if (func_00139d78(D_0035f204) != 0) {
        u32 obj = D_0035f204;
        u32 vtbl = *(u32*)obj;
        u32 fn = *(u32*)(vtbl + 20);
        ((void (*)(u32))fn)(obj);
    }

    if (func_0028be58(D_0035f214) != 0) {
        func_0028be18(D_0035f214);
    }

    Tz__Jiminy__LeaveSeqTbl();
}
}  // Tz

// 00274b40 (was src/anon/batch_w287.cpp)
namespace n00274b40 {
extern u32 D_0035f140 asm("D_0035f140");
extern u8 D_0035f222 asm("D_0035f222");
void Tz__CmComm__DataLoadWait(s32, s32) asm("Tz__CmComm__DataLoadWait");
void func_00276410(void) asm("func_00276410");
void func_00293bd0(s32, s32, s32) asm("func_00293bd0");
void func_00274db8(void) asm("func_00274db8");
void Tz__JmSynthe__ReadMixData(void) asm("Tz__JmSynthe__ReadMixData");
void func_002925c0(void) asm("func_002925c0");
void func_00102448(s32, s32) asm("func_00102448");
void func_00170dd0(s32) asm("func_00170dd0");
void func_00274e08(void) asm("func_00274e08");
void Tz__JmInfo__SetLeadData(void) asm("Tz__JmInfo__SetLeadData");
void func_00294020(s32) asm("func_00294020");
void Tz__JmSynthe__GetMixData(void) asm("Tz__JmSynthe__GetMixData");
s32 func_00292630(void) asm("func_00292630");
s32 func_00287bc0(void) asm("func_00287bc0");
void Tz__Jiminy__LoadData(s32) asm("Tz__Jiminy__LoadData");
// state_dispatch_0_1_2
void Tz__JmPuzzle__SetPiece(void) asm("Tz__JmPuzzle__SetPiece");
void func_002a9d88(void) asm("func_002a9d88");
void Tz__JmComplete__CheckAll(void) asm("Tz__JmComplete__CheckAll");
void Tz__Jiminy__Setup(void) asm("Tz__Jiminy__Setup");
void func_00292870(void) asm("func_00292870");
void func_00242618(s32, s32) asm("func_00242618");
void YI__IMAGE_CACHE__Clear(void) asm("YI__IMAGE_CACHE__Clear");
// clear_64_entries_24
s32 func_00275180(void) asm("func_00275180");
void func_00275438(void) asm("func_00275438");
void func_00274e50(void) asm("func_00274e50");
/*TARGET 00274b40*/
void func_00274b40(s32 a0) asm("func_00274b40");
void func_00274b40(s32 a0) {
    Tz__CmComm__DataLoadWait(3, a0);
    func_00276410();
    func_00293bd0(0, 0, 0);
    func_00274db8();
    Tz__JmSynthe__ReadMixData();
    func_002925c0();
    func_00102448(a0, 1);
    func_00170dd0(a0);
    func_00274e08();
    if (!(D_0035f140 & 4)) {
        Tz__JmInfo__SetLeadData();
        func_00294020(0);
    }
    Tz__JmSynthe__GetMixData();
    while (func_00292630()) func_00102448(a0, 0);
    Tz__Jiminy__LoadData(func_00287bc0());  // state_dispatch_0_1_2
    func_002925c0();
    func_00102448(a0, 0);
    func_00170dd0(a0);
    for (;;) { if (!D_0035f222) break; func_00102448(a0, 0); }
    Tz__JmPuzzle__SetPiece();
    func_002a9d88();
    Tz__JmComplete__CheckAll();
    Tz__Jiminy__Setup();
    func_00292870();
    func_00242618(11, 1);
    for (;;) {
        YI__IMAGE_CACHE__Clear();  // clear_64_entries_24
        if (func_00275180()) break;
        func_00275438();
        func_00102448(a0, 0);
    }
    func_00274e50();
    while (func_00292630()) func_00102448(a0, 0);
    return;
}
}  // namespace n00274b40

// 00274cf0 (was src/anon/batch_w86.cpp)
namespace n00274cf0 {
extern s8* D_0035f1fc asm("D_0035f1fc");
void func_00293bd0(s32, s32, s32) asm("func_00293bd0");
s32 Tz__JmWorldSel__GetId2Info(s32) asm("Tz__JmWorldSel__GetId2Info");
s32 func_002941d8(s32) asm("func_002941d8");
s32 func_00296f90(void) asm("func_00296f90");
// get_global_36f598
s32 func_00296f80(void) asm("func_00296f80");
/*TARGET 00274cf0*/
// get_global_36f594
void Tz__Jiminy__LoadData(s32 m) asm("Tz__Jiminy__LoadData");
// get_global_36f594
void Tz__Jiminy__LoadData(s32 m)
{
    switch (m) {
    case 0:
        func_00293bd0(1, 0, 0);
        break;
    case 1:
        func_00293bd0(2, func_00296f80(), 0);
        break;
    case 2:
        if (*D_0035f1fc == 1) {
            if (func_002941d8(Tz__JmWorldSel__GetId2Info(1))) {
                func_00293bd0(2, func_00296f90(), 0);
                break;
            }
        }
        func_00293bd0(2, Tz__JmWorldSel__GetId2Info(*D_0035f1fc) + 1, 0);
        break;
    case 13:
        func_00293bd0(2, Tz__JmWorldSel__GetId2Info(15) + 1, 0);
        break;
    }
}
}  // namespace n00274cf0

// 00274db8 (was src/anon/tiny_auto80_queue.cpp)
namespace n00274db8 {
void func_00192260(u32, u32) asm("_Z13func_00192260jj");
extern u32 D_0035f140 asm("D_0035f140");
/*TARGET 00274db8*/
void func_00274db8() asm("_Z13func_00274db8v");
void func_00274db8() {
    if ((((*(u8*)(u32)&D_0035f140) ^ 1u) & 1u & 0xffu) != 0u) {
        func_00192260(101u, 5100u);
        *(u32*)(u32)&D_0035f140 |= 1u;
    }
}
}  // namespace n00274db8

// 00274e08 (was src/anon/tiny_auto80_queue.cpp)
namespace n00274e08 {
void func_00192290(u32, u32) asm("_Z13func_00192290jj");
extern u32 D_0035f140 asm("D_0035f140");
/*TARGET 00274e08*/
void func_00274e08() asm("_Z13func_00274e08v");
void func_00274e08() {
    if ((*(u32*)(u32)&D_0035f140 & 2u) != 0u) {
        return;
    }
    func_00192290(101u, 0u);
    *(u32*)(u32)&D_0035f140 |= 2u;
}
}  // namespace n00274e08

// 00274e50 (was src/anon/tiny_auto80_queue.cpp)
namespace n00274e50 {
extern u32 D_0035f140 asm("D_0035f140");
u32 func_001922c8(...) asm("func_001922c8");
/*TARGET 00274e50*/
void func_00274e50() asm("_Z13func_00274e50v");
void func_00274e50() {
    u32 t6 = *(u32*)(u32)&D_0035f140;
    if ((t6 & 4u) != 0u) {
        return;
    }
    s32 t7 = -4;
    if ((t6 & 2u) != 0u) {
        func_001922c8(0u);
        t6 = *(u32*)(u32)&D_0035f140;
        t7 = -4;
    }
    *(u32*)(u32)&D_0035f140 = (u32)(t6 & (u32)t7);
}
}  // namespace n00274e50

// 00274ea0 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00274ea0
extern u32 D_0035f140 asm("D_0035f140");
void func_00293bd0(u32, u32, u32) asm("func_00293bd0");
u32 func_00274db8() asm("func_00274db8");
/*TARGET 00274ea0*/
u32 Tz_Jiminy_WMRead() asm("_ZN2Tz6Jiminy6WMReadEv");
u32 Tz_Jiminy_WMRead() {
    D_0035f140 = 0;
    func_00293bd0(0, 0, 1);
    u32 r2 = func_00274db8();
    D_0035f140 |= 4u;
    return r2;
}
}  // Tz

// 00274ee8 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00274ee8
extern u32 D_0035f140 asm("D_0035f140");
void func_00274e08() asm("func_00274e08");
void Tz__JmInfo__Init(u32) asm("Tz__JmInfo__Init");
void Tz__JmInfo__SetLeadData() asm("Tz__JmInfo__SetLeadData");
void func_00294020(u32) asm("func_00294020");
/*TARGET 00274ee8*/
void Tz_Jiminy_WMInit(ALLOCATOR* a0) asm("_ZN2Tz6Jiminy6WMInitEP9ALLOCATOR");
void Tz_Jiminy_WMInit(ALLOCATOR* a0) {
    if ((D_0035f140 & 8) == 0) {
        u32 s0 = (u32)a0;
        func_00274e08();
        Tz__JmInfo__Init(s0);
        Tz__JmInfo__SetLeadData();
        func_00294020(0);
        D_0035f140 |= 8;
    }
}
}  // Tz

// 00274f50 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00274f50
extern u8 D_00360000 asm("D_00360000");
u32 func_00274e50(...) asm("func_00274e50");
// record_set_value_refresh
extern "C" void func_00293eb0() asm("_ZN2Tz6JmInfo4ExitEv");
u32 func_00293d80(...) asm("func_00293d80");
/*TARGET 00274f50*/
u32 Tz_Jiminy_WMExit() asm("_ZN2Tz6Jiminy6WMExitEv");
u32 Tz_Jiminy_WMExit() {
    *(u32*)((u8*)&D_00360000 - 3776) &= (u32)-13;
    ((u32(*)())func_00274e50)();
    func_00293eb0();
    u32 v0 = ((u32(*)(u32))func_00293d80)(0);
    *(u32*)((u8*)&D_00360000 - 3776) = 0;
    return v0;
}
}  // Tz

// 00274f98 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00274f98
extern u32 D_0035f138 asm("D_0035f138");
/*TARGET 00274f98*/
void Tz_Jiminy_InitWorldNo(s32 value) asm("_ZN2Tz6Jiminy11InitWorldNoEi");
void Tz_Jiminy_InitWorldNo(s32 value) {
    D_0035f138 = (u32)value;
}
}  // Tz

// 00274fa8 (was src/anon/batch_w111.cpp)
namespace n00274fa8 {
struct Pt27 { s16 x; s16 pad; s16 y; };
struct Heap27 { void** vt; };
typedef void* (*AllocFn27)(Heap27*, s32, void*);
struct Sys27 { u8 pad[20]; Heap27* heap; };
struct Item27 { void* vt; u8 pad[8]; s32 f12; u8 pad2[8]; u8 sub[384]; };
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8 D_00347e60[] asm("D_00347e60");
extern union { u8* p; s16 h; } D_0035f210 asm("D_0035f210");
extern Item27* D_0035f204 asm("D_0035f204");
extern void* D_0035f148 asm("D_0035f148");
extern void* D_0035f14c asm("D_0035f14c");
extern u8 D_00373d78[] asm("D_00373d78");
extern u8 D_00373d80[] asm("D_00373d80");
extern Sys27* D_00347f80 asm("D_00347f80");
Pt27* func_00276fa8(void) asm("func_00276fa8");
// global_ptr_by_flag2
void* func_0023ee30(s32) asm("func_0023ee30");
void func_0031a838(void*) asm("func_0031a838");
void YI__IMAGE_FREEZE__IMAGE_FREEZE(void*) asm("YI__IMAGE_FREEZE__IMAGE_FREEZE");
// obj_ctor_36eac8
void YI__LAYOUT__LAYOUT(void*) asm("YI__LAYOUT__LAYOUT");
// obj_ctor_36eae8
void Tz__MenuUtil__CreateLay(void*, s32, s32, s32, s32, s32, s32, s32, s32) asm("Tz__MenuUtil__CreateLay");
void Tz__Layout__SetImageCache(void*) asm("Tz__Layout__SetImageCache");
void Tz__SelHist__Init(void*, void*, void*, void*, void*) asm("Tz__SelHist__Init");
void func_00276598(void) asm("func_00276598");
void func_00239700(void*) asm("func_00239700");
void Tz__Jiminy__SetParentSeqNum(s32, s32) asm("Tz__Jiminy__SetParentSeqNum");
void func_00275af8(void) asm("func_00275af8");
s32 func_00287bc0(void) asm("func_00287bc0");
void Tz__JmWorldSel__Setup(void) asm("Tz__JmWorldSel__Setup");
void func_00296588(void) asm("func_00296588");
void Tz__JmReport__Setup(void) asm("Tz__JmReport__Setup");
void func_00276588(s32) asm("func_00276588");
void func_0028fb28(s32, s32) asm("func_0028fb28");
void Tz__JmMiniGame__Setup(void) asm("Tz__JmMiniGame__Setup");
/*TARGET 00274fa8*/
// Creates this screen's main object and item, then enters the mode-specific setup.
void Tz__Jiminy__Setup(void) asm("Tz__Jiminy__Setup");
// Creates this screen's main object and item, then enters the mode-specific setup.
void Tz__Jiminy__Setup(void)
{
    Pt27* p = func_00276fa8();  // global_ptr_by_flag2
    u8* o = (u8*)func_0023ee30(160);
    *(u32*)o = (u32)D_00347f98;
    func_0031a838(o + 12);
    *(u32*)o = (u32)D_0035eb98;
    YI__IMAGE_FREEZE__IMAGE_FREEZE(o + 24);  // obj_ctor_36eac8
    YI__LAYOUT__LAYOUT(o + 48);  // obj_ctor_36eae8
    D_0035f210.p = o;
    Tz__MenuUtil__CreateLay(o, 30039, 0, 0, p->x, p->y, 0, 0, 0);
    Tz__Layout__SetImageCache(D_0035f210.p);
    Tz__SelHist__Init(D_0035f148, D_0035f14c, D_0035f210.p, D_00373d78, D_00373d80);
    func_00276598();
    Heap27* h = D_00347f80->heap;
    Item27* it = (Item27*)((AllocFn27)h->vt[0])(h, 408, 0);
    it->f12 = 0;
    it->vt = D_00347e60;
    func_00239700(it->sub);
    D_0035f204 = it;
    Tz__Jiminy__SetParentSeqNum(0, 0);
    func_00275af8();
    switch (func_00287bc0()) {
    case 0: Tz__JmWorldSel__Setup(); break;
    case 1: func_00296588(); break;
    case 2: Tz__JmReport__Setup(); break;
    case 11:
        func_00276588(1);
        func_0028fb28(0, 12881);
        Tz__JmMiniGame__Setup();
        break;
    }
}
}  // namespace n00274fa8

// 00275180 (was src/anon/batch_w1905_g.cpp)
namespace n00275180 {
void func_00294b80(void) asm("func_00294b80");
void Tz__JmReport__ControlRoxas(void) asm("Tz__JmReport__ControlRoxas");
void func_00296168(void) asm("func_00296168");
void func_00297630(void) asm("func_00297630");
void Tz__JmAlbum__Control(void) asm("Tz__JmAlbum__Control");
void Tz__JmAlbum__PhotoControl(void) asm("Tz__JmAlbum__PhotoControl");
void Tz__JmTreasure__CtrlPieceInfo(void) asm("Tz__JmTreasure__CtrlPieceInfo");
void func_00299e70(void) asm("func_00299e70");
void func_0029b378(void) asm("func_0029b378");
void Tz__JmDic__CtrlCharaSel(void) asm("Tz__JmDic__CtrlCharaSel");
void func_0029c098(void) asm("func_0029c098");
void func_0029c5c8(void) asm("func_0029c5c8");
void Tz__JmAnsem__CtrlTop(void) asm("Tz__JmAnsem__CtrlTop");
void Tz__JmAnsem__CtrlInfo(void) asm("Tz__JmAnsem__CtrlInfo");
void func_002af010(void) asm("func_002af010");
void Tz__JmTreasure__Control(void) asm("Tz__JmTreasure__Control");
void Tz__JmQuest__Control(void) asm("Tz__JmQuest__Control");
void Tz__JmMiniGame__Control(void) asm("Tz__JmMiniGame__Control");
void Tz__JmBattle__CtrlTop(void) asm("Tz__JmBattle__CtrlTop");
void func_002a5a90(void) asm("func_002a5a90");
void Tz__JmSynthe__Control(void) asm("Tz__JmSynthe__Control");
void func_002a0cb8(void) asm("func_002a0cb8");
u8* func_00276fa8(void) asm("func_00276fa8");
void Tz__MenuBase__SaveMode(void) asm("Tz__MenuBase__SaveMode");
void func_00276438(void) asm("func_00276438");
s32 func_00287db0(void) asm("func_00287db0");
u32 func_00287dc0(void) asm("func_00287dc0");
s32 func_00139d78(u32) asm("func_00139d78");
void Tz__Jiminy__LeaveAll(void) asm("Tz__Jiminy__LeaveAll");
s32 func_002887c8(void) asm("func_002887c8");
void func_002766c0(void) asm("func_002766c0");
void func_00288750(void (*)(void)) asm("func_00288750");
void func_001039f8(void) asm("func_001039f8");
s32 func_0023f0c0(u32) asm("func_0023f0c0");
s32 Tz__MenuBase__isPressAnyKey(void) asm("Tz__MenuBase__isPressAnyKey");
void func_0023f070(u32, s32, s32) asm("func_0023f070");
u32 func_00287bc0(void) asm("func_00287bc0");
extern u32 D_0035f210 asm("D_0035f210");
extern u32 D_0035f140 asm("D_0035f140");
extern u8 D_0035f222 asm("D_0035f222");
/*TARGET 00275180*/
s32 func_00275180(void) asm("func_00275180");
s32 func_00275180(void) {
    u8* p = func_00276fa8();
    Tz__MenuBase__SaveMode();
    func_00276438();
    if (func_00287db0()) {
        if (func_00139d78(func_00287dc0())) return 0;
        if (func_00139d78(D_0035f210)) goto out;
        Tz__Jiminy__LeaveAll();
        if (D_0035f140 & 4) {
            if (D_0035f222) return 0;
            if (func_002887c8()) {
                D_0035f222 = 1;
                func_00288750(func_002766c0);
            }
        }
        if (D_0035f222) goto out;
        func_001039f8();
        return 1;
    }
    goto other;
out:
    return 0;
other:
    if (func_00139d78(D_0035f210) && func_0023f0c0(D_0035f210) != *(s16*)(p + 4)) {
        if (!Tz__MenuBase__isPressAnyKey()) goto out;
        func_0023f070(D_0035f210, *(s16*)(p + 4), -1);
    }
    switch (func_00287bc0()) {
    case 0:
        func_00294b80();
        return 0;
    case 1:
        Tz__JmReport__ControlRoxas();
        return 0;
    case 2:
        func_00296168();
        return 0;
    case 3:
        func_00297630();
        return 0;
    case 4:
        Tz__JmAlbum__Control();
        return 0;
    case 5:
        Tz__JmAlbum__PhotoControl();
        return 0;
    case 8:
        Tz__JmTreasure__CtrlPieceInfo();
        return 0;
    case 13:
        func_00299e70();
        return 0;
    case 14:
        func_0029b378();
        return 0;
    case 15:
    case 18:
    case 21:
        Tz__JmDic__CtrlCharaSel();
        return 0;
    case 16:
    case 19:
    case 22:
        func_0029c098();
        return 0;
    case 17:
    case 20:
    case 23:
        func_0029c5c8();
        return 0;
    case 24:
        Tz__JmAnsem__CtrlTop();
        return 0;
    case 25:
        Tz__JmAnsem__CtrlInfo();
        return 0;
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
        func_002af010();
        return 0;
    case 7:
    case 9:
    case 26:
    case 34:
        Tz__JmTreasure__Control();
        return 0;
    case 10:
    case 35:
        Tz__JmQuest__Control();
        return 0;
    case 11:
    case 36:
        Tz__JmMiniGame__Control();
        return 0;
    case 37:
        Tz__JmBattle__CtrlTop();
        return 0;
    case 38:
        func_002a5a90();
        return 0;
    case 39:
        Tz__JmSynthe__Control();
        return 0;
    case 6:
    case 12:
    case 40:
        func_002a0cb8();
        return 0;
    }
    goto out;
}
}  // namespace n00275180

// 00275438 (was src/anon/batch_w8017_g.cpp)
namespace n00275438 {
u32 func_00287bc0(void) asm("func_00287bc0");
s16* func_00276fa8(void) asm("func_00276fa8");
s32 func_00287db0(void) asm("func_00287db0");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0023f0c0(void*) asm("func_0023f0c0");
void func_0023f070(void*, s32, s32) asm("func_0023f070");
s32 func_0028acc8(void*) asm("func_0028acc8");
s32 func_0028acb8(void*) asm("func_0028acb8");
u8* func_002891b8(void*, s32) asm("func_002891b8");
void func_0028aa40(void*) asm("func_0028aa40");
void func_0028f7a0(void) asm("func_0028f7a0");
void func_0028d5d0(u32) asm("func_0028d5d0");
void func_002748a0(void) asm("func_002748a0");
void func_00276e28(void) asm("func_00276e28");
void func_0028ce38(void) asm("func_0028ce38");
void func_00288018(void) asm("func_00288018");
void func_00276438(void) asm("func_00276438");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_0028d008(s32) asm("func_0028d008");
s32 func_002891d0(void*) asm("func_002891d0");
void func_00275980(s32, s32) asm("func_00275980");
void func_002759e8(s32) asm("func_002759e8");
void func_0028d620(u32) asm("func_0028d620");
void func_0028cdb8(s32) asm("func_0028cdb8");
s32 func_0028d6e8(u32) asm("func_0028d6e8");
void OvlShop__ItemShop__DrawSelector(void*, u32, s32) asm("OvlShop__ItemShop__DrawSelector");
struct VObj { void (**vt)(VObj*); };
extern void* D_0035f200 asm("D_0035f200");
extern VObj* D_0035f208 asm("D_0035f208");
extern void* D_0035f210 asm("D_0035f210");
extern u32 D_0035f218 asm("D_0035f218");
extern u8 D_0035f220 asm("D_0035f220");
extern u8 D_0035f221 asm("D_0035f221");
static inline bool busy_00275438(u8* v) { return *(s32*)(v + 400) || *(s32*)(v + 396); }
static inline void tailL() { if (func_0028d6e8(D_0035f218)) func_0028d5d0(D_0035f218); }
/*TARGET 00275438*/
void func_00275438(void) asm("func_00275438");
void func_00275438(void) {
    u32 mode = func_00287bc0();
    s16* q = func_00276fa8();
    void* p;
    if (func_00287db0()) {
        if (func_00139d78(D_0035f210)) {
            if (func_0023f0c0(D_0035f210) != q[1]) func_0023f070(D_0035f210, q[1], -1);
        }
        if (func_0028acc8(D_0035f200) && !func_0028acb8(D_0035f200)) {
            u8* v = func_002891b8(D_0035f200, 0);
            if (!busy_00275438(v)) func_0028aa40(D_0035f200);
        }
        if (func_00139d78(D_0035f208)) D_0035f208->vt[5](D_0035f208);
        func_0028f7a0();
        func_0028d5d0(D_0035f218);
        func_002748a0();
        func_00276e28();
        func_0028ce38();
    }
    func_00288018();
    func_00276438();
    if (func_00287db0()) return;
    p = D_0035f200;
    if (mode != 7 && mode != 9 && mode != 26 && mode != 34) {
        if (!D_0035f220) {
            if (func_0028acc8(p) && func_00287cd0() == 1) {
                if (!func_0028d008(0)) {
                    func_00275980(0, func_002891d0(p));
                    if (!D_0035f221) func_002759e8(func_002891d0(p));
                    else func_0028d620(D_0035f218);
                }
            } else if (func_00287cd0() == 2) {
                if (func_0028d008(0)) { func_0028cdb8(0); tailL(); } else tailL();
            }
        } else {
            if (func_0028d008(0)) func_0028cdb8(0);
            tailL();
        }
    }
    switch (mode) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6:
    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
    case 20: case 21: case 22: case 23: case 24: case 25: case 27: case 28: case 29:
    case 35: case 36: case 37: case 38: case 40:
        OvlShop__ItemShop__DrawSelector(p, mode, 0);
        break;
    }
}
}  // namespace n00275438

// 002756f8 (was src/anon/batch_w1608.cpp)
namespace n002756f8 {
s32 func_00287cd0(s32) asm("func_00287cd0");
s32 func_002891d0(s32) asm("func_002891d0");
void func_002891e8(s32) asm("func_002891e8");
s32 func_00289310(s32) asm("func_00289310");
s32 func_00289358(s32) asm("func_00289358");
void Tz__MenuCursor__SetParent(s32, s32) asm("Tz__MenuCursor__SetParent");
s32 func_0028d008(s32) asm("func_0028d008");
void func_0028d660(s32, s32) asm("func_0028d660");
s32 func_0028d6e8(s32) asm("func_0028d6e8");
void func_00295668(s32, u32, s32) asm("func_00295668");
void func_00296ea8(s32, u32, s32) asm("func_00296ea8");
void func_00297878(s32, u32, s32) asm("func_00297878");
void func_00298e20(s32, u32, s32) asm("func_00298e20");
void func_0029a718(s32, u32, s32) asm("func_0029a718");
void func_0029cd70(s32, u32, s32) asm("func_0029cd70");
void func_002a0168(s32, u32, s32) asm("func_002a0168");
void func_002a6308(s32, u32, s32) asm("func_002a6308");
void func_002a82f8(s32, u32, s32) asm("func_002a82f8");
void func_002a9570(s32, u32, s32) asm("func_002a9570");
extern s32 D_0035f218 asm("D_0035f218");
/*TARGET 002756f8*/
void OvlShop__ItemShop__DrawSelector(s32 a0, u32 a1, s32 a2) asm("OvlShop__ItemShop__DrawSelector");
void OvlShop__ItemShop__DrawSelector(s32 a0, u32 a1, s32 a2) {
    if (func_00287cd0(a0) != 1) return;
    if (func_00289310(a0)) {
        func_002891e8(a0);
        if (func_0028d008(a2)) Tz__MenuCursor__SetParent(a2, func_002891d0(a0));
        if (func_0028d6e8(D_0035f218)) func_0028d660(D_0035f218, func_002891d0(a0));
    }
    if (func_00289310(a0) || func_00289358(a0)) {
        switch (a1) {
        case 0: func_00295668(a0, a1, a2); return;
        case 1: case 2: func_00296ea8(a0, a1, a2); return;
        case 3: func_00297878(a0, a1, a2); return;
        case 4: case 5: func_00298e20(a0, a1, a2); return;
        case 13: func_0029a718(a0, a1, a2); return;
        case 14: case 15: case 16: case 17: case 18: case 19: case 20: case 21: case 22: case 23:
            func_0029cd70(a0, a1, a2); return;
        case 24: case 25: func_002a0168(a0, a1, a2); return;
        default: return;
        case 10: case 35: func_002a9570(a0, a1, a2); return;
        case 11: case 36: func_002a82f8(a0, a1, a2); return;
        case 37: case 38: func_002a6308(a0, a1, a2); return;
        }
    }
}
}  // namespace n002756f8

// 00275980 (was src/anon/auto80_199_queue.cpp)
namespace n00275980 {
/*TARGET 00275980*/
void func_00275980(u32 a0, u32 a1) asm("_Z13func_00275980jj");
void func_00275980(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    if (func_0028d008(s0, s1) == 0) {
        Tz__MenuCursor__Create(s0, D_0035f14c, D_0035f148, D_0035f210, 33, 33);
    }
    Tz__MenuCursor__SetParent(s0, s1);  // record408_set_and_refresh
}
}  // namespace n00275980

// 002759e8 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 002759e8
class Sprite;
extern u32 D_0035f218 asm("D_0035f218");
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f210 asm("D_0035f210");
extern u32 D_00373d80 asm("D_00373d80");
u32 func_0028d6e8(...) asm("func_0028d6e8");
void Tz__LightCur__Create(...) asm("Tz__LightCur__Create");
void func_0028d660(...) asm("func_0028d660");
/*TARGET 002759e8*/
void Tz_Jiminy_CreateLightCursor(::dk::Sprite* a0) asm("_ZN2Tz6Jiminy17CreateLightCursorEPN2dk6SpriteE");
void Tz_Jiminy_CreateLightCursor(::dk::Sprite* a0) {
    u32 s0 = (u32)a0;
    u32 v0 = func_0028d6e8(D_0035f218);
    if (v0 == 0) {
        Tz__LightCur__Create(D_0035f218, 30065, D_0035f14c, D_0035f148, D_0035f210, (u32)&D_00373d80, 0);
    } else {
        u32 p = D_0035f218;
        if (*(u32*)(p + 396) == s0) {
            return;
        }
        func_0028d660(p, s0);  // record_set_value_refresh
        return;
    }
    func_0028d660(D_0035f218, s0);  // record_set_value_refresh
}
}  // Tz

// 00275a80 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00275a80
extern u32 D_0035f20c asm("D_0035f20c");
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f210 asm("D_0035f210");
u32 func_00139d78(...) asm("func_00139d78");
void Tz__Jiminy__SetupMainFrameLR() asm("Tz__Jiminy__SetupMainFrameLR");
void func_0028d980(...) asm("func_0028d980");
/*TARGET 00275a80*/
void Tz_Jiminy_SetupMainFrame() asm("_ZN2Tz6Jiminy14SetupMainFrameEv");
void Tz_Jiminy_SetupMainFrame() {
    if (func_00139d78(D_0035f20c + 872) == 0) {
        func_0028d980(D_0035f20c + 872, 30040, D_0035f14c, D_0035f148, D_0035f210, 53, 54, -1, 0);
        *(u32*)(D_0035f20c + 1304) = 2;
    }
    Tz__Jiminy__SetupMainFrameLR();
}
}  // Tz

// 00275af8 (was src/anon/auto80_199_queue.cpp)
namespace n00275af8 {
/*TARGET 00275af8*/
void func_00275af8() asm("_Z13func_00275af8v");
void func_00275af8() {
    if (func_00139d78(D_0035f20c + 1308) == 0) {
        func_0028d980(D_0035f20c + 1308, 30040, D_0035f14c, D_0035f148, D_0035f210, 44, 45, -1, 0);
    }
}
}  // namespace n00275af8

// 00275b60 (was src/anon/batch_w92.cpp)
namespace n00275b60 {
struct Sub275 { u8 pad[388]; s32 anim; s32 f392; u8 pad2[40]; };
struct Obj275 { Sub275 sub[4]; };
s32 func_00139d78(Sub275*) asm("func_00139d78");
void func_00138c10(void*, s32) asm("func_00138c10");
extern Obj275* D_0035f20c asm("D_0035f20c");
static inline void reset275(s32 i, s32 id) {
    if (func_00139d78(&D_0035f20c->sub[i])) {
        Sub275* s = &D_0035f20c->sub[i];
        if (s->anim != id) {
            func_00138c10(s, id);
            D_0035f20c->sub[i].f392 = -1;
        }
    }
}
/*TARGET 00275b60*/
// puts the four menu cursors back on their idle animations
void func_00275b60(void) asm("func_00275b60");
// puts the four menu cursors back on their idle animations
void func_00275b60(void) {
    reset275(2, 54);
    reset275(3, 45);
    reset275(0, 48);
    reset275(1, 51);
}
}  // namespace n00275b60

// 00275c78 (was src/anon/batch_w23.cpp)
namespace n00275c78 {
extern u8* D_0035f20c asm("D_0035f20c");
void func_0028dac8(void*, s32) asm("func_0028dac8");
void func_00275dd0(void) asm("func_00275dd0");
/*TARGET 00275c78*/
void func_00275c78(void) asm("func_00275c78");
void func_00275c78(void) {
    func_0028dac8(D_0035f20c + 872, 55);
    func_0028dac8(D_0035f20c + 1308, 46);
    func_00275dd0();
}
}  // namespace n00275c78

// 00275cb8 (was src/anon/auto80_199_queue.cpp)
namespace n00275cb8 {
/*TARGET 00275cb8*/
void func_00275cb8() asm("_Z13func_00275cb8v");
void func_00275cb8() {
    if (func_00139d78(D_0035f20c + 872) != 0) {
        func_00139510(D_0035f20c + 872);
    }

    if (func_00139d78(D_0035f20c + 1308) != 0) {
        func_00139510(D_0035f20c + 1308);
    }

    func_00275e08();
}
}  // namespace n00275cb8

// 00275d10 (was src/anon/batch_w76.cpp)
namespace n00275d10 {
s32 func_00139d78(void*) asm("func_00139d78");
union PtrI { u8* p; s32 i; };
extern PtrI D_0035f20c asm("D_0035f20c");
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f210 asm("D_0035f210");
void func_0028d980(u8*, s32, u32, u32, u32, s32, s32, s32, s32) asm("func_0028d980");
/*TARGET 00275d10*/
void Tz__Jiminy__SetupMainFrameLR(void) asm("Tz__Jiminy__SetupMainFrameLR");
void Tz__Jiminy__SetupMainFrameLR(void)
{
    if (!func_00139d78(D_0035f20c.p)) {
        func_0028d980(D_0035f20c.p, 30040, D_0035f14c, D_0035f148, D_0035f210, 47, 48, -1, 0);
        *(s32*)(D_0035f20c.p + 432) = 2;
    }
    if (!func_00139d78(D_0035f20c.p + 436)) {
        func_0028d980(D_0035f20c.p + 436, 30040, D_0035f14c, D_0035f148, D_0035f210, 50, 51, -1, 0);
        *(s32*)(D_0035f20c.p + 868) = 2;
    }
}
}  // namespace n00275d10

// 00275dd0 (was src/anon/tiny_auto80_solver.cpp)
namespace n00275dd0 {
u32 func_00275dd0(void) asm("_Z13func_00275dd0v");
u32 func_0028dac8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0028dac8jjjjjjjj");
extern u8 D_00360000 asm("D_00360000");
/*TARGET 00275dd0*/
u32 func_00275dd0(void) asm("_Z13func_00275dd0v");
u32 func_00275dd0(void) {
    ((u32(*)(u32, u32))func_0028dac8)(*(u32*)((u8*)&D_00360000 - 3572), 49);
    return ((u32(*)(u32, u32))func_0028dac8)(*(u32*)((u8*)&D_00360000 - 3572) + 436, 52);
}
}  // namespace n00275dd0

// 00275e08 (was src/anon/batch_w45.cpp)
namespace n00275e08 {
s32 func_00139d78(u8*) asm("func_00139d78");
void func_00139510(u8*) asm("func_00139510");
extern u8* D_0035f20c asm("D_0035f20c");
/*TARGET 00275e08*/
void func_00275e08(void) asm("func_00275e08");
void func_00275e08(void) {
    if (func_00139d78(D_0035f20c)) func_00139510(D_0035f20c);
    if (func_00139d78(D_0035f20c + 436)) func_00139510(D_0035f20c + 436);
}
}  // namespace n00275e08

// 00275e68 (was src/anon/batch_w47.cpp)
namespace n00275e68 {
s32 func_00139d78(void*) asm("func_00139d78");
// 0x00259350: definition moved into src/anon/unit_002588e8.cpp

extern u8* D_0035f20c asm("D_0035f20c");
u32 func_00192048(s32) asm("func_00192048");
/*TARGET 00275e68*/
void func_00275e68(s32 a) asm("func_00275e68");
void func_00275e68(s32 a) {
    func_00139d78(D_0035f20c + 872);
    if (a < 0) *(u32*)(D_0035f20c + 1280) = 0;
    else { u8* o = D_0035f20c + 872; *(u32*)(o + 408) = func_00192048(a); }
}
}  // namespace n00275e68

// 00275ec8 (was src/anon/batch_w11.cpp)
namespace n00275ec8 {
extern u8* D_0035f20c asm("D_0035f20c");
void func_00139d78(void*) asm("func_00139d78");
/*TARGET 00275ec8*/
void func_00275ec8(u32 v) asm("func_00275ec8");
void func_00275ec8(u32 v) {
    func_00139d78(D_0035f20c + 872);
    *(u32*)(D_0035f20c + 1280) = v;
}
}  // namespace n00275ec8

// 00275f08 (was src/anon/batch_w48.cpp)
namespace n00275f08 {
// vec_copy_at416_if_diff
s32 func_00139d78(void*) asm("func_00139d78");
// 0x002621a0: definition moved into src/anon/unit_0025f6b8.cpp

extern u8* D_0035f20c asm("D_0035f20c");
s32 func_00192048(s32) asm("func_00192048");
struct S275 { u8 pad[408]; s32 v; };
static inline S275* sub275() { return (S275*)(D_0035f20c + 1308); }
/*TARGET 00275f08*/
void func_00275f08(s32 i) asm("func_00275f08");
void func_00275f08(s32 i) {
    func_00139d78(sub275());
    if (i < 0) {
        *(u32*)(D_0035f20c + 1716) = 0;
        return;
    }
    sub275()->v = func_00192048(i);
}
}  // namespace n00275f08

// 00275f68 (was src/anon/batch_w258.cpp)
namespace n00275f68 {
extern u8* D_0035f20c asm("D_0035f20c");
void u_call4_00139d78(u8*) asm("_Z16u_call4_00139d78jjjj");
s32 func_00259510(s32) asm("func_00259510");
u8* u_tail4_00192048(s32) asm("_Z16u_tail4_00192048jjjj");
void CmComm_FontIcon(s32, char*, bool) asm("_ZN2Tz6CmComm8FontIconEiPcb");
s32 CmComm_GetIconMsgSize(void) asm("_ZN2Tz6CmComm14GetIconMsgSizeEv");
u8* CmComm_CopyMessage(char*, u8*) asm("_ZN2Tz6CmComm11CopyMessageEPcPKN2YS7MESSAGEE");
s32 MESSAGE_get_size(u8*) asm("_ZNK2YS7MESSAGE8get_sizeEv");
/*TARGET 00275f68*/
void Tz__Jiminy__SetMainFrameLRMess(s32 a, s32 b) asm("Tz__Jiminy__SetMainFrameLRMess");
void Tz__Jiminy__SetMainFrameLRMess(s32 a, s32 b) {
    char* s;
    s32 m;
    u_call4_00139d78(D_0035f20c + 1308);
    if (a < 0) {
        *(u32*)(D_0035f20c + 408) = 0;
    } else {
        m = func_00259510(1024);
        s = (char*)(D_0035f20c + 1744);
        CmComm_FontIcon(m, s, 1);
        s += CmComm_GetIconMsgSize();
        CmComm_CopyMessage(s, u_tail4_00192048(a));
        *(u8**)(D_0035f20c + 408) = D_0035f20c + 1744;
    }
    if (b < 0) {
        *(u32*)(D_0035f20c + 844) = 0;
    } else {
        m = func_00259510(2048);
        s = (char*)(D_0035f20c + 1808);
        s += MESSAGE_get_size(CmComm_CopyMessage(s, u_tail4_00192048(b)));
        CmComm_FontIcon(m, s, 1);
        *(u8**)(D_0035f20c + 844) = D_0035f20c + 1808;
    }
}
}  // namespace n00275f68

// 00276088 (was src/anon/batch_w3827_nosched.c)
namespace n00276088 {
extern u16 D_00373d70[3] asm("D_00373d70");
extern u8* D_0035f1fc asm("D_0035f1fc");
/*TARGET 00276088*/
/* Picks the previous/next entries of a 3-slot ring (index from mode a) out of the u16 table D_00373d70. */
void func_00276088(s32 a, s32* l, s32* r) asm("func_00276088");
/* Picks the previous/next entries of a 3-slot ring (index from mode a) out of the u16 table D_00373d70. */
void func_00276088(s32 a, s32* l, s32* r) {
    s32 next, prev, c;
    u16* T;
    s32 i = 0;
    if (a < 3) {
        if (a > 0) goto one;
    } else if (a == 13) goto two_;
    goto done;
one:
    i = 1;
    goto done;
two_:
    i = 2;
done:;
    if (i == 0) prev = 2; else prev = i - 1;
    T = D_00373d70;
    c = i < 2;
    {
        s32 t = i + 1;
        s32 po = prev * 2;
        /* no code: keeps t and c live at the shift so prev*2 gets t6 (local-alloc order) */
        asm("" : "+r"(po) : "r"(t), "r"(c));
        next = c ? t : 0;
        {
            u16* A = (u16*)((u8*)T + po);
            u16* C = &T[next];
            *l = *A;
            *r = *C;
        }
    }
    if (*D_0035f1fc >= 15) {
        s32 k;
        if (i != 2) k = 2; else k = 0;
        if (prev == 1) *l = T[k];
        if (next == 1) *r = T[k];
    }
}
}  // namespace n00276088

// 00276150 (was src/anon/batch_w76.cpp)
namespace n00276150 {
void func_00276088(u32, s32*, s32*) asm("func_00276088");
extern u16 D_00373d70[3] asm("D_00373d70");
/*TARGET 00276150*/
void func_00276150(u32 a, s32* out0, s32* out1) asm("func_00276150");
void func_00276150(u32 a, s32* out0, s32* out1)
{
    s32 v0, v1;
    func_00276088(a, &v0, &v1);
    for (s32 k = 0; k < 2; k++) {
        s32 x;
        if (k == 0) x = v0; else x = v1;
        for (s32 j = 0; j < 3; j++) {
            if (D_00373d70[j] == x) { x = j; break; }
        }
        s32 r = -1;
        switch (x) {
        case 0: r = 0; break;
        case 1: r = 2; break;
        case 2: r = 13; break;
        }
        if (k == 0) *out0 = r; else *out1 = r;
    }
}
}  // namespace n00276150

// 00276220 (was src/anon/batch_w85.cpp)
namespace n00276220 {
extern s16 D_00373d60[] asm("D_00373d60");
extern s16 D_00373d68[] asm("D_00373d68");
extern u8* D_0035f204 asm("D_0035f204");
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f144 asm("D_0035f144");
s32 func_00276368(void) asm("func_00276368");
void func_00138c10(void*, s32) asm("func_00138c10");
void func_0028d8c0(void*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
/*TARGET 00276220*/
// plays the selected entry's cue (mode picks the table)
void Tz__Jiminy__SetParentSeqNum(s32 mode, s32 idx) asm("Tz__Jiminy__SetParentSeqNum");
// plays the selected entry's cue (mode picks the table)
void Tz__Jiminy__SetParentSeqNum(s32 mode, s32 idx) {
    s16* t;
    if (!mode) t = D_00373d60; else t = D_00373d68;
    if (!func_00276368())
        func_0028d8c0(D_0035f204, 30041, D_0035f14c, D_0035f148, D_0035f210, t[idx], -1, 0);
    else
        func_00138c10(D_0035f204, t[idx]);
    if (idx == 0) *(s32*)(D_0035f204 + 392) = t[2]; else *(s32*)(D_0035f204 + 392) = -1;
    D_0035f144 = mode;
}
}  // namespace n00276220

// 00276300 (was src/anon/tiny_auto80_queue.cpp)
namespace n00276300 {
void Tz__Jiminy__SetParentSeqNum(...) asm("Tz__Jiminy__SetParentSeqNum");
extern u8 D_0035f204 asm("D_0035f204");
u32 func_00276368(void) asm("_Z13func_00276368v");
/*TARGET 00276300*/
void func_00276300() asm("_Z13func_00276300v");
void func_00276300() {
    if (func_00276368() == 0u) {
        return;
    }
    u32 t6 = *(u32*)(u32)&D_0035f204;
    if (*(u32*)(t6 + 388u) == 154u) {
        return;
    }
    Tz__Jiminy__SetParentSeqNum(1u, 1u);
}
}  // namespace n00276300

// 00276348 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00276348
extern u32 D_0035f204 asm("D_0035f204");
/*TARGET 00276348*/
void* Tz_Jiminy_GetParent() asm("_ZN2Tz6Jiminy9GetParentEv");
void* Tz_Jiminy_GetParent() {
    return reinterpret_cast<void*>(D_0035f204);
}
}  // Tz

// 00276358 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00276358
extern u32 D_0035f144 asm("D_0035f144");
/*TARGET 00276358*/
s32 Tz_Jiminy_GetParentAnimMode() asm("_ZN2Tz6Jiminy17GetParentAnimModeEv");
s32 Tz_Jiminy_GetParentAnimMode() {
    return static_cast<s32>(D_0035f144);
}
}  // Tz

// 00276368 (was src/anon/tiny_auto80_queue.cpp)
namespace n00276368 {
u32 func_00139d78(...) asm("func_00139d78");
extern u8 D_0035f204 asm("D_0035f204");
/*TARGET 00276368*/
u32 func_00276368(void) asm("_Z13func_00276368v");
u32 func_00276368(void) {
    u32 r14 = *(u32*)((u32)&D_0035f204 + (s32)(0));
    u32 r2 = 0u;
    if (r14 != 0u) {
        r2 = func_00139d78(r14);
    }
    return r2;
}
}  // namespace n00276368

// 00276398 (was src/anon/tiny_jal_wrappers.cpp)
namespace n00276398 {
u32 func_00276368(u32, u32, u32, u32) asm("_Z13func_00276368jjjj");
/*TARGET 00276398*/
// 0x0026ed20: definition moved into src/anon/unit_0026c450.cpp

u32 func_00276398(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00276398jjjj");
// 0x0026ed20: definition moved into src/anon/unit_0026c450.cpp

u32 func_00276398(u32 a0, u32 a1, u32 a2, u32 a3) {  // state_is_150
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r2 = func_00276368(r4, r5, r6, r7);
    r15 = (u32)(0x0036u << 16);
    r14 = *(u32*)((u32)r15 + (s32)(-3580));
    r2 = *(u32*)((u32)r14 + (s32)(388));
    r2 = (u32)(r2 ^ 0x0098u);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
}  // namespace n00276398

// 002763c8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002763c8 {
u32 func_00139d78(...) asm("func_00139d78");
u32 func_0023d820(...) asm("func_0023d820");
u32 func_00287dc0(...) asm("func_00287dc0");
/*TARGET 002763c8*/
u32 func_002763c8(u32 a0) asm("_Z13func_002763c8j");
u32 func_002763c8(u32 a0) {
    u32 r4 = a0, r2, r16;
    r2 = ((u32(*)())func_00287dc0)();
    r16 = r2;
    r4 = r2;
    r2 = ((u32(*)(u32))func_00139d78)(r4);
    if (r2 != 0u) {
        r4 = r16;
        return ((u32(*)(u32))func_0023d820)(r4);
    }
    return r2;
}
}  // namespace n002763c8

// 00276410 (was src/anon/batch_w7.cpp)
namespace n00276410 {
u32 func_002537c8(u32) asm("func_002537c8");
void func_0023fa08(u32, u32) asm("func_0023fa08");
extern char D_0035f3a8[] asm("D_0035f3a8");
/*TARGET 00276410*/
// 0x002691c8: definition moved into src/anon/unit_00268b30.cpp

void func_00276410(void) asm("func_00276410");
// 0x002691c8: definition moved into src/anon/unit_00268b30.cpp

void func_00276410(void) {
    func_0023fa08((u32)D_0035f3a8, func_002537c8(3));
}
}  // namespace n00276410

// 00276438 (was src/anon/batch_w39.cpp)
namespace n00276438 {
// --- 00276438
extern u32 D_0035f200 asm("D_0035f200");
int func_002892f8(u32) asm("func_002892f8");
int func_0028acc8(u32) asm("func_0028acc8");
void func_00288e88(u32) asm("func_00288e88");
/*TARGET 00276438*/
void func_00276438(void) asm("func_00276438");
void func_00276438(void) {
    if (!D_0035f200) return;
    int a = func_002892f8(D_0035f200);
    if (func_0028acc8(D_0035f200)) return;
    if (!a) return;
    func_00288e88(D_0035f200);
}
}  // namespace n00276438

// .rodata 0x373cec
extern const u32 R_00373cec[1] asm("D_00373cec") __attribute__((aligned(4))) = { 0x2 };

// 002764b0 (was src/anon/batch_w403.cpp)
namespace n002764b0 {
extern u8 D_0032bae0 asm("D_0032bae0");
/*TARGET 002764b0*/
/* Index lookup with a hole-y switch; negative input means "use the current value"
   (byte at 0x32bae0). default sits mid-switch in the original (body order proves it). */
s32 Tz__Jiminy__AreaWorld2JmWorld(s32 a) asm("Tz__Jiminy__AreaWorld2JmWorld");
/* Index lookup with a hole-y switch; negative input means "use the current value"
   (byte at 0x32bae0). default sits mid-switch in the original (body order proves it). */
s32 Tz__Jiminy__AreaWorld2JmWorld(s32 a) {
    if (a < 0) a = D_0032bae0;
    switch (a) {
    case 2: return 0;
    case 4: return 1;
    case 5: return 2;
    case 1: case 6: return 3;
    case 7: return 4;
    case 8: return 5;
    case 9: return 6;
    case 10: return 7;
    case 11: return 8;
    case 12: return 9;
    case 13: return 10;
    case 14: return 11;
    default: return -1;
    case 16: return 12;
    case 17: return 13;
    case 18: return 14;
    }
}
}  // namespace n002764b0

// 00276568 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00276568
extern u32 D_0035f1fc asm("D_0035f1fc");
/*TARGET 00276568*/
void* Tz_Jiminy_GetMenuInfo() asm("_ZN2Tz6Jiminy11GetMenuInfoEv");
void* Tz_Jiminy_GetMenuInfo() {
    return reinterpret_cast<void*>(D_0035f1fc);
}
}  // Tz

// 00276578 (was src/anon/tiny_more.cpp)
namespace n00276578 {
extern u32 D_0035f1fc asm("D_0035f1fc");
/*TARGET 00276578*/
void func_00276578(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_00276578jjjj");
void func_00276578(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p = D_0035f1fc; *(u8*)((u32)p + (0)) = (u8)a0; }
}  // namespace n00276578

// 00276588 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00276588
extern u32 D_0035f1fc asm("D_0035f1fc");
/*TARGET 00276588*/
void Tz_Jiminy_SetCover(s32 value) asm("_ZN2Tz6Jiminy8SetCoverEi");
void Tz_Jiminy_SetCover(s32 value) {
    u32 p = D_0035f1fc;
    *(u8*)((u32)p + 1) = (u8)value;
}
}  // Tz

// 00276598 (was src/anon/tiny_auto80_queue.cpp)
namespace n00276598 {
// 0x0026eda8: definition moved into src/anon/unit_0026c450.cpp

extern u8 D_0035f158 asm("D_0035f158");
/*TARGET 00276598*/
void func_00276598() asm("_Z13func_00276598v");
void func_00276598() {
    s32 c = 0;
    s32 d = 0;
    do {
        u16* p = (u16*)((u8*)&D_0035f158 + d);
        s32 e = 40;
        do {
            *p = 0u;
            e -= 1;
            p += 1;
        } while (e >= 0);
        c += 1;
        d += 82;
    } while (c < 2);
}
}  // namespace n00276598

// 002765e8 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 002765e8
extern u32 D_0035f158 asm("D_0035f158");
/*TARGET 002765e8*/
void Tz_Jiminy_SaveCurPos(s32 index, s32 pos, s32 topPos) asm("_ZN2Tz6Jiminy10SaveCurPosEiii");
void Tz_Jiminy_SaveCurPos(s32 index, s32 pos, s32 topPos) {
    u32 p = (u32)&D_0035f158 + ((u32)index << 1);
    *(u16*)(p + 0) = (u16)pos;
    *(u16*)(p + 82) = (u16)topPos;
}
}  // Tz

// 00276608 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00276608
extern u32 D_0035f158 asm("D_0035f158");
/*TARGET 00276608*/
s32 Tz_Jiminy_GetCurPos(s32 index) asm("_ZN2Tz6Jiminy9GetCurPosEi");
s32 Tz_Jiminy_GetCurPos(s32 index) {
    return static_cast<s32>(*(s16*)((u32)&D_0035f158 + ((u32)index << 1)));
}
}  // Tz

// 00276620 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00276620
extern u32 D_0035f158 asm("D_0035f158");
/*TARGET 00276620*/
s32 Tz_Jiminy_GetCurTopPos(s32 index) asm("_ZN2Tz6Jiminy12GetCurTopPosEi");
s32 Tz_Jiminy_GetCurTopPos(s32 index) {
    u32 p = (u32)&D_0035f158 + ((u32)index << 1);
    return static_cast<s32>(*(s16*)(p + 82));
}
}  // Tz

// 00276638 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00276638
s32 Tz_Jiminy_GetCurPos(s32 index) asm("_ZN2Tz6Jiminy9GetCurPosEi");
s32 Tz_Jiminy_GetCurTopPos(s32 index) asm("_ZN2Tz6Jiminy12GetCurTopPosEi");
/*TARGET 00276638*/
s32 Tz_Jiminy_GetSelectPos(s32 index) asm("_ZN2Tz6Jiminy12GetSelectPosEi");
s32 Tz_Jiminy_GetSelectPos(s32 index) {
    return Tz_Jiminy_GetCurPos(index) + Tz_Jiminy_GetCurTopPos(index);
}
}  // Tz

// 00276678 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00276678
extern u32 D_00373d88 asm("D_00373d88");
/*TARGET 00276678*/
void* Tz_Jiminy_GetScrBarSeqTbl() asm("_ZN2Tz6Jiminy15GetScrBarSeqTblEv");
void* Tz_Jiminy_GetScrBarSeqTbl() { return &D_00373d88; }
}  // Tz

// 00276688 (gap, written for the unit)
namespace n00276688 {
s32 func_00276688(void) asm("func_00276688");
s32 func_00276688(void) { return 0; }
}  // namespace n00276688

// 00276690 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00276690
extern u8 D_0035f220 asm("D_0035f220");
void Tz_Jiminy_SetHideLightCursor(bool value) asm("_ZN2Tz6Jiminy18SetHideLightCursorEb");
/*TARGET 00276690*/
void Tz_Jiminy_SetHideCursor(bool value) asm("_ZN2Tz6Jiminy13SetHideCursorEb");
void Tz_Jiminy_SetHideCursor(bool value) {
    u32 v = (u32)value & 0xffu;
    D_0035f220 = (u8)v;
    Tz_Jiminy_SetHideLightCursor(value);
}
}  // Tz

// 002766b0 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 002766b0
extern u32 D_0035f1fc asm("D_0035f1fc");
/*TARGET 002766b0*/
void Tz_Jiminy_SetHideLightCursor(bool value) asm("_ZN2Tz6Jiminy18SetHideLightCursorEb");
void Tz_Jiminy_SetHideLightCursor(bool value) {
    u32 v = (u32)value & 0xffu;
    *(u8*)((u32)&D_0035f1fc + 37) = (u8)v;
}
}  // Tz

// 002766c0 (gap, written for the unit)
namespace n002766c0 {
extern u32 D_0035f1fc asm("D_0035f1fc");
void func_002766c0(void) asm("func_002766c0");
void func_002766c0(void) { *(u8*)((u32)&D_0035f1fc + 38) = 0; }
}  // namespace n002766c0

// 002766d0 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 002766d0
extern u32 D_0035f21c asm("D_0035f21c");
/*TARGET 002766d0*/
void* Tz_Jiminy_GetSeqTbl() asm("_ZN2Tz6Jiminy9GetSeqTblEv");
void* Tz_Jiminy_GetSeqTbl() {
    return reinterpret_cast<void*>(D_0035f21c);
}
}  // Tz

// 002766e0 (was src/anon/batch_w108.cpp)
namespace n002766e0 {
struct Task276;
struct Task276Vt {
    void* pad[5];
    void (*update)(Task276*);
};
struct Task276 {
    Task276Vt* vt;
    u8 body[404];
};
struct Big276 {
    u8 a[408];
    u8 b[408];
    u8 c[408];
    u8 d[408];
    u8 e[436];
    u8 f[436];
    u8 g[436];
    u8 h[436];
    u8 i[436];
    u8 pad[436];
    Task276 tasks0[32];
    Task276 tasks1[32];
};
extern Big276* D_0035f21c asm("D_0035f21c");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00139510(void*) asm("func_00139510");
void func_00276a18(void) asm("func_00276a18");
void func_00276b10(void) asm("func_00276b10");
/*TARGET 002766e0*/
void Tz__Jiminy__LeaveSeqTbl(void) asm("Tz__Jiminy__LeaveSeqTbl");
void Tz__Jiminy__LeaveSeqTbl(void)
{
    s32 i;

    if (func_00139d78(D_0035f21c->a)) func_00139510(D_0035f21c->a);
    if (func_00139d78(D_0035f21c->b)) func_00139510(D_0035f21c->b);
    if (func_00139d78(D_0035f21c->c)) func_00139510(D_0035f21c->c);
    if (func_00139d78(D_0035f21c->d)) func_00139510(D_0035f21c->d);
    if (func_00139d78(D_0035f21c->e)) func_00139510(D_0035f21c->e);
    if (func_00139d78(D_0035f21c->f)) func_00139510(D_0035f21c->f);
    if (func_00139d78(D_0035f21c->g)) func_00139510(D_0035f21c->g);
    if (func_00139d78(D_0035f21c->h)) func_00139510(D_0035f21c->h);
    if (func_00139d78(D_0035f21c->i)) func_00139510(D_0035f21c->i);
    for (i = 0; i < 32; i++) {
        if (func_00139d78(&D_0035f21c->tasks0[i])) {
            Task276* t = ((Big276*)(i * sizeof(Task276) + (u32)D_0035f21c))->tasks0;
            t->vt->update(t);
        }
        if (func_00139d78(&D_0035f21c->tasks1[i])) {
            Task276* t = ((Big276*)(i * sizeof(Task276) + (u32)D_0035f21c))->tasks1;
            t->vt->update(t);
        }
    }
    func_00276a18();
    func_00276b10();
}
}  // namespace n002766e0

// 00276888 (was src/anon/batch_w114.cpp)
namespace n00276888 {
extern u8* D_0035f21c asm("D_0035f21c");
s32 func_00139d78(u8*) asm("func_00139d78");
s32 func_00276a90(void) asm("func_00276a90");
s32 func_00276b90(void) asm("func_00276b90");
s32 func_00276888(void) asm("func_00276888");
/*TARGET 00276888*/
s32 func_00276888(void) asm("func_00276888");
s32 func_00276888(void) {
    s32 r = 0, i;
    if (func_00139d78(D_0035f21c)) r = 1;
    if (r) return r;
    if (func_00139d78(D_0035f21c + 408)) r = 1;
    if (r) return r;
    r = func_00139d78(D_0035f21c + 816) != 0;
    if (r) return r;
    if (func_00139d78(D_0035f21c + 1224)) r = 1;
    if (r) return r;
    r = func_00139d78(D_0035f21c + 1632) != 0;
    if (r) return r;
    if (func_00139d78(D_0035f21c + 2068)) r = 1;
    if (r) return r;
    r = func_00139d78(D_0035f21c + 2504) != 0;
    if (r) return r;
    if (func_00139d78(D_0035f21c + 2940)) r = 1;
    if (r) return r;
    r = func_00139d78(D_0035f21c + 3376) != 0;
    if (r) return r;
    for (i = 0; i < 32; i++) {
        if (func_00139d78(D_0035f21c + i * 408 + 4248) || func_00139d78(D_0035f21c + i * 408 + 17304)) { r = 1; break; }
    }
    if (r) return r;
    r = func_00276a90();
    if (!r) r = func_00276b90();
    return r;
}
}  // namespace n00276888

// 00276a18 (was src/anon/auto80_199_queue.cpp)
namespace n00276a18 {
/*TARGET 00276a18*/
void func_00276a18() asm("_Z13func_00276a18v");
void func_00276a18() {
    s32 s0 = 0;
    s32 s1 = 31;
    do {
        if (func_00139d78(D_0035f21c + s0 + 30360) != 0) {
            u32 p = s0 + D_0035f21c;
            u32 vt = *(u32*)(p + 30360);
            u32 fn = *(u32*)(vt + 20);
            ((void (*)(u32))fn)(p + 30360);
        }
        s1 -= 1;
        s0 += 408;
    } while (s1 >= 0);
}
}  // namespace n00276a18

// 00276a90 (was src/anon/batch_w57.cpp)
namespace n00276a90 {
extern void (**D_0032b914)() asm("D_0032b914");
// 0x00263e18: definition moved into src/anon/unit_002632d0.cpp

// Does any of the 32 records satisfy the predicate?
u32 func_00139d78(u32) asm("func_00139d78");
extern u8* D_0035f21c asm("D_0035f21c");
/*TARGET 00276a90*/
u32 func_00276a90(void) asm("func_00276a90");
u32 func_00276a90(void) {
    u32 r = 0;
    for (s32 i = 0; i < 32; i++) {
        if (func_00139d78((u32)D_0035f21c + i * 408 + 30360)) { r = 1; break; }
    }
    return r;
}
}  // namespace n00276a90

// 00276b10 (was src/anon/batch_w61.cpp)
namespace n00276b10 {
// 00108600: moved to src/anon/unit_001085a8.cpp

struct VObj { s32 (**vt)(...); };
s32 func_00139d78(void*) asm("func_00139d78");
// 0x0026b508: definition moved into src/anon/unit_0026a900.cpp

extern u8* D_0035f21c asm("D_0035f21c");
/*TARGET 00276b10*/
void func_00276b10(void) asm("func_00276b10");
void func_00276b10(void) {
    for (s32 i = 0; i < 32; i++) {
        if (func_00139d78(D_0035f21c + i * 408 + 0xa998)) {
            VObj* o = (VObj*)(i * 408 + (u32)D_0035f21c + 0xa998);
            ((void (*)(VObj*))o->vt[5])(o);
        }
    }
}
}  // namespace n00276b10

// 00276b90 (was src/anon/batch_w52.cpp)
namespace n00276b90 {
extern u8* D_0035f21c asm("D_0035f21c");
u32 func_00139d78(u8*) asm("func_00139d78");
/*TARGET 00276b90*/
u32 func_00276b90(void) asm("func_00276b90");
u32 func_00276b90(void) {
    s32 i;
    u32 r = 0;
    u8* q;
    for (i = 0; i < 32; i++) {
        q = D_0035f21c;
        if (func_00139d78(q + i * 408 + 0xa998)) {
            r = 1;
            break;
        }
    }
    return r;
}
}  // namespace n00276b90

// 00276c18 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00276c18 {
u32 func_00181500(u32, u32, u32, u32) asm("_Z13func_00181500jjjj");
/*TARGET 00276c18*/
u32 func_00276c18(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00276c18jjjj");
u32 func_00276c18(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)0u + (18487));
    u32 (*fp_call4_00181500)(u32, u32, u32, u32) = func_00181500;
    r2 = fp_call4_00181500(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00276c18

// 00276c38 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00276c38
extern u32 D_00373da0 asm("D_00373da0");
/*TARGET 00276c38*/
s32 Tz_Jiminy_GetFontColorSeqNum(s32 index) asm("_ZN2Tz6Jiminy18GetFontColorSeqNumEi");
s32 Tz_Jiminy_GetFontColorSeqNum(s32 index) {
    return static_cast<s32>(*(s16*)((u32)&D_00373da0 + ((u32)index << 1)));
}
}  // Tz

// 00276c50 (was src/anon/batch_w22.cpp)
namespace n00276c50 {
// --- 00276c50
// Tz JmReport DrawMessage
u32 func_00192048(u32) asm("func_00192048");
u32 Tz__Jiminy__CreateHelp(u32, u8) asm("Tz__Jiminy__CreateHelp");
u32 JmReport_DrawMessage(s32, u8) asm("_ZN2Tz8JmReport11DrawMessageEjj");
/*TARGET 00276c50*/
u32 JmReport_DrawMessage(s32 a, u8 b) asm("_ZN2Tz8JmReport11DrawMessageEjj");
u32 JmReport_DrawMessage(s32 a, u8 b) {
    u32 p = 0;
    if (a >= 0) p = func_00192048(a);
    return Tz__Jiminy__CreateHelp(p, b);
}
}  // namespace n00276c50

// 00276c88 (was src/anon/batch_w98.cpp)
namespace n00276c88 {
s32 func_00139d78(u8*) asm("func_00139d78");
void func_0028dcc0(u8*, u32) asm("func_0028dcc0");
void func_001395f8(u8*) asm("func_001395f8");
extern u8* D_0035f21c asm("D_0035f21c");
extern u8* D_0035f20c asm("D_0035f20c");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f210 asm("D_0035f210");
s32 func_00276df8(void) asm("func_00276df8");
void func_0028d980(u8*, s32, u32, u32, u32, s32, s32, s32, s32) asm("func_0028d980");
void func_00138c10(u8*, s32) asm("func_00138c10");
u32 func_0023aa18(u8*) asm("func_0023aa18");
u32 func_0023aa38(u8*) asm("func_0023aa38");
void func_00138c68(u8*, u32, u32) asm("func_00138c68");
/*TARGET 00276c88*/
// Opens (or retargets) the info window for id; optionally fills it from the current entry.
void Tz__Jiminy__CreateHelp(u32 id, u8 flag) asm("Tz__Jiminy__CreateHelp");
// Opens (or retargets) the info window for id; optionally fills it from the current entry.
void Tz__Jiminy__CreateHelp(u32 id, u8 flag) {
    u8* w = D_0035f21c + 3812;
    if (!func_00276df8()) {
        func_0028d980(w, 30045, D_0035f14c, D_0035f148, D_0035f210, 145, -1, -1, 0);
        if (func_00139d78(D_0035f20c + 1308)) func_0028dcc0(w, (u32)(D_0035f20c + 1308));
        *(u32*)(w + 408) = id;
        func_001395f8(w);
        if (flag) {
            func_00139d78(D_0035f20c + 1308);
            u32 x = func_0023aa18(D_0035f20c + 1332);
            func_00138c68(w, x, func_0023aa38(D_0035f20c + 1332));
        }
    } else {
        *(u32*)(w + 408) = id;
        if (*(s32*)(w + 388) != 145) {
            func_00138c10(w, 145);
            *(s32*)(w + 392) = -1;
        }
    }
}
}  // namespace n00276c88

// 00276dc0 (was src/anon/tiny_auto80_queue.cpp)
namespace n00276dc0 {
extern u32 D_0035f21c asm("D_0035f21c");
u32 func_0028dac8(...) asm("func_0028dac8");
/*TARGET 00276dc0*/
void Tz__Jiminy__FadeOutHelp() asm("_Z23Tz__Jiminy__FadeOutHelpv");
void Tz__Jiminy__FadeOutHelp() {
    u32 t6 = *(u32*)(u32)&D_0035f21c;
    if (t6 == 0u) {
        return;
    }
    func_0028dac8((void*)(t6 + 3812u), 146u);
}
}  // namespace n00276dc0

// 00276df8 (was src/anon/batch_w7.cpp)
namespace n00276df8 {
u8 func_00139d78(u32) asm("func_00139d78");
extern u32 D_0035f21c asm("D_0035f21c");
/*TARGET 00276df8*/
u32 func_00276df8(void) asm("func_00276df8");
u32 func_00276df8(void) {
    u32 p = D_0035f21c;
    if (p == 0) return 0;
    return func_00139d78(p + 3812);
}
}  // namespace n00276df8

// 00276e28 (was src/anon/tiny_auto80_queue.cpp)
namespace n00276e28 {
u32 func_00139510(...) asm("func_00139510");
u32 func_00276df8(...) asm("func_00276df8");
/*TARGET 00276e28*/
extern u8* D_0035f21c_e28 asm("D_0035f21c");
s32 func_00276df8_e28(void) asm("func_00276df8");
void func_00139510_e28(u8*) asm("func_00139510");
void func_00276e28(void) asm("_Z13func_00276e28jjjjjjjj");
void func_00276e28(void) {
    if (D_0035f21c_e28 == 0) return;
    if (func_00276df8_e28() == 0) return;
    func_00139510_e28(D_0035f21c_e28 + 3812);
}
}  // namespace n00276e28

// 00276e78 (was src/anon/batch_w1582_g.cpp)
namespace n00276e78 {
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00276348(void) asm("func_00276348");
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_00139620(u8*) asm("func_00139620");
void func_0028dcc0(u8*, s32) asm("func_0028dcc0");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f210 asm("D_0035f210");
extern s8* D_0035f1fc asm("D_0035f1fc");
extern u8* D_0035f21c asm("D_0035f21c");
extern u16 D_00373d40[] asm("D_00373d40");
/*TARGET 00276e78*/
void Tz__Jiminy__CreateCover(void) asm("Tz__Jiminy__CreateCover");
void Tz__Jiminy__CreateCover(void) {
    s32 r = func_00276348();
    s32 mode = func_00287bc0();
    s32 i = D_0035f1fc[1];
    if (mode == 16 || mode == 19 || mode == 22) i += 2;
    func_0028d8c0(D_0035f21c + 408, 30042, D_0035f14c, D_0035f148, D_0035f210, D_00373d40[i], -1, 0);
    func_00139620(D_0035f21c + 408);
    func_0028dcc0(D_0035f21c + 408, r);
}
}  // namespace n00276e78

// 00276f38 (was src/anon/batch_w2.cpp)
namespace n00276f38 {
extern u8* D_0035f21c asm("D_0035f21c");
// id_in_range_5_7_131
u8 func_00139d78(u8*) asm("func_00139d78");
/*TARGET 00276f38*/
// 0x00263688: definition moved into src/anon/unit_002632d0.cpp

u8 func_00276f38(void) asm("func_00276f38");
// 0x00263688: definition moved into src/anon/unit_002632d0.cpp

u8 func_00276f38(void) {
    return func_00139d78(D_0035f21c + 408);
}
}  // namespace n00276f38

// 00276f60 (was src/anon/tiny_auto80_queue.cpp)
namespace n00276f60 {
u32 func_00139510(...) asm("func_00139510");
u32 func_00139d78(...) asm("func_00139d78");
/*TARGET 00276f60*/
extern u8* D_0035f21c_f60 asm("D_0035f21c");
s32 func_00139d78_f60(u8*) asm("func_00139d78");
void func_00139510_f60(u8*) asm("func_00139510");
void func_00276f60(void) asm("_Z13func_00276f60jjjjjjjj");
void func_00276f60(void) {
    if (func_00139d78_f60(D_0035f21c_f60 + 408) == 0) return;
    func_00139510_f60(D_0035f21c_f60 + 408);
}
}  // namespace n00276f60

// 00276fa8 (was src/anon/tiny_auto80_queue.cpp)
namespace n00276fa8 {
extern u32 D_0035f1fc asm("D_0035f1fc");
extern u8  D_00373d50 asm("D_00373d50");
extern u8  D_00373d58 asm("D_00373d58");
/*TARGET 00276fa8*/
u32 func_00276fa8() asm("_Z13func_00276fa8v");
u32 func_00276fa8() {  // global_ptr_by_flag2
    if (*(s8*)((*(u32*)(u32)&D_0035f1fc) + 2u) != 0) {
        return (u32)&D_00373d58;
    }
    return (u32)&D_00373d50;
}
}  // namespace n00276fa8

// 00276fd0 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00276fd0
u32 func_002ad018(...) asm("func_002ad018");
/*TARGET 00276fd0*/
u32 Tz_Jiminy_GetAccomplishmentRate() asm("_ZN2Tz6Jiminy21GetAccomplishmentRateEv");
u32 Tz_Jiminy_GetAccomplishmentRate() {
    return func_002ad018();
}
}  // Tz

// 00276fe8 (was src/anon/batch_w1587.cpp)
namespace n00276fe8 {
extern u32 D_0035f230 asm("D_0035f230");
void Tz__CmAbility__Init(void) asm("Tz__CmAbility__Init");
/*TARGET 00276fe8*/
void func_00276fe8(void) asm("func_00276fe8");
void func_00276fe8(void) { D_0035f230 = 0; Tz__CmAbility__Init(); }
}  // namespace n00276fe8

// 00277008 (was src/anon/tiny.cpp)
namespace n00277008 {
void func_00277070(void*) asm("_Z13func_00277070Pv");
/*TARGET 00277008*/
// 0x002677d8: definition moved into src/anon/unit_00265580.cpp
void func_00277008(BD_VALUE* bd) asm("_Z13func_00277008P8BD_VALUE");
// 0x002677d8: definition moved into src/anon/unit_00265580.cpp
void func_00277008(BD_VALUE* bd) { func_00277070(bd); }
}  // namespace n00277008

// 00277020 (was src/anon/batch_w1589.cpp)
namespace n00277020 {
s32 func_00103570(void) asm("func_00103570");
void* func_001063c0(s32, s32) asm("func_001063c0");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
struct W1589En { u8 x[2]; s8 a; u8 y[2]; s8 b; u8 z[2]; };
struct W1589S { u8 pad[4]; u16 h4; u8 pad6; s8 n; u8 p8[4]; W1589En e[1]; };
/* union with a u16 member: the original reloads the pointer after each u16 store */
union W1589G { W1589S* p; void* v; u16 h; s8 c; };
extern W1589G D_0035f230 asm("D_0035f230");
/*TARGET 00277020*/
void Tz__CmAbility__Init(void) asm("Tz__CmAbility__Init");
void Tz__CmAbility__Init(void)
{
    if (D_0035f230.v == 0) {
        D_0035f230.v = func_001063c0(668, func_00103570());
    }
    func_002fde18(D_0035f230.v, 0, 668);
}
}  // namespace n00277020

// 00277070 (was src/anon/tiny_auto80_queue.cpp)
namespace n00277070 {
u32 func_00106420(...) asm("func_00106420");
/*TARGET 00277070*/
void func_00277070(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00277070jjjjjjjj");
void func_00277070(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = (u32)(0x0036u << 16);
    r15 = *(u32*)((u32)r16 + (s32)(-3536));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00106420)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(u32*)((u32)r16 + (s32)(-3536)) = 0u;
    }
}
}  // namespace n00277070

// 002770a8 (was src/tozawa/cmenu_stat.cpp)
namespace n002770a8 { // method 002770a8
// 0x00267270: definition moved into src/anon/unit_00265580.cpp

extern "C" u32 func_00287bc0(...) asm("func_00287bc0");
u32 func_00287db0(...) asm("func_00287db0");
void func_00256e80(...) asm("func_00256e80");
void Tz__CmAbility__FadeOutSelList(...) asm("Tz__CmAbility__FadeOutSelList");
void func_0027a7e0(...) asm("func_0027a7e0");
void Tz__CmAbility__FadeOutAbilityList(...) asm("Tz__CmAbility__FadeOutAbilityList");
void func_0027b4e8(...) asm("func_0027b4e8");
/*TARGET 002770a8*/
// 0x002674f8: definition moved into src/anon/unit_00265580.cpp

void Tz_CmStat_FadeOutAll() asm("_ZN2Tz6CmStat10FadeOutAllEv");
void Tz_CmStat_FadeOutAll() {
    u32 mode = func_00287bc0();
    if ((u32)(mode - 15) >= 5) {
        return;
    }

    Tz__CmAbility__FadeOutSelList();
    func_0027a7e0(1);
    Tz__CmAbility__FadeOutAbilityList();

    if (func_00287db0() != 0) {
        func_00256e80();
    }

    if (func_00287db0() == 0) {
        return;
    }

    func_00256e80();
    func_0027b4e8();
}
}  // Tz

// 00277128 (was src/tozawa/cmenu_ability.cpp)
namespace n00277128 { // method 00277128
u32 func_00287bc0() asm("func_00287bc0");
void func_0027a180() asm("func_0027a180");
void func_0027a898(u32) asm("func_0027a898");
void func_0027acf8() asm("func_0027acf8");
void func_00256ea8() asm("func_00256ea8");
/*TARGET 00277128*/
void Tz_CmAbility_LeaveAll() asm("_ZN2Tz9CmAbility8LeaveAllEv");
void Tz_CmAbility_LeaveAll() {
    if ((u32)(func_00287bc0() - 15u) >= 5u) {
        return;
    }
    func_0027a180();
    func_0027a898(1u);
    func_0027acf8();
    func_00256ea8();
}
}  // Tz

// 00277178 (was src/anon/batch_w269.cpp)
namespace n00277178 {
union PU269 { u8* p; u16 h; u8 c; };
// 0x0019dbc0: definition moved into src/anon/unit_0019ba60.cpp

extern PU269 D_0035f230 asm("D_0035f230");
extern s32 D_0035f010 asm("D_0035f010");
u8* func_002570e0(void) asm("func_002570e0");
void func_0028fb28(s32, u16) asm("func_0028fb28");
void func_00257050(s32, s32, s32) asm("func_00257050");
s32 func_00257070(s32) asm("func_00257070");
void Tz__CmAbility__SetupTop(s32) asm("Tz__CmAbility__SetupTop");
u16 func_002813b8(void) asm("func_002813b8");
s32 func_0027ae20(void) asm("func_0027ae20");
s32 func_00281100(s32) asm("func_00281100");
s32 func_0027aa78(void) asm("func_0027aa78");
s32 func_00281140(s32, s32) asm("func_00281140");
void func_0028fb68(s32, s32) asm("func_0028fb68");
void func_00279040(void) asm("func_00279040");
void Tz__CmAbility__SetupSel(void) asm("Tz__CmAbility__SetupSel");
/*TARGET 00277178*/
void func_00277178(s32 a0, s32 a1) asm("func_00277178");
void func_00277178(s32 a0, s32 a1) {
    func_0028fb28(0, *(u16*)(func_002570e0() + 54));
    func_00257050(0, 1, 0);
    if (a0 == 15) {
        Tz__CmAbility__SetupTop(a1);
        return;
    }
    PU269* p = (PU269*)D_0035f230.p;
    p->h = func_002813b8();
    u8* q = D_0035f230.p;
    s32 r = func_0027ae20();
    q[6] = r + func_00281100(D_0035f010);
    if (func_0027aa78()) *(u16*)D_0035f230.p |= 0x80;
    if (a1) a1 += func_0027ae20();
    if (func_00257070(15) != a1) {
        func_00257050(16, 0, 0);
        func_00257050(15, a1, 0);
    }
    if (a1) a1 -= func_0027ae20();
    func_0028fb68(1, func_00281140(D_0035f010, a1));
    func_00279040();
    Tz__CmAbility__SetupSel();
}
}  // namespace n00277178

// .rodata 0x373d3c-0x373db0: Jiminy tables that old code reads as extern D_
extern const u32 R_00373d3c[1] asm("D_00373d3c") __attribute__((aligned(4))) = { 0x0 };
extern const u32 R_00373d40[4] asm("D_00373d40") __attribute__((aligned(4))) = { 0x200001, 0x1f001e, 0x1d, 0x0 };
extern const u32 R_00373d50[2] asm("D_00373d50") __attribute__((aligned(4))) = { 0x20000, 0x1 };
extern const u32 R_00373d58[2] asm("D_00373d58") __attribute__((aligned(4))) = { 0x50003, 0x4 };
extern const u32 R_00373d60[2] asm("D_00373d60") __attribute__((aligned(4))) = { 0x970099, 0x98 };
extern const u32 R_00373d68[2] asm("D_00373d68") __attribute__((aligned(4))) = { 0x9a0096, 0x98 };
extern const u32 R_00373d70[2] asm("D_00373d70") __attribute__((aligned(4))) = { 0x2f622f60, 0x2f61 };
extern const u32 R_00373d78[2] asm("D_00373d78") __attribute__((aligned(4))) = { 0x890087, 0x88 };
extern const u32 R_00373d80[2] asm("D_00373d80") __attribute__((aligned(4))) = { 0x250023, 0x24 };
extern const u32 R_00373d88[6] asm("D_00373d88") __attribute__((aligned(4))) = { 0x8b0001, 0x8c008a, 0x8b0001, 0x8c008a, 0x8b0001, 0x8c008a };
extern const u32 R_00373da0[4] asm("D_00373da0") __attribute__((aligned(4))) = { 0x8e0094, 0x930095, 0x8f0090, 0x8d };
