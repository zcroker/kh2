// Linked unit 0x0026a900-0x0026c140 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../tozawa/cmenu_equip.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/cmenu_party.hpp"
#include "../tozawa/cmenu_selector.hpp"
#include "../tozawa/cmenu_slbase.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tz/ui_accessors.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/cmenu_custom.hpp"

// 0026a900 (was src/anon/batch_w2444_g.cpp)
namespace n0026a900 {
u8* func_00257770(void) asm("func_00257770");
u8* func_00281f20(u32) asm("func_00281f20");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028b040(u32) asm("func_0028b040");
s32 func_00285d58(u16) asm("func_00285d58");
void func_00285f50(u16) asm("func_00285f50");
s32 func_00285e30(u16) asm("func_00285e30");
s32 func_002891e8(u32) asm("func_002891e8");
void func_00138c10(u8*, s32) asm("func_00138c10");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f0ec asm("D_0035f0ec");
extern s32 D_00373730 asm("D_00373730");
extern s32 D_00373734 asm("D_00373734");
/*TARGET 0026a900*/
void func_0026a900(void) asm("func_0026a900");
void func_0026a900(void) {
    u16* e;
    s32 v;
    u8* p = func_00257770();
    u8* tbl = func_00281f20(D_0035f0ec);
    s32 w = func_00287bc0();
    s32 idx = func_0028b040(D_0035f01c);
    s32 flag = (u32)(w - 5) < 2;
    if (!flag) {
        if (idx == 0) return;
        idx--;
    }
    e = (u16*)(idx * 6 + (u32)tbl);
    if (func_00285d58(*e)) {
        func_00285f50(*e);
        if (func_00285e30(*e)) v = D_00373734;
        else v = D_00373730;
        func_00138c10(p + func_002891e8(D_0035f01c) * 0x198 + 0x87d0, v);
    }
}
}  // namespace n0026a900

// 0026a9f8 (was src/anon/batch_w89.cpp)
namespace n0026a9f8 {
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f0ec asm("D_0035f0ec");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 Tz__Select__GetPtr2Idx(u32, u8*) asm("Tz__Select__GetPtr2Idx");
// find_index_in_array
s32 func_0028b038(u32) asm("func_0028b038");
u8* func_00281f30(u32) asm("func_00281f30");
void YS__MESSAGEDRAW__MESSAGEDRAW(u8*, u32, u8*, u32, u32) asm("YS__MESSAGEDRAW__MESSAGEDRAW");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
u32 func_0023a918(u8*) asm("func_0023a918");
void YS__MESSAGEDRAW__draw(u8*, s32, s32, u32) asm("YS__MESSAGEDRAW__draw");
/*TARGET 0026a9f8*/
void func_0026a9f8(s32 x, s32 y, u32 a2, u32 a3, u8* o) asm("func_0026a9f8");
void func_0026a9f8(s32 x, s32 y, u32 a2, u32 a3, u8* o) {
    u8 buf[96];
    s32 m = func_00287bc0();
    s32 n = Tz__Select__GetPtr2Idx(D_0035f01c, o);  // find_index_in_array
    bool b = (u32)(m - 5) < 2;
    s32 k = func_0028b038(D_0035f01c);
    u8* base = func_00281f30(D_0035f0ec);
    if (!b && !k) {
        if (n == 0) return;
        n--;
    }
    YS__MESSAGEDRAW__MESSAGEDRAW(buf, 1, base + n * 80, *(u32*)(o + 424), 1);
    s32 px = func_0023aa18(o + 24) + x;
    s32 py = func_0023aa38(o + 24) + y;
    YS__MESSAGEDRAW__draw(buf, px, py, func_0023a918(o + 24));
}
}  // namespace n0026a9f8

// 0026aaf8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0026aaf8 {
u32 func_001a3168(u32, u32, u32, u32) asm("_Z13func_001a3168jjjj");
/*TARGET 0026aaf8*/
// 0x00266c70: definition moved into src/anon/unit_00265580.cpp

u32 func_0026aaf8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0026aaf8jjjj");
// 0x00266c70: definition moved into src/anon/unit_00265580.cpp

