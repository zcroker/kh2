// Linked unit 0x002853b8-0x00286d28 (one namespace per old matched source; class methods in their own namespace).
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

// 002853b8 (was src/anon/batch_w37.cpp)
namespace n002853b8 {
s32 func_00293fb0(void) asm("func_00293fb0");
u32 func_00103570(void) asm("func_00103570");
void Tz__JmInfo__Init(u32) asm("Tz__JmInfo__Init");
void Tz__JmInfo__SetLeadData(void) asm("Tz__JmInfo__SetLeadData");
void func_00253b30(void*, u32) asm("func_00253b30");
void func_0023fa90(u32, void*) asm("func_0023fa90");
extern u32 D_0035f2bc asm("D_0035f2bc");
extern u32 D_0035f2c4 asm("D_0035f2c4");
/*TARGET 002853b8*/
void func_002853b8(void) asm("func_002853b8");
void func_002853b8(void) {
    u8 buf[128];
    if (!func_00293fb0()) {
        Tz__JmInfo__Init(func_00103570());
        Tz__JmInfo__SetLeadData();
    }
    func_00253b30(buf, D_0035f2bc);
    func_0023fa90(D_0035f2c4, buf);
}
}  // namespace n002853b8

// 00285418 (was src/anon/tiny_auto80_queue.cpp)
namespace n00285418 {
extern u32 D_0035f2bc asm("D_0035f2bc");
void func_00253b30(...) asm("func_00253b30");
void func_00293bd0(...) asm("func_00293bd0");
// 00191c88: moved to src/yasui/libys/status.cpp

extern "C" u32 func_00170518(...) asm("func_00170518");
/*TARGET 00285418*/
void func_00285418() asm("_Z13func_00285418v");
void func_00285418() {
    u8 buf[128];
    func_00293bd0(0u, 0u, 0u);
    func_00253b30(buf, *(u32*)(u32)&D_0035f2bc);
    func_00170518(buf, 5100u, 0u);
}
}  // namespace n00285418

// 00285460 (was src/anon/tiny_auto80_queue.cpp)
namespace n00285460 {
u32 func_00170320(...) asm("func_00170320");
u32 func_0023f900(...) asm("func_0023f900");
u32 func_0023fad0(...) asm("func_0023fad0");
u32 func_00293d80(...) asm("func_00293d80");
u32 func_00293eb0(...) asm("func_00293eb0");
/*TARGET 00285460*/
u32 func_00285460(u32 a0) asm("_Z13func_00285460j");
u32 func_00285460(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = (u32)(0x0036u << 16);
    r4 = *(u32*)((u32)r16 + (s32)(-3388));
    r2 = ((u32(*)(u32))func_0023f900)(r4);
    if (r2 != 0u) {
        r4 = *(u32*)((u32)r16 + (s32)(-3388));
        r2 = ((u32(*)(u32))func_0023fad0)(r4);
    }
    r2 = ((u32(*)())func_00293eb0)();
    r4 = 0u;
    r2 = ((u32(*)(u32))func_00293d80)(r4);
    r4 = (u32)((s32)0u + (5100));
    return ((u32(*)(u32))func_00170320)(r4);
}
}  // namespace n00285460

// 002854b0 (was gap, written for the unit)
namespace n002854b0 {
extern u8 D_0035f2d0 asm("D_0035f2d0");
void func_002854b0(void) asm("func_002854b0");
void func_002854b0(void) {
    D_0035f2d0 = 0;
}
}  // namespace n002854b0

// 002854c0 (was src/anon/tiny_wrappers_more.cpp)
namespace n002854c0 {
u32 func_001d9980(u32, u32, u32, u32) asm("_Z13func_001d9980jjjj");
/*TARGET 002854c0*/
u32 func_002854c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002854c0jjjj");
u32 func_002854c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d9980(a0, a1, a2, a3);
}
}  // namespace n002854c0

