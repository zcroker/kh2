/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct SA SA;
typedef struct SS SS;
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
typedef struct SS
{
  u8 p[8];
  u16 a[8];
  u8 q[6];
  u16 z;
} SS;
typedef struct SA
{
  u8 pad[0x11f0];
  SS s;
} SA;
extern SA D_0032e020;
u16 func_001a3820(void);
void func_001a39c8(s32 v)
{
  SA *d = &D_0032e020;
  u16 *p;
  SS *new_var;
  s32 i;
  if ((d->s.a[0] == 0) && (d->s.z == 0))
  {
    d->s.z = func_001a3820();
  }
  new_var = &d->s;
  if (p)
  {
    p = (u16 *) (&d->s);
  }
  else
  {
    p = (u16 *) new_var;
  }
  for (i = 0; i < 8; i++, p++)
  {
    u16 x = p[4];
    if (x == 0)
    {
      p[4] = v;
      return;
    }
    if (x == v)
    {
      return;
    }
  }

}

}
