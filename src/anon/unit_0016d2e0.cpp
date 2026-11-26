// YS script traps (0x16d2e0-0x16e8f8): vector math, progress/flag, fade, form RAM, effect, timer,
// sound and item traps of the VM trap table at 0x34d8b0, ending with the file's static init (random
// seed 0x34d8a8 = 1), the empty atexit destructors of its function-local statics and the I/D stubs.
// Each function keeps the declarations of the source it was matched in (one namespace per function);
// the never-written gap functions were added from the trap table.
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../yasui/libys/attack.hpp"
#include "../yasui/libys/battlereport.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"
inline void* operator new(__SIZE_TYPE__, void* p) { return p; }

// 0016d2e0 (from ys/traps.cpp)
namespace n0016d2e0 {
extern s32 YS_abs_int(s32) asm("_ZN2YS3absEi");
void trap_abs(BD_VALUE* bd) asm("_ZN2YS8trap_absEP8BD_VALUE");
void trap_abs(BD_VALUE* bd) { bd->i = YS_abs_int(bd->i); }
}  // namespace n0016d2e0

// 0016d310 (from anon/tiny_auto80_queue.cpp)
namespace n0016d310 {
f32 fabsf(f32) asm("fabsf");
void func_0016d310(u32 a0) asm("_ZN2YS9trap_absfEP8BD_VALUE");
void func_0016d310(u32 a0) {
    f32 f12 = *(f32*)((u32)a0 + (s32)(0));
    u32 s0 = a0;
    f32 f0 = fabsf(f12);  // fabsf
    *(f32*)((u32)s0 + (s32)(0)) = f0;
}
}  // namespace n0016d310

// 0016d340 (from anon/batch_w58.cpp)
namespace n0016d340 {
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void cpq(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
extern s8 D_004f62b0 asm("D_004f62b0");
extern Vec4 D_004f62c0 asm("D_004f62c0");
void func_002fd188(void (*)(void)) asm("atexit");
void func_0016e878(void) asm("func_0016e878");
void func_0016d340(Vec4** p) asm("func_0016d340");
void func_0016d340(Vec4** p) {
    Vec4* a = p[0];
    Vec4* b = p[1];
    if (!D_004f62b0) {
        D_004f62b0 = 1;
        func_002fd188(func_0016e878);  // pool_alloc_block
    }
    Vec4 t;
    asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvadd.xyzw $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)"
        : : "r"(&t), "r"(a), "r"(b) : "memory");
    if (&t != &D_004f62c0) cpq(&D_004f62c0, &t);
    p[0] = &D_004f62c0;
}
}  // namespace n0016d340

// 0016d3c8 (from anon/batch_w59.cpp)
namespace n0016d3c8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 {
    f32 x, y, z, w;
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
extern s8 D_004f62d0 asm("D_004f62d0");
extern Vec4 D_004f62e0 asm("D_004f62e0");
void func_002fd188(void (*)(void)) asm("atexit");
void func_0016e880(void) asm("func_0016e880");
void func_0016d3c8(Vec4** p) asm("func_0016d3c8");
void func_0016d3c8(Vec4** p) {
    Vec4* a = p[0];
    Vec4* b = p[1];
    if (!D_004f62d0) {
        D_004f62d0 = 1;
        func_002fd188(func_0016e880);  // pool_alloc_block
    }
    Vec4 t;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(t) : "r"(a), "r"(b));
    D_004f62e0 = t;
    p[0] = &D_004f62e0;
}
}  // namespace n0016d3c8

// 0016d450 (from anon/batch_w50.cpp)
namespace n0016d450 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& o) { QCOPY(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Scaled { Vec4* v; f32 s; };
extern s8 D_004f62f0 asm("D_004f62f0");
extern Vec4 D_004f6300 asm("D_004f6300");
void func_0016e888(void) asm("func_0016e888");
void func_002fd188(void*) asm("atexit");
void func_0016d450(Scaled* o) asm("func_0016d450");
void func_0016d450(Scaled* o) {
    Vec4* v = o->v;
    if (!D_004f62f0) {
        D_004f62f0 = 1;
        func_002fd188((void*)func_0016e888);  // pool_alloc_block
    }
    Vec4 t;
    asm("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&t), "r"(v), "f"(o->s) : "$8", "memory");
    D_004f6300 = t;
    o->v = &D_004f6300;
}
}  // namespace n0016d450

// 0016d4d0 (from anon/batch_w1769.cpp)
namespace n0016d4d0 {
struct W1769Vec {
    f32 x, y, z, w;
    W1769Vec& operator=(const W1769Vec& o) {
        if (this != &o) {
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        }
        return *this;
    }
} __attribute__((aligned(16)));
struct W1769Obj { W1769Vec* v; f32 s; };
extern s8 D_004f6310 asm("D_004f6310");
extern W1769Vec D_004f6320 asm("D_004f6320");
void func_0016e890(void) asm("func_0016e890");
void func_002fd188(void (*)(void)) asm("atexit");
static inline W1769Vec w1769_div(const W1769Vec* v, f32 s) {
    W1769Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.wxyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(v), "f"(s) : "$8", "memory");
    return r;
}
void func_0016d4d0(W1769Obj* o) asm("func_0016d4d0");
void func_0016d4d0(W1769Obj* o) {
    W1769Vec* v = o->v;
    if (!D_004f6310) {
        D_004f6310 = 1;
        func_002fd188(func_0016e890);
    }
    D_004f6320 = w1769_div(v, o->s);
    o->v = &D_004f6320;
}
}  // namespace n0016d4d0

// 0016d558 .. 0016d588 (never written before: vector length / normalize traps)
namespace g0016d558 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
void func_0016d558(BD_VALUE* bd) asm("func_0016d558");
void func_0016d558(BD_VALUE* bd) {
    V4* v = (V4*)bd->p;
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    bd->f = r;
}
static inline f32 VNormalize(V4* d, V4* s)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%2)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(d), "r"(s) : "$8", "memory");
    return r;
}
void func_0016d588(BD_VALUE* bd) asm("func_0016d588");
void func_0016d588(BD_VALUE* bd) {
    V4* v = (V4*)bd->p;
    f32 r = VNormalize(v, v);
    v->w = r;
    bd->f = r;
}
}  // namespace g0016d558

