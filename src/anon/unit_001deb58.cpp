// Linked unit 0x001deb58-0x001e0398 (one namespace per old matched source; class methods in their own namespace).
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

// 001deb58 (was src/anon/perm_001deb58.cpp)
namespace n001deb58 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
union FU1deb58
{
  f32 f;
  u16 h;
  u32 u;
};
struct N1deb58
{
  u16 h0;
  u16 h2;
  FU1deb58 v[9];
};
union NU1deb58
{
  N1deb58 *p;
  f32 f;
  u32 u;
};
struct D1deb58
{
  FU1deb58 a[3];
  u32 p0;
  FU1deb58 b[3];
  u32 p1;
  FU1deb58 c[3];
  u32 p2;
  u32 f48;
  u16 h52;
  u8 pad[6];
  u8 b60;
  u8 b61;
};
struct O1deb58
{
  u8 pad[64];
  u32 f64;
  u32 f68;
  u32 f72;
  u32 f76;
  FU1deb58 f80;
  u8 pad2[4];
  NU1deb58 n;
  u32 f92;
};
N1deb58 *func_001e0188(s32) asm("func_001e0188");
/*TARGET 001deb58*/
void func_001deb58(O1deb58 *o, u32 a, u32 b, f32 f, D1deb58 *d) asm("func_001deb58");
void func_001deb58(O1deb58 *o, u32 a, u32 b, f32 f, D1deb58 *d)
{
  N1deb58 *n;
  o->f64 = a;
  o->f68 = b;
  o->f80.f = f;
  o->f92 = 1;
  o->f76 = 0;
  (&o->n)->u = 0;
  o->f72 = d->f48;
  n = func_001e0188(40);
  n->h2 = 0;
  o->n.p = n;
  n->h0 = d->h52;
  o->n.p->v[0].f = d->a[0].f;
  o->n.p->v[1].f = d->a[1].f;
  o->n.p->v[2].f = d->a[2].f;
  o->n.p->v[3].f = d->b[0].f;
  o->n.p->v[4].f = d->b[1].f;
  o->n.p->v[5].f = d->b[2].f;
  o->n.p->v[6].f = d->c[0].f;
  o->n.p->v[7].f = d->c[1].f;
  o->n.p->v[8].f = d->c[2].f;
  o->n.p->h2 = 0;
  if (d->b60)
  {
    o->n.p->h2 |= 1;
  }
  if (d->b61)
  {
    o->n.p->h2 |= 2;
  }
  o->f92 |= 8;
}
}  // namespace n001deb58

// 001dec78 (was src/anon/perm_001dec78.cpp)
namespace n001dec78 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
union FU1dec78
{
  f32 f;
  u16 h;
  u32 u;
};
struct N1dec78
{
  u16 h0;
  u16 h2;
  FU1dec78 v[9];
};
union NU1dec78
{
  N1dec78 *p;
  f32 f;
  u32 u;
};
struct D1dec78
{
  FU1dec78 a[3];
  u32 p0;
  FU1dec78 b[3];
  u32 p1;
  FU1dec78 c[3];
  u32 p2;
  u32 f48;
  u16 h52;
  u8 pad[6];
  u8 b60;
  u8 b61;
};
struct O1dec78
{
  u8 pad[64];
  u32 f64;
  u32 f68;
  u32 f72;
  u32 f76;
  FU1dec78 f80;
  u8 pad2[4];
  NU1dec78 n;
  u32 f92;
};
N1dec78 *func_001e0188(s32) asm("func_001e0188");
/*TARGET 001dec78*/
void ryj__PAX__MANAGER__MANAGER_2(O1dec78 *o, u32 a, u32 b, f32 f, D1dec78 *d) asm("ryj__PAX__MANAGER__MANAGER_2");
void ryj__PAX__MANAGER__MANAGER_2(O1dec78 *o, u32 a, u32 b, f32 f, D1dec78 *d)
{
  O1dec78 *new_var2;
  N1dec78 *n;
  FU1dec78 *new_var;
  o->f64 = a;
  o->f68 = b;
  o->f80.f = f;
  o->f92 = 1;
  o->f76 = 0;
  (&o->n)->u = 0;
  o->f72 = d->f48;
  n = func_001e0188(40);
  new_var = d->c;
  n->h2 = 0;
  o->n.p = n;
  n->h0 = d->h52;
  o->n.p->v[0].f = d->a[0].f;
  o->n.p->v[1].f = d->a[1].f;
  o->n.p->v[2].f = d->a[2].f;
  o->n.p->v[3].f = d->b[0].f;
  o->n.p->v[4].f = d->b[1].f;
  new_var2 = o;
  new_var2->n.p->v[5].f = d->b[2].f;
  new_var2->n.p->v[6].f = new_var[0].f;
  o->n.p->v[7].f = d->c[1].f;
  o->n.p->v[8].f = d->c[2].f;
  new_var2->n.p->h2 = 0;
  if (d->b60)
  {
    new_var2->n.p->h2 |= 1;
  }
  if (d->b61)
  {
    o->n.p->h2 |= 2;
  }
  new_var2->f92 |= 8;
}
}  // namespace n001dec78

