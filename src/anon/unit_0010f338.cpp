// Linked unit 0x0010f338-0x0010fb10 (one namespace per old matched source; class methods in their own namespace).
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

// 0010f338 (was src/anon/batch_w1664.cpp)
namespace n0010f338 {
/*TARGET 0010f338*/
f32 func_0010f338(u8* p) asm("func_0010f338");
f32 func_0010f338(u8* p) { return *(f32*)(p + 3056); }
}  // namespace n0010f338

// 0010f340 (was src/anon/auto200_999_queue.cpp)
namespace n0010f340 {
/*TARGET 0010f340*/
// 00108c00: moved to src/anon/unit_001085a8.cpp

u32 func_0010f340(u32 a0, u32 a1, u32 a2, f32 a3) asm("_Z13func_0010f340jjjf");
// 00108c00: moved to src/anon/unit_001085a8.cpp

u32 func_0010f340(u32 a0, u32 a1, u32 a2, f32 a3) {
    (void)a0;
    u32 flags = *(u32*)(a2 + 12);

    if ((flags & 1u) == 0) {
        f32 f1 = *(f32*)(a1 + 44);
        if (*(f32*)(a2 + 20) + a3 < f1) {
            return 0;
        }
        if (f1 < (*(f32*)(a2 + 16) - a3)) {
            return 0;
        }
    }

    if ((flags & 2u) == 0) {
        u32 ok = 1;
        if ((flags & 8u) != 0) {
            f32 f1 = *(f32*)(a1 + 44);
            if (*(f32*)(a2 + 48) + a3 < f1) goto clear_ok;
            if (f1 < (*(f32*)(a2 + 44) - a3)) goto clear_ok;
            goto after_ok_check;
clear_ok:
            ok = 0;
after_ok_check:
            ;
        }

        if (ok != 0) {
            f32 f1 = *(f32*)(a1 + 0);
            if (f1 < (-*(f32*)(a2 + 28) - a3)) {
                return 0;
            }
            if ((a3 - *(f32*)(a2 + 24)) < f1) {
                return 0;
            }
        }
    }

    {
        f32 f1 = *(f32*)(a1 + 44);
        if (!(f1 < *(f32*)(a2 + 52))) {
            return 1;
        }
        f32 v = fabsf(*(f32*)(a1 + 0));  // fabsf
        if (*(f32*)(a2 + 56) < v) {
            return 0;
        }
    }
    return 1;
}
}  // namespace n0010f340

