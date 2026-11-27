// Linked unit 0x002588e8-0x0025da20 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/cmenu_pause.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tz/ui_accessors.hpp"
#include "../tozawa/item_info.hpp"
#include "../tozawa/multi_seq.hpp"
#include "../tozawa/party_info.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 002588e8 (was src/anon/batch_w1594.cpp)
namespace n002588e8 {
struct O25;
struct O25V { u8 pad[20]; void (*f)(O25*); };
struct O25 { O25V* vt; u8 pad[384]; s32 id; };
s32 func_00139d78(O25*) asm("func_00139d78");
void func_00138c10(O25*, s32) asm("func_00138c10");
void func_0028d8c0(O25*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
extern O25* D_0035f07c asm("D_0035f07c");
extern s32 D_0035f078 asm("D_0035f078");
/*TARGET 002588e8*/
void Tz__Pause__CreateBg(s32 a) asm("Tz__Pause__CreateBg");
void Tz__Pause__CreateBg(s32 a) {
    if (a >= 0) {
        if (!func_00139d78(D_0035f07c)) {
            func_0028d8c0(D_0035f07c, 30001, 0, 0, D_0035f078, a, -1, 0);
            return;
        }
        if (D_0035f07c->id != a) {
            func_00138c10(D_0035f07c, a);
        }
    } else if (func_00139d78(D_0035f07c)) {
        D_0035f07c->vt->f(D_0035f07c);
    }
}
}  // namespace n002588e8

// 002589b0 (was src/anon/batch_w1590.cpp)
namespace n002589b0 {
struct W1590Obj;
struct W1590VT { void* f[5]; void (*fn)(W1590Obj*); };
struct W1590Obj { W1590VT* vt; };
s32 func_00139d78(W1590Obj*) asm("func_00139d78");
extern W1590Obj* D_0035f078 asm("D_0035f078");
extern W1590Obj* D_0035f07c asm("D_0035f07c");
/*TARGET 002589b0*/
void func_002589b0(void) asm("func_002589b0");
void func_002589b0(void) {
    if (D_0035f07c && func_00139d78(D_0035f07c)) {
        D_0035f07c->vt->fn(D_0035f07c);
    }
    if (D_0035f078 && func_00139d78(D_0035f078)) {
        D_0035f078->vt->fn(D_0035f078);
    }
}
}  // namespace n002589b0

// 00258a30 (was src/anon/batch_w29.cpp)
namespace n00258a30 {
u32 func_00139d78(u32) asm("func_00139d78");
extern u32 D_0035f07c asm("D_0035f07c");
extern u32 D_0035f078 asm("D_0035f078");
/*TARGET 00258a30*/
u32 func_00258a30(void) asm("func_00258a30");
u32 func_00258a30(void) {
    u32 r = 0;
    if (D_0035f07c) r = func_00139d78(D_0035f07c) != 0;
    if (!r && D_0035f078) r = func_00139d78(D_0035f078) != 0;
    return r;
}
}  // namespace n00258a30

// 00258a88 (was src/anon/batch_w7.cpp)
namespace n00258a88 {
u32 func_002537c8(u32) asm("func_002537c8");
void func_0023fa08(u32, u32) asm("func_0023fa08");
extern u32 D_0035f074 asm("D_0035f074");
/*TARGET 00258a88*/
void func_00258a88(void) asm("func_00258a88");
void func_00258a88(void) {
    func_0023fa08(D_0035f074, func_002537c8(0));
}
}  // namespace n00258a88

// 00258ab0 (was gap)
namespace n00258ab0 {
extern u8 D_0035f070 asm("D_0035f070");
extern u8 D_0035f0b0 asm("D_0035f0b0");
extern u8 D_0035f0b1 asm("D_0035f0b1");
extern u8 D_0035f0b2 asm("D_0035f0b2");
extern u32 D_0035eca4 asm("D_0035eca4");
extern u32 D_0035f64c asm("D_0035f64c");
extern u8 D_00372f20[] asm("D_00372f20");
extern u8 D_00372eb8[] asm("D_00372eb8");
void func_002b4ac8(s32, s32) asm("func_002b4ac8");
void func_002b4ae0(s32) asm("func_002b4ae0");
void func_002b4af0(void*) asm("func_002b4af0");
void func_00258ce8(void*) asm("func_00258ce8");
void Tz__CmSLBase__Init() asm("Tz__CmSLBase__Init");
void func_002420d8(u32, s32) asm("func_002420d8");
u8* func_00103eb0() asm("func_00103eb0");
void TASK_MANAGER__create_thread(u32, u32, u32, u32, u32) asm("TASK_MANAGER__create_thread");
void func_0014a248() asm("func_0014a248");
void func_002b47a0() asm("func_002b47a0");
s32 YS__CACHE_BUFF__IsFlushing() asm("YS__CACHE_BUFF__IsFlushing");
void func_00170888(u32) asm("func_00170888");
void func_00253818(s32) asm("func_00253818");
void Tz__CmComm__DataLoad(s32) asm("Tz__CmComm__DataLoad");
void Tz__CmComm__DataLoadWait(s32, u32) asm("Tz__CmComm__DataLoadWait");
void func_002b63a8() asm("_ZN2Tz8CmSLBase11SetLeadDataEv");
void func_0014a238() asm("func_0014a238");
void func_00102448(u32, s32) asm("func_00102448");
void Tz__CmSave__Setup() asm("Tz__CmSave__Setup");
void func_00242618(s32, s32) asm("func_00242618");
void YI__IMAGE_CACHE__Clear() asm("YI__IMAGE_CACHE__Clear");
void func_00236148() asm("func_00236148");
s32 func_00259c60() asm("func_00259c60");
void Tz__CmSave__Draw() asm("Tz__CmSave__Draw");
void func_002b6298(u32) asm("func_002b6298");
void func_00233e70(s32) asm("func_00233e70");
s32 func_00233e60() asm("func_00233e60");
void Tz__CmLoad__Setup() asm("Tz__CmLoad__Setup");
s32 Tz__CmLoad__Control() asm("Tz__CmLoad__Control");
void Tz__CmLoad__Draw() asm("Tz__CmLoad__Draw");
s64 func_00287bc0_l() asm("func_00287bc0");
s32 func_0028b040(u32) asm("func_0028b040");
struct E32 { u32 a, b, flags; u8 pad[20]; };
E32* func_00241f10() asm("func_00241f10");
void func_002598b8(u32) asm("func_002598b8");
void func_0025d7f8(u32) asm("func_0025d7f8");

void func_00258ab0() asm("func_00258ab0");
void func_00258ab0() { D_0035f070 = 1; }

}  // namespace n00258ab0

// 00258ac0 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n00258ac0 {
u32 func_00139d78(u32, u32, u32, u32) asm("_Z13func_00139d78jjjj");
/*TARGET 00258ac0*/
u32 func_00258ac0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00258ac0jjjj");
u32 func_00258ac0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = (u32)(0x0036u << 16);
    r4 = *(u32*)((u32)r16 + (s32)(-3976));
    r2 = func_00139d78(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r16 + (s32)(-3976));
    return r2;
}
}  // namespace n00258ac0

// 00258af0 (was src/tozawa/cmenu_pause.cpp)
namespace Tz { // method 00258af0
extern u32 D_0035f068 asm("D_0035f068");
/*TARGET 00258af0*/
void Pause::SetNextMenu(s32 nextMenu) {
    *(u16*)((u32)&D_0035f068 + 6) = (u16)nextMenu;
}
}  // Tz

// 00258b00 (was src/anon/tiny_wrappers_more80_relaxed.cpp)
namespace n00258b00 {
u32 func_00138480(u32, u32, u32, u32) asm("_Z13func_00138480jjjj");
extern u8 D_00360000 asm("D_00360000");
/*TARGET 00258b00*/
u32 func_00258b00(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00258b00jjjj");
u32 func_00258b00(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)((u32)&D_00360000) - 3968u) = (u32)(a0);
    *(u32*)((u32)((u32)&D_00360000) - 3964u) = (u32)(a1);
    return func_00138480(0x00000000u, a1, a2, a3);
}
}  // namespace n00258b00

// 00258b28 (was src/anon/batch_w1666.cpp)
namespace n00258b28 {
extern u8 D_0035f06b asm("D_0035f06b");
/*TARGET 00258b28*/
void func_00258b28(s32 a) asm("func_00258b28");
void func_00258b28(s32 a) { D_0035f06b = a; }
}  // namespace n00258b28

// 00258b38 (was src/tozawa/cmenu_pause.cpp)
namespace Tz { // method 00258b38
u32 func_00139d78(u32) asm("func_00139d78");
extern u32 D_0035f088 asm("D_0035f088");
extern u32 D_0035f078 asm("D_0035f078");
extern u32 D_0035f08c asm("D_0035f08c");
/*TARGET 00258b38*/
void Pause::StartFade(void (*cb)()) {
    u32 s1 = (u32)cb;
    func_00139d78((u32)D_0035f088);
    CreateFadeObject((u32)D_0035f088, 30036, 0, 0, D_0035f078, 5, 1, 0);
    u32 t6 = (u32)D_0035f088 + 24;
    u32 t7 = *(u32*)(t6 + 184);
    t7 |= 8u;
    *(u32*)(t6 + 184) = t7;
    *(u8*)((u32)D_0035f088 + 405) = 1;
    D_0035f08c = s1;
}
}  // Tz

// 00258bc0 (was src/tozawa/cmenu_pause.cpp)
namespace Tz { // method 00258bc0
u32 func_00139d78(u32) asm("func_00139d78");
void func_00138c10(u32, u32) asm("func_00138c10");
extern u32 D_0035f088 asm("D_0035f088");
extern u32 D_0035f08c asm("D_0035f08c");
/*TARGET 00258bc0*/
void Pause::EndFade(void (*cb)()) {
    u32 s1 = (u32)cb;
    func_00139d78((u32)D_0035f088);
    func_00138c10((u32)D_0035f088, 4);
    *(s32*)((u32)D_0035f088 + 392) = -1;
    D_0035f08c = s1;
}
}  // Tz

// 00258c18 (was src/tozawa/cmenu_pause.cpp)
namespace Tz { // method 00258c18
u32 func_00139d78(u32) asm("func_00139d78");
extern u32 D_0035f088 asm("D_0035f088");
/*TARGET 00258c18*/
u32 Pause::isExistFade() {
    u32 r14 = D_0035f088;
    u32 r2 = 0u;
    if (r14 != 0u) {
        r2 = func_00139d78(r14);
    }
    return r2;
}
}  // Tz

// 00258c48 (was src/tozawa/cmenu_pause.cpp)
namespace Tz { // method 00258c48
u32 func_00139d78(u32) asm("func_00139d78");
/*TARGET 00258c48*/
u32 Pause::isLoopFade() {
    u32 r16 = (u32)(0x0036u << 16);
    u32 r4 = *(u32*)((u32)r16 + (s32)(-3960));
    u32 r2 = func_00139d78(r4);
    u32 r15 = *(u32*)((u32)r16 + (s32)(-3960));
    r2 = *(u32*)((u32)r15 + (s32)(388));
    r2 = (u32)(r2 ^ 0x0001u);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
}  // Tz

// 00258c80 (was src/anon/auto80_199_queue.cpp)
namespace n00258c80 {
/*TARGET 00258c80*/
void func_00258c80(void) asm("_Z13func_00258c80v");
void func_00258c80(void) {
    if (D_0035f08c != 0) {
        if (func_00139d78(D_0035f088) != 0) {
            if (func_00258c48() == 0) {
                return;
            }
        }

        ((void(*)(void))D_0035f08c)();
        D_0035f08c = 0;
    }
}
}  // namespace n00258c80

// 00258cd8 (was src/tozawa/cmenu_pause.cpp)
namespace Tz { // method 00258cd8
extern u32 D_0035f068 asm("D_0035f068");
/*TARGET 00258cd8*/
bool Pause::isPause() {
    s32 v = *(s8*)&D_0035f068;
    return v != 0;
}
}  // Tz

// 00258ce8 (was src/anon/batch_w30.cpp)
namespace n00258ce8 {
// int_to_float_scaled
extern u16 D_0035f0a8[3] asm("D_0035f0a8");
/*TARGET 00258ce8*/
void func_00258ce8(u16* a) asm("func_00258ce8");
void func_00258ce8(u16* a) {
    if (!a) {
        D_0035f0a8[0] = 0x9fcf;
        D_0035f0a8[1] = 0x9fd0;
        D_0035f0a8[2] = 0x9fd1;
        return;
    }
    u16* d = D_0035f0a8;
    s32 i;
    for (i = 2; i >= 0; i--) {
        *d++ = *a++;
    }
}
}  // namespace n00258ce8

// 00258d40 (was src/anon/tiny_more2.cpp)
namespace n00258d40 {
extern u32 D_0035f090 asm("D_0035f090");
extern u32 D_0035f094 asm("D_0035f094");
/*TARGET 00258d40*/
void func_00258d40(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_00258d40jjjj");
void func_00258d40(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; *(u16*)&D_0035f090=(u16)a0; *(u16*)&D_0035f094=(u16)a1; }
}  // namespace n00258d40

// 00258d58 (was src/anon/batch_w2.cpp)
namespace n00258d58 {
extern s16 D_0035f090 asm("D_0035f090");
extern s16 D_0035f092 asm("D_0035f092");
extern s16 D_0035f096 asm("D_0035f096");
/*TARGET 00258d58*/
void func_00258d58(s32 a, s32 b, s32 c) asm("func_00258d58");
void func_00258d58(s32 a, s32 b, s32 c) {
    D_0035f090 = a;
    D_0035f092 = b;
    D_0035f096 = c;
}
}  // namespace n00258d58

// 00258d78 (was src/anon/batch_w65.cpp)
namespace n00258d78 {
void func_00258d40(u32, u32) asm("func_00258d40");
void func_00258d58(u32, u32, u32) asm("func_00258d58");
/*TARGET 00258d78*/
void func_00258d78(u32 a, u32 b, u32 c, u32 d) asm("func_00258d78");
void func_00258d78(u32 a, u32 b, u32 c, u32 d) {
    func_00258d40(a, c);
    func_00258d58(a, b, d);
}
}  // namespace n00258d78

// 00258dc8 (was src/anon/batch_w8.cpp)
namespace n00258dc8 {
extern s16 D_0035f090 asm("D_0035f090");
extern s16 D_0035f092 asm("D_0035f092");
extern s16 D_0035f094 asm("D_0035f094");
extern s16 D_0035f096 asm("D_0035f096");
/*TARGET 00258dc8*/
void func_00258dc8(void) asm("func_00258dc8");
void func_00258dc8(void) {
    D_0035f090 = -1;
    D_0035f092 = -1;
    D_0035f094 = -1;
    D_0035f096 = -1;
}
}  // namespace n00258dc8

// 00258df0 (was src/anon/batch_w1594.cpp)
namespace n00258df0 {
u32 func_002424a0(void) asm("func_002424a0");
void func_0028e560(s32, u16*, s32, s32) asm("func_0028e560");
extern u16 D_0035f090 asm("D_0035f090");
extern u16 D_0035f094 asm("D_0035f094");
void Tz__CmComm__SetDrawMunnies(s32 a) asm("_Z12func_00258df0i");
/*TARGET 00258df0*/
void Tz__CmComm__SetDrawMunnies(s32 a) asm("_Z12func_00258df0i");
void Tz__CmComm__SetDrawMunnies(s32 a) {
    u16 buf[6];
    s32 i;
    for (i = 5; i >= 0; i--) buf[5 - i] = D_0035f090;
    u32 v = func_002424a0();
    for (i = 0; i < 6; i++) {
        u32 d = v % 10;
        v = v / 10;
        if (i != 0 && d == 0 && v == 0) break;
        buf[i] = d + D_0035f094;
    }
    func_0028e560(a, buf, 6, -1);
}
}  // namespace n00258df0

// 00258eb8 (was src/anon/batch_w1601.cpp)
namespace n00258eb8 {
// ---- b3.cpp
extern u16 D_0035f090 asm("D_0035f090");
extern u16 D_0035f092 asm("D_0035f092");
extern u16 D_0035f096 asm("D_0035f096");
void func_0014cbe0(u32*, u32*, u32*, u32*) asm("func_0014cbe0");
void func_0028e560(s32, u16*, s32, s32) asm("func_0028e560");
void func_00258eb8_i(s32 a) asm("_Z23Tz__CmComm__SetDrawTimei");
/*TARGET 00258eb8*/
void func_00258eb8_i(s32 a) asm("_Z23Tz__CmComm__SetDrawTimei");
void func_00258eb8_i(s32 a)
{
  u16 buf[16];
  u32 h, m, s, f;
  s32 i, j, n;
  u16* p = buf;
  for (i = 8; i >= 0; i--) *p++ = D_0035f090;
  func_0014cbe0(&h, &m, &s, &f);
  n = 0;
  for (i = 0; i < 2; i++) {
    u32 v, lead; s32 nd;
    if (i == 0) { v = m; nd = 2; lead = *(volatile u32*)&h; } else { v = h; lead = 0; nd = 3; }
    if (i != 0) buf[n++] = D_0035f092;
    for (j = 0; j < nd; j++) {
      u32 r = v % 10;
      v = v / 10;
      if (i != 0 && j != 0 && r == 0 && v == 0 && lead == 0) break;
      buf[n++] = r + D_0035f096;
    }
    if (j < nd) break;
  }
  func_0028e560(a, buf, 9, -1);
}
}  // namespace n00258eb8

// 00259020 (was src/anon/auto80_199_queue.cpp)
namespace n00259020 {
/*TARGET 00259020*/
void func_00259020(
    u32 a0,
    u32 a1,
    u32 a2,
    u32 a3,
    u32 a4,
    u32 a5,
    u32 a6,
    u32 a7
) asm("_Z13func_00259020jjjjjjjj");
void func_00259020(
    u32 a0,
    u32 a1,
    u32 a2,
    u32 a3,
    u32 a4,
    u32 a5,
    u32 a6,
    u32 a7
) {
    u32 s0 = a0;
    u32 s1 = a1;

    func_0028e0d8(s0, a2, a3, a4, a5, a6, a7);

    func_001395e8(s0);
    func_00139610(s0);
    Tz__MultiSeq__setParamXYToOffset(s0, s1);
    func_0028e710(s0, s1);
    func_00139660(s0);
    func_00139688(s0);
    func_001396b0(s0);
    func_0028ebf0(s0, 3);
}
}  // namespace n00259020

// 002590b0 (was src/anon/auto80_199_queue.cpp)
namespace n002590b0 {
/*TARGET 002590b0*/
void func_002590b0(u32 a0) asm("_Z13func_002590b0j");
void func_002590b0(u32 a0) {
    u32 s0 = a0;

    Tz__LayMsg__create(s0);
    u32 v0 = func_0019f880(-1, -1);
    func_0023f618(s0, v0);
    func_001395f8(s0);
    func_0023f6c0(s0, 1);
    func_0023f688(s0, 1);
}
}  // namespace n002590b0

// 00259108 (was src/anon/batch_w1606.cpp)
namespace n00259108 {
void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, u16*, u16*) asm("Tz__Select__SetItem");
u8* func_002891b8(s32, s32) asm("func_002891b8");
s32 func_0023aa78(u8*) asm("func_0023aa78");
s32 func_0023aa98(u8*) asm("func_0023aa98");
void Tz__Select__SetExOffset(s32, s32, s32, s32) asm("Tz__Select__SetExOffset");
void func_00139620(u8*) asm("func_00139620");
void func_0028af28(s32, s32) asm("func_0028af28");
void Tz__Select__SetCurrent(s32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void Tz__Select__SetSelectMax(s32, s32) asm("Tz__Select__SetSelectMax");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u16 D_0035f098[2][4] asm("D_0035f098");
extern u16 D_0035f0a8[] asm("D_0035f0a8");
/*TARGET 00259108*/
void Tz__CmComm__CreateConfirmSelector(s32 o, s32 id, s32 a2, s32 a3, s32 a4, s32 two, u16* src) asm("Tz__CmComm__CreateConfirmSelector");
void Tz__CmComm__CreateConfirmSelector(s32 o, s32 id, s32 a2, s32 a3, s32 a4, s32 two, u16* src) {
    u32 vals[2];
    s32 sid = id;
    s32 b2 = a2;
    s32 b3 = a3;
    s32 save = D_0035f3d4;
    D_0035f3d4 = id < 0 ? save : id;
    s32 kind = 64;
    s32 n;
    s32 i;
    if (two == 0) {
        n = 1;
        vals[0] = D_0035f0a8[0];
        kind = 67;
    } else {
        n = 2;
        vals[0] = D_0035f0a8[2];
        vals[1] = D_0035f0a8[1];
    }
    for (i = 0; i < 2; i++) {
        s32 k;
        for (k = 0; k < 3; k++) D_0035f098[i][k] = src[k];
        D_0035f098[i][3] = 0xffff;
        if (i + 1 >= 2) D_0035f098[i][2] = src[3];
    }
    for (i = 0; i < n; i++) {
        Tz__Select__SetItem(o, i, b2, b3, a4, vals[i] | 0x8000, D_0035f098[0], D_0035f098[1]);
        s32 x = func_0023aa78(func_002891b8(o, i) + 24);
        s32 y = func_0023aa98(func_002891b8(o, i) + 24);
        Tz__Select__SetExOffset(o, i, x, 0);
        func_00139620(func_002891b8(o, i));
        *(s32*)(func_002891b8(o, i) + 432) = 2;
        u8* p = func_002891b8(o, i);
        *(s32*)(p + 412) = y;
        *(s32*)(p + 416) = 0;
    }
    func_0028af28(o, kind);
    Tz__Select__SetCurrent(o, 0, 1, 0, 2);
    Tz__Select__SetSelectMax(o, -1);
    if (sid >= 0) D_0035f3d4 = save;
}
}  // namespace n00259108

// 00259350 (was src/anon/batch_w47.cpp)
namespace n00259350 {
s32 func_002538f8(u32) asm("func_002538f8");
// entry16_get_flag_bit
s32 func_00253928(u32) asm("func_00253928");
// entry16_get_bit1
s32 func_00253918(void) asm("func_00253918");
s32 Tz__CMData__BackRead(u32, s32) asm("Tz__CMData__BackRead");
/*TARGET 00259350*/
s32 Tz__CmComm__DataLoad(u32 a) asm("Tz__CmComm__DataLoad");
s32 Tz__CmComm__DataLoad(u32 a) {
    if (func_002538f8(a)) return 1;
    if (func_00253928(a)) return 1;
    if (func_00253918()) return 0;
    return Tz__CMData__BackRead(a, 0) == 0;
}
}  // namespace n00259350

// 002593b8 (was src/anon/batch_w1592.cpp)
namespace n002593b8 {
s32 func_002538f8(void*) asm("func_002538f8");
s32 func_00253928(void*) asm("func_00253928");
s32 func_00253918(void) asm("func_00253918");
s32 Tz__CMData__BackRead(void*, s32) asm("Tz__CMData__BackRead");
void func_00102448(void*, s32) asm("func_00102448");
/*TARGET 002593b8*/
s32 Tz__CmComm__DataLoadWait(void* a, void* t) asm("Tz__CmComm__DataLoadWait");
s32 Tz__CmComm__DataLoadWait(void* a, void* t) {
    if (func_002538f8(a)) return 1;
    if (!func_00253928(a)) {
    top:
        if (!func_00253918() && !Tz__CMData__BackRead(a, 0)) goto out;
        func_00102448(t, 0); goto top;
    }
out:
    if (!func_002538f8(a)) { func_00102448(t, 0); goto out; }
    return 1;
}
}  // namespace n002593b8

// 00259460 (was src/anon/batch_w1756.cpp)
namespace n00259460 {
struct E6_w1756 { s16 id; s16 a; s16 b; };
extern E6_w1756 D_00372b50[] asm("D_00372b50");
/*TARGET 00259460*/
s32 func_00259460(s32 id, u8 f) asm("func_00259460");
s32 func_00259460(s32 id, u8 f)
{
    s32 r = 11;
    s32 i;
    for (i = 0; D_00372b50[i].id >= 0; i++) {
        if (D_00372b50[i].id == id) {
            if (f) r = D_00372b50[i].b; else r = D_00372b50[i].a;
            break;
        }
    }
    return r;
}
}  // namespace n00259460

// 002594b8 (was src/anon/batch_w31.cpp)
namespace n002594b8 {
// 0022c4b8: moved to src/sasa/event_layout.cpp (linked unit)

struct KV { s16 k; u16 v; };
extern KV D_00372be0[] asm("D_00372be0");
/*TARGET 002594b8*/
// Map key to value through a table terminated by a negative key; -1 if absent.
int func_002594b8(int k) asm("func_002594b8");
// Map key to value through a table terminated by a negative key; -1 if absent.
int func_002594b8(int k) {
    int r = -1;
    for (s32 i = 0; D_00372be0[i].k >= 0; i++) {
        if (D_00372be0[i].k == k) {
            r = D_00372be0[i].v;
            break;
        }
    }
    return r;
}
}  // namespace n002594b8

// 00259510 (was src/anon/batch_w41.cpp)
namespace n00259510 {
struct W41KV { s16 key, val; };
extern W41KV D_00372c30[] asm("D_00372c30");
/*TARGET 00259510*/
s32 func_00259510(s32 k) asm("func_00259510");
s32 func_00259510(s32 k) {
    s32 r = 11;
    for (s32 i = 0; D_00372c30[i].key != -1; i++) {
        if (D_00372c30[i].key == k) { r = D_00372c30[i].val; break; }
    }
    return r;
}
}  // namespace n00259510

// 00259570 (was src/anon/batch_w55.cpp)
namespace n00259570 {
u32 func_00259460(u32, u8) asm("func_00259460");
void func_002595b8(u32, u32, u8) asm("func_002595b8");
/*TARGET 00259570*/
void func_00259570(u32 a, u32 b, u8 c, u8 d) asm("func_00259570");
void func_00259570(u32 a, u32 b, u8 c, u8 d) {
    func_002595b8(func_00259460(a, c), b, d);
}
}  // namespace n00259570

// 002595b8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002595b8 {
/*TARGET 002595b8*/
u32 func_002595b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002595b8jjjj");
u32 func_002595b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)((s32)0u + (9));
    *(u8*)((u32)r5 + (s32)(1)) = (u8)r4;
    *(u8*)((u32)r5 + (s32)(0)) = (u8)r15;
    r6 = (u32)(r6 & 0x00ffu);
    r2 = r5;
    if (r6 != 0u) {
        *(u8*)((u32)r5 + (s32)(2)) = (u8)0u;
    }
    return r2;
}
}  // namespace n002595b8

