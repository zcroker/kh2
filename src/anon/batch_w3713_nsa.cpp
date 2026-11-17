#include "../common/types.h"
struct V6148 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct St6148 { u8 pad[0x80]; u8* tbl; };
struct A6148 { u8 pad[8]; f32 f8; u8 p0[4]; s32 f10; s32 f14; u8 p1[4]; s32 f1c; u8 p2[4]; s32 f24; };
struct R6148 { u8 pad[4]; s32 f4; };
extern "C" {
extern St6148* D_01d9e6e0;
extern u8* D_01d9e6e8;
R6148* func_001e7a98(St6148*, u8*);
void sceVu0ApplyMatrix(void*, void*, void*);
void func_002226b8(void*, void*);
void sceVu0SubVector(void*, void*, void*);
void sceVu0Normalize(void*, void*);
void sceVu0ScaleVector(void*, void*, f32);
// Spawns an effect object from the manager table and runs a point through three matrix stages,
// storing results into three of the object's slots.
void func_001f6148(s32 a0, A6148* a, s16* pos);  // 0x001f6148: definition moved into src/anon/unit_001f5978.cpp
}
