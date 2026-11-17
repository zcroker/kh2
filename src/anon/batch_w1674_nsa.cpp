#include "../common/types.h"
typedef f32 FMTX206[4][4] __attribute__((aligned(16)));
struct Work206b { u8 pad0[0x10]; FMTX206 world; FMTX206 view; };
struct State206b { u8 pad0[0xa8]; u64 flags; };
struct Frame206b { s16 dataOfs; s16 duration; s8 flags; u8 pad5[3]; };
struct Anim206b { u8 pad0[6]; s16 count; u8 pad8[8]; Frame206b frames[1]; };
struct AnimRef206b { Anim206b* anim; s32 x4; };
struct Bank206b { u8 pad0[0x14]; AnimRef206b* anims; };
struct DrawParam206b {
    u16 x00;
    u16 flags;          // 0x02
    u8 rgba[4];         // 0x04
    u32 x08[2];            // 0x08
    f32 (*viewMtx)[4];  // 0x10
    u8* packet;         // 0x14
    s8 x18;             // 0x18
    u8 pad19[3];
    f32 (*localMtx)[4]; // 0x1c
    u8 pad20[0x10];
};
struct Elem206b {
    u8 pad0[8];
    s32 anim;       // 0x08
    u16 speed;      // 0x0c
    u8 pad0e[2];
    u8 x10;         // 0x10
    u8 x11;         // 0x11
    u8 hasOffset;   // 0x12
    u8 pad13;
    f32 offset[3];  // 0x14
    u8 pad20[0x10];
    f32 scale[3];   // 0x30
    u8 rgb[3];      // 0x3c
    u8 alpha;       // 0x3f
    u8 periodA;     // 0x40
    u8 periodB;     // 0x41
    u8 pad42;
    u8 flicker;     // 0x43
    u8 x44;         // 0x44
};
struct Slot206b {
    f32 pos[4];
    Elem206b* elem;     // 0x10
    u8 pad14[4];
    u16 time;           // 0x18
    u16 frame;          // 0x1a
    u8 timerA;          // 0x1c
    u8 timerB;          // 0x1d
    u16 decay;          // 0x1e
    s32 phase;          // 0x20
    u8 pad24[0xc];
};
struct List206b { u8 pad0[8]; u32 count; u8 padc[8]; Slot206b* slots; };
extern "C" {
extern Work206b* D_01d9e6e8;
extern Bank206b* D_01d9e6e4;
extern State206b* D_01d9e6e0;
extern s32 D_01d9ea9c;
extern u8* D_01d9eaa4;
extern FMTX206 D_01d9e730;
extern FMTX206 D_01d9e8c0;
extern f32 D_00359a20[];
void sceVu0ApplyMatrix(f32* out, f32 (*m)[4], f32* in);       // sceVu0ApplyMatrix
void sceVu0MulMatrix(f32 (*out)[4], f32 (*a)[4], f32 (*b)[4]); // sceVu0MulMatrix
void sceVu0CopyVector(f32* out, f32* in);                  // sceVu0CopyVector
void sceVu0CopyMatrix(f32 (*out)[4], f32 (*in)[4]);         // sceVu0CopyMatrix
void sceVu0UnitMatrix(f32 (*m)[4]);                        // sceVu0UnitMatrix
u8* func_0021d048(u8* data, DrawParam206b* p, s32 x);

void func_00206be8(List206b* list);  // 0x00206be8: definition moved into src/anon/unit_00206be8.cpp
}
