// Linked unit (see linked_units.tsv).
#include "../common/types.h"
#include <stdarg.h>
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

// 002b0950 (was src/anon/batch_w1615.cpp)
namespace n002b0950 {
struct Q1615 { u8 v[16] __attribute__((aligned(16))); Q1615() {} ~Q1615() {} };
struct B1615 { u64 a, b, c, d; Q1615 q[2]; f32 f; B1615() {} };
struct P1615 { u64 a, b, c, d; };
struct G1615 {
    u8 p0[28];
    s16 y[2];
    s16 x[2];
    s16 ny;
    s16 nx;
    u8 p28[52 - 40];
    u32 p0b : 10;
    u32 moved : 1;
    u32 sel : 1;
    u32 p1b : 2;
    u32 mode : 4;
};
union GU1615 { G1615* p; s16 h; };
extern GU1615 D_0035f638 asm("D_0035f638");
void* func_00167f18(s32) asm("func_00167f18");
void func_00323af8(B1615*, void*) asm("func_00323af8");
s32 func_00288040(void) asm("func_00288040");
P1615* func_00288008(void) asm("func_00288008");
u32* Tz__JmPuzzle__GetImageInfo(s32) asm("Tz__JmPuzzle__GetImageInfo");
/*TARGET 002b0950*/
s32 func_002b0950(void) asm("func_002b0950");
s32 func_002b0950(void)
{
    B1615 b;
    s32 r = 0;
    func_00323af8(&b, func_00167f18(0));
    u32* fp = Tz__JmPuzzle__GetImageInfo(-1);
    if (func_00288040()) {
        b.a |= func_00288008()->a;
        b.b |= func_00288008()->b;
        b.c |= func_00288008()->c;
        b.d |= func_00288008()->d;
    }
    u32 f = *fp;
    s16 y = D_0035f638.p->y[D_0035f638.p->sel];
    s16 x = D_0035f638.p->x[D_0035f638.p->sel];
    if (!(f & 0x4000000) && ((b.d & 0x10) || (b.b & 0x10))) {
        if (x != 0) x = x - 1;
        else if (b.b & 0x10) x = D_0035f638.p->nx - 1;
        if (D_0035f638.p->x[D_0035f638.p->sel] != x) r = 16;
    } else if (!(f & 0x4000000) && ((b.d & 0x20) || (b.b & 0x20))) {
        if (x < D_0035f638.p->nx - 1) x = x + 1;
        else if (b.b & 0x20) x = 0;
        if (D_0035f638.p->x[D_0035f638.p->sel] != x) r |= 32;
    }
    if (!(f & 0x4000000) && ((b.d & 0x40) || (b.b & 0x40))) {
        if (y != 0) y = y - 1;
        else if (b.b & 0x40) y = D_0035f638.p->ny - 1;
        if (D_0035f638.p->y[D_0035f638.p->sel] != y) r |= 0x40;
    } else if (!(f & 0x4000000) && ((b.d & 0x80) || (b.b & 0x80))) {
        if (y < D_0035f638.p->ny - 1) y = y + 1;
        else if (b.b & 0x80) y = 0;
        if (D_0035f638.p->y[D_0035f638.p->sel] != y) r |= 0x80;
    }
    if (r) {
        D_0035f638.p->y[D_0035f638.p->sel] = y;
        D_0035f638.p->x[D_0035f638.p->sel] = x;
        D_0035f638.p->moved = 1;
        return r;
    }
    if (!(f & 0x4000000) && (b.b & 4)) r = 4;
    else if (b.b & 8) r = 8;
    else if (b.b & 0x100) r = 0x100;
    else if (b.b & 0x2000) r = 0x2000;
    else if ((b.b & 0x10000) && D_0035f638.p->mode >= 2) r = 0x10000;
    else if ((b.b & 0x20000) && D_0035f638.p->mode >= 2) r = 0x20000;
    else if (!(f & 0x4000000) && (b.b & 0x40000) && (f & 0x10000000)) r = 0x40000;
    else if (!(f & 0x4000000) && (b.b & 0x80000) && (f & 0x10000000)) r = 0x80000;
    return r;
}
}  // namespace n002b0950

