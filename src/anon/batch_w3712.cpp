#include "../common/types.h"

/* ---- 001cbcf0: spawn an object at p + rot * (0, -height(i), 0, 0) ---- */
struct QWord {
    f32 x, y, z, w;
    QWord() {}
} __attribute__((aligned(16)));
struct Mtx { QWord r[4]; };
struct Obj { u8 pad[16]; void* fn; u8 pad2[20]; s32 flags; };
/* r = m * v (VU0) */
static inline void MulMV(QWord* r, const Mtx* m, const QWord* v)
{
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
        : : "r"(r), "r"(m), "r"(v) : "memory");
}
/* r = a + b (VU0) */
static inline void VAdd(QWord* r, const QWord* a, const QWord* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(r), "r"(a), "r"(b) : "memory");
}
/* Sets d and returns the address of the product temporary t. The la (partial asm) takes the
   address after y is known, so it is not kept in a saved register across the call (orig: addiu t7,sp,64). */
static inline QWord* SetVT(QWord* d, f32 x, f32 y, f32 z, f32 w, QWord* t)
{
    QWord* tr;
    asm("la %0,%1" : "=r"(tr) : "m"(*t), "f"(y));
    d->x = x; d->y = y; d->z = z; d->w = w;
    return tr;
}

/* ---- 001cd548: static init/teardown of D_01d499b0 and two 0xffff-filled id structs ---- */
struct G1cd548 { u8 pad0[12]; u8 a; u8 pad1[9456 - 13]; u8 b; u8 pad2[16364 - 9457]; u8 c;
    u8 pad3[16796 - 16365]; u8 d; u8 pad4[21920 - 16797]; u8 e; u8 pad5[0x100e0 - 21921]; u8 f; };
extern G1cd548 D_01d499b0;

/* ---- 001e3c18 ---- */
struct E1e3c18 { u8 pad[0x88]; void* x88; u8* x8c; u8 pad2[0xc]; s16 x9c; s16 x9e; };
struct NoTail1e3c18 { ~NoTail1e3c18() {} };

extern "C" {
extern s32 D_00351fe4;
extern s32 D_00361f60;
extern QWord D_0036e180[];
void D_001cab08(void);
void func_0011b6a8(Mtx*);
void func_0011b7b0(Mtx*, void*);
f32 func_001ca8e0(s32);
Obj* func_001cbc50(s32, QWord*, QWord*, s32);
s32 func_002ceb08(void);

Obj* func_001cbcf0(QWord* p, void* rot, s32 i) {
    Obj* r = 0;
    if (D_00351fe4) {
        Mtx m;
        /* s1 is saved but unused in the original: pin a dummy to it */
        register s32 k asm("$17");
        asm("" : "=r"(k));
        func_0011b6a8(&m);
        func_0011b7b0(&m, rot);
        QWord t;
        QWord v;
        QWord* tr = SetVT(&v, 0.0f, -func_001ca8e0(i), 0.0f, 0.0f, &t);
        MulMV(tr, &m, &v);
        VAdd(&v, p, tr);
        Obj* o = func_001cbc50(D_00351fe4, &D_0036e180[i], &v, 0);
        o->fn = (void*)D_001cab08;
        o->flags |= 1;
        if (D_00361f60 && func_002ceb08() == 2) {
            asm("" : : "r"(k));
            o->flags |= 2;
        }
        r = o;
    }
    return r;
}

void func_00319bd0(void*);
void func_00188e08(void*);
void func_00319870(void*);
void func_00321068(void*);
void func_002e7768(void*);
void func_001e0868(void*);
void f_002e77a0(void*) asm("_Z13func_002e77a0Pv");
void wt_001cd548(u32 init, u32 prio, u32, u32) asm("_Z16wtarget_001cd548jjjj");
void wt_001cd548(u32 init, u32 prio, u32, u32)
{
    if (prio == 0xffff && init == 1) {
        /* member constructors */
        G1cd548* g = &D_01d499b0;
        asm("" : "+r"(g));
        func_00319bd0(&g->a);
        func_00188e08(&g->b);
        func_00319870(&g->c);
        func_00321068(&g->d);
        func_002e7768(&g->e);
        func_001e0868(&g->f);
        /* the two id structs' ctors fill a, b, c with 0xffff (prio); the store
           order (c, c, a, a, b, b) needs hand-written instructions */
        register u32 t4 asm("$12");
        register u32 t5 asm("$13");
        register u32 t6 asm("$14");
        register u32 t7 asm("$15");
        asm volatile("lui %0,%%hi(D_01d5a970)" : "=r"(t6));
        asm volatile("lui %0,%%hi(D_01d5a974)" : "=r"(t7));
        asm volatile("addiu %0,%1,%%lo(D_01d5a970)" : "=r"(t5) : "r"(t6));
        asm volatile("addiu %0,%1,%%lo(D_01d5a974)" : "=r"(t4) : "r"(t7));
        asm volatile("sb %0,2(%1)" : : "r"(prio), "r"(t5) : "memory");
        asm volatile("sh %0,4(%1)" : : "r"(prio), "r"(t4) : "memory");
        asm volatile("sh %0,%%lo(D_01d5a974)(%1)" : : "r"(prio), "r"(t7) : "memory");
        asm volatile("sb %0,%%lo(D_01d5a970)(%1)" : : "r"(prio), "r"(t6) : "memory");
        asm volatile("sb %0,1(%1)" : : "r"(prio), "r"(t5) : "memory");
        asm volatile("sh %0,2(%1)" : : "r"(prio), "r"(t4) : "memory");
    }
    struct NoTail { ~NoTail() {} } nt;
    if (prio == 0xffff && init == 0) {
        G1cd548* g = &D_01d499b0;
        asm("" : "+r"(g));
        f_002e77a0(&g->e);
    }
}

void* func_001e3650(void*);
void* f_001e3660(void*, s32) asm("_Z13func_001e3660ji");
void* func_001e38f8(void*, void*, s32, s32);
void* func_001e3a88(void*, void*, s32, s32);
void func_001e3c18(E1e3c18* p) {
    NoTail1e3c18 nt;
    register s32 a asm("$18");
    register s32 b asm("$17");
    void* v;
    /* hand-written loads: x9e must be read last, through the saved copy of p in s0 */
    asm("lh %0,156(%1)" : "=r"(a) : "r"(p));
    v = p->x88;
    asm("lh %0,158($16)" : "=r"(b) : "r"(p), "r"(v));
    v = func_001e3650(v);
    v = f_001e3660(v, 2);
    v = func_001e38f8(v, p->x8c + 0xc0, a, b);
    func_001e3a88(v, p->x8c + 0xd0, a, b);
}
}
