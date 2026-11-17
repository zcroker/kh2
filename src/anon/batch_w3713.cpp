#include "../common/types.h"

struct G2_1eaee0 { u8 pad[0x40]; f32 x, y, z; };
union U2_1eaee0 { G2_1eaee0* p; u32 u; u8 c; };

extern "C" {
void sceVu0UnitMatrix(void*);
extern U2_1eaee0 D_01d9e6e8;

// Copies the owner's 3-float vector at +0xa0 into the global object's x/y/z (after sceVu0UnitMatrix on it).
// Partial asm: the pointer to the vector is formed by one asm addiu pinned to t5 with a "memory"
// clobber, so the float load comes first and the next global reload waits for it (closest C: 6 diffs,
// t6/t7 swapped and ld s0/ra order).
void func_001eaee0(s32 a0, s32 a1, u32** a2);  // 0x001eaee0: definition moved into src/anon/unit_001e8ac8.cpp
}
