// Linked unit 0x0010cdd8-0x0010d900 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include <stdarg.h>
#include "../naka/libkn/friend.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../../src/common/types.h"
extern "C" float fabsf(float);
#include "tiny_auto80_solver_structs.hpp"

// 0010cdd8 (was gap, never written)
namespace g0010cdd8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V10ce {
    f32 x, y, z, w;
    V10ce& operator=(const V10ce& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline V10ce operator-(const V10ce& a, const V10ce& b)
{
    V10ce r;
    asm(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Dot10ce(const V10ce& a, const V10ce& b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\t"
                 "vaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
extern u8* D_00341708 asm("D_00341708");
V10ce func_00190388(u8*) asm("func_00190388");
// vec4_from_arg
V10ce* YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
// obj_get_attach_or_alt
f32 func_001142d0(u32) asm("func_001142d0");
// get_float_at_ptr108
f32 func_00114380(u32) asm("func_00114380");
f32 func_00114390(u32) asm("func_00114390");
s32 func_0010cdd8(u8* o) asm("func_0010cdd8");
s32 func_0010cdd8(u8* o)
{
    u32 t = *(u32*)(o + 3308);
    if (t && *(u32*)(o + 2548) != t) return 1;
    V10ce d = func_00190388(o + 2548) - *YS__OBJ__get_pos(o);
    f32 r = func_001142d0(*(u32*)(o + 2912));
    r = r * r;
    if (r < Dot10ce(d, d)) return 1;
    return 0;
}
}  // namespace g0010cdd8

// 0010ce78 (was src/anon/batch_w1564.cpp)
namespace n0010ce78 {
extern s32 D_003417b0 asm("D_003417b0");
s32 TARGET_is_exist_00190140(void*) asm("_ZNK2YS6TARGET8is_existEv");
typedef struct S0_0010ce78 { u8 pad[0x9f4]; s32 f; } S0_0010ce78;
static inline u8 h0_0010ce78(void) {
    u8 r = 0;
    if (TARGET_is_exist_00190140(&D_003417b0)) r = D_003417b0 != 0;
    return r;
}
/*TARGET 0010ce78*/
s32 func_0010ce78(S0_0010ce78* p) asm("func_0010ce78");
s32 func_0010ce78(S0_0010ce78* p) {
    if (!h0_0010ce78()) return 0;
    s32 d = D_003417b0;
    if (d != 0 && p->f == d) return 0;
    return 1;
}
}  // namespace n0010ce78

// 0010cef0 (was src/anon/batch_w99.cpp)
namespace n0010cef0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V10ce {
    f32 x, y, z, w;
    V10ce& operator=(const V10ce& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline V10ce operator-(const V10ce& a, const V10ce& b)
{
    V10ce r;
    asm(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Dot10ce(const V10ce& a, const V10ce& b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\t"
                 "vaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
extern u8* D_00341708 asm("D_00341708");
V10ce func_00190388(u8*) asm("func_00190388");
// vec4_from_arg
V10ce* YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
// obj_get_attach_or_alt
f32 func_001142d0(u32) asm("func_001142d0");
// get_float_at_ptr108
f32 func_00114380(u32) asm("func_00114380");
f32 func_00114390(u32) asm("func_00114390");
/*TARGET 0010cef0*/
s32 kn__Friend__checkLostTarget_near(u8* o) asm("kn__Friend__checkLostTarget_near");
s32 kn__Friend__checkLostTarget_near(u8* o)
{
    V10ce d = func_00190388(o + 2548) - *YS__OBJ__get_pos(o);  // vec4_from_arg
    f32 r = func_001142d0(*(u32*)(o + 2912));  // get_float_at_ptr108
    r = r * r;
    if (r < Dot10ce(d, d)) return 1;
    r = func_00114380(*(u32*)(o + 2912));
    r += func_00114390(*(u32*)(o + 2912));
    r *= 0.5f;
    r = r * r;
    d = func_00190388(o + 2548) - *YS__OBJ__get_pos(D_00341708);  // vec4_from_arg
    if (r < Dot10ce(d, d)) return 1;
    return 0;
}
}  // namespace n0010cef0

// 0010d038 (was src/anon/batch_w97.cpp)
namespace n0010d038 {
// ---- shared VU0 helpers
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline f32 vdot(const Vq& a, const Vq& b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
static inline Vq vsubn(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
// 00104f58: moved to src/common/area.cpp

// ---- 0010d038
Vq func_00190388(const void*) asm("func_00190388");
// vec4_from_arg
const Vq* YS__OBJ__get_pos(u32) asm("YS__OBJ__get_pos");
// obj_get_attach_or_alt
f32 func_001142d0(u32) asm("func_001142d0");
// get_float_at_ptr108
f32 func_00114390(u32) asm("func_00114390");
extern u32 D_00341708 asm("D_00341708");
/*TARGET 0010d038*/
s32 kn__Friend__checkLostTarget_far(u8* o) asm("kn__Friend__checkLostTarget_far");
s32 kn__Friend__checkLostTarget_far(u8* o) {
    struct Lk { u32 on : 1; u32 rest : 31; };
    Lk* lock = *(Lk**)(o + 3168);
    if (lock && !lock->on) return 1;
    Vq d = vsubn(func_00190388(o + 2548), *YS__OBJ__get_pos((u32)o));  // vec4_from_arg
    f32 r = func_001142d0(*(u32*)(o + 2912));  // get_float_at_ptr108
    r = r * r;
    if (r < vdot(d, d)) return 1;
    r = func_00114390(*(u32*)(o + 2912));
    r = r * r;
    d = vsubn(func_00190388(o + 2548), *YS__OBJ__get_pos(D_00341708));  // vec4_from_arg
    if (vdot(d, d) < r) return 1;
    return 0;
}
}  // namespace n0010d038

// 0010d178 (was gap, never written) / 0010d180
namespace n0010d178 {
s32 func_0010d178() asm("func_0010d178");
s32 func_0010d178() { return 1; }
s32 func_0010d180() asm("func_0010d180");
s32 func_0010d180() { return 0; }
}

// 0010d188 (was src/anon/batch_w261.cpp)
namespace n0010d188 {
struct W261A;
typedef int (W261A::*W261Pmf)();
struct W261A { int pad; };
struct W261E { W261Pmf f; } __attribute__((aligned(8)));
struct W261R { u32 pfn; int d; } __attribute__((aligned(8)));
extern W261E D_00345ad0[] asm("D_00345ad0");
typedef int (*W261Fn)(void*);
int func_0010cc80(void*) asm("func_0010cc80");
int func_001b58a8(void) asm("func_001b58a8");
int func_00112720(void*) asm("func_00112720");
/*TARGET 0010d188*/
// check_2924_lt14

int func_0010d188(W261A* p) asm("func_0010d188");
// check_2924_lt14

int func_0010d188(W261A* p) {
    if (!func_0010cc80(p)) return 1;
    if (func_001b58a8()) return 1;
    if (func_00112720(p)) {  // check_2924_lt14
        return (p->*D_00345ad0[*(int*)((char*)p + 0xb6c) - 8].f)();
    }
    int i = (*(int (**)(void*))(*(u32*)p + 152))(p);
    W261E ee = D_00345ad0[i];
    W261R& e = *(W261R*)&ee;
    int d = e.d;
    char* q = (char*)p + (d >> 1);
    W261Fn fn;
    if ((u8)(d & 1)) fn = *(W261Fn*)(((e.pfn >> 2) << 2) + *(u32*)q);
    else fn = (W261Fn)e.pfn;
    return fn(q);
}
}  // namespace n0010d188

// 0010d2b8 (was src/anon/batch_w1574.cpp)
namespace n0010d2b8 {
struct QW10d { f32 x, y, z, w;
    QW10d() {}
    QW10d(const QW10d& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct Tgt10d { s32 a, b, c, d, e; };
struct Hit10d { s32 p0; f32 r; s32 p8; s32 z; QW10d v; Hit10d() { z = 0; } };
struct Act10d { u8 pad[0xb60]; s32 b60; u8 pad2[0xcec - 0xb64]; s32 cec; };
// 0x0015c2a0: definition moved into src/anon/unit_0015bab8.cpp
f32 func_001142c0(s32) asm("func_001142c0");
void func_00190128(Tgt10d*) asm("func_00190128");
QW10d* YS__OBJ__get_pos(Act10d*) asm("YS__OBJ__get_pos");
void kn__Friend__setAttackTarget(s32, Tgt10d*, QW10d*, f32) asm("kn__Friend__setAttackTarget");
s32 Tgt10d_is_exist(Tgt10d*) asm("_ZNK2YS6TARGET8is_existEv");
s32 Tgt10d_can_attack(Tgt10d*) asm("_ZNK2YS6TARGET10can_attackEv");
s32 YS__TARGET__each(Tgt10d*, s32) asm("YS__TARGET__each");
s32 func_00112d90(Tgt10d*) asm("func_00112d90");
void YS__COLLISION__set(Hit10d*, s32, s32) asm("YS__COLLISION__set");
void func_0010d2b8_impl(Act10d* self, void* unused, Tgt10d* out) asm("_Z13func_0010d2b8Pv");
/*TARGET 0010d2b8*/
void func_0010d2b8_impl(Act10d* self, void* unused, Tgt10d* out) asm("_Z13func_0010d2b8Pv");
void func_0010d2b8_impl(Act10d* self, void* unused, Tgt10d* out) {
    Hit10d hit;
    Tgt10d it;
    f32 best = func_001142c0(self->b60);
    func_00190128(&it);
    func_00190128(&it);
    if (self->cec) {
        QW10d pos(*YS__OBJ__get_pos(self));
        kn__Friend__setAttackTarget(self->cec, &it, &pos, best);
        if (Tgt10d_is_exist(&it)) { *out = it; return; }
    }
    s32 k = 0;
    while ((k = YS__TARGET__each(&it, k)) != 0) {
        if (!func_00112d90(&it)) continue;
        if (!Tgt10d_can_attack(&it)) continue;
        YS__COLLISION__set(&hit, it.a, k);
        QW10d* p = YS__OBJ__get_pos(self);
        f32 len;
        QW10d d;
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(&hit.v), "r"(p), "r"(&d) : "memory");
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8", "memory");
        len = len - hit.r;
        if (len < best) { best = len; *out = it; }
    }
}
}  // namespace n0010d2b8


// 0010d468, 0010d570, 0010d730, 0010d8f8 (were gap): friend target picks (the commanded target, the nearest one in range
// that is also near the leader, the farthest one from the leader within twice the range) and an empty method.
namespace g0010d468 {
struct QW { f32 x, y, z, w;
    QW() {}
    QW(const QW& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct Tgt { s32 a, b, c, d, e; };
struct Hit { s32 p0; f32 r; s32 p8; s32 z; QW v; Hit() { z = 0; } };
struct Act { u8 pad[0xb60]; s32 b60; };
extern Tgt D_003417b0 asm("D_003417b0");
extern Act* D_00341708 asm("D_00341708");
f32 func_001142c0(s32) asm("func_001142c0");
f32 func_00114380(s32) asm("func_00114380");
void func_00190128(Tgt*) asm("func_00190128");
QW* YS__OBJ__get_pos(Act*) asm("YS__OBJ__get_pos");
void kn__Friend__setAttackTarget(s32, Tgt*, QW*, f32) asm("kn__Friend__setAttackTarget");
s32 Tgt_is_exist(Tgt*) asm("_ZNK2YS6TARGET8is_existEv");
s32 Tgt_can_attack(Tgt*) asm("_ZNK2YS6TARGET10can_attackEv");
s32 YS__TARGET__each(Tgt*, s32) asm("YS__TARGET__each");
s32 func_00112d90(Tgt*) asm("func_00112d90");
void YS__COLLISION__set(Hit*, s32, s32) asm("YS__COLLISION__set");
void func_0010da40(Act*, s32, Tgt*) asm("func_0010da40");
static inline f32 dist(QW* a, QW* b, QW* d) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(a), "r"(b), "r"(d) : "memory");
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(d) : "$8", "memory");
    return len;
}
static inline u8 valid(Tgt* t) {
    u8 r = 0;
    if (Tgt_is_exist(t)) r = t->a != 0;
    return r;
}
void func_0010d468(Act* self, s32 a1, Tgt* out) asm("func_0010d468");
void func_0010d468(Act* self, s32 a1, Tgt* out) {
    Tgt it;
    func_00190128(&it);
    func_00190128(&it);
    func_0010da40(self, a1, &it);
    if (valid(&it) && Tgt_can_attack(&it)) {
        *out = it;
        return;
    }
    if (func_00112d90(&D_003417b0)) {
        QW pos(*YS__OBJ__get_pos(self));
        s32 id = D_003417b0.a;
        f32 r = func_001142c0(self->b60);
        kn__Friend__setAttackTarget(id, out, &pos, r);
    }
}
void func_0010d570(Act* self, s32, Tgt* out) asm("func_0010d570");
void func_0010d570(Act* self, s32, Tgt* out) {
    Hit hit;
    Tgt it;
    QW d1, d2;
    f32 lim = func_00114380(self->b60);
    f32 best = func_001142c0(self->b60);
    s32 k = 0;
    func_00190128(&it);
    while ((k = YS__TARGET__each(&it, k)) != 0) {
        if (!func_00112d90(&it)) continue;
        if (!Tgt_can_attack(&it)) continue;
        YS__COLLISION__set(&hit, it.a, k);
        f32 len = dist(&hit.v, YS__OBJ__get_pos(self), &d1) - hit.r;
        if (!(len < best)) continue;
        f32 len2 = dist(&hit.v, YS__OBJ__get_pos(D_00341708), &d2) - hit.r;
        if (!(len2 < lim)) continue;
        // Same code in both arms (a permuter find): the dead test keeps gcc from splitting self's live range for the loop.
        if (self->b60) {
            best = len;
            *out = it;
        } else {
            best = len;
            *out = it;
        }
    }
}
void func_0010d730(Act* self, s32, Tgt* out) asm("func_0010d730");
void func_0010d730(Act* self, s32, Tgt* out) {
    Hit hit;
    Tgt it;
    QW d1, d2;
    f32 best = -1.0f;
    f32 range = func_001142c0(self->b60);
    range = range + range;
    s32 k = 0;
    func_00190128(&it);
    while ((k = YS__TARGET__each(&it, k)) != 0) {
        if (!func_00112d90(&it)) continue;
        if (!Tgt_can_attack(&it)) continue;
        YS__COLLISION__set(&hit, it.a, k);
        f32 len = dist(&hit.v, YS__OBJ__get_pos(self), &d1) - hit.r;
        if (!(len < range)) continue;
        f32 len2 = dist(&hit.v, YS__OBJ__get_pos(D_00341708), &d2) - hit.r;
        if (best < 0.0f || best < len2) {
            best = len2;
            *out = it;
        }
    }
}
void func_0010d8f8(void) asm("func_0010d8f8");
void func_0010d8f8(void) {}
}  // namespace g0010d468
