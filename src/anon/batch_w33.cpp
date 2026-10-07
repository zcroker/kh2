#include "../common/types.h"

extern "C" {

struct NoTail { ~NoTail() {} };

struct KeyVal { s16 key; s16 val; };
extern KeyVal D_00369da8[];
s32 lookup_001033d8(void* k) asm("_Z13func_001033d8Pv");
s32 lookup_001033d8(void* k) {
    s32 r = -1;
    for (s32 i = 0; D_00369da8[i].key >= 0; i++)
        if (D_00369da8[i].key == (s32)k) r = D_00369da8[i].val;
    return r;
}

struct Buf256 { u8 b[256]; };
extern Buf256 D_003a7b70[];
extern Buf256 D_003a7d70[];
extern s32 D_0033cc40;
extern u8 D_0033cc44;
void* func_00106a18(u8 a) {
    if (a || D_0033cc44) return &D_003a7b70[D_0033cc40];
    return &D_003a7d70[D_0033cc40];
}

extern u32 D_003a99f0[];
struct Obj148 { u8 pad[287]; u8 slot; };
// Put o into the first free slot at or after its preferred index; bump the owner's count.
void func_00148a68(s32* owner, Obj148* o) {
    u32* t = D_003a99f0;
    u32 i = o->slot;
    while (t[i]) i++;
    t[i] = (u32)o;
    owner[21372 / 4]++;
}

u8 func_00242d58(void);
u32 func_00242ce8(void);
extern u64 D_0034a970[];
s32 func_001584a0(u64* p) {
    u8 b = func_00242d58();
    return (*p & D_0034a970[(u8)(b ^ 1)]) != 0;
}
s32 func_001584f8(u64* p) {
    u32 i = func_00242ce8();
    return (*p & D_0034a970[i + 2]) != 0;
}

void* func_00167f18(s32);
void func_0016dbe0(s32* p) {
    u64* v = (u64*)func_00167f18(0);
    *p = (u8)((v[1] >> *p) & 1);
}

struct Lim177 { u8 pad[45]; s8 max; };
struct Obj177 { u8 pad[2820]; u8 n; };
Lim177* func_00177860(Obj177*);
s32 func_00177bf8(Obj177* p) {
    if (p->n < func_00177860(p)->max) return p->n;
    return func_00177860(p)->max;
}

struct Cfg17d { u8 pad[88]; f32 scale; };
extern Cfg17d* D_00352130;
struct Val17d { s32 a; s32 b; };
struct Obj17d { void** vt; u8 pad[1160]; Val17d* v; };
s32 func_0017de70(Obj17d* o) {
    return ((s32 (*)(Obj17d*, s32, s32, s32))o->vt[30])(o, (s32)((f32)o->v->b * D_00352130->scale), 0, 0);
}

struct Node17f { u8 pad[60]; s32 a; s32 b; u8 pad2[148 - 68]; Node17f* child; u8 pad3[4]; Node17f* next; };
// Clear two fields on a node and, recursively, on all its children.
void func_0017f380(Node17f* n) {
    n->a = 0;
    n->b = 0;
    Node17f* c = 0;
    while ((c = !c ? n->child : c->next) != 0) func_0017f380(c);
}

s32 func_00181500(void*);
void func_00181178(void*);
s32 func_00181570(void* a, void* b) {
    if (!func_00181500(a) && func_00181500(b)) {
        func_00181178(a);
        return 1;
    }
    return 0;
}

struct Sub1a2 { u8 pad[10]; u8 v; };
struct Obj1a2 { u8 pad[394]; u16 a; u8 pad2[6]; u16 b; u8 pad3[580 - 404]; Sub1a2* s; };
// Add n to two counters, and to a sub-value capped at 100.
void func_001a25c8(Obj1a2* o, s32 n) {
    if (o->s) {
        if (o->s->v + n > 100) n = 100 - o->s->v;
        o->s->v += n;
    }
    o->a += n;
    o->b += n;
}

struct Ent1a8 { u16 id; u16 pad; u8 type; u8 pad2[7]; };
struct Tbl1a8 { u16 pad; u16 count; Ent1a8 e[1]; };
extern Tbl1a8* D_01c6cb98;
Ent1a8* func_001a8258(u32 id) {
    Tbl1a8* t = D_01c6cb98;
    Ent1a8* e = t->e;
    for (s32 i = 0; i < t->count; i++, e++)
        if (e->type == 1 && e->id == id) return e;
    return 0;
}

void func_00239bf8(u8*, u32);
void wtarget_001ac078(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_001ac078jjjj");
void wtarget_001ac078(u32 a, u32 b, u32 c, u32 d) {
    u8* p = (u8*)a;
    p[0] = b;
    p[1] = c;
    p[2] = d;
    if (!b) return;
    u32 n = (b * 4 + c) * 2;
    n = (s32)d >= 4 ? n + 33 : n + 37;
    func_00239bf8(p + 4, n);
}

struct St32 { u8 pad[13604]; u8 a; u8 b; };
extern St32 D_0032bb30;
void* func_001a15d0(s32, s32);
void func_001a1c70(void*);
void func_001a17c8(void*);
void func_001adbc0(void) {
    D_0032bb30.a = 0;
    D_0032bb30.b = 0;
    void* v = func_001a15d0(1, -1);
    func_001a1c70(v);
    func_001a17c8(v);
}

extern void* D_00350dec;
void* func_001708f8(void*, s32);
void* func_001af7c0(void*, void*);
struct Obj1af { u8 pad[4]; void* a; u8 pad2[40]; void* b; void* c; };
void func_001af778(Obj1af* o) {
    o->a = func_001708f8(D_00350dec, -1);
    o->c = func_001af7c0(o, o->b);
}

struct Obj1b4 { u8 pad[64]; u32 flags; };
extern Obj1b4* D_01d48cb0;
void func_001b5460(Obj1b4*);
void func_001b4f40(Obj1b4*);
void func_00105110(void*);
// Destroy and free the singleton at D_01d48cb0.
void func_001b43e0(void) {
    if (D_01d48cb0) {
        func_001b5460(D_01d48cb0);
        Obj1b4* p = D_01d48cb0;
        if (p) {
            NoTail g; // keeps the free a plain call (no sibcall)
            func_001b4f40(p);
            func_00105110(p);
        }
    }
}
void u_call0_001b5400(void) asm("_Z16u_call0_001b5400v");
void u_call0_001b5400(void) {
    if (D_01d48cb0) {
        D_01d48cb0->flags |= 0x10;
        asm volatile("" ::: "memory"); // the original reloads the global after the flag store
        func_001b5460(D_01d48cb0);
        Obj1b4* p = D_01d48cb0;
        if (p) {
            NoTail g;
            func_001b4f40(p);
            func_00105110(p);
        }
    }
}

s32 func_001dc738(void*);
s32 func_001dc790(u32* p) {
    s32 r = 0;
    if (func_001dc738(p) || (p[2] & 0x200000)) r = 1;
    return r;
}

// VU0 random: five vrnext steps seeded with -1, plus 1.0 (hand-written VU0 macro code).
f32 func_00203a40(void) {
    register u32 r asm("$15");
    asm volatile(
        "addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\t"
        "qmfc2 %0, $vf1"
        : "=r"(r) : : "$8");
    union { u32 i; f32 f; } u;
    u.i = r;
    return u.f;
}

struct A207 { u8 pad[16]; s32 a; s32 b; s32 c; };
struct B207 { u8 pad[257]; u8 x; u8 pad2[4]; u8 y; };
s32 func_00207308(A207* a, B207* b) {
    if (!a->a) return 0;
    if (b->y && !a->b) return 0;
    if (b->x && !a->c) return 0;
    return 1;
}

struct Ev234 { s32 type; s32 id; u32 a, b, c, d; u32 pad[2]; };
extern Ev234 D_01dadc00[];
extern s32 D_0035e360;
extern s32 D_0035e368;
u32 wtarget_00234298(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00234298jjjj");
u32 wtarget_00234298(u32 a, u32 b, u32 c, u32 d) {
    s32 i = D_0035e360;
    s32 id = D_0035e368;
    Ev234* e = &D_01dadc00[i];
    e->type = 6;
    e->a = a;
    e->b = b;
    e->c = c;
    e->id = id;
    e->d = d;
    D_0035e360 = (i + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}

struct Slot236 { u8 used; u8 pad[3]; s32 a; s32 b; s32 pad2; s32 x; s32 y; };
extern Slot236 D_0035e440[];
extern s32 D_0035ea40;
void init_00236d10(void*) asm("_Z13func_00236d10Pv");
void init_00236d10(void*) {
    Slot236* s = D_0035e440;
    s32 y = 0x3500, x = 0x3600;
    for (s32 i = 63; i >= 0; i--) {
        s->x = x;
        s->y = y;
        s->used = 0;
        x += 32;
        s->a = 0;
        y += 4;
        s->b = 0;
        s++;
    }
    D_0035ea40 = 1;
}

void func_00242408(void);
u32 func_00242418(void*, u32);
extern void* D_0035ec90;
s32 func_00241670(void* a) {
    func_00242408();
    u32 x = func_00242418(a, 0x8a58);
    func_00242408();
    return x == func_00242418(D_0035ec90, 0x8a58);
}

struct Bits242 { u32 pad; u32 lo : 6; u32 off : 1; };
void* func_001058e8(void);
void func_00242ca0(u8 on) {
    Bits242* b = (Bits242*)((u8*)func_001058e8() + 16800);
    b->off = on == 0;
}

struct Pad267 { u8 pad[28]; u16 mask; };
extern Pad267* D_0035f0e4;
// Index among the set bits of a 10-bit mask: how many set bits precede bit n (-1 if none).
s32 func_002670f8(s32 n) {
    s32 r = -1;
    s32 m = D_0035f0e4->mask;
    s32 c = 0;
    for (s32 i = 0; i < 10; i++) {
        if ((u8)((m >> i) & 1)) {
            if (i == n) { r = c; break; }
            c++;
        }
    }
    return r;
}

void func_00257708(s32);
extern s32* D_0035f2b4;
void func_00283d00(void*);
void func_00283f50(void);
void func_002833f8(void);
void func_002831e0(void* a, s32 b) {
    func_00257708(1);
    *D_0035f2b4 = b;
    func_00283d00(a);
    func_00283f50();
    func_002833f8();
}

extern u8 D_003617e8;
extern s32 D_003617e4;
void func_002b8434(s32);
void ResetPauseImpl_002bd6d0(void) asm("_ZN2Tz9MenuSound14ResetPauseImplEv");
void ResetPauseImpl_002bd6d0(void) {
    if (D_003617e8 != 1 && D_003617e4 > 0 && --D_003617e4 == 0) func_002b8434(0);
}

extern void* D_00362908[];
void func_002e7328(void*);
void func_002cff98(void*);
void func_002db928(u8* p) {
    *(void**)p = D_00362908;
    func_002e7328(p + 2976);
    func_002cff98(p);
    func_00105110(p);
}

extern void* D_00361f60;
void func_002cf280(void*, s32, s32);
u8* func_002dc7c8(void*);
void func_002de698(u8* p) {
    void* m = D_00361f60;
    func_002cf280(p + 2800, 8, 0);
    *(f32*)(p + 3060) = *(f32*)(func_002dc7c8(m) + 172);
}

struct Own2e8 { u8 pad[4]; void* h; };
struct Obj2e8 { Own2e8* o; void* v; f32 a; f32 b; };
void func_001b2210(void*, void*, f32, f32);
void func_0016bd60(void*, s32);
void func_002e8390(Obj2e8* o) {
    u8 tmp[16] __attribute__((aligned(16)));
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(tmp), "r"(o->v) : "$8", "memory");
    func_001b2210(o->o->h, tmp, o->a, o->b);
    func_0016bd60(o->o->h, 9);
}

void func_001c23a8(void*, void*, s32, s32, s32, s32, void*);
extern void* D_00363758[];
extern void* D_00363748;
void func_002ed300(void** p, void* a, void* b) {
    func_001c23a8(p, a, 0, 1, 0, 128, b);
    *p = D_00363758;
    D_00363748 = p;
}

s32 func_00105c30(void);
// Region code from the build/region id: 'SU', 'JP' or 'EU'.
s32 func_002ef988(void) {
    s32 r = 0x5355;
    switch (func_00105c30()) {
    case 2: break;
    case 1: case 8: r = 0x504a; break;
    default: r = 0x5545; break;
    }
    return r;
}

const u8* func_00316f70(const u8* p, s64* out) {
    u32 shift = 0;
    u8 byte;
    u64 result = 0;
    do {
        byte = *p++;
        result |= (byte & 0x7f) << shift;
        shift += 7;
    } while (byte & 0x80);
    if (shift < 64 && (byte & 0x40)) result |= -(1LL << shift);
    *out = result;
    return p;
}

struct VObj31d { void** vt; };
struct Mgr31d { u8 pad[20]; VObj31d* o; };
extern void* D_00347f80;
extern void* D_00347f98[];
void func_0031d7c0(void** p) {
    *p = D_00347f98;
    VObj31d* o = ((Mgr31d*)D_00347f80)->o;
    ((void (*)(VObj31d*, void*))o->vt[1])(o, p);
}

extern void* D_0034ee08[];
void func_0019f9a8(void*);
void func_001c0248(void*);
void func_00319fb0(void*);
void func_00324980(u8* p) {
    *(void**)p = D_0034ee08;
    func_0019f9a8(p + 2568);
    func_001c0248(p + 2640);
    func_00319fb0(p);
    func_00105110(p);
}


}
