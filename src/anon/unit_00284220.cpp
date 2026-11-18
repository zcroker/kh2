// Linked unit 0x00284088-0x00285070 (0x284088 was whole asm; one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/cmenu_newflg.hpp"
#include "../tozawa/cmenu_slbase.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/cmenu_selector.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tz/ui_accessors.hpp"
#include "../tozawa/cmenu_item.hpp"

// 00284088 (was whole asm, src/anon/asm_00284088.s)
// Init of the ending menu. Plain C++ with real classes: class operator new (menu heap through a
// virtual Alloc), inline constructors calling the out-of-line ones, and `D_x = new T;` statements
// (same idiom as 0x253ba8).
namespace n00284088 {
struct Heap4088 { virtual void* Alloc(u32 size, void* ra); };
struct Sys4088 { u8 pad[20]; Heap4088* heap; };
extern Sys4088* D_00347f80 asm("D_00347f80");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
void func_00287b18(s32, s32) asm("func_00287b18");
s32 func_002887c8(void) asm("func_002887c8");
void func_002ba848(s32) asm("func_002ba848");
void func_00136a18(void) asm("func_00136a18");
void set_flag(void) asm("_ZN2YS13TEST_PROGRESS8set_flagEi");
void func_00102ff0(s32) asm("func_00102ff0");
void func_0023f800(void*) asm("func_0023f800");
void func_00323978(void*) asm("func_00323978");
void func_0028d140(void*) asm("func_0028d140");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void* func_00288be8(u32) asm("func_00288be8");
void func_002889f0(void*, s32, s32) asm("func_002889f0");
void func_00239700(void*) asm("func_00239700");
s32 func_00103570(void) asm("func_00103570");
void* func_001063c0(u32, s32) asm("func_001063c0");
struct Th4088 { s32 f0; s32 f4; };
Th4088* func_00103eb0(void) asm("func_00103eb0");
void func_00102818(s32, s32, s32, void (*)(void), s32) asm("func_00102818");
void func_00284738(void) asm("_Z13func_00284738j");

struct MenuObj {
    static void* operator new(u32 size) { return D_00347f80->heap->Alloc(size, 0); }
};
struct Lay28 { u8 b[28]; Lay28() { func_0023f800(this); } static void* operator new(u32 n, s32 sys) { return func_001063c0(n, sys); } };
struct Lay8360 { u8 b[8360]; Lay8360() { func_00323978(this); } static void* operator new(u32 n, s32 sys) { return func_001063c0(n, sys); } };
struct Seq408 : MenuObj {
    void* vt; u8 pad4[8]; s32 f12; u8 pad16[8]; u8 seq[384];
    Seq408() { f12 = 0; vt = D_00347e60; func_00239700(seq); }
};
struct Seq436 : Seq408 {
    s32 f408; u8 pad412[24];
    Seq436() { f408 = 0; vt = D_00347e40; }
};
struct Obj56 { u8 b[56]; Obj56(s32 a, s32 c) { func_002889f0(this, a, c); } static void* operator new(u32 n) { return func_00288be8(n); } };
struct Obj444 : MenuObj { u8 b[444]; Obj444() { func_0028d140(this); } };

extern s32 D_0035f2c0 asm("D_0035f2c0");
extern Lay28* D_0035f2c4 asm("D_0035f2c4");
extern s32 D_0035f2c8 asm("D_0035f2c8");
extern Lay8360* D_0035f2cc asm("D_0035f2cc");
extern u8 D_0035f2d0 asm("D_0035f2d0");
extern s32 D_0035f2d4 asm("D_0035f2d4");
extern Seq436* D_0035f2d8 asm("D_0035f2d8");
extern Obj56* D_0035f2dc asm("D_0035f2dc");
extern Obj444* D_0035f2e0 asm("D_0035f2e0");

void func_00284088(void) asm("func_00284088");
void func_00284088(void) {
    func_00287b18(4, 3);
    if (!func_002887c8()) {
        func_002ba848(960);
        func_00136a18();
        D_0035f2c0 = 0;
        set_flag();
        func_00102ff0(1);
    }
    D_0035f2c4 = new (func_00103570()) Lay28;
    D_0035f2c8 = 0;
    D_0035f2cc = new (func_00103570()) Lay8360;
    D_0035f2d0 = 0;
    D_0035f2d8 = new Seq436;
    D_0035f2dc = new Obj56(2, 0);
    D_0035f2e0 = new Obj444;
    D_0035f2d4 = 0;
    func_00287bd0(0, 0);
    func_00102818(func_00103eb0()->f4, 0, 2000, func_00284738, 4096);
}
}  // namespace n00284088

