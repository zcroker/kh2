// Linked unit 0x1ca8e0-0x1cc008: effect file with globals 0x351fd8.., vtable 0x351ff0, the static
// init 0x1cbf20 and its _GLOBAL__I_ stub 0x1cbfe8 (written here, with 8 small gap wrappers).
// .rodata at 0x36e140. -fno-strict-aliasing (from the _nsa old copies). 0x1cc008 is the C2 copy of
// the next file's constructor (unit_001cc048.cpp) and stays outside.

#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"

// ---- 001ca8e0 from src/anon/tiny_auto80_queue.cpp
namespace n001ca8e0 {
extern u8* D_0036e180 asm("D_0036e180");
f32 func_001ca8e0(u32 a0) asm("_Z13func_001ca8e0j");
f32 func_001ca8e0(u32 a0) {
    a0 = a0 << 4;
    u8* p = (u8*)&D_0036e180 + a0;
    return *(f32*)(p + 4);
}
}  // namespace n001ca8e0

// ---- 001ca8f8 from src/anon/tiny_auto80_queue.cpp
namespace n001ca8f8 {
extern u8  D_00350000 asm("D_00350000");
void func_001ca8f8(f32 a0, f32 a1) asm("_Z13func_001ca8f8ff");
void func_001ca8f8(f32 a0, f32 a1) {
    *(f32*)((u8*)&D_00350000 + 8152u) = a0;
    *(f32*)((u8*)&D_00350000 + 8160u) = a1;
}
}  // namespace n001ca8f8

// ---- 001ca910 from src/anon/tiny_auto80_queue.cpp
namespace n001ca910 {
extern u8  D_00350000 asm("D_00350000");
void func_0016be98(...) asm("func_0016be98");
void func_002bc188(...) asm("func_002bc188");
void func_001ca910(u8* a0) asm("_Z13func_001ca910Ph");
void func_001ca910(u8* a0) {
    u8 tmp[16];
    u8* s0 = a0;
    func_0016be98(tmp, *(u32*)((u8*)&D_00350000 - 5816u));
    u8* t7 = *(u8**)(s0 + 76);
    func_002bc188(*(u32*)(t7 + 12), tmp);
}
}  // namespace n001ca910

// ---- 001ca950 from src/anon/batch_w14.cpp
namespace n001ca950 {
void func_001c6fa8(void*, void*, void*, void*, void*) asm("func_001c6fa8");
void func_001ca950(u8* p, void* a, void* b, void* c, void* d, u32 e) asm("func_001ca950");
void func_001ca950(u8* p, void* a, void* b, void* c, void* d, u32 e) {
    func_001c6fa8(p, a, b, c, d);
    *(u32*)(p + 84) = e;
    *(u32*)(p + 88) = 0;
}
}  // namespace n001ca950

// ---- 001ca988 from src/anon/batch_w15.cpp
namespace n001ca988 {
void func_001c6fa8(u8*, u32, u32, u32, u32) asm("func_001c6fa8");
void func_001ca988(u8* p, u32 a1, u32 a2, u32 a3, u32 a4, u32 x) asm("func_001ca988");
void func_001ca988(u8* p, u32 a1, u32 a2, u32 a3, u32 a4, u32 x) {
    func_001c6fa8(p, a1, a2, a3, a4);
    *(u32*)(p + 84) = x;
    *(u32*)(p + 88) = 0;
}
}  // namespace n001ca988

