#include "../common/types.h"
extern "C" {


extern s32 D_0035eddc;
extern s32 D_0035edec;
extern u8 D_00372298[];
s32 func_00287cd0_a(s32) asm("func_00287cd0");
s32 func_00289310_a(s32) asm("func_00289310");
s32 func_002891e8_a(s32) asm("func_002891e8");
void func_002890e0(s32, s32, s32, s32, s32);
void func_00289038(s32, s32, s32, s32, s32, s32, s32);
s16 *func_0024e008(s32);
void func_0023f070(s32, s32, s32);
void func_0024e5b0(void);
s32 func_0028d008(s32);
s32 func_002891d0(s32);
void func_0028cf28(s32, s32);
u8 *func_0024e058(void);
void func_002b4388(s32, void *, s32);
void func_0024e228(void);
void func_0024dd68(s32 a0, s32 a1, s32 a2)
{
  s32 idx;
  u8 *p;
  if ((func_00287cd0_a(a0) == 1) && (func_00289310_a(a0) != 0))
  {
    idx = func_002891e8_a(a0);
    func_002890e0(a0, 1, 2, 0, -1);
    func_00289038(a0, idx, 1, 1, 2, 0, -1);
    if (a1 == 0)
    {
      func_0023f070(D_0035eddc, func_0024e008(idx)[2], -1);
      func_0024e5b0();
    }
    if (func_0028d008(a2) != 0)
    {
      func_0028cf28(a2, func_002891d0(a0));
    }
    p = D_00372298;
    if (a1 == 0)
    {
      if (a0 || p)
      {
        p = func_0024e058();
      }
      else
      {
        p = func_0024e058();
      }
    }
    func_002b4388(D_0035edec, p + (idx * 36), 0);
    func_0024e228();
  }
}



s32 func_001a3570(u32);
s32 func_001c99b0(u32);
s32 func_00181500(u32);
u8 *func_001b90c8(u32);
u8 *func_00189200(void *, u32);
f32 func_002f8b30(f32, f32);
extern u8 D_0032e020[];
extern u8 *D_00352130;
extern u32 D_003638d0;
s32 func_001d63a8(u8 *a0)
{
  float new_var;
  u8 *q;
  u8 *g;
  f32 f;
  f32 lim;
  f32 r;
  if (func_001a3570(29) > 0)
  {
    return 0;
  }
  if (func_001c99b0(5) != 0)
  {
    return 0;
  }
  if (func_00181500(0x4842) == 0)
  {
    return 0;
  }
  q = func_001b90c8(5);
  if ((*((u8 **) (a0 + 1164)))[433] < q[28])
  {
    return 0;
  }
  q = func_00189200(D_0032e020, 5);
  g = D_00352130;
  new_var = 100.0f;
  f = (*((f32 *) (g + 152))) * func_002f8b30(*((f32 *) (g + 156)), (f32) (*((s32 *) (q + 4))));
  lim = *((f32 *) (D_00352130 + 160));
  if (lim < f)
  {
    f = lim;
  }
  D_003638d0 *= 0x10dcd;
  r = ((f32) D_003638d0) * 2.3283064365386963e-10f;
  (*((s32 *) (q + 4)))++;
  r = r * new_var;
  if (f <= r)
  {
    return 0;
  }
  *((s32 *) (q + 4)) = 0;
  return 1;
}



struct T446
{
  u32 a;
  u16 id;
  u8 kind;
  u8 pad;
};
extern T446 D_003742c8[];
extern u8 *D_0035f2b4;
u8 *func_00258048(void);
void func_002fde18(void *, s32, s32);
s32 func_00181500_c(u16) asm("func_00181500");
inline u8 *inline_fn(u8 *arg0)
{
  return arg0 + 200;
}

void func_00283d00(s32 kind)
{
  u32 i = 0;
  s32 n = 0;
  u8 *save = func_00258048();
  func_002fde18(D_0035f2b4 + 4, 0, 9);
  for (; (&D_003742c8[i])->id != 0; i++)
  {
    if ((kind != (-1)) && (D_003742c8[i].kind != kind))
    {
      continue;
    }
    if (!func_00181500_c(D_003742c8[i].id))
    {
      continue;
    }
    if ((kind == (-1)) && (((u32 *) inline_fn(save))[i >> 5] & (1 << (i & 31))))
    {
      continue;
    }
    D_0035f2b4[n + 4] = i;
    n++;
  }

  D_0035f2b4[13] = n;
  D_0035f2b4[14] = 0;
}



s32 func_00289380(void *s);
s32 func_00287cd0(void);
s32 func_00287bc0(void);
s32 func_00276368(void);
s32 func_00276888(void);
void func_00287f90(s32 a);
s32 func_00292630(void);
void func_00276690(s32 a);
void func_00287c30(void);
s32 func_00276358(void);
void func_00276220(s32 a, s32 b);
void func_00274cf0(s32 a);
void func_002925c0(void);
void func_002995e8(void);
s32 func_00276398(void);
void func_00275b60(void);
void func_00287c90(s32 a);
s32 func_00242848(s32 a);
void func_0028f6f0(s32 a);
void func_00276dc0(void);
s32 func_0028b038(void *s);
void func_002765e8(s32 a, s32 b, s32 c);
void func_00287c00(s32 m);
void func_00287cc0(s32 s);
void func_00287da0(void);
s32 func_00288040(void);
void func_00288018(void);
extern void *D_0035f200;
s32 func_0028acc8(void *s);
int func_0028af18(void *s, u32 a);
s32 func_00289310(void *s);
s32 func_00287df0(s32 a, s32 b, s32 c, void (*d)(void), s32 e);
s32 func_002891e8(void *s);
void func_002958b0(void);
void func_002a7760(void);
void func_002a7758(void);
void func_002a7a60(void)
{
  s32 cur = func_00289380(D_0035f200);
  s32 st = func_00287cd0();
  s32 mode = func_00287bc0();
  if (st == 2)
  {
    if ((func_00276368() || func_0028acc8(D_0035f200)) || func_00276888())
    {
      if (cur == (-1))
      {
        return;
      }
      if (mode || D_0035f200)
      {
        func_00287f90(0);
        func_002a7760();
        return;
      }
      else
      {
        func_00287f90(0);
        func_002a7760();
        return;
      }
    }
    if (func_00292630())
    {
      return;
    }
    func_002a7760();
    func_00287c30();
    mode = func_00287bc0();
    func_0028af18(D_0035f200, 115);
    func_00276690(0);
    func_00276220(func_00276358(), 0);
    func_00274cf0(mode);
    func_002925c0();
    if (mode == 13)
    {
      func_002995e8();
    }
    else
      if (mode == 2)
    {
      func_002958b0();
    }
    return;
  }
  if ((cur != (-1)) || func_00289310(D_0035f200))
  {
    if (!func_00276398())
    {
      func_00276220(0, 2);
      func_00275b60();
    }
  }
  if ((st == 0) && func_00276398())
  {
    func_00287c90(1);
  }
  if (!func_00242848(func_00287df0(cur, func_00289310(D_0035f200), 1, 0, 1)))
  {
    switch (cur)
    {
      case -4:
        func_00287da0();
        break;

      case -1:
        break;

      case -2:
        func_0028f6f0(0);
        func_002a7758();
        func_00276dc0();
        func_00276220(1, 1);
        func_00287c00((mode == 0x24) ? (13) : (2));
        func_00287cc0(2);
      {
        s32 m = func_00287bc0();
        s32 a = func_002891e8(D_0035f200);
        func_002765e8(m, a, func_0028b038(D_0035f200));
      }
        break;

    }

  }
  if (func_00288040())
  {
    func_00288018();
  }
}



s32 func_00289380(void *s);
s32 func_00287cd0(void);
s32 func_00287bc0(void);
s32 func_00276368(void);
s32 func_00276888(void);
void func_00287f90(s32 a);
s32 func_00292630(void);
void func_00276690(s32 a);
void func_00287c30(void);
s32 func_00276358(void);
void func_00276220(s32 a, s32 b);
void func_00274cf0(s32 a);
void func_002925c0(void);
void func_002995e8(void);
s32 func_00276398(void);
void func_00275b60(void);
void func_00287c90(s32 a);
s32 func_00242848(s32 a);
void func_0028f6f0(s32 a);
void func_00276dc0(void);
s32 func_0028b038(void *s);
void func_002765e8(s32 a, s32 b, s32 c);
void func_00287c00(s32 m);
void func_00287cc0(s32 s);
void func_00287da0(void);
s32 func_00288040(void);
void func_00288018(void);
extern void *D_0035f200;
s32 func_0028acc8(void *s);
volatile unsigned int func_0028af18_b(void *s, u32 a) asm("func_0028af18");
s32 func_00289310(void *s);
s32 func_00287df0(s32 a, s32 b, s32 c, void (*d)(void), s32 e);
s32 func_002891e8(void *s);
void func_002958b0(void);
void func_002a8a88(void);
void func_002a8a80(void);
void func_002a8d98(void)
{
  s32 cur = func_00289380(D_0035f200);
  s32 st = func_00287cd0();
  s32 mode = func_00287bc0();
  if (st == 2)
  {
    if ((func_00276368() || func_0028acc8(D_0035f200)) || func_00276888())
    {
      if (cur == (-1))
      {
        return;
      }
      func_00287f90(0);
      func_002a8a88();
      return;
    }
    if (func_00292630())
    {
      return;
    }
    func_002a8a88();
    func_00287c30();
    mode = func_00287bc0();
    func_0028af18_b(D_0035f200, 115);
    func_00276690(0);
    func_00276220(func_00276358(), 0);
    func_00274cf0(mode);
    func_002925c0();
    if (mode == 13)
    {
      func_002995e8();
    }
    else
      if (mode == 2)
    {
      func_002958b0();
    }
    return;
  }
  if ((cur != (-1)) || func_00289310(D_0035f200))
  {
    if (!func_00276398())
    {
      func_00276220(0, 2);
      func_00275b60();
    }
  }
  if ((st == 0) && func_00276398())
  {
    func_00287c90(1);
  }
  if (!func_00242848(func_00287df0(cur, func_00289310(D_0035f200), 1, 0, 1)))
  {
    switch (cur)
    {
      case -4:
        func_00287da0();
        break;

      case -1:
        break;

      case -2:
        func_0028f6f0(0);
        func_002a8a80();
        func_00276dc0();
        func_00276220(1, 1);
        func_00287c00((mode == 0x23) ? (13) : (2));
        func_00287cc0(2);
      {
        s32 m = func_00287bc0();
        s32 a = func_002891e8(D_0035f200);
        func_002765e8(m, a, func_0028b038(D_0035f200));
      }
        break;

    }

  }
  if (func_00288040())
  {
    func_00288018();
  }
}

}
