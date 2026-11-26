// Linked unit 0x00123990-0x00125f78 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "tiny_auto80_solver_structs.hpp"

// 00123990 (gap function, not written before)
namespace g00123990 {
struct SE { u32 w; u8 pad[4]; u32 sz; u8 pad2[20]; };
struct Sub { u8 pad[28]; s32 n; SE e[1]; };
struct O { void* vt; Sub* sub; };
u32 func_00123990(O* o, u8* fl) asm("func_00123990");
u32 func_00123990(O* o, u8* fl) {
    Sub* s = o->sub;
    u32 r = 0;
    for (s32 i = 0; i < s->n; i++)
        if (fl[i] & 0xf) r += s->e[i].sz;
    return r;
}
}  // namespace g00123990

// 001239d8 (was src/anon/batch_w85.cpp)
namespace n001239d8 {
void func_0011ee18(void*) asm("func_0011ee18");
// obj_ctor_347940
void func_0011f2f0(void*) asm("func_0011f2f0");
extern u8 D_00347a90[] asm("D_00347a90");
typedef s32 (*PartFn)(void*);
struct Obj123 { void* vtbl; u8* data; u8 pad[8]; s32 n; s32 a[3]; s32 b[3]; };
/*TARGET 001239d8*/
// constructor: walks the part offset table, accumulating running sizes
void func_001239d8(Obj123* o) asm("func_001239d8");
// constructor: walks the part offset table, accumulating running sizes
void func_001239d8(Obj123* o) {
    s32 s3, s4;
    u8* d;
    s32* list;
    s4 = 0; s3 = 0;
    func_0011ee18(o);  // obj_ctor_347940
    d = o->data;
    o->n = 0;
    o->vtbl = D_00347a90;
    list = (s32*)(d + 16);
    while (*list) {
        s32* p = (s32*)(d + *list);
        list++;
        func_0011f2f0(p);
        s4 += ((PartFn*)*p)[2](p);
        o->a[o->n] = s4;
        s3 += ((PartFn*)*p)[12](p);
        o->b[o->n] = s3;
        o->n++;
    }
}
}  // namespace n001239d8

// 00123ac0 (was src/anon/batch_w86.cpp)
namespace n00123ac0 {
struct Obj;
struct Elem;
struct Obj;
struct Obj;
struct Obj;
struct Elem;
struct Elem;
typedef s32 (*EFn)(Elem*);
struct Elem { s32 vt; };
#define VT(e) ((EFn*)(e)->vt)
struct Obj { void* vt; u32* tbl; u8 p8[8]; s32 n; s32 a[3]; s32 b[3]; };
extern u8 D_00347a90[] asm("D_00347a90");
void func_0011ee18(Obj*) asm("func_0011ee18");
// obj_ctor_347940
void func_0011f2f0(Elem*) asm("func_0011f2f0");
/*TARGET 00123ac0*/
void func_00123ac0(Obj* o) asm("func_00123ac0");
void func_00123ac0(Obj* o)
{
    s32 a = 0;
    s32 b = 0;
    func_0011ee18(o);  // obj_ctor_347940
    u32* t = o->tbl;
    o->n = 0;
    o->vt = D_00347a90;
    u32* p = t + 4;
    while (*p) {
        Elem* e = (Elem*)((u8*)t + *p++);
        func_0011f2f0(e);
        a += VT(e)[2](e);
        o->a[o->n] = a;
        b += VT(e)[12](e);
        s32 n = o->n;
        o->b[n] = b;
        o->n = n + 1;
    }
}
}  // namespace n00123ac0

// 00123ba8 (was src/anon/batch_w44.cpp)
namespace n00123ba8 {
// A local whose (empty) destructor keeps the final call from becoming a sibcall.
struct NoTail { ~NoTail() {} };
void kn__modelDestroy(void*) asm("kn__modelDestroy");
void func_0011ee58(void*) asm("func_0011ee58");
// Destructor: release each offset-listed entry of the attached table.
extern u32 D_00347a90 asm("D_00347a90");
/*TARGET 00123ba8*/
void func_00123ba8(u32* self) asm("func_00123ba8");
void func_00123ba8(u32* self) {
    u8* a = (u8*)self[1];
    self[0] = (u32)&D_00347a90;
    for (u32* p = (u32*)(a + 16); *p; p++) kn__modelDestroy(a + *p);
    NoTail g;
    func_0011ee58(self);  // set_vtbl_347940
}
}  // namespace n00123ba8

// 00123c20 (was src/anon/batch_wcx2.cpp)
namespace n00123c20 {
// ---- 00123c20
extern u8 D_00347a90[] asm("D_00347a90");
void kn__modelDestroy(u8*) asm("kn__modelDestroy");
void func_0011ee58(u32*) asm("func_0011ee58");
// set_vtbl_347940
struct NoTail_00123c20 { ~NoTail_00123c20() {} };
/*TARGET 00123c20*/
void func_00123c20(u32* p) asm("func_00123c20");
void func_00123c20(u32* p) {
    NoTail_00123c20 nt;
    u8* q = (u8*)p[1];
    *p = (u32)D_00347a90;
    for (s32* s = (s32*)(q + 16); *s; s++) kn__modelDestroy(q + *s);
    func_0011ee58(p);  // set_vtbl_347940
}
}  // namespace n00123c20

