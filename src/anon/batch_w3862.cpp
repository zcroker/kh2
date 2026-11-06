#include "../common/types.h"
extern "C" {
struct W3862Layout;
struct W3862Select;
struct W3862LightCur { u8 pad[0x18c]; s32 item; };

extern W3862Select* D_0035f64c;
extern W3862Select* D_0035f650;
extern W3862Layout* D_0035f664;
extern W3862LightCur* D_0035f67c;
extern s32 D_0035f640;
extern s32 D_0035f644;
extern u16 D_00373130[];

u32 mb_GetMode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
s32 mb_GetNextMode(void) asm("_ZN2Tz8MenuBase11GetNextModeEv");
u32 ci_isPadHelpVisible(void) asm("_ZN2Tz6CmItem16isPadHelpVisibleEv");
s32 obj_isActive(W3862Layout*) asm("_Z16u_call4_00139d78jjjj");
s32 lay_getNum(W3862Layout*) asm("_ZN2Tz6Layout6getNumEv");
void lay_setNum(W3862Layout*, s32, s32) asm("_ZN2Tz6Layout6setNumEii");
s32 sel_isCreated(W3862Select*) asm("_ZN2Tz6Select9isCreatedEz");
s32 sel_isFadeOut(W3862Select*) asm("_ZN2Tz6Select9isFadeOutEv");
void sel_Start(W3862Select*) asm("_ZN2Tz6Select5StartEz");
s32 sel_GetCurrentItemPtr(W3862Select*) asm("_ZN2Tz6Select17GetCurrentItemPtrEv");
void cmsl_FadeOutWarningWin(void) asm("_ZN2Tz8CmSLBase17FadeOutWarningWinEv");
void cmsl_FadeOutList(void) asm("_ZN2Tz8CmSLBase11FadeOutListEv");
void sh_FadeOutAll(void) asm("_ZN2Tz7SelHist10FadeOutAllEv");
void lc_FadeOut(W3862LightCur*) asm("_ZN2Tz8LightCur7FadeOutEv");
void lc_Leave(W3862LightCur*) asm("_ZN2Tz8LightCur5LeaveEv");
s32 lc_isExist(W3862LightCur*) asm("_ZN2Tz8LightCur7isExistEv");
void help_Leave(void) asm("_ZN2Tz9CMenuHelp5LeaveEv");
void mc_DeleteAll(...) asm("_ZN2Tz10MenuCursor9DeleteAllEz");
s32 slr_GetState(void) asm("_ZN2Tz8Selector8GetStateEv");
void func_002b6418(void);
s32 func_0028d008(s32);
void func_0028cdb8(s32);
void func_0028cc78(s32, s32, s32, W3862Layout*, s32, s32);
void func_0028cf28(s32, s32);
void func_0028ce98(s32, s32);
s32 func_0028cf10(s32);
void func_0028d1c0(W3862LightCur*, s32, s32, s32, W3862Layout*, u16*, s32);
void func_0028d660(W3862LightCur*, s32);
void func_0025f430(W3862Select*, u32, s32);

static inline s32 W3862_UseSubCursor(W3862Select* sel) {
    if (sel != D_0035f64c && sel_isCreated(D_0035f64c)) return 1;
    return 0;
}

// Menu cursor/light-cursor upkeep for the current menu mode (sibling of func_0025cde0).
void func_0025eee8(void) {
    u32 mode = mb_GetMode();
    W3862Select* sel;
    s32 sub;

    if (ci_isPadHelpVisible()) {
        if (obj_isActive(D_0035f664)) {
            if (lay_getNum(D_0035f664) != 2) lay_setNum(D_0035f664, 2, -1);
        }
        if (sel_isCreated(D_0035f64c) && !sel_isFadeOut(D_0035f64c)) sel_Start(D_0035f64c);
        if (sel_isCreated(D_0035f650) && !sel_isFadeOut(D_0035f650)) sel_Start(D_0035f650);
        cmsl_FadeOutList();
        cmsl_FadeOutWarningWin();
        sh_FadeOutAll();
        lc_FadeOut(D_0035f67c);
        help_Leave();
        mc_DeleteAll();
    }
    func_002b6418();
    if (ci_isPadHelpVisible()) return;

    switch (mode) {
    case 1: case 12:
        sel = D_0035f64c;
        break;
    default:
        sel = 0;
        break;
    case 5: case 7: case 11: case 16:
        sel = D_0035f650;
        break;
    }

    if (sel == 0) {
        if (mode == 18) {
            func_0028cdb8(1);
        } else {
            mc_DeleteAll();
        }
        lc_Leave(D_0035f67c);
        return;
    }

    sub = W3862_UseSubCursor(sel);

    if (sel_isCreated(sel) && slr_GetState() == 1) {
        if (!func_0028d008(sub)) {
            func_0028cc78(sub, 0, 0, D_0035f664, 12, 10);
            func_0028cf28(sub, sel_GetCurrentItemPtr(sel));
            if (!lc_isExist(D_0035f67c))
                func_0028d1c0(D_0035f67c, 0x7571, 0, 0, D_0035f664, D_00373130, 0);
            if (sub) {
                if (func_0028d008(0)) {
                    func_0028ce98(0, 1);
                } else {
                    func_0028cc78(0, D_0035f644, D_0035f640, D_0035f664, 12, 10);
                    func_0028cf28(0, sel_GetCurrentItemPtr(D_0035f64c));
                }
            }
            func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(sel));
        } else {
            if (func_0028cf10(sub) == 1) func_0028ce98(sub, 0);
            if (!lc_isExist(D_0035f67c)) {
                func_0028d1c0(D_0035f67c, 0x7571, 0, 0, D_0035f664, D_00373130, 0);
                func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(sel));
            }
        }
    } else if (slr_GetState() == 2) {
        if (mb_GetMode() == 16 && mb_GetNextMode() != 12) {
            if (func_0028d008(sub)) func_0028cdb8(sub);
            if (lc_isExist(D_0035f67c)) lc_FadeOut(D_0035f67c);
        } else {
            if (func_0028d008(sub)) {
                func_0028cdb8(sub);
                if (sub) {
                    func_0028ce98(0, 0);
                    func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(D_0035f64c));
                } else {
                    lc_FadeOut(D_0035f67c);
                }
            } else if (lc_isExist(D_0035f67c)) {
                if (sub) {
                    func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(D_0035f64c));
                } else {
                    lc_FadeOut(D_0035f67c);
                }
            }
            if (sub && sel_isFadeOut(D_0035f64c) && func_0028d008(0)) {
                func_0028cdb8(0);
                lc_FadeOut(D_0035f67c);
            }
        }
    }

    if (sub && sel_isCreated(sel) && slr_GetState() == 0 && lc_isExist(D_0035f67c)) {
        s32 item = D_0035f67c->item;
        if (item != sel_GetCurrentItemPtr(sel))
            func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(sel));
    }

    switch (mode) {
    case 0: case 1: case 5: case 7: case 11: case 12: case 16:
        func_0025f430(sel, mode, sub);
        break;
    }
}

