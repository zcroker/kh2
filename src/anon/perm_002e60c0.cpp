/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef union BD_VALUE BD_VALUE;
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
extern u64 D_01e2be80[16];
void func_001342c8(void *, s32, s32);
void func_002e60c0(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5, s32 p6, s32 p7, s32 w, s32 h);  // 0x002e60c0: definition moved into src/anon/unit_002e5f70.cpp

}
