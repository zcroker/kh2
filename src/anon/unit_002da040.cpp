// Linked unit 0x002da040-0x002dd650 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../ti/minigame_accessors.hpp"
#include "../taito/mg_hachimitsu_po.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../taito/mg_jump.hpp"

// 002da040 (was src/anon/batch_w82.cpp)
namespace n002da040 {
// 16-byte vector whose assignment is a 128-bit copy.
struct Vec82 {
    f32 x, y, z, w;
    Vec82& operator=(const Vec82& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
Vec82* func_0016c028(u32) asm("func_0016c028");
void func_0017f540(u8*, s32, f32, f32) asm("func_0017f540");
s32 func_001c0cd8(u32) asm("func_001c0cd8");
/*TARGET 002da040*/
// 0x002d2660: definition moved into src/anon/unit_002d2498.cpp

void func_002da040(u8* a0) asm("func_002da040");
// 0x002d2660: definition moved into src/anon/unit_002d2498.cpp

void func_002da040(u8* a0)
{
    s32 i;
    a0[3077] = 0;
    a0[3068] = 1;
    if (*(u8**)(a0 + 3060)) func_0017f540(*(u8**)(a0 + 3060) + 320, 0, 0.0f, 0.0f);
    if (*(u32*)(a0 + 3056)) {
        if (func_001c0cd8(*(u32*)(a0 + 3056))) func_0017f540(*(u8**)(a0 + 3056) + 320, 0, 0.0f, 0.0f);
        else func_0017f540(*(u8**)(a0 + 3056) + 320, 153, 0.0f, 0.0f);
    }
    func_0017f540(a0 + 320, 0, 0.0f, 0.0f);
    for (i = 0; i < 8; i++) ((Vec82*)(a0 + 3232))[i] = *func_0016c028((u32)a0);  // obj_get_attach_or_alt
}
}  // namespace n002da040

// 002da110 (was src/anon/tiny.cpp)
namespace n002da110 {
/*TARGET 002da110*/
// 0x002d8900: definition moved into src/anon/unit_002d6f70.cpp

u32 func_002da110(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002da110jjjj");
// 0x002d8900: definition moved into src/anon/unit_002d6f70.cpp

u32 func_002da110(u32 a0, u32 a1, u32 a2, u32 a3) {  // is_field340_eq14
    (void)a1;
    (void)a2;
    (void)a3;
    return ((*(u32*)((u32)a0 + (340)) ^ 0x000eu) == 0);
}
}  // namespace n002da110

// 002da120 (was src/anon/batch_w256.cpp)
namespace n002da120 {
struct H2d { u8 p[152]; s32 i152; };
struct R2d { u8 p[28]; f32 f28; };
struct C2d { u8 p[320]; u8 mo[1]; };
struct A2d { u8 p[320]; u8 mo[3056-320]; void* p3056; C2d* p3060; f32 f3064; u8 q[4]; f32 f3072; };
struct M256 { u8 pad[20]; s32 i20; s32 i24; u32 i28; };
s32 mo_push_w256(M256*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
// 0x0027afe0: definition moved into src/anon/unit_0027a6d8.cpp


extern H2d* D_00361f60 asm("D_00361f60");
void* getgopher_w256(H2d*) asm("_ZN2Ti12MGHachimitsu10get_gopherEv");
s32 isattach_w256(void*) asm("_ZN2YS3OBJ9is_attachEv");
void addcount_w256(s32, s32) asm("_ZN2YS7MISSION8AddCountEii");
R2d* fmat_w256(H2d*) asm("_ZN2kn7FMatrixaSERKS0_");
void f17f488_w256(void*, s32, f32, f32) asm("_Z13func_0017f488iiff");
void func_002db210(void*) asm("func_002db210");
void func_002dbd30(void*, f32) asm("func_002dbd30");
/*TARGET 002da120*/
void func_002da120(A2d* a) asm("func_002da120");
void func_002da120(A2d* a) {
  H2d* h = D_00361f60;
  void* g = getgopher_w256(h);
  if (g && isattach_w256(g)) {
    func_002db210(g);
  } else {
    if (h->i152 == 1) addcount_w256(-1, 0);
    f17f488_w256(a->mo, 14, 0.0f, 0.0f);
    mo_push_w256((M256*)a->mo, 0, 0.0f, 0.0f, 0);
    if (a->p3060) f17f488_w256(a->p3060->mo, 14, 0.0f, 0.0f);
    if (a->p3056 && isattach_w256(a->p3056)) func_002dbd30(a->p3056, a->f3064);
  }
  a->f3072 = fmat_w256(h)->f28;
}
}  // namespace n002da120

// 002da238 (was src/anon/batch_w2376.cpp)
namespace n002da238 {
// 0x00195360: definition moved into src/anon/unit_00194790.cpp
struct Vec_2da238 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Info_2da238 { u8 pad[16]; s16 radius; };
struct Obj_2da238 { u8 pad[1344]; Vec_2da238 pos; u8 pad2[3056 - 1344 - 16]; void* target; };
s32 is_attach_2da238(void* o) asm("_ZN2YS3OBJ9is_attachEv");
s32 is_separate_blow_2da238(void* o) asm("_ZN2Ti14MGHachimitsuPo16is_separate_blowEv");
Info_2da238* func_0016bc20(void*, s32, s32) asm("func_0016bc20");
Vec_2da238* func_0016c028(void*) asm("func_0016c028");
extern s32 D_00361f60 asm("D_00361f60");
// VU0 distance between two points.
static inline f32 dist_2da238(const Vec_2da238* a, const Vec_2da238* b) {
    Vec_2da238 d;
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&d), "r"(a), "r"(b) : "memory");
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(len) : "r"(&d) : "$8", "memory");
    return len;
}
static inline bool in_reach_2da238(Obj_2da238* self) {
    if (is_attach_2da238(self->target) || is_separate_blow_2da238(self->target)) return false;
    f32 r = func_0016bc20(self->target, 5, -1)->radius;
    if (dist_2da238(&self->pos, func_0016c028(self->target)) < r) return true;
    return false;
}
/*TARGET 002da238*/
// True when enabled, the target is free (not attached, not blown apart) and within the target's radius.
s32 func_002da238(Obj_2da238* self) asm("func_002da238");
// True when enabled, the target is free (not attached, not blown apart) and within the target's radius.
s32 func_002da238(Obj_2da238* self) {
    return D_00361f60 && self->target && in_reach_2da238(self);
}
}  // namespace n002da238

// 002da308 (was src/anon/batch_w83.cpp)
namespace n002da308 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    Vec4(const Vec4& o) { QCOPY(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
// d = a - b (xyzw) via VU0.
static inline void vsub(Vec4* d, const void* a, const void* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
// |v.xyz| via VU0.
static inline f32 vlen(const Vec4* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\t"
                 "vaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
// 0x002d89b0: definition moved into src/anon/unit_002d6f70.cpp

extern void* D_00361f60 asm("D_00361f60");
void* func_002d9210(void*) asm("func_002d9210");
s32 func_001c0cd8(void*) asm("func_001c0cd8");
u8* func_0016bc20c(void*, s32, s32) asm("func_0016bc20");
Vec4* func_0016c028b(void*) asm("func_0016c028");
/*TARGET 002da308*/
// Is p within the target's radius?
bool func_002da308(u8* p) asm("func_002da308");
// Is p within the target's radius?
bool func_002da308(u8* p) {
    void* v = func_002d9210(D_00361f60);
    if (!v) return false;
    if (func_001c0cd8(v)) return false;
    u8* pos = p + 1344;
    f32 r = *(s16*)(func_0016bc20c(v, 5, -1) + 16);
    Vec4* q = func_0016c028b(v);
    Vec4 d;
    vsub(&d, pos, q);
    return vlen(&d) < r;
}
}  // namespace n002da308

// 002da3d8 (was src/anon/batch_w97.cpp)
namespace n002da3d8 {
// ---- shared VU0 helpers
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
// 0x002d4f60: definition moved into src/anon/unit_002d4548.cpp

// ---- 002da3d8
struct Range2da { u8 pad[12]; f32 near; f32 far; };
struct Obj2da { u8 pad[1344]; Vq pos; u8 pad1360[3056 - 1360]; u32 tgt; u8 pad3060[17]; u8 multi; u8 pad3078[154]; Vq pts[8]; };
extern u32 D_00361f60 asm("D_00361f60");
s32 func_002da110(Obj2da*) asm("func_002da110");
// is_field340_eq14
s32 func_001c0cd8(u32) asm("func_001c0cd8");
Range2da* func_002d73f0(u32) asm("func_002d73f0");
/*TARGET 002da3d8*/
s32 func_002da3d8(Obj2da* o, const Vq* p) asm("func_002da3d8");
s32 func_002da3d8(Obj2da* o, const Vq* p) {
    s32 r = 0;
    if (func_002da110(o)) return r;
    u32 m = D_00361f60;
    if (!m) return 0;
    f32 rad;
    if (!o->tgt || !func_001c0cd8(o->tgt)) rad = func_002d73f0(m)->near;
    else rad = func_002d73f0(m)->far;
    if (o->multi) {
        for (s32 i = 0; i < 8; i++) {
            Vq d = vsub(o->pts[i], *p);
            r = 0;
            if (vlen(d) <= rad) return 1;
        }
        return r;
    }
    Vq d = vsub(o->pos, *p);
    return vlen(d) <= rad;
}
}  // namespace n002da3d8

// 002da520 (was src/anon/batch_w269.cpp)
namespace n002da520 {
#define QCOPYL269(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct LV269 {
    f32 x, y, z, w;
    LV269() {}
    LV269(const LV269& o) { QCOPYL269(this, &o); }
    LV269& operator=(const LV269& o) { if (this != &o) QCOPYL269(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline LV269 operator*(const LV269& a, f32 k) {
    LV269 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline LV269 operator+(const LV269& a, const LV269& b) {
    LV269 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct LM269 {
    LV269 r[4];
    LM269& operator=(const LM269& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct LO269 {
    u8 pad[3088];
    LM269 prev;   // 3088
    LM269 cur;    // 3152
    LV269 pts[9]; // 3216.. (pts[1] at 3232)
};
// 0x0029a8e0: definition moved into src/anon/unit_00299920.cpp

void func_002d0bd8(LO269*, const LM269*) asm("func_002d0bd8");
/*TARGET 002da520*/
void func_002da520(LO269* a0, const LM269* a1) asm("func_002da520");
void func_002da520(LO269* a0, const LM269* a1) {
    a0->prev = a0->cur;
    a0->cur = *a1;
    func_002d0bd8(a0, a1);
    LV269 a = a0->prev.r[3];
    LV269 b = a0->cur.r[3];
    s32 i;
    s32 n = 8;
    for (i = 1; i <= n; i++) {
        f32 t = (f32)i / (f32)n;
        a0->pts[i] = b * t + a * (1.0f - t);
    }
}
}  // namespace n002da520

// 002da670 (was src/anon/batch_w3777_nsa.cpp)
namespace n002da670 {
struct M2da670 { f32 m[4][4]; } __attribute__((aligned(16)));
struct Pr2da670 { f32 x, w; };
struct O2da670 { u8 pad[3056]; void* pot; u8 pad2[4]; Pr2da670 pos; };
extern void* D_00361f60 asm("D_00361f60");
s32 o2da670_is_attach(void*) asm("_ZN2YS3OBJ9is_attachEv");
M2da670 func_002d8120(void*, Pr2da670*, f32) asm("func_002d8120");
void func_002da520(O2da670*, const M2da670&) asm("func_002da520");
f32 func_002dbf50(void*) asm("func_002dbf50");
void func_002d8d40(void*, f32*, f32*) asm("func_002d8d40");
bool o2da670_is_separate_blow(void*) asm("_ZN2Ti14MGHachimitsuPo16is_separate_blowEv");
f32 o2da670_get_vertical_pos(void*) asm("_ZN2Ti14MGHachimitsuPo16get_vertical_posEv");
void func_002dc140(void*, const M2da670&) asm("func_002dc140");
// Clamp p into [lo, hi].
static inline __attribute__((always_inline)) void Clamp2da670(Pr2da670& p, const f32& lo, const f32& hi)
{
    if (p.x < lo) p.x = lo;
    if (hi < p.x) p.x = hi;
}
// Clamp a, then push b out so the two stay at least a.w + b.w apart.
static inline __attribute__((always_inline)) void Fix2da670(Pr2da670& a, Pr2da670& b, const f32& lo, const f32& hi)
{
    if (a.x < lo) a.x = lo;
    if (hi < a.x) a.x = hi;
    f32 w = a.w + b.w;
    if (a.x < b.x) {
        if (b.x < a.x + w) b.x = a.x + w;
    }
    if (b.x < a.x) {
        if (a.x < b.x + w) b.x = a.x - w;
    }
}
/*TARGET 002da670*/
void func_002da670(O2da670* o) asm("func_002da670");
void func_002da670(O2da670* o)
{
    void* g = D_00361f60;
    if (!g) return;
    if (!o->pot || o2da670_is_attach(o->pot)) {
        func_002da520(o, func_002d8120(g, &o->pos, 0.0f));
        return;
    }
    Pr2da670 pr[2];
    pr[0].x = o->pos.x;
    pr[0].w = 40.0f;
    pr[1].x = func_002dbf50(o->pot);
    pr[1].w = 30.0f;
    f32 lo, hi;
    func_002d8d40(g, &lo, &hi);
    bool ns = !o2da670_is_separate_blow(o->pot);
    if (ns) {
        Fix2da670(pr[0], pr[1], lo, hi);
        Fix2da670(pr[1], pr[0], lo, hi);
    } else {
        for (s32 i = 0; i < 2; i++) Clamp2da670(pr[i], lo, hi);
    }
    {
    const M2da670& m0 = func_002d8120(g, &pr[0], 0.0f);
    func_002da520(o, m0);
    }
    const M2da670& m1 = func_002d8120(g, &pr[1], o2da670_get_vertical_pos(o->pot));
    func_002dc140(o->pot, m1);
}
}  // namespace n002da670

// 002da8f0 (was src/anon/auto80_199_queue.cpp)
namespace n002da8f0 {
/*TARGET 002da8f0*/
// 0x002d7630: definition moved into src/anon/unit_002d6f70.cpp

void func_002da8f0(u32 a0, u32 a1) asm("_Z13func_002da8f0jj");
// 0x002d7630: definition moved into src/anon/unit_002d6f70.cpp

void func_002da8f0(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 t7 = *(u32*)(a0 + 3060);
    if (t7 != 0) {
        func_002db610(t7);
    }
    t7 = *(u32*)(s0 + 3056);
    if (t7 != 0) {
        func_002dc1b8(t7, s1);
    }
}
}  // namespace n002da8f0

// 002da958 (was src/anon/batch_wcx.cpp)
namespace n002da958 {
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_00180378(u8*, u8*, s32, f32) asm("func_00180378");
/*TARGET 002da958*/
void func_002da958(u8* p) asm("func_002da958");
void func_002da958(u8* p)
{
    if (*(u8**)(p + 3060)) func_0017f488(*(u8**)(p + 3060) + 320, 173, 8.0f, 0.0f);
    u8* o = *(u8**)(p + 3056);
    if (!o) return;
    if (func_001c0cd8(o)) func_0017f488(*(u8**)(p + 3056) + 320, 173, 8.0f, 0.0f);
    func_00180378(*(u8**)(p + 3056) + 320, p, 254, 8.0f);
}
}  // namespace n002da958

// 002daa00 (was src/anon/batch_w1749.cpp)
namespace n002daa00 {
// 00292af0: moved to src/anon/unit_00292998.cpp

struct O2da { u8 pad[0xbf4]; s32 p; };
s32 func_0016c028(s32) asm("func_0016c028");
void func_002bc188(s32, s32) asm("func_002bc188");
/*TARGET 002daa00*/
void func_002daa00(O2da* o, u32 a) asm("func_002daa00");
void func_002daa00(O2da* o, u32 a)
{
    if (o->p) {
        a += 0x56ab8;
        func_002bc188(a, func_0016c028(o->p));
    }
}
}  // namespace n002daa00

// 002daa50 (was src/anon/batch_w29.cpp)
namespace n002daa50 {
void func_002cfeb0(u32*, u32, u32, u32) asm("func_002cfeb0");
// obj_init_field1416_bit800
void func_002cf280(void*, u32, u32) asm("func_002cf280");
extern u8 D_00362858[] asm("D_00362858");
/*TARGET 002daa50*/
// 0x002d28f8: definition moved into src/anon/unit_002d2498.cpp

void func_002daa50(u32* p, u32 a, u32 b) asm("func_002daa50");
// 0x002d28f8: definition moved into src/anon/unit_002d2498.cpp

void func_002daa50(u32* p, u32 a, u32 b) {
    func_002cfeb0(p, a, 3, b);  // obj_init_field1416_bit800
    *(void**)p = D_00362858;
    func_002cf280((u8*)p + 2800, 1, 0);
}
}  // namespace n002daa50

// 002daa98 (was src/anon/batch_w30.cpp)
namespace n002daa98 {
void func_002cfeb0(void*, u32, u32, u32) asm("func_002cfeb0");
// obj_init_field1416_bit800
extern u8 D_00362858[] asm("D_00362858");
void func_002cf280(void*, u32, u32) asm("func_002cf280");
/*TARGET 002daa98*/
// 0x002d1270: definition moved into src/anon/unit_002cf260.cpp

void func_002daa98(u8* p, u32 a, u32 b) asm("func_002daa98");
// 0x002d1270: definition moved into src/anon/unit_002cf260.cpp

void func_002daa98(u8* p, u32 a, u32 b) {
    func_002cfeb0(p, a, 3, b);  // obj_init_field1416_bit800
    *(void**)p = D_00362858;
    func_002cf280(p + 2800, 1, 0);
}
}  // namespace n002daa98

// 002daae0 (was never written: gap function)
namespace n002daae0 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8 D_00362858 asm("D_00362858");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362690[] asm("D_00362690");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016b070(u8*, V*) asm("func_0016b070");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002d0d48(u8*) asm("func_002d0d48");
void func_0019fdc0(u8*, V*, f32) asm("func_0019fdc0");
void func_002d9208(u8*, u8*) asm("func_002d9208");
void func_002e7568(u8*, s32, u8*, f32) asm("func_002e7568");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
struct Z { f32 x, y, z, w; void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); } } __attribute__((aligned(16)));
struct B { u8 pad[0x8078]; f32 mn[3]; f32 mx[3]; };

u32 func_002daae0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002daae0");
u32 func_002daae0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00362858;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002cff98)(u32, u32, u32, u32) = func_002cff98;
    r2 = fp_call4_002cff98(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002daae0

// 002dab08 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002dab08 {
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
extern u8 D_00362858 asm("D_00362858");
/*TARGET 002dab08*/
// 0x002d73f0: definition moved into src/anon/unit_002d6f70.cpp

u32 func_002dab08(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002dab08jjjj");
// 0x002d73f0: definition moved into src/anon/unit_002d6f70.cpp

u32 func_002dab08(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00362858;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002cff98)(u32, u32, u32, u32) = func_002cff98;
    r2 = fp_call4_002cff98(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002dab08

// 002dab30 (was src/anon/batch_w21.cpp)
namespace n002dab30 {
void func_00105110(void*) asm("func_00105110");
void func_002cff98(void*) asm("func_002cff98");
extern u32 D_00362858 asm("D_00362858");
/*TARGET 002dab30*/
// 0x002a92a0: definition moved into src/anon/unit_002a92a0.cpp

void func_002dab30(void** p) asm("func_002dab30");
// 0x002a92a0: definition moved into src/anon/unit_002a92a0.cpp

void func_002dab30(void** p) {
    *p = &D_00362858;
    func_002cff98(p);
    func_00105110(p);
}
}  // namespace n002dab30

// 002dab68 (was never written: gap function)
namespace n002dab68 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8 D_00362858 asm("D_00362858");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362690[] asm("D_00362690");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016b070(u8*, V*) asm("func_0016b070");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002d0d48(u8*) asm("func_002d0d48");
void func_0019fdc0(u8*, V*, f32) asm("func_0019fdc0");
void func_002d9208(u8*, u8*) asm("func_002d9208");
void func_002e7568(u8*, s32, u8*, f32) asm("func_002e7568");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
struct Z { f32 x, y, z, w; void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); } } __attribute__((aligned(16)));
struct B { u8 pad[0x8078]; f32 mn[3]; f32 mx[3]; };

void func_002dab68(u8* p) asm("func_002dab68");
void func_002dab68(u8* p) {
    func_002d00a0(p);
    func_0016bd60(p, 3);
    u8* t = *(u8**)(p + 2076);
    if (t) {
        f32 a = *(f32*)(t + 16), b = *(f32*)(t + 20), c = *(f32*)(t + 24);
        V v;
        v.x = a; v.y = -b; v.z = -c;
        v.w = 0.0f;
        func_0016b070(p, &v);
    }
}
}  // namespace n002dab68

// 002dabd0 (was src/anon/tiny.cpp)
namespace n002dabd0 {
void func_0016a9a0(void*) asm("_Z13func_0016a9a0Pv");
/*TARGET 002dabd0*/
// 0x002bd5c8: definition moved into src/anon/unit_002bc978.cpp
void func_002dabd0(BD_VALUE* bd) asm("_Z13func_002dabd0P8BD_VALUE");
// 0x002bd5c8: definition moved into src/anon/unit_002bc978.cpp
void func_002dabd0(BD_VALUE* bd) { func_0016a9a0(bd); }
}  // namespace n002dabd0

// 002dabe8 (was never written: gap function)
namespace n002dabe8 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8 D_00362858 asm("D_00362858");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362690[] asm("D_00362690");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016b070(u8*, V*) asm("func_0016b070");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002d0d48(u8*) asm("func_002d0d48");
void func_0019fdc0(u8*, V*, f32) asm("func_0019fdc0");
void func_002d9208(u8*, u8*) asm("func_002d9208");
void func_002e7568(u8*, s32, u8*, f32) asm("func_002e7568");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
struct Z { f32 x, y, z, w; void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); } } __attribute__((aligned(16)));
struct B { u8 pad[0x8078]; f32 mn[3]; f32 mx[3]; };

void func_002dabe8(u8* p) asm("func_002dabe8");
void func_002dabe8(u8* p) {
    u8* q = p + 2800;
    if (func_002cf270(q, 256)) {
        func_002cf2b0(q, 256);
        func_0016ac38(p, 0, 1, 0, 0);
    }
    func_002d0d48(p);
}
}  // namespace n002dabe8

// 002dac50 (was src/anon/batch_w31.cpp)
namespace n002dac50 {
void func_002cfeb0(void*, u32, int, u32) asm("func_002cfeb0");
// obj_init_field1416_bit800
extern void* D_003627c8[] asm("D_003627c8");
void func_002cf280(void*, int, int) asm("func_002cf280");
/*TARGET 002dac50*/
// 0x002d4828: definition moved into src/anon/unit_002d4548.cpp

void func_002dac50(u8* p, u32 a, u32 b) asm("func_002dac50");
// 0x002d4828: definition moved into src/anon/unit_002d4548.cpp

void func_002dac50(u8* p, u32 a, u32 b) {
    func_002cfeb0(p, a, 3, b);  // obj_init_field1416_bit800
    *(u32*)(p + 2836) = 0;
    *(u8*)(p + 2840) = 0;
    *(void***)p = D_003627c8;
    *(u32*)(p + 2844) = 0;
    func_002cf280(p + 2800, 1, 0);
}
}  // namespace n002dac50

// 002daca0 (was src/anon/batch_w32.cpp)
namespace n002daca0 {
void func_002cfeb0(void*, void*, s32, void*) asm("func_002cfeb0");
// obj_init_field1416_bit800
extern u8 D_003627c8[] asm("D_003627c8");
void func_002cf280(void*, s32, s32) asm("func_002cf280");
/*TARGET 002daca0*/
// 0x002d5e10: definition moved into src/anon/unit_002d4548.cpp

void func_002daca0(u8* p, void* b, void* c) asm("func_002daca0");
// 0x002d5e10: definition moved into src/anon/unit_002d4548.cpp

void func_002daca0(u8* p, void* b, void* c) {
    func_002cfeb0(p, b, 3, c);  // obj_init_field1416_bit800
    *(u32*)(p + 0xb14) = 0;
    p[0xb18] = 0;
    *(void**)p = D_003627c8;
    *(u32*)(p + 0xb1c) = 0;
    func_002cf280(p + 0xaf0, 1, 0);
}
}  // namespace n002daca0

// 002dacf0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002dacf0 {
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
extern u8 D_003627c8 asm("D_003627c8");
/*TARGET 002dacf0*/
u32 func_002dacf0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002dacf0jjjj");
u32 func_002dacf0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003627c8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002cff98)(u32, u32, u32, u32) = func_002cff98;
    r2 = fp_call4_002cff98(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002dacf0

// 002dad18 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002dad18 {
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
extern u8 D_003627c8 asm("D_003627c8");
/*TARGET 002dad18*/
u32 func_002dad18(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002dad18jjjj");
u32 func_002dad18(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003627c8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002cff98)(u32, u32, u32, u32) = func_002cff98;
    r2 = fp_call4_002cff98(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002dad18

// 002dad40 (was src/anon/batch_w22.cpp)
namespace n002dad40 {
void func_00105110(void*) asm("func_00105110");
// 0x002bca10: definition moved into src/anon/unit_002bc978.cpp

// --- 002dad40
extern u32 D_003627c8 asm("D_003627c8");
void func_002cff98(void*) asm("func_002cff98");
/*TARGET 002dad40*/
void func_002dad40(void** p) asm("func_002dad40");
void func_002dad40(void** p) {
    *p = &D_003627c8;
    func_002cff98(p);
    func_00105110(p);
}
}  // namespace n002dad40

// 002dad78 (was never written: gap function)
namespace n002dad78 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8 D_00362858 asm("D_00362858");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362690[] asm("D_00362690");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016b070(u8*, V*) asm("func_0016b070");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002d0d48(u8*) asm("func_002d0d48");
void func_0019fdc0(u8*, V*, f32) asm("func_0019fdc0");
void func_002d9208(u8*, u8*) asm("func_002d9208");
void func_002e7568(u8*, s32, u8*, f32) asm("func_002e7568");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
struct Z { f32 x, y, z, w; void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); } } __attribute__((aligned(16)));
struct B { u8 pad[0x8078]; f32 mn[3]; f32 mx[3]; };

void func_002dad78(u8* p) asm("func_002dad78");
void func_002dad78(u8* p) {
    func_002d00a0(p);
    V v;
    v.w = v.z = v.y = v.x = 0.0f;
    func_0019fdc0(p, &v, v.x);
    u8* t = *(u8**)(p + 2076);
    if (t) {
        f32 a = *(f32*)(t + 16), b = *(f32*)(t + 20), c = *(f32*)(t + 24);
        v.x = a; v.y = -b; v.z = -c;
        v.w = 0.0f;
        func_0016b070(p, &v);
    }
    if (D_00361f60) func_002d9208(D_00361f60, p);
    func_002e7568(p, 4, D_00362690, 1.0f);
}
}  // namespace n002dad78

// 002dae38 (was src/anon/batch_wcx.cpp)
namespace n002dae38 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8* D_0034e948 asm("D_0034e948");
extern u8 D_00362698[] asm("D_00362698");
void func_001c0d38(u8*, u8*, s32, s32) asm("func_001c0d38");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_0016ace0(u8*, V4*) asm("func_0016ace0");
void func_0016b070(u8*, V4*) asm("func_0016b070");
s32 func_002e7568(u8*, s32, u8*, f32) asm("func_002e7568");
/*TARGET 002dae38*/
void func_002dae38(u8* p) asm("func_002dae38");
void func_002dae38(u8* p)
{
    f32 z = 0.0f;
    func_001c0d38(p, D_0034e948, 16384, 0);
    func_002cf2b0(p + 2800, 1);
    V4 v;
    v.x = z; v.y = z; v.w = z; v.z = -70.0f;
    func_0016ace0(p, &v);
    v.w = v.z = v.y = v.x = z;
    func_0016b070(p, &v);
    func_002e7568(p, 2, D_00362698, 1.0f);
}
}  // namespace n002dae38

// 002daee8 (was src/anon/batch_w79.cpp)
namespace n002daee8 {
typedef void (*VF0)(void*);
void func_00187750(void*) asm("func_00187750");
extern f32 D_00349e10 asm("D_00349e10");
f32 fabsf(f32) asm("fabsf");
/*TARGET 002daee8*/
// 0x002d60e8: definition moved into src/anon/unit_002d4548.cpp

void func_002daee8(u8* p) asm("func_002daee8");
// 0x002d60e8: definition moved into src/anon/unit_002d4548.cpp

void func_002daee8(u8* p) {
    f32 v;
    func_00187750(p);
    if (p[2840] == 0) return;
    *(f32*)(p + 2864) += *(f32*)(p + 2848) * D_00349e10;
    *(f32*)(p + 2868) += *(f32*)(p + 2852) * D_00349e10;
    v = *(f32*)(p + 2852) - D_00349e10 * 0.16666666f;
    *(f32*)(p + 2852) = v;
    if (v < 0.0f) {
        if (fabsf(*(f32*)(p + 2868) < 0.1f ? 1.0f : 0.0f) == 0.0f) return;
        p[2840] = 0;
        (*(VF0*)(*(u8**)p + 32))(p);
        asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 2864) : "memory");
    }
}
}  // namespace n002daee8

