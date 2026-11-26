#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/cmenu_selector.hpp"
#include "../tozawa/cmenu_slbase.hpp"
#include "../tz/ui_accessors.hpp"
#include "../tozawa/jm_info.hpp"
#include "../tozawa/file_address_layout.hpp"
#include "../tozawa/item_stat.hpp"
#include "../harata/libdk/obj2d.hpp"
#include "../tozawa/load_data.hpp"

// 00290f78 (from src/tozawa/item_stat.cpp)
namespace Tz {
u32 u_call4_00139d78_is(u32) asm("_Z16u_call4_00139d78jjjj");
void dk_Sprite_setNum_raw_is(u32, u32) asm("_ZN2dk6Sprite6setNumEi");
u32 wtarget_002fde18_is(u32, u32, u32) asm("_Z16wtarget_002fde18jjjj");
void func_00290d68_is(...) asm("Tz__ItemStat__CreateSeq");
void func_00290f78_is(...) asm("_ZN2Tz8ItemStat8ClearSeqEv");
u32 func_00291380_is(...) asm("func_00291380");
void func_00291510_is(...) asm("Tz__ItemStat__Update");
void func_00291ba8_is(...) asm("func_00291ba8");
void* ItemStat::ClearSeq() {
    s32 s4 = (s32)this;
    s32 s1;
    s32 s2;
    s32 s3;
    s32 s0;

    s3 = s4 + 2180;
    s1 = s4;
    s2 = GetFontSeq(0);
    do {
        s0 = s1 + 4;
        if (u_call4_00139d78_is(s0) != 0) {
            dk_Sprite_setNum_raw_is(s0, s2);
            *(u32*)(s0 + 408) = 0;
        }
        s0 = s1 + 2184;
        if (u_call4_00139d78_is(s0) != 0) {
            dk_Sprite_setNum_raw_is(s0, s2);
            *(u32*)(s0 + 408) = 0;
        }
        s1 += 436;
    } while (s1 < s3);

    s0 = s4 + 4364;
    s1 = 14;
    do {
        if (u_call4_00139d78_is(s0) != 0) {
            dk_Sprite_setNum_raw_is(s0, s2);
            *(u32*)(s0 + 408) = 0;
        }
        s1 -= 1;
        s0 += 436;
    } while ((s32)s1 >= 0);

    return (void*)wtarget_002fde18_is(s4 + 10904, 0, 120);
}
}  // namespace Tz

// 00291068 (from src/tozawa/item_stat.cpp)
namespace Tz {
u32 u_call4_00139d78_is(u32) asm("_Z16u_call4_00139d78jjjj");
void dk_Sprite_setNum_raw_is(u32, u32) asm("_ZN2dk6Sprite6setNumEi");
u32 wtarget_002fde18_is(u32, u32, u32) asm("_Z16wtarget_002fde18jjjj");
void func_00290d68_is(...) asm("Tz__ItemStat__CreateSeq");
void func_00290f78_is(...) asm("_ZN2Tz8ItemStat8ClearSeqEv");
u32 func_00291380_is(...) asm("func_00291380");
void func_00291510_is(...) asm("Tz__ItemStat__Update");
void func_00291ba8_is(...) asm("func_00291ba8");
void ItemStat::UpdateNowStat(s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    u32 s19 = (u32)a1;
    u32 s16 = (u32)this;
    u32 s17 = (u32)a2;
    u32 s20 = (u32)a4;
    u32 s21 = (u32)a5;

    func_00290d68_is(s16, (u32)a3);
    func_00290f78_is(s16);
    u32 s18 = func_00291380_is(s16, s17);
    func_00291510_is(s16, s19, s17, s18);
    func_00291ba8_is(s16, s19, s17, s20, s21, s18);
}
}  // namespace Tz

