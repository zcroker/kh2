// Linked unit 0x00203408-0x00203740 (ryjProg/pppRyjDrawShipolyBone.c: trail/strip set-up; moved from src/anon/batch_wcx2_nsi.c).
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
