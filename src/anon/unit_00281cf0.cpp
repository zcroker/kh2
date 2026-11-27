// Linked unit 0x00281cf0-0x002823b0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/gumi_pause.hpp"
#include "../tozawa/cmenu_config.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tz/ui_accessors.hpp"
#include "../tozawa/item_info.hpp"
#include "../tozawa/multi_seq.hpp"
#include "../tozawa/party_info.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/chg_member.hpp"

// 00281cf0 (was src/anon/batch_w209.cpp)
namespace n00281cf0 {
// --- 00281cf0
extern void func_00281b30(u32) asm("func_00281b30");
extern u8 D_0035f298 asm("D_0035f298");
extern f32 D_0035f294 asm("D_0035f294");
extern u16 D_0035f280 asm("D_0035f280");
/*TARGET 00281cf0*/
void func_00281cf0(u32 a) asm("func_00281cf0");
void func_00281cf0(u32 a) {
    D_0035f294 = 15.0f;
    D_0035f298 = 0;
    func_00281b30(a);
    D_0035f280 = a;
}
}  // namespace n00281cf0

// 00281d38 (was gap, written for the unit)
namespace n00281d38 {
extern s16 D_0035f280 asm("D_0035f280");
s16 func_00281d38(void) asm("func_00281d38");
s16 func_00281d38(void) {
    return D_0035f280;
}
}  // namespace n00281d38

// 00281d48 (was src/anon/batch_w85.cpp)
namespace n00281d48 {
extern f32 D_0035f294 asm("D_0035f294");
extern f32 D_00349e10 asm("D_00349e10");
extern u8 D_0035f298 asm("D_0035f298");
struct Snd281 { s16 id; };
extern Snd281 D_0035f280 asm("D_0035f280");
double func_00313b80(f32) asm("func_00313b80");
// float_to_double
s32 func_003142e0(double, double) asm("func_003142e0");
// double_compare
s32 func_001688b8(void) asm("func_001688b8");
s32 func_00292a90(s16) asm("func_00292a90");
void func_00292b40(Snd281*, s32) asm("func_00292b40");
/*TARGET 00281d48*/
void func_00281d48(void) asm("func_00281d48");
void func_00281d48(void) {
    if (D_0035f294 <= 0.0f) return;
    if (0.0f < D_0035f294) D_0035f294 = D_0035f294 - D_00349e10;
    if (func_003142e0(func_00313b80(D_0035f294), 0.0) < 0) D_0035f294 = 0.0f;
    if (func_003142e0(func_00313b80(D_0035f294), 0.0) > 0) return;
    if (func_001688b8()) return;
    if (!func_00292a90(D_0035f280.id)) func_00292b40(&D_0035f280, 1);
    D_0035f298 = 1;
}
}  // namespace n00281d48

// 00281e20 (was src/anon/tiny_auto80_queue.cpp)
namespace n00281e20 {
extern u16 D_0035f280 asm("D_0035f280");
extern u8  D_0035f298 asm("D_0035f298");
void Tz__ItemPicDraw__Create(...) asm("Tz__ItemPicDraw__Create");
u32 func_00292a90(...) asm("func_00292a90");
/*TARGET 00281e20*/
void func_00281e20() asm("_Z13func_00281e20v");
void func_00281e20() {
    if (*(u8*)(u32)&D_0035f298 != 0u) {
        if (func_00292a90((u32)(s32)(*(s16*)(u32)&D_0035f280)) != 0u) {
            Tz__ItemPicDraw__Create((u32)(s32)(*(s16*)(u32)&D_0035f280));
            *(u8*)(u32)&D_0035f298 = 0u;
        }
    }
}
}  // namespace n00281e20

// 00281e70 (was src/anon/batch_w3.cpp)
namespace n00281e70 {
extern u32 D_0035f28c asm("D_0035f28c");
extern u8 D_0035f299 asm("D_0035f299");
/*TARGET 00281e70*/
void func_00281e70(u32 a) asm("func_00281e70");
void func_00281e70(u32 a) {  // store_global_and_clear_flag
    D_0035f28c = a;
    D_0035f299 = 0;
}
}  // namespace n00281e70

// 00281e88 (was src/anon/batch_w23.cpp)
namespace n00281e88 {
void func_00281f40(void*, s32) asm("func_00281f40");
void func_00281f48(void*) asm("func_00281f48");
// memset_1920
void func_00281f70(void*) asm("func_00281f70");
void func_00281f90(void*) asm("func_00281f90");
/*TARGET 00281e88*/
void func_00281e88(void* p) asm("func_00281e88");
void func_00281e88(void* p) {
    func_00281f40(p, 0);
    func_00281f48(p);  // memset_1920
    func_00281f70(p);
    func_00281f90(p);
}
}  // namespace n00281e88

