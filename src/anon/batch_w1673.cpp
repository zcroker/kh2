#include "../common/types.h"
struct Node_de0a0 { u8 pad[0x60]; Node_de0a0* next; };
struct List_de0a0 { Node_de0a0* head; Node_de0a0* tail; };
struct Obj_de0a0 { u8 pad[8]; u8 sub[4]; List_de0a0 list; };
struct Res_de0a0 { u8 pad[0xc]; Obj_de0a0* owner; };
struct P_de0a0 { u8 pad[0x38]; f32 f; };
extern "C" {
Res_de0a0* eff_create_001dcff0(f32, void*, u16) asm("_ZN3ryj6EFFECT6CreateERNS_11EFFECT_DATAEjjjif");
Node_de0a0* func_001de948(s32);
void func_001dec78(f32, Node_de0a0*, Res_de0a0*, u16*, P_de0a0*);
Res_de0a0* func_001de0a0(Obj_de0a0* a0, u16* a1, s32 a2, s32 a3, s32 t0, P_de0a0* p) {
    f32 f = p->f + 0.1f;
    Res_de0a0* r = eff_create_001dcff0(f, a0->sub, *a1);
    r->owner = a0;
    Node_de0a0* n = func_001de948(0x70);
    func_001dec78(f, n, r, a1, p);
    List_de0a0* l = &a0->list;
    if (a0->list.head == 0) {
        l->tail = n;
        a0->list.head = n;
        n->next = 0;
    } else {
        n->next = a0->list.head;
        a0->list.head = n;
    }
    return r;
}
}
struct S5a48b { u8 pad[4]; u8 v; };
struct S5a48 { u8 pad[0x588]; s32 a; u32 b; u8 pad2[0xaf8-0x590]; S5a48b* p; };
extern "C" {
s32 func_0019ba60(S5a48*);
s32 func_002bfdf8();
s32 func_002c1b48(S5a48*);
void func_002c85c8(s32);
void func_002c8648();
void func_002ca010(s32);
void func_002ca0a8();
void func_002c5a48(void* self, S5a48* o) {
    if (func_002bfdf8() != 0) return;
    s32 s1 = -1;
    s32 s2 = -1;
    if (func_0019ba60(o) != 0) {
        if (o->a < 0) {
            s1 = o->p->v;
        } else {
            u32 bb = o->b; if ((u8)(bb & 1)) s2 = func_002c1b48(o);
        }
    }
    if (s1 >= 0) func_002c85c8(s1); else func_002c8648();
    if (s2 >= 0) func_002ca010(s2); else func_002ca0a8();
}
}
struct E9b90 { u16 id; u16 sub; u8 kind; u8 pad[3]; };
struct H9b90 { u8 pad[2]; u16 x; u8 pad2[8]; u16 n; };
struct O9b90 { u8 pad[8]; H9b90* h; u8 pad2[0x34-0xc]; E9b90* e; };
extern "C" {
s32 func_00198c28(u16, s32);
void func_00198e70(s32, u16);
void func_00198ea8(s32, u16);
void func_00199b90(O9b90* o) {
    for (s32 i = 0; i < o->h->n; i++) {
        u16 id = ((E9b90*)(i*8 + (u8*)o->e))->id;
        s32 sub = -1;
        if (id != 0x4a) sub = ((E9b90*)(i*8 + (u8*)o->e))->sub;
        s32 r = func_00198c28(id, sub);
        switch (((E9b90*)(i*8 + (u8*)o->e))->kind) {
        case 0: func_00198e70(r, o->h->x); break;
        case 1: func_00198ea8(r, o->h->x); break;
        }
    }
}
}
struct A91658 { s32 a; s32 b; };
struct E91658 { u8 d[20]; };
struct B91658 { E91658 e[128]; s32 idx[128]; s32 n; };
extern A91658 D_01c60d10[8];
extern B91658 D_01c60d50;
extern "C" {
void func_00190128(E91658*);
void wtarget_00191658(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_00191658jjjj");
void wtarget_00191658(u32 a0, u32 a1, u32 a2, u32 a3) {
    if (a1 == 0xffff && a0 == 1) {
        A91658* p = D_01c60d10;
        for (s32 i = 7; i != -1; i--, p++) p->b = 0;
    }
    if (a1 == 0xffff && a0 == 1) {
        E91658* e = D_01c60d50.e;
        for (s32 i = 127; i != -1; e++) { i--; func_00190128(e); }
        B91658* b = &D_01c60d50;
        s32* q = b->idx;
        for (s32 j = 0; j < 128; j++) *q++ = j;
        b->n = 128;
    }
}
}
struct S1f1870 { u8 pad[0x9c]; u8 a; u8 b; u8 c; };
extern "C" {
void func_001f1870(S1f1870* o, f32* pa, f32* pb, f32* pc, f32* pd) {
    f32 x = 0.0f;
    f32 z = 1.0f;
    f32 y = z;
    switch (o->a) { case 1: y = 0.5f; break; case 2: y = 0.25f; break; }
    switch (o->b) { case 1: z = 0.5f; break; case 2: z = 0.25f; break; }
    switch (o->c) {
    case 1: x = 0.5f; y += 0.25f; break;
    case 2: x = 0.5f; y += x; break;
    case 3: x = 0.75f; y += x; break;
    }
    f32 e = 0.01f;
    *pa = x + e;
    *pb = y - e;
    *pc = e;
    *pd = z - e;
}
}
typedef unsigned int u128_t __attribute__((mode(TI)));
union U2222b8 { u8* p; u64 v; };
struct N2222b8 { N2222b8* next; };
union UL2222b8 { N2222b8* p; u64 v; };
struct C2222b8 { s32 a; N2222b8* n; u8* p; s32 d; s32 c; U2222b8* flag; u64 e; u64 f; };
extern "C" {
s32 func_00220da0(C2222b8*);
void func_002f25a0(s32, s32);
s32 func_002f35e8(s32);
void func_002f3918(s32, u8*);
void func_003058a0(s32);
void func_002222b8(N2222b8** list, s32 a1, s32 a2, s32 a3, U2222b8* pp, u64 e, u64 f) {
    C2222b8 c;
    s32 id = func_002f35e8(2);
    c.d = a3;
    c.a = a1;
    c.c = a2;
    c.e = e;
    c.f = f;
    N2222b8* n = ((UL2222b8*)list)->p;
    func_002f25a0(0, 0);
    for (; n; n = n->next) {
        c.n = n;
        c.p = pp->p + 16;
        if (func_00220da0(&c)) {
            u8* q = pp->p;
            *(u128_t*)q = 0;
            q[3] = 0x70;
            c.flag->v |= 0x8000;
            *(u16*)q = ((u32)(c.p - pp->p) >> 4) - 1;
            func_003058a0(0);
            func_002f3918(id, q);
            func_002f25a0(0, 0);
        }
    }
}
}
struct O1b9880 { void** vt; u8 pad[0x104]; u32 flags; u8 pad2[0x8b4-0x10c]; O1b9880* next; };
struct L1b9880 { O1b9880* head; O1b9880* tail; };
extern L1b9880 D_01d48da0;
extern L1b9880 D_01d48da8;
extern "C" {
void func_0016a2e0(O1b9880*);
void func_001b9880() {
    O1b9880* p = D_01d48da8.head;
    while (p) {
        O1b9880* n = p->next;
        func_0016a2e0(p);
        if (p) ((void (*)(O1b9880*))p->vt[1])(p);
        p = n;
    }
    D_01d48da8.head = 0;
    D_01d48da8.tail = 0;
    for (p = D_01d48da0.head; p; ) {
        O1b9880* n = p->next;
        if (p->flags & 0x80000) {
            asm volatile("" ::: "memory");
            O1b9880* prev;
            if (p == D_01d48da0.head) {
                prev = 0;
                D_01d48da0.head = p->next;
            } else {
                prev = D_01d48da0.head;
                while (prev->next != p) prev = prev->next;
                prev->next = p->next;
            }
            if (p == D_01d48da0.tail) D_01d48da0.tail = prev;
            p->next = 0;
            if (!D_01d48da8.tail) {
                D_01d48da8.tail = p;
                D_01d48da8.head = p;
                p->next = 0;
            } else {
                D_01d48da8.tail->next = p;
                p->next = 0;
                D_01d48da8.tail = p;
            }
        }
        p = n;
    }
}
}
struct O160bd8 { void** vt; u8 pad[0x7c]; O160bd8* next; u8 pad2[0xfc]; u32 flags : 1; };
struct L160bd8 { O160bd8* head; O160bd8* tail; };
extern L160bd8 D_004f3b38;
extern L160bd8 D_004f3b48;
extern "C" {
void func_00160bd8() {
    O160bd8* p = D_004f3b48.head;
    while (p) {
        O160bd8* n = p->next;
        if (p) ((void (*)(O160bd8*))p->vt[4])(p);
        p = n;
    }
    D_004f3b48.head = 0;
    D_004f3b48.tail = 0;
    for (p = D_004f3b38.head; p; ) {
        O160bd8* n = p->next;
        if (p->flags) {
            asm volatile("" ::: "memory");
            O160bd8* prev;
            if (p == D_004f3b38.head) {
                prev = 0;
                D_004f3b38.head = p->next;
            } else {
                prev = D_004f3b38.head;
                while (prev->next != p) prev = prev->next;
                prev->next = p->next;
            }
            if (p == D_004f3b38.tail) D_004f3b38.tail = prev;
            p->next = 0;
            if (!D_004f3b48.tail) {
                D_004f3b48.tail = p;
                D_004f3b48.head = p;
                p->next = 0;
            } else {
                D_004f3b48.tail->next = p;
                p->next = 0;
                D_004f3b48.tail = p;
            }
        }
        p = n;
    }
}
}
struct I20c580 { u8 pad[0x20]; u16 busy; u8 pad2[0xa0 - 0x22]; };
struct M20c580 { I20c580* items; u8* buf; s32 n; s32 pad; u16 tick; };
struct C20c580 { s32 pad; s32 x4; u8 pad2[4]; u16 max; u16 period; };
struct G20c580 { u8 pad[0xa8]; u64 flags; };
extern G20c580* D_01d9e6e0;
extern s32 D_01d9ea9c;
extern "C" {
void func_0020bdb0(void*, void*, void*, u8*);
void func_0020bef8(M20c580*, C20c580*, I20c580*, s32, u8*);
void func_0020c580(M20c580* m, C20c580* c, s32 a2) {
    s32 cnt = 0;
    I20c580* it = m->items;
    u8* buf = m->buf;
    s32 n = m->n;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (c->x4 == 0xffff) return;
    m->tick++;
    for (s32 i = 0; i < n; i++) {
        if (it->busy) {
            func_0020bef8(m, c, it, a2, buf);
        } else if (c->period <= m->tick) {
            if (cnt < c->max) {
                func_0020bdb0(m, c, it, buf);
                cnt++;
            }
        }
        it++;
        if (buf) buf += 32;
    }
    if (cnt > 0) m->tick = 0;
}
}
struct V20bdb0 { f32 x, y, z, w; };
struct I20bdb0 { V20bdb0 pos; V20bdb0 q; };
struct M20bdb0 { u8 pad[0xb8]; f32 x, y, z; u8 pad2[0xd8 - 0xc4]; f32 r0, r1; };
extern u8 D_01d9e7b0[];
extern "C" {
f32 func_0020b410();
void func_0020b4e8(M20bdb0*, I20bdb0*, u8*);
void func_002f3cd8(void*, void*, void*);
void func_002f3d98(void*, void*);
void func_002fde18(void*, s32, u32);
void func_0020bdb0(void* self, void* mv, void* itv, u8* buf) {
    M20bdb0* m = (M20bdb0*)mv;
    I20bdb0* it = (I20bdb0*)itv;
    func_002fde18(it, 0, 0xa0);
    if (buf) func_002fde18(buf, 0, 0x20);
    V20bdb0 v;
    v.x = m->x;
    v.y = m->y;
    v.z = m->z;
    v.w = 1.0f;
    func_002f3d98(&it->q, &v);
    f32 r = m->r0 + m->r1;
    f32 d = r + r;
    f32 len;
    do {
        it->pos.x = d * func_0020b410() - r;
        it->pos.y = d * func_0020b410() - r;
        it->pos.z = d * func_0020b410() - r;
        asm volatile(
            "lqc2 $vf10,0(%1)\n"
            "vmul.xyz $vf10,$vf10,$vf10\n"
            "vaddx.y $vf10,$vf10,$vf10x\n"
            "vaddy.z $vf10,$vf10,$vf10y\n"
            "vsqrt Q,$vf10z\n"
            "vwaitq\n"
            "vaddq.x $vf10,$vf0,Q\n"
            "qmfc2 %0,$vf10\n" : "=r"(len) : "r"(it));
    } while (r < len);
    it->pos.w = 1.0f;
    func_002f3cd8(it, D_01d9e7b0, it);
    func_0020b4e8(m, it, buf);
}
}
struct V20a510 { f32 x, y, z, w; };
struct I20a510 { V20a510 pos; V20a510 q; };
struct M20a510 { u8 pad[0x7c]; f32 x, y, z; u8 pad2[0x9c - 0x88]; f32 r0, r1; };
extern "C" {
f32 func_00209fb8();
void func_0020a090(M20a510*, I20a510*, u8*);
void func_0020a510(void* self, void* mv, void* itv, u8* buf) {
    M20a510* m = (M20a510*)mv;
    I20a510* it = (I20a510*)itv;
    func_002fde18(it, 0, 0x60);
    if (buf) func_002fde18(buf, 0, 0x20);
    V20a510 v;
    v.x = m->x;
    v.y = m->y;
    v.z = m->z;
    v.w = 1.0f;
    func_002f3d98(&it->q, &v);
    f32 r = m->r0 + m->r1;
    f32 d = r + r;
    f32 len;
    do {
        it->pos.x = d * func_00209fb8() - r;
        it->pos.y = d * func_00209fb8() - r;
        it->pos.z = d * func_00209fb8() - r;
        asm volatile(
            "lqc2 $vf10,0(%1)\n"
            "vmul.xyz $vf10,$vf10,$vf10\n"
            "vaddx.y $vf10,$vf10,$vf10x\n"
            "vaddy.z $vf10,$vf10,$vf10y\n"
            "vsqrt Q,$vf10z\n"
            "vwaitq\n"
            "vaddq.x $vf10,$vf0,Q\n"
            "qmfc2 %0,$vf10\n" : "=r"(len) : "r"(it));
    } while (r < len);
    it->pos.w = 1.0f;
    func_002f3cd8(it, D_01d9e7b0, it);
    func_0020a090(m, it, buf);
}
}
