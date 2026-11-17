#include "../common/types.h"

extern "C" {
union W207U { s32 i; u8 c; };
struct W207P { s16 a; char pad[16]; s16 b; char pad2[4]; s16 c; };

void func_0017c870(f32, f32);
void func_0016bda8(void*) asm("_Z16ctarget_0016bda8jjjj");
void func_0017f488(void*, s32, f32, f32);
u32 func_002c5fa0(u32);

void func_0028b120(W207P* p, W207U* r, W207U* q, s32 x);  // 0x0028b120: definition moved into src/anon/unit_00288b00.cpp

u32 func_001b6f48(u32 a);  // 0x001b6f48: definition moved into src/anon/unit_001b6a50.cpp

u32 func_002c5fb8(f32* a);  // 0x002c5fb8: definition moved into src/anon/unit_002c53c8.cpp

u32 func_002c1950(u32 a, u32 b);  // 0x002c1950: definition moved into src/anon/unit_002c10e0.cpp
}