u8* func_002766d0(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
s32 sel_GetSelectMax(s32) asm("_ZN2Tz6Select12GetSelectMaxEv");
u8* func_002891b8(s32, s32);
s32 func_00192048(s32);
void func_00138c10(u8*, s32);
void func_0028af90(s32, s32);
s32 jm_isFullOpen(void) asm("_ZN2Tz6Jiminy10isFullOpenEv");
s32 func_002a0360(void);
s32 func_002aa2f8(s32);
s32 func_002aa378(s32);
s32 func_002ad338(void);
s32 func_002aa098(s32);
s32 func_002aa148(s32);
s32 func_002ad1b0(s32);
s32 func_002ab540(s32);
s32 func_002ab620(s32);
s32 func_002adaf0(s32);
s32 func_002b3ae8(void);
s32 func_002ac420(s32);
s32 func_002ac748(s32);
s32 func_002ac538(s32);
s32 func_002ac800(s32);
s32 func_002ae660(s32);
s32 func_002ae768(s32);
s32 jmc_isPuzzleInfoComp(s32) asm("_ZN2Tz10JmComplete16isPuzzleInfoCompEi");
s32 func_002ab8e8(s32);
s32 func_002ab9c8(s32);
s32 func_002adcb0(s32);
s32 func_002a9b88(s32);
s32 func_002aacd8(s32);
s32 func_002aad58(s32);
s32 func_002ad7d0(s32);
s32 func_002a8870(s32);
s32 func_002ab100(s32);
s32 func_002ab180(s32);
s32 func_002ad950(s32);
s32 func_002a6500(void);
s32 func_002aaa38(s32);
s32 func_002aaab8(s32);
s32 func_002ad660(void);
s32 func_002a7530(void);
s32 func_002abc60(s32);
s32 func_002abce8(s32);
s32 func_002adf60(s32);
s32 func_002a1b18(s32, s32);
s32 func_002ae1b0(s32, s32);
extern s32 D_0035f200;
extern s32 D_00374908;
extern s32 D_0037490c;
extern u16 D_00374910[];


// Jiminy's journal: fills the menu items with each category's new/complete marks.
void func_00299920(void) {
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
            a = func_002ab540(-1);
            b = func_002ab620(-1);
            c = func_002adaf0(-1);
            break;
        case 5:
            if (!func_002b3ae8()) {
                if (!jm_isFullOpen()) continue;
                show = 0;
            }
            a = 0;
            if (func_002ac420(-1) || func_002ac748(-1)) a = 1;
            if (func_002ac420(-1) && !func_002ac748(-1)) {
                b = func_002ac538(-1);
            } else if (!func_002ac420(-1) && func_002ac748(-1)) {
                b = func_002ac800(-1);
            } else if (func_002ac420(-1) && func_002ac748(-1)) {
                b = 0;
                if (func_002ac538(-1) && func_002ac800(-1)) b = 1;
            } else {
                b = 0;
            }
            c = 0;
            if (func_002ae660(-1) && func_002ae768(-1) && jmc_isPuzzleInfoComp(-1)) c = 1;
            break;
        case 6:
            a = func_002ab8e8(-1);
            b = func_002ab9c8(-1);
            c = func_002adcb0(-1);
            break;
        case 7:
            if (!func_002a9b88(-1)) {
                if (!jm_isFullOpen()) continue;
                show = 0;
            }
            a = func_002aacd8(-1);
            b = func_002aad58(-1);
            c = func_002ad7d0(-1);
            break;
        case 8:
            if (!func_002a8870(-1)) {
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
            s32 r = func_002a1b18(1, -1);
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
    func_0028af90(D_0035f200, n);
}
}
