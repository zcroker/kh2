// Linked unit 0x00131418-0x00133c90 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"

// 00131418 (was unwritten gap)
namespace n00131418 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    u32 v[4];
    QWord& operator=(const QWord& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct C { u8 pad[112]; QWord a; QWord b; };
struct O { u32 x0; C* c; };
void func_00131418(O* o, QWord* a, QWord* b) asm("func_00131418");
void func_00131418(O* o, QWord* a, QWord* b) { C* c = o->c; *a = c->a; *b = c->b; }
#undef QCOPY
}  // namespace

// 00131450 (was src/anon/batch_w2043.cpp)
namespace n00131450 {
struct W2043c_Vq { f32 x, y, z, w; W2043c_Vq() {} W2043c_Vq(f32 a, f32 b, f32 c, f32 e) { x = a; y = b; z = c; w = e; } } __attribute__((aligned(16)));
struct W2043c_Mat { W2043c_Vq r[4]; };
struct W2043c_Dat { u8 p0[0x2c]; s32 f2c; s32 f30; s32 f34; s32 f38; u8 p1[0x90 - 0x3c]; f32 f90; f32 f94; f32 f98; };
struct W2043c_Obj { u8 p0[4]; W2043c_Dat* d; };
void func_0011b6a8(W2043c_Mat*) asm("func_0011b6a8");
void func_001285f8(W2043c_Obj*, s32*, s32*, f32) asm("func_001285f8");
f32 func_00128750(W2043c_Obj*, void*, s32, s32, f32) asm("func_00128750");
void func_0011b6d8(W2043c_Mat*, f32) asm("func_0011b6d8");
void func_0011b720(W2043c_Mat*, f32) asm("func_0011b720");
void func_0011b768(W2043c_Mat*, f32) asm("func_0011b768");
static inline void W2043c_m_trans(W2043c_Mat* m, W2043c_Vq* v) {
    asm volatile("lqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)" : : "r"(m), "r"(v) : "memory");
}
static inline void W2043c_m_scale(W2043c_Mat* m, W2043c_Vq* v) {
    asm volatile("lqc2 $vf4, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tvmulx.wxyz $vf1, $vf1, $vf4x\n\tvmuly.wxyz $vf2, $vf2, $vf4y\n\tvmulz.wxyz $vf3, $vf3, $vf4z\n\tsqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)" : : "r"(m), "r"(v) : "memory");
}
/*TARGET 00131450*/
s32 kn__MotionPrototype0__getPosition(W2043c_Obj* o, W2043c_Mat* m, f32 t) asm("kn__MotionPrototype0__getPosition");
s32 kn__MotionPrototype0__getPosition(W2043c_Obj* o, W2043c_Mat* m, f32 t) {
    W2043c_Dat* d = o->d;
    s32* s = (s32*)((u8*)d + d->f2c);
    func_0011b6a8(m);
    if (s[3] == 0) return 1;
    f32 v[9];
    s32 k0, k1;
    t += d->f90 * 60.0f / d->f98;
    func_001285f8(o, &k0, &k1, t);
    f32* sf = (f32*)s;
    v[0] = sf[0]; v[1] = sf[1]; v[2] = sf[2];
    v[3] = sf[4]; v[4] = sf[5]; v[5] = sf[6];
    v[6] = sf[8]; v[7] = sf[9]; v[8] = sf[10];
    for (s32 i = 0; i < 9; i++) {
        s32 idx = s[12 + i];
        if (idx == -1) continue;
        void* p;
        if (idx >= d->f34) p = (u8*)d + d->f38 + (idx - d->f34) * 6;
        else p = (u8*)d + d->f30 + idx * 6;
        v[i] = func_00128750(o, p, k0, k1, t);
    }
    func_0011b6d8(m, v[3]);
    func_0011b720(m, v[4]);
    func_0011b768(m, v[5]);
    { W2043c_Vq w(v[6], v[7], v[8], 0.0f);
    W2043c_m_trans(m, &w); }
    { W2043c_Vq w(v[0], v[1], v[2], 0.0f);
    W2043c_m_scale(m, &w); }
    return 0;
}
}  // namespace n00131450

// 00131688 (was unwritten gap)
namespace n00131688 {
struct C { u8 pad[144]; f32 a; f32 b; f32 len; f32 cur; };
struct O { u32 x0; C* c; };
f32 func_00131688(O* o) asm("func_00131688");
f32 func_00131688(O* o) { C* c = o->c; return (c->cur - c->a) * 60.0f / c->len; }
}  // namespace

// 001316c0 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n001316c0 {
u32 func_00124bb8(u32, u32, u32, u32) asm("_Z13func_00124bb8jjjj");
extern u8 D_00347bd8 asm("D_00347bd8");
/*TARGET 001316c0*/
// 0x0011a490: definition moved into src/anon/unit_0011a260.cpp

u32 func_001316c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001316c0jjjj");
// 0x0011a490: definition moved into src/anon/unit_0011a260.cpp

u32 func_001316c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_00124bb8(r4, r5, r6, r7);  // obj_ctor_347b88
    r15 = (u32)&D_00347bd8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n001316c0

// 001316f0 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n001316f0 {
u32 func_00124bb8(u32, u32, u32, u32) asm("_Z13func_00124bb8jjjj");
extern u8 D_00347bd8 asm("D_00347bd8");
/*TARGET 001316f0*/
u32 func_001316f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001316f0jjjj");
u32 func_001316f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_00124bb8(r4, r5, r6, r7);  // obj_ctor_347b88
    r15 = (u32)&D_00347bd8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n001316f0

