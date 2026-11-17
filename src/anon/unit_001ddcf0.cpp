// Linked unit 0x001ddcf0-0x001de9a8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 001ddcf0 (was gap)
namespace n001ddcf0 {
// ryj::PAX::PAX() C2 (twin of 0x1ddd10)
void gap_001ddcf0(u32* p) asm("gap_001ddcf0");
void gap_001ddcf0(u32* p) {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[6] = 0;
    p[4] = 0;
    p[3] = 0;
}
}  // namespace n001ddcf0

// 001ddd10 (was src/anon/tiny_auto80.cpp)
namespace n001ddd10 {
// ryj::PAX::PAX() C1
void func_001ddd10(u32* p) asm("_Z13func_001ddd10jjjj");
void func_001ddd10(u32* p) {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[6] = 0;
    p[4] = 0;
    p[3] = 0;
}
}  // namespace n001ddd10

// 001ddd30 (was src/anon/batch_wcx2.cpp)
namespace n001ddd30 {
// 0x001d79b8: definition moved into src/anon/unit_001d7458.cpp

// ---- 001ddd30
struct Nd_001ddd30 { u8 pad[20]; Nd_001ddd30* next; };
extern Nd_001ddd30* D_01d9e348 asm("D_01d9e348");
static inline Nd_001ddd30* Next_001ddd30(Nd_001ddd30* n) { if (!n) return D_01d9e348; return n->next; }
static inline bool Has_001ddd30(Nd_001ddd30* x) {
    Nd_001ddd30* n = 0;
    while ((n = Next_001ddd30(n))) { if (n == x) return true; }
    return false;
}
void func_001dde40_dd30(Nd_001ddd30*) asm("func_001dde40");
/*TARGET 001ddd30*/
void func_001ddd30(Nd_001ddd30* a0) asm("func_001ddd30");
void func_001ddd30(Nd_001ddd30* a0) {
    if (Has_001ddd30(a0)) func_001dde40_dd30(a0);
}
}  // namespace n001ddd30

// 001ddd88 (was src/anon/batch_w28.cpp)
namespace n001ddd88 {
u32 func_00321cb0(void*, void*) asm("func_00321cb0");
void func_001dde40(void*) asm("func_001dde40");
extern u8 D_01d9e348[] asm("D_01d9e348");
// 0x001d9148: definition moved into src/anon/unit_001d7458.cpp

// ryj::PAX::~PAX() (D1), called by the static destructors of PAX members.
void func_001ddd88(void* p) asm("_ZN3ryj3PAXD1Ev");
/*TARGET 001ddd88*/
void func_001ddd88(void* p) asm("_ZN3ryj3PAXD1Ev");
void func_001ddd88(void* p) {
    if (func_00321cb0(D_01d9e348, p)) func_001dde40(p);
}
}  // namespace n001ddd88

// 001dddd0 (was src/anon/batch_w45.cpp)
namespace n001dddd0 {
// singly linked list node / list header (next at +20)
struct Lnk2 { u32 f0; u32 f4; u8 pad[12]; struct Lnk2* next; };
struct LList2 { Lnk2* head; Lnk2* tail; };
void func_001dc010(u8*, u8*) asm("func_001dc010");
extern LList2 D_01d9e348 asm("D_01d9e348");
// 0x001aeb80: definition moved into src/anon/unit_001ada38.cpp

// 001b0858: moved to src/yasui/libys/lookat.cpp

// start the task for id unless it is invalid or already current
// 001b1e80: moved to src/anon/unit_001b1d20.cpp

// init a node and append it to the global list
// 001b2308: moved to src/anon/unit_001b1d20.cpp

// 0x1c8948: moved to src/yasui/libys/summon.cpp

// 001dbc58: moved to src/anon/unit_001dbbe0.cpp

// init a node from a data block and append it to the global list
void wtarget_001dddd0(u32, u32, u32, u32) asm("_Z16wtarget_001dddd0jjjj");
/*TARGET 001dddd0*/
void wtarget_001dddd0(u32 x0, u32 x1, u32, u32) asm("_Z16wtarget_001dddd0jjjj");
void wtarget_001dddd0(u32 x0, u32 x1, u32, u32) {
    Lnk2* a0 = (Lnk2*)x0;
    u8* a1 = (u8*)x1;
    a0->f0 = (u32)a1;
    a0->f4 = (u32)(a1 + 16);
    func_001dc010((u8*)a0 + 8, (u8*)(*(u32*)(a1 + 12) + (u32)a1));
    LList2* l = &D_01d9e348;
    if (l->tail == 0) {
        l->tail = a0;
        l->head = a0;
        a0->next = 0;
    } else {
        l->tail->next = a0;
        a0->next = 0;
        l->tail = a0;
    }
}
}  // namespace n001dddd0

