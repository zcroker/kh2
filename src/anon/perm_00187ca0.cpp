/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Obj187 Obj187;
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
struct Obj187
{
  u8 pad0[0x8c];
  s32 x8c;
  u8 pad90[4];
  s32 x94;
  s32 x98;
  u32 x9c;
  s32 xa0;
  u8 padA4[4];
  f32 xa8;
};
extern u32 D_01c60bc0[];
extern f32 D_00349e10;
s32 func_0016cd48(s32, s32);
void func_0016d110(void) asm("_Z17ttarget0_0016d110v");
void func_00187b90(Obj187 *) asm("_Z17ctarget0_00187b90v");
s32 func_00187be8(Obj187 *);
s32 func_00187e20(Obj187 *);
s32 func_00187e58(Obj187 *);
void func_001884d0(Obj187 *, s32 *);
s32 func_001886d0(Obj187 *);
// 00187ca0: moved to src/anon/unit_00185d10.cpp
void func_00187ca0(Obj187 *p);

}
