// Linked unit 0x002e7ae0-0x002e8b50 (one namespace per old matched source; 26 gap functions written).
#include "../common/types.h"
#include <stdarg.h>
#include "../yasui/libys/attack.hpp"
#include "../yasui/libys/battlereport.hpp"
#include "../yasui/libys/progress.hpp"

// 002e7ae0 (was an unwritten gap)
namespace g002e7ae0 {
void func_001e0428(f32, f32, f32, f32, f32, f32, f32) asm("func_001e0428");
void gap_002e7ae0(f32* v) asm("gap_002e7ae0");
void gap_002e7ae0(f32* v) { func_001e0428(v[0], v[1], v[2], v[3], v[4], v[5], v[6]); }
}  // namespace g002e7ae0

// 002e7b10 (was src/anon/batch_w2.cpp)
namespace n002e7b10 {
void func_001a55a8(u32, u32) asm("func_001a55a8");
/*TARGET 002e7b10*/
// 0x002ba330: definition moved into src/anon/unit_002b9ab8.cpp

void func_002e7b10(u32* v) asm("func_002e7b10");
// 0x002ba330: definition moved into src/anon/unit_002b9ab8.cpp

void func_002e7b10(u32* v) {
    u32 a = v[0];
    func_001a55a8(a, v[1]);
}
}  // namespace n002e7b10

// 002e7b30 (was an unwritten gap)
namespace g002e7b30 {
extern u8* D_0034e948 asm("D_0034e948");
void gap_002e7b30(u32* v) asm("gap_002e7b30");
void gap_002e7b30(u32* v) { v[0] = *(u32*)(D_0034e948 + 2896); }
}  // namespace g002e7b30

// 002e7b48 (was src/anon/tiny_wrappers_imp.cpp)
namespace n002e7b48 {
u32 func_0016bd60(u32, u32, u32, u32) asm("_Z13func_0016bd60jjjj");
/*TARGET 002e7b48*/
// 0x002df1a8: definition moved into src/anon/unit_002de3c8.cpp

// 002e3890: moved to src/anon/unit_002e2f08.cpp

u32 func_002e7b48(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e7b48jjjj");
// 0x002df1a8: definition moved into src/anon/unit_002de3c8.cpp

// 002e3890: moved to src/anon/unit_002e2f08.cpp

u32 func_002e7b48(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0035u << 16);
    r5 = (u32)((s32)0u + (43));
    r4 = *(u32*)((u32)r15 + (s32)(-5816));
    return func_0016bd60(r4, r5, r6, r7);
}
}  // namespace n002e7b48

// 002e7b68 (was src/anon/tiny_wrappers_imp.cpp)
namespace n002e7b68 {
u32 func_0016bd60(u32, u32, u32, u32) asm("_Z13func_0016bd60jjjj");
/*TARGET 002e7b68*/
u32 func_002e7b68(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e7b68jjjj");
u32 func_002e7b68(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0035u << 16);
    r5 = (u32)((s32)0u + (46));
    r4 = *(u32*)((u32)r15 + (s32)(-5816));
    return func_0016bd60(r4, r5, r6, r7);
}
}  // namespace n002e7b68

// 002e7b88 (was src/anon/batch_w3.cpp)
namespace n002e7b88 {
// 0x002c0700: definition moved into src/anon/unit_002bebd0.cpp

void func_002eac70(f32, f32, f32, f32) asm("func_002eac70");
/*TARGET 002e7b88*/
void func_002e7b88(f32* v) asm("func_002e7b88");
void func_002e7b88(f32* v) { func_002eac70(v[0], v[1], v[2], v[3]); }
}  // namespace n002e7b88

// 002e7bb0 (was an unwritten gap)
namespace g002e7bb0 {
void func_002eaea8(f32, f32, f32, f32, f32, f32, f32) asm("func_002eaea8");
void gap_002e7bb0(f32* v) asm("gap_002e7bb0");
void gap_002e7bb0(f32* v) { func_002eaea8(v[0], v[1], v[2], v[3], v[4], v[5], v[6]); }
}  // namespace g002e7bb0

// 002e7be0 (was src/anon/batch_w3.cpp)
namespace n002e7be0 {
void func_002e9a00(s32, s32) asm("func_002e9a00");
/*TARGET 002e7be0*/
void func_002e7be0(BD_VALUE* bd) asm("func_002e7be0");
void func_002e7be0(BD_VALUE* bd) {
    BD_VALUE a = bd[0];
    func_002e9a00(a.i, bd[1].i);
}
}  // namespace n002e7be0

// 002e7c00 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e7c00 {
u32 func_002e9fa8(u32, u32, u32, u32) asm("_Z13func_002e9fa8jjjj");
/*TARGET 002e7c00*/
// 002e7aa0: _GLOBAL__I_ stub, now made by gcc in src/anon/unit_002e7658.cpp

u32 func_002e7c00(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e7c00jjjj");
// 002e7aa0: _GLOBAL__I_ stub, now made by gcc in src/anon/unit_002e7658.cpp

u32 func_002e7c00(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002e9fa8(((u32)(*(u32*)((u32)(a0) + 0u))), a1, a2, a3);
}
}  // namespace n002e7c00

