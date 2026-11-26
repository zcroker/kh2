// Linked unit 0x001f6298-0x001f6868 (ppp programs; one namespace per old matched source, gap functions written for the unit).
#include "../common/types.h"

// 001f6298 (was src/anon/batch_w3779_nsamam.c)
namespace n001f6298 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
  f32 w;
} W2426Vec;
typedef struct 
{
  s16 x;
  s16 y;
  s16 z;
} W2426Pt;
typedef struct 
{
  u8 pad[0x80];
  u8 *tbl;
  u8 pad84[0x24];
  u64 flags;
} W2426Mgr;
typedef struct 
{
  u8 pad[0x10];
  f32 m0[12];
  f32 m1[4];
  u8 pad50[0x40];
  W2426Pt *pts;
} W2426Cam;
typedef struct 
{
  u8 pad[4];
  void *owner;
} W2426Ent;
typedef struct 
{
  s16 a;
  s16 cnt;
  u16 *list;
} W2426Grp;
typedef struct 
{
  u8 pad[0x14];
  W2426Pt *pts;
  u8 pad18[0xc];
} W2426Mdl;
typedef struct 
{
  u8 pad[0x10];
  W2426Mdl *mdl;
  u8 pad14[4];
  W2426Grp *grp;
} W2426Tab;
typedef struct 
{
  u8 pad[4];
  s16 g0;
  u8 pad6[2];
  f32 scale;
  u8 n;
  u8 mask;
  u8 rnd;
  u8 padf;
  s32 idx;
  s32 o14;
  s32 i18;
  s32 o1c;
  s32 i20;
  s32 o24;
} W2426Prm;
typedef struct 
{
  u8 pad[0xc];
  s32 *ofs;
} W2426Ctx;
typedef void (*W2426CB)(void *, W2426Prm *, s16 *);
extern s32 D_01d9eab4 asm("D_01d9eab4");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern W2426Mgr *D_01d9e6e0 asm("D_01d9e6e0");
extern W2426Tab *D_01d9e6e4 asm("D_01d9e6e4");
extern W2426Cam *D_01d9e6e8 asm("D_01d9e6e8");
s32 func_00222568(void) asm("func_00222568");
W2426Ent *func_001e7a98(W2426Mgr *, u8 *) asm("func_001e7a98");
void pppKeBornRnd4_Born(void *, W2426Prm *, s16 *) asm("pppKeBornRnd4_Born");
void func_0021ee48(void *, W2426Prm *, W2426CB, u16 *, s16, u8, u8) asm("func_0021ee48");
void sceVu0ApplyMatrix(void *, void *, void *) asm("sceVu0ApplyMatrix");
void func_002226b8(void *, void *) asm("func_002226b8");
void sceVu0SubVector(void *, void *, void *) asm("sceVu0SubVector");
void sceVu0Normalize(void *, void *) asm("sceVu0Normalize");
void sceVu0ScaleVector(void *, void *, f32) asm("sceVu0ScaleVector");
/*TARGET 001f6298*/
void pppKeBornRnd4(void *owner, W2426Prm *prm, W2426Ctx *c) asm("pppKeBornRnd4");
void pppKeBornRnd4(void *owner, W2426Prm *prm, W2426Ctx *c)
{
  W2426Grp *g;
  u8 *base;
  u16 *slot;
  W2426Pt *pts;
  s32 r;
  s32 rnd;
  s32 idx;
  s32 n;
  W2426Vec v;
  if (D_01d9eab4 != 0)
  {
    return;
  }
  if (D_01d9ea9c != 0)
  {
    return;
  }
  if (((!(D_01d9e6e0->flags & 0xff0000ff00ULL)) && (prm->mask != 255)) && (!((func_00222568() >> 8) & prm->mask)))
  {
    if (prm->idx == (-1))
    {
      return;
    }
    if (prm->i18 == (-1))
    {
      return;
    }
    if (prm->i20 == (-1))
    {
      return;
    }
    func_0021ee48(owner, prm, pppKeBornRnd4_Born, (u16 *) ((((u8 *) owner) + (*c->ofs)) + 160), prm->g0, prm->rnd, prm->n);
  }
  if (D_01d9ea9c != 0)
  {
    return;
  }
  if (__builtin_expect(D_01d9e6e0->flags & 0xff0000ff00ULL, 0))
  {
    return;
  }
  r = func_00222568();
  if (prm->mask == 255)
  {
    return;
  }
  if ((r >> 8) & prm->mask)
  {
    return;
  }
  if (prm->idx == (-1))
  {
    return;
  }
  if (prm->i18 == (-1))
  {
    return;
  }
  if (prm->i20 == (-1))
  {
    return;
  }
  base = ((u8 *) owner) + (*c->ofs);
  slot = (u16 *) (base + 160);
  g = &D_01d9e6e4->grp[prm->g0];
  pts = D_01d9e6e8->pts;
  if (pts == 0)
  {
    pts = D_01d9e6e4->mdl[g->a].pts;
  }
  rnd = prm->rnd;
  if (rnd != 0)
  {
    idx = r % g->cnt;
  }
  else
  {
    idx = *slot;
  }
  for (n = prm->n; n > 0; n--)
  {
    W2426Ent *e = 0;
    f32 w = 1.0f;
    u8 *t = D_01d9e6e0->tbl + (prm->idx * 16);
    W2426Pt *p;
    u8 *p0;
    u8 *p1;
    u8 *p2;
    if (t != 0)
    {
      e = func_001e7a98(D_01d9e6e0, t);
      e->owner = owner;
    }
    p = &pts[g->list[idx++]];
    p0 = (((u8 *) e) + prm->o14) + 160;
    p2 = (((u8 *) e) + prm->o1c) + 160;
    p1 = (((u8 *) e) + prm->o24) + 160;
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    v.w = w;
    sceVu0ApplyMatrix(&v, D_01d9e6e8->m0, &v);
    func_002226b8(p0, &v);
    sceVu0SubVector(&v, &v, D_01d9e6e8->m1);
    sceVu0Normalize(&v, &v);
    func_002226b8(p1, &v);
    sceVu0ScaleVector(&v, &v, prm->scale);
    func_002226b8(p2, &v);
    if (rnd != 0)
    {
      idx = func_00222568() % g->cnt;
    }
    else
      if (!(idx < g->cnt))
    {
      idx = 0;
    }
  }

  *slot = idx;
}
}  // namespace n001f6298

