#include "../common/types.h"
// Built with -fno-strict-aliasing (the *_nsa rule in the Makefile).

struct Ent_2bf468 { s32 id; u8 b4; u8 pad[3]; };
struct Sub_2bf468 { u8 a, b, c; };
struct Obj_2bf468 {
    void* vt;           // 0x000
    u8 p0[0x584];
    u32 flags;          // 0x588
    u8 p1[0xAE4 - 0x58C];
    Sub_2bf468 sub;     // 0xAE4
    u8 ae7;             // 0xAE7
    u8 p2[8];
    f32 af0;            // 0xAF0
    f32 af4;            // 0xAF4
    Ent_2bf468* ent;    // 0xAF8
    s32 afc, b00, b04, b08;
};
extern u8 D_003619c8[];
extern Ent_2bf468 D_00375420[];

struct Node_165898 { s32 a, b; u8 c[8]; };
struct Pool_165898 { Node_165898 n[64]; s32 idx[64]; s32 cnt; };
struct Pair_165898 { s32 a, b; };

extern "C" {
void func_002be770(Obj_2bf468*);
s32 func_001b6d70(u8);
void func_002bf650(Obj_2bf468*, s32);

void func_002bf468(Obj_2bf468* p, s32* key) {
    func_002be770(p);
    p->sub.a = 0;
    p->vt = D_003619c8;
    Sub_2bf468* s = &p->sub;
    s->b = 0; s->c = 0;
    p->ae7 = 0;
    p->af4 = p->af0 = 0.0f;
    p->flags |= 0x80000000;
    p->ent = 0;
    p->afc = 0;
    p->b00 = 0;
    p->b04 = 0;
    p->b08 = 0;
    for (u32 i = 0; i < 12; i++) {
        if (D_00375420[i].id == *key) { p->ent = &D_00375420[i]; break; }
    }
    func_002bf650(p, func_001b6d70(p->ent->b4));
}

void* tz_alloc_165898(u32, u32) asm("_ZN2Tz13LoadDataAllocEjj");
void lst_165898(void*) asm("_Z13func_0031a830Pv");
extern Pair_165898 D_004f41c0;
extern s32 D_0034c7a4;
extern Pool_165898* D_0034c7a0;

void func_00165898(u32 arg) {
    D_004f41c0.b = 0;
    D_0034c7a4 = arg;
    D_004f41c0.a = 0;
    Pool_165898* p = (Pool_165898*)tz_alloc_165898(sizeof(Pool_165898), arg);
    Node_165898* n = p->n;
    for (s32 i = 63; i != -1; i--) {
        n->a = 0; n->b = 0;
        lst_165898(n->c);
        lst_165898(n->c);
        n++;
    }
    for (s32 i = 0; i < 64; i++) p->idx[i] = i;
    p->cnt = 64;
    D_0034c7a0 = p;
}
}
