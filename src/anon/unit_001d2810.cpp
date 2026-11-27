#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../yasui/libys/sora.hpp"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// ---- 001d2810 from src/anon/tiny_jal_wrappers_reloc.cpp
namespace n001d2810 {
u32 func_001a4db0(u32, u32, u32, u32) asm("_Z13func_001a4db0jjjj");
extern u8 D_00352678 asm("D_00352678");
u32 func_001d2810(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d2810jjjj");
u32 func_001d2810(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r6 = (u32)((s32)0u + (100));
    r7 = (u32)((s32)0u + (96));
    r16 = r4;
    r2 = func_001a4db0(r4, r5, r6, r7);
    r15 = (u32)&D_00352678;
    r14 = (u32)(0x0035u << 16);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r14 + (s32)(9832)) = r16;
    return r2;
}
}  // namespace n001d2810

// ---- 001d2850 from src/anon/tiny_jal_wrappers_reloc.cpp
namespace n001d2850 {
u32 func_001a4db0(u32, u32, u32, u32) asm("_Z13func_001a4db0jjjj");
extern u8 D_00352678 asm("D_00352678");
u32 func_001d2850(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d2850jjjj");
u32 func_001d2850(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r6 = (u32)((s32)0u + (100));
    r7 = (u32)((s32)0u + (96));
    r16 = r4;
    r2 = func_001a4db0(r4, r5, r6, r7);
    r15 = (u32)&D_00352678;
    r14 = (u32)(0x0035u << 16);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r14 + (s32)(9832)) = r16;
    return r2;
}
}  // namespace n001d2850

// ---- 001d2890 from src/anon/tiny_auto80_fptr4.cpp
namespace n001d2890 {
u32 func_001a4e30(u32, u32, u32, u32) asm("_Z13func_001a4e30jjjj");
extern u8 D_00352678 asm("D_00352678");
u32 func_001d2890(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d2890jjjj");
u32 func_001d2890(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14;
    r14 = (u32)&D_00352678;
    *(u32*)((u32)r4 + (s32)(0)) = r14;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r13 + (s32)(9832)) = 0u;
    u32 (*fp_call4_001a4e30)(u32, u32, u32, u32) = func_001a4e30;
    r2 = fp_call4_001a4e30(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001d2890

// ---- 001d28c0 from src/anon/tiny_auto80_fptr4.cpp
namespace n001d28c0 {
u32 func_001a4e30(u32, u32, u32, u32) asm("_Z13func_001a4e30jjjj");
extern u8 D_00352678 asm("D_00352678");
u32 func_001d28c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d28c0jjjj");
u32 func_001d28c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14;
    r14 = (u32)&D_00352678;
    *(u32*)((u32)r4 + (s32)(0)) = r14;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r13 + (s32)(9832)) = 0u;
    u32 (*fp_call4_001a4e30)(u32, u32, u32, u32) = func_001a4e30;
    r2 = fp_call4_001a4e30(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001d28c0

// ---- 001d28f0 from src/anon/batch_w18.cpp
namespace n001d28f0 {
void func_00105110(void*) asm("func_00105110");
extern void* D_00352678 asm("D_00352678");
extern void* D_00352668 asm("D_00352668");
void func_001a4e30(void*) asm("func_001a4e30");
void func_001d28f0(void** p) asm("func_001d28f0");
void func_001d28f0(void** p) {
    *p = &D_00352678;
    D_00352668 = 0;
    func_001a4e30(p);
    func_00105110(p);
}
}  // namespace n001d28f0

// ---- 001d2930 from src/anon/batch_w38.cpp
namespace n001d2930 {
extern void* D_00352668 asm("D_00352668");
extern const f32 D_0036e3d0_x asm("D_0036e3d0");
void func_001a5420(void*, const void*, void*) asm("func_001a5420");
void func_001d2930(void* a, s32 n) asm("func_001d2930");
void func_001d2930(void* a, s32 n) {
    if (D_00352668) {
        for (s32 i = 0; i < n; i++) func_001a5420(D_00352668, &D_0036e3d0_x, a);
    }
}
}  // namespace n001d2930

// ---- 001d29a0 from src/anon/batch_wcx2.cpp
namespace n001d29a0 {
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
void func_00134668(void* p) asm("func_00134668");
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));
void func_001a5990(u8*, f32, s32) asm("func_001a5990");
void func_001d29a0(u8* a, u8* b) asm("func_001d29a0");
void func_001d29a0(u8* a, u8* b) {
    func_001a5990(b, 1.0f, 0);
}
}  // namespace n001d29a0

// parameter block read by 0x1d2930
// an unused zero word, then the block
extern "C++" const s32 R_0036e3cc asm("D_0036e3cc") = 0;
// four words (0.0f, 31.0f, 41, 42); one 16-byte object would get 8-byte alignment and pad the section
extern "C++" const f32 R_0036e3d0 asm("D_0036e3d0") = 0.0f;
extern "C++" const f32 R_0036e3d4 asm("D_0036e3d4") = 31.0f;
extern "C++" const s32 R_0036e3d8 asm("D_0036e3d8") = 41;
extern "C++" const s32 R_0036e3dc asm("D_0036e3dc") = 42;

// ---- 001d29c8 from src/anon/batch_w60.cpp
namespace n001d29c8 {
extern u8* D_00352668 asm("D_00352668");
u8* func_001c16f0(void*, void*) asm("func_001c16f0");
void YS__PRIZEEFFECT__get(void*, void*, s32) asm("YS__PRIZEEFFECT__get");
void PrizeTrGetAll(void* o) asm("_ZN2YS8PRIZE_TR6GetAllEPNS_6BTLOBJE");
void PrizeTrGetAll(void* o) {
    if (!D_00352668) return;
    u8* n = 0;
    while ((n = func_001c16f0(*(void**)(D_00352668 + 2548), n))) {
        if (*(s32*)(n + 72) == 0) YS__PRIZEEFFECT__get(n, o, 0);
    }
}
}  // namespace n001d29c8

// ---- 001d2a50 gap (never-written function)
namespace g001d2a50 {
static inline void VZero(void* p) { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p) : "memory"); }
void func_001d2a50(u32, u8* o) asm("func_001d2a50");
void func_001d2a50(u32, u8* o) { VZero(o + 32); }
}  // namespace g001d2a50

