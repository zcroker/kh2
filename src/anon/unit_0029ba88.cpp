// Linked unit 0x0029ba88-0x0029cdf8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/jm_dic.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../harata/libdk/glow.hpp"

// 0029ba88 (was src/anon/batch_wcx2.cpp)
namespace n0029ba88 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
// ---- 0029ba88
extern void* D_0035f200 asm("D_0035f200");
extern s8 D_0035f5c4 asm("D_0035f5c4");
s32 func_00289380(void* s) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00276368(void) asm("func_00276368");
s32 func_0028acc8_ba88(void* s) asm("func_0028acc8");
s32 func_00276888(void) asm("func_00276888");
void func_00287f90(s32 a) asm("func_00287f90");
s32 func_00287c10(void) asm("func_00287c10");
void func_0029aac0(s32 m) asm("func_0029aac0");
s32 func_00292630(void) asm("func_00292630");
s32 func_00293200(void) asm("func_00293200");
void func_00276690(s32 a) asm("func_00276690");
void func_002766b0(s32 a) asm("func_002766b0");
void func_00287c30(void) asm("func_00287c30");
void func_0028af18_ba88(void* s, u32 a) asm("func_0028af18");
s32 func_00276358(void) asm("func_00276358");
void func_00276220(s32 a, s32 b) asm("func_00276220");
void func_00274cf0(s32 a) asm("func_00274cf0");
// state_dispatch_0_1_2
void func_002925c0(void) asm("func_002925c0");
void func_002995e8(void) asm("func_002995e8");
void func_0029af20(void) asm("func_0029af20");
void func_0029be08(void) asm("func_0029be08");
s32 func_00289310_ba88(void* s) asm("func_00289310");
s32 func_00276398(void) asm("func_00276398");
// state_is_150
void func_00275b60(void) asm("func_00275b60");
void func_00287c90(s32 a) asm("func_00287c90");
void func_0029ecf0_x5029(void) asm("func_0029ecf0");
s32 func_00287df0_ba88(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a) asm("func_00242848");
void func_0028f6f0(s32 a) asm("func_0028f6f0");
// record884_refresh_by_index
void func_0029aa30(void) asm("func_0029aa30");
void func_00276dc0(void) asm("func_00276dc0");
s32 func_002891e8_ba88(void* s) asm("func_002891e8");
s32 func_0028b038(void* s) asm("func_0028b038");
void func_002765e8(s32 a, s32 b, s32 c) asm("func_002765e8");
void func_00287c00(s32 m) asm("func_00287c00");
void func_00287cc0(s32 s) asm("func_00287cc0");
void func_00287da0(void) asm("func_00287da0");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
/*TARGET 0029ba88*/
// global_zero_4dwords

void func_0029ba88(void) asm("func_0029ba88");
// global_zero_4dwords

