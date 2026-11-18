#include "../common/types.h"
extern "C" {
void func_002f4028(u32, u32, u32, u32);

// Hand-written VU0 macro code (saves ra in a2 around the jal, trapping addi loop); kept as asm.
void sceVu0RotMatrixZ(void* dst, const void* src, f32 angle);  // 0x002f40a0: definition moved into src/sdk/libvu0_002f3cd8.s
}
