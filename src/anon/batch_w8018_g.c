#include "../common/types.h"
extern s32 D_0035f200;
s32 func_00275e68(s32, s32, s32);
s32 func_00275ec8(s32);
s32 func_002766d0();
s32 func_0028b040(s32);
s32 func_0028de08(s32, s32, s32);
s32 func_00295270(s32, s32);
s32 func_002956c0(s32);
void func_00295508(void) {
    s32 base = func_002766d0();
    s32 v = func_0028b040(D_0035f200);
    s32 s2 = func_00295270(v, 0);
    s32 p;
    if (func_002956c0(v) != 0) {
        func_00275e68(s2, base + 0x110A0, 0x40);
        return;
    }
    p = base + 0x110A0;
    p = func_0028de08(s2, p, 0x40);
    func_00275ec8(p);
}
