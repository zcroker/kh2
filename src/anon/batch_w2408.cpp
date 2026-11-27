#include "../common/types.h"
// helper w2408 2026-10-26: 0027b248 (b0e ? flag : !flag test, separate la/lb locals), 002a5df0 (do-while with ++i < n && k < 10, v reused for the ternary).
extern "C" {
struct W2408Ent { u8 pad[0xe]; s8 b0e; u8 pad2[2]; s8 b11; };
void func_00138c10(u8*, s32);
void func_00139570(u8*);
void func_00139580(u8*);
void func_00139d78(u8*);
s32 func_00192cc0(u8*, u32*, ...);
void YI__SEQUENCE__SetScaleX(f32, u8*);
void func_0023aa58(u8*);
s32 func_002570a0(s32);
u8* func_00257770(void);
void func_0027aed8(s32, s32*, s32*);
s32 func_00287bc0(void);
s32 func_0028b040(s32);
s32 func_002fd178(s32);
extern s32 D_0035f01c;
extern u8* D_0035f230;
extern u32 D_00373de8;
extern s32 D_00373df4;
extern s32 D_00373df8;

void func_0027b248(s32 arg0);  // 0x0027b248: definition moved into src/anon/unit_0027a6d8.cpp

struct W2408Name { u8 c[16]; };
struct W2408Rec { u16 h0; u16 h2; };
u8* func_002766d0(void);
s32 func_0028b038(s32);
void Tz__ScrollBar__SetPos(s32, s32);
void func_002fde18(u8*, s32, s32);
W2408Rec* func_002a6368(s32);
s32 func_002944d0(W2408Rec*);
s32 func_001d44d8(u16);
s32 func_001d4550(s32);
s32 func_00192048(u16);
void func_00192c90(s32, u8*);
void Tz__MenuUtil__MakeQuestionStr(u16, u8*, s32);
u8* func_002891b8(s32, s32);
s32 func_00192b30(s32);
s32 func_002aaa38(s32);
s32 func_002aaab8(s32);
extern s32 D_0035f200;
extern s32 D_0035f214;
extern u8* D_0035f5ec;
extern u32 D_00374ba8;
extern s32 D_00374bd8;
extern s32 D_00374bdc;

void func_002a5df0(void);  // 0x002a5df0: definition moved into src/anon/unit_002a5a90.cpp
}
