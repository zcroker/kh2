// 002afaf0 (w3694): built with -g -fno-strict-aliasing (_gnsa).
// Partial asm: register pins on a0/a1 of the 2nd func_0028d8c0 call only, to set the a1-before-a0 move order (sched1 tie). No code emitted.
#include "../common/types.h"
struct S638 { u8 pad[28]; s16 a[2]; s16 b[2]; s16 c; s16 d; u8 pad2[4]; s32 f44; s32 f48; u32 flags; };
struct Obj { union { u32 w; s16 h; }; u8 sub[4]; };
union U638 { S638* p; s16 h; u32 w; u8 c; };
extern "C" {
s32 func_00276348(void);
s32 func_002766d0(void);
Obj* func_002b23e0(s32);
void func_002b3420(s32);
void func_00276e78(void);
void func_0028d8c0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_0028d980(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00139620(s32);
void func_0028dcc0(s32, s32);
s32 func_0023aa98(s32);
void func_00138c68(s32, s32, s32);
void func_001395f8(s32);
s32 func_002b1aa0(void);
s32 func_00192048(s32);
void func_002b1af0(void);
void func_002b24c8(void);
void func_002b1a00(void);
void func_002766b0(s32);
void func_00287cc0(s32);
extern s32 D_0035f3d4;
extern s32 D_0035f14c;
extern s32 D_0035f148;
extern s32 D_0035f210;
extern U638 D_0035f638;
extern s32 D_0035f634;
extern s8 D_00374cd0[2][4];
extern s16 D_00374cc0[2];
void func_002afaf0(void);  // 0x002afaf0: definition moved into src/anon/unit_002af748.cpp


}
