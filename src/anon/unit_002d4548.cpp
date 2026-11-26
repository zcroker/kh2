// Linked unit: Ti::MGOarashi minigame objects (tornado, gimmicks, player). Built from the old per-function sources;
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


// 002d4548 (was src/anon/batch_w323.cpp)
namespace n002d4548 {
#define QCOPY323(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV323 {
    f32 x, y, z, w;
    QV323() {}
    QV323(const QV323& o) { QCOPY323(this, &o); }
    QV323& operator=(const QV323& o) { if (this != &o) QCOPY323(this, &o); return *this; }
    QV323 operator-(const QV323& o) const {
        QV323 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    QV323 operator*(f32 k) const {
        QV323 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    f32 dot(const QV323& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o) : "$8", "memory");
        return r;
    }
    f32 lensq() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    f32 length() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    void normalize0() {
        asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "$8", "$f0", "memory");
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
extern u8* D_00361f60 asm("D_00361f60");
QV323& YS__OBJ__get_pos(void) asm("YS__OBJ__get_pos");
// obj_get_attach_or_alt
QV323 func_002d1d30(u8*, const QV323&) asm("func_002d1d30");
f32 rnd2d4548(f32, f32) asm("_Z13func_001065a8jjjjjjjj");
f32 fabsf(f32) asm("fabsf");
/*TARGET 002d4548*/
// fabsf
void func_002d4548(u8* self) asm("func_002d4548");
// fabsf
void func_002d4548(u8* self) {
    u8* cam = D_00361f60;
    f32 save = *(f32*)(self + 2876);
    QV323 v = YS__OBJ__get_pos();  // obj_get_attach_or_alt
    QV323 r = func_002d1d30(cam, v);
    if ((0.8f < r.x && 0.0f < *(f32*)(self + 2864)) || (r.x < -0.8f && *(f32*)(self + 2864) < 0.0f) ||
        (0.8f < r.y && 0.0f < *(f32*)(self + 2868)) || (r.y < -0.8f && *(f32*)(self + 2868) < 0.0f)) {
        f32 a, b;
        do {
            a = rnd2d4548(-1.0f, 1.0f);
            b = rnd2d4548(-1.0f, 1.0f);
        } while (fabsf(a) < 0.001f && fabsf(b) < 0.001f);  // fabsf
        if (0.7f < r.x) a = -fabsf(a);  // fabsf
        if (r.x < -0.7f) a = fabsf(a);  // fabsf
        if (0.7f < r.y) b = -fabsf(b);  // fabsf
        if (r.y < -0.7f) b = fabsf(b);  // fabsf
        *(f32*)(self + 2864) = a;
        *(f32*)(self + 2868) = b;
        *(f32*)(self + 2872) = 0.0f;
    }
    ((QV323*)(self + 2864))->normalize0();
    *(f32*)(self + 2876) = save;
}
}  // namespace n002d4548

// 002d47a0 (was never written: gap function)
namespace n002d47a0 {
void func_002d47a0(void) asm("func_002d47a0");
void func_002d47a0(void) {}
}  // namespace n002d47a0

// 002d47a8 (was src/anon/batch_w15.cpp)
namespace n002d47a8 {
// 0x002c1c50: definition moved into src/anon/unit_002c10e0.cpp

extern u8 D_003621a0 asm("D_003621a0");
void func_002e7328(void*) asm("func_002e7328");
// to_2e7458
u8 func_002d2a08(void*) asm("func_002d2a08");
/*TARGET 002d47a8*/
u8 func_002d47a8(void** self) asm("func_002d47a8");
u8 func_002d47a8(void** self) {
    *self = &D_003621a0;
    func_002e7328((u8*)self + 3208);  // to_2e7458
    return func_002d2a08(self);
}
}  // namespace n002d47a8

// 002d47e8 (was src/anon/batch_w16.cpp)
namespace n002d47e8 {
u8 func_002e7328(void*) asm("func_002e7328");
// to_2e7458
u8 func_002d2a08(void*) asm("func_002d2a08");
extern u8 D_003621a0 asm("D_003621a0");
/*TARGET 002d47e8*/
// 0x002c22b8: definition moved into src/anon/unit_002c2228.cpp

u8 func_002d47e8(u8* p) asm("func_002d47e8");
// 0x002c22b8: definition moved into src/anon/unit_002c2228.cpp

u8 func_002d47e8(u8* p) {
    *(void**)p = &D_003621a0;
    func_002e7328(p + 3208);  // to_2e7458
    return func_002d2a08(p);
}
}  // namespace n002d47e8

// 002d4828 (was src/anon/batch_w31.cpp)
namespace n002d4828 {
void func_00105110(void*) asm("func_00105110");
extern void* D_003621a0[] asm("D_003621a0");
void func_002e7328(void*) asm("func_002e7328");
// to_2e7458
void func_002d2a08(void*) asm("func_002d2a08");
/*TARGET 002d4828*/
// 0x002bbe80: definition moved into src/anon/unit_002bb8b0.cpp

void func_002d4828(void** p) asm("func_002d4828");
// 0x002bbe80: definition moved into src/anon/unit_002bb8b0.cpp

void func_002d4828(void** p) {
    *p = D_003621a0;
    func_002e7328((u8*)p + 3208);  // to_2e7458
    func_002d2a08(p);
    func_00105110(p);
}
}  // namespace n002d4828

// 002d4868 (was src/anon/batch_w52.cpp)
namespace n002d4868 {
// 0x002d0e10: definition moved into src/anon/unit_002cf260.cpp

void func_002e7458(u8*) asm("func_002e7458");
void func_002e7568(u8*, u32, u8*, f32) asm("func_002e7568");
extern u8 D_00362190[] asm("D_00362190");
/*TARGET 002d4868*/
void func_002d4868(u8* p) asm("func_002d4868");
void func_002d4868(u8* p) {
    func_002e7458(p + 3208);
    func_002e7568(p, 2, D_00362190, 1.0f);
    *(u32*)(p + 2876) = 0;
}
}  // namespace n002d4868

// 002d48b8 (was src/anon/batch_w53.cpp)
namespace n002d48b8 {
/*TARGET 002d48b8*/
// 002cedd0: moved to src/taito/minigame_base.cpp (linked unit)

// Wrap an angle into [-pi, pi].
f32 func_002d48b8(f32 x) asm("func_002d48b8");
// 002cedd0: moved to src/taito/minigame_base.cpp (linked unit)

// Wrap an angle into [-pi, pi].
f32 func_002d48b8(f32 x) {
    if (0.0f < x) {
        while (3.1415927f < x) x -= 6.2831855f;
    } else {
        while (x < -3.1415927f) x += 6.2831855f;
    }
    return x;
}
}  // namespace n002d48b8

