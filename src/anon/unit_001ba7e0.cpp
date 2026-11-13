#include "../common/types.h"

// YS::MISSION, first part (0x1ba7e0-0x1bb270): the mission object's constructor (C2 and C1 copies),
// map preparation, start/end of a mission and the per-frame task that waits for the mission's exit.
// The accessors that follow are mission.cpp. The "msn/%s/%s.bar" format before this unit's .rodata
// stays retail data.

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
}

// 0x1baa58: the mission object's constructor (sub-objects with vtables 3525a8/352588/352560/352858).
namespace u1baa58_ctor {
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
}  // namespace u1baa58_ctor

// 0x1ba7e0: the same constructor, C2 copy (written as a plain function with the C1 body).
extern "C" u32 func_001ba7e0(u1baa58_ctor::CTarget* self, u32 arg, u32 a2, u32 a3)
{
    using namespace u1baa58_ctor;
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

// 0x1baa58: C1 copy.
extern "C" u32 ctarget_001baa58(u1baa58_ctor::CTarget* self, u32 arg, u32 a2, u32 a3) asm("_Z16ctarget_001baa58jjjj");
extern "C" u32 ctarget_001baa58(u1baa58_ctor::CTarget* self, u32 arg, u32 a2, u32 a3)
{
    using namespace u1baa58_ctor;
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

// 0x1bacd0: loads the mission's map resource, publishes it, and folds its flags into the field state.
namespace u1baa58_prep {
struct W93Map { u8 pad[4]; u16 flags; };
struct W93Res { u8 pad[8]; W93Map* map; };
struct W93Fld { u8 pad[8]; W93Map* map; u8 p2[40 - 12]; u8 f40[32]; u32 f72; };
union W93UM { W93Map* p; u32 u; };
}  // namespace u1baa58_prep

extern "C" {
u32 func_001708f8(void*, s32);
u1baa58_prep::W93Res* func_00168b38_prep(u32, s32, s32) asm("func_00168b38");  // entry_array_find_nth
void func_001d5458(u1baa58_prep::W93Map*);
void func_00191990(void);
extern u1baa58_prep::W93UM D_01d49324;
extern u1baa58_prep::W93UM D_0034f240_prep asm("D_0034f240");

void func_001bacd0(u1baa58_prep::W93Fld* f)
{
    using namespace u1baa58_prep;
    f->f72 = func_001708f8(f->f40, -1);
    W93Map* m = func_00168b38_prep(f->f72, 2, 0)->map;
    func_001d5458(m);
    f->map = m;
    D_01d49324.p = m;
    if (f->map->flags & 1) func_00191990();
    if (f->map->flags & 0x20) D_0034f240_prep.u |= 4;
    if (f->map->flags & 0x40) D_0034f240_prep.u |= 0x200;
    if (f->map->flags & 0x80) D_0034f240_prep.u |= 0x400;
    if (f->map->flags & 0x100) D_0034f240_prep.u |= 0x8000;
}

// 0x1badd8: YS::MISSION::Prepare().
extern u32 D_01d49320;
void func_001bacd0_u(u32) asm("func_001bacd0");
void YS_MISSION_Prepare() asm("_ZN2YS7MISSION7PrepareEv");
void YS_MISSION_Prepare() {
    u32 p = D_01d49320;
    if (p != 0) {
        func_001bacd0_u(p);
    }
}

// 0x1bae08
void func_001d71f0(...);
void func_001bae08() {
    u32** g = (u32**)0x01d50000;
    u32* p = g[-6968];
    if (p != 0) {
        func_001d71f0(p[0]);
    }
}
}

// 0x1bae38: starts the current mission (map hooks, mission parameters, colosseum level, task).
namespace u1baa58_start {
struct Dat838 { u8 pad0[8]; u8 x8; u8 x9; u16 xa; u8 xc; u8 pad0d[3]; s32 x10; u8 pad14[8]; u8 sub1c[4]; };
struct Prm838 { u8 pad0[8]; s32 x8; };
struct Unit838 { u16 x0; u8 pad2[0x16]; s32 x18; };
struct Sub838 { u8 pad0[0x14]; s32 x14; s32 x18; };
struct Obj838 { s32 x0; u8 pad4[4]; Dat838* data; u8 sub2[0x3c]; s32 x48; Sub838 sub3; u8 pad[0x2cc - 0x4c - sizeof(Sub838)]; s32 x2cc; };
struct Lv838 { u8 pad0[2]; u8 lv; u8 pad3[3]; u16 x6; };
static inline bool has838(Prm838* p) { return p && p->x8 != 0; }
}  // namespace u1baa58_start

extern "C" {
extern u1baa58_start::Lv838 D_0032bae0;
void func_001bb220(void*);
void func_001bb2c8(void*);
void func_001db610(void*, void (*)(void*), void*);
u1baa58_start::Prm838* func_00168b38(s32, s32, s32);
s32 func_00196908(s32);
void eff_1dddd0_1971(void*, s32) asm("_Z16wtarget_001dddd0jjjj");
u1baa58_start::Unit838* func_001c1130(u8);
s32 tail4_192048_1971(u16) asm("_Z16u_tail4_00192048jjjj");
s32 func_001bbb50(void);
void func_001ada38(s32);
u64 iscol_1971(void) asm("_ZNK2YS13MISSION_TABLE12is_colosseumEv");
s32 func_001d5668(u8);
void func_001d5698(u8);
void func_001bba30(u1baa58_start::Obj838*);
void func_001bbe18(s32);
void func_001d5518(void*, void*, s32);
void func_001d7218(s32);
void* createtask_1971(s32, s32, void (*)(void*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
void func_001bb958(s32);

void func_001bae38(u1baa58_start::Obj838* o)
{
    using namespace u1baa58_start;
    func_001db610(o->data->sub1c, func_001bb2c8, o);
    Prm838* p = func_00168b38(o->x48, 3, 0);
    if (has838(p)) o->x2cc = func_00196908(p->x8);
    p = func_00168b38(o->x48, 18, 0);
    if (has838(p)) eff_1dddd0_1971(o->sub2, p->x8);
    if (o->data->x8) {
        Unit838* u = func_001c1130(o->data->x8);
        if (o->data->xa) u->x18 = tail4_192048_1971(o->data->xa);
        if (func_001bbb50() || u->x0 == 0x23) func_001ada38(9);
        if (iscol_1971()) {
            s32 max = D_0032bae0.x6 != 0xc4 ? 10 : 50;
            u8 lv = D_0032bae0.lv;
            if (lv == max) { Sub838* s3 = &o->sub3; s3->x14 = 3; }
            else if (lv == max - 1) { Sub838* s3 = &o->sub3; s3->x14 = 4; }
            else { Sub838* s3 = &o->sub3; s3->x18 = lv; }
        }
    }
    if (o->data->xc) {
        if (!func_001d5668(o->data->x9)) {
            func_001d5698(o->data->x9);
            func_001bba30(o);
        }
    }
    func_001bbe18(o->data->x10);
    func_001d5518(&o->sub3, o->sub2, 0);
    func_001d7218(o->x0);
    createtask_1971(1, 14000, func_001bb220);
    func_001bb958(0);
}

// 0x1bb020: YS::MISSION::end().
void func_001d7380(u32 a0);
void func_0014ca20();
void func_001969c0(u32 a0);
u32 func_001dde40(...);
u32 func_00170950(...);
u32 func_001bbb50_v(...) asm("func_001bbb50");

void YS_MISSION_end(u32 a0) asm("_ZN2YS7MISSION3endEv");
void YS_MISSION_end(u32 a0) {
    u32 s0 = a0;
    func_001d7380(*(u32*)a0);
    func_0014ca20();

    s32 t7 = *(s32*)(s0 + 716);
    if (t7 >= 0) {
        func_001969c0((u32)t7);
    }

    if (*(u32*)(s0 + 72) != 0) {
        u32 p = s0 + 12;
        if (*(u32*)(s0 + 12) != 0) {
            func_001dde40(p);
        }
        func_00170950(*(u32*)(s0 + 72));
    }

    return ((void(*)())func_001bbb50_v)();
}
}

// 0x1bb090: one step of the mission's exit sequence (returns 0 when finished).
namespace u1baa58_exit {
struct VObj_w1568;
struct VObj_vt_w1568 { u8 pad[0x40]; s32 (*fn)(VObj_w1568*); };
struct VObj_w1568 { VObj_vt_w1568* vt; };
struct Q_w1568 { s32 a; s32 id; s32 kind; };
struct O_w1568_bb { u32 pad; u32 flags; u32 pad8; u8 x0c[0x78]; Q_w1568 q; u8 pad2[0x1d0]; u8 x260[0x78]; s32 state; s32 p0; s32 p1; };
}  // namespace u1baa58_exit

extern "C" {
extern u1baa58_exit::VObj_w1568* D_0034e948;
extern u32 D_0034f240;
s32 func_00195328(s32);
s32 func_00197920(void);
f32 func_00197b98(void);
s32 func_0019ba60(u1baa58_exit::VObj_w1568*);
void func_001bb630(s32, s32);
void func_001bc0d0(u1baa58_exit::O_w1568_bb*);
void func_001d21c0(void*);
void func_001d5518_x(u1baa58_exit::Q_w1568*, void*, s32) asm("func_001d5518");
void func_001d7f80(u1baa58_exit::O_w1568_bb*);
void func_002bc788(void);
void func_002bc798(void);
s32 func_001bb090(u1baa58_exit::O_w1568_bb* o)
{
    using namespace u1baa58_exit;
    func_001d21c0(o->x260);
    switch (o->state) {
    case 0: {
        VObj_w1568* v = D_0034e948;
        if (func_00197920() && func_0019ba60(v) && !v->vt->fn(v)) return 1;
        if (!(o->flags & 2)) func_001d7f80(o);
        o->state = 1;
        break;
    }
    case 2:
        o->state = 3;
        break;
    case 3:
        if (func_00197b98() <= 4.0f) {
            s32 a;
            if (o->p0 == 16) a = 2;
            else {
                if (o->p0 == 156) {
                    func_002bc798();
                    func_001bbe18(7016);
                    func_002bc788();
                }
                a = 1;
            }
            s32 r = func_00195328(a);
            Q_w1568* q = &o->q;
            if (q->id == 0) { q->id = r; q->kind = 566; }
            func_001d5518_x(q, o->x0c, 0);
            D_0034f240 |= 8;
            func_001bc0d0(o);
        }
        break;
    case 4:
        if (func_00197920() == 0) {
            func_001bb630(o->p0, o->p1);
            return 0;
        }
        break;
    }
    return 1;
}

// 0x1bb220: the mission task: steps the exit sequence of the current mission, then ends the task.
extern u8* D_01d49320_p asm("D_01d49320");
void func_001024a8(void*);
void func_001bb220(void* t)
{
    u8* m = D_01d49320_p;
    if (m && func_001bb090((u1baa58_exit::O_w1568_bb*)m)) return;
    func_001024a8(t);
}
}
