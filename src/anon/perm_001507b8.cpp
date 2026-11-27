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
void dk__Sprite__create(S1507b8 *, s32, u32, u32, s32, s32);
u32 func_0023aa78(u8 *);
void func_0014fc40(O1507b8 *, s32, u32, s32, s32, s32);
void func_001508a0(O1507b8 *, s32);
void func_001507b8(O1507b8 *o, s32 v);  // 0x001507b8: definition moved into src/anon/unit_0014ecb8.cpp

}
