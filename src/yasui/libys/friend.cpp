#include "../../common/types.h"

// YS::FRIEND (0x17d968-0x17e858): the party friends (Donald, Goofy, guests): construction, the two
// friend slots, the per-frame AI hooks of the FRIEND vtable (retail data at 0x34ebc8) and the file's
// static initialiser (the follow angle, 20 degrees). Incl. the never-written vtable entries 0x17dc38 and
// 0x17df40. Each function keeps the declarations of the source it was matched in (namespace fN); every
// symbol is bound by asm label.

namespace YS {
struct OBJ;
}  // namespace YS

static inline f32 Radians(f32 deg) { return deg * 0.0174532925f; }

// ---- .bss (0x1c60520)
static f32 s_followAngle asm("D_01c60520") = Radians(20.0f);
static u32 s_friend[2] asm("D_01c60528");

// 0017d968 (src/anon/batch_w98.cpp)
namespace f0 {
extern u32 D_01c60528[2] asm("D_01c60528");
extern f32 D_01c60520 asm("D_01c60520");
extern u32 D_0034ebc8[] asm("D_0034ebc8");
void func_00175670(u8*, u32, s32, u32) asm("func_00175670");
u8* func_0016a070(u8*) asm("func_0016a070");
u8* func_001a1540(u8*) asm("func_001a1540");
u8* func_0016f6a0(u32, s32) asm("func_0016f6a0");
void func_00176168(u8*, u8*, s32) asm("func_00176168");

// Constructor: registers in the 2-slot table and attaches child parts.
void func_0017d968(u8* p, u32 a, u32 b) {
    s32 i = 0;
    func_00175670(p, a, 1, b);
    *(u32*)(p + 2872) = 0;
    *(u32*)(p + 2880) = 0;
    *(u32*)(p + 2884) = 0;
    *(u32*)p = (u32)D_0034ebc8;
    *(u8*)(p + 2892) = 0;
    for (; i < 2; i++) {
        if (!D_01c60528[i]) break;
    }
    *(s32*)(p + 2888) = i;
    D_01c60528[i] = (u32)p;
    *(u32*)(p + 1416) |= 0x4000;
    u8* r = func_001a1540(func_0016a070(p));
    *(u8**)(p + 1164) = r;
    if (r) *(u8**)(r + 604) = p;
    f32 w = D_01c60520;
    *(f32*)(p + 2876) = (w + w) * i - w;
    for (i = 0; i < 2; i++) {
        u8* e = func_0016f6a0(a, i);
        if (e) func_00176168(p, e, i);
    }
    *(u32*)(p + 1896) |= 0x10;
}
}  // namespace f0

// 0017da90 (src/anon/batch_w99.cpp)
namespace f1 {
extern u8 D_0034ebc8[] asm("D_0034ebc8");
extern u32 D_01c60528[] asm("D_01c60528");
extern f32 D_01c60520 asm("D_01c60520");
void func_00175670(u8*, u32, s32, u32) asm("func_00175670");
u32 func_0016a070(u8*) asm("func_0016a070");
u8* func_001a1540(u32) asm("func_001a1540");
u32 func_0016f6a0(u32, s32) asm("func_0016f6a0");
void func_00176168(u8*, u32, s32) asm("func_00176168");

void func_0017da90(u8* p, u32 a, u32 b)
{
    s32 i = 0;
    func_00175670(p, a, 1, b);
    *(u32*)(p + 2872) = 0;
    *(u32*)(p + 2880) = 0;
    *(u32*)(p + 2884) = 0;
    *(u8**)p = D_0034ebc8;
    p[2892] = 0;
    for (; i < 2; i++) {
        if (!D_01c60528[i]) break;
    }
    *(s32*)(p + 2888) = i;
    D_01c60528[i] = (u32)p;
    *(u32*)(p + 1416) |= 0x4000;
    u8* r = func_001a1540(func_0016a070(p));
    *(u8**)(p + 1164) = r;
    if (r) *(u8**)(r + 604) = p;
    f32 c = D_01c60520;
    *(f32*)(p + 2876) = (c + c) * (f32)i - c;
    for (i = 0; i < 2; i++) {
        u32 v = func_0016f6a0(a, i);
        if (v) func_00176168(p, v, i);
    }
    *(u32*)(p + 1896) |= 0x10;
}
}  // namespace f1

