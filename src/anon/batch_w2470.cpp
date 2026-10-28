#include "../common/types.h"
extern "C" {
u8* func_00257770(void);
void func_0028d068(s32, s32);
s32 func_0028f930(s32);
void func_0028f4d8(s32, s32, s32);
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32);
void func_00288d80(s32, s32, s32, s32, s32, s32, u16*, u16*);
u8* func_002891b8(s32, s32);
void func_00138c10(u8*, s32);
s32 func_0023aa78(u8*);
void func_00288e08(s32, s32, s32, s32);
void func_00139620(u8*);
void func_001395f8(u8*);
void func_0028dcc0(u8*, u8*);
s32 func_00257140(s32);
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00138c68(u8*, s32, s32);
u8* func_0023f1b0(s32);
s32 func_0023c4b8(u8*, s32);
s32 func_00236ca8(s32, s32);
s32 func_00257130(void);
s32 func_00281f18(s32);
s32 func_002570f0(void);
void func_0028bae0(s32, s32, s32, s32, s32, s32, s32, u8*, s32);
void func_002817d8(s32, s32, s32, s32, s32, s32, s32);
void func_00281e70(u8*);
void func_002677d8(void);
s32 func_00257070(s32);
s32 func_00281198(s32, s32);
void func_00282240(s32, s32, s32);
void func_002827f0(s32, s32, s32);
void func_0028af90(s32, s32);
void func_002891f0(s32, s32, s32, s32, s32);
s32 func_00257088(s32);
void func_0028afd0(s32, s32);
s32 func_0028b040(s32);
s32 func_00269508(s32);
s32 func_0028af88(s32);
s32 func_00258068(s32);
void func_0028af18(s32, s32);
void func_0028b218(s32, s32);
void func_0028b248(s32, s32);
void func_00269658(void);
s32 func_00283ab8(s32);
void func_00256cc0(s32, s32, s32);
void func_00287cc0(s32);
extern s32 D_0035ef6c;
extern s32 D_0035ef68;
extern s32 D_0035ef64;
extern s32 D_0035f03c;
extern s32 D_0035f01c;
extern s32 D_0035f04c;
extern s32 D_0035f3d4;
extern s32 D_0035f010;

/* 436-byte menu object (fields at +24, +392, +432). */
struct Obj { u8 b[436]; };
#define OBJ(base, i) ((u8*)&((Obj*)(base))[i])
/* Menu screen setup: base object, 9 items with their cursors, 9 icons, footer. */
void func_002678a8(void) {
    u16 buf[4];
    s32 lay;
    s32 i;
    u8* m;
    s32 id, v, img, t, fl;
    u8* w;
    s32 sz;
    m = func_00257770();
    i = 0;
    func_0028d068(30021, 0);
    for (; i < 4; i++) buf[i] = D_0035ef6c;
    if (!func_0028f930(0)) func_0028f4d8(0, -1, 0);
    if (!func_0028f930(1)) func_0028f4d8(1, -1, 0);
    id = D_0035f3d4;
    func_0028d8c0(m, id, D_0035ef68, D_0035ef64, D_0035f03c, 227, 228, 0);
    id++;
    i = 0;
    v = id + 1;
    sz = 436;
    for (; i < 9; i++) {
        u8* q = m + 24304 + i * sz;
        func_00288d80(D_0035f01c, i, D_0035ef68, D_0035ef64, D_0035f03c, -1, buf, buf);
        func_00138c10(func_002891b8(D_0035f01c, i), 265);
        func_00288e08(D_0035f01c, i, 0, func_0023aa78(func_002891b8(D_0035f01c, i) + 24));
        func_00139620(func_002891b8(D_0035f01c, i));
        func_00138c10(func_002891b8(D_0035f01c, i), D_0035ef6c);
        *(s32*)(func_002891b8(D_0035f01c, i) + 392) = -1;
        func_0028dcc0(func_002891b8(D_0035f01c, i), m);
        func_0028d980(q, v, D_0035ef68, D_0035ef64, D_0035f03c, func_00257140(0), -1, -1, 0);
        func_0028dcc0(q, func_002891b8(D_0035f01c, i));
        func_00139620(q);
        func_001395f8(q);
    }
    i = 0;
    for (; i < 9; i++) {
        func_0028d980(OBJ(m + 3376, i), id, D_0035ef68, D_0035ef64, D_0035f03c, 283, -1, -1, 0);
        func_00138c68(OBJ(m + 3376, i), 0, func_0023aa78(OBJ(m + 3376, i) + 24) * i);
        func_00138c10(OBJ(m + 3376, i), D_0035ef6c);
        func_001395f8(OBJ(m + 3376, i));
        func_0028dcc0(OBJ(m + 3376, i), m);
        *(s32*)(OBJ(m + 3376, i) + 432) = 2;
    }
    lay = func_0023c4b8(func_0023f1b0(D_0035f03c), D_0035ef68);
    img = func_00236ca8(*(s32*)(func_0023f1b0(D_0035f03c) + 40), D_0035ef64);
    v = func_00281f18(func_00257130());
    i = 9;
    if (v < 10) i = v;
    func_0028bae0(D_0035f04c, id, lay, img, func_002570f0(), v, i, m, 0);
    w = m + 0xb350;
    id = D_0035f3d4;
    func_0028d980(w, id, D_0035ef68, D_0035ef64, D_0035f03c, 287, 288, -1, 0);
    func_002817d8(30015, D_0035ef68, D_0035ef64, D_0035f03c, 0, 0, 0);
    func_00281e70(w);
    func_002677d8();
    v = func_00281198(D_0035f010, func_00257070(1)) + 5;
    func_00282240(func_00257130(), v, 0);
    v = 0xc000;
    func_002827f0(func_00257130(), 0, 0);
    func_0028af90(D_0035f01c, func_00281f18(func_00257130()));
    func_002891f0(D_0035f01c, func_00257070(2), 0, -1, -1);
    func_0028afd0(D_0035f01c, func_00257088(2));
    t = func_00269508(func_0028b040(D_0035f01c));
    fl = func_0028af88(D_0035f01c);
    if (func_00258068(1)) v = 0xc100;
    if (t == 4) v |= 0x200;
    func_0028af18(D_0035f01c, fl | v);
    v = -1;
    func_0028b218(D_0035f01c, 1);
    func_0028b248(D_0035f01c, 9);
    func_00269658();
    if ((t == 4 && func_00283ab8(0)) || (t == 1 && func_00283ab8(3))) {
        v = 0xcbdd;
        fl = func_0028af88(D_0035f01c) | 0x400;
        func_0028af18(D_0035f01c, fl);
    }
    if (func_00258068(1)) func_00256cc0(0xb619, 0xb61a, v);
    func_00287cc0(0);
}
}
