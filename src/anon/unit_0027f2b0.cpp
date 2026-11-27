// Linked unit 0x0027ee48-0x00281cf0 (one namespace per old matched source; class methods in their own namespace).
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

// 0027ee48 (was gap, written for the unit): init of the gumi pause menu (menu table entry 0x33000b; exit is 0x27f110)
namespace n0027ee48 {
struct Hp;
struct HpVt { void* (*alloc)(Hp*, u32, u32); void (*free)(Hp*, void*); };
struct Hp { HpVt* vt; };
struct Sys { u8 pad[20]; Hp* heap; };
struct Mm { u32 a; u32 b; };
extern u8* D_0035f264 asm("D_0035f264");
extern void* D_0035f260 asm("D_0035f260");
extern u8* D_0035f25c asm("D_0035f25c");
extern u8* D_0035f258 asm("D_0035f258");
extern void* D_0035f254 asm("D_0035f254");
extern u8* D_0035f250 asm("D_0035f250");
extern s8 D_0035f268 asm("D_0035f268");
extern Sys* D_00347f80 asm("D_00347f80");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern s8 D_00374168[] asm("D_00374168");
void func_00253818(s32) asm("func_00253818");
void func_00259350(s32) asm("func_00259350");
void SetModeMax(s32, s32) asm("_ZN2Tz8MenuBase10SetModeMaxEii");
void PlaySE(s32, s32) asm("_ZN2Tz9MenuSound6PlaySEEib");
void func_0028d068(s32, s32) asm("func_0028d068");
void* func_00288be8(s32) asm("func_00288be8");
void func_002889f0(void*, s32, s32) asm("func_002889f0");
u8* func_0023ee30(s32) asm("func_0023ee30");
void func_002369a0(u8*) asm("func_002369a0");
void func_0023c008(u8*) asm("func_0023c008");
void func_00239700(u8*) asm("func_00239700");
void func_0031a838(u8*) asm("func_0031a838");
void* LoadDataGetSystem(void) asm("func_00103570");
void* LoadDataAlloc(u32, void*) asm("func_001063c0");
Mm* getMenuMode(void) asm("func_00103eb0");
void func_00102818(u32, s32, s32, void (*)(void), s32) asm("func_00102818");
void func_0027f2f8(void) asm("_ZN2Tz9GumiPause11PauseThreadEP4TASK");
static inline void CtorC2(u8* q) {
    *(u32*)q = (u32)D_00347f98;
    func_0031a838(q + 12);
    *(u32*)q = (u32)D_00347e60;
    func_00239700(q + 24);
    *(u32*)q = (u32)D_00347e40;
    *(u32*)(q + 408) = 0;
}
static inline void CtorC(u8* q) {
    *(u32*)q = (u32)D_00347f98;
    func_0031a838(q + 12);
    *(u32*)q = (u32)D_00347e60;
    func_00239700(q + 24);
    *(u32*)(q + 408) = 0;
    *(u32*)q = (u32)D_00347e40;
}
static inline void CtorB1(u8* q) {
    *(u32*)q = (u32)D_00347f98;
    func_0031a838(q + 12);
    *(u32*)q = (u32)D_00347e60;
    func_00239700(q + 24);
}
void func_0027ee48(void) asm("func_0027ee48");
void func_0027ee48(void) {
    s32 n = 0;
    func_00253818(5);
    func_00259350(5);
    SetModeMax(2, 3);
    PlaySE(11, 1);
    func_0028d068(30026, -1);
    void* s = func_00288be8(56);
    func_002889f0(s, 9, 0);
    D_0035f254 = s;
    u8* o = func_0023ee30(160);
    *(u32*)(o + 12) = 0;
    *(u32*)o = (u32)D_0035eb98;
    func_002369a0(o + 24);
    func_0023c008(o + 48);
    u8* vt = D_00347e60;
    D_0035f250 = o;
    u8* q = (u8*)D_00347f80->heap->vt->alloc(D_00347f80->heap, 408, 0);
    *(u32*)(q + 12) = 0;
    *(u32*)q = (u32)vt;
    func_00239700(q + 24);
    D_0035f258 = q;
    for (s32 i = 0; i < 9; i++) {
        if (D_00374168[i] < 0) {
            if (i != 2) n++;
        }
    }
    u32* a = (u32*)D_00347f80->heap->vt->alloc(D_00347f80->heap, n * 872 + 4, 0);
    u8* arr = (u8*)(a + 1);
    *a = n * 2;
    u8* e = arr;
    for (s32 k = n * 2 - 1; k != -1; k--, e += 436) CtorC2(e);
    D_0035f25c = arr;
    D_0035f260 = LoadDataAlloc(88, LoadDataGetSystem());
    u8* p = (u8*)LoadDataAlloc(1312, LoadDataGetSystem());
    func_002369a0(p);
    CtorC(p + 24);
    CtorC(p + 460);
    CtorB1(p + 896);
    D_0035f264 = p;
    D_0035f268 = -1;
    func_00102818(getMenuMode()->b, 0, 2000, func_0027f2f8, 4096);
}
}  // namespace n0027ee48

// 0027f110 (was gap, written for the unit): exit of the menu whose init is 0x27ee48
namespace n0027f110 {
struct El;
typedef void (*ElFn)(El*);
struct El { ElFn* vt; u8 pad[432]; };
struct Hp;
struct HpVt { void* a; void (*free)(Hp*, void*); };
struct Hp { HpVt* vt; };
struct Sys { u8 pad[20]; Hp* heap; };
struct Ob;
typedef void (*ObFn)(Ob*);
struct Ob { ObFn* vt; };
extern u8* D_0035f264 asm("D_0035f264");
extern void* D_0035f260 asm("D_0035f260");
extern El* D_0035f25c asm("D_0035f25c");
extern Ob* D_0035f258 asm("D_0035f258");
extern void* D_0035f254 asm("D_0035f254");
extern Ob* D_0035f250 asm("D_0035f250");
extern s8 D_0035f268 asm("D_0035f268");
extern Sys* D_00347f80 asm("D_00347f80");
extern u8 D_00347e60[] asm("D_00347e60");
void func_002804f0(void) asm("func_002804f0");
void func_0031abd8(u8*) asm("func_0031abd8");
void func_0031acc0(u8*) asm("func_0031acc0");
void func_00239870(u8*) asm("func_00239870");
void func_0031a840(u8*) asm("func_0031a840");
void func_002369f0(u8*) asm("func_002369f0");
void func_00106420(void*) asm("func_00106420");
void func_00288b00(void*) asm("func_00288b00");
void func_00288c20(void*) asm("func_00288c20");
void func_002427c0(void) asm("func_002427c0");
void func_0027f110(void) asm("func_0027f110");
void func_0027f110(void) {
    func_002804f0();
    u8* p = D_0035f264;
    if (p) {
        u8* b = p + 24;
        func_0031abd8(p + 896);
        func_0031acc0(p + 460);
        *(u8**)b = D_00347e60;
        func_00239870(p + 48);
        func_0031a840(b);
        func_002369f0(p);
        func_00106420(p);
        D_0035f264 = 0;
    }
    if (D_0035f260) { func_00106420(D_0035f260); D_0035f260 = 0; }
    if (D_0035f25c) {
        El* e = D_0035f25c + ((s32*)D_0035f25c)[-1];
        for (;;) {
            if (D_0035f25c == e) break;
            --e;
            e->vt[3](e);
        }
        D_00347f80->heap->vt->free(D_00347f80->heap, (u8*)D_0035f25c - 4);
        D_0035f25c = 0;
    }
    if (D_0035f258) { D_0035f258->vt[4](D_0035f258); D_0035f258 = 0; }
    void* s = D_0035f254;
    if (s) { func_00288b00(s); func_00288c20(s); D_0035f254 = 0; }
    if (D_0035f250) { D_0035f250->vt[4](D_0035f250); D_0035f250 = 0; }
    s8 c = D_0035f268;
    if (c == 1 || c == 7 || c == 8) func_002427c0();
    D_0035f268 = -1;
}
}  // namespace n0027f110

// 0027f2b0 (was src/anon/batch_w26.cpp)
namespace n0027f2b0 {
// set_bit_in_array_b
bool u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
bool select_is_created(...) asm("_ZN2Tz6Select9isCreatedEz");
extern void* D_0035f250 asm("D_0035f250");
extern void* D_0035f258 asm("D_0035f258");
extern void* D_0035f254 asm("D_0035f254");
/*TARGET 0027f2b0*/
bool func_0027f2b0(void) asm("func_0027f2b0");
bool func_0027f2b0(void) {
    bool r = u_call4_00139d78(D_0035f250);
    if (!r) {
        r = u_call4_00139d78(D_0035f258);
        if (!r) r = select_is_created(D_0035f254);
    }
    return r;
}
}  // namespace n0027f2b0

// 0027f2f8 (was src/tozawa/gumi_pause.cpp)
namespace Tz { // method 0027f2f8
void func_002593b8(u32, u32) asm("func_002593b8");
void func_00102448(u32, u32) asm("func_00102448");
void func_002806c8() asm("func_002806c8");
void func_00236d60() asm("func_00236d60");
// clear_64_entries_24
extern "C" u32 func_0027f3d8() asm("func_0027f3d8");
void func_0027fba0() asm("func_0027fba0");
/*TARGET 0027f2f8*/
void GumiPause::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    func_002593b8(5, s0);
    func_00102448(s0, 1);
    func_002806c8();
    SetupTop();
    while (true) {
        func_00236d60();  // clear_64_entries_24
        if (func_0027f3d8() != 0) {
            break;
        }
        func_0027fba0();
        func_00102448(s0, 0);
    }
}
}  // Tz

// 0027f370 (was src/tozawa/gumi_pause.cpp)
namespace Tz { // method 0027f370
extern u32 D_0035f250 asm("D_0035f250");
void func_0028d7f0(u32, u32, u32, u32, u32, s32, u32, u32, u32) asm("func_0028d7f0");
void func_0023ef50(u32) asm("func_0023ef50");
void func_0027ff00() asm("func_0027ff00");
void func_00287bd0(u32, u32) asm("func_00287bd0");
void func_0027f4a8() asm("func_0027f4a8");
/*TARGET 0027f370*/
void GumiPause::SetupTop() {
    func_0028d7f0(D_0035f250, 30002, 0, 0, 0, -1, 0, 0, 0);
    func_0023ef50(D_0035f250);
    func_0027ff00();
    func_00287bd0(0, 0);
    func_0027f4a8();
}
}  // Tz