u32 func_0026aaf8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r5 = (u32)((s32)0u + (100));
    r6 = (u32)((s32)0u + (1));
    u32 (*fp_call4_001a3168)(u32, u32, u32, u32) = func_001a3168;
    r2 = fp_call4_001a3168(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0026aaf8

// 0026ab18 (was src/anon/batch_w1602.cpp)
namespace n0026ab18 {
s32 func_002570a0(s32) asm("func_002570a0");
extern u32 D_0035f010 asm("D_0035f010");
u32 func_00269508(s32) asm("func_00269508");
u32 func_00257130(void) asm("func_00257130");
s32 func_002827e0(u32, s32) asm("func_002827e0");
u8* func_00281f20(u32) asm("func_00281f20");
u32 func_0026acb8(u32) asm("func_0026acb8");
s32 Tz__CmEquip__CurPos2FormType(s32) asm("Tz__CmEquip__CurPos2FormType");
u32 func_0026ad68(s32, u32) asm("func_0026ad68");
u32 func_0026ae20(s32, u32) asm("func_0026ae20");
u32 func_0026aea8(s32, u32) asm("func_0026aea8");
u32 func_0026af30(s32, u32) asm("func_0026af30");
s32 func_00257070(s32) asm("func_00257070");
void func_00281058(u32, s32) asm("func_00281058");
/*TARGET 0026ab18*/
void func_0026ab18(u32 a0) asm("func_0026ab18");
void func_0026ab18(u32 a0) {
    s32 n[5];
    u32 r = 0;
    s32 s;
    s32 c = func_002570a0(2);
    u32 m = func_00269508(c);
    for (s32 i = 0; i < 5; i++) { s32 v = func_002827e0(func_00257130(), i); n[i] = v; }
    if (*(u16*)(func_00281f20(func_00257130()) + c * 6) == a0) return;
    switch (m) {
    case 0: r = func_0026acb8(a0); break;
    case 1: r = func_0026ad68(Tz__CmEquip__CurPos2FormType(c), a0); break;
    case 2: s = n[0] + n[1]; r = func_0026ae20(c - s, a0); break;
    case 3: s = n[0] + n[1]; s += n[2]; r = func_0026aea8(c - s, a0); break;
    case 4: s = n[0] + n[1]; s += n[2] + n[3]; r = func_0026af30(c - s, a0); break;
    }
    if (r) func_00281058(D_0035f010, func_00257070(1));
}
}  // namespace n0026ab18

// 0026acb8 (was src/anon/auto80_199_queue.cpp)
namespace n0026acb8 {
// 0x00263570: definition moved into src/anon/unit_002632d0.cpp

u32 func_002811b0(u32, s32) asm("_ZN2Tz9PartyInfo10GetPartNumEi");
/*TARGET 0026acb8*/
// 0x00267690: definition moved into src/anon/unit_00265580.cpp

u32 func_0026acb8(u32 a0) asm("_Z13func_0026acb8j");
// 0x00267690: definition moved into src/anon/unit_00265580.cpp

u32 func_0026acb8(u32 a0) {
    u32 s1 = a0;
    u32 s2 = func_00257070(1);
    u32 v0 = func_00281180(D_0035f010, s2);
    u16* s0 = *(u16**)(v0 + 580);

    u32 cur = s0[0];
    u32 r = 0;
    if (cur == s1) {
        return r;
    }

    u32 z = 0;
    u32 hundred = 100;
    YS__ITEM__Get(cur, hundred, z);
    s0[0] = (u16)s1;
    func_001a3458(s1, hundred);

    u32 h = func_002811b0(D_0035f010, s2);
    func_002933d8(h, 0, s1, 0);
    return 1;
}
}  // namespace n0026acb8

// 0026ad68 (was src/anon/auto80_199_queue.cpp)
namespace n0026ad68 {
// 0x00263570: definition moved into src/anon/unit_002632d0.cpp

u32 func_002811b0(u32, s32) asm("_ZN2Tz9PartyInfo10GetPartNumEi");
u32 func_002815b8(void) asm("_ZN2Tz9PartyInfo10GetNowFormEv");
/*TARGET 0026ad68*/
u32 func_0026ad68(u32 a0, u32 a1) asm("_Z13func_0026ad68jj");
u32 func_0026ad68(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = func_00257070(1);

    u32 cur = func_002814b0(s0);
    u32 r = 0;
    if (cur == s1) {
        return r;
    }

    YS__ITEM__Get(cur, 100, 0);
    func_002814f0(s0, s1);
    func_001a3458(s1, 100);

    if (func_002815b8() == s0) {
        u32 h = func_002811b0(D_0035f010, s2);
        func_002933d8(h, 1, s1, 0);
    }

    return 1;
}
}  // namespace n0026ad68

// 0026ae20 (was src/anon/auto80_199_queue.cpp)
namespace n0026ae20 {
/*TARGET 0026ae20*/
u32 func_0026ae20(u32 a0, u32 a1) asm("_Z13func_0026ae20jj");
u32 func_0026ae20(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 t = func_00257070(1);

    u32 ptr = func_00281180(D_0035f010, t);
    u32 base = *(u32*)(ptr + 580);

    s0 = s0 << 1;
    s0 = s0 + base;

    u32 cur = *(u16*)(s0 + 20);
    if (cur == s1) {
        return 0;
    }

    if (cur != 0) {
        YS__ITEM__Get(cur, 100, 0);
    }

    *(u16*)(s0 + 20) = (u16)s1;
    if (s1 != 0) {
        func_001a3458(s1, 100);
    }

    return 1;
}
}  // namespace n0026ae20

// 0026aea8 (was src/anon/auto80_199_queue.cpp)
namespace n0026aea8 {
/*TARGET 0026aea8*/
u32 func_0026aea8(u32 a0, u32 a1) asm("_Z13func_0026aea8jj");
u32 func_0026aea8(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 t = func_00257070(1);

    u32 ptr = func_00281180(D_0035f010, t);
    u32 base = *(u32*)(ptr + 580);

    s0 = s0 << 1;
    s0 = s0 + base;

    u32 cur = *(u16*)(s0 + 36);
    if (cur == s1) {
        return 0;
    }

    if (cur != 0) {
        YS__ITEM__Get(cur, 100, 0);
    }

    *(u16*)(s0 + 36) = (u16)s1;
    if (s1 != 0) {
        func_001a3458(s1, 100);
    }

    return 1;
}
}  // namespace n0026aea8

// 0026af30 (was src/anon/batch_w83.cpp)
namespace n0026af30 {
extern void* D_0035f01c asm("D_0035f01c");
// 0x00262ff8: definition moved into src/anon/unit_0025f6b8.cpp

extern void* D_0035f010 asm("D_0035f010");
extern void* D_0035f0ec asm("D_0035f0ec");
void* func_00257070(s32) asm("func_00257070");
u8* func_00281180(void*, void*) asm("func_00281180");
void YS__ITEM__Get(u32, s32, s32) asm("YS__ITEM__Get");
u8* func_00281f20(void*) asm("func_00281f20");
u32 func_0028b040(void*) asm("func_0028b040");
void func_001a3458(u32, s32) asm("func_001a3458");
struct Six { u8 b0, b1, b2, b3, b4, b5; };
/*TARGET 0026af30*/
s32 func_0026af30(s32 idx, u32 id) asm("func_0026af30");
s32 func_0026af30(s32 idx, u32 id) {
    u8* b = func_00281180(D_0035f010, func_00257070(1));
    u16* e = (u16*)(idx * 2 + *(u32*)(b + 580));
    if (e[26]) YS__ITEM__Get(e[26], 100, 0);
    Six* t = (Six*)func_00281f20(D_0035f0ec);
    u32 n = func_0028b040(D_0035f01c) - 1;
    if (id == 0 || t[n].b2 != 0) {
        e[26] = id;
        e[34] = 0;
        if (id) func_001a3458(id, 100);
    } else {
        e[34] = id;
        e[26] = 0;
    }
    return 1;
}
}  // namespace n0026af30

// 0026b008 (was src/anon/batch_wcx2.cpp)
namespace n0026b008 {
void Tz__CmEquip__CheckAutoReplenishment(void) asm("Tz__CmEquip__CheckAutoReplenishment");
// 0x0019e758: definition moved into src/anon/unit_0019ba60.cpp

// --------------------
struct Q26b008 { u8 pad[18]; u8 n; u8 pad2[33]; u16 h52[8]; u16 h68[8]; };
struct P26b008 { u8 pad[580]; Q26b008* q; };
extern u32 D_0035f010_26b008 asm("D_0035f010");
s32 func_00257070_26b008(s32) asm("func_00257070");
P26b008* func_00281180_26b008(u32, s32) asm("func_00281180");
/*TARGET 0026b008*/
void Tz__CmEquip__CheckAutoReplenishment() asm("Tz__CmEquip__CheckAutoReplenishment");
void Tz__CmEquip__CheckAutoReplenishment()
{
    u32 list[8];
    Q26b008* q = func_00281180_26b008(D_0035f010_26b008, func_00257070_26b008(1))->q;
    u8 n = q->n;
    s32 i;
    for (i = 0; i < n; i++) list[i] = 0;
    s32 cnt = 0;
    for (i = 0; i < n; i++) {
        u16 h = q->h68[i];
        if (h) list[cnt++] = h;
    }
    for (i = 0; i < n; i++) {
        for (s32 j = 0; j < cnt; j++) {
            if (q->h52[i] == list[j]) {
                q->h68[i] = list[j];
                break;
            }
        }
    }
}
}  // namespace n0026b008

// 0026b0f8 (was src/anon/perm_0026b0f8.cpp)
namespace n0026b0f8 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Q26b0f8
{
  u8 pad[18];
  u8 n;
  u8 pad2[33];
  u16 h52[8];
  u16 h68[8];
};
struct P26b0f8
{
  u8 pad[580];
  Q26b0f8 *q;
};
struct I26b0f8
{
  u16 id;
  u8 a;
  u8 flag;
  u8 pad[2];
};
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f010 asm("D_0035f010");
s32 func_0028b040(u32) asm("_ZN2Tz8JmReport7GetDataEj");
s32 func_00257130() asm("_ZN2Tz5CmTop11GetItemInfoEv");
I26b0f8 *func_00281f20(s32) asm("_ZN2Tz8ItemInfo7GetInfoEv");
s32 func_00257070(s32) asm("_ZN2Tz5CmTop9GetCurPosEi");
P26b0f8 *func_00281180(u32, s32) asm("_ZN2Tz9PartyInfo8GetSheetEi");
s32 func_00281198(u32, s32) asm("_ZN2Tz9PartyInfo8GetPartyEi");
void func_00282240(s32, s32, s32) asm("func_00282240");
void Tz__ItemInfo__MakeMsgTbl(s32, s32, s32) asm("Tz__ItemInfo__MakeMsgTbl");
/*TARGET 0026b0f8*/
void Tz__CmEquip__CtrlAutoConfirm() asm("Tz__CmEquip__CtrlAutoConfirm");
void Tz__CmEquip__CtrlAutoConfirm()
{
  s32 idx = func_0028b040(D_0035f01c);
  I26b0f8 *t = func_00281f20(func_00257130());
  I26b0f8 *info = (I26b0f8 *) (((u32) (idx * 6)) + ((u32) t));
  u8 new_var;
  u16 id = info->id;
  s32 none = info->flag == 0;
  Q26b0f8 *q = func_00281180(D_0035f010, func_00257070(1))->q;
  s32 i;
  new_var = q->n;
  for (i = 0; i < new_var; i++)
  {
    if ((q->h52[i] == id) || (q->h68[i] == id))
    {
      q->h68[i] = (none) ? (id) : (0);
    }
  }

  if (idx)
  {
    idx = func_00281198(D_0035f010, func_00257070(1)) + 5;
    func_00282240(func_00257130(), idx, 0);
    Tz__ItemInfo__MakeMsgTbl(func_00257130(), 0, 0);
  }
  else
  {
    idx = func_00281198(D_0035f010, func_00257070(1)) + 5;
    func_00282240(func_00257130(), idx, 0);
    Tz__ItemInfo__MakeMsgTbl(func_00257130(), 0, 0);
  }
}
}  // namespace n0026b0f8

