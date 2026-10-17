#include "../common/types.h"
extern "C" {


u8 *func_002766d0(void);
s32 func_0028b040(s32);
extern s32 D_0035f200;
extern u8 *D_0035f224;
extern u8 *D_0035f5d0;
void func_0014b950(u8 *, s16, s16, u16, u16);
void func_0014b9a8(u8 *);
s32 func_0023aa58(u8 *);
s32 func_0023aa78(u8 *);
u8 *func_001aae68(s32);
s32 func_00192048(s32);
void func_001a98e8(void *, s32, s32, s32, s32);
void func_001aa6d0(void *, s32);
void func_001a9ae8(void *, s32, s32, s32);
void func_002a0200(s32 a0, s32 a1, s32 a2)
{
  u8 buf[96];
  s32 h = 15;
  u8 *p = func_002766d0() + 24;
  s32 w = func_0028b040(D_0035f200);
  u16 x2 = 512 - a0;
  s32 *new_var;
  s32 n;
  s32 m;
  s32 y;
  u8 *q;
  func_0014b950(D_0035f224 + 32, a0, a1, x2, (*((s8 *) (D_0035f5d0 + 2))) * 9);
  func_0014b9a8(D_0035f224 + 32);
  n = func_0023aa58(p);
  m = func_0023aa78(p);
  if (n)
  {
    h = n;
  }
  w = w * m;
  y = m;
  a1 -= w;
  q = func_001aae68(3);
  y = (y - h) - (*((s32 *) (q + 20)));
  y = (y < 0) ? 0 : y;
  func_001a98e8(buf, 3, func_00192048(*((u16 *) (D_0035f5d0 + 4))), h, 0);
  new_var = &a1;
  func_001aa6d0(buf, y);
  func_001a9ae8(buf, a0, *new_var, a2);
  func_0014b9a8(D_0035f224);
}

}