// ---- 001ca9c0 from src/anon/tiny_auto80_fptr4.cpp
namespace n001ca9c0 {
u32 func_002cf1b8(u32, u32, u32, u32) asm("_Z13func_002cf1b8jjjj");
u32 func_001ca9c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001ca9c0jjjj");
u32 func_001ca9c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_002cf1b8)(u32, u32, u32, u32) = func_002cf1b8;
    r2 = fp_call4_002cf1b8(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001ca9c0

// ---- 001ca9e0 from src/anon/batch_w8002_nsa.cpp
namespace n001ca9e0 {
#define QCOPY(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
struct QV1832 {
    f32 x, y, z, w;
    QV1832() {}
    QV1832(const QV1832& o) { QCOPY(this, &o); }
    QV1832& operator=(const QV1832& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct QM1832 {
    QV1832 r[4];
    QV1832 operator*(const QV1832& v) const {
        QV1832 o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
static inline f32 norm1832(QV1832* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct Obj1832 {
    QV1832 pos;
    void* fn;
    u8 pad14[0x1c];
    QV1832 dir;
    f32 f40;
    u8 pad44[8];
    s32* p4c;
    u8 pad50[0x68];
    s32 b8;
};
extern u8 D_001cad40 asm("D_001cad40");
extern f32 D_00351fd8 asm("D_00351fd8");
extern void* D_00361f60 asm("D_00361f60");
s32 func_001cbab0() asm("func_001cbab0");
s32 func_001064a8(s32) asm("func_001064a8");
void** func_002d1260() asm("func_002d1260");
bool func_001ca9c0(Obj1832*) asm("func_001ca9c0");
void func_001ca910(Obj1832*) asm("func_001ca910");
bool func_001ca9e0(Obj1832* self) asm("func_001ca9e0");
bool func_001ca9e0(Obj1832* self) {
    if (func_001cbab0()) {
        QV1832* d = &self->dir;
        self->b8 = func_001064a8(2);
        void** o = func_002d1260();
        QM1832* m = ((QM1832* (*)(void**))((void**)*o)[41])(o);
        *d = *m * self->pos;
        self->dir.w = norm1832(d);
        self->f40 = D_00351fd8;
        self->fn = &D_001cad40;
        void* g = D_00361f60;
        ((void (*)(void*, s32, s32))((void**)*(void**)g)[10])(g, 1, *self->p4c);
        func_001ca910(self);
        return 1;
    }
    return !func_001ca9c0(self);
}
}  // namespace n001ca9e0

// ---- 001cab08 gap: calls 001ca9e0 and returns its result
namespace n001cab08 {
s32 func_001ca9e0(void*) asm("func_001ca9e0");
s32 func_001cab08(void* p) asm("func_001cab08");
s32 func_001cab08(void* p) {
    struct NoTail { ~NoTail() {} } n;
    return func_001ca9e0(p);
}
}  // namespace n001cab08

// ---- 001cab28 from src/anon/batch_w2023_nsa.cpp
namespace n001cab28 {
void func_0011b6a8(void*) asm("_Z13func_0011b6a8Pv");
struct W2023V {
    f32 x, y, z, w;
    W2023V() {}
    W2023V(const W2023V& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W2023V& operator=(const W2023V& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    void operator*=(f32 k)
    {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                     : : "r"(this), "f"(k) : "$8", "memory");
    }
} __attribute__((aligned(16)));
struct W2023M {
    f32 m[4][4];
    W2023M() {}
    W2023M& operator=(const W2023M& o)
    {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline W2023M W2023Mul(const W2023M& l, const W2023M& r)
{
    W2023M d;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                 : : "r"(&d), "r"(&l), "r"(&r) : "memory");
    return d;
}
static inline W2023V W2023MulV(const W2023M& m, const W2023V& v)
{
    W2023V d;
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)"
                 : : "r"(&d), "r"(&m), "r"(&v) : "memory");
    return d;
}
struct W2023Ob {
    W2023V pos;           
    u8 pad10[6];
    u8 b16;              
    u8 pad17[0x19];
    W2023V vel;            
    f32 timer;           
    u8 pad44[0x74];
    s32 dir;              
};
struct W2023Pl;
typedef W2023M* (*W2023PlFn)(W2023Pl*);
struct W2023Pl { W2023PlFn* vt; };
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00351fd8 asm("D_00351fd8");
extern f32 D_00351fe0 asm("D_00351fe0");
W2023Pl* W2023_current(void) asm("_ZN2Ti8MGPlayer7currentEv");
s32 W2023_ctarget(W2023Pl*) asm("_Z17YS__OBJ__is_existjjjj");
void W2023_rotateY(W2023M*, f32) asm("_ZN2kn7FMatrix7rotateYEf");
f32 func_001cbf50(f32) asm("func_001cbf50");
s32 YS__PRIZEEFFECT_PO__phase_get(W2023Ob* o) asm("YS__PRIZEEFFECT_PO__phase_get");
s32 YS__PRIZEEFFECT_PO__phase_get(W2023Ob* o)
{
    W2023Pl* pl = W2023_current();
    f32 t;
    o->timer -= D_00349e10;
    if (o->timer <= 0.0f || !W2023_ctarget(pl)) return 0;
    t = o->timer / D_00351fd8;
    W2023V v = o->vel;
    v *= o->vel.w * t;
    f32 one = 1.0f;
    v.w = one;
    W2023M m;
    func_0011b6a8(&m);
    if (o->dir) W2023_rotateY(&m, func_001cbf50(D_00351fe0 * (one - t)));
    else W2023_rotateY(&m, func_001cbf50(-D_00351fe0 * (one - t)));
    m = W2023Mul(*pl->vt[40](pl), m);
    o->pos = W2023MulV(m, v);
    o->b16 = t * 255.0f;
    return 1;
}
}  // namespace n001cab28

// ---- 001cad40 gap: calls 001cab28 and returns its result
namespace n001cad40 {
s32 YS__PRIZEEFFECT_PO__phase_get(void*) asm("YS__PRIZEEFFECT_PO__phase_get");
s32 func_001cad40(void* p) asm("func_001cad40");
s32 func_001cad40(void* p) {
    struct NoTail { ~NoTail() {} } n;
    return YS__PRIZEEFFECT_PO__phase_get(p);
}
}  // namespace n001cad40

// ---- 001cad60 from src/anon/batch_w1941_nsa.cpp
namespace n001cad60 {
struct Q1941 { f32 x, y, z, w;
    Q1941() {}
    Q1941(const Q1941& o) { asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
static inline void qmuls1941(Q1941* d, f32 s) {
    asm volatile("lqc2 $vf1,0(%0)\n\tmfc1 $8,%1\n\tqmtc2 $8,$vf2\n\tvmulx.wxyz $vf1,$vf1,$vf2x\n\tsqc2 $vf1,0(%0)" : : "r"(d), "f"(s) : "$8", "memory");
}
static inline void qadd1941(Q1941* d, const Q1941* a, const Q1941* b) {
    asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvadd.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
struct Mot1941 { u8 pad[48]; Q1941 p; };
struct Tgt1941;
struct TgtVt1941 { void* f[40]; Mot1941* (*get)(Tgt1941*); };
struct Tgt1941 { TgtVt1941* vt; };
struct Ob1941 { Q1941 pos; u8 pad0[6]; u8 b22; u8 pad1[41]; f32 f64; u8 pad2[44]; Q1941 v112; u8 pad3[32]; f32 f160; u8 pad4[4]; f32 f168; f32 f172; };
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00351fd8 asm("D_00351fd8");
Tgt1941* func_002d1260(void) asm("func_002d1260");
s32 YS__OBJ__is_exist(Tgt1941*) asm("YS__OBJ__is_exist");
f32 func_001cbf50(f32) asm("func_001cbf50");
f32 cosf(f32) asm("cosf");
f32 sinf(f32) asm("sinf");
s32 func_001cad60(Ob1941* self) asm("func_001cad60");
s32 func_001cad60(Ob1941* self) {
    Tgt1941* t = func_002d1260();
    self->f64 -= D_00349e10;
    if (self->f64 <= 0.0f || !YS__OBJ__is_exist(t)) return 0;
    self->f160 += self->f168 * D_00349e10;
    f32 k = self->f64 / D_00351fd8;
    f32 a = func_001cbf50(self->f160);
    self->pos.x = cosf(a);
    self->pos.y = sinf(a);
    self->pos.z = 0.0f;
    qmuls1941(&self->pos, self->f172 * k);
    Q1941 v = self->v112;
    qmuls1941(&v, v.w * k);
    Mot1941* m = t->vt->get(t);
    Q1941 u;
    qadd1941(&u, &v, &m->p);
    qadd1941(&self->pos, &self->pos, &u);
    self->b22 = (s32)(k * 255.0f);
    return 1;
}
}  // namespace n001cad60

// ---- 001caee0 gap: calls 001cad60 and returns its result
namespace n001caee0 {
s32 func_001cad60(void*) asm("func_001cad60");
s32 func_001caee0(void* p) asm("func_001caee0");
s32 func_001caee0(void* p) {
    struct NoTail { ~NoTail() {} } n;
    return func_001cad60(p);
}
}  // namespace n001caee0

// ---- 001caf00 from src/anon/batch_w1567.cpp
namespace n001caf00 {
struct QV1567b {
    f32 x, y, z, w;
    QV1567b() {}
    QV1567b(const QV1567b& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QV1567b& operator=(const QV1567b& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    void scale(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(s) : "$8", "memory");
    }
} __attribute__((aligned(16)));
struct QM1567b {
    QV1567b r[4];
    QV1567b operator*(const QV1567b& v) const {
        QV1567b o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Pl1567;
struct PlVt1567 { u8 pad[0xa0]; u8* (*get)(Pl1567*); };
struct Pl1567 { PlVt1567* vt; };
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00351fd8 asm("D_00351fd8");
extern f32 D_00351fe0 asm("D_00351fe0");
Pl1567* func_002d1260(void) asm("func_002d1260");
s32 YS__OBJ__is_exist(Pl1567*) asm("YS__OBJ__is_exist");
void func_0011b6a8(QM1567b*) asm("func_0011b6a8");
void func_0011b768(QM1567b*, f32) asm("func_0011b768");
f32 func_001cbf50(f32) asm("func_001cbf50");
s32 uc1567(u8* o, u32, u32, u32) asm("_Z39YS__PRIZEEFFECT_PO__phase_get_po06_falljjjj");
s32 uc1567(u8* o, u32, u32, u32) {
    Pl1567* pl = func_002d1260();
    *(f32*)(o + 0x40) -= D_00349e10;
    if (*(f32*)(o + 0x40) <= 0.0f || !YS__OBJ__is_exist(pl)) return 0;
    f32 t = *(f32*)(o + 0x40) / D_00351fd8;
    QV1567b v(*(QV1567b*)(o + 0x90));
    v.scale(*(f32*)(o + 0x9c) * t);
    v.w = 1.0f;
    QM1567b m;
    func_0011b6a8(&m);
    func_0011b768(&m, func_001cbf50(D_00351fe0 * (1.0f - t)));
    m.r[3] = *(QV1567b*)(pl->vt->get(pl) + 0x30);
    *(QV1567b*)o = m * v;
    *(s8*)(o + 0x16) = (s32)(t * 255.0f);
    return 1;
}
}  // namespace n001caf00

// ---- 001cb088 gap: calls 001caf00 and returns its result
namespace n001cb088 {
s32 YS__PRIZEEFFECT_PO__phase_get_po06_fall(void*) asm("_Z39YS__PRIZEEFFECT_PO__phase_get_po06_falljjjj");
s32 func_001cb088(void* p) asm("func_001cb088");
s32 func_001cb088(void* p) {
    struct NoTail { ~NoTail() {} } n;
    return YS__PRIZEEFFECT_PO__phase_get_po06_fall(p);
}
}  // namespace n001cb088

// ---- 001cb0a8 from src/anon/batch_w1800.cpp
namespace n001cb0a8 {
struct B0a8V { f32 x, y, z, w; } __attribute__((aligned(16)));
void* b0a8_current(void) asm("_ZN2Ti8MGPlayer7currentEv");
B0a8V* YS__OBJ__get_pos(void*) asm("YS__OBJ__get_pos");
static inline __attribute__((always_inline)) f32 b0a8_normalize(B0a8V* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline __attribute__((always_inline)) void b0a8_scale(B0a8V* v, f32 k) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(v), "f"(k) : "$8", "memory");
}
static inline __attribute__((always_inline)) void b0a8_add(B0a8V* d, B0a8V* a, B0a8V* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline __attribute__((always_inline)) void sub_B(B0a8V* a, B0a8V* b, B0a8V* d) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
bool func_001cb0a8(B0a8V* self) asm("func_001cb0a8");
bool func_001cb0a8(B0a8V* self) {
    B0a8V d;
    sub_B(self, YS__OBJ__get_pos(b0a8_current()), &d);
    f32 len = b0a8_normalize(&d);
    if (len < 15.0f) return 0;
    if (6.0f < len) len = 6.0f;
    b0a8_scale(&d, len);
    b0a8_add(self, self, &d);
    return 1;
}
}  // namespace n001cb0a8

// ---- 001cb180 from src/anon/tiny_auto80_fptr4.cpp
namespace n001cb180 {
u32 YS__PRIZEEFFECT_PO__phase_get_po06_fall(u32, u32, u32, u32) asm("_Z39YS__PRIZEEFFECT_PO__phase_get_po06_falljjjj");
u32 func_001cb180(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001cb180jjjj");
u32 func_001cb180(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_001caf00)(u32, u32, u32, u32) = YS__PRIZEEFFECT_PO__phase_get_po06_fall;
    r2 = fp_call4_001caf00(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001cb180

// ---- 001cb1a0 from src/anon/batch_w1800_nsa.cpp
namespace n001cb1a0 {
struct B1a0Mgr;
struct B1a0MgrVt { u8 pad[0x28]; void (*f28)(B1a0Mgr*, s32, s32); };
struct B1a0Mgr { B1a0MgrVt* vt; };
struct B1a0Obj { f32 pos[4]; void* fn; u8 pad[0x40 - 0x14]; f32 timer; u8 pad2[0x4c - 0x44]; s32* id; };
extern B1a0Mgr* D_00361f60 asm("D_00361f60");
extern f32 D_00349e10 asm("D_00349e10");
f32* func_002d1f30(B1a0Mgr*) asm("func_002d1f30");
s32 func_001cbab0(B1a0Obj*) asm("func_001cbab0");
void func_001ca910(B1a0Obj*) asm("func_001ca910");
bool func_001ca9c0(B1a0Obj*) asm("func_001ca9c0");
void func_001cb180(void) asm("func_001cb180");
static inline __attribute__((always_inline)) void vadd(f32* d, f32* s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(s) : "memory");
}
bool func_001cb1a0(B1a0Obj* self) asm("func_001cb1a0");
bool func_001cb1a0(B1a0Obj* self) {
    if (D_00361f60) {
        vadd(self->pos, func_002d1f30(D_00361f60));
    }
    if (self->timer <= 0.0f) {
        if (func_001cbab0(self)) {
            self->fn = (void*)func_001cb180;
            D_00361f60->vt->f28(D_00361f60, 1, *self->id);
            func_001ca910(self);
            return 1;
        }
    }
    self->timer -= D_00349e10;
    return !func_001ca9c0(self);
}
}  // namespace n001cb1a0

// ---- 001cb278 from src/anon/batch_w1985_nsa.cpp
namespace n001cb278 {
struct W1985Vec { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void w1985_vadd(W1985Vec* d, const W1985Vec* a) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(a) : "memory");
}
static inline void w1985_vsub(W1985Vec* d, const W1985Vec* a) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(a) : "memory");
}
static inline void w1985_vscale(W1985Vec* v, f32 s) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(v), "f"(s) : "$8", "memory");
}
static inline f32 w1985_vnorm(W1985Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct W1985W1985MgrVt { void* f[10]; void (*fn40)(void*, s32, s32); };
struct W1985Mgr { W1985W1985MgrVt* vt; };
struct W1985PlVt { void* f[40]; u8* (*fn160)(void*); };
struct W1985Pl { W1985PlVt* vt; };
struct W1985Self {
    W1985Vec pos;                
    void (*fn)(void*);       
    u8 pad14[0x40 - 0x14];
    f32 time;                
    u8 pad44[8];
    s32* p4c;                
    u8 pad50[0x10];
    f32 t60, t64, t68;       
    u8 pad6c[4];
    f32 v70[3];              
    f32 f7c;                 
    u8 pad80[0x20];
    f32 fa0, fa4, fa8, fac, fb0, fb4;
};
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00351fd8 asm("D_00351fd8");
extern W1985Mgr* D_00361f60 asm("D_00361f60");
W1985Vec* func_002d1f30(W1985Mgr*) asm("func_002d1f30");
f32 func_001cbf50(f32) asm("func_001cbf50");
f32 cosf(f32) asm("cosf");
f32 sinf(f32) asm("sinf");
s32 func_001cbab0(W1985Self*) asm("func_001cbab0");
W1985Pl* func_002d1260(void) asm("func_002d1260");
void func_001ca910(W1985Self*) asm("func_001ca910");
bool func_001ca9c0(W1985Self*) asm("func_001ca9c0");
void func_001caee0(void*) asm("func_001caee0");
u32 YS__PRIZEEFFECT_PO__phase_move_po06_rot(W1985Self* self, u32, u32, u32) asm("_Z39YS__PRIZEEFFECT_PO__phase_move_po06_rotjjjj");
u32 YS__PRIZEEFFECT_PO__phase_move_po06_rot(W1985Self* self, u32, u32, u32)
{
    f32 a;
    if (self->time >= self->t60) {
        self->fa0 += self->fa8 * D_00349e10;
        self->fac += self->fb4 * D_00349e10;
    }
    if (D_00361f60) w1985_vadd((W1985Vec*)self->v70, func_002d1f30(D_00361f60));
    a = func_001cbf50(self->fa0);
    self->pos.x = cosf(a);
    self->pos.y = sinf(a);
    self->pos.z = 0.0f;
    w1985_vscale(&self->pos, self->fac);
    w1985_vadd(&self->pos, (W1985Vec*)self->v70);
    if (self->time > self->t68 && func_001cbab0(self)) {
        W1985Pl* p = func_002d1260();
        w1985_vsub((W1985Vec*)self->v70, (W1985Vec*)(p->vt->fn160(p) + 48));
        self->f7c = w1985_vnorm((W1985Vec*)self->v70);
        self->time = D_00351fd8;
        self->fn = func_001caee0;
        D_00361f60->vt->fn40(D_00361f60, 1, *self->p4c);
        func_001ca910(self);
        return 1;
    }
    self->time += D_00349e10;
    if (self->time < self->t64) return 1;
    return !func_001ca9c0(self);
}
}  // namespace n001cb278

// ---- 001cb470 from src/anon/batch_w2353_nsa.cpp
namespace n001cb470 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { QCOPY(this, &o); }
    QV& operator=(const QV& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QV ScaleQ(const QV& a, f32 k) {
    QV r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline void ScaleQIn(QV* a, f32 k) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(a), "f"(k) : "$8", "memory");
}
static inline void AddIn(QV* a, const QV& b) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(a), "r"(&b) : "memory");
}
static inline QV SubQ(const QV& a, const QV& b) {
    QV r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 NormQ(QV* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct CB470 {
    QV pos;
    u32 f10;
    u8 pad14[0x2c];
    f32 t;
    u8 pad44[8];
    s32* f4c;
    u8 pad50[0x10];
    f32 f60;
    f32 f64;
    f32 f68;
    u8 pad6c[0x14];
    QV accel;
    QV vel;
};
extern void* D_00361f60 asm("D_00361f60");
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00351fd8 asm("D_00351fd8");
void func_001cb088(void) asm("func_001cb088");
void func_001ca910(CB470*) asm("func_001ca910");
bool func_001ca9c0(CB470*) asm("func_001ca9c0");
s32 func_001cbab0(CB470*) asm("func_001cbab0");
void* func_002d1260(void) asm("func_002d1260");
QV* func_002d1f30(void*) asm("func_002d1f30");
typedef void* (*CB470Fa0)(void*);
typedef void (*CB470F28)(void*, s32, s32);
s32 u_call4_001cb470(CB470* o) asm("_Z16u_call4_001cb470jjjj");
s32 u_call4_001cb470(CB470* o) {
    if (o->t >= o->f60) {
        QV v = o->vel;
        ScaleQIn(&v, v.w);
        AddIn(&o->pos, ScaleQ(v, D_00349e10));
        AddIn(&v, ScaleQ(o->accel, D_00349e10));
        v.w = NormQ(&v);
        o->vel = v;
    }
    if (D_00361f60) {
        AddIn(&o->pos, *func_002d1f30(D_00361f60));
    }
    if (o->t > o->f68 && func_001cbab0(o)) {
        {
            QV* pv = &o->vel;
            void* x = func_002d1260();
            *pv = SubQ(o->pos, *(QV*)((u8*)((CB470Fa0)(*(void***)x)[0xa0 / 4])(x) + 48));
            f32 len = NormQ(pv);
            o->vel.w = len;
            s32* q = o->f4c;
            o->t = D_00351fd8;
            o->f10 = (u32)func_001cb088;
            ((CB470F28)(*(void***)D_00361f60)[0x28 / 4])(D_00361f60, 1, *q);
            func_001ca910(o);
            return 1;
        }
    }
    o->t += D_00349e10;
    if (o->t < o->f64) return 1;
    return !func_001ca9c0(o);
}
}  // namespace n001cb470

// ---- 001cb6c0 gap: calls 001cb1a0 and returns its result
namespace n001cb6c0 {
s32 func_001cb1a0(void*) asm("func_001cb1a0");
s32 func_001cb6c0(void* p) asm("func_001cb6c0");
s32 func_001cb6c0(void* p) {
    struct NoTail { ~NoTail() {} } n;
    return func_001cb1a0(p);
}
}  // namespace n001cb6c0

// ---- 001cb6e0 from src/anon/tiny_auto80_fptr4.cpp
namespace n001cb6e0 {
u32 YS__PRIZEEFFECT_PO__phase_move_po06_rot(u32, u32, u32, u32) asm("_Z39YS__PRIZEEFFECT_PO__phase_move_po06_rotjjjj");
u32 func_001cb6e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001cb6e0jjjj");
u32 func_001cb6e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_001cb278)(u32, u32, u32, u32) = YS__PRIZEEFFECT_PO__phase_move_po06_rot;
    r2 = fp_call4_001cb278(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001cb6e0

// ---- 001cb700 from src/anon/tiny_auto80_fptr4.cpp
namespace n001cb700 {
u32 func_001cb470(u32, u32, u32, u32) asm("_Z13func_001cb470jjjj");
u32 func_001cb700(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001cb700jjjj");
u32 func_001cb700(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_001cb470)(u32, u32, u32, u32) = func_001cb470;
    r2 = fp_call4_001cb470(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001cb700

// ---- 001cb720 from src/anon/batch_w1944_gnsa.cpp
namespace n001cb720 {
struct W1944QV {
    f32 x, y, z, w;
    W1944QV() {}
    W1944QV(const W1944QV& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1944QV& operator*=(f32 k) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    W1944QV& operator+=(const W1944QV& b) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    W1944QV operator+(const W1944QV& b) const {
        W1944QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1944CamPos { u8 pad[48]; W1944QV pos; };
struct W1944Cam;
struct W1944CamVt { u8 pad[160]; W1944CamPos* (*get)(W1944Cam*); };
struct W1944Cam { W1944CamVt* vt; };
struct W1944Fx {
    W1944QV v;
    u8 pad10[6];
    s8 alpha;
    u8 pad17[0x40 - 0x17];
    f32 time;
    u8 pad44[0x70 - 0x44];
    W1944QV ofs;
    u8 pad80[0xa0 - 0x80];
    f32 ang;
    f32 pada4;
    f32 angVel;
    f32 scale;
};
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00351fd8 asm("D_00351fd8");
W1944Cam* func_002d1260() asm("func_002d1260");
s32 YS__OBJ__is_exist(W1944Cam*) asm("YS__OBJ__is_exist");
f32 func_001cbf50(f32) asm("func_001cbf50");
f32 cosf(f32) asm("cosf");
f32 sinf(f32) asm("sinf");
s32 func_001cb720(W1944Fx* o) asm("func_001cb720");
s32 func_001cb720(W1944Fx* o)
{
    W1944Cam* cam = func_002d1260();
    o->time -= D_00349e10;
    if (o->time <= 0.0f || YS__OBJ__is_exist(cam) == 0) return 0;
    o->ang += o->angVel * D_00349e10;
    f32 r = o->time / D_00351fd8;
    f32 a = func_001cbf50(o->ang);
    o->v.x = cosf(a);
    o->v.y = sinf(a);
    o->v.z = 0.0f;
    o->v *= o->scale * r;
    W1944QV t = o->ofs;
    t *= t.w * r;
    o->v += t + cam->vt->get(cam)->pos;
    o->alpha = (s8)(s32)(r * 255.0f);
    return 1;
}
}  // namespace n001cb720

// ---- 001cb8a0 gap: calls 001cb720 and returns its result
namespace n001cb8a0 {
s32 func_001cb720(void*) asm("func_001cb720");
s32 func_001cb8a0(void* p) asm("func_001cb8a0");
s32 func_001cb8a0(void* p) {
    struct NoTail { ~NoTail() {} } n;
    return func_001cb720(p);
}
}  // namespace n001cb8a0

// ---- 001cb8c0 from src/anon/batch_w3764_nsa.cpp
namespace n001cb8c0 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct VtA { u8 pad[0xa0]; V4* (*get)(void*); };
struct ObjA { VtA* vt; };
struct VtB { u8 pad[0x28]; void (*f)(void*, s32, s32); };
struct ObjB { VtB* vt; };
struct S {
    V4 v;                   
    void* state;            
    u8 p14[0x40 - 0x14];
    f32 t;                  
    u8 p44[0x4c - 0x44];
    s32* p4c;               
    u8 p50[0x60 - 0x50];
    f32 f60, f64, f68;
    u8 p6c[4];
    V4 v70;                 
    u8 p80[0xa0 - 0x80];
    f32 fa0, fa4, fa8, fac, fb0, fb4;
};
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00351fd8 asm("D_00351fd8");
extern ObjB* D_00361f60 asm("D_00361f60");
void func_001cb8a0() asm("func_001cb8a0");
void func_001ca910(S*) asm("func_001ca910");
s32 func_001ca9c0(S*) asm("func_001ca9c0");
s32 func_001cbab0(S*) asm("func_001cbab0");
f32 func_001cbf50(f32) asm("func_001cbf50");
ObjA* func_002d1260() asm("func_002d1260");
f32 cosf(f32) asm("cosf");
f32 sinf(f32) asm("sinf");
static inline __attribute__((always_inline)) void scl(V4* v, f32 s) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(v), "f"(s) : "$8", "memory");
}
static inline __attribute__((always_inline)) void add(V4* d, const V4* a) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(a) : "memory");
}
static inline __attribute__((always_inline)) void sub(V4* d, const V4* a) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(a) : "memory");
}
static inline __attribute__((always_inline)) f32 nrm(V4* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
s32 func_001cb8c0(S* o) asm("func_001cb8c0");
s32 func_001cb8c0(S* o) {
                                                                           
                                                                   
    register s32 d asm("$16");
    if (o->t >= o->f60) {
        o->fa0 += o->fa8 * D_00349e10;
        o->fac += o->fb4 * D_00349e10;
    }
    f32 a = func_001cbf50(o->fa0);
    o->v.x = cosf(a);
    o->v.y = sinf(a);
    *(s32*)&o->v.z = 0;
    asm ("" : "=r"(d));
    scl(&o->v, o->fac);
    asm ("" : : "r"(d));
    V4* q = &o->v70;
    add(&o->v, q);
    if (o->f68 < o->t) {
        if (func_001cbab0(o)) {
            ObjA* c = func_002d1260();
            V4* p = (V4*)((u8*)c->vt->get(c) + 48);
            sub(q, p);
            o->v70.w = nrm(q);
            o->t = D_00351fd8;
            o->state = (void*)func_001cb8a0;
            D_00361f60->vt->f(D_00361f60, 1, *o->p4c);
            func_001ca910(o);
            return 1;
        }
    }
    o->t += D_00349e10;
    if (o->t < o->f64) return 1;
    return (u8)(func_001ca9c0(o) ^ 1);
}
}  // namespace n001cb8c0

// ---- 001cba90 gap: calls 001cb8c0 and returns its result
namespace n001cba90 {
s32 func_001cb8c0(void*) asm("func_001cb8c0");
s32 func_001cba90(void* p) asm("func_001cba90");
s32 func_001cba90(void* p) {
    struct NoTail { ~NoTail() {} } n;
    return func_001cb8c0(p);
}
}  // namespace n001cba90

// ---- 001cbab0 from src/anon/auto80_199_queue.cpp
namespace n001cbab0 {
u32 func_001cbab0(Arg* a0) asm("_Z13func_001cbab0P3Arg");
u32 func_001cbab0(Arg* a0) {
    Obj* s0 = (Obj*)func_002d1260(a0);
    u32 t6 = 0;

    if (YS__OBJ__is_exist((u32)s0) == 0) {
        return t6;
    }

    if ((a0->flags & 1u) == 0) {
        return t6;
    }

    VirtFn fn = (VirtFn)s0->vtbl[42];
    t6 = fn(s0, a0);
    return t6;
}
}  // namespace n001cbab0

// ---- 001cbb18 from src/anon/tiny_jal_wrappers_reloc.cpp
namespace n001cbb18 {
u32 func_001a4db0(u32, u32, u32, u32) asm("_Z13func_001a4db0jjjj");
extern u8 D_00351ff0 asm("D_00351ff0");
u32 func_001cbb18(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001cbb18jjjj");
u32 func_001cbb18(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r6 = (u32)((s32)0u + (1280));
    r7 = (u32)((s32)0u + (192));
    r16 = r4;
    r2 = func_001a4db0(r4, r5, r6, r7);
    r15 = (u32)&D_00351ff0;
    r14 = (u32)(0x0035u << 16);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r14 + (s32)(8164)) = r16;
    return r2;
}
}  // namespace n001cbb18

// ---- 001cbb58 from src/anon/tiny_jal_wrappers_reloc.cpp
namespace n001cbb58 {
u32 func_001a4db0(u32, u32, u32, u32) asm("_Z13func_001a4db0jjjj");
extern u8 D_00351ff0 asm("D_00351ff0");
u32 func_001cbb58(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001cbb58jjjj");
u32 func_001cbb58(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r6 = (u32)((s32)0u + (1280));
    r7 = (u32)((s32)0u + (192));
    r16 = r4;
    r2 = func_001a4db0(r4, r5, r6, r7);
    r15 = (u32)&D_00351ff0;
    r14 = (u32)(0x0035u << 16);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r14 + (s32)(8164)) = r16;
    return r2;
}
}  // namespace n001cbb58

// ---- 001cbb98 from src/anon/tiny_auto80_fptr4.cpp
namespace n001cbb98 {
u32 func_001a4e30(u32, u32, u32, u32) asm("_Z13func_001a4e30jjjj");
extern u8 D_00351ff0 asm("D_00351ff0");
u32 func_001cbb98(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001cbb98jjjj");
u32 func_001cbb98(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14;
    r14 = (u32)&D_00351ff0;
    *(u32*)((u32)r4 + (s32)(0)) = r14;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r13 + (s32)(8164)) = 0u;
    u32 (*fp_call4_001a4e30)(u32, u32, u32, u32) = func_001a4e30;
    r2 = fp_call4_001a4e30(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001cbb98

// ---- 001cbbc8 from src/anon/tiny_auto80_fptr4.cpp
namespace n001cbbc8 {
u32 func_001a4e30(u32, u32, u32, u32) asm("_Z13func_001a4e30jjjj");
extern u8 D_00351ff0 asm("D_00351ff0");
u32 func_001cbbc8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001cbbc8jjjj");
u32 func_001cbbc8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14;
    r14 = (u32)&D_00351ff0;
    *(u32*)((u32)r4 + (s32)(0)) = r14;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r13 + (s32)(8164)) = 0u;
    u32 (*fp_call4_001a4e30)(u32, u32, u32, u32) = func_001a4e30;
    r2 = fp_call4_001a4e30(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001cbbc8

// ---- 001cbbf8 from src/anon/batch_w14.cpp
namespace n001cbbf8 {
void func_00105110(void*) asm("func_00105110");
void func_001a4e30(void*) asm("func_001a4e30");
extern void* D_00351ff0[] asm("D_00351ff0");
extern void* D_00351fe4 asm("D_00351fe4");
void func_001cbbf8(u8* p) asm("func_001cbbf8");
void func_001cbbf8(u8* p) {
    *(void**)p = D_00351ff0;
    D_00351fe4 = 0;
    func_001a4e30(p);
    func_00105110(p);
}
}  // namespace n001cbbf8

// ---- 001cbc38 gap: vtable 0x351ff0 last slot
namespace n001cbc38 {
s32 func_001cbab0(void*) asm("_Z13func_001cbab0P3Arg");
s32 func_001cbc38(void* self, void* o) asm("func_001cbc38");
s32 func_001cbc38(void* self, void* o) {
    return func_001cbab0(o);
}
}  // namespace n001cbc38

// ---- 001cbc50 from src/anon/batch_w66.cpp
namespace n001cbc50 {
u8* func_001db888(u8*, s32, void*) asm("func_001db888");
void func_001ca988(u8*, u8*, u32, u32, void*, u32) asm("func_001ca988");
void func_001cab08(void) asm("func_001cab08");
u8* func_001cbc50(u8* p, u32 a, u32 b, u32 c) asm("func_001cbc50");
u8* func_001cbc50(u8* p, u32 a, u32 b, u32 c) {
    u8* q = *(u8**)(p + 2548) + 20;
    if (!*(u32*)(q + 8)) return 0;
    u8* v = func_001db888(q, 192, __builtin_return_address(0));                      
    func_001ca988(v, p, a, b, (void*)func_001cab08, c);
    return v;
}
}  // namespace n001cbc50

// ---- 001cbcf0 from src/anon/batch_w3712.cpp
namespace n001cbcf0 {
struct QWord {
    f32 x, y, z, w;
    QWord() {}
} __attribute__((aligned(16)));
struct Mtx { QWord r[4]; };
struct Obj { u8 pad[16]; void* fn; u8 pad2[20]; s32 flags; };
static inline void MulMV(QWord* r, const Mtx* m, const QWord* v)
{
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
        : : "r"(r), "r"(m), "r"(v) : "memory");
}
static inline void VAdd(QWord* r, const QWord* a, const QWord* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline QWord* SetVT(QWord* d, f32 x, f32 y, f32 z, f32 w, QWord* t)
{
    QWord* tr;
    asm("la %0,%1" : "=r"(tr) : "m"(*t), "f"(y));
    d->x = x; d->y = y; d->z = z; d->w = w;
    return tr;
}
extern s32 D_00351fe4 asm("D_00351fe4");
extern s32 D_00361f60 asm("D_00361f60");
extern QWord D_0036e180[] asm("D_0036e180");
void D_001cab08(void) asm("D_001cab08");
void func_0011b6a8(Mtx*) asm("func_0011b6a8");
void func_0011b7b0(Mtx*, void*) asm("func_0011b7b0");
f32 func_001ca8e0(s32) asm("func_001ca8e0");
Obj* func_001cbc50(s32, QWord*, QWord*, s32) asm("func_001cbc50");
s32 func_002ceb08(void) asm("func_002ceb08");
Obj* func_001cbcf0(QWord* p, void* rot, s32 i) asm("func_001cbcf0");
Obj* func_001cbcf0(QWord* p, void* rot, s32 i) {
    Obj* r = 0;
    if (D_00351fe4) {
        Mtx m;
                                                                       
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
}  // namespace n001cbcf0

// ---- 001cbe30 from src/anon/batch_w2433.c
namespace n001cbe30 {
u8* func_001cbc50(s32, void*, s32, s32) asm("func_001cbc50");
u32 func_001cb6e0(u32, u32, u32, u32) asm("func_001cb6e0");
u32 func_001cb700(u32, u32, u32, u32) asm("func_001cb700");
extern s32 D_00351fe4 asm("D_00351fe4");
extern u8 D_0036e180[] asm("D_0036e180");
typedef struct W2433_O { u8 pad[0x10]; void* fn; u8 pad2[0x28 - 0x14]; u32 fl; } W2433_O;
W2433_O* func_001cbe30(s32 a0, s32 a1, s32 a2) asm("func_001cbe30");
W2433_O* func_001cbe30(s32 a0, s32 a1, s32 a2) {
    W2433_O* r = 0;
    if (D_00351fe4 != 0) {
        W2433_O* o = (W2433_O*)func_001cbc50(D_00351fe4, D_0036e180 + a1 * 16, a0, 0);
        switch (a2) {
        case 0:
        default:
            o->fn = (void*)func_001cb6e0;
            break;
        case 1:
            o->fn = (void*)func_001cb700;
            break;
        }
        o->fl |= 1;
        r = o;
    }
    return r;
}
}  // namespace n001cbe30

// ---- 001cbeb8 from src/anon/batch_w37.cpp
namespace n001cbeb8 {
extern void* D_00351fe4 asm("D_00351fe4");
extern u8 D_0036e180[] asm("D_0036e180");
u8* func_001cbc50(void*, void*, void*, u32) asm("func_001cbc50");
void func_001cba90(void) asm("func_001cba90");
u8* func_001cbeb8(void* a, s32 i) asm("func_001cbeb8");
u8* func_001cbeb8(void* a, s32 i) {
    u8* r = 0;
    void* m = D_00351fe4;
    if (m) {
        u8* v = func_001cbc50(m, D_0036e180 + i * 16, a, 0);
        *(void**)(v + 16) = (void*)func_001cba90;
        *(u32*)(v + 40) |= 3;
        r = v;
    }
    return r;
}
}  // namespace n001cbeb8

// ---- 001cbf20 from src/anon/batch_w1669.cpp
namespace n001cbf20 {
extern f32 D_00351fe0 asm("D_00351fe0");
void func_001cbf20(u32 a0, u32 a1) asm("func_001cbf20");
void func_001cbf20(u32 a0, u32 a1) {
    if (a1 == 0xffff && a0 == 1) { D_00351fe0 = 4.7123885f; }
}
}  // namespace n001cbf20

// ---- 001cbf50 from src/anon/batch_w62.cpp
namespace n001cbf50 {
f32 func_001cbf50(f32 a) asm("func_001cbf50");
f32 func_001cbf50(f32 a) {                         
    if (0.0f < a) {
        if (3.14159274f < a) {
            do a -= 6.28318548f; while (3.14159274f < a);
        }
    } else {
        while (a < -3.14159274f) a += 6.28318548f;
    }
    return a;
}
}  // namespace n001cbf50

// ---- 001cbfe8 gap: _GLOBAL__I_ stub of this file (static init 0x1cbf20)
namespace n001cbfe8 {
void func_001cbf20(u32, u32) asm("func_001cbf20");
void func_001cbfe8() asm("func_001cbfe8");
void func_001cbfe8() {
    func_001cbf20(1, 0xffff);
}
}  // namespace n001cbfe8

