// Linked unit 0x0022d358-0x002302c0 (one namespace per old matched source; class methods in their own namespace).
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
#include "../sasa/event.hpp"
#include "../tozawa/menu_sound.hpp"

// 0022d358 (was src/anon/tiny_auto80_queue.cpp)
namespace n0022d358 {
extern u8  D_00360000 asm("D_00360000");
void sa__EVENT__fixAlloc(...) asm("sa__EVENT__fixAlloc");
// 0x0013f330: definition moved into src/anon/unit_0013ef70.cpp

extern "C" u32 func_00102448(...) asm("func_00102448");
// 0022d238: moved to src/sasa/event_layout.cpp (linked unit)

extern "C" u32 func_001977a0(...) asm("func_001977a0");
/*TARGET 0022d358*/
void func_0022d358(u32 a0) asm("_Z13func_0022d358j");
void func_0022d358(u32 a0) {
    u32 s0 = a0;
    while (true) {
        if (func_001977a0() == 0) {
            break;
        }
        func_00102448(s0, 0);
    }
    *(u8*)((u8*)&D_00360000 - 8636u) = 1;
    sa__EVENT__fixAlloc();
}
}  // namespace n0022d358

// 0022d3a8 (was src/anon/tiny_more2.cpp)
namespace n0022d3a8 {
extern u32 D_0035de40 asm("D_0035de40");
/*TARGET 0022d3a8*/
void func_0022d3a8(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0022d3a8jjjj");
void func_0022d3a8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; s32 v=*(s16*)((u32)a0 + (4)); D_0035de40=(u32)v; }
}  // namespace n0022d3a8

// 0022d3b8 (was src/anon/tiny_more2.cpp)
namespace n0022d3b8 {
extern u32 D_0035de28 asm("D_0035de28");
/*TARGET 0022d3b8*/
void func_0022d3b8(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0022d3b8jjjj");
void func_0022d3b8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; s32 v=*(s16*)((u32)a0 + (4)); D_0035de28=(u32)v; }
}  // namespace n0022d3b8

// 0022d3c8 (was src/anon/auto80_199_queue.cpp)
namespace n0022d3c8 {
/*TARGET 0022d3c8*/
// 0022d288: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022d3c8(u32 a0) asm("_Z13func_0022d3c8j");
// 0022d288: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022d3c8(u32 a0) {
    u32 s17 = a0;
    f32 f0;
    f32 f12;
    f32 f13;
    f32 f14;
    f32 f20;

    if (sa__EVENT__checkStart(*(u16*)(a0 + 4)) != 0) {
        return;
    }
    if (sa__EVENT__isJumpMode(*(u16*)(s17 + 4)) != 0) {  // flag_query_by_index
        return;
    }
    f0 = func_00227c78(s17 + 8);
    f20 = f0;
    f13 = f0;
    f14 = (f32)(*(u16*)(s17 + 6));
    f12 = D_0035de48;
    func_0014cde0(f12, f13, f14);
    D_0035de48 = f20;
}
}  // namespace n0022d3c8

// 0022d440 (was src/anon/batch_w1781_nsa.cpp)
namespace n0022d440 {
// 00228918: moved to src/anon/unit_00228618.cpp (linked unit)

struct W1781VObj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10();
};
struct W1781Ent40 { s32 a; s32 b; W1781VObj* obj; u8 pad[28]; };
extern W1781Ent40* D_0035dcfc asm("D_0035dcfc");
void YS__OBJ__is_valid(W1781VObj*) asm("YS__OBJ__is_valid");
void sa__EVENT__clearMotionCtrlWk(s32) asm("sa__EVENT__clearMotionCtrlWk");
/*TARGET 0022d440*/
void func_0022d440(void) asm("func_0022d440");
void func_0022d440(void) {
    if (D_0035dcfc != 0) {
        for (s32 i = 0; i < 96; i++) {
            if (D_0035dcfc[i].obj != 0) {
                YS__OBJ__is_valid(D_0035dcfc[i].obj);
                D_0035dcfc[i].obj->v10();
                D_0035dcfc[i].obj = 0;
                sa__EVENT__clearMotionCtrlWk(D_0035dcfc[i].b);
            }
        }
    }
}
}  // namespace n0022d440

// 0022d4e8 (was src/anon/batch_w238.cpp)
namespace n0022d4e8 {
extern void func_0022f5a0(void*, s32, s32) asm("func_0022f5a0");
extern char* D_0035dcfc asm("D_0035dcfc");
struct EE_22d4e8 { s32 a; s32 b; char pad[14]; u8 f; char z[17]; };
/*TARGET 0022d4e8*/
void sa__EVENT__reloadActor(char* a) asm("sa__EVENT__reloadActor");
void sa__EVENT__reloadActor(char* a) {
    if (D_0035dcfc) {
        for (s32 i = 0; i < 96; i++) {
            EE_22d4e8* e = (EE_22d4e8*)((u32)(i * 40) + (u32)D_0035dcfc);
            s32 x = e->a;
            if (x == -1) continue;
            s32 y = e->b;
            if (a[y + 6] != 0 && e->f == 1)
                func_0022f5a0((char*)e + 23, x, y);
        }
    }
}
}  // namespace n0022d4e8

