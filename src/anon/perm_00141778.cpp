/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct R R;
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

}
