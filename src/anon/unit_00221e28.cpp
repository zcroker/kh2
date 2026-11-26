// Linked unit 0x00221e28-0x002223f0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 00221e28 (was src/anon/batch_w2370_nsa.c)
namespace n00221e28 {
/* VIF packet header built in front of a run of 48-byte items. */
typedef struct VifPkt_w2370 {
    u32 w0, w4, w8, wc;
    u32 self;       /* 0x10 */
    u32 w14, w18;
    u16 h1c; u8 b1e; u8 b1f;
    u16 qwc;        /* 0x20 DMA tag */
    u8 b22; u8 id;
    u32 w24;
    u32 vif0;       /* 0x28 */
    u32 w2c, w30;
    u16 h34; u8 b36; u8 count;
    u16 h38; u16 h3a; u16 h3c; u16 h3e;
    u8 pad40[0xc];
    f32 scale;      /* 0x4c */
    u32 w50, w54, w58;
} VifPkt_w2370;
typedef struct { u8 d[48]; } VifItem_w2370;
typedef struct { VifPkt_w2370* pkt; u8 count; } VifOwner_w2370;
/*TARGET 00221e28*/
void func_00221e28(VifOwner_w2370* o) asm("func_00221e28");
void func_00221e28(VifOwner_w2370* o) {
    VifPkt_w2370* s = o->pkt;
    u32* t;
    s->h3e = 0;
    s->self = (u32)s;
    s->count = o->count;
    s->scale = 1.0f;
    s->id = 0x70;
    s->vif0 = 0x040000B0;
    s->h1c = 0;
    s->w18 = 0;
    s->qwc = (s->count * 48u >> 4) + 2;
    s->h34 = 0;
    s->b36 = 0;
    s->h3c = 0;
    s->h38 = 0;
    s->b1e = 0;
    s->w14 = 0;
    s->w4 = 0;
    s->w0 = 0;
    s->wc = 0;
    s->w8 = 0;
    s->w58 = 0;
    t = (u32*)&((VifItem_w2370*)((u8*)s + 0x40))[s->count];
    t[0] = 0;
    t[1] = 0x11000000;
    t[2] = 0x14000000;
    t[3] = 0x11000000;
}
}  // namespace n00221e28

// 00221ed0 (was src/anon/batch_w1796.cpp)
namespace n00221ed0 {
struct Item_w1796 { u8 d[48]; };
struct Node_w1796 {
    Node_w1796* head; s32 pad4; Node_w1796* next; Node_w1796* prev;
    u8 pad10[0x24];
    u16 start2; u16 pad36; u16 cnt2; u16 pad3a; u16 cnt; u16 flags;
    Item_w1796 items[1];
};
void func_00220088(Item_w1796*, u16) asm("func_00220088");
/*TARGET 00221ed0*/
void func_00221ed0(Node_w1796* n) asm("func_00221ed0");
void func_00221ed0(Node_w1796* n) {
    u16 f = n->flags & 0x20;
    Item_w1796* it = n->items;
    s32 i = n->cnt;
    while (i > 0) { func_00220088(it, f); it++; i--; }
    it = &n->items[n->start2];
    i = n->cnt2;
    while (i > 0) { func_00220088(it, f); it++; i--; }
    if (n->prev) {
        if (n->next) n->next->prev = n->prev;
        n->prev->head = n->next;
    }
}
}  // namespace n00221ed0