// 0017dbb8 (src/anon/batch_w28.cpp)
namespace f2 {
void func_0013ddc0(s32, void*) asm("func_0013ddc0");
void func_001758b0(void*) asm("func_001758b0");
void func_00102c18(u32, u32, void (*)(void)) asm("func_00102c18");

void func_0017dbb8(u8* p) {
    if (!(*(u32*)(p + 0x588) & 0x400000)) {
        s32 t = *(s32*)(p + 0xb48);
        if (t < 2) func_0013ddc0(t + 1, p);
    }
    func_001758b0(p);
}
}  // namespace f2

// 0017dc08 (src/anon/tiny_auto80_fptr4.cpp)
namespace f3 {
u32 func_00186008(u32, u32, u32, u32) asm("func_00186008");
extern u8 D_01c60528 asm("D_01c60528");

u32 func_0017dc08(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14, r15;
    r15 = (u32)&D_01c60528;
    r14 = *(u32*)((u32)r4 + (s32)(2888));
    r14 = (u32)(r14 << 2);
    r14 = (u32)(r14 + r15);
    *(u32*)((u32)r14 + (s32)(0)) = 0u;
    return func_00186008(r4, r5, r6, r7);
}
}  // namespace f3

// 0017dc38: virtual (FRIEND vtable): release the friend's slot, effects and target (never written before)
namespace f_dc38 {
void func_0013dde8(s32) asm("func_0013dde8");
void func_0017de70(u8*) asm("func_0017de70");
void func_001dc818(void*) asm("func_001dc818");
void func_00175928(u8*) asm("func_00175928");

void func_0017dc38(u8* o) asm("func_0017dc38");
void func_0017dc38(u8* o) {
    func_0013dde8(*(s32*)(o + 2888) + 1);
    if (*(u32*)(o + 2040) & 4) func_0017de70(o);
    void* p = *(void**)(o + 2884);
    if (p) {
        func_001dc818(p);
        *(void**)(o + 2884) = 0;
    }
    func_00175928(o);
}
}  // namespace f_dc38

// 0017dc98 (src/anon/batch_w2.cpp)
namespace f4 {
void func_0017dcc0(void*) asm("func_0017dcc0");
void func_00175af8(void*) asm("func_00175af8");
typedef void (*VFn3)(void*, u32, u32);
typedef void (*VFn1)(void*);
struct OBJ;

// YS::OBJ::VTABLE<YS::FRIEND>::pre_exec(YS::OBJ*): common pre-step + PARTY pre_exec.
void friend_pre_exec(YS::OBJ* o) asm("_ZN2YS3OBJ6VTABLEINS_6FRIENDEE8pre_execEPS0_");
void friend_pre_exec(YS::OBJ* o) {
    func_0017dcc0(o);
    func_00175af8(o);  // YS::PARTY::_OVR_pre_exec
}
}  // namespace f4

