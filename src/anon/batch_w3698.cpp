#include "../common/types.h"
// 0025e450: case 15 pins a0/a1 so the li a1,2 comes before li a0,-1 (the a0 move fills the jal delay slot like the original).
extern "C" {
s32 func_00233e60(void);
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
void func_002417a0(void);
void func_00241850(s32, s32);
s32 func_00241c40(s32);
s32 func_00287bc0(void);
void func_00287bd0(s32, s32);
void func_00287c00(s32);
s32 func_00287c10(void);
void func_00287c30(void);
void func_00287c90(s32);
s32 func_00287cd0(void);
void func_00287d20(s32);
s32 func_00287d30(void);
void func_00288018(void);
s32 func_00288040(void);
void func_0028f7e8(s32);
void func_0025dba8(void);
void func_002b4c88(s32);
void func_002b4ee0(void);
s32 func_002b4fb8(void);
s32 func_002b4ff8(void);
void func_002b5108(s32, s32);
void func_002b5188(void*, s32);
void func_002b5af0(void);
extern u8 D_00373110;
extern s8 D_0035f0b3;

void func_0025e450(void)
{
    s32 h = func_00240ba0();
    s32 st = func_00287cd0();
    s32 r;
    if (st == 2) {
        if (func_002b4fb8()) return;
        if (func_00287c10() == 1) {
            func_00233e70(0);
            if (!func_00233e60()) return;
        }
        func_00287c30();
        func_00287d20(0);
        r = func_00287bc0();
        if (r == 1) {
            func_002b5af0();
            func_0028f7e8(1);
            func_0025dba8();
            return;
        }
        if (r == 12) {
            func_002417a0();
            func_002b5188(&D_00373110, 1);
        }
        return;
    }
    if (!func_002b4ff8()) return;
    if (st == 0) func_00287c90(1);
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
        if (func_00240e50() > 0) {
            func_00287d20(12);
            break;
        }
    F:
        func_002b4ee0();
        func_00287c00(12);
        func_00287c90(1);
        break;
    case 12:
        func_00241450(1);
        func_00287d20(13);
        break;
    case 13:
        if (func_00233e70(0)) goto C14;
        if (func_00234798()) goto E2;
        func_00287d20(14);
    case 14:
    C14:
        st = func_002413f0();
        if (st < 0) goto F;
        func_00240bc0(st);
        func_00240360(st);
        func_00241450(0);
        func_00287d20(15);
        break;
    E2:
        func_002b5108(0x8a8c, h);
        func_00287bd0(7, 0);
        func_002b4c88(0);
        D_0035f0b3 = 0;
        goto C14;
    case 15:
        if (func_00233e70(0)) break;
        r = func_00234798();
        if (r == 0) {
            func_00240e10(-5);
            func_00287d20(16);
            break;
        }
        if (r == 2) goto E;
        {
            register s32 a1 asm("$5") = 2;
            register s32 a0 asm("$4") = -1;
            func_00240fd8(a0, a1);
        }
    G:
        func_00240c08(func_00240bd0(), 0, 32);
        func_00287d20(12);
        break;
    case 16:
        if (func_00233e70(0)) break;
        st = func_00234758();
        if (st == 0) {
            st = func_002413f0();
            func_00240bc0(st);
            func_00240360(st);
            func_00241850(func_00240bd0(), 0);
            func_002415a0(2, 0, 0);
            func_00287d20(17);
            break;
        }
    K:
        if (st == 1) goto G;
        goto E;
    case 17:
        if (func_00233e70(0)) break;
        func_00240fd8(-1, 2);
        r = func_002347d8();
        if (r == 0) {
            func_00287d20(18);
            break;
        }
        if (r == 1) goto G;
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
        st = func_00234758(); if (__builtin_expect(st != 0, 0)) goto K;
        func_002349c8(h, 0);
        st = func_00241c40(1) ? 16 : 32;
        func_00240c08(func_00240bd0(), 0, st);
        func_00287d20(14);
        break;
    E:
        func_002b5108(0x8a8c, h);
        func_00287bd0(7, 0);
        func_002b4c88(0);
        D_0035f0b3 = 0;
        break;
    }
    if (func_00288040()) func_00288018();
}
}
