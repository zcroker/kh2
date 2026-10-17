#include "../common/types.h"
extern "C" {

void func_00256a58(void);
void func_00263340(s32, s32, s32);
void func_00266678(s32, s32, s32);
s32 func_00267270(void);
void func_0026a238(s32, s32, s32);
void func_00273228(s32, s32, s32);
void func_0027bbe0(s32, s32, s32);
void func_0027d598(s32, s32, s32);
s32 func_00287cd0(void);
void func_00289038(s32, s32, s32, s32, s32, s32, s32);
void func_002890e0(s32, s32, s32, s32, s32);
void* func_002891d0(s32);
s32 func_002891e8(s32);
s32 func_00289310(s32);
s32 func_00289358(s32);
void func_0028cf28(s32, void*);
s32 func_0028d008(s32);
void func_0028d660(s32, void*);
s32 func_0028d6e8(s32);
extern s32 D_0035f050;

void func_002566f0(s32 a0, s32 a1, s32 a2) {
    s32 s1 = func_00289310(a0);
    if (func_00287cd0() != 1) return;
    if (s1 == 0 && a1 == 24) s1 = func_00267270();
    if (s1 != 0) {
        s32 s4 = func_002891e8(a0);
        if (a1 != 2 && a1 != 5 && a1 != 6 && a1 != 7 && a1 != 8 && a1 != 9) {
            func_002890e0(a0, 1, 2, 0, -1);
            func_00289038(a0, s4, 1, 1, 2, 0, -1);
        }
        if (func_0028d008(a2) != 0) {
            func_0028cf28(a2, func_002891d0(a0));
        }
        if (func_0028d6e8(D_0035f050) != 0) {
            void* p;
            if (a1 == 36) p = *(void**)((u8*)func_002891d0(a0) + 0x18c);
            else p = func_002891d0(a0);
            func_0028d660(D_0035f050, p);
        }
    }
    if (s1 == 0 && func_00289358(a0) == 0) return;
    if (a1 == 0) { func_00256a58(); return; }
    if (a1 == 1 || a1 == 10 || a1 == 11 || a1 == 12 || a1 == 13 || a1 == 14) { func_00263340(a0, a1, a2); return; }
    if ((u32)(a1 - 15) < 5) { func_0027bbe0(a0, a1, a2); return; }
    if (a1 == 2 || a1 == 5 || a1 == 6 || a1 == 7 || a1 == 8 || a1 == 9) { func_0026a238(a0, a1, a2); return; }
    if ((u32)(a1 - 25) < 3 || a1 == 29 || a1 == 30 || a1 == 31 || a1 == 32 || a1 == 33) { func_00273228(a0, a1, a2); return; }
    if (a1 == 36) { func_0027d598(a0, 36, a2); return; }
    if ((u32)(a1 - 23) < 2) { func_00266678(a0, a1, a2); return; }
}


s32 func_00242848(s32);
void func_00274cf0(s32);
void func_00275b60(void);
void func_00276220(s32, s32);
s32 func_00276358(void);
s32 func_00276368(void);
s32 func_00276398(void);
void func_002765e8(s32, s32, s32);
void func_002766b0(s32);
s32 func_00276888(void);
void func_00276dc0(void);
s32 func_00287bc0(void);
void func_00287c00(s32);
void func_00287c30(void);
void func_00287c90(s32);
void func_00287cc0(s32);
void func_00287da0(void);
s32 func_00287df0(s32, s32, s32, s32, s32);
void func_00287f90(s32);
void func_00288018(void);
s32 func_00288040(void);
s32 func_00289380(s32);
s32 func_0028acc8(s32);
void func_0028af18(s32, s32);
s32 func_0028b038(s32);
void func_0028f6f0(s32);
void func_002925c0(void);
s32 func_00292630(void);
void func_002926c0(s32);
void func_002927b8(void);
void func_00292870(void);
void func_002995e8(void);
void func_002a2600(void);
void func_002aece8(void);
void func_002aecf0(s32);
void func_002af418(void);
void func_002b01d8(void);
void func_002b3b78(void);
extern s32 D_0035f200;
struct S374cb0 { s16 a; s16 b; };
extern S374cb0 D_00374cb0[];

void func_002af0a0(void)
{
    s32 sel = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (sel != -1) {
                func_00287f90(0);
                func_002aecf0(1);
            }
            return;
        }
        if (func_00292630()) return;
        func_002aecf0(1);
        func_00287c30();
        s32 k = func_00287bc0();
        func_0028af18(D_0035f200, 115);
        func_00276220(func_00276358(), 0);
        switch (k) {
        case 13:
            func_00274cf0(13);
            func_002925c0();
            func_002766b0(0);
            func_002927b8();
            func_002926c0(1);
            func_00292870();
            func_002995e8();
            return;
        case 33: func_002a2600(); return;
        case 31: func_002b01d8(); return;
        case 28: func_002af418(); return;
        }
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f200)) && !func_00276398()) {
        func_00276220(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398()) func_00287c90(1);
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f200), 1, (s32)func_002b3b78, 1)) == 0) {
        switch (sel) {
        case -1: break;
        case -4: {
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            func_00287da0();
            break;
        }
        case -2: {
            func_0028f6f0(0);
            func_002aece8();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(13);
            func_00287cc0(2);
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            break;
        }
        default: {
            func_002aece8();
            func_00276dc0();
            func_00276220(0, 1);
            func_00287c00(D_00374cb0[sel].b);
            func_00287cc0(2);
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            break;
        }
        }
    }
    if (func_00288040()) func_00288018();
}