// 002b0de0 (was src/anon/perm_002b0de0.cpp)
namespace n002b0de0 {
typedef unsigned int u32;
typedef signed int s32;
s32 Tz__JmPuzzle__GameSelCheck(void) asm("Tz__JmPuzzle__GameSelCheck");
s32 PlaySE_2b0(s32, s32) asm("_ZN2Tz9MenuSound6PlaySEEib");
/*TARGET 002b0de0*/
s32 func_002b0de0(u32 a) asm("func_002b0de0");
s32 func_002b0de0(u32 a)
{
  u32 *new_var;
  s32 r;
  u32 m = a & 0xc00f0;
  int new_var2;
  if (m)
  {
    r = 1;
  }
  else
    if ((new_var2 = a) & 8)
  {
    r = 3;
  }
  else
    if (((unsigned char) a) & 4)
  {
    r = 2;
  }
  else
  {
    new_var = &a;
    if ((*new_var) & 0x100)
    {
      r = 5;
    }
    else
    {
      new_var2 = a;
      if (new_var2 & 0x32000)
      {
        r = 2;
      }
      else
      {
        r = 0;
      }
    }
  }
  if (!Tz__JmPuzzle__GameSelCheck())
  {
    r = 4;
  }
  if (r)
  {
    r = PlaySE_2b0(r, 1);
  }
  return r;
}
}  // namespace n002b0de0

// 002b0e78 (was src/anon/batch_w3773.cpp)
namespace n002b0e78 {
struct G2b0 { u8 p0[28]; s16 a[2]; s16 b[2]; u8 p36[8]; u32 bits[2]; u32 :10; u32 b10:1; u32 b11:1; u32 f12:2; };
struct Q2b0 { u8 p[9]; s8 c; };
u8* func_002a9d68(void) asm("func_002a9d68");
u8* Tz__JmPuzzle__GetImageInfo(s32) asm("Tz__JmPuzzle__GetImageInfo");
u32 func_002b2380(s32, s32) asm("func_002b2380");
void Tz__JmPuzzle__UpdatePiece(s32) asm("Tz__JmPuzzle__UpdatePiece");
void func_002b3050(s32) asm("func_002b3050");
extern G2b0* D_0035f638 asm("D_0035f638");
/*TARGET 002b0e78*/
void Tz__JmPuzzle__PieceRot(u32 a0) asm("Tz__JmPuzzle__PieceRot");
void Tz__JmPuzzle__PieceRot(u32 a0)
{
    u8* s3 = func_002a9d68();
    u8* s2 = Tz__JmPuzzle__GetImageInfo(-1);
    u32 v = func_002b2380(D_0035f638->a[D_0035f638->b11], D_0035f638->b[D_0035f638->b11]);
    G2b0* g = D_0035f638;
    if (!g->b11) {
        Q2b0* q = (Q2b0*)(((s2[2] * 48 + v) * 4 + (u32)s3) + 480);
        s32 y = q->c;
        s32 z = (a0 & 0x40000) ? y + 5 : y + 3;
        q->c = z % 4;
        u32* bp = D_0035f638->bits;
        u32* p = bp + (v >> 5);
        *p |= 1 << (v & 31);
        Tz__JmPuzzle__UpdatePiece(0);
    } else {
        s32 x = g->f12;
        x = (a0 & 0x40000) ? x + 5 : x + 3;
        g->f12 = x;
        func_002b3050(1);
    }
}
}  // namespace n002b0e78

