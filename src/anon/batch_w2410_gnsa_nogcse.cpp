#include "../common/types.h"
extern "C" {
void func_002927b8(void);
void func_002926c0(s32);
void func_00292870(void);
s32 func_00276348(void);
s32 func_002766d0(void);
s32 func_0028f930(s32);
void func_0028f4d8(s32, s32, s32);
void func_002aeb28(void);
void func_00276e78(void);
void func_0028d8c0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_00139620(s32);
void func_0028dcc0(s32, s32);
s32 func_0023aa78(s32);
void func_00288d80(s32, s32, s32, s32, s32, s32, s16*, s16*);
s32 func_002891b8(s32, s32);
void func_00138c68(s32, s32, s32);
void func_001395f8(s32);
s32 func_00287bc0(void);
s32 func_00276608(s32);
void func_002891f0(s32, s32, s32, s32, s32);
void func_0028af90(s32, s32);
void func_0028afd0(s32, s32);
void func_0028b218(s32, s32);
void func_0028b248(s32, s32);
void func_002b1708(void);
void func_002b1a00(void);
void func_002766b0(s32);
void func_00287cc0(s32);
extern s32 D_0035f3d4;
extern s32 D_0035f14c;
extern s32 D_0035f148;
extern s32 D_0035f210;
extern s32 D_0035f200;
void func_002aed60(void) {
    s16 arr[2][4];
    s32 a, b, i, j, n, sz, off, r, c;
    func_002927b8();
    func_002926c0(0);
    func_00292870();
    a = func_00276348();
    b = func_002766d0();
    if (!func_0028f930(0)) {
        func_0028f4d8(0, -1, 0);
        func_002aeb28();
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) arr[i][j] = 2;
    }
    n = D_0035f3d4 - 1;
    func_00276e78();
    {s32 z = D_0035f14c, y = D_0035f148, x = D_0035f210;
    func_0028d8c0(b, n, z, y, x, 90, -1, 0);}
    func_00139620(b);
    func_0028dcc0(b, a);
    sz = func_0023aa78(b + 0x18);
    n = D_0035f3d4;
    n++;
    c = b + 0xa998;
    off = 0;
    for (i = 0; i < 3; i++) {
        func_00288d80(D_0035f200, i, D_0035f14c, D_0035f148, D_0035f210, -1, arr[0], arr[1]);
        r = func_002891b8(D_0035f200, i);
        func_00139620(r);
        func_0028dcc0(r, b);
        func_00138c68(r, 0, off);
        off += sz;
        ((s32*)r)[0x1a4/4] = 0x60000008;
        ((s32*)r)[0x1ac/4] = 3;
        func_001395f8(r);
        func_0028d8c0(c, n, D_0035f14c, D_0035f148, D_0035f210, 2, -1, 0);
        func_0028dcc0(c, r);
        c += 0x198;
    }
    func_002891f0(D_0035f200, func_00276608(func_00287bc0()), 0, -1, -1);
    func_0028af90(D_0035f200, 3);
    func_0028afd0(D_0035f200, 0);
    func_0028b218(D_0035f200, 1);
    func_0028b248(D_0035f200, 10);
    func_002b1708();
    func_002b1a00();
    func_002766b0(1);
    func_00287cc0(0);
}
}
