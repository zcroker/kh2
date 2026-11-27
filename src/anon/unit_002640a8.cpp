// Linked unit 0x002640a8-0x00264be0 (one namespace per old matched source; class methods in their own namespace).
#include "../tozawa/cmenu_item.hpp"
#include "../tozawa/cmenu_slbase.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../common/types.h"
#include <stdarg.h>
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
#include "../tozawa/scroll_bar.hpp"
#include "../tozawa/cmenu_help.hpp"

// 002640a8 (was src/anon/batch_w1598.cpp)
namespace n002640a8 {
struct E24 { s16 id; s16 k; u8 pad4[10]; u16 f14; u16 n; u16 pad18; u32 off; };
struct H16 { u8 pad0[6]; s16 count; u8 pad8[8]; E24 e[1]; };
struct Sub8 { s16 a; u16 b; u32 off; };
H16* func_00263ea8(void) asm("func_00263ea8");
u32 func_001a6d08(s32) asm("func_001a6d08");
void func_002641c8(u32, u8*, u32, u32) asm("func_002641c8");
/*TARGET 002640a8*/
void func_002640a8(s32 a0, u16 a1, u32 a2) asm("func_002640a8");
void func_002640a8(s32 a0, u16 a1, u32 a2) {
    s32 i;
    H16* h = func_00263ea8();
    E24* e;
    for (i = 0, e = h->e; i < h->count; i++, e++) {
        if (e->id == a0) continue;
        if (!func_001a6d08(e->k)) continue;
        if (e->f14 & 0x80) continue;
        Sub8* s = (Sub8*)((u8*)h + e->off);
        s32 j;
        for (j = 0; j < e->n; j++, s++) {
            if (s->a < 0) func_002641c8(a2, (u8*)h + s->off, s->b, a1);
        }
    }
}
}  // namespace n002640a8

// 002641c8 (was src/anon/batch_w84.cpp)
namespace n002641c8 {
// Adds each id from the list that is not present yet and passes the mask.
u16 func_002642a8(u16) asm("func_002642a8");
struct Lst { u8 _0[10]; u16 cnt; u8 _12[4]; u16 ids[1]; };
/*TARGET 002641c8*/
void func_002641c8(Lst* p, u16* list, s32 n, u16 mask) asm("func_002641c8");
void func_002641c8(Lst* p, u16* list, s32 n, u16 mask) {
    for (s32 i = 0; i < n; i++) {
        u16 id = list[i];
        s32 j;
        for (j = 0; j < p->cnt; j++) {
            if (id == ((u16*)((u8*)p + 16))[j]) break;
        }
        if (j < p->cnt) continue;
        if (mask & func_002642a8(id)) {
            p->ids[p->cnt] = id;
            p->cnt++;
        }
    }
}
}  // namespace n002641c8

// 002642a8 (was src/anon/perm_002642a8.cpp)
namespace n002642a8 {
typedef unsigned char u8;
typedef signed int s32;
u8 *func_001a80c8(void) asm("func_001a80c8");
/*TARGET 002642a8*/
s32 func_002642a8(void) asm("func_002642a8");
s32 func_002642a8(void)
{
  s32 r;
  u8 *new_var;
  new_var = func_001a80c8();
  r = 0;
  switch (new_var[2])
  {
    case 0:

    case 1:
      r = 8;
      break;

    case 2:

    case 3:

    case 4:

    case 5:

    case 6:

    case 7:

    case 8:

    case 9:

    case 10:

    case 11:

    case 12:

    case 13:
      r = 1;
      break;

    case 14:
      r = 2;
      break;

    case 15:
      r = 4;
      break;

    case 16:
      r = 0x10;
      break;

  }

  return r;
}
}  // namespace n002642a8

// 00264318 (was src/anon/tiny.cpp)
namespace n00264318 {
/*TARGET 00264318*/
void func_00264318(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00264318jjjj");
void func_00264318(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u32*)((u32)b + (-3872)) = (u32)a0;
}
}  // namespace n00264318

// 00264328 (was src/anon/batch_w42.cpp)
namespace n00264328 {
// 00264328: index of `id` in the 128-entry table, or -1
u8* func_00263ea8(void) asm("func_00263ea8");
/*TARGET 00264328*/
// get_global_36f1d0
s32 func_00264328(u32 id) asm("func_00264328");
// get_global_36f1d0
s32 func_00264328(u32 id)
{
    u8* h = func_00263ea8();  // get_global_36f1d0
    u16* t = (u16*)(h + *(u32*)(h + 12));
    s32 r = -1;
    for (s32 i = 0; i < 128; i++) {
        if (t[i] == id) { r = i; break; }
    }
    return r;
}
}  // namespace n00264328

