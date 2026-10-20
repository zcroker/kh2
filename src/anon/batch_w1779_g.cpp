#include "../common/types.h"
extern "C" {
u32 func_00267248(void);
void func_002891f0(u32, s32, s32, s32, s32);
s32 func_0028afa8(u32);
s32 func_0028b040(u32);
extern u8* D_0035f0e4;
extern u8 D_0035f0e8;
void func_00267280(void) {
    u32 a, b;
    s32 sel, n;
    D_0035f0e8 = 1;
    a = func_00267248();
    D_0035f0e4[0x20] ^= 1;
    b = func_00267248();
    sel = func_0028b040(a);
    n = func_0028afa8(b);
    if (sel < n) func_002891f0(b, sel, 0, -1, -1);
    else func_002891f0(b, n - 1, 0, -1, -1);
}
}
