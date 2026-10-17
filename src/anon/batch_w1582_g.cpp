#include "../common/types.h"
extern "C" {
u8* func_00257770(void);
s32 func_00287bc0(void);
s32 func_002570a0(s32);
s32 func_00269508(s32);
s32 func_00139d78(u8*);
void func_00138c10(u8*, s32);
s32 func_0028be58(u32);
void func_0028bd60(u32);
struct E6 { s16 a; s16 b; s16 c; };
extern E6 D_00373798[];
extern E6 D_003737c8[];
extern u32 D_0035f04c;
static inline void set_0026a060(u8* q, s32 v) {
    if (func_00139d78(q) && *(s32*)(q + 0x184) != v) func_00138c10(q, v);
}
void func_0026a060(void) {
    u8* p = func_00257770();
    s32 a, b;
    if (func_00287bc0() == 2) {
        a = 0xe4; b = 0x120;
    } else {
        s32 i = func_00269508(func_002570a0(2));
        a = D_00373798[i].c;
        b = D_003737c8[i].c;
    }
    if (p) set_0026a060(p, a);
    if (p) set_0026a060(p + 0xb350, b);
    if (func_0028be58(D_0035f04c)) {
        func_0028bd60(D_0035f04c);
    }
}
s32 func_00287cd0(void);
s32 func_002576d0(void);
void func_002575a8(void);
void func_00287c30(void);
void func_00287cc0(s32);
s32 func_00257610(s32);
void func_00287c90(s32);
s32 func_00289380(u32);
s32 func_00289310(u32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_00273818(void);
void func_00271ee8(void);
void func_00257530(s32);
void func_00287c00(s32);
extern u32 D_0035f024;
extern u8 D_0035f128;
extern u8 D_0035f130;
void func_0026ff78(void) {
    s32 m = func_00287cd0();
    func_00287bc0();
    if (m == 2) {
        if (!func_002576d0()) {
            func_002575a8();
            func_00287c30();
            func_00287cc0(1);
        }
        return;
    }
    if (m == 0) {
        if (func_00257610(0)) func_00287c90(1);
    }
    if (m == 1) {
        s32 r = func_00289380(D_0035f024);
        if (func_00242848(func_00287df0(r, func_00289310(D_0035f024), 0, 0, 1))) return;
        switch (r) {
        case -4:
        case -3:
        case -1:
            break;
        case 1:
            if (D_0035f130 == 26 || D_0035f130 == 27) {
                func_00273818();
                func_00271ee8();
            }
            D_0035f128 = 1;
        case -2:
        case 0:
            func_00257530(0);
            func_00287cc0(2);
            func_00287c00((s8)D_0035f130);
            break;
        }
    }
}
s32 func_00276348(void);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_00139620(u8*);
void func_0028dcc0(u8*, s32);
extern u32 D_0035f148;
extern u32 D_0035f14c;
extern u32 D_0035f210;
extern s8* D_0035f1fc;
extern u8* D_0035f21c;
extern u16 D_00373d40[];
void func_00276e78(void) {
    s32 r = func_00276348();
    s32 mode = func_00287bc0();
    s32 i = D_0035f1fc[1];
    if (mode == 16 || mode == 19 || mode == 22) i += 2;
    func_0028d8c0(D_0035f21c + 408, 30042, D_0035f14c, D_0035f148, D_0035f210, D_00373d40[i], -1, 0);
    func_00139620(D_0035f21c + 408);
    func_0028dcc0(D_0035f21c + 408, r);
}
}
