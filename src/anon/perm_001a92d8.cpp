/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct B1 B1;
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
void func_001a9350(void *, s32, s32);
s32 func_0016e920(s32);
s32 func_001a9758(s32, s32);
void func_00170e58(void);
void func_001a9218(void *);
typedef struct B1
{
  s32 a;
  s32 f4;
  s32 f8;
} B1;
void func_001a92d8(B1 *p, s32 a, s32 b);  // 0x001a92d8: definition moved into src/anon/unit_001a9130.cpp

}