// 002dafd0 (was src/anon/batch_w1576.cpp)
namespace n002dafd0 {
#define QCP(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCP4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { QCP(this, &o); }
    QV& operator=(const QV& o) { if (this != &o) QCP(this, &o); return *this; }
    QV operator+(const QV& b) const {
        QV o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct QM {
    QV r[4];
    QM() {}
    QM(const QM& o) { QCP4(this, &o); }
    QV operator*(const QV& v) const {
        QV o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
// 0x0025bbe0: definition moved into src/anon/unit_002588e8.cpp

extern u8* D_00361f60 asm("D_00361f60");
void func_0016a9a0(void) asm("func_0016a9a0");
QM* func_002d8110(u8*) asm("func_002d8110");
void func_002d0bd8(u8*, QM*) asm("func_002d0bd8");
void func_0011b6a8(QM*) asm("func_0011b6a8");
void func_0011b7b0(QM*, u8*) asm("func_0011b7b0");
void func_0016ace0(u8*, QV*) asm("func_0016ace0");
void func_0016b070(u8*, u8*) asm("func_0016b070");
void func_002d8120(f32, QM*, u8*, u8*) asm("func_002d8120");
void func_002d0b88(u8*, QM*) asm("func_002d0b88");
/*TARGET 002dafd0*/
void func_002dafd0(u8* o) asm("func_002dafd0");
void func_002dafd0(u8* o) {
    func_0016a9a0();
    if (*(u8*)(o + 0xb18) == 0) return;
    u8* g = D_00361f60;
    if (*(s32*)(o + 0xb1c) == 0) {
        QM m;
        QM* src = func_002d8110(g);
        QV* tp = &m.r[3];
        QCP4(&m, src);
        QV v;
        v.x = *(f32*)(o + 0xb40) + *(f32*)(o + 0xb30);
        v.y = *(f32*)(o + 0xb44) - *(f32*)(o + 0xb34);
        v.z = *(f32*)(o + 0xb48);
        v.w = 1.0f;
        QV t = m * v;
        t.w = 1.0f;
        *tp = t;
        func_002d0bd8(o, &m);
    } else {
        QM m;
        func_0011b6a8(&m);
        func_0011b7b0(&m, o + 0xb50);
        *(s32*)(o + 0xb3c) = 0;
        QV v = m * *(QV*)(o + 0xb30) + *(QV*)(o + 0xb40);
        func_0016ace0(o, &v);
        func_0016b070(o, o + 0xb50);
        QM x;
        func_002d8120(-*(f32*)(o + 0xb34), &x, g, o + 0xb30);
        func_002d0b88(o, &x);
    }
}
}  // namespace n002dafd0

// 002db188 (was never written: gap function)
namespace n002db188 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8 D_00362858 asm("D_00362858");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362690[] asm("D_00362690");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016b070(u8*, V*) asm("func_0016b070");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002d0d48(u8*) asm("func_002d0d48");
void func_0019fdc0(u8*, V*, f32) asm("func_0019fdc0");
void func_002d9208(u8*, u8*) asm("func_002d9208");
void func_002e7568(u8*, s32, u8*, f32) asm("func_002e7568");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
struct Z { f32 x, y, z, w; void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); } } __attribute__((aligned(16)));
struct B { u8 pad[0x8078]; f32 mn[3]; f32 mx[3]; };

void func_002db188(u8* p) asm("func_002db188");
void func_002db188(u8* p) {
    if (*(u8**)(p + 2836) && func_0019ba60(*(u8**)(p + 2836)) && func_001c0cd8(*(u8**)(p + 2836))) {
        u8* o = *(u8**)(p + 2836);
        (*(void (**)(u8*))(*(u8**)o + 32))(o);
    }
    if (D_00361f60) func_002d9208(D_00361f60, 0);
    func_002d0d48(p);
}
}  // namespace n002db188

