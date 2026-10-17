#include "../common/types.h"
// Built by the original with debug info (-g).
extern "C" {
extern u8 D_00295710[];
s32 func_00289380(s32);
s32 func_00287cd0();
s32 func_00276368();
s32 func_00276888();
void func_00287f90(s32);
void func_002945a8();
s32 func_00292630();
void func_00287c30();
void func_0028b0e0(s32);
void func_0028af18(s32, s32);
void func_00274cf0(s32);
void func_002925c0();
s32 func_00276358();
void func_00276220(s32, s32);
void func_002958b0();
void func_002995e8();
void func_00294f00();
s32 func_00289310(s32);
s32 func_00276398();
void func_00275b60();
void func_00287c90(s32);
void func_00295508();
void func_002956a0();
s32 func_00287df0(s32, s32, s32, void*, s32);
s32 func_00242848(s32);
void func_00287da0();
s32 func_00288040();
void func_00288018();
void func_00276150(s32, s32*, s32*);
void func_00276dc0();
void func_00287c00(s32);
void func_00287cc0(s32);
s32 func_00295228(s32);
void func_00276578(s32);
extern s32 D_0035f200;
extern s16* D_0035f598;
extern s8 D_0035f5a0;
void func_00138c10(s32, s32);
s32 func_00139d78(s32);
s8* func_00276568();
s32 func_002766d0();
s32 func_00287bc0();
s32 func_002891e8(s32);
s32 func_0028b040(s32);
s32 func_00294348(s32);
s32 func_002983d8(s32);
s32 func_002a9d68();
u32 func_002aa5b8(s32, s32);
void func_002aa8e0(s32, s32);
void func_00299290(void) {
    s32 s2 = func_002a9d68();
    s32 s3 = func_002766d0();
    if (*(s32*)D_0035f598 == 0) return;
    s32 mode = func_00287bc0();
    s32 idx;
    if (mode == 4) {
        idx = func_0028b040(D_0035f200);
    } else {
        idx = D_0035f5a0;
    }
    s32 id = D_0035f598[idx + 2];
    if (func_00294348(func_002983d8(id)) == 0) return;
    s32 c = *func_00276568();
    u32 bit = func_002aa5b8(c, id);
    s32 q = s2 + c * 4;
    q += (bit >> 5) * 4;
    if (*(u32*)(q + 0x44) & (1 << (bit & 0x1f))) return;
    func_002aa8e0(*func_00276568(), id);
    if (mode != 4) return;
    s32 p = 0x198;
    p = func_002891e8(D_0035f200) * p;
    u8* qq = (u8*)s3;
    qq += p;
    qq += 0xA998;
    p = (s32)qq;
    if (func_00139d78(p) == 0) return;
    func_00138c10(p, 0x5D);
}
void func_00294b80(void) {
    s32 r = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    s32 m = func_00287bc0();
    if (st == 2) {
        if (func_00276368() != 0 || func_00276888() != 0) {
            if (r != -1) {
                func_00287f90(0);
                func_002945a8();
            }
            return;
        }
        if (func_00292630() != 0) return;
        func_002945a8();
        func_00287c30();
        m = func_00287bc0();
        func_0028b0e0(D_0035f200);
        func_0028af18(D_0035f200, 0x73);
        func_00274cf0(m);
        func_002925c0();
        func_00276220(func_00276358(), 0);
        if (m == st) {
            func_002958b0();
        } else if (m == 13) {
            func_002995e8();
        }
        return;
    }
    func_00294f00();
    if ((r != -1 || func_00289310(D_0035f200) != 0) && func_00276398() == 0) {
        func_00276220(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398() != 0) {
        func_00287c90(1);
        func_00295508();
        func_002956a0();
    }
    if (func_00242848(func_00287df0(r, func_00289310(D_0035f200), 1, D_00295710, 1)) == 0) {
        s32 x;
        s32 a;
        s32 b0, b1;
        switch (r) {
        case -4:
        case -2:
            func_00287da0();
            break;
        case -1:
            break;
        case -9:
        case -8:
            func_00276150(m, &b0, &b1);
            if (r == -8) {
                x = b1;
                a = 0;
            } else {
                x = b0;
                a = 1;
            }
            func_00276220(a, 1);
            func_00276dc0();
            func_00287c00(x);
            func_00287cc0(2);
            break;
        default:
            if (r >= 0) {
                r = func_00295228(r);
                func_00276578(r);
                func_00276220(0, 1);
                func_00276dc0();
                func_00287c00(r < 15 ? 2 : 13);
                func_00287cc0(2);
            }
            break;
        }
    }
    if (func_00288040() != 0) {
        func_00288018();
    }
}
}
