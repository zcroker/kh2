#include "../common/types.h"

// ---- 00113470: static init/destroy for priority 0xffff (two constructors, three empty-dtor array loops).
struct W1878E { u8 v[16]; ~W1878E() {} };
struct W1878H { u8 hdr[16]; W1878E arr[32]; };
extern "C" {
void func_0010b450(void*);
void func_00190128(void*);
extern W1878H D_003a9040;
extern W1878E D_00341750[3];
extern W1878E D_00341720[3];
extern u8 D_003417b0[];
}
void func_00113470(int a, int b) {
    if (b == 0xffff && a == 1) func_0010b450(&D_003a9040);
    if (b == 0xffff && a == 1) func_00190128(D_003417b0);
    if (b == 0xffff && a == 0) {
        if (D_00341750) {
            W1878E* e = D_00341750 + 3;
            for (;;) { e->~W1878E(); if (e == D_00341750) break; --e; }
        }
    }
    if (b == 0xffff && a == 0) {
        if (D_00341720) {
            W1878E* e = D_00341720 + 3;
            for (;;) { e->~W1878E(); if (e == D_00341720) break; --e; }
        }
    }
    if (b == 0xffff && a == 0) {
        W1878H* h = &D_003a9040;
        if (h->arr) {
            W1878E* e = h->arr + 32;
            for (;;) { e->~W1878E(); if (e == h->arr) break; --e; }
        }
    }
}

// ---- 0018a818: fills a placement record from a source entry; position = matrix * (x, y, z, 1).
#define W1878_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1878Q {
    f32 v[4];
    W1878Q() {}
    W1878Q(const W1878Q& o) { W1878_QCOPY(this, &o); }
    W1878Q& operator=(const W1878Q& o) {
        if (this != &o) W1878_QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct W1878Mtx { W1878Q r[4]; };
static inline W1878Q W1878MulMV(const W1878Mtx& m, const W1878Q& v)
{
    W1878Q r;
    asm volatile("lqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
        : : "r"(&r), "r"(&v), "r"(&m) : "memory");
    return r;
}
struct W1878Src { u8 pad[5]; u8 b5; u16 flags; s16 x, y, z, dy, px, py; };
struct W1878Dst { s32 f0; f32 f4, f8; W1878Src* src; W1878Q pos; };
struct W1878Ctx { u8 pad[0x7f8]; s32 f7f8; };
extern "C" {
void func_0016b0e0(W1878Ctx*, s32, W1878Mtx*);
void func_0018a818(W1878Dst* o, W1878Ctx* c, W1878Src* s) {
    W1878Mtx m;
    W1878Q v;
    W1878Q* pv = &v;
    pv->v[0] = s->x;
    pv->v[1] = s->y;
    pv->v[2] = s->z;
    o->f0 = s->b5;
    o->src = s;
    pv->v[3] = 1.0f;
    if ((s->flags & 0x4000) || (c->f7f8 & 0x400)) {
        o->f4 = s->px;
        o->f8 = s->py;
        func_0016b0e0(c, s->flags, &m);
        o->pos = W1878MulMV(m, *pv);
        o->pos.v[1] -= s->dy;
    } else {
        o->f4 = o->f8 = 0.0f;
        asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&o->pos) : "memory");
    }
}
}