// 001dde40 (was src/anon/batch_w68.cpp)
namespace n001dde40 {
/* ---- 001dde40: unlink n from the list ---- */
struct LNode { u32 used; u32 pad[4]; LNode* next; };
struct LList { LNode* head; LNode* tail; };
extern LList D_01d9e348 asm("D_01d9e348");
s32 func_00321cb0(void*, void*) asm("func_00321cb0");
void func_001de450(void*) asm("func_001de450");
/*TARGET 001dde40*/
void func_001dde40(LNode* n) asm("func_001dde40");
void func_001dde40(LNode* n) {
    LNode* prev;
    if (!func_00321cb0(&D_01d9e348, n)) return;
    func_001de450(n);
    if (n == D_01d9e348.head) {
        D_01d9e348.head = n->next;
        prev = 0;
    } else {
        for (prev = D_01d9e348.head; prev->next != n; prev = prev->next) ;
        prev->next = n->next;
    }
    if (n == D_01d9e348.tail) D_01d9e348.tail = prev;
    n->next = 0;
    n->used = 0;
}
}  // namespace n001dde40

// 001ddef0 (was src/anon/batch_w109.cpp)
namespace n001ddef0 {
// 0x00139f38: definition moved into src/anon/unit_001393c8.cpp

// ---- f18.cpp
struct D1ddef0 { u16 id; u8 pad[14]; u32 flags; f32 radius; u8 pad2[4]; f32 v[12]; };
u8* func_001dcff0(u8*, u16, f32) asm("func_001dcff0");
f32* func_001dc5f8(u8*) asm("func_001dc5f8");
f32* func_001dc648(u8*) asm("func_001dc648");
f32* func_001dc620(u8*) asm("func_001dc620");
u8* func_001de948(s32) asm("func_001de948");
void func_001dea80(u8*, u8*, D1ddef0*, u8*, f32) asm("func_001dea80");
void func_001df670(u8*) asm("func_001df670");
void func_00180df8(u8*, u8*) asm("func_00180df8");
extern s32 D_00352b50 asm("D_00352b50");
/*TARGET 001ddef0*/
// Builds an entry from a descriptor and pushes its node onto the owner list head.
u8* func_001ddef0(u8* self, D1ddef0* d, s32 a2, s32 a3, s32 a4, u8* w) asm("func_001ddef0");
// Builds an entry from a descriptor and pushes its node onto the owner list head.
u8* func_001ddef0(u8* self, D1ddef0* d, s32 a2, s32 a3, s32 a4, u8* w) {
    f32 r = d->radius;
    if (d->flags & 1) r += 0.1f;
    u8* o = func_001dcff0(self + 8, d->id, r);
    *(u8**)(o + 12) = self;
    func_001dc5f8(o)[0] = d->v[0];
    func_001dc5f8(o)[1] = d->v[1];
    func_001dc5f8(o)[2] = d->v[2];
    func_001dc648(o)[0] = d->v[3];
    func_001dc648(o)[1] = d->v[4];
    func_001dc648(o)[2] = d->v[5];
    func_001dc620(o)[0] = d->v[6];
    func_001dc620(o)[1] = d->v[7];
    func_001dc620(o)[2] = d->v[8];
    u8* n = func_001de948(112);
    func_001dea80(n, o, d, w, r);
    u8** list = (u8**)(self + 12);
    if (list[0] == 0) {
        list[1] = n;
        list[0] = n;
        *(u8**)(n + 96) = 0;
    } else {
        *(u8**)(n + 96) = list[0];
        list[0] = n;
    }
    if (d->flags & 1) {
        func_001df670(n);
        if ((d->flags & 0x20) && D_00352b50 == 1) func_00180df8(w + 320, o);
    }
    return o;
}
}  // namespace n001ddef0