// 00291110 (from src/anon/batch_w88.cpp)
namespace n00291110 {
void Tz__ItemStat__CreateSeq(u32, u32) asm("Tz__ItemStat__CreateSeq");
void func_00290f78(u32) asm("func_00290f78");
u32 func_00291380(u32, u32) asm("func_00291380");
void Tz__ItemStat__Update(u32, u32, u32, u32) asm("Tz__ItemStat__Update");
void Tz__ItemStat__UpdateNewItem(u32, u32, u32, u32, u32) asm("Tz__ItemStat__UpdateNewItem");
void Tz__ItemStat__UpdateNextStat(u32, u32, u32, u32, u32, u32, u32) asm("Tz__ItemStat__UpdateNextStat");
void func_00291110(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) asm("func_00291110");
void func_00291110(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    Tz__ItemStat__CreateSeq(a, e);
    func_00290f78(a);
    u32 m = (func_00291380(a, c) | func_00291380(a, d)) & ~0x100;
    Tz__ItemStat__Update(a, b, c, m);
    Tz__ItemStat__UpdateNewItem(a, b, c, d, m);
    Tz__ItemStat__UpdateNextStat(a, b, c, d, f, g, m);
}
}  // namespace n00291110

// 002911f8 (from src/anon/auto80_199_queue.cpp)
namespace n002911f8 {
u32 func_00139d78(...) asm("func_00139d78");
void func_002911f8(u32 self) asm("func_002911f8");
void func_002911f8(u32 self) {
    u32 s16 = self;
    s32 s17 = 0;
    u32 s18 = self;

    for (;;) {
        if (func_00139d78(s16 + 4) != 0) {
            break;
        }
        if (func_00139d78(s16 + 2184) != 0) {
            break;
        }
        s17 += 1;
        u32 cont = (u32)(s17 < 5);
        s16 += 436;
        if (cont != 0) {
            continue;
        }
        {
            s16 = s18 + 4364;
            s17 = 0;
            u32 arg = s16;
            for (;;) {
                if (func_00139d78(arg) != 0) {
                    break;
                }
                s17 += 1;
                if (s17 >= 15) {
                    break;
                }
                s16 += 436;
                arg = s16;
            }
            break;
        }
    }
}
}  // namespace n002911f8

// 00291288 (from src/anon/batch_w90.cpp)
namespace n00291288 {
struct VObj { void** vt; };
s32 func_00139d78(void*) asm("func_00139d78");
// 00265ab8: stop every active effect slot.
typedef void (*VoidFn)(void*);
static inline void StopIfActive(VObj* o) { if (func_00139d78(o)) ((VoidFn)o->vt[5])(o); }
// 00291288
void func_00291288(u8* self) asm("func_00291288");
void func_00291288(u8* self)
{
    u8* p = self;
    s32 i;
    for (i = 4; i >= 0; i--) {
        StopIfActive((VObj*)(p + 4));
        StopIfActive((VObj*)(p + 2184));
        p += 436;
    }
    p = self;
    for (i = 14; i >= 0; i--) {
        StopIfActive((VObj*)(p + 4364));
        p += 436;
    }
}
}  // namespace n00291288

// 00291358 (from src/tozawa/item_stat.cpp)
namespace n00291358 {
// plain function: a member named Clear makes the build registry take LoadData::Clear (0x292690) for this file
void* ClearSeq(void*) asm("_ZN2Tz8ItemStat8ClearSeqEv");
void ItemStat_Clear(void* p) asm("_ZN2Tz8ItemStat5ClearEv");
void ItemStat_Clear(void* p) { static_cast<void>(ClearSeq(p)); }
}  // namespace n00291358

// 00291370 (from src/tozawa/item_stat.cpp)
namespace Tz {
s32 ItemStat::GetFontSeq(s32 idx) { return *(s16*)((u8*)this + 0x2b20 + idx * 2); }
}  // namespace Tz

