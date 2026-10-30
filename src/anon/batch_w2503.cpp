// w2503: objA f8/vt stores volatile and self-relative so sched2 keeps f8 before vt (jal 320400 slot gets vt).
#include "../common/types.h"
// CTarget constructor: builds slots, sub-objects (vtables 3525a8/352588/352560/352858) and the resource.
inline void* operator new(unsigned int, void* p) { return p; }
extern "C" {
void func_001ddd10(u8*);
void func_00320400(u8*);
void func_001d1678(u8*, s32);
void func_001d1fa8(u8*);
void func_001d4d28(u8*);
void func_002fee78(u8*, const char*, u32, u32);
void func_00170518(u8*, s32, s32);
u32 func_001d7098(u32);
extern u8 D_003525c8[];
extern u8 D_003525a8[];
extern u8 D_00352588[];
extern u8 D_00352560[];
extern u8 D_00352858[];
extern char D_0036dbf0[];
extern u32 D_0033caf4[];

struct Pair {
    u32 a;
    u32 b;
};
static inline void Pair_ctor(Pair* p)
{
    p->a = 0;
    p->b = 0;
}
struct One {
    u32 v;
};
struct Slot28 {
    s32 kind;
    u32 f4;
    u32 f8;
    Pair p;
    u32 f20;
    u32 f24;
};

struct ObjBase {
    u8* vt;
    u32 f4;
    One f8;
    u8 body[32];
};


static inline void Slot28_ctor(Slot28* s, s32 kind)
{
    s->f4 = 0;
    Pair_ctor(&s->p);
    s->kind = kind;
    s->f20 = 0;
    s->f24 = 0;
}

struct CTarget {
    u32 arg;          // 0x00
    u32 f4;           // 0x04
    u32 f8;           // 0x08
    u8 work[28];      // 0x0c
    u8 res[32];       // 0x28
    u32 f48;          // 0x48
    Slot28 slots[4];  // 0x4c
    ObjBase objA;     // 0xbc
    u8 objB[3][56];   // 0xe8
    u8 objC[3][52];   // 0x190
    u8 objD[52];      // 0x22c
    u8 objE[104];     // 0x260
    u32 f2c8;
    s32 f2cc;
    u32 f2d0;
    u32 f2d4;
    u32 f2d8;
    u8 pad2dc[8];
    u8 objF[580];     // 0x2e4
    u32 f528;
    u32 f52c;
    union { f32 f; u32 u; } f530;
};

struct OneC { const u32 v; OneC() : v(0) {} };
static inline void ObjBase_ctor(ObjBase* o)
{
    o->f4 = 0;
    new (&o->f8) OneC;
    *(u32*)&o->vt = (u32)D_003525c8;
    func_00320400(o->body);
    func_001d1678((u8*)o, -1);
}
u32 ctarget_001baa58(CTarget* self, u32 arg, u32 a2, u32 a3) asm("_Z16ctarget_001baa58jjjj");
u32 ctarget_001baa58(CTarget* self, u32 arg, u32 a2, u32 a3)
{
    s32 i;
    u8* p;

    self->arg = arg;
    self->f4 = 0;
    self->f8 = 0;
    func_001ddd10(self->work);
    self->f48 = 0;
    Slot28_ctor(&self->slots[0], 12);
    Slot28_ctor(&self->slots[1], 14);
    Slot28_ctor(&self->slots[2], 14);
    Slot28_ctor(&self->slots[3], 15);
    {
        ObjBase* o = &self->objA;
        o->f4 = 0;
        *(volatile u32*)&self->objA.f8.v = 0;
        *(volatile u32*)&o->vt = (u32)D_003525c8;
        func_00320400(o->body);
        func_001d1678((u8*)o, -1);
    }
    *(u32*)&self->objA.vt = (u32)D_003525a8;
    for (i = 2, p = self->objB[0]; i != -1; i--, p += 56) {
        ObjBase_ctor((ObjBase*)p);
        *(u32*)p = (u32)D_00352588;
        *(u32*)(p + 48) = 0;
    }
    {
        s32 j;
        u8* q;
        for (q = self->objC[0], j = 2; j != -1; j--, q += 52) {
            ObjBase_ctor((ObjBase*)q);
            *(u32*)q = (u32)D_00352560;
            *(u32*)(q + 48) = 0;
        }
    }
    p = self->objD;
    ObjBase_ctor((ObjBase*)p);
    *(u32*)self->objD = (u32)D_00352858;
    p = self->objE;
    func_001d1fa8(p);
    self->f2c8 = 0;
    self->f2cc = -1;
    self->f2d0 = 0;
    self->f2d4 = 0;
    self->f2d8 = 0;
    func_001d4d28(self->objF);
    self->f528 = 0;
    self->f52c = 0;
    self->f530.f = 1.0f;
    func_002fee78(self->res, D_0036dbf0, D_0033caf4[0], a2);
    func_00170518(self->res, 900, 0);
    return func_001d7098(arg);
}
}