// 001de0a0 (was src/anon/batch_w1673.cpp)
namespace n001de0a0 {
struct Node_de0a0 { u8 pad[0x60]; Node_de0a0* next; };
struct List_de0a0 { Node_de0a0* head; Node_de0a0* tail; };
struct Obj_de0a0 { u8 pad[8]; u8 sub[4]; List_de0a0 list; };
struct Res_de0a0 { u8 pad[0xc]; Obj_de0a0* owner; };
struct P_de0a0 { u8 pad[0x38]; f32 f; };
Res_de0a0* eff_create_001dcff0(f32, void*, u16) asm("_ZN3ryj6EFFECT6CreateERNS_11EFFECT_DATAEjjjif");
Node_de0a0* func_001de948(s32) asm("func_001de948");
void func_001dec78(f32, Node_de0a0*, Res_de0a0*, u16*, P_de0a0*) asm("func_001dec78");
/*TARGET 001de0a0*/
Res_de0a0* func_001de0a0(Obj_de0a0* a0, u16* a1, s32 a2, s32 a3, s32 t0, P_de0a0* p) asm("func_001de0a0");
Res_de0a0* func_001de0a0(Obj_de0a0* a0, u16* a1, s32 a2, s32 a3, s32 t0, P_de0a0* p) {
    f32 f = p->f + 0.1f;
    Res_de0a0* r = eff_create_001dcff0(f, a0->sub, *a1);
    r->owner = a0;
    Node_de0a0* n = func_001de948(0x70);
    func_001dec78(f, n, r, a1, p);
    List_de0a0* l = &a0->list;
    if (a0->list.head == 0) {
        l->tail = n;
        a0->list.head = n;
        n->next = 0;
    } else {
        n->next = a0->list.head;
        a0->list.head = n;
    }
    return r;
}
}  // namespace n001de0a0

// 001de168 (was src/anon/batch_w25.cpp)
namespace n001de168 {
// 0x001d14e0: definition moved into src/anon/unit_001d14e0.cpp

u8 func_001ddef0(u32**, u8*) asm("func_001ddef0");
/*TARGET 001de168*/
u32 func_001de168(u32** o, u32 id) asm("func_001de168");
u32 func_001de168(u32** o, u32 id) {  // scan_list_by_half
    u32 r = 0;
    s32 n = (*o)[2];
    s32 i;
    for (i = 0; i < n; i++) {
        u8* e = (u8*)o[1] + i * 80;
        if (*(u16*)(e + 2) == id) {
            r = func_001ddef0(o, e);
            break;
        }
    }
    return r;
}
}  // namespace n001de168

// 001de1c0 (was gap)
namespace n001de1c0 {
// find the entry with this id and create its effect (0x1de0a0)
struct Ent { u16 a; u16 id; u8 pad[76]; };
struct Hdr { u8 pad[8]; s32 n; };
struct Obj { Hdr* h; Ent* e; };
u32 func_001de0a0(Obj*, Ent*, s32, s32, s32, s32) asm("func_001de0a0");
u32 gap_001de1c0(Obj* o, u32 id, s32 a2, s32 a3, s32 a4, s32 a5) asm("gap_001de1c0");
u32 gap_001de1c0(Obj* o, u32 id, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 n = o->h->n;
    s32 i = 0;
    u32 r = 0;
    if (n > 0) {
        Ent* e = o->e;
        do {
            if (e->id == id) {
                r = func_001de0a0(o, e, a3, a4, a5, a2);
                break;
            }
            i++;
            e++;
        } while (i < n);
    }
    return r;
}
}  // namespace n001de1c0

// 001de228 (was src/anon/batch_wcx.cpp)
namespace n001de228 {
// 0x1c88a8: moved to src/yasui/libys/summon.cpp
void func_001ddef0(u8**, u8*, u32, u32, u32, u32) asm("func_001ddef0");
/*TARGET 001de228*/
void func_001de228(u8** p, u32 k, u32 c, u32 d, u32 e, u32 f) asm("func_001de228");
void func_001de228(u8** p, u32 k, u32 c, u32 d, u32 e, u32 f)
{
    s32 n = *(s32*)(p[0] + 8);
    for (s32 i = 0; i < n; i++) {
        u8* x = p[1] + i * 80;
        if (x[4] == k) func_001ddef0(p, x, c, d, e, f);
    }
}
}  // namespace n001de228