// 00291380 (from src/anon/perm_00291380.cpp)
namespace n00291380 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
u8 *func_002924d0() asm("func_002924d0");
u8 *func_001a80c8(u32) asm("func_001a80c8");
s32 func_002914a8(u32, u32) asm("func_002914a8");
inline int inline_fn(u8 *arg0, int arg1)
{
  return arg0[2] == arg1;
}
u32 func_00291380(u32 a, u32 id) asm("func_00291380");
u32 func_00291380(u32 a, u32 id)
{
  u32 r;
  u8 *p;
  u8 *q;
  if (id == 0)
  {
    return 0;
  }
  r = 6;
  p = func_002924d0();
  q = func_001a80c8(id);
  if (!func_002914a8(a, id))
  {
    r = 248;
    if (q[2] != 14)
    {
      r = 0;
      if (inline_fn(q, 15))
      {
        r = 7;
      }
    }
  }
  if (p[7])
  {
    r |= 1;
  }
  if (p[4])
  {
    r |= 2;
  }
  if (p[5])
  {
    r |= 4;
  }
  if (p[6])
  {
    r |= 8;
  }
  if (p[9] != 100)
  {
    r |= 16;
  }
  if (p[10] != 100)
  {
    r |= 32;
  }
  if (p[11] != 100)
  {
    r |= 64;
  }
  if (p[12] != 100)
  {
    r |= 128;
  }
  if (func_002914a8(a, id) && (*((u16 *) (p + 2))))
  {
    r |= 256;
  }
  return r;
}
}  // namespace n00291380

// 002914a8 (from src/anon/batch_w40.cpp)
namespace n002914a8 {
u8* func_001a80c8(u32) asm("func_001a80c8");
extern s8 D_00374488[] asm("D_00374488");
// Is the item's kind byte in the -1 terminated list?
s32 func_002914a8(u32 a0, u32 a1) asm("func_002914a8");
s32 func_002914a8(u32 a0, u32 a1) {
    s32 r = 0;
    u8* v = func_001a80c8(a1);  // table24_find_by_id
    for (s32 i = 0; D_00374488[i] >= 0; i++) {
        if (v[2] == D_00374488[i]) { r = 1; break; }
    }
    return r;
}
}  // namespace n002914a8

// 00291510 (from src/anon/batch_w2457.cpp)
namespace n00291510 {
extern u16 D_00374548[] asm("D_00374548");
extern u16 D_00374560[] asm("D_00374560");
extern u32 D_00374498 asm("D_00374498");
extern u32 D_003744a0 asm("D_003744a0");
u8* func_002924d0(u8*, s32) asm("func_002924d0");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
s32 func_0023aa78(u8*) asm("func_0023aa78");
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
s32 func_00192048(s32) asm("func_00192048");
s32 func_00291370(u8*, s32) asm("func_00291370");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
u8* func_001a80c8(s32) asm("func_001a80c8");
void func_00192cc0(u8*, u32*, s32) asm("func_00192cc0");
void Tz__ItemStat__Update(u8* obj, s32 mode, s32 id, s32 mask) asm("Tz__ItemStat__Update");
void Tz__ItemStat__Update(u8* obj, s32 mode, s32 id, s32 mask)
{
    u8* p = func_002924d0(obj, id);
    s32 c;
    switch (mode) {
    case 0:
    case 4:
        c = *(s16*)(obj + 11054);
        break;
    case 1:
        c = *(s16*)(obj + 11056);
        break;
    case 2:
        c = *(s16*)(obj + 11060);
        break;
    case 3:
    default:
        c = *(s16*)(obj + 11064);
        break;
    }
    s32 k = 0;
    s32 t;
    u8* o = *(u8**)(obj + 400) + 24;
    s32 x2, y2;
    s32 X = func_0023aa18(o);
    s32 Y = func_0023aa38(o);
    for (u32 i = 0; (s32)i < 9; i++) {
        if (((mask >> i) ^ 1) & 1) continue;
        u8* e = obj + k * 436 + 4;
        if (mode == 1 && i == 8) c = *(s16*)(obj + 11058);
        func_00138c10(e, c);
        s32 x = X;
        s32 h = func_0023aa78(e + 24);
        x2 = func_0023aa18(e + 24);
        y2 = func_0023aa38(e + 24);
        s32 y = Y + h * k;
        func_00138c68(e, x, y);
        if (mode != 0) t = D_00374560[i];
        else t = D_00374548[i];
        if (t == 0) t = D_00374548[i];
        *(s32*)(e + 408) = func_00192048(t);
        if (mode - 2u < 2) {
            e = obj + k * 436 + 2184;
            if (mode == 2) t = *(s16*)(obj + 11062);
            else t = *(s16*)(obj + 11066);
            func_00138c10(e, t);
            func_00138c68(e, X, y);
        }
        x = x2;
        y = y2;
        e = obj + k * 436 + 4364;
        if ((mode == 0 || mode == 4) && i == 8) y += h;
        if (mode == 3) {
            t = func_00291370(obj, 0);
            x = 0;
            y = 0;
            func_0028dcc0(e, obj + k * 436 + 2184);
        } else if (i == 8) {
            t = func_00291370(obj, 2);
            func_0028dcc0(e, obj + k * 436 + 4);
        } else {
            t = func_00291370(obj, 0);
            func_0028dcc0(e, obj + k * 436 + 4);
        }
        func_00138c68(e, x, y);
        func_00138c10(e, t);
        t = -1;
        switch (i) {
        case 0: t = p[7]; break;
        case 1: t = p[4]; break;
        case 2: t = p[5]; break;
        case 3: t = p[6]; break;
        case 4: t = p[9]; break;
        case 5: t = p[10]; break;
        case 6: t = p[11]; break;
        case 7: t = p[12]; break;
        case 8: t = *(u16*)(p + 2); break;
        }
        *(s32*)(e + 432) = 1;
        if (i == 8) {
            u8* it = func_001a80c8(t);
            if (mode == 1) *(s32*)(e + 432) = 2;
            *(s32*)(e + 408) = func_00192048(*(u16*)(it + 8));
        } else {
            if (i - 4 < 4) func_00192cc0(obj + k * 8 + 10904, &D_00374498, 100 - t);
            else func_00192cc0(obj + k * 8 + 10904, &D_003744a0, t);
            *(u8**)(e + 408) = obj + k * 8 + 10904;
        }
        k++;
    }
}
}  // namespace n00291510

