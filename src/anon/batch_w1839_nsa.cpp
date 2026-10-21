#include "../common/types.h"
struct Obj {
    u8 pad0[0x10c]; u32 f10c;
    u8 pad1[0x768 - 0x110]; u32 f768;
    u8 pad2[0x9ac - 0x76c]; u8 mode;
};
static inline void setSub(Obj* p, s32 s) {
    switch (s) {
    case 0: p->f768 &= ~0x200; p->f768 &= ~0x400; break;
    case 1: p->f768 |= 0x200; p->f768 &= ~0x400; break;
    case 2: p->f768 &= ~0x200; p->f768 |= 0x400; break;
    }
}
struct Ent { s32 a; s32 b; s32 c; };
struct Dst {
    Ent e[32];
    u8 pad0[0x188 - 0x180]; u16 h188; u16 pad18a; u16 h18c; u16 pad18e;
    u8 pad1[0x198 - 0x190]; s32 w198; s32 w19c; s32 w1a0; s32 w1a4;
    u8 b1a8[7];
    u8 pad2[0x1c4 - 0x1af]; f32 f1c4;
    u8 pad3[0x264 - 0x1c8]; struct Src* src;
};
struct Src { u16 h0; u16 id; u16 v[32]; u16 m44; u16 m46; u16 k[7]; };
struct G { u8 pad[300]; f32 f; };
extern G* D_00352130;
extern "C" {
u16* func_001c0c80(u16);
u16* func_001c0cc8(void);
void wtarget_00194468(Obj* p, u32, u32, u32) asm("_Z16wtarget_00194468jjjj");
void wtarget_00194468(Obj* p, u32, u32, u32) {
    switch (p->mode) {
    case 0: p->f10c |= 0x200; break;
    case 1: case 2: case 3: setSub(p, p->mode - 1); p->f10c &= ~0x200; break;
    case 4: case 5: case 6: setSub(p, p->mode - 4); p->f10c |= 0x200; break;
    }
}
void func_001a0ee0(Dst* d, Src* s) {
    u16* t;
    s32 i;
    if (s->id) t = func_001c0c80(s->id);
    else t = func_001c0cc8();
    for (i = 0; i < 32; i++) {
        d->e[i].b = d->e[i].a = (t[0] * s->v[i] + 99) / 100;
        d->e[i].c = 0;
    }
    d->h188 = t[1];
    d->h18c = t[2];
    d->w198 = t[3];
    d->w19c = t[4];
    s32 r = d->e[0].b;
    d->w1a0 = (r * s->m44 + 9999) / 10000;
    d->w1a4 = (r * s->m46 + 9999) / 10000;
    for (i = 0; i < 7; i++) d->b1a8[i] = s->k[i];
    d->f1c4 = D_00352130->f;
    d->src = s;
}
}