// 002e7c18 (was src/anon/batch_w48.cpp)
namespace n002e7c18 {
struct Vq {
    f32 x, y, z, w;
    Vq() {}
    Vq(const Vq& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// 002e3b88: moved to src/anon/unit_002e2f08.cpp

void func_002e9d08(u32, u32, const Vq&, const Vq&, s32, s32, s32) asm("func_002e9d08");
/*TARGET 002e7c18*/
void func_002e7c18(u32* o) asm("func_002e7c18");
void func_002e7c18(u32* o) {
    u32 a = o[0];
    Vq d = *(Vq*)o[3];
    Vq c = *(Vq*)o[2];
    s32 g = o[6] != 0;
    s32 e = o[4] != 0;
    s32 f = o[5] != 0;
    func_002e9d08(a, o[1], c, d, e, f, g);
}
}  // namespace n002e7c18

// 002e7c78 (was src/anon/batch_w6.cpp)
namespace n002e7c78 {
// 002e7768: moved to src/anon/unit_002e7658.cpp

void func_0016c568(u32, u32, f32) asm("func_0016c568");
/*TARGET 002e7c78*/
void func_002e7c78(u32* p) asm("func_002e7c78");
void func_002e7c78(u32* p) {
    u32 o = ((u32*)p[0])[1];
    func_0016c568(o, p[1], *(f32*)&p[2]);
}
}  // namespace n002e7c78

// 002e7ca0 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n002e7ca0 {
u32 func_0019c6f0(u32, u32, u32, u32) asm("_Z13func_0019c6f0jjjj");
/*TARGET 002e7ca0*/
// 0x002e1140: definition moved into src/anon/unit_002de3c8.cpp

// 002e3510: moved to src/anon/unit_002e2f08.cpp

// 002e3810: moved to src/anon/unit_002e2f08.cpp

// 002e3ad8: moved to src/anon/unit_002e2f08.cpp

// 002e3c70: moved to src/anon/unit_002e2f08.cpp

// 002e3da8: moved to src/anon/unit_002e2f08.cpp

u32 func_002e7ca0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e7ca0jjjj");
// 0x002e1140: definition moved into src/anon/unit_002de3c8.cpp

// 002e3510: moved to src/anon/unit_002e2f08.cpp

// 002e3810: moved to src/anon/unit_002e2f08.cpp

// 002e3ad8: moved to src/anon/unit_002e2f08.cpp

// 002e3c70: moved to src/anon/unit_002e2f08.cpp

// 002e3da8: moved to src/anon/unit_002e2f08.cpp

u32 func_002e7ca0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r2 = func_0019c6f0(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n002e7ca0

// 002e7cd0 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e7cd0 {
// 0x0016a9a0: definition moved into src/anon/unit_00169f98.cpp

u32 func_0016c5a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0016c5a0jjjj");
/*TARGET 002e7cd0*/
u32 func_002e7cd0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e7cd0jjjj");
u32 func_002e7cd0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0016c5a0(((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 0u)))) + 4u))), ((u32)(*(u32*)((u32)(a0) + 4u))), a2, a3);
}
}  // namespace n002e7cd0

// 002e7cf0 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n002e7cf0 {
u32 func_0019bb58(u32, u32, u32, u32) asm("_Z13func_0019bb58jjjj");
/*TARGET 002e7cf0*/
u32 func_002e7cf0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e7cf0jjjj");
u32 func_002e7cf0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r2 = func_0019bb58(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n002e7cf0

// 002e7d20 (was src/anon/batch_wcx2.cpp)
namespace n002e7d20 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
// 00185138: moved to src/anon/unit_00183088.cpp

struct B32 { f32 a, y, c; u32 d; Vec4 pos; };
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
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
// 0x0029aac0: definition moved into src/anon/unit_00299920.cpp

struct VB30 {
    f32 x, y, z, w;
    VB30& operator=(const VB30& s) { if (this != &s) QCOPY(this, &s); return *this; }
    VB30 operator-(const VB30& b) const
    {
        VB30 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                     : : "r"(this), "r"(&b), "r"(&r) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
union UD30 { u32 u; u8* p; VB30* v; };
struct B30 { f32 a, rad, c; UD30 d; VB30 pos; };
void func_0018a818(B32*, u8*, u32) asm("func_0018a818");
s32 func_0019ba60(u8*) asm("func_0019ba60");
u8* func_0016bba8(u8*, s32, u8*) asm("func_0016bba8");
struct Find30 { s32 idx; VB30* target; };
/*TARGET 002e7d20*/
void func_002e7d20(Find30* f) asm("func_002e7d20");
void func_002e7d20(Find30* f)
{
    f32 best = 0.0f;
    s32 idx = -1;
    u8* obj = *(u8**)(*(u8**)f + 4);
    VB30* t = f->target;
    VB30 d;
    B30 b;
    b.d.u = 0;
    func_0019ba60(obj);
    u8* o = 0;
    while ((o = func_0016bba8(obj, 2, o)) != 0) {
        func_0018a818((B32*)&b, obj, (u32)o);
        d = *t - b.pos;
        f32 l2;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                     : "=f"(l2) : "r"(&d) : "$8", "memory");
        d.w = l2;
        if (idx < 0 || l2 < best) {
            best = l2;
            idx = o[1];
        }
    }
    f->idx = idx;
}
}  // namespace n002e7d20

// 002e7e28 (was an unwritten gap)
namespace g002e7e28 {
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QV& operator=(const QV& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern QV D_01e2bf80 asm("D_01e2bf80");
void gap_002e7e28(u32* v) asm("gap_002e7e28");
void gap_002e7e28(u32* v) {
    D_01e2bf80 = *(QV*)(*(u32*)(v[0] + 4) + 2208);
    v[0] = (u32)&D_01e2bf80;
}
}  // namespace g002e7e28

// 002e7e58 (was src/anon/batch_w66.cpp)
namespace n002e7e58 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// 0x002d56a0: definition moved into src/anon/unit_002d4548.cpp
// ---- 002e7e58
void func_0016bd60(u8*, s32) asm("func_0016bd60");
/*TARGET 002e7e58*/
void func_002e7e58(u8** p) asm("func_002e7e58");
void func_002e7e58(u8** p) {
    u8* o = *(u8**)(p[0] + 4);
    Vq* v = (Vq*)(o + 32);
    *v = *(Vq*)p[1];
    *(u32*)(o + 36) = 0;
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(v) : "$8", "$f0", "memory");
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(v), "f"(*(f32*)(p + 3)) : "$8", "memory");
    *(f32*)(o + 36) = -*(f32*)(p + 2);
    func_0016bd60(o, 36);
}
}  // namespace n002e7e58

