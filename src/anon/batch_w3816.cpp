#include "../common/types.h"
extern "C" {
struct Ent8 { u8 pad[8]; s16 h; };
u8* func_00257770(void);
void func_00139d78(u8*);
s32 func_0028b038(s32);
void Tz__ScrollBar__SetPos(s32, s32);
s32 func_00257070(s32);
void func_002713a0(s32, s8**, s32*);
s32 func_00257140(s32);
s32 func_002892f8(s32);
u8* func_002891b8(s32, s32);
void func_0028b040(s32);
s32 func_00257158(s32, s32, s32);
void func_00138c10(u8*, s32);
s32 func_00272c20(s32);
s32 func_00192048(u32);
s32 func_00286068(s32);
s32 func_00286160(s32);
extern s32 D_0035ef6c;
extern s32 D_0035f01c;
extern s32 D_0035f04c;
extern u8* D_0035f12c;
extern s8* D_01e21ed8;
extern s32 D_003739ec;
extern s32 D_003739f0;
extern s16 D_003739f8[];
extern s16 D_00373a08[];
extern u16 D_00373a18[];
extern u16 D_00373a28[];

// Sets up the 9 sprite rows and fills them from the current list.
void func_00271ee8(void);  // 0x00271ee8: definition moved into src/anon/unit_00271e08.cpp

extern s32 D_0035ed20;
extern u8* D_0035ed40;
extern u8 D_00371ab8[];
extern u8 D_00371ac0[];
extern u8 D_00371cb8[];
extern u8 D_00371cc0[];
s32 func_002891e8(s32);
s32 func_002474e0(s32);
void func_0028dcc0(void*, void*);
void func_002fde18(void*, s32, s32);
s32 func_00105c30(void);
s32 func_00192cc0(u8*, u8*, s32);
s32 func_00192b30(s32);
void func_00192c90(s32, u8*);
s32 func_00192c40(s32, u8*);
s32 func_0023aa98(void*);
s32 func_002469a0(s32);
s32 func_00246840(void);
void func_00138c68(void*, s32, s32);
u32 func_0028af88(s32);
void func_0028af18(s32, u32);
// true for the Japanese-style layouts (system language 1 or 8)
static inline u8 isjp() { u8 r = 0; if (func_00105c30() == 1 || func_00105c30() == 8) r = 1; return r; }
// Refreshes the selection rows and the gauge/caption of the selected entry.
void Tz__HECO__UpdateMaker(u8 flag);  // 0x00247580: definition moved into src/anon/unit_00242478.cpp
}