// 002595e0 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 002595e0
/*TARGET 002595e0*/
s64 CmComm::GetIconMsgSize() { return 2; }
}  // Tz

// 002595e8 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n002595e8 {
u32 func_00192c90(u32, u32, u32, u32) asm("_Z13func_00192c90jjjj");
/*TARGET 002595e8*/
u32 func_002595e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002595e8jjjj");
u32 func_002595e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r4 = r5;
    r5 = r16;
    r2 = func_00192c90(r4, r5, r6, r7);
    r2 = r16;
    return r2;
}
}  // namespace n002595e8

// 00259618 (was src/anon/auto80_199_queue.cpp)
namespace n00259618 {
/*TARGET 00259618*/
u32 func_00259618(u32 a0, u32 a1, u32 a2) asm("_Z13func_00259618jjj");
u32 func_00259618(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a2 & 0xff;
    u32 s1 = a0;
    u32 s2 = a1;

    u8* p = func_001a80c8(s1);  // table24_find_by_id

    s32 a2v = -1;
    if (s0 != 0) {
        a2v = (s32)func_00259460((u32)p[2], s0);
    }

    YS__ITEM__MakeMessage(s2, s1, a2v);
    return s2;
}
}  // namespace n00259618

// 00259680 (was gap)
namespace n00259680 {
extern u8 D_0035f070 asm("D_0035f070");
extern u8 D_0035f0b0 asm("D_0035f0b0");
extern u8 D_0035f0b1 asm("D_0035f0b1");
extern u8 D_0035f0b2 asm("D_0035f0b2");
extern u32 D_0035eca4 asm("D_0035eca4");
extern u32 D_0035f64c asm("D_0035f64c");
extern u8 D_00372f20[] asm("D_00372f20");
extern u8 D_00372eb8[] asm("D_00372eb8");
void func_002b4ac8(s32, s32) asm("func_002b4ac8");
void func_002b4ae0(s32) asm("func_002b4ae0");
void func_002b4af0(void*) asm("func_002b4af0");
void func_00258ce8(void*) asm("func_00258ce8");
void Tz__CmSLBase__Init() asm("Tz__CmSLBase__Init");
void func_002420d8(u32, s32) asm("func_002420d8");
u8* func_00103eb0() asm("func_00103eb0");
void TASK_MANAGER__create_thread(u32, u32, u32, u32, u32) asm("TASK_MANAGER__create_thread");
void func_0014a248() asm("func_0014a248");
void func_002b47a0() asm("func_002b47a0");
s32 YS__CACHE_BUFF__IsFlushing() asm("YS__CACHE_BUFF__IsFlushing");
void func_00170888(u32) asm("func_00170888");
void func_00253818(s32) asm("func_00253818");
void Tz__CmComm__DataLoad(s32) asm("Tz__CmComm__DataLoad");
void Tz__CmComm__DataLoadWait(s32, u32) asm("Tz__CmComm__DataLoadWait");
void func_002b63a8() asm("_ZN2Tz8CmSLBase11SetLeadDataEv");
void func_0014a238() asm("func_0014a238");
void func_00102448(u32, s32) asm("func_00102448");
void Tz__CmSave__Setup() asm("Tz__CmSave__Setup");
void func_00242618(s32, s32) asm("func_00242618");
void YI__IMAGE_CACHE__Clear() asm("YI__IMAGE_CACHE__Clear");
void func_00236148() asm("func_00236148");
s32 func_00259c60() asm("func_00259c60");
void Tz__CmSave__Draw() asm("Tz__CmSave__Draw");
void func_002b6298(u32) asm("func_002b6298");
void func_00233e70(s32) asm("func_00233e70");
s32 func_00233e60() asm("func_00233e60");
void Tz__CmLoad__Setup() asm("Tz__CmLoad__Setup");
s32 Tz__CmLoad__Control() asm("Tz__CmLoad__Control");
void Tz__CmLoad__Draw() asm("Tz__CmLoad__Draw");
s64 func_00287bc0_l() asm("func_00287bc0");
s32 func_0028b040(u32) asm("func_0028b040");
struct E32 { u32 a, b, flags; u8 pad[20]; };
E32* func_00241f10() asm("func_00241f10");
void func_002598b8(u32) asm("func_002598b8");
void func_0025d7f8(u32) asm("func_0025d7f8");

u32 func_00259680(u32 a) asm("func_00259680");
u32 func_00259680(u32 a) { return a < 18; }

}  // namespace n00259680

// 00259690 (was src/anon/auto80_199_queue.cpp)
namespace n00259690 {
/*TARGET 00259690*/
u32 Tz__CmLoad__Init(void) asm("_Z16Tz__CmLoad__Initv");
u32 Tz__CmLoad__Init(void) {
    func_002b4ac8(0, 0);  // store_globals_two_b
    func_002b4ae0(19);  // store_global_word_b
    func_002b4af0((void*)&D_00372f20);  // store_global_word
    func_00258ce8((void*)&D_00372eb8);
    Tz__CmSLBase__Init();

    D_0035f0b0 = 1;
    D_0035f0b2 = 0;
    D_0035f0b1 = 0;

    u32 v0 = func_00103eb0();
    u32 a0 = *(u32*)(v0 + 4);
    return TASK_MANAGER__create_thread(a0, 0, 2000, (u32)&D_002598b8, 4096);
}
}  // namespace n00259690