// 002854d8 (was src/anon/batch_w297.cpp)
namespace n002854d8 {
struct Sub297 { u8 pad[184]; u32 f; void Set8() { f |= 8; } };
union UP297 { u8* p; u32 u; u8 c; };
extern UP297 D_0035f2d8 asm("D_0035f2d8");
extern UP297 D_0035f2dc asm("D_0035f2dc");
extern s32 D_0035f2c8 asm("D_0035f2c8");
extern u8 D_00374378[] asm("D_00374378");
void func_00139d78(void*) asm("func_00139d78");
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void func_00139620(void*) asm("func_00139620");
s32 func_00192048(void*) asm("func_00192048");
s32 func_0023aa18(void*) asm("func_0023aa18");
s32 func_0023aa38(void*) asm("func_0023aa38");
s32 func_0023aa78(void*) asm("func_0023aa78");
void Tz__CmComm__CreateConfirmSelector(void*, s32, s32, s32, s32, s32, void*) asm("Tz__CmComm__CreateConfirmSelector");
u8* func_002891b8(void*, s32) asm("func_002891b8");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
void func_00288f48(void*, s32, s32, s32, s32) asm("func_00288f48");
void func_0028af28(void*, s32) asm("func_0028af28");
/*TARGET 002854d8*/
void func_002854d8(void* p, u8 flag) asm("func_002854d8");
void func_002854d8(void* p, u8 flag) {
    func_00139d78(D_0035f2d8.p);
    func_0028d980(D_0035f2d8.p, 30013, 0, 0, D_0035f2c8, 4, 5, -1, 0);
    func_00139620(D_0035f2d8.p);
    *(s32*)(D_0035f2d8.p + 432) = 2;
    D_0035f2d8.p[405] = 1;
    ((Sub297*)(D_0035f2d8.p + 24))->Set8();
    u8* q = D_0035f2d8.p;
    *(s32*)(q + 408) = func_00192048(p);
    s32 x = func_0023aa18(D_0035f2d8.p + 24);
    s32 y = func_0023aa38(D_0035f2d8.p + 24);
    s32 n, m;
    if (flag) { m = 1; n = 2; }
    else { m = 0; n = 1; }
    Tz__CmComm__CreateConfirmSelector(D_0035f2dc.p, 30013, 0, 0, D_0035f2c8, m, D_00374378);
    for (s32 i = 0; i < n; i++) {
        func_0028dcc0(func_002891b8(D_0035f2dc.p, i), D_0035f2d8.p);
        s32 w = func_0023aa78(func_002891b8(D_0035f2dc.p, i) + 24);
        func_00138c68(func_002891b8(D_0035f2dc.p, i), x + w * i, y);
        ((Sub297*)(func_002891b8(D_0035f2dc.p, i) + 24))->Set8();
    }
    func_00288f48(D_0035f2dc.p, 128, 64, 0, 0);
    func_0028af28(D_0035f2dc.p, flag ? 64 : 96);
}
}  // namespace n002854d8

// 002856c8 (was src/anon/auto80_199_queue.cpp)
namespace n002856c8 {
/*TARGET 002856c8*/
void func_002856c8(void) asm("_Z13func_002856c8v");
void func_002856c8(void) {
    func_0028dac8(D_0035f2d8, 6);

    if (func_0028acc8(D_0035f2dc) == 0) {
        return;
    }

    if (func_0028acb8(D_0035f2dc) != 0) {
        return;
    }

    func_0028aa40(D_0035f2dc);
}
}  // namespace n002856c8

// 00285728 (was src/anon/tiny_auto80_queue.cpp)
namespace n00285728 {
extern u32 D_0035f2d8 asm("D_0035f2d8");
extern u32 D_0035f2dc asm("D_0035f2dc");
u32 func_0028acc8(...) asm("func_0028acc8");
u32 func_00139d78(...) asm("func_00139d78");
/*TARGET 00285728*/
u32 func_00285728() asm("_Z13func_00285728v");
u32 func_00285728() {
    u32 v0 = func_00139d78((void*)(*(u32*)(u32)&D_0035f2d8));
    if (v0 == 0u) {
        v0 = func_0028acc8(*(u32*)(u32)&D_0035f2dc);
    }
    return v0;
}
}  // namespace n00285728

// 00285760 (was src/anon/batch_w90.cpp)
namespace n00285760 {
// 0x00265ab8: definition moved into src/anon/unit_00265580.cpp

// 00285760
s32 func_00289380(void*) asm("func_00289380");
s32 func_00289310(void*) asm("func_00289310");
s32 func_0028ae28(void*, s32) asm("func_0028ae28");
void func_00138c10(void*, s32) asm("func_00138c10");
void func_0028ab20(void*) asm("func_0028ab20");
void func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
extern void* D_0035f2dc asm("D_0035f2dc");
extern void* D_0035f2d8 asm("D_0035f2d8");
/*TARGET 00285760*/
s32 Tz__Ending__SelCtrl(void) asm("Tz__Ending__SelCtrl");
s32 Tz__Ending__SelCtrl(void)
{
    s32 r = func_00289380(D_0035f2dc);
    if (r != -1 || func_00289310(D_0035f2dc)) {
        if (!func_0028ae28(D_0035f2dc, 0)) {
            func_00138c10(D_0035f2d8, 5);
            func_0028ab20(D_0035f2dc);
        }
    }
    func_00287df0(r, func_00289310(D_0035f2dc), 0, 0, 1);
    switch (r) {
    case 0: case -2: return 0;
    case 1: return 1;
    default: return -1;
    }
}
}  // namespace n00285760