// 00284220 (was src/anon/perm_00284220.cpp)
namespace n00284220 {
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef void (*W1572_VFn)(void *);
typedef struct W1572_VObj
{
  W1572_VFn *vt;
} W1572_VObj;
extern W1572_VObj *D_0035f2c4 asm("D_0035f2c4");
extern W1572_VObj *D_0035f2c8 asm("D_0035f2c8");
extern u8 *D_0035f2cc asm("D_0035f2cc");
extern s32 D_0035f2d4 asm("D_0035f2d4");
extern W1572_VObj *D_0035f2d8 asm("D_0035f2d8");
extern s32 D_0035f2dc asm("D_0035f2dc");
extern W1572_VObj *D_0035f2e0 asm("D_0035f2e0");
extern u8 D_00347e60[] asm("D_00347e60");
void func_00285460(void) asm("func_00285460");
void func_00284ea8(void) asm("func_00284ea8");
void func_0031acc0(void *) asm("func_0031acc0");
void func_00239870(void *) asm("func_00239870");
void func_0031a840(void *) asm("func_0031a840");
void func_00106420(void *) asm("func_00106420");
void func_00288b00(s32) asm("func_00288b00");
void func_00288c20(s32) asm("func_00288c20");
/*TARGET 00284220*/
void func_00284220(void) asm("func_00284220");
void func_00284220(void)
{
  u8 *o;
  W1572_VObj *p;
  W1572_VObj *q;
  s32 h;
  if (o)
  {
    func_00285460();
  }
  else
  {
    func_00285460();
  }
  if (D_0035f2d4 != 1)
  {
    func_00284ea8();
  }
  if (D_0035f2c4)
  {
    D_0035f2c4->vt[1](D_0035f2c4);
    D_0035f2c4 = 0;
  }
  if (D_0035f2c8)
  {
    D_0035f2c8->vt[4](D_0035f2c8);
    D_0035f2c8 = 0;
  }
  o = D_0035f2cc;
  if (o)
  {
    if (o + 4360)
    {
      p = (W1572_VObj *) (o + 7848);
      top1:
      if (((W1572_VObj *) (o + 4360)) == p)
      {
        goto out1;
      }

      p = (W1572_VObj *) (((u8 *) p) - 436);
      p->vt[3](p);
      goto top1;
    }
    out1:
    if (o + 872)
    {
      q = (W1572_VObj *) (o + 4360);
      top2:
      if (((W1572_VObj *) (o + 872)) == q)
      {
        goto out2;
      }

      q = (W1572_VObj *) (((u8 *) q) - 436);
      q->vt[3](q);
      goto top2;
    }

    out2:
    func_0031acc0(o + 436);

    *((u32 *) o) = (u32) D_00347e60;
    func_00239870(o + 24);
    func_0031a840(o);
    func_00106420(o);
    D_0035f2cc = 0;
  }
  if (D_0035f2d8)
  {
    D_0035f2d8->vt[4](D_0035f2d8);
    D_0035f2d8 = 0;
  }
  h = D_0035f2dc;
  if (h)
  {
    func_00288b00(h);
    func_00288c20(h);
    D_0035f2dc = 0;
  }
  if (D_0035f2e0)
  {
    D_0035f2e0->vt[4](D_0035f2e0);
    D_0035f2e0 = 0;
  }
}
}  // namespace n00284220

// 002843c0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002843c0 {
u32 func_002843e8(...) asm("func_002843e8");
u32 func_00284538(...) asm("func_00284538");
/*TARGET 002843c0*/
void func_002843c0(void) asm("_Z13func_002843c0v");
void func_002843c0(void) {
    if (func_00284538() != 0u) {
        func_002843e8();
    }
}
}  // namespace n002843c0