// 0026b200 (was src/anon/batch_w3836.cpp)
namespace n0026b200 {
// --------------------
// 0026b200: true if the current entry's id is found in the second id list but not the first.
u32 func_0028b040(u32) asm("func_0028b040");
u32 func_00257130(void) asm("func_00257130");
u8* func_00281f20(u32) asm("func_00281f20");
u32 func_00257070(u32) asm("func_00257070");
u8* func_00281180(u32, u32) asm("func_00281180");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f010 asm("D_0035f010");
struct E26b200 { u16 id; u8 pad; u8 on; u16 x; };
struct S26b200 { u8 pad[18]; u8 n; u8 pad2[33]; u16 a[8]; u16 b[8]; };
/*TARGET 0026b200*/
s32 func_0026b200(void) asm("func_0026b200");
s32 func_0026b200(void) {
    s32 idx = func_0028b040(D_0035f01c);
    u32 b = (u32)func_00281f20(func_00257130());
    E26b200* e = (E26b200*)(idx * sizeof(E26b200) + b);
    s32 r;
    register u32 id asm("$17") = e->id;
    if (!e->on) {
        r = 0;
    } else {
        S26b200* t = *(S26b200**)(func_00281180(D_0035f010, func_00257070(1)) + 580);
        u8 n = t->n;
        s32 i;
        for (i = 0; i < n; i++) {
            if ((t->a[i] == id || t->b[i] == id) && t->a[i] != id) {
                r = 1;
                goto out;
            }
        }
        r = 0;
    }
out:
    // no code: keeps idx live so the product gets its own register
    asm("" :: "r"(idx));
    return r;
}
}  // namespace n0026b200

