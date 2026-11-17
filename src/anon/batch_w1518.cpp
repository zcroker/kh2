#include "../common/types.h"

extern "C" {
u8* func_001bfd60(u8*, s32);
void func_001ad990(u8*, f32, f32, f32);

struct Col1945 { u8 r, g, b, a; };

// Allocates an entry from the list at +0x8e0, stores its packed RGBA colour and sets it up.
void func_001945a0(u8* a, f32 f, s32 b, u32 c);  // 0x001945a0: definition moved into src/anon/unit_00193be8.cpp
}
