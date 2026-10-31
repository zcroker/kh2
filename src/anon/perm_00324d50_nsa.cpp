/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct F2 F2;
typedef struct F7 F7;
typedef struct Obj Obj;
typedef struct Q8 Q8;
typedef struct S3 S3;
typedef struct S4 S4;
typedef struct T9 T9;
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
struct S3
{
  s32 a;
  s32 b;
  s32 c;
};
struct S4
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
};
struct F2
{
  f32 x;
  f32 y;
};
struct F7
{
  f32 a;
  f32 b;
  f32 c;
  f32 d;
  f32 e;
  f32 f;
  f32 g;
};
struct T9
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
  s32 e;
  s32 f;
  s32 g;
  s32 h;
  s32 i;
};
struct Q8
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
  s32 e;
  s32 f;
  s32 g;
  s32 h;
};
struct Obj
{
  void *vptr;
  S3 m4;
  S3 b16;
  S3 b28;
  S3 b40;
  S4 m52;
  f32 m68;
  F2 m72;
  S3 b80;
  S3 b92;
  s32 m104;
  F7 m108;
  s32 m136;
  T9 m140;
};
extern u8 D_0035eae8;
void func_00324d50(Obj *d, const Obj *s)
{
  d->vptr = &D_0035eae8;
  d->m4.a = s->m4.a;
  d->m4.b = s->m4.b;
  d->m4.c = s->m4.c;
  d->b16 = s->b16;
  d->b28 = s->b28;
  d->b40 = s->b40;
  d->m52.a = s->m52.a;
  d->m52.b = s->m52.b;
 do { d->m52.c = s->m52.c; d->m52.d = s->m52.d; d->m68 = s->m68; d->m72.x = s->m72.x; d->m72.y = s->m72.y; d->b80 = s->b80; d->b92 = s->b92; } while (0);
  d->m104 = s->m104;
  d->m108.a = s->m108.a;
  d->m108.b = s->m108.b;
  d->m108.c = s->m108.c;
  d->m108.d = s->m108.d;
  d->m108.e = s->m108.e;
  d->m108.f = s->m108.f;
  d->m108.g = s->m108.g;
  d->m136 = s->m136;
  ((Q8 *) (&d->m140))->f = ((const Q8 *) (&s->m140))->f;
  ((Q8 *) (&d->m140))->h = ((const Q8 *) (&s->m140))->h;
  (&d->m140)->a = ((const Q8 *) (&s->m140))->a;
  d->m140.b = s->m140.b;
  d->m140.c = s->m140.c;
  d->m140.d = s->m140.d;
  d->m140.e = s->m140.e;
  d->m140.g = s->m140.g;
  d->m140.i = s->m140.i;
}

}