// 002e7ef8 (was an unwritten gap)
namespace g002e7ef8 {
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QV& operator=(const QV& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void func_002ed1d8(u32, QV, f32, f32) asm("func_002ed1d8");
void gap_002e7ef8(BD_VALUE* bd) asm("gap_002e7ef8");
struct O { u8 pad[4]; u32 obj; };
void gap_002e7ef8(BD_VALUE* bd) { BD_VALUE a = bd[0]; u32 o = ((O*)a.p)->obj; func_002ed1d8(o, *(QV*)bd[1].p, bd[2].f, bd[3].f); }
}  // namespace g002e7ef8

// 002e7f38 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e7f38 {
u32 func_002e9b58(u32, u32, u32, u32) asm("_Z13func_002e9b58jjjj");
/*TARGET 002e7f38*/
u32 func_002e7f38(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e7f38jjjj");
u32 func_002e7f38(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002e9b58(((u32)(*(u32*)((u32)(a0) + 0u))), ((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 4u)))) + 4u))), 0xffffffffu, a3);
}
}  // namespace n002e7f38

// 002e7f60 (was an unwritten gap)
namespace g002e7f60 {
void func_002e9c98(s32, s32) asm("func_002e9c98");
void gap_002e7f60(BD_VALUE* bd) asm("gap_002e7f60");
void gap_002e7f60(BD_VALUE* bd) {
    BD_VALUE a = bd[0];
    func_002e9c98(a.i, bd[1].i);
}
}  // namespace g002e7f60

// 002e7f80 (was src/anon/batch_w45.cpp)
namespace n002e7f80 {
void func_00190128(void*) asm("func_00190128");
void func_002e9d08(u8*, void*, void*, void*, u32, u32, u32) asm("func_002e9d08");
/*TARGET 002e7f80*/
// 0x002d6ec8: definition moved into src/anon/unit_002d62d0.cpp

// 002e3a78: moved to src/anon/unit_002e2f08.cpp

void func_002e7f80(u32* a0) asm("func_002e7f80");
// 0x002d6ec8: definition moved into src/anon/unit_002d62d0.cpp

// 002e3a78: moved to src/anon/unit_002e2f08.cpp

void func_002e7f80(u32* a0) {
    u8 m[32] __attribute__((aligned(16)));
    u8 v1[16] __attribute__((aligned(16)));
    u8 v2[16] __attribute__((aligned(16)));
    func_00190128(m);
    u8* s = (u8*)a0[0];
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(v1), "r"(a0[2]) : "$8", "memory");
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(v2), "r"(a0[1]) : "$8", "memory");
    func_002e9d08(s, m, v2, v1, 1, a0[3] != 0, 0);
    a0[0] = s[5];
}
}  // namespace n002e7f80

// 002e7ff8 (was src/anon/batch_w13.cpp)
namespace n002e7ff8 {
struct Q128 { u32 w[4]; };
f32 func_001906f0(void*, void*) asm("func_001906f0");
extern void (*D_0035e380[])(void) asm("D_0035e380");
/*TARGET 002e7ff8*/
// 0x002de810: definition moved into src/anon/unit_002de3c8.cpp

void func_002e7ff8(u32* p) asm("func_002e7ff8");
// 0x002de810: definition moved into src/anon/unit_002de3c8.cpp

void func_002e7ff8(u32* p) {
    Q128 t;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(p[1]) : "$8", "memory");
    *(f32*)p = func_001906f0((void*)p[0], &t);
}
}  // namespace n002e7ff8

