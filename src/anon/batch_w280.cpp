#include "../common/types.h"
#define F(p,o,T) (*(T*)((u8*)(p)+(o)))
typedef s32 (*VF)(...);
typedef void (*VV)(...);
#define VT(o,i) ((VF)((*(void***)(o))[i]))
#define VTv(o,i) ((VV)((*(void***)(o))[i]))
extern "C" {
s32 func_001c0298(void*, void*);  // state_check5or6
void* func_0018db38(void*, void*, u32, u32);
void func_0018e420(void*, void*, void*, void*, s32);
void func_0018ef68(void*, void*, s32);
void func_0018ca10(void*);  // alloc_from_pool_magic
void func_0018e298(void** a0, void* a1, void* a2)
{
    s32 mode;
    if (VT(a1, 24)(a1) != 0 || func_001c0298((u8*)a1 + 2640, *a0) == 0) {  // state_check5or6
        mode = 4;
    } else {
        mode = 1;
        F(*a0, 4, u32) |= 0x1000;
    }
    u8* t = F(a2, 12, u8*);
    void* r = func_0018db38(*a0, a1, *(u16*)(t + 2), t[1]);
    u32* f = (u32*)((u8*)a1 + 2748);
    if (!((f[0] | f[1]) & ~f[2] & 0x2000))
        func_0018e420(a0, a1, r, a2, mode);
    {
        void* c = *a0;
        void* o = F(c, 136, void*);
        VTv(o, 29)(o, a1, c, F(r, 32, void*));
    }
    if (F(*a0, 140, void*)) {
        struct { void* a; void* b; void* c; } st;
        st.a = F(*a0, 148, void*);
        st.b = a1;
        st.c = *a0;
        func_0018ef68((u8*)*a0 + 140, &st, 3);
    }
    F(*a0, 4, u32) &= ~0x1000;
    asm volatile("" ::: "memory");
    u8 x = F(F(*a0, 40, u8*), 47, u8);
    if (x) {
        void* o = F(*a0, 12, void*);
        VT(o, 30)(o, x, 0, 0);
    }
    VTv(a1, 25)(a1, r);
    func_0018ca10(r);  // alloc_from_pool_magic
}
}

