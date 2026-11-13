#include "../../common/types.h"

// YS::MOTION, first part (0x17eb68-0x180378): motion playback of an object (the motion set, the
// request queue, anmatr triggers). The file begins with the MOTION constructor pair at 0x17e858 (C2,
// inlines the member ctor) / 0x17e9d0 (C1, calls the linkonce 0x31cc28), which stays outside. The
// capture helper 0x180378 matches only with strict aliasing (this part needs -fno-strict-aliasing),
// so it stays a separate function and the file goes on in src/anon/unit_00180408.cpp.
// Each function keeps the declarations of the source it was matched in (namespace gN); every symbol
// is bound by asm label.

// ---- .data (0x34ec60)
extern "C" {
s32 D_0034ec60 = -1;
}

// 0017eb68 (src/anon/batch_w7.cpp)
namespace g1 {
void func_00180ce0(u32) asm("func_00180ce0");
u8 func_0017ee68(u32) asm("func_0017ee68");

u32 func_0017eb68(u32 a0) {
    func_00180ce0(a0);
    return func_0017ee68(a0);
}
}  // namespace g1

// 0017eb98 (src/anon/batch_w8.cpp)
namespace g2 {
typedef void (*VFn)(void*);
typedef void (*VF3)(void*, u32, u32);
typedef u32 (*VR3)(void*, u32, u32);
void func_00180ce0(void*) asm("func_00180ce0");
u8 func_0017ee68(void*) asm("func_0017ee68");

u32 func_0017eb98(void* p) {
    func_00180ce0(p);
    return func_0017ee68(p);
}
}  // namespace g2

// 0017ebc8 (src/anon/tiny_auto80_fptr4.cpp)
namespace g3 {
u32 func_001a9780(u32, u32, u32, u32) asm("func_001a9780");

u32 func_0017ebc8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = *(u32*)((u32)r4 + (s32)(0));
    u32 (*fp_call4_001a9780)(u32, u32, u32, u32) = func_001a9780;
    r2 = fp_call4_001a9780(r4, r5, r6, r7);
    return r2;
}
}  // namespace g3

// 0017ebe8 (src/anon/misc_1.cpp)
namespace g4 {

void func_0017ebe8(void* self, s32 v) { *(s32*)((char*)self + 0) = v; }
}  // namespace g4

// 0017ebf0 (src/anon/tiny_auto80_queue.cpp)
namespace g5 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);
extern "C" u32 func_00170950(...) asm("func_00170950");

void func_0017ebf0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(0));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00170950)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(volatile u32*)((u32)r16 + (s32)(0)) = 0u;
    }
}
}  // namespace g5

// 0017ec28 (src/anon/batch_w1664.cpp)
namespace g6 {

void wtarget_0017ec28(u32, u32, u32, u32) asm("_Z16wtarget_0017ec28jjjj");
void wtarget_0017ec28(u32 a0, u32 a1, u32, u32) { *(u32*)(a0 + 4) = a1; }
}  // namespace g6

// 0017ec30 (src/anon/tiny_auto80_queue.cpp)
namespace g7 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);
extern "C" u32 func_00168b38(...) asm("func_00168b38");  // entry_array_find_nth
extern "C" u32 func_0017ec98(...) asm("func_0017ec98");
extern "C" u32 func_0017ec28(...) asm("func_0017ec28");
extern "C" u32 func_001a97b8(...) asm("func_001a97b8");

void func_0017ec30(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_0017ec98(a0);
    v0 = func_001a97b8(*(u32*)((u32)s0 + (s32)(0)), v0);
    a0 = s0;
    if (v0 != 0u) {
        func_0017ec28(a0, v0);
        return;
    }
}
}  // namespace g7

// 0017ec80 (src/anon/tiny_wrappers_more.cpp)
namespace g8 {
u32 func_0017ec28(u32, u32, u32, u32) asm("func_0017ec28");

u32 func_0017ec80(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0017ec28(a0, 0x00000000u, a2, a3);
}
}  // namespace g8

// 0017ec98 (src/anon/perm_0017ec98.cpp)
namespace g9 {
struct Chr
{
  u8 pad[0x588];
  u32 flags;
};
struct Obj
{
  void *a;
  void *b;
  Chr *c;
};
extern u8 D_0036c5e0[][4] asm("D_0036c5e0");
s32 func_0017ebc8(Obj *) asm("func_0017ebc8");
s32 func_0019bf00(Chr *) asm("func_0019bf00");
s32 func_00176258(Chr *) asm("func_00176258");
s32 func_001a97b8(void *, s32) asm("_ZNK2YS9MOTIONSET9is_playerEv");
s32 func_0017ec98(Obj *o, s32 id) asm("func_0017ec98");
s32 func_0017ec98(Obj *o, s32 id)
{
  u8 new_var3;
  int new_var;
  char new_var2;
  if (!o->a)
  {
    return -1;
  }
  if (func_0017ebc8(o))
  {
    id *= 4;
    s32 k = 1;
    if (!func_0019bf00(o->c))
    {
      new_var = 2;
      k = new_var;
    }
    Chr *c = o->c;
    new_var2 = 4;
    if (c->flags & new_var2)
    {
      if (func_00176258(c))
      {
        k ^= 1;
      }
    }
    s32 i;
    for (i = 0; i < new_var2; i++)
    {
      s32 v;
      new_var3 = D_0036c5e0[k][i];
      if (o->b && func_001a97b8(o->b, id + new_var3))
      {
        return id + new_var3;
      }
      if (func_001a97b8(o->a, id + new_var3))
      {
        return id + new_var3;
      }
    }

    return i = -1;
  }
  return id;
}
}  // namespace g9