// 002e8038 (was src/anon/batch_w15.cpp)
namespace n002e8038 {
// Batch w15: small wrappers, destructors, list searches and leaf helpers.

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
// 0x002db7d0: definition moved into src/anon/unit_002da040.cpp

void func_002e9fe0(u32, u32, void*) asm("func_002e9fe0");
/*TARGET 002e8038*/
void func_002e8038(u32* p) asm("func_002e8038");
void func_002e8038(u32* p) {
    Q16 tmp;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&tmp), "r"(p[2]) : "$8", "memory");
    func_002e9fe0(p[0], ((u32*)p[1])[1], &tmp);
}
}  // namespace n002e8038

// 002e8070 (was src/anon/batch_w4.cpp)
namespace n002e8070 {
void func_002e9cb8(u32, u32, u32) asm("func_002e9cb8");
// 0x002d5c20: definition moved into src/anon/unit_002d4548.cpp

struct Args002e8070 {
    u32 a, b, c;
};
/*TARGET 002e8070*/
void func_002e8070(Args002e8070* p) asm("func_002e8070");
void func_002e8070(Args002e8070* p) {
    u32 b = p->b;
    u32 a = p->a;
    func_002e9cb8(a, b, p->c);
}
}  // namespace n002e8070

// 002e8098 (was an unwritten gap)
namespace g002e8098 {
void func_00190128_g(u32) asm("_ZN2YS6TARGETC1Ev");
void gap_002e8098(u32* v) asm("gap_002e8098");
void gap_002e8098(u32* v) { func_00190128_g(v[0]); }
}  // namespace g002e8098

// 002e80b0 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e80b0 {
u32 YS_TARGET_set_obj(u32, u32, u32, u32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
/*TARGET 002e80b0*/
u32 func_002e80b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e80b0jjjj");
u32 func_002e80b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return YS_TARGET_set_obj(((u32)(*(u32*)((u32)(a0) + 0u))), ((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 0u)))) + 0u))), ((u32)(*(u32*)((u32)(a0) + 4u))), a3);
}
}  // namespace n002e80b0

// 002e80d8 (was an unwritten gap)
namespace g002e80d8 {
void gap_002e80d8(u32* v) asm("gap_002e80d8");
void gap_002e80d8(u32* v) { v[0] = *(u32*)(v[0] + 4); }
}  // namespace g002e80d8

// 002e80e8 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e80e8 {
u32 func_00111040(u32, u32, u32, u32) asm("_Z13func_00111040jjjj");
/*TARGET 002e80e8*/
u32 func_002e80e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e80e8jjjj");
u32 func_002e80e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00111040(((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 0u)))) + 4u))), a1, a2, a3);
}
}  // namespace n002e80e8

// 002e8108 (was an unwritten gap)
namespace g002e8108 {
u32 func_0017df58(u32) asm("func_0017df58");
void gap_002e8108(u32* v) asm("gap_002e8108");
void gap_002e8108(u32* v) { v[0] = func_0017df58(v[0]); }
}  // namespace g002e8108

// 002e8138 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e8138 {
u32 func_001124e8(u32, u32, u32, u32) asm("_Z13func_001124e8jjjj");
/*TARGET 002e8138*/
u32 func_002e8138(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e8138jjjj");
u32 func_002e8138(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001124e8(((u32)(*(u32*)((u32)(a0) + 0u))), a1, a2, a3);
}
}  // namespace n002e8138

// 002e8150 (was src/ys/traps.cpp)
namespace n002e8150 {
extern void dk_LockOn_show(void*) asm("_ZN2dk6LockOn4showEv");
/*TARGET 002e8150*/
void trap_lockon_hide(BD_VALUE* bd) asm("_ZN2Ts16trap_lockon_hideEP8BD_VALUE");
void trap_lockon_hide(BD_VALUE* bd) { dk_LockOn_show(bd); }
}  // namespace n002e8150

// 002e8168 (was an unwritten gap)
namespace g002e8168 {
void func_0013e8a8() asm("func_0013e8a8");
void gap_002e8168(u32* v) asm("gap_002e8168");
void gap_002e8168(u32* v) { func_0013e8a8(); }
extern u32 D_0034f240 asm("D_0034f240");
void gap_002e8180(u32* v) asm("gap_002e8180");
void gap_002e8180(u32* v) { D_0034f240 |= 0x800; }
void gap_002e8198(u32* v) asm("gap_002e8198");
void gap_002e8198(u32* v) { D_0034f240 &= ~0x800; }
}  // namespace g002e8168

// 002e81b0 (was src/anon/tiny_jal_tail_wrappers.cpp)
namespace n002e81b0 {
u32 func_001a5a48() asm("_Z13func_001a5a48v");
u32 func_001bfc28() asm("_Z13func_001bfc28v");
/*TARGET 002e81b0*/
// 0x00271b58: definition moved into src/anon/unit_00271900.cpp


u32 func_002e81b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e81b0jjjj");
// 0x00271b58: definition moved into src/anon/unit_00271900.cpp


u32 func_002e81b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001a5a48();
    return func_001bfc28();
}
}  // namespace n002e81b0

