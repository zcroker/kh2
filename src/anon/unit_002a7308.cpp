// Linked unit 0x002a7308-0x002a8330.
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

// 002a7308 (gap function, never written before)
namespace n002a7308 {
typedef void (*VFn)(u8*);
struct E436 { u8 d[436]; };
extern E436 (*D_0035f5f4b)[2] asm("D_0035f5f4");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
s32 func_00276a90(void) asm("func_00276a90");
s32 func_00276b90(void) asm("func_00276b90");
s32 func_002a7308(void) asm("func_002a7308");
s32 func_002a7308(void)
{
    s32 r = 0;
    for (s32 i = 0; i < 4; i++) {
        for (s32 j = 0; j < 2; j++) {
            if (u_call4_00139d78(&D_0035f5f4b[i][j])) {
                u8* o = D_0035f5f4b[i][j].d;
                (*(VFn*)(*(u8**)o + 20))(o);
                r = 1;
            }
        }
    }
    if (!r) {
        r = func_00276a90();
        if (!r) r = func_00276b90();
    }
    return r;
}
}  // namespace n002a7308

// 002a73d0 (was src/anon/batch_wcx.cpp)
namespace n002a73d0 {
typedef void (*VFn)(u8*);
struct E436 { u8 d[436]; };
extern E436 (*D_0035f5f4b)[2] asm("D_0035f5f4");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00276a18(void) asm("func_00276a18");
void func_00276b10(void) asm("func_00276b10");
/*TARGET 002a73d0*/
void func_002a73d0(void) asm("func_002a73d0");
void func_002a73d0(void)
{
    for (s32 i = 0; i < 4; i++) {
        for (s32 j = 0; j < 2; j++) {
            if (u_call4_00139d78(&D_0035f5f4b[i][j])) {
                u8* o = D_0035f5f4b[i][j].d;
                (*(VFn*)(*(u8**)o + 20))(o);
            }
        }
    }
    func_00276a18();
    func_00276b10();
}
}  // namespace n002a73d0

