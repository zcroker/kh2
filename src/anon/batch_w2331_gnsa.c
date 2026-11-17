#include "../common/types.h"

/* Plain C (partMng family), built without strict aliasing. -g makes no difference here; the name is _gnsa
   only because batch_wcx2_nsa.c / _gnsa.c would share an object name with the workspace .cpp files. */

/* 001fa2b0: particle position integrate, then build and submit a sprite render request. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V1fa2b0;
typedef struct {
    V1fa2b0 a;
    V1fa2b0 col;
    void* p32;
    u32 w36;
    void* p40;
    s32 w44;
    V1fa2b0 b;
    u64 q64;
    u64 q72;
    u64 q80;
    f32 f88;
    f32 f92;
} Req1fa2b0;
typedef struct { s32 f0; f32 f4, f8, f12, f16, f20; u8 b24; u8 b25; } Ent1fa2b0;
typedef struct { u8 pad0[12]; s32* off; } Ctx1fa2b0;
typedef struct { u8 pad0[168]; u64 flags; } Cur1fa2b0;
extern s32 D_01d9ea9c;
extern Cur1fa2b0* D_01d9e6e0;
extern u8 D_01d9e8c0[];
extern u32 D_01d9eaa4;
extern u32 D_01d9eaa8;
extern f32 D_00354be0[];
extern s32 D_00352be4, D_00352be8, D_00352bec, D_00352bf0, D_00352bf8, D_00352bfc;
extern u64 D_00352c18;
void sceVu0ApplyMatrix(V1fa2b0*, V1fa2b0*, V1fa2b0*);
void func_00222f88(Req1fa2b0*);
s32 func_002231b8(Req1fa2b0*);
void func_0020e7a8(u32, u32, s32, s32);
void func_0020e858(u32, u32, s32, s32);
void func_001fa2b0(u8* base, Ent1fa2b0* e, Ctx1fa2b0* c);  // 0x001fa2b0: definition moved into src/anon/unit_001fa1b8.cpp