// 00285828 (was src/anon/batch_w1596.cpp)
namespace n00285828 {
// ---- 00285828
struct O285828 { s32 a[20]; s32 b[3]; s32 c[18]; s32 d[9]; s32 e; u8 f[0x11c - 0xcc]; };
extern O285828* volatile D_0035f2e4 asm("D_0035f2e4");
s32 func_00103570() asm("func_00103570");
O285828* func_001063c0(s32, s32) asm("func_001063c0");
void func_00323ad0(void*) asm("func_00323ad0");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
void func_002859c0() asm("func_002859c0");
/*TARGET 00285828*/
void func_00285828() asm("func_00285828");
void func_00285828() {
    s32* p; s32 n;
    O285828* o = func_001063c0(0x11c, func_00103570());
    p = o->a; n = 19; do { *p = 0; n--; p++; } while (n >= 0);
    p = o->b; n = 2; do { *p = 0; n--; p++; } while (n >= 0);
    p = o->c; n = 17; do { *p = 0; n--; p++; } while (n >= 0);
    p = o->d; n = 8; do { *p = 0; n--; p++; } while (n >= 0);
    o->e = 0;
    func_00323ad0(o->f);
    D_0035f2e4 = o;
    func_002fde18(D_0035f2e4, 0, 0x11c);
    func_002859c0();
}
}  // namespace n00285828

// 00285910 (was src/anon/batch_w57.cpp)
namespace n00285910 {
extern void (**D_0032b914)() asm("D_0032b914");
// 0x001c6850: definition moved into src/anon/unit_001c5b90.cpp

// OR the pending bitset (640 bits) into the destination set, then free it.
u32* func_002859a0(void) asm("func_002859a0");
void func_00106420(void*) asm("func_00106420");
extern union { u32* p; u8 c; } D_0035f2e4 asm("D_0035f2e4");
/*TARGET 00285910*/
void func_00285910(void) asm("func_00285910");
void func_00285910(void) {
    u32* dst = func_002859a0();
    s32 i = 0;
    do {
        u8* s = (u8*)D_0035f2e4.p;
        u32 off = ((u32)i >> 5) << 2;
        if (*(u32*)(s + off + 204) & (1 << (i & 31))) *(u32*)((u8*)dst + off) |= 1 << (i & 31);
        i++;
    } while (i < 640);
    if (D_0035f2e4.p) {
        func_00106420(D_0035f2e4.p);
        D_0035f2e4.p = 0;
    }
}
}  // namespace n00285910

// 002859a0 (was src/tozawa/cmenu_newflg.cpp)
namespace Tz { // method 002859a0
u32 getSaveRam() asm("_Z10getSaveRamv");
/*TARGET 002859a0*/
u32 CmNewFlg::GetSram() {
    u32 r2 = getSaveRam();
    r2 = (u32)((s32)r2 + 16808);
    return r2;
}
}  // Tz

// 002859c0 (was src/anon/tiny_auto80_fptr0.cpp)
namespace n002859c0 {
u32 func_002859f0() asm("_Z13func_002859f0v");
u32 func_00285fa0() asm("_Z13func_00285fa0v");
u32 func_00286298() asm("_Z13func_00286298v");
u32 func_00286628() asm("_Z13func_00286628v");
/*TARGET 002859c0*/
u32 func_002859c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002859c0jjjj");
u32 func_002859c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call0_002859f0)() = func_002859f0;
    r2 = fp_call0_002859f0();
    u32 (*fp_call0_00285fa0)() = func_00285fa0;
    r2 = fp_call0_00285fa0();
    u32 (*fp_call0_00286298)() = func_00286298;
    r2 = fp_call0_00286298();
    return func_00286628();
}
}  // namespace n002859c0

