// Linked unit 0x001b6a50-0x001b82d8 (one namespace per old matched source; class methods in their own namespace).
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

// 001b6a50 (was gap, never written)
namespace n001b6a50 {
struct X { u8 p[20]; u8* f20; };
extern X* D_00351184 asm("D_00351184");
void ys_printf(const char*) asm("func_001024a8");
void YS__SHEET__add_hp(u8*, s32, s32, s32) asm("YS__SHEET__add_hp");
void YS__SHEET__add_mp(u8*, s32, s32) asm("YS__SHEET__add_mp");
void func_001b6a50(const char* m) asm("func_001b6a50");
void func_001b6a50(const char* m) {
    if (D_00351184 == 0 || D_00351184->f20 == 0) {
        ys_printf(m);
        return;
    }
    YS__SHEET__add_hp(D_00351184->f20, 6, 0, 0);
    YS__SHEET__add_mp(D_00351184->f20, 6, 0);
}
}


// 001b6ab8 (was src/anon/batch_w24.cpp)
namespace n001b6ab8 {
// 001abb28: moved to src/anon/unit_001abb28.cpp

u8* YS__SAVERAM_BATTLE__get_formram(void*, u32) asm("YS__SAVERAM_BATTLE__get_formram");
void func_001a1cc0(u32, u32, u8) asm("func_001a1cc0");
void YS__SHEET__Free(u32) asm("YS__SHEET__Free");
extern u8 D_0032e020 asm("D_0032e020");
/*TARGET 001b6ab8*/
void func_001b6ab8(u32* p) asm("func_001b6ab8");
void func_001b6ab8(u32* p) {
    if (p[5]) {
        u8* e = YS__SAVERAM_BATTLE__get_formram(&D_0032e020, p[1]);
        func_001a1cc0(p[5], p[1], e[2]);
        YS__SHEET__Free(p[5]);
        p[5] = 0;
    }
}
}  // namespace n001b6ab8

// 001b6b10 (was src/anon/batch_w90.cpp)
namespace n001b6b10 {
// 0015d5d0: moved to src/anon/unit_0015d440.cpp

// 0017e138
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
// 0x001a2340: definition moved into src/anon/unit_0019fb70.cpp

// 001b6b10
s32 YS__OBJ__is_exist(void*) asm("YS__OBJ__is_exist");
u8* func_001050d8(s32) asm("func_001050d8");
void func_001b6298(void*, void*, s32, s32) asm("func_001b6298");
void func_0016bd60(void*, s32) asm("func_0016bd60");
void YS__SACRIFICE__StartForm(s32) asm("YS__SACRIFICE__StartForm");
extern u8 D_0032f054 asm("D_0032f054");
extern u8 D_0032bb30[] asm("D_0032bb30");
/*TARGET 001b6b10*/
void func_001b6b10(u8* self, s32 id) asm("func_001b6b10");
void func_001b6b10(u8* self, s32 id)
{
    YS__OBJ__is_exist(self);
    if (id == D_0032f054) return;
    u8* o = func_001050d8(32);
    func_001b6298(o, self, id, 0);
    if (id) {
        func_0016bd60(self, 0);
        func_0017f488(self + 320, 52, 0.0f, 0.0f);
        asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(self + 32) : "memory");
        YS__SACRIFICE__StartForm(id);
    } else {
        o[28] = 1;
    }
    *(u32*)(self + 264) |= 0x100;
    D_0032bb30[13604] = id;
}
}  // namespace n001b6b10

// 001b6bd8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n001b6bd8 {
u32 func_001050d8(u32, u32, u32, u32) asm("_Z13func_001050d8jjjj");
u32 func_001b6298(u32, u32, u32, u32) asm("_Z13func_001b6298jjjj");
/*TARGET 001b6bd8*/
u32 func_001b6bd8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b6bd8jjjj");
u32 func_001b6bd8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r16, r17;
    r16 = r4;
    r17 = r5;
    r4 = (u32)((s32)0u + (32));
    u32 (*fp_call4_001050d8)(u32, u32, u32, u32) = func_001050d8;
    r2 = fp_call4_001050d8(r4, r5, r6, r7);
    r5 = r16;
    r7 = r17;
    r4 = r2;
    r6 = (u32)((s32)0u + (12));
    return func_001b6298(r4, r5, r6, r7);
}
}  // namespace n001b6bd8

// 001b6c20 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n001b6c20 {
u32 func_001050d8(u32, u32, u32, u32) asm("_Z13func_001050d8jjjj");
u32 func_001b6298(u32, u32, u32, u32) asm("_Z13func_001b6298jjjj");
/*TARGET 001b6c20*/
u32 YS__CHANGEFORM__CaptureEnd(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z26YS__CHANGEFORM__CaptureEndjjjj");
u32 YS__CHANGEFORM__CaptureEnd(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15, r16;
    r16 = r4;
    r4 = (u32)((s32)0u + (32));
    u32 (*fp_call4_001050d8)(u32, u32, u32, u32) = func_001050d8;
    r2 = fp_call4_001050d8(r4, r5, r6, r7);
    r15 = (u32)(0x0033u << 16);
    r5 = r16;
    r6 = (u32)(*(u8*)((u32)r15 + (s32)(-4012)));
    r4 = r2;
    r7 = 0u;
    return func_001b6298(r4, r5, r6, r7);
}
}  // namespace n001b6c20

// 001b6c60 (was src/anon/batch_w62.cpp)
namespace n001b6c60 {
// 0x0019bf50: definition moved into src/anon/unit_0019ba60.cpp

void func_001b0330(u32) asm("func_001b0330");
void* func_001050d8(u32) asm("func_001050d8");
void func_001b6298(void*, u8*, u32, u32) asm("func_001b6298");
extern u8 D_0032f054 asm("D_0032f054");
/*TARGET 001b6c60*/
void YS__CHANGEFORM__Dead(u8* p) asm("YS__CHANGEFORM__Dead");
void YS__CHANGEFORM__Dead(u8* p) {
    func_001b0330(*(u32*)(p + 2488));
    D_0032f054 = 0;
    func_001b6298(func_001050d8(32), p, 0, 0);
}
}  // namespace n001b6c60

// 001b6ca8 (was src/anon/tiny_wrappers_more.cpp)
namespace n001b6ca8 {
u32 YS__CHANGEFORM__exec(u32, u32, u32, u32) asm("_Z20YS__CHANGEFORM__execjjjj");
/*TARGET 001b6ca8*/
u32 func_001b6ca8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b6ca8jjjj");
u32 func_001b6ca8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return YS__CHANGEFORM__exec(((u32)(*(u32*)((u32)(a0) + 4u))), a0, a2, a3);
}
}  // namespace n001b6ca8

