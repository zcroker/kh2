#include "../common/types.h"

/* 00112ab8 */
struct W1886P0;
struct W1886P0Vt { u8 pad[0x60]; s32 (*fn)(W1886P0*); };
struct W1886P0 { W1886P0Vt* vt; u8 pad[0x140 - 4]; u8 sub[0x14]; s32 v154; u8 pad2[0x7f8 - 0x158]; u32 flags; };
struct W1886Pn { u8 pad[0xb7c]; u32 flags; };
struct W1886G { W1886P0* p0; W1886Pn* p1; W1886Pn* p2; };
struct W1886Q { u8 pad[4]; u8 kind; };
struct W1886Arg { s32 v0; u8 pad[0xc]; s32 v10; u8 pad2[0xc]; W1886Q* q; };
static inline bool w1886_isk(W1886Q* q) { return q->kind == 5 || q->kind == 6; }

/* 002362b0 */
struct W1886GSrc {
    u8 pad[8]; s32 o8; u8 pad1[4]; s32 o16; u8 pad2[4];
    s32 v24; u16 h28, h30, h32, h34, h36, h38; s32 v40; u16 h44, h46, h48, h50;
    u8 pad3[8]; u32 f0:1; u32 f1:1; u32 f2:1;
};
struct W1886GDst {
    u8 pad[4]; s32 v4; u32 h8, h12, h16, h20, h24, h28; s32 v32; u32 h36, h40, h44;
    u64 h48:32; u64 b0:1; u64 b1:1; u64 b2:1;
    u8* p56; u8* p60; u8 pad4[400 - 64]; u8 neg2; u8 pad5[3]; s32 z404; u8* p408;
};

/* 00236a58: Tz::MenuBasic::SetGraRes */
extern "C" {
void* func_001063f0(u32, u32);
}
struct W1886Gra {
    u8 pad[396]; u8 flag; u8 pad2[15];
    static void* operator new[](unsigned int sz, u32 h) { return func_001063f0(sz, h); }
    static void operator delete[](void*) asm("func_00106450");
    W1886Gra(); /* the complete constructor is func_002361a0 (see the asm alias below) */
    void setFlag() { flag = 1; }
    virtual ~W1886Gra();
} __attribute__((aligned(16)));
asm("_ZN8W1886GraC1Ev = func_002361a0");
struct W1886Ent { s32 off; s32 pad; };
struct W1886Res { u8 pad[6]; s8 flag; u8 pad2; s32 entOff; s32 n; };
struct W1886Menu { u8 pad[4]; u32 heap; W1886Res* res; W1886Ent* ents; s32 n; W1886Gra* gra; };

extern "C" {
extern W1886G D_00341708;
extern s32 D_003417c4;
extern f32 D_003417c8;
extern f32 D_003417cc;
extern s32 D_003417d0;
s32 func_00112d90(W1886Arg*);
f32 func_001806f8(void*, s32);
void func_001129d8(s32);
void func_00112ab8(s32 mode, W1886Arg* arg)
{
    W1886G* g = &D_00341708;
    W1886P0* p = g->p0;
    switch (mode) {
    case 0:
        if (arg == 0) break;
        if (p->flags & 4) break;
        if (p->vt->fn(p)) break;
        if (w1886_isk(arg->q)) break;
        func_001129d8(arg->v10);
        if (g->p1) g->p1->flags &= ~0x100;
        if (g->p2) g->p2->flags &= ~0x100;
        break;
    case 1: {
        D_003417c4 = 0;
        if (arg && func_00112d90(arg)) D_003417c4 = arg->v0;
        f32 f = func_001806f8(D_00341708.p0->sub, -1);
        D_003417cc = D_003417c8 = f;
        D_003417d0 = D_00341708.p0->v154;
        if (D_00341708.p1) D_00341708.p1->flags &= ~0x200;
        if (D_00341708.p2) D_00341708.p2->flags &= ~0x200;
        break;
    }
    }
}

void func_00236560(W1886GDst*);
void func_002362b0(W1886GDst* d, W1886GSrc* s)
{
    d->v4 = s->v24 < 0 ? 0x3600 : s->v24 >> 8;
    d->h8 = s->h28;
    d->h12 = s->h30;
    d->h16 = s->h32;
    d->h20 = s->h34;
    d->h24 = s->h36;
    d->h28 = s->h38;
    d->v32 = s->v40 < 0 ? 0x3500 : s->v40 >> 8;
    d->h36 = s->h44;
    d->h40 = s->h46;
    d->h44 = s->h48;
    d->h48 = s->h50;
    d->b0 = s->f0;
    d->b1 = s->f1;
    d->b2 = s->f2;
    d->p56 = (u8*)s + s->o8;
    d->p60 = (u8*)s + s->o16;
    d->neg2 = s->v24 == -2;
    d->z404 = 0;
    d->p408 = (u8*)s + 56;
    func_00236560(d);
}

void func_002367c8(W1886Gra*);
}
void W1886_SetGraRes(W1886Menu* m, W1886Res* r, u32 heap) asm("_ZN2Tz9MenuBasic9SetGraResEz");
void W1886_SetGraRes(W1886Menu* m, W1886Res* r, u32 heap)
{
    s32 i;
    m->heap = heap;
    m->res = r;
    m->ents = (W1886Ent*)((u8*)r + r->entOff);
    m->n = r->n;
    if (m->gra) delete[] m->gra;
    m->gra = new (m->heap) W1886Gra[m->n];
    for (i = 0; i < m->n; i++) {
        func_002362b0((W1886GDst*)&m->gra[i], (W1886GSrc*)((u8*)r + m->ents[i].off));
        func_002367c8(&m->gra[i]);
        if (r->flag) m->gra[i].setFlag();
    }
}
