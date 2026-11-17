#include "../common/types.h"

// ---- 001ef8e0: pull a node toward another along the normalized offset (VU0 macro normalize, asm)
extern "C" {
struct Body1987 { f32 x, y, z, r; f32 f10, f14, f18; };
struct Nd1987 { u8 pad[160]; Body1987 b; };
struct Te1987 { s32 f0; s32 p; s32 f8, fc; };
struct Mgr1987 { u8 pad[128]; Te1987* tbl; };
struct Ent1987 { s32 f0; s32 idx1; s32 off1; s32 idx2; s32 off2; f32 f14; };
struct Ent21987 { u8 pad[12]; s32* offs; };
struct V41987 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern Mgr1987* D_01d9e6e0;
extern Body1987 D_01d9e360;
f32 sceVu0InnerProduct(Body1987*, V41987*);
void func_001ef8e0(u8* base, Ent1987* e, Ent21987* e2);  // 0x001ef8e0: definition moved into src/anon/unit_001ef780.cpp
}