// 001b6cc8 (was gap, never written)
namespace n001b6cc8 {
void func_001b6518(u8*) asm("func_001b6518");
void area_free(u8*) asm("_ZN4AREA4FreeEPv");
void func_001b6cc8(u8* o) asm("func_001b6cc8");
void func_001b6cc8(u8* o) {
    struct NoTail { ~NoTail() {} } nt;
    u8* p = *(u8**)(o + 4);
    if (p) {
        func_001b6518(p);
        area_free(p);
    }
}
}

// 001b6d00 (was src/anon/batch_w22.cpp)
namespace n001b6d00 {
// 0x001af328: definition moved into src/anon/unit_001ada38.cpp

// --- 001b6d00
extern u8* D_00351184 asm("D_00351184");
extern u32 D_00351214 asm("D_00351214");
void func_00102670(u32, u32) asm("func_00102670");
/*TARGET 001b6d00*/
// to_1025f8
void func_001b6d00(void) asm("func_001b6d00");
// to_1025f8
void func_001b6d00(void) {
    if (D_00351184) {
        func_00102670(D_00351214, *(u32*)(D_00351184 + 24));  // to_1025f8
        D_00351184 = 0;
    }
}
}  // namespace n001b6d00

// 001b6d40 (was src/anon/tiny_auto80_queue.cpp)
namespace n001b6d40 {
// is_halfword42_zero


extern "C" u32 func_001c8ab0(...) asm("func_001c8ab0");
/*TARGET 001b6d40*/
u32 func_001b6d40(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001b6d40jjjjjjjj");
u32 func_001b6d40(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r15 = (u32)(0x0035u << 16);
    r14 = ((u32*)(u32)r15)[1121];
    r2 = 0u;
    if (r14 == 0u) {
        r2 = ((u32(*)())func_001c8ab0)();
        r2 = ((u32)r2 < 0x00000001u);
    }
    return r2;
}
}  // namespace n001b6d40

// 001b6d70 (was src/anon/tiny.cpp)
namespace n001b6d70 {
extern u32 D_0032fb1c asm("D_0032fb1c");
/*TARGET 001b6d70*/
// 0x001aae68: definition moved into src/anon/unit_001aaa08.cpp

u32 func_001b6d70(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b6d70jjjj");
// 0x001aae68: definition moved into src/anon/unit_001aaa08.cpp

u32 func_001b6d70(u32 a0, u32 a1, u32 a2, u32 a3) {  // table_entry_ptr_b
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_0032fb1c + ((u32)a0 << 2);
}
}  // namespace n001b6d70

// 001b6d88 (was src/anon/batch_w63.cpp)
namespace n001b6d88 {
// 00199098: moved to src/anon/unit_00198e40.cpp

// 001abe80: moved to src/anon/unit_001abb28.cpp

struct B4 { u8 c0; u8 c1; u8 c2; u8 b0 : 1; u8 rest : 7; };
/*TARGET 001b6d88*/
void func_001b6d88(B4* p, s32 a1) asm("func_001b6d88");
void func_001b6d88(B4* p, s32 a1) {
    if (a1 == 3 && p->c0 >= 3) {
        p->c0++;
        return;
    }
    p->c0 = a1;
    if (a1 == 2) p->b0 = 0;
}
}  // namespace n001b6d88

// 001b6dd0 (was src/anon/batch_w21.cpp)
namespace n001b6dd0 {
struct u128 { u32 w[4]; } __attribute__((aligned(16)));
void YS__OBJ__prepare_jump(void*, void*) asm("YS__OBJ__prepare_jump");
/*TARGET 001b6dd0*/
void func_001b6dd0(u8* p, u128* v) asm("func_001b6dd0");
void func_001b6dd0(u8* p, u128* v) {
    u128 t;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(v) : "$8", "memory");
    YS__OBJ__prepare_jump(p, &t);
    p[1300] = 3;
}
}  // namespace n001b6dd0

// 001b6e08 (was src/anon/auto80_199_queue.cpp)
namespace n001b6e08 {
/*TARGET 001b6e08*/
void YS__ACTION_FLYJUMP__start(u32 a0, u32 a1) asm("_Z25YS__ACTION_FLYJUMP__startjj");
void YS__ACTION_FLYJUMP__start(u32 a0, u32 a1) {
    (void)a0;
    u32 s0 = a1;
    *(u32*)(a1 + 0xf0) = *(u32*)(*(u32*)(a1 + 0x0c) + 4);
    YS__ACTION_JUMP__start();

    f32 f20 = func_00184a90(s0);
    f32 f1 = *(f32*)(YS__OBJ__get_pos(s0) + 4);  // obj_get_attach_or_alt
    f20 = f20 - f1;

    if (0.0f < f20) {
        f20 = func_00184a90(s0);
        f1 = f20 - *(f32*)(YS__OBJ__get_pos(s0) + 4);  // obj_get_attach_or_alt
    } else {
        f1 = 0.0f;
    }

    *(f32*)(s0 + 0xe0) = f1;
}
}  // namespace n001b6e08

// 001b6e90 (was src/anon/auto80_199_queue.cpp)
namespace n001b6e90 {
/*TARGET 001b6e90*/
void YS__ACTION_FLYJUMP__control(u32 a0, u32 a1) asm("_Z27YS__ACTION_FLYJUMP__controljj");
void YS__ACTION_FLYJUMP__control(u32 a0, u32 a1) {
    u32 s1 = a0;
    u32 s0 = a1;

    func_0017c690(s1);

    f32 f1cmp = *(f32*)(s0 + 0xd0);
    f32 f0cmp = *(f32*)(s0 + 0xd4);
    if (f0cmp <= f1cmp) {
        f32 f20 = func_00184a90(s0);
        f32 f1 = *(f32*)(YS__OBJ__get_pos(s0) + 4);  // obj_get_attach_or_alt
        f20 = f20 - f1;

        if (0.0f < f20) {
            f20 = func_00184a90(s0);
            f1 = f20 - *(f32*)(YS__OBJ__get_pos(s0) + 4);  // obj_get_attach_or_alt
        } else {
            f1 = 0.0f;
        }

        if (f1 <= *(f32*)(s0 + 0xe0)) {
            VirtCall2 fn = (VirtCall2)(*(u32*)(*(u32*)s1 + 0x14));
            fn(s1, s0);
        }
    }
}
}  // namespace n001b6e90

// 001b6f48 (was src/anon/batch_w207.cpp)
namespace n001b6f48 {
void func_0017c870(f32, f32) asm("func_0017c870");
/*TARGET 001b6f48*/
u32 func_001b6f48(u32 a) asm("func_001b6f48");
u32 func_001b6f48(u32 a) {
    func_0017c870(0.9f, 0.95f);
    return a;
}
}  // namespace n001b6f48

// 001b6f88 (was src/anon/tiny_wrappers_more.cpp)
namespace n001b6f88 {
u32 YS__ACTION_JUMP___land(u32, u32, u32, u32) asm("_Z22YS__ACTION_JUMP___landjjjj");
/*TARGET 001b6f88*/
u32 func_001b6f88(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b6f88jjjj");
u32 func_001b6f88(u32 a0, u32 a1, u32 a2, u32 a3) {
    return YS__ACTION_JUMP___land(a0, a1, ((u32)(*(u32*)((u32)(a1) + 240u))), a3);
}
}  // namespace n001b6f88

// 001b6fa0 (was src/anon/tiny.cpp)
namespace n001b6fa0 {
/*TARGET 001b6fa0*/
// 0x001afae0: definition moved into src/anon/unit_001ada38.cpp

// 001b13f0: moved to src/yasui/libys/databuff.cpp

void func_001b6fa0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b6fa0jjjj");
// 0x001afae0: definition moved into src/anon/unit_001ada38.cpp

// 001b13f0: moved to src/yasui/libys/databuff.cpp

void func_001b6fa0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d5u << 16);
    *(u32*)((u32)b + (-29516)) = (u32)a0;
}
}  // namespace n001b6fa0

