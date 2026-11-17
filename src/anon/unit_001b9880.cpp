// Linked unit 0x001b9880-0x001ba138: YS object lists (update, sweep, control-off bits) and their static init.
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"

// 001b9880 (was src/anon/batch_w1673.cpp)
namespace n001b9880 {
struct O1b9880 { void** vt; u8 pad[0x104]; u32 flags; u8 pad2[0x8b4-0x10c]; O1b9880* next; };
struct L1b9880 { O1b9880* head; O1b9880* tail; };
extern L1b9880 D_01d48da0 asm("D_01d48da0");
extern L1b9880 D_01d48da8 asm("D_01d48da8");
void func_0016a2e0(O1b9880*) asm("func_0016a2e0");
void func_001b9880() asm("func_001b9880");
void func_001b9880() {
    O1b9880* p = D_01d48da8.head;
    while (p) {
        O1b9880* n = p->next;
        func_0016a2e0(p);
        if (p) ((void (*)(O1b9880*))p->vt[1])(p);
        p = n;
    }
    D_01d48da8.head = 0;
    D_01d48da8.tail = 0;
    for (p = D_01d48da0.head; p; ) {
        O1b9880* n = p->next;
        if (p->flags & 0x80000) {
            asm volatile("" ::: "memory");
            O1b9880* prev;
            if (p == D_01d48da0.head) {
                prev = 0;
                D_01d48da0.head = p->next;
            } else {
                prev = D_01d48da0.head;
                while (prev->next != p) prev = prev->next;
                prev->next = p->next;
            }
            if (p == D_01d48da0.tail) D_01d48da0.tail = prev;
            p->next = 0;
            if (!D_01d48da8.tail) {
                D_01d48da8.tail = p;
                D_01d48da8.head = p;
                p->next = 0;
            } else {
                D_01d48da8.tail->next = p;
                p->next = 0;
                D_01d48da8.tail = p;
            }
        }
        p = n;
    }
}
}  // namespace n001b9880

// 001b99b0 (never written before): task callback, runs the object sweep twice.
namespace n001b99b0 {
void sweep(s32) asm("func_001b9880");
void func_001b99b0(void) asm("func_001b99b0");
void func_001b99b0(void) {
    sweep(0);
    sweep(0);
}
}  // namespace n001b99b0

// 001b99d0 (was src/anon/batch_w3769.cpp)
namespace n001b99d0 {
struct Nd2Sub { u8 pad[0x7f8]; u32 flags; };
struct Nd2 {
    u8 pad0[0x570];
    Nd2Sub* sub;
    u8 pad1[0x800 - 0x574];
    s32 dead;
    u8 pad2[0x8b8 - 0x804];
    Nd2* next;
};
struct Nd2List { Nd2* head; Nd2* tail; };
extern Nd2List D_01d48db0 asm("D_01d48db0");
void func_001b9b28(Nd2*) asm("func_001b9b28");
s32 func_001c0cd8(Nd2*) asm("func_001c0cd8");
void func_00320468(Nd2List*, Nd2*) asm("func_00320468");
// Unlinks every node flagged dead, then repeatedly sweeps the list, releasing nodes that
// func_001c0cd8 rejects or whose 0x100 flag is set, until the list is empty.
// Pins: p in s1 and h in t7 give the original's register rotation; hb is the list's high
// half held in s5 before the sweep loop's entry test, as the original hoists it.
void func_001b99d0(void) asm("func_001b99d0");
// Unlinks every node flagged dead, then repeatedly sweeps the list, releasing nodes that
// func_001c0cd8 rejects or whose 0x100 flag is set, until the list is empty.
// Pins: p in s1 and h in t7 give the original's register rotation; hb is the list's high
// half held in s5 before the sweep loop's entry test, as the original hoists it.
void func_001b99d0(void)
{
    register Nd2* p asm("$17");
    Nd2* n;
    Nd2* q;
    Nd2* qn;
    Nd2* it;
    register Nd2* h asm("$15");
    for (p = D_01d48db0.head; p; p = n) {
        n = p->next;
        if (p->dead) {
            func_001b9b28(p);
            Nd2* prev;
            if (p == D_01d48db0.head) {
                D_01d48db0.head = p->next;
                prev = 0;
            } else {
                prev = D_01d48db0.head;
                while (prev->next != p) prev = prev->next;
                prev->next = p->next;
            }
            if (p == D_01d48db0.tail) D_01d48db0.tail = prev;
            p->next = 0;
        }
    }
    register u32 hb asm("$21") = 0x1d50000; // %hi(D_01d48db0)
    asm("" : "+r"(hb));
    while ((h = ((Nd2List*)(hb - 29264))->head) != 0) {
        for (it = q = h; q; q = qn) {
            qn = !it ? D_01d48db0.head : it->next;
            it = qn;
            if (!func_001c0cd8(q) || (q->sub->flags & 0x100)) {
                func_001b9b28(q);
                func_00320468(&D_01d48db0, q);
            }
        }
    }
}
}  // namespace n001b99d0