// 002a7470 (was src/anon/tiny_wrappers_more.cpp)
namespace n002a7470 {
u32 func_00276c50(u32, u32, u32, u32) asm("_Z13func_00276c50jjjj");
/*TARGET 002a7470*/
// 0x002978d0: definition moved into src/anon/unit_00295d28.cpp

u32 func_002a7470(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002a7470jjjj");
// 0x002978d0: definition moved into src/anon/unit_00295d28.cpp

u32 func_002a7470(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00276c50(0x000048f9u, 0x00000000u, a2, a3);
}
}  // namespace n002a7470

// 002a7490 (was src/anon/tiny_auto80_queue.cpp)
namespace n002a7490 {
u32 func_001058e8(...) asm("func_001058e8");
/*TARGET 002a7490*/
u32 Tz__JmSynthe__isEnableRecipe() asm("_Z28Tz__JmSynthe__isEnableRecipev");
u32 Tz__JmSynthe__isEnableRecipe() {
    u32 t7 = *(u32*)(func_001058e8() + 18984);
    u32 v0 = t7 & 1;
    if (v0 == 0) {
        u32 t6 = t7 & 0x400;
        v0 = 0u < t6;
    }
    return v0;
}
}  // namespace n002a7490

// 002a74c0 (was src/anon/batch_w46.cpp)
namespace n002a74c0 {
u8* func_001058e8(void) asm("func_001058e8");
/*TARGET 002a74c0*/
// 0x0029c9d8: definition moved into src/anon/unit_0029ba88.cpp

// ---- 002a74c0: is any of the 64 flag bits set?
s32 Tz__JmSynthe__isEnableMaterial(void) asm("Tz__JmSynthe__isEnableMaterial");
// 0x0029c9d8: definition moved into src/anon/unit_0029ba88.cpp

// ---- 002a74c0: is any of the 64 flag bits set?
s32 Tz__JmSynthe__isEnableMaterial(void) {
    u32* bits = (u32*)(func_001058e8() + 18932);
    s32 r = 0;
    for (s32 i = 0; i < 64; i++) {
        if (bits[(u32)i >> 5] & (1 << (i & 31))) { r = 1; break; }
    }
    return r;
}
}  // namespace n002a74c0

// 002a7530 (was src/anon/auto80_199_queue.cpp)
namespace n002a7530 {
/*TARGET 002a7530*/
u32 func_002a7530(void) asm("_Z13func_002a7530v");
u32 func_002a7530(void) {
    u32 s0 = 0;
    if (Tz__JmSynthe__isEnableRecipe() != 0) {
        goto L_set;
    }
    if (Tz__JmSynthe__isEnableMaterial() != 0) {
        goto L_set;
    }
    if (func_00276c18() == 0) {
        goto L_ret;
    }
L_set:
    s0 = 1;
L_ret:
    return s0;
}
}  // namespace n002a7530

// 002a7588 (was src/anon/batch_w2027_nsa.cpp)
namespace n002a7588 {
// 0x002bef78: definition moved into src/anon/unit_002bebd0.cpp

/* Linked-list search: returns 1 when t is in the list at p+0x94. */
// 0017fdc0: moved to src/yasui/libys/motion.cpp

/* func_00253b30 is a (char*, const char*) copy. Declaring it as the strcpy
   builtin gives the original argument order (a0 set before a1). */
char* strcpy(char*, const char*) asm("func_00253b30");
char* func_002b64c8(void) asm("func_002b64c8");
void func_00170518(char*, s32, s32) asm("func_00170518");
/*TARGET 002a7588*/
void Tz__JmSynthe__ReadMixData(void) asm("Tz__JmSynthe__ReadMixData");
void Tz__JmSynthe__ReadMixData(void) {
    char buf[128];
    strcpy(buf, func_002b64c8());
    func_00170518(buf, 5102, 0);
}
}  // namespace n002a7588

// 002a75c0 (was src/anon/batch_wcx.cpp)
namespace n002a75c0 {
typedef void (*VFn)(u8*);
extern u8* D_0035f5f8 asm("D_0035f5f8");
extern u8 D_0035f5fc asm("D_0035f5fc");
extern u8 D_0035f5fd asm("D_0035f5fd");
void func_002b64d8(u8*) asm("func_002b64d8");
u8* func_00290948(u8*, s32) asm("func_00290948");
void func_002b6530(u8*) asm("func_002b6530");
void func_00293d80(s32) asm("func_00293d80");
/*TARGET 002a75c0*/
void Tz__JmSynthe__GetMixData(void) asm("Tz__JmSynthe__GetMixData");
void Tz__JmSynthe__GetMixData(void)
{
    func_002b64d8(D_0035f5f8);
    u8* t = func_00290948(D_0035f5f8, 0);
    s32 c = 0;
    u8* e = t + 16;
    s32 n = *(s32*)(t + 8);
    for (s32 i = 0; i < n; i++, e += 32) {
        c++;
        if (*(s16*)(e + 6)) c++;
    }
    D_0035f5fd = c;
    D_0035f5fc = func_00290948(D_0035f5f8, 1)[8];
    func_002b6530(D_0035f5f8);
    func_00293d80(5102);
    if (D_0035f5f8) { (*(VFn*)(*(u8**)D_0035f5f8 + 4))(D_0035f5f8); D_0035f5f8 = 0; }
}
}  // namespace n002a75c0

// 002a7678 (was src/anon/batch_w1585_g.cpp)
namespace n002a7678 {
void* tz_lsys(void) asm("_ZN2Tz17LoadDataGetSystemEv");
void* tz_alloc(u32, void*) asm("_ZN2Tz13LoadDataAllocEjj");
void func_00324448(void*) asm("func_00324448");
// 0x002a1f88: definition moved into src/anon/unit_002a1d38.cpp

/* 002a7678 */
extern void* D_0035f600 asm("D_0035f600");
extern void* D_0035f604 asm("D_0035f604");
/*TARGET 002a7678*/
void func_002a7678(void) asm("func_002a7678");
void func_002a7678(void) {
    void* t;
    D_0035f600 = tz_alloc(0x104, tz_lsys());
    t = tz_alloc(0x2350, tz_lsys());
    func_00324448(t);
    D_0035f604 = t;
}
}  // namespace n002a7678

// 002a76d8 (was src/anon/batch_w50.cpp)
namespace n002a76d8 {
typedef void (*VFn)(void*);
void func_00106420(void*) asm("func_00106420");
extern void* D_0035f600 asm("D_0035f600");
extern u8* D_0035f604 asm("D_0035f604");
/*TARGET 002a76d8*/
// 0x0029ec40: definition moved into src/anon/unit_0029d008.cpp

void func_002a76d8(void) asm("func_002a76d8");
// 0x0029ec40: definition moved into src/anon/unit_0029d008.cpp

void func_002a76d8(void) {
    if (D_0035f600) {
        func_00106420(D_0035f600);
        D_0035f600 = 0;
    }
    u8* p = D_0035f604;
    if (p) {
        u8* e = p + 8720;
        for (;;) {
            if (p == e) break;
            e -= 436;
            (*(VFn*)(*(u8**)e + 12))(e);
        }
        func_00106420(p);
        D_0035f604 = 0;
    }
}
}  // namespace n002a76d8

// 002a7758 (was src/anon/misc_2.cpp)
namespace n002a7758 {
/*TARGET 002a7758*/
void func_002a7758(void* self) asm("_Z13func_002a7758Pv");
void func_002a7758(void* self) {}
}  // namespace n002a7758

// 002a7760 (was src/anon/tiny_auto80_queue.cpp)
namespace n002a7760 {
void func_002a8258(...) asm("func_002a8258");
u32 func_00274ac8(...) asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
u32 func_00287bc0(...) asm("func_00287bc0");
/*TARGET 002a7760*/
void Tz__JmMiniGame__LeaveAll() asm("_Z24Tz__JmMiniGame__LeaveAllv");
void Tz__JmMiniGame__LeaveAll() {
    u32 v0 = func_00287bc0();
    if (v0 == 11 || v0 == 36) {
        func_002a8258();
        func_00274ac8();
    }
}
}  // namespace n002a7760

// 002a77a0 (was src/anon/batch_w2411_g.cpp)
namespace n002a77a0 {
u8* jm_parent(void) asm("_ZN2Tz6Jiminy9GetParentEv");
u8* jm_seqtbl(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
u8* jm_scrbar(void) asm("_ZN2Tz6Jiminy15GetScrBarSeqTblEv");
s32 func_0028f930(s32) asm("func_0028f930");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void Tz__Jiminy__CreateCover(void) asm("Tz__Jiminy__CreateCover");
void pz_cfo(void*, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz5Pause16CreateFadeObjectEz");
void obj_xyoff(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void mc_as(void*, void*) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
void* lay_get(s32) asm("_ZN2Tz6Layout9getLayoutEv");
s32 yi_unit(void*, s32) asm("_ZN2YI6LAYOUT15GetSequenceUnitEi");
s32 yi_img(void*, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void func_0028bae0(s32, s32, s32, s32, u8*, s32, s32, u8*, s32) asm("func_0028bae0");
void sel_set(s32) asm("_ZN2Tz8Selector8SetStateEi");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f214 asm("D_0035f214");
struct Lay77 { u8 pad[40]; void* img; };
void Tz__JmMiniGame__ChkMGameInfo(void) asm("Tz__JmMiniGame__ChkMGameInfo");
void Tz__JmMiniGame__CreateList(void) asm("Tz__JmMiniGame__CreateList");
void Tz__JmMiniGame__AdjustPos(void) asm("Tz__JmMiniGame__AdjustPos");
void Tz__JmMiniGame__UpdateNewMark(void) asm("Tz__JmMiniGame__UpdateNewMark");
void Tz__JmMiniGame__UpdateList(void) asm("Tz__JmMiniGame__UpdateList");
void func_002a8748(void) asm("func_002a8748");
void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("Tz__Select__SetItem");
void* sel_item(s32, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
void Tz__Select__SetSelectMax(s32, s32) asm("Tz__Select__SetSelectMax");
void Tz__Select__SetCurrent(s32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_0028afd0(s32, s32) asm("func_0028afd0");
void jm_hide(s32) asm("_ZN2Tz6Jiminy13SetHideCursorEb");
void sel_dis(s32, s32) asm("_ZN2Tz6Select16SetDisableButtonEj");
void Tz__Select__SetPageMode(s32, s32) asm("Tz__Select__SetPageMode");
void func_0028b248(s32, s32) asm("func_0028b248");
extern s32 D_0035f200 asm("D_0035f200");
extern s32* D_0035f600 asm("D_0035f600");
static inline s32 GetImg77(s32 i, void* self) { return yi_img(self, i); }
/*TARGET 002a77a0*/
void Tz__JmMiniGame__Setup(void) asm("Tz__JmMiniGame__Setup");
void Tz__JmMiniGame__Setup(void) {
    u8* par = jm_parent();
    u8* seq = jm_seqtbl();
    if (!func_0028f930(0)) func_0028f4d8(0, -1, 0);
    s16 h[4];
    for (s32 i = 0; i < 4; i++) h[i] = 2;
    Tz__JmMiniGame__ChkMGameInfo();
    s32 n = D_0035f3d4 - 1;
    Tz__Jiminy__CreateCover();
    pz_cfo(seq, n, D_0035f14c, D_0035f148, D_0035f210, 101, -1, 0);
    u8* seq2 = seq + 1224;
    obj_xyoff(seq);
    mc_as(seq, par);
    pz_cfo(seq2, n, D_0035f14c, D_0035f148, D_0035f210, 109, -1, 0);
    obj_xyoff(seq2);
    mc_as(seq2, par);
    Tz__Select__SetItem(D_0035f200, 0, D_0035f14c, D_0035f148, D_0035f210, -1, h, h);
    void* it = sel_item(D_0035f200, 0);
    obj_xyoff(it);
    mc_as(it, seq);
    Tz__JmMiniGame__CreateList();
    s32 n2 = D_0035f3d4;
    s32 pg = *D_0035f600 - 10;
    if (pg > 0) pg = pg + 1; else pg = 1;
    s32 u = yi_unit(lay_get(D_0035f210), D_0035f14c);
    Lay77* lay = (Lay77*)lay_get(D_0035f210);
    s32 im = GetImg77(D_0035f148, lay->img);
    func_0028bae0(D_0035f214, n2, u, im, jm_scrbar(), *D_0035f600, 10, seq2, 0);
    Tz__Select__SetSelectMax(D_0035f200, pg);
    Tz__Select__SetCurrent(D_0035f200, 0, 0, -1, -1);
    func_0028afd0(D_0035f200, 0);
    jm_hide(1);
    sel_dis(D_0035f200, 16);
    if (pg >= 2) {
        Tz__Select__SetPageMode(D_0035f200, 1);
        func_0028b248(D_0035f200, 10);
    }
    Tz__JmMiniGame__AdjustPos();
    Tz__JmMiniGame__UpdateNewMark();
    Tz__JmMiniGame__UpdateList();
    func_002a8748();
    sel_set(0);
}
}  // namespace n002a77a0

// 002a7a60 (was src/anon/batch_w1262.cpp)
namespace n002a7a60 {
// 0x00283d00: definition moved into src/anon/unit_00282c68.cpp



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
void Tz__Jiminy__SetParentSeqNum(s32 a, s32 b) asm("Tz__Jiminy__SetParentSeqNum");
void Tz__Jiminy__LoadData(s32 a) asm("Tz__Jiminy__LoadData");
void func_002925c0(void) asm("func_002925c0");
void func_002995e8(void) asm("func_002995e8");
s32 func_00276398(void) asm("func_00276398");
void func_00275b60(void) asm("func_00275b60");
void func_00287c90(s32 a) asm("func_00287c90");
s32 func_00242848(s32 a) asm("func_00242848");
void Tz__SelHist__FadeOut(s32 a) asm("Tz__SelHist__FadeOut");
void Tz__Jiminy__FadeOutHelp(void) asm("Tz__Jiminy__FadeOutHelp");
s32 func_0028b038(void *s) asm("func_0028b038");
void func_002765e8(s32 a, s32 b, s32 c) asm("func_002765e8");
void func_00287c00(s32 m) asm("func_00287c00");
void func_00287cc0(s32 s) asm("func_00287cc0");
void func_00287da0(void) asm("func_00287da0");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
extern void *D_0035f200 asm("D_0035f200");
s32 func_0028acc8(void *s) asm("func_0028acc8");
int func_0028af18(void *s, u32 a) asm("func_0028af18");
s32 func_00289310(void *s) asm("func_00289310");
s32 func_00287df0(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_002891e8(void *s) asm("func_002891e8");
void Tz__JmReport__Setup(void) asm("Tz__JmReport__Setup");
void Tz__JmMiniGame__LeaveAll(void) asm("Tz__JmMiniGame__LeaveAll");
void func_002a7758(void) asm("func_002a7758");
/*TARGET 002a7a60*/
void Tz__JmMiniGame__Control(void) asm("Tz__JmMiniGame__Control");
void Tz__JmMiniGame__Control(void)
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
      if (mode || D_0035f200)
      {
        func_00287f90(0);
        Tz__JmMiniGame__LeaveAll();
        return;
      }
      else
      {
        func_00287f90(0);
        Tz__JmMiniGame__LeaveAll();
        return;
      }
    }
    if (func_00292630())
    {
      return;
    }
    Tz__JmMiniGame__LeaveAll();
    func_00287c30();
    mode = func_00287bc0();
    func_0028af18(D_0035f200, 115);
    func_00276690(0);
    Tz__Jiminy__SetParentSeqNum(func_00276358(), 0);
    Tz__Jiminy__LoadData(mode);
    func_002925c0();
    if (mode == 13)
    {
      func_002995e8();
    }
    else
      if (mode == 2)
    {
      Tz__JmReport__Setup();
    }
    return;
  }
  if ((cur != (-1)) || func_00289310(D_0035f200))
  {
    if (!func_00276398())
    {
      Tz__Jiminy__SetParentSeqNum(0, 2);
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
        Tz__SelHist__FadeOut(0);
        func_002a7758();
        Tz__Jiminy__FadeOutHelp();
        Tz__Jiminy__SetParentSeqNum(1, 1);
        func_00287c00((mode == 0x24) ? (13) : (2));
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
}  // namespace n002a7a60

// 002a7d10 (was src/anon/batch_w66.cpp)
namespace n002a7d10 {
s32 func_00287bc0(void) asm("func_00287bc0");
// 0x0027c118: definition moved into src/anon/unit_0027a6d8.cpp
// ---- 002a7d10
struct E2a7 { s16 a, b; };
struct T2a7 { s32 n; E2a7 e[1]; };
extern T2a7* D_0035f600 asm("D_0035f600");
extern u32 D_0035f200 asm("D_0035f200");
s8* func_00276568(void) asm("func_00276568");
s32 func_0028afa8(u32) asm("func_0028afa8");
void func_0028afd0(u32, s32) asm("func_0028afd0");
/*TARGET 002a7d10*/
// obj_set_signed18
void Tz__JmMiniGame__AdjustPos(void) asm("Tz__JmMiniGame__AdjustPos");
// obj_set_signed18
void Tz__JmMiniGame__AdjustPos(void) {
    s32 n;
    if (func_00287bc0() == 36) {
        n = 0;
    } else {
        s32 cnt = D_0035f600->n;
        s8 c = *func_00276568();
        s32 i;
        for (i = 0; i < cnt; i++) {
            E2a7* e = &D_0035f600->e[i];
            if (c == e->a && e->b < 0) break;
        }
        n = i;
        if (n >= func_0028afa8(D_0035f200)) n = func_0028afa8(D_0035f200) - 1;
    }
    func_0028afd0(D_0035f200, n);  // obj_set_signed18
}
}  // namespace n002a7d10

// 002a7dc8 (was src/anon/batch_w99.cpp)
namespace n002a7dc8 {
#ifndef QCOPY
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#endif
struct V13f6 {
    f32 x, y, z, w;
    V13f6() {}
    V13f6(const V13f6& o) { QCOPY(this, &o); }
    V13f6& operator=(const V13f6& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
    V13f6& operator*=(f32 s)
    {
        asm("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
            : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    V13f6& operator+=(const V13f6& o)
    {
        asm("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
            : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline V13f6 operator-(const V13f6& a, const V13f6& b)
{
    V13f6 r;
    asm("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V1791 {
    f32 x, y, z, w;
    V1791& operator=(const V1791& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline V1791 operator*(const V1791& v, f32 s)
{
    V1791 r;
    asm("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
    return r;
}
struct E2a7d { u16 id; u16 pad[2]; u16 h6; };
struct T2a7d { u32 pad[2]; s32 count; u32 pad2; E2a7d e[1]; };
struct P2a7d { s16 a; s16 b; };
struct O2a7d { s32 count; P2a7d e[64]; };
union U2a7d { O2a7d* p; u32 w; s16 h; };
extern U2a7d D_0035f600 asm("D_0035f600");
T2a7d* func_00294000(s32) asm("func_00294000");
void func_002fde18(void*, s32, u32) asm("func_002fde18");
u8* func_001d56c8(u16) asm("func_001d56c8");
s32 func_00276c18(void) asm("func_00276c18");
static inline bool Ge2a7d(u8 v) { return !(v < 2); }
/*TARGET 002a7dc8*/
// Builds the grouped index list for table 7.
void Tz__JmMiniGame__ChkMGameInfo(void) asm("Tz__JmMiniGame__ChkMGameInfo");
// Builds the grouped index list for table 7.
void Tz__JmMiniGame__ChkMGameInfo(void)
{
    s32 n = 0;
    s32 i = 0;
    T2a7d* t = func_00294000(7);
    E2a7d* es = t->e;
    func_002fde18(D_0035f600.p, 0, 260);
    for (; i < t->count; i++) {
        E2a7d* e = &es[i];
        if (Ge2a7d(*func_001d56c8(e->h6)) || func_00276c18()) {
            if (n == 0 || D_0035f600.p->e[n - 1].a != e->id) {
                D_0035f600.p->e[n].a = e->id;
                D_0035f600.p->e[n].b = -1;
                n++;
            }
            D_0035f600.p->e[n].a = *(volatile u16*)&e->id;
            D_0035f600.p->e[n].b = i;
            n++;
        }
    }
    D_0035f600.p->count = n;
}
}  // namespace n002a7dc8

// 002a7f20 (was src/anon/batch_w20.cpp)
namespace n002a7f20 {
u8* func_00294000(u32) asm("func_00294000");
/*TARGET 002a7f20*/
// 0x002a1f40: definition moved into src/anon/unit_002a1d38.cpp

u8* func_002a7f20(s32 i) asm("func_002a7f20");
// 0x002a1f40: definition moved into src/anon/unit_002a1d38.cpp

u8* func_002a7f20(s32 i) {
    u8* b = func_00294000(7) + 16;
    return b + i * 8;
}
}  // namespace n002a7f20

// 002a7f58 (was src/anon/batch_w3844_nsamam.cpp)
namespace n002a7f58 {
u8* func_002766d0(void) asm("func_002766d0");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
s32 func_0023aa78(u8*) asm("func_0023aa78");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
void func_00139620(u8*) asm("func_00139620");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
extern u8* D_0035f604 asm("D_0035f604");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f210 asm("D_0035f210");
/*TARGET 002a7f58*/
/* 002a7f58: sets up 10 rows of three sprites (two 436-byte items in D_0035f604's table at 872 bytes per row,
   plus one 408-byte item at w+0xa998), each placed from its parent and given draw flags 0x60000008. */
void Tz__JmMiniGame__CreateList(void) asm("Tz__JmMiniGame__CreateList");
/* 002a7f58: sets up 10 rows of three sprites (two 436-byte items in D_0035f604's table at 872 bytes per row,
   plus one 408-byte item at w+0xa998), each placed from its parent and given draw flags 0x60000008. */
void Tz__JmMiniGame__CreateList(void) {
    s32 i = 0;
    s32 off = 0;
    u8* w = func_002766d0();
    u32 flags = 0x60000000; /* top bits 29-30 = 3 */
    func_002fde18(D_0035f604 + 8720, 0, 320);
    s32 base = D_0035f3d4;
    u8* q = w + 0xa998;
    u8* a;
    for (; i < 10; i++) {
        a = D_0035f604 + off;
        func_0028d980(a, base, D_0035f14c, D_0035f148, D_0035f210, 108, -1, -1, 0);
        s32 x = func_0023aa78(a + 24);
        s32 y = func_0023aa18(a + 24);
        s32 z = func_0023aa38(a + 24);
        func_00139620(a);
        func_00138c68(a, 0, x * i);
        func_0028dcc0(a, w);
        *(s32*)(a + 428) = 3;
        u32 f = flags | 8; /* loop-invariant: hoisted after base+1/base+2 like the original */
        *(u32*)(a + 420) = f;
        func_00138c10(a, 2);
        a = D_0035f604 + off + 436;
        func_0028d980(a, base + 1, D_0035f14c, D_0035f148, D_0035f210, 2, -1, -1, 0);
        func_00139620(a);
        func_00138c68(a, y, z);
        func_0028dcc0(a, D_0035f604 + off);
        off += 872;
        *(s32*)(a + 428) = 3;
        *(u32*)(a + 420) = f;
        *(s32*)(a + 432) = 1;
        *(u8**)(a + 408) = D_0035f604 + i * 32 + 8720;
        func_0028d8c0(q, base + 2, D_0035f14c, D_0035f148, D_0035f210, 2, -1, 0);
        func_0028dcc0(q, a);
        q += 408;
    }
}
}  // namespace n002a7f58

// 002a81a8 (was src/anon/batch_wcx.cpp)
namespace n002a81a8 {
typedef void (*VFn)(u8*);
struct E436 { u8 d[436]; };
extern E436 (*D_0035f604b)[2] asm("D_0035f604");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
s32 func_00276a90(void) asm("func_00276a90");
void func_00276b90(void) asm("func_00276b90");
/*TARGET 002a81a8*/
s32 func_002a81a8(void) asm("func_002a81a8");
s32 func_002a81a8(void)
{
    for (s32 i = 0; i < 10; i++) {
        for (s32 j = 0; j < 2; j++) {
            if (u_call4_00139d78(&D_0035f604b[i][j])) {
                u8* o = D_0035f604b[i][j].d;
                (*(VFn*)(*(u8**)o + 20))(o);
            }
        }
    }
    if (!func_00276a90()) func_00276b90();
    return 0;
}
}  // namespace n002a81a8

// 002a8258 (was src/anon/batch_w66.cpp)
namespace n002a8258 {
// 0x0010b568: definition moved into src/anon/unit_0010b450.cpp
// ---- 0013793c
s32 func_00139d78(u8*) asm("func_00139d78");
struct VObj436 { void** vt; u8 pad[432]; };
extern VObj436 (*D_0035f604)[2] asm("D_0035f604");
void func_00276a18(void) asm("func_00276a18");
void func_00276b10(void) asm("func_00276b10");
/*TARGET 002a8258*/
void func_002a8258(void) asm("func_002a8258");
void func_002a8258(void) {
    for (s32 i = 0; i < 10; i++) {
        for (s32 j = 0; j < 2; j++) {
            if (func_00139d78((u8*)&D_0035f604[i][j])) {
                VObj436* o = &D_0035f604[i][j];
                ((void (*)(VObj436*))o->vt[5])(o);
            }
        }
    }
    func_00276a18();
    func_00276b10();
}
}  // namespace n002a8258

// 002a82f8 (was src/anon/batch_w1588.cpp)
namespace n002a82f8 {
s32 func_00289310(void) asm("func_00289310");
void Tz__JmMiniGame__UpdateNewMark(void) asm("Tz__JmMiniGame__UpdateNewMark");
void Tz__JmMiniGame__UpdateList(void) asm("Tz__JmMiniGame__UpdateList");
/*TARGET 002a82f8*/
void func_002a82f8(void) asm("func_002a82f8");
void func_002a82f8(void) {
    if (func_00289310()) {
        Tz__JmMiniGame__UpdateNewMark();
        Tz__JmMiniGame__UpdateList();
    }
}
}  // namespace n002a82f8

