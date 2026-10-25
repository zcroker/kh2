#include "../common/types.h"

extern "C" {
void func_00141010(float);
void* func_00140df0(void);
void func_00140dc0(void);
extern u8 D_0034a9e8;
void func_00158f40(void) {
    func_00141010(30.0f);
    u8* p = (u8*)func_00140df0();
    func_00140dc0();
    *(s32*)(p + 0x40) = 6;
    D_0034a9e8 = 1;
}

struct LNode_w1671 { u8 pad[0x7c]; LNode_w1671* next; };
struct LList_w1671 { LNode_w1671* head; LNode_w1671* tail; };
void func_0031fdb0(LList_w1671* l, LNode_w1671* after, LNode_w1671* n) {
    if (after == 0) {
        LNode_w1671* h = l->head;
        if (h == 0) { l->tail = n; l->head = n; n->next = 0; return; }
        n->next = h; l->head = n; return;
    }
    if (after == l->tail) { after->next = n; n->next = 0; l->tail = n; return; }
    n->next = after->next; after->next = n;
}

void func_001fa610(u8* a0, u8* a1, u8* a2) {
    u8* p = a0 + **(s32**)(a2 + 0xc) + 160;
    if (*(s32*)a1 == *(s32*)(a0 + 0xc)) {
        *(f32*)(p + 0xa8) += *(f32*)(a1 + 8);
        p[0x8e] = a1[0xc];
        *(f32*)(p + 0x9c) += *(f32*)(a1 + 4);
        p[0x8f] = a1[0xd];
    }
}

struct RE_w1671 { s32 type; s32 id; s32 a; s32 b; s32 c; s32 pad[3]; };
extern s32 D_0035e360;
extern s32 D_0035e368;
extern RE_w1671 D_01dadc00[];
s32 func_00234240(s32 a0, s32 a1, s32 a2) {
    s32 i = D_0035e360;
    s32 id = D_0035e368;
    RE_w1671* e = &D_01dadc00[i];
    e->type = 5;
    e->a = a0;
    e->b = a1;
    e->id = id;
    e->c = a2;
    D_0035e360 = (i + 1) & 0x3f;
    D_0035e368 = id + 1;
    return id;
}

void func_002bc1e8(void*);
void func_001d1820(u8* a0) {
    u32 f = *(u32*)(a0 + 0xc);
    if (!(f & 4)) goto set;
    if (f & 8) goto set;
    {
        void* q = *(void**)(a0 + 0x28);
        if (q) { func_002bc1e8(q); f = *(u32*)(a0 + 0xc); }
    }
set:
    *(u32*)(a0 + 0xc) = f | 8;
}

extern s32 D_0035de5c;
extern u8 D_0035de54;
extern f32 D_0035de1c;
extern s32 D_0035de20;
void func_00226f20(s32 a0) {
    D_0035de5c = a0;
    if (a0 == 0) { D_0035de54 = 0; D_0035de1c = 0.0f; D_0035de20 = 0; return; }
    D_0035de54 = 1; D_0035de1c = -2.0f; D_0035de20 = -1;
}

extern s32 D_00361a50;
extern u8* D_0034e948;
void func_001c1130(s32);
void func_00197760(void);
void func_00197c90(void);
void func_001398d0(s32);
void func_002bfa98(s32* a0, s32 a1, s32 a2) {
    a0[0] = a1; a0[1] = a2;
    D_00361a50 = (s32)a0;
    func_001c1130(12);
    *(u32*)(*(u8**)(D_0034e948 + 0xb40) + 0x2c) |= 1;
    func_00197760();
    func_00197c90();
    func_001398d0(201);
}

void func_001e1500(void*);
extern f32 D_00349e10;
void func_001e1638(u8* a0) {
    func_001e1500(a0);
    f32 t = *(f32*)(a0 + 0x28);
    if (30.0f <= t) { *(f32*)(a0 + 0x28) = 0.0f; *(s32*)(a0 + 0x24) = 6; }
    else *(f32*)(a0 + 0x28) = t + D_00349e10;
}

struct C105_w1671 { void* vt; s32 f4; u8 f8; u8 p9[0xb]; s32 f14; s32 f18; s32 f1c; s32 f20; s32 f24; s32 f28; };
extern C105_w1671 D_0033cb80;
extern u8 D_0032b930;
void wt_00105e68(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_00105e68jjjj");
void wt_00105e68(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) {
        C105_w1671* p = &D_0033cb80;
        p->vt = &D_0032b930;
        p->f4 = 0;
        p->f8 = 84;
        p->f14 = 2;
        p->f18 = 0x222e0;
        p->f1c = 0; p->f20 = 0; p->f24 = 0;
        p->f28 = 4096;
    }
}

extern s32 D_003417a8;
extern s32 D_00341788[];
s32 func_00112a58(s32 a0) {
    s32 n = D_003417a8;
    if (n == 0) return 0;
    if (a0 < 0) { s32 j = n + a0; if (j < 0) return 0; return D_00341788[j]; }
    if (a0 >= n) return 0;
    return D_00341788[a0];
}

extern s32 D_00351eb8;
extern s32 D_00351ec0;
extern s32 D_00351ec8;
// 001c8e00 static initialiser: moved to src/yasui/libys/mutex.cpp (linked unit).

struct VObj_w1671 { void** vt; };
s32 func_0011f078(void*, s32);
void func_0011c890(u8* a0, s32 a1) {
    VObj_w1671* o = *(VObj_w1671**)(a0 + 0x14);
    ((void (*)(VObj_w1671*, s32, s32))o->vt[0x48 / 4])(o, *(s32*)(a0 + 0x104), a1);
    if (func_0011f078(*(void**)(a0 + 0x14), *(s32*)(a0 + 0x104))) *(u32*)(a0 + 0xc) |= 2;
    else *(u32*)(a0 + 0xc) &= ~2;
}
}
