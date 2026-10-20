#include "../common/types.h"
// Built with -fno-strict-aliasing (_nsa): 001fb478 and 002e9850 reload a global after stores of other types.

struct W1761S1 { u8 pad[0x8c]; u8 b8c; u8 b8d; u8 p2[0x9c - 0x8e]; s32 w9c; u8 p3[8]; s32 wa8; u8 p4[0xc0 - 0xac]; u8 bc0; u8 bc1; };
struct W1761Ev { s32 type; s32 id; s32 a[6]; };
struct W1761Ent64 { u8 d[64]; };
struct W1761Pool30 { W1761Ent64 e[30]; s32 idx[30]; s32 n; };

extern "C" {
void func_0021f5d8(void*);
extern u8 D_003590b0;

void func_001fb478(char* a0, s32** a1) {
    W1761S1* p = (W1761S1*)(a0 + *a1[3] + 0xa0);
    func_0021f5d8(p);
    p->w9c = 0;
    p->wa8 = 0;
    p->b8c = D_003590b0;
    p->b8d = 2;
    p->bc0 = 0;
    p->bc1 = 0;
    D_003590b0++;
}

extern s32 D_0035e360;
extern s32 D_0035e368;
extern W1761Ev D_01dadc00[64];

s32 func_00234188(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5) {
    W1761Ev* e = &D_01dadc00[D_0035e360];
    s32 id = D_0035e368;
    e->type = 3;
    e->id = id;
    e->a[0] = p0;
    e->a[1] = p1;
    e->a[2] = p2;
    e->a[3] = p3;
    e->a[4] = p4;
    e->a[5] = p5;
    D_0035e360 = (D_0035e360 + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}

extern W1761Pool30* D_01e2bfa0;
extern s32 D_01e2bfa4;
void func_002e93a0(W1761Ent64*);

static inline W1761Ent64* w1761_pop(W1761Pool30* p) {
    p->n--;
    return &p->e[p->idx[p->n]];
}

W1761Ent64* func_002e9850(void) {
    W1761Ent64* r;
    D_01e2bfa4++;
    r = w1761_pop(D_01e2bfa0);
    func_002e93a0(r);
    return r;
}
}