// 0026b2c0 (was src/anon/batch_w279.cpp)
namespace n0026b2c0 {
// ---- func_0026b2c0
u8* item_get_info(void*) asm("_ZN2Tz8ItemInfo7GetInfoEv");
s32 menu_get_mode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
s32 cmtop_get_select_pos(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
s32 cmtop_get_cur_pos(s32) asm("_ZN2Tz5CmTop9GetCurPosEi");
s32 jm_report_get_data(u32) asm("_ZN2Tz8JmReport7GetDataEj");
u8* party_get_sheet(void*, s32) asm("_ZN2Tz9PartyInfo8GetSheetEi");
u16* Tz__CmEquip__GetItemTbl(s32, s32) asm("Tz__CmEquip__GetItemTbl");
u8* func_001a80c8(s32) asm("func_001a80c8");
// table24_find_by_id
u8* YS__ITEM_TABLE__get_param(u8*) asm("YS__ITEM_TABLE__get_param");
extern void* D_0035f0ec asm("D_0035f0ec");
extern u32 D_0035f01c asm("D_0035f01c");
extern void* D_0035f010 asm("D_0035f010");
union W279Slot { u16 raw; struct { u16 id : 15; u16 on : 1; } b; };
static inline u8 w279_stat(u16 id) {
    if (id == 0) return 0;
    return YS__ITEM_TABLE__get_param(func_001a80c8(id))[7];
}
/*TARGET 0026b2c0*/
s32 func_0026b2c0(void) asm("func_0026b2c0");
s32 func_0026b2c0(void) {
    u8* info = item_get_info(D_0035f0ec);
    u16 sel;
    u16 old;
    s32 sum;
    s32 i;
    W279Slot* p;
    if (menu_get_mode() != 8) return 0;
    sel = 0;
    u16* r = Tz__CmEquip__GetItemTbl(cmtop_get_select_pos(2), 2);
    if (r) sel = *r;
    if (sel == 0) return 0;
    s32 k = jm_report_get_data(D_0035f01c);
    old = k ? *(u16*)(info + k * 6 - 6) : 0;
    sum = 0;
    s32 who = cmtop_get_cur_pos(1);
    p = (W279Slot*)(*(u8**)(party_get_sheet(D_0035f010, who) + 580) + 84);
    for (i = 0; i < 80; i++) {
        W279Slot x = *p++;
        if (x.b.id && (x.raw >> 15)) sum += func_001a80c8(x.b.id)[7];
    }
    u16 cap = *(u16*)(party_get_sheet(D_0035f010, who) + 398);
    s32 a;
    if (sel) a = YS__ITEM_TABLE__get_param(func_001a80c8(sel))[7];
    else a = 0;
    s32 d = a - w279_stat(old);
    if (cap - sum - d < 0) return 1;
    return 0;
}
}  // namespace n0026b2c0

// 0026b448 (was src/anon/batch_w10.cpp)
namespace n0026b448 {
void func_0026b470(void) asm("func_0026b470");
void Tz__CmEquip__SortEquip(void) asm("Tz__CmEquip__SortEquip");
void func_0026b5a0(s32) asm("func_0026b5a0");
/*TARGET 0026b448*/
// 0x0025ccc0: definition moved into src/anon/unit_002588e8.cpp

void func_0026b448(void) asm("func_0026b448");
// 0x0025ccc0: definition moved into src/anon/unit_002588e8.cpp

void func_0026b448(void) {
    func_0026b470();
    Tz__CmEquip__SortEquip();
    func_0026b5a0(-1);
}
}  // namespace n0026b448

// 0026b470 (was src/anon/batch_w60.cpp)
namespace n0026b470 {
extern u32 D_0035f010 asm("D_0035f010");
s32 func_00257070(s32) asm("func_00257070");
u8* func_00281180(u32, s32) asm("func_00281180");
// Packs the non-zero entries to the front.
struct Slots26b { u8 pad[16]; u8 n; u8 pad2[3]; u16 a[1]; };
/*TARGET 0026b470*/
void func_0026b470(void) asm("func_0026b470");
void func_0026b470(void) {
    Slots26b* t = *(Slots26b**)(func_00281180(D_0035f010, func_00257070(1)) + 580);
    u8 n = t->n;
    s32 i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (t->a[i] == 0 && t->a[j] != 0) {
                t->a[i] = t->a[j];
                t->a[j] = 0;
            }
        }
    }
}
}  // namespace n0026b470

