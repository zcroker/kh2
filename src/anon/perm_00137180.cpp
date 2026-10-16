/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct P137180 P137180;
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
typedef struct P137180 P137180;
struct P137180
{
  u32 cur;
  u32 prev;
  u32 f8;
  u32 flags;
};
extern P137180 D_00347d30[2];
extern u8 D_00347d54;
void func_002ba2b0(s32, s32);
void func_00136b78(s32, s32);
void func_00137180(u32 *in)
{
  P137180 *p;
  s32 i;
  u32 v;
  u32 f;
  v = 1;
  D_00347d54 = v;
  p = D_00347d30;
  for (i = 0; i < 2; i++, in++, p++)
  {
    v = *in;
    if ((p->cur == v) && (p->prev == v))
    {
      continue;
    }
    p->cur = v;
    func_002ba2b0(240, i);
    if ((*in) != 0)
    {
      f = p->flags;
      p->flags = f | 2;
      if (p->prev != (*in))
      {
        p->prev = *in;
        p->flags = f | 3;
      }
    }
    else
    {
      func_00136b78(i, 0);
    }
  }

}

}
