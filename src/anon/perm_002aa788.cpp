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
s32 func_002a9d68() asm("_ZN2Tz9JmNewInfo7GetSramEv");
s32 func_00294000(s32) asm("_ZN2Tz6JmInfo7GetDataEi");
u32 func_002aa5b8(s32, s32);
extern s32 D_0035f610;
s32 func_002aa788(s32 a, s32 id)
{
  s32 base = func_002a9d68();
  s32 r = 1;
  s32 t = func_00294000(2);
  if (id < 0)
  {
    s32 i;
    for (i = 0; i < (*((s32 *) (t + 8))); i++)
    {
      s32 bit = func_002aa5b8(a, i);
      if (bit >= 0)
      {
        s32 q = D_0035f610 + (a * 4);
        q += (((u32) bit) >> 5) * 4;
        u32 m = 1 << (bit & 0x1f);
        if ((*((u32 *) (q + 0x44))) & m)
        {
          s32 q2 = base + (a * 4);
          q2 += (((u32) bit) >> 5) * 4;
          r = ((*((u32 *) (q2 + 0x44))) & m) != 0;
          if (!r)
          {
            return r;
          }
        }
      }
    }

  }
  else
  {
    u32 bit = r = func_002aa5b8(a, id);
    u32 w = bit >> 5;
    s32 q = D_0035f610 + (a * 4);
    q += w * 4;
    u32 m = 1 << (bit & 0x1f);
    s32 k = 0;
    if ((*((u32 *) (q + 0x44))) & m)
    {
      s32 q2 = base + (a * 4);
      q2 += (bit >> 5) * 4;
      k = ((*((u32 *) (q2 + 0x44))) & m) != 0;
    }
    r = k;
  }
  return r;
}

}