// 001b9b28 (was src/anon/auto80_199_queue.cpp)
namespace n001b9b28 {
// 0x001b9230: definition moved into src/anon/unit_001b87a0.cpp

void func_001b9b28(u32 a0) asm("_Z13func_001b9b28j");
// 0x001b9230: definition moved into src/anon/unit_001b87a0.cpp

void func_001b9b28(u32 a0) {
    D_00351210 = a0;

    if (func_0019c768(a0) == 0) {
        if (func_001c0cd8(a0) != 0) {
            func_00193608(*(u32*)(a0 + 1392));
        }

        func_00193608(a0);
        func_0017fba0(a0 + 320, a0 + 1712);

        if (func_0019c470(a0) == 0) {
            func_001b3118(a0 + 2048, a0);
        }

        u32 t7 = *(u32*)(a0 + 1296);
        if (t7 != 0) {
            func_001b78d0(t7);
        }
    }

    u32 t7 = *(volatile u32*)(a0 + 2040);
    *(u32*)(a0 + 2040) = t7 | 0x500;
}
}  // namespace n001b9b28

// 001b9bc8 (was src/anon/batch_wcx2.cpp)
namespace n001b9bc8 {
// ---- 001b9bc8
extern u8* D_01d48da0 asm("D_01d48da0");
s32 func_0019baa8(u8*) asm("func_0019baa8");
static inline u8* Next_001b9bc8(u8* n) { if (!n) return D_01d48da0; return *(u8**)(n + 2228); }
u8* ct_001b9bc8(u8* p) asm("_Z16ctarget_001b9bc8jjjj");
u8* ct_001b9bc8(u8* p) asm("_Z16ctarget_001b9bc8jjjj");
u8* ct_001b9bc8(u8* p) {
    while ((p = Next_001b9bc8(p)) && func_0019baa8(p)) {}
    return p;
}
}  // namespace n001b9bc8

// 001b9c28 (was src/anon/batch_w7.cpp)
namespace n001b9c28 {
extern u32 D_01d48db8[] asm("D_01d48db8");
// 0x001b90c8: definition moved into src/anon/unit_001b87a0.cpp

// Sets control-off bit i in the global bitset.
void control_off(s32 i) asm("_ZN2YS3OBJ10ControlOffEi");
void control_off(s32 i) asm("_ZN2YS3OBJ10ControlOffEi");
void control_off(s32 i) {
    D_01d48db8[(u32)i >> 5] |= 1 << (i & 31);
}
}  // namespace n001b9c28

