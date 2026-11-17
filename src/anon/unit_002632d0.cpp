// Linked unit 0x002632d0-0x00263ee0 (one namespace per old matched source; class methods in their own namespace).
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

// 002632d0 (was src/anon/auto80_199_queue.cpp)
namespace n002632d0 {
/*TARGET 002632d0*/
u32 func_002632d0(u32 a0) asm("_Z13func_002632d0j");
u32 func_002632d0(u32 a0) {
    u32 s1 = a0;
    u8* s0 = func_00281f20(func_00257130());

    u32 v0 = func_00281f18(func_00257130());
    if (v0 == 0) {
        return v0;
    }

    u8* p = (u8*)((s1 * 6) + (u32)s0);
    return func_001a80c8((u32)(*(u16*)p));  // table24_find_by_id
}
}  // namespace n002632d0

// 00263340 (was src/anon/auto80_199_queue.cpp)
namespace n00263340 {
/*TARGET 00263340*/
void func_00263340(u32 a0, u32 a1) asm("_Z13func_00263340jj");
void func_00263340(u32 a0, u32 a1) {
    (void)a0;

    if (a1 == 1) {
        func_00261d48();
        func_00262af8();
        return;
    }

    if (a1 != 10) {
        func_00262af8();
        return;
    }

    if (func_00289358() != 0) {
        func_00262820();
        func_00262a30();
        return;
    }

    func_00262a30();
    func_00262af8();
}
}  // namespace n00263340

// 002633a8 (was src/anon/batch_w98.cpp)
namespace n002633a8 {
s32 func_00139d78(u8*) asm("func_00139d78");
extern u32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035f03c asm("D_0035f03c");
u8* func_00257770(u32) asm("func_00257770");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028d008(u32) asm("func_0028d008");
u8* func_0028d0e0(u32) asm("func_0028d0e0");
void func_0028d8c0(u8*, u32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0(u8*, u32) asm("func_0028dcc0");
/*TARGET 002633a8*/
// Shows or hides the help window for an entry.
void func_002633a8(u32 id, u8 show) asm("func_002633a8");
// Shows or hides the help window for an entry.
void func_002633a8(u32 id, u8 show) {
    u8* base = func_00257770(id);
    s32 k = func_00287bc0();
    u8* m = k == 11 ? base + 816 : base + 1224;
    if (k == 13) id = 1;
    s32 busy = func_00139d78(m);
    if (func_0028d008(id)) {
        if (!busy) {
            func_0028d8c0(m, D_0035f3d4 + 2, D_0035ef68, D_0035ef64, D_0035f03c, 290, -1, 0);
            func_0028dcc0(m, *(u32*)(func_0028d0e0(id) + 396));
        }
        if (show) func_0028dcc0(m, *(u32*)(func_0028d0e0(id) + 396));
    } else if (busy) {
        (*(void (**)(u8*))(*(u8**)m + 20))(m);
    }
}
}  // namespace n002633a8

// 002634c8 (was src/anon/tiny.cpp)
namespace n002634c8 {
void func_002634c8(s32) asm("_Z13func_002634c8jjjj");
/*TARGET 002634c8*/
void func_002634c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002634c8jjjj");
void func_002634c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u8*)((u32)b + (-3915)) = (u8)a0;
}
}  // namespace n002634c8

// 002634d8 (was src/anon/batch_w1592.cpp)
namespace n002634d8 {
extern s8 D_0035f0b5 asm("D_0035f0b5");
s32 func_00257130(void) asm("func_00257130");
void func_00282240(s32, s32, s32) asm("func_00282240");
void func_00282d70(s32) asm("func_00282d70");
/*TARGET 002634d8*/
void func_002634d8(s32 a) asm("func_002634d8");
void func_002634d8(s32 a) {
    s32 n;
    if (a < 0) a = D_0035f0b5;
    switch (a) {
    case 2: n = 11; break;
    default:
    case 0: n = 0; break;
    case 1: n = 13; break;
    case 3: n = 12; break;
    case 4: n = 14; break;
    }
    func_00282240(func_00257130(), 0, n);
    func_00282d70(func_00257130());
}
}  // namespace n002634d8