namespace w280_a1 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct QMat {
    QWord r[4];
    QMat() {}
    QMat& operator=(const QMat& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QWord Add(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QWord Cross(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void CrossTo(QWord* r, const QWord& a, const QWord& b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)"
                 : : "r"(r), "r"(&a), "r"(&b) : "memory");
}
static inline QWord MulV(const QMat& m, const QWord& v)
{
    QWord r;
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                 : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
extern "C" {
f32 func_002f8960(f32);
f32 func_002f87c0(f32);
QMat func_0011b558(const QWord*);
void func_001074c0(u8* o, s32 mode, f32 ang)
{
    QWord* pos = (QWord*)(o + 80);
    QWord* ctr = (QWord*)(o + 96);
    QWord d, ax;
    QMat m;
    QWord* pax = &ax;
    QMat* pm = &m;
    d = Sub(*pos, *ctr);
    switch (mode) {
    case 0: {
        f32 s = func_002f8960(ang);
        f32 c = func_002f87c0(ang);
        f32 x = c * d.f[0] + s * d.f[2];
        f32 z = -s * d.f[0] + c * d.f[2];
        *(f32*)(o + 80) = *(f32*)(o + 96) + x;
        *(f32*)(o + 88) = *(f32*)(o + 104) + z;
        break;
    }
    case 1: {
        CrossTo(pax, d, *(QWord*)(o + 112));
        ax.f[3] = ang;
        *pm = func_0011b558(pax);
        *pos = Add(*ctr, MulV(*pm, d));
        break;
    }
    }
}
}
}

namespace w280_a2 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct QMat {
    QWord r[4];
    QMat() {}
    QMat& operator=(const QMat& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void MulMat(QMat* r, const QMat* a, const QMat* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tvmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\tvmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\tvmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\tsqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                 : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline QMat Mul(const QMat& a, const QMat& b)
{
    QMat r;
    MulMat(&r, &a, &b);
    return r;
}
typedef void (*VF2)(u8*, QMat*);
extern "C" {
QWord func_0017fe10(u8*, f32);
void func_0011b6a8(QMat*);
QMat* func_0011b720(QMat*, f32);
void func_00193e88(u8* o)
{
    QWord v;
    QMat m;
    QMat* pm = &m;
    v = func_0017fe10(o + 320, -1.0f);
    func_0011b6a8(pm);
    pm->r[3].f[0] = -v.f[0];
    pm->r[3].f[1] = -v.f[1];
    pm->r[3].f[2] = -v.f[2];
    *(QMat*)(o + 1712) = Mul(*(QMat*)(o + 64), *func_0011b720(pm, -v.f[3]));
    *(QWord*)(o + 1840) = *(QWord*)(o + 112);
    if (*(u32*)(o + 1416) & 0x8000000)
        ((VF2)((*(void***)o)[32]))(o, (QMat*)(o + 1712));
}
}
}

namespace w280_a3 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(f32 x, f32 y, f32 z, f32 w) { f[0] = x; f[1] = y; f[2] = z; f[3] = w; }
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline void QZero(QWord* p)
{
    asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p) : "memory");
}
extern "C" u8* D_00361f60;
extern "C" {
void func_0016aef0(u8*, QWord*);
QWord* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_0016ace0(u8*, QWord*);
void func_002dff60(u8*, u8*);
void func_002e0230(u8*, u8*);
void func_002deda8(u8*, u8*);
f32 func_002de6e8(u32);
f32 func_002dc248(u8*);
void func_002dfcb0(u8* a, u8* b)
{
    u8* g = D_00361f60;
    if (!g) return;
    {
        QWord v(0.0f, 0.0f, -1.0f, 0.0f);
        func_0016aef0(b, &v);
    }
    QWord p = *func_0016c028(b);  // obj_get_attach_or_alt
    p.f[2] = 0.0f;
    func_0016ace0(b, &p);
    if (*(u32*)(a + 72)) func_002dff60(a, b);
    else func_002e0230(a, b);
    if (*(u32*)(a + 72)) {
        QZero((QWord*)(b + 16));
        QWord w = *func_0016c028(b);  // obj_get_attach_or_alt
        w.f[1] = func_002de6e8(*(u32*)(a + 72));
        func_0016ace0(b, &w);
    } else {
        func_002deda8(a, b);
    }
    if (*(f32*)(a + 40) <= 0.0f) {
        if (func_002dc248(g) <= p.f[1]) *(u8*)(a + 84) = 0;
    }
    u8 r = 0;
    if (*(u8*)(a + 84)) {
        if (p.f[1] < func_002dc248(g)) r = 1;
    }
    *(u8*)(g + 0x8000 + 108) = r;
    *(u32*)(b + 264) &= 0xfffeffff;
}
}
}

namespace w280_a4 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(f32 x, f32 y, f32 z, f32 w) { f[0] = x; f[1] = y; f[2] = z; f[3] = w; }
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
union FU { f32 f; s32 i; };
struct P1 { s32 n0; s32 n1; f32 f8; f32 f12; f32 f16; f32 f20; };
extern "C" {
QWord func_002d38e8(u32);
u8* func_001cbe30(QWord*, u32, s32);
void func_002d3568(u32 a, P1* p, u32 c)
{
    s32* pn1 = &p->n1;
    f32* pf12 = &p->f12;
    f32* pf8 = &p->f8;
    f32* pf16 = &p->f16;
    QWord q = func_002d38e8(a);
    s32* pn0 = &p->n0;
    for (s32 i = 0; i < *pn0; i++) {
        f32 y = (f32)i * *pf8;
        for (s32 j = 0; j < *pn1; j++) {
            u8* e = func_001cbe30(&q, c, 0);
            if (e) {
                f32 v = (f32)j * 6.2831854820251465f / (f32)*pn1 - 3.1415927410125732f;
                *(QWord*)(e + 112) = q;
                ((FU*)(e + 160))->f = v;
                ((FU*)(e + 168))->f = *pf16;
                ((FU*)(e + 172))->f = 0.0f;
                ((FU*)(e + 180))->f = *pf12;
                ((FU*)(e + 96))->f = y;
                ((FU*)(e + 100))->f = 120.0f;
                ((FU*)(e + 104))->f = p->f20;
                ((FU*)(e + 64))->f = 0.0f;
            }
        }
    }
}
}
}

namespace w280_a5 {
static inline f32 VRand(void)
{
    f32 u;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(u) : : "$8");
    return u;
}
struct S1 { s32 id; s32 off; void* a; void* b; void* c; u8 two; };
struct T1 { u8 pad[12]; s32* p; };
extern "C" s32 D_01d9ea9c;
extern "C" u8* D_01d9e6e0;
extern "C" s32 D_01d9e360[];
union FU { f32 f; s32 i; };
extern "C" {
s32 func_001ed7d8(void*, f32);  // int_float_mul_m1_b
void func_001ed7f0(u8* o, S1* s, T1* t)
{
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (s->id != *(s32*)(o + 12)) return;
    f32 r = VRand();
    if (s->two) r = (r + VRand()) * 0.5f;
    FU* pr = (FU*)(o + *t->p + 160);
    pr->f = r;
    s32* d;
    if (s->off != -1) d = (s32*)(o + s->off + 160);
    else d = D_01d9e360;
    f32 v = pr->f;
    d[0] += func_001ed7d8(s->a, v);  // int_float_mul_m1_b
    d[1] += func_001ed7d8(s->b, pr->f);  // int_float_mul_m1_b
    d[2] += func_001ed7d8(s->c, pr->f);  // int_float_mul_m1_b
}
}
}
