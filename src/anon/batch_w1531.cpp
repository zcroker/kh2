#include "../common/types.h"

struct W1531_TT { u8 pad[0x28]; W1531_TT* next; };
struct W1531_TL { W1531_TT* head; s32 count; };
struct W1531_Tab { s32 x; s32 count; s32 tab[1]; };
struct W1531_Ob { u8 pad[0x7f8]; s32 flags; };
struct W1531_E32 { u8 b[32]; };
struct W1531_Lst { s32 n; W1531_Ob* o; s32 k; s32 pad; W1531_E32 arr[1]; };

extern "C" {
extern W1531_TL D_004f6290;
void func_0016cab8(W1531_TT*);
void func_0016c7d8(W1531_TT*);

void ttarget0_0016d110(void) asm("_Z17ttarget0_0016d110v");
void ttarget0_0016d110(void) {
    W1531_TT* nx;
    W1531_TT* cur = D_004f6290.head;
    W1531_TT* it = cur;
    if (cur) {
        do {
            if (!it) nx = D_004f6290.head; else nx = it->next;
            it = nx;
            if (cur) { func_0016cab8(cur); func_0016c7d8(cur); }
            cur = nx;
        } while (nx);
    }
    D_004f6290.head = 0;
    D_004f6290.count = 0;
}

extern W1531_Tab* D_01d48cb4;
s32 func_001b7818(void*);
u8* func_001b6fb0(void* self, s32 a) {
    s32 n = func_001b7818(self);
    if (n == 0) n = 1;
    W1531_Tab* d = *(W1531_Tab* volatile*)&D_01d48cb4;
    if (n >= d->count || d->tab[n] == 0) n = 1;
    W1531_Tab* e = D_01d48cb4;
    s32* v = (s32*)e + e->tab[n];
    s32 m = *v;
    if (m < a) a = m;
    return (u8*)v + a * 16 - 12;
}

s32 func_0016bba8(W1531_Ob*, s32, s32);
void func_0018a818(W1531_E32*, W1531_Ob*, s32);
void func_001b78d0(W1531_Lst* l) {
    l->n = 0;
    s32 v = 0;
    if (l->o->flags & 0x400) {
        while ((v = func_0016bba8(l->o, l->k, v)) != 0) {
            func_0018a818(&l->arr[l->n], l->o, v);
            l->n++;
        }
    }
}
}
