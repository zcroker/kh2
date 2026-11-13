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
// 001cd548: static init of the prize work object, moved to src/anon/unit_001cd548.cpp

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
