#include "../common/types.h"

typedef struct { f32 x, y, z, w; } Vec95d8;
typedef struct { u8 pad[0x40]; Vec95d8 pos; } Cam95d8;
typedef struct { u8 pad[168]; u64 flags; } Mgr95d8;
typedef struct { u8 pad[12]; s32* ofs; } Ctx95d8;
typedef struct { u16 r, g, b, a; } Col95d8;
typedef struct { Col95d8 c[6]; } Cols95d8;
typedef struct { s32 id; u8 pad4[28]; Cols95d8 add; u8 world; } Prm95d8;
typedef struct { u8 pad[12]; s32 id; u8 pad10[141]; u8 hide; } Own95d8;
/* per-owner trail state (owner + *ofs + 160) */
typedef struct { Cols95d8 h; Vec95d8 hist[28]; u8 pad[10]; u8 cur; } Trail95d8;
extern s32 D_01d9ea9c;
extern Mgr95d8* D_01d9e6e0;
extern Cam95d8* D_01d9e6e8;
extern u8 D_01d9e6f0[];
void sceVu0ApplyMatrix(Vec95d8*, void*, Vec95d8*);
void sceVu0CopyVector(Vec95d8*, Vec95d8*);

/* 001f95d8 (partMng): records the camera-relative position into a 28-entry position history ring
 * (filling the whole ring on first use), then accumulates the u16 colour sums (c2+=c3, c0+=c2,
 * c4+=c5, c1+=c4) and adds the parameter colours when the owner id matches. */
void func_001f95d8(Own95d8* o, Prm95d8* p, Ctx95d8* c)
{
    Trail95d8* t;
    Vec95d8 v;
    s32 i;
    Vec95d8* q;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    t = (Trail95d8*)((u8*)o + *c->ofs + 160);
    if (o->id == 0 && o->hide == 0) {
        if (p->world) { sceVu0ApplyMatrix(&v, D_01d9e6f0, &D_01d9e6e8->pos); v.w = 1.0f; }
        else { sceVu0CopyVector(&v, &D_01d9e6e8->pos); v.w = 1.0f; }
        q = t->hist;
        for (i = 28; i > 0; i--) { sceVu0CopyVector(q, &v); q++; }
    }
    if (t->cur == 0) t->cur = 28;
    t->cur--;
    if (p->world) {
        sceVu0ApplyMatrix(&t->hist[t->cur], D_01d9e6f0, &D_01d9e6e8->pos);
        ((f32*)&t->hist[t->cur])[3] = 1.0f;
    } else {
        sceVu0CopyVector(&t->hist[t->cur], &D_01d9e6e8->pos);
    }
    t->h.c[2].r += t->h.c[3].r;
    t->h.c[0].r += t->h.c[2].r;
    t->h.c[2].g += t->h.c[3].g;
    t->h.c[0].g += t->h.c[2].g;
    t->h.c[2].b += t->h.c[3].b;
    t->h.c[0].b += t->h.c[2].b;
    t->h.c[2].a += t->h.c[3].a;
    t->h.c[0].a += t->h.c[2].a;
    t->h.c[4].r += t->h.c[5].r;
    t->h.c[1].r += t->h.c[4].r;
    t->h.c[4].g += t->h.c[5].g;
    t->h.c[1].g += t->h.c[4].g;
    t->h.c[4].b += t->h.c[5].b;
    t->h.c[1].b += t->h.c[4].b;
    t->h.c[4].a += t->h.c[5].a;
    t->h.c[1].a += t->h.c[4].a;
    if (o->id != p->id) return;
    t->h.c[0].r += p->add.c[0].r;
    t->h.c[0].g += p->add.c[0].g;
    t->h.c[0].b += p->add.c[0].b;
    t->h.c[0].a += p->add.c[0].a;
    t->h.c[2].r += p->add.c[2].r;
    t->h.c[2].g += p->add.c[2].g;
    t->h.c[2].b += p->add.c[2].b;
    t->h.c[2].a += p->add.c[2].a;
    t->h.c[3].r += p->add.c[3].r;
    t->h.c[3].g += p->add.c[3].g;
    t->h.c[3].b += p->add.c[3].b;
    t->h.c[3].a += p->add.c[3].a;
    t->h.c[1].r += p->add.c[1].r;
    t->h.c[1].g += p->add.c[1].g;
    t->h.c[1].b += p->add.c[1].b;
    t->h.c[1].a += p->add.c[1].a;
    t->h.c[4].r += p->add.c[4].r;
    t->h.c[4].g += p->add.c[4].g;
    t->h.c[4].b += p->add.c[4].b;
    t->h.c[4].a += p->add.c[4].a;
    t->h.c[5].r += p->add.c[5].r;
    t->h.c[5].g += p->add.c[5].g;
    t->h.c[5].b += p->add.c[5].b;
    t->h.c[5].a += p->add.c[5].a;
}
