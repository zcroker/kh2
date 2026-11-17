#include "../common/types.h"

// Ts target searcher (0x2e9a00-0x2ea0f0, plus the gap fn 0x2ea0f0 at the end): init, the "already locked" ring of recent targets, the
// target filters, the nearest/farthest search and the nearest-hit-sphere search. Each function keeps
// the declarations of the source it was matched in (namespace nADDR); every symbol is bound by asm label.

// 002e9a00 (from src/anon/auto200_999.cpp)
namespace n002e9a00 {
struct T { u32 a; u32 b; u32 c; u32 d; u32 e; f32 r; f32 ang; };
void func_002e9a00(T* p, u32 a1) asm("func_002e9a00");
void func_002e9a00(T* p, u32 a1) {
    p->a = a1;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->ang = 3.1415925f;
    p->r = 1000.0f;
}
}  // namespace n002e9a00

// 002e9a38 (from src/anon/tiny_auto80_queue.cpp)
namespace n002e9a38 {
u32 func_002e9a38(u32* a0, u32 a1, u32 a2) asm("func_002e9a38");
u32 func_002e9a38(u32* a0, u32 a1, u32 a2) {
    s32 t5 = (s32)a0[2];
    s32 t6 = 0;
    if (t5 <= 0) {
        goto L_fail;
    }
L_loop:
    if (a0[7] != a1) {
        goto L_miss;
    }
    if (a0[8] == a2) {
        return 1;
    }
L_miss:
    t6 = t6 + 1;
    if (t6 < t5) {
        a0 = (u32*)((u8*)a0 + 8);
        goto L_loop;
    }
L_fail:
    return 0;
}
}  // namespace n002e9a38

// 002e9a78 (from src/anon/batch_wcx2.cpp)
namespace n002e9a78 {
// 128-bit copies (lq/sq) are hand-written asm in the original.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
s32 func_001c0ce8(u8*) asm("func_001c0ce8");
s32 func_002e9a78(void* self, u8* o, s32 k) asm("func_002e9a78");
s32 func_002e9a78(void* self, u8* o, s32 k) {
    if (func_001c0cd8(o) && func_001c0ce8(o)) return 0;
    switch (k) {
    case 0: { u32 m = *(u32*)(o + 0x588) & 0x10; return m != 0; }
    case 1: { u32 m = *(u32*)(o + 0x588) & 4; return m != 0; }
    case 2: { u32 m = *(u32*)(o + 0x588) & 4; return m != 0; }
    }
    return 1;
}
}  // namespace n002e9a78

// 002e9b10 (from src/anon/batch_w32.cpp)
namespace n002e9b10 {
// 002e9338: moved to src/sugi/flare.cpp

// Advances a byte counter and wraps it into [0, max).
struct WrapCtr { s32 max; u8 cur; };
void func_002e9b10(WrapCtr* s) asm("func_002e9b10");
void func_002e9b10(WrapCtr* s) {
    s->cur++;
    while (s->cur >= s->max) s->cur -= *(u8*)&s->max;
}
}  // namespace n002e9b10

// 002e9b58 (from src/anon/batch_w84.cpp)
namespace n002e9b58 {
s32 func_0019ba60(u32) asm("func_0019ba60");
s32 func_002e9a38(u8*, u32, s32) asm("func_002e9a38");
u8* func_0016bba8(u32, s32, u8*) asm("func_0016bba8");
void func_002e9b10(u8*) asm("func_002e9b10");
void wt3_2e9b58(u32, u32, u32) asm("_Z16wtarget_002e9b58jjjj");
// Recursively registers o (or all its children when k < 0).
void wtarget_002e9b58(u32 a0, u32 o, u32 k, u32) asm("_Z16wtarget_002e9b58jjjj");
void wtarget_002e9b58(u32 a0, u32 o, u32 k, u32) {
    u8* p = (u8*)a0;
    if (!o) return;
    if (!func_0019ba60(o)) return;
    if ((s32)k < 0) {
        u8* r = 0;
        while ((r = func_0016bba8(o, 3, r)) != 0) wt3_2e9b58(a0, o, *r);
        return;
    }
    if (func_002e9a38(p, o, k)) return;
    *(u32*)(p + p[4] * 8 + 28) = o;
    *(u32*)(p + p[4] * 8 + 32) = k;
    if (*(s32*)(p + 8) < *(s32*)p) *(s32*)(p + 8) += 1;
    func_002e9b10(p);
}
}  // namespace n002e9b58

// 002e9c58 (from src/anon/batch_w15.cpp)
namespace n002e9c58 {
u8 func_0019bc38(void*) asm("func_0019bc38");
u8 func_002e9c58(u8* a, u8* b) asm("func_002e9c58");
u8 func_002e9c58(u8* a, u8* b) {
    if (*(u32*)(a + 12) != 2 && !(*(u32*)(b + 1416) & 4)) return func_0019bc38(b);
    return 1;
}
}  // namespace n002e9c58

