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
s32 func_002b3c38(void);
s32 PlaySE_2b0(s32, s32) asm("_ZN2Tz9MenuSound6PlaySEEib");
s32 func_002b0de0(u32 a)
{
  u32 *new_var;
  s32 r;
  u32 m = a & 0xc00f0;
  int new_var2;
  if (m)
  {
    r = 1;
  }
  else
    if ((new_var2 = a) & 8)
  {
    r = 3;
  }
  else
    if (((unsigned char) a) & 4)
  {
    r = 2;
  }
  else
  {
    new_var = &a;
    if ((*new_var) & 0x100)
    {
      r = 5;
    }
    else
    {
      new_var2 = a;
      if (new_var2 & 0x32000)
      {
        r = 2;
      }
      else
      {
        r = 0;
      }
    }
  }
  if (!func_002b3c38())
  {
    r = 4;
  }
  if (r)
  {
    r = PlaySE_2b0(r, 1);
  }
  return r;
}

}