// 001b9c58 (was src/anon/tiny_auto80_solver.cpp)
namespace n001b9c58 {
void func_001b9c58(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001b9c58jjjjjjjj");
extern u8 D_01d48db8 asm("D_01d48db8");
void func_001b9c58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001b9c58jjjjjjjj");
void func_001b9c58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 idx = a0 >> 5;
    u32 base = (u32)&D_01d48db8;
    idx <<= 2;
    idx += base;
    a0 &= 31;
    u32 mask = 1;
    u32 val = *(volatile u32*)idx;
    mask <<= a0;
    mask = ~mask;
    val &= mask;
    *(volatile u32*)idx = val;
}
}  // namespace n001b9c58

// 001b9c90 (was src/anon/batch_w66.cpp)
namespace n001b9c90 {
// 0x001b9380: definition moved into src/anon/unit_001b87a0.cpp
// ---- 001b9c90
u32 func_0016a040(u8*) asm("func_0016a040");
s32 func_00105300(void) asm("func_00105300");
extern u32 D_01d48db8[] asm("D_01d48db8");
s32 func_001b9c90(u8* p) asm("func_001b9c90");
s32 func_001b9c90(u8* p) {
    s32 r = 0;
    u32 id = func_0016a040(p);
    if (!(D_01d48db8[id >> 5] & (1 << (id & 31))) && !(*(u32*)(p + 268) & 0x200000) && !func_00105300()) {
        if (func_0016a040(p) || (*(u32*)(p + 2040) & 0x80)) r = 1;
    }
    return r;
}
}  // namespace n001b9c90

// 001b9d40 (was src/anon/batch_w47.cpp)
namespace n001b9d40 {
// 001b84b8: moved to src/anon/unit_001b82d8.cpp

s32 func_001b9d40(u8* p) asm("func_001b9d40");
// 001b84b8: moved to src/anon/unit_001b82d8.cpp

s32 func_001b9d40(u8* p) {  // vtable_call_slot64_flags
    s32 r = 0;
    if ((*(s32 (**)(u8*))(*(u8**)p + 64))(p)) {
        u32 f = *(u32*)(p + 352);
        s32 t = 0;
        if (f & 4) goto one;
        if (f & 8) goto one;
        if (!(f & 16)) goto done;
    one:
        t = 1;
    done:
        r = t;
    }
    return r;
}
}  // namespace n001b9d40

// 001b9db0 (was src/anon/batch_w93.cpp)
namespace n001b9db0 {
// Loads the field's map resource, publishes it, and folds its flags into the global field state.
// 001bacd0: moved to src/anon/unit_001ba7e0.cpp

struct W93Ob;
struct W93ObVt { u8 pad[40]; void (*kill)(W93Ob*); u8 p2[60 - 44]; s32 (*prio)(W93Ob*); };
struct W93Ob { W93ObVt* vt; u8 pad[264 - 4]; u32 flags; u8 p2[768 - 268]; u8 f768[2228 - 768]; W93Ob* next; };
void func_001a58f8(void) asm("func_001a58f8");
void func_001bf6a8(void) asm("func_001bf6a8");
void func_001c1060(void) asm("func_001c1060");
void func_001b5400(void) asm("func_001b5400");
void func_001b6038(void) asm("func_001b6038");
void func_001b6d00(void) asm("func_001b6d00");
void func_001c8d08(void) asm("func_001c8d08");
void func_001a5e38(void) asm("func_001a5e38");
void func_001ba740(void) asm("func_001ba740");
void func_0018d790(void) asm("func_0018d790");
void func_001d6c58(void) asm("func_001d6c58");
extern W93Ob* D_01d48da0 asm("D_01d48da0");
extern u8 D_0036dbd8[] asm("D_0036dbd8");
void func_00188120(void*, void*) asm("func_00188120");
s32 func_001c0cd8(W93Ob*) asm("func_001c0cd8");
void func_0016ae18(W93Ob*) asm("func_0016ae18");
static inline W93Ob* W93Next(W93Ob* o) { if (!o) return D_01d48da0; return o->next; }
// Runs the per-frame subsystem updates, then culls or refreshes every live object by priority.
void func_001b9db0(s32 lim) asm("func_001b9db0");
// Runs the per-frame subsystem updates, then culls or refreshes every live object by priority.
void func_001b9db0(s32 lim)
{
    W93Ob* o = 0;
    func_001a58f8(); func_001bf6a8(); func_001c1060(); func_001b5400();
    func_001b6038(); func_001b6d00(); func_001c8d08(); func_001a5e38();
    func_001ba740(); func_0018d790(); func_001d6c58();
    while ((o = W93Next(o))) {
        if (o->flags & 0x80000) continue;
        if (o->vt->prio(o) >= lim) {
            o->vt->kill(o);
        } else {
            func_00188120(o->f768, D_0036dbd8);
            if (!func_001c0cd8(o)) func_0016ae18(o);
        }
    }
}
}  // namespace n001b9db0

