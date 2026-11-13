#include "../common/types.h"

// Light/fog effects (0x1b14d8-0x1b1c38): a pool of 16 effects (40 bytes each) with a free-index
// stack and an active list. Each frame the active effects are faded and folded into the map's
// light colour and fog. The static initialiser (0x1b1c38) and its _GLOBAL__I_ stub stay separate
// functions; the pool and list (0x1d44100, 0x1d44108) and the "lights off" flag (0x350e8c) are
// reached as data.

extern "C" {
// 0x1b14d8: resets the pool and list and starts the per-frame task (exit hook 0x1b18e8).
struct T2_001b14d8 { u32 a, b; };
extern T2_001b14d8 D_01d44100;
struct Sub_001b14d8 { u8 pad[640]; s32 arr[16]; };
extern Sub_001b14d8 D_01d44108;
extern s32 D_01d443c8;
extern u8 D_00350e8c;
void func_001b1560();
void func_001b18e8();
u8* func_00102c18_14d8(u32, u32, void (*)()) asm("func_00102c18");
void func_001b14d8() {
    D_01d44100.a = 0;
    D_01d44100.b = 0;
    for (s32 i = 0; i < 16; i++) D_01d44108.arr[i] = i;
    D_01d443c8 = 16;
    D_00350e8c = 0;
    *(void (**)())(func_00102c18_14d8(1, 42000, func_001b1560) + 48) = func_001b18e8;
}
}

// 0x1b1560: the per-frame task: folds every live effect into the light colour and the fog.
namespace u1b14d8_frame {
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
static inline void Mod1b1560(Col1b1560* d, const Col1b1560* s, f32 t)
{
    Col1b1560 k;
    k.Set((s32)((s->r - 128) * t) + 128, (s32)((s->g - 128) * t) + 128, (s32)((s->b - 128) * t) + 128, (s32)((s->a - 128) * t) + 128);
    d->r = d->r * k.r >> 7;
    d->g = d->g * k.g >> 7;
    d->b = d->b * k.b >> 7;
    d->a = d->a * k.a >> 7;
}
}  // namespace u1b14d8_frame

extern "C" {
extern u1b14d8_frame::Eff1b1560* D_01d44100_e asm("D_01d44100");
u1b14d8_frame::Fog1b1560* f1b1560_getFogDefault(void) asm("_ZN2dk8MapColor13getFogDefaultEv");
s32 func_001b1b58_e(u1b14d8_frame::Eff1b1560*) asm("func_001b1b58");
void func_001b1ab8_e(u1b14d8_frame::Eff1b1560*) asm("func_001b1ab8");
void func_0015efa0(u8, u8, u8);
void func_0015ca40(u8, u8, u8, f32, f32, f32, f32);
void func_0015f618(void);
void func_0015f548(void);
void func_001b1560(void)
{
    using namespace u1b14d8_frame;
    Col1b1560 col;
    col.Set(128);
    Fog1b1560 fog;
    Eff1b1560* e;
    fog = *f1b1560_getFogDefault();
    e = D_01d44100_e;
    while (e) {
        Eff1b1560* next = e->next;
        if (func_001b1b58_e(e)) {
            switch (e->type) {
            case 0:
                if (e->flags & 2) Mod1b1560(&col, &e->c, e->t);
                break;
            case 1:
                Mod1b1560(&fog.c, &e->c, e->t);
                fog.near += (e->near - fog.near) * e->t;
                fog.far += (e->far - fog.far) * e->t;
                fog.min += (e->min - fog.min) * e->t;
                fog.max += (e->max - fog.max) * e->t;
                break;
            }
        } else {
            func_001b1ab8_e(e);
        }
        e = next;
    }
    func_0015efa0(col.r, col.g, col.b);
    func_0015ca40(fog.c.r, fog.c.g, fog.c.b, fog.near, fog.far, fog.min, fog.max);
    if (!(col.r | col.g | col.b)) {
        if (!D_00350e8c) {
            func_0015f618();
            D_00350e8c = 1;
        }
    } else if (D_00350e8c) {
        func_0015f548();
        D_00350e8c = 0;
    }
}
}

// 0x1b18e8 (not in the layout): the task's exit hook: releases every live effect.
namespace u1b14d8_list {
struct N1b { u32 f0; N1b* next; u8 pad[32]; };
struct Pool1b { N1b items[16]; s32 freeIdx[16]; s32 nfree; };
struct List1b { N1b* head; N1b* tail; };
}  // namespace u1b14d8_list