void func_0029ba88(void) {
    s32 cur = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    s32 mode = func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_0028acc8_ba88(D_0035f200) || func_00276888()) {
            if (cur == -1) return;
            func_00287f90(0);
            func_0029aac0(func_00287c10());
            return;
        }
        if (func_00292630()) return;
        if (func_00293200()) return;
        func_00276690(0);
        func_002766b0(1);
        func_0029aac0(func_00287c10());
        func_00287c30();
        mode = func_00287bc0();
        func_0028af18_ba88(D_0035f200, 115);
        func_00276220(func_00276358(), 0);
        if (mode == 13) {
            func_00274cf0(13);  // state_dispatch_0_1_2
            func_002925c0();
            func_002766b0(0);
            func_002995e8();
        } else if (mode == 14) {
            func_0029af20();
        } else if (mode == 16 || mode == 19 || mode == 22) {
            D_0035f5c4 = -1;
            func_0029be08();
        }
        return;
    }
    if (cur != -1 || func_00289310_ba88(D_0035f200)) {
        if (!func_00276398()) {  // state_is_150
            func_00276220(0, 2);
            func_00275b60();
        }
    }
    if (st == 0 && func_00276398()) func_00287c90(1);  // state_is_150
    if (!func_00242848(func_00287df0_ba88(cur, func_00289310_ba88(D_0035f200), 1, func_0029ecf0_x5029, 1))) {
        s32 next;
        switch (cur) {
        case -2:
            if (mode == 15) {
                func_0028f6f0(1);  // record884_refresh_by_index
                next = 14;
            } else {
                func_0028f6f0(0);  // record884_refresh_by_index
                next = 13;
            }
            func_0029aa30();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(next);
            func_00287cc0(2);
            break;
        case -4:
            func_00287da0();
            break;
        case -1:
            break;
        default: {
            if (mode == 15) next = 16;
            else next = mode == 18 ? 19 : 22;
            func_0029aa30();
            func_00276dc0();
            s32 a = func_002891e8_ba88(D_0035f200);
            func_002765e8(15, a, func_0028b038(D_0035f200));
            func_00276220(0, 1);
            func_00287c00(next);
            func_00287cc0(2);
            break;
        }
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0029ba88
#undef QCOPY

// 0029be08 (was src/anon/perm_0029be08.cpp)
namespace n0029be08 {
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
struct Lst29be08
{
  u8 pad[5];
  s8 count;
  u8 pad2[2];
  s16 ids[1];
};
struct Obj29be08
{
  u8 pad[420];
  u32 f420;
  u8 pad2[4];
  s32 f428;
  u8 pad3[4];
  void *f436;
};
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f210 asm("D_0035f210");
union G29be08
{
  void *p;
  u8 c;
};
extern G29be08 D_0035f200 asm("D_0035f200");
extern Lst29be08 *D_0035f5ac asm("D_0035f5ac");
void *func_00276348(void) asm("func_00276348");
void *func_002766d0(void) asm("func_002766d0");
void func_00293d80(s32 a) asm("func_00293d80");
void func_0029dd00(void) asm("func_0029dd00");
void func_0029dd60(void) asm("func_0029dd60");
void func_00276e78(void) asm("func_00276e78");
void func_0028d8c0(void *w, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g) asm("func_0028d8c0");
void func_00139620(void *w) asm("func_00139620");
void func_0028dcc0(void *a, void *b) asm("func_0028dcc0");
void func_00288d80(void *s, s32 a, s32 b, s32 c, s32 d, s32 e, s16 *f, s16 *g) asm("func_00288d80");
Obj29be08 *func_002891b8(void *s, s32 a) asm("func_002891b8");
void func_001395f8(void *o) asm("func_001395f8");
void func_0029d318(void) asm("func_0029d318");
void func_0029daa0(void) asm("func_0029daa0");
void func_00276690(s32 a) asm("func_00276690");
void func_0028af28(void *s, s32 a) asm("func_0028af28");
u8 *func_00294000(s32 a) asm("func_00294000");
s32 func_002943b0(u8 *p) asm("func_002943b0");
u32 func_0028af88(void *s) asm("func_0028af88");
void func_0028af18(void *s, u32 a) asm("func_0028af18");
void func_0028b1e8(void *s, s32 a) asm("func_0028b1e8");
volatile unsigned short func_0029e960(void) asm("func_0029e960");
void func_0029ea30(void) asm("func_0029ea30");
void func_00287cc0(s32 a) asm("func_00287cc0");
void func_0029dba0(void) asm("func_0029dba0");
/*TARGET 0029be08*/
void func_0029be08(void) asm("func_0029be08");
void func_0029be08(void)
{
  s16 c[2][4];
  s32 i;
  s32 j;
  s32 n;
  s32 m;
  void *o = func_00276348();
  void *w = func_002766d0();
  u8 *t;
  u32 fl;
  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 4; j++)
    {
      c[i][j] = 2;
    }

  }

  m = D_0035f3d4 - 1;
  func_00293d80(5101);
  func_0029dd00();
  func_0029dd60();
  func_00276e78();
  n = 0;
  func_0028d8c0(w, m, D_0035f14c, D_0035f148, D_0035f210, 75, -1, 0);
  func_00139620(w);
  func_0028dcc0(w, o);
  func_00288d80(D_0035f200.p, 0, D_0035f14c, D_0035f148, D_0035f210, -1, c[0], c[1]);
  func_00139620(func_002891b8(D_0035f200.p, 0));
  func_0028dcc0(func_002891b8(D_0035f200.p, 0), w);
  func_002891b8(D_0035f200.p, 0)->f428 = 3;
  func_002891b8(D_0035f200.p, 0)->f420 = 0x60000008;
  func_002891b8(D_0035f200.p, 0)->f436 = (void *) func_0029dba0;
  func_001395f8(func_002891b8(D_0035f200.p, 0));
  func_0029d318();
  func_0029daa0();
  func_00276690(1);
  func_0028af28(D_0035f200.p, 16);
  t = func_00294000(3) + 16;
  for (i = 0; i < D_0035f5ac->count; i++)
  {
    if (func_002943b0(t + (D_0035f5ac->ids[i] * 36)))
    {
      n++;
    }
  }

  fl = func_0028af88(D_0035f200.p);
  if (n >= 2)
  {
    fl |= 0xc000;
  }
  func_0028af18(D_0035f200.p, fl | 0x200);
  func_0028b1e8(D_0035f200.p, 0);
  func_0029e960();
  func_0029ea30();
  func_00287cc0(0);
}
}  // namespace n0029be08