// 002b0fc8 (was src/anon/batch_w322.cpp)
namespace n002b0fc8 {
struct W322Ent { s8 c0; s8 c1; s8 c2; s8 c3; };
struct W322Sav { u8 pad[488]; W322Ent e[1][48]; };
struct W322G { u8 pad[28]; s16 h28; s16 h30; s16 h32; s16 h34; u8 pad2[44-36]; u32 bits[2];
    u32 :11; u32 b11:1; u32 b12:2; };
struct W322S3 { u8 b0; u8 b1; u8 b2; };
union W322GU { W322G* p; u8 c; };
extern W322GU D_0035f638 asm("D_0035f638");
W322Sav* func_002a9d68(void) asm("func_002a9d68");
W322S3* Tz__JmPuzzle__GetImageInfo(s32) asm("Tz__JmPuzzle__GetImageInfo");
// list_entry_by_index_checked
u32 func_002b2380(s32, s32) asm("func_002b2380");
void func_002b2da8(s32) asm("func_002b2da8");
void func_002b3050(s32) asm("func_002b3050");
void Tz__JmPuzzle__UpdatePiece(s32) asm("Tz__JmPuzzle__UpdatePiece");
void func_002b2f28(s32) asm("func_002b2f28");
// 0x00281fe0: definition moved into src/anon/unit_00281cf0.cpp
static inline void w322_setbit(u32* p, u32 n) { p += n >> 5; *p |= 1 << (n & 31); }
/*TARGET 002b0fc8*/
void func_002b0fc8(u32 fl) asm("func_002b0fc8");
void func_002b0fc8(u32 fl) {
    W322Sav* sv = func_002a9d68();
    W322S3* s3 = Tz__JmPuzzle__GetImageInfo(-1);  // list_entry_by_index_checked
    u32 a = func_002b2380(D_0035f638.p->h28, D_0035f638.p->h32);
    if (!D_0035f638.p->b11) {
        D_0035f638.p->h30 = D_0035f638.p->h28;
        D_0035f638.p->h34 = D_0035f638.p->h32;
        D_0035f638.p->b12 = sv->e[s3->b2][a].c1;
        func_002b2da8(1);
    } else {
        if (fl & 4) {
            u32 b = func_002b2380(D_0035f638.p->h30, D_0035f638.p->h34);
            sv->e[s3->b2][a].c1 = D_0035f638.p->b12;
            W322Ent t = sv->e[s3->b2][b];
            sv->e[s3->b2][b] = sv->e[s3->b2][a];
            sv->e[s3->b2][a] = t;
            D_0035f638.p->h28 = D_0035f638.p->h30;
            D_0035f638.p->h32 = D_0035f638.p->h34;
            w322_setbit(D_0035f638.p->bits, a);
            w322_setbit(D_0035f638.p->bits, b);
            Tz__JmPuzzle__UpdatePiece(0);
        }
        func_002b2f28(1);
    }
    D_0035f638.p->b11 ^= 1;
    func_002b3050(1);
}
}  // namespace n002b0fc8

// 002b1208 (was src/anon/batch_w65.cpp)
namespace n002b1208 {
// 00292870: moved to src/anon/unit_00292620.cpp

// Step the selection up/down (wrapping) among the entries flagged 0x2000000.
struct Ent36 { u32 f; u32 r[8]; };
extern u32* D_0035f630 asm("D_0035f630");
s32 func_00276608(s32) asm("func_00276608");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
/*TARGET 002b1208*/
void Tz__JmPuzzle__ChangeImage(u32 a) asm("Tz__JmPuzzle__ChangeImage");
void Tz__JmPuzzle__ChangeImage(u32 a) {
    s32 n = 0;
    Ent36* e = (Ent36*)D_0035f630;
    s32 i;
    for (i = 0; i < 10; i++, e++) {
        if (e->f & 0x2000000) n++;
    }
    s32 v = func_00276608(28);
    v = (a & 0x10000) ? v + 1 : v - 1;
    if (v < 0) v = n - 1;
    else if (v >= n) v = 0;
    func_002765e8(28, v, 0);
}
}  // namespace n002b1208

