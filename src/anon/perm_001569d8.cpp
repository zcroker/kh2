/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct W1633Gauge W1633Gauge;
typedef struct W1633Hud W1633Hud;
typedef struct W1633Owner W1633Owner;
typedef struct W1633Owner2 W1633Owner2;
typedef struct W1633Sprite W1633Sprite;
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
typedef struct W1633Sprite W1633Sprite;
struct W1633Sprite
{
  u8 pad0[0x188];
  s32 id;
  W1633Sprite *parent;
  s32 flag;
  u8 pad1[8];
};
typedef struct W1633Gauge W1633Gauge;
struct W1633Gauge
{
  u8 pad0[0x20];
  u8 barA[0x120];
  u8 barB[0x100];
  W1633Sprite *parent;
  u8 pad1[0xc];
};
typedef struct W1633Owner2 W1633Owner2;
struct W1633Owner2
{
  u8 pad[0x250];
  u32 flags;
};
typedef struct W1633Owner W1633Owner;
struct W1633Owner
{
  u8 pad[0x48c];
  W1633Owner2 *sub;
};
typedef struct W1633Hud W1633Hud;
struct W1633Hud
{
  u8 pad0[0x18];
  u32 f18;
  u8 pad1[0x34 - 0x1c];
  W1633Owner *owner;
  u8 pad2[8];
  W1633Sprite header;
  u8 pad3[0x1a30 - 0x1dc];
  W1633Sprite spr[12];
  u8 pad4[0x33b0 - 0x2d80];
  W1633Gauge gauge[4];
  u8 pad5[0x3cf0 - 0x3cf0];
  s32 f3cf0;
  s8 b3cf4;
  s8 b3cf5;
  s8 b3cf6;
  s8 b3cf7;
  s8 b3cf8;
  s8 b3cf9;
  s8 b3cfa;
  s8 b3cfb;
};
void func_00158138(W1633Hud *, W1633Owner *, u32, u32);
u32 func_0013a7e8(u32);
u32 func_0013d7e0(void);
u32 func_00158290(W1633Hud *);
volatile unsigned char func_00158050(W1633Sprite *, u32, u32, u32, u32, u32, u32);
void func_0013e0f8(W1633Gauge *, u32, u32, u32);
void func_00139d78(void *);
void func_0014b200(void *, u32);
void func_001581f8(W1633Hud *);
void func_001565c0(W1633Hud *, u32, u32, u32);
void func_00153fa0(W1633Sprite *, u32, u32, W1633Owner *, u32, u32);
void func_00156880(W1633Hud *, u32, u32, u32);
void func_00156130(W1633Hud *, u32, u32, u32);
void func_001564b0(W1633Hud *, u32, u32, u32);
void func_001582a8(W1633Hud *);
s32 func_00155d58(W1633Hud *, u32);
void func_001396b0(W1633Sprite *);
void func_0031a260(W1633Sprite *, u32);
void func_001395e8(W1633Sprite *);
void func_00139610(W1633Sprite *);
inline static void W1633_setParent(W1633Sprite *obj, W1633Sprite *parent)
{
  obj->parent = parent;
  func_001396b0(obj);
  if (obj->parent != 0)
  {
    obj->flag = 0;
    func_001396b0(obj);
    if (obj->flag != 0)
    {
      func_0031a260(obj, 0);
    }
  }
}

void func_001569d8(W1633Hud *self, W1633Owner *owner)
{
  u32 a;
  u32 b;
  u32 c;
  s32 j;
  W1633Sprite *top = &self->spr[0];
  W1633Sprite *sub;
  W1633Gauge *g;
  func_00158138(self, owner, 0, 0);
  a = func_0013a7e8(1);
  b = func_0013d7e0();
  c = func_00158290(self);
  self->b3cf6 = 0;
  self->b3cf4 = -1;
  self->b3cf5 = -1;
  self->b3cf7 = 0;
  self->b3cf8 = 0;
  self->b3cf9 = 0;
  self->f3cf0 = 0;
  self->b3cfa = 0;
  self->b3cfb = 0;
  func_00158050(top, 7000, a, b, 136, 0, c);
  func_0013e0f8(&self->gauge[0], 7000, 0, c);
  func_00139d78(&self->gauge[0]);
  func_0014b200(self->gauge[0].barA, 0);
  func_0014b200(self->gauge[0].barB, 0);
  func_001581f8(self);
  func_001565c0(self, a, b, c);
  func_00153fa0(&self->header, 7000, 0, self->owner, self->f18, c);
  func_00156880(self, a, b, c);
  for (s32 i = 0; i < 12; i++)
  {
    W1633_setParent(&self->spr[i], top);
    func_001395e8(&self->spr[i]);
    func_00139610(&self->spr[i]);
  }

  for (j = 0; j < 4; j++)
  {
    g = &self->gauge[j];
    func_00139d78(g);
    g->parent = top;
  }

  W1633_setParent(&self->header, top);
  sub = &self->spr[8];
  W1633_setParent(&self->spr[9], sub);
  W1633_setParent(&self->spr[10], sub);
  W1633_setParent(&self->spr[11], sub);
  W1633_setParent(top, 0);
  top->id = func_00155d58(self, 0);
  sub->id = 117;
  func_00156130(self, a, b, c);
  func_001564b0(self, a, b, c);
  func_001582a8(self);
}

}
