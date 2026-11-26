// Linked unit 0x141458-0x142c90 (dk octree collision file: model ctor pair, dk::OctCollFile, queries).
// Starts at the unwritten C2 ctor 0x141458, after the previous file's D stub at 0x141438; ends with __tcf_0
// (0x142c88) of the local static in 0x142208. Flags: -G0 -fno-strict-aliasing -fmove-all-movables.
#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../harata/libdk/octfile.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// ---- 00141458: unwritten C2 copy of the constructor at 0x1415e8 (same body)
namespace n00141458 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
struct VB30 {
    f32 x, y, z, w;
    VB30& operator=(const VB30& s) { if (this != &s) QCOPY(this, &s); return *this; }
    VB30 operator-(const VB30& b) const
    {
        VB30 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                     : : "r"(this), "r"(&b), "r"(&r) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
typedef unsigned int u128 __attribute__((mode(TI)));
struct Mtx5 { u128 r[4]; };
struct Hdr5 { u8 pad[24]; u32 o24, n28, o32, n36, o40, n44, o48, n52, o56, n60, o64, n68, o72, n76; };
struct Mdl5 {
    u32 h;
    u32 p4, p8, p12, p16, p20, p24, p28;
    u32 n32, n36, n40, n44, n48, n52, n56, f60, f64, f68;
    u8 pad[136];
    u8 b208, b209, b210, b211;
    u32 f212, f216, f220;
};
void func_00141850(Mdl5*, u32) asm("func_00141850");
void func_0011b6a8(Mtx5*) asm("func_0011b6a8");
void func_00142940(Mdl5*, Mtx5*) asm("func_00142940");
void func_00141808(Mdl5*) asm("func_00141808");
void func_00141458(Mdl5* m, u32 hp, u32 a2) asm("func_00141458");
void func_00141458(Mdl5* m, u32 hp, u32 a2)
{
    Hdr5* h = (Hdr5*)hp;
    m->p4 = 0;
    m->p8 = 0; m->p12 = 0; m->p16 = 0; m->p20 = 0; m->p24 = 0; m->p28 = 0;
    m->n32 = 0; m->n36 = 0; m->n40 = 0; m->n44 = 0; m->n48 = 0; m->n52 = 0; m->n56 = 0;
    m->f60 = 0; m->f64 = 0; m->f68 = 0;
    m->b208 = 0; m->b209 = 0; m->b210 = 0; m->b211 = 0;
    m->f212 = 0; m->f216 = 0; m->f220 = 0;
    m->h = hp;
    m->p4 = (u32)h + h->o24;
    m->p8 = (u32)h + h->o32;
    m->p12 = (u32)h + h->o40;
    m->p16 = (u32)h + h->o48;
    m->p24 = (u32)h + h->o56;
    m->p28 = (u32)h + h->o64;
    m->p20 = (u32)h + h->o72;
    m->n32 = h->n28 / 32;
    m->n36 = h->n36 / 20;
    m->n40 = h->n44 / 16;
    m->n44 = h->n52 / 16;
    m->n52 = h->n60 / 16;
    m->n56 = h->n68 / 12;
    m->n48 = h->n76 / 4;
    func_00141850(m, a2);
    Mtx5 a;
    func_0011b6a8(&a);
    Mtx5 b;
                                            
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                 : : "r"(&b), "r"(&a) : "$8", "$9", "$10", "$11", "memory");
    func_00142940(m, &b);
    func_00141808(m);
}
}  // namespace n00141458