// 002859f0 (was src/anon/batch_wcx2.cpp)
namespace n002859f0 {
// 0x001c3150: definition moved into src/anon/unit_001c2b58.cpp

// ---- 002859f0
struct Save285 { u32 seen[51]; u32 fresh[64]; };
// Reloaded after every u32 store in the original (no strict aliasing).
extern union { Save285* p; u32 u; } D_0035f2e4 asm("D_0035f2e4");
u32* func_002859a0(void) asm("func_002859a0");
void* func_001a8bd0_59f0(s32 a) asm("func_001a8bd0");
u32 func_001a8c10(void* p, s32 i) asm("func_001a8c10");
u8* func_001a1658(u32 m, s32 a) asm("func_001a1658");
// state_dispatch_0_1_14
void YS__SHEET__Free(u8* c) asm("YS__SHEET__Free");
u32 func_00281420(void) asm("func_00281420");
u32 func_002814b0(s32 i) asm("func_002814b0");
u16* func_001a8110(u16* it) asm("func_001a8110");
s32 func_00285d18(u8 a) asm("func_00285d18");
s32 func_001a3570_59f0(u16 id) asm("func_001a3570");
void ucall_2859f0(void) asm("_Z16u_call0_002859f0v");
static inline void MarkFresh(u32* have, u32 id) {
    if (id && !(have[id >> 5] & (1 << (id & 31)))) {
        u32* f = D_0035f2e4.p->fresh;
        f += id >> 5;
        *f |= 1 << (id & 31);
    }
}
static inline void MarkSeen(u32* have, u32 id) {
    if (!(have[id >> 5] & (1 << (id & 31)))) {
        u32* f = D_0035f2e4.p->seen;
        f += id >> 5;
        *f |= 1 << (id & 31);
    }
}
/*TARGET 002859f0*/
// Flag equipment/items the player now holds that were not owned before.
void ucall_2859f0(void) asm("_Z16u_call0_002859f0v");
// Flag equipment/items the player now holds that were not owned before.
void ucall_2859f0(void) {
    s32 i;
    u16* it = 0;
    u32* have = func_002859a0();
    void* party = func_001a8bd0_59f0(-1);
    for (i = 0; i < 4; i++) {
        u32 m = func_001a8c10(party, i);
        if (!m) continue;
        u8* c = func_001a1658(m, -1);  // state_dispatch_0_1_14
        u16* eq = *(u16**)(c + 580);
        s32 k;
        for (k = 0; k < 2; k++) MarkFresh(have, eq[k]);
        for (k = 0; k < 8; k++) MarkFresh(have, eq[10 + k]);
        for (k = 0; k < 8; k++) MarkFresh(have, eq[18 + k]);
        for (k = 0; k < 8; k++) MarkFresh(have, eq[26 + k]);
        YS__SHEET__Free(c);
    }
    s32 mask = func_00281420();
    for (i = 0; i < 7; i++) {
        if ((mask >> i) & 1) MarkFresh(have, func_002814b0(i));
    }
    for (;;) {
        it = func_001a8110(it);
        if (!it) break;
        if (!func_00285d18(((u8*)it)[2])) continue;
        if (!func_001a3570_59f0(it[0])) continue;
        MarkSeen(have, it[0]);
    }
}
}  // namespace n002859f0

// 00285d18 (was src/anon/batch_w1588.cpp)
namespace n00285d18 {
extern s8 D_003743c0[] asm("D_003743c0");
/*TARGET 00285d18*/
// 0x00264388: definition moved into src/anon/unit_002640a8.cpp

s32 func_00285d18(s32 x) asm("func_00285d18");
// 0x00264388: definition moved into src/anon/unit_002640a8.cpp

s32 func_00285d18(s32 x) {  // byte_list_contains
    s32 r = 0;
    s32 i;
    for (i = 0; D_003743c0[i] >= 0; i++) {
        if (D_003743c0[i] == x) {
            r = 1;
            break;
        }
    }
    return r;
}
}  // namespace n00285d18

// 00285d58 (was src/anon/batch_w86.cpp)
namespace n00285d58 {
struct Rec { u8 f0, f1, kind; };
extern u32* D_0035f2e4 asm("D_0035f2e4");
Rec* func_001a80c8(s32) asm("func_001a80c8");
// table24_find_by_id
s32 func_00285d18(u8) asm("func_00285d18");
/*TARGET 00285d58*/
s32 func_00285d58(s32 id) asm("func_00285d58");
s32 func_00285d58(s32 id)
{
    s32 r = 0;
    if (id >= 0) {
        r = (D_0035f2e4[(u32)id >> 5] & (1 << (id & 31))) != 0;
    } else {
        for (s32 i = 0; i < 640; i++) {
            if (!(D_0035f2e4[(u32)i >> 5] & (1 << (i & 31)))) continue;
            if (func_00285d18(func_001a80c8(i)->kind)) { r = 1; break; }
        }
    }
    return r;
}
}  // namespace n00285d58

