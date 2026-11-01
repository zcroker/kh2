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
extern u64 D_01e2be80[16];
void func_001342c8(void *, s32, s32);
void func_002e60c0(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5, s32 p6, s32 p7, s32 w, s32 h)
{
  u64 *new_var2;
  u64 new_var;
  s32 f = p5 & 7;
  s32 n;
  u64 new_var3;
  n = 8;
  if (f == 1)
  {
    n = 6;
  }
  if (f == 2)
  {
    n = 4;
  }
  if (f == 3)
  {
    n = 2;
  }
  if (f == 4)
  {
    n = 1;
  }
  s32 sz = (w * h) * n;
  if (p5)
  {
    n = p5;
  }
  else
  {
    n = p5;
  }
  s32 q = sz / 32;
  if (sz & 0x1f)
  {
    q++;
  }
  u64 b = ((((u64) p3) << 32) | (((u64) p4) << 48)) | (((u64) n) << 56);
  new_var = ((u64) p6) << 32;
  u64 r = ((u64) w) | (((u64) h) << 32);
  new_var2 = D_01e2be80;
  new_var3 = new_var;
  u64 p = new_var3 | (((u64) p7) << 48);
  u64 *d = new_var2;
  D_01e2be80[0] = (1ULL << 60) | 5;
  D_01e2be80[1] = 14;
  D_01e2be80[2] = 0;
  D_01e2be80[3] = 0x3f;
  D_01e2be80[4] = b;
  D_01e2be80[5] = 0x50;
  D_01e2be80[6] = p;
  D_01e2be80[7] = 0x51;
  D_01e2be80[8] = r;
  D_01e2be80[9] = 0x52;
  d[10] = 0;
  D_01e2be80[12] = (((u64) q) | 0x8000) | (1ULL << 59);
  D_01e2be80[11] = 0x53;
  D_01e2be80[15] = (D_01e2be80[13] = 0);
  D_01e2be80[14] = 0;
  func_001342c8(new_var2, 7, 0x13000000);
  func_001342c8((void *) p2, q, 0x13000000);
}

}
