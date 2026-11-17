// Linked unit 0x0010fea0-0x001109c8 (one namespace per old matched source; class methods in their own namespace).
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

// 0010fea0 (was src/anon/batch_w42.cpp)
namespace n0010fea0 {
// 00109360: moved to src/anon/unit_001085a8.cpp

// 0010fea0: common value of three slots, or 0
s32 func_00112720(void*) asm("func_00112720");
/*TARGET 0010fea0*/
// check_2924_lt14
s32 func_0010fea0(u8* p) asm("func_0010fea0");
// check_2924_lt14
s32 func_0010fea0(u8* p)
{
    if (func_00112720(p)) return 0;
    s32* a = (s32*)(p + 3156);
    for (s32 i = 1; i < 3; i++) {
        if (a[0] != a[i]) return 0;
    }
    return a[0];
}
}  // namespace n0010fea0

// 0010ff08 (was src/anon/batch_w3903_nsa.cpp)
namespace n0010ff08 {
struct Ent10ff08;
struct Tgt10ff08;
struct Who10ff08;
typedef s32 (Who10ff08::*Pick10ff08)(Ent10ff08*, Tgt10ff08*, s32*, s32);
struct Tgt10ff08;
void func_00190128(Tgt10ff08*) asm("func_00190128");
struct Tgt10ff08 {
    s32 f0, f4, f8, f12, f16;
    Tgt10ff08() { func_00190128(this); }
};
struct V10ff08 {
    f32 x, y, z, w;
    V10ff08() {}
    V10ff08(const V10ff08& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct Pt10ff08 { f32 x, y, z, w, r; };
struct Q10ff08 { u8 pad[8]; s32 n; };
struct Other10ff08 { u8 pad[384]; s32 level; };
struct Who10ff08 { s32 dummy; };
struct Ent10ff08 {
    u32 flags;
    Pick10ff08 pick;
    u8 pad[4];
    Q10ff08* q;
    u8 pad2[8];
    s32 slot;
    u8 pad3[4];
};
struct Cand10ff08 {
    Ent10ff08* e;
    Tgt10ff08 t;
    s32 score;
};
struct Cam10ff08 {
    u8 pad0[1164];
    Other10ff08* other;
    u8 pad1[2548 - 1168];
    Tgt10ff08 tgt;
    u8 pad1b[2912 - 2568];
    Who10ff08* who;
    u8 pad2[2940 - 2916];
    u32 flags;
    u8 pad3[3072 - 2944];
    V10ff08 dir;
    u8 pad3b[3168 - 3088];
    Ent10ff08* cur;
    s32 score;
    u8 pad4[3304 - 3176];
    s32 count;
};
extern s8 D_003a9618 asm("D_003a9618");
extern Cand10ff08 D_003a9620[32] asm("D_003a9620");
s32 func_0010fb10(Cam10ff08*) asm("func_0010fb10");
s32 func_0010f8d0(Cam10ff08*) asm("func_0010f8d0");
s32 func_001137e0(Who10ff08*) asm("func_001137e0");
Ent10ff08* func_001137e8(Who10ff08*) asm("func_001137e8");
s32 func_001a1de0(Other10ff08*) asm("func_001a1de0");
s32 func_0010f648(s32) asm("func_0010f648");
s32 func_0010f600(Cam10ff08*) asm("func_0010f600");
f32 func_0010f660(void) asm("func_0010f660");
f32 func_001142b0(Who10ff08*) asm("func_001142b0");
s32 func_001137f0(Who10ff08*) asm("func_001137f0");
Pt10ff08* func_00113808(Who10ff08*, s32) asm("func_00113808");
void func_0010c9f8(Cam10ff08*, f32, f32, f32, f32, f32) asm("func_0010c9f8");
void func_0010ef28(Cam10ff08*, Ent10ff08*) asm("func_0010ef28");
void func_0010eed8(Cam10ff08*, Ent10ff08*, s32) asm("func_0010eed8");
void func_00110630(Cam10ff08*) asm("func_00110630");
Ent10ff08* func_0010fea0(Cam10ff08*) asm("func_0010fea0");
u8* func_00112570(Cam10ff08*) asm("func_00112570");
void func_0016b010(Cam10ff08*, V10ff08*) asm("func_0016b010");
/*TARGET 0010ff08*/
// func_0010ff08: camera target choice. Collects candidate entities whose pick callback accepts them
// (pass 0 skips kind 2 and entities refused by func_001a1de0, pass 1 takes only kind 2), then picks one at random.
void func_0010ff08(Cam10ff08* c) asm("func_0010ff08");
// func_0010ff08: camera target choice. Collects candidate entities whose pick callback accepts them
// (pass 0 skips kind 2 and entities refused by func_001a1de0, pass 1 takes only kind 2), then picks one at random.
void func_0010ff08(Cam10ff08* c)
{
    if (func_0010fb10(c)) return;
    if (func_0010f8d0(c)) return;
    s32 n = func_001137e0(c->who);
    Ent10ff08* ents = func_001137e8(c->who);
    if (!D_003a9618) {
        Cand10ff08* p = D_003a9620;
        for (s32 k = 31; k != -1; k--) {
            func_00190128(&p->t);
            p++;
        }
        D_003a9618 = 1;
    }
    Tgt10ff08 t;
    V10ff08* dp;
    s32 score;
    if (c->cur) {
        if (c->cur->flags & 0x200) {
            c->flags |= 4;
            t = c->tgt;
            score = c->score;
            if ((c->who->*c->cur->pick)(c->cur, &t, &score, 1)) {
                (c->who->*c->cur->pick)(c->cur, &t, &score, 0);
                return;
            }
        }
    }
    if (c->cur && (c->cur->flags & 2) && func_0010f600(c) && func_0010f660() < func_001142b0(c->who)) {
        s32 k = func_001137f0(c->who);
        if (k > 0) {
            Pt10ff08* v = func_00113808(c->who, func_0010f648(k));
            func_0010c9f8(c, v->x, v->y, v->z, v->w, v->r);
            c->count = 0;
            func_0010eed8(c, 0, 0);
            return;
        }
    }
    if (!(c->flags & 0x800) && c->count >= 2) {
        func_00110630(c);
        c->count = 0;
        func_0010eed8(c, 0, 0);
        return;
    }
    Ent10ff08* prev;
    s32 refused = 0;
    c->flags &= ~4;
    Cand10ff08* pick = 0;
    s32 pass = 0;
    prev = func_0010fea0(c);
    do {
        s32 cnt = 0;
        for (s32 i = 0; i < n; i++) {
            if (!ents[i].pick) continue;
            u8 kind;
            if (ents[i].slot == -1) kind = 0;
            else kind = func_00112570(c)[ents[i].slot + 1];
            bool skip = false;
            if (!pass) {
                if (kind == 2) {
                    skip = true;
                } else if (ents[i].q && ents[i].q->n > 0) {
                    if (c->other) skip = func_001a1de0(c->other) != 0;
                    if (kind == 1 && c->other && c->other->level < ents[i].q->n) skip = true;
                }
            } else {
                skip = kind != 2;
            }
            if (skip) continue;
            func_00190128(&t);
            if ((c->who->*ents[i].pick)(&ents[i], &t, &score, 1) && cnt < 32) {
                D_003a9620[cnt].e = &ents[i];
                D_003a9620[cnt].t = t;
                D_003a9620[cnt].score = score;
                cnt++;
            }
        }
        asm("" :: "r"(cnt)); // allocation tie: one more use of cnt gives it s5 before ents
        if (cnt > 0) {
            pick = &D_003a9620[func_0010f648(cnt)];
            if (pick->e == prev) {
                pick = 0;
                refused = 1;
            }
        }
        if (pick) goto found;
        pass++;
    } while (refused && pass < 2);
    dp = &c->dir;
    func_00110630(c);
    c->dir.w = 0.0f;
    c->count = 0;
    func_0010eed8(c, 0, 0);
    {
        V10ff08 d = *dp;
        func_0016b010(c, &d);
    }
    return;
found:
    (c->who->*pick->e->pick)(pick->e, &pick->t, &pick->score, 0);
    u32 f = pick->e->flags & 1;
    if (f == 0) {
        func_0010ef28(c, pick->e);
        c->count++;
    } else {
        c->count = 0;
    }
    func_0010eed8(c, pick->e, pick->score);
}
}  // namespace n0010ff08

// 00110500 (was src/anon/batch_w94.cpp)
namespace n00110500 {
void func_0010e810(u8*, u8*) asm("func_0010e810");
f32 func_0010e7e0(u8*, s32) asm("func_0010e7e0");
// float2_get_by_index
extern u8* D_00341708 asm("D_00341708");
static inline f32 vlen(void* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\t"
                 "vaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(v) : "$8");
    return r;
}
/*TARGET 00110500*/
void func_00110500(u8* p) asm("func_00110500");
void func_00110500(u8* p) {
    func_0010e810(p, p + 2944);
    switch (*(s32*)(p + 2924)) {
    case 12:
    case 15:
    case 16:
        if (func_0010e7e0(p, 1) < *(f32*)(p + 3084)) {  // float2_get_by_index
            f32 l = vlen(D_00341708 + 0x860);
            if (*(f32*)(p + 3084) < l) *(f32*)(p + 3084) = l + 2.0f;
        }
        break;
    case 13:
        if (func_0010e7e0(p, 1) < *(f32*)(p + 3084)) {  // float2_get_by_index
            f32 l = vlen(D_00341708 + 0x860);
            if (*(f32*)(p + 3084) < l) *(f32*)(p + 3084) = l;
        }
        break;
    }
}
}  // namespace n00110500

// 00110618 (was src/naka/libkn/friend.cpp)
namespace kn { // method 00110618
extern void Friend_followMove(void*, void const*) asm("_ZN2kn6Friend10followMoveEPKNS_6VecSetE");
class Friend;
/*TARGET 00110618*/
void Friend::followEnemy() {
    Friend_followMove(this, reinterpret_cast<u8 const*>(this) + 2992u);
}
}  // kn

// 00110630 (was src/anon/auto80_199_queue.cpp)
namespace n00110630 {
u32 func_0010cc80(u8* a0) asm("_Z13func_0010cc80Ph");
/*TARGET 00110630*/
/*AMBIG*/ void func_00110630(u8* a0);
void func_00110630(u8* a0) {
    u8* s0 = a0;
    u32 t6 = *(u32*)(s0 + 2940);

    if ((t6 & 0x1000) == 0) {
        if (func_0010cc80(s0) != 0) {
            func_00110618(s0);
            return;
        }
        t6 = *(u32*)(s0 + 2940);
    }

    if ((t6 & 0x20000) != 0) {
        return;
    }

    func_00110500(s0);
}
}  // namespace n00110630

// 001106a0 (was src/anon/batch_w2352.cpp)
namespace n001106a0 {
/* VU0 macro-mode vector helpers (hand-written asm in the original math library). */
struct V6a0 {
    f32 x, y, z, w;
    V6a0() {}
    V6a0& operator=(const V6a0& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V6a0 operator+(const V6a0& b) const
    {
        V6a0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V6a0 operator*(f32 k) const
    {
        V6a0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    V6a0& operator+=(const V6a0& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    void zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct St6a0 { s32 f0; u32 state; };
struct O6a0 {
    u8 pad0[12];
    St6a0* st;
    u8 pad1[2940 - 16];
    u32 flags;          /* 2940 */
    u8 pad2[3072 - 2944];
    V6a0 dir;           /* 3072, w = zoom value */
    u8 pad3[3184 - 3088];
    V6a0 hist[6];       /* 3184: ring of recent directions */
    s32 hist_pos;       /* 3280 */
};
f32 func_0010e7e0(O6a0*, s32) asm("func_0010e7e0");
/*TARGET 001106a0*/
/* 001106a0: smooth the look direction over the last six frames, then snap the zoom value (dir.w) to a level. */
void func_001106a0(O6a0* o) asm("func_001106a0");
/* 001106a0: smooth the look direction over the last six frames, then snap the zoom value (dir.w) to a level. */
void func_001106a0(O6a0* o)
{
    V6a0 v;
    s32 i;
    if (o->st && o->st->state == 2) return;
    if (o->flags & 0x10) v.zero();
    else v = o->dir * o->dir.w;
    if (o->hist_pos < 0) {
        for (i = 0; i < 5; i++) o->hist[i] = v;
        o->hist_pos = 5;
    }
    o->hist[o->hist_pos] = v;
    if (++o->hist_pos >= 6) o->hist_pos = 0;
    v.zero();
    for (i = 0; i < 6; i++) v += o->hist[i];
    v.w = v.normalize() / 6.0f;
    o->dir = (o->dir + v) * 0.5f;
    {
        f32 a = func_0010e7e0(o, 1);
        f32 b = func_0010e7e0(o, 2);
        if (o->dir.w < b) {
            if (o->dir.w < a * 0.5f) o->dir.w = 0.0f;
            else if (o->dir.w < (a + b) * 0.5f) o->dir.w = a;
            else o->dir.w = b;
        }
    }
    if (o->flags & 0x10) o->dir.w = func_0010e7e0(o, 1);
}
}  // namespace n001106a0

// 001108f0 (was gap, never written)
namespace n001108f0 {
struct C; struct CVt { void* f0; void* f4; void* f8; void (*f12)(C*); };
struct C { CVt* vt; };
void func_0017e030(u8*, u8*) asm("func_0017e030");
s32 func_00112d28(u32) asm("func_00112d28");
void func_001108f0(u8* p, u8* m) asm("func_001108f0");
void func_001108f0(u8* p, u8* m) {
    C* c = *(C**)(p + 2912);
    c->vt->f12(c);
    func_0017e030(p, m);
    if (*(u32*)(m + 16) && func_00112d28(*(u32*)(m + 16))) *(u32*)(p + 3308) = *(u32*)(m + 16);
}
}

// 00110960 (was src/anon/auto80_199_queue.cpp)
namespace n00110960 {
/*TARGET 00110960*/
void func_00110960(u8* a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00110960Phjjj");
void func_00110960(u8* a0, u32 a1, u32 a2, u32 a3) {
    u8* s0 = a0;
    u32 s3 = a1;
    u32 s1 = a2;
    u32 s2 = a3;

    u32 p = *(u32*)(s0 + 2912);
    u32 vtbl = *(u32*)p;
    u32 fn = *(u32*)(vtbl + 16);
    ((void (*)(u32))fn)(p);

    func_00177760(s0, s3, s1, s2);
}
}  // namespace n00110960