// 002e81d0 (was an unwritten gap)
namespace g002e81d0 {
void func_002eb890(u32, u32) asm("func_002eb890");
struct O { u8 pad[4]; u32 obj; };
void gap_002e81d0(BD_VALUE* bd) asm("gap_002e81d0");
void gap_002e81d0(BD_VALUE* bd) { O* x = (O*)bd[0].p; O* y = (O*)bd[1].p; func_002eb890(y->obj, x->obj); }
void func_002eb920(u32, u32, f32) asm("func_002eb920");
void gap_002e81f8(BD_VALUE* bd) asm("gap_002e81f8");
void gap_002e81f8(BD_VALUE* bd) { BD_VALUE a = bd[0]; u32 x = ((O*)a.p)->obj; func_002eb920(x, bd[1].u, bd[2].f); }
}  // namespace g002e81d0

// 002e8220 (was src/anon/batch_w7.cpp)
namespace n002e8220 {
void func_002eb990(u32, u32, f32) asm("func_002eb990");
// Script-style argument block: {ptr, int, float, int}
struct Args { u32 a; u32 b; f32 c; u32 d; };
/*TARGET 002e8220*/
// 0x002ba948: definition moved into src/anon/unit_002b9ab8.cpp

void func_002e8220(Args* a) asm("func_002e8220");
// 0x002ba948: definition moved into src/anon/unit_002b9ab8.cpp

void func_002e8220(Args* a) {
    u32 p = *(u32*)(a->a + 4);
    func_002eb990(p, a->b, a->c);
}
}  // namespace n002e8220

// 002e8248 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e8248 {
u32 func_002ec960(u32, u32, u32, u32) asm("_Z13func_002ec960jjjj");
/*TARGET 002e8248*/
u32 func_002e8248(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e8248jjjj");
u32 func_002e8248(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002ec960(((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 0u)))) + 4u))), a1, a2, a3);
}
}  // namespace n002e8248

// 002e8268 (was an unwritten gap)
namespace g002e8268 {
void func_002ec9d0(u32, u32, u32) asm("func_002ec9d0");
struct O { u8 pad[4]; u32 obj; };
void gap_002e8268(BD_VALUE* bd) asm("gap_002e8268");
void gap_002e8268(BD_VALUE* bd) { BD_VALUE a = bd[0]; u32 y = bd[1].u; u32 x = ((O*)a.p)->obj; func_002ec9d0(x, y, bd[2].u); }
}  // namespace g002e8268

// 002e8290 (was src/anon/batch_w8.cpp)
namespace n002e8290 {
// 0x002bb070: definition moved into src/anon/unit_002bb070.cpp

void func_002eda90(u32, u32, f32) asm("func_002eda90");
extern u32 D_003637d0 asm("D_003637d0");
struct S2e8290 { u32 a; f32 f; };
/*TARGET 002e8290*/
void func_002e8290(S2e8290* p) asm("func_002e8290");
void func_002e8290(S2e8290* p) {
    u32 g = D_003637d0;
    func_002eda90(g, p->a, p->f);
}
}  // namespace n002e8290

// 002e82b8 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e82b8 {
u32 YS_OBJ_attach_camera(u32, u32, u32, u32) asm("_ZN2YS3OBJ13attach_cameraEPN2kn7FMatrixE");
/*TARGET 002e82b8*/
u32 func_002e82b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e82b8jjjj");
u32 func_002e82b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return YS_OBJ_attach_camera(((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 0u)))) + 4u))), 0x00000000u, a2, a3);
}
}  // namespace n002e82b8

// 002e82d8 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e82d8 {
u32 func_00194668(u32, u32, u32, u32) asm("_Z13func_00194668jjjj");
/*TARGET 002e82d8*/
u32 func_002e82d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e82d8jjjj");
u32 func_002e82d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00194668(((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 0u)))) + 4u))), a1, a2, a3);
}
}  // namespace n002e82d8

// 002e82f8 (was an unwritten gap)
namespace g002e82f8 {
void gap_002e82f8(u32* v) asm("gap_002e82f8");
void gap_002e82f8(u32* v) { u32 m = *(u32*)(*(u32*)(v[0] + 4) + 268) & 0x40; v[0] = m != 0; }
}  // namespace g002e82f8

// 002e8318 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e8318 {
u32 YS_OBJ_change_action(u32, u32, u32, u32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
/*TARGET 002e8318*/
u32 func_002e8318(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e8318jjjj");
u32 func_002e8318(u32 a0, u32 a1, u32 a2, u32 a3) {
    return YS_OBJ_change_action(((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 0u)))) + 4u))), 0x00000032u, a2, a3);
}
}  // namespace n002e8318

// 002e8338 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e8338 {
u32 YS_OBJ_change_action(u32, u32, u32, u32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
/*TARGET 002e8338*/
u32 func_002e8338(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e8338jjjj");
u32 func_002e8338(u32 a0, u32 a1, u32 a2, u32 a3) {
    return YS_OBJ_change_action(((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 0u)))) + 4u))), 0x00000034u, a2, a3);
}
}  // namespace n002e8338