// 001de2e0 (was src/anon/tiny_auto80_queue.cpp)
namespace n001de2e0 {
/*TARGET 001de2e0*/
s32 func_001de2e0(u32 a0, u64 a1) asm("_Z13func_001de2e0jy");
s32 func_001de2e0(u32 a0, u64 a1) {
    s32 t5 = *(s32*)(u32)(*(u32*)(u32)(a0 + 0) + 8);
    s32 t6 = 0;
    if (t5 > 0) {
        u32 v0 = *(u32*)(u32)(a0 + 4);
        while (1) {
            u64 t7 = *(u64*)(u32)(v0 + 8);
            t7 = (u64)(t7 & a1);
            if (a1 == t7) {
                return (s32)(*(u16*)(u32)(v0 + 2));
            }
            t6 = (s32)(t6 + 1);
            if (t6 < t5) {
                v0 = (u32)((s32)v0 + 80);
                continue;
            }
            break;
        }
    }
    return -1;
}
}  // namespace n001de2e0

// 001de328 (was src/anon/batch_wcx2.cpp)
namespace n001de328 {
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
// 0x002ae280: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct I1de328 { u16 a; u16 id; };
struct N1de328 { u8 pad[0x40]; u32 f40; I1de328* info; u8 pad48[0x18]; N1de328* next; };
struct L1de328 { N1de328* head; N1de328* tail; };
struct O1de328 { u8 pad[0xc]; L1de328 list; };
void func_001dc920(u32) asm("func_001dc920");
void func_001e0058(N1de328*) asm("func_001e0058");
/*TARGET 001de328*/
void func_001de328(O1de328* o, u32 id) asm("func_001de328");
void func_001de328(O1de328* o, u32 id)
{
    N1de328* head = o->list.head;
    N1de328* n = head;
    while (n != 0) {
        N1de328* next = n->next;
        if (n->info->id == id) {
            N1de328* p;
            L1de328* l = &o->list;
            if (n == head) {
                l->head = next;
                p = 0;
            } else {
                p = head;
                while (p->next != n) p = p->next;
                p->next = next;
            }
            if (n == l->tail) l->tail = p;
            n->next = 0;
            func_001dc920(n->f40);
            func_001e0058(n);
            return;
        }
        n = next;
    }
}
}  // namespace n001de328

// 001de3d8 (was src/anon/auto80_199_queue.cpp)
namespace n001de3d8 {
/*TARGET 001de3d8*/
// 0x001dd140: definition moved into src/anon/unit_001dbfd8.cpp

void func_001de3d8(u32 a0, u32 a1) asm("_Z13func_001de3d8jj");
// 0x001dd140: definition moved into src/anon/unit_001dbfd8.cpp

void func_001de3d8(u32 a0, u32 a1) {
    u32 s2 = a1;
    u32 s3 = a0;
    u32 s0 = *(u32*)(a0 + 12);
    if (s0 == 0) {
        return;
    }

    while (1) {
        u32 t6 = *(u32*)(s0 + 68);
        u32 t7 = *(u8*)(t6 + 4);
        u32 s1 = *(u32*)(s0 + 96);
        if (t7 == s2) {
            func_00321ce8(s3 + 12, s0);  // list_unlink_node
            func_001dc920(*(u32*)(s0 + 64));
            func_001e0058(s0);
        }
        if (s1 != 0) {
            s0 = s1;
            continue;
        }
        return;
    }
}
}  // namespace n001de3d8

// 001de450 (was src/anon/batch_w37.cpp)
namespace n001de450 {
void func_00321ce8(void*, void*) asm("func_00321ce8");
// list_unlink_node
void func_001dc920(void*) asm("func_001dc920");
void func_001e0058(void*) asm("func_001e0058");
/*TARGET 001de450*/
void func_001de450(u8* p) asm("func_001de450");
void func_001de450(u8* p) {
    u8* n = *(u8**)(p + 12);
    while (n) {
        u8* next = *(u8**)(n + 96);
        func_00321ce8(p + 12, n);  // list_unlink_node
        func_001dc920(*(void**)(n + 64));
        func_001e0058(n);
        n = next;
    }
}
}  // namespace n001de450

