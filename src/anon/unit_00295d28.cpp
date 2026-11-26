// Linked unit 0x00295d28-0x002978f0 (Tz Jiminy journal: world select, report, story).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/jiminy.hpp"
#include "../tozawa/cmenu_slbase.hpp"
#include "../tozawa/jm_report.hpp"
#include "../tozawa/jm_story.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 00295d28 (was src/anon/batch_w1613.cpp)
namespace n00295d28 {
extern s32 D_0035f200 asm("D_0035f200");
// 0x0025dfb0: definition moved into src/anon/unit_0025da20.cpp


u8* func_002766d0(void) asm("func_002766d0");
s32 func_0028afa8(s32) asm("func_0028afa8");
void Tz__Select__SetSelectMax(s32, s32) asm("Tz__Select__SetSelectMax");
u8* func_002891b8(s32, s32) asm("func_002891b8");
s32 func_00192048(u16) asm("func_00192048");
void func_00138c10(u8*, s32) asm("func_00138c10");
s8* func_00276568(void) asm("func_00276568");
s32 Tz__JmDiagram__GetNewInfo(s32, s32) asm("Tz__JmDiagram__GetNewInfo");
s32 func_002ae1b0(s32, s32) asm("func_002ae1b0");
s32 Tz__JmNewInfo__isStoryNew(s32, s32) asm("Tz__JmNewInfo__isStoryNew");
s32 func_002ac110(s32, s32) asm("func_002ac110");
s32 func_002ae0c0(s32) asm("func_002ae0c0");
s32 func_002aa668(s32, s32) asm("func_002aa668");
s32 func_002aa788(s32, s32) asm("func_002aa788");
s32 Tz__JmComplete__isAlbumComp(s32) asm("Tz__JmComplete__isAlbumComp");
s32 func_002a4380(s32) asm("func_002a4380");
s32 Tz__JmNewInfo__isTreasureNew(s32) asm("Tz__JmNewInfo__isTreasureNew");
s32 func_002ab620(s32) asm("func_002ab620");
s32 Tz__JmComplete__isTreasureComp(s32) asm("Tz__JmComplete__isTreasureComp");
s32 Tz__JmPuzzle__isEnable(void) asm("Tz__JmPuzzle__isEnable");
s32 func_00276c18(void) asm("func_00276c18");
s32 Tz__JmNewInfo__isPuzzleInfoNew(s32) asm("Tz__JmNewInfo__isPuzzleInfoNew");
s32 func_002ac800(s32) asm("func_002ac800");
s32 func_002ae890(s32) asm("func_002ae890");
s32 Tz__JmNewInfo__isNaviNew(s32) asm("Tz__JmNewInfo__isNaviNew");
s32 func_002ab9c8(s32) asm("func_002ab9c8");
s32 Tz__JmComplete__isNaviComp(s32) asm("Tz__JmComplete__isNaviComp");
s32 Tz__JmQuest__isEnable(s32) asm("Tz__JmQuest__isEnable");
s32 func_002aae88(s32) asm("func_002aae88");
s32 func_002aaf40(s32) asm("func_002aaf40");
s32 func_002ad7d0(s32) asm("func_002ad7d0");
s32 Tz__JmMiniGame__isEnable(s32) asm("Tz__JmMiniGame__isEnable");
s32 func_002ab2b0(s32) asm("func_002ab2b0");
s32 func_002ab368(s32) asm("func_002ab368");
s32 func_002ad950(s32) asm("func_002ad950");
extern s32 D_00374750 asm("D_00374750");
extern s32 D_00374754 asm("D_00374754");
extern u16 D_00374758[] asm("D_00374758");
/*TARGET 00295d28*/
void func_00295d28(void) asm("func_00295d28");
void func_00295d28(void)
{
    s32 i = 0;
    s32 cnt = 0;
    u8* base = func_002766d0();
    s32 n = func_0028afa8(D_0035f200);
    for (; i < n; i++) {
        s32 c = 0;
        s32 b = 0;
        s32 a = 0;
        s32 r;
        switch (i) {
        case 0:
            r = Tz__JmDiagram__GetNewInfo(0, -1);
            if (r) { a = 1; b = r == 2; }
            c = func_002ae1b0(0, *func_00276568());
            break;
        default:
            break;
        case 1:
            a = Tz__JmNewInfo__isStoryNew(*func_00276568(), -1);
            b = func_002ac110(*func_00276568(), -1);
            c = func_002ae0c0(*func_00276568());
            break;
        case 2:
            a = func_002aa668(*func_00276568(), -1);
            b = func_002aa788(*func_00276568(), -1);
            c = Tz__JmComplete__isAlbumComp(*func_00276568());
            break;
        case 3:
            if (func_002a4380(*func_00276568())) continue;
            a = Tz__JmNewInfo__isTreasureNew(*func_00276568());
            b = func_002ab620(*func_00276568());
            c = Tz__JmComplete__isTreasureComp(*func_00276568());
            break;
        case 4:
            if (!Tz__JmPuzzle__isEnable() && !func_00276c18()) continue;
            a = Tz__JmNewInfo__isPuzzleInfoNew(*func_00276568());
            b = func_002ac800(*func_00276568());
            c = func_002ae890(*func_00276568());
            break;
        case 5:
            a = Tz__JmNewInfo__isNaviNew(*func_00276568());
            b = func_002ab9c8(*func_00276568());
            c = Tz__JmComplete__isNaviComp(*func_00276568());
            break;
        case 6:
            if (!Tz__JmQuest__isEnable(*func_00276568())) continue;
            a = func_002aae88(*func_00276568());
            b = func_002aaf40(*func_00276568());
            c = func_002ad7d0(*func_00276568());
            break;
        case 7:
            if (!Tz__JmMiniGame__isEnable(*func_00276568())) continue;
            a = func_002ab2b0(*func_00276568());
            b = func_002ab368(*func_00276568());
            c = func_002ad950(*func_00276568());
            break;
        case 8:
            r = Tz__JmDiagram__GetNewInfo(1, -1);
            if (r) { a = 1; b = r == 2; }
            c = func_002ae1b0(1, 16);
            break;
        }
        u8* o = func_002891b8(D_0035f200, cnt);
        *(s32*)(o + 0x198) = func_00192048(D_00374758[i]);
        if (a) { s32 v; if (b) v = D_00374754; else v = D_00374750; func_00138c10(base + cnt * 408 + 0xa998, v); }
        if (c) func_00138c10(base + cnt * 408 + 0x7698, 160);
        cnt++;
    }
    Tz__Select__SetSelectMax(D_0035f200, cnt);
}
}  // namespace n00295d28

