// Linked unit 0x00145600-0x00147140 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../harata/libdk/aabbox.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"

// 00145600 (was gap, never written)
namespace n00145600 {
struct SBox { s16 x0, y0, z0, x1, y1, z1; };
// 1 if s16 box a contains box b
s32 func_00145600(const SBox* a, const SBox* b) asm("func_00145600");
s32 func_00145600(const SBox* a, const SBox* b) {
    if (a->x0 > b->x0) return 0;
    if (a->x1 < b->x1) return 0;
    if (a->y0 > b->y0) return 0;
    if (a->y1 < b->y1) return 0;
    if (a->z0 > b->z0) return 0;
    s32 t = a->z1 < b->z1; return t == 0;
}
}  // namespace n00145600

// 00145680 (was src/anon/batch_w286.cpp)
namespace n00145680 {
// 0x0011b0a8: definition moved into src/anon/unit_0011a660.cpp

struct Hd_5680 { u8 p0[0x14]; s32 x14; u32 x18; s32 x1c; u32 x20; s32 x24; u32 x28; };
struct El_5680 { s32 x0; s32 x4; };
struct Ob_5680 {
  u32 x0; u32 x4; u32 x8; u32 xc; u32 x10; u32 x14; u32 x18; u32 x1c;
  u8 x20[0x120 - 0x20]; u8 x120[0x778 - 0x120]; u8 x778; u8 x779; u8 p77a[0x790 - 0x77a];
  u8 x790[0xc60 - 0x790]; u8 xc60[16][880]; El_5680 x4360[512]; u8 p5360[4]; s32 x5364; u8 p5368[4];
  s32 x536c, x5370, x5374, x5378, x537c;
};
void func_00106ab8(void*) asm("func_00106ab8");
// noop_ret
void func_001070c8(void*) asm("func_001070c8");
// set_vtbl_34cc50
void func_0015e4e0(void*) asm("func_0015e4e0");
void func_0015e9e0(void*) asm("func_0015e9e0");
void func_0031a830(void*) asm("func_0031a830");
void func_001447c0(u8*, f32, f32, f32, f32, f32, f32) asm("func_001447c0");
void func_00145b90(Ob_5680*, s32) asm("func_00145b90");
void func_00146d28(Ob_5680*) asm("func_00146d28");
/*TARGET 00145680*/
void func_00145680(Ob_5680* o, Hd_5680* h, u8 flag, s32 a3) asm("func_00145680");
void func_00145680(Ob_5680* o, Hd_5680* h, u8 flag, s32 a3) {
  o->x4 = 0; o->x8 = 0; o->xc = 0; o->x10 = 0; o->x14 = 0; o->x18 = 0; o->x1c = 0;
  func_00106ab8(o->x20);  // noop_ret
  func_001070c8(o->x120);  // set_vtbl_34cc50
  o->x778 = flag;
  o->x779 = 0;
  func_0015e4e0(o->x790);
  {
    u8 (*p)[880] = o->xc60;
    for (s32 i = 15; i != -1; i--, p++) func_0015e9e0(p);
  }
  {
    El_5680* e = o->x4360;
    s32 i = 511;
    do { e->x0 = 0; e->x4 = 0; i--; func_0031a830(&(e++)->x4); } while (i != -1);
  }
  o->x0 = (u32)h;
  o->x5364 = 0; o->x536c = 0; o->x5370 = 0; o->x5374 = 0; o->x5378 = 0; o->x537c = 0;
  o->x4 = (u32)h + h->x14;
  o->x8 = (u32)h + h->x1c;
  o->xc = (u32)h + h->x24;
  o->x10 = h->x18 / 48;
  o->x14 = h->x20 / 28;
  o->x18 = h->x28 / 52;
  o->x778 = flag;
  func_001447c0((u8*)o->x4 + 16, -100000000.0f, -100000000.0f, -100000000.0f, 100000000.0f, 100000000.0f, 100000000.0f);
  func_00145b90(o, a3);
  func_00146d28(o);
}
}  // namespace n00145680

// 00145830 (was src/anon/batch_wcx2.cpp)
namespace n00145830 {
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
// --------------------
// Model instance setup: construct members, point at the model data tables and reset the bounds.
struct Hdr145830 { u8 pad[20]; s32 o20; u32 n24; s32 o28; u32 n32; s32 o36; u32 n40; };
union P145830 { u8* p; u8 c; };
union H145830 { struct Hdr145830* p; u8 c; };
struct E8_145830 { s32 a; u32 b; };
struct Obj145830 {
    H145830 hdr; P145830 t4; P145830 t8; P145830 t12; u32 n16, n20, n24, f28;
    u8 m32[256]; u8 m288[1624]; u8 f1912; u8 f1913; u8 pad1914[22]; u8 m1936[1232];
    u8 e3168[16][880]; E8_145830 e17248[512];
    s32 f21344, f21348, f21352, f21356, f21360, f21364, f21368, f21372;
};
void func_00106ab8(u8* p) asm("func_00106ab8");
void func_001070c8(u8* p) asm("func_001070c8");
void func_0015e4e0(u8* p) asm("func_0015e4e0");
void func_0015e9e0(u8* p) asm("func_0015e9e0");
void func_0031a830(u32* p) asm("func_0031a830");
void func_001447c0_x14971(u8* p, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) asm("func_001447c0");
void func_00145b90(Obj145830* o, s32 a) asm("func_00145b90");
void func_00146d28(Obj145830* o) asm("func_00146d28");
/*TARGET 00145830*/
void func_00145830(Obj145830* o, Hdr145830* h, u8 flag, s32 a) asm("func_00145830");
void func_00145830(Obj145830* o, Hdr145830* h, u8 flag, s32 a)
{
    s32 i;
    o->t4.p = 0;
    o->t8.p = 0;
    o->t12.p = 0;
    o->n16 = 0;
    o->n20 = 0;
    o->n24 = 0;
    o->f28 = 0;
    func_00106ab8(o->m32);
    func_001070c8(o->m288);
    o->f1912 = flag;
    o->f1913 = 0;
    func_0015e4e0(o->m1936);
    {
        u8* p = o->e3168[0];
        for (i = 15; i != -1; i--, p += 880) func_0015e9e0(p);
    }
    {
        E8_145830* e = o->e17248;
        i = 511;
        do {
            u32* q;
            e->a = 0;
            e->b = 0;
            q = &e->b;
            i--;
            e++;
            func_0031a830(q);
        } while (i != -1);
    }
    o->hdr.p = h;
    o->f21348 = 0;
    o->f21356 = 0;
    o->f21360 = 0;
    o->f21364 = 0;
    o->f21368 = 0;
    o->f21372 = 0;
    o->t4.p = (u8*)h + h->o20;
    o->t8.p = (u8*)h + h->o28;
    o->t12.p = (u8*)h + h->o36;
    o->n16 = h->n24 / 48;
    o->n20 = h->n32 / 28;
    o->n24 = h->n40 / 52;
    o->f1912 = flag;
    func_001447c0_x14971(o->t4.p + 16, -100000000.0f, -100000000.0f, -100000000.0f, 100000000.0f, 100000000.0f, 100000000.0f);
    func_00145b90(o, a);
    func_00146d28(o);
}
}  // namespace n00145830

