#include "../common/types.h"

// YS::EFFECT file tail (0x1a3d70-0x1a3e70): the static initialiser / teardown of the effect work
// (0x1c6cae0, a ryj::PAX, and the 4+1 words at 0x1c6cb00, all defined in effect.cpp) and its
// _GLOBAL__I_ / _GLOBAL__D_ stubs, as plain functions. The function at 0x1a3e70 starts the next file.

void func_001ddd10(void*);
void func_001ddd88(void*);
extern u8 D_01c6cae0[];
extern u32 D_01c6cb00[];
void wtarget_001a3d70(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) func_001ddd10(D_01c6cae0);
    if (a1 == 0xffff && a0 == 1) {
        u32* base = D_01c6cb00;
        u32* q = base;
        for (s32 i = 3; i >= 0; i--) *q++ = 0;
        base[4] = 0;
    }
    if (a1 == 0xffff && a0 == 0) func_001ddd88(D_01c6cae0);
}

// 0x1a3e30: the _GLOBAL__I_ stub.
u32 func_001a3d70(u32, u32, u32, u32);
extern "C" u32 func_001a3e30(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001a3d70(0x00000001u, 0x0000ffffu, a2, a3);
}

// 0x1a3e50 (not in the layout): the _GLOBAL__D_ stub.
extern "C" u32 func_001a3e50(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001a3d70(0x00000000u, 0x0000ffffu, a2, a3);
}