// 0017eda8 (src/anon/tiny_auto80_queue.cpp)
namespace g10 {
typedef u32  (*Fn_002cf1b8)(u32, u32);
extern "C" u32 func_0017ebc8(...) asm("func_0017ebc8");

u32 func_0017eda8(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 v0 = func_0017ebc8(a0, a1);
    u32 t6 = 0u;
    if ((s32)s0 < 0) {
        t6 = 1u;
    }
    u32 t7 = (u32)((s32)s0 + 3);
    if (t6 == 0u) {
        t7 = s0;
    }
    t6 = (u32)-1;
    if (v0 != 0u) {
        t7 = (u32)((s32)t7 >> 2);
        t7 = (u32)(t7 << 2);
        t6 = (u32)((s32)s0 - (s32)t7);
    }
    return t6;
}
}  // namespace g10

// 0017edf0 (src/anon/batch_w45.cpp)
namespace g11 {
u32 func_001a97b8(u32, s32) asm("func_001a97b8");

u32 func_0017edf0(u32* a0, s32 a1) {
    if (a1 < 0 || a0[0] == 0) return 0;
    if (a0[1]) {
        u32 r = func_001a97b8(a0[1], a1);
        if (r) return r;
    }
    return func_001a97b8(a0[0], a1);
}
}  // namespace g11

// 0017ee68 (src/anon/batch_w57.cpp)
namespace g12 {
extern void (**D_0032b914)();
void* func_001050c8(void) asm("func_001050c8");
void func_00127c70(u32, void*, u32) asm("func_00127c70");

void func_0017ee68(u8* t) {
    u32 s = *(u32*)(*(u8**)(t + 8) + 1648);
    if (*(u32*)(t + 208)) {
        func_00127c70(s, func_001050c8(), *(u32*)(t + 208));
        *(u32*)(t + 208) = 0;
    }
    if (*(u32*)(t + 212)) {
        func_00127c70(s, func_001050c8(), *(u32*)(t + 212));
        *(u32*)(t + 212) = 0;
    }
}
}  // namespace g12

// 0017eee8 (src/anon/batch_w1791_nsa.cpp)
namespace g13 {
struct Bx;
struct BxVt { void* f[5]; void (*get)(Bx*, f32*, f32*); };
struct Bx { BxVt* vt; };
struct Ob {
    u8 pad0[0xc];
    Bx* box;
    u8 pad10[0x20];
    f32 f30;
    f32 f34;
    f32 f38;
    u8 pad3c[0xd8 - 0x3c];
    f32 mn[3];
    f32 mx[3];
};

void func_0017eee8(Ob* o, f32 a, f32 b) {
    f32 lo[4];
    f32 hi[4];
    f32* ph = hi;
    s32 i;
    o->f34 = a;
    o->f38 = b;
    o->f30 = 2.0f;
    o->box->vt->get(o->box, lo, ph);
    f32* mn = o->mn; f32* mx = o->mx;
    for (i = 0; i < 3; i++) { s32 k = i * 4; if (*(f32*)((u8*)mn + k) > *(f32*)((u8*)lo + k)) *(f32*)((u8*)mn + k) = *(f32*)((u8*)lo + k);
      if (*(f32*)((u8*)ph + k) > *(f32*)((u8*)mx + k)) *(f32*)((u8*)mx + k) = *(f32*)((u8*)ph + k); }
}
}  // namespace g13

// 0017efa0 (src/anon/batch_w1964_nsa.cpp)
namespace g14 {
struct VtM { u8 p[8]; s32 (*get)(void*); };
struct M6 { VtM* vt; };
struct R6 { u8 p[8]; M6* m; };
struct Q6 { u8 p[8]; s32 v; };
struct C6 { u8 p[0x10c]; u32 f10c; };
struct O6 {
    u8 p0[8];
    C6* p8;       // 8
    M6* fc;       // c
    s32 f10;      // 10
    s32 f14, f18; // 14, 18
    u8 p1c[4];
    u32 f20;      // 20
    u32 f24;      // 24
    u8 p28[4];
    f32 f2c;      // 2c
    f32 f30;      // 30
    s32 f34;      // 34
    u8 p38[0x104 - 0x38];
    u32 f104;     // 104
    u8 p108[0x148 - 0x108];
    s32* ref;     // 148
    u8 p14c[0x194 - 0x14c];
    s32 f194;     // 194
};
s32 func_0019c6f0(C6*) asm("func_0019c6f0");
void func_001d7a50(void*) asm("func_001d7a50");
void func_00180ce0(O6*) asm("func_00180ce0");
void func_00189258(O6*) asm("func_00189258");
R6* func_00168b38(void*, s32, s32) asm("func_00168b38");
void func_00180800(O6*, s32) asm("func_00180800");
void func_001807d0(O6*, f32) asm("func_001807d0");
void func_0017eee8(O6*, f32, f32) asm("func_0017eee8");
void func_0017f938(O6*) asm("func_0017f938");
void func_001807a0(O6*, f32, f32) asm("func_001807a0");

s32 func_0017efa0(O6* o, void* r, f32 a, f32 b) {
    if (func_0019c6f0(o->p8)) func_001d7a50((u8*)o->p8 + 0x518);
    if (o->ref) {
        (*o->ref)--;
        o->ref = 0;
    }
    func_00180ce0(o);
    func_00189258(o);
    if (!r) {
        o->fc = 0;
        return 0;
    }
    R6* s = func_00168b38(r, 9, 0);
    o->f14 = -1;
    o->f18 = -1;
    func_00180800(o, -1);
    o->p8->f10c &= ~1;
    o->fc = s->m;
    o->f2c = (f32)o->fc->vt->get(o->fc);
    s = func_00168b38(r, 16, 0);
    o->f10 = ((Q6*)s)->v;
    u32 m = o->f20 & 0x80;
    s32 had = m != 0;
    o->f20 = 1;
    o->f194 = 0;
    u32 f = o->f24;
    o->f24 = 0;
    if (f & 4) o->f20 = 0x4001;
    func_001807d0(o, b);
    if (2.0f < a && (o->f104 & 1) == 1) {
        func_0017eee8(o, a, b);
    } else {
        o->f30 = b;
        o->f34 = 0;
        func_001807a0(o, b, -1.0f);
    }
    o->f20 |= 0x2000;
    if (had) func_0017f938(o);
    return 1;
}
}  // namespace g14

