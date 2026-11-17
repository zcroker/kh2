/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct W W;
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
extern s32 D_00361f60;
extern u8 D_00362c08[];
s32 func_001b0320(s32);
u8 *func_002dc7c8(s32);
void func_002e7568(f32, void *, s32, void *);
typedef struct W
{
  u8 pad[0x9b8];
  s32 h;
} W;
void func_002df6d8(void *a0, W *p);  // 0x002df6d8: definition moved into src/anon/unit_002de3c8.cpp

}
