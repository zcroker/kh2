#include "../common/types.h"
// Owner batch 2026-10-21: functions that needed layout.tsv splits (001e03b0..001e03d8, 0014b290/0014b2c8)
// and the hand-written VU0 rotation routines 002f4148/002f41f0.
extern "C" {

// 001e03b0, 001e03c8, 001e03d0, 001e03d8 (PadWave): moved to src/anon/unit_001e0398.cpp

// ---- 0014b290 / 0014b2c8: two identical copies (C1/C2 of one constructor)
void func_0014b150(void*);
void func_0014b300(void*);
extern u8 D_00349b40[];
void dk__RectBase__createPacket(u32* self, u32, u32, u32) asm("_Z26dk__RectBase__createPacketjjjj");
// 0014b290: moved to src/anon/unit_0014b150.cpp
// 0014b2c8: moved to src/anon/unit_0014b150.cpp

// Hand-written VU0 macro code (libvu0-style rotation matrix: calls func_002f4028
// with a non-standard convention, saves ra in a2, trapping addi); kept as asm.
void sceVu0RotMatrixX(u32, u32, f32);  // 0x002f4148: definition moved into src/sdk/libvu0_002f3cd8.s

// Sibling of sceVu0RotMatrixX (rotation about another axis); hand-written, kept as asm.
void sceVu0RotMatrixY(u32, u32, f32);  // 0x002f41f0: definition moved into src/sdk/libvu0_002f3cd8.s

}
