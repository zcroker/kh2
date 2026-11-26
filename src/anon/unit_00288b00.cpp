// Linked unit 0x00288b00-0x0028be78 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/select.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/scroll_bar.hpp"

// 00288b00 (was src/anon/tiny_wrappers_more.cpp)
namespace n00288b00 {
u32 func_00288ca8(u32, u32, u32, u32) asm("_Z13func_00288ca8jjjj");
/*TARGET 00288b00*/
u32 func_00288b00(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00288b00jjjj");
u32 func_00288b00(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00288ca8(a0, a1, a2, a3);
}
}  // namespace n00288b00

// 00288b18 (was src/anon/auto80_199_queue.cpp)
namespace n00288b18 {
/*TARGET 00288b18*/
void func_00288b18(u32 a0) asm("_Z13func_00288b18j");
void func_00288b18(u32 a0) {
    if (D_0035f34c != a0) {
        if (D_0035f34c != 0) {
            D_0035f350 = D_0035f34c;
        }
        D_0035f34c = a0;
    } else {
        D_0035f348 = (u8)(D_0035f348 + 1);
    }

    if (func_00103b38() != 0) {
        Tz__MenuBase__SavePadInit(D_0035f34c);
    }
}
}  // namespace n00288b18

// 00288b78 (was src/anon/batch_w38.cpp)
namespace n00288b78 {
void Select_End(void*) asm("_ZN2Tz6Select3EndEv");
void func_00287f30(void) asm("func_00287f30");
// 0x00262c40: definition moved into src/anon/unit_0025f6b8.cpp

s32 func_00103b38(void) asm("func_00103b38");
extern s8 D_0035f348 asm("D_0035f348");
extern u32 D_0035f34c asm("D_0035f34c");
extern u32 D_0035f350 asm("D_0035f350");
/*TARGET 00288b78*/
void Select_End(void*) asm("_ZN2Tz6Select3EndEv");
void Select_End(void*) {
    if (func_00103b38()) func_00287f30();
    s8* c = &D_0035f348;
    if (*c) {
        (*c)--;
        return;
    }
    u32 n = D_0035f350;
    if (n) D_0035f34c = n;
    else D_0035f34c = 0;
    D_0035f350 = 0;
}
}  // namespace n00288b78

// 00288be8 (was src/anon/batch_w20.cpp)
namespace n00288be8 {
extern u8* D_0035f34c asm("D_0035f34c");
/*TARGET 00288be8*/
// Dispatches through slot 0 of the object at D_0035f34c, passing the caller's return address.
u32 func_00288be8(u32 a) asm("func_00288be8");
// Dispatches through slot 0 of the object at D_0035f34c, passing the caller's return address.
u32 func_00288be8(u32 a) {
    u8* o = D_0035f34c;
    return (*(u32 (**)(u8*, u32, void*))(*(u8**)o))(o, a, __builtin_return_address(0));
}
}  // namespace n00288be8

// 00288c20 (was src/anon/batch_w21.cpp)
namespace n00288c20 {
extern void** D_0035f34c asm("D_0035f34c");
typedef void (*Slot1Fn)(void*, void*);
/*TARGET 00288c20*/
void func_00288c20(void* a) asm("func_00288c20");
void func_00288c20(void* a) {
    if (a) {
        void** o = D_0035f34c;
        (*(Slot1Fn*)((u8*)*o + 4))(o, a);
    }
}
}  // namespace n00288c20

// 00288c58 (was src/anon/batch_w50.cpp)
namespace n00288c58 {
u32 func_00288be8(s32) asm("func_00288be8");
/*TARGET 00288c58*/
void func_00288c58(u8* o, s32 n) asm("func_00288c58");
void func_00288c58(u8* o, s32 n) {
    *(u32*)(o + 40) = func_00288be8(n * 4);
    *(u32*)(o + 44) = func_00288be8(n * 8);
    *(u32*)(o + 48) = func_00288be8(n * 8);
}
}  // namespace n00288c58

// 00288ca8 (was src/anon/tiny_auto80_solver.cpp)
namespace n00288ca8 {
void func_00288c20(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00288c20jjjjjjjj");
u32 func_00288ca8(u32) asm("_Z13func_00288ca8j");
/*TARGET 00288ca8*/
u32 func_00288ca8(u32 a0) asm("_Z13func_00288ca8j");
u32 func_00288ca8(u32 a0) {
    u32 s0 = a0;
    ((u32(*)(u32))func_00288c20)(*(u32*)(a0 + 40));
    ((u32(*)(u32))func_00288c20)(*(u32*)(s0 + 44));
    return ((u32(*)(u32))func_00288c20)(*(u32*)(s0 + 48));
}
}  // namespace n00288ca8

// 00288ce0 (was src/anon/batch_w1592.cpp)
namespace n00288ce0 {
union U1592W { u32 w; u8 c; };
union U1592H { u16 h; u8 c; };
struct S1592 { u8 p0[4]; s16 n; u8 p6[8]; s16 e; u8 p10[6]; s16 m; u8 p18[0x10]; U1592W* a; U1592H* b; U1592H* c; };
/*TARGET 00288ce0*/
void func_00288ce0(S1592* s, u32 x, s32 i, u16* p, u16* q) asm("func_00288ce0");
void func_00288ce0(S1592* s, u32 x, s32 i, u16* p, u16* q) {  // anim_add_key
    s32 j;
    s->a[i].w = x;
    if (i >= s->n) s->n = i + 1;
    for (j = 0; j < 4; j++) {
        s->b[i * 4 + j].h = p ? p[j] : 0xffff;
        s->c[i * 4 + j].h = q ? q[j] : s->b[i * 4 + j].h;
    }
    s->e = 0;
    s->m = s->n;
}
}  // namespace n00288ce0

// 00288d80 (was src/anon/batch_w3751_nsa.cpp)
namespace n00288d80 {
struct O { u8 pad[0x188]; s32 a; u8 p2[0x20]; s32 b; };
struct T { s16 a; s16 b; s16 c; };
O* Tz__MenuItem__start(s32, s32, s32, s32, s32, s32) asm("Tz__MenuItem__start");
void func_00288ce0(s32, O*, s32, T*, s32) asm("func_00288ce0");
/*TARGET 00288d80*/
// Empty asm and pin keep the first lh in its own pseudo (t7), which sched1 issues in the prologue.
void Tz__Select__SetItem(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, T* t2, s32 t3) asm("Tz__Select__SetItem");
// Empty asm and pin keep the first lh in its own pseudo (t7), which sched1 issues in the prologue.
void Tz__Select__SetItem(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, T* t2, s32 t3) {
    register s32 v asm("$15") = t2->a;
    asm("" : "+r"(v));
    O* o = Tz__MenuItem__start(v, a2, a3, t0, t1, 0);
    o->a = t2->c;
    o->b = 1;
    func_00288ce0(a0, o, a1, t2, t3);
}
}  // namespace n00288d80

// 00288e08 (was src/anon/batch_w1766.cpp)
namespace n00288e08 {
s32 func_0023aa98(s32) asm("func_0023aa98");
void func_00138c68(s32, s32, s32) asm("func_00138c68");
/*TARGET 00288e08*/
void Tz__Select__SetExOffset(s32 p, s32 i, s32 a, s32 b) asm("Tz__Select__SetExOffset");
void Tz__Select__SetExOffset(s32 p, s32 i, s32 a, s32 b) {
    p = (*(s32**)(p + 0x28))[i];
    s32 v = func_0023aa98(p + 0x18);
    if (b == -1) b = v;
    s32 aa = a;
    if (a == -1) aa = v;
    func_00138c68(p, aa * i, b * i);
}
}  // namespace n00288e08

// 00288e88 (was src/anon/batch_w85.cpp)
namespace n00288e88 {
void func_0028af18(void*, s32) asm("func_0028af18");
void func_0028b1b0(void*, s32) asm("func_0028b1b0");
void Tz__Select__SetPageMode(void*, s32) asm("Tz__Select__SetPageMode");
// obj_set_flag39_bits3000
void func_0028b248(void*, s32) asm("func_0028b248");
// set_field28_half
union S16U { s16 s; u8 c; };
union U32U { u32 w; u8 c; };
struct Obj288 { u8 p0[4]; s16 n; u8 p6[8]; s16 h14; u8 p16[2]; s16 h18; u8 p20[2]; s16 h22; u8 p24[16]; U32U* a; S16U* b; S16U* c; };
/*TARGET 00288e88*/
void func_00288e88(Obj288* o) asm("func_00288e88");
void func_00288e88(Obj288* o) {
    s32 i, k;
    for (i = 0; i < o->n; i++) {
        o->a[i].w = 0;
        for (k = 0; k < 4; k++) {
            o->b[i * 4 + k].s = -1;
            o->c[i * 4 + k].s = -1;
        }
    }
    o->n = 0;
    o->h22 = 0;
    o->h18 = 0;
    o->h14 = 0;
    func_0028af18(o, 115);
    func_0028b1b0(o, 0);
    Tz__Select__SetPageMode(o, 0);  // obj_set_flag39_bits3000
    func_0028b248(o, 1);  // set_field28_half
}
}  // namespace n00288e88

// 00288f48 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n00288f48 {
/*TARGET 00288f48*/
void func_00288f48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00288f48jjjjjjjj");
void func_00288f48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7;
    *(volatile u16*)((u32)r4 + (s32)(6)) = (u16)r5;
    *(volatile u16*)((u32)r4 + (s32)(12)) = (u16)r8;
    *(volatile u16*)((u32)r4 + (s32)(8)) = (u16)r6;
    *(volatile u16*)((u32)r4 + (s32)(10)) = (u16)r7;
}
}  // namespace n00288f48

// 00288f60 (was src/anon/batch_w1528.cpp)
namespace n00288f60 {
struct W1528_S5 { u8 pad[0x2c]; u16* volatile a; u16* volatile b; };
/*TARGET 00288f60*/
void func_00288f60(W1528_S5* p, s32 n, u16* s, u16* t) asm("func_00288f60");
void func_00288f60(W1528_S5* p, s32 n, u16* s, u16* t) {  // anim_copy4
    s32 i;
    for (i = 0; i < 4; i++) p->a[n * 4 + i] = s[i];
    for (i = 0; i < 4; i++) p->b[n * 4 + i] = t ? t[i] : s[i];
}
}  // namespace n00288f60