// 001ded98 (was src/anon/batch_w41.cpp)
namespace n001ded98 {
struct NoTail { ~NoTail() {} };
// delete[]-free object with a 2-element 16-byte-aligned member array (empty dtors)
struct W41Inner { u32 w[4]; ~W41Inner() {} } __attribute__((aligned(16)));
struct W41Outer { u8 pad[32]; W41Inner arr[2]; ~W41Outer() {} };
void operator delete(void*) asm("func_001e0158");
// 001dbcd0: moved to src/anon/unit_001dbbe0.cpp

void func_001e01b8(void*) asm("func_001e01b8");
struct W41Own { u8 pad[0x58]; W41Outer* obj; u32 flags; };
/*TARGET 001ded98*/
void func_001ded98(W41Own* p) asm("func_001ded98");
void func_001ded98(W41Own* p) {
    NoTail nt;
    if (p->flags & 4) {
        delete p->obj;
    } else if (p->flags & 8) {
        func_001e01b8(p->obj);
    }
}
}  // namespace n001ded98

// 001dee10 (was src/anon/batch_w42.cpp)
namespace n001dee10 {
// 0x001dcb98: definition moved into src/anon/unit_001dbfd8.cpp

// 001dee10: release the attached object
struct NoTail { ~NoTail() {} };
struct E16 { u8 d[16]; ~E16() {} } __attribute__((aligned(16)));
struct Odee { u8 pad[32]; E16 e[2]; static void operator delete(void* p) asm("func_001e0158"); };
void func_001e01b8(void*) asm("func_001e01b8");
/*TARGET 001dee10*/
void func_001dee10(u8* p) asm("func_001dee10");
void func_001dee10(u8* p)
{
    NoTail keep_frame; // forces jal instead of a sibling call
    u32 fl = *(u32*)(p + 92);
    if (fl & 4) delete *(Odee**)(p + 88);
    else if (fl & 8) func_001e01b8(*(void**)(p + 88));
}
}  // namespace n001dee10