// 0010f448 (was src/anon/batch_w3839_nsa.cpp)
namespace n0010f448 {
// w3839: 0010f448 and 00270c70 (both need -fno-strict-aliasing for 00270c70; 0010f448 matches either way).
struct QWf44 { f32 x, y, z, w;
    QWf44() {}
    QWf44(const QWf44& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
static inline f32 Dotf44(const QWf44& a, const QWf44& b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
struct Kf44 { s32 i0; s32 i4; };
struct Tf44 { s32 i0; s32 i4; s32 i8; u32 flags; };
struct Hf44 { s32 i0; s32 i4; s32 i8; };
struct Of44 {
    u8 p0[12]; Kf44* k; u8 p1[352 - 16]; u32 f160; u8 p2[1164 - 356]; Hf44* h;
    u8 p3[1360 - 1168]; QWf44 v550; u8 p4[2940 - 1376]; u32 fb7c; u8 p5[2992 - 2944]; QWf44 vbb0;
    u8 p6[3024 - 3008]; QWf44 vbd0; u8 p7[3056 - 3040]; f32 fbf0;
};
struct Af44 { u32 flags; s32 i4; s32 i8; s32 ic; Tf44* t; s32 i14; s32 i18; s32 i1c; };
u8* getFSR_f44(Of44*) asm("_ZN2kn6Friend16getFriendSaveRamEv");
s32 ct_10f7b0_f44(Of44*, s32, s32) asm("_Z26kn__Friend__equipedAbilityjjjj");
s32 uc_1a1de0_f44(Hf44*) asm("_Z21YS__SHEET__is_mpdrivejjjj");
s32 func_0010cc80(Of44*) asm("func_0010cc80");
s32 func_0010f340(Of44*, QWf44*, Tf44*, f32) asm("func_0010f340");
/*TARGET 0010f448*/
// Checks whether an action entry may be used now (party member, flags, save state, target, facing).
// The ==3 return shares its block with the failed ctarget call (goto zero) so if-conversion keeps it,
// and the function ends on return 1, which makes cross-jumping keep that early return-0 block.
s32 func_0010f448(Of44* o, Af44* a, u8 c1, u8 c2) asm("func_0010f448");
// Checks whether an action entry may be used now (party member, flags, save state, target, facing).
// The ==3 return shares its block with the failed ctarget call (goto zero) so if-conversion keeps it,
// and the function ends on return 1, which makes cross-jumping keep that early return-0 block.
s32 func_0010f448(Of44* o, Af44* a, u8 c1, u8 c2) {
    if (c1) {
        Kf44* k = o->k;
        if (!k) return 0;
        if (k->i4 != 0 && k->i4 != 31) return 0;
    }
    if (c2 && !(o->f160 & 4)) return 0;
    if (a->i14) {
        if (a->i1c == -1) return 0;
        if ((getFSR_f44(o) + a->i1c)[1] == 3) { zero: return 0; }
        if (!ct_10f7b0_f44(o, a->i14, a->i18)) goto zero;
    }
    if (a->t) {
        if (o->h && a->t->i8 > 0) {
            if (!(o->fb7c & 0x20)) return 0;
            if (uc_1a1de0_f44(o->h)) return 0;
        }
        if (a->flags & 2) {
            if (!func_0010cc80(o)) return 0;
            f32 f = o->fbf0;
            if (!func_0010f340(o, &o->vbb0, a->t, f)) return 0;
            if (!(a->t->flags & 0x10)) {
                QWf44 v(o->v550);
                v.y = 0.0f;
                if (Dotf44(v, o->vbd0) < v.y) return 0;
            }
        }
    } else if (a->flags & 2) return 0;
    return 1;
}
}  // namespace n0010f448

// 0010f600 (was src/anon/batch_w34.cpp)
namespace n0010f600 {
s32 func_0010cc80(void*) asm("func_0010cc80");
/*TARGET 0010f600*/
// Selects the current id; falls back to a saved slot when the id is unknown.
// 00103500: moved to src/common/unit_001031b0.cpp

s32 func_0010f600(u8* p) asm("func_0010f600");
// Selects the current id; falls back to a saved slot when the id is unknown.
// 00103500: moved to src/common/unit_001031b0.cpp

s32 func_0010f600(u8* p) {
    u32* q = *(u32**)(p + 12);
    if (q == 0) return 0;
    if (q[1] != 0) return 0;
    if (!(*(u32*)(p + 352) & 4)) return 0;
    return func_0010cc80(p) != 0;
}
}  // namespace n0010f600

// 0010f648 (was src/anon/tiny.cpp)
namespace n0010f648 {
void func_001064a8(void*) asm("_Z13func_001064a8Pv");
/*TARGET 0010f648*/
void func_0010f648(BD_VALUE* bd) asm("_Z13func_0010f648P8BD_VALUE");
void func_0010f648(BD_VALUE* bd) { func_001064a8(bd); }
}  // namespace n0010f648

// 0010f660 (was src/anon/batch_w215.cpp)
namespace n0010f660 {
extern u32 func_001064a8(u32) asm("func_001064a8");
/*TARGET 0010f660*/
// int_to_float_scaled

float func_0010f660() asm("func_0010f660");
// int_to_float_scaled

float func_0010f660() { return (float)func_001064a8(20001) * 0.00005f; }
}  // namespace n0010f660

// 0010f6b8 (was src/anon/batch_w11.cpp)
namespace n0010f6b8 {
struct HasF4 { s32 limit; s32 base; };
struct P10f6b8 { u8 pad[1164]; HasF4* lim; };
/*TARGET 0010f6b8*/
// Is base*scale over the limit?
s32 func_0010f6b8(P10f6b8* p, f32 scale) asm("func_0010f6b8");
// Is base*scale over the limit?
s32 func_0010f6b8(P10f6b8* p, f32 scale) {  // count_reached_threshold
    HasF4* l = p->lim;
    if (l != 0) {
        s32 n = (s32)((f32)l->base * scale);
        if (l->limit < n) return 1;
    }
    return 0;
}
}  // namespace n0010f6b8

// 0010f6f8 (was src/anon/batch_w64.cpp)
namespace n0010f6f8 {
/*TARGET 0010f6f8*/
// Returns the index of the first of 19 table entries the check rejects (0 if none).
// 00105f00: moved to src/common/world.cpp

// ---------------------------------------------------------------------------
s32 func_0010f6f8(u8* p, f32 f) asm("func_0010f6f8");
// Returns the index of the first of 19 table entries the check rejects (0 if none).
// 00105f00: moved to src/common/world.cpp

// ---------------------------------------------------------------------------
s32 func_0010f6f8(u8* p, f32 f) {  // count_reached_threshold_b
    if (*(u32*)(p + 2040) & 4) return 0;
    u8* q = *(u8**)(p + 1164);
    if (q) {
        s32 lim = (s32)((f32)*(s32*)(q + 388) * f);
        if (*(s32*)(q + 384) < lim) return 1;
    }
    return 0;
}
}  // namespace n0010f6f8

// 0010f748 (was src/anon/batch_w43.cpp)
namespace n0010f748 {
u8* func_0016a070(void) asm("func_0016a070");
s32 func_001a35f8(u32, u8*) asm("func_001a35f8");
/*TARGET 0010f748*/
s32 kn__Friend__canItemAction(u8* p, u32 b) asm("kn__Friend__canItemAction");
s32 kn__Friend__canItemAction(u8* p, u32 b) {
    u8* q = *(u8**)(p + 12);
    if (!q) return 0;
    s32 t = *(s32*)(q + 4);
    if (t != 0 && t != 31) return 0;
    if (!(*(u32*)(p + 352) & 4)) return 0;
    return func_001a35f8(b, func_0016a070()) > 0;
}
}  // namespace n0010f748

// 0010f7b0 (was src/anon/batch_w76.cpp)
namespace n0010f7b0 {
s32 func_00114620(u32) asm("func_00114620");
u32 func_0016a070(u32) asm("func_0016a070");
s32 func_001a35f8(s32, u32) asm("func_001a35f8");
u8* func_001058e8(void) asm("func_001058e8");
u8* YS__SAVERAM_BATTLE__get_partram(u8*, u32) asm("YS__SAVERAM_BATTLE__get_partram");
struct Entry { u16 id : 15; u16 on : 1; };
u32 kn__Friend__equipedAbility(u32, u32, s32, u32) asm("_Z26kn__Friend__equipedAbilityjjjj");
/*TARGET 0010f7b0*/
u32 kn__Friend__equipedAbility(u32 a, u32 b, s32 id, u32 d) asm("_Z26kn__Friend__equipedAbilityjjjj");
u32 kn__Friend__equipedAbility(u32 a, u32 b, s32 id, u32 d)
{
    if (id < 0) id = func_00114620(b);
    if (id == 0) return 0;
    if (func_001a35f8(id, func_0016a070(a)) <= 0) return 0;
    u8* base = func_001058e8() + 9456;
    u8* r = YS__SAVERAM_BATTLE__get_partram(base, func_0016a070(a));
    u16 key = id;
    Entry* p = (Entry*)(r + 84);
    for (s32 i = 0; i < 80; i++) {
        Entry e = *p++;
        u32 on = e.on;
        if (e.id == key && on) return 1;
    }
    return 0;
}
}  // namespace n0010f7b0

// 0010f880 (was src/anon/tiny_auto80_queue.cpp)
namespace n0010f880 {
f32 func_001065a8(u32,u32,u32,u32,u32,u32,u32,u32) asm("_Z13func_001065a8jjjjjjjj");
/*TARGET 0010f880*/
void func_0010f880(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0010f880jjjjjjjj");
void func_0010f880(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a0;
    f32 f0 = func_001065a8(a0, a1, a2, a3, a4, a5, a6, a7);
    *(f32*)((u32)s0 + (s32)(3284)) = f0;
}
}  // namespace n0010f880

// 0010f8a8 (was src/anon/tiny_more.cpp)
namespace n0010f8a8 {
/*TARGET 0010f8a8*/
// 00102f70: moved to src/common/title.cpp

// 001070a8: moved to src/naka/libkn/camera.cpp

f32 func_0010f8a8(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0010f8a8jjjj");
// 00102f70: moved to src/common/title.cpp

// 001070a8: moved to src/naka/libkn/camera.cpp

f32 func_0010f8a8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(f32*)((u32)a0 + (3284)); }
}  // namespace n0010f8a8

// 0010f8b0 (was gap, never written) / 0010f8b8
namespace n0010f8b0 {
void func_0010f8b0(u8* p, u32 v) asm("func_0010f8b0");
void func_0010f8b0(u8* p, u32 v) { *(u32*)(p + 3312) = v; }
u32 func_0010f8b8(u8* p) asm("func_0010f8b8");
u32 func_0010f8b8(u8* p) { return *(u32*)(p + 3312); }
}

// 0010f8c0 (was src/anon/tiny_leaf.cpp)
namespace n0010f8c0 {
/*TARGET 0010f8c0*/
// 00105710: moved to src/anon/unit_001056e8.cpp

u32 func_0010f8c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0010f8c0jjjj");
// 00105710: moved to src/anon/unit_001056e8.cpp

u32 func_0010f8c0(u32 a0, u32 a1, u32 a2, u32 a3) {  // test_field2940_bit2
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = *(u32*)((u32)r4 + (s32)(2940));
    r2 = (u32)((s32)r2 >> 2);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}
}  // namespace n0010f8c0

// 0010f8d0 (was src/anon/tiny.cpp)
namespace n0010f8d0 {
/*TARGET 0010f8d0*/
u32 func_0010f8d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0010f8d0jjjj");
u32 func_0010f8d0(u32 a0, u32 a1, u32 a2, u32 a3) {  // is_field912_set
    (void)a1;
    (void)a2;
    (void)a3;
    return (*(u32*)((u32)a0 + (912)) != 0);
}
}  // namespace n0010f8d0

// 0010f8e0 (was src/anon/tiny_leaf.cpp)
namespace n0010f8e0 {
/*TARGET 0010f8e0*/
u32 func_0010f8e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0010f8e0jjjj");
u32 func_0010f8e0(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_bit3_of_field2940
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = *(u32*)((u32)r4 + (s32)(2940));
    r2 = (u32)((s32)r2 >> 3);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}
}  // namespace n0010f8e0

// 0010f8f0 (was src/anon/tiny.cpp)
namespace n0010f8f0 {
/*TARGET 0010f8f0*/
// 00109330: moved to src/anon/unit_001085a8.cpp

void func_0010f8f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0010f8f0jjjj");
// 00109330: moved to src/anon/unit_001085a8.cpp

void func_0010f8f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = *(u32*)((u32)a0 + (2940));
    v &= (u32)((s32)-1025);
    *(u32*)((u32)a0 + (2940)) = v;
}
}  // namespace n0010f8f0

// 0010f908 (was src/anon/batch_w1666.cpp)
namespace n0010f908 {
/*TARGET 0010f908*/
// 00292540: moved to src/anon/unit_00290f78.cpp
void func_0010f908(u8* p) asm("func_0010f908");
// 00292540: moved to src/anon/unit_00290f78.cpp
void func_0010f908(u8* p) { *(u32*)(p + 2940) |= 0x400; }
}  // namespace n0010f908

// 0010f918 (was src/anon/batch_w55.cpp)
namespace n0010f918 {
void func_0016bd60(u32, s32) asm("func_0016bd60");
void wtarget_0010f918(u32, u32, u32, u32) asm("_Z16wtarget_0010f918jjjj");
/*TARGET 0010f918*/
// Clears bit 14 of the flags word unless the target kind is 32.
void wtarget_0010f918(u32 a, u32, u32, u32) asm("_Z16wtarget_0010f918jjjj");
// Clears bit 14 of the flags word unless the target kind is 32.
void wtarget_0010f918(u32 a, u32, u32, u32) {
    u8* p = (u8*)a;
    if (*(s32*)(*(u8**)(p + 12) + 4) == 32) {
        func_0016bd60(a, 31);
        return;
    }
    *(u32*)(p + 2940) &= ~0x4000;
}
}  // namespace n0010f918

// 0010f960 (was src/anon/batch_w19.cpp)
namespace n0010f960 {
void func_0016bd60(void*, s32) asm("func_0016bd60");
/*TARGET 0010f960*/
// 001045b8: moved to src/common/gumimenu.cpp

void kn__Friend__enableInertia(u8* p) asm("kn__Friend__enableInertia");
// 001045b8: moved to src/common/gumimenu.cpp

void kn__Friend__enableInertia(u8* p) {
    if (*(s32*)(*(u8**)(p + 12) + 4) == 31) {
        func_0016bd60(p, 32);
        return;
    }
    *(u32*)(p + 0xb7c) |= 0x4000;
}
}  // namespace n0010f960

// 0010f9a0 (was gap, never written) / 0010f9c0
namespace n0010f9a0 {
u32 func_0010f9a0(u8* p) asm("func_0010f9a0");
u32 func_0010f9a0(u8* p) { u32* q = *(u32**)(p + 3168); if (!q) return 0; u32 t = *q & 2; return t != 0; }
u32 func_0010f9c0(u8* p) asm("func_0010f9c0");
u32 func_0010f9c0(u8* p) { u32* q = *(u32**)(p + 3168); if (!q) return 0; u32 t = *q & 1; return t != 0; }
}

// 0010f9e0 (was src/anon/tiny_more.cpp)
namespace n0010f9e0 {
/*TARGET 0010f9e0*/
u32 func_0010f9e0(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0010f9e0jjjj");
u32 func_0010f9e0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; u32 v = *(u32*)((u32)a0 + (3168)); v ^= a1; return (v < (u32)1); }
}  // namespace n0010f9e0

// 0010f9f0 (was src/anon/batch_w22.cpp)
namespace n0010f9f0 {
/*TARGET 0010f9f0*/
// --- 0010f9f0
void func_0010f9f0(u8* p, u8* src, u8 flag) asm("func_0010f9f0");
// --- 0010f9f0
void func_0010f9f0(u8* p, u8* src, u8 flag) {  // obj_set_vec_flag
    u8* dst = p + 3072;
    if (dst != src) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
    if (flag) *(u32*)(p + 2940) |= 0x80;
    else *(u32*)(p + 2940) &= ~0x80;
}
}  // namespace n0010f9f0

// 0010fa28 (was src/anon/tiny.cpp)
namespace n0010fa28 {
/*TARGET 0010fa28*/
u32 func_0010fa28(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0010fa28jjjj");
u32 func_0010fa28(u32 a0, u32 a1, u32 a2, u32 a3) {  // ptr_add3072
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)((s32)a0 + (3072));
}
}  // namespace n0010fa28

// 0010fa38 (was gap, never written)
namespace n0010fa38 {
struct Q { u32 v[4]; Q& operator=(const Q& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; } } __attribute__((aligned(16)));
void func_0010fa38(u8* p, const Q* v) asm("func_0010fa38");
void func_0010fa38(u8* p, const Q* v) { *(Q*)(p + 3104) = *v; }
}

// 0010fa58 (was src/anon/tiny.cpp)
namespace n0010fa58 {
/*TARGET 0010fa58*/
u32 kn__Friend__getInertia(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z22kn__Friend__getInertiajjjj");
u32 kn__Friend__getInertia(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)((s32)a0 + (3104));
}
}  // namespace n0010fa58

// 0010fa68 (was src/anon/auto80_199_queue.cpp)
namespace n0010fa68 {
/*TARGET 0010fa68*/
void func_0010fa68(u8* a0) asm("_Z13func_0010fa68Ph");
void func_0010fa68(u8* a0) {
    u8* s0 = a0;
    u32 s1;

    u32 g = D_00341708;
    if (g != 0) {
        if (func_001a2478(*(u32*)(g + 1164)) != 0) {  // count_div4_compare
            g = D_00341708;
            *(u32*)(s0 + 3300) = g;
            return;
        }
    }

    if (func_00112720(s0) != 0) {  // check_2924_lt14
        *(u32*)(s0 + 3300) = 0;
        return;
    }

    if (func_001a2478(*(u32*)(s0 + 1164)) != 0) {  // count_div4_compare
        *(u32*)(s0 + 3300) = (u32)s0;
        return;
    }

    s1 = func_00111e20(s0);
    if (s1 == 0) {
        goto set_zero;
    }
    if (func_001a2478(*(u32*)(s1 + 1164)) == 0) {  // count_div4_compare
        goto set_zero;
    }
    *(u32*)(s0 + 3300) = s1;
    return;

set_zero:
    *(u32*)(s0 + 3300) = 0;
}
}  // namespace n0010fa68

// 0010fb08 (was src/anon/batch_w1664.cpp)
namespace n0010fb08 {
/*TARGET 0010fb08*/
u32 func_0010fb08(u8* p) asm("func_0010fb08");
u32 func_0010fb08(u8* p) { return *(u32*)(p + 3300); }
}  // namespace n0010fb08

