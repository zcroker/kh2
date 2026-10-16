/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct K1d4e50 K1d4e50;
typedef struct M1d4e50 M1d4e50;
typedef struct S1d4e50 S1d4e50;
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
typedef struct S1d4e50 S1d4e50;
typedef struct M1d4e50 M1d4e50;
typedef struct K1d4e50 K1d4e50;
struct S1d4e50
{
  u8 busy;
  u8 age;
  u16 id;
};
struct M1d4e50
{
  u8 pad[56];
  S1d4e50 slot[128];
};
struct K1d4e50
{
  u16 id;
  u8 pad[0x28];
  u16 f2a;
};
void func_001d4f40(M1d4e50 *, u16, u8);
void func_001d4e50(M1d4e50 *m, K1d4e50 *k)
{
  u16 id;
  S1d4e50 *best;
  s32 i;
  S1d4e50 *s;
  S1d4e50 *hit;
  S1d4e50 *c;
  u8 a;
  if (k->f2a == 0)
  {
    return;
  }
  id = k->id;
  best = 0;
  i = 0;
  s = m->slot;
  for (; i < 128; i++, s++)
  {
    c = s;
    if ((c->busy == 0) && (c->id == id))
    {
      hit = c;
      goto found;
    }
    if ((best == 0) || (best->age > c->age))
    {
      best = c;
    }
  }

  best->id = id;
  best->busy = 0;
  best->age = 0;
  c = best;
  hit = c;
  found:
  a = hit->age;

  hit->age = a + 1;
  func_001d4f40(m, k->f2a, a);
}

}