// 0017dcc0 (src/anon/batch_w287.cpp)
namespace f5 {
struct Ent253 { s16 a; s16 id; s32 pad[2]; s32* val; };
extern u8 D_0033cbb0 asm("D_0033cbb0");
void func_00197c90(void) asm("func_00197c90");
Ent253* func_00253330(u32) asm("func_00253330");
s32 func_00103550(void) asm("func_00103550");
s32 func_00103b38(void) asm("func_00103b38");
u8 func_00103428(s32) asm("func_00103428");
s32 func_00103560(void) asm("func_00103560");
void func_00103500(s32) asm("func_00103500");
s32 func_00253380(u32) asm("func_00253380");
void func_00253538(s32) asm("func_00253538");
void func_001037b8(void) asm("func_001037b8");
struct V287 {
    f32 x, y, z, w;
    V287() {}
    V287(const V287& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V287& operator=(const V287& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct R287 { f32 x, y, z; s32 w; V287 b; R287() { w = 0; } };
void func_0018a818(R287*, u8*, s32) asm("func_0018a818");
extern u8* D_00352130 asm("D_00352130");
extern f32 D_00349e10 asm("D_00349e10");
s32 func_001917b0(void) asm("func_001917b0");
void func_0017de70(u8*) asm("func_0017de70");
s32 func_001b9d40(u8*) asm("func_001b9d40");  // vtable_call_slot64_flags
s32 func_0019c090(u8*) asm("func_0019c090");  // obj_is_enabled
s32 func_001a3a78(void) asm("func_001a3a78");
s32 func_001de168(s32, s32, s32, s32, s32, s32) asm("func_001de168");  // scan_list_by_half
void func_0017f540(u8*, s32, f32, f32) asm("func_0017f540");
s32 func_0016bc20(u8*, s32, s32) asm("func_0016bc20");
V287* func_001dc5f8(s32) asm("func_001dc5f8");
void func_001dc818(s32) asm("func_001dc818");
static inline bool l287_idle(u8* o) asm("l287_idle");
static inline bool l287_flag(u8* o) { return (*(u32*)(*(u8**)(o + 12) + 8) & 2) || (*(u32*)(o + 352) & 0x40); }
static inline bool l287_idle(u8* o) {
    bool b = false;
    if (func_0019c090(o) || l287_flag(o)) b = true;
    return !b;
}

void func_0017dcc0(u8* o) {
    R287 res;
    if (*(u32*)(o + 2040) & 4) {
        f32 dt = D_00349e10;
        if (!func_001917b0()) dt *= *(f32*)(D_00352130 + 92);
        *(f32*)(o + 2880) -= dt;
        if (*(f32*)(o + 2880) <= 0.0f) func_0017de70(o);
    }
    if ((*(u32*)(o + 2040) & 4) && func_001b9d40(o)) {  // vtable_call_slot64_flags
        if (l287_idle(o)) {
            if (*(s32*)(o + 2884) == 0) *(s32*)(o + 2884) = func_001de168(func_001a3a78(), 14, 1, 1, 0, 0);  // scan_list_by_half
            func_0017f540(o + 320, 54, 0.0f, 0.0f);
            goto out;
        }
    }
    if (*(s32*)(o + 340) != 54 && *(s32*)(o + 2884)) {
        func_001dc818(*(s32*)(o + 2884));
        *(s32*)(o + 2884) = 0;
    }
out:
    if (*(s32*)(o + 2884)) {
        func_0018a818(&res, o, func_0016bc20(o, 16, -1));
        *func_001dc5f8(*(s32*)(o + 2884)) = res.b;
    }
}
}  // namespace f5

// 0017de70 (src/anon/batch_w33.cpp)
namespace f6 {
struct Cfg17d { u8 pad[88]; f32 scale; };
extern Cfg17d* D_00352130 asm("D_00352130");
struct Val17d { s32 a; s32 b; };
struct Obj17d { void** vt; u8 pad[1160]; Val17d* v; };

s32 func_0017de70(Obj17d* o) {
    return ((s32 (*)(Obj17d*, s32, s32, s32))o->vt[30])(o, (s32)((f32)o->v->b * D_00352130->scale), 0, 0);
}
}  // namespace f6

// 0017dec0 (src/anon/batch_w5.cpp)
namespace f7 {
typedef void (*VFn)(void*);
void func_00102c18(u32, u32, void (*)(void)) asm("func_00102c18");
extern "C" void func_001c9770(void) asm("func_001c9770");
extern u32 D_01c60528[2] asm("D_01c60528");
class FRIEND { public: static void Init() asm("_ZN2YS6FRIEND4InitEv"); };

void FRIEND::Init() {
    D_01c60528[0] = 0;
    D_01c60528[1] = 0;
    func_001c9770();
}
}  // namespace f7

// 0017dee8 (src/anon/auto80_199_queue.cpp)
namespace f8 {
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
u32 func_0017f488(...) asm("func_0017f488");
u32 func_0017f5e0(...) asm("func_0017f5e0");
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef u32 (*Method1)(u32);

u32 func_0017dee8(u32 a0) {
    u32 s0 = a0 + 320;
    f32 f20 = 0.0f;

    ((u32(*)(u32, u32, f32, f32))func_0017f488)(s0, 151, f20, f20);
    return ((u32(*)(u32, u32, u32, f32, f32))func_0017f5e0)(s0, 0, 0, f20, f20);
}
}  // namespace f8

// 0017df40: virtual (FRIEND vtable) forwarding to 0x17dee8 (never written before)
namespace f_df40 {
void func_0017dee8(u8*) asm("func_0017dee8");

void func_0017df40(u8* o) asm("func_0017df40");
void func_0017df40(u8* o) {
    func_0017dee8(o);
}
}  // namespace f_df40

// 0017df58 YS::FRIEND::Get (src/yasui/libys/friend.cpp)
// (a plain function bound to the method's symbol: a method named Get makes the build registry give
// YS::PARTY::Get (0x176b20) to this file)
namespace f_df58 {
extern u32 D_01c60528 asm("D_01c60528");

u32 FRIEND_Get(s32 index) asm("_ZN2YS6FRIEND3GetEi");
u32 FRIEND_Get(s32 index) { return *(u32*)((u32)&D_01c60528 + ((u32)index << 2)); }
}  // namespace f_df58

// 0017df70 (src/anon/auto80_199_queue.cpp)
namespace f10 {
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
u32 func_001a8bd0(...) asm("func_001a8bd0");
u32 func_001a8bf8(...) asm("func_001a8bf8");
u32 func_001a8b38(u32) asm("func_001a8b38");
u32 func_0017df70(u32 a0) asm("func_0017df70");
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef u32 (*Method1)(u32);

u32 func_0017df70(u32 a0) {
    u32 s0 = a0;

    u32 v0 = func_001a8bd0((u32)-1);
    v0 = func_001a8bf8(v0, s0);  // get_bits5_at

    u32 t6 = v0;
    u32 out = 0;
    if (t6 != 18) {
        return func_001a8b38(v0);
    }

    return out;
}
}  // namespace f10

// 0017dfc8 (src/anon/batch_w47.cpp)
namespace f11 {
s32 func_0017df70(void) asm("func_0017df70");
u8* func_0016e920(s32) asm("func_0016e920");
u32 func_0016f7d0(s32, u8*) asm("func_0016f7d0");

s32 func_0017dfc8(void) {
    s32 r = func_0017df70();
    if (r) {
        u8* o = func_0016e920(r);
        if (*(u16*)(o + 76) == 8) {
            if (func_0016f7d0(r, o) < 2) r = 2077;
        }
    }
    return r;
}
}  // namespace f11

// 0017e030 (src/anon/auto80_199_queue.cpp)
namespace f12 {
typedef void (*Fn0)(void);
typedef void (*Fn2)(u32, u32);
u32 func_001a2478(u32) asm("func_001a2478");
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
typedef void (*VCall4)(Obj*, u32);
void func_001762f8(u32, u32) asm("func_001762f8");
typedef void (*FnA0)(u32);
typedef void (*VirtCall)(u32 a0, u32 a1, u32 a2);
typedef void (*VirtCall2)(u32 a0, u32 a1);
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef void (*Cb)(u32);
typedef void (*Fn_001d8270)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8310)(u32 a0);
typedef void (*Fn_001d8470)(u32 a0);
typedef void (*Fn_001d8578)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8bd0)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d9288)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32 (*Func_001db610_cb)(u32, u32);
u32 fn(...) asm("fn");
typedef void (*Fn1)(u32);
typedef void (*Fn_0028e080)(u32, u32);
typedef void (*VFn)(u32);
typedef void (*VCall20)(void*);
typedef void (*VCall16)(void*);
typedef u32 (*Method1)(u32);
typedef void (*VFn73d8)(u32 a0, u8 a1, u32 a2);
typedef void (*Fn_0031d8f8)(u32, u32);
typedef void (*Fn_0031d9b8)(u32);
typedef void (*Fn_0031f968)(u32);
typedef void (*Fn_0031f9c0)(u32);
typedef void (*Fn_00321de8)(u32);
typedef void (*Fn_00321e60_dtor)(u32);
typedef void (*Fn_00321e60_mgr)(u32, u32);
typedef void (*Fn_00321ef8)(u32);
typedef void (*Fn_00321f70_dtor)(u32);
typedef void (*Fn_00321f70_mgr)(u32, u32);
typedef void (*Fn_00322008)(u32);
typedef void (*Fn_00322080_dtor)(u32);
typedef void (*Fn_00322080_mgr)(u32, u32);
typedef void (*Fn_00322118_dtor)(u32);
typedef void (*Fn_00322118_mgr)(u32, u32);
typedef void (*Fn_003221b0)(u32);
typedef void (*Fn_00322908)(u32, u32);
typedef void (*Fn_00322a98)(u32);
typedef void (*Fn_00322a10)(u32, u32);
typedef void (*Fn_00322b10_dtor)(u32);
typedef void (*Fn_00322b10_mgr)(u32, u32);
typedef void (*FnMgr)(u32, u32);

void func_0017e030(u32 a0, u32 a1) {
    u32 s2 = a0;
    u32 s1 = a1;

    u32 s0 = func_001a2478(*(u32*)(a0 + 1164));  // count_div4_compare
    func_001762f8(s2, s1);

    if (s0 == 0) {
        u32 v0 = func_001a2478(*(u32*)(s2 + 1164));  // count_div4_compare
        if (v0 != 0) {
            u32 t7 = *(u32*)(s2 + 0);
            u32 fn = *(u32*)(t7 + 84);
            ((void(*)(u32, u32, u32))fn)(s2, 9, 0);
        }
    }
}
}  // namespace f12