// 002b12a0 (was src/anon/batch_w119.cpp)
namespace n002b12a0 {
extern u32 D_0035f634 asm("D_0035f634");
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f210 asm("D_0035f210");
extern u8* D_0035f638 asm("D_0035f638");
extern u8 D_00374ce8[] asm("D_00374ce8");
u16* Tz__JmPuzzle__GetImageInfo(s32) asm("Tz__JmPuzzle__GetImageInfo");
// list_entry_by_index_checked
u8* func_001a80c8(u32) asm("func_001a80c8");
// table24_find_by_id
void func_00281cf0(u32) asm("func_00281cf0");
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028d980(u8*, s32, u32, u32, u32, s32, s32, s32, s32) asm("func_0028d980");
void func_00139620(u8*) asm("func_00139620");
void func_001395f8(u8*) asm("func_001395f8");
void func_00139688(u8*) asm("func_00139688");
u32 func_00192048(u32) asm("func_00192048");
u32 func_001a37e8(u32, s32) asm("func_001a37e8");
void func_00192c90(u32, u8*) asm("func_00192c90");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_002817d8(s32, u32, u32, u32, s32, s32, u8*) asm("func_002817d8");
// store_globals_quad
void func_00281e70(u8*) asm("func_00281e70");
// store_global_and_clear_flag
void func_00281e20(void) asm("func_00281e20");
void func_00242618(s32, s32) asm("func_00242618");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 002b12a0*/
// Sets up a menu screen: title/background layouts, the selected entry's name and icon.
void func_002b12a0(void) asm("func_002b12a0");
// Sets up a menu screen: title/background layouts, the selected entry's name and icon.
void func_002b12a0(void)
{
    u16 id = *Tz__JmPuzzle__GetImageInfo(-1);  // list_entry_by_index_checked
    u8* info = func_001a80c8(id);  // table24_find_by_id
    func_00281cf0(*(u16*)(info + 20));
    func_0028d8c0((u8*)D_0035f634 + 21624, 30061, D_0035f14c, D_0035f148, D_0035f210, 125, 126, 0);
    u8* o = (u8*)D_0035f634 + 23776;
    func_0028d980(o, 30061, D_0035f14c, D_0035f148, D_0035f210, 122, 123, -1, 0);
    func_00139620(o);
    *(u32*)(o + 432) = 2;
    *(u32*)(o + 408) = func_00192048(20689);
    o = (u8*)D_0035f634 + 22904;
    u8* sub = o + 24;
    func_0028d980(o, 30061, D_0035f14c, D_0035f148, D_0035f210, 128, 129, -1, 0);
    *(u32*)(o + 432) = 2;
    func_00139620(o);
    func_001395f8(o);
    func_00192c90(func_001a37e8(id, -1), D_0035f638 + 56);
    *(u8**)(o + 408) = D_0035f638 + 56;
    s32 x = func_0023aa18(sub);
    s32 y = func_0023aa38(sub);
    o = (u8*)D_0035f634 + 23340;
    func_0028d980(o, 30061, D_0035f14c, D_0035f148, D_0035f210, 3, -1, -1, 0);
    func_0028dcc0(o, (u8*)D_0035f634 + 22904);
    *(u32*)(o + 432) = 2;
    func_00139620(o);
    func_00138c68(o, x, y);
    func_00139688(o);
    *(u32*)(o + 408) = func_00192048(*(u16*)(info + 10));
    func_002817d8(30062, D_0035f14c, D_0035f148, D_0035f210, 0, 0, D_00374ce8);  // store_globals_quad
    func_00281e70((u8*)D_0035f634 + 21624);  // store_global_and_clear_flag
    func_00281e20();
    func_00242618(19, 1);
    func_00287cc0(0);
}
}  // namespace n002b12a0

