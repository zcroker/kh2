// Linked unit 0x002a92a0-0x002a98a8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/jm_newinfo.hpp"
#include "../tozawa/jm_complete.hpp"
#include "../tozawa/jm_puzzle.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 002a92a0 (was src/anon/batch_w21.cpp)
namespace n002a92a0 {
u8* func_00294000(s32) asm("func_00294000");
u8* func_002a92a0(s32 i) asm("func_002a92a0");
u8* func_002a92a0(s32 i) {
    u8* b = func_00294000(8) + 16;
    return b + i * 16;
}
}  // namespace n002a92a0

// 002a92d8 (was src/anon/batch_w109.cpp)
namespace n002a92d8 {
// ---- f20.cpp
extern u8* D_0035f60c asm("D_0035f60c");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f210 asm("D_0035f210");
u8* func_002766d0(void) asm("func_002766d0");
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
s32 func_0023aa78(u8*) asm("func_0023aa78");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
void func_00139620(u8*) asm("func_00139620");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_00138c10(u8*, s32) asm("func_00138c10");
void Tz__JmQuest__CreateList(void) asm("Tz__JmQuest__CreateList");
void Tz__JmQuest__CreateList(void) {
    u8* g = func_002766d0();
    s32 id = D_0035f3d4;
    u8* q = g + 0xa998;
    for (s32 i = 0; i < 10; i++) {
        u8* p = D_0035f60c + i * 436;
        u8* b = p + 24;
        func_0028d980(p, id, D_0035f14c, D_0035f148, D_0035f210, 106, -1, -1, 0);
        s32 h = func_0023aa78(b);
        s32 x = func_0023aa18(b);
        s32 y = func_0023aa38(b);
        func_00139620(p);
        func_00138c68(p, 0, h * i);
        func_0028dcc0(p, g);
        *(u32*)(p + 420) = 0x60000008;
        *(s32*)(p + 428) = 3;
        func_00138c10(p, 2);
        func_0028d8c0(q, id + 1, D_0035f14c, D_0035f148, D_0035f210, 2, -1, 0);
        func_0028dcc0(q, p);
        func_00138c68(q, x, y);
        q += 408;
    }
}
}  // namespace n002a92d8

// 002a9470 (was src/anon/batch_w61.cpp)
namespace n002a9470 {
// 00108600: moved to src/anon/unit_001085a8.cpp

struct VObj { s32 (**vt)(...); };
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_00276a90(void) asm("func_00276a90");
void func_00276b90(void) asm("func_00276b90");
extern u8* D_0035f60c asm("D_0035f60c");
s32 func_002a9470(void) asm("func_002a9470");
s32 func_002a9470(void) {
    for (s32 i = 0; i < 10; i++) {
        if (func_00139d78(D_0035f60c + i * 436)) {
            VObj* o = (VObj*)(i * 436 + (u32)D_0035f60c);
            ((void (*)(VObj*))o->vt[5])(o);
        }
    }
    if (!func_00276a90()) func_00276b90();
    return 0;
}
}  // namespace n002a9470

// 002a94f8 (was src/anon/batch_w45.cpp)
namespace n002a94f8 {
typedef void (*VFn)(u8*);
s32 func_00139d78(u8*) asm("func_00139d78");
extern u8* D_0035f60c asm("D_0035f60c");
void func_00276a18(void) asm("func_00276a18");
void func_00276b10(void) asm("func_00276b10");
void func_002a94f8(void) asm("func_002a94f8");
void func_002a94f8(void) {
    u32 off = 0;
    for (s32 i = 9; i >= 0; i--) {
        if (func_00139d78(D_0035f60c + off)) {
            u8* o = (u8*)(off + (u32)D_0035f60c);
            (*(VFn*)(*(u8**)o + 20))(o);
        }
        off += 436;
    }
    func_00276a18();
    func_00276b10();
}
}  // namespace n002a94f8

// 002a9570 (was src/anon/batch_w1588.cpp)
namespace n002a9570 {
s32 func_00289310(void) asm("func_00289310");
void Tz__JmQuest__UpdateNewMark(void) asm("Tz__JmQuest__UpdateNewMark");
void func_002a95a8(void) asm("func_002a95a8");
void func_002a9570(void) asm("func_002a9570");
void func_002a9570(void) {
    if (func_00289310()) {
        Tz__JmQuest__UpdateNewMark();
        func_002a95a8();
    }
}
}  // namespace n002a9570

