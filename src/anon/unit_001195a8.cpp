// Linked unit 0x00117778-0x00119bf8.
#include "../naka/libkn/stitch.hpp"
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 001195a8 (was src/anon/batch_w100.cpp)
namespace n001195a8 {
void* func_0010c778(u32) asm("func_0010c778");
void func_00135aa0(void*) asm("func_00135aa0");
u8* func_00111e38(u32) asm("func_00111e38");
void func_00194668(u8*) asm("func_00194668");
void func_00194468(u8*) asm("func_00194468");
void func_001c0e60(u8*) asm("func_001c0e60");
u32 func_001762c0(u8*, s32) asm("func_001762c0");
void func_001c0d38(u8*, u8*, u32, u32) asm("func_001c0d38");
void func_0016bd60(u8*, u32) asm("func_0016bd60");
void func_00198970(u32) asm("func_00198970");
void func_00112778(u32, u32) asm("func_00112778");
/*TARGET 001195a8*/
void func_001195a8(u8* w) asm("func_001195a8");
void func_001195a8(u8* w) {
    u8* pl;
    s32 i;
    func_00135aa0(func_0010c778(*(u32*)(w + 4)));
    pl = func_00111e38(0);
    *(u32*)(pl + 1688) = 0;
    *(f32*)(pl + 60) = 1.0f;
    func_00194668(pl);
    if (w[1920]) func_00194468(pl);
    for (i = 0; i < 2; i++) {
        u8* m = ((u8**)(pl + 2808))[i];
        if (!m) continue;
        func_00194668(m);
        func_001c0e60(m);
        func_001c0d38(m, pl, func_001762c0(pl, i), 0);
        *(u32*)(m + 1688) = 0;
        if (*(u8*)(i + (u32)w + 1921)) func_00194468(m);
    }
    func_0016bd60(pl, 0);
    func_00198970(*(u32*)(w + 4));
    func_00112778(*(u32*)(w + 4), 0);
}
}  // namespace n001195a8

// 001196d0 (was gap)
namespace g001196d0 {
struct Pers { u32 x0; };
typedef s32 (Pers::*Handler)(void*, void*, u32*, u32);
struct Act { u32 x0; Handler fn; };
// The member-function pointer constants {method, 0} of the three handlers (unlisted methods 0x119000, 0x119108,
// 0x1192b0), passed by value to the action lookup.
extern const u32 R_0036a858[2] asm("D_0036a858") __attribute__((aligned(8))) = { 0x119000, 0 };
extern const u32 R_0036a860[2] asm("D_0036a860") __attribute__((aligned(8))) = { 0x119108, 0 };
extern const u32 R_0036a868[2] asm("D_0036a868") __attribute__((aligned(8))) = { 0x1192b0, 0 };
struct Pmf8 { u64 v; } __attribute__((packed));
extern const Pmf8 K525 asm("D_0036a858");
extern const Pmf8 K526 asm("D_0036a860");
extern const Pmf8 K527 asm("D_0036a868");
Pers* getPersonality(void*) asm("_ZN2kn6Friend14getPersonalityEv");
Act* findAction(Pers*, u64) asm("func_001144e8");
void TargetCtor(void*) asm("_ZN2YS6TARGETC1Ev");
void setLastAction(void*, Act*, void*) asm("_ZN2kn6Friend13setLastActionEPNS_12FriendActionEPv");
u32 func_00112740(void*) asm("func_00112740");
void func_00112730(void*, u32) asm("func_00112730");
void update(Pers*) asm("_ZN2kn6Stitch14update_obj_posEv");
struct Loc { u8 t[32]; u32 v; };
// Message 525-527: look up the matching action and run its handler once right away.
s32 f(void* self, s32 msg) asm("func_001196d0");
s32 f(void* self, s32 msg) {
    Act* a = 0;
    Pers* p = getPersonality(self);
    switch (msg) {
    case 525: a = findAction(p, K525.v); break;
    case 526: a = findAction(p, K526.v); break;
    case 527: a = findAction(p, K527.v); break;
    }
    Loc l;
    TargetCtor(l.t);
    l.v = 0;
    TargetCtor(l.t);
    setLastAction(self, 0, 0);
    (p->*(a->fn))(a, l.t, &l.v, 0);
    setLastAction(self, a, 0);
    func_00112730(self, func_00112740(self) & ~4);
    update(p);
    return 0;
}
}  // namespace g001196d0