// 001de4b0 (was src/anon/batch_w26.cpp)
namespace n001de4b0 {
// 0x001d7ec8: definition moved into src/anon/unit_001d7458.cpp

struct DEnt { u8 pad[64]; void* val; u8* info; u8 pad2[24]; DEnt* next; };
struct DList { u8 pad[12]; DEnt* head; };
/*TARGET 001de4b0*/
// Returns the value of the entry (optionally of a type) following `prev`.
void* func_001de4b0(DList* l, s32 type, void* prev) asm("func_001de4b0");
// Returns the value of the entry (optionally of a type) following `prev`.
void* func_001de4b0(DList* l, s32 type, void* prev) {
    s32 found = 0;
    DEnt* e = l->head;
    while (e) {
        DEnt* nx = e->next;
        if (type < 0 || e->info[4] == type) {
            if (!prev || found) return e->val;
            found = e->val == prev;
        }
        e = nx;
    }
    return 0;
}
}  // namespace n001de4b0

// 001de508 (was src/anon/batch_w32.cpp)
namespace n001de508 {
// alloc_336_align_171
void func_001dc700(void*, s32) asm("func_001dc700");
// 0x001dc878: definition moved into src/anon/unit_001dbfd8.cpp

struct Binding { u8 pad[0x40]; void* eff; u32 pad44; u32 w48; u8 pad2[0x10]; u32 f5c; Binding* next; };
void PAX_unbind(u8*, void*) asm("_ZN3ryj3PAX6unbindEPNS_6EFFECTE");
/*TARGET 001de508*/
void PAX_unbind(u8* pax, void* e) asm("_ZN3ryj3PAX6unbindEPNS_6EFFECTE");
void PAX_unbind(u8* pax, void* e) {
    Binding* b = *(Binding**)(pax + 12);
    while (b) {
        Binding* nx = b->next;
        if (b->eff == e) {
            b->w48 = 0;
            b->f5c &= ~1;
            func_001dc700(e, 0);
            return;
        }
        b = nx;
    }
}
}  // namespace n001de508

// 001de568 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n001de568 {
u32 func_00321cb0(u32, u32, u32, u32) asm("_Z13func_00321cb0jjjj");
extern u8 D_01d9e348 asm("D_01d9e348");
/*TARGET 001de568*/
// 0x001dcc48: definition moved into src/anon/unit_001dbfd8.cpp