// 0029c098 (was src/anon/perm_0029c098.cpp)
namespace n0029c098 {
typedef signed char s8;
typedef signed int s32;
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00289380(void *) asm("func_00289380");
s32 func_0029e2f8(s32) asm("func_0029e2f8");
void func_0029e4c8(s32) asm("func_0029e4c8");
s32 func_00287c10(void) asm("func_00287c10");
s32 func_00276368(void) asm("func_00276368");
s32 func_0028acc8(void *) asm("func_0028acc8");
s32 func_00276888(void) asm("func_00276888");
s32 func_0029ad40(void) asm("func_0029ad40");
s32 func_00292630(void) asm("func_00292630");
void func_0029e430(void) asm("func_0029e430");
void func_00276690(s32) asm("func_00276690");
void func_002766b0(s32) asm("func_002766b0");
void func_0029aac0(s32) asm("func_0029aac0");
s32 func_00276358(void) asm("func_00276358");
void func_00276220(s32, s32) asm("func_00276220");
void func_00287c30(void) asm("func_00287c30");
long long func_0028af18(void *, s32) asm("func_0028af18");
void func_0028b1e8(void *, s32) asm("func_0028b1e8");
void func_0029e9d0(void) asm("func_0029e9d0");
void func_00287bd0(s32, s32) asm("func_00287bd0");
s32 func_00276638(s32) asm("func_00276638");
void func_002a0908(s32) asm("func_002a0908");
void func_0029b698(void) asm("func_0029b698");
void func_0029be08(void) asm("func_0029be08");
void func_0029c568(void) asm("func_0029c568");
void func_00287f90(s32) asm("func_00287f90");
void func_0029e298(s32) asm("func_0029e298");
void func_0029de18(void) asm("func_0029de18");
s32 func_00289310(void *) asm("func_00289310");
s32 func_00276398(void) asm("func_00276398");
void func_00275b60(void) asm("func_00275b60");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, void (*)(void), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_0029ecf0(void) asm("func_0029ecf0");
void func_00287da0(void) asm("func_00287da0");
void func_0029cb28(s32) asm("func_0029cb28");
void func_0029aa30(void) asm("func_0029aa30");
void func_00287c00(s32) asm("func_00287c00");
void func_00287cc0(s32) asm("func_00287cc0");
void func_0029e258(s32) asm("func_0029e258");
void func_00276dc0(void) asm("func_00276dc0");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
extern void *D_0035f200 asm("D_0035f200");
extern s8 D_0035f5c4 asm("D_0035f5c4");
/*TARGET 0029c098*/
void func_0029c098(void) asm("func_0029c098");
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
}  // namespace n0029c098

