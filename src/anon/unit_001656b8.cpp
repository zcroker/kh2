#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"

// 001656b8 (gap: __tcf_0 of the local static in 0x164d60, empty)
namespace n001656b8 {
void func_001656b8(void) asm("func_001656b8");
void func_001656b8(void) {}
} // n001656b8

// 001656c0 (from src/anon/tiny_more2.cpp)
namespace n001656c0 {
void func_001656c0(u32 a0,u32 a1,u32 a2,u32 a3) asm("func_001656c0");
void func_001656c0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; *(u32*)((u32)a0 + (0)) = 0; *(u32*)((u32)a0 + (4)) = 0; *(u32*)((u32)a0 + (8)) = 0; }
} // n001656c0

// 001656d0 (from src/anon/batch_w58.cpp)
namespace n001656d0 {
struct Nd12 { u32 f0; void* f4; u32 f8; Nd12* next; };
struct L12 { Nd12* head; Nd12* tail; };
extern L12 D_004f41c0 asm("D_004f41c0");
extern union { u32 v; u8 c; } D_0034c7a4 asm("D_0034c7a4");
void func_001656c0(Nd12*) asm("func_001656c0");
void* func_001063c0(u32, u32) asm("func_001063c0");
void func_001415e8(void*, u32, s32) asm("func_001415e8");
void func_001656d0(Nd12* n, u32 a1, u32 a2) asm("func_001656d0");
void func_001656d0(Nd12* n, u32 a1, u32 a2) {
    func_001656c0(n);
    n->f0 = a2;
    void* o = func_001063c0(224, D_0034c7a4.v);
    func_001415e8(o, a1, -1);
    n->f4 = o;
    asm volatile("" ::: "memory");
    if (!D_004f41c0.tail) { D_004f41c0.tail = n; D_004f41c0.head = n; n->next = 0; }
    else { D_004f41c0.tail->next = n; n->next = 0; D_004f41c0.tail = n; }
}
} // n001656d0

// 00165768 (from src/anon/batch_w80.cpp)
namespace n00165768 {
struct U0_Link { u32 f0; void* buf; u32 f8; U0_Link* next; };
struct U0_LinkList { U0_Link* head; U0_Link* tail; };
struct U0_LinkPool { U0_Link e[64]; s32 freeIdx[64]; s32 nfree; };
extern U0_LinkList D_004f41c0 asm("D_004f41c0");
extern U0_LinkPool* D_0034c7a0 asm("D_0034c7a0");
void func_00106420(void*) asm("func_00106420");
void func_00165768(U0_Link* n) asm("func_00165768");
void func_00165768(U0_Link* n) {                  
    U0_Link* prev;
    U0_LinkPool* pool;
    s32 k;
    if (n == D_004f41c0.head) {
        D_004f41c0.head = n->next;
        prev = 0;
    } else {
        for (prev = D_004f41c0.head; prev->next != n; prev = prev->next) ;
        prev->next = n->next;
    }
    if (n == D_004f41c0.tail) D_004f41c0.tail = prev;
    n->next = 0;
    if (n->buf) func_00106420(n->buf);
    n->buf = 0;
    asm volatile("" ::: "memory");
    pool = D_0034c7a0;
    pool->freeIdx[pool->nfree++] = n - pool->e;
}
} // n00165768

// 00165830 (from src/anon/batch_w16.cpp)
namespace n00165830 {
void func_00142940(u32, void*) asm("func_00142940");
void func_00165830(u8* p, void* m) asm("func_00165830");
void func_00165830(u8* p, void* m) {
    u32 tmp[16] __attribute__((aligned(16)));
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                 "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                 : : "r"(tmp), "r"(m) : "$8", "$9", "$10", "$11", "memory");
    func_00142940(*(u32*)(p + 4), tmp);
}
} // n00165830