// 00131720 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00131720 {
// set_vtbl_347940
u32 func_00124c08(u32, u32, u32, u32) asm("_Z13func_00124c08jjjj");
extern u8 D_00347bd8 asm("D_00347bd8");
/*TARGET 00131720*/
u32 func_00131720(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00131720jjjj");
u32 func_00131720(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347bd8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00124c08)(u32, u32, u32, u32) = func_00124c08;
    r2 = fp_call4_00124c08(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00131720

// 00131748 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00131748 {
// set_vtbl_347940
u32 func_00124c08(u32, u32, u32, u32) asm("_Z13func_00124c08jjjj");
extern u8 D_00347bd8 asm("D_00347bd8");
/*TARGET 00131748*/
u32 func_00131748(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00131748jjjj");
u32 func_00131748(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347bd8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00124c08)(u32, u32, u32, u32) = func_00124c08;
    r2 = fp_call4_00124c08(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00131748

// 00131770 (was src/anon/batch_w15.cpp)
namespace n00131770 {
// 0x0011b6a8: definition moved into src/anon/unit_0011b3f8.cpp

extern u8 D_00347bd8 asm("D_00347bd8");
void func_00124c08(void*) asm("func_00124c08");
// set_vtbl_347b88
void func_00106420(void*) asm("func_00106420");
/*TARGET 00131770*/
void func_00131770(void** self) asm("func_00131770");
void func_00131770(void** self) {
    *self = &D_00347bd8;
    func_00124c08(self);  // set_vtbl_347b88
    func_00106420(self);
}
}  // namespace n00131770

// 001317a8 (was src/anon/batch_w216.cpp)
namespace n001317a8 {
struct W216Obj { char p[0x24]; s32 cnt; char q[0x30]; float f58; };
struct W216Holder { s32 p0; W216Obj* o; };
/*TARGET 001317a8*/
s32 func_001317a8(W216Holder* a, float x) asm("func_001317a8");
s32 func_001317a8(W216Holder* a, float x) {
    W216Obj* o = a->o;
    float v = x * o->f58 / 60.0f + 0.5f;
    s32 r = (s32)v;
    if (r < 0) r = 0;
    if (r >= o->cnt) r = o->cnt - 1;
    return r;
}
}  // namespace n001317a8

// 00131800 (was unwritten gap)
namespace n00131800 {
struct C { u8 pad[32]; u32 v; };
struct O { u32 x0; C* c; };
u32 func_00131800(O* o) asm("func_00131800");
u32 func_00131800(O* o) { return o->c->v; }
}  // namespace

// 00131810 (was src/anon/batch_w91.cpp)
namespace n00131810 {
// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// 4x4 matrix; assignment copies four quadwords.
struct Mq {
    Vq r[4];
    Mq& operator=(const Mq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// 0x001215b8: definition moved into src/anon/unit_00120520.cpp

// --- 00131810
// Copies the current frame's matrices into the destination's matrix buffer.
void func_00127cf8(u32) asm("func_00127cf8");
s32 func_001317a8(u8*, f32) asm("func_001317a8");
/*TARGET 00131810*/
void func_00131810(u8* p, u8* q, u32, u32, u32 x, f32 t) asm("func_00131810");
void func_00131810(u8* p, u8* q, u32, u32, u32 x, f32 t) {
    func_00127cf8(x);
    u8* s = *(u8**)(p + 4);
    s32 k = func_001317a8(p, t);
    u8* base = s + *(s32*)(s + 40);
    base += *(s32*)(s + 16) * k * 64;
    for (s32 i = 0; i < *(s32*)(s + 16); i++) {
        (*(Mq**)(q + 44))[i] = ((Mq*)base)[i];
    }
}
}  // namespace n00131810

// 001318d8 (was unwritten gap)
namespace n001318d8 {
u32 func_001318d8(void) asm("func_001318d8");
u32 func_001318d8(void) { return 0; }
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    u32 v[4];
    QWord& operator=(const QWord& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct C { u8 pad[48]; QWord a; QWord b; };
struct O { u32 x0; C* c; };
void func_001318e0(O* o, QWord* a, QWord* b) asm("func_001318e0");
void func_001318e0(O* o, QWord* a, QWord* b) { C* c = o->c; *a = c->a; *b = c->b; }
#undef QCOPY
}  // namespace

// 00131918 (was src/anon/batch_w61.cpp)
namespace n00131918 {
struct M64 {
    u8 b[64];
    M64& operator=(const M64& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void func_0011b6a8(u8*) asm("func_0011b6a8");
s32 func_001317a8(void*) asm("func_001317a8");
/*TARGET 00131918*/
s32 func_00131918(u8** a0, M64* dst) asm("func_00131918");
s32 func_00131918(u8** a0, M64* dst) {
    u8* base = a0[1];
    s32 off = *(s32*)(base + 44);
    u8* t = base + off;
    if (off == 0) {
        func_0011b6a8((u8*)dst);
        return 1;
    }
    M64* src = (M64*)(t + (func_001317a8(a0) << 6));
    *dst = *src;
    return 0;
}
}  // namespace n00131918

// 001319a0 (was unwritten gap)
namespace n001319a0 {
struct C { u8 pad[80]; f32 a; f32 b; f32 len; f32 cur; };
struct O { u32 x0; C* c; };
f32 func_001319a0(O* o) asm("func_001319a0");
f32 func_001319a0(O* o) { C* c = o->c; return (c->cur - c->a) * 60.0f / c->len; }
}  // namespace

// 001319d8 (was src/anon/batch_w2356_nsa.cpp)
namespace n001319d8 {
#define Q_COPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct CVec {
    f32 x, y, z, w;
    CVec() {}
    CVec(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    CVec(const CVec& o) { Q_COPY(this, &o); }
    CVec& operator=(const CVec& o) { if (this != &o) Q_COPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct CMtx { CVec r[4]; };
static inline void CApply(CVec& d, const CMtx& m, const CVec& v) {
    asm volatile("lqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                 : : "r"(&d), "r"(&v), "r"(&m) : "memory");
}
static inline void CClamp(CVec& v, f32 lo, f32 hi) {
    asm volatile("mfc1 $8, %1\n\tmfc1 $9, %2\n\tlqc2 $vf1, 0(%0)\n\tqmtc2 $8, $vf2\n\tqmtc2 $9, $vf3\n\tvmaxx.wxyz $vf1, $vf1, $vf2x\n\tvminix.wxyz $vf1, $vf1, $vf3x\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "f"(lo), "f"(hi) : "$8", "$9", "memory");
}
static inline void CScale(CVec& v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "f"(s) : "$8", "memory");
}
static inline void CAdd(CVec& d, const CVec& a, const CVec& b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&d), "r"(&a), "r"(&b) : "memory");
}
static inline u32 CPack(f32 r, f32 g, f32 b, f32 a) {
    return ((s32)a << 24) | ((s32)b << 16) | ((s32)g << 8) | (s32)r;
}
extern s8 D_003b8a90 asm("D_003b8a90");
extern CMtx D_003b8aa0 asm("D_003b8aa0");
void func_001320a8(void) asm("func_001320a8");
s32 func_002fd188(void (*)(void)) asm("func_002fd188");
/*TARGET 001319d8*/
/* Desaturate an RGBA colour: t >= 1 gives grey (YIQ luma), t < 1 blends towards the original. */
u32 func_001319d8(u32 c, f32 t) asm("func_001319d8");
/* Desaturate an RGBA colour: t >= 1 gives grey (YIQ luma), t < 1 blends towards the original. */
u32 func_001319d8(u32 c, f32 t) {
    if (!D_003b8a90) {
        CVec r0(0.299f, 0.587f, 0.114f, 0.0f);
        CVec r1(0.596f, -0.274f, -0.322f, 0.0f);
        CVec r2(0.211f, -0.523f, 0.312f, 0.0f);
        CVec r3(0.0f, 0.0f, 0.0f, 1.0f);
        Q_COPY(&D_003b8aa0.r[0], &r0);
        Q_COPY(&D_003b8aa0.r[1], &r1);
        Q_COPY(&D_003b8aa0.r[2], &r2);
        Q_COPY(&D_003b8aa0.r[3], &r3);
        D_003b8a90 = 1;
        func_002fd188(func_001320a8);
    }
    CVec a;
    CVec v;
    CVec w;
    CVec* p = &v;  // x goes through a pointer: the original stores it via the &v register
    p->x = (f32)(c & 0xff);
    v.y = (f32)((c >> 8) & 0xff);
    v.z = (f32)((c >> 16) & 0xff);
    v.w = (f32)((c >> 24) & 0xff);
    if (t < 1.0f) a = v;
    CApply(w, D_003b8aa0, v);
    v = w;
    CClamp(v, 0.0f, 255.0f);
    if (t < 1.0f) {
        v.y = v.z = v.x;
        CScale(v, t);
        CScale(a, 1.0f - t);
        CAdd(w, v, a);
        a = w;
        CClamp(a, 0.0f, 255.0f);
        return CPack(a.x, a.y, a.z, a.w);
    }
    return CPack(v.x, v.x, v.x, v.w);
}
}  // namespace n001319d8

// 00131da8 (was src/anon/batch_w80.cpp)
namespace n00131da8 {
struct U0_Node { s16 type; u16 flags; u32 count; u32 offs[6]; u32 valOff; };
// obj_get_sub_ptr_by12
u32 func_001319d8(u32, f32) asm("func_001319d8");
/*TARGET 00131da8*/
// 0x001214c0: definition moved into src/anon/unit_00120520.cpp
void func_00131da8(U0_Node* n) asm("func_00131da8");
// 0x001214c0: definition moved into src/anon/unit_00120520.cpp
void func_00131da8(U0_Node* n) {
    u32 i;
    s16 t;
    if (n->flags & 1) return;
    t = n->type;
    n->flags |= 1;
    if (t != -1) {
        if (t == 0) {
        u32* v = (u32*)((u8*)n + n->valOff);
        for (i = 0; i < n->count; i++, v++) *v = func_001319d8(*v, 1.0f);
        }
    } else {
        u32* o = n->offs;
        for (i = 0; i < n->count; i++, o++) func_00131da8((U0_Node*)((u8*)n + *o));
    }
}
}  // namespace n00131da8

// 00131e80 (was src/anon/batch_wcx2.cpp)
namespace n00131e80 {
#define last(b) ((b)->bk)
// --------------------
struct E131e80 { u8 pad[0x74]; u32 ptr; u8 pad78[0x18]; };
struct N131e80 { s16 type; u16 done; u32 nkids; s32 last; u8 padc[8]; u32 tbl; };
N131e80* Reloc131e80(N131e80* n) asm("func_00131e80");
/*TARGET 00131e80*/
N131e80* Reloc131e80(N131e80* n) asm("func_00131e80");
N131e80* Reloc131e80(N131e80* n)
{
    s16 t = n->type;
    if (t != -1) {
        if (t != 0) return n;
        E131e80* e = (E131e80*)((u8*)n + n->tbl);
        for (s32 i = 0; i <= n->last; i++, e++) e->ptr = (u32)n + e->ptr;
    } else {
        u32* p = (u32*)((u8*)n + 8);
        for (u32 i = 0; i < n->nkids; i++) Reloc131e80((N131e80*)((u8*)n + *p++));
    }
    n->done = 0;
    return n;
}
}  // namespace n00131e80

// 00131f40 (was src/anon/misc_1.cpp)
namespace n00131f40 {
/*TARGET 00131f40*/
// 0x00124840: definition moved into src/anon/unit_00123990.cpp

void func_00131f40(void* self) asm("_Z13func_00131f40Pv");
// 0x00124840: definition moved into src/anon/unit_00123990.cpp

void func_00131f40(void* self) {}
}  // namespace n00131f40

// 00131f48 (was src/anon/batch_w88.cpp)
namespace n00131f48 {
/*TARGET 00131f48*/
// 0028def0: moved to src/anon/unit_0028c878.cpp

// Relocate a node tree in place: type -1 = group of child offsets (recursed),
// type 0 = table whose entry pointers (+116) are rebased from base to p.
u8* func_00131f48(u8* p, u32 base) asm("func_00131f48");
// 0028def0: moved to src/anon/unit_0028c878.cpp

// Relocate a node tree in place: type -1 = group of child offsets (recursed),
// type 0 = table whose entry pointers (+116) are rebased from base to p.
u8* func_00131f48(u8* p, u32 base) {
    s16 t = *(s16*)p;
    if (t != -1) {
        if (t == 0) {
            u8* e = p + *(s32*)(p + 20);
            for (s32 i = 0; i <= *(s32*)(p + 8); i++, e += 144)
                *(u32*)(e + 116) = (u32)p + (*(u32*)(e + 116) - base);
        }
    } else {
        u32* q = (u32*)(p + 8);
        for (u32 i = 0; i < *(u32*)(p + 4); i++) {
            u32 off = *q++;
            u32 nb = base + off;
            func_00131f48(p + off, nb);
        }
    }
    return p;
}
}  // namespace n00131f48

// 00132018 (was src/anon/batch_w60.cpp)
namespace n00132018 {
/*TARGET 00132018*/
// Follows redirect nodes (type -1) and returns the entry of a type-0 node.
u8* func_00132018(u8* p) asm("func_00132018");
// Follows redirect nodes (type -1) and returns the entry of a type-0 node.
u8* func_00132018(u8* p) {  // entry_ptr_from_header
    if (p) {
        s16 t = *(s16*)p;
        if (t != -1) {
            if (t == 0) return p + (*(s32*)(p + 32) + *(s32*)(p + 4) * 4);
            return 0;
        }
        return func_00132018(p + ((s32*)(p + 4))[*(s32*)(p + 4)]);  // entry_ptr_from_header
    }
    return 0;
}
}  // namespace n00132018

// 00132068 (was src/anon/batch_w15.cpp)
namespace n00132068 {
struct Chunk { s16 type; u16 _2; u32 _4; u32 offs[1]; };
/*TARGET 00132068*/
void* func_00132068(Chunk* c, int i) asm("func_00132068");
void* func_00132068(Chunk* c, int i) {  // entry_get_by_index
    if (c != 0) {
        switch (c->type) {
        case -1: return (u8*)c + c->offs[i];
        case 0: return c;
        }
    }
    return 0;
}
}  // namespace n00132068

// 001320a8 (was unwritten gap)
namespace n001320a8 {
void func_001320a8(void) asm("func_001320a8");
void func_001320a8(void) {}
}  // namespace

// 001320b0 (was src/anon/tiny_auto80_queue.cpp)
namespace n001320b0 {
/*TARGET 001320b0*/
u32 func_001320b0(u32 a0) asm("_Z13func_001320b0j");
u32 func_001320b0(u32 a0) {  // read_u32_be
    if ((a0 & 3u)) {
        u8* p = (u8*)(u32)a0;
        u32 r13 = (u32)p[2];
        u32 r14 = (u32)p[3];
        u32 r15 = (u32)p[1];
        r13 = (u32)(r13 << 16);
        u32 r12 = (u32)p[0];
        r14 = (u32)(r14 << 24);
        r15 = (u32)(r15 << 8);
        r14 = (u32)(r14 | r12);
        r15 = (u32)(r15 | r13);
        return (u32)(r14 | r15);
    }
    return *(u32*)((u32)a0 + (s32)(0));
}
}  // namespace n001320b0

// 001320f0 (was src/anon/tiny_auto80_queue.cpp)
namespace n001320f0 {
/*TARGET 001320f0*/
u32 func_001320f0(u32 a0) asm("_Z13func_001320f0j");
u32 func_001320f0(u32 a0) {
    if ((a0 & 3u)) {
        u8* p = (u8*)(u32)a0;
        u32 r13 = (u32)p[6];
        u32 r14 = (u32)p[7];
        u32 r15 = (u32)p[5];
        r13 = (u32)(r13 << 16);
        u32 r12 = (u32)p[4];
        r14 = (u32)(r14 << 24);
        r15 = (u32)(r15 << 8);
        r14 = (u32)(r14 | r12);
        r15 = (u32)(r15 | r13);
        return (u32)(r14 | r15);
    }
    return *(u32*)((u32)a0 + (s32)(4));
}
}  // namespace n001320f0

// 00132130 (was src/anon/batch_w16.cpp)
namespace n00132130 {
// list_nth_node_rel
s32 func_001320f0(u8*) asm("func_001320f0");
u32 func_00132208(u8*) asm("func_00132208");
/*TARGET 00132130*/
// 0x00123e00: definition moved into src/anon/unit_00123990.cpp

// Skips a header (size from func_001320f0 plus 8); 0 when the rest is invalid.
u8* func_00132130(u8* p) asm("func_00132130");
// 0x00123e00: definition moved into src/anon/unit_00123990.cpp

// Skips a header (size from func_001320f0 plus 8); 0 when the rest is invalid.
u8* func_00132130(u8* p) {
    s32 off = func_001320f0(p) + 8;
    p += off;
    if (!func_00132208(p)) p = 0;
    return p;
}
}  // namespace n00132130

// 00132170 (was src/anon/tiny.cpp)
namespace n00132170 {
/*TARGET 00132170*/
// 0x00124c08: definition moved into src/anon/unit_00123990.cpp

u32 func_00132170(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00132170jjjj");
// 0x00124c08: definition moved into src/anon/unit_00123990.cpp

u32 func_00132170(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)((s32)a0 + (8));
}
}  // namespace n00132170

// 00132180 (was src/anon/batch_w58.cpp)
namespace n00132180 {
// 00106a60: moved to src/naka/libkn/camera.cpp

// Walks a chunk chain until a chunk with the given tag (or the "_KN5" end tag).
s32 func_00132208(void*) asm("func_00132208");
u32 func_001320b0(void*) asm("func_001320b0");
// read_u32_be
void* func_00132130(void*) asm("func_00132130");
/*TARGET 00132180*/
void* func_00132180(void* p, u32 tag) asm("func_00132180");
void* func_00132180(void* p, u32 tag) {
    for (;;) {
        if (!func_00132208(p) || func_001320b0(p) == 0x354e4b5f) return 0;
        if (func_001320b0(p) == tag) return p;
        p = func_00132130(p);
    }
}
}  // namespace n00132180

// 00132208 (was src/anon/auto80_199_queue.cpp)
namespace n00132208 {
/*TARGET 00132208*/
// 0x00129008: definition moved into src/anon/unit_00128480.cpp

u32 func_00132208(u32 a0) asm("_Z13func_00132208j");
// 0x00129008: definition moved into src/anon/unit_00128480.cpp

u32 func_00132208(u32 a0) {
    u32 t5 = 0;
    u32 v0;
    u32 t7;
    u32 t6;

    if (a0 == 0) {
        goto L0013224c;
    }

    v0 = func_001320b0(a0);  // read_u32_be
    t7 = 0x41584554;
    t5 = 1;
    if (v0 == t7) {
        goto L0013224c;
    }

    t6 = (t7 < v0);
    if (t6 != 0) {
        goto L0013225c;
    }

    t7 = 0x354e4b5f;

L00132244:
    if (v0 != t7) {
        t5 = 0;
    }

L0013224c:
    return t5;

L0013225c:
    t7 = 0x43535655;
    if (v0 == t7) {
        goto L0013224c;
    }

    t7 = 0x594d445f;
    goto L00132244;
}
}  // namespace n00132208

// 00132270 (was src/anon/batch_wlit.cpp)
namespace n00132270 {
extern u32 D_00347c00 asm("D_00347c00");
/*TARGET 00132270*/
// 0x002c1a18: definition moved into src/anon/unit_002c10e0.cpp

// Constructor-like init: vtable/type pointer at +0, scale 1.0 at +24.
void func_00132270(u32* p, u32 a) asm("func_00132270");
// 0x002c1a18: definition moved into src/anon/unit_002c10e0.cpp

// Constructor-like init: vtable/type pointer at +0, scale 1.0 at +24.
void func_00132270(u32* p, u32 a) {  // obj_ctor_347c00
    p[1] = a;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[0] = (u32)&D_00347c00;
    p[5] = 0;
    p[7] = 0;
    p[8] = 0;
    ((f32*)p)[6] = 1.0f;
}
}  // namespace n00132270

// 001322b0 (was unwritten gap)
namespace n001322b0 {
extern u8 D_00347c00[] asm("D_00347c00");
struct O { void* vt; u32 a; u32 b; u32 c; u32 d; u32 e; f32 f; u32 g; u32 h; };
void func_001322b0(O* o, u32 a) asm("func_001322b0");
void func_001322b0(O* o, u32 a) {
    o->b = 0; o->c = 0; o->f = 1.0f; o->d = 0; o->vt = D_00347c00; o->e = 0; o->g = 0; o->h = 0; o->a = a;
}
}  // namespace

// 001322f0 (was src/anon/tiny.cpp)
namespace n001322f0 {
extern u32 D_00347c00 asm("D_00347c00");
/*TARGET 001322f0*/
void func_001322f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001322f0jjjj");
void func_001322f0(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_347c00
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00347c00;
}
}  // namespace n001322f0

// 00132300 (was unwritten gap)
namespace n00132300 {
extern u8 D_00347c00[] asm("D_00347c00");
void func_00132300(void** o) asm("func_00132300");
void func_00132300(void** o) { *o = D_00347c00; }
}  // namespace

// 00132310 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n00132310 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_00347c00 asm("D_00347c00");
/*TARGET 00132310*/
// 0x00124c28: definition moved into src/anon/unit_00123990.cpp

u32 func_00132310(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00132310jjjjjjjj");
// 0x00124c28: definition moved into src/anon/unit_00123990.cpp

u32 func_00132310(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00347c00;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n00132310

// 00132330 (was src/anon/misc_1.cpp)
namespace n00132330 {
/*TARGET 00132330*/
s32 func_00132330(void* self) asm("_Z13func_00132330Pv");
s32 func_00132330(void* self) { return (s32)(*(s32*)((char*)self + 4)); }
}  // namespace n00132330

// 00132338 (was src/anon/tiny.cpp)
namespace n00132338 {
/*TARGET 00132338*/
// 0x001133f8: definition moved into src/anon/unit_001117d8.cpp

u32 func_00132338(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00132338jjjj");
// 0x001133f8: definition moved into src/anon/unit_001117d8.cpp

u32 func_00132338(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_field8
    return (u32)(*(u32*)((u32)a0 + (8)));
}
}  // namespace n00132338

// 00132340 (was unwritten gap)
namespace n00132340 {
u32 func_00132340(u32* o) asm("func_00132340");
u32 func_00132340(u32* o) { return o[4]; }
}  // namespace

// 00132348 (was src/anon/misc_1.cpp)
namespace n00132348 {
/*TARGET 00132348*/
void func_00132348(void* self, s32 v) asm("_Z13func_00132348Pvi");
void func_00132348(void* self, s32 v) { *(s32*)((char*)self + 16) = v; }
}  // namespace n00132348

// 00132350 (was src/naka/libkn/animation.cpp: kn::AnimationWork::getNext / setNext)
namespace n00132350 {
struct AnimationWorkLayout { char _pad0[28]; void* next; };
s32 AnimationWork_getNext(const AnimationWorkLayout* self) asm("_ZNK2kn13AnimationWork7getNextEv");
s32 AnimationWork_getNext(const AnimationWorkLayout* self) {
    return (s32)self->next;
}
void AnimationWork_setNext(AnimationWorkLayout* self, void* v) asm("_ZN2kn13AnimationWork7setNextEPS0_");
void AnimationWork_setNext(AnimationWorkLayout* self, void* v) {
    self->next = v;
}
}  // namespace n00132350

// 00132360 (was src/anon/misc_1.cpp)
namespace n00132360 {
/*TARGET 00132360*/
s32 func_00132360(void* self) asm("_Z13func_00132360Pv");
s32 func_00132360(void* self) { return (s32)(*(s32*)((char*)self + 32)); }
}  // namespace n00132360

// 00132368 (was src/anon/misc_1.cpp)
namespace n00132368 {
/*TARGET 00132368*/
void func_00132368(void* self, s32 v) asm("_Z13func_00132368Pvi");
void func_00132368(void* self, s32 v) { *(s32*)((char*)self + 32) = v; }
}  // namespace n00132368

// 00132370 (was src/anon/tiny_auto80_queue.cpp)
namespace n00132370 {
/*TARGET 00132370*/
void func_00132370(u32 a0, u32 a1, u32 a2, f32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00132370jjjfjjjj");
void func_00132370(u32 a0, u32 a1, u32 a2, f32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    *(f32*)((u32)a0 + (s32)(24)) = a3;
}
}  // namespace n00132370

// 00132378 (was unwritten gap)
namespace n00132378 {
f32 func_00132378(f32* o) asm("func_00132378");
f32 func_00132378(f32* o) { return o[6]; }
s32 func_00132380(u32 a, u32 b) asm("func_00132380");
s32 func_00132380(u32 a, u32 b) { return a == b; }
}  // namespace

// 00132390 (was src/anon/batch_w55.cpp)
namespace n00132390 {
/*TARGET 00132390*/
// 0x00127de8: definition moved into src/anon/unit_00127a88.cpp

// Walks the list from a (up to b) and returns the first node whose virtual test accepts.
void* func_00132390(void* a, void* b, u32 c, u32 d, u32 e) asm("func_00132390");
// 0x00127de8: definition moved into src/anon/unit_00127a88.cpp

// Walks the list from a (up to b) and returns the first node whose virtual test accepts.
void* func_00132390(void* a, void* b, u32 c, u32 d, u32 e) {
    for (; a && a != b; a = *(void**)((u8*)a + 28)) {
        if ((*(s32 (**)(void*, u32, u32, u32))(*(u8**)a + 12))(a, c, d, e)) return a;
    }
    return 0;
}
}  // namespace n00132390

// 00132430 (was src/anon/batch_w62.cpp)
namespace n00132430 {
// 0x001246b8: definition moved into src/anon/unit_00123990.cpp

void func_00132270(u8*) asm("func_00132270");
// obj_ctor_347c00
void func_00108398(u8*) asm("func_00108398");
// clear_quads_set_flags
extern u8 D_00347c30[] asm("D_00347c30");
/*TARGET 00132430*/
// Constructor: base, vtable, four 144-byte members at +48.
void func_00132430(u8* p) asm("func_00132430");
// Constructor: base, vtable, four 144-byte members at +48.
void func_00132430(u8* p) {
    func_00132270(p);  // obj_ctor_347c00
    *(u32*)p = (u32)D_00347c30;
    u8* e = p + 48;
    for (s32 i = 3; i != -1; i--) {
        func_00108398(e + 16);  // clear_quads_set_flags
        e += 144;
    }
    *(u32*)(p + 8) = 1;
    *(u32*)(p + 628) = 0;
    *(u32*)(p + 632) = 0;
    *(u32*)(p + 636) = 0;
    *(u32*)(p + 624) = 0;
}
}  // namespace n00132430

// 001324b8 (was src/anon/batch_w63.cpp)
namespace n001324b8 {
void func_00132270(void*) asm("func_00132270");
// obj_ctor_347c00
void func_00108398(void*) asm("func_00108398");
extern u8 D_00347c30[] asm("D_00347c30");
/*TARGET 001324b8*/
// Frame/system reset sequence.
// 00104e18: moved to src/common/area.cpp

// Scales x by a random integer normalised to [0, 1].
// 00106558: moved to src/anon/unit_00106490.cpp

// Constructor: base ctor, vtable, four 144-byte members, cleared tail fields.
void kn__TEXAnmWork__TEXAnmWork(u8* p) asm("kn__TEXAnmWork__TEXAnmWork");
// Frame/system reset sequence.
// 00104e18: moved to src/common/area.cpp

// Scales x by a random integer normalised to [0, 1].
// 00106558: moved to src/anon/unit_00106490.cpp

// Constructor: base ctor, vtable, four 144-byte members, cleared tail fields.
void kn__TEXAnmWork__TEXAnmWork(u8* p) {
    func_00132270(p);  // obj_ctor_347c00
    *(void**)p = D_00347c30;
    u8* e = p + 48;
    for (s32 i = 3; i != -1; i--) {
        func_00108398(e + 16);  // clear_quads_set_flags
        e += 144;
    }
    *(u32*)(p + 624) = 0;
    *(u32*)(p + 628) = 0;
    *(u32*)(p + 632) = 0;
    *(u32*)(p + 636) = 0;
    *(u32*)(p + 8) = 1;
}
}  // namespace n001324b8

// 00132540 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00132540 {
// set_vtbl_347b88
u32 func_001322f0(u32, u32, u32, u32) asm("_Z13func_001322f0jjjj");
extern u8 D_00347c30 asm("D_00347c30");
/*TARGET 00132540*/
u32 func_00132540(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00132540jjjj");
u32 func_00132540(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347c30;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_001322f0)(u32, u32, u32, u32) = func_001322f0;
    r2 = fp_call4_001322f0(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00132540

// 00132568 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00132568 {
// set_vtbl_347b88
u32 func_001322f0(u32, u32, u32, u32) asm("_Z13func_001322f0jjjj");
extern u8 D_00347c30 asm("D_00347c30");
/*TARGET 00132568*/
u32 func_00132568(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00132568jjjj");
u32 func_00132568(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347c30;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_001322f0)(u32, u32, u32, u32) = func_001322f0;
    r2 = fp_call4_001322f0(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00132568

// 00132590 (was src/anon/batch_w16.cpp)
namespace n00132590 {
u8 func_00106420(void*) asm("func_00106420");
void func_001322f0(void*) asm("func_001322f0");
extern u8 D_00347c30 asm("D_00347c30");
/*TARGET 00132590*/
void func_00132590(void* p) asm("func_00132590");
void func_00132590(void* p) {
    *(void**)p = &D_00347c30;
    func_001322f0(p);  // set_vtbl_347c00
    func_00106420(p);
}
}  // namespace n00132590

// 001325c8 (was src/anon/batch_w2437.cpp)
namespace n001325c8 {
struct T2437Tbl { u8 pad[8]; u16 lo; u16 hi; u16 n; u16 pad2; u8 pad3[8]; s32 off; };
T2437Tbl* func_00132c68(s32) asm("func_00132c68");
/*TARGET 001325c8*/
// The shared fail block sits in the mask == 0 arm, so that arm's compare falls into it
// (bnez -> out, b fail), and the two failure tests of the mask arm are separate gotos.
s32 func_001325c8(s32 a0, u32 mask, u32 id) asm("func_001325c8");
// The shared fail block sits in the mask == 0 arm, so that arm's compare falls into it
// (bnez -> out, b fail), and the two failure tests of the mask arm are separate gotos.
s32 func_001325c8(s32 a0, u32 mask, u32 id) {
    T2437Tbl* t = func_00132c68(a0);
    s32 r = -1;
    u32 v;
    if (t) {
        if (mask) {
            id &= mask;
            if (id >= t->lo && id <= t->hi) {
                v = *(u16*)((u8*)t + t->off + (id - t->lo) * 2);
                r = v - 1;
                if (v == 0) goto fail;
                if (t->n < v) goto fail;
            }
        } else {
            r = id;
            if (id >= t->n) {
            fail:
                r = -1;
            }
        }
    }
    return r;
}
}  // namespace n001325c8

// 00132678 (was unwritten gap)
namespace n00132678 {
struct H { u8 pad[28]; s32 tab; u8 pad2[4]; u32 id; };
struct O { u8 pad[628]; u8* cur; };
void func_00132348(O*, s32) asm("_Z13func_00132348Pvi");
H* func_00132c68(O*) asm("func_00132c68");
s32 func_001325c8(O*, u32, u32) asm("func_001325c8");
void func_00132678(O* o, s32 v) asm("func_00132678");
void func_00132678(O* o, s32 v) {
    func_00132348(o, v);
    H* h = func_00132c68(o);
    s32 i = func_001325c8(o, 0, h->id);
    if (i >= 0) o->cur = (u8*)h + ((s32*)((u8*)h + h->tab))[i];
}
s32 func_001326e0(O* o, s32 k, u32 m, u32 id) asm("func_001326e0");
s32 func_001326e0(O* o, s32 k, u32 m, u32 id) {
    s32 r = 0;
    if (k == 1) r = func_001325c8(o, m, id) >= 0;
    return r;
}
}  // namespace

// 00132720 (was src/anon/batch_w54.cpp)
namespace n00132720 {
// unions with a char member: the original was built without strict aliasing
union U32c {
    u32 v;
    u8 c;
};
// 0x00124618: definition moved into src/anon/unit_00123990.cpp

struct Snd132 {
    u8 pad[2];
    u16 a;
    u16 b;
};
struct Obj132 {
    u8 pad[20];
    U32c flags;
    u8 pad2[632 - 24];
    Snd132* cur;
    Snd132* last;
    f32 len;
    u32 pos;
};
u32 func_00106520(u32, u32) asm("func_00106520");
/*TARGET 00132720*/
void func_00132720(Obj132* p, Snd132* s) asm("func_00132720");
void func_00132720(Obj132* p, Snd132* s) {
    if (p->cur != s) {
        if (s) {
            p->flags.v |= 1;
            p->len = (f32)func_00106520(s->a, s->b + 1);
            p->pos = 0;
        }
        p->last = s;
        p->cur = s;
    }
}
}  // namespace n00132720

// 001327b0 (was unwritten gap)
namespace n001327b0 {
struct H { u8 pad[28]; s32 tab; };
struct O;
H* func_00132c68(O*) asm("func_00132c68");
s32 func_001325c8(O*, u32, u32) asm("func_001325c8");
void func_00132720(O*, u8*) asm("func_00132720");
void func_001327b0(O* o, u32 m, u32 id) asm("func_001327b0");
void func_001327b0(O* o, u32 m, u32 id) {
    H* h = func_00132c68(o);
    if (h) {
        s32 i = func_001325c8(o, m, id);
        if (i >= 0) func_00132720(o, (u8*)h + ((s32*)((u8*)h + h->tab))[i]);
    }
}
}  // namespace

// 00132850 (was src/anon/batch_w3899_nsa.cpp)
namespace n00132850 {
struct K850 { u16 type:4; s16 off:12; };
struct Anim850 { u8 pad[4]; u16 n; };
struct Obj850 {
    u8 pad0[0x14]; u32 flags; f32 speed; u8 pad1[4]; Obj850* link;
    u8 pad2[0x274 - 0x24]; s32 f274; u8* base; K850* cur; f32 dur; f32 time;
};
Anim850* func_00132c68(Obj850*) asm("func_00132c68");
void func_00132720(Obj850*, s32) asm("func_00132720");
u32 func_00106520(u16, s32) asm("func_00106520");
/*TARGET 00132850*/
// Advance an object's key-frame cursor by dt * speed. A linked object copies
// the cursor and timing of its link. Type-2 keys jump, type-3 keys stop.
// Partial asm: the f0..f3 pins and empty "+f" ties keep the loop values in
// the original's FP registers and keep its mov.s copies; the .p2align gives
// the original's aligned loop head (the goto loop has no loop notes, so the
// li 2/li 3 constants stay in the loop as in the original).
void func_00132850(Obj850* o, f32 dt) asm("func_00132850");
// Advance an object's key-frame cursor by dt * speed. A linked object copies
// the cursor and timing of its link. Type-2 keys jump, type-3 keys stop.
// Partial asm: the f0..f3 pins and empty "+f" ties keep the loop values in
// the original's FP registers and keep its mov.s copies; the .p2align gives
// the original's aligned loop head (the goto loop has no loop notes, so the
// li 2/li 3 constants stay in the loop as in the original).
void func_00132850(Obj850* o, f32 dt) {
    Anim850* a = func_00132c68(o);
    if (a == 0) return;
    if (!(o->flags & 4)) func_00132720(o, o->f274);
    else o->flags &= ~4;
    Obj850* l = o->link;
    if (l != 0) {
        if (l->cur != 0) o->cur = (K850*)((u8*)o->base + ((u8*)l->cur - (u8*)l->base));
        else o->cur = 0;
        *(u32*)&o->flags = l->flags;
        o->time = l->time;
        o->dur = l->dur;
        return;
    }
    K850* p = o->cur;
    if (p == 0) return;
    if (p->type == 3) return;
    if (p->type == 2) o->cur = (K850*)((u8*)p + p->off * (a->n * 2 + 8));
    u32 f = o->flags;
    if ((u8)(f & 1)) { o->flags = f & ~1; return; }

    f32 sp;
    register f32 tm asm("$f2");
    f32 dur;
    register f32 t0 asm("$f0");
    sp = dt * o->speed;
    dur = o->dur;
    t0 = o->time + sp;
    asm("" : "+f"(t0));
    tm = t0;
    o->time = t0;
    asm volatile(".p2align 3");
top:
    if (!(dur <= tm)) return;
    {
        register f32 r asm("$f0");
        r = tm - dur;
        asm("" : "+f"(r));
        o->time = r;
    }
    {
        s32 sz = a->n * 2 + 8;
        p = (K850*)((u8*)o->cur + sz);
        o->cur = p;
        if (p->type == 2) {
            if (o->flags & 2) goto Z;
            o->cur = (K850*)((u8*)p + p->off * (a->n * 2 + 8));
        } else if (p->type == 3) return;
        u16* q = (u16*)o->cur;
        f32 nd;
        nd = (f32)func_00106520(q[1], q[2] + 1);
        asm("" : "+f"(nd));
        register f32 nt asm("$f0");
        nt = o->time;

        dur = nd;
        tm = nt;
        o->dur = nd;
    }
    goto top;
Z:
    o->cur = 0;
}
}  // namespace n00132850

// 00132a60 (was unwritten gap)
namespace n00132a60 {
struct O { u8 pad[632]; u32 a; u32 b; };
void func_00132a60(O* o) asm("func_00132a60");
void func_00132a60(O* o) { o->b = 0; o->a = 0; }
}  // namespace

// 00132a70 (was src/anon/tiny_auto80_queue.cpp)
namespace n00132a70 {
extern "C" u32 func_00132c68(...);
/*TARGET 00132a70*/
u32 func_00132a70(u32 a0) asm("_Z13func_00132a70j");
u32 func_00132a70(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_00132c68(a0);
    s32 r14 = 1;
    if (v0 == 0u) goto ZERO;
    if (*(u32*)((u32)s0 + (s32)(636)) != 0u) goto RET;
ZERO:
    r14 = 0u;
RET:
    return (u32)r14;
}
}  // namespace n00132a70

// 00132ab0 (was src/anon/batch_w2487.cpp)
namespace n00132ab0 {
struct W1575Hdr { u16 f0, f2, f4, f6, lo, hi, max, fe, f10, f12, f14, f16; s32 off; };
struct W1575Obj { u8 pad[8]; s32 f8; };
// Compare two resources: same header fields and the same set of valid table entries.
s32 func_00132338(W1575Obj*) asm("func_00132338");
W1575Hdr* func_00132c68(W1575Obj*) asm("func_00132c68");
/*TARGET 00132ab0*/
s32 func_00132ab0(W1575Obj* a, W1575Obj* b) asm("func_00132ab0");
s32 func_00132ab0(W1575Obj* a, W1575Obj* b) {
    if (a == b) return 1;
    if (a->f8 != func_00132338(b)) return 0;
    W1575Hdr* x = func_00132c68(a);
    W1575Hdr* y = func_00132c68(b);
    if (!x) return 0;
    if (!y) return 0;
    if (x->f0 != y->f0) return 0;
    if (x->f2 != y->f2) return 0;
    if (x->max != y->max) return 0;
    if (x->lo != y->lo) return 0;
    if (x->hi != y->hi) return 0;
    if (x->f10 != y->f10) return 0;
    if (x->f12 != y->f12) return 0;
    if (x->f14 != y->f14) return 0;
    if (x->f16 != y->f16) return 0;
    u16* ta = (u16*)((u8*)x + x->off);
    u16* tb = (u16*)((u8*)y + y->off);
    for (u16 i = x->lo; i <= x->hi; i++) {
        u16 va = ta[i - x->lo];
        if (va != 0 && va <= x->max) {
            u16 vb = tb[i - y->lo];
            if (vb == 0 || vb > y->max) return 0;
        } else {
            u16 vb = tb[i - y->lo];
            if (vb != 0 && vb <= y->max) return 0;
        }
    }
    return 1;
}
}  // namespace n00132ab0

// 00132c68 (was src/anon/tiny_auto80_queue.cpp)
namespace n00132c68 {
u32 func_00132170(...) asm("func_00132170");
/*TARGET 00132c68*/
extern "C" u32 func_00132c68(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
u32 func_00132c68(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = 0u;
    r15 = *(u32*)((u32)r4 + (s32)(16));
    r4 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00132170)(r4, r5, r6, r7, r8, r9, r10, r11);
    }
    return r2;
}
}  // namespace n00132c68

// 00132c98 (was src/anon/tiny_auto80_solver.cpp)
namespace n00132c98 {
/*TARGET 00132c98*/
u32 func_00132c98(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00132c98jjjjjjjj");
u32 func_00132c98(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // entry144_sub_ptr
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r15 = *(u32*)((u32)r4 + (s32)(624));
    r14 = (u32)((s32)0u + (144));
    r15 = (u32)(r15 * r14);
    r4 = (u32)(r4 + r15);
    r4 = (u32)((s32)r4 + (48));
    r2 = r4;
    return r2;
}
}  // namespace n00132c98

// 00132cb8 (was src/anon/tiny_leaf_more.cpp)
namespace n00132cb8 {
/*TARGET 00132cb8*/
// 0x00120800: definition moved into src/anon/unit_00120520.cpp

void func_00132cb8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00132cb8jjjj");
// 0x00120800: definition moved into src/anon/unit_00120520.cpp

void func_00132cb8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r14 = *(u32*)((u32)r4 + (s32)(624));
    r15 = (u32)((s32)0u + (2));
    if (r14 != 0u) r15 = 0u;
    *(u32*)((u32)r4 + (s32)(624)) = r15;
}
}  // namespace n00132cb8

// 00132cd0 (was src/anon/tiny_auto80_queue.cpp)
namespace n00132cd0 {
extern "C" u32 func_00132c68(...);
/*TARGET 00132cd0*/
u32 func_00132cd0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00132cd0jjjjjjjj");
u32 func_00132cd0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_00132c68)();
    r15 = (u32)((s32)0u + (-1));
    if (r2 != 0u) {
        r15 = (u32)(*(u16*)((u32)r2 + (s32)(16)));
    }
    r2 = r15;
    return r2;
}
}  // namespace n00132cd0

// 00132d00 (was src/anon/tiny_auto80_queue.cpp)
namespace n00132d00 {
extern "C" u32 func_00132c68(...);
/*TARGET 00132d00*/
u32 func_00132d00(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00132d00jjjjjjjj");
u32 func_00132d00(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_00132c68)();
    r15 = (u32)((s32)0u + (-1));
    if (r2 != 0u) {
        r15 = (u32)(*(u16*)((u32)r2 + (s32)(18)));
    }
    r2 = r15;
    return r2;
}
}  // namespace n00132d00

// 00132d30 (was src/anon/tiny_auto80_queue.cpp)
namespace n00132d30 {
extern "C" u32 func_00132c68(...);
/*TARGET 00132d30*/
u32 func_00132d30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00132d30jjjjjjjj");
u32 func_00132d30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_00132c68)();
    r15 = (u32)((s32)0u + (-1));
    if (r2 != 0u) {
        r15 = (u32)(*(u16*)((u32)r2 + (s32)(20)));
    }
    r2 = r15;
    return r2;
}
}  // namespace n00132d30

// 00132d60 (was src/anon/tiny_auto80_queue.cpp)
namespace n00132d60 {
extern "C" u32 func_00132c68(...);
/*TARGET 00132d60*/
u32 func_00132d60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00132d60jjjjjjjj");
u32 func_00132d60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_00132c68)();
    r15 = (u32)((s32)0u + (-1));
    if (r2 != 0u) {
        r15 = (u32)(*(u16*)((u32)r2 + (s32)(22)));
    }
    r2 = r15;
    return r2;
}
}  // namespace n00132d60

// 00132d90 (was src/anon/batch_w3747.cpp)
namespace n00132d90 {
typedef struct H6 { u8 pad[6]; u16 x6; u8 pad2[0x14 - 8]; u16 x14; u16 x16; u8 pad3[8]; s32 x20; } H6;
typedef struct O6 { u8 pad[0x27c]; u16* t; } O6;
H6* func_00132c68(O6*) asm("func_00132c68");
/*TARGET 00132d90*/
u8* func_00132d90(O6* o, s32 i) asm("func_00132d90");
u8* func_00132d90(O6* o, s32 i) {
    register H6* h asm("$10") = func_00132c68(o);
    u8* r = 0;
    if (h) {
        u16* t;
t = o->t; if (t) for (;;) { if (t[0] & 0xf) break;             r = (u8*)h + (h->x20 + t[i + 3] * (((u32)(h->x14 * h->x6) >> 3) * h->x16));
 break; }
    }
    return r;
}
}  // namespace n00132d90

// 00132e18 (was unwritten gap)
namespace n00132e18 {
struct O { u8 pad[20]; u32 flags; };
void func_00132e18(O* o) asm("func_00132e18");
void func_00132e18(O* o) { o->flags |= 2; }
}  // namespace

// 00132e28 (was src/anon/batch_w56.cpp)
namespace n00132e28 {
// 00132e28: look up an entry, flag the owner and hand the entry's data to 00132720
u8* func_00132c68(void*, u32) asm("func_00132c68");
s32 func_001325c8(void*, s32, u32) asm("func_001325c8");
void func_00132720(void*, u8*) asm("func_00132720");
/*TARGET 00132e28*/
void kn__TEXAnmWork__set(u8* a, u32 b) asm("kn__TEXAnmWork__set");
void kn__TEXAnmWork__set(u8* a, u32 b)
{
    u8* h = func_00132c68(a, b);
    if (h) {
        s32 i = func_001325c8(a, 0xffff, b);
        if (i >= 0) {
            u8* t = h + *(u32*)(h + *(u32*)(h + 28) + i * 4);
            *(u32*)(a + 20) |= 4;
            func_00132720(a, t);
        }
    }
}
}  // namespace n00132e28

// 00132ec0 (was src/anon/batch_w46.cpp)
namespace n00132ec0 {
// 0x0011c828: definition moved into src/anon/unit_0011c128.cpp

// ---- 00132ec0
u8* func_00132c68(u8*, u32) asm("func_00132c68");
s32 func_001325c8(u8*, u32, u32) asm("func_001325c8");
/*TARGET 00132ec0*/
void func_00132ec0(u8* p, u32 id) asm("func_00132ec0");
void func_00132ec0(u8* p, u32 id) {
    u8* d = func_00132c68(p, id);
    if (d) {
        s32 i = func_001325c8(p, 0xffff, id);
        if (i >= 0) {
            s32* tbl = (s32*)(d + *(s32*)(d + 0x1c));
            *(u8**)(p + 628) = d + tbl[i];
        }
    }
}
}  // namespace n00132ec0

// 00132f38 (was src/anon/batch_w45.cpp)
namespace n00132f38 {
u8* func_00132c68(u8*) asm("func_00132c68");
s32 func_001325c8(u8*, u32, u32) asm("func_001325c8");
/*TARGET 00132f38*/
void func_00132f38(u8* a0) asm("func_00132f38");
void func_00132f38(u8* a0) {
    u8* v = func_00132c68(a0);
    s32 r = func_001325c8(a0, 0, *(u32*)(v + 36));
    if (r >= 0) {
        *(u8**)(a0 + 628) = v + *(s32*)(v + *(s32*)(v + 28) + r * 4);
    }
}
}  // namespace n00132f38

// 00132f98 (was src/anon/batch_w91.cpp)
namespace n00132f98 {
// --- 00132f98
// Walks a list and collects (counts) the active entries with the given id/owner.
s32 func_00132338(u8*) asm("func_00132338");
// get_field8
u8* func_00132c68(u8*) asm("func_00132c68");
u8* func_00132350(u8*) asm("func_00132350");
/*TARGET 00132f98*/
s32 func_00132f98(u8* p, u32 id, u8** out, u32, u8* owner) asm("func_00132f98");
s32 func_00132f98(u8* p, u32 id, u8** out, u32, u8* owner) {
    s32 n = 0;
    if (p) do {
        if (func_00132338(p) == 1) {  // get_field8
            u8* d = func_00132c68(p);
            if ((!owner || *(u8**)(p + 4) == owner) && d && *(u16*)(d + 2) == id && *(s32*)(p + 636)) {
                if (out) out[n] = p;
                n++;
            }
        }
    } while ((p = func_00132350(p)) != 0);
    return n;
}
}  // namespace n00132f98

// 00133078 (was src/anon/batch_w88.cpp)
namespace n00133078 {
s32 func_00132f98(void*, u32, u32*, u32, u32) asm("func_00132f98");
/*TARGET 00133078*/
s32 func_00133078(void* a, u32* tab, u32, u32 n, u32 x) asm("func_00133078");
s32 func_00133078(void* a, u32* tab, u32, u32 n, u32 x) {
    u32* out = tab + n * 2;
    s32 total = 0;
    for (u32 i = 0; i < n; i++) {
        u32 buf[8];
        s32 c = func_00132f98(a, i, buf, 8, x);
        u32* t = &tab[i * 2];
        t[0] = c;
        t[1] = (n * 2 + total) * 4;
        total += c;
        for (s32 k = 0; k < c; k++) *out++ = buf[k];
    }
    return total;
}
}  // namespace n00133078

// 00133158 (was src/anon/tiny_auto80_solver.cpp)
namespace n00133158 {
u32 func_00132270(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00132270jjjjjjjj");
extern u8 D_00347c60 asm("D_00347c60");
/*TARGET 00133158*/
u32 func_00133158(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00133158jjjjjjjj");
u32 func_00133158(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a0;
    u32 ret = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00132270)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 vt = (u32)&D_00347c60;
    *(u32*)(s0 + 40) = 0;
    u32 two = 2;
    *(u32*)(s0 + 36) = 0;
    *(u32*)(s0 + 8) = two;
    *(u32*)s0 = vt;
    return ret;
}
}  // namespace n00133158

// 00133198 (was src/anon/tiny_auto80_solver.cpp)
namespace n00133198 {
u32 func_00132270(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00132270jjjjjjjj");
extern u8 D_00347c60 asm("D_00347c60");
/*TARGET 00133198*/
u32 func_00133198(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00133198jjjjjjjj");
u32 func_00133198(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a0;
    u32 ret = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00132270)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 vt = (u32)&D_00347c60;
    *(u32*)(s0 + 40) = 0;
    u32 two = 2;
    *(u32*)(s0 + 36) = 0;
    *(u32*)(s0 + 8) = two;
    *(u32*)s0 = vt;
    return ret;
}
}  // namespace n00133198

// 001331d8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n001331d8 {
// set_vtbl_347b88
u32 func_001322f0(u32, u32, u32, u32) asm("_Z13func_001322f0jjjj");
extern u8 D_00347c60 asm("D_00347c60");
/*TARGET 001331d8*/
u32 func_001331d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001331d8jjjj");
u32 func_001331d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347c60;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_001322f0)(u32, u32, u32, u32) = func_001322f0;
    r2 = fp_call4_001322f0(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001331d8

// 00133200 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00133200 {
// set_vtbl_347b88
u32 func_001322f0(u32, u32, u32, u32) asm("_Z13func_001322f0jjjj");
extern u8 D_00347c60 asm("D_00347c60");
/*TARGET 00133200*/
u32 func_00133200(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133200jjjj");
u32 func_00133200(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347c60;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_001322f0)(u32, u32, u32, u32) = func_001322f0;
    r2 = fp_call4_001322f0(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00133200

// 00133228 (was src/anon/batch_w17.cpp)
namespace n00133228 {
// 0x00115290: definition moved into src/anon/unit_00114a90.cpp

extern u32 D_00347c60 asm("D_00347c60");
void func_001322f0(void*) asm("func_001322f0");
// set_vtbl_347c00
void func_00106420(void*) asm("func_00106420");
/*TARGET 00133228*/
void func_00133228(void** p) asm("func_00133228");
void func_00133228(void** p) {
    *p = &D_00347c60;
    func_001322f0(p);  // set_vtbl_347c00
    func_00106420(p);
}
}  // namespace n00133228

// 00133260 (was unwritten gap)
namespace n00133260 {
struct O;
u32* func_001333c8(O*) asm("func_001333c8");
s32 func_00133260(O* o, s32 k, u32 m, u32 v) asm("func_00133260");
s32 func_00133260(O* o, s32 k, u32 m, u32 v) {
    u32* p = func_001333c8(o);
    if (k == 2 && p) {
        if ((*p & m) == v) return 1;
    }
    return 0;
}
struct P { u8 pad[12]; u32 a; u8 pad2[4]; u32 flags; u8 pad3[12]; u32 b; u32 c; };
void func_001332c8(P* o) asm("func_001332c8");
void func_001332c8(P* o) { o->b = 0; o->flags |= 1; o->c = 0; o->a = 0; }
}  // namespace

// 001332e8 (was src/anon/batch_w1784_nsa.cpp)
namespace n001332e8 {
struct W1784V3 { f32 x, y, z; };
struct W1784O1 {
    u8 pad0[0xc];
    f32 pos;      /* 0x0c */
    u8 pad10[4];
    u32 b0 : 1;   /* 0x14 */
    u32 b1 : 1;
    u32 rest : 30;
    f32 speed;    /* 0x18 */
    u8 pad1c[8];
    s32 ix;       /* 0x24 */
    s32 iy;       /* 0x28 */
};
W1784V3* func_001333c8(W1784O1*) asm("func_001333c8");
/*TARGET 001332e8*/
void func_001332e8(W1784O1* o, f32 dt) asm("func_001332e8");
void func_001332e8(W1784O1* o, f32 dt) {
    W1784V3* v = func_001333c8(o);
    if (v) {
        u32 a = o->b0;
        if (!o->b1) {
            if ((u8)a) {
                o->b0 = 0;
            } else {
                f32 t = dt * o->speed;
                s32 d = (s32)(v->y * t);
                o->ix += d;
                d = (s32)(v->z * t);
                o->iy += d;
                o->pos += t;
            }
        }
    }
}
}  // namespace n001332e8

// 00133398 (was unwritten gap)
namespace n00133398 {
struct O { u8 pad[16]; u32 p; u32 flags; };
void func_00133398(O* o) asm("func_00133398");
void func_00133398(O* o) { o->flags |= 2; }
s32 func_001333a8(O* o) asm("func_001333a8");
s32 func_001333a8(O* o) {
    if (o->p == 0) return 0;
    s32 t = o->flags & 2;
    return t == 0;
}
}  // namespace

// 001333c8 (was src/anon/tiny_auto80_queue.cpp)
namespace n001333c8 {
u32 func_00132170(...) asm("func_00132170");
/*TARGET 001333c8*/
u32 func_001333c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001333c8jjjjjjjj");
u32 func_001333c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = 0u;
    r15 = *(u32*)((u32)r4 + (s32)(16));
    r4 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00132170)(r4, r5, r6, r7, r8, r9, r10, r11);
    }
    return r2;
}
}  // namespace n001333c8

// 001333f8 (was src/anon/batch_wcx.cpp)
namespace n001333f8 {
// 0x00124338: definition moved into src/anon/unit_00123990.cpp
u32 __fixunssfsi(f32) asm("__fixunssfsi");
/*TARGET 001333f8*/
u32 func_001333f8(u8* p, u32 a, u32 b) asm("func_001333f8");
u32 func_001333f8(u8* p, u32 a, u32 b)
{
    f32 r = (f32)a / (f32)b;
    return (__fixunssfsi((f32)*(u32*)(p + 36) * r) >> 16) & 0xfff;
}
}  // namespace n001333f8

// 001334a8 (was src/anon/batch_wcx.cpp)
namespace n001334a8 {
// 0x001243f8: definition moved into src/anon/unit_00123990.cpp
u32 __fixunssfsi(f32) asm("__fixunssfsi");
/*TARGET 001334a8*/
u32 func_001334a8(u8* p, u32 a, u32 b) asm("func_001334a8");
u32 func_001334a8(u8* p, u32 a, u32 b)
{
    f32 r = (f32)a / (f32)b;
    return (__fixunssfsi((f32)*(u32*)(p + 40) * r) >> 16) & 0xfff;
}
}  // namespace n001334a8

// 00133558 (was unwritten gap)
namespace n00133558 {
void func_00133630(void*) asm("_Z13func_00133630jjjj");
void func_00133558(void* o) asm("func_00133558");
void func_00133558(void* o) { func_00133630(o); }
}  // namespace

// 00133570 (was src/anon/tiny_wrappers_more.cpp)
namespace n00133570 {
u32 func_00133630(u32, u32, u32, u32) asm("_Z13func_00133630jjjj");
/*TARGET 00133570*/
// 0x00127e88: definition moved into src/anon/unit_00127a88.cpp

u32 func_00133570(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133570jjjj");
// 0x00127e88: definition moved into src/anon/unit_00127a88.cpp

u32 func_00133570(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133630(a0, a1, a2, a3);
}
}  // namespace n00133570

// 00133588 (was unwritten gap)
namespace n00133588 {
void func_00133588(void) asm("func_00133588");
void func_00133588(void) {}
void func_00133590(void) asm("func_00133590");
void func_00133590(void) {}
}  // namespace

// 00133598 (was src/anon/auto80_199_queue.cpp)
namespace n00133598 {
/*TARGET 00133598*/
void func_00133598(u32 a0, u32 a1, u32 a2) asm("_Z13func_00133598jjj");
void func_00133598(u32 a0, u32 a1, u32 a2) {
    u32 t6 = a1 + 15;
    *(u8*)(a0 + 0) = 0;
    t6 = t6 & 0xFFFFFFF0;

    u32 a1n = a1 + a2;
    a1n = a1n - t6;
    a1n = a1n >> 1;

    u32 t7 = t6 + a1n;
    (*(u32*)(a0 + 8) = t6, *(u32*)(a0 + 12) = t7, *(u32*)(a0 + 4) = t6);
    *(u32*)(a0 + 16) = a1n;

    u32 v0 = func_001336f8(a0);
    *(u32*)(a0 + 24) = v0;

    *(u32*)(a0 + 20) = 0;
    *(u32*)(a0 + 28) = 0;

    func_00133be8(a0, 0, 0, 0);  // forward_sub24_to_1338e8
    func_00133690(a0);
    func_00133be8(a0, 0, 0, 0);  // forward_sub24_to_1338e8
    func_00133690(a0);
}
}  // namespace n00133598

// 00133630 (was src/anon/tiny_auto80.cpp)
namespace n00133630 {
/*TARGET 00133630*/
// 0x00124828: definition moved into src/anon/unit_00123990.cpp

void func_00133630(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133630jjjj");
// 0x00124828: definition moved into src/anon/unit_00123990.cpp

void func_00133630(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(volatile u32*)((u32)r4 + (s32)(28)) = 0u;
    *(u8*)((u32)r4 + (s32)(0)) = (u8)0u;
    *(volatile u32*)((u32)r4 + (s32)(4)) = 0u;
    *(u32*)((u32)r4 + (s32)(8)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(12)) = 0u;
    *(u32*)((u32)r4 + (s32)(16)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(24)) = 0u;
    *(u32*)((u32)r4 + (s32)(32)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(20)) = 0u;
}
}  // namespace n00133630

// 00133658 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00133658 {
// set_vtbl_347c00
u32 func_001336f8(u32, u32, u32, u32) asm("_Z13func_001336f8jjjj");
/*TARGET 00133658*/
u32 func_00133658(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133658jjjj");
u32 func_00133658(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15, r16;
    r16 = r4;
    u32 (*fp_call4_001336f8)(u32, u32, u32, u32) = func_001336f8;
    r2 = fp_call4_001336f8(r4, r5, r6, r7);
    r15 = r2;
    r2 = *(u32*)((u32)r16 + (s32)(24));
    r2 = (u32)(r2 ^ r15);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
}  // namespace n00133658

// 00133690 (was src/anon/tiny_auto80_queue.cpp)
namespace n00133690 {
u32 func_001336f8(u32 a0) asm("_Z13func_001336f8j");
/*TARGET 00133690*/
// 0x00127cf8: definition moved into src/anon/unit_00127a88.cpp

void func_00133690(u32 a0) asm("_Z13func_00133690j");
// 0x00127cf8: definition moved into src/anon/unit_00127a88.cpp

void func_00133690(u32 a0) {
    u32 s0 = a0;
    if (*(u8*)(a0 + 0) != 0) {
        *(u8*)(a0 + 0) = 0;
        goto call;
    }
    *(u8*)(a0 + 0) = 1;
call:
    u32 v0 = func_001336f8(s0);
    *(u32*)(s0 + 24) = v0;
    *(u32*)(s0 + 20) = 0;
}
}  // namespace n00133690

// 001336d8 (was src/anon/tiny_leaf.cpp)
namespace n001336d8 {
/*TARGET 001336d8*/
void func_001336d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001336d8jjjj");
void func_001336d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = *(u32*)((u32)r4 + (s32)(24));
    *(u32*)((u32)r4 + (s32)(28)) = r15;
}
}  // namespace n001336d8

// 001336e8 (was src/anon/tiny_leaf.cpp)
namespace n001336e8 {
/*TARGET 001336e8*/
void func_001336e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001336e8jjjj");
void func_001336e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = *(u32*)((u32)r4 + (s32)(28));
    *(u32*)((u32)r4 + (s32)(28)) = 0u;
    *(u32*)((u32)r4 + (s32)(24)) = r15;
}
}  // namespace n001336e8

// 001336f8 (was src/anon/tiny_auto80_queue.cpp)
namespace n001336f8 {
/*TARGET 001336f8*/
u32 func_001336f8(u32 a0) asm("_Z13func_001336f8j");
u32 func_001336f8(u32 a0) {
    u32 t7 = (u32)*(u8*)((u32)a0 + (s32)(0));
    if (t7 == 0u) return *(u32*)((u32)a0 + (s32)(8));
    return *(u32*)((u32)a0 + (s32)(12));
}
}  // namespace n001336f8

// 00133718 (was src/anon/misc_1.cpp)
namespace n00133718 {
/*TARGET 00133718*/
s32 func_00133718(void* self) asm("_Z13func_00133718Pv");
s32 func_00133718(void* self) { return (s32)(*(s32*)((char*)self + 24)); }
}  // namespace n00133718

// 00133720 (was src/anon/tiny_auto80_solver.cpp)
namespace n00133720 {
u32 func_001336f8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001336f8jjjjjjjj");
u32 func_00133718(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00133718jjjjjjjj");
u32 func_00133720(u32) asm("_Z13func_00133720j");
/*TARGET 00133720*/
u32 func_00133720(u32 a0) asm("_Z13func_00133720j");
u32 func_00133720(u32 a0) {
    u32 s1 = a0;
    u32 s0 = ((u32(*)(u32))func_00133718)(a0);
    u32 v0 = ((u32(*)(u32))func_001336f8)(s1);
    return (s0 - v0) + *(u32*)(s1 + 20);
}
}  // namespace n00133720

// 00133768 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n00133768 {
u32 func_00133720(u32, u32, u32, u32) asm("_Z13func_00133720jjjj");
/*TARGET 00133768*/
// 0x0011e3c8: definition moved into src/anon/unit_0011c128.cpp

u32 func_00133768(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133768jjjj");
// 0x0011e3c8: definition moved into src/anon/unit_0011c128.cpp

u32 func_00133768(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_00133720(r4, r5, r6, r7);
    r15 = r2;
    r2 = *(u32*)((u32)r16 + (s32)(16));
    r2 = (u32)(r2 - r15);
    return r2;
}
}  // namespace n00133768

// 00133798 (was unwritten gap)
namespace n00133798 {
u8 func_00133798(u8* p) asm("func_00133798");
u8 func_00133798(u8* p) { return *p; }
}  // namespace

// 001337a0 (was src/anon/tiny_auto80_solver.cpp)
namespace n001337a0 {
u32 func_001337a0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001337a0jjjjjjjj");
/*TARGET 001337a0*/
u32 func_001337a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001337a0jjjjjjjj");
u32 func_001337a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32* pp = (u32*)a0;
    u32 x = 0x50000000u | a2;
    *(u8*)(*pp + 2) = 0;
    *(u32*)(*pp + 8) = a3;
    *(u32*)(*pp + 12) = x;
    *(u8*)(*pp + 3) = 48;
    *(u32*)(*pp + 4) = a1;
    *(u16*)*pp = (u16)a2;
    *pp = *pp + 16;
    return a1;
}
}  // namespace n001337a0

// 001337f0 (was src/anon/batch_w28.cpp)
namespace n001337f0 {
u8* wtarget_001337f0(u32, u32, u32, u32) asm("_Z16wtarget_001337f0jjjj");
// Initialise a fixed descriptor when called with (1, 0xffff).
// 00103080: static initialiser, now made by gcc in src/common/title.cpp

// Append a packet header of n quadwords to a packet cursor; returns its payload.
struct Pk { u16 h0; u8 b2; u8 b3; u32 f4; u32 f8; u32 fc; };
union PkCursor { Pk* p; u32 w; u16 h; };
/*TARGET 001337f0*/
u8* wtarget_001337f0(u32 a, u32 n, u32 c, u32) asm("_Z16wtarget_001337f0jjjj");
u8* wtarget_001337f0(u32 a, u32 n, u32 c, u32) {
    PkCursor* cur = (PkCursor*)a;
    cur->p->b2 = 0;
    cur->p->f8 = c;
    cur->p->fc = n | 0x50000000;
    cur->p->b3 = 0x10;
    cur->p->f4 = 0;
    cur->p->h0 = n;
    u8* v = (u8*)cur->p;
    cur->p = (Pk*)(v + n * 16 + 16);
    return v + 16;
}
}  // namespace n001337f0

// 00133848 (was src/anon/tiny_auto80_solver.cpp)
namespace n00133848 {
u32 func_00133848(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00133848jjjjjjjj");
/*TARGET 00133848*/
u32 func_00133848(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00133848jjjjjjjj");
u32 func_00133848(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // entry16_init_flag16
    u32* pp = (u32*)a0;
    *(u8*)(*pp + 2) = 0;
    *(u32*)(*pp + 8) = a2;
    *(u32*)(*pp + 12) = a3;
    *(u8*)(*pp + 3) = 16;
    *(u32*)(*pp + 4) = 0;
    *(u16*)*pp = (u16)a1;
    u32 p = *pp;
    u32 q = p + (a1 << 4) + 16;
    *pp = q;
    return p + 16;
}
}  // namespace n00133848

// 00133898 (was src/anon/tiny_auto80_solver.cpp)
namespace n00133898 {
// entry16_init_flag16
u32 func_00133898(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00133898jjjjjjjj");
/*TARGET 00133898*/
u32 func_00133898(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00133898jjjjjjjj");
u32 func_00133898(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // entry16_init_flag96
    u32* pp = (u32*)a0;
    *(u8*)(*pp + 2) = 0;
    *(u32*)(*pp + 8) = a2;
    *(u32*)(*pp + 12) = a3;
    *(u8*)(*pp + 3) = 96;
    *(u32*)(*pp + 4) = 0;
    *(u16*)*pp = (u16)a1;
    u32 p = *pp;
    u32 q = p + (a1 << 4) + 16;
    *pp = q;
    return p + 16;
}
}  // namespace n00133898

// 001338e8 (was src/anon/tiny_auto80_solver.cpp)
namespace n001338e8 {
// entry16_init_flag96
u32 func_001338e8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001338e8jjjjjjjj");
/*TARGET 001338e8*/
u32 func_001338e8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001338e8jjjjjjjj");
u32 func_001338e8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32* pp = (u32*)a0;
    *(u8*)(*pp + 2) = 0;
    *(u32*)(*pp + 8) = a2;
    *(u32*)(*pp + 12) = a3;
    *(u8*)(*pp + 3) = 112;
    *(u32*)(*pp + 4) = 0;
    *(u16*)*pp = (u16)a1;
    u32 p = *pp;
    u32 q = p + (a1 << 4) + 16;
    *pp = q;
    return p + 16;
}
}  // namespace n001338e8

// 00133938 (was src/anon/batch_w56.cpp)
namespace n00133938 {
// 00133938: write a 16-byte packet header at the cursor and advance the cursor
struct PktHdr { u16 id; u8 b2; u8 b3; PktHdr* next; PktHdr* p8; PktHdr* p12; };
PktHdr* wtarget_00133938(PktHdr** pp, PktHdr* next, u32 id, u32 a3, u32 a4) asm("_Z16wtarget_00133938jjjj");
/*TARGET 00133938*/
PktHdr* wtarget_00133938(PktHdr** pp, PktHdr* next, u32 id, u32 a3, u32 a4) asm("_Z16wtarget_00133938jjjj");
PktHdr* wtarget_00133938(PktHdr** pp, PktHdr* next, u32 id, u32 a3, u32 a4)
{
    (*pp)->b2 = 0;
    (*pp)->p8 = (PktHdr*)a3;
    (*pp)->p12 = (PktHdr*)a4;
    (*pp)->b3 = 32;
    (*pp)->next = next;
    *(u16*)*pp = id;

    PktHdr* r = *pp;
    *pp = next;
    return r + 1;
}
}  // namespace n00133938

// 00133980 (was src/anon/batch_w61.cpp)
namespace n00133980 {
struct Hd { u16 n; u8 b2; u8 b3; u32 a; u32 c; u32 d; };
union HP { Hd* h; u8* b; };
u8* wtarget_00133980(HP*, u32, u32, u32, u32) asm("_Z16wtarget_00133980jjjj");
/*TARGET 00133980*/
// Appends a 16-byte header plus n*16 bytes to a packet cursor; the fifth word arrives in t0.
u8* wtarget_00133980(HP* pp, u32 a1, u32 a2, u32 a3, u32 t0) asm("_Z16wtarget_00133980jjjj");
// Appends a 16-byte header plus n*16 bytes to a packet cursor; the fifth word arrives in t0.
u8* wtarget_00133980(HP* pp, u32 a1, u32 a2, u32 a3, u32 t0) {
    pp->h->b2 = 0;
    pp->h->c = a3;
    pp->h->d = t0;
    pp->h->b3 = 80;
    pp->h->a = a1;
    pp->h->n = a2;
    u8* r = pp->b;
    pp->b = r + (a2 << 4) + 16;
    return r + 16;
}
}  // namespace n00133980

// 001339d0 (was src/anon/batch_w51.cpp)
namespace n001339d0 {
u32 wtarget_001339d0(u32, u32, u32, u32, u32) asm("_Z16wtarget_001339d0jjjj");
// 0x001286d0: definition moved into src/anon/unit_00128480.cpp

struct Pkt { u16 h0; u8 b2; u8 b3; u32 w4; u32 w8; u32 w12; };
union PktCursor { Pkt* p; u32 u; u16 h; };
/*TARGET 001339d0*/
// Append one 16-byte packet at the cursor and advance it.
u32 wtarget_001339d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0) asm("_Z16wtarget_001339d0jjjj");
// Append one 16-byte packet at the cursor and advance it.
u32 wtarget_001339d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0) {
    PktCursor* pp = (PktCursor*)a0;
    pp->p->b2 = 0;
    pp->p->w8 = a3;
    pp->p->w12 = t0;
    pp->p->b3 = 48;
    pp->p->w4 = a1;
    pp->p->h0 = a2;
    pp->p++;
    return a1;
}
}  // namespace n001339d0

// 00133a18 (was src/anon/batch_w1784_nsa.cpp)
namespace n00133a18 {
// GIF tag: NLOOP, EOP, NREG, REGS
struct W1784Tag {
    u64 nloop : 15;
    u64 eop : 1;
    u64 pad : 44;
    u64 nreg : 4;
    u64 regs : 4;
    u64 rest : 60;
} __attribute__((aligned(16)));
struct W1784Pkt { u8 pad[16]; W1784Tag tag; };
struct W1784O2 {
    u8 pad0[0x18];
    W1784Pkt* buf;   /* 0x18 */
    u8 pad1c[4];
    W1784Pkt* pkt;   /* 0x20 */
};
void func_00133ba0(W1784O2*, s32, u32) asm("func_00133ba0");
void wtarget_00133a18(W1784O2* o, u32, u32, u32) asm("_Z16wtarget_00133a18jjjj");
/*TARGET 00133a18*/
void wtarget_00133a18(W1784O2* o, u32, u32, u32) asm("_Z16wtarget_00133a18jjjj");
void wtarget_00133a18(W1784O2* o, u32, u32, u32) {
    if (o->pkt == 0) {
        W1784Pkt* t = o->buf;
        func_00133ba0(o, 1, 0x13000000);
        o->pkt = t;
        *(u128*)&t->tag = 0;
        o->pkt->tag.nloop = 0;
        o->pkt->tag.eop = 1;
        o->pkt->tag.nreg = 1;
        o->pkt->tag.regs = 0xe;
    }
}
}  // namespace n00133a18

// 00133ac8 (was src/anon/tiny_auto80_solver.cpp)
namespace n00133ac8 {
void func_00133ac8(u32, u64, u64, u32, u32, u32, u32, u32) asm("_Z13func_00133ac8jyyjjjjj");
/*TARGET 00133ac8*/
void func_00133ac8(u32 a0, u64 a1, u64 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00133ac8jyyjjjjj");
void func_00133ac8(u32 a0, u64 a1, u64 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r14, r15;
    r15 = *(u32*)((u32)r4 + (s32)(24));
    r14 = r15;
    r15 = (u32)((s32)r15 + (16));
    *(u32*)((u32)r4 + (s32)(24)) = r15;
    *(u64*)((u32)r14 + (s32)(0)) = a2;
    *(u64*)((u32)r14 + (s32)(8)) = a1;
}
}  // namespace n00133ac8

// 00133ae8 (was src/anon/batch_w63.cpp)
namespace n00133ae8 {
struct WNode { u16 h0; u16 h2; u32 w4; u32 w8; u32 tag; u64 idx : 15; u64 rest : 49; };
struct WCtx { u8 pad[24]; WNode* cur; u32 pad28; union { WNode* top; u16 h; }; };
void wtarget_00133ae8(u32, u32, u32, u32) asm("_Z16wtarget_00133ae8jjjj");
/*TARGET 00133ae8*/
// Closes the current DMA packet: stores its qword count and an end tag.
void wtarget_00133ae8(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_00133ae8jjjj");
// Closes the current DMA packet: stores its qword count and an end tag.
void wtarget_00133ae8(u32 a0, u32 a1, u32, u32) {
    WCtx* c = (WCtx*)a0;
    WNode* t = c->top;
    t->idx = ((u32)c->cur - (u32)t - 32) >> 4;
    if ((u8)a1 && c->top->idx == 0) {
        c->cur = c->top;
    } else {
        c->top->h0 = c->top->idx + 1;
        c->top->tag = c->top->h0 | 0x50000000;
    }
    c->top = 0;
}
}  // namespace n00133ae8

// 00133b78 (was src/anon/tiny_leaf.cpp)
namespace n00133b78 {
/*TARGET 00133b78*/
void func_00133b78(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133b78jjjj");
void func_00133b78(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = *(u32*)((u32)r4 + (s32)(32));
    *(u32*)((u32)r4 + (s32)(32)) = 0u;
    *(u32*)((u32)r4 + (s32)(24)) = r15;
}
}  // namespace n00133b78

// 00133b88 (was src/anon/tiny_wrappers_more.cpp)
namespace n00133b88 {
u32 func_001337a0(u32, u32, u32, u32) asm("_Z13func_001337a0jjjj");
/*TARGET 00133b88*/
u32 func_00133b88(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133b88jjjj");
u32 func_00133b88(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001337a0(((u32)(a0) + 24u), a1, a2, a3);
}
}  // namespace n00133b88

// 00133ba0 (was src/anon/tiny_wrappers_more.cpp)
namespace n00133ba0 {
u32 func_001337f0(u32, u32, u32, u32) asm("_Z13func_001337f0jjjj");
/*TARGET 00133ba0*/
u32 func_00133ba0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133ba0jjjj");
u32 func_00133ba0(u32 a0, u32 a1, u32 a2, u32 a3) {  // forward_sub24_to_1337f0
    return func_001337f0(((u32)(a0) + 24u), a1, a2, a3);
}
}  // namespace n00133ba0

// 00133bb8 (was src/anon/tiny_wrappers_more.cpp)
namespace n00133bb8 {
u32 func_00133848(u32, u32, u32, u32) asm("_Z13func_00133848jjjj");
/*TARGET 00133bb8*/
u32 func_00133bb8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133bb8jjjj");
u32 func_00133bb8(u32 a0, u32 a1, u32 a2, u32 a3) {  // forward_sub24_to_133848
    return func_00133848(((u32)(a0) + 24u), a1, a2, a3);  // entry16_init_flag16
}
}  // namespace n00133bb8

// 00133bd0 (was src/anon/tiny_wrappers_more.cpp)
namespace n00133bd0 {
// entry16_init_flag16
u32 func_00133898(u32, u32, u32, u32) asm("_Z13func_00133898jjjj");
/*TARGET 00133bd0*/
u32 func_00133bd0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133bd0jjjj");
u32 func_00133bd0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133898(((u32)(a0) + 24u), a1, a2, a3);  // entry16_init_flag96
}
}  // namespace n00133bd0

// 00133be8 (was src/anon/tiny_wrappers_more.cpp)
namespace n00133be8 {
// entry16_init_flag96
u32 func_001338e8(u32, u32, u32, u32) asm("_Z13func_001338e8jjjj");
/*TARGET 00133be8*/
u32 func_00133be8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133be8jjjj");
u32 func_00133be8(u32 a0, u32 a1, u32 a2, u32 a3) {  // forward_sub24_to_1338e8
    return func_001338e8(((u32)(a0) + 24u), a1, a2, a3);
}
}  // namespace n00133be8

// 00133c00 (was src/anon/tiny_wrappers_more.cpp)
namespace n00133c00 {
u32 func_00133938(u32, u32, u32, u32) asm("_Z13func_00133938jjjj");
/*TARGET 00133c00*/
u32 func_00133c00(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133c00jjjj");
u32 func_00133c00(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133938(((u32)(a0) + 24u), a1, a2, a3);
}
}  // namespace n00133c00

// 00133c18 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n00133c18 {
u32 func_00133938(u32, u32, u32, u32) asm("_Z13func_00133938jjjj");
/*TARGET 00133c18*/
u32 func_00133c18(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133c18jjjj");
u32 func_00133c18(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u, r17 = 0u;
    r15 = (u32)(r6 << 4);
    r17 = r4;
    r16 = *(u32*)((u32)r4 + (s32)(24));
    r4 = (u32)((s32)r4 + (24));
    r16 = (u32)(r16 + r15);
    r2 = func_00133938(r4, r5, r6, r7);
    r16 = (u32)((s32)r16 + (16));
    *(u32*)((u32)r17 + (s32)(24)) = r16;
    return r2;
}
}  // namespace n00133c18

// 00133c60 (was src/anon/tiny_wrappers_more.cpp)
namespace n00133c60 {
u32 func_00133980(u32, u32, u32, u32) asm("_Z13func_00133980jjjj");
/*TARGET 00133c60*/
u32 func_00133c60(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133c60jjjj");
u32 func_00133c60(u32 a0, u32 a1, u32 a2, u32 a3) {  // forward_sub24_to_133980
    return func_00133980(((u32)(a0) + 24u), a1, a2, a3);
}
}  // namespace n00133c60

// 00133c78 (was src/anon/tiny_wrappers_more.cpp)
namespace n00133c78 {
u32 func_001339d0(u32, u32, u32, u32) asm("_Z13func_001339d0jjjj");
/*TARGET 00133c78*/
u32 func_00133c78(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00133c78jjjj");
u32 func_00133c78(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001339d0(((u32)(a0) + 24u), a1, a2, a3);
}
}  // namespace n00133c78


// 00133c90 (gap, was src/anon/asm_00133c90.s): take n bytes, 16-aligned, from the top of a double-buffered area.
// The end is summed in each branch (the tails are cross-jumped after reload) and `top` is updated in place.
namespace n00133c90 {
struct Q { u8 dbl; u8 pad[7]; u32 base0; u32 base1; u32 size; u32 used; u32 min; };
u32 func_00133c90(Q* o, u32 n) asm("func_00133c90");
u32 func_00133c90(Q* o, u32 n) {
    u32 top;
    n = (n + 15) & ~15;
    if (!o->dbl) top = o->base0 + o->size; else top = o->base1 + o->size;
    top &= ~15;
    top -= o->used;
    u32 r = top - n;
    if (r < o->min) return 0;
    o->used += n;
    return r;
}
}  // namespace n00133c90
