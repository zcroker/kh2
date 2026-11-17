#include "../common/types.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V1f7b40;
typedef struct {
    u64 q0;
    u64 q8;
    void* p16;
    f32* p20;
    s32 w24;
    s32 w28;
    s32 w32;
    s32 w36;
    u64 q40;
    V1f7b40* p48;
    V1f7b40* p52;
    s32 w56;
    s32 w60;
    s32 w64;
    s32 w68;
} Req1f7b40;
typedef struct { s32 f0; s32 set; f32 f8, f12, f16; u8 b20; u8 b21; } Ent1f7b40;
typedef struct { u8 pad0[12]; s32* off; } Ctx1f7b40;
typedef struct { u8 pad0[16]; u8* sets; } Res1f7b40;
typedef struct { u8 pad0[168]; u64 flags; } Cur1f7b40;
typedef struct { u8 pad0[144]; s32 p144; } Ovr1f7b40;
extern s32 D_01d9ea9c;
extern Cur1f7b40* D_01d9e6e0;
extern Res1f7b40* D_01d9e6e4;
extern Ovr1f7b40* D_01d9e6e8;
extern u8 D_01d9e8c0[];
extern s32 D_01d9eaa4;
extern s32 D_01d9eaa8;
extern f32 D_00354be0[];
extern s32 D_00352be4, D_00352be8, D_00352bec, D_00352bf0, D_00352bf8, D_00352bfc;
extern u64 D_00352c18;
void sceVu0ScaleVector(V1f7b40*, V1f7b40*, f32);
void func_001f7e90(Req1f7b40*);
void func_001f7b40(u8 *base, Ent1f7b40 *e, Ctx1f7b40 *c);  // 0x001f7b40: definition moved into src/anon/unit_001f7b40.cpp