// 001b6fb0 (was src/anon/batch_w1531.cpp)
namespace n001b6fb0 {
struct W1531_Tab { s32 x; s32 count; s32 tab[1]; };
// 0016d110: moved to src/anon/unit_0016c770.cpp

extern W1531_Tab* D_01d48cb4 asm("D_01d48cb4");
s32 func_001b7818(void*) asm("func_001b7818");
/*TARGET 001b6fb0*/
u8* YS__LEVELUP__Get(void* self, s32 a) asm("YS__LEVELUP__Get");
u8* YS__LEVELUP__Get(void* self, s32 a) {
    s32 n = func_001b7818(self);
    if (n == 0) n = 1;
    W1531_Tab* d = D_01d48cb4;
    if (n >= d->count || d->tab[n] == 0) n = 1;
    W1531_Tab* e = D_01d48cb4;
    s32* v = (s32*)e + e->tab[n];
    s32 m = *v;
    if (m < a) a = m;
    return (u8*)v + a * 16 - 12;
}
}  // namespace n001b6fb0

// 001b7038 (was src/anon/auto80_199_queue.cpp)
namespace n001b7038 {
/*TARGET 001b7038*/
u32 func_001b7038() asm("_Z13func_001b7038v");
u32 func_001b7038() {
    u32 t7 = 0;
    if (YS__MISSION__IsNoExp() != 0) {
        return t7;
    }

    u32 s2 = 0;
    u32 s1 = func_001a8b68(0);
    u32 s0 = D_0034e948;
    if (YS__OBJ__is_exist(s0) != 0) {
        if (func_0016a070(s0) == s1) {
            u32 v0 = func_00177860(s0);
            u32 masked = *(u32*)(v0 + 0x0c) & 0x00100000;
            s2 = (masked < 1);
        }
    }

    t7 = s2;
    return t7;
}
}  // namespace n001b7038

// 001b70d0 (was src/anon/batch_w93.cpp)
namespace n001b70d0 {
// 0x001b9db0: definition moved into src/anon/unit_001b9880.cpp

struct W93Gold { u8 pad[14048]; s32 munny; };
extern W93Gold D_0032bb30 asm("D_0032bb30");
extern u8 D_0032bae0 asm("D_0032bae0");
extern u8 D_0032e020[] asm("D_0032e020");
s32 func_001a8b68(s32) asm("func_001a8b68");
u32 YS__SAVERAM_BATTLE__get_partram(void*, s32) asm("YS__SAVERAM_BATTLE__get_partram");
u32 YS__PARTY__GetByPart(s32) asm("YS__PARTY__GetByPart");
void YS__LEVELUP__Check(s32, u32, u32) asm("YS__LEVELUP__Check");
void func_00188bb0(u32, s32) asm("func_00188bb0");
/*TARGET 001b70d0*/
// Adds munny (capped at 9,999,999) and refreshes the thirteen status panels.
void YS__LEVELUP__AddExp(s32 add) asm("YS__LEVELUP__AddExp");
// Adds munny (capped at 9,999,999) and refreshes the thirteen status panels.
void YS__LEVELUP__AddExp(s32 add)
{
    s32 v = D_0032bb30.munny + add;
    D_0032bb30.munny = v > 9999999 ? 9999999 : v;
    for (s32 i = 1; i < 14; i++) {
        s32 id = i;
        switch (i) {
        case 1: id = func_001a8b68(0); break;
        case 6: if (D_0032bae0 == 8) id = func_001a8b68(3); break;
        }
        u32 x = YS__SAVERAM_BATTLE__get_partram(D_0032e020, id);
        YS__LEVELUP__Check(id, x, YS__PARTY__GetByPart(id));
    }
    func_00188bb0(YS__SAVERAM_BATTLE__get_partram(D_0032e020, 1), 1);
}
}  // namespace n001b70d0

// 001b71e8 (was src/anon/batch_w80.cpp)
namespace n001b71e8 {
// ---- unit 2 (good1b7.cpp)
struct U2_Lvl { s32 need; };
struct U2_Grow { u8 pad[14]; u8 f14; u8 lv; };
struct U2_GrowOwn { u8 pad[1164]; u32 f1164; };
extern s32 D_0032bb30[] asm("D_0032bb30");
// test_bit_addressable
U2_Lvl* YS__LEVELUP__Get(void*, u32) asm("YS__LEVELUP__Get");
void func_001b72c0(U2_Lvl*, void*, u32, u32) asm("func_001b72c0");
void YS__LEVELUP__ShowEffect(U2_GrowOwn*) asm("YS__LEVELUP__ShowEffect");
void func_001a1460(u32) asm("func_001a1460");
/*TARGET 001b71e8*/
// level up while the experience requirement is met
void YS__LEVELUP__Check(void* o, U2_Grow* g, U2_GrowOwn* own) asm("YS__LEVELUP__Check");
// level up while the experience requirement is met
void YS__LEVELUP__Check(void* o, U2_Grow* g, U2_GrowOwn* own) {
    s32 first = 1;
    for (;;) {
        if (g->lv >= 99) return;
        if (D_0032bb30[3512] < YS__LEVELUP__Get(o, g->lv)->need) return;
        g->lv++;
        func_001b72c0(YS__LEVELUP__Get(o, g->lv), o, g->lv, g->f14);
        if (own) {
            if (first) { YS__LEVELUP__ShowEffect(own); first = 0; }
            func_001a1460(own->f1164);
        }
    }
}
}  // namespace n001b71e8

