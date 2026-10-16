/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct E2e5010 E2e5010;
typedef struct O2e5010 O2e5010;
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
typedef struct E2e5010 E2e5010;
typedef struct O2e5010 O2e5010;
struct E2e5010
{
  u8 pad[52];
  f32 v;
  u8 pad2[40];
};
struct O2e5010
{
  f32 w;
  u8 pad[12];
  E2e5010 e[41];
};
void func_002e5010(O2e5010 *o, f32 a, f32 b)
{
  f32 w;
  f32 t;
  f32 x;
  s32 i;
  f32 f;
  s32 j;
  E2e5010 *e;
  E2e5010 *e0;
  E2e5010 *e1;
  w = o->w;
  t = (a + (w * 0.5f)) / w;
  if (t < 0.0f)
  {
    return;
  }
  if (1.0f < t)
  {
    return;
  }
  x = t * 40.0f;
  i = (s32) x;
  f = x - ((f32) i);
  if (f < 0.0001f)
  {
    e = &o->e[i];
    e->v += b;
    return;
  }
  j = i + 1;
  e0 = &o->e[i];
  e1 = &o->e[j];
  e0->v += b * (1.0f - (x - ((f32) i)));
  e1->v += b * (x - ((f32) i));
}

}