// 0022d598 (was src/anon/auto80_199_queue.cpp)
namespace n0022d598 {
// 0x0016fba0: definition moved into src/anon/unit_0016e8f8.cpp

void func_00170888(u32 a0) asm("_Z13func_00170888j");
/*TARGET 0022d598*/
void func_0022d598(u32 a0, u32 a1) asm("_Z13func_0022d598jj");
void func_0022d598(u32 a0, u32 a1) {
    u32 s16v = a0;
    u32 s17 = a1;

    if (sa__EVENT__checkStart(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    func_0022d440();
    sa__EVENT__waitMessageOn();
    func_00102448(s17, 2);
    func_00170320(-200);
    sa__EVENT__reloadActor(s16v);
    func_00170888(s17);
    func_00225a20();
}
}  // namespace n0022d598

// 0022d618 (was src/anon/auto80_199_queue.cpp)
namespace n0022d618 {
/*TARGET 0022d618*/
void func_0022d618(u32 a0) asm("_Z13func_0022d618j");
void func_0022d618(u32 a0) {
    u32 s16v = a0;
    s32 a4;

    if (sa__EVENT__checkStart(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (*(s8*)(s16v + 7) == 0) {
        func_0015ee10(*(s8*)(s16v + 6));
        return;
    }
    a4 = *(s8*)(s16v + 6);
    if (func_0015f718(a4) != 0) {  // test_bit_global64
        return;
    }
    func_0015ee90(*(s8*)(s16v + 6));
}
}  // namespace n0022d618

// 0022d688 (was src/anon/tiny_auto80_queue.cpp)
namespace n0022d688 {
extern u8  D_00360000 asm("D_00360000");
u32 func_0014abb8(...) asm("func_0014abb8");
// get_data_359840
extern "C" u32 func_0014abc8(...) asm("func_0014abc8");
u32 func_0014aa80(...) asm("func_0014aa80");
/*TARGET 0022d688*/
void func_0022d688() asm("_Z13func_0022d688v");
void func_0022d688() {
    u32 v0 = func_0014abb8();  // get_data_359840
    func_0014aa80(v0, 1, 0);
    v0 = func_0014abc8();  // get_data_359950
    func_0014aa80(v0, 1, 0);
    *(u8*)((u8*)&D_00360000 - 7336u) = 0;
}
}  // namespace n0022d688

// 0022d6d8 (was src/sasa/event.cpp)
namespace sa { // method 0022d6d8
extern u8 D_00360000 asm("D_00360000");
u32 func_0014abb8(...) asm("func_0014abb8");
// get_data_359840
extern "C" u32 func_0014abc8(...) asm("func_0014abc8");
// get_data_359950
extern "C" void func_0014aa58(...) asm("func_0014aa58");
/*TARGET 0022d6d8*/
void EVENT::wide_on() {
    u32 v0 = func_0014abb8();  // get_data_359840
    func_0014aa58(v0, 1, 0);
    v0 = func_0014abc8();  // get_data_359950
    func_0014aa58(v0, 1, 0);
    *(u8*)((u8*)&D_00360000 - 7336u) = 1;
}
}  // sa

// 0022d728 (was src/anon/tiny_auto80_queue.cpp)
namespace n0022d728 {
u32 sa__EVENT__checkStart(...) asm("sa__EVENT__checkStart");
void func_0022d688() asm("_Z13func_0022d688v");
void func_0022d6d8() asm("_ZN2sa5EVENT7wide_onEv");
/*TARGET 0022d728*/
void func_0022d728(u8* a0) asm("_Z13func_0022d728Ph");
void func_0022d728(u8* a0) {
    u8* s0 = a0;
    if (sa__EVENT__checkStart((u32)*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (*(s16*)(s0 + 6) == 0) {
        func_0022d688();
    } else {
        func_0022d6d8();
    }
}
}  // namespace n0022d728

// 0022d778 (was src/anon/tiny_auto80_queue.cpp)
namespace n0022d778 {
void func_00143298(...) asm("func_00143298");
void func_001432a8(...) asm("func_001432a8");
u32 sa__EVENT__checkStart(...) asm("sa__EVENT__checkStart");
/*TARGET 0022d778*/
void sa__EVENT__set_bin_wall_clip(u8* a0) asm("_Z28sa__EVENT__set_bin_wall_clipPh");
void sa__EVENT__set_bin_wall_clip(u8* a0) {
    u8* s0 = a0;
    if (sa__EVENT__checkStart((u32)*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (*(s16*)(s0 + 6) == 0) {
        func_00143298();
    } else {
        func_001432a8();
    }
}
}  // namespace n0022d778

// 0022d7c8 (was src/anon/tiny.cpp)
namespace n0022d7c8 {
/*TARGET 0022d7c8*/
// 0022c9f0: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022d7c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0022d7c8jjjj");
// 0022c9f0: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022d7c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u8*)((u32)b + (-7336)) = (u8)0;
}
}  // namespace n0022d7c8

// 0022d7d8 (was src/anon/tiny.cpp)
namespace n0022d7d8 {
/*TARGET 0022d7d8*/
u32 func_0022d7d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0022d7d8jjjj");
u32 func_0022d7d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-7336)));
}
}  // namespace n0022d7d8

// 0022d7e8 (was src/anon/batch_w19.cpp)
namespace n0022d7e8 {
struct Slot8 { u32 a; s16 b, c; };
extern Slot8 D_01dad9c0[32] asm("D_01dad9c0");
/*TARGET 0022d7e8*/
void func_0022d7e8(void) asm("func_0022d7e8");
void func_0022d7e8(void) {
    s32 i;
    for (i = 0; i < 32; i++) {
        D_01dad9c0[i].a = 0;
        D_01dad9c0[i].b = -1;
        D_01dad9c0[i].c = -1;
    }
}
}  // namespace n0022d7e8

// 0022d820 (was src/anon/batch_w57.cpp)
namespace n0022d820 {
extern void (**D_0032b914)() asm("D_0032b914");
// 001a4e30: moved to src/anon/unit_001a4db0.cpp

// Release every live entry of the 32-slot table.
struct Ent22 { void** obj; u32 x; };
extern Ent22 D_01dad9c0[32] asm("D_01dad9c0");
/*TARGET 0022d820*/
void func_0022d820(void) asm("func_0022d820");
void func_0022d820(void) {
    for (s32 i = 0; i < 32; i++) {
        if (D_01dad9c0[i].obj) {
            (*(void (**)(void*))((u8*)*D_01dad9c0[i].obj + 32))(D_01dad9c0[i].obj);
            D_01dad9c0[i].obj = 0;
        }
    }
}
}  // namespace n0022d820

// 0022d880 (was src/anon/batch_w1835_nsa.cpp)
namespace n0022d880 {
struct W1835VObj;
struct W1835VTbl { u8 pad[0x20]; void (*release)(W1835VObj*); };
struct W1835VObj { W1835VTbl* vt; };
struct W1835Slot { W1835VObj* p; s16 b; s16 a; };
struct W1835Req { u8 pad[4]; s16 id; s16 a; s16 b; s16 mode; };
extern W1835Slot D_01dad9c0[32] asm("D_01dad9c0");
s32 sa__EVENT__checkStart(s16) asm("sa__EVENT__checkStart");
s32 sa__EVENT__isJumpMode(s16) asm("sa__EVENT__isJumpMode");
W1835VObj* func_001050d8(s32) asm("func_001050d8");
void func_001ac8b0(W1835VObj*, s16) asm("func_001ac8b0");
void func_001ac7c8(W1835VObj*, W1835VObj*) asm("func_001ac7c8");
/*TARGET 0022d880*/
// 001a7a48: moved to src/yasui/libys/bg.cpp

void func_0022d880(W1835Req* a) asm("func_0022d880");
// 001a7a48: moved to src/yasui/libys/bg.cpp

void func_0022d880(W1835Req* a) {
    s32 i;
    if (sa__EVENT__checkStart(a->id) != 0) return;
    if (sa__EVENT__isJumpMode(a->id) != 0) return;
    if (a->mode == 0) {
        for (i = 0; i < 32; i++) {
            W1835Slot* s = &D_01dad9c0[i];
            if (s->p == 0) {
                s16 v = a->b;
                W1835VObj* o = func_001050d8(0x84);
                func_001ac8b0(o, v);
                func_001ac7c8(func_001050d8(0x1c), o);
                s->p = o;
                s->a = a->a;
                s->b = a->b;
                return;
            }
        }
    } else {
        for (i = 0; i < 32; i++) {
            W1835Slot* s = &D_01dad9c0[i];
            if (s->p != 0 && s->a == a->a && s->b == a->b) {
                s->p->vt->release(s->p);
                s->p = 0;
                return;
            }
        }
    }
}
}  // namespace n0022d880

// 0022d9b0 (was src/anon/perm_0022d9b0.cpp)
namespace n0022d9b0 {
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
struct WinSlot
{
  void **obj;
  s16 id;
  s16 group;
};
extern WinSlot D_01dad9c0[32] asm("D_01dad9c0");
struct WinReq
{
  u32 _0;
  s16 idx;
  s16 group;
  s16 id;
  s16 mode;
  s16 kind;
};
void *W1688_area_alloc(u32) asm("_ZN4AREA5AllocEj");
void W1688_obj2d_ctor(void *self, void *win) asm("_ZN2YS12WINDOW_OBJ2DC1EPNS_6WINDOWE");
void func_00102448(u32, s32) asm("_ZN2Tz9TaskYieldEz");
void func_001ad0f8(void *, s32, s32) asm("func_001ad0f8");
void func_001ad330(void *, s32) asm("func_001ad330");
void sa__EVENT__waitMessageOn(void) asm("sa__EVENT__waitMessageOn");
void func_00225a20(void) asm("func_00225a20");
s32 sa__EVENT__isJumpMode(s32) asm("sa__EVENT__isJumpMode");
s32 sa__EVENT__checkStart(s32) asm("sa__EVENT__checkStart");
inline static bool W1688_busy(void **o)
{
  return (*((s32 *) (((u8 *) o) + 0x70))) != 3;
}
/*TARGET 0022d9b0*/
void func_0022d9b0(WinReq *req, u32 task) asm("func_0022d9b0");
void func_0022d9b0(WinReq *req, u32 task)
{
  s32 i;
  if (sa__EVENT__checkStart(req->idx) != 0)
  {
    return;
  }
  if (sa__EVENT__isJumpMode(req->idx) != 0)
  {
    return;
  }
  i = 0;
  switch (req->mode)
  {
    case 0:
      for (; __builtin_expect(i < 32, 0); i++)
    {
      if (D_01dad9c0[i].obj == 0)
      {
        void *w;
        s16 id;
        switch (req->kind)
        {
          case 0:
            id = req->id;
            w = W1688_area_alloc(0xb6c);
            func_001ad0f8(w, id, 0);
            W1688_obj2d_ctor(W1688_area_alloc(0x1c), w);
            D_01dad9c0[i].obj = (void **) w;
            break;

          case 1:
            if (req->group)
          {
            id = req->id;
            w = W1688_area_alloc(0x1230);
            func_001ad330(w, id);
            W1688_obj2d_ctor(W1688_area_alloc(0x1c), w);
            D_01dad9c0[i].obj = (void **) w;
            break;
          }
          else
          {
            id = req->id;
            w = W1688_area_alloc(0x1230);
            func_001ad330(w, id);
            W1688_obj2d_ctor(W1688_area_alloc(0x1c), w);
            D_01dad9c0[i].obj = (void **) w;
            break;
          }

        }

        D_01dad9c0[i].group = req->group;
        D_01dad9c0[i].id = req->id;
        return;
      }
    }

      break;

    case 1:
    {
      WinSlot *e = D_01dad9c0;
      for (; i < 32; i++, e++)
      {
        if ((e->obj && (e->group == req->group)) && (e->id == req->id))
        {
          (*((void (**)(void *)) (((u8 *) (*e->obj)) + 32)))(e->obj);
          e->obj = 0;
          break;
        }
      }

    }

    case 2:
      for (i = 0; i < 32; i++)
    {
      if ((D_01dad9c0[i].obj && (D_01dad9c0[i].group == req->group)) && (D_01dad9c0[i].id == req->id))
      {
        if (sa__EVENT__isJumpMode(req->idx) != 0)
        {
          return;
        }
        while (W1688_busy(D_01dad9c0[i].obj))
        {
          sa__EVENT__waitMessageOn();
          func_00102448(task, 0);
        }

        func_00225a20();
        return;
      }
    }

      break;

  }

}
}  // namespace n0022d9b0

// 0022dc30 (was gap)
namespace n0022dc30 {
struct E52 { s32 a; s32 id; u8 pad[44]; };
struct E84 { s32 state; u8 pad[8]; s32 id; u8 pad2[68]; };
extern E52* D_0035dcf4 asm("D_0035dcf4");
extern E84* D_0035dcf0 asm("D_0035dcf0");
u32 delChk(E52*) asm("func_0022e110");
void func_002278e0(E84*) asm("func_002278e0");
void func_001024a8(u8*) asm("func_001024a8");
void func_0022dc30(u8* t) asm("func_0022dc30");
void func_0022dc30(u8* t) {
    if (D_0035dcf4 == 0) return;
    for (s32 i = 0; i < 96; i++) {
        if (D_0035dcf4[i].id != -1) {
            if (delChk(&D_0035dcf4[i])) return;
        }
    }
    for (s32 i = 0; i < 128; i++) {
        if (D_0035dcf0[i].id != -1 && D_0035dcf0[i].state == 2) func_002278e0(&D_0035dcf0[i]);
    }
    func_001024a8(t);
}
}  // namespace n0022dc30

// 0022dd40 (was src/anon/batch_w13.cpp)
namespace n0022dd40 {
s32 sa__EVENT__checkStart(s32) asm("sa__EVENT__checkStart");
void func_00102c18(s32, s32, void*) asm("func_00102c18");
void func_0022dc30(void) asm("func_0022dc30");
extern void (*D_0035e380[])(void) asm("D_0035e380");
/*TARGET 0022dd40*/
// 0x001e27c0: definition moved into src/anon/unit_001e0cb8.cpp

void func_0022dd40(u8* p) asm("func_0022dd40");
// 0x001e27c0: definition moved into src/anon/unit_001e0cb8.cpp

void func_0022dd40(u8* p) {
    if (sa__EVENT__checkStart(*(s16*)(p + 4)) == 0) {
        func_00102c18(1, 0x17318, (void*)func_0022dc30);
    }
}
}  // namespace n0022dd40

// 0022dd80 (was src/anon/batch_w1689_nsa.cpp)
namespace n0022dd80 {
struct EffObj { u8 pad[0x230]; void* owner; };
struct EffSlot { s32 w0; s32 w4; EffObj* obj; u8 pad[28]; };
extern EffSlot* D_0035dcfc asm("D_0035dcfc");
struct Res { u8 pad[0x14]; s32 w14; };
struct Ent {
    s32 w0;
    s32 key;
    s16 h8;
    u8 pad_a[2];
    void* eff;
    u8 sub[0x20];
    s16 slot;
};
struct Cmd { u8 pad[4]; s16 h4; u8 p6[2]; s16 h8; s16 ha; s16 hc; s16 type; s16 h10; };
s32 sa__EVENT__checkStart(s32) asm("sa__EVENT__checkStart");
s32 sa__EVENT__isJumpMode(s32) asm("sa__EVENT__isJumpMode");
Ent* func_0022e330(s32) asm("func_0022e330");
s32 func_0022e0a8(Ent*) asm("func_0022e0a8");
Res* func_00227bd8(s32, s32) asm("func_00227bd8");
void YS__OBJ__is_valid(EffObj*) asm("YS__OBJ__is_valid");
void* ryj__PAX__start(void*, s32, s32, s32, s32, EffObj*) asm("ryj__PAX__start");
void func_0022e368(Cmd*) asm("func_0022e368");
void eff_setup_1dddd0(void*, s32) asm("_Z14ryj__PAX__initjjjj");
s32 eff_is_loop(void*) asm("_ZN3ryj6EFFECT7is_loopEv");
void eff_loop_end_kill(void*) asm("_ZN3ryj6EFFECT13loop_end_killEv");
void eff_kill(void*) asm("_ZN3ryj6EFFECT4killEv");
void eff_fadeout_kill(void*, f32) asm("_ZN3ryj6EFFECT12fadeout_killEf");
s32 eff_is_alive(void*) asm("_ZN3ryj6EFFECT8is_aliveEv");
s32 eff_is_active(void*) asm("_ZN3ryj6EFFECT9is_activeEv");
/*TARGET 0022dd80*/
void sa__EVENT__set_effect_seq(Cmd* c) asm("sa__EVENT__set_effect_seq");
void sa__EVENT__set_effect_seq(Cmd* c) {
    if (sa__EVENT__checkStart(c->h4) || sa__EVENT__isJumpMode(c->h4)) return;
    switch (c->type) {
    case 0: {
        Ent* e = func_0022e330(c->h8);
        Res* r = func_00227bd8(e->w0, 2);
        if (e->slot == -1) {
            eff_setup_1dddd0(e->sub, r->w14);
            e->eff = ryj__PAX__start(e->sub, e->h8, 1, 3, 0, 0);
        } else {
            EffSlot* s = &D_0035dcfc[e->slot];
            eff_setup_1dddd0(e->sub, r->w14);
            EffObj* obj = s->obj;
            YS__OBJ__is_valid(obj);
            obj->owner = e->sub;
            e->eff = ryj__PAX__start(e->sub, e->h8, 1, 3, 0, obj);
        }
        break;
    }
    case 5: {
        Ent* e = func_0022e330(c->h8);
        eff_setup_1dddd0(e->sub, func_00227bd8(e->w0, 2)->w14);
        EffSlot* s = &D_0035dcfc[e->slot];
        EffObj* obj = s->obj;
        YS__OBJ__is_valid(obj);
        obj->owner = e->sub;
        break;
    }
    case 4:
        func_0022e368(c);
        break;
    default: {
        Ent* e = func_0022e330(c->h8);
        void* f;
        switch (c->type) {
        case 1:
            if (func_0022e0a8(e)) {
                f = e->eff;
                if (eff_is_alive(f) && eff_is_active(f) && eff_is_loop(f)) eff_kill(f);
            }
            break;
        case 6:
            if (func_0022e0a8(e)) {
                f = e->eff;
                if (eff_is_alive(f) && eff_is_active(f)) eff_kill(f);
            }
            break;
        case 3:
            if (func_0022e0a8(e)) {
                f = e->eff;
                if (eff_is_alive(f) && eff_is_active(f)) eff_fadeout_kill(f, c->h10);
            }
            break;
        case 2:
            if (func_0022e0a8(e)) {
                f = e->eff;
                if (eff_is_alive(f) && eff_is_active(f)) eff_loop_end_kill(f);
            }
            break;
        }
        break;
    }
    }
}
}  // namespace n0022dd80

// 0022e0a8 (was src/anon/batch_w46.cpp)
namespace n0022e0a8 {
// 0022d1d8: moved to src/sasa/event_layout.cpp (linked unit)

// ---- 0022e0a8
u32 func_001de4b0(u8*, u32, u32) asm("func_001de4b0");
/*TARGET 0022e0a8*/
s32 func_0022e0a8(u8* p) asm("func_0022e0a8");
s32 func_0022e0a8(u8* p) {
    u32 v = 0;
    while ((v = func_001de4b0(p + 16, 0, v))) {
        if (*(u32*)(p + 12) == v) return 1;
    }
    return 0;
}
}  // namespace n0022e0a8

// 0022e110 (was src/anon/tiny_auto80_queue.cpp)
namespace n0022e110 {
u32 func_001de4b0(...) asm("func_001de4b0");
u32 func_001de568(...) asm("func_001de568");
/*TARGET 0022e110*/
u32 func_0022e110(u8* a0) asm("_Z13func_0022e110Ph");
u32 func_0022e110(u8* a0) {
    u8* s0 = a0 + 16;
    u32 v0 = func_001de568((u32)s0);
    u32 t7;
    if (v0 == 0) {
        goto zero;
    }
    v0 = func_001de4b0((u32)s0, 0, 0);
    if (v0 != 0) {
        t7 = 1;
        goto out;
    }
zero:
    t7 = 0;
out:
    return t7;
}
}  // namespace n0022e110

// 0022e160 (was src/anon/batch_w16.cpp)
namespace n0022e160 {
void func_00226030(u32, u32, u8*) asm("func_00226030");
void func_001de750(u32) asm("func_001de750");
/*TARGET 0022e160*/
void func_0022e160(u32 a, u32 b, u8* c) asm("func_0022e160");
void func_0022e160(u32 a, u32 b, u8* c) {
    func_00226030(a, b, c);
    func_001de750(*(u32*)(c + 20));
}
}  // namespace n0022e160

// 0022e188 (was src/anon/batch_w39.cpp)
namespace n0022e188 {
// --- 0022e188
// Builds prefix + s + suffix in a static buffer.
extern char D_01dadac0[] asm("D_01dadac0");
extern char D_003711e8[] asm("D_003711e8");
extern char D_003711f8[] asm("D_003711f8");
void func_002feee8(char*, const char*) asm("func_002feee8");
void strlen(char*) asm("strlen");
/*TARGET 0022e188*/
// strlen
char* func_0022e188(const char* s) asm("func_0022e188");
// strlen
char* func_0022e188(const char* s) {
    D_01dadac0[0] = 0;
    func_002feee8(D_01dadac0, D_003711e8);
    func_002feee8(D_01dadac0, s);
    func_002feee8(D_01dadac0, D_003711f8);
    strlen(D_01dadac0);  // strlen
    return D_01dadac0;
}
}  // namespace n0022e188

// 0022e1f8 (was src/anon/batch_w51.cpp)
namespace n0022e1f8 {
u32* func_00227a28(u32) asm("func_00227a28");
void func_002ff2e8(void*, u32) asm("func_002ff2e8");
u32 func_0022e188(u32) asm("func_0022e188");
u32 func_00227870(u32, void*, u32) asm("func_00227870");
void YS__FILE__ReadBack(u32, u32, void*, void*) asm("YS__FILE__ReadBack");
void func_0022e160(void) asm("func_0022e160");
/*TARGET 0022e1f8*/
void sa__EVENT__effect_read_set(u32 a0, u32 a1) asm("sa__EVENT__effect_read_set");
void sa__EVENT__effect_read_set(u32 a0, u32 a1) {
    u32* o = func_00227a28(a0);
    o[3] = a1;
    o[0] = 2;
    o[4] = (u32)-1;
    func_002ff2e8(o + 12, a0);
    u32 s = func_0022e188(a0);
    u32 r = func_00227870(s, o, 0);
    o[5] = r;
    YS__FILE__ReadBack(s, r, (void*)func_0022e160, o);
}
}  // namespace n0022e1f8

// 0022e288 (was src/anon/batch_w68.cpp)
namespace n0022e288 {
/* ---- 001dde40: unlink n from the list ---- */
struct LNode { u32 used; u32 pad[4]; LNode* next; };
void ryj__PAX__ensure(LNode* n) asm("ryj__PAX__ensure");
/* ---- 0022e288 ---- */
struct E12 { u32 f0; s32 id; u32 f8; u32 fc; u8 node[36]; };
union U12 { E12* p; s32 i; };
extern U12 D_0035dcf4 asm("D_0035dcf4");
s32 func_001de568(void*) asm("func_001de568");
/*TARGET 0022e288*/
void sa__EVENT__leaveAllEffect(void) asm("sa__EVENT__leaveAllEffect");
void sa__EVENT__leaveAllEffect(void) {
    s32 i;
    if (!D_0035dcf4.p) return;
    for (i = 0; i < 96; i++) {
        if (D_0035dcf4.p[i].id == -1) continue;
        if (func_001de568(D_0035dcf4.p[i].node)) ryj__PAX__ensure((LNode*)D_0035dcf4.p[i].node);
        D_0035dcf4.p[i].fc = 0;
        D_0035dcf4.p[i].id = -1;
    }
}
}  // namespace n0022e288

// 0022e330 (was src/anon/batch_w11.cpp)
namespace n0022e330 {
struct E22e { u32 a; s32 key; u8 pad[44]; };
extern E22e* D_0035dcf4 asm("D_0035dcf4");
/*TARGET 0022e330*/
E22e* func_0022e330(s32 key) asm("func_0022e330");
E22e* func_0022e330(s32 key) {
    E22e* e = D_0035dcf4;
    s32 i;
    for (i = 0; i < 96; i++, e++) {
        if (e->key == key) return e;
    }
    return 0;
}
}  // namespace n0022e330

// 0022e368 (was src/anon/batch_wcx2.cpp)
namespace n0022e368 {
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
// ---- 0022e368
union UA_0022e368 { s32 i; s16 s; u16 h; };
struct E_0022e368 { UA_0022e368 a; UA_0022e368 b; UA_0022e368 c; UA_0022e368 d; u8 pad2[30]; u16 e; u8 pad3[4]; };
union UG_0022e368 { E_0022e368* p; s32 i; u16 h; };
extern UG_0022e368 D_0035dcf4_e368 asm("D_0035dcf4");
/*TARGET 0022e368*/
void func_0022e368(UA_0022e368* a0) asm("func_0022e368");
void func_0022e368(UA_0022e368* a0) {
    for (s32 i = 0; i < 96; i++) {
        if (D_0035dcf4_e368.p[i].b.i == -1) {
            D_0035dcf4_e368.p[i].b.i = ((UA_0022e368*)((u8*)a0 + 8))->s;
            D_0035dcf4_e368.p[i].a.i = ((UA_0022e368*)((u8*)a0 + 10))->s;
            D_0035dcf4_e368.p[i].c.h = ((UA_0022e368*)((u8*)a0 + 12))->h;
            ((UA_0022e368*)&D_0035dcf4_e368.p[i].e)->h = ((UA_0022e368*)((u8*)a0 + 4))->h;
            D_0035dcf4_e368.p[i].d.i = 0;
            return;
        }
    }
}
}  // namespace n0022e368
#undef QCOPY

// 0022e3e8 (was src/anon/auto80_199_queue.cpp)
namespace n0022e3e8 {
/*TARGET 0022e3e8*/
void sa__EVENT__set_kage_seq(u32 a0) asm("_Z23sa__EVENT__set_kage_seqj");
void sa__EVENT__set_kage_seq(u32 a0) {
    u32 s16v = a0;
    u32 s17;
    u32 p;
    u32 q;

    if (sa__EVENT__checkStart(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s17 = func_00227d10(*(s16*)(s16v + 8));
    YS__OBJ__is_valid(*(u32*)(s17 + 8));  // list_contains_ptr
    if (*(s16*)(s16v + 10) != 0) {
        func_00194468(*(u32*)(s17 + 8));
        return;
    }
    p = *(u32*)(s17 + 8);
    q = *(u32*)(p + 268);
    q = q | 0x200;
    *(u32*)(p + 268) = q;
}
}  // namespace n0022e3e8

// 0022e468 (was src/anon/auto80_199_queue.cpp)
namespace n0022e468 {
/*TARGET 0022e468*/
void sa__EVENT__set_ik_seq(u32 a0) asm("_Z21sa__EVENT__set_ik_seqj");
void sa__EVENT__set_ik_seq(u32 a0) {
    u32 s16v = a0;
    u32 s17;
    u32 p;
    u32 q;
    s32 d;

    if (sa__EVENT__checkStart(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s17 = func_00227d10(*(s16*)(s16v + 8));
    YS__OBJ__is_valid(*(u32*)(s17 + 8));  // list_contains_ptr
    d = 0xbfff0000;
    d = d | 0xffff;
    if (*(s16*)(s16v + 10) != 0) {
        u32 p1 = *(u32*)(s17 + 8);
        u32 q1 = *(u32*)(p1 + 264);
        q1 = q1 & (u32)d;
        *(u32*)(p1 + 264) = q1;
        goto L0022e4c0;
    }
    p = *(u32*)(s17 + 8);
    q = *(u32*)(p + 264);
    q = q | 0x40000000;
    *(u32*)(p + 264) = q;
L0022e4c0:
    return;
}
}  // namespace n0022e468

// 0022e4f0 (was src/anon/batch_w83.cpp)
namespace n0022e4f0 {
s32 sa__EVENT__checkStart(s32) asm("sa__EVENT__checkStart");
u8* func_00227d10(s32) asm("func_00227d10");
void YS__OBJ__is_valid(void*) asm("YS__OBJ__is_valid");
// list_contains_ptr
double func_00313b80(f32) asm("func_00313b80");
// float_to_double
double func_002f83f0(double) asm("func_002f83f0");
f32 __truncdfsf2(double) asm("__truncdfsf2");
// double_trunc
struct Rot { s16 pad0, pad1; s16 a, b, nx, ny, nz; };
struct Hold { u8 pad[8]; f32* o; };
/*TARGET 0022e4f0*/
// Wrap each rotation component through double helpers, optionally negating it.
void sa__EVENT__set_mirror_seq(Rot* r) asm("sa__EVENT__set_mirror_seq");
// Wrap each rotation component through double helpers, optionally negating it.
void sa__EVENT__set_mirror_seq(Rot* r) {
    if (sa__EVENT__checkStart(r->a)) return;
    Hold* v = (Hold*)func_00227d10(r->b);
    YS__OBJ__is_valid(v->o);  // list_contains_ptr
    f32* o = v->o;
    o[12] = __truncdfsf2(func_002f83f0(func_00313b80(o[12])));  // double_trunc
    if (r->nx) { v->o[12] = -v->o[12];  }
    o = v->o;
    o[13] = __truncdfsf2(func_002f83f0(func_00313b80(o[13])));  // double_trunc
    if (r->ny) { v->o[13] = -v->o[13];  }
    o = v->o;
    o[14] = __truncdfsf2(func_002f83f0(func_00313b80(o[14])));  // double_trunc
    if (r->nz) v->o[14] = -v->o[14];
}
}  // namespace n0022e4f0

// 0022e5f8 (was src/anon/auto80_199_queue.cpp)
namespace n0022e5f8 {
/*TARGET 0022e5f8*/
void func_0022e5f8(u32 a0) asm("_Z13func_0022e5f8j");
void func_0022e5f8(u32 a0) {
    u32 s18 = a0;
    u32 s16v;
    u32 s17;
    f32 f0;
    f32 f20;
    f32 f21;

    if (sa__EVENT__checkStart(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s16v = func_00227d10(*(s16*)(s18 + 6));
    YS__OBJ__is_valid(*(u32*)(s16v + 8));  // list_contains_ptr
    s17 = *(u32*)(s16v + 8);
    f21 = func_00227c78(s18 + 8);
    s17 = s17 + 2248;
    f20 = func_00227c78(s18 + 12);
    f0 = func_00227c78(s18 + 16);
    func_001ad990(s17, f21, f20, f0);
}
}  // namespace n0022e5f8

// 0022e6b0 (was src/anon/batch_w45.cpp)
namespace n0022e6b0 {
void YS__OBJ__is_valid(u8*) asm("YS__OBJ__is_valid");
/*TARGET 0022e6b0*/
// 0022c758: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022e6b0(s32 which, u8* a1, f32 f) asm("func_0022e6b0");
// 0022c758: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022e6b0(s32 which, u8* a1, f32 f) {
    YS__OBJ__is_valid(a1);  // list_contains_ptr
    switch (which) {
    case 0: *(f32*)(a1 + 52) = f; break;
    case 1: *(f32*)(a1 + 56) = f; break;
    case 2: *(f32*)(a1 + 48) = f; break;
    }
}
}  // namespace n0022e6b0

// 0022e728 (was gap)
namespace n0022e728 {
s32 YS__OBJ__is_valid(u32) asm("YS__OBJ__is_valid");
s32 func_0014f0e0(f32*) asm("func_0014f0e0");
void func_0022e6b0(s32, u32, f32) asm("func_0022e6b0");
void func_00106420(f32*) asm("func_00106420");
void func_001024a8(u8*) asm("func_001024a8");
void func_0022e728(u8* t) asm("func_0022e728");
void func_0022e728(u8* t) {
    u32 obj = *(u32*)(t + 4);
    if (!YS__OBJ__is_valid(obj)) return;
    f32* v = *(f32**)(t + 8);
    s32 which = *(s32*)(t + 12);
    if (func_0014f0e0(v) == 0) {
        func_0022e6b0(which, obj, v[0]);
        func_00106420(v);
        *(f32**)(t + 8) = 0;
        func_001024a8(t);
    } else {
        func_0022e6b0(which, obj, v[0]);
    }
}
}  // namespace n0022e728

// 0022e7e8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0022e7e8 {
u32 func_00106420(...) asm("func_00106420");
/*TARGET 0022e7e8*/
void func_0022e7e8(u32* a0) asm("_Z13func_0022e7e8Pj");
void func_0022e7e8(u32* a0) {
    u32 t7 = a0[2];
    if (t7 == 0) {
        return;
    }
    func_00106420(t7);
}
}  // namespace n0022e7e8

// 0022e818 (was src/anon/batch_w279.cpp)
namespace n0022e818 {
// 00179718: moved to src/yasui/libys/player.cpp

// ---- sa__EVENT__set_scale_seq
s32 sa__EVENT__checkStart(s32) asm("sa__EVENT__checkStart");
s32 sa__EVENT__getEventPriority(void) asm("sa__EVENT__getEventPriority");
// limit_15000_or_25000
u8* sa_entry_work_get(s32) asm("_ZN2sa5EVENT14entry_work_getEi");
void YS__OBJ__is_valid(u32) asm("YS__OBJ__is_valid");
// list_contains_ptr
s32 sa__EVENT__isJumpMode(s32) asm("sa__EVENT__isJumpMode");
// flag_query_by_index
u8* field_create_task(s32, s32, void (*)(void*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
void* area_get_allocator(void) asm("_ZN4AREA12GetAllocatorEv");
f32* tz_load_data_alloc(u32, void*) asm("_ZN2Tz13LoadDataAllocEjj");
f32 sa_get_float(void*) asm("_ZN2sa5EVENT9get_floatEPv");
void func_0014f030(f32*, f32, f32, f32) asm("func_0014f030");
// obj_set_lerp_params
void func_0022e6b0(s32, u32, f32) asm("func_0022e6b0");
void func_0022e7e8(void*) asm("func_0022e7e8");
void func_0022e728(void*) asm("func_0022e728");
union W279H { s16 h; u8 c; };
union W279P { f32* p; u8 c; };
/*TARGET 0022e818*/
void sa__EVENT__set_scale_seq(u8* s) asm("sa__EVENT__set_scale_seq");
void sa__EVENT__set_scale_seq(u8* s) {
    if (sa__EVENT__checkStart(*(s16*)(s + 4))) return;
    s32 a = sa__EVENT__getEventPriority();  // limit_15000_or_25000
    u8* b = sa_entry_work_get(*(s16*)(s + 6));
    YS__OBJ__is_valid(*(u32*)(b + 8));  // list_contains_ptr
    if (!sa__EVENT__isJumpMode(*(s16*)(s + 4))) {  // flag_query_by_index
        u8* t = field_create_task(1, a, func_0022e728);
        *(u32*)(t + 48) = (u32)func_0022e7e8;
        *(u32*)(t + 4) = *(u32*)(b + 8);
        f32* v = tz_load_data_alloc(12, area_get_allocator());
        v[0] = 0.0f;
        v[1] = 0.0f;
        v[2] = 1.0f;
        ((W279P*)(t + 8))->p = v;
        *(s32*)(t + 12) = ((W279H*)(s + 18))->h;
        f32 h = ((W279H*)(s + 16))->h;
        f32 x = sa_get_float(s + 8);
        h = h * 2.0f;
        f32 y = sa_get_float(s + 12);
        func_0014f030(v, x, y, h);  // obj_set_lerp_params
    } else {
        func_0022e6b0(*(s16*)(s + 18), *(u32*)(b + 8), sa_get_float(s + 12));
    }
}
}  // namespace n0022e818

// 0022e998 (was src/anon/auto80_199_queue.cpp)
namespace n0022e998 {
/*TARGET 0022e998*/
void func_0022e998(u32 a0) asm("_Z13func_0022e998j");
void func_0022e998(u32 a0) {
    u32 s17 = a0;
    u32 s16v = *(u32*)(a0 + 8);

    if (func_002f13b0(s16v) != 0) {
        return;
    }
    func_00106420(s16v);
    *(u32*)(s17 + 8) = 0;
    func_001024a8(s17);
}
}  // namespace n0022e998

// 0022e9f8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0022e9f8 {
u32 func_00106420(...) asm("func_00106420");
/*TARGET 0022e9f8*/
void func_0022e9f8(u32* a0) asm("_Z13func_0022e9f8Pj");
void func_0022e9f8(u32* a0) {
    u32 t7 = a0[2];
    if (t7 == 0) {
        return;
    }
    func_00106420(t7);
}
}  // namespace n0022e9f8

// 0022ea28 (was src/anon/batch_w94.cpp)
namespace n0022ea28 {
s32 sa__EVENT__checkStart(s32) asm("sa__EVENT__checkStart");
u32 sa__EVENT__getEventPriority(void) asm("sa__EVENT__getEventPriority");
// limit_15000_or_25000
u8* func_00227d10(s16) asm("func_00227d10");
void YS__OBJ__is_valid(u32) asm("YS__OBJ__is_valid");
// list_contains_ptr
s32 sa__EVENT__isJumpMode(s16) asm("sa__EVENT__isJumpMode");
// flag_query_by_index
void func_0022e998(void) asm("func_0022e998");
void func_0022e9f8(void) asm("func_0022e9f8");
u8* func_00102c18(s32, u32, void (*)(void)) asm("func_00102c18");
u32 func_001050c8(void) asm("func_001050c8");
u8* func_001063c0(s32, u32) asm("func_001063c0");
f32 func_00227c78(u8*) asm("func_00227c78");
void dk__Turn__start(u8*, u32, s32, f32, f32) asm("dk__Turn__start");
void func_0016aeb8(u32, f32) asm("func_0016aeb8");
union Slot { u8* p; s16 h; };
/*TARGET 0022ea28*/
void func_0022ea28(u8* p) asm("func_0022ea28");
void func_0022ea28(u8* p) {
    if (sa__EVENT__checkStart(*(s16*)(p + 4))) return;
    u32 parent = sa__EVENT__getEventPriority();  // limit_15000_or_25000
    u8* m = func_00227d10(*(s16*)(p + 6));
    YS__OBJ__is_valid(*(u32*)(m + 8));  // list_contains_ptr
    if (sa__EVENT__isJumpMode(*(s16*)(p + 4)) == 0) {  // flag_query_by_index
        u8* o = func_00102c18(1, parent, func_0022e998);
        *(void (**)(void))(o + 48) = func_0022e9f8;
        u8* n = func_001063c0(24, func_001050c8());
        ((Slot*)(o + 8))->p = n;
        dk__Turn__start(n, *(u32*)(m + 8), *(s16*)(p + 8), func_00227c78(p + 12), *(s16*)(p + 10) * 2.0f);
    } else {
        func_0016aeb8(*(u32*)(m + 8), 3.1415927f - func_00227c78(p + 12) * 0.017453292f);
    }
}
}  // namespace n0022ea28

// 0022eb80 (was src/anon/batch_w1975_nsa.cpp)
namespace n0022eb80 {
#define W1975_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define W1975_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct W1975V {
    f32 x, y, z, w;
    W1975V() {}
    W1975V(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1975V(const W1975V& o) { W1975_QCOPY(this, &o); }
    W1975V& operator=(const W1975V& o) { if (this != &o) W1975_QCOPY(this, &o); return *this; }
    void scale(f32 s) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(this), "f"(s) : "$8", "memory");
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct W1975M {
    W1975V r[4];
    W1975M() {}
    W1975M& operator=(const W1975M& o) { if (this != &o) W1975_QCOPY4(this, &o); return *this; }
    W1975V operator*(const W1975V& v) const {
        W1975V o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t.set noreorder\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    W1975V apply3(const W1975V& v) const {
        W1975V o;
        asm volatile("lqc2 $vf4, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tvmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tsqc2 $vf4, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
inline void* operator new(unsigned int, void* p) { return p; }
void W1975_identity(W1975M*) asm("_Z13func_0011b6a8Pv");
void W1975_rotateX(W1975M*, f32) asm("_ZN2kn7FMatrix7rotateXEf");
void W1975_rotateZ(W1975M*, f32) asm("_ZN2kn7FMatrix7rotateZEf");
f32 W1975_FixRadian(f32) asm("_ZN2YS4MATH9FixRadianEf");
// func_0022eb80 types
struct W1975Ev { s16 h0; s16 h2; s16 h4; s16 h6; s32 f8; s32 f12; s16 h16; s16 h18; };
struct W1975Work { u8 pad[8]; u8* p8; };
f32 W1975_Ev_get_float(void*) asm("_ZN2sa5EVENT9get_floatEPv");
W1975Work* W1975_Ev_entry_work_get(s32) asm("_ZN2sa5EVENT14entry_work_getEi");
// The mangled name lists only the f32, but the call passes a vector pointer in a1 as well.
void W1975_LookAt_release(u8*, f32, W1975V*) asm("_ZN2YS6LOOKAT7releaseEf");
extern s8 D_01dadaf0 asm("D_01dadaf0");
extern W1975V D_01dadb00 asm("D_01dadb00");
s32 sa__EVENT__checkStart(s32) asm("sa__EVENT__checkStart");
void YS__OBJ__is_valid(u8*) asm("YS__OBJ__is_valid");
void func_002fd188(void (*)(void)) asm("func_002fd188");
void func_0022f8e8(void) asm("func_0022f8e8");
void func_001b0858(u8*, f32, W1975V*, s32) asm("func_001b0858");
/*TARGET 0022eb80*/
// 0x001e1160: definition moved into src/anon/unit_001e0cb8.cpp

// D_01dadb00 is a function-local static (guard D_01dadaf0, empty atexit dtor func_0022f8e8).
void func_0022eb80(W1975Ev* self) asm("func_0022eb80");
// 0x001e1160: definition moved into src/anon/unit_001e0cb8.cpp

// D_01dadb00 is a function-local static (guard D_01dadaf0, empty atexit dtor func_0022f8e8).
void func_0022eb80(W1975Ev* self) {
    W1975Work* w;
    f32 rx, rz;
    W1975V v;
    W1975M m;
    if (sa__EVENT__checkStart(self->h4) != 0) return;
    w = W1975_Ev_entry_work_get(self->h6);
    YS__OBJ__is_valid(w->p8);
    if (!D_01dadaf0) {
        D_01dadaf0 = 1;
        new (&D_01dadb00) W1975V(0.0f, 1.0f, 0.0f, 1.0f);
        func_002fd188(func_0022f8e8);
    }
    f32 k = 0.017453292f;
    f32 az = W1975_Ev_get_float(&self->f12) * k;
    f32 ax = W1975_Ev_get_float(&self->f8) * k;
    rz = W1975_FixRadian(az);
    rx = W1975_FixRadian(ax);
    W1975_identity(&m);
    W1975_rotateX(&m, rx);
    W1975_rotateZ(&m, rz);
    v = m * D_01dadb00;
    v.normalize();
    if (self->h18 == 0) func_001b0858(w->p8 + 1184, (f32)self->h16 * 2.0f, &v, 0);
    else W1975_LookAt_release(w->p8 + 1184, (f32)self->h16 * 2.0f, &v);
}
}  // namespace n0022eb80
#undef W1975_QCOPY
#undef W1975_QCOPY4

// 0022ed70 (was gap)
namespace n0022ed70 {
s32 YS__OBJ__is_valid(u8*) asm("YS__OBJ__is_valid");
s32 func_0014f0e0(f32*) asm("func_0014f0e0");
void func_00106420(f32*) asm("func_00106420");
void func_001024a8(u8*) asm("func_001024a8");
void func_0022ed70(u8* t) asm("func_0022ed70");
void func_0022ed70(u8* t) {
    u8* obj = *(u8**)(t + 4);
    if (!YS__OBJ__is_valid(obj)) return;
    f32* v = *(f32**)(t + 8);
    if (func_0014f0e0(v) == 0) {
        *(f32*)(obj + 2472) = v[0];
        func_00106420(v);
        *(f32**)(t + 8) = 0;
        func_001024a8(t);
    } else {
        *(f32*)(obj + 2472) = v[0];
    }
}
}  // namespace n0022ed70

// 0022ee00 (was src/anon/tiny_auto80_queue.cpp)
namespace n0022ee00 {
u32 func_00106420(...) asm("func_00106420");
/*TARGET 0022ee00*/
void func_0022ee00(u32* a0) asm("_Z13func_0022ee00Pj");
void func_0022ee00(u32* a0) {
    u32 t7 = a0[2];
    if (t7 == 0) {
        return;
    }
    func_00106420(t7);
}
}  // namespace n0022ee00

// 0022ee30 (was src/anon/batch_w259.cpp)
namespace n0022ee30 {
struct A22e { u8 p[4]; s16 h4; s16 h6; u8 b8; u8 b9; s16 h10; };
struct B22e { u8 p[2472]; f32 f2472; };
struct C22e { u8 p[8]; B22e* f8; };
struct W22e { u32 f0; u32 f4; f32 f8; };
struct V22e { u32 f0; B22e* f4; union { W22e* p; u32 u; f32 f; } f8; u8 p[36]; B22e* f48; };
// 0x00259e90: definition moved into src/anon/unit_002588e8.cpp

s32 sa__EVENT__checkStart(s32) asm("sa__EVENT__checkStart");
void* sa__EVENT__getEventPriority(void) asm("sa__EVENT__getEventPriority");
// limit_15000_or_25000
C22e* func_00227d10(s32) asm("func_00227d10");
void YS__OBJ__is_valid(B22e*) asm("YS__OBJ__is_valid");
// list_contains_ptr
s32 sa__EVENT__isJumpMode(s32) asm("sa__EVENT__isJumpMode");
// flag_query_by_index
V22e* func_00102c18(s32, void*, void*) asm("func_00102c18");
void* func_001050c8(void) asm("func_001050c8");
W22e* func_001063c0(s32, void*) asm("func_001063c0");
void func_0014f030(W22e*, f32, f32, f32) asm("func_0014f030");
// obj_set_lerp_params
void func_0022ed70(void) asm("func_0022ed70");
void func_0022ee00(void) asm("func_0022ee00");
/*TARGET 0022ee30*/
void sa__EVENT__set_shadow_alpha_seq(A22e* a) asm("sa__EVENT__set_shadow_alpha_seq");
void sa__EVENT__set_shadow_alpha_seq(A22e* a) {
    if (sa__EVENT__checkStart(a->h4)) return;
    void* s = sa__EVENT__getEventPriority();  // limit_15000_or_25000
    C22e* c = func_00227d10(a->h6);
    YS__OBJ__is_valid(c->f8);  // list_contains_ptr
    if (!sa__EVENT__isJumpMode(a->h4)) {  // flag_query_by_index
    V22e* v = func_00102c18(1, s, (void*)func_0022ed70);
    v->f48 = (B22e*)func_0022ee00;
    v->f4 = c->f8;
    W22e* w = func_001063c0(12, func_001050c8());
    w->f0 = 0;
    w->f4 = 0;
    w->f8 = 1.0f;
    v->f8.p = w;
    func_0014f030(w, (f32)a->b8, (f32)a->b9, (f32)a->h10 * 2.0f);  // obj_set_lerp_params
    } else {
        c->f8->f2472 = (f32)a->b9;
    }
}
}  // namespace n0022ee30

// 0022ef50 (was src/anon/auto80_199_queue.cpp)
namespace n0022ef50 {
/*TARGET 0022ef50*/
void sa__EVENT__set_part_seq(u32 a0) asm("_Z23sa__EVENT__set_part_seqj");
void sa__EVENT__set_part_seq(u32 a0) {
    u32 s17 = a0;
    u32 s16v;
    u32 p;

    if (sa__EVENT__checkStart(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s16v = func_00227d10(*(s16*)(s17 + 8));
    YS__OBJ__is_valid(*(u32*)(s16v + 8));  // list_contains_ptr
    p = *(u32*)(s16v + 8);
    func_0011c798(*(u32*)(p + 1648), s17 + 10);
}
}  // namespace n0022ef50

// 0022efb8 (was src/anon/batch_w47.cpp)
namespace n0022efb8 {
// The original reloads p->f4 after the first store (no strict aliasing); the
// union destination reproduces that.
struct S22e { u8 pad[4]; s16 f4; u8 pad6[2]; u8 f8; u8 f9; s16 f10; s16 f12; };
union U22 { s32 i; s16 h; };
struct R22e { u8 pad[12]; U22 f12; U22 f16; u8 f20; u8 f21; };
s32 sa__EVENT__checkStart(s32) asm("sa__EVENT__checkStart");
R22e* func_00227d10(s32) asm("func_00227d10");
/*TARGET 0022efb8*/
void sa__EVENT__set_alpha_seq(S22e* p) asm("sa__EVENT__set_alpha_seq");
void sa__EVENT__set_alpha_seq(S22e* p) {
    if (sa__EVENT__checkStart(p->f4)) return;
    R22e* r = func_00227d10(p->f12);
    r->f12.i = p->f4;
    r->f16.i = p->f4 + p->f10;
    r->f20 = p->f8;
    r->f21 = p->f9;
}
}  // namespace n0022efb8

// 0022f018 (was src/anon/batch_w295.cpp)
namespace n0022f018 {
struct T40 { s32 w0; s32 w4; u32 w8; u8 pad[28]; };
struct T52 { s32 w0; s32 w4; u8 pad[38]; s16 h46; s16 h48; u8 pad2[2]; };
extern T40* D_0035dcfc asm("D_0035dcfc");
extern T52* D_0035dcf4 asm("D_0035dcf4");
extern s32 D_0035de20 asm("D_0035de20");
s32 sa__EVENT__checkStart(s32) asm("sa__EVENT__checkStart");
void ut_1c0d38(u32, u32, s32, s32) asm("_Z15YS__OBJ__attachjjjj");
struct S { u8 pad[4]; s16 h4; u8 p6[2]; s16 h8; s16 h10; s16 h12; s16 h14; s16 h16; };
/*TARGET 0022f018*/
void func_0022f018(S* s) asm("func_0022f018");
void func_0022f018(S* s) {
  s32 b, a, i;
  if (sa__EVENT__checkStart(s->h4)) return;
  b = -1; a = -1;
  switch (s->h16) {
  case 1: {
    T40* e = D_0035dcfc;
    for (i = 0; i < 96; i++, e++) { if (e->w0 != -1 && e->w4 == s->h10) { a = i; break; } }
    e = D_0035dcfc;
    for (i = 0; i < 96; i++, e++) { if (e->w0 != -1 && e->w4 == s->h8) { b = i; break; } }
    break; }
  case 0: {
    T40* e = D_0035dcfc;
    for (i = 0; i < 96; i++, e++) { if (e->w0 != -1 && e->w4 == s->h8) { b = i; break; } }
    s32 d = D_0035de20;
    T52* f = D_0035dcf4;
    for (i = 0; i < 96; i++, f++) {
      if (f->w4 != -1 && f->w4 == s->h10 && f->w0 == s->h14 && !(d < f->h46)) { a = i; break; }
    }
    break; }
  }
  if (b < 0) return;
  if (a < 0) return;
  switch (s->h16) {
  case 0: D_0035dcf4[a].h48 = b; break;
  case 1: ut_1c0d38(D_0035dcfc[a].w8, D_0035dcfc[b].w8, s->h12, 0); break;
  }
}
}  // namespace n0022f018

// 0022f200 (was src/anon/auto80_199_queue.cpp)
namespace n0022f200 {
/*TARGET 0022f200*/
void sa__EVENT__set_bgcol_seq(u32 a0) asm("_Z24sa__EVENT__set_bgcol_seqj");
void sa__EVENT__set_bgcol_seq(u32 a0) {
    u32 s16v = a0;
    u32 s17;
    u32 p;
    u32 q;
    s32 mask = -2;

    if (sa__EVENT__checkStart(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s17 = func_00227d10(*(s16*)(s16v + 8));
    YS__OBJ__is_valid(*(u32*)(s17 + 8));  // list_contains_ptr
    if (*(s16*)(s16v + 10) != 0) {
        u32 p1 = *(u32*)(s17 + 8);
        u32 q1 = *(u32*)(p1 + 264);
        q1 = q1 & (u32)mask;
        *(u32*)(p1 + 264) = q1;
        goto L0022f254;
    }
    p = *(u32*)(s17 + 8);
    q = *(u32*)(p + 264);
    q = q | 0x1;
    *(u32*)(p + 264) = q;
L0022f254:
    return;
}
}  // namespace n0022f200

// 0022f280 (was src/anon/auto80_199_queue.cpp)
namespace n0022f280 {
/*TARGET 0022f280*/
void func_0022f280(u32 a0) asm("_Z13func_0022f280j");
void func_0022f280(u32 a0) {
    u32 s16v = a0;
    u32 s17;

    if (sa__EVENT__checkStart(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s17 = func_00227d10(*(s16*)(s16v + 6));
    YS__OBJ__is_valid(*(u32*)(s17 + 8));  // list_contains_ptr
    if (*(s8*)(s16v + 10) == 1) {
        func_00194070(*(u32*)(s17 + 8), *(u16*)(s16v + 8));
    } else {
        func_00194088(*(u32*)(s17 + 8), *(u16*)(s16v + 8));
    }
}
}  // namespace n0022f280

// 0022f308 (was src/anon/batch_wcx.cpp)
namespace n0022f308 {
typedef void (*VFn)(u8*);
// 0x001ea100: definition moved into src/anon/unit_001e8ac8.cpp
s32 sa__EVENT__checkStart(s16) asm("sa__EVENT__checkStart");
u8* func_00227d10(s16) asm("func_00227d10");
void YS__OBJ__is_valid(u8*) asm("YS__OBJ__is_valid");
// list_contains_ptr
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_001c0e60(u8*) asm("func_001c0e60");
void sa__EVENT__clearMotionCtrlWk(s16) asm("sa__EVENT__clearMotionCtrlWk");
void func_00227950(void) asm("func_00227950");
u8* func_00102c18(s32, s32, void (*)(void)) asm("func_00102c18");
union HP { s16 h[4]; u8* q; };
/*TARGET 0022f308*/
void func_0022f308(HP* hp) asm("func_0022f308");
void func_0022f308(HP* hp)
{
    s16* p = hp->h;
    if (sa__EVENT__checkStart(p[2])) return;
    u8* e = func_00227d10(p[3]);
    YS__OBJ__is_valid(*(u8**)(e + 8));  // list_contains_ptr
    if (func_001c0cd8(*(u8**)(e + 8))) func_001c0e60(*(u8**)(e + 8));
    (*(VFn*)(**(u8***)(e + 8) + 40))(*(u8**)(e + 8));
    *(u8**)(e + 8) = 0;
    sa__EVENT__clearMotionCtrlWk(hp->h[3]);
    *(s32*)(func_00102c18(1, 0xa7ee, func_00227950) + 4) = hp->h[3];
}
}  // namespace n0022f308

// 0022f3a8 (was src/anon/batch_w3911.cpp)
namespace n0022f3a8 {
struct Obj { u8 pad[943]; u8 a; };
struct Ent { s32 id; s32 pad4; Obj* obj; s32 start; s32 end; u8 from; u8 to; u8 pad[18]; };
extern Ent* D_0035dcfc asm("D_0035dcfc");
extern s32 D_0035de20 asm("D_0035de20");
void YS__OBJ__is_valid(Obj*) asm("YS__OBJ__is_valid");
/*TARGET 0022f3a8*/
// Fade each live entry's object value from 'from' to 'to' over [start, end).
// The FULL path is written in both arms so CSE shares one hi(D_0035dcfc) and
// cross-jumping merges the copies into the original's single out-of-line block.
void func_0022f3a8(void) asm("func_0022f3a8");
// Fade each live entry's object value from 'from' to 'to' over [start, end).
// The FULL path is written in both arms so CSE shares one hi(D_0035dcfc) and
// cross-jumping merges the copies into the original's single out-of-line block.
void func_0022f3a8(void)
{
    if (D_0035dcfc == 0) return;
    s32 now = D_0035de20;
    for (s32 i = 0; i < 96; i++) {
        Ent* e = (Ent*)(i*40 + (u32)D_0035dcfc);
        if (e->id == -1 || e->obj == 0) continue;
        Obj* o = e->obj;
        s32 st = e->start;
        if (st < 0 || now < st) continue;
        s32 en = e->end;
        if (now < en) {
            if (st != en) {
                u8 v = (s32)((f32)(now - st) * (f32)(e->to - e->from) / (f32)(en - st) + (f32)e->from);
                YS__OBJ__is_valid(o);
                D_0035dcfc[i].obj->a = v;
            } else {
                YS__OBJ__is_valid(o);
                D_0035dcfc[i].obj->a = D_0035dcfc[i].to;
            }
        } else {
            YS__OBJ__is_valid(o);
            D_0035dcfc[i].obj->a = D_0035dcfc[i].to;
        }
    }
}
}  // namespace n0022f3a8

// 0022f4f0 (was src/anon/batch_w12.cpp)
namespace n0022f4f0 {
extern u8* D_0035dcfc asm("D_0035dcfc");
/*TARGET 0022f4f0*/
u8* func_0022f4f0(s32 id) asm("func_0022f4f0");
u8* func_0022f4f0(s32 id) {
    u8* p = D_0035dcfc;
    s32 i;
    for (i = 0; i < 96; i++, p += 40)
        if (*(s32*)p == id) return p + 23;
    return 0;
}
}  // namespace n0022f4f0

// 0022f528 (was src/anon/batch_w225.cpp)
namespace n0022f528 {
void func_002ff2e8(void*, void*) asm("func_002ff2e8");
void func_00227da8(void*) asm("func_00227da8");
// 0x001904f0: definition moved into src/anon/unit_001900d0.cpp

struct K_w225 { s32 a, b, c, d, e; u8 f0, f1, f2, f3; u8 g[24]; };
/*TARGET 0022f528*/
void func_0022f528(u8* o) asm("func_0022f528");
void func_0022f528(u8* o) {
    {
        K_w225 t; t.a = -1; t.b = -1; t.c = 0; t.f2 = 0; t.f3 = 0;
        func_002ff2e8(&t.f3, o + 8);
    }
    K_w225 k; k.a = *(s16*)(o + 4); k.b = *(s16*)(o + 6); k.c = 0; k.d = -1; k.e = -1; k.f0 = 0; k.f1 = 0;
    func_00227da8(&k);
}
}  // namespace n0022f528

// 0022f5a0 (was src/anon/batch_w50.cpp)
namespace n0022f5a0 {
void YS__OBJENTRY__ReadRequest(u32, s32, s32) asm("YS__OBJENTRY__ReadRequest");
u8* func_00227d10(u32) asm("func_00227d10");
/*TARGET 0022f5a0*/
void func_0022f5a0(u32 a, u32 b, u32 c) asm("func_0022f5a0");
void func_0022f5a0(u32 a, u32 b, u32 c) {
    YS__OBJENTRY__ReadRequest(b | 0x40000000, -1, 30);
    func_00227d10(c)[22] = 1;
}
}  // namespace n0022f5a0

// 0022f5e8 (was src/anon/batch_w85.cpp)
namespace n0022f5e8 {
struct Obj22f;
struct Obj22fvt { u8 pad[40]; void (*f40)(Obj22f*); };
struct Obj22f { Obj22fvt* vt; };
void YS__OBJ__is_valid(Obj22f*) asm("YS__OBJ__is_valid");
// list_contains_ptr
void sa__EVENT__clearMotionCtrlWk(u32) asm("sa__EVENT__clearMotionCtrlWk");
struct Ent22f { s32 id; u32 f4; Obj22f* obj; u8 pad[28]; };
union Tbl22f { Ent22f* p; u8 c; };
extern Tbl22f D_0035dcfc asm("D_0035dcfc");
/*TARGET 0022f5e8*/
// releases every live entry; returns whether any was released
s32 func_0022f5e8(void) asm("func_0022f5e8");
// releases every live entry; returns whether any was released
s32 func_0022f5e8(void) {
    s32 r = 0;
    s32 i;
    if (!D_0035dcfc.p) return 0;
    for (i = 0; i < 96; i++) {
        if (D_0035dcfc.p[i].obj) {
            YS__OBJ__is_valid(D_0035dcfc.p[i].obj);  // list_contains_ptr
            D_0035dcfc.p[i].obj->vt->f40(D_0035dcfc.p[i].obj);
            D_0035dcfc.p[i].obj = 0;
            sa__EVENT__clearMotionCtrlWk(D_0035dcfc.p[i].f4);
            D_0035dcfc.p[i].id = -1;
            r = 1;
        }
    }
    return r;
}
}  // namespace n0022f5e8

// 0022f6b8 (was src/anon/batch_w84.cpp)
namespace n0022f6b8 {
// Converts a degree rotation (y offset by 180) to radians and applies it.
void func_0016b070(void*, f32*) asm("func_0016b070");
void func_0016aeb8(void*, f32) asm("func_0016aeb8");
s32 func_002283b0(void*, f32*) asm("func_002283b0");
static inline void DegToRad(u8* p, f32* v) {
    v[0] = v[0] * 0.0174532924f;
    v[1] = (v[1] + 180.0f) * 0.0174532924f;
    v[2] = -(v[2] * 0.0174532924f);
    func_0016b070(p, v);
}
/*TARGET 0022f6b8*/
void func_0022f6b8(u8* p, f32* v) asm("func_0022f6b8");
void func_0022f6b8(u8* p, f32* v) {
    if (*(u32*)(p + 1416) & 0x800000) {
        DegToRad(p, v);
        return;
    }
    if ((v[0] == 0.0f && v[2] == 0.0f) || !func_002283b0(p, v)) {
        func_0016aeb8(p, v[1] * 0.0174532924f);
        return;
    }
    DegToRad(p, v);
}
}  // namespace n0022f6b8

// 0022f7c0 (was src/anon/batch_w92.cpp)
namespace n0022f7c0 {
// ---- 22f7c0 ----
struct V22f {
    f32 x, y, z, w;
    V22f() {}
    V22f(const V22f& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct E22f { s32 f0; s32 id; void* obj; u32 pad[7]; };
s32 sa__EVENT__checkStart(u16) asm("sa__EVENT__checkStart");
void YS__OBJ__is_valid(void*) asm("YS__OBJ__is_valid");
// list_contains_ptr
f32 func_00227c78(u8*) asm("func_00227c78");
void func_0016adc8(void*, V22f) asm("func_0016adc8");
void func_0022f6b8(void*, V22f*) asm("func_0022f6b8");
extern E22f* D_0035dcfc asm("D_0035dcfc");
/*TARGET 0022f7c0*/
void func_0022f7c0(u8* s) asm("func_0022f7c0");
void func_0022f7c0(u8* s) {
    if (sa__EVENT__checkStart(*(u16*)(s + 38))) return;
    if (*(s16*)(s + 4)) return;
    f32 one = 1.0f;
    for (s32 i = 0; i < 96; i++) {
        E22f* e = (E22f*)((u32)(i * 40) + (u32)D_0035dcfc);
        if (e->f0 < 0) continue;
        if (*(s16*)(s + 36) != e->id) continue;
        void* o = e->obj;
        YS__OBJ__is_valid(o);  // list_contains_ptr
        V22f a, unused, b;
        (void)&unused;
        a.x = func_00227c78(s + 8);
        a.y = func_00227c78(s + 12);
        a.z = func_00227c78(s + 16);
        a.w = one;
        b.x = func_00227c78(s + 20);
        b.y = func_00227c78(s + 24);
        b.z = func_00227c78(s + 28);
        b.w = one;
        func_0016adc8(o, a);
        func_0022f6b8(o, &b);
        return;
    }
}
}  // namespace n0022f7c0

// 0022f8e8 (was gap)
namespace n0022f8e8 {
void func_0022f8e8(void) asm("func_0022f8e8");
void func_0022f8e8(void) {}
}  // namespace n0022f8e8

// 0022f8f0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0022f8f0 {
/*TARGET 0022f8f0*/
f32 func_0022f8f0(f32* a0, f32* a1) asm("_Z13func_0022f8f0PfS_");
f32 func_0022f8f0(f32* a0, f32* a1) {  // vec4_dot
    return a0[0] * a1[0] + a0[1] * a1[1] + a0[2] * a1[2] + a0[3] * a1[3];
}
}  // namespace n0022f8f0

// 0022f928 (was src/anon/batch_w1690_nsa.cpp)
namespace n0022f928 {
inline void* operator new(unsigned int, void* p) { return p; }
struct W1690Vec {
    f32 x, y, z, w;
    W1690Vec() {}
    W1690Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1690Vec(const W1690Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1690Vec& operator=(const W1690Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1690Mtx {
    W1690Vec r0, r1, r2, r3;
    W1690Mtx(const W1690Vec& a, const W1690Vec& b, const W1690Vec& c, const W1690Vec& d) : r0(a), r1(b), r2(c), r3(d) {}
    W1690Vec operator*(const W1690Vec& v) const {
        W1690Vec o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct W1690Pt { f32 x, y, z; };
extern s8 D_01dadb10 asm("D_01dadb10");
extern W1690Mtx D_01dadb20 asm("D_01dadb20");
void func_00230d68(void) asm("func_00230d68");
void func_002fd188(void (*)(void)) asm("func_002fd188");
f32 func_0022f8f0(const W1690Vec*, const W1690Vec*) asm("func_0022f8f0");
/*TARGET 0022f928*/
// Cubic Hermite interpolation: p0, p1 are the end points, t0, t1 the tangents.
// The basis matrix is a function-local static (guard D_01dadb10, empty atexit dtor func_00230d68).
void func_0022f928(W1690Pt* out, W1690Pt* p0, W1690Pt* p1, W1690Pt* t0, W1690Pt* t1, f32 t) asm("func_0022f928");
// Cubic Hermite interpolation: p0, p1 are the end points, t0, t1 the tangents.
// The basis matrix is a function-local static (guard D_01dadb10, empty atexit dtor func_00230d68).
void func_0022f928(W1690Pt* out, W1690Pt* p0, W1690Pt* p1, W1690Pt* t0, W1690Pt* t1, f32 t)
{
    if (!D_01dadb10) {
        W1690Vec r0(2.0f, -2.0f, 1.0f, 1.0f);
        W1690Vec r1(-3.0f, 3.0f, -2.0f, -1.0f);
        W1690Vec r2(0.0f, 0.0f, 1.0f, 0.0f);
        W1690Vec r3(1.0f, 0.0f, 0.0f, 0.0f);
        new (&D_01dadb20) W1690Mtx(r0, r1, r2, r3);
        D_01dadb10 = 1;
        func_002fd188(func_00230d68);
    }
    f32 t2 = t * t;
    W1690Vec v(t2 * t, t2, t, 1.0f);
    v = D_01dadb20 * v;
    W1690Vec x(p0->x, p1->x, t0->x, t1->x);
    W1690Vec y(p0->y, p1->y, t0->y, t1->y);
    W1690Vec z(p0->z, p1->z, t0->z, t1->z);
    out->x = func_0022f8f0(&v, &x);
    out->y = func_0022f8f0(&v, &y);
    out->z = func_0022f8f0(&v, &z);
}
}  // namespace n0022f928

// 0022fb98 (was src/anon/batch_w1691_nsa.cpp)
namespace n0022fb98 {
// Uniform cubic B-spline point evaluation (needs -fno-strict-aliasing: the four freed
// basis-row temporaries are merged into one stack slot, which fixes the local layout).
inline void* operator new(unsigned int, void* p) { return p; }
#define W1691_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1691Vec {
    f32 x, y, z, w;
    W1691Vec() {}
    W1691Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1691Vec(const W1691Vec& o) { W1691_QCOPY(this, &o); }
    W1691Vec& operator=(const W1691Vec& o) { if (this != &o) W1691_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1691Mtx {
    W1691Vec r0, r1, r2, r3;
    W1691Mtx(const W1691Vec& a, const W1691Vec& b, const W1691Vec& c, const W1691Vec& d) : r0(a), r1(b), r2(c), r3(d) {}
    // VU0 matrix * column vector.
    W1691Vec operator*(const W1691Vec& v) const {
        W1691Vec o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct W1691Point { f32 x, y, z; };
f32 func_0022f8f0(const W1691Vec* a, const W1691Vec* b) asm("func_0022f8f0");
// vec4_dot
extern s8 D_01dadb60 asm("D_01dadb60");
// basis-matrix init guard
extern W1691Mtx D_01dadb70 asm("D_01dadb70");
// B-spline basis matrix
void func_00230d70(void) asm("func_00230d70");
// basis-matrix destructor (empty)
void func_002fd188(void (*)(void)) asm("func_002fd188");
/*TARGET 0022fb98*/
// atexit-style registration

// out = B-spline point at parameter t for control points p0..p3.
void func_0022fb98(W1691Point* out, f32 t, const W1691Point* p0, const W1691Point* p1, const W1691Point* p2, const W1691Point* p3) asm("func_0022fb98");
// atexit-style registration

// out = B-spline point at parameter t for control points p0..p3.
void func_0022fb98(W1691Point* out, f32 t, const W1691Point* p0, const W1691Point* p1, const W1691Point* p2, const W1691Point* p3) {
    if (!D_01dadb60) {
        W1691Vec r0(-1.0f / 6, 0.5f, -0.5f, 1.0f / 6);
        W1691Vec r1(0.5f, -1.0f, 0.5f, 0.0f);
        W1691Vec r2(-0.5f, 0.0f, 0.5f, 0.0f);
        W1691Vec r3(1.0f / 6, 2.0f / 3, 1.0f / 6, 0.0f);
        new (&D_01dadb70) W1691Mtx(r0, r1, r2, r3);
        D_01dadb60 = 1;
        func_002fd188(func_00230d70);
    }
    W1691Vec c(t * t * t, t * t, t, 1.0f);
    c = D_01dadb70 * c;
    W1691Vec px(p0->x, p1->x, p2->x, p3->x);
    W1691Vec py(p0->y, p1->y, p2->y, p3->y);
    W1691Vec pz(p0->z, p1->z, p2->z, p3->z);
    out->x = func_0022f8f0(&c, &px);
    out->y = func_0022f8f0(&c, &py);
    out->z = func_0022f8f0(&c, &pz);
}
}  // namespace n0022fb98
#undef W1691_QCOPY

// 0022fe08 (was src/anon/batch_w1692_nsa.cpp)
namespace n0022fe08 {
// Curve evaluation for a looping key list (0x0022fe08). VU0 vector ops are inline asm.
struct SplV3 { f32 x, y, z; };
struct SplVec {
    f32 x, y, z, w;
    SplVec() {}
    SplVec(f32 x_, f32 y_, f32 z_, f32 w_) { x = x_; y = y_; z = z_; w = w_; }
    SplVec& operator=(const SplVec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline SplVec operator*(const SplVec& v, f32 k) {
    SplVec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&v), "f"(k) : "$8", "memory");
    return r;
}
static inline SplVec operator-(const SplVec& a, const SplVec& b) {
    SplVec r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline SplVec operator+(const SplVec& a, const SplVec& b) {
    SplVec r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
// One key: position plus outgoing and incoming Bezier control points.
struct SplKey { SplV3 pos; SplV3 out; SplV3 in; f32 pad; };
struct Spline { u8 pad0[6]; s16 num; s16 type; u8 pad1[6]; SplKey key[1]; };
#define SPL_VEC(v) (v).x, (v).y, (v).z, 0.0f
void func_0022f928(SplVec* out, const SplVec* p0, const SplVec* p1, const SplVec* m0, const SplVec* m1, f32 t) asm("func_0022f928");
void func_0022fb98(SplVec* out, const SplVec* a, const SplVec* b, const SplVec* c, const SplVec* d, f32 t) asm("func_0022fb98");
/*TARGET 0022fe08*/
void func_0022fe08(SplVec* out, f32 t, Spline* s, s32 idx) asm("func_0022fe08");
void func_0022fe08(SplVec* out, f32 t, Spline* s, s32 idx) {
    s32 n = s->num;
    s32 i = idx % n;
    s32 ip = (i + n - 1) % n;
    s32 i1 = (i + 1) % n;
    s32 i2 = (i + 2) % n;
    SplVec m0, m1;
    SplKey* k = s->key;

    switch (s->type) {
    case 0: { // linear
        SplVec a(SPL_VEC(k[i].pos));
        SplVec b(SPL_VEC(k[i1].pos));
        *out = a * (1.0f - t) + b * t;
        break;
    }
    case 1: { // Bezier, converted to Hermite tangents
        SplVec a(SPL_VEC(k[i].out));
        SplVec b(SPL_VEC(k[i].pos));
        SplVec c(SPL_VEC(k[i1].pos));
        SplVec d(SPL_VEC(k[i1].in));
        m0 = (a - b) * 3.0f;
        m1 = (c - d) * 3.0f;
        func_0022f928(out, &b, &c, &m0, &m1, t);
        break;
    }
    case 2: { // uniform B-spline
        SplVec a(SPL_VEC(k[ip].pos));
        SplVec b(SPL_VEC(k[i].pos));
        SplVec c(SPL_VEC(k[i1].pos));
        SplVec d(SPL_VEC(k[i2].pos));
        func_0022fb98(out, &a, &b, &c, &d, t);
        break;
    }
    case 3: { // Catmull-Rom
        SplVec a(SPL_VEC(k[i1].pos));
        SplVec b(SPL_VEC(k[ip].pos));
        SplVec c(SPL_VEC(k[i2].pos));
        SplVec d(SPL_VEC(k[i].pos));
        m0 = (a - b) * 0.5f;
        m1 = (c - d) * 0.5f;
        func_0022f928(out, &d, &a, &m0, &m1, t);
        break;
    }
    }
}
}  // namespace n0022fe08
#undef SPL_VEC

// 00230260 (was src/anon/batch_w2367.cpp)
namespace n00230260 {
struct W2367Vec3 { f32 x, y, z; };
// 0x0018a100: definition moved into src/anon/unit_00189d38.cpp

// Yaw that faces from a towards b, written as (0, yaw, 0).
f32 f_atan2f(f32, f32) asm("f_atan2f");
f32 FixRadian_w2367(f32) asm("_ZN2YS4MATH9FixRadianEf");
/*TARGET 00230260*/
void func_00230260(W2367Vec3* a, W2367Vec3* b, W2367Vec3* out) asm("func_00230260");
void func_00230260(W2367Vec3* a, W2367Vec3* b, W2367Vec3* out) {
    f32 t = f_atan2f(b->x - a->x, b->z - a->z);
    t = 3.14159274f - t;
    t = FixRadian_w2367(t);
    out->x = 0; out->y = t; out->z = 0;
}
}  // namespace n00230260

