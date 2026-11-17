#include "../common/types.h"
// 00246ab8: builds the menu sprite/layout objects for up to 4 entries.
extern "C" {
struct O6ab8 {
    u8 pad[24];
    u8 sub[384];
    u32 f198;
    u8 pad19c[20];
    s32 f1b0;
};
struct Q6ab8 { u8 d[408]; };
struct R6ab8 { u8 d[32]; };
struct M6ab8 {
    O6ab8 o[18];
    Q6ab8 q[16];
    R6ab8 r[9];
};
union U6ab8 { M6ab8* p; s32 i; u32 u; };
extern U6ab8 D_0035ed40;
extern void* D_0035ed20;
extern s32 D_0035ed28;
extern s32 D_0035f3d4;
extern s16 D_00371cc8[];
void func_002fde18(void*, s32, s32);
s32 func_00246968(s32);
void* func_002891b8(void*, s32);
s32 func_002891e8(void*);
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32);
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0028dcc0(void*, void*);
void func_00139620(void*);
void func_001395f8(void*);
u32 func_00192048(s32);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
void func_00138c68(void*, s32, s32);

void func_00246ab8(void);  // 0x00246ab8: definition moved into src/anon/unit_00242478.cpp

}

// 00223e98: draws animation idx n times along a line for each D_00354688 matrix entry.
#include "../common/types.h"

typedef unsigned int u128 __attribute__((mode(TI)));
typedef f32 FMTX[4][4] __attribute__((aligned(16)));

// Shared render-work types (same layout as batch_w1674_nsa.cpp).
struct PrtMtx { f32 m[4][4]; } __attribute__((aligned(16)));
struct PrtWork { u8 pad0[0x10]; FMTX world; u128 view[4]; };
struct PrtState { u8 pad0[0xa8]; u64 flags; };
struct PrtFrame { s16 dataOfs; s16 duration; s8 flags; u8 pad5[3]; };
struct PrtAnim { u8 pad0[6]; s16 count; u8 pad8[8]; PrtFrame frames[1]; };
struct PrtAnimRef { PrtAnim* anim; s32 x4; };
struct PrtBank { u8 pad0[0x14]; PrtAnimRef* anims; };
// Draw request (scratchpad packet header).
struct PrtReq { s32 type; s32 w4; f32 f8; s32 w12; s32 rgba[4]; u8 pad32[16]; u128 mtx[4]; };
// Shadow/marker entry: position; w is either 1.0f or 4 control bytes
// (alpha, frame, angle, scale).
struct PrtEnt { f32 pos[3]; f32 w; } __attribute__((aligned(16)));

extern "C" {
extern PrtWork* D_01d9e6e8;
extern PrtBank* D_01d9e6e4;
extern PrtState* D_01d9e6e0;
extern s32 D_01d9ea9c;
extern FMTX D_01d9e730;
extern FMTX D_01d9e8c0;
extern PrtMtx D_01d9ea40;
extern f32 D_00359a20[];
extern PrtEnt* D_00354680;
extern s32 D_00354684;
extern PrtMtx* D_00354688;
extern s32 D_0035468c;
void func_0021cda0(s32);
PrtReq* func_0021e988(void);
PrtReq* func_0021e998(void);
PrtReq* func_0021e9a8(void);
void func_0021cdd0(u8*, PrtReq*);
void func_001e7538(void);
void func_0020e0a0(void);

// VU0 macro code below is hand-written (no memory clobber, as in the original).
void func_00223e98(u32 idx, u8* rgba, u8 mode, s32 unused, u32 n, f32 scale, f32 len);  // 0x00223e98: definition moved into src/anon/unit_00222aa8.cpp
}
