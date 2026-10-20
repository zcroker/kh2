#include "../common/types.h"

#define W1767_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// 16-byte VU0 vector. The VU0 macro instructions (lqc2/qmtc2/vmulx/sqc2) cannot come from C.
struct W1767Vec {
    f32 x, y, z, w;
    W1767Vec() {}
    W1767Vec(const W1767Vec& o) { W1767_QCOPY(this, &o); }
    W1767Vec& operator=(const W1767Vec& o) { if (this != &o) W1767_QCOPY(this, &o); return *this; }
    W1767Vec operator*(f32 k) const {
        W1767Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    W1767Vec& operator*=(f32 k) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1767Obj { u8 pad[0x20]; W1767Vec v20; };

struct W1767D { s32 x0; u8 pad[0x18]; u8 b1c; u8 b1d; };
struct W1767V { u8 pad[4]; u8 b4; };

typedef struct W1767Node { void* vt; u8 pad[0x1c]; struct W1767Node* next; } W1767Node;
typedef struct W1767List { W1767Node* head; W1767Node* tail; } W1767List;

extern "C" {
extern u8 D_00350378;
extern u8 D_0032bae2;
extern f32 D_00349e10;
extern W1767List D_01e2c080;
extern u8 D_00363808[];
extern u8 D_003637e0[];
W1767V* func_0016e920(s32);
s32 func_0016f448(u8);
f32 func_001c3ba8(void*, W1767Obj*);

s32 func_00199810(W1767D* p) {
    s32 r = 0;
    W1767V* v = func_0016e920(p->x0);
    if (v == 0) return r;
    if (D_00350378 != 0 && func_0016f448(v->b4) >= 2000) return r;
    if (p->b1c == 1 && p->b1d != D_0032bae2) return r;
    return 1;
}

W1767Vec func_001c3b20(void* a, W1767Obj* o) {
    o->v20 *= 0.9f;
    W1767Vec t;
    t = o->v20;
    t.y = func_001c3ba8(a, o);
    return t * D_00349e10;
}

void func_002ee380(W1767Node* n) {
    W1767Node* prev;
    W1767Node* c;
    n->vt = D_00363808;
    c = D_01e2c080.head;
    if (n == c) {
        D_01e2c080.head = n->next;
        prev = 0;
    } else {
        prev = c;
        while (prev->next != n) prev = prev->next;
        prev->next = n->next;
    }
    if (n == D_01e2c080.tail) D_01e2c080.tail = prev;
    n->next = 0;
    n->vt = D_003637e0;
}
}