// 0027f3d8 (was src/anon/batch_w89.cpp)
namespace n0027f3d8 {
struct FnHolder { u32 f0; void (*fn)(void); };
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00287db0(void) asm("func_00287db0");
s32 func_0027f2b0(void) asm("func_0027f2b0");
s32 func_00253918(void) asm("func_00253918");
FnHolder* func_001040f8(void) asm("func_001040f8");
s32 func_00242a00(void) asm("func_00242a00");
void func_0023d1d0(void) asm("func_0023d1d0");
// set_global_word1
void func_0023d1e0(void) asm("func_0023d1e0");
// zero_global_d
void func_001039f8(void) asm("func_001039f8");
void func_0027f7f0(void) asm("func_0027f7f0");
void func_0027f9d8(void) asm("func_0027f9d8");
/*TARGET 0027f3d8*/
s32 func_0027f3d8(void) asm("func_0027f3d8");
s32 func_0027f3d8(void) {
    if (func_00287db0()) {
        if (func_0027f2b0()) return 0;
        if (func_00253918()) return 0;
        func_001040f8()->fn();
        if (func_00242a00()) func_0023d1d0();
        else func_0023d1e0();  // zero_global_d
        func_001039f8();
        return 1;
    }
    s32 m = func_00287bc0();
    if (m != 0) {
        if (m == 1) func_0027f9d8();
    } else func_0027f7f0();
    return 0;
}
}  // namespace n0027f3d8

// 0027f4a8 (was src/anon/batch_w1612.cpp)
namespace n0027f4a8 {
struct Sub { u8 pad[184]; u32 flags; void set8() { flags |= 8; } };
struct Win { u8 pad[24]; Sub sub; };
struct E { u8 pad[408]; s32 f408; u8 pad2[20]; s32 f432; };
extern s32 D_0035f250 asm("D_0035f250");
extern void* D_0035f254 asm("D_0035f254");
extern Win* D_0035f258 asm("D_0035f258");
union UE { E* p; s32 i; };
extern UE D_0035f25c asm("D_0035f25c");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u16 D_003740f8[2][9] asm("D_003740f8");
extern u16 D_00374130[] asm("D_00374130");
extern u16 D_00374158[][2] asm("D_00374158");
extern s8 D_00374168[] asm("D_00374168");
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_00288d80(void*, s32, s32, s32, s32, s32, u16*, u16*) asm("func_00288d80");
E* func_002891b8(void*, s32) asm("func_002891b8");
void func_00139620(void*) asm("func_00139620");
s32 func_0023aa18(void*) asm("func_0023aa18");
s32 func_0023aa38(void*) asm("func_0023aa38");
s32 func_0023aa98(void*) asm("func_0023aa98");
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
void func_001395f8(void*) asm("func_001395f8");
s32 func_00192048(u16) asm("func_00192048");
void func_0028af28(void*, s32) asm("func_0028af28");
s32 func_001041c0(void) asm("func_001041c0");
void func_0028b1b0(void*, s32) asm("func_0028b1b0");
void func_0027fd38(void) asm("func_0027fd38");
void func_002891f0(void*, s32, s32, s32, s32) asm("func_002891f0");
void func_00287bd0(s32, s32) asm("func_00287bd0");
/*TARGET 0027f4a8*/
// Builds the menu window and its 9 rows, then the per-row sub-items.
void func_0027f4a8(void) asm("func_0027f4a8");
// Builds the menu window and its 9 rows, then the per-row sub-items.
void func_0027f4a8(void) {
    u16 a[2][4];
    s32 i, j;
    func_0028d8c0(D_0035f258, 30003, 1, 0, D_0035f250, 1, -1, 0);
    D_0035f258->sub.set8();
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 2; j++) {
            for (s32 m = 0; m < 4; m++) a[j][m] = D_003740f8[j][i];
        }
        func_00288d80(D_0035f254, i, 1, 0, D_0035f250, D_00374130[i], a[0], a[1]);
        func_00139620(func_002891b8(D_0035f254, i));
        func_002891b8(D_0035f254, i)->f432 = 2;
    }
    s32 n = D_0035f3d4 + 1;
    s32 c = 0;
    for (i = 0; i < 9; i++) {
        if (D_00374168[i] >= 0) continue;
        if (i == 2) continue;
        s32 x = func_0023aa18((u8*)func_002891b8(D_0035f254, i) + 24);
        s32 y = func_0023aa38((u8*)func_002891b8(D_0035f254, i) + 24);
        s32 h = func_0023aa98((u8*)func_002891b8(D_0035f254, i) + 24);
        s32 off = c * 436;
        for (j = 0; j < 2; j++) {
            E* e;
            func_0028d980((E*)((u8*)D_0035f25c.p + off), n, 1, 0, D_0035f250, 27, -1, -1, 0);
            func_0028dcc0((E*)((u8*)D_0035f25c.p + off), func_002891b8(D_0035f254, i));
            func_00139620((E*)((u8*)D_0035f25c.p + off));
            func_00138c68((E*)((u8*)D_0035f25c.p + off), x, y);
            x += h;
            func_001395f8((E*)((u8*)D_0035f25c.p + off));
            e = (E*)((u8*)D_0035f25c.p + off);
            e->f408 = func_00192048(D_00374158[c / 2][j]);
            ((E*)((u8*)D_0035f25c.p + off))->f432 = 2;
            c++;
            off += 436;
        }
    }
    func_0028af28(D_0035f254, 32);
    if (func_001041c0() != 3) func_0028b1b0(D_0035f254, 64);
    func_0027fd38();
    func_002891f0(D_0035f254, 0, 1, 0, -1);
    func_00287bd0(0, 0);
}
}  // namespace n0027f4a8