// 0026b508 (was src/anon/batch_w61.cpp)
namespace n0026b508 {
u32 func_00257070(u32) asm("func_00257070");
u8* func_00281180(u32, u32) asm("func_00281180");
extern u32 D_0035f010 asm("D_0035f010");
struct T26 { u8 pad[17]; u8 n; u8 pad2[18]; u16 a[1]; };
/*TARGET 0026b508*/
void Tz__CmEquip__SortEquip(void) asm("Tz__CmEquip__SortEquip");
void Tz__CmEquip__SortEquip(void) {
    T26* t = *(T26**)(func_00281180(D_0035f010, func_00257070(1)) + 580);
    s32 n = t->n;
    for (s32 i = 0; i < n; i++) {
        for (s32 j = i + 1; j < n; j++) {
            if (t->a[i] == 0 && t->a[j] != 0) {
                t->a[i] = t->a[j];
                t->a[j] = 0;
            }
        }
    }
}
}  // namespace n0026b508

// 0026b5a0 (was src/anon/batch_w3902_nsa.cpp)
namespace n0026b5a0 {
struct Ent26b { s32 a; s32 b; s32 c; };
struct Obj26b { u8 p0[0x12]; u8 n; u8 p13[0x34 - 0x13]; u16 x[8]; u16 y[8]; };
extern s32 D_0035f010 asm("D_0035f010");
s32 func_00257070(s32) asm("func_00257070");
u8* func_00281180(s32, s32) asm("func_00281180");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
u16* func_001a8110(u16*) asm("func_001a8110");
/*TARGET 0026b5a0*/
// Sorts the object's (x, y) id pairs by the order in which the ids appear in
// the func_001a8110 list. Reusing v for the func_00257070 result gives v the
// v0 preference; the explicit goto reproduces the original's jump threading.
void func_0026b5a0(s32 arg) asm("func_0026b5a0");
// Sorts the object's (x, y) id pairs by the order in which the ids appear in
// the func_001a8110 list. Reusing v for the func_00257070 result gives v the
// v0 preference; the explicit goto reproduces the original's jump threading.
void func_0026b5a0(s32 arg)
{
    Ent26b e[8];
    s32 ids[8];
    u16* it = 0;
    s32 i, j, cnt, ord;
    s32 v;
    Obj26b* o;
    v = func_00257070(arg < 0 ? 1 : arg);
    o = *(Obj26b**)(func_00281180(D_0035f010, v) + 0x244);
    u8 n = o->n;
    func_002fde18(e, 0, sizeof(e));
    for (i = 0; i < n; i++) {
        Ent26b* p = &e[i];
        p->a = o->x[i];
        p->b = o->y[i];
        p->c = 999;
    }
    cnt = 0;
    for (i = 0; i < n; i++) {
        { s32 t = e[i].a; if (t) { v = t; goto have; } }
        v = e[i].b;
        if (v == 0) continue;
    have:
        for (j = 0; j < cnt; j++)
            if (v == ids[j]) break;
        if (j < cnt) continue;
        ids[cnt++] = v;
    }
    ord = 0;
    for (;;) {
        it = func_001a8110(it);
        if (!it) break;
        if (((u8*)it)[2]) continue;
        for (i = 0; i < cnt; i++) {
            if (it[0] != ids[i]) continue;
            for (j = 0; j < n; j++) {
                if (e[j].a == ids[i] || e[j].b == ids[i]) e[j].c = ord + (e[j].a == 0);
            }
            ord += 2;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (e[j].c < e[i].c) {
                Ent26b t = e[i];
                e[i] = e[j];
                e[j] = t;
            }
        }
    }
    for (i = 0; i < n; i++) {
        o->x[i] = e[i].a;
        o->y[i] = e[i].b;
    }
}
}  // namespace n0026b5a0

// 0026b850 (was src/tozawa/cmenu_equip.cpp)
namespace Tz { // method 0026b850
extern u32 D_00373788 asm("D_00373788");
/*TARGET 0026b850*/
void* Tz_CmEquip_GetFormMsgTbl() asm("_ZN2Tz7CmEquip13GetFormMsgTblEv");
void* Tz_CmEquip_GetFormMsgTbl() { return &D_00373788; }
}  // Tz