// 00264388 (was src/anon/batch_w1588.cpp)
namespace n00264388 {
void* func_00103570(void) asm("func_00103570");
void* func_001063c0(u32, void*) asm("func_001063c0");
void func_002fde18(void*, s32, u32) asm("func_002fde18");
extern void* D_0035f0e4 asm("D_0035f0e4");
extern u8 D_0035f0e8 asm("D_0035f0e8");
/*TARGET 00264388*/
void Tz__CmStat__Init(void) asm("Tz__CmStat__Init");
void Tz__CmStat__Init(void) {  // alloc_global_buffer
    void* p = func_001063c0(2116, func_00103570());
    D_0035f0e4 = p;
    func_002fde18(p, 0, 2116);
    D_0035f0e8 = 0;
}
}  // namespace n00264388

// 002643d0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002643d0 {
u32 func_00106420(...) asm("func_00106420");
/*TARGET 002643d0*/
void func_002643d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002643d0jjjjjjjj");
void func_002643d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // release_global_buffer
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = (u32)(0x0036u << 16);
    r15 = *(u32*)((u32)r16 + (s32)(-3868));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00106420)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(u32*)((u32)r16 + (s32)(-3868)) = 0u;
    }
}
}  // namespace n002643d0

// 00264408 (was src/anon/tiny_auto80_queue.cpp)
namespace n00264408 {
void func_00265580(...) asm("func_00265580");
void Tz__CmAbility__FadeOutAll(...) asm("Tz__CmAbility__FadeOutAll");
u32 func_00287db0(...) asm("func_00287db0");
u32 func_00287bc0(...) asm("func_00287bc0");
u32 func_00256e80(...) asm("func_00256e80");
/*TARGET 00264408*/
void func_00264408() asm("_Z13func_00264408v");
void func_00264408() {
    if ((u32)(func_00287bc0() - 23u) >= 2u) {
        return;
    }
    func_00265580();
    Tz__CmAbility__FadeOutAll();
    if (func_00287db0() == 0u) {
        return;
    }
    func_00256e80();
}
}  // namespace n00264408

// 00264458 (was src/anon/tiny_auto80_queue.cpp)
namespace n00264458 {
void func_002655e8(...) asm("func_002655e8");
void func_00265ab8(...) asm("func_00265ab8");
void func_00256ea8(...) asm("_ZN2Tz5CmTop12LeavePadHelpEv");
u32 func_00287bc0(...) asm("func_00287bc0");
/*TARGET 00264458*/
void func_00264458() asm("_Z13func_00264458v");
void func_00264458() {
    if ((u32)(func_00287bc0() - 23u) >= 2u) {
        return;
    }
    func_002655e8();
    func_00265ab8();
    func_00256ea8();
}
}  // namespace n00264458

