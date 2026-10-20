#include "../common/types.h"

struct C34e0 { u8 v:8; };
typedef struct E34e0 { u8 b0, b1, b2, b3; u8 pad[0xe]; u16 h12; } E34e0;
extern u8 D_0032e020[];

extern "C" {
E34e0* func_001a80c8(s32);

/* The mask goes through a variable so gcc keeps the test in SImode (no extra andi 0xff). */
void func_001a34e0(s32 a0, s32 a1) {
    E34e0* e = func_001a80c8(a0);
    u8* base = D_0032e020;
    u32* bits = (u32*)(base + 0x11d0);
    s32 m = 1;
    if (e->b3 & m) {
        u32 i = e->h12;
        bits[i >> 5] &= ~(1 << (i & 31));
    } else {
        C34e0* c = (C34e0*)(base + e->h12 + 0x1090);
        if (a1 < c->v) c->v -= a1; else c->v = 0;
    }
}
}
