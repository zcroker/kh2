#include "../common/types.h"
typedef unsigned int W1820u128 __attribute__((mode(TI)));

// Object with a 16-qword GS register packet at +0x20 (two GIF tags + A+D pairs).
struct W1820Gs {
    u8 pad[4];
    u16 w, h;
    s16 x, y;
    u32 z;
    u8 b0, b1, b2, b3;
    u8 pad2[12];
    u64 g[22];
    u64 g2[2];
};

// DMA packet builder: 3 words, write cursor at +8.
struct W1820Pkt {
    u32 a, b;
    W1820u128* p;
    W1820Pkt() { p = 0; b = 0; a = 0; }
};

extern "C" {
void func_0013eb00(W1820Gs*);
void func_001b7e68(W1820Pkt*, s32);
void func_001b80d8(W1820Pkt*);
void func_001b7f30(W1820Pkt*);

void func_0013e940(W1820Gs* p)
{
    p->g[0] = 0x8000000000000001ULL;
    p->g[1] = 0xEEEEEEEEULL;
    p->g[2] = 0;
    p->g[3] = 0x3f;
    p->g[4] = 0x800d8;
    p->g[5] = 0x4c;
    p->g[6] = 0x31000070;
    p->g[7] = 0x4e;
    p->g[8] = 0;
    p->g[9] = 6;
    p->g[10] = 0x60;
    p->g[11] = 0x14;
    p->g[12] = 0x30000;
    p->g[13] = 0x47;
    p->g[14] = 0x44;
    p->g[15] = 0x42;
    p->g[16] = 5;
    p->g[17] = 8;
    p->g[18] = 0xA400000000008001ULL;
    p->g[19] = 0x5353535310ULL;
    p->g[20] = 0x144;
    p->g[21] = (u64)p->b0 | ((u64)p->b1 << 8) | ((u64)p->b2 << 16) | ((u64)p->b3 << 24) | (1ULL << 32);
    func_0013eb00(p);
}

void func_0014b698(W1820Gs* p)
{
    p->g[21] = (u64)p->b0 | ((u64)p->b1 << 8) | ((u64)p->b2 << 16) | ((u64)p->b3 << 24) | (1ULL << 32);
    ((u64*)p)[27] = (s32)((p->x << 4) + 0x7000) | ((u64)(s32)((p->y << 4) + 0x7300) << 16) | ((u64)p->z << 32);
    ((u64*)p)[29] = (s32)(((p->x + p->w) << 4) + 0x7000) | ((u64)(s32)(((p->y + p->h) << 4) + 0x7300) << 16) | ((u64)p->z << 32);
    W1820Pkt pkt;
    func_001b7e68(&pkt, 0xd0);
    W1820Pkt* pp = &pkt;
    W1820u128* s = (W1820u128*)p->g;
    for (s32 i = 12; i >= 0; i--) { *pp->p = *s; s++; pp->p++; }
    func_001b80d8(&pkt);
    func_001b7f30(&pkt);
}
}