// 00288fd8 (was src/anon/batch_w39.cpp)
namespace n00288fd8 {
// --- 00288fd8
// Fills the 4 entries of row i of both tables (second one with w, or v if w is 0).
struct S288 { u8 pad[44]; u16* volatile a; u16* volatile b; };
/*TARGET 00288fd8*/
void func_00288fd8(S288* p, int i, int v, int w) asm("func_00288fd8");
void func_00288fd8(S288* p, int i, int v, int w) {  // anim_store4
    for (int j = 0; j < 4; j++) p->a[i * 4 + j] = v;
    for (int j = 0; j < 4; j++) p->b[i * 4 + j] = w ? w : v;
}
}  // namespace n00288fd8

// 00289038 (was src/anon/batch_w1592.cpp)
namespace n00289038 {
struct O1592 { u8 p[0x188]; s32 v; };
struct S1592b { u8 p0[0x28]; O1592** a; s16 (*b)[4]; s16 (*c)[4]; };
void func_00138c10(O1592*, s32) asm("func_00138c10");
/*TARGET 00289038*/
void func_00289038(S1592b* s, s32 i, u8 sel, u8 f1, s32 x, u8 f2, s32 y) asm("func_00289038");
void func_00289038(S1592b* s, s32 i, u8 sel, u8 f1, s32 x, u8 f2, s32 y) {  // anim_apply_child_key
    O1592* o = s->a[i];
    if (o) {
        s16* t = (sel ? s->c : s->b)[i];
        func_00138c10(o, f1 ? t[x] : x);
        o->v = f2 ? t[y] : y;
    }
}
}  // namespace n00289038

// 002890e0 (was src/anon/auto80_199_queue.cpp)
namespace n002890e0 {
/*TARGET 002890e0*/
void func_002890e0(Obj_002890e0* self, u32 a1, s32 a2, u32 a3, s32 a4) asm("_Z13func_002890e0P12Obj_002890e0jiji");
void func_002890e0(Obj_002890e0* self, u32 a1, s32 a2, u32 a3, s32 a4) {
    s32 i = 0;
    u32 s2 = a1 & 0xFF;
    u32 s3 = a3 & 0xFF;
    s32 s4 = a4;
    s32 s5 = a2;

    if ((s32)self->count <= 0) {
        return;
    }

    do {
        func_00289038((u32)self, i, 0, s2, s5, s3, s4);
        i += 1;
    } while (i < (s32)self->count);
}
}  // namespace n002890e0

// 00289178 (was gap, written for the unit)
namespace n00289178 {
struct G1 { u8 p0[4]; s16 n; u8 p6[12]; s16 f18; u8 p20[2]; s16 f22; u8 p24[4]; s16 f28; u8 p30[6]; u8 f36; u8 p37[3]; void** items; s16 (*t44)[4]; s16 (*t48)[4]; u32 f52; };
s16 func_00289178(G1* o, s32 i, u8 alt, s32 k) asm("func_00289178");
s16 func_00289178(G1* o, s32 i, u8 alt, s32 k) {
    s16* r;
    if (alt) r = o->t48[i];
    else r = o->t44[i];
    if (!r) return -1;
    return r[k];
}
}  // namespace n00289178

// 002891b8 (was src/tozawa/select.cpp)
namespace Tz { // method 002891b8
/*TARGET 002891b8*/
void* Select::GetItemPtr(s32 index) { return reinterpret_cast<SelectLayout*>(this)->itemPtr[index]; }
}  // Tz

// 002891d0 (was src/tozawa/select.cpp)
namespace Tz { // method 002891d0
/*TARGET 002891d0*/
void* Select::GetCurrentItemPtr() { return reinterpret_cast<SelectLayout*>(this)->itemPtr[reinterpret_cast<SelectLayout*>(this)->current]; }
}  // Tz

// 002891e8 (was src/tozawa/select.cpp)
namespace Tz { // method 002891e8
/*TARGET 002891e8*/
s16 Select::GetCurrent() { return reinterpret_cast<SelectLayout*>(this)->current; }
}  // Tz

// 002891f0 (was src/anon/batch_wcx2.cpp)
namespace n002891f0 {
// 0x002ab9c8: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct W2891f0 { u8 pad[392]; s32 f392; };
struct O2891f0 { s16 cur; u8 p2[2]; s16 n; u8 p6[12]; s16 off; u8 p20[2]; s16 max; u8 p24[13]; u8 b37; u8 p38[2]; W2891f0** w; u8 p44[4]; s16 (*tab)[4]; };
s32 func_0028b1c0(O2891f0*) asm("func_0028b1c0");
void func_00289b30(O2891f0*, O2891f0*, s16*) asm("func_00289b30");
void func_00138c10_2891f0(W2891f0*, s32) asm("func_00138c10");
void func_002891f0_def(O2891f0* o, s32 v, u8 flag, s32 a, s32 b) asm("Tz__Select__SetCurrent");
/*TARGET 002891f0*/
void func_002891f0_def(O2891f0* o, s32 v, u8 flag, s32 a, s32 b) asm("Tz__Select__SetCurrent");
void func_002891f0_def(O2891f0* o, s32 v, u8 flag, s32 a, s32 b)
{
    o->cur = v;
    if (o->n < o->max) {
        if ((s16)v < o->n) {
            o->off = 0;
        } else {
            o->cur = o->n - 1;
            o->off = v - o->n + 1;
        }
    }
    if (o->b37 == 0 && func_0028b1c0(o)) func_00289b30(o, o, &o->off);
    if (!flag) return;
    W2891f0* w = o->w[o->cur];
    if (!w) return;
    s16* t = o->tab[o->cur];
    func_00138c10_2891f0(w, t[a]);
    if (b >= 0) w->f392 = t[b];
}
}  // namespace n002891f0

// 002892f8 (was src/tozawa/select.cpp)
namespace Tz { // method 002892f8
/*TARGET 002892f8*/
s16 Select::GetItemMax() { return reinterpret_cast<SelectLayout*>(this)->itemMax; }
}  // Tz

// 00289300 (was src/tozawa/select.cpp)
namespace Tz { // method 00289300
/*TARGET 00289300*/
s32 Select::GetLast() {
    u32 r2 = (u32)(s32)(*(s16*)((u32)this + (s32)(4)));
    r2 = (u32)((s32)r2 + (-1));
    return (s32)r2;
}
}  // Tz

// 00289310 (was src/tozawa/select.cpp)
namespace Tz { // method 00289310
u32 func_0028b040(...) asm("func_0028b040");
/*TARGET 00289310*/
u32 Select::isCursorMove() {
    u32 s0 = (u32)this;
    u32 ret;
    if (*(s16*)(s0 + 2) >= 0) {
        ret = ((u32(*)(void))func_0028b040)() != (u32)(s32)*(s16*)(s0 + 2);
    } else {
        ret = 0;
    }
    return ret;
}
}  // Tz

// 00289358 (was src/anon/tiny_auto80_queue.cpp)
namespace n00289358 {
/*TARGET 00289358*/
u32 func_00289358(void* a0) asm("_Z13func_00289358Pv");
u32 func_00289358(void* a0) {
    s32 t;
    s32 v;
    t = (s32)*(s16*)((u8*)a0 + 20);
    if (t < 0) {
        goto ret0;
    }
    v = (s32)*(s16*)((u8*)a0 + 18);
    return (u32)((v ^ t) != 0);
ret0:
    return 0u;
}
}  // namespace n00289358

// 00289380 (was src/anon/batch_w1717.cpp)
namespace n00289380 {
struct W1717Q { u8 v[16] __attribute__((aligned(16))); W1717Q() {} ~W1717Q() {} };
struct W1717Pad { u64 a, b, c, d; W1717Q q[2]; f32 f; W1717Pad() {} };
struct W1717Obj {
    u8 p0[2]; s16 m2; s16 m4; u8 p6[0xc]; u16 m12; u16 m14; s16 m16;
    u8 p18[0xd]; u8 f25; u8 p26; u8 f27;
};
s16 func_0028b040(W1717Obj*) asm("func_0028b040");
void* func_00167f18(s32) asm("func_00167f18");
void func_00323af8(W1717Pad*, void*) asm("func_00323af8");
s32 func_00288040(void) asm("func_00288040");
W1717Pad* func_00288008(void) asm("func_00288008");
s32 func_002899e0(W1717Obj*, W1717Pad*) asm("func_002899e0");
s32 func_00289ef8(W1717Obj*, W1717Pad*) asm("func_00289ef8");
s32 func_0028af78(W1717Obj*, s32) asm("func_0028af78");
/*TARGET 00289380*/
s16 func_00289380(W1717Obj* o) asm("func_00289380");
s16 func_00289380(W1717Obj* o) {
    W1717Pad pad;
    s32 r;
    o->m2 = func_0028b040(o);
    o->m14 = o->m12;
    func_00323af8(&pad, func_00167f18(0));
    if (func_00288040()) {
        pad.a |= func_00288008()->a;
        pad.b |= func_00288008()->b;
        pad.c |= func_00288008()->c;
        pad.d |= func_00288008()->d;
    }
    r = 0;
    if (o->m16 != 0 && o->m4 != 0) {
        if (o->f25 != 0) r = func_00289ef8(o, &pad);
        else r = func_002899e0(o, &pad);
    }
    if (r) return -1;
    if (o->f25 == 0 && (pad.b & 0x40) && func_0028af78(o, 4)) return -12;
    if (o->f25 == 0 && (pad.b & 0x80) && func_0028af78(o, 8)) return -13;
    if (o->f25 == 0 && (pad.d & 0x40) && func_0028af78(o, 0x40000)) return -12;
    if (o->f25 == 0 && (pad.d & 0x80) && func_0028af78(o, 0x80000)) return -13;
    if (o->f25 == 0 && (pad.a & 0x40) && func_0028af78(o, 0x10000)) return -12;
    if (o->f25 == 0 && (pad.a & 0x80) && func_0028af78(o, 0x20000)) return -13;
    if ((pad.b & 4) && func_0028af78(o, 0x10)) return func_0028b040(o);
    if ((pad.b & 8) && func_0028af78(o, 0x20)) return -2;
    if ((pad.b & 0x100) && func_0028af78(o, 0x40)) return -4;
    if ((pad.b & 0x800) && func_0028af78(o, 0x100)) return -5;
    if ((pad.b & 0x1000) && func_0028af78(o, 0x200)) return -6;
    if ((pad.b & 0x2000) && func_0028af78(o, 0x400)) return -7;
    if ((pad.b & 0x4000) && func_0028af78(o, 0x1000) && o->f27 == 0) return -8;
    if ((pad.b & 0x8000) && func_0028af78(o, 0x2000) && o->f27 == 0) return -9;
    if ((pad.b & 0x10000) && func_0028af78(o, 0x4000)) return -10;
    if ((pad.b & 0x20000) && func_0028af78(o, 0x8000)) return -11;
    return -1;
}
}  // namespace n00289380

