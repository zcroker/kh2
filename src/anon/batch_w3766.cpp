#include "../common/types.h"
struct CEnt { u32 a, b; s32 x8; s32 xc; };
struct CArr { u32 a; s32 n; };
struct CHdr { u8 pad[0x28]; s32 x28; u8 pad2[4]; s32 x30; s32 x34; };
struct CObj {
    u8 state; u8 next; u8 pad[0x26];
    s32 x28;
    u8 pad2c[4];
    CArr* arr;
    u8 pad34[4];
    union { u32* ids; struct { s16 id; s16 res; } s; } u;
};
static inline int ge10k(s32 v) { return v >= 10000; }
extern "C" {
CEnt* func_00168b38(CArr*, s32, s32);
void func_00168be8(s32);
CHdr* func_0016fac8(s32);
void cbh_ctor_0016fba0(CHdr*, u32, s32, s32) asm("_ZN2YS10CACHE_BUFF6HEADERC1EPKcij");
void* cbh_find_00170240(u32, s32) asm("_Z16ctarget_00170240jjjj");
void func_001700e8(void*, s32);
void func_00170188(CHdr*);
void func_00170178(void);
s16 func_002ba3b8(s16, s32, s32, s32, s32, void (*)(void), CObj*);

// Cache-buffer loader state step: state 1 starts the two streams, state 2 builds one header per entry, then goes to state 3.
// Partial asm (w3766): the sz/new-header s0 sharing needs h pinned to s0; three one-instruction asms keep the
// original order move a3,s0 / move s0,v0 / move a0,v0 / li a2 (gcc otherwise emits move a0,v0 first).
void func_0016fda8(CObj* o) {
    switch (o->state) {
    case 0:
        break;
    case 1: {
        if (o->u.s.id < 0) break;
        if (ge10k(o->x28)) break;
        register CArr* a asm("$21") = o->arr;
        register CEnt* e1 asm("$17") = func_00168b38(a, 32, 0);
        if (e1 == 0 || e1->x8 == 0) break;
        CEnt* e2 = func_00168b38(a, 31, 0);
        if (e2 == 0 || e2->x8 == 0) break;
        o->next = 2;
        o->u.s.res = func_002ba3b8(o->u.s.id, e2->x8, e2->xc, e1->x8, e1->xc, func_00170178, o);
        return;
    }
    case 2: {
        register CArr* a asm("$21") = o->arr;
        register s32 n asm("$22") = a->n;
        register u32* p asm("$18") = o->u.ids;
        s32 i;
        for (i = 0; i < n; i++) {
            void* t = cbh_find_00170240(*p, -1);
            if (t) func_001700e8(t, 0);
            CEnt* e = func_00168b38(a, -1, i);
            u32 sz = (e->xc + 0x7ff) & ~0x7ff;
            sz = (sz + 0x7f) & ~0x7f;
            CHdr* nh = func_0016fac8(0x40);
            u32 q = *p++;
            register u32 a3 asm("$7") = sz;
            register CHdr* h asm("$16");
            asm("move %0, %1" : "=r"(h) : "r"(nh), "r"(a3));
            register CHdr* a0r asm("$4");
            asm("move %0, %1" : "=r"(a0r) : "r"(nh), "r"(h));
            register s32 a2r asm("$6");
            asm("li %0, 5300" : "=r"(a2r) : "r"(a0r));
            cbh_ctor_0016fba0(a0r, q, a2r, a3);
            s32 v = e->x8;
            h->x28 = 10000;
            h->x30 = h->x34 = v;
            func_00168be8(e->x8);
            func_00170188(h);
        }
        o->next = 3;
        func_001700e8(o, 0);
        return;
    }
    }
    o->next = 3;
}
}
