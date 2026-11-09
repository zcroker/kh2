// 00238c90: sprite draw into a GIF packet. Builds -O2 -fno-strict-aliasing (_nsa).
// The prologue statement order places the ox*16 spill store before the packet constructor stores.
// GIF tag word 0 is a chain of separate u64 values (nreg, prim, pre): with bitfields the PRIM and REGS10 constants swap registers.
#include "../common/types.h"

extern "C" {

// Sprite cell: texture rectangle and four corner colors.
struct W1700Cell {
    s32 id;      // 0x00
    s32 u0;      // 0x04
    s32 v0;      // 0x08
    s32 u1;      // 0x0c
    s32 v1;      // 0x10
    u8 pad14[8]; // 0x14
    u32 col[4];  // 0x1c
};

// Screen rectangle of one sprite piece.
struct W1700Piece {
    s32 x0, y0, x1, y1; // 0x00
    s32 cell;           // 0x10
};

struct W1700Sprite {
    u8 pad0[4];
    W1700Cell* cells;   // 0x04
    u8 pad8[8];
    u32 flags;          // 0x10
    W1700Piece* pieces; // 0x14
    s32 count;          // 0x18
    f32 m00, m01;       // 0x1c
    f32 m10, m11;       // 0x24
    f32 sx, sy;         // 0x2c
    u8 pad34[0x6c - 0x34];
    f32 alpha;          // 0x6c
    u8 pad70[0x88 - 0x70];
    s32 colorMode;      // 0x88
    s32 x;              // 0x8c
    s32 y;              // 0x90
    s32 ox;             // 0x94
    s32 oy;             // 0x98
    s32 z;              // 0x9c
    u16 u[4];           // 0xa0
    u16 v[4];           // 0xa8
};

// GS packed vertex: UV, A+D RGBAQ, XYZF2.
struct W1700Vtx {
    s32 u, v;   // 0x00
    u8 pad8[8];
    u64 rgba;   // 0x10
    u64 adreg;  // 0x18
    s32 x, y;   // 0x20
    s32 z;      // 0x28
    s32 adc;    // 0x2c
};

struct W1700GifTag {
    u64 nloop : 15; u64 eop : 1; u64 pad16 : 30; u64 pre : 1; u64 prim : 11; u64 flg : 2; u64 nreg : 4;
    u64 r0 : 4, r1 : 4, r2 : 4, r3 : 4, r4 : 4, r5 : 4, r6 : 4, r7 : 4;
    u64 r8 : 4, r9 : 4, r10 : 4, r11 : 4, r12 : 4, r13 : 4, r14 : 4, r15 : 4;
};

struct W1700Pkt {
    u8* base;
    u32 b;
    u32 c;
    W1700Pkt() { c = 0; b = 0; base = 0; }
};

void func_001b7e68(W1700Pkt*, s32);
void* func_001b7ff8(W1700Pkt*, s32);
void func_001b80d8(W1700Pkt*);
void func_001b7f30(W1700Pkt*);
u32 func_00233708(u32, s32);
u32 func_002338a8(f32, u32);

void func_00238c90(W1700Sprite* s, s32 x, s32 y, s32 ox, s32 oy) {
    s32 sox, soy, bx, by;
    s->x = x;
    s->y = y;
    s->oy = oy;
    bx = x * 16 + 0x7000;
    by = y * 16 + 0x7300;
    s->ox = ox;
    sox = ox * 16;
    W1700Pkt pkt;
    soy = oy * 16;
    func_001b7e68(&pkt, s->count * 12 + 1);
    W1700GifTag* tag = (W1700GifTag*)(pkt.base + 0x10);
    W1700Vtx* q = (W1700Vtx*)(pkt.base + 0x20);
    W1700Piece* pc = s->pieces;
    s32 n = s->count;
    s32 i;
    for (i = n; i > 0; i--, pc++, q += 4) {
        q[0].adreg = 1;
        q[0].z = s->z;
        q[0].adc = 0x8000;
        q[1].adreg = 1;
        q[1].z = s->z;
        q[1].adc = 0x8000;
        q[2].adreg = 1;
        q[2].z = s->z;
        q[2].adc = 0;
        q[3].adreg = 1;
        q[3].z = s->z;
        q[3].adc = 0;
        W1700Cell* c = &s->cells[pc->cell];
        if (!(s->flags & 0x40)) {
            q[0].u = q[2].u = c->u0 * 16 + 8;
            q[0].v = q[1].v = c->v0 * 16 + 8;
            q[1].u = q[3].u = c->u1 * 16 + 8;
            q[2].v = q[3].v = c->v1 * 16 + 8;
        } else {
            q[0].u = s->u[0] * 16 + 8;
            q[0].v = s->v[0] * 16 + 8;
            q[1].u = s->u[1] * 16 + 8;
            q[1].v = s->v[1] * 16 + 8;
            q[2].u = s->u[2] * 16 + 8;
            q[2].v = s->v[2] * 16 + 8;
            q[3].u = s->u[3] * 16 + 8;
            q[3].v = s->v[3] * 16 + 8;
        }
        f32 x0 = pc->x0 * 16 + sox;
        f32 y0 = pc->y0 * 16 + soy;
        f32 x1 = pc->x1 * 16 + sox;
        f32 y1 = pc->y1 * 16 + soy;
        if (((s->flags >> 4) & 1) == 0) {
            x0 *= s->sx;
            y0 *= s->sy;
            x1 *= s->sx;
            y1 *= s->sy;
        }
        if (((s->flags >> 3) & 1) == 0) {
            f32 m00 = s->m00, m10 = s->m10, m01 = s->m01, m11 = s->m11;
            q[0].x = bx + (s32)(x0 * m00 + y0 * m10);
            q[0].y = by + (s32)(x0 * m01 + y0 * m11);
            q[1].x = bx + (s32)(x1 * m00 + y0 * m10);
            q[1].y = by + (s32)(x1 * m01 + y0 * m11);
            q[2].x = bx + (s32)(x0 * m00 + y1 * m10);
            q[2].y = by + (s32)(x0 * m01 + y1 * m11);
            q[3].x = bx + (s32)(x1 * m00 + y1 * m10);
            q[3].y = by + (s32)(x1 * m01 + y1 * m11);
        } else {
            q[0].x = q[2].x = bx + (s32)x0;
            q[0].y = q[1].y = by + (s32)y0;
            q[1].x = q[3].x = bx + (s32)x1;
            q[2].y = q[3].y = by + (s32)y1;
        }
        if (((s->flags >> 5) & 1) == 0) {
            if (s->alpha == 1.0f) {
                q[0].rgba = func_00233708(c->col[0], s->colorMode);
                q[1].rgba = func_00233708(c->col[1], s->colorMode);
                q[2].rgba = func_00233708(c->col[2], s->colorMode);
                q[3].rgba = func_00233708(c->col[3], s->colorMode);
            } else {
                q[0].rgba = func_002338a8(s->alpha, func_00233708(c->col[0], s->colorMode));
                q[1].rgba = func_002338a8(s->alpha, func_00233708(c->col[1], s->colorMode));
                q[2].rgba = func_002338a8(s->alpha, func_00233708(c->col[2], s->colorMode));
                q[3].rgba = func_002338a8(s->alpha, func_00233708(c->col[3], s->colorMode));
            }
        } else {
            q[0].rgba = c->col[0];
            q[1].rgba = c->col[1];
            q[2].rgba = c->col[2];
            q[3].rgba = c->col[3];
        }
    }
    u64 g0 = (u32)(s->count | 0x8000);
    u64 g1 = g0 | (12ULL << 60);
    u64 g2 = g1 | (0x15cULL << 47);
    u64 g3 = g2 | (1ULL << 46);
    *(u64*)tag = g3;
    ((u64*)tag)[1] = 0;
    tag->r0 = 3; tag->r1 = 0xe; tag->r2 = 4; tag->r3 = 3; tag->r4 = 0xe; tag->r5 = 4;
    tag->r6 = 3; tag->r7 = 0xe; tag->r8 = 4; tag->r9 = 3; tag->r10 = 0xe; tag->r11 = 4;
    func_001b7ff8(&pkt, s->count * 12 + 1);
    func_001b80d8(&pkt);
    func_001b7f30(&pkt);
}

}
