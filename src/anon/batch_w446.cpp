#include "../common/types.h"
extern "C" {
extern s32 D_0035f024;
s32 func_00289380(s32);
s32 func_00287cd0(void);
void func_0026c470(void);
s32 func_0026d180(void);
void func_00287c30(void);
void func_0026c048(void);
void func_0028af18(s32, s32);
s32 func_00257610(s32);
void func_00287c90(s32);
s32 func_00289310(s32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_0026d168(void);
void func_00287c00(s32);
void func_0026c9f0(void) {
    s32 a = func_00289380(D_0035f024);
    s32 b = func_00287cd0();
    func_0026c470();
    if (b == 2) {
        if (func_0026d180() == 0) {
            func_00287c30();
            func_0026c048();
            func_0028af18(D_0035f024, 115);
        }
        return;
    }
    if (b == 0) {
        if (func_00257610(1)) func_00287c90(1);
    }
    if (b != 1) return;
    if (func_00242848(func_00287df0(a, func_00289310(D_0035f024), 0, 0, 1))) return;
    if (a == -2) goto L;
    if (a < -1) return;
    if (a == -1) return;
    if (a != 0) return;
L:
        func_0026d168();
        func_00287c00(20);
        func_00287c90(1);
}
}
