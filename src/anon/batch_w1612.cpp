#include "../common/types.h"
namespace n002450c8 {
struct El {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~El();
    u8 pad[404];
};
struct Ek {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~Ek();
    u8 pad[432];
};
struct AV { void* a; void (*free)(void*, void*); };
struct AO { AV* vt; };
struct AH { u8 pad[20]; AO* a; };
extern "C" AH* D_00347f80;
struct El2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~El2();
    u8 pad[404];
    static void operator delete[](void* p) { D_00347f80->a->vt->free(D_00347f80->a, p); }
};
struct DV { void* a[4]; void (*del)(void*); };
struct DO { DV* vt; };
extern "C" void func_0031acc0(void*);
extern "C" void func_00239870(void*);
extern "C" void func_00106420(void*);
extern "C" void func_0031a840(void*);
struct B0 { ~B0() { func_0031a840(this); } };
extern "C" u8 D_00347e60[];
struct M24 { ~M24() { func_00239870(this); } };
struct B : B0 { u8 pad[24]; M24 m; u8 pad2[411]; ~B() { *(u8**)this = D_00347e60; } };
struct M436 { u8 pad[436]; ~M436() { func_0031acc0(this); } };
struct Big {
    B b; M436 m; Ek a[4]; Ek b2[4]; Ek c[4]; Ek d[4]; El e[4]; El f[4]; El g[4]; El h[4];
    static void operator delete(void* p) { func_00106420(p); }
};
extern "C" {
extern void* D_0035ed20;
extern void* D_0035ed24;
extern DO* D_0035ed28;
extern DO* D_0035ed2c;
extern DO* D_0035ed30;
extern El2* D_0035ed34;
extern void* D_0035ed38;
extern Big* D_0035ed40;
extern AO* D_0032ba14;
void func_00288b00(void*);
void func_00288c20(void*);
void func_002b3fb0(void*);
// Frees the module's globals; the big object's destructor and the array delete are inlined.
void func_002450c8(void) {
    void* p;
    if ((p = D_0035ed20) != 0) { func_00288b00(p); func_00288c20(p); D_0035ed20 = 0; }
    if ((p = D_0035ed24) != 0) { func_00288b00(p); func_00288c20(p); D_0035ed24 = 0; }
    if (D_0035ed28) { D_0035ed28->vt->del(D_0035ed28); D_0035ed28 = 0; }
    if (D_0035ed2c) { D_0035ed2c->vt->del(D_0035ed2c); D_0035ed2c = 0; }
    if (D_0035ed30) { D_0035ed30->vt->del(D_0035ed30); D_0035ed30 = 0; }
    if ((p = D_0035ed38) != 0) { func_002b3fb0(p); D_0032ba14->vt->free(D_0032ba14, p); D_0035ed38 = 0; }
    if (D_0035ed40) {
        delete D_0035ed40;
        D_0035ed40 = 0;
    }
    if (D_0035ed34) {
        delete[] D_0035ed34;
        D_0035ed34 = 0;
    }
}
}
}
namespace n0027f4a8 {
struct Sub { u8 pad[184]; u32 flags; void set8() { flags |= 8; } };
struct Win { u8 pad[24]; Sub sub; };
struct E { u8 pad[408]; s32 f408; u8 pad2[20]; s32 f432; };
extern "C" {
extern s32 D_0035f250;
extern void* D_0035f254;
extern Win* D_0035f258;
union UE { E* p; s32 i; };
extern UE D_0035f25c;
extern s32 D_0035f3d4;
extern u16 D_003740f8[2][9];
extern u16 D_00374130[];
extern u16 D_00374158[][2];
extern s8 D_00374168[];
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32);
void func_00288d80(void*, s32, s32, s32, s32, s32, u16*, u16*);
E* func_002891b8(void*, s32);
void func_00139620(void*);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
s32 func_0023aa98(void*);
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0028dcc0(void*, void*);
void func_00138c68(void*, s32, s32);
void func_001395f8(void*);
s32 func_00192048(u16);
void func_0028af28(void*, s32);
s32 func_001041c0(void);
void func_0028b1b0(void*, s32);
void func_0027fd38(void);
void func_002891f0(void*, s32, s32, s32, s32);
void func_00287bd0(s32, s32);

// Builds the menu window and its 9 rows, then the per-row sub-items.
void func_0027f4a8(void) {
    u16 a[2][4];
    s32 i, j;
    func_0028d8c0(D_0035f258, 30003, 1, 0, D_0035f250, 1, -1, 0);
    D_0035f258->sub.set8();
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 2; j++) {
            for (s32 m = 0; m < 4; m++) a[j][m] = D_003740f8[j][i];
        }
        func_00288d80(D_0035f254, i, 1, 0, D_0035f250, D_00374130[i], a[0], a[1]);
        func_00139620(func_002891b8(D_0035f254, i));
        func_002891b8(D_0035f254, i)->f432 = 2;
    }
    s32 n = D_0035f3d4 + 1;
    s32 c = 0;
    for (i = 0; i < 9; i++) {
        if (D_00374168[i] >= 0) continue;
        if (i == 2) continue;
        s32 x = func_0023aa18((u8*)func_002891b8(D_0035f254, i) + 24);
        s32 y = func_0023aa38((u8*)func_002891b8(D_0035f254, i) + 24);
        s32 h = func_0023aa98((u8*)func_002891b8(D_0035f254, i) + 24);
        s32 off = c * 436;
        for (j = 0; j < 2; j++) {
            E* e;
            func_0028d980((E*)((u8*)D_0035f25c.p + off), n, 1, 0, D_0035f250, 27, -1, -1, 0);
            func_0028dcc0((E*)((u8*)D_0035f25c.p + off), func_002891b8(D_0035f254, i));
            func_00139620((E*)((u8*)D_0035f25c.p + off));
            func_00138c68((E*)((u8*)D_0035f25c.p + off), x, y);
            x += h;
            func_001395f8((E*)((u8*)D_0035f25c.p + off));
            e = (E*)((u8*)D_0035f25c.p + off);
            e->f408 = func_00192048(D_00374158[c / 2][j]);
            ((E*)((u8*)D_0035f25c.p + off))->f432 = 2;
            c++;
            off += 436;
        }
    }
    func_0028af28(D_0035f254, 32);
    if (func_001041c0() != 3) func_0028b1b0(D_0035f254, 64);
    func_0027fd38();
    func_002891f0(D_0035f254, 0, 1, 0, -1);
    func_00287bd0(0, 0);
}
}
}
namespace n0025f7f0 {
struct E { u8 pad[408]; s32 f408; };
struct F { u8 pad[408]; };
struct Base { u8 pad[0x87d0]; F e[8]; };
extern "C" {
extern s32 D_0035f3d4;
extern void* D_0035f010;
extern void* D_0035f01c;
extern s32 D_0035ef68;
extern s32 D_0035ef64;
extern s32 D_0035f03c;
extern s32 D_0037327c;
extern s32 D_00373278;
Base* func_00257770(void);
void func_0028f4d8(s32, s32, s32);
s32 func_00281180(void*, s32);
s32 func_00281140(void*, s32);
s32 func_00257100(s32);
void func_00288d80(void*, s32, s32, s32, s32, s32, s32, s32);
void func_00288e08(void*, s32, s32, s32);
E* func_002891b8(void*, s32);
void func_00139620(void*);
void func_001395f8(void*);
s32 func_00192048(s32);
s32 func_00285d58(s32);
s32 func_00285e30(s32);
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32);
void func_0028dcc0(void*, void*);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
void func_00138c68(void*, s32, s32);
s32 func_00257070(s32);
void func_00257050(s32, s32, s32);
void func_002891f0(void*, s32, s32, s32, s32);
u32 func_0028af88(void*);
s32 func_00258068(s32);
void func_0028af18(void*, u32);
void func_0025f7d8(void);
void func_00261b30(void);
void func_00261d48(void);
void func_00262af8(void);
void func_00256cc0(s32, s32, s32);
void func_00287cc0(s32);

void func_0025f7f0(s32 sel) {
    s32 i, k;
    E* p;
    s32 save;
    Base* b = func_00257770();
    func_0028f4d8(0, -1, 0);
    save = D_0035f3d4;
    D_0035f3d4 = 30017;
    k = 0;
    for (i = 0; i < 4; i++) {
        if (func_00281180(D_0035f010, i)) {
            s32 x = func_00257100(0);
            func_00288d80(D_0035f01c, k, D_0035ef68, D_0035ef64, D_0035f03c, -1, x, func_00257100(1));
            func_00288e08(D_0035f01c, k, 0, -1);
            p = func_002891b8(D_0035f01c, k++);
            func_00139620(p);
            p->f408 = func_00281140(D_0035f010, i);
            func_001395f8(p);
        }
    }
    s32 x = func_00257100(0);
    func_00288d80(D_0035f01c, k, D_0035ef68, D_0035ef64, D_0035f03c, -1, x, func_00257100(1));
    func_00288e08(D_0035f01c, k, 0, -1);
    p = func_002891b8(D_0035f01c, k);
    func_00139620(p);
    p->f408 = func_00192048(0x8455);
    func_001395f8(p);
    i = D_0035f3d4 + 1;
    if (func_00285d58(-1)) {
        s32 t = func_00285e30(-1) ? D_0037327c : D_00373278;
        F* e = &b->e[k];
        func_0028d8c0(e, i, D_0035ef68, D_0035ef64, D_0035f03c, t, -1, 0);
        func_0028dcc0(e, p);
        s32 y = func_0023aa18((u8*)p + 24);
        func_00138c68(e, y, func_0023aa38((u8*)p + 24));
    }
    D_0035f3d4 = save;
    s32 v = func_00257070(1);
    if (sel >= 0 && sel != v) {
        func_00257050(2, 0, 0);
        func_00257050(1, sel, 0);
        v = sel;
    }
    func_002891f0(D_0035f01c, v, 1, 0, 2);
    u32 f = func_0028af88(D_0035f01c);
    if (func_00258068(1)) f |= 0x100;
    func_0028af18(D_0035f01c, f);
    func_0025f7d8();
    func_00261b30();
    func_00261d48();
    func_00262af8();
    if (func_00258068(1)) func_00256cc0(0xb619, -1, -1);
    func_00287cc0(0);
}
}
}
