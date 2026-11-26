// Linked unit 0x002aeba0-0x002af418 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/jm_newinfo.hpp"
#include "../tozawa/jm_complete.hpp"
#include "../tozawa/jm_puzzle.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 002aeba0 (was src/anon/batch_w268.cpp)
namespace n002aeba0 {
struct W268VObj { void (**vt)(W268VObj*); };
extern void* D_0035f638 asm("D_0035f638");
extern u8* D_0035f634 asm("D_0035f634");
extern void* D_0035f630 asm("D_0035f630");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
void func_0023f848(void*) asm("func_0023f848");
void func_00106420(void*) asm("func_00106420");
void func_00106450(void*) asm("func_00106450");
void func_0031acc0(void*) asm("func_0031acc0");
void func_0031abd8(void*) asm("func_0031abd8");
void func_00239870(void*) asm("func_00239870");
void func_002816f0(void) asm("func_002816f0");
void Tz__JmPuzzle__Exit(void) asm("Tz__JmPuzzle__Exit");
void Tz__JmPuzzle__Exit(void)
{
    void* lf = D_0035f638;
    if (lf) {
        func_0023f848(lf);
        func_00106420(lf);
        D_0035f638 = 0;
    }
    u8* p = D_0035f634;
    if (p) {
        func_0031acc0(p + 24212);
        func_0031acc0(p + 23776);
        func_0031acc0(p + 23340);
        func_0031acc0(p + 22904);
        func_0031acc0(p + 22468);
        func_0031acc0(p + 22032);
        func_0031abd8(p + 21624);
        func_0031abd8(p + 21216);
        func_0031abd8(p + 20808);
        if (p + 19992) {
            u8* e = p + 20808;
        top1:
            if (p + 19992 == e) goto out1;
            e -= 408;
            ((W268VObj*)e)->vt[3]((W268VObj*)e);
            goto top1;
        out1:;
        }
        u8* e2 = p + 19584;
        *(u32*)(p + 19584) = (u32)D_00347e60;
        func_00239870(p + 19608);
        *(u32*)(p + 19584) = (u32)D_00347f98;
        if (p) {
            u8* e = e2;
        top2:
            if (p == e) goto out2;
            e -= 408;
            ((W268VObj*)e)->vt[3]((W268VObj*)e);
            goto top2;
        out2:;
        }
        func_00106420(p);
        D_0035f634 = 0;
    }
    if (D_0035f630) {
        func_00106450(D_0035f630);
        D_0035f630 = 0;
    }
    func_002816f0();
}
}  // namespace n002aeba0

// 002aece8 (was src/anon/misc_2.cpp)
namespace n002aece8 {
void func_002aece8(void* self) asm("_Z13func_002aece8Pv");
void func_002aece8(void* self) {}
}  // namespace n002aece8

// 002aecf0 (was src/anon/auto80_199_queue.cpp)
namespace n002aecf0 {
u32 func_002aecf0(u32 a0) asm("_Z13func_002aecf0j");
u32 func_002aecf0(u32 a0) {
    u32 s0 = a0 & 0xff;
    u32 v0 = func_00287bc0();

    if ((u32)(v0 - 27) < 4 || v0 == 33 || v0 == 32 || v0 == 31) {
        if (s0 != 0) {
            Tz__JmPuzzle__LeaveAll();
        }
        func_00274ac8();
        return Tz__JmPuzzle__LeaveSeqTbl();
    }

    return v0;
}
}  // namespace n002aecf0

