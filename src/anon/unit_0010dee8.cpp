// Linked unit 0x0010dee8-0x0010ef48 (one namespace per old matched source; class methods in their own namespace).
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

// 0010dee8 (was src/anon/auto200_999.cpp)
namespace n0010dee8 {
/*TARGET 0010dee8*/
void func_0010dee8(u32 a0, u32 *a1, u32 *a2) asm("_Z13func_0010dee8jPjS_");
void func_0010dee8(u32 a0, u32 *a1, u32 *a2) {
    a2[0] = a1[0];
    a2[1] = a1[1];
    a2[2] = a1[2];
    a2[3] = a1[3];
    a2[4] = a1[4];
}
}  // namespace n0010dee8

// 0010df18 (was src/anon/batch_w318.cpp)
namespace n0010df18 {
struct A318;
struct T318;
typedef void (A318::*P318)(T318*, void*);
struct T318 { u32 a, b, c, d, e; };
struct A318 { u8 pad[2548]; T318 t; u8 pad2[2924-2568]; int idx; u8 pad3[12]; u32 fl; };
struct E318 { P318 f; } __attribute__((aligned(8)));
struct R318 { u32 pfn; int d; } __attribute__((aligned(8)));
extern E318 D_00345b28[] asm("D_00345b28");
typedef void (*F318)(void*, T318*, void*);
void func_00190128(void*) asm("func_00190128");
int func_00190140(void*) asm("func_00190140");
int func_00190680(void*, T318*) asm("func_00190680");
int func_001b58a8(void) asm("func_001b58a8");
int func_00112720(void*) asm("func_00112720");
/*TARGET 0010df18*/
// check_2924_lt14
void func_0010df18(A318* p) asm("func_0010df18");
// check_2924_lt14
void func_0010df18(A318* p) {
    T318* s = &p->t;
    T318 t = p->t;
    func_00190128(s);
    if (func_001b58a8()) {
        (p->*D_00345b28[11].f)(&t, s);
    } else if (func_00112720(p)) {  // check_2924_lt14
        (p->*D_00345b28[p->idx - 8].f)(&t, s);
    } else {
        int i = (*(int (**)(void*))(*(u32*)p + 152))(p);
        E318 ee = D_00345b28[i];
        R318& e = *(R318*)&ee;
        int d = e.d;
        char* q = (char*)p + (d >> 1);
        F318 fn;
        if ((u8)(d & 1)) fn = *(F318*)(((e.pfn >> 2) << 2) + *(u32*)q);
        else fn = (F318)e.pfn;
        fn(q, &t, s);
    }
    u32 ok = 0;
    if (func_00190140(s)) ok = p->t.a != 0;
    if (!(u8)ok) func_00190128(s);
    if (!func_00190680(s, &t)) p->fl |= 8;
}
}  // namespace n0010df18