s32 func_00233e60(void);
s32 func_00233e70(s32);
s32 func_002348a8(s32, s32);
void func_00234570(s32, s32);
s32 func_00240ba0(void);
void func_00240be0(void);
void func_0025dba8(void);
void func_00287bd0(s32, s32);
s32 func_00287c10(void);
void func_00287d20(s32);
s32 func_0028abe0(s32);
s32 func_0028ae28(s32, s32);
void func_0028f7e8(s32);
void func_002b4ee0(void);
void func_002b4f50(void);
s32 func_002b4fb8(void);
s32 func_002b50e8(void);
void func_002b50f8(void);
void func_002b5108(s32, s32);
void func_002b5188(void*, s32);
void func_002b5558(void);
bool func_002b55e0(void);
void func_002b5af0(void);
extern u8 D_0035f0b3;
extern s32 D_0035f650;
extern u8 D_00373110[];

void func_0025dfb0(void)
{
    s32 sel;
    s32 st = func_00287cd0();
    if (st == 2) {
        sel = func_00289380(D_0035f650);
        s32 m = func_00287c10();
        s32 r;
        if (m == st) r = func_0028acc8(D_0035f650);
        else r = func_002b4fb8();
        if (r) {
            if (sel != -1 || func_00289310(D_0035f650)) {
                if (m == 2) {
                    func_0028abe0(D_0035f650);
                    return;
                }
                func_002b4f50();
            }
            return;
        }
        bool ok = 1;
        if ((u32)(m - 1) < 2) ok = !func_002b55e0();
        if (ok) {
            sel = 1;
            if (m == sel) {
                func_00233e70(0);
                if (!func_00233e60()) return;
            }
            func_00287c30();
            func_00287d20(0);
            s32 t = func_00287bc0();
            if (t == sel) {
                func_002b5af0();
                func_0028f7e8(1);
                func_0025dba8();
            } else if (t == 12) {
                func_002b5188(D_00373110, 1);
            } else if (t == 2) {
                func_00240be0();
            }
            func_00288018();
        }
        D_0035f0b3 = 1;
        return;
    }
    if (!func_00233e70(0)) {
        if (D_0035f0b3) {
            s32 h = func_00240ba0();
            if (func_002348a8(h, 0) != 3) {
                if (func_00287bc0() == 5) {
                    func_002b5108(0x8a89, h);
                    func_00287c00(2);
                    func_0028abe0(D_0035f650);
                    func_002b5558();
                    func_00287cc0(2);
                }
                func_00234570(h, 0);
                return;
            }
            if (func_00287bc0() != 5) {
                func_002b5108(0xb85d, h);
                func_00287bd0(5, func_00287cd0());
                func_00234570(h, 0);
                return;
            }
            func_00234570(h, 0);
        }
        func_002b50f8();
    }
    if (func_002b50e8()) return;
    if (st == 0) {
        if (func_0028ae28(D_0035f650, 0)) func_00287cc0(1);
        sel = -1;
    } else {
        sel = func_00289380(D_0035f650);
    }
    s32 k = func_00287bc0();
    if (!func_00242848(func_00287df0(sel, func_00289310(D_0035f650), 0, 0, 1))) {
        switch (sel) {
        case -1: break;
        case -2:
        case 0:
            if (k == 10) {
                func_00287c00(12);
            } else {
                func_002b5558();
                func_00287c00(1);
                func_0028f6f0(1);
            }
            func_002b4ee0();
            func_00287cc0(2);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}


u8* func_002766d0(void);
s32 func_0028afa8(s32);
void func_0028af90(s32, s32);
u8* func_002891b8(s32, s32);
s32 func_00192048(u16);
void func_00138c10(u8*, s32);
s8* func_00276568(void);
s32 func_002a1b18(s32, s32);
s32 func_002ae1b0(s32, s32);
s32 func_002abff0(s32, s32);
s32 func_002ac110(s32, s32);
s32 func_002ae0c0(s32);
s32 func_002aa668(s32, s32);
s32 func_002aa788(s32, s32);
s32 func_002ad4a8(s32);
s32 func_002a4380(s32);
s32 func_002ab540(s32);
s32 func_002ab620(s32);
s32 func_002adaf0(s32);
s32 func_002b3ae8(void);
s32 func_00276c18(void);
s32 func_002ac748(s32);
s32 func_002ac800(s32);
s32 func_002ae890(s32);
s32 func_002ab8e8(s32);
s32 func_002ab9c8(s32);
s32 func_002adcb0(s32);
s32 func_002a9b88(s32);
s32 func_002aae88(s32);
s32 func_002aaf40(s32);
s32 func_002ad7d0(s32);
s32 func_002a8870(s32);
s32 func_002ab2b0(s32);
s32 func_002ab368(s32);
s32 func_002ad950(s32);
extern s32 D_00374750;
extern s32 D_00374754;
extern u16 D_00374758[];

void func_00295d28(void)
{
    s32 i = 0;
    s32 cnt = 0;
    u8* base = func_002766d0();
    s32 n = func_0028afa8(D_0035f200);
    for (; i < n; i++) {
        s32 c = 0;
        s32 b = 0;
        s32 a = 0;
        s32 r;
        switch (i) {
        case 0:
            r = func_002a1b18(0, -1);
            if (r) { a = 1; b = r == 2; }
            c = func_002ae1b0(0, *func_00276568());
            break;
        default:
            break;
        case 1:
            a = func_002abff0(*func_00276568(), -1);
            b = func_002ac110(*func_00276568(), -1);
            c = func_002ae0c0(*func_00276568());
            break;
        case 2:
            a = func_002aa668(*func_00276568(), -1);
            b = func_002aa788(*func_00276568(), -1);
            c = func_002ad4a8(*func_00276568());
            break;
        case 3:
            if (func_002a4380(*func_00276568())) continue;
            a = func_002ab540(*func_00276568());
            b = func_002ab620(*func_00276568());
            c = func_002adaf0(*func_00276568());
            break;
        case 4:
            if (!func_002b3ae8() && !func_00276c18()) continue;
            a = func_002ac748(*func_00276568());
            b = func_002ac800(*func_00276568());
            c = func_002ae890(*func_00276568());
            break;
        case 5:
            a = func_002ab8e8(*func_00276568());
            b = func_002ab9c8(*func_00276568());
            c = func_002adcb0(*func_00276568());
            break;
        case 6:
            if (!func_002a9b88(*func_00276568())) continue;
            a = func_002aae88(*func_00276568());
            b = func_002aaf40(*func_00276568());
            c = func_002ad7d0(*func_00276568());
            break;
        case 7:
            if (!func_002a8870(*func_00276568())) continue;
            a = func_002ab2b0(*func_00276568());
            b = func_002ab368(*func_00276568());
            c = func_002ad950(*func_00276568());
            break;
        case 8:
            r = func_002a1b18(1, -1);
            if (r) { a = 1; b = r == 2; }
            c = func_002ae1b0(1, 16);
            break;
        }
        u8* o = func_002891b8(D_0035f200, cnt);
        *(s32*)(o + 0x198) = func_00192048(D_00374758[i]);
        if (a) { s32 v; if (b) v = D_00374754; else v = D_00374750; func_00138c10(base + cnt * 408 + 0xa998, v); }
        if (c) func_00138c10(base + cnt * 408 + 0x7698, 160);
        cnt++;
    }
    func_0028af90(D_0035f200, cnt);
}

}
