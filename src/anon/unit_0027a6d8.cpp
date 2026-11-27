// Linked unit 0x0027a6d8-0x0027ccf8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/cmenu_ability.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/cmenu_tutorial.hpp"
#include "../tozawa/cmenu_selector.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../harata/libdk/obj2d.hpp"
#include "../tozawa/cmenu_config.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/simple_stat.hpp"

// 0027a6d8 (was src/anon/batch_w3705.cpp)
namespace n0027a6d8 {
/* Table entry whose byte at +3 is read as a one-byte struct: the value stays in QImode, so the
 * 0xff test keeps its andi and the s8 conversions keep their sll/sra like the original. */
struct Ent27a6d8Byte { u8 v; };
struct Ent27a6d8 { u8 pad[3]; Ent27a6d8Byte v; u8 pad2[4]; };
struct Tbl27a6d8 { u8 pad[16]; Ent27a6d8 e[1]; };
extern s32 D_0035f01c asm("D_0035f01c");
extern Tbl27a6d8* D_0035f230 asm("D_0035f230");
s32 func_002570a0(s32) asm("func_002570a0");
void func_0027aed8(s32, s32*, s32*) asm("func_0027aed8");
s32 func_0028b040(s32) asm("func_0028b040");
s32 Tz__CmNewFlg__isAbilityNewMember(s32, s32) asm("Tz__CmNewFlg__isAbilityNewMember");
s32 func_0027ae78(s32) asm("func_0027ae78");
s32 Tz__CmNewFlg__isAbilityNewForm(s32, s8) asm("Tz__CmNewFlg__isAbilityNewForm");
void Tz__CmNewFlg__SetAbilityFlgMember(s32, s8) asm("Tz__CmNewFlg__SetAbilityFlgMember");
void func_00287430(s32, s8) asm("func_00287430");
/*TARGET 0027a6d8*/
void Tz__CmAbility__UpdateNew(void) asm("Tz__CmAbility__UpdateNew");
void Tz__CmAbility__UpdateNew(void) {
    s32 mode;
    s32 h;
    func_0027aed8(func_002570a0(15), &mode, &h);
    s32 i = func_0028b040(D_0035f01c);
    Ent27a6d8Byte c = D_0035f230->e[i].v;
    s8 k;
    if (c.v == 0xff) return;
    if (mode == 0) {
        k = c.v & 0x7f;
        if (Tz__CmNewFlg__isAbilityNewMember(h, k)) Tz__CmNewFlg__SetAbilityFlgMember(h, k);
    } else {
        k = c.v & 0x7f;
        if ((s8)c.v & 0x80) {
            if (Tz__CmNewFlg__isAbilityNewForm(func_0027ae78(h), k)) func_00287430(func_0027ae78(h), k);
        } else {
            if (Tz__CmNewFlg__isAbilityNewMember(0, k)) Tz__CmNewFlg__SetAbilityFlgMember(0, k);
        }
    }
}
}  // namespace n0027a6d8

// 0027a7e0 (was src/anon/batch_w66.cpp)
namespace n0027a7e0 {
s32 func_0028acc8(u32) asm("func_0028acc8");
// 0x0026e140: definition moved into src/anon/unit_0026c450.cpp
// ---- 0027a7e0
u8* func_00257770(void) asm("func_00257770");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0028dac8(u8*, s32) asm("func_0028dac8");
void func_0027b4e8(void) asm("func_0027b4e8");
s32 func_0028be58(u32) asm("func_0028be58");
void func_0028bdb8(u32) asm("func_0028bdb8");
s32 func_0028acb8(u32) asm("func_0028acb8");
void func_0028aa40(u32) asm("func_0028aa40");
extern u32 D_0035f04c asm("D_0035f04c");
extern u32 D_0035f01c asm("D_0035f01c");
/*TARGET 0027a7e0*/
void func_0027a7e0(u8 a) asm("func_0027a7e0");
void func_0027a7e0(u8 a) {
    u8* v = func_00257770();
    if (func_00287bc0() != 16) return;
    func_0028dac8(v, 232);
    if (a) func_0027b4e8();
    if (func_0028be58(D_0035f04c)) func_0028bdb8(D_0035f04c);
    if (!func_0028acc8(D_0035f01c)) return;
    if (func_0028acb8(D_0035f01c)) return;
    func_0028aa40(D_0035f01c);
}
}  // namespace n0027a7e0

// 0027a898 (was src/anon/auto80_199_queue.cpp)
namespace n0027a898 {
/*TARGET 0027a898*/
void func_0027a898(u32 a0) asm("_Z13func_0027a898j");
void func_0027a898(u32 a0) {
    u32 s0 = a0 & 0xff;
    func_00257a00();
    if (s0 != 0) {
        func_0027b510();
    }
    if (func_0028be58(D_0035f04c) != 0) {
        func_0028be18(D_0035f04c);
    }
    if (func_0028acc8(D_0035f01c) == 0) {
        return;
    }
    func_0028abe0(D_0035f01c);
}
}  // namespace n0027a898

// 0027a908 (was src/anon/batch_w55.cpp)
namespace n0027a908 {
bool func_002577b0(void) asm("func_002577b0");
bool func_0027b528(void) asm("func_0027b528");
s32 func_0028be58(void*) asm("func_0028be58");
extern void* D_0035f04c asm("D_0035f04c");
extern u8* D_0035f01c asm("D_0035f01c");
s32 Select_isCreated(u8*) asm("_ZN2Tz6Select9isCreatedEz");
/*TARGET 0027a908*/
// 0x002638e0: definition moved into src/anon/unit_002632d0.cpp

bool func_0027a908(u8 a) asm("func_0027a908");
// 0x002638e0: definition moved into src/anon/unit_002632d0.cpp

bool func_0027a908(u8 a) {
    bool r = func_002577b0();
    if (r) return r;
    if (a) r = func_0027b528();
    if (r) return r;
    if (D_0035f04c) r = func_0028be58(D_0035f04c) != 0;
    if (r) return r;
    if (D_0035f01c) r = Select_isCreated(D_0035f01c) != 0;
    return r;
}
}  // namespace n0027a908

// 0027a990 (was src/anon/auto80_199_queue.cpp)
namespace n0027a990 {
/*TARGET 0027a990*/
u32 func_0027a990() asm("_Z13func_0027a990v");
u32 func_0027a990() {
    u32 s0 = func_00257770();
    s32 s1 = 231;

    u32 mode = func_00287bc0();
    if (mode != 16) {
        u32 i = Tz__CmAbility__Cur2AbiltyType();  // check_state16_then_loop
        s1 = D_00373e30[i * 3 + 2];
    }

    if (func_00139d78(s0) == 0) {
        return 0;
    }
    return (u32)(*(u32*)(s0 + 388) == (u32)s1);
}
}  // namespace n0027a990

// 0027aa10 (was src/anon/batch_w3687_g.c)
namespace n0027aa10 {
u8* Tz_CmTop_GetListBuffer(void) asm("_ZN2Tz5CmTop13GetListBufferEv");
s32 u_call4_00139d78(u8*) asm("_Z16u_call4_00139d78jjjj");
s32 Tz_MenuBase_GetMode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
s32 Tz__CmAbility__Cur2AbiltyType(void) asm("Tz__CmAbility__Cur2AbiltyType");
void Tz_Select_SetSequence(u8*, s32) asm("_ZN2Tz6Select11SetSequenceEz");
typedef struct SeqEntry3687 { s16 a, b, seq; } SeqEntry3687;
extern SeqEntry3687 D_00373e30[] asm("D_00373e30");
/*TARGET 0027aa10*/
void func_0027aa10(void) asm("func_0027aa10");
/* Refreshes the menu list buffer and starts its selection sequence (231 in mode 16, else
   from the table entry of the current item). Declaring the check as returning
   s32 (not void) puts the buffer copy into a0 before the copy into s0, as in the original. */
void func_0027aa10(void) {
    u8* p = Tz_CmTop_GetListBuffer();
    s32 n;
    u_call4_00139d78(p);
    if (Tz_MenuBase_GetMode() == 16) n = 231;
    else n = D_00373e30[Tz__CmAbility__Cur2AbiltyType()].seq;
    Tz_Select_SetSequence(p, n);
}
}  // namespace n0027aa10

