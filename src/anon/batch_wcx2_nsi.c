#include "../common/types.h"

/* Plain C code (partMng family). Lives in _nsi.c only because batch_wcx2.c would share the object name with batch_wcx2.cpp; it matches with or without -fno-sched-interblock.
   00204850: strip particle physics step (colour integrate, angle step, VU0 position update, fade counters). */
typedef struct Em048 Em048; typedef struct Pr048 Pr048; typedef struct Pt048 Pt048; typedef struct Cf048 Cf048;
struct Em048 { u8 pad[64]; f32 v64[4]; };
struct Pr048 {
    u8 pad0[34]; u16 h34; u8 pad36; u8 b37; u8 pad38[56 - 38];
    f32 f56, f60, f64, f68; u8 pad72[100 - 72]; f32 f100, f104; u8 pad108[132 - 108];
    f32 f132; u8 pad136[164 - 136]; f32 f164, f168; u8 pad172[180 - 172]; f32 f180;
    u8 pad184[202 - 184]; u8 b202, b203; u8 pad204[2]; u8 b206;
};
struct Pt048 {
    f32 pos[4]; f32 vel[4]; u8 pad32[38 - 32]; u16 h38; u8 pad40[44 - 40]; u8 b44; u8 pad45; u16 h46; s16 h48; s16 h50;
    f32 f52, f56, f60, f64, f68, f72, f76, f80, f84, f88; u8 b92, b93, b94, b95;
};
struct Cf048 { f32 x, y, z, w, vx, vy, vz, vw; };
void func_00204850(Em048* e, Pr048* p, Pt048* pt, u8* col, Cf048* cf)
{
    s32 alpha = col[11];
    if (cf) {
        cf->x += cf->vx;
        cf->y += cf->vy;
        cf->z += cf->vz;
        cf->w += cf->vw;
        s32 w = (s32)cf->w;
        cf->vx += p->f56;
        cf->vy += p->f60;
        cf->vz += p->f64;
        cf->vw += p->f68;
        alpha = col[11] + w;
        if (alpha > 255) alpha = 255;
    }
    pt->h46 += pt->h48;
    if (p->b203 & 0x10) pt->h48 += p->f132 + pt->h50;
    else pt->h48 += p->f132;
    pt->f52 += pt->f60;
    pt->f56 += pt->f64;
    if (p->b202 & 0x10) {
        pt->f60 += p->f100 + pt->f68;
        pt->f64 += p->f104 + pt->f72;
    } else {
        pt->f60 += p->f100;
        pt->f64 += p->f104;
    }
    pt->f76 += p->f168;
    if (!p->b206) {
        if (p->f164 > 0.0f && p->f168 < 0.0f) {
            if (pt->f76 < 0.0f) pt->f76 = 0.0f;
        } else if (p->f164 < 0.0f && p->f168 > 0.0f) {
            if (pt->f76 > 0.0f) pt->f76 = 0.0f;
        }
    }
    pt->f80 += p->f180;
    /* hand-written VU0 block: pos.xyz += vel.xyz * f76 + wind.xyz * f80 */
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tlw $8, 0(%2)\n\tqmtc2 $8, $vf3\n\tlqc2 $vf4, 0(%3)\n\tlw $9, 0(%4)\n\tqmtc2 $9, $vf5\n\t"
                 "vmulx.xyz $vf2, $vf2, $vf3x\n\tvmulx.xyz $vf4, $vf4, $vf5x\n\tvadd.xyz $vf1, $vf1, $vf2\n\tvadd.xyz $vf1, $vf1, $vf4\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(pt->pos), "r"(pt->vel), "r"(&pt->f76), "r"(e->v64), "r"(&pt->f80) : "$8", "$9", "memory");
    if (p->h34) pt->h38--;
    pt->b44++;
    if (pt->b92 && pt->b44 <= pt->b92) pt->f84 -= (f32)alpha / (f32)pt->b92;
    if (pt->b93 && pt->h38 <= pt->b93) pt->f84 += (f32)alpha / (f32)p->b37;
    if (pt->b94 && pt->b44 <= pt->b94) pt->f88 = (f32)pt->b44 / (f32)pt->b94;
    if (pt->b95 && pt->h38 <= pt->b95) pt->f88 = (f32)pt->h38 / (f32)pt->b95;
}

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
void func_002f3f88(V203408*, V203408*);
s32 func_002fe0a0(char*);
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
            func_002f3f88(&st->hist[i * 2], &D_00354680[0]);
            func_002f3f88(&st->hist[i * 2 + 1], &D_00354680[1]);
        }
    }
    set = (Set203408*)(D_01d9e6e4->sets + e->set * 36);
    h = (H203408*)(set->data + *(s32*)(set->data + 4));
    k = 0;
    while (h->type != -1) {
        size = 0;
        switch (h->type) {
        case 0: case 1: case 2: case 3: case 5: case 7:
            return func_002fe0a0(D_00370378);
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
