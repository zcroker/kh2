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
s32 func_0019c6f0(u8 *);
s32 func_0019c4f8(u8 *p)
{
  u32 f = *((u32 *) (p + 2040));
  u32 m;
  u32 n = f & 4;
  s32 r = 0;
  if (((((n || (!(f & 0x400))) || ((*((u32 *) (p + 264))) & 0x40)) || ((*((u32 *) (p + 352))) & 0x8000000)) || func_0019c6f0(p)) || ((*((u32 *) ((*((u8 **) (p + 12))) + 8))) & 0x2000))
  {
    r = 1;
  }
  return r;
}

}