// 002d4950 (was never written: gap function, C2 copy of the ctor at 0x2d49c0)
namespace n002d4950 {
void func_002d0ea8(void*) asm("func_002d0ea8");
extern u8 D_003622c0[] asm("D_003622c0");
typedef struct V4_w3717 { f32 x, y, z, w; } V4_w3717;
typedef struct O2d4_w3717 {
    void* vt;
    u8 pad[0xbec];
    union { s32 i; f32 f; } bf0;
    u8 pad2[0xc];
    V4_w3717 c00;
    f32 c10;
    f32 c14, c18, c1c;
    u8 pad3[0x10];
    f32 c30, c34;
} O2d4_w3717;
// Constructor: base init, vtable, then clears the colour/scale fields.
// The empty asm ties the x store to the c10 store (the original stores x after c10
// although it is independent); v is pinned to $f1 as in the original.
void func_002d4950(O2d4_w3717* o) asm("func_002d4950");
// Constructor: base init, vtable, then clears the colour/scale fields.
// The empty asm ties the x store to the c10 store (the original stores x after c10
// although it is independent); v is pinned to $f1 as in the original.
void func_002d4950(O2d4_w3717* o) {
    func_002d0ea8(o);
    o->vt = D_003622c0;
    o->bf0.i = 0;
    V4_w3717* q = &o->c00;
    register f32 v asm("$f1") = o->bf0.f;
    q->y = v;
    q->z = v;
    q->w = v;
    o->c34 = 0.0f;
    o->c14 = 0.0f;
    o->c18 = 0.0f;
    o->c1c = 0.0f;
    o->c30 = 0.0f;
    o->c10 = 0.004f;
    asm("" : "+f"(v) : "m"(o->c10));
    q->x = v;
}
}  // namespace n002d4950


// 002d49c0 (was src/anon/batch_w3717.cpp)
namespace n002d49c0 {
void func_002d0ea8(void*) asm("func_002d0ea8");
extern u8 D_003622c0[] asm("D_003622c0");
typedef struct V4_w3717 { f32 x, y, z, w; } V4_w3717;
typedef struct O2d4_w3717 {
    void* vt;
    u8 pad[0xbec];
    union { s32 i; f32 f; } bf0;
    u8 pad2[0xc];
    V4_w3717 c00;
    f32 c10;
    f32 c14, c18, c1c;
    u8 pad3[0x10];
    f32 c30, c34;
} O2d4_w3717;
/*TARGET 002d49c0*/
// Constructor: base init, vtable, then clears the colour/scale fields.
// The empty asm ties the x store to the c10 store (the original stores x after c10
// although it is independent); v is pinned to $f1 as in the original.
void func_002d49c0(O2d4_w3717* o) asm("func_002d49c0");
// Constructor: base init, vtable, then clears the colour/scale fields.
// The empty asm ties the x store to the c10 store (the original stores x after c10
// although it is independent); v is pinned to $f1 as in the original.
void func_002d49c0(O2d4_w3717* o) {
    func_002d0ea8(o);
    o->vt = D_003622c0;
    o->bf0.i = 0;
    V4_w3717* q = &o->c00;
    register f32 v asm("$f1") = o->bf0.f;
    q->y = v;
    q->z = v;
    q->w = v;
    o->c34 = 0.0f;
    o->c14 = 0.0f;
    o->c18 = 0.0f;
    o->c1c = 0.0f;
    o->c30 = 0.0f;
    o->c10 = 0.004f;
    asm("" : "+f"(v) : "m"(o->c10));
    q->x = v;
}
}  // namespace n002d49c0

// 002d4a30 (was src/anon/batch_w39.cpp)
namespace n002d4a30 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
// 16-byte aligned vector; assignment copies a quadword unless self-assigned.
struct Vec4 {
    f32 x, y, z, w;
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
// 0x002cf8c0: definition moved into src/anon/unit_002cf260.cpp

// --- 002d4a30
void func_0016aef0(u8*, f32*) asm("func_0016aef0");
/*TARGET 002d4a30*/
void func_002d4a30(u8* p, Vec4* v) asm("func_002d4a30");
void func_002d4a30(u8* p, Vec4* v) {
    f32 t[4];
    t[0] = 1.0f;
    t[3] = t[2] = t[1] = 0.0f;
    func_0016aef0(p, t);
    *(Vec4*)(p + 1344) = *v;
    *(f32*)(p + 1352) = *(f32*)(p + 3056);
}
}  // namespace n002d4a30

// 002d4aa0 (was src/anon/batch_wcx.cpp)
namespace n002d4aa0 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
// 002c6610: moved to src/anon/unit_002c6420.cpp (linked unit)
extern u32 D_00361f60 asm("D_00361f60");
void func_001780d8(u8*) asm("func_001780d8");
void func_00198860(u8*, s32) asm("func_00198860");
u8* func_002d1f00(u32) asm("func_002d1f00");
// ptr_add160
void func_0016ace0(u8*, V4*) asm("func_0016ace0");
void func_0016aef0(u8*, V4*) asm("func_0016aef0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
/*TARGET 002d4aa0*/
void func_002d4aa0(u8* p) asm("func_002d4aa0");
void func_002d4aa0(u8* p)
{
    func_001780d8(p);
    func_00198860(p, 6);
    V4 a, b;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&a), "r"(func_002d1f00(D_00361f60) + 48) : "$8", "memory");  // ptr_add160
    *(u32*)&a.z = 0;
    func_0016ace0(p, &a);
    asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 3104) : "memory");
    f32 z = 0.0f;
    b.x = 1.0f;
    b.y = z;
    b.z = z;
    b.w = z;
    func_0016aef0(p, &b);
    func_0016bd60(p, 37);
}
}  // namespace n002d4aa0