// 001b72c0 (was src/anon/batch_w99.cpp)
namespace n001b72c0 {
struct Buf1b72 { u8 b[80]; };
void func_001b74b8(Buf1b72*) asm("func_001b74b8");
void func_001b7508(Buf1b72*, s32, s32) asm("func_001b7508");
s32 func_001b73e8(u8*, u32) asm("func_001b73e8");
// compute_avg_state
void YS__ITEM__Get(u16, u32, s32) asm("YS__ITEM__Get");
void func_001b7538(Buf1b72*, u16) asm("func_001b7538");
u32 func_001a8bd0(s32) asm("func_001a8bd0");
s32 func_001a9080(u32, u32) asm("func_001a9080");
void func_001b75e8(Buf1b72*, u32, u32) asm("func_001b75e8");
/*TARGET 001b72c0*/
void func_001b72c0(u8* p, u32 b, u32 c, s32 idx) asm("func_001b72c0");
void func_001b72c0(u8* p, u32 b, u32 c, s32 idx)
{
    Buf1b72 s;
    func_001b74b8(&s);
    func_001b7508(&s, p[4] - p[-12], 0x8ade);
    func_001b7508(&s, p[5] - p[-11], 0x8adf);
    func_001b7508(&s, p[6] - p[-10], 0x8ae0);
    s32 d = func_001b73e8(p, b);  // compute_avg_state
    d -= func_001b73e8(p - 16, b);  // compute_avg_state
    func_001b7508(&s, d, 0x8ae1);
    u16 id = *(u16*)(p + idx * 2 + 8);
    if (id) {
        YS__ITEM__Get(id, b, 0);
        func_001b7538(&s, id);
    }
    if (func_001a9080(func_001a8bd0(-1), b)) func_001b75e8(&s, b, c);
}
}  // namespace n001b72c0

// 001b73e8 (was src/anon/tiny_auto80_queue.cpp)
namespace n001b73e8 {
/*TARGET 001b73e8*/
u32 func_001b73e8(u8* a0, u32 a1) asm("_Z13func_001b73e8Phj");
u32 func_001b73e8(u8* a0, u32 a1) {  // compute_avg_state
    u32* b = (u32*)0x00330000;
    u32 mode = b[-2062];
    if (mode == 3) {
        if (a1 == 1 || a1 == 14) {
            u32 v = a0[7];
            return (u32)(((s32)(v << 1) + (s32)v) >> 1);
        }
    }
    return a0[7];
}
}  // namespace n001b73e8

// 001b7428 (was src/anon/batch_w15.cpp)
namespace n001b7428 {
// 001a2a18: moved to src/anon/unit_001a28f8.cpp

void* func_001a3a78(void*) asm("func_001a3a78");
void ryj__PAX__start(void*, u32, u32, u32, u32, void*) asm("ryj__PAX__start");
/*TARGET 001b7428*/
// scan_list_by_half
void YS__LEVELUP__ShowEffect(void* p) asm("YS__LEVELUP__ShowEffect");
// scan_list_by_half
void YS__LEVELUP__ShowEffect(void* p) {
    ryj__PAX__start(func_001a3a78(p), 15, 1, 1, 10005, p);  // scan_list_by_half
}
}  // namespace n001b7428

// 001b7468 (was src/anon/batch_w16.cpp)
namespace n001b7468 {
u32 func_001a3a78(void*) asm("func_001a3a78");
void ryj__PAX__start(u32, u32, u32, u32, u32, void*) asm("ryj__PAX__start");
/*TARGET 001b7468*/
// 0x001aa940: definition moved into src/anon/unit_001a9130.cpp

void YS__LEVELUP__ShowEffectDrive(void* p) asm("YS__LEVELUP__ShowEffectDrive");
// 0x001aa940: definition moved into src/anon/unit_001a9130.cpp

void YS__LEVELUP__ShowEffectDrive(void* p) {
    ryj__PAX__start(func_001a3a78(p), 16, 1, 1, 10005, p);  // scan_list_by_half
}
}  // namespace n001b7468

// 001b74b8 (was src/yasui/libys/levelup.cpp)
namespace YS { namespace LEVELUP { // method 001b74b8
/*TARGET 001b74b8*/
INFO::INFO() {
    INFO_Layout* i = reinterpret_cast<INFO_Layout*>(this);
    i->v2 = 0;
    i->v0 = 0;
    i->v1 = 0;
}
}}  // YS::LEVELUP

// 001b74c8 (was src/anon/tiny_auto80_queue.cpp)
namespace n001b74c8 {
u32 func_00192048(...) asm("func_00192048");
/*TARGET 001b74c8*/
u32 func_001b74c8(u32 a0, u32 a1) asm("_Z13func_001b74c8jj");
u32 func_001b74c8(u32 a0, u32 a1) {
    u32* t6 = (u32*)a0;
    u32 t7 = t6[2];
    u32 s0 = t7 << 2;
    t7 = t7 + 1;
    s0 = s0 + (u32)t6;
    u32 arg = a1;
    t6[2] = t7;
    u32 v0 = func_00192048(arg);
    *(u32*)s0 = v0;
    return v0;
}
}  // namespace n001b74c8

// 001b7508 (was src/anon/tiny_auto80_queue.cpp)
namespace n001b7508 {
u32 func_001b74c8(u32 a0, u32 a1) asm("_Z13func_001b74c8jj");
/*TARGET 001b7508*/
void func_001b7508(u32 a0, s32 a1, u32 a2) asm("_Z13func_001b7508jij");
void func_001b7508(u32 a0, s32 a1, u32 a2) {
    if (a1 > 0) {
        func_001b74c8(a0, a2);
    }
}
}  // namespace n001b7508

// 001b7538 (was src/anon/auto80_199_queue.cpp)
namespace n001b7538 {
/*TARGET 001b7538*/
void func_001b7538(u32 a0, u32 a1) asm("_Z13func_001b7538jj");
void func_001b7538(u32 a0, u32 a1) {
    u32 s1 = a0;
    u32 stack_buf[8];

    if (a1 != 0) {
        YS__ITEM__MakeMessage(stack_buf, a1, -1);
        u32 v0 = func_00192048(0x8ae8);

        u32 s0 = *(u32*)(s1 + 8);
        u32 base = s1 + (s0 << 5) + 12;
        u32 out_index = (s0 << 2) + s1;
        v0 = func_00192e50(v0, base, 32, (u32)stack_buf);

        u32 next = *(u32*)(s1 + 8);
        *(u32*)(out_index + 0) = v0;
        next = next + 1;
        *(u32*)(s1 + 8) = next;
    }
}
}  // namespace n001b7538

// 001b75b0 (was src/anon/tiny_auto80_queue.cpp)
namespace n001b75b0 {
/*TARGET 001b75b0*/
u32 func_001b75b0(u32 a0, s32 a1) asm("_Z13func_001b75b0ji");
u32 func_001b75b0(u32 a0, s32 a1) {
    (void)a0;
    switch (a1) {
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 2;
    default:
        return 3;
    }
}
}  // namespace n001b75b0