// 0027f7f0 (was src/anon/batch_w1577.cpp)
namespace n0027f7f0 {
struct PauseParam1577 { bool b0; bool b1; bool b2; u8 b3; };
extern s32 D_0035f254 asm("D_0035f254");
extern s8 D_0035f268 asm("D_0035f268");
extern u8 D_00374168[] asm("D_00374168");
s32 func_00289380(s32) asm("func_00289380");
s32 func_00289310(s32) asm("func_00289310");
void func_002806f0(void) asm("func_002806f0");
s32 func_00287df0(s32, s32, s32, void (*)(void), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
PauseParam1577* func_001040f8(void) asm("func_001040f8");
void func_00287da0(void) asm("func_00287da0");
s32 func_0028b040(s32) asm("func_0028b040");
void func_0027fd38(void) asm("func_0027fd38");
bool func_00242a00(void) asm("func_00242a00");
void func_00242a28(u8) asm("func_00242a28");
void func_0027f9b0(void) asm("func_0027f9b0");
void func_00287bd0(s32, s32) asm("func_00287bd0");
/*TARGET 0027f7f0*/
void func_0027f7f0(void) asm("func_0027f7f0");
void func_0027f7f0(void) {
    s32 r = func_00289380(D_0035f254);
    if (func_00242848(func_00287df0(r, func_00289310(D_0035f254), 1, func_002806f0, 1))) return;
    switch (r) {
    case -4:
    case -2:
        func_001040f8()->b3 = 0;
        func_00287da0();
        return;
    case -13:
    case -12:
        switch (func_0028b040(D_0035f254)) {
        case 3: { PauseParam1577* p = func_001040f8(); p->b0 = !p->b0; break; }
        case 6: { PauseParam1577* p = func_001040f8(); p->b2 = !p->b2; break; }
        case 5: { PauseParam1577* p = func_001040f8(); p->b1 = !p->b1; break; }
        case 4: func_00242a28(!func_00242a00()); break;
        }
        func_0027fd38();
        return;
    case -1:
        break;
    default:
        if (r == 2) {
            func_0027f9b0();
            func_00287bd0(1, 0);
            return;
        }
        func_001040f8()->b3 = D_00374168[r];
        D_0035f268 = r;
        func_00287da0();
        break;
    }
}
}  // namespace n0027f7f0

// 0027f9b0 (was src/anon/batch_w9.cpp)
namespace n0027f9b0 {
void func_00280148(void) asm("func_00280148");
void func_002800d0(void) asm("func_002800d0");
void func_00287cc0(u32) asm("func_00287cc0");
/*TARGET 0027f9b0*/
// 0x002631b0: definition moved into src/anon/unit_0025f6b8.cpp

void func_0027f9b0(void) asm("func_0027f9b0");
// 0x002631b0: definition moved into src/anon/unit_0025f6b8.cpp

void func_0027f9b0(void) {
    func_00280148();
    func_002800d0();
    func_00287cc0(0);
}
}  // namespace n0027f9b0

// 0027f9d8 (was src/anon/batch_w115.cpp)
namespace n0027f9d8 {
struct Pad { u8 p0[8]; u64 trig; u8 p16[8]; u64 rep; };
struct Cur { u8 p0[4]; s8 count; s8 sel; };
extern Cur* D_0035f260 asm("D_0035f260");
Pad* func_00167f18(s32) asm("func_00167f18");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00280290(void) asm("func_00280290");
void func_002802e8(void) asm("func_002802e8");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00280458(void) asm("func_00280458");
void func_00280528(void) asm("func_00280528");
s32 func_00280368(void) asm("func_00280368");
void func_002803e0(void) asm("func_002803e0");
void func_00287cc0(s32) asm("func_00287cc0");
void func_00242618(s32, s32) asm("func_00242618");
void func_00280240(void) asm("func_00280240");
void func_002800d0(void) asm("func_002800d0");
/*TARGET 0027f9d8*/
void func_0027f9d8(void) asm("func_0027f9d8");
void func_0027f9d8(void) {
    Pad* pad = func_00167f18(0);
    s32 st = func_00287cd0();
    if (st == 2) {
        if (func_00280290()) {
            if (pad->trig & 0xf8) func_002802e8();
            return;
        }
        func_00287bd0(0, 0);
        return;
    }
    func_00280458();
    func_00280528();
    if (st == 0) {
        if (pad->rep & 0xf8) {
            if (!func_00280368()) func_002803e0();
        }
        if (func_00280368()) func_00287cc0(1);
    }
    u64 b = pad->trig;
    s32 d;
    if (b & 0x10) d = -5;
    else if (b & 0x20) d = 5;
    else if (b & 0x40) d = -1;
    else if (b & 0x80) d = 1;
    else {
        if (!(b & 8)) return;
        func_00242618(9, 1);
        func_00280240();
        func_00287cc0(2);
        return;
    }
    if (d) func_00242618(7, 1);
    s32 cur = D_0035f260->sel;
    s32 n = cur + d;
    if (n < 0) {
        if (cur != 0) cur = 0;
        else cur = D_0035f260->count - 1;
    } else if (n >= D_0035f260->count) {
        s32 last = D_0035f260->count - 1;
        cur = cur < last ? last : 0;
    } else {
        cur = n;
    }
    D_0035f260->sel = cur;
    func_002800d0();
}
}  // namespace n0027f9d8

// 0027fba0 (was src/anon/batch_w3785.cpp)
namespace n0027fba0 {
struct VObj { void (**vt)(VObj*); };
s32 func_00287db0(void) asm("func_00287db0");
s32 func_00139d78(VObj*) asm("func_00139d78");
s32 func_0028acc8(u32) asm("func_0028acc8");
void func_0028abe0(u32) asm("func_0028abe0");
s32 func_00289310(u32) asm("func_00289310");
void func_002890e0(u32, s32, s32, s32, s32) asm("func_002890e0");
u32 func_002891e8(u32) asm("func_002891e8");
void func_00289038(u32, u32, s32, s32, s32, s32, s32) asm("func_00289038");
void func_0027fcc0(void) asm("func_0027fcc0");
extern VObj* D_0035f250 asm("D_0035f250");
extern VObj* D_0035f258 asm("D_0035f258");
extern u32 D_0035f254 asm("D_0035f254");
/*TARGET 0027fba0*/
void func_0027fba0(void) asm("func_0027fba0");
void func_0027fba0(void) {
    if (func_00287db0()) {
        /* empty barrier: keeps reorg from filling the beqz slot from the if body (orig: beqzl stealing lui s1) */
        asm volatile("");
        if (func_00139d78(D_0035f250)) D_0035f250->vt[5](D_0035f250);
        if (func_00139d78(D_0035f258)) D_0035f258->vt[5](D_0035f258);
        if (func_0028acc8(D_0035f254)) func_0028abe0(D_0035f254);
        s32 i = 0; s32 c;
        do {
            i++;
            c = i < 9;
             /* hand-written delay nops */



        } while (c);
    }
    if (!func_00289310(D_0035f254)) return;
    u32 r = func_002891e8(D_0035f254);
    func_002890e0(D_0035f254, 1, 2, 0, -1);
    func_00289038(D_0035f254, r, 1, 1, 2, 0, -1);
    func_0027fcc0();
}
}  // namespace n0027fba0

// 0027fcc0 (was src/tozawa/cmenu_config.cpp)
namespace Tz { // method 0027fcc0
extern u32 D_0035f254 asm("D_0035f254");
u32 func_0028af88(...) asm("func_0028af88");
u32 func_0028b040(...) asm("func_0028b040");
void func_0028af18(...) asm("func_0028af18");
extern u8 D_00374168 asm("D_00374168");
/*TARGET 0027fcc0*/
void CmConfig::DrawUpdate(Select*, s32, s32) {
    u32 s1 = func_0028af88(D_0035f254);
    u32 i = func_0028b040(D_0035f254);
    s8 v = *((s8*)&D_00374168 + i);
    s32 m = -13;
    if (v >= 0) {
        goto clear_bits;
    }
    if (i == 2) {
        goto clear_bits;
    }
    s1 |= 0xcu;
    goto apply;
clear_bits:
    s1 &= (u32)m;
apply:
    func_0028af18(D_0035f254, s1);
}
}  // Tz

// 0027fd38 (was src/anon/batch_w1905.cpp)
namespace n0027fd38 {
struct S8 { s8 a, b, c; };
S8* func_001040f8(void) asm("func_001040f8");
s32 func_001041c0(void) asm("func_001041c0");
void func_00138c10(s32, s32) asm("func_00138c10");
s32 func_00242a00(void) asm("func_00242a00");
extern s32 D_0035f25c asm("D_0035f25c");
extern s32 D_003740f0 asm("D_003740f0");
extern s32 D_003740f4 asm("D_003740f4");
extern s8 D_00374168[] asm("D_00374168");
/*TARGET 0027fd38*/
void func_0027fd38(void) asm("func_0027fd38");
void func_0027fd38(void) {
    s32 i, n = 0; s32 k2 = 2, k3 = 3, k4 = 4;
    for (i = 0; i < 9; i++) {
        s32 f;
        if (D_00374168[i] >= 0) continue;
        if (i == k2) continue;
        f = 0;
        if (i == k4) goto c4;
        if (i >= 5) goto ge5;
        if (i == k3) goto c3;
        goto join;
    join:
        if (func_001041c0() != 3 && i == 6) {
            func_00138c10(D_0035f25c + n*0x368, 0x1b);
            func_00138c10(D_0035f25c + n*0x368 + 0x1b4, 0x1b);
        } else {
            func_00138c10(D_0035f25c + n*0x368, f == 0 ? D_003740f0 : D_003740f4);
            func_00138c10(D_0035f25c + n*0x368 + 0x1b4, f ? D_003740f0 : D_003740f4);
        }
        n++;
        continue;
    c3: f = func_001040f8()->a; goto join;
    ge5:
        if (i == 5) goto c5;
        if (i != 6) goto join;
        f = func_001040f8()->c; goto join;
    c5: f = func_001040f8()->b; goto join;
    c4: f = func_00242a00() == 0; goto join;
    }
}
}  // namespace n0027fd38

// 0027ff00 (was src/anon/batch_w109.cpp)
namespace n0027ff00 {
// ---- f12.cpp
struct List27ff00 {
    u8 pad[4];
    u8 count;
    u8 b5;
    s8 b6;
    s8 b7;
    s8 ids[40];
    s8 keys[40];
};
struct Ent27ff00 {
    s32 id;
    s32 flag;
    u8 pad[12];
    s32 key;
};
extern List27ff00* D_0035f260 asm("D_0035f260");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
s32 func_002f1ab8(void) asm("func_002f1ab8");
Ent27ff00* func_002f1ac8(s32) asm("func_002f1ac8");
s32 func_002f1ae0(s32) asm("func_002f1ae0");
/*TARGET 0027ff00*/
void func_0027ff00(void) asm("func_0027ff00");
void func_0027ff00(void) {
    s32 n = 0;
    s32 i, j;
    func_002fde18(D_0035f260, 0, 88);
    D_0035f260->b6 = -1;
    D_0035f260->b7 = -1;
    D_0035f260->b5 = 0;
    s32 cnt = func_002f1ab8();
    for (i = 0; i < cnt; i++) {
        Ent27ff00* e = func_002f1ac8(i);
        if (e->flag != 0 && !func_002f1ae0(e->id)) continue;
        for (j = 0; j < n; j++) {
            if (D_0035f260->keys[j] == e->key) break;
        }
        if (j < n) continue;
        D_0035f260->ids[n] = e->id;
        D_0035f260->keys[n] = e->key;
        n++;
    }
    D_0035f260->count = n;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (D_0035f260->keys[i] > D_0035f260->keys[j]) {
                s8 t = D_0035f260->ids[i];
                D_0035f260->ids[i] = D_0035f260->ids[j];
                D_0035f260->ids[j] = t;
                t = D_0035f260->keys[i];
                D_0035f260->keys[i] = D_0035f260->keys[j];
                D_0035f260->keys[j] = t;
            }
        }
    }
}
}  // namespace n0027ff00

// 002800d0 (was src/tozawa/gumi_pause.cpp)
namespace Tz { // method 002800d0
extern u32 D_0035f264 asm("D_0035f264");
extern u32 D_0035f260 asm("D_0035f260");
extern u32 D_003740c0 asm("D_003740c0");
u32 func_00192048(u32) asm("func_00192048");
u32 func_00192c40(u32, u32) asm("func_00192c40");
void func_00192cc0(u32, u32, s32) asm("func_00192cc0");
void func_00280678() asm("func_00280678");
/*TARGET 002800d0*/
void GumiPause::UpdateAdvice() {
    u32 s0 = D_0035f264;
    u32 r = func_00192048(18694);
    s0 += 1304;
    s0 += func_00192c40(r, s0);

    u8* p = (u8*)D_0035f260;
    s8 o = ((s8*)p)[5];
    u32 q = (u32)(s32)o + (u32)p;
    s32 val = (s32)*(s8*)(q + 48);
    func_00192cc0(s0, (u32)&D_003740c0, val);

    p = (u8*)D_0035f260;
    p[6] = p[5];
    func_00280678();
}
}  // Tz

// 00280148 (was src/anon/batch_w82.cpp)
namespace n00280148 {
extern u32 D_0035f264 asm("D_0035f264");
extern u32 D_0035f250 asm("D_0035f250");
void func_0028d980(u8*, s32, s32, s32, u32, s32, s32, s32, s32) asm("func_0028d980");
void func_00139620(u8*) asm("func_00139620");
void func_001395f8(u8*) asm("func_001395f8");
u32 func_00192048(s32) asm("func_00192048");
void wt82(u8*, u32, u32) asm("_Z16wtarget_002fde18jjjj");
/*TARGET 00280148*/
// 0x0026a178: definition moved into src/anon/unit_00269a60.cpp

void func_00280148(void) asm("func_00280148");
// 0x0026a178: definition moved into src/anon/unit_00269a60.cpp

void func_00280148(void)
{
    u8* p = (u8*)D_0035f264 + 24;
    func_0028d980(p, 30045, 0, 0, D_0035f250, 7, 8, -1, 0);
    func_00139620(p);
    func_001395f8(p);
    *(u32*)(p + 432) = 2;
    *(u32*)(p + 408) = func_00192048(18691);
    p = (u8*)D_0035f264 + 460;
    func_0028d980(p, 30046, 0, 0, D_0035f250, 10, 11, -1, 0);
    wt82((u8*)D_0035f264 + 1304, 0, 8);
    func_00139620(p);
    func_001395f8(p);
    *(u32*)(p + 432) = 2;
    *(u32*)(p + 408) = D_0035f264 + 1304;
}
}  // namespace n00280148

// 00280240 (was src/anon/batch_w24.cpp)
namespace n00280240 {
void func_0028dac8(u8*, s32) asm("func_0028dac8");
extern u8* D_0035f264 asm("D_0035f264");
/*TARGET 00280240*/
void func_00280240(void) asm("func_00280240");
void func_00280240(void) {
    func_0028dac8(D_0035f264 + 24, 9);
    func_0028dac8(D_0035f264 + 460, 12);
    func_0028dac8(D_0035f264 + 896, 3);
}
}  // namespace n00280240

