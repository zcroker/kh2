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
typedef void (*DtorFn)(void *);
void func_00106420(void *) asm("_ZN2Tz12LoadDataFreeEz");
void func_00239870(void *) asm("_ZN2YI8SEQUENCED1Ev");
extern u8 D_0035f0f0;
extern u32 D_0035f0f8;
extern void *D_0035f0fc;
extern u8 *D_0035f0f4;
extern u8 D_00347e60[];
extern u8 D_00347f98[];
inline static void vdtor(void *e)
{
  (*((DtorFn *) ((*((u8 **) e)) + 12)))(e);
}

void func_0026bab8(void)
{
  D_0035f0f0 = 0;
  D_0035f0f8 = 0;
  if (D_0035f0fc)
  {
    func_00106420(D_0035f0fc);
    D_0035f0fc = 0;
  }
  u8 *p = D_0035f0f4;
  if (p)
  {
    if (p + 3816)
    {
      u8 *e = (p + 3816) + (5 * 436);
      u8 *b = p + 3816;
      a:
      if (b == e)
      {
        goto a_out;
      }

      e -= 436;
      vdtor(e);
      goto a;
      a_out:
      ;

      ;
    }
    if (p + 2040)
    {
      u8 *e = (p + 2040) + (4 * 436);
      u8 *b = p + 2040;
      b:
      if (b == e)
      {
        goto b_out;
      }

      if (p)
      {
        e -= 436;
        vdtor(e);
        goto b;
      }
      else
      {
        e -= 436;
        vdtor(e);
        goto b;
      }
      b_out:
      ;

      ;
    }
    if (p + 408)
    {
      u8 *e = (p + 408) + (4 * 408);
      u8 *b = p + 408;
      c:
      if (b == e)
      {
        goto c_out;
      }

      e -= 408;
      vdtor(e);
      goto c;
      c_out:
      ;

      ;
    }
    *((u32 *) p) = (u32) D_00347e60;
    func_00239870(p + 24);
    *((u32 *) p) = (u32) D_00347f98;
    func_00106420(p);
    D_0035f0f4 = 0;
  }
}

}
