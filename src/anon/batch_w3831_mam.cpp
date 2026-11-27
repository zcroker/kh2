#include "../common/types.h"
extern "C" {
extern u32 D_0035f01c;
extern u32 D_0035f010;
extern u32 D_0035f03c;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern s32 D_0035ef6c;
extern s32 D_0035f3d4;
extern u8* D_0035f230;
extern s32 D_00373dfc;
extern s32 D_00373e00;
u8* func_00257770(void);
void func_0028f4d8(s32, s32, s32);
s32 func_00257100(s32);
void Tz__Select__SetItem(u32, s32, u32, u32, u32, s32, s32, s32);
void Tz__Select__SetExOffset(u32, s32, s32, s32);
u8* func_002891b8(u32, s32);
void func_00139620(u8*);
void func_001395f8(u8*);
s32 func_00281140(u32, s32);
s32 func_00281180(u32, s32);
s32 func_00281100(u32);
s32 func_0023aa98(u8*);
s32 func_00277708(s32);
void func_00138c68(u8*, s32, s32);
s32 func_00257070(s32);
s32 func_002892f8(u32);
void func_00257050(s32, s32, s32);
void Tz__Select__SetCurrent(u32, s32, s32, s32, s32);
s32 func_0028afa8(u32);
void func_0027aed8(s32, s32*, s32*);
s32 Tz__CmNewFlg__isAbilityNewMember(s32, s32);
s32 Tz__CmNewFlg__isAbilityHistMember(s32, s32);
s32 func_0027ae78(s32);
s32 Tz__CmNewFlg__isAbilityNewForm(s32, s32);
s32 func_00287218(s32, s32);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_0028dcc0(u8*, u8*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void Tz__CmAbility__CreateTopList(void);
void func_00279ec8(void);
s32 func_0028af88(u32);
s32 func_00258068(s32);
void Tz__CmTop__CreatePadHelp(s32, s32, s32);
void func_0028af18(u32, s32);
void func_00287cc0(s32);

// 002772c8: sets up the list in D_0035f01c (first entry, up to three more entries chosen by
// func_00281180, then one row per entry), then sets its flags. Built with -fmove-all-movables.
// Partial asm (no code emitted): p is pinned to s2 with empty "+r" ties so the call result is
// used straight from v0 like the original; w doubles as the first product term so it gets s1.
void Tz__CmAbility__SetupTop(s32 arg);  // 0x002772c8: definition moved into src/anon/unit_002772c8.cpp
}
