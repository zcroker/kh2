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
s32 YS__OBJ__is_stop(u8 *);
s32 YS__OBJ__is_disable_rc(u8 *p);  // 0x0019c4f8: definition moved into src/anon/unit_0019ba60.cpp

}
