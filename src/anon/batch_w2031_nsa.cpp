#include "../common/types.h"

extern "C" {

s32 get_part_num_0016a070(s32) asm("_ZN2YS3OBJ12get_part_numEv");
s32 func_001a3888(s32);

struct W2031_PE { s32 a; s32 b; s32 c; s32 d; s32 e; W2031_PE* next; };
struct W2031_Pool { W2031_PE e[4]; s32 fr[4]; s32 n; };
struct W2031_PL { W2031_PE* head; W2031_PE* tail; };
extern W2031_Pool D_01c620c8;
extern W2031_PL D_01c62140;

struct W2031_N { f32 t; s32 b; s32 a; s32 r; s32 c; W2031_N* next; };
struct W2031_NL { W2031_N* head; W2031_N* tail; };
extern W2031_NL D_01d48de0;

struct W2031_V5 { s32 v[5]; };

void func_0010cae8(u8* a0, u8* a1) {
    *(u16*)(a0 + 0xc30) = 1;
    *(W2031_V5*)(a0 + 0xc38) = *(W2031_V5*)(a0 + 0x9f4);
    *(s32*)(a0 + 0xb78) = 0;
    *(u8**)(a0 + 0xc68) = a1;
    if (*(s32*)(a0 + 0x48c) != 0 && *(s32*)(a1 + 8) != 0) a0[0xc35] = a1[8];
    else a0[0xc35] = 0;
}

void func_001994d8(s32 a0, s32 a1, s32 a2) {
    W2031_Pool* P = &D_01c620c8; W2031_PL* L = &D_01c62140;
    s32 i = --P->n;
    W2031_PE* e = &P->e[P->fr[i]];
    e->a = 1; e->b = a1; e->c = a2; e->d = a0;
    if (L->head == 0) { L->tail = e; L->head = e; e->next = 0; }
    else { e->next = L->head; L->head = e; }
}

void func_001ba168(W2031_N* n, s32 a1, s32 a2, s32 a3) {
    n->b = a2; n->a = a1; n->t = 30.0f;
    n->r = get_part_num_0016a070(a1);
    n->c = func_001a3888(n->b) ? 0 : a3;
    if (D_01d48de0.tail == 0) { D_01d48de0.tail = n; D_01d48de0.head = n; n->next = 0; }
    else { D_01d48de0.tail->next = n; n->next = 0; D_01d48de0.tail = n; }
}

}