// 00123c98 (was src/anon/batch_wcx2.cpp)
namespace n00123c98 {
// ---- 00123c20
extern u8 D_00347a90[] asm("D_00347a90");
void kn__modelDestroy(u8*) asm("kn__modelDestroy");
void func_0011ee58(u32*) asm("func_0011ee58");
// ---- 00123c98
void func_00106420_3c98(u32*) asm("func_00106420");
/*TARGET 00123c98*/
void func_00123c98(u32* p) asm("func_00123c98");
void func_00123c98(u32* p) {
    u8* q = (u8*)p[1];
    *p = (u32)D_00347a90;
    for (s32* s = (s32*)(q + 16); *s; s++) kn__modelDestroy(q + *s);
    func_0011ee58(p);  // set_vtbl_347940
    func_00106420_3c98(p);
}
}  // namespace n00123c98

// 00123d10 (was src/anon/batch_w8.cpp)
namespace n00123d10 {
// Batch w8: small leaf / wrapper functions.

typedef void (*VFn)(void*);
void** func_00124748(void*, u32) asm("func_00124748");
/*TARGET 00123d10*/
// list_nth_node_rel
void kn__ModelMulti__getDistanceFromSkeleton(void* p) asm("kn__ModelMulti__getDistanceFromSkeleton");
// list_nth_node_rel
void kn__ModelMulti__getDistanceFromSkeleton(void* p) {
    void** o = func_00124748(p, 0);  // list_nth_node_rel
    ((VFn)(*(void***)o)[3])(o);
}
}  // namespace n00123d10

// 00123d40 (was src/anon/batch_w26.cpp)
namespace n00123d40 {
void* func_00124748(void*, s32) asm("func_00124748");
/*TARGET 00123d40*/
void kn__ModelMulti__getBoundingBox(void* a, void* b, void* c) asm("kn__ModelMulti__getBoundingBox");
void kn__ModelMulti__getBoundingBox(void* a, void* b, void* c) {
    void** o = (void**)func_00124748(a, 0);  // list_nth_node_rel
    ((void (*)(void*, void*, void*))((void**)*o)[4])(o, b, c);
}
}  // namespace n00123d40

// 00123d90 (was src/anon/batch_w13.cpp)
namespace n00123d90 {
void* func_00124748(void*, s32) asm("func_00124748");
extern void (*D_0035e380[])(void) asm("D_0035e380");
typedef s32 (*VFn2)(void*, s32);
/*TARGET 00123d90*/
s32 kn__ModelMulti__partName2matrixNo(void* a, s32 b) asm("kn__ModelMulti__partName2matrixNo");
s32 kn__ModelMulti__partName2matrixNo(void* a, s32 b) {
    void* o = func_00124748(a, 0);  // list_nth_node_rel
    return (*(VFn2*)(*(u8**)o + 24))(o, b);
}
}  // namespace n00123d90

// 00123dd0 (was src/anon/batch_w10.cpp)
namespace n00123dd0 {
void* func_00124748(void*, s32) asm("func_00124748");
/*TARGET 00123dd0*/
// 0x0011a430: definition moved into src/anon/unit_0011a260.cpp

void* kn__ModelMulti__getHrcNum(void* a) asm("kn__ModelMulti__getHrcNum");
// 0x0011a430: definition moved into src/anon/unit_0011a260.cpp

void* kn__ModelMulti__getHrcNum(void* a) {
    void* o = func_00124748(a, 0);  // list_nth_node_rel
    return (*(void* (**)(void*))(*(u8**)o + 28))(o);
}
}  // namespace n00123dd0

// 00123e00 (was src/anon/batch_w16.cpp)
namespace n00123e00 {
typedef u32 (*VFnR)(void*);
void* func_00124748(void*, u32) asm("func_00124748");
/*TARGET 00123e00*/
u32 kn__ModelMulti__getHrc(void* a) asm("kn__ModelMulti__getHrc");
u32 kn__ModelMulti__getHrc(void* a) {
    void* o = func_00124748(a, 0);  // list_nth_node_rel
    return (*(VFnR*)(*(u8**)o + 32))(o);
}
}  // namespace n00123e00

// 00123e30 (was src/anon/batch_wcx2_nsa.cpp)
namespace n00123e30 {
// 0x00193330: definition moved into src/anon/unit_00193038.cpp

struct Alloc123e30 {
    virtual u8* alloc(u32 size, void* ra);
};
struct Hdr123e30 { u8 pad[16]; u16 cnt; };
struct Mdl123e30 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual s32 parts();
    Hdr123e30* hdr;
    u8 pad[8];
    s32 n;
    s32 a[3];
    s32 b[3];
};
struct Obj123e30 {
    u8 pad0[16];
    Alloc123e30* al;
    u8 pad1[8];
    u8* p28;
    u8* p32;
    u8* p36;
    u8* p40;
    u8* p44;
    u8* p48;
    u8 pad2[260 - 52];
    u8* vis;
    u8* p264;
    u8* p268;
};
Mdl123e30* func_00124748(Mdl123e30*, s32) asm("func_00124748");
void func_0011c2d0(Obj123e30*) asm("func_0011c2d0");
u8* func_00120a20(Mdl123e30*, Obj123e30*, u8*, u8*, s32) asm("func_00120a20");
void func_0011eef8(Mdl123e30*, Obj123e30*) asm("func_0011eef8");
/*TARGET 00123e30*/
Obj123e30* func_00123e30(Mdl123e30* mdl, Alloc123e30* al) asm("func_00123e30");
Obj123e30* func_00123e30(Mdl123e30* mdl, Alloc123e30* al)
{
    s32 i = 0;
    Hdr123e30* h = func_00124748(mdl, 0)->hdr;
    u32 off = (mdl->b[mdl->n - 1] + 15) & ~15;
    Obj123e30* o = (Obj123e30*)al->alloc(304 + off + h->cnt * 48 + mdl->a[mdl->n - 1] * 2, __builtin_return_address(0));
    func_0011c2d0(o);
    o->vis = (u8*)o + 304;
    for (i = 0; i < mdl->parts(); i++) o->vis[i] = 1;
    u8* p = o->vis + off;
    o->p28 = p;
    p += h->cnt * 16;
    o->p32 = p;
    p += h->cnt * 16;
    o->p36 = p;
    u8* q = al->alloc(h->cnt * 192, __builtin_return_address(0));
    o->p40 = q;
    q += h->cnt * 64;
    o->p44 = q;
    q += h->cnt * 64;
    o->al = al;
    o->p48 = q;
    s32 tot = 0;
    for (i = 0; i < mdl->n; i++) tot += func_00124748(mdl, i)->parts();
    o->p264 = o->p36 + h->cnt * 16;
    o->p268 = o->p264 + tot * 4;
    u8* d = (u8*)(((u32)(o->p268 + tot * 4) + 15) & ~15);
    tot = 0;
    for (i = 0; i < mdl->n; i++) {
        Mdl123e30* s = func_00124748(mdl, i);
        d = func_00120a20(s, o, o->p264 + tot * 4, d, 0);
        d = func_00120a20(s, o, o->p268 + tot * 4, d, 1);
        tot += s->parts();
    }
    func_0011eef8(mdl, o);
    return o;
}
}  // namespace n00123e30