// 0017e0b0 (src/anon/auto80_199_queue.cpp)
namespace f13 {
typedef void (*Fn0)(void);
typedef void (*Fn2)(u32, u32);
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
typedef void (*VCall4)(Obj*, u32);
u32 func_00177860(...) asm("func_00177860");
u32 func_001b6070() asm("func_001b6070");
u32 func_0017e358(u32) asm("func_0017e358");
void func_001b5ef0(u32) asm("func_001b5ef0");
void func_00176ec8(u32) asm("func_00176ec8");
typedef void (*FnA0)(u32);
typedef void (*VirtCall)(u32 a0, u32 a1, u32 a2);
typedef void (*VirtCall2)(u32 a0, u32 a1);
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef void (*Cb)(u32);
typedef void (*Fn_001d8270)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8310)(u32 a0);
typedef void (*Fn_001d8470)(u32 a0);
typedef void (*Fn_001d8578)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8bd0)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d9288)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef void (*Fn1)(u32);
typedef void (*Fn_0028e080)(u32, u32);
typedef void (*VFn)(u32);
typedef void (*VCall20)(void*);
typedef void (*VCall16)(void*);
typedef u32 (*Method1)(u32);
typedef void (*VFn73d8)(u32 a0, u8 a1, u32 a2);
typedef void (*Fn_0031d8f8)(u32, u32);
typedef void (*Fn_0031d9b8)(u32);
typedef void (*Fn_0031f968)(u32);
typedef void (*Fn_0031f9c0)(u32);
typedef void (*Fn_00321de8)(u32);
typedef void (*Fn_00321e60_dtor)(u32);
typedef void (*Fn_00321e60_mgr)(u32, u32);
typedef void (*Fn_00321ef8)(u32);
typedef void (*Fn_00321f70_dtor)(u32);
typedef void (*Fn_00321f70_mgr)(u32, u32);
typedef void (*Fn_00322008)(u32);
typedef void (*Fn_00322080_dtor)(u32);
typedef void (*Fn_00322080_mgr)(u32, u32);
typedef void (*Fn_00322118_dtor)(u32);
typedef void (*Fn_00322118_mgr)(u32, u32);
typedef void (*Fn_003221b0)(u32);
typedef void (*Fn_00322908)(u32, u32);
typedef void (*Fn_00322a98)(u32);
typedef void (*Fn_00322a10)(u32, u32);
typedef void (*Fn_00322b10_dtor)(u32);
typedef void (*Fn_00322b10_mgr)(u32, u32);
typedef void (*FnMgr)(u32, u32);

