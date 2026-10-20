#include "../common/types.h"

/* 16-byte vector with an lq/sq copy assignment (hand-written VU-style copy). */
struct W1774Vec {
    f32 x, y, z, w;
    W1774Vec() {}
    W1774Vec& operator=(const W1774Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct W1774Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(void*);
};

extern "C" {

struct W1774Node { u8 pad[0x30]; u8 sub[0x90]; W1774Node* next; };
extern W1774Node* D_01c60cd8;
u8* func_00186078(u8*);
void func_001c0458(void*, s32);

static inline W1774Node* w1774_next(W1774Node* q) { if (!q) return D_01c60cd8; return q->next; }

void func_0018e040(s32 a0) {
    u8* p = 0;
    while ((p = func_00186078(p)) != 0) {
        func_001c0458(p + 0xa50, a0);
        if (*(s32*)(p + 0xaac) == a0) *(s32*)(p + 0xaac) = 0;
    }
    W1774Node* q = 0;
    while ((q = w1774_next(q)) != 0) func_001c0458(q->sub, a0);
}

W1774Vec func_0019fbe0r(void) asm("func_0019fbe0");
s32 func_001b2d10(void*, W1774Vec*);

W1774Vec* func_001c8fe8(W1774Vec* r, W1774Obj* o, void* x) {
    W1774Vec t;
    *r = func_0019fbe0r();
    if (r->y > 0.0f) {
        if (func_001b2d10(x, r)) o->v5(x);
    }
    return r;
}

}
