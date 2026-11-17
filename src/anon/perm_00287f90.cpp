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
s32 func_00167f18(void) asm("_ZN2Tz10MenuCursor13GetInputStateEz");
extern volatile long * volatile D_0035f324;
void func_00287f90(u64 *s);  // 0x00287f90: definition moved into src/anon/unit_00286d28.cpp

}