// 0029c568 (was src/anon/batch_w1589.cpp)
namespace n0029c568 {
void func_0029dfc0(void) asm("func_0029dfc0");
void func_0029e4c8(s32) asm("func_0029e4c8");
void func_00276690(s32) asm("func_00276690");
u32 func_0028af88(s32) asm("func_0028af88");
void func_0028af18(s32, u32) asm("func_0028af18");
void func_00287cc0(s32) asm("func_00287cc0");
extern s32 D_0035f200 asm("D_0035f200");
/*TARGET 0029c568*/
// 0x002799b0: definition moved into src/anon/unit_002793b0.cpp

void func_0029c568(void) asm("func_0029c568");
// 0x002799b0: definition moved into src/anon/unit_002793b0.cpp

void func_0029c568(void)
{
    func_0029dfc0();
    func_0029e4c8(1);
    func_00276690(1);
    func_0028af18(D_0035f200, ((func_0028af88(D_0035f200) & ~0x50) | 0x30000) & ~3);
    func_00287cc0(0);
}
}  // namespace n0029c568

// 0029c5c8 (was src/anon/batch_w3725.cpp)
namespace n0029c5c8 {
struct S29c { u8 p0[5]; s8 b5; };
extern s32 D_0035f200 asm("D_0035f200");
extern S29c* D_0035f5ac asm("D_0035f5ac");
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0029e2f8(s32) asm("func_0029e2f8");
void func_0029e4c8(s32) asm("func_0029e4c8");
s32 func_00292630(void) asm("func_00292630");
void func_0029e430(void) asm("func_0029e430");
void func_00287c30(void) asm("func_00287c30");
void func_0028af18(s32, s32) asm("func_0028af18");
void func_0028af28(s32, s32) asm("func_0028af28");
s32 func_0028af88(s32) asm("func_0028af88");
void func_0028b1e8(s32, s32) asm("func_0028b1e8");
s32 func_0028afa8(s32) asm("func_0028afa8");
void func_0028b218(s32, s32) asm("func_0028b218");
void func_0028b248(s32, s32) asm("func_0028b248");
void func_0029ea30(void) asm("func_0029ea30");
void func_00287cc0(s32) asm("func_00287cc0");
void func_00287f90(s32) asm("func_00287f90");
void func_0029e298(s32) asm("func_0029e298");
s32 func_00289310(s32) asm("func_00289310");
s32 func_0029e0f8(void) asm("func_0029e0f8");
void func_0029e148(void) asm("func_0029e148");
void func_00287c90(s32) asm("func_00287c90");
void func_00242618(s32, s32) asm("func_00242618");
void func_0029e050(void) asm("func_0029e050");
void func_0029e258(s32) asm("func_0029e258");
void func_00287c00(s32) asm("func_00287c00");
void func_0029e808(s32) asm("func_0029e808");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
/*TARGET 0029c5c8*/
void func_0029c5c8(void) asm("func_0029c5c8");
void func_0029c5c8(void)
{
    register s32 r asm("$17") = func_00289380(D_0035f200);
    s32 mode = func_00287cd0();
    register s32 m asm("$18") = func_00287bc0();
    register s32 i asm("$16");
    if (mode != 2 && !func_0029e2f8(1)) func_0029e4c8(1);
    if (__builtin_expect(mode == 2, 1)) {
        for (i = 0; i < 2; i++)
            if (func_0029e2f8(i)) goto found;
        if (func_00292630()) return;
        func_0029e430();
        func_00287c30();
        m = func_00287bc0();
        func_0028af18(D_0035f200, 115);
        if (m == 16 || m == 19 || m == 22) {
            s32 f;
            func_0028af28(D_0035f200, 16);
            f = func_0028af88(D_0035f200);
            {
                s32 g = f;
                S29c* q = D_0035f5ac;
                s32 h = f | 0xc000;
                if (q->b5 >= 2) g = h;
                asm("" : "+r"(g) : "r"(h), "r"(q));
                func_0028af18(D_0035f200, g | 0x200);
            }
            func_0028b1e8(D_0035f200, 0);
            if (func_0028afa8(D_0035f200) >= 2) {
                func_0028b218(D_0035f200, 1);
                func_0028b248(D_0035f200, 7);
            }
            func_0029ea30();
            func_00287cc0(0);
        }
        return;
    found:
        if (r != -1) {
            func_00287f90(0);
            for (i = 0; i < 2; i++) func_0029e298(i);
        }
    } else {
        if ((r != -1 || func_00289310(D_0035f200)) && !func_0029e0f8()) func_0029e148();
        if (mode == 0 && func_0029e0f8()) func_00287c90(1);
        if (r == -2) func_00242618(3, 1);
        switch (r) {
        case -2: {
            s32 id = 16;
            if (m != 17) id = (m != 17) ? 22 : 16;
            asm("" : : "r"(m));
            func_0029e050();
            func_0029e258(1);
            func_00287c00(id);
            func_00287cc0(2);
            break;
        }
        case -11: case -10: case -9: case -8: case -7: case -6: case -5: case -4: case -3: case -1:
            break;
        case -13:
        case -12:
            func_0029e808(r);
            break;
        }
        if (func_00288040()) func_00288018();
    }
}
}  // namespace n0029c5c8

