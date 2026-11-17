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
u32 func_003149e8(u8);
s64 __muldi3(s32, u64);
volatile char func_00314b90(u8, s32, s32, void *);
inline s64 inline_fn(s32 arg0, u8 *arg1)
{
  return __muldi3(arg0, func_003149e8(arg1[0x14]));
}

s32 func_00314dd8(u8 *a0, s32 a1);  // 0x00314dd8: definition moved into src/libsupc++/eh_personality.cpp

}
