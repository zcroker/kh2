#include "../common/types.h"
struct E270 { s16 id; s8 a; s8 b; u8 pad[4]; };
struct T270 { u8 pad[3]; s8 h3; u8 pad2[4]; E270 e[1]; };
struct L270 { u16 id; u16 pad[2]; };
struct R270 { u8 pad[5]; u8 f5; };
extern "C" {
struct Pad2a23a0 { u64 a; u64 b; u64 c; u64 d; };
Pad2a23a0* func_00167f18(s32);
void func_00242618(s32, s32);
void Tz__Jiminy__LoadData(s32);
void Tz__Jiminy__SetParentSeqNum(s32, s32);
s32 func_00276358(void);
s32 func_00276368(void);
s32 func_00276398(void);
s32 func_00276888(void);
void Tz__Jiminy__FadeOutHelp(void);
s32 func_00287bc0(void);
void func_00287c00(s32);
void func_00287c30(void);
void func_00287cc0(s32);
s32 func_00287cd0(void);
void func_00287da0(void);
void func_00287f90(s32);
void func_00288018(void);
s32 func_00288040(void);
void Tz__SelHist__FadeOut(s32);
void func_002925c0(void);
s32 func_00292630(void);
void Tz__JmReport__Setup(void);
void func_002995e8(void);
void func_002a2148(void);
void func_002a2150(void);
s32 func_002a40c8(void);
void func_002a4470(void);
void func_002a45a0(void);
void func_002a4620(Pad2a23a0*);
void Tz__JmTreasure__Control(void);  // 0x002a23a0: definition moved into src/anon/unit_002a1d38.cpp
void func_002aed60(void);
void Tz__JmTreasure__CtrlPieceInfo(void);  // 0x002a2818: definition moved into src/anon/unit_002a1d38.cpp
extern s32 D_0035f01c;
void Tz__CmAbility__SelCheck(void);
s32 func_00289380(s32);
s32 func_00287c10(void);
s32 func_0027ad80(void);
s32 func_0028f930(s32);
s32 func_00256ef0(void);
s32 func_00289310(s32);
void func_0027acf8(void);
void func_00279040(void);
void Tz__CmAbility__SetupSel(void);
s32 func_0027a990(void);
void func_0027aa10(void);
void func_0028fa98(s32);
void func_0027b6b8(void);
void func_00287c90(s32);
s32 func_0028afa8(s32);
s32 func_00287df0(s32, s32, s32, void (*)(void), s32);
s32 func_00242848(s32);
void Tz__CmAbility__ChgEquipAbility(void);
void Tz__CMenuHelp__FadeOut(void);
void func_00256e80(void);
void Tz__CmAbility__FadeOutAbilityList(void);
void func_00287bd0(s32, s32);
void func_002831e0(s32, s32);
void func_00278dd0(void);  // 0x00278dd0: definition moved into src/anon/unit_00278dd0.cpp
extern T270* D_0035f12c;
extern s32 D_0035f014;
extern s32 D_0035f04c;
s32 func_002570a0(s32);
u32 Tz__CmCustom__CurPos2CustomType(s32);
s32 func_00281f18(s32);
L270* func_00281f20(s32);
R270* func_00273180(s32, s32);
void Tz__Select__SetCurrent(s32, s32, s32, s32, s32);
void func_0028afd0(s32, s32);
void Tz__ScrollBar__SetPos(s32, s32);
void Tz__CmCustom__SetIndiCustomDefaultPos(void);  // 0x00270648: definition moved into src/anon/unit_0026f0a0.cpp
}
