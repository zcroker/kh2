#include "../common/types.h"
extern "C" {
struct W1709Layout;
struct W1709Select;
struct W1709LightCur { u8 pad[0x18c]; s32 item; };

extern W1709Select* D_0035f64c;
extern W1709Select* D_0035f650;
extern W1709Layout* D_0035f664;
extern W1709LightCur* D_0035f67c;
extern s32 D_0035f640;
extern s32 D_0035f644;
extern s32 D_0035f66c;
extern s32 D_0035f670;
extern u16 D_00372ec0[];

u32 mb_GetMode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
s32 mb_GetNextMode(void) asm("_ZN2Tz8MenuBase11GetNextModeEv");
u32 ci_isPadHelpVisible(void) asm("_ZN2Tz6CmItem16isPadHelpVisibleEv");
s32 obj_isActive(W1709Layout*) asm("_Z16u_call4_00139d78jjjj");
s32 lay_getNum(W1709Layout*) asm("_ZN2Tz6Layout6getNumEv");
void lay_setNum(W1709Layout*, s32, s32) asm("_ZN2Tz6Layout6setNumEii");
s32 sel_isCreated(W1709Select*) asm("_ZN2Tz6Select9isCreatedEz");
s32 sel_isFadeOut(W1709Select*) asm("_ZN2Tz6Select9isFadeOutEv");
void sel_Start(W1709Select*) asm("_ZN2Tz6Select5StartEz");
s32 sel_GetCurrentItemPtr(W1709Select*) asm("_ZN2Tz6Select17GetCurrentItemPtrEv");
void cmsl_FadeOutWarningWin(void) asm("_ZN2Tz8CmSLBase17FadeOutWarningWinEv");
void cmsl_FadeOutList(void) asm("_ZN2Tz8CmSLBase11FadeOutListEv");
void sh_FadeOutAll(void) asm("_ZN2Tz7SelHist10FadeOutAllEv");
void lc_FadeOut(W1709LightCur*) asm("_ZN2Tz8LightCur7FadeOutEv");
void lc_Leave(W1709LightCur*) asm("_ZN2Tz8LightCur5LeaveEv");
s32 lc_isExist(W1709LightCur*) asm("_ZN2Tz8LightCur7isExistEv");
void help_Leave(void) asm("_ZN2Tz9CMenuHelp5LeaveEv");
void mc_DeleteAll(...) asm("_ZN2Tz10MenuCursor9DeleteAllEz");
s32 slr_GetState(void) asm("_ZN2Tz8Selector8GetStateEv");
void func_0028ffe8(s32, s32);
void func_00290508(s32, s32);
void func_002b6418(void);
s32 func_0028d008(s32);
void func_0028cdb8(s32);
void func_0028cc78(s32, s32, s32, W1709Layout*, s32, s32);
void func_0028cf28(s32, s32);
void func_0028ce98(s32, s32);
s32 func_0028cf10(s32);
void func_0028d1c0(W1709LightCur*, s32, s32, s32, W1709Layout*, u16*, s32);
void func_0028d660(W1709LightCur*, s32);
void func_0025d3c8(W1709Select*, u32, s32);

static inline s32 W1709_UseSubCursor(W1709Select* sel) {
    if (sel != D_0035f64c && sel_isCreated(D_0035f64c)) return 1;
    return 0;
}
void func_0025cde0(void) {
    u32 mode = mb_GetMode();
    W1709Select* sel;
    s32 sub;

    if (ci_isPadHelpVisible()) {
        if (obj_isActive(D_0035f664)) {
            if (lay_getNum(D_0035f664) != 2) lay_setNum(D_0035f664, 2, -1);
        }
        if (sel_isCreated(D_0035f64c) && !sel_isFadeOut(D_0035f64c)) sel_Start(D_0035f64c);
        if (sel_isCreated(D_0035f650) && !sel_isFadeOut(D_0035f650)) sel_Start(D_0035f650);
        cmsl_FadeOutWarningWin();
        cmsl_FadeOutList();
        sh_FadeOutAll();
        lc_FadeOut(D_0035f67c);
        help_Leave();
        func_0028ffe8(D_0035f66c, 1);
        func_00290508(D_0035f670, 1);
        mc_DeleteAll();
    }
    func_002b6418();
    if (ci_isPadHelpVisible()) return;

    switch (mode) {
    case 0: case 1: case 12:
        sel = D_0035f64c;
        break;
    default:
        sel = 0;
        break;
    case 5: case 7: case 8: case 10: case 13: case 19: case 22:
        sel = D_0035f650;
        break;
    }

    if (sel == 0) {
        if (mode == 15 || mode == 9 || mode == 20 || mode == 14) {
            if (!func_0028d008(1)) func_0028cdb8(1);
            if (!func_0028d008(0)) {
                func_0028cc78(0, 0, 0, D_0035f664, 12, 10);
                func_0028cf28(0, sel_GetCurrentItemPtr(D_0035f64c));
                func_0028ce98(0, 1);
            } else if (func_0028cf10(0) != 1) {
                func_0028ce98(0, 1);
            }
        } else {
            mc_DeleteAll();
        }
        lc_Leave(D_0035f67c);
        return;
    }

    sub = W1709_UseSubCursor(sel);

    if (sel_isCreated(sel) && slr_GetState() == 1) {
        if (!func_0028d008(sub)) {
            func_0028cc78(sub, 0, 0, D_0035f664, 12, 10);
            func_0028cf28(sub, sel_GetCurrentItemPtr(sel));
            if (!lc_isExist(D_0035f67c))
                func_0028d1c0(D_0035f67c, 0x7571, 0, 0, D_0035f664, D_00372ec0, 0);
            if (sub) {
                if (!func_0028d008(0)) {
                    func_0028cc78(0, D_0035f644, D_0035f640, D_0035f664, 12, 10);
                    func_0028cf28(0, sel_GetCurrentItemPtr(D_0035f64c));
                }
                func_0028ce98(0, 1);
            }
            func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(sel));
        } else {
            if (func_0028cf10(sub) == 1) func_0028ce98(sub, 0);
            if (!lc_isExist(D_0035f67c)) {
                func_0028d1c0(D_0035f67c, 0x7571, 0, 0, D_0035f664, D_00372ec0, 0);
                func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(sel));
            }
        }
    } else if (slr_GetState() == 2) {
        if ((mode == 13 || mode == 8) && mb_GetNextMode() != 12) {
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
        }
        if (sub && sel_isFadeOut(D_0035f64c) && func_0028d008(0)) {
            func_0028cdb8(0);
            lc_FadeOut(D_0035f67c);
        }
    }

    if (sub && sel_isCreated(sel) && slr_GetState() == 0 && lc_isExist(D_0035f67c)) {
        s32 item = D_0035f67c->item;
        if (item != sel_GetCurrentItemPtr(sel))
            func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(sel));
    }

    switch (mode) {
    case 0: case 1: case 5: case 7: case 8: case 10: case 12: case 13: case 19:
        func_0025d3c8(sel, mode, sub);
        break;
    }
}
}
