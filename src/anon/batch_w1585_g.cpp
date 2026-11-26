#include "../common/types.h"
extern "C" {
void* tz_lsys(void) asm("_ZN2Tz17LoadDataGetSystemEv");
void* menu_alloc(void) asm("_ZN4MENU15GetObjAllocatorEv");
void* tz_alloc(u32, void*) asm("_ZN2Tz13LoadDataAllocEjj");
void func_00324448(void*);
void func_003241a0(void*);

/* 002a1f88 */
struct E8 { u32 a, b; };
struct Big { u8 pad[0x108c]; E8 e[10]; };
extern Big* D_0035f5e4;
extern void* D_0035f5e8;
void Tz__JmTreasure__Init(void);  // 0x002a1f88: definition moved into src/anon/unit_002a1d38.cpp

/* 002a7678 */
extern void* D_0035f600;
extern void* D_0035f604;
void func_002a7678(void);  // 0x002a7678: definition moved into src/anon/unit_002a7308.cpp

/* 002a21b0 */
u8* jm_parent(void) asm("_ZN2Tz6Jiminy9GetParentEv");
u8* jm_seqtbl(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
u8* jm_scrbar(void) asm("_ZN2Tz6Jiminy15GetScrBarSeqTblEv");
s32 func_002a43f0(void);
void func_002a2a80(void);
void func_002a2c40(void);
s32 func_0028f930(s32);
void func_0028f4d8(s32, s32, s32);
void Tz__Jiminy__CreateCover(void);
void pz_cfo(void*, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz5Pause16CreateFadeObjectEz");
void obj_xyoff(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void mc_as(void*, void*) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
void func_002a3ba8(void);
void* lay_get(s32) asm("_ZN2Tz6Layout9getLayoutEv");
s32 yi_unit(void*, s32) asm("_ZN2YI6LAYOUT15GetSequenceUnitEi");
s32 yi_img(void*, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void func_0028bae0(s32, s32, s32, s32, u8*, s32, s32, u8*, s32);
void Tz__JmTreasure__AdjustCurPos(void);
void Tz__JmTreasure__UpdateNewMark(void);
void func_002a3910(void);
void sel_set(s32) asm("_ZN2Tz8Selector8SetStateEi");
extern s32 D_0035f3d4;
extern s32 D_0035f14c;
extern s32 D_0035f148;
extern s32 D_0035f210;
extern s32 D_0035f214;
struct Lay { u8 pad[40]; void* img; };
struct BigV { u8 pad[0x1080]; s32 v; };
struct H2 { s16 v; H2() : v(2) {} };
void Tz__JmTreasure__Setup(void);  // 0x002a21b0: definition moved into src/anon/unit_002a1d38.cpp

/* 002a2600 */
s32 mb_mode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
void func_002a2de8(void);
s32 func_002b3b60(s32);
void Tz__JmTreasure__SetupPieceInfo(void);  // 0x002a2600: definition moved into src/anon/unit_002a1d38.cpp
}
