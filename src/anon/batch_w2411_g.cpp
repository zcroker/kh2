#include "../common/types.h"
extern "C" {
u8* jm_parent(void) asm("_ZN2Tz6Jiminy9GetParentEv");
u8* jm_seqtbl(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
u8* jm_scrbar(void) asm("_ZN2Tz6Jiminy15GetScrBarSeqTblEv");
s32 func_0028f930(s32);
void func_0028f4d8(s32, s32, s32);
void Tz__Jiminy__CreateCover(void);
void pz_cfo(void*, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz5Pause16CreateFadeObjectEz");
void obj_xyoff(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void mc_as(void*, void*) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
void* lay_get(s32) asm("_ZN2Tz6Layout9getLayoutEv");
s32 yi_unit(void*, s32) asm("_ZN2YI6LAYOUT15GetSequenceUnitEi");
s32 yi_img(void*, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void func_0028bae0(s32, s32, s32, s32, u8*, s32, s32, u8*, s32);
void sel_set(s32) asm("_ZN2Tz8Selector8SetStateEi");
extern s32 D_0035f3d4;
extern s32 D_0035f14c;
extern s32 D_0035f148;
extern s32 D_0035f210;
extern s32 D_0035f214;
struct Lay77 { u8 pad[40]; void* img; };

void Tz__JmMiniGame__ChkMGameInfo(void);
void Tz__JmMiniGame__CreateList(void);
void Tz__JmMiniGame__AdjustPos(void);
void Tz__JmMiniGame__UpdateNewMark(void);
void Tz__JmMiniGame__UpdateList(void);
void func_002a8748(void);
void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, s16*, s16*);
void* sel_item(s32, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
void Tz__Select__SetSelectMax(s32, s32);
void Tz__Select__SetCurrent(s32, s32, s32, s32, s32);
void func_0028afd0(s32, s32);
void jm_hide(s32) asm("_ZN2Tz6Jiminy13SetHideCursorEb");
void sel_dis(s32, s32) asm("_ZN2Tz6Select16SetDisableButtonEj");
void Tz__Select__SetPageMode(s32, s32);
void func_0028b248(s32, s32);
extern s32 D_0035f200;
extern s32* D_0035f600;
static inline s32 GetImg77(s32 i, void* self) { return yi_img(self, i); }
void Tz__JmMiniGame__Setup(void);  // 0x002a77a0: definition moved into src/anon/unit_002a7308.cpp
}
