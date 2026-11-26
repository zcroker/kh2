// 00299e70: empty asm on k in the -8 arm makes k conflict with mode, so k stays in s2; barrier asms keep the order lw a0, li a1, move s3,v0 before jal 0028af18.
#include "../common/types.h"
extern "C" {
extern s32 D_0035f200;
extern u16 D_00374910[];
s32 func_00289380(s32);
s32 func_00287cd0(void);
s32 func_00287bc0(void);
s32 func_00276368(void);
s32 func_0028acc8(s32);
s32 func_00276888(void);
void func_00287f90(s32);
void Tz__JmCollection__LeaveAll(void);
s32 func_00292630(void);
void func_00287c30(void);
void func_0028af18(s32, s32);
void Tz__Jiminy__LoadData(s32);
void func_002925c0(void);
s32 func_00276358(void);
void Tz__Jiminy__SetParentSeqNum(s32, s32);
void Tz__JmWorldSel__Setup(void);
void Tz__JmReport__Setup(void);
void Tz__JmDic__Setup(void);
void Tz__JmAnsem__SetupTop(void);
void func_002aed60(void);
void Tz__JmTreasure__Setup(void);
void Tz__JmQuest__Setup(void);
void Tz__JmMiniGame__Setup(void);
void func_002a4e38(void);
void Tz__JmSynthe__Setup(void);
void func_002a0908(s32);
void func_0029a368(void);
s32 func_00289310(s32);
s32 func_00276398(void);
void func_00275b60(void);
void func_00287c90(s32);
void Tz__JmCollection__SelCheck(void);
s32 func_00287df0(s32, s32, s32, void (*)(void), s32);
s32 func_00242848(s32);
void func_00287da0(void);
void func_00276150(s32, s32*, s32*);
void Tz__Jiminy__FadeOutHelp(void);
void func_00287c00(s32);
void func_00287cc0(s32);
s32 Tz__JmCollection__Cur2SelNum(s32);
void func_0028fb28(s32, u16);
void func_00275dd0(void);
void func_002765e8(s32, s32, s32);
s32 func_00288040(void);
void func_00288018(void);
void func_00299e70(void);  // 0x00299e70: definition moved into src/anon/unit_00299920.cpp
}
