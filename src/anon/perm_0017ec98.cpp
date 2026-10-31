/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Chr Chr;
typedef struct Obj Obj;
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
extern u8 D_0036c5e0[][4];
s32 func_0017ebc8(Obj *);
s32 func_0019bf00(Chr *);
s32 func_00176258(Chr *);
s32 func_001a97b8(void *, s32) asm("_ZNK2YS9MOTIONSET9is_playerEv");
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

}