// 002960d0 (was src/anon/batch_w1772_g.cpp)
namespace n002960d0 {
u8* GetSeqTbl_w1772(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
s8* GetMenuInfo_w1772(void) asm("_ZN2Tz6Jiminy11GetMenuInfoEv");
void func_00294288(s32, s32*, s32*) asm("func_00294288");
s32 tail4_w1772(s32) asm("_Z16u_tail4_00192048jjjj");
/*TARGET 002960d0*/
void func_002960d0(void) asm("func_002960d0");
void func_002960d0(void) {
    u8* s = GetSeqTbl_w1772();
    s8* q = GetMenuInfo_w1772();
    u8* a = s + 1632;
    u8* b = s + 2068;
    u8* c = s + 2504;
    u8* d = s + 2940;
    s32 x, y;
    func_00294288(*q, &x, &y);
    *(s32*)(a + 408) = tail4_w1772(x);
    *(s32*)(b + 408) = tail4_w1772(12883);
    *(s32*)(c + 408) = tail4_w1772(y);
    *(s32*)(d + 408) = tail4_w1772(12884);
}
}  // namespace n002960d0

// 00296168 (was src/anon/batch_w3692_g.cpp)
namespace n00296168 {
extern s32 D_0035f200 asm("D_0035f200");
extern u8 D_00296f28[] asm("D_00296f28");
extern u16 D_00374758[] asm("D_00374758");
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00287bc0() asm("func_00287bc0");
s32 func_00276368() asm("func_00276368");
s32 func_0028acc8(s32) asm("func_0028acc8");
s32 func_00276888() asm("func_00276888");
void func_00287f90(s32) asm("func_00287f90");
void func_00295868() asm("func_00295868");
s32 func_00292630() asm("func_00292630");
void func_00287c30() asm("func_00287c30");
void Tz__Jiminy__LoadData(s32) asm("Tz__Jiminy__LoadData");
void func_002925c0() asm("func_002925c0");
s32 func_00276358() asm("func_00276358");
void Tz__Jiminy__SetParentSeqNum(s32, s32) asm("Tz__Jiminy__SetParentSeqNum");
void Tz__JmWorldSel__Setup() asm("Tz__JmWorldSel__Setup");
void func_002995e8() asm("func_002995e8");
void func_00297050() asm("func_00297050");
void func_00297e68() asm("func_00297e68");
void Tz__JmTreasure__Setup() asm("Tz__JmTreasure__Setup");
void Tz__JmTreasure__SetupPieceInfo() asm("Tz__JmTreasure__SetupPieceInfo");
void func_002a0908(s32) asm("func_002a0908");
void Tz__JmMiniGame__Setup() asm("Tz__JmMiniGame__Setup");
void Tz__JmQuest__Setup() asm("Tz__JmQuest__Setup");
void func_00296b08() asm("func_00296b08");
s32 func_00289310(s32) asm("func_00289310");
s32 func_00276398() asm("func_00276398");
void func_00275b60() asm("func_00275b60");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, void*, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00287da0() asm("func_00287da0");
s32 func_00288040() asm("func_00288040");
void func_00288018() asm("func_00288018");
void func_00276150(s32, s32*, s32*) asm("func_00276150");
void Tz__Jiminy__FadeOutHelp() asm("Tz__Jiminy__FadeOutHelp");
void func_00287c00(s32) asm("func_00287c00");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00296da8(s32) asm("func_00296da8");
void func_0028fb28(s32, u16) asm("func_0028fb28");
void func_00275dd0() asm("func_00275dd0");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
/*TARGET 00296168*/
// 0x00265018: definition moved into src/anon/unit_00264be0.cpp

void func_00296168(void) asm("func_00296168");
// 0x00265018: definition moved into src/anon/unit_00264be0.cpp

void func_00296168(void) {
    s32 r = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    s32 m = func_00287bc0();
    if (st == 2) {
        if (func_00276368() != 0 || func_0028acc8(D_0035f200) != 0 || func_00276888() != 0) {
            if (r != -1) {
                func_00287f90(0);
                func_00295868();
            }
            return;
        }
        if (func_00292630() != 0) return;
        func_00295868();
        func_00287c30();
        {
            /* sched2 tie: gcc puts li a1 in the jal delay slot; the original keeps m's copy there. */
            register s32 t asm("$2") = func_00287bc0();
            s32 g = D_0035f200;
            register s32 a0 asm("$4") = g;
            register s32 a1 asm("$5") = 0x73;
            asm volatile(".set noreorder\n\tjal func_0028af18\n\tmove %0,%1\n\t.set reorder"
                         : "=r"(m) : "r"(t), "r"(a0), "r"(a1)
                         : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13",
                           "$14", "$15", "$24", "$25", "$31", "hi", "lo", "memory");
        }
        Tz__Jiminy__LoadData(m);
        func_002925c0();
        Tz__Jiminy__SetParentSeqNum(func_00276358(), 0);
        if (m == 0) {
            Tz__JmWorldSel__Setup();
        } else if (m == 13) {
            func_002995e8();
        } else if (m == 3) {
            func_00297050();
        } else if (m == 4) {
            func_00297e68();
        } else if (m == 7 || m == 9) {
            Tz__JmTreasure__Setup();
        } else if (m == 8) {
            Tz__JmTreasure__SetupPieceInfo();
        } else if (m == 6 || m == 12) {
            func_002a0908(-1);
        } else if (m == 11) {
            Tz__JmMiniGame__Setup();
        } else if (m == 10) {
            Tz__JmQuest__Setup();
        }
        return;
    }
    func_00296b08();
    if ((r != -1 || func_00289310(D_0035f200) != 0) && func_00276398() == 0) {
        Tz__Jiminy__SetParentSeqNum(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398() != 0) {
        func_00287c90(1);
    }
    if (func_00242848(func_00287df0(r, func_00289310(D_0035f200), 1, D_00296f28, 1)) == 0) {
        s32 x;
        s32 a;
        s32 b0, b1;
        switch (r) {
        case -4:
            func_00287da0();
            break;
        case -1:
            break;
        case -9:
        case -8:
            func_00276150(m, &b0, &b1);
            if (r == -8) {
                x = b1;
                a = 0;
            } else {
                x = b0;
                a = 1;
            }
            Tz__Jiminy__SetParentSeqNum(a, 1);
            Tz__Jiminy__FadeOutHelp();
            func_00287c00(x);
            func_00287cc0(2);
            break;
        default: {
            s32 v = func_00296da8(r);
            Tz__Jiminy__SetParentSeqNum(0, 1);
            func_0028fb28(0, D_00374758[v]);
            s32 k;
            switch (v) {
            case 0: k = 6; break;
            case 1: k = 3; break;
            case 2: k = 4; break;
            case 3: k = 7; break;
            case 4: k = 8; break;
            case 5: k = 9; break;
            case 6: k = 10; break;
            case 7: k = 11; break;
            case 8:
            default: k = 12; break;
            }
            func_00287c00(k);
            func_00275dd0();
            Tz__Jiminy__FadeOutHelp();
            func_00287cc0(2);
            func_002765e8(m, r, 0);
            break;
        }
        case -2:
            Tz__Jiminy__SetParentSeqNum(1, 1);
            Tz__Jiminy__FadeOutHelp();
            func_00287c00(0);
            func_00287cc0(2);
            break;
        }
    }
    if (func_00288040() != 0) {
        func_00288018();
    }
}
}  // namespace n00296168

// 00296588 (was src/anon/batch_w3815_g.cpp)
namespace n00296588 {
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f200 asm("D_0035f200");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f3d4 asm("D_0035f3d4");
void func_001395f8(u8*) asm("func_001395f8");
void func_00139620(u8*) asm("func_00139620");
u8* func_00276348() asm("func_00276348");
void func_00276690(s32) asm("func_00276690");
u8* func_002766d0() asm("func_002766d0");
void func_00287cc0(s32) asm("func_00287cc0");
void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("Tz__Select__SetItem");
void func_00288e88(s32) asm("func_00288e88");
u8* func_002891b8(s32, s32) asm("func_002891b8");
void func_0028af28(s32, s32) asm("func_0028af28");
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_002960d0() asm("func_002960d0");
void func_002969e0() asm("func_002969e0");
void Tz__JmReport__CreateGra(s32) asm("Tz__JmReport__CreateGra");
struct Sub { u8 pad[0xb8]; u32 fl; };
/*TARGET 00296588*/
void func_00296588(void) asm("func_00296588");
void func_00296588(void)
{
    u8 *cam, *w; s32 base, id; u8 *cur, *par, *par2; Sub* s;
    s16 tab[4];
    // One s0 variable: first the second 816-byte item, then the constant 1 stored to the 0x195 flags.
    register u32 one asm("$16");
    cam = func_00276348();
    w = func_002766d0();
    func_00288e88(D_0035f200);
    func_002969e0();
    for (s32 i = 0; i < 4; i++) tab[i] = 3;
    base = D_0035f3d4;
    id = base - 1;
    func_0028d8c0(w, id, D_0035f14c, D_0035f148, D_0035f210, 163, -1, 0);
    one = (u32)w + 0x330; asm("" : "+r"(one));
    func_00139620(w);
    func_0028dcc0(w, cam);
    func_0028d8c0((u8*)one, id, D_0035f14c, D_0035f148, D_0035f210, 166, -1, 0);
    id = base + 3;
    func_00139620((u8*)one);
    func_0028dcc0((u8*)one, cam);
    one = 1;
    cur = w + 0x660;
    func_0028d980(cur, id, D_0035f14c, D_0035f148, D_0035f210, 170, -1, -1, 0);
    func_001395f8(cur);
    func_0028dcc0(cur, cam);
    par = cur;
    cur = w + 0x814;
    s = (Sub*)(w + 0x678); s->fl |= 8;
    par[0x195] = one;
    func_0028d980(cur, id, D_0035f14c, D_0035f148, D_0035f210, 3, -1, -1, 0);
    func_00139620(cur);
    func_0028dcc0(cur, par);
    *(s32*)(cur + 0x1B0) = 2;
    s = (Sub*)(w + 0x82C); s->fl |= 8;
    cur[0x195] = one;
    cur = w + 0x9C8;
    func_0028d980(cur, id, D_0035f14c, D_0035f148, D_0035f210, 171, -1, -1, 0);
    func_001395f8(cur);
    func_0028dcc0(cur, cam);
    par2 = cur;
    cur = w + 0xB7C;
    s = (Sub*)(w + 0x9E0); s->fl |= 8;
    par2[0x195] = one;
    func_0028d980(cur, id, D_0035f14c, D_0035f148, D_0035f210, 3, -1, -1, 0);
    func_00139620(cur);
    func_0028dcc0(cur, par2);
    *(s32*)(cur + 0x1B0) = 2;
    s = (Sub*)(w + 0xB94); s->fl |= 8;
    cur[0x195] = one;
    Tz__Select__SetItem(D_0035f200, 0, D_0035f14c, D_0035f148, D_0035f210, -1, tab, tab);
    func_00139620(func_002891b8(D_0035f200, 0));
    func_0028dcc0(func_002891b8(D_0035f200, 0), w);
    Tz__JmReport__CreateGra(0);
    func_002960d0();
    func_00276690(1);
    func_0028af28(D_0035f200, 16);
    func_00287cc0(0);
}
}  // namespace n00296588

// 002968d8 (was src/anon/batch_w95.cpp)
namespace n002968d8 {
extern u32 D_0035f200 asm("D_0035f200");
s32 func_00289380(u32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
void func_00296b08(void) asm("func_00296b08");
s32 func_00289310(u32) asm("func_00289310");
s32 func_00276398(void) asm("func_00276398");
// state_is_150
void Tz__Jiminy__SetParentSeqNum(u32, u32) asm("Tz__Jiminy__SetParentSeqNum");
void func_00287c90(u32) asm("func_00287c90");
u32 func_00287df0(s32, s32, u32, u32, u32) asm("func_00287df0");
s32 func_00242848(u32) asm("func_00242848");
void func_00287da0(void) asm("func_00287da0");
/*TARGET 002968d8*/
void Tz__JmReport__ControlRoxas(void) asm("Tz__JmReport__ControlRoxas");
void Tz__JmReport__ControlRoxas(void) {
    s32 sel = func_00289380(D_0035f200);
    s32 busy = func_00287cd0();
    func_00296b08();
    if (sel != -1 || func_00289310(D_0035f200)) {
        if (!func_00276398()) Tz__Jiminy__SetParentSeqNum(0, 2);  // state_is_150
    }
    if (!busy && func_00276398()) func_00287c90(1);  // state_is_150
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f200), 1, 0, 1))) return;
    switch (sel) {
    case -4:
    case -2:
        func_00287da0();
        break;
    case -1:
        break;
    }
}
}  // namespace n002968d8

