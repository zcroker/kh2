/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct O1507b8 O1507b8;
typedef struct S1507b8 S1507b8;
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
typedef struct S1507b8 S1507b8;
typedef struct O1507b8 O1507b8;
struct S1507b8
{
  u8 pad[392];
  s32 f392;
  u8 pad2[116];
};
struct O1507b8
{
  u8 pad[48];
  S1507b8 a;
  u8 pad2[412];
  u32 f972;
};
u32 func_0013a7e8(s32);
u32 func_0013d7e0();
void func_00138d60(S1507b8 *, s32, u32, u32, s32, s32, s32);
void func_001386e0(S1507b8 *, s32, u32, u32, s32, s32);
u32 func_0023aa78(u8 *);
void func_0014fc40(O1507b8 *, s32, u32, s32, s32, s32);
void func_001508a0(O1507b8 *, s32);
void func_001507b8(O1507b8 *o, s32 v)
{
  u32 a;
  S1507b8 *s;
  S1507b8 *t;
  u32 b;
  a = func_0013a7e8(1);
  s = &o->a;
  ;
  b = func_0013d7e0();
  func_00138d60(s, 8000, a, b, 0, v, 7);
  func_001386e0((S1507b8 *) (((u8 *) o) + 560), 8000, a, b, 0, 7);
  s->f392 = 1;
  ((S1507b8 *) (((u8 *) o) - -560))->f392 = 2;
  func_0014fc40(o, 1, func_0023aa78(((u8 *) o) + 72), 8000, 7, 0);
  o->f972 = 0;
  func_001508a0(o, v);
}

}