// ---- 001415e8 from src/anon/batch_wcx2.cpp
namespace n001415e8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
struct VB30 {
    f32 x, y, z, w;
    VB30& operator=(const VB30& s) { if (this != &s) QCOPY(this, &s); return *this; }
    VB30 operator-(const VB30& b) const
    {
        VB30 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                     : : "r"(this), "r"(&b), "r"(&r) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
typedef unsigned int u128 __attribute__((mode(TI)));
struct Mtx5 { u128 r[4]; };
struct Hdr5 { u8 pad[24]; u32 o24, n28, o32, n36, o40, n44, o48, n52, o56, n60, o64, n68, o72, n76; };
struct Mdl5 {
    u32 h;
    u32 p4, p8, p12, p16, p20, p24, p28;
    u32 n32, n36, n40, n44, n48, n52, n56, f60, f64, f68;
    u8 pad[136];
    u8 b208, b209, b210, b211;
    u32 f212, f216, f220;
};
void func_00141850(Mdl5*, u32) asm("func_00141850");
void func_0011b6a8(Mtx5*) asm("func_0011b6a8");
void func_00142940(Mdl5*, Mtx5*) asm("func_00142940");
void func_00141808(Mdl5*) asm("func_00141808");
void func_001415e8(Mdl5* m, u32 hp, u32 a2) asm("func_001415e8");
void func_001415e8(Mdl5* m, u32 hp, u32 a2)
{
    Hdr5* h = (Hdr5*)hp;
    m->p4 = 0;
    m->p8 = 0; m->p12 = 0; m->p16 = 0; m->p20 = 0; m->p24 = 0; m->p28 = 0;
    m->n32 = 0; m->n36 = 0; m->n40 = 0; m->n44 = 0; m->n48 = 0; m->n52 = 0; m->n56 = 0;
    m->f60 = 0; m->f64 = 0; m->f68 = 0;
    m->b208 = 0; m->b209 = 0; m->b210 = 0; m->b211 = 0;
    m->f212 = 0; m->f216 = 0; m->f220 = 0;
    m->h = hp;
    m->p4 = (u32)h + h->o24;
    m->p8 = (u32)h + h->o32;
    m->p12 = (u32)h + h->o40;
    m->p16 = (u32)h + h->o48;
    m->p24 = (u32)h + h->o56;
    m->p28 = (u32)h + h->o64;
    m->p20 = (u32)h + h->o72;
    m->n32 = h->n28 / 32;
    m->n36 = h->n36 / 20;
    m->n40 = h->n44 / 16;
    m->n44 = h->n52 / 16;
    m->n52 = h->n60 / 16;
    m->n56 = h->n68 / 12;
    m->n48 = h->n76 / 4;
    func_00141850(m, a2);
    Mtx5 a;
    func_0011b6a8(&a);
    Mtx5 b;
                                            
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                 : : "r"(&b), "r"(&a) : "$8", "$9", "$10", "$11", "memory");
    func_00142940(m, &b);
    func_00141808(m);
}
}  // namespace n001415e8

// ---- 00141778 from src/anon/perm_00141778.cpp
namespace n00141778 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef struct R
{
  u8 pad[12];
  u16 lo;
  u16 hi;
  u8 kind;
  u8 pad2[3];
} R;
typedef struct T
{
  u8 pad[8];
  R *r;
  u8 pad2[0x18];
  s32 n;
} T;
s32 func_00141778(T *t, u16 v) asm("func_00141778");
s32 func_00141778(T *t, u16 v)
{
  R *r;
  s32 i;
  if (v == 0xffff)
  {
    return 0;
  }
  if (r || v)
  {
    r = t->r;
  }
  else
  {
    r = t->r;
  }
  for (i = 0; i < t->n; i++, r++)
  {
    if (r->kind == 1)
    {
      if ((v >= r->lo) && (v < r->hi))
      {
        return 1;
      }
    }
    else
      if ((v >= r->lo) && (v < r->hi))
    {
      return 0;
    }
  }

  return 0;
}
}  // namespace n00141778

// ---- 00141808 from src/anon/tiny_auto80_queue.cpp
namespace n00141808 {
void func_00141808(u32 a0) asm("_Z13func_00141808j");
void func_00141808(u32 a0) {
    s32 n = *(s32*)((u32)a0 + (s32)(48));
    s32 i = 0;
    if (n <= 0) {
        return;
    }
    u32 p = *(u32*)((u32)a0 + (s32)(20));
    while (i < n) {
        u32 v = *(u32*)((u32)p + (s32)(0));
        if ((v & 15u) == 5u) {
            *(u8*)((u32)a0 + (s32)(210)) = (u8)1u;
            return;
        }
        p = (u32)((s32)p + (4));
        i = (s32)(i + 1);
    }
}
}  // namespace n00141808

// ---- 00141850 from src/anon/batch_w59.cpp
namespace n00141850 {
void func_00141928(u8*, u8) asm("func_00141928");
struct E141 { u8 pad[16]; u8 f; u8 p2[3]; };
void func_00141850(u8* p, u64 mask) asm("func_00141850");
void func_00141850(u8* p, u64 mask) {
    s32 j;
    s32 n = *(s32*)(p + 36);
    for (j = 0; j < n; j++) (*(E141**)(p + 8))[j].f = 0;
    s32 i;
    for (i = 0; i < 64; i++) {
        u64 one = 1;
        if (mask & (one << i)) func_00141928(p, i);                          
    }
}
}  // namespace n00141850

// ---- 001418e8 from src/anon/batch_w14.cpp
namespace n001418e8 {
struct Entry20 { u8 pad[16]; u8 on; u8 id; u8 pad2[2]; };
void func_001418e8(u8* p, u8 id) asm("func_001418e8");
void func_001418e8(u8* p, u8 id) {                           
    s32 n = *(s32*)(p + 36);
    s32 i;
    for (i = 0; i < n; i++) {
        if ((*(Entry20**)(p + 8))[i].id == id) (*(Entry20**)(p + 8))[i].on = 0;
    }
}
}  // namespace n001418e8

