#include "../common/types.h"
extern "C" {
s32 func_00242848(s32);
s32 func_00256e80(void);
s32 func_00256ef0(void);
s32 func_002570a0(s32);
void func_00263c60(void);
void func_0026f388(void);
void func_0026ff30(void);
void func_00270c70(s32);
void func_00272340(void);
void func_002723e0(void);
s32 func_00272428(void);
void func_00272468(void);
s32 func_00272538(void);
s32 func_00272b60(s32);
void func_00272c90(s32);
void func_00273530(void);
s32 func_00273818(void);
s32 func_00273b30(void);
void func_002831e0(s32, s32);
s32 func_00287bc0(void);
void func_00287bd0(s32, s32);
void func_00287c00(s32);
void func_00287c30(void);
void func_00287c90(s32);
void func_00287cc0(s32);
s32 func_00287cd0(void);
void func_00287da0(void);
s32 func_00287df0(s32, s32, s32, s32, s32);
void func_00287f90(s32);
void func_00288018(void);
s32 func_00288040(void);
s32 func_00289310(s32);
s32 func_00289380(s32);
s32 func_0028afa8(s32);
void func_0028f6f0(s32);
void func_0028f7e8(s32);
s32 func_0028f930(s32);
void func_0028fa98(s32);
void func_00273e88(void);
extern s32 D_0035f01c;
extern s8 D_0035f128;
extern s8* D_0035f12c;

void func_002708c0(void)
{
    s32 sel = func_00289380(D_0035f01c);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00272428() || func_0028f930(2) || func_00256ef0()) {
            if (sel != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                func_002723e0();
            }
            return;
        }
        if (D_0035f128) {
            func_00273818();
            func_00270c70(func_002570a0(25));
            D_0035f128 = 0;
        }
        func_00287c30();
        func_0028f7e8(2);
        func_0026f388();
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f01c)) && !func_00272538()) {
        func_00272468();
        func_0028fa98(-1);
    }
    if (st == 0 && func_00272538()) {
        func_00272c90(1);
        func_00287c90(1);
    }
    s32 n = func_0028afa8(D_0035f01c);
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f01c), 1, (s32)func_00273e88, 1)) == 0) {
        s32 off;
        if (D_0035f128) sel = -2;
        switch (sel) {
        case -1: break;
        default:
            if (sel >= 0 && sel < n) {
                n = func_002570a0(26);
                if (func_00272b60(n) == 2) {
                    if (func_002570a0(25)) n--;
                    off = n * 8;
                    n = *(s8*)(off + (s32)D_0035f12c + 10) != 0;
                    if (func_002570a0(25)) {
                        if (*(s8*)(off + (s32)D_0035f12c + 11) == 2) n += 2;
                    }
                    if (n == sel) goto B;
                    if (func_00273b30()) {
                        func_0026ff30();
                        func_00287bd0(28, 0);
                        break;
                    }
                }
                func_00273530();
            B:
                func_00263c60();
                func_00256e80();
                func_0028f6f0(2);
            C:
                func_00272340();
                func_00287cc0(2);
                {
                    s32 r = func_002570a0(25);
                    s32 v = 26;
                    asm volatile("" : "+r"(v));
                    if (r) v = 27;
                    func_00287c00(v);
                }
            }
            break;
        case -7: {
            s32 r = func_00272b60(func_002570a0(26));
            n = func_00287bc0();
            func_00287bd0(37, 0);
            if (r == 2) func_002831e0(0, n);
            else if (r == 1) func_002831e0(1, n);
            break;
        }
        case -2:
            func_00263c60();
            func_0028f6f0(2);
            func_00256e80();
            goto C;
        case -4:
            func_00287da0();
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}
