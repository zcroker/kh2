// Linked unit 0x001ef780-0x001f0868 (ppp programs; one namespace per old matched source, gap functions written for the unit).
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

// 001ef780 (gap, written for the unit)
namespace n001ef780 {
struct S { u8 pad[12]; union { s32 i; f32 f; } a; s32 b; u8 p2[4]; f32 c; f32 e; f32 d; };
void func_001ef780(u8* o, u8* t) asm("func_001ef780");
void func_001ef780(u8* o, u8* t) {
    S* s = (S*)(o + **(s32**)(t + 12) + 160);
    s->a.i = 0;
    s->b = 0;
    s->c = s->e = s->d = s->a.f;
}
}

// 001ef7b0 (gap, written for the unit)
namespace n001ef7b0 {
struct M { u8 pad[0xa8]; u64 flags; };
struct S { s32 a, b, c; f32 x, y, n; f32 u, v, w; };
struct P { s32 id; s32 a, b, c; f32 x, y; f32 u, v, w; };
struct O { u8 pad[12]; s32 id; };
struct C { u8 pad[12]; s32* ofs; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern M* D_01d9e6e0 asm("D_01d9e6e0");
static inline f32 vsqrt(f32 x) {
    f32 r;
    asm volatile("qmtc2 %1, $vf2\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tvaddq.x $vf2, $vf0, Q\n\tqmfc2 %0, $vf2" : "=r"(r) : "r"(x));
    return r;
}
void func_001ef7b0(O* o, P* p, C* c) asm("func_001ef7b0");
void func_001ef7b0(O* o, P* p, C* c) {
    S* s = (S*)((u8*)o + c->ofs[0] + 160);
    if (D_01d9ea9c == 0 && !(D_01d9e6e0->flags & 0xff0000ff00ULL)) {
        s->v += s->w;
        s->u += s->v;
    }
    if (p->id == o->id) {
        s->a = p->a;
        s->b = p->b;
        s->c = p->c;
        f32 x = p->x;
        s->x = x;
        f32 y = p->y;
        s->y = y;
        s->n = x / vsqrt(x * x + y * y);
        if (D_01d9ea9c == 0 && !(D_01d9e6e0->flags & 0xff0000ff00ULL)) {
            s->u += p->u;
            s->v += p->v;
            s->w += p->w;
        }
    }
}
}

// 001ef8e0 (was src/anon/batch_w1987.cpp)
namespace n001ef8e0 {
struct Body1987 { f32 x, y, z, r; f32 f10, f14, f18; };
struct Nd1987 { u8 pad[160]; Body1987 b; };
struct Te1987 { s32 f0; s32 p; s32 f8, fc; };
struct Mgr1987 { u8 pad[128]; Te1987* tbl; };
struct Ent1987 { s32 f0; s32 idx1; s32 off1; s32 idx2; s32 off2; f32 f14; };
struct Ent21987 { u8 pad[12]; s32* offs; };
struct V41987 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern Mgr1987* D_01d9e6e0 asm("D_01d9e6e0");
extern Body1987 D_01d9e360 asm("D_01d9e360");
f32 sceVu0InnerProduct(Body1987*, V41987*) asm("sceVu0InnerProduct");
/*TARGET 001ef8e0*/
void func_001ef8e0(u8* base, Ent1987* e, Ent21987* e2) asm("func_001ef8e0");
void func_001ef8e0(u8* base, Ent1987* e, Ent21987* e2)
{
    Body1987* a = &((Nd1987*)(base + e2->offs[0]))->b;
    Body1987* b0;
    Body1987* b1;
    V41987 d;
    f32 len;
    if (e->idx1 != -1) b0 = &((Nd1987*)(D_01d9e6e0->tbl[e->idx1].p + e->off1))->b; else b0 = &D_01d9e360;
    if (e->idx2 != -1) b1 = &((Nd1987*)(D_01d9e6e0->tbl[e->idx2].p + e->off2))->b; else b1 = &D_01d9e360;
    d.x = a->x - b1->x;
    d.y = a->y - b1->y;
    d.z = a->z - b1->z;
    asm volatile("lqc2 $vf10, 0(%1)\n\tvadd.xyz $vf8, $vf0, $vf10\n\tvmul.xyz $vf10, $vf10, $vf10\n\tvmove.xyz $vf9, $vf10\n\t"
                 "vaddx.y $vf9, $vf9, $vf9x\n\tvaddy.z $vf9, $vf9, $vf9y\n\tvsqrt Q, $vf9z\n\tvwaitq\n\t"
                 "vaddq.x $vf10, $vf0, Q\n\tqmfc2 %0, $vf10\n\tvdiv Q, $vf0w, $vf10x\n\tvwaitq\n\t"
                 "vmulq.xyz $vf9, $vf8, Q\n\tsqc2 $vf9, 0(%1)"
                 : "=r"(len) : "r"(&d) : "memory");
    if (len < b0->r) {
        f32 t = sceVu0InnerProduct(b0, &d);
        if (b0->f14 < t) {
            Body1987* c = &((Nd1987*)(base + e2->offs[1]))->b;
            f32 k = b0->f18 * ((t - b0->f14) / (1.0f - b0->f14)) * ((b0->r - len) / b0->r) / e->f14;
            c->x += d.x * k;
            c->y += d.y * k;
            c->z += d.z * k;
        }
    }
}
}  // namespace n001ef8e0

// 001efae8 (gap, written for the unit)
namespace n001efae8 {
void func_001efae8(void) asm("func_001efae8");
void func_001efae8(void) {}
}

// 001efaf0 (gap, written for the unit)
namespace n001efaf0 {
void func_001efaf0(void) asm("func_001efaf0");
void func_001efaf0(void) {}
}

// 001efaf8 (gap, written for the unit)
namespace n001efaf8 {
void func_001efaf8(void) asm("func_001efaf8");
void func_001efaf8(void) {}
}

// 001efb00 (gap, written for the unit)
namespace n001efb00 {
void func_001efb00(void) asm("func_001efb00");
void func_001efb00(void) {}
}

// 001efb08 (gap, written for the unit)
namespace n001efb08 {
void func_001efb08(void) asm("func_001efb08");
void func_001efb08(void) {}
}

// 001efb10 (gap, written for the unit)
namespace n001efb10 {
void func_001efb10(void) asm("func_001efb10");
void func_001efb10(void) {}
}

// 001efb18 (was src/anon/batch_w2.cpp)
namespace n001efb18 {
// namespace YS

// 001826e0: moved to src/yasui/libys/areadata.cpp

struct Vec3f { f32 x, y, z; };
/*TARGET 001efb18*/
void wtarget_001efb18(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_001efb18jjjj");
void wtarget_001efb18(u32 a0, u32 a1, u32, u32) {
    Vec3f* v = (Vec3f*)(a0 + *(u32*)(*(u32*)(a1 + 12) + 4) + 160);
    f32 z = 0.0f;
    v->x = z;
    v->z = z;
    v->y = z;
}
}  // namespace n001efb18

// 001efb40 (was src/anon/tiny_wrappers_more.cpp)
namespace n001efb40 {
u32 func_001efb18(u32, u32, u32, u32) asm("_Z13func_001efb18jjjj");
/*TARGET 001efb40*/
// 0x001e7050: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_001efb40(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001efb40jjjj");
// 0x001e7050: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_001efb40(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001efb18(a0, a1, a2, a3);
}
}  // namespace n001efb40

// 001efb58 (gap, written for the unit)
namespace n001efb58 {
struct V { f32 x, y, z; };
struct P { s32 id; V v; };
struct M { u8 pad[0xa8]; u64 flags; };
struct O { u8 pad[12]; s32 id; };
struct C { u8 pad[12]; s32* ofs; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern s32 D_01d9eab4 asm("D_01d9eab4");
extern M* D_01d9e6e0 asm("D_01d9e6e0");
void func_001efb58(O* o, P* p, C* c) asm("func_001efb58");
void func_001efb58(O* o, P* p, C* c) {
    V* a = (V*)((u8*)o + c->ofs[0] + 160);
    V* b = (V*)((u8*)o + c->ofs[1] + 160);
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (p->id == o->id) {
        f32 x = b->x + p->v.x; f32 y = b->y + p->v.y; f32 z = b->z + p->v.z;
        b->x = x; b->y = y; b->z = z;
    }
    if (D_01d9eab4 != 0) return;
    {
        f32 x = a->x + b->x; f32 y = a->y + b->y; f32 z = a->z + b->z;
        a->x = x; a->y = y; a->z = z;
    }
}
}

// 001efc28 (was src/anon/batch_w4.cpp)
namespace n001efc28 {
struct Vec3u {
    u32 x, y, z;
};
/*TARGET 001efc28*/
// 0x001d71f0: definition moved into src/anon/unit_001d68e0.cpp

void func_001efc28(u8* p, u8* q) asm("func_001efc28");
// 0x001d71f0: definition moved into src/anon/unit_001d68e0.cpp

void func_001efc28(u8* p, u8* q) {
    Vec3u* r = (Vec3u*)(p + ((s32*)*(u32*)(q + 12))[1] + 160);
    r->x = 0;
    r->z = 0;
    r->y = 0;
}
}  // namespace n001efc28

// 001efc48 (was src/anon/tiny_wrappers_more.cpp)
namespace n001efc48 {
u32 func_001efc28(u32, u32, u32, u32) asm("_Z13func_001efc28jjjj");
/*TARGET 001efc48*/
u32 func_001efc48(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001efc48jjjj");
u32 func_001efc48(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001efc28(a0, a1, a2, a3);
}
}  // namespace n001efc48

// 001efc60 (gap, written for the unit)
namespace n001efc60 {
struct V { s32 x, y, z; };
struct P { s32 id; V v; };
struct M { u8 pad[0xa8]; u64 flags; };
struct O { u8 pad[12]; s32 id; };
struct C { u8 pad[12]; s32* ofs; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern s32 D_01d9eab4 asm("D_01d9eab4");
extern M* D_01d9e6e0 asm("D_01d9e6e0");
void func_001efc60(O* o, P* p, C* c) asm("func_001efc60");
void func_001efc60(O* o, P* p, C* c) {
    V* a = (V*)((u8*)o + c->ofs[0] + 160);
    V* b = (V*)((u8*)o + c->ofs[1] + 160);
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (p->id == o->id) {
        s32 x = b->x + p->v.x; s32 y = b->y + p->v.y; s32 z = b->z + p->v.z;
        b->x = x; b->y = y; b->z = z;
    }
    if (D_01d9eab4 != 0) return;
    {
        s32 x = a->x + b->x; s32 y = a->y + b->y; s32 z = a->z + b->z;
        a->x = x; a->y = y; a->z = z;
    }
}
}

// 001efd38 (was src/anon/batch_w3.cpp)
namespace n001efd38 {
// namespace YS
void wtarget_001efd38(u32, u32, u32, u32) asm("_Z16wtarget_001efd38jjjj");
// namespace YS

struct Vec3 {
    f32 x, y, z;
};
/*TARGET 001efd38*/
void wtarget_001efd38(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_001efd38jjjj");
void wtarget_001efd38(u32 a0, u32 a1, u32, u32) {
    a0 += (*(u32**)(a1 + 12))[1];
    Vec3* v = (Vec3*)(a0 + 160);
    v->x = v->y = v->z = 0.0f;
}
}  // namespace n001efd38

// 001efd60 (was src/anon/tiny_wrappers_more.cpp)
namespace n001efd60 {
u32 func_001efd38(u32, u32, u32, u32) asm("_Z13func_001efd38jjjj");
/*TARGET 001efd60*/
u32 func_001efd60(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001efd60jjjj");
u32 func_001efd60(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001efd38(a0, a1, a2, a3);
}
}  // namespace n001efd60

// 001efd78 (gap, written for the unit)
namespace n001efd78 {
struct V { f32 x, y, z; };
struct P { s32 id; V v; };
struct M { u8 pad[0xa8]; u64 flags; };
struct O { u8 pad[12]; s32 id; };
struct C { u8 pad[12]; s32* ofs; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern s32 D_01d9eab4 asm("D_01d9eab4");
extern M* D_01d9e6e0 asm("D_01d9e6e0");
void func_001efd78(O* o, P* p, C* c) asm("func_001efd78");
void func_001efd78(O* o, P* p, C* c) {
    V* a = (V*)((u8*)o + c->ofs[0] + 160);
    V* b = (V*)((u8*)o + c->ofs[1] + 160);
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (p->id == o->id) {
        f32 x = b->x + p->v.x; f32 y = b->y + p->v.y; f32 z = b->z + p->v.z;
        b->x = x; b->y = y; b->z = z;
    }
    if (D_01d9eab4 != 0) return;
    {
        f32 x = a->x + b->x; f32 y = a->y + b->y; f32 z = a->z + b->z;
        a->x = x; a->y = y; a->z = z;
    }
}
}

// 001efe48 (was src/anon/batch_w247.cpp)
namespace n001efe48 {
union PtrF247 { u8* p; f32 f; };
extern PtrF247 D_01d9e6e8 asm("D_01d9e6e8");
void func_001e8fe0(u8*, u8*) asm("func_001e8fe0");
// VU0 macro: scale row xyz by k.
static inline void ScaleRow247(u8* row, f32 k)
{
    asm volatile(
        "qmtc2 %1, $vf9\n\t"
        "lqc2 $vf10, 0(%0)\n\t"
        "vmulx.xyz $vf10, $vf10, $vf9x\n\t"
        "sqc2 $vf10, 0(%0)"
        : : "r"(row), "r"(k) : "memory");
}
/*TARGET 001efe48*/
// 0x001eac28: definition moved into src/anon/unit_001e8ac8.cpp
void func_001efe48(u8* base, u32 unused, u8* desc) asm("func_001efe48");
// 0x001eac28: definition moved into src/anon/unit_001e8ac8.cpp
void func_001efe48(u8* base, u32 unused, u8* desc)
{
    u32* d = *(u32**)(desc + 12);
    u8* p0 = base + d[0];
    u8* p1 = base + d[1];
    u8* p2 = base + d[2];
    f32* t = (f32*)(p0 + 160);
    f32* s = (f32*)(p2 + 160);
    func_001e8fe0(D_01d9e6e8.p + 16, p1 + 160);
    ScaleRow247(D_01d9e6e8.p + 16, s[0]);
    ScaleRow247(D_01d9e6e8.p + 32, s[1]);
    ScaleRow247(D_01d9e6e8.p + 48, s[2]);
    *(f32*)(D_01d9e6e8.p + 64) = t[0];
    *(f32*)(D_01d9e6e8.p + 68) = t[1];
    *(f32*)(D_01d9e6e8.p + 72) = t[2];
}
}  // namespace n001efe48

// 001eff30 (was src/anon/tiny_auto80_queue.cpp)
namespace n001eff30 {
/*TARGET 001eff30*/
// 0x001ef578: definition moved into src/anon/unit_001ec098.cpp

void func_001eff30(u32 a0, u8* a1) asm("_Z13func_001eff30jPh");
// 0x001ef578: definition moved into src/anon/unit_001ec098.cpp

void func_001eff30(u32 a0, u8* a1) {
    f32 z = 0.0f;
    *(u32*)(a1 + 12) = a0;
    *(f32*)(a1 + 8) = z;
    *(f32*)(a1 + 4) = z;
    *(f32*)(a1 + 0) = z;
}
}  // namespace n001eff30

// 001eff48 (gap, written for the unit)
namespace n001eff48 {
void func_001eff48(u8* o, u8* t) asm("func_001eff48");
void func_001eff48(u8* o, u8* t) { *(s32*)(o + **(s32**)(t + 12) + 172) = 0; }
}

// 001eff60 (gap, written for the unit)
namespace n001eff60 {
struct V { f32 x, y, z; };
struct T { s32 id; V v; };
struct S { V v; T* t; };
void func_001eff60(u8* o, u8* t) asm("func_001eff60");
void func_001eff60(u8* o, u8* t) {
    S* s = (S*)(o + **(s32**)(t + 12) + 160);
    f32 x = s->v.x - s->t->v.x; f32 y = s->v.y - s->t->v.y; f32 z = s->v.z - s->t->v.z;
    s->v.x = x; s->v.y = y; s->v.z = z;
}
}

// 001effa8 (was src/anon/batch_w2377.c)
namespace n001effa8 {
/* partMng (C): add an event's vector to a part's per-object vector work area.
 * The work vector and the event vector share one struct type, so gcc can tell
 * that different fields never overlap (needed for the original load order). */
typedef struct { f32 x, y, z; } PVec3;
typedef struct { PVec3 v; s32 init; } PAddWork;
typedef struct { s32 id; PVec3 v; } PAddArg;
typedef struct { u8 pad[0xc]; s32* offs; } PAddDesc;
typedef struct { u8 pad[0xc]; s32 id; } PObj;
typedef struct { u8 pad[0xa8]; u64 flags; } PSys;
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern PSys* D_01d9e6e0 asm("D_01d9e6e0");
void func_001eff30(PAddArg*, PAddWork*) asm("func_001eff30");
/*TARGET 001effa8*/
/* 001effa8 */
void func_001effa8(PObj* obj, PAddArg* arg, PAddDesc* desc) asm("func_001effa8");
/* 001effa8 */
void func_001effa8(PObj* obj, PAddArg* arg, PAddDesc* desc)
{
    PAddWork* w = (PAddWork*)((u8*)obj + *desc->offs + 0xa0);
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (w->init == 0) func_001eff30(arg, w);
    if (arg->id != obj->id) return;
    w->v.x += arg->v.x;
    w->v.y += arg->v.y;
    w->v.z += arg->v.z;
}
}  // namespace n001effa8

// 001f0080 (was src/anon/tiny_auto80.cpp)
namespace n001f0080 {
/*TARGET 001f0080*/
// 0x001e0cb8: definition moved into src/anon/unit_001e0cb8.cpp

void func_001f0080(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001f0080jjjj");
// 0x001e0cb8: definition moved into src/anon/unit_001e0cb8.cpp

void func_001f0080(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(volatile u32*)((u32)r5 + (s32)(12)) = r4;
    *(volatile u32*)((u32)r5 + (s32)(8)) = 0u;
    *(volatile u32*)((u32)r5 + (s32)(4)) = 0u;
    *(volatile u32*)((u32)r5 + (s32)(0)) = 0u;
}
}  // namespace n001f0080

// 001f0098 (gap, written for the unit)
namespace n001f0098 {
void func_001f0098(u8* o, u8* t) asm("func_001f0098");
void func_001f0098(u8* o, u8* t) { *(s32*)(o + **(s32**)(t + 12) + 172) = 0; }
}

// 001f00b0 (gap, written for the unit)
namespace n001f00b0 {
struct V { s32 x, y, z; };
struct T { s32 id; V v; };
struct S { V v; T* t; };
void func_001f00b0(u8* o, u8* t) asm("func_001f00b0");
void func_001f00b0(u8* o, u8* t) {
    S* s = (S*)(o + **(s32**)(t + 12) + 160);
    s32 x = s->v.x - s->t->v.x; s32 y = s->v.y - s->t->v.y; s32 z = s->v.z - s->t->v.z;
    s->v.x = x; s->v.y = y; s->v.z = z;
}
}

// 001f00f8 (was src/anon/auto80_199_queue.cpp)
namespace n001f00f8 {
/*TARGET 001f00f8*/
// 0x001e8fe0: definition moved into src/anon/unit_001e8ac8.cpp

void func_001f00f8(s32* a0) asm("_Z13func_001f00f8Pi");
// 0x001e8fe0: definition moved into src/anon/unit_001e8ac8.cpp

void func_001f00f8(s32* a0) {
    s32 v = a0[0];
    if (v > 0x10000) {
        while (1) {
            s32 t = v + (s32)0xFFFF0000;
            if (t > 0x10000) {
                v = t;
            } else {
                a0[0] = t;
                break;
            }
        }
        v = a0[1];
    } else {
        v = a0[1];
    }

    if (v > 0x10000) {
        while (1) {
            s32 t = v + (s32)0xFFFF0000;
            if (t > 0x10000) {
                v = t;
            } else {
                a0[1] = t;
                break;
            }
        }
        v = a0[2];
    } else {
        v = a0[2];
    }

    if (v > 0x10000) {
        while (1) {
            s32 t = v + (s32)0xFFFF0000;
            if (t > 0x10000) {
                v = t;
            } else {
                a0[2] = t;
                break;
            }
        }
    }
}
}  // namespace n001f00f8

// 001f01b8 (was src/anon/batch_w2381_nsa.c)
namespace n001f01b8 {
/* Plain C (partMng / pppPart range), built with -fno-strict-aliasing. */

/* ---- 001f01b8: add an offset vector to a part's position, then refresh it */
typedef struct { s32 x, y, z, w; } W2381Vec;
typedef struct { u8 pad[0xa0]; W2381Vec pos; } W2381Part;
typedef struct { s32 id; W2381Vec d; } W2381Move;
typedef struct { u32 p0, p4, p8; s32 id; } W2381Owner;
typedef struct { u32 p0, p4, p8; s32* off; } W2381Desc;
typedef struct { u64 f0:8; u64 f1:8; u64 f2:16; u64 f4:8; u64 f5:24; } W2381Bits;
typedef struct { u8 pad[0xa8]; W2381Bits b; } W2381Mng;
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern W2381Mng* D_01d9e6e0 asm("D_01d9e6e0");
void func_001f0080(W2381Move*, W2381Vec*) asm("func_001f0080");
void func_001f00f8(W2381Vec*) asm("func_001f00f8");
/*TARGET 001f01b8*/
void func_001f01b8(W2381Owner* o, W2381Move* m, W2381Desc* d) asm("func_001f01b8");
void func_001f01b8(W2381Owner* o, W2381Move* m, W2381Desc* d)
{
    W2381Vec* v = &((W2381Part*)((u8*)o + *d->off))->pos;
    if (D_01d9ea9c == 0 && D_01d9e6e0->b.f1 == 0 && D_01d9e6e0->b.f4 == 0) {
        if (v->w == 0) func_001f0080(m, v);
        if (m->id == o->id) {
            v->x += m->d.x;
            v->y += m->d.y;
            v->z += m->d.z;
            func_001f00f8(v);
        }
    }
}
}  // namespace n001f01b8

// 001f02b0 (was src/anon/tiny_auto80_queue.cpp)
namespace n001f02b0 {
/*TARGET 001f02b0*/
void func_001f02b0(u32 a0, u8* a1) asm("_Z13func_001f02b0jPh");
void func_001f02b0(u32 a0, u8* a1) {
    f32 z = 0.0f;
    *(u32*)(a1 + 12) = a0;
    *(f32*)(a1 + 8) = z;
    *(f32*)(a1 + 4) = z;
    *(f32*)(a1 + 0) = z;
}
}  // namespace n001f02b0

// 001f02c8 (gap, written for the unit)
namespace n001f02c8 {
void func_001f02c8(u8* o, u8* t) asm("func_001f02c8");
void func_001f02c8(u8* o, u8* t) { *(s32*)(o + **(s32**)(t + 12) + 172) = 0; }
}

// 001f02e0 (gap, written for the unit)
namespace n001f02e0 {
struct V { f32 x, y, z; };
struct T { s32 id; V v; };
struct S { V v; T* t; };
void func_001f02e0(u8* o, u8* t) asm("func_001f02e0");
void func_001f02e0(u8* o, u8* t) {
    S* s = (S*)(o + **(s32**)(t + 12) + 160);
    f32 x = s->v.x - s->t->v.x; f32 y = s->v.y - s->t->v.y; f32 z = s->v.z - s->t->v.z;
    s->v.x = x; s->v.y = y; s->v.z = z;
}
}

// 001f0328 (was src/anon/batch_w2377.c)
namespace n001f0328 {
/* partMng (C): add an event's vector to a part's per-object vector work area.
 * The work vector and the event vector share one struct type, so gcc can tell
 * that different fields never overlap (needed for the original load order). */
typedef struct { f32 x, y, z; } PVec3;
typedef struct { PVec3 v; s32 init; } PAddWork;
typedef struct { s32 id; PVec3 v; } PAddArg;
typedef struct { u8 pad[0xc]; s32* offs; } PAddDesc;
typedef struct { u8 pad[0xc]; s32 id; } PObj;
typedef struct { u8 pad[0xa8]; u64 flags; } PSys;
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern PSys* D_01d9e6e0 asm("D_01d9e6e0");
void func_001f02b0(PAddArg*, PAddWork*) asm("func_001f02b0");
/*TARGET 001f0328*/
/* 001f0328: same as 001effa8 with its own init helper */
void func_001f0328(PObj* obj, PAddArg* arg, PAddDesc* desc) asm("func_001f0328");
/* 001f0328: same as 001effa8 with its own init helper */
void func_001f0328(PObj* obj, PAddArg* arg, PAddDesc* desc)
{
    PAddWork* w = (PAddWork*)((u8*)obj + *desc->offs + 0xa0);
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (w->init == 0) func_001f02b0(arg, w);
    if (arg->id != obj->id) return;
    w->v.x += arg->v.x;
    w->v.y += arg->v.y;
    w->v.z += arg->v.z;
}
}  // namespace n001f0328

// 001f0400 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n001f0400 {
u32 sceVu0MulMatrix(u32, u32, u32, u32) asm("_Z15sceVu0MulMatrixjjjj");
extern u8 D_01d9e900 asm("D_01d9e900");
extern u8 D_01da0000 asm("D_01da0000");
/*TARGET 001f0400*/
// 0x001eb2a0: definition moved into src/anon/unit_001e8ac8.cpp

u32 func_001f0400(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001f0400jjjj");
// 0x001eb2a0: definition moved into src/anon/unit_001e8ac8.cpp

u32 func_001f0400(u32 a0, u32 a1, u32 a2, u32 a3) {
    return sceVu0MulMatrix(((u32)(((u32)(*(u32*)((u32)((u32)&D_01da0000) - 6424u)))) + 80u), (u32)&D_01d9e900, ((u32)(((u32)(*(u32*)((u32)((u32)&D_01da0000) - 6424u)))) + 16u), a3);
}
}  // namespace n001f0400

// 001f0430 (was src/anon/batch_w2026_nsa.cpp)
namespace n001f0430 {
struct V30 { u8 pad[8]; f32 f8; u8 pad2[8]; f32 f14; };
struct R30 { V30* p; f32 a, b, c, d, e, f; };
/*TARGET 001f0430*/
void func_001f0430(V30* v, R30* r) asm("func_001f0430");
void func_001f0430(V30* v, R30* r) {
    f32 z = 0.0f;
    r->a = v->f8;
    r->d = v->f14;
    r->f = z;
    r->e = z;
    r->c = z;
    r->b = z;
    r->p = v;
}
}  // namespace n001f0430

// 001f0460 (gap, written for the unit)
namespace n001f0460 {
void func_001f0460(u8* o, u8* t) asm("func_001f0460");
void func_001f0460(u8* o, u8* t) { *(s32*)(o + (*(s32**)(t + 12))[2] + 160) = 0; }
}

// 001f0478 (gap, written for the unit)
namespace n001f0478 {
struct S { u8 pad[8]; f32 a; f32 d; u8 p2[4]; f32 c; f32 b; };
void func_001f0478(u8* o, u8* t) asm("func_001f0478");
void func_001f0478(u8* o, u8* t) {
    S* s = (S*)(o + (*(s32**)(t + 12))[2] + 160);
    s->a = s->d = s->c = s->b = 0.0f;
}
}

// 001f04a0 (gap, written for the unit)
namespace n001f04a0 {
void func_001f04a0(void) asm("func_001f04a0");
void func_001f04a0(void) {}
}

// 001f04a8 (was src/anon/batch_w94.cpp)
namespace n001f04a8 {
void func_001f0430(u8*, f32*) asm("func_001f0430");
f32 func_002f8b00(f32, f32) asm("func_002f8b00");
// to_2f9a38
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9eab4 asm("D_01d9eab4");
/*TARGET 001f04a8*/
void func_001f04a8(u8* self, u8* ent, u8* desc) asm("func_001f04a8");
void func_001f04a8(u8* self, u8* ent, u8* desc) {
    f32* s = (f32*)(self + *(u32*)(*(u8**)(desc + 12) + 8) + 160);
    if (*(u32*)s == 0) func_001f0430(ent, s);
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (*(u32*)ent == *(u32*)(self + 12)) {
        s[2] += *(f32*)(ent + 12);
        s[3] += *(f32*)(ent + 16);
        s[5] += *(f32*)(ent + 24);
        s[6] += *(f32*)(ent + 28);
    }
    if (D_01d9eab4) return;
    s[2] += s[3];
    s[1] += s[2];
    s[5] += s[6];
    s[4] += s[5];
    s[1] = func_002f8b00(s[1], 32768.0f);  // to_2f9a38
    s[4] = func_002f8b00(s[4], 32768.0f);  // to_2f9a38
}
}  // namespace n001f04a8

// 001f0600 (was whole asm, src/anon/batch_w3883.s): model render request. Cast stores for w12/w28 keep
// the D_01d9e6e8/D_01d9eaa4 loads after them (a field store lets sched1 hoist the loads).
namespace n001f0600 {
typedef struct { f32 m[4][4]; } __attribute__((aligned(16))) M1f0600;
typedef struct {
    u32 flags;
    void* p4;
    u16 tex;
    u8 b10;
    u8 pad11;
    s32 w12;
    s32 y;
    s32 x;
    u8 rgba[4];
    s32 w28;
    void* p32;
    void* p36;
    void* p40;
    void* p44;
    M1f0600* mtx;
    s32 p52;
    s32 p56;
    s32 p60;
    s32 w64;
    s32 w68;
    u8 pad72[4];
    u8 b76;
    u8 b77;
    u8 pad78[18];
} Req1f0600;
typedef struct { u32 flags; u8 pad[18]; u16 tex; } Mdl1f0600;
typedef struct { u8 pad0[4]; s32 set; u8 pad1[24]; union { u16 tex; u8 texlo; } t; u8 mode; u8 b35; u8 b36; u8 b37; } Ent1f0600;
typedef struct { u8 pad0[12]; s32* off; } Ctx1f0600;
typedef struct { u8 pad0[16]; u8* sets; } Res1f0600;
typedef struct { u8 pad0[16]; M1f0600 m16; u8 pad1[80 - 80]; u8 m80[64]; s32 p144; s32 p148; } Ovr1f0600;
extern Res1f0600* D_01d9e6e4 asm("D_01d9e6e4");
extern Ovr1f0600* D_01d9e6e8 asm("D_01d9e6e8");
extern M1f0600 D_01d9e840 asm("D_01d9e840");
extern u8 D_01d9eac0[] asm("D_01d9eac0");
extern u8 D_01d9e9c0[] asm("D_01d9e9c0");
extern u8 D_01d9e980[] asm("D_01d9e980");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
void sceVu0MulMatrix(M1f0600*, M1f0600*, M1f0600*) asm("sceVu0MulMatrix");
s32 func_0020f1e0(Mdl1f0600*, Req1f0600*, s32) asm("func_0020f1e0");
void func_001f0600(u8* base, Ent1f0600* e, Ctx1f0600* c) asm("func_001f0600");
void func_001f0600(u8* base, Ent1f0600* e, Ctx1f0600* c)
{
    f32* pos = (f32*)(base + c->off[2] + 160);
    Mdl1f0600* m;
    u8* col;
    Req1f0600 r;
    M1f0600 tmp;
    Ovr1f0600* g;
    if (e->set == 0xffff) return;
    m = *(Mdl1f0600**)(D_01d9e6e4->sets + e->set * 36 + 28);
    col = base + c->off[0] + 160;
    r.rgba[0] = col[8];
    r.rgba[1] = col[9];
    r.rgba[3] = col[11];
    r.rgba[2] = col[10];
    if (col[11] == 0) return;
    r.flags = 0;
    if (e->mode & 2) r.flags = 4;
    else if (e->mode & 1) r.flags = 128;
    if ((m->flags & 1) == 0) r.flags |= 8;
    if (!(m->flags & 2)) r.flags |= 16;
    if (e->b35) r.flags |= 0x200;
    if (e->b36) r.flags |= 0x100;
    if (e->b37) {
        r.flags = (r.flags & ~16) | 0x2000;
        r.mtx = &tmp;
        sceVu0MulMatrix(&tmp, &D_01d9e840, &D_01d9e6e8->m16);
    } else {
        r.mtx = 0;
    }
    r.p4 = D_01d9eac0;
    if (e->t.texlo == 255) r.tex = m->tex;
    else r.tex = e->t.tex;
    *(s32*)((u8*)&r + 12) = 0;
    r.b10 = 0;
    r.y = (s32)(pos[1] * 65536.0f);
    r.x = (s32)(pos[4] * 65536.0f);
    r.p36 = D_01d9e9c0;
    r.p40 = D_01d9e980;
    *(s32*)((u8*)&r + 28) = 0;
    r.w68 = 0;
    g = D_01d9e6e8;
    r.p32 = g->m80;
    r.p44 = &g->m16;
    r.p52 = D_01d9eaa4;
    r.p56 = g->p144;
    r.p60 = g->p148;
    r.w64 = 0;
    r.b76 = 0;
    r.b77 = 0;
    D_01d9eaa4 = func_0020f1e0(m, &r, *(s32*)(D_01d9e6e4->sets + e->set * 36 + 32));
}
}  // namespace n001f0600
