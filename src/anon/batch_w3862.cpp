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
void func_0025eee8(void);  // 0x0025eee8: definition moved into src/anon/unit_0025da20.cpp

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
void func_00299920(void);  // 0x00299920: definition moved into src/anon/unit_00299920.cpp
}
