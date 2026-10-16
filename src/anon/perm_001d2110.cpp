/* found by decomp-permuter (nightly.py) */
extern "C" {


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
inline u8 *inline_fn(void *arg0)
{
  return (u8 *) arg0;
}

void func_001d2110(void *p, s32 n)
{
  s32 new_var;
  s32 max = *((s32 *) (((u8 *) p) + 24));
  s32 lt = n < max;
  if (n <= 0)
  {
    n = 0;
  }
  if (!lt)
  {
    if (n)
    {
      n = max;
    }
    else
    {
      new_var = max;
      n = new_var;
    }
  }
  *((s32 *) (inline_fn(p) + 44)) = n;
}

}