// 00285e30 (was src/anon/batch_w98.cpp)
namespace n00285e30 {
extern u32* D_0035f2e4 asm("D_0035f2e4");
u32* func_002859a0(void) asm("func_002859a0");
u8* func_001a80c8(s32) asm("func_001a80c8");
// table24_find_by_id
s32 func_00285d18(u8) asm("func_00285d18");
static inline u32 Bit285(u32* a, s32 i) { return a[(u32)i >> 5] & (1 << (i & 31)); }
/*TARGET 00285e30*/
// True when the id (or, for id < 0, every enabled id that qualifies) is also set in the obtained mask.
s32 func_00285e30(s32 id) asm("func_00285e30");
// True when the id (or, for id < 0, every enabled id that qualifies) is also set in the obtained mask.
s32 func_00285e30(s32 id) {
    s32 ok = 1;
    u32* got = func_002859a0();
    if (id >= 0) {
        ok = Bit285(D_0035f2e4, id) && Bit285(got, id);
    } else {
        for (s32 i = 0; i < 640; i++) {
            if (!Bit285(D_0035f2e4, i)) continue;
            if (!func_00285d18(func_001a80c8(i)[2])) continue;
            ok = Bit285(got, i) != 0;
            if (!ok) break;
        }
    }
    return ok;
}
}  // namespace n00285e30

// 00285f50 (was src/anon/batch_w35.cpp)
namespace n00285f50 {
// Sets bit `i` in the bitset returned by func_002859a0 (if not already set).
extern "C" u32* func_002859a0(void) asm("func_002859a0");
/*TARGET 00285f50*/
void func_00285f50(void* a) asm("_Z13func_00285f50Pv");
void func_00285f50(void* a) {
    u32 i = (u32)a;
    u32* bits = func_002859a0();
    u32* w = (u32*)((i >> 5) * 4 + (u32)bits);
    u32 m = 1 << (i & 31);
    if (!(*w & m)) *w |= m;
}
}  // namespace n00285f50

// 00285fa0 (was src/anon/batch_w67.cpp)
namespace n00285fa0 {
// 0x2ca320: moved to src/anon/unit_002ca0e0.cpp


u32* func_002859a0(void) asm("func_002859a0");
u8* func_001a8110(u8*) asm("func_001a8110");
s32 func_00286058(u8) asm("func_00286058");
s32 func_001a3570(u16) asm("func_001a3570");
extern u32* D_0035f2e4 asm("D_0035f2e4");
/*TARGET 00285fa0*/
// 00285fa0
void u_call0_00285fa0(void) asm("_Z16u_call0_00285fa0v");
// 00285fa0
void u_call0_00285fa0(void)
{
    u8* e = 0;
    u32* bits = func_002859a0();
    for (;;) {
        e = func_001a8110(e);
        if (!e) break;
        if (!func_00286058(e[2])) continue;
        if (!func_001a3570(*(u16*)e)) continue;
        u16 id = *(u16*)e;
        u32 m = 1 << (id & 31);
        u32 off = id >> 5;
        if (bits[off] & m) continue;
        u32* d = D_0035f2e4;
        d += off;
        *d |= m;
    }
}
}  // namespace n00285fa0

// 00286058 (was src/anon/misc_2.cpp)
namespace n00286058 {
/*TARGET 00286058*/
s64 func_00286058(s64 param0, s64 param1, s64 param2, s64 param3) asm("_Z13func_00286058xxxx");
s64 func_00286058(s64 param0, s64 param1, s64 param2, s64 param3) {
    s64 result = 0, arg0 = param0, arg1 = param1, arg2 = param2, arg3 = param3, returnAddr = 0;
    arg0 = (s64)((u64)arg0 ^ 0x0012);
    arg0 = ((u64)arg0 < (u64)((s64)1)) ? 1 : 0;
    result = arg0 + 0;
    return result;
}
}  // namespace n00286058

// 00286068 (was src/anon/batch_w82.cpp)
namespace n00286068 {
u8* func_001a80c8(u32) asm("func_001a80c8");
extern u32* D_0035f2e4 asm("D_0035f2e4");
s32 func_00286058(u8) asm("func_00286058");
static inline s32 Bit0028(s32 i) { return (D_0035f2e4[(u32)i >> 5] & (1 << (i & 31))) != 0; }
/*TARGET 00286068*/
// id >= 0: whether item id is flagged and usable; id < 0: whether any of the 640 is.
s32 func_00286068(s32 id) asm("func_00286068");
// id >= 0: whether item id is flagged and usable; id < 0: whether any of the 640 is.
s32 func_00286068(s32 id)
{
    s32 r = 0;
    if (id >= 0) {
        if (id != 0 && func_00286058(func_001a80c8(id)[2])) r = Bit0028(id);
    } else {
        s32 i;
        for (i = 0; i < 640; i++) {
            if (Bit0028(i) && func_00286058(func_001a80c8(i)[2])) {
                r = 1;
                break;
            }
        }
    }
    return r;
}
}  // namespace n00286068