// 002a95a8 (was src/anon/perm_002a95a8.cpp)
namespace n002a95a8 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed int s32;
struct W1610Slot
{
  u8 pad[408];
  s32 h;
  u8 pad2[436 - 412];
};
struct W1610LE
{
  s8 a;
  s8 b;
  u16 c;
};
struct W1610Lst
{
  s32 cnt;
  W1610LE e[1];
};
struct W1610Rec
{
  u8 pad[4];
  u16 id;
};
struct W1610Base
{
  u8 pad[0xa998];
  u8 lay[10][408];
  u8 pad2[(0x110a0 - 0xa998) - 4080];
  u8 name[10][64];
};
extern s32 D_0035f200 asm("D_0035f200");
extern s32 D_0035f214 asm("D_0035f214");
extern W1610Slot *D_0035f60c asm("D_0035f60c");
extern W1610Lst *D_0035f608 asm("D_0035f608");
extern s32 D_00374c38 asm("D_00374c38");
extern s32 D_00374c3c asm("D_00374c3c");
W1610Base *func_002766d0(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
s32 func_0028b038(s32) asm("_ZN2Tz6Select12GetSelectTopEv");
void Tz__ScrollBar__SetPos(s32, s32) asm("Tz__ScrollBar__SetPos");
void func_002fde18(void *, s32, s32) asm("_Z16wtarget_002fde18jjjj");
void func_00138c10(void *, s32) asm("_ZN2dk6Sprite6setNumEi");
s32 Tz__JmWorldSel__GetId2WorldName(s32, s32) asm("Tz__JmWorldSel__GetId2WorldName");
s32 func_002954e0(s32) asm("_ZN2Tz10JmWorldSel11isWorldOpenEi");
s32 func_00192048(s32) asm("_Z16u_tail4_00192048jjjj");
s32 Tz__MenuUtil__MakeQuestionStr(s32, void *, s32) asm("Tz__MenuUtil__MakeQuestionStr");
s32 func_002a9c40(s32) asm("func_002a9c40");
W1610Rec *func_002a92a0(s32) asm("func_002a92a0");
s32 Tz__JmQuest__GetQuestStat(W1610Rec *) asm("Tz__JmQuest__GetQuestStat");
s32 func_002aacd8(s32) asm("func_002aacd8");
s32 func_002aad58(s32) asm("func_002aad58");
void func_002a95a8(void) asm("func_002a95a8");
void func_002a95a8(void)
{
  W1610Base *base = func_002766d0();
  int new_var2;
  s32 new_var;
  s32 idx = func_0028b038(D_0035f200);
  Tz__ScrollBar__SetPos(D_0035f214, idx);
  func_002fde18(base->name, 0, 640);
  s32 i;
  for (i = 0; i < 10; i++)
  {
    W1610Slot *p = &D_0035f60c[i];
    func_00138c10(p, 2);
    p->h = 0;
    func_00138c10(base->lay[i], 2);
  }

  s32 n = D_0035f608->cnt;
  if (n > 10)
  {
    n = 10;
  }
  for (i = 0; i < n; i++)
  {
    s32 a = D_0035f608->e[idx + i].a;
    W1610Slot *s = &D_0035f60c[i];
    u8 *buf = base->name[i];
    s32 h;
    if ((D_0035f608->e[idx + i].b < 0) && (D_0035f608->e[idx + i].c == 0))
    {
      func_00138c10(s, 102);
      h = (new_var = Tz__JmWorldSel__GetId2WorldName(a, 1));
      if (func_002954e0(a))
      {
        s->h = func_00192048(h);
      }
      else
      {
        s->h = Tz__MenuUtil__MakeQuestionStr(h, buf, 64);
      }
    }
    else
      if ((D_0035f608->e[idx + i].b < 0) && (D_0035f608->e[idx + i].c != 0))
    {
      func_00138c10(s, 104);
      h = D_0035f608->e[idx + i].c;
      if (func_002a9c40(h))
      {
        s->h = func_00192048(h);
      }
      else
      {
        s->h = Tz__MenuUtil__MakeQuestionStr(h, buf, 64);
      }
    }
    else
    {
      h = 106;
      W1610Rec *r = func_002a92a0(D_0035f608->e[idx + i].b);
      new_var2 = 107;
      s32 v = Tz__JmQuest__GetQuestStat(r);
      if (v == 2)
      {
        h = new_var2;
      }
      func_00138c10(s, h);
      h = r->id;
      if (v != 3)
      {
        if (s)
        {
          a = func_00192048(h);
          s->h = a;
        }
        else
        {
          a = func_00192048(h);
          s->h = a;
        }
      }
      else
      {
        s->h = Tz__MenuUtil__MakeQuestionStr(h, buf, 64);
      }
      if (func_002aacd8(D_0035f608->e[idx + i].b))
      {
        if (func_002aad58(D_0035f608->e[idx + i].b))
        {
          h = D_00374c3c;
        }
        else
        {
          h = D_00374c38;
        }
        func_00138c10(base->lay[i], h);
      }
    }
  }

}
}  // namespace n002a95a8

// 002a9888 (was src/anon/tiny_wrappers_more.cpp)
namespace n002a9888 {
u32 func_00276c50(u32, u32, u32, u32) asm("_Z13func_00276c50jjjj");
u32 func_002a9888(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002a9888jjjj");
u32 func_002a9888(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00276c50(0x000048f6u, 0x00000000u, a2, a3);
}
}  // namespace n002a9888