// 00119830 (was src/anon/batch_wcx2.cpp)
namespace n00119830 {
struct Handle119830;
// 0x001161c8: definition moved into src/anon/unit_00114a90.cpp


// --------------------
// 00119830: spawn the attack effects for a party move kind and scatter extra hits around the camera target
struct V119830 {
    f32 x, y, z, w;
    V119830() {}
    V119830(const V119830& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V119830& operator=(const V119830& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
s32 f119830_ok(Handle119830*) asm("func_00190140");
s32 func_001901c0(Handle119830*) asm("func_001901c0");
struct Handle119830 {
    s32 id;
    bool valid() { return f119830_ok(this) && id != 0; }
};
struct Model119830 { u8 pad0[268]; u32 f268; u8 pad1[2548 - 272]; Handle119830 h; };
struct Who119830 { u8 pad0[4]; Model119830* model; u8 pad1[1928 - 8]; s32 count; };
void* func_00111e38(s32) asm("func_00111e38");
void* func_00117970(Who119830*, s32, void*, s32, s32, s32, s32, s32) asm("func_00117970");
void func_00117b20(Who119830*, void*) asm("func_00117b20");
void func_00118da0(Who119830*) asm("func_00118da0");
void* f119830_cam(s32) asm("func_00106a60");
void func_00107368(void*, V119830*) asm("func_00107368");
f32 func_0010f660(void) asm("func_0010f660");
void func_00113338(Model119830*, V119830*, Handle119830*, s32, s32, s32) asm("func_00113338");
/*TARGET 00119830*/
void func_00119830(Who119830* w, s32 kind) asm("func_00119830");
void func_00119830(Who119830* w, s32 kind)
{
    s32 n = 0;
    void* leader = func_00111e38(0);
    switch (kind) {
    case 0:
    case 2:
        func_00117b20(w, func_00117970(w, 1, w->model, 108, -1, 0, 1, 0));
        n = 1;
        if ((w->model->f268 & 0x10000) && kind != 2) {
            func_00117b20(w, func_00117970(w, 1, leader, 0x4003, -1, 0, 1, 0));
            n = 2;
        }
        break;
    case 1:
    case 3:
        func_00117b20(w, func_00117970(w, 1, w->model, 54, -1, 0, 1, 0));
        n = 1;
        if ((w->model->f268 & 0x10000) && kind != 3) {
            func_00117b20(w, func_00117970(w, 1, leader, 0x4003, -1, 0, 1, 0));
            n = 2;
        }
        break;
    }
    if (w->model->f268 & 0x10000) {
        if (!(w->model->h.valid() && func_001901c0(&w->model->h))) func_00118da0(w);
        if (w->model->h.valid() && func_001901c0(&w->model->h)) {
            V119830 base;
            func_00107368(f119830_cam(1), &base);
            while (n-- > 0) {
                V119830 p;
                p = base;
                p.x += (func_0010f660() - 0.5f) * 2.0f * 200.0f;
                p.y += (func_0010f660() - 0.5f) * 2.0f * 200.0f;
                V119830 q(p);
                func_00113338(w->model, &q, &w->model->h, 883, -1, 2);
            }
        }
    } else if (!kind) {
        w->count++;
    }
}
}  // namespace n00119830

// 00119b10 (was src/anon/batch_w234.cpp)
namespace n00119b10 {
struct V { f32 x, y, z; u32 w; };
extern V D_003a99d0 asm("D_003a99d0");
extern V D_003a99e0 asm("D_003a99e0");
void func_wt119b10(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_00119b10jjjj");
/*TARGET 00119b10*/
void func_wt119b10(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_00119b10jjjj");
void func_wt119b10(u32 a0, u32 a1, u32 a2, u32 a3) {
    if (a1 == 0xffff) {
        if (a0 == 1) {
            D_003a99d0.x = -218.0f;
            D_003a99d0.w = 0;
            D_003a99d0.z = 1024.0f;
            D_003a99d0.y = 55.0f;
        }
    }
    if (a1 == 0xffff) {
        if (a0 == 1) {
            D_003a99e0.x = 185.0f;
            D_003a99e0.w = 0;
            D_003a99e0.z = 1024.0f;
            D_003a99e0.y = 125.0f;
        }
    }
}
}  // namespace n00119b10

// 00119bb8 (was src/anon/tiny_wrappers_more.cpp)
namespace n00119bb8 {
u32 func_00119b10(u32, u32, u32, u32) asm("_Z13func_00119b10jjjj");
/*TARGET 00119bb8*/
// 00109670: moved to src/anon/unit_001085a8.cpp

u32 func_00119bb8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00119bb8jjjj");
// 00109670: moved to src/anon/unit_001085a8.cpp

u32 func_00119bb8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00119b10(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n00119bb8


// 00119bd8 (was gap): _GLOBAL__D_ stub of the static init 0x119b10.
namespace g00119bd8 {
u32 func_00119b10(u32, u32, u32, u32) asm("_Z13func_00119b10jjjj");
u32 f(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00119bd8");
u32 f(u32 a0, u32 a1, u32 a2, u32 a3) { return func_00119b10(0, 0xffff, a2, a3); }
}  // namespace g00119bd8