void func_0017e0b0(u32 a0) {
    u32 s1 = a0;

    u32 v0 = func_00177860(a0);
    u32 t7 = *(u32*)(v0 + 16);
    t7 &= 0x4;
    if (t7 != 0) {
        if (func_001b6070() != 0) {
            if (func_0017e358(s1) != 0) {
                func_001b5ef0(s1);
            }
        }
    }

    func_00176ec8(s1);

    u32 s0 = *(u32*)(s1 + 300);
    v0 = func_00177860(s1);

    f32 f0 = *(f32*)(s0 + 24);
    f32 f1 = *(f32*)(v0 + 92);
    f0 = f0 * f1;
    *(f32*)(s1 + 2880) = f0;
}
}  // namespace f13

// 0017e138 (src/anon/batch_w90.cpp)
namespace f14 {
typedef s32 (*VFn)(void*);
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(void*, s32, s32, f32, f32) asm("func_0017f5e0");
u8* func_00177860(void*) asm("func_00177860");
extern u8* D_00352130 asm("D_00352130");

s32 func_0017e138(u8* self, s32 n)
{
    *(u32*)(self + 2040) &= ~4;
    u8* m = self + 320;
    if (*(s32*)(m + 20) == 54) {
        func_0017f488(m, 55, 8.0f, 0.0f);
        func_0017f5e0(m, 0, 0, 0.0f, 0.0f);
    }
    u8* p = func_00177860(self);
    f32 k = 1.0f;
    if (!(*(u32*)(p + 16) & 8)) k = *(f32*)(D_00352130 + 84);
    return (s32)((f32)n * k);
}
}  // namespace f14