// 001f6630 (gap, written for the unit)
namespace n001f6630 {
void func_001f6630(u8* self, u8* t) asm("func_001f6630");
void func_001f6630(u8* self, u8* t) {
    *(s16*)(self + **(s32**)(t + 12) + 0xa0) = 0;
}
}  // namespace n001f6630

// 001f6648 (was src/anon/batch_w1833_nsa.cpp)
namespace n001f6648 {
// 001081c8: moved to src/anon/unit_00108068.cpp
struct W1833Vec { f32 x, y, z, w; };
struct W1833Mgr { u8 pad[0x80]; u8* tbl; };
struct W1833Cam { u8 pad[0x10]; f32 m0[12]; f32 m1[4]; };
struct W1833Ent { u8 pad[4]; void* owner; };
struct W1833Prm { u8 pad[8]; f32 scale; u8 padc[4]; s32 idx; s32 o20; u8 pad18[4]; s32 o28; };
extern W1833Mgr* D_01d9e6e0 asm("D_01d9e6e0");
extern W1833Cam* D_01d9e6e8 asm("D_01d9e6e8");
W1833Ent* func_001e7a98(W1833Mgr*, u8*) asm("func_001e7a98");
void sceVu0ApplyMatrix(W1833Vec*, void*, W1833Vec*) asm("sceVu0ApplyMatrix");
void func_002226b8(void*, W1833Vec*) asm("func_002226b8");
void sceVu0SubVector(W1833Vec*, W1833Vec*, void*) asm("sceVu0SubVector");
void sceVu0Normalize(W1833Vec*, W1833Vec*) asm("sceVu0Normalize");
void sceVu0ScaleVector(W1833Vec*, W1833Vec*, f32) asm("sceVu0ScaleVector");
/*TARGET 001f6648*/
void pppKeBornRnd5_Born(void* owner, W1833Prm* prm, s16* pos) asm("pppKeBornRnd5_Born");
void pppKeBornRnd5_Born(void* owner, W1833Prm* prm, s16* pos) {
    W1833Ent* e = 0;
    u8* t = D_01d9e6e0->tbl + prm->idx * 16;
    if (t != 0) {
        e = func_001e7a98(D_01d9e6e0, t);
        e->owner = owner;
    }
    u8* p1 = (u8*)e + prm->o28 + 160;
    u8* p0 = (u8*)e + prm->o20 + 160;
    W1833Vec v;
    v.x = pos[0];
    v.y = pos[1];
    v.z = pos[2];
    v.w = 1.0f;
    sceVu0ApplyMatrix(&v, D_01d9e6e8->m0, &v);
    func_002226b8(p0, &v);
    sceVu0SubVector(&v, &v, D_01d9e6e8->m1);
    sceVu0Normalize(&v, &v);
    sceVu0ScaleVector(&v, &v, prm->scale);
    func_002226b8(p1, &v);
}
}  // namespace n001f6648

// 001f6778 (was src/anon/batch_w91.cpp)
namespace n001f6778 {
// 0x001ead10: definition moved into src/anon/unit_001e8ac8.cpp

// --- 001f6778
extern u32 D_01d9eab4 asm("D_01d9eab4");
extern u32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_001f6648[] asm("D_001f6648");
struct A1f { u8 pad[4]; s16 h; u8 pad2[6]; u8 b12; u8 b13:8; u8 b14; u8 pad3; s32 w16; u32 pad4; s32 w24; };
struct S1f { u8 pad[2]; u8 cnt:8; };
void func_0021ee48(u8*, A1f*, u8*, S1f*, s32, u32, u32) asm("func_0021ee48");
/*TARGET 001f6778*/
void func_001f6778(u8* base, A1f* a1, u8* a2) asm("func_001f6778");
void func_001f6778(u8* base, A1f* a1, u8* a2) {
    if (D_01d9eab4) return;
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0x000000ff0000ff00ULL) return;
    if (!a1->b13) return;
    S1f* s = (S1f*)(base + **(u32**)(a2 + 12) + 160);
    if (s->cnt == 0) {
        s->cnt = a1->b13;
        if (a1->w16 == -1) return;
        if (a1->w24 == -1) return;
        func_0021ee48(base, a1, D_001f6648, s, a1->h, a1->b14, a1->b12);
    }
    s->cnt--;
}
}  // namespace n001f6778

// 001f6850 (gap, written for the unit)
namespace n001f6850 {
struct S { s16 a; u8 b; };
void func_001f6850(u8* self, u8* t) asm("func_001f6850");
void func_001f6850(u8* self, u8* t) {
    S* s = (S*)(self + **(s32**)(t + 12) + 0xa0);
    s->a = 0;
    s->b = 0;
}
}  // namespace n001f6850

