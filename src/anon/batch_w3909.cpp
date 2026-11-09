#include "../common/types.h"
extern "C" {
extern u32 D_0035f01c;
extern u32 D_0035f03c;
extern u32 D_0035f04c;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern s32 D_0035ef6c;
extern s32 D_0035f3d4;
extern u8 D_00373280;
u8* func_00257770(void);
void func_0028f4d8(s32, s32, s32);
u8* func_00256b68(s32);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_002817d8(s32, u32, u32, u32, s32, u8*, s32);
void func_002634d8(s32);
s32 func_00257130(void);
s32 func_00281f18(s32);
void func_00288d80(u32, s32, u32, u32, u32, s32, s16*, s16*);
u8* func_002891b8(u32, s32);
void func_00138c10(u8*, s32);
s32 func_0023aa98(u8*);
s32 func_0023aa78(u8*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_00138c68(u8*, s32, s32);
void func_00139620(u8*);
void func_00263210(void);
void func_0028dcc0(u8*, u8*);
u8* func_0023f1b0(u32);
s32 func_0023c4b8(u8*, u32);
s32 func_00236ca8(s32, u32);
s32 func_002570f0(void);
void func_0028bae0(u32, s32, s32, s32, s32, s32, s32, u8*, s32);
void func_00263858(s32);
s32 func_00287bc0(void);
s32 func_00257070(s32);
s32 func_00257088(s32);
void func_002891f0(u32, s32, s32, s32, s32);
void func_0028af90(u32, s32);
void func_0028afd0(u32, s32);
void func_0028b078(u32, s32, s32);
void func_0028b218(u32, s32);
void func_0028b248(u32, s32);
s32 func_0028af88(u32);
void func_0028af18(u32, s32);
void func_0025f7d8(void);
void func_00262820(void);
void func_00262a30(void);
void func_00257708(s32);
s32 func_00262650(void);
void func_002623c8(void);
void func_00287cc0(s32);

void func_0025ffd0(void)
{
    s16 tab[2][4];
    s32 cnt;
    s32 saved;
    s32 i = 0;
    u8* p;
    u8* base = func_00257770();
    func_0028f4d8(1, -1, 0);
    for (; i < 2; i++) {
        for (s32 k = 0; k < 4; k++) tab[i][k] = (i == 0) + 303;
    }
    u8* h = func_00256b68(1);
    func_0028d8c0(h, 0x753d, D_0035ef68, D_0035ef64, D_0035f03c, 293, 294, 0);
    u8* t = h + 24;
    *(s32*)(t + 184) |= 8;
    func_002817d8(0x753f, D_0035ef68, D_0035ef64, D_0035f03c, 0, &D_00373280, 0);
    saved = D_0035f3d4;
    D_0035f3d4 = 0x753e;
    func_002634d8(-1);
    cnt = func_00281f18(func_00257130());
    u8* q = base + 0x87d0;
    for (i = 0; i < 18; ) {
        func_00288d80(D_0035f01c, i, D_0035ef68, D_0035ef64, D_0035f03c, -1, tab[0], tab[1]);
        p = func_002891b8(D_0035f01c, i);
        func_00138c10(p, 304);
        *(s32*)(p + 392) = -1;
        u8* b = p + 24;
        s32 w = func_0023aa98(b);
        s32 hh = func_0023aa78(b);
        s32 x = func_0023aa18(b);
        s32 y = func_0023aa38(b);
        func_00138c68(p, (i % 2) * w, (i / 2) * hh);
        func_00139620(p);
        if (i++ < cnt) *(void (**)(void))(p + 436) = func_00263210;
        func_0028dcc0(p, h);
        func_0028d8c0(q, 0x7540, D_0035ef68, D_0035ef64, D_0035f03c, D_0035ef6c, -1, 0);
        func_0028dcc0(q, p);
        func_00138c68(q, x, y);
        q += 408;
    }
    D_0035f3d4 = saved;
    s32 n = cnt ? cnt : 1;
    h = func_00256b68(1);
    s32 c = func_0023c4b8(func_0023f1b0(D_0035f03c), D_0035ef68);
    s32 d = func_00236ca8(*(s32*)(func_0023f1b0(D_0035f03c) + 40), D_0035ef64);
    // p is reused for the half count (one pseudo for p and half gives the original registers)
    p = (u8*)(n / 2);
    p += n & 1;
    func_0028bae0(D_0035f04c, 0x753e, c, d, func_002570f0(), (s32)p, 9, h, 0);
    func_00263858(n);
    d = func_00287bc0();
    func_002891f0(D_0035f01c, func_00257070(d), 1, 0, 2);
    func_0028af90(D_0035f01c, n);
    func_0028afd0(D_0035f01c, func_00257088(d));
    func_0028b078(D_0035f01c, 2, 9);
    func_0028b218(D_0035f01c, 1);
    func_0028b248(D_0035f01c, 18);
    s32 fl = func_0028af88(D_0035f01c);
    fl |= 0xc000;
    if (!cnt) fl &= ~0x10;
    func_0028af18(D_0035f01c, fl);
    func_0025f7d8();
    func_00262820();
    func_00262a30();
    if (!cnt) func_00257708(1);
    if (!func_00262650()) func_002623c8();
    func_00287cc0(0);
}

}
