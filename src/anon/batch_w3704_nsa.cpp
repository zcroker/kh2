#include "../common/types.h"

// u8 member: these u16 accesses may alias any store (the original was built without strict aliasing)
union W1650H { u16 v; u8 c; };
// 0x1b4-byte layout sprite (init by func_0028d980)
struct W1650Spr { u8 pad0[0x18]; u8 sub[0x180]; s32 x198; u8 pad19c[8]; u32 x1a4; s32 x1a8; s32 x1ac; s32 x1b0; };
// 0x198-byte layout element (init by func_0028d8c0)
struct W1650Lay { u8 pad0[0x198]; };
struct W1650Panel {
    W1650Spr a[4];      // 0x0000
    W1650Spr item[5];   // 0x06d0
    W1650Spr cnt[5];  // 0x0f54
    W1650Lay d[2];      // 0x17d8
    W1650H x1b08;
    char num[8];        // 0x1b0a
    char nums[5][8];    // 0x1b12
    s8 x1b3a;
    s8 x1b3b;
};
struct W1650Work { u8 pad0[0x18]; u8 sub[0x318]; W1650Lay x330; u8 pad4c8[0x110a0 - 0x4c8]; char names[10][64]; };
struct W1650List { u8 pad0[4]; s8 x4; s8 count; u8 pad6[2]; s16 ids[0x80]; char name[64]; };
struct W1650Ent { u8 pad0[2]; s8 x2; u8 pad3[3]; u16 x6; u16 x8; W1650H xa; u16 xc; u8 pade[2]; W1650H flags; };
struct W1650Item { u8 pad0[8]; s32 x8; };
struct W1650Tbl { u16 x0; u16 ids[5]; };
struct W1650Def { u8 pad0[0x4c]; u16 x4c; };

extern "C" {
void* func_002766d0(void);
s32 func_00276638(s32);
W1650Ent* func_0029da68(s32);
void* func_00276348(void);
s32 func_00287bc0(void);
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32);
void func_00139620(void*);
void func_001395f8(void*);
void func_0028dcc0(void*, void*);
s32 func_00192048(s32);
s32 func_00295430(s32, s32);
void func_00192e50(s32, char*, s32, s32);
void func_002595e8(char*, s32);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
s32 func_0023aa58(void*);
s32 func_0023aa78(void*);
s32 func_00276c38(s32);
s32 func_00192cc0(char*, char*, s32);
s32 func_00294368(W1650Ent*);
void func_00138c68(void*, s32, s32);
s32 func_00192b80(s32);
void func_0028af90(void*, s32);
void func_002891f0(void*, s32, s32, s32, s32);
void func_0028afd0(void*, s32);
void func_0028b218(void*, s32);
void func_0028b248(void*, s32);
void func_002fde18(void*, s32, s32);
W1650Def* func_0016e920(s32);
W1650Tbl* func_001d23e0(s32);
W1650Item* func_001b8e88(s32);
s32 func_001b90a8(W1650Item*);
s32 func_00276c18(void);
s32 func_0028de08(s32, char*, s32);
extern W1650List* D_0035f5ac;
union W1650PanelPtr { W1650Panel* p; u8 c; };
extern W1650PanelPtr D_0035f5b0;
extern s32 D_0035f3d4;
extern s32 D_0035f14c;
extern s32 D_0035f148;
extern s32 D_0035f210;
extern void* D_0035f200;
extern s16 D_00374ae0[];
extern char D_003749e8[];