// 002969e0 (was src/anon/batch_w77.cpp)
namespace n002969e0 {
extern u32 D_0035f58c asm("D_0035f58c");
extern u8 D_0035f590 asm("D_0035f590");
void func_0023f900(u32) asm("func_0023f900");
s32 func_00292630(void) asm("func_00292630");
s8* func_00276568(void) asm("func_00276568");
s32 func_00287bc0(void) asm("func_00287bc0");
u32 Tz__JmWorldSel__GetId2Info(s32) asm("Tz__JmWorldSel__GetId2Info");
s32 func_002941d8(u32) asm("func_002941d8");
u32 func_00296f90(void) asm("func_00296f90");
// get_global_36f598
u32 func_00296f80(void) asm("func_00296f80");
// get_global_36f594
u32 func_00293db8(s32, u32) asm("func_00293db8");
void func_0023fa08(u32, u32) asm("func_0023fa08");
/*TARGET 002969e0*/
void func_002969e0(void) asm("func_002969e0");
void func_002969e0(void)
{
    func_0023f900(D_0035f58c);
    if (!func_00292630()) {
        s8 c = *func_00276568();
        u32 v;
        if (func_00287bc0() == 2) {
            if (c == 1 && func_002941d8(Tz__JmWorldSel__GetId2Info(1))) v = func_00296f90();
            else v = Tz__JmWorldSel__GetId2Info(c) + 1;
        } else {
            v = func_00296f80();  // get_global_36f594
        }
        func_0023fa08(D_0035f58c, func_00293db8(2, v));
        D_0035f590 = 1;
    } else {
        D_0035f590 = 0;
    }
}
}  // namespace n002969e0

