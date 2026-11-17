#include "../common/types.h"

struct In171 { u32 x0; u32 x4; };
struct R171 { u32 x0, x4, x8, xc, x10, x14; };
struct A171 { In171* p0; In171* p4; u32 p8; u32 pc; u32 p10; u32 p14; };
extern u32 D_0034d8a0;

extern "C" {
R171* u_tail4(u32, u32, u32, u32) asm("_Z16u_tail4_001c0d38jjjj");

// Creates an entry via u_tail4 and, when a->p10 is set, fills its fields 0xc/0x10/0x14.
void func_00171c60(A171* a);  // 0x00171c60: definition moved into src/anon/unit_00170f58.cpp
}
