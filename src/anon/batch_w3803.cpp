#include "../common/types.h"
extern "C" {
struct Slot272 { u8 p0[3]; s8 b3; u8 p4[7]; s8 bb; };
struct Pair272 { u16 a; u16 b; u16 c; u16 d; };
struct Rec272 { u16 a; u16 id; };
extern s32 D_0035f01c;
extern s32 D_0035f014;
extern u8* D_0035f12c;
extern s32 D_003739c4;
extern s32 D_003739c8;
extern u16 D_00373a80[];
extern u16 D_00373a90[];
extern Pair272 D_00373af8[];
s32 func_00287bc0(void);
u8* func_00257770(void);
s32 func_0028b040(s32);
s32 func_002570a0(s32);
s32 func_00272b60(s32);
Rec272* func_00273180(s32, s32);
u8* func_00273140(s32);
u8* func_00281f20(s32);
u8* func_001a80c8(u32);
u32 func_00192048(s32);
s32 func_00192c90(u32, u8*);
void func_00263a90(u8*, s32);
struct S2b2 { u8 pad[0x34]; s32 idx:8; u32 flag:1; u32 rest:23; };
struct I2b2 { u32 lo:26; u32 b26:1; u32 b27:1; u32 hi:4; };
struct L2b2 { s8 cols; s8 rows; s16 step; };
struct F2b2 { u32 b0:3; u32 b3:1; u32 b4:9; u32 b13:1; u32 hi:18; };
struct Sub2b2 { u8 pad[0xb8]; F2b2 f; };
struct O2b2 { u8 pad[0x18]; Sub2b2 sub; u8 pad2[0x195 - 0x18 - 0xbc]; u8 b195; u8 pad3[2]; };
extern S2b2* D_0035f638;
extern O2b2* D_0035f634;
extern s32 D_0035f3d4;
extern s32 D_0035f210;
extern const L2b2 D_00374cd0[];
void func_002b2428(s32);
s32 func_00292630(void);
u8* func_002766d0(void);
I2b2* func_002b23e0(s32);
void func_002b27c8(void);
s32 func_0023f1b0(s32);
s32 func_0023c4b8(s32, s32);
s32 func_0023f988(void*, s32);
void func_002362b0(void*, s32);
void func_001386e0(void*, s32, s32, void*, s32, s32);
void func_00139620(void*);
void func_0028dcc0(void*, void*);
void func_00138c68(void*, s32, s32);
void func_002b28b0(u32, s32, s32, void*);
void func_00239558(void*, void*, void*);
void func_002b1bd0(s32);
void func_002b2a18(void);
void func_002b2da8(s32);
void func_002b3050(s32);

}

extern "C" {
// Looks up the message id for the current menu mode and draws that message.
// Partial inline asm (asm_review.tsv): register pins for id/mode/has/k/t/i/o and one pinned subu.
void func_00272c90(void);  // 0x00272c90: definition moved into src/anon/unit_00271e08.cpp

// Builds a grid of menu entries (rows x cols from the D_00374cd0 layout table) and lays them out.
void func_002b24c8(void);  // 0x002b24c8: definition moved into src/anon/unit_002b1db8.cpp
}
