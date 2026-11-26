// Linked unit 0x002cf260-0x002d2330: Ti::LFlag, the minigame object queue (0x361fa0) and Ti::MGOarashi
// (minigame "po_06"). Built from the old per-function sources; gap functions marked "never written before".
#include "../taito/minigame.hpp"
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../taito/mg_oarashi.hpp"

// 002cf260, 002cf268: Ti::LFlag::LFlag (C2 copy, never written before, and C1; was src/taito/minigame.cpp)
namespace nLFlag {
void LFlag_C2(u32* f, u32 bits) asm("_ZN2Ti5LFlagC2Ej");
void LFlag_C2(u32* f, u32 bits) { *f = bits; }
void LFlag_C1(u32* f, u32 bits) asm("_ZN2Ti5LFlagC1Ej");
void LFlag_C1(u32* f, u32 bits) { *f = bits; }
}  // namespace nLFlag

// 002cf270 (was src/taito/minigame.cpp)
namespace nLFlag {
bool LFlag_check(u32* f, u32 bits) asm("_ZN2Ti5LFlag5checkEj");
bool LFlag_check(u32* f, u32 bits) { return (*f & bits) != 0; }
}  // namespace nLFlag

// 002cf280 (was src/anon/tiny_auto80_queue.cpp)
namespace n002cf280 {
/*TARGET 002cf280*/
// 002cf1b8: moved to src/taito/minigame_base.cpp (linked unit)

void func_002cf280(u32 a0, u32 a1, u32 a2) asm("_Z13func_002cf280jjj");
// 002cf1b8: moved to src/taito/minigame_base.cpp (linked unit)

void func_002cf280(u32 a0, u32 a1, u32 a2) {
    u32 t6 = a1 & a2;
    if (a2 == 0) {
        *(u32*)a0 = *(u32*)a0 | a1;
        return;
    }
    u32 t5 = ~a2;
    u32 t7 = *(u32*)a0;
    t7 = t7 & t5;
    *(u32*)a0 = t7 | t6;
}
}  // namespace n002cf280

// 002cf2b0 (was src/taito/minigame.cpp)
namespace nLFlag {
void func_002cf280(u32, u32, u32) asm("func_002cf280");
void LFlag_reset(u32* f, u32 bits) asm("_ZN2Ti5LFlag5resetEj");
void LFlag_reset(u32* f, u32 bits) { func_002cf280((u32)f, 0, bits); }
}  // namespace nLFlag

// 002cf2d0 (was src/taito/minigame.cpp)
namespace nLFlag {
void LFlag_zero(u32* f) asm("_ZN2Ti5LFlag4zeroEv");
void LFlag_zero(u32* f) { *f = 0; }
}  // namespace nLFlag

// 002cf2d8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002cf2d8 {
extern u32 D_00361fb0 asm("D_00361fb0");
/*TARGET 002cf2d8*/
void func_002cf2d8() asm("_Z13func_002cf2d8v");
void func_002cf2d8() {
    s32 i = 2;
    u32* p = &D_00361fb0;
    do {
        *p = 0;
        i -= 1;
        p += 1;
    } while (i >= 0);
}
}  // namespace n002cf2d8

// 002cf308 (was src/anon/tiny_more2.cpp)
namespace n002cf308 {
extern u32 D_00361fb0 asm("D_00361fb0");
/*TARGET 002cf308*/
u32 Ti__MGObj__get_prize_count(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z26Ti__MGObj__get_prize_countjjjj");
u32 Ti__MGObj__get_prize_count(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u32*)((u32)&D_00361fb0 + ((u32)a0 << 2) + (0)); }
}  // namespace n002cf308

// 002cf320 (was src/anon/batch_w8024.cpp)
void* func_001063f0(u32, s32) asm("func_001063f0");
inline void* operator new[](unsigned int sz, s32 h) { return func_001063f0(sz, h); }
namespace n002cf320 {
s32 func_001050c8(void) asm("func_001050c8");
void func_002cf268(void*, s32) asm("func_002cf268");
struct SubQ_w8024 { s32 x; SubQ_w8024() { func_002cf268(this, 0); } };
struct ElemQ_w8024 { s32 a; SubQ_w8024 b; s32 c[8]; ElemQ_w8024() : a(0) { c[0]=0; c[1]=0; c[2]=0; c[3]=0; c[4]=0; c[5]=0; c[6]=0; c[7]=0; } };
extern s32 D_00361fa0 asm("D_00361fa0");
extern ElemQ_w8024* D_00361fa4 asm("D_00361fa4");
extern s32 D_00361fa8 asm("D_00361fa8");
/*TARGET 002cf320*/
void func_002cf320(s32 n) asm("func_002cf320");
void func_002cf320(s32 n)
{
    D_00361fa0 = n;
    D_00361fa8 = 0;
    D_00361fa4 = 0;
    if (n > 0) D_00361fa4 = new (func_001050c8()) ElemQ_w8024[n];
    else D_00361fa4 = 0;
}
}  // namespace n002cf320

// 002cf3f8 (was src/anon/batch_w29.cpp)
namespace n002cf3f8 {
void ctarget_002cf3f8(void) asm("_Z16ctarget_002cf3f8jjjj");
void func_00106450(u32) asm("func_00106450");
extern u32 D_00361fa4 asm("D_00361fa4");
extern u32 D_00361fa0 asm("D_00361fa0");
/*TARGET 002cf3f8*/
// 0x002bfd48: definition moved into src/anon/unit_002bebd0.cpp

void ctarget_002cf3f8(void) asm("_Z16ctarget_002cf3f8jjjj");
// 0x002bfd48: definition moved into src/anon/unit_002bebd0.cpp

void ctarget_002cf3f8(void) {
    if (D_00361fa4) func_00106450(D_00361fa4);
    D_00361fa4 = 0;
    D_00361fa0 = 0;
}
}  // namespace n002cf3f8

// 002cf438 (gap function, never written before)
namespace n002cf438 {
struct V4g { f32 x, y, z, w; V4g(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; } };
u8* func_0016f000(u32, V4g*, f32) asm("func_0016f000");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
u8* func_002cf438(u32 id) asm("func_002cf438");
u8* func_002cf438(u32 id)
{
    V4g v(0.0f, 0.0f, 0.0f, 0.0f);
    u8* o = func_0016f000(id, &v, 0.0f);
    if (*(u32*)(o + 1416) & 0x8000000) func_002cf270(o + 2800, 0x1000);
    *(u32*)(o + 264) |= 0x400;
    return o;
}
}  // namespace n002cf438

// 002cf4a8 (was src/anon/batch_w108.cpp)
namespace n002cf4a8 {
struct Info2cf {
    s32 id;
    f32 x, y, z;
};
struct Ref2cf {
    u8 pad[16];
    u16* data;
};
struct Params2cf {
    s32 f0;
    u32 f4;
    u32 f8;
    Info2cf* info;
    u32 f16;
    s32 f20;
    union { Ref2cf* ref0; u32 ref0u; };
    union { Ref2cf* ref1; u32 ref1u; };
};
struct Ctx2cf {
    u8 pad[92];
    u32 f92;
};
extern Ctx2cf* D_00361f60 asm("D_00361f60");
extern s32 D_00361fa8 asm("D_00361fa8");
u8* YS__OBJ__Each(u8*) asm("YS__OBJ__Each");
s32 func_0016a020(u8*) asm("func_0016a020");
s32 func_0019c768(u8*) asm("func_0019c768");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
u8* func_00199938(Info2cf*, s32) asm("func_00199938");
void func_002cff50(u8*) asm("func_002cff50");
u32 func_002e3260(u32, s32, u16) asm("func_002e3260");
void func_0016ace0(u8*, f32*) asm("func_0016ace0");
void func_002d0d88(u8*) asm("func_002d0d88");
static inline void SetPos2cf(f32* v, f32 x, f32 y, f32 z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = 0.0f;
}
/*TARGET 002cf4a8*/
// Finds a reusable spawned object matching p->info (or creates one) and places it.
u8* func_002cf4a8(Params2cf* p) asm("func_002cf4a8");
// Finds a reusable spawned object matching p->info (or creates one) and places it.
u8* func_002cf4a8(Params2cf* p)
{
    u8* it = 0;
    u8* obj = 0;
    f32 pos[4];

    while ((it = YS__OBJ__Each(it)) != 0) {
        if (!(*(u32*)(it + 1416) & 0x08000000)) continue;
        if (func_0016a020(it) != p->info->id) continue;
        if (!func_0019c768(it)) continue;
        if (!func_002cf270(it + 2800, 4096)) continue;
        if (*(s32*)(it + 2832) > 0) continue;
        obj = it;
        break;
    }
    if (obj == 0) {
        obj = func_00199938(p->info, p->f20);
    }
    if (func_0019c768(obj)) {
        func_002cff50(obj);
    }
    if (p->ref0) {
        *(u32*)(obj + 2808) = func_002e3260(D_00361f60->f92, p->f0, *p->ref0->data);
        *(u32*)(obj + 2812) = (u32)p->ref0->data;
        *(u32*)(obj + 2816) = p->ref1 ? (u32)p->ref1->data : 0;
    }
    if (func_0019c768(obj)) {
        SetPos2cf(pos, p->info->x, p->info->y, p->info->z);
        func_0016ace0(obj, pos);
        func_002d0d88(obj);
    } else {
        D_00361fa8++;
    }
    return obj;
}
}  // namespace n002cf4a8

// 002cf638 (was src/anon/batch_w99.cpp)
namespace n002cf638 {
struct E2cf6 { u32 used; u8 obj[8]; u32 w12; u32 w16; u8 pad[16]; s32 w36; };
extern s32 D_00361fa0 asm("D_00361fa0");
extern E2cf6* D_00361fa4 asm("D_00361fa4");
s32 func_002cf270(void*, s32) asm("func_002cf270");
/*TARGET 002cf638*/
// Scans the slot table; returns the index just past the last busy slot once n free slots were seen, or -1.
s32 Ti__MGObj__find_free_member_buffer(s32 n) asm("Ti__MGObj__find_free_member_buffer");
// Scans the slot table; returns the index just past the last busy slot once n free slots were seen, or -1.
s32 Ti__MGObj__find_free_member_buffer(s32 n)
{
    s32 i;
    s32 cnt = 0;
    s32 last = 0;
    for (i = 0; i < D_00361fa0; i++) {
        E2cf6* e = &D_00361fa4[i];
        s32 ok = 0;
        if (!e->used || (e->w12 && func_002cf270(e->obj, 2))) ok = 1;
        else if (e->w16) ok = e->w36 < 1;
        if (ok) {
            if (++cnt >= n) return last;
        } else {
            last = i + 1;
        }
    }
    return -1;
}
}  // namespace n002cf638

