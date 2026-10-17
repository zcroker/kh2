#include "../common/types.h"
extern "C" {
extern s32 D_0035f610;

s32 func_00276348(void);
s32 func_002766d0(void);
s32 func_0028f930(s32);
void func_0028f4d8(s32, s32, s32);
void func_002a9100(void);
void func_00276e78(void);
void func_0028d8c0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_00139620(s32);
void func_0028dcc0(s32, s32);
void func_00288d80(s32, s32, s32, s32, s32, s32, s16*, s16*);
s32 func_002891b8(s32, s32);
void func_002a92d8(void);
void* func_0023f1b0(s32);
s32 func_0023c4b8(void*, s32);
s32 func_00236ca8(s32, s32);
s32 func_00276678(void);
void func_0028bae0(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0028af90(s32, s32);
void func_002891f0(s32, s32, s32, s32, s32);
void func_0028afd0(s32, s32);
void func_00276690(s32);
void func_0028af28(s32, s32);
void func_0028b218(s32, s32);
void func_0028b248(s32, s32);
void func_002a9048(void);
void func_002a98a8(void);
void func_002a95a8(void);
void func_002a9888(void);
void func_00287cc0(s32);
extern s32 D_0035f3d4;
extern s32 D_0035f14c;
extern s32 D_0035f148;
extern s32 D_0035f210;
extern s32 D_0035f200;
extern s32 D_0035f214;
extern s32* D_0035f608;
void func_002a8ac8(void) {
    s16 arr[4];
    s32 a = func_00276348();
    s32 b = func_002766d0();
    s32 i, n, c, v, cnt, lim, r0, r1, r2;
    s16* p;
    if (!func_0028f930(0)) func_0028f4d8(0, -1, 0);
    for (i = 0; i < 4; i++) arr[i] = 2;
    func_002a9100();
    n = D_0035f3d4 - 1;
    c = b + 0x4c8;
    func_00276e78();
    func_0028d8c0(b, n, D_0035f14c, D_0035f148, D_0035f210, 101, -1, 0);
    v = 10;
    func_00139620(b);
    func_0028dcc0(b, a);
    func_0028d8c0(c, n, D_0035f14c, D_0035f148, D_0035f210, 109, -1, 0);
    func_00139620(c);
    func_0028dcc0(c, a);
    func_00288d80(D_0035f200, 0, D_0035f14c, D_0035f148, D_0035f210, -1, arr, arr);
    r0 = func_002891b8(D_0035f200, 0);
    func_00139620(r0);
    func_0028dcc0(r0, b);
    func_002a92d8();
    n = D_0035f3d4;
    lim = *D_0035f608;
    if (lim >= 11) v = lim;
    cnt = lim - 10;
    if (cnt > 0) cnt = lim - 9; else cnt = 1;
    r1 = func_0023c4b8(func_0023f1b0(D_0035f210), D_0035f14c);
    { void* o = func_0023f1b0(D_0035f210); s32 k = D_0035f148;
    r2 = func_00236ca8(*(s32*)((u8*)o + 0x28), k); }
    func_0028bae0(D_0035f214, n, r1, r2, func_00276678(), v, 10, c, 0);
    func_0028af90(D_0035f200, cnt);
    func_002891f0(D_0035f200, 0, 0, -1, -1);
    func_0028afd0(D_0035f200, 0);
    func_00276690(1);
    func_0028af28(D_0035f200, 16);
    if (cnt >= 2) {
        func_0028b218(D_0035f200, 1);
        func_0028b248(D_0035f200, 10);
    }
    func_002a9048();
    func_002a98a8();
    func_002a95a8();
    func_002a9888();
    func_00287cc0(0);
}

s32 func_00103570(void);
s32 func_001063c0(s32, s32);
void func_00319a60(s32);
void func_002a9ce8(void) {
    s32 p = func_001063c0(0x968, func_00103570());
    func_00319a60(p);
    D_0035f610 = p;
}

void func_002a9d88(void);
s32 func_002aa098(s32);
s32 func_002aa2f8(s32);
s32 func_002aa668(s32, s32);
s32 func_002aaa38(s32);
s32 func_002aae88(s32);
s32 func_002ab2b0(s32);
s32 func_002ab540(s32);
s32 func_002ab8e8(s32);
s32 func_002abc60(s32);
s32 func_002abff0(s32, s32);
s32 func_002ac420(s32);
s32 func_002ac748(s32);
u8 func_002acc98(void) {
    s32 i;
    func_002a9d88();
    if (func_002aa098(-1)) return 1;
    if (func_002aa2f8(-1)) return 1;
    if (func_002aaa38(-1)) return 1;
    if (func_002aae88(-1)) return 1;
    if (func_002ab2b0(-1)) return 1;
    if (func_002ab540(-1)) return 1;
    if (func_002ab8e8(-1)) return 1;
    if (func_002abc60(-1)) return 1;
    if (func_002ac420(-1)) return 1;
    if (func_002ac748(-1)) return 1;
    for (i = 0; i < 15; i++) {
        if (func_002aa668(i, -1)) return 1;
        if (func_002abff0(i, -1)) return 1;
    }
    return 0;
}
s32 func_00242848(s32);
s32 func_00275b60();
s32 func_00276220(s32, s32);
s32 func_00276358();
s32 func_00276368();
s32 func_00276398();
s32 func_002765e8(s32, s32, s32);
s32 func_00276608(s32);
s32 func_00276888();
s32 func_00276dc0();
s32 func_00287bc0();
s32 func_00287bd0(s32, s32);
s32 func_00287c00(s32);
s32 func_00287c30();
s32 func_00287c90(s32);
s32 func_00287cd0();
s32 func_00287da0();
s32 func_00287f90(s32);
s32 func_00288018();
s32 func_00288040();
s32 func_002891e8(s32);
s32 func_0028b038(s32);
s32 func_002aece8();
s32 func_002aecf0(s32);
void func_002af418(void);
s32 func_002afaf0();
s32 func_002b01d8();
s32 func_002b0950();
s32 func_002b0de0(s32);
s32 func_002b0e78(s32);
s32 func_002b0fc8(s32);
s32 func_002b1208(s32);
s32 func_002b12a0();
s32 func_002b2220();
s32 func_002b2338(s32);
s32 func_002b2428(s32);
s32 func_002b24c8();
s32 func_002b2840();
s32 func_002b2c80();
s32 func_002b2d48();
s32 func_002b3050(s32);
s32 func_002b3318();
extern u8* D_0035f638;
void func_002afe18(void) {
    s32 f = func_002b0950();
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_002b2220() || func_00276888()) {
            if (f) {
                func_00287f90(0);
                func_002aecf0(1);
            }
            return;
        }
        func_002aecf0(1);
        func_00287c30();
        s32 m = func_00287bc0();
        func_002b2840();
        func_00276220(func_00276358(), 0);
        switch (m) {
        case 28: func_002af418(); return;
        case 30: func_002b01d8(); return;
        case 29:
            func_002b2428(func_002b2338(func_00276608(28)));
            func_002afaf0();
            return;
        }
        return;
    }
    func_002b24c8();
    if (f && !func_00276398()) {
        func_00276220(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398()) func_00287c90(1);
    if (!func_002b2d48()) f = 0;
    if (!func_00242848(func_002b0de0(f))) {
        if (f & 0xf0) {
            func_002b3050(0);
        } else if (f & 0xc0000) {
            func_002b0e78(f);
        } else if (f & 0x100) {
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            func_002b2c80();
            func_00287da0();
        } else {
            s32 e = f & 8;
            if (f & 0x30008) {
                if (e && (*(u32*)(D_0035f638 + 0x34) & 0x800)) goto l48;
                func_002aece8();
                func_002b2c80();
                if (e) {
                    func_00276dc0();
                    func_00276220(1, 1);
                    func_00287c00(28);
                    func_00287cc0(2);
                } else {
                    func_002b1208(f);
                    func_00276220(((f >> 16) ^ 1) & 1, 1);
                    func_00287c00(func_00287bc0());
                    func_00287cc0(2);
                }
                goto l49;
            }
            if (f & 0x2000) {
                func_002aece8();
                func_002b2c80();
                func_00276dc0();
                func_00276220(0, 1);
                func_00287c00(30);
                func_00287cc0(2);
            } else if (f & 4) {
            l48:
                func_002b0fc8(f);
            }
        }
    l49:
        if ((f & 0xc0004) && func_002b3318()) {
            func_00287bd0(32, 0);
            func_002b12a0();
        }
    }
    if (func_00288040()) func_00288018();
}
}