// 002843e8 (was src/anon/batch_w269.cpp)
namespace n002843e8 {
typedef void (*VF269)(u8*);
#define VCALL269(p) ((*(VF269*)(*(u8**)(p) + 20))(p))
extern u8* D_0035f2c8 asm("D_0035f2c8");
extern u8* D_0035f2cc asm("D_0035f2cc");
extern u8* D_0035f2d8 asm("D_0035f2d8");
extern u8* D_0035f2dc asm("D_0035f2dc");
s32 func_00139d78(u8*) asm("func_00139d78");
void func_00139510(u8*) asm("func_00139510");
s32 func_0028acc8(u8*) asm("func_0028acc8");
void func_0028abe0(u8*) asm("func_0028abe0");
/*TARGET 002843e8*/
void func_002843e8(void) asm("func_002843e8");
void func_002843e8(void) {
    s32 i;
    if (func_00139d78(D_0035f2c8)) VCALL269(D_0035f2c8);
    if (func_00139d78(D_0035f2cc)) func_00139510(D_0035f2cc);
    if (func_00139d78(D_0035f2cc + 436)) func_00139510(D_0035f2cc + 436);
    for (i = 0; i < 8; i++) {
        if (func_00139d78(D_0035f2cc + i * 436 + 872)) VCALL269(D_0035f2cc + i * 436 + 872);
        if (func_00139d78(D_0035f2cc + i * 436 + 4360)) VCALL269(D_0035f2cc + i * 436 + 4360);
    }
    if (func_00139d78(D_0035f2d8)) VCALL269(D_0035f2d8);
    if (func_0028acc8(D_0035f2dc)) func_0028abe0(D_0035f2dc);
}
}  // namespace n002843e8

// 00284538 (was src/anon/batch_w94.cpp)
namespace n00284538 {
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028acc8(void*) asm("func_0028acc8");
extern u8* D_0035f2c8 asm("D_0035f2c8");
extern u8* D_0035f2cc asm("D_0035f2cc");
extern u8* D_0035f2d8 asm("D_0035f2d8");
extern u8* D_0035f2dc asm("D_0035f2dc");
typedef void (*VFn284)(u8*);
#define VCALL20(o) (*(VFn284*)(*(u8**)(o) + 20))(o)
/*TARGET 00284538*/
s32 func_00284538(void) asm("func_00284538");
s32 func_00284538(void) {
    s32 r = func_00139d78(D_0035f2c8);
    if (r) goto out;
    r = func_00139d78(D_0035f2cc);
    if (r) goto out;
    r = func_00139d78(D_0035f2cc + 436);
    if (r) goto out;
    for (s32 i = 0; i < 8; i++) {
        if (func_00139d78(D_0035f2cc + i * 436 + 872)) VCALL20(D_0035f2cc + i * 436 + 872);
        if (func_00139d78(D_0035f2cc + i * 436 + 4360)) VCALL20(D_0035f2cc + i * 436 + 4360);
    }
    if (r) goto out;
    r = func_00139d78(D_0035f2d8);
    if (r) goto out;
    r = func_0028acc8(D_0035f2dc);
out:
    return r;
}
}  // namespace n00284538

// 00284650 (was src/anon/batch_w86.cpp)
namespace n00284650 {
struct Item { u8 p[436]; };
struct Tri { s8 a, b, anim; };
extern void* D_0035f2c8 asm("D_0035f2c8");
extern Item* D_0035f2cc asm("D_0035f2cc");
extern Tri D_00374360[] asm("D_00374360");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_002854c0(void) asm("func_002854c0");
void func_0023f070(void*, s32, s32) asm("func_0023f070");
void func_00138c10(void*, s32) asm("func_00138c10");
/*TARGET 00284650*/
void func_00284650(void) asm("func_00284650");
void func_00284650(void)
{
    func_00139d78(D_0035f2c8);
    func_0023f070(D_0035f2c8, D_00374360[func_002854c0()].anim, -1);
    func_00139d78(&D_0035f2cc[0]);
    func_00138c10(&D_0035f2cc[0], 2);
    func_00139d78(&D_0035f2cc[1]);
    func_00138c10(&D_0035f2cc[1], 8);
    for (s32 i = 0; i < 8; i++) {
        func_00139d78(&D_0035f2cc[i + 2]);
        func_00138c10(&D_0035f2cc[i + 2], 5);
    }
}
}  // namespace n00284650

// 00284738 (was src/anon/auto80_199_queue.cpp)
namespace n00284738 {
// 0x0016fba0: definition moved into src/anon/unit_0016e8f8.cpp

void func_00170888(u32 a0) asm("_Z13func_00170888j");
/*TARGET 00284738*/
void func_00284738(u32 a0) asm("_Z13func_00284738j");
void func_00284738(u32 a0) {
    u32 s0 = a0;

    if (func_00170cd0(s0) != 0) {
        func_00170888(s0);
    }

    func_00285418();
    func_00170888(s0);
    func_00102448(s0, 1);
    func_002853b8();
    func_002847e0();

    if (D_0035f2d0 == 0) {
        func_00284e40();
    }

    while (1) {
        func_00236d60();  // clear_64_entries_24
        if (func_00284ef0() != 0) {
            return;
        }
        func_002851e0();
        func_00102448(s0, 0);
    }
}
}  // namespace n00284738