// 00280290 (was src/anon/auto80_199_queue.cpp)
namespace n00280290 {
/*TARGET 00280290*/
u32 func_00280290(void) asm("_Z13func_00280290v");
u32 func_00280290(void) {
    u32 v = func_00139d78(D_0035f264 + 24);
    if (v == 0) {
        v = func_00139d78(D_0035f264 + 460);
        if (v == 0) {
            v = func_00139d78(D_0035f264 + 896);
        }
    }
    return v;
}
}  // namespace n00280290

// 002802e8 (was src/anon/auto80_199_queue.cpp)
namespace n002802e8 {
/*TARGET 002802e8*/
void func_002802e8(void) asm("_Z13func_002802e8v");
void func_002802e8(void) {
    if (func_00139d78(D_0035f264 + 24) != 0) {
        func_00139510(D_0035f264 + 24);
    }

    if (func_00139d78(D_0035f264 + 460) != 0) {
        func_00139510(D_0035f264 + 460);
    }

    if (func_00139d78(D_0035f264 + 896) != 0) {
        func_00139510(D_0035f264 + 896);
    }
}
}  // namespace n002802e8

// 00280368 (was src/anon/auto80_199_queue.cpp)
namespace n00280368 {
/*TARGET 00280368*/
u32 func_00280368(void) asm("_Z13func_00280368v");
u32 func_00280368(void) {
    u32 ok = 0;
    if (func_00139d78(D_0035f264 + 24) != 0) {
        ok = (*(u32*)(D_0035f264 + 412) == 8);
    }

    if (ok == 0) {
        if (func_00139d78(D_0035f264 + 460) != 0) {
            ok = (*(u32*)(D_0035f264 + 848) == 11);
        }
    }
    return ok;
}
}  // namespace n00280368

// 002803e0 (was src/anon/batch_w21.cpp)
namespace n002803e0 {
void func_0028da70(void*, s32) asm("func_0028da70");
extern u8* D_0035f264 asm("D_0035f264");
/*TARGET 002803e0*/
// 0x00263a58: definition moved into src/anon/unit_002632d0.cpp

void func_002803e0(void) asm("func_002803e0");
// 0x00263a58: definition moved into src/anon/unit_002632d0.cpp

void func_002803e0(void) {
    func_0028da70(D_0035f264 + 24, 8);
    func_0028da70(D_0035f264 + 460, 11);
}
}  // namespace n002803e0

// 00280420 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00280420 {
u32 func_002fee78(u32, u32, u32, u32) asm("_Z13func_002fee78jjjj");
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00360000 asm("D_00360000");
extern u8 D_003740c8 asm("D_003740c8");
/*TARGET 00280420*/
u32 func_00280420(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00280420jjjj");
u32 func_00280420(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002fee78(a0, (u32)&D_003740c8, ((u32)(*(u32*)((u32)((u32)&D_00340000) - 13580u))), ((u32)(*(s8*)((u32)(((u32)(((u32)(*(u32*)((u32)((u32)&D_00360000) - 3488u)))) + (u32)(a1))) + 8u))));
}
}  // namespace n00280420

// 00280458 (was src/tozawa/gumi_pause.cpp)
namespace Tz { // method 00280458
extern u32 D_0035f260 asm("D_0035f260");
u32 func_00253918() asm("func_00253918");
u32 func_002806a0() asm("func_002806a0");
void func_002804f0() asm("func_002804f0");
void func_00280420(void*, s32) asm("func_00280420");
void func_002539e8(u32, void*) asm("func_002539e8");
/*TARGET 00280458*/
void GumiPause::ChkLoadRequest() {
    u8 buf[64];
    if (func_00253918() != 0) {
        return;
    }

    u8* p = (u8*)D_0035f260;
    if ((s8)p[6] < 0) {
        return;
    }
    if ((s8)p[7] >= 0) {
        return;
    }

    if (func_002806a0() != 0) {
        return;
    }

    func_002804f0();
    u8* p1 = (u8*)D_0035f260;
    func_00280420(buf, (s32)(s8)p1[6]);
    func_002539e8(6, buf);

    u8* p2 = (u8*)D_0035f260;
    u8 b = p2[6];
    p2[7] = b;
    u8* p3 = (u8*)D_0035f260;
    p3[6] = 0xff;
}
}  // Tz

// 002804f0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002804f0 {
extern u32 D_0035f260 asm("D_0035f260");
void func_002537e0(u32 a0) asm("_Z13func_002537e0j");
/*TARGET 002804f0*/
void func_002804f0() asm("_Z13func_002804f0v");
void func_002804f0() {
    u32 p = *(u32*)(u32)&D_0035f260;
    if (*(u32*)p == 0u) {
        return;
    }
    *(u32*)p = 0u;
    func_002537e0(6u);
}
}  // namespace n002804f0

// 00280528 (was src/anon/batch_w67.cpp)
namespace n00280528 {
s32 func_00103570(void) asm("func_00103570");
// 002e3540
// 002e3540: moved to src/anon/unit_002e2f08.cpp

s32 func_00253918(void) asm("func_00253918");
s32 func_002537c8(s32) asm("func_002537c8");
void func_00236c38(u32) asm("func_00236c38");
void func_00236a58(u32, s32, s32) asm("func_00236a58");
void func_002805d0(void) asm("func_002805d0");
struct State280 { s32 v; s8 pad[2]; s8 b6; s8 b7; };
union StatePtr { State280* p; u8 c; };
extern StatePtr D_0035f260 asm("D_0035f260");
extern u32 D_0035f264 asm("D_0035f264");
/*TARGET 00280528*/
// 00280528
void func_00280528(void) asm("func_00280528");
// 00280528
void func_00280528(void)
{
    if (func_00253918()) return;
    if (D_0035f260.p->b7 < 0) return;
    D_0035f260.p->b7 = -1;
    D_0035f260.p->v = func_002537c8(6);
    if (D_0035f260.p->b6 >= 0) return;
    func_00236c38(D_0035f264);
    func_00236a58(D_0035f264, D_0035f260.p->v, func_00103570());
    func_002805d0();
}
}  // namespace n00280528

// 002805d0 (was src/anon/batch_wcx.cpp)
namespace n002805d0 {
extern u8* D_0035f264 asm("D_0035f264");
extern u32 D_0035f250 asm("D_0035f250");
void func_002806a0(void) asm("func_002806a0");
u32 func_0023f1b0(u32) asm("func_0023f1b0");
u32 func_0023c4b8(u32, s32) asm("func_0023c4b8");
u32 func_00236ca8(u8*, s32) asm("func_00236ca8");
void func_001386e0(u8*, s32, u32, u32, s32, s32) asm("func_001386e0");
/*TARGET 002805d0*/
void func_002805d0(void) asm("func_002805d0");
void func_002805d0(void)
{
    func_002806a0();
    u8* s0 = D_0035f264;
    u8* s1 = s0 + 896;
    s0 += 920;
    u32 x = func_0023c4b8(func_0023f1b0(D_0035f250), 0);
    u32 y = func_00236ca8(D_0035f264, 0);
    func_001386e0(s1, 30047, x, y, 1, 0);
    *(s32*)(s1 + 392) = 2;
    s1[405] = 1;
    *(u32*)(s0 + 184) |= 8;
}
}  // namespace n002805d0

// 00280678 (was src/anon/tiny_wrappers_imp.cpp)
namespace n00280678 {
u32 func_0028dac8(u32, u32, u32, u32) asm("_Z13func_0028dac8jjjj");
/*TARGET 00280678*/
u32 func_00280678(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00280678jjjj");
u32 func_00280678(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0036u << 16);
    r5 = (u32)((s32)0u + (3));
    r4 = *(u32*)((u32)r15 + (s32)(-3484));
    r4 = (u32)((s32)r4 + (896));
    return func_0028dac8(r4, r5, r6, r7);
}
}  // namespace n00280678

// 002806a0 (was src/anon/batch_w3.cpp)
namespace n002806a0 {
// 0x00265780: definition moved into src/anon/unit_00265580.cpp

extern u32 D_0035f264 asm("D_0035f264");
u8 func_00139d78(u32) asm("func_00139d78");
/*TARGET 002806a0*/
u32 func_002806a0() asm("func_002806a0");
u32 func_002806a0() { return func_00139d78(D_0035f264 + 896); }
}  // namespace n002806a0

// 002806c8 (was src/anon/batch_w10.cpp)
namespace n002806c8 {
void* func_002537c8(s32) asm("func_002537c8");
void* func_0023fa08(void*, void*) asm("func_0023fa08");
extern u8 D_0035f3a8 asm("D_0035f3a8");
void* CMData_GetPtr(s32) asm("_ZN2Tz6CMData6GetPtrEi");
/*TARGET 002806c8*/
void* CMData_GetPtr(s32) asm("_ZN2Tz6CMData6GetPtrEi");
void* CMData_GetPtr(s32) {
    return func_0023fa08(&D_0035f3a8, func_002537c8(5));
}
}  // namespace n002806c8

// 002806f0 (was gap, written for the unit)
namespace n002806f0 {
extern s8 D_00374168[] asm("D_00374168");
s32 func_002806f0(s32 i) asm("func_002806f0");
s32 func_002806f0(s32 i) {
    if (i < 0) return 1;
    if (i == 2) return 1;
    return D_00374168[i] >= 0;
}
}  // namespace n002806f0

