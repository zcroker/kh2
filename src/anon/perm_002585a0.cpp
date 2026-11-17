/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct P P;
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
struct P
{
  u8 pad[3];
  u8 b3;
  u8 pad2[0x10];
  s16 h14;
};
extern P *D_0035f080;
extern s32 D_0035f084;
extern s16 D_0035f06c;
extern u8 D_0035f069;
void func_002588e8(s32);
void func_0026dd18(P *, s32, s32);
void func_002585a0(void);  // 0x002585a0: definition moved into src/anon/unit_002584c8.cpp

}
