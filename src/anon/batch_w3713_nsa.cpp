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
void func_001f6148(s32 a0, A6148* a, s16* pos)
{
    St6148* st = D_01d9e6e0;
    u8* e = st->tbl + a->f10 * 16;
    R6148* r = 0;
    if (e) { r = func_001e7a98(st, e); r->f4 = a0; }
    V6148 v; v.x = pos[0]; v.y = pos[1]; v.z = pos[2]; v.w = 1.0f;
    u8* p0 = (u8*)r + a->f14 + 160;
    u8* p2 = (u8*)r + a->f1c + 160;
    u8* p1 = (u8*)r + a->f24 + 160;
    sceVu0ApplyMatrix(&v, D_01d9e6e8 + 16, &v);
    func_002226b8(p0, &v);
    sceVu0SubVector(&v, &v, D_01d9e6e8 + 64);
    sceVu0Normalize(&v, &v);
    func_002226b8(p1, &v);
    sceVu0ScaleVector(&v, &v, a->f8);
    func_002226b8(p2, &v);
}
}