// 00281ec8 (was src/anon/batch_w11.cpp)
namespace n00281ec8 {
void func_00281f40(void*, s32) asm("func_00281f40");
void func_00281f48(void*) asm("func_00281f48");
// memset_1920
void func_00281f70(void*) asm("func_00281f70");
void func_00281f90(void*) asm("func_00281f90");
/*TARGET 00281ec8*/
void func_00281ec8(void* p) asm("func_00281ec8");
void func_00281ec8(void* p) {
    func_00281f40(p, 0);
    func_00281f48(p);  // memset_1920
    func_00281f70(p);
    func_00281f90(p);
}
}  // namespace n00281ec8

// 00281f08 (was gap, written for the unit)
namespace n00281f08 {
void func_00281f08(void) asm("func_00281f08");
void func_00281f08(void) {
}
}  // namespace n00281f08

// 00281f10 (was src/anon/misc_2.cpp)
namespace n00281f10 {
/*TARGET 00281f10*/
// 0x00263ea0: definition moved into src/anon/unit_002632d0.cpp

void func_00281f10(void* self) asm("_Z13func_00281f10Pv");
// 0x00263ea0: definition moved into src/anon/unit_002632d0.cpp

void func_00281f10(void* self) {}
}  // namespace n00281f10

// 00281f18 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 00281f18
/*TARGET 00281f18*/
s32 ItemInfo::GetInfoMax() { return reinterpret_cast<ItemInfoLayout*>(this)->infoMax; }
}  // Tz

// 00281f20 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 00281f20
/*TARGET 00281f20*/
void* ItemInfo::GetInfo() { return reinterpret_cast<void*>((char*)this + 4); }
}  // Tz

// 00281f30 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 00281f30
/*TARGET 00281f30*/
void* ItemInfo::GetMsgTbl() { return reinterpret_cast<void*>((char*)this + 1540); }
}  // Tz

// 00281f40 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 00281f40
/*TARGET 00281f40*/
void ItemInfo::SetPartyInfo(PartyInfo* v) {
    reinterpret_cast<ItemInfoLayout*>(this)->partyInfo = v;
}
}  // Tz

