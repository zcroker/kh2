
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;
typedef float f32;
union BD_VALUE
{
  s32 i;
  f32 f;
  void *p;
  u32 u;
};
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
extern s32 D_01d9eab4;
extern s32 D_01d9ea9c;
extern W2426Mgr *D_01d9e6e0;
extern W2426Tab *D_01d9e6e4;
extern W2426Cam *D_01d9e6e8;
s32 func_00222568(void);
W2426Ent *func_001e7a98(W2426Mgr *, u8 *);
void func_001f6148(void *, W2426Prm *, s16 *);
void func_0021ee48(void *, W2426Prm *, W2426CB, u16 *, s16, u8, u8);
void sceVu0ApplyMatrix(void *, void *, void *);
void func_002226b8(void *, void *);
void sceVu0SubVector(void *, void *, void *);
void sceVu0Normalize(void *, void *);
void sceVu0ScaleVector(void *, void *, f32);
void func_001f6298(void *owner, W2426Prm *prm, W2426Ctx *c)
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
    func_0021ee48(owner, prm, func_001f6148, (u16 *) ((((u8 *) owner) + (*c->ofs)) + 160), prm->g0, prm->rnd, prm->n);
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

