#include "../common/types.h"

/* YI::SEQUENCE key (0x90 bytes): each pair is {value at start, value at end} */
struct W1702Key {
    u32 flags;          /* 0x00 */
    s32 pad04;          /* 0x04 */
    s32 start;          /* 0x08 */
    s32 end;            /* 0x0c */
    s32 x[2];           /* 0x10 */
    s32 y[2];           /* 0x18 */
    s32 w[2];           /* 0x20 */
    s32 h[2];           /* 0x28 */
    f32 rx[2];          /* 0x30 */
    f32 ry[2];          /* 0x38 */
    f32 rz[2];          /* 0x40 */
    f32 scale[2];       /* 0x48 */
    f32 sx[2];          /* 0x50 */
    f32 sy[2];          /* 0x58 */
    f32 ease[4];        /* 0x60 */
    f32 ampX[2];        /* 0x70 */
    f32 ampY[2];        /* 0x78 */
    u16 freqX;          /* 0x80 */
    u16 freqY;          /* 0x82 */
    u32 pad84;          /* 0x84 */
    u8 col[2][4];       /* 0x88 */
};

/* YI::SEQUENCE (fields used by the key evaluator) */
struct W1702Seq {
    u8 pad00[0xb8];
    u32 mode;           /* 0xb8 */
    u8 padbc[8];
    W1702Key* keys;     /* 0xc4 */
    s32 numKeys;        /* 0xc8 */
    f32 time;           /* 0xcc */
    u32 padd0;
    u8 active;          /* 0xd4 */
    f32 scaleX;         /* 0xd8 */
    f32 scaleY;         /* 0xdc */
    u32 rgba;           /* 0xe0 */
    s32 posX;           /* 0xe4 */
    s32 posY;           /* 0xe8 */
    u8 padec[0x118 - 0xec];
    f32 colScale[4];    /* 0x118 */
    f32 rot[3];         /* 0x128 */
    f32 scale;          /* 0x134 */
    f32 sx;             /* 0x138 */
    f32 sy;             /* 0x13c */
};

