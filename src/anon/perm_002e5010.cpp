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
void func_002e5010(O2e5010 *o, f32 a, f32 b);  // 0x002e5010: definition moved into src/anon/unit_002e3f58.cpp

}