// 00296ab0 (was src/anon/auto80_199_queue.cpp)
namespace n00296ab0 {
/*TARGET 00296ab0*/
void Tz__JmReport__LeaveAll(void) asm("_Z22Tz__JmReport__LeaveAllv");
void Tz__JmReport__LeaveAll(void) {
    if (D_0035f590 != 0) {
        if (func_0023f900(D_0035f58c) != 0) {
            func_0023fad0(D_0035f58c);
        }
    }
    func_00293d80(5101);
    D_0035f590 = 0;
}
}  // namespace n00296ab0

// 00296b08 (was src/anon/batch_w42.cpp)
namespace n00296b08 {
// 00296b08
extern u8 D_0035f590 asm("D_0035f590");
extern u8 D_0035f591 asm("D_0035f591");
void func_002969e0(void) asm("func_002969e0");
void Tz__JmReport__CreateGra(s32) asm("Tz__JmReport__CreateGra");
/*TARGET 00296b08*/
void func_00296b08(void) asm("func_00296b08");
void func_00296b08(void)
{
    if (!(D_0035f590 && D_0035f591)) {
        if (!D_0035f590) func_002969e0();
        if (D_0035f590 && !D_0035f591) Tz__JmReport__CreateGra(1);
    }
}
}  // namespace n00296b08

