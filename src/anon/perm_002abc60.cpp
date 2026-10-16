/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Flg Flg;
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
typedef struct Flg
{
  u8 pad[0x140];
  u32 bits[1];
} Flg;
extern Flg *D_0035f610;
inline static s32 chk2(u32 *b, u32 n)
{
  return (b[n >> 5] & (1 << (n & 31))) != 0;
}

s32 func_002abc60(s32 n)
{
  s32 new_var;
  if (n < 0)
  {
    s32 r;
    s32 i;
    u32 *b = D_0035f610->bits;
    for (i = 0; i < 4; i++)
    {
      r = chk2(b, i);
      if (r)
      {
        break;
      }
    }

    new_var = r;
    return new_var;
  }
  new_var = n;
  return chk2(D_0035f610->bits, new_var);
}

}
