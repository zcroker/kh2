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
s32 func_00257070(s32) asm("_ZN2Tz5CmTop9GetCurPosEi");
void func_002713a0(s32, s8 **, s32 *);
s32 func_00272c20(s32);
extern s8 *D_01e21edc;
s32 func_00272b60(s32 n)
{
  s32 cnt;
  s32 sum = 0;
  s32 *new_var;
  s32 r = -1;
  s32 i;
  new_var = &cnt;
  func_002713a0(i = func_00257070(25), &D_01e21edc, new_var);
  for (i = 0; i < cnt; i++)
  {
    sum += func_00272c20(D_01e21edc[i]);
    if (n < sum)
    {
      r = D_01e21edc[i];
      break;
    }
  }

  return r;
}

}