u32 func_001de568(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001de568jjjj");
// 0x001dcc48: definition moved into src/anon/unit_001dbfd8.cpp

u32 func_001de568(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r5 = r4;
    r4 = (u32)&D_01d9e348;
    u32 (*fp_call4_00321cb0)(u32, u32, u32, u32) = func_00321cb0;
    r2 = fp_call4_00321cb0(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001de568

// 001de590 (was src/anon/batch_wcx2.cpp)
namespace n001de590 {
// 001b14d8: moved to src/anon/unit_001b14d8.cpp

// ---- 001de590
extern u8* D_00352b58 asm("D_00352b58");
s32 func_001dc9e0(u8*) asm("func_001dc9e0");
void f1de590_update(u8*) asm("func_001dfa38");
/*TARGET 001de590*/
void func_001de590(u8* p) asm("func_001de590");
void func_001de590(u8* p) {
    u8* o = *(u8**)(p + 12);
    while (o) {
        u8* nx = *(u8**)(o + 96);
        if (func_001dc9e0(*(u8**)(o + 64))) {
            u8 b = (*(s32*)(*(u8**)(o + 64) + 8) >> 26) & 1;
            if (!b) {
                D_00352b58 = o;
                f1de590_update(o);
                D_00352b58 = 0;
            }
        }
        o = nx;
    }
}
}  // namespace n001de590

// 001de610 (was src/anon/batch_w57.cpp)
namespace n001de610 {
extern void (**D_0032b914)() asm("D_0032b914");
// 0x001d8070: definition moved into src/anon/unit_001d7458.cpp

// Drop every list entry whose owner is still valid.
u32 func_001dca20(void*) asm("func_001dca20");
// get_bit20_of_field8
void func_00321ce8(void*, void*) asm("func_00321ce8");
// list_unlink_node
void func_001e0058(void*) asm("func_001e0058");
/*TARGET 001de610*/
void func_001de610(u8* t) asm("func_001de610");
void func_001de610(u8* t) {
    u8* n = *(u8**)(t + 12);
    while (n) {
        u8* a = *(u8**)(n + 64);
        u8 bit = (*(s32*)(a + 8) >> 26) & 1;
        u8* nx = *(u8**)(n + 96);
        if (!bit) {
            if (func_001dca20(a)) {  // get_bit20_of_field8
                func_00321ce8(t + 12, n);  // list_unlink_node
                func_001e0058(n);
            }
        }
        n = nx;
    }
}
}  // namespace n001de610

// 001de690 (was src/anon/tiny_auto80_queue.cpp)
namespace n001de690 {
extern u32 D_01d9e348 asm("D_01d9e348");
void func_001de590(...) asm("func_001de590");
/*TARGET 001de690*/
void func_001de690(void) asm("_Z13func_001de690v");
void func_001de690(void) {
    u32 s0 = D_01d9e348;
    while (s0 != 0u) {
        u32 next = *(u32*)(u32)(s0 + 20);
        func_001de590(s0);
        s0 = next;
    }
}
}  // namespace n001de690

// 001de6d0 (was src/anon/tiny_auto80_queue.cpp)
namespace n001de6d0 {
extern u32 D_01d9e348 asm("D_01d9e348");
void func_001de610(...) asm("func_001de610");
/*TARGET 001de6d0*/
void func_001de6d0(void) asm("_Z13func_001de6d0v");
void func_001de6d0(void) {
    u32 s0 = D_01d9e348;
    while (s0 != 0u) {
        u32 next = *(u32*)(u32)(s0 + 20);
        func_001de610(s0);
        s0 = next;
    }
}
}  // namespace n001de6d0

// 001de710 (was src/anon/tiny_auto80_queue.cpp)
namespace n001de710 {
extern u32 D_01d9e348 asm("D_01d9e348");
u32 func_001dde40(...) asm("func_001dde40");
/*TARGET 001de710*/
void func_001de710(void) asm("_Z13func_001de710v");
void func_001de710(void) {
    u32 s0 = D_01d9e348;
    while (s0 != 0u) {
        u32 next = *(u32*)(u32)(s0 + 20);
        func_001dde40(s0);
        s0 = next;
    }
}
}  // namespace n001de710

// 001de750 (was src/anon/tiny_wrappers_more.cpp)
namespace n001de750 {
u32 func_001dc098(u32, u32, u32, u32) asm("_Z13func_001dc098jjjj");
/*TARGET 001de750*/
// 0x001ddcb0: definition moved into src/anon/unit_001dd920.cpp

u32 func_001de750(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001de750jjjj");
// 0x001ddcb0: definition moved into src/anon/unit_001dd920.cpp

u32 func_001de750(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001dc098(((u32)(((u32)(*(u32*)((u32)(a0) + 12u)))) + (u32)(a0)), a1, a2, a3);
}
}  // namespace n001de750

// 001de770 (was src/anon/tiny_wrappers_more.cpp)
namespace n001de770 {
u32 func_001dc140(u32, u32, u32, u32) asm("_Z13func_001dc140jjjj");
/*TARGET 001de770*/
u32 func_001de770(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001de770jjjj");
u32 func_001de770(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001dc140(((u32)(((u32)(*(u32*)((u32)(a0) + 12u)))) + (u32)(a0)), ((u32)(((u32)(*(u32*)((u32)(a0) + 12u)))) + (u32)(a1)), a2, a3);
}
}  // namespace n001de770

// 001de798 (was gap)
namespace n001de798 {
s32 func_001dcd88_798() asm("func_001dcd88");
s32 gap_001de798() asm("gap_001de798");
s32 gap_001de798() { return func_001dcd88_798(); }
}  // namespace n001de798

// 001de7b0 (was src/anon/tiny_auto80_queue.cpp)
namespace n001de7b0 {
u32 func_001dcd58(...) asm("func_001dcd58");
u32 func_001dcd88(...) asm("func_001dcd88");
/*TARGET 001de7b0*/
u32 func_001de7b0(u32 a0) asm("_Z13func_001de7b0j");
u32 func_001de7b0(u32 a0) {
    a0 = (u32)(a0 & 0xffu);
    if (a0 == 1u) {
        return func_001dcd88();
    }
    return func_001dcd58();
}
}  // namespace n001de7b0

// 001de7d8 (was src/anon/batch_w7.cpp)
namespace n001de7d8 {
void func_001dcdb8(void) asm("func_001dcdb8");
void func_001de808(void) asm("func_001de808");
extern u32 D_01d9e340 asm("D_01d9e340");
struct ZeroPair { u32 a, b; };
extern ZeroPair D_01d9e348 asm("D_01d9e348");
/*TARGET 001de7d8*/
// 0x001dc5f8: definition moved into src/anon/unit_001dbfd8.cpp

void func_001de7d8(u32 a0) asm("func_001de7d8");
// 0x001dc5f8: definition moved into src/anon/unit_001dbfd8.cpp

void func_001de7d8(u32 a0) {
    D_01d9e340 = a0;
    func_001dcdb8();
    D_01d9e348.a = 0;
    D_01d9e348.b = 0;
    func_001de808();
}
}  // namespace n001de7d8

// 001de808 (was src/anon/batch_w1578_g.cpp)
namespace n001de808 {
struct W1578Mode { s32 pad; s32 id; };
W1578Mode* W1578_getFieldMode(void) asm("_Z12getFieldModev");
W1578Mode* W1578_getGumiBattleMode(void) asm("_Z17getGumiBattleModev");
void func_00102180(W1578Mode**) asm("func_00102180");
void func_001e02f8(s32) asm("func_001e02f8");
void func_001de8a8(s32, s32, s32, s32) asm("func_001de8a8");
/*TARGET 001de808*/
// 0x001d0068: definition moved into src/anon/unit_001cf0b0.cpp

void func_001de808(void) asm("func_001de808");
// 0x001d0068: definition moved into src/anon/unit_001cf0b0.cpp

void func_001de808(void) {
    W1578Mode* f = W1578_getFieldMode();
    W1578Mode* g = W1578_getGumiBattleMode();
    W1578Mode* cur;
    func_00102180(&cur);
    W1578Mode* c = cur;
    if (c == f) {
        func_001e02f8(1);
        func_001de8a8(c->id, 9, 20300, 0x16760);
    } else if (c == g) {
        func_001e02f8(2);
        func_001de8a8(g->id, 1, 31000, 0x11940);
    }
}
}  // namespace n001de808

// 001de8a8 (was src/anon/batch_w45.cpp)
namespace n001de8a8 {
u8* func_00102788(u32, u32, u32, void*) asm("func_00102788");
void func_001de690(void) asm("func_001de690");
void func_001de6d0(void) asm("func_001de6d0");
void func_001de710(void) asm("func_001de710");
/*TARGET 001de8a8*/
void func_001de8a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001de8a8");
void func_001de8a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    func_00102788(a0, a1, a2, (void*)func_001de690);
    u8* t = func_00102788(a0, a1, a3, (void*)func_001de6d0);
    *(void**)(t + 48) = (void*)func_001de710;
}
}  // namespace n001de8a8

// 001de910 (was src/anon/batch_w6.cpp)
namespace n001de910 {
// 0x001dcd88: definition moved into src/anon/unit_001dbfd8.cpp

struct Pair { u32 a, b; };
void func_001de690(u32) asm("func_001de690");
void func_001dced0(void) asm("func_001dced0");
extern Pair D_01d9e348 asm("D_01d9e348");
/*TARGET 001de910*/
void func_001de910(void) asm("func_001de910");
void func_001de910(void) {
    func_001de690(0);
    D_01d9e348.a = 0;
    D_01d9e348.b = 0;
    func_001dced0();
}
}  // namespace n001de910

// 001de940 (was gap)
namespace n001de940 {
void gap_001de940() asm("gap_001de940");
void gap_001de940() {}
}  // namespace n001de940

// 001de948 (was src/anon/batch_w8.cpp)
namespace n001de948 {
typedef u32 (*VR3)(void*, u32, u32);
// 0x001dc620: definition moved into src/anon/unit_001dbfd8.cpp

extern void** D_01d9e340 asm("D_01d9e340");
/*TARGET 001de948*/
u32 func_001de948(u32 x) asm("func_001de948");
u32 func_001de948(u32 x) {
    void** o = D_01d9e340;
    return ((VR3)(*(void***)o)[0])(o, x, 0);
}
}  // namespace n001de948

// 001de978 (was src/anon/batch_w9.cpp)
namespace n001de978 {
extern void* D_01d9e340 asm("D_01d9e340");
/*TARGET 001de978*/
// 0x001dc648: definition moved into src/anon/unit_001dbfd8.cpp

void func_001de978(u32 a) asm("func_001de978");
// 0x001dc648: definition moved into src/anon/unit_001dbfd8.cpp

void func_001de978(u32 a) {
    void* o = D_01d9e340;
    (*(void (**)(void*, u32))(*(u8**)o + 4))(o, a);
}
}  // namespace n001de978

