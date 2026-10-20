#include "../common/types.h"

struct W1765Ent { s32 a, b; f32 f; };
extern s32 D_00351600;
extern W1765Ent D_01d49658[];

struct W1765Mx {
    u8 d[64];
    // 64-byte block copy through four 128-bit registers (lq/sq), as in the original.
    W1765Mx& operator=(const W1765Mx& o) {
        if (this != &o)
            asm volatile("lq $8,0(%1)\n\tlq $9,16(%1)\n\tlq $10,32(%1)\n\tlq $11,48(%1)\n\t"
                         "sq $8,0(%0)\n\tsq $9,16(%0)\n\tsq $10,32(%0)\n\tsq $11,48(%0)"
                         :: "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1765Nd { u8 pad[0x40]; W1765Mx src; W1765Mx dst; u8 pad2[0x110 - 0xc0]; W1765Nd* next; };
struct W1765Slot { u8 pad[0x2c]; W1765Nd* head; };
struct W1765Mg { u8 p0[4]; W1765Slot* ents; u8 p8[8]; s32 n; u8 pad[0x5360 - 0x14]; s32 f5360; };

extern "C" {
void func_001c4200(void*, s32);

void func_001c4188(void* p, f32 x) {
    s32 i;
    for (i = 0; i < D_00351600; i++) {
        if (D_01d49658[i].f < x) { func_001c4200(p, i); return; }
    }
    if (D_00351600 == 0) func_001c4200(p, 0);
}

void func_00146d68(W1765Mg* m) {
    m->f5360 = 0;
    W1765Slot* e = m->ents;
    s32 n = m->n;
    for (s32 i = 0; i < n; i++) {
        for (W1765Nd* d = e[i].head; d; d = d->next) d->dst = d->src;
        e[i].head = 0;
    }
}
}
