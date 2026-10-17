/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Ent3 Ent3;
typedef struct Sub Sub;
typedef struct Sub12 Sub12;
typedef struct SubVt SubVt;
typedef struct T T;
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
typedef struct Sub Sub;
typedef struct SubVt SubVt;
typedef struct Ent3 Ent3;
typedef struct Sub12 Sub12;
typedef struct T T;
struct Sub;
struct SubVt
{
  u8 pad[32];
  void (*fn)(Sub *);
};
struct Sub
{
  SubVt *vt;
  u8 pad[108];
  s32 state;
};
struct Ent3
{
  u8 b0;
  u8 b1;
  u8 b2;
};
struct Sub12
{
  u32 bit : 1;
  u8 pad[28];
  s32 f32;
};
struct T
{
  u8 pad0[12];
  Sub12 s12;
  u8 pad1[(112 - 12) - (sizeof(Sub12))];
  s32 state;
  u8 pad2[132 - 116];
  u8 s132[476 - 132];
  s32 f476;
  u8 s480[1192 - 480];
  Sub *f1192;
  u8 s1196[4];
};
extern Ent3 D_00350a38[];
s32 func_00167f18(s32);
s32 func_00239d10(void *);
void func_00239bf8(void *, u32);
void func_001aa558(void *);
void func_001abdf0(void *, s32);
void func_001abe80(void *, T *, s32);
void func_001ac728(T *);
void func_001ac0d0(void *);
s32 func_001ac1d0(void *);
inline static u8 isEnd(Sub *s)
{
  return s->state == 3;
}

void func_001acbc0(T *t)
{
  s32 r = func_00167f18(0);
  int new_var;
  switch (t->state)
  {
    case 0:
      if (func_00239d10(t->s132))
    {
      return;
    }
      func_00239bf8(t->s132, D_00350a38[t->f476].b1);
      t->state = 1;
      break;

    case 1:
    {
      Sub12 *q = &t->s12;
      if (!((u8) q->bit))
      {
        return;
      }
      func_001aa558(q);
      if (t->f1192)
      {
        func_001abdf0(t->s480, 0);
      }
      else
        if (q->f32 > 0)
      {
        func_001abdf0(t->s480, 2);
      }
      else
      {
        func_001abdf0(t->s480, 1);
      }
      t->state = 2;
      break;
    }

    case 2:
    {
      Sub *s = t->f1192;
      new_var = 0 == s;
      if (new_var)
      {
        func_001abe80(t->s480, t, r);
        return;
      }
      if (isEnd(s))
      {
        s->vt->fn(s);
        func_001ac728(t);
      }
      return;
    }

    case 3:
      return;

    case 4:
      func_001ac0d0(t->s1196);
      t->state = 5;
      break;

    case 5:
      if (func_001ac1d0(t->s1196))
    {
      return;
    }
      func_00239bf8(t->s132, D_00350a38[t->f476].b2);
      t->state = 6;
      break;

    case 6:
      if (func_00239d10(t->s132))
    {
      return;
    }
      t->state = 7;
      break;

  }

}

}
