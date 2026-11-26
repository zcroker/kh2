// Linked unit 0x0020a090-0x0020a510 (strip particle init; moved from src/anon/batch_wcx2_nsi.c).
#include "../common/types.h"

/* The soft-float double compare (rand() > 0.5) is a libcall to dpcmp, which lives in the game at 0x3142e0. */
asm("dpcmp = func_003142e0");
asm("fptodp = func_00313b80");

/* 0020a090: strip particle init from its emitter record (random colour spread, angle, speeds, signs). */
typedef struct {
    u8 pad0[4]; s32 kind; u8 pad8[12]; u16 life; u8 tex;
    u8 pad23; f32 pos[4]; u8 pad40[16]; u8 col[4]; f32 f60, f64; u8 pad68[4]; f32 f72, f76;
    u8 pad80[16]; f32 f96, f100; u8 pad104[4]; f32 f108, f112; u8 pad116[4]; f32 f120;
    u8 pad124[12]; f32 f136; u8 pad140[4]; f32 f144; u8 pad148[35];
    u8 s;
    u8 r;
} Src20a090;
typedef struct {
    u8 pad0[34]; s16 h34; u8 pad36[2]; s16 h38; s8 col[4]; f32 f44, f48, f52, f56, f60, f64, f68, f72, f76, f80;
    s32 w84; u64 tex : 8, b8 : 1, texOn : 1, rest : 54;
} Dst20a090;
typedef struct { u8 pad0[6]; s16 h6; } Shape20a090;
typedef struct { Shape20a090* sh; s32 pad; } ShapeEnt20a090;
typedef struct { u8 pad0[20]; ShapeEnt20a090* shapes; } Res20a090;
extern Res20a090* D_01d9e6e4_20a090 asm("D_01d9e6e4"); /* same global as D_01d9e6e4, typed for this function */
s8 func_0020a000(u8);
f32 func_00209fb8(void);
void birth(Src20a090* s, Dst20a090* d, f32* pos)
{
    d->col[0] = func_0020a000(s->col[0]);
    d->col[1] = func_0020a000(s->col[1]);
    d->col[2] = func_0020a000(s->col[2]);
    d->col[3] = func_0020a000(s->col[3]);
    {
        s32 k = s->kind * 8; /* byte offset into the 8-byte shape entries */
        d->h34 = (*(Shape20a090**)((u8*)D_01d9e6e4_20a090->shapes + k))->h6 * func_00209fb8();
    }
    if (s->tex) {
        d->tex = s->tex;
        d->texOn = 1;
    }
    d->f44 = s->f108;
    d->f48 = s->f112;
    if (s->r) {
        d->f52 = func_00209fb8() * s->f120;
        if ((s->r & 1) && (s->r & 2)) {
            if (func_00209fb8() > 0.5) d->f52 = -d->f52;
        } else if (s->r & 2) {
            d->f52 = -d->f52;
        }
    }
    if ((s->r & 4)) d->f44 += d->f52;
    if ((s->r & 8)) d->f48 += d->f52;
    while (d->f44 >= 180.0f) d->f44 -= 360.0f;
    while (d->f44 < -180.0f) d->f44 += 360.0f;
    d->f56 = s->f60;
    d->f60 = s->f64;
    d->f64 = s->f72;
    d->f68 = s->f76;
    if (s->s) {
        if ((s->s & 0x20)) {
            d->f72 = d->f76 = func_00209fb8() * s->f96;
            if ((s->s & 1) && (s->s & 2)) {
                if (func_00209fb8() > 0.5) {
                    d->f72 = -d->f72;
                    d->f76 = -d->f76;
                }
            } else if (s->s & 2) {
                d->f72 = -d->f72;
                d->f76 = -d->f76;
            }
        } else {
            d->f72 = func_00209fb8() * s->f96;
            d->f76 = func_00209fb8() * s->f100;
            if ((s->s & 1) && (s->s & 2)) {
                if (func_00209fb8() > 0.5) d->f72 = -d->f72;
                if (func_00209fb8() > 0.5) d->f76 = -d->f76;
            } else if (s->s & 2) {
                d->f72 = -d->f72;
                d->f76 = -d->f76;
            }
        }
    }
    if ((s->s & 4)) {
        d->f56 += d->f72;
        d->f60 += d->f76;
    }
    if ((s->s & 8)) {
        d->f64 += d->f72;
        d->f68 += d->f76;
    }
    d->f80 = s->f136;
    if (s->f144 != 0.0f) d->f80 += s->f144 * 2.0f * func_00209fb8() - s->f144;
    if (!s->life) d->h38 = -1;
    else d->h38 = s->life;
    if (pos) {
        pos[4] = s->pos[0];
        pos[5] = s->pos[1];
        pos[6] = s->pos[2];
        pos[7] = s->pos[3];
    }
    d->w84 = 0;
}