// 002899e0 (was src/anon/sweep_002899e0_nsa.cpp)
namespace n002899e0 {
struct S2899 { u16 x; s16 pad2; s16 pad4; s16 m6; s16 m8; s16 pad[4]; u16 y; s16 p20; s16 h22; };
struct M2899 { u64 a; u64 b; u64 c; u64 d; };
s32 func_0028af78(S2899*, s32) asm("func_0028af78");
s32 func_00289d28(S2899*, u16*, u16*) asm("func_00289d28");
s32 func_00289b30(S2899*, u16*, u16*) asm("func_00289b30");
s32 func_0028a5a8(S2899*, M2899*) asm("func_0028a5a8");
/*TARGET 002899e0*/
s32 func_002899e0(S2899* a0, M2899* a1) asm("func_002899e0");
s32 func_002899e0(S2899* a0, M2899* a1)
{
    u16 l[2];
    s32 r = 0;
    s16 v;
    u16 x = a0->x, y = a0->y;
    v = x + y;
    l[0] = x;
    l[1] = y;
    if (a1->d & a0->m6) {
        if (func_0028af78(a0, 1)) {
            if (v != 0 || (a1->b & a0->m6)) v = func_00289d28(a0, &l[0], &l[1]);
            goto done;
        }
    }
    if (a1->d & a0->m8) {
        if (func_0028af78(a0, 2)) {
            if (v < a0->h22 - 1 || (a1->b & a0->m8)) v = func_00289b30(a0, &l[0], &l[1]);
            goto done;
        }
    }
    r = func_0028a5a8(a0, a1);
done:
    if (r == 0) {
        if (v != (s16)a0->x + (s16)a0->y) {
            r = 1;
            a0->x = l[0];
            a0->y = l[1];
        }
    }
    return r;
}
}  // namespace n002899e0

// 00289b30 (was src/anon/match_00289b30_mam.cpp)
namespace n00289b30 {
struct ListCur {
    s16 def_cur;
    u16 pad2;
    s16 rows;
    u8 pad6[12];
    s16 def_top;
    u16 pad20;
    s16 count;
    u8 pad24[12];
    u8 wrap;
};
s32 func_0028b1c0(ListCur*, s32) asm("func_0028b1c0");
/*TARGET 00289b30*/
s32 func_00289b30(ListCur* o, s16* cur, s16* top) asm("func_00289b30");
s32 func_00289b30(ListCur* o, s16* cur, s16* top) {
    s32 n = o->count;
    s32 lim = n;
    if (o->rows < n) lim = o->rows;
    u32 all = 0;
    s32 idx;
    for (s32 i = 0; i < n; i++) all |= 1 << i;
    u32 seen = 0;
    while (seen != all) {
        if (o->rows >= o->count) {
            if (*cur < lim - 1) (*cur)++;
            else if (o->wrap) *cur = 0;
        } else {
            if (*cur < o->rows - 1) (*cur)++;
            else if (o->wrap) {
                if (*top < o->count - o->rows) (*top)++;
                else { *top = 0; *cur = 0; }
            } else if (*top < o->count - o->rows) (*top)++;
        }
        idx = *top + *cur;
        if (!func_0028b1c0(o, idx)) break;
        seen |= 1 << idx;
    }
    if (seen == all) {
        *cur = o->def_cur;
        *top = o->def_top;
        idx = *top + *cur;
    }
    return idx;
}
}  // namespace n00289b30

// 00289d28 (was src/anon/batch_w110.cpp)
namespace n00289d28 {
struct ListCur {
    s16 def_cur;
    u16 pad2;
    s16 rows;
    u8 pad6[12];
    s16 def_top;
    u16 pad20;
    s16 count;
    u8 pad24[12];
    u8 wrap;
};
s32 func_0028b1c0(ListCur*, s32) asm("func_0028b1c0");
/*TARGET 00289d28*/
// test_bit_field32
// Moves the cursor up one entry (scrolling / wrapping), skipping entries the check accepts.
s32 func_00289d28(ListCur* o, s16* cur, s16* top) asm("func_00289d28");
// test_bit_field32
// Moves the cursor up one entry (scrolling / wrapping), skipping entries the check accepts.
s32 func_00289d28(ListCur* o, s16* cur, s16* top) {
    s32 n = o->count;
    s32 lim = n;
    if (o->rows < n) lim = o->rows;
    u32 all = 0;
    s32 idx;
    for (s32 i = 0; i < n; i++) all |= 1 << i;
    u32 seen = 0;
    while (seen != all) {
        if (o->rows >= o->count) {
            if (*cur > 0) (*cur)--;
            else if (o->wrap) *cur = lim - 1;
        } else {
            if (*cur > 0) (*cur)--;
            else if (*top > 0) (*top)--;
            else if (o->wrap) {
                *top = o->count - o->rows;
                *cur = o->rows - 1;
            }
        }
        idx = *top + *cur;
        if (!func_0028b1c0(o, idx)) break;
        seen |= 1 << idx;
    }
    if (seen == all) {
        *cur = o->def_cur;
        *top = o->def_top;
        idx = *top + *cur;
    }
    return idx;
}
}  // namespace n00289d28

// 00289ef8 (was src/anon/batch_w1718.cpp)
namespace n00289ef8 {
struct W1718Select {
    s16 cur;        // 0x00 cursor inside the visible page
    s16 pad2;
    s16 last;       // 0x04
    s16 keyUp;      // 0x06
    s16 keyDown;    // 0x08
    s16 keyLeft;    // 0x0a
    s16 keyRight;   // 0x0c
    s16 padE[2];
    s16 top;        // 0x12 first item of the visible page
    s16 pad14;
    s16 count;      // 0x16 item count
    s16 cols;       // 0x18 items per row
    s16 rows;       // 0x1a visible rows
    u8 pad1c[8];
    u8 loop;        // 0x24 wrap around
};
struct W1718Pad {
    u64 pad0;
    u64 trig;       // 0x08
    u64 pad10;
    u64 rep;        // 0x18
};
s32 func_0028af78(W1718Select*, s32) asm("func_0028af78");
void func_0028b120(W1718Select*, s32*, s32*, s32) asm("func_0028b120");
u8 W1718_IsCenter(void*) asm("_Z13func_0028b210Pv");
s32 func_0028a5a8(W1718Select*, W1718Pad*) asm("func_0028a5a8");
/*TARGET 00289ef8*/
// Tz::Select: move the cursor on a grid of items from the pad input.
// Returns 1 if a direction key was handled, 0 if the move is blocked.
s32 func_00289ef8(W1718Select* sel, W1718Pad* pad) asm("func_00289ef8");
// Tz::Select: move the cursor on a grid of items from the pad input.
// Returns 1 if a direction key was handled, 0 if the move is blocked.
s32 func_00289ef8(W1718Select* sel, W1718Pad* pad)
{
    s32 col, row;
    s32 w, prow;
    s32 span;       // columns on the cursor's row, later the centering offset of a short last row
    s32 nrows;
    s32 ret;
    u64 rep;

    func_0028b120(sel, &col, &row, -1);
    func_0028b120(sel, &w, &prow, sel->cur);
    rep = pad->rep;
    if ((sel->keyLeft | sel->keyRight) & rep) {
        w = sel->count / sel->cols * sel->cols;
        span = (sel->cur + sel->top < w) ? sel->cols : sel->count - w;
    } else {
        span = sel->cols;
    }
    nrows = sel->count / sel->cols;
    if ((w = sel->count % sel->cols) != 0) nrows++;

    if ((rep & sel->keyUp) && func_0028af78(sel, 1)) {
        if (row == 0 && !(pad->trig & sel->keyUp)) return 0;
        if (nrows == 1 && (pad->trig & sel->keyUp)) return 0;
    } else if ((pad->rep & sel->keyDown) && func_0028af78(sel, 2)) {
        if (row >= nrows - 1 && !(pad->trig & sel->keyDown)) return 0;
        if (nrows == 1 && (pad->trig & sel->keyDown)) return 0;
    }
    if (W1718_IsCenter(sel)) {
        if ((pad->rep & sel->keyLeft) && func_0028af78(sel, 4)) {
            if (col == 0 && !(pad->trig & sel->keyLeft)) return 0;
            if (span == 1 && (pad->trig & sel->keyLeft)) return 0;
        } else if ((pad->rep & sel->keyRight) && func_0028af78(sel, 8)) {
            if (col >= span - 1 && !(pad->trig & sel->keyRight)) return 0;
            if (span == 1 && (pad->trig & sel->keyRight)) return 0;
        }
    }

    if ((pad->rep & sel->keyUp) && func_0028af78(sel, 1)) {
        ret = 1;
        span = 0;
        if ((row >= nrows - 1 || row == 0) && W1718_IsCenter(sel)) {
            if (sel->count % sel->cols != 0) span = (sel->cols - sel->count % sel->cols) / 2;
        }
        if (prow > 0) {
            sel->cur -= sel->cols;
            // The original tests both orders, so the result is always span.
            sel->cur += (span < col && col < span) ? col : span;
            goto end;
        } else if (sel->top > 0) {
            sel->top -= sel->cols;
            sel->cur += (span < col && col < span) ? col : span;
            goto end;
        } else {
            if (!sel->loop) goto end;
            if (sel->cols * sel->rows < sel->count) {
                sel->top = sel->count - sel->cols * sel->rows;
                if (sel->top % sel->cols != 0) sel->top += sel->cols - sel->top % sel->cols;
                sel->cur = col + sel->cols * (sel->rows - 1);
            } else {
                sel->cur = col + sel->cols * (nrows - 1);
            }
            sel->cur -= (col < span) ? col : span;
            if (sel->top + sel->cur >= sel->count) sel->cur = sel->count - sel->top - 1;
            goto end;
        }
    }
    if ((pad->rep & sel->keyDown) && func_0028af78(sel, 2)) {
        s32 vrows;
        ret = 1;
        span = 0;
        if (row >= nrows - 2 && W1718_IsCenter(sel)) {
            if (sel->count % sel->cols != 0) span = (sel->cols - sel->count % sel->cols) / 2;
        }
        if (sel->last < sel->count) {
            vrows = sel->rows;
        } else {
            vrows = sel->count / sel->cols;
            if ((w = sel->last % sel->cols) != 0) vrows++;
        }
        if (row < nrows - 1) {
            if (prow >= vrows - 1 && sel->rows < nrows) {
                sel->top += sel->cols;
            } else {
                sel->cur += sel->cols;
            }
            sel->cur -= (col < span) ? col : span;
            if (sel->top + sel->cur >= sel->count) sel->cur = sel->count - sel->top - 1;
            goto end;
        }
        if (sel->loop) {
            sel->top = 0;
            sel->cur = col + span;
        }
        goto end;
    }
    if ((pad->rep & sel->keyLeft) && func_0028af78(sel, 4)) {
        ret = 1;
        if (col > 0) sel->cur = sel->cur - 1;
        else sel->cur = sel->cur + span - 1;
        goto end;
    }
    if ((pad->rep & sel->keyRight) && func_0028af78(sel, 8)) {
        ret = 1;
        if (col < span - 1) sel->cur = sel->cur + 1;
        else sel->cur = sel->cur - span + 1;
        goto end;
    }
    ret = func_0028a5a8(sel, pad);
end:
    return ret;
}
}  // namespace n00289ef8

