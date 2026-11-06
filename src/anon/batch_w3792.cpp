#include "../common/types.h"
extern "C" {
extern s32 D_0035f01c;
s32 func_00257770(void);
s32 func_00289380(s32);
s32 func_00287cd0(void);
s32 func_00287c10(void);
s32 func_00256ef0(void);
s32 func_0027a1c8(void);
s32 func_0028f930(s32);
s32 func_00257970(void);
s32 func_00289310(s32);
void func_00287f90(s32);
void func_0027a180(void);
void func_00256ea8(void);
void func_0028f878(void);
void func_00287c30(void);
void func_0028af18(s32, s32);
void func_0028f7e8(s32);
void func_002551b8(void);
void func_00277d20(void);
s32 func_002570a0(s32);
void func_0027aed8(s32, s32*, s32*);
void func_002677f0(s32, s32);
s32 func_0028ae28(s32, s32);
void func_0028da70(s32, s32);
void func_0028ab20(s32);
void func_00256e30(void);
void func_0028fa98(s32);
void func_0027b6b8(void);
void func_00287c90(s32);
s32 func_0028afa8(s32);
void func_0027c3e0(void);
s32 func_00287df0(s32, s32, s32, void (*)(void), s32);
s32 func_00242848(s32);
void func_00287da0(void);
void func_00263c60(void);
void func_00256e80(void);
void func_0028f6f0(s32);
void func_0027a108(void);
void func_00287c00(s32);
struct W408 { u8 pad[408]; s32 f408; };
W408* func_002891b8(s32, s32);
void func_0028fb68(s32, s32);
s32 func_002891e8(s32);
void func_00257050(s32, s32, s32);
s32 func_00257070(s32);
s32 func_00288040(void);
void func_00288018(void);

// 00277938: the common tail is written out in every switch case (cross-jumped back into one block).
void func_00277938(void)
{
    s32 v;
    s32 w;
    s32 h = func_00257770();
    s32 r = func_00289380(D_0035f01c);
    s32 st = func_00287cd0();
    if (st == 2) {
        s32 h2 = 0;
        s32 m = func_00287c10();
        if (m == 0) h2 = func_00256ef0();
        if (func_0027a1c8() || h2 || (m < 2u && func_0028f930(0)) || func_00257970()) {
            if (r != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                func_0027a180();
                if (m == 0) func_00256ea8();
                if (m < 2u) func_0028f878();
            }
            return;
        }
        func_00287c30();
        func_0028af18(D_0035f01c, 115);
        if (m == 0) {
            func_0028f7e8(0);
            func_002551b8();
        } else if (m == 16) {
            func_00277d20();
        } else if (m == 1) {
            func_0027aed8(func_002570a0(15), &v, &w);
            if (v) w = 0;
            func_002677f0(1, w);
        }
        return;
    }
    if ((r != -1 || func_00289310(D_0035f01c)) && !func_0028ae28(D_0035f01c, 0)) {
        func_0028da70(h, 141);
        func_0028ab20(D_0035f01c);
        func_00256e30();
        func_0028fa98(-1);
    }
    if (st == 0 && func_0028ae28(D_0035f01c, 0)) {
        func_0027b6b8();
        func_00287c90(1);
    }
    s32 n = func_0028afa8(D_0035f01c);
    if (func_00242848(func_00287df0(r, func_00289310(D_0035f01c), 1, func_0027c3e0, 1)) == 0) {
        switch (r) {
        case -4:
            func_00287da0();
            { v = func_00257070(15); if (v != func_002891e8(D_0035f01c)) func_00257050(16, 0, 0); func_00257050(15, func_002891e8(D_0035f01c), 0); }
            break;
        case -5:
            func_00263c60();
            func_00256e80();
            func_0028f6f0(0);
            func_0027a108();
            func_00287c90(1);
            func_00287c00(1);
            { v = func_00257070(15); if (v != func_002891e8(D_0035f01c)) func_00257050(16, 0, 0); func_00257050(15, func_002891e8(D_0035f01c), 0); }
            break;
        case -2:
            func_00263c60();
            func_00256e80();
            func_0028f6f0(0);
            func_0027a108();
            func_00287c90(1);
            func_00287c00(0);
            { v = func_00257070(15); if (v != func_002891e8(D_0035f01c)) func_00257050(16, 0, 0); func_00257050(15, func_002891e8(D_0035f01c), 0); }
            break;
        case -1:
            goto end;
        default:
            if (r < 0 || r >= n) goto end;
            v = 16;
            func_00263c60();
            func_0027a108();
            func_00287c90(1);
            func_00287c00(v);
            func_0028fb68(1, func_002891b8(D_0035f01c, r)->f408);
            v = func_002570a0(15);
            if (func_002891e8(D_0035f01c) != v) func_00257050(16, 0, 0);
            { v = func_00257070(15); if (v != func_002891e8(D_0035f01c)) func_00257050(16, 0, 0); func_00257050(15, func_002891e8(D_0035f01c), 0); }
            break;
        }
    }
end:
    if (func_00288040()) func_00288018();
}




}
