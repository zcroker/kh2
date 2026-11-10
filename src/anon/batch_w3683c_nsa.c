#include "../common/types.h"
typedef struct P96 P96; struct P96 {
    u8 pad0[28]; f32 key; u8 pad20[4]; u16 x36; u16 x38;
    s8 c[4]; u8 pad2c[0x54 - 0x2c]; f32 x84; u8 pad58[96 - 0x58];
};
typedef struct M64 M64; struct M64 { u8 b[64]; };
typedef struct C32 C32; struct C32 { f32 v[4]; u8 pad[16]; };
typedef struct PS PS; struct PS {
    u8 pad0[80]; P96* a96; M64* a64; C32* a32; u32 n;
};
typedef struct PQ PQ; struct PQ { u8 pad0[8]; u8 rgba[4]; };
typedef struct PT PT; struct PT { s16 x0; s16 x2; };
typedef struct PE PE; struct PE { s16 off; s16 pad1[3]; };
typedef struct PTb PTb; struct PTb { u8 hdr[16]; PE e[1]; };
typedef struct PW PW; struct PW { s32 x0; s32 x4; f32 x8; s32 xc; s32 rgba[4]; u8 pad20[0x30 - 0x20]; u8 x30[0x68 - 0x30]; f32 x68; };
typedef struct PO PO; struct PO {
    u8 pad0[128]; u8 m80[64]; u8 mc0[64]; u8 m100[128];
    s32 cnt; s32 base[4]; s32 col[4]; u8 pad1a4[0x1b0 - 0x1a4]; u8 v1b0[16];
};
typedef struct PEnt PEnt; struct PEnt {
    u8 pad0[4]; s32 id; u8 pad8[4]; u8 x0c; u8 pad0d; u8 x0e; u8 x0f; u8 pad10[8]; f32 x18;
    u8 pad1c[0xcd - 0x1c]; u8 xcd;
};
typedef struct PC2 PC2; struct PC2 { s32 x0; s32 x4; s32 x8; };
typedef struct PCtx PCtx; struct PCtx { u8 pad0[12]; PC2* c; };
typedef struct PD PD; struct PD { u8 pad0[20]; u8** tbl; };
extern PD* D_01d9e6e4;
extern u8* D_01d9e6e8;
extern u8 D_01d9e730[];
extern u8 D_01d9e8c0[];
extern u8 D_00354be0[];
extern char D_003704d0[], D_003704e8[];
s32 func_00203ae8(PS*);
s32* func_001e7698(PD*, u32);
void func_001e7798(PD*, void*);
void func_00205040(s32*, f32*, s32, s32);
void func_0021cda0(u8);
PW* func_0021e988(void);
PW* func_0021e998(void);
PO* func_0020eaf8(s32);
void func_0020ebd8(s32);
void u4_f3f98(void*, void*) asm("_Z16sceVu0CopyMatrixjjjj");
void sceVu0CopyVector(void*, void*);
void func_00204fe0(u8*, PO*, PEnt*, PS*);
PW* func_0021e9a8(void);
void func_00205798(u8*, PO*, void*, PEnt*, PS*, P96*, M64*);
void func_002233f0(char*, char*, s32);
void func_0021cdd0(PT*, PW*);
void func_001e7538(void);
void func_0020e0a0(void);

/* Built with -fno-strict-aliasing (_nsa file). The unused bp = &base keeps base in its stack home
   (sw a0,0(sp)) and blocks the sibcall at the end. */