// 0028a5a8 (was src/anon/batch_w2415.cpp)
namespace n0028a5a8 {
// 002c29d8: large constructor (vtable stores, member ctors, D_00361c10 = this).
struct W1610Lc { s16 cur; u8 p2[2]; s16 vis; u8 p6[12]; s16 top; u8 p20[2]; s16 n; s16 cols; s16 rows; s16 step; u8 p30[6]; u8 wrap; u8 grid; u8 p38; u8 on; };
struct W1610Pd { u8 p0[8]; u64 rep; u8 p16[8]; u64 trg; };
// 0x002c29d8: definition moved into src/anon/unit_002c2228.cpp
// 0028a5a8: list cursor scroll up/down with wrap and grid paging.
s32 func_0028b040(W1610Lc*) asm("func_0028b040");
s32 func_0028af78(W1610Lc*, s32) asm("func_0028af78");
/*TARGET 0028a5a8*/
s32 func_0028a5a8(W1610Lc* l, W1610Pd* p) asm("func_0028a5a8");
s32 func_0028a5a8(W1610Lc* l, W1610Pd* p) {
    s32 ret = 0;
    s32 sm;
    s32 vis = l->vis < l->n ? l->vis : l->n;
    if (!l->on) return 0;
    s32 cur = l->cur;
    s32 top = l->top;
    s32 sel = func_0028b040(l);
    if ((p->trg & 0x8000) && func_0028af78(l, 0x2000)) {
        if (sel == 0 && !(p->rep & 0x8000)) return 0;
        if (top - l->step >= 0) {
            top -= l->step;
        } else if (top != 0 || cur != 0) {
            if (top + cur - l->step < 0) {
                cur = 0;
                top = 0;
            } else {
                cur = sel - l->step;
                top = 0;
            }
        } else if (l->wrap) {
            if (l->grid) {
                s32 pg = l->cols * l->rows;
                s32 m = l->n % pg;
                sm = m;
                sm += (pg - m) / l->cols * l->cols;
                top = l->n - sm;
                if (top < 0) top = 0;
            } else {
                top = l->n - vis;
            }
            cur = l->n - top - 1;
        }
    } else if ((p->trg & 0x4000) && func_0028af78(l, 0x1000)) {
        if (sel >= l->n - 1 && !(p->rep & 0x4000)) return 0;
        if (sel >= l->n - 1) {
            if (l->wrap) {
                cur = 0;
                top = 0;
            }
        } else {
            if (top + cur + l->step < l->n) {
                s32 t = top + l->step;
                if (t + vis < l->n) {
                    top = t;
                } else {
                    if (l->grid) {
                        s32 q = l->n / l->cols;
                        if (l->n % l->cols) q++;
                        top = (q - l->rows) * l->cols;
                    } else {
                        top = l->n - vis;
                    }
                    if (top + cur >= l->n) cur = l->n - top - 1;
                }
            } else {
                if (l->grid) {
                    s32 pg = l->cols * l->rows;
                    s32 m = l->n % pg;
                    sm = m;
                sm += (pg - m) / l->cols * l->cols;
                top = l->n - sm;
                    if (top < 0) top = 0;
                } else {
                    top = l->n - vis;
                }
                cur = l->n - top - 1;
            }
        }
    }
    if (func_0028b040(l) != top + cur) {
        l->cur = cur;
        ret = 1;
        l->top = top;
    }
    return ret;
}
}  // namespace n0028a5a8

// 0028a890 (was gap, written for the unit)
namespace n0028a890 {
struct G1 { u8 p0[4]; s16 n; u8 p6[12]; s16 f18; u8 p20[2]; s16 f22; u8 p24[4]; s16 f28; u8 p30[6]; u8 f36; u8 p37[3]; void** items; s16 (*t44)[4]; s16 (*t48)[4]; u32 f52; };
void func_00139580(void*) asm("func_00139580");
void func_0028a890(G1* o) asm("func_0028a890");
void func_0028a890(G1* o) {
    for (s32 i = 0; i < o->n; i++) {
        void* p = o->items[i];
        if (p) func_00139580(p);
    }
}
}  // namespace n0028a890

// 0028a908 (was src/anon/batch_w44.cpp)
namespace n0028a908 {
void func_00139570(void*) asm("func_00139570");
/*TARGET 0028a908*/
void func_0028a908(u8* o) asm("func_0028a908");
void func_0028a908(u8* o) {
    for (s32 i = 0; i < *(s16*)(o + 4); i++) {
        void* e = (*(void***)(o + 40))[i];
        if (e) func_00139570(e);
    }
}
}  // namespace n0028a908

// 0028a980 (was src/anon/batch_w86.cpp)
namespace n0028a980 {
struct Spr { u8 p0[392]; s32 f392; };
struct Def { s16 anim; s16 f2; s16 f4; };
union N16 { s16 v; s32 i; };
struct Obj { u8 p0[4]; N16 n; u8 p8[6]; s16 f14; u8 p16[24]; Spr** sprs; };
Def* func_0028ac98(Obj*, s32) asm("func_0028ac98");
// lookup_by_index_align
void func_00138c10(Spr*, s32) asm("func_00138c10");
/*TARGET 0028a980*/
void func_0028a980(Obj* o) asm("func_0028a980");
void func_0028a980(Obj* o)
{
    for (s32 i = 0; i < o->n.v; i++) {
        if (!o->sprs[i]) continue;
        Def* d = func_0028ac98(o, i);  // lookup_by_index_align
        if (d) {
            func_00138c10(o->sprs[i], d->anim);
            o->sprs[i]->f392 = d->f4;
        }
    }
    o->f14 = 0;
}
}  // namespace n0028a980

// 0028aa40 (was src/anon/batch_w84.cpp)
namespace n0028aa40 {
// Tz::Select::Start
union S16U { s16 v; s32 i; };
struct Sel {
    u8 _0[4];
    S16U n;
    u8 _8[6];
    s16 done;
    u8 _16[24];
    u8** arr;
};
s32 func_0028acc8(Sel*) asm("func_0028acc8");
u8* func_0028ac98(Sel*, s32) asm("func_0028ac98");
// lookup_by_index_align
void func_00138c10(void*, s32) asm("func_00138c10");
void sel_start(Sel* s) asm("_ZN2Tz6Select5StartEz");
/*TARGET 0028aa40*/
void sel_start(Sel* s) asm("_ZN2Tz6Select5StartEz");
void sel_start(Sel* s) {
    if (func_0028acc8(s)) {
        for (s32 i = 0; i < s->n.v; i++) {
            if (s->arr[i] == 0) continue;
            u8* r = func_0028ac98(s, i);  // lookup_by_index_align
            if (!r) continue;
            s16 v = *(s16*)(r + 2);
            if (*(s32*)(s->arr[i] + 388) == v) continue;
            func_00138c10(s->arr[i], v);
            *(s32*)(s->arr[i] + 392) = -1;
        }
    }
    s->done = 1;
}
}  // namespace n0028aa40

// 0028ab20 (was src/anon/batch_w81.cpp)
namespace n0028ab20 {
void func_00138c10(u8*, u32) asm("func_00138c10");
s32 func_0028acc8(u32) asm("func_0028acc8");
// --- 0028ab20: release every entry's id (-1) and clear the current selection
u8* func_0028ac98(u8*, s32) asm("func_0028ac98");
// lookup_by_index_align
union Cnt81 { u16 v; u8 c; };
void SelectLeave81(u8* o) asm("_ZN2Tz6Select5LeaveEz");
/*TARGET 0028ab20*/
void SelectLeave81(u8* o) asm("_ZN2Tz6Select5LeaveEz");
void SelectLeave81(u8* o) {
    func_0028acc8((u32)o);
    s32 i;
    for (i = 0; i < (s16)((Cnt81*)(o + 4))->v; i++) {
        if ((*(u8***)(o + 40))[i] == 0) continue;
        u8* v = func_0028ac98(o, i);  // lookup_by_index_align
        if (!v) continue;
        func_00138c10((*(u8***)(o + 40))[i], *(s16*)(v + 4));
        *(s32*)((*(u8***)(o + 40))[i] + 392) = -1;
    }
    *(s16*)(o + 14) = 0;
}
}  // namespace n0028ab20

// 0028abe0 (was src/anon/batch_w1593.cpp)
namespace n0028abe0 {
typedef void (*VF1593)(void*);
struct VT1593 { void* f[8]; };
struct Obj1593 { VT1593* vt; };
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028acc8(void*) asm("func_0028acc8");
// ---- 0028abe0 Tz::Select::Destroy
union ItemU1593 { Obj1593* p; s16 h; u8 c; };
struct Sel1593 { u32 a; s16 n; u8 pad[0x22]; ItemU1593* items; };
void sel_destroy1593(Sel1593* p) asm("_ZN2Tz6Select7DestroyEz");
/*TARGET 0028abe0*/
void sel_destroy1593(Sel1593* p) asm("_ZN2Tz6Select7DestroyEz");
void sel_destroy1593(Sel1593* p) {
    s32 i;
    if (!func_0028acc8(p)) return;
    for (i = 0; i < p->n; i++) {
        if (p->items[i].p) {
            if (func_00139d78(p->items[i].p)) ((VF1593)p->items[i].p->vt->f[5])(p->items[i].p);
            else p->items[i].p = 0;
        }
    }
}
}  // namespace n0028abe0

