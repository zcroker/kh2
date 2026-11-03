#include "../common/types.h"
extern "C" {
extern s32 D_0035f200;
extern s8 *D_0035f5d0;
struct Sram { u8 pad[316]; u32 bits[8]; };
struct Ent { u8 pad[408]; };
struct Seq { u8 pad[0xa998]; Ent e[4]; };
Sram *func_002a9d68(void);
Seq *func_002766d0(void);
s32 func_00287bc0(void);
s32 func_0028b040(s32);
s32 func_00276638(s32);
s32 func_002a01c8(s32);
s32 func_002943e8(s32);
void func_002aa450(s32);
s32 func_002891e8(s32);
s32 func_00139d78(Ent *);
void func_00138c10(Ent *, s32);
// Register pin: idx in s1 (the original keeps the D_0035f5d0 %hi in s0).
void func_002a03d0(void)
{
  register s32 idx asm("$17");
  Sram *a = func_002a9d68();
  Seq *b = func_002766d0();
  s32 c = func_00287bc0();
  if (c == 24) idx = func_0028b040(D_0035f200);
  else idx = func_00276638(24);
  if (!func_002943e8(func_002a01c8(D_0035f5d0[idx + 6]))) return;
  s32 k = D_0035f5d0[idx + 6];
  u32* q = &a->bits[(u32)k >> 5]; if (*q & (1 << (k & 31))) return;
  func_002aa450(k);
  if (c != 24) return;
  s32 m = 408;
  m = func_002891e8(D_0035f200) * m;
  Ent *p = (Ent*)((u8*)b + m + 0xa998);
  if (func_00139d78(p)) func_00138c10(p, 93);
}
}