// 002b14f0 (was src/anon/batch_wcx2.cpp)
namespace n002b14f0 {
// 0x002a41f0: definition moved into src/anon/unit_002a40c8.cpp

struct Pad53 { u8 pad[8]; u64 trg; };
extern u8* D_0035f634__83558 asm("D_0035f634");
Pad53* func_00167f18(s32) asm("func_00167f18");
s32 func_00287cd0(void) asm("func_00287cd0");
void func_00281d48(void) asm("func_00281d48");
s32 func_002b1660(void) asm("func_002b1660");
u16* Tz__JmPuzzle__GetImageInfo(s32) asm("Tz__JmPuzzle__GetImageInfo");
// list_entry_by_index_checked
void YS__ITEM__Get(u16, s32, s32) asm("YS__ITEM__Get");
u32 func_002b1aa0(void) asm("func_002b1aa0");
u32 func_00192048__83558(u32) asm("func_00192048");
void func_002b1af0(void) asm("func_002b1af0");
void func_00139580(u8*) asm("func_00139580");
void func_002817b8(void) asm("func_002817b8");
void func_00287c30(void) asm("func_00287c30");
void func_00287cc0(s32) asm("func_00287cc0");
void Tz__JmPuzzle__UpdateHelpMess(void) asm("Tz__JmPuzzle__UpdateHelpMess");
void func_00281e20(void) asm("func_00281e20");
s32 func_002b16d8(void) asm("func_002b16d8");
void func_00287c90(s32) asm("func_00287c90");
void func_00242618(s32, s32) asm("func_00242618");
void func_0028dac8(u8*, s32) asm("func_0028dac8");
void func_00281b30__83558(void) asm("func_00281b30");
void func_00287c00(s32) asm("func_00287c00");
/*TARGET 002b14f0*/
void func_002b14f0(void) asm("func_002b14f0");
void func_002b14f0(void)
{
    Pad53* pad = func_00167f18(0);
    s32 st = func_00287cd0();
    func_00281d48();
    if (st == 2) {
        if (func_002b1660()) return;
        YS__ITEM__Get(*Tz__JmPuzzle__GetImageInfo(-1), 100, 0);
        u8* o = D_0035f634__83558 + 22468;
        *(u32*)(o + 408) = func_00192048__83558(func_002b1aa0());
        func_002b1af0();
        func_00139580(D_0035f634__83558 + 24212);
        func_002817b8();
        func_00287c30();
        func_00287cc0(1);
        Tz__JmPuzzle__UpdateHelpMess();
        return;
    }
    func_00281e20();
    if (!st && func_002b16d8()) func_00287c90(1);
    if (st != 1) return;
    if (!(pad->trg & 4)) return;
    func_00242618(2, 1);
    func_0028dac8(D_0035f634__83558 + 23776, 124);
    func_0028dac8(D_0035f634__83558 + 21624, 127);
    func_0028dac8(D_0035f634__83558 + 22904, 130);
    func_00281b30__83558();
    func_00287c00(29);
    func_00287cc0(2);
}
}  // namespace n002b14f0

// 002b1660 (was src/anon/batch_w36.cpp)
namespace n002b1660 {
s32 func_00139d78(u32) asm("func_00139d78");
extern u8* D_0035f634 asm("D_0035f634");
u8 func_00281be0(void) asm("func_00281be0");
// 0x002abdc8: definition moved into src/anon/unit_002a99c8.cpp

// The empty-destructor local keeps the final call from becoming a tail call.
struct NoTail { ~NoTail() {} };
/*TARGET 002b1660*/
void func_002b1660(void) asm("func_002b1660");
void func_002b1660(void) {
    NoTail g;
    if (func_00139d78((u32)(D_0035f634 + 21624))) return;
    if (func_00139d78((u32)(D_0035f634 + 22904))) return;
    if (func_00139d78((u32)(D_0035f634 + 23340))) return;
    if (func_00139d78((u32)(D_0035f634 + 23776))) return;
    func_00281be0();
}
}  // namespace n002b1660

// 002b16d8 (was src/anon/batch_w6.cpp)
namespace n002b16d8 {
// 0x002a65a0: definition moved into src/anon/unit_002a5a90.cpp

struct S16d8 { u8 pad[22012]; s32 a; u8 pad2[23292 - 22016]; s32 b; };
extern S16d8* D_0035f634 asm("D_0035f634");
/*TARGET 002b16d8*/
u32 func_002b16d8(void) asm("func_002b16d8");
u32 func_002b16d8(void) {
    S16d8* p = D_0035f634;
    s32 a = p->a;
    s32 b = p->b;
    u32 r = 0;
    if (a == 126) r = (b == 0x81);
    return r;
}
}  // namespace n002b16d8

