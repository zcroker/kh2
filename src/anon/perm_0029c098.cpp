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
s32 func_00287cd0(void);
s32 func_00287bc0(void);
s32 func_00289380(void *);
s32 func_0029e2f8(s32);
void func_0029e4c8(s32);
s32 func_00287c10(void);
s32 func_00276368(void);
s32 func_0028acc8(void *);
s32 func_00276888(void);
s32 func_0029ad40(void);
s32 func_00292630(void);
void func_0029e430(void);
void func_00276690(s32);
void func_002766b0(s32);
void func_0029aac0(s32);
s32 func_00276358(void);
void func_00276220(s32, s32);
void func_00287c30(void);
long long func_0028af18(void *, s32);
void func_0028b1e8(void *, s32);
void func_0029e9d0(void);
void func_00287bd0(s32, s32);
s32 func_00276638(s32);
void func_002a0908(s32);
void func_0029b698(void);
void func_0029be08(void);
void func_0029c568(void);
void func_00287f90(s32);
void func_0029e298(s32);
void func_0029de18(void);
s32 func_00289310(void *);
s32 func_00276398(void);
void func_00275b60(void);
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, void (*)(void), s32);
s32 func_00242848(s32);
void func_0029ecf0(void);
void func_00287da0(void);
void func_0029cb28(s32);
void func_0029aa30(void);
void func_00287c00(s32);
void func_00287cc0(s32);
void func_0029e258(s32);
void func_00276dc0(void);
s32 func_00288040(void);
void func_00288018(void);
extern void *D_0035f200;
extern s8 D_0035f5c4;
void func_0029c098(void)
{
  s32 r;
  s32 mode;
  s32 st;
  s32 k;
  s32 i;
  s32 busy;
  mode = func_00287cd0();
  st = func_00287bc0();
  if (mode == 2)
  {
    r = -1;
  }
  else
  {
    r = func_00289380(D_0035f200);
  }
  if ((mode != 2) && (!func_0029e2f8(0)))
  {
    func_0029e4c8(0);
  }
  if (mode == 2)
  {
    k = func_00287c10();
    if (((k == 17) || (k == 20)) || (k == 23))
    {
      busy = 0;
    }
    else
    {
      busy = 0;
      if (((func_00276368() || func_0028acc8(D_0035f200)) || func_00276888()) || func_0029ad40())
      {
        busy = 1;
      }
    }
    if (!busy)
    {
      for (i = 0; i < 2; i++)
      {
        if (func_0029e2f8(i))
        {
          goto busy;
        }
      }

      if (func_00292630())
      {
        return;
      }
      func_0029e430();
      func_00276690(0);
      func_002766b0(1);
      if (((k != 17) && (k != 20)) && (k != 23))
      {
        func_0029aac0(func_00287c10());
        func_00276220(func_00276358(), 0);
      }
      func_00287c30();
      busy = func_00287bc0();
      func_0028af18(D_0035f200, 115);
      func_0028b1e8(D_0035f200, 1);
      if (((busy == 15) || (busy == 18)) || (busy == 21))
      {
        func_0029e9d0();
        if (D_0035f5c4 > 0)
        {
          func_00287bd0(D_0035f5c4, 0);
          func_002a0908(func_00276638(15));
        }
        else
        {
          func_0029b698();
        }
        D_0035f5c4 = -1;
      }
      else
        if (((busy == 16) || (busy == 19)) || (busy == 22))
      {
        func_00276220(func_00276358(), 0);
        func_0029be08();
      }
      else
        if (((busy == 17) || (busy == 20)) || (busy == 23))
      {
        func_0029c568();
      }
      return;
    }
    busy:
    if (r != (-1))
    {
      func_00287f90(0);
      if (((k == 17) || (k == 20)) || (k == 23))
      {
        for (i = 0; i < 2; i++)
        {
          func_0029e298(i);
        }

      }
      else
      {
        func_0029aac0(func_00287c10());
      }
    }

    return;
  }
  func_0029de18();
  if (((r != (-1)) || func_00289310(D_0035f200)) && (!func_00276398()))
  {
    func_00276220(0, 2);
    func_00275b60();
  }
  if ((mode == 0) && func_00276398())
  {
    func_00287c90(1);
  }
  if (!func_00242848(func_00287df0(r, func_00289310(D_0035f200), 1, func_0029ecf0, 1)))
  {
    switch (r)
    {
      case -4:
        func_00287da0();
        break;

      case -1:
        break;

      case -11:

      case -10:
        func_0029cb28(r);
        func_0029aa30();
        func_00276220(r != (-10), 1);
        func_00287c00(func_00287bc0());
        func_00287cc0(2);
        break;

      case -6:
        k = 17;
        if (st != 16)
      {
        k = (st == 19) ? (20) : (23);
      }
        func_0029e258(0);
        func_00276dc0();
        func_00287c00(k);
        func_00287cc0(2);
        break;

      case -2:
        k = 15;
        if (st != 16)
      {
        k = (st == 19) ? (18) : (21);
      }
        func_0029aa30();
        func_00276dc0();
        func_00276220(1, 1);
        func_00287c00(k);
        func_00287cc0(2);
        break;

    }

  }
  if (func_00288040())
  {
    func_00288018();
  }
}

}
