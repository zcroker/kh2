#include "../common/types.h"
extern "C" {
struct W1829Ent { u8 pad[0x1c4]; void* m4; s32 a2; s32 a1; s32 a5; s32 a6; u8 m1[64]; u8 m2[64]; };
struct W1829R { s32 head; s32 tail; W1829Ent e[16]; };
struct W1829Q { u8 pad[12]; W1829R r; };
void func_00192c90(void*, void*);
void func_00192b30(void*);

/* 0031cc30: push an entry onto a 16-slot ring buffer (600-byte entries), copying one or two matrices. */
void func_0031cc30(W1829Q* q, s32 a1, s32 a2, void* a3, void* a4, s32 a5, s32 a6) {
    W1829R* r = &q->r;
    s32 h = r->head;
    s32 n = (h - r->tail + 16) % 16;
    if (n < 15) {
        r->head = (h + 1) % 16;
        W1829Ent* e = &r->e[h];
        func_00192c90(a3, e->m1);
        func_00192b30(a3);
        if (a4) {
            func_00192c90(a4, e->m2);
            func_00192b30(a4);
        }
        e->a2 = a2;
        e->m4 = a4;
        e->a1 = a1;
        e->a5 = a5;
        e->a6 = a6;
    }
}
}