// 0016d5d0 (from anon/batch_w37.cpp)
namespace n0016d5d0 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern s8 D_004f6330 asm("D_004f6330");
extern Vq D_004f6340 asm("D_004f6340");
void func_0016e898(void) asm("func_0016e898");
void func_002fd188(void (*)(void)) asm("atexit");
Vq YS__MATH__VectorRotY(u32, f32) asm("YS__MATH__VectorRotY");
void func_0016d5d0(u32* p) asm("func_0016d5d0");
void func_0016d5d0(u32* p) {
    if (!D_004f6330) {
        D_004f6330 = 1;
        func_002fd188(func_0016e898);  // pool_alloc_block
    }
    D_004f6340 = YS__MATH__VectorRotY(p[0], *(f32*)&p[1]);
    p[0] = (u32)&D_004f6340;
}
}  // namespace n0016d5d0

// 0016d640 (from anon/batch_w25.cpp)
namespace n0016d640 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
extern Q16 D_004f62a0 asm("D_004f62a0");
void func_0017d5e8(Q16*, u32, float) asm("func_0017d5e8");
void func_0016d640(u32* p) asm("func_0016d640");
void func_0016d640(u32* p) {
    Q16 tmp;
    func_0017d5e8(&tmp, p[0], *(float*)&p[1]);
    if (&tmp != &D_004f62a0)
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&D_004f62a0), "r"(&tmp) : "$8", "memory");
    p[0] = (u32)&D_004f62a0;
}
}  // namespace n0016d640

// 0016d690 (never written before: empty trap)
namespace g0016d690 {
void func_0016d690(void) asm("func_0016d690");
void func_0016d690(void) {}
}  // namespace g0016d690

// 0016d698 (from anon/auto80_199_queue.cpp)
namespace n0016d698 {
void func_0016d698(u8* a0) asm("_ZN2YS16trap_vector_dumpEP8BD_VALUE");
void func_0016d698(u8* a0) {
    u8* s0 = a0;
    u8* s1 = (u8*)*(u32*)(a0 + 0);
    u8* t7 = (u8*)*(u32*)(a0 + 4);

    f32 f20 = func_002f8ad0(*(f32*)(t7 + 0), *(f32*)(t7 + 8));
    f20 = f20 - func_002f8ad0(*(f32*)(s1 + 0), *(f32*)(s1 + 8));
    *(f32*)(s0 + 0) = func_0017ce10(f20);
}
}  // namespace n0016d698

// 0016d700 (never written before: scale a vector in place)
namespace g0016d700 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void VScale(V4* d, V4* s, f32 k)
{
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
void func_0016d700(BD_VALUE* bd) asm("func_0016d700");
void func_0016d700(BD_VALUE* bd) {
    f32 k = bd[1].f;
    V4* v = (V4*)bd[0].p;
    VScale(v, v, k);
}
}  // namespace g0016d700

// 0016d728 (from anon/tiny_auto80_queue.cpp)
namespace n0016d728 {
f32 func_002f8ad0(f32, f32) asm("f_atan2f");
void func_0016d728(u32 a0) asm("_ZN2YS19method_vector_scaleEP8BD_VALUE");
void func_0016d728(u32 a0) {
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    u32 s0 = a0;
    f32 f0 = func_002f8ad0(*(f32*)((u32)t7 + (s32)(0)), *(f32*)((u32)t7 + (s32)(8)));
    *(f32*)((u32)s0 + (s32)(0)) = f0;
}
}  // namespace n0016d728

// 0016d760 (from anon/batch_wcx.cpp)
namespace n0016d760 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern f32 D_00349e10 asm("D_00349e10");
static inline f32 VNormalize(V4* d, V4* s)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%2)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(d), "r"(s) : "$8", "memory");
    return r;
}
static inline void VScale(V4* d, V4* s, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline void VAdd(V4* d, V4* a, V4* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
struct Mv { V4* pos; V4* dir; f32 speed; };
void func_0016d760(Mv* m) asm("func_0016d760");
void func_0016d760(Mv* m)
{
    V4* pos = m->pos;
    V4 n;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&n), "r"(m->dir) : "$8", "memory");
    VNormalize(&n, &n);
    V4 b, a;
    VScale(&a, &n, m->speed);
    VScale(&b, &a, D_00349e10);
    VAdd(pos, pos, &b);
}
}  // namespace n0016d760

// 0016d800 (from anon/batch_w209.cpp)
namespace n0016d800 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V209 {
    f32 x, y, z, w;
    V209() {}
    V209(const V209& o) { QCOPY(this, &o); }
    V209& operator=(const V209& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct VP209 { V209* p; u32 x; f32 y; };
extern V209 func_0017d348(V209* self, u32 x, f32 y) asm("func_0017d348");
void func_0016d800(VP209* a) asm("func_0016d800");
void func_0016d800(VP209* a) {
    V209* self = a->p;
    u32 x = a->x;
    *self = func_0017d348(self, x, a->y);
}
}  // namespace n0016d800

// 0016d848 (never written before: lerp of two vectors into the shared result vector)
namespace g0016d848 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern V4 D_004f62a0 asm("D_004f62a0");
void func_0016d848(BD_VALUE* bd) asm("func_0016d848");
void func_0016d848(BD_VALUE* bd) {
    V4* d = &D_004f62a0;
    V4* a = (V4*)bd[0].p;
    V4* b = (V4*)bd[1].p;
    f32 t = bd[2].f;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b), "f"(t) : "$8", "memory");
    bd[0].p = d;
}
}  // namespace g0016d848

// 0016d888 (from anon/batch_w1744.cpp)
namespace n0016d888 {
#define W1744_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { W1744_QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) W1744_QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord Cross(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct VPair { QWord* a; QWord* b; };
extern QWord D_004f62a0 asm("D_004f62a0");
void func_0016d888(VPair* p) asm("func_0016d888");
void func_0016d888(VPair* p) {
    D_004f62a0 = Cross(*p->a, *p->b);
    p->a = &D_004f62a0;
}
}  // namespace n0016d888

// 0016d8d0 (from anon/batch_w64.cpp)
namespace n0016d8d0 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct V16 { u128 q; };
static inline void vcopy(void* d, void* s) {
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
void func_0017d698(V16*, u32, u32, f32) asm("func_0017d698");
extern V16 D_004f62a0 asm("D_004f62a0");
void func_0016d8d0(u32* p) asm("func_0016d8d0");
void func_0016d8d0(u32* p) {
    V16 tmp;
    func_0017d698(&tmp, p[0], p[1], *(f32*)(p + 2));
    vcopy(&D_004f62a0, &tmp);
    *(V16**)p = &D_004f62a0;
}
}  // namespace n0016d8d0