// 00263570 (was src/anon/auto80_199_queue.cpp)
namespace n00263570 {
void func_00262768(void) asm("_Z13func_00262768v");
/*TARGET 00263570*/
void func_00263570(s32 a0) asm("_Z13func_00263570i");
void func_00263570(s32 a0) {
    s32 t;

    if (a0 == -10) {
        t = *(u8*)&D_0035f0b5;
        t = t + 1;
        D_0035f0b5 = (u8)t;
        if ((s8)t >= 5) {
            D_0035f0b5 = 0;
        }
    } else {
        t = *(u8*)&D_0035f0b5;
        t = t - 1;
        D_0035f0b5 = (u8)t;
        if ((s8)t < 0) {
            D_0035f0b5 = 4;
        }
    }

    func_00262768();
}
}  // namespace n00263570

// 002635d8 (was src/anon/batch_w54.cpp)
namespace n002635d8 {
u8* func_002632d0(void) asm("func_002632d0");
/*TARGET 002635d8*/
s32 func_002635d8(void) asm("func_002635d8");
s32 func_002635d8(void) {
    s8 tbl[3] = {0, 1, -1};
    s32 r = 0;
    u8* v = func_002632d0();
    u8 c = v[2];
    s32 i;
    for (i = 0; tbl[i] >= 0; i++) {
        if (c == tbl[i]) {
            r = 1;
            break;
        }
    }
    return r;
}
}  // namespace n002635d8