// 002644a0 (was pad)
extern "C" const u32 D_003732e4 = 0;  // .rodata zero word between two jump tables (no code loads it)
// 002644a0 (cont src/anon/batch_w3753_mam.cpp)
namespace n002644a0 {
struct Info28 { u8 pad[28]; u16 mask; };
extern Info28* D_0035f0e4 asm("D_0035f0e4");
extern u8 D_0035f0e8 asm("D_0035f0e8");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f03c asm("D_0035f03c");
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035ef68 asm("D_0035ef68");
extern s32 D_0035ef6c asm("D_0035ef6c");
extern s32 D_003734f8 asm("D_003734f8");
extern s32 D_003734fc asm("D_003734fc");
u8* func_00257770(void) asm("func_00257770");
void func_00267320(void) asm("func_00267320");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void func_00266c90(void) asm("func_00266c90");
s32 func_00257100(s32) asm("func_00257100");
s32 func_00257118(s32) asm("func_00257118");
void Tz__Select__SetItem(u32, s32, u32, u32, u32, s32, s32, s32) asm("Tz__Select__SetItem");
u8* func_002891b8(u32, s32) asm("func_002891b8");
s32 func_0023aa98(u8*) asm("func_0023aa98");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_00139620(u8*) asm("func_00139620");
void func_001395f8(u8*) asm("func_001395f8");
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
s32 func_0028afa8(u32) asm("func_0028afa8");
s32 Tz__CmStat__GetSelMsg(s32) asm("Tz__CmStat__GetSelMsg");
s32 func_002670a0(s32) asm("func_002670a0");
s32 Tz__CmNewFlg__isStatNew(s32) asm("Tz__CmNewFlg__isStatNew");
s32 func_002864f8(s32) asm("func_002864f8");
s32 func_00192048(s32) asm("func_00192048");
void func_00138c10(u8*, s32) asm("func_00138c10");
s32 func_00257070(s32) asm("func_00257070");
s32 func_002670f8(s32) asm("func_002670f8");
void Tz__Select__SetCurrent(u32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void Tz__CmStat__CreateTopList(void) asm("Tz__CmStat__CreateTopList");
void func_002657a8(void) asm("func_002657a8");
void Tz__CmStat__UpdateNew(void) asm("Tz__CmStat__UpdateNew");
void func_002666a8(void) asm("func_002666a8");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 002644a0*/
void Tz__CmStat__SetupTop(u8 flag) asm("Tz__CmStat__SetupTop");
void Tz__CmStat__SetupTop(u8 flag)
{
    s32 saved;
    u8* base = func_00257770();
    if (flag) func_00267320();
    func_0028f4d8(0, -1, 0);
    s32 y = 0;
    s32 n = 0;
    s32 f;
    func_00266c90();
    s32 i;
    u8* o;
    saved = D_0035f3d4;
    u8* w = base + 0x87d0;
    D_0035f3d4 = 30015;
    for (i = 0; i < 10; i++) {
        if (((D_0035f0e4->mask >> i) ^ 1) & 1) continue;
        s32 t, b;
        if (i == 0 || i >= 7) {
            t = func_00257100(0);
            b = func_00257100(1);
        } else {
            t = func_00257118(0);
            b = func_00257118(1);
        }
        Tz__Select__SetItem(D_0035f01c, n, D_0035ef68, D_0035ef64, D_0035f03c, -1, t, b);
        o = func_002891b8(D_0035f01c, n);
        n++;
        s32 h = func_0023aa98(o + 24);
        func_00138c68(o, 0, y);
        y += h;
        func_00139620(o);
        func_001395f8(o);
        func_0028d8c0(w, 30017, D_0035ef68, D_0035ef64, D_0035f03c, D_0035ef6c, -1, 0);
        func_0028dcc0(w, o);
        s32 x = func_0023aa18(o + 24);
        func_00138c68(w, x, func_0023aa38(o + 24));
        w += 408;
    }
    D_0035f3d4 = saved;
    n = func_0028afa8(D_0035f01c);
    for (i = 0; i < n; i++) {
        o = func_002891b8(D_0035f01c, i);
        s32 r = -1;
        s32 id = Tz__CmStat__GetSelMsg(i);
        switch (func_002670a0(i)) {
        case 1:
            if (Tz__CmNewFlg__isStatNew(0)) r = func_002864f8(0) ? D_003734fc : D_003734f8;
            break;
        case 2:
            if (Tz__CmNewFlg__isStatNew(1)) r = func_002864f8(1) ? D_003734fc : D_003734f8;
            break;
        case 3:
            if (Tz__CmNewFlg__isStatNew(2)) r = func_002864f8(2) ? D_003734fc : D_003734f8;
            break;
        case 4:
            if (Tz__CmNewFlg__isStatNew(3)) r = func_002864f8(3) ? D_003734fc : D_003734f8;
            break;
        case 5:
            if (Tz__CmNewFlg__isStatNew(4)) r = func_002864f8(4) ? D_003734fc : D_003734f8;
            break;
        case 6: {
            s32 t;
            f = 0;
            for (t = 5; t < 9; t++) {
                if (Tz__CmNewFlg__isStatNew(t)) {
                    f = 1;
                    break;
                }
            }
            if (f) {
                f = 0;
                for (t = 5; t < 9; t++) {
                    if (Tz__CmNewFlg__isStatNew(t) && !func_002864f8(t)) {
                        f = 1;
                        break;
                    }
                }
                r = f ? D_003734f8 : D_003734fc;
            }
            break;
        }
        case 9:
            break;
        }
        *(s32*)(o + 408) = func_00192048(id);
        if (r >= 0) func_00138c10(base + i * 408 + 0x87d0, r);
    }
    s32 v = func_002670f8(func_00257070(23));
    if (v < 0) v = 0;
    Tz__Select__SetCurrent(D_0035f01c, v, 1, 0, 2);
    Tz__CmStat__CreateTopList();
    func_002657a8();
    Tz__CmStat__UpdateNew();
    func_002666a8();
    D_0035f0e8 = 0;
    func_00287cc0(0);
}
}  // namespace n002644a0

// 002648b8 (was src/anon/batch_wcx2.cpp)
namespace n002648b8 {
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
// 0x0025b7b8: definition moved into src/anon/unit_002588e8.cpp

// ---- 002648b8
extern void* D_0035f01c_48b8 asm("D_0035f01c");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00289380(void* s) asm("func_00289380");
s32 func_00289310_48b8(void* s) asm("func_00289310");
s32 func_00287c10(void) asm("func_00287c10");
s32 func_0028f930(s32 a) asm("func_0028f930");
s32 func_002656c0(void) asm("func_002656c0");
s32 func_00257970(void) asm("func_00257970");
void func_00287f90(s32 a) asm("func_00287f90");
void func_002655e8(void) asm("func_002655e8");
void func_0028f7e8(s32 a) asm("func_0028f7e8");
void func_00287c30(void) asm("func_00287c30");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00267398(void) asm("func_00267398");
void func_002551b8(void) asm("func_002551b8");
void Tz__CmStat__SetupHelp(void) asm("Tz__CmStat__SetupHelp");
s32 func_0028ae28(void* s, s32 a) asm("func_0028ae28");
s32 func_00265740(void) asm("func_00265740");
void func_0028ab20(void* s) asm("func_0028ab20");
void func_00265780(void) asm("func_00265780");
void func_0028fa98(s32 a) asm("func_0028fa98");
void func_00287cc0(s32 s) asm("func_00287cc0");
s32 func_00287df0_48b8(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a) asm("func_00242848");
void Tz__CMenuHelp__FadeOut(void) asm("Tz__CMenuHelp__FadeOut");
// sync_global_index_if_changed
void func_00265580(void) asm("func_00265580");
u8* func_002891b8_48b8(void* p, s32 n) asm("func_002891b8");
void func_0028fb68(s32 a, u32 b) asm("func_0028fb68");
u32 func_002891e8_48b8(void* s) asm("func_002891e8");
u32 func_002670a0(u32 a) asm("func_002670a0");
void func_00257050_48b8(s32 a, u32 b, s32 c) asm("func_00257050");
void func_00287c00(s32 m) asm("func_00287c00");
void func_00287c90(s32 a) asm("func_00287c90");
void func_00287da0(void) asm("func_00287da0");
void Tz__SelHist__FadeOut(s32 a) asm("Tz__SelHist__FadeOut");
// record884_refresh_by_index
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
/*TARGET 002648b8*/
// global_zero_4dwords

// Party/item menu: per-frame state update.
void Tz__CmStat__CtrlTop(void) asm("Tz__CmStat__CtrlTop");
// global_zero_4dwords

// Party/item menu: per-frame state update.
void Tz__CmStat__CtrlTop(void) {
    s32 cur = func_00289380(D_0035f01c_48b8);
    s32 st = func_00287cd0();
    if (st == 2) {
        s32 r = 0;
        s32 next = func_00287c10();
        if (next == 0) r = func_0028f930(0);
        if (func_002656c0() || r || func_00257970()) {
            if (cur == -1 && !func_00289310_48b8(D_0035f01c_48b8)) return;
            func_00287f90(0);
            func_002655e8();
            if (next == 0) func_0028f7e8(0);
            return;
        }
        func_00287c30();
        s32 m = func_00287bc0();
        if (m == 0) {
            func_0028f7e8(0);
            func_00267398();
            func_002551b8();
        } else if (m == 24) {
            Tz__CmStat__SetupHelp();
        }
        return;
    }
    if (cur != -1 || func_00289310_48b8(D_0035f01c_48b8)) {
        if (!func_0028ae28(D_0035f01c_48b8, 0) || !func_00265740()) {
            func_0028ab20(D_0035f01c_48b8);
            func_00265780();
            func_0028fa98(-1);
        }
    }
    if (st == 0 && func_0028ae28(D_0035f01c_48b8, 0) && func_00265740()) func_00287cc0(1);
    if (!func_00242848(func_00287df0_48b8(cur, func_00289310_48b8(D_0035f01c_48b8), 1, 0, 1))) {
        switch (cur) {
        case -2:
            Tz__CMenuHelp__FadeOut();  // sync_global_index_if_changed
            Tz__SelHist__FadeOut(0);  // record884_refresh_by_index
            func_00265580();
            func_00257050_48b8(23, func_002670a0(func_002891e8_48b8(D_0035f01c_48b8)), 0);
            func_00287c90(1);
            func_00287c00(0);
            break;
        case -4:
            func_00257050_48b8(23, func_002670a0(func_002891e8_48b8(D_0035f01c_48b8)), 0);
            func_00267398();
            func_00287da0();
            break;
        case -1:
            break;
        default:
            Tz__CMenuHelp__FadeOut();  // sync_global_index_if_changed
            func_00265580();
            func_0028fb68(1, *(u32*)(func_002891b8_48b8(D_0035f01c_48b8, cur) + 408));
            func_00257050_48b8(23, func_002670a0(func_002891e8_48b8(D_0035f01c_48b8)), 0);
            func_00287c00(24);
            func_00287c90(1);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n002648b8