// 0026b860 (was src/anon/auto80_199_queue.cpp)
namespace n0026b860 {
/*TARGET 0026b860*/
u32 func_0026b860(u32 a0) asm("_Z13func_0026b860j");
u32 func_0026b860(u32 a0) {
    u32 s0 = a0 & 0xFF;
    u32 s1 = func_00257070(1);
    u32 v0 = func_00281100(D_0035f010);
    s32 t6 = (s32)v0 - 1;

    if (s0 != 0) {
        s1 = s1 + 1;
        if (!((s32)s1 < (s32)v0)) {
            s1 = 0;
        }
    } else {
        s1 = s1 - 1;
        if ((s32)s1 < 0) {
            s1 = (u32)t6;
        }
    }

    func_00257050(1, s1, 0);
    v0 = func_00281140(D_0035f010, s1);
    return func_0028fb68(1, v0);
}
}  // namespace n0026b860

// 0026b8f0 (gap, written for the unit)
namespace n0026b8f0 {
extern u32 D_0035f010 asm("D_0035f010");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f0ec asm("D_0035f0ec");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00281100(u32) asm("func_00281100");
s32 func_0028b040(u32) asm("func_0028b040");
s32 func_00269508(s32) asm("func_00269508");
u32 func_00257130(void) asm("func_00257130");
u8* func_00281f20(u32) asm("func_00281f20");
s32 func_002570a0(s32) asm("func_002570a0");
s32 func_00281f18(u32) asm("func_00281f18");
s32 func_0026aaf8(u32) asm("_Z13func_0026aaf8jjjj");
s32 func_0026b8f0(s32 k) asm("func_0026b8f0");
s32 func_0026b8f0(s32 k) {
    s32 r = 0;
    s32 idx;
    u8* t;
    s32 m = func_00287bc0();
    if (m == 2) {
        if ((u32)(k + 11) < 2) {
            r = (func_00281100(D_0035f010) < 2) == 0;
        } else {
            r = 1;
            idx = func_0028b040(D_0035f01c);
            if (func_00269508(idx) == 4 && k == -6) {
                t = func_00281f20(func_00257130());
                if (*(u16*)(t + idx * 6) == 0) r = 0;
            }
        }
    } else if (k < 0) {
        r = 1;
    } else {
        t = func_00281f20(func_00257130());
        idx = func_002570a0(2);
        s32 v = func_00281f18(D_0035f0ec);
        if ((u32)(m - 5) < 2) {
            if (v) r = func_0026aaf8(*(u16*)(t + idx * 6));
        } else {
            u16 id = *(u16*)(t + idx * 6);
            if (id) r = func_0026aaf8(id);
            else r = 1;
        }
    }
    return r;
}
}  // namespace n0026b8f0

// 0026ba48 (was src/anon/batch_w1589_g.cpp)
namespace n0026ba48 {
s32 func_00103570(void) asm("func_00103570");
void* func_001063c0(s32, s32) asm("func_001063c0");
void func_00323408(void*) asm("func_00323408");
void func_001a8bb8(void*) asm("func_001a8bb8");
extern u8 D_0035f0f0 asm("D_0035f0f0");
extern void* D_0035f0f4 asm("D_0035f0f4");
extern void* D_0035f0fc asm("D_0035f0fc");
/*TARGET 0026ba48*/
void func_0026ba48(void) asm("func_0026ba48");
void func_0026ba48(void)
{
    void* o;
    D_0035f0f0 = 0;
    o = func_001063c0(6252, func_00103570());
    func_00323408(o);
    D_0035f0f4 = o;
    o = func_001063c0(4, func_00103570());
    func_001a8bb8(o);
    D_0035f0fc = o;
}
}  // namespace n0026ba48

// 0026bab8 (was src/anon/perm_0026bab8.cpp)
namespace n0026bab8 {
typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*DtorFn)(void *);
void func_00106420(void *) asm("_ZN2Tz12LoadDataFreeEz");
void func_00239870(void *) asm("_ZN2YI8SEQUENCED1Ev");
extern u8 D_0035f0f0 asm("D_0035f0f0");
extern u32 D_0035f0f8 asm("D_0035f0f8");
extern void *D_0035f0fc asm("D_0035f0fc");
extern u8 *D_0035f0f4 asm("D_0035f0f4");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
inline static void vdtor(void *e)
{
  (*((DtorFn *) ((*((u8 **) e)) + 12)))(e);
}
/*TARGET 0026bab8*/
void func_0026bab8(void) asm("func_0026bab8");
void func_0026bab8(void)
{
  D_0035f0f0 = 0;
  D_0035f0f8 = 0;
  if (D_0035f0fc)
  {
    func_00106420(D_0035f0fc);
    D_0035f0fc = 0;
  }
  u8 *p = D_0035f0f4;
  if (p)
  {
    if (p + 3816)
    {
      u8 *e = (p + 3816) + (5 * 436);
      u8 *b = p + 3816;
      a:
      if (b == e)
      {
        goto a_out;
      }

      e -= 436;
      vdtor(e);
      goto a;
      a_out:
      ;

      ;
    }
    if (p + 2040)
    {
      u8 *e = (p + 2040) + (4 * 436);
      u8 *b = p + 2040;
      b:
      if (b == e)
      {
        goto b_out;
      }

      if (p)
      {
        e -= 436;
        vdtor(e);
        goto b;
      }
      else
      {
        e -= 436;
        vdtor(e);
        goto b;
      }
      b_out:
      ;

      ;
    }
    if (p + 408)
    {
      u8 *e = (p + 408) + (4 * 408);
      u8 *b = p + 408;
      c:
      if (b == e)
      {
        goto c_out;
      }

      e -= 408;
      vdtor(e);
      goto c;
      c_out:
      ;

      ;
    }
    *((u32 *) p) = (u32) D_00347e60;
    func_00239870(p + 24);
    *((u32 *) p) = (u32) D_00347f98;
    func_00106420(p);
    D_0035f0f4 = 0;
  }
}
}  // namespace n0026bab8