// 00259710 (was src/anon/tiny_jal_tail_wrappers.cpp)
namespace n00259710 {
u32 func_0014a248() asm("_Z13func_0014a248v");
u32 func_002b47a0() asm("_Z13func_002b47a0v");
/*TARGET 00259710*/
u32 func_00259710(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00259710jjjj");
u32 func_00259710(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_0014a248();  // zero_global_byte_b
    return func_002b47a0();
}
}  // namespace n00259710

// 00259730 (was gap)
namespace n00259730 {
extern u8 D_0035f070 asm("D_0035f070");
extern u8 D_0035f0b0 asm("D_0035f0b0");
extern u8 D_0035f0b1 asm("D_0035f0b1");
extern u8 D_0035f0b2 asm("D_0035f0b2");
extern u32 D_0035eca4 asm("D_0035eca4");
extern u32 D_0035f64c asm("D_0035f64c");
extern u8 D_00372f20[] asm("D_00372f20");
extern u8 D_00372eb8[] asm("D_00372eb8");
void func_002b4ac8(s32, s32) asm("func_002b4ac8");
void func_002b4ae0(s32) asm("func_002b4ae0");
void func_002b4af0(void*) asm("func_002b4af0");
void func_00258ce8(void*) asm("func_00258ce8");
void Tz__CmSLBase__Init() asm("Tz__CmSLBase__Init");
void func_002420d8(u32, s32) asm("func_002420d8");
u8* func_00103eb0() asm("func_00103eb0");
void TASK_MANAGER__create_thread(u32, u32, u32, u32, u32) asm("TASK_MANAGER__create_thread");
void func_0014a248() asm("func_0014a248");
void func_002b47a0() asm("func_002b47a0");
s32 YS__CACHE_BUFF__IsFlushing() asm("YS__CACHE_BUFF__IsFlushing");
void func_00170888(u32) asm("func_00170888");
void func_00253818(s32) asm("func_00253818");
void Tz__CmComm__DataLoad(s32) asm("Tz__CmComm__DataLoad");
void Tz__CmComm__DataLoadWait(s32, u32) asm("Tz__CmComm__DataLoadWait");
void func_002b63a8() asm("_ZN2Tz8CmSLBase11SetLeadDataEv");
void func_0014a238() asm("func_0014a238");
void func_00102448(u32, s32) asm("func_00102448");
void Tz__CmSave__Setup() asm("Tz__CmSave__Setup");
void func_00242618(s32, s32) asm("func_00242618");
void YI__IMAGE_CACHE__Clear() asm("YI__IMAGE_CACHE__Clear");
void func_00236148() asm("func_00236148");
s32 func_00259c60() asm("func_00259c60");
void Tz__CmSave__Draw() asm("Tz__CmSave__Draw");
void func_002b6298(u32) asm("func_002b6298");
void func_00233e70(s32) asm("func_00233e70");
s32 func_00233e60() asm("func_00233e60");
void Tz__CmLoad__Setup() asm("Tz__CmLoad__Setup");
s32 Tz__CmLoad__Control() asm("Tz__CmLoad__Control");
void Tz__CmLoad__Draw() asm("Tz__CmLoad__Draw");
s64 func_00287bc0_l() asm("func_00287bc0");
s32 func_0028b040(u32) asm("func_0028b040");
struct E32 { u32 a, b, flags; u8 pad[20]; };
E32* func_00241f10() asm("func_00241f10");
void func_002598b8(u32) asm("func_002598b8");
void func_0025d7f8(u32) asm("func_0025d7f8");

void func_00259730() asm("func_00259730");
void func_00259730() {
    func_002b4ac8(0, 0);
    func_002b4ae0(19);
    func_002b4af0(D_00372f20);
    func_00258ce8(D_00372eb8);
    Tz__CmSLBase__Init();
    D_0035f0b0 = 1;
    D_0035f0b2 = 1;
    func_002420d8(D_0035eca4, 1);
    TASK_MANAGER__create_thread(*(u32*)(func_00103eb0() + 4), 0, 2000, (u32)func_002598b8, 4096);
}

}  // namespace n00259730

// 002597c0 (was gap)
namespace n002597c0 {
extern u8 D_0035f070 asm("D_0035f070");
extern u8 D_0035f0b0 asm("D_0035f0b0");
extern u8 D_0035f0b1 asm("D_0035f0b1");
extern u8 D_0035f0b2 asm("D_0035f0b2");
extern u32 D_0035eca4 asm("D_0035eca4");
extern u32 D_0035f64c asm("D_0035f64c");
extern u8 D_00372f20[] asm("D_00372f20");
extern u8 D_00372eb8[] asm("D_00372eb8");
void func_002b4ac8(s32, s32) asm("func_002b4ac8");
void func_002b4ae0(s32) asm("func_002b4ae0");
void func_002b4af0(void*) asm("func_002b4af0");
void func_00258ce8(void*) asm("func_00258ce8");
void Tz__CmSLBase__Init() asm("Tz__CmSLBase__Init");
void func_002420d8(u32, s32) asm("func_002420d8");
u8* func_00103eb0() asm("func_00103eb0");
void TASK_MANAGER__create_thread(u32, u32, u32, u32, u32) asm("TASK_MANAGER__create_thread");
void func_0014a248() asm("func_0014a248");
void func_002b47a0() asm("func_002b47a0");
s32 YS__CACHE_BUFF__IsFlushing() asm("YS__CACHE_BUFF__IsFlushing");
void func_00170888(u32) asm("func_00170888");
void func_00253818(s32) asm("func_00253818");
void Tz__CmComm__DataLoad(s32) asm("Tz__CmComm__DataLoad");
void Tz__CmComm__DataLoadWait(s32, u32) asm("Tz__CmComm__DataLoadWait");
void func_002b63a8() asm("_ZN2Tz8CmSLBase11SetLeadDataEv");
void func_0014a238() asm("func_0014a238");
void func_00102448(u32, s32) asm("func_00102448");
void Tz__CmSave__Setup() asm("Tz__CmSave__Setup");
void func_00242618(s32, s32) asm("func_00242618");
void YI__IMAGE_CACHE__Clear() asm("YI__IMAGE_CACHE__Clear");
void func_00236148() asm("func_00236148");
s32 func_00259c60() asm("func_00259c60");
void Tz__CmSave__Draw() asm("Tz__CmSave__Draw");
void func_002b6298(u32) asm("func_002b6298");
void func_00233e70(s32) asm("func_00233e70");
s32 func_00233e60() asm("func_00233e60");
void Tz__CmLoad__Setup() asm("Tz__CmLoad__Setup");
s32 Tz__CmLoad__Control() asm("Tz__CmLoad__Control");
void Tz__CmLoad__Draw() asm("Tz__CmLoad__Draw");
s64 func_00287bc0_l() asm("func_00287bc0");
s32 func_0028b040(u32) asm("func_0028b040");
struct E32 { u32 a, b, flags; u8 pad[20]; };
E32* func_00241f10() asm("func_00241f10");
void func_002598b8(u32) asm("func_002598b8");
void func_0025d7f8(u32) asm("func_0025d7f8");

void func_002597c0() asm("func_002597c0");
void func_002597c0() {
    func_0014a248();
    func_002b47a0();
    D_0035f0b2 = 0;
}

}  // namespace n002597c0

// 002597f0 (was src/anon/auto80_199_queue.cpp)
namespace n002597f0 {
/*TARGET 002597f0*/
u32 func_002597f0(void) asm("_Z13func_002597f0v");
u32 func_002597f0(void) {
    if (func_00139d78(D_0035f664) != 0) {
        Obj002597f0* obj = (Obj002597f0*)D_0035f664;
        obj->vtbl->fn20(obj);
    }

    if (func_0028acc8(D_0035f64c) != 0) {
        func_0028abe0(D_0035f64c);
    }

    if (func_0028acc8(D_0035f650) != 0) {
        func_0028abe0(D_0035f650);
    }

    func_002b5658();
    func_002b4f50();
    func_0028f7e8(-1);
    func_0028d620(D_0035f67c);
    func_00263d28();
    func_0028ff68(D_0035f66c);
    func_00290488(D_0035f670);
    func_0028ce38();
    return func_002b6418();
}
}  // namespace n002597f0

// 002598b8 (was gap)
namespace n002598b8 {
extern u8 D_0035f070 asm("D_0035f070");
extern u8 D_0035f0b0 asm("D_0035f0b0");
extern u8 D_0035f0b1 asm("D_0035f0b1");
extern u8 D_0035f0b2 asm("D_0035f0b2");
extern u32 D_0035eca4 asm("D_0035eca4");
extern u32 D_0035f64c asm("D_0035f64c");
extern u8 D_00372f20[] asm("D_00372f20");
extern u8 D_00372eb8[] asm("D_00372eb8");
void func_002b4ac8(s32, s32) asm("func_002b4ac8");
void func_002b4ae0(s32) asm("func_002b4ae0");
void func_002b4af0(void*) asm("func_002b4af0");
void func_00258ce8(void*) asm("func_00258ce8");
void Tz__CmSLBase__Init() asm("Tz__CmSLBase__Init");
void func_002420d8(u32, s32) asm("func_002420d8");
u8* func_00103eb0() asm("func_00103eb0");
void TASK_MANAGER__create_thread(u32, u32, u32, u32, u32) asm("TASK_MANAGER__create_thread");
void func_0014a248() asm("func_0014a248");
void func_002b47a0() asm("func_002b47a0");
s32 YS__CACHE_BUFF__IsFlushing() asm("YS__CACHE_BUFF__IsFlushing");
void func_00170888(u32) asm("func_00170888");
void func_00253818(s32) asm("func_00253818");
void Tz__CmComm__DataLoad(s32) asm("Tz__CmComm__DataLoad");
void Tz__CmComm__DataLoadWait(s32, u32) asm("Tz__CmComm__DataLoadWait");
void func_002b63a8() asm("_ZN2Tz8CmSLBase11SetLeadDataEv");
void func_0014a238() asm("func_0014a238");
void func_00102448(u32, s32) asm("func_00102448");
void Tz__CmSave__Setup() asm("Tz__CmSave__Setup");
void func_00242618(s32, s32) asm("func_00242618");
void YI__IMAGE_CACHE__Clear() asm("YI__IMAGE_CACHE__Clear");
void func_00236148() asm("func_00236148");
s32 func_00259c60() asm("func_00259c60");
void Tz__CmSave__Draw() asm("Tz__CmSave__Draw");
void func_002b6298(u32) asm("func_002b6298");
void func_00233e70(s32) asm("func_00233e70");
s32 func_00233e60() asm("func_00233e60");
void Tz__CmLoad__Setup() asm("Tz__CmLoad__Setup");
s32 Tz__CmLoad__Control() asm("Tz__CmLoad__Control");
void Tz__CmLoad__Draw() asm("Tz__CmLoad__Draw");
s64 func_00287bc0_l() asm("func_00287bc0");
s32 func_0028b040(u32) asm("func_0028b040");
struct E32 { u32 a, b, flags; u8 pad[20]; };
E32* func_00241f10() asm("func_00241f10");
void func_002598b8(u32) asm("func_002598b8");
void func_0025d7f8(u32) asm("func_0025d7f8");

void func_002598b8(u32 key) {
    if (YS__CACHE_BUFF__IsFlushing()) func_00170888(key);
    func_00253818(1);
    Tz__CmComm__DataLoad(1);
    Tz__CmComm__DataLoadWait(1, key);
    func_002b63a8();
    func_0014a238();
    func_00102448(key, 1);
    for (;;) {
        if (!D_0035f0b1) break;
        func_00102448(key, 0);
    }
    Tz__CmSave__Setup();
    func_00242618(11, 1);
    for (;;) {
        YI__IMAGE_CACHE__Clear();
        func_00236148();
        if (func_00259c60()) break;
        Tz__CmSave__Draw();
        func_00102448(key, 0);
    }
}

}  // namespace n002598b8

// 00259998 (was src/anon/batch_w1609.cpp)
namespace n00259998 {
struct AllocVt259 { void* (*alloc)(void* self, u32 size, void* ra); };
struct AllocObj259 { AllocVt259* vt; };
struct Holder259 { u8 pad[20]; AllocObj259* al; };
extern Holder259* D_00347f80 asm("D_00347f80");
extern AllocObj259* D_0032ba14 asm("D_0032ba14");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8 D_0035ebb8[] asm("D_0035ebb8");
extern u8* D_0035f664 asm("D_0035f664");
extern u8* D_0035f668 asm("D_0035f668");
extern void* D_0035f66c asm("D_0035f66c");
extern void* D_0035f670 asm("D_0035f670");
extern s32 D_0035f674 asm("D_0035f674");
extern u8 D_0035f0b2 asm("D_0035f0b2");
extern u8 D_00372e70[] asm("D_00372e70");
extern u8 D_00372e78[] asm("D_00372e78");
extern u8 D_00372e80[] asm("D_00372e80");
extern u8 D_00372e88[] asm("D_00372e88");
extern u8 D_00372ec0[] asm("D_00372ec0");
extern u8 D_00372ec8[] asm("D_00372ec8");
u8* func_0023ee30(u32 size) asm("func_0023ee30");
void YI__IMAGE_FREEZE__IMAGE_FREEZE(u8* p) asm("YI__IMAGE_FREEZE__IMAGE_FREEZE");
void YI__LAYOUT__LAYOUT(u8* p) asm("YI__LAYOUT__LAYOUT");
s32 func_0023f948(s32, s32) asm("func_0023f948");
void Tz__MenuUtil__CreateLay(u8* a, u32 b, u32 c, u32 d, u32 e, u32 f, s32 g, u32 h, u32 i) asm("Tz__MenuUtil__CreateLay");
void Tz__Layout__SetImageCache(u8* p) asm("Tz__Layout__SetImageCache");
void Tz__SelHist__Init(u32 a, u32 b, u8* c, u8* d, u8* e) asm("Tz__SelHist__Init");
void Tz__CMenuHelp__Init(u32 a, u32 b, u8* c, u8* d, u8* e) asm("Tz__CMenuHelp__Init");
void func_002590b0(u8* a, u32 b, u8* c, u8* d, u8* e, s32 f, u32 g, u32 h) asm("func_002590b0");
void func_0023f618(u8*, s32) asm("func_0023f618");
s32 func_00192048(u32) asm("func_00192048");
u8* GetLayout259(u8* p) asm("func_0023f1b0");
u32 func_0023c4b8(u8* p, u32 a) asm("func_0023c4b8");
u32 func_00236ca8(u32 p, u32 a) asm("func_00236ca8");
void func_0028fc78(void* p, u32 a, u32 b, u8* c) asm("func_0028fc78");
void func_0028fe38(void* p, u32 a, u32 b, u32 c, u32 d) asm("func_0028fe38");
void func_00290198(void* p, u32 a, u32 b, u32 c, u8* d) asm("func_00290198");
void Tz__TimeDraw__Create(void* p, u32 a, u32 b, u32 c, u32 d) asm("Tz__TimeDraw__Create");
void func_0023d2e0(s32*) asm("func_0023d2e0");
void func_00240b90(s32) asm("func_00240b90");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0025a1d0(void) asm("func_0025a1d0");
void Tz__CmSLBase__SetupSlot(void) asm("Tz__CmSLBase__SetupSlot");
static inline void* Alloc259(u32 size) { return D_0032ba14->vt->alloc(D_0032ba14, size, __builtin_return_address(0)); }
enum E259 { E0, E1, E2 };
/*TARGET 00259998*/
void Tz__CmSave__Setup(void) asm("Tz__CmSave__Setup");
void Tz__CmSave__Setup(void)
{
    s32 h;
    u8* o = func_0023ee30(160);
    *(u32*)(o + 12) = 0;
    *(u8**)o = D_0035eb98;
    YI__IMAGE_FREEZE__IMAGE_FREEZE(o + 24);
    YI__LAYOUT__LAYOUT(o + 48);
    D_0035f664 = o;
    Tz__MenuUtil__CreateLay(D_0035f664, 30039, 0, 0, 0, 1, func_0023f948(D_0035f674, 0), 0, 0);
    Tz__Layout__SetImageCache(D_0035f664);
    Tz__SelHist__Init(0, 0, D_0035f664, D_00372e80, D_00372ec0);
    Tz__CMenuHelp__Init(0, 0, D_0035f664, D_00372e70, D_00372ec8);
    AllocObj259* al = D_00347f80->al;
    u8* m = (u8*)al->vt->alloc(al, 76, 0);
    *(u32*)(m + 12) = 0;
    *(u8**)m = D_0035ebb8;
    D_0035f668 = m;
    func_002590b0(m, 30040, D_0035f664, D_00372e70, D_00372e78, -1, 0, 0);
    if (D_0035f0b2) func_0023f618(D_0035f668, func_00192048(0xce7b));
    u32 seq = func_0023c4b8(GetLayout259(D_0035f664), 0);
    u32 img = func_00236ca8(*(u32*)(GetLayout259(D_0035f664) + 40), 0);
    void* p = Alloc259(20);
    func_0028fc78(p, 19, 28, D_00372e88);
    D_0035f66c = p;
    func_0028fe38(p, 30045, seq, img, 0);
    void* q = Alloc259(20);
    func_00290198(q, 19, 48, 38, D_00372e88 + 6);
    D_0035f670 = q;
    Tz__TimeDraw__Create(q, 30045, seq, img, 0);
    func_0023d2e0(&h);
    func_00240b90(h);
    func_00287bd0(D_0035f0b2 != 0, 0);
    func_00287cc0(0);
    switch ((E259)func_00287bc0()) {
    case E0:
        Tz__CmSLBase__SetupSlot();
        break;
    case E1:
        func_0025a1d0();
        break;
    }
}
}  // namespace n00259998

// 00259c60 (was src/anon/batch_w2402_g.cpp)
namespace n00259c60 {
extern s32 D_0035f650 asm("D_0035f650");
extern s32 D_0035f664 asm("D_0035f664");
extern s32 D_0035f670 asm("D_0035f670");
void func_001039f8(void) asm("func_001039f8");
s32 func_00139d78(s32) asm("func_00139d78");
s32 func_00233e60(void) asm("func_00233e60");
void func_00233e70(s32) asm("func_00233e70");
s32 func_0023f0c0(s32) asm("func_0023f0c0");
void Tz__CmSave__CtrlTop(void) asm("Tz__CmSave__CtrlTop");
void Tz__CmSave__CtrlSlot(void) asm("Tz__CmSave__CtrlSlot");
void func_0025a468(void) asm("func_0025a468");
void func_0025a660(void) asm("func_0025a660");
void func_0025aa10(void) asm("func_0025aa10");
void Tz__CmSave__CtrlSlotCheck(void) asm("Tz__CmSave__CtrlSlotCheck");
void func_0025af70(void) asm("func_0025af70");
void func_0025b050(void) asm("func_0025b050");
void func_0025b218(void) asm("func_0025b218");
void func_0025b5e0(void) asm("func_0025b5e0");
void Tz__CmSave__CtrlList(void) asm("Tz__CmSave__CtrlList");
void func_0025bbe0(void) asm("func_0025bbe0");
void func_0025bd98(void) asm("func_0025bd98");
void func_0025c3c0(void) asm("func_0025c3c0");
void Tz__CmSave__CtrlWMapConfirm(void) asm("Tz__CmSave__CtrlWMapConfirm");
void func_0025ccf0(void) asm("func_0025ccf0");
void func_0025cd78(void) asm("func_0025cd78");
void func_0025d4e8(void) asm("func_0025d4e8");
u32 func_00287bc0(void) asm("func_00287bc0");
void Tz__MenuBase__SaveMode(void) asm("Tz__MenuBase__SaveMode");
s32 func_00287db0(void) asm("func_00287db0");
s32 func_0028acc8(s32) asm("func_0028acc8");
void func_00290420(s32) asm("func_00290420");
s32 func_00290580(s32) asm("func_00290580");
s32 func_002b55e0(void) asm("func_002b55e0");
void func_002b5af0(void) asm("func_002b5af0");
void func_002b6418(void) asm("func_002b6418");
/*TARGET 00259c60*/
s32 func_00259c60(void) asm("func_00259c60");
s32 func_00259c60(void) {
    Tz__MenuBase__SaveMode();
    func_002b6418();
    if (func_00287db0()) {
        func_00233e70(0);
        if (!func_00233e60()) return 0;
        if (func_00139d78(D_0035f664) || func_002b55e0() || func_0028acc8(D_0035f650)) return 0;
        func_002b5af0();
        func_0025d4e8();
        func_001039f8();
        return 1;
    } else {
        if (func_00290580(D_0035f670)) func_00290420(D_0035f670);
        if (func_00139d78(D_0035f664) == 0 || func_0023f0c0(D_0035f664) == 1) {
            switch (func_00287bc0()) {
            case 0: Tz__CmSave__CtrlTop(); break;
            case 1: Tz__CmSave__CtrlSlot(); break;
            case 2: func_0025a468(); break;
            case 3: func_0025b050(); break;
            case 4: func_0025b218(); break;
            case 9: Tz__CmSave__CtrlSlotCheck(); break;
            case 11: func_0025af70(); break;
            case 12: Tz__CmSave__CtrlList(); break;
            case 8: case 13: func_0025aa10(); break;
            case 14: func_0025c3c0(); break;
            case 15: func_0025bd98(); break;
            case 19: Tz__CmSave__CtrlWMapConfirm(); break;
            case 20: func_0025bbe0(); break;
            case 21: func_0025b5e0(); break;
            case 5: case 7: case 10: case 22: func_0025a660(); break;
            case 23: func_0025ccf0(); break;
            case 24: func_0025cd78(); break;
            }
        }
    }
    return 0;
}
}  // namespace n00259c60

// 00259e90 (was src/anon/batch_w259.cpp)
namespace n00259e90 {
struct E259 { u8 p0[8]; u8 f8[10]; u16 h18; u8 p1[16]; };
// 0x001cfbd8: definition moved into src/anon/unit_001cf0b0.cpp

extern E259 D_00372ed8[] asm("D_00372ed8");
extern void* D_0035f64c asm("D_0035f64c");
extern u32 D_0035f664 asm("D_0035f664");
s32 func_00253578(void) asm("func_00253578");
// get_global_36ee90
void Tz__Select__SetItem(void*, s32, s32, s32, u32, u32, E259*, void*) asm("Tz__Select__SetItem");
void Tz__Select__SetExOffset(void*, s32, s32, s32) asm("Tz__Select__SetExOffset");
u32 func_002891b8(void*, s32) asm("func_002891b8");
void func_00139620(u32) asm("func_00139620");
void func_001395f8(u32) asm("func_001395f8");
void Tz__Select__SetCurrent(void*, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_0028af18(void*, s32) asm("func_0028af18");
/*TARGET 00259e90*/
void Tz__CmSLBase__SetupSlot(void) asm("Tz__CmSLBase__SetupSlot");
void Tz__CmSLBase__SetupSlot(void) {
    for (s32 i = 0; i < 2; i++) {
        if (i == 1 && func_00253578() == 2) break;
        Tz__Select__SetItem(D_0035f64c, i, 0, 0, D_0035f664, D_00372ed8[i].h18, &D_00372ed8[i], D_00372ed8[i].f8);
        Tz__Select__SetExOffset(D_0035f64c, i, 0, -1);
        func_00139620(func_002891b8(D_0035f64c, i));
        func_001395f8(func_002891b8(D_0035f64c, i));
    }
    Tz__Select__SetCurrent(D_0035f64c, 0, 1, 0, 2);
    func_0028af18(D_0035f64c, 115);
}
}  // namespace n00259e90

// 00259fb8 (was src/anon/batch_wcx2.cpp)
namespace n00259fb8 {
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
extern s32 D_0035f64c_259 asm("D_0035f64c");
s32 func_00289380_x9644(s32) asm("func_00289380");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_0028acc8_x9646(s32) asm("func_0028acc8");
s32 func_00289310_x9647(s32) asm("func_00289310");
void func_00287f90(s32) asm("func_00287f90");
void func_0028abe0_x9649(s32) asm("func_0028abe0");
void func_00287c30() asm("func_00287c30");
s32 func_00287bc0() asm("func_00287bc0");
void func_002b5af0() asm("func_002b5af0");
void func_0028f7e8(s32) asm("func_0028f7e8");
void func_0025a1d0() asm("func_0025a1d0");
s32 func_0028ae28_x9655(s32, s32) asm("func_0028ae28");
void func_0028ab20_x9656(s32) asm("func_0028ab20");
void func_00287cc0(s32) asm("func_00287cc0");
void func_0025d560() asm("func_0025d560");
void func_0025d620() asm("func_0025d620");
s32 func_00287df0_259(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void Tz__CMenuHelp__FadeOut() asm("Tz__CMenuHelp__FadeOut");
void func_00287da0() asm("func_00287da0");
void func_0028aa40(s32) asm("func_0028aa40");
void func_00287c00(s32) asm("func_00287c00");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_0025ca78() asm("func_0025ca78");
s32 func_00288040() asm("func_00288040");
void func_00288018() asm("func_00288018");
/*TARGET 00259fb8*/
void Tz__CmSave__CtrlTop() asm("Tz__CmSave__CtrlTop");
void Tz__CmSave__CtrlTop() {
    s32 r = func_00289380_x9644(D_0035f64c_259);
    s32 a = func_00287cd0();
    if (a == 2) {
        if (func_0028acc8_x9646(D_0035f64c_259)) {
            if (r != -1 || func_00289310_x9647(D_0035f64c_259)) {
                func_00287f90(0);
                func_0028abe0_x9649(D_0035f64c_259);
            }
            return;
        }
        func_00287c30();
        if (func_00287bc0() != 1) return;
        func_002b5af0();
        func_0028f7e8(1);
        func_0025a1d0();
        return;
    }
    if (r != -1 || func_00289310_x9647(D_0035f64c_259)) {
        if (!func_0028ae28_x9655(D_0035f64c_259, 0)) func_0028ab20_x9656(D_0035f64c_259);
    }
    if (!a && func_0028ae28_x9655(D_0035f64c_259, 0)) {
        func_00287cc0(1);
        func_0025d560();
    }
    if (!func_00242848(func_00287df0_259(r, func_00289310_x9647(D_0035f64c_259), 1, func_0025d620, 1))) {
        switch (r) {
        case -4: case -2:
            Tz__CMenuHelp__FadeOut();
            func_00287da0();
            break;
        case -3: case -1:
            break;
        case 0:
            func_0028aa40(D_0035f64c_259);
            func_00287cc0(2);
            func_00287c00(1);
            Tz__CMenuHelp__FadeOut();
            break;
        case 1:
            func_00287bd0(19, 0);
            func_0025ca78();
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n00259fb8

// 0025a1d0 (was src/anon/batch_w9.cpp)
namespace n0025a1d0 {
void OvlShop__ItemShop__SetupConfirm(void) asm("OvlShop__ItemShop__SetupConfirm");
void func_0028f4d8(u32, u32, u32) asm("func_0028f4d8");
void func_00240be0(void) asm("func_00240be0");
extern u16 D_00372eea asm("D_00372eea");
/*TARGET 0025a1d0*/
void func_0025a1d0(void) asm("func_0025a1d0");
void func_0025a1d0(void) {
    OvlShop__ItemShop__SetupConfirm();
    func_0028f4d8(0, D_00372eea, 0);
    func_00240be0();
}
}  // namespace n0025a1d0

// 0025a200 (was src/anon/batch_wcx2.cpp)
namespace n0025a200 {
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
extern s32 D_0035f64c_25a asm("D_0035f64c");
s32 func_00289380_x10375(s32) asm("func_00289380");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_0028acc8_x10377(s32) asm("func_0028acc8");
s32 func_00289310_x10378(s32) asm("func_00289310");
void func_00287f90(s32) asm("func_00287f90");
void func_0028abe0_x10380(s32) asm("func_0028abe0");
void func_00287c30() asm("func_00287c30");
s32 func_00287bc0() asm("func_00287bc0");
void func_002b5af0() asm("func_002b5af0");
void func_0028f7e8(s32) asm("func_0028f7e8");
void Tz__CmSLBase__SetupSlot() asm("Tz__CmSLBase__SetupSlot");
void func_00240be0() asm("func_00240be0");
void Tz__CmSLBase__SetupSlotCheck() asm("Tz__CmSLBase__SetupSlotCheck");
extern u8 D_0035f0b2 asm("D_0035f0b2");
void Tz__SelHist__FadeOut(s32) asm("Tz__SelHist__FadeOut");
void func_00240b90(s32) asm("func_00240b90");
s32 func_0028ae28_x10391(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10392(s32) asm("func_0028ab20");
void func_00287cc0(s32) asm("func_00287cc0");
void func_0025d560() asm("func_0025d560");
void func_0025d620() asm("func_0025d620");
s32 func_00287df0_25a(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void Tz__CMenuHelp__FadeOut() asm("Tz__CMenuHelp__FadeOut");
void func_00287da0() asm("func_00287da0");
void func_0028aa40(s32) asm("func_0028aa40");
void func_00287c00(s32) asm("func_00287c00");
s32 func_00288040() asm("func_00288040");
void func_00288018() asm("func_00288018");
/*TARGET 0025a200*/
void Tz__CmSave__CtrlSlot() asm("Tz__CmSave__CtrlSlot");
void Tz__CmSave__CtrlSlot() {
    s32 r = func_00289380_x10375(D_0035f64c_25a);
    s32 a = func_00287cd0();
    if (a == 2) {
        if (func_0028acc8_x10377(D_0035f64c_25a)) {
            if (r != -1 || func_00289310_x10378(D_0035f64c_25a)) {
                func_00287f90(0);
                func_0028abe0_x10380(D_0035f64c_25a);
            }
            return;
        }
        func_00287c30();
        s32 s = func_00287bc0();
        if (s == 0) {
            func_0028f7e8(0);
            Tz__CmSLBase__SetupSlot();
        } else if (s == 2) {
            func_002b5af0();
            func_0028f7e8(1);
            func_00240be0();
            Tz__CmSLBase__SetupSlotCheck();
        }
        return;
    }
    if (r != -1 || func_00289310_x10378(D_0035f64c_25a)) {
        if (!func_0028ae28_x10391(D_0035f64c_25a, 0)) func_0028ab20_x10392(D_0035f64c_25a);
    }
    if (!a && func_0028ae28_x10391(D_0035f64c_25a, 0)) {
        func_00287cc0(1);
        func_0025d560();
    }
    if (!func_00242848(func_00287df0_25a(r, func_00289310_x10378(D_0035f64c_25a), 1, func_0025d620, 1))) {
        switch (r) {
        case -2:
            if (!D_0035f0b2) goto other;
        case -4:
            Tz__CMenuHelp__FadeOut();
            func_00287da0();
            break;
        case -3: case -1:
            break;
        other:
            func_0028aa40(D_0035f64c_25a);
            func_00287cc0(2);
            func_00287c00(0);
            Tz__SelHist__FadeOut(0);
            Tz__CMenuHelp__FadeOut();
            break;
        case 0: case 1:
            func_00240b90(r);
            func_00287c00(2);
            func_0028aa40(D_0035f64c_25a);
            func_00287cc0(2);
            Tz__CMenuHelp__FadeOut();
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0025a200

// 0025a468 (was src/anon/batch_w1604.cpp)
namespace n0025a468 {
extern s32 D_0035f654 asm("D_0035f654");
s32 Tz__MenuUtil__SprtIsLoop(s32) asm("Tz__MenuUtil__SprtIsLoop");
s32 func_00287cd0(void) asm("func_00287cd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00240ba0(void) asm("func_00240ba0");
u32 func_00287d30(void) asm("func_00287d30");
s32 func_00233e70(s32) asm("func_00233e70");
void func_002419d0(s32) asm("func_002419d0");
s32 func_00234888(s32, s32) asm("func_00234888");
s32 func_002348a8(s32, s32) asm("func_002348a8");
s32 func_00234848(s32, s32) asm("func_00234848");
s32 func_00234868(s32, s32) asm("func_00234868");
void func_002b5108(s32, s32) asm("func_002b5108");
void func_00287d20(s32) asm("func_00287d20");
void func_00240bb0(s32) asm("func_00240bb0");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00241450(s32) asm("func_00241450");
void Tz__CmSLBase__SetupWarningConfirm(s32) asm("Tz__CmSLBase__SetupWarningConfirm");
void func_00234570(s32, s32) asm("func_00234570");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
/*TARGET 0025a468*/
void func_0025a468(void) asm("func_0025a468");
void func_0025a468(void)
{
    if (!Tz__MenuUtil__SprtIsLoop(D_0035f654)) return;
    if (func_00287cd0() == 0) func_00287cc0(1);
    s32 h = func_00240ba0();
    switch (func_00287d30()) {
    case 0:
        if (func_00233e70(0) == 0) {
            s32 m;
            s32 r;
            func_002419d0(0);
            r = func_00234888(h, 0);
            switch (func_002348a8(h, 0)) {
            case 3:
                goto bad;
            case 4:
                func_002b5108(0x8aae, h);
                r = -1;
                m = 6;
                break;
            default:
                if (func_00234848(h, 0) != 2) {
                bad:
                    func_002b5108(0xb85d, h);
                    r = -1;
                    m = 2;
                } else if (!func_00234868(h, 0)) {
                    func_002419d0(1);
                    m = 5;
                } else {
                    func_002b5108(0x8a89, h);
                    m = 1;
                }
                break;
            }
            func_00287d20(m);
            func_00240bb0(r);
        }
        break;
    case 1:
        func_00287bd0(4, 0);
        func_00287d20(10);
        func_00241450(1);
        break;
    case 2:
        Tz__CmSLBase__SetupWarningConfirm(0);
        func_00287bd0(5, 0);
        func_00234570(h, 0);
        break;
    case 3:
        Tz__CmSLBase__SetupWarningConfirm(1);
        func_00287bd0(8, 0);
        func_00234570(h, 0);
        break;
    case 5:
        func_00287bd0(11, 0);
        break;
    case 6:
        Tz__CmSLBase__SetupWarningConfirm(0);
        func_00287bd0(7, 0);
        func_00234570(h, 0);
        break;
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0025a468

// 0025a660 (was src/anon/batch_wcx2.cpp)
namespace n0025a660 {
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
// ---- 0025a660
extern void* D_0035f650 asm("D_0035f650");
extern u8 D_0035f0b0 asm("D_0035f0b0");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00289380(void* s) asm("func_00289380");
s32 func_00287c10(void) asm("func_00287c10");
s32 func_0028acc8_a660(void* s) asm("func_0028acc8");
s32 func_00289310_a660(void* s) asm("func_00289310");
void func_0028abe0_a660(void* s) asm("func_0028abe0");
void func_002b4f50(void) asm("func_002b4f50");
bool func_002b55e0(void) asm("func_002b55e0");
s32 func_00233e70(s32 a) asm("func_00233e70");
s32 func_00233e60(void) asm("func_00233e60");
void func_00287c30(void) asm("func_00287c30");
void func_00287d20(s32 a) asm("func_00287d20");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_002b5af0(void) asm("func_002b5af0");
void func_0028f7e8(s32 a) asm("func_0028f7e8");
void func_0025a1d0(void) asm("func_0025a1d0");
void func_00288018(void) asm("func_00288018");
// global_zero_4dwords
void func_00240be0(void) asm("func_00240be0");
s32 func_002b4fb8(void) asm("func_002b4fb8");
void func_002b50f8(void) asm("func_002b50f8");
// zero_global_byte_c
s32 func_00240ba0_a660(void) asm("func_00240ba0");
s32 func_002348a8_a660(s32 slot, s32 a) asm("func_002348a8");
void func_002b5108_a660(u32 msg, s32 slot) asm("func_002b5108");
void func_00287c00(s32 m) asm("func_00287c00");
void func_002b5558(void) asm("func_002b5558");
void func_00287cc0(s32 s) asm("func_00287cc0");
void func_00234570_a660(s32 slot, void* p) asm("func_00234570");
void func_00287bd0(s32 a, s32 b) asm("func_00287bd0");
s32 func_002b50e8(void) asm("func_002b50e8");
// get_global_byte_c
s32 func_0028ae28(void* s, s32 a) asm("func_0028ae28");
s32 func_00287df0(s32 a, s32 b, s32 c, s32 d, s32 e) asm("func_00287df0");
s32 func_00242848(s32 a) asm("func_00242848");
void func_002b4ee0(void) asm("func_002b4ee0");
void Tz__SelHist__FadeOut(s32 a) asm("Tz__SelHist__FadeOut");
/*TARGET 0025a660*/
// record884_refresh_by_index

// Memory-card menu: per-frame state update.
void func_0025a660(void) asm("func_0025a660");
// record884_refresh_by_index

// Memory-card menu: per-frame state update.
void func_0025a660(void) {
    s32 cur;
    s32 st = func_00287cd0();
    if (st == 2) {
        cur = func_00289380(D_0035f650);
        s32 next = func_00287c10();
        s32 r;
        if (next == st) r = func_0028acc8_a660(D_0035f650);
        else r = func_002b4fb8();
        if (r) {
            if (cur == -1 && !func_00289310_a660(D_0035f650)) return;
            if (next == 2) func_0028abe0_a660(D_0035f650);
            else func_002b4f50();
            return;
        }
        bool ok = 1;
        if (next == 1 || next == 2) ok = !func_002b55e0();
        if (ok) {
            if (next == 1) {
                func_00233e70(0);
                if (!func_00233e60()) return;
            }
            func_00287c30();
            func_00287d20(0);
            s32 m = func_00287bc0();
            if (m == 1) {
                func_002b5af0();
                func_0028f7e8(1);
                func_0025a1d0();
            } else if (m == 2) {
                func_00240be0();
            }
            func_00288018();  // global_zero_4dwords
        }
        D_0035f0b0 = 1;
        return;
    }
    func_0028acc8_a660(D_0035f650);
    if (!func_00233e70(0)) {
        func_002b50f8();  // zero_global_byte_c
        if (D_0035f0b0) {
            s32 slot = func_00240ba0_a660();
            if (func_002348a8_a660(slot, 0) != 3) {
                if (func_00287bc0() == 5) {
                    func_002b5108_a660(0x8a89, slot);
                    func_00287c00(2);
                    func_0028abe0_a660(D_0035f650);
                    func_002b5558();
                    func_00287cc0(2);
                }
                func_00234570_a660(slot, 0);
                return;
            }
            if (func_00287bc0() != 5) {
                func_002b5108_a660(0xb85d, slot);
                func_00287bd0(5, func_00287cd0());
                func_00234570_a660(slot, 0);
                return;
            }
            func_00234570_a660(slot, 0);
        }
    }
    if (func_002b50e8()) return;
    if (st == 0 && func_0028ae28(D_0035f650, 0)) func_00287cc0(1);
    if (st != 1) return;
    cur = func_00289380(D_0035f650);
    if (func_00242848(func_00287df0(cur, func_00289310_a660(D_0035f650), 0, 0, 1))) return;
    s32 m = func_00287bc0();
    switch (cur) {
    case -1:
        break;
    case -2:
    case 0:
        if (m == 10 || m == 22) {
            func_00287c00(12);
        } else {
            func_002b5558();
            func_00287c00(1);
            Tz__SelHist__FadeOut(1);  // record884_refresh_by_index
        }
        func_002b4ee0();
        func_00287cc0(2);
        break;
    }
}
}  // namespace n0025a660

// 0025aa10 (was src/anon/batch_w1614.cpp)
namespace n0025aa10 {
extern s32 D_0035f650 asm("D_0035f650");
extern s32 D_0035f64c asm("D_0035f64c");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287c10(void) asm("func_00287c10");
s32 func_0028acc8(s32) asm("func_0028acc8");
s32 func_002b4fb8(void) asm("func_002b4fb8");
s32 func_00289310(s32) asm("func_00289310");
void func_0028abe0(s32) asm("func_0028abe0");
void func_002b4f50(void) asm("func_002b4f50");
void func_00233e70(s32) asm("func_00233e70");
s32 func_00233e60(void) asm("func_00233e60");
void func_00287c30(void) asm("func_00287c30");
void func_00287d20(s32) asm("func_00287d20");
s32 func_00240ba0(void) asm("func_00240ba0");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_002b5af0(void) asm("func_002b5af0");
void func_0028f7e8(s32) asm("func_0028f7e8");
void func_0025a1d0(void) asm("func_0025a1d0");
void func_00288018(void) asm("func_00288018");
void Tz__CmSLBase__SetupWarningConfirm(s32) asm("Tz__CmSLBase__SetupWarningConfirm");
void func_002b5108(s32, s32) asm("func_002b5108");
void func_002345f0(s32, s32) asm("func_002345f0");
void func_00241450(s32) asm("func_00241450");
void func_002400f8(s32) asm("func_002400f8");
bool func_0028acc8b(s32) asm("func_0028acc8");
s32 func_00233e70b(s32) asm("func_00233e70");
void func_002b50f8(void) asm("func_002b50f8");
s32 func_002348a8(s32, s32) asm("func_002348a8");
void func_00234570(s32, s32) asm("func_00234570");
void func_00287c00(s32) asm("func_00287c00");
s32 func_002b50e8(void) asm("func_002b50e8");
s32 func_0028ae28(s32, s32) asm("func_0028ae28");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_002b4ee0(void) asm("func_002b4ee0");
void func_0028aa40(s32) asm("func_0028aa40");
void func_002b5558(void) asm("func_002b5558");
void Tz__SelHist__FadeOut(s32) asm("Tz__SelHist__FadeOut");
static inline __attribute__((always_inline)) bool chk(s32 st)
{
    if (st == 1) return !func_0028acc8b(D_0035f64c);
    return true;
}
/*TARGET 0025aa10*/
void func_0025aa10(void) asm("func_0025aa10");
void func_0025aa10(void)
{
    s32 mode = func_00287cd0();
    if (mode == 2) {
        s32 r = func_00289380(D_0035f650);
        s32 st = func_00287c10();
        s32 c;
        if (st == 9 || st == 14) c = func_0028acc8(D_0035f650);
        else c = func_002b4fb8();
        if (c) {
            if (r != -1 || func_00289310(D_0035f650)) {
                if (st == 9 || st == 14) func_0028abe0(D_0035f650);
                else func_002b4f50();
            }
            return;
        }
        if (!chk(st)) return;
        if (st == 1) {
            func_00233e70(0);
            if (!func_00233e60()) return;
        }
        func_00287c30();
        func_00287d20(0);
        s32 h = func_00240ba0();
        s32 m = func_00287bc0();
        if (m == 1) {
            func_002b5af0();
            func_0028f7e8(1);
            func_0025a1d0();
        } else if (m == 5) {
            Tz__CmSLBase__SetupWarningConfirm(0);
        } else if (m == 9) {
            func_002b5108(0x8a8f, h);
            func_00287d20(20);
            func_002345f0(h, 0);
        } else if (m == 14) {
            func_00241450(1);
            func_002b5108(0x8a90, h);
            func_00287d20(70);
            func_002400f8(1);
        }
        func_00288018();
        return;
    }
    func_0028acc8(D_0035f650);
    if (!func_00233e70b(0)) {
        func_002b50f8();
        s32 h = func_00240ba0();
        if (func_002348a8(h, 0) != 3) {
            func_00234570(h, 0);
        } else {
            func_002b5108(0xb85d, h);
            func_00287c00(5);
            func_00234570(h, 0);
            func_0028abe0(D_0035f650);
            func_00287cc0(2);
            return;
        }
    }
    if (func_002b50e8()) return;
    if (mode == 0 && func_0028ae28(D_0035f650, 0)) func_00287cc0(1);
    if (mode != 1) return;
    s32 r = func_00289380(D_0035f650);
    if (func_00242848(func_00287df0(r, func_00289310(D_0035f650), 0, 0, 1))) return;
    s32 m = func_00287bc0();
    switch (r) {
    case -1:
        break;
    case -2:
    case 0:
        if (m == 8 || m == 13) func_00287c00(12);
    b:
        func_002b4ee0();
    c:
        func_0028aa40(D_0035f650);
        func_00287cc0(2);
        break;
    case 1:
        if (m == 8) {
            func_00287c00(9);
            goto c;
        }
        if (m == 13) {
            func_00287c00(14);
            goto c;
        }
        func_002b5558();
        func_00287c00(1);
        Tz__SelHist__FadeOut(1);
        goto b;
    }
}
}  // namespace n0025aa10

// 0025adf0 (was src/anon/batch_wcx2.cpp)
namespace n0025adf0 {
extern u8 D_0035f0b0 asm("D_0035f0b0");
s32 func_00287cd0(void) asm("func_00287cd0");
u32 func_00240ba0(void) asm("func_00240ba0");
s32 func_002b4ff8(void) asm("func_002b4ff8");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00287d30(void) asm("func_00287d30");
s32 func_00233e70(s32) asm("func_00233e70");
s32 func_00234778(void) asm("func_00234778");
void func_002419d0(s32) asm("func_002419d0");
// store_global_bool_converted
void func_00234570(u32, s32) asm("func_00234570");
void func_00287d20(s32) asm("func_00287d20");
s32 func_002348a8(u32, s32) asm("func_002348a8");
u32 func_00234888(u32, s32) asm("func_00234888");
// entry32_word
void func_00240bb0(u32) asm("func_00240bb0");
// global_store_half2
void func_00241450(s32) asm("func_00241450");
void func_002b5108(s32, u32) asm("func_002b5108");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_002400f8(s32) asm("func_002400f8");
void Tz__CmSLBase__SetupWarningConfirm(s32) asm("Tz__CmSLBase__SetupWarningConfirm");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
/*TARGET 0025adf0*/
// global_zero_4dwords
void Tz__CmSave__CtrlSlotCheck(void) asm("Tz__CmSave__CtrlSlotCheck");
// global_zero_4dwords
void Tz__CmSave__CtrlSlotCheck(void)
{
    s32 open = func_00287cd0();
    u32 w = func_00240ba0();
    if (!func_002b4ff8()) return;
    if (!open) func_00287cc0(1);
    s32 done = 0;
    switch (func_00287d30()) {
    case 20:
        if (func_00233e70(0)) break;
        if (func_00234778()) {
            done = 1;
            break;
        }
        func_002419d0(0);  // store_global_bool_converted
        func_00234570(w, 0);
        func_00287d20(21);
        break;
    case 21:
        if (func_00233e70(0)) break;
        w = func_00240ba0();
        if (func_002348a8(w, 0) != 3) {
            func_00240bb0(func_00234888(w, 0));  // global_store_half2
            func_00241450(1);
            func_002b5108(0x8a90, w);
            func_00287bd0(14, 0);
            func_00287d20(70);
            func_002400f8(1);
        } else {
            done = 1;
        }
        break;
    }
    if (done) {
        func_002b5108(0x8a95, w);
        func_00287bd0(7, 0);
        Tz__CmSLBase__SetupWarningConfirm(0);
        D_0035f0b0 = 0;
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0025adf0

// 0025af70 (was src/anon/batch_w81.cpp)
namespace n0025af70 {
s32 func_00287bc0(void) asm("func_00287bc0");
// --- 0025af70
extern u8 D_00372ea0[] asm("D_00372ea0");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_002b4fb8(void) asm("func_002b4fb8");
s32 func_00287c10(void) asm("func_00287c10");
void func_00233e70(u32) asm("func_00233e70");
s32 func_00233e60(void) asm("func_00233e60");
void func_00287c30(void) asm("func_00287c30");
void func_00287d20(u32) asm("func_00287d20");
void func_002b5188(u8*, u32) asm("func_002b5188");
void func_00287cc0(u32) asm("func_00287cc0");
void func_00240bb0(u32) asm("func_00240bb0");
// global_store_half2
void func_002417a0(void) asm("func_002417a0");
void func_002b4ee0(void) asm("func_002b4ee0");
void func_00287c00(u32) asm("func_00287c00");
/*TARGET 0025af70*/
void func_0025af70(void) asm("func_0025af70");
void func_0025af70(void) {
    s32 m = func_00287cd0();
    if (m == 2) {
        if (func_002b4fb8()) return;
        if (func_00287c10() == 1) {
            func_00233e70(0);
            if (!func_00233e60()) return;
        }
        func_00287c30();
        func_00287d20(0);
        if (func_00287bc0() == 12) func_002b5188(D_00372ea0, 0);
        return;
    }
    if (m == 0) func_00287cc0(1);
    func_00240bb0(8000);  // global_store_half2
    func_002417a0();
    func_002b4ee0();
    func_00287c00(12);
    func_00287cc0(2);
}
}  // namespace n0025af70

// 0025b050 (was src/anon/batch_w291.cpp)
namespace n0025b050 {
// 0022c590: moved to src/sasa/event_layout.cpp (linked unit)

extern u8 D_0035f0b0 asm("D_0035f0b0");
s32 func_00240ba0() asm("func_00240ba0");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_002b4ff8() asm("func_002b4ff8");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00241a48() asm("func_00241a48");
void func_00287bd0(s32, s32) asm("func_00287bd0");
s32 func_00287d30() asm("func_00287d30");
s32 func_00240430() asm("func_00240430");
void func_00240118(s32, s32, s32) asm("func_00240118");
void func_00241450(s32) asm("func_00241450");
void func_00287d20(s32) asm("func_00287d20");
s32 func_00233e70(s32) asm("func_00233e70");
s32 func_00234798() asm("func_00234798");
s32 func_00234758() asm("func_00234758");
void Tz__MCard__GetDirInfo(s32) asm("Tz__MCard__GetDirInfo");
void func_002b5108(s32, s32) asm("func_002b5108");
void Tz__CmSLBase__SetupWarningConfirm(s32) asm("Tz__CmSLBase__SetupWarningConfirm");
s32 func_00241a88(s32) asm("func_00241a88");
void func_00241a60() asm("func_00241a60");
s32 func_00288040() asm("func_00288040");
void func_00288018() asm("func_00288018");
/*TARGET 0025b050*/
// global_zero_4dwords
void func_0025b050() asm("func_0025b050");
// global_zero_4dwords
void func_0025b050()
{
    s32 r;
    s32 a = func_00240ba0();
    s32 st = func_00287cd0();
    if (st == 2) return;
    if (!func_002b4ff8()) return;
    if (st == 0) func_00287cc0(1);
    if (!func_00241a48()) { func_00287bd0(21, 0); return; }
    switch (func_00287d30()) {
    case 90:
        func_00240118(func_00240430(), 0, 1);
        func_00241450(0);
        func_00287d20(91);
        break;
    case 91:
        if (func_00233e70(0)) break;
        if (func_00234798()) goto give;
        Tz__MCard__GetDirInfo(-4);
        func_00287d20(92);
        break;
    case 92: {
        if (func_00233e70(0)) break;
        r = func_00234758();
        if (r == 0) { func_00287d20(93); break; }
        if (r == 1) goto fail;
    give:
        func_002b5108(0x8a8c, a);
        func_00287bd0(7, 0);
        Tz__CmSLBase__SetupWarningConfirm(0);
        D_0035f0b0 = 0;
        break;
    }
    case 93:
        if (!func_00241a88(1)) {
    fail:
            func_00241a60();
        }
        func_00287bd0(21, 0);
        break;
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0025b050

// 0025b218 (was src/anon/batch_w2428.cpp)
namespace n0025b218 {
s32 func_00233e70(s32) asm("func_00233e70");
s32 func_00234758(void) asm("func_00234758");
s32 func_00234798(void) asm("func_00234798");
s32 YI__MCARD__GetResultRead(void) asm("YI__MCARD__GetResultRead");
void func_002349c8(s32, s32) asm("func_002349c8");
void Tz__MCard__MakeFname(s32) asm("Tz__MCard__MakeFname");
s32 func_00240a08(s32) asm("func_00240a08");
s32 func_00240ba0(void) asm("func_00240ba0");
void func_00240bc0(s32) asm("func_00240bc0");
s32 Tz__MCard__GetPos(void) asm("Tz__MCard__GetPos");
void func_00240c08(s32, s32, s32) asm("func_00240c08");
void Tz__MCard__GetDirInfo(s32) asm("Tz__MCard__GetDirInfo");
s32 Tz__MCard__UpdateDirInfo(void) asm("Tz__MCard__UpdateDirInfo");
void func_00240fd8(s32, s32) asm("func_00240fd8");
s32 func_002413f0(void) asm("func_002413f0");
void func_00241450(s32) asm("func_00241450");
void func_002415a0(s32, s32, s32) asm("func_002415a0");
void func_00241850(s32, s32) asm("func_00241850");
s32 Tz__MCard__ChkFileSize(s32) asm("Tz__MCard__ChkFileSize");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00287cd0(void) asm("func_00287cd0");
void func_00287d20(s32) asm("func_00287d20");
s32 func_00287d30(void) asm("func_00287d30");
void func_00288018(void) asm("func_00288018");
s32 func_00288040(void) asm("func_00288040");
void Tz__CmSLBase__SetupWarningConfirm(s32) asm("Tz__CmSLBase__SetupWarningConfirm");
s32 func_002b4ff8(void) asm("func_002b4ff8");
void func_002b5108(s32, s32) asm("func_002b5108");
extern s8 D_0035f0b0 asm("D_0035f0b0");
/*TARGET 0025b218*/
void func_0025b218(void) asm("func_0025b218");
void func_0025b218(void)
{
    s32 h = func_00240ba0();
    s32 st = func_00287cd0();
    s32 r;
    if (st == 2) return;
    if (!func_002b4ff8()) return;
    if (st == 0) func_00287cc0(1);
    switch (func_00287d30()) {
    case 10:
        if (func_00233e70(0)) break;
        if (func_00234798()) goto E;
        Tz__MCard__GetDirInfo(-1);
        func_00287d20(11);
        break;
    case 11:
        if (func_00233e70(0)) break;
        if (func_00234758()) goto E;
        if (Tz__MCard__UpdateDirInfo() <= 0) goto X;
        func_00287d20(12);
        break;
    case 12:
        func_00241450(1);
        func_00287d20(13);
        break;
    case 13:
        if (func_00233e70(0)) break;
        if (func_00234798()) goto E;
        func_00287d20(14);
        break;
    case 14:
        st = func_002413f0();
        if (st < 0) {
        X:
            func_00287bd0(3, 0);
            func_00287d20(90);
            break;
        }
        func_00240bc0(st);
        Tz__MCard__MakeFname(st);
        func_00241450(0);
        func_00287d20(15);
        break;
    case 15:
        if (func_00233e70(0)) break;
        r = func_00234798();
        if (r == 0) {
            Tz__MCard__GetDirInfo(-5);
            func_00287d20(16);
            break;
        }
        if (r == 2) goto E;
        func_00240fd8(-1, 2);
    G:
        func_00240c08(Tz__MCard__GetPos(), 0, 32);
        func_00287d20(12);
        break;
    case 16:
        if (!func_00233e70(0)) {
            r = func_00234758();
            if (r == 0) {
                st = func_002413f0();
                func_00240bc0(st);
                Tz__MCard__MakeFname(st);
                func_00241850(Tz__MCard__GetPos(), 0);
                func_002415a0(2, 0, 0);
                func_00287d20(17);
            } else if (r == 1) {
                func_00240c08(Tz__MCard__GetPos(), 0, 32);
                func_00287d20(12);
            } else {
                func_002b5108(0x8a8c, h);
                func_00287bd0(7, 0);
                Tz__CmSLBase__SetupWarningConfirm(0);
                D_0035f0b0 = 0;
            }
        }
    case 17:
        if (func_00233e70(0)) break;
        func_00240fd8(-1, 2);
        r = YI__MCARD__GetResultRead();
        if (r == 0) {
            func_00287d20(18);
            break;
        }
        if (r == 1) { func_00240c08(Tz__MCard__GetPos(), 0, 32); func_00287d20(12); break; }
        if (r != 3) goto E;
    H:
        func_00240c08(Tz__MCard__GetPos(), 0, 32);
        func_00287d20(14);
        break;
    case 18:
        if (!func_00240a08(0)) goto H;
        Tz__MCard__GetDirInfo(-4);
        func_00287d20(19);
        break;
    case 19:
        if (func_00233e70(0)) break;
        r = func_00234758();
        if (r == 0) {
            func_002349c8(h, 0);
            st = Tz__MCard__ChkFileSize(1) ? 16 : 32;
            func_00240c08(Tz__MCard__GetPos(), 0, st);
            func_00287d20(14);
            break;
        }
        if (r == 1) { func_00240c08(Tz__MCard__GetPos(), 0, 32); func_00287d20(12); break; }
    E:
        func_002b5108(0x8a8c, h);
        func_00287bd0(7, 0);
        Tz__CmSLBase__SetupWarningConfirm(0);
        D_0035f0b0 = 0;
        break;
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0025b218

// 0025b5e0 (was src/anon/batch_w1580_g.cpp)
namespace n0025b5e0 {
void func_00287cc0(s32) asm("func_00287cc0");
extern u8 D_00372ea0[] asm("D_00372ea0");
void func_00234570(s32, s32) asm("func_00234570");
s32 func_002408d0(s32) asm("func_002408d0");
s32 func_00240ba0(void) asm("func_00240ba0");
void func_002417a0(void) asm("func_002417a0");
s32 func_00241a00(void) asm("func_00241a00");
s32 func_00241a48(void) asm("func_00241a48");
s16* func_00241f10(void) asm("func_00241f10");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287c00(s32) asm("func_00287c00");
void func_00287c30(void) asm("func_00287c30");
s32 func_00287cd0(void) asm("func_00287cd0");
void func_00287d20(s32) asm("func_00287d20");
void Tz__CmSLBase__SetupWarningConfirm(s32) asm("Tz__CmSLBase__SetupWarningConfirm");
void func_002b4ee0(void) asm("func_002b4ee0");
s32 func_002b4fb8(void) asm("func_002b4fb8");
void func_002b5108(s32, s32) asm("func_002b5108");
void func_002b5188(void*, s32) asm("func_002b5188");
/*TARGET 0025b5e0*/
void func_0025b5e0(void) asm("func_0025b5e0");
void func_0025b5e0(void) {
    s32 x = func_00240ba0();
    s32 m = func_00287cd0();
    if (m == 2) {
        if (func_002b4fb8() == 0) {
            func_00287c30();
            func_00287d20(0);
            s32 k = func_00287bc0();
            func_00287cc0(0);
            if (k == 12) {
                func_002417a0();
                func_002b5188(D_00372ea0, 0);
            }
        }
        return;
    }
    if (m == 0) {
        func_00287cc0(1);
    }
    s32 lt = func_00241f10()[1] < func_002408d0(0);
    s32 ok = lt == 0;
    if ((func_00241a00() && func_00241a48()) ||
        (func_00241a00() && !(func_00241f10()[1] < func_002408d0(2)))) {
        ok = 1;
    } else if (func_00241a48()) {
        if (!(func_00241f10()[1] < func_002408d0(1))) ok = 1;
    }
    if (ok) {
        func_002b4ee0();
        func_00287c00(12);
        func_00287cc0(2);
    } else {
        func_00234570(x, 0);
        func_002b5108(0xC6C8, x);
        func_00287bd0(7, 0);
        Tz__CmSLBase__SetupWarningConfirm(0);
    }
}
}  // namespace n0025b5e0

// 0025b7b8 (was src/anon/batch_wcx2.cpp)
namespace n0025b7b8 {
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
// ---- 0025b7b8
extern void* D_0035f64c asm("D_0035f64c");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00289380(void* s) asm("func_00289380");
s32 func_00289310_b7b8(void* s) asm("func_00289310");
s32 func_00233e70(s32 a) asm("func_00233e70");
bool func_002b55e0(void) asm("func_002b55e0");
void func_002b5658(void) asm("func_002b5658");
void func_00287c30(void) asm("func_00287c30");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0028af18_b7b8(void* s, u32 a) asm("func_0028af18");
void func_0028f7e8(s32 a) asm("func_0028f7e8");
void func_0025a1d0(void) asm("func_0025a1d0");
s32 func_00240ba0_b7b8(void) asm("func_00240ba0");
s32 func_002b5490(void) asm("func_002b5490");
void func_002b54f8(void) asm("func_002b54f8");
void func_00287cc0(s32 s) asm("func_00287cc0");
void func_0025d560(void) asm("func_0025d560");
s32 func_002348a8_b7b8(s32 slot, s32 a) asm("func_002348a8");
void func_00234570_b7b8(s32 slot, void* p) asm("func_00234570");
void func_0025d620(void) asm("func_0025d620");
s32 func_00287df0_b7b8(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a) asm("func_00242848");
s32 func_0028afa8_b7b8(void* s) asm("func_0028afa8");
void func_00240bc0(s32 a) asm("func_00240bc0");
void Tz__CmSLBase__SetupWarningWin(s32 a) asm("Tz__CmSLBase__SetupWarningWin");
s32 func_002419e8(void) asm("func_002419e8");
void func_002b5108_b7b8(u32 msg, s32 slot) asm("func_002b5108");
void Tz__CmSLBase__SetupWarningConfirm(s32 a) asm("Tz__CmSLBase__SetupWarningConfirm");
void func_00287bd0(s32 a, s32 b) asm("func_00287bd0");
void Tz__CMenuHelp__FadeOut(void) asm("Tz__CMenuHelp__FadeOut");
// sync_global_index_if_changed
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
// global_zero_4dwords
s32 func_00241c20(s32 a) asm("func_00241c20");
struct SaveEnt { u16 a; s16 b; u8 pad[4]; u32 flags; u8 pad2[20]; };
SaveEnt* func_00241f10(void) asm("func_00241f10");
s32 func_002408d0(s32 a) asm("func_002408d0");
void func_00241450(s32 a) asm("func_00241450");
void func_00287d20(s32 a) asm("func_00287d20");
s32 func_00241770(s32 a) asm("func_00241770");
void func_002400f8(s32 a) asm("func_002400f8");
void func_00287da0(void) asm("func_00287da0");
void func_002b5558(void) asm("func_002b5558");
void func_00287c00(s32 m) asm("func_00287c00");
void Tz__SelHist__FadeOut(s32 a) asm("Tz__SelHist__FadeOut");
/*TARGET 0025b7b8*/
// record884_refresh_by_index

// Memory-card load menu: per-frame state update.
void Tz__CmSave__CtrlList(void) asm("Tz__CmSave__CtrlList");
// record884_refresh_by_index

// Memory-card load menu: per-frame state update.
void Tz__CmSave__CtrlList(void) {
    s32 cur = func_00289380(D_0035f64c);
    s32 st = func_00287cd0();
    s32 slot = func_00240ba0_b7b8();
    if (st == 2) {
        func_00233e70(0);
        if (func_002b55e0()) {
            if (cur == -1 && !func_00289310_b7b8(D_0035f64c)) return;
            func_002b5658();
            return;
        }
        func_00287c30();
        s32 m = func_00287bc0();
        func_0028af18_b7b8(D_0035f64c, 115);
        if (m == 1) {
            func_0028f7e8(1);
            func_0025a1d0();
        }
        return;
    }
    if (cur != -1 || func_00289310_b7b8(D_0035f64c)) {
        if (!func_002b5490()) func_002b54f8();
    }
    if (st == 0 && func_002b5490()) {
        func_00287cc0(1);
        func_0025d560();
    }
    if (!func_00233e70(0)) {
        if (func_002348a8_b7b8(slot, 0) != 3) {
            func_00234570_b7b8(slot, 0);
        } else {
            Tz__CmSLBase__SetupWarningWin(-1);
            Tz__CmSLBase__SetupWarningConfirm(0);
            func_002b5108_b7b8(0xb85d, slot);
            func_00287bd0(5, 0);
            func_00234570_b7b8(slot, 0);
            Tz__CMenuHelp__FadeOut();  // sync_global_index_if_changed
            return;
        }
    }
    if (!func_00242848(func_00287df0_b7b8(cur, func_00289310_b7b8(D_0035f64c), 1, func_0025d620, 1))) {
        switch (cur) {
        case -2:
            func_002b5558();
            func_00287cc0(2);
            func_00287c00(1);
            Tz__SelHist__FadeOut(1);  // record884_refresh_by_index
            Tz__CMenuHelp__FadeOut();  // sync_global_index_if_changed
            break;
        case -4:
            Tz__CMenuHelp__FadeOut();  // sync_global_index_if_changed
            func_00287da0();
            break;
        case -1:
            break;
        default:
            if (cur >= 0 && cur < func_0028afa8_b7b8(D_0035f64c)) {
                func_00240bc0(cur);
                Tz__CmSLBase__SetupWarningWin(-1);
                if (func_002419e8()) {
                    func_002b5108_b7b8(0x8aa6, slot);
                    Tz__CmSLBase__SetupWarningConfirm(1);
                    func_00287bd0(8, 0);
                    func_00234570_b7b8(slot, 0);
                } else if (func_00241c20(cur) && func_00241f10()->b < func_002408d0(0)) {
                    func_00241450(1);
                    func_002b5108_b7b8(0x8a90, slot);
                    func_00287bd0(20, 0);
                    func_00287d20(60);
                } else if (func_00241770(cur)) {
                    func_00241450(1);
                    func_002b5108_b7b8(0x8aa4, slot);
                    func_00287bd0(13, 0);
                    Tz__CmSLBase__SetupWarningConfirm(1);
                    func_00234570_b7b8(slot, 0);
                } else if (*(u32*)((u8*)func_00241f10() + (cur << 5) + 8) & 0x40) {
                    func_002b5108_b7b8(0xc6c8, slot);
                    func_00287bd0(22, 0);
                    Tz__CmSLBase__SetupWarningConfirm(0);
                } else {
                    func_00241450(1);
                    func_002b5108_b7b8(0x8a90, slot);
                    func_00287bd0(14, 0);
                    func_00287d20(70);
                    func_002400f8(1);
                }
                Tz__CMenuHelp__FadeOut();  // sync_global_index_if_changed
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0025b7b8

// 0025bbe0 (was src/anon/batch_w1576.cpp)
namespace n0025bbe0 {
extern u8 D_0035f0b0 asm("D_0035f0b0");
s32 func_00240ba0(void) asm("func_00240ba0");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_002b4ff8(void) asm("func_002b4ff8");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00287d30(void) asm("func_00287d30");
s32 func_00233e70(s32) asm("func_00233e70");
s32 func_00234798(void) asm("func_00234798");
s32 func_00234758(void) asm("func_00234758");
void func_00241450(s32) asm("func_00241450");
void func_00287d20(s32) asm("func_00287d20");
s32 Tz__MCard__ChkFileSize(s32) asm("Tz__MCard__ChkFileSize");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_002400f8(s32) asm("func_002400f8");
void func_002b5108(s32, s32) asm("func_002b5108");
void Tz__CmSLBase__SetupWarningConfirm(s32) asm("Tz__CmSLBase__SetupWarningConfirm");
void Tz__MCard__GetDirInfo(s32) asm("Tz__MCard__GetDirInfo");
void func_00234570(s32, s32) asm("func_00234570");
/*TARGET 0025bbe0*/
void func_0025bbe0(void) asm("func_0025bbe0");
void func_0025bbe0(void) {
    s32 fail = 0;
    s32 id = func_00240ba0();
    s32 st = func_00287cd0();
    if (st == 2) return;
    if (func_002b4ff8() == 0) return;
    if (st == 0) func_00287cc0(1);
    switch (func_00287d30()) {
    case 0x3c:
        if (func_00233e70(0) == 0) {
            if (func_00234798() != 0) {
                fail = 1;
            } else {
                func_00241450(0);
                func_00287d20(0x3d);
            }
        }
        break;
    case 0x3e:
        if (func_00233e70(0) == 0) {
            if (func_00234758() != 0) {
                fail = 1;
            } else if (Tz__MCard__ChkFileSize(0) != 0) {
                func_00287bd0(0xe, 0);
                func_00287d20(0x46);
                func_002400f8(1);
            } else {
                func_002b5108(0xc6c8, id);
                func_00287bd0(0x16, 0);
                Tz__CmSLBase__SetupWarningConfirm(0);
            }
        }
        break;
    case 0x3d:
        if (func_00233e70(0) == 0) {
            if (func_00234798() != 0) {
                fail = 1;
            } else {
                Tz__MCard__GetDirInfo(-4);
                func_00287d20(0x3e);
            }
        }
        break;
    }
    if (fail) {
        Tz__CmSLBase__SetupWarningConfirm(0);
        func_002b5108(0x8a8b, id);
        func_00287bd0(7, 0);
        func_00234570(id, 0);
        D_0035f0b0 = 0;
    }
}
}  // namespace n0025bbe0

// 0025bd98 (was src/anon/batch_w1707.cpp)
namespace n0025bd98 {
extern u8 D_0035f0b0 asm("D_0035f0b0");
extern u8 D_0035f0b2 asm("D_0035f0b2");
extern s32 D_0035f674 asm("D_0035f674");
s32 func_00240ba0(void) asm("func_00240ba0");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_002b4fb8(void) asm("func_002b4fb8");
s32 func_00287c10(void) asm("func_00287c10");
s32 func_00233e70(s32) asm("func_00233e70");
s32 func_00233e60(void) asm("func_00233e60");
void func_00287c30(void) asm("func_00287c30");
void func_00287d20(s32) asm("func_00287d20");
s32 func_00287bc0(void) asm("func_00287bc0");
void Tz__CmSLBase__UpdateListMess(s32) asm("Tz__CmSLBase__UpdateListMess");
void func_0025cd40(void) asm("func_0025cd40");
void func_00287cc0(s32) asm("func_00287cc0");
void func_00240108(void) asm("func_00240108");
s32 func_002b4ff8(void) asm("func_002b4ff8");
s32 func_00287d30(void) asm("func_00287d30");
s32 func_00234798(void) asm("func_00234798");
s32 func_00234758(void) asm("func_00234758");
s32 func_002347a8(void) asm("func_002347a8");
s32 func_002347b8(void) asm("func_002347b8");
s32 func_002347c8(void) asm("func_002347c8");
s32 YI__MCARD__GetResultRead(void) asm("YI__MCARD__GetResultRead");
s32 func_002347e8(void) asm("func_002347e8");
s32 Tz__MCard__GetPos(void) asm("Tz__MCard__GetPos");
void Tz__MCard__GetDirInfo(s32) asm("Tz__MCard__GetDirInfo");
s32 func_002349c8(s32, s32) asm("func_002349c8");
void func_002414c0(void) asm("func_002414c0");
void func_00241450(s32) asm("func_00241450");
void Tz__MCard__MakeFname(s32) asm("Tz__MCard__MakeFname");
void Tz__MCard__UpdateLocalInfo(void) asm("Tz__MCard__UpdateLocalInfo");
u32 func_00241160(void) asm("func_00241160");
s32 func_00241358(void) asm("func_00241358");
void func_00241528(void) asm("func_00241528");
void func_002415a0(s32, s32, s32) asm("func_002415a0");
void func_00241568(s32) asm("func_00241568");
void func_00241320(void) asm("func_00241320");
s32 func_0028b8d0(s32) asm("func_0028b8d0");
s32 func_00241670(s32) asm("func_00241670");
void func_00241608(s32, s32, s32) asm("func_00241608");
void func_00240450(s32, s32) asm("func_00240450");
void func_00240a70(s32) asm("func_00240a70");
void func_00234570(s32, s32) asm("func_00234570");
s32 func_002348a8(s32, s32) asm("func_002348a8");
s32 func_00234888(s32, s32) asm("func_00234888");
void func_00240bb0(s32) asm("func_00240bb0");
void func_00241740(s32) asm("func_00241740");
void func_002417a0(void) asm("func_002417a0");
void func_0023d2c8(s32, s32) asm("func_0023d2c8");
void func_00242618(s32, s32) asm("func_00242618");
void func_002b4ee0(void) asm("func_002b4ee0");
void func_00287c00(s32) asm("func_00287c00");
void Tz__CmSLBase__SetupWarningConfirm(s32) asm("Tz__CmSLBase__SetupWarningConfirm");
void func_002b5108(s32, s32) asm("func_002b5108");
void func_00287bd0(s32, s32) asm("func_00287bd0");
/*TARGET 0025bd98*/
void func_0025bd98(void) asm("func_0025bd98");
void func_0025bd98(void) {
    s32 fail = 0;
    s32 id = func_00240ba0();
    u32 flags;
    if (func_00287cd0() == 2) {
        if (func_002b4fb8() != 0) return;
        if (func_00287c10() == 1) {
            func_00233e70(0);
            if (func_00233e60() == 0) return;
        }
        func_00287c30();
        func_00287d20(0);
        s32 next = func_00287bc0();
        if (next == 12 || next == 24) {
            Tz__CmSLBase__UpdateListMess(0);
            if (next == 24) func_0025cd40();
            func_00287cc0(0);
        }
        return;
    }
    func_00240108();
    if (func_002b4ff8() == 0) return;
    if (func_00287cd0() == 0) func_00287cc0(1);
    switch (func_00287d30()) {
    case 30:
        if (func_00233e70(0) == 0) {
            if (func_00234798() != 0) {
                fail = 1;
            } else {
                Tz__MCard__GetDirInfo(Tz__MCard__GetPos());
                func_00287d20(31);
            }
        }
        break;
    case 31:
        if (func_00233e70(0) == 0) {
            if (func_00234758() != 0) {
                fail = 1;
            } else if (func_002349c8(id, 0) <= 0) {
                func_002414c0();
                func_00287d20(32);
            } else {
                func_00241450(0);
                func_00287d20(33);
            }
        }
        break;
    case 32:
        if (func_00233e70(0) == 0) {
            if (func_002347a8() != 0) {
                fail = 1;
            } else {
                Tz__MCard__MakeFname(Tz__MCard__GetPos());
                func_00241450(0);
                func_00287d20(33);
            }
        }
        break;
    case 33:
        if (func_00233e70(0) == 0) {
            if (func_00234798() != 0) {
                fail = 1;
            } else {
                Tz__MCard__GetDirInfo(-4);
                func_00287d20(34);
            }
        }
        break;
    case 34:
        if (func_00233e70(0) == 0) {
            if (func_00234758() != 0) {
                fail = 1;
            } else {
                Tz__MCard__UpdateLocalInfo();
                flags = func_00241160();
                if (flags & 0xff0) {
                    func_00241358();
                    func_00241528();
                    func_00287d20(35);
                } else {
                    Tz__MCard__MakeFname(-2);
                    if (!(flags & 2)) {
                        func_00241568(0);
                        func_00287d20(37);
                    } else {
                        func_002415a0(1, 0, 0);
                        func_00287d20(36);
                    }
                }
            }
        }
        break;
    case 35:
        if (func_00233e70(0) == 0) {
            if (func_002347c8() != 0) {
                fail = 1;
            } else {
                func_00241320();
                if (func_00241358() < 0) {
                    flags = func_00241160();
                    Tz__MCard__MakeFname(-2);
                    if (!(flags & 2)) {
                        func_00241568(0);
                        func_00287d20(37);
                    } else {
                        func_002415a0(1, 0, 0);
                        func_00287d20(36);
                    }
                } else {
                    func_00241528();
                }
            }
        }
        break;
    case 36:
        if (func_00233e70(0) == 0) {
            if (YI__MCARD__GetResultRead() != 0) {
                fail = 1;
            } else if (func_00241670(func_0028b8d0(D_0035f674)) != 0) {
                Tz__MCard__MakeFname(-3);
                func_00241568(0);
                func_00287d20(39);
            } else {
                func_00241608(1, 0, func_0028b8d0(D_0035f674));
                func_00287d20(38);
            }
        }
        break;
    case 37:
        if (func_00233e70(0) == 0) {
            if (func_002347b8() != 0) {
                fail = 1;
            } else {
                func_00241608(1, 0, func_0028b8d0(D_0035f674));
                func_00287d20(38);
            }
        }
        break;
    case 38:
        if (func_00233e70(0) == 0) {
            if (func_002347e8() != 0) {
                fail = 1;
            } else {
                Tz__MCard__MakeFname(-3);
                flags = func_00241160();
                if (!(flags & 1)) {
                    func_00241568(0);
                    func_00287d20(39);
                } else {
                    func_00240450(0, Tz__MCard__GetPos());
                    func_00241608(0, 0, 0);
                    func_00287d20(40);
                }
            }
        }
        break;
    case 39:
        if (func_00233e70(0) == 0) {
            if (func_002347b8() != 0) {
                fail = 1;
            } else {
                func_00240450(0, Tz__MCard__GetPos());
                func_00241608(0, 0, 0);
                func_00287d20(40);
            }
        }
        break;
    case 40:
        if (func_00233e70(0) == 0) {
            if (func_002347e8() != 0) {
                fail = 1;
            } else {
                Tz__MCard__MakeFname(Tz__MCard__GetPos());
                func_00240a70(0);
                flags = func_00241160();
                if (flags & 4) {
                    func_00241608(2, 0, 0);
                    func_00287d20(42);
                } else {
                    func_00241568(0);
                    func_00287d20(41);
                }
            }
        }
        break;
    case 41:
        if (func_00233e70(0) == 0) {
            if (func_002347b8() != 0) {
                fail = 1;
            } else {
                func_00241608(2, 0, 0);
                func_00287d20(42);
            }
        }
        break;
    case 42:
        if (func_00233e70(0) == 0) {
            if (func_002347e8() != 0) {
                fail = 1;
            } else {
                func_00234570(id, 0);
                func_00287d20(43);
            }
        }
        break;
    case 43:
        if (func_00233e70(0) == 0) {
            id = func_00240ba0();
            if (func_002348a8(id, 0) == 3) {
                fail = 1;
            } else {
                func_00240bb0(func_00234888(id, 0));
                func_00241740(-1);
                func_002417a0();
                func_0023d2c8(id, Tz__MCard__GetPos());
                func_00242618(12, 1);
                func_002b4ee0();
                func_00287c00(D_0035f0b2 != 0 ? 24 : 12);
                func_00287cc0(2);
                func_00287d20(0);
            }
        }
        break;
    }
    if (fail) {
        Tz__CmSLBase__SetupWarningConfirm(0);
        func_002b5108(0x8a8b, id);
        func_00287bd0(7, 0);
        func_00234570(id, 0);
        D_0035f0b0 = 0;
    }
}
}  // namespace n0025bd98

// 0025c3c0 (was src/anon/batch_w1708.cpp)
namespace n0025c3c0 {
extern u8 D_0035f0b0 asm("D_0035f0b0");
extern s32 D_0035eca4 asm("D_0035eca4");
extern s32 D_0035f674 asm("D_0035f674");
s32 func_00240ba0(void) asm("func_00240ba0");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_002b4fb8(void) asm("func_002b4fb8");
s32 func_002b4ff8(void) asm("func_002b4ff8");
void func_00287c30(void) asm("func_00287c30");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00287d30(void) asm("func_00287d30");
void func_00240108(void) asm("func_00240108");
s32 func_001058e8(void) asm("func_001058e8");
s32 func_001058d8(s32) asm("func_001058d8");
s32 func_002421e8(s32) asm("func_002421e8");
void func_002420d8(s32, s32) asm("func_002420d8");
s32 func_00233e70(s32) asm("func_00233e70");
s32 func_00234758(void) asm("func_00234758");
s32 func_00234798(void) asm("func_00234798");
s32 func_002347a8(void) asm("func_002347a8");
s32 func_002347b8(void) asm("func_002347b8");
s32 func_002347c8(void) asm("func_002347c8");
s32 YI__MCARD__GetResultRead(void) asm("YI__MCARD__GetResultRead");
s32 func_002347e8(void) asm("func_002347e8");
s32 func_002349c8(s32, s32) asm("func_002349c8");
s32 func_002348a8(s32, s32) asm("func_002348a8");
s32 func_00234888(s32, s32) asm("func_00234888");
void func_00234570(s32, s32) asm("func_00234570");
void func_00241450(s32) asm("func_00241450");
void func_00287d20(s32) asm("func_00287d20");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287c00(s32) asm("func_00287c00");
void func_002400f8(s32) asm("func_002400f8");
void func_002b5108(s32, s32) asm("func_002b5108");
void Tz__CmSLBase__SetupWarningConfirm(s32) asm("Tz__CmSLBase__SetupWarningConfirm");
s32 Tz__MCard__GetPos(void) asm("Tz__MCard__GetPos");
void Tz__MCard__GetDirInfo(s32) asm("Tz__MCard__GetDirInfo");
void Tz__MCard__MakeFname(s32) asm("Tz__MCard__MakeFname");
void func_00240450(s32, s32) asm("func_00240450");
void func_00240bb0(s32) asm("func_00240bb0");
void func_002414c0(void) asm("func_002414c0");
void Tz__MCard__UpdateLocalInfo(void) asm("Tz__MCard__UpdateLocalInfo");
u32 func_00241160(void) asm("func_00241160");
void func_00241320(void) asm("func_00241320");
s32 func_00241358(void) asm("func_00241358");
void func_00241528(void) asm("func_00241528");
void func_00241568(s32) asm("func_00241568");
void func_002415a0(s32, s32, s32) asm("func_002415a0");
void func_00241608(s32, s32, s32) asm("func_00241608");
s32 func_00241670(s32) asm("func_00241670");
s32 func_00241a48(void) asm("func_00241a48");
void func_00241a70(void) asm("func_00241a70");
s32 func_002420d0(s32) asm("func_002420d0");
void func_00242110(s32) asm("func_00242110");
s32 Tz__McSys__isEnableDataKH2(s32) asm("Tz__McSys__isEnableDataKH2");
void func_002421c0(s32) asm("func_002421c0");
s32 func_0028b8d0(s32) asm("func_0028b8d0");
s32 func_0028b8d8(s32) asm("func_0028b8d8");
/*TARGET 0025c3c0*/
void func_0025c3c0(void) asm("func_0025c3c0");
void func_0025c3c0(void) {
    s32 fail = 0;
    s32 id = func_00240ba0();
    u32 flags;
    if (func_00287cd0() == 2) {
        if (func_002b4fb8() != 0) return;
        func_00287c30();
        func_00287d20(0);
        if (func_00287bc0() != 0xf) return;
        func_00241450(1);
        func_00287bd0(0xf, 0);
        func_00287d20(0x1e);
        func_002400f8(0);
        func_00287cc0(0);
        return;
    }
    func_00240108();
    if (func_002b4ff8() == 0) return;
    if (func_00287cd0() == 0) {
        func_00287cc0(1);
        if (func_001058d8(func_001058e8()) != 0 && func_002421e8(D_0035eca4) == 0) {
            func_002420d8(D_0035eca4, 1);
        }
    }
    switch (func_00287d30()) {
    case 0x46:
        if (func_00233e70(0) == 0) {
            if (func_00234798() != 0) {
                fail = 1;
            } else {
                Tz__MCard__GetDirInfo(Tz__MCard__GetPos());
                func_00287d20(0x47);
            }
        }
        break;
    case 0x47:
        if (func_00233e70(0) == 0) {
            if (func_00234758() != 0) {
                fail = 1;
            } else if (func_002349c8(id, 0) <= 0) {
                func_002414c0();
                func_00287d20(0x48);
            } else {
                func_00241450(0);
                func_00287d20(0x49);
            }
        }
        break;
    case 0x48:
        if (func_00233e70(0) == 0) {
            if (func_002347a8() != 0) {
                fail = 1;
            } else {
                Tz__MCard__MakeFname(Tz__MCard__GetPos());
                func_00241450(0);
                func_00287d20(0x49);
            }
        }
        break;
    case 0x49:
        if (func_00233e70(0) == 0) {
            if (func_00234798() != 0) {
                fail = 1;
            } else {
                Tz__MCard__GetDirInfo(-4);
                func_00287d20(0x4a);
            }
        }
        break;
    case 0x4a:
        if (func_00233e70(0) == 0) {
            if (func_00234758() != 0) {
                fail = 1;
            } else {
                Tz__MCard__UpdateLocalInfo();
                flags = func_00241160();
                if (flags & 0xff0) {
                    func_00241358();
                    func_00241528();
                    func_00287d20(0x4b);
                } else {
                    Tz__MCard__MakeFname(-2);
                    if (!(flags & 2)) {
                        func_00241568(0);
                        func_00287d20(0x4d);
                    } else {
                        func_002415a0(1, 0, 0);
                        func_00287d20(0x4c);
                    }
                }
            }
        }
        break;
    case 0x4b:
        if (func_00233e70(0) == 0) {
            if (func_002347c8() != 0) {
                fail = 1;
            } else {
                func_00241320();
                if (func_00241358() < 0) {
                    flags = func_00241160();
                    Tz__MCard__MakeFname(-2);
                    if (!(flags & 2)) {
                        func_00241568(0);
                        func_00287d20(0x4d);
                    } else {
                        func_002415a0(1, 0, 0);
                        func_00287d20(0x4c);
                    }
                } else {
                    func_00241528();
                }
            }
        }
        break;
    case 0x4c:
        if (func_00233e70(0) == 0) {
            if (YI__MCARD__GetResultRead() != 0) {
                fail = 1;
            } else if (func_00241670(func_0028b8d0(D_0035f674)) != 0) {
                Tz__MCard__MakeFname(-3);
                func_00241568(0);
                func_00287d20(0x4f);
            } else {
                func_00241608(1, 0, func_0028b8d8(D_0035f674));
                func_00287d20(0x4e);
            }
        }
        break;
    case 0x4d:
        if (func_00233e70(0) == 0) {
            if (func_002347b8() != 0) {
                fail = 1;
            } else {
                func_00241608(1, 0, func_0028b8d8(D_0035f674));
                func_00287d20(0x4e);
            }
        }
        break;
    case 0x4e:
        if (func_00233e70(0) == 0) {
            if (func_002347e8() != 0) {
                fail = 1;
            } else {
                Tz__MCard__MakeFname(-3);
                flags = func_00241160();
                bool no = !(flags & 1);
                if (no) {
                    func_00241568(0);
                    func_00287d20(0x4f);
                } else {
                    func_00240450(0, Tz__MCard__GetPos());
                    func_00241608(0, 0, 0);
                    func_00287d20(0x50);
                }
            }
        }
        break;
    case 0x4f:
        if (func_00233e70(0) == 0) {
            if (func_002347b8() != 0) {
                fail = 1;
            } else {
                func_00240450(0, Tz__MCard__GetPos());
                func_00241608(0, 0, 0);
                func_00287d20(0x50);
            }
        }
        break;
    case 0x50:
        if (func_00233e70(0) == 0) {
            if (func_002347e8() != 0) {
                fail = 1;
            } else {
                Tz__MCard__MakeFname(Tz__MCard__GetPos());
                flags = func_00241160();
                if (!(flags & 4)) {
                    func_00241568(0);
                    func_00287d20(0x51);
                } else if (flags & 2) {
                    bool no = !(flags & 1);
                    if (no) {
                        func_002421c0(D_0035eca4);
                        func_00287d20(0x53);
                    } else {
                        func_002415a0(2, 0, func_002420d0(D_0035eca4));
                        func_00287d20(0x52);
                    }
                } else {
                    func_002421c0(D_0035eca4);
                    func_00287d20(0x53);
                }
            }
        }
        break;
    case 0x51:
        if (func_00233e70(0) == 0) {
            if (func_002347b8() != 0) {
                fail = 1;
            } else {
                func_002421c0(D_0035eca4);
                func_00287d20(0x53);
            }
        }
        break;
    case 0x52:
        if (func_00233e70(0) == 0) {
            if (YI__MCARD__GetResultRead() != 0) {
                fail = 1;
            } else if (Tz__McSys__isEnableDataKH2(D_0035eca4) != 0) {
                func_00287d20(0x53);
            } else {
                func_002421c0(D_0035eca4);
                func_00287d20(0x53);
            }
        }
        break;
    case 0x53:
        func_00242110(D_0035eca4);
        func_00241608(2, 0, func_002420d0(D_0035eca4));
        func_00287d20(0x54);
        break;
    case 0x54:
        if (func_00233e70(0) == 0) {
            if (func_002347e8() != 0) {
                fail = 1;
            } else {
                func_00234570(id, 0);
                func_00287d20(0x55);
            }
        }
        break;
    case 0x55:
        if (func_00233e70(0) == 0) {
            id = func_00240ba0();
            if (func_002348a8(id, 0) == 3) {
                fail = 1;
            } else {
                func_00240bb0(func_00234888(id, 0));
                if (func_00241a48() == 0) func_00241a70();
                func_00287c00(0xf);
                func_00287d20(0);
                func_00287cc0(2);
            }
        }
        break;
    }
    if (fail) {
        Tz__CmSLBase__SetupWarningConfirm(0);
        func_002b5108(0x8a8b, id);
        func_00287bd0(7, 0);
        func_00234570(id, 0);
        D_0035f0b0 = 0;
        func_002400f8(0);
    }
}
}  // namespace n0025c3c0

// 0025ca78 (was src/anon/auto80_199_queue.cpp)
namespace n0025ca78 {
/*TARGET 0025ca78*/
u32 func_0025ca78(void) asm("_Z13func_0025ca78v");
u32 func_0025ca78(void) {
    Tz__CmComm__CreateConfirmSelector(D_0035f650, 30064, 0, 0, D_0035f664, 1, (u32)&D_00372e98);
    func_00288f48(D_0035f650, 128, 64, 0, 0);
    func_0028af28(D_0035f650, 64);
    func_00287cc0(0);
    return func_0025d560();
}
}  // namespace n0025ca78

// 0025caf0 (was src/anon/batch_w292.cpp)
namespace n0025caf0 {
// 0x002add90: definition moved into src/anon/unit_002a99c8.cpp

extern s32 D_0035f650 asm("D_0035f650");
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_0028acc8(s32) asm("func_0028acc8");
s32 func_00289310(s32) asm("func_00289310");
void func_00287f90(s32) asm("func_00287f90");
void func_0028abe0(s32) asm("func_0028abe0");
void func_00287c30(void) asm("func_00287c30");
void func_0025d560(void) asm("func_0025d560");
s32 func_0028ae28(s32, s32) asm("func_0028ae28");
void func_0028ab20(s32) asm("func_0028ab20");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_0028aa40(s32) asm("func_0028aa40");
void func_00287c00(s32) asm("func_00287c00");
void func_0025ccc0(void) asm("func_0025ccc0");
void func_00287bd0(s32, s32) asm("func_00287bd0");
/*TARGET 0025caf0*/
void Tz__CmSave__CtrlWMapConfirm(void) asm("Tz__CmSave__CtrlWMapConfirm");
void Tz__CmSave__CtrlWMapConfirm(void)
{
    s32 a = func_00289380(D_0035f650);
    s32 st = func_00287cd0();
    if (st == 2) {
        if (func_0028acc8(D_0035f650)) {
            if (a != -1 || func_00289310(D_0035f650)) {
                func_00287f90(0);
                func_0028abe0(D_0035f650);
            }
        } else {
            func_00287c30();
            func_0025d560();
        }
        return;
    }
    if (a != -1 || func_00289310(D_0035f650)) {
        if (!func_0028ae28(D_0035f650, 0)) func_0028ab20(D_0035f650);
    }
    if (st == 0 && func_0028ae28(D_0035f650, 0)) func_00287cc0(1);
    if (func_00242848(func_00287df0(a, func_00289310(D_0035f650), 1, 0, 1))) return;
    switch (a) {
    case -1:
        break;
    case -2:
    case 0:
        func_0028aa40(D_0035f650);
        func_00287cc0(2);
        func_00287c00(0);
        break;
    case 1:
        func_0025ccc0();
        func_00287bd0(23, 0);
        break;
    }
}
}  // namespace n0025caf0

// 0025ccc0 (was src/anon/batch_w10.cpp)
namespace n0025ccc0 {
void* func_0014aba8(void) asm("func_0014aba8");
void func_0014aa58(void*, s32, s32) asm("func_0014aa58");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 0025ccc0*/
void func_0025ccc0(void) asm("func_0025ccc0");
void func_0025ccc0(void) {
    func_0014aa58(func_0014aba8(), 15, 0);
    func_00287cc0(0);
}
}  // namespace n0025ccc0

// 0025ccf0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0025ccf0 {
void func_00103c80(...) asm("func_00103c80");
void func_002597f0(...) asm("func_002597f0");
void func_00287da0(...) asm("_ZN2Tz8MenuBase7SetExitEv");
u32 func_00287cc0(...) asm("func_00287cc0");
u32 func_0014aba8(...) asm("func_0014aba8");
/*TARGET 0025ccf0*/
void func_0025ccf0() asm("_Z13func_0025ccf0v");
void func_0025ccf0() {
    u32 v0 = func_0014aba8();
    u32 t7 = *(u32*)(v0 + 252);
    t7 ^= 4;
    if (t7 == 0) {
        func_00103c80(1);
        func_00287cc0(2);
        func_00287da0();
        func_002597f0();
    }
}
}  // namespace n0025ccf0

// 0025cd40 (was src/anon/batch_w19.cpp)
namespace n0025cd40 {
void* func_0014aba8(void) asm("func_0014aba8");
void func_0014aa58(void*, s32, s32) asm("func_0014aa58");
void func_002bd760(s32) asm("func_002bd760");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 0025cd40*/
void func_0025cd40(void) asm("func_0025cd40");
void func_0025cd40(void) {
    func_0014aa58(func_0014aba8(), 15, 0);
    func_002bd760(60);
    func_00287cc0(0);
}
}  // namespace n0025cd40

// 0025cd78 (was src/anon/auto80_199_queue.cpp)
namespace n0025cd78 {
u32 func_002597f0(void) asm("_Z13func_002597f0v");
/*TARGET 0025cd78*/
void func_0025cd78(void) asm("_Z13func_0025cd78v");
void func_0025cd78(void) {
    u32 v0 = func_0014aba8();
    u32 t7 = *(u32*)(v0 + 252);
    t7 = t7 ^ 4;

    s32 a0v = 3;
    if (t7 != 0) {
        return;
    }

    func_00103c80(a0v);
    func_00287cc0(2);
    func_00287da0();
    func_002597f0();
    func_00288658(-1, -1);
    Tz__Ending__SoundBufferFree();
}
}  // namespace n0025cd78

// 0025cde0 (was src/anon/batch_w1709.cpp)
namespace n0025cde0 {
struct W1709Layout;
struct W1709Select;
struct W1709LightCur { u8 pad[0x18c]; s32 item; };
extern W1709Select* D_0035f64c asm("D_0035f64c");
extern W1709Select* D_0035f650 asm("D_0035f650");
extern W1709Layout* D_0035f664 asm("D_0035f664");
extern W1709LightCur* D_0035f67c asm("D_0035f67c");
extern s32 D_0035f640 asm("D_0035f640");
extern s32 D_0035f644 asm("D_0035f644");
extern s32 D_0035f66c asm("D_0035f66c");
extern s32 D_0035f670 asm("D_0035f670");
extern u16 D_00372ec0[] asm("D_00372ec0");
u32 mb_GetMode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
s32 mb_GetNextMode(void) asm("_ZN2Tz8MenuBase11GetNextModeEv");
u32 ci_isPadHelpVisible(void) asm("_ZN2Tz6CmItem16isPadHelpVisibleEv");
s32 obj_isActive(W1709Layout*) asm("_Z16u_call4_00139d78jjjj");
s32 lay_getNum(W1709Layout*) asm("_ZN2Tz6Layout6getNumEv");
void lay_setNum(W1709Layout*, s32, s32) asm("_ZN2Tz6Layout6setNumEii");
s32 sel_isCreated(W1709Select*) asm("_ZN2Tz6Select9isCreatedEz");
s32 sel_isFadeOut(W1709Select*) asm("_ZN2Tz6Select9isFadeOutEv");
void sel_Start(W1709Select*) asm("_ZN2Tz6Select5StartEz");
s32 sel_GetCurrentItemPtr(W1709Select*) asm("_ZN2Tz6Select17GetCurrentItemPtrEv");
void cmsl_FadeOutWarningWin(void) asm("_ZN2Tz8CmSLBase17FadeOutWarningWinEv");
void cmsl_FadeOutList(void) asm("_ZN2Tz8CmSLBase11FadeOutListEv");
void sh_FadeOutAll(void) asm("_ZN2Tz7SelHist10FadeOutAllEv");
void lc_FadeOut(W1709LightCur*) asm("_ZN2Tz8LightCur7FadeOutEv");
void lc_Leave(W1709LightCur*) asm("_ZN2Tz8LightCur5LeaveEv");
s32 lc_isExist(W1709LightCur*) asm("_ZN2Tz8LightCur7isExistEv");
void help_Leave(void) asm("_ZN2Tz9CMenuHelp5LeaveEv");
void mc_DeleteAll(...) asm("_ZN2Tz10MenuCursor9DeleteAllEz");
s32 slr_GetState(void) asm("_ZN2Tz8Selector8GetStateEv");
void func_0028ffe8(s32, s32) asm("func_0028ffe8");
void func_00290508(s32, s32) asm("func_00290508");
void func_002b6418(void) asm("func_002b6418");
s32 func_0028d008(s32) asm("func_0028d008");
void func_0028cdb8(s32) asm("func_0028cdb8");
void Tz__MenuCursor__Create(s32, s32, s32, W1709Layout*, s32, s32) asm("Tz__MenuCursor__Create");
void Tz__MenuCursor__SetParent(s32, s32) asm("Tz__MenuCursor__SetParent");
void Tz__MenuCursor__SetType(s32, s32) asm("Tz__MenuCursor__SetType");
s32 func_0028cf10(s32) asm("func_0028cf10");
void Tz__LightCur__Create(W1709LightCur*, s32, s32, s32, W1709Layout*, u16*, s32) asm("Tz__LightCur__Create");
void func_0028d660(W1709LightCur*, s32) asm("func_0028d660");
void func_0025d3c8(W1709Select*, u32, s32) asm("func_0025d3c8");
static inline s32 W1709_UseSubCursor(W1709Select* sel) {
    if (sel != D_0035f64c && sel_isCreated(D_0035f64c)) return 1;
    return 0;
}
/*TARGET 0025cde0*/
void Tz__CmSave__Draw(void) asm("Tz__CmSave__Draw");
void Tz__CmSave__Draw(void) {
    u32 mode = mb_GetMode();
    W1709Select* sel;
    s32 sub;

    if (ci_isPadHelpVisible()) {
        if (obj_isActive(D_0035f664)) {
            if (lay_getNum(D_0035f664) != 2) lay_setNum(D_0035f664, 2, -1);
        }
        if (sel_isCreated(D_0035f64c) && !sel_isFadeOut(D_0035f64c)) sel_Start(D_0035f64c);
        if (sel_isCreated(D_0035f650) && !sel_isFadeOut(D_0035f650)) sel_Start(D_0035f650);
        cmsl_FadeOutWarningWin();
        cmsl_FadeOutList();
        sh_FadeOutAll();
        lc_FadeOut(D_0035f67c);
        help_Leave();
        func_0028ffe8(D_0035f66c, 1);
        func_00290508(D_0035f670, 1);
        mc_DeleteAll();
    }
    func_002b6418();
    if (ci_isPadHelpVisible()) return;

    switch (mode) {
    case 0: case 1: case 12:
        sel = D_0035f64c;
        break;
    default:
        sel = 0;
        break;
    case 5: case 7: case 8: case 10: case 13: case 19: case 22:
        sel = D_0035f650;
        break;
    }

    if (sel == 0) {
        if (mode == 15 || mode == 9 || mode == 20 || mode == 14) {
            if (!func_0028d008(1)) func_0028cdb8(1);
            if (!func_0028d008(0)) {
                Tz__MenuCursor__Create(0, 0, 0, D_0035f664, 12, 10);
                Tz__MenuCursor__SetParent(0, sel_GetCurrentItemPtr(D_0035f64c));
                Tz__MenuCursor__SetType(0, 1);
            } else if (func_0028cf10(0) != 1) {
                Tz__MenuCursor__SetType(0, 1);
            }
        } else {
            mc_DeleteAll();
        }
        lc_Leave(D_0035f67c);
        return;
    }

    sub = W1709_UseSubCursor(sel);

    if (sel_isCreated(sel) && slr_GetState() == 1) {
        if (!func_0028d008(sub)) {
            Tz__MenuCursor__Create(sub, 0, 0, D_0035f664, 12, 10);
            Tz__MenuCursor__SetParent(sub, sel_GetCurrentItemPtr(sel));
            if (!lc_isExist(D_0035f67c))
                Tz__LightCur__Create(D_0035f67c, 0x7571, 0, 0, D_0035f664, D_00372ec0, 0);
            if (sub) {
                if (!func_0028d008(0)) {
                    Tz__MenuCursor__Create(0, D_0035f644, D_0035f640, D_0035f664, 12, 10);
                    Tz__MenuCursor__SetParent(0, sel_GetCurrentItemPtr(D_0035f64c));
                }
                Tz__MenuCursor__SetType(0, 1);
            }
            func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(sel));
        } else {
            if (func_0028cf10(sub) == 1) Tz__MenuCursor__SetType(sub, 0);
            if (!lc_isExist(D_0035f67c)) {
                Tz__LightCur__Create(D_0035f67c, 0x7571, 0, 0, D_0035f664, D_00372ec0, 0);
                func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(sel));
            }
        }
    } else if (slr_GetState() == 2) {
        if ((mode == 13 || mode == 8) && mb_GetNextMode() != 12) {
            if (func_0028d008(sub)) func_0028cdb8(sub);
            if (lc_isExist(D_0035f67c)) lc_FadeOut(D_0035f67c);
        } else {
            if (func_0028d008(sub)) {
                func_0028cdb8(sub);
                if (sub) {
                    Tz__MenuCursor__SetType(0, 0);
                    func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(D_0035f64c));
                } else {
                    lc_FadeOut(D_0035f67c);
                }
            } else if (lc_isExist(D_0035f67c)) {
                if (sub) {
                    func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(D_0035f64c));
                } else {
                    lc_FadeOut(D_0035f67c);
                }
            }
        }
        if (sub && sel_isFadeOut(D_0035f64c) && func_0028d008(0)) {
            func_0028cdb8(0);
            lc_FadeOut(D_0035f67c);
        }
    }

    if (sub && sel_isCreated(sel) && slr_GetState() == 0 && lc_isExist(D_0035f67c)) {
        s32 item = D_0035f67c->item;
        if (item != sel_GetCurrentItemPtr(sel))
            func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(sel));
    }

    switch (mode) {
    case 0: case 1: case 5: case 7: case 8: case 10: case 12: case 13: case 19:
        func_0025d3c8(sel, mode, sub);
        break;
    }
}
}  // namespace n0025cde0

// 0025d3c8 (was src/anon/batch_w1598.cpp)
namespace n0025d3c8 {
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00289310(u32) asm("func_00289310");
void func_002890e0(u32, s32, s32, s32, s32) asm("func_002890e0");
u32 func_002891e8(u32) asm("func_002891e8");
void func_00289038(u32, u32, s32, s32, s32, s32, s32) asm("func_00289038");
s32 func_00289358(u32) asm("func_00289358");
void Tz__CmSLBase__UpdateListMess(s32) asm("Tz__CmSLBase__UpdateListMess");
s32 func_0028d008(u32) asm("func_0028d008");
u32 func_002891d0(u32) asm("func_002891d0");
void Tz__MenuCursor__SetParent(u32, u32) asm("Tz__MenuCursor__SetParent");
s32 func_0028d6e8(u32) asm("func_0028d6e8");
void func_0028d660(u32, u32) asm("func_0028d660");
void func_0025d560(void) asm("func_0025d560");
extern u32 D_0035f67c asm("D_0035f67c");
/*TARGET 0025d3c8*/
void func_0025d3c8(u32 a0, s32 a1, u32 a2) asm("func_0025d3c8");
void func_0025d3c8(u32 a0, s32 a1, u32 a2) {
    if (func_00287cd0() != 1) return;
    if (!func_00289310(a0)) return;
    func_002890e0(a0, 1, 2, 0, -1);
    func_00289038(a0, func_002891e8(a0), 1, 1, 2, 0, -1);
    if (a1 == 12 && func_00289358(a0)) Tz__CmSLBase__UpdateListMess(0);
    if (func_0028d008(a2)) Tz__MenuCursor__SetParent(a2, func_002891d0(a0));
    if (func_0028d6e8(D_0035f67c)) func_0028d660(D_0035f67c, func_002891d0(a0));
    func_0025d560();
}
}  // namespace n0025d3c8

// 0025d4e8 (was src/anon/auto80_199_queue.cpp)
namespace n0025d4e8 {
/*TARGET 0025d4e8*/
void func_0025d4e8(void) asm("_Z13func_0025d4e8v");
void func_0025d4e8(void) {
    if (func_00139d78(D_0035f668) != 0) {
        Obj0025d4e8* obj = (Obj0025d4e8*)D_0035f668;
        obj->vtbl->fn20(obj);
    }

    if (func_00290060(D_0035f66c) != 0) {
        func_0028ff68(D_0035f66c);
    }

    if (func_00290580(D_0035f670) != 0) {
        func_00290488(D_0035f670);
    }

    Tz__SelHist__LeaveAll();
}
}  // namespace n0025d4e8

// 0025d560 (was src/anon/batch_w1594.cpp)
namespace n0025d560 {
u32 func_00287bc0(void) asm("func_00287bc0");
u32 func_0028b040(u32) asm("func_0028b040");
void func_002b6338(u32, u32, u32, u32) asm("func_002b6338");
u32 Tz__CMenuHelp__Create_2(u32, u32) asm("Tz__CMenuHelp__Create_2");
u32 func_00263a58(u32, u32) asm("func_00263a58");
u32 func_00263d28(void) asm("func_00263d28");
extern u32 D_0035f64c asm("D_0035f64c");
extern u32 D_0035f6c4 asm("D_0035f6c4");
extern u16 D_00372f40[] asm("D_00372f40");
/*TARGET 0025d560*/
u32 func_0025d560(void) asm("func_0025d560");
u32 func_0025d560(void) {
    u32 v0 = func_00287bc0();
    u32 id;
    if (v0 == 0) {
        v0 = func_0028b040(D_0035f64c);
        return func_00263a58(D_00372f40[v0], 1);
    }
    id = 0x8A82;
    if (v0 == 19) {
        return func_00263a58(id, 1);
    }
    if (v0 == 1) {
        u32 a3 = func_0028b040(D_0035f64c);
        func_002b6338(D_0035f6c4, 512, 0xB85A, a3);
        return Tz__CMenuHelp__Create_2(D_0035f6c4, 1);
    }
    if (v0 == 12) {
        return func_00263a58(0x8AA1, 1);
    }
    return func_00263d28();
}
}  // namespace n0025d560

// 0025d620 (was src/anon/batch_w55.cpp)
namespace n0025d620 {
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00253578(void) asm("func_00253578");
/*TARGET 0025d620*/
s32 func_0025d620(s32 a) asm("func_0025d620");
s32 func_0025d620(s32 a) {
    s32 r = 1;
    switch (func_00287bc0()) {
    case 0:
        if (a && func_00253578()) r = 0;
        break;
    case 1:
    case 12:
        r = 1;
        break;
    default:
        r = 0;
        break;
    }
    return r;
}
}  // namespace n0025d620

// 0025d6a0 (was gap)
namespace n0025d6a0 {
extern u8 D_0035f070 asm("D_0035f070");
extern u8 D_0035f0b0 asm("D_0035f0b0");
extern u8 D_0035f0b1 asm("D_0035f0b1");
extern u8 D_0035f0b2 asm("D_0035f0b2");
extern u32 D_0035eca4 asm("D_0035eca4");
extern u32 D_0035f64c asm("D_0035f64c");
extern u8 D_00372f20[] asm("D_00372f20");
extern u8 D_00372eb8[] asm("D_00372eb8");
void func_002b4ac8(s32, s32) asm("func_002b4ac8");
void func_002b4ae0(s32) asm("func_002b4ae0");
void func_002b4af0(void*) asm("func_002b4af0");
void func_00258ce8(void*) asm("func_00258ce8");
void Tz__CmSLBase__Init() asm("Tz__CmSLBase__Init");
void func_002420d8(u32, s32) asm("func_002420d8");
u8* func_00103eb0() asm("func_00103eb0");
void TASK_MANAGER__create_thread(u32, u32, u32, u32, u32) asm("TASK_MANAGER__create_thread");
void func_0014a248() asm("func_0014a248");
void func_002b47a0() asm("func_002b47a0");
s32 YS__CACHE_BUFF__IsFlushing() asm("YS__CACHE_BUFF__IsFlushing");
void func_00170888(u32) asm("func_00170888");
void func_00253818(s32) asm("func_00253818");
void Tz__CmComm__DataLoad(s32) asm("Tz__CmComm__DataLoad");
void Tz__CmComm__DataLoadWait(s32, u32) asm("Tz__CmComm__DataLoadWait");
void func_002b63a8() asm("_ZN2Tz8CmSLBase11SetLeadDataEv");
void func_0014a238() asm("func_0014a238");
void func_00102448(u32, s32) asm("func_00102448");
void Tz__CmSave__Setup() asm("Tz__CmSave__Setup");
void func_00242618(s32, s32) asm("func_00242618");
void YI__IMAGE_CACHE__Clear() asm("YI__IMAGE_CACHE__Clear");
void func_00236148() asm("func_00236148");
s32 func_00259c60() asm("func_00259c60");
void Tz__CmSave__Draw() asm("Tz__CmSave__Draw");
void func_002b6298(u32) asm("func_002b6298");
void func_00233e70(s32) asm("func_00233e70");
s32 func_00233e60() asm("func_00233e60");
void Tz__CmLoad__Setup() asm("Tz__CmLoad__Setup");
s32 Tz__CmLoad__Control() asm("Tz__CmLoad__Control");
void Tz__CmLoad__Draw() asm("Tz__CmLoad__Draw");
s64 func_00287bc0_l() asm("func_00287bc0");
s32 func_0028b040(u32) asm("func_0028b040");
struct E32 { u32 a, b, flags; u8 pad[20]; };
E32* func_00241f10() asm("func_00241f10");
void func_002598b8(u32) asm("func_002598b8");
void func_0025d7f8(u32) asm("func_0025d7f8");

void func_0025d6a0() asm("func_0025d6a0");
void func_0025d6a0() { D_0035f0b1 = 0; }

}  // namespace n0025d6a0

// 0025d6b0 (was src/anon/auto80_199_queue.cpp)
namespace n0025d6b0 {
/*TARGET 0025d6b0*/
u32 Tz__CmSave__Init(void) asm("_Z16Tz__CmSave__Initv");
u32 Tz__CmSave__Init(void) {
    func_002b4ac8(0, 0);  // store_globals_two_b
    func_002b4ae0(19);  // store_global_word_b
    func_002b4af0((u32)&D_00373148);  // store_global_word
    func_00258ce8((u32)&D_00373128);
    Tz__CmSLBase__Init();

    D_0035f0b3 = 1;
    D_0035f0b4 = 0;

    u32* v0 = (u32*)func_00103eb0();
    return TASK_MANAGER__create_thread(v0[1], 0, 2000, (u32)&func_0025d7f8, 4096);
}
}  // namespace n0025d6b0

// 0025d728 (was src/anon/tiny_jal_tail_wrappers.cpp)
namespace n0025d728 {
u32 func_0014a248() asm("_Z13func_0014a248v");
u32 func_002b47a0() asm("_Z13func_002b47a0v");
/*TARGET 0025d728*/
u32 func_0025d728(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0025d728jjjj");
u32 func_0025d728(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_0014a248();  // zero_global_byte_b
    return func_002b47a0();
}
}  // namespace n0025d728

// 0025d748 (was src/anon/auto80_199_queue.cpp)
namespace n0025d748 {
/*TARGET 0025d748*/
u32 func_0025d748(void) asm("_Z13func_0025d748v");
u32 func_0025d748(void) {
    if (func_00139d78((void*)D_0035f664) != 0) {
        u32 t7 = D_0035f664;
        u32 t6 = *(u32*)t7;
        ((void (*)(u32))(*(u32*)(t6 + 20)))(t7);
    }

    if (func_0028acc8(D_0035f64c) != 0) {
        func_0028abe0(D_0035f64c);
    }

    if (func_0028acc8(D_0035f650) != 0) {
        func_0028abe0(D_0035f650);
    }

    func_002b5658();
    func_002b4f50();
    func_0028f7e8(-1);
    func_0028d620(D_0035f67c);
    func_00263d28();
    func_0028ce38();
    return func_002b6418();
}
}  // namespace n0025d748

// 0025d7f8 (was gap)
namespace n0025d7f8 {
extern u8 D_0035f070 asm("D_0035f070");
extern u8 D_0035f0b0 asm("D_0035f0b0");
extern u8 D_0035f0b1 asm("D_0035f0b1");
extern u8 D_0035f0b2 asm("D_0035f0b2");
extern u32 D_0035eca4 asm("D_0035eca4");
extern u32 D_0035f64c asm("D_0035f64c");
extern u8 D_00372f20[] asm("D_00372f20");
extern u8 D_00372eb8[] asm("D_00372eb8");
void func_002b4ac8(s32, s32) asm("func_002b4ac8");
void func_002b4ae0(s32) asm("func_002b4ae0");
void func_002b4af0(void*) asm("func_002b4af0");
void func_00258ce8(void*) asm("func_00258ce8");
void Tz__CmSLBase__Init() asm("Tz__CmSLBase__Init");
void func_002420d8(u32, s32) asm("func_002420d8");
u8* func_00103eb0() asm("func_00103eb0");
void TASK_MANAGER__create_thread(u32, u32, u32, u32, u32) asm("TASK_MANAGER__create_thread");
void func_0014a248() asm("func_0014a248");
void func_002b47a0() asm("func_002b47a0");
s32 YS__CACHE_BUFF__IsFlushing() asm("YS__CACHE_BUFF__IsFlushing");
void func_00170888(u32) asm("func_00170888");
void func_00253818(s32) asm("func_00253818");
void Tz__CmComm__DataLoad(s32) asm("Tz__CmComm__DataLoad");
void Tz__CmComm__DataLoadWait(s32, u32) asm("Tz__CmComm__DataLoadWait");
void func_002b63a8() asm("_ZN2Tz8CmSLBase11SetLeadDataEv");
void func_0014a238() asm("func_0014a238");
void func_00102448(u32, s32) asm("func_00102448");
void Tz__CmSave__Setup() asm("Tz__CmSave__Setup");
void func_00242618(s32, s32) asm("func_00242618");
void YI__IMAGE_CACHE__Clear() asm("YI__IMAGE_CACHE__Clear");
void func_00236148() asm("func_00236148");
s32 func_00259c60() asm("func_00259c60");
void Tz__CmSave__Draw() asm("Tz__CmSave__Draw");
void func_002b6298(u32) asm("func_002b6298");
void func_00233e70(s32) asm("func_00233e70");
s32 func_00233e60() asm("func_00233e60");
void Tz__CmLoad__Setup() asm("Tz__CmLoad__Setup");
s32 Tz__CmLoad__Control() asm("Tz__CmLoad__Control");
void Tz__CmLoad__Draw() asm("Tz__CmLoad__Draw");
s64 func_00287bc0_l() asm("func_00287bc0");
s32 func_0028b040(u32) asm("func_0028b040");
struct E32 { u32 a, b, flags; u8 pad[20]; };
E32* func_00241f10() asm("func_00241f10");
void func_002598b8(u32) asm("func_002598b8");
void func_0025d7f8(u32) asm("func_0025d7f8");

void func_0025d7f8(u32 key) {
    if (YS__CACHE_BUFF__IsFlushing()) func_00170888(key);
    func_00253818(1);
    Tz__CmComm__DataLoad(1);
    func_002b6298(key);
    func_002b63a8();
    func_0014a238();
    for (;;) {
        func_00236148();
        func_00233e70(0);
        if (func_00233e60()) break;
        func_00102448(key, 0);
    }
    func_00102448(key, 1);
    Tz__CmLoad__Setup();
    func_00242618(11, 1);
    for (;;) {
        YI__IMAGE_CACHE__Clear();
        func_00236148();
        if (Tz__CmLoad__Control()) break;
        Tz__CmLoad__Draw();
        func_00102448(key, 0);
    }
    for (;;) {
        func_00236148();
        func_00233e70(0);
        if (func_00233e60()) break;
        func_00102448(key, 0);
    }
}

}  // namespace n0025d7f8

// 0025d918 (was src/anon/batch_w90.cpp)
namespace n0025d918 {
// 0025d918: create the menu object and set up its layers.
u8* func_0023ee30(u32) asm("func_0023ee30");
void YI__IMAGE_FREEZE__IMAGE_FREEZE(void*) asm("YI__IMAGE_FREEZE__IMAGE_FREEZE");
// obj_ctor_36eac8
void YI__LAYOUT__LAYOUT(void*) asm("YI__LAYOUT__LAYOUT");
// obj_ctor_36eae8
s32 func_0023f948(void*, s32) asm("func_0023f948");
void Tz__MenuUtil__CreateLay(void*, s32, s32, s32, s32, s32, s32, s32, s32) asm("Tz__MenuUtil__CreateLay");
void Tz__Layout__SetImageCache(void*) asm("Tz__Layout__SetImageCache");
void Tz__SelHist__Init(s32, s32, void*, void*, void*) asm("Tz__SelHist__Init");
void Tz__CMenuHelp__Init(s32, s32, void*, void*, void*) asm("Tz__CMenuHelp__Init");
// store_globals_and_init
void func_0023d2e0(u32*) asm("func_0023d2e0");
// store_global_test_result
void func_00240b90(u32) asm("func_00240b90");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
void func_0025dba8(void) asm("func_0025dba8");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8* D_0035f664 asm("D_0035f664");
extern void* D_0035f674 asm("D_0035f674");
extern u8 D_00373100[] asm("D_00373100");
extern u8 D_00373108[] asm("D_00373108");
extern u8 D_00373130[] asm("D_00373130");
extern u8 D_00373138[] asm("D_00373138");
/*TARGET 0025d918*/
void Tz__CmLoad__Setup(void) asm("Tz__CmLoad__Setup");
void Tz__CmLoad__Setup(void)
{
    u8* o = func_0023ee30(160);
    *(u32*)(o + 12) = 0;
    *(void**)o = D_0035eb98;
    YI__IMAGE_FREEZE__IMAGE_FREEZE(o + 24);  // obj_ctor_36eac8
    YI__LAYOUT__LAYOUT(o + 48);  // obj_ctor_36eae8
    D_0035f664 = o;
    s32 v = func_0023f948(D_0035f674, 1);
    Tz__MenuUtil__CreateLay(D_0035f664, 30039, 0, 0, 0, 1, v, 0, 0);
    Tz__Layout__SetImageCache(D_0035f664);
    Tz__SelHist__Init(0, 0, D_0035f664, D_00373108, D_00373130);
    Tz__CMenuHelp__Init(0, 0, D_0035f664, D_00373100, D_00373138);  // store_globals_and_init
    u32 tmp;
    func_0023d2e0(&tmp);  // store_global_test_result
    func_00240b90(tmp);
    func_00287bd0(1, 0);
    func_00287cc0(0);
    func_0025dba8();
}
}  // namespace n0025d918

