/* 00223af8: shadow/marker draw (sibling of 002236d0). helper w3910, C++ -O2 -fno-strict-aliasing.
   Partial asm: the VU0 matrix block, two register pins ($14 for the anim table pointer and the
   scale word) and one empty asm use of ctl (lifts ctl over the anim/offset local for s1). */
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
struct PrtEnt64 { u8 pad0[48]; f32 pos[3]; f32 w; } __attribute__((aligned(16)));
extern PrtEnt64* D_00354688;
extern s32 D_0035468c;
void func_0021cda0(s32);
PrtReq* func_0021e988(void);
PrtReq* func_0021e998(void);
PrtReq* func_0021e9a8(void);
void func_0021cdd0(u8*, PrtReq*);
void func_001e7538(void);
void func_0020e0a0(void);


void func_00223af8(u32 idx, u8* rgba, u8 mode);  // 0x00223af8: definition moved into src/anon/unit_00222aa8.cpp
#undef anim
}