// 001459e0 (was gap, never written)
namespace n001459e0 {
extern u8 D_0034c6e0[] asm("D_0034c6e0");
extern u8 D_00349dc0[] asm("D_00349dc0");
extern u8 D_00348d58[] asm("D_00348d58");
void func_0031bab8(u8*) asm("func_0031bab8");
void func_0031baa8(u8*) asm("func_0031baa8");
void func_001070e8(u8*) asm("func_001070e8");
void func_00106ac8(u8*) asm("func_00106ac8");
void func_001459e0(u8* t) asm("func_001459e0");
struct NoTail { ~NoTail() {} };
static inline void el5(u8* e) __attribute__((always_inline));
static inline void el5(u8* e) {
    if (e != 0) {
        u8* q = e + 80;
    top3:
        if (e == q) return;
        q -= 16;
        goto top3;
    }
}
void func_001459e0(u8* t) {
    NoTail nt;
    if (t + 3168 != 0) {
        u8* p = t + 17248;
        u8* b = t + 3168;
    top:
        if (b == p) goto done;
        p -= 880;
        ((void (*)(u8*))(**(void***)p))(p);
        goto top;
    done:;
    }
    *(u8**)(t + 1936) = D_0034c6e0;
    func_0031bab8(t + 2352);
    *(u8**)(t + 2080) = D_00349dc0;
    func_0031baa8(t + 2080);
    *(u8**)(t + 1936) = D_00348d58;
    if (t + 624 != 0) {
        u8* p = t + 1904;
        u8* b = t + 624;
    top2:
        if (b == p) goto done2;
        p -= 80;
        el5(p);
        goto top2;
    done2:;
    }
    func_001070e8(t + 288);
    func_00106ac8(t + 32);
}
}  // namespace n001459e0

// 00145ab8 (was src/anon/batch_w89.cpp)
namespace n00145ab8 {
struct E880 { void (**vt)(E880*); u8 pad[876]; };
struct Q16 { u8 d[16]; };
struct E80 { Q16 q[5]; };
// Local whose (empty) destructor keeps the final call from becoming a tail call.
struct NoTail { ~NoTail() {} };
extern u8 D_0034c6e0[] asm("D_0034c6e0");
extern u8 D_00349dc0[] asm("D_00349dc0");
extern u8 D_00348d58[] asm("D_00348d58");
void func_0031bab8(u8*) asm("func_0031bab8");
void func_0031baa8(u8*) asm("func_0031baa8");
// set_vtbl_3486a8_b
void func_001070e8(u8*) asm("func_001070e8");
void func_00106ac8(u8*) asm("func_00106ac8");
/*TARGET 00145ab8*/
// Destructor body: member arrays destroyed back to front, then members and bases.
void func_00145ab8(u8* o) asm("func_00145ab8");
// Destructor body: member arrays destroyed back to front, then members and bases.
void func_00145ab8(u8* o) {
    NoTail nt;
    if (o + 3168 != 0) {
        E880* p = (E880*)(o + 3168) + 16;
        E880* b = (E880*)(o + 3168);
    top1:
        if (b != p) { p--; p->vt[0](p); goto top1; }
    }
    *(u32*)(o + 1936) = (u32)D_0034c6e0;
    func_0031bab8(o + 2352);
    *(u32*)(o + 2080) = (u32)D_00349dc0;
    func_0031baa8(o + 2080);  // set_vtbl_3486a8_b
    *(u32*)(o + 1936) = (u32)D_00348d58;
    if (o + 624 != 0) {
        E80* p = (E80*)(o + 624) + 16;
        E80* b = (E80*)(o + 624);
    top2:
        if (b != p) {
            p--;
            Q16* a = (Q16*)p;
            if (a != 0) {
                Q16* q = a + 5;
            top3:
                if (a != q) { q--; goto top3; }
            }
            goto top2;
        }
    }
    func_001070e8(o + 288);
    func_00106ac8(o + 32);
}
}  // namespace n00145ab8

// 00145b90 (was src/anon/batch_w61.cpp)
namespace n00145b90 {
void func_00145c68(void*, u8) asm("func_00145c68");
struct E28 { u8 b0; u8 pad[27]; };
struct S145 { u8 pad[8]; E28* arr; u8 pad2[8]; s32 n; };
/*TARGET 00145b90*/
void func_00145b90(S145* a0, u64 mask) asm("func_00145b90");
void func_00145b90(S145* a0, u64 mask) {
    s32 n = a0->n;
    for (s32 i = 0; i < n; i++) a0->arr[i].b0 = 0;
    for (s32 i = 0; i < 64; i++) {
        u64 bit = (u64)1 << i;
        if (mask & bit) func_00145c68(a0, i);
    }
}
}  // namespace n00145b90

