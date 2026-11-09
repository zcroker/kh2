// w3902 (zl90). Plain -O2 C++.
#include "../common/types.h"

extern "C" {

struct Ent36
{
  u8 pad0[8];
  u8 name[8];
  s8 f10;
  u8 pad11;
  u16 f12;
  u8 pad14[16];
};
struct VObj
{
  struct VT
  {
    u8 pad[24];
    void (*f18)(VObj *, s32, u32, s32, s32, s32, s32);
  } *vt;
};
u8 *func_0023ee30(u32);
void func_0031a838(u8 *);
void func_002369a0(u8 *);
void func_0023c008(u8 *);
void func_0028d7f0(u8 *, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0023ef50(u8 *);
s32 func_00244938(s32);
s32 func_002431d0(s32, s32);
void func_00288d80(void *, s32, s32, s32, u8 *, s32, Ent36 *, u8 *);
u8 *func_002891b8(void *, s32);
s32 func_0023aa98(u8 *);
s32 func_0023aa78(u8 *);
s32 func_0028dd90(s32);
s32 func_0028ddd8(s32);
void func_001395f8(u8 *);
void func_00139620(u8 *);
s32 func_002892f8(void *);
void func_00138c68(u8 *, s32, s32);
void func_002891f0(void *, s32, s32, s32, s32);
void func_002449c0(void);
s32 func_002891e8(void *);
s32 func_00244ee8(s32);
void func_002b4070(void *, s32, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, s32, Ent36 *, s32, s32);
s32 func_001a6d08(s32);
s32 func_00244a10(void);
void func_0028af40(void *, s32);
void func_0028d980(u8 *, s32, s32, s32, u8 *, s32, s32, s32, s32);
void func_00244a60(void);
VObj *func_00287dc0(void);
void func_0023d808(VObj *, s32);
void func_0023e858(VObj *, s32, f32);
void func_0023e8b8(VObj *, s32, f32);
void func_0023e8d8(VObj *, s32, f32);
s32 func_00139d78(s32);
void func_0023e9b0(VObj *, s32, s32);
void func_0023e690(VObj *, s32, s32, s32);
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_002887c8(void);
void func_00243e30(void);
void func_00288750(void (*)(void));
void func_00244058(void);
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u8 D_0035ed0c;
extern u8 D_0035ed14;
extern u8 *D_0035ecf0;
extern u8 *D_0035ecf4;
extern u8 *D_0035ecf8;
extern u8 *D_0035ecfc;
extern u8 *D_0035ed08;
extern void *D_0035ece8;
extern Ent36 D_003719a0[];
extern s16 D_00371968[][3];
extern u8 D_00371960[];
extern u8 D_00371978[];
extern u8 D_00371980[];
extern u8 D_00371988[];
extern u8 D_00371990[];
extern u8 D_00371998[];
inline static u8 *NewLayout(void)
{
  u8 *o = func_0023ee30(160);
  *((u8 **) o) = D_00347f98;
  func_0031a838(o + 12);
  *((u8 **) o) = D_0035eb98;
  func_002369a0(o + 24);
  func_0023c008(o + 48);
  return o;
}

static inline s32 inline_fn(s32 arg0)
{
  return arg0;
}

// Builds the slot-select layout: two entries, a centred column, then the
// header/title objects (w3892/w3902, zl90).
void func_00243740(void)
{
  s32 i;
  s32 n;
  s32 sel;
  s32 w;
  s32 half;
  s32 k;
  u8 *o;
  VObj *p;
  sel = 0;
  k = 0;
  D_0035ed0c = 0;
  D_0035ecf0 = NewLayout();
  func_0028d7f0(D_0035ecf0, 30002, 0, 0, 30, 32, 0, 0, 0);
  func_0023ef50(D_0035ecf0);
  for (i = 0; i < 2; i++)
  {
    if (func_00244938(i))
    {
      if (func_002431d0(3, i) == 0)
      {
        D_0035ed14 |= 1 << i;
      }
      if (D_003719a0[i].f10)
      {
        sel = i;
      }
      func_00288d80(D_0035ece8, k, 0, 0, D_0035ecf0, D_003719a0[i].f12, &D_003719a0[i], D_003719a0[i].name);
      o = func_002891b8(D_0035ece8, k++);
      p = (VObj *) func_0023aa98(o + 24);
      *((s32 *) (o + 432)) = func_0028dd90((s32) p);
      *((s32 *) (o + 428)) = func_0028ddd8((s32) p);
      func_001395f8(o);
    }
  }

  n = func_002892f8(D_0035ece8);
  w = func_0023aa78(func_002891b8(D_0035ece8, 0) + 24);
  half = (w * n) / 2;
  for (i = 0; i < n; i++)
  {
    func_00138c68(func_002891b8(D_0035ece8, i), 0, i * w - half);
  }

  func_002891f0(D_0035ece8, sel, 0, -1, -1);
  func_002449c0();
  sel = func_002891e8(D_0035ece8);
  func_002891f0(D_0035ece8, sel, 1, 0, 2);
  half = func_00244ee8(sel);
  func_002b4070(D_0035ed08, 30003, D_0035ecf0, D_00371960, D_00371978, D_00371980, D_00371988, D_00371990, D_00371998, 0xcb96, &D_003719a0[half], 0, 0);
  D_0035ecf8 = NewLayout();
  func_0028d7f0(D_0035ecf8, 30002, 0, 0, D_00371968[half][0], D_00371968[half][2], 0, 0, 0);
  func_0023ef50(D_0035ecf8);
  D_0035ecf4 = NewLayout();
  func_0028d7f0(D_0035ecf4, 30019, 0, 0, 33, 35, 0, 0, 0);
  func_0023ef50(D_0035ecf4);
  if (func_001a6d08(10) && func_00244a10())
  {
    func_0028af40(D_0035ece8, 512);
    func_0028d980(D_0035ecfc, 30011, 0, 0, D_0035ecf0, 31, 33, 3971, 0);
    func_00139620(D_0035ecfc);
    func_001395f8(D_0035ecfc);
    D_0035ecfc[405] = 1;
    {
      u8 *q = D_0035ecfc + 24;
      *((u32 *) (q + 184)) |= 8;
    }
  }
  func_00244a60();
  p = func_00287dc0();
  func_0023d808(p, 30008);
  p->vt->f18(p, 0, 0x2000044d, 134, 2, 155, 221);
  func_0023e858(p, 0, -457.0f);
  func_0023e8b8(p, 0, 0.0f);
  func_0023e8d8(p, 0, 30.0f);
  {
    u8 *s = D_0035ed08;
    func_00139d78(*((s32 *) (s + 8)));
    func_0023e9b0(p, 0, inline_fn(*((s32 *) (s + 8))));
  }
  func_0023e690(p, 0, 135, -1);
  func_00287bd0(0, 0);
  func_00287cc0(0);
  n = func_002887c8();
  if (n)
  {
    func_00243e30();
    D_0035ed0c = 1;
    func_00288750(func_00244058);
  }
}

}