// 00286160 (was src/anon/batch_w99.cpp)
namespace n00286160 {
extern u32* D_0035f2e4 asm("D_0035f2e4");
u32* func_002859a0(void) asm("func_002859a0");
u8* func_001a80c8(s32) asm("func_001a80c8");
// table24_find_by_id
s32 func_00286058(u8) asm("func_00286058");
static inline s32 Check286(u32* got, u32 i)
{
    u32 m = 1 << (i & 31);
    if (!(D_0035f2e4[i >> 5] & m)) return 0;
    return (got[i >> 5] & m) != 0;
}
/*TARGET 00286160*/
s32 func_00286160(s32 id) asm("func_00286160");
s32 func_00286160(s32 id)
{
    s32 r = 1;
    u32* got = func_002859a0();
    s32 i;
    if (id >= 0) {
        r = Check286(got, id);
    } else {
    for (i = 0; i < 640; i++) {
        if (!(D_0035f2e4[(u32)i >> 5] & (1 << ((u32)i & 31)))) continue;
        if (!func_00286058(func_001a80c8(i)[2])) continue;
        r = (got[(u32)i >> 5] & (1 << ((u32)i & 31))) != 0;
        if (!r) break;
    }
    }
    return r;
}
}  // namespace n00286160

// 00286280 (was src/anon/tiny.cpp)
namespace n00286280 {
void func_00285f50(void*) asm("_Z13func_00285f50Pv");
/*TARGET 00286280*/
void func_00286280(BD_VALUE* bd) asm("_Z13func_00286280P8BD_VALUE");
void func_00286280(BD_VALUE* bd) { func_00285f50(bd); }
}  // namespace n00286280

// 00286298 (was src/anon/batch_w8004.cpp)
namespace n00286298 {
// 0028f878: moved to src/anon/unit_0028f1e0.cpp

// ---- 00286298
struct Bits_w8004 {
    u32 w[2];
    s32 Test(u32 b) { return w[b >> 5] & (1 << (b & 31)); }
    void Set(u32 b) { u32* p = &w[b >> 5]; *p |= 1 << (b & 31); }
};
struct BitsC8_w8004 { u8 pad[0xc8]; Bits_w8004 bits; };
struct BitsCC_w8004 { u8 pad[0xcc]; Bits_w8004 bits; };
extern BitsC8_w8004* D_0035f2e4 asm("D_0035f2e4");
extern s16 D_003743d8[] asm("D_003743d8");
extern s16 D_003743e8[] asm("D_003743e8");
BitsCC_w8004* func_002859a0(void) asm("func_002859a0");
s32 func_001a3570(s32) asm("func_001a3570");
s32 func_001a36e0(s32) asm("func_001a36e0");
void u_call0_00286298(void) asm("_Z16u_call0_00286298v");
/*TARGET 00286298*/
// Separate counters per loop give each loop its own PRE copy of i*2.
void u_call0_00286298(void) asm("_Z16u_call0_00286298v");
// Separate counters per loop give each loop its own PRE copy of i*2.
void u_call0_00286298(void)
{
    u32 i = 0;
    BitsCC_w8004* cur = func_002859a0();
    for (; D_003743d8[i] >= 0; i++) {
        if (func_001a3570(func_001a36e0(D_003743d8[i])) && !cur->bits.Test(i)) D_0035f2e4->bits.Set(i);
    }
    for (u32 j = 0; D_003743e8[j] >= 0; j++) {
        if (func_001a3570(D_003743e8[j]) && !cur->bits.Test(j + 5)) D_0035f2e4->bits.Set(j + 5);
    }
}
}  // namespace n00286298

// 00286418 (was src/anon/batch_w87.cpp)
namespace n00286418 {
// ---- 0x286418 / 0x2864f8: flag-bit queries ----
struct Flags { u8 pad[200]; u32 bits[2]; };
extern Flags* D_0035f2e4 asm("D_0035f2e4");
s32 func_002812e0(void) asm("func_002812e0");
/*TARGET 00286418*/
s32 Tz__CmNewFlg__isStatNew(s32 n) asm("Tz__CmNewFlg__isStatNew");
s32 Tz__CmNewFlg__isStatNew(s32 n) {
    s32 r;
    if (n >= 0) {
        u32* w = &D_0035f2e4->bits[(u32)n >> 5];
        r = (*w & (1 << (n & 31))) != 0;
        if (func_002812e0() && n < 5) r = 0;
    } else {
        for (s32 i = 0; i < 9; i++) {
            u32* w = &D_0035f2e4->bits[(u32)i >> 5];
            r = (*w & (1 << (i & 31))) != 0;
            if (func_002812e0() && i < 5) r = 0;
            if (r) break;
        }
    }
    return r;
}
}  // namespace n00286418

