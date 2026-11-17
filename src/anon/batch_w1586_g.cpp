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
void func_002a8ac8(void);  // 0x002a8ac8: definition moved into src/anon/unit_002a8ac8.cpp

s32 func_00103570(void);
s32 func_001063c0(s32, s32);
void func_00319a60(s32);
void func_002a9ce8(void);  // 0x002a9ce8: definition moved into src/anon/unit_002a99c8.cpp

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
u8 func_002acc98(void);  // 0x002acc98: definition moved into src/anon/unit_002a99c8.cpp
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