// 00280720 (was src/anon/batch_w3715_nsa.cpp)
namespace n00280720 {
typedef u8* (*AllocFn)(...);
struct Alloc { AllocFn* vt; };
void func_002427c0(void) asm("func_002427c0");
void func_00253818(s32) asm("func_00253818");
void func_00259350(s32) asm("func_00259350");
void func_00287b18(s32, s32) asm("func_00287b18");
void func_00242618(s32, s32) asm("func_00242618");
void func_0028d068(s32, s32) asm("func_0028d068");
u8* func_00288be8(s32) asm("func_00288be8");
void func_002889f0(u8*, s32, s32) asm("func_002889f0");
u8* func_0023ee30(u32) asm("func_0023ee30");
void func_0031a838(u8*) asm("func_0031a838");
void func_002369a0(u8*) asm("func_002369a0");
void func_0023c008(u8*) asm("func_0023c008");
void func_00239700(u8*) asm("func_00239700");
u8* func_00103eb0(void) asm("func_00103eb0");
void func_002809d8(u32) asm("func_002809d8");
void func_00102818(u32, u32, u32, void (*)(u32), u32) asm("func_00102818");
extern u8* D_00347f80 asm("D_00347f80");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8* D_0035f254 asm("D_0035f254");
extern u8* D_0035f258 asm("D_0035f258");
extern u8* D_0035f25c asm("D_0035f25c");
/*TARGET 00280720*/
// Startup: builds the global managers (D_0035f250..5c) and starts a thread.
void func_00280720(void) asm("func_00280720");
// Startup: builds the global managers (D_0035f250..5c) and starts a thread.
void func_00280720(void) {
    func_002427c0();
    func_00253818(5);
    func_00259350(5);
    func_00287b18(1, 3);
    func_00242618(11, 1);
    func_0028d068(30026, -1);
    u8* p0 = func_00288be8(56);
    func_002889f0(p0, 3, 0);
    D_0035f254 = p0;
    u8* p1 = func_0023ee30(160);
    *(u32*)p1 = (u32)D_00347f98;
    func_0031a838(p1 + 12);
    *(u32*)p1 = (u32)D_0035eb98;
    func_002369a0(p1 + 24);
    func_0023c008(p1 + 48);
    // The original stores D_0035f250 before it loads D_00347f80 (as if the two could alias):
    // the store goes through a hidden high half pinned to t7, the register the original uses.
    register u32 hs asm("$15") = 0x360000; asm("" : "+r"(hs));
    *(u8**)(hs - 3504) = p1;
    Alloc* al = *(Alloc**)(D_00347f80 + 20);
    u8* p2 = al->vt[0](al, 408, 0);
    *(u32*)(p2 + 12) = 0;
    *(u32*)p2 = (u32)D_00347e60;
    func_00239700(p2 + 24);
    D_0035f258 = p2;
    Alloc* al2 = *(Alloc**)(D_00347f80 + 20);
    u8* p3 = al2->vt[0](al2, 1312, 0);
    *(u32*)p3 = 3;
    u8* a = p3 + 4;
    u8* q = a;
    for (s32 i = 2; i != -1; i--, q += 436) {
        *(u32*)q = (u32)D_00347f98;
        func_0031a838(q + 12);
        *(u32*)q = (u32)D_00347e60;
        func_00239700(q + 24);
        *(u32*)q = (u32)D_00347e40;
        *(u32*)(q + 408) = 0;
    }
    D_0035f25c = a;
    func_00102818(*(u32*)(func_00103eb0() + 4), 0, 2000, func_002809d8, 4096);
}
}  // namespace n00280720

// 002808e8 (was gap, written for the unit)
namespace n002808e8 {
struct El;
typedef void (*ElFn)(El*);
struct El { ElFn* vt; u8 pad[432]; };
struct Hp;
struct HpVt { void* a; void (*free)(Hp*, void*); };
struct Hp { HpVt* vt; };
struct Sys { u8 pad[20]; Hp* heap; };
struct Ob;
typedef void (*ObFn)(Ob*);
struct Ob { ObFn* vt; };
extern El* D_0035f25c asm("D_0035f25c");
extern Ob* D_0035f258 asm("D_0035f258");
extern void* D_0035f254 asm("D_0035f254");
extern Ob* D_0035f250 asm("D_0035f250");
extern Sys* D_00347f80 asm("D_00347f80");
void func_00288b00(void*) asm("func_00288b00");
void func_00288c20(void*) asm("func_00288c20");
void func_002808e8(void) asm("func_002808e8");
void func_002808e8(void) {
    if (D_0035f25c) {
        El* e = D_0035f25c + ((s32*)D_0035f25c)[-1];
        for (;;) {
            if (D_0035f25c == e) break;
            --e;
            e->vt[3](e);
        }
        D_00347f80->heap->vt->free(D_00347f80->heap, (u8*)D_0035f25c - 4);
        D_0035f25c = 0;
    }
    if (D_0035f258) { D_0035f258->vt[4](D_0035f258); D_0035f258 = 0; }
    void* s = D_0035f254;
    if (s) { func_00288b00(s); func_00288c20(s); D_0035f254 = 0; }
    if (D_0035f250) { D_0035f250->vt[4](D_0035f250); D_0035f250 = 0; }
}
}  // namespace n002808e8

// 002809d8 (was src/anon/auto80_199_queue.cpp)
namespace n002809d8 {
/*TARGET 002809d8*/
void func_002809d8(u32 a0) asm("_Z13func_002809d8j");
void func_002809d8(u32 a0) {
    func_002593b8(5, a0);
    func_00102448(a0, 1);
    func_002806c8();
    func_00280a50();
    while (true) {
        func_00236d60();  // clear_64_entries_24
        if (func_00280c38() != 0) {
            break;
        }
        func_00280d40();
        func_00102448(a0, 0);
    }
}
}  // namespace n002809d8

// 00280a50 (was src/anon/batch_w1910.cpp)
namespace n00280a50 {
extern s32 D_0035f250 asm("D_0035f250");
extern s32 D_0035f254 asm("D_0035f254");
extern s32 D_0035f258 asm("D_0035f258");
extern u16 D_00374120[2][3] asm("D_00374120");
extern u16 D_00374148[] asm("D_00374148");
extern u16 D_00374150[] asm("D_00374150");
void func_0028d7f0(s32, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d7f0");
void func_0023ef50(s32) asm("func_0023ef50");
void func_0028d8c0(s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
s32 func_00103550(void) asm("func_00103550");
void func_00288d80(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("func_00288d80");
u8* func_002891b8(s32, s32) asm("func_002891b8");
void func_00139620(u8*) asm("func_00139620");
void func_0028af28(s32, s32) asm("func_0028af28");
void func_002891f0(s32, s32, s32, s32, s32) asm("func_002891f0");
static inline void setf8(u8* p) { *(u32*)(p + 184) |= 8; }
static inline void set432(u8* p, s32 v) { *(s32*)(p + 432) = v; }
/*TARGET 00280a50*/
void func_00280a50(void) asm("func_00280a50");
void func_00280a50(void) {
    s16 arr[2][4];
    s32 i, j, k;
    func_0028d7f0(D_0035f250, 30002, 0, 0, 0, -1, 0, 0, 0);
    func_0023ef50(D_0035f250);
    func_0028d8c0(D_0035f258, 30003, 1, 0, D_0035f250, 0, -1, 0);
    setf8((u8*)D_0035f258 + 24);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++)
            for (k = 0; k < 4; k++) arr[j][k] = D_00374120[j][i];
        u16* t = D_00374148;
        if (func_00103550() == 53) t = D_00374150;
        func_00288d80(D_0035f254, i, 1, 0, D_0035f250, t[i], arr[0], arr[1]);
        func_00139620(func_002891b8(D_0035f254, i));
        set432(func_002891b8(D_0035f254, i), 2);
    }
    func_0028af28(D_0035f254, 32);
    func_0028af28(D_0035f254, 64);
    func_002891f0(D_0035f254, 0, 1, 0, -1);
}
}  // namespace n00280a50

// 00280c38 (was src/anon/batch_w251.cpp)
namespace n00280c38 {
extern u32 D_0035f250 asm("D_0035f250");
extern u32 D_0035f254 asm("D_0035f254");
extern u32 D_0035f258 asm("D_0035f258");
extern u8 D_00374178[] asm("D_00374178");
struct F { u8 pad[3]; u8 b3; void (*fn)(void); };
s32 func_00287db0(void) asm("func_00287db0");
s32 func_00139d78(u32) asm("func_00139d78");
s32 func_0028acc8(u32) asm("func_0028acc8");
F* func_001040f8(void) asm("func_001040f8");
void func_001039f8(void) asm("func_001039f8");
s32 func_00289380(u32) asm("func_00289380");
s32 func_00289310(u32) asm("func_00289310");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00287da0(void) asm("func_00287da0");
/*TARGET 00280c38*/
s32 func_00280c38(void) asm("func_00280c38");
s32 func_00280c38(void)
{
    s32 r;
    if (func_00287db0()) {
        if (func_00139d78(D_0035f250)) { r = 0; goto out; }
        if (func_00139d78(D_0035f258)) { r = 0; goto out; }
        if (func_0028acc8(D_0035f254)) { r = 0; goto out; }
        func_001040f8()->fn();
        func_001039f8();
        r = 1;
    } else {
        s32 s = func_00289380(D_0035f254);
        if (func_00242848(func_00287df0(s, func_00289310(D_0035f254), 0, 0, 1))) { r = 0; goto out; }
        if (s != -1) {
        func_001040f8()->b3 = D_00374178[s];
        func_00287da0();
        }
        r = 0;
    }
out:
    return r;
}
}  // namespace n00280c38

// 00280d40 (was src/anon/batch_w98.cpp)
namespace n00280d40 {
s32 func_0028acc8(u8*) asm("func_0028acc8");
s32 func_00139d78(u8*) asm("func_00139d78");
// 0x00285e30: definition moved into src/anon/unit_002853b8.cpp

struct W280 { void** vt; u8 pad[432]; };
extern u8* D_0035f250 asm("D_0035f250");
extern u8* D_0035f258 asm("D_0035f258");
extern u8* D_0035f254 asm("D_0035f254");
extern W280* D_0035f25c asm("D_0035f25c");
s32 func_00287db0(void) asm("func_00287db0");
void func_0028abe0(u8*) asm("func_0028abe0");
s32 func_00289310(u8*) asm("func_00289310");
s32 func_002891e8(u8*) asm("func_002891e8");
void func_002890e0(u8*, s32, s32, s32, s32) asm("func_002890e0");
void func_00289038(u8*, s32, s32, s32, s32, s32, s32) asm("func_00289038");
/*TARGET 00280d40*/
// Closes the open sub-windows and resets the list cursor.
void func_00280d40(void) asm("func_00280d40");
// Closes the open sub-windows and resets the list cursor.
void func_00280d40(void) {
    if (func_00287db0()) {
        if (func_00139d78(D_0035f250)) (*(void (**)(u8*))(*(u8**)D_0035f250 + 20))(D_0035f250);
        if (func_00139d78(D_0035f258)) (*(void (**)(u8*))(*(u8**)D_0035f258 + 20))(D_0035f258);
        if (func_0028acc8(D_0035f254)) func_0028abe0(D_0035f254);
        for (s32 i = 0; i < 3; i++) {
            if (func_00139d78((u8*)&D_0035f25c[i])) (*(void (**)(W280*))((u8*)D_0035f25c[i].vt + 20))(&D_0035f25c[i]);
        }
    }
    if (func_00289310(D_0035f254)) {
        s32 s = func_002891e8(D_0035f254);
        func_002890e0(D_0035f254, 1, 2, 0, -1);
        func_00289038(D_0035f254, s, 1, 1, 2, 0, -1);
    }
}
}  // namespace n00280d40

// 00280e98 (was gap, written for the unit)
namespace n00280e98 {
u32 func_00280ef8(u32*, u32, u32, u32) asm("func_00280ef8");
u32 func_00280e98(u32* a0, u32 a1, u32 a2, u32 a3) asm("func_00280e98");
u32 func_00280e98(u32* a0, u32 a1, u32 a2, u32 a3) {
    *a0 = 0;
    return func_00280ef8(a0, a1, a2, a3);
}
}  // namespace n00280e98

// 00280eb0 (was src/anon/tiny_wrappers_more.cpp)
namespace n00280eb0 {
u32 func_00280ef8(u32, u32, u32, u32) asm("_Z13func_00280ef8jjjj");
/*TARGET 00280eb0*/
u32 func_00280eb0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00280eb0jjjj");
u32 func_00280eb0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)(0x00000000u);
    return func_00280ef8(a0, a1, a2, a3);
}
}  // namespace n00280eb0

