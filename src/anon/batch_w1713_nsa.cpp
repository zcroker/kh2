#include "../common/types.h"
/* 00277d20: builds the save/load slot menu (rows of labels, frames and icons). */
/* Needs -fno-strict-aliasing (built from a *_nsa.cpp file). */
extern "C" {

struct W1713Sub { u8 pad[1]; };
struct W1713Item {
    u8 pad0[0x18];
    W1713Sub sub;              /* 0x18 */
    u8 pad19[0x1b0 - 0x19];
    s32 mode;                  /* 0x1b0 */
};
struct W1713Item2 { u8 pad[0x198]; };
struct W1713Obj {
    u8 pad0[0x18];
    W1713Sub sub;              /* 0x18 */
    u8 pad19[0x1b4 - 0x19];
    void* callback;            /* 0x1b4 */
};
struct W1713Menu {
    u8 pad0[0xd30];
    W1713Item tabs[24];        /* 0x0d30 */
    W1713Item frames[24];      /* 0x3610 */
    W1713Item labels[24];      /* 0x5ef0 */
    W1713Item2 icons[24];      /* 0x87d0 */
};
struct W1713Slot { s8 a; s8 flag; u8 pad[6]; };
struct W1713Save {
    u8 pad0[7];
    s8 count;                  /* 0x07 */
    u8 pad8[8];
    W1713Slot slots[1];        /* 0x10 */
};
struct W1713Tex { u8 pad[0x28]; s32 id; };

extern s32 D_0035ef64;
extern s32 D_0035ef68;
extern s32 D_0035ef6c;
extern s32 D_0035f01c;
extern s32 D_0035f03c;
extern s32 D_0035f04c;
extern W1713Save* D_0035f230;
extern s32 D_0035f3d4;
extern s16 D_01e21ee0[2][4];

W1713Menu* func_00257770(void);
s32 func_0028f930(s32);
void func_0028f4d8(s32, s32, s32);
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32);
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_002570a0(s32);
void func_0027aed8(s32, s32*, s32*);
void func_00288d80(s32, s32, s32, s32, s32, s32, s16*, s16*);
W1713Obj* func_002891b8(s32, s32);
void func_00138c10(void*, s32);
void func_00138c68(void*, s32, s32);
s32 func_0023aa78(void*);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
void func_0028dcc0(void*, void*);
void func_00139620(void*);
void func_001395f8(void*);
s32 func_00257140(s32);
void func_0027b960(void);
W1713Tex* func_0023f1b0(s32);
s32 func_0023c4b8(W1713Tex*, s32);
s32 func_00236ca8(s32, s32);
void func_00257708(s32);
s32 func_002570f0(void);
void func_0028bae0(s32, s32, s32, s32, s32, s32, s32, W1713Menu*, s32);
void func_0028af90(s32, s32);
void func_0027c2f8(void);
void func_0028b218(s32, s32);
void func_0028b248(s32, s32);
void func_00257050(s32, s32, s32);
s32 func_0028af88(s32);
s32 func_00258068(s32);
s32 func_0028b040(s32);
void func_0028af18(s32, s32);
void func_0028af28(s32, s32);
s32 func_00283ab8(s32);
void func_00256cc0(s32, s32, s32);
void func_0027b0f8(void);
void func_0027a6d8(void);
void func_0027a208(void);
void func_00287cc0(s32);

/* The original passes the colour before the shared screen globals. */
static inline __attribute__((always_inline)) void W1713InitIcon(void* p, s32 id, s32 color, s32 w, s32 h, s32 tex) {
    func_0028d8c0(p, id, w, h, tex, color, -1, 0);
}