// 00296b80 (was src/anon/batch_w3717.cpp)
namespace n00296b80 {
u8* func_002766d0(void) asm("func_002766d0");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
s32 func_0023f1b0(s32) asm("func_0023f1b0");
s32 func_0023c4b8(s32, s32) asm("func_0023c4b8");
s32 func_0023f988(s32, s32) asm("func_0023f988");
void YI__IMAGE__Init(u8*, s32) asm("YI__IMAGE__Init");
void dk__Sprite__create(u8*, s32, s32, u8*, s32, s32) asm("dk__Sprite__create");
void func_00139620(u8*) asm("func_00139620");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
extern u8 D_0035f590 asm("D_0035f590");
extern u8 D_0035f591 asm("D_0035f591");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f58c asm("D_0035f58c");
extern s32 D_0037473c asm("D_0037473c");
extern s32 D_00374740 asm("D_00374740");
extern s32 D_00374744 asm("D_00374744");
extern s32 D_00374748 asm("D_00374748");
extern s32 D_0037474c asm("D_0037474c");
/*TARGET 00296b80*/
// Sets up the two party-member panels (i = 0, 1) once, then marks D_0035f591.
// Register pins (p in s7, d in t7, the constant 1 in t6) and the empty asms reproduce the
// original's register choice and scheduling; the else arm reads D_00374738 through a hidden
// high half (0x370000 + 0x4738) so its lui is issued before id = d + 1.
void Tz__JmReport__CreateGra(u8 flag) asm("Tz__JmReport__CreateGra");
// Sets up the two party-member panels (i = 0, 1) once, then marks D_0035f591.
// Register pins (p in s7, d in t7, the constant 1 in t6) and the empty asms reproduce the
// original's register choice and scheduling; the else arm reads D_00374738 through a hidden
// high half (0x370000 + 0x4738) so its lui is issued before id = d + 1.
void Tz__JmReport__CreateGra(u8 flag) {
    u8* w = func_002766d0();
    if (D_0035f590 == 0) return;
    if (D_0035f591 != 0) return;
    u8* q0 = w + 0x18;
    s32 i = 0;
    s32 a = func_0023aa18(q0);
    register u8* p asm("$23") = w + 0x4398;
    s32 b = func_0023aa38(q0);
    do {
        register s32 d asm("$15") = D_0035f3d4;
        s32 id = d;
        id += 2;
        s32 m;
        if (i == 0) { m = D_0037473c; }
        else {
            u32 hb = 0x370000;  // &D_00374738 high half
            asm volatile("" : "+r"(hb));
            id = d + 1;
            asm volatile("");
            m = *(s32*)(hb + 0x4738);
        }
        s32 c = func_0023c4b8(func_0023f1b0(D_0035f210), m);
        s32 e = func_0023f988(D_0035f58c, i);
        u8* q = w + i * 0x1a0 + 0xdca0;
        YI__IMAGE__Init(q, e);
        register u8 one asm("$14") = 1;
        q[0x190] = one;
        s32 x, y;
        if (flag) {
            x = i == 0 ? D_00374748 : D_00374740;
            y = i == 0 ? D_0037474c : D_00374744;
        } else {
            x = i == 0 ? D_0037474c : D_00374744;
            y = -1;
        }
        u8* ob = w + i * 0x198;
        u8* o = ob + 0x4398;
        u8* o2 = ob + 0x43b0;
        dk__Sprite__create(o, id, c, w + i * 0x1a0 + 0xdca0, x, 0);
        *(s32*)(o + 0x188) = y;
        func_00139620(o);
        *(u32*)(o2 + 0xb8) |= 8;
        o[0x195] = 1;
        if (i == 0) {
            func_0028dcc0(p, w);
            func_00138c68(p, a, b);
        } else {
            func_0028dcc0(o, w + 0x330);
        }
        i++;
    } while (i < 2);
    D_0035f591 = 1;
}
}  // namespace n00296b80

// 00296da8 (was src/anon/batch_w76.cpp)
namespace n00296da8 {
// 0028de08: moved to src/anon/unit_0028c878.cpp

s8* func_00276568(void) asm("func_00276568");
s32 func_002a4380(s8) asm("func_002a4380");
s32 Tz__JmPuzzle__isEnable(void) asm("Tz__JmPuzzle__isEnable");
s32 Tz__JmQuest__isEnable(s8) asm("Tz__JmQuest__isEnable");
s32 Tz__JmMiniGame__isEnable(s8) asm("Tz__JmMiniGame__isEnable");
s32 JmReport_GetIndex(u32 idx) asm("_ZN2Tz8JmReport8GetIndexEj");
/*TARGET 00296da8*/
s32 JmReport_GetIndex(u32 idx) asm("_ZN2Tz8JmReport8GetIndexEj");
s32 JmReport_GetIndex(u32 idx)
{
    s32 list[9];
    s32* p = list;
    for (s32 i = 0; i < 9; i++) {
        if (i == 3 && func_002a4380(*func_00276568())) continue;
        if (i == 4 && !Tz__JmPuzzle__isEnable()) continue;
        if (i == 6 && !Tz__JmQuest__isEnable(*func_00276568())) continue;
        if (i == 7 && !Tz__JmMiniGame__isEnable(*func_00276568())) continue;
        *p++ = i;
    }
    return list[idx];
}
}  // namespace n00296da8

// 00296ea8 (was src/tozawa/cmenu_jiminy.cpp)
namespace Tz { // method 00296ea8
u32 func_00289310() asm("_ZN2Tz6Select12isCursorMoveEv");
void func_00296ed0() asm("_ZN2Tz8JmReport10DrawUpdateEPNS_6SelectEii");
/*TARGET 00296ea8*/
void Jiminy::DrawSelector(Select*, s32, s32) {
    if (func_00289310() != 0u) {
        func_00296ed0();
    }
}
}  // Tz

// 00296ed0 (was src/tozawa/jm_report.cpp)
namespace Tz { // method 00296ed0
extern u16 D_00374770[] asm("D_00374770");
extern u32 D_0035f200 asm("D_0035f200");
/*TARGET 00296ed0*/
void JmReport::DrawUpdate(Select*, s32, s32) {
    u32 a0 = 0;
    u32 v0 = (u32)MenuBase::GetMode();
    if (v0 == 1) {
        goto special;
    }
    v0 = GetData(D_0035f200);
    v0 = GetIndex(v0);
    v0 <<= 1;
    v0 = (u32)(((u8*)D_00374770) + v0);
    a0 = *(u16*)v0;
    goto call;
special:
    a0 = 18751;
call:
    DrawMessage(a0, 0);
}
}  // Tz

// 00296f28 (gap: report draw-update callback)
namespace g00296f28 {
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00276150(s32, s32*, s32*) asm("func_00276150");
u32 func_00296da8(s32) asm("func_00296da8");
s32 cb(s32 a0) asm("D_00296f28");
s32 cb(s32 a0) {
    s32 x, y;
    s32 r = func_00287bc0();
    if ((u32)(a0 + 9) < 2) {
        func_00276150(r, &x, &y);
        return 1;
    }
    return func_00296da8(a0) < 9;
}
}  // namespace g00296f28

// 00296f80 (was src/anon/tiny.cpp)
namespace n00296f80 {
/*TARGET 00296f80*/
u32 func_00296f80(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00296f80jjjj");
u32 func_00296f80(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_36f594
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u32*)((u32)b + (-2684)));
}
}  // namespace n00296f80

// 00296f90 (was src/anon/tiny.cpp)
namespace n00296f90 {
/*TARGET 00296f90*/
u32 func_00296f90(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00296f90jjjj");
u32 func_00296f90(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_36f598
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u32*)((u32)b + (-2680)));
}
}  // namespace n00296f90