// 0028ac98 (was src/anon/batch_w2.cpp)
namespace n0028ac98 {
struct Entry8 { u32 x, y; };
struct Table8 {
    s16 id;
    u8 pad[0x2a];
    Entry8* other;  // 0x2c
    Entry8* self;   // 0x30
};
/*TARGET 0028ac98*/
Entry8* func_0028ac98(Table8* t, s32 id) asm("func_0028ac98");
Entry8* func_0028ac98(Table8* t, s32 id) {  // lookup_by_index_align
    if (id == t->id) return &t->self[id];
    return &t->other[id];
}
}  // namespace n0028ac98

// 0028acb8 (was src/tozawa/select.cpp)
namespace Tz { // method 0028acb8
/*TARGET 0028acb8*/
u32 Select::isFadeOut() {
    u32 v0 = (u32)(s16)*(s16*)((u32)this + 14);
    return (u32)(0u < v0);
}
}  // Tz

// 0028acc8 (was src/anon/batch_w55.cpp)
namespace n0028acc8 {
s32 func_00139d78(void*) asm("func_00139d78");
s32 Select_isCreated(u8*) asm("_ZN2Tz6Select9isCreatedEz");
/*TARGET 0028acc8*/
s32 Select_isCreated(u8* s) asm("_ZN2Tz6Select9isCreatedEz");
s32 Select_isCreated(u8* s) {
    s32 i;
    for (i = 0; i < *(s16*)(s + 4); i++) {
        void* o = (*(void***)(s + 40))[i];
        if (o && func_00139d78(o)) return 1;
    }
    return 0;
}
}  // namespace n0028acc8

// 0028ad50 (was src/anon/batch_w88.cpp)
namespace n0028ad50 {
s32 func_001396c0(u8*) asm("func_001396c0");
s32 func_0028acc8p(u8*) asm("func_0028acc8");
s32 func_00239d30i(u8*, u32) asm("func_00239d30");
/*TARGET 0028ad50*/
s32 func_0028ad50(u8* p) asm("func_0028ad50");
s32 func_0028ad50(u8* p) {
    if (!func_0028acc8p(p)) return 0;
    for (s32 i = 0; i < (s16)*(u16*)(p + 4); i++) {
        u8* o = (*(u8***)(p + 40))[i];
        if (!o) continue;
        if (func_001396c0(o)) continue;
        u8* q = (*(u8***)(p + 40))[i] + 24;
        if ((u8)func_00239d30i(q, *(u32*)(q + 276))) continue;
        if (!(*(u8***)(p + 40))[i][404]) return 0;
    }
    return 1;
}
}  // namespace n0028ad50

// 0028ae28 (was src/anon/batch_w39.cpp)
namespace n0028ae28 {
// --- 0028ae28
struct S28a { u8 pad[40]; u8** items; };
void func_00139d78(u8*) asm("func_00139d78");
s16* func_0028ac98(S28a*, int) asm("func_0028ac98");
// lookup_by_index_align
int IsSeqDone_impl(S28a* p, int i) asm("_ZN2Tz6Select9IsSeqDoneEz");
/*TARGET 0028ae28*/
int IsSeqDone_impl(S28a* p, int i) asm("_ZN2Tz6Select9IsSeqDoneEz");
int IsSeqDone_impl(S28a* p, int i) {
    func_00139d78(p->items[i]);
    s16* r = func_0028ac98(p, i);  // lookup_by_index_align
    return *(s32*)(p->items[i] + 388) == r[2];
}
}  // namespace n0028ae28

// 0028ae98 (was src/anon/batch_w62.cpp)
namespace n0028ae98 {
void func_00139d78(u8*) asm("func_00139d78");
s16* func_0028ac98(u8*, u32) asm("func_0028ac98");
/*TARGET 0028ae98*/
// lookup_by_index_align
s32 func_0028ae98(u8* p, u32 i) asm("func_0028ae98");
// lookup_by_index_align
s32 func_0028ae98(u8* p, u32 i) {
    u8* o = (*(u8***)(p + 40))[i];
    if (o) func_00139d78(o);
    s16* r = func_0028ac98(p, i);  // lookup_by_index_align
    return *(s32*)((*(u8***)(p + 40))[i] + 388) == r[3];
}
}  // namespace n0028ae98

// 0028af18 (was src/tozawa/select.cpp)
namespace Tz { // method 0028af18
/*TARGET 0028af18*/
s32 Select::SetEnableButton(u32 v) {
    reinterpret_cast<SelectLayout*>(this)->enableButton = (s32)v;
    return (s32)v;
}
}  // Tz

// 0028af28 (was src/tozawa/select.cpp)
namespace Tz { // method 0028af28
/*TARGET 0028af28*/
s32 Select::SetDisableButton(u32 v) {
    u32 r = (u32)reinterpret_cast<SelectLayout*>(this)->enableButton;
    r &= ~(0u | v);
    reinterpret_cast<SelectLayout*>(this)->enableButton = (s32)r;
    return (s32)r;
}
}  // Tz

// 0028af40 (was src/tozawa/select.cpp)
namespace Tz { // method 0028af40
/*TARGET 0028af40*/
s32 Select::SetEnableShortCut(u32 v) {
    u32 r2 = *(u32*)((u32)this + (s32)(52));
    u32 r15 = (u32)((s32)0u + (-1793));
    v = (u32)(v & 0x0700u);
    r2 = (u32)(r2 & r15);
    r2 = (u32)(r2 | v);
    *(u32*)((u32)this + (s32)(52)) = r2;
    return (s32)r2;
}
}  // Tz

// 0028af60 (was gap, written for the unit)
namespace n0028af60 {
struct G1 { u8 p0[4]; s16 n; u8 p6[12]; s16 f18; u8 p20[2]; s16 f22; u8 p24[4]; s16 f28; u8 p30[6]; u8 f36; u8 p37[3]; void** items; s16 (*t44)[4]; s16 (*t48)[4]; u32 f52; };
u32 func_0028af60(G1* o, u32 m) asm("func_0028af60");
u32 func_0028af60(G1* o, u32 m) {
    u32 r = o->f52 & ~(m & 0x700);
    o->f52 = r;
    return r;
}
}  // namespace n0028af60

