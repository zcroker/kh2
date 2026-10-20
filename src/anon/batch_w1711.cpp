#include "../common/types.h"
extern "C" {
extern s32 D_0035f01c;
extern s32 D_0035f010;
extern s8 D_0035f129;
extern u16 D_00373a18[];
extern u16 D_00373a28[];

s32 func_00289380(s32);
s32 func_00287cd0(void);
s32 func_00287c10(void);
s32 func_0028f930(s32);
s32 func_00256ef0(void);
s32 func_00272428(void);
s32 func_00257970(void);
s32 func_00289310(s32);
void func_00287f90(s32);
void func_002723e0(void);
void func_00256ea8(void);
void func_00287c30(void);
void func_0028af18(s32, s32);
void func_0028f7e8(s32);
void func_0026ee78(void);
void func_00257050(s32, s32, s32);
s32 func_00281140(s32, s32);
void func_0028fb68(s32, s32);
s32 func_00257070(s32);
void func_00271b58(s32);
void func_0026f388(void);
void func_002700f0(void);
s32 func_00272538(void);
void func_00272468(void);
void func_0028fa98(s32);
void func_00256e30(void);
void func_00272c90(s32);
void func_00287c90(s32);
s32 func_0028afa8(s32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_00287da0(void);
s32 func_002891e8(s32);
s32 func_0028b038(s32);
s32 func_00288040(void);
void func_00288018(void);
s8 func_00273de0(s32, s32);
void func_00263c60(void);
void func_00256e80(void);
void func_0028f6f0(s32);
void func_00272340(void);
void func_00287c00(s32);
s32 func_0028b040(s32);
s32 func_00272b60(s32);
s32 func_00287bc0(void);
void func_00287bd0(s32, s32);
void func_002831e0(s32, s32);
void func_002713c8(void);
void func_002736f8(void);
void func_00273cb8(s32);
void func_00273c40(s32);
s32 func_00273b30(void);
void func_0026ff30(void);
void func_00273818(void);
void func_0028fb28(s32, s32);
void func_00273e88(void);

void func_0026f920(void)
{
    s32 flag = 0;
    s32 sel = func_00289380(D_0035f01c);
    s32 st = func_00287cd0();
    if (st == 2) {
        s32 next = func_00287c10();
        if (next >= 25 && next <= 27) flag = func_0028f930(1);
        if (next != 26 && next != 27) flag = flag || func_00256ef0();
        if (func_00272428() || flag || func_00257970()) {
            if (sel != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                func_002723e0();
                if (next != 26 && next != 27) func_00256ea8();
            }
            return;
        }
        func_00287c30();
        func_0028af18(D_0035f01c, 0x73);
        if (next == 25) {
            func_0028f7e8(1);
            func_0026ee78();
            return;
        }
        if (next == 26 || next == 27) {
            func_00257050(25, D_0035f129, 0);
            func_0028fb68(1, func_00281140(D_0035f010, D_0035f129));
            D_0035f129 = -1;
            func_00271b58(func_00257070(25));
            func_0026f388();
            return;
        }
        func_002700f0();
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f01c)) && !func_00272538()) {
        func_00272468();
        func_0028fa98(-1);
        func_00256e30();
    }
    if (st == 0 && func_00272538()) {
        func_00272c90(1);
        func_00287c90(1);
    }
    s32 type;
    s32 n = func_0028afa8(D_0035f01c);
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f01c), 1, (s32)func_00273e88, 1)) == 0) {
        switch (sel) {
        case -1:
            break;
        case -4: {
            func_00287da0();
            s32 cur = func_002891e8(D_0035f01c);
            func_00257050(26, cur, func_0028b038(D_0035f01c));
            break;
        }
        case -11:
        case -10:
            D_0035f129 = func_00273de0(sel == -10, 0);
            func_00263c60();
            func_00256e80();
            func_0028f6f0(1);
            func_00272340();
            func_00287c90(1);
            func_00287c00(D_0035f129 == 0 ? 26 : 27);
            func_00257050(26, 0, 0);
            break;
        case -7: {
            type = func_00272b60(func_0028b040(D_0035f01c));
            n = func_00287bc0();
            func_00287bd0(37, 0);
            if (type == 2) func_002831e0(0, n);
            else if (type == 1) func_002831e0(1, n);
            break;
        }
        case -6:
            switch (func_00272b60(func_0028b040(D_0035f01c))) {
            case 1:
                func_002736f8();
                break;
            case 2:
                if (func_00273b30()) {
                    func_0026ff30();
                    func_00287bd0(28, 0);
                } else {
                    func_00273818();
                }
                break;
            case 3:
                func_00273c40(-1);
                break;
            case 4:
                func_00273cb8(-1);
                break;
            }
            func_002713c8();
            func_00272c90(0);
            break;
        case -2: {
            func_00263c60();
            func_00256e80();
            func_0028f6f0(1);
            func_00272340();
            func_00287c90(1);
            func_00287c00(25);
            s32 cur = func_002891e8(D_0035f01c);
            func_00257050(26, cur, func_0028b038(D_0035f01c));
            break;
        }
        default:
            if (sel >= 0 && sel < n) {
                s32 id = -1;
                type = func_00272b60(sel);
                switch (type) {
                case 0: id = 29; break;
                case 1: id = 30; break;
                case 2: id = 31; break;
                case 3: id = 32; break;
                case 4: id = 33; break;
                }
                if (type == 0) func_0028fb28(2, D_00373a28[sel]);
                else func_0028fb28(2, D_00373a18[type]);
                func_00256e80();
                func_00263c60();
                func_00272340();
                func_00287c90(1);
                func_00287c00(id);
                id = func_00257070(25);
                if (func_002891e8(D_0035f01c) != id) func_00257050(26, 0, 0);
                s32 cur = func_002891e8(D_0035f01c);
                func_00257050(26, cur, func_0028b038(D_0035f01c));
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}
