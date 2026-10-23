#include "../common/types.h"

/* Plain C (partMng family). */
/* The soft-float double compares (rand() > 0.5) are libcalls to fptodp/dpcmp, which live in the game. */
asm("dpcmp = func_003142e0");
asm("fptodp = func_00313b80");

/* 0020b4e8: strip particle init from its emitter record (colour spread, angles, rotations, uv scroll, random flips). */
typedef struct {
    u8 pad0[16]; u16 life; u8 fadeIn; u8 pad19; f32 pos[4]; u8 pad36[16]; u8 col[4];
    s32 ang[3]; s32 angv[3]; u8 pad80[12]; s32 anga[3]; f32 rot[3]; f32 rotv[3]; u8 pad128[12];
    f32 rota[3]; f32 u, du; u8 pad160[4]; f32 dur; f32 v, dv; u8 pad176[4]; f32 dvr; u8 pad184[12];
    f32 speed; u8 pad200[4]; f32 speedr; u8 pad208[35];
    u8 s; u8 r; u8 q; u8 flip;
} Src20b4e8;
typedef struct {
    u8 pad0[32]; u16 h32; s8 col[4]; u8 pad38[2]; s32 ang[3]; s32 angv[3]; s32 anga[3]; u8 pad76[8];
    f32 rot[3]; f32 rotv[6]; f32 speed; f32 u, v, du, dv; f32 f140, f144; f32 alpha;
    union { u64 all; u8 cnt; } f;
} Dst20b4e8;
s8 func_0020b458(u8);
f32 func_0020b410(void);
void func_0020b4e8(Src20b4e8* s, Dst20b4e8* d, f32* pos)
{
    s32 i;
    d->col[0] = func_0020b458(s->col[0]);
    d->col[1] = func_0020b458(s->col[1]);
    d->col[2] = func_0020b458(s->col[2]);
    d->col[3] = func_0020b458(s->col[3]);
    if (s->fadeIn) {
        d->f.cnt = s->fadeIn;
        d->f.all |= 0x200;
    }
    d->ang[0] = s->ang[0];
    d->ang[1] = s->ang[1];
    d->ang[2] = s->ang[2];
    d->angv[0] = s->angv[0];
    d->angv[1] = s->angv[1];
    d->angv[2] = s->angv[2];
    if (s->r) {
        if (s->r & 0x20) {
            d->anga[0] = d->anga[1] = d->anga[2] = func_0020b410() * (f32)s->anga[0];
            if ((s->r & 1) && (s->r & 2)) {
                if (func_0020b410() > 0.5) {
                    for (i = 0; i < 3; i++) d->anga[i] = -d->anga[i];
                }
            } else if (s->r & 2) {
                for (i = 0; i < 3; i++) d->anga[i] = -d->anga[i];
            }
        } else {
            d->anga[0] = func_0020b410() * (f32)s->anga[0];
            d->anga[1] = func_0020b410() * (f32)s->anga[1];
            d->anga[2] = func_0020b410() * (f32)s->anga[2];
            if ((s->r & 1) && (s->r & 2)) {
                for (i = 0; i < 3; i++) {
                    if (func_0020b410() > 0.5) d->anga[i] = -d->anga[i];
                }
            } else if (s->r & 2) {
                for (i = 0; i < 3; i++) d->anga[i] = -d->anga[i];
            }
        }
    }
    if (s->r & 4) {
        for (i = 0; i < 3; i++) d->ang[i] += d->anga[i];
    }
    if (s->r & 8) {
        for (i = 0; i < 3; i++) d->angv[i] += d->anga[i];
    }
    for (i = 0; i < 3; i++) {
        s32* w = (s32*)&d->h32; /* the original indexes this block as words from +32 */
        if (w[i + 2] < -0x8000 || w[i + 2] > 0x7fff) w[i + 2] %= 0x8000;
    }
    d->rot[0] = s->rot[0];
    d->rot[1] = s->rot[1];
    d->rot[2] = s->rot[2];
    d->rotv[0] = s->rotv[0];
    d->rotv[1] = s->rotv[1];
    d->rotv[2] = s->rotv[2];
    if (s->s) {
        if (s->s & 0x20) {
            d->rotv[3] = d->rotv[4] = d->rotv[5] = func_0020b410() * s->rota[0];
            if ((s->s & 1) && (s->s & 2)) {
                if (func_0020b410() > 0.5) {
                    for (i = 0; i < 3; i++) {
                    f32* rv = d->rotv;
                    rv[i + 3] = -rv[i + 3];
                }
                }
            } else if (s->s & 2) {
                for (i = 0; i < 3; i++) {
                    f32* rv = d->rotv;
                    rv[i + 3] = -rv[i + 3];
                }
            }
        } else {
            d->rotv[3] = func_0020b410() * s->rota[0];
            d->rotv[4] = func_0020b410() * s->rota[1];
            d->rotv[5] = func_0020b410() * s->rota[2];
            if ((s->s & 1) && (s->s & 2)) {
                for (i = 0; i < 3; i++) {
                    f32* rv = d->rotv;
                    if (func_0020b410() > 0.5) rv[i + 3] = -rv[i + 3];
                }
            } else if (s->s & 2) {
                for (i = 0; i < 3; i++) {
                    f32* rv = d->rotv;
                    rv[i + 3] = -rv[i + 3];
                }
            }
        }
    }
    if (s->s & 4) {
        for (i = 0; i < 3; i++) d->rot[i] += d->rotv[i + 3];
    }
    if (s->s & 8) {
        for (i = 0; i < 3; i++) d->rotv[i] += d->rotv[i + 3];
    }
    d->speed = s->speed;
    if (s->speedr != 0.0f) d->speed += s->speedr * 2.0f * func_0020b410() - s->speedr;
    d->u = s->u;
    d->v = s->v;
    d->du = s->du;
    d->dv = s->dv;
    if (s->q) {
        if (s->q & 0x20) {
            d->f140 = d->f144 = func_0020b410() * s->dur;
            if ((s->q & 1) && (s->q & 2)) {
                if (func_0020b410() > 0.5) {
                    d->f140 = -d->f140;
                    d->f144 = -d->f144;
                }
            } else if (s->q & 2) {
                d->f140 = -d->f140;
                d->f144 = -d->f144;
            }
        } else {
            d->f140 = func_0020b410() * s->dur;
            d->f144 = func_0020b410() * s->dvr;
            if ((s->q & 1) && (s->q & 2)) {
                if (func_0020b410() > 0.5) d->f140 = -d->f140;
                if (func_0020b410() > 0.5) d->f144 = -d->f144;
            } else if (s->q & 2) {
                d->f140 = -d->f140;
                d->f144 = -d->f144;
            }
        }
    }
    if (s->q & 4) {
        d->u += d->f140;
        d->v += d->f144;
    }
    if (s->q & 8) {
        d->du += d->f140;
        d->dv += d->f144;
    }
    if (!s->life) d->h32 = -1;
    else d->h32 = s->life;
    if (pos) {
        pos[4] = s->pos[0];
        pos[5] = s->pos[1];
        pos[6] = s->pos[2];
        pos[7] = s->pos[3];
    }
    d->alpha = 0.0f;
    switch (s->flip) {
    case 1:
        if (func_0020b410() > 0.5f) d->rot[0] = -d->rot[0];
        break;
    case 2:
        if (func_0020b410() > 0.5f) d->rot[1] = -d->rot[1];
        break;
    case 3:
        if (func_0020b410() > 0.5f) d->rot[0] = -d->rot[0];
        if (func_0020b410() > 0.5f) d->rot[1] = -d->rot[1];
        break;
    }
}
