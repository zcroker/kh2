// Linked unit 0x193be8-0x194790 (YS, after the whole-asm function 0x193608): object helpers,
// YS::OBJ texanm/part/colour/camera members, fade alpha, and the file's static init 0x194710
// with its _GLOBAL__I_ stub 0x194750 and the gap _GLOBAL__D_ stub 0x194770 (written here).
// Flags: -G0.
#include "../common/types.h"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../yasui/libys/obj.hpp"
#include "../tozawa/menu_sound.hpp"

// ---- 00193be8 from src/anon/batch_w100.cpp
namespace n00193be8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord Cross(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline QWord Scale(const QWord& a, f32 s)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
void func_00193be8(void* self, const QWord* a, const QWord* b, QWord* m) asm("func_00193be8");
void func_00193be8(void* self, const QWord* a, const QWord* b, QWord* m) {
    m[0] = Cross(*a, *b);
    Normalize(&m[0]);
    m[0].f[3] = 0.0f;
    QWord* z = &m[2];
    *z = Scale(*a, -1.0f);
    Normalize(z);
    z->f[3] = 0.0f;
    QWord* y = &m[1];
    *y = Cross(*z, m[0]);
    Normalize(y);
    y->f[3] = 0.0f;
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&m[3]) : "memory");
}
}  // namespace n00193be8

// ---- 00193d38 from src/anon/batch_wcx2.cpp
namespace n00193d38 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct B32 { f32 a, y, c; u32 d; Vec4 pos; };
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
void YS__COLLISION__set(B32*, u8*, u32) asm("YS__COLLISION__set");
s32 func_001a7610(Vec4*, VecD*, s32, f32, f32) asm("func_001a7610");
struct VA14;
void func_00193be8(u8*, VA14*, void*, u32) asm("func_00193be8");
extern u8 D_01c61ae0[] asm("D_01c61ae0");
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
void YS__OBJ__make_matrix_lk(u8* p, u32 a1) asm("YS__OBJ__make_matrix_lk");
void YS__OBJ__make_matrix_lk(u8* p, u32 a1)
{
    B32 b;
    VecD out[2];
    VA14 dir;
    b.d = 0;
    u32* q = (u32*)(p + 1636);
    for (s32 i = 0; i < 2; i++) {
        YS__COLLISION__set(&b, p, *q++);
        func_001a7610(&b.pos, &out[i], ((s32)(*(s64*)(p + 1536) << 29 >> 32)) & 0xf, 0.0f, b.c);
    }
    dir = out[0] - out[1];
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&dir) : "$8", "$f0", "memory");
    func_00193be8(p, &dir, D_01c61ae0, a1);
}
}  // namespace n00193d38