// 00280ec8 (was src/anon/tiny.cpp)
namespace n00280ec8 {
void func_00281008(void*) asm("_Z13func_00281008Pv");
/*TARGET 00280ec8*/
void func_00280ec8(BD_VALUE* bd) asm("_Z13func_00280ec8P8BD_VALUE");
void func_00280ec8(BD_VALUE* bd) { func_00281008(bd); }
}  // namespace n00280ec8

// 00280ee0 (was src/anon/tiny.cpp)
namespace n00280ee0 {
void func_00281008(void*) asm("_Z13func_00281008Pv");
/*TARGET 00280ee0*/
void func_00280ee0(BD_VALUE* bd) asm("_Z13func_00280ee0P8BD_VALUE");
void func_00280ee0(BD_VALUE* bd) { func_00281008(bd); }
}  // namespace n00280ee0

// 00280ef8 (was src/anon/batch_w1597.cpp)
namespace n00280ef8 {
// 00280ef8: fill the 4 slots of a list object from key's entries; o->n = number of valid ones
struct W1597E20 { s16 id; s16 v; s16 w; s16 pad; s32 a; s32 b; s32 c; };
struct W1597C20 { s32 pad0; s16 id; s16 v; s16 w; s16 pad; s32 a; s32 b; s32 c[0]; };
union W1597KU { s32 v; s16 h; };
struct W1597Obj { s32 n; W1597E20 e[4]; W1597KU key; };
void func_002fde18(void*, s32, s32) asm("func_002fde18");
s32 func_001a8c10(s32, s32) asm("func_001a8c10");
s32 func_00281108(W1597Obj*, s32) asm("func_00281108");
s32 func_001b77a8(s32) asm("func_001b77a8");
s32 func_001a1658(s32, s32) asm("func_001a1658");
s32 func_001a8bf8(s32, s32) asm("func_001a8bf8");
void wtarget_00280ef8(W1597Obj* o, s32 key) asm("_Z16wtarget_00280ef8jjjj");
/*TARGET 00280ef8*/
void wtarget_00280ef8(W1597Obj* o, s32 key) asm("_Z16wtarget_00280ef8jjjj");
void wtarget_00280ef8(W1597Obj* o, s32 key)
{
    s32 n = 0;
    s32 i = 0;
    s32 w = 18;
    W1597C20* p = (W1597C20*)o;
    W1597C20* q = (W1597C20*)o;
    func_002fde18((u8*)o + 4, 0, 80);
    o->key.v = key;
    do {
        p->v = 0;
        p->w = w;
        q->id = i;
        p++;
        s32 v = func_001a8c10(o->key.v, i);
        q->v = v;
        if (v) {
            s32 b = func_00281108(o, i);
            q->b = b;
            if (b) {
                n++;
                q->a = func_001b77a8(v);
                q->c[0] = func_001a1658(v, 0);
                q->w = func_001a8bf8(key, i);
                q++;
            }
        }
        i++;
    } while (i < 4);
    o->n = n;
}
}  // namespace n00280ef8

// 00281008 (was src/anon/batch_w30.cpp)
namespace n00281008 {
void func_001a17c8(u32) asm("func_001a17c8");
void func_00281008_impl(void*) asm("_Z13func_00281008Pv");
/*TARGET 00281008*/
// 0x00174d98: definition moved into src/anon/unit_00171e58.cpp

void func_00281008_impl(void* p) asm("_Z13func_00281008Pv");
// 0x00174d98: definition moved into src/anon/unit_00171e58.cpp

void func_00281008_impl(void* p) {
    u32* e = (u32*)((u8*)p + 20);
    s32 i;
    for (i = 3; i >= 0; i--) {
        if (*e) func_001a17c8(*e);
        e += 5;
    }
}
}  // namespace n00281008

// 00281058 (was src/anon/auto80_199_queue.cpp)
namespace n00281058 {
/*TARGET 00281058*/
void func_00281058(u32 a0, s32 a1) asm("_Z13func_00281058ji");
void func_00281058(u32 a0, s32 a1) {
    s32 i = 0;
    do {
        if ((a1 < 0) || (i == a1)) {
            if (*(u32*)(a0 + 16) != 0) {
                func_001a1460(*(u32*)(a0 + 20));
            }
        }
        i += 1;
        a0 += 20;
    } while (i < 4);
}
}  // namespace n00281058

// 002810c8 (was src/anon/batch_w11.cpp)
namespace n002810c8 {
void func_00281008(void*, void*) asm("func_00281008");
void func_00280ef8(void*, void*) asm("func_00280ef8");
/*TARGET 002810c8*/
void func_002810c8(void* a, void* b) asm("func_002810c8");
void func_002810c8(void* a, void* b) {
    func_00281008(a, b);
    func_00280ef8(a, b);
}
}  // namespace n002810c8

// 00281100 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 00281100
/*TARGET 00281100*/
// 0x002595e0: definition moved into src/anon/unit_002588e8.cpp
s32 PartyInfo::GetPartyMax() { return reinterpret_cast<PartyInfoLayout*>(this)->partyMax; }
}  // Tz

// 00281108 (was src/anon/batch_w1.cpp)
namespace n00281108 {
void* func_00281238(void) asm("func_00281238");
void func_0016e920(void*) asm("func_0016e920");
/*TARGET 00281108*/
void func_00281108(void) asm("func_00281108");
void func_00281108(void) {
    func_0016e920(func_00281238());
}
}  // namespace n00281108

// 00281128 (was src/anon/tiny.cpp)
namespace n00281128 {
/*TARGET 00281128*/
// 00242408: moved to src/tozawa/crc.cpp (linked unit)

u32 func_00281128(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00281128jjjj");
// 00242408: moved to src/tozawa/crc.cpp (linked unit)

u32 func_00281128(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_entry20_field16
    (void)a2;
    (void)a3;
    return *(u32*)((u32)a0 + ((u32)a1 * (20)) + (16));
}
}  // namespace n00281128

// 00281140 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 00281140
/*TARGET 00281140*/
u32 PartyInfo::GetName(s32 index) {
    return *(u32*)((char*)this + ((u32)index * 20) + 12);
}
}  // Tz

// 00281158 (was src/anon/tiny_auto80_solver.cpp)
namespace n00281158 {
u32 func_001b77d0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001b77d0jjjjjjjj");
/*TARGET 00281158*/
u32 func_00281158(u32 a0, u32 a1) asm("_Z13func_00281158jj");
u32 func_00281158(u32 a0, u32 a1) {  // entry_short_at
    a1 *= 20;
    a1 += a0;
    return ((u32(*)(s32))func_001b77d0)(*(s16*)(a1 + 6));
}
}  // namespace n00281158

// 00281180 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 00281180
/*TARGET 00281180*/
u32 PartyInfo::GetSheet(s32 index) {
    return *(u32*)((char*)this + ((u32)index * 20) + 20);
}
}  // Tz

// 00281198 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 00281198
/*TARGET 00281198*/
s32 PartyInfo::GetParty(s32 index) {
    return (s32)(*(s16*)((char*)this + ((u32)index * 20) + 4));
}
}  // Tz

// 002811b0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002811b0 {
/*TARGET 002811b0*/
u32 func_002811b0(u32 a0, s32 a1) asm("_Z13func_002811b0ji");
u32 func_002811b0(u32 a0, s32 a1) {
    if (a1 < 0) {
        goto fail;
    }
    if (!(a1 < (s32)(*(u32*)a0))) {
        goto fail;
    }
    return (u32)(s32)(*(s16*)(a0 + (u32)(a1 * 20) + 6u));
fail:
    return 0u;
}
}  // namespace n002811b0

// 002811e0 (was src/anon/tiny_more2.cpp)
namespace n002811e0 {
/*TARGET 002811e0*/
u32 func_002811e0(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_002811e0jjjj");
u32 func_002811e0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; return (u32)(s32)(*(s16*)((u32)a0 + ((u32)a1 * (20)) + (8))); }
}  // namespace n002811e0

// 002811f8 (was src/anon/batch_w22.cpp)
namespace n002811f8 {
// --- 002811f8
// Index of the entry with the given id, or -1.
struct E281 { s16 id; s16 pad; u32 x[4]; };
struct T281 { s32 n; E281 e[1]; };
/*TARGET 002811f8*/
s32 func_002811f8(T281* t, s32 key) asm("func_002811f8");
s32 func_002811f8(T281* t, s32 key) {  // find_halfword_index
    s32 i;
    for (i = 0; i < t->n; i++) {
        if (t->e[i].id == key) break;
    }
    if (i < t->n) return i;
    return -1;
}
}  // namespace n002811f8

// 00281238 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 00281238
u32 func_001a8bd0(...) asm("func_001a8bd0");
u32 func_001a8bf8(...) asm("func_001a8bf8");
// get_bits5_at
extern u32 D_00374190 asm("D_00374190");
/*TARGET 00281238*/
u32 PartyInfo::GetEntryId(s32 index) {
    u32 i = 0;
    while (true) {
        u32 t = func_001a8bd0(-1);
        u32 l = func_001a8bf8(t, i);  // get_bits5_at
        u32 r = func_001a8bf8(*(u32*)((u32)this + 84), (u32)index);  // get_bits5_at
        if (l == r) {
            break;
        }
        i += 1;
        if ((s32)i >= 4) {
            break;
        }
    }
    return ((u32*)&D_00374190)[i];
}
}  // Tz

