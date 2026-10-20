#include "../common/types.h"
// VU0 macro matrix*vector (inline asm) and a 16-byte vector class with an lq/sq copy.
#define W1806_QC(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1806Vec {
    f32 x, y, z, w;
    W1806Vec() {}
    W1806Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1806Vec(const W1806Vec& o) { W1806_QC(this, &o); }
    W1806Vec& operator=(const W1806Vec& o) { if (this != &o) W1806_QC(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1806Mtx {
    W1806Vec r[4];
    W1806Vec operator*(const W1806Vec& v) const {
        W1806Vec o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct W1806Elem { u8 pad[28]; f32 len; u8 pad2[32]; };
struct W1806Src {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual W1806Elem* get();
};
struct W1806Obj { u8 pad[20]; W1806Src* src; u8 pad2[20]; W1806Mtx* mtx; };

struct W1806Ent { s32 a; s32 off; };
struct W1806Hdr { s32 x; s32 n; W1806Ent e[1]; };
struct W1806Item { u8 pad[128]; s32 h; u8 pad2[12]; };
struct W1806Set { W1806Hdr* h; W1806Item* e; s32 p8; s32 id; };

extern "C" {
void* func_001050d8(s32);
void func_00165870(s32);
s32 func_001659b8(void*, s32);
extern s32 D_01d48c90;

void func_0011d5e0(W1806Obj* o, s32 i, W1806Vec* out, f32 s) {
    W1806Elem* e = &o->src->get()[i];
    W1806Vec v(e->len * s, 0.0f, 0.0f, 1.0f);
    *out = o->mtx[i] * v;
    out->y = -out->y;
    out->z = -out->z;
}

void func_001b2f38(W1806Set* o, W1806Hdr* h, u8 flag) {
    s32 i;
    o->h = h;
    o->e = (W1806Item*)func_001050d8(h->n * 144);
    for (i = 0; i < o->h->n; i++) {
        o->e[i].h = func_001659b8((u8*)o->h + o->h->e[i].off, D_01d48c90);
        if (!flag) func_00165870(o->e[i].h);
    }
    o->id = D_01d48c90++;
}
}
