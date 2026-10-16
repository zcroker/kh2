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
void func_00138d60(void *, s32, s32, s32, s32, s32, s32);
s32 func_00192048(s32);
extern s32 D_0035f3d4;
void func_0028c0a0(u8 *p, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1)
{
  int new_var;
  func_00138d60(p, D_0035f3d4, a2, a3, a1, 0, t1);
  *((u32 *) (p + 0xc)) |= 8;
  new_var = 1;
  if (t0 >= 0)
  {
    *((s32 *) (p + 0x198)) = func_00192048(t0);
  }
  *((u32 *) (p + 0x1a4)) = 0x80e5e5e5;
  *((s32 *) (p + 0x1ac)) = new_var;
}

}
