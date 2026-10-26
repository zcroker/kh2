#include "../common/types.h"
extern "C" {
s32 func_00257070(s32);
s32 func_002570a0(s32);
s32 func_00257130(void);
u8* func_00257770(void);
void func_00263a58(s32, s32);
s32 func_00269508(s32);
s32 func_002695a0(s32);
u16* func_0026a178(s32, s32);
s32 func_002811b0(s32, s32);
void func_002817b8(void);
void func_00281cf0(u16);
s32 func_00281f18(s32);
u8* func_00281f20(s32);
s32 func_00287bc0(void);
s32 func_0028b040(s32);
void func_00291068(s32, s32, u16, u8*, s32, s32);
void func_00291110(s32, s32, s32, u16, u8*, s32, s32);
void func_00291358(s32);
extern s32 D_0035f010;
extern s32 D_0035f018;
extern s32 D_0035f01c;
extern s32 D_0035f0ec;

void func_00269a60(void)
{
    s32 none = 0;
    u8* buf = func_00257770();
    s32 mode = func_00287bc0();
    s32 idx = func_0028b040(D_0035f01c);
    s32 msg;
    if (mode == 2) goto A;
    if (mode == 5 || mode == 6) {
        if (!func_00281f18(D_0035f0ec)) { none = 1; goto B; }
    A:
        if (!func_0026a178(idx, -1) || !*func_0026a178(idx, -1)) none = 1;
    } else if (!idx || !func_0026a178(idx - 1, -1) || !*func_0026a178(idx - 1, -1)) {
        none = 1;
    }
B:
    if (mode == 2) {
        if (none) msg = -1;
        else msg = (u16)(func_0026a178(idx, -1)[5] | 0x8000);
    } else if (mode == 5 || mode == 6) {
        if (func_00281f18(D_0035f0ec)) msg = (u16)(func_0026a178(idx, -1)[5] | 0x8000);
        else msg = 0x844a;
    } else if (!idx) {
        if (mode == 7) msg = 0xcb8d;
        else msg = mode == 8 ? 0xcb8e : 0x8469;
    } else {
        msg = (u16)(func_0026a178(idx - 1, -1)[5] | 0x8000);
    }
    func_00263a58(msg, 1);
    s32 s4 = func_002811b0(D_0035f010, func_00257070(1));
    s32 v;
    if (mode == 2) v = func_0028b040(D_0035f01c);
    else v = func_00257070(2);
    s32 s3;
    if (func_00269508(v) == 1) s3 = func_002695a0(v); else s3 = 0;
    if (none) {
        func_002817b8();
        if (mode == 2) {
            func_00291358(D_0035f018);
            return;
        }
        v = *(u16*)(func_00281f20(func_00257130()) + func_002570a0(2) * 6);
        if ((mode == 5 || mode == 6)) func_00291110(D_0035f018, 3, v, 0, buf + 0xb350, s4, s3);
        else func_00291110(D_0035f018, 2, v, 0, buf + 0xb350, s4, s3);
        return;
    }
    idx -= (u32)(mode - 7) < 3;
    func_00281cf0(func_0026a178(idx, -1)[10]);
    if (mode == 2) {
        func_00291068(D_0035f018, 1, *func_0026a178(idx, -1), buf + 0xb350, s4, s3);
        return;
    }
    v = *(u16*)(func_00281f20(func_00257130()) + func_002570a0(2) * 6);
    if ((mode == 5 || mode == 6)) func_00291110(D_0035f018, 3, v, *func_0026a178(idx, -1), buf + 0xb350, s4, s3);
    else func_00291110(D_0035f018, 2, v, *func_0026a178(idx, -1), buf + 0xb350, s4, s3);
}
}
