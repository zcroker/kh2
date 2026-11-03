#include "../common/types.h"

struct G2_1eaee0 { u8 pad[0x40]; f32 x, y, z; };
union U2_1eaee0 { G2_1eaee0* p; u32 u; u8 c; };

extern "C" {
void func_002f4000(void*);
extern U2_1eaee0 D_01d9e6e8;

// Copies the owner's 3-float vector at +0xa0 into the global object's x/y/z (after func_002f4000 on it).
// Partial asm: the pointer to the vector is formed by one asm addiu pinned to t5 with a "memory"
// clobber, so the float load comes first and the next global reload waits for it (closest C: 6 diffs,
// t6/t7 swapped and ld s0/ra order).
void func_001eaee0(s32 a0, s32 a1, u32** a2) {
    u8* p = (u8*)(a0 + **(s32**)((u8*)a2 + 0xc));
    func_002f4000((u8*)D_01d9e6e8.p + 0x10);
    f32 f = *(f32*)(p + 0xa0);
    register f32* v asm("$13");
    asm("addiu %0,%1,160" : "=r"(v) : "r"(p) : "memory");
    D_01d9e6e8.p->x = f;
    D_01d9e6e8.p->y = v[1];
    D_01d9e6e8.p->z = v[2];
}
}
