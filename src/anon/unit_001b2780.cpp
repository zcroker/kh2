// Linked unit 0x001b2780-0x001b65e0 (one namespace per old matched source; class methods in their own namespace).
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
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../yasui/libys/levelup.hpp"

// 001b2780 (was src/anon/batch_w20.cpp)
namespace n001b2780 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
void func_0017c4c8(void*, Q16*) asm("func_0017c4c8");
void func_0016bd60(void*, s32) asm("func_0016bd60");
/*TARGET 001b2780*/
// 0x00190140: definition moved into src/anon/unit_001900d0.cpp

// 00191c50: moved to src/yasui/libys/status.cpp

// 001ac1d0: moved to src/anon/unit_001abb28.cpp

// 001b1ff0: moved to src/anon/unit_001b1d20.cpp

void func_001b2780(void* a0, void* a1, Q16* a2) asm("func_001b2780");
// 0x00190140: definition moved into src/anon/unit_001900d0.cpp

// 00191c50: moved to src/yasui/libys/status.cpp

// 001ac1d0: moved to src/anon/unit_001abb28.cpp

// 001b1ff0: moved to src/anon/unit_001b1d20.cpp

void func_001b2780(void* a0, void* a1, Q16* a2) {
    Q16 t;
    QCOPY(&t, a2);
    func_0017c4c8(a1, &t);
    func_0016bd60(a1, 20);
}
}  // namespace n001b2780

// 001b27c0 (was src/anon/batch_w6.cpp)
namespace n001b27c0 {
// 001a6c60: moved to src/anon/unit_001a6a10.cpp

void func_0017c430(u32) asm("func_0017c430");
void func_0016bd60(u32, u32) asm("func_0016bd60");
/*TARGET 001b27c0*/
void func_001b27c0(u32, u32 a) asm("func_001b27c0");
void func_001b27c0(u32, u32 a) {
    func_0017c430(a);
    func_0016bd60(a, 20);
}
}  // namespace n001b27c0