// 0016d920 (from anon/batch_w34.cpp)
namespace n0016d920 {
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
f32 YS__MATH__VectorAngle(Vec4*, Vec4*) asm("YS__MATH__VectorAngle");
void func_0016d920(Vec4** p) asm("func_0016d920");
void func_0016d920(Vec4** p) {
    Vec4 b;
    Vec4 a;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&b), "r"(p[1]) : "$8", "memory");
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&a), "r"(p[0]) : "$8", "memory");
    *(f32*)p = YS__MATH__VectorAngle(&a, &b);
}
}  // namespace n0016d920

// 0016d968 (from anon/match_0016d968_nsr.cpp)
namespace n0016d968 {
struct W2437V4 {
    f32 x, y, z, w;
    W2437V4& operator=(const W2437V4& o) {
        // 128-bit copy (lq/sq), skipped for self-assignment
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W2437M4 { W2437V4 r[4]; };
static inline void W2437_scaleM(W2437M4* m, W2437V4* s) {
    asm volatile(".set noreorder\n\tlqc2 $vf4, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tvmulx.wxyz $vf1, $vf1, $vf4x\n\tvmuly.wxyz $vf2, $vf2, $vf4y\n\tvmulz.wxyz $vf3, $vf3, $vf4z\n\tsqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\t.set reorder" : : "r"(m), "r"(s) : "memory");
}
struct W2437Obj { W2437V4* pos; f32 scale; };
void func_0011b6a8(W2437M4*) asm("func_0011b6a8");
void func_0016d968(W2437Obj* o) asm("func_0016d968");
void func_0016d968(W2437Obj* o) {
    W2437M4 m;
    func_0011b6a8(&m);
    W2437V4 s;
    s.w = 0.0f;
    s.x = o->scale;
    s.y = o->scale;
    s.z = o->scale;
    W2437_scaleM(&m, &s);
    m.r[3] = *o->pos;
    m.r[3].w = 1.0f;
    s32 i = 4;
    do { i--; } while (i >= 2);
}
}  // namespace n0016d968

// 0016da20 (from anon/batch_wcx.cpp)
namespace n0016da20 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline f32 VNormalize(V4* d, V4* s)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%2)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(d), "r"(s) : "$8", "memory");
    return r;
}
static inline void VCp(V4* d, V4* s) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory"); }
static inline f32 VDot(V4* a, V4* b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
struct DotArg { V4* a; V4* b; };
void func_0016da20(DotArg* p) asm("func_0016da20");
void func_0016da20(DotArg* p)
{
    V4 n1, n2;
    VCp(&n1, p->a);
    VNormalize(&n1, &n1);
    VCp(&n2, p->b);
    VNormalize(&n2, &n2);
    *(f32*)p = VDot(&n1, &n2);
}
}  // namespace n0016da20

// 0016dad8 (from anon/batch_w35.cpp)
namespace n0016dad8 {
void YS__MATH__VectorToAngle(void*, u32) asm("YS__MATH__VectorToAngle");
extern u8 D_004f62a0[] asm("D_004f62a0");
void func_0016dad8(u8* p) asm("func_0016dad8");
void func_0016dad8(u8* p) {
    u8 tmp[16] __attribute__((aligned(16)));
    YS__MATH__VectorToAngle(tmp, *(u32*)p);
    u8* d = D_004f62a0;
    if (d != tmp) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(tmp) : "$8", "memory");
    *(u8**)p = d;
}
}  // namespace n0016dad8

// 0016db20 (from anon/auto80_199_queue.cpp)
namespace n0016db20 {
void func_0016db20(u8* a0) asm("_ZN2gm17trap_thread_startEP8BD_VALUE");
void func_0016db20(u8* a0) {
    u32 s0 = *(u32*)(a0 + 0);
    if (s0 != 0) {
        func_0016cff0(D_0034d8a0, s0, s0);
    }

    u32 v0 = func_0016cfa0(
        D_0034d8a0,
        *(u32*)(a0 + 0),
        *(u32*)(a0 + 4),
        (u32)(a0 + 12),
        (u32)(*(u32*)(a0 + 12) != 0));

    u32 t7 = *(u32*)(a0 + 8);
    if (t7 != 0) {
        *(u32*)(v0 + 36) = t7;
    }
    *(u32*)(a0 + 0) = v0;
}
}  // namespace n0016db20

// 0016db98 (never written before: input state bit test, first word)
namespace g0016db98 {
void* func_00167f18(s32) asm("func_00167f18");
void func_0016db98(s32* p) asm("func_0016db98");
void func_0016db98(s32* p) {
    u64* v = (u64*)func_00167f18(0);
    *p = (u8)((v[0] >> *p) & 1);
}
}  // namespace g0016db98

// 0016dbe0 (from anon/batch_w33.cpp)
namespace n0016dbe0 {
void* func_00167f18(s32) asm("func_00167f18");
void func_0016dbe0(s32* p) asm("func_0016dbe0");
void func_0016dbe0(s32* p) {
    u64* v = (u64*)func_00167f18(0);
    *p = (u8)((v[1] >> *p) & 1);
}
}  // namespace n0016dbe0

// 0016dc28 (from ys/traps.cpp)
namespace n0016dc28 {
extern s32 YS_FILE_IsReading(void) asm("_ZN2YS4FILE9IsReadingEv");
void trap_file_is_reading(BD_VALUE* bd) asm("_ZN2YS20trap_file_is_readingEP8BD_VALUE");
void trap_file_is_reading(BD_VALUE* bd) { bd->i = YS_FILE_IsReading(); }
}  // namespace n0016dc28

// 0016dc50 (from ys/traps.cpp)
namespace n0016dc50 {
extern void YS_CACHE_BUFF_Flush(s32) asm("_ZN2YS10CACHE_BUFF5FlushEP4TASK");
void trap_file_flush(BD_VALUE* bd) asm("_ZN2YS15trap_file_flushEP8BD_VALUE");
void trap_file_flush(BD_VALUE* bd) {
    (void)bd;
    YS_CACHE_BUFF_Flush(0);
}
}  // namespace n0016dc50

// 0016dc68 (from ys/traps.cpp)
namespace n0016dc68 {
extern void YS_PROGRESS_SetFlag(s32) asm("_ZN2YS8PROGRESS7SetFlagEi");
void trap_progress_set_flag(BD_VALUE* bd) asm("_ZN2YS22trap_progress_set_flagEP8BD_VALUE");
void trap_progress_set_flag(BD_VALUE* bd) { YS_PROGRESS_SetFlag(bd->i); }
}  // namespace n0016dc68

// 0016dc80 (from ys/traps.cpp)
namespace n0016dc80 {
void trap_progress_check_flag(BD_VALUE* bd) asm("_ZN2YS24trap_progress_check_flagEP8BD_VALUE");
void trap_progress_check_flag(BD_VALUE* bd) {
    bd->i = YS::PROGRESS::CheckFlag(bd->i);
}
}  // namespace n0016dc80

