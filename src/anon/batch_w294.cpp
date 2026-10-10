#include "../common/types.h"
namespace n0023c728 {
struct Ent { union { u16 f0; u8 fx; }; u16 f2; u8 pad[16]; };
struct Seg { s32 f0; s32 f4; s32 f8; s32 pad[3]; };
// Item's constructor is func_00239700; the mangled name is equated to it below.
struct Item {
    Item();
    virtual ~Item();
    u8 pad[64];
    f32 f68;
    u8 pad2[272];
    static void* operator new[](unsigned int n, void* h) asm("_Znaj");
    static void operator delete[](void* p) asm("_ZdaPv");
};
asm(".equ _ZN9n0023c7284ItemC1Ev, func_00239700");
struct Obj {
    u32 f0; void* f4; u8* f8; u8 pad0[4]; Seg* f16; Ent* f20; s32* f24; u8 pad1[12];
    void* f40; u8 pad2[4]; Item* f48; union { s32 f52; u8 c52; }; u8 pad3[8]; f32 f64; f32 f68; f32 f72; s32 f76; u8 f80;
};
extern "C" {
u8* GetImage294(void*, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void wtarget294_00239bf8(void*, s32) asm("_Z16wtarget_00239bf8jjjj");
s32 func_0023c5a0(Obj*, s32);
void func_00239988(Item*, u8*, u8*);
u8 func_0023c978(Obj*);
void func_0023c728(Obj* o, s32 idx) {
    o->f76 = idx;
    Ent* e = &o->f20[idx];
    o->f52 = e->f2;
    delete[] o->f48;
    o->f48 = new (o->f4) Item[o->f52];
    f32 r = func_0023c5a0(o, idx);
    o->f68 = r;
    if (r < o->f64) o->f64 = r;
    o->f68 = o->f68 + 1.0f;
    Seg* s = &o->f16[e->f0];
    for (s32 i = 0; i < o->f52; i++) {
        u8* img = GetImage294(o->f40, s->f0);
        func_00239988(&o->f48[i], o->f8 + o->f24[s->f4], img);
        wtarget294_00239bf8(&o->f48[i], s->f8);
        s++;
        Item& it = o->f48[i]; it.f68 = o->f72;
    }
    o->f80 = func_0023c978(o);
}
}
}

namespace n002515a0 {
extern "C" {
struct Sub { u8 pad[184]; u32 f184; void set8() { f184 |= 8; } };
struct Sc { u8 pad[24]; Sub sub; u8 pad2[405-24-188]; u8 f405; };
extern Sc* D_0035ee80;
extern s32 D_0035ee60;
extern void* D_0035ee5c;
struct W { s32 v; };
extern W D_0035f3d4;
extern s32 D_003725c0[];
void func_0028d8c0(Sc*, s32, s32, s32, s32, s32, s32, s32);
void func_00288d80(void*, s32, s32, s32, s32, s32, s16*, s16*);
u8* func_002891b8(void*, s32);
s32 func_0023aa78(u8*);
void func_00288e08(void*, s32, s32, s32);
void func_00139620(u8*);
void func_0028dcc0(u8*, Sc*);
void func_002891f0(void*, s32, s32, s32, s32);
void func_0028af28(void*, s32);
void func_00287cc0(s32);
void func_002515a0(void) {
    s16 a[2][4];
    s32 i;
    for (i = 0; i < 2; i++) {
        for (s32 j = 0; j < 4; j++) {
            if (i == 1) a[1][j] = 11;
            else a[i][j] = 10;
        }
    }
    func_0028d8c0(D_0035ee80, 30013, 2, 2, D_0035ee60, 7, 8, 0);
    D_0035ee80->f405 = 1;
    D_0035ee80->sub.set8();
    s32 save = D_0035f3d4.v;
    D_0035f3d4.v = 30014;
    for (i = 0; i < 2; i++) {
        func_00288d80(D_0035ee5c, i, 2, 2, D_0035ee60, D_003725c0[i], a[0], a[1]);
        u8* o = func_002891b8(D_0035ee5c, i);
        func_00288e08(D_0035ee5c, i, 0, func_0023aa78(o + 24));
        func_00139620(o);
        *(s32*)(o + 432) = 2;
        func_0028dcc0(o, D_0035ee80);
    }
    D_0035f3d4.v = save;
    func_002891f0(D_0035ee5c, 1, 1, 0, 2);
    func_0028af28(D_0035ee5c, 64);
    func_00287cc0(0);
}
}
}
