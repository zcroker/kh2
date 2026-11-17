// Linked unit 0x001117d8-0x001135b0 (one namespace per old matched source; class methods in their own namespace).
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

// 001117d8 (was gap, never written)
namespace n001117d8 {
s32 func_00175bb8(u8*) asm("func_00175bb8");
s32 func_001117d8(u8* p) asm("func_001117d8");
s32 func_001117d8(u8* p) {
    struct NoTail { ~NoTail() {} } nt;
    if (*(u32*)(p + 2940) & 0x400) return 0;
    return func_00175bb8(p);
}
}

// 00111808 (was src/anon/batch_w51.cpp)
namespace n00111808 {
f32 func_001142e0(u32, u32, u32, u32) asm("func_001142e0");
// entry8_float_by_flags
s32 func_001917c0(void) asm("func_001917c0");
typedef s32 (*VFnI)(void*);
/*TARGET 00111808*/
// Scaled value: base minus half of a field, clamped to >= 1, doubled for state 3 in battle mode.
f32 func_00111808(u8* p) asm("func_00111808");
// Scaled value: base minus half of a field, clamped to >= 1, doubled for state 3 in battle mode.
f32 func_00111808(u8* p) {  // obj_update_sprite_floats
    f32 r = func_001142e0(*(u32*)(p + 2912), 1, 0, 1) - *(f32*)(p + 1464) * 0.5f;
    if (r <= 1.0f) r = 1.0f;
    if (func_001917c0()) {
        if ((*(VFnI*)(*(u8**)p + 152))(p) == 3) r += r;
    }
    return r;
}
}  // namespace n00111808