// 0016dcb0 (from ys/traps.cpp)
namespace n0016dcb0 {
void trap_progress_is_second(BD_VALUE* bd) asm("_ZN2YS23trap_progress_is_secondEP8BD_VALUE");
void trap_progress_is_second(BD_VALUE* bd) { bd->i = YS::PROGRESS::IsSecond(); }
}  // namespace n0016dcb0

// 0016dcd8 (from ys/traps.cpp)
namespace n0016dcd8 {
void trap_progress_is_secret_movie(BD_VALUE* bd) asm("_ZN2YS29trap_progress_is_secret_movieEP8BD_VALUE");
void trap_progress_is_secret_movie(BD_VALUE* bd) {
    bd->i = YS::BATTLE_REPORT::IsSecretMovie();
}
}  // namespace n0016dcd8

// 0016dd00 (from ys/traps.cpp)
namespace n0016dd00 {
void trap_progress_is_fm_secret_movie(BD_VALUE* bd) asm("_ZN2YS32trap_progress_is_fm_secret_movieEP8BD_VALUE");
void trap_progress_is_fm_secret_movie(BD_VALUE* bd) {
    bd->i = YS::BATTLE_REPORT::IsFMSecretMovie();
}
}  // namespace n0016dd00

// 0016dd28 (from anon/batch_w51.cpp)
namespace n0016dd28 {
extern u32 D_0034d8a8 asm("D_0034d8a8");
void func_0016dd28(u32* p) asm("func_0016dd28");
void func_0016dd28(u32* p) {
    u32 seed = D_0034d8a8 * 0x10dcd;
    u32 n = *p;
    D_0034d8a8 = seed;
    *p = (u64)seed / (((u64)(n - 1) + 0x100000000ull) / n);
}
}  // namespace n0016dd28

// 0016dda8 .. 0016de78 (never written before: random float traps, and a wrapper)
namespace g0016dda8 {
extern u32 D_0034d8a8 asm("D_0034d8a8");
void func_0016dda8(f32* p) asm("func_0016dda8");
void func_0016dda8(f32* p) {
    u32 seed = D_0034d8a8 * 0x10dcd;
    D_0034d8a8 = seed;
    *p = (f32)seed * 2.3283064365386963e-10f * *p;
}
void func_0016de08(f32* p) asm("func_0016de08");
void func_0016de08(f32* p) {
    u32 seed = D_0034d8a8 * 0x10dcd;
    D_0034d8a8 = seed;
    *p = (f32)seed * 2.3283064365386963e-10f * (p[1] - p[0]) + p[0];
}
void func_001b8838(s32) asm("func_001b8838");
void func_0016de78(BD_VALUE* bd) asm("func_0016de78");
void func_0016de78(BD_VALUE* bd) { func_001b8838(bd->i); }
}  // namespace g0016dda8

// 0016de90 (from ys/traps.cpp)
namespace n0016de90 {
extern s32 YS_WORLDFLAG_Check(s32) asm("_ZN2YS9WORLDFLAG5CheckEi");
void trap_worldflag_check(BD_VALUE* bd) asm("_ZN2YS20trap_worldflag_checkEP8BD_VALUE");
void trap_worldflag_check(BD_VALUE* bd) { bd->i = YS_WORLDFLAG_Check(bd->i); }
}  // namespace n0016de90

// 0016dec0 (from ys/traps.cpp)
namespace n0016dec0 {
extern void func_0014ce50(f32) asm("func_0014ce50");
void func_system_set_game_speed(BD_VALUE* bd) asm("_ZN2YS26func_system_set_game_speedEP8BD_VALUE");
void func_system_set_game_speed(BD_VALUE* bd) { func_0014ce50(bd->f); }
}  // namespace n0016dec0

// 0016ded8 (from ys/traps.cpp)
namespace n0016ded8 {
extern void func_0019ec88(u32) asm("_ZN2YS4BLUR4initEv");
void method_blur_init(BD_VALUE* bd) asm("_ZN2YS16method_blur_initEP8BD_VALUE");
void method_blur_init(BD_VALUE* bd) { func_0019ec88(*(u32*)((u32)bd + 0u)); }
}  // namespace n0016ded8

// 0016def0 (from ys/traps.cpp)
namespace n0016def0 {
extern void YS_BLUR_start(s32, f32) asm("_ZN2YS4BLUR5startEf");
void method_blur_start(BD_VALUE* bd) asm("_ZN2YS17method_blur_startEP8BD_VALUE");
void method_blur_start(BD_VALUE* bd) { YS_BLUR_start(bd->i, 0.0f); }
}  // namespace n0016def0

// 0016df10 (never written before)
namespace g0016df10 {
void func_0019ed48(s32) asm("func_0019ed48");
void func_0016df10(BD_VALUE* bd) asm("func_0016df10");
void func_0016df10(BD_VALUE* bd) { func_0019ed48(bd->i); }
}  // namespace g0016df10

// 0016df28 (from anon/batch_w54.cpp)
namespace n0016df28 {
void* func_0014aba8(void) asm("_ZN2dk10getAllFadeEv");
void func_0014aa58(void*, s32, s32) asm("_ZN2dk4Fade7fadeOutEjb");
void func_0016df28(f32* p) asm("func_0016df28");
void func_0016df28(f32* p) {
    s32 v = (s32)(*p * 0.5f);
    func_0014aa58(func_0014aba8(), v, 1);
}
}  // namespace n0016df28

// 0016df70 (from anon/batch_w55.cpp)
namespace n0016df70 {
u32 func_0014aba8(void) asm("_ZN2dk10getAllFadeEv");
void func_0014aa80(u32, s32, s32) asm("func_0014aa80");
void func_0016df70(f32* p) asm("func_0016df70");
void func_0016df70(f32* p) {
    s32 n = (s32)(*p * 0.5f);
    func_0014aa80(func_0014aba8(), n, 1);
}
}  // namespace n0016df70