// 00291918 (from src/anon/batch_w1608.cpp)
namespace n00291918 {
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_00192cc0(u8*, u32*, s32) asm("func_00192cc0");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
s32 func_00291370(u8*, s32) asm("func_00291370");
u8* func_002924d0(u8*, s32) asm("func_002924d0");
extern u32 D_00374498 asm("D_00374498");
extern u32 D_003744a0 asm("D_003744a0");
void Tz__ItemStat__UpdateNewItem(u8* obj, s32 mode, s32 id1, s32 id2, s32 mask) asm("Tz__ItemStat__UpdateNewItem");
void Tz__ItemStat__UpdateNewItem(u8* obj, s32 mode, s32 id1, s32 id2, s32 mask) {
    u32 i;
    s32 k = 0;
    u8* p1 = func_002924d0(obj, id1);
    u8* p2 = func_002924d0(obj, id2);
    for (i = 0; (s32)i < 9; i++) {
        if (((mask >> i) ^ 1) & 1) continue;
        u8* e = obj + k * 436 + 0x888;
        s32 x, y;
        if (mode == 2) {
            x = 0;
            y = 0;
        } else {
            x = func_0023aa18(e + 0x18);
            y = func_0023aa38(e + 0x18);
        }
        s32 m = k + 5;
        u8* d = obj + m * 436 + 0x110c;
        func_0028dcc0(d, e);
        func_00138c68(d, x, y);
        s32 a = -1;
        s32 b = -1;
        switch (i) {
        case 0: a = p2[7]; b = p1[7]; break;
        case 1: a = p2[4]; b = p1[4]; break;
        case 2: a = p2[5]; b = p1[5]; break;
        case 3: a = p2[6]; b = p1[6]; break;
        case 4: a = p2[9]; b = p1[9]; break;
        case 5: a = p2[10]; b = p1[10]; break;
        case 6: a = p2[11]; b = p1[11]; break;
        case 7: a = p2[12]; b = p1[12]; break;
        }
        *(s32*)(d + 0x1b0) = 1;
        if (i - 4 < 4) {
            s32 r;
            if (a < b) r = 6; else r = (b < a) ? 3 : 0;
            func_00138c10(d, func_00291370(obj, r));
            func_00192cc0(obj + m * 8 + 0x2a98, &D_00374498, 100 - a);
        } else {
            s32 r;
            if (b < a) r = 6; else r = (a < b) ? 3 : 0;
            func_00138c10(d, func_00291370(obj, r));
            func_00192cc0(obj + m * 8 + 0x2a98, &D_003744a0, a);
        }
        k++;
        *(u8**)(d + 0x198) = obj + m * 8 + 0x2a98;
    }
}
}  // namespace n00291918

