// Linked unit: Ti::MGOarashi minigame objects (gimmicks, tornado, player). Built from the old per-function sources;
// functions marked "gap function" were never written before.
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
#include <stdarg.h>

// 002d2330 (was never written: gap function; was whole asm src/anon/asm_002d2330.s)
// Keep-in-range test for an object: position + offset + out, clamped by the camera frustum (002d1bf8; 002d1b90 is
// the same with the default margins, so it takes only the camera and the position).
namespace n002d2330 {
struct V {
    f32 x, y, z, w;
    V() {}
    V(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V& operator=(const V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V operator+(const V& b) const {
        V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V operator-(const V& b) const {
        V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
V* YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
void func_002d1b90(u8*, V*) asm("func_002d1b90");
void func_002d1bf8(u8*, V*, V*, V*) asm("func_002d1bf8");
void func_002d2330(u8* self, u8* o, const V& off, V& out) asm("func_002d2330");
void func_002d2330(u8* self, u8* o, const V& off, V& out)
{
    if (!self[88]) return;
    if (!(*(u32*)(o + 1416) & 0x80) && **(s32**)(o + 8) != 1565) return;
    V u = (*YS__OBJ__get_pos(o) + off) + out;
    V t = u;
    if (*(u32*)(o + 1416) & 0x80) {
        func_002d1b90(self, &t);
    } else {
        V a(50.0f, 30.0f, 0.0f, 0.0f);
        V b(50.0f, 30.0f, 0.0f, 0.0f);
        func_002d1bf8(self, &t, &a, &b);
    }
    out = (t - u) + out;
}
}  // namespace n002d2330

// 002d2498 (was never written: gap function)
namespace n002d2498 {
struct V4g { f32 x, y, z, w; V4g(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; } };
bool func_002d1e08(u8*, u8*, V4g*) asm("func_002d1e08");
bool func_002d2498(u8* a, u8* b) asm("func_002d2498");
bool func_002d2498(u8* a, u8* b)
{
    V4g v(100.0f, 100.0f, 0.0f, 0.0f);
    return !func_002d1e08(a, b, &v);
}
u32 func_002d24e0(void) asm("func_002d24e0");
u32 func_002d24e0(void) { return 1; }
}  // namespace n002d2498

// 002d24e8 (was src/anon/batch_w1818.cpp)
namespace n002d24e8 {
#define QCOPY1818(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec1818 {
    f32 x, y, z, w;
    Vec1818() {}
    Vec1818(const Vec1818& o) { QCOPY1818(this, &o); }
    Vec1818& operator=(const Vec1818& o) { if (this != &o) QCOPY1818(this, &o); return *this; }
} __attribute__((aligned(16)));
// VU0: r = a - b (all four lanes)
static inline Vec1818 operator-(const Vec1818& a, const Vec1818& b) {
    Vec1818 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
// VU0: xyz length
static inline f32 vlen1818(const Vec1818& v) {
    f32 l;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(l) : "r"(&v) : "$8", "memory");
    return l;
}
struct Obj1818 { u32 a, b; s32* id; };
struct Slot1818 { u32 x; Obj1818* p; };
struct Owner1818 { u8 pad[320]; u32 q[4]; };
// --- 002d24e8: keep the nearer of two objects with id 2031/2032
extern Vec1818* YS__OBJ__get_pos(Obj1818*) asm("YS__OBJ__get_pos");
// obj_get_attach_or_alt
extern Obj1818* func_002d1260(void) asm("func_002d1260");
/*TARGET 002d24e8*/
void Ti__MGOarashi__set_current_tornado(Owner1818* s, Obj1818* o) asm("Ti__MGOarashi__set_current_tornado");
void Ti__MGOarashi__set_current_tornado(Owner1818* s, Obj1818* o) {
    s32 id = *o->id;
    u32 r = (u32)(id - 2031) < 2;
    u8 i = id != 2031;
    if (r) {
        Slot1818* t = (Slot1818*)((i << 2) + (u32)s + 320);
        if (t->p == 0) { t->p = o; return; }
        Vec1818 base(*YS__OBJ__get_pos(func_002d1260()));
        Vec1818 d1 = *YS__OBJ__get_pos(t->p) - base;
        Vec1818 d2 = *YS__OBJ__get_pos(o) - base;
        if (vlen1818(d2) < vlen1818(d1)) t->p = o;
    }
}
}  // namespace n002d24e8

// 002d25f0 (was src/anon/batch_w37.cpp)
namespace n002d25f0 {
u8* YS__OBJ__Each(void*) asm("YS__OBJ__Each");
void Ti__MGOarashi__set_current_tornado(void*, void*) asm("Ti__MGOarashi__set_current_tornado");
/*TARGET 002d25f0*/
void func_002d25f0(void* a) asm("func_002d25f0");
void func_002d25f0(void* a) {
    u8* v = 0;
    while ((v = YS__OBJ__Each(v)) != 0) {
        if (*(u32*)(v + 1416) & 0x08000000) Ti__MGOarashi__set_current_tornado(a, v);
    }
}
}  // namespace n002d25f0

// 002d2660 (was src/anon/batch_w82.cpp)
namespace n002d2660 {
// 16-byte vector whose assignment is a 128-bit copy.
struct Vec82 {
    f32 x, y, z, w;
    Vec82& operator=(const Vec82& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
Vec82* YS__OBJ__get_pos(u32) asm("YS__OBJ__get_pos");
static inline void QCopy82(void* d, const void* s) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory"); }
static inline void VSub82(void* d, const void* a, const void* b) { asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline f32 VLen82(const void* v)
{
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(d) : "r"(v) : "$8", "memory");
    return d;
}
u8* func_002d1260(u8*) asm("func_002d1260");
u8* func_0016bc20(u32, s32, s32) asm("func_0016bc20");
/*TARGET 002d2660*/
// 002c66b8: moved to src/anon/unit_002c6420.cpp (linked unit)

// Returns the target in slot a1 if it is within its own reach radius of this object.
u32 Ti__MGOarashi__get_attach_ready_tornado(u8* a0, s32 a1) asm("Ti__MGOarashi__get_attach_ready_tornado");
// 002c66b8: moved to src/anon/unit_002c6420.cpp (linked unit)

// Returns the target in slot a1 if it is within its own reach radius of this object.
u32 Ti__MGOarashi__get_attach_ready_tornado(u8* a0, s32 a1)
{
    u32* slot = (u32*)(a1 * 4 + (u32)a0 + 320);
    u8* o;
    f32 r;
    u8 a[16] __attribute__((aligned(16)));
    u8 b[16] __attribute__((aligned(16)));
    u8 d[16] __attribute__((aligned(16)));
    if (!slot[1]) return 0;
    o = func_002d1260(a0);
    r = *(s16*)(func_0016bc20(slot[1], 5, -1) + 16);
    QCopy82(a, YS__OBJ__get_pos((u32)o));  // obj_get_attach_or_alt
    QCopy82(b, YS__OBJ__get_pos(slot[1]));  // obj_get_attach_or_alt
    VSub82(d, a, b);
    if (VLen82(d) < r) return slot[1];
    return 0;
}
}  // namespace n002d2660

// 002d2740 (was src/anon/batch_w1834_nsa.cpp)
namespace n002d2740 {
// 16-byte VU0 vector
struct W1834Vec {
    f32 x, y, z, w;
    W1834Vec() {}
    W1834Vec(const W1834Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1834Vec& operator=(const W1834Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1834VObj { u8 pad[0x10]; W1834Vec a; W1834Vec b; };
extern f32 D_00349e10 asm("D_00349e10");
// normalize xyz in place, return the old length
static inline f32 w1834_norm(W1834Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline W1834Vec w1834_mul(const W1834Vec& a, f32 s) {
    W1834Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline W1834Vec w1834_lerp(const W1834Vec& a, const W1834Vec& b, f32 t) {
    W1834Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
/*TARGET 002d2740*/
W1834Vec func_002d2740(void* self, W1834VObj* o, f32 t0, f32 t1) asm("func_002d2740");
W1834Vec func_002d2740(void* self, W1834VObj* o, f32 t0, f32 t1) {
    W1834Vec x;
    W1834Vec d = o->b;
    d.w = w1834_norm(&d);
    if (d.w <= o->a.w) {
        x = w1834_lerp(w1834_mul(o->a, o->a.w), o->b, t0);
    } else {
        x = w1834_lerp(w1834_mul(o->a, o->a.w), o->b, t1);
    }
    o->b = x;
    return w1834_mul(x, D_00349e10);
}
}  // namespace n002d2740

// 002d2870 (was src/anon/batch_w55.cpp)
namespace n002d2870 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
// 128-bit copy (lq/sq through t0).
static inline void copyQ(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
u32 func_002d1260(void) asm("func_002d1260");
s32 func_002d5c40(u32) asm("func_002d5c40");
void func_002d3fa8(Q16*, u32, u32) asm("func_002d3fa8");
/*TARGET 002d2870*/
// 0x002c5900: definition moved into src/anon/unit_002c53c8.cpp

Q16* func_002d2870(Q16* out, u8* b, u32 c) asm("func_002d2870");
// 0x002c5900: definition moved into src/anon/unit_002c53c8.cpp

Q16* func_002d2870(Q16* out, u8* b, u32 c) {
    f32* v = (f32*)out;
    v[3] = v[2] = v[1] = v[0] = 0.0f;
    if (func_002d5c40(func_002d1260()) == 2) {
        Q16 t;
        func_002d3fa8(&t, *(u32*)(b + 324), c);
        if (out != &t) copyQ(out, &t);
    }
    return out;
}
}  // namespace n002d2870

// .rodata table read by 0x2d28f8 (defined in place)
extern const u32 R_00375a40[4] asm("D_00375a40") __attribute__((aligned(4))) = { 0xa, 0x5, 0x1, 0x0 };

// 002d28f8 (was src/anon/batch_w29.cpp)
namespace n002d28f8 {
struct W3 { u32 w[3]; };
void func_001d86a0(u32, u32) asm("func_001d86a0");
extern W3 D_00375a40 asm("D_00375a40");
/*TARGET 002d28f8*/
// 0x002cf3f8: definition moved into src/anon/unit_002cf260.cpp

void func_002d28f8(u32 x, u32 m, s32 i) asm("func_002d28f8");
// 0x002cf3f8: definition moved into src/anon/unit_002cf260.cpp

void func_002d28f8(u32 x, u32 m, s32 i) {
    W3 t = D_00375a40;
    func_001d86a0(t.w[i] * m, 0);
}
}  // namespace n002d28f8

// 002d2948 (was src/anon/auto80_199_queue.cpp)
namespace n002d2948 {
/*TARGET 002d2948*/
// 0x002ce870: definition moved into src/taito/path.cpp

void func_002d2948(u8* a0) asm("_Z13func_002d2948Ph");
// 0x002ce870: definition moved into src/taito/path.cpp

void func_002d2948(u8* a0) {
    u8* s0 = a0;

    func_002cfeb0((u32)a0);  // obj_init_field1416_bit800

    *(u32*)(s0 + 0) = (u32)(&D_00360000 + 0x2230);
    func_002cf280(s0 + 2800, 1, 0);

    u32 t7 = *(u32*)(s0 + 268);
    u32 t6 = *(u32*)(s0 + 264);
    t7 = t7 | 0x8000;
    *(u32*)(s0 + 2852) = 0;
    t6 = t6 | 0x1;
    *(u32*)(s0 + 268) = t7;
    *(u32*)(s0 + 264) = t6;
}
}  // namespace n002d2948

// 002d29a8 (was src/anon/auto80_199_queue.cpp)
namespace n002d29a8 {
/*TARGET 002d29a8*/
void func_002d29a8(u8* a0) asm("_Z13func_002d29a8Ph");
void func_002d29a8(u8* a0) {
    u8* s0 = a0;

    func_002cfeb0((u32)a0);  // obj_init_field1416_bit800

    *(u32*)(s0 + 0) = (u32)(&D_00360000 + 0x2230);
    func_002cf280(s0 + 2800, 1, 0);

    u32 t7 = *(u32*)(s0 + 268);
    u32 t6 = *(u32*)(s0 + 264);
    t7 = t7 | 0x8000;
    *(u32*)(s0 + 2852) = 0;
    t6 = t6 | 0x1;
    *(u32*)(s0 + 268) = t7;
    *(u32*)(s0 + 264) = t6;
}
}  // namespace n002d29a8

// 002d2a08 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002d2a08 {
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
extern u8 D_00362230 asm("D_00362230");
/*TARGET 002d2a08*/
// 0x002d1818: definition moved into src/anon/unit_002cf260.cpp

u32 func_002d2a08(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d2a08jjjj");
// 0x002d1818: definition moved into src/anon/unit_002cf260.cpp

u32 func_002d2a08(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00362230;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002cff98)(u32, u32, u32, u32) = func_002cff98;
    r2 = fp_call4_002cff98(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002d2a08

// 002d2a30 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002d2a30 {
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
extern u8 D_00362230 asm("D_00362230");
/*TARGET 002d2a30*/
u32 func_002d2a30(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d2a30jjjj");
u32 func_002d2a30(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00362230;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002cff98)(u32, u32, u32, u32) = func_002cff98;
    r2 = fp_call4_002cff98(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002d2a30

// 002d2a58 (was src/anon/batch_w19.cpp)
namespace n002d2a58 {
void func_00105110(void*) asm("func_00105110");
u8 func_002cff98(void*) asm("func_002cff98");
extern u8 D_00362230[] asm("D_00362230");
/*TARGET 002d2a58*/
void func_002d2a58(void** p) asm("func_002d2a58");
void func_002d2a58(void** p) {
    *p = D_00362230;
    func_002cff98(p);
    func_00105110(p);
}
}  // namespace n002d2a58

// 002d2a90 (was src/anon/batch_w89.cpp)
namespace n002d2a90 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
// 16-byte vector with a qword copy constructor and a self-checking assignment.
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct VO { void (**vt)(VO*, s32, s32, VO*, s32); };
void* func_0016abf8(VO*, s32, s32, s32) asm("func_0016abf8");
QWord* func_001dc5f8(void*) asm("func_001dc5f8");
QWord YS__OBJ__get_target_pos(VO*) asm("YS__OBJ__get_target_pos");
/*TARGET 002d2a90*/
void Ti__MGOarashiGimObj__start_tornado_attack(VO* o) asm("Ti__MGOarashiGimObj__start_tornado_attack");
void Ti__MGOarashiGimObj__start_tornado_attack(VO* o) {
    s32 st = *(s32*)((u8*)o + 2924);
    if (st < 0) return;
    if (st == 0) {
        o->vt[20](o, 1548, 0, o, 0);
    } else {
        o->vt[20](o, 1549, 0, o, 0);
        void* x = func_0016abf8(o, 1, 1, 0);
        if (x) *func_001dc5f8(x) = YS__OBJ__get_target_pos(o);
    }
    *(u32*)((u8*)o + 2876) = 0;
}
}  // namespace n002d2a90

// 002d2b50 (was src/anon/batch_w2473_nsa.cpp)
namespace n002d2b50 {
struct O2d2b50;
struct V2d2b50 {
    f32 x, y, z, w;
    V2d2b50() {}
    void Set3(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; w = 0.0f; }
    V2d2b50(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V2d2b50(const V2d2b50& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V2d2b50& operator=(const V2d2b50& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2d2b50 operator-(const V2d2b50& b) const
    {
        V2d2b50 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct Rec2d2b50 { u8 pad[6]; s16 angle; s16 height; s16 mode; u8 pad2[2]; u16 turn; u8 pad3[10]; s16 h26; s16 h28; };
struct Pt2d2b50 { u8 pad[4]; f32 x, y, z; u8 pad2[20]; f32 angle; };
struct It2d2b50 { u8 pad[16]; f32 a, b, c; };
struct Cfg2d2b50 {
    u8 pad[92]; f32 f92, f96; u8 pad1[100 - 100]; u8 tab100[12]; u8 tab112[12]; u8 tab124[20];
    f32 f144, f148, f152; u8 pad2[180 - 156]; f32 f180[2]; f32 f188, f192, f196, f200; u8 pad3[240 - 204]; f32 f240, f244, f248;
};
struct O2d2b50Vt { void* f[20]; void (*msg)(O2d2b50*, s32, s32, O2d2b50*, s32); };
struct O2d2b50 {
    O2d2b50Vt* vt;
    u8 pad0[4];
    s32* kind;
    u8 pad1[944 - 12];
    s32 f944;
    u8 pad2[1344 - 948];
    V2d2b50 pos;
    u8 pad3[2076 - 1360];
    It2d2b50* item;
    u8 pad4[2800 - 2080];
    u8 lflag[4];
    s32 f2804;
    Rec2d2b50* rec;
    Pt2d2b50* pt;
    u8 pad5[2828 - 2816];
    s32 f2828;
    u8 pad6[4];
    f32 f2836, f2840, f2844, f2848, f2852;
    u8 pad7[2864 - 2856];
    V2d2b50 dir;
    V2d2b50 to;
    f32 f2896, f2900, f2904, f2908, f2912, f2916, f2920;
    s32 f2924, f2928;
    u8* f2932;
    f32 f2936, f2940;
    u8 f2944;
    u8 pad8[3];
    f32 f2948[64];
};
extern void* D_00361f60 asm("D_00361f60");
void o2d2b50_init(O2d2b50*) asm("_ZN2Ti5MGObj15_OVR_initializeEv");
void o2d2b50_change_action(O2d2b50*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
s32 func_0016ac38(O2d2b50*, s32, s32, s32, s32) asm("func_0016ac38");
void o2d2b50_0016b070(O2d2b50*, V2d2b50*) asm("_Z16wtarget_0016b070jjjj");
void o2d2b50_set(void*, u32, s32) asm("_Z16wtarget_002cf280jjjj");
Cfg2d2b50* o2d2b50_config(void*) asm("_ZN2Ti9MGOarashi6configEv");
f32 cosf(f32) asm("cosf");
f32 sinf(f32) asm("sinf");
f32 o2d2b50_atan2f(f32, f32) asm("f_atan2f");
/*TARGET 002d2b50*/
// Ti::MGOarashi object init: action, dir/to vectors, turn/side/kind setup
void func_002d2b50(O2d2b50* o) asm("func_002d2b50");
// Ti::MGOarashi object init: action, dir/to vectors, turn/side/kind setup
void func_002d2b50(O2d2b50* o)
{
    o2d2b50_init(o);
    o2d2b50_change_action(o, 3);
    void* g = D_00361f60;
    if (!o->rec) return;
    f32 ang;
    if (o->rec->angle == 0x7fff) ang = o->pt->angle;
    else ang = o->rec->angle * 3.1415927f * 0.0625f;
    f32 c = cosf(ang);
    o->dir = V2d2b50(c, -sinf(ang), 0.0f, o->rec->height);
    V2d2b50 p(o->pt->x, o->pt->y, o->pt->z, 0.0f);
    o->to = o->pos - p;
    V2d2b50 n(o->to);
    n.z = 0.0f;
    f32 len = n.normalize();
    o->f2900 = len;
    if (len < 0.01f) o->f2896 = 0.0f;
    else o->f2896 = o2d2b50_atan2f(n.y, n.x);
    switch (o->rec->turn) {
    default:
        o->f2904 = 0.0f;
        break;
    case 1: o->f2904 = o2d2b50_config(g)->f240 * 0.017453292f; break;
    case 2: o->f2904 = -(o2d2b50_config(g)->f240 * 0.017453292f); break;
    case 3: o->f2904 = o2d2b50_config(g)->f244 * 0.017453292f; break;
    case 4: o->f2904 = -(o2d2b50_config(g)->f244 * 0.017453292f); break;
    case 5: o->f2904 = o2d2b50_config(g)->f248 * 0.017453292f; break;
    case 6: o->f2904 = -(o2d2b50_config(g)->f248 * 0.017453292f); break;
    }
    if (o->rec->mode) {
        switch (o->rec->mode) {
        case 1: o->f2804 = 0; break;
        case 2: o->f2804 = 1; break;
        case 3: o->f2804 = 2; break;
        case 0:
            if (1.0f < o->pos.z) o->f2804 = 1;
            else if (o->pos.z < -1.0f) o->f2804 = 2;
            else o->f2804 = 0;
            break;
        }
        o->f2852 = 0.0f;
        switch (o->f2804) {
        case 0: o->f2852 = 0.0f; break;
        case 1: if (g) o->f2852 = o2d2b50_config(g)->f96; break;
        case 2: if (g) o->f2852 = o2d2b50_config(g)->f92; break;
        }
    }
    o->f2936 = 0.0f;
    if (*o->kind == 2031) {
        o->f2924 = 0;
        o->f944 = 1;
        o->f2828 = func_0016ac38(o, 0, 1, 0, 0);
        o2d2b50_set(o->lflag, 128, 0);
        o2d2b50_set(o->lflag, 1024, 0);
        o2d2b50_set(o->lflag, 2048, 0);
    } else if (*o->kind == 2032) {
        o->f944 = 1;
        o->f2924 = 1;
        o->f2828 = func_0016ac38(o, 0, 1, 0, 0);
        o2d2b50_set(o->lflag, 128, 0);
        o2d2b50_set(o->lflag, 1024, 0);
        o2d2b50_set(o->lflag, 2048, 0);
    } else {
        o->f2828 = 0;
        o->f944 = 2;
        o->f2924 = -1;
        switch ((u32)*o->kind) {
        case 1627:
            o->f2932 = o2d2b50_config(g)->tab112;
            o->f2936 = o2d2b50_config(g)->f148;
            break;
        case 1629:
            o->f2932 = o2d2b50_config(g)->tab124;
            o->f2936 = o2d2b50_config(g)->f152;
            break;
        case 1626:
        default:
            o->f2932 = o2d2b50_config(g)->tab100;
            o->f2936 = o2d2b50_config(g)->f144;
            break;
        }
    }
    if (o->f2924 < 0) {
        o->f944 = 0;
        o->vt->msg(o, 1236, 0, o, 0);
        o->f944 = 2;
    }
    if (o->rec->height == 0 && o->f2924 >= 0) o->f2940 = o2d2b50_config(g)->f180[o->f2924];
    else o->f2940 = -1.0f;
    o->f2928 = 0;
    o->f2836 = o2d2b50_config(g)->f192;
    o->f2840 = o2d2b50_config(g)->f188;
    o->f2844 = o2d2b50_config(g)->f196;
    o->f2848 = o2d2b50_config(g)->f200;
    if (o->item) {
        n.Set3(o->item->a, -o->item->b, -o->item->c);
        o2d2b50_0016b070(o, &n);
    }
    o->f2912 = o->rec->h26;
    o->f2908 = o->rec->h28;
    o->f2916 = 0.0f;
    o->f2944 = 0;
    o->f2920 = 0.0f;
    for (s32 i = 0; i < 64; i++) o->f2948[i] = -1.0f;
}
}  // namespace n002d2b50

// 002d3128 (was src/anon/batch_w56.cpp)
namespace n002d3128 {
// 0x2c85c8: moved to src/anon/unit_002c7e68.cpp


// 002d3128
u8* func_002d1878(u32) asm("func_002d1878");
extern u32 D_00361f60 asm("D_00361f60");
/*TARGET 002d3128*/
void Ti__MGOarashiGimObj__reserve_fall_prize(u8* p, s32 n) asm("Ti__MGOarashiGimObj__reserve_fall_prize");
void Ti__MGOarashiGimObj__reserve_fall_prize(u8* p, s32 n)
{
    f32 s = *(f32*)(func_002d1878(D_00361f60) + 80);
    for (s32 i = 0; i < 64 && n > 0; i++) {
        f32* a = (f32*)(p + 2944) + i;
        if (a[1] < 0.0f) { n--; a[1] = s * (f32)n; }
    }
}
}  // namespace n002d3128

// 002d31b0 (was src/anon/batch_w3706_nsa.cpp)
namespace n002d31b0 {
struct V2d31b0 {
    f32 x, y, z, w;
    V2d31b0() {}
    void Set3(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; w = 0.0f; }
    V2d31b0(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V2d31b0(const V2d31b0& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V2d31b0 operator+(const V2d31b0& b) const
    {
        V2d31b0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2d31b0& operator+=(const V2d31b0& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    V2d31b0& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    V2d31b0& operator=(const V2d31b0& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2d31b0 operator-(const V2d31b0& b) const
    {
        V2d31b0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct O2d31b0 {
    u8 pad0[264];
    u32 f264;
    u8 pad1[1344 - 268];
    V2d31b0 pos;
    u8 pad2[2780 - 1360];
    f32 height;
    u8 pad3[2800 - 2784];
    u8 lflag[4];
    s32 f2804;
    void* rec;
    u8 pad4[2864 - 2812];
    V2d31b0 dir;
    V2d31b0 to;
    f32 ang, radius, angVel, f2908, period, phase, bob;
    u8 pad5[2944 - 2924];
    u8 f2944;
    u8 pad6[3];
    f32 timer[64];
    bool InAir() { return 0.0f < height; }
};
extern void* D_00361f60 asm("D_00361f60");
extern f32 D_00349e10 asm("D_00349e10");
void func_0016a9a0(O2d31b0*) asm("func_0016a9a0");
void o2d31b0_set(void*, u32, s32) asm("_Z16wtarget_002cf280jjjj");
s32 o2d31b0_is_attach(O2d31b0*) asm("_ZN2YS3OBJ9is_attachEv");
V2d31b0* func_002d1f20(void*) asm("func_002d1f20");
V2d31b0 func_002d2870(void*, O2d31b0*) asm("func_002d2870");
void Ti__MGOarashiGimObj__appear_fall_prize(O2d31b0*) asm("Ti__MGOarashiGimObj__appear_fall_prize");
f32 func_002d48b8(f32) asm("func_002d48b8");
f32 cosf(f32) asm("cosf");
f32 sinf(f32) asm("sinf");
/*TARGET 002d31b0*/
// Moves the object: attach check, circular path around "to", pending timers, bobbing.
void func_002d31b0(O2d31b0* o) asm("func_002d31b0");
// Moves the object: attach check, circular path around "to", pending timers, bobbing.
void func_002d31b0(O2d31b0* o)
{
    func_0016a9a0(o);
    void* g = D_00361f60;
    // Partial asm: the original loads f264 only after g, with f264 in t7 (the register the
    // lui of g just freed). gcc hoists the load above g and picks t6.
    register u32 f asm("$15"); asm("lw %0,%1" : "=r"(f) : "m"(o->f264), "r"(g));
    o->f264 = f | 2;
    asm volatile(""); // keeps the f264 store above the f2944 load
    if (o->f2944 && !o->InAir()) o2d31b0_set(o->lflag, 4, 0);
    if (!o->rec) return;
    if (o2d31b0_is_attach(o)) return;
    V2d31b0 v(*func_002d1f20(D_00361f60));
    bool air = o->InAir();
    f32 zero = 0.0f;
    if (air) {
        o->pos.z = zero;
        o->pos.x += v.x;
    } else {
        V2d31b0 c = o->pos - o->to;
        V2d31b0 w(o->dir);
        w *= w.w * D_00349e10;
        v.z = zero;
        v.y = zero;
        w.x += v.x;
        c += w;
        o->ang = func_002d48b8(o->ang + o->angVel * D_00349e10);
        f32 cs = cosf(o->ang);
        V2d31b0 r(cs, sinf(o->ang), 0.0f, 0.0f);
        r *= o->radius;
        o->pos = c + r;
        o->pos.y += o->bob;
        o->to = o->pos - c;
        o->pos.z = zero;
    }
    o->pos += func_002d2870(g, o);
    for (s32 i = 0; i < 64; i++) {
        if (0.0f <= o->timer[i]) {
            o->timer[i] -= D_00349e10;
            if (o->timer[i] < 0.0f) Ti__MGOarashiGimObj__appear_fall_prize(o);
        }
    }
    if (0.0f < o->period) {
        f32 a = o->phase * 6.2831855f / o->period;
        o->phase += D_00349e10;
        while (o->period < o->phase) o->phase -= o->period;
        o->bob = sinf(a) * o->f2908;
    }
}
}  // namespace n002d31b0

// 002d34d8 (was never written: gap function)
namespace n002d34d8 {
extern f32 D_00349e10 asm("D_00349e10");
void func_00198690(u8*) asm("func_00198690");
u32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_002d34d8(u8* o) asm("func_002d34d8");
void func_002d34d8(u8* o)
{
    func_00198690(o);
    if (func_001c0cd8(o)) *(f32*)(o + 2940) = -1.0f;
    f32 t = *(f32*)(o + 2940);
    if (0.0f < t) {
        f32 n = t - D_00349e10;
        *(f32*)(o + 2940) = n;
        if (n <= 0.0f) (*(void (**)(u8*))(*(u8**)o + 32))(o);
    }
}
void func_002d3550(u8* a, u8* b) asm("func_002d3550");
void func_002d3550(u8* a, u8* b) { *(f32*)(b + 56) += *(f32*)(a + 2852); }
}  // namespace n002d34d8

// 002d3568 (was src/anon/batch_w280.cpp)
namespace n002d3568 {
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
QWord func_002d38e8(u32) asm("func_002d38e8");
u8* func_001cbe30(QWord*, u32, s32) asm("func_001cbe30");
/*TARGET 002d3568*/
void Ti__MGOarashiGimObj__appear_rot_prize(u32 a, P1* p, u32 c) asm("Ti__MGOarashiGimObj__appear_rot_prize");
void Ti__MGOarashiGimObj__appear_rot_prize(u32 a, P1* p, u32 c)
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
}  // namespace n002d3568

// 002d36f0 (was src/anon/batch_w1986_nsa.cpp)
namespace n002d36f0 {
// 00108730: moved to src/anon/unit_001085a8.cpp

// 002d36f0
struct W1986V4 {
    f32 x, y, z, w;
    W1986V4() {}
    W1986V4(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    W1986V4& operator=(const W1986V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1986Obj {
    u8 pad0[0x40];
    s32 x40;
    u8 pad44[0x1c];
    f32 f60;
    f32 f64;
    f32 f68;
    u8 pad6c[0x14];
    W1986V4 v80;
    W1986V4 v90;
};
struct W1986Cfg {
    u8 pad0[0x44];
    s32 n;
    f32 f48;
    f32 f4c;
    f32 f50;
    f32 f54;
    f32 f58;
};
struct W1986Tmp { u8 d[16]; };
extern void* D_00361f60 asm("D_00361f60");
void func_002d38e8(W1986Tmp*, void*) asm("func_002d38e8");
W1986Cfg* func_002d1878(void*) asm("func_002d1878");
W1986Obj* func_001cbe30(W1986Tmp*, s32, s32) asm("func_001cbe30");
f32 sinf(f32) asm("sinf");
f32 cosf(f32) asm("cosf");
/*TARGET 002d36f0*/
void Ti__MGOarashiGimObj__appear_fall_prize(void* a) asm("Ti__MGOarashiGimObj__appear_fall_prize");
void Ti__MGOarashiGimObj__appear_fall_prize(void* a)
{
    W1986Tmp t;
    void* g = D_00361f60;
    func_002d38e8(&t, a);
    W1986Cfg* c = func_002d1878(g);
    f32 h = c->f58 / 60.0f;
    f32 w = c->f4c;
    s32& n = c->n;
    f32& wd = c->f48;
    f32& st = c->f50;
    for (s32 j = 0; j < 1; j++) {
        f32 z = (f32)j * st;
        for (s32 i = 0; i < n; i++) {
            W1986Obj* o = func_001cbe30(&t, 1, 1);
            if (o) {
                f32 ang = (wd * (f32)i) / (f32)(n - 1) - wd * 0.5f;
                f32 cs = sinf(ang);
                o->v90 = W1986V4(cs, -cosf(ang), 0, w);
                o->v80 = W1986V4(0, h, 0, 0);
                o->f60 = z;
                o->f64 = 120.0f;
                o->f68 = c->f54;
                o->x40 = 0;
            }
        }
    }
}
}  // namespace n002d36f0

// 002d38e8 (was src/anon/batch_w79.cpp)
namespace n002d38e8 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct Q16 {
    u128 v;
    Q16() {}
    Q16(const Q16& o) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    Q16& operator=(const Q16& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
Q16* YS__OBJ__get_pos(void*) asm("YS__OBJ__get_pos");
// fabsf
void func_00144450(f32*) asm("func_00144450");
void YS__OBJCLSN__calc_bounding_box(void*, f32*) asm("YS__OBJCLSN__calc_bounding_box");
static inline void vu0_scaled(Q16& r, const Q16& v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\t"
                 "vmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
}
/*TARGET 002d38e8*/
Q16* func_002d38e8(Q16* out, u8* o) asm("func_002d38e8");
Q16* func_002d38e8(Q16* out, u8* o) {
    if (*(void**)(o + 1296) != 0) {
        f32 m[6];
        func_00144450(m);
        YS__OBJCLSN__calc_bounding_box(*(void**)(o + 1296), m);
        Q16 s;
        Q16 r;
        ((f32*)&s)[3] = 0.0f;
        ((f32*)&s)[0] = m[0] + m[3];
        ((f32*)&s)[1] = m[1] + m[4];
        ((f32*)&s)[2] = m[2] + m[5];
        vu0_scaled(r, s, 0.5f);
        *out = r;
        ((s32*)out)[2] = 0;
    } else {
        *out = *YS__OBJ__get_pos(o);
        ((s32*)out)[2] = 0;
    }
    return out;
}
}  // namespace n002d38e8

// 002d39c8 (was src/anon/batch_w3700.cpp)
namespace n002d39c8 {
struct QW2d3 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Sub2d3 { u8 pad[24]; s16 h; };
struct Act2d3 {
    u8 p0[1416]; u32 flags;            /* 0x588 */
    u8 p1[2040 - 1420]; u32 f7f8;      /* 0x7f8 */
    u8 p2[2092 - 2044]; u8 snd[2780 - 2092]; f32 fadc; /* 0x82c, 0xadc */
    u8 p3[2808 - 2784]; Sub2d3* sub;   /* 0xaf8 */
    u8 p4[2936 - 2812]; f32 fb78; u8 p5[4]; u8 bb80; /* 0xb78, 0xb80 */
};
struct Hit2d3 { u8 pad[16]; Act2d3* other; };
static inline u8 IsPos2d3(f32 v) { return v > 0.0f; }
void func_001ad990(void*, f32, f32, f32) asm("_Z13func_001ad990Pvfff");
void YS__OBJ__get_target_pos(QW2d3*, Act2d3*) asm("_Z23YS__OBJ__get_target_posjjjj");
void YS__BTLOBJ__set_hitback(Act2d3*, QW2d3*, f32) asm("_Z23YS__BTLOBJ__set_hitbackjjjj");
void func_0016ac38(Act2d3*, s32, s32, s32, s32) asm("func_0016ac38");
f32 fabsf(f32) asm("fabsf");
/*TARGET 002d39c8*/
void Ti__MGOarashiGimObj__exec_damage_self(Act2d3* a, Hit2d3* h) asm("Ti__MGOarashiGimObj__exec_damage_self");
void Ti__MGOarashiGimObj__exec_damage_self(Act2d3* a, Hit2d3* h) {
    QW2d3 d, pa, pb;
    Act2d3* b = h->other;
    if (!(b->flags & 0x8000000)) return;
    if (IsPos2d3(a->fadc)) return;
    if (IsPos2d3(b->fadc)) return;
    s16 ha = a->sub->h;
    if (ha == 0) return;
    s16 hb = b->sub->h;
    if (hb == 0) return;
    if (hb < ha) return;
    if (!(a->f7f8 & 0x10)) func_001ad990(a->snd, 1.0f, 0.0f, 0.0f);
    // s0 for &pa: local-alloc priority gives it to &pb otherwise (partial asm, see asm_review.tsv)
    register QW2d3* ppa asm("$16");
        ppa = &pa;
    func_0016ac38(a, 0, 1, 0, 0);
    a->bb80 = 1;
    YS__OBJ__get_target_pos(ppa, a);
    YS__OBJ__get_target_pos(&pb, h->other);
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(ppa), "r"(&pb) : "memory");
    d.z = 0.0f;
    {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                     : "=f"(r) : "r"(&d) : "$8", "memory");
    }
    if (a->fb78 < 0.0f) asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(&d) : "memory");
    YS__BTLOBJ__set_hitback(a, &d, fabsf(a->fb78));
}
}  // namespace n002d39c8

// 002d3b78 (was src/anon/batch_wcx2_nsa.cpp)
namespace n002d3b78 {
// --------------------
// 002d3b78: Ti::MGOarashi object hit by the player (count hits, prize, knock-back)
struct V2d3b78 {
    f32 x, y, z, w;
    V2d3b78() {}
    void Set(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    void Zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    void Set3(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; w = 0.0f; }
    V2d3b78(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V2d3b78(const V2d3b78& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V2d3b78 operator+(const V2d3b78& b) const
    {
        V2d3b78 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2d3b78& operator+=(const V2d3b78& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    V2d3b78& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    V2d3b78& operator=(const V2d3b78& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2d3b78 operator-(const V2d3b78& b) const
    {
        V2d3b78 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct Cfg2d3b78 { u8 pad[40]; u8 tab40[24]; s32 f64; u8 pad2[216 - 68]; u8 tab216[4]; };
struct O2d3b78 {
    u8 pad0[8];
    s32* kind;
    u8 pad1[320 - 12];
    u8 motion[1416 - 320];
    u32 flags;
    u8 pad2[2040 - 1420];
    u32 f2040;
    u8 pad3[2092 - 2044];
    u8 f2092[2924 - 2092];
    s32 f2924;
    s32 hits;
    s32* tbl;
    f32 f2936;
    u8 pad4[4];
    u8 f2944;
};
struct Hit2d3b78 { u8 pad[16]; O2d3b78* other; u8 pad2[8]; s32 f28; };
extern void* D_00361f60 asm("D_00361f60");
extern V2d3b78 D_0034eef0 asm("D_0034eef0");
void Ti__MGOarashiGimObj__exec_damage_self(O2d3b78*, Hit2d3b78*) asm("Ti__MGOarashiGimObj__exec_damage_self");
void* o2d3b78_current(void) asm("_ZN2Ti8MGPlayer7currentEv");
s32 func_002d5c40(void*) asm("func_002d5c40");
void YS__PIERROT__damage_se(O2d3b78*, Hit2d3b78*) asm("YS__PIERROT__damage_se");
void* o2d3b78_start_effect(O2d3b78*, s32, s32, s32) asm("_ZN2YS3OBJ12start_effectEiii");
V2d3b78* o2d3b78_effect_pos(void*) asm("_ZN3ryj6EFFECT3posEv");
s32 o2d3b78_appear_prize_ok(void*) asm("_ZN2Ti15MGOarashiPlayer15appear_prize_okEv");
Cfg2d3b78* o2d3b78_config(void*) asm("_ZN2Ti9MGOarashi6configEv");
void Ti__MGOarashiGimObj__reserve_fall_prize(O2d3b78*, s32) asm("Ti__MGOarashiGimObj__reserve_fall_prize");
void Ti__MGOarashiGimObj__appear_rot_prize(O2d3b78*, void*, s32) asm("Ti__MGOarashiGimObj__appear_rot_prize");
void func_001ad990(void*, f32, f32, f32) asm("func_001ad990");
s32 func_0016ac38(O2d3b78*, s32, s32, s32, s32) asm("func_0016ac38");
void o2d3b78_00186a90(O2d3b78*, V2d3b78*, f32) asm("_Z23YS__BTLOBJ__set_hitbackjjjj");
V2d3b78 o2d3b78_0016bda8(O2d3b78*) asm("_Z23YS__OBJ__get_target_posjjjj");
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
void o2d3b78_push(void*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
f32 fabsf(f32) asm("fabsf");
/*TARGET 002d3b78*/
void func_002d3b78(O2d3b78* o, Hit2d3b78* h) asm("func_002d3b78");
void func_002d3b78(O2d3b78* o, Hit2d3b78* h)
{
    void* g = D_00361f60;
    if (o->f2924 >= 0) return;
    if (o->f2944) return;
    O2d3b78* t = h->other;
    if (t && !(t->flags & 0x80)) {
        if ((t->flags & 0x08000000) && t->f2924 < 0) {
            Ti__MGOarashiGimObj__exec_damage_self(o, h);
            return;
        }
    }
    s32 done = 0;
    s32 kind = func_002d5c40(o2d3b78_current());
    YS__PIERROT__damage_se(o, h);
    o->hits++;
    s32 eff = -1;
    s32 need;
    if (kind == 2) {
        eff = 1;
        need = o->tbl[1];
    } else if (kind == 3) {
        eff = 2;
        need = o->tbl[2];
    } else {
        need = o->tbl[0];
    }
    if (eff >= 0 && h->f28) {
        void* e = o2d3b78_start_effect(h->other, eff, 1, 0);
        if (e) *o2d3b78_effect_pos(e) = D_0034eef0;
    }
    if (o2d3b78_appear_prize_ok(o2d3b78_current())) {
        if (*o->kind == 1629 || (need > 0 && !(o->hits < need))) done = 1;
    }
    if (done) {
        if (*o->kind == 1629) Ti__MGOarashiGimObj__reserve_fall_prize(o, o2d3b78_config(g)->f64);
        else if (*o->kind == 1627) Ti__MGOarashiGimObj__appear_rot_prize(o, o2d3b78_config(g)->tab216, 0);
        else Ti__MGOarashiGimObj__appear_rot_prize(o, o2d3b78_config(g)->tab40, 2);
    }
    if (need > 0 && !(o->hits < need)) {
        if (!(o->f2040 & 0x10)) func_001ad990(o->f2092, 1.0f, 0.0f, 0.0f);
        func_0016ac38(o, 0, 1, 0, 0);
        o->f2944 = 1;
    } else if (*o->kind != 1626) {
        func_0017f488(o->motion, 14, 0.0f, 0.0f);
        o2d3b78_push(o->motion, 0, 0.0f, 0.0f, 0);
    }
    if (!h->other) return;
    if (*o->kind == 1627 || *o->kind == 1629) {
        V2d3b78 v;
        v.Set(1.0f, 0.0f, 0.0f, 0.0f);
        o2d3b78_00186a90(o, &v, fabsf(o->f2936));
    } else {
        V2d3b78 v = o2d3b78_0016bda8(o) - o2d3b78_0016bda8(h->other);
        v.z = 0.0f;
        v.normalize();
        if (o->f2936 < 0.0f) v.Zero();
        o2d3b78_00186a90(o, &v, fabsf(o->f2936));
    }
}
}  // namespace n002d3b78

// 002d3f18 (was src/anon/batch_w62.cpp)
namespace n002d3f18 {
// 0x002bda38: definition moved into src/anon/unit_002bc978.cpp

s32 func_002cf270(u8*, u32) asm("func_002cf270");
void func_002cf2b0(u8*, u32) asm("func_002cf2b0");
void func_0016ac38(u8*, u32, u32, u32, u32) asm("func_0016ac38");
void func_002cf280(u8*, u32, u32) asm("func_002cf280");
/*TARGET 002d3f18*/
void Ti__MGOarashiGimObj__force_destroy(u8* p) asm("Ti__MGOarashiGimObj__force_destroy");
void Ti__MGOarashiGimObj__force_destroy(u8* p) {
    u8* s = p + 2800;
    if (*(s32*)(p + 2924) >= 0) return;
    if (!func_002cf270(s, 256)) return;
    func_002cf2b0(s, 256);
    func_0016ac38(p, 0, 1, 0, 0);
    func_002cf280(s, 4, 0);
}
}  // namespace n002d3f18

// 002d3fa8 (was src/anon/batch_w2037.cpp)
namespace n002d3fa8 {
struct QVW2037a {
    f32 x, y, z, w;
    QVW2037a() {}
    QVW2037a(f32 v) { x = v; y = v; z = v; w = v; }
    QVW2037a(const QVW2037a& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct ObjW2037a {
    u8 pad0[0x588]; u32 flags;
    u8 pad1[0xaf0 - 0x58c]; u8 sub[0x24];
    f32 lim; f32 scale; f32 base; f32 mul;
};
static inline void vsubW2037a(QVW2037a* o, const QVW2037a* a, const QVW2037a* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(o), "r"(a), "r"(b) : "memory");
}
static inline void vaddW2037a(QVW2037a* o, const QVW2037a* a, const QVW2037a* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(o), "r"(a), "r"(b) : "memory");
}
static inline void vscaleW2037a(QVW2037a* o, const QVW2037a* a, const f32& s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(o), "r"(a), "f"(s) : "$8", "memory");
}
static inline f32 normalizeW2037a(QVW2037a* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline QVW2037a mulSW2037a(const QVW2037a* d, const f32& s, f32 t) {
    f32 c;
    if (t < (c = -1.0f) || (c = 1.0f) < t) t = c;
    QVW2037a s1, s2;
    vscaleW2037a(&s1, d, s);
    vscaleW2037a(&s2, &s1, t);
    return s2;
}
extern f32 D_00349e10 asm("D_00349e10");
s32 func_001c0cd8(void*) asm("func_001c0cd8");
s32 func_002cf270(void*, s32) asm("func_002cf270");
void YS__OBJ__get_target_pos(QVW2037a*, void*) asm("YS__OBJ__get_target_pos");
/*TARGET 002d3fa8*/
QVW2037a func_002d3fa8(ObjW2037a* a, ObjW2037a* b) asm("func_002d3fa8");
QVW2037a func_002d3fa8(ObjW2037a* a, ObjW2037a* b) {
    QVW2037a r(0.0f);
    if (b == a || (b->flags & 0x80) || func_001c0cd8(b) || ((b->flags & 0x08000000) && func_002cf270(b->sub, 0x400)))
        return QVW2037a(0.0f);
    QVW2037a pa, pb, d;
    YS__OBJ__get_target_pos(&pa, a);
    YS__OBJ__get_target_pos(&pb, b);
    vsubW2037a(&d, &pa, &pb);
    *(s32*)&d.z = 0;
    d.w = normalizeW2037a(&d);
    f32 lim = a->lim;
    if (lim != 0.0f && lim <= d.w) return QVW2037a(0.0f);
    QVW2037a s2 = mulSW2037a(&d, a->scale, (d.w - a->base) * a->mul);
    vaddW2037a(&r, &r, &s2);
    vscaleW2037a(&r, &r, D_00349e10);
    return r;
}
}  // namespace n002d3fa8

// 002d41c0 (was never written: gap function)
namespace n002d41c0 {
extern u8 D_003621a0[] asm("D_003621a0");
void func_002d2948(u8*, u32, u32, void*, f32) asm("_ZN2Ti15MGOarashiGimObjC1EPKN2YS8OBJENTRYEjRKN2kn7FVectorEf");
void func_002e7308(u8*) asm("func_002e7308");
void func_002d41c0(u8* o, u32 e, void* pos, f32 r) asm("func_002d41c0");
void func_002d41c0(u8* o, u32 e, void* pos, f32 r)
{
    func_002d2948(o, e, 1, pos, r);
    *(u8**)o = D_003621a0;
    func_002e7308(o + 3208);
}
}  // namespace n002d41c0

// 002d4200 (was src/anon/batch_w14.cpp)
namespace n002d4200 {
void func_002d2948(void*, void*, s32, void*) asm("func_002d2948");
void func_002e7308(void*) asm("func_002e7308");
extern u8 D_003621a0[] asm("D_003621a0");
/*TARGET 002d4200*/
// 0x002bf618: definition moved into src/anon/unit_002bebd0.cpp

void Ti__MGOarashiPiglet__MGOarashiPiglet(u8* p, void* a, void* b) asm("Ti__MGOarashiPiglet__MGOarashiPiglet");
// 0x002bf618: definition moved into src/anon/unit_002bebd0.cpp

void Ti__MGOarashiPiglet__MGOarashiPiglet(u8* p, void* a, void* b) {
    func_002d2948(p, a, 1, b);
    *(u8**)p = D_003621a0;
    func_002e7308(p + 3208);
}
}  // namespace n002d4200

// 002d4240 (was never written: gap function)
namespace n002d4240 {
void func_002d2b50(u8*) asm("func_002d2b50");
u8* cur(void) asm("_ZN2Ti8MGPlayer7currentEv");
void func_002d5950(u8*, u8*) asm("func_002d5950");
void func_002d4240(u8* o) asm("func_002d4240");
void func_002d4240(u8* o)
{
    func_002d2b50(o);
    u8* p = cur();
    if (p) func_002d5950(p, o);
    o[3204] = 0;
    *(u32*)(o + 944) = 1;
}
}  // namespace n002d4240

// 002d4290 (was src/anon/tiny_auto80_queue.cpp)
namespace n002d4290 {
void func_002d0070(...) asm("func_002d0070");
u32 func_002d1260(...) asm("func_002d1260");
// is_field340_eq151
extern "C" void func_002d5950(...) asm("func_002d5950");
/*TARGET 002d4290*/
void func_002d4290(u32 a0) asm("_Z13func_002d4290j");
void func_002d4290(u32 a0) {
    u32 s0 = a0;
    u32 p = func_002d1260(a0);
    if (p != 0) {
        func_002d5950(p, 0);
    }
    func_002d0070(s0);
}
}  // namespace n002d4290


// 002d42d0 (gap function, never written before)
namespace n002d42d0 {
#define QC(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { QC(this, &o); }
    void sety(f32 v) { y = v; }
    void setz(f32 v) { z = v; }
    V& operator=(const V& o) { if (this != &o) QC(this, &o); return *this; }
    V operator-(const V& o) const {
        V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    V operator+(const V& o) const {
        V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    V& operator+=(const V& o) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
    V& operator*=(f32 k) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8* D_00361f60 asm("D_00361f60");
extern f32 D_00349e10 asm("D_00349e10");
extern u8 D_00362188[] asm("D_00362188");
void func_0016a9a0(u8*) asm("func_0016a9a0");
V* YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
V func_002d1d30(u8*, const V&) asm("func_002d1d30");
void func_002e7568(u8*, s32, u8*) asm("func_002e7568");
u8* config(u8*) asm("_ZN2Ti9MGOarashi6configEv");
void func_002e7340(u8*, u8*, s32, u8*, f32, f32) asm("func_002e7340");
V* func_002d1f20(u8*) asm("func_002d1f20");
void func_002d4548(u8*) asm("func_002d4548");
f32 func_002d48b8(f32) asm("func_002d48b8");
f32 cos_(f32) asm("cosf");
f32 sin_(f32) asm("sinf");
void func_002d42d0(u8* o) asm("func_002d42d0");
void func_002d42d0(u8* o)
{
    func_0016a9a0(o);
    u8* g = D_00361f60;
    if (!*(u32*)(o + 2808)) return;
    V pos = *YS__OBJ__get_pos(o);
    V r = func_002d1d30(g, pos);
    f32 t;
    if (!o[3204]) {
        t = 1.0f;
        if (!(t < r.x) && !(r.x < -1.0f) && !(t < r.y) && !(r.y < -1.0f)) {
            o[3204] = 1;
            func_002e7568(o, 4, D_00362188);
            u8* c1 = config(g);
            u8* c2 = config(g);
            func_002e7340(o + 3208, o, 4, D_00362188, *(f32*)(c1 + 256), *(f32*)(c2 + 260));
        }
    }
    V w = *func_002d1f20(D_00361f60);
    w.setz(0.0f);
    w.sety(0.0f);
    if (o[3204]) func_002d4548(o);
    V* p = (V*)(o + 1344);
    V* q = (V*)(o + 2880);
    V d = *p - *q;
    V v = *(V*)(o + 2864);
    v *= v.w * D_00349e10;
    v.x += w.x;
    d += v;
    t = *(f32*)(o + 2896);
    t += *(f32*)(o + 2904) * D_00349e10;
    *(f32*)(o + 2896) = func_002d48b8(t);
    f32 c = cos_(*(f32*)(o + 2896));
    V u(c, sin_(*(f32*)(o + 2896)), 0.0f, 0.0f);
    u *= *(f32*)(o + 2900);
    *p = d + u;
    *q = *p - d;
    *(f32*)(o + 1352) = 0.0f;
}
}