// 002e8358 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e8358 {
u32 YS_OBJ_change_action(u32, u32, u32, u32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
/*TARGET 002e8358*/
u32 func_002e8358(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e8358jjjj");
u32 func_002e8358(u32 a0, u32 a1, u32 a2, u32 a3) {
    return YS_OBJ_change_action(((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 0u)))) + 4u))), 0x00000039u, a2, a3);
}
}  // namespace n002e8358

// 002e8378 (was an unwritten gap)
namespace g002e8378 {
void gap_002e8378(u32* v) asm("gap_002e8378");
void gap_002e8378(u32* v) { *(u32*)(*(u32*)(v[0] + 4) + 268) |= 0x200; }
}  // namespace g002e8378

// 002e8390 (was src/anon/batch_w33.cpp)
namespace n002e8390 {
// 0x002de698: definition moved into src/anon/unit_002de3c8.cpp

struct Own2e8 { u8 pad[4]; void* h; };
struct Obj2e8 { Own2e8* o; void* v; f32 a; f32 b; };
void func_001b2210(void*, void*, f32, f32) asm("func_001b2210");
void func_0016bd60(void*, s32) asm("func_0016bd60");
/*TARGET 002e8390*/
void func_002e8390(Obj2e8* o) asm("func_002e8390");
void func_002e8390(Obj2e8* o) {
    u8 tmp[16] __attribute__((aligned(16)));
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(tmp), "r"(o->v) : "$8", "memory");
    func_001b2210(o->o->h, tmp, o->a, o->b);
    func_0016bd60(o->o->h, 9);
}
}  // namespace n002e8390

// 002e83e8 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e83e8 {
u32 func_001d4bb8(u32, u32, u32, u32) asm("_Z13func_001d4bb8jjjj");
/*TARGET 002e83e8*/
u32 func_002e83e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e83e8jjjj");
u32 func_002e83e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d4bb8(((u32)(*(u32*)((u32)(a0) + 0u))), a1, a2, a3);
}
}  // namespace n002e83e8

// 002e8400 (was src/anon/batch_wcx.cpp)
namespace n002e8400 {
// 002e2440: moved to src/anon/unit_002e1908.cpp

u8* func_001b9bc8(u8*) asm("func_001b9bc8");
s32 func_0019c6f0(u32) asm("func_0019c6f0");
void func_0016c568(u8*, u32, f32) asm("func_0016c568");
/*TARGET 002e8400*/
void func_002e8400(u8* p) asm("func_002e8400");
void func_002e8400(u8* p)
{
    u8* a = *(u8**)(*(u8**)p + 4);
    u8* b = *(u8**)(*(u8**)(p + 12) + 4);
    u8* n = 0;
    while ((n = func_001b9bc8(n))) {
        if (n == a || n == b) continue;
        if ((*(u32*)(n + 1416) & 0x40) && !func_0019c6f0(*(u32*)(n + 2548))) continue;
        func_0016c568(n, *(u32*)(p + 4), *(f32*)(p + 8));
    }
}
}  // namespace n002e8400

// 002e84a8 (was an unwritten gap)
namespace g002e84a8 {
void func_0016c640(u32) asm("func_0016c640");
void gap_002e84a8(u32* v) asm("gap_002e84a8");
void gap_002e84a8(u32* v) { func_0016c640(v[0]); }
}  // namespace g002e84a8

// 002e84c0 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e84c0 {
u32 func_0016c5b8(u32, u32, u32, u32) asm("_Z13func_0016c5b8jjjj");
/*TARGET 002e84c0*/
u32 func_002e84c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e84c0jjjj");
u32 func_002e84c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0016c5b8(((u32)(*(u32*)((u32)(a0) + 0u))), ((u32)(*(u32*)((u32)(a0) + 4u))), a2, a3);
}
}  // namespace n002e84c0

// 002e84e0 (was an unwritten gap)
namespace g002e84e0 {
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QV& operator=(const QV& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void func_00188250(u32, u32) asm("func_00188250");
void gap_002e84e0(u32* v) asm("gap_002e84e0");
void gap_002e84e0(u32* v) { func_00188250(*(u32*)(v[0] + 4) + 768, v[1]); }
u32 func_001d35e0(u32, QV*, QV*, u32) asm("func_001d35e0");
void gap_002e8508(u32* v) asm("gap_002e8508");
void gap_002e8508(u32* v) {
    QV a;
    QV b;
    a = *(QV*)v[1];
    b = *(QV*)v[2];
    a.w = 1.0f;
    b.w = 1.0f;
    v[0] = func_001d35e0(v[0], &a, &b, v[3]);
}
}  // namespace g002e84e0

// 002e8578 (was src/anon/batch_w31.cpp)
namespace n002e8578 {
void func_001d3698(void*, u32) asm("func_001d3698");
extern u8 D_01e2bf80[] asm("D_01e2bf80");
/*TARGET 002e8578*/
void func_002e8578(u8* p) asm("func_002e8578");
void func_002e8578(u8* p) {
    u32 tmp[4] __attribute__((aligned(16)));
    func_001d3698(tmp, *(u32*)p);
    u8* d = D_01e2bf80;
    if ((u8*)tmp != d) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(tmp) : "$8", "memory");
    }
    *(u8**)p = d;
}
}  // namespace n002e8578