// 002812c8 (was src/anon/tiny_more2.cpp)
namespace n002812c8 {
extern u32 D_00374190 asm("D_00374190");
/*TARGET 002812c8*/
u32 func_002812c8(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_002812c8jjjj");
u32 func_002812c8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u32*)((u32)&D_00374190 + ((u32)a0 << 2) + (0)); }
}  // namespace n002812c8

// 002812e0 (was src/anon/batch_w36.cpp)
namespace n002812e0 {
u8* func_001058e8(void) asm("func_001058e8");
extern s8 D_00374188[] asm("D_00374188");
/*TARGET 002812e0*/
// 0x002637e8: definition moved into src/anon/unit_002632d0.cpp

// Is the current id in the -1-terminated table?
s32 func_002812e0(void) asm("func_002812e0");
// 0x002637e8: definition moved into src/anon/unit_002632d0.cpp

// Is the current id in the -1-terminated table?
s32 func_002812e0(void) {
    s32 r = 0;
    u8 c = func_001058e8()[12];
    s32 i;
    for (i = 0; D_00374188[i] >= 0; i++) {
        if (D_00374188[i] == c) {
            r = 1;
            break;
        }
    }
    return r;
}
}  // namespace n002812e0

// 00281340 (was src/anon/tiny_auto80_queue.cpp)
namespace n00281340 {
u32 func_001a3570(...) asm("func_001a3570");
u32 func_001a36e0(...) asm("func_001a36e0");
u32 func_002812e0(...) asm("func_002812e0");
/*TARGET 00281340*/
u32 func_00281340(u32 a0) asm("_Z13func_00281340j");
u32 func_00281340(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002812e0)(r4);
    r4 = r16;
    r15 = 0u;
    if (r2 == 0u) {
        r2 = ((u32(*)(u32))func_001a36e0)(r4);
        r4 = r2;
        r2 = ((u32(*)(u32))func_001a3570)(r4);
        r15 = ((u32)0u < (u32)r2);
    }
    r2 = r15;
    return r2;
}
}  // namespace n00281340

// 00281388 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 00281388
/*TARGET 00281388*/
u32 PartyInfo::isDoubleWeaponForm(s32 index) {
    u32 v0 = 0u;
    if ((u32)index == 1u || (u32)index == 4u || (u32)index == 5u) {
        v0 = 1u;
    }
    return v0;
}
}  // Tz

// 002813b8 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 002813b8
u32 func_00281340(...) asm("func_00281340");
/*TARGET 002813b8*/
u32 PartyInfo::GetAllHaveForm() {
    u32 mask = 0;
    for (s32 i = 0; i < 7; i++) {
        if (i != 0) {
            if (func_00281340((u32)i) != 0) {
                mask |= (1u << (u32)i);
            }
        }
    }
    return mask;
}
}  // Tz

// 00281420 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 00281420
u32 PartyInfo::isDoubleWeaponForm(s32 index) asm("_ZN2Tz9PartyInfo18isDoubleWeaponFormEi");
/*TARGET 00281420*/
u32 PartyInfo::GetAllDoubleWeaponForm() {
    u32 mask = 0;
    for (s32 i = 0; i < 7; i++) {
        if (isDoubleWeaponForm(i) != 0) {
            mask |= (1u << (u32)i);
        }
    }
    return mask;
}
}  // Tz

// 00281480 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 00281480
/*TARGET 00281480*/
u32 PartyInfo::isSora(s32 index) {
    u32 t6 = *(u32*)((char*)this + ((u32)index * 20) + 16);
    u32 v0 = 0u;
    if (t6 != 0u) {
        v0 = (u32)(*(u16*)(t6 + 76u) == 1u);
    }
    return v0;
}
}  // Tz

// 002814b0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002814b0 {
u32 func_001058e8(...) asm("func_001058e8");
u32 func_00189200(...) asm("func_00189200");
/*TARGET 002814b0*/
u32 func_002814b0(u32 a0, u32 a1) asm("_Z13func_002814b0jj");
u32 func_002814b0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_001058e8)(r4, r5);
    r4 = (u32)((s32)r2 + (9456));
    r5 = r16;
    r2 = ((u32(*)(u32,u32))func_00189200)(r4, r5);
    r15 = 0u;
    if (r2 != 0u) {
        r15 = (u32)(*(u16*)((u32)r2 + (s32)(0)));
    }
    r2 = r15;
    return r2;
}
}  // namespace n002814b0

// 002814f0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002814f0 {
u32 func_00189200(...) asm("func_00189200");
u32 func_001058e8(...) asm("func_001058e8");
/*TARGET 002814f0*/
void func_002814f0(u32 a0, u32 a1) asm("_Z13func_002814f0jj");
void func_002814f0(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 p = func_00189200((void*)(func_001058e8() + 9456u), s0);
    if (p != 0u) {
        *(u16*)p = (u16)s1;
    }
}
}  // namespace n002814f0

// 00281538 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 00281538
u32 PartyInfo::GetEntryId(s32 index) asm("_ZN2Tz9PartyInfo10GetEntryIdEi");
u32 func_00281180(...) asm("func_00281180");
u32 func_00281198(...) asm("func_00281198");
u32 func_00281128(...) asm("func_00281128");
// get_entry20_field16
extern "C" u32 func_001a9758(...) asm("func_001a9758");
/*TARGET 00281538*/
u32 PartyInfo::isLoadObj(s32 index) {
    u32 ok = func_00281180((u32)this, (u32)index);
    u32 out = 0;
    if (ok != 0) {
        u32 t = func_00281198((u32)this, (u32)index);
        u32 obj = GetEntryId((s32)t);
        u32 tmp = func_00281128((u32)this, (u32)index);  // get_entry20_field16
        (void)tmp;
        out = func_001a9758(obj, 0);
    }
    return out;
}
}  // Tz

// 002815b8 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 002815b8
u32 func_001058e8(...) asm("func_001058e8");
/*TARGET 002815b8*/
u32 PartyInfo::GetNowForm() {
    u32 r2 = func_001058e8();
    r2 = (u32)(*(u8*)((u32)r2 + (s32)(13604)));
    return r2;
}
}  // Tz

// 002815d8 (was src/anon/batch_w1825_nsa.cpp)
namespace n002815d8 {
struct W1825Heap;
struct W1825HeapVt { u8* (*alloc)(W1825Heap*, s32, s32); };
struct W1825Heap { W1825HeapVt* vt; };
struct W1825Sys { u8 pad[20]; W1825Heap* heap; };
extern u8* D_00347f80 asm("D_00347f80");
#define SYS ((W1825Sys*)D_00347f80)
extern u8 D_00347e60[] asm("D_00347e60");
extern u8* D_0035f288 asm("D_0035f288");
extern u8* D_0035f28c asm("D_0035f28c");
extern u8* D_0035f290 asm("D_0035f290");
extern u8* D_0035f29c asm("D_0035f29c");
extern s16 D_0035f280 asm("D_0035f280");
extern s8 D_0035f299 asm("D_0035f299");
extern s32 D_0035f274 asm("D_0035f274");
extern s32 D_0035f270 asm("D_0035f270");
extern s32 D_0035f278 asm("D_0035f278");
extern s32 D_0035f27c asm("D_0035f27c");
extern s32 D_0035f284 asm("D_0035f284");
void func_00239700(u8*) asm("func_00239700");
u32 func_00103570() asm("func_00103570");
u8* func_001063c0(s32, u32) asm("func_001063c0");
void func_002361a0(u8*) asm("func_002361a0");
void func_002817b8() asm("func_002817b8");
static inline __attribute__((always_inline)) u8* w1825_mk() {
    u8* a = SYS->heap->vt->alloc(SYS->heap, 408, 0);
    *(u8**)a = D_00347e60;
    *(u32*)(a + 12) = 0;
    func_00239700(a + 24);
    return a;
}
/*TARGET 002815d8*/
void func_002815d8(void) asm("func_002815d8");
void func_002815d8(void)
{
    u8* a; u8* c;
    D_0035f288 = w1825_mk();
    D_0035f28c = D_0035f288;
    D_0035f290 = w1825_mk();
    c = func_001063c0(416, func_00103570());
    func_002361a0(c);
    D_0035f29c = c;
    D_0035f280 = D_0035f27c = D_0035f278 = D_0035f270 = D_0035f274 = -1;
    D_0035f299 = 1;
    D_0035f284 = 0;
    func_002817b8();
}
}  // namespace n002815d8

// 002816f0 (was src/anon/batch_w87.cpp)
namespace n002816f0 {
// ---- 0x2816f0: reset state and release three owned objects ----
typedef void (*VFn)(void*);
extern s16 D_0035f280 asm("D_0035f280");
extern s32 D_0035f274 asm("D_0035f274");
extern u8 D_0035f299 asm("D_0035f299");
extern s32 D_0035f270 asm("D_0035f270");
extern s32 D_0035f278 asm("D_0035f278");
extern s32 D_0035f27c asm("D_0035f27c");
extern s32 D_0035f284 asm("D_0035f284");
extern void* D_0035f288 asm("D_0035f288");
extern void* D_0035f290 asm("D_0035f290");
extern void* D_0035f29c asm("D_0035f29c");
/*TARGET 002816f0*/
void func_002816f0(void) asm("func_002816f0");
void func_002816f0(void) {
    D_0035f274 = -1;
    D_0035f270 = -1;
    D_0035f278 = -1;
    D_0035f27c = -1;
    D_0035f280 = -1;
    D_0035f284 = 0;
    D_0035f299 = 1;
    if (D_0035f288) {
        (*(VFn*)((*(u8**)D_0035f288) + 16))(D_0035f288);
        D_0035f288 = 0;
    }
    if (D_0035f290) {
        (*(VFn*)((*(u8**)D_0035f290) + 16))(D_0035f290);
        D_0035f290 = 0;
    }
    if (D_0035f29c) {
        (*(VFn*)((*(u8**)D_0035f29c) + 4))(D_0035f29c);
        D_0035f29c = 0;
    }
}
}  // namespace n002816f0