// 001b9ee8 (was src/anon/batch_w59.cpp)
namespace n001b9ee8 {
// --- 001b9ee8
extern u8* D_01d48da0 asm("D_01d48da0");
static inline u8* Next1b9(u8* o) {
    if (!o) return D_01d48da0;
    return *(u8**)(o + 2228);
}
void func_001b9ee8(s32 lim) asm("func_001b9ee8");
void func_001b9ee8(s32 lim) {
    u8* o = 0;
    while ((o = Next1b9(o))) {
        if (*(u32*)(o + 1416) & 0x20) continue;
        typedef s32 (*Fn)(u8*);
        if ((*(Fn*)(*(u8**)o + 60))(o) < lim) *(u32*)(o + 268) |= 0x80;
    }
}
}  // namespace n001b9ee8

// 001b9f80 (was src/anon/batch_wcx.cpp)
namespace n001b9f80 {
extern u8* D_01d48da0 asm("D_01d48da0");
static inline u8* NextB(u8* n) { if (!n) return D_01d48da0; return *(u8**)(n + 2228); }
typedef s32 (*Fn60)(u8*);
void func_001b9f80(s32 lv) asm("func_001b9f80");
void func_001b9f80(s32 lv)
{
    u8* n = 0;
    while ((n = NextB(n))) {
        if (*(u32*)(n + 1416) & 0x20) continue;
        if ((*(Fn60*)(*(u8**)n + 60))(n) < lv) *(u32*)(n + 268) &= ~0x80;
    }
}
}  // namespace n001b9f80

// 001ba020 (never written before): empty function.
namespace n001ba020 {
void func_001ba020(void) asm("func_001ba020");
void func_001ba020(void) {}
}  // namespace n001ba020

// 001ba028 (was src/anon/batch_w23.cpp)
namespace n001ba028 {
// 0x001af360: definition moved into src/anon/unit_001ada38.cpp

struct L1b { u8 pad[2228]; L1b* next; };
extern L1b* D_01d48da0 asm("D_01d48da0");
static inline L1b* list1b_next(L1b* n) { if (!n) return D_01d48da0; return n->next; }
static inline bool list1b_has(L1b* o) {
    L1b* n = 0;
    while ((n = list1b_next(n)) != 0) {
        if (n == o) return true;
    }
    return false;
}
// Is o in the list?
u8 func_001ba028(L1b* o) asm("func_001ba028");
// Is o in the list?
u8 func_001ba028(L1b* o) {  // list_contains_ptr
    return list1b_has(o);
}
}  // namespace n001ba028

// File statics: the object lists (live, dying, update order) and the control-off bitset.
// gcc makes the static initialiser (0x1ba060) and the _GLOBAL__I_/_GLOBAL__D_ stubs.
namespace nstatics {
struct ObjList {
    u8* head;
    u8* tail;
    ObjList() { head = 0; tail = 0; }
    ~ObjList() {}
};
struct CtrlBits {
    u32 w;
    CtrlBits() { w = 0; }
};
static ObjList s_list0 asm("D_01d48da0");
static ObjList s_list1 asm("D_01d48da8");
static ObjList s_list2 asm("D_01d48db0");
static CtrlBits s_ctrl asm("D_01d48db8");
}  // namespace nstatics