// 0028af78 (was src/anon/tiny_more2.cpp)
namespace n0028af78 {
/*TARGET 0028af78*/
u32 func_0028af78(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0028af78jjjj");
u32 func_0028af78(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; u32 v=*(u32*)((u32)a0+(52)); v &= a1; return (v != 0); }
}  // namespace n0028af78

// 0028af88 (was src/tozawa/select.cpp)
namespace Tz { // method 0028af88
/*TARGET 0028af88*/
s32 Select::GetEnableButton() { return reinterpret_cast<SelectLayout*>(this)->enableButton; }
}  // Tz

// 0028af90 (was src/anon/batch_w4.cpp)
namespace n0028af90 {
/*TARGET 0028af90*/
void Tz__Select__SetSelectMax(u8* p, s32 a) asm("Tz__Select__SetSelectMax");
void Tz__Select__SetSelectMax(u8* p, s32 a) {  // obj_set_field22_from_arg
    *(u16*)(p + 22) = (a >= 0) ? a : *(u16*)(p + 4);
}
}  // namespace n0028af90

// 0028afa8 (was src/tozawa/select.cpp)
namespace Tz { // method 0028afa8
/*TARGET 0028afa8*/
s16 Select::GetSelectMax() { return *(s16*)((u32)this + 22); }
}  // Tz

// 0028afb0 (was gap, written for the unit)
namespace n0028afb0 {
struct G1 { u8 p0[4]; s16 n; u8 p6[12]; s16 f18; u8 p20[2]; s16 f22; u8 p24[4]; s16 f28; u8 p30[6]; u8 f36; u8 p37[3]; void** items; s16 (*t44)[4]; s16 (*t48)[4]; u32 f52; };
s32 func_0028afb0(G1* o, s32 v) asm("func_0028afb0");
s32 func_0028afb0(G1* o, s32 v) {
    s32 r = v - o->f18;
    if (r < 0) r += o->f22;
    return r;
}
}  // namespace n0028afb0

// 0028afd0 (was src/anon/batch_w37.cpp)
namespace n0028afd0 {
s32 func_0028b1c0(void*, s32) asm("func_0028b1c0");
// test_bit_field32
void func_00289b30(void*, void*, void*) asm("func_00289b30");
/*TARGET 0028afd0*/
void func_0028afd0(s16* p, s32 a) asm("func_0028afd0");
void func_0028afd0(s16* p, s32 a) {  // obj_set_signed18
    p[9] = a;
    s32 v = (s16)a + p[0];
    if (((u8*)p)[37] == 0) {
        if (func_0028b1c0(p, v)) func_00289b30(p, p, p + 9);  // test_bit_field32
    }
}
}  // namespace n0028afd0

// 0028b038 (was src/tozawa/select.cpp)
namespace Tz { // method 0028b038
/*TARGET 0028b038*/
s16 Select::GetSelectTop() { return reinterpret_cast<SelectLayout*>(this)->selectTop; }
}  // Tz

// 0028b040 (was src/anon/batch_w12.cpp)
namespace n0028b040 {
s32 JmReport_GetData(s16*) asm("_ZN2Tz8JmReport7GetDataEj");
/*TARGET 0028b040*/
s32 JmReport_GetData(s16* self) asm("_ZN2Tz8JmReport7GetDataEj");
s32 JmReport_GetData(s16* self) {
    if (self[11] != 0) return (self[0] + self[9]) % self[11];
    return self[0] + self[9];
}
}  // namespace n0028b040

// 0028b078 (was src/anon/batch_w45.cpp)
namespace n0028b078 {
void func_00288f48(u8*, u32, u32, u32, u32) asm("func_00288f48");
void func_0028af18(u8*, u32) asm("func_0028af18");
void func_0028b1b0(u8*, u32) asm("func_0028b1b0");
/*TARGET 0028b078*/
void func_0028b078(u8* a0, s32 a1, s32 a2) asm("func_0028b078");
void func_0028b078(u8* a0, s32 a1, s32 a2) {  // obj_setup_from_args
    a0[38] = 0;
    a0[37] = 1;
    *(s16*)(a0 + 24) = a1;
    *(s16*)(a0 + 26) = a2;
    func_00288f48(a0, 16, 32, 64, 128);
    func_0028af18(a0, 127);
    func_0028b1b0(a0, 0);
}
}  // namespace n0028b078

// 0028b0e0 (was src/anon/batch_w16.cpp)
namespace n0028b0e0 {
struct SelW16 {
    u8 pad[24];
    u16 f24;
    u16 f26;
    u8 pad2[9];
    u8 f37;
    u8 f38;
};
void SetEnableButton(SelW16*, u32) asm("_ZN2Tz6Select15SetEnableButtonEj");
void SetSelectDisable(SelW16*, u32) asm("_ZN2Tz6Select16SetSelectDisableEj");
/*TARGET 0028b0e0*/
void Reset2DMode(SelW16* t) asm("_ZN2Tz6Select11Reset2DModeEv");
void Reset2DMode(SelW16* t) {
    t->f37 = 0;
    t->f38 = 0;
    t->f24 = 0;
    t->f26 = 0;
    SetEnableButton(t, 115);
    SetSelectDisable(t, 0);
}
}  // namespace n0028b0e0

// 0028b120 (was src/anon/batch_w207.cpp)
namespace n0028b120 {
union W207U { s32 i; u8 c; };
struct W207P { s16 a; char pad[16]; s16 b; char pad2[4]; s16 c; };
/*TARGET 0028b120*/
void func_0028b120(W207P* p, W207U* r, W207U* q, s32 x) asm("func_0028b120");
void func_0028b120(W207P* p, W207U* r, W207U* q, s32 x) {
    if (x < 0) x = p->a + p->b;
    r->i = x % p->c;
    q->i = x / p->c;
}
}  // namespace n0028b120

// 0028b160 (was src/anon/batch_w211.cpp)
namespace n0028b160 {
struct W211S28 { u8 p[4]; s16 n; u8 q[0x22]; u32* tbl; };
/*TARGET 0028b160*/
s32 Tz__Select__GetPtr2Idx(W211S28* s, u32 key) asm("Tz__Select__GetPtr2Idx");
s32 Tz__Select__GetPtr2Idx(W211S28* s, u32 key) {  // find_index_in_array
    s32 i = 0;
    s32 n = s->n;
    if (n > 0) {
        u32* p = s->tbl;
        do {
            if (key == *p) break;
            p++;
            i++;
        } while (i < n);
    }
    return i < s->n ? i : -1;
}
}  // namespace n0028b160

// 0028b1b0 (was src/tozawa/select.cpp)
namespace Tz { // method 0028b1b0
/*TARGET 0028b1b0*/
void Select::SetSelectDisable(u32 v) { reinterpret_cast<SelectLayout*>(this)->selectDisable = v; }
}  // Tz

// 0028b1b8 (was src/anon/misc_2.cpp)
namespace n0028b1b8 {
/*TARGET 0028b1b8*/
s32 func_0028b1b8(void* self) asm("_Z13func_0028b1b8Pv");
s32 func_0028b1b8(void* self) { return (s32)(*(s32*)((char*)self + 32)); }
}  // namespace n0028b1b8

// 0028b1c0 (was src/anon/batch_w4.cpp)
namespace n0028b1c0 {
/*TARGET 0028b1c0*/
// Tests bit `bit` of the mask at +0x20.
u32 func_0028b1c0(u8* p, s32 bit) asm("func_0028b1c0");
// Tests bit `bit` of the mask at +0x20.
u32 func_0028b1c0(u8* p, s32 bit) {  // test_bit_field32
    u32 m = *(u32*)(p + 32);
    if (m == 0) return 0;
    return (m & (1 << bit)) != 0;
}
}  // namespace n0028b1c0

// 0028b1e8 (was src/tozawa/select.cpp)
namespace Tz { // method 0028b1e8
/*TARGET 0028b1e8*/
void Select::SetSelectorLoop(bool v) { *(u8*)((u32)this + 36) = (u8)((u32)v & 0xffu); }
}  // Tz

// 0028b1f8 (was gap, written for the unit)
namespace n0028b1f8 {
struct G1 { u8 p0[4]; s16 n; u8 p6[12]; s16 f18; u8 p20[2]; s16 f22; u8 p24[4]; s16 f28; u8 p30[6]; u8 f36; u8 p37[3]; void** items; s16 (*t44)[4]; s16 (*t48)[4]; u32 f52; };
u8 func_0028b1f8(G1* o) asm("func_0028b1f8");
u8 func_0028b1f8(G1* o) {
    return o->f36;
}
}  // namespace n0028b1f8

// 0028b200 (was src/anon/tiny.cpp)
namespace n0028b200 {
/*TARGET 0028b200*/
void func_0028b200(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0028b200jjjj");
void func_0028b200(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a2;
    (void)a3;
    u32 v = a1 & 0x00ffu;
    *(u8*)((u32)a0 + (38)) = (u8)v;
}
}  // namespace n0028b200

// 0028b210 (was src/anon/misc_2.cpp)
namespace n0028b210 {
/*TARGET 0028b210*/
u8 func_0028b210(void* self) asm("_Z13func_0028b210Pv");
u8 func_0028b210(void* self) { return (u8)(*(u8*)((char*)self + 38)); }
}  // namespace n0028b210

// 0028b218 (was src/anon/batch_w10.cpp)
namespace n0028b218 {
/*TARGET 0028b218*/
void Tz__Select__SetPageMode(u8* p, u8 on) asm("Tz__Select__SetPageMode");
void Tz__Select__SetPageMode(u8* p, u8 on) {  // obj_set_flag39_bits3000
    p[39] = on;
    if (on) {
        *(u32*)(p + 52) |= 0x3000;
    } else {
        *(u32*)(p + 52) &= ~0x3000;
    }
}
}  // namespace n0028b218

// 0028b248 (was src/anon/tiny.cpp)
namespace n0028b248 {
/*TARGET 0028b248*/
void func_0028b248(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0028b248jjjj");
void func_0028b248(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_field28_half
    *(u16*)((u32)a0 + (28)) = (u16)a1;
}
}  // namespace n0028b248

// 0028b250 (was gap, written for the unit)
namespace n0028b250 {
struct G1 { u8 p0[4]; s16 n; u8 p6[12]; s16 f18; u8 p20[2]; s16 f22; u8 p24[4]; s16 f28; u8 p30[6]; u8 f36; u8 p37[3]; void** items; s16 (*t44)[4]; s16 (*t48)[4]; u32 f52; };
s16 func_0028b250(G1* o) asm("func_0028b250");
s16 func_0028b250(G1* o) {
    return o->f28;
}
}  // namespace n0028b250

// 0028b258 (was src/anon/batch_w1592.cpp)
namespace n0028b258 {
struct Q1592 { u8 v[16] __attribute__((aligned(16))); Q1592() {} ~Q1592() {} };
struct B1592 { u64 a, b, c, d; Q1592 q[2]; f32 f; B1592() {} };
void* func_00167f18(s32) asm("func_00167f18");
void func_00323af8(B1592*, void*) asm("func_00323af8");
s32 func_00288040(void) asm("func_00288040");
u64* func_00288008(void) asm("func_00288008");
/*TARGET 0028b258*/
s32 func_0028b258(u32 m) asm("func_0028b258");
s32 func_0028b258(u32 m) {
    B1592 b;
    func_00323af8(&b, func_00167f18(0));
    if (func_00288040()) b.a |= *func_00288008();
    return (b.a & m) != 0;
}
}  // namespace n0028b258

// 0028b300 (was src/anon/batch_w82.cpp)
namespace n0028b300 {
void func_0028d8c0(u8*, u32, u32, u32, u32, u32, s32, s32) asm("func_0028d8c0");
void func_0028b4c0(u8*, u32) asm("func_0028b4c0");
// copy_3halfwords_416
void func_0028b4f0(u8*, u32) asm("func_0028b4f0");
// copy_3halfwords_422
u8* func_0023f1b0(u32) asm("func_0023f1b0");
u32 YI__LAYOUT__SearchSequence(u8*, s16, s32) asm("YI__LAYOUT__SearchSequence");
void func_0028dd28(u8*, u32) asm("func_0028dd28");
/*TARGET 0028b300*/
void Tz__LaySeq__create(u8* a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, u32 t3) asm("Tz__LaySeq__create");
void Tz__LaySeq__create(u8* a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, u32 t3)
{
    s32 cur;
    s32 i;
    *(u32*)(a0 + 408) = t0;
    func_0028d8c0(a0, a1, a2, a3, t0, t3, -1, 0);
    func_0028b4c0(a0, t1);  // copy_3halfwords_416
    func_0028b4f0(a0, t2);  // copy_3halfwords_422
    cur = *(s32*)(func_0023f1b0(*(u32*)(a0 + 408)) + 76);
    {
        u8* p = a0;
        for (i = 0; i < 3; i++, p += 2) {
            if (cur == *(s16*)(p + 416))
                func_0028dd28(a0, YI__LAYOUT__SearchSequence(func_0023f1b0(*(u32*)(a0 + 408)), *(s16*)(p + 422), 0));
        }
    }
    *(s16*)(a0 + 428) = cur;
}
}  // namespace n0028b300

// 0028b3c0 (was src/anon/batch_w81.cpp)
namespace n0028b3c0 {
typedef void (*VFnV81)(...);
struct VObjV81 { VFnV81* vt; };
s32 func_00139d78(u32) asm("func_00139d78");
// --- 0028b3c0
u8* func_0023f1b0(u32) asm("func_0023f1b0");
u32 YI__LAYOUT__SearchSequence(u8*, s16, u32) asm("YI__LAYOUT__SearchSequence");
void func_001396b0(u8*) asm("func_001396b0");
void func_0031ac78(u8*, u32) asm("func_0031ac78");
void dk__Sprite__update(u8*) asm("dk__Sprite__update");
/*TARGET 0028b3c0*/
void Tz__LaySeq__update(u8* o) asm("Tz__LaySeq__update");
void Tz__LaySeq__update(u8* o) {
    if (!func_00139d78(*(u32*)(o + 408))) {
        ((VObjV81*)o)->vt[5](o);
        return;
    }
    s32 cur = *(s32*)(func_0023f1b0(*(u32*)(o + 408)) + 76);
    if (cur != *(s16*)(o + 428)) {
        s32 k = 0;
        u8* q = o;
        for (; k < 3; k++, q += 2) {
            if (cur == *(s16*)(q + 416)) {
                *(u32*)(o + 400) = YI__LAYOUT__SearchSequence(func_0023f1b0(*(u32*)(o + 408)), *(s16*)(q + 422), 0);
                func_001396b0(o);
                if (*(u32*)(o + 400)) {
                    *(u32*)(o + 396) = 0;
                    func_001396b0(o);
                    if (*(u32*)(o + 396)) func_0031ac78(o, 0);
                }
                break;
            }
        }
    }
    *(s16*)(o + 428) = cur;
    dk__Sprite__update(o);
}
}  // namespace n0028b3c0

// 0028b4c0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0028b4c0 {
/*TARGET 0028b4c0*/
void func_0028b4c0(void* a0, void* a1) asm("_Z13func_0028b4c0PvS_");
void func_0028b4c0(void* a0, void* a1) {  // copy_3halfwords_416
    s32 i = 0;
    do {
        s32 off = i << 1;
        u16 v = *(u16*)((u32)off + (u32)a1);
        *(u16*)((u32)off + (u32)a0 + 416) = v;
        i = i + 1;
    } while (i < 3);
}
}  // namespace n0028b4c0

// 0028b4f0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0028b4f0 {
/*TARGET 0028b4f0*/
void func_0028b4f0(void* a0, void* a1) asm("_Z13func_0028b4f0PvS_");
void func_0028b4f0(void* a0, void* a1) {  // copy_3halfwords_422
    u8* p0 = (u8*)a0 + 422;
    u8* p1 = (u8*)a1;
    s32 i = 0;
    for (;;) {
        u16 v = *(u16*)p1;
        i = i + 1;
        s32 c = i < 3;
        *(u16*)p0 = v;
        p1 = p1 + 2;
        if (c != 0) {
            p0 = p0 + 2;
            continue;
        }
        p0 = p0 + 2;
        break;
    }
}
}  // namespace n0028b4f0

// 0028b520 (was src/anon/batch_w77.cpp)
namespace n0028b520 {
void func_0028d980(u8*, u32, u32, u32, u32, u32, s32, u32, s32) asm("func_0028d980");
void func_0028b6f0(u8*, u32) asm("func_0028b6f0");
void func_0028b720(u8*, u32) asm("func_0028b720");
u8* func_0023f1b0(u32) asm("func_0023f1b0");
u32 YI__LAYOUT__SearchSequence(u8*, s32, s32) asm("YI__LAYOUT__SearchSequence");
void func_0028dd28(u8*, u32) asm("func_0028dd28");
/*TARGET 0028b520*/
void Tz__LaySeqMess__create(u8* p, u32 a, u32 b, u32 c, u32 id, u32 x, u32 y, u32 z, u32 w) asm("Tz__LaySeqMess__create");
void Tz__LaySeqMess__create(u8* p, u32 a, u32 b, u32 c, u32 id, u32 x, u32 y, u32 z, u32 w)
{
    *(u32*)(p + 436) = id;
    func_0028d980(p, a, b, c, id, z, -1, w, 0);
    func_0028b6f0(p, x);
    func_0028b720(p, y);
    s32 v = *(s32*)(func_0023f1b0(*(u32*)(p + 436)) + 76);
    for (s32 i = 0; i < 3; i++) {
        if (v == ((s16*)(p + 444))[i]) {
            func_0028dd28(p, YI__LAYOUT__SearchSequence(func_0023f1b0(*(u32*)(p + 436)), ((s16*)(p + 450))[i], 0));
            break;
        }
    }
    *(s16*)(p + 456) = v;
}
}  // namespace n0028b520

// 0028b5f0 (was gap, written for the unit)
namespace n0028b5f0 {
struct LD;
typedef void (*LFn)(LD*);
struct LD { LFn* vt; u8 p4[392]; void* f396; void* f400; u8 p404[32]; void* f436; u8 p440[4]; s16 a444[3]; s16 a450[3]; s16 f456; };
s32 func_00139d78(void*) asm("func_00139d78");
u8* func_0023f1b0(void*) asm("func_0023f1b0");
void* YI__LAYOUT__SearchSequence(u8*, s32, s32) asm("YI__LAYOUT__SearchSequence");
void func_001396b0(void*) asm("func_001396b0");
void func_0031ac78(void*, s32) asm("func_0031ac78");
void dk__SpriteMessage__update(void*) asm("dk__SpriteMessage__update");
void func_0028b5f0(LD* o) asm("func_0028b5f0");
void func_0028b5f0(LD* o) {
    if (!func_00139d78(o->f436)) { o->vt[5](o); return; }
    s32 v = *(s32*)(func_0023f1b0(o->f436) + 76);
    if (v != o->f456) {
        for (s32 i = 0; i < 3; i++) {
            if (v == o->a444[i]) {
                o->f400 = YI__LAYOUT__SearchSequence(func_0023f1b0(o->f436), o->a450[i], 0);
                func_001396b0(o);
                if (o->f400) {
                    o->f396 = 0;
                    func_001396b0(o);
                    if (o->f396) func_0031ac78(o, 0);
                }
                break;
            }
        }
    }
    o->f456 = v;
    dk__SpriteMessage__update(o);
}
}  // namespace n0028b5f0

// 0028b6f0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0028b6f0 {
/*TARGET 0028b6f0*/
void func_0028b6f0(void* a0, void* a1) asm("_Z13func_0028b6f0PvS_");
void func_0028b6f0(void* a0, void* a1) {
    u8* p0 = (u8*)a0 + 444;
    u8* p1 = (u8*)a1;
    s32 i = 0;
    for (;;) {
        u16 v = *(u16*)p1;
        i = i + 1;
        s32 c = i < 3;
        *(u16*)p0 = v;
        p1 = p1 + 2;
        if (c != 0) {
            p0 = p0 + 2;
            continue;
        }
        p0 = p0 + 2;
        break;
    }
}
}  // namespace n0028b6f0