// 002847e0 (was src/anon/batch_w1715_nsa.cpp)
namespace n002847e0 {
struct W1715_Sub { u8 pad[0xb8]; u32 flags; };
struct W1715_Sprite {
    u8 pad0[0x18];
    W1715_Sub sub;          /* 0x18 */
    u8 pad1[0x195 - 0x18 - 0xbc];
    u8 visible;             /* 0x195 */
    u8 pad2[2];
    s32 text;               /* 0x198 */
    u8 pad3[0x1b0 - 0x19c];
    s32 mode;               /* 0x1b0 */
};
struct W1715_Menu {
    W1715_Sprite title;         /* 0x0 */
    W1715_Sprite frame;         /* 0x1b4 */
    W1715_Sprite icon[8];       /* 0x368 */
    W1715_Sprite label[8];      /* 0x1108 */
    char buf[8][64];            /* 0x1ea8: text lines */
};
struct W1715_Pos { s8 x; s8 pad; s8 y; };
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern void* D_0035f2c4 asm("D_0035f2c4");
extern u8* D_0035f2c8 asm("D_0035f2c8");
extern W1715_Menu* D_0035f2cc asm("D_0035f2cc");
extern u8 D_0035f2d0 asm("D_0035f2d0");
extern W1715_Pos D_00374360[] asm("D_00374360");
extern u16 D_00374388[] asm("D_00374388");
extern u16 D_00374398[] asm("D_00374398");
extern u16 D_003743a0[] asm("D_003743a0");
extern u8 D_003743b0[] asm("D_003743b0");
extern u16 D_003743b8[] asm("D_003743b8");
extern char D_00374330[] asm("D_00374330");
extern char D_00374338[] asm("D_00374338");
extern char D_00374340[] asm("D_00374340");
void func_002854b0(void) asm("func_002854b0");
u8* func_0023ee30(u32) asm("func_0023ee30");
void func_0031a838(u8*) asm("func_0031a838");
void func_002369a0(u8*) asm("func_002369a0");
void func_0023c008(u8*) asm("func_0023c008");
s32 func_002854c0(void) asm("func_002854c0");
s32 func_0023f948(void*, s32) asm("func_0023f948");
s32 func_0023f908(void*, s32) asm("func_0023f908");
void func_0028d7f0(u8*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d7f0");
void func_0023ef50(u8*) asm("func_0023ef50");
void func_0028d980(W1715_Sprite*, s32, s32, s32, u8*, s32, s32, s32, s32) asm("func_0028d980");
void func_00139620(W1715_Sprite*) asm("func_00139620");
void func_001395f8(W1715_Sprite*) asm("func_001395f8");
s32 func_00192048(u32) asm("func_00192048");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
s32 func_0023aa78(W1715_Sub*) asm("func_0023aa78");
s32 func_0023aa18(W1715_Sub*) asm("func_0023aa18");
s32 func_0023aa38(W1715_Sub*) asm("func_0023aa38");
void func_00138c68(W1715_Sprite*, s32, s32) asm("func_00138c68");
void func_0028dcc0(W1715_Sprite*, W1715_Sprite*) asm("func_0028dcc0");
u8* func_001058e8(void) asm("func_001058e8");
s32 func_00105868(u8*) asm("func_00105868");
void func_00192c90(s32, char*) asm("func_00192c90");
s32 func_00192c40(s32, char*) asm("func_00192c40");
char* func_00192cc0(char*, const char*, s32) asm("func_00192cc0");
s32 func_00192b30(char*) asm("func_00192b30");
s32 func_00276fd0(void) asm("func_00276fd0");
f32 func_001e09d0(u8*) asm("func_001e09d0");
s32 func_002887c8(void) asm("func_002887c8");
void func_00284650(void) asm("func_00284650");
void func_00288750(void (*)(void)) asm("func_00288750");
static inline void W1715_SetFlag(W1715_Sub* s) { s->flags |= 8; }
/*TARGET 002847e0*/
void func_002847e0(void) asm("func_002847e0");
void func_002847e0(void)
{
    s32 i, n, best, bi;
    s32 off;
    u16* tbl;
    u8* o = func_0023ee30(0xa0);
    *(u8**)o = D_00347f98;
    func_0031a838(o + 12);
    *(u8**)o = D_0035eb98;
    func_002369a0(o + 24);
    func_0023c008(o + 48);
    D_0035f2c8 = o;
    best = func_002854c0();
    s32 a = func_0023f948(D_0035f2c4, 0);
    s32 b = func_0023f908(D_0035f2c4, 0);
    func_0028d7f0(D_0035f2c8, 30002, 0, 0, D_00374360[best].x, D_00374360[best].y, a, b, 0);
    func_0023ef50(D_0035f2c8);

    W1715_Sprite* s = &D_0035f2cc->title;
    func_0028d980(s, 30011, 1, 1, D_0035f2c8, 1, 2, -1, 0);
    func_00139620(s);
    func_001395f8(s);
    s->mode = 2;
    s->text = func_00192048(0xcc24);
    s->visible = 1;
    W1715_SetFlag(&s->sub);

    s = &D_0035f2cc->frame;
    func_0028d980(s, 30011, 1, 1, D_0035f2c8, 7, 8, -1, 0);
    func_00139620(s);
    func_001395f8(s);
    s->mode = 2;
    s->text = func_00192048(0xcebf);
    s->visible = 1;
    W1715_SetFlag(&s->sub);

    func_002fde18(D_0035f2cc->buf, 0, 0x200);
    tbl = D_00374388;
    off = 0;
    for (i = 0; i < 8; i++) {
        s = (W1715_Sprite*)((u8*)D_0035f2cc->icon + off);
        func_0028d980(s, 30011, 1, 1, D_0035f2c8, 4, 5, -1, 0);
        s32 h = func_0023aa78(&s->sub);
        s32 x = func_0023aa18(&s->sub);
        s32 y = func_0023aa38(&s->sub);
        func_00138c68(s, 0, h * i);
        func_00139620(s);
        func_001395f8(s);
        s->text = func_00192048(*tbl++);
        s->visible = 1;
        W1715_SetFlag(&s->sub);

        s = (W1715_Sprite*)((u8*)D_0035f2cc->label + off);
        func_0028d980(s, 30012, 1, 1, D_0035f2c8, 10, -1, -1, 0);
        func_0028dcc0(s, (W1715_Sprite*)((u8*)D_0035f2cc->icon + off));
        off += sizeof(W1715_Sprite);
        func_00139620(s);
        func_001395f8(s);
        s->mode = 1;
        func_00138c68(s, x, y);
        s->text = (s32)D_0035f2cc->buf[i];
        s->visible = 1;
        W1715_SetFlag(&s->sub);
    }

    u8* sv = func_001058e8();
    u16* st = (u16*)(sv + 0x3fce);
    char* p = D_0035f2cc->buf[0];
    n = func_00105868(func_001058e8());
    func_00192c90(func_00192048(D_00374398[n]), p);
    p = D_0035f2cc->buf[1];
    func_00192cc0(p, D_00374330, func_00276fd0());
    p = D_0035f2cc->buf[2];
    func_00192cc0(p, D_00374330, (s32)func_001e09d0(func_001058e8() + 0x100e0));
    p = D_0035f2cc->buf[3];
    n = func_00192b30(func_00192cc0(p, D_00374338, st[1]));
    func_00192c90(func_00192048(0xcc20), p + n);
    p = D_0035f2cc->buf[4];
    n = func_00192b30(func_00192cc0(p, D_00374338, *(u16*)(func_001058e8() + 0x3db2)));
    func_00192c90(func_00192048(0xcc20), p + n);

    best = -1;
    bi = 0;
    p = D_0035f2cc->buf[5];
    for (i = 1; i < 7; i++) {
        if (best < st[3 + i]) {
            best = st[3 + i];
            bi = i;
        }
    }
    n = func_00192c40(func_00192048(D_003743a0[bi]), p);
    n += func_00192b30(func_00192cc0(p + n, D_00374340, best));
    func_00192c90(func_00192048(0xcc20), p + n);

    p = D_0035f2cc->buf[6];
    n = func_00192b30(func_00192cc0(p, D_00374338, st[9]));
    func_00192c90(func_00192048(0xcc20), p + n);

    best = -1;
    bi = 0;
    p = D_0035f2cc->buf[7];
    i = 0;
    do {
        u8 c = D_003743b0[i];
        if (best < st[10 + c]) {
            best = st[10 + c];
            bi = c;
        }
    } while (++i < 4);
    n = func_00192c40(func_00192048(D_003743b8[bi]), p);
    n += func_00192b30(func_00192cc0(p + n, D_00374340, best));
    func_00192c90(func_00192048(0xcc20), p + n);

    if (func_002887c8()) {
        func_00284650();
        D_0035f2d0 = 1;
        func_00288750(func_002854b0);
    }
}
}  // namespace n002847e0

// 00284e40 (was src/anon/batch_w44.cpp)
namespace n00284e40 {
typedef u32 (*AllocFn)(void*, u32, s32);
void* func_00103580(void) asm("func_00103580");
void func_002bd788(u32) asm("func_002bd788");
void func_002bd730(void*, s32, s32, s32) asm("func_002bd730");
// 0x00269ef8: definition moved into src/anon/unit_00269a60.cpp

extern u32 D_0035f2c0 asm("D_0035f2c0");
extern u8 D_00374348[] asm("D_00374348");
/*TARGET 00284e40*/
void func_00284e40(void) asm("func_00284e40");
void func_00284e40(void) {
    void** o = (void**)func_00103580();
    u32 v = (**(AllocFn**)o)(o, 0x48800, 0);
    u32 a = (v + 63) & ~63;
    D_0035f2c0 = v;
    func_002bd788(a);
    func_002bd730(D_00374348, 16383, 0, 0);
}
}  // namespace n00284e40

// 00284ea8 (was src/anon/batch_w25.cpp)
namespace n00284ea8 {
struct VObj { void (**vt)(...); };
typedef void (*VFn)(void*, void*);
extern u32 D_0035f2c0 asm("D_0035f2c0");
void func_002bd7d8(void) asm("func_002bd7d8");
VObj* func_00103580(void) asm("func_00103580");
/*TARGET 00284ea8*/
void func_00284ea8(void) asm("func_00284ea8");
void func_00284ea8(void) {
    func_002bd7d8();
    VObj* o = func_00103580();
    ((VFn)o->vt[1])(o, (void*)D_0035f2c0);
    D_0035f2c0 = 0;
}
}  // namespace n00284ea8

// 00284ef0 (was src/anon/batch_w87.cpp)
namespace n00284ef0 {
// ---- 0x284ef0 ----
void func_00287d68(void) asm("func_00287d68");
// copy_globals_3words
s32 func_00287db0(void) asm("func_00287db0");
extern s32 D_0035f2d4 asm("D_0035f2d4");
extern u8 D_0035f2d0 asm("D_0035f2d0");
s32 func_00284538(void) asm("func_00284538");
u8* func_0014aba8(void) asm("func_0014aba8");
void func_002843e8(void) asm("func_002843e8");
void func_001039f8(void) asm("func_001039f8");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00285070(void) asm("func_00285070");
void func_00284fd8(void) asm("func_00284fd8");
/*TARGET 00284ef0*/
s32 func_00284ef0(void) asm("func_00284ef0");
s32 func_00284ef0(void) {
    func_00287d68();  // copy_globals_3words
    if (func_00287db0()) {
        if (D_0035f2d4 == 2 && func_00284538()) {
            if ((*(s32*)(func_0014aba8() + 252) ^ 4) == 0) func_002843e8();
            return 0;
        }
        if (func_00284538()) return 0;
        func_001039f8();
        return 1;
    }
    if (D_0035f2d0) return 0;
    switch (func_00287bc0()) {
    case 0: func_00284fd8(); break;
    case 1: case 2: func_00285070(); break;
    }
    return 0;
}
}  // namespace n00284ef0

// 00284fd8 (was src/anon/batch_w64.cpp)
namespace n00284fd8 {
// 0x002630d8: definition moved into src/anon/unit_0025f6b8.cpp

// ---------------------------------------------------------------------------
u8* func_00167f18(s32) asm("func_00167f18");
extern u8* D_0035f2cc asm("D_0035f2cc");
void func_00242618(s32, s32) asm("func_00242618");
void func_002854d8(s32, s32) asm("func_002854d8");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 00284fd8*/
void func_00284fd8(void) asm("func_00284fd8");
void func_00284fd8(void) {
    u8* v = func_00167f18(0);
    if (*(s32*)(D_0035f2cc + 824) != 8) return;
    u64 fl = *(u64*)(v + 8);
    if (fl & 4) {
        func_00242618(8, 1);
        func_002854d8(0xceca, 0);
        func_00287bd0(1, 0);
        func_00287cc0(0);
    } else if (fl & 8) {
        func_00242618(8, 1);
        func_002854d8(0xcecb, 1);
        func_00287bd0(2, 0);
        func_00287cc0(0);
    }
}
}  // namespace n00284fd8

