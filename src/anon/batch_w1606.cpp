#include "../common/types.h"
namespace w1606_27eb10 {
struct Ent { u8 pad0[0x694]; u8 g0[0x82c - 0x694]; u8 g1[0x13e4 - 0x82c]; char s0[8]; char s1[8]; char s2[8]; };
struct Sub { u8 pad[0xf]; u8 lv; };
struct Obj {
    s32 hp; s32 hpmax; u8 pad8[0x180 - 8]; s32 mp; s32 mpmax;
    u16 a188; u16 a18a; u16 a18c; u16 a18e; u8 pad190[0x1b0 - 0x190]; u8 b1b0; u8 b1b1;
    u8 pad1b2[0x244 - 0x1b2]; Sub* sub;
};
}
using namespace w1606_27eb10;
extern "C" {
s32 func_00281100(s32);
Obj* func_00281180(s32, s32);
void func_00192cc0(char*, const char*, ...);
void YI__SEQUENCE__SetScaleX(f32, u8*);
extern s32 D_0035f010;
extern Ent* D_0035f248;
extern u8 D_0035f24d;
extern s8 D_0035f24e;
extern char D_00373fd8[];
extern char D_00373fe0[];

void Tz__SimpleStat__UpdateNum(void);  // 0x0027eb10: definition moved into src/anon/unit_0027e920.cpp

void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, u16*, u16*);
u8* func_002891b8(s32, s32);
s32 func_0023aa78(u8*);
s32 func_0023aa98(u8*);
void Tz__Select__SetExOffset(s32, s32, s32, s32);
void func_00139620(u8*);
void func_0028af28(s32, s32);
void Tz__Select__SetCurrent(s32, s32, s32, s32, s32);
void Tz__Select__SetSelectMax(s32, s32);
extern s32 D_0035f3d4;
extern u16 D_0035f098[2][4];
extern u16 D_0035f0a8[];

void Tz__CmComm__CreateConfirmSelector(s32 o, s32 id, s32 a2, s32 a3, s32 a4, s32 two, u16* src);  // 0x00259108: definition moved into src/anon/unit_002588e8.cpp
}