// 0017f178 (src/anon/batch_w77.cpp)
namespace g15 {
struct VObj;
typedef s32 (*CountFn)(VObj*);
struct VObj { void** vt; };
typedef void (*VFn)(void*);
typedef void (*RelFn)(VObj*, u32);
struct Nd { u32 h; u32 f4; u32 f8; u8 p12[12]; u32 f24; u8 p28[120]; Nd* child; u8 p152[4]; Nd* next; u8 p160[80]; u32 f240; u8 p244[8]; u32 f252; u32 f256; };
s32 func_001a9798(u32) asm("func_001a9798");
u32 func_0017edf0(Nd*, u32) asm("func_0017edf0");
s32 func_0017efa0(Nd*, u32, f32, f32) asm("func_0017efa0");
u32 func_0017eda8(Nd*, u32) asm("func_0017eda8");
void func_00180800(Nd*, u32) asm("func_00180800");
s32 func_0017f178(Nd* p, u32 a, f32 x, f32 y) asm("func_0017f178");
static inline Nd* Next(Nd* p, Nd* c)
{
    if (!c) return p->child;
    return c->next;
}

s32 func_0017f178(Nd* p, u32 a, f32 x, f32 y)
{
    if (func_001a9798(p->h)) x = 0.0f;
    p->f252 = 0;
    p->f256 = 0;
    p->f240 = p->f8 + 128;
    if (!func_0017efa0(p, func_0017edf0(p, a), x, y)) return 0;
    p->f24 = a;
    func_00180800(p, func_0017eda8(p, a));
    Nd* c = 0;
    while ((c = Next(p, c))) func_0017f178(c, a, x, y);
    return 1;
}
}  // namespace g15

// 0017f268 (src/anon/batch_w256.cpp)
namespace g16 {
struct M256 { u8 pad[20]; s32 i20; s32 i24; u32 i28; };
s32 func_0017ec98(M256*, s32) asm("func_0017ec98");
s32 func_0017ebc8(M256*) asm("func_0017ebc8");
s32 func_0017f178(M256*, s32, f32, f32) asm("func_0017f178");
u32 mo_start_num_w256(M256*, s32) asm("_ZN2YS6MOTION9start_numEiff");
s32 mo_is_exist_w256(M256*, s32) asm("_ZN2YS6MOTION8is_existEi");
s32 mo_push_w256(M256*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");

s32 func_0017f268(M256* m, s32 a1, f32 x, f32 y) {
  s32 k = func_0017ec98(m, a1);
  if (func_0017ebc8(m) && !a1) {
    u32 v = mo_start_num_w256(m, k);
    u32 t = m->i28;
    if ((t < 2 && v - 2 < 2) || (t - 2 < 2 && v < 2)) {
      if (mo_is_exist_w256(m, 6)) {
        func_0017f268(m, 6, 0.0f, 0.0f);
        mo_push_w256(m, 0, 0.0f, 0.0f, 0);
        goto one;
      }
    }
  }
  if (!func_0017f178(m, k, x, y)) return 0;
  m->i20 = a1;
one:
  return 1;
}
}  // namespace g16

// 0017f380 (src/anon/batch_w33.cpp)
namespace g17 {
struct Node17f { u8 pad[60]; s32 a; s32 b; u8 pad2[148 - 68]; Node17f* child; u8 pad3[4]; Node17f* next; };

// Clear two fields on a node and, recursively, on all its children.
void func_0017f380(Node17f* n) {  // obj_walk_children
    n->a = 0;
    n->b = 0;
    Node17f* c = 0;
    while ((c = !c ? n->child : c->next) != 0) func_0017f380(c);  // obj_walk_children
}
}  // namespace g17

// 0017f3d8 (src/anon/batch_w1752_nsa.cpp)
namespace g18 {
struct W1752Ent { u32 a; f32 x; f32 y; s32 z; u32 w; };
struct W1752Ring { s32 idx; u32 pad; W1752Ent e[4]; };
struct W1752Q { u8 pad[0x3c]; W1752Ring r; };

W1752Ent* w1752_wt_0017f3d8(W1752Q* q, u32 a, f32 x, f32 y, s32 z) asm("_Z16wtarget_0017f3d8jjjj");
W1752Ent* w1752_wt_0017f3d8(W1752Q* q, u32 a, f32 x, f32 y, s32 z) {
    W1752Ring* r = &q->r;
    s32 n = r->idx;
    r->idx = (n + 1) % 4;
    W1752Ent* e = &r->e[n];
    e->x = x; e->y = y; e->z = z;
    r->e[n].a = a;
    r->e[n].w = 0;
    return e;
}
}  // namespace g18

// 0017f430 (src/anon/auto80_199_queue.cpp)
namespace g19 {
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
void func_0017f380(u32) asm("func_0017f380");
void func_0017efa0(u32, u32, f32, f32) asm("func_0017efa0");
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

void func_0017f430(u32 a0, u32 a1, f32 a2, f32 a3) {
    f32 f21 = a2;
    f32 f20 = a3;
    u32 s0 = a0;
    u32 s1 = a1;

    func_0017f380(s0);  // obj_walk_children
    func_0017efa0(s0, s1, f21, f20);
}
}  // namespace g19

// 0017f488 (src/anon/batch_w34.cpp)
namespace g20 {
void u_tail0_0014d008(void) asm("_Z16u_tail0_0014d008v");
void f17f488(s32, s32, f32, f32) asm("_Z13func_0017f488iiff");
void MISSION_Activate2d(void*) asm("_ZN2YS7MISSION10Activate2dEv");
void EFFECT_kill(void*) asm("_ZN3ryj6EFFECT4killEv");
u32 wtarget_002342f0(u32, u32, u32, u32) asm("_Z16wtarget_002342f0jjjj");
void Layout_setNum(void*, s32, s32) asm("_ZN2Tz6Layout6setNumEii");
void u_tail4_002e2d88(u32, u32, u32, u32) asm("_Z16u_tail4_002e2d88jjjj");
void func_0014cfc8(void) asm("func_0014cfc8");
void func_0014c908(void) asm("func_0014c908");
void sceGsSyncVCallback(void*) asm("sceGsSyncVCallback");
void func_0014d308(void) asm("func_0014d308");
void func_0014cf18(void) asm("func_0014cf18");
void func_0014cf88(void) asm("func_0014cf88");
void func_00102788(u32, u32, u32, void*) asm("func_00102788");
void func_0017f380(s32) asm("func_0017f380");  // obj_walk_children
void func_0017f268(s32, s32, f32, f32) asm("func_0017f268");
extern u32 D_0032b91c asm("D_0032b91c");
typedef void (*VFn)(void*);

void f17f488(s32 a, s32 b, f32 x, f32 y) {
    func_0017f380(a);  // obj_walk_children
    func_0017f268(a, b, x, y);
}
}  // namespace g20

// 0017f4e0 (src/anon/batch_w37.cpp)
namespace g21 {
void func_002fd188(void (*)(void)) asm("func_002fd188");  // pool_alloc_block
typedef s32 (*VFn)(void*);
typedef void (*VFn0)(void*);
void* func_0017ec98(void*) asm("func_0017ec98");
void* func_0017edf0(void*, void*) asm("func_0017edf0");
u8* func_00168b38(void*, u32, u32) asm("func_00168b38");  // entry_array_find_nth

s32 func_0017f4e0(u8* p) {
    void* v = func_0017edf0(p, func_0017ec98(p));
    if (v) {
        u8* q = func_00168b38(v, 9, 0);  // entry_array_find_nth
        if (*(u32*)(p + 12) != *(u32*)(q + 8)) return 1;
    }
    return 0;
}
}  // namespace g21

// 0017f540 (src/anon/auto80_199_queue.cpp)
namespace g22 {
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
u32 func_0017f488(...) asm("func_0017f488");
void func_0017f380(u32) asm("func_0017f380");
u32 func_0017f4e0(u32, u32) asm("func_0017f4e0");
f32 func_00180448(u32, u32, f32, f32) asm("func_00180448");
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

void func_0017f540(u32 a0, u32 a1, f32 a2, f32 a3) {
    f32 f21 = a2;
    f32 f20 = a3;
    u32 s0 = a0;
    u32 s1 = a1;

    func_0017f380(s0);  // obj_walk_children
    u32 v0 = func_0017f4e0(s0, s1);

    if (v0 != 0) {
        f32 f0 = func_00180448(s0, s1, f21, f20);
        ((u32(*)(u32, u32, f32, f32))func_0017f488)(s0, s1, f21, f0);
    }
}
}  // namespace g22

// 0017f5e0 (src/anon/tiny_wrappers_more.cpp)
namespace g23 {
u32 func_0017f3d8(u32, u32, u32, u32) asm("func_0017f3d8");

u32 func_0017f5e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0017f3d8(a0, a1, a2, a3);
}
}  // namespace g23

