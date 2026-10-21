#include "../common/types.h"
extern "C" {
s32 func_00276348(void);
s32 func_002766d0(void);
s32 func_0028f930(s32);
void func_0028f4d8(s32, s32, s32);
void func_00276e78(void);
void func_0028d8c0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_00139620(s32);
void func_0028dcc0(s32, s32);
void func_00288d80(s32, s32, s32, s32, s32, s32, s16*, s16*);
s32 func_002891b8(s32, s32);
void func_002891f0(s32, s32, s32, s32, s32);
void func_00276690(s32);
void func_0028af28(s32, s32);
void func_002a6e50(void);
void func_002a7470(void);
void func_00287cc0(s32);
extern s32 D_0035f3d4;
extern s32 D_0035f14c;
extern s32 D_0035f148;
extern s32 D_0035f210;
extern s32 D_0035f200;
void func_002a6a50(void) {
    s16 buf[4];
    s32 i;
    s32 a = func_00276348();
    s32 b = func_002766d0();
    s32 n, c;
    if (func_0028f930(0) == 0) {
        func_0028f4d8(0, -1, 0);
    }
    for (i = 0; i < 4; i++) {
        buf[i] = 2;
    }
    n = D_0035f3d4;
    func_00276e78();
    func_0028d8c0(b, n - 1, D_0035f14c, D_0035f148, D_0035f210, 101, -1, 0);
    func_00139620(b);
    func_0028dcc0(b, a);
    func_00288d80(D_0035f200, 0, D_0035f14c, D_0035f148, D_0035f210, -1, buf, buf);
    c = func_002891b8(D_0035f200, 0);
    func_00139620(c);
    func_0028dcc0(c, b);
    func_002891f0(D_0035f200, 0, 0, -1, -1);
    func_00276690(1);
    func_0028af28(D_0035f200, 16);
    func_002a6e50();
    func_002a7470();
    func_00287cc0(0);
}
}