// 00263660 (was src/anon/tiny_jal_wrappers.cpp)
namespace n00263660 {
u32 func_002632d0(u32, u32, u32, u32) asm("_Z13func_002632d0jjjj");
/*TARGET 00263660*/
u32 func_00263660(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00263660jjjj");
u32 func_00263660(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_002632d0(r4, r5, r6, r7);
    r2 = (u32)(*(u16*)((u32)r2 + (s32)(14)));
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
}  // namespace n00263660

// 00263688 (was src/anon/batch_w2.cpp)
namespace n00263688 {
u16* func_002632d0() asm("func_002632d0");
u8 func_001a3888(u16) asm("func_001a3888");
/*TARGET 00263688*/
// 0x00258d58: definition moved into src/anon/unit_002588e8.cpp

u8 func_00263688(void) asm("func_00263688");
// 0x00258d58: definition moved into src/anon/unit_002588e8.cpp

u8 func_00263688(void) {
    return func_001a3888(*func_002632d0());  // id_in_range_5_7_131
}
}  // namespace n00263688

// 002636b0 (was src/anon/batch_w49.cpp)
namespace n002636b0 {
// Returns 1 if the current id is in the -1-terminated list.
u16* func_002632d0(void) asm("func_002632d0");
extern s16 D_00373270[] asm("D_00373270");
/*TARGET 002636b0*/
s32 func_002636b0(void) asm("func_002636b0");
s32 func_002636b0(void) {
    u16 k = *func_002632d0();
    s32 r = 0;
    for (s32 i = 0; D_00373270[i] >= 0; i++)
        if (D_00373270[i] == k) {
            r = 1;
            break;
        }
    return r;
}
}  // namespace n002636b0

// 00263720 (was src/anon/auto80_199_queue.cpp)
namespace n00263720 {
u32 func_002632d0(u32 a0) asm("_Z13func_002632d0j");
u32 func_002811b0(u32, s32) asm("_ZN2Tz9PartyInfo10GetPartNumEi");
/*TARGET 00263720*/
void func_00263720(u32 a0) asm("_Z13func_00263720j");
void func_00263720(u32 a0) {
    u16 s0 = *(u16*)func_002632d0((u32)Tz::CmTop::GetSelectPos(10));
    u32 v0 = func_002811b0(D_0035f010, a0);
    u32 (*fp)(u32, u32) = func_001a2d78;
    (void)fp((u32)s0, v0);
}
}  // namespace n00263720

// 00263778 (was src/anon/perm_00263778.cpp)
namespace n00263778 {
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
void func_0013dbb0(void) asm("func_0013dbb0");
volatile short func_001a2a50(u32, s32, s32, s32) asm("func_001a2a50");
void func_001a3458(u32, s32) asm("func_001a3458");
s32 func_002570a0(s32) asm("func_002570a0");
u16 *func_002632d0(s32) asm("func_002632d0");
s32 func_002811b0(s32, s32) asm("func_002811b0");
extern s32 D_0035f010 asm("D_0035f010");
/*TARGET 00263778*/
void func_00263778(s32 a0) asm("func_00263778");
void func_00263778(s32 a0)
{
  u16 id = *func_002632d0(func_002570a0(10));
  s32 v = func_002811b0(D_0035f010, a0);
  func_001a2a50(id, v, 0, 100);
  func_001a3458(id, 100);
  func_0013dbb0();
}
}  // namespace n00263778

// 002637e8 (was src/anon/batch_w36.cpp)
namespace n002637e8 {
u32 func_002570a0(u32) asm("func_002570a0");
s32 func_002635d8(u32) asm("func_002635d8");
s32 func_00263660(u32) asm("func_00263660");
/*TARGET 002637e8*/
s32 func_002637e8(s32 a) asm("func_002637e8");
s32 func_002637e8(s32 a) {
    u32 h = func_002570a0(10);
    if (!a) a = func_002635d8(h) == 0;
    else a = 1;
    if (a == 1) {
        if (!func_00263660(h)) a = -1;
    }
    return a;
}
}  // namespace n002637e8

// 00263858 (was src/anon/auto80_199_queue.cpp)
namespace n00263858 {
/*TARGET 00263858*/
void func_00263858(s32 a0) asm("_Z13func_00263858i");
void func_00263858(s32 a0) {
    s32 s0 = a0;
    s32 s1 = func_00257070(10);
    s32 v0 = func_00257088(10);

    if ((v0 + s1) < s0) {
        return;
    }

    if (s1 != 0) {
        s1 -= 1;
    } else {
        if (v0 != 0) {
            v0 -= 2;
        } else {
            s1 = 0;
        }
    }

    func_00257050(10, s1, v0);
}
}  // namespace n00263858

// 002638e0 (was src/anon/batch_w55.cpp)
namespace n002638e0 {
s32 func_00287bc0(void) asm("func_00287bc0");
// get_global_36ee90
s32 func_002637e8(s32) asm("func_002637e8");
/*TARGET 002638e0*/
// 0x0025d620: definition moved into src/anon/unit_002588e8.cpp

s32 func_002638e0(s32 a) asm("func_002638e0");
// 0x0025d620: definition moved into src/anon/unit_002588e8.cpp

s32 func_002638e0(s32 a) {
    s32 r = 0;
    switch (func_00287bc0()) {
    case 10: r = 1; break;
    case 1: r = 1; break;
    case 11: if (a >= 0) r = func_002637e8(a) >= 0; break;
    default: r = 1; break;
    }
    return r;
}
}  // namespace n002638e0

// 00263960 (was src/anon/batch_w59.cpp)
namespace n00263960 {
// 0022b898: moved to src/sasa/musical_2d.cpp (linked unit)

// --- 00263960
// Store the parameters, then allocate and construct the 460-byte object.
extern u32 D_0035f0b8 asm("D_0035f0b8");
extern u32 D_0035f0bc asm("D_0035f0bc");
extern u32 D_0035f0c0 asm("D_0035f0c0");
extern u8* D_00347f80 asm("D_00347f80");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_0035f360[] asm("D_0035f360");
extern u32* volatile D_0035f0dc asm("D_0035f0dc");
void func_00263bb0(u32, u32) asm("func_00263bb0");
void func_00239700(u32*) asm("func_00239700");
/*TARGET 00263960*/
void func_00263960(u32 a, u32 b, u32 c, u32 d, u32 e) asm("func_00263960");
void func_00263960(u32 a, u32 b, u32 c, u32 d, u32 e) {  // store_globals_and_init
    D_0035f0b8 = a;
    D_0035f0bc = b;
    D_0035f0c0 = c;
    func_00263bb0(d, e);
    u8* h = *(u8**)(D_00347f80 + 20);
    typedef u32* (*Fn)(u8*, u32, u32);
    u32* o = (**(Fn**)h)(h, 460, 0);
    o[3] = 0;
    o[0] = (u32)D_00347e60;
    func_00239700(o + 6);
    o[102] = 0;
    *(volatile u32*)o = (u32)D_0035f360;
    D_0035f0dc = o;
}
}  // namespace n00263960

// 002639f8 (was src/anon/auto80_199_queue.cpp)
namespace n002639f8 {
/*TARGET 002639f8*/
void func_002639f8(void) asm("_Z13func_002639f8v");
void func_002639f8(void) {
    D_0035f0bc = -1;
    D_0035f0c0 = 0;
    D_0035f0b8 = -1;

    Obj_002639f8* obj = D_0035f0dc;
    if (obj != 0) {
        obj->vtbl->fn10((void*)obj);
        D_0035f0dc = 0;
    }
}
}  // namespace n002639f8

// 00263a58 (was src/anon/batch_w21.cpp)
namespace n00263a58 {
void* func_00192048(s32) asm("func_00192048");
void func_00263a90(void*, u8) asm("func_00263a90");
void Tz_CMenuHelp_Create(s32, bool) asm("_ZN2Tz9CMenuHelp6CreateEib");
/*TARGET 00263a58*/
void Tz_CMenuHelp_Create(s32 i, bool b) asm("_ZN2Tz9CMenuHelp6CreateEib");
void Tz_CMenuHelp_Create(s32 i, bool b) {
    void* p = 0;
    if (i >= 0) p = func_00192048(i);
    func_00263a90(p, b);
}
}  // namespace n00263a58

// 00263a90 (was src/anon/batch_w1828_nsa.cpp)
namespace n00263a90 {
struct S8 { s16 a, b, c, d; };
union US8 { S8 s; u32 u; };
u8 func_00263cc0(void) asm("func_00263cc0");
void func_0028b520(void*, u32, u32, u32, u32, void*, void*, s32, s32, s32) asm("func_0028b520");
u32 func_0023aa18(u32) asm("func_0023aa18");
u32 func_0023aa38(u32) asm("func_0023aa38");
void func_00138c68(void*, u32, u32) asm("func_00138c68");
void func_001395f8(void*) asm("func_001395f8");
void func_00138c10(void*, s32) asm("func_00138c10");
extern u32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035f0bc asm("D_0035f0bc");
extern u32 D_0035f0b8 asm("D_0035f0b8");
extern u32 D_0035f0c0 asm("D_0035f0c0");
extern S8 D_0035f0c8 asm("D_0035f0c8");
extern US8 D_0035f0d0_ asm("D_0035f0d0");
#define D_0035f0d0 D_0035f0d0_.s
union UP { u8* p; u32 u; };
extern UP D_0035f0dc asm("D_0035f0dc");
#define G D_0035f0dc.p
/*TARGET 00263a90*/
void func_00263a90(u32 a0, u8 a1) asm("func_00263a90");
void func_00263a90(u32 a0, u8 a1) {
    if (func_00263cc0() == 0) {
        u32 p1 = D_0035f3d4;
        func_0028b520(G, p1, D_0035f0bc, D_0035f0b8, D_0035f0c0, &D_0035f0c8, &D_0035f0d0, D_0035f0d0.d, -1, 0);
        *(u32*)(G + 0x198) = a0;
        if (a1) {
            u32 h = *(u32*)(G + 0x190);
            u32 x = func_0023aa18(h);
            func_00138c68(G, x, func_0023aa38(h));
        }
        func_001395f8(G);
        return;
    }
    *(u32*)(G + 0x198) = a0;
    if (*(s32*)(G + 0x184) != D_0035f0d0.d) {
        func_00138c10(G, D_0035f0d0.d);
        *(s32*)(G + 0x188) = -1;
    }
}
#undef D_0035f0d0
}  // namespace n00263a90

// 00263bb0 (was src/anon/auto80_199_queue.cpp)
namespace n00263bb0 {
/*TARGET 00263bb0*/
void func_00263bb0(u16* a0, u16* a1) asm("_Z13func_00263bb0PtS_");
void func_00263bb0(u16* a0, u16* a1) {
    for (s32 i = 0; i < 3; i += 1) {
        D_0035f0c8[i] = a0[i];
    }

    for (s32 i = 0; i < 5; i += 1) {
        D_0035f0d0[i] = a1[i];
    }

    if (func_00263cc0() == 0) {
        return;
    }

    func_0028b6f0(D_0035f0dc, (u32)D_0035f0c8);
    func_0028b720(D_0035f0dc, (u32)D_0035f0d0);
}
}  // namespace n00263bb0

// 00263c60 (was src/anon/batch_w46.cpp)
namespace n00263c60 {
// ---- 00263c60
s32 func_00263cc0(void) asm("func_00263cc0");
void func_00138c10(u8*, s32) asm("func_00138c10");
extern s16 D_0035f0d8 asm("D_0035f0d8");
extern u8* D_0035f0dc asm("D_0035f0dc");
/*TARGET 00263c60*/
void func_00263c60(void) asm("func_00263c60");
void func_00263c60(void) {  // sync_global_index_if_changed
    if (func_00263cc0()) {
        s16 v = D_0035f0d8;
        if (*(s32*)(D_0035f0dc + 388) != v) {
            func_00138c10(D_0035f0dc, v);
            *(s32*)(D_0035f0dc + 392) = -1;
        }
    }
}
}  // namespace n00263c60

// 00263cc0 (was src/anon/batch_w42.cpp)
namespace n00263cc0 {
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void menu_help_leave(void) asm("_ZN2Tz9CMenuHelp5LeaveEv");
// 00263cc0
extern u8* D_0035f0dc asm("D_0035f0dc");
extern u8* D_0035f0c0 asm("D_0035f0c0");
/*TARGET 00263cc0*/
u8 func_00263cc0(void) asm("func_00263cc0");
u8 func_00263cc0(void)
{
    if (!D_0035f0dc) return 0;
    if (!u_call4_00139d78(D_0035f0c0) && u_call4_00139d78(D_0035f0dc)) menu_help_leave();
    return u_call4_00139d78(D_0035f0dc);
}
}  // namespace n00263cc0

// 00263d28 (was src/tozawa/cmenu_help.cpp)
namespace Tz { // method 00263d28
u32 func_00263cc0() asm("func_00263cc0");
extern u32 D_0035f0dc asm("D_0035f0dc");
/*TARGET 00263d28*/
void CMenuHelp::Leave() {
    if (func_00263cc0() == 0u) {
        return;
    }
    void* a0 = *(void**)(u32)&D_0035f0dc;
    u32 f = *(u32*)(*(u32*)a0 + 20u);
    ((void (*)(void*))f)(a0);
}
}  // Tz

// 00263d60 (was gap)
namespace n00263d60 {
u8* func_00257770() asm("func_00257770");
s32 func_00139d78(u8*) asm("func_00139d78");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f0dc asm("D_0035f0dc");
s32 func_0028b160(u32, u8*) asm("func_0028b160");
u32 func_00257130() asm("func_00257130");
s32 func_00281f30(u32) asm("func_00281f30");
void func_001a98e8(u8*, s32, s32, u32, s32) asm("func_001a98e8");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
u32 func_0023a918(u8*) asm("func_0023a918");
void func_001a9ae8(u8*, s32, s32, u32) asm("func_001a9ae8");

u32 func_00263d60() asm("func_00263d60");
u32 func_00263d60() { return D_0035f0dc; }

}  // namespace n00263d60

// 00263d70 (was src/anon/batch_w18.cpp)
namespace n00263d70 {
u32 func_00102818(void*, u32, u32, u32, u32) asm("func_00102818");
u8* func_00103eb0(void) asm("func_00103eb0");
void func_00263db0(void) asm("func_00263db0");
/*TARGET 00263d70*/
void func_00263d70(void) asm("func_00263d70");
void func_00263d70(void) {
    func_00102818(*(void**)(func_00103eb0() + 4), 0, 2000, (u32)func_00263db0, 4096);
}
}  // namespace n00263d70

// 00263da8 (was gap)
namespace n00263da8 {
u8* func_00257770() asm("func_00257770");
s32 func_00139d78(u8*) asm("func_00139d78");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f0dc asm("D_0035f0dc");
s32 func_0028b160(u32, u8*) asm("func_0028b160");
u32 func_00257130() asm("func_00257130");
s32 func_00281f30(u32) asm("func_00281f30");
void func_001a98e8(u8*, s32, s32, u32, s32) asm("func_001a98e8");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
u32 func_0023a918(u8*) asm("func_0023a918");
void func_001a9ae8(u8*, s32, s32, u32) asm("func_001a9ae8");

void func_00263da8() asm("func_00263da8");
void func_00263da8() {}

}  // namespace n00263da8

// 00263db0 (was src/anon/auto80_199_queue.cpp)
namespace n00263db0 {
/*TARGET 00263db0*/
void func_00263db0(u32 a0) asm("_Z13func_00263db0j");
void func_00263db0(u32 a0) {
    func_00263ea0(a0);
    func_00102448(a0, 1);
    func_00263e10();

    while (1) {
        if (func_00263e18() != 0) {
            return;
        }
        func_00263e98();
        func_00102448(a0, 0);
    }
}
}  // namespace n00263db0

// 00263e10 (was src/anon/misc_2.cpp)
namespace n00263e10 {
/*TARGET 00263e10*/
// 0x0025f6b0: definition moved into src/anon/unit_0025da20.cpp

void func_00263e10(void* self) asm("_Z13func_00263e10Pv");
// 0x0025f6b0: definition moved into src/anon/unit_0025da20.cpp

void func_00263e10(void* self) {}
}  // namespace n00263e10

// 00263e18 (was src/anon/batch_w57.cpp)
namespace n00263e18 {
extern void (**D_0032b914)() asm("D_0032b914");
u32 func_00138470(void) asm("func_00138470");
u32 func_00138440(void) asm("func_00138440");
void func_001382e0(void) asm("func_001382e0");
u32 func_00287db0(void) asm("func_00287db0");
void func_001039f8(void) asm("func_001039f8");
void func_0017a798(void) asm("func_0017a798");
void func_00287da0(void) asm("func_00287da0");
/*TARGET 00263e18*/
u32 func_00263e18(void) asm("func_00263e18");
u32 func_00263e18(void) {
    if (!func_00138470()) {
        if (!func_00138440()) func_001382e0();
    }
    if (func_00287db0()) {
        func_001039f8();
        return 1;
    }
    if (func_00138470()) {
        func_0017a798();
        func_00287da0();
    }
    return 0;
}
}  // namespace n00263e18

// 00263e98 (was src/anon/misc_2.cpp)
namespace n00263e98 {
/*TARGET 00263e98*/
void func_00263e98(void* self) asm("_Z13func_00263e98Pv");
void func_00263e98(void* self) {}
}  // namespace n00263e98

// 00263ea0 (was src/anon/misc_2.cpp)
namespace n00263ea0 {
/*TARGET 00263ea0*/
void func_00263ea0(void* self) asm("_Z13func_00263ea0Pv");
void func_00263ea0(void* self) {}
}  // namespace n00263ea0

// 00263ea8 (was src/anon/tiny.cpp)
namespace n00263ea8 {
/*TARGET 00263ea8*/
u32 func_00263ea8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00263ea8jjjj");
u32 func_00263ea8(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_36f1d0
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u32*)((u32)b + (-3872)));
}
}  // namespace n00263ea8

// 00263eb8 (was src/anon/tiny_auto80_queue.cpp)
namespace n00263eb8 {
/*TARGET 00263eb8*/
u32 func_00263eb8(void* a0) asm("_Z13func_00263eb8Pv");
u32 func_00263eb8(void* a0) {
    u32 v0 = 0u;
    if (*(u32*)a0 == 0x48535a54u) {
        v0 = (u32)(*(s16*)((u8*)a0 + 4) == 7);
    }
    return v0;
}
}  // namespace n00263eb8

