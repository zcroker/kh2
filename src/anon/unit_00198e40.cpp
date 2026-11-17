// Event slots, part 2 (0x198e40-0x1991a8): slot setters, running a slot, and the slot array
// with its static initialiser. Part 1 is unit_00198b88.cpp.
#include "../common/types.h"

// Event slots (16 x 88 bytes at 0x1c61b48): a sound, a flag, resources and entries to run, and a
// YS::JUMPER at +52.
struct Ent198 {
    u16 type : 2;
    u16 id : 13;
};
struct JUMPER88 { u8 w[36]; };
struct EVENT88 {
    s32 a;          // 0x00
    s32 b;          // 0x04
    u32 se;         // 0x08
    s32 bgm;        // 0x0c
    u32 f10;        // 0x10
    s32 f14;        // 0x14
    s32 nres;       // 0x18
    u32* res;       // 0x1c
    Ent198 ents[7]; // 0x20
    s16 nents;      // 0x2e
    u8 f30;         // 0x30
    u8 pad31[3];
    JUMPER88 jmp;   // 0x34
    EVENT88();
} __attribute__((aligned(8)));
struct S36 { u32 w[9]; };

extern "C" {
static EVENT88 D_01c61b48[16];
}

// EVENT88 constructor pair (C2 0x198d50 inlines the +84 member's ctor, C1 0x198dc0 calls linkonce 0x31cc28),
// written as plain functions.
namespace n00198d50 {
inline void* operator new(unsigned int, void* p) { return p; }
struct W1530_C3 { u8 a, b, c; W1530_C3(u32 x, u32 y, u32 z) { a = x; b = y; c = z; } };
struct W1530_S3 { u16 a; s16 b; s16 c; W1530_S3(u32 x, s32 y, s32 z) { a = x; b = y; c = z; } };
struct W1530_C {
    s32 x0, x4; u32 x8; s32 xc, x10, x14, x18, x1c;
    u8 pad20[0xe]; union { s16 x2e; u8 x2e_c; }; union { u8 x30; u8 x30_c; }; u8 pad31[3]; u8 x34[4];
    u8 x38[3]; u8 pad3b; u16 x3c; s16 x3e; s16 x40; u8 pad42[0x12]; u8 x54[4];
};
extern "C" {
void func_0031cc28(void*);
void func_0019ef70(void*);
}
void func_00198d50(W1530_C* p) asm("func_00198d50");
void func_00198d50(W1530_C* p) {
    s32 m = -1;
    u32 f = 0xffff;
    p->x0 = m;
    p->x4 = m;
    p->x8 = f;
    p->xc = m;
    p->x10 = 0;
    p->x14 = m;
    p->x18 = 0;
    p->x1c = 0;
    p->x2e = 0;
    p->x30 = 0;
    new (p->x38) W1530_C3(f, m, m);
    new (&p->x3c) W1530_S3(f, m, m);
    void* q = p->x34;
    *(s32*)p->x54 = 0;
    func_0019ef70(q);
}
void func_00198dc0(W1530_C* p) asm("_ZN7EVENT88C1Ev");
void func_00198dc0(W1530_C* p) {
    s32 m = -1;
    u32 f = 0xffff;
    p->x0 = m;
    p->x4 = m;
    p->x8 = f;
    p->xc = m;
    p->x10 = 0;
    p->x14 = m;
    p->x18 = 0;
    p->x1c = 0;
    p->x2e = 0;
    p->x30 = 0;
    new (p->x38) W1530_C3(f, m, m);
    new (&p->x3c) W1530_S3(f, m, m);
    void* q = p->x34;
    func_0031cc28(p->x54);
    func_0019ef70(q);
}
}  // namespace n00198d50

void func_00198e40(void* self, s32 v) { *(s32*)((char*)self + 8) = v; }

void func_00198e48(void* self, s32 v) { *(s32*)((char*)self + 12) = v; }

EVENT88* ctarget_00198bd0(s32 a, s32 b) asm("_Z16ctarget_00198bd0jjjj");

extern "C" {
s32 func_00181500(u32);
void func_00181178(u32);
void func_001a6c90(s32);  // set_bit_in_array_b
u32 func_001a8258(u32);
void func_001a8438(u32);
void func_0019b2b0(u32);
void func_0019b2d8(u32);
void func_00197930(u32, u32, u8*);
void func_0019f070(u8*, u32);
u8 func_0019f060(u8*);

void func_00198e50(EVENT88* e, u32 a, s32 b) {
    e->f10 = a;
    e->f14 = b;
}

void func_00198e60(EVENT88* e, s32 n, u32* res) {
    e->nres = n;
    e->res = res;
}

void func_00198e70(EVENT88* e, u32 id) {
    Ent198* x = &e->ents[e->nents++];
    x->type = 0;
    x->id = id;
}

void func_00198ea8(EVENT88* e, u32 id) {
    Ent198* x = &e->ents[e->nents++];
    x->type = 1;
    x->id = id;
}

void func_00198ee8(EVENT88* o) {
    if (o->se != 0xffff && !func_00181500(o->se)) func_00181178(o->se);
    if (o->bgm >= 0) func_001a6c90(o->bgm);  // set_bit_in_array_b
    if (o->nres > 0)
        for (s32 i = 0; i < o->nres; i++) func_001a8438(func_001a8258(o->res[i]));
    for (s32 i = 0; i < o->nents; i++) {
        switch (o->ents[i].type) {
        case 0: func_0019b2d8(o->ents[i].id); break;
        case 1: func_0019b2b0(o->ents[i].id); break;
        }
    }
    o->a = -1;
}

s32 func_00199030(EVENT88* e) {
    u8* p = (u8*)e;
    if (p[48]) return 1;
    if (*(u32*)(p + 16)) {
        func_00197930(*(u32*)(p + 16), *(u32*)(p + 20), p + 52);
        return 1;
    }
    func_0019f070(p + 52, 0);
    return func_0019f060(p + 52);
}

S36 func_00199098(u32 a1) {
    EVENT88* v = ctarget_00198bd0(a1, -1);
    func_00198ee8(v);
    return *(S36*)&v->jmp;
}
}