// 0017f5f8 (src/anon/tiny_jal_wrappers.cpp)
namespace g24 {
u32 func_0017f3d8(u32, u32, u32, u32) asm("func_0017f3d8");

u32 func_0017f5f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r2 = func_0017f3d8(r4, r5, r6, r7);
    r15 = *(u32*)((u32)r2 + (s32)(16));
    r15 = (u32)(r15 | 0x0001u);
    *(u32*)((u32)r2 + (s32)(16)) = r15;
    return r2;
}
}  // namespace g24

// 0017f620 (src/anon/batch_w1638.cpp)
namespace g25 {
struct W1638Vq {
    f32 x, y, z, w;
    W1638Vq& operator=(const W1638Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
    void add(const W1638Vq& b) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&b) : "memory");
    }
};
struct W1638Mtx {
    f32 m[4][4];
    W1638Mtx& operator=(const W1638Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
};
struct W1638Anim;
struct W1638AnimVt { void* pad[7]; f32 (*length)(W1638Anim*); };
struct W1638Anim { W1638AnimVt* vt; };
struct W1638Req {
    s32 id;
    f32 blend;
    f32 start;
    void (*fn)(u8*);
    s32 flags;
};
struct W1638Queue {
    s32 tail;
    union { s32 head; u8 head_c; };
    W1638Req e[4];
    bool empty() { return head == tail; }
    s32 pop() { s32 h = head; head = (h + 1) % 4; return h; }
};
struct W1638Motion {
    u8 pad0[8];
    u8* obj;               // 0x08
    W1638Anim* anim;       // 0x0c
    u32 anmatr;            // 0x10
    s32 cur;               // 0x14
    u32 pad18;
    u32 f1c;               // 0x1c
    union {
        u32 flags;         // 0x20
        struct {
            u32 fstop : 1;
            u32 floop : 1;
            u32 fb2 : 5;
            u32 fb7 : 1;
            u32 fb8 : 1;
            u32 fb9 : 3;
            u32 fb12 : 1;
            u32 fb13 : 1;
            u32 fb14 : 18;
        };
    };
    u32 pad24[2];
    f32 end;               // 0x2c
    f32 time;              // 0x30
    f32 hold;              // 0x34
    f32 loop_start;        // 0x38
    W1638Queue q;          // 0x3c
    u8 pad94[0xa0 - 0x94];
    W1638Vq pos;           // 0xa0
    W1638Vq rot;           // 0xb0
    W1638Vq prev;          // 0xc0
    u32 fd0;               // 0xd0
    u32 fd4;
    u8 padd8[0xf0 - 0xd8];
    u32 ff0;               // 0xf0
    f32 speed;             // 0xf4
    u8 bf8;
    u8 bf9;                // 0xf9
    u8 padfa[2];
    u32 ffc;               // 0xfc
    u32 f100;              // 0x100
    u32 f104;              // 0x104
    bool has_hold() { return hold > 0.0f; }
};
s32 W1638_is_no_motion(W1638Motion*) asm("_ZN2YS6MOTION12is_no_motionEv");
void W1638_exec_trigger(W1638Motion*, f32, f32) asm("_ZNK2YS6ANMATR12exec_triggerEPNS_6MOTIONEff");
void W1638_check_range(W1638Motion*, f32) asm("_ZNK2YS6ANMATR11check_rangeEPNS_6MOTIONEf");
u32 W1638_is_player(u32, s32) asm("_ZNK2YS9MOTIONSET9is_playerEv");
void func_0017fef0(W1638Motion*, f32) asm("func_0017fef0");
void func_00189258(W1638Motion*) asm("func_00189258");
void func_0019be88(u8*) asm("func_0019be88");
void func_001801b0(u32, u32, u32, u8*, u32, f32) asm("func_001801b0");
void func_0017f268(W1638Motion*, s32, f32, f32) asm("func_0017f268");
void W1638_identity(W1638Mtx*) asm("_Z13func_0011b6a8Pv");
W1638Mtx& W1638_rotateY(W1638Mtx*, f32) asm("_ZN2kn7FMatrix7rotateYEf");
u32 W1638_get_allocator(void) asm("_ZN4AREA12GetAllocatorEv");
u32 W1638_copy_pose(u32, u32) asm("_Z13func_00127a88Pv");
void W1638_matrix_swap(u32) asm("_ZN2kn8ModelObj10matrixSwapEv");

// ---- 0017f620: advance the motion by dt: hold/loop handling, end of clip, next queued request, triggers.
void func_0017f620(W1638Motion* m, f32 dt) {
    m->bf9 = 0;
    if (W1638_is_no_motion(m)) return;
    W1638Vq* rot = &m->rot;
    rot->zero();
    if (m->fstop) return;
    m->floop = 0;
    m->fb8 = 0;
    f32 old = m->time;
    m->time += dt * m->speed;
    if (m->has_hold()) {
        if (m->hold <= m->time) {
            m->time = (m->time - m->hold) + m->loop_start;
            m->hold = 0.0f;
            m->fstop = 1;
            W1638_exec_trigger(m, m->loop_start, -1.0f);
            W1638_exec_trigger(m, m->loop_start, m->time);
        }
    } else if (m->end <= m->time) {
        W1638Vq tmp;
        W1638_exec_trigger(m, old, m->end);
        func_0017fef0(m, m->end);
        tmp = *rot;
        m->time -= m->end;
        W1638Queue* q = &m->q;
        if (q->empty()) {
            func_0017fef0(m, m->anim->vt->length(m->anim));
            m->time += m->anim->vt->length(m->anim);
            if (m->end < m->time) {
                m->time = m->end;
            } else {
                W1638_exec_trigger(m, m->anim->vt->length(m->anim), m->time);
            }
            rot->zero();
            func_0017fef0(m, m->time);
            rot->add(tmp);
            func_0019be88(m->obj);
        } else {
            if (m->f1c) func_0019be88(m->obj);
            s32 h = q->pop();
            W1638Req* e = &q->e[h];
            if (e->fn) e->fn(m->obj);
            if (q->e[h].flags % 2) {
                m->cur = e->id;
                u32 sv = m->f100;
                func_001801b0(m->ffc, W1638_is_player(sv, e->id), m->ff0, m->obj, 0, e->blend);
                m->f100 = sv;
            } else {
                func_0017f268(m, e->id, e->blend, e->start);
            }
        }
        m->floop = 1;
    } else {
        W1638_exec_trigger(m, old, m->time);
    }
    func_00189258(m);
    W1638_check_range(m, m->has_hold() ? m->loop_start : m->time);
}
}  // namespace g25

