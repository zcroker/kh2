#include "../common/types.h"
extern "C" {
extern u32 D_0035f01c;
extern u32 D_0035f010;
extern u32 D_0035f03c;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern s32 D_0035ef6c;
extern s32 D_0035f3d4;
extern u8* D_0035f230;
extern s32 D_00373dfc;
extern s32 D_00373e00;
u8* func_00257770(void);
void func_0028f4d8(s32, s32, s32);
s32 func_00257100(s32);
void func_00288d80(u32, s32, u32, u32, u32, s32, s32, s32);
void func_00288e08(u32, s32, s32, s32);
u8* func_002891b8(u32, s32);
void func_00139620(u8*);
void func_001395f8(u8*);
s32 func_00281140(u32, s32);
s32 func_00281180(u32, s32);
s32 func_00281100(u32);
s32 func_0023aa98(u8*);
s32 func_00277708(s32);
void func_00138c68(u8*, s32, s32);
s32 func_00257070(s32);
s32 func_002892f8(u32);
void func_00257050(s32, s32, s32);
void func_002891f0(u32, s32, s32, s32, s32);
s32 func_0028afa8(u32);
void func_0027aed8(s32, s32*, s32*);
s32 func_00286d28(s32, s32);
s32 func_00287028(s32, s32);
s32 func_0027ae78(s32);
s32 func_00286ec8(s32, s32);
s32 func_00287218(s32, s32);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_0028dcc0(u8*, u8*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_00279cd8(void);
void func_00279ec8(void);
s32 func_0028af88(u32);
s32 func_00258068(s32);
void func_00256cc0(s32, s32, s32);
void func_0028af18(u32, s32);
void func_00287cc0(s32);

// 002772c8: sets up the list in D_0035f01c (first entry, up to three more entries chosen by
// func_00281180, then one row per entry), then sets its flags. Built with -fmove-all-movables.
// Partial asm (no code emitted): p is pinned to s2 with empty "+r" ties so the call result is
// used straight from v0 like the original; w doubles as the first product term so it gets s1.
void func_002772c8(s32 arg)
{
    s32 flag;
    s32 w;
    s32 id;
    s32 saved;
    s32 i = 1;
    u8* base = func_00257770();
    func_0028f4d8(0, -1, 0);
    saved = D_0035f3d4;
    D_0035f3d4 = 0x7541;
    s32 a = func_00257100(0);
    s32 b = func_00257100(1);
    func_00288d80(D_0035f01c, 0, D_0035ef68, D_0035ef64, D_0035f03c, -1, a, b);
    func_00288e08(D_0035f01c, 0, 0, -1);
    u8* t = func_002891b8(D_0035f01c, 0);
    register u8* p asm("$18") = t;
    asm("" : "+r"(p));
    func_00139620(t);
    *(s32*)(p + 0x198) = func_00281140(D_0035f010, 0);
    func_001395f8(p);
    s32 x = func_0023aa98(p + 0x18);
    s32 m = func_00277708(1);
    s32 n = m + 1;
    w = func_0023aa98(func_002891b8(D_0035f01c, m) + 0x18);
    { s32 q = w * m; m = q; }
    x += m;
    do {
        if (func_00281180(D_0035f010, i)) {
            m = func_00257100(0);
            s32 b2 = func_00257100(1);
            func_00288d80(D_0035f01c, n, D_0035ef68, D_0035ef64, D_0035f03c, -1, m, b2);
            t = func_002891b8(D_0035f01c, n++);
            p = t;
            asm("" : "+r"(p));
            w = func_0023aa98(t + 0x18);
            func_00138c68(p, 0, x);
            x += w;
            func_00139620(p);
            *(s32*)(p + 0x198) = func_00281140(D_0035f010, i);
            func_001395f8(p);
        }
        i++;
    } while (i < 4);
    D_0035f3d4 = saved;
    D_0035f230[6] = n;
    s32 sel = func_00257070(15);
    if (arg >= 0) {
        s32 v = 0;
        if (arg != 0) v = func_002892f8(D_0035f01c) - func_00281100(D_0035f010) + arg;
        if (sel != v) {
            sel = v;
            func_00257050(16, 0, 0);
            func_00257050(15, v, 0);
        }
    }
    func_002891f0(D_0035f01c, sel, 1, 0, 2);
    i = 0;
    s32 cnt = func_0028afa8(D_0035f01c);
    if (cnt > 0) {
        u8* q = base + 0x87d0;
        do {
            func_0027aed8(i, &flag, &id);
            s32 c = D_0035ef6c;
            s32 r;
            if (!flag) {
                if (!func_00286d28(id, -1)) goto skip;
                r = func_00287028(id, -1);
            } else {
                if (!func_00286ec8(func_0027ae78(id), -1)) goto skip;
                r = func_00287218(func_0027ae78(id), -1);
            }
            c = r ? D_00373e00 : D_00373dfc;
        skip:
            func_0028d8c0(q, 0x7541, D_0035ef68, D_0035ef64, D_0035f03c, c, -1, 0);
            u8* p3 = func_002891b8(D_0035f01c, i++);
            func_0028dcc0(q, p3);
            u8* f = p3 + 0x18;
            s32 g = func_0023aa18(f);
            func_00138c68(q, g, func_0023aa38(f));
            q += 0x198;
        } while (i < cnt);
    }
    func_00279cd8();
    func_00279ec8();
    s32 fl = func_0028af88(D_0035f01c);
    if (func_00258068(0)) {
        fl |= 0x100;
        func_00256cc0(0xb373, -1, -1);
    }
    func_0028af18(D_0035f01c, fl);
    func_00287cc0(0);
}
}
