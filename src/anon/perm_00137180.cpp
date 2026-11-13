/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct P137180 P137180;
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
typedef struct P137180 P137180;
struct P137180
{
  u32 cur;
  u32 prev;
  u32 f8;
  u32 flags;
};
extern P137180 D_00347d30[2];
extern u8 D_00347d54;
void func_002ba2b0(s32, s32);
void func_00136b78(s32, s32);
// 00137180: moved to src/harata/libdk/bgm.cpp

}