// 001240b0 (gap function, not written before)
namespace g001240b0 {
struct M;
typedef void (*Fn)(M*, u32, u32);
struct M { Fn* vt; };
M* func_00124748(void*, s32) asm("func_00124748");
void func_001240b0(void* o, u32 a, u32 b) asm("func_001240b0");
void func_001240b0(void* o, u32 a, u32 b) {
    M* m = func_00124748(o, 0);
    m->vt[10](m, a, b);
}
}  // namespace g001240b0

// 00124100 (was src/anon/batch_w14.cpp)
namespace n00124100 {
void* func_00124748(void*, s32) asm("func_00124748");
/*TARGET 00124100*/
void kn__ModelMulti__calc(void* a, s32 b) asm("kn__ModelMulti__calc");
void kn__ModelMulti__calc(void* a, s32 b) {
    void** o = (void**)func_00124748(a, 0);  // list_nth_node_rel
    (*(void (**)(void*, s32))(*(u8**)o + 44))(o, b);
}
}  // namespace n00124100

// 00124140 (was src/anon/auto80_199_queue.cpp)
namespace n00124140 {
/*TARGET 00124140*/
u32 kn__ModelMulti__getGroupNum(u8* a0) asm("_Z27kn__ModelMulti__getGroupNumPh");
u32 kn__ModelMulti__getGroupNum(u8* a0) {
    s32 s1 = 0;
    u32 s2 = 0;

    s32 t7 = *(s32*)(a0 + 0x10);
    if (t7 > 0) {
        do {
            VObj* obj = func_00124748((u32)a0, (u32)s1);  // list_nth_node_rel
            VCall48 fn = (VCall48)obj->vtbl[12];
            u32 v = fn(obj);
            s1 = s1 + 1;
            t7 = *(s32*)(a0 + 0x10);
            s2 = s2 + v;
        } while (s1 < t7);
    }

    return s2;
}
}  // namespace n00124140

// 001241b8 (was src/anon/batch_wcx.cpp)
namespace n001241b8 {
typedef void (*Fn52)(u8*, s32, u32);
u8* func_00124748(u8*, s32) asm("func_00124748");
/*TARGET 001241b8*/
// list_nth_node_rel
void kn__ModelMulti__setDisplayFlag(u8* p, s32 base, u32 c) asm("kn__ModelMulti__setDisplayFlag");
// list_nth_node_rel
void kn__ModelMulti__setDisplayFlag(u8* p, s32 base, u32 c)
{
    u8* o = func_00124748(p, 0);  // list_nth_node_rel
    (*(Fn52*)(*(u8**)o + 52))(o, base, c);
    for (s32 i = 1; i < *(s32*)(p + 16); i++) {
        o = func_00124748(p, i);  // list_nth_node_rel
        (*(Fn52*)(*(u8**)o + 52))(o, base + ((s32*)(p + 28))[i], c);
    }
}
}  // namespace n001241b8

// 00124278 (was src/anon/batch_wcx.cpp)
namespace n00124278 {
typedef void (*Fn60)(u8*, s32, u32);
u8* func_00124748(u8*, s32) asm("func_00124748");
/*TARGET 00124278*/
// list_nth_node_rel
void kn__ModelMulti__showPart(u8* p, s32 base, u32 c) asm("kn__ModelMulti__showPart");
// list_nth_node_rel
void kn__ModelMulti__showPart(u8* p, s32 base, u32 c)
{
    u8* o = func_00124748(p, 0);  // list_nth_node_rel
    (*(Fn60*)(*(u8**)o + 60))(o, base, c);
    for (s32 i = 1; i < *(s32*)(p + 16); i++) {
        o = func_00124748(p, i);  // list_nth_node_rel
        (*(Fn60*)(*(u8**)o + 60))(o, base + ((s32*)(p + 28))[i], c);
    }
}
}  // namespace n00124278