// 0017f938 (src/anon/batch_w1899_nsa.cpp)
namespace g26 {
struct W1638Vq {
    f32 x, y, z, w;
    W1638Vq& operator=(const W1638Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
    void add(const W1638Vq& b) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&b) : "memory");
    }
};
struct W1638Mtx {
    W1638Vq a, b, c, t;
    W1638Mtx& operator=(const W1638Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
};
extern "C" void func_0011c138(void*) asm("func_0011c138");
struct W1638Node {
    u8 pad[32];
    W1638Node() { func_0011c138(this); }
    ~W1638Node() {}
};
struct W1638Anim;
struct W1638AnimVt { void* pad[7]; f32 (*length)(W1638Anim*); };
struct W1638Anim { W1638AnimVt* vt; };
struct W1638Req {
    s32 id;
    f32 blend;
    f32 start;
    void (*fn)(u8*);
    s32 flags;
};
struct W1638Queue {
    s32 tail;
    union { s32 head; u8 head_c; };
    W1638Req e[4];
    bool empty() { return head == tail; }
    s32 pop() { s32 h = head; head = (h + 1) % 4; return h; }
};
struct W1638Motion {
    u8 pad0[8];
    u8* obj;               // 0x08
    W1638Anim* anim;       // 0x0c
    u32 anmatr;            // 0x10
    s32 cur;               // 0x14
    u32 pad18;
    u32 f1c;               // 0x1c
    union {
        u32 flags;         // 0x20
        struct {
            u32 fstop : 1;
            u32 floop : 1;
            u32 fb2 : 5;
            u32 fb7 : 1;
            u32 fb8 : 1;
            u32 fb9 : 3;
            u32 fb12 : 1;
            u32 fb13 : 1;
            u32 fb14 : 18;
        };
    };
    u32 pad24[2];
    f32 end;               // 0x2c
    f32 time;              // 0x30
    f32 hold;              // 0x34
    f32 loop_start;        // 0x38
    W1638Queue q;          // 0x3c
    u8 pad94[0xa0 - 0x94];
    W1638Vq pos;           // 0xa0
    W1638Vq rot;           // 0xb0
    W1638Vq prev;          // 0xc0
    u32 fd0;               // 0xd0
    u32 fd4;
    u8 padd8[0xf0 - 0xd8];
    u32 ff0;               // 0xf0
    f32 speed;             // 0xf4
    u8 bf8;
    u8 bf9;                // 0xf9
    u8 padfa[2];
    u32 ffc;               // 0xfc
    u32 f100;              // 0x100
    u32 f104;              // 0x104
    bool has_hold() { return hold > 0.0f; }
};
s32 W1638_is_no_motion(W1638Motion*) asm("_ZN2YS6MOTION12is_no_motionEv");
void W1638_exec_trigger(W1638Motion*, f32, f32) asm("_ZNK2YS6ANMATR12exec_triggerEPNS_6MOTIONEff");
void W1638_check_range(W1638Motion*, f32) asm("_ZNK2YS6ANMATR11check_rangeEPNS_6MOTIONEf");
u32 W1638_is_player(u32, s32) asm("_ZNK2YS9MOTIONSET9is_playerEv");
void func_0017fef0(W1638Motion*, f32) asm("func_0017fef0");
void W1638_identity(W1638Mtx*) asm("_Z13func_0011b6a8Pv");
W1638Mtx& W1638_rotateY(W1638Mtx*, f32) asm("_ZN2kn7FMatrix7rotateYEf");
u32 W1638_get_allocator(void) asm("_ZN4AREA12GetAllocatorEv");
u32 W1638_copy_pose(u32, u32) asm("_Z13func_00127a88Pv");
void W1638_matrix_swap(u32) asm("_ZN2kn8ModelObj10matrixSwapEv");
void func_0017ee68(W1638Motion*) asm("func_0017ee68");
void func_0017fff8(W1638Motion*) asm("func_0017fff8");
void func_0017fdf8(W1638Motion*) asm("func_0017fdf8");
void func_001808c0(W1638Motion*, W1638Node*) asm("func_001808c0");
void func_00124b10(u32, W1638Mtx*) asm("func_00124b10");
u32 func_001b0580(u8*) asm("func_001b0580");
void func_0011c4e8(u32, u8*, W1638Anim*, u32, W1638Node*, u32, f32) asm("func_0011c4e8");
void func_00180b98(W1638Motion*) asm("func_00180b98");
void func_00180e28(W1638Motion*) asm("func_00180e28");

void func_0017f938(W1638Motion* m) {
    u32 model = *(u32*)(m->obj + 0x670);
    if (m->fstop) {
        func_0017ee68(m);
        if (m->has_hold()) {
            W1638Mtx mtx;
            W1638Node nodes[16];
            if (m->f104 & 2) {
                m->fd0 = W1638_copy_pose(model, W1638_get_allocator());
                W1638_identity(&mtx);
                mtx.t.x = -m->prev.x;
                mtx.t.y = m->prev.y;
                mtx.t.z = m->prev.z;
                mtx = W1638_rotateY(&mtx, m->prev.w);
                func_00124b10(m->fd0, &mtx);
            }
            func_001808c0(m, nodes);
            func_0011c4e8(model, m->obj + 0x40, m->anim, func_001b0580(m->obj + 0x4a0), nodes, 0, m->loop_start);
            m->fd4 = W1638_copy_pose(model, W1638_get_allocator());
            if (!(m->f104 & 2)) m->fd0 = W1638_copy_pose(model, W1638_get_allocator());
            W1638_matrix_swap(model);
        } else {
            func_0017fff8(m);
        }
        func_0017fdf8(m);
        m->fstop = 0;
    }
    func_0017fef0(m, m->time);
    m->prev = m->pos;
    m->fb7 = 1;
    func_00180b98(m);
    func_00180e28(m);
    if (m->fb13) {
        m->fb13 = 0;
        m->fb12 = 1;
    } else {
        m->fb12 = 0;
    }
}
}  // namespace g26