extern "C" {
extern u1b14d8_list::List1b D_01d44100_l asm("D_01d44100");
extern u1b14d8_list::Pool1b D_01d44108_l asm("D_01d44108");
void func_001b1ab8(u1b14d8_list::N1b* n);
void func_001b18e8() {
    using namespace u1b14d8_list;
    N1b* n = D_01d44100_l.head;
    while (n) {
        N1b* nx = n->next;
        func_001b1ab8(n);
        n = nx;
    }
}

// 0x1b1928: YS::LIGHT::Create(int): takes an effect from the pool, initialises it and appends it.
struct LightPool { u8 ent[16][40]; s32 idx[16]; s32 count; };
extern LightPool D_01d44108_c asm("D_01d44108");
struct LightList { u8* head; u8* tail; };
extern LightList D_01d44100_c asm("D_01d44100");
void func_001b1a30(u8*, s32);
u8* ys_light_create(s32 t) asm("_ZN2YS5LIGHT6CreateEi");
u8* ys_light_create(s32 t) {
    s32 n = --D_01d44108_c.count;
    u8* l = D_01d44108_c.ent[D_01d44108_c.idx[n]];
    func_001b1a30(l, t);
    if (!D_01d44100_c.tail) {
        D_01d44100_c.tail = l;
        D_01d44100_c.head = l;
    } else {
        *(u8**)(D_01d44100_c.tail + 4) = l;
        D_01d44100_c.tail = l;
    }
    *(u8**)(l + 4) = 0;
    return l;
}

// 0x1b19a8 (not in the layout) and 0x1b1a30: the effect's constructor, C2 and C1 copies.
struct C4_001b1a30 { u8 r, g, b, a; };
f32* func_0015cc70();
void func_001b19a8(u8* p, s32 a1) {
    *(s32*)p = a1;
    *(u32*)(p + 12) = 0;
    s32 m = 128;
    *(u32*)(p + 16) = 0;
    *(f32*)(p + 8) = 1.0f;
    C4_001b1a30* c = (C4_001b1a30*)(p + 20);
    c->r = m;
    c->g = m;
    c->b = m;
    c->a = m;
    if (*(s32*)p == 1) {
        f32* v = func_0015cc70();
        *(f32*)(p + 24) = v[1];
        *(f32*)(p + 28) = v[2];
        *(f32*)(p + 32) = v[3];
        *(f32*)(p + 36) = v[4];
    }
}

void func_001b1a30(u8* p, s32 a1) {
    *(s32*)p = a1;
    *(u32*)(p + 12) = 0;
    s32 m = 128;
    *(u32*)(p + 16) = 0;
    *(f32*)(p + 8) = 1.0f;
    C4_001b1a30* c = (C4_001b1a30*)(p + 20);
    c->r = m;
    c->g = m;
    c->b = m;
    c->a = m;
    if (*(s32*)p == 1) {
        f32* v = func_0015cc70();
        *(f32*)(p + 24) = v[1];
        *(f32*)(p + 28) = v[2];
        *(f32*)(p + 32) = v[3];
        *(f32*)(p + 36) = v[4];
    }
}

// 0x1b1ab8: releases an effect: back to the free stack, out of the active list.
void func_001b1ab8(u1b14d8_list::N1b* n) {
    using namespace u1b14d8_list;
    D_01d44108_l.freeIdx[D_01d44108_l.nfree++] = n - D_01d44108_l.items;
    N1b* prev;
    if (n == D_01d44100_l.head) {
        D_01d44100_l.head = n->next;
        prev = 0;
    } else {
        prev = D_01d44100_l.head;
        while (prev->next != n) prev = prev->next;
        prev->next = n->next;
    }
    if (n == D_01d44100_l.tail) D_01d44100_l.tail = prev;
    n->next = 0;
}

// 0x1b1b58: steps the effect's fade; 0 once it has faded out.
void func_001ad9c8(...);  // float_accumulate_clamped
u32 func_001b1b58(u8* a0) {
    u8* s0 = a0;
    func_001ad9c8(s0 + 8);
    if (*(f32*)(s0 + 8) == 0.0f) {
        return 0;
    }
    return 1;
}

// 0x1b1b98 (not in the layout): is the fade still moving?
u8 func_001b1b98(u8* p) {
    s32 r = *(f32*)(p + 12) != 0.0f;
    return r;
}

// 0x1b1bb8: sets the effect's colour and fades it in.
void func_001b1be0(u8*);
void func_001b1bb8(u8* p, u32 r, u32 g, u32 b, u32 a) {
    u8* c = p + 20;
    p[20] = r;
    c[1] = g;
    c[2] = b;
    c[3] = a;
    func_001b1be0(p);
}

// 0x1b1be0: fades the effect in over x.
void func_001ad990(u8*, f32, f32, f32);
void func_001b1be0_f(u8* p, f32 x) asm("func_001b1be0");
void func_001b1be0_f(u8* p, f32 x) {
    func_001ad990(p + 8, 0.0f, 1.0f, x);
}

// 0x1b1c10: fades the effect out over a1.
void func_001ad990_u(u32, f32, f32, f32) asm("func_001ad990");
void func_001b1c10(u8* a0, f32 a1) {
    func_001ad990_u((u32)(a0 + 8), *(f32*)(a0 + 8), 0.0f, a1);
}
}