// 001b75e8 (was src/anon/auto80_199_queue.cpp)
namespace n001b75e8 {
/*TARGET 001b75e8*/
u32 func_001b75e8(u32 a0, u32 a1, u32 a2) asm("_Z13func_001b75e8jjj");
u32 func_001b75e8(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s3 = a2;
    u32 s2 = func_001b77a8(s1);
    u32 t0 = func_001b75b0(s0, s1);
    return dk__LEVELUP_INFO__openChara(s2, *(u32*)(s0 + 0), *(u32*)(s0 + 4), s3, t0);
}
}  // namespace n001b75e8

// 001b7658 (was src/anon/auto80_199_queue.cpp)
namespace n001b7658 {
/*TARGET 001b7658*/
u32 func_001b7658(u32 a0, u32 a1, u32 a2) asm("_Z13func_001b7658jjj");
u32 func_001b7658(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s3 = a2;
    u32 s2 = func_001b77a8(s1);
    u32 t0 = func_001b75b0(s0, s1);
    return func_00153310(s2, *(u32*)(s0 + 0), *(u32*)(s0 + 4), s3, t0);
}
}  // namespace n001b7658

// 001b76c8 (was src/anon/auto80_199_queue.cpp)
namespace n001b76c8 {
/*TARGET 001b76c8*/
void func_001b76c8(u32 a0, u32 a1, u32 a2) asm("_Z13func_001b76c8jjj");
void func_001b76c8(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = a2;
    if (*(u32*)(a0 + 0) == 0) {
        return;
    }

    u32 out;
    if (s1 == 0) {
        out = func_001b77a8(1);
    } else {
        u32 v0 = func_001a36e0(s1);
        v0 = func_001a80c8(v0);  // table24_find_by_id
        out = func_00192048(*(u16*)(v0 + 8));
    }

    func_00153350(out, *(u32*)(s0 + 0), *(u32*)(s0 + 4), s2, s1);
}
}  // namespace n001b76c8

// 001b7768 (was src/anon/batch_w11.cpp)
namespace n001b7768 {
// 0x001b01d8: definition moved into src/anon/unit_001ada38.cpp

void* func_001b77a8(s32) asm("func_001b77a8");
void dk__LEVELUP_INFO__openSummon(void*, u32, void*) asm("dk__LEVELUP_INFO__openSummon");
/*TARGET 001b7768*/
void YS__LEVELUP__INFO__show_summon(u32* a, void* b) asm("YS__LEVELUP__INFO__show_summon");
void YS__LEVELUP__INFO__show_summon(u32* a, void* b) {
    dk__LEVELUP_INFO__openSummon(func_001b77a8(1), *a, b);
}
}  // namespace n001b7768

// OBJPART tables (retail 0x36dacc-0x36db2f)
extern "C" const u32 D_0036dacc = 0;
extern "C" const u8 D_0036dad0[32] __attribute__((aligned(4))) = { 0x00, 0x00, 0x1f, 0x85, 0x20, 0x85, 0x21, 0x85, 0x22, 0x85, 0x23, 0x85, 0x25, 0x85, 0x26, 0x85, 0x27, 0x85, 0x28, 0x85, 0x29, 0x85, 0x2a, 0x85, 0x2b, 0x85, 0x2c, 0x85, 0x2d, 0x85, 0x24, 0x85 };
extern "C" const u8 D_0036daf0[32] __attribute__((aligned(4))) = { 0x00, 0x00, 0x2a, 0x00, 0x2b, 0x00, 0x2c, 0x00, 0x38, 0x00, 0x3a, 0x00, 0x3c, 0x00, 0x73, 0x00, 0x3e, 0x00, 0x3f, 0x00, 0x40, 0x00, 0x41, 0x00, 0x42, 0x00, 0xb5, 0x00, 0x39, 0x00, 0x3b, 0x00 };
extern "C" const u8 D_0036db10[32] __attribute__((aligned(4))) = { 0x00, 0x00, 0x00, 0x00, 0x5c, 0x00, 0x5d, 0x00, 0x00, 0x00, 0x5e, 0x00, 0x60, 0x00, 0x72, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x65, 0x00, 0x66, 0x00, 0xb4, 0x00, 0x00, 0x00, 0x5f, 0x00 };

// 001b77a8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n001b77a8 {
u32 func_00192048(u32, u32, u32, u32) asm("_Z13func_00192048jjjj");
extern u8 D_0036dad0 asm("D_0036dad0");
/*TARGET 001b77a8*/
u32 func_001b77a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b77a8jjjj");
u32 func_001b77a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15;
    r15 = (u32)&D_0036dad0;
    r4 = (u32)(r4 << 1);
    r4 = (u32)(r4 + r15);
    r4 = (u32)(*(u16*)((u32)r4 + (s32)(0)));
    return func_00192048(r4, r5, r6, r7);
}
}  // namespace n001b77a8

// 001b77d0 (was src/anon/tiny.cpp)
namespace n001b77d0 {
extern u32 D_0036dad0 asm("D_0036dad0");
/*TARGET 001b77d0*/
u32 func_001b77d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b77d0jjjj");
u32 func_001b77d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return *(u16*)((u32)&D_0036dad0 + ((u32)a0 << 1) + (0));
}
}  // namespace n001b77d0

// 001b77e8 (was src/anon/tiny.cpp)
namespace n001b77e8 {
extern u32 D_0036daf0 asm("D_0036daf0");
/*TARGET 001b77e8*/
u32 func_001b77e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b77e8jjjj");
u32 func_001b77e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return *(u16*)((u32)&D_0036daf0 + ((u32)a0 << 1) + (0));
}
}  // namespace n001b77e8

