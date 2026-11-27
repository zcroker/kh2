// Linked unit 0x00299920-0x0029af20 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include <stdarg.h>
#include "../tozawa/jm_album.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/jm_collection.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 00299920 (was src/anon/batch_w3862.cpp)
namespace n00299920 {
// 0x0025eee8: definition moved into src/anon/unit_0025da20.cpp

u8* func_002766d0(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
s32 sel_GetSelectMax(s32) asm("_ZN2Tz6Select12GetSelectMaxEv");
u8* func_002891b8(s32, s32) asm("func_002891b8");
s32 func_00192048(s32) asm("func_00192048");
void func_00138c10(u8*, s32) asm("func_00138c10");
void Tz__Select__SetSelectMax(s32, s32) asm("Tz__Select__SetSelectMax");
s32 jm_isFullOpen(void) asm("_ZN2Tz6Jiminy10isFullOpenEv");
s32 func_002a0360(void) asm("func_002a0360");
s32 func_002aa2f8(s32) asm("func_002aa2f8");
s32 func_002aa378(s32) asm("func_002aa378");
s32 func_002ad338(void) asm("func_002ad338");
s32 func_002aa098(s32) asm("func_002aa098");
s32 func_002aa148(s32) asm("func_002aa148");
s32 func_002ad1b0(s32) asm("func_002ad1b0");
s32 Tz__JmNewInfo__isTreasureNew(s32) asm("Tz__JmNewInfo__isTreasureNew");
s32 func_002ab620(s32) asm("func_002ab620");
s32 Tz__JmComplete__isTreasureComp(s32) asm("Tz__JmComplete__isTreasureComp");
s32 Tz__JmPuzzle__isEnable(void) asm("Tz__JmPuzzle__isEnable");
s32 Tz__JmNewInfo__isPuzzlePieceNew(s32) asm("Tz__JmNewInfo__isPuzzlePieceNew");
s32 Tz__JmNewInfo__isPuzzleInfoNew(s32) asm("Tz__JmNewInfo__isPuzzleInfoNew");
s32 func_002ac538(s32) asm("func_002ac538");
s32 func_002ac800(s32) asm("func_002ac800");
s32 Tz__JmComplete__isPuzzlePieceComp(s32) asm("Tz__JmComplete__isPuzzlePieceComp");
s32 Tz__JmComplete__isPuzzleGameComp(s32) asm("Tz__JmComplete__isPuzzleGameComp");
s32 jmc_isPuzzleInfoComp(s32) asm("_ZN2Tz10JmComplete16isPuzzleInfoCompEi");
s32 Tz__JmNewInfo__isNaviNew(s32) asm("Tz__JmNewInfo__isNaviNew");
s32 func_002ab9c8(s32) asm("func_002ab9c8");
s32 Tz__JmComplete__isNaviComp(s32) asm("Tz__JmComplete__isNaviComp");
s32 Tz__JmQuest__isEnable(s32) asm("Tz__JmQuest__isEnable");
s32 func_002aacd8(s32) asm("func_002aacd8");
s32 func_002aad58(s32) asm("func_002aad58");
s32 func_002ad7d0(s32) asm("func_002ad7d0");
s32 Tz__JmMiniGame__isEnable(s32) asm("Tz__JmMiniGame__isEnable");
s32 func_002ab100(s32) asm("func_002ab100");
s32 func_002ab180(s32) asm("func_002ab180");
s32 func_002ad950(s32) asm("func_002ad950");
s32 func_002a6500(void) asm("func_002a6500");
s32 func_002aaa38(s32) asm("func_002aaa38");
s32 func_002aaab8(s32) asm("func_002aaab8");
s32 func_002ad660(void) asm("func_002ad660");
s32 func_002a7530(void) asm("func_002a7530");
s32 func_002abc60(s32) asm("func_002abc60");
s32 func_002abce8(s32) asm("func_002abce8");
s32 func_002adf60(s32) asm("func_002adf60");
s32 Tz__JmDiagram__GetNewInfo(s32, s32) asm("Tz__JmDiagram__GetNewInfo");
s32 func_002ae1b0(s32, s32) asm("func_002ae1b0");
extern s32 D_0035f200 asm("D_0035f200");
extern s32 D_00374908 asm("D_00374908");
extern s32 D_0037490c asm("D_0037490c");
extern u16 D_00374910[] asm("D_00374910");
/*TARGET 00299920*/
// Jiminy's journal: fills the menu items with each category's new/complete marks.
void Tz__JmCollection__SetupSelMess(void) asm("Tz__JmCollection__SetupSelMess");
// Jiminy's journal: fills the menu items with each category's new/complete marks.
void Tz__JmCollection__SetupSelMess(void) {
    s32 i = 0;
    s32 n = 0;
    s32 j;
    u8* seq = func_002766d0();
    s32 max = sel_GetSelectMax(D_0035f200);
    for (; i < max; i++) {
        s32 show = 1;
        s32 c = 0;
        s32 b = 0;
        s32 a = 0;
        switch (i) {
        case 0:
            if (!func_002a0360()) {
                if (!jm_isFullOpen()) continue;
                show = 0;
            }
            a = func_002aa2f8(-1);
            b = func_002aa378(-1);
            c = func_002ad338();
            break;
        case 1:
            for (j = 0; j < 15; j++) {
                a = func_002aa098(j);
                if (a) goto found;
            }
            a = func_002aa098(16);
            if (a) {
            found:
                for (j = 0; j < 15; j++) {
                    b = func_002aa148(j);
                    if (!b) goto cpart;
                }
                b = func_002aa148(16);
            }
        cpart:
            for (j = 0; j < 15; j++) {
                c = func_002ad1b0(j);
                if (!c) goto done;
            }
            c = func_002ad1b0(16);
        done:
            break;
        case 2:
            a = func_002aa098(17);
            b = func_002aa148(17);
            c = func_002ad1b0(17);
            break;
        case 3:
            a = func_002aa098(18);
            b = func_002aa148(18);
            c = func_002ad1b0(18);
            break;
        case 4:
            a = Tz__JmNewInfo__isTreasureNew(-1);
            b = func_002ab620(-1);
            c = Tz__JmComplete__isTreasureComp(-1);
            break;
        case 5:
            if (!Tz__JmPuzzle__isEnable()) {
                if (!jm_isFullOpen()) continue;
                show = 0;
            }
            a = 0;
            if (Tz__JmNewInfo__isPuzzlePieceNew(-1) || Tz__JmNewInfo__isPuzzleInfoNew(-1)) a = 1;
            if (Tz__JmNewInfo__isPuzzlePieceNew(-1) && !Tz__JmNewInfo__isPuzzleInfoNew(-1)) {
                b = func_002ac538(-1);
            } else if (!Tz__JmNewInfo__isPuzzlePieceNew(-1) && Tz__JmNewInfo__isPuzzleInfoNew(-1)) {
                b = func_002ac800(-1);
            } else if (Tz__JmNewInfo__isPuzzlePieceNew(-1) && Tz__JmNewInfo__isPuzzleInfoNew(-1)) {
                b = 0;
                if (func_002ac538(-1) && func_002ac800(-1)) b = 1;
            } else {
                b = 0;
            }
            c = 0;
            if (Tz__JmComplete__isPuzzlePieceComp(-1) && Tz__JmComplete__isPuzzleGameComp(-1) && jmc_isPuzzleInfoComp(-1)) c = 1;
            break;
        case 6:
            a = Tz__JmNewInfo__isNaviNew(-1);
            b = func_002ab9c8(-1);
            c = Tz__JmComplete__isNaviComp(-1);
            break;
        case 7:
            if (!Tz__JmQuest__isEnable(-1)) {
                if (!jm_isFullOpen()) continue;
                show = 0;
            }
            a = func_002aacd8(-1);
            b = func_002aad58(-1);
            c = func_002ad7d0(-1);
            break;
        case 8:
            if (!Tz__JmMiniGame__isEnable(-1)) {
                if (!jm_isFullOpen()) continue;
                show = 0;
            }
            a = func_002ab100(-1);
            b = func_002ab180(-1);
            c = func_002ad950(-1);
            break;
        case 9:
            if (!func_002a6500()) {
                if (!jm_isFullOpen()) continue;
                show = 0;
            }
            a = func_002aaa38(-1);
            b = func_002aaab8(-1);
            c = func_002ad660();
            break;
        case 10:
            if (!func_002a7530()) {
                if (!jm_isFullOpen()) continue;
                show = 0;
            }
            {
                s32 x = func_002abc60(-1);  // temp: original sets a0 before copying a
                b = func_002abce8(-1);
                a = x;
            }
            c = func_002adf60(-1);
            break;
        case 11: {
            s32 r = Tz__JmDiagram__GetNewInfo(1, -1);
            if (r) {
                a = 1;
                b = r == 2;
            }
            c = func_002ae1b0(1, 16);
            break;
        }
        }
        u8* item = func_002891b8(D_0035f200, n);
        *(s32*)(item + 408) = func_00192048(D_00374910[i]);
        if (show && a) {
            s32 v = b ? D_0037490c : D_00374908;
            func_00138c10(seq + n * 408 + 0xa998, v);
        }
        if (show && c) {
            func_00138c10(seq + n * 408 + 30360, 156);
        }
        n++;
    }
    Tz__Select__SetSelectMax(D_0035f200, n);
}
}  // namespace n00299920

// 00299e70 (was src/anon/batch_w3731.cpp)
namespace n00299e70 {
extern s32 D_0035f200 asm("D_0035f200");
extern u16 D_00374910[] asm("D_00374910");
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00276368(void) asm("func_00276368");
s32 func_0028acc8(s32) asm("func_0028acc8");
s32 func_00276888(void) asm("func_00276888");
void func_00287f90(s32) asm("func_00287f90");
void Tz__JmCollection__LeaveAll(void) asm("Tz__JmCollection__LeaveAll");
s32 func_00292630(void) asm("func_00292630");
void func_00287c30(void) asm("func_00287c30");
s32 func_0028af18(s32, s32) asm("func_0028af18");
void Tz__Jiminy__LoadData(s32) asm("Tz__Jiminy__LoadData");
void func_002925c0(void) asm("func_002925c0");
s32 func_00276358(void) asm("func_00276358");
void Tz__Jiminy__SetParentSeqNum(s32, s32) asm("Tz__Jiminy__SetParentSeqNum");
void Tz__JmWorldSel__Setup(void) asm("Tz__JmWorldSel__Setup");
void Tz__JmReport__Setup(void) asm("Tz__JmReport__Setup");
void Tz__JmDic__Setup(void) asm("Tz__JmDic__Setup");
void Tz__JmAnsem__SetupTop(void) asm("Tz__JmAnsem__SetupTop");
void func_002aed60(void) asm("func_002aed60");
void Tz__JmTreasure__Setup(void) asm("Tz__JmTreasure__Setup");
void Tz__JmQuest__Setup(void) asm("Tz__JmQuest__Setup");
void Tz__JmMiniGame__Setup(void) asm("Tz__JmMiniGame__Setup");
void func_002a4e38(void) asm("func_002a4e38");
void Tz__JmSynthe__Setup(void) asm("Tz__JmSynthe__Setup");
void func_002a0908(s32) asm("func_002a0908");
void func_0029a368(void) asm("func_0029a368");
s32 func_00289310(s32) asm("func_00289310");
s32 func_00276398(void) asm("func_00276398");
void func_00275b60(void) asm("func_00275b60");
void func_00287c90(s32) asm("func_00287c90");
void Tz__JmCollection__SelCheck(void) asm("Tz__JmCollection__SelCheck");
s32 func_00287df0(s32, s32, s32, void (*)(void), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00287da0(void) asm("func_00287da0");
void func_00276150(s32, s32*, s32*) asm("func_00276150");
void Tz__Jiminy__FadeOutHelp(void) asm("Tz__Jiminy__FadeOutHelp");
void func_00287c00(s32) asm("func_00287c00");
void func_00287cc0(s32) asm("func_00287cc0");
s32 Tz__JmCollection__Cur2SelNum(s32) asm("Tz__JmCollection__Cur2SelNum");
void func_0028fb28(s32, u16) asm("func_0028fb28");
void func_00275dd0(void) asm("func_00275dd0");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
/*TARGET 00299e70*/
void func_00299e70(void) asm("func_00299e70");
void func_00299e70(void)
{
    s32 r = func_00289380(D_0035f200);
    s32 mode = func_00287cd0();
    s32 m = func_00287bc0();
    if (mode == 2) {
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (r != -1) {
                func_00287f90(0);
                Tz__JmCollection__LeaveAll();
            }
            return;
        }
        if (func_00292630()) return;
        Tz__JmCollection__LeaveAll();
        func_00287c30();
        m = func_00287bc0();
        func_0028af18(D_0035f200, 115);
        Tz__Jiminy__LoadData(m);
        func_002925c0();
        Tz__Jiminy__SetParentSeqNum(func_00276358(), 0);
        switch (m) {
        case 0: Tz__JmWorldSel__Setup(); break;
        case 2: Tz__JmReport__Setup(); break;
        case 14: case 18: case 21: Tz__JmDic__Setup(); break;
        case 24: Tz__JmAnsem__SetupTop(); break;
        case 27: func_002aed60(); break;
        case 26: case 34: Tz__JmTreasure__Setup(); break;
        case 35: Tz__JmQuest__Setup(); break;
        case 36: Tz__JmMiniGame__Setup(); break;
        case 37: func_002a4e38(); break;
        case 39: Tz__JmSynthe__Setup(); break;
        case 40: func_002a0908(-1); break;
        }
        return;
    }
    func_0029a368();
    s32 k;  // also holds the func_00289310 test below (the original reuses it; this keeps k out of mode's register)
    if ((r != -1 || (k = func_00289310(D_0035f200))) && !func_00276398()) {
        Tz__Jiminy__SetParentSeqNum(0, 2);
        func_00275b60();
    }
    if (mode == 0 && func_00276398()) func_00287c90(1);
    if (!func_00242848(func_00287df0(r, func_00289310(D_0035f200), 1, Tz__JmCollection__SelCheck, 1))) {
        switch (r) {
        case -4:
            func_00287da0();
            break;
        case -1:
            break;
        case -9:
        case -8: {
            s32 a, b;
            func_00276150(m, &a, &b);
            if (r == -8) {
                mode = b;
                r = 0;
            } else {
                mode = a;
                r = 1;
            }
            Tz__Jiminy__FadeOutHelp();
            Tz__Jiminy__SetParentSeqNum(r, 1);
            func_00287c00(mode);
            func_00287cc0(2);
            break;
        }
        default: {
            k = -1;
            switch (Tz__JmCollection__Cur2SelNum(r)) {
            case 0: k = 24; break;
            case 1: k = 14; break;
            case 2: k = 18; break;
            case 3: k = 21; break;
            case 4: k = 26; break;
            case 5: k = 27; break;
            case 6: k = 34; break;
            case 7: k = 35; break;
            case 8: k = 36; break;
            case 9: k = 37; break;
            case 10: k = 39; break;
            case 11: k = 40; break;
            }
            Tz__Jiminy__SetParentSeqNum(0, 1);
            func_0028fb28(0, D_00374910[Tz__JmCollection__Cur2SelNum(r)]);
            func_00287c00(k);
            Tz__Jiminy__FadeOutHelp();
            func_00275dd0();
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
    if (func_00288040()) func_00288018();
}
}  // namespace n00299e70

// 0029a2a0 (was src/tozawa/jm_collection.cpp)
namespace Tz { // method 0029a2a0
extern u32 D_0035f5a4 asm("D_0035f5a4");
extern u8 D_0035f5a8 asm("D_0035f5a8");
u32 func_0023f900(u32) asm("func_0023f900");
u32 func_00292630() asm("func_00292630");
u32 Tz__JmWorldSel__GetId2Info(u32) asm("Tz__JmWorldSel__GetId2Info");
u32 func_00293db8(u32, u32) asm("func_00293db8");
void func_0023fa08(u32, u32) asm("func_0023fa08");
/*TARGET 0029a2a0*/
void JmCollection::FileAlloc() {
    func_0023f900(D_0035f5a4);
    if (func_00292630() == 0) {
        u8* p = (u8*)Tz__JmWorldSel__GetId2Info(15);
        u32 v = func_00293db8(2, (u32)(p + 1));
        func_0023fa08(D_0035f5a4, v);
        D_0035f5a8 = 1;
        return;
    }
    D_0035f5a8 = 0;
}
}  // Tz

// 0029a310 (was src/anon/auto80_199_queue.cpp)
namespace n0029a310 {
/*TARGET 0029a310*/
void func_0029a310(void) asm("_Z13func_0029a310v");
void func_0029a310(void) {
    if (D_0035f5a8 != 0) {
        if (func_0023f900(D_0035f5a4) != 0) {
            func_0023fad0(D_0035f5a4);
        }
    }
    func_00293d80(5101);
    D_0035f5a8 = 0;
}
}  // namespace n0029a310

// 0029a368 (was src/anon/batch_wcx2.cpp)
namespace n0029a368 {
// 0x00294f00: definition moved into src/anon/unit_00292e60.cpp

// ---- 0029a368
extern bool D_0035f5a8 asm("D_0035f5a8");
extern bool D_0035f5a9 asm("D_0035f5a9");
void func_0029a2a0() asm("func_0029a2a0");
void Tz__JmCollection__CreateGra(u32) asm("Tz__JmCollection__CreateGra");
/*TARGET 0029a368*/
void func_0029a368() asm("func_0029a368");
void func_0029a368() {
    if (D_0035f5a8 && D_0035f5a9) return;
    if (!D_0035f5a8) func_0029a2a0();
    if (D_0035f5a8 && !D_0035f5a9) Tz__JmCollection__CreateGra(1);
}
}  // namespace n0029a368

// 0029a3e0 (was src/anon/batch_w3758.cpp)
namespace n0029a3e0 {
// 0016cc18: moved to src/anon/unit_0016c770.cpp

struct Sub3e0 { u8 pad[184]; u32 f184; };
struct Spr3e0 { u8 pad[24]; Sub3e0 sub; u8 pad2[392-24-188]; s32 f392; u8 pad3[9]; u8 b405; u8 pad4[2]; };
struct Obj3e0 { u8 pad[400]; u8 b400; u8 pad2[15]; };
struct Big3e0 { u8 pad[0x4398]; Spr3e0 spr[2]; u8 pad2[0xdca0 - 0x4398 - 816]; Obj3e0 obj[2]; };
Big3e0* func_002766d0(void) asm("func_002766d0");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
s32 func_0023f1b0(u32) asm("func_0023f1b0");
s32 func_0023c4b8(s32, u32) asm("func_0023c4b8");
s32 func_0023f988(u32, s32) asm("func_0023f988");
void YI__IMAGE__Init(Obj3e0*, s32) asm("YI__IMAGE__Init");
void dk__Sprite__create(Spr3e0*, u8*, s32, Obj3e0*, u32, s32) asm("dk__Sprite__create");
void func_00139620(Spr3e0*) asm("func_00139620");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
extern u8 D_0035f5a8 asm("D_0035f5a8");
extern u8 D_0035f5a9 asm("D_0035f5a9");
extern u8* D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035f5a4 asm("D_0035f5a4");
extern u32 D_003748f0 asm("D_003748f0");
extern u32 D_003748f4 asm("D_003748f4");
extern u32 D_003748f8 asm("D_003748f8");
extern u32 D_003748fc asm("D_003748fc");
extern u32 D_00374900 asm("D_00374900");
extern u32 D_00374904 asm("D_00374904");
/*TARGET 0029a3e0*/
// Partial asm: register pins (k1/c1 t7, one t6, spr0 s7), empty asm barriers keeping the original's serial
// lui/lw order, and one hand-written lui so t6 holds the high half across the movz. See asm_review.tsv.
void Tz__JmCollection__CreateGra(u8 flag) asm("Tz__JmCollection__CreateGra");
// Partial asm: register pins (k1/c1 t7, one t6, spr0 s7), empty asm barriers keeping the original's serial
// lui/lw order, and one hand-written lui so t6 holds the high half across the movz. See asm_review.tsv.
void Tz__JmCollection__CreateGra(u8 flag) {
    Big3e0* b = func_002766d0();
    if (D_0035f5a8 && !D_0035f5a9) {
    s32 i;
    u8* base = D_0035f3d4 + 4;
    s32 x = func_0023aa18((u8*)b + 24);
    s32 y = func_0023aa38((u8*)b + 24); register Spr3e0* s0 asm("$23")=b->spr;
    Obj3e0* o = b->obj;
    for (i = 0; i < 2; i++, o++) {
        register u32 k1 asm("$15") = D_003748f4; asm volatile(""); u32 k = D_003748f0;  register u32 hi asm("$14"); asm volatile("lui $14,%%hi(D_0035f210)" : "=r"(hi)); if (i == 0) k = k1; asm volatile(""); u32 g = *(u32*)(hi - 3568);
        s32 sh = func_0023c4b8(func_0023f1b0(g), k);
        YI__IMAGE__Init(o, func_0023f988(D_0035f5a4, i));
        {register u8 one asm("$14") = 1; o->b400 = one;}
        u32 col;
        s32 c2;
        if (flag) {
            register u32 c1 asm("$15") = D_00374900; asm volatile(""); u32 c0 = D_003748f8; col = i != 0 ? c0 : c1;
            if (i == 0) c2 = D_00374904; else c2 = D_003748fc;
        } else {
            if (i == 0) col = D_00374904; else col = D_003748fc;
            c2 = -1;
        }
        Spr3e0* s = &b->spr[i];
        Sub3e0* sub = &s->sub;
        dk__Sprite__create(s, base, sh, &b->obj[i], col, 0);
        s->f392 = c2;
        func_00139620(s);
        sub->f184 |= 8;
        s->b405 = 1;
        if (i == 0) {
            func_0028dcc0(s0, b);
            func_00138c68(s0, x, y);
        } else {
            func_0028dcc0(s, (u8*)b + 816);
        }
    }
    D_0035f5a9 = 1;
    }
}
}  // namespace n0029a3e0

// 0029a5f0 (was src/anon/batch_w259.cpp)
namespace n0029a5f0 {
s32 func_002a0360(void) asm("func_002a0360");
s32 Tz__JmQuest__isEnable(s32) asm("Tz__JmQuest__isEnable");
s32 Tz__JmMiniGame__isEnable(s32) asm("Tz__JmMiniGame__isEnable");
s32 Tz__JmPuzzle__isEnable(void) asm("Tz__JmPuzzle__isEnable");
s32 func_002a6500(void) asm("func_002a6500");
s32 func_002a7530(void) asm("func_002a7530");
/*TARGET 0029a5f0*/
s32 Tz__JmCollection__Cur2SelNum(s32 idx) asm("Tz__JmCollection__Cur2SelNum");
s32 Tz__JmCollection__Cur2SelNum(s32 idx) {
    s32 tbl[12];
    s32* p = tbl;
    for (s32 i = 0; i < 12; i++) {
        if (i == 0 && !func_002a0360()) continue;
        if (i == 7 && !Tz__JmQuest__isEnable(-1)) continue;
        if (i == 8 && !Tz__JmMiniGame__isEnable(-1)) continue;
        if (i == 5 && !Tz__JmPuzzle__isEnable()) continue;
        if (i == 9 && !func_002a6500()) continue;
        if (i == 10 && !func_002a7530()) continue;
        *p++ = i;
    }
    return tbl[idx];
}
}  // namespace n0029a5f0

// 0029a718 (was src/anon/tiny_auto80_queue.cpp)
namespace n0029a718 {
u32 func_00289310() asm("_ZN2Tz6Select12isCursorMoveEv");
u32 func_0029a740() asm("_ZN2Tz12JmCollection10DrawUpdateEPNS_6SelectEii");
/*TARGET 0029a718*/
void func_0029a718(void) asm("_Z13func_0029a718v");
void func_0029a718(void) {
    if (func_00289310() != 0u) {
        func_0029a740();
    }
}
}  // namespace n0029a718

// 0029a740 (was src/tozawa/jm_collection.cpp)
namespace Tz { // method 0029a740
extern u8 D_00360000 asm("D_00360000");
extern u8 D_00374928 asm("D_00374928");
u32 func_0028b040(u32) asm("func_0028b040");
u32 Tz__JmCollection__Cur2SelNum(u32) asm("Tz__JmCollection__Cur2SelNum");
u32 func_00276c50(u32, u32) asm("func_00276c50");
/*TARGET 0029a740*/
u32 JmCollection::DrawUpdate(Select*, s32, s32) {
    u32 v = func_0028b040(*(u32*)((u8*)&D_00360000 - 3584));
    v = Tz__JmCollection__Cur2SelNum(v);
    v <<= 1;
    v = (u32)((u8*)&D_00374928 + v);
    return func_00276c50(*(u16*)v, 0);
}
}  // Tz

// 0029a780 (was src/anon/batch_wcx.cpp)
namespace n0029a780 {
// 0x00293240: definition moved into src/anon/unit_00292e60.cpp

u32 func_00287bc0(void) asm("func_00287bc0");
void func_00276150(u32, s32*, s32*) asm("func_00276150");
s8* func_00276568(void) asm("func_00276568");
s32 Tz__JmCollection__Cur2SelNum(s32) asm("Tz__JmCollection__Cur2SelNum");
/*TARGET 0029a780*/
s32 Tz__JmCollection__SelCheck(s32 a) asm("Tz__JmCollection__SelCheck");
s32 Tz__JmCollection__SelCheck(s32 a)
{
    s32 r = 0;
    u32 o = func_00287bc0();
    if ((u32)(a + 9) < 2) {
        s32 x, y;
        func_00276150(o, &x, &y);
        s32 v = a == -8 ? y : x;
        s32 c = *func_00276568();
        if (v != 2) r = 1;
        else if ((u32)c < 15) r = 1;
    } else {
        r = (u32)Tz__JmCollection__Cur2SelNum(a) < 12;
    }
    return r;
}
}  // namespace n0029a780

// 0029a820 (was src/anon/batch_w3706_g.cpp)
namespace n0029a820 {
s32 func_00103570(void) asm("func_00103570");
s32 func_001063c0(s32, s32) asm("func_001063c0");
void func_00323fd8(s32) asm("func_00323fd8");
void func_0023d4f8(s32, u32) asm("func_0023d4f8");
typedef s32 (*VFn)(u32, s32, s32);
extern s32 D_0035f5ac asm("D_0035f5ac");
extern s32 D_0035f5b0 asm("D_0035f5b0");
extern s8 D_0035f5b4 asm("D_0035f5b4");
extern s16 D_0035f5b6 asm("D_0035f5b6");
extern s32 D_0035f5b8 asm("D_0035f5b8");
extern s32 D_0035f5bc asm("D_0035f5bc");
extern s32 D_0035f5c0 asm("D_0035f5c0");
extern s8 D_0035f5c4 asm("D_0035f5c4");
/*TARGET 0029a820*/
// Allocates two work buffers, then asks the manager object (D_00347f80 + 20) for entry 0x14f0.
void func_0029a820(void) asm("func_0029a820");
// Allocates two work buffers, then asks the manager object (D_00347f80 + 20) for entry 0x14f0.
void func_0029a820(void) {
    D_0035f5ac = func_001063c0(0x388, func_00103570());
    s32 p = func_001063c0(0x1b3c, func_00103570());
    func_00323fd8(p);
    // Partial asm: the original issues the lui of D_00347f80 (in t6) above the store to
    // D_0035f5b0, sets a2 right after that store and loads D_00347f80 into t5 last.
    // gcc rematerialises the lui next to its load, reusing t7, and sinks the a2 move.
    register u32 h asm("$14"); asm volatile("lui %0,%%hi(D_00347f80)" : "=r"(h));
    D_0035f5b0 = p;
    s32 z; asm volatile("move %0,$0" : "=r"(z));
    register u32 g asm("$13"); asm volatile("lw %0,%%lo(D_00347f80)(%1)" : "=r"(g) : "r"(h));
    u32 obj = *(u32*)(g + 20);
    s32 q = ((VFn)**(u32**)obj)(obj, 0x14f0, z);
    func_0023d4f8(q, 1);
    s32 m = -1;
    D_0035f5b4 = 0; D_0035f5bc = q; D_0035f5b6 = m; D_0035f5c4 = m; D_0035f5b8 = 0; D_0035f5c0 = 0;
}
}  // namespace n0029a820

// 0029a8e0 (was src/anon/batch_w269.cpp)
namespace n0029a8e0 {
typedef void (*KVF269)(u8*);
#define KVCALL269(p, off) ((*(KVF269*)(*(u8**)(p) + (off)))(p))
// 0x002843e8: definition moved into src/anon/unit_00284220.cpp

extern u8* D_0035f5ac asm("D_0035f5ac");
extern u8* D_0035f5b0 asm("D_0035f5b0");
extern u8 D_0035f5b4 asm("D_0035f5b4");
extern s16 D_0035f5b6 asm("D_0035f5b6");
extern u32 D_0035f5b8 asm("D_0035f5b8");
extern u8* D_0035f5bc asm("D_0035f5bc");
extern s8 D_0035f5c4 asm("D_0035f5c4");
extern u8 D_00347e60[] asm("D_00347e60");
void func_00106420(void*) asm("func_00106420");
void func_0031abd8(u8*) asm("func_0031abd8");
void func_0031acc0(u8*) asm("func_0031acc0");
void func_00239870(u8*) asm("func_00239870");
void func_0031a840(u8*) asm("func_0031a840");
/*TARGET 0029a8e0*/
void func_0029a8e0(void) asm("func_0029a8e0");
void func_0029a8e0(void) {
    if (D_0035f5ac) {
        func_00106420(D_0035f5ac);
        D_0035f5ac = 0;
    }
    u8* o = D_0035f5b0;
    if (o) {
        u8* p;
        func_0031abd8(o + 6512);
        p = o + 6104;
        func_0031abd8(p);
        if (o + 3924 != 0) {
            u8* e1 = o + 3924;
        top1:
            if (e1 == p) goto out1;
            p -= 436;
            KVCALL269(p, 12);
            goto top1;
        }
    out1:
        if (o + 1744 != 0) {
            u8* q = o + 3924;
            u8* e2 = o + 1744;
        top2:
            if (e2 == q) goto out2;
            q -= 436;
            KVCALL269(q, 12);
            goto top2;
        }
    out2:
        func_0031acc0(o + 1308);
        func_0031acc0(o + 872);
        func_0031acc0(o + 436);
        *(u32*)o = (u32)D_00347e60;
        func_00239870(o + 24);
        func_0031a840(o);
        func_00106420(o);
        D_0035f5b0 = 0;
    }
    if (D_0035f5bc) {
        KVCALL269(D_0035f5bc, 16);
        D_0035f5bc = 0;
    }
    D_0035f5b4 = 0;
    D_0035f5b6 = -1;
    D_0035f5b8 = 0;
    D_0035f5c4 = -1;
}
}  // namespace n0029a8e0
#undef KVCALL269

// 0029aa30 (was src/anon/batch_w55.cpp)
namespace n0029aa30 {
struct NoTail { ~NoTail() {} };
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0029df98(void) asm("func_0029df98");
void func_0029e050(void) asm("func_0029e050");
void func_0029e258(s32) asm("func_0029e258");
/*TARGET 0029aa30*/
void func_0029aa30(void) asm("func_0029aa30");
void func_0029aa30(void) {
    NoTail keep_frame; // forces jal instead of a sibling call
    s32 m = func_00287bc0();
    if ((u32)(m - 14) < 2 || m == 18 || m == 21 || m == 16 || m == 19 || m == 22 || m == 17 || m == 20 || m == 23) {
        func_0029df98();
        func_0029e050();
        func_0029e258(0);
        func_0029e258(1);
    }
}
}  // namespace n0029aa30

// 0029aac0 (was src/anon/batch_wcx2.cpp)
namespace n0029aac0 {
// 0x0026d620: definition moved into src/anon/unit_0026c450.cpp

extern u8* D_0035f5bc asm("D_0035f5bc");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00274ac8(void) asm("func_00274ac8");
void func_0028f7e8(s32) asm("func_0028f7e8");
void func_0029ac00(void) asm("func_0029ac00");
u8* func_00287dc0(void) asm("func_00287dc0");
s32 func_00139d78(void*) asm("func_00139d78");
void func_0023d820(u8*) asm("func_0023d820");
void func_0029e9d0(void) asm("func_0029e9d0");
/*TARGET 0029aac0*/
void func_0029aac0(s32 k) asm("func_0029aac0");
void func_0029aac0(s32 k)
{
    s32 v = func_00287bc0();
    if (!((u32)(v - 14) < 2 || v == 18 || v == 21 || v == 16 || v == 19 || v == 22 || v == 17 || v == 20 || v == 23)) return;
    func_00274ac8();
    if (!((u32)(k - 14) < 2 || k == 18 || k == 21 || k == 16 || k == 19 || k == 22)) func_0028f7e8(0);
    if (!((u32)(k - 15) < 2 || k == 18 || k == 21)) func_0028f7e8(1);
    func_0029ac00();
    u8* o = func_00287dc0();
    if (func_00139d78(o)) func_0023d820(o);
    if (func_00139d78(D_0035f5bc)) func_0023d820(D_0035f5bc);
    func_0029e9d0();
}
}  // namespace n0029aac0

// 0029ac00 (was src/anon/batch_w265.cpp)
namespace n0029ac00 {
extern u8* D_0035f5b0 asm("D_0035f5b0");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00139510(void*) asm("func_00139510");
struct W265Sub { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); u8 pad[432]; };
struct W265Big { u8 pad[1744]; W265Sub arr[10]; };
/*TARGET 0029ac00*/
void func_0029ac00(void) asm("func_0029ac00");
void func_0029ac00(void) {
    s32 i;
    s32 off;
    if (D_0035f5b0 == 0) return;
    if (func_00139d78(D_0035f5b0)) func_00139510(D_0035f5b0);
    if (func_00139d78(D_0035f5b0 + 436)) func_00139510(D_0035f5b0 + 436);
    if (func_00139d78(D_0035f5b0 + 872)) func_00139510(D_0035f5b0 + 872);
    if (func_00139d78(D_0035f5b0 + 6104)) func_00139510(D_0035f5b0 + 6104);
    if (func_00139d78(D_0035f5b0 + 6512)) func_00139510(D_0035f5b0 + 6512);
    off = 0;
    for (i = 4; i >= 0; i--) {
        if (func_00139d78(&((W265Big*)D_0035f5b0)->arr[off])) ((W265Big*)D_0035f5b0)->arr[off].v5();
        if (func_00139d78(&((W265Big*)D_0035f5b0)->arr[off + 5])) ((W265Big*)D_0035f5b0)->arr[off].v5();
        off++;
    }
}
}  // namespace n0029ac00

// 0029ad40 (was src/anon/batch_w91.cpp)
namespace n0029ad40 {
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
// 0x00292f18: definition moved into src/anon/unit_00292e60.cpp

// --- 0029ad40
// Returns early as soon as any of the menu's sprites is still alive.
extern u8* D_0035f5b0 asm("D_0035f5b0");
struct NoTail91 { ~NoTail91() {} };
/*TARGET 0029ad40*/
void func_0029ad40(void) asm("func_0029ad40");
void func_0029ad40(void) {
    NoTail91 nt;
    if (u_call4_00139d78(D_0035f5b0)) return;
    if (u_call4_00139d78(D_0035f5b0 + 436)) return;
    if (u_call4_00139d78(D_0035f5b0 + 872)) return;
    if (u_call4_00139d78(D_0035f5b0 + 1308)) return;
    for (s32 i = 0; i < 5; i++) {
        if (u_call4_00139d78(D_0035f5b0 + i * 436 + 1744)) return;
        if (u_call4_00139d78(D_0035f5b0 + i * 436 + 3924)) return;
    }
    if (u_call4_00139d78(D_0035f5b0 + 6104)) return;
    u_call4_00139d78(D_0035f5b0 + 6512);
}
}  // namespace n0029ad40

// 0029ae30 (was src/anon/tiny.cpp)
namespace n0029ae30 {
extern u32 D_0035f5b4 asm("D_0035f5b4");
/*TARGET 0029ae30*/
// 0x00293bb0: definition moved into src/anon/unit_00292e60.cpp

void func_0029ae30(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0029ae30jjjj");
// 0x00293bb0: definition moved into src/anon/unit_00292e60.cpp

void func_0029ae30(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_0035f5b4 = (u8)v;
}
}  // namespace n0029ae30

// .rodata 0x3748f0-0x374940: this file's const tables, read by other code as extern D_
namespace r003748f0 {
extern const u32 R_003748f0[1] asm("D_003748f0") __attribute__((aligned(4))) = { 0x3 };
extern const u32 R_003748f4[1] asm("D_003748f4") __attribute__((aligned(4))) = { 0x4 };
extern const u32 R_003748f8[1] asm("D_003748f8") __attribute__((aligned(4))) = { 0x1 };
extern const u32 R_003748fc[1] asm("D_003748fc") __attribute__((aligned(4))) = { 0x2 };
extern const u32 R_00374900[1] asm("D_00374900") __attribute__((aligned(4))) = { 0x1 };
extern const u32 R_00374904[1] asm("D_00374904") __attribute__((aligned(4))) = { 0x2 };
extern const u32 R_00374908[1] asm("D_00374908") __attribute__((aligned(4))) = { 0x9d };
extern const u32 R_0037490c[1] asm("D_0037490c") __attribute__((aligned(4))) = { 0x9e };
extern const u32 R_00374910[6] asm("D_00374910") __attribute__((aligned(4))) = { 0x367a3679, 0x367c367b, 0x4f4748da, 0x48dc48db, 0x48de48dd, 0x48e048df };
extern const u32 R_00374928[6] asm("D_00374928") __attribute__((aligned(4))) = { 0x48e248e1, 0x48e448e3, 0x4f6b48e5, 0x48e748e6, 0x48e948e8, 0x48eb48ea };
}  // namespace r003748f0

// 0029ae40 (was src/anon/batch_wcx2.cpp)
namespace n0029ae40 {
// 0x002826f8: definition moved into src/anon/unit_00282620.cpp

// --------------------
extern s32 D_0035f200_x9084 asm("D_0035f200");
extern u8 D_00374ad8[] asm("D_00374ad8");
extern s8 D_0035f5c4 asm("D_0035f5c4");
void func_00288e88(s32) asm("func_00288e88");
s32 func_00287bc0() asm("func_00287bc0");
void func_0028f4a0(void*) asm("func_0028f4a0");
void func_0029ae30() asm("func_0029ae30");
void func_0029af20() asm("func_0029af20");
void func_0029e950(s32) asm("func_0029e950");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
void func_0029b698() asm("func_0029b698");
void func_0029be08() asm("func_0029be08");
/*TARGET 0029ae40*/
void Tz__JmDic__Setup() asm("Tz__JmDic__Setup");
void Tz__JmDic__Setup() {
    func_00288e88(D_0035f200_x9084);
    s32 n = func_00287bc0();
    func_0028f4a0(D_00374ad8);
    func_0029ae30();
    switch (n) {
    case 14:
        func_0029af20();
        break;
    case 15: case 18: case 21:
        if (n == 18) func_0029e950(17);
        else if (n == 21) func_0029e950(18);
        func_002765e8(15, 0, 0);
        func_0029b698();
        break;
    case 16: case 19: case 22:
        D_0035f5c4 = -1;
        func_0029be08();
        break;
    }
}
}  // namespace n0029ae40

