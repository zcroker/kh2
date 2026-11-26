/* found by decomp-permuter (nightly.py) */
extern "C" {


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
s32 Tz__JmPuzzle__GameSelCheck(void);
s32 PlaySE_2b0(s32, s32) asm("_ZN2Tz9MenuSound6PlaySEEib");
s32 func_002b0de0(u32 a);  // 0x002b0de0: definition moved into src/anon/unit_002b0950.cpp

}