// 0017fba0 (src/anon/batch_w1941_nsa.cpp)
namespace g27 {
extern "C" void func_0011c138(void*) asm("func_0011c138");
struct E1941 { u8 d[32]; E1941() { func_0011c138(this); } ~E1941() {} };
struct Sub1941 { u8 pad[1184]; u8 m[464]; void* p1648; };
struct Obj1941 {
    u8 pad0[8]; Sub1941* sub; s32 v12; u8 pad1[16]; u32 flags32; u8 pad2[12];
    f32 f48; f32 f52; u8 pad3[152]; s32 v208; s32 v212; u8 pad4[44]; u32 flags260;
};
static inline bool gt0_1941(f32 x) { return 0.0f < x; }
s32 func_00180cd0(Obj1941*) asm("func_00180cd0");
void func_0011c4b0(void*) asm("func_0011c4b0");
void func_001808c0(Obj1941*, E1941*) asm("func_001808c0");
void func_00180a10(Obj1941*, E1941*) asm("func_00180a10");
s32 func_001b0580(void*) asm("func_001b0580");
void func_0011c6a8(f32, void*, s32, s32, s32, s32, E1941*, s32) asm("func_0011c6a8");
void func_0011c4e8(f32, void*, s32, s32, s32, E1941*, s32) asm("func_0011c4e8");

void func_0017fba0(Obj1941* self, s32 a) {
    void* h = self->sub->p1648;
    self->flags32 &= ~0x80;
    self->flags260 = (self->flags260 | 1) & ~2;
    if (h != 0) {
        if (func_00180cd0(self) == 0) {
            E1941 arr[16];
            func_001808c0(self, arr);
            s32 r = func_001b0580(self->sub->m);
            f32 d = self->f52;
            bool pos = gt0_1941(d);
            if (pos) {
                func_0011c6a8(self->f48 / d, h, a, self->v208, self->v212, r, arr, 0);
            } else {
                s32 v = self->v12;
                func_0011c4e8(self->f48, h, a, v, r, arr, 0);
            }
            func_00180a10(self, arr);
            self->flags260 |= 2;
        } else {
            func_0011c4b0(h);
        }
    }
}
}  // namespace g27

// 0017fd20 (src/anon/tiny_more.cpp)
namespace g28 {

u32 func_0017fd20(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = (u32)((s32)(*(u32*)((u32)a0 + (20))) + (-56)); return (v < (u32)18); }
}  // namespace g28

