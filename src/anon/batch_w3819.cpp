#include "../common/types.h"
extern "C" {
u8* func_00257770(void);
s32 func_00139d78(void*);
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32);
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_002817d8(s32, s32, s32, s32, s32, s32, s32);
void func_00281e70(void*);
void func_0025f7d8(void);
s32 func_00257070(s32);
s32 func_00257130(void);
s32 func_00281f30(s32);
void func_00139620(void*);
void func_001395f8(void*);
void func_0028dcc0(void*, void*);
s32 func_00257140(s32);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
s32 func_0023aa78(void*);
void func_00138c68(void*, s32, s32);
s32 func_002570a0(s32);
s32 func_002635d8(s32);
s32 func_0028acc8(void*);
void func_00288d80(void*, s32, s32, s32, s32, s32, s16*, s16*);
u8* func_002891b8(void*, s32);
s32 func_00263660(s32);
s32 func_002637e8(s32);
u32 func_00192048(u16);
void func_002891f0(void*, s32, s32, s32, s32);
u16* func_002632d0(s32);
void func_00291068(void*, s32, u16, void*, s32, s32);
void func_00262af8(void);
s32 func_00281c30(void);
void func_00281cf0(u16);
void func_00287cc0(s32);
extern s32 D_0035f3d4;
/* The asm label only changes the symbol text gcse hashes: with it the three
   high-part pseudos get the original stack slot order (sp+32/36/40). */
extern s32 D_0035ef68 asm("D_0035ef68");
extern s32 D_0035ef64;
extern s32 D_0035f03c;
extern void* D_0035f01c;
extern void* D_0035f018;
extern u16 D_00373298[];

/* Sets up the menu objects for the current level, then one or two entries
   (436-byte objects at base+24304) in a loop. */
void func_00260808(void) {
    s16 tbl[2][4];
    u8* base;
    s32 i;
    s32 j;
    s32 r;
    s32 h;
    s32 lvl;
    s32 lm;
    u8* p;
    u8* q;
    u8* q2;
    u8* e;
    u8* o;
    u8* m;
    s32 x;
    s32 y;
    s32 k;
    s32 mo = -1;
    s32 n;
    s32 r2;

    i = 0;
    r = 0;
    base = func_00257770();
    for (; i < 2; i++) {
        for (j = 0; j < 4; j++) tbl[i][j] = 0x123;
    }
    lvl = D_0035f3d4;
    lm = lvl - 1;
    if (!func_00139d78(base)) func_0028d8c0(base, lm, D_0035ef68, D_0035ef64, D_0035f03c, 296, 297, 0);
    p = base + 0xb350;
    if (!func_00139d78(p)) func_0028d980(p, lm, D_0035ef68, D_0035ef64, D_0035f03c, 305, 306, -1, 0);
    q = base + 0x660;
    func_002817d8(lvl, D_0035ef68, D_0035ef64, D_0035f03c, 0, 0, 0);
    func_00281e70(p);
    func_0025f7d8();
    h = func_00257070(10);
    if (!func_00139d78(q)) {
        func_0028d980(q, lvl, D_0035ef68, D_0035ef64, D_0035f03c, 292, -1, -1, 0);
        r = func_00281f30(func_00257130());
        func_00139620(q);
        func_0028dcc0(q, base);
        *(s32*)(q + 408) = r + h * 80 + 16;
    }
    q2 = base + 0xd30;
    if (!func_00139d78(q2)) {
        func_0028d980(q2, lvl + 1, D_0035ef68, D_0035ef64, D_0035f03c, func_00257140(2), -1, -1, 0);
        func_00139620(q2);
        func_001395f8(q2);
        func_0028dcc0(q2, q);
        m = base + 1656;
        x = func_0023aa18(m);
        y = func_0023aa38(m);
        func_00138c68(q2, x, y);
        *(s32*)(q2 + 432) = 1;
        *(s32*)(q2 + 408) = r + h * 80;
    }
    h = func_002570a0(10);
    r2 = func_002635d8(h) ? 2 : 1;
    if (!func_0028acc8(D_0035f01c)) {
        i = 0;
        if (i < r2) { o = base + 24304; do {
            func_00288d80(D_0035f01c, i, D_0035ef68, D_0035ef64, D_0035f03c, mo, tbl[0], tbl[1]);
            e = func_002891b8(D_0035f01c, i);
            *(s32*)(e + 392) = mo;
            func_00138c68(e, 0, func_0023aa78(e + 24) * i);
            func_00139620(e);
            func_0028dcc0(e, base);
            if (!func_00263660(h) && func_002637e8(i)) k = 1; else k = 0;
            func_0028d980(o, lvl + 1, D_0035ef68, D_0035ef64, D_0035f03c,
                          func_00257140(k), -1, -1, 0);
            func_00139620(o);
            func_001395f8(o);
            func_0028dcc0(o, e);
            n = i;
            n++;
            if (!func_002635d8(h)) i = n;
            *(u32*)(o + 408) = func_00192048(D_00373298[i]);
            i = n;
            o += 436;
        } while (i < r2); }
        func_002891f0(D_0035f01c, 0, 1, 0, 2);
    }
    func_00291068(D_0035f018, 0, *func_002632d0(h), base + 0xb350, -1, 0);
    func_00262af8();
    if (!func_00281c30()) func_00281cf0(func_002632d0(h)[10]);
    func_00287cc0(0);
}
}