// 002db208 (was src/ti/minigame_accessors.cpp)
namespace n002db208 {
void set_balloon(Ti::MGHachimitsuGopher* self, Ti::MGObj* v) asm("_ZN2Ti18MGHachimitsuGopher11set_balloonEPNS_5MGObjE");
void set_balloon(Ti::MGHachimitsuGopher* self, Ti::MGObj* v) {
    reinterpret_cast<Ti::MGHachimitsuGopherLayout*>(self)->balloon = v;
}
}  // namespace n002db208

// 002db210 (was src/anon/batch_wcx2_nsa.cpp)
namespace n002db210 {
struct H2db210;
#define W2db210_QCOPY(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
struct W2db210Vec {
    f32 x, y, z, w;
    W2db210Vec() {}
    W2db210Vec(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    W2db210Vec operator*(f32 k) const
    {
        W2db210Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    void Zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    W2db210Vec(const W2db210Vec& o) { W2db210_QCOPY(this, &o); }
    W2db210Vec& operator=(const W2db210Vec& o) { if (this != &o) W2db210_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W2db210Mtx {
    W2db210Vec r0, r1, r2, r3;
    W2db210Mtx() {}
    W2db210Mtx(const W2db210Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W2db210Mtx& operator=(const W2db210Mtx& o) {
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
    W2db210Vec operator*(const W2db210Vec& v) const {
        W2db210Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
static inline W2db210Vec operator*(f32 k, const W2db210Vec& v) { return v * k; }
struct Cfg2db210 { u8 pad[44]; f32 f44; u8 pad2[8]; f32 speed; f32 angle; };
struct H2db210Vt { void* f[8]; void (*kill)(H2db210*); };
struct H2db210 { H2db210Vt* vt; };
struct O2db210 {
    u8 pad0[320]; u8 motion[2800 - 320];
    u8 lflag[36]; H2db210* holder; u8 f2840; u8 pad1[3]; s32 thrown;
    W2db210Vec vel; W2db210Vec acc; W2db210Vec pos; W2db210Vec rot;
};
extern void* g2db210_game asm("D_00361f60");
extern void* g2db210_player asm("D_0034e948");
void o2db210_detach(void*) asm("_ZN2YS3OBJ6detachEv");
void o2db210_set(void*, u32, s32) asm("_Z16wtarget_002cf280jjjj");
s32 o2db210_alive(H2db210*) asm("_Z16ctarget_0019ba60jjjj");
s32 o2db210_is_attach(void*) asm("_ZN2YS3OBJ9is_attachEv");
void o2db210_change(void*, s32, f32, f32) asm("_ZN2YS6MOTION6changeEiff");
W2db210Mtx* o2db210_002d8110(void*) asm("func_002d8110");
W2db210Vec* o2db210_0016c028(O2db210*) asm("func_0016c028");
W2db210Vec* o2db210_get_xyzrot(void*) asm("_ZN2YS3OBJ10get_xyzrotEv");
s32 func_001064a8(s32) asm("func_001064a8");
Cfg2db210* o2db210_002d73f0(void*) asm("func_002d73f0");
f32 cosf(f32) asm("cosf");
f32 sinf(f32) asm("sinf");
void o2db210_002d9208(void*, s32) asm("_Z13func_002d9208Pvi");
/*TARGET 002db210*/
void func_002db210(O2db210* o) asm("func_002db210");
void func_002db210(O2db210* o)
{
    o2db210_detach(o);
    o2db210_set(o->lflag, 1, 0);
    if (o->holder && o2db210_alive(o->holder)) {
        if (o2db210_is_attach(o->holder)) o2db210_detach(o->holder);
        o->holder->vt->kill(o->holder);
    }
    void* g = g2db210_game;
    o2db210_change(o->motion, 151, 0.0f, 0.0f);
    if (!o->thrown) {
        W2db210Mtx m(*o2db210_002d8110(g));
        m.invOrtho();
        o->pos = m * *o2db210_0016c028(o);
    } else {
        o->rot = *o2db210_get_xyzrot(g2db210_player);
        o->pos = *o2db210_0016c028(o);
    }
    f32 ang;
    if (func_001064a8(2)) ang = o2db210_002d73f0(g)->angle;
    else ang = 3.1415927f - o2db210_002d73f0(g)->f44;
    o->vel = o2db210_002d73f0(g)->speed * W2db210Vec(cosf(ang), sinf(ang), 0.0f, 0.0f);
    o->acc.Zero();
    o->f2840 = 1;
    o2db210_002d9208(g, 0);
}
}  // namespace n002db210

// 002db4b0 (was src/anon/tiny_auto80_solver.cpp)
namespace n002db4b0 {
u32 func_002db4b0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002db4b0jjjjjjjj");
extern u8 D_00362738 asm("D_00362738");
u32 func_002cfeb0(u32 a0) asm("_Z13func_002cfeb0j");
/*TARGET 002db4b0*/
u32 func_002db4b0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002db4b0jjjjjjjj");
u32 func_002db4b0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15, r16;
    r7 = r6;
    r6 = (u32)((s32)0u + (1));
    r16 = r4;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_002cfeb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = (u32)&D_00362738;
    r14 = (u32)((s32)0u + (-1));
    *(u32*)((u32)r16 + (s32)(2836)) = r14;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n002db4b0

// 002db4f0 (was src/anon/tiny_auto80_solver.cpp)
namespace n002db4f0 {
extern u8 D_00362738 asm("D_00362738");
u32 func_002cfeb0(u32 a0) asm("_Z13func_002cfeb0j");
/*TARGET 002db4f0*/
u32 func_002db4f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002db4f0jjjjjjjj");
u32 func_002db4f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15, r16;
    r7 = r6;
    r6 = (u32)((s32)0u + (1));
    r16 = r4;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_002cfeb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = (u32)&D_00362738;
    r14 = (u32)((s32)0u + (-1));
    *(u32*)((u32)r16 + (s32)(2836)) = r14;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n002db4f0

// 002db530 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002db530 {
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
u32 func_002db530(u32, u32, u32, u32) asm("_Z13func_002db530jjjj");
extern u8 D_00362738 asm("D_00362738");
/*TARGET 002db530*/
u32 func_002db530(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002db530jjjj");
u32 func_002db530(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00362738;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002cff98)(u32, u32, u32, u32) = func_002cff98;
    r2 = fp_call4_002cff98(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002db530

// 002db558 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002db558 {
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
extern u8 D_00362738 asm("D_00362738");
/*TARGET 002db558*/
u32 func_002db558(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002db558jjjj");
u32 func_002db558(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00362738;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002cff98)(u32, u32, u32, u32) = func_002cff98;
    r2 = fp_call4_002cff98(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002db558

// 002db580 (was src/anon/batch_w23.cpp)
namespace n002db580 {
void func_00105110(void*) asm("func_00105110");
// 0x002bec38: definition moved into src/anon/unit_002bebd0.cpp

extern u32 D_00362738 asm("D_00362738");
void func_002cff98(void*) asm("func_002cff98");
/*TARGET 002db580*/
void func_002db580(void** p) asm("func_002db580");
void func_002db580(void** p) {
    *p = &D_00362738;
    func_002cff98(p);
    func_00105110(p);
}
}  // namespace n002db580

// 002db5b8 (was never written: gap function)
namespace n002db5b8 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8 D_00362858 asm("D_00362858");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362690[] asm("D_00362690");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016b070(u8*, V*) asm("func_0016b070");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002d0d48(u8*) asm("func_002d0d48");
void func_0019fdc0(u8*, V*, f32) asm("func_0019fdc0");
void func_002d9208(u8*, u8*) asm("func_002d9208");
void func_002e7568(u8*, s32, u8*, f32) asm("func_002e7568");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
struct Z { f32 x, y, z, w; void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); } } __attribute__((aligned(16)));
struct B { u8 pad[0x8078]; f32 mn[3]; f32 mx[3]; };

void func_002db5b8(u8* p) asm("func_002db5b8");
void func_002db5b8(u8* p) {
    func_002d00a0(p);
    V v;
    v.w = v.z = v.y = v.x = 0.0f;
    func_0019fdc0(p, &v, v.x);
    *(u32*)(p + 264) |= 3;
}
}  // namespace n002db5b8

// 002db610 (was src/anon/batch_w40.cpp)
namespace n002db610 {
// 0x002d0f38: definition moved into src/anon/unit_002cf260.cpp

void func_001dc818(u32) asm("func_001dc818");
u32 func_0016ac38(u8*, s32, u32, u32, u32) asm("func_0016ac38");
/*TARGET 002db610*/
void func_002db610(u8* p, s32 id) asm("func_002db610");
void func_002db610(u8* p, s32 id) {
    if (*(u32*)(p + 2828)) {
        if (*(s32*)(p + 2836) == id) return;
        func_001dc818(*(u32*)(p + 2828));
        *(u32*)(p + 2828) = 0;
    }
    if (id >= 0) *(u32*)(p + 2828) = func_0016ac38(p, id, 1, 0, 0);
    *(s32*)(p + 2836) = id;
}
}  // namespace n002db610

// 002db680 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n002db680 {
u32 func_002db4b0(u32, u32, u32, u32) asm("_Z13func_002db4b0jjjj");
extern u8 D_003626a8 asm("D_003626a8");
/*TARGET 002db680*/
// 0x002d69c8: definition moved into src/anon/unit_002d62d0.cpp

u32 func_002db680(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002db680jjjj");
// 0x002d69c8: definition moved into src/anon/unit_002d62d0.cpp

u32 func_002db680(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_002db4b0(r4, r5, r6, r7);
    r15 = (u32)&D_003626a8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n002db680

// 002db6b0 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n002db6b0 {
u32 func_002db4b0(u32, u32, u32, u32) asm("_Z13func_002db4b0jjjj");
extern u8 D_003626a8 asm("D_003626a8");
/*TARGET 002db6b0*/
u32 func_002db6b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002db6b0jjjj");
u32 func_002db6b0(u32 a0, u32 a1, u32 a2, u32 a3) {  // obj_ctor_basic
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_002db4b0(r4, r5, r6, r7);
    r15 = (u32)&D_003626a8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n002db6b0

// 002db6e0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002db6e0 {
extern u8 D_003626a8 asm("D_003626a8");
u32 func_002db530(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002db530jjjj");
/*TARGET 002db6e0*/
u32 func_002db6e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002db6e0jjjj");
u32 func_002db6e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003626a8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002db530)(u32, u32, u32, u32) = func_002db530;
    r2 = fp_call4_002db530(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002db6e0

// 002db708 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002db708 {
extern u8 D_003626a8 asm("D_003626a8");
u32 func_002db530(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002db530jjjj");
/*TARGET 002db708*/
u32 func_002db708(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002db708jjjj");
u32 func_002db708(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003626a8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002db530)(u32, u32, u32, u32) = func_002db530;
    r2 = fp_call4_002db530(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002db708

// 002db730 (was src/anon/batch_w11.cpp)
namespace n002db730 {
void func_00105110(void*) asm("func_00105110");
// 0x002c58c8: definition moved into src/anon/unit_002c53c8.cpp

extern u32 D_003626a8 asm("D_003626a8");
void func_002db530(void*) asm("func_002db530");
/*TARGET 002db730*/
void func_002db730(void** p) asm("func_002db730");
void func_002db730(void** p) {
    *p = &D_003626a8;
    func_002db530(p);
    func_00105110(p);
}
}  // namespace n002db730

// 002db768 (was never written: gap function)
namespace n002db768 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8 D_00362858 asm("D_00362858");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362690[] asm("D_00362690");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016b070(u8*, V*) asm("func_0016b070");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002d0d48(u8*) asm("func_002d0d48");
void func_0019fdc0(u8*, V*, f32) asm("func_0019fdc0");
void func_002d9208(u8*, u8*) asm("func_002d9208");
void func_002e7568(u8*, s32, u8*, f32) asm("func_002e7568");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
struct Z { f32 x, y, z, w; void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); } } __attribute__((aligned(16)));
struct B { u8 pad[0x8078]; f32 mn[3]; f32 mx[3]; };

void func_002db768(u8* p) asm("func_002db768");
void func_002db768(u8* p) {
    func_002d00a0(p);
    func_0016bd60(p, 3);
    *(u32*)(p + 264) |= 3;
    u8* t = *(u8**)(p + 2076);
    if (t) func_0017f488(p + 320, *(s32*)(t + 32) + 151, 0.0f, 0.0f);
}
}  // namespace n002db768

// 002db7d0 (was src/anon/batch_w15.cpp)
namespace n002db7d0 {
// 0x002d47a8: definition moved into src/anon/unit_002d4548.cpp

void func_0016a9a0(void*) asm("func_0016a9a0");
// to_16a950
void func_002db610(void*, s32) asm("func_002db610");
/*TARGET 002db7d0*/
void func_002db7d0(u8* p) asm("func_002db7d0");
void func_002db7d0(u8* p) {
    func_0016a9a0(p);  // to_16a950
    func_002db610(p, (p[568] & 1) ? 0 : -1);
}
}  // namespace n002db7d0

// 002db808 (was src/anon/batch_w53.cpp)
namespace n002db808 {
// Local with a non-trivial destructor: keeps the final call a jal instead of a sibcall.
struct NoTail { ~NoTail() {} };
extern u8 D_00362908[] asm("D_00362908");
void func_002cfeb0(u8*, u32, u32, u32) asm("func_002cfeb0");
// obj_init_field1416_bit800
void func_002e7308(u8*) asm("func_002e7308");
/*TARGET 002db808*/
// 0x002d48b8: definition moved into src/anon/unit_002d4548.cpp

void func_002db808(u8* p, u32 a, u32 b) asm("func_002db808");
// 0x002d48b8: definition moved into src/anon/unit_002d4548.cpp

void func_002db808(u8* p, u32 a, u32 b) {
    NoTail g;
    func_002cfeb0(p, a, 3, b);  // obj_init_field1416_bit800
    *(s32*)(p + 2836) = -1;
    *(u8**)p = D_00362908;
    func_002e7308(p + 2976);
}
}  // namespace n002db808

// 002db858 (was src/anon/batch_w24.cpp)
namespace n002db858 {
// 0x002d6e08: definition moved into src/anon/unit_002d62d0.cpp

void func_002cfeb0(u8*, u32, s32, u32) asm("func_002cfeb0");
// obj_init_field1416_bit800
u8 func_002e7308(u8*) asm("func_002e7308");
extern void* D_00362908[] asm("D_00362908");
/*TARGET 002db858*/
s32 func_002db858(u8* p, u32 a, u32 b) asm("func_002db858");
s32 func_002db858(u8* p, u32 a, u32 b) {
    func_002cfeb0(p, a, 3, b);  // obj_init_field1416_bit800
    *(s32*)(p + 2836) = -1;
    *(void**)p = D_00362908;
    return func_002e7308(p + 2976);
}
}  // namespace n002db858

// 002db8a8 (was src/anon/batch_w20.cpp)
namespace n002db8a8 {
u8 func_002cff98(void*) asm("func_002cff98");
void func_002e7328(void*) asm("func_002e7328");
extern void* D_00362908[] asm("D_00362908");
/*TARGET 002db8a8*/
// 0x002d6af0: definition moved into src/anon/unit_002d62d0.cpp

s32 func_002db8a8(void** p) asm("func_002db8a8");
// 0x002d6af0: definition moved into src/anon/unit_002d62d0.cpp

s32 func_002db8a8(void** p) {
    *p = D_00362908;
    func_002e7328((u8*)p + 2976);  // to_2e7458
    return func_002cff98(p);
}
}  // namespace n002db8a8

// 002db8e8 (was src/anon/batch_w21.cpp)
namespace n002db8e8 {
void func_002cff98(void*) asm("func_002cff98");
void func_002e7328(void*) asm("func_002e7328");
extern u32 D_00362908 asm("D_00362908");
// Destructor-shaped: base teardown runs last as a cleanup (no tail call).
struct BaseDtor { void** self; ~BaseDtor() { func_002cff98(self); } };
/*TARGET 002db8e8*/
void func_002db8e8(void** p) asm("func_002db8e8");
void func_002db8e8(void** p) {
    BaseDtor g = { p };
    *p = &D_00362908;
    func_002e7328((u8*)p + 2976);  // to_2e7458
}
}  // namespace n002db8e8

// 002db928 (was src/anon/batch_w33.cpp)
namespace n002db928 {
void func_00105110(void*) asm("func_00105110");
// 0x002bd6d0: definition moved into src/anon/unit_002bc978.cpp

extern void* D_00362908[] asm("D_00362908");
void func_002e7328(void*) asm("func_002e7328");
// to_2e7458
void func_002cff98(void*) asm("func_002cff98");
/*TARGET 002db928*/
void func_002db928(u8* p) asm("func_002db928");
void func_002db928(u8* p) {
    *(void**)p = D_00362908;
    func_002e7328(p + 2976);  // to_2e7458
    func_002cff98(p);
    func_00105110(p);
}
}  // namespace n002db928

// 002db968 (was src/anon/batch_w2373.cpp)
namespace n002db968 {
struct P2db968 { u8 pad[0x48]; f32 x; f32 y; };
P2db968* func_002d73f0(s32) asm("func_002d73f0");
void func_002e7340(f32, f32, s32, s32, s32, void*) asm("func_002e7340");
extern s32 D_00361f60 asm("D_00361f60");
extern u8 D_003628e8[] asm("D_003628e8");
extern u8 D_003628f8[] asm("D_003628f8");
// 0017ca88: moved to src/anon/unit_0017c400.cpp

/* The always_inline helper (argument b = a + 0xba0 passed in) reproduces the original's saved-but-unused s4. */
static inline __attribute__((always_inline)) void db968_draw(s32 b, s32 a, s32 mode, void* tex, s32 g) {
    P2db968* p = func_002d73f0(g);
    P2db968* q = func_002d73f0(g);
    func_002e7340(p->x, q->y, b, a, mode, tex);
}
/*TARGET 002db968*/
/* 002db968: draw element a (style 3 or 6) at the current target's x/y. */
void func_002db968(s32 a, u8 f) asm("func_002db968");
/* 002db968: draw element a (style 3 or 6) at the current target's x/y. */
void func_002db968(s32 a, u8 f) {
    s32 g = D_00361f60;
    if (f) db968_draw(a + 0xba0, a, 3, D_003628f8, g);
    else db968_draw(a + 0xba0, a, 6, D_003628e8, g);
}
}  // namespace n002db968

// 002dba28 (was src/anon/tiny_wrappers_more.cpp)
namespace n002dba28 {
u32 func_002e7458(u32, u32, u32, u32) asm("_Z13func_002e7458jjjj");
/*TARGET 002dba28*/
// 0x002d8d08: definition moved into src/anon/unit_002d6f70.cpp

u32 func_002dba28(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002dba28jjjj");
// 0x002d8d08: definition moved into src/anon/unit_002d6f70.cpp

u32 func_002dba28(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002e7458(((u32)(a0) + 2976u), a1, a2, a3);
}
}  // namespace n002dba28

// 002dba40 (was src/anon/batch_w54.cpp)
namespace n002dba40 {
// unions with a char member: the original was built without strict aliasing
union U32c {
    u32 v;
    u8 c;
};
// 0x002d0d88: definition moved into src/anon/unit_002cf260.cpp

struct Vec4f {
    f32 x, y, z, w;
};
void func_002d00a0(void*) asm("func_002d00a0");
s32 func_00181500(s32) asm("func_00181500");
void func_0016bd60(void*, s32) asm("func_0016bd60");
void func_0016b070(void*, void*) asm("func_0016b070");
void func_002db968(void*, s32) asm("func_002db968");
extern u8 D_003628f0[] asm("D_003628f0");
/*TARGET 002dba40*/
void func_002dba40(u8* p) asm("func_002dba40");
void func_002dba40(u8* p) {
    func_002d00a0(p);
    Vec4f v;
    bool off = func_00181500(9271) == 0;
    D_003628f0[1] = 21 - off;
    func_0016bd60(p, 3);
    v.w = v.z = v.y = v.x = 0.0f;
    ((U32c*)(p + 264))->v |= 1;
    func_0016b070(p, &v);
    *(f32*)(p + 3056) = 0.0f;
    func_002db968(p, 1);
}
}  // namespace n002dba40

// 002dbad8 (was src/anon/batch_w1787_nsa.cpp)
namespace n002dbad8 {
// 0x00283c50: definition moved into src/anon/unit_00282c68.cpp

/* 002dbad8 */
extern f32 D_00349e10 asm("D_00349e10");
void func_00187750(void*) asm("func_00187750");
f32 fabsf(f32) asm("fabsf");
struct Obj2dbad8 {
    u8 pad0[0xbc0];
    u8 flag;          /* bc0 */
    u8 pad1[0x13];
    f32 a;            /* bd4 */
    u8 pad2[8];
    f32 v[4];         /* be0 */
    u8 pad3[4];
    f32 c;            /* bf4 */
};
/*TARGET 002dbad8*/
void func_002dbad8(Obj2dbad8* p) asm("func_002dbad8");
void func_002dbad8(Obj2dbad8* p) {
    func_00187750(p);
    if (p->flag) {
        f32 d = D_00349e10;
        p->v[1] += p->a * d;
        p->a -= p->c * D_00349e10;
        if (p->a < 0.0f) {
            if (fabsf(p->v[1] < 0.1f ? 1.0f : 0.0f) != 0.0f) {
                p->flag = 0;
                /* VU0 vector zero (vsub vf1,vf0,vf0 + sqc2) */
                asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" :: "r"(p->v) : "memory");
            }
        }
    }
}
}  // namespace n002dbad8

// 002dbb88 (was src/anon/batch_w257.cpp)
namespace n002dbb88 {
extern u8* D_00361f60 asm("D_00361f60");
void func_00198690(u8*) asm("func_00198690");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0016b070(u8*, f32*) asm("func_0016b070");
void func_0016ace0(u8*, f32*) asm("func_0016ace0");
s32 func_002d8d68(u8*, u8*, u8*, u8*) asm("func_002d8d68");
u8* func_002d73f0(u8*) asm("func_002d73f0");
void func_001d86a0(s32, s32) asm("func_001d86a0");
union UF { f32 f; s32 i; u8 c; };
/*TARGET 002dbb88*/
void func_002dbb88(u8* a0) asm("func_002dbb88");
void func_002dbb88(u8* a0) {
    func_00198690(a0);
    if (func_001c0cd8(a0)) {
        f32 z = 0.0f;
        f32 v[4];
        f32 w[4];
        v[0] = -1.570796251296997f; v[1] = -1.570796251296997f; v[2] = z; v[3] = z;
        func_0016b070(a0, v);
        w[0] = z; w[1] = z; w[2] = z; w[3] = z;
        func_0016ace0(a0, w);
        return;
    }
    if (a0[0xbc0]) return;
    if (!(*(f32*)(a0 + 0xbf0) <= 0.0f)) return;
    u8* s = D_00361f60;
    if (!s) return;
    if (func_002d8d68(s, a0, a0 + 0xb20, a0 + 0xb60) <= 0) return;
    a0[0xb1c] = *(f32*)(a0 + 0xb18) < 0.0f;
    ((UF*)(a0 + 0xbf0))->f = *(f32*)(func_002d73f0(s) + 0x34);
    if (*(s32*)(s + 0x98) == 1) func_001d86a0(-1, 0);
}
}  // namespace n002dbb88

// 002dbca0 (was src/anon/batch_w63.cpp)
namespace n002dbca0 {
void func_0017f540(void*, s32, f32, f32) asm("func_0017f540");
u32 func_002d1260(void) asm("func_002d1260");
void func_001c0d38(void*, u32, s32, s32) asm("func_001c0d38");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002db968(void*, s32) asm("func_002db968");
extern u8 D_003628f0 asm("D_003628f0");
/*TARGET 002dbca0*/
// 0x002bdac8: definition moved into src/anon/unit_002bc978.cpp

void func_002dbca0(u8* p, u8 flag) asm("func_002dbca0");
// 0x002bdac8: definition moved into src/anon/unit_002bc978.cpp

void func_002dbca0(u8* p, u8 flag) {
    func_0017f540(p + 320, 0, 0.0f, 0.0f);
    func_001c0d38(p, func_002d1260(), 67, 0);
    if (flag) func_002e7568(p, 2, &D_003628f0, 1.0f);
    func_002db968(p, 1);
}
}  // namespace n002dbca0

// 002dbd30 (was src/anon/batch_w1992.cpp)
namespace n002dbd30 {
#define W1992_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define W1992_MCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t" \
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" \
                         : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QW2dbd30 { union { u32 v[4]; f32 f[4]; };
  QW2dbd30() {}
  QW2dbd30(f32 x, f32 y, f32 z, f32 w) { f[0] = x; f[1] = y; f[2] = z; f[3] = w; }
  QW2dbd30& operator=(const QW2dbd30& o) { if (this != &o) W1992_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct MT2dbd30 { QW2dbd30 r[4];
  MT2dbd30& operator=(const MT2dbd30& o) { if (this != &o) W1992_MCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Cfg2dbd30 { u8 pad[0x28]; f32 f28; f32 f2c; u8 pad2[0x40 - 0x30]; f32 f40; };
struct Ob2dbd30 { u8 pad[0x140]; u8 s140[0xb1c - 0x140]; u8 neg; u8 pad2[3]; MT2dbd30 m20; MT2dbd30 m60;
  u8 pad3[0xbc0 - 0xba0]; u8 bc0; u8 pad4[15]; QW2dbd30 vd0; QW2dbd30 ve0; u8 pad5[0xbf4 - 0xbf0]; f32 bf4; };
extern s32 D_00361f60 asm("D_00361f60");
extern u32 D_0034e948 asm("D_0034e948");
extern u8 D_003628e0[] asm("D_003628e0");
void func_0017f540(void*, s32, f32, f32) asm("func_0017f540");
void func_001c0e60(Ob2dbd30*) asm("func_001c0e60");
void func_0011b6a8(MT2dbd30*) asm("func_0011b6a8");
u32 func_0016b0a0(u32) asm("func_0016b0a0");
void func_0011b7b0(MT2dbd30*, u32) asm("func_0011b7b0");
QW2dbd30* func_0016c028(Ob2dbd30*) asm("func_0016c028");
Cfg2dbd30* func_002d73f0(s32) asm("func_002d73f0");
f32 cosf(f32) asm("cosf");
f32 sinf(f32) asm("sinf");
void func_002e7568(Ob2dbd30*, s32, void*, f32) asm("func_002e7568");
void func_002db968(Ob2dbd30*, s32) asm("func_002db968");
static inline void w1992_scale(QW2dbd30& d, const QW2dbd30& a, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&d), "r"(&a), "f"(s) : "$8", "memory");
}
static inline void w1992_zero(QW2dbd30* d) { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(d) : "memory"); }
static inline void w1992_setdir(QW2dbd30& out, f32 a, f32 r) {
    QW2dbd30 res;
    QW2dbd30 v(cosf(a), sinf(a), 0.0f, 0.0f);
    w1992_scale(res, v, r);
    out = res;
}
/*TARGET 002dbd30*/
void func_002dbd30(Ob2dbd30* self, f32 x) asm("func_002dbd30");
void func_002dbd30(Ob2dbd30* self, f32 x) {
    s32 id = D_00361f60;
    func_0017f540(self->s140, 153, 0.0f, 0.0f);
    func_001c0e60(self);
    self->neg = x < 0.0f;
    func_0011b6a8(&self->m60);
    func_0011b7b0(&self->m60, func_0016b0a0(D_0034e948));
    self->m60.r[3] = *func_0016c028(self);
    self->m60.r[3].f[3] = 1.0f;
    self->m20 = self->m60;
    self->bc0 = 1;
    f32 a;
    if (self->neg) a = func_002d73f0(id)->f2c;
    else a = 3.14159274f - func_002d73f0(id)->f2c;
    w1992_setdir(self->vd0, a, func_002d73f0(id)->f28);
    f32 y = self->vd0.f[1];
    self->bf4 = y * y / (2.0f * func_002d73f0(id)->f40);
    w1992_zero(&self->ve0);
    func_002e7568(self, 5, D_003628e0, 1.0f);
    func_002db968(self, 0);
}
}  // namespace n002dbd30

// 002dbf38 (was never written: gap function)
namespace n002dbf38 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8 D_00362858 asm("D_00362858");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362690[] asm("D_00362690");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016b070(u8*, V*) asm("func_0016b070");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002d0d48(u8*) asm("func_002d0d48");
void func_0019fdc0(u8*, V*, f32) asm("func_0019fdc0");
void func_002d9208(u8*, u8*) asm("func_002d9208");
void func_002e7568(u8*, s32, u8*, f32) asm("func_002e7568");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
struct Z { f32 x, y, z, w; void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); } } __attribute__((aligned(16)));
struct B { u8 pad[0x8078]; f32 mn[3]; f32 mx[3]; };

void func_002dbf38(u8* p) asm("func_002dbf38");
void func_002dbf38(u8* p) { ((Z*)(p + 16))->Zero(); }
}  // namespace n002dbf38

// 002dbf50 (was src/anon/batch_w287.cpp)
namespace n002dbf50 {
struct V287 {
    f32 x, y, z, w;
    V287() {}
    V287(const V287& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V287& operator=(const V287& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M287 {
    V287 r[4];
    M287() {}
    M287(const M287& o) {
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
            : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    // In-place inverse of an orthonormal transform (transpose rotation, negate rotated translation).
    void invert() {
        asm volatile(".set noreorder\n\tlq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\tpextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\tpcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\tqmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\tvmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
static inline void o287_apply(V287* d, const M287* m, const V287* v) {
    asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(m), "r"(v) : "memory");
}
extern u8* D_00361f60 asm("D_00361f60");
extern f32 D_00349e10 asm("D_00349e10");
s32 func_001c0cd8(void) asm("func_001c0cd8");
V287* func_0016c028(u8*) asm("func_0016c028");
// obj_get_attach_or_alt
u8* func_002d73f0(u8*) asm("func_002d73f0");
/*TARGET 002dbf50*/
f32 func_002dbf50(u8* a0) asm("func_002dbf50");
f32 func_002dbf50(u8* a0) {
    if (func_001c0cd8()) return 0.0f;
    u8* cam = D_00361f60;
    if (!cam) return 0.0f;
    *(f32*)(a0 + 2840) = 0.0f;
    M287 m = *(M287*)(cam + 336);
    m.invert();
    V287 p = *func_0016c028(a0);  // obj_get_attach_or_alt
    p.w = 1.0f;
    V287 r;
    o287_apply(&r, &m, &p);
    r.w = 1.0f;
    r.y = 0.0f;
    r.z = 0.0f;
    if (a0[3008]) {
        *(f32*)(a0 + 2840) = r.x + *(f32*)(a0 + 3024) * D_00349e10;
    } else if (*(f32*)(a0 + 3056) > r.y) {
        f32 s = *(f32*)(func_002d73f0(cam) + 48);
        f32 dt = D_00349e10;
        *(f32*)(a0 + 2840) = r.x + (a0[2844] ? s : -s) * dt;
        *(f32*)(a0 + 3056) -= D_00349e10;
    } else {
        *(f32*)(a0 + 2840) = r.x;
    }
    return *(f32*)(a0 + 2840);
}
}  // namespace n002dbf50

// 002dc100 (was src/anon/tiny_auto80_queue.cpp)
namespace n002dc100 {
u32 func_001c0cd8(...) asm("func_001c0cd8");
/*TARGET 002dc100*/
f32 func_002dc100(u32 a0) asm("_Z13func_002dc100j");
f32 func_002dc100(u32 a0) {
    if (func_001c0cd8(a0) != 0) {
        return 0.0f;
    }
    if (*(u8*)(a0 + 3008) == 0) {
        return 0.0f;
    }
    return -*(f32*)(a0 + 3044);
}
}  // namespace n002dc100

// 002dc140 (was src/anon/batch_w47.cpp)
namespace n002dc140 {
// 0x002bb3f0: definition moved into src/anon/unit_002bb070.cpp

void func_002d0bd8(u8*, u8*) asm("func_002d0bd8");
static inline void mcopy(void* d, void* s) {
    if (d != s) asm volatile("lq $8,0(%1)\n\tlq $9,16(%1)\n\tlq $10,32(%1)\n\tlq $11,48(%1)\n\tsq $8,0(%0)\n\tsq $9,16(%0)\n\tsq $10,32(%0)\n\tsq $11,48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
/*TARGET 002dc140*/
// Saves the current matrix (+2848) to +2912, loads m into it, then updates.
void func_002dc140(u8* p, u8* m) asm("func_002dc140");
// Saves the current matrix (+2848) to +2912, loads m into it, then updates.
void func_002dc140(u8* p, u8* m) {
    mcopy(p + 2912, p + 2848);
    mcopy(p + 2848, m);
    func_002d0bd8(p, m);
}
}  // namespace n002dc140

// 002dc1b0 (was src/ti/minigame_accessors.cpp)
namespace n002dc1b0 {
u8 is_separate_blow(Ti::MGHachimitsuPo* self) asm("_ZN2Ti14MGHachimitsuPo16is_separate_blowEv");
u8 is_separate_blow(Ti::MGHachimitsuPo* self) {
    return reinterpret_cast<Ti::MGHachimitsuPoLayout*>(self)->separate_blow;
}
}  // namespace n002dc1b0

// 002dc1b8 (was src/anon/batch_w50.cpp)
namespace n002dc1b8 {
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_001dc818(u32) asm("func_001dc818");
u32 func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
/*TARGET 002dc1b8*/
// 0x002cbca0: definition moved into src/taito/path.cpp

void func_002dc1b8(u8* o, s32 id) asm("func_002dc1b8");
// 0x002cbca0: definition moved into src/taito/path.cpp

void func_002dc1b8(u8* o, s32 id) {
    if (func_001c0cd8(o) || o[3008]) id = -1;
    u32 h = *(u32*)(o + 2828);
    if (h) {
        if (*(s32*)(o + 2836) == id) return;
        func_001dc818(h);
        *(u32*)(o + 2828) = 0;
    }
    if (id >= 0) *(u32*)(o + 2828) = func_0016ac38(o, id, 1, 0, 0);
    *(s32*)(o + 2836) = id;
}
}  // namespace n002dc1b8

// 00375d3c-00375d44: two constants in .rodata that no code in this file loads (300.0f is read by later files).
namespace r00375d3c {
extern "C" const f32 D_00375d3c = 0.0f;
extern "C" const f32 D_00375d40 = 300.0f;
}

// 002dc248 (was src/anon/batch_w203.cpp)
namespace n002dc248 {
struct W203Fl { u8 pad[0x70]; float f; };
W203Fl* w203_config(void) asm("_ZN2Ti6MGJump6configEv");
/*TARGET 002dc248*/
float func_002dc248(void) asm("func_002dc248");
float func_002dc248(void) { return -300.0f - w203_config()->f; }
}  // namespace n002dc248

// 002dc278 (was src/anon/batch_w34.cpp)
namespace n002dc278 {
void* func_001050d8(u32) asm("func_001050d8");
void func_002dc4e0(void*, u32, u32) asm("func_002dc4e0");
/*TARGET 002dc278*/
// 0x002c0470: definition moved into src/anon/unit_002bebd0.cpp

void func_002dc278(u32 a, u32 b) asm("func_002dc278");
// 0x002c0470: definition moved into src/anon/unit_002bebd0.cpp

void func_002dc278(u32 a, u32 b) {
    func_002dc4e0(func_001050d8(0x80a0), a, b);
}
}  // namespace n002dc278

// 00375d48: data file name read by the minigame setup functions above.
namespace r00375d48 {
extern const char D_00375d48_def[8] asm("D_00375d48") __attribute__((aligned(4))) = "po_08";
}

// 002dc2b8 (was src/anon/batch_w2040.cpp)
namespace n002dc2b8 {
struct W2040Ent { u32 a; u32 b; s32 v; };
struct W2040Obj {
    u8* vt;
    u8 pad04[0x58];
    s32 f5c;
    s32 f60;
    f32 f64, f68, f6c;
    s32 f70;
    s32 f74[3];
    s32 f80;
    u8 pad84[0x100 - 0x84];
    u8 m100[0x7e20 - 0x100];
    u8 m7e20[0x8060 - 0x7e20];
    u8 f8060;
    u8 pad8061[3];
    s32 f8064;
    u8 pad8068[0x10];
    u8 m8078[0x10];
};
void func_00102c80(void) asm("func_00102c80");
void func_00144450(void*) asm("func_00144450");
W2040Ent* func_00168b38(s32, s32, s32) asm("func_00168b38");
s32 func_0016b740(s32) asm("func_0016b740");
void func_0016bd60(s32, s32) asm("func_0016bd60");
s32 func_001708f8(char*, s32) asm("func_001708f8");
void func_002ce958(void*, s32, s32, s32) asm("func_002ce958");
void func_002ceae8(void*, char*, const char*) asm("func_002ceae8");
void func_002cedd0(s32, void*) asm("func_002cedd0");
s32 func_002dc7f8(void*) asm("func_002dc7f8");
void func_002dc850(void*) asm("func_002dc850");
void func_002e4a08(void*) asm("func_002e4a08");
void func_002e5f70(void*) asm("func_002e5f70");
void func_002e5fb8(void*, s32) asm("func_002e5fb8");
extern u8 D_00362990[] asm("D_00362990");
extern u8 D_003629e8[] asm("D_003629e8");
extern char D_00375d48[] asm("D_00375d48");
/*TARGET 002dc2b8*/
void func_002dc2b8(W2040Obj* self, s32 x, s32 y) asm("func_002dc2b8");
void func_002dc2b8(W2040Obj* self, s32 x, s32 y) {
    char buf[64];
    s32 i;
    s32 h;
    s32 t;
    s32 r;
    W2040Ent* e;
    u8* m;
    func_002ce958(self, 2, y, 160);
    m = self->m7e20;
    self->vt = D_003629e8;
    self->f64 = 0.34906584f;
    self->f68 = 2000.0f;
    self->f6c = 0.5f;
    self->f80 = x;
    func_002e4a08(self->m100);
    func_002e5f70(m);
    func_00144450(self->m8078);
    func_00102c80();
    func_002ceae8(self, buf, D_00375d48);
    h = func_001708f8(buf, -1);
    self->f60 = h;
    func_00168b38(h, 42, 0);
    self->f70 = func_00168b38(h, 42, 0)->v + 16;
    func_00168b38(h, 10, 0);
    t = func_00168b38(h, 10, 0)->v;
    self->f5c = func_00168b38(h, 42, self->f80 * 2 + 1)->v;
    e = func_00168b38(h, 42, self->f80 * 2 + 2);
    self->f8064 = e->v;
    {
        s32* p = self->f74;
        i = 0;
        do {
            *p = func_00168b38(h, 42, i + 9)->v;
            i++;
            p++;
        } while (i < 3);
    }
    func_002e5fb8(m, t);
    func_002dc850(self);
    func_002cedd0(5, D_00362990);
    self->f8060 = 0;
    func_0016bd60(func_002dc7f8(self), 30);
    r = func_0016b740(0x6a2);
    if (r != 0) func_0016bd60(r, 34);
    r = func_0016b740(0x6a3);
    if (r != 0) func_0016bd60(r, 35);
}
}  // namespace n002dc2b8

// 002dc4e0 (was src/anon/batch_w2040.cpp)
namespace n002dc4e0 {
struct W2040Ent { u32 a; u32 b; s32 v; };
struct W2040Obj {
    u8* vt;
    u8 pad04[0x58];
    s32 f5c;
    s32 f60;
    f32 f64, f68, f6c;
    s32 f70;
    s32 f74[3];
    s32 f80;
    u8 pad84[0x100 - 0x84];
    u8 m100[0x7e20 - 0x100];
    u8 m7e20[0x8060 - 0x7e20];
    u8 f8060;
    u8 pad8061[3];
    s32 f8064;
    u8 pad8068[0x10];
    u8 m8078[0x10];
};
void func_00102c80(void) asm("func_00102c80");
void func_00144450(void*) asm("func_00144450");
W2040Ent* func_00168b38(s32, s32, s32) asm("func_00168b38");
s32 func_0016b740(s32) asm("func_0016b740");
void func_0016bd60(s32, s32) asm("func_0016bd60");
s32 func_001708f8(char*, s32) asm("func_001708f8");
void func_002ce958(void*, s32, s32, s32) asm("func_002ce958");
void func_002ceae8(void*, char*, const char*) asm("func_002ceae8");
void func_002cedd0(s32, void*) asm("func_002cedd0");
s32 func_002dc7f8(void*) asm("func_002dc7f8");
void func_002dc850(void*) asm("func_002dc850");
void func_002e4a08(void*) asm("func_002e4a08");
void func_002e5f70(void*) asm("func_002e5f70");
void func_002e5fb8(void*, s32) asm("func_002e5fb8");
extern u8 D_00362990[] asm("D_00362990");
extern u8 D_003629e8[] asm("D_003629e8");
extern char D_00375d48[] asm("D_00375d48");
/*TARGET 002dc4e0*/
void func_002dc4e0(W2040Obj* self, s32 x, s32 y) asm("func_002dc4e0");
void func_002dc4e0(W2040Obj* self, s32 x, s32 y) {
    char buf[64];
    s32 i;
    s32 h;
    s32 t;
    s32 r;
    W2040Ent* e;
    u8* m;
    func_002ce958(self, 2, y, 160);
    m = self->m7e20;
    self->vt = D_003629e8;
    self->f64 = 0.34906584f;
    self->f68 = 2000.0f;
    self->f6c = 0.5f;
    self->f80 = x;
    func_002e4a08(self->m100);
    func_002e5f70(m);
    func_00144450(self->m8078);
    func_00102c80();
    func_002ceae8(self, buf, D_00375d48);
    h = func_001708f8(buf, -1);
    self->f60 = h;
    func_00168b38(h, 42, 0);
    self->f70 = func_00168b38(h, 42, 0)->v + 16;
    func_00168b38(h, 10, 0);
    t = func_00168b38(h, 10, 0)->v;
    self->f5c = func_00168b38(h, 42, self->f80 * 2 + 1)->v;
    e = func_00168b38(h, 42, self->f80 * 2 + 2);
    self->f8064 = e->v;
    {
        s32* p = self->f74;
        i = 0;
        do {
            *p = func_00168b38(h, 42, i + 9)->v;
            i++;
            p++;
        } while (i < 3);
    }
    func_002e5fb8(m, t);
    func_002dc850(self);
    func_002cedd0(5, D_00362990);
    self->f8060 = 0;
    func_0016bd60(func_002dc7f8(self), 30);
    r = func_0016b740(0x6a2);
    if (r != 0) func_0016bd60(r, 34);
    r = func_0016b740(0x6a3);
    if (r != 0) func_0016bd60(r, 35);
}
}  // namespace n002dc4e0

// 002dc708 (was src/anon/batch_w22.cpp)
namespace n002dc708 {
// --- 002dc708
extern u32 D_003629e8 asm("D_003629e8");
void func_002e4a90(void*) asm("func_002e4a90");
// in_even_range
u8 func_002cea28(void*) asm("func_002cea28");
/*TARGET 002dc708*/
u32 func_002dc708(void** p) asm("func_002dc708");
u32 func_002dc708(void** p) {
    *p = &D_003629e8;
    func_002e4a90(p + 64);  // in_even_range
    return func_002cea28(p);
}
}  // namespace n002dc708

// 002dc748 (was src/anon/batch_w23.cpp)
namespace n002dc748 {
extern u32 D_003629e8 asm("D_003629e8");
u8 func_002e4a90(void*) asm("func_002e4a90");
// in_even_range
u8 func_002cea28(void*) asm("func_002cea28");
/*TARGET 002dc748*/
s32 func_002dc748(void** p) asm("func_002dc748");
s32 func_002dc748(void** p) {
    *p = &D_003629e8;
    func_002e4a90((u8*)p + 256);  // in_even_range
    return func_002cea28(p);
}
}  // namespace n002dc748

// 002dc788 (was src/anon/batch_w35.cpp)
namespace n002dc788 {
// 0x002c5ff8: definition moved into src/anon/unit_002c53c8.cpp

extern u8 D_003629e8[] asm("D_003629e8");
void func_002e4a90(void*) asm("func_002e4a90");
// in_even_range
void func_002cea28(void*) asm("func_002cea28");
void func_00105110(void*) asm("func_00105110");
/*TARGET 002dc788*/
void func_002dc788(u8* p) asm("func_002dc788");
void func_002dc788(u8* p) {
    *(void**)p = D_003629e8;
    func_002e4a90(p + 256);  // in_even_range
    func_002cea28(p);
    func_00105110(p);
}
}  // namespace n002dc788

// 002dc7c8 (was src/taito/mg_jump.cpp)
namespace n002dc7c8 {
s32 config(Ti::MGJump* self) asm("_ZN2Ti6MGJump6configEv");
s32 config(Ti::MGJump* self) { return reinterpret_cast<Ti::MGJumpLayout*>(self)->configValue; }
}  // namespace n002dc7c8

// 002dc7d0 (was src/anon/tiny_wrappers_more.cpp)
namespace n002dc7d0 {
u32 func_002cebc0(u32, u32, u32, u32) asm("_Z13func_002cebc0jjjj");
/*TARGET 002dc7d0*/
u32 func_002dc7d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002dc7d0jjjj");
u32 func_002dc7d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002cebc0(a0, a1, a2, a3);
}
}  // namespace n002dc7d0

// 002dc7e8 (was src/anon/tiny.cpp)
namespace n002dc7e8 {
/*TARGET 002dc7e8*/
u32 func_002dc7e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002dc7e8jjjj");
u32 func_002dc7e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)((s32)a0 + (256));
}
}  // namespace n002dc7e8

// 002dc7f8 (was src/anon/tiny.cpp)
namespace n002dc7f8 {
/*TARGET 002dc7f8*/
// 0x002d1260: definition moved into src/anon/unit_002cf260.cpp

u32 func_002dc7f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002dc7f8jjjj");
// 0x002d1260: definition moved into src/anon/unit_002cf260.cpp

u32 func_002dc7f8(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_35e958
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0035u << 16);
    return (u32)(*(u32*)((u32)b + (-5816)));
}
}  // namespace n002dc7f8

// 002dc808 (was src/anon/batch_w31.cpp)
namespace n002dc808 {
u8* func_002dc7c8(void*) asm("func_002dc7c8");
/*TARGET 002dc808*/
f32 func_002dc808(u8* p) asm("func_002dc808");
f32 func_002dc808(u8* p) {
    if (*(u32*)(p + 0x8070)) return *(f32*)(func_002dc7c8(p) + 180);
    return *(f32*)func_002dc7c8(p);
}
}  // namespace n002dc808

// 002dc850 (was src/anon/batch_w2386.cpp)
namespace n002dc850 {
struct V4_2386 {
    f32 x, y, z, w;
};
struct Box2386 {
    s32 w[6];
};
// Pooh honey minigame object: only the fields touched by func_002dc850.
struct HoneyGame2386 {
    u8 pad0[0x88];
    s32 f88;
    s32 f8c;
    s32 f90;
    u8 pad94[0xd4 - 0x94];
    f32 fd4;
    f32 fd8;
    u8 paddc[0x100 - 0xdc];
    u8 rope[0x8068 - 0x100];  // passed to func_002e4af8
    f32 f8068;
    u8 f806c;
    s32 f8070;
    s32 f8074;
    Box2386 box;
    u8 f8090;
};
void Aabbox_2386(Box2386*, const V4_2386*, const V4_2386*) asm("_ZN2dk6AabboxC1ERKN2kn7FVectorES4_");
void setHideGroup_2386(u32 g) asm("_ZN2dk3Map12setHideGroupEj");
void func_002e4af8(void*) asm("func_002e4af8");
/*TARGET 002dc850*/
// 002dc850: reset the honey minigame state: rebuild the area box, hide map group 2, clear the counters.
void func_002dc850(HoneyGame2386* p) asm("func_002dc850");
// 002dc850: reset the honey minigame state: rebuild the area box, hide map group 2, clear the counters.
void func_002dc850(HoneyGame2386* p)
{
    Box2386* d = &p->box;
    V4_2386 a;
    V4_2386 b;
    Box2386 r;
    a.x = 900.0f;
    a.y = 200.0f;
    a.z = 2000.0f;
    b.x = -900.0f;
    b.y = -6000.0f;
    b.z = -2000.0f;
    f32 z = 0.0f;
    b.w = a.w = z;
    Aabbox_2386(&r, &b, &a);
    *d = r;
    p->f8090 = 0;
    setHideGroup_2386(2);
    p->fd4 = z;
    p->f8068 = z;
    p->fd8 = -1.0f;
    p->f8c = 0;
    p->f88 = 0;
    p->f90 = 0;
    p->f806c = 0;
    p->f8074 = 0;
    p->f8070 = 0;
    func_002e4af8(p->rope);
}
}  // namespace n002dc850

// 002dc988 (was src/anon/batch_w3911_nsa.cpp)
namespace n002dc988 {
#define W2dc988_QCOPY(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
struct W2dc988Vec {
    f32 x, y, z, w;
    W2dc988Vec() {}
    W2dc988Vec(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    void AddXYZ(const W2dc988Vec& b) { asm volatile(".set noreorder\n\tlqc2 $vf1, %0\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0\n\t.set reorder" : "+m"(*this) : "r"(&b) : "memory"); }
    W2dc988Vec(const W2dc988Vec& o) { W2dc988_QCOPY(this, &o); }
    W2dc988Vec& operator=(const W2dc988Vec& o) { if (this != &o) W2dc988_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W2dc988Mtx {
    W2dc988Vec r0, r1, r2, r3;
    W2dc988Mtx() {}
    W2dc988Mtx(const W2dc988Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W2dc988Mtx& operator=(const W2dc988Mtx& o) {
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
    W2dc988Mtx operator*(const W2dc988Mtx& r) const
    {
        W2dc988Mtx d;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                     : : "r"(&d), "r"(this), "r"(&r) : "memory");
        return d;
    }
    // VU0 matrix * column vector.
    W2dc988Vec operator*(const W2dc988Vec& v) const {
        W2dc988Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Box2dc988 {
    W2dc988Vec min, max;
    Box2dc988(const W2dc988Vec& a, const W2dc988Vec& b);
};
void o2dc988_box(Box2dc988*, const W2dc988Vec&, const W2dc988Vec&) asm("_ZN2dk6AabboxC1ERKN2kn7FVectorES4_");
inline Box2dc988::Box2dc988(const W2dc988Vec& a, const W2dc988Vec& b) { o2dc988_box(this, a, b); }
struct Cam2dc988 { u32 vt; u8 pad[12]; W2dc988Mtx m; };
struct O2dc988 { u8 pad0[256]; u8 draw[32288 - 256]; u8 tex[0x8050 - 32288]; u64 gs; };
s32 o2dc988_visible(O2dc988*, Box2dc988*) asm("_ZN2Ti8MiniGame15bbox_is_visibleERKN2dk6AabboxE");
Cam2dc988* func_00106a60(s32) asm("func_00106a60");
W2dc988Mtx* func_00106a18(s32) asm("func_00106a18");
void func_0011b6a8(W2dc988Mtx*) asm("func_0011b6a8");
void o2dc988_rotateX(W2dc988Mtx*, f32) asm("_ZN2kn7FMatrix7rotateXEf");
s32 func_001344f8(void) asm("func_001344f8");
void func_002e6210(void*, s32, s32) asm("func_002e6210");
void func_002e5518(void*, W2dc988Mtx*, s32, u64) asm("func_002e5518");
/*TARGET 002dc988*/
// Minigame pot marker draw: skip when the bounding box is off screen, then
// draw with proj * camera * (translate(0,300,0) * rotateX(pi)).
void func_002dc988(s32 arg) asm("_Z13func_002dc988i");
// Minigame pot marker draw: skip when the bounding box is off screen, then
// draw with proj * camera * (translate(0,300,0) * rotateX(pi)).
void func_002dc988(s32 arg)
{
    O2dc988* o = (O2dc988*)arg;
    {
    W2dc988Vec mx(1000.0f, 20.0f, 1000.0f, 0.0f);
    W2dc988Vec mn(-1000.0f, -20.0f, -1000.0f, 0.0f);
    Box2dc988 box(mn, mx);
    W2dc988Mtx m;
    W2dc988Vec& t = m.r3;
    func_0011b6a8(&m);
    t = W2dc988Vec(0.0f, -300.0f, 0.0f, 0.0f);
    if (!o2dc988_visible(o, &box)) return;
    }
    Cam2dc988* cam = func_00106a60(1);
    W2dc988Mtx* pr = func_00106a18(1);
    W2dc988Mtx r;
    func_0011b6a8(&r);
    W2dc988Vec off(0.0f, 300.0f, 0.0f, 1.0f);
    W2dc988Vec unused; // never used; the original frame keeps a slot for it
    r.r3.AddXYZ(off);
    W2dc988Mtx p = *pr * cam->m;
    o2dc988_rotateX(&r, 3.1415927f);
    p = p * r;
    s32 tex = func_001344f8();
    func_002e6210(o->tex, tex, 0x3500);
    func_002e5518(o->draw, &p, tex, o->gs);
}
}  // namespace n002dc988

// 002dcc38 (was never written: gap function)
namespace n002dcc38 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8 D_00362858 asm("D_00362858");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362690[] asm("D_00362690");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016b070(u8*, V*) asm("func_0016b070");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002d0d48(u8*) asm("func_002d0d48");
void func_0019fdc0(u8*, V*, f32) asm("func_0019fdc0");
void func_002d9208(u8*, u8*) asm("func_002d9208");
void func_002e7568(u8*, s32, u8*, f32) asm("func_002e7568");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
struct Z { f32 x, y, z, w; void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); } } __attribute__((aligned(16)));
struct B { u8 pad[0x8078]; f32 mn[3]; f32 mx[3]; };

void func_002dcc38(void) asm("func_002dcc38");
void func_002dcc38(void) {}
}  // namespace n002dcc38

// 002dcc40 (was never written: gap function)
namespace n002dcc40 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8 D_00362858 asm("D_00362858");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362690[] asm("D_00362690");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016b070(u8*, V*) asm("func_0016b070");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002d0d48(u8*) asm("func_002d0d48");
void func_0019fdc0(u8*, V*, f32) asm("func_0019fdc0");
void func_002d9208(u8*, u8*) asm("func_002d9208");
void func_002e7568(u8*, s32, u8*, f32) asm("func_002e7568");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
struct Z { f32 x, y, z, w; void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); } } __attribute__((aligned(16)));
struct B { u8 pad[0x8078]; f32 mn[3]; f32 mx[3]; };

s32 func_002dcc40(u8* p, s32 v) asm("func_002dcc40");
s32 func_002dcc40(u8* p, s32 v) {
    struct S { u8 pad[144]; s32 a[16]; };
    S* o = (S*)p;
    s32 i;
    for (i = 0; o->a[i] != 0 && i < 16; i++)
        if (o->a[i] == v) return 1;
    return 0;
}
}  // namespace n002dcc40

// 002dcc90 (was src/anon/batch_w1983_nsa.cpp)
namespace n002dcc90 {
struct H_w1983 { char p[0x8064]; s32 h; char p2[0x8074 - 0x8068]; s32 v74; char p3[0x8090 - 0x8078]; u8 b90; };
struct O_w1983 {
    char p0[0x58]; u8 b58; char p1[0x88 - 0x59]; s32 v88; s32 v8c; s32 arr[17]; f32 fd4; f32 fd8;
};
struct Q_w1983 { char p[0x8c]; s32 v8c; };
Q_w1983* func_002dc7c8(void*) asm("func_002dc7c8");
s32 func_002ceb28(void) asm("func_002ceb28");
s32 func_00197920(void) asm("func_00197920");
s32 func_002e33d8(s32, s32, s32) asm("func_002e33d8");
s32 func_002e33f8(s32, s32, s32) asm("func_002e33f8");
s32 func_002e3318(s32, s32*, s32, s32, s32, s32) asm("func_002e3318");
void func_002cf938(s32) asm("func_002cf938");
void func_002cfb30(void) asm("func_002cfb30");
extern f32 D_00349e10 asm("D_00349e10");
#define HH_w1983(o) ((H_w1983*)(o))
/*TARGET 002dcc90*/
void func_002dcc90(int arg) asm("_Z13func_002dcc90i");
void func_002dcc90(int arg)
{
    O_w1983* o = (O_w1983*)arg;
    o->b58 = 1;
    if (HH_w1983(o)->v74 >= func_002dc7c8(o)->v8c) o->v88 = 1;
    else o->v88 = 0;
    if (!func_002ceb28()) return;
    if (func_00197920()) return;
    {
        f32 k = 60.0f;
        s32 idx = (s32)(o->fd4 / k);
        if (o->fd8 / k < (f32)idx) {
            s32 r = func_002e33d8(HH_w1983(o)->h, idx, o->v8c);
            if (r >= 0) {
                idx = r;
                o->fd4 = (f32)r * k;
            }
            r = func_002e33f8(HH_w1983(o)->h, idx, o->v8c);
            if (r >= 0) {
                idx = r;
                o->v8c = 0;
                HH_w1983(o)->b90 = 0;
                o->fd4 = (f32)r * k;
            }
            s32 n = func_002e3318(HH_w1983(o)->h, o->arr, 16, idx, o->v88, o->v8c);
            o->arr[n] = 0;
            if (n) {
                if (HH_w1983(o)->b90) {
                    s32 j;
                    for (j = 0; j < n; j++) {
                        s32 w = o->arr[j];
                        if (w != 0 && (w & 0xffffff) != 0x315f6d) {
                            HH_w1983(o)->b90 = 0;
                            break;
                        }
                    }
                }
                func_002cf938(0);
            }
            o->arr[0] = 0;
        }
        func_002cfb30();
        o->fd8 = o->fd4;
        o->fd4 += D_00349e10;
    }
}
}  // namespace n002dcc90

// 002dce80 (was src/anon/batch_w201.cpp)
namespace n002dce80 {
void wtarget_002dce80(u32, u32, u32, u32) asm("_Z16wtarget_002dce80jjjj");
extern void func_002e5350(void*, s32, f32) asm("func_002e5350");
/*TARGET 002dce80*/
// 002ead48: moved to src/anon/unit_002eaa68.cpp
void wtarget_002dce80(u32 a, u32, u32, u32) asm("_Z16wtarget_002dce80jjjj");
// 002ead48: moved to src/anon/unit_002eaa68.cpp
void wtarget_002dce80(u32 a, u32, u32, u32) { func_002e5350((u8*)a + 256, 20, 0.0199999996f); }
}  // namespace n002dce80

// 002dcea8 (was src/anon/batch_w1665.cpp)
namespace n002dcea8 {
// 002cebc0: moved to src/taito/minigame_base.cpp (linked unit)
void wt_2dcea8(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002dcea8jjjj");
/*TARGET 002dcea8*/
void wt_2dcea8(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002dcea8jjjj");
void wt_2dcea8(u32 a, u32 b, u32 c, u32 d) {}
}  // namespace n002dcea8

// 002dceb0 (was src/anon/batch_w41.cpp)
namespace n002dceb0 {
// 0x002d0fb0: definition moved into src/anon/unit_002cf260.cpp

u8* func_002dc7c8(u8*) asm("func_002dc7c8");
/*TARGET 002dceb0*/
f32 func_002dceb0(u8* p) asm("func_002dceb0");
f32 func_002dceb0(u8* p) {
    u8* q = p + 0x8000;
    u8* r = func_002dc7c8(p);
    f32 f = *(f32*)(q + 104) / *(f32*)(r + 160);
    if (f > 1.0f) f = 1.0f;
    if (f < 0.0f) f = 0.0f;
    return f;
}
}  // namespace n002dceb0

// 002dcf18 (was src/anon/batch_w3707.cpp)
namespace n002dcf18 {
typedef struct JumpCfg { u8 pad[0xa0]; f32 max; } JumpCfg;
JumpCfg* MGJump_config(u8* self) asm("_ZN2Ti6MGJump6configEv");
extern f32 D_00349e10 asm("D_00349e10");
/* 1.0f */
typedef struct JS { u8 pad[0x68]; f32 v; u8 flag; } JS;
/*TARGET 002dcf18*/
/* Ramp a value up toward the jump config's maximum, or back down to 0, by 1.0 per call. */
void func_002dcf18(u8* a0) asm("func_002dcf18");
void func_002dcf18(u8* a0) {
    JS* s = (JS*)(a0 + 0x8000);
    if (s->flag) {
        if (s->v < MGJump_config(a0)->max) s->v = s->v + D_00349e10;
    } else {
        if (s->v > 0.0f) s->v = s->v - D_00349e10;
    }
}
}  // namespace n002dcf18

// 002dcf90 (was src/anon/batch_w109.cpp)
namespace n002dcf90 {
// 0x002a92d8: definition moved into src/anon/unit_002a92a0.cpp

// ---- f21.cpp
struct V4dcf90 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct V3dcf90 { f32 x, y, z; };
void func_002dcf90_i(u8* self) asm("_Z13func_002dcf90i");
void func_002dcf18(u8*) asm("func_002dcf18");
s32 func_002dc7f8(u8*) asm("func_002dc7f8");
// get_global_35e958
s32 func_00106a18(s32) asm("func_00106a18");
// buffer_get_256
void func_00106de8(s32, s32, f32) asm("func_00106de8");
void func_00106c08(s32) asm("func_00106c08");
s32 func_00106a60(s32) asm("func_00106a60");
// buffer_get_by_index
V4dcf90* func_0016c028(s32) asm("func_0016c028");
// obj_get_attach_or_alt
u8* func_002dc7c8(u8*) asm("func_002dc7c8");
f32 func_002dceb0(u8*) asm("func_002dceb0");
f32 sinf(f32) asm("sinf");
f32 cosf(f32) asm("cosf");
void func_00107340_c(s32, f32, f32, f32) asm("_ZN2kn6Camera12setReferenceEfff");
void func_00107330_c(s32, f32, f32, f32) asm("_ZN2kn6Camera11setPositionEfff");
/*TARGET 002dcf90*/
// Sets the view reference point and orbit position from the interpolated angle.
void func_002dcf90_i(u8* self) asm("_Z13func_002dcf90i");
// Sets the view reference point and orbit position from the interpolated angle.
void func_002dcf90_i(u8* self) {
    V3dcf90 ref;
    V3dcf90 pos;
    func_002dcf18(self);
    if (self[0x8000 + 96]) return;
    if (!func_002dc7f8(self)) return;
    V4dcf90 v;
    V4dcf90* dst = &v;
    s32 m = func_00106a18(1);  // buffer_get_256
    func_00106de8(m, 1, *(f32*)(self + 100));
    func_00106c08(m);
    s32 cam = func_00106a60(1);  // buffer_get_by_index
    pos.z = 0.0f;
    V4dcf90* src = func_0016c028(func_002dc7f8(self));  // obj_get_attach_or_alt
    // 128-bit copy of the source position (lq/sq through t0).
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    ref.z = 0.0f;
    f32 y = v.y + 300.0f;
    ref.y = y - 80.0f;
    u8* p1 = func_002dc7c8(self);
    u8* p0 = func_002dc7c8(self);
    f32 t = func_002dceb0(self);
    f32 lo = *(f32*)(p0 + 168);
    f32 ang = (*(f32*)(p1 + 164) - lo) * t + lo;
    pos.y = y - sinf(ang) * *(f32*)(self + 104);
    pos.z = -cosf(ang) * *(f32*)(self + 104);
    ref.x = pos.x = v.x * *(f32*)(self + 108);
    ref.y -= 300.0f;
    pos.y -= 300.0f;
    func_00107340_c(cam, ref.x, ref.y, ref.z);
    func_00107330_c(cam, pos.x, pos.y, pos.z);
}
}  // namespace n002dcf90

// 002dd140 (was src/anon/batch_w1757_g.cpp)
namespace n002dd140 {
struct W1757Msg { s16 h[5]; };
extern W1757Msg D_0032bae0 asm("D_0032bae0");
void func_00195750(void) asm("func_00195750");
void func_00104f58(W1757Msg*, s32, s32, s32, s32) asm("func_00104f58");
/*TARGET 002dd140*/
void func_002dd140(void) asm("func_002dd140");
void func_002dd140(void) {
    W1757Msg m = D_0032bae0;
    func_00195750();
    func_00104f58(&m, 1, 0, 0, 0);
}
}  // namespace n002dd140

// 002dd198 (was src/anon/tiny.cpp)
namespace n002dd198 {
void func_002dcc90(s32) asm("_Z13func_002dcc90i");
/*TARGET 002dd198*/
// 0x002d8d28: definition moved into src/anon/unit_002d6f70.cpp
void func_002dd198(BD_VALUE* bd) asm("_Z13func_002dd198P8BD_VALUE");
// 0x002d8d28: definition moved into src/anon/unit_002d6f70.cpp
void func_002dd198(BD_VALUE* bd) { func_002dcc90(bd[1].i); }
}  // namespace n002dd198

// 002dd1b0 (was src/anon/tiny_wrappers_more.cpp)
namespace n002dd1b0 {
u32 func_002dce80(u32, u32, u32, u32) asm("_Z13func_002dce80jjjj");
/*TARGET 002dd1b0*/
u32 func_002dd1b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002dd1b0jjjj");
u32 func_002dd1b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002dce80(((u32)(*(u32*)((u32)(a0) + 4u))), a1, a2, a3);
}
}  // namespace n002dd1b0

// 002dd1c8 (was never written: gap function)
namespace n002dd1c8 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8 D_00362858 asm("D_00362858");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362690[] asm("D_00362690");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016b070(u8*, V*) asm("func_0016b070");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002d0d48(u8*) asm("func_002d0d48");
void func_0019fdc0(u8*, V*, f32) asm("func_0019fdc0");
void func_002d9208(u8*, u8*) asm("func_002d9208");
void func_002e7568(u8*, s32, u8*, f32) asm("func_002e7568");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
struct Z { f32 x, y, z, w; void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); } } __attribute__((aligned(16)));
struct B { u8 pad[0x8078]; f32 mn[3]; f32 mx[3]; };

void func_002dd1c8(void) asm("func_002dd1c8");
void func_002dd1c8(void) {}
}  // namespace n002dd1c8

// 002dd1d0 (was src/anon/tiny_wrappers_more.cpp)
namespace n002dd1d0 {
u32 func_002dcea8(u32, u32, u32, u32) asm("_Z13func_002dcea8jjjj");
/*TARGET 002dd1d0*/
u32 func_002dd1d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002dd1d0jjjj");
u32 func_002dd1d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002dcea8(((u32)(*(u32*)((u32)(a0) + 4u))), a1, a2, a3);
}
}  // namespace n002dd1d0

// 002dd1e8 (was src/anon/tiny.cpp)
namespace n002dd1e8 {
void func_002dc988(s32) asm("_Z13func_002dc988i");
/*TARGET 002dd1e8*/
void func_002dd1e8(BD_VALUE* bd) asm("_Z13func_002dd1e8P8BD_VALUE");
void func_002dd1e8(BD_VALUE* bd) { func_002dc988(bd[1].i); }
}  // namespace n002dd1e8

// 002dd200 (was src/anon/tiny.cpp)
namespace n002dd200 {
void func_002dcf90(s32) asm("_Z13func_002dcf90i");
/*TARGET 002dd200*/
void func_002dd200(BD_VALUE* bd) asm("_Z13func_002dd200P8BD_VALUE");
void func_002dd200(BD_VALUE* bd) { func_002dcf90(bd[1].i); }
}  // namespace n002dd200

// 002dd218 (was src/anon/batch_w202.cpp)
namespace n002dd218 {
extern float func_002e50f8(u8*) asm("func_002e50f8");
/*TARGET 002dd218*/
// 0x001b5878: definition moved into src/anon/unit_001b2780.cpp
float func_002dd218(u8* a) asm("func_002dd218");
// 0x001b5878: definition moved into src/anon/unit_001b2780.cpp
float func_002dd218(u8* a) { return -(func_002e50f8(a+256) + 300.0f); }
}  // namespace n002dd218

// 002dd248 (was never written: gap function)
namespace n002dd248 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8 D_00362858 asm("D_00362858");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362690[] asm("D_00362690");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016b070(u8*, V*) asm("func_0016b070");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002d0d48(u8*) asm("func_002d0d48");
void func_0019fdc0(u8*, V*, f32) asm("func_0019fdc0");
void func_002d9208(u8*, u8*) asm("func_002d9208");
void func_002e7568(u8*, s32, u8*, f32) asm("func_002e7568");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
struct Z { f32 x, y, z, w; void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); } } __attribute__((aligned(16)));
struct B { u8 pad[0x8078]; f32 mn[3]; f32 mx[3]; };

s32 func_002dd248(void) asm("func_002dd248");
s32 func_002dd248(void) { return 1; }
}  // namespace n002dd248

// 002dd250 (was src/anon/tiny_auto80_queue.cpp)
namespace n002dd250 {
u32 func_002dc7c8(...) asm("func_002dc7c8");
/*TARGET 002dd250*/
f32 func_002dd250(u32 a0, u32 a1) asm("_Z13func_002dd250jj");
f32 func_002dd250(u32 a0, u32 a1) {
    (void)a0;
    u32 s0 = a1;
    u32 p = func_002dc7c8();
    s0 <<= 2;
    s0 = s0 + p;
    return *(f32*)(s0 + 16);
}
}  // namespace n002dd250

// 002dd280 (was src/anon/tiny_auto80_queue.cpp)
namespace n002dd280 {
u32 func_002dc7c8(...) asm("func_002dc7c8");
/*TARGET 002dd280*/
f32 func_002dd280(u32 a0, u32 a1) asm("_Z13func_002dd280jj");
f32 func_002dd280(u32 a0, u32 a1) {
    (void)a0;
    u32 s0 = a1;
    u32 p = func_002dc7c8();
    s0 <<= 2;
    s0 = s0 + p;
    return *(f32*)(s0 + 64);
}
}  // namespace n002dd280

// 002dd2b0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002dd2b0 {
u32 func_002dc7c8(...) asm("func_002dc7c8");
/*TARGET 002dd2b0*/
f32 func_002dd2b0() asm("_Z13func_002dd2b0v");
f32 func_002dd2b0() {
    u32 p = func_002dc7c8();
    return *(f32*)(p + 116);
}
}  // namespace n002dd2b0

// 002dd2d0 (was never written: gap function)
namespace n002dd2d0 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8 D_00362858 asm("D_00362858");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362690[] asm("D_00362690");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016b070(u8*, V*) asm("func_0016b070");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002d0d48(u8*) asm("func_002d0d48");
void func_0019fdc0(u8*, V*, f32) asm("func_0019fdc0");
void func_002d9208(u8*, u8*) asm("func_002d9208");
void func_002e7568(u8*, s32, u8*, f32) asm("func_002e7568");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
struct Z { f32 x, y, z, w; void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); } } __attribute__((aligned(16)));
struct B { u8 pad[0x8078]; f32 mn[3]; f32 mx[3]; };

f32 func_002dd2d0(void) asm("func_002dd2d0");
f32 func_002dd2d0(void) { return 0.0f; }
}  // namespace n002dd2d0

// 002dd2d8 (was src/anon/batch_w41.cpp)
namespace n002dd2d8 {
f32 func_002e4af0(u8*) asm("func_002e4af0");
/*TARGET 002dd2d8*/
void func_002dd2d8(u8* p, f32* a, f32* b) asm("func_002dd2d8");
void func_002dd2d8(u8* p, f32* a, f32* b) {
    f32 f = (func_002e4af0(p + 256) * 0.5f - 1.0f) * 100.0f;
    *b = f;
    *a = -f;
}
}  // namespace n002dd2d8

// 002dd348 (was src/anon/tiny_auto80_queue.cpp)
namespace n002dd348 {
void func_002dd2d8(...) asm("func_002dd2d8");
/*TARGET 002dd348*/
f32 func_002dd348(u32 a0, f32 a1) asm("_Z13func_002dd348jf");
f32 func_002dd348(u32 a0, f32 a1) {
    f32 lo;
    f32 hi;
    f32 x = a1;

    func_002dd2d8(a0, (u32)&lo, (u32)&hi);

    if (hi < x) {
        x = hi;
    }
    if (x < lo) {
        x = lo;
    }
    return x;
}
}  // namespace n002dd348

// 002dd398 (was never written: gap function)
namespace n002dd398 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8 D_00362858 asm("D_00362858");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362690[] asm("D_00362690");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016b070(u8*, V*) asm("func_0016b070");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002d0d48(u8*) asm("func_002d0d48");
void func_0019fdc0(u8*, V*, f32) asm("func_0019fdc0");
void func_002d9208(u8*, u8*) asm("func_002d9208");
void func_002e7568(u8*, s32, u8*, f32) asm("func_002e7568");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
struct Z { f32 x, y, z, w; void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); } } __attribute__((aligned(16)));
struct B { u8 pad[0x8078]; f32 mn[3]; f32 mx[3]; };

s32 func_002dd398(void) asm("func_002dd398");
s32 func_002dd398(void) { return 1; }
}  // namespace n002dd398

// 002dd3a0 (was src/anon/batch_w1783.cpp)
namespace n002dd3a0 {
// 0x002bb468: definition moved into src/anon/unit_002bb070.cpp

// ---- 002dd3a0
struct S24c { u32 a, b, c, d, e, f; };
struct SubE { S24c v; const S24c& ref() const { return v; } };
struct DE { u8 _0[0x740]; SubE m740; u8 _758[0xaf0 - 0x758]; u8 maf0[4]; };
bool fpv(u32, S24c) asm("func_00144d10");
s32 func_002cf270(u32, s32) asm("func_002cf270");
void func_002cf280(u32, s32, s32) asm("func_002cf280");
/*TARGET 002dd3a0*/
bool func_002dd3a0(u32 a0, DE* a1) asm("func_002dd3a0");
bool func_002dd3a0(u32 a0, DE* a1) {
    bool r = fpv(a0 + 0x8078, a1->m740.ref());
    bool ret;
    if (!func_002cf270((u32)a1->maf0, 2)) { if (r) func_002cf280((u32)a1->maf0, 2, 0); ret = false; }
    else ret = !r;
    return ret;
}
}  // namespace n002dd3a0

// 002dd448 (was src/anon/batch_w42.cpp)
namespace n002dd448 {
void mission_add_count(s32, s32) asm("_ZN2YS7MISSION8AddCountEii");
// 0x002d6d10: definition moved into src/anon/unit_002d62d0.cpp

// 002dd448: add score (10/5/1 per rank) to the mission counter
struct Score3 { s32 v[3]; };
extern const Score3 D_00375dc8 asm("D_00375dc8") __attribute__((aligned(4))) = { { 10, 5, 1 } };
/*TARGET 002dd448*/
void func_002dd448(u8* p, s32 mul, s32 idx) asm("func_002dd448");
void func_002dd448(u8* p, s32 mul, s32 idx)
{
    Score3 t = D_00375dc8;
    if (*(s32*)(p + 128) == 2) mission_add_count(t.v[idx] * mul, 0);
}
}  // namespace n002dd448

// 002dd4a8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002dd4a8 {
void func_001d9050(u32, u32, f32) asm("_Z13func_001d9050jjf");
/*TARGET 002dd4a8*/
void func_002dd4a8(u32 a0, u32 a1) asm("_Z13func_002dd4a8jj");
void func_002dd4a8(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    func_001d9050(s1, 0, 0.0f);

    u32 t6 = 0x8000;
    s0 = s0 + t6;

    u32 v = *(u32*)(s0 + 116);
    v = v + s1;
    *(u32*)(s0 + 116) = v;
}
}  // namespace n002dd4a8

// 002dd4f8 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n002dd4f8 {
u32 YS_MISSION_ResetComboCounter(u32, u32, u32, u32) asm("_ZN2YS7MISSION17ResetComboCounterEi");
/*TARGET 002dd4f8*/
// 0x002d8120: definition moved into src/anon/unit_002d6f70.cpp

u32 func_002dd4f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002dd4f8jjjj");
// 0x002d8120: definition moved into src/anon/unit_002d6f70.cpp

u32 func_002dd4f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r4 = 0u;
    r2 = YS_MISSION_ResetComboCounter(r4, r5, r6, r7);
    r15 = (u32)(0u | 0x8000u);
    r16 = (u32)(r16 + r15);
    *(u32*)((u32)r16 + (s32)(116)) = 0u;
    return r2;
}
}  // namespace n002dd4f8

// 002dd530 (was src/anon/batch_w1794.cpp)
namespace n002dd530 {
struct W1794_S0 { u8 pad0[0x8C]; s32 a; s32 b; u8 pad1[0xD4-0x94]; s32 c; f32 d; u8 pad2[0x8090-0xDC]; s8 e; };
s32 func_0016a060(void *) asm("func_0016a060");
s32 func_0019c768(void *) asm("func_0019c768");
void *func_001b9bc8(void *) asm("func_001b9bc8");
void func_002cf280(void *, s32, s32) asm("func_002cf280");
/*TARGET 002dd530*/
void func_002dd530(W1794_S0 *arg0, s32 arg1) asm("func_002dd530");
void func_002dd530(W1794_S0 *arg0, s32 arg1) {
    u8 *p;
    arg0->a = arg1;
    arg0->b = 0;
    arg0->c = 0;
    arg0->e = 1;
    p = 0;
    arg0->d = -1.0f;
    while ((p = (u8*)func_001b9bc8(p)) != 0) {
        if ((*(s32*)(p + 0x588) & 0x08000000) && func_0019c768(p) == 0 && func_0016a060(p) == 0x16) {
            func_002cf280(p + 0xAF0, 4, 0);
        }
    }
}
}  // namespace n002dd530

// 002dd5f0 (was never written: gap function)
namespace n002dd5f0 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8 D_00362858 asm("D_00362858");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362690[] asm("D_00362690");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016b070(u8*, V*) asm("func_0016b070");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002d0d48(u8*) asm("func_002d0d48");
void func_0019fdc0(u8*, V*, f32) asm("func_0019fdc0");
void func_002d9208(u8*, u8*) asm("func_002d9208");
void func_002e7568(u8*, s32, u8*, f32) asm("func_002e7568");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
struct Z { f32 x, y, z, w; void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); } } __attribute__((aligned(16)));
struct B { u8 pad[0x8078]; f32 mn[3]; f32 mx[3]; };

s32 func_002dd5f0(u8* p, f32* v) asm("func_002dd5f0");
s32 func_002dd5f0(u8* p, f32* v)
{
    B* b = (B*)p;
    return !(b->mn[0] <= v[0] && v[0] <= b->mx[0] && b->mn[1] <= v[1] && v[1] <= b->mx[1]);
}
}  // namespace n002dd5f0

