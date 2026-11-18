// 001c70e8: sets D_01d498d0.c = (55, 55, 55, 0), the 4-bit field at bits 3-6 of the flags word to 6,
// v = 60.0f and flags |= 1. Built with -fno-schedule-insns. Partial asm: 55.0f held through an empty asm
// (loaded first), and an empty asm output pinned to $15 that is live until the 60.0f load, so that pool
// address goes to t6 after the bitfield store (as in the original).
#include "../common/types.h"
struct Vq { f32 x, y, z, w; } __attribute__((aligned(16)));
struct G { Vq a, b, c, res; u8 pad40[0x2c]; f32 v; u64 flags; };
extern G D_01d498d0;
extern u32 D_w asm("D_01d49940");
extern "C" {
void func_001c70e8(void);  // 0x001c70e8: definition moved into src/anon/unit_001c70e8.cpp
}
