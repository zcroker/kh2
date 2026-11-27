// Linked unit: Ti::MGHachimitsu minigame (honey hunt: gophers, balloons, player). Built from the old per-function sources;
// functions marked "gap function" were never written before.
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../taito/mg_hachimitsu.hpp"
#include "../taito/debug.hpp"

// 002d62d0 (was src/anon/batch_w2045.cpp)
namespace n002d62d0 {
struct W2045_V4b { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W2045_Self { u8 pad[2848]; W2045_V4b dir; };
W2045_V4b* YS__OBJ__get_pos(void) asm("YS__OBJ__get_pos");
f32 func_001065a8(f32, f32) asm("func_001065a8");
void func_002d1d30(W2045_V4b*, void*, W2045_V4b*) asm("func_002d1d30");
f32 fabsf(f32) asm("fabsf");
extern void* D_00361f60 asm("D_00361f60");
// VU0 normalize xyz in place
static inline f32 w2045_norm(W2045_V4b* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
/*TARGET 002d62d0*/
// 0x001dd320: definition moved into src/anon/unit_001dd2b8.cpp

// ---- 0x2d62d0 (VU0 normalize asm, lq/sq copy) ----
void Ti__Path__search_near_point_from_pre_point_nocycle(W2045_Self* self) asm("Ti__Path__search_near_point_from_pre_point_nocycle");
// 0x001dd320: definition moved into src/anon/unit_001dd2b8.cpp

// ---- 0x2d62d0 (VU0 normalize asm, lq/sq copy) ----
void Ti__Path__search_near_point_from_pre_point_nocycle(W2045_Self* self) {
    W2045_V4b v;
    W2045_V4b o;
    void* s = D_00361f60;
    W2045_V4b* pv = &v;
    W2045_V4b* src = YS__OBJ__get_pos();
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(pv), "r"(src) : "$8", "memory");
    func_002d1d30(&o, s, pv);
    if ((o.x > 0.8f && self->dir.x > 0.0f) || (o.x < -0.8f && self->dir.x < 0.0f)
        || (o.y > 0.8f && self->dir.y > 0.0f) || (o.y < -0.8f && self->dir.y < 0.0f)) {
        f32 a, b;
        do {
            a = func_001065a8(-1.0f, 1.0f);
            b = func_001065a8(-1.0f, 1.0f);
        } while (fabsf(a) < 0.001f && fabsf(b) < 0.001f);
        if (o.x > 0.7f) a = -fabsf(a);
        if (o.x < -0.7f) a = fabsf(a);
        if (o.y > 0.7f) b = -fabsf(b);
        if (o.y < -0.7f) b = fabsf(b);
        self->dir.x = a;
        self->dir.y = b;
        self->dir.z = 0.0f;
        w2045_norm(&self->dir);
    }
}
}  // namespace n002d62d0

// 002d6518 (was src/anon/batch_w2379.cpp)
namespace n002d6518 {
// ---- 002d6518: when the global owner D_00361f60 exists, reset the object's pose, attach it,
// play its effect and place it at the owner's position.
void func_0017f540(f32, f32, s32, s32) asm("func_0017f540");
s32 YS__OBJ__attach(s32, s32, s32, s32) asm("YS__OBJ__attach");
s32 func_002d1260() asm("func_002d1260");
u8* func_002d1878(s32) asm("func_002d1878");
void func_002e7340(f32, f32, s32, s32, s32, void*) asm("func_002e7340");
void func_002e7568(f32, s32, s32, void*) asm("func_002e7568");
extern s32 D_00361f60 asm("D_00361f60");
extern u8 D_00362380[8] asm("D_00362380");
extern u8 D_00362388[8] asm("D_00362388");
/*TARGET 002d6518*/
void func_002d6518(s32 obj) asm("func_002d6518");
void func_002d6518(s32 obj) {
    s32 fx = obj + 0xb38;
    s32 owner = D_00361f60;
    if (owner != 0) {
        func_0017f540(0.0f, 0.0f, obj + 0x140, 0);
        YS__OBJ__attach(obj, func_002d1260(), 0x43, 0);
        func_002e7568(1.0f, obj, 2, D_00362380);
        u8* p = func_002d1878(owner);
        u8* q = func_002d1878(owner);
        func_002e7340(*(f32*)(p + 0x100), *(f32*)(q + 0x104), fx, obj, 3, D_00362388);
    }
}
}  // namespace n002d6518

// 002d6600 (was src/anon/batch_w270.cpp)
namespace n002d6600 {
struct W270V {
    f32 x, y, z, w;
    W270V& operator=(const W270V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W270V operator-(const W270V& b) const {
        W270V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
static inline f32 w270_vnorm(W270V* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct W270Ys { u8 pad[320]; u8 sub320[2528]; W270V v2848; f32 f2864; f32 f2868; u8 sub2872[4]; };
struct W270Cfg { u8 pad[256]; f32 f256; f32 f260; };
extern void* D_00361f60 asm("D_00361f60");
extern u32 D_0034e948 asm("D_0034e948");
extern u8 D_00362370[] asm("D_00362370");
extern u8 D_00362378[] asm("D_00362378");
// 0x0026db60: definition moved into src/anon/unit_0026c450.cpp
s32 W270_is_attach(W270Ys*) asm("_ZN2YS3OBJ9is_attachEv");
void W270_detach(W270Ys*) asm("_ZN2YS3OBJ6detachEv");
void W270_change_action(W270Ys*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
void W270_ctarget(W270V*, u32) asm("_Z23YS__OBJ__get_target_posjjjj");
void W270_set_pos(W270Ys*, W270V*) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
void W270_set_rot(W270Ys*, f32) asm("_ZN2YS3OBJ7set_rotEf");
void W270_17f488(void*, s32, f32, f32) asm("_Z13func_0017f488iiff");
W270Cfg* W270_config(void*) asm("_ZN2Ti9MGOarashi6configEv");
void func_002e7568(W270Ys*, s32, void*, f32) asm("func_002e7568");
void func_002e7340(void*, W270Ys*, s32, void*, f32, f32) asm("func_002e7340");
/*TARGET 002d6600*/
void func_002d6600(W270Ys* o, W270V* dir) asm("func_002d6600");
void func_002d6600(W270Ys* o, W270V* dir) {
    void* g = D_00361f60;
    if (!W270_is_attach(o)) return;
    W270_detach(o);
    W270_change_action(o, 38);
    W270V t;
    W270_ctarget(&t, D_0034e948);
    t.z = 0.0f;
    W270_set_pos(o, &t);
    W270_set_rot(o, 0.0f);
    W270_17f488(o->sub320, 153, 0.0f, 0.0f);
    o->v2848 = *dir;
    o->v2848.z = 0.0f;
    w270_vnorm(&o->v2848);
    o->f2864 = 0.0f;
    o->f2868 = 0.0f;
    func_002e7568(o, 5, D_00362370, 1.0f);
    W270Cfg* a = W270_config(g);
    W270Cfg* b = W270_config(g);
    func_002e7340(o->sub2872, o, 5, D_00362378, a->f256, b->f260);
}
}  // namespace n002d6600

// 002d6750 (was src/anon/batch_w299.cpp)
namespace n002d6750 {
struct Act2d6;
struct V299 {
    f32 x, y, z, w;
    V299() {}
    V299& operator=(const V299& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    f32 Normalize() {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
static inline V299 operator-(const V299& a, const V299& b) {
    V299 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct Act2d6Vt { void* s[24]; s32 (*f96)(Act2d6*); };
struct Act2d6 { Act2d6Vt* vt; u8 pad[1412]; u32 f1416; u8 pad2[2780 - 1420]; f32 f2780; u8 pad3[2868 - 2784]; f32 f2868; };
struct Ctx2d6 { u8 pad[16]; Act2d6* f16; };
struct Cfg2d6 { u8 pad[140]; f32 f140; u8 pad2[12]; f32 f156; };
struct Mg2d6 { u8 pad[320]; u8 f320; };
// 0x0011b8d0: definition moved into src/anon/unit_0011b3f8.cpp

extern Mg2d6* D_00361f60 asm("D_00361f60");
Cfg2d6* config2d6(Mg2d6*) asm("_ZN2Ti9MGOarashi6configEv");
s32 is_attach2d6(Act2d6*) asm("_ZN2YS3OBJ9is_attachEv");
V299 getpos2d6(Act2d6*) asm("_Z23YS__OBJ__get_target_posjjjj");
void setdir2d6(Act2d6*, V299*, f32) asm("_Z23YS__BTLOBJ__set_hitbackjjjj");
void wt2cf280(void*, s32, s32) asm("_Z16wtarget_002cf280jjjj");
void func_002d6600(Act2d6*, V299*) asm("func_002d6600");
void Ti__MGOarashiGimObj__force_destroy(Act2d6*) asm("Ti__MGOarashiGimObj__force_destroy");
f32 fabsf(f32) asm("fabsf");
// fabsf
static inline u8 pos2d6(Act2d6* t) { return 0.0f < t->f2780; }
/*TARGET 002d6750*/
void func_002d6750(Act2d6* a, Ctx2d6* c) asm("func_002d6750");
void func_002d6750(Act2d6* a, Ctx2d6* c) {
    Mg2d6* g = D_00361f60;
    Cfg2d6* cf = config2d6(g);
    if (is_attach2d6(a)) return;
    if (cf->f156 > a->f2868) return;
    if (a->vt->f96(a)) return;
    Act2d6* t = c->f16;
    if (!t) return;
    if ((t->f1416 & 0x8000000) && pos2d6(t)) return;
    if (!t) return;
    V299 d = getpos2d6(a) - getpos2d6(c->f16);
    d.z = 0;
    f32 len = d.Normalize();
    if (len < 0.01f) {
        d.y = d.z = 0.0f;
        d.x = 1.0f;
    }
    g->f320 = 1;
    if (is_attach2d6(a)) {
        func_002d6600(a, &d);
    } else {
        if (config2d6(g)->f140 < 0.0f) d.Zero();
        setdir2d6(a, &d, fabsf(config2d6(g)->f140));  // fabsf
    }
    wt2cf280((u8*)c->f16 + 2800, 256, 0);
    Ti__MGOarashiGimObj__force_destroy(c->f16);
}
}  // namespace n002d6750

// 002d6948 (was never written: gap function)
namespace n002d6948 {
u32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_002d6948(u8* p, u8* o) asm("func_002d6948");
void func_002d6948(u8* p, u8* o)
{
    if (!func_001c0cd8(p)) *(f32*)(o + 56) -= 50.0f;
}
}  // namespace n002d6948

// 002d6990 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n002d6990 {
u32 func_002cfeb0(u32, u32, u32, u32) asm("_Z13func_002cfeb0jjjj");
extern u8 D_00362398 asm("D_00362398");
/*TARGET 002d6990*/
// 002cea68: moved to src/taito/minigame_base.cpp (linked unit)

u32 func_002d6990(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d6990jjjj");
// 002cea68: moved to src/taito/minigame_base.cpp (linked unit)

u32 func_002d6990(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r7 = r6;
    r6 = (u32)((s32)0u + (1));
    r16 = r4;
    r2 = func_002cfeb0(r4, r5, r6, r7);  // obj_init_field1416_bit800
    r15 = (u32)&D_00362398;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n002d6990

// 002d69c8 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n002d69c8 {
u32 func_002cfeb0(u32, u32, u32, u32) asm("_Z13func_002cfeb0jjjj");
extern u8 D_00362398 asm("D_00362398");
/*TARGET 002d69c8*/
u32 func_002d69c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d69c8jjjj");
u32 func_002d69c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r7 = r6;
    r6 = (u32)((s32)0u + (1));
    r16 = r4;
    r2 = func_002cfeb0(r4, r5, r6, r7);  // obj_init_field1416_bit800
    r15 = (u32)&D_00362398;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n002d69c8

// 002d6a00 (was src/anon/batch_w8024.cpp)
namespace n002d6a00 {
struct V4_w8024 { f32 x, y, z, w; V4_w8024(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {} };
void func_0016ace0(s32, V4_w8024*) asm("func_0016ace0");
void func_0016b070(s32, V4_w8024*) asm("func_0016b070");
void func_0016bd60(s32, s32) asm("func_0016bd60");
s32 YS__OBJ__attach(s32, s32, s32, s32) asm("YS__OBJ__attach");
void func_002d00a0(s32) asm("func_002d00a0");
s32 func_002d1260() asm("func_002d1260");
/*TARGET 002d6a00*/
// 0x002cf320: definition moved into src/anon/unit_002cf260.cpp

void func_002d6a00(s32 a0) asm("func_002d6a00");
// 0x002cf320: definition moved into src/anon/unit_002cf260.cpp

void func_002d6a00(s32 a0)
{
    func_002d00a0(a0);
    func_0016bd60(a0, 3);
    YS__OBJ__attach(a0, func_002d1260(), 0x55, 0);
    V4_w8024 r(-1.57079625f, -1.57079625f, 0.0f, 0.0f);
    func_0016b070(a0, &r);
    V4_w8024 t(0.0f, 0.0f, 0.0f, 0.0f);
    func_0016ace0(a0, &t);
}
}  // namespace n002d6a00

// 002d6aa0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002d6aa0 {
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
extern u8 D_00362398 asm("D_00362398");
/*TARGET 002d6aa0*/
u32 func_002d6aa0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d6aa0jjjj");
u32 func_002d6aa0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00362398;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002cff98)(u32, u32, u32, u32) = func_002cff98;
    r2 = fp_call4_002cff98(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002d6aa0

// 002d6ac8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002d6ac8 {
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
extern u8 D_00362398 asm("D_00362398");
/*TARGET 002d6ac8*/
u32 func_002d6ac8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d6ac8jjjj");
u32 func_002d6ac8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00362398;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002cff98)(u32, u32, u32, u32) = func_002cff98;
    r2 = fp_call4_002cff98(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002d6ac8

// 002d6af0 (was src/anon/batch_w20.cpp)
namespace n002d6af0 {
void func_00105110(void*) asm("func_00105110");
u8 func_002cff98(void*) asm("func_002cff98");
extern void* D_00362398[] asm("D_00362398");
/*TARGET 002d6af0*/
void func_002d6af0(void** p) asm("func_002d6af0");
void func_002d6af0(void** p) {
    *p = D_00362398;
    func_002cff98(p);
    func_00105110(p);
}
}  // namespace n002d6af0

// 002d6b28 (was never written: gap function)
namespace n002d6b28 {
void func_002d6b28(u8* o) asm("func_002d6b28");
void func_002d6b28(u8* o) { *(u32*)(o + 12) = 0; }
}  // namespace n002d6b28

// 002d6b30 (was src/anon/batch_w110.cpp)
namespace n002d6b30 {
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
struct CamP { f32 f0, f4, f8, f12, f16, f20, f24; };
struct CamIn { u8 pad[12]; f32 f12; };
extern void* D_00361f60 asm("D_00361f60");
extern f32 D_00349e10 asm("D_00349e10");
s32 func_002d5cc8(void*) asm("func_002d5cc8");
CamP* func_002d1878(void*) asm("func_002d1878");
QV func_002d4f60(void*) asm("func_002d4f60");
QV func_002d2740(void*, void*, f32, f32) asm("func_002d2740");
/*TARGET 002d6b30*/
// Camera target: clamps the follow distance, refreshes the target vector and returns it scaled.
QV Ti__ACTION_PO_OARASHI__calc_movement(CamIn* in, u8* o) asm("Ti__ACTION_PO_OARASHI__calc_movement");
// Camera target: clamps the follow distance, refreshes the target vector and returns it scaled.
QV Ti__ACTION_PO_OARASHI__calc_movement(CamIn* in, u8* o) {
    void* w = D_00361f60;
    QV r;
    if (func_002d5cc8(o)) {
        CamP* a = func_002d1878(w);
        CamP* b = func_002d1878(w);
        CamP* c = func_002d1878(w);
        f32 d = a->f16 - b->f20 * in->f12;
        if (d < c->f24) d = c->f24;
        QV* v16 = (QV*)(o + 16);
        *v16 = func_002d4f60(o);
        *(f32*)(o + 28) = d;
        r = *v16;
        ScaleQIn(&r, r.w * D_00349e10);
        in->f12 += D_00349e10;
        *(QV*)(o + 32) = ScaleQ(*v16, *(f32*)(o + 28));
    } else {
        CamP* a = func_002d1878(w);
        CamP* b = func_002d1878(w);
        r = func_002d2740(w, o, a->f8, b->f12);
        in->f12 = 0.0f;
    }
    r.z = 0.0f;
    r.w = 1.0f;
    return r;
}
}  // namespace n002d6b30

// 002d6cd0 (was never written: gap function)
namespace n002d6cd0 {
void func_002d6cd0(void) asm("func_002d6cd0");
void func_002d6cd0(void) {}
}  // namespace n002d6cd0

// 002d6cd8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002d6cd8 {
u32 func_002d1878(...) asm("func_002d1878");
/*TARGET 002d6cd8*/
void func_002d6cd8(u32 a0) asm("_Z13func_002d6cd8j");
void func_002d6cd8(u32 a0) {
    u32* base = (u32*)0x00360000;
    u32 p = func_002d1878(*(u32*)((u8*)base + 0x1f60));
    *(f32*)(a0 + 12) = *(f32*)(p + 172);
}
}  // namespace n002d6cd8

// 002d6d10 (was src/anon/batch_w42.cpp)
namespace n002d6d10 {
u8* oarashi_config(void*) asm("_ZN2Ti9MGOarashi6configEv");
// 0x002c1860: definition moved into src/anon/unit_002c10e0.cpp

// 002d6d10
extern void* D_00361f60 asm("D_00361f60");
void func_002d2740(void*, void*, u32, f32, f32) asm("func_002d2740");
/*TARGET 002d6d10*/
void* Ti__ACTION_PO_OARASHI_TORNADO_S__calc_movement(void* ret, u32, u32 a2) asm("Ti__ACTION_PO_OARASHI_TORNADO_S__calc_movement");
void* Ti__ACTION_PO_OARASHI_TORNADO_S__calc_movement(void* ret, u32, u32 a2)
{
    void* c = D_00361f60;
    u8* x = oarashi_config(c);
    u8* y = oarashi_config(c);
    func_002d2740(ret, c, a2, *(f32*)(x + 208), *(f32*)(y + 212));
    return ret;
}
}  // namespace n002d6d10

// 002d6d88 (was src/anon/tiny_auto80_queue.cpp)
namespace n002d6d88 {
void Ti__MGOarashiPlayer__stop_tornado_attack(...) asm("Ti__MGOarashiPlayer__stop_tornado_attack");
// 0x0018c458: definition moved into src/yasui/libys/npc.cpp

extern f32 D_00349e10 asm("D_00349e10");
/*TARGET 002d6d88*/
void func_002d6d88(u32 a0, u32 a1) asm("_Z13func_002d6d88jj");
void func_002d6d88(u32 a0, u32 a1) {
    f32 zero = 0.0f;
    f32 dec = D_00349e10;
    u32 self = a0;
    f32 v = *(f32*)(a0 + 12) - dec;
    *(f32*)(self + 12) = v;
    if (v <= zero) {
        Ti__MGOarashiPlayer__stop_tornado_attack(a1);
    }
}
}  // namespace n002d6d88

// 002d6dd0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002d6dd0 {
u32 func_002d1878(...) asm("func_002d1878");
/*TARGET 002d6dd0*/
void func_002d6dd0(u32 a0) asm("_Z13func_002d6dd0j");
void func_002d6dd0(u32 a0) {
    u32* base = (u32*)0x00360000;
    u32 p = func_002d1878(*(u32*)((u8*)base + 0x1f60));
    *(f32*)(a0 + 12) = *(f32*)(p + 176);
}
}  // namespace n002d6dd0

// 002d6e08 (was src/anon/batch_w24.cpp)
namespace n002d6e08 {
// 0x002c14a8: definition moved into src/anon/unit_002c10e0.cpp

// Clear the vector at q+32, then scale p.xyzw by p.w and zero p.z.
void func_002d5c20(f32*, u8*) asm("func_002d5c20");
/*TARGET 002d6e08*/
f32* func_002d6e08(f32* p, u32, u8* q) asm("func_002d6e08");
f32* func_002d6e08(f32* p, u32, u8* q) {
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(q + 32) : "memory");
    func_002d5c20(p, q);
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(p), "f"(p[3]) : "$8", "memory");
    p[2] = 0;
    return p;
}
}  // namespace n002d6e08

// 002d6e60 (was src/anon/tiny_auto80_queue.cpp)
namespace n002d6e60 {
void Ti__MGOarashiPlayer__stop_tornado_attack(...) asm("Ti__MGOarashiPlayer__stop_tornado_attack");
// 0x0018c458: definition moved into src/yasui/libys/npc.cpp

extern f32 D_00349e10 asm("D_00349e10");
/*TARGET 002d6e60*/
void func_002d6e60(u32 a0, u32 a1) asm("_Z13func_002d6e60jj");
void func_002d6e60(u32 a0, u32 a1) {
    f32 zero = 0.0f;
    f32 dec = D_00349e10;
    u32 self = a0;
    f32 v = *(f32*)(a0 + 12) - dec;
    *(f32*)(self + 12) = v;
    if (v <= zero) {
        Ti__MGOarashiPlayer__stop_tornado_attack(a1);
    }
}
}  // namespace n002d6e60

// 002d6ea8 (was never written: gap function)
namespace n002d6ea8 {
struct V { f32 x, y, z, w; void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); } } __attribute__((aligned(16)));
void func_002d6ea8(u8* p, u8* o) asm("func_002d6ea8");
void func_002d6ea8(u8* p, u8* o) { ((V*)(o + 32))->Zero(); }
void func_002d6ec0(void) asm("func_002d6ec0");
void func_002d6ec0(void) {}
}  // namespace n002d6ea8

// 002d6ec8 (was src/anon/batch_w45.cpp)
namespace n002d6ec8 {
void kn__MotionPrototype0__calcLimitValue(void*, u32, f32, f32) asm("kn__MotionPrototype0__calcLimitValue");
/*TARGET 002d6ec8*/
// 0x002c2688: definition moved into src/anon/unit_002c2228.cpp

u8* func_002d6ec8(u8* out, u32 a1, u32 a2) asm("func_002d6ec8");
// 0x002c2688: definition moved into src/anon/unit_002c2228.cpp

u8* func_002d6ec8(u8* out, u32 a1, u32 a2) {
    u8 tmp[16] __attribute__((aligned(16)));
    kn__MotionPrototype0__calcLimitValue(tmp, a2, 0.8f, 0.0f);
    if (out != tmp) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(out), "r"(tmp) : "$8", "memory");
    *(f32*)(out + 8) = 0.0f;
    return out;
}
}  // namespace n002d6ec8

// 002d6f28 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002d6f28 {
u32 func_001050d8(u32, u32, u32, u32) asm("_Z13func_001050d8jjjj");
u32 Ti__MGHachimitsu__MGHachimitsu(u32, u32, u32, u32) asm("_Z30Ti__MGHachimitsu__MGHachimitsujjjj");
/*TARGET 002d6f28*/
u32 func_002d6f28(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d6f28jjjj");
u32 func_002d6f28(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r16, r17;
    r16 = r4;
    r17 = r5;
    r4 = (u32)((s32)0u + (496));
    u32 (*fp_call4_001050d8)(u32, u32, u32, u32) = func_001050d8;
    r2 = fp_call4_001050d8(r4, r5, r6, r7);
    r5 = r16;
    r6 = r17;
    r4 = r2;
    r7 = 0u;
    return Ti__MGHachimitsu__MGHachimitsu(r4, r5, r6, r7);
}
}  // namespace n002d6f28