// 00281f48 (was src/anon/tiny_wrappers_more.cpp)
namespace n00281f48 {
u32 func_002fde18(u32, u32, u32, u32) asm("_Z13func_002fde18jjjj");
/*TARGET 00281f48*/
u32 func_00281f48(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00281f48jjjj");
u32 func_00281f48(u32 a0, u32 a1, u32 a2, u32 a3) {  // memset_1920
    *(u32*)((u32)(a0) + 0u) = (u32)(0x00000000u);
    return func_002fde18(((u32)(a0) + 4u), 0x00000000u, 0x00000780u, a3);
}
}  // namespace n00281f48

// 00281f70 (was src/anon/tiny_wrappers_more.cpp)
namespace n00281f70 {
u32 func_002fde18(u32, u32, u32, u32) asm("_Z13func_002fde18jjjj");
/*TARGET 00281f70*/
u32 func_00281f70(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00281f70jjjj");
u32 func_00281f70(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002fde18(((u32)(a0) + 1540u), 0x00000000u, 0x00000a00u, a3);
}
}  // namespace n00281f70

// 00281f90 (was src/anon/batch_w31.cpp)
namespace n00281f90 {
// 0x002594b8: definition moved into src/anon/unit_002588e8.cpp

void* memset_(void*, int, u32) asm("func_002fde18");
/*TARGET 00281f90*/
void func_00281f90(u8* p) asm("func_00281f90");
void func_00281f90(u8* p) {
    *(s32*)(p + 4104) = -1;
    *(s32*)(p + 4108) = -1;
    u32* q = (u32*)(p + 4112);
    for (s32 i = 4; i >= 0; i--) *q++ = 0;
    memset_(p + 4132, 0, 64);
}
}  // namespace n00281f90

// 00281fe0 (was src/anon/batch_w322.cpp)
namespace n00281fe0 {
struct W322Pr { s8 a; s8 b; };
extern W322Pr D_003741b0[] asm("D_003741b0");
s32 func_002811f8(u32, s32) asm("func_002811f8");
// find_halfword_index
s32 func_002811b0(u32, s32) asm("func_002811b0");
/*TARGET 00281fe0*/
u32 Tz__ItemInfo__GetItemTypeMask(u8* o, s32 a1, s32 m) asm("Tz__ItemInfo__GetItemTypeMask");
u32 Tz__ItemInfo__GetItemTypeMask(u8* o, s32 a1, s32 m) {
    u32 r = 0; s32 i;
    if (m == 1 || m == 11 || m == 0) {
        if (a1 == 0) {
            for (i = 0; D_003741b0[i].a >= 0; i++) r |= 1 << D_003741b0[i].b;
        } else {
            s32 v = func_002811f8(*(u32*)(o + 4100), a1 < 5 ? a1 - 1 : a1 - 5);  // find_halfword_index
            v = func_002811b0(*(u32*)(o + 4100), v);
            for (i = 0; D_003741b0[i].a >= 0; i++) {
                if (D_003741b0[i].a == v) { r = 1 << D_003741b0[i].b; break; }
            }
        }
    }
    if (m == 2 || m == 0) r |= 0x4000;
    if (m == 3 || m == 0) r |= 0x8000;
    if (m == 4 || m == 0 || m == 10) r |= 1;
    if (m == 5 || m == 0) r |= 2;
    if (m == 6 || m == 0) r |= 0x10000;
    if (m == 7 || m == 0) r |= 0x20000;
    if (m == 8 || m == 0) r |= 0x100000;
    if (m == 9 || m == 10) r |= 0x40000;
    if (m == 12 || m == 0) r |= 0xc000;
    if (m == 13 || m == 0) r |= 3;
    if (m == 14 || m == 0) { r |= 0x20000; r |= 0x10000; r |= 0x100000; }
    return r;
}
}  // namespace n00281fe0

// 00282228 (was src/anon/auto200_999.cpp)
namespace n00282228 {
/*TARGET 00282228*/
u32 func_00282228(u32 a0, u32 a1, u32 a2) asm("_Z13func_00282228jjj");
u32 func_00282228(u32 a0, u32 a1, u32 a2) {  // bit_test_idx
    u32 mask = 1;
    mask <<= a1;
    a2 &= mask;
    a2 = (u32)(0 < a2);
    return a2;
}
}  // namespace n00282228

// 00282240 (was src/anon/batch_w1590.cpp)
namespace n00282240 {
void func_00281f48(s32, s32, s32) asm("func_00281f48");
s32 Tz__ItemInfo__GetItemTypeMask(s32, s32, s32) asm("Tz__ItemInfo__GetItemTypeMask");
void func_002822c0(s32, s32, s32) asm("func_002822c0");
void Tz__ItemInfo__SetEquip(s32, s32, s32) asm("Tz__ItemInfo__SetEquip");
/*TARGET 00282240*/
// 0x002589b0: definition moved into src/anon/unit_002588e8.cpp

void func_00282240(s32 a, s32 b, s32 c) asm("func_00282240");
// 0x002589b0: definition moved into src/anon/unit_002588e8.cpp

void func_00282240(s32 a, s32 b, s32 c) {
    s32 r;
    func_00281f48(a, b, c);
    r = Tz__ItemInfo__GetItemTypeMask(a, b, c);
    if (b < 5) {
        func_002822c0(a, b, r);
    } else {
        Tz__ItemInfo__SetEquip(a, b, r);
    }
}
}  // namespace n00282240

// 002822c0 (was src/anon/batch_w1596.cpp)
namespace n002822c0 {
// 0x00285828: definition moved into src/anon/unit_002853b8.cpp

// ---- 002822c0
struct E2822c0 { u16 id; u8 kind; u8 z; s16 v; };
struct L2822c0 { union { s32 n; s16 nh; }; E2822c0 e[682]; s32 pad; s32 h; s32 m; s32 sel; };
void func_00281f90(L2822c0*) asm("func_00281f90");
s32 func_002811f8(s32, s32) asm("func_002811f8");
u16* func_001a8110(u16*) asm("func_001a8110");
s32 func_00282228(L2822c0*, u8, s32) asm("func_00282228");
u8 func_001a3570(u16) asm("func_001a3570");
s32 func_00282ec0(u16) asm("func_00282ec0");
/*TARGET 002822c0*/
void func_002822c0(L2822c0* l, s32 a1, s32 a2) asm("func_002822c0");
void func_002822c0(L2822c0* l, s32 a1, s32 a2) {
    u16* it = 0;
    E2822c0* e = l->e;
    func_00281f90(l);
    l->m = 0;
    if (a1) l->sel = func_002811f8(l->h, a1 - 1);
    l->n = 0;
    for (;;) {
        it = func_001a8110(it);
        if (!it) break;
        if (!func_00282228(l, ((u8*)it)[2], a2)) continue;
        u8 k = func_001a3570(it[0]);
        if (!k) continue;
        if (func_00282ec0(it[0])) continue;
        e->kind = k;
        e->id = it[0];
        e->z = 0;
        e->v = 999;
        e++;
        l->n++;
    }
}
}  // namespace n002822c0

