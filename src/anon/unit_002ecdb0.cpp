// Linked unit 0x002ecd98-0x002ee588 (0x2ecd98 is a gap action method before 0x2ecdb0) (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
typedef unsigned int u128 __attribute__((mode(TI)));
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/menu_sound.hpp"


// 002ecd98 (gap): action method, clears the velocity and copies the base height
extern "C" void func_002ecd98(u32, u8* o) {
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(o + 32) : "memory");
    *(f32*)(o + 240) = *(f32*)(o + 296);
}

// 002ecdb0 (was src/anon/batch_w3.cpp)
namespace n002ecdb0 {
struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
};
/*TARGET 002ecdb0*/
void func_002ecdb0(VObj* o) asm("func_002ecdb0");
void func_002ecdb0(VObj* o) { o->v9(); }
}  // namespace n002ecdb0

// 002ecdd8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002ecdd8 {
u32 func_00195858(u32, u32, u32, u32) asm("_Z13func_00195858jjjj");
/*TARGET 002ecdd8*/
// 0x002de7e8: definition moved into src/anon/unit_002de3c8.cpp

// 002e3ed0: moved to src/anon/unit_002e2f08.cpp

u32 func_002ecdd8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ecdd8jjjj");
// 0x002de7e8: definition moved into src/anon/unit_002de3c8.cpp

// 002e3ed0: moved to src/anon/unit_002e2f08.cpp

u32 func_002ecdd8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)r5 + (272));
    r5 = (u32)((s32)0u + (1));
    u32 (*fp_call4_00195858)(u32, u32, u32, u32) = func_00195858;
    r2 = fp_call4_00195858(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002ecdd8

// 002ecdf8 (was src/anon/batch_w30.cpp)
namespace n002ecdf8 {
void func_00195858(void*, u32) asm("func_00195858");
/*TARGET 002ecdf8*/
// 0x002daa98: definition moved into src/anon/unit_002da040.cpp

// 002e2240: moved to src/anon/unit_002e1908.cpp

void func_002ecdf8(u8* p, u8* a) asm("func_002ecdf8");
// 0x002daa98: definition moved into src/anon/unit_002da040.cpp

// 002e2240: moved to src/anon/unit_002e1908.cpp

void func_002ecdf8(u8* p, u8* a) {
    func_00195858(a + 272, 60);
    (*(void (**)(void*, void*))(*(u8**)p + 36))(p, a);
}
}  // namespace n002ecdf8

// 002ece48 (was src/anon/batch_w31.cpp)
namespace n002ece48 {
void func_00195858(void*, int) asm("func_00195858");
typedef void (*VFn2)(void*, void*);
/*TARGET 002ece48*/
void func_002ece48(void** p, u8* q) asm("func_002ece48");
void func_002ece48(void** p, u8* q) {
    func_00195858(q + 272, 63);
    (*(VFn2*)(*(u8**)p + 36))(p, q);
}
}  // namespace n002ece48

// 002ece98 (was src/anon/batch_w24.cpp)
namespace n002ece98 {
// 0x002db858: definition moved into src/anon/unit_002da040.cpp

void func_00195858(u8*, s32) asm("func_00195858");
/*TARGET 002ece98*/
void func_002ece98(u32, u8* o) asm("func_002ece98");
void func_002ece98(u32, u8* o) {
    func_00195858(o + 272, 62);
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(o + 32) : "memory");
    *(f32*)(o + 240) = *(f32*)(o + 296);
}
}  // namespace n002ece98