// 0017fd30 YS::MOTION::sync (src/yasui/libys/motion.cpp)
namespace YS {
class MOTION {
public:
    u32 is_no_motion() asm("_ZN2YS6MOTION12is_no_motionEv");
    void sync(MOTION*) asm("_ZN2YS6MOTION4syncEPS0_");
};

void MOTION::sync(MOTION* other) {
    u32 t7 = (u32)((s32)(u32)this + 148);
    u32 t6 = *(u32*)((u32)t7 + 4);
    if (t6 == 0u) {
        *(u32*)((u32)t7 + 4) = (u32)other;
        *(u32*)((u32)this + 148) = (u32)other;
        *(u32*)((u32)other + 156) = 0u;
        return;
    }
    *(u32*)((u32)t6 + 156) = (u32)other;
    *(u32*)((u32)other + 156) = 0u;
    *(u32*)((u32)t7 + 4) = (u32)other;
}
}  // namespace YS

// 0017fd60 (src/anon/auto80_199_queue.cpp)
namespace g30 {
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

void func_0017fd60(u32 a0, u32 a1) {
    u32 t7 = *(u32*)(a0 + 148);
    u32 t4 = a0 + 148;

    u32 t5;
    if (a1 == t7) {
        t7 = *(u32*)(a1 + 156);
        t5 = 0;
        *(u32*)(a0 + 148) = t7;
    } else {
        u32 t6 = *(u32*)(t7 + 156);
        t5 = t7;
        if (t6 != a1) {
            do {
                t7 = *(u32*)(t6 + 156);
                t5 = t6;
                t6 = t7;
            } while (t7 != a1);
        }
        t7 = *(u32*)(a1 + 156);
        *(u32*)(t5 + 156) = t7;
    }

    t7 = *(u32*)(t4 + 4);
    if (a1 == t7) {
        *(u32*)(t4 + 4) = t5;
    }

    *(u32*)(a1 + 156) = 0;
}
}  // namespace g30

// 0017fdc0 (src/anon/batch_w2027_nsa.cpp)
namespace g31 {
struct W2027Node { u8 pad[0x9c]; W2027Node* next; };
struct W2027List {
    W2027Node* head;
    W2027Node* nx(W2027Node* n) { return !n ? head : n->next; }
};

u8 func_0017fdc0(u8* p, W2027Node* t) {
    W2027List* l = (W2027List*)(p + 0x94);
    W2027Node* n = 0;
    s32 r;
    while ((n = l->nx(n)) != 0) {
        if (n == t) { r = 1; goto out; }
    }
    r = 0;
out:
    return r;
}
}  // namespace g31

// 0017fdf8 (src/anon/batch_w3.cpp)
namespace g32 {
void func_00102c18(s32, s32, void (*)(void*)) asm("func_00102c18");

// Zero the 16-byte vector at +0xa0 (VU0).
void func_0017fdf8(u8* p) {  // clear_vec_at160
    asm volatile(".set noreorder\n\tvsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(p + 160) : "memory");
}
}  // namespace g32

// 0017fe10 (src/anon/batch_w79.cpp)
namespace g33 {
typedef s32 (*VF4)(void*, u8, s32, s32);
typedef void (*VF0)(void*);
typedef s32 (*VF24)(void*, f32*, f32);
typedef void (*DtorFn)(void*);
typedef void (*FreeFn)(void*, void*);
void func_00178cf8(void*, void*) asm("func_00178cf8");  // clear_vecs_three
void func_00178cf8_1(void*) asm("func_00178cf8");
s32 func_00180cd0(void*) asm("func_00180cd0");
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");
void func_00102788(u32, s32, s32, void (*)(void)) asm("func_00102788");
static inline bool is_up(u8* o) { return *(f32*)(o + 52) > 0.0f; }

f32* func_0017fe10(f32* out, u8* o, f32 t) {
    f32 m[16];
    u8* c;
    if (t < 0.0f) t = *(f32*)(o + 48);
    if (func_00180cd0(o) != 0 || is_up(o) ||
        (c = *(u8**)(o + 12), (*(VF24*)(*(u8**)c + 24))(c, m, t) != 0)) {
        asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(out) : "memory");
        return out;
    }
    out[1] = -m[13];
    out[0] = m[12];
    out[2] = -m[14];
    out[3] = -func_002f8ad0(m[8], m[10]);
    return out;
}
}  // namespace g33

// 0017fef0 (src/anon/batch_w46.cpp)
namespace g34 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq vsub46(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void vaddto46(Vq& a, const Vq& b) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&a), "r"(&b) : "memory");
}
void operator delete[](void*) asm("func_00106450");
void wtarget_0011c828(u8* o, u32 a1, u32, u32) asm("_Z16wtarget_0011c828jjjj");
void wtarget_00160de0(u32 id, u32, u32, u32) asm("_Z16wtarget_00160de0jjjj");
u8* ctarget_001947c0(s32 a, s32 b, u32, u32) asm("_Z16ctarget_001947c0jjjj");
void wtarget_001e0750(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001e0750jjjj");
void ctarget_0028e350(u8* p, u32, u32, u32) asm("_Z16ctarget_0028e350jjjj");
void func_001397d8_i(s32 id) asm("_Z13func_001397d8i");
f32 FixRadian46(f32 x) asm("_ZN2YS4MATH9FixRadianEf");
void Activate46(char*) asm("_ZN2YS4UNIT8ActivateEPc");
struct VObj11c { void (**vt)(VObj11c*, u32, u32); };
s32 func_0011f078(VObj11c*, u32) asm("func_0011f078");
struct Node139 { void (**vt)(Node139*); Node139* next; u32 pad[2]; s32 id; };
struct Head139 { u32 pad; Node139* first; };
extern Head139* D_00347f80 asm("D_00347f80");
static inline Node139* Next139(Node139* n) {
    Head139* h = D_00347f80;
    if (!n) return h->first;
    return n->next;
}
struct Node160 { u8 pad[128]; Node160* next; u8 pad2[292]; u32 id; };
extern Node160* D_004f3b38 asm("D_004f3b38");
void func_00160d28(Node160*) asm("func_00160d28");
static inline Node160* Next160(Node160* n) {
    if (!n) return D_004f3b38;
    return n->next;
}
f32 func_002f8b00(f32, f32) asm("func_002f8b00");  // to_2f9a38
struct Obj17f { u8 pad[160]; Vq pos; Vq rot; };
Vq func_0017fe10(Obj17f*) asm("func_0017fe10");

void func_0017fef0(Obj17f* p) {
    Vq t = func_0017fe10(p);
    Vq* rot = &p->rot;
    Vq d = vsub46(t, p->pos);
    vaddto46(*rot, d);
    p->rot.w = FixRadian46(p->rot.w);
    p->pos = t;
}
}  // namespace g34