// 0017e210 (src/anon/auto80_199_queue.cpp)
namespace f15 {
typedef void (*Fn0)(void);
typedef void (*Fn2)(u32, u32);
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
typedef void (*VCall4)(Obj*, u32);
void func_00185a28(u32) asm("func_00185a28");
void func_0016a2e0(u32) asm("func_0016a2e0");
typedef void (*FnA0)(u32);
typedef void (*VirtCall)(u32 a0, u32 a1, u32 a2);
typedef void (*VirtCall2)(u32 a0, u32 a1);
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef void (*Cb)(u32);
typedef void (*Fn_001d8270)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8310)(u32 a0);
typedef void (*Fn_001d8470)(u32 a0);
typedef void (*Fn_001d8578)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8bd0)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d9288)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32 (*Func_001db610_cb)(u32, u32);
u32 fn(...) asm("fn");
typedef void (*Fn1)(u32);
typedef s32 (*Cb_0028d730)(u32);
typedef void (*Fn_0028e080)(u32, u32);
typedef void (*VFn)(u32);
typedef void (*VCall20)(void*);
typedef void (*VCall16)(void*);
typedef u32 (*Method1)(u32);
typedef void (*VFn73d8)(u32 a0, u8 a1, u32 a2);
typedef void (*Fn_0031d8f8)(u32, u32);
typedef void (*Fn_0031d9b8)(u32);
typedef void (*Fn_0031f968)(u32);
typedef void (*Fn_0031f9c0)(u32);
typedef void (*Fn_00321de8)(u32);
typedef void (*Fn_00321e60_dtor)(u32);
typedef void (*Fn_00321e60_mgr)(u32, u32);
typedef void (*Fn_00321ef8)(u32);
typedef void (*Fn_00321f70_dtor)(u32);
typedef void (*Fn_00321f70_mgr)(u32, u32);
typedef void (*Fn_00322008)(u32);
typedef void (*Fn_00322080_dtor)(u32);
typedef void (*Fn_00322080_mgr)(u32, u32);
typedef void (*Fn_00322118_dtor)(u32);
typedef void (*Fn_00322118_mgr)(u32, u32);
typedef void (*Fn_003221b0)(u32);
typedef void (*Fn_00322908)(u32, u32);
typedef void (*Fn_00322a98)(u32);
typedef void (*Fn_00322a10)(u32, u32);
typedef void (*Fn_00322b10_dtor)(u32);
typedef void (*Fn_00322b10_mgr)(u32, u32);
typedef void (*FnMgr)(u32, u32);

void func_0017e210(u32 a0) {
    u32 s0 = a0 + 2800;
    s32 s1 = 1;
    u32 s2 = a0;

    do {
        u32 t7 = *(u32*)(s0 + 8);
        if (t7 != 0) {
            func_00185a28(t7);
            *(u32*)(s0 + 8) = 0;
        }
        s1 -= 1;
        s0 += 4;
    } while (s1 >= 0);

    u32 t6 = *(u32*)(s2 + 0);
    u32 fn = *(u32*)(t6 + 40);
    ((void(*)(u32))fn)(s2);

    func_0016a2e0(s2);
}
}  // namespace f15

