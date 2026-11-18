// Linked unit 0x0029d008-0x0029f220 (one namespace per old matched source; class methods in their own namespace).
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

// 0029d008 (was src/anon/perm_0029d008.cpp)
namespace n0029d008 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
struct E29d
{
  u8 pad[4];
  u16 h4;
  u16 msg;
  u8 pad8[8];
  u16 flags;
  u8 pad12[0x12];
};
struct G29d
{
  u8 pad[4];
  s8 b4;
  s8 cnt;
  u16 pad6;
  s16 ids[(0x108 - 8) / 2];
  char names[10][64];
};
struct I29d
{
  u8 pad[0x198];
  void *name;
};
extern G29d *D_0035f5ac asm("D_0035f5ac");
extern s32 D_0035f200 asm("D_0035f200");
extern s32 D_0035f214 asm("D_0035f214");
extern s32 D_00374ad0 asm("D_00374ad0");
extern s32 D_00374ad4 asm("D_00374ad4");
u8 *func_002766d0(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
u8 *func_00294000(s32) asm("_ZN2Tz6JmInfo7GetDataEi");
void func_00138c10(void *, s32) asm("_ZN2dk6Sprite6setNumEi");
s32 func_0028b038(s32) asm("_ZN2Tz6Select12GetSelectTopEv");
void func_0028be78(s32, s32) asm("func_0028be78");
I29d *func_002891b8(s32, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
void *func_00192048(u32) asm("_Z16u_tail4_00192048jjjj");
s32 func_0028afa8(s32) asm("_ZN2Tz6Select12GetSelectMaxEv");
s32 func_002943b0(E29d *) asm("func_002943b0");
u32 func_00295430(s32, s32) asm("func_00295430");
void *func_00192e50(void *, char *, s32, void *) asm("func_00192e50");
void func_002595e8(char *, void *) asm("_ZN2Tz6CmComm11CopyMessageEPcPKN2YS7MESSAGEE");
void *func_00192a80(void *) asm("func_00192a80");
void func_0028def0(char *, void *) asm("func_0028def0");
s32 func_002a9e98(u32) asm("func_002a9e98");
s32 func_002a9f50(u32) asm("func_002a9f50");
/*TARGET 0029d008*/
void func_0029d008(void) asm("func_0029d008");
void func_0029d008(void)
{
  char buf[64];
  s32 i;
  s32 k;
  s32 n;
  s32 top;
  s32 t;
  u8 *base = func_002766d0();
  u32 tbl = (u32) (func_00294000(3) + 0x10);
  for (i = 0; i < 10; i++)
  {
    func_00138c10((base + 0xa998) + (i * 0x198), 2);
  }

  top = func_0028b038(D_0035f200);
  func_0028be78(D_0035f214, top);
  if (D_0035f5ac->cnt == 0)
  {
    func_002891b8(D_0035f200, 0)->name = func_00192048(0x36b3);
  }
  k = 0;
  n = func_0028afa8(D_0035f200);
  if (n >= 11)
  {
    n = 10;
  }
  for (i = 0; (i < D_0035f5ac->cnt) && (k < n); i++)
  {
    if (i < top)
    {
      continue;
    }
    s32 idx = D_0035f5ac->ids[i];
    E29d *e = (E29d *) ((idx * 0x24) + tbl);
    t = e->msg;
    s32 r = func_002943b0(e);
    if (r)
    {
      if (e->flags & 0x400)
      {
        void *m = func_00192048(t);
        t = k << 6;
        func_00192e50(m, (((char *) D_0035f5ac) + t) + 0x108, 64, func_00192048(func_00295430(D_0035f5ac->b4, 1)));
      }
      else
      {
        void *m = func_00192048(t);
        t = k << 6;
        func_002595e8((((char *) D_0035f5ac) + t) + 0x108, m);
      }
    }
    else
    {
      void *m;
      if (e->flags & 0x400)
      {
        void *mm = func_00192048(t);
        m = func_00192e50(mm, buf, 64, func_00192048(func_00295430(D_0035f5ac->b4, 1)));
      }
      else
      {
        m = func_00192048(t);
      }
      t = k << 6;
      D_0035f5ac = D_0035f5ac;
      func_0028def0((((char *) D_0035f5ac) + t) + 0x108, func_00192a80(m));
    }
    func_002891b8(D_0035f200, k)->name = (((char *) D_0035f5ac) + t) + 0x108;
    if (r)
    {
      E29d *e2 = (E29d *) ((idx * 0x24) + tbl);
      if (func_002a9e98(e2->h4))
      {
        if (func_002a9f50(e2->h4))
        {
          t = D_00374ad4;
        }
        else
        {
          t = D_00374ad0;
        }
        func_00138c10((base + (k * 0x198)) + 0xa998, t);
      }
    }
    k++;
  }

}
}  // namespace n0029d008

// 0029d318 (was src/anon/batch_w3704_nsa.cpp)
namespace n0029d318 {
// u8 member: these u16 accesses may alias any store (the original was built without strict aliasing)
union W1650H { u16 v; u8 c; };
// 0x1b4-byte layout sprite (init by func_0028d980)
struct W1650Spr { u8 pad0[0x18]; u8 sub[0x180]; s32 x198; u8 pad19c[8]; u32 x1a4; s32 x1a8; s32 x1ac; s32 x1b0; };
// 0x198-byte layout element (init by func_0028d8c0)
struct W1650Lay { u8 pad0[0x198]; };
struct W1650Panel {
    W1650Spr a[4];      // 0x0000
    W1650Spr item[5];   // 0x06d0
    W1650Spr cnt[5];  // 0x0f54
    W1650Lay d[2];      // 0x17d8
    W1650H x1b08;
    char num[8];        // 0x1b0a
    char nums[5][8];    // 0x1b12
    s8 x1b3a;
    s8 x1b3b;
};
struct W1650Work { u8 pad0[0x18]; u8 sub[0x318]; W1650Lay x330; u8 pad4c8[0x110a0 - 0x4c8]; char names[10][64]; };
struct W1650List { u8 pad0[4]; s8 x4; s8 count; u8 pad6[2]; s16 ids[0x80]; char name[64]; };
struct W1650Ent { u8 pad0[2]; s8 x2; u8 pad3[3]; u16 x6; u16 x8; W1650H xa; u16 xc; u8 pade[2]; W1650H flags; };
struct W1650Item { u8 pad0[8]; s32 x8; };
struct W1650Tbl { u16 x0; u16 ids[5]; };
struct W1650Def { u8 pad0[0x4c]; u16 x4c; };
void* func_002766d0(void) asm("func_002766d0");
s32 func_00276638(s32) asm("func_00276638");
W1650Ent* func_0029da68(s32) asm("func_0029da68");
void* func_00276348(void) asm("func_00276348");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_00139620(void*) asm("func_00139620");
void func_001395f8(void*) asm("func_001395f8");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
s32 func_00192048(s32) asm("func_00192048");
s32 func_00295430(s32, s32) asm("func_00295430");
void func_00192e50(s32, char*, s32, s32) asm("func_00192e50");
void func_002595e8(char*, s32) asm("func_002595e8");
s32 func_0023aa18(void*) asm("func_0023aa18");
s32 func_0023aa38(void*) asm("func_0023aa38");
s32 func_0023aa58(void*) asm("func_0023aa58");
s32 func_0023aa78(void*) asm("func_0023aa78");
s32 func_00276c38(s32) asm("func_00276c38");
s32 func_00192cc0(char*, char*, s32) asm("func_00192cc0");
s32 func_00294368(W1650Ent*) asm("func_00294368");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
s32 func_00192b80(s32) asm("func_00192b80");
void func_0028af90(void*, s32) asm("func_0028af90");
void func_002891f0(void*, s32, s32, s32, s32) asm("func_002891f0");
void func_0028afd0(void*, s32) asm("func_0028afd0");
void func_0028b218(void*, s32) asm("func_0028b218");
void func_0028b248(void*, s32) asm("func_0028b248");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
W1650Def* func_0016e920(s32) asm("func_0016e920");
W1650Tbl* func_001d23e0(s32) asm("func_001d23e0");
W1650Item* func_001b8e88(s32) asm("func_001b8e88");
s32 func_001b90a8(W1650Item*) asm("func_001b90a8");
s32 func_00276c18(void) asm("func_00276c18");
s32 func_0028de08(s32, char*, s32) asm("func_0028de08");
extern W1650List* D_0035f5ac asm("D_0035f5ac");
union W1650PanelPtr { W1650Panel* p; u8 c; };
extern W1650PanelPtr D_0035f5b0 asm("D_0035f5b0");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f210 asm("D_0035f210");
extern void* D_0035f200 asm("D_0035f200");
extern s16 D_00374ae0[] asm("D_00374ae0");
extern char D_003749e8[] asm("D_003749e8");
/*TARGET 0029d318*/
void func_0029d318(void) asm("func_0029d318");
void func_0029d318(void)
{
    s32 a;
    s32 b;
    s32 d;
    s32 mode;
    void* o;
    W1650Work* w;
    W1650Ent* e;
    s32 base;
    W1650Spr* s;
    s32 v;
    s32 k;

    w = (W1650Work*)func_002766d0();
    {
        s32 idx = func_00276638(15);
        e = func_0029da68(D_0035f5ac->ids[idx]);
    }
    base = D_0035f3d4;
    o = func_00276348();
    mode = func_00287bc0();
    s = &D_0035f5b0.p->a[0];
    v = e->x6;

    func_0028d980(s, base, D_0035f14c, D_0035f148, D_0035f210, 76, -1, -1, 0);
    func_00139620(s);
    func_0028dcc0(s, o);
    s->x1ac = 3;
    s->x1a4 = 0x60000008;
    if (e->flags.v & 0x400) {
        s32 t = func_00192048(v);
        func_00192e50(t, D_0035f5ac->name, 64, func_00192048(func_00295430(D_0035f5ac->x4, 1)));
    } else {
        func_002595e8(D_0035f5ac->name, func_00192048(v));
    }
    s->x198 = (s32)D_0035f5ac->name;

    k = e->xa.v;
    if (k != 0) {
        s = &D_0035f5b0.p->a[1];
        func_0028d980(s, base, D_0035f14c, D_0035f148, D_0035f210, 77, -1, k, 0);
        func_00139620(s);
        func_0028dcc0(s, o);
        s->x1ac = 3;
        s->x1a4 = 0x60000008;
    }

    if (e->flags.v & 0x800) {
        s = &D_0035f5b0.p->a[2];
        void* sub = s->sub;
        func_0028d980(s, base, D_0035f14c, D_0035f148, D_0035f210, 78, -1, -1, 0);
        s->x198 = func_00192048(0x489b);
        a = func_0023aa18(sub);
        b = func_0023aa38(sub);
        d = func_0023aa58(sub);
        func_0028dcc0(s, o);
        func_00139620(s);
        func_001395f8(s);
        s = &D_0035f5b0.p->a[3];
        func_0028d980(s, base + 1, D_0035f14c, D_0035f148, D_0035f210, func_00276c38(2), -1, -1, 0);
        s->x198 = func_00192cc0(D_0035f5b0.p->num, D_003749e8, func_00294368(e));
        func_00139620(s);
        func_0028dcc0(s, &D_0035f5b0.p->a[2]);
        func_001395f8(s);
        func_00138c68(s, a, b);
        s->x1b0 = 1;
        s->x1a8 = d;
    }

    {
        W1650Lay* l = &D_0035f5b0.p->d[0];
        func_0028d8c0(l, base, D_0035f14c, D_0035f148, D_0035f210, 81, -1, 0);
        func_0028dcc0(l, o);
        l = &D_0035f5b0.p->d[1];
        func_0028d8c0(l, base, D_0035f14c, D_0035f148, D_0035f210, 82, -1, 0);
        func_0028dcc0(l, o);
        void* sub = w->sub;
        l = &w->x330;
        v = D_00374ae0[e->x2];
        func_0028d8c0(l, base, D_0035f14c, D_0035f148, D_0035f210, v, -1, 0);
        func_0028dcc0(l, w);
        a = func_0023aa18(sub);
        b = func_0023aa38(sub);
        func_00138c68(l, a, b);
        D_0035f5b0.p->x1b3b = func_0023aa78(sub);
    }
    D_0035f5b0.p->x1b08.v = e->x8;
    D_0035f5b0.p->x1b3a = func_00192b80(func_00192048(e->x8));
    {
        s32 lv = D_0035f5b0.p->x1b3a;
        s32 n = (lv < 8) ? 1 : lv - 6;
        func_0028af90(D_0035f200, n);
        func_002891f0(D_0035f200, 0, 0, -1, -1);
        func_0028afd0(D_0035f200, 0);
        if (n >= 2) {
            func_0028b218(D_0035f200, 1);
            func_0028b248(D_0035f200, 7);
        }
    }
    func_002fde18(w->names, 0, sizeof(w->names));

    if (mode == 19 || mode == 22) {
        W1650Tbl* t = func_001d23e0(func_0016e920(e->xc)->x4c);
        if (t != 0) {
            s32 n = 0;
            s32 i;
            for (i = 0; i < 5; i++) {
                u16 id = t->ids[i];
                W1650Item* it;
                if (id == 0) continue;
                it = func_001b8e88(id);
                if (func_001b90a8(it) == 0 && func_00276c18() == 0) continue;
                v = 0;
                if (it != 0) {
                    v = func_001b90a8(it);
                    if (v >= 1000) { v = 999; asm(""); }
                }
                s = &D_0035f5b0.p->item[n];
                func_0028d980(s, 30052, D_0035f14c, D_0035f148, D_0035f210, 79, -1, -1, 0);
                {
                    k = it->x8;
                    if (v != 0) k = func_00192048(k);
                    else k = func_0028de08(k, w->names[n], 64);
                    s->x198 = k;
                }
                void* sub = s->sub;
                a = func_0023aa18(sub);
                b = func_0023aa38(sub);
                s32 c = func_0023aa78(sub);
                d = func_0023aa58(sub);
                func_00138c68(s, 0, c * n);
                func_0028dcc0(s, o);
                func_00139620(s);
                func_001395f8(s);
                s = &D_0035f5b0.p->cnt[n];
                func_0028d980(s, 30053, D_0035f14c, D_0035f148, D_0035f210, func_00276c38(2), -1, -1, 0);
                s->x198 = func_00192cc0(D_0035f5b0.p->nums[n], D_003749e8, v);
                func_00139620(s);
                func_0028dcc0(s, &D_0035f5b0.p->item[n]);
                func_001395f8(s);
                func_00138c68(s, a, b);
                { register s32 one asm("$13") = 1; s->x1b0 = one; }
                s->x1a8 = d;
                n++;
            }
        }
    }
}
}  // namespace n0029d318

// 0029da68 (was src/anon/tiny_auto80_solver.cpp)
namespace n0029da68 {
u32 func_00294000(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00294000jjjjjjjj");
/*TARGET 0029da68*/
u32 func_0029da68(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0029da68jjjjjjjj");
u32 func_0029da68(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16;
    r16 = r4;
    r4 = (u32)((s32)0u + (3));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00294000)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = (u32)((s32)0u + (36));
    r16 = (u32)(r16 * r15);
    r2 = (u32)((s32)r2 + (16));
    r2 = (u32)(r2 + r16);
    return r2;
}
}  // namespace n0029da68

// 0029daa0 (was src/anon/batch_w77.cpp)
namespace n0029daa0 {
extern u8* D_0035f5b0 asm("D_0035f5b0");
extern u32 D_0035f200 asm("D_0035f200");
s32 func_00139d78(u8*) asm("func_00139d78");
s32 func_0028b040(u32) asm("func_0028b040");
s32 func_0028afa8(u32) asm("func_0028afa8");
void func_00139570(u8*) asm("func_00139570");
void func_00139580(u8*) asm("func_00139580");
/*TARGET 0029daa0*/
void func_0029daa0(void) asm("func_0029daa0");
void func_0029daa0(void)
{
    if (!func_00139d78(D_0035f5b0 + 6104)) return;
    if (!func_00139d78(D_0035f5b0 + 6512)) return;
    s32 cur = func_0028b040(D_0035f200);
    s32 n = func_0028afa8(D_0035f200);
    if (n < 2) {
        func_00139570(D_0035f5b0 + 6104);
        func_00139570(D_0035f5b0 + 6512);
    } else if (cur == 0) {
        func_00139570(D_0035f5b0 + 6104);
        func_00139580(D_0035f5b0 + 6512);
    } else if (cur >= n - 1) {
        func_00139580(D_0035f5b0 + 6104);
        func_00139570(D_0035f5b0 + 6512);
    } else {
        func_00139580(D_0035f5b0 + 6104);
        func_00139580(D_0035f5b0 + 6512);
    }
}
}  // namespace n0029daa0

// 0029dba0 (was src/anon/perm_0029dba0.cpp)
namespace n0029dba0 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
struct Gw29dba0
{
  u8 pad[6920];
  s16 id;
  u8 pad2[49];
  s8 col;
};
struct Rc29dba0
{
  u8 pad[20];
  s32 w;
};
extern void *D_0035f200 asm("D_0035f200");
extern u8 *D_0035f224 asm("D_0035f224");
extern Gw29dba0 *D_0035f5b0 asm("D_0035f5b0");
u8 *func_002766d0(void) asm("func_002766d0");
s32 func_0028b040(void *a) asm("func_0028b040");
void func_0014b950(void *p, s16 x, s16 y, u16 w, u16 c) asm("func_0014b950");
void func_0014b9a8(void *p) asm("func_0014b9a8");
s32 func_0023aa58(void *p) asm("func_0023aa58");
s32 func_0023aa78(void *p) asm("func_0023aa78");
Rc29dba0 *func_001aae68(s32 a) asm("func_001aae68");
s32 func_00192048(s16 id) asm("func_00192048");
void func_001a98e8(void *t, s32 a, s32 b, s32 c, s32 d) asm("func_001a98e8");
void func_001aa6d0(void *t, s32 w) asm("func_001aa6d0");
void func_001a9ae8(void *t, s32 x, s32 y, s32 z) asm("func_001a9ae8");
/*TARGET 0029dba0*/
void func_0029dba0(s32 x, s32 y, s32 z) asm("func_0029dba0");
void func_0029dba0(s32 x, s32 y, s32 z)
{
  u8 buf[96];
  s32 lo = 15;
  u8 *ent;
  s32 sc;
  s32 *new_var;
  s32 a;
  s32 b;
  ent = func_002766d0() + 24;
  sc = func_0028b040(D_0035f200);
  func_0014b950(D_0035f224 + 32, x, y, 512 - x, D_0035f5b0->col * 7);
  func_0014b9a8(D_0035f224 + 32);
  a = func_0023aa58(ent);
  b = func_0023aa78(ent);
  if (a)
  {
    lo = a;
  }
  sc *= b;
  {
    Rc29dba0 *r = func_001aae68(3);
    b -= lo;
    y -= sc;
    b -= r->w;
  }
  if (b < 0)
  {
    b = 0;
  }
  func_001a98e8(buf, 3, func_00192048(D_0035f5b0->id), lo, 0);
  func_001aa6d0(buf, b);
  func_001a9ae8(buf, x, *(new_var = &y), z);
  func_0014b9a8(D_0035f224);
}
}  // namespace n0029dba0

// 0029dd00 (was src/anon/batch_w49.cpp)
namespace n0029dd00 {
// obj_dec_timer



void func_002ff2e8(char*, const char*) asm("func_002ff2e8");
// 0x0027ae78: definition moved into src/anon/unit_0027a6d8.cpp

extern s8* D_0035f5ac asm("D_0035f5ac");
extern char* D_0035f5c8 asm("D_0035f5c8");
extern char* D_0035f5cc asm("D_0035f5cc");
u32 func_00293de8(s32) asm("func_00293de8");
void func_00293cb8(char*, s32, u32) asm("func_00293cb8");
char* func_002ff918(char*, const char*) asm("func_002ff918");
void func_002931a8(char*) asm("func_002931a8");
/*TARGET 0029dd00*/
void func_0029dd00(void) asm("func_0029dd00");
void func_0029dd00(void) {
    char buf[128];
    func_00293cb8(buf, 4, func_00293de8(D_0035f5ac[4]));
    char* r = func_002ff918(buf, D_0035f5c8);
    if (r) func_002ff2e8(r, D_0035f5cc);
    func_002931a8(buf);
}
}  // namespace n0029dd00

// 0029dd60 (was src/tozawa/jm_dic.cpp)
namespace Tz { // method 0029dd60
u32 func_00276638(u32) asm("func_00276638");
u32 func_0029da68(u32) asm("func_0029da68");
void func_00292b40(void*, u32) asm("func_00292b40");
/*TARGET 0029dd60*/
void JmDic::RequestGraLoad() {
    s16 tmp;
    u32 v0 = func_00276638(15);
    u32 base = 0x00360000u;
    v0 = v0 << 1;
    v0 = v0 + *(u32*)(base + (s32)-2644);
    v0 = func_0029da68((u32)(s16)*(u16*)(v0 + 8));
    tmp = *(s8*)(v0 + 1);
    func_00292b40(&tmp, 1);
}
}  // Tz

// 0029dda8 (was src/anon/batch_w43.cpp)
namespace n0029dda8 {
s32 func_00276638(s32) asm("func_00276638");
extern u8* D_0035f5ac asm("D_0035f5ac");
u8* func_0029da68(s32) asm("func_0029da68");
s32 func_00292a90(s32) asm("func_00292a90");
s32 func_00292af0(s32) asm("func_00292af0");
void func_0029dd60(void) asm("func_0029dd60");
/*TARGET 0029dda8*/
// 0028f690: moved to src/anon/unit_0028f1e0.cpp

void func_0029dda8(void) asm("func_0029dda8");
// 0028f690: moved to src/anon/unit_0028f1e0.cpp

void func_0029dda8(void) {
    s32 i = func_00276638(15);
    u8* e = func_0029da68(*(s16*)(D_0035f5ac + i * 2 + 8));
    s32 s = *(s8*)(e + 1);
    if (func_00292a90(s)) return;
    if (func_00292af0(s)) return;
    func_0029dd60();
}
}  // namespace n0029dda8

// 0029de18 (was src/anon/batch_w1944_gnsa.cpp)
namespace n0029de18 {
struct W1944S43 { u8 pad[0xb8]; u32 fl; };
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s16* D_0035f5ac asm("D_0035f5ac");
void func_001386e0(u8*, s32, s32, u8*, s32, s32) asm("func_001386e0");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_00139620(u8*) asm("func_00139620");
s32 func_00139d78(u8*) asm("func_00139d78");
void func_002362b0(u8*, s32) asm("func_002362b0");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
s32 func_0023c4b8(s32, s32) asm("func_0023c4b8");
s32 func_0023f1b0(s32) asm("func_0023f1b0");
s32 func_00276638(s32) asm("func_00276638");
u8* func_002766d0() asm("func_002766d0");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
s32 func_00292a90(s32) asm("func_00292a90");
s32 func_00293148(s32) asm("func_00293148");
s8* func_0029da68(s32) asm("func_0029da68");
void func_0029dda8() asm("func_0029dda8");
static inline __attribute__((always_inline)) void w1944_set8(u8* p, s32 v) { *p = v; }
/*TARGET 0029de18*/
void func_0029de18(void) asm("func_0029de18");
void func_0029de18(void) {
    u8* w = func_002766d0();
    func_0029dda8();
    u8* obj = w + 0x4398;
    s32 kind = func_0029da68(D_0035f5ac[func_00276638(0xF) + 4])[1];
    if (func_00292a90(kind) == 0) return;
    if (func_00139d78(obj) != 0) return;
    u8* s3 = w + 0x18;
    s32 s1 = D_0035f3d4 + 2;
    s32 s2 = func_0023c4b8(func_0023f1b0(D_0035f210), 0);
    u8* e = w + 0xDCA0;
    func_002362b0(e, func_00293148(kind));
    w1944_set8(e + 0x190, 1);
    func_001386e0(obj, s1, s2, e, 1, 0);
    *(s32*)(obj + 0x188) = 2;
    func_00139620(obj);
    W1944S43* f = (W1944S43*)(w + 0x43B0);
    f->fl |= 8;
    obj[0x195] = 1;
    func_0028dcc0(obj, w);
    s32 a = func_0023aa18(s3);
    func_00138c68(obj, a, func_0023aa38(s3));
}
}  // namespace n0029de18

// 0029df98 (was src/anon/batch_w2.cpp)
namespace n0029df98 {
u8* func_002766d0() asm("func_002766d0");
void func_0028dac8(u8*, s32) asm("func_0028dac8");
/*TARGET 0029df98*/
// 0028dfe8: moved to src/anon/unit_0028c878.cpp

void func_0029df98(void) asm("func_0029df98");
// 0028dfe8: moved to src/anon/unit_0028c878.cpp

void func_0029df98(void) {
    func_0028dac8(func_002766d0() + 17304, 3);  // Tz::Select::FadeOut(Jiminy seq table, 3)
}
}  // namespace n0029df98

// 0029dfc0 (was src/tozawa/jm_dic.cpp)
namespace Tz { // method 0029dfc0
u32 func_002766d0() asm("func_002766d0");
u32 func_00139d78(u32) asm("func_00139d78");
void func_0028d8c0(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_0028d8c0");
void func_0028dcc0(u32, u32) asm("func_0028dcc0");
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f210 asm("D_0035f210");
/*TARGET 0029dfc0*/
void JmDic::SetupCharaInfo() {
    u32 s1 = func_002766d0();
    u32 s0 = s1 + 0x4860;

    if (func_00139d78(s0) != 0) {
        return;
    }

    func_0028d8c0(s0, 30055, D_0035f14c, D_0035f148, D_0035f210, 4, 5, 0);
    func_0028dcc0(s0, s1);
}
}  // Tz

// 0029e050 (was src/anon/batch_w3.cpp)
namespace n0029e050 {
// 0x00281e70: definition moved into src/anon/unit_00281cf0.cpp

u32 func_002766d0() asm("func_002766d0");
void func_0028dac8(u32, u32) asm("func_0028dac8");
/*TARGET 0029e050*/
void func_0029e050() asm("func_0029e050");
void func_0029e050() { func_0028dac8(func_002766d0() + 18528, 6); }
}  // namespace n0029e050

// 0029e078 (gap: menu object update)
namespace g0029e078 {
u8* func_002766d0(void) asm("func_002766d0");
s32 func_00139d78(void*) asm("func_00139d78");
void func_0029e078(void) asm("func_0029e078");
void func_0029e078(void) {
    u8* b = func_002766d0();
    u8* o = b + 0x4860;
    if (func_00139d78(o)) {
        void** vt = *(void***)(b + 0x4860);
        ((void (*)(u8*))vt[5])(o);
    }
}
}  // namespace g0029e078

// 0029e0d0 (was src/anon/batch_w4.cpp)
namespace n0029e0d0 {
void* func_002766d0(void) asm("func_002766d0");
u8 func_00139d78(void*) asm("func_00139d78");
/*TARGET 0029e0d0*/
// 0x00265c50: definition moved into src/anon/unit_00265580.cpp

u32 func_0029e0d0(void) asm("func_0029e0d0");
// 0x00265c50: definition moved into src/anon/unit_00265580.cpp

u32 func_0029e0d0(void) {
    return func_00139d78((u8*)func_002766d0() + 18528);
}
}  // namespace n0029e0d0

// 0029e0f8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0029e0f8 {
u32 func_002766d0(...) asm("func_002766d0");
u32 func_00139d78(...) asm("func_00139d78");
/*TARGET 0029e0f8*/
u32 func_0029e0f8() asm("_Z13func_0029e0f8v");
u32 func_0029e0f8() {
    u32 s1 = 0;
    u32 s0 = func_002766d0() + 18528;
    if (func_00139d78((void*)s0) != 0) {
        s1 = (*(u32*)(s0 + 388) == 5);
    }
    return s1;
}
}  // namespace n0029e0f8

// 0029e148 (was src/anon/batch_w5.cpp)
namespace n0029e148 {
// 0x0026c450: definition moved into src/anon/unit_0026c450.cpp

u8* func_002766d0(void) asm("func_002766d0");
void func_0028da70(u8*, u32) asm("func_0028da70");
/*TARGET 0029e148*/
void func_0029e148(void) asm("func_0029e148");
void func_0029e148(void) {
    func_0028da70(func_002766d0() + 18528, 5);
}
}  // namespace n0029e148

// 0029e170 (was src/anon/batch_w90.cpp)
namespace n0029e170 {
s32 func_00139d78(void*) asm("func_00139d78");
// 00291288: moved to src/anon/unit_00290f78.cpp

// 0029e170
u8* func_002766d0(void) asm("func_002766d0");
void func_0028d8c0(void*, void*, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
void func_00138cb8(void*, s32*, s32*) asm("func_00138cb8");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
extern u8* D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f210 asm("D_0035f210");
/*TARGET 0029e170*/
void func_0029e170(s32 a0) asm("func_0029e170");
void func_0029e170(s32 a0)
{
    u8* w = func_002766d0();
    s32 n = a0 + 1;
    u8* o = w + n * 408 + 17304;
    u8* h = D_0035f3d4 + 4;
    if (!func_00139d78(o)) {
        func_0028d8c0(o, h, D_0035f14c, D_0035f148, D_0035f210, 7, 8, 0);
        func_0028dcc0(o, w);
    }
    s32 xy[2];
    func_00138cb8(w, &xy[0], &xy[1]);
    if (!a0) func_00138c68(o, 340 - xy[0], 208 - xy[1]);
    else func_00138c68(o, 256 - xy[0], 208 - xy[1]);
}
}  // namespace n0029e170

// 0029e258 (was src/anon/batch_w16.cpp)
namespace n0029e258 {
u8* func_002766d0(s32) asm("func_002766d0");
void func_0028dac8(void*, u32) asm("func_0028dac8");
/*TARGET 0029e258*/
// 00290870: moved to src/anon/unit_0028f1e0.cpp

void func_0029e258(s32 i) asm("func_0029e258");
// 00290870: moved to src/anon/unit_0028f1e0.cpp

void func_0029e258(s32 i) {
    u8* b = func_002766d0(i);
    i++;
    func_0028dac8(b + i * 408 + 17304, 9);
}
}  // namespace n0029e258

// 0029e298 (was src/anon/auto80_199_queue.cpp)
namespace n0029e298 {
/*TARGET 0029e298*/
void func_0029e298(u32 a0) asm("_Z13func_0029e298j");
void func_0029e298(u32 a0) {
    u32 v0 = func_002766d0();
    a0 += 1;
    u32 s0 = v0 + a0 * 408u;
    u32 s1 = s0 + 17304u;

    if (func_00139d78(s1) == 0) {
        return;
    }

    u32 t7 = *(u32*)(s0 + 17304u);
    (*(void (**)(u32))(t7 + 20))(s1);
}
}  // namespace n0029e298

// 0029e2f8 (was src/anon/batch_w17.cpp)
namespace n0029e2f8 {
// 0x00293f78: definition moved into src/anon/unit_00292e60.cpp

u8* func_002766d0(void) asm("func_002766d0");
u8 func_00139d78_u8(void*) asm("func_00139d78");
/*TARGET 0029e2f8*/
u8 func_0029e2f8(s32 i) asm("func_0029e2f8");
u8 func_0029e2f8(s32 i) {
    i++;
    return func_00139d78_u8(func_002766d0() + i * 408 + 17304);
}
}  // namespace n0029e2f8

// 0029e338 (was src/anon/auto80_199_queue.cpp)
namespace n0029e338 {
/*TARGET 0029e338*/
u32 func_0029e338(u32 a0) asm("_Z13func_0029e338j");
u32 func_0029e338(u32 a0) {
    a0 += 1;
    u32 s1 = 0;
    u32 v0 = func_002766d0();
    u32 s0 = v0 + a0 * 408u + 17304u;

    if (func_00139d78(s0) != 0) {
        s1 = (*(u32*)(s0 + 388u) == 8u);
    }

    return s1;
}
}  // namespace n0029e338

// 0029e3a0 (was src/anon/batch_w18.cpp)
namespace n0029e3a0 {
// 0x00293fc0: definition moved into src/anon/unit_00292e60.cpp

u8* func_002766d0(void) asm("func_002766d0");
void func_0028da70(void*, u32) asm("func_0028da70");
/*TARGET 0029e3a0*/
void func_0029e3a0(s32 i) asm("func_0029e3a0");
void func_0029e3a0(s32 i) {
    u8* v = func_002766d0();
    i++;
    func_0028da70((u8*)v + i * 408 + 17304, 8);
}
}  // namespace n0029e3a0

// 0029e3e0 (was src/anon/batch_w29.cpp)
namespace n0029e3e0 {
void func_00292630(void) asm("func_00292630");
void func_0029e430(void) asm("func_0029e430");
void func_00293c40(s32, u32) asm("func_00293c40");
void func_002925c0(void) asm("func_002925c0");
extern s8 D_0035f228 asm("D_0035f228");
extern s16 D_0035f5b6 asm("D_0035f5b6");
/*TARGET 0029e3e0*/
// 0x002956c0: definition moved into src/anon/unit_00292e60.cpp

void func_0029e3e0(u32 a) asm("func_0029e3e0");
// 0x002956c0: definition moved into src/anon/unit_00292e60.cpp

void func_0029e3e0(u32 a) {
    func_00292630();
    func_0029e430();
    D_0035f5b6 = a;
    func_00293c40((s16)a, D_0035f228 == 1);
    func_002925c0();
}
}  // namespace n0029e3e0

// 0029e430 (was src/anon/batch_w1773_g.cpp)
namespace n0029e430 {
/* 0029e430 (matches only with -g) */
s32 Tz_LoadDataIsFlushing(void) asm("_ZN2Tz18LoadDataIsFlushingEv");
void* Tz_MenuBase_GetMenuObj(void) asm("_ZN2Tz8MenuBase10GetMenuObjEv");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_0023d820(void*) asm("func_0023d820");
void Tz_JMData_Clear(s32) asm("_ZN2Tz6JMData5ClearEi");
void Tz_JMData_Destroy(s32) asm("_ZN2Tz6JMData7DestroyEi");
extern void* D_0035f5bc asm("D_0035f5bc");
extern s16 D_0035f5b6 asm("D_0035f5b6");
extern s8 D_0035f228 asm("D_0035f228");
/*TARGET 0029e430*/
void func_0029e430(void) asm("func_0029e430");
void func_0029e430(void) {
    Tz_LoadDataIsFlushing();
    void* o = Tz_MenuBase_GetMenuObj();
    if (u_call4_00139d78(o)) func_0023d820(o);
    if (u_call4_00139d78(D_0035f5bc)) func_0023d820(D_0035f5bc);
    D_0035f5b6 = -1;
    if (D_0035f228 == 1) Tz_JMData_Destroy(5103);
    else Tz_JMData_Clear(5103);
}
}  // namespace n0029e430

// 0029e4c8 (was src/anon/batch_w1610.cpp)
namespace n0029e4c8 {
struct W1610Mdl;
struct W1610MdlVt { u8 pad[24]; void (*set)(W1610Mdl*, s32, u32, u32, s32, s32, s32); };
struct W1610Mdl { W1610MdlVt* vt; };
struct W1610Fx { u8 pad[12]; u16 id; u16 sub; u16 fl; s16 x0; s16 y0; s16 z0; s16 x1; s16 y1; f32 s0; f32 s1; };
union W1610Fl { u16 w; struct { u16 v : 10; u16 pad : 2; u16 on : 1; u16 hi : 1; u16 r : 2; } b; };
struct W1610Tb { u8 pad[8]; s16 idx[1]; };
s32 func_00139d78(void*) asm("func_00139d78");
// 00291de0: moved to src/anon/unit_00290f78.cpp
extern W1610Tb* D_0035f5ac asm("D_0035f5ac");
extern s16 D_0035f5b6 asm("D_0035f5b6");
extern W1610Mdl* D_0035f5bc asm("D_0035f5bc");
u8* func_002766d0(void) asm("func_002766d0");
s32 func_0029e2f8(s32) asm("func_0029e2f8");
s32 func_00292630(void) asm("func_00292630");
s32 func_00293200(void) asm("func_00293200");
s32 func_00276638(s32) asm("func_00276638");
W1610Fx* func_0029da68(s32) asm("func_0029da68");
void func_0029e3e0(u16) asm("func_0029e3e0");
void func_0029e170(s32) asm("func_0029e170");
W1610Mdl* func_00287dc0(void) asm("func_00287dc0");
void func_0023d808(W1610Mdl*, s32) asm("func_0023d808");
s32 func_0029ec98(u16) asm("func_0029ec98");
void func_0023e858(W1610Mdl*, s32, f32) asm("func_0023e858");
void func_0023e8d8(W1610Mdl*, s32, f32) asm("func_0023e8d8");
void func_0023e918(W1610Mdl*, s32, f32, f32, f32) asm("func_0023e918");
void func_0023e9c8(W1610Mdl*, s32, u8*) asm("func_0023e9c8");
void func_0023ec38(W1610Mdl*, s32) asm("func_0023ec38");
void func_0023eb50(W1610Mdl*, s32, s32) asm("func_0023eb50");
s32 func_0029e7b0(u16) asm("func_0029e7b0");
void func_0023e660(W1610Mdl*, s32, s32) asm("func_0023e660");
/*TARGET 0029e4c8*/
void func_0029e4c8(s32 n) asm("func_0029e4c8");
void func_0029e4c8(s32 n) {
    u8* base = func_002766d0();
    if (func_0029e2f8(n)) return;
    if (func_00292630()) return;
    if (func_00293200()) return;
    s32 k = func_00276638(15);
    W1610Fx* fx = func_0029da68(D_0035f5ac->idx[k]);
    if (D_0035f5b6 < 0) {
        func_0029e3e0(fx->id);
        return;
    }
    func_0029e170(n);
    W1610Mdl* m;
    if (n == 0) {
        m = func_00287dc0();
        if (!func_00139d78(m)) func_0023d808(m, 30051);
    } else {
        m = D_0035f5bc;
        if (!func_00139d78(m)) func_0023d808(m, 30056);
    }
    f32 y = -100.0f;
    f32 z;
    f32 s;
    s32 a, b;
    if (n == 0) {
        z = fx->z0;
        a = fx->x0;
        b = fx->y0;
        s = fx->s0;
    } else {
        a = fx->x1;
        b = fx->y1;
        s = fx->s1;
        z = 0.0f;
    }
    u16 id = fx->id;
    if (func_0029ec98(id)) {
        y = (n == 0 ? fx->s0 : fx->s1) + -100.0f;
        s = 1.0f;
    }
    m->vt->set(m, 0, id | 0x30000000, fx->sub, 2, a, b);
    func_0023e858(m, 0, y);
    func_0023e8d8(m, 0, z);
    func_0023e918(m, 0, s, s, s);
    func_0023e9c8(m, 0, base + n * 408 + 17712);
    func_0023ec38(m, 1);
    W1610Fl fl;
    fl.w = fx->fl;
    s32 v = fl.b.v;
    if (fl.w & 0x1000) {
        if (fl.w & 0x2000) v = v << 10;
        else v = v << 20;
    }
    func_0023eb50(m, 0, v);
    s32 r = func_0029e7b0(id);
    if (r >= 0) func_0023e660(m, 0, r);
}
}  // namespace n0029e4c8

// .rodata 0x374a08-0x374a48: this file's const tables, read by other code as extern D_
namespace r00374a08 {
extern const u32 R_00374a08[14] asm("D_00374a08") __attribute__((aligned(4))) = { 0x410926, 0x4209fe, 0x430928, 0x440929, 0x45092a, 0x46092b, 0x47092c, 0x48092d, 0x49092e, 0x4a092f, 0x4b09ff, 0x4c0931, 0x4d0932, 0x0 };
extern const u32 R_00374a40[2] asm("D_00374a40") __attribute__((aligned(4))) = { 0x40000000, 0x41800000 };
}  // namespace r00374a08

// 0029e7b0 (was src/anon/batch_w216.cpp)
namespace n0029e7b0 {
struct W216Pair { s16 k; s16 v; };
extern W216Pair D_00374a08[] asm("D_00374a08");
/*TARGET 0029e7b0*/
s32 func_0029e7b0(s32 k) asm("func_0029e7b0");
s32 func_0029e7b0(s32 k) {  // short_table_lookup
    s32 r = -1;
    for (s32 i = 0; D_00374a08[i].k > 0; i++) {
        if (D_00374a08[i].k == k) { r = D_00374a08[i].v; break; }
    }
    return r;
}
}  // namespace n0029e7b0

// 0029e808 (was src/anon/batch_w94.cpp)
namespace n0029e808 {
s32 func_00276638(s32) asm("func_00276638");
u8* func_0029da68(s16) asm("func_0029da68");
void func_0023e788(f32*, u32, s32) asm("func_0023e788");
s32 func_0029ec40(u16) asm("func_0029ec40");
double func_00313b80(f32) asm("func_00313b80");
// float_to_double
s32 func_003142e0(double, double) asm("func_003142e0");
// double_compare
void func_0023e8d8(u32, s32, f32) asm("func_0023e8d8");
extern s16* D_0035f5ac asm("D_0035f5ac");
extern u32 D_0035f5bc asm("D_0035f5bc");
/*TARGET 0029e808*/
void func_0029e808(s32 dir) asm("func_0029e808");
void func_0029e808(s32 dir) {
    u8* e = func_0029da68(D_0035f5ac[func_00276638(15) + 4]);
    f32 v[4] __attribute__((aligned(16)));
    func_0023e788(v, D_0035f5bc, 0);
    f32 a = v[1];
    if (dir == -12) {
        a += 2.0f;
        if (func_0029ec40(*(u16*)(e + 12)) && 16.0f < a) a = 16.0f;
    } else {
        a -= 2.0f;
        if (func_0029ec40(*(u16*)(e + 12)) && a < -16.0f) a = -16.0f;
    }
    double d = func_00313b80(a);  // float_to_double
    if (func_003142e0(360.0, d) <= 0) a -= 360.0f;
    else if (func_003142e0(d, -360.0) <= 0) a += 360.0f;
    func_0023e8d8(D_0035f5bc, 0, a);
}
}  // namespace n0029e808

// 0029e950 (was src/anon/tiny_more.cpp)
namespace n0029e950 {
extern u32 D_0035f5ac asm("D_0035f5ac");
/*TARGET 0029e950*/
// 0x00276578: definition moved into src/anon/unit_002748a0.cpp

void func_0029e950(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0029e950jjjj");
// 0x00276578: definition moved into src/anon/unit_002748a0.cpp

void func_0029e950(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p = D_0035f5ac; *(u8*)((u32)p + (4)) = (u8)a0; }
}  // namespace n0029e950

// 0029e960 (was src/anon/auto80_199_queue.cpp)
namespace n0029e960 {
/*TARGET 0029e960*/
void func_0029e960(void) asm("_Z13func_0029e960v");
void func_0029e960(void) {
    if (D_0035f5c0 != 0) {
        return;
    }

    u32 v0 = func_00103b48(0, 0x0001adb0, &D_0015de58);
    D_0035f5c0 = v0;
    u32 v1 = func_00103580();

    u32 t = D_0034b278;
    D_0034b278 = v1;
    D_0034b27c = t;

    func_0015def8();
}
}  // namespace n0029e960

// 0029e9d0 (was src/harata/libdk/glow.cpp)
namespace dk { // method 0029e9d0
extern u32 D_0035f5c0 asm("D_0035f5c0");
extern u32 D_0034b278 asm("D_0034b278");
extern u32 D_0034b27c asm("D_0034b27c");
u32 func_00103eb0() asm("func_00103eb0");
void func_00102670(u32, u32) asm("func_00102670");
// to_1025f8
extern "C" void func_0015df98() asm("func_0015df98");
/*TARGET 0029e9d0*/
void Glow::menuDestroy() {
    if (D_0035f5c0 == 0) {
        return;
    }

    u32 v0 = func_00103eb0();
    func_00102670(*(u32*)(v0 + 4), D_0035f5c0);  // to_1025f8
    func_0015df98();

    D_0035f5c0 = 0;
    D_0034b278 = D_0034b27c;
}
}  // dk

// 0029ea30 (was src/anon/batch_w1521.cpp)
namespace n0029ea30 {
// 001ac5b8: moved to src/anon/unit_001abb28.cpp

s32 func_00287bc0(void) asm("func_00287bc0");
void func_00276c50(s32, s32) asm("func_00276c50");
/*TARGET 0029ea30*/
void func_0029ea30(void) asm("func_0029ea30");
void func_0029ea30(void) {
    s32 v;
    switch (func_00287bc0()) {
    case 14: v = 0x48ee; break;
    case 15: v = 0x48ef; break;
    case 18: v = 0x48f0; break;
    default: v = 0x48f3; break;
    case 21: v = 0x48f1; break;
    case 16: case 19: case 22: v = 0x48f2; break;
    }
    func_00276c50(v, 0);
}
}  // namespace n0029ea30

// 0029eaa8 (was src/anon/batch_w1933_g.cpp)
namespace n0029eaa8 {
u32* func_002a9d68(void) asm("func_002a9d68");
u8* func_002766d0(void) asm("func_002766d0");
u8* func_00294000(s32) asm("func_00294000");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028b040(s32) asm("func_0028b040");
s32 func_00276638(s32) asm("func_00276638");
s32 func_002943b0(u8*) asm("func_002943b0");
void func_002aa048(s32) asm("func_002aa048");
s32 func_002891e8(s32) asm("func_002891e8");
s32 func_00139d78(u8*) asm("func_00139d78");
void func_00138c10(u8*, s32) asm("func_00138c10");
struct S5ac { u8 pad[5]; s8 b5; u8 pad2[2]; s16 ids[1]; };
extern S5ac* D_0035f5ac asm("D_0035f5ac");
extern s32 D_0035f200 asm("D_0035f200");
/*TARGET 0029eaa8*/
void func_0029eaa8(void) asm("func_0029eaa8");
void func_0029eaa8(void) {
    u32* bits = func_002a9d68();
    u8* base = func_002766d0();
    if (D_0035f5ac->b5 == 0) return;
    u8* tbl = func_00294000(3) + 16;
    s32 k = func_00287bc0();
    s32 idx;
    switch (k) {
    case 15: case 18: case 21:
        idx = func_0028b040(D_0035f200);
        break;
    case 16: case 19: case 22:
        idx = func_00276638(15);
        break;
    default:
        return;
    }
    s16 id = D_0035f5ac->ids[idx];
    if (func_002943b0(tbl + id * 36) == 0) return;
    u32 uid = id;
    if (bits[uid >> 5] & (1 << (uid & 31))) return;
    func_002aa048(id);
    switch (k) {
    case 15: case 18: case 21: {
        idx = func_002891e8(D_0035f200);
        u8* o = base + idx * 0x198 + 0xa998;
        if (func_00139d78(o) != 0) func_00138c10(o, 93);
        break;
    }
    }
}
}  // namespace n0029eaa8

// .rodata 0x374a9c-0x374aac: pad word + this file's const values, read by other code as extern D_
namespace r00374a9c {
extern const u32 R_00374a9c[1] asm("D_00374a9c") __attribute__((aligned(4))) = { 0x0 };
extern const u32 R_00374aa0[2] asm("D_00374aa0") __attribute__((aligned(4))) = { 0x8fc, 0x0 };
extern const u32 R_00374aa8[1] asm("D_00374aa8") __attribute__((aligned(4))) = { 0x3e4 };
}  // namespace r00374a9c

// 0029ec40 (was src/anon/batch_w50.cpp)
namespace n0029ec40 {
extern u16 D_00374aa0[] asm("D_00374aa0");
/*TARGET 0029ec40*/
// Is id in the zero-terminated u16 list?
s32 func_0029ec40(u32 id) asm("func_0029ec40");
// Is id in the zero-terminated u16 list?
s32 func_0029ec40(u32 id) {
    s32 r = 0;
    for (s32 i = 0; D_00374aa0[i]; i++) {
        if (D_00374aa0[i] == id) { r = 1; break; }
    }
    return r;
}
}  // namespace n0029ec40

// 0029ec98 (was src/anon/batch_w51.cpp)
namespace n0029ec98 {
// 0028ff18: moved to src/anon/unit_0028f1e0.cpp

extern u16 D_00374aa8[] asm("D_00374aa8");
/*TARGET 0029ec98*/
// Is id in the zero-terminated list?
s32 func_0029ec98(u32 id) asm("func_0029ec98");
// Is id in the zero-terminated list?
s32 func_0029ec98(u32 id) {  // table_contains_short
    s32 r = 0;
    for (s32 i = 0; D_00374aa8[i] != 0; i++) {
        if (D_00374aa8[i] == id) {
            r = 1;
            break;
        }
    }
    return r;
}
}  // namespace n0029ec98

// 0029ecf0 (was src/anon/batch_wcx2.cpp)
namespace n0029ecf0 {
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
// --------------------
struct T29ecf0 { u8 pad[8]; s16 idx[1]; };
extern T29ecf0* D_0035f5ac asm("D_0035f5ac");
s32 func_00287bc0() asm("func_00287bc0");
u8* func_00294000_x9122(s32) asm("func_00294000");
s32 func_0029c9d8(s32) asm("func_0029c9d8");
s32 func_002954e0(s32) asm("func_002954e0");
s32 func_002943b0(u8*) asm("func_002943b0");
/*TARGET 0029ecf0*/
s32 func_0029ecf0(s32 a) asm("func_0029ecf0");
s32 func_0029ecf0(s32 a) {
    s32 n = func_00287bc0();
    u8* base = func_00294000_x9122(3) + 16;
    switch (n) {
    case 14:
        if (a < 0) return 1;
        return func_002954e0(func_0029c9d8(a)) != 0;
    case 15: case 18: case 21:
        if (a < 0) return 1;
        return func_002943b0(base + D_0035f5ac->idx[a] * 36) != 0;
    case 16: case 19: case 22:
        return 1;
    }
    return 0;
}
}  // namespace n0029ecf0
#undef QCOPY

// 0029edb8 (was src/anon/batch_w1588.cpp)
namespace n0029edb8 {
void* func_00103570(void) asm("func_00103570");
void* func_001063c0(u32, void*) asm("func_001063c0");
void func_002fde18(void*, s32, u32) asm("func_002fde18");
extern void* D_0035f5d0 asm("D_0035f5d0");
/*TARGET 0029edb8*/
void func_0029edb8(void) asm("func_0029edb8");
void func_0029edb8(void) {  // alloc_global_obj
    D_0035f5d0 = func_001063c0(20, func_00103570());
    func_002fde18(D_0035f5d0, 0, 20);
}
}  // namespace n0029edb8

// 0029edf8 (was src/anon/batch_w1588.cpp)
namespace n0029edf8 {
void func_00106420(void*) asm("func_00106420");
extern void* D_0035f5d0 asm("D_0035f5d0");
/*TARGET 0029edf8*/
// 0x002a9570: definition moved into src/anon/unit_002a92a0.cpp

void func_0029edf8(void) asm("func_0029edf8");
// 0x002a9570: definition moved into src/anon/unit_002a92a0.cpp

void func_0029edf8(void) {  // release_global_obj
    if (D_0035f5d0) {
        func_00106420(D_0035f5d0);
        D_0035f5d0 = 0;
    }
}
}  // namespace n0029edf8

// 0029ee30 (was src/anon/misc_2.cpp)
namespace n0029ee30 {
/*TARGET 0029ee30*/
void func_0029ee30(void* self) asm("_Z13func_0029ee30Pv");
void func_0029ee30(void* self) {}
}  // namespace n0029ee30

// 0029ee38 (was src/anon/tiny_auto80_queue.cpp)
namespace n0029ee38 {
u32 func_00274ac8(...) asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
u32 func_00287bc0(...) asm("func_00287bc0");
/*TARGET 0029ee38*/
void func_0029ee38() asm("_Z13func_0029ee38v");
void func_0029ee38() {
    if ((u32)(func_00287bc0() - 24u) < 2u) {
        func_00274ac8();
    }
}
}  // namespace n0029ee38

// 0029ee68 (was whole asm src/anon/asm_0029ee68.s; Jiminy list page init, up to 10 rows)
// Natural shapes that mattered: one `n` for the row count and the scroll-bar count (if/else clamps),
// `id` re-read before the loop with `id + 1` in the loop, `i * step` and `&cursor[i]` left to the
// strength reducer, and the second table row taken once into a local before the loop.
namespace n0029ee68 {
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f200 asm("D_0035f200");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f214 asm("D_0035f214");
extern s32 D_0035f3d4 asm("D_0035f3d4");
struct RD { s8 x0; s8 x1; s8 x2; s8 x3; u16 x4; s8 items[1]; };
extern RD* D_0035f5d0 asm("D_0035f5d0");
struct Lay { u8 pad[40]; s32 img; };
struct Obj { u8 pad[408]; s32 x198; u8 pad2[8]; u32 x1a4; u8 pad3[4]; s32 x1ac; s32 x1b0; void* x1b4; };
struct Cur { u8 pad[408]; };
void setOffsetPos(void*, s32, s32) asm("func_00138c68");
void reset_alpha(void*) asm("func_001395f8");
void obj_xyoff(void*) asm("func_00139620");
s32 yi_img(s32, s32) asm("func_00236ca8");
s32 yi_cr(void*) asm("func_0023aa78");
s32 yi_unit(void*, s32) asm("func_0023c4b8");
Lay* lay_get(s32) asm("func_0023f1b0");
u8* jm_parent() asm("func_00276348");
s32 jm_curpos(s32) asm("func_00276608");
s32 jm_curtop(s32) asm("func_00276620");
u8* jm_scrbar() asm("func_00276678");
void jm_hide(s32) asm("func_002766b0");
u8* jm_seqtbl() asm("func_002766d0");
void func_00276e78() asm("func_00276e78");
s32 mb_mode() asm("func_00287bc0");
void sel_set(s32) asm("func_00287cc0");
void func_00288d80(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("func_00288d80");
Obj* sel_item(s32, s32) asm("func_002891b8");
void func_002891f0(s32, s32, s32, s32, s32) asm("func_002891f0");
void func_0028af90(s32, s32) asm("func_0028af90");
void func_0028afd0(s32, s32) asm("func_0028afd0");
void func_0028b218(s32, s32) asm("func_0028b218");
void func_0028b248(s32, s32) asm("func_0028b248");
void func_0028bae0(s32, s32, s32, s32, u8*, s32, s32, u8*, s32) asm("func_0028bae0");
void pz_cfo(void*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void mc_as(void*, void*) asm("func_0028dcc0");
s32 func_0028f930(s32) asm("func_0028f930");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void func_0029fbf0() asm("func_0029fbf0");
void func_0029fcb0() asm("func_0029fcb0");
void func_002a03a0() asm("func_002a03a0");
void func_002a03d0() asm("func_002a03d0");
/*TARGET 0029ee68*/
void func_0029ee68(void) asm("func_0029ee68");
void func_0029ee68(void) {
    s16 tab[2][4];
    s32 step;
    u8* w2;
    s32 id;
    s32 n;
    s32 i;

    u8* cam = jm_parent();
    u8* w = jm_seqtbl();
    func_0029fbf0();
    if (func_0028f930(0) == 0) {
        func_0028f4d8(0, -1, 0);
    }
    for (i = 0; i < 2; i++) {
        for (s32 j = 0; j < 4; j++) {
            tab[i][j] = 2;
        }
    }
    s16* r1 = tab[1];
    w2 = w + 0x4C8;
    id = D_0035f3d4 - 1;
    func_00276e78();
    pz_cfo(w, id, D_0035f14c, D_0035f148, D_0035f210, 90, -1, 0);
    obj_xyoff(w);
    mc_as(w, cam);
    pz_cfo(w2, id, D_0035f14c, D_0035f148, D_0035f210, 95, -1, 0);
    obj_xyoff(w2);
    mc_as(w2, cam);
    step = yi_cr(w + 0x18);
    s32 t = D_0035f5d0->x0;
    if (t < 10) n = t; else n = 10;
    id = D_0035f3d4;
    for (i = 0; i < n; i++) {
        func_00288d80(D_0035f200, i, D_0035f14c, D_0035f148, D_0035f210, -1, tab[0], r1);
        Obj* o = sel_item(D_0035f200, i);
        obj_xyoff(o);
        mc_as(o, w);
        setOffsetPos(o, 0, i * step);
        o->x1ac = 3;
        u32 bf = 3u << 29;
        bf |= 8;
        o->x1a4 = bf;
        reset_alpha(o);
        Cur* c = (Cur*)(w + 0xA998) + i;
        pz_cfo(c, id + 1, D_0035f14c, D_0035f148, D_0035f210, 2, -1, 0);
        mc_as(c, o);
    }
    s32 cnt = D_0035f5d0->x0;
    func_002891f0(D_0035f200, jm_curpos(mb_mode()), 0, -1, -1);
    func_0028af90(D_0035f200, cnt);
    func_0028afd0(D_0035f200, jm_curtop(mb_mode()));
    if (cnt >= 2) {
        func_0028b218(D_0035f200, 1);
        func_0028b248(D_0035f200, 10);
    }
    id = D_0035f3d4;
    if (cnt > 10) n = cnt; else n = 10;
    s32 a = yi_unit(lay_get(D_0035f210), D_0035f14c);
    s32 b = yi_img(lay_get(D_0035f210)->img, D_0035f148);
    func_0028bae0(D_0035f214, id, a, b, jm_scrbar(), n, 10, w2, 0);
    func_0029fcb0();
    func_002a03d0();
    func_002a03a0();
    jm_hide(1);
    sel_set(0);
}
}  // namespace n0029ee68