// 0027aa78 (was src/tozawa/cmenu_ability.cpp)
namespace Tz { // method 0027aa78
u32 getSaveRam() asm("_Z10getSaveRamv");
/*TARGET 0027aa78*/
u32 CmAbility_isWorldLK() asm("_Z13func_0027aa78v");
u32 CmAbility_isWorldLK() {
    u32 r2 = getSaveRam();
    r2 = (u32)(*(u8*)((u32)r2 + 12));
    r2 = (u32)(r2 ^ 0x000au);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
}  // Tz

// 0027aaa0 (was src/anon/batch_w1948_nsa.cpp)
namespace n0027aaa0 {
u8* func_00257770(void) asm("func_00257770");
s32 func_0028b038(s32) asm("func_0028b038");
void Tz__ScrollBar__SetPos(s32, s32) asm("Tz__ScrollBar__SetPos");
s32 func_002570a0(s32) asm("func_002570a0");
s32 func_00257140(s32) asm("func_00257140");
void func_00138c10(void*, s32) asm("func_00138c10");
u8* func_0027bba0(s32) asm("func_0027bba0");
s32 func_00192048(u16) asm("func_00192048");
s32 func_00192cc0(void*, void*, s32) asm("func_00192cc0");
void func_0027aed8(s32, s32*, s32*) asm("func_0027aed8");
s32 Tz__CmAbility__Cur2AbiltyType(void) asm("Tz__CmAbility__Cur2AbiltyType");
s32 func_0027c3b8(s32) asm("func_0027c3b8");
struct S436 { u8 p[408]; s32 v; u8 q[24]; };
struct E27aaa0 { s8 a; s8 b; u8 pad[6]; };
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f04c asm("D_0035f04c");
extern u8* D_0035f230 asm("D_0035f230");
extern u8 D_00373de0 asm("D_00373de0");
extern u16 D_00373e60[] asm("D_00373e60");
/*TARGET 0027aaa0*/
void func_0027aaa0(void) asm("func_0027aaa0");
void func_0027aaa0(void) {
    s32 a, b;
    u8* w = func_00257770();
    u8* o = w + 24304;
    Tz__ScrollBar__SetPos(D_0035f04c, func_0028b038(D_0035f01c));
    s32 k = func_002570a0(16);
    func_00138c10(o, func_00257140(0));
    *(s32*)(o + 408) = func_00192048(*(u16*)(func_0027bba0(k) + 8));
    o = w + 2068;
    *(s32*)(o + 408) = func_00192cc0(w + 0xb170, &D_00373de0, ((E27aaa0*)(D_0035f230 + 16))[k].b);
    func_0027aed8(func_002570a0(15), &a, &b);
    s32 f = Tz__CmAbility__Cur2AbiltyType();
    s32 m = func_002570a0(16);
    s8 t = ((E27aaa0*)(D_0035f230 + 16))[m].a;
    s32 n;
    if (a != 0) goto two;
    n = 2;
    if (b == 0) goto go;
    if (f != 0) goto go;
    if (t != 0) goto go;
    n = 4;
    if (func_0027c3b8(m) == 0) goto go;
two:
    n = 2;
go:
    for (k = 0; k < n; k++) {
        func_00138c10(&((S436*)(w + 24740))[k], func_00257140(0));
        ((S436*)(w + 24740))[k].v = func_00192048(D_00373e60[k != 0]);
    }
}
}  // namespace n0027aaa0

// 0027ac38 (was src/anon/batch_w1583_g.cpp)
namespace n0027ac38 {
s32 func_00257770(void) asm("func_00257770");
s32 func_0028be58(s32) asm("func_0028be58");
void func_0028bdb8(s32) asm("func_0028bdb8");
s32 func_0028acc8(s32) asm("func_0028acc8");
s32 func_0028acb8(s32) asm("func_0028acb8");
void func_0028aa40(s32) asm("func_0028aa40");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 Tz__CmAbility__Cur2AbiltyType(void) asm("Tz__CmAbility__Cur2AbiltyType");
void func_0028dac8(s32, s32) asm("func_0028dac8");
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f04c asm("D_0035f04c");
struct E6 { s16 a; s16 b; s16 c; };
extern E6 D_00373e30[] asm("D_00373e30");
/*TARGET 0027ac38*/
void Tz__CmAbility__FadeOutAbilityList(void) asm("Tz__CmAbility__FadeOutAbilityList");
void Tz__CmAbility__FadeOutAbilityList(void) {
    s32 p = func_00257770();
    if ((u32)(func_00287bc0() - 0x11) >= 3) return;
    func_0028dac8(p, D_00373e30[Tz__CmAbility__Cur2AbiltyType()].b);
    if (func_0028be58(D_0035f04c)) func_0028bdb8(D_0035f04c);
    if (!func_0028acc8(D_0035f01c)) return;
    if (func_0028acb8(D_0035f01c)) return;
    func_0028aa40(D_0035f01c);
}
}  // namespace n0027ac38

// 0027acf8 (was src/anon/batch_w1583_g.cpp)
namespace n0027acf8 {
s32 func_00257770(void) asm("func_00257770");
s32 func_00139d78(s32) asm("func_00139d78");
void func_00257a00(void) asm("func_00257a00");
void func_00139510(s32) asm("func_00139510");
s32 func_0028be58(s32) asm("func_0028be58");
void func_0028be18(s32) asm("func_0028be18");
s32 func_0028acc8(s32) asm("func_0028acc8");
void func_0028abe0(s32) asm("func_0028abe0");
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f04c asm("D_0035f04c");
/*TARGET 0027acf8*/
void func_0027acf8(void) asm("func_0027acf8");
void func_0027acf8(void) {
    s32 p = func_00257770();
    func_00257a00();
    p += 0x814;
    if (func_00139d78(p)) func_00139510(p);
    if (func_0028be58(D_0035f04c)) func_0028be18(D_0035f04c);
    if (func_0028acc8(D_0035f01c)) func_0028abe0(D_0035f01c);
}
}  // namespace n0027acf8

// 0027ad80 (was src/anon/batch_w66.cpp)
namespace n0027ad80 {
// 0x0010b568: definition moved into src/anon/unit_0010b450.cpp
// ---- 0013793c
s32 func_00139d78(u8*) asm("func_00139d78");
s32 func_0028acc8(u32) asm("func_0028acc8");
// 0x0026e140: definition moved into src/anon/unit_0026c450.cpp
// ---- 0027a7e0
u8* func_00257770(void) asm("func_00257770");
s32 func_0028be58(u32) asm("func_0028be58");
extern u32 D_0035f04c asm("D_0035f04c");
extern u32 D_0035f01c asm("D_0035f01c");
// ---- 0027ad80
s32 func_002577b0(void) asm("func_002577b0");
/*TARGET 0027ad80*/
s32 func_0027ad80(void) asm("func_0027ad80");
s32 func_0027ad80(void) {
    u8* v = func_00257770();
    s32 r = func_002577b0();
    if (r) return r;
    r = func_00139d78(v + 2504) != 0;
    if (r) return r;
    if (D_0035f04c) {
        if (func_0028be58(D_0035f04c)) r = 1;
    }
    if (r) return r;
    if (D_0035f01c) r = func_0028acc8(D_0035f01c) != 0;
    return r;
}
}  // namespace n0027ad80

// 0027ae20 (was src/anon/batch_w34.cpp)
namespace n0027ae20 {
extern s16* D_0035f230 asm("D_0035f230");
/*TARGET 0027ae20*/
// Counts set bits 0-5 and 7 of the flag word.
s32 func_0027ae20(void) asm("func_0027ae20");
// Counts set bits 0-5 and 7 of the flag word.
s32 func_0027ae20(void) {
    s32 n = 0;
    for (s32 i = 0; i < 7; i++) {
        if (i != 6) {
            if (!((*D_0035f230 >> i) & 1)) continue;
            n++;
        }
    }
    if (*(u16*)D_0035f230 & 0x80) n++;
    return n;
}
}  // namespace n0027ae20

// 0027ae78 (was src/anon/batch_w49.cpp)
namespace n0027ae78 {
extern s16* D_0035f230 asm("D_0035f230");
/*TARGET 0027ae78*/
s32 func_0027ae78(s32 n) asm("func_0027ae78");
s32 func_0027ae78(s32 n) {
    s32 k = 0;
    s32 i;
    for (i = 0; i < 8; i++) {
        if (i == 6) continue;
        if (!((*D_0035f230 >> i) & 1)) continue;
        if (n == k) break;
        k++;
    }
    return i;
}
}  // namespace n0027ae78

// 0027aed8 (was src/anon/batch_w58.cpp)
namespace n0027aed8 {
// 0x0026e5b8: definition moved into src/anon/unit_0026c450.cpp

s32 func_0027ae20(void) asm("func_0027ae20");
/*TARGET 0027aed8*/
void func_0027aed8(s32 a, s32* o1, s32* o2) asm("func_0027aed8");
void func_0027aed8(s32 a, s32* o1, s32* o2) {
    if (a == 0) {
        *o1 = 0;
        *o2 = 0;
        return;
    }
    s32 n = func_0027ae20();
    if (n != 0 && a < n + 1) {
        *o1 = 1;
        *o2 = a - 1;
    } else {
        *o1 = 0;
        *o2 = a - n;
    }
}
}  // namespace n0027aed8

// 0027af58 (was src/anon/batch_w56.cpp)
namespace n0027af58 {
extern u32 D_0035f01c asm("D_0035f01c");
// 0x002656c0: definition moved into src/anon/unit_00265580.cpp

// 0027af58: pick the bucket a value falls into from a table of 4 weights
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028b040(u32) asm("func_0028b040");
s32 func_002570a0(s32) asm("func_002570a0");
extern s8* D_0035f230 asm("D_0035f230");
/*TARGET 0027af58*/
s32 Tz__CmAbility__Cur2AbiltyType(void) asm("Tz__CmAbility__Cur2AbiltyType");
s32 Tz__CmAbility__Cur2AbiltyType(void)
{
    s32 v = func_00287bc0();
    if (v == 16) v = func_0028b040(D_0035f01c);
    else v = func_002570a0(16);
    s32 sum = 0, r = -1;
    for (s32 i = 0; i < 4; i++) {
        sum += D_0035f230[i + 8];
        if (v < sum) { r = i; break; }
    }
    return r;
}
}  // namespace n0027af58

// 0027afe0 (was src/anon/batch_w256.cpp)
namespace n0027afe0 {
struct E27 { s8 a; u8 x; s8 b; u8 y; s8 c; u8 z[3]; };
struct T27 { u8 hdr[14]; E27 e[1]; };
struct I27 { u8 p[5]; u8 b5; u8 q[2]; };
extern T27* D_0035f230 asm("D_0035f230");
extern u32 D_0035f01c asm("D_0035f01c");
u32 getselpos_w256(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
s32 getitemtbl_w256(s32) asm("_ZN2Tz9CmAbility10GetItemTblEi");
void func_0027aed8(u32, s32*, s32*) asm("func_0027aed8");
s32 Tz__CmAbility__Cur2AbiltyType(void) asm("Tz__CmAbility__Cur2AbiltyType");
// check_state16_then_loop
I27* func_00273180(s32, s32) asm("func_00273180");
// state_dispatch_2_3
void Tz__Select__SetCurrent(u32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_0027b248(s32) asm("func_0027b248");
/*TARGET 0027afe0*/
void Tz__CmAbility__SetIndiAbilityDefaultPos(void) asm("Tz__CmAbility__SetIndiAbilityDefaultPos");
void Tz__CmAbility__SetIndiAbilityDefaultPos(void) {
  s32 a, b;
  s32 r = 0;
  func_0027aed8(getselpos_w256(15), &a, &b);
  s32 k = getselpos_w256(16);
  s32 v = Tz__CmAbility__Cur2AbiltyType();  // check_state16_then_loop
  s8 f = D_0035f230->e[k].b;
  if (!D_0035f230->e[k].a) goto out;
  if (a) goto one;
  if (!b) goto one;
  if (v) goto one;
  if (f) goto one;
  if (getitemtbl_w256(k)) goto one;
  {
    I27* p = func_00273180(4, -1);  // state_dispatch_2_3
    s32 i;
    for (i = 0; i < 3; i++) if (p[i].b5 == D_0035f230->e[k].c) break;
    r = i + 1;
  }
  goto out;
one:
  r = 1;
out:
  Tz__Select__SetCurrent(D_0035f01c, r, 0, -1, -1);
  func_0027b248(r != 0);
}
}  // namespace n0027afe0

// 0027b0f8 (was src/anon/batch_w1881_g.cpp)
namespace n0027b0f8 {
struct H1881 { u16 a; s16 h2; s16 h4; u8 pad[646]; u8 body[1]; };
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035f03c asm("D_0035f03c");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef64 asm("D_0035ef64");
extern H1881* D_0035f230 asm("D_0035f230");
extern u8 D_00373de8[] asm("D_00373de8");
u8* func_00257770(void) asm("func_00257770");
s32 func_00139d78(u8*) asm("func_00139d78");
void func_0028d980(u8*, s32, u32, u32, u32, s32, s32, s32, s32) asm("func_0028d980");
s32 func_00192cc0(u8*, u8*, s32, s32) asm("func_00192cc0");
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_0027b248(s32) asm("func_0027b248");
/*TARGET 0027b0f8*/
void func_0027b0f8(void) asm("func_0027b0f8");
void func_0027b0f8(void) {
    u8* base = func_00257770();
    u8* w = base + 0xb350;
    if (!func_00139d78(w)) {
        s32 id = D_0035f3d4;
        func_0028d980(w, id, D_0035ef68, D_0035ef64, D_0035f03c, 272, 273, -1, 0);
        H1881* h = D_0035f230;
        s32 a2 = h->h4; s32 a3 = h->h2; *(s32*)(w + 408) = func_00192cc0(h->body, D_00373de8, a2, a3);
        *(s32*)(w + 432) = 1;
        u8* w2 = base + 0xb504;
        func_0028d8c0(w2, id + 1, D_0035ef68, D_0035ef64, D_0035f03c, 269, -1, 100);
        func_0028dcc0(w2, w);
        u8* w3 = base + 0xb6b8;
        func_0028d8c0(w3, id + 2, D_0035ef68, D_0035ef64, D_0035f03c, 270, -1, 0);
        func_0028dcc0(w3, w);
    }
    func_0027b248(1);
}
}  // namespace n0027b0f8

// 0027b248 (was src/anon/batch_w2408.cpp)
namespace n0027b248 {
struct W2408Ent { u8 pad[0xe]; s8 b0e; u8 pad2[2]; s8 b11; };
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_00139570(u8*) asm("func_00139570");
void func_00139580(u8*) asm("func_00139580");
void func_00139d78(u8*) asm("func_00139d78");
s32 func_00192cc0(u8*, u32*, ...) asm("func_00192cc0");
void YI__SEQUENCE__SetScaleX(f32, u8*) asm("YI__SEQUENCE__SetScaleX");
void func_0023aa58(u8*) asm("func_0023aa58");
s32 func_002570a0(s32) asm("func_002570a0");
u8* func_00257770(void) asm("func_00257770");
void func_0027aed8(s32, s32*, s32*) asm("func_0027aed8");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028b040(s32) asm("func_0028b040");
s32 func_002fd178(s32) asm("func_002fd178");
extern s32 D_0035f01c asm("D_0035f01c");
extern u8* D_0035f230 asm("D_0035f230");
extern u32 D_00373de8 asm("D_00373de8");
extern s32 D_00373df4 asm("D_00373df4");
extern s32 D_00373df8 asm("D_00373df8");
/*TARGET 0027b248*/
void func_0027b248(s32 arg0) asm("func_0027b248");
void func_0027b248(s32 arg0) {
    s32 la, lb;
    u8 flag = arg0;
    u8* w = func_00257770();
    u8* o = w + 0xb350;
    func_00139d78(o);
    if (((s8*)D_0035f230)[7] == 0) {
        func_00139570(w + 0xb504);
        func_00139570(w + 0xb6b8);
        return;
    }
    s32 cur = *(s16*)(D_0035f230 + 4);
    s32 max = *(s16*)(D_0035f230 + 2);
    f32 fmax = max;
    *(s32*)(o + 0x198) = func_00192cc0(D_0035f230 + 652, &D_00373de8, cur, max);
    f32 r1 = (f32)cur / fmax;
    if (1.0f < r1) r1 = 1.0f;
    func_0027aed8(func_002570a0(15), &la, &lb);
    s32 m = func_00287bc0();
    s32 idx;
    if (m == 16) idx = func_0028b040(D_0035f01c);
    else idx = func_002570a0(16);
    W2408Ent* e = (W2408Ent*)((u32)(idx * 8) + (u32)D_0035f230);
    s32 delta = e->b11;
    if (m == 16) {
        if (e->b0e && la != 1) delta = -delta;
    } else if (e->b0e ? flag != 0 : flag == 0) {
        delta = 0;
    } else {
        delta = ((W2408Ent*)(D_0035f230 + idx * 8))->b0e ? -delta : delta;
    }
    if (max < cur + delta) delta = max - cur;
    f32 r2 = (f32)func_002fd178(cur + delta) / fmax;
    if (1.0f < r2) r2 = 1.0f;
    if (delta == 0 || la == 1) func_00139570(w + 0xb504);
    else func_00139580(w + 0xb504);
    u8* q = w + 0xb504;
    func_0023aa58(q + 24);
    func_00138c10(q, (r1 <= r2) ? D_00373df4 : D_00373df8);
    f32 f = r1;
    u8* p1 = w + 0xb51c;
    if (!(r2 <= r1)) f = r2;
    YI__SEQUENCE__SetScaleX(f, p1);
    f32 g = r1;
    u8* p2 = w + 0xb6d0;
    if (!(r1 < r2)) g = r2;
    YI__SEQUENCE__SetScaleX(g, p2);
}
}  // namespace n0027b248

// 0027b4e8 (was src/anon/batch_w8.cpp)
namespace n0027b4e8 {
// 0x00269378: definition moved into src/anon/unit_00268b30.cpp

u8* func_00257770(void) asm("func_00257770");
void func_0028dac8(u8*, u32) asm("func_0028dac8");
/*TARGET 0027b4e8*/
void func_0027b4e8(void) asm("func_0027b4e8");
void func_0027b4e8(void) {
    func_0028dac8(func_00257770() + 0xb350, 274);
}
}  // namespace n0027b4e8

// 0027b510 (was src/anon/tiny.cpp)
namespace n0027b510 {
void Tz__CmTop__LeaveListSubWin(void*) asm("_Z26Tz__CmTop__LeaveListSubWinPv");
/*TARGET 0027b510*/
void func_0027b510(BD_VALUE* bd) asm("_Z13func_0027b510P8BD_VALUE");
void func_0027b510(BD_VALUE* bd) { Tz__CmTop__LeaveListSubWin(bd); }
}  // namespace n0027b510

// 0027b528 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0027b528 {
u32 func_00257910(u32, u32, u32, u32) asm("_Z13func_00257910jjjj");
/*TARGET 0027b528*/
u32 func_0027b528(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0027b528jjjj");
u32 func_0027b528(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_00257910)(u32, u32, u32, u32) = func_00257910;
    r2 = fp_call4_00257910(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0027b528

// 0027b548 (was src/anon/auto80_199_queue.cpp)
namespace n0027b548 {
/*TARGET 0027b548*/
void func_0027b548(u32 a0) asm("_Z13func_0027b548j");
void func_0027b548(u32 a0) {
    u32 s0 = a0 & 0xff;
    s32 idx = Tz::CmTop::GetSelectPos(15);

    if (s0 != 0) {
        idx += 1;
        if (!(idx < (s8)*(s8*)(D_0035f230 + 6))) {
            idx = 0;
        }
    } else {
        idx -= 1;
        if (idx < 0) {
            idx = (s8)*(s8*)(D_0035f230 + 6) - 1;
        }
    }

    func_00257050(15, idx, 0);
    func_0028fb68(1, func_0027b5d0());
}
}  // namespace n0027b548

// 0027b5d0 (was src/anon/batch_w91.cpp)
namespace n0027b5d0 {
u32 cmtop_select_pos(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
// --- 0027b5d0
extern u32 D_0035f010 asm("D_0035f010");
u16* func_0026b850(void) asm("func_0026b850");
void func_0027aed8(u32, s32*, s32*) asm("func_0027aed8");
u32 func_00281140(u32, s32) asm("func_00281140");
u32 func_00192048(u32) asm("func_00192048");
extern s16* D_0035f230 asm("D_0035f230");
/*TARGET 0027b5d0*/
u32 func_0027b5d0(void) asm("func_0027b5d0");
u32 func_0027b5d0(void) {
    u32 r = 0;
    u16* v = func_0026b850();
    s32 oa, ob;
    func_0027aed8(cmtop_select_pos(15), &oa, &ob);
    if (oa == 0) {
        r = func_00281140(D_0035f010, ob);
    } else {
        s32 n = 0;
        for (s32 i = 0; i < 16; i++) {
            if (i == 6) continue;
            if ((u8)(((*D_0035f230 >> i) ^ 1) & 1)) continue;
            if (ob == n) { r = func_00192048(i == 7 ? 0xb2ec : v[i]); break; }
            n++;
        }
    }
    return r;
}
}  // namespace n0027b5d0

// 0027b6b8 (was src/anon/perm_0027b6b8_g.cpp)
namespace n0027b6b8 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed int s32;
s32 func_00257770(void) asm("_ZN2Tz5CmTop13GetListBufferEv");
s32 func_00287bc0(void) asm("_ZN2Tz8MenuBase7GetModeEv");
void func_002fde18(s32, s32, s32) asm("_Z16wtarget_002fde18jjjj");
s32 func_0028b040(s32) asm("_ZN2Tz8JmReport7GetDataEj");
s32 func_002570a0(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
void func_0027aed8(s32, s32 *, s32 *) asm("func_0027aed8");
void func_00263a58(s32, s32) asm("_ZN2Tz9CMenuHelp6CreateEib");
short Tz__CMenuHelp__Create_2(s32, s32) asm("Tz__CMenuHelp__Create_2");
u8 *func_0027bba0(s32) asm("_Z16ctarget_0027bba0jjjj");
s32 func_00192048(s32) asm("_Z16u_tail4_00192048jjjj");
s32 func_00192b30(s32) asm("_ZNK2YS7MESSAGE8get_sizeEv");
void func_00192c90(s32, s32) asm("_ZNK2YS7MESSAGE3dupEPc");
s32 Tz__CmAbility__Cur2AbiltyType(void) asm("Tz__CmAbility__Cur2AbiltyType");
s32 func_0027c3b8(s32) asm("_ZN2Tz9CmAbility10GetItemTblEi");
u8 *func_00273180(s32, s32) asm("func_00273180");
void func_002595e8(s32, s32) asm("_ZN2Tz6CmComm11CopyMessageEPcPKN2YS7MESSAGEE");
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_00373e04[2] asm("D_00373e04");
extern u16 D_00373e68[2] asm("D_00373e68");
struct Ent
{
  u16 id;
  s8 on;
  u8 p0;
  s8 col;
  u8 p1;
  s8 kind;
  u8 p2;
};
struct Tbl
{
  u8 pad[7];
  s8 n;
  u8 pad2[4];
  Ent e[1];
};
extern Tbl *D_0035f230 asm("D_0035f230");
/*TARGET 0027b6b8*/
void func_0027b6b8(void) asm("func_0027b6b8");
void func_0027b6b8(void)
{
  s32 b = func_00257770();
  s32 mode = func_00287bc0();
  s32 buf = b + 0xB1D0;
  s32 r0;
  s32 r1;
  s32 s2;
  s32 s5;
  s32 s1;
  s32 s0;
  func_002fde18(buf, 0, 0xC0);
  if (mode == 15)
  {
    func_0027aed8(func_0028b040(D_0035f01c), &r0, &r1);
    if (r0 == 0)
    {
      s0 = D_00373e04[0];
    }
    else
    {
      s0 = D_00373e04[1];
    }
    func_00263a58(s0, 1);
    return;
  }
  if (mode == 16)
  {
    if (D_0035f230->n == 0)
    {
      func_00263a58(-1, 1);
      return;
    }
    s2 = func_0028b040(D_0035f01c);
    s0 = *((u16 *) (func_0027bba0(s2) + 0xA));
    s5 = func_00192b30(func_00192048(s0));
    s32 h = func_00192048(s0);
    func_00192c90(h, buf);
    Tz__CMenuHelp__Create_2(buf, 1);
  }
  else
  {
    s2 = func_0028b040(D_0035f01c);
    s0 = D_00373e68[(s2 == 0) ? (0) : (1)];
    s5 = func_00192b30(func_00192048(s0));
    func_00192c90(func_00192048(s0), buf);
    Tz__CMenuHelp__Create_2(buf, 1);
    if (s2 == 0)
    {
      return;
    }
  }
  func_0027aed8(func_002570a0(15), &r0, &r1);
  s0 = Tz__CmAbility__Cur2AbiltyType();
  if (mode == 16)
  {
    s1 = s2;
  }
  else
  {
    s1 = func_002570a0(16);
  }
  if (r0 != 0)
  {
    return;
  }
  if (r1 == 0)
  {
    return;
  }
  if (s0 != 0)
  {
    return;
  }
  if (func_0027c3b8(s1))
  {
    return;
  }
  u8 *t = func_00273180(4, -1);
  s32 j;
  if (mode == 16)
  {
    Tbl *tb = D_0035f230;
    if (tb->e[s1].kind < 0)
    {
      return;
    }
    if (!tb->e[s1].on)
    {
      return;
    }
    for (j = 0; j < 3; j++)
    {
      if (t[(j * 8) + 5] == tb->e[s2].kind)
      {
        break;
      }
    }

  }
  else
  {
    j = s2 - 1;
  }
  s0 = *((u16 *) ((t + (j * 8)) + 2));
  func_002595e8((b + s5) + 0xB1D0, func_00192048(s0));
}
}  // namespace n0027b6b8

// 0027b960 (was unwritten gap)
namespace n0027b960 {
s32 GetMode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
u8* GetListBuffer(void) asm("_ZN2Tz5CmTop13GetListBufferEv");
s32 Tz__Select__GetPtr2Idx(s32, u8*) asm("Tz__Select__GetPtr2Idx");
s32 GetSelectTop(s32) asm("_ZN2Tz6Select12GetSelectTopEv");
s32 GetSelectPos(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
s32 Tz__CmAbility__Cur2AbiltyType(void) asm("Tz__CmAbility__Cur2AbiltyType");
void func_0027aed8(s32, s32*, s32*) asm("func_0027aed8");
u32 GetItemTbl(s32) asm("_ZN2Tz9CmAbility10GetItemTblEi");
u8* func_00273180(s32, s32) asm("func_00273180");
u8* func_00192048(u16) asm("_Z16u_tail4_00192048jjjj");
void YS__MESSAGEDRAW__MESSAGEDRAW(u8*, s32, u8*, u32, s32) asm("YS__MESSAGEDRAW__MESSAGEDRAW");
void YS__MESSAGEDRAW__draw(u8*, s32, s32, s32) asm("_Z21YS__MESSAGEDRAW__drawjjjj");
void dk__Sprite__getPosAddOffset(u8*, s32*, s32*) asm("dk__Sprite__getPosAddOffset");
void getSeqActiveXY(u8*, s32*, s32*) asm("_ZN2dk6Sprite14getSeqActiveXYERiS1_");
s32 GetParamX(u8*) asm("_ZN2YI8SEQUENCE9GetParamXEv");
s32 GetParamY(u8*) asm("_ZN2YI8SEQUENCE9GetParamYEv");
extern s32 D_0035f01c asm("D_0035f01c");
struct Ent { u16 id; s8 on; u8 p0; s8 col; u8 p1; s8 kind; u8 p2; };
struct Tbl { u8 pad[12]; Ent e[1]; };
extern Tbl* D_0035f230 asm("D_0035f230");
void func_0027b960(u32 a0, u32 a1, s32 a2, u32 a3, u8* o) asm("func_0027b960");
void func_0027b960(u32 a0, u32 a1, s32 a2, u32 a3, u8* o)
{
    u8 buf[96];
    s32 x, y, w, h;
    s32 r0, r1;
    s32 v;
    s32 mode = GetMode();
    u8* b = GetListBuffer();
    if (mode == 16 || mode == 17) {
        if (mode == 16) {
            s32 k = Tz__Select__GetPtr2Idx(D_0035f01c, o);
            v = k + GetSelectTop(D_0035f01c);
            s8* e = v * 8 + (s8*)D_0035f230;
            if (D_0035f230->e[v].kind < 0) return;
            if (D_0035f230->e[v].on == 0) return;
            u8* seq = o + 24;
            YS__MESSAGEDRAW__MESSAGEDRAW(buf, 1, b + k * 4 + 0xb110, *(u32*)(o + 424), 1);
            dk__Sprite__getPosAddOffset(o, &x, &y);
            getSeqActiveXY(o, &w, &h);
            w += GetParamX(seq) + x;
            h += GetParamY(seq) + y;
            YS__MESSAGEDRAW__draw(buf, w, h, a2);
        } else {
            v = Tz__Select__GetPtr2Idx(D_0035f01c, o);
            if (v == 0) return;
            s32 p15 = GetSelectPos(15);
            s32 z = Tz__CmAbility__Cur2AbiltyType();
            func_0027aed8(p15, &r0, &r1);
            s32 p16 = GetSelectPos(16);
            s8 col = ((u8*)D_0035f230 + p16 * 8)[16];
            if (r0 != 0) return;
            if (r1 == 0) return;
            if (z != 0) return;
            if (col != 0) return;
            if (GetItemTbl(p16)) return;
            u8* t = func_00273180(4, -1);
            u8* seq = o + 24;
            u32 m = *(u32*)(o + 424);
            YS__MESSAGEDRAW__MESSAGEDRAW(buf, 1, func_00192048(*(u16*)(t + v * 8 - 8)), m, 1);
            dk__Sprite__getPosAddOffset(o, &x, &y);
            getSeqActiveXY(o, &w, &h);
            w += GetParamX(seq) + x;
            h += GetParamY(seq) + y;
            YS__MESSAGEDRAW__draw(buf, w, h, a2);
        }
    }
}
}  // namespace n0027b960

// 0027bba0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0027bba0 {
extern u32 D_0035f230 asm("D_0035f230");
u32 func_001a80c8(...) asm("func_001a80c8");
/*TARGET 0027bba0*/
u32 func_0027bba0(u32 a0) asm("_Z13func_0027bba0j");
u32 func_0027bba0(u32 a0) {
    u32 p = (a0 << 3) + *(u32*)(u32)&D_0035f230;
    u32 v = *(u16*)(p + 12u);
    if (v != 0u) {
        return func_001a80c8(v);  // table24_find_by_id
    }
    return 0u;
}
}  // namespace n0027bba0

// 0027bbe0 (was src/anon/batch_w8011.cpp)
namespace n0027bbe0 {
struct E27bb { u8 a; s8 f1; u8 q[6]; };
void func_00279ec8(void) asm("func_00279ec8");
void func_0027b6b8(void) asm("func_0027b6b8");
s32 func_002570a0(s32) asm("func_002570a0");
void func_0027aed8(s32, s32*, s32*) asm("func_0027aed8");
void Tz__CmAbility__UpdateNew(void) asm("Tz__CmAbility__UpdateNew");
void func_0027a208(void) asm("func_0027a208");
void func_0027b248(s32) asm("func_0027b248");
u32 func_0028af88(s32) asm("func_0028af88");
s32 func_0028b040(s32) asm("func_0028b040");
extern E27bb* D_0035f230 asm("D_0035f230");
s32 func_00283ab8(s32) asm("func_00283ab8");
s32 func_00258068(s32) asm("func_00258068");
void Tz__CmTop__CreatePadHelp(s32, s32, s32) asm("Tz__CmTop__CreatePadHelp");
void func_0028af18(s32, u32) asm("func_0028af18");
void func_0027aaa0(void) asm("func_0027aaa0");
/*TARGET 0027bbe0*/
void func_0027bbe0(s32 a0, s32 a1) asm("func_0027bbe0");
void func_0027bbe0(s32 a0, s32 a1) {
    if (a1 == 15) {
        func_00279ec8();
    } else if (a1 == 16) {
        s32 st0, st1;
        u32 f;
        s32 id;
        func_0027aed8(func_002570a0(15), &st0, &st1);
        Tz__CmAbility__UpdateNew();
        func_0027a208();
        if (st0 == 0) func_0027b248(1);
        f = func_0028af88(a0);
        if (st0 == 0) {
            E27bb* e;
            a1 = func_0028b040(a0);
            e = (E27bb*)((u32)(a1 << 3) + (u32)D_0035f230) + 2;
            if (!e->f1) f &= ~0x200;
            else f |= 0x200;
        }
        id = -1;
        if (func_00283ab8(2)) {
            f |= 0x400;
            id = 0xcbdd;
        } else {
            f &= ~0x400;
        }
        if (func_00258068(0)) {
            Tz__CmTop__CreatePadHelp(0xb373, 0xb61a, id);
        } else if (id >= 0) {
            Tz__CmTop__CreatePadHelp(0xb61a, id, -1);
        }
        func_0028af18(a0, f);
    } else {
        func_0027aaa0();
        func_0027b248(func_0028b040(a0) != 0);
    }
    func_0027b6b8();
}
}  // namespace n0027bbe0

// 0027bd40 (was src/anon/batch_w295.cpp)
namespace n0027bd40 {
s32 chk_139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void lv_139510(void*) asm("_ZN2dk5Obj2D5leaveEv");
extern s32 D_0035f3d4 asm("D_0035f3d4");
struct T373 { u8 pad[8]; s16 t[1]; };
extern T373 D_00373e50 asm("D_00373e50");
extern u32 D_0035ef64 asm("D_0035ef64"); extern u32 D_0035ef68 asm("D_0035ef68"); extern u32 D_0035f03c asm("D_0035f03c"); extern u32 D_0035f01c asm("D_0035f01c");
extern s8* D_0035f230 asm("D_0035f230");
u8* cm_glb(void) asm("_ZN2Tz5CmTop13GetListBufferEv");
s32 mb_gm(void) asm("_ZN2Tz8MenuBase7GetModeEv");
s32 cm_gsp(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
void func_0027aed8(s32, s32*, s32*) asm("func_0027aed8");
s32 func_0028d008(void*) asm("func_0028d008");
s32 Tz__CmAbility__Cur2AbiltyType(void) asm("Tz__CmAbility__Cur2AbiltyType");
// check_state16_then_loop
void pz_cfo(void*, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz5Pause16CreateFadeObjectEz");
void mc_as(void*, void*) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
u8* mc_gs(void*) asm("_ZN2Tz10MenuCursor9GetSpriteEi");
void sp_gop(u32, s32*, s32*) asm("_ZN2dk6Sprite12getOffsetPosERiS1_");
void sp_sop(void*, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
s32 jm_gd(u32) asm("_ZN2Tz8JmReport7GetDataEj");
void cm_csci(void*) asm("_ZN2Tz5CmTop18CreateShortCutInfoEPN2dk6SpriteE");
void cm_lsci(void) asm("_ZN2Tz5CmTop17LeaveShortCutInfoEv");
/*TARGET 0027bd40*/
void Tz__CmAbility__UpdateTopSelActive(void* p, u8 flag) asm("Tz__CmAbility__UpdateTopSelActive");
void Tz__CmAbility__UpdateTopSelActive(void* p, u8 flag) {
  s32 v[4];
  u8* w = cm_glb();
  s32 m = mb_gm();
  u8* o = w + 816;
  { s32* q = &v[1]; func_0027aed8(cm_gsp(15), q - 1, q); }
  s32 act = chk_139d78(o);
  if (func_0028d008(p)) {
  if (!act) {
    s32 c = 249;
    s32 s = D_0035f3d4 + 2;
    if (m != 16) c = D_00373e50.t[Tz__CmAbility__Cur2AbiltyType()];
    pz_cfo(o, s, D_0035ef68, D_0035ef64, D_0035f03c, c, -1, 0);
    mc_as(o, w);
    sp_gop(*(u32*)(mc_gs(p) + 396), &v[2], &v[3]);
    sp_sop(o, v[2], v[3]);
  }
  if (flag) {
    sp_gop(*(u32*)(mc_gs(p) + 396), &v[2], &v[3]);
    sp_sop(o, v[2], v[3]);
  }
  if (chk_139d78(w + 2504) && !flag) return;
  s32 r = jm_gd(D_0035f01c);
  if (m == 16 && v[0] == 0 && D_0035f230[r * 8 + 17]) { cm_csci(mc_gs(p)); return; }
  } else {
    if (act) lv_139510(o);
  }
  cm_lsci();
}
}  // namespace n0027bd40

// 0027bf20 (was src/anon/batch_w24.cpp)
namespace n0027bf20 {
// 0x0026dcb8: definition moved into src/anon/unit_0026c450.cpp

struct Ent8 { u8 _0[2]; s8 flag; u8 _3[2]; s8 lim; u8 _6[2]; };
struct Hdr8 { s16 _0; s16 a; s16 b; u8 _6[6]; Ent8 e[1]; };
extern Hdr8* D_0035f230 asm("D_0035f230");
/*TARGET 0027bf20*/
s32 func_0027bf20(s32 i) asm("func_0027bf20");
s32 func_0027bf20(s32 i) {
    Hdr8* h = D_0035f230;
    s32 d = h->a - h->b;
    if (d < 0) d = 0;
    if (h->e[i].flag) return 1;
    return !(d < h->e[i].lim);
}
}  // namespace n0027bf20

// 0027bf68 (was src/anon/batch_w287.cpp)
namespace n0027bf68 {
struct E27 { u8 pad[5]; u8 key; u8 pad2[2]; };
extern u8* D_0035f230 asm("D_0035f230");
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f010 asm("D_0035f010");
s32 func_002570a0(s32) asm("func_002570a0");
void func_0027aed8(s32, s32*, s32*) asm("func_0027aed8");
s32 Tz__CmAbility__Cur2AbiltyType(void) asm("Tz__CmAbility__Cur2AbiltyType");
// check_state16_then_loop
s32 func_0028b040(s32) asm("func_0028b040");
s32 func_0027c3b8(s32) asm("func_0027c3b8");
E27* func_00273180(s32, s32) asm("func_00273180");
// state_dispatch_2_3
u8* func_001145b0(u16) asm("func_001145b0");
u8* func_00281180(s32, s32) asm("func_00281180");
void Tz__CmAbility__SetEquip(s32, s32) asm("Tz__CmAbility__SetEquip");
#define REC(i) (D_0035f230 + (i) * 8)
/*TARGET 0027bf68*/
void Tz__CmAbility__ChgEquip(void) asm("Tz__CmAbility__ChgEquip");
void Tz__CmAbility__ChgEquip(void) {
    s32 a, b;
    func_0027aed8(func_002570a0(15), &a, &b);
    s32 busy = Tz__CmAbility__Cur2AbiltyType();  // check_state16_then_loop
    s32 idx = func_0028b040(D_0035f01c);
    s8 f16 = *(s8*)(REC(idx) + 16);
    s32 ok;
    E27* v;
    s32 i;
    u8* sp_;
    u8* w;
    if (a != 0 || b == 0 || busy != 0 || f16 != 0 || func_0027c3b8(idx)) goto early;
    v = func_00273180(4, -1);  // state_dispatch_2_3
    if (*(s8*)(REC(idx) + 14) != 0) {
        for (i = 0; i < 3; i++) {
            if (v[i].key == *(s8*)(REC(idx) + 18)) break;
        }
    } else {
        i = -1;
    }
    if (i + 1 < 3) {
        REC(idx)[18] = v[i + 1].key;
        sp_ = func_001145b0(*(u16*)(REC(idx) + 12));
        w = func_00281180(D_0035f010, b);
        (sp_ + *(s32*)(w + 580))[245] = REC(idx)[18];
        ok = 1;
    } else {
        REC(idx)[18] = -1;
        ok = 0;
    }
    Tz__CmAbility__SetEquip(idx, ok);
    return;
early:
    ok = *(s8*)(REC(idx) + 14) == 0;
    Tz__CmAbility__SetEquip(idx, ok);
}
}  // namespace n0027bf68

// 0027c118 (was src/anon/batch_w66.cpp)
namespace n0027c118 {
// ---- 0027c118
u32 func_002570a0(s32) asm("func_002570a0");
void func_0027aed8(u32, s32*, s32*) asm("func_0027aed8");
u8* func_00281180(u32, s32) asm("func_00281180");
extern u32 D_0035f010 asm("D_0035f010");
extern u8* D_0035f230 asm("D_0035f230");
struct H27c { u16 v : 15; u16 flag : 1; };
struct W27c { u8 pad[4]; H27c h; };
struct E27d { u8 pad[14]; u8 b14; s8 b15; };
/*TARGET 0027c118*/
void Tz__CmAbility__SetEquip(s32 i, u8 f) asm("Tz__CmAbility__SetEquip");
void Tz__CmAbility__SetEquip(s32 i, u8 f) {
    s32 a, b;
    func_0027aed8(func_002570a0(15), &a, &b);
    u8* v = func_00281180(D_0035f010, a ? 0 : b);
    u8* t = *(u8**)(v + 580);
    ((E27d*)((u8*)D_0035f230 + i * 8))->b14 = f;
    ((W27c*)(t + ((E27d*)((u8*)D_0035f230 + i * 8))->b15 * 2 + 80))->h.flag = f != 0;
}
}  // namespace n0027c118

// 0027c1c0 (was src/anon/batch_w95.cpp)
namespace n0027c1c0 {
struct ColEnt { u8 pad[5]; u8 col; u8 pad6[2]; };
struct ColSlot2 { u16 id; u16 pad2; s8 lock; u8 pad5[3]; };
struct ColTab2 { u8 pad[12]; ColSlot2 s[1]; };
extern u32 D_0035f010 asm("D_0035f010");
extern u32 D_0035f01c asm("D_0035f01c");
extern ColTab2* D_0035f230 asm("D_0035f230");
u32 func_002570a0(u32) asm("func_002570a0");
s32 func_0028b040(u32) asm("func_0028b040");
void Tz__CmAbility__SetEquip(u32, u32) asm("Tz__CmAbility__SetEquip");
s32 Tz__CmAbility__Cur2AbiltyType(void) asm("Tz__CmAbility__Cur2AbiltyType");
// check_state16_then_loop
void func_0027aed8(u32, s32*, s32*) asm("func_0027aed8");
s32 func_0027c3b8(u32) asm("func_0027c3b8");
ColEnt* func_00273180(u32, s32) asm("func_00273180");
// state_dispatch_2_3
u8* func_001145b0(u32) asm("func_001145b0");
u8* func_00281180(u32, u32) asm("func_00281180");
/*TARGET 0027c1c0*/
void Tz__CmAbility__ChgEquipAbility(void) asm("Tz__CmAbility__ChgEquipAbility");
void Tz__CmAbility__ChgEquipAbility(void) {
    u32 x = func_002570a0(16);
    s32 b = func_0028b040(D_0035f01c);
    Tz__CmAbility__SetEquip(x, b != 0);
    u32 y = func_002570a0(15);
    u32 z = Tz__CmAbility__Cur2AbiltyType();  // check_state16_then_loop
    s32 o1, o0;
    func_0027aed8(y, &o0, &o1);
    s8 lock = D_0035f230->s[x].lock;
    if (o0 != 0) return;
    if (o1 == 0) return;
    if (z != 0) return;
    if (lock != 0) return;
    if (func_0027c3b8(x)) return;
    z = (u32)func_00273180(4, -1);  // state_dispatch_2_3
    y = (u32)func_001145b0(D_0035f230->s[x].id);
    x = func_0028b040(D_0035f01c);
    if (!x) return;
    u32 off = *(u32*)(func_00281180(D_0035f010, o1) + 580);
    ((u8*)y)[off + 245] = ((ColEnt*)z)[x - 1].col;
    func_002570a0(16);
}
}  // namespace n0027c1c0

// 0027c2f8 (was src/anon/batch_w79.cpp)
namespace n0027c2f8 {
s32 func_00257070(s32) asm("func_00257070");
s32 func_00257088(s32) asm("func_00257088");
s32 func_0028afa8(u32) asm("func_0028afa8");
s32 func_002892f8(u32) asm("func_002892f8");
void Tz__Select__SetCurrent(u32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_0028afd0(u32, s32) asm("func_0028afd0");
// obj_set_signed18
extern u32 D_0035f01c asm("D_0035f01c");
/*TARGET 0027c2f8*/
void func_0027c2f8(void) asm("func_0027c2f8");
void func_0027c2f8(void) {
    s32 sel = func_00257070(16);
    s32 top = func_00257088(16);
    s32 cnt = func_0028afa8(D_0035f01c);
    s32 vis = func_002892f8(D_0035f01c);
    if (cnt < top + vis) top = vis < cnt ? cnt - vis : 0;
    if (!(vis < cnt) && !(sel < cnt)) {
        sel = cnt - 1;
        top = 0;
    }
    Tz__Select__SetCurrent(D_0035f01c, sel, 0, -1, -1);
    func_0028afd0(D_0035f01c, top);  // obj_set_signed18
}
}  // namespace n0027c2f8

// 0027c3b8 (was src/tozawa/cmenu_ability.cpp)
namespace Tz { // method 0027c3b8
u32 func_0027bba0(u32) asm("func_0027bba0");
/*TARGET 0027c3b8*/
u32 CmAbility_GetItemTbl(s32 index) asm("_Z13func_0027c3b8i");
u32 CmAbility_GetItemTbl(s32 index) {
    u32 r2 = func_0027bba0((u32)index);
    r2 = (u32)(*(u8*)((u32)r2 + (s32)(6)));
    r2 = (u32)(r2 ^ 0x0001u);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
}  // Tz

// 0027c3e0 (was src/anon/batch_w81.cpp)
namespace n0027c3e0 {
s32 func_00287bc0(void) asm("func_00287bc0");
extern u32 D_0035f01c asm("D_0035f01c");
// 0x0026c048: definition moved into src/anon/unit_0026a900.cpp

// --- 0027c3e0
extern u8* D_0035f230 asm("D_0035f230");
u32 func_0028b040(u32) asm("func_0028b040");
u32 func_002570a0(u32) asm("func_002570a0");
void func_0027aed8(u32, s32*, s32*) asm("func_0027aed8");
s32 func_0027bf20(u32) asm("func_0027bf20");
/*TARGET 0027c3e0*/
s32 Tz__CmAbility__SelCheck(s32 id) asm("Tz__CmAbility__SelCheck");
s32 Tz__CmAbility__SelCheck(s32 id) {
    s32 m = func_00287bc0();
    u32 h = func_0028b040(D_0035f01c);
    if (m == 15) return 1;
    if (m != 16) return 1;
    s32 b;
    s32 a;
    func_0027aed8(func_002570a0(15), &a, &b);
    if (id == -7) return 1;
    if (id == -6) return func_0027bf20(h);
    if ((u32)(id + 11) < 2) {
        s32 r = 0;
        if (*(s8*)(D_0035f230 + 6) >= 2) r = 1;
        return r;
    }
    if (id == -5) return 1;
    if (*(s8*)(D_0035f230 + id * 8 + 17) != 0 && a == 0) return func_0027bf20(h);
    return 0;
}
}  // namespace n0027c3e0

// 0027c4d8 (was src/anon/batch_w1587.cpp)
namespace n0027c4d8 {
extern u32 D_0035f234 asm("D_0035f234");
u32 func_00103570(void) asm("func_00103570");
u8* func_001063f0(u32, u32) asm("func_001063f0");
/*TARGET 0027c4d8*/
// 0x0025ee58: definition moved into src/anon/unit_0025da20.cpp

void Tz__CmConfig__Init(void) asm("Tz__CmConfig__Init");
// 0x0025ee58: definition moved into src/anon/unit_0025da20.cpp

void Tz__CmConfig__Init(void) { D_0035f234 = (u32)func_001063f0(10, func_00103570()); }
}  // namespace n0027c4d8

// 0027c508 (was src/anon/tiny_auto80_queue.cpp)
namespace n0027c508 {
u32 func_00106450(...) asm("func_00106450");
/*TARGET 0027c508*/
void func_0027c508(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0027c508jjjjjjjj");
void func_0027c508(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // release_global_slots
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = (u32)(0x0036u << 16);
    r15 = *(u32*)((u32)r16 + (s32)(-3532));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00106450)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(u32*)((u32)r16 + (s32)(-3532)) = 0u;
    }
}
}  // namespace n0027c508

// 0027c540 (was src/anon/tiny_auto80_queue.cpp)
namespace n0027c540 {
u32 func_0027d2e8(...) asm("func_0027d2e8");
u32 func_00287bc0(...) asm("func_00287bc0");
/*TARGET 0027c540*/
u32 func_0027c540(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0027c540jjjjjjjj");
u32 func_0027c540(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_00287bc0)();
    if (r2 != 36u) return r2;
    return ((u32(*)())func_0027d2e8)();
}
}  // namespace n0027c540

// 0027c570 (was src/tozawa/cmenu_tutorial.cpp)
namespace Tz { // method 0027c570
u32 func_0027d350(...) asm("func_0027d350");
u32 func_00287bc0(...) asm("func_00287bc0");
/*TARGET 0027c570*/
u32 CmTutorial_LeaveAll() asm("_Z13func_0027c570v");
u32 CmTutorial_LeaveAll() {
    u32 r2 = func_00287bc0();
    if (r2 != 36u) {
        return r2;
    }
    return func_0027d350();
}
}  // Tz

// 0027c5a0 (was src/anon/batch_w92.cpp)
namespace n0027c5a0 {
u32 func_00257770(void) asm("func_00257770");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void func_0027c9a8(void) asm("func_0027c9a8");
void func_0027ccf8(void) asm("func_0027ccf8");
s32 func_00257070(s32) asm("func_00257070");
s32 func_00257088(s32) asm("func_00257088");
void Tz__Select__SetCurrent(u32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_0028afd0(u32, s32) asm("func_0028afd0");
// obj_set_signed18
void Tz__Select__SetSelectMax(u32, s32) asm("Tz__Select__SetSelectMax");
// obj_set_field22_from_arg
void Tz__Select__SetPageMode(u32, s32) asm("Tz__Select__SetPageMode");
// obj_set_flag39_bits3000
void func_0028b248(u32, s32) asm("func_0028b248");
// set_field28_half
u8* func_0023f1b0(u32) asm("func_0023f1b0");
u32 func_0023c4b8(u8*, u32) asm("func_0023c4b8");
u32 func_00236ca8(u32, u32) asm("func_00236ca8");
u32 func_002570f0(void) asm("func_002570f0");
void func_0028bae0(u32, u32, u32, u32, u32, s32, s32, u32, s32) asm("func_0028bae0");
void func_0028af28(u32, s32) asm("func_0028af28");
u32 func_0028b040(u32) asm("func_0028b040");
void func_0027d810(u32) asm("func_0027d810");
void func_0027d008(void) asm("func_0027d008");
void func_00287cc0(s32) asm("func_00287cc0");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f03c asm("D_0035f03c");
extern u32 D_0035f04c asm("D_0035f04c");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035f3d4 asm("D_0035f3d4");
/*TARGET 0027c5a0*/
void Tz__CmConfig__Setup(void) asm("Tz__CmConfig__Setup");
void Tz__CmConfig__Setup(void) {
    u32 a = func_00257770();
    func_0028f4d8(0, -1, 0);
    func_0027c9a8();
    func_0027ccf8();
    Tz__Select__SetCurrent(D_0035f01c, func_00257070(36), 0, -1, -1);
    func_0028afd0(D_0035f01c, func_00257088(36));  // obj_set_signed18
    Tz__Select__SetSelectMax(D_0035f01c, 10);  // obj_set_field22_from_arg
    Tz__Select__SetPageMode(D_0035f01c, 1);  // obj_set_flag39_bits3000
    func_0028b248(D_0035f01c, 9);  // set_field28_half
    u32 b = func_0023c4b8(func_0023f1b0(D_0035f03c), D_0035ef68);
    u32 c = func_00236ca8(*(u32*)(func_0023f1b0(D_0035f03c) + 40), D_0035ef64);
    u32 d = D_0035f3d4;
    func_0028bae0(D_0035f04c, d, b, c, func_002570f0(), 10, 9, a, 0);
    func_0028af28(D_0035f01c, 16);
    func_0027d810(func_0028b040(D_0035f01c));
    func_0027d008();
    func_00287cc0(0);
}
}  // namespace n0027c5a0

// .rodata tables of this file (0x373df4-0x373e70), read by other functions as extern D_.
extern const u32 R_00373df4[1] asm("D_00373df4") __attribute__((aligned(4))) = { 0x10d };
extern const u32 R_00373df8[1] asm("D_00373df8") __attribute__((aligned(4))) = { 0x10f };
extern const u32 R_00373dfc[1] asm("D_00373dfc") __attribute__((aligned(4))) = { 0x32 };
extern const u32 R_00373e00[1] asm("D_00373e00") __attribute__((aligned(4))) = { 0x31 };
extern const u32 R_00373e04[9] asm("D_00373e04") __attribute__((aligned(4))) = { 0xbb8b, 0xbb8c, 0x0, 0x8b0089, 0x96008f, 0xfc00f8, 0x1090106, 0x1160114, 0x11b0118 };
extern const u32 R_00373e28[2] asm("D_00373e28") __attribute__((aligned(4))) = { 0xb2efb2ee, 0xb2edb2f0 };
extern const u32 R_00373e30[8] asm("D_00373e30") __attribute__((aligned(4))) = { 0x9b0099, 0xab009a, 0xac00ad, 0xb600b4, 0xcf00b5, 0xd000d1, 0xb300a1, 0xd800bc };
extern const u32 R_00373e50[4] asm("D_00373e50") __attribute__((aligned(4))) = { 0xaf009d, 0xd300b8, 0xae009c, 0xd200b7 };
extern const u32 R_00373e60[2] asm("D_00373e60") __attribute__((aligned(4))) = { 0xb627b629, 0x0 };
extern const u32 R_00373e68[2] asm("D_00373e68") __attribute__((aligned(4))) = { 0xb628b62a, 0x0 };

// 0027c700 (was src/anon/batch_wcx2.cpp)
namespace n0027c700 {
// --------------------
extern s32 D_0035f01c_27c asm("D_0035f01c");
s32 func_00289380_x9988(s32) asm("func_00289380");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00287c10() asm("func_00287c10");
s32 func_0027d3b0() asm("func_0027d3b0");
s32 func_0028f930(s32) asm("func_0028f930");
s32 func_00289310_x9993(s32) asm("func_00289310");
void func_00287f90(s32) asm("func_00287f90");
void func_0027d350() asm("func_0027d350");
void func_00287c30() asm("func_00287c30");
void func_0028af18_x9997(s32, s32) asm("func_0028af18");
void func_0028f7e8(s32) asm("func_0028f7e8");
void func_002551b8() asm("func_002551b8");
s32 func_0027d408() asm("func_0027d408");
void func_0027d450() asm("func_0027d450");
void func_0028ab20_x10002(s32) asm("func_0028ab20");
void func_0028fa98(s32) asm("func_0028fa98");
void func_00287c90(s32) asm("func_00287c90");
void func_0027d540() asm("func_0027d540");
void func_0027d5d8() asm("func_0027d5d8");
void func_0028afa8_x10007(s32) asm("func_0028afa8");
void func_0027d9e8() asm("func_0027d9e8");
s32 func_00287df0_27c(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_0027d868(s32) asm("func_0027d868");
void func_0027d008() asm("func_0027d008");
void Tz__CmConfig__SetConfig() asm("Tz__CmConfig__SetConfig");
void func_0013a460() asm("func_0013a460");
void func_00287da0() asm("func_00287da0");
s32 func_002891e8_x10016(s32) asm("func_002891e8");
s32 func_0028b038_x10017(s32) asm("func_0028b038");
void func_00257050_x10018(s32, s32, s32) asm("func_00257050");
void Tz__CMenuHelp__FadeOut() asm("Tz__CMenuHelp__FadeOut");
void func_00256e80() asm("func_00256e80");
void Tz__SelHist__FadeOut(s32) asm("Tz__SelHist__FadeOut");
void func_0027d2e8() asm("func_0027d2e8");
void func_00287c00(s32) asm("func_00287c00");
s32 func_00288040() asm("func_00288040");
void func_00288018() asm("func_00288018");
/*TARGET 0027c700*/
void Tz__CmConfig__Ctrl() asm("Tz__CmConfig__Ctrl");
void Tz__CmConfig__Ctrl() {
    s32 r = func_00289380_x9988(D_0035f01c_27c);
    s32 a = func_00287cd0();
    if (a == 2) {
        s32 st = func_00287c10();
        if (!func_0027d3b0() && !func_0028f930(0)) goto idle;
        if (r != -1 || func_00289310_x9993(D_0035f01c_27c)) {
            func_00287f90(0);
            func_0027d350();
        }
        return;
    idle:
        func_00287c30();
        func_0028af18_x9997(D_0035f01c_27c, 115);
        if (st) return;
        func_0028f7e8(0);
        func_002551b8();
        return;
    }
    if (r != -1 || func_00289310_x9993(D_0035f01c_27c)) {
        if (!func_0027d408()) {
            func_0027d450();
            func_0028ab20_x10002(D_0035f01c_27c);
            func_0028fa98(-1);
        }
    }
    if (!a && func_0027d408()) {
        func_00287c90(1);
        func_0027d540();
        func_0027d5d8();
    }
    func_0028afa8_x10007(D_0035f01c_27c);
    if (!func_00242848(func_00287df0_27c(r, func_00289310_x9993(D_0035f01c_27c), 1, func_0027d9e8, 1))) {
        switch (r) {
        case -4: {
            Tz__CmConfig__SetConfig();
            func_0013a460();
            func_00287da0();
            s32 n = func_002891e8_x10016(D_0035f01c_27c);
            func_00257050_x10018(36, n, func_0028b038_x10017(D_0035f01c_27c));
            break;
        }
        case -11: case -10: case -9: case -8: case -7: case -6: case -5: case -3: case -1:
            break;
        case -13: case -12:
            func_0027d868(r == -12);
            func_0027d008();
            func_0027d540();
            break;
        case -2: {
            Tz__CmConfig__SetConfig();
            func_0013a460();
            Tz__CMenuHelp__FadeOut();
            func_00256e80();
            Tz__SelHist__FadeOut(0);
            func_0027d2e8();
            func_00287c90(1);
            func_00287c00(0);
            s32 n = func_002891e8_x10016(D_0035f01c_27c);
            func_00257050_x10018(36, n, func_0028b038_x10017(D_0035f01c_27c));
            break;
        }
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0027c700

// 0027c9a8 (was src/anon/batch_wcx2.cpp)
namespace n0027c9a8 {
// --------------------
extern s8* D_0035f234 asm("D_0035f234");
s32 func_00242b58() asm("func_00242b58");
s32 func_00242bd0() asm("func_00242bd0");
s32 func_00242d58() asm("func_00242d58");
s32 func_00242ce8() asm("func_00242ce8");
s32 func_00242dc8() asm("func_00242dc8");
s32 func_00242ae8() asm("func_00242ae8");
s32 func_00242a00() asm("func_00242a00");
s32 func_00242a68() asm("func_00242a68");
s32 func_00242c70() asm("func_00242c70");
s32 func_001058e8_x9950() asm("func_001058e8");
s8 func_00105868(s32) asm("func_00105868");
/*TARGET 0027c9a8*/
void func_0027c9a8() asm("func_0027c9a8");
void func_0027c9a8() {
    s32 i;
    for (i = 0; i < 10; i++) {
        switch (i) {
        case 0: D_0035f234[i] = func_00242b58() == 0; break;
        case 1: D_0035f234[i] = func_00242bd0() == 0; break;
        case 2: D_0035f234[i] = func_00242d58() != 0; break;
        case 3: D_0035f234[i] = func_00242ce8() != 0; break;
        case 4: {
            s32 v = func_00242dc8();
            if (v == 0) D_0035f234[i] = 2;
            else if (v == 2) D_0035f234[i] = 0;
            else D_0035f234[i] = 1;
            break;
        }
        case 5: D_0035f234[i] = func_00242ae8() == 0; break;
        case 6: D_0035f234[i] = func_00242a00() == 0; break;
        case 7: {
            s32 v = func_00242a68();
            if (v == 0) D_0035f234[i] = 2;
            else if (v == 2) D_0035f234[i] = 1;
            else D_0035f234[i] = 0;
            break;
        }
        case 8: D_0035f234[i] = func_00242c70() == 0; break;
        case 9: {
            s8* p = &D_0035f234[i];
            *p = func_00105868(func_001058e8_x9950());
            break;
        }
        }
    }
}
}  // namespace n0027c9a8

// 0027cb48 (was src/anon/batch_wcx2.cpp)
namespace n0027cb48 {
// --------------------
extern s8* D_0035f234 asm("D_0035f234");
void func_00242b88(s32) asm("func_00242b88");
void func_00242c00(s32) asm("func_00242c00");
void func_00242d80(s32) asm("func_00242d80");
void func_00242d10(s32) asm("func_00242d10");
void Tz__Config__SetSummonEffect(s32) asm("Tz__Config__SetSummonEffect");
void func_00242b10(s32) asm("func_00242b10");
void func_00242a28(s32) asm("func_00242a28");
void func_00242a90(s32) asm("func_00242a90");
void func_00242ca0(s32) asm("func_00242ca0");
/*TARGET 0027cb48*/
void Tz__CmConfig__SetConfig() asm("Tz__CmConfig__SetConfig");
void Tz__CmConfig__SetConfig() {
    s32 i;
    for (i = 0; i < 10; i++) {
        switch (i) {
        case 0: func_00242b88(D_0035f234[i] == 0); break;
        case 1: func_00242c00(D_0035f234[i] == 0); break;
        case 2: func_00242d80(D_0035f234[i] == 1); break;
        case 3: func_00242d10(D_0035f234[i] == 1); break;
        case 4: {
            s8 t = D_0035f234[i];
            s32 v;
            if (t == 2) v = 0;
            else if (t == 0) v = 2;
            else v = 1;
            Tz__Config__SetSummonEffect(v);
            break;
        }
        case 5: func_00242b10(D_0035f234[i] == 0); break;
        case 6: func_00242a28(D_0035f234[i] == 0); break;
        case 7: {
            s8 t = D_0035f234[i];
            s32 v;
            if (t == 2) v = 0;
            else if (t == 1) v = 2;
            else v = 1;
            func_00242a90(v);
            break;
        }
        case 8: func_00242ca0(D_0035f234[i] == 0); break;
        case 9: break;
        }
    }
}
}  // namespace n0027cb48