// 002aed60 (was src/anon/batch_w2410_gnsa_nogcse.cpp)
namespace n002aed60 {
void Tz__UnitLoad__Exit(void) asm("Tz__UnitLoad__Exit");
void Tz__UnitLoad__Init(s32) asm("Tz__UnitLoad__Init");
void func_00292870(void) asm("func_00292870");
s32 func_00276348(void) asm("func_00276348");
s32 func_002766d0(void) asm("func_002766d0");
s32 func_0028f930(s32) asm("func_0028f930");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void func_002aeb28(void) asm("func_002aeb28");
void Tz__Jiminy__CreateCover(void) asm("Tz__Jiminy__CreateCover");
void func_0028d8c0(s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_00139620(s32) asm("func_00139620");
void func_0028dcc0(s32, s32) asm("func_0028dcc0");
s32 func_0023aa78(s32) asm("func_0023aa78");
void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("Tz__Select__SetItem");
s32 func_002891b8(s32, s32) asm("func_002891b8");
void func_00138c68(s32, s32, s32) asm("func_00138c68");
void func_001395f8(s32) asm("func_001395f8");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00276608(s32) asm("func_00276608");
void Tz__Select__SetCurrent(s32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void Tz__Select__SetSelectMax(s32, s32) asm("Tz__Select__SetSelectMax");
void func_0028afd0(s32, s32) asm("func_0028afd0");
void Tz__Select__SetPageMode(s32, s32) asm("Tz__Select__SetPageMode");
void func_0028b248(s32, s32) asm("func_0028b248");
void Tz__JmPuzzle__UpdateTopList(void) asm("Tz__JmPuzzle__UpdateTopList");
void Tz__JmPuzzle__UpdateHelpMess(void) asm("Tz__JmPuzzle__UpdateHelpMess");
void func_002766b0(s32) asm("func_002766b0");
void func_00287cc0(s32) asm("func_00287cc0");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f200 asm("D_0035f200");
void func_002aed60(void) asm("func_002aed60");
void func_002aed60(void) {
    s16 arr[2][4];
    s32 a, b, i, j, n, sz, off, r, c;
    Tz__UnitLoad__Exit();
    Tz__UnitLoad__Init(0);
    func_00292870();
    a = func_00276348();
    b = func_002766d0();
    if (!func_0028f930(0)) {
        func_0028f4d8(0, -1, 0);
        func_002aeb28();
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) arr[i][j] = 2;
    }
    n = D_0035f3d4 - 1;
    Tz__Jiminy__CreateCover();
    {s32 z = D_0035f14c, y = D_0035f148, x = D_0035f210;
    func_0028d8c0(b, n, z, y, x, 90, -1, 0);}
    func_00139620(b);
    func_0028dcc0(b, a);
    sz = func_0023aa78(b + 0x18);
    n = D_0035f3d4;
    n++;
    c = b + 0xa998;
    off = 0;
    for (i = 0; i < 3; i++) {
        Tz__Select__SetItem(D_0035f200, i, D_0035f14c, D_0035f148, D_0035f210, -1, arr[0], arr[1]);
        r = func_002891b8(D_0035f200, i);
        func_00139620(r);
        func_0028dcc0(r, b);
        func_00138c68(r, 0, off);
        off += sz;
        ((s32*)r)[0x1a4/4] = 0x60000008;
        ((s32*)r)[0x1ac/4] = 3;
        func_001395f8(r);
        func_0028d8c0(c, n, D_0035f14c, D_0035f148, D_0035f210, 2, -1, 0);
        func_0028dcc0(c, r);
        c += 0x198;
    }
    Tz__Select__SetCurrent(D_0035f200, func_00276608(func_00287bc0()), 0, -1, -1);
    Tz__Select__SetSelectMax(D_0035f200, 3);
    func_0028afd0(D_0035f200, 0);
    Tz__Select__SetPageMode(D_0035f200, 1);
    func_0028b248(D_0035f200, 10);
    Tz__JmPuzzle__UpdateTopList();
    Tz__JmPuzzle__UpdateHelpMess();
    func_002766b0(1);
    func_00287cc0(0);
}
}  // namespace n002aed60

// 002af010 (was src/anon/batch_w1591.cpp)
namespace n002af010 {
s32 func_00287bc0() asm("func_00287bc0");
void Tz__JmPuzzle__CtrlTop() asm("Tz__JmPuzzle__CtrlTop");
void Tz__JmPuzzle__CtrlSel() asm("Tz__JmPuzzle__CtrlSel");
void func_002afe18() asm("func_002afe18");
void Tz__JmPuzzle__CtrlTutorial() asm("Tz__JmPuzzle__CtrlTutorial");
void func_002b14f0() asm("func_002b14f0");
void Tz__JmTreasure__CtrlPieceInfo() asm("Tz__JmTreasure__CtrlPieceInfo");
void func_002af010(void) asm("func_002af010");
void func_002af010(void) {
    switch (func_00287bc0()) {
    case 27: Tz__JmPuzzle__CtrlTop(); return;
    case 28: Tz__JmPuzzle__CtrlSel(); return;
    case 29: func_002afe18(); return;
    case 30: case 31: Tz__JmPuzzle__CtrlTutorial(); return;
    case 32: func_002b14f0(); return;
    case 33: Tz__JmTreasure__CtrlPieceInfo(); return;
    }
}
}  // namespace n002af010

// 002af0a0 (was src/anon/batch_w1613.cpp)
namespace n002af0a0 {
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_002891e8(s32) asm("func_002891e8");
s32 func_00289310(s32) asm("func_00289310");
s32 func_00242848(s32) asm("func_00242848");
void Tz__Jiminy__LoadData(s32) asm("Tz__Jiminy__LoadData");
void func_00275b60(void) asm("func_00275b60");
void Tz__Jiminy__SetParentSeqNum(s32, s32) asm("Tz__Jiminy__SetParentSeqNum");
s32 func_00276358(void) asm("func_00276358");
s32 func_00276368(void) asm("func_00276368");
s32 func_00276398(void) asm("func_00276398");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
void func_002766b0(s32) asm("func_002766b0");
s32 func_00276888(void) asm("func_00276888");
void Tz__Jiminy__FadeOutHelp(void) asm("Tz__Jiminy__FadeOutHelp");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287c00(s32) asm("func_00287c00");
void func_00287c30(void) asm("func_00287c30");
void func_00287c90(s32) asm("func_00287c90");
void func_00287cc0(s32) asm("func_00287cc0");
void func_00287da0(void) asm("func_00287da0");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_00287f90(s32) asm("func_00287f90");
void func_00288018(void) asm("func_00288018");
s32 func_00288040(void) asm("func_00288040");
s32 func_00289380(s32) asm("func_00289380");
s32 func_0028acc8(s32) asm("func_0028acc8");
void func_0028af18(s32, s32) asm("func_0028af18");
s32 func_0028b038(s32) asm("func_0028b038");
void Tz__SelHist__FadeOut(s32) asm("Tz__SelHist__FadeOut");
void func_002925c0(void) asm("func_002925c0");
s32 func_00292630(void) asm("func_00292630");
void Tz__UnitLoad__Init(s32) asm("Tz__UnitLoad__Init");
void Tz__UnitLoad__Exit(void) asm("Tz__UnitLoad__Exit");
void func_00292870(void) asm("func_00292870");
void func_002995e8(void) asm("func_002995e8");
void Tz__JmTreasure__SetupPieceInfo(void) asm("Tz__JmTreasure__SetupPieceInfo");
void func_002aece8(void) asm("func_002aece8");
void func_002aecf0(s32) asm("func_002aecf0");
void func_002af418(void) asm("func_002af418");
void func_002b01d8(void) asm("func_002b01d8");
void func_002b3b78(void) asm("func_002b3b78");
extern s32 D_0035f200 asm("D_0035f200");
struct S374cb0 { s16 a; s16 b; };
extern S374cb0 D_00374cb0[] asm("D_00374cb0");
void Tz__JmPuzzle__CtrlTop(void) asm("Tz__JmPuzzle__CtrlTop");
void Tz__JmPuzzle__CtrlTop(void)
{
    s32 sel = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (sel != -1) {
                func_00287f90(0);
                func_002aecf0(1);
            }
            return;
        }
        if (func_00292630()) return;
        func_002aecf0(1);
        func_00287c30();
        s32 k = func_00287bc0();
        func_0028af18(D_0035f200, 115);
        Tz__Jiminy__SetParentSeqNum(func_00276358(), 0);
        switch (k) {
        case 13:
            Tz__Jiminy__LoadData(13);
            func_002925c0();
            func_002766b0(0);
            Tz__UnitLoad__Exit();
            Tz__UnitLoad__Init(1);
            func_00292870();
            func_002995e8();
            return;
        case 33: Tz__JmTreasure__SetupPieceInfo(); return;
        case 31: func_002b01d8(); return;
        case 28: func_002af418(); return;
        }
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f200)) && !func_00276398()) {
        Tz__Jiminy__SetParentSeqNum(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398()) func_00287c90(1);
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f200), 1, (s32)func_002b3b78, 1)) == 0) {
        switch (sel) {
        case -1: break;
        case -4: {
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            func_00287da0();
            break;
        }
        case -2: {
            Tz__SelHist__FadeOut(0);
            func_002aece8();
            Tz__Jiminy__FadeOutHelp();
            Tz__Jiminy__SetParentSeqNum(1, 1);
            func_00287c00(13);
            func_00287cc0(2);
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            break;
        }
        default: {
            func_002aece8();
            Tz__Jiminy__FadeOutHelp();
            Tz__Jiminy__SetParentSeqNum(0, 1);
            func_00287c00(D_00374cb0[sel].b);
            func_00287cc0(2);
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            break;
        }
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n002af0a0

