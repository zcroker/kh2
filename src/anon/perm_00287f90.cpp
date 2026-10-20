/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef union BD_VALUE BD_VALUE;

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
s32 func_00167f18(void) asm("_ZN2Tz10MenuCursor13GetInputStateEz");
extern volatile long * volatile D_0035f324;
void func_00287f90(u64 *s)
{
  u64 a;
  u64 b;
  u64 c;
  u64 d;
  if (!s)
  {
    s = (u64 *) func_00167f18();
  }
  a = s[0];
  b = s[1];
  c = s[2];
  d = s[3];
  D_0035f324[0] |= a;
  D_0035f324[1] |= b;
  D_0035f324[2] |= c;
  D_0035f324[3] |= d;
}

}
