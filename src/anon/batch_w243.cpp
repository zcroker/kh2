#include "../common/types.h"

extern "C" {
struct w243_L4 { u8 pad[8]; s32 n; };
w243_L4* func_00294000(s32);
s32 func_002aa5b8(s32, s32);
extern u8* D_0035f620;

s32 func_002ad4a8(s32 a) {
    s32 i; s32 ok = 1;
    w243_L4* l = func_00294000(2);
    for (i = 0; i < l->n; i++) {
        s32 r = func_002aa5b8(a, i);
        if (r >= 0) {
            u32* q = (u32*)(D_0035f620 + (a << 2)) + 17;
            if (!(q[(u32)r >> 5] & (1 << (r & 31)))) { ok = 0; break; }
        }
    }
    return ok;
}

struct w243_T { u8 pad[4]; u8 kind; };
struct w243_B { u8 pad[0x3b0]; u32 idx; };
struct w243_A { u8 pad[0xc]; w243_B* c; w243_B* d; u8 pad2[0x14]; w243_T* t; u8 pad3; u8 m; };
s32 func_001af9e8(w243_A*, w243_B*);
s32 func_001c0268(void*, w243_A*);
s32 func_0019bb58(w243_B*);
s32 func_0019ba60(w243_B*);
s32 func_0019c6f0(w243_B*);
static inline bool w243_kind(w243_A* a) { return (u8)(a->t->kind - 5) < 2; }
s32 w243_ctarget(w243_A* a, w243_B* b) asm("_Z16ctarget_0018d940jjjj");
s32 w243_ctarget(w243_A* a, w243_B* b) {
    if (func_001af9e8(a, b)) return 0;
    if (!func_001c0268((u8*)b + 0xa50, a)) return 0;
    if (w243_kind(a)) return 1;
    if (!func_0019bb58(b)) return 0;
    if (a->c == b || a->d == b) return 0;
    if (((a->m >> b->idx) & 1) == 0) return 0;
    if (func_0019ba60(a->c) && func_0019c6f0(a->c)) return 0;
    return 1;
}

struct w243_E2c { u8 pad[0xf8]; s32 len; u8 pad2[344 - 0xfc]; };
struct w243_E14 { u16 h; u8 pad[18]; };
struct w243_E10 { u32 a; s32 i; s32 off; u8 pad[12]; };
struct w243_O { u8 pad[0x10]; w243_E10* t10; w243_E14* t14; u8 pad2[0x24 - 0x18]; s32 cnt; u8 pad3[4]; w243_E2c* arr; u8* base; s32 cnt34; u8 pad4[0x4c - 0x38]; s32 idx; };
u8* func_0023c3e0(w243_O* o, s32 x, s32 n) {
    s32 acc = 0;
    s32 i;
    for (i = 0; i < o->cnt; i++) {
        s32 prev = acc;
        acc += o->arr[i].len;
        if (x < acc) {
            s32 off = x - prev;
            w243_E14* h = &o->t14[o->idx];
            w243_E10* e = &o->t10[h->h];
            s32 j;
            for (j = 0; j < o->cnt34; j++, e++) {
                if (e->i == i && e->off == off) {
                    if (n == 0) return o->base + j * 344;
                    n--;
                }
            }
        }
    }
    return 0;
}
}