// 0029c880 (was src/anon/batch_w87.cpp)
namespace n0029c880 {
// 0x002864f8: definition moved into src/anon/unit_002853b8.cpp

// ---- 0x29c880 ----
union GB { u8* p; u16 h; u32 u; };
extern u8 D_0035f5c4 asm("D_0035f5c4");
extern GB D_0035f5ac asm("D_0035f5ac");
u8* func_00276568(void) asm("func_00276568");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_0029dd00(void) asm("func_0029dd00");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
void func_0029be08(void) asm("func_0029be08");
/*TARGET 0029c880*/
void func_0029c880(s8* p, s32 k) asm("func_0029c880");
void func_0029c880(s8* p, s32 k) {
    D_0035f5c4 = k;
    D_0035f5ac.p[5] = p[0];
    u8* o = D_0035f5ac.p;
    o[4] = k == 6 ? *func_00276568() : 16;
    for (s32 i = 0; i < p[0]; i++) ((u16*)(D_0035f5ac.p + 8))[i] = *(u16*)(p + 80 + i * 8);
    func_00287bd0(16, 0);
    func_0029dd00();
    s32 a = p[1];
    s32 b = 0;
    if (a >= 10) { b = a - 9; a = 9; }
    func_002765e8(15, a, b);
    func_0029be08();
}
}  // namespace n0029c880

// 0029c958 (was src/anon/batch_w50.cpp)
namespace n0029c958 {
s32 func_002954e0(s32) asm("func_002954e0");
s32 func_00276c18(void) asm("func_00276c18");
extern u32* D_0035f5ac asm("D_0035f5ac");
/*TARGET 0029c958*/
// 0x00288c58: definition moved into src/anon/unit_00288b00.cpp

void func_0029c958(void) asm("func_0029c958");
// 0x00288c58: definition moved into src/anon/unit_00288b00.cpp

void func_0029c958(void) {
    u32 mask = 0;
    for (s32 i = 0; i < 15; i++) {
        if (func_002954e0(i) || func_00276c18()) mask |= 1 << (i + 1);
    }
    mask |= 1;
    *D_0035f5ac = mask;
}
}  // namespace n0029c958

// 0029c9d8 (was src/anon/batch_w46.cpp)
namespace n0029c9d8 {
// 0x00293148: definition moved into src/anon/unit_00292e60.cpp

// ---- 0029c9d8
s32 func_0028b040(u32) asm("func_0028b040");
extern u32 D_0035f200 asm("D_0035f200");
extern s32* D_0035f5ac asm("D_0035f5ac");
/*TARGET 0029c9d8*/
s32 func_0029c9d8(s32 n) asm("func_0029c9d8");
s32 func_0029c9d8(s32 n) {
    if (n < 0) n = func_0028b040(D_0035f200);
    s32 m = *D_0035f5ac;
    s32 c = 0;
    s32 i;
    for (i = 0; i < 19; i++) {
        if ((u8)((m >> i) & 1)) {
            if (c == n) break;
            c++;
        }
    }
    return i ? i - 1 : 16;
}
}  // namespace n0029c9d8