void func_0029d318(void)
{
    s32 a;
    s32 b;
    s32 d;
    s32 mode;
    void* o;
    W1650Work* w;
    W1650Ent* e;
    s32 base;
    W1650Spr* s;
    s32 v;
    s32 k;

    w = (W1650Work*)func_002766d0();
    {
        s32 idx = func_00276638(15);
        e = func_0029da68(D_0035f5ac->ids[idx]);
    }
    base = D_0035f3d4;
    o = func_00276348();
    mode = func_00287bc0();
    s = &D_0035f5b0.p->a[0];
    v = e->x6;

    func_0028d980(s, base, D_0035f14c, D_0035f148, D_0035f210, 76, -1, -1, 0);
    func_00139620(s);
    func_0028dcc0(s, o);
    s->x1ac = 3;
    s->x1a4 = 0x60000008;
    if (e->flags.v & 0x400) {
        s32 t = func_00192048(v);
        func_00192e50(t, D_0035f5ac->name, 64, func_00192048(func_00295430(D_0035f5ac->x4, 1)));
    } else {
        func_002595e8(D_0035f5ac->name, func_00192048(v));
    }
    s->x198 = (s32)D_0035f5ac->name;

    k = e->xa.v;
    if (k != 0) {
        s = &D_0035f5b0.p->a[1];
        func_0028d980(s, base, D_0035f14c, D_0035f148, D_0035f210, 77, -1, k, 0);
        func_00139620(s);
        func_0028dcc0(s, o);
        s->x1ac = 3;
        s->x1a4 = 0x60000008;
    }

    if (e->flags.v & 0x800) {
        s = &D_0035f5b0.p->a[2];
        void* sub = s->sub;
        func_0028d980(s, base, D_0035f14c, D_0035f148, D_0035f210, 78, -1, -1, 0);
        s->x198 = func_00192048(0x489b);
        a = func_0023aa18(sub);
        b = func_0023aa38(sub);
        d = func_0023aa58(sub);
        func_0028dcc0(s, o);
        func_00139620(s);
        func_001395f8(s);
        s = &D_0035f5b0.p->a[3];
        func_0028d980(s, base + 1, D_0035f14c, D_0035f148, D_0035f210, func_00276c38(2), -1, -1, 0);
        s->x198 = func_00192cc0(D_0035f5b0.p->num, D_003749e8, func_00294368(e));
        func_00139620(s);
        func_0028dcc0(s, &D_0035f5b0.p->a[2]);
        func_001395f8(s);
        func_00138c68(s, a, b);
        s->x1b0 = 1;
        s->x1a8 = d;
    }

    {
        W1650Lay* l = &D_0035f5b0.p->d[0];
        func_0028d8c0(l, base, D_0035f14c, D_0035f148, D_0035f210, 81, -1, 0);
        func_0028dcc0(l, o);
        l = &D_0035f5b0.p->d[1];
        func_0028d8c0(l, base, D_0035f14c, D_0035f148, D_0035f210, 82, -1, 0);
        func_0028dcc0(l, o);
        void* sub = w->sub;
        l = &w->x330;
        v = D_00374ae0[e->x2];
        func_0028d8c0(l, base, D_0035f14c, D_0035f148, D_0035f210, v, -1, 0);
        func_0028dcc0(l, w);
        a = func_0023aa18(sub);
        b = func_0023aa38(sub);
        func_00138c68(l, a, b);
        D_0035f5b0.p->x1b3b = func_0023aa78(sub);
    }
    D_0035f5b0.p->x1b08.v = e->x8;
    D_0035f5b0.p->x1b3a = func_00192b80(func_00192048(e->x8));
    {
        s32 lv = D_0035f5b0.p->x1b3a;
        s32 n = (lv < 8) ? 1 : lv - 6;
        func_0028af90(D_0035f200, n);
        func_002891f0(D_0035f200, 0, 0, -1, -1);
        func_0028afd0(D_0035f200, 0);
        if (n >= 2) {
            func_0028b218(D_0035f200, 1);
            func_0028b248(D_0035f200, 7);
        }
    }
    func_002fde18(w->names, 0, sizeof(w->names));

    if (mode == 19 || mode == 22) {
        W1650Tbl* t = func_001d23e0(func_0016e920(e->xc)->x4c);
        if (t != 0) {
            s32 n = 0;
            s32 i;
            for (i = 0; i < 5; i++) {
                u16 id = t->ids[i];
                W1650Item* it;
                if (id == 0) continue;
                it = func_001b8e88(id);
                if (func_001b90a8(it) == 0 && func_00276c18() == 0) continue;
                v = 0;
                if (it != 0) {
                    v = func_001b90a8(it);
                    if (v >= 1000) { v = 999; asm(""); }
                }
                s = &D_0035f5b0.p->item[n];
                func_0028d980(s, 30052, D_0035f14c, D_0035f148, D_0035f210, 79, -1, -1, 0);
                {
                    k = it->x8;
                    if (v != 0) k = func_00192048(k);
                    else k = func_0028de08(k, w->names[n], 64);
                    s->x198 = k;
                }
                void* sub = s->sub;
                a = func_0023aa18(sub);
                b = func_0023aa38(sub);
                s32 c = func_0023aa78(sub);
                d = func_0023aa58(sub);
                func_00138c68(s, 0, c * n);
                func_0028dcc0(s, o);
                func_00139620(s);
                func_001395f8(s);
                s = &D_0035f5b0.p->cnt[n];
                func_0028d980(s, 30053, D_0035f14c, D_0035f148, D_0035f210, func_00276c38(2), -1, -1, 0);
                s->x198 = func_00192cc0(D_0035f5b0.p->nums[n], D_003749e8, v);
                func_00139620(s);
                func_0028dcc0(s, &D_0035f5b0.p->item[n]);
                func_001395f8(s);
                func_00138c68(s, a, b);
                { register s32 one asm("$13") = 1; s->x1b0 = one; }
                s->x1a8 = d;
                n++;
            }
        }
    }
}
}
