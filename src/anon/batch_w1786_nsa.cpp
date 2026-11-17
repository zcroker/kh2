#include "../common/types.h"

struct W1786Q4 { u8 pad[8]; s32 x; };
struct W1786S350 { void (*fn)(s32, u32, s32); W1786Q4* p; s32 a; u32 b; s32 c; };
struct W1786Vn { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W1786A1fb { u8 pad[0xc]; s32* p; };

extern "C" {
void FlushCache(s32);
s32 func_002f7dc8();
extern W1786S350 D_00350cb0;
void func_001adc48(s32 x);  // 0x001adc48: definition moved into src/anon/unit_001ada38.cpp

void func_001fa668(u8*, s32, void*);
void W1786_wtarget(W1786Vn*, void*, W1786Vn*) asm("_Z17sceVu0ApplyMatrixjjjj");
void sceVu0ScaleVector(void*, W1786Vn*, f32);
void func_001faea8(void*, s32, s32);
extern u8* D_01d9e6e8;
void func_001fb3c8(u8* a0, s32 a1, W1786A1fb* a2);  // 0x001fb3c8: definition moved into src/anon/unit_001fb350.cpp
}