// ---- 001d2a68 from src/anon/batch_w95.cpp
#undef QCOPY
namespace n001d2a68 {
static inline void QCOPY(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& s) {
        if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq operator-(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
union FI { f32 f; s32 i; };
static inline Vq operator*(const Vq& a, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
extern f32 D_00349e10 asm("D_00349e10");
f32 func_00184a90(u8*) asm("func_00184a90");
Vq* YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
struct VqI { FI x, y, z, w; } __attribute__((aligned(16)));
Vq YS__ACTION_DEADSORA__calc_movement(u32, u8* o) asm("YS__ACTION_DEADSORA__calc_movement");
Vq YS__ACTION_DEADSORA__calc_movement(u32, u8* o) {
    VqI v;
    QCOPY(&v, o + 2144);
    v.x.i = 0;
    v.z.i = 0;
    f32 z = v.x.f;
    if (v.y.f < z) v.y.f = z;
    f32 h = MAX(z, func_00184a90(o) - YS__OBJ__get_pos(o)->y);
    if (h < 300.0f) {
        v.y.f = (v.y.f - 0.5f) * 0.95f + 0.5f;
    } else {
        v.y.f = MIN(v.y.f + D_00349e10 * 0.2f, 6.0f);
    }
    return *(Vq*)&v * D_00349e10;
}
}  // namespace n001d2a68

// ---- 001d2bb0 gap (never-written function)
namespace g001d2bb0 {
struct QW1d2 { f32 x, y, z, w;
    QW1d2() {}
    QW1d2(const QW1d2& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QW1d2& operator=(const QW1d2& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline QW1d2 operator*(const QW1d2& a, f32 k) {
    QW1d2 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
struct Cfg { u8 p[228]; f32 f228; f32 f232; u8 q[268 - 236]; f32 lo268, hi272, lo276; };
struct Obj1d2 { u8 p0[12]; u8* f12; u8 pp[12]; f32 f28; QW1d2 v32; u8 p1[340 - 48]; s32 f340; u8 rest[2920 - 344]; f32 timer; };
extern Cfg* D_00352130 asm("D_00352130");
QW1d2 v2e68(void*, Obj1d2*) asm("YS__ACTION_LM_DOLPHIN__GetNearVector");
f32 func_001d3000(void*, f32) asm("func_001d3000");
void func_001d2bb0(void* a0, Obj1d2* o) asm("func_001d2bb0");
void func_001d2bb0(void* a0, Obj1d2* o) {
    Cfg* c = D_00352130;
    QW1d2 r = v2e68(a0, o);
    o->v32 = r * func_001d3000(a0, r.w);
    f32 t = r.w * c->lo268;
    f32 x;
    if (t < c->lo276) x = c->lo276; else if (c->hi272 < t) x = c->hi272; else x = t;
    o->timer = x;
}
}  // namespace g001d2bb0

// ---- 001d2c78 from src/anon/batch_w1951_nsa.cpp
namespace n001d2c78 {
struct QW1d2 { f32 x, y, z, w;
    QW1d2() {}
    QW1d2(const QW1d2& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QW1d2& operator=(const QW1d2& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline QW1d2 operator*(const QW1d2& a, f32 k) {
    QW1d2 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline f32 Normalize1d2(QW1d2* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Res1d2 { s32 a, b, c; f32 f; };
struct Cfg1d2 { u8 p[280]; f32 k; };
struct Obj1d2 { u8 p0[32]; QW1d2 v32; u8 p1[320 - 48]; u8 mot[2548 - 320]; u8 tgt[2920 - 2548]; f32 timer; };
static inline __attribute__((always_inline)) void SubL(const QW1d2& a, const QW1d2& b, QW1d2* r) {asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(r), "r"(&a), "r"(&b) : "memory");}
Res1d2 YS__ACTION_LM_DOLPHIN__GetNearVector(void*, Obj1d2*) asm("YS__ACTION_LM_DOLPHIN__GetNearVector");
f32 func_001d3000(void*, f32) asm("func_001d3000");
void func_00183768(Obj1d2*, Res1d2*, f32) asm("func_00183768");
void YS__OBJ__set_wish_dir(Obj1d2*, QW1d2*) asm("YS__OBJ__set_wish_dir");
s32 Tgt1d2_is_exist(void*) asm("_ZNK2YS6TARGET8is_existEv");
QW1d2 func_00190388(void*) asm("func_00190388");
QW1d2 ctarget_0016bda8_1d2(Obj1d2*) asm("_Z23YS__OBJ__get_target_posjjjj");
void f17f488_1d2(void*, s32, f32, f32) asm("_Z13func_0017f488iiff");
void push_1d2(void*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
void chg_1d2(Obj1d2*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
extern Cfg1d2* D_00352130 asm("D_00352130");
extern f32 D_00349e10 asm("D_00349e10");
void YS__ACTION_LM_DOLPHIN__control(void* a0, Obj1d2* o) asm("YS__ACTION_LM_DOLPHIN__control");
void YS__ACTION_LM_DOLPHIN__control(void* a0, Obj1d2* o) {
    Cfg1d2* cfg = D_00352130;
    Res1d2 r = YS__ACTION_LM_DOLPHIN__GetNearVector(a0, o);
    func_00183768(o, &r, func_001d3000(a0, r.f));
    QW1d2 v(o->v32);
    YS__OBJ__set_wish_dir(o, &v);
    o->timer -= D_00349e10;
    if (o->timer <= 0.0f) {
        if (Tgt1d2_is_exist(o->tgt)) {
            SubL(func_00190388(o->tgt), ctarget_0016bda8_1d2(o), &v);
            Normalize1d2(&v);
            o->v32 = v * cfg->k;
        }
        f17f488_1d2(o->mot, 153, 0.0f, 0.0f);
        push_1d2(o->mot, 0, 0.0f, 0.0f, 0);
        chg_1d2(o, 29);
    }
}
}  // namespace n001d2c78

// ---- 001d2e28 from src/anon/tiny_auto80_queue.cpp
namespace n001d2e28 {
extern u8  D_00350000 asm("D_00350000");
void kn__MotionPrototype0__calcLimitValue(u32, u32, f32, f32) asm("_Z36kn__MotionPrototype0__calcLimitValuejjff");
void* func_001d2e28(void* a0, u32 a1, u32 a2) asm("_Z13func_001d2e28Pvjj");
void* func_001d2e28(void* a0, u32 a1, u32 a2) {
    (void)a1;
    u8* t6 = *(u8**)((u8*)&D_00350000 + 8496u);
    f32 f12 = *(f32*)(t6 + 236);
    kn__MotionPrototype0__calcLimitValue(a0, a2, f12, f12);
    return a0;
}
}  // namespace n001d2e28

// ---- 001d2e68 from src/anon/batch_w8009_nsa.cpp
namespace n001d2e68 {
struct V1d2e68 {
    f32 x, y, z, w;
    V1d2e68() {}
    V1d2e68& operator=(const V1d2e68& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline V1d2e68 sub_1d2e68(const V1d2e68& a, const V1d2e68& b) {
    V1d2e68 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 norm_1d2e68(V1d2e68* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct P1d2e68 { u8 p0[256]; f32 f100; f32 f104; f32 f108; };
struct S1d2e68 { f32 a, b, c; s32 d; V1d2e68 pos; u8 pad[16]; };
struct O1d2e68 { u8 p0[2548]; u8 tgt[4]; };
extern u8 D_00352130[] asm("D_00352130");
s32 func_00190140(void*) asm("_ZNK2YS6TARGET8is_existEv");
void YS__TARGET__make_collision(void*, S1d2e68*) asm("YS__TARGET__make_collision");
V1d2e68 YS__OBJ__get_target_pos(O1d2e68*) asm("_Z23YS__OBJ__get_target_posjjjj");
V1d2e68 YS__MATH__VectorRotY(V1d2e68*, f32) asm("YS__MATH__VectorRotY");
V1d2e68 YS__OBJ__get_dir(O1d2e68*) asm("YS__OBJ__get_dir");
V1d2e68 YS__ACTION_LM_DOLPHIN__GetNearVector(void* self, O1d2e68* o) asm("YS__ACTION_LM_DOLPHIN__GetNearVector");
V1d2e68 YS__ACTION_LM_DOLPHIN__GetNearVector(void* self, O1d2e68* o) {
    V1d2e68 r;
    P1d2e68* prm = *(P1d2e68**)D_00352130;
    S1d2e68 s;
    s.d = 0;
    if (func_00190140(o->tgt)) {
        YS__TARGET__make_collision(o->tgt, &s);
        r = sub_1d2e68(s.pos, YS__OBJ__get_target_pos(o));
        f32 d = norm_1d2e68(&r) - s.b;
        if (d < 0.0f) d = 0.0f;
        if (d < prm->f104) {
            f32 t = (d - prm->f104) / (prm->f108 - prm->f104);
            f32 c;
            if (t < 0.0f) c = 0.0f;
            else if (1.0f < t) c = 1.0f;
            else c = t;
            r = YS__MATH__VectorRotY(&r, prm->f100 * c);
        }
        r.w = d;
    } else {
        r = YS__OBJ__get_dir(o);
        *(s32*)&r.w = 0;
    }
    return r;
}
}  // namespace n001d2e68

// ---- 001d3000 from src/anon/batch_w27.cpp
namespace n001d3000 {
struct Lerp1d3000 { u8 pad[240]; f32 hiVal; f32 loVal; f32 hi; f32 lo; };
extern Lerp1d3000* D_00352130 asm("D_00352130");
f32 func_001d3000(f32 x) asm("func_001d3000");
f32 func_001d3000(f32 x) {
    Lerp1d3000* t = D_00352130;
    if (x >= t->hi) return t->hiVal;
    if (x <= t->lo) return t->loVal;
    x -= t->lo;
    f32 r = x / (t->hi - t->lo);
    return t->loVal + (t->hiVal - t->loVal) * r;
}
}  // namespace n001d3000

// ---- 001d3060 from src/anon/batch_wcx2.cpp
namespace n001d3060 {
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
void func_00134668(void* p) asm("func_00134668");
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));
extern f32 D_01d5ba08 asm("D_01d5ba08");
void wtarget_001d3060(u32, u32, u32, u32) asm("_Z16wtarget_001d3060jjjj");
void wtarget_001d3060(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) D_01d5ba08 = 1.57079625f;
}
}  // namespace n001d3060

// ---- 001d3090 from src/anon/tiny_wrappers_more.cpp
namespace n001d3090 {
u32 func_001d3060(u32, u32, u32, u32) asm("_Z13func_001d3060jjjj");
u32 func_001d3090(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d3090jjjj");
u32 func_001d3090(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d3060(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n001d3090

