#include "../common/types.h"
u8* func_002924d0(s32, s32);
void func_00292520(s32, u32, u32);
void func_002921d0(s32 a0, s32* a1, s32 a2, s32 a3, u8* t0) {
    u8* x = func_002924d0(a0, a2);
    u8* y = func_002924d0(a0, a3);
    s32 v = *(u16*)(t0 + 0x18a);
    *a1 = v - x[5] + y[5];
    func_00292520(a0, x[5], y[5]);
}
