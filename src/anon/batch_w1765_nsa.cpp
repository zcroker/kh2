#include "../common/types.h"

struct W1765E0 { u8 pad[0x10]; s16 h; };
struct W1765Hd { u8* base; };
struct W1765S3 { W1765Hd* a; u8* b; u8 pad8[8]; u8 p10[2]; u16 f12; u8 p14[4]; s32 f18; s16 f1c; u8 p1e[6]; s32 f24; u8 f28; };
extern s32 D_01d9eaa4;

extern "C" {
s32 func_0021d048(u8*, void*, s32);

void func_0021f060(W1765S3* p) {
    W1765Hd* a = p->a;
    W1765E0* e = (W1765E0*)(a->base + p->b[2] * 8);
    p->f18 = 0;
    p->f28 = 0;
    p->f24 = D_01d9eaa4;
    p->f1c = 0x12;
    p->f12 |= 0x30;
    D_01d9eaa4 = func_0021d048(a->base + e->h, &p->p10, 0);
}
}
