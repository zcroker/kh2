#include "../common/types.h"
extern "C" {
struct Col1b1560 {
    u8 r, g, b, a;
    void Set(s32 v) { r = v; g = v; b = v; a = v; }
    void Set(s32 ar, s32 ag, s32 ab, s32 aa) { r = ar; g = ag; b = ab; a = aa; }
};
struct Fog1b1560 { Col1b1560 c; f32 near, far, min, max; };
struct Eff1b1560 {
    s32 type;
    Eff1b1560* next;
    f32 t;
    u8 pad[4];
    u32 flags;
    Col1b1560 c;
    f32 near, far, min, max;
};
extern Eff1b1560* D_01d44100;

extern u8 D_00350e8c;
Fog1b1560* f1b1560_getFogDefault(void) asm("_ZN2dk8MapColor13getFogDefaultEv");
s32 func_001b1b58(Eff1b1560*);
void func_001b1ab8(Eff1b1560*);
void func_0015efa0(u8, u8, u8);
void func_0015ca40(u8, u8, u8, f32, f32, f32, f32);
void dk__Map__noDrawAll(void);
void func_0015f548(void);
static inline void Mod1b1560(Col1b1560* d, const Col1b1560* s, f32 t)
{
    Col1b1560 k;
    k.Set((s32)((s->r - 128) * t) + 128, (s32)((s->g - 128) * t) + 128, (s32)((s->b - 128) * t) + 128, (s32)((s->a - 128) * t) + 128);
    d->r = d->r * k.r >> 7;
    d->g = d->g * k.g >> 7;
    d->b = d->b * k.b >> 7;
    d->a = d->a * k.a >> 7;
}
// 001b1560: moved to src/anon/unit_001b14d8.cpp
}

/* ---- 0020c9d0 ---- */
struct Ent20c9d0 { u8 pad[0x1c]; u16* data; s32 f20; };
struct Tbl20c9d0 { u8 pad[0x10]; Ent20c9d0* ents; };
struct Ctx20c9d0 { u8 pad[0x90]; s32 f90; s32 f94; };
struct Param20c9d0 {
    u32 flags;      /* 00 */
    void* p04;      /* 04 */
    u16 h08;        /* 08 */
    u8 b0a;         /* 0a */
    u8 pad0b;
    s32 f0c;        /* 0c */
    union { s64 xy; struct { s32 x, y; } s; } pos; /* 10 */
    u8 c[4];        /* 18 */
    s32 f1c;        /* 1c */
    void* p20;      /* 20 */
    void* p24;      /* 24 */
    void* p28;      /* 28 */
    void* p2c;      /* 2c */
    void* p30;      /* 30 */
    s32 prev;       /* 34 */
    s32 f38;        /* 38 */
    s32 f3c;        /* 3c */
    s32 f40;        /* 40 */
    s32 f44;        /* 44 */
    u8 pad48[5];
    u8 b4d;         /* 4d */
    u8 pad4e[0x12];
};
struct Elem20c9d0 {
    u8 pad0[0x20];
    u16 on;         /* 20 */
    s8 c[4];        /* 22 */
    u8 pad26[0x7c - 0x26];
    f32 x;          /* 7c */
    f32 y;          /* 80 */
    u8 pad84[0x94 - 0x84];
    f32 fade;       /* 94 */
    u64 flags;      /* 98 */
};
struct Col20c9d0 { f32 r, g, b, a; u8 pad[16]; };
struct Grp20c9d0 {
    Elem20c9d0* elems;
    Col20c9d0* cols;
    s32 n;
    f32 alpha;
    u8 pad10[2];
    u8 f12;
};
struct Base20c9d0 { u8 pad[8]; u8 r, g, b, a; };
struct Hdr20c9d0 { u8 pad[4]; s32 off4; s32 off8; };
struct Arg20c9d0 { u8 pad[12]; Hdr20c9d0* h; };
struct Par20c9d0 { u8 pad[4]; s32 idx; u8 f8; u8 pad9[0xd0 - 9]; f32 dist; f32 range; };
struct Obj20c9d0 { u8 pad[64]; };
extern "C" {
extern Tbl20c9d0* D_01d9e6e4;
extern Ctx20c9d0* D_01d9e6e8;
extern s32 D_01d9eaa4;
extern u8 D_01d9eac0[];
s32 func_0020b4b8(Grp20c9d0*, Par20c9d0*);
void func_0020c858(Obj20c9d0*, Par20c9d0*, Grp20c9d0*);
f32 func_0020c860(Obj20c9d0*, f32*, Par20c9d0*, Grp20c9d0*, Elem20c9d0*);
s32 func_0020f1e0(u16*, Param20c9d0*, s32);
void pppRyjDrawMegaBirthModelFilter(u8* base, Par20c9d0* par, Arg20c9d0* arg);  // 0x0020c9d0: definition moved into src/anon/unit_0020c580.cpp
}
