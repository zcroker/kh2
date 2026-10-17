/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct S4 S4;
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
void func_001671e8(s32, s32);
void func_00167218(void);
s32 func_00227ca8(void *);
s32 func_002282f0(s32);
typedef struct S4
{
  s32 a;
  s16 h;
  u8 b6;
  u8 b7;
  u8 p8[4];
} S4;
void func_0022cea0(S4 *p)
{
  int new_var;
  if (func_002282f0(p->h) == 0)
  {
    if (p->b6 == 0)
    {
      u8 b = p->b7;
      new_var = b == 0;
      func_001671e8(func_00227ca8(&p->p8), new_var);
    }
    else
    {
      func_00167218();
    }
  }
}

}