// 002cf750 (was src/anon/batch_wcx2.cpp)
namespace n002cf750 {
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
struct Ref99 { u8 pad[36]; s32 ref; };
struct Hdr99 { u32 type; u8 pad; u8 kind; };
struct Node99 { u32 a; u8 sub[4]; s32 cat; u32* p; u32 f16; u32 b; Ref99* r0; Ref99* r1; u32 pad; s32 f36; };
extern Node99* D_00361fa4 asm("D_00361fa4");
extern s32 D_00361fb0[] asm("D_00361fb0");
Hdr99* func_0016e920(u32) asm("func_0016e920");
s32 Ti__MGObj__IsInitAppear(Hdr99*) asm("Ti__MGObj__IsInitAppear");
s32 func_002cf638_115228(s32) asm("Ti__MGObj__find_free_member_buffer");
void func_002cf2d0(u8*) asm("func_002cf2d0");
void func_002cf280(u8*, s32, s32) asm("func_002cf280");
/*TARGET 002cf750*/
Node99* func_002cf750(u32 a, u32 b, u32* p, Ref99* r0, Ref99* r1) asm("func_002cf750");
Node99* func_002cf750(u32 a, u32 b, u32* p, Ref99* r0, Ref99* r1)
{
    Hdr99* h = func_0016e920(*p);
    if (Ti__MGObj__IsInitAppear(h)) return 0;
    s32 idx = func_002cf638_115228(1);
    Node99* n = D_00361fa4 + idx;
    n->a = a;
    n->b = b;
    n->p = p;
    n->cat = 0;
    n->f16 = 0;
    n->r0 = r0;
    if (r0) r0->ref++;
    n->r1 = r1;
    if (r1) r1->ref++;
    func_002cf2d0(n->sub);
    n->f36 = 0;
    if (h->kind == 51) {
        func_002cf280(n->sub, 4, 0);
        switch (h->type) {
        case 2055: n->cat = 1; break;
        case 2054: n->cat = 2; break;
        case 2056: n->cat = 0; break;
        }
        D_00361fb0[n->cat]++;
    }
    return n;
}
}  // namespace n002cf750

// 002cf8c0 (was src/anon/batch_w39.cpp)
namespace n002cf8c0 {
// 0x002bd7d8: definition moved into src/anon/unit_002bc978.cpp

// --- 002cf8c0
union U2cf { u32 w; u16 h[2]; };
struct S2cf { u32 a; u32 b; u32 c; u32 d; U2cf* e; u32 f; u32 pad[3]; u32 g; };
extern S2cf* D_00361fa4 asm("D_00361fa4");
void func_002cf280(u32*, int, int) asm("func_002cf280");
/*TARGET 002cf8c0*/
S2cf* func_002cf8c0(int idx, u32 a, u32 b, U2cf* c) asm("func_002cf8c0");
S2cf* func_002cf8c0(int idx, u32 a, u32 b, U2cf* c) {
    S2cf* e = &D_00361fa4[idx];
    e->a = a;
    e->f = b;
    e->c = 0;
    e->e = c;
    e->d = 0;
    e->g = 0;
    if (c->h[1] == 3) func_002cf280(&e->b, 16, 0);
    return e;
}
}  // namespace n002cf8c0

// 002cf938 (was src/anon/batch_w44.cpp)
namespace n002cf938 {
void YS__UNIT__InitMinigame(void) asm("YS__UNIT__InitMinigame");
// 0x002c2168: definition moved into src/anon/unit_002c1e80.cpp

extern s32 D_00361fa0 asm("D_00361fa0");
extern u8* volatile D_00361fa4 asm("D_00361fa4");
/*TARGET 002cf938*/
void Ti__MGObj__reset_all_members(u8 on) asm("Ti__MGObj__reset_all_members");
void Ti__MGObj__reset_all_members(u8 on) {  // count_entries_masked
    if (on && D_00361fa4) {
        for (s32 i = 0; i < D_00361fa0; i++) *(u32*)(D_00361fa4 + i * 40) = 0;
    }
    YS__UNIT__InitMinigame();
}
}  // namespace n002cf938

// 002cf998 (was src/anon/batch_w8012_g.cpp)
namespace n002cf998 {
struct V4_2cf998 { f32 x, y, z, w; };
static inline __attribute__((always_inline)) void set4_2cf998(V4_2cf998* v, f32 x, f32 y, f32 z, f32 w) {
    v->w = w;
    v->x = x;
    v->y = y;
    v->z = z;
}
struct E2cf998 { s32 on; u8 flags[12]; f32* pos; u8 pad[20]; };
s32 func_002ceb28(void) asm("func_002ceb28");
s32 func_00197920(void) asm("func_00197920");
s32 func_002cf270(void*, s32) asm("func_002cf270");
void func_002cf280(void*, s32, s32) asm("func_002cf280");
void func_002cf2b0(void*, s32) asm("func_002cf2b0");
void func_001444c8(void*, V4_2cf998*, V4_2cf998*) asm("func_001444c8");
s32 func_002cec20(s32, void*) asm("func_002cec20");
extern s32 D_00361fa0 asm("D_00361fa0");
extern E2cf998* D_00361fa4 asm("D_00361fa4");
extern s32 D_00361f60 asm("D_00361f60");
/*TARGET 002cf998*/
void func_002cf998(void) asm("func_002cf998");
void func_002cf998(void) {
    V4_2cf998 lo;
    V4_2cf998 hi;
    u8 box[32];
    s32 i;
    E2cf998* e;
    f32* p;
    f32 z;
    f32 r;
    s32* g;
    u8* b;
    if (!func_002ceb28()) return;
    if (func_00197920()) return;
    i = 0;
    if (D_00361fa0 <= 0) return;
    do {
        e = &D_00361fa4[i];
        if (e->on == 0) goto next;
        if (e->pos == 0) goto next;
        if (!func_002cf270(e->flags, 16)) goto next;
        p = e->pos;
        b = box;
        r = 1.0f;
        z = 0.0f;
        set4_2cf998(&lo, p[1] - r, p[2] - r, p[3] - r, z);
        set4_2cf998(&hi, p[1] + r, p[2] + r, p[3] + r, z);
        g = &D_00361f60;
        func_001444c8(b, &lo, &hi);
        if (func_002cec20(*g, b)) func_002cf280(e->flags, 32, 0);
        else func_002cf2b0(e->flags, 32);
    next:
        i++;
    } while (i < D_00361fa0);
}
}  // namespace n002cf998

// 002cfb30 (was src/anon/batch_w2425_gnsa.cpp)
namespace n002cfb30 {
struct V2cfb30 {
    f32 x, y, z, w;
    V2cfb30() {}
    V2cfb30(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));
struct Obj2cfb30 { u8 pad[1416]; u32 flags; u8 pad2[2800 - 1420]; u8 lflag[32]; s32 balloons; };
struct Ref2cfb30 { u8 pad[16]; u16* id; u8 pad2[16]; s32 refs; };
struct Item2cfb30 { s32 kind; f32 px, py, pz; f32 rx, ry, rz; };
struct Ent2cfb30 {
    s32 id;
    u8 lflag[4];
    s32 arg;
    Item2cfb30* item;
    u8 pad[8];
    Ref2cfb30* ref0;
    Ref2cfb30* ref1;
    f32 timer;
    u8 pad2[4];
};
struct Game2cfb30;
struct Game2cfb30Vt { void* f[6]; s32 (*check)(Game2cfb30*, Ent2cfb30*); };
struct Game2cfb30 { Game2cfb30Vt* vt; u8 pad[88]; s32 table; };
struct Rec2cfb30 { u8 pad[16]; s16 time; };
extern s32 D_00361fa0 asm("D_00361fa0");
extern Ent2cfb30* D_00361fa4 asm("D_00361fa4");
extern s32 D_00361fa8 asm("D_00361fa8");
extern Game2cfb30* D_00361f60 asm("D_00361f60");
extern f32 D_00349e10 asm("D_00349e10");
s32 g2cfb30_be_ready(void) asm("_ZN2Ti8MiniGame8be_readyEv");
s32 g2cfb30_IsExec(void) asm("_ZN2YS5EVENT6IsExecEv");
Obj2cfb30* g2cfb30_next(Obj2cfb30*) asm("_Z13YS__OBJ__Eachjjjj");
s32 g2cfb30_is_ghost(Obj2cfb30*) asm("_ZN2YS3OBJ8is_ghostEv");
s32 g2cfb30_check(void*, u32) asm("_ZN2Ti5LFlag5checkEj");
void g2cfb30_set(void*, u32, s32) asm("_Z16wtarget_002cf280jjjj");
Obj2cfb30* func_002cf4a8(Ent2cfb30*) asm("func_002cf4a8");
Obj2cfb30* func_0016f000(s32, V2cfb30*, f32) asm("func_0016f000");
void g2cfb30_set_balloon(Obj2cfb30*, Obj2cfb30*) asm("_ZN2Ti18MGHachimitsuGopher11set_balloonEPNS_5MGObjE");
void func_001cbcf0(V2cfb30*, V2cfb30*, s32) asm("func_001cbcf0");
s32 g2cfb30_type(void) asm("_ZN2Ti8MiniGame4typeEv");
Rec2cfb30* func_002e3260(s32, s32, u16) asm("func_002e3260");
s32 g2cfb30_001c0d38s(Obj2cfb30*, Obj2cfb30*, s32, s32) asm("_Z15YS__OBJ__attachjjjj");
/*TARGET 002cfb30*/
void func_002cfb30(void) asm("func_002cfb30");
void func_002cfb30(void)
{
    if (!g2cfb30_be_ready() || g2cfb30_IsExec()) return;
    Obj2cfb30* o = 0;
    while ((o = g2cfb30_next(o)) != 0) {
        if ((o->flags & 0x08000000) && g2cfb30_is_ghost(o) && g2cfb30_check(o->lflag, 0x1000)) {
            if (o->balloons > 0) o->balloons--;
        }
    }
    for (s32 i = 0; i < D_00361fa0; i++) {
        Ent2cfb30* e = &D_00361fa4[i];
        if (!e->id) continue;
        if (!e->item) continue;
        if (g2cfb30_check(e->lflag, 2)) continue;
        s32 fire = 0;
        if (g2cfb30_check(e->lflag, 64)) {
            e->timer -= D_00349e10;
            if (e->timer <= 0.0f) fire = 1;
        } else if (D_00361f60->vt->check(D_00361f60, e)) {
            fire = 1;
            if (g2cfb30_type() == 0 || g2cfb30_type() == 2) {
                Ref2cfb30* r = e->ref0;
                if (r) {
                    Rec2cfb30* rec = func_002e3260(D_00361f60->table, e->id, *r->id);
                    if (rec && rec->time > 0) {
                        fire = 0;
                        g2cfb30_set(e->lflag, 64, 0);
                        e->timer = rec->time * 60.0f;
                    }
                }
            }
        }
        if (!fire) continue;
        if (g2cfb30_check(e->lflag, 4)) {
            V2cfb30 pos(e->item->px, e->item->py, e->item->pz, 0.0f);
            V2cfb30 rot(e->item->rx, -e->item->ry, -e->item->rz, 0.0f);
            func_001cbcf0(&pos, &rot, e->arg);
        } else {
            Obj2cfb30* owner = func_002cf4a8(e);
            if (e->item->kind == 1631) {
                V2cfb30 z(0.0f, 0.0f, 0.0f, 0.0f);
                Obj2cfb30* b = func_0016f000(1634, &z, 0.0f);
                g2cfb30_001c0d38s(b, owner, 0x4000, 0);
                g2cfb30_set_balloon(owner, b);
                D_00361fa8++;
                g2cfb30_set(owner->lflag, 64, 0);
                g2cfb30_set(b->lflag, 64, 0);
            }
        }
        g2cfb30_set(e->lflag, 2, 0);
        if (e->ref0) e->ref0->refs--;
        if (e->ref1) e->ref1->refs--;
    }
}
}  // namespace n002cfb30