// 00291ba8 (from src/anon/batch_w2500.cpp)
namespace n00291ba8 {
u8* func_001a1728(s32, s32) asm("func_001a1728");
void YS__SHEET__Free(u8*) asm("YS__SHEET__Free");
s32 func_00291370(u8*, s32) asm("func_00291370");
s32 func_0023aa78(u8*) asm("func_0023aa78");
s32 func_0023aa98(u8*) asm("func_0023aa98");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_00192cc0(char*, const char*, ...) asm("func_00192cc0");
extern char D_00374498[] asm("D_00374498");
extern char D_003744a0[] asm("D_003744a0");
void func_00291ba8(u8* w, s32 mode, s32 a2, s32 a3, s32 a4, s32 mask) asm("func_00291ba8");
void func_00291ba8(u8* w, s32 mode, s32 a2, s32 a3, s32 a4, s32 mask) {
    if (__builtin_expect(mode == 0,0)) return;
    if (mode == 4) return;
    u8* r = func_001a1728(a3, a4);
    s32 base;
    if (__builtin_expect(mode == 2,0)) base = *(s16*)(w + 11062);
    else base = func_00291370(w, 2);
    s32 n = 0;
    u8* q = w + 28;
    s32 i = 0;
    func_0023aa78(q);
    s32 x = func_0023aa98(q);
    func_0023aa18(q);
    func_0023aa38(q);
    for (; __builtin_expect(i < 9, 1); i++) {
        bool off = !((mask >> i) & 1);
        if ((u8)off) continue;
        if (i == 8) continue;
        s32 k = n + 5;
        s32 v = mode == 1 ? x : 0;
        u8* o = w + k * 436 + 4364;
        func_00138c10(o, base);
        func_00138c68(o, v, 0);
        s32 val = -1;
        switch (i) {
        case 0: val = *(u16*)(r + 398); break;
        case 1: val = *(u16*)(r + 392); break;
        case 2: val = *(u16*)(r + 394); break;
        case 3: val = *(u16*)(r + 396); break;
        case 4: val = r[425]; break;
        case 5: val = r[426]; break;
        case 6: val = r[427]; break;
        case 7: val = r[428]; break;
        case 8: break;
        }
        if ((u32)(i - 4) < 4) func_00192cc0((char*)(w + k * 8 + 10904), D_00374498, 100 - val);
        else func_00192cc0((char*)(w + k * 8 + 10904), D_003744a0, val);
        n++;
        *(u8**)(o + 408) = w + k * 8 + 10904;
    }
    YS__SHEET__Free(r);
}
}  // namespace n00291ba8