// 002e9c98 (from src/anon/batch_w4.cpp)
namespace n002e9c98 {
struct Pair {
    u32 a, b;
};
void func_002e9b58(u32, u32, u32) asm("func_002e9b58");
void func_002e9c98(u32 x, Pair* p) asm("func_002e9c98");
void func_002e9c98(u32 x, Pair* p) {
    u32 a = p->a;
    func_002e9b58(x, a, p->b);
}
}  // namespace n002e9c98

// 002e9cb8 (from src/anon/tiny_auto80_queue.cpp)
namespace n002e9cb8 {
extern "C" u32 func_00190878(...) asm("func_00190878");
extern "C" u32 func_00190878(...) asm("func_00190878");
extern "C" u32 func_00190878(...) asm("func_00190878");
void func_002e9cb8(u8* a0, u32 a1, u32 a2) asm("_ZN2Ts15TARGET_SEARCHER7get_oldEPN2YS6TARGETEi");
void func_002e9cb8(u8* a0, u32 a1, u32 a2) {
    u8* t4 = a0;
    s32 t6 = (s32)(u32)a0[4];
    s32 t5 = *(s32*)(a0 + 0);
    t6 = t6 - (s32)a2;
    t6 = t6 + t5;
    t6 = t6 - 1;
    s32 t7 = t6 % t5;
    t4 = t4 + ((u32)t7 << 3);
    func_00190878(a1, *(u32*)(t4 + 28), *(u32*)(t4 + 32));
}
}  // namespace n002e9cb8