// 00145c28 (was src/anon/batch_w16.cpp)
namespace n00145c28 {
// 0x0013b260: definition moved into src/anon/unit_0013a8b8.cpp

// Deactivates every 28-byte entry whose id matches.
struct Ent28 {
    u8 active;
    u8 id;
    u8 pad[26];
};
/*TARGET 00145c28*/
void func_00145c28(u8* p, u8 id) asm("func_00145c28");
void func_00145c28(u8* p, u8 id) {
    s32 n = *(s32*)(p + 20);
    for (s32 i = 0; i < n; i++) {
        Ent28* e = (Ent28*)(i * 28 + *(u32*)(p + 8));
        if (e->id == id) e->active = 0;
    }
}
}  // namespace n00145c28

// 00145c68 (was src/anon/batch_w26.cpp)
namespace n00145c68 {
// 0x00140850: definition moved into src/anon/unit_0013fca8.cpp

struct Ent28 { u8 flag; u8 id; u8 pad[26]; };
struct EntList { u8 pad[8]; Ent28* ents; u8 pad2[8]; s32 count; };
/*TARGET 00145c68*/
// Sets the flag of every entry with the given id.
void func_00145c68(EntList* l, u8 id) asm("func_00145c68");
// Sets the flag of every entry with the given id.
void func_00145c68(EntList* l, u8 id) {  // array_find_byte
    s32 n = l->count;
    s32 i;
    for (i = 0; i < n; i++) {
        if (l->ents[i].id == id) l->ents[i].flag = 1;
    }
}
}  // namespace n00145c68