// 0028b720 (was src/anon/tiny_auto80_queue.cpp)
namespace n0028b720 {
/*TARGET 0028b720*/
void func_0028b720(void* a0, void* a1) asm("_Z13func_0028b720PvS_");
void func_0028b720(void* a0, void* a1) {  // anim_copy3
    u8* p0 = (u8*)a0 + 450;
    u8* p1 = (u8*)a1;
    s32 i = 0;
    for (;;) {
        u16 v = *(u16*)p1;
        i = i + 1;
        s32 c = i < 3;
        *(u16*)p0 = v;
        p1 = p1 + 2;
        if (c != 0) {
            p0 = p0 + 2;
            continue;
        }
        p0 = p0 + 2;
        break;
    }
}
}  // namespace n0028b720

// 0028b750 (was src/anon/batch_w22.cpp)
namespace n0028b750 {
// --- 0028b750
extern u32 D_0035f3a0 asm("D_0035f3a0");
void func_0023f7e0(void*) asm("func_0023f7e0");
void func_0028b870(void*) asm("func_0028b870");
/*TARGET 0028b750*/
void func_0028b750(void** p) asm("func_0028b750");
void func_0028b750(void** p) {
    func_0023f7e0(p);
    *p = &D_0035f3a0;
    func_0028b870(p);
}
}  // namespace n0028b750

// 0028b788 (was src/anon/batch_w23.cpp)
namespace n0028b788 {
void LeadDataInit(void*) asm("_ZN2Tz12LeadDataInitEPv");
extern u32 D_0035f3a0 asm("D_0035f3a0");
void func_0023f7e0(void*) asm("func_0023f7e0");
void func_0028b870(void*) asm("func_0028b870");
/*TARGET 0028b788*/
void LeadDataInit(void* p) asm("_ZN2Tz12LeadDataInitEPv");
void LeadDataInit(void* p) {
    func_0023f7e0(p);
    *(void**)p = &D_0035f3a0;
    func_0028b870(p);
}
}  // namespace n0028b788

// 0028b7c0 (was gap, written for the unit)
namespace n0028b7c0 {
void func_0028b8a0(void*) asm("func_0028b8a0");
u8 func_0023f820(void*) asm("func_0023f820");
extern u8 D_0035f3a0 asm("D_0035f3a0");
u8 func_0028b7c0(void** p) asm("func_0028b7c0");
u8 func_0028b7c0(void** p) {
    *p = &D_0035f3a0;
    func_0028b8a0(p);
    return func_0023f820(p);
}
}  // namespace n0028b7c0

// 0028b7f8 (was src/anon/batch_w13.cpp)
namespace n0028b7f8 {
void func_0028b8a0(void*) asm("func_0028b8a0");
u8 func_0023f820(void*) asm("func_0023f820");
extern void (*D_0035e380[])(void) asm("D_0035e380");
extern u8 D_0035f3a0 asm("D_0035f3a0");
/*TARGET 0028b7f8*/
u8 func_0028b7f8(void** p) asm("func_0028b7f8");
u8 func_0028b7f8(void** p) {
    *p = &D_0035f3a0;
    func_0028b8a0(p);
    return func_0023f820(p);
}
}  // namespace n0028b7f8

// 0028b830 (was src/anon/batch_w14.cpp)
namespace n0028b830 {
// set_vtbl_347b88
void func_00106420(void*) asm("func_00106420");
void func_0028b8a0(void*) asm("func_0028b8a0");
void func_0023f820(void*) asm("func_0023f820");
extern u8 D_0035f3a0[] asm("D_0035f3a0");
/*TARGET 0028b830*/
void func_0028b830(u8* p) asm("func_0028b830");
void func_0028b830(u8* p) {
    *(u8**)p = D_0035f3a0;
    func_0028b8a0(p);
    func_0023f820(p);
    func_00106420(p);
}
}  // namespace n0028b830

// 0028b870 (was src/anon/tiny_auto80_solver.cpp)
namespace n0028b870 {
u32 func_0023f8a8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0023f8a8jjjjjjjj");
u32 func_0028b870(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0028b870jjjjjjjj");
/*TARGET 0028b870*/
u32 func_0028b870(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0028b870jjjjjjjj");
u32 func_0028b870(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0023f8a8)(r4, r5, r6, r7, r8, r9, r10, r11);
    *(u32*)((u32)r16 + (s32)(28)) = 0u;
    *(volatile u32*)((u32)r16 + (s32)(32)) = 0u;
    return r2;
}
}  // namespace n0028b870

// 0028b8a0 (was src/anon/tiny_auto80_solver.cpp)
namespace n0028b8a0 {
u32 func_0023f8c8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0023f8c8jjjjjjjj");
u32 func_0028b8a0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0028b8a0jjjjjjjj");
/*TARGET 0028b8a0*/
u32 func_0028b8a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0028b8a0jjjjjjjj");
u32 func_0028b8a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0023f8c8)(r4, r5, r6, r7, r8, r9, r10, r11);
    *(u32*)((u32)r16 + (s32)(28)) = 0u;
    *(volatile u32*)((u32)r16 + (s32)(32)) = 0u;
    return r2;
}
}  // namespace n0028b8a0

