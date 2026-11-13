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
void func_001d4e50(M1d4e50 *m, K1d4e50 *k);  // 0x001d4e50: definition moved into src/anon/unit_001d3c08.cpp

}
