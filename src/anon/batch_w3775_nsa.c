// Built with -fno-strict-aliasing (_nsa).
// 001e8048: set up an object from a data header (cursor reads, entry table from a linked list).
// Partial asm: an empty tie on the header cursor p keeps it live with an addiu after each read; e pinned to t3.
#include "../common/types.h"
typedef struct Node Node; struct Node { Node* next; u32 pad[3]; s32 v10; };
typedef struct Ent Ent; struct Ent { Node* n; s32 w4; s32 v8; u16 h12; u8 b14; u8 pad; };
typedef struct Obj Obj; struct Obj {
    u8 pad0[0x54]; s32 w54; s32 w58;
    u8 pad1[0x64 - 0x5c]; s32 w64; s32 n68; s32 pad6c; Node* list70; s32 w74; s32* p78; s32* p7c; Ent* ents;
    u8 b84; u8 b85;
    u8 pad2[0x98 - 0x86]; s32 w98;
};
extern Obj* D_01d9e6e0;
extern s32 D_01d9e6e4;
Ent* func_001e7698(s32, s32);
void func_001e7810(Obj*);

void func_001e8048(Obj* o, s32* d, s32 go) {
    s32* p = d + 1;
    asm("" : "+r"(p));
    D_01d9e6e0 = o;
    o->w54 = d[0];
    s32 fl = *p++;
    s32* a = (s32*)((u8*)d + *p++);
    s32* b = (s32*)((u8*)d + *p++);
    if (fl & 1) o->b84 = 1; else o->b84 = 0;
    o->w64 = *a++;
    o->p78 = a;
    o->n68 = *b++;
    o->p7c = b;
    if (o->n68) o->ents = func_001e7698(D_01d9e6e4, o->n68 << 4);
    else o->ents = 0;
    Node* n = (Node*)p;
    if (n->next) o->list70 = 0;
    o->list70 = o->n68 ? n : 0;
    o->w58 = 0;
    o->b85 = 0;
    o->w74 = 0;
    register Ent* e asm("$11") = o->ents;
    u8 i = 0;
    for (; n; n = n->next) {
        e->n = n;
        e->v8 = n->v10;
        e->b14 = i++;
        e->w4 = 0;
        e->h12 = 0;
        e++;
    }
    if (go) func_001e7810(o);
    o->w98 = 0;
}