// 002e85c0 (was an unwritten gap)
namespace g002e85c0 {
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QV& operator=(const QV& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void gap_002e85c0(u32* v) asm("gap_002e85c0");
void gap_002e85c0(u32* v) { v[0] = ~*(u32*)(v[0] + 20) != 0; }
extern QV D_01e2bf80 asm("D_01e2bf80");
void gap_002e85d8(u32* v) asm("gap_002e85d8");
void gap_002e85d8(u32* v) {
    D_01e2bf80 = *(QV*)v[0];
    v[0] = (u32)&D_01e2bf80;
}
}  // namespace g002e85c0

// 002e8600 (was src/ys/traps.cpp)
namespace n002e8600 {
s32 func_001d36e8(s32) asm("func_001d36e8");
/*TARGET 002e8600*/
// 002e8ce0: moved to src/anon/unit_002e8b50.cpp

// 002e9120: moved to src/anon/unit_002e8b50.cpp

void trap_bghit_get_cross_pos(BD_VALUE* bd) asm("_ZN2Ts24trap_bghit_get_cross_posEP8BD_VALUE");
// 002e8ce0: moved to src/anon/unit_002e8b50.cpp

// 002e9120: moved to src/anon/unit_002e8b50.cpp

void trap_bghit_get_cross_pos(BD_VALUE* bd) { bd->i = func_001d36e8(bd->i); }
}  // namespace n002e8600

// 002e8630 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n002e8630 {
u32 func_002edbf8(u32, u32, u32, u32) asm("_Z13func_002edbf8jjjj");
/*TARGET 002e8630*/
u32 func_002e8630(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e8630jjjj");
u32 func_002e8630(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r4 = *(u32*)((u32)r4 + (s32)(0));
    r2 = func_002edbf8(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n002e8630

// 002e8660 (was an unwritten gap)
namespace g002e8660 {
void gap_002e8660(u32* v) asm("gap_002e8660");
void gap_002e8660(u32* v) {
    u8* p = (u8*)(*(u32*)(v[0] + 4) + 1656);
    p[41] = v[1];
    p[42] = v[2];
    p[43] = v[3];
}
void gap_002e8688(u32* v) asm("gap_002e8688");
void gap_002e8688(u32* v) { v[0] = *(u32*)(*(u32*)(v[0] + 4) + 2796) != 0; }
}  // namespace g002e8660

// 002e86a0 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e86a0 {
u32 YS_OBJ_change_action(u32, u32, u32, u32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
/*TARGET 002e86a0*/
u32 func_002e86a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e86a0jjjj");
u32 func_002e86a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return YS_OBJ_change_action(((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 0u)))) + 4u))), 0x00000013u, a2, a3);
}
}  // namespace n002e86a0

// 002e86c0 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n002e86c0 {
u32 func_00186ce8(u32, u32, u32, u32) asm("_Z13func_00186ce8jjjj");
/*TARGET 002e86c0*/
u32 func_002e86c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e86c0jjjj");
u32 func_002e86c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r2 = func_00186ce8(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n002e86c0

// 002e86f0 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e86f0 {
u32 func_00194468(u32, u32, u32, u32) asm("_Z13func_00194468jjjj");
/*TARGET 002e86f0*/
u32 func_002e86f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e86f0jjjj");
u32 func_002e86f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00194468(((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 0u)))) + 4u))), a1, a2, a3);
}
}  // namespace n002e86f0

// 002e8710 (was an unwritten gap)
namespace g002e8710 {
void gap_002e8710(u32* v) asm("gap_002e8710");
void gap_002e8710(u32* v) {
    if (v[1]) *(u32*)(*(u32*)(v[0] + 4) + 1896) |= 0x20;
    else *(u32*)(*(u32*)(v[0] + 4) + 1896) &= ~0x20;
}
void gap_002e8750(u32* v) asm("gap_002e8750");
void gap_002e8750(u32* v) {
    u8* p = (u8*)(*(u32*)(v[0] + 4) + 2768);
    asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(p) : "memory");
}
}  // namespace g002e8710

// 002e8770 (was src/anon/batch_w49.cpp)
namespace n002e8770 {
// 00199468: moved to src/anon/unit_001991a8.cpp

struct NoTail { ~NoTail() {} };
// 0x002636b0: definition moved into src/anon/unit_002632d0.cpp

u32 func_00190140(u8*) asm("func_00190140");
u32 func_00176fb0(u8*, u32) asm("func_00176fb0");
void func_00177008(u8*, u32, u8*) asm("func_00177008");
/*TARGET 002e8770*/
void func_002e8770(u8** a) asm("func_002e8770");
void func_002e8770(u8** a) {
    NoTail g;
    u8* o = a[0];
    if (*(u32*)(o + 1416) & 0x80) {
        u8* q = *(u8**)(o + 2880) + 4;
        func_00190140(q);
        func_00177008(o, func_00176fb0(o, (u32)a[1]), q);
    }
}
}  // namespace n002e8770