// 001b7800 (was src/anon/tiny.cpp)
namespace n001b7800 {
extern u32 D_0036db10 asm("D_0036db10");
/*TARGET 001b7800*/
u32 func_001b7800(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b7800jjjj");
u32 func_001b7800(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return *(u16*)((u32)&D_0036db10 + ((u32)a0 << 1) + (0));
}
}  // namespace n001b7800

// 001b7818 (was src/anon/tiny_auto80_queue.cpp)
namespace n001b7818 {
/*TARGET 001b7818*/
s32 func_001b7818(s32 a0) asm("_Z13func_001b7818i");
s32 func_001b7818(s32 a0) {
    if ((u32)(a0 - 1) >= 15u) {
        return 0;
    }
    if (a0 == 14) {
        a0 = 1;
    } else {
        s32 t7 = 6;
        if ((a0 ^ 0xF) == 0) {
            a0 = t7;
        }
    }
    return a0;
}
}  // namespace n001b7818

// 001b7850 (was src/anon/auto80_199_queue.cpp)
namespace n001b7850 {
/*TARGET 001b7850*/
u32 func_001b7850(u32 a0, u32 a1, u32 a2) asm("_Z13func_001b7850jjj");
u32 func_001b7850(u32 a0, u32 a1, u32 a2) {
    u32 s1 = a0;
    u32 s0 = a2;
    u32 v0 = func_0018a218(a1, a2);
    u32 t6 = 0;
    if (v0 != 0) {
        u32 p = func_001050d8((v0 << 5) + 16);
        *(u32*)(p + 4) = s1;
        t6 = p;
        *(u32*)(p + 8) = s0;
        *(u32*)(p + 0) = 0;
    }
    return t6;
}
}  // namespace n001b7850

// 001b78b8 (was src/anon/tiny.cpp)
namespace n001b78b8 {
void func_00105110(void*) asm("_Z13func_00105110Pv");
/*TARGET 001b78b8*/
// 0x00195738: definition moved into src/anon/unit_00194790.cpp
// 001acda8: moved to src/anon/unit_001abb28.cpp
// 001b20f0: moved to src/anon/unit_001b1d20.cpp
void func_001b78b8(BD_VALUE* bd) asm("_Z13func_001b78b8P8BD_VALUE");
// 0x00195738: definition moved into src/anon/unit_00194790.cpp
// 001acda8: moved to src/anon/unit_001abb28.cpp
// 001b20f0: moved to src/anon/unit_001b1d20.cpp
void func_001b78b8(BD_VALUE* bd) { func_00105110(bd); }
}  // namespace n001b78b8

// 001b78d0 (was src/anon/batch_w1531.cpp)
namespace n001b78d0 {
struct W1531_Ob { u8 pad[0x7f8]; s32 flags; };
struct W1531_E32 { u8 b[32]; };
struct W1531_Lst { s32 n; W1531_Ob* o; s32 k; s32 pad; W1531_E32 arr[1]; };
s32 func_0016bba8(W1531_Ob*, s32, s32) asm("func_0016bba8");
void YS__COLLISION__set(W1531_E32*, W1531_Ob*, s32) asm("YS__COLLISION__set");
/*TARGET 001b78d0*/
void func_001b78d0(W1531_Lst* l) asm("func_001b78d0");
void func_001b78d0(W1531_Lst* l) {
    l->n = 0;
    s32 v = 0;
    if (l->o->flags & 0x400) {
        while ((v = func_0016bba8(l->o, l->k, v)) != 0) {
            YS__COLLISION__set(&l->arr[l->n], l->o, v);
            l->n++;
        }
    }
}
}  // namespace n001b78d0

// 001b7958 (was src/anon/batch_w17.cpp)
namespace n001b7958 {
/*TARGET 001b7958*/
// 001ac660: moved to src/anon/unit_001abb28.cpp

void func_001b7958(s32* p, void* v) asm("func_001b7958");
// 001ac660: moved to src/anon/unit_001abb28.cpp

void func_001b7958(s32* p, void* v) {  // add_vec_to_records
    for (s32 i = 0; i < *p; i++) {
        u8* q = (u8*)p + 32 + i * 32;
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(q), "r"(v) : "memory");
    }
}
}  // namespace n001b7958

// 001b7998 (was src/anon/batch_w51.cpp)
namespace n001b7998 {
s32 func_0018a550(void*, u32) asm("func_0018a550");
/*TARGET 001b7998*/
// state_dispatch_0_1_3

void* func_001b7998(s32* p, u32 a1) asm("func_001b7998");
// state_dispatch_0_1_3

void* func_001b7998(s32* p, u32 a1) {
    for (s32 i = 0; i < p[0]; i++) {
        u8* e = (u8*)p + 16 + i * 32;
        if (func_0018a550(e, a1)) return e;
    }
    return 0;
}
}  // namespace n001b7998

// 001b7a18 (was src/anon/batch_w86.cpp)
namespace n001b7a18 {
struct QWord { f32 v[4]; } __attribute__((aligned(16)));
static inline void Scale(QWord* d, const QWord* a, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "f"(k) : "$8", "memory");
}
static inline void SubIn(QWord* a, const QWord* b)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(a), "r"(b) : "memory");
}
struct Item { u8 p0[16]; u8 key[16]; };
struct List { s32 n; u8 p4[12]; Item items[1]; };
void* func_001b7998(void*, void*) asm("func_001b7998");
void func_0018a7d0(void*, void*, QWord*) asm("func_0018a7d0");
void YS__OBJCLSN__avoid(void*, List*, QWord*, QWord*) asm("YS__OBJCLSN__avoid");
void func_001b7958(void*, QWord*) asm("func_001b7958");
/*TARGET 001b7a18*/
// add_vec_to_records
void func_001b7a18(void* o, List* l, QWord* acc) asm("func_001b7a18");
// add_vec_to_records
void func_001b7a18(void* o, List* l, QWord* acc)
{
    QWord t;
    QWord s;
    for (s32 i = 0; i < l->n; i++) {
        void* x = func_001b7998(o, l->items[i].p0);
        if (x) {
            func_0018a7d0(x, l->items[i].p0, &t);
            YS__OBJCLSN__avoid(o, l, acc, &t);
            Scale(&s, &t, -1.0f);
            func_001b7958(o, &s);  // add_vec_to_records
            SubIn(acc, &t);
        }
    }
}
}  // namespace n001b7a18

