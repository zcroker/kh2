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
void func_00324d50(Obj *d, const Obj *s);  // 0x00324d50: definition moved into src/anon/unit_00324808.cpp

}
