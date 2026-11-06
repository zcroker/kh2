#include "../common/types.h"

/* Built with -fmove-all-movables (_mam). */
extern "C" {
u8* func_00257770(void);
s32 func_00287bc0(void);
s32 func_002570a0(s32);
s32 func_00272b60(s32);
void func_00282240(s32, s32, s32);
void func_00282620(s32);
void func_00282cb8(s32, s32);
void func_00282d70(s32);
s32 func_00281f18(s32);
void func_00282940(s32, s32, s32);
void func_0028f4d8(s32, s32, s32);
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32);
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00139620(u8*);
void func_001395f8(u8*);
void func_0028dcc0(u8*, u8*);
s32 func_00257158(s32, s32, s32);
s32 func_00257140(s32);
void func_00288d80(s32, s32, s32, s32, s32, s32, u16*, u16*);
u8* func_002891b8(s32, s32);
s32 func_0023aa78(u8*);
void func_00288e08(s32, s32, s32, s32);
void func_00273078(void);
u8* func_0023f1b0(s32);
s32 func_0023c4b8(u8*, s32);
s32 func_00236ca8(s32, s32);
s32 func_002570f0(void);
void func_0028bae0(s32, s32, s32, s32, s32, s32, s32, u8*, s32);
void func_0028b218(s32, s32);
void func_0028b248(s32, s32);
void func_0028af90(s32, s32);
void func_00270648(void);
s32 func_00283ab8(s32);
s32 func_0028af88(s32);
void func_0028af18(s32, s32);
void func_00256cc0(s32, s32, s32);
void func_00287cc0(s32);
void func_002725d8(void);
extern u8 D_0035f128;
extern u16 D_00373a60[];
extern u16 D_01e21ec0[2][4];
extern s16 D_00373a30[][3];
extern s16 D_00373a50[];
extern u8* D_0035f12c;
extern s32 D_0035f014;
extern s32 D_0035f3d4;
extern s32 D_0035ef68;
extern s32 D_0035ef64;
extern s32 D_0035f03c;
extern s32 D_0035f01c;
extern s32 D_0035f04c;


/* Sets up the level menu: header objects, then up to 8 entries (436-byte
   objects at base+24740), then the list control. */
void func_002700f0(void) {
    s32 id, t, cnt, k, mode, id1, big;
    u8* m;
    s32 i, j, n, r;
    u8* a;
    u8* b;
    u8* o;
    u8* q;
    i = 0;
    m = func_00257770();
    D_0035f128 = 0;
    mode = func_00287bc0();
    k = func_002570a0(26);
    t = func_00272b60(k);
    for (; i < 2; i++) {
        for (j = 0; j < 4; j++) D_01e21ec0[i][j] = D_00373a60[t];
    }
    if (t == 0) {
        func_00282240(D_0035f014, 0, 10);
        func_00282620(D_0035f014);
        func_00282cb8(D_0035f014, -1);
        func_00282d70(D_0035f014);
        cnt = func_00281f18(D_0035f014);
        func_00282940(D_0035f014, 0, cnt++);
    } else if (t == 1) {
        cnt = 2;
    } else if (t == 2) {
        cnt = 2;
        if (func_002570a0(25)) cnt = 4;
    } else {
        cnt = 6;
        if (t != 3) cnt = 3;
    }
    func_0028f4d8(2, -1, 0);
    big = cnt < 9;
    a = m + 1632;
    b = m + 24304;
    n = 8;
    id = D_0035f3d4;
    func_0028d8c0(m, id, D_0035ef68, D_0035ef64, D_0035f03c, D_00373a30[t][0], D_00373a30[t][2], 0);
    id++;
    id1 = id + 1;
    func_0028d980(a, id, D_0035ef68, D_0035ef64, D_0035f03c, D_00373a50[t], -1, -1, 0);
    func_00139620(a);
    func_0028dcc0(a, m);
    if (big) n = cnt;
    r = func_00257140(func_00257158(*(s16*)(D_0035f12c + k * 8 + 8), 1, t == 1));
    func_0028d980(b, id1, D_0035ef68, D_0035ef64, D_0035f03c, r, -1, -1, 0);
    *(u8**)(b + 408) = m + k * 32 + 0xae10;
    func_0028dcc0(b, a);
    func_00139620(b);
    func_001395f8(b);
    r = func_00257140(0);
    for (i = 0; i < n; i++) {
        q = m + 24740 + i * 436;
        func_00288d80(D_0035f01c, i, D_0035ef68, D_0035ef64, D_0035f03c, -1, D_01e21ec0[0], D_01e21ec0[1]);
        o = func_002891b8(D_0035f01c, i);
        func_00288e08(D_0035f01c, i, 0, func_0023aa78(o + 24));
        func_00139620(o);
        if (mode == 31 && func_002570a0(25)) {
            *(void (**)(void))(func_002891b8(D_0035f01c, i) + 436) = func_00273078;
        }
        func_0028dcc0(o, m);
        func_0028d980(q, id1, D_0035ef68, D_0035ef64, D_0035f03c, r, -1, -1, 0);
        func_0028dcc0(q, o);
        func_00139620(q);
        func_001395f8(q);
    }
    big = cnt < 9;
    n = 8; if (big) n = cnt;
    func_0028bae0(D_0035f04c, id, func_0023c4b8(func_0023f1b0(D_0035f03c), D_0035ef68),
                  func_00236ca8(*(s32*)(func_0023f1b0(D_0035f03c) + 40), D_0035ef64),
                  func_002570f0(), cnt, n, m, 0);
    func_0028b218(D_0035f01c, 1);
    func_0028b248(D_0035f01c, n);
    if (!big) func_0028af90(D_0035f01c, cnt);
    func_00270648();
    if ((t == 2 && func_00283ab8(0)) || (t == 1 && func_00283ab8(1))) {
        func_0028af18(D_0035f01c, func_0028af88(D_0035f01c) | 0x400);
        func_00256cc0(0xcbdd, -1, -1);
    }
    func_00287cc0(0);
    func_002725d8();
}
}