// 001dee88 (was src/anon/batch_w3866_nsa.cpp)
namespace n001dee88 {
#define W1dee88_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1dee88Vec {
    f32 x, y, z, w;
    W1dee88Vec() {}
    W1dee88Vec(const W1dee88Vec& o) { W1dee88_QCOPY(this, &o); }
    W1dee88Vec& operator=(const W1dee88Vec& o) { if (this != &o) W1dee88_QCOPY(this, &o); return *this; }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W1dee88Mtx {
    W1dee88Vec r0, r1, r2, r3;
    W1dee88Mtx() {}
    W1dee88Mtx(const W1dee88Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W1dee88Mtx& operator=(const W1dee88Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * matrix (each column of b transformed by this).
    void mul(const W1dee88Mtx& a, const W1dee88Mtx& b) {
        W1dee88Mtx& o = *this;
        asm volatile(".set noreorder\n\t"
                     "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                     : : "r"(&o), "r"(&a), "r"(&b) : "memory");
    }
    // VU0 matrix * column vector.
    W1dee88Vec operator*(const W1dee88Vec& v) const {
        W1dee88Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Key1dee88 { u16 id; u16 flags; f32 pos[3]; f32 rot[3]; f32 scale[3]; };
struct Src1dee88 { u8 pad[16]; u32 flags; u8 pad2[8]; f32 pos[3]; f32 rot[3]; f32 scale[3]; };
struct O1dee88 { W1dee88Mtx world; void* h; Src1dee88* src; u32 pad; f32 frame; u8 pad2[8]; Key1dee88* key; u32 flags; };
void func_0011b6a8(W1dee88Mtx*) asm("func_0011b6a8");
void func_0011b7b0(W1dee88Mtx*, W1dee88Vec*) asm("func_0011b7b0");
W1dee88Vec* func_001dc5f8(void*) asm("func_001dc5f8");
void func_0011bac8(W1dee88Mtx*, W1dee88Vec*) asm("func_0011bac8");
W1dee88Vec* func_001dc648(void*) asm("func_001dc648");
f32 func_0017ce10(f32) asm("func_0017ce10");
W1dee88Vec* func_001dc620(void*) asm("func_001dc620");
double func_00313b80(f32) asm("func_00313b80");
s32 func_003142e0(double, double) asm("func_003142e0");
void sceVu0CopyVector(void*, void*) asm("sceVu0CopyVector");
static inline void xform1dee88(W1dee88Vec* out, const W1dee88Mtx* m, const W1dee88Vec* v)
{
    asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(out), "r"(m), "r"(v) : "memory");
}
static inline void vmul1dee88(W1dee88Vec* out, const W1dee88Vec* a, const W1dee88Vec* b)
{
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(out), "r"(a), "r"(b) : "memory");
}
/*TARGET 001dee88*/
// Writes a node's position, rotation and scale slots: from the key (world matrix times position) or from the source (world times local transform, axes normalised, lengths kept for scale).
void ryj__PAX__MANAGER__bind(O1dee88* o) asm("ryj__PAX__MANAGER__bind");
// Writes a node's position, rotation and scale slots: from the key (world matrix times position) or from the source (world times local transform, axes normalised, lengths kept for scale).
void ryj__PAX__MANAGER__bind(O1dee88* o)
{
    W1dee88Vec pos, rot, scale;
    W1dee88Mtx r, m;
    W1dee88Vec len;
    W1dee88Mtx prod;
    W1dee88Mtx *mp, *rp, *pp;
    s32 local = 0;
    if (o->flags & 8) {
        Key1dee88* k = o->key;
        pos.x = k->pos[0];
        pos.y = k->pos[1];
        pos.z = k->pos[2];
        rot.x = k->rot[0];
        rot.y = k->rot[1];
        rot.z = k->rot[2];
        scale.x = k->scale[0];
        scale.y = k->scale[1];
        scale.z = k->scale[2];
        if (k->flags & 1) local = 1;
    } else {
        Src1dee88* s = o->src;
        pos.x = s->pos[0];
        pos.y = s->pos[1];
        pos.z = s->pos[2];
        rot.x = s->rot[0];
        rot.y = s->rot[1];
        rot.z = s->rot[2];
        scale.x = s->scale[0];
        scale.y = s->scale[1];
        scale.z = s->scale[2];
        u32 f = s->flags & 4; local = f != 0;
    }
    pos.w = 1.0f;
    rot.w = 0.0f;
    scale.w = 0.0f;
    if (local) {
        xform1dee88(func_001dc5f8(o->h), &o->world, &pos);
        *func_001dc648(o->h) = rot;
    } else {
        mp = &m;
        func_0011b6a8(mp);
        func_0011b7b0(mp, &rot);
        mp->r3 = pos;
        rp = &r;
        pp = &prod;
        pp->mul(o->world, *mp);
        *rp = *pp;
        *func_001dc5f8(o->h) = rp->r3;
        len.x = rp->r0.normalize();
        len.y = rp->r1.normalize();
        len.z = rp->r2.normalize();
        *(s32*)&len.w = 0;
        rp->r3.unit();
        func_0011bac8(rp, func_001dc648(o->h));
        func_001dc648(o->h)->x = func_0017ce10(func_001dc648(o->h)->x);
        func_001dc648(o->h)->y = func_0017ce10(func_001dc648(o->h)->y);
        func_001dc648(o->h)->z = func_0017ce10(func_001dc648(o->h)->z);
        if (o->src->flags & 0x100) {
            W1dee88Vec* d = func_001dc620(o->h);
            vmul1dee88(&pp->r0, &scale, &len);
            *d = pp->r0;
            goto tail;
        }
    }
    if (func_003142e0(func_00313b80(o->frame), 0) <= 0) {
        *func_001dc620(o->h) = scale;
    }
tail:
    if (o->flags & 4) {
        sceVu0CopyVector((u8*)o->key + 32, o->key);
        sceVu0CopyVector((u8*)o->key + 48, (u8*)o->key + 16);
    }
}
}  // namespace n001dee88

// 001df2c0 (was src/anon/batch_w3810.cpp)
namespace n001df2c0 {
#define W1df2c0_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1df2c0Vec {
    f32 x, y, z, w;
    W1df2c0Vec() {}
    W1df2c0Vec(const W1df2c0Vec& o) { W1df2c0_QCOPY(this, &o); }
    W1df2c0Vec& operator=(const W1df2c0Vec& o) { if (this != &o) W1df2c0_QCOPY(this, &o); return *this; }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W1df2c0Mtx {
    W1df2c0Vec r0, r1, r2, r3;
    W1df2c0Mtx() {}
    W1df2c0Mtx(const W1df2c0Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W1df2c0Mtx& operator=(const W1df2c0Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * matrix (each column of b transformed by this).
    void mul(const W1df2c0Mtx& a, const W1df2c0Mtx& b) {
        W1df2c0Mtx& o = *this;
        asm volatile(".set noreorder\n\t"
                     "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                     : : "r"(&o), "r"(&a), "r"(&b) : "memory");
    }
    // VU0 matrix * column vector.
    W1df2c0Vec operator*(const W1df2c0Vec& v) const {
        W1df2c0Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Src1df2c0 { u8 pad[28]; f32 a[3], b[3], c[3]; };
struct Cam1df2c0 { s32 v; u8 pad[12]; };
struct O1df2c0 { u8 pad[64]; void* h; Src1df2c0* src; };
void func_00102180(Cam1df2c0*) asm("func_00102180");
s32 func_00104190(void) asm("func_00104190");
u8* func_00106a60(s32) asm("func_00106a60");
void func_0011b6a8(W1df2c0Mtx*) asm("func_0011b6a8");
void func_0011b7b0(W1df2c0Mtx*, W1df2c0Vec*) asm("func_0011b7b0");
W1df2c0Vec* func_001dc5f8(void*) asm("func_001dc5f8");
void func_0011bac8(W1df2c0Mtx*, W1df2c0Vec*) asm("func_0011bac8");
W1df2c0Vec* func_001dc648(void*) asm("func_001dc648");
f32 func_0017ce10(f32) asm("func_0017ce10");
W1df2c0Vec* func_001dc620(void*) asm("func_001dc620");
/*TARGET 001df2c0*/
// View-relative transform: inverse camera view times local transform; writes position, normalised rotation axes and scale slots.
void func_001df2c0(O1df2c0* oo) asm("func_001df2c0");
// View-relative transform: inverse camera view times local transform; writes position, normalised rotation axes and scale slots.
void func_001df2c0(O1df2c0* oo)
{
    register O1df2c0* o asm("$18") = oo; // pin: keeps o in s2 (global-alloc priority otherwise swaps it with mp)
    Src1df2c0* s = o->src;
    W1df2c0Vec pos, rot, scale;
    pos.x = s->a[0];
    pos.y = s->a[1];
    pos.z = s->a[2];
    rot.x = s->b[0];
    rot.y = s->b[1];
    rot.z = s->b[2];
    scale.x = s->c[0];
    scale.y = s->c[1];
    scale.z = s->c[2];
    W1df2c0Mtx view, r, m, prod;
    W1df2c0Mtx* vp = &view;
    pos.w = 1.0f;
    rot.w = 0.0f;
    scale.w = 0.0f;
    Cam1df2c0 cam;
    func_00102180(&cam);
    u8* p;
    if (cam.v == func_00104190()) p = func_00106a60(0);
    else p = func_00106a60(1);
    *vp = *(W1df2c0Mtx*)(p ? p + 16 : 0);
    W1df2c0Vec* r0 = &r.r0; W1df2c0Vec* r1 = &r.r1; W1df2c0Vec* r2 = &r.r2; W1df2c0Vec* r3 = &r.r3; W1df2c0Mtx* mp = &m; W1df2c0Vec* m3 = &m.r3;
    vp->invOrtho();
    func_0011b6a8(mp);
    func_0011b7b0(mp, &rot);
    *m3 = pos;
    m3->w = 1.0f;
    prod.mul(*vp, *mp);
    *(W1df2c0Mtx*)r0 = prod;
    *func_001dc5f8(o->h) = *r3;
    r0->normalize();
    r1->normalize();
    r2->normalize();
    r3->unit();
    func_0011bac8((W1df2c0Mtx*)r0, func_001dc648(o->h));
    func_001dc648(o->h)->x = func_0017ce10(func_001dc648(o->h)->x);
    func_001dc648(o->h)->y = func_0017ce10(func_001dc648(o->h)->y);
    func_001dc648(o->h)->z = func_0017ce10(func_001dc648(o->h)->z);
    *func_001dc620(o->h) = scale;
}
}  // namespace n001df2c0

// 001df670 (was src/anon/batch_wcx2_nsa.cpp)
namespace n001df670 {
#define W1df670_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1df670Vec {
    f32 x, y, z, w;
    W1df670Vec() {}
    W1df670Vec(const W1df670Vec& o) { W1df670_QCOPY(this, &o); }
    W1df670Vec& operator=(const W1df670Vec& o) { if (this != &o) W1df670_QCOPY(this, &o); return *this; }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
    W1df670Vec& operator+=(const W1df670Vec& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1df670Mtx {
    W1df670Vec r0, r1, r2, r3;
    W1df670Mtx() {}
    W1df670Mtx(const W1df670Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W1df670Mtx& operator=(const W1df670Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * matrix (each column of b transformed by this).
    W1df670Mtx operator*(const W1df670Mtx& b) const {
        W1df670Mtx o;
        asm volatile(".set noreorder\n\t"
                     "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                     : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
    // rotate v in place by the 3x3 part
    void rot(W1df670Vec& v) const {
        asm volatile(".set noreorder\n\tlqc2 $vf4, 0(%0)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\t"
                     "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tsqc2 $vf4, 0(%0)\n\t.set reorder"
                     : : "r"(&v), "r"(this) : "memory");
    }
    // VU0 matrix * column vector.
    W1df670Vec operator*(const W1df670Vec& v) const {
        W1df670Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Def1df670 { u8 pad[6]; u16 node; u8 pad1[20]; f32 a[3]; f32 b[3]; u8 pad2[12]; u16 nodeA; u16 nodeB; f32 lenA; f32 lenB; u8 on; };
struct Pair1df670 { W1df670Vec a, b; };
struct Model1df670 { void* skel; u8 pad[60]; W1df670Mtx m; u8 pad2[268 - 128]; u32 f268; };
struct O1df670 {
    W1df670Mtx mtx;
    void* h;
    Def1df670* def;
    Model1df670* model;
    u8 pad[12];
    Pair1df670* pair;
    u32 flags;
};
extern s32 D_00352b50 asm("D_00352b50");
s32 YS__OBJ__is_exist(Model1df670*) asm("YS__OBJ__is_exist");
s32 YS__OBJ__is_stop(Model1df670*) asm("YS__OBJ__is_stop");
void func_001dc700(void*, s32) asm("func_001dc700");
void func_001dcc30(void*) asm("func_001dcc30");
void func_001dcc48(void*) asm("func_001dcc48");
void YS__OBJ__get_bone_matrix(Model1df670*, u16, W1df670Mtx*) asm("YS__OBJ__get_bone_matrix");
W1df670Vec func_0016b478(Model1df670*, u16, f32) asm("func_0016b478");
W1df670Mtx func_0023ec48(Model1df670*, u16) asm("func_0023ec48");
void func_0011d6c0(void*, u16, W1df670Mtx*) asm("func_0011d6c0");
/*TARGET 001df670*/
void ryj__PAX__MANAGER__get_obj_data(O1df670* o) asm("ryj__PAX__MANAGER__get_obj_data");
void ryj__PAX__MANAGER__get_obj_data(O1df670* o)
{
    switch (D_00352b50) {
    case 1:
        if (!YS__OBJ__is_exist(o->model)) {
            o->flags |= 0x10;
            func_001dc700(o->h, 0);
            return;
        }
        func_001dc700(o->h, YS__OBJ__is_stop(o->model));
        if (o->model->f268 & 0x80) func_001dcc30(o->h);
        else func_001dcc48(o->h);
        YS__OBJ__get_bone_matrix(o->model, o->def->node, &o->mtx);
        if (!(o->flags & 4)) return;
        o->pair->a = func_0016b478(o->model, o->def->nodeA, o->def->lenA);
        o->pair->b = func_0016b478(o->model, o->def->nodeB, o->def->lenB);
        if (!o->def->on) return;
        {
            W1df670Vec t;
            W1df670Mtx m;
            t.x = o->def->a[0];
            t.y = o->def->a[1];
            t.z = o->def->a[2];
            *(s32*)&t.w = 0;
            YS__OBJ__get_bone_matrix(o->model, o->def->nodeA, &m);
            m.r3.unit();
            m.rot(t);
            o->pair->a += t;
            t.x = o->def->b[0];
            t.y = o->def->b[1];
            t.z = o->def->b[2];
            *(s32*)&t.w = 0;
            YS__OBJ__get_bone_matrix(o->model, o->def->nodeB, &m);
            m.r3.unit();
            m.rot(t);
            o->pair->b += t;
        }
        break;
    case 2: {
        Model1df670* mdl = o->model;
        if (mdl->skel) {
            W1df670Mtx m;
            func_0011d6c0(mdl->skel, o->def->node, &m);
            o->mtx = mdl->m * m;
        } else {
            o->mtx = mdl->m;
        }
        break;
    }
    case 3:
        o->mtx = func_0023ec48(o->model, o->def->node);
        break;
    }
}
}  // namespace n001df670

// 001df9c8 (was src/anon/batch_w46.cpp)
namespace n001df9c8 {
// 001cd4c0: moved to src/anon/unit_001cd078.cpp

// ---- 001df9c8
void func_001dc840(u32) asm("func_001dc840");
void func_001dc978(u32, f32) asm("func_001dc978");
/*TARGET 001df9c8*/
void ryj__PAX__MANAGER__system_delete(u8* p) asm("ryj__PAX__MANAGER__system_delete");
void ryj__PAX__MANAGER__system_delete(u8* p) {
    u32 f = *(u32*)(p + 92);
    if (f & 0x20) return;
    *(u32*)(p + 92) = f | 0x20;
    u8* x = *(u8**)(p + 68);
    u32 g = *(u32*)(x + 16);
    if (g & 0x80) func_001dc840(*(u32*)(p + 64));
    else if (g & 0x40) func_001dc978(*(u32*)(p + 64), (f32)x[5]);
}
}  // namespace n001df9c8

// 001dfa38 (was src/anon/batch_wcx2.cpp)
namespace n001dfa38 {
extern f32 D_00349e10 asm("D_00349e10");
// 0x001112a8: definition moved into src/anon/unit_00110b00.cpp


// --------------------
// 001dfa38: effect object per-frame update (attach/transform, spawn the linked effect after the delay, end conditions)
struct H1dfa38 { u8 pad[8]; s32 bits; };
struct Def1dfa38 { u8 pad[16]; u32 flags; u8 pad2[4]; s32 effect; };
struct Src1dfa38 { u16 f0; u16 flags; };
struct O1dfa38 {
    u8 pad[64];
    H1dfa38* h;
    Def1dfa38* def;
    s32 f72;
    f32 time;
    f32 delay;
    s32 effect;
    Src1dfa38* src;
    union { u32 flags; struct { u32 local : 1; u32 rest : 31; } fb; };
};
void func_001df2c0(O1dfa38*) asm("func_001df2c0");
void ryj__PAX__MANAGER__get_obj_data(O1dfa38*) asm("ryj__PAX__MANAGER__get_obj_data");
void ryj__PAX__MANAGER__bind(O1dfa38*) asm("ryj__PAX__MANAGER__bind");
s32 func_001dc9f0(H1dfa38*) asm("func_001dc9f0");
void func_001dfca8(O1dfa38*, s32) asm("func_001dfca8");
void func_001dfe88(O1dfa38*, s32) asm("func_001dfe88");
void func_001dfdb8(O1dfa38*) asm("func_001dfdb8");
void func_001e00b0(O1dfa38*) asm("func_001e00b0");
void* f1dfa38_pos(H1dfa38*) asm("func_001dc5f8");
s32 f1dfa38_effect(s32, void*) asm("func_002bc188");
s32 func_001dffd8(O1dfa38*) asm("func_001dffd8");
void ryj__PAX__MANAGER__system_delete(O1dfa38*) asm("ryj__PAX__MANAGER__system_delete");
/*TARGET 001dfa38*/
void func_001dfa38(O1dfa38* o) asm("func_001dfa38");
void func_001dfa38(O1dfa38* o)
{
    if (o->flags & 2) {
        func_001df2c0(o);
    } else if (o->fb.local) {
        if (!(o->flags & 0x10)) {
            if (o->time <= 0.0f) {
                ryj__PAX__MANAGER__get_obj_data(o);
                ryj__PAX__MANAGER__bind(o);
            } else if (func_001dc9f0(o->h) || !(((o->flags & 8) ? o->src->flags : o->def->flags) & 2)) {
                ryj__PAX__MANAGER__bind(o);
                ryj__PAX__MANAGER__get_obj_data(o);
            }
        }
    }
    if (o->def->flags & 8) {
        if (o->fb.local) func_001dfca8(o, 0);
        else func_001dfe88(o, 0);
    } else if (o->def->flags & 0x10) {
        if (o->fb.local) func_001dfca8(o, 1);
        else func_001dfe88(o, 1);
    }
    if ((o->def->flags & 0x800) && o->fb.local) func_001dfdb8(o);
    func_001e00b0(o);
    if (!(o->flags & 0x40) && o->delay <= o->time && o->def->effect > 0) {
        o->effect = f1dfa38_effect(o->def->effect, f1dfa38_pos(o->h));
        o->flags |= 0x40;
    }
    if (o->f72 && !(o->flags & 8)) {
        if (((o->flags & 0x10) && (o->def->flags & 0x200)) || (u8)((o->h->bits >> 25) & 1) || ((o->def->flags & 0x400) && func_001dffd8(o))) ryj__PAX__MANAGER__system_delete(o);
    }
    o->time += D_00349e10;
}
}  // namespace n001dfa38

// 001dfca8 (was src/anon/batch_w92.cpp)
namespace n001dfca8 {
union F1df { f32 f; u32 u; };
struct V1df { F1df x, y, z; };
u8* func_001946f0(u32) asm("func_001946f0");
V1df* func_001dc670(u32) asm("func_001dc670");
extern s32 D_00352b50 asm("D_00352b50");
/*TARGET 001dfca8*/
// sets the model tint from the light colour, optionally as greyscale
void func_001dfca8(u8* self, u8 grey) asm("func_001dfca8");
// sets the model tint from the light colour, optionally as greyscale
void func_001dfca8(u8* self, u8 grey) {
    f32 g = 1.0f;
    f32 r = g;
    f32 b = g;
    if (D_00352b50 == 1) {
        u8* c = func_001946f0(*(u32*)(self + 72));
        r = c[0] * 0.0078125f;
        g = c[1] * 0.0078125f;
        b = c[2] * 0.0078125f;
    }
    if (grey) {
        b = r * 0.3f + g * 0.59f + b * 0.11f;
        g = b;
        r = b;
    }
    func_001dc670(*(u32*)(self + 64))->x.f = r;
    func_001dc670(*(u32*)(self + 64))->y.f = g;
    func_001dc670(*(u32*)(self + 64))->z.f = b;
}
}  // namespace n001dfca8

// 001dfdb8 (was src/anon/batch_w2376.cpp)
namespace n001dfdb8 {
// 0x002da238: definition moved into src/anon/unit_002da040.cpp
struct Rec_1dfdb8 { u8 pad[0xc]; f32 f; };
struct Hdr_1dfdb8 { u8 pad[6]; u16 id; };
struct Part_1dfdb8 { u8 pad[0xaf8]; Part_1dfdb8* l; Part_1dfdb8* r; };
struct Obj_1dfdb8 { u8 pad[0x40]; s32 x40; Hdr_1dfdb8* h; Part_1dfdb8* p; };
f32 func_00194690(Part_1dfdb8*) asm("func_00194690");
extern s32 D_00352b50 asm("D_00352b50");
s32 YS__OBJ__is_exist(Part_1dfdb8*) asm("YS__OBJ__is_exist");
s32 func_0019c5d0(Part_1dfdb8*) asm("func_0019c5d0");
Rec_1dfdb8* func_001dc670(s32) asm("func_001dc670");
/*TARGET 001dfdb8*/
// Store a factor (1, or the left/right part's value when mode 1 is on and the part is usable) into the record.
void func_001dfdb8(Obj_1dfdb8* o) asm("func_001dfdb8");
// Store a factor (1, or the left/right part's value when mode 1 is on and the part is usable) into the record.
void func_001dfdb8(Obj_1dfdb8* o) {
    f32 f = 1.0f;
    if (D_00352b50 == 1) {
        Part_1dfdb8* p = o->p;
        switch (o->h->id) {
        case 0x4003: case 0x4005: case 0x4007: p = p->l; break;
        case 0x4004: case 0x4006: case 0x4008: p = p->r; break;
        }
        if (!YS__OBJ__is_exist(p) || func_0019c5d0(p)) f = 0.0f;
        else f = func_00194690(p);
    }
    func_001dc670(o->x40)->f = f;
}
}  // namespace n001dfdb8

// 001dfe88 (was src/anon/batch_w3722_nsa.cpp)
namespace n001dfe88 {
#define QC(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QVfe88 {
    f32 x, y, z, w;
    QVfe88() {}
    QVfe88(const QVfe88& o) { QC(this, &o); }
    QVfe88& operator=(const QVfe88& o) { if (this != &o) QC(this, &o); return *this; }
} __attribute__((aligned(16)));
QVfe88* func_001dc5f8(s32) asm("func_001dc5f8");
f32* func_001dc670(s32) asm("func_001dc670");
void func_00143860(u8*, QVfe88*) asm("func_00143860");
/*TARGET 001dfe88*/
// Set an object's colour from a lookup (optionally converted to grey).
void func_001dfe88(u8* o, u8 flag) asm("func_001dfe88");
// Set an object's colour from a lookup (optionally converted to grey).
void func_001dfe88(u8* o, u8 flag) {
    QVfe88 v;
    v = *func_001dc5f8(*(s32*)(o + 0x40));
    v.y += 100000.0f;
    QVfe88 a;
    QVfe88* src = func_001dc5f8(*(s32*)(o + 0x40));
    QVfe88 b;
    QVfe88* pb = &b;
    a = *src;
    *pb = v;
    u8 c[4];
    func_00143860(c, &a);
    f32 r = c[0] * 0.0078125f;
    f32 g = c[1] * 0.0078125f;
    f32 bl = c[2] * 0.0078125f;
    if (flag) {
        bl = r * 0.3f + g * 0.59f + bl * 0.11f;
        g = bl;
        r = bl;
    }
    func_001dc670(*(s32*)(o + 0x40))[0] = r;
    func_001dc670(*(s32*)(o + 0x40))[1] = g;
    func_001dc670(*(s32*)(o + 0x40))[2] = bl;
}
}  // namespace n001dfe88

// 001dffd8 (was src/anon/batch_w62.cpp)
namespace n001dffd8 {
// 0x001d6088: definition moved into src/anon/unit_001d4f40.cpp

extern s32 D_00352b50 asm("D_00352b50");
s32 YS__OBJ__is_exist(u8*) asm("YS__OBJ__is_exist");
/*TARGET 001dffd8*/
s32 func_001dffd8(u8* p) asm("func_001dffd8");
s32 func_001dffd8(u8* p) {
    if (D_00352b50 != 1) return 0;
    s32 r = 0;
    if (!YS__OBJ__is_exist(*(u8**)(p + 72)) || (*(u32*)(*(u8**)(p + 72) + 352) & 0x20000000) ||
        (*(u32*)(*(u8**)(p + 72) + 268) & 0x400))
        r = 1;
    return r;
}
}  // namespace n001dffd8

// 001e0058 (was src/anon/batch_w58.cpp)
namespace n001e0058 {
// 0x001dced0: definition moved into src/anon/unit_001dbfd8.cpp

void func_002bc358(s32, s32) asm("func_002bc358");
void func_001dee10(u8*) asm("func_001dee10");
void func_001de978(u8*) asm("func_001de978");
/*TARGET 001e0058*/
void func_001e0058(u8* p) asm("func_001e0058");
void func_001e0058(u8* p) {
    s32 h = *(s32*)(p + 84);
    if (h >= 0) func_002bc358(h, 120);
    if (p) {
        func_001dee10(p);
        func_001de978(p);
    }
}
}  // namespace n001e0058

// 001e00b0 (was src/anon/batch_w43.cpp)
namespace n001e00b0 {
s32 func_001dc790(u32) asm("func_001dc790");
u32 func_001dc5f8(u32) asm("func_001dc5f8");
void func_002bc398(u32, u32) asm("func_002bc398");
void func_002bc3f0(u32) asm("func_002bc3f0");
s32 func_001dcc60(u8* p) asm("func_001dcc60");
/*TARGET 001e00b0*/
// 0x001dcc60: definition moved into src/anon/unit_001dbfd8.cpp

void func_001e00b0(u8* p) asm("func_001e00b0");
// 0x001dcc60: definition moved into src/anon/unit_001dbfd8.cpp

void func_001e00b0(u8* p) {
    if (*(s32*)(p + 84) < 0) return;
    if (!func_001dc790(*(u32*)(p + 64)) && func_001dcc60(*(u8**)(p + 64))) {
        func_002bc398(*(u32*)(p + 84), func_001dc5f8(*(u32*)(p + 64)));
        return;
    }
    func_002bc3f0(*(u32*)(p + 84));
}
}  // namespace n001e00b0

// 001e0128 (was src/anon/batch_w10.cpp)
namespace n001e0128 {
extern void** D_01d9e340 asm("D_01d9e340");
/*TARGET 001e0128*/
// 0x001dc7e8: definition moved into src/anon/unit_001dbfd8.cpp

void* func_001e0128(void* a) asm("func_001e0128");
// 0x001dc7e8: definition moved into src/anon/unit_001dbfd8.cpp

void* func_001e0128(void* a) {
    void** o = D_01d9e340;
    return (*(void* (**)(void*, void*, s32))*o)(o, a, 0);
}
}  // namespace n001e0128

// 001e0158 (was src/anon/batch_w13.cpp)
namespace n001e0158 {
extern u8* D_01d9e340 asm("D_01d9e340");
extern void (*D_0035e380[])(void) asm("D_0035e380");
// 0x001dcfb0: definition moved into src/anon/unit_001dbfd8.cpp

typedef void (*VFnP)(void*, void*);
/*TARGET 001e0158*/
void func_001e0158(void* a) asm("func_001e0158");
void func_001e0158(void* a) {
    u8* o = D_01d9e340;
    (*(VFnP*)(*(u8**)o + 4))(o, a);
}
}  // namespace n001e0158

// 001e0188 (was src/anon/batch_w6.cpp)
namespace n001e0188 {
// Batch w6: small leaf / wrapper functions.

// Object whose first word is a vtable pointer.
struct VObj { void** vt; };
extern VObj* D_01d9e340 asm("D_01d9e340");
/*TARGET 001e0188*/
u32 func_001e0188(u32 a) asm("func_001e0188");
u32 func_001e0188(u32 a) {
    VObj* o = D_01d9e340;
    return ((u32 (*)(VObj*, u32, u32))o->vt[0])(o, a, 0);
}
}  // namespace n001e0188

// 001e01b8 (was src/anon/batch_w7.cpp)
namespace n001e01b8 {
extern u32 D_01d9e340 asm("D_01d9e340");
struct VObj { void** vtbl; };
/*TARGET 001e01b8*/
void func_001e01b8(u32 a0) asm("func_001e01b8");
void func_001e01b8(u32 a0) {
    VObj* o = (VObj*)D_01d9e340;
    ((void (*)(VObj*, u32))o->vtbl[1])(o, a0);
}
}  // namespace n001e01b8

// 001e01e8 (was src/anon/batch_w29.cpp)
namespace n001e01e8 {
/*TARGET 001e01e8*/
// Replaces value a with b on every list node not flagged 0x200.
void func_001e01e8(u8* list, u32 a, u32 b) asm("func_001e01e8");
// Replaces value a with b on every list node not flagged 0x200.
void func_001e01e8(u8* list, u32 a, u32 b) {
    u8* p = *(u8**)(list + 12);
    while (p) {
        if (!(*(u32*)(*(u8**)(p + 68) + 16) & 0x200)) {
            if (*(u32*)(p + 72) == a) *(u32*)(p + 72) = b;
        }
        p = !p ? (u8*)*(u32*)(list + 12) : *(u8**)(p + 96);
    }
}
}  // namespace n001e01e8

// 001e0230 (was src/anon/batch_w47.cpp)
namespace n001e0230 {
// 0x001b9d40: definition moved into src/anon/unit_001b9880.cpp

struct N1e0 { u8 pad[20]; N1e0* next; };
extern N1e0* D_01d9e348 asm("D_01d9e348");
void func_001e01e8(N1e0*, u32, u32) asm("func_001e01e8");
static inline N1e0* Next1e0(N1e0* n) { if (!n) return D_01d9e348; return n->next; }
/*TARGET 001e0230*/
void func_001e0230(u32 a, u32 b) asm("func_001e0230");
void func_001e0230(u32 a, u32 b) {
    N1e0* n = 0;
    while ((n = Next1e0(n))) func_001e01e8(n, a, b);
}
}  // namespace n001e0230

// 001e02a0 (was src/anon/tiny_wrappers_more.cpp)
namespace n001e02a0 {
u32 ryj__PAX__init(u32, u32, u32, u32) asm("_Z14ryj__PAX__initjjjj");
/*TARGET 001e02a0*/
u32 func_001e02a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e02a0jjjj");
u32 func_001e02a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return ryj__PAX__init(a0, ((u32)(*(u32*)((u32)(a1) + 0u))), a2, a3);
}
}  // namespace n001e02a0

// 001e02b8 (was gap)
namespace n001e02b8 {
// find the entry with this id (0 if none)
struct Ent { u16 a; u16 id; u8 pad[76]; };
struct Hdr { u8 pad[8]; s32 n; };
struct Obj { Hdr* h; Ent* e; };
Ent* gap_001e02b8(Obj* o, u32 id) asm("gap_001e02b8");
Ent* gap_001e02b8(Obj* o, u32 id) {
    s32 n = o->h->n;
    s32 i = 0;
    if (n > 0) {
        Ent* e = o->e;
        do {
            if (e->id == id) return e;
            i++;
            e++;
        } while (i < n);
    }
    return 0;
}
}  // namespace n001e02b8

// 001e02f8 (was src/anon/tiny.cpp)
namespace n001e02f8 {
extern u32 D_00352b50 asm("D_00352b50");
extern u32 D_00352b54 asm("D_00352b54");
/*TARGET 001e02f8*/
// 0x001dc9e0: definition moved into src/anon/unit_001dbfd8.cpp

void func_001e02f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e02f8jjjj");
// 0x001dc9e0: definition moved into src/anon/unit_001dbfd8.cpp

void func_001e02f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    D_00352b50 = a0;
    D_00352b54 = 0;
}
}  // namespace n001e02f8

// 001e0310 (was src/anon/batch_w1667.cpp)
namespace n001e0310 {
extern u32 D_00352b50 asm("D_00352b50");
extern u32 D_00352b54 asm("D_00352b54");
/*TARGET 001e0310*/
// 0x001afe18: definition moved into src/anon/unit_001ada38.cpp

void func_001e0310(u32 a) asm("func_001e0310");
// 0x001afe18: definition moved into src/anon/unit_001ada38.cpp

void func_001e0310(u32 a) {
    D_00352b54 = D_00352b50;
    D_00352b50 = a;
}
}  // namespace n001e0310

// 001e0328 (was src/anon/tiny_wrappers_imp.cpp)
namespace n001e0328 {
u32 func_001e02f8(u32, u32, u32, u32) asm("_Z13func_001e02f8jjjj");
/*TARGET 001e0328*/
// 0x001d6d88: definition moved into src/anon/unit_001d68e0.cpp

u32 func_001e0328(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e0328jjjj");
// 0x001d6d88: definition moved into src/anon/unit_001d68e0.cpp

u32 func_001e0328(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0035u << 16);
    r4 = *(u32*)((u32)r15 + (s32)(11092));
    return func_001e02f8(r4, r5, r6, r7);
}
}  // namespace n001e0328

// 001e0348 (was src/anon/batch_w15.cpp)
namespace n001e0348 {
// 0x001d5b78: definition moved into src/anon/unit_001d4f40.cpp

void wtarget_impl(u32, u32, u32, u32) asm("_Z16wtarget_001e0348jjjj");
struct W2 { u32 a; u32 b; };
extern W2 D_01d9e348 asm("D_01d9e348");
/*TARGET 001e0348*/
void wtarget_impl(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001e0348jjjj");
void wtarget_impl(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_01d9e348.b = 0;
        D_01d9e348.a = 0;
    }
}
}  // namespace n001e0348

// 001e0370 (was src/anon/misc_1.cpp)
namespace n001e0370 {
/*TARGET 001e0370*/
// 0x001dc5f0: definition moved into src/anon/unit_001dbfd8.cpp

void func_001e0370(void* self) asm("_Z13func_001e0370Pv");
// 0x001dc5f0: definition moved into src/anon/unit_001dbfd8.cpp

void func_001e0370(void* self) {}
}  // namespace n001e0370

// 001e0378 (was src/anon/tiny_wrappers_more.cpp)
namespace n001e0378 {
u32 func_001e0348(u32, u32, u32, u32) asm("_Z13func_001e0348jjjj");
/*TARGET 001e0378*/
u32 func_001e0378(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e0378jjjj");
u32 func_001e0378(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001e0348(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n001e0378

