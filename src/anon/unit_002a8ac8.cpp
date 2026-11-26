// Linked unit 0x002a8ac8-0x002a9100 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 002a8ac8 (was src/anon/batch_w1586_g.cpp)
namespace n002a8ac8 {
s32 func_00276348(void) asm("func_00276348");
s32 func_002766d0(void) asm("func_002766d0");
s32 func_0028f930(s32) asm("func_0028f930");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void func_002a9100(void) asm("func_002a9100");
void func_00276e78(void) asm("func_00276e78");
void func_0028d8c0(s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_00139620(s32) asm("func_00139620");
void func_0028dcc0(s32, s32) asm("func_0028dcc0");
void func_00288d80(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("func_00288d80");
s32 func_002891b8(s32, s32) asm("func_002891b8");
void func_002a92d8(void) asm("func_002a92d8");
void* func_0023f1b0(s32) asm("func_0023f1b0");
s32 func_0023c4b8(void*, s32) asm("func_0023c4b8");
s32 func_00236ca8(s32, s32) asm("func_00236ca8");
s32 func_00276678(void) asm("func_00276678");
void func_0028bae0(s32, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028bae0");
void func_0028af90(s32, s32) asm("func_0028af90");
void func_002891f0(s32, s32, s32, s32, s32) asm("func_002891f0");
void func_0028afd0(s32, s32) asm("func_0028afd0");
void func_00276690(s32) asm("func_00276690");
void func_0028af28(s32, s32) asm("func_0028af28");
void func_0028b218(s32, s32) asm("func_0028b218");
void func_0028b248(s32, s32) asm("func_0028b248");
void func_002a9048(void) asm("func_002a9048");
void func_002a98a8(void) asm("func_002a98a8");
void func_002a95a8(void) asm("func_002a95a8");
void func_002a9888(void) asm("func_002a9888");
void func_00287cc0(s32) asm("func_00287cc0");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f200 asm("D_0035f200");
extern s32 D_0035f214 asm("D_0035f214");
extern s32* D_0035f608 asm("D_0035f608");
/*TARGET 002a8ac8*/
void func_002a8ac8(void) asm("func_002a8ac8");
void func_002a8ac8(void) {
    s16 arr[4];
    s32 a = func_00276348();
    s32 b = func_002766d0();
    s32 i, n, c, v, cnt, lim, r0, r1, r2;
    s16* p;
    if (!func_0028f930(0)) func_0028f4d8(0, -1, 0);
    for (i = 0; i < 4; i++) arr[i] = 2;
    func_002a9100();
    n = D_0035f3d4 - 1;
    c = b + 0x4c8;
    func_00276e78();
    func_0028d8c0(b, n, D_0035f14c, D_0035f148, D_0035f210, 101, -1, 0);
    v = 10;
    func_00139620(b);
    func_0028dcc0(b, a);
    func_0028d8c0(c, n, D_0035f14c, D_0035f148, D_0035f210, 109, -1, 0);
    func_00139620(c);
    func_0028dcc0(c, a);
    func_00288d80(D_0035f200, 0, D_0035f14c, D_0035f148, D_0035f210, -1, arr, arr);
    r0 = func_002891b8(D_0035f200, 0);
    func_00139620(r0);
    func_0028dcc0(r0, b);
    func_002a92d8();
    n = D_0035f3d4;
    lim = *D_0035f608;
    if (lim >= 11) v = lim;
    cnt = lim - 10;
    if (cnt > 0) cnt = lim - 9; else cnt = 1;
    r1 = func_0023c4b8(func_0023f1b0(D_0035f210), D_0035f14c);
    { void* o = func_0023f1b0(D_0035f210); s32 k = D_0035f148;
    r2 = func_00236ca8(*(s32*)((u8*)o + 0x28), k); }
    func_0028bae0(D_0035f214, n, r1, r2, func_00276678(), v, 10, c, 0);
    func_0028af90(D_0035f200, cnt);
    func_002891f0(D_0035f200, 0, 0, -1, -1);
    func_0028afd0(D_0035f200, 0);
    func_00276690(1);
    func_0028af28(D_0035f200, 16);
    if (cnt >= 2) {
        func_0028b218(D_0035f200, 1);
        func_0028b248(D_0035f200, 10);
    }
    func_002a9048();
    func_002a98a8();
    func_002a95a8();
    func_002a9888();
    func_00287cc0(0);
}
}  // namespace n002a8ac8

// 002a8d98 (was src/anon/batch_w1262.cpp)
namespace n002a8d98 {
s32 func_00289380(void *s) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00276368(void) asm("func_00276368");
s32 func_00276888(void) asm("func_00276888");
void func_00287f90(s32 a) asm("func_00287f90");
s32 func_00292630(void) asm("func_00292630");
void func_00276690(s32 a) asm("func_00276690");
void func_00287c30(void) asm("func_00287c30");
s32 func_00276358(void) asm("func_00276358");
void func_00276220(s32 a, s32 b) asm("func_00276220");
void func_00274cf0(s32 a) asm("func_00274cf0");
void func_002925c0(void) asm("func_002925c0");
void func_002995e8(void) asm("func_002995e8");
s32 func_00276398(void) asm("func_00276398");
void func_00275b60(void) asm("func_00275b60");
void func_00287c90(s32 a) asm("func_00287c90");
s32 func_00242848(s32 a) asm("func_00242848");
void func_0028f6f0(s32 a) asm("func_0028f6f0");
void func_00276dc0(void) asm("func_00276dc0");
s32 func_0028b038(void *s) asm("func_0028b038");
void func_002765e8(s32 a, s32 b, s32 c) asm("func_002765e8");
void func_00287c00(s32 m) asm("func_00287c00");
void func_00287cc0(s32 s) asm("func_00287cc0");
void func_00287da0(void) asm("func_00287da0");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
extern void *D_0035f200 asm("D_0035f200");
s32 func_0028acc8(void *s) asm("func_0028acc8");
unsigned int func_0028af18_b(void *s, u32 a) asm("func_0028af18");
s32 func_00289310(void *s) asm("func_00289310");
s32 func_00287df0(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_002891e8(void *s) asm("func_002891e8");
void func_002958b0(void) asm("func_002958b0");
void func_002a8a88(void) asm("func_002a8a88");
void func_002a8a80(void) asm("func_002a8a80");
/*TARGET 002a8d98*/
void func_002a8d98(void) asm("func_002a8d98");
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
}  // namespace n002a8d98

// 002a9048 (was src/anon/batch_w68.cpp)
namespace n002a9048 {
s32 func_00287bc0(void) asm("func_00287bc0");
// 0x00287a28: definition moved into src/anon/unit_00286d28.cpp

/* ---- 002a9048 ---- */
s8* func_00276568(void) asm("func_00276568");
struct E18 { s8 id; s8 flag; u8 pad[2]; };
struct T18 { s32 n; E18 e[1]; };
extern T18* D_0035f608 asm("D_0035f608");
extern void* D_0035f200 asm("D_0035f200");
s32 func_0028afa8(void*) asm("func_0028afa8");
void func_0028afd0(void*, s32) asm("func_0028afd0");
/*TARGET 002a9048*/
// obj_set_signed18

void func_002a9048(void) asm("func_002a9048");
// obj_set_signed18

void func_002a9048(void) {
    s32 sel;
    if (func_00287bc0() == 35) {
        sel = 0;
    } else {
        s32 n = D_0035f608->n;
        s32 k = *func_00276568();
        s32 i;
        for (i = 0; i < n; i++) {
            if (k == D_0035f608->e[i].id && D_0035f608->e[i].flag < 0) break;
        }
        sel = i;
        if (sel >= func_0028afa8(D_0035f200)) sel = func_0028afa8(D_0035f200) - 1;
    }
    func_0028afd0(D_0035f200, sel);  // obj_set_signed18
}
}  // namespace n002a9048