// 0016dfb8 (from ys/traps.cpp)
namespace n0016dfb8 {
extern u32 func_00153f08(u32, u32, u32, u32) asm("_ZN2dk6Camera20singleCrossFadeStartEf");
u32 trap_screen_cross_fade(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS22trap_screen_cross_fadeEP8BD_VALUE");
u32 trap_screen_cross_fade(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00153f08(*(u32*)(a0 + 0u), *(u32*)(a0 + 4u), a2, a3);
}
}  // namespace n0016dfb8

// 0016dfd8 (never written before)
namespace g0016dfd8 {
void func_00162058(f32) asm("func_00162058");
void func_0016dfd8(f32* p) asm("func_0016dfd8");
void func_0016dfd8(f32* p) { func_00162058(*p * 0.5f); }
}  // namespace g0016dfd8

// 0016e000 (from anon/batch_w56.cpp)
namespace n0016e000 {
void* func_0014aba8(void) asm("_ZN2dk10getAllFadeEv");
void func_0014aa58(void*, s32, s32) asm("_ZN2dk4Fade7fadeOutEjb");
void func_0016e000(f32* a) asm("func_0016e000");
void func_0016e000(f32* a)
{
    s32 v = (s32)(*a * 0.5f);
    func_0014aa58(func_0014aba8(), v, 0);
}
}  // namespace n0016e000

// 0016e048 (from anon/batch_w57.cpp)
namespace n0016e048 {
s32 func_0014aba8(void) asm("_ZN2dk10getAllFadeEv");
void func_0014aa80(u32, u32, u32) asm("func_0014aa80");
void func_0016e048(f32* p) asm("func_0016e048");
void func_0016e048(f32* p) {
    s32 n = (s32)(p[0] * 0.5f);
    u32 v = func_0014aba8();
    func_0014aa80(v, n, 0);
}
}  // namespace n0016e048

// 0016e090 (from anon/tiny_jal_wrappers_reloc.cpp)
namespace n0016e090 {
u32 YS__SAVERAM_BATTLE__get_partram(u32, u32, u32, u32) asm("_Z31YS__SAVERAM_BATTLE__get_partramjjjj");
extern u8 D_0032e020 asm("D_0032e020");
u32 func_0016e090(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS24trap_saveram_get_partramEP8BD_VALUE");
u32 func_0016e090(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r5 = *(u32*)((u32)r4 + (s32)(0));
    r4 = (u32)&D_0032e020;
    r2 = YS__SAVERAM_BATTLE__get_partram(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n0016e090

// 0016e0c8 (from anon/tiny_wrappers_more80_reloc.cpp)
namespace n0016e0c8 {
u32 func_00189028(u32, u32, u32, u32) asm("func_00189028");
extern u8 D_0032e020 asm("D_0032e020");
u32 func_0016e0c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS28trap_saveram_set_form_weaponEP8BD_VALUE");
u32 func_0016e0c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00189028((u32)&D_0032e020, ((u32)(*(u32*)((u32)(a0) + 0u))), ((u32)(*(u32*)((u32)(a0) + 4u))), ((u32)(*(u32*)((u32)(a0) + 8u))));
}
}  // namespace n0016e0c8

// 0016e0f8 (never written before: store a halfword into the form RAM entry)
namespace g0016e0f8 {
extern u32 D_0032e020 asm("D_0032e020");
void* YS__SAVERAM_BATTLE__get_formram(void*, u32) asm("_Z31YS__SAVERAM_BATTLE__get_formramjjjj");
void func_0016e0f8(u32* v) asm("func_0016e0f8");
void func_0016e0f8(u32* v) {
    *(u16*)YS__SAVERAM_BATTLE__get_formram(&D_0032e020, v[0]) = *(u16*)&v[1];
}
}  // namespace g0016e0f8

// 0016e130 (from anon/batch_w11.cpp)
namespace n0016e130 {
extern u32 D_0032e020 asm("D_0032e020");
void* YS__SAVERAM_BATTLE__get_formram(void*, u32) asm("_Z31YS__SAVERAM_BATTLE__get_formramjjjj");
void func_001891b8(void*, u32) asm("_ZN2YS7FORMRAM11set_abilityEi");
void trap_saveram_set_form_ability(u32*) asm("_ZN2YS29trap_saveram_set_form_abilityEP8BD_VALUE");
void trap_saveram_set_form_ability(u32* v) asm("_ZN2YS29trap_saveram_set_form_abilityEP8BD_VALUE");
void trap_saveram_set_form_ability(u32* v) {
    func_001891b8(YS__SAVERAM_BATTLE__get_formram(&D_0032e020, v[0]), v[1]);
}
}  // namespace n0016e130

// 0016e168 (from ys/traps.cpp)
namespace n0016e168 {
extern void func_001d97c8(BD_VALUE*) asm("func_001d97c8");
void trap_effect_set_pos(BD_VALUE* bd) asm("_ZN2YS19trap_effect_set_posEP8BD_VALUE");
void trap_effect_set_pos(BD_VALUE* bd) { func_001d97c8(bd); }
}  // namespace n0016e168

// 0016e180 (never written before: set effect position from a vector)
namespace g0016e180 {
void* func_001dc5f8(void*) asm("_ZN3ryj6EFFECT3posEv");
void func_0016e180(void** p) asm("func_0016e180");
void func_0016e180(void** p) {
    u8* d = (u8*)func_001dc5f8(p[0]);
    u8* s = (u8*)p[1];
    if (d != s) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
}
}  // namespace g0016e180

// 0016e1c0 (from anon/tiny_auto80_queue.cpp)
namespace n0016e1c0 {
extern u32 func_001dc620(...) asm("_ZN3ryj6EFFECT5scaleEv");
void func_0016e1c0(BD_VALUE* param_1) asm("_ZN2YS21trap_effect_set_scaleEP8BD_VALUE");
void func_0016e1c0(BD_VALUE* param_1) {
    kn::FVector* dst = (kn::FVector*)(u32)func_001dc620(param_1[0].u);
    *dst = *(kn::FVector*)param_1[1].p;
}
}  // namespace n0016e1c0

// 0016e200 (from anon/batch_w14.cpp)
namespace n0016e200 {
void* func_001dc648(void*) asm("_ZN3ryj6EFFECT5angleEv");
void YS__trap_effect_set_rot(void** p) asm("YS__trap_effect_set_rot");
void YS__trap_effect_set_rot(void** p) {
    u8* d = (u8*)func_001dc648(p[0]);
    u8* s = (u8*)p[1];
    if (d != s) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
}
}  // namespace n0016e200

// 0016e240 (from anon/batch_w65.cpp)
namespace n0016e240 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
Vq* func_001dc648(u32) asm("_ZN3ryj6EFFECT5angleEv");
Vq YS__MATH__VectorToAngle(u32) asm("YS__MATH__VectorToAngle");
void YS__trap_effect_set_dir(u32* p) asm("YS__trap_effect_set_dir");
void YS__trap_effect_set_dir(u32* p) {
    Vq* d = func_001dc648(p[0]);
    *d = YS__MATH__VectorToAngle(p[1]);
}
}  // namespace n0016e240

// 0016e290 (from ys/traps.cpp)
namespace n0016e290 {
extern void ryj_EFFECT_loop_end(s32) asm("_ZN3ryj6EFFECT8loop_endEv");
void trap_effect_loop_end(BD_VALUE* bd) asm("_ZN2YS20trap_effect_loop_endEP8BD_VALUE");
void trap_effect_loop_end(BD_VALUE* bd) { ryj_EFFECT_loop_end(bd->i); }
}  // namespace n0016e290

// 0016e2a8 (from ys/traps.cpp)
namespace n0016e2a8 {
extern void ryj_EFFECT_loop_end_kill(s32) asm("_ZN3ryj6EFFECT13loop_end_killEv");
void trap_effect_loop_end_kill(BD_VALUE* bd) asm("_ZN2YS25trap_effect_loop_end_killEP8BD_VALUE");
void trap_effect_loop_end_kill(BD_VALUE* bd) { ryj_EFFECT_loop_end_kill(bd->i); }
}  // namespace n0016e2a8

// 0016e2c0 (from ys/traps.cpp)
namespace n0016e2c0 {
extern s32 ryj_EFFECT_is_alive(void*) asm("_ZN3ryj6EFFECT8is_aliveEv");
void trap_effect_is_alive(BD_VALUE* bd) asm("_ZN2YS20trap_effect_is_aliveEP8BD_VALUE");
void trap_effect_is_alive(BD_VALUE* bd) { bd->i = ryj_EFFECT_is_alive((void*)bd->i); }
}  // namespace n0016e2c0

// 0016e2f0 (from ys/traps.cpp)
namespace n0016e2f0 {
extern s32 ryj_EFFECT_is_active(void*) asm("_ZN3ryj6EFFECT9is_activeEv");
void trap_effect_is_active(BD_VALUE* bd) asm("_ZN2YS21trap_effect_is_activeEP8BD_VALUE");
void trap_effect_is_active(BD_VALUE* bd) { bd->i = ryj_EFFECT_is_active((void*)bd->i); }
}  // namespace n0016e2f0

// 0016e320 (from ys/traps.cpp)
namespace n0016e320 {
extern void ryj_EFFECT_kill(s32) asm("_ZN3ryj6EFFECT4killEv");
void trap_effect_kill(BD_VALUE* bd) asm("_ZN2YS16trap_effect_killEP8BD_VALUE");
void trap_effect_kill(BD_VALUE* bd) { ryj_EFFECT_kill(bd->i); }
}  // namespace n0016e320

// 0016e338 (from anon/tiny_auto80_queue.cpp)
namespace n0016e338 {
extern u32 func_001dc978(...) asm("_ZN3ryj6EFFECT12fadeout_killEf");
extern u32 ryj__EFFECT__fadeout_free(...) asm("ryj__EFFECT__fadeout_free");
void func_0016e338(u32 a0) asm("_ZN2YS19trap_effect_fadeoutEP8BD_VALUE");
void func_0016e338(u32 a0) {
    u32 t7 = *(u32*)((u32)a0 + (s32)(8));
    u32 t6 = a0;
    if (t7 != 0u) {
        a0 = *(u32*)((u32)a0 + (s32)(0));
        ((void(*)(u32, f32))func_001dc978)(a0, *(f32*)((u32)t6 + (s32)(4)));
        return;
    }
    a0 = *(u32*)((u32)a0 + (s32)(0));
    ((void(*)(u32, f32))ryj__EFFECT__fadeout_free)(a0, *(f32*)((u32)t6 + (s32)(4)));
}
}  // namespace n0016e338

// 0016e378 (never written before: get effect position into a function-local static)
namespace g0016e378 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern s8 D_004f6350 asm("D_004f6350");
extern Vq D_004f6360 asm("D_004f6360");
void func_0016e8a0(void) asm("func_0016e8a0");
void func_002fd188(void (*)(void)) asm("atexit");
Vq* func_001dc5f8(u32) asm("_ZN3ryj6EFFECT3posEv");
void func_0016e378(u32* p) asm("func_0016e378");
void func_0016e378(u32* p) {
    if (!D_004f6350) {
        D_004f6350 = 1;
        func_002fd188(func_0016e8a0);
    }
    D_004f6360 = *func_001dc5f8(p[0]);
    p[0] = (u32)&D_004f6360;
}
}  // namespace g0016e378

// 0016e3e0 (from anon/batch_w1816_nsa.cpp)
namespace n0016e3e0 {
struct W1816Vs {
    f32 x, y, z, w;
    W1816Vs() {}
    W1816Vs(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    W1816Vs& operator=(const W1816Vs& o) {
        if (this != &o) {
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        }
        return *this;
    }
} __attribute__((aligned(16)));
struct W1816Mx { f32 m[4][4]; } __attribute__((aligned(16)));
struct W1816Hd { W1816Vs* v; };
static inline W1816Vs W1816MulV(const W1816Mx* m, const W1816Vs* v) {
    W1816Vs r;
    asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(m), "r"(v) : "memory");
    return r;
}
extern s8 D_004f6370 asm("D_004f6370");
extern W1816Vs D_004f6380 asm("D_004f6380");
extern s8 D_004f6378 asm("D_004f6378");
extern W1816Vs D_004f6390 asm("D_004f6390");
void func_0016e8a8(void) asm("func_0016e8a8");
void func_0016e8b0(void) asm("func_0016e8b0");
void func_002fd188(void (*)(void)) asm("atexit");
void func_0011b6a8(W1816Mx*) asm("func_0011b6a8");
void* func_001dc648(W1816Vs*) asm("_ZN3ryj6EFFECT5angleEv");
void func_0011b7b0(W1816Mx*, void*) asm("_ZN2kn7FMatrix9rotateXYZERKNS_7FVectorE");
void func_0016e3e0(W1816Hd* o) asm("func_0016e3e0");
void func_0016e3e0(W1816Hd* o) {
    if (!D_004f6370) {
        new (&D_004f6380) W1816Vs(0.0f, 0.0f, 1.0f, 0.0f);
        D_004f6370 = 1;
        func_002fd188(func_0016e8a8);
    }
    if (!D_004f6378) {
        D_004f6378 = 1;
        func_002fd188(func_0016e8b0);
    }
    W1816Mx m;
    func_0011b6a8(&m);
    func_0011b7b0(&m, func_001dc648(o->v));
    D_004f6390 = W1816MulV(&m, &D_004f6380);
    o->v = &D_004f6390;
}
}  // namespace n0016e3e0

// 0016e4e0 (never written before)
namespace g0016e4e0 {
void func_001dc698(s32, s32) asm("func_001dc698");
void func_0016e4e0(BD_VALUE* bd) asm("func_0016e4e0");
void func_0016e4e0(BD_VALUE* bd) { func_001dc698(bd[0].i, bd[1].i != 0); }
}  // namespace g0016e4e0

// 0016e500 (from anon/batch_w15.cpp)
namespace n0016e500 {
void* func_001dc670(u32) asm("_ZN3ryj6EFFECT5colorEv");
void func_0016e500(u32* p) asm("func_0016e500");
void func_0016e500(u32* p) {
    void* d = func_001dc670(p[0]);
    void* s = (void*)p[1];
    if (d != s) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
}
}  // namespace n0016e500

// 0016e540 (from ys/traps.cpp)
namespace n0016e540 {
extern void YS_EFFECT_AddDeadEffect(s32) asm("_ZN2YS6EFFECT13AddDeadEffectEPN3ryj6EFFECTE");
void trap_effect_add_dead_block(BD_VALUE* bd) asm("_ZN2YS26trap_effect_add_dead_blockEP8BD_VALUE");
void trap_effect_add_dead_block(BD_VALUE* bd) { YS_EFFECT_AddDeadEffect(bd->i); }
}  // namespace n0016e540

// 0016e558 (never written before)
namespace g0016e558 {
void func_0016e558(BD_VALUE* bd) asm("func_0016e558");
void func_0016e558(BD_VALUE* bd) { ((s32*)bd[0].p)[1] = bd[1].i; }
}  // namespace g0016e558

// 0016e568 (from ys/traps.cpp)
namespace n0016e568 {
extern f32 YS_MATH_FixRadian(f32) asm("_ZN2YS4MATH9FixRadianEf");
void trap_effect_set_type(BD_VALUE* bd) asm("_ZN2YS20trap_effect_set_typeEP8BD_VALUE");
void trap_effect_set_type(BD_VALUE* bd) { bd->f = YS_MATH_FixRadian(bd->f); }
}  // namespace n0016e568

// 0016e598 (from ys/traps.cpp)
namespace n0016e598 {
extern s32 AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
void trap_memory_alloc(BD_VALUE* bd) asm("_ZN2YS17trap_memory_allocEP8BD_VALUE");
void trap_memory_alloc(BD_VALUE* bd) { bd->i = AREA_Alloc((u32)bd->i); }
}  // namespace n0016e598

// 0016e5c8 (from ys/traps.cpp)
namespace n0016e5c8 {
extern void AREA_Free(s32) asm("_ZN4AREA4FreeEPv");
void trap_memory_free(BD_VALUE* bd) asm("_ZN2YS16trap_memory_freeEP8BD_VALUE");
void trap_memory_free(BD_VALUE* bd) { AREA_Free(bd->i); }
}  // namespace n0016e5c8

// 0016e5e0 (from ys/traps.cpp)
namespace n0016e5e0 {
extern void dk_Timer_setCountDown(s32) asm("_ZN2dk5Timer12setCountDownEj");
extern void dk_Timer_start(void) asm("_ZN2dk5Timer5startEv");
void trap_timer_count_down(BD_VALUE* bd) asm("_ZN2YS21trap_timer_count_downEP8BD_VALUE");
void trap_timer_count_down(BD_VALUE* bd) {
    dk_Timer_setCountDown(bd->i);
    dk_Timer_start();
}
}  // namespace n0016e5e0

// 0016e600 .. 0016e620 (never written before: timer traps)
namespace g0016e600 {
void func_0014c970(s32) asm("func_0014c970");
void dk_Timer_start(void) asm("_ZN2dk5Timer5startEv");
void func_0016e600(BD_VALUE* bd) asm("func_0016e600");
void func_0016e600(BD_VALUE* bd) {
    func_0014c970(bd->i);
    dk_Timer_start();
}
void func_001a9160(s32) asm("func_001a9160");
void func_0016e620(BD_VALUE* bd) asm("func_0016e620");
void func_0016e620(BD_VALUE* bd) { func_001a9160(bd->i); }
}  // namespace g0016e600

// 0016e638 (from ys/traps.cpp)
namespace n0016e638 {
extern void YS_SAVEFLAG_Reset(s32) asm("_ZN2YS8SAVEFLAG5ResetEj");
void trap_saveflag_reset(BD_VALUE* bd) asm("_ZN2YS19trap_saveflag_resetEP8BD_VALUE");
void trap_saveflag_reset(BD_VALUE* bd) { YS_SAVEFLAG_Reset(bd->i); }
}  // namespace n0016e638

// 0016e650 (from ys/traps.cpp)
namespace n0016e650 {
extern s32 YS_SAVEFLAG_Check(s32) asm("_ZN2YS8SAVEFLAG5CheckEj");
void trap_saveflag_check(BD_VALUE* bd) asm("_ZN2YS19trap_saveflag_checkEP8BD_VALUE");
void trap_saveflag_check(BD_VALUE* bd) { bd->i = YS_SAVEFLAG_Check(bd->i); }
}  // namespace n0016e650

// 0016e680 (never written before: empty trap)
namespace g0016e680 {
void func_0016e680(void) asm("func_0016e680");
void func_0016e680(void) {}
}  // namespace g0016e680

// 0016e688 (from anon/batch_w1.cpp)
namespace n0016e688 {
void YS__PARTRAM__set_item_max(s32, s32) asm("YS__PARTRAM__set_item_max");
void trap_assert(BD_VALUE* bd) asm("_ZN2YS11trap_assertEP8BD_VALUE");
void trap_assert(BD_VALUE* bd) {
    s32 a = bd[0].i;
    YS__PARTRAM__set_item_max(a, bd[1].i);
}
}  // namespace n0016e688

// 0016e6a8 .. 0016e700 (never written before: byte adds/stores on a party ram entry)
namespace g0016e6a8 {
void func_0016e6a8(BD_VALUE* bd) asm("func_0016e6a8");
void func_0016e6a8(BD_VALUE* bd) { u8* o = (u8*)bd[0].p; o[9] += (u8)bd[1].u; }
void func_0016e6c0(BD_VALUE* bd) asm("func_0016e6c0");
void func_0016e6c0(BD_VALUE* bd) { u8* o = (u8*)bd[0].p; o[10] += (u8)bd[1].u; }
void func_0016e6d8(BD_VALUE* bd) asm("func_0016e6d8");
void func_0016e6d8(BD_VALUE* bd) { u8* o = (u8*)bd[0].p; o[11] += (u8)bd[1].u; }
void func_0016e6f0(BD_VALUE* bd) asm("func_0016e6f0");
void func_0016e6f0(BD_VALUE* bd) { ((u8*)bd[0].p)[14] = (u8)bd[1].u; }
void func_0016e700(BD_VALUE* bd) asm("func_0016e700");
void func_0016e700(BD_VALUE* bd) { u8* o = (u8*)bd[0].p; o[8] += (u8)bd[1].u; }
}  // namespace g0016e6a8

// 0016e718 (from anon/batch_w5.cpp)
namespace n0016e718 {
extern void func_00188b68(s32, s32, u32) asm("_ZN2YS7PARTRAM11add_abilityEib");
void trap_partram_add_ability(BD_VALUE* bd) asm("_ZN2YS24trap_partram_add_abilityEP8BD_VALUE");
void trap_partram_add_ability(BD_VALUE* bd) {
    s32 a = bd[0].i;
    func_00188b68(a, bd[1].i, bd[2].i != 0);
}
}  // namespace n0016e718

// 0016e740 (from ys/traps.cpp)
namespace n0016e740 {
extern void SOUND_SE3DDisable(void*) asm("_ZN5SOUND11SE3DDisableEv");
void trap_sound_disable(BD_VALUE* bd) asm("_ZN2YS18trap_sound_disableEP8BD_VALUE");
void trap_sound_disable(BD_VALUE* bd) { SOUND_SE3DDisable(bd); }
}  // namespace n0016e740

// 0016e758 .. 0016e7a0 (never written before: sound traps)
namespace g0016e758 {
void SOUND_systemSePlay(s32, s32) asm("_ZN5SOUND12systemSePlayEii");
void func_0016e758(BD_VALUE* bd) asm("func_0016e758");
void func_0016e758(BD_VALUE* bd) { SOUND_systemSePlay(bd->i, 0); }
void SOUND__silentBgSeOff(void) asm("SOUND__silentBgSeOff");
void func_002bbed0(void) asm("func_002bbed0");
void func_0016e778(BD_VALUE* bd) asm("func_0016e778");
void func_0016e778(BD_VALUE* bd) {
    if (bd->i > 0) SOUND__silentBgSeOff();
    else func_002bbed0();
}
void func_001a6c90(s32) asm("func_001a6c90");
void func_0016e7a0(BD_VALUE* bd) asm("func_0016e7a0");
void func_0016e7a0(BD_VALUE* bd) { func_001a6c90(bd->i); }
}  // namespace g0016e758

// 0016e7b8 (from ys/traps.cpp)
namespace n0016e7b8 {
extern void YS_MENUFLAG_Reset(s32) asm("_ZN2YS8MENUFLAG5ResetEi");
void trap_menuflag_reset(BD_VALUE* bd) asm("_ZN2YS19trap_menuflag_resetEP8BD_VALUE");
void trap_menuflag_reset(BD_VALUE* bd) { YS_MENUFLAG_Reset(bd->i); }
}  // namespace n0016e7b8

// 0016e7d0 (from ys/traps.cpp)
namespace n0016e7d0 {
extern s32 YS_MENUFLAG_Check(s32) asm("_ZN2YS8MENUFLAG5CheckEi");
void trap_menuflag_check(BD_VALUE* bd) asm("_ZN2YS19trap_menuflag_checkEP8BD_VALUE");
void trap_menuflag_check(BD_VALUE* bd) { bd->i = YS_MENUFLAG_Check(bd->i); }
}  // namespace n0016e7d0

// 0016e800 (from anon/tiny_auto80_solver.cpp)
namespace n0016e800 {
u32 YS__ITEM__Get(u32, u32, u32, u32, u32, u32, u32, u32) asm("YS__ITEM__Get");
u32 func_0016e800(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_ZN2YS13trap_item_getEP8BD_VALUE");
u32 func_0016e800(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a0;
    u32 v0 = YS__ITEM__Get(*(u32*)a0, *(u32*)(s0 + 4), 0, a3, a4, a5, a6, a7);
    *(u32*)s0 = v0;
    return v0;
}
}  // namespace n0016e800

// 0016e838 (from ys/traps.cpp)
namespace n0016e838 {
extern void YS_ITEM_Reduce(s32, s32) asm("_ZN2YS4ITEM6ReduceEii");
void trap_item_reduce(BD_VALUE* bd) asm("_ZN2YS16trap_item_reduceEP8BD_VALUE");
void trap_item_reduce(BD_VALUE* bd) { YS_ITEM_Reduce(bd->i, bd[1].i); }
}  // namespace n0016e838

// 0016e858 (from anon/tiny_auto80_queue.cpp)
namespace n0016e858 {
extern u8 D_0034d8a8 asm("D_0034d8a8");
void func_0016e858(u32 a0, u32 a1) asm("_Z16wtarget_0016e858jjjj");
void func_0016e858(u32 a0, u32 a1) {
    if (a1 == 0xffffu) {
        if (a0 == 1u) {
            *(u32*)&D_0034d8a8 = a0;
        }
    }
}
}  // namespace n0016e858

// 0016e878 .. 0016e8b0 (never written before: the empty atexit destructors of the function-local statics)
namespace g0016e878 {
void func_0016e878(void) asm("func_0016e878");
void func_0016e878(void) {}
void func_0016e880(void) asm("func_0016e880");
void func_0016e880(void) {}
void func_0016e888(void) asm("func_0016e888");
void func_0016e888(void) {}
void func_0016e890(void) asm("func_0016e890");
void func_0016e890(void) {}
void func_0016e898(void) asm("func_0016e898");
void func_0016e898(void) {}
void func_0016e8a0(void) asm("func_0016e8a0");
void func_0016e8a0(void) {}
void func_0016e8a8(void) asm("func_0016e8a8");
void func_0016e8a8(void) {}
void func_0016e8b0(void) asm("func_0016e8b0");
void func_0016e8b0(void) {}
}  // namespace g0016e878

// 0016e8b8 (from anon/tiny_wrappers_more.cpp)
namespace n0016e8b8 {
u32 func_0016e858(u32, u32, u32, u32) asm("_Z16wtarget_0016e858jjjj");
u32 func_0016e8b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0016e8b8");
u32 func_0016e8b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0016e858(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n0016e8b8

// 0016e8d8 (never written before: the _GLOBAL__D_ stub)
namespace g0016e8d8 {
u32 func_0016e858(u32, u32, u32, u32) asm("_Z16wtarget_0016e858jjjj");
u32 func_0016e8d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0016e8d8");
u32 func_0016e8d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0016e858(0, 0x0000ffffu, a2, a3);
}
}  // namespace g0016e8d8
