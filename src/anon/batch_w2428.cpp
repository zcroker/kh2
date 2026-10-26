#include "../common/types.h"
extern "C" {
s32 func_00233e70(s32);
s32 func_00234758(void);
s32 func_00234798(void);
s32 func_002347d8(void);
void func_002349c8(s32, s32);
void func_00240360(s32);
s32 func_00240a08(s32);
s32 func_00240ba0(void);
void func_00240bc0(s32);
s32 func_00240bd0(void);
void func_00240c08(s32, s32, s32);
void func_00240e10(s32);
s32 func_00240e50(void);
void func_00240fd8(s32, s32);
s32 func_002413f0(void);
void func_00241450(s32);
void func_002415a0(s32, s32, s32);
void func_00241850(s32, s32);
s32 func_00241c40(s32);
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_00287cd0(void);
void func_00287d20(s32);
s32 func_00287d30(void);
void func_00288018(void);
s32 func_00288040(void);
void func_002b4c88(s32);
s32 func_002b4ff8(void);
void func_002b5108(s32, s32);
extern s8 D_0035f0b0;

void func_0025b218(void)
{
    s32 h = func_00240ba0();
    s32 st = func_00287cd0();
    s32 r;
    if (st == 2) return;
    if (!func_002b4ff8()) return;
    if (st == 0) func_00287cc0(1);
    switch (func_00287d30()) {
    case 10:
        if (func_00233e70(0)) break;
        if (func_00234798()) goto E;
        func_00240e10(-1);
        func_00287d20(11);
        break;
    case 11:
        if (func_00233e70(0)) break;
        if (func_00234758()) goto E;
        if (func_00240e50() <= 0) goto X;
        func_00287d20(12);
        break;
    case 12:
        func_00241450(1);
        func_00287d20(13);
        break;
    case 13:
        if (func_00233e70(0)) break;
        if (func_00234798()) goto E;
        func_00287d20(14);
        break;
    case 14:
        st = func_002413f0();
        if (st < 0) {
        X:
            func_00287bd0(3, 0);
            func_00287d20(90);
            break;
        }
        func_00240bc0(st);
        func_00240360(st);
        func_00241450(0);
        func_00287d20(15);
        break;
    case 15:
        if (func_00233e70(0)) break;
        r = func_00234798();
        if (r == 0) {
            func_00240e10(-5);
            func_00287d20(16);
            break;
        }
        if (r == 2) goto E;
        func_00240fd8(-1, 2);
    G:
        func_00240c08(func_00240bd0(), 0, 32);
        func_00287d20(12);
        break;
    case 16:
        if (!func_00233e70(0)) {
            r = func_00234758();
            if (r == 0) {
                st = func_002413f0();
                func_00240bc0(st);
                func_00240360(st);
                func_00241850(func_00240bd0(), 0);
                func_002415a0(2, 0, 0);
                func_00287d20(17);
            } else if (r == 1) {
                func_00240c08(func_00240bd0(), 0, 32);
                func_00287d20(12);
            } else {
                func_002b5108(0x8a8c, h);
                func_00287bd0(7, 0);
                func_002b4c88(0);
                D_0035f0b0 = 0;
            }
        }
    case 17:
        if (func_00233e70(0)) break;
        func_00240fd8(-1, 2);
        r = func_002347d8();
        if (r == 0) {
            func_00287d20(18);
            break;
        }
        if (r == 1) { func_00240c08(func_00240bd0(), 0, 32); func_00287d20(12); break; }
        if (r != 3) goto E;
    H:
        func_00240c08(func_00240bd0(), 0, 32);
        func_00287d20(14);
        break;
    case 18:
        if (!func_00240a08(0)) goto H;
        func_00240e10(-4);
        func_00287d20(19);
        break;
    case 19:
        if (func_00233e70(0)) break;
        r = func_00234758();
        if (r == 0) {
            func_002349c8(h, 0);
            st = func_00241c40(1) ? 16 : 32;
            func_00240c08(func_00240bd0(), 0, st);
            func_00287d20(14);
            break;
        }
        if (r == 1) { func_00240c08(func_00240bd0(), 0, 32); func_00287d20(12); break; }
    E:
        func_002b5108(0x8a8c, h);
        func_00287bd0(7, 0);
        func_002b4c88(0);
        D_0035f0b0 = 0;
        break;
    }
    if (func_00288040()) func_00288018();
}



}