// 002817b8 (was src/anon/tiny_auto80_solver.cpp)
namespace n002817b8 {
void func_002817b8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002817b8jjjjjjjj");
extern u8 D_00360000 asm("D_00360000");
/*TARGET 002817b8*/
void func_002817b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002817b8jjjjjjjj");
void func_002817b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    *(u16*)((u32)&D_00360000 - 3456) = (u16)-1;
    *(u32*)((u32)&D_00360000 - 3436) = 0u;
    *(u8*)((u32)&D_00360000 - 3432) = 0u;
}
}  // namespace n002817b8

// 002817d8 (was src/anon/batch_w86.cpp)
namespace n002817d8 {
extern s32 D_0035f270 asm("D_0035f270");
extern s32 D_0035f274 asm("D_0035f274");
extern s32 D_0035f278 asm("D_0035f278");
extern s32 D_0035f27c asm("D_0035f27c");
extern s32 D_0035f284 asm("D_0035f284");
extern s32 D_0035f288 asm("D_0035f288");
extern s32 D_0035f28c asm("D_0035f28c");
extern u8 D_0035f299 asm("D_0035f299");
extern u16 D_0035f2a0[3] asm("D_0035f2a0");
extern u16 D_0035f2a8[2] asm("D_0035f2a8");
extern u16 D_003741a8[] asm("D_003741a8");
/*TARGET 002817d8*/
void func_002817d8(s32 a, s32 b, s32 c, s32 d, s32 e, u16* f, u16* g) asm("func_002817d8");
void func_002817d8(s32 a, s32 b, s32 c, s32 d, s32 e, u16* f, u16* g)
{
    D_0035f270 = a;
    D_0035f278 = b;
    D_0035f27c = c;
    D_0035f284 = d;
    D_0035f274 = e;
    if (f) {
        D_0035f28c = D_0035f288;
        D_0035f299 = 1;
    } else {
        D_0035f28c = 0;
        D_0035f299 = 0;
    }
    for (s32 i = 0; i < 3; i++) D_0035f2a0[i] = f ? f[i] : 0xffff;
    if (!g) g = D_003741a8;
    for (s32 i = 0; i < 2; i++) D_0035f2a8[i] = g[i];
}
}  // namespace n002817d8

// 002818b8 (was src/anon/batch_w2050_nsa.cpp)
namespace n002818b8 {
typedef void (*VFn_w2050b)(void*);
s32 func_00281be0(void) asm("func_00281be0");
s32 func_00139d78(s32) asm("func_00139d78");
void func_0028d8c0(s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
s32 func_001b1e70(void) asm("func_001b1e70");
s32 func_00293148(s32) asm("func_00293148");
void func_002362b0(u8*, s32) asm("func_002362b0");
void func_001386e0(u8*, s32, s32, u8*, s32, s32) asm("func_001386e0");
s32 func_0023aa98(s32) asm("func_0023aa98");
s32 func_0023f1b0(s32) asm("func_0023f1b0");
s32 func_0023c3e0(s32, s32, s32) asm("func_0023c3e0");
void func_001396b0(u8*) asm("func_001396b0");
void func_0031a260(u8*, s32) asm("func_0031a260");
void func_0031ac78(u8*, s32) asm("func_0031ac78");
u64 func_00313b80(f32) asm("func_00313b80");
u64 func_00314190(u64, u64)  asm("func_00314190")__attribute__((const));
f32 __truncdfsf2(u64) asm("__truncdfsf2");
extern s32 D_0035f270 asm("D_0035f270");
extern s32 D_0035f274 asm("D_0035f274");
extern s32 D_0035f278 asm("D_0035f278");
extern s32 D_0035f27c asm("D_0035f27c");
extern s32 D_0035f284 asm("D_0035f284");
extern s32 D_0035f28c asm("D_0035f28c");
extern u8* D_0035f290 asm("D_0035f290");
extern u8* D_0035f29c asm("D_0035f29c");
extern s16 D_0035f2a0[3] asm("D_0035f2a0");
extern s16 D_0035f2a8[2] asm("D_0035f2a8");
/*TARGET 002818b8*/
void func_002818b8(s32 arg0) asm("func_002818b8");
void func_002818b8(s32 arg0) {
    s32 n;
    u8* o;
    if (func_00281be0() != 0) {
        (*(VFn_w2050b*)(*(u8**)D_0035f290 + 0x14))(D_0035f290);
        return;
    }
    if (D_0035f274 == 0 && func_00139d78(D_0035f28c) == 0) {
        func_0028d8c0(D_0035f28c, D_0035f270, D_0035f278, D_0035f27c, D_0035f284, D_0035f2a0[0], D_0035f2a0[2], 0);
    }
    s32 r = func_001b1e70();
    func_002362b0(D_0035f29c, func_00293148(arg0));
    D_0035f29c[0x190] = 1;
    func_001386e0(D_0035f290, D_0035f270, r, D_0035f29c, D_0035f2a8[0], 0);
    if (D_0035f274 == 0) {
        n = func_0023aa98(D_0035f28c + 0x18);
        u8* p = D_0035f290;
        *(s32*)(p + 0x18c) = D_0035f28c;
        func_001396b0(p);
        if (*(s32*)(p + 0x18c) != 0) {
            *(s32*)(p + 0x190) = 0;
            func_001396b0(p);
            if (*(s32*)(p + 0x190) != 0) func_0031a260(p, 0);
        }
    } else {
        n = func_0023aa98(func_0023c3e0(func_0023f1b0(D_0035f284), D_0035f2a0[2], 0));
        o = D_0035f290;
        *(s32*)(o + 0x190) = func_0023c3e0(func_0023f1b0(D_0035f284), D_0035f2a0[2], 0);
        func_001396b0(o);
        if (*(s32*)(o + 0x190) != 0) {
            *(s32*)(o + 0x18c) = 0;
            func_001396b0(o);
            if (*(s32*)(o + 0x18c) != 0) func_0031ac78(o, 0);
        }
    }
    if (n <= 0) n = 100;
    u8* s = D_0035f290 + 0x18;
    *(u32*)(s + 0xb8) |= 8;
    u64 d = func_00313b80((f32)n);
    u8* q = D_0035f290;
    *(f32*)(q + 0x180) = __truncdfsf2(func_00314190(d, 0x4059000000000000ULL));
    D_0035f290[0x195] = 1;
    func_001396b0(D_0035f290);
}
}  // namespace n002818b8

// 00281b30 (was src/anon/batch_wcx.cpp)
namespace n00281b30 {
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
// Tz::CmItem::FadeOutHelp
extern u8 D_0035f299 asm("D_0035f299");
extern u32 D_0035f274 asm("D_0035f274");
extern u8* D_0035f28c asm("D_0035f28c");
extern u8* D_0035f290 asm("D_0035f290");
extern s16 D_0035f2a2 asm("D_0035f2a2");
extern s16 D_0035f2aa asm("D_0035f2aa");
extern s16 D_0035f280 asm("D_0035f280");
void func_0028dac8(u8*, s32) asm("func_0028dac8");
s32 func_00281c30(void) asm("func_00281c30");
void CmItem_FadeOutHelp(void) asm("_ZN2Tz6CmItem11FadeOutHelpEv");
/*TARGET 00281b30*/
void CmItem_FadeOutHelp(void) asm("_ZN2Tz6CmItem11FadeOutHelpEv");
void CmItem_FadeOutHelp(void)
{
    if (D_0035f299 && !D_0035f274 && u_call4_00139d78(D_0035f28c) && *(s32*)(D_0035f28c + 388) != D_0035f2a2) {
        func_0028dac8(D_0035f28c, D_0035f2a2);
        D_0035f280 = -1;
    }
    if (func_00281c30() && *(s32*)(D_0035f290 + 388) != D_0035f2aa) {
        func_0028dac8(D_0035f290, D_0035f2aa);
        D_0035f280 = -1;
    }
}
}  // namespace n00281b30

// 00281be0 (was src/anon/tiny_auto80_queue.cpp)
namespace n00281be0 {
extern u32 D_0035f274 asm("D_0035f274");
extern u32 D_0035f28c asm("D_0035f28c");
extern u8  D_0035f299 asm("D_0035f299");
u32 func_00281c30(...) asm("func_00281c30");
u32 func_00139d78(...) asm("func_00139d78");
/*TARGET 00281be0*/
u32 func_00281be0() asm("_Z13func_00281be0v");
u32 func_00281be0() {
    u32 v0 = 0u;
    if (*(u32*)(u32)&D_0035f274 == 0u) {
        if (*(u8*)(u32)&D_0035f299 != 0u) {
            v0 = func_00139d78((void*)(*(u32*)(u32)&D_0035f28c));
        }
    }
    if (v0 == 0u) {
        v0 = func_00281c30();
    }
    return v0;
}
}  // namespace n00281be0

// 00281c30 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00281c30 {
u32 func_00139d78(u32, u32, u32, u32) asm("_Z13func_00139d78jjjj");
/*TARGET 00281c30*/
u32 func_00281c30(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00281c30jjjj");
u32 func_00281c30(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)(0x0036u << 16);
    r4 = *(u32*)((u32)r15 + (s32)(-3440));
    u32 (*fp_call4_00139d78)(u32, u32, u32, u32) = func_00139d78;
    r2 = fp_call4_00139d78(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00281c30

// 00281c50 (was src/anon/batch_w67.cpp)
namespace n00281c50 {
typedef void (*VFn)(void*);
s32 func_00139d78(void*) asm("func_00139d78");
extern u32 D_0035f274 asm("D_0035f274");
extern u8 D_0035f299 asm("D_0035f299");
extern void* D_0035f28c asm("D_0035f28c");
extern void* D_0035f290 asm("D_0035f290");
extern s16 D_0035f280 asm("D_0035f280");
extern u32 D_0035f294 asm("D_0035f294");
extern u8 D_0035f298 asm("D_0035f298");
void cmItemLeavePopup(void) asm("_ZN2Tz6CmItem10LeavePopupEv");
/*TARGET 00281c50*/
void cmItemLeavePopup(void) asm("_ZN2Tz6CmItem10LeavePopupEv");
void cmItemLeavePopup(void)
{
    if (!D_0035f274 && D_0035f299) {
        if (func_00139d78(D_0035f28c)) (*(VFn*)(*(u8**)D_0035f28c + 20))(D_0035f28c);
    }
    if (func_00139d78(D_0035f290)) (*(VFn*)(*(u8**)D_0035f290 + 20))(D_0035f290);
    D_0035f280 = -1;
    D_0035f294 = 0;
    D_0035f298 = 0;
}
}  // namespace n00281c50

