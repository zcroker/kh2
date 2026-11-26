// 002b2a18: sets up three entries of a widget table (two in a loop, one after it).
// Built with -fmove-all-movables (_mam). Partial asm (logged in asm_review.tsv):
// - st and the constant 1 are pinned to s6/s7 (global-alloc priority otherwise puts the table pointer there);
// - the table's high half comes from a one-instruction `lui` asm tied to the D_0035f3d4 load, so it is
//   issued after that load and reuses t7 like the original.
#include "../common/types.h"
struct St2b2a18 { u32 pad:27; u32 bit:1; u32 pad2:4; };
extern "C" {
extern u8* D_0035f634;
extern s32 D_0035f3d4;
extern s32 D_0035f14c;
extern s32 D_0035f148;
extern s32 D_0035f210;
extern s16 D_00374cc8[];
extern s16 D_00374cd8[];
u8* func_002766d0(void);
St2b2a18* Tz__JmPuzzle__GetImageInfo(s32);
void func_00139d78(u8*);
s32 func_0023f1b0(s32);
s32 func_0023c4b8(s32, s32);
void dk__Sprite__create(u8*, s32, s32, u8*, s32, s32);
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32);
void func_00139620(u8*);
void func_0028dcc0(u8*, u8*);
void func_00139570(u8*);
}

extern "C" {
void func_002b2a18(void);  // 0x002b2a18: definition moved into src/anon/unit_002b2a18.cpp

}