// 00165870 (from src/anon/tiny.cpp)
namespace n00165870 {
void func_00165870(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00165870");
void func_00165870(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t = *(u32*)((u32)a0 + (8));
    t |= 0x0001u;
    *(u32*)((u32)a0 + (8)) = t;
}
} // n00165870

// 00165880 (gap: clears the bit that 0x165870 sets)
namespace n00165880 {
void func_00165880(u32 a0) asm("func_00165880");
void func_00165880(u32 a0) {
    u32 t = *(u32*)((u32)a0 + (8));
    t &= ~0x0001u;
    *(u32*)((u32)a0 + (8)) = t;
}
} // n00165880

// 00165898 (from src/anon/batch_w1798_nsa.cpp)
namespace n00165898 {
struct Node_165898 { s32 a, b; u8 c[8]; };
struct Pool_165898 { Node_165898 n[64]; s32 idx[64]; s32 cnt; };
struct Pair_165898 { s32 a, b; };
void* tz_alloc_165898(u32, u32) asm("_ZN2Tz13LoadDataAllocEjj");
void lst_165898(void*) asm("_Z13func_0031a830Pv");
extern Pair_165898 D_004f41c0 asm("D_004f41c0");
extern s32 D_0034c7a4 asm("D_0034c7a4");
extern Pool_165898* D_0034c7a0 asm("D_0034c7a0");
void func_00165898(u32 arg) asm("func_00165898");
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
} // n00165898

// 00165968 (from src/anon/batch_w1746.cpp)
namespace n00165968 {
struct W1746Elem { u32 w[4]; ~W1746Elem() {} } __attribute__((aligned(16)));
struct W1746ElemArray { W1746Elem e[64]; };
extern W1746ElemArray* D_0034c7a0 asm("D_0034c7a0");
void LoadDataFree(...) asm("_ZN2Tz12LoadDataFreeEz");
void func_00165968(void) asm("func_00165968");
void func_00165968(void) {
    W1746ElemArray* p = D_0034c7a0;
    if (p) {
        p->~W1746ElemArray();
        LoadDataFree(p);
        D_0034c7a0 = 0;
    }
}
} // n00165968

// 001659b8 (from src/anon/batch_w65.cpp)
namespace n001659b8 {
struct Pool16 { u8 e[64][16]; s32 idx[64]; s32 n; };
extern u8* D_0034c7a0 asm("D_0034c7a0");
void func_001656d0(void*, u32, u32) asm("func_001656d0");
void* func_001659b8(u32 a, u32 b) asm("func_001659b8");
void* func_001659b8(u32 a, u32 b) {
    Pool16* s = (Pool16*)D_0034c7a0;
    void* r = s->e[s->idx[--s->n]];
    func_001656d0(r, a, b);
    return r;
}
} // n001659b8

// 00165a10 (from src/anon/batch_w81.cpp)
namespace n00165a10 {
struct Vn81 {
    f32 x, y, z, w;
    Vn81& operator=(const Vn81& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vn81 vsub81n(const Vn81& a, const Vn81& b) {
    Vn81 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct Ent165 { u32 id; u32 obj; u32 flags; };
struct Me165 { Vn81 pos; Vn81 dir; u8 pad[16]; Vn81 tgt; u8 pad2[60]; u32 id; };
Ent165* func_00165ef0(Ent165*) asm("func_00165ef0");
s32 func_00142b70(u32) asm("func_00142b70");
s32 func_00164718(u32, Me165*) asm("func_00164718");
s32 func_00165a10(Me165* m) asm("func_00165a10");
s32 func_00165a10(Me165* m) {
    Ent165* e = 0;
    s32 found = 0;
    while ((e = func_00165ef0(e)) != 0) {
        if (e->id == m->id) continue;
        u32 f = e->flags & 1;
        if (f) continue;
        if (func_00142b70(e->obj)) continue;
        if (!func_00164718(e->obj, m)) continue;
        found = 1;
        m->dir = vsub81n(m->tgt, m->pos);
    }
    return found;
}
} // n00165a10

// 00165ad8 (from src/anon/batch_w2414_nsa.cpp)
namespace n00165ad8 {
struct V165ad8 {
    f32 x, y, z, w;
    V165ad8& operator=(const V165ad8& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Ent165ad8 { s32 id; void* body; };
struct Hit165ad8 {
    V165ad8 v0, v1, v2, v3, v4, v5;
    u16 s0, s1, s2, s3;
    f32 dist;
    f32 f108;
    struct { u32 b0 : 1; u32 b1 : 2; u32 b3 : 4; u32 rest : 25; } a;
    struct { u32 c0 : 1; u32 c1 : 1; u32 c2 : 1; u32 rest : 29; } fl;
    Ent165ad8* ent;
    s32 owner;
    f32 f128;
};
void func_0031b9e0(Hit165ad8*) asm("func_0031b9e0");
Ent165ad8* func_00165ef0(Ent165ad8*) asm("func_00165ef0");
s32 func_00142b70(void*) asm("func_00142b70");
s32 func_001424c0(void*, Hit165ad8*) asm("func_001424c0");
s32 func_00165ad8(Hit165ad8* h, f32* minDist) asm("func_00165ad8");
s32 func_00165ad8(Hit165ad8* h, f32* minDist)
{
    Ent165ad8* e = 0;
    s32 found = 0;
    f32 bestD = 10000000.0f;
    *minDist = bestD;
    Hit165ad8 best;
    func_0031b9e0(&best);
    f32 saved = h->v3.y;
    u64 mask = (u64)1 << 32;                                                                         
    while ((e = func_00165ef0(e)) != 0) {
        if (e->id == h->owner) continue;
        if (func_00142b70(e->body)) continue;
        if (!func_001424c0(e->body, h)) continue;
        h->ent = e;
        if (!(*(u64*)&h->a & mask)) {
            if (h->v3.y < bestD) {
                bestD = h->v3.y;
                best = *h;
                found = 1;
            }
        } else if (*minDist > h->dist) *minDist = h->dist;
        h->v3.y = saved;
    }
    if (found == 1) *h = best;
    return found;
}
} // n00165ad8

