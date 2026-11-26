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
s32 func_00103570() asm("_ZN2Tz17LoadDataGetSystemEv");
u8 *func_001063c0(s32, s32) asm("_ZN2Tz13LoadDataAllocEjj");
void func_002361a0(void *) asm("_ZN2YI5IMAGEC1Ev");
void func_00239700(void *);
void func_002907c0(void *, s32, s32) asm("_ZN2Tz8MenuFileC1EP9ALLOCATORi");
void func_002fde18(void *, s32, s32) asm("_Z16wtarget_002fde18jjjj");
void func_0031a838(void *) asm("_Z10ErrorRaisePv");
extern short D_00347e40[];
extern u8 D_00347e60[];
extern volatile unsigned short D_00347f98[];
extern u8 *D_0035f2b0;
extern u8 *D_0035f2b4;
extern u8 *D_0035f2b8;
void Tz__CmTutorial__Init(void);  // 0x00282f68: definition moved into src/anon/unit_00282c68.cpp

}
