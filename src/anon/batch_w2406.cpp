#include "../common/types.h"
struct Msg246 { u8 pad[26]; s16 id; u8 pad2[8]; };
struct Ent246 { u8 pad[4]; s16 f4; };
extern "C" {
extern s32 D_0035ed30;
extern s32 D_0035ed38;
extern Msg246 D_00371c50[];
extern u8 D_00371ca8[];
extern u8 D_00371cb0[];
s32 func_00287cd0(s32);
s32 func_00289310(s32);
s32 func_002891e8(s32);
void func_002890e0(s32, s32, s32, s32, s32);
void func_00289038(s32, s32, s32, s32, s32, s32, s32);
s32 func_002469a0(s32);
Ent246* func_002468a0(s32);
void func_0023f070(s32, s32, s32);
void Tz__HECO__UpdateMaker(s32);
void func_00247c20(void);
Msg246* func_00246868(void);
s32 func_002474e0(s32);
s32 func_00246840(void);
void func_002b4388(s32, void*, s32);
static inline u8 w2406_menuFlag(s32 k) { if (func_00246840()) return D_00371cb0[k]; return D_00371ca8[k]; }

void func_00246490(s32 a, s32 b);  // 0x00246490: definition moved into src/anon/unit_00242478.cpp
}