// 00291de0 (from src/anon/batch_w1610.cpp)
namespace n00291de0 {
struct W1610Sl { u8 pad[408]; u8* name; u8 pad2[432 - 412]; s32 on; };
void func_00138c68(void*, s32, s32) asm("func_00138c68");
extern u8 D_00374498[] asm("D_00374498");
extern u8 D_003744a0[] asm("D_003744a0");
s32 func_001a1728(s32, s32) asm("func_001a1728");
void YS__SHEET__Free(s32) asm("YS__SHEET__Free");
s32 func_00291370(u8*, s32) asm("func_00291370");
s32 func_0023aa18(void*) asm("func_0023aa18");
s32 func_0023aa38(void*) asm("func_0023aa38");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
void func_00138c10(void*, s32) asm("func_00138c10");
void func_00192cc0(u8*, u8*, s32) asm("func_00192cc0");
s32 func_002920c0(u8*, s32*, s32, s32, s32) asm("func_002920c0");
s32 func_00292148(u8*, s32*, s32, s32, s32) asm("func_00292148");
s32 func_002921d0(u8*, s32*, s32, s32, s32) asm("func_002921d0");
s32 func_00292258(u8*, s32*, s32, s32, s32) asm("func_00292258");
s32 func_002922e0(u8*, s32*, s32, s32, s32, s32) asm("func_002922e0");
void Tz__ItemStat__UpdateNextStat(u8* w, s32 mode, s32 p2, s32 p3, s32 p4, s32 p5, s32 mask) asm("Tz__ItemStat__UpdateNextStat");
void Tz__ItemStat__UpdateNextStat(u8* w, s32 mode, s32 p2, s32 p3, s32 p4, s32 p5, s32 mask) {
    s32 h = func_001a1728(p4, p5);
    if (mode != 2) func_00291370(w, 2);
    s32 n = 0;
    for (s32 i = 0; i < 9; i++) {
        if (!((mask >> i) & 1)) continue;
        if (i == 8) continue;
        W1610Sl* s;
        if (mode == 2) s = (W1610Sl*)(w + n * 436 + 2184);
        else s = (W1610Sl*)(w + n * 436 + 4);
        s32 k = n + 10;
        s32 x = func_0023aa18((u8*)s + 24);
        s32 y = func_0023aa38((u8*)s + 24);
        W1610Sl* d = (W1610Sl*)(w + k * 436 + 4364);
        func_0028dcc0(d, s);
        func_00138c68(d, x, y);
        s32 sel = -1;
        s32 res = 1;
        switch (i) {
        case 0: res = func_002920c0(w, &sel, p2, p3, h); d->on = 1; break;
        case 1: res = func_00292148(w, &sel, p2, p3, h); d->on = 1; break;
        case 2: res = func_002921d0(w, &sel, p2, p3, h); d->on = 1; break;
        case 3: res = func_00292258(w, &sel, p2, p3, h); d->on = 1; break;
        case 4: res = func_002922e0(w, &sel, p2, p3, 1, h); d->on = 1; break;
        case 5: res = func_002922e0(w, &sel, p2, p3, 2, h); d->on = 1; break;
        case 6: res = func_002922e0(w, &sel, p2, p3, 3, h); d->on = 1; break;
        case 7: res = func_002922e0(w, &sel, p2, p3, 4, h); d->on = 1; break;
        case 8: default: { s32 one = 1; d->on = one; } break;
        }
        s32 a = 6;
        if (res != 2) a = res ? 0 : 3;
        func_00138c10(d, func_00291370(w, a));
        if ((u32)(i - 4) < 4) func_00192cc0(w + k * 8 + 10904, D_00374498, sel);
        else func_00192cc0(w + k * 8 + 10904, D_003744a0, sel);
        n++;
        d->name = w + k * 8 + 10904;
    }
    YS__SHEET__Free(h);
}
}  // namespace n00291de0

// 002920c0 (from src/anon/sweep_002920c0_nsa.cpp)
namespace n002920c0 {
u8* func_002924d0(s32, s32) asm("func_002924d0");
void func_00292520(s32, u32, u32) asm("func_00292520");
void func_002920c0(s32 a0, s32* a1, s32 a2, s32 a3, u8* t0) asm("func_002920c0");
void func_002920c0(s32 a0, s32* a1, s32 a2, s32 a3, u8* t0) {
    u8* x = func_002924d0(a0, a2);
    u8* y = func_002924d0(a0, a3);
    s32 v = *(u16*)(t0 + 0x18e);
    *a1 = v - x[7] + y[7];
    func_00292520(a0, x[7], y[7]);
}
}  // namespace n002920c0