// 002b1708 (was src/anon/batch_w98.cpp)
namespace n002b1708 {
extern u8* D_0035f200 asm("D_0035f200");
u8* func_002891b8(u8*, s32) asm("func_002891b8");
void func_00138c10(u8*, s32) asm("func_00138c10");
// 0x00276c88: definition moved into src/anon/unit_002748a0.cpp

extern u16 D_00374cb0[][2] asm("D_00374cb0");
extern u32 D_00374c9c asm("D_00374c9c");
extern u32 D_00374ca0 asm("D_00374ca0");
u8* func_002766d0(void) asm("func_002766d0");
s32 func_002892f8(u8*) asm("func_002892f8");
u32 func_00192048(u16) asm("func_00192048");
s32 Tz__JmNewInfo__isPuzzlePieceNew(s32) asm("Tz__JmNewInfo__isPuzzlePieceNew");
s32 Tz__JmNewInfo__isPuzzleInfoNew(s32) asm("Tz__JmNewInfo__isPuzzleInfoNew");
s32 func_002ac538(s32) asm("func_002ac538");
s32 func_002ac800(s32) asm("func_002ac800");
/*TARGET 002b1708*/
// Resets the item rows, then refreshes the three category rows and their availability marks.
void Tz__JmPuzzle__UpdateTopList(void) asm("Tz__JmPuzzle__UpdateTopList");
// Resets the item rows, then refreshes the three category rows and their availability marks.
void Tz__JmPuzzle__UpdateTopList(void) {
    u8* base = func_002766d0();
    s32 n = func_002892f8(D_0035f200);
    s32 i;
    for (i = 0; i < n; i++) func_00138c10(base + 0xa998 + i * 408, 2);
    u8* w = base + 0xa998;
    for (i = 0; i < 3; w += 408, i++) {
        u8* it = func_002891b8(D_0035f200, i);
        *(u32*)(it + 408) = func_00192048(D_00374cb0[i][0]);
        if (i == 2) continue;
        s32 a, b;
        if (i == 0) a = Tz__JmNewInfo__isPuzzlePieceNew(-1);
        else a = Tz__JmNewInfo__isPuzzleInfoNew(-1);
        if (i == 0) b = func_002ac538(-1);
        else b = func_002ac800(-1);
        if (a) func_00138c10(w, b == 0 ? D_00374c9c : D_00374ca0);
    }
}
}  // namespace n002b1708

// 002b1850 (was src/anon/match_002b1850_mam.cpp)
namespace n002b1850 {
struct Item2b1 { u8 pad[408]; };
struct Obj2b1 { u8 pad[0xa998]; Item2b1 items[1]; };
struct Ent2b1 { u32 flags; u8 rest[32]; };
struct Res2b1 { u8 pad[408]; void* p; };
Obj2b1* func_002766d0() asm("func_002766d0");
s32 func_002892f8(s32) asm("func_002892f8");
s32 func_0028afa8(s32) asm("func_0028afa8");
Res2b1* func_002891b8(s32, s32) asm("func_002891b8");
void func_00138c10(Item2b1*, s32) asm("func_00138c10");
s32 Tz__JmNewInfo__isPuzzlePieceNew(u8) asm("Tz__JmNewInfo__isPuzzlePieceNew");
s32 func_002ac538(u8) asm("func_002ac538");
extern s32 D_0035f200 asm("D_0035f200");
extern Ent2b1* D_0035f630 asm("D_0035f630");
extern s32 D_00374c9c asm("D_00374c9c");
extern s32 D_00374ca0 asm("D_00374ca0");
/*TARGET 002b1850*/
void func_002b1850(void) asm("func_002b1850");
void func_002b1850(void) {
    Obj2b1* base = func_002766d0();
    s32 n = func_002892f8(D_0035f200);
    s32 i;
    for (i = 0; i < n; i++) func_00138c10(&base->items[i], 2);
    s32 j = 0;
    n = func_0028afa8(D_0035f200);
    for (i = 0; i < n; i++) {
        s32 found = -1;
        for (; j < 10; j++) {
            if (D_0035f630[j].flags & 0x1000000) {
                found = j;
                func_002891b8(D_0035f200, i)->p = &D_0035f630[j].rest;
                j++;
                break;
            }
        }
        if (found < 0) break;
        if ((D_0035f630[found].flags & 0x3000000) == 0x3000000 && Tz__JmNewInfo__isPuzzlePieceNew(((u8*)&D_0035f630[found])[2])) {
            s32 a;
            if (func_002ac538(((u8*)&D_0035f630[found])[2])) a = D_00374ca0;
            else a = D_00374c9c;
            func_00138c10(&base->items[i], a);
        }
    }
}
}  // namespace n002b1850