// 00296fa0 (was src/tozawa/jm_story.cpp)
namespace Tz { // method 00296fa0
u32 LoadDataGetSystem() asm("_ZN2Tz17LoadDataGetSystemEv");
u32 LoadDataAlloc(u32, u32) asm("_ZN2Tz13LoadDataAllocEjj");
extern u32 D_0035f594 asm("D_0035f594");
/*TARGET 00296fa0*/
u32 JmStory::Init() {
    u32 r2 = LoadDataGetSystem();
    r2 = LoadDataAlloc(520, r2);
    D_0035f594 = r2;
    return r2;
}
}  // Tz

// 00296fd0 (was src/anon/tiny_auto80_queue.cpp)
namespace n00296fd0 {
u32 func_00106420(...) asm("func_00106420");
/*TARGET 00296fd0*/
void func_00296fd0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00296fd0jjjjjjjj");
void func_00296fd0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = (u32)(0x0036u << 16);
    r15 = *(volatile u32*)((u32)r16 + (s32)(-2668));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00106420)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(volatile u32*)((u32)r16 + (s32)(-2668)) = 0u;
    }
}
}  // namespace n00296fd0

// 00297008 (was src/anon/misc_2.cpp)
namespace n00297008 {
/*TARGET 00297008*/
void func_00297008(void* self) asm("_Z13func_00297008Pv");
void func_00297008(void* self) {}
}  // namespace n00297008

// 00297010 (was src/tozawa/jm_story.cpp)
namespace Tz { // method 00297010
void func_00274ac8() asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
/*TARGET 00297010*/
void JmStory::LeaveAll() {
    if (MenuBase::GetMode() == 3) {
        func_00274ac8();
        LeaveAllPost(0);
    }
}
}  // Tz

