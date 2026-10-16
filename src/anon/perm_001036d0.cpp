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
extern u8 D_01f18014[];
extern u32 D_0032ba14;
extern u32 D_0032ba18;
extern u8 D_0032ba30;
u32 func_00106178(void *, int);
void func_001036d0(u8 *base, int size)
{
  u8 *new_var;
  u8 *p;
  int n;
  u8 *new_var2;
  if (!base)
  {
    new_var2 = D_01f18014;
    base = new_var2;
  }
  new_var2 = base;
  p = new_var2;
  n = size - 0x68000;
  new_var = new_var2;
  D_0032ba14 = func_00106178(new_var, n);
  p += n;
  D_0032ba18 = func_00106178(p, 0x68000);
  D_0032ba30 = 1;
}

}