// ---- 00141928 from src/anon/batch_w25.cpp
namespace n00141928 {
struct E20 { u8 pad[16]; u8 flag; u8 id; u8 pad2[2]; };
void func_00141928(u8* o, u8 id) asm("func_00141928");
void func_00141928(u8* o, u8 id) {                          
    s32 n = *(s32*)(o + 36);
    s32 i;
    for (i = 0; i < n; i++) {
        E20* e = (E20*)(i * 20 + *(u32*)(o + 8));
        if (e->id == id) e->flag = 1;
    }
}
}  // namespace n00141928

// ---- 00141970 from src/anon/tiny_more.cpp
namespace n00141970 {
u32 func_00141970(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_00141970jjjj");
u32 func_00141970(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p = *(u32*)((u32)a0 + (0)); return *(u32*)((u32)p + (12)); }
}  // namespace n00141970

// ---- 00141980 from src/harata/libdk/octfile.cpp
namespace dk {
void OctCollFile::sethitCollPolygonTableAddress(u16* v) {
    reinterpret_cast<OctCollFileLayout*>(this)->hitCollPolygonTableAddress = v;
}
}  // namespace dk

// ---- 00141988 from src/anon/batch_w49.cpp
namespace n00141988 {
union U141988 { u32 v; u16 h; };
struct Idx141988 { u16 f0; u16 a, b, c, d; };
struct Out141988 { U141988 v[4]; U141988 n; };
void func_00141988(u8* o, Idx141988* ix, Out141988* out) asm("func_00141988");
void func_00141988(u8* o, Idx141988* ix, Out141988* out) {                                 
    out->v[0].v = *(u32*)(o + 16) + ix->a * 16;
    out->v[1].v = *(u32*)(o + 16) + ix->b * 16;
    out->v[2].v = *(u32*)(o + 16) + ix->c * 16;
    if (ix->d != 0xffff) {
        out->v[3].v = *(u32*)(o + 16) + ix->d * 16;
        out->n.v = 4;
    } else {
        out->n.v = 3;
    }
}
}  // namespace n00141988

// ---- 001419f8 from src/anon/batch_w3735_nsa.cpp
namespace n001419f8 {
struct FV {
    f32 x, y, z, w;
    FV() {}
    FV(const FV& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    FV& operator=(const FV& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct FM {
    FV r[4];
    FV operator*(const FV& v) const {
        FV o;
        asm volatile("lqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(&v), "r"(this) : "memory");
        return o;
    }
};
struct FTri { u16 x0, v0, v1, v2, v3, plane, x0c, mat; };
struct FPoly { FV* v[4]; s32 n; };
struct FColl {
    u8 pad0[0xc];
    FTri* tris;
    FV* verts;
    u32* mats;
    FV* planes;
    u8 pad1c[0x74];
    FM mtx;
    u8 padd0;
    u8 noMtx;
};
struct FFlags { u64 b0:1; u64 pad:31; u64 hit:1; u64 hi:31; };
struct FRes {
    FV base;
    f32 x10, x14, x18, x1c;
    f32 x20, x24, x28, x2c;
    FV pos;
    u8 pad40[0x20];
    s16 idx;
    u8 pad62[0xa];
    f32 x6c;
    FFlags fl;
    u8 pad78[8];
    f32 x80;
};
void func_00141988(FColl*, FTri*, FPoly*) asm("func_00141988");
s32 func_00163828(FV*, FV*, FV*) asm("func_00163828");
void func_001419f8(FColl* c, u16 idx, FRes* r, FV* p) asm("func_001419f8");
void func_001419f8(FColl* c, u16 idx, FRes* r, FV* p) {
    if (idx == 0xffff) {
        r->fl.hit = 1;
        r->idx = -1;
        return;
    }
    if (r->fl.b0) {
                                                                                                         
                                                              
        FTri* tb = c->tris;
        register u32 off asm("$15") = (u32)idx << 4;
        register FTri* t asm("$20") = (FTri*)((u8*)tb + off);
        asm("" : "+r"(t) : "r"(tb), "r"(off));
        FV* pl = &c->planes[t->plane];
        FPoly poly;
        func_00141988(c, t, &poly);
        FV v = r->pos;
        if (!c->noMtx) v = c->mtx * v;
        if (func_00163828(&v, poly.v[0], pl)) {
            r->fl.hit = 1;
        } else {
            if ((*(u32*)((u8*)c->mats + (t->mat << 2)) & 0xf) == 2) r->fl.hit = 1;
            else r->fl.hit = 0;
            r->pos = *p;
        }
    } else {
        f32 z = 0.0f;
        asm("" : "+f"(z));                                              

        FV q = r->base;
        f32 d = r->x14;
        if (z < d) q.y += d;
        if (q.y + (r->x6c - r->x24) + r->x80 - 1.0f < p->y) {
            r->fl.hit = 1;
        } else {
            r->fl.hit = 0;
            r->pos = *p;
        }
    }
    r->idx = idx;
}
}  // namespace n001419f8

// ---- 00141c18 from src/anon/tiny_auto80_solver.cpp
namespace n00141c18 {
void func_00141c18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00141c18jjjjjjjj");
void func_00141c18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 v3 = a3 & 0xffu;
    *(u32*)(a0 + 64) = a1;
    u32 v4 = a4 & 0xffu;
    *(u32*)(a0 + 68) = a2;
    *(u8*)(a0 + 208) = (u8)v3;
    *(u8*)(a0 + 211) = (u8)v4;
}
}  // namespace n00141c18

// ---- 00141c38 from src/anon/batch_w3775_nsamam.cpp
namespace n00141c38 {
struct TNode { s16 child[8]; u8 box[12]; u16 first; u16 end; };
struct TItem { u8 box[12]; u16 lo; u16 hi; u8 on; u8 pad[3]; };
struct TLeaf { u8 pad[12]; u16 c; u16 idx; };
struct TBox { u8 b[12]; };
struct Tree {
  u8 pad0[4]; TNode* nodes; TItem* items; TLeaf* leafs; u8 pad16[4]; s32* flags; u8 pad24[4]; TBox* boxes;         
  u8 pad32[60-32]; u16* out; s32 mask; s32 val;            
  u8 pad72[208-72]; u8 mode; u8 pad209; u8 b210; u8 b211;
};
s32 func_00145580(void*, void*) asm("func_00145580");
s32 func_0031b940(Tree*, s32, s32*) asm("func_0031b940");
static inline bool okf(Tree* t, s32* f) {
  if (t->mode == 1) return (*f & t->mask) != t->val;
  return (*f & t->mask) == t->val;
}
static inline bool skf(Tree* t, s32* f) {
  bool sk = false;
  if (t->b211 && t->b210) sk = (*f & 0xf) == 5;
  return sk;
}
void dk__OctCollFile__selectPolygon(Tree* t, s32 n, void* box, u16* cnt, s32 arg) asm("dk__OctCollFile__selectPolygon");
void dk__OctCollFile__selectPolygon(Tree* t, s32 n, void* box, u16* cnt, s32 arg) {
  TNode* nd = &t->nodes[n];
  if (!func_00145580(nd->box, box)) return;
   
  s32 ne = nd->end;
  for (s32 i = nd->first; i < ne; i++) {
    TItem* it = &t->items[i];
    if (it->on && func_00145580(it, box)) {
      s32 end = it->hi;
      for (s32 j = it->lo; j < end; j++) {
        TLeaf* lf = &t->leafs[j];
        s32* f = &t->flags[lf->idx];
        if (okf(t, f)) {
          if (skf(t, f) || func_0031b940(t, arg, f)) {
            if (lf->c == 0xffff || func_00145580(&t->boxes[lf->c], box)) {
              if (*cnt >= 1023) return;
              t->out[*cnt] = j;
              (*cnt)++;
            }
          }
        }
      }
    }
  }
  asm("" : : "r"(nd));
  s16* c = nd->child;
  s32 m;
  for (m = 0; m < 8; m++) {
    s32 k = *c++;
    if (k == -1) return;
    dk__OctCollFile__selectPolygon(t, k, box, cnt, arg);
  }
    asm("" : : "r"(ne));
}
}  // namespace n00141c38

// ---- 00141e78 from src/anon/batch_wcx2.cpp
namespace n00141e78 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
struct VB6 {
    f32 x, y, z, w;
    VB6() {}
    VB6(const VB6& s) { QCOPY(this, &s); }
    VB6& operator=(const VB6& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
struct Tri6 { VB6 v[2]; };
struct Face6 { u8 pad[10]; u16 n; u8 pad2[4]; };
struct Mesh6 { u8 pad[12]; Face6* faces; u8 pad2[8]; VB6* norms; u8 pad3[32]; u16* list; };
void func_00141988(Mesh6*, Face6*, Tri6*) asm("func_00141988");
s32 func_001628d8(VB6*, Tri6*, VB6*, VB6*) asm("func_001628d8");
static inline f32 Dist2_6(const VB6& b, const VB6& a)
{
    f32 r;
    asm volatile("lqc2 $vf6, 0(%1)\n\tlqc2 $vf4, 0(%2)\n\tvsub.xyzw $vf5, $vf6, $vf4\n\tvmove.xyzw $vf4, $vf5\n\tvmul.xyz $vf5, $vf4, $vf5\n\t"
                 "vaddy.x $vf5, $vf5, $vf5y\n\tvaddz.x $vf5, $vf5, $vf5z\n\tqmfc2 $2, $vf5\n\tmtc1 $2, %0"
                 : "=f"(r) : "r"(&b), "r"(&a) : "$2", "memory");
    return r;
}
u32 func_00141e78(Mesh6* m, VB6* ray, s32 n, VB6* out) asm("func_00141e78");
u32 func_00141e78(Mesh6* m, VB6* ray, s32 n, VB6* out)
{
    f32 best = 9.99999920e13f;
    u32 id = 0xffff;
    VB6 hit;
    Tri6 tri;
    for (s32 i = 0; i < n; i++) {
        u32 k = m->list[i];
        Face6* f = &m->faces[k];
        func_00141988(m, f, &tri);                                 
        VB6 nrm(m->norms[f->n]);
        if (func_001628d8(ray, &tri, &nrm, &hit)) {
            VB6 a, b;
            a = *ray;
            b = hit;
            f32 d = Dist2_6(b, a);
            if (d < best) {
                best = d;
                *out = hit;
                id = (u16)k;
            }
        }
    }
    return id;
}
}  // namespace n00141e78

// ---- 00141ff0 from src/anon/batch_w2400.cpp
namespace n00141ff0 {
struct V4n {
    f32 x, y, z, w;
    V4n() {}
    V4n(const V4n& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4n& operator=(const V4n& o) {
        if (this == &o) return *this;
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V4n operator-(const V4n& o) const {
        V4n r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct M4n {
    V4n r[4];
    V4n operator*(const V4n& v) const {
        V4n o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
};
struct SegN { V4n a, b; };
struct BoxN { V4n a, b; };
struct ObjN { u8 pad[80]; M4n m80; M4n m144; u8 pad2[1]; u8 b209; };
void func_00144618(BoxN*, SegN*) asm("func_00144618");
void func_00144e30(V4n*) asm("func_00144e30");
u32 func_00141970(ObjN*) asm("func_00141970");
void func_00144e50(V4n*, BoxN*, u32) asm("func_00144e50");
void func_00141980(ObjN*, u8*) asm("func_00141980");
void dk__OctCollFile__selectPolygon(ObjN*, s32, V4n*, u16*, s32) asm("dk__OctCollFile__selectPolygon");
u16 func_00141e78(ObjN*, SegN*, s32, V4n*) asm("func_00141e78");
s32 func_00141ff0(ObjN* o, SegN* ray, V4n* out, u16* id, s32 mask) asm("func_00141ff0");
s32 func_00141ff0(ObjN* o, SegN* ray, V4n* out, u16* id, s32 mask) {
    SegN s = *ray;
    if (!o->b209) {
        s.a = o->m144 * s.a;
        s.b = o->m144 * s.b;
    }
    SegN r2;
    r2.a = s.a;
    r2.b = s.b - s.a;
    r2.b.w = 1.0f;
    r2.a.w = 1.0f;
    BoxN box;
    func_00144618(&box, &s);
    V4n b;
    func_00144e30(&b);
    func_00144e50(&b, &box, func_00141970(o));
    u16 r = 0;
    u8 buf[2048];
    func_00141980(o, buf);
    dk__OctCollFile__selectPolygon(o, 0, &b, &r, mask);
    u16 v = func_00141e78(o, &r2, r, out);
    *id = v;
    if (v == 0xffff) return 0;
    if (o->b209) return 1;
    *out = o->m80 * *out;
    return 1;
}
}  // namespace n00141ff0

// ---- 00142208 from src/anon/batch_w36.cpp
namespace n00142208 {
u32 wtarget_00142208(u32, u32, u32, u32) asm("_Z16wtarget_00142208jjjj");
void func_00141988(u8*, u32, u8*) asm("func_00141988");
struct Out00142208 { u32 v[5]; ~Out00142208() {} };
u32 wtarget_00142208(u32 a0, u32 a1, u32, u32) {
    u8* p = (u8*)a0;
    u16 i = a1;
    static Out00142208 s_out;
    func_00141988(p, *(u32*)(p + 12) + i * 16, (u8*)&s_out);
    return (u32)&s_out;
}
}  // namespace n00142208

// ---- 00142278 from src/anon/tiny_auto80_fptr4.cpp
namespace n00142278 {
u32 func_00142278(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00142278jjjj");
u32 func_00142278(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r14, r15;
    r14 = *(u32*)((u32)r4 + (s32)(12));
    r5 = (u32)(r5 & 0xffffu);
    r5 = (u32)(r5 << 4);
    r2 = *(u32*)((u32)r4 + (s32)(24));
    r14 = (u32)(r14 + r5);
    r15 = (u32)(*(u16*)((u32)r14 + (s32)(10)));
    r15 = (u32)(r15 << 4);
    r2 = (u32)(r2 + r15);
    return r2;
}
}  // namespace n00142278

// ---- 001422a0 from src/anon/batch_w91.cpp
namespace n001422a0 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Mc {
    Vq r[4];
    Mc() {}
    Mc(const Mc& o) { asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory"); }
} __attribute__((aligned(16)));
Vq* func_001422a0(Vq* out, u8* obj, u16 idx) asm("func_001422a0");
Vq* func_001422a0(Vq* out, u8* obj, u16 idx) {                           
    u8* e = *(u8**)(obj + 12) + idx * 16;
    *out = *(Vq*)(*(u8**)(obj + 24) + *(u16*)(e + 10) * 16);
    out->w = 1.0f;
    if (!obj[209]) {
        Mc m(*(Mc*)(obj + 80));
        asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&m.r[3]) : "memory");
        Vq t;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                     "sqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&t), "r"(out), "r"(&m) : "memory");
        *out = t;
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                     : "=f"(len) : "r"(out) : "$8", "memory");
    }
    return out;
}
}  // namespace n001422a0

// ---- 00142398 from src/harata/libdk/octfile.cpp
namespace dk {
u32 OctCollFile::getAttr(u16 idx) {
    u32 r14 = *(u32*)((u32)this + 12);
    u32 r5 = ((u32)idx & 0xffffu) << 4;
    u32 r2 = *(u32*)((u32)this + 20);
    r14 = r14 + r5;
    u32 r15 = (u32)(*(u16*)((u32)r14 + 14));
    r15 = r15 << 2;
    r2 = r2 + r15;
    return r2;
}
}  // namespace dk

// ---- 001423c0 from src/anon/batch_w90.cpp
namespace n001423c0 {
struct FV {
    f32 x, y, z, w;
    FV() {}
    FV& operator=(const FV& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M44 { FV r[4]; };
static inline FV MulMV(const M44* m, const FV* v)
{
    FV out;
    asm volatile(
        "lqc2 $vf5, 0(%1)\n\t"
        "lqc2 $vf1, 0(%2)\n\t"
        "lqc2 $vf2, 16(%2)\n\t"
        "lqc2 $vf3, 32(%2)\n\t"
        "lqc2 $vf4, 48(%2)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\t"
        "vmadday.wxyz ACC, $vf2, $vf5y\n\t"
        "vmaddaz.wxyz ACC, $vf3, $vf5z\n\t"
        "vmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
        "sqc2 $vf5, 0(%0)"
        : : "r"(&out), "r"(v), "r"(m) : "memory");
    return out;
}
struct PtrList { FV* p[4]; s32 n; };
void func_00141988(void*, void*, PtrList*) asm("func_00141988");
u32 wtarget_001423c0(u8* self, u32 a1, FV* out, u32) asm("_Z16wtarget_001423c0jjjj");
u32 wtarget_001423c0(u8* self, u32 a1, FV* out, u32)
{
    u16 i = a1;
    if (i == 0xffff) return 0;
    PtrList l;
    func_00141988(self, *(u8**)(self + 12) + i * 16, &l);                                 
    s32 n = l.n;
    if (self[209]) {
        for (s32 k = 0; k < n; k++) *out++ = *l.p[k];
    } else {
        for (s32 k = 0; k < n; k++) *out++ = MulMV((M44*)(self + 80), l.p[k]);
    }
    return n;
}
}  // namespace n001423c0

// ---- 001424c0 from src/anon/batch_w292.cpp
namespace n001424c0 {
#define QCOPY142(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV142 {
    f32 x, y, z, w;
    QV142() {}
    QV142(const QV142& o) { QCOPY142(this, &o); }
    QV142& operator=(const QV142& o) {
        if (this != &o) QCOPY142(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Seg142 {
    QV142 a, b;
    Seg142(const QV142& p, const QV142& q) { a = p; b = q; }
};
static inline f32 clamp142(f32 v, f32 lo, f32 hi) { if (v < lo) return lo; if (hi < v) return hi; return v; }
struct Obj142 {
    u8 pad[20]; f32 rad; u8 pad2[48 - 24]; QV142 pos; u8 pad3[104 - 64]; f32 f104; f32 h;
    u64 lo : 3; u64 kind : 4; u64 mid : 26; u64 miss : 1; u64 hi : 30;
};
f32 fabsf(f32) asm("fabsf");
void func_00141c18(void*, s32, s32, s32, s32) asm("func_00141c18");
s32 func_00141ff0(void*, Seg142*, QV142*, s16*, s32) asm("func_00141ff0");
void func_001419f8(void*, u16, Obj142*, QV142) asm("func_001419f8");
s32 func_001424c0(void* self, Obj142* o) asm("func_001424c0");
s32 func_001424c0(void* self, Obj142* o)
{
    QV142 p(o->pos);
    QV142 q(o->pos);
    f32 r = fabsf(o->rad);          
    if (o->kind == 0) r = clamp142(r, 0.0f, 100.0f);
    p.y = p.y - o->h - r;
    q.y = q.y + o->h * 3.0f;
    Seg142 seg(p, q);
    QV142 out;
    s16 hit = -1;
    func_00141c18(self, 15, 4, 1, 0);
    if (func_00141ff0(self, &seg, &out, &hit, (s32)(*(u64*)((u8*)o + 112) >> 3) & 0xf)) {
        o->miss = 0;
        o->f104 = out.y;
        func_001419f8(self, hit, o, out);
        return 1;
    }
    o->miss = 1;
    o->f104 = 320000.0f;
    func_001419f8(self, hit, o, o->pos);
    return 0;
}
}  // namespace n001424c0

// ---- 00142688 from src/anon/batch_w1957_nsa.cpp
namespace n00142688 {
struct W1957V {
    f32 x, y, z, w;
    W1957V() {}
    W1957V(const W1957V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    W1957V& operator=(const W1957V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1957Face { u8 pad[10]; u16 plane; u8 pad2[4]; };
struct W1957Hit { u8 d[32]; };
struct W1957Map {
    u8 pad0[12];
    W1957Face* faces;             
    u8 pad10[8];
    W1957V* planes;               
    u8 pad1c[32];
    u16* list;                    
};
struct W1957Who { u8 pad[48]; W1957V pos; u8 pad40[44]; f32 height; };
void func_00141988(W1957Map*, W1957Face*, W1957Hit*) asm("func_00141988");
s32 func_00162408(W1957Hit*, W1957V*) asm("func_00162408");
f32 fabsf(f32) asm("fabsf");
static inline f32 w1957_dot(const W1957V& a, const W1957V& b) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
s32 func_00142688(W1957Map* map, f32* out, s32 n, W1957Who* who) asm("func_00142688");
s32 func_00142688(W1957Map* map, f32* out, s32 n, W1957Who* who) {
    f32 best = 10000000.0f;
    u16 res = 0xffff;
    W1957V v;
    W1957V t;
    v = t = who->pos;
    t.y -= who->height;
    for (s32 i = 0; i < n; i++) {
        s32 id = map->list[i];
        W1957Face* f = &map->faces[id];
        W1957V* pl = &map->planes[f->plane];
        if (w1957_dot(t, *pl) + pl->w < 0.0f) continue;
        W1957Hit hit;
        func_00141988(map, f, &hit);
        if (!func_00162408(&hit, &v)) continue;
        f32 y = (-pl->w - (pl->x * v.x + pl->z * v.z)) / pl->y;
        f32 a = fabsf(t.y - y);
        if (a < best) {
            best = a;
            res = id;
            *out = y;
        }
    }
    return res;
}
}  // namespace n00142688

// ---- 00142848 from src/anon/batch_wcx.cpp
namespace n00142848 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Seg { V4 a, b; };
void func_00144490(Seg*, f32, f32, f32, f32, f32, f32) asm("func_00144490");
void func_00144e30(V4*) asm("func_00144e30");
u32 func_00141970(u8*) asm("func_00141970");
void func_00144e50(V4*, Seg*, u32) asm("func_00144e50");
void func_00141c18(u8*, s32, s32, s32, s32) asm("func_00141c18");
void dk__OctCollFile__selectPolygon(u8*, s32, V4*, u16*, s32) asm("dk__OctCollFile__selectPolygon");
u16 dk__OctCollFile__selectDownAllPolygon(u8* o, u8* p) asm("dk__OctCollFile__selectDownAllPolygon");
u16 dk__OctCollFile__selectDownAllPolygon(u8* o, u8* p)
{
    Seg a;
    V4 b;
    func_00144490(&a, *(f32*)(p + 48), *(f32*)(p + 52) - *(f32*)(p + 108), *(f32*)(p + 56), *(f32*)(p + 48), *(f32*)(p + 52) + 320000.0f, *(f32*)(p + 56));
    func_00144e30(&b);                     
    func_00144e50(&b, &a, func_00141970(o));
    u16 r = 0;
    func_00141c18(o, 0, 0, 0, 0);
    dk__OctCollFile__selectPolygon(o, 0, &b, &r, 15);
    return r;
}
}  // namespace n00142848

// ---- 00142900 from src/anon/batch_w15.cpp
namespace n00142900 {
int func_00141970(void*, u32) asm("func_00141970");
void func_001450e8(void*, int, u32) asm("func_001450e8");
void func_00142900(u8* p, u32 a, u32 b) asm("func_00142900");
void func_00142900(u8* p, u32 a, u32 b) {
    u8* q = *(u8**)(p + 4);
    int r = func_00141970(p, a);                 
    func_001450e8(q + 16, r, b);
}
}  // namespace n00142900

// ---- 00142940 from src/anon/batch_w112.cpp
namespace n00142940 {
struct Mtx { f32 m[16]; } __attribute__((aligned(16)));
static inline void MtxCopy(Mtx* d, const Mtx* s) {
    if (d != s)
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void MtxInverse(Mtx* m) {
    asm volatile(
        "lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
        "vopmula.xyz ACC, $vf2, $vf3\n\tvopmsub.xyz $vf5, $vf3, $vf2\n\t"
        "vopmula.xyz ACC, $vf3, $vf1\n\tvopmsub.xyz $vf6, $vf1, $vf3\n\t"
        "vopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf7, $vf2, $vf1\n\t"
        "vmul.xyz $vf8, $vf1, $vf5\n\tvmul.xyz $vf1, $vf4, $vf5\n\tvmul.xyz $vf2, $vf4, $vf6\n\tvmul.xyz $vf3, $vf4, $vf7\n\t"
        "vaddy.x $vf8, $vf8, $vf8y\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddx.y $vf2, $vf2, $vf2x\n\tvaddx.z $vf3, $vf3, $vf3x\n\t"
        "vaddz.x $vf8, $vf8, $vf8z\n\tvaddz.x $vf4, $vf1, $vf1z\n\tvaddz.y $vf4, $vf2, $vf2z\n\tvaddy.z $vf4, $vf3, $vf3y\n\t"
        "vdiv Q, $vf0w, $vf8x\n\t"
        "qmfc2 $8, $vf5\n\tqmfc2 $9, $vf6\n\tqmfc2 $10, $vf7\n\tqmfc2 $11, $vf0\n\t"
        "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
        "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
        "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
        "vsub.xyz $vf4, $vf0, $vf4\n\tvwaitq\n\t"
        "vmulq.xyzw $vf1, $vf1, Q\n\tvmulq.xyzw $vf2, $vf2, Q\n\tvmulq.xyzw $vf3, $vf3, Q\n\tvmulq.xyz $vf4, $vf4, Q\n\t"
        "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)"
        : : "r"(m) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}
struct Xf { u8 pad[80]; Mtx world; Mtx inv; u8 pad3[1]; u8 identity; };
void func_00142940(Xf* o, Mtx* m) asm("func_00142940");
void func_00142940(Xf* o, Mtx* m) {
    o->identity = 0;
    if (m->m[0] == 1.0f && m->m[1] == 0.0f && m->m[2] == 0.0f && m->m[3] == 0.0f &&
        m->m[4] == 0.0f && m->m[5] == 1.0f && m->m[6] == 0.0f && m->m[7] == 0.0f &&
        m->m[8] == 0.0f && m->m[9] == 0.0f && m->m[10] == 1.0f && m->m[11] == 0.0f &&
        m->m[12] == 0.0f && m->m[13] == 0.0f && m->m[14] == 0.0f && m->m[15] == 1.0f)
        o->identity = 1;
    MtxCopy(&o->world, m);
    MtxInverse(m);
    MtxCopy(&o->inv, m);
}
}  // namespace n00142940

// ---- 00142b70 from src/anon/batch_w61.cpp
namespace n00142b70 {
static inline f32 lsq(const void* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(v) : "$8");
    return r;
}
s32 func_00142b70(u8* p) asm("func_00142b70");
s32 func_00142b70(u8* p) {                        
    if (lsq(p + 80) < 0.01f || lsq(p + 96) < 0.01f || lsq(p + 112) < 0.01f) return 1;
    return 0;
}
}  // namespace n00142b70

// ---- 00142bf8 from src/anon/batch_wcx2.cpp
namespace n00142bf8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
void func_00134668(void* p) asm("func_00134668");
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));
void func_0014ed28(u32, s32) asm("func_0014ed28");
void func_00142bf8(u8* p) asm("func_00142bf8");
void func_00142bf8(u8* p) {
    for (s32 i = 0; i < *(s32*)(p + 40); i++) {
        u8* e = *(u8**)(p + 12);
        e += i * 16;
        u32* t = *(u32**)(p + 20);
        t += *(u16*)(e + 14);
        u32 w = *t;
        if (w & 0x60000) func_0014ed28((w >> 17) & 3, i);
    }
}
}  // namespace n00142bf8


// 0x36aefc: jump table of the switch in the out-of-line inline flag test at 0x31b940
// (called from 0x141c38). It sits at the end of this file's .rodata.
extern "C" const u32 D_0036aefc[16] __attribute__((aligned(4))) = {
    0x0031b9c0, 0x0031b964, 0x0031b978, 0x0031b984, 0x0031b9a8, 0x0031b9b4, 0x0031b9c0, 0x0031b9cc,
    0x0031b9cc, 0x0031b9cc, 0x0031b9cc, 0x0031b9cc, 0x0031b9cc, 0x0031b9cc, 0x0031b9cc, 0x0031b9d4,
};