// 0017e280 (src/anon/batch_w61.cpp)
namespace f16 {
s32 func_0019ba60(void*) asm("func_0019ba60");
s32 func_0019c6f0(void*) asm("func_0019c6f0");
u8* func_001b9bc8(u8*) asm("func_001b9bc8");

s32 func_0017e280(u8* a0) {
    if (!func_0019ba60(a0) || (*(u32*)(a0 + 352) & 0x4000) || func_0019c6f0(a0)) return 0;
    u8* n = 0;
    while ((n = func_001b9bc8(n))) {
        if (!(*(u32*)(n + 1416) & 0x40) && *(u8**)(n + 1392) == a0) return 0;
    }
    return 1;
}
}  // namespace f16

// 0017e310 (src/anon/tiny_auto80_queue.cpp)
namespace f17 {
typedef u32  (*Fn_002cf1b8)(u32, u32);
extern "C" u32 func_0017e280(...) asm("func_0017e280");

u32 func_0017e310(u32 a0) {
    u32 s0 = a0;
    u32 s1 = 0u;
    if (func_0017e280(a0) != 0u) {
        u32 t7 = *(volatile u32*)((u32)s0 + (s32)(2040));
        t7 = (u32)(t7 & 4u);
        s1 = (u32)(t7 < 1u);
    }
    return s1;
}
}  // namespace f17

// 0017e358 (src/anon/batch_w36.cpp)
namespace f18 {
s32 func_0017e310(u32) asm("func_0017e310");
u32 func_001a8bd0(s32) asm("func_001a8bd0");
u32 func_0016a070(u32) asm("func_0016a070");
s32 func_001a90a8(u32, u32) asm("func_001a90a8");

s32 func_0017e358(u32 a) {
    s32 r = 0;
    if (func_0017e310(a)) {
        u32 x = func_001a8bd0(-1);
        r = func_001a90a8(x, func_0016a070(a)) == 0;
    }
    return r;
}
}  // namespace f18

// 0017e3b8 (src/anon/auto80_199_queue.cpp)
namespace f19 {
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
u32 func_001a8bd0(...) asm("func_001a8bd0");
u32 func_0016a070(...) asm("func_0016a070");
u32 func_001a90a8(u32, u32) asm("func_001a90a8");
u32 func_0017e280(u32) asm("func_0017e280");
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef u32 (*Method1)(u32);

u32 func_0017e3b8(u32 a0) {
    u32 s1 = a0;
    u32 s0 = 0;

    if (func_0017e280(s1) != 0) {
        u32 v0 = func_001a8bd0((u32)-1);
        s0 = v0;
        v0 = func_0016a070(s1);
        v0 = func_001a90a8(s0, v0);
        s0 = (u32)(v0 < 1);
    }

    return s0;
}
}  // namespace f19

// 0017e418 (src/anon/batch_w82.cpp)
namespace f20 {
extern u8 D_0032bb30[] asm("D_0032bb30");
void func_001c97b0(u16, f32) asm("func_001c97b0");
u32 func_001c88a8(u32, f32) asm("func_001c88a8");
s32 func_001c9958(u8, u16) asm("func_001c9958");  // state_pair_check
void* func_001050d8(u32) asm("func_001050d8");
void func_0010c078(void*, u8*, u32, f32) asm("func_0010c078");

u32 func_0017e418(u8* a0, u32 a1, f32 f)
{
    void* p;
    if (D_0032bb30[13605]) {
        func_001c97b0(*(u16*)(a0 + 76), 15.0f);
        return func_001c88a8(a1, f);
    }
    if (func_001c9958(D_0032bb30[13604], *(u16*)(a0 + 76))) {  // state_pair_check
        func_001c97b0(*(u16*)(a0 + 76), 15.0f);
        return 0;
    }
    p = func_001050d8(3328);
    func_0010c078(p, a0, a1, f);
    return (u32)p;
}
}  // namespace f20

