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
u8 *func_001a80c8(void);
s32 func_002642a8(void)
{
  s32 r;
  u8 *new_var;
  new_var = func_001a80c8();
  r = 0;
  switch (new_var[2])
  {
    case 0:

    case 1:
      r = 8;
      break;

    case 2:

    case 3:

    case 4:

    case 5:

    case 6:

    case 7:

    case 8:

    case 9:

    case 10:

    case 11:

    case 12:

    case 13:
      r = 1;
      break;

    case 14:
      r = 2;
      break;

    case 15:
      r = 4;
      break;

    case 16:
      r = 0x10;
      break;

  }

  return r;
}

}