// 002e87e0 (was src/anon/batch_wcx2.cpp)
namespace n002e87e0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
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
#define QCOPY_2e87e0(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V2e87e0 {
    f32 x, y, z, w;
    V2e87e0() {}
    V2e87e0(const V2e87e0& o) { QCOPY_2e87e0(this, &o); }
    V2e87e0& operator=(const V2e87e0& o) { if (this != &o) QCOPY_2e87e0(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline V2e87e0 Cross2e87e0(const V2e87e0& a, const V2e87e0& b)
{
    V2e87e0 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf3, $vf0, $vf0\n\t"
                 "vopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline V2e87e0 Scale2e87e0(const V2e87e0& a, f32 k)
{
    V2e87e0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline f32 Normalize2e87e0(V2e87e0* v)
{
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct M2e87e0 { V2e87e0 r[4]; V2e87e0 t; };
struct A2e87e0 { V2e87e0* dir; V2e87e0* up; };
extern V2e87e0 D_01e2bf80 asm("D_01e2bf80");
void func_0011b6a8_2e87e0(M2e87e0*) asm("func_0011b6a8");
void func_0011bac8(M2e87e0*, V2e87e0*) asm("func_0011bac8");
/*TARGET 002e87e0*/
void func_002e87e0(A2e87e0* a) asm("func_002e87e0");
void func_002e87e0(A2e87e0* a)
{
    M2e87e0 m;
    V2e87e0& r1 = m.r[1];
    V2e87e0& r2 = m.r[2];
    V2e87e0 z(*a->dir);
    V2e87e0* up = a->up;
    Normalize2e87e0(&z);
    Normalize2e87e0(up);
    z.w = 0.0f;
    up->w = 0.0f;
    if (up == &z) {
        z.z = z.w;
        z.y = -1.0f;
        z.x = z.w;
    }
    func_0011b6a8_2e87e0(&m);
    m.r[0] = Cross2e87e0(*up, z);
    Normalize2e87e0(&m.r[0]);
    m.r[0].w = 0.0f;
    r2 = Scale2e87e0(z, -1.0f);
    r2.w = 0.0f;
    *up = Cross2e87e0(z, m.r[0]);
    r1 = Cross2e87e0(r2, m.r[0]);
    Normalize2e87e0(&r1);
    r1.w = 0.0f;
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(&D_01e2bf80) : "memory");
    func_0011bac8(&m, &D_01e2bf80);
    a->dir = &D_01e2bf80;
}
}  // namespace n002e87e0

// 002e8a28 (was src/anon/batch_w51.cpp)
namespace n002e8a28 {
typedef void (*VFn)(void*);
u32 func_0016a070(void*) asm("func_0016a070");
s32 func_001b9bc8(u32) asm("func_001b9bc8");
/*TARGET 002e8a28*/
// Call slot 17 on every other object with the same part number as this one.
void func_002e8a28(u32** p) asm("func_002e8a28");
// Call slot 17 on every other object with the same part number as this one.
void func_002e8a28(u32** p) {
    u32 me = (*p)[1];
    u32 type = func_0016a070((void*)me);
    u32 o = 0;
    while ((o = func_001b9bc8(o)) != 0) {
        if (func_0016a070((void*)o) == type && o != me) (*(VFn*)(*(u8**)o + 68))((void*)o);
    }
}
}  // namespace n002e8a28

// 002e8ab0 (was an unwritten gap)
namespace g002e8ab0 {
u32 func_00198580(u32, u32) asm("func_00198580");
void gap_002e8ab0(u32* v) asm("gap_002e8ab0");
void gap_002e8ab0(u32* v) { v[0] = func_00198580(*(u32*)(v[0] + 4), v[1]); }
}  // namespace g002e8ab0

// 002e8ae8 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e8ae8 {
u32 func_002bc358(u32, u32, u32, u32) asm("_Z13func_002bc358jjjj");
/*TARGET 002e8ae8*/
u32 func_002e8ae8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e8ae8jjjj");
u32 func_002e8ae8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002bc358(((u32)(*(u32*)((u32)(a0) + 0u))), ((u32)(*(u32*)((u32)(a0) + 4u))), a2, a3);
}
}  // namespace n002e8ae8

// 002e8b08 (was src/anon/batch_w1665.cpp)
namespace n002e8b08 {
// 002e3ef0: moved to src/anon/unit_002e2f08.cpp
void wt_2e8b08(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002e8b08jjjj");
/*TARGET 002e8b08*/
void wt_2e8b08(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002e8b08jjjj");
void wt_2e8b08(u32 a, u32 b, u32 c, u32 d) {}
}  // namespace n002e8b08

// 002e8b10 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e8b10 {
u32 func_002e8b08(u32, u32, u32, u32) asm("_Z13func_002e8b08jjjj");
/*TARGET 002e8b10*/
u32 func_002e8b10(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e8b10jjjj");
u32 func_002e8b10(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002e8b08(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n002e8b10

// 002e8b30 (was an unwritten gap)
namespace g002e8b30 {
void func_002e8b08_g(u32, u32) asm("func_002e8b08");
void gap_002e8b30(u32* v) asm("gap_002e8b30");
void gap_002e8b30(u32* v) { func_002e8b08_g(0, 0xffff); }
}  // namespace g002e8b30