extern "C" {
/* the game's own __fixunssfsi (float to u32); const like the libcall */
u32 func_00313bc0(f32) __attribute__((const));
f32 func_002f8960(f32); /* sinf */
f32 func_002f87c0(f32); /* cosf */

/* Finds the active key at seq->time and evaluates color, scale and position. */

void func_0023a0d8(W1702Seq* seq) {
    seq->active = 1;
    s32 n = seq->numKeys;
    W1702Key* k = seq->keys;
    for (; n > 0; n--, k++) {
        if ((k->flags & 2) == 0) continue;
        /* frame range of the key; the array stays on the stack */
        f32 range[2];
        f32 time = seq->time;
        range[0] = (f32)k->start;
        if (!(range[0] <= time)) continue;
        range[1] = (f32)k->end;
        if (!(time <= range[1])) continue;

        f32 len = range[1] - range[0];
        f32 t;
        if (len == 0.0f) t = 1.0f;
        else t = (time - range[0]) / len;

        u32 flags = k->flags;
        /* ease: cubic Bezier with control points 1, 1 - ease[1], 1 - ease[3], 0 */
        if ((flags & 1) == 0) {
            f32 u = 1.0f - t;
            f32 uu = u * u;
            f32 tt = t * t;
            t = 1.0f - (uu * u + uu * 3.0f * t * (1.0f - k->ease[1]) + u * 3.0f * tt * (1.0f - k->ease[3]) + tt * t * 0.0f);
        }

        u32 mode = seq->mode;
        if (mode & 4) {
            u32 c;
            if ((flags & 0x80) == 0) {
                c = func_00313bc0((k->col[0][0] + (s32)((k->col[1][0] - k->col[0][0]) * t)) * seq->colScale[0])
                  | (func_00313bc0((k->col[0][1] + (s32)((k->col[1][1] - k->col[0][1]) * t)) * seq->colScale[1]) << 8)
                  | (func_00313bc0((k->col[0][2] + (s32)((k->col[1][2] - k->col[0][2]) * t)) * seq->colScale[2]) << 16)
                  | (func_00313bc0((k->col[0][3] + (s32)((k->col[1][3] - k->col[0][3]) * t)) * seq->colScale[3]) << 24);
            } else {
                c = func_00313bc0(k->col[0][0] * seq->colScale[0]) | (func_00313bc0(k->col[0][1] * seq->colScale[1]) << 8)
                  | (func_00313bc0(k->col[0][2] * seq->colScale[2]) << 16) | (func_00313bc0(k->col[0][3] * seq->colScale[3]) << 24);
            }
            seq->rgba = c;
        } else if ((flags & 0x80) == 0) {
            seq->rgba = (k->col[0][0] + (s32)((k->col[1][0] - k->col[0][0]) * t))
                      | ((k->col[0][1] + (s32)((k->col[1][1] - k->col[0][1]) * t)) << 8)
                      | ((k->col[0][2] + (s32)((k->col[1][2] - k->col[0][2]) * t)) << 16)
                      | ((k->col[0][3] + (s32)((k->col[1][3] - k->col[0][3]) * t)) << 24);
        } else {
            seq->rgba = *(u32*)k->col[0];
        }

        if (mode & 2) {
            if ((k->flags & 0x40) == 0) {
                f32 s = seq->scale * (k->scale[0] + (k->scale[1] - k->scale[0]) * t);
                seq->scaleX = s * seq->sx * (k->sx[0] + (k->sx[1] - k->sx[0]) * t);
                seq->scaleY = s * seq->sy * (k->sy[0] + (k->sy[1] - k->sy[0]) * t);
            } else {
                seq->scaleX = seq->scale * seq->sx;
                seq->scaleY = seq->scale * seq->sy;
            }
        } else if ((k->flags & 0x40) == 0) {
            seq->scaleX = k->sx[0] + (k->sx[1] - k->sx[0]) * t;
            seq->scaleY = k->sy[0] + (k->sy[1] - k->sy[0]) * t;
        } else {
            seq->scaleX = 1.0f;
            seq->scaleY = 1.0f;
        }

        s32 x = k->x[0] + (s32)((k->x[1] - k->x[0]) * t);
        s32 y = k->y[0] + (s32)((k->y[1] - k->y[0]) * t);
        if ((k->flags & 0x10) == 0) {
            f32 ax = k->ampX[0] + (k->ampX[1] - k->ampX[0]) * t;
            f32 ay = k->ampY[0] + (k->ampY[1] - k->ampY[0]) * t;
            if ((k->flags & 8) == 0) {
                f32 a = t * 3.1415927f;
                x += (s32)(ax * func_002f8960(a * k->freqX));
                y += (s32)(ay * func_002f8960(a * k->freqY));
            } else {
                f32 a = t * 3.1415927f;
                x += (s32)(ax * func_002f87c0(a * k->freqX));
                y += (s32)(ay * func_002f87c0(a * k->freqY));
            }
        }

        f32 ox = (k->w[0] + (s32)((k->w[1] - k->w[0]) * t)) * seq->scaleX;
        f32 oy = (k->h[0] + (s32)((k->h[1] - k->h[0]) * t)) * seq->scaleY;
        f32 rx, ry, rz;
        /* the original tests this bit without a bool conversion */
        if ((seq->mode & 1) == 1) {
            if ((k->flags & 0x20) == 0) {
                f32 x0 = k->rx[0], y0 = k->ry[0], z0 = k->rz[0];
                rx = x0 + (k->rx[1] - x0) * t + seq->rot[0];
                ry = y0 + (k->ry[1] - y0) * t + seq->rot[1];
                rz = z0 + (k->rz[1] - z0) * t + seq->rot[2];
            } else {
                rx = seq->rot[0];
                ry = seq->rot[1];
                rz = seq->rot[2];
            }
        } else if ((k->flags & 0x20) == 0) {
            f32 x0 = k->rx[0], y0 = k->ry[0], z0 = k->rz[0];
            rx = x0 + (k->rx[1] - x0) * t;
            ry = y0 + (k->ry[1] - y0) * t;
            rz = z0 + (k->rz[1] - z0) * t;
        } else {
            seq->posX = x + (s32)ox;
            seq->posY = y + (s32)oy;
            return;
        }
        f32 sa = func_002f8960(rx);
        f32 ca = func_002f87c0(rx);
        f32 sb = func_002f8960(ry);
        f32 cb = func_002f87c0(ry);
        f32 sc = func_002f8960(rz);
        f32 cc = func_002f87c0(rz);
        f32 sasb = sa * sb;
        f32 nsc = -sc;
        f32 m00 = cb * cc;
        f32 m01 = sasb * cc + ca * sc;
        f32 m10 = cb * nsc;
        f32 m11 = sasb * nsc + ca * cc;
        seq->posX = x + (s32)(ox * m00 + oy * m01);
        seq->posY = y + (s32)(ox * m10 + oy * m11);
        return;
    }
}
}
