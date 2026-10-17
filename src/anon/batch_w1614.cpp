#include "../common/types.h"
extern "C" {
struct Ent36 { u8 pad[8]; u8 text[10]; u16 id; u8 pad2[16]; };
extern Ent36 D_00372a28[];
extern s8 D_0035f05b;
extern s8 D_0035f05c;
extern u32 D_0035f01c;
extern u32 D_0035f020;
extern u32 D_0035f024;
extern u8* D_0035f038;
extern u32 D_0035f03c;
extern s32 D_0035f3d4;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern u16 D_0035ef70;
extern s32 D_00372968;
extern s32 D_0037296c;
void func_002937c0(void);
void func_00288f48(u32, s32, s32, s32, s32);
void func_0028b1e8(u32, s32);
s32 func_00257e00(void);
void func_00288d80(u32, s32, u32, u32, u32, u16, Ent36*, u8*);
void func_00288e08(u32, s32, u32, s32);
u8* func_002891b8(u32, s32);
void func_00139620(u8*);
void func_001395f8(u8*);
u32 func_0023aa18(u8*);
u32 func_0023aa38(u8*);
s32 func_00285d58(s32);
s32 func_00285e30(s32);
s32 func_00286d28(s32, s32);
s32 func_00286ec8(s32, s32);
s32 func_00287028(s32, s32);
s32 func_00287218(s32, s32);
s32 func_00286068(s32);
s32 func_00286160(s32);
s32 func_00286418(s32);
s32 func_002864f8(s32);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_0028dcc0(u8*, u8*);
void func_00138c68(u8*, u32, u32);
s32 func_00257070(s32);
s32 func_00257ff8(s32);
void func_002891f0(u32, s32, s32, s32, s32);
void func_00254ab8(void);
void func_0027dee8(s32, s32, s32);
s32 func_00287bc0(void);
void func_00287bd0(s32, s32);
void func_002831e0(s32, s32);
void func_002551b8(void)
{
    if (!D_0035f05b) func_002937c0();
    func_00288f48(D_0035f01c, 16, 32, 0, 0);
    func_00288f48(D_0035f020, 16, 32, 0, 0);
    func_00288f48(D_0035f024, 16, 32, 0, 0);
    s32 n = 0;
    s32 r;
    func_0028b1e8(D_0035f024, 0);
    D_0035ef70 = func_00257e00();
    s32 k = D_0035f3d4 + 1;
    for (s32 i = 0; i < 8; i++) {
        if (((D_0035ef70 >> i) ^ 1) & 1 & 0xff) continue;
        r = -1;
        Ent36* e = (Ent36*)((u8*)(i * 36) + (u32)D_00372a28);
        func_00288d80(D_0035f01c, n, D_0035ef68, D_0035ef64, D_0035f03c, e->id, e, (u8*)(i * 36) + (u32)D_00372a28[0].text);
        func_00288e08(D_0035f01c, n, 0, -1);
        u8* o = func_002891b8(D_0035f01c, n);
        func_00139620(o);
        func_001395f8(o);
        u32 a = func_0023aa18(o + 24);
        u32 b = func_0023aa38(o + 24);
        if (i == 0) {
            if (func_00285d58(-1)) r = func_00285e30(-1) ? D_0037296c : D_00372968;
        } else if (i == 1) {
            if (func_00286d28(-1, -1) || func_00286ec8(-1, -1)) {
                if (func_00287028(-1, -1)) r = func_00287218(-1, -1) ? D_0037296c : D_00372968;
                else r = D_00372968;
            }
        } else if (i == 2) {
            if (func_00286068(-1)) r = func_00286160(-1) ? D_0037296c : D_00372968;
        } else if (i == 4) {
            if (func_00286418(-1)) r = func_002864f8(-1) ? D_0037296c : D_00372968;
        } else if (i == 5) {
            if (D_0035f05c) r = 50;
        }
        if (r >= 0) {
            func_0028d8c0(D_0035f038 + i * 408 + 0x87d0, k, D_0035ef68, D_0035ef64, D_0035f03c, r, -1, 0);
            func_0028dcc0(D_0035f038 + i * 408 + 0x87d0, o);
            func_00138c68(D_0035f038 + i * 408 + 0x87d0, a, b);
        }
        n++;
    }
    r = func_00257ff8(func_00257070(0));
    if (r < 0) r = 0;
    func_002891f0(D_0035f01c, r, 1, 0, 2);
    func_00254ab8();
    func_0027dee8(0, 0, 4);
    if (D_0035f05b) {
        r = func_00287bc0();
        func_00287bd0(37, 0);
        func_002831e0(-1, r);
        D_0035f05b = 0;
    }
}
extern s32 D_0035f650;
extern s32 D_0035f64c;
s32 func_00287cd0(void);
s32 func_00289380(s32);
s32 func_00287c10(void);
s32 func_0028acc8(s32);
s32 func_002b4fb8(void);
s32 func_00289310(s32);
void func_0028abe0(s32);
void func_002b4f50(void);
void func_00233e70(s32);
s32 func_00233e60(void);
void func_00287c30(void);
void func_00287d20(s32);
s32 func_00240ba0(void);
s32 func_00287bc0(void);
void func_002b5af0(void);
void func_0028f7e8(s32);
void func_0025a1d0(void);
void func_00288018(void);
void func_002b4c88(s32);
void func_002b5108(s32, s32);
void func_002345f0(s32, s32);
void func_00241450(s32);
void func_002400f8(s32);
bool func_0028acc8b(s32) asm("func_0028acc8");
s32 func_00233e70b(s32) asm("func_00233e70");
void func_002b50f8(void);
s32 func_002348a8(s32, s32);
void func_00234570(s32, s32);
void func_00287c00(s32);
s32 func_002b50e8(void);
s32 func_0028ae28(s32, s32);
void func_00287cc0(s32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_002b4ee0(void);
void func_0028aa40(s32);
void func_002b5558(void);
void func_0028f6f0(s32);
static inline __attribute__((always_inline)) bool chk(s32 st)
{
    if (st == 1) return !func_0028acc8b(D_0035f64c);
    return true;
}
void func_0025aa10(void)
{
    s32 mode = func_00287cd0();
    if (mode == 2) {
        s32 r = func_00289380(D_0035f650);
        s32 st = func_00287c10();
        s32 c;
        if (st == 9 || st == 14) c = func_0028acc8(D_0035f650);
        else c = func_002b4fb8();
        if (c) {
            if (r != -1 || func_00289310(D_0035f650)) {
                if (st == 9 || st == 14) func_0028abe0(D_0035f650);
                else func_002b4f50();
            }
            return;
        }
        if (!chk(st)) return;
        if (st == 1) {
            func_00233e70(0);
            if (!func_00233e60()) return;
        }
        func_00287c30();
        func_00287d20(0);
        s32 h = func_00240ba0();
        s32 m = func_00287bc0();
        if (m == 1) {
            func_002b5af0();
            func_0028f7e8(1);
            func_0025a1d0();
        } else if (m == 5) {
            func_002b4c88(0);
        } else if (m == 9) {
            func_002b5108(0x8a8f, h);
            func_00287d20(20);
            func_002345f0(h, 0);
        } else if (m == 14) {
            func_00241450(1);
            func_002b5108(0x8a90, h);
            func_00287d20(70);
            func_002400f8(1);
        }
        func_00288018();
        return;
    }
    func_0028acc8(D_0035f650);
    if (!func_00233e70b(0)) {
        func_002b50f8();
        s32 h = func_00240ba0();
        if (func_002348a8(h, 0) != 3) {
            func_00234570(h, 0);
        } else {
            func_002b5108(0xb85d, h);
            func_00287c00(5);
            func_00234570(h, 0);
            func_0028abe0(D_0035f650);
            func_00287cc0(2);
            return;
        }
    }
    if (func_002b50e8()) return;
    if (mode == 0 && func_0028ae28(D_0035f650, 0)) func_00287cc0(1);
    if (mode != 1) return;
    s32 r = func_00289380(D_0035f650);
    if (func_00242848(func_00287df0(r, func_00289310(D_0035f650), 0, 0, 1))) return;
    s32 m = func_00287bc0();
    switch (r) {
    case -1:
        break;
    case -2:
    case 0:
        if (m == 8 || m == 13) func_00287c00(12);
    b:
        func_002b4ee0();
    c:
        func_0028aa40(D_0035f650);
        func_00287cc0(2);
        break;
    case 1:
        if (m == 8) {
            func_00287c00(9);
            goto c;
        }
        if (m == 13) {
            func_00287c00(14);
            goto c;
        }
        func_002b5558();
        func_00287c00(1);
        func_0028f6f0(1);
        goto b;
    }
}
s32 func_00289380(s32);
s32 func_00287cd0(void);
s32 func_00287c10(void);
s32 func_00262650(void);
s32 func_0028f930(s32);
s32 func_00262290(void);
s32 func_00257970(void);
s32 func_00281c30(void);
s32 func_00289310(s32);
void func_00287f90(s32);
void func_00262208(void);
void func_00262588(void);
void func_00257708(s32);
void func_00287c30(void);
void func_0028b0e0(s32);
s32 func_00287bc0(void);
void func_0028af18(s32, s32);
void func_0028f7e8(s32);
void func_0025f7f0(s32);
void func_0025ffd0(void);
void func_00260808(void);
s32 func_00262300(void);
void func_00262360(void);
void func_00262730(void);
void func_0028fa98(s32);
void func_00287c90(s32);
void func_002638e0(void);
s32 func_00287df0_p(s32, s32, s32, void (*)(void), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_00287da0(void);
void func_00263570(s32);
void func_00263c60(void);
void func_002621a0(void);
void func_00281b30(void);
void func_00287c00(s32);
void func_00257050(s32, s32, s32);
void func_0025f7d8(void);
void func_00262538(void);
s32 func_002891e8(s32);
s32 func_0028b038(s32);
void func_0028f6f0(s32);
void func_00281d48(void);
void func_00281e20(void);
s32 func_00288040(void);
void func_00288018(void);
void func_00260418(void)
{
    s32 x = 0;
    s32 r = func_00289380(D_0035f01c);
    s32 st = func_00287cd0();
    if (st == 2) {
        st = func_00287c10();
        if (st != 10) {
            x = func_00262650();
            if (st == 1) x = x || func_0028f930(1);
        }
        if (func_00262290() || x || func_00257970() || func_00281c30()) {
            if (r != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                func_00262208();
                if (st != 10) func_00262588();
            }
            return;
        }
        func_00257708(0);
        func_00287c30();
        func_0028b0e0(D_0035f01c);
        s32 m = func_00287bc0();
        func_0028af18(D_0035f01c, 115);
        if (m == 1) {
            func_0028f7e8(1);
            func_0025f7f0(-1);
        } else if (m == 10) {
            func_0025ffd0();
        } else if (m == 11) {
            func_00260808();
        }
        return;
    }
    if ((r != -1 || func_00289310(D_0035f01c)) && !func_00262300()) {
        func_00262360();
        func_00262730();
        func_0028fa98(-1);
    }
    if (st == 0 && func_00262300()) func_00287c90(1);
    if (!func_00242848(func_00287df0_p(r, func_00289310(D_0035f01c), 1, func_002638e0, 1))) {
        switch (r) {
        case -4:
            func_00287da0();
            break;
        case -1:
            break;
        case -11:
        case -10:
            func_00263570(r);
            func_00263c60();
            func_002621a0();
            func_00281b30();
            func_00287c90(1);
            func_00287c00(func_00287bc0());
            func_00257050(10, 0, 0);
            func_0025f7d8();
            break;
        default:
            func_00263c60();
            func_002621a0();
            func_00262538();
            func_00281b30();
            func_00287c90(1);
            func_00287c00(11);
            {
                s32 a = func_002891e8(D_0035f01c);
                func_00257050(10, a, func_0028b038(D_0035f01c));
            }
            func_0025f7d8();
            break;
        case -2:
            func_00263c60();
            func_00262538();
            func_0028f6f0(1);
            func_002621a0();
            func_00281b30();
            func_00287c90(1);
            func_00287c00(1);
            func_0025f7d8();
            func_00257050(10, 0, 0);
            break;
        }
    }
    if (func_00287cd0() == 1) {
        func_00281d48();
        func_00281e20();
    }
    if (func_00288040()) func_00288018();
}
struct LE8 { s16 a; s16 b; s16 c; s16 x; };
struct LL8 { s16 n; s16 pad[3]; LE8 e[1]; };
extern LL8* D_0035f594;
extern s32 D_0035f3d4;
extern s32 D_0035f14c;
extern s32 D_0035f148;
extern s32 D_0035f210;
extern s32 D_0035f200;
extern s32 D_0035f214;
struct W436 { u8 pad[420]; u32 f420; u8 pad2[12]; void (*f436)(void); };
void* func_00276348(void);
u8* func_002766d0(void);
void func_00276690(s32);
void func_00288e88(s32);
void func_0028f4d8(s32, s32, s32);
void func_00276e78(void);
void func_0028d8c0_m7050(u8*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_00139620_m7050(void*) asm("func_00139620");
void func_0028dcc0_m7050(void*, void*) asm("func_0028dcc0");
void func_00288d80_m7050(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("func_00288d80");
W436* func_002891b8_m7050(s32, s32) asm("func_002891b8");
void func_002978f0(void);
void func_001395f8_m7050(void*) asm("func_001395f8");
s32 func_0023aa78(u8*);
void func_00138c68_m7050(u8*, s32, s32) asm("func_00138c68");
void func_00297478(void);
void func_0028af90(s32, s32);
void func_002891f0_m7050(s32, s32, s32, s32, s32) asm("func_002891f0");
void func_0028afd0(s32, s32);
void* func_0023f1b0(s32);
s32 func_0023c4b8(void*, s32);
s32 func_00236ca8(s32, s32);
s32 func_00276678(void);
void func_0028bae0(s32, s32, s32, s32, s32, s32, s32, u8*, s32);
void func_0028be78(s32, s32);
void func_0028af28(s32, s32);
void func_0028b218(s32, s32);
void func_0028b248(s32, s32);
void func_0028b1e8_m7050(s32, s32) asm("func_0028b1e8");
void func_00297b30(void);
void func_002978d0(void);
void func_00287cc0(s32);
void func_00297050(void)
{
    s16 c[2][4];
    s32 i;
    s32 j;
    s32 y;
    void* o = func_00276348();
    u8* w = func_002766d0();
    func_00276690(1);
    func_00288e88(D_0035f200);
    func_0028f4d8(0, -1, 0);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) c[i][j] = 2;
    }
    s32 m = D_0035f3d4 - 1;
    u8* w2 = w + 1224;
    y = 0;
    func_00276e78();
    func_0028d8c0_m7050(w, m, D_0035f14c, D_0035f148, D_0035f210, 96, -1, 0);
    func_00139620_m7050(w);
    func_0028dcc0_m7050(w, o);
    func_0028d8c0_m7050(w2, m, D_0035f14c, D_0035f148, D_0035f210, 100, -1, 0);
    func_00139620_m7050(w2);
    func_0028dcc0_m7050(w2, o);
    func_00288d80_m7050(D_0035f200, 0, D_0035f14c, D_0035f148, D_0035f210, -1, c[0], c[1]);
    func_00139620_m7050(func_002891b8_m7050(D_0035f200, 0));
    func_0028dcc0_m7050(func_002891b8_m7050(D_0035f200, 0), w);
    *(u32*)&func_002891b8_m7050(D_0035f200, 0)->f436 = (u32)func_002978f0;
    *(u32*)&func_002891b8_m7050(D_0035f200, 0)->f420 = 0x60000008;
    func_001395f8_m7050(func_002891b8_m7050(D_0035f200, 0));
    m = D_0035f3d4;
    s32 h = func_0023aa78(w + 24);
    for (i = 0; i < 10; i++) {
        u8* p = w + 0xa998 + i * 408;
        func_0028d8c0_m7050(p, m + 1, D_0035f14c, D_0035f148, D_0035f210, 2, -1, 0);
        func_0028dcc0_m7050(p, w);
        func_00138c68_m7050(p, 0, y);
        y += h;
    }
    func_00297478();
    s32 tot = 0;
    for (i = 0; i < D_0035f594->n - 1; i++) tot += D_0035f594->e[i].x;
    s32 sum = tot;
    s32 last = D_0035f594->e[D_0035f594->n - 1].x;
    tot = sum + 1;
    if (last > 10) { s32 ex = last - 10; tot += ex; }
    func_0028af90(D_0035f200, tot);
    func_002891f0_m7050(D_0035f200, 0, 0, -1, -1);
    func_0028afd0(D_0035f200, sum);
    s32 r1 = func_0023c4b8(func_0023f1b0(D_0035f210), D_0035f14c);
    s32 r2 = func_00236ca8(*(s32*)((u8*)func_0023f1b0(D_0035f210) + 40), D_0035f148);
    s32 last2 = D_0035f594->e[D_0035f594->n - 1].x;
    m = D_0035f3d4;
    s32 v = sum + 10;
    if (last2 >= 10) v = sum + last2;
    func_0028bae0(D_0035f214, m, r1, r2, func_00276678(), v, 10, w2, 0);
    func_0028be78(D_0035f214, sum);
    func_0028af28(D_0035f200, 16);
    func_0028b218(D_0035f200, 1);
    func_0028b248(D_0035f200, 10);
    func_0028b1e8_m7050(D_0035f200, 0);
    func_00297b30();
    func_002978d0();
    func_00287cc0(0);
}
}
