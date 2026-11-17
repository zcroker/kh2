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
void func_0025cde0(void);  // 0x0025cde0: definition moved into src/anon/unit_002588e8.cpp
}