// 0028b8d0 (was src/anon/misc_2.cpp)
namespace n0028b8d0 {
/*TARGET 0028b8d0*/
s32 func_0028b8d0(void* self) asm("_Z13func_0028b8d0Pv");
s32 func_0028b8d0(void* self) { return (s32)(*(s32*)((char*)self + 28)); }
}  // namespace n0028b8d0

// 0028b8d8 (was src/anon/misc_2.cpp)
namespace n0028b8d8 {
/*TARGET 0028b8d8*/
s32 func_0028b8d8(void* self) asm("_Z13func_0028b8d8Pv");
s32 func_0028b8d8(void* self) { return (s32)(*(s32*)((char*)self + 32)); }
}  // namespace n0028b8d8

// 0028b8e0 (was src/anon/auto80_199_queue.cpp)
namespace n0028b8e0 {
/*TARGET 0028b8e0*/
void func_0028b8e0(Obj_0028b8e0* self) asm("_Z13func_0028b8e0P12Obj_0028b8e0");
void func_0028b8e0(Obj_0028b8e0* self) {
    func_0023fa08((u32)self);
    func_00168aa0(self->field4, 37);

    u32 p0 = func_00168b38(self->field4, 37, 0);  // entry_array_find_nth
    self->field28 = *(u32*)(p0 + 8);

    u32 p1 = func_00168b38(self->field4, 37, 1);  // entry_array_find_nth
    self->field32 = *(u32*)(p1 + 8);
}
}  // namespace n0028b8e0

// 0028b940 (was src/anon/batch_w40.cpp)
namespace n0028b940 {
struct VObj28 { struct VT { u32 (*f0)(VObj28*, u32, u32); }* vt; };
struct G28 { u8 pad[20]; VObj28* o; };
extern G28* D_00347f80 asm("D_00347f80");
void func_0028dfe8(u32) asm("func_0028dfe8");
/*TARGET 0028b940*/
// obj_ctor_36f440
void func_0028b940(u32* p) asm("func_0028b940");
// obj_ctor_36f440
void func_0028b940(u32* p) {
    VObj28* o = D_00347f80->o;
    u32 v = o->vt->f0(o, 60, 0);
    func_0028dfe8(v);  // obj_ctor_36f440
    p[0] = v;
    p[1] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    p[12] = 0;
}
}  // namespace n0028b940

// 0028b9b0 (was src/anon/batch_w41.cpp)
namespace n0028b9b0 {
struct W41VA { u32 (**vt)(W41VA*, u32, u32); };
struct W41SysA { u8 pad[0x14]; W41VA* alloc; };
extern W41SysA* D_00347f80_sys asm("D_00347f80");
void func_0028dfe8(u32) asm("func_0028dfe8");
/*TARGET 0028b9b0*/
// obj_ctor_36f440
void func_0028b9b0(u32* p) asm("func_0028b9b0");
// obj_ctor_36f440
void func_0028b9b0(u32* p) {
    W41VA* a = D_00347f80_sys->alloc;
    u32 v = a->vt[0](a, 60, 0);
    func_0028dfe8(v);  // obj_ctor_36f440
    p[0] = v;
    p[1] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    p[12] = 0;
}
}  // namespace n0028b9b0

// 0028ba20 (was src/anon/auto80_199_queue.cpp)
namespace n0028ba20 {
/*TARGET 0028ba20*/
void func_0028ba20(Obj_0028ba20* self) asm("_Z13func_0028ba20P12Obj_0028ba20");
void func_0028ba20(Obj_0028ba20* self) {
    Obj_0028ba20* s0 = self;

    if (func_0028be58((u32)s0) != 0) {
        u32 p = s0->field0;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 20)))(p);
    }

    {
        u32 p = s0->field0;
        if (p != 0) {
            ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
            s0->field0 = 0;
        }
    }
}
}  // namespace n0028ba20

// 0028ba80 (was src/anon/auto80_199_queue.cpp)
namespace n0028ba80 {
/*TARGET 0028ba80*/
void func_0028ba80(Obj_0028ba80* self) asm("_Z13func_0028ba80P12Obj_0028ba80");
void func_0028ba80(Obj_0028ba80* self) {
    Obj_0028ba80* s0 = self;

    if (func_0028be58((u32)s0) != 0) {
        u32 p = s0->field0;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 20)))(p);
    }

    {
        u32 p = s0->field0;
        if (p != 0) {
            ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
            s0->field0 = 0;
        }
    }
}
}  // namespace n0028ba80

// 0028bae0 (was src/anon/batch_w119.cpp)
namespace n0028bae0 {
struct Gauge {
    u8* lay;
    u8* link;
    u16 tbl[3][4];
    s32 maxv;
    s32 cur;
    s32 f40;
    s32 w0;
    s32 w1;
};
void func_0028be58(Gauge*) asm("func_0028be58");
void func_0028e0d8(u8*, s32, s32, s32, u16*, s32, s32) asm("func_0028e0d8");
void func_0028e5e0(u8*, u16*, s32) asm("func_0028e5e0");
u8* func_0028e798(u8*, s32) asm("func_0028e798");
s32 func_0023aa58(u8*) asm("func_0023aa58");
double func_00313b80(f32) asm("func_00313b80");
// float_to_double
s32 func_003142e0(double, double) asm("func_003142e0");
// double_compare
void func_0028e748(u8*, s32, u8*) asm("func_0028e748");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
void func_0028e710(u8*, u8*) asm("func_0028e710");
void func_0028e870(u8*, s32, s32) asm("func_0028e870");
void func_00139660(u8*) asm("func_00139660");
void func_00139688(u8*) asm("func_00139688");
void func_0028eb88(u8*, s32, f32, f32) asm("func_0028eb88");
void func_0028e8b8(u8*, s32, s32, s32) asm("func_0028e8b8");
/*TARGET 0028bae0*/
// Gauge layout setup: copies the frame table, links the bar and scales it by cur/total (clamped to 1).
void func_0028bae0(Gauge* g, s32 a, s32 b, s32 c, u16 (*src)[4], s32 total, s32 cur, u8* link) asm("func_0028bae0");
// Gauge layout setup: copies the frame table, links the bar and scales it by cur/total (clamped to 1).
void func_0028bae0(Gauge* g, s32 a, s32 b, s32 c, u16 (*src)[4], s32 total, s32 cur, u8* link)
{
    func_0028be58(g);
    for (s32 i = 0; i < 3; i++)
        for (s32 j = 0; j < 4; j++)
            g->tbl[i][j] = src[i][j];
    func_0028e0d8(g->lay, a, b, c, g->tbl[0], 4, 0);
    func_0028e5e0(g->lay, g->tbl[2], 4);
    g->link = link;
    g->f40 = 0;
    g->cur = cur;
    g->maxv = total < cur ? cur : total;
    if (!link)
        g->w0 = func_0023aa58(func_0028e798(g->lay, 0));
    else
        g->w0 = func_0023aa58(link + 24);
    s32 w1 = func_0023aa58(func_0028e798(g->lay, 2));
    g->w1 = w1;
    f32 r = (f32)cur / (f32)total;
    if (func_003142e0(1.0, func_00313b80(r)) <= 0)
        r = 1.0f;
    f32 sc = (f32)g->w0 / (f32)w1 * r;
    if (g->link == 0) {
        u8* p = func_0028e798(g->lay, 0);
        func_0028e748(g->lay, 1, p);
        func_0028e748(g->lay, 2, p);
        func_0028e748(g->lay, 3, p);
    } else {
        s32 x = func_0023aa18(g->link + 24);
        s32 y = func_0023aa38(g->link + 24);
        func_0028e710(g->lay, g->link);
        func_0028e870(g->lay, x, y);
        func_00139660(g->lay);
        func_00139688(g->lay);
    }
    func_0028eb88(g->lay, 2, 1.0f, sc);
    func_0028e8b8(g->lay, 3, 0, (s32)((f32)g->w1 * sc));
}
}  // namespace n0028bae0

// 0028bd60 (was src/anon/auto80_199_queue.cpp)
namespace n0028bd60 {
/*TARGET 0028bd60*/
void func_0028bd60(Obj_0028bd60* self) asm("_Z13func_0028bd60P12Obj_0028bd60");
void func_0028bd60(Obj_0028bd60* self) {
    func_0028be58((u32)self);
    u32 v = func_0028e4c8(self->field0, 1);

    if ((s32)v != (s32)self->field26) {
        func_0028e560(self->field0, (u32)&self->field24, 4, -1);
    }
}
}  // namespace n0028bd60

// 0028bdb8 (was src/anon/batch_w40.cpp)
namespace n0028bdb8 {
s32 func_0028be58(u32) asm("func_0028be58");
s16 func_0028e4c8(u32, u32) asm("func_0028e4c8");
void func_0028e560(u32, void*, u32, s32) asm("func_0028e560");
void lead_data_leave(u32 a) asm("_ZN2Tz13LeadDataLeaveEj");
/*TARGET 0028bdb8*/
void lead_data_leave(u32 a) asm("_ZN2Tz13LeadDataLeaveEj");
void lead_data_leave(u32 a) {
    u32* s = (u32*)a;
    if (func_0028be58(a)) {
        if (func_0028e4c8(s[0], 0) != *(s16*)(s + 4)) func_0028e560(s[0], s + 4, 4, -1);
    }
}
}  // namespace n0028bdb8

// 0028be18 (was src/yw/scrollbar.cpp)
namespace Tz { // method 0028be18
u32 func_0028be58(...) asm("func_0028be58");
/*TARGET 0028be18*/
void ScrollBar::Leave() {
    u8* s0 = (u8*)this;
    if (func_0028be58(s0) != 0u) {
        void* obj = *(void**)s0;
        ((void (*)(void*))(*(u32*)(*(u32*)obj + 20u)))(obj);
    }
}
}  // Tz

// 0028be58 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0028be58 {
u32 func_00139d78(u32, u32, u32, u32) asm("_Z13func_00139d78jjjj");
/*TARGET 0028be58*/
u32 func_0028be58(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0028be58jjjj");
u32 func_0028be58(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = *(u32*)((u32)r4 + (s32)(0));
    u32 (*fp_call4_00139d78)(u32, u32, u32, u32) = func_00139d78;
    r2 = fp_call4_00139d78(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0028be58