// 002eced8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002eced8 {
u32 func_00195858(u32, u32, u32, u32) asm("_Z13func_00195858jjjj");
/*TARGET 002eced8*/
u32 func_002eced8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002eced8jjjj");
u32 func_002eced8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)r5 + (272));
    r5 = (u32)((s32)0u + (1));
    u32 (*fp_call4_00195858)(u32, u32, u32, u32) = func_00195858;
    r2 = fp_call4_00195858(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002eced8

// 002ecef8 (was src/anon/batch_w1831.cpp)
namespace n002ecef8 {
// 002ecef8: vector with lq/sq copy ctor, copy-assign and VU0 scale.
struct W1831QC {
    f32 x, y, z, w;
    W1831QC() {}
    W1831QC(const W1831QC& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1831QC& operator=(const W1831QC& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1831QC& operator*=(f32 k) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    W1831QC operator*(f32 k) const {
        W1831QC r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1831Body {
    u8 p0[0x10];
    W1831QC v10;
    W1831QC v20;
    u8 p30[0xf0 - 0x30];
    f32 ff0;
    u8 pf4[0x114 - 0xf4];
    f32 f114;
};
// Soft-float double helpers (game copies). Declared const so gcc treats them like its own libcalls.
u64 func_00313b80(f32)  asm("func_00313b80")__attribute__((const));
s32 func_003142e0(u64, u64)  asm("func_003142e0")__attribute__((const));
extern f32 D_00349e10 asm("D_00349e10");
void YS__OBJ__set_wish_dir(W1831Body*, W1831QC) asm("YS__OBJ__set_wish_dir");
W1831QC YS__OBJ__get_dir(W1831Body*) asm("YS__OBJ__get_dir");
/*TARGET 002ecef8*/
W1831QC Ts__ACTION_LIMIT_PETERPAN__calc_movement(void* self, W1831Body* o) asm("Ts__ACTION_LIMIT_PETERPAN__calc_movement");
W1831QC Ts__ACTION_LIMIT_PETERPAN__calc_movement(void* self, W1831Body* o) {
    W1831QC a;
    if (func_003142e0(0, func_00313b80(o->v10.w)) < 0 && o->v10.x != 0.0f && o->v10.z != 0.0f) {
        YS__OBJ__set_wish_dir(o, o->v10);
    }
    a = YS__OBJ__get_dir(o);
    a *= o->f114;
    a.y = o->v10.y * o->v10.w * (1.0f - o->ff0) + o->v20.y * o->ff0;
    o->v20 = a;
    return a * D_00349e10;
}
}  // namespace n002ecef8

// 002ed020 (was gap)
namespace n002ed020 {
struct GP20 { f32 f0, f4, f8; };
extern GP20 D_00363630 asm("D_00363630");
void gap_002ed020(void* self, u8* o) asm("gap_002ed020");
void gap_002ed020(void* self, u8* o) {
    *(f32*)(o + 272) = D_00363630.f0;
    *(f32*)(o + 276) = D_00363630.f4;
    *(f32*)(o + 284) = D_00363630.f8;
}
}  // namespace n002ed020

// 002ed048 (was gap)
namespace n002ed048 {
void gap_002ed048(void* self, u8* o) asm("gap_002ed048");
void gap_002ed048(void* self, u8* o) {
    f32* v = *(f32**)(o + 300);
    *(f32*)(o + 272) = v[0];
    *(f32*)(o + 276) = v[1];
    *(f32*)(o + 284) = v[3];
}
}  // namespace n002ed048

// 002ed068 (was src/anon/batch_w276.cpp)
namespace n002ed068 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QV& operator=(const QV& o) { if (this != &o) QCOPY(this, &o); return *this; }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
static inline f32 normalize(QV* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline f32 dot3(QV* v) {
    register f32 d asm("$f0");
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(d) : "r"(v) : "$8", "memory");
    return d;
}
struct O { u8 pad[16]; QV v16; QV v32; };
struct GP { f32 f0, f4, f8, f12, f16, f20, f24, f28, g32; };
extern GP D_00363630 asm("D_00363630");
u64 func_00313b80(f32) asm("func_00313b80");
// float_to_double
s32 func_003142e0(u64, u64) asm("func_003142e0");
// double_compare
void func_00183768(O*, QV*, f32) asm("func_00183768");
// copy_quad_at16_and_len
QV kn__MotionPrototype0__calcLimitValue(O*, f32, f32) asm("kn__MotionPrototype0__calcLimitValue");
void YS__OBJ__turn_to_dir(O*, QV*) asm("YS__OBJ__turn_to_dir");
QV func_002ede48(O*, QV*, f32, f32) asm("func_002ede48");
/*TARGET 002ed068*/
QV func_002ed068(void* unused, O* o) asm("func_002ed068");
QV func_002ed068(void* unused, O* o) {
    QV r;
    r = o->v32;
    f32 len = normalize(&r);
    r.w = len;
    if (func_003142e0(0, func_00313b80(o->v16.w)) < 0 && o->v16.w <= len) {  // double_compare
        func_00183768(o, &o->v16, len);  // copy_quad_at16_and_len
    }
    f32 t = (D_00363630.f24 < o->v16.w) ? D_00363630.f16 : D_00363630.f20;
    r = kn__MotionPrototype0__calcLimitValue(o, D_00363630.f12, 1.0f - t);
    f32 d = dot3(&r);
    register f32 z asm("$f12") = 0.0f;
    if (z < d) YS__OBJ__turn_to_dir(o, &r);
    r = func_002ede48(o, &r, D_00363630.f28, D_00363630.g32);
    return r;
}
}  // namespace n002ed068

// 002ed1d8 (was src/anon/batch_w54.cpp)
namespace n002ed1d8 {
// 128-bit value with a self-checking lq/sq copy
struct Q16 {
    u128 v;
    Q16& operator=(const Q16& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
// noreorder: the original keeps the following branch delay slot empty
static inline void vu0_scaled(Q16& r, const Q16& v, f32 s) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\t"
                 "vmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
}
// normalize xyz in place, returns the length
static inline f32 vu0_normalize(Q16& v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\t"
                 "vaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\t"
                 "vaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\t"
                 "vmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(len) : "r"(&v) : "$8", "memory");
    return len;
}
void func_0016bd60(void*, s32) asm("func_0016bd60");
// 0x002de968: definition moved into src/anon/unit_002de3c8.cpp

struct Glob363 {
    u8 pad[16];
    f32 a, b;
};
extern Glob363 D_00363630 asm("D_00363630");
/*TARGET 002ed1d8*/
void func_002ed1d8(u8* p, Q16* v, f32 a, f32 b) asm("func_002ed1d8");
void func_002ed1d8(u8* p, Q16* v, f32 a, f32 b) {
    D_00363630.a = a;
    D_00363630.b = b;
    f32 w = ((f32*)v)[3];
    vu0_normalize(*v);
    Q16* dst = (Q16*)(p + 32);
    Q16 t;
    vu0_scaled(t, *v, w);
    *dst = t;
    func_0016bd60(p, 42);
}
}  // namespace n002ed1d8

// 002ed268 (was src/anon/batch_w64.cpp)
namespace n002ed268 {
// Builds a vector, sets w = 0 and transforms it by the current view matrix.
// 002e1908: moved to src/anon/unit_002e1908.cpp

// ---------------------------------------------------------------------------
struct Words9 { u32 w[9]; };
extern Words9 D_00363630 asm("D_00363630");
void wt_002ed268(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002ed268jjjj");
/*TARGET 002ed268*/
void wt_002ed268(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002ed268jjjj");
void wt_002ed268(u32 a, u32 b, u32 c, u32 d) {
    D_00363630 = *(Words9*)a;
}
}  // namespace n002ed268

// 002ed2b0 (was src/anon/batch_w32.cpp)
namespace n002ed2b0 {
void func_001c23a8(void*, void*, s32, s32, s32, s32, void*) asm("func_001c23a8");
extern u8 D_00363758[] asm("D_00363758");
extern void* D_00363748 asm("D_00363748");
/*TARGET 002ed2b0*/
// 002e9b10: moved to src/anon/unit_002e9a00.cpp

void func_002ed2b0(void** p, void* b, void* c) asm("func_002ed2b0");
// 002e9b10: moved to src/anon/unit_002e9a00.cpp

void func_002ed2b0(void** p, void* b, void* c) {
    func_001c23a8(p, b, 0, 1, 0, 128, c);
    p[0] = D_00363758;
    D_00363748 = p;
}
}  // namespace n002ed2b0

// 002ed300 (was src/anon/batch_w33.cpp)
namespace n002ed300 {
void func_001c23a8(void*, void*, s32, s32, s32, s32, void*) asm("func_001c23a8");
extern void* D_00363758[] asm("D_00363758");
extern void* D_00363748 asm("D_00363748");
/*TARGET 002ed300*/
void func_002ed300(void** p, void* a, void* b) asm("func_002ed300");
void func_002ed300(void** p, void* a, void* b) {
    func_001c23a8(p, a, 0, 1, 0, 128, b);
    *p = D_00363758;
    D_00363748 = p;
}
}  // namespace n002ed300

// 002ed350 (was src/anon/batch_w80.cpp)
namespace n002ed350 {
// ---- unit 24 (o.cpp)
struct U24_W80Vec {
    f32 x, y, z, w;
    U24_W80Vec& operator=(const U24_W80Vec& v) {
        if (this != &v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&v) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct U24_W80Param { u32 a, b, c, d, e; };
struct U24_W80Eff { u8 pad[64]; U24_W80Vec pos; u8 pad2[100 - 80]; U24_W80Param prm; };
struct U24_W80Heap { u8 pad[8]; u32 f8; };
struct U24_W80Own { u8 pad[2548]; u8* heap; };
U24_W80Eff* func_001db888(U24_W80Heap*, u32, void*) asm("func_001db888");
// record_index_calc
void func_002ed8a0(void) asm("func_002ed8a0");
void func_002ed558(U24_W80Eff*, U24_W80Own*, u32, u32, void (*)(void)) asm("func_002ed558");
void func_002ed5a8(U24_W80Eff*) asm("func_002ed5a8");
/*TARGET 002ed350*/
// 0x002e1668: definition moved into src/anon/unit_002de3c8.cpp


U24_W80Eff* func_002ed350(U24_W80Own* own, u32 a1, const U24_W80Param* prm, u32 a3, const U24_W80Vec* pos) asm("func_002ed350");
// 0x002e1668: definition moved into src/anon/unit_002de3c8.cpp


U24_W80Eff* func_002ed350(U24_W80Own* own, u32 a1, const U24_W80Param* prm, u32 a3, const U24_W80Vec* pos) {
    U24_W80Heap* h = (U24_W80Heap*)(own->heap + 20);
    U24_W80Eff* e;
    if (!h->f8) return 0;
    e = func_001db888(h, 128, __builtin_return_address(0));  // record_index_calc
    func_002ed558(e, own, a1, a3, func_002ed8a0);
    e->prm = *prm;
    e->pos = *pos;
    func_002ed5a8(e);
    return e;
}
}  // namespace n002ed350

// 002ed438 (was src/anon/batch_w18.cpp)
namespace n002ed438 {
// 002e2e18: moved to src/anon/unit_002e2d18.cpp

void* func_001050d8(u32) asm("func_001050d8");
void* func_0016e920(u32) asm("func_0016e920");
void func_002ed300(void*, void*, u32) asm("func_002ed300");
void TrinityShot_Init(void* self) asm("_ZN2Ts16TRINITY_SHOT_OBJ4InitEv");
/*TARGET 002ed438*/
void TrinityShot_Init(void* self) asm("_ZN2Ts16TRINITY_SHOT_OBJ4InitEv");
void TrinityShot_Init(void* self) {
    void* v = func_001050d8(2560);
    func_002ed300(v, func_0016e920(1475), 256);
}
}  // namespace n002ed438

// 002ed478 (was src/anon/tiny_auto80_queue.cpp)
namespace n002ed478 {
typedef void (*Fn_002ed478)(u32);
/*TARGET 002ed478*/
void func_002ed478() asm("_Z13func_002ed478v");
void func_002ed478() {
    u32* base = (u32*)0x00360000;
    u32 s0 = *(u32*)((u8*)base + 14152);
    if (s0 != 0) {
        Fn_002ed478 fn = *(Fn_002ed478*)(*(u32*)s0 + 32);
        fn(s0);
        *(u32*)((u8*)base + 14152) = 0;
    }
}
}  // namespace n002ed478

// 002ed4b8 (was src/anon/batch_w58.cpp)
namespace n002ed4b8 {
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
// 128-bit copy.
static inline void cpq(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
// 002ecb10: moved to src/anon/unit_002ec5f8.cpp

extern u32 D_00363748 asm("D_00363748");
u8* func_002ed350(u32, u32, u32, Vec4*, Vec4*) asm("func_002ed350");
/*TARGET 002ed4b8*/
u8* func_002ed4b8(u32 a0, u32 a1, Vec4* a2, Vec4* a3) asm("func_002ed4b8");
u8* func_002ed4b8(u32 a0, u32 a1, Vec4* a2, Vec4* a3) {
    Vec4 b, c;
    cpq(&b, a3);
    cpq(&c, a2);
    u8* r = func_002ed350(D_00363748, a0, a1, &c, &b);
    return r ? r + 48 : 0;
}
}  // namespace n002ed4b8

// 002ed508 (was src/anon/batch_w34.cpp)
namespace n002ed508 {
void func_001c1748(void*, u32, u32, u32) asm("func_001c1748");
// obj_init_from_src
void func_00190128(void*) asm("func_00190128");
/*TARGET 002ed508*/
// 0x002dc278: definition moved into src/anon/unit_002da040.cpp

// 002e3c28: moved to src/anon/unit_002e2f08.cpp

// 002eb9d8: moved to src/anon/unit_002eaf38.cpp

void func_002ed508(u8* p, u8* q, u32 c, u32 d, u32 e) asm("func_002ed508");
// 0x002dc278: definition moved into src/anon/unit_002da040.cpp

// 002e3c28: moved to src/anon/unit_002e2f08.cpp

// 002eb9d8: moved to src/anon/unit_002eaf38.cpp

void func_002ed508(u8* p, u8* q, u32 c, u32 d, u32 e) {
    func_001c1748(p, *(u32*)(q + 2548), d, e);  // obj_init_from_src
    *(u32*)(p + 80) = c;
    func_00190128(p + 100);
    *(u32*)(p + 120) = 0;
}
}  // namespace n002ed508

// 002ed558 (was src/anon/batch_w35.cpp)
namespace n002ed558 {
void func_001c1748(void*, u32, u32, u32) asm("func_001c1748");
// obj_init_from_src
void func_00190128(void*) asm("func_00190128");
/*TARGET 002ed558*/
void func_002ed558(u8* p, u8* q, u32 a2, u32 a3, u32 a4) asm("func_002ed558");
void func_002ed558(u8* p, u8* q, u32 a2, u32 a3, u32 a4) {
    func_001c1748(p, *(u32*)(q + 2548), a3, a4);  // obj_init_from_src
    *(u32*)(p + 80) = a2;
    func_00190128(p + 100);
    *(u32*)(p + 120) = 0;
}
}  // namespace n002ed558

// 002ed5a8 (was src/anon/batch_w52.cpp)
namespace n002ed5a8 {
/*TARGET 002ed5a8*/
// 002e2e50: moved to src/anon/unit_002e2d18.cpp

void func_002ed5a8(u8* p) asm("func_002ed5a8");
// 002e2e50: moved to src/anon/unit_002e2d18.cpp

void func_002ed5a8(u8* p) {
    *(u32*)(p + 96) = 0;
    *(u32*)(p + 120) = 1;
    p[20] = 8;
    p[22] = 0xff;
    *(f32*)(p + 88) = 60.0f;
    *(f32*)(p + 92) = 20.0f;
    p[84] = 7;
    // normalize the vector at +64 (VU0)
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(p + 64) : "$8", "$f0", "memory");
}
}  // namespace n002ed5a8

// 002ed630 (was src/anon/batch_w1811_nsa.cpp)
namespace n002ed630 {
struct W1811V {
    f32 x, y, z, w;
    W1811V() {}
    W1811V& operator=(const W1811V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1811V operator-(const W1811V& o) const {
        W1811V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W1811V operator*(f32 k) const {
        W1811V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    W1811V& operator+=(const W1811V& b) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
/* 002ed630: homing mover (target at 0x64, turn rate 0x60, speed 0x5c). */
struct W1811Tgt { s32 a, b, c, d, e; };
struct W1811Homer { W1811V pos; u8 p10[0x20]; W1811V dir; W1811V vel; u8 p50[0xc]; f32 spd; f32 turn; W1811Tgt tgt; s32 flags; };
extern f32 D_00349e10 asm("D_00349e10");
W1811V func_00190388(W1811Tgt*) asm("func_00190388");
W1811V func_0017d348(W1811V*, W1811V*, f32) asm("func_0017d348");
/*TARGET 002ed630*/
// 0x001c6760: definition moved into src/anon/unit_001c5b90.cpp

void func_002ed630(W1811Homer* o) asm("func_002ed630");
// 0x001c6760: definition moved into src/anon/unit_001c5b90.cpp

void func_002ed630(W1811Homer* o) {
    if ((o->flags & 1) == 1) {
        o->dir = func_00190388(&o->tgt) - o->pos;
        o->vel = func_0017d348(&o->vel, &o->dir, o->turn);
    }
    o->pos += o->vel * o->spd * D_00349e10;
}
}  // namespace n002ed630

// 002ed720 (was src/anon/tiny_leaf_fpu.cpp)
namespace n002ed720 {
/*TARGET 002ed720*/
// 0x002e0870: definition moved into src/anon/unit_002de3c8.cpp

void func_002ed720(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ed720jjjj");
// 0x002e0870: definition moved into src/anon/unit_002de3c8.cpp

void func_002ed720(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    f32 f0 = 0.0f, f1 = 0.0f;
    r15 = (u32)(0x0035u << 16);
    f0 = *(f32*)((u32)r4 + (s32)(88));
    f1 = *(f32*)((u32)r15 + (s32)(-25072));
    f0 = f0 - f1;
    *(f32*)((u32)r4 + (s32)(88)) = f0;
}
}  // namespace n002ed720

// 002ed738 (was src/anon/batch_w90.cpp)
namespace n002ed738 {
// 0x002d5e50: definition moved into src/anon/unit_002d4548.cpp

// 002ed738
s32 func_00190140(void*) asm("func_00190140");
f32 YS__TARGET__get_dist(void*, void*) asm("YS__TARGET__get_dist");
double func_00313b80(f32) asm("func_00313b80");
// float_to_double
s32 func_003142e0(double, double) asm("func_003142e0");
// double_compare
void func_002ed630(void*) asm("func_002ed630");
void func_002ed720(void*) asm("func_002ed720");
u32 func_002ed830(void*) asm("func_002ed830");
void func_002ed8c0(void) asm("func_002ed8c0");
struct Fx { u32 pos[4]; u32 cb; u8 cur; u8 pad[63]; u8 src; u8 pad2[3]; f32 t; u8 pad3[8]; u8 trk[20]; struct { u32 on : 1; } fl; };
u32 Ts__TRINITY_SHOT_EFFECT__main(Fx* self, u32, u32, u32) asm("_Z29Ts__TRINITY_SHOT_EFFECT__mainjjjj");
/*TARGET 002ed738*/
u32 Ts__TRINITY_SHOT_EFFECT__main(Fx* self, u32, u32, u32) asm("_Z29Ts__TRINITY_SHOT_EFFECT__mainjjjj");
u32 Ts__TRINITY_SHOT_EFFECT__main(Fx* self, u32, u32, u32)
{
    self->cur = self->src;
    if (self->fl.on) {
        if (func_00190140(self->trk)) {
            u32 tmp[4] __attribute__((aligned(16)));
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(tmp), "r"(self->pos) : "$8", "memory");
            if (func_003142e0(func_00313b80(YS__TARGET__get_dist(self->trk, tmp)), 30.0) < 0) self->fl.on = 0;
        } else {
            self->fl.on = 0;
        }
    }
    func_002ed630(self);
    func_002ed720(self);
    if (func_003142e0(func_00313b80(self->t), 0.0) <= 0) {  // double_compare
        self->t = 8.0f;
        self->cb = (u32)func_002ed8c0;
        return func_002ed830(self);
    }
    return 1;
}
}  // namespace n002ed738

// 002ed830 (was src/anon/batch_w44.cpp)
namespace n002ed830 {
u32 u_call4_002ed830(u32, u32, u32, u32) asm("_Z16u_call4_002ed830jjjj");
void func_002ed630(void*) asm("func_002ed630");
void func_002ed720(void*) asm("func_002ed720");
/*TARGET 002ed830*/
// 002e3a18: moved to src/anon/unit_002e2f08.cpp

// 002eb7f0: moved to src/anon/unit_002eaf38.cpp

u32 u_call4_002ed830(u32 a, u32, u32, u32) asm("_Z16u_call4_002ed830jjjj");
// 002e3a18: moved to src/anon/unit_002e2f08.cpp

// 002eb7f0: moved to src/anon/unit_002eaf38.cpp

u32 u_call4_002ed830(u32 a, u32, u32, u32) {
    u8* o = (u8*)a;
    func_002ed630(o);
    func_002ed720(o);
    f32 f = *(f32*)(o + 88);
    if (f < 0.0f) return 0;
    *(u8*)(o + 21) = (s32)(f * 0.125f * 128.0f);
    return 1;
}
}  // namespace n002ed830

// 002ed8a0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002ed8a0 {
// set_vtbl_362d20
u32 Ts__TRINITY_SHOT_EFFECT__main(u32, u32, u32, u32) asm("_Z29Ts__TRINITY_SHOT_EFFECT__mainjjjj");
/*TARGET 002ed8a0*/
u32 func_002ed8a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ed8a0jjjj");
u32 func_002ed8a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_002ed738)(u32, u32, u32, u32) = Ts__TRINITY_SHOT_EFFECT__main;
    r2 = fp_call4_002ed738(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002ed8a0

// 002ed8c0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002ed8c0 {
u32 func_002ed830(u32, u32, u32, u32) asm("_Z13func_002ed830jjjj");
/*TARGET 002ed8c0*/
u32 func_002ed8c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ed8c0jjjj");
u32 func_002ed8c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_002ed830)(u32, u32, u32, u32) = func_002ed830;
    r2 = fp_call4_002ed830(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002ed8c0

// 002ed8e0 (was src/anon/batch_w95.cpp)
namespace n002ed8e0 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& s) {
        if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq operator*(const Vq& a, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
u32 Ts__SUMMON_ENEMY__Get(u32, u32, u32, u32) asm("_Z21Ts__SUMMON_ENEMY__Getjjjj");
// 002cec88: moved to src/taito/minigame_base.cpp (linked unit)

extern u32 D_003637b0[8] asm("D_003637b0");
extern u32 D_003638d0 asm("D_003638d0");
u8 YS__OBJENTRY__GetCacheBuffStatus(u32, u32) asm("YS__OBJENTRY__GetCacheBuffStatus");
u8* func_0016e920(u32) asm("func_0016e920");
s32 func_00182690(f32) asm("func_00182690");
u32 func_0016a020(u32) asm("func_0016a020");
u64 func_00312db8(u64, u64) asm("func_00312db8");
/*TARGET 002ed8e0*/
// Pick a random member among the eligible party slots.
u32 Ts__SUMMON_ENEMY__Get(u32 a, u32, u32, u32) asm("_Z21Ts__SUMMON_ENEMY__Getjjjj");
// Pick a random member among the eligible party slots.
u32 Ts__SUMMON_ENEMY__Get(u32 a, u32, u32, u32) {
    u32 cand[12];
    u32* out = cand;
    s32 n = 0;
    u32* src = D_003637b0;
    for (s32 i = 7; i >= 0; i--, src++) {
        if (YS__OBJENTRY__GetCacheBuffStatus(*src, 0) & 1) continue;
        if (func_00182690(func_0016e920(*src)[84])) {
            *out++ = *src;
            n++;
        }
    }
    if (n > 0) {
        D_003638d0 *= 0x10dcd;
        u32 r = D_003638d0;
        return cand[(s32)func_00312db8(r, func_00312db8((u64)(u32)(n - 1) + 0x100000000ULL, (u32)n))];
    }
    return func_0016a020(a);
}
}  // namespace n002ed8e0

// 002eda00 (was gap)
namespace n002eda00 {
// twin of 0x2eda10
extern u32* D_003637d0 asm("D_003637d0");
void gap_002eda00(u32* p) asm("gap_002eda00");
void gap_002eda00(u32* p) {
    *p = 0;
    D_003637d0 = p;
}
}  // namespace n002eda00

// 002eda10 (was src/anon/tiny_leaf.cpp)
namespace n002eda10 {
/*TARGET 002eda10*/
// 0x002d8898: definition moved into src/anon/unit_002d6f70.cpp

void func_002eda10(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002eda10jjjj");
// 0x002d8898: definition moved into src/anon/unit_002d6f70.cpp

void func_002eda10(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    *(u32*)((u32)r4 + (s32)(0)) = 0u;
    r15 = (u32)(0x0036u << 16);
    *(u32*)((u32)r15 + (s32)(14288)) = r4;
}
}  // namespace n002eda10

// 002eda20 (was gap)
namespace n002eda20 {
// twin of 0x2eda30
extern u32* D_003637d0 asm("D_003637d0");
void gap_002eda20() asm("gap_002eda20");
void gap_002eda20() {
    D_003637d0 = 0;
}
}  // namespace n002eda20

// 002eda30 (was src/anon/tiny.cpp)
namespace n002eda30 {
/*TARGET 002eda30*/
// 0x002dc7f8: definition moved into src/anon/unit_002da040.cpp

void func_002eda30(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002eda30jjjj");
// 0x002dc7f8: definition moved into src/anon/unit_002da040.cpp

void func_002eda30(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u32*)((u32)b + (14288)) = (u32)0;
}
}  // namespace n002eda30

// 002eda40 (was src/anon/batch_w59.cpp)
namespace n002eda40 {
void wtarget_002eda40(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002eda40jjjj");
// 0x002c1aa0: definition moved into src/anon/unit_002c10e0.cpp

// --- 002eda40
// Count the timer down by one; fire event 151 when it runs out.
extern f32 D_00349e10 asm("D_00349e10");
void func_001991a8(u32, u32) asm("func_001991a8");
/*TARGET 002eda40*/
void wtarget_002eda40(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002eda40jjjj");
void wtarget_002eda40(u32 a, u32 b, u32 c, u32 d) {
    f32* p = (f32*)a;
    if (0.0f < *p) {
        *p = *p - D_00349e10;
        if (*p <= 0.0f) func_001991a8(151, 0);
    }
}
}  // namespace n002eda40

// 002eda90 (was src/anon/batch_w44.cpp)
namespace n002eda90 {
void func_001991a8(s32) asm("func_001991a8");
/*TARGET 002eda90*/
void func_002eda90(f32* p, f32 f) asm("func_002eda90");
void func_002eda90(f32* p, f32 f) {
    func_001991a8(140);
    f32 v = *p;
    if (v < f) *p = v = f;
    *p = (1.0f < v) ? v : 1.0f;
}
}  // namespace n002eda90

// 002edaf8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002edaf8 {
// 0x0019ac30: definition moved into src/anon/unit_00199688.cpp

extern "C" u32 func_001991a8(...) asm("func_001991a8");
/*TARGET 002edaf8*/
void func_002edaf8(f32* a0) asm("_Z13func_002edaf8Pf");
void func_002edaf8(f32* a0) {
    f32 f1 = 0.0f;
    f32 f0 = a0[0];
    if (f1 < f0) {
        a0[0] = f1;
        func_001991a8(151, 0);
    }
}
}  // namespace n002edaf8

// 002edb38 (was src/anon/auto80_199_queue.cpp)
namespace n002edb38 {
/*TARGET 002edb38*/
// 002eb920: moved to src/anon/unit_002eaf38.cpp

// 002ec1d0: moved to src/anon/unit_002eaf38.cpp

void func_002edb38(void) asm("_Z13func_002edb38v");
// 002eb920: moved to src/anon/unit_002eaf38.cpp

// 002ec1d0: moved to src/anon/unit_002eaf38.cpp

void func_002edb38(void) {
    if (D_003637d0 != 0) {
        return;
    }

    u32 p = func_001050d8(4);
    func_002eda10(p);
    u32 q = func_00102c18(1, 20500, (u32)&D_002edb90);
    *(u32*)(q + 48) = (u32)&D_002edbb0;
}
}  // namespace n002edb38

// 002edb90 (was src/anon/tiny_wrappers_imp.cpp)
namespace n002edb90 {
u32 func_002eda40(u32, u32, u32, u32) asm("_Z13func_002eda40jjjj");
/*TARGET 002edb90*/
u32 func_002edb90(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002edb90jjjj");
u32 func_002edb90(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r5 = r4;
    r15 = (u32)(0x0036u << 16);
    r4 = *(u32*)((u32)r15 + (s32)(14288));
    return func_002eda40(r4, r5, r6, r7);
}
}  // namespace n002edb90

// 002edbb0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002edbb0 {
void func_002eda30(...) asm("func_002eda30");
u32 func_00106420(...) asm("func_00106420");
/*TARGET 002edbb0*/
void func_002edbb0() asm("_Z13func_002edbb0v");
void func_002edbb0() {
    u32* base = (u32*)0x00360000;
    u32 s0 = *(u32*)((u8*)base + 14288);
    if (s0 != 0) {
        func_002eda30(s0);
        func_00106420(s0);
    }
}
}  // namespace n002edbb0

// 002edbf8 (was src/anon/batch_wcx.cpp)
namespace n002edbf8 {
u8* YS__OBJ__Each(u8*) asm("YS__OBJ__Each");
s32 func_0016a070(u8*) asm("func_0016a070");
s32 func_0016c008(u8*, s32) asm("func_0016c008");
u8* Ts__XEMNAS__Get(u32, u32, u32, u32) asm("_Z15Ts__XEMNAS__Getjjjj");
/*TARGET 002edbf8*/
u8* Ts__XEMNAS__Get(u32 want, u32, u32, u32) asm("_Z15Ts__XEMNAS__Getjjjj");
u8* Ts__XEMNAS__Get(u32 want, u32, u32, u32)
{
    u8* n = 0;
    while ((n = YS__OBJ__Each(n))) {
        if (func_0016a070(n) != 4007) continue;
        if (func_0016c008(n, 1) == 1) { if (!want) return n; }
        else { if (want) return n; }
    }
    return 0;
}
}  // namespace n002edbf8

// 002edca0 (was src/anon/batch_w59.cpp)
namespace n002edca0 {
// --- 002edca0
u32 YS__OBJ__Each(u32) asm("YS__OBJ__Each");
u32 func_001c0cd8(u32) asm("func_001c0cd8");
void func_001c1020(u32, u32) asm("func_001c1020");
/*TARGET 002edca0*/
void func_002edca0(u32 key, u32 arg) asm("func_002edca0");
void func_002edca0(u32 key, u32 arg) {
    u32 o = 0;
    while ((o = YS__OBJ__Each(o))) {
        if (func_001c0cd8(o) && *(u32*)(o + 1392) == key) func_001c1020(o, arg);
    }
}
}  // namespace n002edca0

// .rodata 0x3761a8: a 10000.0f the code never loads, kept in place
extern const u32 R_003761a8[1] asm("D_003761a8") __attribute__((aligned(4))) = { 0x461c4000 };

// 002edd20 (was src/anon/batch_w1831.cpp)
namespace n002edd20 {
// 002edd20: vector with lq/sq copy-assign (self-check), used by value in a segment.
struct W1831QV {
    f32 x, y, z, w;
    W1831QV() {}
    W1831QV& operator=(const W1831QV& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1831Seg {
    W1831QV a, b;
    W1831Seg(const W1831QV& p, const W1831QV& q) { a = p; b = q; }
    W1831Seg() {}
};
struct W1831Obj { u8 pad[0x600]; s64 lo : 3; s64 kind : 32; };
// Soft-float double helpers (game copies). Declared const so gcc treats them like its own libcalls.
u64 func_00313b80(f32)  asm("func_00313b80")__attribute__((const));
u64 __subdf3(u64, u64)  asm("__subdf3")__attribute__((const));
u64 func_00313e80(u64, u64)  asm("func_00313e80")__attribute__((const));
f32 __truncdfsf2(u64)  asm("__truncdfsf2")__attribute__((const));
W1831QV* YS__OBJ__get_pos(W1831Obj*) asm("YS__OBJ__get_pos");
s32 func_00143b60(W1831Seg, W1831QV*, s32) asm("func_00143b60");
/*TARGET 002edd20*/
f32 Ts__ACTION_LIB__HeightFromFloor(W1831Obj* o) asm("Ts__ACTION_LIB__HeightFromFloor");
f32 Ts__ACTION_LIB__HeightFromFloor(W1831Obj* o) {
    W1831QV hit;
    W1831QV a;
    W1831QV b;
    W1831Seg s;
    W1831QV* pa = &a;
    W1831QV* pb = &b;
    W1831QV* pc = &s.a;
    W1831QV* pd = &s.b;
    *pa = *YS__OBJ__get_pos(o);
    *pb = *pa;
    a.y = __truncdfsf2(__subdf3(func_00313b80(a.y), 0x4069000000000000ULL));
    b.y = __truncdfsf2(func_00313e80(func_00313b80(b.y), 0x40c3ec0000000000ULL));
    *pc = *pa;
    *pd = *pb;
    if (func_00143b60(s, &hit, o->kind & 0xf)) return -(YS__OBJ__get_pos(o)->y - hit.y);
    return 10000.0f;
}
}  // namespace n002edd20

// 002ede48 (was src/anon/batch_w82.cpp)
namespace n002ede48 {
// 16-byte vector whose assignment is a 128-bit copy.
struct Vec82 {
    f32 x, y, z, w;
    Vec82& operator=(const Vec82& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern f32 D_00349e10 asm("D_00349e10");
f32 Ts__ACTION_LIB__HeightFromFloor(u32) asm("Ts__ACTION_LIB__HeightFromFloor");
f32 fabsf(f32) asm("fabsf");
// fabsf
double func_00313b80(f32) asm("func_00313b80");
// float_to_double
double func_00313e80(double, double) asm("func_00313e80");
// double_div
s32 func_003142e0(double, double) asm("func_003142e0");
/*TARGET 002ede48*/
// double_compare

// 002e2940: moved to src/anon/unit_002e1908.cpp

// Copies a2 into a0 and nudges its y toward the target height by one step.
Vec82* func_002ede48(Vec82* a0, u32 a1, Vec82* a2, f32 f12, f32 f13) asm("func_002ede48");
// double_compare

// 002e2940: moved to src/anon/unit_002e1908.cpp

// Copies a2 into a0 and nudges its y toward the target height by one step.
Vec82* func_002ede48(Vec82* a0, u32 a1, Vec82* a2, f32 f12, f32 f13)
{
    f32 diff = Ts__ACTION_LIB__HeightFromFloor(a1) - f12;
    f32 step;
    double dx;
    *a0 = *a2;
    dx = func_00313b80(fabsf(diff));  // float_to_double
    step = f13 * D_00349e10;
    if (func_003142e0(func_00313e80(func_00313b80(step), 10.0), dx) < 0) {  // double_compare
        if (func_003142e0(func_00313b80(diff), 0.0) < 0) a0->y -= step;
        else a0->y += step;
    }
    return a0;
}
}  // namespace n002ede48

// 002edf28 (was src/anon/batch_w25.cpp)
namespace n002edf28 {
// 0x002cff50: definition moved into src/anon/unit_002cf260.cpp

extern u8 D_003637e0 asm("D_003637e0");
struct C4 { u8 r, g, b, a; };
struct O2ed { void* vt; u32 a, b, c, d, e; C4 col; u32 f; };
/*TARGET 002edf28*/
// Constructor: zeroed fields, colour 128/128/128/128.
void func_002edf28(O2ed* o) asm("func_002edf28");
// Constructor: zeroed fields, colour 128/128/128/128.
void func_002edf28(O2ed* o) {  // obj_ctor_3637e0
    o->a = 0;
    o->c = 0;
    o->vt = &D_003637e0;
    o->b = 0;
    o->d = 0;
    o->e = 0;
    C4* c = &o->col;
    s32 v = 128;
    c->r = v;
    c->g = v;
    c->b = v;
    c->a = v;
    o->f = 0;
}
}  // namespace n002edf28

// 002edf68 (was src/anon/auto200_999.cpp)
namespace n002edf68 {
// C1 twin of the constructor at 0x2edf28 (same body)
extern u8 D_003637e0 asm("D_003637e0");
struct C4 { u8 r, g, b, a; };
struct O2ed { void* vt; u32 a, b, c, d, e; C4 col; u32 f; };
void func_002edf68(O2ed* o) asm("_Z13func_002edf68j");
void func_002edf68(O2ed* o) {
    o->a = 0;
    o->c = 0;
    o->vt = &D_003637e0;
    o->b = 0;
    o->d = 0;
    o->e = 0;
    C4* c = &o->col;
    s32 v = 128;
    c->r = v;
    c->g = v;
    c->b = v;
    c->a = v;
    o->f = 0;
}
}  // namespace n002edf68

// 002edfa8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002edfa8 {
/*TARGET 002edfa8*/
void func_002edfa8(u32* a0, u32 a1) asm("_Z13func_002edfa8Pjj");
void func_002edfa8(u32* a0, u32 a1) {
    u32* t7 = (u32*)((u8*)a0 + 8);
    u32 t6 = t7[1];
    if (t6 == 0) {
        t7[1] = a1;
        a0[2] = a1;
        *(u32*)(a1 + 32) = 0;
        goto L_c4;
    }
    *(u32*)(t6 + 32) = a1;
    *(u32*)(a1 + 32) = 0;
    t7[1] = a1;
L_c4:
    *(u32*)(a1 + 28) = (u32)a0;
}
}  // namespace n002edfa8

// 002edfd8 (was src/anon/auto80_199_queue.cpp)
namespace n002edfd8 {
/*TARGET 002edfd8*/
void func_002edfd8(u32 a0, u32 a1) asm("_Z13func_002edfd8jj");
void func_002edfd8(u32 a0, u32 a1) {  // list_unlink_and_clear
    u32 t7 = *(u32*)(a0 + 8);
    u32 t5;
    u32 t4 = a0 + 8;

    if (a1 == t7) {
        t7 = *(u32*)(a1 + 32);
        t5 = 0;
        *(u32*)(a0 + 8) = t7;
    } else {
        u32 t6 = *(u32*)(t7 + 32);
        t5 = t7;
        while (t6 != a1) {
            t7 = *(u32*)(t6 + 32);
            t5 = t6;
            t6 = t7;
        }
        t7 = *(u32*)(a1 + 32);
        *(u32*)(t5 + 32) = t7;
    }

    t7 = *(u32*)(t4 + 4);
    if (a1 == t7) {
        *(u32*)(t4 + 4) = t5;
    }
    *(u32*)(a1 + 32) = 0;
    *(u32*)(a1 + 28) = 0;
}
}  // namespace n002edfd8

// 002ee040 (was src/anon/batch_w37.cpp)
namespace n002ee040 {
// 0x002d25f0: definition moved into src/anon/unit_002d2498.cpp

typedef s32 (*VFnB)(void*);
/*TARGET 002ee040*/
s32 func_002ee040(u8* p) asm("func_002ee040");
s32 func_002ee040(u8* p) {
    if (!(*(VFnB*)(*(u8**)p + 8))(p)) return 0;
    u8* c = *(u8**)(p + 8);
    s32 r = 1;
    while (c) {
        u8* next = *(u8**)(c + 32);
        s32 t = func_002ee040(c) != 0;
        if (!r) t = 0;
        r = t;
        c = next;
    }
    return r;
}
}  // namespace n002ee040

// 002ee0b0 (was src/anon/batch_w1894_nsa.cpp)
namespace n002ee0b0 {
struct Pos2ee0 { s32 x, y; };
struct Col2ee0 { u8 r, g, b, a; };
static inline __attribute__((always_inline)) void Mul2ee0(Col2ee0& d, const Col2ee0& s) {
    d.r = d.r * s.r >> 7;
    d.g = d.g * s.g >> 7;
    d.b = d.b * s.b >> 7;
    d.a = d.a * s.a >> 7;
}
struct Node2ee0 {
    virtual void f0(); virtual void f1(); virtual void f2();
    virtual void drawSelf(Pos2ee0, Col2ee0, s32);
    virtual void draw(Pos2ee0, Col2ee0);
    u32 flags; Node2ee0* child; u8 pad[4]; s32 x, y; Col2ee0 col; u8 pad2[4]; Node2ee0* next;
};
/*TARGET 002ee0b0*/
/* Needs -fno-strict-aliasing for the colour byte stores and flag test order. */
void func_002ee0b0(Node2ee0* n, Pos2ee0 pos, Col2ee0 col) asm("func_002ee0b0");
/* Needs -fno-strict-aliasing for the colour byte stores and flag test order. */
void func_002ee0b0(Node2ee0* n, Pos2ee0 pos, Col2ee0 col)
{
    s32 hide = 0;
    pos.x += n->x;
    pos.y += n->y;
    Mul2ee0(col, n->col);
    s32 f0 = n->flags & 1;
    if (f0 || (n->flags & 2)) hide = 1;
    if (!(u8)hide) n->drawSelf(pos, col, hide);
    if (!(n->flags & 2)) {
        Node2ee0* c = n->child;
        while (c) {
            Node2ee0* nx = c->next;
            c->draw(pos, col);
            c = nx;
        }
    }
}
}  // namespace n002ee0b0

// 002ee220 (was src/anon/batch_wcx.cpp)
namespace n002ee220 {
typedef void (*VFn)(u8*);
// 0x002d4aa0: definition moved into src/anon/unit_002d4548.cpp
struct HT { u8* head; u8* tail; };
extern HT D_01e2c080 asm("D_01e2c080");
extern u8 D_00363808[] asm("D_00363808");
extern u32 D_003637f8 asm("D_003637f8");
void func_002edf28(u8*) asm("func_002edf28");
// obj_ctor_3637e0
u8* func_002ee840(void) asm("func_002ee840");
// get_data_1e2c088
void func_002ee498(void) asm("func_002ee498");
u32 func_00102788(u32, s32, s32, void (*)(void)) asm("func_00102788");
/*TARGET 002ee220*/
void menu__Window__Window(u8* p) asm("menu__Window__Window");
void menu__Window__Window(u8* p)
{
    func_002edf28(p);  // obj_ctor_3637e0
    *(u32*)p = (u32)D_00363808;
    if (!D_003637f8) {
        u8* o = func_002ee840();  // get_data_1e2c088
        (**(VFn**)o)(o);
        D_003637f8 = func_00102788(*(u32*)(o + 4), 0, 2000, func_002ee498);
    }
    if (!D_01e2c080.head) {
        D_01e2c080.tail = p;
        D_01e2c080.head = p;
        *(u8**)(p + 32) = 0;
    } else {
        *(u8**)(p + 32) = D_01e2c080.head;
        D_01e2c080.head = p;
    }
}
}  // namespace n002ee220

// 002ee2d0 (was gap)
namespace n002ee2d0 {
typedef void (*VFn)(u8*);
// 0x002d4aa0: definition moved into src/anon/unit_002d4548.cpp
struct HT { u8* head; u8* tail; };
extern HT D_01e2c080 asm("D_01e2c080");
extern u8 D_00363808[] asm("D_00363808");
extern u32 D_003637f8 asm("D_003637f8");
void func_002edf28(u8*) asm("func_002edf28");
// obj_ctor_3637e0
u8* func_002ee840(void) asm("func_002ee840");
// get_data_1e2c088
void func_002ee498(void) asm("func_002ee498");
u32 func_00102788(u32, s32, s32, void (*)(void)) asm("func_00102788");
// twin of 0x2ee220
void gap_002ee2d0(u8* p) asm("gap_002ee2d0");
void gap_002ee2d0(u8* p)
{
    func_002edf28(p);  // obj_ctor_3637e0
    *(u32*)p = (u32)D_00363808;
    if (!D_003637f8) {
        u8* o = func_002ee840();  // get_data_1e2c088
        (**(VFn**)o)(o);
        D_003637f8 = func_00102788(*(u32*)(o + 4), 0, 2000, func_002ee498);
    }
    if (!D_01e2c080.head) {
        D_01e2c080.tail = p;
        D_01e2c080.head = p;
        *(u8**)(p + 32) = 0;
    } else {
        *(u8**)(p + 32) = D_01e2c080.head;
        D_01e2c080.head = p;
    }
}
}  // namespace n002ee2d0

// 002ee380 (was src/anon/batch_w1767.cpp)
namespace n002ee380 {
typedef struct W1767Node { void* vt; u8 pad[0x1c]; struct W1767Node* next; } W1767Node;
typedef struct W1767List { W1767Node* head; W1767Node* tail; } W1767List;
extern W1767List D_01e2c080 asm("D_01e2c080");
extern u8 D_00363808[] asm("D_00363808");
extern u8 D_003637e0[] asm("D_003637e0");
/*TARGET 002ee380*/
// 0x001c3b20: definition moved into src/anon/unit_001c2b58.cpp

void func_002ee380(W1767Node* n) asm("func_002ee380");
// 0x001c3b20: definition moved into src/anon/unit_001c2b58.cpp

void func_002ee380(W1767Node* n) {
    W1767Node* prev;
    W1767Node* c;
    n->vt = D_00363808;
    c = D_01e2c080.head;
    if (n == c) {
        D_01e2c080.head = n->next;
        prev = 0;
    } else {
        prev = c;
        while (prev->next != n) prev = prev->next;
        prev->next = n->next;
    }
    if (n == D_01e2c080.tail) D_01e2c080.tail = prev;
    n->next = 0;
    n->vt = D_003637e0;
}
}  // namespace n002ee380

// 002ee400 (was gap)
namespace n002ee400 {
// destructor twin of 0x2ee448 without the base destructor call
extern u8 D_01e2c080[] asm("D_01e2c080");
extern u8 D_00363808[] asm("D_00363808");
extern u8 D_003637e0[] asm("D_003637e0");
void func_00325840(void*, void*) asm("func_00325840");
void gap_002ee400(void** p) asm("gap_002ee400");
void gap_002ee400(void** p) {
    *(u32*)p = (u32)D_00363808;
    func_00325840(D_01e2c080, p);
    *p = D_003637e0;
}
}  // namespace n002ee400

// 002ee448 (was src/anon/batch_w54.cpp)
namespace n002ee448 {
extern u8 D_01e2c080[] asm("D_01e2c080");
extern u8 D_00363808[] asm("D_00363808");
extern u8 D_003637e0[] asm("D_003637e0");
void func_00325840(void*, void*) asm("func_00325840");
void func_00106420(void*) asm("func_00106420");
/*TARGET 002ee448*/
// destructor: unregister from the list at D_01e2c080, then the base destructor
void func_002ee448(void** p) asm("func_002ee448");
// destructor: unregister from the list at D_01e2c080, then the base destructor
void func_002ee448(void** p) {
    *(u32*)p = (u32)D_00363808;
    func_00325840(D_01e2c080, p);
    *p = D_003637e0;
    func_00106420(p);
}
}  // namespace n002ee448

// 002ee498 (was an unwritten gap)
namespace n002ee0b0 {
// per-frame task (registered by 0x2ee220): draw the widget tree, or stop when it is empty
struct List498 { Node2ee0* head; Node2ee0* tail; };
extern List498 D_01e2c080_498 asm("D_01e2c080");
extern u32 D_003637f8_498 asm("D_003637f8");
void func_001024a8_498(void*) asm("func_001024a8");
u8* func_002ee840_498() asm("func_002ee840");
s32 func_002ee040_498(Node2ee0*) asm("func_002ee040");
void gap_002ee498(void* task) asm("gap_002ee498");
void gap_002ee498(void* task) {
    Node2ee0* h = D_01e2c080_498.head;
    if (!h) {
        func_001024a8_498(task);
        *(u32*)(func_002ee840_498() + 28) = 3;
        D_003637f8_498 = 0;
        return;
    }
    if (func_002ee040_498(h)) {
        Pos2ee0 pos;
        Col2ee0 col;
        s32 v = 128;
        pos.x = 0;
        pos.y = 0;
        col.r = v;
        col.g = v;
        col.b = v;
        col.a = v;
        typedef void (*DrawFn)(Node2ee0*, u64, u64);
        ((DrawFn)(*(void***)h)[4])(h, *(u64*)&pos, *(u32*)&col);
    }
}
}  // namespace n002ee0b0

// 002ee530 (was src/anon/tiny.cpp)
namespace n002ee530 {
extern u32 D_003637f8 asm("D_003637f8");
/*TARGET 002ee530*/
// 0x002e10c0: definition moved into src/anon/unit_002de3c8.cpp

// 002e2920: moved to src/anon/unit_002e1908.cpp

// 002e2930: moved to src/anon/unit_002e1908.cpp

u32 func_002ee530(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ee530jjjj");
// 0x002e10c0: definition moved into src/anon/unit_002de3c8.cpp

// 002e2920: moved to src/anon/unit_002e1908.cpp

// 002e2930: moved to src/anon/unit_002e1908.cpp

u32 func_002ee530(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (D_003637f8 != 0);
}
}  // namespace n002ee530

// 002ee540 (was src/anon/batch_w1669.cpp)
namespace n002ee540 {
struct W1669Pair { u32 a, b; };
extern W1669Pair D_01e2c080 asm("D_01e2c080");
void wtarget_002ee540(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002ee540jjjj");
/*TARGET 002ee540*/
void wtarget_002ee540(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002ee540jjjj");
void wtarget_002ee540(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) { D_01e2c080.b = 0; D_01e2c080.a = 0; }
}
}  // namespace n002ee540

// 002ee568 (was src/anon/tiny_wrappers_more.cpp)
namespace n002ee568 {
u32 func_002ee540(u32, u32, u32, u32) asm("_Z13func_002ee540jjjj");
/*TARGET 002ee568*/
// 002ead78: moved to src/anon/unit_002eaa68.cpp

// 002eaf18: _GLOBAL__I_ stub, now made by gcc in src/anon/unit_002eae08.cpp

// 002ebc00: moved to src/anon/unit_002eaf38.cpp

// 002ec138: moved to src/anon/unit_002eaf38.cpp

// 002ec560: moved to src/anon/unit_002eaf38.cpp

// 002ecaa8: moved to src/anon/unit_002ec5f8.cpp

// 002ecd58: moved to src/anon/unit_002ec5f8.cpp

u32 func_002ee568(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ee568jjjj");
// 002ead78: moved to src/anon/unit_002eaa68.cpp

// 002eaf18: _GLOBAL__I_ stub, now made by gcc in src/anon/unit_002eae08.cpp

// 002ebc00: moved to src/anon/unit_002eaf38.cpp

// 002ec138: moved to src/anon/unit_002eaf38.cpp

// 002ec560: moved to src/anon/unit_002eaf38.cpp

// 002ecaa8: moved to src/anon/unit_002ec5f8.cpp

// 002ecd58: moved to src/anon/unit_002ec5f8.cpp

u32 func_002ee568(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002ee540(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n002ee568

