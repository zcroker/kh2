#include "../common/types.h"
extern "C" {
s32 func_00257770(void);
s32 func_00139d78(s32);
void func_0028da70(s32, s32);
s32 func_00103570(void);
s32 func_001063c0(s32, s32);
void func_0023f800(s32);
extern s32 D_0035f57c;
extern u8 D_0035f580;
extern u8 D_0035f581;
void func_00257a00(void);

void func_00139510(s32);
s32 func_0028be58(s32);
void func_0028be18(s32);
void func_0028bdb8(s32);
s32 func_0028acc8(s32);
s32 func_0028acb8(s32);
void func_0028abe0(s32);
void func_0028aa40(s32);
s32 func_00287bc0(void);
s32 func_0027af58(void);
void func_0028dac8(s32, s32);
extern s32 D_0035f01c;
extern s32 D_0035f04c;
struct E6 { s16 a; s16 b; s16 c; };
extern E6 D_00373e30[];

void func_0027d450(void) {
    s32 p = func_00257770();
    func_00139d78(p);
    func_0028da70(p, 0xEA);
}
void func_002944f8(void) {
    D_0035f580 = 0;
    D_0035f581 = 0;
    s32 r = func_001063c0(0x1C, func_00103570());
    func_0023f800(r);
    D_0035f57c = r;
}
void func_0027acf8(void) {
    s32 p = func_00257770();
    func_00257a00();
    p += 0x814;
    if (func_00139d78(p)) func_00139510(p);
    if (func_0028be58(D_0035f04c)) func_0028be18(D_0035f04c);
    if (func_0028acc8(D_0035f01c)) func_0028abe0(D_0035f01c);
}
void func_0027ac38(void) {
    s32 p = func_00257770();
    if ((u32)(func_00287bc0() - 0x11) >= 3) return;
    func_0028dac8(p, D_00373e30[func_0027af58()].b);
    if (func_0028be58(D_0035f04c)) func_0028bdb8(D_0035f04c);
    if (!func_0028acc8(D_0035f01c)) return;
    if (func_0028acb8(D_0035f01c)) return;
    func_0028aa40(D_0035f01c);
}
s32 func_00287cd0(void);
s32 func_00285728(void);
s32 func_00287c10(void);
void func_00287da0(void);
void func_00288658(s32, s32);
void func_00288670(void (*)(void));
void func_002843e8(void);
void func_00103c80(s32);
s32 func_0014aba8(void);
void func_0014aa58(s32, s32, s32);
void func_002bd760(s32);
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_00285760(void);
s32 func_0028ae28(s32, s32);
void func_00287c00(s32);
void func_002856c8(void);
extern s32 D_0035f2d4;
extern s32 D_0035f2dc;

void func_00285070(void) {
    s32 s2 = func_00287bc0();
    s32 s0 = func_00287cd0();
    if (s0 == 2) {
        if (func_00285728()) return;
        if (func_00287c10()) {
            func_00287da0();
            if (s2 == 1) {
                func_00288658(4, 10);
                func_00288670(func_002843e8);
                D_0035f2d4 = s2;
            } else {
                func_00103c80(3);
                func_0014aa58(func_0014aba8(), 0xF, 0);
                func_002bd760(0x3C);
                D_0035f2d4 = s0;
            }
        }
        func_00287bd0(0, 0);
        func_00287cc0(1);
    } else {
        s32 s1 = func_00285760();
        if (func_0028ae28(D_0035f2dc, 0) && s0 != 1) func_00287cc0(1);
        if (s1 == -1) return;
        if (s1 == 1) func_00287c00(3);
        else if (s2 == 1) func_00287c00(3);
        else func_00287c00(0);
        func_002856c8();
        func_00287cc0(2);
    }
}
s32 func_0028d008(s32);
void func_0028cc78(s32, s32, s32, s32, s32, s32);
s32 func_002891d0(s32);
void func_0028cf28(s32, s32);
s32 func_0028d6e8(s32);
void func_0028d1c0(s32, s32, s32, s32, s32, void*, s32);
void func_0028d660(s32, s32);
s32 func_00289310(s32);
s32 func_002891e8(s32);
void func_002890e0(s32, s32, s32, s32, s32);
void func_00289038(s32, s32, s32, s32, s32, s32, s32);
void func_0028ce38(void);
void func_0028d5d0(s32);
extern s32 D_0035f2c8;
extern s32 D_0035f2e0;
extern u8 D_00374380[];

void func_002851e0(void) {
    s32 a = func_00287bc0();
    s32 st = func_00287cd0();
    if ((u32)(a - 1) >= 2) return;
    if (st == 1) {
        if (!func_0028d008(0)) {
            func_0028cc78(0, 0, 0, D_0035f2c8, 8, 8);
            func_0028cf28(0, func_002891d0(D_0035f2dc));
            if (!func_0028d6e8(D_0035f2e0)) {
                func_0028d1c0(D_0035f2e0, 0x754A, 0, 0, D_0035f2c8, D_00374380, 0);
                func_0028d660(D_0035f2e0, func_002891d0(D_0035f2dc));
            }
        }
        if (func_00289310(D_0035f2dc)) {
            s32 n = func_002891e8(D_0035f2dc);
            func_002890e0(D_0035f2dc, 1, 2, 0, -1);
            func_00289038(D_0035f2dc, n, 1, 1, 2, 0, -1);
            if (func_0028d008(0)) func_0028cf28(0, func_002891d0(D_0035f2dc));
            if (func_0028d6e8(D_0035f2e0)) func_0028d660(D_0035f2e0, func_002891d0(D_0035f2dc));
        }
    } else if (st == 2) {
        if (func_0028d008(0)) {
            func_0028ce38();
            func_0028d5d0(D_0035f2e0);
        }
    }
}
}
