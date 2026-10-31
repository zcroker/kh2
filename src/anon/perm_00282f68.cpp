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
void func_00282f68(void)
{
  s32 new_var;
  u8 *a = func_001063c0(0x18, func_00103570());
  new_var = func_00103570();
  func_002907c0(a, new_var, 10);
  D_0035f2b0 = a;
  u8 *b = func_001063c0(0x20, func_00103570());
  D_0035f2b4 = b;
  func_002fde18(b, 0, 0x20);
  u32 v60 = (u32) D_00347e60;
  u8 *p = func_001063c0(0x840, func_00103570());
  func_002361a0(p);
  u32 v98 = (u32) D_00347f98;
  u8 *q = p + 0x1a0;
  *((u32 *) (p + 0x1a0)) = v60;
  *((u32 *) (p + 0x1ac)) = 0;
  func_00239700(p + 0x1b8);
  *((u32 *) (q + 0x198)) = 0;
  *((u32 *) (p + 0x1a0)) = (u32) D_00347e40;
  u8 *r = p + 0x354;
  *((u32 *) (p + 0x354)) = v98;
  func_0031a838(p + 0x360);
  *((u32 *) (p + 0x354)) = v60;
  func_00239700(p + 0x36c);
  *((u32 *) (r + 0x198)) = 0;
  *((u32 *) (p + 0x354)) = (u32) D_00347e40;
  *((u32 *) (p + 0x508)) = v98;
  func_0031a838(p + 0x514);
  *((u32 *) (p + 0x508)) = v60;
  func_00239700(p + 0x520);
  *((u32 *) (p + 0x6a0)) = v98;
  func_0031a838(p + 0x6ac);
  *((u32 *) (p + 0x6a0)) = v60;
  func_00239700(p + 0x6b8);
  D_0035f2b8 = p;
}

}