// 0029ca50 (was src/anon/batch_w2441_nsa.cpp)
namespace n0029ca50 {
struct W2441Ent { s8 slot; u8 f1; u8 pad[14]; };
struct W2441Hdr { u8 h[16]; W2441Ent e[1]; };
W2441Hdr* func_00294000(s32) asm("func_00294000");
struct W1595Ent { s8 kind; u8 pad[35]; };
struct W1595Hdr { s32 a, b, count, c; W1595Ent e[1]; };
struct W1595List { s32 a; s8 kind; u8 n; u16 pad; s16 list[1]; };
s32 func_002943b0(W1595Ent*) asm("func_002943b0");
s32 func_00276c18() asm("func_00276c18");
extern W1595List* D_0035f5ac asm("D_0035f5ac");
/*TARGET 0029ca50*/
// 0x002ac678: definition moved into src/anon/unit_002a99c8.cpp

void func_0029ca50(void) asm("func_0029ca50");
// 0x002ac678: definition moved into src/anon/unit_002a99c8.cpp

void func_0029ca50(void) { s32 i = 0; s32 n = 0; W1595Hdr* h = (W1595Hdr*)func_00294000(3); s8 k = D_0035f5ac->kind; W1595Ent* base = h->e;
 for (; i < h->count; i++) { W1595Ent* e = &base[i]; if (e->kind != k) continue; if (!func_002943b0(e) && !func_00276c18()) continue; D_0035f5ac->list[n++] = i; }
 D_0035f5ac->n = n; }
}  // namespace n0029ca50

// 0029cb28 (was src/anon/batch_w110.cpp)
namespace n0029cb28 {
struct IdList { u8 pad[5]; s8 count; u8 pad6[2]; s16 ids[1]; };
extern IdList* D_0035f5ac asm("D_0035f5ac");
u8* func_00294000(s32) asm("func_00294000");
s32 func_00276638(s32) asm("func_00276638");
s32 func_00276620(s32) asm("func_00276620");
s32 func_002943b0(u8*) asm("func_002943b0");
// test_bit_global_array
void func_002765e8(s32, s32, s32) asm("func_002765e8");
void func_0029eaa8(void) asm("func_0029eaa8");
/*TARGET 0029cb28*/
// Moves the list cursor to the next/previous usable entry (wrapping) and scrolls the 10-row window.
void func_0029cb28(s32 dir) asm("func_0029cb28");
// Moves the list cursor to the next/previous usable entry (wrapping) and scrolls the 10-row window.
void func_0029cb28(s32 dir) {
    u8* base = func_00294000(3) + 16;
    s32 cur = func_00276638(15);
    s32 top = func_00276620(15);
    s32 i;
    if (dir == -10) {
        for (i = cur + 1; i < D_0035f5ac->count; i++)
            if (func_002943b0(base + D_0035f5ac->ids[i] * 36)) break;
        if (i >= D_0035f5ac->count) {
            for (i = 0; i < cur; i++)
                if (func_002943b0(base + D_0035f5ac->ids[i] * 36)) break;
        }
        if (i < D_0035f5ac->count) {
            cur = i;
        } else {
            cur = 0;
            top = 0;
        }
    } else {
        for (i = cur - 1; i >= 0; i--)
            if (func_002943b0(base + D_0035f5ac->ids[i] * 36)) break;
        if (i < 0) {
            for (i = D_0035f5ac->count - 1; cur < i; i--)
                if (func_002943b0(base + D_0035f5ac->ids[i] * 36)) break;
        }
        cur = i;
        if (i < 0) {
            cur = D_0035f5ac->count - 1;
            top = D_0035f5ac->count - 11;
        }
    }
    if (cur - top >= 10) top += cur - top - 9;
    else if (cur - top < 0) top += cur - top;
    func_002765e8(15, cur - top, top);
    func_0029eaa8();
}
}  // namespace n0029cb28

// 0029cd70 (was src/anon/batch_w1591.cpp)
namespace n0029cd70 {
s32 func_00289310(s32) asm("func_00289310");
void func_0029cdf8() asm("func_0029cdf8");
void func_0029d008() asm("func_0029d008");
void func_0029eaa8() asm("func_0029eaa8");
void func_0029daa0() asm("func_0029daa0");
/*TARGET 0029cd70*/
void func_0029cd70(s32 a0, s32 a1) asm("func_0029cd70");
void func_0029cd70(s32 a0, s32 a1) {
    if (func_00289310(a0) == 0) return;
    switch (a1) {
    case 14: func_0029cdf8(); return;
    case 15: case 18: case 21: func_0029d008(); func_0029eaa8(); return;
    case 16: case 19: case 22: func_0029daa0(); return;
    }
}
}  // namespace n0029cd70