// 002b1a00 (was src/anon/batch_w68.cpp)
namespace n002b1a00 {
s32 func_00287bc0(void) asm("func_00287bc0");
// 0x002ad1b0: definition moved into src/anon/unit_002a99c8.cpp

/* ---- 002b1a00 ---- */
struct E19 { u16 a; s16 b; };
extern E19 D_00374c68[] asm("D_00374c68");
u32* Tz__JmPuzzle__GetImageInfo(s32) asm("Tz__JmPuzzle__GetImageInfo");
// list_entry_by_index_checked
void func_00276c50(s32, u32) asm("func_00276c50");
/*TARGET 002b1a00*/
void Tz__JmPuzzle__UpdateHelpMess(void) asm("Tz__JmPuzzle__UpdateHelpMess");
void Tz__JmPuzzle__UpdateHelpMess(void) {
    s32 r = -1;
    s32 cur = func_00287bc0();
    s32 i;
    for (i = 0; D_00374c68[i].a != 0; i++) {
        if (cur == D_00374c68[i].b) { r = D_00374c68[i].a; break; }
    }
    if (r == 20297) {
        if (*Tz__JmPuzzle__GetImageInfo(-1) & 0x4000000) r = 20696;
    }
    func_00276c50(r, 0);
}
}  // namespace n002b1a00

// 002b1aa0 (was src/anon/batch_w31.cpp)
namespace n002b1aa0 {
u32* Tz__JmPuzzle__GetImageInfo(int) asm("Tz__JmPuzzle__GetImageInfo");
// list_entry_by_index_checked
extern u32 D_00374ca4 asm("D_00374ca4");
extern u32 D_00374ca8 asm("D_00374ca8");
/*TARGET 002b1aa0*/
// 0x00295228: definition moved into src/anon/unit_00292e60.cpp

u32 func_002b1aa0(void) asm("func_002b1aa0");
// 0x00295228: definition moved into src/anon/unit_00292e60.cpp

u32 func_002b1aa0(void) {
    u32 f = *Tz__JmPuzzle__GetImageInfo(-1);  // list_entry_by_index_checked
    if (f & 0x04000000) return 20690;
    if (f & 0x10000000) return D_00374ca4;
    return D_00374ca8;
}
}  // namespace n002b1aa0

// 002b1af0 (was src/anon/batch_w77.cpp)
namespace n002b1af0 {
extern u8* D_0035f634 asm("D_0035f634");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f210 asm("D_0035f210");
extern u8* D_0035f638 asm("D_0035f638");
u32 func_002766d0(void) asm("func_002766d0");
void func_0028d980(u8*, s32, u32, u32, u32, s32, s32, s32, s32) asm("func_0028d980");
void func_00139620(u8*) asm("func_00139620");
void func_0028dcc0(u8*, u32) asm("func_0028dcc0");
u32 func_00192048(s32) asm("func_00192048");
u16* Tz__JmPuzzle__GetImageInfo(s32) asm("Tz__JmPuzzle__GetImageInfo");
// list_entry_by_index_checked
u32 func_001a37e8(u16, s32) asm("func_001a37e8");
void func_00192e50(u32, u8*, s32, u32) asm("func_00192e50");
/*TARGET 002b1af0*/
void func_002b1af0(void) asm("func_002b1af0");
void func_002b1af0(void)
{
    u32 r = func_002766d0();
    s32 k = D_0035f3d4 + 2;
    u8* o = D_0035f634 + 24212;
    func_0028d980(o, k, D_0035f14c, D_0035f148, D_0035f210, 131, -1, -1, 0);
    func_00139620(o);
    func_0028dcc0(o, r);
    *(u32*)(o + 432) = 2;
    u32 x = func_00192048(20688);
    func_00192e50(x, D_0035f638 + 88, 64, func_001a37e8(*Tz__JmPuzzle__GetImageInfo(-1), -1));
    *(u8**)(o + 408) = D_0035f638 + 88;
}
}  // namespace n002b1af0

