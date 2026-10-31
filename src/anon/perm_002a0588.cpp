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
extern u8 D_00347e40[];
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern void *D_0035f5d4;
extern void *D_0035f5d8;
extern void *D_0035f5dc;
extern u8 D_0035f5e0;
extern u8 D_0035f5e1;
s32 func_00103570(void) asm("_ZN2Tz17LoadDataGetSystemEv");
void *func_001063c0(s32, s32) asm("_ZN2Tz13LoadDataAllocEjj");
void func_00239700(void *);
void func_0031a838(void *) asm("_Z10ErrorRaisePv");
void func_0023f800(void *) asm("_ZN2Tz7LayFileC1Ev");
void func_002fde18(void *, s32, s32) asm("_Z16wtarget_002fde18jjjj");
void func_002a0588(void)
{
  u8 (*new_var)[];
  D_0035f5d4 = func_001063c0(0x150, func_00103570());
  u8 *p = (u8 *) func_001063c0(0x67c, func_00103570());
  *((u8 **) p) = D_00347e60;
  *((s32 *) (p + 0xc)) = 0;
  new_var = &D_00347f98;
  func_00239700(p + 0x18);
  *((u8 **) (p + 0x198)) = *new_var;
  func_0031a838(p + 0x1a4);
  *((u8 **) (p + 0x198)) = D_00347e60;
  func_00239700(p + 0x1b0);
  *((u8 **) (p + 0x330)) = D_00347f98;
  func_0031a838(p + 0x33c);
  *((u8 **) (p + 0x330)) = D_00347e60;
  func_00239700(p + 0x348);
  u8 *c = p + 0x4c8;
  *((u8 **) (p + 0x4c8)) = D_00347f98;
  func_0031a838(p + 0x4d4);
  *((u8 **) (p + 0x4c8)) = D_00347e60;
  func_00239700(p + 0x4e0);
  *((s32 *) (c + 0x198)) = 0;
  D_0035f5d8 = p;
  *((u8 **) c) = D_00347e40;
  void *q = func_001063c0(0x1c, func_00103570());
  func_0023f800(q);
  void *h = D_0035f5d4;
  D_0035f5dc = q;
  D_0035f5e0 = 0;
  D_0035f5e1 = 0;
  func_002fde18(h, 0, 0x150);
}

}