// 0017e4f8 (src/anon/batch_w1893_g.cpp)
namespace f21 {
struct V1893 {
    f32 x, y, z, w;
    V1893() {}
    V1893(const V1893& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V1893& operator=(const V1893& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V1893 operator-(const V1893& b) const {
        V1893 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
extern u32 D_0034e948 asm("D_0034e948");
s32 func_0016e920(void) asm("func_0016e920");
V1893* func_0016c028(u32) asm("func_0016c028");
s32 func_001a75d8(V1893*, V1893*, s32) asm("func_001a75d8");
V1893 func_001a7888(V1893*, s32, f32, f32) asm("func_001a7888");
s32 func_001050d8(s32) asm("func_001050d8");
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");
void func_0010c078(f32, s32, s32, V1893*) asm("func_0010c078");

s32 func_0017e4f8(void* a, V1893* t, f32 h, f32 x, f32 y) {
    V1893 p;
    V1893 q;
    V1893 r;
    V1893* pq = &q;
    if (a == 0) return 0;
    s32 k = func_0016e920();
    p = *func_0016c028(D_0034e948);
    p.y -= h;
    if (t != 0) {
        *pq = *t;
        pq->y -= h;
        if (func_001a75d8(&p, pq, 0x10000)) {
            *pq = *t;
            goto done;
        }
    }
    *pq = func_001a7888(&p, 0x10000, x, y);
done:
    r = p - *pq;
    s32 o = func_001050d8(0xd00);
    func_0010c078(func_002f8ad0(r.x, r.z), o, k, pq);
    return o;
}
}  // namespace f21

// 0017e668 (src/anon/auto80_199_queue.cpp)
namespace f22 {
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
u32 func_0016a070(...) asm("func_0016a070");
u32 func_0017df58(u32) asm("func_0017df58");
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef s32 (*Cb_0028d730)(u32);
typedef u32 (*Method1)(u32);

u32 func_0017e668(u32 a0) {
    u32 s1 = 0;
    u32 s2 = a0;

    do {
        u32 v0 = func_0017df58(s1);
        s1 += 1;
        u32 s0 = v0;

        if (v0 != 0) {
            if (func_0016a070(v0) == s2) {
                return s0;
            }
        }
    } while ((s32)s1 < 2);

    return 0;
}
}  // namespace f22

// 0017e6d8 (src/anon/tiny_auto80_queue.cpp)
namespace f23 {
typedef u32  (*Fn_002cf1b8)(u32, u32);
extern "C" u32 func_0017df58(...) asm("func_0017df58");

u32 func_0017e6d8() {
    u32 s0 = 0u;
    u32 t6;
    do {
        u32 v0 = func_0017df58(s0);
        s0 = (u32)((s32)s0 + 1);
        if (v0 != 0u) {
            t6 = 1u;
            break;
        }
        t6 = 0u;
    } while ((s32)s0 < 2);
    return t6;
}
}  // namespace f23

// 0017e720 (src/anon/batch_w77.cpp)
namespace f24 {
struct VObj;
typedef s32 (*CountFn)(VObj*);
struct VObj { void** vt; };
typedef void (*VFn)(void*);
typedef void (*RelFn)(VObj*, u32);
extern f32 D_0034ebb8 asm("D_0034ebb8");
extern f32 D_00349e10 asm("D_00349e10");
extern u8* D_00352130 asm("D_00352130");
u32 func_001a8bd0(s32) asm("func_001a8bd0");
u32 func_001a8c10(u32, s32) asm("func_001a8c10");
s32 func_0017e668(u32) asm("func_0017e668");
u8* func_001a1658(u32, s32) asm("func_001a1658");  // state_dispatch_0_1_14
void func_001a1950(u8*, s32, s32, s32) asm("func_001a1950");
void func_001a17c8(u8*) asm("func_001a17c8");

void func_0017e720(void)
{
    if ((D_0034ebb8 -= D_00349e10) <= 0.0f) {
        u32 h = func_001a8bd0(-1);
        for (s32 i = 1; i < 4; i++) {
            u32 o = func_001a8c10(h, i);
            if (o && !func_0017e668(o)) {
                u8* q = func_001a1658(o, -1);  // state_dispatch_0_1_14
                if (*(u32*)(q + 476) & 0x10) func_001a1950(q, 1, 0, 0);
                func_001a17c8(q);
            }
        }
        D_0034ebb8 = *(f32*)(D_00352130 + 360);
    }
}
}  // namespace f24
