#include "../common/types.h"

/* GS packet qword, written as two dwords or four words. */
typedef union Pk598 { u64 d[2]; u32 w[4]; } Pk598;
typedef struct Ctx598 { u32 a; u32 b; union { Pk598* p; u64 q; }; } Ctx598;
extern volatile u64 D_0036d770; /* GIF tag for the sprite packet */
s32 func_001aaf98(u32, s32, s32, s32, s32);

/* Sprite for cell idx (10 per row, 24x24) of a texture page at (x, y). Returns 1 if a packet was written. */
s32 func_001ab598(u32 a0, Ctx598* c, s32 x, s32 y, u32 col, s32 idx) {
    s32 r;
    u32 cc;
    if (func_001aaf98(a0, x, y, 384, 384) != 0) {
        r = 0;
    } else {
        Pk598* volatile* pp = (Pk598* volatile*)&c->p;
        r = 1;
        y += 64;
        cc = col >> 24;
        s32 u = (idx % 10 * 24) << 4;
        s32 v = (idx / 10 * 24) << 4;
        (*pp)->d[0] = D_0036d770;
        (*pp)->d[1] = 6;
        c->p++;
        *(u32*)c->p = 128;
        (*pp)->w[1] = 128;
        c->p->w[2] = 128;
        c->p->w[3] = cc;
        c->p++;
        c->p->w[0] = u + 8;
        c->p->w[1] = v + 8;
        c->p->w[2] = 0;
        c->p->w[3] = 0;
        c->p++;
        c->p->w[0] = x;
        c->p->w[1] = y - 384;
        c->p->w[2] = 0;
        c->p->w[3] = 0x8000;
        c->p++;
        c->p->w[0] = u + 392;
        c->p->w[1] = v + 392;
        c->p->w[2] = 0;
        c->p->w[3] = 0;
        c->p++;
        c->p->w[0] = x + 384;
        c->p->w[1] = y;
        c->p->w[2] = 0;
        c->p->w[3] = 0;
        c->p++;
    }
    return r;
}
