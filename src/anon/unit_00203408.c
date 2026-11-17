// Linked unit 0x00203408-0x002039c0 (ryjProg/pppRyjDrawShipolyBone.c: trail/strip set-up and draw; set-up moved from src/anon/batch_wcx2_nsi.c, draw 0x203740 was a gap).
#include "../common/types.h"

/* 00203408: trail/strip effect set-up: allocate the history vectors, then number the vertices of
   every strip record (types 4 and 6) in the model set; unknown record types print an error. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V203408;
typedef struct { u8 r, g, b, a; } C203408;
typedef struct { C203408 col[4]; s16 idx[4]; } R203408;
typedef struct { u8 pad0; s8 type; s16 count; u8 pad4[12]; } H203408;
typedef struct { s32 f0; s32 set; u8 pad8[6]; u8 n; } Ent203408;
typedef struct { u8 pad0[12]; s32* off; } Ctx203408;
typedef struct { u8 pad0[16]; u8* sets; } Res203408;
typedef struct { u8 pad0[4]; u8 n; u8 pad5[3]; V203408* hist; } St203408;
typedef struct { s32 w0; u8 pad4[4]; s32 w8; u8 pad12[16]; u8* data; } Set203408;
extern Res203408* D_01d9e6e4;
extern V203408* D_00354680;
extern s32 D_00354684;
extern char D_003703e0[];
extern char D_00370398[];
extern char D_00370378[];
void* func_001e7698(Res203408*, s32);
void func_002233f0(char*, char*, s32);
void sceVu0CopyVector(V203408*, V203408*);
s32 puts(char*);
void func_00202ce0(Set203408*, Ent203408*, St203408*);
s32 func_00203408(u8* base, Ent203408* e, Ctx203408* c)
{
    St203408* st = (St203408*)(base + c->off[1] + 160);
    Set203408* set;
    H203408* h;
    s32 i, j, k, size;
    R203408* r;
    if (e->set == 0xffff) return;
    if (D_00354680 == 0) return;
    if (D_00354684 <= 0) return;
    if (st->hist == 0) {
        u8 n = e->n;
        st->n = n;
        st->hist = func_001e7698(D_01d9e6e4, n * 32);
        if (st->hist == 0) func_002233f0(D_003703e0, D_00370398, 551);
        for (i = 0; i < st->n; i++) {
            sceVu0CopyVector(&st->hist[i * 2], &D_00354680[0]);
            sceVu0CopyVector(&st->hist[i * 2 + 1], &D_00354680[1]);
        }
    }
    set = (Set203408*)(D_01d9e6e4->sets + e->set * 36);
    h = (H203408*)(set->data + *(s32*)(set->data + 4));
    k = 0;
    while (h->type != -1) {
        size = 0;
        switch (h->type) {
        case 0: case 1: case 2: case 3: case 5: case 7:
            return puts(D_00370378);
        case 4:
            r = (R203408*)(h + 1);
            for (j = 0; j < h->count; j++, k++) {
                r->idx[0] = k * 2;
                r->idx[1] = k * 2 + 1;
                r->idx[2] = k * 2 + 2;
                r->idx[3] = k * 2 + 3;
                r->col[0].r = r->col[1].r = r->col[2].r = r->col[3].r =
                r->col[0].g = r->col[1].g = r->col[2].g = r->col[3].g =
                r->col[0].b = r->col[1].b = r->col[2].b = r->col[3].b = 0xff;
                r = (R203408*)((u8*)r + 24);
            }
            size = 24;
            break;
        case 6:
            r = (R203408*)(h + 1);
            for (j = 0; j < h->count; j++, k++) {
                r->idx[0] = k * 2;
                r->idx[1] = k * 2 + 1;
                r->idx[2] = k * 2 + 2;
                r->idx[3] = k * 2 + 3;
                r->col[0].r = r->col[1].r = r->col[2].r = r->col[3].r =
                r->col[0].g = r->col[1].g = r->col[2].g = r->col[3].g =
                r->col[0].b = r->col[1].b = r->col[2].b = r->col[3].b = 0xff;
                r = (R203408*)((u8*)r + 40);
            }
            size = 40;
            break;
        }
        h = (H203408*)((u8*)h + size * h->count);
        h = h + 1;
    }
    if (set->w0 == set->w8 * 2 + 2) func_00202ce0(set, e, st);
}

/* 00203740 (was gap, written for the unit): strip draw: fill the packet and hand it to the model drawer. */
typedef struct {
    u32 flags; void* tex; u16 h08; u8 b0a; u8 pad0b; s32 f0c; s64 pos; u8 c[4]; s32 f1c;
    void* mtx; void* p24; void* p28; void* p2c; void* p30; s32 prev; s32 f38; s32 f3c; s32 f40;
    void* p44; u8 pad48[4]; u8 b4c; u8 b4d; u8 pad4e[0x12];
} Pk203740;
typedef f32 Mtx203740[4][4] __attribute__((aligned(16)));
typedef struct { u32 w0; u8 pad4[18]; u16 h22; } Model203740;
typedef struct { u8 pad0[28]; Model203740* model; s32 f32; } Ent203740;
typedef struct { u8 pad0[16]; Ent203740* ents; } Bank203740;
typedef struct { u8 pad0[4]; s32 id; u8 b8, b9, b10, b11, b12; u8 pad13[6]; u8 b19; } Par203740;
extern u8* D_01d9e6e8;
extern s32 D_01d9eaa4;
extern u8 D_01d9eac0[];
extern u8 D_01d9e9c0[];
extern u8 D_01d9e980[];
extern f32 D_01d9e840[4][4];
extern f32 D_01d9ea00[4][4];
void sceVu0MulMatrix(f32 (*)[4], f32 (*)[4], f32 (*)[4]);
void sceVu0UnitMatrix(f32 (*)[4]);
s32 func_0020f1e0(Model203740*, Pk203740*, s32);
static inline void ini203740(Pk203740* q, Model203740* md) { q->p44 = 0; q->h08 = md->h22; q->f1c = 0; q->b0a = 0; }
void func_00203740(u8* base, Par203740* d, Ctx203408* c)
{
    Pk203740 p;
    Mtx203740 m;
    u8* col;
    Ent203740* ent;
    Model203740* md;
    func_00203408(base, (Ent203408*)d, c);
    if (d->id == 0xffff) return;
    if (D_00354680 == 0) return;
    if (D_00354684 <= 0) return;
    col = base + c->off[0] + 160;
    if ((p.c[3] = col[11]) == 0) return;
    ent = &((Bank203740*)D_01d9e6e4)->ents[d->id];
    md = ent->model;
    p.flags = 0;
    if (d->b8 & 2) {
        p.flags = 4;
        if ((md->w0 & 1) == 0) p.flags |= 8;
    } else {
        if (d->b8 & 1) p.flags = 128;
        if ((md->w0 & 1) == 0) p.flags |= 8;
    }
    if ((md->w0 & 2) == 0) p.flags |= 0x10;
    if (d->b9) p.flags |= 0x200;
    if (d->b11) p.flags |= 0x100;
    if (d->b10) {
        p.flags |= 0x2000;
        p.p30 = m;
        sceVu0MulMatrix(m, D_01d9e840, (f32 (*)[4])(D_01d9e6e8 + 16));
    }
    ini203740(&p, md);
    p.f38 = *(s32*)(D_01d9e6e8 + 144);
    p.f3c = *(s32*)(D_01d9e6e8 + 148);
    p.tex = D_01d9eac0;
    sceVu0UnitMatrix((f32 (*)[4])(D_01d9e6e8 + 80));
    sceVu0CopyVector((V203408*)(D_01d9e6e8 + 128), D_00354680);
    sceVu0MulMatrix((f32 (*)[4])(D_01d9e6e8 + 80), D_01d9ea00, (f32 (*)[4])(D_01d9e6e8 + 80));
    p.mtx = D_01d9e6e8 + 80;
    p.c[0] = col[8];
    p.c[1] = col[9];
    p.c[2] = col[10];
    p.p24 = D_01d9e9c0;
    p.p28 = D_01d9e980;
    p.p2c = D_01d9e6e8 + 16;
    p.prev = D_01d9eaa4;
    p.b4c = d->b12;
    p.b4d = d->b19;
    p.f0c = 0;
    p.pos = 0;
    p.f40 = 0;
    D_01d9eaa4 = func_0020f1e0(md, &p, ent->f32);
}