// 002e9d08 (from src/anon/batch_wcx2.cpp)
namespace n002e9d08 {
// 128-bit copies (lq/sq) are hand-written asm in the original.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
u8* func_0016bba8(u8*, s32, u8*) asm("func_0016bba8");
u8* func_0016bba8(u8*, s32, u8*) asm("func_0016bba8");
double func_00313b80(f32) asm("func_00313b80");
s32 func_003142e0(double, double) asm("func_003142e0");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
s32 func_001c0ce8(u8*) asm("func_001c0ce8");
s32 func_002e9a78(void* self, u8* o, s32 k) asm("func_002e9a78");
// --------------------
// VU0 macro-mode vector helpers (hand-written vu0 library idioms) and lq/sq copy
struct V2e9d08 {
    f32 x, y, z, w;
    V2e9d08() {}
    V2e9d08& operator=(const V2e9d08& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline V2e9d08 Sub2e9d08(const V2e9d08& a, const V2e9d08& b)
{
    V2e9d08 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Length2e9d08(const V2e9d08& v)
{
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\t"
                 "vsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(len) : "r"(&v) : "$8", "memory");
    return len;
}
struct B2e9d08 { f32 a, y, c; u32 d; V2e9d08 pos; };
struct S2e9d08 { u8 pad[4]; u32 flags; u8 pad8[4]; s32 fc; f32 minDist, maxDist, maxAng; };
void func_0018a818_2e9d08(B2e9d08*, u8*, u8*) asm("func_0018a818");
void func_00190128_2e9d08(u32*) asm("func_00190128");
void func_00190878_2e9d08(u32*, u8*, u8) asm("func_00190878");
u8* func_001b9bc8(u8*) asm("func_001b9bc8");
s32 func_002e9a38(S2e9d08*, u8*, u8) asm("func_002e9a38");
s32 func_002e9c58(S2e9d08*, u8*) asm("func_002e9c58");
void func_002e9c98(S2e9d08*, u32*) asm("func_002e9c98");
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");
f32 func_0017ce10(f32) asm("func_0017ce10");
void func_002e9d08(S2e9d08* s, u32* res, V2e9d08* origin, V2e9d08* dir, u8 nearest, u8 flat, u8 check) asm("func_002e9d08");
void func_002e9d08(S2e9d08* s, u32* res, V2e9d08* origin, V2e9d08* dir, u8 nearest, u8 flat, u8 check)
{
    B2e9d08 b;
    V2e9d08 d;
    f32 best = 0.0f;
    u8* o = 0;
    b.d = 0;
    func_00190128_2e9d08(res);
    ((u8*)s)[5] = 0;
    while ((o = func_001b9bc8(o)) != 0) {
        if (!func_002e9a78(s, o, s->fc)) continue;
        if ((s->flags & 0x10000) && (*(u32*)(o + 0x108) & 0x8000)) continue;
        if (!func_002e9c58(s, o)) continue;
        u8* e = 0;
        f32 k = 3.1415925f;
        while ((e = func_0016bba8(o, 3, e)) != 0) {
            ((u8*)s)[5]++;
            if (check && func_002e9a38(s, o, *e)) continue;
            func_0018a818_2e9d08(&b, o, e);
            d = Sub2e9d08(b.pos, *origin);
            if (flat) d.y = 0.0f;
            f32 len = Length2e9d08(d);
            f32 v = len;
            if (len < s->minDist) continue;
            if (s->maxDist < len) continue;
            if (s->maxAng < k) {
                f32 a = func_002f8ad0(dir->x, dir->z) - func_002f8ad0(d.x, d.z);
                a = func_0017ce10(a);
                if (func_003142e0(func_00313b80(a), 0.0) < 0) a = -a;
                if (s->maxAng <= a) continue;
            }
            if (!nearest) v = -len;
            if (*res == 0 || v < best) {
                best = v;
                func_00190878_2e9d08(res, o, *e);
            }
        }
    }
    if (*res != 0 && check) func_002e9c98(s, res);
}
}  // namespace n002e9d08

// 002e9fa8 (from src/anon/tiny_auto80.cpp)
namespace n002e9fa8 {
void func_002e9fa8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002e9fa8");
void func_002e9fa8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(volatile u8*)((u32)r4 + (s32)(4)) = (u8)0u;
    *(volatile u32*)((u32)r4 + (s32)(8)) = 0u;
}
}  // namespace n002e9fa8

// 002e9fb8 (from src/anon/batch_w9.cpp)
namespace n002e9fb8 {
struct Flags2e9fb8 { u32 lo : 16; u32 flag : 1; u32 hi : 15; };
void func_002e9fb8(u8* p, u8 b) asm("func_002e9fb8");
void func_002e9fb8(u8* p, u8 b) {
    ((Flags2e9fb8*)(p + 4))->flag = b != 0;
}
}  // namespace n002e9fb8

// 002e9fe0 (from src/anon/batch_wcx2.cpp)
namespace n002e9fe0 {
// 128-bit copies (lq/sq) are hand-written asm in the original.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
// 00185138: moved to src/anon/unit_00183088.cpp

struct B32 { f32 a, y, c; u32 d; Vec4 pos; };
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
void func_0018a818(B32*, u8*, u32) asm("func_0018a818");
struct VA14;
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
struct VB36 {
    f32 x, y, z, w;
    VB36& operator=(const VB36& s) { if (this != &s) QCOPY(this, &s); return *this; }
    VB36 operator-(const Vec4& b) const
    {
        VB36 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                     : : "r"(this), "r"(&b), "r"(&r) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct B36 { f32 a, rad, c; u32 d; VB36 pos; };
struct It36 { u32 cur; u8 pad[28]; };
void func_00190128(It36*) asm("func_00190128");
u8* func_0016bba8(u8*, s32, u8*) asm("func_0016bba8");
void func_00190878(It36*, u8*, u8) asm("func_00190878");
void func_002e9fe0(It36* it, u8* obj, Vec4* pos) asm("func_002e9fe0");
void func_002e9fe0(It36* it, u8* obj, Vec4* pos)
{
    B36 b;
    VB36 d;
    f32 best = 0.0f;
    u8* o = 0;
    b.d = 0;
    func_00190128(it);
    while ((o = func_0016bba8(obj, 3, o)) != 0) {
        func_0018a818((B32*)&b, obj, (u32)o);
        d = b.pos - *pos;
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                     : "=f"(len) : "r"(&d) : "$8", "memory");
        f32 dist = len - b.rad;
        if (it->cur == 0 || dist < best) {
            best = dist;
            func_00190878(it, obj, *o);
        }
    }
}
}  // namespace n002e9fe0

// 002ea0f0 (was gap, never written): count-down motion step (sin ease toward a target object, then finish via vtable slot 8)
namespace g002ea0f0 {
#undef QCOPY
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V& operator=(const V& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline V operator*(const V& a, f32 k) {
    V r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline V operator+(const V& a, const V& b) {
    V r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct O {
    void** vt; u8 p4[56]; f32 f3c; u8 p40[2420]; u32 f9b4; f32 f9b8; f32 t; f32 tmax; u8 p9c4[12]; V pos;
};
extern f32 D_00349e10 asm("D_00349e10");
extern u8* D_0034e948 asm("D_0034e948");
extern "C" f32 sinf(f32);
V func_0016af58(O*) asm("func_0016af58");
void set_rot(O*, f32) asm("_ZN2YS3OBJ7set_rotEf");
V func_0016be98(u8*) asm("func_0016be98");
void set_pos(O*, const V&) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
u32 func_001a37e8(u32, s32) asm("func_001a37e8");
void func_00138210(u32) asm("func_00138210");
void func_002ea0f0(void*, O* o) asm("func_002ea0f0");
void func_002ea0f0(void*, O* o)
{
    f32 t = o->t - D_00349e10;
    u8* tgt = D_0034e948;
    o->t = t;
    if (0.0f < t) {
        f32 k = t / o->tmax;
        f32 s = sinf((1.0f - k) * 3.1415927f * 0.5f);
        k = 1.0f - s;
        V v;
        v = o->pos * k;
        t = k * 3.1415927f;
        v.y -= sinf(t) * 50.0f;
        set_rot(o, func_0016af58(o).w + (1.0f - k) * 0.523598731f);
        set_pos(o, func_0016be98(tgt) + v);
        if (k < 0.1f) { k *= 9.999999f; o->f3c = o->f9b8 * k; }
    } else {
        func_00138210(func_001a37e8(o->f9b4, -1));
        ((void (*)(O*))o->vt[8])(o);
    }
}
}  // namespace g002ea0f0
