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
typedef struct P
{
  u8 pad[0x24];
  s32 x24;
  s32 x28;
  s32 pad2[2];
  s32 **x34;
} P;
void func_00138c10(u8 *, s32);
void func_00157990(P *p)
{
  s32 b = *p->x34[0x48c / 4];
  int new_var;
  s32 a = p->x28;
  if (a == b)
  {
    return;
  }
  if (a < b)
  {
    p->x24 = b;
  }
  else
  {
    p->x24 = a;
    new_var = 8764;
  }
  p->x28 = b;
  func_00138c10(((u8 *) p) + 7528, 126);
  func_00138c10(((u8 *) p) + new_var, 127);
}

}
