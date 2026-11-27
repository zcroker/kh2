// Linked unit 0x00113628-0x00113fb0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../naka/libkn/friend_personality.hpp"
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
#include "../tozawa/help_gra.hpp"
#include "../naka/libkn/ability_info.hpp"

// 00113628 (was src/anon/tiny_auto80_solver.cpp)
namespace n00113628 {
void func_00113628(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113628jjjjjjjj");
extern u8 D_00345cf8 asm("D_00345cf8");
/*TARGET 00113628*/
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r15;
    r15 = (u32)&D_00345cf8;
    *(u32*)(r4 + 4) = r5;
    *(u32*)(r4 + 8) = r6;
    *(u32*)(r4 + 0) = r15;
    *(u32*)(r4 + 12) = 0u;
    *(u32*)(r4 + 16) = 0u;
}
}  // namespace n00113628

// 00113648 (was src/anon/tiny_auto80_solver.cpp)
namespace n00113648 {
extern u8 D_00345cf8 asm("D_00345cf8");
/*TARGET 00113648*/
void func_00113648(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113648jjjjjjjj");
void func_00113648(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r15;
    r15 = (u32)&D_00345cf8;
    *(u32*)(r4 + 4) = r5;
    *(u32*)(r4 + 8) = r6;
    *(u32*)(r4 + 0) = r15;
    *(u32*)(r4 + 12) = 0u;
    *(u32*)(r4 + 16) = 0u;
}
}  // namespace n00113648

// 00113668 (was src/anon/tiny.cpp)
namespace n00113668 {
extern u32 D_00345cf8 asm("D_00345cf8");
/*TARGET 00113668*/
// 0x0010fa58: definition moved into src/anon/unit_0010f338.cpp

void func_00113668(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00113668jjjj");
// 0x0010fa58: definition moved into src/anon/unit_0010f338.cpp

void func_00113668(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00345cf8;
}
}  // namespace n00113668

// 00113678 (gap function, not written before)
namespace g00113678 {
extern u32 D_00345cf8 asm("D_00345cf8");
/*TARGET 00113668*/
// 0x0010fa58: definition moved into src/anon/unit_0010f338.cpp

void func_00113678(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00113678");
// 0x0010fa58: definition moved into src/anon/unit_0010f338.cpp

void func_00113678(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00345cf8;
}
}  // namespace g00113678

// 00113688 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00113688 {
u32 func_00105110(u32, u32, u32, u32) asm("_Z13func_00105110jjjj");
extern u8 D_00345cf8 asm("D_00345cf8");
/*TARGET 00113688*/
// 0x00111020: definition moved into src/anon/unit_00110b00.cpp

u32 func_00113688(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00113688jjjj");
// 0x00111020: definition moved into src/anon/unit_00110b00.cpp

u32 func_00113688(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00345cf8);
    return func_00105110(a0, a1, a2, a3);
}
}  // namespace n00113688

// 001136a8 (gap function, not written before)
namespace g001136a8 {
void func_001136a8(void) asm("func_001136a8");
void func_001136a8(void) {}
}  // namespace g001136a8

// 001136b0 (was src/naka/libkn/friend_personality.cpp)
namespace kn { // method 001136b0
class Friend;
/*TARGET 001136b0*/
void FriendPersonality::setObj(Friend* v) {
    reinterpret_cast<FriendPersonalityLayout*>(this)->obj = v;
}
}  // kn

// 001136b8 (was src/anon/batch_w99.cpp)
namespace n001136b8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V10ce {
    f32 x, y, z, w;
    V10ce& operator=(const V10ce& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline V10ce operator-(const V10ce& a, const V10ce& b)
{
    V10ce r;
    asm(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct R1136 { u32 id; u8 pad[124]; };
struct E1136 { u8 pad[12]; u32 id; u32 res; u32 a; u32 b; u32 c; u32 pad2; };
struct D1136 { u8 pad[160]; s32 count; u32 off; };
struct S1136 { u32 pad[2]; u32 data; s32 count; u32 ents; };
u32 func_00114620(u32) asm("func_00114620");
u32 func_001145b0(u32) asm("func_001145b0");
#define DATA ((D1136*)s->data)
#define ENTS ((E1136*)s->ents)
/*TARGET 001136b8*/
// Links each entry to the resource record with the same id and resolves its handles.
void func_001136b8(S1136* s) asm("func_001136b8");
// Links each entry to the resource record with the same id and resolves its handles.
void func_001136b8(S1136* s)
{
    s32 i, j;
    if (!s->data) return;
    R1136* res = (R1136*)(s->data + DATA->off);
    for (i = 0; i < s->count; i++) {
        ENTS[i].res = 0;
        for (j = 0; j < DATA->count; j++) {
            if (ENTS[i].id == res[j].id) {
                ENTS[i].res = (u32)&res[j];
                break;
            }
        }
        if (ENTS[i].a) {
            u32 h = func_00114620(ENTS[i].a);
            ENTS[i].b = h;
        }
        E1136* e = (E1136*)(i * sizeof(E1136) + s->ents);
        if (e->b) e->c = func_001145b0(e->b);
    }
}
}  // namespace n001136b8

// 001137e0 (was src/anon/misc_1.cpp)
namespace n001137e0 {
/*TARGET 001137e0*/
// 00108990: moved to src/anon/unit_001085a8.cpp

s32 func_001137e0(void* self) asm("_Z13func_001137e0Pv");
// 00108990: moved to src/anon/unit_001085a8.cpp

s32 func_001137e0(void* self) { return (s32)(*(s32*)((char*)self + 12)); }
}  // namespace n001137e0

// 001137e8 (was src/anon/misc_1.cpp)
namespace n001137e8 {
/*TARGET 001137e8*/
s32 func_001137e8(void* self) asm("_Z13func_001137e8Pv");
s32 func_001137e8(void* self) { return (s32)(*(s32*)((char*)self + 16)); }
}  // namespace n001137e8

// 001137f0 (was src/anon/tiny_auto80_queue.cpp)
namespace n001137f0 {
/*TARGET 001137f0*/
u32 func_001137f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001137f0jjjjjjjj");
u32 func_001137f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = *(u32*)((u32)r4 + (s32)(8));
    r2 = 0u;
    if (r15 != 0u) {
        r2 = *(u32*)((u32)r15 + (s32)(168));
    }
    return r2;
}
}  // namespace n001137f0

// 00113808 (was src/anon/batch_w20.cpp)
namespace n00113808 {
/*TARGET 00113808*/
// 00105da8: moved to src/common/shop.cpp

// Returns the i-th 32-byte entry of the table hanging off p->f8, or 0 when out of range.
u8* func_00113808(u8* p, s32 i) asm("func_00113808");
// 00105da8: moved to src/common/shop.cpp

// Returns the i-th 32-byte entry of the table hanging off p->f8, or 0 when out of range.
u8* func_00113808(u8* p, s32 i) {
    u8* h = *(u8**)(p + 8);
    if (!h) return 0;
    if (i < 0 || i >= *(s32*)(h + 0xa8)) return 0;
    return h + *(s32*)(h + 0xac) + i * 32;
}
}  // namespace n00113808

// 00113848 (was src/anon/batch_wcx2.cpp)
namespace n00113848 {
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Rec20 { u32 w[5]; };
u32 func_0010f8c0(u32 a0) asm("func_0010f8c0");
// test_field2940_bit2
void func_0010f880(f32 a0, f32 a1, u32 a2) asm("func_0010f880");
u32 func_0010f8e0(u32 a0) asm("func_0010f8e0");
// get_bit3_of_field2940
f32 func_0010f8a8(u32 a0) asm("func_0010f8a8");
// get_float_3284
u32 func_0010ef48(u32 a0) asm("func_0010ef48");
u32 func_0010f9e0(u32 a0, u32 a1) asm("func_0010f9e0");
u32 func_0010cc80(u32 a0) asm("func_0010cc80");
u8* func_0010cc70(u32 a0) asm("func_0010cc70");
void YS__OBJ__set_wish_dir(u32, Vec4*) asm("YS__OBJ__set_wish_dir");
// obj_set_float1644_from_pair
void YS__OBJ__get_dir(Vec4*, u8*) asm("YS__OBJ__get_dir");
void func_0010f9f0(u32, Vec4*, s32) asm("func_0010f9f0");
/*TARGET 00113848*/
u8 func_00113848(u32 param_1, u32 param_2, Rec20* param_3, u32* param_4, u8 param_5) asm("func_00113848");
u8 func_00113848(u32 param_1, u32 param_2, Rec20* param_3, u32* param_4, u8 param_5) {
    if (param_5 != 0) {
        *param_4 = 0;
        u32 o = *(u32*)(param_1 + 4);
        param_3->w[0] = *(u32*)(o + 2548);
        param_3->w[1] = *(u32*)(o + 2552);
        param_3->w[2] = *(u32*)(o + 2556);
        param_3->w[3] = *(u32*)(o + 2560);
        param_3->w[4] = *(u32*)(o + 2564);
        if (func_0010f8c0(*(u32*)(param_1 + 4)) != 0) {  // test_field2940_bit2
            if (func_0010f8e0(*(u32*)(param_1 + 4)) != 0) {  // get_bit3_of_field2940
                return 0;
            }
            if (func_0010f8a8(*(u32*)(param_1 + 4)) <= 0.0f) {  // get_float_3284
                return 0;
            }
        } else if (func_0010f9e0(*(u32*)(param_1 + 4), param_2) != 0) {
            return 0;
        }
        return (u8)(func_0010ef48(*(u32*)(param_1 + 4)) ^ 1);
    }

    if (func_0010f8c0(*(u32*)(param_1 + 4)) == 0) {  // test_field2940_bit2
        u32 obj = *(u32*)(param_1 + 8);
        f32 f12 = *(f32*)(obj + 112);
        f32 f13 = *(f32*)(obj + 116);
        func_0010f880(f12, f13, *(u32*)(param_1 + 4));
    }
    Vec4 v;
    if (func_0010cc80(*(u32*)(param_1 + 4)) != 0) {
        u8* q = func_0010cc70(*(u32*)(param_1 + 4));
        // 128-bit copy (hand-written lq/sq)
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&v), "r"(q + 32) : "$8", "memory");
        YS__OBJ__set_wish_dir(*(u32*)(param_1 + 4), &v);  // obj_set_float1644_from_pair
    }
    YS__OBJ__get_dir(&v, *(u8**)(param_1 + 4));
    *(u32*)&v.w = 0;
    func_0010f9f0(*(u32*)(param_1 + 4), &v, 0);
    return 1;
}
}  // namespace n00113848

// 00113990 (was src/anon/auto80_199_queue.cpp)
namespace n00113990 {
// 0x0010fa68: definition moved into src/anon/unit_0010f338.cpp

void func_00110630(u8* a0) asm("_Z13func_00110630j");
/*TARGET 00113990*/
// 0x001132d8: definition moved into src/anon/unit_001117d8.cpp

u8 func_00113990(u32 param_1, u32 param_2, u32 param_3, u32* param_4, u8 param_5) asm("_Z13func_00113990jjjPjh");
// 0x001132d8: definition moved into src/anon/unit_001117d8.cpp

u8 func_00113990(u32 param_1, u32 param_2, u32 param_3, u32* param_4, u8 param_5) {
    (void)param_2;
    (void)param_3;

    if (param_5 != 0) {
        *param_4 = 0;
        if (func_0010f8c0(*(u32*)(param_1 + 4)) != 0) {  // test_field2940_bit2
            if (func_0010f8e0(*(u32*)(param_1 + 4)) != 0) {  // get_bit3_of_field2940
                return 0;
            }
            if (func_0010f8a8(*(u32*)(param_1 + 4)) <= 0.0f) {  // get_float_3284
                return 0;
            }
        }
        return (u8)(func_0010ef48(*(u32*)(param_1 + 4)) ^ 1);
    }

    if (func_0010f8c0(*(u32*)(param_1 + 4)) == 0) {  // test_field2940_bit2
        u32 obj = *(u32*)(param_1 + 8);
        f32 f12 = *(f32*)(obj + 0x78);
        f32 f13 = *(f32*)(obj + 0x7c);
        func_0010f880(f12, f13, *(u32*)(param_1 + 4));
    }
    func_00110630(*(u32*)(param_1 + 4));
    return 1;
}
}  // namespace n00113990

// 00113a40 (gap function, not written before)
namespace g00113a40 {
struct St5 { s32 a, b, c, d, e; };
struct Inner { u8 pad[0x300]; u8 sub[0x6f4]; St5 st; };
struct Owner { u32 x0; Inner* in; };
struct Req { u8 pad[0x10]; s32 id; };
u8 func_0010f448(Inner*, Req*, s32, s32) asm("func_0010f448");
void func_00110630(Inner*) asm("func_00110630");
void func_0010cae8(Inner*, s32) asm("func_0010cae8");
u8 func_00113a40(Owner* o, Req* a, St5* st, s32* out, u8 mode) asm("func_00113a40");
u8 func_00113a40(Owner* o, Req* a, St5* st, s32* out, u8 mode) {
    if (!a || !a->id) return 0;
    if (mode) {
        *out = 0;
        *st = o->in->st;
        return func_0010f448(o->in, a, 1, 1);
    }
    func_00110630(o->in);
    func_0010cae8(o->in, a->id);
    return 1;
}
}


// 00113af0, 00113d70 (never written before): pick a target for an ability. With mode set they fill the
// target from the owner's lock-on, the party leader and the owner's partner (each only within 0.45 and
// while the target is still empty), then try the ability ids of one table row (row 1 when at least two
// candidates were found) and store the first usable id in *out. With mode clear they apply *out.
namespace g00113af0 {
struct Tgt { u32 w[5]; };
struct Owner { u32 x0; void* in; };
struct Req;
extern "C" const f32 D_0036a57c = 0.0f;
extern u32 D_00345ca8[2][5] asm("D_00345ca8");
extern u32 D_00345cd0[2][4] asm("D_00345cd0");
void* func_0010fb08(void*) asm("func_0010fb08");
void func_00190128(Tgt*) asm("func_00190128");
s32 func_00190140(Tgt*) asm("func_00190140");
void func_00190878(Tgt*, void*, s32) asm("func_00190878");
s32 func_0010f6b8(void*, f32) asm("func_0010f6b8");
s32 func_0010f6f8(void*, f32) asm("func_0010f6f8");
void* func_00111e38(s32) asm("func_00111e38");
void* func_00111e20(void*) asm("func_00111e20");
u8* func_00112570(void*) asm("func_00112570");
s32 func_001145b0(u32) asm("func_001145b0");
s32 kn__Friend__canItemAction(void*, u32) asm("kn__Friend__canItemAction");
void func_0010cbc8(void*, s32, u32, s32) asm("func_0010cbc8");
static inline bool IsValid(Tgt* s) {
    bool ok = false;
    if (func_00190140(s)) ok = s->w[0] != 0;
    return ok;
}
u8 func_00113af0(Owner* o, Req* a, Tgt* t, s32* out, u8 mode) asm("func_00113af0");
u8 func_00113af0(Owner* o, Req* a, Tgt* t, s32* out, u8 mode) {
    static const f32 kRange = 0.45f;
    static const s32 kNum = 5;
    if (mode) {
        u32 id = 0;
        s32 n = 0;
        void* lock = func_0010fb08(o->in);
        *out = 0;
        func_00190128(t);
        func_00190878(t, lock, 0);
        if (func_0010f6b8(o->in, kRange)) {
            if (!IsValid(t)) func_00190878(t, o->in, 0);
            n++;
        }
        void* p = func_00111e38(0);
        if (func_0010f6b8(p, kRange)) {
            if (!IsValid(t)) func_00190878(t, p, 0);
            n++;
        }
        p = func_00111e20(o->in);
        if (p && func_0010f6b8(p, kRange)) {
            if (!IsValid(t)) func_00190878(t, p, 0);
            n++;
        }
        if (IsValid(t)) {
            s32 row = n >= 2;
            u8* tab = func_00112570(o->in);
            s32 k = row * 5;
            u32* e = (u32*)D_00345ca8 + k;
            for (s32 i = 0; i < kNum; i++) {
                s32 lv = tab[func_001145b0(e[i]) + 1];
                if (lv < 2 || lock) {
                    if (kn__Friend__canItemAction(o->in, e[i])) {
                        id = e[i];
                        break;
                    }
                }
            }
        }
        *out = id;
        return id != 0;
    }
    u32 w = t->w[0];
    func_0010cbc8(o->in, *out, w, 1);
    return 1;
}
u8 func_00113d70(Owner* o, Req* a, Tgt* t, s32* out, u8 mode) asm("func_00113d70");
u8 func_00113d70(Owner* o, Req* a, Tgt* t, s32* out, u8 mode) {
    static const f32 kRange = 0.45f;
    static const s32 kNum = 4;
    if (mode) {
        f32 range = kRange;
        u32 id = 0;
        s32 n = 0;
        void* lock = func_0010fb08(o->in);
        *out = 0;
        func_00190128(t);
        if (func_0010f6f8(o->in, range)) {
            func_00190878(t, o->in, 0);
            n++;
        }
        void* p = func_00111e38(0);
        if (func_0010f6f8(p, range)) {
            if (!IsValid(t)) func_00190878(t, p, 0);
            n++;
        }
        p = func_00111e20(o->in);
        if (p && func_0010f6f8(p, kRange)) {
            if (!IsValid(t)) func_00190878(t, p, 0);
            n++;
        }
        if (IsValid(t)) {
            s32 row = n >= 2;
            u8* tab = func_00112570(o->in);
            s32 k = row * 4;
            u32* e = (u32*)D_00345cd0 + k;
            for (s32 i = 0; i < kNum; i++) {
                s32 lv = tab[func_001145b0(e[i]) + 1];
                if (lv < 2 || lock) {
                    if (kn__Friend__canItemAction(o->in, e[i])) {
                        id = e[i];
                        break;
                    }
                }
            }
        }
        *out = id;
        return id != 0;
    }
    u32 w = t->w[0];
    func_0010cbc8(o->in, *out, w, 1);
    return 1;
}
}  // namespace g00113af0
