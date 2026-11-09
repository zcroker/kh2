/* func_001e8330: per-entry node update loop (calls a per-slot handler and records timing from 0x10000000).
 * Register pins and empty asm statements reproduce the original allocation (zl90 w3891, carried by w3901). */
#include "../common/types.h"
typedef struct Node_e Node_e;
struct Node_e { Node_e* next; u8 pad4[8]; s32 val; u8 pad10[0x9c - 0x10]; u8 b9c; u8 b9d; u8 b9e; };
typedef struct Hnd_e Hnd_e;
struct Hnd_e { u8 pad0[4]; void (*fn)(Node_e*, s32*, void*); u8 pad8[4]; s32 off; u8 pad10[0x28 - 0x10]; s32 start; s32 sum; s32 max; };
typedef struct Slot_e Slot_e;
struct Slot_e { Hnd_e* h; u16 add; u8 pad[10]; };
typedef struct Grp_e Grp_e;
struct Grp_e { u8 pad0[0x20]; s32 off; u8 pad24[2]; s16 nslots; Slot_e slot[1]; };
typedef struct Ent_e Ent_e;
struct Ent_e { Grp_e* g; Node_e* first; u8 pad8[4]; u16 n; u8 pade[2]; };
typedef struct Self_e Self_e;
struct Self_e { u8 pad0[0x68]; s32 count; u8 pad6c[0x80 - 0x6c]; Ent_e* ents; };
typedef struct Dev_e Dev_e;
struct Dev_e { u8 pad[0xa8]; u64 flags; };
extern Dev_e* D_01d9e6e0;
extern Node_e* D_01d9e6e8;
extern s32 D_01d9ea9c;
void func_001e7948(Node_e*);
void func_001e8330(Self_e* self)
{
    s32 i;
    for (i = 0; i < self->count; i++) {
        Ent_e* e = &self->ents[i];
        Grp_e* g = e->g;
        s32 j;
        if (e->n == 0)
            continue;
        for (j = 0; j < g->nslots; j++) {
            Slot_e* sl = &g->slot[j];
            register Hnd_e* h asm("$19") = sl->h;
            Node_e* nd = e->first;
            void (*fn)(Node_e*, s32*, void*) = h->fn;
            s32 off = h->off;
            register s32 k asm("$20");
            if (fn == 0 || off != 0)
                continue;
            k = e->n;
            do {
                Node_e* next = nd->next;
                s32** pp0 = (s32**)((u8*)nd + g->off + j * 4);
                if (!nd->b9c) {
                    s32** pp = pp0;
                    register s32* p asm("$18") = *pp;
                    register s32* q asm("$22") = (s32*)((u8*)p + sl->add);
                    register s32* t asm("$16");
                    D_01d9e6e8 = nd;
                    if (D_01d9ea9c == 0 && !(D_01d9e6e0->flags & 0xff0000ff00ULL) && nd->b9e) {
                        nd->val = 0;
                        nd->b9d = 1;
                        func_001e7948(nd);
                        nd->b9e = 0;
                    }
                    if (*q == nd->val) {
                        *pp = q;
                        p = q;
                    }
                    t = &h->start;
                    h->start = *(volatile s32*)0x10000000;
                    fn(nd, p, sl);
                    t[1] += *(volatile s32*)0x10000000 - h->start;
                    if (t[2] < t[1])
                        t[2] = t[1];
                }
                nd = next;
            } while (--k);
            {
            register s32 ph asm("$21");
            asm volatile("" : "=r"(ph));
            asm("" :: "r"(fn), "r"(ph));
            }
        }
    }
}