void func_00277d20(void) {
    W1713Menu* menu = func_00257770();
    s32 i;
    s32 j;
    s32 n;
    s32 base;
    s32 noSave;
    s32 hasData;
    s32 w;
    s32 x;
    s32 y;
    s32 a;
    s32 b;
    s32 cur;
    s32 slot;
    s32 val;      /* selected count, then menu flags, then the second sound id */

    if (func_0028f930(0) == 0) {
        func_0028f4d8(0, -1, 0);
    }
    if (func_0028f930(1) == 0) {
        func_0028f4d8(1, -1, 0);
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            D_01e21ee0[i][j] = D_0035ef6c;
        }
    }
    base = D_0035f3d4;
    func_0028d8c0(menu, base, D_0035ef68, D_0035ef64, D_0035f03c, 230, 231, 0);
    n = D_0035f230->count < 10 ? D_0035f230->count : 9;
    if (n == 0) n = 1;
    func_0027aed8(func_002570a0(15), &noSave, &hasData);
    base = D_0035f3d4;
    for (i = 0; i < n; i++) {
        W1713Obj* obj;
        W1713Item* p;
        W1713Item* q;
        W1713Item2* ic;
        func_00288d80(D_0035f01c, i, D_0035ef68, D_0035ef64, D_0035f03c, -1, D_01e21ee0[0], D_01e21ee0[1]);
        obj = func_002891b8(D_0035f01c, i);
        func_00138c10(obj, 0xf8);
        w = func_0023aa78(&obj->sub);
        x = func_0023aa18(&obj->sub);
        y = func_0023aa38(&obj->sub);
        func_00138c10(obj, D_0035ef6c);
        func_00138c68(obj, 0, i * w);
        func_0028dcc0(obj, menu);
        func_00139620(obj);
        if (noSave == 0 && hasData != 0) {
            obj->callback = (void*)func_0027b960;
        }
        p = &menu->labels[i];
        func_0028d980(p, base, D_0035ef68, D_0035ef64, D_0035f03c, func_00257140(0), -1, -1, 0);
        func_0028dcc0(p, obj);
        func_00139620(p);
        func_001395f8(p);
        q = &menu->frames[i];
        func_0028d980(q, base, D_0035ef68, D_0035ef64, D_0035f03c, 251, -1, -1, 0);
        func_0028dcc0(q, obj);
        func_00138c10(q, D_0035ef6c);
        func_00139620(q);
        q->mode = 1;
        ic = &menu->icons[i];
        W1713InitIcon(ic, base + 2, D_0035ef6c, D_0035ef68, D_0035ef64, D_0035f03c);
        func_0028dcc0(ic, obj);
        func_00138c68(ic, x, y);
    }
    for (i = 0; i < n; i++) {
        W1713Item* p = &menu->tabs[i];
        func_0028d980(p, base, D_0035ef68, D_0035ef64, D_0035f03c, 276, -1, -1, 0);
        w = func_0023aa78(&p->sub);
        func_00138c68(p, 0, w * i);
        func_00138c10(p, D_0035ef6c);
        func_001395f8(p);
        func_0028dcc0(p, menu);
        p->mode = 2;
    }
    a = func_0023c4b8(func_0023f1b0(D_0035f03c), D_0035ef68);
    b = func_00236ca8(func_0023f1b0(D_0035f03c)->id, D_0035ef64);
    val = D_0035f230->count;
    if (val == 0) {
        func_00257708(1);
        val = n;
    }
    func_0028bae0(D_0035f04c, base, a, b, func_002570f0(), val, n, menu, 0);
    n = D_0035f230->count;
    if (n == 0) n = 1;
    func_0028af90(D_0035f01c, n);
    func_0027c2f8();
    func_0028b218(D_0035f01c, 1);
    func_0028b248(D_0035f01c, 9);
    func_00257050(16, 0, 0);
    cur = func_0028af88(D_0035f01c);
    val = 0xc000;
    if (func_00258068(0) != 0) val = 0xc100;
    slot = func_0028b040(D_0035f01c);
    if (noSave == 0 && D_0035f230->count != 0) {
        if (D_0035f230->slots[slot].flag != 0) val |= 0x200;
    }
    func_0028af18(D_0035f01c, cur | val);
    if (D_0035f230->count == 0) {
        func_0028af28(D_0035f01c, 16);
    }
    val = -1;
    if (func_00283ab8(2) != 0) {
        val = 0xcbdd;
        cur = func_0028af88(D_0035f01c) | 0x400;
        func_0028af18(D_0035f01c, cur);
    }
    if (func_00258068(0) != 0) {
        func_00256cc0(0xb373, 0xb61a, val);
    } else {
        func_00256cc0(0xb61a, val, -1);
    }
    if (noSave == 0) {
        func_0027b0f8();
    }
    func_0027a6d8();
    func_0027a208();
    func_00287cc0(0);
}

}
