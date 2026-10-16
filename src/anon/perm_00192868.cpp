/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct A192868 A192868;
typedef struct B192868 B192868;
typedef struct R192868 R192868;
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
typedef struct A192868 A192868;
typedef struct B192868 B192868;
typedef struct R192868 R192868;
struct A192868
{
  u8 pad[20];
  s32 x14;
};
struct B192868
{
  u8 pad[12];
  s32 c;
};
struct R192868
{
  u32 max;
  s32 sum;
};
u8 *func_00192800(u8 *, A192868 *, B192868 *, R192868 *);
void func_00192388(u8 *);
void func_00192868(u8 *n, A192868 *a, B192868 *b, R192868 *out)
{
  R192868 tmp;
  s32 k;
  s32 k2;
  tmp.max = 0;
  tmp.sum = 0;
  out->max = 0;
  out->sum = 0;
  while (n != 0)
  {
    n = func_00192800(n, a, b, &tmp);
    out->max = (tmp.max < out->max) ? (out->max) : (tmp.max);
    k = b->c + a->x14;
    out->sum = (out->sum + tmp.sum) + k;
    if (n == 0)
    {
      break;
    }
    if ((*n) == 16)
    {
      if (a)
      {
        func_00192388(n);
        break;
      }
      else
      {
        func_00192388(n);
        break;
      }
    }
  }

  k2 = a->x14 + b->c;
  out->sum -= k2;
}

}
