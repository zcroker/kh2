// Linked unit 0x193608-0x193be8: YS__OBJ__make_matrix (object world-matrix build), converted from whole asm.
// The vector/matrix helpers are the VU0 inline math library, kept as inline asm (less-asm).
// The two skip tests are value-form "a || b" inlines (flag cleared before the call, set after), negated in a third inline.
// Flags: -G0 -fno-strict-aliasing (from the _nsa suffix).
#include "../common/types.h"
extern "C" {
// Hand-written VU0 macro code (inline math library): kept as inline asm.
struct V {
    f32 x, y, z, w;
    V& operator=(const V& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V operator*(f32 s) const
    {
        V r;
        V* out = &r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(out), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    V& operator*=(f32 s)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    V operator+(const V& b) const
    {
        V r;
        V* out = &r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(out), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct M {
    V r[4];
    M& operator=(const M& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    void scale(const V& s)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf4, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tvmulx.wxyz $vf1, $vf1, $vf4x\n\tvmuly.wxyz $vf2, $vf2, $vf4y\n\tvmulz.wxyz $vf3, $vf3, $vf4z\n\tsqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\t.set reorder" : : "r"(this), "r"(&s) : "memory");
    }
    M operator*(const M& b) const
    {
        M r;
        M* out = &r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n"
            "\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n"
            "\tvmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n"
            "\tvmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n"
            "\tvmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n"
            "\tsqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder" : : "r"(out), "r"(this), "r"(&b) : "memory");
        return r;
    }
};
M* func_0011b6a8(M*);
M* func_0011b720(M*, f32);
M* func_0011b7b0(M*, V*);
struct O;
s32 func_0019c400(O*);
s32 func_001c0cd8(O*);
s32 func_0019bad8(O*);
s32 func_0019c090(O*);
s32 func_0016a070(O*);
V func_0017fe10(void*, f32);
void func_0016b0e0(void*, u32, M*) asm("YS__OBJ__get_bone_matrix");
void func_00193be8(O*, V*, void*, M*);
void func_00193d38(O*, M*) asm("YS__OBJ__make_matrix_lk");
void func_001b78d0(void*);
void func_00193e88(O*);
extern u8 D_01c61ae0[];
struct O12 { u8 pad[8]; u32 flags; };
struct O {
    u8 pad0[12];
    O12* p12;
    u8 padA[48 - 16];
    V v48;
    M mtx;
    u8 pad1[320 - 128];
    u8 v320[352 - 320];
    u32 i352;
    u8 pad2[1344 - 356];
    V pos;
    V rot;
    u8 pad3[1392 - 1376];
    void* p1392;
    u16 h1396;
    u16 h1398;
    u8 pad4[1636 - 1400];
    void* p1636;
    u8 pad5[2088 - 1640];
    void* p2088;
    u8 pad6[2256 - 2092];
    f32 f2256;
};
static inline bool IN(O* o){ return (o->p12->flags & 2)||(o->i352 & 0x40); }
static inline bool PRED(O* o){ return func_0019c090(o) || IN(o); }
static inline bool NP(O* o){ return !PRED(o); }
void func_00193608(O* o) asm("YS__OBJ__make_matrix");
void func_00193608(O* o)
{
    V save;
    V scale;
    V save2;
    V a;
    M m;
    M m2;
    M m3;
    if (func_0019c400(o)) {
        func_0011b6a8(&m);
        m = *func_0011b7b0(&m, &o->rot);
    } else {
        func_00193be8(o, &o->rot, D_01c61ae0, &m);
    }
    scale = o->v48 * o->v48.w * o->f2256;
    scale.w = 1.0f;
    m.scale(scale);
    if (func_001c0cd8(o)) {
        const f32 k = -1.0f;
        a = func_0017fe10(o->v320, k);
        func_0011b6a8(&m2);
        m2 = *func_0011b720(&m2, a.w);
        m2.r[3] = o->pos + a;
        m2.r[3].w = 1.0f;
        if (!(o->h1396 & 0x4000)) {
            m.r[1] *= k;
            m.r[2] *= k;
        }
        func_0016b0e0(o->p1392, o->h1396, &m3);
        m = m3 * m * m2;
        if ((u8)((o->h1398 >> 1) & 1)) {
            save = m.r[3];
            func_00193be8(o, &o->rot, D_01c61ae0, &m);
            m.r[3] = save;
        }
    } else {
        m.r[3] = o->pos;
        m.r[3].w = 1.0f;
    }
    o->mtx = m;
    if (func_0019bad8(o) && o->p1636 && NP(o) && !func_001c0cd8(o)) {
        func_00193d38(o, &o->mtx);
        o->mtx.scale(scale);
        V& d = o->mtx.r[3];
        d = o->pos;
        d.w = 1.0f;
    } else if (func_0016a070(o) == 5067 && o->p1636 && NP(o)) {
        save2 = o->mtx.r[3];
        func_00193d38(o, &o->mtx);
        o->mtx.scale(scale);
        V& d = o->mtx.r[3];
        d = save2;
        d.w = 1.0f;
    }
    if (o->p2088) func_001b78d0(o->p2088);
    func_00193e88(o);
}
}