// 001b7b10 (was src/anon/batch_w275.cpp)
namespace n001b7b10 {
struct V7b {
    f32 x, y, z, w;
    V7b() {}
    V7b(const V7b& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V7b& operator=(const V7b& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    V7b& operator+=(const V7b& o) { asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&o) : "memory"); return *this; }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
static inline V7b scl(const V7b& a, f32 n, f32 d) {
    V7b r;
    asm volatile(".set noreorder\n\tnop\n\tnop\n\tdiv.s $f0, %2, %3\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, $f0\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "f"(n), "f"(d) : "$8", "memory");
    return r;
}
struct V7e {
    f32 x, y, z, w;
    V7e() {}
    V7e(const V7e& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V7e& operator=(const V7e& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    f32 len() const { f32 r; asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory"); return r; }
} __attribute__((aligned(16)));
static inline V7e operator-(const V7e& a, const V7e& b) {
    V7e r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
s32 YS__OBJ__is_heavy(void*) asm("YS__OBJ__is_heavy");
f32 func_0016a0a0(void*) asm("func_0016a0a0");
void func_001b7958(void*, V7b*) asm("func_001b7958");
/*TARGET 001b7b10*/
// add_vec_to_records
void YS__OBJCLSN__avoid(u8* a, u8* b, V7b* src, V7b* dst) asm("YS__OBJCLSN__avoid");
// add_vec_to_records
void YS__OBJCLSN__avoid(u8* a, u8* b, V7b* src, V7b* dst) {
    if (YS__OBJ__is_heavy(*(void**)(b + 4))) {
        if (YS__OBJ__is_heavy(*(void**)(a + 4))) {
            *dst = *src;
        }
        return;
    }
    if (YS__OBJ__is_heavy(*(void**)(a + 4))) {
        *(V7b*)(*(u8**)(b + 4) + 2160) += *dst;
        func_001b7958(b, dst);  // add_vec_to_records
        dst->zero();
        return;
    }
    f32 ma = func_0016a0a0(*(void**)(a + 4));
    f32 mb = func_0016a0a0(*(void**)(b + 4));
    V7b v;
    v = scl(*dst, ma, ma + mb);
    *dst = scl(v, mb, ma);
    *(V7b*)(*(u8**)(b + 4) + 2160) += v;
    func_001b7958(b, &v);  // add_vec_to_records
}
}  // namespace n001b7b10

// 001b7c80 (was src/anon/batch_wcx2.cpp)
namespace n001b7c80 {
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
struct Sp90 { f32 r; f32 h; u32 pad; f32 x, y, z; u8 pad2[8]; };
struct Obj90 { union { s32 n; f32 nf; }; u8 pad[16]; Sp90 s[1]; };
void func_00144450(f32*) asm("func_00144450");
void func_001447c0(f32*, f32, f32, f32, f32, f32, f32) asm("func_001447c0");
#define MIN90(a, b) ((a) < (b) ? (a) : (b))
/*TARGET 001b7c80*/
void YS__OBJCLSN__calc_bounding_box(Obj90* o, f32* b) asm("YS__OBJCLSN__calc_bounding_box");
void YS__OBJCLSN__calc_bounding_box(Obj90* o, f32* b)
{
    if (!o->n) {
        func_00144450(b);
        return;
    }
    func_001447c0(b, o->s[0].x - o->s[0].r, o->s[0].y - o->s[0].h, o->s[0].z - o->s[0].r,
                  o->s[0].x + o->s[0].r, o->s[0].y + o->s[0].h, o->s[0].z + o->s[0].r);
    for (s32 i = 1; i < o->n; i++) {
        Sp90* s = &o->s[i];
        b[0] = MIN90(b[0], s->x - s->r);
        b[1] = MIN90(b[1], s->y - s->h);
        b[2] = MIN90(b[2], s->z - s->r);
        b[3] = MIN90(b[3], s->x + s->r);
        b[4] = MIN90(b[4], s->y + s->h);
        b[5] = MIN90(b[5], s->z + s->r);
    }
}
}  // namespace n001b7c80

// 001b7df0 (was src/anon/batch_w47.cpp)
namespace n001b7df0 {
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
s32 YS__OBJ__is_heavy(u8*) asm("YS__OBJ__is_heavy");
u8* func_001b7998(u8*, u32) asm("func_001b7998");
void func_0018a7d0(u8*, u32, Vec4*) asm("func_0018a7d0");
/*TARGET 001b7df0*/
void func_001b7df0(u8* p, u32 b) asm("func_001b7df0");
void func_001b7df0(u8* p, u32 b) {
    if (YS__OBJ__is_heavy(*(u8**)(p + 4))) return;
    u8* v = func_001b7998(p, b);
    if (!v) return;
    Vec4 t;
    func_0018a7d0(v, b, &t);
    u8* d = *(u8**)(p + 4) + 2160;
    asm volatile("lqc2 $vf1,0(%0)\n\tlqc2 $vf2,0(%1)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)" : : "r"(d), "r"(&t) : "memory");
}
}  // namespace n001b7df0

// 001b7e68 (was src/anon/batch_w8031_nsa.c)
namespace n001b7e68 {
s32 func_00170b30(s32) asm("func_00170b30");
void func_001b7f30(void) asm("func_001b7f30");
void func_001b7f88(s32) asm("func_001b7f88");
extern u32 D_003511bc asm("D_003511bc");
extern u8 D_003511c3 asm("D_003511c3");
extern u32 D_01d48cb8 asm("D_01d48cb8");
typedef struct { u32 start; u32 end; u32 data; } Buf;
/*TARGET 001b7e68*/
void func_001b7e68(Buf* b, s32 n) asm("func_001b7e68");
void func_001b7e68(Buf* b, s32 n) {
    func_001b7f30();
    if (n != 0) {
        n++;
        if ((u32)n < 1024) {
            D_003511c3 = 0;
            if (D_003511bc < D_01d48cb8 + n * 16) func_001b7f88(n * 16);
            b->start = D_01d48cb8;
            D_01d48cb8 += n * 16;
        } else {
            b->start = func_00170b30(n * 16);
            D_003511c3 = 1;
        }
        b->end = b->start + n * 16;
        b->data = b->start + 16;
    }
}
}  // namespace n001b7e68

// 001b7f30 (was src/anon/batch_w57.cpp)
namespace n001b7f30 {
extern void (**D_0032b914)() asm("D_0032b914");
void func_001b7f88(void) asm("func_001b7f88");
void func_00170c00(void*) asm("func_00170c00");
extern u8 D_003511c3 asm("D_003511c3");
/*TARGET 001b7f30*/
void func_001b7f30(u32* t) asm("func_001b7f30");
void func_001b7f30(u32* t) {
    if (t[0]) {
        if (D_003511c3 == 1) {
            func_001b7f88();
            func_00170c00((void*)t[0]);
        }
    }
    t[2] = 0;
    t[1] = 0;
    t[0] = 0;
}
}  // namespace n001b7f30

// 001b7f88 (was src/anon/batch_w64.cpp)
namespace n001b7f88 {
// Takes a light from the free pool, initialises it and appends it to the active list.
// 001b1928: YS::LIGHT::Create, moved to src/anon/unit_001b14d8.cpp

// ---------------------------------------------------------------------------
extern u8 D_003511c0 asm("D_003511c0");
extern u32 D_003511b8 asm("D_003511b8");
extern u32 D_01d48cb8 asm("D_01d48cb8");
void sceGsSyncPath(s32, s32) asm("sceGsSyncPath");
/*TARGET 001b7f88*/
void func_001b7f88(void) asm("func_001b7f88");
void func_001b7f88(void) {
    if (D_003511c0) {
        sceGsSyncPath(0, 0);
        D_01d48cb8 = D_003511b8;
    }
    D_003511c0 = 0;
}
}  // namespace n001b7f88

// 001b7fd0 (was src/anon/batch_w6.cpp)
namespace n001b7fd0 {
extern u8 D_003511c3 asm("D_003511c3");
extern u8 D_003511c2 asm("D_003511c2");
/*TARGET 001b7fd0*/
u32 func_001b7fd0(void) asm("func_001b7fd0");
u32 func_001b7fd0(void) {
    if (D_003511c3 != 0) return 0;
    return D_003511c2 == 1;
}
}  // namespace n001b7fd0

// 001b7ff8 (was src/anon/batch_w2.cpp)
namespace n001b7ff8 {
struct Vec16 { u32 x[4]; };
struct Cursor16 { u32 a, b; Vec16* p; };
/*TARGET 001b7ff8*/
// Advance the cursor by n 16-byte entries; returns the old position.
Vec16* func_001b7ff8(Cursor16* c, s32 n) asm("func_001b7ff8");
// Advance the cursor by n 16-byte entries; returns the old position.
Vec16* func_001b7ff8(Cursor16* c, s32 n) {  // bump_field8_alloc
    Vec16* r = c->p;
    c->p = r + n;
    return r;
}
}  // namespace n001b7ff8

// 001b8010 (was src/anon/batch_w1795_nsa.cpp)
namespace n001b8010 {
struct W1795AD { u64 data, addr; };
struct W1795Pkt { u32 f0, f4; W1795AD* ptr; };
/*TARGET 001b8010*/
// Appends A+D register writes (reg, value pairs ending with 0xffff) after a GIF tag.
void func_001b8010(W1795Pkt* p, s32 eop, ...) asm("func_001b8010");
// Appends A+D register writes (reg, value pairs ending with 0xffff) after a GIF tag.
void func_001b8010(W1795Pkt* p, s32 eop, ...) {
    va_list ap;
    W1795AD* tag = p->ptr;
    p->ptr++;
    va_start(ap, eop);
    u64 reg;
    while ((reg = va_arg(ap, u64)) != 0xffff) {
        p->ptr->data = va_arg(ap, u64);
        p->ptr->addr = reg;
        p->ptr++;
    }
    va_end(ap);
    s32 n = p->ptr - tag;
    tag->addr = 14;
    tag->data = (n - 1) | ((u64)eop << 15) | (1ull << 60);
}
}  // namespace n001b8010

// 001b80d8 (was src/anon/batch_wcx2.cpp)
namespace n001b80d8 {
// 0x001ae308: definition moved into src/anon/unit_001ada38.cpp

extern u8 D_003511c2 asm("D_003511c2");
extern u8 D_003511c0 asm("D_003511c0");
struct Pkt15 { u64* start; u32 pad; u8* cur; };
s32 func_001b7fd0(Pkt15*) asm("func_001b7fd0");
u32 func_002f35e8(s32) asm("func_002f35e8");
void func_002f3918(u32, u64*) asm("func_002f3918");
void func_003058a0(s32) asm("func_003058a0");
void sceGsSyncPath(s32, s32) asm("sceGsSyncPath");
static inline u64 Tag15(s32 qwc, s32 irq)
{
    return (s64)qwc | (u64)(s64)irq << 63 | 0x70000000;
}
/*TARGET 001b80d8*/
void func_001b80d8(Pkt15* p) asm("func_001b80d8");
void func_001b80d8(Pkt15* p)
{
    u64* s = p->start;
    if (!s) return;
    u8* e = p->cur;
    if (!((u8*)s + 16 < e)) return;
    if (D_003511c2 == 1) {
        *s = Tag15(((e - (u8*)s) >> 4) - 1, func_001b7fd0(p) != 0);
    } else {
        *s = Tag15(((e - (u8*)s) >> 4) - 1, 0);
    }
    if (func_001b7fd0(p)) {
        func_002f3918(func_002f35e8(2), p->start);
        D_003511c0 = 1;
    } else {
        func_003058a0(0);
        func_002f3918(func_002f35e8(2), p->start);
        sceGsSyncPath(0, 0);
    }
}
}  // namespace n001b80d8

// 001b81e8 (was src/anon/batch_w10.cpp)
namespace n001b81e8 {
void func_001b7f88(void) asm("func_001b7f88");
extern s32 D_003511b8 asm("D_003511b8");
extern u8 D_003511c1 asm("D_003511c1");
/*TARGET 001b81e8*/
// 0x001a1a20: definition moved into src/anon/unit_0019fb70.cpp

// 001a6c38: moved to src/anon/unit_001a6a10.cpp

// 001b26e0: moved to src/anon/unit_001b1d20.cpp

s32 func_001b81e8(void) asm("func_001b81e8");
// 0x001a1a20: definition moved into src/anon/unit_0019fb70.cpp

// 001a6c38: moved to src/anon/unit_001a6a10.cpp

// 001b26e0: moved to src/anon/unit_001b1d20.cpp

s32 func_001b81e8(void) {
    func_001b7f88();
    D_003511c1 = 1;
    return D_003511b8;
}
}  // namespace n001b81e8

// 001b8218 (was src/anon/tiny.cpp)
namespace n001b8218 {
/*TARGET 001b8218*/
void func_001b8218(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b8218jjjj");
void func_001b8218(u32 a0, u32 a1, u32 a2, u32 a3) {  // zero_global_byte_f
    u32 b = (0x0035u << 16);
    *(u8*)((u32)b + (4545)) = (u8)0;
}
}  // namespace n001b8218

// 001b8228 (was src/anon/batch_w22.cpp)
namespace n001b8228 {
// --- 001b8228
extern u8 D_003a99f0[] asm("D_003a99f0");
extern u8* D_01d48cb8 asm("D_01d48cb8");
extern u8* D_003511bc asm("D_003511bc");
extern u8* D_003511b8 asm("D_003511b8");
extern u8 D_003511c2 asm("D_003511c2");
/*TARGET 001b8228*/
void func_001b8228(void) asm("func_001b8228");
void func_001b8228(void) {
    u8* p = D_003a99f0;
    D_003511c2 = 0;
    D_003511bc = p + 16384;
    D_003511b8 = p;
    D_01d48cb8 = p;
}
}  // namespace n001b8228

// 001b8258 (was src/anon/batch_w15.cpp)
namespace n001b8258 {
extern u32 D_003511bc asm("D_003511bc");
extern u8 D_003511c2 asm("D_003511c2");
extern u32 D_003511b8 asm("D_003511b8");
extern u32 D_01d48cb8 asm("D_01d48cb8");
/*TARGET 001b8258*/
void func_001b8258(void) asm("func_001b8258");
void func_001b8258(void) {
    D_003511c2 = 1;
    D_003511bc = 0x70004000;
    D_003511b8 = 0x70000000;
    D_01d48cb8 = 0x70000000;
}
}  // namespace n001b8258

// 001b8290 (was src/anon/batch_w1668.cpp)
namespace n001b8290 {
// 001d3bc0 (static init): moved to src/anon/unit_001d35e0.cpp

extern u32 D_003511b8 asm("D_003511b8");
extern u32 D_01d48cb8 asm("D_01d48cb8");
void w1b8290(u32, u32, u32, u32) asm("_Z16wtarget_001b8290jjjj");
/*TARGET 001b8290*/
void w1b8290(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001b8290jjjj");
void w1b8290(u32 a, u32 b, u32, u32) { if (b == 0xffff && a == 1) D_01d48cb8 = D_003511b8; }
}  // namespace n001b8290

// 001b82b8 (was src/anon/tiny_wrappers_more.cpp)
namespace n001b82b8 {
u32 func_001b8290(u32, u32, u32, u32) asm("_Z13func_001b8290jjjj");
/*TARGET 001b82b8*/
u32 func_001b82b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b82b8jjjj");
u32 func_001b82b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001b8290(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n001b82b8