// 002d4b40 (was src/anon/batch_wcx2_nsa.cpp)
namespace n002d4b40 {
struct Tgt2d4b40;
#define W2d4b40_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W2d4b40Vec {
    f32 x, y, z, w;
    W2d4b40Vec() {}
    W2d4b40Vec(const W2d4b40Vec& o) { W2d4b40_QCOPY(this, &o); }
    W2d4b40Vec& operator=(const W2d4b40Vec& o) { if (this != &o) W2d4b40_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W2d4b40Mtx {
    W2d4b40Vec r0, r1, r2, r3;
    W2d4b40Mtx() {}
    W2d4b40Mtx(const W2d4b40Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W2d4b40Mtx& operator=(const W2d4b40Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * column vector.
    W2d4b40Vec operator*(const W2d4b40Vec& v) const {
        W2d4b40Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct O2d4b40 { u8 pad0[2884]; s32 f2884; u8 pad1[3092 - 2888]; void* h3092; void* h3096; void* f3100; u8 pad2[3128 - 3104]; void* f3128; s32 f3132; };
extern void* D_00361f60 asm("D_00361f60");
void func_002d10a0(O2d4b40*) asm("func_002d10a0");
W2d4b40Vec* YS__OBJ__get_pos(O2d4b40*) asm("YS__OBJ__get_pos");
W2d4b40Mtx* func_002d1f10(void*) asm("func_002d1f10");
W2d4b40Mtx* func_002d1f00(void*) asm("func_002d1f00");
void o2d4b40_set_pos(O2d4b40*, W2d4b40Vec*) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
void* func_0016b740(s32) asm("func_0016b740");
s32 func_002d5588(O2d4b40*) asm("func_002d5588");
s32 func_002d56a0(O2d4b40*) asm("func_002d56a0");
s32 o2d4b40_is_attach(void*) asm("_ZN2YS3OBJ9is_attachEv");
void func_00190128(Tgt2d4b40*) asm("func_00190128");
void o2d4b40_set_obj(Tgt2d4b40*, void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
struct Tgt2d4b40 {
    u8 pad[64];
    Tgt2d4b40(void* obj) { func_00190128(this); o2d4b40_set_obj(this, obj, 0); }
};
void func_001bd3e0(s32, s32, s32, Tgt2d4b40*, s32, s32) asm("func_001bd3e0");
s32 Ti__MGOarashiPlayer__is_combine_ready(O2d4b40*) asm("Ti__MGOarashiPlayer__is_combine_ready");
void* Ti__MGOarashi__get_attach_ready_tornado(void*, s32) asm("Ti__MGOarashi__get_attach_ready_tornado");
/*TARGET 002d4b40*/
void func_002d4b40(O2d4b40* o) asm("func_002d4b40");
void func_002d4b40(O2d4b40* o)
{
    func_002d10a0(o);
    void* g = D_00361f60;
    if (!g) return;
    {
    W2d4b40Vec p(*YS__OBJ__get_pos(o));
    W2d4b40Mtx m(*func_002d1f10(g));
    m.invOrtho();
    p.w = 1.0f;
    W2d4b40Vec a = m * p;
    a.z = 0.0f;
    W2d4b40Vec b = *func_002d1f00(g) * a;
    b.z = 0.0f;
    o2d4b40_set_pos(o, &b);
    }
    if (!o->h3092) o->h3092 = func_0016b740(1565);
    if (!o->h3096) o->h3096 = func_0016b740(1628);
    if (func_002d5588(o)) return;
    if (func_002d56a0(o) && o->h3092 && o2d4b40_is_attach(o->h3092)) {
        Tgt2d4b40 t(o->f3100);
        func_001bd3e0(o->f2884, 1, 497, &t, 1, 100);
        return;
    }
    if (Ti__MGOarashiPlayer__is_combine_ready(o)) {
        Tgt2d4b40 t(o->h3092);
        func_001bd3e0(o->f2884, 1, 496, &t, 1, 100);
        return;
    }
    void* r = Ti__MGOarashi__get_attach_ready_tornado(g, 0);
    if (r) {
        Tgt2d4b40 t(r);
        func_001bd3e0(o->f2884, 1, 578, &t, 1, 100);
        o->f3128 = r;
        o->f3132 = 0;
        return;
    }
    r = Ti__MGOarashi__get_attach_ready_tornado(g, 1);
    if (r) {
        Tgt2d4b40 t(r);
        func_001bd3e0(o->f2884, 1, 579, &t, 1, 100);
        o->f3128 = r;
        o->f3132 = 1;
    }
}
}  // namespace n002d4b40

// 002d4e30 (was never written: gap function)
namespace n002d4e30 {
struct V {
    f32 x, y, z, w;
    V& operator=(const V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void YS__PLAYER___OVR_exec(u8*) asm("YS__PLAYER___OVR_exec");
u32 func_002d5578(u8*) asm("func_002d5578");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
u32 func_001dc9d0(u32) asm("func_001dc9d0");
V* func_001dc5f8(u32) asm("func_001dc5f8");
void func_001dc920(u32) asm("func_001dc920");
V YS__OBJ__get_target_pos(u8*) asm("YS__OBJ__get_target_pos");
void func_002d4e30(u8* o) asm("func_002d4e30");
void func_002d4e30(u8* o)
{
    YS__PLAYER___OVR_exec(o);
    if (func_002d5578(o)) {
        u8* m = o + 320;
        if ((*(u32*)(o + 352) & 0x10) && 0.0f < *(f32*)(o + 28)) func_0017f488(m, 0, 8.0f, 0.0f);
    }
    if (*(u32*)(o + 3124)) {
        if (func_001dc9d0(*(u32*)(o + 3124))) {
            *func_001dc5f8(*(u32*)(o + 3124)) = YS__OBJ__get_target_pos(*(u8**)(o + 3092));
        } else {
            func_001dc920(*(u32*)(o + 3124));
            *(u32*)(o + 3124) = 0;
        }
    }
    if (*(u32*)(o + 3120)) {
        if (func_001dc9d0(*(u32*)(o + 3120))) {
            *func_001dc5f8(*(u32*)(o + 3120)) = YS__OBJ__get_target_pos(o);
        } else {
            func_001dc920(*(u32*)(o + 3120));
            *(u32*)(o + 3120) = 0;
        }
    }
}
u32 func_002d1228(void) asm("func_002d1228");
u32 func_002d4f48(void) asm("func_002d4f48");
u32 func_002d4f48(void) { return func_002d1228(); }
}  // namespace n002d4e30

// 002d4f60 (was src/anon/batch_w97.cpp)
namespace n002d4f60 {
// ---- shared VU0 helpers
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq vsubn(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
// Normalises xyz in place; returns the original length.
static inline f32 vnormalize(Vq* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline void vcopy(Vq* d, const Vq* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
// 0x002c5b20: definition moved into src/anon/unit_002c53c8.cpp

// ---- 002d4f60
union W2d4 { u32 u; f32 f; };
struct Quad2d4 { W2d4 v[4]; };
struct Rec2d4 { u32 a; Quad2d4 b; };
struct Src2d4 { u32 f0; Rec2d4 r; };
struct Obj2d4 { u8 pad[1344]; Vq pos; u8 pad1360[2548 - 1360]; Rec2d4 r; u8 pad2568[3104 - 2568]; Vq dir; };
Vq func_00190388(const void*) asm("func_00190388");
/*TARGET 002d4f60*/
// vec4_from_arg
Vq func_002d4f60(Obj2d4* o) asm("func_002d4f60");
// vec4_from_arg
Vq func_002d4f60(Obj2d4* o) {
    Rec2d4* rr = &o->r;
    Rec2d4* sr = &(*(Src2d4**)((u8*)o + 2880))->r;
    o->r.a = sr->a;
    o->r.b = sr->b;
    Vq d;
    d.w = d.z = d.y = d.x = 0.0f;
    if (rr->b.v[2].u == 6) {
        d = vsubn(func_00190388(rr), o->pos);  // vec4_from_arg
        vnormalize(&d);
        o->dir = d;
    }
    Vq r;
    vcopy(&r, &o->dir);
    return r;
}
}  // namespace n002d4f60

// 002d5088 (was src/anon/batch_w274.cpp)
namespace n002d5088 {
struct V4 {
    f32 x, y, z, w;
    V4() {}
    V4(const V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4& operator=(const V4& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline f32 Normalize(V4* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline V4 operator+(const V4& a, const V4& b) {
    V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void Zero(V4* v) {
    asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(v) : "memory");
}
static inline f32 Length(const V4* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct C5088 { u8 pad[16]; V4 v; u8 pad2[2840]; u8* o2872; u8 pad3[228]; V4 v3104; };
// 00158708: moved to src/harata/libdk/scopecamera.cpp
extern u8* D_00361f60 asm("D_00361f60");
s32 YS__OBJ__can_control(void) asm("YS__OBJ__can_control");
// vtable_call_slot64_flags
s32 func_002d5588(C5088*) asm("func_002d5588");
u8* func_002d1878(u8*) asm("func_002d1878");
/*TARGET 002d5088*/
void func_002d5088(C5088* p) asm("func_002d5088");
void func_002d5088(C5088* p) {
    Zero(&p->v);
    if (!YS__OBJ__can_control()) return;
    u8* cfg = D_00361f60;
    V4 a = *(V4*)(p->o2872 + 48);
    a.z = 0.0f;
    a.w = Length(&a);
    V4 b;
    f32 z = a.z;
    b.x = a.x; b.y = a.y; b.z = z; b.w = z;
    if (Normalize(&b) < 0.1f) {
        b.w = z;
    } else {
        p->v3104 = b;
        *(f32*)((u8*)p + 3116) = 1.0f;
        if (func_002d5588(p)) b.w = *(f32*)(func_002d1878(cfg) + 204);
        else b.w = *(f32*)(func_002d1878(cfg) + 4);
    }
    p->v = b;
}
}  // namespace n002d5088

// 002d51f0 (was src/anon/tiny.cpp)
namespace n002d51f0 {
/*TARGET 002d51f0*/
// 0x002d1f30: definition moved into src/anon/unit_002cf260.cpp

u32 func_002d51f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d51f0jjjj");
// 0x002d1f30: definition moved into src/anon/unit_002cf260.cpp

u32 func_002d51f0(u32 a0, u32 a1, u32 a2, u32 a3) {  // obj_state_is_14
    (void)a1;
    (void)a2;
    (void)a3;
    return ((*(u32*)((u32)a0 + (340)) ^ 0x000eu) == 0);
}
}  // namespace n002d51f0

// 002d5200 (was src/anon/batch_wcx2_nsa.cpp)
namespace n002d5200 {
struct O2d5200;
// --------------------
// 002d5200: Ti::MGOarashi player bumped into an object (stop motions, prize/effect, knock-back)
struct V2d5200 {
    f32 x, y, z, w;
    V2d5200() {}
    void Set(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    void Zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    void Set3(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; w = 0.0f; }
    V2d5200(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V2d5200(const V2d5200& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V2d5200 operator+(const V2d5200& b) const
    {
        V2d5200 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2d5200& operator+=(const V2d5200& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    V2d5200& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    V2d5200& operator=(const V2d5200& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2d5200 operator-(const V2d5200& b) const
    {
        V2d5200 r;
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
struct Cfg2d5200 { u8 pad[136]; f32 knock; };
struct O2d5200Vt { void* f[24]; s32 (*busy)(O2d5200*); };
struct O2d5200 {
    O2d5200Vt* vt;
    u8 pad1[316];
    u8 motion[1416 - 320];
    u32 flags;
    u8 pad2[2780 - 1420];
    f32 height;
    u8 pad3[2800 - 2784];
    u8 lflag[3092 - 2800];
    O2d5200* h3092;
    O2d5200* h3096;
    bool InAir() { return 0.0f < height; }
};
struct G2d5200 { u8 pad[320]; u8 f320; };
struct Hit2d5200 { u8 pad[16]; O2d5200* other; u8 pad2[8]; s32 f28; };
extern G2d5200* g2d5200_game asm("D_00361f60");
extern V2d5200 g2d5200_zero asm("D_0034eef0");
V2d5200 o2d5200_0016bda8(O2d5200*) asm("_Z23YS__OBJ__get_target_posjjjj");
s32 func_002d51f0(O2d5200*) asm("func_002d51f0");
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
void o2d5200_push(void*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
s32 o2d5200_is_attach(void*) asm("_ZN2YS3OBJ9is_attachEv");
void func_002d6600(O2d5200*, V2d5200*) asm("func_002d6600");
void* o2d5200_start_effect(O2d5200*, s32, s32, s32) asm("_ZN2YS3OBJ12start_effectEiii");
V2d5200* o2d5200_effect_pos(void*) asm("_ZN3ryj6EFFECT3posEv");
void o2d5200_set(void*, u32, s32) asm("_Z16wtarget_002cf280jjjj");
void Ti__MGOarashiGimObj__force_destroy(O2d5200*) asm("Ti__MGOarashiGimObj__force_destroy");
Cfg2d5200* o2d5200_config(void*) asm("_ZN2Ti9MGOarashi6configEv");
void o2d5200_00186a90(O2d5200*, V2d5200*, f32) asm("_Z23YS__BTLOBJ__set_hitbackjjjj");
f32 fabsf(f32) asm("fabsf");
/*TARGET 002d5200*/
void func_002d5200(O2d5200* o, Hit2d5200* h) asm("func_002d5200");
void func_002d5200(O2d5200* o, Hit2d5200* h)
{
    G2d5200* g = g2d5200_game;
    if (!g) return;
    if (o->vt->busy(o)) return;
    V2d5200 d = o2d5200_0016bda8(o) - o2d5200_0016bda8(h->other);
    d.z = 0.0f;
    if (d.normalize() < 0.01f) {
        f32 zero = 0.0f;
        d.x = 1.0f; d.z = zero; d.y = zero;
    }
    if (!func_002d51f0(o)) {
        O2d5200* t = h->other;
        if (t && (t->flags & 0x08000000) && t->InAir()) return;
        func_0017f488(o->motion, 14, 0.0f, 0.0f);
        o2d5200_push(o->motion, 0, 0.0f, 0.0f, 0);
        if (o->h3096) {
            func_0017f488(o->h3096->motion, 14, 0.0f, 0.0f);
            o2d5200_push(o->h3096->motion, 0, 0.0f, 0.0f, 0);
        }
        if (o->h3092 && o2d5200_is_attach(o->h3092)) {
            g->f320 = 1;
            func_002d6600(o->h3092, &d);
        }
        if (h->f28) {
            void* e = o2d5200_start_effect(h->other, 1, 1, 0);
            if (e) *o2d5200_effect_pos(e) = g2d5200_zero;
        }
        if (h->other && (h->other->flags & 0x08000000)) {
            o2d5200_set(h->other->lflag, 256, 0);
            Ti__MGOarashiGimObj__force_destroy(h->other);
        }
    }
    if (o2d5200_config(g)->knock < 0.0f) d.Zero();
    o2d5200_00186a90(o, &d, fabsf(o2d5200_config(g)->knock));
}
}  // namespace n002d5200

// 002d54a8 (was src/anon/batch_w85.cpp)
namespace n002d54a8 {
// 0x002ad9f8: definition moved into src/anon/unit_002a99c8.cpp
s32 func_002d5578(u8*) asm("func_002d5578");
// is_field340_eq151
void func_00178d28(u8*) asm("func_00178d28");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, s32, s32, f32, f32) asm("func_0017f5e0");
#define TAIL     func_00178d28(o); \
        if (*(u8**)(o + 3096)) { f32 z = 0.0f; \
            func_0017f488(*(u8**)(o + 3096) + 320, 151, z, z); \
            func_0017f5e0(*(u8**)(o + 3096) + 320, 0, 0, z, z); }
/*TARGET 002d54a8*/
void func_002d54a8(u8* o) asm("func_002d54a8");
void func_002d54a8(u8* o) {
    if (!func_002d5578(o) || (*(u32*)(o + 352) & 0x10)) {  // is_field340_eq151
        if (*(f32*)(o + 3116) == 0.0f) {
            if (0.0f <= *(f32*)(o + 1360)) *(f32*)(o + 3104) = 1.0f;
            else *(f32*)(o + 3104) = -1.0f;
        }
        TAIL
    }
}
}  // namespace n002d54a8

// 002d5578 (was src/anon/tiny.cpp)
namespace n002d5578 {
/*TARGET 002d5578*/
u32 func_002d5578(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d5578jjjj");
u32 func_002d5578(u32 a0, u32 a1, u32 a2, u32 a3) {  // is_field340_eq151
    (void)a1;
    (void)a2;
    (void)a3;
    return ((*(u32*)((u32)a0 + (340)) ^ 0x0097u) == 0);
}
}  // namespace n002d5578

// 002d5588 (was src/anon/batch_w1731.cpp)
namespace n002d5588 {
// --- 002d5588: true when the linked object's id is 0x38 or 0x37
struct I_w1731 { u8 pad[4]; s32 id; };
struct P_w1731 { u8 pad[12]; I_w1731* i; };
/*TARGET 002d5588*/
s32 func_002d5588(P_w1731* p) asm("func_002d5588");
s32 func_002d5588(P_w1731* p) {
    s32 t = p->i->id;
    s32 r = 0;
    if ((t ^ 0x38) == 0 || (t ^ 0x37) == 0) r = 1;
    return r;
}
}  // namespace n002d5588

// 002d55b8 (was src/anon/batch_w1809_nsa.cpp)
namespace n002d55b8 {
struct W1809V2d5 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W1809R2d5 { u8 pad[16]; s16 h10; };
// 0016c808: moved to src/anon/unit_0016c770.cpp

// 0016c8f8: moved to src/anon/unit_0016c770.cpp

extern s32 D_00361f60 asm("D_00361f60");
s32 func_001c0cd8(void*) asm("func_001c0cd8");
W1809R2d5* func_0016bc20(void*, s32, s32) asm("func_0016bc20");
void YS__OBJ__get_target_pos(W1809V2d5*, void*) asm("YS__OBJ__get_target_pos");
/*TARGET 002d55b8*/
// VU0 macro code: d = a - b, then the xyz length of d.
s32 Ti__MGOarashiPlayer__is_combine_ready(u8* a0) asm("Ti__MGOarashiPlayer__is_combine_ready");
// VU0 macro code: d = a - b, then the xyz length of d.
s32 Ti__MGOarashiPlayer__is_combine_ready(u8* a0) {
    s32 r = 0;
    if (D_00361f60 != 0) {
        void* t = *(void**)(a0 + 0xc14);
        if (t != 0) {
            if (func_001c0cd8(t) != 0) goto no;
            {
            W1809V2d5 d, a, b;
            W1809V2d5* pd = &d;
            f32 len;
            f32 range = func_0016bc20(*(void**)(a0 + 0xc14), 5, -1)->h10;
            YS__OBJ__get_target_pos(&a, a0);
            YS__OBJ__get_target_pos(&b, *(void**)(a0 + 0xc14));
            asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(pd), "r"(&a), "r"(&b) : "memory");
            pd->z = 0.0f;
            asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(len) : "r"(pd) : "$8", "memory");
            r = 1;
            if (len < range) goto out;
            }
        no:
            r = 0;
        }
    }
out:
    return r;
}
}  // namespace n002d55b8

// 002d56a0 (was src/anon/batch_w66.cpp)
namespace n002d56a0 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq vsub(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 vlen(const Vq& a) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a) : "$8", "memory");
    return r;
}
// ---- 002d56a0
u8* func_0016bc20p(u32, s32, s32) asm("func_0016bc20");
Vq* func_0016c028v(u32) asm("YS__OBJ__get_pos");
/*TARGET 002d56a0*/
s32 func_002d56a0(u8* p) asm("func_002d56a0");
s32 func_002d56a0(u8* p) {
    Vq* pos = (Vq*)(p + 1344);
    if (!*(u32*)(p + 3100)) return 0;
    u8* v = func_0016bc20p(*(u32*)(p + 3100), 5, -1);
    f32 rad = *(s16*)(v + 16);
    Vq* q = func_0016c028v(*(u32*)(p + 3100));
    f32 l = vlen(vsub(*pos, *q));
    return l < rad ? 1 : 0;
}
}  // namespace n002d56a0

// 002d5748 (was src/anon/batch_w1881.cpp)
namespace n002d5748 {
struct V5748 {
    f32 x, y, z, w;
    V5748() {}
    V5748& operator=(const V5748& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Mg5748 { u8 pad[0x140]; u8 f140; };
struct Act5748 {
    u8 pad[0xc14]; void* c14; u8 p2[4]; s32 c1c; u8 p3[0x10]; void* c30; void* c34;
};
s32 st_eff5748(Act5748*, s32, s32, s32) asm("_ZN2YS3OBJ12start_effectEiii");
V5748* epos5748(void*) asm("_ZN3ryj6EFFECT3posEv");
void ekill5748(void*) asm("_ZN3ryj6EFFECT4killEv");
V5748 getpos5748(void*) asm("_Z23YS__OBJ__get_target_posjjjj");
void tornado5748(Act5748*) asm("_ZN2Ti15MGOarashiPlayer20start_tornado_attackEv");
extern Mg5748* D_00361f60 asm("D_00361f60");
void func_002d6518(void*) asm("func_002d6518");
void func_001991a8(s32, s32) asm("func_001991a8");
void func_002d4868(s32) asm("func_002d4868");
/*TARGET 002d5748*/
void func_002d5748(Act5748* self, u16* msg) asm("func_002d5748");
void func_002d5748(Act5748* self, u16* msg)
{
    Mg5748* g = D_00361f60;
    if (g == 0) return;
    s32 c = *msg;
    if ((u16)c == 0x1f0) {
        func_002d6518(self->c14);
        g->f140 = 0;
        if (self->c34) ekill5748(self->c34);
        void* e = (void*)st_eff5748(self, 1, 0, 0);
        self->c34 = e;
        if (e) *epos5748(e) = getpos5748(self->c14);
        if (self->c30) ekill5748(self->c30);
        e = (void*)st_eff5748(self, 0, 0, 0);
        self->c30 = e;
        if (e) *epos5748(e) = getpos5748(self);
    } else if ((u16)c == 0x1f1) {
        func_001991a8(21, 0);
        func_002d4868(self->c1c);
    } else if ((u32)((c - 0x242) & 0xffff) < 2) {
        tornado5748(self);
    }
}
}  // namespace n002d5748

// 002d5890 (was never written: gap function)
namespace n002d5890 {
struct V {
    f32 x, y, z, w;
    V() {}
    V operator-(const V& b) const {
        V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 length() const {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
extern u8* D_00361f60 asm("D_00361f60");
u32 func_001c0cd8(u8*) asm("func_001c0cd8");
u8* config(u8*) asm("_ZN2Ti9MGOarashi6configEv");
bool func_002d5890(u8* o, const V& p) asm("func_002d5890");
bool func_002d5890(u8* o, const V& p)
{
    u8* g = D_00361f60;
    if (!g) return 0;
    f32 r;
    u8* e = *(u8**)(o + 3092);
    if (e && func_001c0cd8(e)) r = *(f32*)(config(g) + 28);
    else r = *(f32*)(config(g) + 32);
    return (*(V*)(o + 1344) - p).length() <= r;
}
}  // namespace n002d5890

// 002d5950 (was src/anon/misc_2.cpp)
namespace n002d5950 {
/*TARGET 002d5950*/
// 0x002d00d8: definition moved into src/anon/unit_002cf260.cpp

void func_002d5950(void* self, s32 v) asm("_Z13func_002d5950Pvi");
// 0x002d00d8: definition moved into src/anon/unit_002cf260.cpp

void func_002d5950(void* self, s32 v) { *(s32*)((char*)self + 3100) = v; }
}  // namespace n002d5950

// 002d5958 (was src/anon/batch_w112.cpp)
namespace n002d5958 {
struct QV { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Info64 { u8 pad[48]; QV pos; };
extern u32 D_00361f60 asm("D_00361f60");
void YS__OBJ__get_bone_matrix(u32, u32, Info64*) asm("YS__OBJ__get_bone_matrix");
u8* YS__OBJ__Each(u8*) asm("YS__OBJ__Each");
s32 func_0016a060(u8*) asm("func_0016a060");
s32 func_002cf270(u8*, u32) asm("func_002cf270");
s32 func_002ceef8(u32, u8*) asm("func_002ceef8");
QV* YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
static inline void qcopy(QV* d, const QV* s) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory"); }
static inline void vsub(QV* d, const QV* a, const QV* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 vlen(const QV* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(v) : "$8");
    return r;
}
/*TARGET 002d5958*/
// Returns the nearest active actor of kind 20 that passes the area checks.
u8* func_002d5958(u32 id) asm("func_002d5958");
// Returns the nearest active actor of kind 20 that passes the area checks.
u8* func_002d5958(u32 id) {
    u8* best = 0;
    f32 bestd = 0.0f;
    u32 area = D_00361f60;
    Info64 info;
    QV pos;
    u8* a = 0;
    YS__OBJ__get_bone_matrix(id, 67, &info);
    qcopy(&pos, &info.pos);
    while ((a = YS__OBJ__Each(a))) {
        if (!(*(u32*)(a + 1416) & 0x8000000)) continue;
        if (func_0016a060(a) != 20) continue;
        if (func_002cf270(a + 2800, 128)) continue;
        if (!func_002ceef8(area, a)) continue;
        if (best) {
            QV d;
            vsub(&d, YS__OBJ__get_pos(a), &pos);  // obj_get_attach_or_alt
            if (vlen(&d) < bestd) best = a;
        } else {
            QV d;
            best = a;
            vsub(&d, YS__OBJ__get_pos(a), &pos);  // obj_get_attach_or_alt
            bestd = vlen(&d);
        }
    }
    return best;
}
}  // namespace n002d5958

// 002d5af0 (was src/anon/auto80_199_queue.cpp)
namespace n002d5af0 {
/*TARGET 002d5af0*/
void func_002d5af0(u32 a0) asm("_Z13func_002d5af0j");
void func_002d5af0(u32 a0) {
    u32 s0 = a0;
    u32 p = *(u32*)(s0 + 3128);
    func_002cf2b0(p + 2800, 1);
    Ti__MGOarashiGimObj__start_tornado_attack(*(u32*)(s0 + 3128));
    func_00190128(s0 + 2548);
    u32 a1 = 56;
    if (*(u32*)(s0 + 3132) == 0) {
        a1 = 55;
    }
    func_0016bd60(s0, a1);
}
}  // namespace n002d5af0

// 002d5b48 (was src/anon/auto80_199_queue.cpp)
namespace n002d5b48 {
/*TARGET 002d5b48*/
void Ti__MGOarashiPlayer__stop_tornado_attack(u32 a0) asm("_Z40Ti__MGOarashiPlayer__stop_tornado_attackj");
void Ti__MGOarashiPlayer__stop_tornado_attack(u32 a0) {
    u8* s0 = (u8*)a0;
    s32 t7 = -1;
    u32 v0 = *(u32*)(s0 + 3128);
    if (v0 != 0) {
        if (*(s32*)(s0 + 3132) >= 0) {
            u32* vtbl = *(u32**)v0;
            ((void (*)(u32))vtbl[8])(v0);
            t7 = -1;
        }
    }
    *(u32*)(s0 + 3128) = 0;
    *(s32*)(s0 + 3132) = t7;
    func_0016bd60(a0, 37);
}
}  // namespace n002d5b48

// 002d5ba8 (was never written: gap function)
namespace n002d5ba8 {
u32 func_0017a680(u8*) asm("func_0017a680");
u32 func_002d5ba8(u8* o) asm("func_002d5ba8");
u32 func_002d5ba8(u8* o)
{
    u32 r = 0;
    bool is = *(u32*)(*(u8**)(o + 12) + 4) == 0x38;
    if (!is) r = func_0017a680(o);
    return r;
}
}  // namespace n002d5ba8

// 002d5bd8 (was src/anon/batch_w1736.cpp)
namespace n002d5bd8 {
// 0x0026ff30: definition moved into src/anon/unit_0026f0a0.cpp

/* 002d5bd8 */
struct w1736_In { u8 p[4]; s32 kind; };
struct w1736_Ob { u8 p[0xc]; w1736_In* in; };
u8 func_00179b68(w1736_Ob*) asm("func_00179b68");
/*TARGET 002d5bd8*/
s32 func_002d5bd8(w1736_Ob* o) asm("func_002d5bd8");
s32 func_002d5bd8(w1736_Ob* o) {
    u32 k = o->in->kind;
    if ((k ^ 0x38) == 0 || (k ^ 0x37) == 0) return 1;
    return func_00179b68(o);
}
}  // namespace n002d5bd8

// 002d5c20 (was src/anon/batch_w4.cpp)
namespace n002d5c20 {
/*TARGET 002d5c20*/
// 0x002c5460: definition moved into src/anon/unit_002c53c8.cpp

f32* func_002d5c20(f32* v) asm("func_002d5c20");
// 0x002c5460: definition moved into src/anon/unit_002c53c8.cpp

f32* func_002d5c20(f32* v) {  // vec4_clear
    v[3] = v[2] = v[1] = v[0] = 0.0f;
    return v;
}
}  // namespace n002d5c20

// 002d5c40 (was src/anon/auto80_199_queue.cpp)
namespace n002d5c40 {
/*TARGET 002d5c40*/
u32 func_002d5c40(u32 a0) asm("_Z13func_002d5c40j");
u32 func_002d5c40(u32 a0) {
    u32 s0 = a0;
    u32 t4;
    if (func_002d5578(a0) != 0) {  // is_field340_eq151
        t4 = 1;
    } else {
        u32 t6 = *(u32*)(*(u32*)(s0 + 12) + 4);
        t4 = 2;
        if ((t6 ^ 0x37) != 0) {
            u32 a0v = t6 ^ 0x38;
            u32 t7 = 3;
            t4 = 0;
            if (a0v == 0) {
                t4 = t7;
            }
        }
    }
    return t4;
}
}  // namespace n002d5c40

// 002d5c98 (was src/anon/tiny_auto80_queue.cpp)
namespace n002d5c98 {
u32 func_001c0cd8(...) asm("func_001c0cd8");
/*TARGET 002d5c98*/
u32 func_002d5c98(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002d5c98jjjjjjjj");
u32 func_002d5c98(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = 0u;
    r15 = *(volatile u32*)((u32)r4 + (s32)(3092));
    r4 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_001c0cd8)(r4, r5, r6, r7, r8, r9, r10, r11);
        r2 = ((u32)0u < (u32)r2);
    }
    return r2;
}
}  // namespace n002d5c98

// 002d5cc8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002d5cc8 {
u32 func_002d5578(...) asm("func_002d5578");
/*TARGET 002d5cc8*/
u32 func_002d5cc8(u32 a0) asm("_Z13func_002d5cc8j");
u32 func_002d5cc8(u32 a0) {
    u32 s1 = 0;

    if (func_002d5578(a0) != 0) {  // is_field340_eq151
        u32 t7 = *(u8*)(a0 + 568);
        t7 &= 1u;
        s1 = (0u < t7) ? 1u : 0u;
    }

    return s1;
}
}  // namespace n002d5cc8

// 002d5d10 (was src/anon/batch_w17.cpp)
namespace n002d5d10 {
// 0x002c6158: definition moved into src/worldmap/cameramanager.cpp

extern u32 D_00362428 asm("D_00362428");
void func_002cfeb0(void*, u32, u32, u32) asm("func_002cfeb0");
// obj_init_field1416_bit800
void func_002e7308(void*) asm("func_002e7308");
/*TARGET 002d5d10*/
void func_002d5d10(u8* p, u32 a, u32 b) asm("func_002d5d10");
void func_002d5d10(u8* p, u32 a, u32 b) {
    func_002cfeb0(p, a, 1, b);  // obj_init_field1416_bit800
    *(void**)p = &D_00362428;
    func_002e7308(p + 2872);
}
}  // namespace n002d5d10

// 002d5d50 (was src/anon/batch_w18.cpp)
namespace n002d5d50 {
// 0x002d1840: definition moved into src/anon/unit_002cf260.cpp

extern u32 D_00362428 asm("D_00362428");
void func_002cfeb0(void*, u32, u32, u32) asm("func_002cfeb0");
// obj_init_field1416_bit800
void func_002e7308(void*) asm("func_002e7308");
/*TARGET 002d5d50*/
void func_002d5d50(u8* p, u32 a, u32 b) asm("func_002d5d50");
void func_002d5d50(u8* p, u32 a, u32 b) {
    func_002cfeb0(p, a, 1, b);  // obj_init_field1416_bit800
    *(void**)p = &D_00362428;
    func_002e7308(p + 2872);
}
}  // namespace n002d5d50

// 002d5d90 (was never written: gap function)
namespace n002d5d90 {
extern u8 D_00362428[] asm("D_00362428");
void func_002e7328(u8*) asm("func_002e7328");
void func_002cff98(u8*) asm("func_002cff98");
struct NoTail { ~NoTail() {} };
void func_002d5d90(u8* o) asm("func_002d5d90");
void func_002d5d90(u8* o)
{
    NoTail nt;
    *(u8**)o = D_00362428;
    func_002e7328(o + 2872);
    func_002cff98(o);
}
}  // namespace n002d5d90

// 002d5dd0 (was src/anon/batch_w19.cpp)
namespace n002d5dd0 {
u8 func_002cff98(void*) asm("func_002cff98");
u8 func_002e7328(void*) asm("func_002e7328");
extern u8 D_00362428[] asm("D_00362428");
/*TARGET 002d5dd0*/
u32 func_002d5dd0(u8* p) asm("func_002d5dd0");
u32 func_002d5dd0(u8* p) {
    *(void**)p = D_00362428;
    func_002e7328(p + 0xb38);  // to_2e7458
    return func_002cff98(p);
}
}  // namespace n002d5dd0

// 002d5e10 (was src/anon/batch_w32.cpp)
namespace n002d5e10 {
extern u8 D_00362428[] asm("D_00362428");
void func_002e7328(void*) asm("func_002e7328");
// to_2e7458
void func_002cff98(void*) asm("func_002cff98");
void func_00105110(void*) asm("func_00105110");
/*TARGET 002d5e10*/
// 0x002bc398: definition moved into src/anon/unit_002bb8b0.cpp

void func_002d5e10(void** p) asm("func_002d5e10");
// 0x002bc398: definition moved into src/anon/unit_002bb8b0.cpp

void func_002d5e10(void** p) {
    p[0] = D_00362428;
    func_002e7328((u8*)p + 0xb38);  // to_2e7458
    func_002cff98(p);
    func_00105110(p);
}
}  // namespace n002d5e10

// 002d5e50 (was src/anon/batch_w90.cpp)
namespace n002d5e50 {
// 0x002ab368: definition moved into src/anon/unit_002a99c8.cpp

// 002d5e50
void func_002d00a0(void*) asm("func_002d00a0");
s32 func_00181500(s32) asm("func_00181500");
u32 func_002d1260(void) asm("func_002d1260");
void YS__OBJ__attach(void*, u32, s32, s32) asm("YS__OBJ__attach");
u8* func_002d1878(void*) asm("func_002d1878");
void func_002e7340(void*, void*, s32, void*, f32, f32) asm("func_002e7340");
extern u8 D_00362380[] asm("D_00362380");
extern u8 D_00362388[] asm("D_00362388");
union PtrWord { void* p; u32 w; };
extern PtrWord D_00361f60 asm("D_00361f60");
/*TARGET 002d5e50*/
void func_002d5e50(u8* self) asm("func_002d5e50");
void func_002d5e50(u8* self)
{
    func_002d00a0(self);
    s32 z = func_00181500(9271) == 0;
    D_00362380[1] = 21 - z;
    YS__OBJ__attach(self, func_002d1260(), 67, 0);
    *(u32*)(self + 264) |= 2;
    asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(self + 2848) : "memory");
    *(u32*)(self + 2864) = 0;
    *(u32*)(self + 2868) = 0;
    u8* x = self + 2872;
    void* q = D_00361f60.p;
    if (q) {
        u8* a = func_002d1878(q);
        u8* b = func_002d1878(q);
        func_002e7340(x, self, 3, D_00362388, *(f32*)(a + 256), *(f32*)(b + 260));
    }
}
}  // namespace n002d5e50

// 002d5f48 (was src/anon/batch_w1337.cpp)
namespace n002d5f48 {
#define QCOPY1337(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPY4_1337(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QV1337 {
    f32 x, y, z, w;
    QV1337() {}
    QV1337(const QV1337& o) { QCOPY1337(this, &o); }
    QV1337& operator=(const QV1337& o) { if (this != &o) QCOPY1337(this, &o); return *this; }
} __attribute__((aligned(16)));
struct QM1337 {
    QV1337 r[4];
    QM1337() {}
    QM1337(const QM1337& o) { QCOPY4_1337(this, &o); }
    QV1337 operator*(const QV1337& v) const {
        QV1337 o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
// 0x002d0718: definition moved into src/anon/unit_002cf260.cpp


extern u8* D_00361f60 asm("D_00361f60");
void BtlObj_pre_exec(void*) asm("_ZN2YS6BTLOBJ13_OVR_pre_execEv");
s32 Obj_is_attach(void*) asm("_ZN2YS3OBJ9is_attachEv");
void Obj_set_pos(void*, const QV1337*) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
QV1337* YS__OBJ__get_pos(void*) asm("YS__OBJ__get_pos");
QM1337* func_002d1f10(u8*) asm("func_002d1f10");
QM1337* func_002d1f00(u8*) asm("func_002d1f00");
void YS__OBJ__set_wish_dir(void*, QV1337*) asm("YS__OBJ__set_wish_dir");
/*TARGET 002d5f48*/
void func_002d5f48(u8* self) asm("func_002d5f48");
void func_002d5f48(u8* self) {
    u8* other;
    BtlObj_pre_exec(self);
    other = D_00361f60;
    if (other == 0) return;
    if (Obj_is_attach(self) == 0) {
        QV1337 pos(*YS__OBJ__get_pos(self));
        QM1337 m(*func_002d1f10(other));
        m.invOrtho();
        pos.w = 1.0f;
        QV1337 local = m * pos;
        local.z = 0.0f;
        QV1337 world = *func_002d1f00(other) * local;
        world.z = 0.0f;
        Obj_set_pos(self, &world);
        QV1337 v(*(QV1337*)(self + 0xb20));
        YS__OBJ__set_wish_dir(self, &v);
    } else {
        *(u32*)(self + 0x108) |= 2;
    }
}
}  // namespace n002d5f48

// 002d60e8 (was src/anon/batch_w79.cpp)
namespace n002d60e8 {
extern void* D_00361f60 asm("D_00361f60");
u8* func_002d1878(void*) asm("func_002d1878");
/*TARGET 002d60e8*/
// 0x002c5c50: definition moved into src/anon/unit_002c53c8.cpp

// Interpolates between two keys by the current time.
f32 Ti__MGOarashiPo__get_separate_speed(u8* p) asm("Ti__MGOarashiPo__get_separate_speed");
// 0x002c5c50: definition moved into src/anon/unit_002c53c8.cpp

// Interpolates between two keys by the current time.
f32 Ti__MGOarashiPo__get_separate_speed(u8* p) {
    void* o = D_00361f60;
    u8* a = func_002d1878(o);
    u8* b = func_002d1878(o);
    u8* c = func_002d1878(o);
    u8* d = func_002d1878(o);
    f32 x = *(f32*)(p + 2868);
    f32 k = *(f32*)(b + 160);
    f32 w;
    if (x < k) return *(f32*)(a + 156);
    w = *(f32*)(c + 164);
    if (x < k + w) {
        f32 t = (x - k) / w;
        return *(f32*)(a + 156) * (1.0f - t) + *(f32*)(d + 168) * t;
    }
    return *(f32*)(d + 168);
}
}  // namespace n002d60e8

// 002d61c0 (was never written: gap function)
namespace n002d61c0 {
struct V {
    f32 x, y, z, w;
    V() {}
    V(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
    V& operator=(const V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32 normalize() {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
            : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
extern f32 D_00349e10 asm("D_00349e10");
void func_0016a9a0(u8*) asm("func_0016a9a0");
u32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0016b070(u8*, V*) asm("func_0016b070");
void func_0016ace0(u8*, V*) asm("func_0016ace0");
void Ti__Path__search_near_point_from_pre_point_nocycle(u8*) asm("Ti__Path__search_near_point_from_pre_point_nocycle");
f32 Ti__MGOarashiPo__get_separate_speed(u8*) asm("Ti__MGOarashiPo__get_separate_speed");
void func_002d61c0(u8* o) asm("func_002d61c0");
void func_002d61c0(u8* o)
{
    V* d = (V*)(o + 16);
    func_0016a9a0(o);
    d->Zero();
    if (func_001c0cd8(o)) {
        V a(-1.5707963f, -1.5707963f, 0.0f, 0.0f);
        func_0016b070(o, &a);
        V b(0.0f, 0.0f, 0.0f, 0.0f);
        func_0016ace0(o, &b);
    } else {
        Ti__Path__search_near_point_from_pre_point_nocycle(o);
        *d = *(V*)(o + 2848);
        d->normalize();
        *(f32*)(o + 28) = Ti__MGOarashiPo__get_separate_speed(o);
        *(f32*)(o + 2868) += D_00349e10;
    }
}
}  // namespace n002d61c0