// 00297050 (was src/anon/batch_w1614.cpp)
namespace n00297050 {
// 0x00260418: definition moved into src/anon/unit_0025f6b8.cpp
struct LE8 { s16 a; s16 b; s16 c; s16 x; };
struct LL8 { s16 n; s16 pad[3]; LE8 e[1]; };
extern LL8* D_0035f594 asm("D_0035f594");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f200 asm("D_0035f200");
extern s32 D_0035f214 asm("D_0035f214");
struct W436 { u8 pad[420]; u32 f420; u8 pad2[12]; void (*f436)(void); };
void* func_00276348(void) asm("func_00276348");
u8* func_002766d0(void) asm("func_002766d0");
void func_00276690(s32) asm("func_00276690");
void func_00288e88(s32) asm("func_00288e88");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void Tz__Jiminy__CreateCover(void) asm("Tz__Jiminy__CreateCover");
void func_0028d8c0_m7050(u8*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_00139620_m7050(void*) asm("func_00139620");
void func_0028dcc0_m7050(void*, void*) asm("func_0028dcc0");
void func_00288d80_m7050(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("Tz__Select__SetItem");
W436* func_002891b8_m7050(s32, s32) asm("func_002891b8");
void func_002978f0(void) asm("func_002978f0");
void func_001395f8_m7050(void*) asm("func_001395f8");
s32 func_0023aa78(u8*) asm("func_0023aa78");
void func_00138c68_m7050(u8*, s32, s32) asm("func_00138c68");
void func_00297478(void) asm("func_00297478");
void Tz__Select__SetSelectMax(s32, s32) asm("Tz__Select__SetSelectMax");
void func_002891f0_m7050(s32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_0028afd0(s32, s32) asm("func_0028afd0");
void* func_0023f1b0(s32) asm("func_0023f1b0");
s32 func_0023c4b8(void*, s32) asm("func_0023c4b8");
s32 func_00236ca8(s32, s32) asm("func_00236ca8");
s32 func_00276678(void) asm("func_00276678");
void func_0028bae0(s32, s32, s32, s32, s32, s32, s32, u8*, s32) asm("func_0028bae0");
void Tz__ScrollBar__SetPos(s32, s32) asm("Tz__ScrollBar__SetPos");
void func_0028af28(s32, s32) asm("func_0028af28");
void Tz__Select__SetPageMode(s32, s32) asm("Tz__Select__SetPageMode");
void func_0028b248(s32, s32) asm("func_0028b248");
void func_0028b1e8_m7050(s32, s32) asm("func_0028b1e8");
void Tz__JmStory__UpdateNewMark(void) asm("Tz__JmStory__UpdateNewMark");
void func_002978d0(void) asm("func_002978d0");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 00297050*/
void func_00297050(void) asm("func_00297050");
void func_00297050(void)
{
    s16 c[2][4];
    s32 i;
    s32 j;
    s32 y;
    void* o = func_00276348();
    u8* w = func_002766d0();
    func_00276690(1);
    func_00288e88(D_0035f200);
    func_0028f4d8(0, -1, 0);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) c[i][j] = 2;
    }
    s32 m = D_0035f3d4 - 1;
    u8* w2 = w + 1224;
    y = 0;
    Tz__Jiminy__CreateCover();
    func_0028d8c0_m7050(w, m, D_0035f14c, D_0035f148, D_0035f210, 96, -1, 0);
    func_00139620_m7050(w);
    func_0028dcc0_m7050(w, o);
    func_0028d8c0_m7050(w2, m, D_0035f14c, D_0035f148, D_0035f210, 100, -1, 0);
    func_00139620_m7050(w2);
    func_0028dcc0_m7050(w2, o);
    func_00288d80_m7050(D_0035f200, 0, D_0035f14c, D_0035f148, D_0035f210, -1, c[0], c[1]);
    func_00139620_m7050(func_002891b8_m7050(D_0035f200, 0));
    func_0028dcc0_m7050(func_002891b8_m7050(D_0035f200, 0), w);
    *(u32*)&func_002891b8_m7050(D_0035f200, 0)->f436 = (u32)func_002978f0;
    *(u32*)&func_002891b8_m7050(D_0035f200, 0)->f420 = 0x60000008;
    func_001395f8_m7050(func_002891b8_m7050(D_0035f200, 0));
    m = D_0035f3d4;
    s32 h = func_0023aa78(w + 24);
    for (i = 0; i < 10; i++) {
        u8* p = w + 0xa998 + i * 408;
        func_0028d8c0_m7050(p, m + 1, D_0035f14c, D_0035f148, D_0035f210, 2, -1, 0);
        func_0028dcc0_m7050(p, w);
        func_00138c68_m7050(p, 0, y);
        y += h;
    }
    func_00297478();
    s32 tot = 0;
    for (i = 0; i < D_0035f594->n - 1; i++) tot += D_0035f594->e[i].x;
    s32 sum = tot;
    s32 last = D_0035f594->e[D_0035f594->n - 1].x;
    tot = sum + 1;
    if (last > 10) { s32 ex = last - 10; tot += ex; }
    Tz__Select__SetSelectMax(D_0035f200, tot);
    func_002891f0_m7050(D_0035f200, 0, 0, -1, -1);
    func_0028afd0(D_0035f200, sum);
    s32 r1 = func_0023c4b8(func_0023f1b0(D_0035f210), D_0035f14c);
    s32 r2 = func_00236ca8(*(s32*)((u8*)func_0023f1b0(D_0035f210) + 40), D_0035f148);
    s32 last2 = D_0035f594->e[D_0035f594->n - 1].x;
    m = D_0035f3d4;
    s32 v = sum + 10;
    if (last2 >= 10) v = sum + last2;
    func_0028bae0(D_0035f214, m, r1, r2, func_00276678(), v, 10, w2, 0);
    Tz__ScrollBar__SetPos(D_0035f214, sum);
    func_0028af28(D_0035f200, 16);
    Tz__Select__SetPageMode(D_0035f200, 1);
    func_0028b248(D_0035f200, 10);
    func_0028b1e8_m7050(D_0035f200, 0);
    Tz__JmStory__UpdateNewMark();
    func_002978d0();
    func_00287cc0(0);
}
}  // namespace n00297050

// 00297478 (was src/anon/batch_w3760_nsa.cpp)
namespace n00297478 {
struct Ent { u16 id; s16 idx; s16 mul; s16 val; };
struct Hdr { s16 n; u16 m; s16 z; s16 pad; Ent e[64]; };
struct Src { s8 k; u8 pad[7]; u16 id; u16 pad2; };
struct SrcList { u8 pad[8]; s32 n; u8 pad2[4]; Src s[1]; };
struct Lim { u8 pad[0x14]; s32 v; };
extern Hdr* D_0035f594 asm("D_0035f594");
s32 func_002766d0(void) asm("func_002766d0");
SrcList* func_00294000(s32) asm("func_00294000");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
s8* func_00276568(void) asm("func_00276568");
s32 func_00294268(Src*) asm("func_00294268");
u16 func_0023aa78(s32) asm("func_0023aa78");
s32 func_0023aa58(s32) asm("func_0023aa58");
Lim* func_001aae68(s32) asm("func_001aae68");
s32 func_00192048(u16) asm("func_00192048");
s16 func_00192b80(s32) asm("func_00192b80");
/*TARGET 00297478*/
void func_00297478(void) asm("func_00297478");
void func_00297478(void) {
    s32 base = func_002766d0();
    SrcList* l = func_00294000(1);
    Src* s = l->s;
    s32 cnt = 0;
    s32 i = 0;
    func_002fde18(D_0035f594, 0, 0x208);
    for (; i < l->n; i++) {
        s8 c = *func_00276568();
        if (s[i].k == c && func_00294268(&s[i])) {
            D_0035f594->e[cnt].id = s[i].id;
            D_0035f594->e[cnt].idx = i;
            cnt++;
        }
    }
    D_0035f594->n = cnt;
    u16 m = func_0023aa78(base + 0x18);
    s32 d = 15;
    s32 t = func_0023aa58(base + 0x18);
    if (t != 0) d = t;
    Lim* lim = func_001aae68(3);
    D_0035f594->m = m;
    t = m - d - lim->v;
    if (t < 0) D_0035f594->m -= t;
    for (i = 0; i < D_0035f594->n; i++) {
        D_0035f594->e[i].val = func_00192b80(func_00192048(D_0035f594->e[i].id));
        D_0035f594->e[i].mul = (u16)D_0035f594->e[i].val * D_0035f594->m;
    }
    D_0035f594->z = 0;
}
}  // namespace n00297478

// 00297630 (was src/anon/batch_w109.cpp)
namespace n00297630 {
// 0x0027ff00: definition moved into src/anon/unit_0027f2b0.cpp

// ---- f14.cpp
extern s32 D_0035f200 asm("D_0035f200");
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00276368(void) asm("func_00276368");
s32 func_0028acc8(s32) asm("func_0028acc8");
s32 func_00276888(void) asm("func_00276888");
void func_00287f90(s32) asm("func_00287f90");
void func_00297010(void) asm("func_00297010");
s32 func_00292630(void) asm("func_00292630");
void func_00276690(s32) asm("func_00276690");
void func_00287c30(void) asm("func_00287c30");
void func_0028af18(s32, s32) asm("func_0028af18");
void func_0028b1e8(s32, s32) asm("func_0028b1e8");
void Tz__Jiminy__LoadData(s32) asm("Tz__Jiminy__LoadData");
// state_dispatch_0_1_2
void func_002925c0(void) asm("func_002925c0");
s32 func_00276358(void) asm("func_00276358");
void Tz__Jiminy__SetParentSeqNum(s32, s32) asm("Tz__Jiminy__SetParentSeqNum");
void Tz__JmReport__Setup(void) asm("Tz__JmReport__Setup");
s32 func_00289310(s32) asm("func_00289310");
s32 func_00276398(void) asm("func_00276398");
// state_is_150
void func_00275b60(void) asm("func_00275b60");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00287da0(void) asm("func_00287da0");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
// global_zero_4dwords
void Tz__SelHist__FadeOut(s32) asm("Tz__SelHist__FadeOut");
// record884_refresh_by_index
void func_00297008(void) asm("func_00297008");
void Tz__Jiminy__FadeOutHelp(void) asm("Tz__Jiminy__FadeOutHelp");
void func_00287c00(s32) asm("func_00287c00");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 00297630*/
void func_00297630(void) asm("func_00297630");
void func_00297630(void) {
    s32 a = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (a != -1) {
                func_00287f90(0);
                func_00297010();
            }
            return;
        }
        if (func_00292630()) return;
        func_00276690(0);
        func_00297010();
        func_00287c30();
        s32 b = func_00287bc0();
        func_0028af18(D_0035f200, 115);
        func_0028b1e8(D_0035f200, 1);
        Tz__Jiminy__LoadData(b);  // state_dispatch_0_1_2
        func_002925c0();
        Tz__Jiminy__SetParentSeqNum(func_00276358(), 0);
        if (b == st) Tz__JmReport__Setup();
        return;
    }
    if (a != -1 || func_00289310(D_0035f200)) {
        if (!func_00276398()) {  // state_is_150
            Tz__Jiminy__SetParentSeqNum(0, 2);
            func_00275b60();
        }
    }
    if (st == 0 && func_00276398()) func_00287c90(1);  // state_is_150
    if (!func_00242848(func_00287df0(a, func_00289310(D_0035f200), 1, 0, 1))) {
        switch (a) {
        case -4:
            func_00287da0();
            break;
        case -1:
            break;
        case -2:
            Tz__SelHist__FadeOut(0);  // record884_refresh_by_index
            func_00297008();
            Tz__Jiminy__FadeOutHelp();
            Tz__Jiminy__SetParentSeqNum(1, 1);
            func_00287c00(2);
            func_00287cc0(2);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n00297630

// 00297878 (gap: story select step)
namespace g00297878 {
extern s32 D_0035f214 asm("D_0035f214");
s32 func_00289310(s32) asm("func_00289310");
s32 func_0028b038(s32) asm("func_0028b038");
void Tz__ScrollBar__SetPos(s32, s32) asm("Tz__ScrollBar__SetPos");
void Tz__JmStory__UpdateNewMark(void) asm("Tz__JmStory__UpdateNewMark");
void func_00297878(s32 a0, u32 a1, s32 a2) asm("func_00297878");
void func_00297878(s32 a0, u32 a1, s32 a2) {
    if (func_00289310(a0)) {
        Tz__ScrollBar__SetPos(D_0035f214, func_0028b038(a0));
        Tz__JmStory__UpdateNewMark();
    }
}
}  // namespace g00297878

// 002978d0 (was src/anon/tiny_wrappers_more.cpp)
namespace n002978d0 {
u32 func_00276c50(u32, u32, u32, u32) asm("_Z13func_00276c50jjjj");
/*TARGET 002978d0*/
u32 func_002978d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002978d0jjjj");
u32 func_002978d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00276c50(0x000048d7u, 0x00000000u, a2, a3);
}
}  // namespace n002978d0


// 002978f0 (gap: story list draw)
namespace n002978f0 {

struct Ent { u16 id; s16 idx; s16 mul; s16 val; };
struct Hdr { s16 n; s16 m; s16 z; s16 pad; Ent e[64]; };
struct Rc { u8 pad[20]; s32 w; };
extern s32 D_0035f200 asm("D_0035f200");
extern u8* D_0035f224 asm("D_0035f224");
extern Hdr* D_0035f594 asm("D_0035f594");
u8* func_002766d0(void) asm("func_002766d0");
s32 func_0028b040(s32) asm("func_0028b040");
void func_0014b950(void*, s16, s16, u16, u16) asm("func_0014b950");
void func_0014b9a8(void*) asm("func_0014b9a8");
s32 func_0023aa58(void*) asm("func_0023aa58");
s32 func_0023aa78(void*) asm("func_0023aa78");
Rc* func_001aae68(s32) asm("func_001aae68");
s32 func_00192048(u16) asm("func_00192048");
void YS__MESSAGEDRAW__MESSAGEDRAW(void*, s32, s32, s32, s32) asm("YS__MESSAGEDRAW__MESSAGEDRAW");
void YS__MESSAGEDRAW__set_line_space(void*, s32) asm("YS__MESSAGEDRAW__set_line_space");
void YS__MESSAGEDRAW__draw(void*, s32, s32, s32) asm("YS__MESSAGEDRAW__draw");
void func_002978f0(s32 x, s32 y, s32 z) asm("func_002978f0");
void func_002978f0(s32 x, s32 y, s32 z) {
    u8 buf[96];
    s32 lo;
    s32 sel;
    s32 i;
    s32 zz = z;
    lo = 15;
    i = 0;
    u8* ent = func_002766d0() + 24;
    s32 v = func_0028b040(D_0035f200);
    s32 lim;
    s32 py;
    s32 b, acc, w;
    func_0014b950(D_0035f224 + 32, x, y, 512 - x, D_0035f594->m * 10);
    func_0014b9a8(D_0035f224 + 32);
    lim = y + D_0035f594->m * 10;
    py = y;
    sel = 0;
    acc = func_0023aa58(ent);
    b = func_0023aa78(ent);
    if (acc) lo = acc;
    acc = 0;
    for (; i < D_0035f594->n; i++) {
        if (v == acc || v < acc + D_0035f594->e[i].val) {
            py = py - (v - acc) * D_0035f594->m;
            sel = i;
            break;
        }
        acc += D_0035f594->e[i].val;
    }
    {
        Rc* r = func_001aae68(3);
        w = b - lo - r->w;
    }
    if (w < 0) w = 0;
    for (i = sel; i < D_0035f594->n; i++) {
        YS__MESSAGEDRAW__MESSAGEDRAW(buf, 3, func_00192048(D_0035f594->e[i].id), lo, 0);
        YS__MESSAGEDRAW__set_line_space(buf, w);
        YS__MESSAGEDRAW__draw(buf, x, py, zz);
        py += D_0035f594->e[i].mul;
        if (py >= lim) break;
    }
    func_0014b9a8(D_0035f224);
}
}  // namespace n002978f0