// 00221f98 (was src/anon/tiny_auto80_queue.cpp)
namespace n00221f98 {
/*TARGET 00221f98*/
u32 func_00221f98(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00221f98jjjjjjjj");
u32 func_00221f98(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r14 = *(u32*)((u32)r4 + (s32)(4));
    r2 = 0u;
    if (r14 != 0u) {
        r15 = *(u32*)((u32)r14 + (s32)(0));
        r2 = r14;
        *(u32*)((u32)r4 + (s32)(4)) = r15;
    }
    return r2;
}
}  // namespace n00221f98

// 00221fb8 (was src/anon/auto80_199_queue.cpp)
namespace n00221fb8 {
/*TARGET 00221fb8*/
void func_00221fb8(u32 a0, u32 a1, u32 a2) asm("_Z13func_00221fb8jjj");
void func_00221fb8(u32 a0, u32 a1, u32 a2) {
    a2 = a2 & 0xff;
    a1 = a1 & 0xff;

    *(u8*)(a0 + 1) = (u8)a2;
    u32 t7 = a2 - 1;
    u32 t6 = a0 + 16;
    *(u8*)(a0 + 0) = (u8)a1;

    a2 = t7 & 0xff;
    *(u32*)(a0 + 4) = t6;

    t7 = 48;
    a1 = a1 - 1;
    t7 = a2 * t7;
    t7 = t7 + 128;
    a2 = t7 & 0xffff;

    *(u16*)(a0 + 2) = (u16)a2;
    if ((s32)a1 > 0) {
        do {
            u32 t7p = t6;
            a1 = a1 - 1;
            t6 = t6 + a2;
            *(u32*)(t7p + 0) = t6;
        } while ((s32)a1 > 0);
    }

    *(u32*)(t6 + 0) = 0;
}
}  // namespace n00221fb8

// 00222018 (was src/anon/auto80_199_queue.cpp)
namespace n00222018 {
/*TARGET 00222018*/
void func_00222018(u32 a0, u32 a1) asm("_Z13func_00222018jj");
void func_00222018(u32 a0, u32 a1) {
    u32 s2 = a1;
    u32 s3 = a0;
    u32 s1 = *(u32*)(a0 + 0);

    if (s1 != 0) {
        do {
            u32 s0 = s1;
            s1 = *(u32*)(s1 + 0);
            func_00221ed0(s0);
            u32 t7 = *(u32*)(s2 + 4);
            *(u32*)(s0 + 0) = t7;
            *(u32*)(s2 + 4) = s0;
        } while (s1 != 0);
    }

    *(u32*)(s3 + 0) = 0;
}
}  // namespace n00222018

// 00222080 (was src/anon/batch_w87.cpp)
namespace n00222080 {
// 0x001c91c8: definition moved into src/anon/unit_001c91c8.cpp

// ---- 0x222080: allocates a node and links it at the head of a list ----
u8* func_00221f98(u8*) asm("func_00221f98");
struct Key { void* p; u8 b; };
void func_00221e28(Key*) asm("func_00221e28");
void func_002226b8(void*, s32) asm("func_002226b8");
/*TARGET 00222080*/
// vec3_copy
void func_00222080(u8* list, u8* a1, s32 a2, s32 a3) asm("func_00222080");
// vec3_copy
void func_00222080(u8* list, u8* a1, s32 a2, s32 a3) {
    u8* n = func_00221f98(a1);
    if (!n) return;
    Key k;
    k.p = n;
    k.b = a1[1];
    u32 fl = 256;
    func_00221e28(&k);
    *(s32*)(n + 92) = 0;
    *(s32*)(n + 48) = 0;
    u8 c = list[4];
    if (c & 4) fl = 384;
    if (c & 0x10) fl |= 0x200;
    if (c & 8) fl |= 0x400;
    if (c & 0x20) fl |= 0x1000;
    *(u16*)(n + 62) |= fl;
    func_002226b8(n + 64, a2);  // vec3_copy
    func_002226b8(n + 96, a3);  // vec3_copy
    u8* h = *(u8**)list;
    if (h) *(u8**)(h + 4) = n;
    *(u8**)n = h;
    *(u8**)(n + 4) = list;
    *(u8**)list = n;
}
}  // namespace n00222080

// 00222170 (was src/anon/batch_w99.cpp)
namespace n00222170 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V13f6 {
    f32 x, y, z, w;
    V13f6() {}
    V13f6(const V13f6& o) { QCOPY(this, &o); }
    V13f6& operator=(const V13f6& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
    V13f6& operator*=(f32 s)
    {
        asm("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
            : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    V13f6& operator+=(const V13f6& o)
    {
        asm("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
            : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline V13f6 operator-(const V13f6& a, const V13f6& b)
{
    V13f6 r;
    asm("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct M2221 { u8 a[32]; u8 b[16]; };
struct N2221 {
    N2221* next; N2221* prev; u8 pad[44]; u16 sel; u8 pad2[8]; u16 flags; M2221 m[1];
};
struct H2221 { N2221* first; u8 flags; };
struct C2221 { H2221* head; u32 a; void* b; N2221* list; u32 c; u32 d; };
struct W2221 { u8 pad[64]; N2221* node; u32 a; u32 l; void* b; };
void sceVu0UnitMatrix(W2221*) asm("sceVu0UnitMatrix");
// vu_store_w_splat
void func_002226b8(void*, u32) asm("func_002226b8");
// vec3_copy
void func_00221348(W2221*) asm("func_00221348");
void func_00221ed0(N2221*) asm("func_00221ed0");
/*TARGET 00222170*/
void func_00222170(C2221* c) asm("func_00222170");
void func_00222170(C2221* c)
{
    H2221* h = c->head;
    s32 fl = 0;
    W2221 w;
    if (h->flags & 2) {
        fl = 32;
        h->flags &= ~2;
    }
    sceVu0UnitMatrix(&w);  // vu_store_w_splat
    w.a = c->a;
    w.l = (u32)c->list;
    w.b = c->b;
    N2221* n = h->first;
    while (n) {
        if (n->flags & 0x200) {
            func_002226b8(n->m[n->sel].a, c->c);  // vec3_copy
            func_002226b8(n->m[n->sel].a + 32, c->d);  // vec3_copy
        }
        if (n->flags & 0x100) n->flags = fl | n->flags;
        w.node = n;
        func_00221348(&w);
        if (n->flags & 0x10) {
            N2221* cur = n;
            n = n->next;
            if (cur->next) cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
            func_00221ed0(cur);
            cur->next = c->list->prev;
            c->list->prev = cur;
        } else {
            n = n->next;
        }
    }
}
}  // namespace n00222170

// 002222b8 (was src/anon/batch_w1673.cpp)
namespace n002222b8 {
typedef unsigned int u128_t __attribute__((mode(TI)));
union U2222b8 { u8* p; u64 v; };
struct N2222b8 { N2222b8* next; };
union UL2222b8 { N2222b8* p; u64 v; };
struct C2222b8 { s32 a; N2222b8* n; u8* p; s32 d; s32 c; U2222b8* flag; u64 e; u64 f; };
s32 func_00220da0(C2222b8*) asm("func_00220da0");
void sceGsSyncPath(s32, s32) asm("sceGsSyncPath");
s32 func_002f35e8(s32) asm("func_002f35e8");
void func_002f3918(s32, u8*) asm("func_002f3918");
void func_003058a0(s32) asm("func_003058a0");
/*TARGET 002222b8*/
void func_002222b8(N2222b8** list, s32 a1, s32 a2, s32 a3, U2222b8* pp, u64 e, u64 f) asm("func_002222b8");
void func_002222b8(N2222b8** list, s32 a1, s32 a2, s32 a3, U2222b8* pp, u64 e, u64 f) {
    C2222b8 c;
    s32 id = func_002f35e8(2);
    c.d = a3;
    c.a = a1;
    c.c = a2;
    c.e = e;
    c.f = f;
    N2222b8* n = ((UL2222b8*)list)->p;
    sceGsSyncPath(0, 0);
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
            sceGsSyncPath(0, 0);
        }
    }
}
}  // namespace n002222b8

// 002223e0 (was src/anon/tiny_auto80.cpp)
namespace n002223e0 {
/*TARGET 002223e0*/
void func_002223e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002223e0jjjj");
void func_002223e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)a0 = 0;
    *(u8*)(a0 + 4) = 0;
}
}  // namespace n002223e0

