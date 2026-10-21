#include "../common/types.h"
extern "C" {
struct E24 { u8 pad[0x14]; s32 base; u8 p2[0x24-0x18]; };
struct G8 { s16 a; s16 n; u16* list; };
struct DA { u8 pad[0x10]; E24* e; u8 p1[4]; G8* g; };
struct DB { u8 pad[0x90]; s32 base; };
extern DA* D_01d9e6e4;
extern DB* D_01d9e6e8;
s32 func_00222568();
typedef void (*CB)(s32, s32, s32);

void func_0021ee48(s32 a0, s32 a1, CB cb, u16* pidx, s16 gi, u8 rnd, u8 cnt) {
    G8* g = &D_01d9e6e4->g[gi];
    s32 base = D_01d9e6e8->base;
    s32 i;
    if (base == 0) base = D_01d9e6e4->e[g->a].base;
    if (rnd) i = func_00222568() % g->n;
    else i = *pidx;
    while (cnt != 0) {
        cb(a0, a1, base + g->list[i++] * 6);
        if (rnd) i = func_00222568() % g->n;
        else if (i >= g->n) i = 0;
        cnt--;
    }
    *pidx = i;
}
}