// 002cfeb0 (was src/anon/tiny_auto80_solver.cpp)
namespace n002cfeb0 {
u32 func_002cf268(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002cf268jjjjjjjj");
u32 func_002cfeb0(u32) asm("_Z13func_002cfeb0j");
// obj_init_field1416_bit800
u32 func_002cff50(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002cff50jjjjjjjj");
extern u8 D_00361fc8 asm("D_00361fc8");
u32 func_001b3b70(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001b3b70jjjjjjjj");
/*TARGET 002cfeb0*/
u32 func_002cfeb0(u32 a0) asm("_Z13func_002cfeb0j");
u32 func_002cfeb0(u32 a0) {  // obj_init_field1416_bit800
    u32 s0 = a0;
    ((u32(*)(u32))func_001b3b70)(a0);
    *(u32*)s0 = (u32)&D_00361fc8;
    ((u32(*)(u32, u32))func_002cf268)(s0 + 2800, 0);
    *(u32*)(s0 + 1416) |= 0x08000000u;
    return ((u32(*)(u32))func_002cff50)(s0);
}
}  // namespace n002cfeb0

// 002cff00 (was src/anon/auto200_999.cpp)
namespace n002cff00 {
u32 func_001b3b70(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001b3b70jjjjjjjj");
u32 func_002cf268(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002cf268jjjjjjjj");
u32 func_002cff50(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002cff50jjjjjjjj");
extern u8 D_00361fc8 asm("D_00361fc8");
/*TARGET 002cff00*/
// 00290610: moved to src/anon/unit_0028f1e0.cpp

u32 Ti__MGObj__MGObj(u32 a0) asm("_Z16Ti__MGObj__MGObjj");
// 00290610: moved to src/anon/unit_0028f1e0.cpp

u32 Ti__MGObj__MGObj(u32 a0) {
    u32 s0 = a0;
    ((u32 (*)(u32))func_001b3b70)(a0);
    *(u32 *)s0 = (u32)&D_00361fc8;
    ((u32 (*)(u32, u32))func_002cf268)(s0 + 2800, 0);
    *(u32 *)(s0 + 1416) |= 0x08000000u;
    return ((u32 (*)(u32))func_002cff50)(s0);
}
}  // namespace n002cff00

// 002cff50 (was src/anon/batch_w25.cpp)
namespace n002cff50 {
// 0x002be960: definition moved into src/anon/unit_002be020.cpp

void func_002cf2d0(void*) asm("func_002cf2d0");
/*TARGET 002cff50*/
void func_002cff50(u8* o) asm("func_002cff50");
void func_002cff50(u8* o) {
    func_002cf2d0(o + 2800);
    *(u32*)(o + 2804) = 0;
    *(u32*)(o + 2808) = 0;
    *(u32*)(o + 2812) = 0;
    *(u32*)(o + 2816) = 0;
    *(u32*)(o + 2820) = 0;
    *(u32*)(o + 2824) = 0;
    *(u32*)(o + 2828) = 0;
}
}  // namespace n002cff50

// 002cff98 (was src/anon/batch_w26.cpp)
namespace n002cff98 {
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
u8 func_00319fb0(void*) asm("func_00319fb0");
extern u8 D_0034ee08[] asm("D_0034ee08");
/*TARGET 002cff98*/
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_002cff98(u8* o) asm("func_002cff98");
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_002cff98(u8* o) {
    *(u8**)o = D_0034ee08;
    YS__OBJ_ATTACK__clear(o + 2568);  // array8_free_slots
    func_001c0248(o + 2640);
    return func_00319fb0(o);  // big_obj_dtor
}
}  // namespace n002cff98

// 002cffe0 (was src/anon/batch_w27.cpp)
namespace n002cffe0 {
// An empty-destructor local keeps a cleanup pending, which stops gcc from
// turning the final call into a sibling call (as in the game's destructors).
struct NoTail { ~NoTail() {} };
// 002ceaa8: moved to src/taito/minigame_base.cpp (linked unit)

extern u32 D_0034ee08 asm("D_0034ee08");
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
void func_00319fb0(void*) asm("func_00319fb0");
/*TARGET 002cffe0*/
// big_obj_dtor
void func_002cffe0(u8* p) asm("func_002cffe0");
// big_obj_dtor
void func_002cffe0(u8* p) {
    NoTail g;
    *(void**)p = &D_0034ee08;
    YS__OBJ_ATTACK__clear(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
}
}  // namespace n002cffe0

// 002d0028 (was src/anon/batch_w30.cpp)
namespace n002d0028 {
// strlen
extern u8 D_0034ee08[] asm("D_0034ee08");
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
u8 func_00319fb0(void*) asm("func_00319fb0");
// big_obj_dtor
void func_00105110(void*) asm("func_00105110");
/*TARGET 002d0028*/
// Deleting destructor.
void func_002d0028(u8* p) asm("func_002d0028");
// Deleting destructor.
void func_002d0028(u8* p) {
    *(void**)p = D_0034ee08;
    YS__OBJ_ATTACK__clear(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}
}  // namespace n002d0028

// 002d0070 (was src/anon/tiny_jal_wrappers.cpp)
namespace n002d0070 {
u32 func_00186008(u32, u32, u32, u32) asm("_Z13func_00186008jjjj");
/*TARGET 002d0070*/
// 0x002c60f8: definition moved into src/anon/unit_002c53c8.cpp

u32 func_002d0070(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d0070jjjj");
// 0x002c60f8: definition moved into src/anon/unit_002c53c8.cpp

u32 func_002d0070(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r2 = func_00186008(r4, r5, r6, r7);
    r14 = (u32)(0x0036u << 16);
    r15 = *(u32*)((u32)r14 + (s32)(8104));
    r15 = (u32)((s32)r15 + (-1));
    *(u32*)((u32)r14 + (s32)(8104)) = r15;
    return r2;
}
}  // namespace n002d0070

// 002d00a0 (was src/anon/tiny_auto80_solver.cpp)
namespace n002d00a0 {
u32 YS__STDOBJ___OVR_initialize(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z27YS__STDOBJ___OVR_initializejjjjjjjj");
u32 func_002d00a0(u32) asm("_Z13func_002d00a0j");
/*TARGET 002d00a0*/
u32 func_002d00a0(u32 a0) asm("_Z13func_002d00a0j");
u32 func_002d00a0(u32 a0) {
    u32 s0 = a0;
    ((u32(*)(u32))YS__STDOBJ___OVR_initialize)(a0);
    void (**vt)() = *(void (***)())s0;
    ((void (*)(u32))vt[31])(s0);
}
}  // namespace n002d00a0

// 002d00d8 (was src/anon/misc_2.cpp)
namespace n002d00d8 {
/*TARGET 002d00d8*/
// 0x002cb918: definition moved into src/taito/path.cpp

void func_002d00d8(void* self) asm("_Z13func_002d00d8Pv");
// 0x002cb918: definition moved into src/taito/path.cpp

void func_002d00d8(void* self) { *(s32*)((char*)self + 2832) = 0; }
}  // namespace n002d00d8

// 002d00e0 (was src/anon/batch_w92.cpp)
namespace n002d00e0 {
struct Mgr2d0 { s32 (**vt)(Mgr2d0*, u8*); };
u8* YS__OBJ__Each(u8*) asm("YS__OBJ__Each");
s32 func_0019c768(u8*) asm("func_0019c768");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf2b0(u8*, s32) asm("func_002cf2b0");
void func_002d0c28(u8*) asm("func_002d0c28");
extern Mgr2d0* D_00361f60 asm("D_00361f60");
void wt_002d00e0(void) asm("_Z26Ti__MGObj__check_all_leavejjjj");
/*TARGET 002d00e0*/
void wt_002d00e0(void) asm("_Z26Ti__MGObj__check_all_leavejjjj");
void wt_002d00e0(void) {
    u8* o = 0;
    while ((o = YS__OBJ__Each(o)) != 0) {
        if (!(*(u32*)(o + 1416) & 0x8000000)) continue;
        if (func_0019c768(o)) continue;
        u8* st = o + 2800;
        if (func_002cf270(st, 0x2000)) {
            func_002d0c28(o);
            continue;
        }
        s32 ok = 0;
        if (func_002cf270(st, 4)) ok = 1;
        else if (func_002cf270(st, 1)) ok = D_00361f60->vt[7](D_00361f60, o) != 0;
        if (!ok) continue;
        func_002cf2b0(st, 4);
        func_002cf2b0(st, 1);
        if (func_002cf270(st, 0x1000)) func_002d0c28(o);
        else (*(void (**)(u8*))(*(u8**)o + 32))(o);
    }
}
}  // namespace n002d00e0

// 002d0200 (was src/anon/batch_w61.cpp)
namespace n002d0200 {
/*TARGET 002d0200*/
// 0x002c6280: definition moved into src/worldmap/cameramanager.cpp

s32 Ti__MGObj__IsInitAppear(u8* p) asm("Ti__MGObj__IsInitAppear");
// 0x002c6280: definition moved into src/worldmap/cameramanager.cpp

s32 Ti__MGObj__IsInitAppear(u8* p) {
    if (p[4] != 16) return 1;
    if (*(u32*)p == 1566) return 0;
    switch (p[5]) {
    case 0: case 1: case 2: case 5: case 6: case 15: case 16: case 17:
    case 25: case 27: case 200: case 201:
        return 1;
    }
    return 0;
}
}  // namespace n002d0200

// 002d0290 (was src/anon/batch_wcx2.cpp)
namespace n002d0290 {
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
// 0x00268db8: definition moved into src/anon/unit_00268b30.cpp

// ---- 002d0290
struct Src2d0 { s32 id; u8 pad; u8 type; };
struct Vec2d0 { f32 x, y, z, w; };
u8* AllocR(u32 size) asm("_ZN4AREA5AllocEj");
u32 func_00167f18_0290(s32 a) asm("func_00167f18");
void func_002d49c0(u8* p, Src2d0* s, u32 v, u32 a, f32 f) asm("func_002d49c0");
void func_002dd700(u8* p, Src2d0* s, u32 v, u32 a, f32 f) asm("func_002dd700");
void func_002d9730(u8* p, Src2d0* s, u32 v, u32 a, f32 f) asm("func_002d9730");
void Ti__MGObj__MGObj(u8* p, Src2d0* s, s32 k, u32 a, f32 f) asm("Ti__MGObj__MGObj");
void func_002db858(u8* p, Src2d0* s, u32 a, f32 f) asm("func_002db858");
void func_002db4f0(u8* p, Src2d0* s, u32 a, f32 f) asm("func_002db4f0");
void func_002d5d50(u8* p, Src2d0* s, u32 a, f32 f) asm("func_002d5d50");
void func_002d69c8(u8* p, Src2d0* s, u32 a, f32 f) asm("func_002d69c8");
void Ti__MGOarashiPiglet__MGOarashiPiglet(u8* p, Src2d0* s, u32 a, f32 f) asm("Ti__MGOarashiPiglet__MGOarashiPiglet");
void func_00177f50_0290(u8* p, Src2d0* s, s32 k, u32 v, u32 a, f32 f) asm("YS__PLAYER__PLAYER");
void func_002d29a8(u8* p, Src2d0* s, s32 k, u32 a, f32 f) asm("func_002d29a8");
void func_002dda88(u8* p, Src2d0* s, u32 a, f32 f) asm("func_002dda88");
void Ti__MGHachimitsuGopher__MGHachimitsuGopher(u8* p, Src2d0* s, u32 a, f32 f) asm("Ti__MGHachimitsuGopher__MGHachimitsuGopher");
void Ti__MGHachimitsuGimObj__MGHachimitsuGimObj(u8* p, Src2d0* s, u32 a, f32 f) asm("Ti__MGHachimitsuGimObj__MGHachimitsuGimObj");
void func_002db6b0(u8* p, Src2d0* s, u32 a, f32 f) asm("func_002db6b0");
void func_002de788(u8* p, Src2d0* s, Vec2d0* v, f32 f) asm("func_002de788");
/*TARGET 002d0290*/
// Create the effect object for a source entry according to its type.
u8* Ti__MGObj__create(Src2d0* s, u32 a, f32 f) asm("Ti__MGObj__create");
// Create the effect object for a source entry according to its type.
u8* Ti__MGObj__create(Src2d0* s, u32 a, f32 f) {
    u8* r = 0;
    u8* p;
    switch (s->type) {
    case 0:
        p = AllocR(3136);
        func_002d49c0(p, s, func_00167f18_0290(0), a, f);
        r = p;
        break;
    case 1:
        p = AllocR(3360);
        func_002d9730(p, s, func_00167f18_0290(0), a, f);
        r = p;
        break;
    case 2:
        p = AllocR(3088);
        func_002dd700(p, s, func_00167f18_0290(0), a, f);
        r = p;
        break;
    case 5:
    case 200:
        p = AllocR(2928);
        func_00177f50_0290(p, s, 11, func_00167f18_0290(0), a, f);
        r = p;
        break;
    case 6:
    case 100:
    case 201:
        p = AllocR(2848);
        Ti__MGObj__MGObj(p, s, 1, a, f);
        r = p;
        break;
    case 15:
        if (s->id == 1565) {
            p = AllocR(2912);
            func_002d5d50(p, s, a, f);
        } else if (s->id == 1628) {
            p = AllocR(2848);
            func_002d69c8(p, s, a, f);
        } else if (s->id == 1566) {
            p = AllocR(3248);
            Ti__MGOarashiPiglet__MGOarashiPiglet(p, s, a, f);
        } else {
            p = AllocR(2848);
            Ti__MGObj__MGObj(p, s, 0, a, f);
        }
        *(s32*)(p + 944) = 1;
        r = p;
        break;
    case 16:
        if (s->id == 1630) {
            p = AllocR(3072);
            func_002db858(p, s, a, f);
        } else {
            p = AllocR(2848);
            func_002db4f0(p, s, a, f);
        }
        *(s32*)(p + 944) = 1;
        r = p;
        break;
    case 17:
        if (s->id == 1635) {
            p = AllocR(2848);
            Vec2d0 v;
            f32 z = 0.0f;
            v.x = z;
            v.y = -300.0f;
            v.z = z;
            v.w = z;
            func_002de788(p, s, &v, z);
        } else {
            p = AllocR(2848);
            Ti__MGObj__MGObj(p, s, 1, a, f);
        }
        *(s32*)(p + 944) = 1;
        r = p;
        break;
    case 20:
        p = AllocR(3216);
        func_002d29a8(p, s, 3, a, f);
        r = p;
        break;
    case 21:
        if (s->id == 1631) {
            p = AllocR(2912);
            Ti__MGHachimitsuGopher__MGHachimitsuGopher(p, s, a, f);
        } else {
            p = AllocR(2848);
            Ti__MGHachimitsuGimObj__MGHachimitsuGimObj(p, s, a, f);
        }
        r = p;
        break;
    case 22:
        p = AllocR(3072);
        func_002dda88(p, s, a, f);
        r = p;
        break;
    case 26:
        p = AllocR(2848);
        func_002db6b0(p, s, a, f);
        r = p;
        break;
    }
    return r;
}
}  // namespace n002d0290

// 002d0718 (was src/anon/batch_w1337.cpp)
namespace n002d0718 {
struct BoxVec1337 {
    f32 x, y, z, w;
    };
struct Box1337 { f32 v[6]; };
struct ObjData1337 { s32 w[6]; };
struct Model1337 { void** vtbl; };
static inline void BoxVecSet1337(BoxVec1337* v, f32 x, f32 y, f32 z, f32 w) { v->x = x; v->y = y; v->z = z; v->w = w; }
typedef void (*GetBoundsFn1337)(Model1337*, BoxVec1337*, BoxVec1337*);
s32 JmInfo_GetCharaData(u32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
s32 func_0016f6f8(s32) asm("func_0016f6f8");
void YS__OBJDATA__clear(ObjData1337*) asm("YS__OBJDATA__clear");
void func_001a92d8(ObjData1337*, s32, s32) asm("func_001a92d8");
Model1337* ObjData_get_knm(ObjData1337*) asm("_ZN2YS7OBJDATA7get_knmEv");
void ObjData_free(ObjData1337*) asm("_ZN2YS7OBJDATA4freeEv");
void Aabbox_ctor(Box1337*, const BoxVec1337*, const BoxVec1337*) asm("_ZN2dk6AabboxC1ERKN2kn7FVectorES4_");
/*TARGET 002d0718*/
Box1337* func_002d0718(Box1337* out, s32* chara) asm("func_002d0718");
Box1337* func_002d0718(Box1337* out, s32* chara) {
    union {
        struct { ObjData1337 obj; s32 pad[2]; BoxVec1337 mn; BoxVec1337 mx; Box1337 box; } m;
        struct { BoxVec1337 mn; BoxVec1337 mx; Box1337 box; } d;
    } u;
    s32 data = JmInfo_GetCharaData(*chara);
    if (func_0016f6f8(*chara) != 0) {
        s32 id = *chara;
        Model1337* m;
        YS__OBJDATA__clear(&u.m.obj);
        func_001a92d8(&u.m.obj, id, data);
        m = ObjData_get_knm(&u.m.obj);
        ((GetBoundsFn1337)m->vtbl[4])(m, &u.m.mn, &u.m.mx);
        u.m.mn.y = -u.m.mn.y;
        u.m.mn.z = -u.m.mn.z;
        u.m.mx.y = -u.m.mx.y;
        u.m.mx.z = -u.m.mx.z;
        Aabbox_ctor(&u.m.box, &u.m.mn, &u.m.mx);
        *out = u.m.box;
        ObjData_free(&u.m.obj);
    } else {
        BoxVecSet1337(&u.d.mn, -100.0f, -100.0f, -100.0f, 0.0f);
        BoxVecSet1337(&u.d.mx, 100.0f, 100.0f, 100.0f, 0.0f);
        Aabbox_ctor(&u.d.box, &u.d.mn, &u.d.mx);
        *out = u.d.box;
    }
    return out;
}
}  // namespace n002d0718

// 002d08b8 (was src/anon/batch_w3742.cpp)
namespace n002d08b8 {
struct V3_1577 {
    f32 x, y, z;
    f32 dot(const V3_1577& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o), "m"(*this), "m"(o) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
struct Vec3_1577 { f32 x, y, z; };
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");
f32 func_002d0e10(f32) asm("func_002d0e10");
static inline void wrap3(V3_1577& o, const V3_1577& i) {
    o.x = func_002d0e10(i.x);
    o.y = func_002d0e10(i.y);
    o.z = func_002d0e10(i.z);
}
/*TARGET 002d08b8*/
void func_002d08b8(Vec3_1577* out, f32* m) asm("func_002d08b8");
void func_002d08b8(Vec3_1577* out, f32* m) {
    V3_1577 a, b, r;
    f32 m0 = m[0];
    register f32 m2 asm("$f0") = m[2];
    f32 sy = -m2;
    f32 cy = __builtin_sqrtf(m0 * m0 + m[1] * m[1]);
    if (cy > 1.9073486328125e-06f) {
        r.z = func_002f8ad0(m[1], m[0]);
        r.y = func_002f8ad0(-m[2], cy);
        r.x = func_002f8ad0(m[6], m[10]);
    } else {
        asm volatile("" : : "f"(m0));
        r.z = 0.0f;
        r.y = func_002f8ad0(sy, cy);
        r.x = func_002f8ad0(-m[9], m[5]);
    }
    a.x = func_002d0e10(r.x);
    a.y = func_002d0e10(r.y);
    a.z = func_002d0e10(r.z);
    r.x += 3.1415927f;
    r.z += 3.1415927f;
    r.y = 3.1415927f - r.y;
    wrap3(b, r);
    f32 bz = b.z; asm("" : "=f"(bz) : "0"(bz), "m"(b.z));
    if (a.dot(a) <= b.dot(b)) {
        out->x = a.x; out->y = a.y; out->z = a.z;
    } else {
        out->x = b.x; out->y = b.y; out->z = bz;
    }
}
}  // namespace n002d08b8

// 002d0a78 (was src/anon/batch_w254.cpp)
namespace n002d0a78 {
u8* YS__OBJ__Each(u8*) asm("YS__OBJ__Each");
s32 func_0016a040(u8*) asm("func_0016a040");
s32 func_0016a060(u8*) asm("func_0016a060");
/*TARGET 002d0a78*/
// 0x002c3c90: definition moved into src/anon/unit_002c3c90.cpp

// Walk all objects; type 16 with sub-type 20/21/22/25/26/27 get virtual slot 10 called.
void func_002d0a78(void) asm("func_002d0a78");
// 0x002c3c90: definition moved into src/anon/unit_002c3c90.cpp

// Walk all objects; type 16 with sub-type 20/21/22/25/26/27 get virtual slot 10 called.
void func_002d0a78(void) {
    u8* o = 0;
    while ((o = YS__OBJ__Each(o)) != 0) {
        if (func_0016a040(o) != 16) continue;
        if (func_0016a060(o) == 20 || func_0016a060(o) == 21 || func_0016a060(o) == 22 ||
            func_0016a060(o) == 25 || func_0016a060(o) == 26 || func_0016a060(o) == 27) {
            (*(void (**)(u8*))(*(u8**)o + 40))(o);
        }
    }
}
}  // namespace n002d0a78

// 002d0b88 (was src/anon/tiny_auto80_queue.cpp)
namespace n002d0b88 {
void func_0016b070(...) asm("func_0016b070");
void func_002d08b8(...) asm("func_002d08b8");
u32 func_0016ace0(...) asm("func_0016ace0");
/*TARGET 002d0b88*/
void Ti__MGObj__set_matrix(u32 a0, u32 a1) asm("_Z21Ti__MGObj__set_matrixjj");
void Ti__MGObj__set_matrix(u32 a0, u32 a1) {
    u8 tmp[16];
    u32 s0 = a1;
    u32 s1 = a0;

    func_0016ace0(s1, s0 + 48);
    func_002d08b8((u32)tmp, s0);
    func_0016b070(s1, (u32)tmp);
}
}  // namespace n002d0b88

// 002d0bd8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002d0bd8 {
void func_0016b070(...) asm("func_0016b070");
void func_002d08b8(...) asm("func_002d08b8");
u32 func_0016ace0(...) asm("func_0016ace0");
/*TARGET 002d0bd8*/
void Ti__MGObj__set_matrix_2(u32 a0, u32 a1) asm("_Z23Ti__MGObj__set_matrix_2jj");
void Ti__MGObj__set_matrix_2(u32 a0, u32 a1) {
    u8 tmp[16];
    u32 s0 = a1;
    u32 s1 = a0;

    func_0016ace0(s1, s0 + 48);
    func_002d08b8((u32)tmp, s0);
    func_0016b070(s1, (u32)tmp);
}
}  // namespace n002d0bd8

// 002d0c28 (was src/anon/batch_w81.cpp)
namespace n002d0c28 {
// 0x002be190: definition moved into src/anon/unit_002be020.cpp

// --- 002d0c28
void func_001dc818(u32) asm("func_001dc818");
void func_002cf280(u8*, u32, u32) asm("func_002cf280");
s32 func_002cf270(u8*, u32) asm("func_002cf270");
void func_002cf2b0(u8*, u32) asm("func_002cf2b0");
void Ti__MGObj__hibernate(u8*) asm("Ti__MGObj__hibernate");
/*TARGET 002d0c28*/
void func_002d0c28(u8* o) asm("func_002d0c28");
void func_002d0c28(u8* o) {
    if (*(s32*)(o + 2832) == 0) {
        if (*(u32*)(o + 2828)) {
            func_001dc818(*(u32*)(o + 2828));
            *(u32*)(o + 2828) = 0;
        }
        *(u32*)(o + 264) |= 3;
        func_002cf280(o + 2800, 8192, 0);
    }
    (*(s32*)(o + 2832))++;
    if (func_002cf270(o + 2800, 16384) && *(s32*)(o + 2832) < 5) return;
    func_002cf2b0(o + 2800, 8192);
    func_002cf2b0(o + 2800, 16384);
    Ti__MGObj__hibernate(o);
}
}  // namespace n002d0c28

// 002d0cf0 (was src/anon/batch_w52.cpp)
namespace n002d0cf0 {
// 00109450: moved to src/anon/unit_001085a8.cpp

void func_001dc818(u32) asm("func_001dc818");
/*TARGET 002d0cf0*/
void Ti__MGObj__hibernate(u8* p) asm("Ti__MGObj__hibernate");
void Ti__MGObj__hibernate(u8* p) {
    if (*(u32*)(p + 2828)) {
        func_001dc818(*(u32*)(p + 2828));
        *(u32*)(p + 2828) = 0;
    }
    *(u32*)(p + 268) |= 0x80;
    *(u32*)(p + 264) |= 0x403;
    *(u32*)(p + 2832) = 0;
}
}  // namespace n002d0cf0

// 002d0d48 (was src/anon/tiny_auto80_queue.cpp)
namespace n002d0d48 {
u32 func_00186020(...) asm("func_00186020");
u32 func_001dc818(...) asm("func_001dc818");
/*TARGET 002d0d48*/
u32 Ti__MGObj___OVR_leave_req(u32 a0) asm("_Z25Ti__MGObj___OVR_leave_reqj");
u32 Ti__MGObj___OVR_leave_req(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(2828));
    r4 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32))func_001dc818)(r4);
        *(volatile u32*)((u32)r16 + (s32)(2828)) = 0u;
    }
    r4 = r16;
    return ((u32(*)(u32))func_00186020)(r4);
}
}  // namespace n002d0d48

// 002d0d88 (was src/anon/batch_w54.cpp)
namespace n002d0d88 {
// 0x002aacd8: definition moved into src/anon/unit_002a99c8.cpp

void func_002cf2b0(void*, s32) asm("func_002cf2b0");
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
struct Flags108 {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 5;
    u32 b7 : 1;
    u32 b8 : 2;
    u32 b10 : 1;
    u32 rest : 21;
};
/*TARGET 002d0d88*/
void func_002d0d88(u8* p) asm("func_002d0d88");
void func_002d0d88(u8* p) {
    func_002cf2b0(p + 2800, 4);
    ((Flags108*)(p + 264))->b0 = 0;
    ((Flags108*)(p + 264))->b1 = 0;
    ((Flags108*)(p + 268))->b7 = 0;
    (*(void (**)(void*))(*(u8**)p + 124))(p);
    ((Flags108*)(p + 264))->b10 = 0;
    func_0017f488(p + 320, 0, 0.0f, 0.0f);
}
}  // namespace n002d0d88

// 002d0e10 (was src/anon/batch_w52.cpp)
namespace n002d0e10 {
/*TARGET 002d0e10*/
// 0x002c1cb0: definition moved into src/anon/unit_002c10e0.cpp

// Wraps an angle into [-pi, pi].
f32 func_002d0e10(f32 a) asm("func_002d0e10");
// 0x002c1cb0: definition moved into src/anon/unit_002c10e0.cpp

// Wraps an angle into [-pi, pi].
f32 func_002d0e10(f32 a) {  // float_bucket_index_b
    if (0.0f < a) {
        while (3.1415927f < a) a -= 6.2831855f;
    } else {
        while (a < -3.1415927f) a += 6.2831855f;
    }
    return a;
}
}  // namespace n002d0e10

// 002d0ea8 (was src/anon/tiny_auto80_solver.cpp)
namespace n002d0ea8 {
u32 func_00177dc8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00177dc8jjjjjjjj");
u32 func_00182f28(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00182f28jjjjjjjj");
u32 func_002d0ea8(u32, u32, u32, u32) asm("_Z13func_002d0ea8jjjj");
extern u8 D_00362060 asm("D_00362060");
extern u8 D_00360000 asm("D_00360000");
/*TARGET 002d0ea8*/
u32 func_002d0ea8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d0ea8jjjj");
u32 func_002d0ea8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s0 = a0;
    ((u32(*)(u32, u32, u32, u32, u32))func_00177dc8)(a0, a1, 11, a2, a3);
    *(u32*)s0 = (u32)&D_00362060;
    *(u32*)((u8*)&D_00360000 + 8272) = s0;
    return ((u32(*)(u32))func_00182f28)(s0);
}
}  // namespace n002d0ea8

// 002d0ef0 (was src/anon/auto200_999.cpp)
namespace n002d0ef0 {
u32 func_00177dc8(...) asm("_Z13func_00177dc8z");
u32 func_00182f28(...) asm("_Z13func_00182f28z");
extern u8 D_00360000 asm("D_00360000");
extern u8 D_00362060 asm("D_00362060");
/*TARGET 002d0ef0*/
u32 func_002d0ef0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d0ef0jjjj");
u32 func_002d0ef0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s0 = a0;
    ((u32 (*)(u32, u32, u32, u32, u32))func_00177dc8)(a0, a1, 11, a2, a3);
    *(u32 *)s0 = (u32)&D_00362060;
    *(u32 *)((u8 *)&D_00360000 + 8272) = s0;
    return ((u32 (*)(u32))func_00182f28)(s0);
}
}  // namespace n002d0ef0

// 002d0f38 (was src/anon/batch_w40.cpp)
namespace n002d0f38 {
// 0x002c5238: definition moved into src/anon/unit_002c4ca8.cpp

void func_00182f28(u32) asm("func_00182f28");
// store_global_35ed04
void func_00319f88(u8*) asm("func_00319f88");
void YS__OBJ_ATTACK__clear(u8*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(u8*) asm("func_001c0248");
void func_00319fb0(u8*) asm("func_00319fb0");
// big_obj_dtor
extern void* D_00362060[] asm("D_00362060");
union U362 { u32 v; void* p; };
extern U362 D_00362050 asm("D_00362050");
extern void* D_0034e8b8[] asm("D_0034e8b8");
extern void* D_0034ee08[] asm("D_0034ee08");
struct NoTail { ~NoTail() {} };
void u_call4_dtor(u32 a, u32, u32, u32) asm("_Z16u_call4_002d0f38jjjj");
/*TARGET 002d0f38*/
// Destructor chain (vtables reset per base, members destroyed).
void u_call4_dtor(u32 a, u32, u32, u32) asm("_Z16u_call4_002d0f38jjjj");
// Destructor chain (vtables reset per base, members destroyed).
void u_call4_dtor(u32 a, u32, u32, u32) {
    NoTail g;
    u8* p = (u8*)a;
    *(void**)p = D_00362060;
    func_00182f28(0);  // store_global_35ed04
    D_00362050.v = 0;
    *(void**)p = D_0034e8b8;
    func_00319f88(p + 2824);
    *(void**)p = D_0034ee08;
    YS__OBJ_ATTACK__clear(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
}
}  // namespace n002d0f38

// 002d0fb0 (was src/anon/batch_w41.cpp)
namespace n002d0fb0 {
struct NoTail { ~NoTail() {} };
// 002ceef8: moved to src/taito/minigame_base.cpp (linked unit)

extern void* D_00362060[] asm("D_00362060");
extern void* D_0034e8b8[] asm("D_0034e8b8");
extern void* D_0034ee08[] asm("D_0034ee08");
extern void* D_00362050 asm("D_00362050");
void func_00182f28(u32) asm("func_00182f28");
// store_global_35ed04
void func_00319f88(u8*) asm("func_00319f88");
void YS__OBJ_ATTACK__clear(u8*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(u8*) asm("func_001c0248");
void func_00319fb0(u8*) asm("func_00319fb0");
/*TARGET 002d0fb0*/
// big_obj_dtor
void func_002d0fb0(u8* p) asm("func_002d0fb0");
// big_obj_dtor
void func_002d0fb0(u8* p) {
    NoTail nt;
    *(void**)p = D_00362060;
    func_00182f28(0);  // store_global_35ed04
    D_00362050 = 0;
    *(void**)p = D_0034e8b8;
    func_00319f88(p + 2824);
    *(void**)p = D_0034ee08;
    YS__OBJ_ATTACK__clear(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
}
}  // namespace n002d0fb0

// 002d1028 (was src/anon/batch_w44.cpp)
namespace n002d1028 {
void func_00182f28(s32) asm("func_00182f28");
// store_global_35ed04
void func_00319f88(void*) asm("func_00319f88");
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
void func_00319fb0(void*) asm("func_00319fb0");
// big_obj_dtor
void func_00105110(void*) asm("func_00105110");
// Destructor chain: vtables reset as each base is torn down.
extern u8 D_00362060[] asm("D_00362060");
extern void* D_00362050 asm("D_00362050");
extern u8 D_0034e8b8[] asm("D_0034e8b8");
extern u8 D_0034ee08[] asm("D_0034ee08");
/*TARGET 002d1028*/
void func_002d1028(u8* o) asm("func_002d1028");
void func_002d1028(u8* o) {
    *(void**)o = D_00362060;
    func_00182f28(0);  // store_global_35ed04
    D_00362050 = 0;
    *(void**)o = D_0034e8b8;
    func_00319f88(o + 2824);
    *(void**)o = D_0034ee08;
    YS__OBJ_ATTACK__clear(o + 2568);  // array8_free_slots
    func_001c0248(o + 2640);
    func_00319fb0(o);  // big_obj_dtor
    func_00105110(o);
}
}  // namespace n002d1028

// 002d10a0 (was src/anon/batch_w1910.cpp)
namespace n002d10a0 {
#define QCOPY_w(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPY4_w(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QV_w {
    f32 x, y, z, w;
    QV_w() {}
    QV_w(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV_w(const QV_w& o) { QCOPY_w(this, &o); }
    QV_w& operator=(const QV_w& o) { if (this != &o) QCOPY_w(this, &o); return *this; }
    QV_w& operator+=(const QV_w& o) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct QM_w {
    QV_w r[4];
    QM_w() {}
    QM_w& operator=(const QM_w& o) { if (this != &o) QCOPY4_w(this, &o); return *this; }
    QV_w operator*(const QV_w& v) const {
        QV_w o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
struct Cam_w { u8 pad[0xb70]; QM_w m; QM_w inv; };
void YS__PLAYER___OVR_pre_exec(Cam_w*) asm("YS__PLAYER___OVR_pre_exec");
void func_0011b6a8(QM_w*) asm("func_0011b6a8");
void FMatrix_rotateY_w(QM_w*, f32) asm("_ZN2kn7FMatrix7rotateYEf");
void FMatrix_rotateXYZ_w(QM_w*, const QV_w*) asm("_ZN2kn7FMatrix9rotateXYZERKNS_7FVectorE");
f32 ObjCamera_getObjBackDirection_w(Cam_w*) asm("_ZN2dk9ObjCamera19getObjBackDirectionEv");
const QV_w* OBJ_get_xyzrot_w(Cam_w*) asm("_ZN2YS3OBJ10get_xyzrotEv");
s32 OBJ_is_xyzrot_w(Cam_w*) asm("_ZN2YS3OBJ9is_xyzrotEv");
const QV_w* YS__OBJ__get_pos(Cam_w*) asm("YS__OBJ__get_pos");
/*TARGET 002d10a0*/
void func_002d10a0(Cam_w* o) asm("func_002d10a0");
void func_002d10a0(Cam_w* o)
{
    YS__PLAYER___OVR_pre_exec(o);
    QM_w* m = &o->m;
    func_0011b6a8(m);
    if (OBJ_is_xyzrot_w(o)) FMatrix_rotateXYZ_w(m, OBJ_get_xyzrot_w(o));
    else FMatrix_rotateY_w(m, ObjCamera_getObjBackDirection_w(o));
    o->m.r[3] = *YS__OBJ__get_pos(o);
    { QV_w t = *m * QV_w(0.0f, -80.0f, 0.0f, 0.0f); o->m.r[3] += t; }
    o->m.r[3].w = 1.0f;
    o->inv = *m;
    o->inv.invOrtho();
}
}  // namespace n002d10a0

// 002d1228 (was src/anon/tiny_wrappers_more.cpp)
namespace n002d1228 {
u32 func_001789b8(u32, u32, u32, u32) asm("_Z13func_001789b8jjjj");
/*TARGET 002d1228*/
// 002cf248: moved to src/taito/minigame_base.cpp (linked unit)

u32 func_002d1228(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d1228jjjj");
// 002cf248: moved to src/taito/minigame_base.cpp (linked unit)

u32 func_002d1228(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001789b8(a0, a1, a2, a3);
}
}  // namespace n002d1228

// 002d1240, 002d1250 (gap functions, never written before)
namespace n002d1240 {
u8* func_002d1240(u8* p) asm("func_002d1240");
u8* func_002d1240(u8* p) { return p + 2928; }
u8* func_002d1250(u8* p) asm("func_002d1250");
u8* func_002d1250(u8* p) { return p + 2992; }
}  // namespace n002d1240

// 002d1260 (was src/anon/tiny.cpp)
namespace n002d1260 {
/*TARGET 002d1260*/
// 0x002cb530: definition moved into src/anon/unit_002cb200.cpp

u32 func_002d1260(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d1260jjjj");
// 0x002cb530: definition moved into src/anon/unit_002cb200.cpp

u32 func_002d1260(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u32*)((u32)b + (8272)));
}
}  // namespace n002d1260

// 002d1270 (was src/anon/batch_w30.cpp)
namespace n002d1270 {
void* func_001050d8(u32) asm("func_001050d8");
void* Ti__MGOarashi__MGOarashi(void*, u32, u32) asm("Ti__MGOarashi__MGOarashi");
/*TARGET 002d1270*/
void* func_002d1270(u32 a, u32 b) asm("func_002d1270");
void* func_002d1270(u32 a, u32 b) {
    return Ti__MGOarashi__MGOarashi(func_001050d8(336), a, b);
}
}  // namespace n002d1270

// "po_06" (read by 0x2d12b0 and 0x2d1550), 4-aligned so the unit's .rodata stays 4-aligned
extern const char D_003759b0[8] asm("D_003759b0") __attribute__((aligned(4))) = "po_06";

// 002d12b0 (was src/anon/batch_w1656_nsa.cpp)
namespace n002d12b0 {
#define W1656_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define W1656_MCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t" \
    "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct W1656Vec {
    f32 x, y, z, w;
    W1656Vec() {}
    W1656Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1656Vec& operator=(const W1656Vec& o) {
        if (this != &o) W1656_QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct W1656Mtx {
    f32 m[16];
    W1656Mtx& operator=(const W1656Mtx& o) {
        if (this != &o) W1656_MCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct W1656Cfg { u8 pad[36]; f32 scale; };
struct W1656Res { u8 pad[8]; s32 data; };
struct W1656Oarashi {
    u32 vt;
    u8 pad4[88];
    s32 f92;
    s32 res;
    s32 f100;
    s32 f104;
    s32 afp;
    f32 f112;
    u8 pad116[12];
    W1656Vec v128;
    f32 f144;
    f32 f148;
    f32 f152;
    u8 pad156[4];
    W1656Mtx m160;
    W1656Mtx m224;
    W1656Vec v288;
    W1656Vec v304;
    u8 f320;
    u8 pad321[3];
    u32 f324;
    u32 f328;
};
extern u8 D_00362158[] asm("D_00362158");
extern u8 D_00362110[] asm("D_00362110");
void func_002ce958(W1656Oarashi* p, s32 a, s32 b, s32 c) asm("func_002ce958");
void MiniGame_make_data_path_W1656(W1656Oarashi* p, char* out, const char* name) asm("_ZN2Ti8MiniGame14make_data_pathEPcS1_");
s32 CACHE_BUFF_Alloc_W1656(const char* path, s32 n) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");
W1656Res* func_00168b38(s32 h, s32 kind, s32 idx) asm("func_00168b38");
W1656Cfg* MGOarashi_config_W1656(W1656Oarashi* p) asm("_ZN2Ti9MGOarashi6configEv");
void func_001ca8f8(f32 a, f32 b) asm("func_001ca8f8");
void Afp_getCount_W1656(s32 a) asm("_ZN2Ti3Afp8getCountEPv");
s32 func_002e64b8(s32 a, s32 b) asm("func_002e64b8");
void getFieldMode_W1656(void) asm("_Z12getFieldModev");
void Ti__Afp__Data__calc_matrix(s32 afp, W1656Mtx* m, f32 t) asm("Ti__Afp__Data__calc_matrix");
void func_001069b8(s32 a) asm("func_001069b8");
void Ti__MiniGame__create_task(s32 a, u8* b) asm("Ti__MiniGame__create_task");
void Ti__MGObj__reset_all_members(s32 a) asm("Ti__MGObj__reset_all_members");
/*TARGET 002d12b0*/
void func_002d12b0(W1656Oarashi* p, s32 id, s32 b) asm("func_002d12b0");
void func_002d12b0(W1656Oarashi* p, s32 id, s32 b)
{
    s32 data, r;
    f32 z = 0.0f;
    W1656Vec& v128 = p->v128;
    W1656Mtx& m160 = p->m160;
    W1656Mtx& m224 = p->m224;
    W1656Vec& v288 = p->v288;
    W1656Vec& v304 = p->v304;
    func_002ce958(p, 0, b, 2048);
    p->f104 = id;
    p->f100 = 0;
    p->afp = 0;
    p->vt = (u32)D_00362158;
    p->f112 = 40.0f;
    v128.x = z;
    v128.y = z;
    v128.z = z;
    v128.w = z;
    p->f144 = z;
    p->f152 = z;
    p->f320 = 0;
    {
        char path[64] __attribute__((aligned(16)));
        MiniGame_make_data_path_W1656(p, path, (char*)D_003759b0);
        p->res = r = CACHE_BUFF_Alloc_W1656(path, -1);
    }
    func_00168b38(r, 42, 0);
    p->f100 = func_00168b38(r, 42, 0)->data + 16;
    func_00168b38(r, 42, 1);
    data = func_00168b38(r, 42, 1)->data;
    func_00168b38(r, 42, p->f104 + 2);
    p->f92 = func_00168b38(r, 42, p->f104 + 2)->data;
    func_001ca8f8(MGOarashi_config_W1656(p)->scale, z);
    Afp_getCount_W1656(data);
    p->afp = func_002e64b8(0, data);
    getFieldMode_W1656();
    p->f112 = 40.0f;
    v128 = W1656Vec(z, z, 150.0f, z);
    p->f144 = z;
    {
        W1656Mtx m;
        Ti__Afp__Data__calc_matrix(p->afp, &m, z);
        m160 = m;
        m224 = m;
        v288 = W1656Vec(z, z, z, z);
        v304 = W1656Vec(z, z, z, z);
    }
    p->f324 = 0;
    p->f328 = 0;
    func_001069b8(2);
    Ti__MiniGame__create_task(4, D_00362110);
    Ti__MGObj__reset_all_members(1);
}
}  // namespace n002d12b0

// 002d1550 (was src/anon/batch_wcx2_nsa.cpp)
namespace n002d1550 {
// 001b1100: moved to src/yasui/libys/lookat.cpp

// --------------------
// 002d1550: Ti::MGOarashi set-up (base init, "po_06" data, Afp resources, start pose)
// Member addresses are taken up front like the member constructors of the original ctor.
struct V2d1550 {
    f32 x, y, z, w;
    V2d1550() {}
    V2d1550(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    void Init(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V2d1550 operator-(const V2d1550& b) const
    {
        V2d1550 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2d1550& operator+=(const V2d1550& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    V2d1550& operator=(const V2d1550& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M2d1550 {
    V2d1550 r[4];
    M2d1550() {}
    M2d1550& operator=(const M2d1550& o)
    {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Ent2d1550 { u8 pad[8]; s32 data; };
struct Cfg2d1550 { u8 pad[36]; f32 f36; };
struct G2d1550 {
    u32 vt;
    u8 pad0[88];
    s32 f92;
    s32 bar;
    s32 f100;
    s32 id;
    s32 afp;
    f32 dist;
    u8 pad1[12];
    V2d1550 pos;
    f32 f144;
    u8 pad2[4];
    f32 f152;
    u8 pad3[4];
    M2d1550 m0;
    M2d1550 m1;
    V2d1550 v288;
    V2d1550 v304;
    u8 f320;
    u8 pad4[3];
    s32 f324;
    s32 f328;
};
extern u8 D_00362158[] asm("D_00362158");
extern u8 D_00362110[] asm("D_00362110");
void func_002ce958(G2d1550*, s32, s32, s32) asm("func_002ce958");
void g2d1550_make_data_path(G2d1550*, char*, const char*) asm("_ZN2Ti8MiniGame14make_data_pathEPcS1_");
s32 g2d1550_Alloc(const char*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");
Ent2d1550* func_00168b38(s32, s32, s32) asm("func_00168b38");
Cfg2d1550* g2d1550_config(G2d1550*) asm("_ZN2Ti9MGOarashi6configEv");
void func_001ca8f8(f32, f32) asm("func_001ca8f8");
void g2d1550_getCount(s32) asm("_ZN2Ti3Afp8getCountEPv");
s32 func_002e64b8(s32, s32) asm("func_002e64b8");
s32 g2d1550_getFieldMode(void) asm("_Z12getFieldModev");
void Ti__Afp__Data__calc_matrix(f32, s32, M2d1550*) asm("Ti__Afp__Data__calc_matrix");
void func_001069b8(s32) asm("func_001069b8");
void Ti__MiniGame__create_task(s32, u8*) asm("Ti__MiniGame__create_task");
void Ti__MGObj__reset_all_members(s32) asm("Ti__MGObj__reset_all_members");
/*TARGET 002d1550*/
void Ti__MGOarashi__MGOarashi(G2d1550* g, s32 id, s32 arg) asm("Ti__MGOarashi__MGOarashi");
void Ti__MGOarashi__MGOarashi(G2d1550* g, s32 id, s32 arg)
{
    func_002ce958(g, 0, arg, 0x800);
    M2d1550* m0 = &g->m0;
    M2d1550* m1 = &g->m1;
    V2d1550* v288 = &g->v288;
    V2d1550* v304 = &g->v304;
    g->id = id;
    g->f100 = 0;
    g->afp = 0;
    g->vt = (u32)D_00362158;
    g->dist = 40.0f;
    g->pos.Init(0.0f, 0.0f, 0.0f, 0.0f);
    g->f144 = 0.0f;
    g->f152 = 0.0f;
    g->f320 = 0;
    s32 bar;
    {
        char path[64];
        g2d1550_make_data_path(g, path, (char*)D_003759b0);
        bar = g2d1550_Alloc(path, -1);
    }
    g->bar = bar;
    func_00168b38(bar, 42, 0);
    g->f100 = func_00168b38(bar, 42, 0)->data + 16;
    func_00168b38(bar, 42, 1);
    s32 afp = func_00168b38(bar, 42, 1)->data;
    func_00168b38(bar, 42, g->id + 2);
    g->f92 = func_00168b38(bar, 42, g->id + 2)->data;
    func_001ca8f8(g2d1550_config(g)->f36, 0.0f);
    g2d1550_getCount(afp);
    g->afp = func_002e64b8(0, afp);
    g2d1550_getFieldMode();
    g->dist = 40.0f;
    g->pos = V2d1550(0.0f, 0.0f, 150.0f, 0.0f);
    g->f144 = 0.0f;
    M2d1550 m;
    Ti__Afp__Data__calc_matrix(0.0f, g->afp, &m);
    *m0 = m;
    *m1 = m;
    *v288 = V2d1550(0.0f, 0.0f, 0.0f, 0.0f);
    *v304 = V2d1550(0.0f, 0.0f, 0.0f, 0.0f);
    g->f324 = 0;
    g->f328 = 0;
    func_001069b8(2);
    Ti__MiniGame__create_task(4, D_00362110);
    Ti__MGObj__reset_all_members(1);
}
}  // namespace n002d1550

// 002d17f0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002d17f0 {
u32 func_002cea28(u32, u32, u32, u32) asm("_Z13func_002cea28jjjj");
extern u8 D_00362158 asm("D_00362158");
/*TARGET 002d17f0*/
// 0x2ca3d0: moved to src/anon/unit_002ca0e0.cpp


u32 func_002d17f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d17f0jjjj");
// 0x2ca3d0: moved to src/anon/unit_002ca0e0.cpp


u32 func_002d17f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00362158;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002cea28)(u32, u32, u32, u32) = func_002cea28;
    r2 = fp_call4_002cea28(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002d17f0

// 002d1818 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002d1818 {
u32 func_002cea28(u32, u32, u32, u32) asm("_Z13func_002cea28jjjj");
extern u8 D_00362158 asm("D_00362158");
/*TARGET 002d1818*/
u32 func_002d1818(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d1818jjjj");
u32 func_002d1818(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00362158;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002cea28)(u32, u32, u32, u32) = func_002cea28;
    r2 = fp_call4_002cea28(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002d1818

// 002d1840 (was src/anon/batch_w18.cpp)
namespace n002d1840 {
void func_00105110(void*) asm("func_00105110");
extern u32 D_00362158 asm("D_00362158");
void func_002cea28(void*) asm("func_002cea28");
/*TARGET 002d1840*/
void func_002d1840(void** p) asm("func_002d1840");
void func_002d1840(void** p) {
    *p = &D_00362158;
    func_002cea28(p);
    func_00105110(p);
}
}  // namespace n002d1840

// 002d1878 (was src/taito/mg_oarashi.cpp)
namespace Ti {
s32 MGOarashi_config(MGOarashi* self) asm("_ZN2Ti9MGOarashi6configEv");
s32 MGOarashi_config(MGOarashi* self) { return reinterpret_cast<MGOarashiLayout*>(self)->configValue; }
}  // Ti

// 002d1880 (was src/anon/tiny_wrappers_more.cpp)
namespace n002d1880 {
u32 func_002cebc0(u32, u32, u32, u32) asm("_Z13func_002cebc0jjjj");
/*TARGET 002d1880*/
u32 func_002d1880(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d1880jjjj");
u32 func_002d1880(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002cebc0(a0, a1, a2, a3);
}
}  // namespace n002d1880

// 002d1898 (gap function, never written before)
namespace n002d1898 {
struct PadE { u64 b0 : 1; u64 rest : 63; };
PadE* func_00167bf0(s32) asm("func_00167bf0");
void func_002d2070(u8*) asm("func_002d2070");
static inline bool on() { u8 r = func_00167bf0(0)->b0; return r; }
void func_002d1898(u8* p) asm("func_002d1898");
void func_002d1898(u8* p) { if (on()) func_002d2070(p); }
}  // namespace n002d1898

// 002d18e8 (was src/anon/tiny_auto80.cpp)
namespace n002d18e8 {
u32 func_002d25f0(u32, u32, u32, u32) asm("_Z13func_002d25f0jjjj");
/*TARGET 002d18e8*/
// 0x2c9ea8: moved to src/anon/unit_002c9998.cpp


u32 func_002d18e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d18e8jjjj");
// 0x2c9ea8: moved to src/anon/unit_002c9998.cpp


u32 func_002d18e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(volatile u32*)((u32)r4 + (s32)(328)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(324)) = 0u;
    return ((u32(*)(u32,u32,u32,u32))func_002d25f0)(r4, r5, r6, r7);
}
}  // namespace n002d18e8

// 002d1908 (was src/anon/batch_wcx2_nsa.cpp)
namespace n002d1908 {
// 001b1100: moved to src/yasui/libys/lookat.cpp

// --------------------
// 002d1550: Ti::MGOarashi set-up (base init, "po_06" data, Afp resources, start pose)
// Member addresses are taken up front like the member constructors of the original ctor.
struct V2d1550 {
    f32 x, y, z, w;
    V2d1550() {}
    V2d1550(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    void Init(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V2d1550 operator-(const V2d1550& b) const
    {
        V2d1550 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2d1550& operator+=(const V2d1550& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    V2d1550& operator=(const V2d1550& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M2d1550 {
    V2d1550 r[4];
    M2d1550() {}
    M2d1550& operator=(const M2d1550& o)
    {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct G2d1550 {
    u32 vt;
    u8 pad0[88];
    s32 f92;
    s32 bar;
    s32 f100;
    s32 id;
    s32 afp;
    f32 dist;
    u8 pad1[12];
    V2d1550 pos;
    f32 f144;
    u8 pad2[4];
    f32 f152;
    u8 pad3[4];
    M2d1550 m0;
    M2d1550 m1;
    V2d1550 v288;
    V2d1550 v304;
    u8 f320;
    u8 pad4[3];
    s32 f324;
    s32 f328;
};
// --------------------
// 002d1908: Ti::MGOarashi per-frame update (camera, ride along the Afp path, speed from slope)
struct Afp2d1908 { u8 pad[4]; s32 frames; };
extern f32 D_00349e10 asm("D_00349e10");
void g2d1908_exec(void) asm("_ZN2Ti8MiniGame4execEv");
void func_002cf998(void) asm("func_002cf998");
void g2d1908_002cfb30(void) asm("func_002cfb30");
void* g2d1908_00106a18(s32) asm("kn__getProjection");
void g2d1908_00106de8(void*, s32, f32) asm("kn__Projection__setFOV");
void g2d1908_00106c08(void*) asm("kn__Projection__calcMatrix");
void g2d1908_002e6ab0(s32, f32, M2d1550*) asm("Ti__Afp__Data__calc_matrix");
void func_002e6930(f32, s32, V2d1550*) asm("func_002e6930");
f32* g2d1908_config(G2d1550*) asm("_ZN2Ti9MGOarashi6configEv");
f32 g2d1908_fabsf(f32) asm("fabsf");
void g2d1908(G2d1550*) asm("_Z16wtarget_002d1908jjjj");
/*TARGET 002d1908*/
void g2d1908(G2d1550* g) asm("_Z16wtarget_002d1908jjjj");
void g2d1908(G2d1550* g)
{
    g2d1908_exec();
    func_002cf998();
    g2d1908_002cfb30();
    void* cam = g2d1908_00106a18(1);
    g2d1908_00106de8(cam, 1, g->dist * 0.017453292f);
    g2d1908_00106c08(cam);
    g->m1 = g->m0;
    g2d1908_002e6ab0(g->afp, g->f144, &g->m0);
    g->m0.r[3] += g->pos;
    if (!g->f320) {
        f32 thr = 0.5f;
        V2d1550 a, b;
        func_002e6930(g->f144, g->afp, &a);
        f32 k = *g2d1908_config(g);
        func_002e6930(g->f144 + k * 15.0f * 11.0f, g->afp, &b);
        if (g2d1908_fabsf(b.y) < thr) {
            if (g->f152 > 0.0f) g->f152 -= 1.3333333f;
        } else if (thr < g2d1908_fabsf(a.y)) {
            if (g->f152 < 20.0f) g->f152 += 1.3333333f;
        }
        if (g->f152 < 0.0f) g->f152 = 0.0f;
        if (20.0f < g->f152) g->f152 = 20.0f;
        g->f144 += k * (g->f152 + 1.0f) * D_00349e10 * 0.5f;
        s32 n = ((Afp2d1908*)g->afp)->frames;
        if (!((s32)g->f144 < n - 1)) g->f144 = n;
    }
    g->v304 = g->v288;
    g->v288 = g->m0.r[3] - g->m1.r[3];
}
}  // namespace n002d1908

// 002d1b90 (was src/anon/perm_002d1b90.cpp)
namespace n002d1b90 {
typedef unsigned char u8;
typedef float f32;
typedef struct V4
{
  f32 x;
  f32 y;
  f32 z;
  f32 w;
} V4;
void func_002d1bf8(u8 *, u8 *, V4 *, V4 *) asm("func_002d1bf8");
inline static void v4set(V4 *v, f32 a, f32 b, f32 c, f32 d)
{
  v->x = a;
  v->y = b;
  v->z = c;
  v->w = d;
}
/*TARGET 002d1b90*/
void func_002d1b90(u8 *a, u8 *b) asm("func_002d1b90");
void func_002d1b90(u8 *a, u8 *b)
{
  V4 v0;
  V4 v1;
  float new_var;
  new_var = 240.0f;
  v4set(&v0, 70.0f, 5.0f, 0.0f, 0.0f);
  v4set(&v1, 70.0f, new_var, 0.0f, 0.0f);
  func_002d1bf8(a, b, &v1, &v0);
}
}  // namespace n002d1b90

// 002d1bf8 (was src/anon/batch_wcx2.cpp)
namespace n002d1bf8 {
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
f32 func_002f8a18(f32) asm("func_002f8a18");
f32 fabsf(f32) asm("fabsf");
/*TARGET 002d1bf8*/
// fabsf
// 002d1bf8: clamp v (relative to the camera at +208) inside the view frustum, with margins lo/hi
void func_002d1bf8(u8* cam, Vec4* v, f32* hi, f32* lo) asm("func_002d1bf8");
// fabsf
// 002d1bf8: clamp v (relative to the camera at +208) inside the view frustum, with margins lo/hi
void func_002d1bf8(u8* cam, Vec4* v, f32* hi, f32* lo)
{
    Vec4* c = (Vec4*)(cam + 208);
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(v), "r"(c) : "memory");
    f32 h = func_002f8a18(*(f32*)(cam + 112) * 0.5f * 0.017453292f);
    h *= fabsf(v->z);  // fabsf
    f32 w = h * 4.0f / 3.0f;
    if (w - lo[0] < v->x) v->x = w - lo[0];
    if (v->x < hi[0] - w) v->x = hi[0] - w;
    if (h - lo[1] < v->y) v->y = h - lo[1];
    if (v->y < hi[1] - h) v->y = hi[1] - h;
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(v), "r"(c) : "memory");
}
}  // namespace n002d1bf8

// 002d1d30 (was src/anon/batch_w78.cpp)
namespace n002d1d30 {
struct W78Vec {
    f32 x, y, z, w;
    W78Vec& operator=(const W78Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void vsub(W78Vec* d, const W78Vec* a, const W78Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline W78Vec operator-(const W78Vec& a, const W78Vec& b) { W78Vec r; vsub(&r, &a, &b); return r; }
f32 func_002f8a18(f32) asm("func_002f8a18");
f32 fabsf(f32) asm("fabsf");
// fabsf
struct W78VecC2 {
    f32 x, y, z, w;
    W78VecC2& operator=(const W78VecC2& o) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
/*TARGET 002d1d30*/
W78VecC2* func_002d1d30(W78VecC2* out, u8* cam, W78VecC2* pos) asm("func_002d1d30");
W78VecC2* func_002d1d30(W78VecC2* out, u8* cam, W78VecC2* pos) {
    *out = *pos;
    vsub((W78Vec*)out, (W78Vec*)out, (W78Vec*)(cam + 208));
    f32 t = func_002f8a18(*(f32*)(cam + 112) * 0.5f * 0.01745329238474369f);
    t *= fabsf(out->z);  // fabsf
    out->z = 0.0f;
    out->x = out->x / (t * 4.0f / 3.0f);
    out->y = out->y / t;
    return out;
}
}  // namespace n002d1d30

// 002d1e08 (was src/anon/batch_w1814.cpp)
namespace n002d1e08 {
// 16-byte vector: lq/sq copy and VU0 vsub (no C equivalent for the 128-bit ops).
struct W1814Vec {
    f32 x, y, z, w;
    W1814Vec() {}
    W1814Vec(const W1814Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1814Vec& operator-=(const W1814Vec& o) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1814Cam { u8 pad[0x70]; f32 fov; u8 pad2[0x110 - 0x74]; W1814Vec pos; };
f32 func_002f8a18(f32) asm("func_002f8a18");
f32 fabsf(f32) asm("fabsf");
/*TARGET 002d1e08*/
// visible-box test: point p relative to the camera inside the view half extents
s32 func_002d1e08(W1814Cam* c, W1814Vec* p, f32* sz) asm("func_002d1e08");
// visible-box test: point p relative to the camera inside the view half extents
s32 func_002d1e08(W1814Cam* c, W1814Vec* p, f32* sz) {
    W1814Vec d = *p;
    d -= c->pos;
    f32 t = func_002f8a18(c->fov * 0.5f * 0.017453292f);
    t *= fabsf(d.z);
    f32 hw = t * 4.0f / 3.0f; hw += sz[0];
    t += sz[1];
    if (d.x < -hw || hw < d.x || d.y < -t || t < d.y) return 0;
    return 1;
}
}  // namespace n002d1e08

// 002d1f00 (was src/anon/tiny.cpp)
namespace n002d1f00 {
/*TARGET 002d1f00*/
// 002cebb0: moved to src/taito/minigame_base.cpp (linked unit)

u32 func_002d1f00(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d1f00jjjj");
// 002cebb0: moved to src/taito/minigame_base.cpp (linked unit)

u32 func_002d1f00(u32 a0, u32 a1, u32 a2, u32 a3) {  // ptr_add160
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)((s32)a0 + (160));
}
}  // namespace n002d1f00

// 002d1f10 (was src/anon/tiny.cpp)
namespace n002d1f10 {
/*TARGET 002d1f10*/
u32 func_002d1f10(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d1f10jjjj");
u32 func_002d1f10(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)((s32)a0 + (224));
}
}  // namespace n002d1f10

// 002d1f20 (was src/anon/tiny.cpp)
namespace n002d1f20 {
/*TARGET 002d1f20*/
u32 func_002d1f20(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d1f20jjjj");
u32 func_002d1f20(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)((s32)a0 + (288));
}
}  // namespace n002d1f20

// 002d1f30 (was src/anon/tiny.cpp)
namespace n002d1f30 {
/*TARGET 002d1f30*/
u32 func_002d1f30(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d1f30jjjj");
u32 func_002d1f30(u32 a0, u32 a1, u32 a2, u32 a3) {  // ptr_add304
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)((s32)a0 + (304));
}
}  // namespace n002d1f30

// 002d1f40 (was src/anon/tiny.cpp)
namespace n002d1f40 {
/*TARGET 002d1f40*/
// 0x2c9e90: moved to src/anon/unit_002c9998.cpp


void func_002d1f40(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d1f40jjjj");
// 0x2c9e90: moved to src/anon/unit_002c9998.cpp


void func_002d1f40(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)((u32)a0 + (88)) = (u8)v;
}
}  // namespace n002d1f40

// 002d1f50 (was src/anon/tiny.cpp)
namespace n002d1f50 {
void func_002d18e8(s32) asm("_Z13func_002d18e8i");
/*TARGET 002d1f50*/
// 0x002bdb58: definition moved into src/anon/unit_002bc978.cpp
void func_002d1f50(BD_VALUE* bd) asm("_Z13func_002d1f50P8BD_VALUE");
// 0x002bdb58: definition moved into src/anon/unit_002bc978.cpp
void func_002d1f50(BD_VALUE* bd) { func_002d18e8(bd[1].i); }
}  // namespace n002d1f50

// 002d1f68 (was src/anon/tiny_wrappers_more.cpp)
namespace n002d1f68 {
u32 func_002d1908(u32, u32, u32, u32) asm("_Z13func_002d1908jjjj");
/*TARGET 002d1f68*/
u32 func_002d1f68(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d1f68jjjj");
u32 func_002d1f68(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002d1908(((u32)(*(u32*)((u32)(a0) + 4u))), a1, a2, a3);
}
}  // namespace n002d1f68

namespace n002d1f80 {
void func_002d1f80() asm("func_002d1f80");
void func_002d1f80() {}
}  // namespace n002d1f80

// 002d1f88 (was src/anon/batch_w81.cpp)
namespace n002d1f88 {
// 64-byte matrix; copy-construct / assign with four 128-bit lq/sq (assignment checks self)
struct M81 {
    u8 b[64];
    M81() {}
    M81(const M81& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    M81& operator=(const M81& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// --- 002d1f88: push the inverse of the node's (orthonormal) matrix
u8* func_00106a60(u32) asm("func_00106a60");
/*TARGET 002d1f88*/
// buffer_get_by_index
void func_002d1f88(u8* o) asm("func_002d1f88");
// buffer_get_by_index
void func_002d1f88(u8* o) {
    M81 m = *(M81*)(*(u8**)(o + 4) + 160);
    // transpose the 3x3 part, translation = -(R^T * t)
    asm volatile(
        "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
        "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
        "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
        "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
        "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
        "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)"
        : : "r"(&m) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    *(M81*)(func_00106a60(1) + 16) = m;
}
}  // namespace n002d1f88

// 002d2058 (was src/anon/tiny_wrappers_more.cpp)
namespace n002d2058 {
u32 func_002d1f40(u32, u32, u32, u32) asm("_Z13func_002d1f40jjjj");
/*TARGET 002d2058*/
u32 func_002d2058(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d2058jjjj");
u32 func_002d2058(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002d1f40(((u32)(*(u32*)((u32)(a0) + 4u))), a1, a2, a3);
}
}  // namespace n002d2058

// 002d2070 (was src/anon/batch_w1756_g.cpp)
namespace n002d2070 {
struct S10_w1756 { s16 h[5]; };
extern S10_w1756 D_0032bae0 asm("D_0032bae0");
void func_00195750() asm("func_00195750");
void AREA__MapJump(S10_w1756*, s32, s32, s32, s32) asm("AREA__MapJump");
/*TARGET 002d2070*/
void func_002d2070() asm("func_002d2070");
void func_002d2070()
{
    S10_w1756 x = D_0032bae0;
    func_00195750();
    AREA__MapJump(&x, 1, 0, 0, 0);
}
}  // namespace n002d2070

// 002d20c8, 002d2128 (gap functions, never written before)
namespace n002d20c8 {
struct V { f32 x, y, z, w; V() {} V(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; } } __attribute__((aligned(16)));
static inline f32 norm(V* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
V func_002d20c8(u8* self, const V& b) asm("func_002d20c8");
V func_002d20c8(u8* self, const V& b)
{
    V r(b.x, b.y, 0.0f, 0.0f);
    r.w = norm(&r);
    return r;
}
}
namespace n002d2128 {
u32 func_002d2128(u8* self, u8* a, u8* b) asm("func_002d2128");
u32 func_002d2128(u8* self, u8* a, u8* b) { return (b ? *(u32*)(b + 104) : *(u32*)(a + 104)) & 1; }
}  // namespace n002d2128

// 002d2140 (was src/anon/tiny_wrappers_more.cpp)
namespace n002d2140 {
u32 Ti__MiniGame___prepare_zone(u32, u32, u32, u32) asm("_Z27Ti__MiniGame___prepare_zonejjjj");
/*TARGET 002d2140*/
u32 func_002d2140(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d2140jjjj");
u32 func_002d2140(u32 a0, u32 a1, u32 a2, u32 a3) {
    return Ti__MiniGame___prepare_zone(a0, a1, a2, a3);
}
}  // namespace n002d2140

// 002d2158, 002d21a0 (gap functions, never written before)
namespace n002d2158 {
s32 func_002cf270(u8*, s32) asm("func_002cf270");
u32 func_002cee58(u8*, u32) asm("func_002cee58");
u32 func_002d2158(u8* self, u8* e) asm("func_002d2158");
u32 func_002d2158(u8* self, u8* e)
{
    u32 r = 0;
    if (self[88]) {
        u8* t = *(u8**)(e + 28);
        if (t) r = func_002cf270(t + 4, 32);
        else r = func_002cee58(self, *(u32*)(e + 12));
    }
    return r;
}
}  // namespace n002d2158

namespace n002d21a0 {
struct V2c {
    f32 x, y, z, w;
    V2c() {}
    V2c(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V2c& operator=(const V2c& o) {
        if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Box2c { V2c a, b; };
struct Mat2c { V2c r[4]; };
extern f32 D_00349e10 asm("D_00349e10");
s32 func_002cf270(u8*, s32) asm("func_002cf270");
void func_002cf280(u8*, u32, u32) asm("func_002cf280");
void func_0011b6a8(void*) asm("func_0011b6a8");
void dk__Aabbox__mulMatrix(void*, void*) asm("dk__Aabbox__mulMatrix");
void func_001444c8(void*, void*, void*) asm("func_001444c8");
V2c YS__OBJ__get_target_pos(u8*) asm("YS__OBJ__get_target_pos");
u32 bbox_is_visible(u8* self, const void* box) asm("_ZN2Ti8MiniGame15bbox_is_visibleERKN2dk6AabboxE");
u32 func_002ceef8(u8* self, u8* o) asm("func_002ceef8");
u32 func_002d21a0(u8* self, u8* o) asm("func_002d21a0");
u32 func_002d21a0(u8* self, u8* o)
{
    u8* fl = o + 2800;
    u32 vis;
    if (func_002cf270(fl, 0x800)) {
        V2c lo(100.0f, 100.0f, 100.0f, 0.0f);
        V2c hi(-100.0f, -100.0f, -100.0f, 0.0f);
        Box2c box;
        Mat2c m;
        func_001444c8(&box, &hi, &lo);
        V2c* r3 = &m.r[3];
        func_0011b6a8(&m);
        *r3 = YS__OBJ__get_target_pos(o);
        m.r[3].w = 1.0f;
        dk__Aabbox__mulMatrix(&box, &m);
        vis = bbox_is_visible(self, &box);
    } else {
        vis = func_002ceef8(self, o);
    }
    if (vis) {
        func_002cf280(fl, 2, 0);
        *(f32*)(o + 2820) = 0.0f;
    } else {
        *(f32*)(o + 2820) += D_00349e10;
    }
    f32 lim = func_002cf270(fl, 2) ? 120.0f : 300.0f;
    return lim < *(f32*)(o + 2820);
}
}  // namespace n002d21a0