// 001118a8 (was src/anon/batch_w2462_nsa.cpp)
namespace n001118a8 {
inline void* operator new(unsigned int, void* p) { return p; }
// VU0 macro-mode vector/matrix helpers (hand-written asm in the original math library)
struct V1118a8 {
    f32 x, y, z, w;
    V1118a8() {}
    void set(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V1118a8(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V1118a8& operator=(const V1118a8& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V1118a8 operator-(const V1118a8& b) const
    {
        V1118a8 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V1118a8 operator*(f32 k) const
    {
        V1118a8 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    f32 dot(const V1118a8& o) const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this), "r"(&o) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
static inline V1118a8 operator*(f32 k, const V1118a8& v) { return v * k; }
struct M1118a8 {
    V1118a8 r[4];
    M1118a8() {}
    M1118a8& operator=(const M1118a8& o)
    {
        if (this != &o)
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    // out = this * (v.xyz, 1), w = 1
    void xfpt(V1118a8* out, const V1118a8& v) const
    {
        asm volatile(".set noreorder\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\t"
                     "vmove.w $vf5, $vf0\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
                     : : "r"(out), "r"(this), "r"(&v) : "memory");
    }
} __attribute__((aligned(16)));
struct Fr1118a8 {
    u8 pad0[112];
    V1118a8 v112;
    u8 pad1[1712 - 128];
    M1118a8 mtx;
};
extern s8 D_003a99a0 asm("D_003a99a0");
extern V1118a8 D_003a99b0[2] asm("D_003a99b0");
extern Fr1118a8* D_00341708[3] asm("D_00341708");
extern V1118a8 D_00341720[3] asm("D_00341720");
extern V1118a8 D_00341750[3] asm("D_00341750");
void func_002fd188(void (*)(void)) asm("func_002fd188");
void func_001135b0(void) asm("func_001135b0");
V1118a8* f1118a8_attach(Fr1118a8*) asm("func_0016c028");
f32 func_00111808(Fr1118a8*) asm("func_00111808");
/*TARGET 001118a8*/
void func_001118a8(void) asm("func_001118a8");
void func_001118a8(void)
{
    if (!D_003a99a0) {
        new (&D_003a99b0[0]) V1118a8(0.86f, 0.0f, 0.51f, 1.0f);
        new (&D_003a99b0[1]) V1118a8(-0.86f, 0.0f, 0.51f, 1.0f);
        D_003a99a0 = 1;
        func_002fd188(func_001135b0);
    }
    s32 i;
    for (i = 0; i < 3; i++) D_00341750[i] = D_00341720[i];
    Fr1118a8* leader = D_00341708[0];
    D_00341720[0] = *f1118a8_attach(leader);
    V1118a8 p, t, d;
    d = D_00341720[0] - D_00341750[0];
    s32 best[2];
    M1118a8 m;
    m = leader->mtx;
    m.r[3] = leader->v112;
    f32 bestDist[2];
    for (s32 k = 0; k < 2; k++) {
        best[k] = -1;
        bestDist[k] = 0.0f;
        Fr1118a8* f = D_00341708[k + 1];
        if (!f) continue;
        for (i = 0; i < 2; i++) {
            t = func_00111808(f) * D_003a99b0[i];
            m.xfpt(&p, t);
            d = p - *f1118a8_attach(f);
            f32 dist = d.dot(d);
            if (best[k] < 0 || dist < bestDist[k]) {
                bestDist[k] = dist;
                best[k] = i;
                D_00341720[k + 1] = p;
            }
        }
    }
    if (!D_00341708[1] || !D_00341708[2]) return;
    if (bestDist[1] < bestDist[0]) {
        if (best[0] != best[1]) return;
        best[0] ^= 1;
        f32 sc = func_00111808(D_00341708[1]);
        t = sc * D_003a99b0[best[0]];
        m.xfpt(&D_00341720[1], t);
    } else {
        if (best[1] != best[0]) return;
        best[1] ^= 1;
        f32 sc = func_00111808(D_00341708[2]);
        t = sc * D_003a99b0[best[1]];
        m.xfpt(&D_00341720[2], t);
    }
}
}  // namespace n001118a8

// 00111d18 (was gap, never written) / 00111d60
namespace n00111d18 {
struct Q { u32 v[4]; } __attribute__((aligned(16)));
extern Q D_00341720[] asm("D_00341720");
extern u32 D_00341708[] asm("D_00341708");
void func_0016adc8(u8*, Q*) asm("func_0016adc8");
void func_00111d18(u8* p) asm("func_00111d18");
void func_00111d18(u8* p) {
    *(u32*)(p + 3288) = 0;
    *(s32*)(p + 3280) = -1;
    Q t;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(&D_00341720[*(u32*)(p + 2928)]) : "$8", "memory");
    func_0016adc8(p, &t);
}
s32 func_00111d60() asm("func_00111d60");
s32 func_00111d60() {
    s32 n = 0;
    for (s32 i = 0; i < 3; i++) if (i != 0 && D_00341708[i]) n++;
    return n;
}
}

// 00111d98 (was src/anon/batch_w8026.c)
namespace n00111d98 {
/* 00111d98: look up a non-zero table entry after the matched one. */
extern void* D_00341708[] asm("D_00341708");
void* wtarget_00111d98(void* a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00111d98jjjj");
/*TARGET 00111d98*/
void* wtarget_00111d98(void* a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00111d98jjjj");
void* wtarget_00111d98(void* a, u32 b, u32 c, u32 d) {
    s32 i, j;
    for (i = 0; i < 3; i++) {
        if (i != 0 && D_00341708[i] == a) {
            for (j = 1; j < 3; j++) {
                s32 k = (i + j) % 3;
                if (k != 0 && D_00341708[k] != 0) return D_00341708[k];
            }
        }
    }
    return 0;
}
}  // namespace n00111d98

// 00111e20 (was src/naka/libkn/friend.cpp)
namespace kn { // method 00111e20
extern u32 Friend_getPartner_raw(u32) asm("_Z16wtarget_00111d98jjjj");
class Friend;
/*TARGET 00111e20*/
u32 Friend::getPartner() { return Friend_getPartner_raw((u32)this); }
}  // kn

// 00111e38 (was src/naka/libkn/friend.cpp)
namespace kn { // method 00111e38
class Friend;
extern u32 D_00341708 asm("D_00341708");
/*TARGET 00111e38*/
u32 Friend::getPartyChara(s32 index) {
    return *(u32*)((u32)&D_00341708 + ((u32)index << 2));
}
}  // kn

// 00111e50 (was src/anon/batch_w76.cpp)
namespace n00111e50 {
extern u32 D_00341708[3] asm("D_00341708");
extern u32 D_0034e948 asm("D_0034e948");
u8* func_0017df58(s32) asm("func_0017df58");
void func_001136b0(u32, u8*) asm("func_001136b0");
void func_00135818(u32, u32) asm("func_00135818");
void func_001357d8(void) asm("func_001357d8");
/*TARGET 00111e50*/
void func_00111e50(void) asm("func_00111e50");
void func_00111e50(void)
{
    u32 old[3];
    s32 i, k;
    for (i = 0; i < 3; i++) old[i] = D_00341708[i];
    D_00341708[2] = 0;
    D_00341708[0] = D_0034e948;
    D_00341708[1] = 0;
    for (k = 1; k < 3; k++) {
        u8* o = func_0017df58(k - 1);
        if (o) {
            D_00341708[k] = (u32)o;
            func_001136b0(*(u32*)(o + 2912), o);
            *(s32*)(o + 2928) = k;
        }
    }
    for (i = 0; i < 3; i++) {
        if (old[i] != D_00341708[i]) func_00135818(old[i], D_00341708[i]);
    }
    func_001357d8();
}
}  // namespace n00111e50

// 00111f50 (was src/anon/batch_w3834_g.cpp)
namespace n00111f50 {
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
struct FMat { QWord c[4]; };
static inline void MatMul(FMat* r, const FMat* a, const FMat* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                 : : "r"(r), "r"(a), "r"(b) : "memory");
}
struct Tgt {
    u32 w[5];
};
s32 TARGET_is_exist(Tgt*) asm("_ZNK2YS6TARGET8is_existEv");
static inline bool TgtValid(Tgt* t) {
    bool r = false;
    if (TARGET_is_exist(t)) r = t->w[0] != 0;
    return r;
}
struct VObj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); };
struct Chara {
    u8 p0[0x10c]; u32 x10c;
    u8 p1[0x160 - 0x110]; u32 x160;
    u8 p2[0x9f4 - 0x164]; Tgt tgt;
    u8 p3[0xb60 - 0xa08]; VObj* xb60;
    u8 p4[0xbe0 - 0xb64]; QWord xbe0;
    u8 p5[0xce0 - 0xbf0]; u32 xce0;
    u8 p6[0xcec - 0xce4]; u32 xcec;
};
void func_00111e50(void) asm("func_00111e50");
void* func_00106a18(s32) asm("func_00106a18");
FMat* func_00106ad0(void*) asm("func_00106ad0");
u8* func_00106a60(s32) asm("func_00106a60");
void func_00146680(void*, FMat*) asm("func_00146680");
void* func_0016c028(Chara*) asm("func_0016c028");
s32 wtarget_0010b468(void*, void*) asm("_Z16wtarget_0010b468jjjj");
s32 func_00112d90(Tgt*) asm("func_00112d90");
void func_00190128(Tgt*) asm("func_00190128");
s32 Friend_is_party(Tgt*) asm("_ZN2kn6Friend8is_partyEPKN2YS6TARGETE");
QWord func_00190388(Tgt*) asm("func_00190388");
s32 ctarget_0019ba60(u32) asm("_Z16ctarget_0019ba60jjjj");
void func_001127c0(void) asm("func_001127c0");
void func_001118a8(void) asm("func_001118a8");
extern Chara* D_00341708[3] asm("D_00341708");
extern Tgt D_003417b0 asm("D_003417b0");
extern u32 D_003417c4 asm("D_003417c4");
extern u8 D_003a9250[] asm("D_003a9250");
extern u8 D_003a9040[] asm("D_003a9040");
/*TARGET 00111f50*/
void func_00111f50(void) asm("func_00111f50");
void func_00111f50(void) {
    func_00111e50();
    FMat* m = func_00106ad0(func_00106a18(1));
    u8* p = func_00106a60(1);
    FMat* q = p ? (FMat*)(p + 16) : 0;
    {
        FMat r;
        MatMul(&r, m, q);
        func_00146680(D_003a9250, &r);
    }
    s32 s6 = 0;
    Chara* lead = D_00341708[0];
    if (lead) {
        if (TgtValid(&lead->tgt)) {
            D_003417b0 = D_00341708[0]->tgt;
        }
        if (!(D_00341708[0]->x160 & 0x4000)) {
            s6 = wtarget_0010b468(D_003a9040, func_0016c028(D_00341708[0]));
        }
    }
    Tgt* t = &D_003417b0;
    if (t->w[2] || !TgtValid(t) || !func_00112d90(t)) func_00190128(t);
    s32 i;
    for (i = 1; i < 3; i++) {
        Chara* c = D_00341708[i];
        if (!c) continue;
        if (!Friend_is_party(&c->tgt)) {
            // No code: three extra reads of the loop pointer (&D_00341708[i]) raise its allocation
            // priority above c->tgt, so the pointer gets s2 and the target address s3 as in the original.
            asm("" : : "r"(&D_00341708[i]), "r"(&D_00341708[i]), "r"(&D_00341708[i]));
            if (func_00112d90(&c->tgt)) {
                c->xbe0 = func_00190388(&c->tgt);
            } else {
                if (!(c->x10c & 0x10000) || !TgtValid(&c->tgt)) func_00190128(&c->tgt);
            }
        }
        if (s6) c->xce0 = 0;
        if (c->xcec) {
            if (!ctarget_0019ba60(c->xcec)) c->xcec = 0;
        }
    }
    func_001127c0();
    if (D_003417c4) {
        D_003417c4 = ctarget_0019ba60(D_003417c4) ? D_003417c4 : 0;
    }
    if (D_00341708[0] && (D_00341708[1] || D_00341708[2])) func_001118a8();
    for (i = 0; i < 2; i++) {
        Chara* c = D_00341708[i + 1];
        if (c) c->xb60->v7();
    }
}
}  // namespace n00111f50

// 001122a0 (was gap, never written)
namespace n001122a0 {
struct C; struct CVt { void* f[8]; void (*f32)(C*); };
struct C { CVt* vt; };
extern u8 D_00341700 asm("D_00341700");
extern u8* D_00341708[] asm("D_00341708");
extern s32 D_003417d0 asm("D_003417d0");
extern s32 D_003417cc asm("D_003417cc");
extern f32 D_003417c8 asm("D_003417c8");
extern f32 D_00349e10 asm("D_00349e10");
u8 func_001917c0() asm("func_001917c0");
void func_001127b0() asm("func_001127b0");
void func_001122a0() asm("func_001122a0");
void func_001122a0() {
    u8 v = func_001917c0();
    if (D_00341700 && !v) func_001127b0();
    D_00341700 = v;
    u8* q = D_00341708[0];
    if (q == 0 || D_003417d0 != *(s32*)(q + 340)) {
        D_003417d0 = -1;
        D_003417cc = 0;
        D_003417c8 = 0;
    }
    if (0.0f < D_003417c8) D_003417c8 -= D_00349e10;
    for (s32 i = 1; i < 3; i++) {
        u8* o = D_00341708[i];
        if (o) { C* c = *(C**)(o + 2912); c->vt->f32(c); }
    }
}
}

// 00112388 (was src/anon/batch_w43.cpp)
namespace n00112388 {
void func_00135d88(void) asm("func_00135d88");
extern u8* D_00341708[] asm("D_00341708");
/*TARGET 00112388*/
void func_00112388(void) asm("func_00112388");
void func_00112388(void) {
    func_00135d88();
    for (s32 i = 0; i < 2; i++) {
        u8* e = D_00341708[i + 1];
        if (e) {
            u8* o = *(u8**)(e + 2912);
            (*(void (**)(void*))(*(u8**)o + 36))(o);
        }
    }
}
}  // namespace n00112388

// 001123f0 (was src/anon/batch_w85.cpp)
namespace n001123f0 {
// 128-bit vector with the engine's self-checking quadword copy
struct Vec4 {
    f32 x, y, z, w;
    Vec4& operator=(const Vec4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void func_00102788(u32, s32, s32, void (*)(void)) asm("func_00102788");
u8* func_00102c80(void) asm("func_00102c80");
void func_00111f50(void) asm("func_00111f50");
void func_001122a0(void) asm("func_001122a0");
void func_00112388(void) asm("func_00112388");
void func_001127b0(void) asm("func_001127b0");
void func_00190128(void*) asm("func_00190128");
void func_001357c8(void) asm("func_001357c8");
void func_00135d78(void) asm("func_00135d78");
extern u32 D_00351214 asm("D_00351214");
extern u32 D_00341708[3] asm("D_00341708");
extern Vec4 D_00341720[3] asm("D_00341720");
extern Vec4 D_00341750[3] asm("D_00341750");
extern u8 D_00341700 asm("D_00341700");
extern u32 D_00341780 asm("D_00341780");
extern u8 D_003417b0[] asm("D_003417b0");
/*TARGET 001123f0*/
void func_001123f0(void) asm("func_001123f0");
void func_001123f0(void) {
    s32 i;
    func_00102788(D_00351214, 0, 4, func_00111f50);
    func_00102788(D_00351214, 0, 6, func_001122a0);
    func_00102788(*(u32*)(func_00102c80() + 4), 1, 20500, func_00112388);
    for (i = 0; i < 3; i++) {
        D_00341708[i] = 0;
        asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&D_00341720[i]) : "memory");
        D_00341750[i] = D_00341720[i];
    }
    D_00341700 = 0;
    D_00341780 = 2;
    func_001127b0();
    func_00190128(D_003417b0);
    func_001357c8();
    func_00135d78();
}
}  // namespace n001123f0

// 001124e0 (was src/anon/batch_w1664.cpp)
namespace n001124e0 {
void wtarget_001124e0(u32, u32, u32, u32) asm("_Z16wtarget_001124e0jjjj");
/*TARGET 001124e0*/
void wtarget_001124e0(u32, u32, u32, u32) asm("_Z16wtarget_001124e0jjjj");
void wtarget_001124e0(u32, u32, u32, u32) {}
}  // namespace n001124e0

// 001124e8 (was src/anon/tiny_more3.cpp)
namespace n001124e8 {
extern u32 D_00341780 asm("D_00341780");
/*TARGET 001124e8*/
// 0010abb8: moved to src/anon/unit_0010a918.cpp

u32 func_001124e8(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_001124e8jjjj");
// 0010abb8: moved to src/anon/unit_0010a918.cpp

u32 func_001124e8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 old=D_00341780; D_00341780=a0; return old; }
}  // namespace n001124e8

// 001124f8 (was src/anon/batch_w47.cpp)
namespace n001124f8 {
void wtarget_001124f8(u32, u32, u32, u32) asm("_Z16wtarget_001124f8jjjj");
extern u8 D_00341700 asm("D_00341700");
extern u8 D_003a9040[] asm("D_003a9040");
extern u16 D_0032bae0 asm("D_0032bae0");
extern s32 D_00341780 asm("D_00341780");
extern s32 D_003417d0 asm("D_003417d0");
extern s32 D_003417c4 asm("D_003417c4");
extern s32 D_003417c8 asm("D_003417c8");
void func_0010b550(void*) asm("func_0010b550");
void func_001127b0(void) asm("func_001127b0");
/*TARGET 001124f8*/
void wtarget_001124f8(u32, u32, u32, u32) asm("_Z16wtarget_001124f8jjjj");
void wtarget_001124f8(u32, u32, u32, u32) {
    D_00341700 = 0;
    func_0010b550(D_003a9040);
    if (D_0032bae0 == 2056 || D_0032bae0 == 781) D_00341780 = 1;
    else D_00341780 = 2;
    D_003417d0 = -1;
    D_003417c4 = 0;
    D_003417c8 = 0;
    func_001127b0();
}
}  // namespace n001124f8

// 00112568 (was src/anon/batch_w1664.cpp)
namespace n00112568 {
/*TARGET 00112568*/
void func_00112568(void) asm("func_00112568");
void func_00112568(void) {}
}  // namespace n00112568

// 00112570 (was src/anon/tiny_auto80_solver.cpp)
namespace n00112570 {
u32 func_001058e8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001058e8jjjjjjjj");
u32 func_00112570(u32) asm("_Z13func_00112570j");
u32 func_0016a070(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0016a070jjjjjjjj");
u32 func_00188fe0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00188fe0jjjjjjjj");
/*TARGET 00112570*/
u32 func_00112570(u32 a0) asm("_Z13func_00112570j");
u32 func_00112570(u32 a0) {
    u32 s1 = a0;
    u32 s0 = ((u32(*)(u32))func_001058e8)(a0) + 9456;
    u32 v0 = ((u32(*)(u32))func_0016a070)(s1);
    return ((u32(*)(u32, u32))func_00188fe0)(s0, v0) + 244;
}
}  // namespace n00112570

// 001125b8 (was src/anon/tiny_jal_wrappers.cpp)
namespace n001125b8 {
u32 func_00112570(u32, u32, u32, u32) asm("_Z13func_00112570jjjj");
/*TARGET 001125b8*/
u32 func_001125b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001125b8jjjj");
u32 func_001125b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_00112570(r4, r5, r6, r7);
    r2 = (u32)(*(u8*)((u32)r2 + (s32)(0)));
    return r2;
}
}  // namespace n001125b8

// 001125d8 (was src/anon/batch_w100.cpp)
namespace n001125d8 {
struct S20 { u32 w[5]; };
struct Obj { u8 pad[2548]; S20 s; u8 pad2[2940-2548-20]; u32 flags; };
extern S20 D_003417b0 asm("D_003417b0");
void func_00190128(S20*) asm("func_00190128");
s32 func_00190140(S20*) asm("func_00190140");
void func_0010d918(Obj*, S20*, S20*) asm("func_0010d918");
static inline bool IsValid(S20* s) {
    bool ok = false;
    if (func_00190140(s)) ok = s->w[0] != 0;
    return ok;
}
/*TARGET 001125d8*/
void func_001125d8(Obj* o, s32 mode, S20* src) asm("func_001125d8");
void func_001125d8(Obj* o, s32 mode, S20* src) {
    switch (mode) {
    case 0: break;
    case 1: o->s = *src; break;
    case 2: o->s = D_003417b0; break;
    case 3: func_00190128(&o->s); func_0010d918(o, &o->s, &o->s); break;
    }
    if (!IsValid(&o->s)) func_00190128(&o->s);
    if (!mode) o->flags &= ~0x10000;
    else o->flags |= 0x10000;
}
}  // namespace n001125d8

// 00112720 (was src/anon/tiny_leaf_more.cpp)
namespace n00112720 {
/*TARGET 00112720*/
// 001051a0: moved to src/common/area.cpp

u32 func_00112720(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00112720jjjj");
// 001051a0: moved to src/common/area.cpp

u32 func_00112720(u32 a0, u32 a1, u32 a2, u32 a3) {  // check_2924_lt14
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = *(u32*)((u32)r4 + (s32)(2924));
    r2 = ((s32)r2 >= (14));
    return r2;
}
}  // namespace n00112720

// 00112730 (was src/anon/tiny_more.cpp)
namespace n00112730 {
/*TARGET 00112730*/
u32 func_00112730(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_00112730jjjj");
u32 func_00112730(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; u32 old = *(u32*)((u32)a0 + (2940)); *(u32*)((u32)a0 + (2940)) = a1; return old; }
}  // namespace n00112730

// 00112740 (was src/anon/tiny.cpp)
namespace n00112740 {
/*TARGET 00112740*/
// 0010aba8: moved to src/anon/unit_0010a918.cpp

u32 func_00112740(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00112740jjjj");
// 0010aba8: moved to src/anon/unit_0010a918.cpp

u32 func_00112740(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_field2940
    return (u32)(*(u32*)((u32)a0 + (2940)));
}
}  // namespace n00112740

// 00112748 (was gap, never written) / 00112770 / 00112c18
namespace n00112748 {
u32 func_00112748(u8* p, u32 v) asm("func_00112748");
u32 func_00112748(u8* p, u32 v) { u32 r = *(u32*)(p + 3320); *(u32*)(p + 3320) = v; return r; }
}

// 00112758 (was src/naka/libkn/friend.cpp)
namespace kn { // method 00112758
class Friend;
/*TARGET 00112758*/
s32 Friend::getToScript() { return reinterpret_cast<FriendLayout*>(this)->toScript; }
}  // kn

// 00112760 (was src/anon/tiny_more.cpp)
namespace n00112760 {
/*TARGET 00112760*/
u32 func_00112760(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_00112760jjjj");
u32 func_00112760(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; u32 old = *(u32*)((u32)a0 + (3316)); *(u32*)((u32)a0 + (3316)) = a1; return old; }
}  // namespace n00112760

// 00112770 (was gap, never written)
namespace n00112770 {
u32 func_00112770(u8* p) asm("func_00112770");
u32 func_00112770(u8* p) { return *(u32*)(p + 3316); }
}

// 00112778 (was src/naka/libkn/friend.cpp)
namespace kn { // method 00112778
class Friend;
typedef int (*FriendCallback)(Friend*, int);
/*TARGET 00112778*/
void Friend::setCallFromScript(FriendCallback v) {
    reinterpret_cast<FriendLayout*>(this)->callFromScript = v;
}
}  // kn

// 00112780 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00112780 {
/*TARGET 00112780*/
// 00102f80: moved to src/common/title.cpp

// 001063c0: moved to src/naka/libkn/memoryallocator.cpp

// 001063f0: moved to src/naka/libkn/memoryallocator.cpp

u32 func_00112780(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00112780jjjj");
// 00102f80: moved to src/common/title.cpp

// 001063c0: moved to src/naka/libkn/memoryallocator.cpp

// 001063f0: moved to src/naka/libkn/memoryallocator.cpp

u32 func_00112780(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r2 = *(u32*)((u32)r4 + (s32)(3324));
    r2 = ((u32 (*)(u32, u32, u32, u32))(u32)r2)(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00112780

// 001127a0 (was src/anon/batch_w1665.cpp)
namespace n001127a0 {
/*TARGET 001127a0*/
// 00104200: moved to src/common/gumibattle.cpp
u8* func_001127a0(u8* p) asm("func_001127a0");
// 00104200: moved to src/common/gumibattle.cpp
u8* func_001127a0(u8* p) { return p + 3040; }
}  // namespace n001127a0

// 001127b0 (was src/anon/tiny.cpp)
namespace n001127b0 {
/*TARGET 001127b0*/
void func_001127b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001127b0jjjj");
void func_001127b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0034u << 16);
    *(u32*)((u32)b + (6056)) = (u32)0;
}
}  // namespace n001127b0

// 001127c0 (was src/anon/batch_w93.cpp)
namespace n001127c0 {
// Builds a perspective projection matrix from the camera's near/far planes.
// 00106af0: moved to src/naka/libkn/camera.cpp

s32 func_0019ba60(u32) asm("func_0019ba60");
extern u32 D_00341788[8] asm("D_00341788");
extern s32 D_003417a8 asm("D_003417a8");
/*TARGET 001127c0*/
// Drops dead entries from the 8-slot list, compacting the survivors.
void func_001127c0(void) asm("func_001127c0");
// Drops dead entries from the 8-slot list, compacting the survivors.
void func_001127c0(void)
{
    u32 tmp[8];
    s32 n = 0;
    s32 i;
    for (i = 0; i < D_003417a8; i++) {
        if (func_0019ba60(D_00341788[i])) tmp[n++] = D_00341788[i];
    }
    D_003417a8 = n;
    for (i = 0; i < D_003417a8; i++) D_00341788[i] = tmp[i];
    for (i = D_003417a8; i < 8; i++) D_00341788[i] = 0;
}
}  // namespace n001127c0

// 001128d0 (was src/anon/batch_w253.cpp)
namespace n001128d0 {
extern u32 D_00341788[8] asm("D_00341788");
extern s32 D_003417a8 asm("D_003417a8");
void u_tail4(u32 a0, u8 a1) asm("_Z16u_tail4_001128d0jjjj");
/*TARGET 001128d0*/
void u_tail4(u32 a0, u8 a1) asm("_Z16u_tail4_001128d0jjjj");
void u_tail4(u32 a0, u8 a1) {
    s32 i;
    for (i = 0; i < D_003417a8; i++)
        if (D_00341788[i] == a0) break;
    s32 n = D_003417a8;
    if (i < n) {
        if (a1 == 0) {
            s32 j;
            for (j = i + 1; j < n; j++) D_00341788[j - 1] = D_00341788[j];
            D_003417a8--;
        } else {
            s32 j;
            for (j = i + 1; j < n; j++) D_00341788[j - i - 1] = D_00341788[j];
            D_003417a8 = D_003417a8 - i - 1;
        }
    }
}
}  // namespace n001128d0

// 001129d8 (was src/anon/batch_w43.cpp)
namespace n001129d8 {
void func_001128d0(u32, s32) asm("func_001128d0");
extern s32 D_003417a8 asm("D_003417a8");
extern u32 D_00341788[] asm("D_00341788");
/*TARGET 001129d8*/
void func_001129d8(u32 a) asm("func_001129d8");
void func_001129d8(u32 a) {
    func_001128d0(a, 1);
    if (D_003417a8 >= 8) func_001128d0(D_00341788[0], 1);
    D_00341788[D_003417a8++] = a;
}
}  // namespace n001129d8

// 00112a58 (was src/anon/batch_w1671.cpp)
namespace n00112a58 {
// 00105e68: static initialiser, now made by gcc in src/common/shop.cpp

extern s32 D_003417a8 asm("D_003417a8");
extern s32 D_00341788[] asm("D_00341788");
/*TARGET 00112a58*/
s32 func_00112a58(s32 a0) asm("func_00112a58");
s32 func_00112a58(s32 a0) {
    s32 n = D_003417a8;
    if (n == 0) return 0;
    if (a0 < 0) { s32 j = n + a0; if (j < 0) return 0; return D_00341788[j]; }
    if (a0 >= n) return 0;
    return D_00341788[a0];
}
}  // namespace n00112a58

// 00112ab8 (was src/anon/batch_w1886_nsa.cpp)
namespace n00112ab8 {
struct W1886P0;
struct W1886P0Vt { u8 pad[0x60]; s32 (*fn)(W1886P0*); };
struct W1886P0 { W1886P0Vt* vt; u8 pad[0x140 - 4]; u8 sub[0x14]; s32 v154; u8 pad2[0x7f8 - 0x158]; u32 flags; };
struct W1886Pn { u8 pad[0xb7c]; u32 flags; };
struct W1886G { W1886P0* p0; W1886Pn* p1; W1886Pn* p2; };
struct W1886Q { u8 pad[4]; u8 kind; };
struct W1886Arg { s32 v0; u8 pad[0xc]; s32 v10; u8 pad2[0xc]; W1886Q* q; };
static inline bool w1886_isk(W1886Q* q) { return q->kind == 5 || q->kind == 6; }
extern W1886G D_00341708 asm("D_00341708");
extern s32 D_003417c4 asm("D_003417c4");
extern f32 D_003417c8 asm("D_003417c8");
extern f32 D_003417cc asm("D_003417cc");
extern s32 D_003417d0 asm("D_003417d0");
s32 func_00112d90(W1886Arg*) asm("func_00112d90");
f32 func_001806f8(void*, s32) asm("func_001806f8");
void func_001129d8(s32) asm("func_001129d8");
/*TARGET 00112ab8*/
void func_00112ab8(s32 mode, W1886Arg* arg) asm("func_00112ab8");
void func_00112ab8(s32 mode, W1886Arg* arg)
{
    W1886G* g = &D_00341708;
    W1886P0* p = g->p0;
    switch (mode) {
    case 0:
        if (arg == 0) break;
        if (p->flags & 4) break;
        if (p->vt->fn(p)) break;
        if (w1886_isk(arg->q)) break;
        func_001129d8(arg->v10);
        if (g->p1) g->p1->flags &= ~0x100;
        if (g->p2) g->p2->flags &= ~0x100;
        break;
    case 1: {
        D_003417c4 = 0;
        if (arg && func_00112d90(arg)) D_003417c4 = arg->v0;
        f32 f = func_001806f8(D_00341708.p0->sub, -1);
        D_003417cc = D_003417c8 = f;
        D_003417d0 = D_00341708.p0->v154;
        if (D_00341708.p1) D_00341708.p1->flags &= ~0x200;
        if (D_00341708.p2) D_00341708.p2->flags &= ~0x200;
        break;
    }
    }
}
}  // namespace n00112ab8

// 00112c18 (was gap, never written)
namespace n00112c18 {
extern u32 D_003417c4 asm("D_003417c4");
u32 func_00112c18() asm("func_00112c18");
u32 func_00112c18() { return D_003417c4; }
}

// 00112c28 (was src/anon/tiny.cpp)
namespace n00112c28 {
extern u32 D_003417c8 asm("D_003417c8");
/*TARGET 00112c28*/
f32 func_00112c28(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00112c28jjjj");
f32 func_00112c28(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return *(f32*)&D_003417c8;
}
}  // namespace n00112c28

// 00112c38 (was src/anon/tiny.cpp)
namespace n00112c38 {
extern u32 D_003417cc asm("D_003417cc");
/*TARGET 00112c38*/
f32 func_00112c38(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00112c38jjjj");
f32 func_00112c38(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return *(f32*)&D_003417cc;
}
}  // namespace n00112c38

// 00112c48 (was src/anon/tiny.cpp)
namespace n00112c48 {
/*TARGET 00112c48*/
u32 func_00112c48(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00112c48jjjj");
u32 func_00112c48(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0034u << 16);
    return (u32)(*(u32*)((u32)b + (6096)));
}
}  // namespace n00112c48

// 00112c58 (was src/anon/tiny_more.cpp)
namespace n00112c58 {
/*TARGET 00112c58*/
void func_00112c58(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_00112c58jjjj");
void func_00112c58(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = *(u32*)((u32)a0 + (2940)); v |= (u32)0x40000000u; *(u32*)((u32)a0 + (2940)) = v; }
}  // namespace n00112c58

// 00112c70 (was src/anon/batch_w1666.cpp)
namespace n00112c70 {
/*TARGET 00112c70*/
u32 func_00112c70(u8* p) asm("func_00112c70");
u32 func_00112c70(u8* p) { return (*(s32*)(p + 2940) >> 30) & 1; }
}  // namespace n00112c70

// 00112c80 (was src/anon/tiny_auto80_queue.cpp)
namespace n00112c80 {
u32 func_0019ba60(...) asm("func_0019ba60");
/*TARGET 00112c80*/
u32 func_00112c80(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00112c80jjjjjjjj");
u32 func_00112c80(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16;
    if (!((r4 != 0u))) {
        r15 = 0u;
    } else {
        r16 = r4;
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0019ba60)(r4, r5, r6, r7, r8, r9, r10, r11);
        r15 = 0u;
        if (r2 != 0u) {
            r15 = *(volatile u32*)((u32)r16 + (s32)(1416));
            r15 = (u32)(r15 & 0x0004u);
            r15 = ((u32)0u < (u32)r15);
        }
    }
    r2 = r15;
    return r2;
}
}  // namespace n00112c80

// 00112cc8 (was src/anon/auto80_199_queue.cpp)
namespace n00112cc8 {
/*TARGET 00112cc8*/
u32 func_00112cc8(s32* a0) asm("_Z13func_00112cc8Pi");
u32 func_00112cc8(s32* a0) {
    s32* s1 = a0;
    u32 s0 = 0;
    u32 t6 = 0;

    if (func_00190140() != 0) {
        s0 = (u32)(*s1 != 0);
    }
    if ((s0 & 0xff) != 0) {
        t6 = func_00112c80((u32)*s1);
    }
    return t6;
}
}  // namespace n00112cc8

// 00112d28 (was src/anon/batch_w44.cpp)
namespace n00112d28 {
s32 func_0019ba60(void*) asm("func_0019ba60");
/*TARGET 00112d28*/
// Frees the menu allocator unless it is locked or the menu mode is 1, 2 or 6.
// 00103748: MENU::DestoryAllocator, moved to src/common/unit_001031b0.cpp

s32 func_00112d28(u8* p) asm("func_00112d28");
// Frees the menu allocator unless it is locked or the menu mode is 1, 2 or 6.
// 00103748: MENU::DestoryAllocator, moved to src/common/unit_001031b0.cpp

s32 func_00112d28(u8* p) {
    s32 r = 0;
    if (p == 0) return r;
    if (!func_0019ba60(p)) return 0;
    if (!(*(u32*)(p + 1416) & 0x10)) return 0;
    if (*(u32*)(p + 2040) & 4) return 0;
    u32 m = *(u32*)(p + 264) & 0x8000;
    return m == 0;
}
}  // namespace n00112d28

// 00112d90 (was src/anon/batch_w218.cpp)
namespace n00112d90 {
u32 func_00190140(void) asm("func_00190140");
u32 func_00112d28(u32) asm("func_00112d28");
/*TARGET 00112d90*/
u32 func_00112d90(u32* p) asm("func_00112d90");
u32 func_00112d90(u32* p) {
    u32 ok = 0; u32 r = 0;
    if (func_00190140()) ok = *p != 0;
    if ((u8)ok) r = func_00112d28(*p);
    return r;
}
}  // namespace n00112d90

// 00112df0 (was src/anon/batch_w283.cpp)
namespace n00112df0 {
struct W283_Tgt { void* obj; u32 a, b, c, d; };
struct W283_TI { f32 f0; f32 r; f32 f8; u32 f12; f32 pos[4]; } __attribute__((aligned(16)));
struct W283_Q { f32 v[4]; } __attribute__((aligned(16)));
void func_00190128(W283_Tgt*) asm("func_00190128");
void W283_set_obj(W283_Tgt*, void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
void* func_00190730(W283_Tgt*, void*) asm("func_00190730");
s32 W283_can_attack(W283_Tgt*) asm("_ZNK2YS6TARGET10can_attackEv");
void func_0018a818(W283_TI*, void*, void*) asm("func_0018a818");
/*TARGET 00112df0*/
void func_00112df0(void* obj, W283_Tgt* out, W283_Q* from, f32 best) asm("func_00112df0");
void func_00112df0(void* obj, W283_Tgt* out, W283_Q* from, f32 best) {
    W283_TI ti;
    W283_Tgt t;
    W283_Q d;
    void* cur = 0;
    ti.f12 = 0;
    func_00190128(&t);
    func_00190128(&t);
    W283_set_obj(&t, obj, 0);
    while ((cur = func_00190730(&t, cur)) != 0) {
        if (t.obj != obj) break;
        if (!W283_can_attack(&t)) continue;
        if (from == 0) { *out = t; break; }
        func_0018a818(&ti, obj, cur);
        f32 len;
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(ti.pos), "r"(from), "r"(&d) : "memory");
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8");
        len = len - ti.r;
        if (best <= 0.0f || len < best) {
            best = len;
            *out = t;
        }
    }
}
}  // namespace n00112df0

// 00112f88 (was src/anon/batch_w260.cpp)
namespace n00112f88 {
struct W260Q { f32 x, y, z, w; } __attribute__((aligned(16)));
// VU0 squared length of the xyz part.
static inline __attribute__((always_inline)) f32 W260LenSq(const W260Q& a)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a) : "$8", "memory");
    return r;
}
struct W260Col { f32 a[3]; int n; W260Q b; W260Col() : n(0) {} };
struct W260Tg { u8* obj; };
int w260_is_exist(W260Tg*) asm("_ZNK2YS6TARGET8is_existEv");
static inline __attribute__((always_inline)) bool W260Valid(W260Tg* t) { return w260_is_exist(t) && t->obj; }
// 0x0018e698: definition moved into src/anon/unit_0018d050.cpp

W260Q func_00190388(W260Tg*) asm("func_00190388");
// vec4_from_arg
int func_0016bba8(u8*, int, int) asm("func_0016bba8");
void func_0018a818(W260Col*, u8*, int) asm("func_0018a818");
/*TARGET 00112f88*/
int func_00112f88(W260Tg* t) asm("func_00112f88");
int func_00112f88(W260Tg* t)
{
    int best = 0;
    if (W260Valid(t)) {
        u8* o = t->obj;
        if (*(u32*)(o + 1416) & 2) {
            W260Col r;
            f32 bd = 0;
            W260Q tp = func_00190388(t);  // vec4_from_arg
            int c = 0;
            while ((c = func_0016bba8(o, 2, c)) != 0) {
                func_0018a818(&r, o, c);
                W260Q d;
                asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(&tp), "r"(&r.b), "r"(&d) : "memory");
                f32 ds = W260LenSq(d);
                if (!best || ds < bd) { bd = ds; best = c; }
            }
        }
    }
    return best;
}
}  // namespace n00112f88

// 001130b0 (was src/anon/batch_w2351_nsa.cpp)
namespace n001130b0 {
#define QCOPY2040(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V2040 {
    f32 x, y, z, w;
    V2040() {}
    V2040(const V2040& o) { QCOPY2040(this, &o); }
    V2040& operator=(const V2040& o) { if (this != &o) QCOPY2040(this, &o); return *this; }
    V2040 operator-(const V2040& b) const {
        V2040 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2040 operator+(const V2040& b) const {
        V2040 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 normalize() {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                     : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    V2040& operator*=(f32 k) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Q2040 { u8 pad0[12]; s32 f12; V2040 v; };
struct Info2040 { u8 b0; u8 b1; u16 h2; };
struct Res2040 { u8 pad[0x18]; u32 flag : 1; bool isFlag() { return flag; } };
struct Ent2040 { void** vt; };
struct Ctx2040 { u8 pad[8]; void* f8; };
typedef void (*EntFn2040)(Ent2040*, Res2040*);
s32 func_0018d940(Ctx2040*, Ent2040*) asm("func_0018d940");
Info2040* func_00112f88(Ent2040**) asm("func_00112f88");
void func_0018a818(Q2040*, Ent2040*, Info2040*) asm("func_0018a818");
f32 func_0018a970(Q2040*, V2040) asm("func_0018a970");
Res2040* func_0018db38(Ctx2040*, Ent2040*, u16, u8) asm("func_0018db38");
void func_0018ca10(Res2040*) asm("func_0018ca10");
void* func_0016ac80(void*, s32, V2040*, s32, s32) asm("func_0016ac80");
V2040* func_001dc648(void*) asm("func_001dc648");
V2040 func_0017d050(const V2040&) asm("func_0017d050");
void func_001c2c00(void*) asm("func_001c2c00");
/*TARGET 001130b0*/
// Moves pos toward the target the query found, then runs the entity's hit callback and,
// for id >= 0, spawns effect id at the new position facing dir.
s32 func_001130b0(V2040* pos, Ent2040** pe, Ctx2040* ctx, s32 id) asm("func_001130b0");
// Moves pos toward the target the query found, then runs the entity's hit callback and,
// for id >= 0, spawns effect id at the new position facing dir.
s32 func_001130b0(V2040* pos, Ent2040** pe, Ctx2040* ctx, s32 id) {
    s32 r = 0;
    Res2040* res = 0;
    Ent2040* e = *pe;
    if (func_0018d940(ctx, e) != 0) {
        Info2040* info = func_00112f88(pe);
        if (info != 0) {
            Q2040 q;
            V2040 p;
            V2040 dir;
            V2040* pp = &p;
            V2040* qv = &q.v;
            q.f12 = 0;
            func_0018a818(&q, e, info);
            dir = *qv - *pos;
            f32 d = func_0018a970(&q, *pos);
            dir.normalize();
            dir *= d;
            *pp = *pos + dir;
            pp->w = 1.0f;
            res = func_0018db38(ctx, e, info->h2, info->b1);
            if (res != 0 && !res->isFlag()) {
                r = 1;
                ((EntFn2040)e->vt[25])(e, res);
                if (id >= 0 && ctx->f8 != 0) {
                    void* v = func_0016ac80(ctx->f8, id, pp, 1, 10000);
                    if (v != 0) {
                        *func_001dc648(v) = func_0017d050(dir);
                        func_001c2c00(v);
                    }
                }
            }
        }
    }
    if (res) func_0018ca10(res);
    return r;
}
}  // namespace n001130b0

// 001132d8 (was src/anon/auto80_199_queue.cpp)
namespace n001132d8 {
/*TARGET 001132d8*/
void func_001132d8(u32 a0, u32 a1, u32 a2) asm("_Z13func_001132d8jjj");
void func_001132d8(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a1;
    u32 s1 = a0;
    u32 s2 = a2;
    u8 tmp[16];

    u32 vtbl = *(u32*)s0;
    u32 fn = *(u32*)(vtbl + 8);
    ((void (*)(void*))fn)(tmp);
    func_001130b0(tmp, s1, s0, s2);
}
}  // namespace n001132d8

// 00113338 (was src/anon/batch_w68.cpp)
namespace n00113338 {
typedef unsigned int u128 __attribute__((mode(TI)));
/* ---- 00113338 ---- */
void* func_001050d8(u32) asm("func_001050d8");
void func_0018d238(void*, u32, u32, u32, u32, s32, u32) asm("func_0018d238");
s32 func_001130b0(u128*, u32, void*, u32) asm("func_001130b0");
void func_0018f028(void*) asm("func_0018f028");
/*TARGET 00113338*/
s32 func_00113338(u32 a0, u128* a1, u32 a2, u32 a3, u32 a4, u32 a5) asm("func_00113338");
s32 func_00113338(u32 a0, u128* a1, u32 a2, u32 a3, u32 a4, u32 a5) {
    u128 tmp;
    void* o = func_001050d8(208);
    func_0018d238(o, a0, 0, a3, 0, -1, a4);
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&tmp), "r"(a1) : "$8", "memory");
    s32 r = func_001130b0(&tmp, a2, o, a5);
    func_0018f028(o);
    return r;
}
}  // namespace n00113338

// 001133f8 (was src/anon/tiny.cpp)
namespace n001133f8 {
/*TARGET 001133f8*/
void func_001133f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001133f8jjjj");
void func_001133f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t = *(u32*)((u32)a0 + (2940));
    t |= 0x1000u;
    *(u32*)((u32)a0 + (2940)) = t;
}
}  // namespace n001133f8

// 00113408 (was src/anon/batch_w1666.cpp)
namespace n00113408 {
/*TARGET 00113408*/
// 0x002be750: definition moved into src/anon/unit_002be020.cpp
void func_00113408(u8* p) asm("func_00113408");
// 0x002be750: definition moved into src/anon/unit_002be020.cpp
void func_00113408(u8* p) { *(u32*)(p + 2940) &= ~0x1000; }
}  // namespace n00113408

// 00113420 (was src/anon/batch_w1666.cpp)
namespace n00113420 {
/*TARGET 00113420*/
void func_00113420(u8* p) asm("func_00113420");
void func_00113420(u8* p) { *(u32*)(p + 2940) |= 0x20000; }
}  // namespace n00113420

// 00113438 (was src/anon/batch_w1667.cpp)
namespace n00113438 {
/*TARGET 00113438*/
void func_00113438(u8* p) asm("func_00113438");
void func_00113438(u8* p) { *(u32*)(p + 0xb7c) &= ~0x20000; }
}  // namespace n00113438

// 00113450 (was src/anon/tiny_auto80.cpp)
namespace n00113450 {
/*TARGET 00113450*/
// 00106108: moved to src/naka/libkn/memoryallocator.cpp

// 00106420: moved to src/naka/libkn/memoryallocator.cpp

void func_00113450(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00113450jjjj");
// 00106108: moved to src/naka/libkn/memoryallocator.cpp

// 00106420: moved to src/naka/libkn/memoryallocator.cpp

void func_00113450(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14, r15;
    r14 = *(u32*)((u32)r5 + (s32)(0));
    r15 = *(u32*)((u32)r14 + (s32)(28));
    r15 = (u32)(r15 | 0x0004u);
    *(u32*)((u32)r14 + (s32)(28)) = r15;
    *(u32*)((u32)r4 + (s32)(2896)) = r5;
    *(u32*)((u32)r4 + (s32)(2900)) = r6;
}
}  // namespace n00113450

// 00113470 (was src/anon/batch_w1878_nsa.cpp)
namespace n00113470 {
// ---- 00113470: static init/destroy for priority 0xffff (two constructors, three empty-dtor array loops).
struct W1878E { u8 v[16]; ~W1878E() {} };
struct W1878H { u8 hdr[16]; W1878E arr[32]; };
void func_0010b450(void*) asm("func_0010b450");
void func_00190128(void*) asm("func_00190128");
extern W1878H D_003a9040 asm("D_003a9040");
extern W1878E D_00341750[3] asm("D_00341750");
extern W1878E D_00341720[3] asm("D_00341720");
extern u8 D_003417b0[] asm("D_003417b0");
/*TARGET 00113470*/
void func_00113470(int a, int b) asm("_Z13func_00113470ii");
void func_00113470(int a, int b) {
    if (b == 0xffff && a == 1) func_0010b450(&D_003a9040);
    if (b == 0xffff && a == 1) func_00190128(D_003417b0);
    if (b == 0xffff && a == 0) {
        if (D_00341750) {
            W1878E* e = D_00341750 + 3;
            for (;;) { e->~W1878E(); if (e == D_00341750) break; --e; }
        }
    }
    if (b == 0xffff && a == 0) {
        if (D_00341720) {
            W1878E* e = D_00341720 + 3;
            for (;;) { e->~W1878E(); if (e == D_00341720) break; --e; }
        }
    }
    if (b == 0xffff && a == 0) {
        W1878H* h = &D_003a9040;
        if (h->arr) {
            W1878E* e = h->arr + 32;
            for (;;) { e->~W1878E(); if (e == h->arr) break; --e; }
        }
    }
}
}  // namespace n00113470