// ---- 00193e88 from src/anon/batch_w280.cpp
namespace n00193e88 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct QMat {
    QWord r[4];
    QMat() {}
    QMat& operator=(const QMat& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void MulMat(QMat* r, const QMat* a, const QMat* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tvmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\tvmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\tvmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\tsqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                 : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline QMat Mul(const QMat& a, const QMat& b)
{
    QMat r;
    MulMat(&r, &a, &b);
    return r;
}
typedef void (*VF2)(u8*, QMat*);
QWord func_0017fe10(u8*, f32) asm("func_0017fe10");
void func_0011b6a8(QMat*) asm("func_0011b6a8");
QMat* func_0011b720(QMat*, f32) asm("func_0011b720");
void func_00193e88(u8* o) asm("func_00193e88");
void func_00193e88(u8* o)
{
    QWord v;
    QMat m;
    QMat* pm = &m;
    v = func_0017fe10(o + 320, -1.0f);
    func_0011b6a8(pm);
    pm->r[3].f[0] = -v.f[0];
    pm->r[3].f[1] = -v.f[1];
    pm->r[3].f[2] = -v.f[2];
    *(QMat*)(o + 1712) = Mul(*(QMat*)(o + 64), *func_0011b720(pm, -v.f[3]));
    *(QWord*)(o + 1840) = *(QWord*)(o + 112);
    if (*(u32*)(o + 1416) & 0x8000000)
        ((VF2)((*(void***)o)[32]))(o, (QMat*)(o + 1712));
}
}  // namespace n00193e88

// ---- 00194010 from src/anon/auto80_199_queue.cpp
namespace n00194010 {
u32 func_00194010(u32 a0) asm("_Z13func_00194010j");
u32 func_00194010(u32 a0) {
    u32 s0 = a0;
    func_001ad9c8(a0 + 2092);                             
    func_001ad9c8(s0 + 2240);                             
    func_001942b8(s0);
    if (func_001ad9c8(s0 + 2248) != 0) {                             
        func_00194120(s0, *(f32*)(s0 + 2248));
    }
    func_001ad9c8(s0 + 2256);                             
    return func_001ad9c8(s0 + 2100);                             
}
}  // namespace n00194010

// ---- 00194070 from src/anon/tiny_wrappers_more.cpp
namespace n00194070 {
u32 kn__ModelObj__setDefaultTexanm(u32, u32, u32, u32) asm("_Z30kn__ModelObj__setDefaultTexanmjjjj");
u32 func_00194070(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00194070jjjj");
u32 func_00194070(u32 a0, u32 a1, u32 a2, u32 a3) {
    return kn__ModelObj__setDefaultTexanm(((u32)(*(u32*)((u32)(a0) + 1648u))), a1, a2, a3);
}
}  // namespace n00194070

// ---- 00194088 from src/anon/tiny_wrappers_more.cpp
namespace n00194088 {
u32 kn__ModelObj__resetDefaultTexanm(u32, u32, u32, u32) asm("_Z32kn__ModelObj__resetDefaultTexanmjjjj");
u32 func_00194088(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00194088jjjj");
u32 func_00194088(u32 a0, u32 a1, u32 a2, u32 a3) {
    return kn__ModelObj__resetDefaultTexanm(((u32)(*(u32*)((u32)(a0) + 1648u))), a1, a2, a3);
}
}  // namespace n00194088

// ---- 001940a0 from src/anon/tiny_wrappers_more.cpp
namespace n001940a0 {
u32 kn__ModelObj__setTexanm(u32, u32, u32, u32) asm("_Z23kn__ModelObj__setTexanmjjjj");
u32 func_001940a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001940a0jjjj");
u32 func_001940a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return kn__ModelObj__setTexanm(((u32)(*(u32*)((u32)(a0) + 1648u))), a1, a2, a3);
}
}  // namespace n001940a0

// ---- 001940b8 from src/anon/batch_w21.cpp
namespace n001940b8 {
void func_001ad990(u32, f32, f32, f32) asm("_Z13func_001ad990jfff");
void func_001940b8(u8* p, u32 a, u32 b, u32 c, f32 x, f32 y) asm("func_001940b8");
void func_001940b8(u8* p, u32 a, u32 b, u32 c, f32 x, f32 y) {                           
    p[1664] = a;
    p[1665] = b;
    p[1666] = c;
    func_001ad990((u32)(p + 2240), *(f32*)(p + 2240), x, y);
}
}  // namespace n001940b8

// ---- 001940f0 from src/anon/tiny_wrappers_more.cpp
namespace n001940f0 {
u32 func_0011c7c8(u32, u32, u32, u32) asm("_Z13func_0011c7c8jjjj");
u32 func_001940f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001940f0jjjj");
u32 func_001940f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0011c7c8(((u32)(*(u32*)((u32)(a0) + 1648u))), a1, a2, a3);
}
}  // namespace n001940f0

// ---- 00194108 from src/anon/tiny_wrappers_more.cpp
namespace n00194108 {
u32 func_0011c7f8(u32, u32, u32, u32) asm("_Z13func_0011c7f8jjjj");
u32 func_00194108(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00194108jjjj");
u32 func_00194108(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0011c7f8(((u32)(*(u32*)((u32)(a0) + 1648u))), a1, a2, a3);
}
}  // namespace n00194108

// ---- 00194120 from src/anon/batch_w89.cpp
namespace n00194120 {
void func_00194218(u8*, s32, f32) asm("func_00194218");
void func_00194120(u8* o, f32 v) asm("func_00194120");
void func_00194120(u8* o, f32 v) {
    f32 c = v < 0.0f ? 0.0f : (1.0f < v ? 1.0f : v);
    o[1696] = (s32)(c * 255.0f);
    u16 type = *(u16*)(*(u8**)(o + 8) + 76);
    if (type != 5000) {
        if (type == 5002) {
            func_00194218(o, 0, 1.0f - c);
            func_00194218(o, 1, c);
        }
    } else {
        for (s32 i = 0; i < 10; i++) func_00194218(o, i, c);
    }
}
}  // namespace n00194120

// ---- 00194218 from src/anon/batch_w2368.cpp
namespace n00194218 {
struct W2368Snd { u8 pad[0xc]; f32 vol; };
struct W2368Slot { u8 pad[8]; s32 h; };
struct W2368Obj { u8 pad0[0x9c]; u8 res[0x7b0 - 0x9c]; s32 arr[8]; };
s32 ryj__PAX__start(void*, s32, s32, s32, s32, W2368Obj*) asm("ryj__PAX__start");
W2368Snd* func_001dc670(s32) asm("func_001dc670");
void func_001dc920(s32) asm("func_001dc920");
static inline W2368Slot* w2368_slot(W2368Obj* o, s32 i) { return (W2368Slot*)(i * 4 + (u32)o + 0x7b0); }
void func_00194218(W2368Obj* o, s32 i, f32 v) asm("func_00194218");
void func_00194218(W2368Obj* o, s32 i, f32 v) {
    if (v > 0.0f) {
        if (w2368_slot(o, i)->h == 0) w2368_slot(o, i)->h = ryj__PAX__start(o->res, i, 0, 1, 0, o);
        func_001dc670(w2368_slot(o, i)->h)->vol *= v;
    } else if (w2368_slot(o, i)->h) {
        func_001dc920(w2368_slot(o, i)->h);
        w2368_slot(o, i)->h = 0;
    }
}
}  // namespace n00194218

// ---- 001942b8 from src/anon/batch_w64.cpp
namespace n001942b8 {
void func_001dcb98(u32, u8*) asm("func_001dcb98");
void func_001942b8(u8* p) asm("func_001942b8");
void func_001942b8(u8* p) {
    for (s32 i = 0; i < 16; i++) {
        u32 x = *(u32*)(p + 1976 + i * 4);
        if (x) func_001dcb98(x, p + 1880);
    }
}
}  // namespace n001942b8

// ---- 00194318 from src/anon/batch_w90.cpp
namespace n00194318 {
u8* func_001bfd60(void*, u32) asm("func_001bfd60");
void func_00194318(u8* self) asm("func_00194318");
void func_00194318(u8* self)
{
    s32 d = self[2268] == 1 ? -16 : 16;
    s32 v = self[2269] + d;
    self[2269] = v < 0 ? 0 : (v < 129 ? v : 128);
    u8* a = func_001bfd60(self + 2272, 0xffc00);
    u8* b = func_001bfd60(self + 2272, 0x3ff00000);
    *(u32*)(self + 1656) |= 0x10;
    u8 x = self[2269];
    if (x < 64) { a[7] = 0x80; b[7] = self[2269] * 2; }
    else { a[7] = -(x * 2); b[7] = 0x80; }
}
}  // namespace n00194318

// ---- 001943e8 from src/anon/batch_w62.cpp
namespace n001943e8 {
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
s32 func_001943e8(u8* p) asm("func_001943e8");
s32 func_001943e8(u8* p) {
    s32 r = 0;
    f32* v = (f32*)(p + 48);
    for (s32 i = 2; i >= 0; i--) {
        if (*v < 0.0f) r ^= 1;
        v++;
    }
    if (func_001c0cd8(p)) r = (r ^ func_001943e8(*(u8**)(p + 1392))) != 0;
    return r;
}
}  // namespace n001943e8

// ---- 00194468 from src/anon/batch_w1839_nsa.cpp
namespace n00194468 {
struct Obj {
    u8 pad0[0x10c]; u32 f10c;
    u8 pad1[0x768 - 0x110]; u32 f768;
    u8 pad2[0x9ac - 0x76c]; u8 mode;
};
static inline void setSub(Obj* p, s32 s) {
    switch (s) {
    case 0: p->f768 &= ~0x200; p->f768 &= ~0x400; break;
    case 1: p->f768 |= 0x200; p->f768 &= ~0x400; break;
    case 2: p->f768 &= ~0x200; p->f768 |= 0x400; break;
    }
}
void wtarget_00194468(Obj* p, u32, u32, u32) asm("_Z16wtarget_00194468jjjj");
void wtarget_00194468(Obj* p, u32, u32, u32) {
    switch (p->mode) {
    case 0: p->f10c |= 0x200; break;
    case 1: case 2: case 3: setSub(p, p->mode - 1); p->f10c &= ~0x200; break;
    case 4: case 5: case 6: setSub(p, p->mode - 4); p->f10c |= 0x200; break;
    }
}
}  // namespace n00194468

// ---- 001945a0 from src/anon/batch_w1518.cpp
namespace n001945a0 {
u8* func_001bfd60(u8*, s32) asm("func_001bfd60");
void func_001ad990(u8*, f32, f32, f32) asm("func_001ad990");
struct Col1945 { u8 r, g, b, a; };
void func_001945a0(u8* a, f32 f, s32 b, u32 c) asm("func_001945a0");
void func_001945a0(u8* a, f32 f, s32 b, u32 c) {
    u8* r = func_001bfd60(a + 2272, b);
    Col1945* q = (Col1945*)(r + 4);
    q->r = c; q->g = c >> 8; q->b = c >> 16; q->a = c >> 24;
    func_001ad990(r + 8, 0.0f, 1.0f, f);
}
}  // namespace n001945a0

// ---- 00194610 from src/anon/tiny_auto80_queue.cpp
namespace n00194610 {
void func_001ad990(u32, f32, f32, f32) asm("_Z13func_001ad990jfff");
u32 func_001bfd60(...) asm("func_001bfd60");
void func_00194610(u32 a0, f32 a1) asm("_Z13func_00194610jf");
void func_00194610(u32 a0, f32 a1) {
    f32 f20 = a1;
    u32 v0 = ((u32(*)(u32, f32))func_001bfd60)((u32)((s32)a0 + (2272)), a1);
    func_001ad990((u32)((s32)v0 + (8)), *(f32*)((u32)v0 + (s32)(8)), 0.0f, f20);
}
}  // namespace n00194610

// ---- 00194648 from src/yasui/libys/obj.cpp
namespace YS {
void OBJ::attach_camera(kn::FMatrix* camera) {
    u32 v0 = *(u32*)((u32)this + 268);
    u32 v1 = *(u32*)((u32)this + 1896);
    *(u32*)((u32)this + 1936) = (u32)camera;
    *(u32*)((u32)this + 268) = v0 | 0x40u;
    *(u32*)((u32)this + 1896) = v1 | 0x1000u;
}
}  // namespace YS

// ---- 00194668 from src/anon/auto200_999.cpp
namespace n00194668 {
void func_00194668(u32 a0) asm("_Z13func_00194668j");
void func_00194668(u32 a0) {
    u32 v0 = *(u32 *)(a0 + 268);
    u32 v1 = *(u32 *)(a0 + 1896);
    v0 &= 0xffffffbf;
    *(u32 *)(a0 + 1936) = 0;
    v1 &= 0xffffefff;
    *(u32 *)(a0 + 268) = v0;
    *(u32 *)(a0 + 1896) = v1;
}
}  // namespace n00194668

// ---- 00194690 from src/anon/auto80_199_queue.cpp
namespace n00194690 {
f32 func_00194690(u32 a0) asm("_Z13func_00194690j");
f32 func_00194690(u32 a0) {
    u32 s0 = a0;
    f32 s4 = *(f32*)(a0 + 2092) * *(f32*)(a0 + 2100);
    if (func_001c0cd8(a0) != 0) {
        if ((*(u16*)(s0 + 1398) & 4) == 0) {
            s4 = s4 * func_00194690(*(u32*)(s0 + 1392));
        }
    }
    return s4;
}
}  // namespace n00194690

// ---- 001946f0 from src/anon/auto200_999.cpp
namespace n001946f0 {
u32 YS_OBJ_get_draw_color(u32) asm("_ZN2YS3OBJ14get_draw_colorEv");
u32 YS_OBJ_get_draw_color(u32 a0) {
    u32 flag = *(u32 *)(a0 + 1416);
    u32 alt = a0 + 1880;
    flag &= 0x20000000;
    a0 += 2236;
    if (flag == 0) {
        a0 = alt;
    }
    return a0;
}
}  // namespace n001946f0

// ---- 00194710 from src/anon/batch_w1670.cpp
namespace n00194710 {
struct F4_w1670 { f32 a, b, c, d; };
extern F4_w1670 D_01c61ae0 asm("D_01c61ae0");
void wtarget_00194710(u32 a, u32 b, u32, u32) asm("_Z16wtarget_00194710jjjj");
void wtarget_00194710(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        f32 z = 0.0f, o = 1.0f;
        D_01c61ae0.a = z;
        D_01c61ae0.b = o;
        D_01c61ae0.c = z;
        D_01c61ae0.d = o;
    }
}
}  // namespace n00194710

// ---- 00194750 from src/anon/tiny_wrappers_more.cpp
namespace n00194750 {
u32 func_00194710(u32, u32, u32, u32) asm("_Z16wtarget_00194710jjjj");
u32 func_00194750(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00194750jjjj");
u32 func_00194750(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00194710(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n00194750


// ---- 00194770 gap: _GLOBAL__D_ stub of the 0x194710 static init (unwritten before)
namespace n00194770 {
u32 func_00194710(u32, u32, u32, u32) asm("_Z16wtarget_00194710jjjj");
u32 func_00194770(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00194770");
u32 func_00194770(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00194710(0, 0x0000ffffu, a2, a3);
}
}  // namespace n00194770
