#include "../common/types.h"

/* ---- func_001921d8: formats a name string into the shared buffer D_01c61ab8 ---- */
char* func_00105ee8(void);
s32 func_002fee78(char*, const char*, ...);
extern char D_01c61ab8[];
extern char D_0036cd78[];
extern char D_0036cd80[];
extern char D_0036cd88[];
extern char D_0036cd98[];
extern s32 D_0033caf4;
static inline const char* nm(s32 a) {
    switch (a) {
    case 101: return D_0036cd78;
    case 100: return D_0036cd80;
    case 102: return D_0036cd98;
    }
    return func_00105ee8();
}
/* the $7 pin puts "move a3,v0" before the jal and "addiu a1" into its delay slot, as the original does */
// 001921d8: moved to src/yasui/libys/message.cpp

/* ---- func_002b31c0 ---- */


u8 *func_002766d0(void);
s32 func_0028b040(s32);
extern s32 D_0035f200;
extern u8 *D_0035f224;
extern u8 *D_0035f638;
void func_0014b950(u8 *, s16, s16, u16, u16);
void func_0014b9a8(u8 *);
s32 func_0023aa58(u8 *);
s32 func_0023aa78(u8 *);
u8 *func_001aae68(s32);
s32 func_00192048(s32);
void func_001a98e8(void *, s32, s32, s32, s32);
void func_001aa6d0(void *, s32);
void func_001a9ae8(void *, s32, s32, s32);
void func_002b31c0(s32 a0, s32 a1, s32 a2)
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
  func_0014b950(D_0035f224 + 32, a0, a1, x2, (*((s16 *) (D_0035f638 + 40))) * 9);
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
  /* $14 (t6) pin: the original loads q+20 into t6 */
  { register s32 t asm("$14") = *(s32*)(q + 20); y = (y - h) - t; }
  y = (y < 0) ? 0 : y;
  func_001a98e8(buf, 3, func_00192048(20298), h, 0);
  new_var = &a1;
  func_001aa6d0(buf, y);
  func_001a9ae8(buf, a0, *new_var, a2);
  func_0014b9a8(D_0035f224);
}
