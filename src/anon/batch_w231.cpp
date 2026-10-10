#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

extern "C" {
struct W231Ent { u32 a; u32 b; u32 c; };
struct W231Q { char p[0x108]; u32 flags; char q[0x48c - 0x10c]; W231Ent* tab; };
struct W231S { char p[4]; W231Q* q; char r[0x18]; u32 w20; u32 idx; W231Q* q28; };
void func_0019cbe8(W231S*);
u32* func_00177860(W231Q*);
s32 func_0019ba60(W231Q*);
u32 func_00154b40(u32, u32);

void func_0019cb48(W231S* s) {
    volatile u32 z[5];
    z[3] = 0;
    func_0019cbe8(s);
    if (s->q28->tab) {
        if (*func_00177860(s->q28) & 0x80000) {
            if (func_0019ba60(s->q)) {
                if (!(s->q->flags & 0x4000)) {
                    W231Ent* t = s->q->tab;
                    if (t) {
                        W231Ent* e = (W231Ent*)(s->idx * 12 + (u32)t);
                        s->w20 = func_00154b40(e->a, e->b);
                    }
                }
            }
        }
    }
}

s64 func_00312db8(s64, s64);
extern u32 D_003638d0;
struct W231Sl { u8 pad[12]; u8 st; u8 b13; s8 b14; s8 b15; };
void func_001e23b0(W231Sl* p, W231Sl* src) {
    for (s32 i = 0; i < 10; i++, p++) {
        if (p->st == 0) {
            s8 k = -128;
            if (p != src) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" :: "r"(p), "r"(src) : "$8", "memory");
            p->b13 = 0;
            p->st = k;
            D_003638d0 = D_003638d0 * 0x10dcd;
            s32 r = (s32)func_00312db8(D_003638d0, 0x1010102);
            p->b14 = r;
            p->b15 = 30;
            return;
        }
    }
}

s32 func_002538f8(s32);  // entry16_get_flag_bit
s32 func_00253928(s32);  // entry16_get_bit1
s32 func_00253918(void);
s32 func_002539e8(s32, s32);
void func_00102448(u32, s32);
s32 func_002b6298(u32 a) {
    if (func_002538f8(1)) return 1;
    if (!func_00253928(1)) {  // entry16_get_bit1
        for (;;) {
            if (!func_00253918() && !func_002539e8(1, 0)) break;
            func_00102448(a, 0);
        }
    }
    for (;;) {
        if (func_002538f8(1)) break;
        func_00102448(a, 0);
    }
    return 1;
}
}
