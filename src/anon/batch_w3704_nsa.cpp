#include "../common/types.h"

// u8 member: these u16 accesses may alias any store (the original was built without strict aliasing)
union W1650H { u16 v; u8 c; };
// 0x1b4-byte layout sprite (init by func_0028d980)
struct W1650Spr { u8 pad0[0x18]; u8 sub[0x180]; s32 x198; u8 pad19c[8]; u32 x1a4; s32 x1a8; s32 x1ac; s32 x1b0; };
// 0x198-byte layout element (init by func_0028d8c0)
struct W1650Lay { u8 pad0[0x198]; };
struct W1650Panel {
    W1650Spr a[4];      // 0x0000
    W1650Spr item[5];   // 0x06d0
    W1650Spr cnt[5];  // 0x0f54
    W1650Lay d[2];      // 0x17d8
    W1650H x1b08;
    char num[8];        // 0x1b0a
    char nums[5][8];    // 0x1b12
    s8 x1b3a;
    s8 x1b3b;
};
struct W1650Work { u8 pad0[0x18]; u8 sub[0x318]; W1650Lay x330; u8 pad4c8[0x110a0 - 0x4c8]; char names[10][64]; };
struct W1650List { u8 pad0[4]; s8 x4; s8 count; u8 pad6[2]; s16 ids[0x80]; char name[64]; };
struct W1650Ent { u8 pad0[2]; s8 x2; u8 pad3[3]; u16 x6; u16 x8; W1650H xa; u16 xc; u8 pade[2]; W1650H flags; };
struct W1650Item { u8 pad0[8]; s32 x8; };
struct W1650Tbl { u16 x0; u16 ids[5]; };
struct W1650Def { u8 pad0[0x4c]; u16 x4c; };

extern "C" {
void* func_002766d0(void);
s32 func_00276638(s32);
W1650Ent* func_0029da68(s32);
void* func_00276348(void);
s32 func_00287bc0(void);
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32);
void func_00139620(void*);
void func_001395f8(void*);
void func_0028dcc0(void*, void*);
s32 func_00192048(s32);
s32 Tz__JmWorldSel__GetId2WorldName(s32, s32);
void func_00192e50(s32, char*, s32, s32);
void func_002595e8(char*, s32);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
s32 func_0023aa58(void*);
s32 func_0023aa78(void*);
s32 func_00276c38(s32);
s32 func_00192cc0(char*, char*, s32);
s32 func_00294368(W1650Ent*);
void func_00138c68(void*, s32, s32);
s32 func_00192b80(s32);
void Tz__Select__SetSelectMax(void*, s32);
void Tz__Select__SetCurrent(void*, s32, s32, s32, s32);
void func_0028afd0(void*, s32);
void Tz__Select__SetPageMode(void*, s32);
void func_0028b248(void*, s32);
void func_002fde18(void*, s32, s32);
W1650Def* func_0016e920(s32);
W1650Tbl* func_001d23e0(s32);
W1650Item* YS__COMMAND_ELEM__Get(s32);
s32 func_001b90a8(W1650Item*);
s32 func_00276c18(void);
s32 Tz__MenuUtil__MakeQuestionStr(s32, char*, s32);
extern W1650List* D_0035f5ac;
union W1650PanelPtr { W1650Panel* p; u8 c; };
extern W1650PanelPtr D_0035f5b0;
extern s32 D_0035f3d4;
extern s32 D_0035f14c;
extern s32 D_0035f148;
extern s32 D_0035f210;
extern void* D_0035f200;
extern s16 D_00374ae0[];
extern char D_003749e8[];

void func_0029d318(void);  // 0x0029d318: definition moved into src/anon/unit_0029d008.cpp
}
