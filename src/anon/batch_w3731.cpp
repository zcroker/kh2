// 00299e70: empty asm on k in the -8 arm makes k conflict with mode, so k stays in s2; barrier asms keep the order lw a0, li a1, move s3,v0 before jal 0028af18.
#include "../common/types.h"
extern "C" {
extern s32 D_0035f200;
extern u16 D_00374910[];
s32 func_00289380(s32);
s32 func_00287cd0(void);
s32 func_00287bc0(void);
s32 func_00276368(void);
s32 func_0028acc8(s32);
s32 func_00276888(void);
void func_00287f90(s32);
void func_002995a8(void);
s32 func_00292630(void);
void func_00287c30(void);
void func_0028af18(s32, s32);
void func_00274cf0(s32);
void func_002925c0(void);
s32 func_00276358(void);
void func_00276220(s32, s32);
void func_002945e8(void);
void func_002958b0(void);
void func_0029ae40(void);
void func_0029ee68(void);
void func_002aed60(void);
void func_002a21b0(void);
void func_002a8ac8(void);
void func_002a77a0(void);
void func_002a4e38(void);
void func_002a6a50(void);
void func_002a0908(s32);
void func_0029a368(void);
s32 func_00289310(s32);
s32 func_00276398(void);
void func_00275b60(void);
void func_00287c90(s32);
void func_0029a780(void);
s32 func_00287df0(s32, s32, s32, void (*)(void), s32);
s32 func_00242848(s32);
void func_00287da0(void);
void func_00276150(s32, s32*, s32*);
void func_00276dc0(void);
void func_00287c00(s32);
void func_00287cc0(s32);
s32 func_0029a5f0(s32);
void func_0028fb28(s32, u16);
void func_00275dd0(void);
void func_002765e8(s32, s32, s32);
s32 func_00288040(void);
void func_00288018(void);
void func_00299e70(void)
{
    s32 r = func_00289380(D_0035f200);
    s32 mode = func_00287cd0();
    s32 m = func_00287bc0();
    if (mode == 2) {
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (r != -1) {
                func_00287f90(0);
                func_002995a8();
            }
            return;
        }
        if (func_00292630()) return;
        func_002995a8();
        func_00287c30();
        { s32 t = func_00287bc0();
        s32 d = D_0035f200;
        asm volatile("" : : "r"(d));
        register s32 x1 asm("$5") = 115;
        asm volatile("" : : "r"(x1));
        m = t;
        func_0028af18(d, x1); }
        func_00274cf0(m);
        func_002925c0();
        func_00276220(func_00276358(), 0);
        switch (m) {
        case 0: func_002945e8(); break;
        case 2: func_002958b0(); break;
        case 14: case 18: case 21: func_0029ae40(); break;
        case 24: func_0029ee68(); break;
        case 27: func_002aed60(); break;
        case 26: case 34: func_002a21b0(); break;
        case 35: func_002a8ac8(); break;
        case 36: func_002a77a0(); break;
        case 37: func_002a4e38(); break;
        case 39: func_002a6a50(); break;
        case 40: func_002a0908(-1); break;
        }
        return;
    }
    func_0029a368();
    if ((r != -1 || func_00289310(D_0035f200)) && !func_00276398()) {
        func_00276220(0, 2);
        func_00275b60();
    }
    if (mode == 0 && func_00276398()) func_00287c90(1);
    s32 k;
    if (!func_00242848(func_00287df0(r, func_00289310(D_0035f200), 1, func_0029a780, 1))) {
        switch (r) {
        case -4:
            func_00287da0();
            break;
        case -1:
            break;
        case -9:
        case -8: {
            s32 a, b;
            func_00276150(m, &a, &b);
            if (r == -8) {
                mode = b;
                r = 0;
            } else {
                mode = a;
                r = 1;
            }
            asm volatile("" : "=r"(k));
            func_00276dc0();
            func_00276220(r, 1);
            func_00287c00(mode);
            func_00287cc0(2);
            break;
        }
        default: {
            k = -1;
            switch (func_0029a5f0(r)) {
            case 0: k = 24; break;
            case 1: k = 14; break;
            case 2: k = 18; break;
            case 3: k = 21; break;
            case 4: k = 26; break;
            case 5: k = 27; break;
            case 6: k = 34; break;
            case 7: k = 35; break;
            case 8: k = 36; break;
            case 9: k = 37; break;
            case 10: k = 39; break;
            case 11: k = 40; break;
            }
            func_00276220(0, 1);
            func_0028fb28(0, D_00374910[func_0029a5f0(r)]);
            func_00287c00(k);
            func_00276dc0();
            func_00275dd0();
            func_00287cc0(2);
            func_002765e8(m, r, 0);
            break;
        }
        case -2:
            func_00276220(1, 1);
            func_00276dc0();
            func_00287c00(0);
            func_00287cc0(2);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}
