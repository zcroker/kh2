// Tz__JmWorldSel__Setup: menu page setup (fill the u16 attribute table, build 18 row pairs, then one row per
// eligible entry). Built with -fno-strict-aliasing -fmove-all-movables (_nsamam).
#include "../common/types.h"
extern "C" {
void func_00138c10(u8*, s32);
void func_00139620(u8*);
void func_00275a80(void);
void Tz__Jiminy__SetMainFrameLRMess(s32, s32);
void func_00276088(s32, s32*, s32*);
u8* func_00276348(void);
s8* func_00276568(void);
void func_00276588(s32);
u8* func_002766d0(void);
s32 func_00276c18(void);
s32 func_00287bc0(void);
void func_00287cc0(s32);
void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, u16*, u16*);
void func_00288e88(s32);
u8* func_002891b8(s32, s32);
void Tz__Select__SetCurrent(s32, s32, s32, s32, s32);
s32 func_0028af88(s32);
void func_0028af18(s32, s32);
void Tz__Select__SetSelectMax(s32, s32);
void func_0028b078(s32, s32, s32);
void func_0028b200(s32, s32);
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32);
void func_0028dcc0(u8*, u8*);
struct T294 { u8 pad[8]; s32 n; };
T294* func_00294000(s32);
s32 func_002941a8(s8*);
void func_00294998(void);
void Tz__JmWorldSel__FileAlloc(void);
void func_00294f78(s32);
s32 func_002952f8(s32);
void Tz__JmWorldSel__DrawUpdate(void);
s32 Tz__JmNewInfo__isWorldNew(s32);
s32 func_002acb20(s32);
s32 Tz__JmComplete__isWorldComp(s32);
extern s32 D_0035f148;
extern s32 D_0035f14c;
extern s32 D_0035f150;
extern u16 D150h asm("D_0035f150");
extern s32 D_0035f200;
extern s32 D_0035f210;
extern s32 D_0035f3d4;
extern s32 D_003746b4;
extern s32 D_003746b8;

struct Sub208 { u8 pad[184]; s32 flags; };
struct E408 { u8 pad[24]; Sub208 sub; u8 pad2[408 - 212]; };
struct B408 { u8 pad[30360]; E408 e[64]; };
void Tz__JmWorldSel__Setup(void);  // 0x002945e8: definition moved into src/anon/unit_00292e60.cpp
}