// 00145cb0 (was src/anon/batch_w1681.cpp)
namespace n00145cb0 {
// 4x4 float matrix (16-byte aligned rows), copied with lq/sq.
struct W1681Mtx {
    f32 m[4][4];
    W1681Mtx() {}
    W1681Mtx(const W1681Mtx& o)
    {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W1681Mtx& operator=(const W1681Mtx& o)
    {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// 4-float vector copied with one lq/sq.
struct W1681Vec4 {
    f32 v[4];
    W1681Vec4& operator=(const W1681Vec4& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// result = r * l (each row of r transforms the rows of l)
static inline W1681Mtx W1681Mul(const W1681Mtx& l, const W1681Mtx& r)
{
    W1681Mtx d;
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
// Field types below reproduce the original's alias sets: the scheduler order of the
// inlined record copy depends on which members may alias each other.
struct W1681Handle { void* p; };
union W1681Value { s32 i; s32* p; };
struct W1681Range { s32* begin; s32* end; } __attribute__((aligned(8)));
// 256-byte camera record (see func_00106a18).
struct W1681Cam {
    W1681Mtx world;     // 0
    f32 f40;            // 64
    W1681Handle h44;    // 68
    void* p48;          // 72
    s32 i4c;            // 76
    W1681Value v50;     // 80
    void* p54;          // 84
    W1681Range r58;     // 88
    s32* p60;           // 96
    f32 f64, f68, f6c, f70, f74, f78;  // 100
    W1681Mtx view;      // 128 (func_00106ad0)
    W1681Mtx clip;      // 192 (func_00106ae0)
};
// 144-byte record (see func_00106a60).
struct W1681Rec {
    W1681Vec4 v0;       // 0
    W1681Mtx m;         // 16
    W1681Vec4 v50, v60, v70;
    f32 f80;            // 128
};
struct W1681Obj {
    u8 pad0[32];
    W1681Cam cam;       // 32
    W1681Rec rec;       // 288
    W1681Mtx worldMul;  // 432
    W1681Mtx viewMul;   // 496
    W1681Mtx clipMul;   // 560
};
W1681Cam* func_00106a18(s32) asm("func_00106a18");
W1681Rec* func_00106a60(s32) asm("func_00106a60");
W1681Mtx* W1681_camView(W1681Cam*) asm("_ZN2dk11ViewFrustum9setMatrixERKN2kn7FMatrixE");
W1681Mtx* W1681_camClip(W1681Cam*) asm("_ZN2kn10Projection19getViewClipGsMatrixEv");
void func_00146680(W1681Mtx*, const W1681Mtx*) asm("func_00146680");
/*TARGET 00145cb0*/
// Takes a snapshot of the current camera and the current record, and precomputes the products.
void func_00145cb0(W1681Obj* o) asm("func_00145cb0");
// Takes a snapshot of the current camera and the current record, and precomputes the products.
void func_00145cb0(W1681Obj* o)
{
    o->cam = *func_00106a18(1);
    W1681Mtx view(*W1681_camView(&o->cam));
    W1681Mtx clip(*W1681_camClip(&o->cam));
    W1681Rec* d = &o->rec;
    W1681Rec* r = func_00106a60(1);
    d->m = r->m;
    d->v50 = r->v50;
    d->v60 = r->v60;
    d->v70 = r->v70;
    d->f80 = r->f80;
    o->worldMul = W1681Mul(o->cam.world, d->m);
    func_00146680(&o->viewMul, &W1681Mul(view, d->m));
    func_00146680(&o->clipMul, &W1681Mul(clip, d->m));
}
}  // namespace n00145cb0

// 00146070 (was src/anon/misc_1.cpp)
namespace n00146070 {
/*TARGET 00146070*/
// 0x0013fd88: definition moved into src/anon/unit_0013fca8.cpp

void func_00146070(void* self, s32 v) asm("_Z13func_00146070Pvi");
// 0x0013fd88: definition moved into src/anon/unit_0013fca8.cpp

void func_00146070(void* self, s32 v) { *(s32*)((char*)self + 28) = v; }
}  // namespace n00146070

// 00146078 (was src/anon/misc_1.cpp)
namespace n00146078 {
/*TARGET 00146078*/
void func_00146078(void* self, s32 v) asm("_Z13func_00146078Pvi");
void func_00146078(void* self, s32 v) { *(s32*)((char*)self + 21352) = v; }
}  // namespace n00146078

// 00146080 (was src/anon/misc_1.cpp)
namespace n00146080 {
/*TARGET 00146080*/
void func_00146080(void* self, s32 v) asm("_Z13func_00146080Pvi");
void func_00146080(void* self, s32 v) { *(s32*)((char*)self + 21348) = v; }
}  // namespace n00146080

// 00146088 (was src/anon/batch_w45.cpp)
namespace n00146088 {
s32 func_00146c08(u8*, u32) asm("func_00146c08");
/*TARGET 00146088*/
// 0x001386e0: definition moved into src/anon/unit_00138480.cpp

// true if any of the a0+624 entries (stride 80) accepts a1
s32 func_00146088(u8* a0, u32 a1) asm("func_00146088");
// 0x001386e0: definition moved into src/anon/unit_00138480.cpp

// true if any of the a0+624 entries (stride 80) accepts a1
s32 func_00146088(u8* a0, u32 a1) {
    s32 n = *(s32*)(a0 + 1904);
    for (s32 i = 0; i < n; i++) {
        if (func_00146c08(a0 + 624 + i * 80, a1)) return 1;
    }
    return 0;
}
}  // namespace n00146088

// 00146100 (was src/anon/tiny_leaf.cpp)
namespace n00146100 {
/*TARGET 00146100*/
// 0x0013dd18: definition moved into src/anon/unit_0013a8b8.cpp

void func_00146100(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00146100jjjj");
// 0x0013dd18: definition moved into src/anon/unit_0013a8b8.cpp

void func_00146100(u32 a0, u32 a1, u32 a2, u32 a3) {  // array_push_short
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r13 = 0u, r14 = 0u, r15 = 0u;
    r14 = *(u32*)((u32)r5 + (s32)(0));
    r6 = (u32)(r6 << 16);
    r13 = *(u32*)((u32)r4 + (s32)(28));
    r6 = (u32)((s32)r6 >> 16);
    r15 = (u32)(r14 << 1);
    r15 = (u32)(r15 + r13);
    r14 = (u32)((s32)r14 + (1));
    *(u16*)((u32)r15 + (s32)(0)) = (u16)r6;
    *(u32*)((u32)r5 + (s32)(0)) = r14;
}
}  // namespace n00146100

// 00146128 (was src/anon/batch_w90.cpp)
namespace n00146128 {
// 0x00143b88: definition moved into src/anon/unit_00142c90.cpp

// 00146128
s32 func_00146730(void*, void*) asm("func_00146730");
void func_00146100(void*, s32*, s16) asm("func_00146100");
/*TARGET 00146128*/
void func_00146128(u8* self, s32* cnt, s16 idx) asm("func_00146128");
void func_00146128(u8* self, s32* cnt, s16 idx)
{
    switch (func_00146730(self + 560, *(u8**)(self + 8) + idx * 28 + 4)) {
    case 0: break;
    case 1: func_00146100(self, cnt, idx); break;
    case 2: (*(u16**)(self + 28))[*cnt] = idx | 0x8000; (*cnt)++; break;
    }
}
}  // namespace n00146128

// 001461f0 (was src/anon/auto80_199_queue.cpp)
namespace n001461f0 {
/*TARGET 001461f0*/
void func_001461f0(u32 a0, u8* a1) asm("_Z13func_001461f0jPh");
void func_001461f0(u32 a0, u8* a1) {
    u32 s0 = *(u32*)(a1 + 44);
    u32 s1 = a0;
    if (s0 == 0) {
        return;
    }

    do {
        u32 t7 = *(u32*)(s0 + 248);
        if ((t7 & 0x800) == 0) {
            func_001471d8(s1, s0);
        } else {
            func_001471d8(s1, s0);
        }
        s0 = *(u32*)(s0 + 272);
    } while (s0 != 0);
}
}  // namespace n001461f0

// 00146250 (was src/anon/batch_w265.cpp)
namespace n00146250 {
struct V265q { f32 v[4]; ~V265q() {} } __attribute__((aligned(16)));
// 0x002c1320: definition moved into src/anon/unit_002c10e0.cpp
struct N265q { u8 pad[208]; u8 d[40]; u32 fl; V265q* mp; u8 pad2[16]; N265q* next; };
struct Y265q { u8 pad[44]; N265q* head; };
void func_001471d8(u8*, N265q*) asm("func_001471d8");
void func_00147210(u8*, N265q*) asm("func_00147210");
void func_00144b38(u8*, V265q*) asm("func_00144b38");
s32 func_001466b0(u8*, V265q*) asm("func_001466b0");
/*TARGET 00146250*/
// mat4_transform_vecs
void func_00146250(u8* a, Y265q* y) asm("func_00146250");
// mat4_transform_vecs
void func_00146250(u8* a, Y265q* y) {
    V265q m[8];
    N265q* n;
    for (n = y->head; n; n = n->next) {
        u32 fl = n->fl;
        if (fl & 0x1000) {
            if (!(fl & 0x20)) goto A;
            goto B;
        }
        if (!(fl & 0x800)) goto A;
        {
            V265q* mp;
            s32 r, r2;
            if (n->mp) mp = n->mp;
            else {
                mp = m;
                func_00144b38(n->d, m);
            }
            r = func_001466b0(a + 496, mp);  // mat4_transform_vecs
            if (r == 1) goto A;
            if (r < 2) continue;
            if (r != 2) continue;
            if (!(n->fl & 0x20)) goto A;
            r2 = func_001466b0(a + 560, mp);  // mat4_transform_vecs
            if (r2 == 1) goto A;
            if (r2 < 2) continue;
            if (r2 != r) continue;
            goto B;
        }
    B:
        func_00147210(a, n);
        continue;
    A:
        func_001471d8(a, n);
    }
}
}  // namespace n00146250

// 00146390 (was src/anon/batch_w81.cpp)
namespace n00146390 {
// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct Vq81 {
    f32 x, y, z, w;
    Vq81& operator=(const Vq81& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// 0x0013d9e0: definition moved into src/anon/unit_0013a8b8.cpp

// --- 00146390: recursive tree walk (node test, visit items, then up to 8 children)
struct Node146 { s16 child[8]; Vq81 v; u8 pad20[8]; s16 start, end; u8 pad[4]; };
struct Tree146 { u32 a; Node146* nodes; u8* items; };
s32 func_00146088(Tree146*, Vq81*) asm("func_00146088");
void func_00146100(Tree146*, u32, s16) asm("func_00146100");
void func_001461f0(Tree146*, Node146*) asm("func_001461f0");
/*TARGET 00146390*/
void func_00146390(Tree146* t, s32 idx, u32 arg) asm("func_00146390");
void func_00146390(Tree146* t, s32 idx, u32 arg) {
    Node146* n = &t->nodes[idx];
    if (func_00146088(t, &n->v) == 1) return;
    s32 j;
    s32 end = n->end;
    s32 i;
    for (i = n->start; i < end; i++) {
        if (t->items[i * 28]) func_00146100(t, arg, i);
    }
    func_001461f0(t, n);
    for (j = 0; j < 8; j++) {
        if (n->child[j] == -1) break;
        func_00146390(t, n->child[j], arg);
    }
}
}  // namespace n00146390

// 00146498 (was src/anon/batch_w111.cpp)
namespace n00146498 {
struct Node14 { s16 child[8]; u8 box[24]; s16 first; s16 end; u8 pad[4]; };
struct Item14 { u8 on; u8 pad[3]; u8 box[24]; };
struct Tree14 { u8 pad[4]; Node14* nodes; Item14* items; u8 pad2[484]; u8 view[1]; };
s32 func_00146730(void*, void*) asm("func_00146730");
void func_00146390(Tree14*, s32, void*) asm("func_00146390");
s32 func_00146088(Tree14*, void*) asm("func_00146088");
void func_00146100(Tree14*, void*, s16) asm("func_00146100");
void func_00146128(Tree14*, void*, s16) asm("func_00146128");
void func_00146250(Tree14*, Node14*) asm("func_00146250");
/*TARGET 00146498*/
// Recursively visits a node tree against a view volume, handling items of partly visible nodes.
void func_00146498(Tree14* t, s32 idx, void* arg) asm("func_00146498");
// Recursively visits a node tree against a view volume, handling items of partly visible nodes.
void func_00146498(Tree14* t, s32 idx, void* arg)
{
    Node14* n = &t->nodes[idx];
    switch (func_00146730(t->view, n->box)) {
    case 1:
        func_00146390(t, idx, arg);
        return;
    case 0:
        return;
    case 2:
        if (func_00146088(t, n->box) == 1) return;
        s32 end = n->end;
        for (s32 i = n->first; i < end; i++) {
            Item14* it = (Item14*)(i * sizeof(Item14) + (u32)t->items);
            if (it->on) {
                switch (func_00146730(t->view, it->box)) {
                case 0: break;
                case 1: func_00146100(t, arg, i); break;
                case 2: func_00146128(t, arg, i); break;
                }
            }
        }
        func_00146250(t, n);
        break;
    }
    for (s32 k = 0; k < 8; k++) {
        s32 c = n->child[k];
        if (c == -1) break;
        func_00146498(t, c, arg);
    }
}
}  // namespace n00146498

// 00146680 (was src/anon/batch_w8.cpp)
namespace n00146680 {
/*TARGET 00146680*/
// 0x00123d10: definition moved into src/anon/unit_00123990.cpp

// 64-byte (matrix) copy src -> dst unless they are the same.
void func_00146680(u8* dst, u8* src) asm("func_00146680");
// 0x00123d10: definition moved into src/anon/unit_00123990.cpp

// 64-byte (matrix) copy src -> dst unless they are the same.
void func_00146680(u8* dst, u8* src) {  // copy_quad4_if_diff
    if (dst != src) {
        asm volatile(
            "lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
            : : "r"(dst), "r"(src) : "$8", "$9", "$10", "$11", "memory");
    }
}
}  // namespace n00146680

// 001466b0 (was src/anon/batch_w58.cpp)
namespace n001466b0 {
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
/*TARGET 001466b0*/
// Clip-tests 8 points against the matrix m: 0 = all outside one plane,
// 2 = partially clipped, 1 = all inside.
s32 func_001466b0(Vec4* m, Vec4* v) asm("func_001466b0");
// Clip-tests 8 points against the matrix m: 0 = all outside one plane,
// 2 = partially clipped, 1 = all inside.
s32 func_001466b0(Vec4* m, Vec4* v) {  // mat4_transform_vecs
    u32 orr = 0, andd = 63;
    for (s32 i = 0; i < 8; i++, v++) {
        u32 c;
        asm volatile("lqc2 $vf8,0(%1)\n\tlqc2 $vf4,0(%2)\n\tlqc2 $vf5,16(%2)\n\tlqc2 $vf6,32(%2)\n\tlqc2 $vf7,48(%2)\n\t"
            "vmulax.wxyz ACC,$vf4,$vf8x\n\tvmadday.wxyz ACC,$vf5,$vf8y\n\tvmaddaz.wxyz ACC,$vf6,$vf8z\n\tvmaddw.wxyz $vf12,$vf7,$vf8w\n\t"
            "vclipw.xyz $vf12,$vf12w\n\tvnop\n\tvnop\n\tvnop\n\tvnop\n\tcfc2.ni %0,$vi18"
            : "=r"(c) : "r"(v), "r"(m));
        c &= 0x3f;
        orr |= c;
        andd &= c;
        if (andd == 0 && orr != 0) return 2;
    }
    return andd == 0;
}
}  // namespace n001466b0

// 00146730 (was src/anon/batch_w29.cpp)
namespace n00146730 {
struct E16 { u32 w[4]; ~E16() {} } __attribute__((aligned(16)));
void wtarget_00146730(u32 a, u32 b) asm("_Z16wtarget_00146730jjjj");
void func_00144b38(u32, E16*) asm("func_00144b38");
void func_001466b0(u32, E16*) asm("func_001466b0");
/*TARGET 00146730*/
// 0x00140ce8: definition moved into src/anon/unit_0013fca8.cpp

void wtarget_00146730(u32 a, u32 b) asm("_Z16wtarget_00146730jjjj");
// 0x00140ce8: definition moved into src/anon/unit_0013fca8.cpp

void wtarget_00146730(u32 a, u32 b) {
    E16 buf[8];
    func_00144b38(b, buf);
    func_001466b0(a, buf);  // mat4_transform_vecs
}
}  // namespace n00146730

// 00146788 (was src/anon/batch_wcx2.cpp)
namespace n00146788 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V33 {
    f32 x, y, z, w;
    V33& operator=(const V33& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
V33 func_00163650(const V33*, const V33*, const V33*) asm("func_00163650");
/*TARGET 00146788*/
void func_00146788(V33* out, V33* p) asm("func_00146788");
void func_00146788(V33* out, V33* p)
{
    out[0] = func_00163650(&p[0], &p[1], &p[2]);
    out[1] = func_00163650(&p[7], &p[6], &p[5]);
    out[2] = func_00163650(&p[3], &p[2], &p[6]);
    out[3] = func_00163650(&p[0], &p[4], &p[5]);
    out[4] = func_00163650(&p[4], &p[0], &p[3]);
    out[5] = func_00163650(&p[6], &p[2], &p[1]);
}
}  // namespace n00146788

// 001468f0 (was src/anon/batch_wcx2.cpp)
namespace n001468f0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V33 {
    f32 x, y, z, w;
    V33& operator=(const V33& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
// 002e1f70: moved to src/anon/unit_002e1908.cpp

V33 func_00163650(const V33*, const V33*, const V33*) asm("func_00163650");
/*TARGET 001468f0*/
void func_001468f0(V33* out, V33* p) asm("func_001468f0");
void func_001468f0(V33* out, V33* p)
{
    out[0] = func_00163650(&p[0], &p[1], &p[2]);
    out[1] = func_00163650(&p[7], &p[6], &p[5]);
    out[2] = func_00163650(&p[3], &p[2], &p[6]);
    out[3] = func_00163650(&p[0], &p[4], &p[5]);
    out[4] = func_00163650(&p[4], &p[0], &p[3]);
    out[5] = func_00163650(&p[6], &p[2], &p[1]);
}
}  // namespace n001468f0

// 00146a58 (was gap, never written)
namespace n00146a58 {
struct V4 { f32 x, y, z, w; };
static inline f32 dot3(const V4* a, const V4* b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8");
    return r;
}
// 1 if the point is behind all 6 planes
s32 func_00146a58(const V4* pl, const V4* p) asm("func_00146a58");
s32 func_00146a58(const V4* pl, const V4* p) {
    for (s32 i = 0; i < 6; i++, pl++) {
        if (dot3(p, pl) + pl->w >= 0.0f) return 0;
    }
    return 1;
}
}  // namespace n00146a58

// 00146ab0 (was src/anon/batch_w92.cpp)
namespace n00146ab0 {
// ---- 146ab0 ----
struct V146 {
    f32 x, y, z, w;
    V146& operator=(const V146& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
V146 func_00163650(const V146*, const V146*, const V146*) asm("func_00163650");
void f_00146ab0(V146* pl, const V146* eye, const V146* c) asm("_Z13func_00146ab0Pv");
/*TARGET 00146ab0*/
// builds 5 planes: one from the far corners, four from the eye and corner pairs
void f_00146ab0(V146* pl, const V146* eye, const V146* c) asm("_Z13func_00146ab0Pv");
// builds 5 planes: one from the far corners, four from the eye and corner pairs
void f_00146ab0(V146* pl, const V146* eye, const V146* c) {
    pl[0] = func_00163650(&c[0], &c[1], &c[2]);
    pl[1] = func_00163650(eye, &c[2], &c[3]);
    pl[2] = func_00163650(eye, &c[0], &c[1]);
    pl[3] = func_00163650(eye, &c[3], &c[0]);
    pl[4] = func_00163650(eye, &c[1], &c[2]);
}
}  // namespace n00146ab0

// 00146bd8 (was src/anon/tiny.cpp)
namespace n00146bd8 {
void func_00146ab0(void*) asm("_Z13func_00146ab0Pv");
/*TARGET 00146bd8*/
void func_00146bd8(BD_VALUE* bd) asm("_Z13func_00146bd8P8BD_VALUE");
void func_00146bd8(BD_VALUE* bd) { func_00146ab0(bd); }
}  // namespace n00146bd8

// 00146bf0 (was gap, never written)
namespace n00146bf0 {
void func_00146ab0(void*) asm("_Z13func_00146ab0Pv");
void func_00146bf0(BD_VALUE* bd) asm("func_00146bf0");
void func_00146bf0(BD_VALUE* bd) { func_00146ab0(bd); }
}  // namespace n00146bf0

// 00146c08 (was src/anon/batch_w68.cpp)
namespace n00146c08 {
// 0x0013d2d0: definition moved into src/anon/unit_0013a8b8.cpp

/* ---- 00146c08: box vs 5 planes (VU0 dot product) ---- */
static inline bool front2(f32 d) { return 0.0f <= d; }
static inline f32 dot1(f32* v, f32* pl) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
            : "=f"(d) : "r"(v), "r"(pl) : "$8", "memory");
    return d;
}
/*TARGET 00146c08*/
s32 func_00146c08(f32* pl, f32* box) asm("func_00146c08");
s32 func_00146c08(f32* pl, f32* box) {
    s32 i;
    for (i = 0; i < 5; i++, pl += 4) {
        f32 v[4] __attribute__((aligned(16)));
        f32 d;
        v[0] = *(s32*)&pl[0] >= 0 ? box[3] : box[0];
        v[1] = *(s32*)&pl[1] >= 0 ? box[4] : box[1];
        v[2] = *(s32*)&pl[2] >= 0 ? box[5] : box[2];
        d = dot1(v, pl);
        if (front2(d + pl[3])) return 0;
    }
    return 1;
}
}  // namespace n00146c08

// 00146cb0 (was src/anon/batch_w223.cpp)
namespace n00146cb0 {
struct V4 { f32 x, y, z, w; };
static inline f32 dot3(const V4* a, const V4* b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8");
    return r;
}
// 1 if all 8 points are behind all 5 planes (was a whole-body asm copy)
s32 func_00146cb0(const V4* pl, const V4* p) asm("func_00146cb0");
s32 func_00146cb0(const V4* pl, const V4* p) {
    for (s32 i = 0; i < 5; i++) {
        for (s32 j = 0; j < 8; j++) {
            if (dot3(&p[j], &pl[i]) + pl[i].w >= 0.0f) return 0;
        }
    }
    return 1;
}
}  // namespace n00146cb0

// 00146d28 (was src/anon/tiny_auto80_queue.cpp)
namespace n00146d28 {
/*TARGET 00146d28*/
void func_00146d28(u32 a0) asm("_Z13func_00146d28j");
void func_00146d28(u32 a0) {
    *(u32*)((u32)a0 + (s32)(21344)) = 0u;
    s32 n = *(s32*)((u32)a0 + (s32)(16));
    if (n <= 0) return;
    s32 cnt = n;
    u32 idx = 0u;
L:
    u32 base = *(u32*)((u32)a0 + (s32)(4));
    cnt = (s32)(cnt - 1);
    u32 s = (u32)(idx + base); base = s;
    *(u32*)((u32)base + (s32)(44)) = 0u;
    if (cnt != 0) {
        idx = (u32)(idx + (48));
        goto L;
    }
}
}  // namespace n00146d28

// 00146d68 (was src/anon/batch_w1765.cpp)
namespace n00146d68 {
struct W1765Mx {
    u8 d[64];
    // 64-byte block copy through four 128-bit registers (lq/sq), as in the original.
    W1765Mx& operator=(const W1765Mx& o) {
        if (this != &o)
            asm volatile("lq $8,0(%1)\n\tlq $9,16(%1)\n\tlq $10,32(%1)\n\tlq $11,48(%1)\n\t"
                         "sq $8,0(%0)\n\tsq $9,16(%0)\n\tsq $10,32(%0)\n\tsq $11,48(%0)"
                         :: "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1765Nd { u8 pad[0x40]; W1765Mx src; W1765Mx dst; u8 pad2[0x110 - 0xc0]; W1765Nd* next; };
struct W1765Slot { u8 pad[0x2c]; W1765Nd* head; };
struct W1765Mg { u8 p0[4]; W1765Slot* ents; u8 p8[8]; s32 n; u8 pad[0x5360 - 0x14]; s32 f5360; };
/*TARGET 00146d68*/
// 0x001c4188: definition moved into src/anon/unit_001c4120.cpp

void func_00146d68(W1765Mg* m) asm("func_00146d68");
// 0x001c4188: definition moved into src/anon/unit_001c4120.cpp

void func_00146d68(W1765Mg* m) {
    m->f5360 = 0;
    W1765Slot* e = m->ents;
    s32 n = m->n;
    for (s32 i = 0; i < n; i++) {
        for (W1765Nd* d = e[i].head; d; d = d->next) d->dst = d->src;
        e[i].head = 0;
    }
}
}  // namespace n00146d68

// 00146de0 (was src/anon/tiny_auto80_queue.cpp)
namespace n00146de0 {
/*TARGET 00146de0*/
void func_00146de0(u32 a0) asm("_Z13func_00146de0j");
void func_00146de0(u32 a0) {
    s32 t7 = *(s32*)((u32)a0 + (s32)(21344));
    if (t7 <= 0) return;
    s32 t4 = t7;
    u32 t2 = (u32)-3;
    u32 t3 = (u32)-2;
L:
    u32 t7p = *(u32*)((u32)a0 + (s32)(17248));
    t4 = (s32)(t4 - 1);
    u32 t6 = *(u32*)((u32)t7p + (s32)(248));
    t6 = (u32)(t6 & t2);
    *(u32*)((u32)t7p + (s32)(248)) = t6;
    u32 t5 = *(u32*)((u32)a0 + (s32)(17252));
    t5 = (u32)(t5 & t3);
    *(u32*)((u32)a0 + (s32)(17252)) = t5;
    if (t4 != 0) {
        a0 = (u32)((s32)a0 + (8));
        goto L;
    }
}
}  // namespace n00146de0

// 00146e28 (was src/anon/tiny_auto80_queue.cpp)
namespace n00146e28 {
/*TARGET 00146e28*/
// 0x00143f78: definition moved into src/anon/unit_00142c90.cpp

void func_00146e28(u32 a0, u32 a1) asm("_Z13func_00146e28jj");
// 0x00143f78: definition moved into src/anon/unit_00142c90.cpp

void func_00146e28(u32 a0, u32 a1) {
    union Cnt {
        u32 w;
        u16 h;
    };
    Cnt* c = (Cnt*)(a0 + 21344);

    u16 t7 = c->h;
    *(u16*)(a1 + 284) = t7;

    u32 t6 = c->w;
    u32 t7w = t6 << 3;
    t7w += a0;
    u32 t6n = t6 + 1;
    *(u32*)(t7w + 17248) = a1;
    c->w = t6n;

    u32 t5 = *(u32*)(a0 + 4);
    u32 t7i = *(u16*)(a1 + 280);
    t7i *= 48;
    t5 += t7i;
    u32 t6v = *(u32*)(t5 + 44);
    *(u32*)(a1 + 272) = t6v;
    *(u32*)(t5 + 44) = a1;
}
}  // namespace n00146e28

// 00146e70 (was src/anon/tiny_auto80_queue.cpp)
namespace n00146e70 {
/*TARGET 00146e70*/
void func_00146e70(u32 a0, u32 a1, u32 a2) asm("_Z13func_00146e70jjj");
void func_00146e70(u32 a0, u32 a1, u32 a2) {
    if (a2 == 0u) {
        *(u32*)((u32)a0 + (s32)(21360)) = a1;
        return;
    }
    *(u32*)((u32)a0 + (s32)(21364)) = a1;
}
}  // namespace n00146e70

// 00146e88 (was src/anon/tiny_auto80_queue.cpp)
namespace n00146e88 {
static inline u32 add_lhs(u32 a, u32 b) { return a + b; }
// 0x00143f78: definition moved into src/anon/unit_00142c90.cpp

void func_00146e28(u32 a0, u32 a1) asm("_Z13func_00146e28jj");
/*TARGET 00146e88*/
void func_00146e88(u32 a0, u32 a1) asm("_Z13func_00146e88jj");
void func_00146e88(u32 a0, u32 a1) {
    u32 t7 = *(u32*)(a1 + 248);
    u32 t6 = t7 & 8;
    t7 &= 4;
    if (t7 == 0) {
        if (t6 == 0) {
            return;
        }
    }
    u32 t6w = *(u32*)(a0 + 21344);
    t6w <<= 3;
    t6w = add_lhs(a0, t6w);
    u32 t7w = *(u32*)(t6w + 17252);
    t7w |= 2;
    *(u32*)(t6w + 17252) = t7w;
    func_00146e28(a0, a1);
}
}  // namespace n00146e88

// 00146ed8 (was src/anon/batch_w213.cpp)
namespace n00146ed8 {
// 00158fd8 (static initialiser, now made by gcc): moved to src/harata/libdk/bookcamera.cpp

struct S146 { u8 pad[235]; u8 b; u8 pad2[12]; u32 w; };
/*TARGET 00146ed8*/
u32 func_00146ed8(void* a0, S146* p) asm("func_00146ed8");
u32 func_00146ed8(void* a0, S146* p) {
    u8 b = p->b;
    if (b) { if ((s8)p->b >= 0) { if (p->w & 0x10) { p->w &= ~0x800; return 1; } } }
    p->w |= 0x800;
    return 0;
}
}  // namespace n00146ed8

// 00146f28 (was src/anon/batch_wcx2.cpp)
namespace n00146f28 {
// 0x00142f50: definition moved into src/anon/unit_00142c90.cpp

struct Node6 { u8 pad[236]; Node6* sib; Node6* child; u8 pad2[4]; u32 flags; u8 pad3[28]; s16 h280; s16 h282; };
struct St6 { u32 f; u32 pad; };
struct Tree6 { u8 pad[17252]; St6 st[511]; u8 pad2[21344 - 17252 - 4088]; s32 cur; };
s32 func_00146ed8(Tree6*, Node6*) asm("func_00146ed8");
void func_00147140(Tree6*, Node6*) asm("func_00147140");
void func_00146e28(Tree6*, Node6*) asm("func_00146e28");
void wtarget_00146f28(Tree6* t, Node6* n, u8 flag) asm("_Z16wtarget_00146f28jjjj");
static inline __attribute__((always_inline)) u32* StP6(Tree6* t, s32 i) { return &t->st[i].f; }
#define ST6(t) (*StP6((t), (t)->cur))
/*TARGET 00146f28*/
void wtarget_00146f28(Tree6* t, Node6* n, u8 flag) asm("_Z16wtarget_00146f28jjjj");
void wtarget_00146f28(Tree6* t, Node6* n, u8 flag)
{
    u32 fl = n->flags;
    if (fl & 4) goto on;
    if (!(fl & 8)) goto kids;
on:
    if ((fl & 0x1000) || func_00146ed8(t, n)) {
        if (!flag) goto clr;
        ST6(t) |= 2;
    } else {
        if (!flag) goto clr;
        ST6(t) |= 2;
        func_00147140(t, n);
        goto done;
    }
    goto zero;
clr:
    ST6(t) &= ~2;
zero:
    n->h282 = 0;
    n->h280 = 0;
done:
    func_00146e28(t, n);
kids:
    Node6* c = 0;
    while ((c = !c ? n->child : c->sib) != 0) wtarget_00146f28(t, c, 0);
}
}  // namespace n00146f28

// 00147050 (was src/anon/batch_w86.cpp)
namespace n00147050 {
struct Node { s16 link[8]; u8 box[32]; };
struct Graph { u32 f0; Node* nodes; };
s32 func_00144d90(void*, void*) asm("func_00144d90");
/*TARGET 00147050*/
s32 func_00147050(Graph* g, s32 idx, u8* c, s32 depth, s32* best) asm("func_00147050");
s32 func_00147050(Graph* g, s32 idx, u8* c, s32 depth, s32* best)
{
    Node* n = &g->nodes[idx];
    s32 found = 0;
    if (!func_00144d90(n->box, c + 208)) return 0;
    if (*best <= depth) {
        *best = depth;
        found = idx;
    }
    s16* l = n->link;
    for (s32 i = 0; i < 8; i++) {
        s32 k = *l++;
        if (k == -1) break;
        s32 r = func_00147050(g, k, c, depth + 1, best);  // entry48_process_5args
        if (r) found = r;
    }
    return found;
}
}  // namespace n00147050