// 002864f8 (was src/anon/batch_w87.cpp)
namespace n002864f8 {
// ---- 0x286418 / 0x2864f8: flag-bit queries ----
struct Flags { u8 pad[200]; u32 bits[2]; };
struct Flags2 { u8 pad[204]; u32 bits[2]; };
extern Flags* D_0035f2e4 asm("D_0035f2e4");
Flags2* func_002859a0(void) asm("func_002859a0");
/*TARGET 002864f8*/
s32 func_002864f8(s32 n) asm("func_002864f8");
s32 func_002864f8(s32 n) {
    Flags2* t = func_002859a0();
    s32 r = 1;
    if (n >= 0) {
        u32 m = 1 << (n & 31);
        u32 w = (u32)n >> 5;
        s32 res = 0;
        u32* pa = &D_0035f2e4->bits[w];
        if (*pa & m) { u32* pb = &t->bits[w]; res = (*pb & m) != 0; }
        return res;
    }
    u32* db = D_0035f2e4->bits;
    u32* tb = t->bits;
    for (s32 i = 0; i < 9; i++) {
        u32 m = 1 << (i & 31);
        if (db[(u32)i >> 5] & m) {
            r = (tb[(u32)i >> 5] & m) != 0;
            if (!r) return r;
        }
    }
    return r;
}
}  // namespace n002864f8

// 002865d0 (was src/anon/batch_w63.cpp)
namespace n002865d0 {
u8* func_002859a0(void) asm("func_002859a0");
/*TARGET 002865d0*/
// 0x00262208: definition moved into src/anon/unit_0025f6b8.cpp

// Sets a bit in the flag array at +204 if not already set.
void func_002865d0(u32 bit) asm("func_002865d0");
// 0x00262208: definition moved into src/anon/unit_0025f6b8.cpp

// Sets a bit in the flag array at +204 if not already set.
void func_002865d0(u32 bit) {
    u32* a = (u32*)(func_002859a0() + 204);
    u32 i = bit >> 5;
    u32 m = 1 << (bit & 31);
    if (!(a[i] & m)) a[i] |= m;
}
}  // namespace n002865d0

