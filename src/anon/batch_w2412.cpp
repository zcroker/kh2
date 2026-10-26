#include "../common/types.h"
extern "C" {
extern s32 D_0035f200;
extern u8 D_0035f5a0;
s32 func_00289380(s32);
s32 func_00287cd0(void);
s32 func_00287bc0(void);
s32 func_00276368(void);
s32 func_0028acc8(s32);
s32 func_00276888(void);
void func_00287f90(s32);
s32 func_00287c10(void);
void func_00297e00(s32);
s32 func_00292630(void);
void func_00276690(s32);
void func_00287c30(void);
s32 func_0028af18(s32, s32);
s32 func_00276358(void);
void func_00276220(s32, s32);
void func_00274cf0(s32);
void func_002925c0(void);
void func_002766b0(s32);
void func_002958b0(void);
void func_002986e0(void);
s32 func_00289310(s32);
s32 func_00276398(void);
void func_00275b60(void);
void func_00287c90(s32);
void func_00299408(void);
s32 func_00287df0(s32, s32, s32, void (*)(void), s32);
s32 func_00242848(s32);
void func_00297df8(void);
void func_00276dc0(void);
void func_002765e8(s32, s32, s32);
void func_00287c00(s32);
void func_00287cc0(s32);
void func_00287da0(void);
void func_0028f6f0(s32);
s32 func_00288040(void);
void func_00288018(void);
void func_00298410(void)
{
    s32 r = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (r != -1) {
                func_00287f90(0);
                func_00297e00(func_00287c10());
            }
            return;
        }
        if (func_00292630()) return;
        func_00276690(0);
        func_00297e00(func_00287c10());
        func_00287c30();
        s32 m = func_00287bc0();
        func_0028af18(D_0035f200, 115);
        func_00276220(func_00276358(), 0);
        if (m == st) {
            func_00274cf0(2);
            func_002925c0();
            func_002766b0(0);
            func_002958b0();
        } else if (m == 5) {
            func_002986e0();
        }
        return;
    }
    if ((r != -1 || func_00289310(D_0035f200)) && !func_00276398()) {
        func_00276220(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398()) func_00287c90(1);
    if (!func_00242848(func_00287df0(r, func_00289310(D_0035f200), 1, func_00299408, 1))) {
        switch (r) {
        case -2:
            func_0028f6f0(0);
            func_00297df8();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(2);
            func_00287cc0(2);
            break;
        case -4:
            func_00287da0();
            break;
        case -1: break;
        default:
            func_00297df8();
            D_0035f5a0 = r;
            func_00276dc0();
            func_002765e8(func_00287bc0(), r, 0);
            func_00276220(0, 1);
            func_00287c00(5);
            func_00287cc0(2);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}