// 00124338 (was src/anon/batch_wcx.cpp)
namespace n00124338 {
typedef void (*Fn64)(u8*, s32, u32);
u8* func_00124748(u8*, s32) asm("func_00124748");
/*TARGET 00124338*/
// list_nth_node_rel
void kn__ModelMulti__hidePart(u8* p, s32 base, u32 c) asm("kn__ModelMulti__hidePart");
// list_nth_node_rel
void kn__ModelMulti__hidePart(u8* p, s32 base, u32 c)
{
    u8* o = func_00124748(p, 0);  // list_nth_node_rel
    (*(Fn64*)(*(u8**)o + 64))(o, base, c);
    for (s32 i = 1; i < *(s32*)(p + 16); i++) {
        o = func_00124748(p, i);  // list_nth_node_rel
        (*(Fn64*)(*(u8**)o + 64))(o, base + ((s32*)(p + 28))[i], c);
    }
}
}  // namespace n00124338

// 001243f8 (was src/anon/batch_wcx.cpp)
namespace n001243f8 {
typedef void (*Fn68)(u8*, s32, u32);
u8* func_00124748(u8*, s32) asm("func_00124748");
/*TARGET 001243f8*/
// list_nth_node_rel
void kn__ModelMulti__setStealth(u8* p, s32 base, u32 c) asm("kn__ModelMulti__setStealth");
// list_nth_node_rel
void kn__ModelMulti__setStealth(u8* p, s32 base, u32 c)
{
    u8* o = func_00124748(p, 0);  // list_nth_node_rel
    (*(Fn68*)(*(u8**)o + 68))(o, base, c);
    for (s32 i = 1; i < *(s32*)(p + 16); i++) {
        o = func_00124748(p, i);  // list_nth_node_rel
        (*(Fn68*)(*(u8**)o + 68))(o, base + ((s32*)(p + 28))[i], c);
    }
}
}  // namespace n001243f8

// 001244b8 (was src/anon/batch_wcx.cpp)
namespace n001244b8 {
typedef void (*Fn72)(u8*, s32, u32);
u8* func_00124748(u8*, s32) asm("func_00124748");
/*TARGET 001244b8*/
// list_nth_node_rel
void kn__ModelMulti__resetStealth(u8* p, s32 base, u32 c) asm("kn__ModelMulti__resetStealth");
// list_nth_node_rel
void kn__ModelMulti__resetStealth(u8* p, s32 base, u32 c)
{
    u8* o = func_00124748(p, 0);  // list_nth_node_rel
    (*(Fn72*)(*(u8**)o + 72))(o, base, c);
    for (s32 i = 1; i < *(s32*)(p + 16); i++) {
        o = func_00124748(p, i);  // list_nth_node_rel
        (*(Fn72*)(*(u8**)o + 72))(o, base + ((s32*)(p + 28))[i], c);
    }
}
}  // namespace n001244b8

// 00124578 (was src/anon/batch_w53.cpp)
namespace n00124578 {
typedef u32 (*Fn8)(u8*, u32, u32, u32, u32, u32, u8, u32);
u8* func_00124748(u32, u32) asm("func_00124748");
/*TARGET 00124578*/
u32 kn__ModelMulti__draw(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u8 t2, u32 t3) asm("kn__ModelMulti__draw");
u32 kn__ModelMulti__draw(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u8 t2, u32 t3) {
    u8* o = func_00124748(a0, 0);  // list_nth_node_rel
    return (*(Fn8*)(*(u8**)o + 76))(o, a1, a2, a3, t0, t1, t2, t3);
}
}  // namespace n00124578

// 00124618 (was src/anon/batch_w54.cpp)
namespace n00124618 {
typedef s32 (*VFn124)(void*, s32, s32, s32, s32, s32, u8, s32);
void* func_00124748(void*, s32) asm("func_00124748");
/*TARGET 00124618*/
// list_nth_node_rel
s32 kn__ModelMulti__drawSilhouette(void* a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, u8 t2, s32 t3) asm("kn__ModelMulti__drawSilhouette");
// list_nth_node_rel
s32 kn__ModelMulti__drawSilhouette(void* a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, u8 t2, s32 t3) {
    void* o = func_00124748(a0, 0);  // list_nth_node_rel
    return (*(VFn124*)((*(u8**)o) + 80))(o, a1, a2, a3, t0, t1, t2, t3);
}
}  // namespace n00124618

// 001246b8 (was src/anon/batch_w62.cpp)
namespace n001246b8 {
// 00108698: moved to src/anon/unit_001085a8.cpp

struct VObj1246 { u32 (**vt)(...); };
VObj1246* func_00124748(u32, u32) asm("func_00124748");
// list_nth_node_rel
typedef u32 (*Fn1246)(VObj1246*, u32, u32, u32, u32, u8, u32);
/*TARGET 001246b8*/
u32 kn__ModelMulti__drawOnShadow(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u8 t1, u32 t2) asm("kn__ModelMulti__drawOnShadow");
u32 kn__ModelMulti__drawOnShadow(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u8 t1, u32 t2) {
    VObj1246* o = func_00124748(a0, 0);  // list_nth_node_rel
    return ((Fn1246)o->vt[22])(o, a1, a2, a3, t0, t1, t2);
}
}  // namespace n001246b8

// 00124748 (was src/anon/batch_w22.cpp)
namespace n00124748 {
/*TARGET 00124748*/
// 0x00119d08: definition moved into src/anon/unit_00119bf8.cpp

// --- 00124748
u8* func_00124748(u8* a, s32 n) asm("func_00124748");
// 0x00119d08: definition moved into src/anon/unit_00119bf8.cpp

// --- 00124748
u8* func_00124748(u8* a, s32 n) {  // list_nth_node_rel
    u8* base = *(u8**)(a + 4);
    u8* r = 0;
    for (u32* q = (u32*)(base + 16); *q; q++) {
        r = base + *q;
        if (--n == -1) break;
    }
    return r;
}
}  // namespace n00124748