// 00292148 (from src/anon/sweep_00292148_nsa.cpp)
namespace n00292148 {
u8* func_002924d0(s32, s32) asm("func_002924d0");
void func_00292520(s32, u32, u32) asm("func_00292520");
void func_00292148(s32 a0, s32* a1, s32 a2, s32 a3, u8* t0) asm("func_00292148");
void func_00292148(s32 a0, s32* a1, s32 a2, s32 a3, u8* t0) {
    u8* x = func_002924d0(a0, a2);
    u8* y = func_002924d0(a0, a3);
    s32 v = *(u16*)(t0 + 0x188);
    *a1 = v - x[4] + y[4];
    func_00292520(a0, x[4], y[4]);
}
}  // namespace n00292148

// 002921d0 (from src/anon/sweep_002921d0_nsa.cpp)
namespace n002921d0 {
u8* func_002924d0(s32, s32) asm("func_002924d0");
void func_00292520(s32, u32, u32) asm("func_00292520");
void func_002921d0(s32 a0, s32* a1, s32 a2, s32 a3, u8* t0) asm("func_002921d0");
void func_002921d0(s32 a0, s32* a1, s32 a2, s32 a3, u8* t0) {
    u8* x = func_002924d0(a0, a2);
    u8* y = func_002924d0(a0, a3);
    s32 v = *(u16*)(t0 + 0x18a);
    *a1 = v - x[5] + y[5];
    func_00292520(a0, x[5], y[5]);
}
}  // namespace n002921d0

// 00292258 (from src/anon/sweep_00292258_nsa.cpp)
namespace n00292258 {
typedef struct E6 { u8 pad[6]; u8 b; } E6;
typedef struct S18c { u8 pad[0x18c]; u16 h; } S18c;
E6* func_002924d0(s32, s32) asm("func_002924d0");
s32 func_00292520(s32, u32, u32) asm("func_00292520");
void func_00292258(s32 a0, s32* out, s32 a2, s32 a3, S18c* s) asm("func_00292258");
void func_00292258(s32 a0, s32* out, s32 a2, s32 a3, S18c* s) {
    E6* p = func_002924d0(a0, a2);
    E6* q = func_002924d0(a0, a3);
    *out = s->h - p->b + q->b;
    func_00292520(a0, p->b, q->b);
}
}  // namespace n00292258

// 002922e0 (from src/anon/sweep_002922e0_nsa.cpp)
namespace n002922e0 {
struct Tbl { u8 p0[16]; u8 n0; u8 n1; u8 p12[2]; u16 a[8]; u16 b[8]; };
struct Obj { u8 p0[424]; u8 r[156]; Tbl* t; };
struct Rec { u8 p0[2]; u8 kind; };
u8* func_002924d0(u8*, u32) asm("func_002924d0");
Rec* func_001a80c8(u32) asm("func_001a80c8");
void func_00292520(u8*, s32, s32) asm("func_00292520");
void func_002922e0(u8* p, s32* out, u32 id, u32 alt, u32 k, Obj* o) asm("func_002922e0");
void func_002922e0(u8* p, s32* out, u32 id, u32 alt, u32 k, Obj* o)
{
    s32 found = 0;
    func_002924d0(p, id);
    func_002924d0(p, alt);
    s32 base = 100 - o->r[k];
    u32 q = id ? id : alt;
    s32 kind;
    if (q) kind = func_001a80c8(q)->kind;
    else kind = -1;
    s32 v = 100;
    s32 i;
    for (i = 0; i < o->t->n0; i++) {
        u32 a = o->t->a[i];
        if (!found && kind == 14 && a == id) { a = alt; found = 1; }
        if (a) v = (v * func_002924d0(p, a)[k + 8] + 99) / 100;
    }
    for (i = 0; i < o->t->n1; i++) {
        u32 a = o->t->b[i];
        if (!found && kind == 15 && a == id) { a = alt; found = 1; }
        if (a) v = (v * func_002924d0(p, a)[k + 8] + 99) / 100;
    }
    *out = 100 - v;
    func_00292520(p, base, 100 - v);
}
}  // namespace n002922e0

