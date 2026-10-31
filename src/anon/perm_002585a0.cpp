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
void func_002585a0(void)
{
  s16 new_var2;
  s16 new_var;
  if (D_0035f080 != 0)
  {
    P **pp;
 do { new_var2 = D_0035f06c; } while (0);
    if (new_var2 == 9)
    {
      new_var = D_0035f080->h14;
      func_002588e8(new_var = new_var);
      new_var2 = 1;
      func_0026dd18(*(&D_0035f080), D_0035f084, (D_0035f069) ? (-new_var2) : (D_0035f080->b3));
    }
  }
  D_0035f069 = 0;
}

}
