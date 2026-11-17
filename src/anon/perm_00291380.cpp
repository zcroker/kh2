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
u8 *func_002924d0();
u8 *func_001a80c8(u32);
s32 func_002914a8(u32, u32);
inline int inline_fn(u8 *arg0, int arg1)
{
  return arg0[2] == arg1;
}

u32 func_00291380(u32 a, u32 id);  // 00291380: moved to src/anon/unit_00290f78.cpp

}