// 00124788 (was src/anon/batch_w57.cpp)
namespace n00124788 {
extern void (**D_0032b914)() asm("D_0032b914");
// Sum a virtual query over the objects referenced by an offset table.
u32 func_00124748(void*) asm("func_00124748");
// list_nth_node_rel
typedef s32 (*VFn124)(u8*);
/*TARGET 00124788*/
s32 func_00124788(u8* a) asm("func_00124788");
s32 func_00124788(u8* a) {
    s32 sum = 0;
    u8* end = (u8*)func_00124748(a);  // list_nth_node_rel
    u8* base = *(u8**)(a + 4);
    s32* p = (s32*)(base + 16);
    while (*p) {
        u8* o = base + *p;
        if (o == end) break;
        p++;
        sum += (*(VFn124*)((*(u8**)o) + 48))(o);
    }
    return sum;
}
}  // namespace n00124788

// 00124810 (gap function, not written before)
namespace g00124810 {
u32 func_00124810(u8* p) asm("func_00124810");
u32 func_00124810(u8* p) { return *(u32*)(p + 16); }
void func_00124818(u8* p) asm("func_00124818");
void func_00124818(u8* p) { p[24] = 0; p[25] = 0; }
}  // namespace g00124810

// 00124828 (was src/anon/tiny_auto80.cpp)
namespace n00124828 {
/*TARGET 00124828*/
void func_00124828(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00124828jjjj");
void func_00124828(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(volatile u8*)((u32)r4 + (s32)(25)) = (u8)0u;
    *(volatile u8*)((u32)r4 + (s32)(24)) = (u8)0u;
}
}  // namespace n00124828

// 00124838 (gap function, not written before)
namespace g00124838 {
void func_00124838(void) asm("func_00124838");
void func_00124838(void) {}
}  // namespace g00124838

// 00124840 (was src/anon/misc_1.cpp)
namespace n00124840 {
/*TARGET 00124840*/
void func_00124840(void* self) asm("_Z13func_00124840Pv");
void func_00124840(void* self) {}
}  // namespace n00124840

// 00124848 (was src/anon/batch_w1985_nsa.cpp)
namespace n00124848 {
struct W1985Mtx {
    f32 m[4][4];
    W1985Mtx() {}
    W1985Mtx(const W1985Mtx& o)
    {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W1985Mtx& operator=(const W1985Mtx& o)
    {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline W1985Mtx W1985Mul(const W1985Mtx& l, const W1985Mtx& r)
{
    W1985Mtx d;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                 : : "r"(&d), "r"(&l), "r"(&r) : "memory");
    return d;
}
struct W1985Bone { u32 f0; s16 parent; s16 f6; u64 flags; u8 pad[48]; };
struct W1985SkelVt { void* f[8]; W1985Bone* (*bones)(void*); };
struct W1985Skel { W1985SkelVt* vt; };
struct W1985Bones { u32 f0; W1985Mtx* mats; u8 pad[12]; W1985Skel* skel; };
/*TARGET 00124848*/
void func_00124848(W1985Bones* self, s32 idx, W1985Mtx* out) asm("func_00124848");
void func_00124848(W1985Bones* self, s32 idx, W1985Mtx* out)
{
    W1985Bone* b = self->skel->vt->bones(self->skel);
    if (b[idx].parent >= 0 && (b[b[idx].parent].flags & 0x100000000ULL)) {
        W1985Mtx m(self->mats[idx]);
        s32 p;
        for (p = b[idx].parent; p >= 0 && (b[p].flags & 0x100000000ULL); p = b[p].parent)
            m = W1985Mul(self->mats[p], m);
        *out = m;
    } else {
        *out = self->mats[idx];
    }
}
}  // namespace n00124848

// 00124a40 (was src/anon/batch_w77.cpp)
namespace n00124a40 {
struct VObj;
typedef u8* (*GetFn)(VObj*);
typedef s32 (*CountFn)(VObj*);
struct VObj { void** vt; };
void func_00124848(u8*, s32, u32) asm("func_00124848");
/*TARGET 00124a40*/
void func_00124a40(u8* p) asm("func_00124a40");
void func_00124a40(u8* p)
{
    if (p[25]) return;
    VObj* o = *(VObj**)(p + 20);
    u8* arr = ((GetFn)o->vt[8])(o);
    s32 i = 0;
    o = *(VObj**)(p + 20);
    s32 n = ((CountFn)o->vt[7])(o);
    for (; i < n; i++) {
        if (!(*(u64*)(arr + i * 64 + 8) & (1ULL << 32)))
            func_00124848(p, i, *(u32*)(p + 4) + i * 64);
    }
    p[25] = 1;
}
}  // namespace n00124a40

// 00124b10 (was src/anon/batch_w67.cpp)
namespace n00124b10 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPYN(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
// 16-byte aligned vector: copy-construct = quadword copy, assignment skips self.
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& o) { QCOPYN(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Mtx {
    Vec4 r[4];
    Mtx() {}
    Mtx& operator=(const Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
/*TARGET 00124b10*/
// 0x0010c940: definition moved into src/anon/unit_0010b978.cpp

// 00124b10: obj->matrix = m * obj->matrix (VU0)
void func_00124b10(u8* p, Mtx* m) asm("func_00124b10");
// 0x0010c940: definition moved into src/anon/unit_0010b978.cpp

// 00124b10: obj->matrix = m * obj->matrix (VU0)
void func_00124b10(u8* p, Mtx* m)
{
    Mtx* d = *(Mtx**)(p + 4);
    Mtx t;
    asm volatile(".set noreorder\n\t"
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
        "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
        "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
        : : "r"(&t), "r"(m), "r"(d) : "memory");
    *d = t;
}
}  // namespace n00124b10

// 00124bb8 (was src/anon/tiny_auto80_solver.cpp)
namespace n00124bb8 {
// list_nth_node_rel
void func_00124bb8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00124bb8jjjjjjjj");
extern u8 D_00347b88 asm("D_00347b88");
/*TARGET 00124bb8*/
void func_00124bb8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00124bb8jjjjjjjj");
void func_00124bb8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // obj_ctor_347b88
    u32 r4 = a0, r5 = a1, r15;
    r15 = (u32)&D_00347b88;
    *(u32*)(r4 + 4) = r5;
    *(u32*)(r4 + 20) = 0u;
    *(volatile u32*)(r4 + 0) = r15;
    *(volatile u32*)(r4 + 8) = 0u;
    *(volatile u32*)(r4 + 12) = 0u;
    *(volatile u32*)(r4 + 16) = 0u;
}
}  // namespace n00124bb8

// 00124be0 (gap function, not written before)
namespace g00124be0 {
extern u8 D_00347b88 asm("D_00347b88");
// C1 copy of the ctor at 0x124bb8.
void func_00124be0(u32 a0, u32 a1) asm("func_00124be0");
void func_00124be0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r15;
    r15 = (u32)&D_00347b88;
    *(u32*)(r4 + 4) = r5;
    *(u32*)(r4 + 20) = 0u;
    *(volatile u32*)(r4 + 0) = r15;
    *(volatile u32*)(r4 + 8) = 0u;
    *(volatile u32*)(r4 + 12) = 0u;
    *(volatile u32*)(r4 + 16) = 0u;
}
}  // namespace g00124be0

// 00124c08 (was src/anon/tiny.cpp)
namespace n00124c08 {
extern u32 D_00347b88 asm("D_00347b88");
/*TARGET 00124c08*/
void func_00124c08(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00124c08jjjj");
void func_00124c08(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_347b88
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00347b88;
}
}  // namespace n00124c08

// 00124c18 (gap function, not written before)
namespace g00124c18 {
extern u32 D_00347b88 asm("D_00347b88");
void func_00124c18(u32 a0) asm("func_00124c18");
void func_00124c18(u32 a0) {
    *(u32*)((u32)a0 + (0)) = (u32)&D_00347b88;
}
}  // namespace g00124c18

// 00124c28 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n00124c28 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_00347b88 asm("D_00347b88");
/*TARGET 00124c28*/
u32 func_00124c28(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00124c28jjjjjjjj");
u32 func_00124c28(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00347b88;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n00124c28

// 00124c48 (was src/anon/batch_w3702.cpp)
namespace n00124c48 {
/* 00124c48: walk a table of variable-length entries (id, count, then count 16-byte items)
   ending at id -1; return the entry whose id matches, or 0.
   Partial asm: register pins (h/nx in t6, cur in t4, it in t5) reproduce the original's
   allocation (cur kept apart from the reloaded id, copied with move t4,t6). */
typedef struct Hdr00124c48 { u32 x0; u32 x4; s32 off; s32 cnt; } Hdr00124c48;
typedef struct Item00124c48 { u32 a, b, c, d; } Item00124c48;
typedef struct Ent00124c48 { s32 id; s32 n; u32 x8, xc; } Ent00124c48;
typedef struct Obj00124c48 { u32 x0; Hdr00124c48* h; } Obj00124c48;
/*TARGET 00124c48*/
Ent00124c48* func_00124c48(Obj00124c48* o, s32 id) asm("func_00124c48");
Ent00124c48* func_00124c48(Obj00124c48* o, s32 id) {
    register Hdr00124c48* h asm("$14") = o->h;
    Ent00124c48* e = h->cnt ? (Ent00124c48*)((u8*)h + h->off) : 0;
    if (e) {
        register s32 cur asm("$12") = e->id;
        if (cur != -1) {
            for (;;) {
                register Item00124c48* it asm("$13") = (Item00124c48*)(e + 1);
                if (cur == id) return e;
                e = (Ent00124c48*)(it + e->n);
                register s32 nx asm("$14") = e->id;
                if (nx == -1) break;
                cur = nx;
            }
        }
    }
    return 0;
}
}  // namespace n00124c48

// 00124ca8 (was src/anon/batch_w3847_nsa.cpp)
namespace n00124ca8 {
struct V124 {
    f32 x, y, z, w;
    V124() {}
    V124(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V124& operator=(const V124& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V124 operator-(const V124& b) const
    {
        V124 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V124 operator^(const V124& b) const
    {
        V124 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct M124 {
    V124 r[4];
    M124() {}
    void set(const V124& a, const V124& b, const V124& c) { r[0] = a; r[1] = b; r[2] = c; r[3].unit(); }
    M124& operator=(const M124& o) {
        if (this != &o)
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    M124 operator*(const M124& b) const {
        M124 o;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
void func_0011b6a8(M124*) asm("func_0011b6a8");
M124* func_0011b6d8(M124*, f32) asm("func_0011b6d8");
/*TARGET 00124ca8*/
// 00124ca8: look-at view matrix (eye, target, optional up, roll); with proj, also a 2D correction from the triangle a, b, |target-eye|
void gm__GRID__draw(V124* eye, V124* tgt, s32 flip, M124* out, M124* proj, V124* upv, f32 a, f32 b, f32 roll, f32 roll2) asm("gm__GRID__draw");
// 00124ca8: look-at view matrix (eye, target, optional up, roll); with proj, also a 2D correction from the triangle a, b, |target-eye|
void gm__GRID__draw(V124* eye, V124* tgt, s32 flip, M124* out, M124* proj, V124* upv, f32 a, f32 b, f32 roll, f32 roll2)
{
    V124 fwd(0.0f, 0.0f, 0.0f, 0.0f), up(0.0f, 0.0f, 0.0f, 0.0f), side(0.0f, 0.0f, 0.0f, 0.0f);
    M124 view, rot, m2;
    V124* pu = &up;
    V124* ps = &side;
    fwd = *tgt - *eye;
    f32 len = fwd.normalize();
    if (upv) {
        (*pu) = *upv - *eye;
        pu->normalize();
        (*ps) = fwd ^ (*pu);
        ps->normalize();
        (*pu) = (*ps) ^ fwd;
        pu->normalize();
    } else {
        pu->x = -fwd.y;
        pu->y = fwd.x;
        pu->z = 0.0f;
        pu->normalize();
        (*ps) = fwd ^ (*pu);
        ps->normalize();
    }
    view.set(fwd, (*pu), (*ps));
    if (roll != 0.0f) {
        func_0011b6a8(&rot);
        func_0011b6d8(&rot, roll);
        view = view * rot;
    }
    if (!proj) {
        *out = view;
        return;
    }
    f32 c = (len * len - a * a - b * b) / (2.0f * a * b);
    if (c > 1.0f) c = 1.0f;
    else if (c < -1.0f) c = -1.0f;
    f32 s = 1.0f - c * c;
    if (s < 0.0f) s = 0.0f;
    if (flip) s = -__builtin_sqrtf(s);
    else s = __builtin_sqrtf(s);
    proj->r[0].x = c;
    proj->r[0].y = s;
    proj->r[0].z = 0.0f;
    proj->r[0].w = 0.0f;
    proj->r[1].x = -s;
    proj->r[1].y = c;
    proj->r[1].z = 0.0f;
    proj->r[1].w = 0.0f;
    proj->r[2].x = 0.0f;
    proj->r[2].y = 0.0f;
    proj->r[2].z = 1.0f;
    proj->r[2].w = 0.0f;
    proj->r[3].x = 0.0f;
    proj->r[3].y = 0.0f;
    proj->r[3].z = 0.0f;
    proj->r[3].w = 1.0f;
    if (roll2 != 0.0f) {
        func_0011b6a8(&rot);
        func_0011b6d8(&rot, roll2);
        *proj = *proj * rot;
    }
    f32 x = (a + b * c) * len;
    f32 y = -(b * s) * len;
    f32 n = __builtin_sqrtf(x * x + y * y);
    x /= n;
    y /= n;
    m2.r[0].x = x;
    m2.r[0].y = y;
    m2.r[0].z = 0.0f;
    m2.r[0].w = 0.0f;
    m2.r[1].x = -y;
    m2.r[1].y = x;
    m2.r[1].z = 0.0f;
    m2.r[1].w = 0.0f;
    m2.r[2].x = 0.0f;
    m2.r[2].y = 0.0f;
    m2.r[2].z = 1.0f;
    m2.r[2].w = 0.0f;
    m2.r[3].x = 0.0f;
    m2.r[3].y = 0.0f;
    m2.r[3].z = 0.0f;
    m2.r[3].w = 1.0f;
    *out = view * m2;
}
}  // namespace n00124ca8

// 001253c0 (was src/anon/batch_wcx2_nsa.cpp)
namespace n001253c0 {
struct V1253c0 {
    f32 x, y, z, w;
    V1253c0& operator=(const V1253c0& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M1253c0 {
    V1253c0 r[4];
    M1253c0& operator=(const M1253c0& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    M1253c0 operator*(const M1253c0& b) const {
        M1253c0 o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
    V1253c0 operator*(const V1253c0& v) const {
        V1253c0 o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    void scale(const V1253c0& s) {
        asm volatile("lqc2 $vf4, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tvmulx.wxyz $vf1, $vf1, $vf4x\n\tvmuly.wxyz $vf2, $vf2, $vf4y\n\tvmulz.wxyz $vf3, $vf3, $vf4z\n\tsqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)" : : "r"(this), "r"(&s) : "memory");
    }
} __attribute__((aligned(16)));
struct Bone1253c0 { u8 pad0[2]; s16 sibling; s16 parent; s16 child; u32 w8; u32 hasParent : 1; u32 rest : 31; u8 pad[48]; } __attribute__((aligned(16)));
struct Skel1253c0 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6();
    virtual s32 count();
    virtual Bone1253c0* bones();
};
struct Self1253c0 { u8 pad0[20]; Skel1253c0* skel; u8 pad1[16]; M1253c0* local; M1253c0* world; };
extern M1253c0 D_003a99f0[] asm("D_003a99f0");
s32 func_0011f270(Skel1253c0*, s32) asm("func_0011f270");
/*TARGET 001253c0*/
void func_001253c0(Self1253c0* s, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 idx, f32 f) asm("func_001253c0");
void func_001253c0(Self1253c0* s, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 idx, f32 f)
{
    Bone1253c0* bones = s->skel->bones();
    M1253c0* mats = D_003a99f0;
    V1253c0* scales = (V1253c0*)&mats[s->skel->count()];
    while (idx >= 0) {
        V1253c0 t;
        s32 parent;
        if (!bones[idx].hasParent) parent = func_0011f270(s->skel, idx);
        else parent = bones[idx].parent;
        if (parent < 0) {
            mats[idx] = s->local[idx];
            t = s->local[idx].r[3];
        } else {
            mats[idx] = mats[parent] * s->local[idx];
            t = s->world[parent] * s->local[idx].r[3];
        }
        s->world[idx] = mats[idx];
        s->world[idx].scale(scales[idx]);
        s->world[idx].r[3] = t;
        if (bones[idx].child >= 0) func_001253c0(s, a1, a2, a3, a4, a5, bones[idx].child, f);
        idx = bones[idx].sibling;
    }
}
}  // namespace n001253c0

// 001256c0 (was src/anon/batch_w285.cpp)
namespace n001256c0 {
static inline void vlerp(f32* d, f32* a, f32* b, f32 t) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b), "f"(t) : "$8", "memory");
}
static inline void vnorm(f32* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\t.set noreorder\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(v) : "$8", "memory");
}
static inline void vouter(f32* d, f32* a, f32* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
/*TARGET 001256c0*/
void func_001256c0(f32 (*d)[4], f32 (*a)[4], f32 (*b)[4], f32 t) asm("func_001256c0");
void func_001256c0(f32 (*d)[4], f32 (*a)[4], f32 (*b)[4], f32 t) {
    vlerp(d[3], a[3], b[3], t);
    vlerp(d[0], a[0], b[0], t);
    vnorm(d[0]);
    vlerp(d[1], a[1], b[1], t);
    vnorm(d[1]);
    vouter(d[2], d[0], d[1]);
    vnorm(d[2]);
    vouter(d[1], d[2], d[0]);
    vnorm(d[1]);
}
}  // namespace n001256c0

// 00125860 (was src/anon/batch_wcx2.cpp)
namespace n00125860 {
struct VA14;
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
struct V125860 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M125860 { V125860 r[4]; };
static inline void lerp125860(V125860* d, const V125860* a, const V125860* b, f32 t)
{
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(a), "r"(b), "f"(t) : "$8", "memory");
}
static inline f32 dot125860(const V125860* a, const V125860* b)
{
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(a), "r"(b) : "$8");
    return r;
}
static inline f32 norm125860(V125860* v)
{
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline void cross125860(V125860* d, const V125860* a, const V125860* b)
{
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
/*TARGET 00125860*/
void func_00125860(M125860* d, const M125860* a, const M125860* b, f32 t) asm("func_00125860");
void func_00125860(M125860* d, const M125860* a, const M125860* b, f32 t)
{
    lerp125860(&d->r[3], &a->r[3], &b->r[3], t);
    f32 d0 = dot125860(&a->r[0], &b->r[0]);
    f32 d1 = dot125860(&a->r[1], &b->r[1]);
    f32 d2 = dot125860(&a->r[2], &b->r[2]);
    if (d1 <= d0 && d2 <= d0) {
        lerp125860(&d->r[0], &a->r[0], &b->r[0], t);
        norm125860(&d->r[0]);
        if (d2 <= d1) {
            lerp125860(&d->r[1], &a->r[1], &b->r[1], t);
            norm125860(&d->r[1]);
            cross125860(&d->r[2], &d->r[0], &d->r[1]);
            norm125860(&d->r[2]);
            cross125860(&d->r[1], &d->r[2], &d->r[0]);
            norm125860(&d->r[1]);
        } else {
            lerp125860(&d->r[2], &a->r[2], &b->r[2], t);
            norm125860(&d->r[2]);
            cross125860(&d->r[1], &d->r[2], &d->r[0]);
            norm125860(&d->r[1]);
            cross125860(&d->r[2], &d->r[0], &d->r[1]);
            norm125860(&d->r[2]);
        }
    } else if (d2 <= d1 && d0 <= d1) {
        lerp125860(&d->r[1], &a->r[1], &b->r[1], t);
        norm125860(&d->r[1]);
        if (d2 <= d0) {
            lerp125860(&d->r[0], &a->r[0], &b->r[0], t);
            norm125860(&d->r[0]);
            cross125860(&d->r[2], &d->r[0], &d->r[1]);
            norm125860(&d->r[2]);
            cross125860(&d->r[0], &d->r[1], &d->r[2]);
            norm125860(&d->r[0]);
        } else {
            lerp125860(&d->r[2], &a->r[2], &b->r[2], t);
            norm125860(&d->r[2]);
            cross125860(&d->r[0], &d->r[1], &d->r[2]);
            norm125860(&d->r[0]);
            cross125860(&d->r[2], &d->r[0], &d->r[1]);
            norm125860(&d->r[2]);
        }
    } else {
        lerp125860(&d->r[2], &a->r[2], &b->r[2], t);
        norm125860(&d->r[2]);
        if (d1 <= d0) {
            lerp125860(&d->r[0], &a->r[0], &b->r[0], t);
            norm125860(&d->r[0]);
            cross125860(&d->r[1], &d->r[2], &d->r[0]);
            norm125860(&d->r[1]);
            cross125860(&d->r[0], &d->r[1], &d->r[2]);
            norm125860(&d->r[0]);
        } else {
            lerp125860(&d->r[1], &a->r[1], &b->r[1], t);
            norm125860(&d->r[1]);
            cross125860(&d->r[0], &d->r[1], &d->r[2]);
            norm125860(&d->r[0]);
            cross125860(&d->r[1], &d->r[2], &d->r[0]);
            norm125860(&d->r[1]);
        }
    }
}
}  // namespace n00125860

