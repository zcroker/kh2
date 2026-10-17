/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Ent Ent;
typedef struct Hdr Hdr;
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
typedef struct Ent Ent;
struct Ent
{
  s16 a;
  u16 id;
  s16 b;
  s16 n;
};
typedef struct Hdr Hdr;
struct Hdr
{
  s16 count;
  s16 pad[3];
  Ent e[1];
};
s32 func_002766d0(void);
void func_00138c10(s32, s32);
s32 func_0028b040(s32);
s8 *func_00276568(void);
void func_002ac268(s32, s32);
s32 func_002abff0(s32, s32);
s32 func_002ac110(s32, s32);
extern s32 D_0035f200;
extern Hdr *D_0035f594;
extern s32 D_00374788;
extern s32 D_0037478c;
void func_00297b30(void)
{
  s32 base = func_002766d0();
  s32 i;
  s32 acc;
  s32 v;
  s32 off;
  s32 sel;
  s32 c;
  s32 new_var;
  for (i = 0; i < 10; i++)
  {
    func_00138c10((base + (i * 0x198)) + 0xa998, 2);
  }

  sel = 0;
  v = func_0028b040(D_0035f200);
  new_var = (acc = 0);
  off = v;
  for (i = 0, new_var; i < D_0035f594->count; i++)
  {
    if ((v == acc) || (v < (acc + D_0035f594->e[i].n)))
    {
      off = acc - v;
      sel = i;
      break;
    }
    acc += D_0035f594->e[i].n;
  }

  c = *func_00276568();
  for (i = sel; i < D_0035f594->count; i++)
  {
    if (off >= 0)
    {
      u16 id = D_0035f594->e[i].id;
      if (off == 0)
      {
        func_002ac268(c, id);
      }
      if (func_002abff0(c, id))
      {
        func_00138c10((base + (off * 0x198)) + 0xa998, (func_002ac110(c, id)) ? (D_0037478c) : (D_00374788));
      }
    }
    off += D_0035f594->e[i].n;
    if (off >= 10)
    {
      break;
    }
  }

}

}
