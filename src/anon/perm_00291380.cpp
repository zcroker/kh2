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
u8 *func_002924d0();
u8 *func_001a80c8(u32);
s32 func_002914a8(u32, u32);
inline int inline_fn(u8 *arg0, int arg1)
{
  return arg0[2] == arg1;
}

u32 func_00291380(u32 a, u32 id)
{
  u32 r;
  u8 *p;
  u8 *q;
  if (id == 0)
  {
    return 0;
  }
  r = 6;
  p = func_002924d0();
  q = func_001a80c8(id);
  if (!func_002914a8(a, id))
  {
    r = 248;
    if (q[2] != 14)
    {
      r = 0;
      if (inline_fn(q, 15))
      {
        r = 7;
      }
    }
  }
  if (p[7])
  {
    r |= 1;
  }
  if (p[4])
  {
    r |= 2;
  }
  if (p[5])
  {
    r |= 4;
  }
  if (p[6])
  {
    r |= 8;
  }
  if (p[9] != 100)
  {
    r |= 16;
  }
  if (p[10] != 100)
  {
    r |= 32;
  }
  if (p[11] != 100)
  {
    r |= 64;
  }
  if (p[12] != 100)
  {
    r |= 128;
  }
  if (func_002914a8(a, id) && (*((u16 *) (p + 2))))
  {
    r |= 256;
  }
  return r;
}

}
