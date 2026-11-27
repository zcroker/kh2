// Linked unit 0x00297b30-0x00297e68 (Tz Jiminy journal: story list).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/jiminy.hpp"
#include "../tozawa/cmenu_slbase.hpp"
#include "../tozawa/jm_report.hpp"
#include "../tozawa/jm_story.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 00297b30 (was src/anon/perm_00297b30.cpp)
namespace n00297b30 {
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
struct Ent
{
  s16 a;
  u16 id;
  s16 b;
  s16 n;
};
struct Hdr
{
  s16 count;
  s16 pad[3];
  Ent e[1];
};
s32 func_002766d0(void) asm("func_002766d0");
void func_00138c10(s32, s32) asm("func_00138c10");
s32 func_0028b040(s32) asm("func_0028b040");
s8 *func_00276568(void) asm("func_00276568");
void func_002ac268(s32, s32) asm("func_002ac268");
s32 Tz__JmNewInfo__isStoryNew(s32, s32) asm("Tz__JmNewInfo__isStoryNew");
s32 func_002ac110(s32, s32) asm("func_002ac110");
extern s32 D_0035f200 asm("D_0035f200");
extern Hdr *D_0035f594 asm("D_0035f594");
extern s32 D_00374788 asm("D_00374788");
extern s32 D_0037478c asm("D_0037478c");
/*TARGET 00297b30*/
void Tz__JmStory__UpdateNewMark(void) asm("Tz__JmStory__UpdateNewMark");
void Tz__JmStory__UpdateNewMark(void)
{
  s32 base = func_002766d0();
  s32 i;
  s32 acc;
  s32 v;
  s32 off;
  s32 sel;
  s32 c;
  s32 new_var;
  for (i = 0; i < 10; i++)
  {
    func_00138c10((base + (i * 0x198)) + 0xa998, 2);
  }

  sel = 0;
  v = func_0028b040(D_0035f200);
  new_var = (acc = 0);
  off = v;
  for (i = 0, new_var; i < D_0035f594->count; i++)
  {
    if ((v == acc) || (v < (acc + D_0035f594->e[i].n)))
    {
      off = acc - v;
      sel = i;
      break;
    }
    acc += D_0035f594->e[i].n;
  }

  c = *func_00276568();
  for (i = sel; i < D_0035f594->count; i++)
  {
    if (off >= 0)
    {
      u16 id = D_0035f594->e[i].id;
      if (off == 0)
      {
        func_002ac268(c, id);
      }
      if (Tz__JmNewInfo__isStoryNew(c, id))
      {
        func_00138c10((base + (off * 0x198)) + 0xa998, (func_002ac110(c, id)) ? (D_0037478c) : (D_00374788));
      }
    }
    off += D_0035f594->e[i].n;
    if (off >= 10)
    {
      break;
    }
  }

}
}  // namespace n00297b30

// 00297cf8 (was src/anon/batch_w1590_g.cpp)
namespace n00297cf8 {
u32 func_00103570(void) asm("func_00103570");
void* func_001063c0(s32, u32) asm("func_001063c0");
void func_0023f800(void*) asm("func_0023f800");
extern void* D_0035f598 asm("D_0035f598");
extern void* D_0035f59c asm("D_0035f59c");
extern s8 D_0035f5a0 asm("D_0035f5a0");
extern s8 D_0035f5a1 asm("D_0035f5a1");
extern s8 D_0035f5a2 asm("D_0035f5a2");
extern s8 D_0035f5a3 asm("D_0035f5a3");
/*TARGET 00297cf8*/
void Tz__JmAlbum__Init(void) asm("Tz__JmAlbum__Init");
void Tz__JmAlbum__Init(void) {
    void* p;
    D_0035f598 = func_001063c0(0x14, func_00103570());
    p = func_001063c0(0x1c, func_00103570());
    func_0023f800(p);
    D_0035f59c = p;
    D_0035f5a0 = -1;
    D_0035f5a1 = -1;
    D_0035f5a3 = 0;
    D_0035f5a2 = 0;
}
}  // namespace n00297cf8

// 00297d78 (was src/anon/auto80_199_queue.cpp)
namespace n00297d78 {
/*TARGET 00297d78*/
void func_00297d78(void) asm("_Z13func_00297d78v");
void func_00297d78(void) {
    if (D_0035f598 != 0) {
        func_00106420(D_0035f598);
        D_0035f598 = 0;
    }
    if (D_0035f59c != 0) {
        u32 p = D_0035f59c;
        ((void (*)(u32))(*(u32*)(*(u32*)p + 4)))(p);
        D_0035f59c = 0;
    }
    D_0035f5a0 = -1;
    D_0035f5a1 = -1;
    D_0035f5a3 = 0;
    D_0035f5a2 = 0;
}
}  // namespace n00297d78

// 00297df8 (was src/anon/misc_2.cpp)
namespace n00297df8 {
/*TARGET 00297df8*/
void func_00297df8(void* self) asm("_Z13func_00297df8Pv");
void func_00297df8(void* self) {}
}  // namespace n00297df8

// 00297e00 (was src/anon/auto80_199_queue.cpp)
namespace n00297e00 {
/*TARGET 00297e00*/
void Tz__JmAlbum__LeaveAll(u32 a0) asm("_Z21Tz__JmAlbum__LeaveAllj");
void Tz__JmAlbum__LeaveAll(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_00287bc0();
    v0 -= 4;
    if (v0 >= 2) {
        return;
    }
    func_00298f90();
    func_00274ac8();
    if ((u32)(s0 - 4) < 2) {
        return;
    }
    func_0028f7e8(0);
}
}  // namespace n00297e00