// 0026bbe0 (was src/tozawa/cmenu_party.cpp)
namespace Tz { // method 0026bbe0
extern void Tz_CmParty_FadeOutList(void) asm("_ZN2Tz7CmParty11FadeOutListEv");
/*TARGET 0026bbe0*/
void Tz_CmParty_FadeOutAll() asm("_ZN2Tz7CmParty10FadeOutAllEv");
void Tz_CmParty_FadeOutAll() { Tz_CmParty_FadeOutList(); }
}  // Tz

// 0026bbf8 (was src/tozawa/cmenu_party.cpp)
namespace Tz { // method 0026bbf8
extern void Tz_CmParty_LeaveList(void) asm("_ZN2Tz7CmParty9LeaveListEv");
/*TARGET 0026bbf8*/
void Tz_CmParty_LeaveAll() asm("_ZN2Tz7CmParty8LeaveAllEv");
void Tz_CmParty_LeaveAll() { Tz_CmParty_LeaveList(); }
}  // Tz

// 0026bc10 (was src/anon/batch_w3696_mam.cpp)
namespace n0026bc10 {
struct B4 { u8 b[4]; };
struct Elem { u8 pad0[0x18]; u8 f18[0x198 - 0x18]; s32 f198; u8 pad1[0x1b0 - 0x19c]; s32 f1b0; };
union HU { s16 h; u8 c; };
struct Big { u8 pad0[0x7f8]; Elem e[4]; HU arr[4][4]; };
extern B4* D_0035f0fc asm("D_0035f0fc");
extern Big* D_0035f0f4 asm("D_0035f0f4");
union BigU { Big* p; u8 c; };
extern BigU D_f0f4u asm("D_0035f0f4");
union U32U { u32 v; u8 c; };
extern U32U D_f010u asm("D_0035f010");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f024 asm("D_0035f024");
extern u32 D_0035f010 asm("D_0035f010");
extern u32 D_0035f03c asm("D_0035f03c");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef64 asm("D_0035ef64");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0037382c asm("D_0037382c");
extern s32 D_00373830 asm("D_00373830");
B4* func_00293bc0(void) asm("func_00293bc0");
void func_002937c0(void) asm("func_002937c0");
void func_00288f48(u32, s32, s32, s32, s32) asm("func_00288f48");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
s32 func_00256b68(s32) asm("func_00256b68");
void func_0028d8c0(s32, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
s32 func_00281100(u32) asm("func_00281100");
s32 func_00281180(u32, s32) asm("func_00281180");
s32 func_00281140(u32, s32) asm("func_00281140");
void Tz__Select__SetItem(u32, s32, u32, u32, u32, s32, HU*, HU*) asm("Tz__Select__SetItem");
u8* func_002891b8(u32, s32) asm("func_002891b8");
void func_00138c10(u8*, s32) asm("func_00138c10");
void Tz__Select__SetExOffset(u32, s32, s32, s32) asm("Tz__Select__SetExOffset");
void func_0028dcc0(void*, s32) asm("func_0028dcc0");
s32 func_001a8c78(B4*, s32) asm("func_001a8c78");
void func_0028d980(Elem*, s32, u32, u32, u32, s32, s32, s32, s32) asm("func_0028d980");
s32 func_0023aa98(void*) asm("func_0023aa98");
void func_00138c68(Elem*, s32, s32) asm("func_00138c68");
void func_0028b1b0(u32, s32) asm("func_0028b1b0");
void Tz__Select__SetCurrent(u32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
s32 func_0028af88(u32) asm("func_0028af88");
void func_0028af18(u32, s32) asm("func_0028af18");
void func_00257708(s32) asm("func_00257708");
void func_00287cc0(s32) asm("func_00287cc0");
void func_0026c140(void) asm("func_0026c140");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0026c048(void) asm("func_0026c048");
void func_0026cb38(void) asm("func_0026cb38");
/*TARGET 0026bc10*/
void func_0026bc10(void) asm("func_0026bc10");
void func_0026bc10(void)
{
    s32 i;
    s32 n;
    s32 saved;
    s32 cnt;
    s32 mask;
    s32 sel;
    B4* st = func_00293bc0();
    *D_0035f0fc = *st;
    func_002937c0();
    func_00288f48(D_0035f01c, 64, 128, 0, 0);
    func_00288f48(D_0035f024, 64, 128, 0, 0);
    func_0028f4d8(0, -1, 0);
    s32 h = func_00256b68(1);
    func_0028d8c0(h, 0x753d, D_0035ef68, D_0035ef64, D_0035f03c, 312, 313, 0);
    for (i = 0; i < func_00281100(D_0035f010); i++) {
        for (s32 k = 0; k < 4; k++) (*(Big* volatile*)&D_0035f0f4)->arr[i][k].h = (i != 3) ? 315 : 316;
    }
    n = 0;
    saved = D_0035f3d4;
    D_0035f3d4 = 0x753e;
    for (i = 0; i < 4; i++) {
        if (func_00281180(D_0035f010, i)) {
            Tz__Select__SetItem(D_0035f01c, n, D_0035ef68, D_0035ef64, D_0035f03c, -1, D_0035f0f4->arr[n], D_0035f0f4->arr[n]);
            func_00138c10(func_002891b8(D_0035f01c, n), D_0035f0f4->arr[n][2].h);
            *(s32*)(func_002891b8(D_0035f01c, n) + 0x188) = -1;
            Tz__Select__SetExOffset(D_0035f01c, n, -1, 0);
            func_0028dcc0(func_002891b8(D_0035f01c, n), h);
            n++;
        }
    }
    for (i = 0; i < n; i++) {
        func_0028d980(&D_f0f4u.p->e[i], 0x753e, D_0035ef68, D_0035ef64, D_0035f03c,
                      (i == 0 || func_001a8c78(st, i)) ? D_0037382c : D_00373830, -1, -1, 0);
        func_00138c68(&D_f0f4u.p->e[i], func_0023aa98(D_f0f4u.p->e[i].f18) * i, 0);
        func_0028dcc0(&D_f0f4u.p->e[i], h);
        Elem* e = &D_f0f4u.p->e[i];
        e->f1b0 = 2;
        e = &D_f0f4u.p->e[i];
        e->f198 = func_00281140(D_f010u.v, i);
    }
    cnt = 0;
    sel = n >= 2;
    D_0035f3d4 = saved;
    /* the multi-player branch is the cold path */
    if (__builtin_expect(sel, 0)) {
        mask = 1;
        for (i = 1; i < n; i++) {
            if (func_001a8c78(st, i)) {
                mask |= 1 << i;
                cnt++;
            } else if (func_001a8c78(st, sel)) {
                sel = i;
            }
        }
        func_0028b1b0(D_0035f01c, mask);
    }
    Tz__Select__SetCurrent(D_0035f01c, sel, 0, -1, -1);
    if (n < 3 || n - cnt < 3) {
        mask = func_0028af88(D_0035f01c) & ~0x13;
        func_0028af18(D_0035f01c, mask);
        func_00257708(1);
    }
    func_00287cc0(0);
    func_0026c140();
    if (func_00287bc0() == 20) func_0026c048();
    func_0026cb38();
}
}  // namespace n0026bc10

// 0026c048 (was src/anon/batch_w81.cpp)
namespace n0026c048 {
// 0x0025af70: definition moved into src/anon/unit_002588e8.cpp

// --- 0026c048
extern u32 D_0035f010 asm("D_0035f010");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f024 asm("D_0035f024");
extern u8* D_0035f0f4 asm("D_0035f0f4");
s32 func_00281180(u32, s32) asm("func_00281180");
u32 func_002891b8(u32, s32) asm("func_002891b8");
void func_00288ce0(u32, u32, s32, u8*, u8*) asm("func_00288ce0");
void Tz__Select__SetSelectMax(u32, s32) asm("Tz__Select__SetSelectMax");
// obj_set_field22_from_arg
void func_0028b1e8(u32, u32) asm("func_0028b1e8");
void func_00257708(u32) asm("func_00257708");
/*TARGET 0026c048*/
void func_0026c048(void) asm("func_0026c048");
void func_0026c048(void) {
    s32 i;
    s32 n = 0;
    for (i = 0; i < 4; i++) {
        if (func_00281180(D_0035f010, i)) {
            u32 v = func_002891b8(D_0035f01c, n);
            func_00288ce0(D_0035f024, v, n, D_0035f0f4 + n * 8 + 3784, D_0035f0f4 + n * 8 + 3784);
            n++;
        }
    }
    Tz__Select__SetSelectMax(D_0035f024, n);  // obj_set_field22_from_arg
    func_0028b1e8(D_0035f024, 1);
    if (n < 3) func_00257708(1);
}
}  // namespace n0026c048

// .rodata 0x373730-0x373810: file tables that old code reads as extern D_
extern const u32 R_00373730[1] asm("D_00373730") __attribute__((aligned(4))) = { 0x32 };
extern const u32 R_00373734[13] asm("D_00373734") __attribute__((aligned(4))) = { 0x31, 0x10a0109, 0xf800fc, 0x106, 0x0, 0x10affff, 0xffffffff, 0x10c010b, 0xffff, 0x11c011b, 0x1140116, 0x118, 0x0 };
extern const u32 R_00373768[8] asm("D_00373768") __attribute__((aligned(4))) = { 0x845d845b, 0x84658463, 0x8467, 0x0, 0x11cffff, 0xffffffff, 0x11e011d, 0xffff };
extern const u32 R_00373788[4] asm("D_00373788") __attribute__((aligned(4))) = { 0x845d0000, 0xce9fb353, 0x8461845f, 0x0 };
extern const u32 R_00373798[12] asm("D_00373798") __attribute__((aligned(4))) = { 0xd100cf, 0xd900d0, 0xda00db, 0xad00ab, 0x9900ac, 0x9a009b, 0xb600b4, 0xb5, 0xe200d8, 0xa100b3, 0xbc, 0x0 };
extern const u32 R_003737c8[8] asm("D_003737c8") __attribute__((aligned(4))) = { 0xd700d5, 0xdf00d6, 0xe000e1, 0xb200b0, 0x9e00b1, 0x9f00a0, 0xbb00b9, 0xba };
extern const u32 R_003737e8[10] asm("D_003737e8") __attribute__((aligned(4))) = { 0xdd00d3, 0x9d00af, 0xd200b8, 0xae00dc, 0xb7009c, 0x0, 0xde00d4, 0xffffffff, 0xffff, 0x0 };