// 0010e130 (was src/anon/batch_w2043.cpp)
namespace n0010e130 {
struct W2043a_Obj;
struct W2043a_Vq {
    f32 x, y, z, w;
    W2043a_Vq() {}
    W2043a_Vq(const W2043a_Vq& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W2043a_Vq& operator=(const W2043a_Vq& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct W2043a_Tgt { u8 pad[0x588]; u32 f588; };
struct W2043a_Hdl { W2043a_Tgt* p; u8 pad[0x1c]; };
struct W2043a_Vt { u8 pad[0x98]; s32 (*f98)(W2043a_Obj*); };
struct W2043a_Obj {
    W2043a_Vt* vt; u8 p0[0x9f4 - 4];
    W2043a_Hdl h;               // 9f4
    u8 p1[0xb60 - 0xa14];
    void* b60;
    u8 p2[0xb7c - 0xb64];
    s32 flags;           // b7c
    u8 b80[0x30];        // b80
    f32 fbb0pad[0];
    u8 bb0[0x1c];        // bb0
    f32 bcc;             // bcc
    u8 p4[0x20];
    f32 bf0;             // bf0
};
W2043a_Vq* func_0016c028(W2043a_Obj*) asm("func_0016c028");
void func_00190128(void*) asm("func_00190128");
s32 func_00190140(W2043a_Hdl*) asm("func_00190140");
W2043a_Vq func_00190388(W2043a_Hdl*) asm("func_00190388");
f32 func_001906f0(W2043a_Hdl*, W2043a_Vq*) asm("func_001906f0");
void func_00190878(W2043a_Hdl*, u32, s32) asm("func_00190878");
void func_0010b620(void*, W2043a_Vq*, W2043a_Vq*) asm("func_0010b620");
s32 func_001917c0(void) asm("func_001917c0");
f32 func_00114370(void*) asm("func_00114370");
s32 func_0010f8d0(W2043a_Obj*) asm("func_0010f8d0");
void func_0010df18(W2043a_Obj*) asm("func_0010df18");
s32 func_0010d188(W2043a_Obj*) asm("func_0010d188");
extern u32 D_00341708 asm("D_00341708");
s32 W2043_ctarget_0010e130(W2043a_Obj* o, u8 a1) asm("_Z16ctarget_0010e130jjjj");
/*TARGET 0010e130*/
s32 W2043_ctarget_0010e130(W2043a_Obj* o, u8 a1) asm("_Z16ctarget_0010e130jjjj");
s32 W2043_ctarget_0010e130(W2043a_Obj* o, u8 a1) {
    W2043a_Vq a = *func_0016c028(o);
    o->flags &= ~8;
    {
    W2043a_Hdl b;
    func_00190128(&b);
    func_00190878(&b, D_00341708, 0);
    W2043a_Vq c = func_00190388(&b);
    func_0010b620(o->b80, &c, &a);
    }
    f32 d = func_00114370(o->b60);
    switch (o->vt->f98(o)) {
    case 2: d *= 0.5f; break;
    case 3: case 5: d *= 2.0f; break;
    }
    if (!(o->flags & 0x20000) && d < *(f32*)((u8*)o + 0xbac)) o->flags |= 0x40;
    if (func_001917c0()) {
        if (a1 || (!func_0010f8d0(o) && !(o->flags & 0x10000) && func_0010d188(o))) func_0010df18(o);
        W2043a_Hdl* h = &o->h;
        s32 ok = 0;
        if (func_00190140(h)) ok = h->p != 0;
        if ((u8)ok && (h->p->f588 & 0x10)) {
            W2043a_Vq c = func_00190388(h);
            func_0010b620(o->bb0, &c, &a);
            c = a;
            o->bf0 = o->bcc - func_001906f0(h, &c);
        }
    } else {
        if (a1 || (!func_0010f8d0(o) && !(o->flags & 0x10000))) func_00190128(&o->h);
    }
    return (o->flags >> 3) & 1;
}
}  // namespace n0010e130

// 0010e368 (was src/anon/batch_wcx2.cpp)
namespace n0010e368 {
s32 func_001917c0(void) asm("func_001917c0");
// 0x001a9c20: definition moved into src/anon/unit_001a9130.cpp



// --------------------
// 0010e368: camera/look-direction update by state (aim at a point or follow the message direction, zoom level hysteresis)
// VU0 macro-mode vector helpers (hand-written asm in the original math library)
struct V10e368 {
    f32 x, y, z, w;
    V10e368() {}
    V10e368& operator=(const V10e368& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V10e368 operator-(const V10e368& b) const
    {
        V10e368 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V10e368 operator*(f32 k) const
    {
        V10e368 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    V10e368& operator+=(const V10e368& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    f32 dot(const V10e368& o) const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this), "r"(&o) : "$8");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct Msg10e368 { f32 x; u8 pad[12]; V10e368 dir; V10e368 up; };
struct St10e368 { s32 f0; u32 state; };
struct O10e368 {
    u8 pad0[12];
    St10e368* st;
    u8 pad1[1360 - 16];
    V10e368 fwd;
    u8 pad2[2912 - 1376];
    s32 f2912;
    u8 pad3[2928 - 2916];
    s32 point;
    u8 pad4[4];
    s32 level;
    u32 flags;
    Msg10e368 msg;
    u8 pad5[3072 - 2992];
    V10e368 dir;
};
extern V10e368 D_00341720[] asm("D_00341720");
void func_0010cac8(O10e368*, s32, f32) asm("func_0010cac8");
V10e368* f10e368_attach(O10e368*) asm("func_0016c028");
f32 func_00114328(s32, s32, s32, s32) asm("func_00114328");
f32 func_001142e0(s32, s32, s32, s32) asm("func_001142e0");
f32 func_0010e7e0(O10e368*, s32) asm("func_0010e7e0");
/*TARGET 0010e368*/
s32 func_0010e368(O10e368* o, Msg10e368* m) asm("func_0010e368");
s32 func_0010e368(O10e368* o, Msg10e368* m)
{
    if (!o->st) return 0;
    switch (o->st->state) {
    case 1:
        break;
    case 0:
        return 0;
    case 2:
        o->dir.x = o->dir.z = 0.0f;
        if (m->x < 0.0f) {
            o->dir.w = 0.0f;
            o->dir.y = -1.0f;
        } else {
            func_0010cac8(o, 3, 0.0f);
        }
        break;
    case 31:
    case 32: {
        s32 mode = func_001917c0();
        bool self = m == &o->msg;
        if (self && !(o->flags & 0x10)) {
            o->dir = D_00341720[o->point] - *f10e368_attach(o);
            o->dir.normalize();
        } else {
            o->dir = m->dir;
        }
        V10e368* d = &m->dir;
        if (func_00114328(o->f2912, o->level, mode, self) < d->w) {
            if (o->level < 2) o->level++;
        } else if (d->w < func_001142e0(o->f2912, o->level, mode, self)) {
            if (o->level > 0) o->level--;
        }
        f32 f = func_0010e7e0(o, o->level);
        o->dir.w = f;
        if (self && f == 0.0f) {
            if (o->flags & 0x10) {
                o->dir += o->fwd * 0.8f;
                o->dir.normalize();
                o->dir.w = func_0010e7e0(o, 1) * 0.2f;
                if (0.97f < o->fwd.dot(m->up)) o->flags &= ~0x10;
            } else {
                if (o->fwd.dot(m->up) <= 0.5f) o->flags |= 0x10;
            }
            o->flags &= ~0x40;
        } else {
            o->flags &= ~0x10;
        }
        break;
    }
    }
    return 1;
}
}  // namespace n0010e368

// 0010e6e0 (was src/anon/batch_w87.cpp)
namespace n0010e6e0 {
// 00109070: moved to src/anon/unit_001085a8.cpp

// ---- 0x10e6e0: probe at three heights; returns the agreeing result ----
s32 func_00184780(void*, s32, f32, f32, f32) asm("func_00184780");
/*TARGET 0010e6e0*/
s32 func_0010e6e0(u8* p, s32 a, f32 x, f32 y, f32 z) asm("func_0010e6e0");
s32 func_0010e6e0(u8* p, s32 a, f32 x, f32 y, f32 z) {
    if (*(s32*)(p + 2064) != 0) return 0;
    s32 r0 = func_00184780(p, a, *(f32*)(p + 1456) + x, y * 0.1f, z);
    if (r0 == func_00184780(p, a, *(f32*)(p + 1456) + x, y * 0.9f, z)) return r0;
    return func_00184780(p, a, *(f32*)(p + 1456) + x, y * 0.5f, z);
}
}  // namespace n0010e6e0

// 0010e7e0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0010e7e0 {
/*TARGET 0010e7e0*/
f32 func_0010e7e0(u8* a0, u32 a1) asm("_Z13func_0010e7e0Phj");
f32 func_0010e7e0(u8* a0, u32 a1) {  // float2_get_by_index
    switch (a1) {
    case 1:
        return *(f32*)(a0 + 0x110);
    case 2:
        return *(f32*)(a0 + 0x114);
    default:
        return 0.0f;
    }
}
}  // namespace n0010e7e0

// 0010e810 (was src/anon/batch_w3757.cpp)
namespace n0010e810 {
struct Fr10e810;
// VU0 macro-mode vector helpers (hand-written asm in the original math library)
struct V10e810 {
    f32 x, y, z, w;
    V10e810() {}
    V10e810& operator=(const V10e810& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V10e810 operator-(const V10e810& b) const
    {
        V10e810 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V10e810 operator*(f32 k) const
    {
        V10e810 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    V10e810& operator+=(const V10e810& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    V10e810& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    V10e810 operator+(const V10e810& b) const
    {
        V10e810 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V10e810 cross(const V10e810& b) const
    {
        V10e810 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 dot(const V10e810& o) const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this), "r"(&o) : "$8");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct VecSet10e810 { f32 x; u8 pad[28]; V10e810 dir; };
struct Seg10e810 { V10e810 p, q; };
struct Fr10e810Vt { void* f[38]; s32 (*kind)(Fr10e810*); };
struct Who10e810;
struct Fr10e810 {
    Fr10e810Vt* vt;
    u8 pad0[280 - 4];
    f32 reach;
    u8 pad1[1360 - 284];
    V10e810 fwd;
    u8 pad2[1456 - 1376];
    f32 f1456;
    u8 pad3[1520 - 1460];
    u16 h1520;
    u8 pad4[1532 - 1522];
    f32 f1532;
    u64 bits;
    s32 f1544;
    u8 pad5[1584 - 1548];
    V10e810 up;
    u8 pad6[2064 - 1600];
    s32 f2064;
    u8 pad7[2912 - 2068];
    Who10e810* who;
    u8 pad8[2928 - 2916];
    s32 point;
    u8 pad9[4];
    s32 level;
    u32 flags;
    VecSet10e810 own;
    u8 pad10[3072 - 2992];
    V10e810 dir;
    u8 pad11[3288 - 3088];
    s32 f3288;
};
extern V10e810 D_00341720[] asm("D_00341720");
extern Fr10e810* D_00341708 asm("D_00341708");
extern u8 D_003a9040 asm("D_003a9040");
s32 f10e810_update(Fr10e810*, const VecSet10e810*) asm("func_0010e368");
s32 func_001917c0(void) asm("func_001917c0");
V10e810* f10e810_attach(Fr10e810*) asm("func_0016c028");
f32 f10e810_hi(Who10e810*, s32, s32, s32) asm("func_00114328");
f32 f10e810_lo(Who10e810*, s32, s32, s32) asm("func_001142e0");
f32 f10e810_dist(Fr10e810*, s32) asm("func_0010e7e0");
s32 func_0010e6e0(Fr10e810*, V10e810*, f32, f32, f32) asm("func_0010e6e0");
s32 func_00143f28(u16, s32) asm("func_00143f28");
s32 func_00143ae0(Seg10e810*, V10e810*, V10e810*, s32) asm("func_00143ae0");
void f10e810_warp(Fr10e810*, s32, f32) asm("func_0010cac8");
void f10e810_followMove(Fr10e810* o, const VecSet10e810* vs) asm("_ZN2kn6Friend10followMoveEPKNS_6VecSetE");
/*TARGET 0010e810*/
void f10e810_followMove(Fr10e810* o, const VecSet10e810* vs) asm("_ZN2kn6Friend10followMoveEPKNS_6VecSetE");
void f10e810_followMove(Fr10e810* o, const VecSet10e810* vs)
{
    if (o->flags & 0x10000000) return;
    if (f10e810_update(o, vs)) return;
    s32 mode = func_001917c0();
    bool self = vs == &o->own;
    if (self && !(o->flags & 0x10)) {
        o->dir = D_00341720[o->point] - *f10e810_attach(o);
        o->dir.y = 0.0f;
        o->dir.normalize();
    } else {
        o->dir = vs->dir;
    }
    const V10e810* d = &vs->dir;
    if (o->level != 3) {
        f32 hi = f10e810_hi(o->who, o->level, mode, self);
        f32 lo = f10e810_lo(o->who, o->level, mode, self);
        if (mode && self && o->vt->kind(o) == 3) {
            hi += hi;
            lo += lo;
        }
        if (hi < d->w) {
            if (o->level < 2) o->level++;
        } else if (d->w < lo) {
            if (o->level > 0) o->level--;
        }
    }
    f32 f = f10e810_dist(o, o->level);
    o->dir.w = f;
    if (self && f == 0.0f) {
        if (o->flags & 0x10) {
            o->dir += o->fwd * 0.4f;
            o->dir.normalize();
            o->dir.w = f10e810_dist(o, 1);
            if (0.97f < o->fwd.dot(*d)) o->flags &= ~0x10;
        } else {
            if (D_003a9040 && o->fwd.dot(*d) < 0.5f) o->flags |= 0x10;
        }
        o->flags &= ~0x40;
    } else {
        o->flags &= ~0x10;
    }
    f32 reach = o->reach;
    f32 limit = reach;
    if (self && 0.0f < vs->x) limit = reach + vs->x;
    switch (func_0010e6e0(o, &o->dir, o->dir.w, reach, limit)) {
    case 0:
    case 2:
        break;
    case 1: {
        if (!o->f1544 && o->h1520 != 0xffff && func_00143f28(o->h1520, 0) == 4) break;
        V10e810 p, a, b;
        Seg10e810 s;
        V10e810 out;
        p = *f10e810_attach(o);
        p.y -= o->f1532 * 0.4f;
        { register f32 w asm("$f1") = *(f32*)&o->dir.w; f32 f = *(f32*)&o->f1456; a = o->dir * (f + w); }
        a.w = 1.0f;
        f32 len = a.normalize();
        b = o->up.cross(a);
        b.normalize();
        a = b.cross(o->up);
        a.normalize();
        a *= len;
        a = p + a;
        a.w = 1.0f;
        s.p = p;
        s.q = a;
        if (func_00143ae0(&s, &b, &out, (s32)(o->bits >> 3) & 0xf)) {
            p = *f10e810_attach(o);
            f10e810_warp(o, 3, reach);
        }
        break;
    }
    default:
        o->dir.w = 0.0f;
        o->f3288++;
        break;
    }
    if (d->w < 8.0f && vs->x < -250.0f) {
        o->dir.w = 0.0f;
        o->f3288++;
    }
    if (!(o->flags & 0x20000) && o->f2064 && D_00341708 && !D_00341708->f2064 && 80.0f < o->own.x) {
        f10e810_warp(o, 3, reach);
    }
}
}  // namespace n0010e810

// 0010eed8 (was src/anon/tiny.cpp)
namespace n0010eed8 {
/*TARGET 0010eed8*/
void func_0010eed8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0010eed8jjjj");
void func_0010eed8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a3;
    *(u32*)((u32)a0 + (3168)) = a1;
    *(u32*)((u32)a0 + (3172)) = a2;
}
}  // namespace n0010eed8

// 0010eee8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0010eee8 {
u32 func_0010eed8(...) asm("func_0010eed8");
/*TARGET 0010eee8*/
void func_0010eee8(u8* a0) asm("_Z13func_0010eee8Ph");
void func_0010eee8(u8* a0) {
    s32 t6 = 2;
    u32* t7 = (u32*)(a0 + 0xc54);
    do {
        *t7 = 0;
        t6 -= 1;
        t7 += 1;
    } while (t6 >= 0);
    func_0010eed8((u32)a0, 0, 0);
}
}  // namespace n0010eee8

// 0010ef28 (was src/anon/auto200_999.cpp)
namespace n0010ef28 {
/*TARGET 0010ef28*/
// 0010a800: moved to src/anon/unit_00109c30.cpp

void func_0010ef28(u32 a0, u32 a1) asm("_Z13func_0010ef28jj");
// 0010a800: moved to src/anon/unit_00109c30.cpp

void func_0010ef28(u32 a0, u32 a1) {
    u32 p = a0 + 8;
    *(u32 *)(p + 3156) = *(u32 *)(p + 3152);
    p = a0 + 4;
    *(u32 *)(p + 3156) = *(u32 *)(p + 3152);
    *(u32 *)(a0 + 3156) = a1;
}
}  // namespace n0010ef28