void func_00205178(u8* base, PEnt* ent, PCtx* ctx)
{
    PS* s = (PS*)(base + ctx->c->x8 + 160);
    PQ* q = (PQ*)(base + ctx->c->x4 + 160);
    P96* a96 = s->a96;
    M64* a64 = s->a64;
    C32* a32 = s->a32;
    s32* order = 0;
    PW* r;
    PW* r2;
    PO* o;
    u8* tbl;
    u8** te;
    u32 i;
    u8** bp = &base;

    if (func_00203ae8(s) == 0) return;
    if (ent->id == 0xffff) return;
    if (!ent->x0f) {
        f32* keys;
        order = func_001e7698(D_01d9e6e4, s->n << 2);
        keys = (f32*)func_001e7698(D_01d9e6e4, s->n << 2);
        for (i = 0; i < s->n; i++) {
            order[i] = i;
            keys[i] = a96[i].key;
        }
        func_00205040(order, keys, 0, s->n - 1);
        func_001e7798(D_01d9e6e4, keys);
    }
    func_0021cda0(ent->x0c);
    r = func_0021e988();
    r2 = func_0021e998();
    o = func_0020eaf8(480);
    o->cnt = s->n;
    u4_f3f98(o->m80, D_01d9e730);
    u4_f3f98(o->mc0, D_01d9e8c0);
    u4_f3f98(o->m100, D_01d9e6e8 + 16);
    sceVu0CopyVector(o->v1b0, D_00354be0);
    func_00204fe0(base, o, ent, s);
    te = &D_01d9e6e4->tbl[ent->id * 2];
    {
        s32 v = ent->xcd;
        if (v != 1) v = 0;
        r->x0 = v;
    }
    if (ent->x0e) r->x8 = ent->x18; else r->x8 = 0.0f;
    tbl = *te;
    o->base[0] = q->rgba[0];
    o->base[1] = q->rgba[1];
    o->base[2] = q->rgba[2];
    o->base[3] = q->rgba[3];
    r2->x0 = r->x0;
    r2->x8 = r->x8;
    while (o->cnt-- > 0) {
        M64* m = 0;
        C32* c = 0;
        P96* p;
        PT* t;
        s32 k;
        if (!order) {
            k = o->cnt;
            p = &a96[k];
            if (a64) m = &a64[k];
            if (a32) c = &a32[k];
        } else {
            k = order[o->cnt];
            p = &a96[k];
            if (a64) m = &a64[k];
            if (a32) c = &a32[k];
        }
        if (!p->x38) continue;
        r = func_0021e9a8();
        func_00205798(base, o, r->x30, ent, s, p, m);
        if (!ent->x0f) p->key = r->x68;
        t = (PT*)(tbl + ((PE*)(16 + (p->x36 << 3) + tbl))->off);
        if (t->x2 >= 9) {
            // The original keeps the two %hi halves in t6/t7 (probably HIGHs hoisted by loop.c and
            // rematerialised by reload; -fmove-all-movables shows it); gcc ties them to a0/a1 here, so the argument setup is asm.
            register char* e asm("$4");
            register char* f asm("$5");
            register s32 l asm("$6");
            asm("lui $14,%%hi(D_003704d0)\n\tlui $15,%%hi(D_003704e8)\n\taddiu %0,$14,%%lo(D_003704d0)\n\taddiu %1,$15,%%lo(D_003704e8)\n\tli %2,1710"
                : "=r"(e), "=r"(f), "=r"(l) : : "$14", "$15");
            func_002233f0(e, f, l);
        }
        {
            s32 c0, c1, c2, c3;
            o->col[0] = c0 = o->base[0] + p->c[0];
            o->col[1] = c1 = o->base[1] + p->c[1];
            o->col[2] = c2 = o->base[2] + p->c[2];
            o->col[3] = c3 = (s32)((f32)o->base[3] + (f32)p->c[3] - p->x84);
            if (c) {
                o->col[0] = c0 + (s32)c->v[0];
                o->col[1] = c1 + (s32)c->v[1];
                o->col[2] = c2 + (s32)c->v[2];
                o->col[3] = c3 + (s32)c->v[3];
            }
        }
        if (o->col[0] < 0) o->col[0] = 0; else if (o->col[0] >= 256) o->col[0] = 255;
        if (o->col[1] < 0) o->col[1] = 0; else if (o->col[1] >= 256) o->col[1] = 255;
        if (o->col[2] < 0) o->col[2] = 0; else if (o->col[2] >= 256) o->col[2] = 255;
        if (o->col[3] < 0) o->col[3] = 0; else if (o->col[3] >= 128) o->col[3] = 127;
        r->rgba[0] = (u8)o->col[0];
        r->rgba[1] = (u8)o->col[1];
        r->rgba[2] = (u8)o->col[2];
        r->rgba[3] = (u8)o->col[3];
        func_0021cdd0(t, r);
        r->x0 = 10;
    }
    func_0020ebd8(480);
    func_001e7538();
    if (ent->xcd == 1) func_0020e0a0();
    if (order) func_001e7798(D_01d9e6e4, order);
}
