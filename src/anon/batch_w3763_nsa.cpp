#include "../common/types.h"
struct Prm { u16 a0; u16 flags; u8 c[4]; u64 z8; void* p10; s32 v14; u8 b18; u8 pad19[3]; void* p1c; u8 pad20[0x10]; };
struct Ent { s32 a; s32 b; };
struct Tbl { u8 pad[0x14]; Ent* ents; };
struct Rec { u8 pad[0x10]; s16 off; };
struct Node { u8 pad[4]; u16 idx; u8 pad6[2]; u8 c[4]; };
struct Arg1 { u8 pad[4]; s32 id; u8 pad8[4]; u8 bc, bd, be, bf, b10; };
struct Arg2 { u8 pad[0xc]; s32* offs; };
extern Tbl* D_01d9e6e4;
extern u8* D_01d9e6e8;
extern s32 D_01d9eaa4;
extern "C" s32 func_0021d048(u8*, Prm*, s32);
extern "C" {
void func_001fe798(u8* base, Arg1* a, Arg2* b) {
    s32* offs = b->offs;
    s32 id = a->id;
    Node* n0 = (Node*)(base + offs[0] + 0xa0);
    Node* n1 = (Node*)(base + offs[1] + 0xa0);
    if (id == 0xffff) return;
    Ent* e = &D_01d9e6e4->ents[id];
    Prm p;
    if (!a->bf) p.flags = 0x80; else p.flags = 0;
    if (a->b10 == 1) p.flags |= 0x10;
    if (a->bc) p.flags |= 0x800;
    if (a->bd) p.flags |= 0x400;
    if (a->be) p.p1c = base + offs[3] + 0xa0; else p.p1c = 0;
    p.p10 = D_01d9e6e8 + 0x50;
    p.c[0] = n1->c[0];
    p.c[1] = n1->c[1];
    p.c[2] = n1->c[2];
    p.c[3] = n1->c[3];
    p.z8 = 0;
    p.b18 = 0;
    u8* d = (u8*)e->a;
    u32 kk = n0->idx * 8;
    Rec* q = (Rec*)(d + kk);
    s32 of = q->off;
    p.v14 = D_01d9eaa4;
    s32 eb = e->b;
    u8* aa = d + of;
    D_01d9eaa4 = func_0021d048(aa, &p, eb);
}
}