// 002924d0 (from src/anon/batch_w28.cpp)
namespace n002924d0 {
u32 func_001a80c8(u32) asm("func_001a80c8");
u8* YS__ITEM_TABLE__get_param(u32) asm("YS__ITEM_TABLE__get_param");
u8* func_002924d0(u8* p, u32 a) asm("func_002924d0");
u8* func_002924d0(u8* p, u32 a) {  // find_or_default_offset
    u8* r = a ? YS__ITEM_TABLE__get_param(func_001a80c8(a)) : p + 0x2b3c;
    return r ? r : p + 0x2b3c;
}
}  // namespace n002924d0

// 00292520 (from src/anon/tiny_auto80_queue.cpp)
namespace n00292520 {
u32 func_00292520(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00292520");
u32 func_00292520(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = ((s32)r5 < (s32)r6);
    r2 = (u32)((s32)0u + (2));
    if (r15 == 0u) {
        r15 = ((s32)r6 < (s32)r5);
        r2 = ((u32)r15 < 0x00000001u);
    }
    return r2;
}
}  // namespace n00292520

// 00292540 (from src/anon/batch_w1666.cpp)
namespace n00292540 {
extern u8 D_0035f4b8 asm("D_0035f4b8");
void func_00292540(void) asm("func_00292540");
void func_00292540(void) { D_0035f4b8 = 0; }
}  // namespace n00292540

// 00292550 (from src/anon/tiny_wrappers_more.cpp)
namespace n00292550 {
extern "C" u32 Tz_LoadData_Clear(u32, u32, u32, u32) asm("_ZN2Tz8LoadData5ClearEi");
u32 func_00292550(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00292550");
u32 func_00292550(u32 a0, u32 a1, u32 a2, u32 a3) {
    return Tz_LoadData_Clear(0x000013ecu, a1, a2, a3);
}
}  // namespace n00292550

// 00292568 (from src/tozawa/load_data.cpp)
namespace Tz {
u32 func_00170cd0_ld(...) asm("YS__CACHE_BUFF__IsFlushing");
void func_00170518_ld(...) asm("func_00170518");
extern u8 D_00360000_ld asm("D_00360000");
void YS_CACHE_BUFF_Flush_ld(TASK*) asm("_ZN2YS10CACHE_BUFF5FlushEP4TASK");
void LoadData::Request(const char* a0, s32 a1, bool a2) {
    u32 s16 = (u32)a0;
    u32 s17 = (u32)a1;
    if (((u32)a2 & 0xff) == 0) {
        func_00170cd0_ld();
    }
    func_00170518_ld(s16, s17, 0);
    u8* base = (u8*)&D_00360000_ld;
    base[-2888] = 1;
}
}  // namespace Tz

// 002925c0 (from src/anon/batch_w30.cpp)
namespace n002925c0 {
u8* func_00103eb0(void) asm("func_00103eb0");
u8* TASK_MANAGER__create_thread(u32, u32, u32, void*, u32) asm("TASK_MANAGER__create_thread");
void func_00292608(void*) asm("_ZN2Tz8LoadData9FlushTaskEP4TASK");
void func_00292620(void) asm("func_00292620");
}  // namespace n002925c0
namespace Tz {
void LoadDataFlush();
}
void Tz::LoadDataFlush() {
    using namespace n002925c0;
    u8* t = func_00103eb0();
    u8* r = TASK_MANAGER__create_thread(*(u32*)(t + 4), 0, 0x222e0, (void*)func_00292608, 4096);
    *(void**)(r + 0x30) = (void*)func_00292620;
}

// 00292608 (from src/tozawa/load_data.cpp)
namespace Tz {
u32 func_00170cd0_ld(...) asm("YS__CACHE_BUFF__IsFlushing");
void func_00170518_ld(...) asm("func_00170518");
extern u8 D_00360000_ld asm("D_00360000");
void YS_CACHE_BUFF_Flush_ld(TASK*) asm("_ZN2YS10CACHE_BUFF5FlushEP4TASK");
void LoadData::FlushTask(TASK* task) { YS_CACHE_BUFF_Flush_ld(task); }
}  // namespace Tz