// 00286628 (was src/anon/batch_w3802_nsa.cpp)
namespace n00286628 {
struct W1716Sram {
    u8 pad[0x50];
    u32 bits0[3];
    u32 bits1[18];
    u32 bits2[11];
    u16 list0[80];
    u16 list1[12][48];
    u16 list2[6][48];
};
struct W1716Tbl { u32 hdr; u16 ids[80]; };
struct W1716SrcA { u8 pad[0x50]; W1716Tbl tbl; };
struct W1716SrcB { u8 pad[8]; u16 ids[80]; };
extern W1716Sram* D_0035f2e4 asm("D_0035f2e4");
W1716Sram* W1716_GetSram(void) asm("_ZN2Tz8CmNewFlg7GetSramEv");
u8* W1716_getSaveRam(void) asm("_Z10getSaveRamv");
W1716SrcA* W1716_ctarget_00188fe0(void*, s32) asm("_Z31YS__SAVERAM_BATTLE__get_partramjjjj");
W1716SrcB* W1716_ctarget_00189200(void*, s32) asm("_Z31YS__SAVERAM_BATTLE__get_formramjjjj");
static inline u32 W1716Test(u32* bits, u32 id) { return bits[id >> 5] & (1 << (id & 31)); }
static inline u32* W1716Bits(W1716Sram* s, s32 grp) {
    if (grp == 0) return s->bits0;
    if (grp == 1) return s->bits1;
    return s->bits2;
}
static inline void W1716MarkNew(W1716Sram* s, s32 grp, u32 bit) {
    if (W1716Test(W1716Bits(s, grp), bit) == 0) {
        u32* f = W1716Bits(D_0035f2e4, grp);
        f += bit >> 5;
        *f |= 1 << (bit & 31);
    }
}
// Tz::CmNewFlg: refresh the "new" flag lists in the save RAM (list0, 12 x list1, 6 x list2)
// from the current item tables and mark ids that changed.
void u_tail0_00286628(void) asm("_Z16u_tail0_00286628v");
/*TARGET 00286628*/
void u_tail0_00286628(void) asm("_Z16u_tail0_00286628v");
void u_tail0_00286628(void) {
    s32 n, i, j, k, count, found;
    u32 bit;
    // id is pinned to t3: without the pin global-alloc gives it t1 and the k<count test t3.
    register u32 id asm("$11"); u16 idt;
    W1716Sram* s;
    W1716SrcA* a;
    W1716SrcB* b;
    s = W1716_GetSram();
    for (count = 0; s->list0[count] != 0 && count < 80; count++) {
    }
    a = W1716_ctarget_00188fe0(W1716_getSaveRam() + 0x24f0, 1);
    if (count < 80) {
        for (j = 0; (a->tbl.ids[j] & 0x7fff) && j < 80; j++) {
            if (count >= 80) break;
            idt = a->tbl.ids[j] & 0x7fff; id = idt;
            for (k = 0; k < count; k++) {
                if (s->list0[k] == id) break;
            }
            if (k >= count) { s->list0[count] = id; count++; }
        }
        for (j = 0; j < count; j++) {
            W1716MarkNew(s, 0, j);
        }
    }
    for (j = 0; j < count; j++) {
        bit = j;
        found = 0;
        for (k = 0; (a->tbl.ids[k] & 0x7fff) && k < 80; k++) {
            if (s->list0[j] == (a->tbl.ids[k] & 0x7fff)) {
                found = 1;
                break;
            }
        }
        if (!found) {
            if (W1716Test(s->bits0, bit) == 0) {
                u32* h = s->bits0;
                h += bit >> 5;
                *h |= 1 << (bit & 31);
            }
        }
    }

    for (n = 2, i = 0; n < 14; n++, i++) {
        count = 0;
        for (k = 0; k < 48; k++) {
            if (s->list1[i][k] == 0) break;
            count++;
        }
        a = W1716_ctarget_00188fe0(W1716_getSaveRam() + 0x24f0, n);
        if (count < 48) {
            for (j = 0; (a->tbl.ids[j] & 0x7fff) && j < 80; j++) {
                if (count >= 48) break;
                idt = a->tbl.ids[j] & 0x7fff; id = idt;
                for (k = 0; k < count; k++) {
                if (s->list1[i][k] == id) break;
            }
                if (k >= count) { bit = i * 48 + count; s->list1[0][bit] = id; count = -~count; }
            }
            for (j = 0; j < count; j++) {
                bit = i * 48 + j; W1716MarkNew(s, 1, bit);
            }
        }
        for (j = 0; j < count; j++) {
            bit = i * 48 + j;
            found = 0;
            for (k = 0; (a->tbl.ids[k] & 0x7fff) && k < 80; k++) {
                if (s->list1[i][j] == (a->tbl.ids[k] & 0x7fff)) {
                    found = 1;
                    break;
                }
            }
            if (!found) {

                if (W1716Test(s->bits1, bit) == 0) {
                    u32* h = s->bits1;
                    h += bit >> 5;
                    *h |= 1 << (bit & 31);
                }
            }
        }
    }

    for (n = 1, i = 0; n < 8; n++, i++) {
        if (n == 6) {
            i--;
            continue;
        }
        count = 0;
        for (k = 0; k < 48; k++) {
            if (s->list2[i][k] == 0) break;
            count++;
        }
        b = W1716_ctarget_00189200(W1716_getSaveRam() + 0x24f0, n);
        if (count < 48) {
            for (j = 0; (b->ids[j] & 0x7fff) && j < 24; j++) {
                if (count >= 48) break;
                idt = b->ids[j] & 0x7fff; id = idt;
                for (k = 0; k < count; k++) {
                if (s->list2[i][k] == id) break;
            }
                if (k >= count) { bit = i * 48 + count; s->list2[0][bit] = id; count = -~count; }
            }
            for (j = 0; j < count; j++) {
                bit = i * 48 + j; W1716MarkNew(s, 2, bit);
            }
        }
        for (j = 0; j < count; j++) {
            bit = i * 48 + j;
            found = 0;
            for (k = 0; (b->ids[k] & 0x7fff) && k < 80; k++) {
                if (s->list2[i][j] == (b->ids[k] & 0x7fff)) {
                    found = 1;
                    break;
                }
            }
            if (!found) {

                if (W1716Test(s->bits2, bit) == 0) {
                    u32* h = s->bits2;
                    h += bit >> 5;
                    *h |= 1 << (bit & 31);
                }
            }
        }
    }
}
}  // namespace n00286628

