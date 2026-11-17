#include "../common/types.h"
extern "C" {
struct O { u8 pad[0x188]; s32 a; u8 p2[0x20]; s32 b; };
struct T { s16 a; s16 b; s16 c; };
O* func_0028c198(s32, s32, s32, s32, s32, s32);
void func_00288ce0(s32, O*, s32, T*, s32);
// Empty asm and pin keep the first lh in its own pseudo (t7), which sched1 issues in the prologue.
void func_00288d80(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, T* t2, s32 t3);  // 0x00288d80: definition moved into src/anon/unit_00288b00.cpp
}