// 0017ff68 (src/anon/batch_w62.cpp)
namespace g35 {
struct u128 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vr {
    union { u128 q; f32 f[4]; };
    Vr() {}
    Vr(const Vr& o) {
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder"
                     : : "r"(this), "r"(&o) : "$8", "memory");
    }
    void operator=(const Vr& o) { if (this != &o) QCOPY(this, &o); }
};
void func_002fd160(void) asm("func_002fd160") __attribute__((noreturn));
struct VObj1246 { u32 (**vt)(...); };
typedef u32 (*Fn1246)(VObj1246*, u32, u32, u32, u32, u8, u32);
void wtarget_0014ec40(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_0014ec40jjjj");
void func_002fd188(void (*)(void)) asm("func_002fd188");  // pool_alloc_block
static inline bool isPos(f32 x) { return 0.0f < x; }
struct S17f { u8 pad[48]; f32 f30; f32 f34; u8 pad2[104]; Vr v; };

// Returns v scaled by f30/f34 (w cleared), or v unchanged if f34 <= 0.
Vr func_0017ff68(S17f* s) {
    bool pos = isPos(s->f34);
    if (pos) {
        Vr r;
        Vr t;
        f32 k = s->f30 / s->f34;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                     : : "r"(&t), "r"(&s->v), "f"(k) : "$8", "memory");
        r = t;
        r.f[3] = 0.0f;
        return r;
    }
    return s->v;
}
}  // namespace g35

// 0017fff8 (src/anon/auto80_199_queue.cpp)
namespace g36 {
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
u32 func_00180cd0(u32) asm("func_00180cd0");
void func_001447e0(u32, u32, u32) asm("func_001447e0");
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

void func_0017fff8(u32 a0) {
    u8 buf[32];

    u32 s0 = a0;
    u32 s1 = (u32)(buf + 16);

    if (func_00180cd0(s0) == 0) {
        u32 t5 = *(u32*)(s0 + 12);
        u32 fn = *(u32*)(*(u32*)(t5 + 0) + 20);
        ((void(*)(u32, u32, u32))fn)(t5, (u32)buf, s1);

        func_001447e0(s0 + 216, (u32)buf, s1);
    }
}
}  // namespace g36

// 00180058 (src/anon/batch_w99.cpp)
namespace g37 {
u8* func_00168b88(u32, s32, s32, s32) asm("func_00168b88");  // find_entry16_by_half_word
void func_0017efa0(u8*, u32, f32, f32) asm("func_0017efa0");
void func_00180800(u8*, s32) asm("func_00180800");

void func_00180058(u8* p, u32 res, s8* id, u32 a, u32 b, s32* ref, f32 s)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        u8* e = func_00168b88(res, -1, id[0] | (id[1] << 8) | (id[2] << 16) | (id[3] << 24), i);  // find_entry16_by_half_word
        if (e && *(u32*)(e + 8)) {
            *(u32*)(p + 240) = a;
            *(u32*)(p + 36) |= 4;
            *(u32*)(p + 252) = b;
            *(u32*)(p + 256) = 0;
            func_0017efa0(p, *(u32*)(e + 8), s, 0.0f);
            func_00180800(p, i);
            if (ref) {
                *(u32*)(p + 328) = (u32)ref;
                (*ref)++;
            }
            return;
        }
    }
    func_0017efa0(p, 0, 0.0f, 0.0f);
}
}  // namespace g37

extern "C" const char D_0036c5b0[] = "%03d0";

// 001801b0 (src/anon/batch_w100.cpp)
namespace g38 {
extern char D_0036c5b0[] asm("D_0036c5b0");
extern s32 D_0034ec60 asm("D_0034ec60");
u32 func_0016a080(u8*) asm("func_0016a080");
s32 func_002fee78(char*, const char*, ...) asm("func_002fee78");
void func_00180058(u8*, u32, char*, u32, u32, u32, f32) asm("func_00180058");

s32 func_001801b0(u32 a, u32 b, u32 c, u8* o, u32 d, f32 k) {
    char name[16];
    u8** m;
    s32 i;
    func_002fee78(name, D_0036c5b0, func_0016a080(o));
    func_00180058(o + 320, b, name, c, a, d, k);
    if (*(u32*)(o + 1416) & 4) {
        m = (u8**)(o + 2808);
        for (i = 1; i >= 0; i--) {
            u8* p;
            name[3]++;
            p = *m++;
            if (p) func_00180058(p + 320, b, name, c, a, d, k);
        }
    }
    if (--D_0034ec60 >= 0) D_0034ec60 = -1;
    *(s32*)(o + 344) = D_0034ec60;
    return D_0034ec60;
}
}  // namespace g38

// 001802d8 (src/anon/auto80_199_queue.cpp)
namespace g39 {
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
void func_0017f380(u32) asm("func_0017f380");
u32 func_001a97b8(u32, u32) asm("func_001a97b8");
void func_001801b0(u32, u32, u32, u32, u32, f32) asm("func_001801b0");
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

void func_001802d8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, f32 a6) {
    f32 f20 = a6;
    u32 s4 = a0;
    u32 s2 = a1;
    u32 s1 = a2;
    u32 s0 = a3;
    u32 s3 = a4;
    u32 s5 = a5;

    func_0017f380(s0 + 320);  // obj_walk_children
    u32 v0 = func_001a97b8(s2, s3);

    func_001801b0(s4, v0, s1, s0, s5, f20);

    *(u32*)(s0 + 576) = s2;
    *(u32*)(s0 + 340) = s3;
}
}  // namespace g39