// 002b1bd0 (was src/anon/batch_w3794_nsamam.cpp)
namespace n002b1bd0 {
struct PzEnt { u8 pad[8]; s8 a; s8 b; };
struct PzWork { u8 pad[0x1e0]; PzEnt ent[1]; };
struct PzObj { u8 pad[0x18]; u8 m[0x16c]; s32 f184; u8 pad2[0x10]; };
struct PzBits { u8 pad[0x2c]; u32 mask[1]; };
struct PzUV { s16 u[4]; s16 v[4]; };
static inline int PzBit(u32* m, u32 n) { return m[n >> 5] & (1 << (n & 31)); }
extern s16 D_00374cc8[] asm("D_00374cc8");
extern s8 D_00374cd0[] asm("D_00374cd0");
extern PzObj* D_0035f634 asm("D_0035f634");
extern PzBits* D_0035f638 asm("D_0035f638");
u8* Tz__JmPuzzle__GetImageInfo(s32) asm("Tz__JmPuzzle__GetImageInfo");
PzWork* func_002a9d68(void) asm("func_002a9d68");
void func_00138c10(void*, s32) asm("func_00138c10");
void func_002b28b0(u32, s32, s32, PzUV*) asm("func_002b28b0");
void YI__SPRITE__SetDirextUV(void*, s16*, s16*) asm("YI__SPRITE__SetDirextUV");
/*TARGET 002b1bd0*/
// Puzzle board refresh: for every piece set in the dirty mask (or all when
// flag), resize its sprite and set its UVs from the piece table.
void Tz__JmPuzzle__UpdatePiece(u8 flag) asm("Tz__JmPuzzle__UpdatePiece");
// Puzzle board refresh: for every piece set in the dirty mask (or all when
// flag), resize its sprite and set its UVs from the piece table.
void Tz__JmPuzzle__UpdatePiece(u8 flag)
{
    s32 row = 0;
    s32 rows;
    s32 cols;
    u8* info = Tz__JmPuzzle__GetImageInfo(-1);
    PzWork* work = func_002a9d68();
    u32 kind = (*(u32*)info >> 27) & 1;
    s8* g = &D_00374cd0[kind * 4];
    cols = D_00374cd0[kind * 4];
    rows = g[1];
    s16 size = D_00374cc8[kind];
    for (row = 0; row < rows; row++) {
        for (s32 col = 0; col < cols; col++) {
            u32 idx = row * cols + col;
            if (PzBit(D_0035f638->mask, idx) || flag) {
                PzObj* o = &D_0035f634[idx];
                PzEnt* e = (PzEnt*)(((info[2] * 48 + idx) * 4 + (u32)work) + 480);
                s32 a = e->a;
                s32 b = e->b;
                if (a < 0) {
                    func_00138c10(o, 0);
                } else {
                    if (o->f184 != size) func_00138c10(o, size);
                    PzUV uv;
                    func_002b28b0((*(u32*)info >> 27) & 1, a, b, &uv);
                    YI__SPRITE__SetDirextUV(o->m, uv.u, uv.v);
                }
            }
        }
    }
    PzBits* pz = D_0035f638;
    pz->mask[0] = 0;
    pz->mask[1] = 0;
}
}  // namespace n002b1bd0