// 001b27f0 (was src/anon/batch_w46.cpp)
namespace n001b27f0 {
// 16-byte vector whose copy constructor is a 128-bit lq/sq (used for by-value passing).
struct Vc {
    f32 x, y, z, w;
    Vc() {}
    Vc(const Vc& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
// 001b2380: moved to src/anon/unit_001b1d20.cpp

// ---- 001b27f0
Vc func_0017c030(u8*, u32*, u8) asm("func_0017c030");
void func_001b6dd0(u8*, Vc) asm("func_001b6dd0");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
/*TARGET 001b27f0*/
void func_001b27f0(u32, u8* p, u8 f) asm("func_001b27f0");
void func_001b27f0(u32, u8* p, u8 f) {
    u32 x;
    Vc v = func_0017c030(p, &x, f);
    func_001b6dd0(p, v);
    p[1300] = 4;
    func_0017f488(p + 320, x, 0.0f, 0.0f);
    *(u32*)(p + 256) = 4;
    *(u32*)(p + 260) = 5;
}
}  // namespace n001b27f0

// 001b2860 (was src/anon/batch_w320.cpp)
namespace n001b2860 {
struct Cfg { u8 pad[172]; f32 f172; u8 pad176[12]; f32 f188; };
extern Cfg* D_00352130 asm("D_00352130");
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QWord& operator=(const QWord& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline f32 Normalize(QWord* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline f32 Dot(QWord& a, QWord& b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
static inline void ScaleIn(QWord* v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(v), "f"(s) : "$8", "memory");
}
struct P300 { u8 pad[36]; f32 f36; };
struct Ob {
    u8 p0[16]; QWord q16; QWord q32; u8 p48[240 - 48]; f32 f240; u8 p244[272 - 244]; f32 f272; u8 p276[300 - 276]; P300* p300;
    u8 p304[320 - 304]; u8 sub[32]; u32 f352; u8 p356[2208 - 356]; QWord q2208;
};
struct Ob2 { u8 pad[320]; u8 sub[32]; };
extern Ob2* D_00351068 asm("D_00351068");
extern f32 D_00349e10 asm("D_00349e10");
void func_0016af58(QWord*) asm("func_0016af58");
s32 func_001b2b58(Ob*) asm("func_001b2b58");
void func_0017f540(void*, s32, f32, f32) asm("func_0017f540");
/*TARGET 001b2860*/
void func_001b2860(void* self, Ob* o) asm("func_001b2860");
void func_001b2860(void* self, Ob* o)
{
    QWord v;
    s32 id = 0;
    v = o->q2208;
    f32 len = Normalize(&v);
    v.f[3] = len;
    if (8.0f < len) {
        QWord t;
        func_0016af58(&t);
        if (Dot(v, t) < -0.865999996662f) o->f240 = 0;
        ScaleIn(&o->q32, 0.5f);
    }
    v = o->q32;
    v.f[1] = 0.0f;
    Normalize(&v);
    if (o->q16.f[3] > o->f272) {
        if (func_001b2b58(o)) {
            id = 2;
            o->q16.f[3] = o->p300->f36;
        } else {
            f32 d = Dot(v, o->q16);
            if (D_00352130->f172 < d) o->f240 += D_00349e10;
            else o->f240 = 0;
        }
    } else {
        o->f240 = 0;
    }
    void* sb = o->sub;
    if (o->f352 & 4) {
        f32 k = 12.0f, z = 0.0f;
        func_0017f540(sb, id, k, z);
        func_0017f540(D_00351068->sub, id, k, z);
    }
}
}  // namespace n001b2860

// 001b2a90 (was gap, never written)
namespace n001b2a90 {
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QWord& operator=(const QWord& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline f32 Normalize(QWord* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Cfg { u8 pad[180]; f32 f180; f32 f184; };
extern Cfg* D_00352130 asm("D_00352130");
struct P300 { u8 pad[40]; f32 f40; f32 f44; };
struct Ob { u8 p0[32]; QWord q32; u8 p48[300 - 48]; P300* p300; };
s32 func_001b2b58(Ob*) asm("_Z13func_001b2b58Ph");
QWord func_00184540(Ob*, f32, f32) asm("_Z13func_00184540jjff");
QWord func_001b2a90(void* self, Ob* o) asm("func_001b2a90");
QWord func_001b2a90(void* self, Ob* o) {
    QWord v;
    f32 a = o->p300->f40;
    f32 b = o->p300->f44;
    v = o->q32;
    v.f[1] = 0.0f;
    Normalize(&v);
    if (func_001b2b58(o)) {
        Cfg* c = D_00352130;
        a = c->f180;
        b = c->f184;
    }
    return func_00184540(o, a, b);
}
}


// 001b2b58 (was src/anon/tiny_auto80_queue.cpp)
namespace n001b2b58 {
/*TARGET 001b2b58*/
// 001b1400: moved to src/yasui/libys/databuff.cpp

// 001b1b58: moved to src/anon/unit_001b14d8.cpp

// 001b1c10: moved to src/anon/unit_001b14d8.cpp

// 001b2028: moved to src/anon/unit_001b1d20.cpp

u32 func_001b2b58(u8* a0) asm("_Z13func_001b2b58Ph");
// 001b1400: moved to src/yasui/libys/databuff.cpp

// 001b1b58: moved to src/anon/unit_001b14d8.cpp

// 001b1c10: moved to src/anon/unit_001b14d8.cpp

// 001b2028: moved to src/anon/unit_001b1d20.cpp

u32 func_001b2b58(u8* a0) {
    f32 f1 = *(f32*)(a0 + 240);
    u32* b = (u32*)0x00350000;
    u32 p = b[2124];
    f32 f0 = *(f32*)(p + 176);
    if (f0 <= f1) {
        return 1;
    }
    return 0;
}
}  // namespace n001b2b58

// 001b2b80 (was src/anon/auto80_199_queue.cpp)
namespace n001b2b80 {
/*TARGET 001b2b80*/
// 0x001b03b0: definition moved into src/anon/unit_001ada38.cpp

// 001b04d8: moved to src/yasui/libys/lookat.cpp

// 001b1da0: moved to src/anon/unit_001b1d20.cpp

u32 func_001b2b80(u32 a0, u32 a1) asm("_Z13func_001b2b80jj");
// 0x001b03b0: definition moved into src/anon/unit_001ada38.cpp

// 001b04d8: moved to src/yasui/libys/lookat.cpp

// 001b1da0: moved to src/anon/unit_001b1d20.cpp

u32 func_001b2b80(u32 a0, u32 a1) {
    u32 s1 = a0;
    u32 s0 = a1;

    if (func_0019c090(a1) == 0) {  // obj_is_enabled
        u32 v0 = func_0016c028(s0);  // obj_get_attach_or_alt
        *(f32*)(s0 + 224) = *(f32*)(v0 + 4);
    }

    return func_0017c578(s1, s0);
}
}  // namespace n001b2b80

// 001b2bd8 (was gap, never written)
namespace n001b2bd8 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY_G(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
void func_0017c4c8(void*, Q16*) asm("func_0017c4c8");
void func_0016bd60(void*, s32) asm("func_0016bd60");
void func_001b2bd8(void* a0, void* a1, Q16* a2) asm("func_001b2bd8");
void func_001b2bd8(void* a0, void* a1, Q16* a2) {
    Q16 t;
    QCOPY_G(&t, a2);
    func_0017c4c8(a1, &t);
    func_0016bd60(a1, 20);
}
#undef QCOPY_G
}


// 001b2c18 (was src/anon/batch_w7.cpp)
namespace n001b2c18 {
void func_0017c430(u32) asm("func_0017c430");
void func_0016bd60(u32, u32) asm("func_0016bd60");
/*TARGET 001b2c18*/
// 0x001ae650: definition moved into src/anon/unit_001ada38.cpp

void func_001b2c18(u32 a0, u32 a1) asm("func_001b2c18");
// 0x001ae650: definition moved into src/anon/unit_001ada38.cpp

void func_001b2c18(u32 a0, u32 a1) {
    func_0017c430(a1);
    func_0016bd60(a1, 20);
}
}  // namespace n001b2c18

// 001b2c48 (was src/anon/batch_w1786.cpp)
namespace n001b2c48 {
struct W1786V4 { f32 x, y, z, w;
  W1786V4& operator=(const W1786V4& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct W1786VC { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(void*); };
// 0x00190a80: definition moved into src/anon/unit_001900d0.cpp

W1786V4 func_0017c870(f32, f32) asm("func_0017c870");
s32 func_001b2d10(void*, W1786V4*) asm("func_001b2d10");
/*TARGET 001b2c48*/
W1786V4 func_001b2c48(W1786VC* c, void* x) asm("func_001b2c48");
W1786V4 func_001b2c48(W1786VC* c, void* x) {
    W1786V4 d;
    W1786V4 r;
    r = func_0017c870(0.9f, 0.95f);
    if (r.y > 0.0f && func_001b2d10(x, &r)) c->f5(x);
    return r;
}
}  // namespace n001b2c48

// 001b2cf8 (was src/anon/tiny_wrappers_more.cpp)
namespace n001b2cf8 {
u32 func_0017cc30(u32, u32, u32, u32) asm("_Z13func_0017cc30jjjj");
/*TARGET 001b2cf8*/
// 001b2708: moved to src/anon/unit_001b1d20.cpp

u32 func_001b2cf8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b2cf8jjjj");
// 001b2708: moved to src/anon/unit_001b1d20.cpp

u32 func_001b2cf8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0017cc30(a0, a1, 0x0000000au, a3);
}
}  // namespace n001b2cf8

// 001b2d10 (was src/anon/batch_wcx.cpp)
namespace n001b2d10 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
// 0x001ae8d8: definition moved into src/anon/unit_001ada38.cpp

V4* func_0016c028(u8*) asm("func_0016c028");
// obj_get_attach_or_alt
f32 func_001849d8(u8*) asm("func_001849d8");
/*TARGET 001b2d10*/
s32 func_001b2d10(u8* p, f32* q) asm("func_001b2d10");
s32 func_001b2d10(u8* p, f32* q)
{
    V4 t;
    V4* src = func_0016c028(p);  // obj_get_attach_or_alt
    // 128-bit copy (lq/sq)
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(src) : "$8", "memory");
    f32 s = t.y + q[1];
    if (func_001849d8(p) - 100.0f <= s) { q[1] = 0; return 1; }
    if (*(f32*)(p + 224) <= s) { q[1] = *(f32*)(p + 224) - t.y; return 1; }
    return 0;
}
}  // namespace n001b2d10

// 001b2db0 (was gap, never written)
namespace n001b2db0 {
void func_001b2db0(u32, u8* p) asm("func_001b2db0");
void func_001b2db0(u32, u8* p) { *(u32*)(p + 240) = 0; }
}


// 001b2db8 (was src/anon/batch_w271.cpp)
namespace n001b2db8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V4_w271 {
    f32 x, y, z, w;
    V4_w271() {}
    V4_w271(const V4_w271& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
struct VT_w271 { void* f[32]; };
struct Obj_w271 { VT_w271* vt; };
extern u32 D_0034e948 asm("D_0034e948");
u32 func_0019ba60(u32) asm("func_0019ba60");
u32 func_0019c090(u32) asm("func_0019c090");
// obj_is_enabled
u32 func_0019c5d0(Obj_w271*) asm("func_0019c5d0");
f32 func_001849d8(u32) asm("func_001849d8");
u32 c5d0f(Obj_w271*, f32) asm("func_0019c5d0");
V4_w271* func_0016c028(u32) asm("func_0016c028");
// obj_get_attach_or_alt
f32 func_0016afe0(u32) asm("func_0016afe0");
void func_0016aeb8(Obj_w271*, f32) asm("func_0016aeb8");
void func_0016ace0(Obj_w271*, V4_w271*) asm("func_0016ace0");
void func_0016ad68(Obj_w271*, u32) asm("func_0016ad68");
void func_0016ac38(Obj_w271*, s32, s32, s32, s32) asm("func_0016ac38");
/*TARGET 001b2db8*/
void func_001b2db8(u32 self, Obj_w271* o) asm("func_001b2db8");
void func_001b2db8(u32 self, Obj_w271* o) {
    u32 w = D_0034e948;
    if (func_0019ba60(w)) {
        if (func_0019c090(w)) {  // obj_is_enabled
            if (!c5d0f(o, 0.0f)) {
                f32 a = func_001849d8(w);
                if (a < func_0016c028((u32)o)->y) ((void (*)(Obj_w271*))o->vt->f[17])(o);  // obj_get_attach_or_alt
            }
            func_0016aeb8(o, func_0016afe0(w));
            V4_w271 t(*func_0016c028(w));  // obj_get_attach_or_alt
            t.y = (func_0016c028((u32)o)->y < t.y) ? t.y : func_0016c028((u32)o)->y;
            func_0016ace0(o, &t);
        } else {
            func_0016ad68(o, w);
            if (func_0019c5d0(o)) {
                func_0016ac38(o, 1, 1, 0, 0);
                ((void (*)(Obj_w271*))o->vt->f[18])(o);
            }
        }
    }
    asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"((u8*)o + 16) : "memory");
}
}  // namespace n001b2db8

// 001b2f10 (was src/anon/batch_w12.cpp)
namespace n001b2f10 {
void* func_001050c8(void) asm("func_001050c8");
void func_00165898(void*) asm("func_00165898");
extern s32 D_01d48c90 asm("D_01d48c90");
/*TARGET 001b2f10*/
// 0x001b0148: definition moved into src/anon/unit_001ada38.cpp

// 001b1328: moved to src/yasui/libys/lookat.cpp

void func_001b2f10(void) asm("func_001b2f10");
// 0x001b0148: definition moved into src/anon/unit_001ada38.cpp

// 001b1328: moved to src/yasui/libys/lookat.cpp

void func_001b2f10(void) {
    D_01d48c90 = 1;
    func_00165898(func_001050c8());
}
}  // namespace n001b2f10

// 001b2f38 (was src/anon/batch_w1806_nsa.cpp)
namespace n001b2f38 {
struct W1806Ent { s32 a; s32 off; };
struct W1806Hdr { s32 x; s32 n; W1806Ent e[1]; };
struct W1806Item { u8 pad[128]; s32 h; u8 pad2[12]; };
struct W1806Set { W1806Hdr* h; W1806Item* e; s32 p8; s32 id; };
void* func_001050d8(s32) asm("func_001050d8");
void func_00165870(s32) asm("func_00165870");
s32 func_001659b8(void*, s32) asm("func_001659b8");
extern s32 D_01d48c90 asm("D_01d48c90");
/*TARGET 001b2f38*/
void func_001b2f38(W1806Set* o, W1806Hdr* h, u8 flag) asm("func_001b2f38");
void func_001b2f38(W1806Set* o, W1806Hdr* h, u8 flag) {
    s32 i;
    o->h = h;
    o->e = (W1806Item*)func_001050d8(h->n * 144);
    for (i = 0; i < o->h->n; i++) {
        o->e[i].h = func_001659b8((u8*)o->h + o->h->e[i].off, D_01d48c90);
        if (!flag) func_00165870(o->e[i].h);
    }
    o->id = D_01d48c90++;
}
}  // namespace n001b2f38

// 001b3018 (was src/anon/batch_w65.cpp)
namespace n001b3018 {
void func_00105110(void*) asm("func_00105110");
// 001a3a88: moved to src/yasui/libys/effect.cpp

void func_00165768(u32) asm("func_00165768");
/*TARGET 001b3018*/
void func_001b3018(u32* p) asm("func_001b3018");
void func_001b3018(u32* p) {
    if (p[0]) {
        s32 i;
        for (i = 0; i < *(s32*)(p[0] + 4); i++) func_00165768(*(u32*)(p[1] + i * 144 + 128));
        func_00105110((void*)p[1]);
        p[0] = 0;
    }
}
}  // namespace n001b3018

// 001b3098 (was src/anon/batch_w50.cpp)
namespace n001b3098 {
struct Arr144 { u8* hdr; u8* arr; };
void func_00165768(u32) asm("func_00165768");
void func_00105110(void*) asm("func_00105110");
/*TARGET 001b3098*/
void func_001b3098(Arr144* s) asm("func_001b3098");
void func_001b3098(Arr144* s) {
    if (!s->hdr) return;
    for (s32 i = 0; i < *(s32*)(s->hdr + 4); i++) func_00165768(*(u32*)(s->arr + i * 144 + 128));
    func_00105110(s->arr);
    s->hdr = 0;
}
}  // namespace n001b3098

// 001b3118 (was src/anon/batch_w82.cpp)
namespace n001b3118 {
struct Mat82 { f32 m[16]; } __attribute__((aligned(16)));
struct Lst001b { u8 pad[4]; s32 count; struct { u32 item; u32 x; } e[1]; };
struct Bones001b { Lst001b* t; u8* arr; s32 idx; };
// 64-byte quadword copy (four lq then four sq).
static inline void Copy64_82(void* d, const void* s)
{
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
        : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
void func_0016b0e0(u32, u32, u8*) asm("func_0016b0e0");
void func_00165830(u32, Mat82*) asm("func_00165830");
/*TARGET 001b3118*/
// Updates each bone matrix into the current double-buffer half, then flips halves.
void func_001b3118(Bones001b* b, u32 a1) asm("func_001b3118");
// Updates each bone matrix into the current double-buffer half, then flips halves.
void func_001b3118(Bones001b* b, u32 a1)
{
    s32 i;
    if (!b->t) return;
    for (i = 0; i < b->t->count; i++) {
        Mat82 m;
        func_0016b0e0(a1, b->t->e[i].item, b->arr + i * 144 + b->idx * 64);
        Copy64_82(&m, b->arr + i * 144 + b->idx * 64);
        func_00165830(*(u32*)(b->arr + i * 144 + 128), &m);
    }
    b->idx ^= 1;
}
}  // namespace n001b3118

// 001b3208 (was src/anon/batch_wcx2.cpp)
namespace YS { // method 001b3208
struct HeapE;
void* operator new[](unsigned int, HeapE*) asm("func_001063f0");
struct OEnt_001b3208 { s32 id; u32 y; };
struct OTab_001b3208 { u32 x; s32 n; OEnt_001b3208 e[1]; };
union OFl_001b3208 { u32 f; OTab_001b3208* t; };
struct OObj_001b3208 { u8 pad[128]; OFl_001b3208* p; u8 pad2[12]; };
struct OBJOCC { OTab_001b3208* tab; OObj_001b3208* objs; void disable(int); };
/*TARGET 001b3208*/
void OBJOCC::disable(int id) {
    for (s32 i = 0; i < tab->n; i++) {
        if (tab->e[i].id == id) objs[i].p[2].f |= 2;
    }
}
}  // YS

// 001b3270 (was src/anon/batch_w57.cpp)
namespace n001b3270 {
extern void (**D_0032b914)() asm("D_0032b914");
// 0x001aaf98: definition moved into src/anon/unit_001aaea8.cpp

// OBJOCC::disable_all(): flag every occupant entry as disabled.
struct OccHdr { s32 f0; s32 count; };
struct OccObj { u32 a, b, flags; };
struct OccEnt { u8 p[128]; OccObj* obj; u8 q[12]; };
struct OccSelf { union { OccHdr* h; u32 uh; }; union { OccEnt* arr; u32 uarr; }; };
void OccDisableAll(OccSelf* t) asm("_ZN2YS6OBJOCC11disable_allEv");
/*TARGET 001b3270*/
void OccDisableAll(OccSelf* t) asm("_ZN2YS6OBJOCC11disable_allEv");
void OccDisableAll(OccSelf* t) {
    if (t->uh) {
        for (s32 i = 0; i < ((OccHdr*)t->uh)->count; i++) {
            ((OccEnt*)t->uarr)[i].obj->flags |= 2;
        }
    }
}
}  // namespace n001b3270

// 001b32c8 (was gap, never written): YS::OBJOCC::enable(int)
namespace n001b32c8 {
struct OEnt { s32 id; u32 y; };
struct OTab { u32 x; s32 n; OEnt e[1]; };
union OFl { u32 f; OTab* t; };
struct OObj { u8 pad[128]; OFl* p; u8 pad2[12]; };
struct OCC { OTab* tab; OObj* objs; };
void func_001b32c8(OCC* o, int id) asm("func_001b32c8");
void func_001b32c8(OCC* o, int id) {
    for (s32 i = 0; i < o->tab->n; i++) {
        if (o->tab->e[i].id == id) o->objs[i].p[2].f &= ~2;
    }
}
}


// 001b3330 (was src/anon/batch_w56.cpp)
namespace n001b3330 {
struct OccS;
struct OccH;
union OccF { u32 v; s32 i; OccS* s; OccH* h; };
struct OccE { u8 pad[8]; OccF fl; };
struct OccS { u8 pad[128]; OccE* e; u8 pad2[12]; };
struct OccH { u32 x; s32 n; };
struct OccSet { OccH* h; OccS* s; };
void occ_enable_all(OccSet* self) asm("_ZN2YS6OBJOCC10enable_allEv");
/*TARGET 001b3330*/
void occ_enable_all(OccSet* self) asm("_ZN2YS6OBJOCC10enable_allEv");
void occ_enable_all(OccSet* self)
{
    if (!self->h) return;
    for (s32 i = 0; i < self->h->n; i++) self->s[i].e->fl.v &= ~2;
}
}  // namespace n001b3330

// 001b3388 (was src/anon/batch_w1778_nsa.cpp)
namespace n001b3388 {
struct W1778Item { u8 pad[0x80]; s32 key; u8 pad2[0x90 - 0x84]; };
struct W1778Tbl { u32 a; s32 n; };
struct W1778Grp { u8 pad[0x800]; W1778Tbl* t; W1778Item* items; };
struct W1778Res { W1778Grp* g; W1778Item* it; };
W1778Grp* func_001b9bc8(W1778Grp*) asm("func_001b9bc8");
/*TARGET 001b3388*/
void func_001b3388(W1778Res* r, s32 key) asm("func_001b3388");
void func_001b3388(W1778Res* r, s32 key) {
    W1778Grp* g = 0;
    while ((g = func_001b9bc8(g)) != 0) {
        if (g->t == 0) continue;
        for (s32 i = 0; i < g->t->n; i++) {
            if (g->items[i].key == key) {
                r->g = g;
                r->it = &g->items[i];
                return;
            }
        }
    }
    r->g = 0;
}
}  // namespace n001b3388

// 001b3428 (was src/anon/batch_w1651_nsa.cpp)
namespace n001b3428 {
inline void* operator new(unsigned int, void* p) { return p; }
struct W1651Vec {
    f32 x, y, z, w;
    W1651Vec() {}
    W1651Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1651Vec& operator=(const W1651Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1651Vec operator-(const W1651Vec& o) const {
        W1651Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1651Mtx {
    W1651Vec r[4];
    W1651Mtx() {}
    W1651Mtx& operator=(const W1651Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    void inverse(const W1651Mtx& src) {
        *this = src;
        asm volatile(
            "lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
            "vopmula.xyz ACC, $vf2, $vf3\n\tvopmsub.xyz $vf5, $vf3, $vf2\n\t"
            "vopmula.xyz ACC, $vf3, $vf1\n\tvopmsub.xyz $vf6, $vf1, $vf3\n\t"
            "vopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf7, $vf2, $vf1\n\t"
            "vmul.xyz $vf8, $vf1, $vf5\n\tvmul.xyz $vf1, $vf4, $vf5\n\tvmul.xyz $vf2, $vf4, $vf6\n\tvmul.xyz $vf3, $vf4, $vf7\n\t"
            "vaddy.x $vf8, $vf8, $vf8y\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddx.y $vf2, $vf2, $vf2x\n\tvaddx.z $vf3, $vf3, $vf3x\n\t"
            "vaddz.x $vf8, $vf8, $vf8z\n\tvaddz.x $vf4, $vf1, $vf1z\n\tvaddz.y $vf4, $vf2, $vf2z\n\tvaddy.z $vf4, $vf3, $vf3y\n\t"
            "vdiv Q, $vf0w, $vf8x\n\t"
            "qmfc2 $8, $vf5\n\tqmfc2 $9, $vf6\n\tqmfc2 $10, $vf7\n\tqmfc2 $11, $vf0\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\tvwaitq\n\t"
            "vmulq.xyzw $vf1, $vf1, Q\n\tvmulq.xyzw $vf2, $vf2, Q\n\tvmulq.xyzw $vf3, $vf3, Q\n\tvmulq.xyz $vf4, $vf4, Q\n\t"
            "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    W1651Vec operator*(const W1651Vec& v) const {
        W1651Vec o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
// Double-buffered transform entry (144 bytes); the owner picks the current buffer.
struct W1651Entry { W1651Mtx m[2]; s32 pad80[4]; };
struct W1651Owner { u8 pad[0x808]; s32 cur; };
struct W1651Ref { W1651Owner* owner; W1651Entry* entry; };
struct W1651Actor;
extern s8 D_01d48c98 asm("D_01d48c98");
extern W1651Vec D_01d48ca0 asm("D_01d48ca0");
void func_001b3740(void) asm("func_001b3740");
void func_002fd188(void (*)(void)) asm("func_002fd188");
W1651Vec* func_0016c028(W1651Actor*) asm("func_0016c028");
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");
void func_001835a0(W1651Actor*, f32) asm("func_001835a0");
/*TARGET 001b3428*/
W1651Vec func_001b3428(W1651Ref* ref, W1651Actor* act) asm("func_001b3428");
W1651Vec func_001b3428(W1651Ref* ref, W1651Actor* act)
{
    if (!D_01d48c98) {
        new (&D_01d48ca0) W1651Vec(0.0f, 0.0f, 1.0f, 0.0f);
        D_01d48c98 = 1;
        func_002fd188(func_001b3740);
    }
    W1651Vec pos;
    W1651Vec dir;
    W1651Mtx m;
    W1651Vec* pd = &dir;
    W1651Mtx* pm = &m;
    pos = *func_0016c028(act);
    pos.w = 1.0f;
    pm->inverse(ref->entry->m[ref->owner->cur]);
    W1651Vec ret;
    ret = m * pos;
    ret.w = 1.0f;
    *pd = m * D_01d48ca0;
    m = ref->entry->m[ref->owner->cur ^ 1];
    ret = m * ret - pos;
    *pd = m * *pd;
    func_001835a0(act, func_002f8ad0(pd->x, pd->z));
    return ret;
}
}  // namespace n001b3428

// .rodata objects between the literal pools (retail 0x36d9f4-0x36da17)
extern "C" const u32 D_0036d9f4 = 0;
extern "C" const u8 D_0036d9f8[32] __attribute__((aligned(4))) = { 0x00, 0x01, 0x00, 0x02, 0x03, 0x04, 0x05, 0x00, 0x00, 0x00, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x00 };

// 001b3740 (was gap, never written)
namespace n001b3740 {
void func_001b3740() asm("func_001b3740");
void func_001b3740() {}
}


// 001b3748 (was src/anon/batch_w1623_g.cpp)
namespace n001b3748 {
struct W1623Vec {
    f32 x, y, z, w;
    W1623Vec() {}
    W1623Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1623Vec& operator=(const W1623Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32 normalize() {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                     : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    W1623Vec operator-(const W1623Vec& o) const {
        W1623Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1623Obj { u8 pad[1360]; W1623Vec dir; };
extern u8 D_0036d9f8[] asm("D_0036d9f8");
s32 map_is_pax_exist(void) asm("_ZN2dk3Map10isPaxExistEv");
void* map_get_pax(void) asm("_ZN2dk3Map6getPaxEv");
s32 obj_get_ground(W1623Obj*) asm("_ZN2YS3OBJ10get_groundEv");
s32 pax_search_id(void*, u64) asm("_ZN3ryj3PAX9search_idEy");
W1623Vec* effect_pos(void*) asm("_ZN3ryj6EFFECT3posEv");
W1623Vec* effect_angle(void*) asm("_ZN3ryj6EFFECT5angleEv");
void* func_001de168(void*, s32, s32, s32, s32, s32) asm("func_001de168");
W1623Vec func_0016b478(f32, W1623Obj*, u32) asm("func_0016b478");
W1623Vec* func_0016c028(W1623Obj*) asm("func_0016c028");
s32 func_001a76c8(W1623Vec*, W1623Vec*, s32) asm("func_001a76c8");
W1623Vec func_0017d050(const W1623Vec&) asm("func_0017d050");
/*TARGET 001b3748*/
// Spawns the effect for a map trigger of the given type: even types aim from the 0x8028 point
// towards 0x802c, odd types from 0x8029 towards 0x802d; any other type uses the object itself.
void func_001b3748(W1623Obj* obj, u32 type) asm("func_001b3748");
// Spawns the effect for a map trigger of the given type: even types aim from the 0x8028 point
// towards 0x802c, odd types from 0x8029 towards 0x802d; any other type uses the object itself.
void func_001b3748(W1623Obj* obj, u32 type)
{
    W1623Vec pos;
    W1623Vec tgt;
    W1623Vec dir;
    W1623Vec hit;
    s32 ok = 1;
    W1623Vec* pdir = &dir;
    W1623Vec* phit = &hit;
    if (!map_is_pax_exist()) return;
    u8 g = D_0036d9f8[obj_get_ground(obj)];
    if (!g) return;
    u64 mask = (u64)1 << g | (u64)1 << (type + 32);
    s32 k = pax_search_id(map_get_pax(), mask);
    if (k < 0) return;
    switch (type) {
    case 0: case 2: case 4: case 6: case 8: case 10: case 12: case 14: case 16: case 18:
        pos = func_0016b478(1.0f, obj, 0x8028);
        pos.y = func_0016c028(obj)->y;
        tgt = func_0016b478(1.0f, obj, 0x802c);
        *pdir = tgt - pos;
        dir.y = 0.0f;
        pdir->normalize();
        ok = func_001a76c8(&pos, phit, 0);
        break;
    case 1: case 3: case 5: case 7: case 9: case 11: case 13: case 15: case 17: case 19:
        pos = func_0016b478(1.0f, obj, 0x8029);
        pos.y = func_0016c028(obj)->y;
        tgt = func_0016b478(1.0f, obj, 0x802d);
        *pdir = tgt - pos;
        dir.y = 0.0f;
        pdir->normalize();
        ok = func_001a76c8(&pos, phit, 0);
        break;
    default:
        *phit = *func_0016c028(obj);
        *pdir = obj->dir;
        break;
    }
    if (!ok) return;
    void* e = func_001de168(map_get_pax(), k, 1, 2, 10001, 0);
    *effect_pos(e) = *phit;
    *effect_angle(e) = func_0017d050(*pdir);
}
}  // namespace n001b3748

// 4-char ids (retail 0x36da6c-0x36da87)
extern "C" const u32 D_0036da6c = 0;
extern "C" const char D_0036da70[8] __attribute__((aligned(4))) = "dead";
extern "C" const char D_0036da78[8] __attribute__((aligned(4))) = "comb";
extern "C" const char D_0036da80[8] __attribute__((aligned(4))) = "gage";

// 001b3a10 (was gap, never written) (C2 copy of 0x1b3a90)
namespace n001b3a10 {
u32 func_0016a070(void*) asm("func_0016a070");
void func_001b3b70(void*, u32, u32, u32) asm("_Z13func_001b3b70jjjjjjjj");
extern u8 D_00351078[] asm("D_00351078");
extern void* D_00351068 asm("D_00351068");
void func_001b3a10(u8* p, u32 a1, u32 a2) asm("func_001b3a10");
void func_001b3a10(u8* p, u32 a1, u32 a2) {
    func_001b3b70(p, a1, 2, a2);
    *(u32*)(p + 1416) |= 0x10000;
    *(void**)p = D_00351078;
    *(u32*)(p + 1536) &= ~0x78;
    *(u32*)(p + 944) = 1;
    if (func_0016a070(p) == 5008) D_00351068 = p;
}
}


// 001b3a90 (was src/anon/batch_w51.cpp)
namespace n001b3a90 {
u32 func_0016a070(void*) asm("func_0016a070");
// 001a5e38: moved to src/yasui/libys/magic.cpp

void func_001b3b70(void*, u32, u32, u32) asm("func_001b3b70");
extern u8 D_00351078[] asm("D_00351078");
extern void* D_00351068 asm("D_00351068");
/*TARGET 001b3a90*/
void func_001b3a90(u8* p, u32 a1, u32 a2) asm("func_001b3a90");
void func_001b3a90(u8* p, u32 a1, u32 a2) {
    func_001b3b70(p, a1, 2, a2);
    *(u32*)(p + 1416) |= 0x10000;
    *(void**)p = D_00351078;
    *(u32*)(p + 1536) &= ~0x78;
    *(u32*)(p + 944) = 1;
    if (func_0016a070(p) == 5008) D_00351068 = p;
}
}  // namespace n001b3a90

// 001b3b10 (was src/anon/auto80_199_queue.cpp)
namespace n001b3b10 {
/*TARGET 001b3b10*/
u32 func_001b3b10(u32 a0) asm("_Z13func_001b3b10j");
u32 func_001b3b10(u32 a0) {
    u32 s0 = a0;
    func_00190920(a0 + 2548, 3, s0);
    func_00198450(s0);
    u32 v0 = func_0016a070(s0);

    u32 a1 = 19;
    if (v0 != 5008) {
        return;
    }
    return func_0016bd60(s0, a1);
}
}  // namespace n001b3b10

// 001b3b70 (was src/anon/tiny_auto80_solver.cpp)
namespace n001b3b70 {
u32 func_00185ed8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00185ed8jjjjjjjj");
u32 func_001b3b70(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001b3b70jjjjjjjj");
extern u8 D_00351100 asm("D_00351100");
/*TARGET 001b3b70*/
u32 func_001b3b70(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001b3b70jjjjjjjj");
u32 func_001b3b70(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a0;
    u32 r = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00185ed8)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 mask = *(u32*)(s0 + 1420);
    u32 vtbl = (u32)&D_00351100;
    *(u32*)(s0 + 2788) = 0;
    mask |= 2;
    *(u32*)s0 = vtbl;
    *(u32*)(s0 + 2796) = 0;
    *(u32*)(s0 + 1420) = mask;
    return r;
}
}  // namespace n001b3b70

// 001b3bb8 (was src/anon/auto200_999.cpp)
namespace n001b3bb8 {
// store_global_35ed04
u32 func_00185ed8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00185ed8jjjjjjjj");
extern u8 D_00351100 asm("D_00351100");
/*TARGET 001b3bb8*/
// 0x001a98e8: definition moved into src/anon/unit_001a9130.cpp

// 001d3328: moved to src/anon/unit_001d30b0.cpp

u32 func_001b3bb8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                  u32 a7) asm("_Z13func_001b3bb8jjjjjjjj");
// 0x001a98e8: definition moved into src/anon/unit_001a9130.cpp

// 001d3328: moved to src/anon/unit_001d30b0.cpp

u32 func_001b3bb8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                  u32 a7) {
    u32 s0 = a0;
    u32 r = ((u32 (*)(u32, u32, u32, u32, u32, u32, u32, u32))func_00185ed8)(
        a0, a1, a2, a3, a4, a5, a6, a7);
    u32 mask = *(u32 *)(s0 + 1420);
    u32 vtbl = (u32)&D_00351100;
    *(u32 *)(s0 + 2788) = 0;
    mask |= 2;
    *(u32 *)s0 = vtbl;
    *(u32 *)(s0 + 2796) = 0;
    *(u32 *)(s0 + 1420) = mask;
    return r;
}
}  // namespace n001b3bb8

// 001b3c00 (was src/anon/auto80_199_queue.cpp)
namespace n001b3c00 {
/*TARGET 001b3c00*/
void func_001b3c00(u32 a0, u32 a1) asm("_Z13func_001b3c00jj");
void func_001b3c00(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;

    u32 t7 = *(u32*)(a0 + 1164);
    if (t7 != 0) {
        func_001a17c8(t7);
    }

    u32 v0 = func_001a1018(s1);
    *(u32*)(s0 + 1164) = v0;
    if (v0 != 0) {
        *(u32*)(v0 + 604) = s0;
    }
}
}  // namespace n001b3c00

// 001b3c58 (was src/anon/auto80_199_queue.cpp)
namespace n001b3c58 {
/*TARGET 001b3c58*/
void func_001b3c58(u32 a0, u32 a1) asm("_Z13func_001b3c58jj");
void func_001b3c58(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;

    u32 t7 = *(u32*)(a0 + 1164);
    if (t7 != 0) {
        func_001a17c8(t7);
    }

    u32 v0 = func_001a1060(s1);
    *(u32*)(s0 + 1164) = v0;
    if (v0 != 0) {
        *(u32*)(v0 + 604) = s0;
    }
}
}  // namespace n001b3c58

// 001b3cb0 (was src/anon/tiny_auto80_queue.cpp)
namespace n001b3cb0 {
// 0x0018ffb8: definition moved into src/anon/unit_0018f140.cpp

extern "C" u32 func_0019ba60(...) asm("func_0019ba60");
/*TARGET 001b3cb0*/
void func_001b3cb0(u8* a0, u32 a1) asm("_Z13func_001b3cb0Phj");
void func_001b3cb0(u8* a0, u32 a1) {
    u8* s1 = a0;
    u32 s0 = a1;
    *(u32*)(s1 + 2788) = s0;
    if (func_0019ba60(s0) != 0) {
        if (*(u32*)(s0 + 944) == 1) {
            *(u32*)(s1 + 2796) = s0;
        }
    }
}
}  // namespace n001b3cb0

// 001b3d00 (was src/anon/batch_wcx2.cpp)
namespace n001b3d00 {
// 0x0018eb98: definition moved into src/anon/unit_0018d050.cpp

struct Mask11 { u32 on, set, off; u32 Get() { return (on | set) & ~off; } };
struct Hit11 { u8 pad[24]; u32 flags; u32 src; u32* def; };
struct Chr11 { void** vt; };
s32 func_001b58a8(void) asm("func_001b58a8");
s32 func_0018cdd0(Hit11*) asm("func_0018cdd0");
void func_001b5ab0(void) asm("func_001b5ab0");
void func_001b3e88(Chr11*, Hit11*) asm("func_001b3e88");
void func_001b3cb0(Chr11*, u32) asm("func_001b3cb0");
void func_00186d48(Chr11*, Hit11*) asm("func_00186d48");
void func_001c20e8(u32, Hit11*, Chr11*) asm("func_001c20e8");
void func_001883f8(u8*, Hit11*) asm("func_001883f8");
void func_0016cce8(u32, s32, Hit11**, s32, s32) asm("func_0016cce8");
void func_00186148(Chr11*, Hit11*) asm("func_00186148");
/*TARGET 001b3d00*/
void func_001b3d00(Chr11* p, Hit11* h) asm("func_001b3d00");
void func_001b3d00(Chr11* p, Hit11* h)
{
    u8* b = (u8*)p;
    Mask11* m = (Mask11*)(b + 2748);
    if (m->Get() & 0x2000) {
        func_00186148(p, h);
        return;
    }
    {
        if (func_001b58a8() && func_0018cdd0(h)) func_001b5ab0();
        if (!(h->flags & 4)) func_001b3e88(p, h);
        if (*(u32*)(b + 2040) & 4) return;
        if (((s32 (*)(Chr11*))p->vt[24])(p)) return;
        *(u32*)(b + 2792) = *h->def;
        func_001b3cb0(p, *(u32*)(h->src + 8));
        func_00186d48(p, h);
        if (!(*(u32*)(b + 2040) & 4) || !(*(u32*)(b + 1416) & 0x800)) func_001c20e8((*(u32*)(b + 2748) | m->set) & ~m->off, h, p);
        if (*(u32*)(b + 1156)) {
            func_001883f8(b + 768, h);
            u32 t = (u32)h;
            func_0016cce8(*(u32*)(b + 1156), 6, (Hit11**)&t, 1, 0);
        }
        ((void (*)(Chr11*, Hit11*))p->vt[26])(p, h);
    }
    func_00186148(p, h);
}
}  // namespace n001b3d00

// 001b3e88 (was src/anon/batch_w89.cpp)
namespace n001b3e88 {
s32 func_0018ca48(u8) asm("func_0018ca48");
void func_00198580(u8*, s32) asm("func_00198580");
/*TARGET 001b3e88*/
// check_div1000_500
void func_001b3e88(u8* o, u8* e) asm("func_001b3e88");
// check_div1000_500
void func_001b3e88(u8* o, u8* e) {
    u8* p = *(u8**)(o + 2484);
    s32 id = p ? *(s16*)(p + 2) : -1;
    if (id >= 0) {
        s32 k = -1;
        bool isK = *(u32*)(*(u8**)(o + 12) + 4) == 0x17;
        if (isK) {
            switch ((*(u8**)(e + 32))[43]) {
            case 0: k = 0; break;
            case 1: k = 2; break;
            }
        } else {
            switch (func_0018ca48(e[39])) {
            case 1: case 3: case 5: k = 0; break;
            case 4: k = 2; break;
            }
        }
        if (k >= 0) {
            func_00198580(o, id * 1000 + k + (o[2044] & 1));  // check_div1000_500
            o[2044]++;
        }
    }
}
}  // namespace n001b3e88

// 001b3f88 (was gap, never written)
namespace n001b3f88 {
struct D40 { u8 p[19]; u8 f19; u8 f20; u8 f21; s16 f22; u32 f24; };
struct O { u32 f0; u32 f4; u8 p[32]; D40* f40; };
void w3cb0(u8*, u32) asm("_Z16wtarget_001b3cb0jjjj");
void func_00188430(u8*, O*, u8*) asm("func_00188430");
u32 func_0016cce8(...) asm("_ZN2YS2VM8callbackEiP8BD_VALUEiPS0_");
void func_00187018(u8*, O*, u8*, u32, f32) asm("func_00187018");
void act_clear(u8*) asm("_ZN2YS3ACT5clearEv");
u32 func_0019ff78(D40*) asm("func_0019ff78");
void act_push(u8*, u32) asm("_ZN2YS3ACT4pushEPc");
void func_001b3f88(u8* self, O** po, u8** pk) asm("func_001b3f88");
void func_001b3f88(u8* self, O** po, u8** pk) {
    w3cb0(self, *(u32*)(*pk + 8));
    if (*(u32*)(self + 1156)) {
        func_00188430(self + 768, *po, *pk);
        u32 args[2];
        args[0] = (u32)*po;
        args[1] = (u32)*pk;
        func_0016cce8(*(u32*)(self + 1156), 19, args, 2, 0);
    }
    if ((*po)->f4 & 0x40) return;
    if ((*po)->f40->f19 == 2) return;
    u8 c = (*po)->f40->f21;
    if (c) {
        func_00187018(self, *po, *pk, c, (f32)(*po)->f40->f22);
        act_clear(self + 768);
    }
    D40* d = (*po)->f40;
    if (d->f24) act_push(self + 768, func_0019ff78(d));
    (*po)->f4 |= 0x40;
}
}


// 001b4098 (was src/anon/tiny_auto80_queue.cpp)
namespace n001b4098 {
u32 func_0016cce8(...) asm("func_0016cce8");
/*TARGET 001b4098*/
void func_001b4098(u8* a0, u32 a1, u32 a2) asm("_Z13func_001b4098Phjj");
void func_001b4098(u8* a0, u32 a1, u32 a2) {
    u32 t1 = a1;
    u32 t2 = a2;
    u32* p = *(u32**)(a0 + 1156);
    if (p != 0) {
        u32 args[2];
        args[0] = t1;
        args[1] = t2;
        func_0016cce8((u32)p, 15, args, 2, 0);
    }
}
}  // namespace n001b4098

// 001b40e0 (was src/anon/batch_wcx.cpp)
namespace n001b40e0 {
extern u8 D_0036da70[] asm("D_0036da70");
s32 func_001883d8(u8*, u8*) asm("func_001883d8");
void func_001880b0(u8*, u8*) asm("func_001880b0");
struct Tmp48 { u8 d[16]; };
void func_0016c2b0(Tmp48*, u8*) asm("func_0016c2b0");
void func_001b4198(u8*, u32, Tmp48*) asm("func_001b4198");
void func_0016be00(u8*, u16) asm("func_0016be00");
void func_00187850(u8*) asm("func_00187850");
/*TARGET 001b40e0*/
void func_001b40e0(u8* p) asm("func_001b40e0");
void func_001b40e0(u8* p)
{
    u8* q = p + 768;
    if (func_001883d8(q, D_0036da70)) func_001880b0(q, D_0036da70);
    u8* t = *(u8**)(p + 1164);
    if (t && *(u8**)(t + 612)) {
        Tmp48 tmp;
        func_0016c2b0(&tmp, p);
        func_001b4198(*(u8**)(*(u8**)(p + 1164) + 612), *(u32*)(p + 2788), &tmp);
        u16 v = *(u16*)(*(u8**)(*(u8**)(p + 1164) + 612) + 88);
        if (v) func_0016be00(p, v);
    }
    func_00187850(p);
}
}  // namespace n001b40e0

// 001b4198 (was src/anon/batch_wcx2.cpp)
namespace n001b4198 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V62 {
    f32 x, y, z, w;
    V62() {}
    V62(const V62& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
struct Obj62 { u8 pad[86]; u16 pow; u8 pad2[2]; u16 se; };
struct Itm62 { u8 pad[10]; u16 atk; };
struct Hp62 { s32 hp; s32 max; };
struct Tune62 { u8 pad[324]; f32 thr; };
extern u8* D_0034e948 asm("D_0034e948");
extern s32 D_0032dfc8 asm("D_0032dfc8");
extern Tune62* D_00352130__89182 asm("D_00352130");
s32 func_001b7038(Obj62*) asm("func_001b7038");
u8* func_00177860(u8*) asm("func_00177860");
Itm62* func_001c0cc8(void) asm("func_001c0cc8");
// get_global_35c63c
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001b70d0(s32) asm("func_001b70d0");
void func_0015b680(V62*, s32, s32) asm("func_0015b680");
void func_001c0890(u16) asm("func_001c0890");
/*TARGET 001b4198*/
void func_001b4198(Obj62* o, u8* e, const V62* pos) asm("func_001b4198");
void func_001b4198(Obj62* o, u8* e, const V62* pos)
{
    if (func_001b7038(o)) {
        u8* pl = D_0034e948;
        u8* st = func_00177860(pl);
        s32 dmg = (func_001c0cc8()->atk * o->pow + 99) / 100;
        if (dmg > 0) {
            if (D_0032dfc8 == 3) {
                dmg = dmg * 75 / 100;
                if (!dmg) dmg = 1;
            }
            if (func_0019ba60(e) && (*(u32*)(e + 1416) & 0x80)) {
                Hp62* h = *(Hp62**)(pl + 1164);
                if ((f32)h->hp / (f32)h->max <= D_00352130__89182->thr) dmg *= st[47];
            }
            s32 r = func_001b70d0(dmg);
            if (r > 0) {
                V62 p = *pos;
                func_0015b680(&p, dmg, r);
            }
        }
    }
    if (o->se) func_001c0890(o->se);
}
}  // namespace n001b4198

// 001b4300 (was src/anon/batch_w14.cpp)
namespace n001b4300 {
void* func_00102c18(s32, s32, void (*)(void)) asm("func_00102c18");
void func_001b4340(void) asm("func_001b4340");
void func_001b43e0(void) asm("func_001b43e0");
extern void* D_01d48cb0 asm("D_01d48cb0");
/*TARGET 001b4300*/
// 0x001a0678: definition moved into src/anon/unit_0019fb70.cpp

void func_001b4300(void) asm("func_001b4300");
// 0x001a0678: definition moved into src/anon/unit_0019fb70.cpp

void func_001b4300(void) {
    D_01d48cb0 = 0;
    u8* p = (u8*)func_00102c18(1, 0x5078, func_001b4340);
    *(void (**)(void))(p + 48) = func_001b43e0;
}
}  // namespace n001b4300

// 001b4340 (was src/anon/batch_w1778.cpp)
namespace n001b4340 {
struct W1778Obj;
struct W1778ObjVt { void* f[16]; s32 (*isOk)(W1778Obj*); };
struct W1778Obj { W1778ObjVt* vt; };
extern W1778Obj* D_0034e948 asm("D_0034e948");
extern s32 D_01d48cb0 asm("D_01d48cb0");
extern u8 D_00351eb8[] asm("D_00351eb8");
s32 func_0019ba60(W1778Obj*) asm("func_0019ba60");
void func_001b5250(s32, s32) asm("func_001b5250");
bool func_001c8db8(void*, s32) asm("func_001c8db8");
void func_001d4180(void) asm("func_001d4180");
/*TARGET 001b4340*/
void func_001b4340(void) asm("func_001b4340");
void func_001b4340(void) {
    W1778Obj* o = D_0034e948;
    if (D_01d48cb0 == 0) {
        if (func_0019ba60(o) && o->vt->isOk(o)) {
            bool b = !func_001c8db8(D_00351eb8, 0);
            if (b) func_001d4180();
        }
    } else {
        func_001b5250(D_01d48cb0, 0);
    }
}
}  // namespace n001b4340

// 001b43e0 (was src/anon/batch_w33.cpp)
namespace n001b43e0 {
struct NoTail { ~NoTail() {} };
// 0x001af778: definition moved into src/anon/unit_001ada38.cpp

struct Obj1b4 { u8 pad[64]; u32 flags; };
extern Obj1b4* D_01d48cb0 asm("D_01d48cb0");
void func_001b5460(Obj1b4*) asm("func_001b5460");
void func_001b4f40(Obj1b4*) asm("func_001b4f40");
void func_00105110(void*) asm("func_00105110");
/*TARGET 001b43e0*/
// Destroy and free the singleton at D_01d48cb0.
void func_001b43e0(void) asm("func_001b43e0");
// Destroy and free the singleton at D_01d48cb0.
void func_001b43e0(void) {
    if (D_01d48cb0) {
        func_001b5460(D_01d48cb0);
        Obj1b4* p = D_01d48cb0;
        if (p) {
            NoTail g; // keeps the free a plain call (no sibcall)
            func_001b4f40(p);
            func_00105110(p);
        }
    }
}
}  // namespace n001b43e0

// 001b4430 (was src/anon/batch_wcx2.cpp)
namespace n001b4430 {
// 00107700: moved to src/naka/libkn/camera.cpp

struct Rec91 { u16 id; u8 pad[26]; u8 b28; u8 pad2[3]; u16 h32; };
struct Dat91 { u8 pad; u8 kind; };
struct Wk91 { u8 pad[52]; u32 snd; };
union U91 { Wk91* p; u8 c; };
extern U91 D_01d48cb0_106899 asm("D_01d48cb0");
Rec91* func_001b8e88(u32) asm("func_001b8e88");
Dat91* func_001d3fe0(u16) asm("func_001d3fe0");
Wk91* func_001050d8_106899(s32) asm("func_001050d8");
void func_001b47d8(Wk91*, Dat91*, u8*, f32) asm("func_001b47d8");
s32 func_001d3f80(Dat91*) asm("func_001d3f80");
void func_00179a68(u8*, f32) asm("func_00179a68");
s32 func_001b5c60(Rec91*) asm("func_001b5c60");
// to_1bbf80_field28
void func_00187650(u8*, s32, s32) asm("func_00187650");
void func_00176d68(u8*, u8) asm("func_00176d68");
u8* func_0017df58(s32) asm("func_0017df58");
s32 func_0019ba60(u8*) asm("func_0019ba60");
void func_001c9780(u8*, f32) asm("func_001c9780");
void func_001b5250(Wk91*, s32) asm("func_001b5250");
void func_001d6148(u8*, u32) asm("func_001d6148");
void func_0016cce8_106899(u32, s32, u32*, s32, s32) asm("func_0016cce8");
/*TARGET 001b4430*/
void func_001b4430(u32 id, u8* e) asm("func_001b4430");
void func_001b4430(u32 id, u8* e)
{
    Rec91* r = func_001b8e88(id);
    Dat91* d = func_001d3fe0(r->id);
    if (d) {
        Wk91* w = func_001050d8_106899(220);
        func_001b47d8(w, d, e, r->h32);
        D_01d48cb0_106899.p = w;
        if (func_001d3f80(d)) func_00179a68(e, -r->b28);
        else func_00187650(e, -func_001b5c60(r), 0);
        if (d->kind != 1) func_00176d68(e, d->kind);
        for (s32 i = 0; i < 2; i++) {
            u8* p = func_0017df58(i);
            if (!func_0019ba60(p)) continue;
            if (*(u32*)(p + 1416) & 0x400000) continue;
            if (p[2892]) continue;
            func_001c9780(p, 0.0f);
        }
        func_001b5250(D_01d48cb0_106899.p, 1);
    } else {
        func_001d6148(e, id);
        u32 arg[1];
        arg[0] = id;
        func_0016cce8_106899(D_01d48cb0_106899.p->snd, 23, arg, 1, 0);
    }
}
}  // namespace n001b4430

// 001b45b0 (was gap, never written): C2 copy of the 0x1b47d8 constructor
namespace n001b45b0 {
extern u8 D_00350e48[] asm("D_00350e48");
extern u8 D_003525c8[] asm("D_003525c8");
extern u8 D_00352560[] asm("D_00352560");
extern u8 D_00351eb8 asm("D_00351eb8");
void func_001ddd10(u8*) asm("func_001ddd10");
void func_001d1fa8(u8*) asm("func_001d1fa8");
// obj_ctor_3525c8
void func_00320400(u8*) asm("func_00320400");
void func_001d1678(u8*, s32) asm("func_001d1678");
// obj_init_28bytes
s32 func_001b5cb8(u8*) asm("func_001b5cb8");
s32 func_001d3f38(u32) asm("func_001d3f38");
// type_is_282_344_484
void func_0016bd60(u8*, s32) asm("func_0016bd60");
u8* func_0017e668(u32) asm("func_0017e668");
void func_001b4d70(u8*, f32) asm("func_001b4d70");
void func_001b4a00(u8*) asm("func_001b4a00");
s32 func_001b5858(u8*) asm("func_001b5858");
void func_001b4d10(u8*) asm("func_001b4d10");
void func_001c8d80(void*, s32) asm("func_001c8d80");
u8* func_001b1928(s32) asm("func_001b1928");
struct Sub72 {
    u8* vt;
    u32 f4;
    s32 f8;
    u32 f12;
    u32 f16;
    u32 f20;
};
struct Sub168 {
    u8* vt;
    u32 f4;
    u32 f8;
    u8 f12[36];
    u32 f48;
};
/*TARGET 001b47d8*/
// Constructor-style init: sets up the sub-objects and spawns up to three child entities from data[1..3].
void func_001b45b0(u8* self, u8* data, u8* owner, f32 scale) asm("func_001b45b0");
// Constructor-style init: sets up the sub-objects and spawns up to three child entities from data[1..3].
void func_001b45b0(u8* self, u8* data, u8* owner, f32 scale)
{
    s32 i;
    u8* p;

    *(u8**)(self + 12) = owner;
    *(u8**)(self + 0) = data;
    *(u32*)(self + 4) = 0;
    *(u32*)(self + 8) = 0;
    func_001ddd10(self + 24);
    *(u32*)(self + 52) = 0;
    *(u32*)(self + 56) = 0;
    *(u32*)(self + 60) = 0;
    *(u32*)(self + 64) = 0;
    *(u32*)(self + 68) = 0;
    {
        Sub72* q = (Sub72*)(self + 72);
        q->f20 = 6144;
        q->f8 = -1;
        q->f12 = 0;
        q->f16 = 0;
        q->f4 = 0;
        *(u32*)&q->vt = (u32)D_00350e48;
    }
    func_001d1fa8(self + 104);  // obj_ctor_3525c8
    *(u32*)(self + 172) = 0;
    *(u32*)(self + 176) = 0;
    *(u8**)(self + 168) = D_003525c8;
    func_00320400(self + 180);
    {
        Sub168* sub = (Sub168*)(self + 168);
        func_001d1678((u8*)sub, -1);  // obj_init_28bytes
        sub->f48 = 0;
        sub->vt = D_00352560;
    }
    if (!func_001b5cb8(self)) {
        *(u32*)(*(u8**)(self + 12) + 268) |= 0x10000;
    }
    if (func_001d3f38(*(u32*)self)) {  // type_is_282_344_484
        func_0016bd60(*(u8**)(self + 12), 0);
    }
    *(u32*)(self + 16) = 0;
    *(u32*)(self + 20) = 0;
    {
        s32 n = 0;
        for (i = 0; i < 3; i++) {
            u8 c = data[i + 1];
            if (c < 2) continue;
            ((u8**)(self + 16))[n] = func_0017e668(c);
            ((u8**)(self + 16))[n][2892] = 1;
            *(u32*)(((u8**)(self + 16))[n] + 268) |= 0x10000;
            if (func_001d3f38(*(u32*)self)) {  // type_is_282_344_484
                func_0016bd60(((u8**)(self + 16))[n], 0);
            }
            n++;
        }
    }
    if (func_001b5cb8(self)) {
        func_001b4d70(self, scale);
    } else {
        func_001b4a00(self);
        if (func_001b5858(self)) {
            func_001b4d10(self);
        } else {
            func_001c8d80(&D_00351eb8, 0);
        }
    }
    p = func_001b1928(0);
    *(u32*)(self + 56) = (u32)p;
    *(u32*)(p + 16) |= 2;
    *(u32*)(self + 64) |= 1;
}
}  // namespace n001b45b0

// 001b47d8 (was src/anon/batch_w108.cpp)
namespace n001b47d8 {
extern u8 D_00350e48[] asm("D_00350e48");
extern u8 D_003525c8[] asm("D_003525c8");
extern u8 D_00352560[] asm("D_00352560");
extern u8 D_00351eb8 asm("D_00351eb8");
void func_001ddd10(u8*) asm("func_001ddd10");
void func_001d1fa8(u8*) asm("func_001d1fa8");
// obj_ctor_3525c8
void func_00320400(u8*) asm("func_00320400");
void func_001d1678(u8*, s32) asm("func_001d1678");
// obj_init_28bytes
s32 func_001b5cb8(u8*) asm("func_001b5cb8");
s32 func_001d3f38(u32) asm("func_001d3f38");
// type_is_282_344_484
void func_0016bd60(u8*, s32) asm("func_0016bd60");
u8* func_0017e668(u32) asm("func_0017e668");
void func_001b4d70(u8*, f32) asm("func_001b4d70");
void func_001b4a00(u8*) asm("func_001b4a00");
s32 func_001b5858(u8*) asm("func_001b5858");
void func_001b4d10(u8*) asm("func_001b4d10");
void func_001c8d80(void*, s32) asm("func_001c8d80");
u8* func_001b1928(s32) asm("func_001b1928");
struct Sub72 {
    u8* vt;
    u32 f4;
    s32 f8;
    u32 f12;
    u32 f16;
    u32 f20;
};
struct Sub168 {
    u8* vt;
    u32 f4;
    u32 f8;
    u8 f12[36];
    u32 f48;
};
/*TARGET 001b47d8*/
// Constructor-style init: sets up the sub-objects and spawns up to three child entities from data[1..3].
void func_001b47d8(u8* self, u8* data, u8* owner, f32 scale) asm("func_001b47d8");
// Constructor-style init: sets up the sub-objects and spawns up to three child entities from data[1..3].
void func_001b47d8(u8* self, u8* data, u8* owner, f32 scale)
{
    s32 i;
    u8* p;

    *(u8**)(self + 12) = owner;
    *(u8**)(self + 0) = data;
    *(u32*)(self + 4) = 0;
    *(u32*)(self + 8) = 0;
    func_001ddd10(self + 24);
    *(u32*)(self + 52) = 0;
    *(u32*)(self + 56) = 0;
    *(u32*)(self + 60) = 0;
    *(u32*)(self + 64) = 0;
    *(u32*)(self + 68) = 0;
    {
        Sub72* q = (Sub72*)(self + 72);
        q->f20 = 6144;
        q->f8 = -1;
        q->f12 = 0;
        q->f16 = 0;
        q->f4 = 0;
        *(u32*)&q->vt = (u32)D_00350e48;
    }
    func_001d1fa8(self + 104);  // obj_ctor_3525c8
    *(u32*)(self + 172) = 0;
    *(u32*)(self + 176) = 0;
    *(u8**)(self + 168) = D_003525c8;
    func_00320400(self + 180);
    {
        Sub168* sub = (Sub168*)(self + 168);
        func_001d1678((u8*)sub, -1);  // obj_init_28bytes
        sub->f48 = 0;
        sub->vt = D_00352560;
    }
    if (!func_001b5cb8(self)) {
        *(u32*)(*(u8**)(self + 12) + 268) |= 0x10000;
    }
    if (func_001d3f38(*(u32*)self)) {  // type_is_282_344_484
        func_0016bd60(*(u8**)(self + 12), 0);
    }
    *(u32*)(self + 16) = 0;
    *(u32*)(self + 20) = 0;
    {
        s32 n = 0;
        for (i = 0; i < 3; i++) {
            u8 c = data[i + 1];
            if (c < 2) continue;
            ((u8**)(self + 16))[n] = func_0017e668(c);
            ((u8**)(self + 16))[n][2892] = 1;
            *(u32*)(((u8**)(self + 16))[n] + 268) |= 0x10000;
            if (func_001d3f38(*(u32*)self)) {  // type_is_282_344_484
                func_0016bd60(((u8**)(self + 16))[n], 0);
            }
            n++;
        }
    }
    if (func_001b5cb8(self)) {
        func_001b4d70(self, scale);
    } else {
        func_001b4a00(self);
        if (func_001b5858(self)) {
            func_001b4d10(self);
        } else {
            func_001c8d80(&D_00351eb8, 0);
        }
    }
    p = func_001b1928(0);
    *(u32*)(self + 56) = (u32)p;
    *(u32*)(p + 16) |= 2;
    *(u32*)(self + 64) |= 1;
}
}  // namespace n001b47d8

// 001b4a00 (was src/anon/batch_w2352_nsa.cpp)
namespace n001b4a00 {
struct Ent { u8 pad[0x28]; u16 id; };
struct Res { u8 pad[8]; s32 v; };
struct Sub {
    u32 vt;
    s32 f4, f8, fc, f10, f14, f18, f1c;
};
struct Obj {
    Ent* ent;       /* 0x00 */
    s32 h;          /* 0x04 */
    s32 f8;         /* 0x08 */
    u8 pad0c[0x0c];
    u8 s18[0x1c];   /* 0x18 */
    s32 f34;        /* 0x34 */
    u8 pad38[0x0c];
    Sub* psub;      /* 0x44 */
    Sub sub;        /* 0x48 */
    u8 s68[4];      /* 0x68 */
    u8 s6c[0x3c];   /* 0x6c */
    u8 sa8[4];      /* 0xa8 */
    u8 sac[4];      /* 0xac */
};
extern u8 D_00350e48[] asm("D_00350e48");
extern u8 D_0036da78[] asm("D_0036da78");
extern u8 D_0036da80[] asm("D_0036da80");
Res* func_00168b38(s32, s32, s32) asm("func_00168b38");
void func_0016cbc8(s32, s32, void*, s32) asm("func_0016cbc8");
s32 func_0016d080(s32, s32) asm("func_0016d080");
s32 func_001708f8(s32, s32) asm("func_001708f8");
void func_001b4c48(Obj*, void*, void*) asm("func_001b4c48");
void func_001b5708(Obj*, s32) asm("func_001b5708");
void func_001d1698(void*, s32, s32, s32) asm("func_001d1698");
void func_001d16e8(void*, s32, s32) asm("func_001d16e8");
void func_001d1a18(void*, s32, s32, s32) asm("func_001d1a18");
void func_001d1d00(void*) asm("func_001d1d00");
void func_001d1da0(void*, f32) asm("func_001d1da0");
void func_001d20a8(void*) asm("func_001d20a8");
void func_001d2248(void*, s32) asm("func_001d2248");
s32 func_001d3f98(Ent*) asm("func_001d3f98");
s32 func_001d4550(Ent*) asm("func_001d4550");
void func_001dddd0(void*, s32) asm("func_001dddd0");
static inline bool valid(Res* r) { return r && r->v; }
/*TARGET 001b4a00*/
/* 001b4a00: set-up step of an entity: reads its parameters (0x14, 0x12, 3, 0x22) and initialises the sub-objects. */
void func_001b4a00(Obj* self, f32 f) asm("func_001b4a00");
/* 001b4a00: set-up step of an entity: reads its parameters (0x14, 0x12, 3, 0x22) and initialises the sub-objects. */
void func_001b4a00(Obj* self, f32 f)
{
    Res* r;
    self->h = func_001708f8(func_001d3f98(self->ent), -1);
    r = func_00168b38(self->h, 0x14, 0);
    if (valid(r)) {
        self->f8 = r->v;
    }
    r = func_00168b38(self->h, 0x12, 0);
    if (valid(r)) {
        func_001dddd0(self->s18, r->v);
    }
    r = func_00168b38(self->h, 3, 0);
    if (valid(r)) {
        Obj* tmp;
        s32 m = func_0016d080(r->v, 0);
        self->f34 = m;
        tmp = self;
        func_0016cbc8(m, 0x16, &tmp, 1);
    }
    r = func_00168b38(self->h, 0x22, 0);
    if (valid(r)) {
        s32 v = r->v;
        Sub* s = &self->sub;
        /* The original addresses these words without the field types: as plain
           field stores gcc reorders them (it can tell the fields apart). */
        *(s32*)((u8*)s + 8) = -1;
        *(s32*)((u8*)s + 20) = 0x1800;
        *(s32*)((u8*)s + 12) = 0;
        *(s32*)((u8*)s + 16) = 0;
        s->f1c = v;
        s->vt = (u32)D_00350e48;
        *(s32*)((u8*)s + 4) = 2;
        self->psub = s;
    }
    func_001b4c48(self, self->s6c, D_0036da78);
    func_001d1a18(self->s68, 0, 999, 0);
    func_001d2248(self->s68, func_001d4550(self->ent));
    if (self->ent->id != 0x1e4 && self->ent->id != 0x26c) {
        func_001d20a8(self->s68);
    }
    func_001b4c48(self, self->sac, D_0036da80);
    func_001d16e8(self->sa8, 1, 12);
    {
        s32 i = (s32)f;
        func_001d1698(self->sa8, i, i, 0);
    }
    func_001d1da0(self->sa8, f);
    func_001d1d00(self->sa8);
    if (self->ent->id == 0x1e4) {
        func_001b5708(self, 3);
    }
}
}  // namespace n001b4a00

// 001b4c48 (was src/anon/batch_wcx2.cpp)
namespace n001b4c48 {
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
// ---- 001b4c48
u8* func_00168b88_4c48(u32, u32, s32, u32) asm("func_00168b88");
static inline s32 rd4_1b4c48(s8* b) { return b[0] | (b[1] << 8) | (b[2] << 16) | (b[3] << 24); }
/*TARGET 001b4c48*/
void func_001b4c48(u8* p, u32* out, s8* b) asm("func_001b4c48");
void func_001b4c48(u8* p, u32* out, s8* b) {
    u8* x = func_00168b88_4c48(*(u32*)(p + 4), 24, rd4_1b4c48(b), 0);
    u8* y = func_00168b88_4c48(*(u32*)(p + 4), 25, rd4_1b4c48(b), 0);
    u32 a = *(u32*)(x + 8);
    u32 c = *(u32*)(y + 8);
    out[0] = a;
    out[1] = c;
}
}  // namespace n001b4c48

// 001b4d10 (was src/anon/auto80_199_queue.cpp)
namespace n001b4d10 {
/*TARGET 001b4d10*/
void func_001b4d10(u32 a0) asm("_Z13func_001b4d10j");
void func_001b4d10(u32 a0) {
    u32 s1 = a0;
    u32 s0 = *(u32*)(*(u32*)(a0 + 0x10) + 0x484);
    if (s0 != 0) {
        u32 stack0 = s1;
        u32 a2 = func_0016cb88(s0, 22);
        u32 v0 = func_0016cf00(s0, 0, a2, &stack0, 1);
        *(u32*)(s1 + 0x34) = v0;
    }
}
}  // namespace n001b4d10

// 001b4d70 (was src/anon/auto80_199_queue.cpp)
namespace n001b4d70 {
/*TARGET 001b4d70*/
void func_001b4d70(u32 a0) asm("_Z13func_001b4d70j");
void func_001b4d70(u32 a0) {
    u32 s1 = a0;
    u32 s0 = *(u32*)(*(u32*)(a0 + 0x0c) + 0x484);
    if (s0 != 0) {
        u32 stack0 = s1;
        u32 a2 = func_0016cb88(s0, 22);
        u32 v0 = func_0016cf00(s0, 0, a2, &stack0, 1);
        *(u32*)(s1 + 0x34) = v0;
    }
}
}  // namespace n001b4d70

// 001b4dd0 (was src/anon/batch_wcx2.cpp)
namespace n001b4dd0 {
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
extern u32 D_01d48cb0 asm("D_01d48cb0");
extern u8 D_00351eb8[] asm("D_00351eb8");
extern u8 D_00352560[] asm("D_00352560");
extern u8 D_00350e48[] asm("D_00350e48");
s32 func_0019ba60(u8*) asm("func_0019ba60");
void func_0016cab8(u8*) asm("func_0016cab8");
void func_0016c7d8(u8*) asm("func_0016c7d8");
void func_001dde40(u8*) asm("func_001dde40");
void func_001b1c10(u32, f32) asm("func_001b1c10");
void func_0016c640(s32) asm("func_0016c640");
void func_001d4570(u32, u32) asm("func_001d4570");
void func_00170950(u32) asm("func_00170950");
s32 func_001b5858(u8*) asm("func_001b5858");
s32 func_001b5cb8(u8*) asm("func_001b5cb8");
void func_001c8d98(u8*, s32) asm("func_001c8d98");
void func_001d1ed0(u8*) asm("func_001d1ed0");
void func_001d2048(u8*) asm("func_001d2048");
void func_001b0188(u8*) asm("func_001b0188");
void func_001ddd88(u8*) asm("func_001ddd88");
struct NoTail14 { ~NoTail14() {} };
/*TARGET 001b4dd0*/
void func_001b4dd0(u8* p) asm("func_001b4dd0");
void func_001b4dd0(u8* p)
{
    NoTail14 nt;
    *(u32*)(*(u8**)(p + 12) + 268) &= ~0x10000;
    u8* q = p;
    for (s32 i = 0; i < 2; i++, q += 4) {
        if (func_0019ba60(*(u8**)(q + 16))) {
            *(u32*)(*(u32*)(q + 16) + 268) &= ~0x10000;
            ((u8*)*(u32*)(q + 16))[2892] = 0;
        }
    }
    u8* o = *(u8**)(p + 52);
    if (o) {
        func_0016cab8(o);
        func_0016c7d8(o);
    }
    u8* a = p + 24;
    if (*(u32*)(p + 24)) func_001dde40(a);
    u8* w = p + 104;
    func_001b1c10(*(u32*)(p + 56), 30.0f);
    func_0016c640(1);
    func_001d4570(*(u32*)p, *(u32*)(w + 56));
    if (*(u32*)(p + 4)) func_00170950(*(u32*)(p + 4));
    D_01d48cb0 = 0;
    if (!func_001b5858(p) && !func_001b5cb8(p)) func_001c8d98(D_00351eb8, 0);
    *(u32*)(p + 168) = (u32)D_00352560;
    func_001d1ed0(p + 168);
    func_001d2048(w);
    *(u32*)(p + 72) = (u32)D_00350e48;
    func_001b0188(p + 72);
    func_001ddd88(a);
}
}  // namespace n001b4dd0

// 001b4f40 (was src/anon/batch_w275.cpp)
namespace n001b4f40 {
struct NoTail { ~NoTail() {} };
// 0017d1d8: moved to src/anon/unit_0017c400.cpp

extern s32 D_01D48CB0 asm("D_01D48CB0");
extern u8 D_00351EB8 asm("D_00351EB8");
extern u8 D_00352560 asm("D_00352560");
extern u8 D_00350E48 asm("D_00350E48");
s32 func_0019ba60(void*) asm("func_0019ba60");
void func_0016cab8(void*) asm("func_0016cab8");
void func_0016c7d8(void*) asm("func_0016c7d8");
void func_001dde40(void*) asm("func_001dde40");
void func_001b1c10(void*, f32) asm("func_001b1c10");
void func_0016c640(s32) asm("func_0016c640");
void func_001d4570(void*, void*) asm("func_001d4570");
void func_00170950(void*) asm("func_00170950");
s32 func_001b5858(void*) asm("func_001b5858");
s32 func_001b5cb8(void*) asm("func_001b5cb8");
void func_001c8d98(void*, s32) asm("func_001c8d98");
void func_001d1ed0(void*) asm("func_001d1ed0");
void func_001d2048(void*) asm("func_001d2048");
void func_001b0188(void*) asm("func_001b0188");
void func_001ddd88(void*) asm("func_001ddd88");
/*TARGET 001b4f40*/
void func_001b4f40(u8* p) asm("func_001b4f40");
void func_001b4f40(u8* p) {
    NoTail nt;
    u32* q = (u32*)p;
    s32 i;
    *(u32*)(*(u8**)(p + 12) + 268) &= ~0x10000;
    for (i = 1; i >= 0; i--, q++) {
        if (func_0019ba60((void*)q[4])) {
            *(u32*)((u8*)q[4] + 268) &= ~0x10000;
            ((u8*)q[4])[2892] = 0;
        }
    }
    void* o = *(void**)(p + 52);
    if (o) { func_0016cab8(o); func_0016c7d8(o); }
    u8* m24 = p + 24;
    if (*(void**)(p + 24)) func_001dde40(m24);
    u8* m = p + 104;
    func_001b1c10(*(void**)(p + 56), 30.0f);
    func_0016c640(1);
    func_001d4570(*(void**)p, *(void**)(m + 56));
    void* o4 = *(void**)(p + 4); if (o4) func_00170950(o4);
    D_01D48CB0 = 0;
    if (!func_001b5858(p) && !func_001b5cb8(p)) func_001c8d98(&D_00351EB8, 0);
    *(void**)(p + 168) = &D_00352560;
    func_001d1ed0(p + 168);
    func_001d2048(m);
    *(void**)(p + 72) = &D_00350E48;
    func_001b0188(p + 72);
    func_001ddd88(m24);
}
}  // namespace n001b4f40

// 001b50b0 (was src/anon/batch_w8.cpp)
namespace n001b50b0 {
// 001b1bb8: moved to src/anon/unit_001b14d8.cpp

void func_001802d8(u32, u32, void*, u32, u32, void*) asm("func_001802d8");
/*TARGET 001b50b0*/
void func_001b50b0(u8* p, u32 a, u32 b) asm("func_001b50b0");
void func_001b50b0(u8* p, u32 a, u32 b) {
    func_001802d8(0, *(u32*)(p + 8), p + 24, a, b, p + 60);
}
}  // namespace n001b50b0

// 001b50e0 (was src/anon/batch_wcx2.cpp)
namespace n001b50e0 {
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
struct VB13 {
    f32 x, y, z, w;
    VB13() {}
    VB13(const VB13& s) { QCOPY(this, &s); }
    VB13& operator=(const VB13& s) { QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
struct Shk13 { u32 a; f32 b, c; u32 d; VB13 pos; };
s32 func_001b5858(u8*) asm("func_001b5858");
u8* func_00168b88(u32, s32, u32, s32) asm("func_00168b88");
// find_entry16_by_half_word
u32 func_00198738(u32, s8*) asm("func_00198738");
void func_00185278(u32, u8, f32) asm("func_00185278");
void func_0016af58__52620(VB13*, u32) asm("func_0016af58");
void func_0016b010__52620(u32, VB13*) asm("func_0016b010");
double func_00313b80(f32) asm("func_00313b80");
// float_to_double
s32 func_003142e0(double, double) asm("func_003142e0");
// double_compare
VB13* func_0016c028__52620(u32) asm("func_0016c028");
void func_00185e78(Shk13*) asm("func_00185e78");
u8* func_001050d8(s32) asm("func_001050d8");
void func_00196ca8(u8*, s32, u32) asm("func_00196ca8");
void func_00196e98(u8*, u32) asm("func_00196e98");
void func_00196f00(u8*) asm("func_00196f00");
#define ID4(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))
static inline bool Valid13(u8* r) { return r && *(u32*)(r + 8); }
/*TARGET 001b50e0*/
void func_001b50e0(u8* p, s8* id, u8 flag, f32 shake) asm("func_001b50e0");
void func_001b50e0(u8* p, s8* id, u8 flag, f32 shake)
{
    u32 v = 0;
    if (func_001b5858(p)) {
        v = func_00198738(*(u32*)(p + 16), id);
    } else {
        u8* r = func_00168b88(*(u32*)(p + 4), 22, ID4(id), 0);  // find_entry16_by_half_word
        if (Valid13(r)) v = *(u32*)(r + 8);
    }
    if (!v) return;
    func_00185278(*(u32*)(p + 12), flag, 500.0f);
    VB13 t;
    func_0016af58__52620(&t, *(u32*)(p + 12));
    func_0016b010__52620(*(u32*)(p + 12), &t);
    if (func_003142e0(0.0, func_00313b80(shake)) < 0) {  // double_compare
        Shk13 s;
        VB13* q = func_0016c028__52620(*(u32*)(p + 12));
        s.a = 0;
        s.b = shake;
        s.c = shake;
        s.d = 0;
        s.pos = *q;
        func_00185e78(&s);
    }
    u8* o = func_001050d8(176);
    func_00196ca8(o, 11, v);
    func_00196e98(o, *(u32*)(p + 12));
    func_00196f00(o);
}
}  // namespace n001b50e0

// 001b5250 (was src/anon/batch_w1886.cpp)
namespace n001b5250 {
/* 001b5250 */
struct W1886Obj {
    u8 pad[0x34]; s32 p34; u8 pad2[8]; u32 flags; s32 p44;
    inline ~W1886Obj() __attribute__((always_inline));
    static void operator delete(void*) asm("func_00105110");
};
void func_001b4f40(W1886Obj*) asm("func_001b4f40");
inline W1886Obj::~W1886Obj() { func_001b4f40(this); }
// 0x0018a670: definition moved into src/anon/unit_00189d38.cpp

extern u32 D_0034f240 asm("D_0034f240");
extern f32 D_00349e10 asm("D_00349e10");
s32 func_001b55e8(W1886Obj*) asm("func_001b55e8");
void func_001b5460(W1886Obj*) asm("func_001b5460");
void func_00185e20(s32) asm("func_00185e20");
s32 func_00197920(void) asm("func_00197920");
void func_0016c640(s32) asm("func_0016c640");
void func_001b0250(s32) asm("func_001b0250");
s32 func_0016cd48(s32, s32) asm("func_0016cd48");
void func_001b5588(W1886Obj*) asm("func_001b5588");
s32 func_001b5680(W1886Obj*) asm("func_001b5680");
void func_001b53b0(W1886Obj*, f32) asm("func_001b53b0");
/*TARGET 001b5250*/
void func_001b5250(W1886Obj* t, u8 flag) asm("func_001b5250");
void func_001b5250(W1886Obj* t, u8 flag)
{
    if ((t->flags & 4) && func_001b55e8(t)) {
        func_001b5460(t);
        delete t;
        return;
    }
    if (!flag) {
        if (D_0034f240 & 0x20) return;
        if ((t->flags & 1) == 1) {
            func_00185e20(1);
            t->flags = (t->flags & ~1) | 2;
        } else if ((t->flags & 2) && !func_00197920()) {
            func_0016c640(1);
            t->flags &= ~2;
        }
    }
    if (t->p44) func_001b0250(t->p44);
    if (t->p34 && func_0016cd48(t->p34, 0) == 1) func_001b5588(t);
    if (func_001b5680(t)) func_001b53b0(t, D_00349e10);
}
}  // namespace n001b5250

// 001b53b0 (was src/anon/batch_w1670.cpp)
namespace n001b53b0 {
u8* ys_party_get_ability_w1670(u32) asm("_ZN2YS5PARTY11get_abilityEv");
void func_001d1da0(f32, u8*) asm("func_001d1da0");
/*TARGET 001b53b0*/
// 0x001ae788: definition moved into src/anon/unit_001ada38.cpp

// 001cc310: moved to src/anon/unit_001cc048.cpp

void func_001b53b0(u8* o, f32 x) asm("func_001b53b0");
// 0x001ae788: definition moved into src/anon/unit_001ada38.cpp

// 001cc310: moved to src/anon/unit_001cc048.cpp

void func_001b53b0(u8* o, f32 x) {
    u8* p = o + 0xa8;
    func_001d1da0(*(f32*)(p + 0x2c) + -x * *(f32*)(ys_party_get_ability_w1670(*(u32*)(o + 0xc)) + 0x60), p);
}
}  // namespace n001b53b0

// 001b5400 (was src/anon/batch_w33.cpp)
namespace n001b5400 {
struct NoTail { ~NoTail() {} };
// 0x001af778: definition moved into src/anon/unit_001ada38.cpp

struct Obj1b4 { u8 pad[64]; u32 flags; };
extern Obj1b4* D_01d48cb0 asm("D_01d48cb0");
void func_001b5460(Obj1b4*) asm("func_001b5460");
void func_001b4f40(Obj1b4*) asm("func_001b4f40");
void func_00105110(void*) asm("func_00105110");
void u_call0_001b5400(void) asm("_Z16u_call0_001b5400v");
/*TARGET 001b5400*/
void u_call0_001b5400(void) asm("_Z16u_call0_001b5400v");
void u_call0_001b5400(void) {
    if (D_01d48cb0) {
        D_01d48cb0->flags |= 0x10;
        asm volatile("" ::: "memory"); // the original reloads the global after the flag store
        func_001b5460(D_01d48cb0);
        Obj1b4* p = D_01d48cb0;
        if (p) {
            NoTail g;
            func_001b4f40(p);
            func_00105110(p);
        }
    }
}
}  // namespace n001b5400

// 001b5460 (was src/anon/batch_w98.cpp)
namespace n001b5460 {
// 0x001aa558: definition moved into src/anon/unit_001a9130.cpp

s32 func_001b5858(u8*) asm("func_001b5858");
s32 func_001b5cb8(u8*) asm("func_001b5cb8");
u8* func_001b9bc8(u8*) asm("func_001b9bc8");
void func_0016cab8(u8*) asm("func_0016cab8");
void func_0016c7d8(u8*) asm("func_0016c7d8");
void func_001de450(u8*) asm("func_001de450");
void func_001c9770(void) asm("func_001c9770");
void func_001c9b90(void) asm("func_001c9b90");
void func_001d1c70(u8*) asm("func_001d1c70");
void func_001d1ed0(u8*) asm("func_001d1ed0");
void func_001b57f8(u8*) asm("func_001b57f8");
void func_001b5588(u32) asm("func_001b5588");
extern u32 D_01d48cb0 asm("D_01d48cb0");
/*TARGET 001b5460*/
// Shutdown: releases owned resources and hands off to the next stage.
void func_001b5460(u8* o) asm("func_001b5460");
// Shutdown: releases owned resources and hands off to the next stage.
void func_001b5460(u8* o) {
    if (!func_001b5858(o) && !func_001b5cb8(o)) {
        u8* e = 0;
        while ((e = func_001b9bc8(e)) != 0) {
            if ((*(s32 (**)(u8*))(*(u8**)e + 60))(e) == 5000) (*(void (**)(u8*))(*(u8**)e + 40))(e);
        }
    }
    u8* t = *(u8**)(o + 52);
    if (t) {
        func_0016cab8(t);
        func_0016c7d8(t);
        *(u8**)(o + 52) = 0;
    }
    u8* h = o + 24;
    if (*(u32*)h) func_001de450(h);
    if (!func_001b5858(o)) {
        if (*(u32*)(o + 64) & 0x10) func_001c9770();
        else func_001c9b90();
    }
    func_001d1c70(o + 104);
    func_001d1ed0(o + 168);
    func_001b57f8(o);
    func_001b5588(D_01d48cb0);
}
}  // namespace n001b5460

// 001b5588 (was src/anon/auto80_199_queue.cpp)
namespace n001b5588 {
/*TARGET 001b5588*/
void func_001b5588(u32 a0) asm("_Z13func_001b5588j");
void func_001b5588(u32 a0) {
    u32 s0 = a0;
    u32 t6 = *(u32*)(s0 + 0x40);
    u32 a0p = a0 + 0x68;
    if ((t6 & 4) == 0) {
        if ((*(u32*)(s0 + 0x74) & 4) != 0) {
            func_001d1b28((void*)a0p);
        }
        func_001b5878(s0);
        t6 = *(u32*)(s0 + 0x40);
    }
    *(u32*)(s0 + 0x40) = t6 | 4;
}
}  // namespace n001b5588

// 001b55e8 (was src/anon/batch_w59.cpp)
namespace n001b55e8 {
// 0x00190388: definition moved into src/anon/unit_001900d0.cpp

// --- 001b55e8
u32 func_0016f7d0(u32, u32) asm("func_0016f7d0");
u32 func_001d1ca8(u8*) asm("func_001d1ca8");
u32 func_001d1f08(u8*) asm("func_001d1f08");
u32 func_001c9df8(void) asm("func_001c9df8");
/*TARGET 001b55e8*/
u32 func_001b55e8(u8* p) asm("func_001b55e8");
u32 func_001b55e8(u8* p) {
    u32 o = *(u32*)(*(u8**)p + 36);
    if (o && (func_0016f7d0(o, 0) & 8)) return 0;
    if (func_001d1ca8(p + 104)) return 0;
    if (func_001d1f08(p + 168)) return 0;
    if (func_001c9df8()) return 0;
    return *(u32*)(p + 36) == 0 && *(u32*)(p + 60) == 0;
}
}  // namespace n001b55e8

// 001b5680 (was src/anon/auto80_199_queue.cpp)
namespace n001b5680 {
/*TARGET 001b5680*/
u32 func_001b5680(u32 a0) asm("_Z13func_001b5680j");
u32 func_001b5680(u32 a0) {
    u32 s0 = a0;
    u32 t5 = 0;

    if (func_001d1f08((void*)(a0 + 0xa8)) == 0) {
        return t5;
    }

    if (((*(u32*)(*(u32*)(s0 + 0x0c) + 0x168) & 1) & 0xff) != 0) {
        return t5;
    }

    u32* p = (u32*)(s0 + 0x10);
    for (s32 i = 0; i < 2; i++) {
        u32 v = *p;
        p += 1;
        if (v != 0) {
            if (((*(u32*)(v + 0x168) & 1) & 0xff) != 0) {
                return t5;
            }
        }
    }

    t5 = 1;
    return t5;
}
}  // namespace n001b5680

// 001b5708 (was src/anon/batch_w83.cpp)
namespace n001b5708 {
// 0x001a0a48: definition moved into src/anon/unit_0019fb70.cpp

struct Rgba8 { s8 r, g, b, a; };
extern Rgba8 D_0036da98 asm("D_0036da98");
void* func_00168b88(void*, s32, u32, s32) asm("func_00168b88");
// find_entry16_by_half_word
void func_001bdb70(void*, void*, void*, void*, s32) asm("func_001bdb70");
static inline u32 packRgba(const Rgba8& c) { return c.r | (c.g << 8) | (c.b << 16) | (c.a << 24); }
struct R8 { u8 pad[8]; void* p; };
struct Obj1b5708 { u32 pad; void* d; };
/*TARGET 001b5708*/
void func_001b5708(Obj1b5708* p, void* a) asm("func_001b5708");
void func_001b5708(Obj1b5708* p, void* a) {
    R8* r0 = (R8*)func_00168b88(p->d, 24, packRgba(D_0036da98), 0);  // find_entry16_by_half_word
    void* d = p->d;
    u32 c = packRgba(D_0036da98);
    void* v0 = r0->p;
    R8* r1 = (R8*)func_00168b88(d, 25, c, 0);  // find_entry16_by_half_word
    func_001bdb70(*(void**)(*(u8**)((u8*)p + 12) + 2884), a, v0, r1->p, 0);
    *(u32*)((u8*)p + 64) |= 8;
    *(s32*)((u8*)p + 60) += 1;
}
}  // namespace n001b5708

// 001b57f8 (was src/anon/auto80_199_queue.cpp)
namespace n001b57f8 {
/*TARGET 001b57f8*/
void func_001b57f8(u32 a0) asm("_Z13func_001b57f8j");
void func_001b57f8(u32 a0) {
    if ((*(u32*)(a0 + 0x40) & 8) != 0) {
        u32 s0 = a0;
        u32 obj = *(u32*)(*(u32*)(a0 + 0x0c) + 0x0b44);
        FnA0 fn = (FnA0)(*(u32*)(*(u32*)obj + 0x18));
        fn(obj);
        *(u32*)(s0 + 0x3c) = *(u32*)(s0 + 0x3c) - 1;
        *(u32*)(s0 + 0x40) = *(u32*)(s0 + 0x40) & (u32)-9;
    }
}
}  // namespace n001b57f8

// 001b5858 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n001b5858 {
u32 func_001d3f80(u32, u32, u32, u32) asm("_Z13func_001d3f80jjjj");
/*TARGET 001b5858*/
// 0x001b01b0: definition moved into src/anon/unit_001ada38.cpp

u32 func_001b5858(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b5858jjjj");
// 0x001b01b0: definition moved into src/anon/unit_001ada38.cpp

u32 func_001b5858(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = *(u32*)((u32)r4 + (s32)(0));
    u32 (*fp_call4_001d3f80)(u32, u32, u32, u32) = func_001d3f80;
    r2 = fp_call4_001d3f80(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001b5858

// 001b5878 (was src/anon/batch_w202.cpp)
namespace n001b5878 {
extern void func_001d1d68(u8*) asm("func_001d1d68");
void YS_LIMIT_close_gauge(u8* a) asm("_ZN2YS5LIMIT11close_gaugeEv");
/*TARGET 001b5878*/
void YS_LIMIT_close_gauge(u8* a) asm("_ZN2YS5LIMIT11close_gaugeEv");
void YS_LIMIT_close_gauge(u8* a) { u32 f = *(u32*)(a+180) & 4; u8* p = a+168; if (f) func_001d1d68(p); }
}  // namespace n001b5878

// 001b58a8 (was src/anon/tiny.cpp)
namespace n001b58a8 {
extern u32 D_01d48cb0 asm("D_01d48cb0");
/*TARGET 001b58a8*/
// 0x001b0320: definition moved into src/anon/unit_001ada38.cpp

// 001b1e58: moved to src/anon/unit_001b1d20.cpp

u32 func_001b58a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b58a8jjjj");
// 0x001b0320: definition moved into src/anon/unit_001ada38.cpp

// 001b1e58: moved to src/anon/unit_001b1d20.cpp

u32 func_001b58a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (D_01d48cb0 != 0);
}
}  // namespace n001b58a8

// 001b58b8 (was src/anon/batch_w14.cpp)
namespace n001b58b8 {
void func_0016cfa0(void*, s32, void*, void*, void*) asm("func_0016cfa0");
extern void* D_01d48cb0 asm("D_01d48cb0");
/*TARGET 001b58b8*/
void func_001b58b8(void* a, void* b, void* c) asm("func_001b58b8");
void func_001b58b8(void* a, void* b, void* c) {
    func_0016cfa0(*(void**)((u8*)D_01d48cb0 + 52), 0, a, b, c);
}
}  // namespace n001b58b8

// 001b58f0 (was src/anon/batch_w2.cpp)
namespace n001b58f0 {
void func_001de168(void*, u32, u32, u32, u32, u32) asm("func_001de168");
/*TARGET 001b58f0*/
// 0x001a91f8: definition moved into src/anon/unit_001a9130.cpp

void func_001b58f0(u8* p, u32 a1, u32 a2, u32 a3) asm("func_001b58f0");
// 0x001a91f8: definition moved into src/anon/unit_001a9130.cpp

void func_001b58f0(u8* p, u32 a1, u32 a2, u32 a3) {
    func_001de168(p + 24, a1, a2, 1, 30000, a3);  // scan_list_by_half
}
}  // namespace n001b58f0

// 001b5918 (was src/anon/auto80_199_queue.cpp)
namespace n001b5918 {
/*TARGET 001b5918*/
u32 func_001b5918(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b5918jjjj");
u32 func_001b5918(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 v0;
    u32 t6 = D_01d48cb0;
    u32 t7;
    if (t6 == 0) {
        goto ret0;
    }

    t7 = t6 + 0x18;
    if (a0 == t7) {
        goto callpath;
    }

ret0:
    v0 = 0;
    goto done;

callpath:
    u32 args[3];
    args[0] = a1;
    args[1] = a2;
    args[2] = a3;
    func_0016cce8(*(u32*)(t6 + 0x34), 24, args, 3, 0);
    v0 = 1;
done:
    return v0;
}
}  // namespace n001b5918

// 001b5970 (was src/anon/tiny_auto80_queue.cpp)
namespace n001b5970 {
u32 func_0016cce8(...) asm("func_0016cce8");
/*TARGET 001b5970*/
void func_001b5970(u32 a0, u32 a1) asm("_Z13func_001b5970jj");
void func_001b5970(u32 a0, u32 a1) {
    u32* b = (u32*)0x01D50000;
    u32* d = (u32*)b[-7380];
    if (d == 0) {
        return;
    }
    u32 a2 = a0;
    u32* vtbl = *(u32**)a0;
    if ((vtbl[354] & 4) == 0) {
        return;
    }
    func_0016cce8(d[13], 25, a2, a1, 0);
}
}  // namespace n001b5970

// 001b59c0 (was src/anon/tiny_auto80_queue.cpp)
namespace n001b59c0 {
u32 func_0016cce8(...) asm("func_0016cce8");
/*TARGET 001b59c0*/
void func_001b59c0(u32 a0, u32 a1, u32 a2) asm("_Z13func_001b59c0jjj");
void func_001b59c0(u32 a0, u32 a1, u32 a2) {
    u32 t1 = a1;
    u32 t2 = a2;
    u32* b = (u32*)0x01D50000;
    u32* p = (u32*)b[-7380];
    if (p != 0) {
        u32 args[3];
        args[0] = a0;
        args[1] = t1;
        args[2] = t2;
        func_0016cce8(p[13], 26, args, 3, 0);
    }
}
}  // namespace n001b59c0

// 001b5a10 (was src/anon/batch_w34.cpp)
namespace n001b5a10 {
s32 func_001b5cb8(u8*) asm("func_001b5cb8");
extern u8* D_01d48cb0 asm("D_01d48cb0");
/*TARGET 001b5a10*/
// 0x001a8c78: definition moved into src/anon/unit_001a8618.cpp

// 001ac858: moved to src/anon/unit_001abb28.cpp

// 001b1448: moved to src/yasui/libys/databuff.cpp

void* func_001b5a10(void) asm("func_001b5a10");
// 0x001a8c78: definition moved into src/anon/unit_001a8618.cpp

// 001ac858: moved to src/anon/unit_001abb28.cpp

// 001b1448: moved to src/yasui/libys/databuff.cpp

void* func_001b5a10(void) {
    if (!D_01d48cb0) return 0;
    if (func_001b5cb8(D_01d48cb0)) return *(u8**)(D_01d48cb0 + 12) + 128;
    return D_01d48cb0 + 24;
}
}  // namespace n001b5a10

// 001b5a60 (was src/anon/tiny_auto80_queue.cpp)
namespace n001b5a60 {
void func_001b0210(...) asm("func_001b0210");
/*TARGET 001b5a60*/
void func_001b5a60(u32 a0, u32 a1, u32 a2) asm("_Z13func_001b5a60jjj");
void func_001b5a60(u32 a0, u32 a1, u32 a2) {
    u32 t1 = a0;
    u32 t2 = a1;
    u32* b = (u32*)0x01D50000;
    u32* p = (u32*)b[-7380];
    u32 t3 = a2;
    if (p == 0) {
        return;
    }
    u32 q = p[17];
    if (q == 0) {
        return;
    }
    func_001b0210(q, t1, t2, t3);
}
}  // namespace n001b5a60

// 001b5ab0 (was src/anon/tiny_auto80_queue.cpp)
namespace n001b5ab0 {
u32 func_001b58a8(...) asm("func_001b58a8");
void func_001d2130(...) asm("func_001d2130");
/*TARGET 001b5ab0*/
void func_001b5ab0() asm("_Z13func_001b5ab0v");
void func_001b5ab0() {
    if (func_001b58a8() != 0) {
        u32* b = (u32*)0x01D50000;
        ((void(*)(u32, u32, f32))func_001d2130)((u32)((u8*)b[-7380] + 104), 1, 0.0f);
    }
}
}  // namespace n001b5ab0

// 001b5af0 (was src/anon/batch_w9.cpp)
namespace n001b5af0 {
extern u8* D_01d48cb0 asm("D_01d48cb0");
/*TARGET 001b5af0*/
// 0x001a1db8: definition moved into src/anon/unit_0019fb70.cpp

// 001b1fc8: moved to src/anon/unit_001b1d20.cpp

u16 func_001b5af0(void) asm("func_001b5af0");
// 0x001a1db8: definition moved into src/anon/unit_0019fb70.cpp

// 001b1fc8: moved to src/anon/unit_001b1d20.cpp

u16 func_001b5af0(void) {
    u8* p = D_01d48cb0;
    if (p == 0 || (*(u32*)(p + 64) & 4)) return 0;
    return *(u16*)(*(u8**)p + 40);
}
}  // namespace n001b5af0

// 001b5b20 (was src/anon/batch_w92.cpp)
namespace n001b5b20 {
struct C1b5 { u8 pad[384]; s32 f384; u8 pad2[48]; f32 f436; };
void* func_001d3fe0(u16) asm("func_001d3fe0");
s32 func_001b58a8(void) asm("func_001b58a8");
s32 func_001c8db8(void*, s32) asm("func_001c8db8");
s32 func_001d3f80(void*) asm("func_001d3f80");
s32 func_001b5c60(u16*) asm("func_001b5c60");
// to_1bbf80_field28
s32 func_001a1de0(C1b5*) asm("func_001a1de0");
void* func_0017df58(s32) asm("func_0017df58");
s32 func_0019ba60(void*) asm("func_0019ba60");
s32 func_0017e280(void*) asm("func_0017e280");
extern u8 D_00351ec0 asm("D_00351ec0");
/*TARGET 001b5b20*/
s32 func_001b5b20(u8* self, u16* ev, s32 r) asm("func_001b5b20");
s32 func_001b5b20(u8* self, u16* ev, s32 r) {
    void* o = func_001d3fe0(ev[0]);
    if (!o) return r;
    if (func_001b58a8()) {
        r = 5;
    } else if (ev[1] == 81 && func_001c8db8(&D_00351ec0, 0)) {
        r = 5;
    } else if (func_001d3f80(o)) {
        if ((*(C1b5**)(self + 1164))->f436 == 0.0f) r = 5;
    } else {
        s32 n = func_001b5c60(ev);  // to_1bbf80_field28
        if (n > 0) {
            if (func_001a1de0(*(C1b5**)(self + 1164))) r = 5;
            else if ((*(C1b5**)(self + 1164))->f384 < n) r = 2;
        }
    }
    if (ev[1] == 707 && r < 4) {
        for (s32 i = 0; i < 2; i++) {
            void* q = func_0017df58(i);
            if (func_0019ba60(q) && !func_0017e280(q)) { r = 5; break; }
        }
    }
    return r;
}
}  // namespace n001b5b20

// 001b5c60 (was src/anon/tiny_wrappers_more.cpp)
namespace n001b5c60 {
u32 func_001bbf80(u32, u32, u32, u32) asm("_Z13func_001bbf80jjjj");
/*TARGET 001b5c60*/
u32 func_001b5c60(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b5c60jjjj");
u32 func_001b5c60(u32 a0, u32 a1, u32 a2, u32 a3) {  // to_1bbf80_field28
    return func_001bbf80(((u32)(*(u8*)((u32)(a0) + 28u))), a1, a2, a3);
}
}  // namespace n001b5c60

// 001b5c78 (was src/anon/batch_w21.cpp)
namespace n001b5c78 {
// to_306698_arg10
void func_001d2180(void*) asm("func_001d2180");
void func_001d20a8(void*) asm("func_001d20a8");
u32 YS_LIMIT_reset_hit_counter(u8*) asm("_ZN2YS5LIMIT17reset_hit_counterEv");
/*TARGET 001b5c78*/
// 0x001ae620: definition moved into src/anon/unit_001ada38.cpp

u32 YS_LIMIT_reset_hit_counter(u8* self) asm("_ZN2YS5LIMIT17reset_hit_counterEv");
// 0x001ae620: definition moved into src/anon/unit_001ada38.cpp

u32 YS_LIMIT_reset_hit_counter(u8* self) {
    u8* h = self + 104;
    u32 n = *(u32*)(h + 44);
    func_001d2180(h);
    func_001d20a8(h);
    return n;
}
}  // namespace n001b5c78

// 001b5cb8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n001b5cb8 {
u32 func_001d4808(u32, u32, u32, u32) asm("_Z13func_001d4808jjjj");
/*TARGET 001b5cb8*/
u32 func_001b5cb8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b5cb8jjjj");
u32 func_001b5cb8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = *(u32*)((u32)r4 + (s32)(0));
    u32 (*fp_call4_001d4808)(u32, u32, u32, u32) = func_001d4808;
    r2 = fp_call4_001d4808(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001b5cb8

// 001b5cd8 (was gap, never written) (C2 copy of 0x1b5ce8)
namespace n001b5cd8 {
void func_001b5cd8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001b5cd8");
void func_001b5cd8(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)(a0 + 0) = a1;
    *(u32*)(a0 + 4) = a2;
    *(u32*)(a0 + 8) = a3;
}
}


// 001b5ce8 (was src/anon/tiny_auto80.cpp)
namespace n001b5ce8 {
/*TARGET 001b5ce8*/
// 0x0019f480: definition moved into src/anon/unit_0019ee80.cpp

// 001ac6a0: moved to src/anon/unit_001abb28.cpp

void func_001b5ce8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b5ce8jjjj");
// 0x0019f480: definition moved into src/anon/unit_0019ee80.cpp

// 001ac6a0: moved to src/anon/unit_001abb28.cpp

void func_001b5ce8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(u32*)((u32)r4 + (s32)(0)) = r5;
    *(u32*)((u32)r4 + (s32)(4)) = r6;
    *(u32*)((u32)r4 + (s32)(8)) = r7;
}
}  // namespace n001b5ce8

// 4-char id (retail 0x36da94-0x36da9f)
extern "C" const u32 D_0036da94 = 0;
extern "C" const char D_0036da98[8] __attribute__((aligned(4))) = "comd";

// 001b5cf8 (was src/anon/batch_w298.cpp)
namespace n001b5cf8 {
#define QCOPY298(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV298 {
    f32 x, y, z, w;
    QV298() {}
    QV298(const QV298& o) { QCOPY298(this, &o); }
    QV298& operator=(const QV298& o) { if (this != &o) QCOPY298(this, &o); return *this; }
} __attribute__((aligned(16)));
struct O5cf8 { s32 f0; u8* p4; s32 f8; };
// 0022a3d0: moved to src/sasa/musical_input.cpp (linked unit)

s32 func_0016a070(u8*) asm("func_0016a070");
QV298* func_0016c028(u8*) asm("func_0016c028");
// obj_get_attach_or_alt
void func_001703a8(s32) asm("func_001703a8");
void func_001afb80(void*, s32, s32, s32) asm("func_001afb80");
void func_0016ed50(s32, s32, s32) asm("func_0016ed50");
void func_00170888(void*) asm("func_00170888");
void func_001c9e50(void*) asm("func_001c9e50");
s32 func_0017e4f8(s32, QV298*, f32, f32, f32) asm("func_0017e4f8");
void func_001617d8(void) asm("func_001617d8");
void func_001ad990(u8*, f32, f32, f32) asm("func_001ad990");
s32 func_001ba028(u8*) asm("func_001ba028");
// list_contains_ptr
void func_00102448(void*, s32) asm("func_00102448");
/*TARGET 001b5cf8*/
s32 func_001b5cf8(O5cf8* o, void* a1) asm("func_001b5cf8");
s32 func_001b5cf8(O5cf8* o, void* a1)
{
    s32 s5 = -1;
    s32 s6 = func_0016a070(o->p4);
    s32 id = ((s32 (*)(u8*))(*(void***)o->p4)[15])(o->p4);
    s32 s4 = *(s32*)(o->p4 + 1964);
    switch (id) {
    case 2410: s5 = 5; break;
    case 2420: s5 = 6; break;
    }
    QV298 pos;
    pos = *func_0016c028(o->p4);  // obj_get_attach_or_alt
    switch (o->f0) {
    case 0: {
        u8* p = o->p4;
        if (!(*(u32*)(p + 2040) & 0x10)) { f32 c = 8.0f; func_001ad990(p + 2092, 1.0f, 0.0f, c); }
        *(u32*)(p + 2040) |= 0x10;
        while (func_001ba028(o->p4)) func_00102448(a1, 0);  // list_contains_ptr
        func_00102448(a1, 1);
        break;
    }
    case 1:
        ((void (*)(u8*))(*(void***)o->p4)[36])(o->p4);
        break;
    }
    func_001703a8(id);
    func_001703a8(id + 1);
    func_001703a8(id + 2);
    func_001afb80(a1, s4, s6, o->f8);
    func_0016ed50(o->f8, id, s5);
    func_00170888(a1);
    func_001c9e50(a1);
    s32 r = func_0017e4f8(o->f8, &pos, 100.0f, 200.0f, 300.0f);
    if (o->f0 == 1) func_001617d8();
    return r;
}
}  // namespace n001b5cf8

// 001b5ef0 (was src/anon/batch_wcx2.cpp)
namespace n001b5ef0 {
// 0x00197318: definition moved into src/anon/unit_00195d00.cpp

// ---- 001b5ef0
extern u32 D_00351214 asm("D_00351214");
union UDf_001b5ef0 { u8* p; void (*f)(); u32 i; };
extern UDf_001b5ef0 D_00351180 asm("D_00351180");
extern u8 D_00351ec0[] asm("D_00351ec0");
void func_001b5f68() asm("func_001b5f68");
void func_001b5fe0() asm("func_001b5fe0");
u8* func_00102818(u32, u32, u32, void (*)(), u32) asm("func_00102818");
void func_001c8d80(u8*, u32) asm("func_001c8d80");
/*TARGET 001b5ef0*/
void func_001b5ef0(u8* p) asm("func_001b5ef0");
void func_001b5ef0(u8* p) {
    u8* t = func_00102818(D_00351214, 0, 2, func_001b5f68, 8192);
    *(u8**)(t + 4) = p;
    *(void (**)())(t + 48) = func_001b5fe0;
    D_00351180.p = t;
    func_001c8d80(D_00351ec0, 2);
    *(u32*)(p + 264) |= 0x100;
}
}  // namespace n001b5ef0

// 001b5f68 (was src/anon/auto80_199_queue.cpp)
namespace n001b5f68 {
/*TARGET 001b5f68*/
void func_001b5f68(u32 a0) asm("_Z13func_001b5f68j");
void func_001b5f68(u32 a0) {
    u32 s0 = a0;
    u32 s1 = *(u32*)(a0 + 4);
    u32 stack_buf[4];

    u32 a3 = func_0017df70(3);
    func_001b5ce8(stack_buf, 0, s1, a3);

    *(u32*)(s0 + 8) = func_0016a070(s1);

    u32 v0 = func_001b5cf8(stack_buf, s0);
    VirtCall fn = (VirtCall)(*(u32*)(*(u32*)v0 + 0x54));
    fn(v0, 17, 0);
}
}  // namespace n001b5f68

// 001b5fe0 (was src/anon/auto80_199_queue.cpp)
namespace n001b5fe0 {
/*TARGET 001b5fe0*/
void func_001b5fe0(u32 a0) asm("_Z13func_001b5fe0j");
void func_001b5fe0(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_001a8bd0(-1);
    func_001a8f68(v0, *(u32*)(s0 + 8));
    func_001afae0();
    func_001c8d98((u32)&D_00351ec0, 2);
    D_00351180 = 0;
}
}  // namespace n001b5fe0

// 001b6038 (was src/anon/auto200_999.cpp)
namespace n001b6038 {
void func_00102670(u32, u32) asm("_Z13func_00102670jj");
extern u8 D_00350000 asm("D_00350000");
/*TARGET 001b6038*/
// 0x001d5698: definition moved into src/anon/unit_001d4f40.cpp

void func_001b6038() asm("_Z13func_001b6038v");
// 0x001d5698: definition moved into src/anon/unit_001d4f40.cpp

void func_001b6038() {
    u32 t6 = *(u32 *)((u8 *)&D_00350000 + 4480u);
    if (t6 == 0) {
        return;
    }
    func_00102670(*(u32 *)((u8 *)&D_00350000 + 4628u), t6);  // to_1025f8
}
}  // namespace n001b6038

// 001b6070 (was src/anon/batch_w47.cpp)
namespace n001b6070 {
// 0x001aa728: definition moved into src/anon/unit_001a9130.cpp

s32 func_001b58a8(void) asm("func_001b58a8");
u32 func_001a8bd0(s32) asm("func_001a8bd0");
s32 func_001a8bf8(u32, s32) asm("func_001a8bf8");
// get_bits5_at
s32 func_001c8db8(void*, s32) asm("func_001c8db8");
extern u8 D_00351ec0[] asm("D_00351ec0");
/*TARGET 001b6070*/
s32 func_001b6070(void) asm("func_001b6070");
s32 func_001b6070(void) {
    if (func_001b58a8()) return 0;
    s32 r = 0;
    if (func_001a8bf8(func_001a8bd0(-1), 3) != 18) r = func_001c8db8(D_00351ec0, 0) == 0;
    return r;
}
}  // namespace n001b6070

// 001b60e0 (was src/anon/batch_w8021_nsa.cpp)
namespace n001b60e0 {
// 001b60e0 and 001b6298 are constructor twins. The flags store goes through a
// byte offset, so it has no MEM_EXPR and sched2 puts the id store before sd ra.
struct W8021Sub { u8 pad[8]; u32 f8; };
struct W8021Owner { u8 pad[0xc]; W8021Sub* p0c; u8 pad2[0x160 - 0x10]; u32 f160; };
struct W8021Obj { u8 pad[4]; void* back; u8 pad2[0x30 - 8]; void* cb; };
struct W8021T { W8021Owner* owner; s32 id; s32 x; u32 flags; s32 f10; s32 f14; W8021Obj* f18; u8 f1c; };
extern W8021T* D_00351184 asm("D_00351184");
extern u32 D_00351214 asm("D_00351214");
extern u8 D_00351ec0[] asm("D_00351ec0");
void func_001b6d00(void) asm("func_001b6d00");
s32 func_001a1658(s32, s32) asm("func_001a1658");
s32 func_001d1438(s32) asm("func_001d1438");
s32 func_0019c090(W8021Owner*) asm("func_0019c090");
void func_001c8d80(void*, s32) asm("func_001c8d80");
W8021Obj* func_00102818(u32, u32, u32, void*, s32) asm("func_00102818");
void func_00102788(u32, u32, u32, void*) asm("func_00102788");
void func_001b6ca8(void) asm("func_001b6ca8");
void func_001b6cc8(void) asm("func_001b6cc8");
void func_001b6a50(void) asm("func_001b6a50");
static inline __attribute__((always_inline)) bool ok(s32 id) { return id != 0 && id < 7; }
static inline __attribute__((always_inline)) bool isA(u32 f) {
    bool r = false;
    if (f & 0x20) goto yes;
    if (f & 0x1000000) goto yes;
    goto no;
yes: r = true;
no: return r;
}
static inline __attribute__((always_inline)) bool isB(u32 f) {
    bool r = false;
    if (isA(f)) goto yes;
    if (f & 0x40) goto yes;
    goto no;
yes: r = true;
no: return r;
}
/*TARGET 001b60e0*/
void func_001b60e0(W8021T* t, W8021Owner* o, s32 id, s32 x) asm("func_001b60e0");
void func_001b60e0(W8021T* t, W8021Owner* o, s32 id, s32 x) {
    t->owner = o;
    t->id = id;
    t->x = x;
    *(u32*)((u8*)t + 12) = 0;
    t->f10 = 0;
    t->f14 = 0;
    t->f1c = 0;
    if (D_00351184) func_001b6d00();
    D_00351184 = t;
    if (ok(id)) t->f14 = func_001a1658(1, -1);
    if (t->x == 0) t->x = func_001d1438(t->id);
    if (func_0019c090(t->owner)) {
        W8021Owner* ow = t->owner;
        t->flags |= 1;
        if (!isB(ow->f160)) {
            u32 g = ow->p0c->f8;
            if (g & 0x40) goto out;
            if (g & 0x4000) goto out;
            t->flags |= 2;
        }
    }
out:
    func_001c8d80(D_00351ec0, 1);
    t->f18 = func_00102818(D_00351214, 0, 1, (void*)func_001b6ca8, 0x2000);
    t->f18->back = t;
    t->f18->cb = (void*)func_001b6cc8;
    if (t->f14) func_00102788(D_00351214, 0, 1, (void*)func_001b6a50);
}
}  // namespace n001b60e0

// 001b6298 (was src/anon/batch_w8021_nsa.cpp)
namespace n001b6298 {
// 001b60e0 and 001b6298 are constructor twins. The flags store goes through a
// byte offset, so it has no MEM_EXPR and sched2 puts the id store before sd ra.
struct W8021Sub { u8 pad[8]; u32 f8; };
struct W8021Owner { u8 pad[0xc]; W8021Sub* p0c; u8 pad2[0x160 - 0x10]; u32 f160; };
struct W8021Obj { u8 pad[4]; void* back; u8 pad2[0x30 - 8]; void* cb; };
struct W8021T { W8021Owner* owner; s32 id; s32 x; u32 flags; s32 f10; s32 f14; W8021Obj* f18; u8 f1c; };
extern W8021T* D_00351184 asm("D_00351184");
extern u32 D_00351214 asm("D_00351214");
extern u8 D_00351ec0[] asm("D_00351ec0");
void func_001b6d00(void) asm("func_001b6d00");
s32 func_001a1658(s32, s32) asm("func_001a1658");
s32 func_001d1438(s32) asm("func_001d1438");
s32 func_0019c090(W8021Owner*) asm("func_0019c090");
void func_001c8d80(void*, s32) asm("func_001c8d80");
W8021Obj* func_00102818(u32, u32, u32, void*, s32) asm("func_00102818");
void func_00102788(u32, u32, u32, void*) asm("func_00102788");
void func_001b6ca8(void) asm("func_001b6ca8");
void func_001b6cc8(void) asm("func_001b6cc8");
void func_001b6a50(void) asm("func_001b6a50");
static inline __attribute__((always_inline)) bool ok(s32 id) { return id != 0 && id < 7; }
static inline __attribute__((always_inline)) bool isA(u32 f) {
    bool r = false;
    if (f & 0x20) goto yes;
    if (f & 0x1000000) goto yes;
    goto no;
yes: r = true;
no: return r;
}
static inline __attribute__((always_inline)) bool isB(u32 f) {
    bool r = false;
    if (isA(f)) goto yes;
    if (f & 0x40) goto yes;
    goto no;
yes: r = true;
no: return r;
}
void u_tail4_001b6298(W8021T* t, W8021Owner* o, s32 id, s32 x) asm("_Z16u_tail4_001b6298jjjj");
/*TARGET 001b6298*/
void u_tail4_001b6298(W8021T* t, W8021Owner* o, s32 id, s32 x) asm("_Z16u_tail4_001b6298jjjj");
void u_tail4_001b6298(W8021T* t, W8021Owner* o, s32 id, s32 x) {
    t->owner = o;
    t->id = id;
    t->x = x;
    *(u32*)((u8*)t + 12) = 0;
    t->f10 = 0;
    t->f14 = 0;
    t->f1c = 0;
    if (D_00351184) func_001b6d00();
    D_00351184 = t;
    if (ok(id)) t->f14 = func_001a1658(1, -1);
    if (t->x == 0) t->x = func_001d1438(t->id);
    if (func_0019c090(t->owner)) {
        W8021Owner* ow = t->owner;
        t->flags |= 1;
        if (!isB(ow->f160)) {
            u32 g = ow->p0c->f8;
            if (g & 0x40) goto out;
            if (g & 0x4000) goto out;
            t->flags |= 2;
        }
    }
out:
    func_001c8d80(D_00351ec0, 1);
    t->f18 = func_00102818(D_00351214, 0, 1, (void*)func_001b6ca8, 0x2000);
    t->f18->back = t;
    t->f18->cb = (void*)func_001b6cc8;
    if (t->f14) func_00102788(D_00351214, 0, 1, (void*)func_001b6a50);
}
}  // namespace n001b6298

// 001b6450 (was src/anon/auto80_199_queue.cpp)
namespace n001b6450 {
/*TARGET 001b6450*/
void func_001b6450(u32 a0) asm("_Z13func_001b6450j");
void func_001b6450(u32 a0) {
    u32 s0 = a0;
    u32 p = *(u32*)(a0 + 0x10);
    if (p != 0) {
        func_001b1ab8(p);  // alloc_from_pool_magic_b
        *(u32*)(s0 + 0x10) = 0;
    }

    func_0019ed48((u32)&D_00350448);
    func_001b6ab8(s0);

    if (*(u8*)(s0 + 0x1c) != 0) {
        func_001c9b90();
    }
    func_001c8d98((u32)&D_00351ec0, 1);

    u32 s1 = (u32)&D_00351eb8;
    if ((*(u32*)(s0 + 0x0c) & 8) == 0) {
        u32 v0 = func_001c8db8(s1, 0);
        if (v0 != 0) {
            func_001c8d98(s1, 0);
        }
    }

    u32 t6 = D_00351184;
    if ((t6 ^ s0) == 0) {
        t6 = 0;
    }
    D_00351184 = t6;
}
}  // namespace n001b6450

// 001b6518 (was src/anon/auto80_199_queue.cpp)
namespace n001b6518 {
/*TARGET 001b6518*/
void func_001b6518(u32 a0) asm("_Z13func_001b6518j");
void func_001b6518(u32 a0) {
    u32 s0 = a0;
    u32 p = *(u32*)(a0 + 0x10);
    if (p != 0) {
        func_001b1ab8(p);  // alloc_from_pool_magic_b
        *(u32*)(s0 + 0x10) = 0;
    }

    func_0019ed48((u32)&D_00350448);
    func_001b6ab8(s0);

    if (*(u8*)(s0 + 0x1c) != 0) {
        func_001c9b90();
    }
    func_001c8d98((u32)&D_00351ec0, 1);

    u32 s1 = (u32)&D_00351eb8;
    if ((*(u32*)(s0 + 0x0c) & 8) == 0) {
        u32 v0 = func_001c8db8(s1, 0);
        if (v0 != 0) {
            func_001c8d98(s1, 0);
        }
    }

    u32 t6 = D_00351184;
    if ((t6 ^ s0) == 0) {
        t6 = 0;
    }
    D_00351184 = t6;
}
}  // namespace n001b6518

