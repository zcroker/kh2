#include "../common/types.h"

// 0018ad18
struct W22Ent { u32 w; u32 x[3]; };
struct W22Sub8 { u8 pad[10]; u16 n; };
struct W22Q { u8 pad[8]; W22Sub8* s; };
struct W22R { u8 pad[0x24]; s32 f24; };
struct W22Bits {
    u32 w[1];
    bool Test(u32 i) { return (w[i >> 5] >> (i & 31)) & 1; }
    void Set(u32 i) { u32* q = &w[i >> 5]; *q |= 1 << (i & 31); }
};
extern "C" {
struct W22P;
void func_00198450(W22P*);
W22Ent* func_0019b308(W22Q*);
s32 func_0018c528(u8);
}
struct W22P {
    u8 pad[0x818]; W22Q* f818; W22R* f81c;
    u8 pad2[0xa40 - 0x820]; s32 a40; s32 a44; s32 a48;
    u8 pad3[0xb04 - 0xa4c]; W22Bits bits;
    void Init() {
        a44 = 0; a40 = 2; a48 = 0;
        W22Q* q = f818;
        s32 n = q->s->n;
        W22Ent* e = func_0019b308(q);
        for (s32 j = 0; j < n; j++) {
            if ((e[j].w & 0xff0000ff) == 0x04000000) a48 = func_0018c528(((u8*)&e[j])[1]);
        }
    }
};

// 00237280
struct W22Hdr { s32 f0, f4, n8, oc, n10, o14, n18, o1c; };
struct W22Obj {
    s32 f0; void* p4; void* p8; void* pc;
    u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, rest:26;
    s32 f14, f18; u8 pad1c[0x34 - 0x1c];
    s32 n34, n38, n3c, f40; f32 f44; s32 f48; u8 pad4c[0x68 - 0x4c]; s32 f68;
    u8 pad6c[0x88 - 0x6c]; u32 f88; s32 f8c, f90, f94, f98;
};

extern "C" {

void func_0018ad18(W22P* p)
{
    func_00198450(p);
    if (p->f81c) {
        for (u32 i = 0; i < 7; i++) {
            if ((u8)((p->f81c->f24 >> i) & 1)) p->bits.Set(i);
        }
    }
    if (p->bits.Test(0)) p->Init();
}

void func_002373a8(W22Obj*);
void func_00237680(W22Obj*, s32);
void func_00237740(W22Obj*, f32, f32, f32);
void func_00237a68(W22Obj*, f32, f32, f32);
void func_00237ad8(W22Obj*, s32);

s32 func_00237280(W22Obj* o, W22Hdr* h, s32 a)
{
    f32 one = 1.0f;
    o->p4 = (u8*)h + h->oc;
    o->p8 = (u8*)h + h->o14;
    o->pc = (u8*)h + h->o1c;
    o->n34 = h->n8;
    o->n38 = h->n10;
    o->n3c = h->n18;
    o->f68 = -1;
    o->b0 = 1; o->b1 = 1; o->b2 = 1;
    o->b3 = 0; o->b4 = 0; o->b5 = 0;
    o->f40 = a;
    o->f44 = one;
    o->f48 = 0;
    o->f14 = 0;
    o->f18 = 0;
    func_002373a8(o);
    func_00237680(o, 0);
    func_00237740(o, 0.0f, 0.0f, 0.0f);
    func_00237a68(o, one, one, one);
    o->f8c = 0;
    o->f90 = 0;
    o->f88 = 0x80808080;
    o->f94 = 0;
    o->f98 = 0;
    func_00237ad8(o, 0);
    return 1;
}

}
