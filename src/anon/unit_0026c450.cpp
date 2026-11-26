// Linked unit 0x0026c450-0x0026ee78 (one namespace per old matched source; class methods in their own namespace).
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

// 0026c450 (was src/anon/batch_w5.cpp)
namespace n0026c450 {
u32 func_00287dc0(void) asm("func_00287dc0");
void func_0023d820(u32) asm("func_0023d820");
/*TARGET 0026c450*/
void func_0026c450(void) asm("func_0026c450");
void func_0026c450(void) {
    func_0023d820(func_00287dc0());
}
}  // namespace n0026c450

// 0026c470 (was src/anon/batch_w120.cpp)
namespace n0026c470 {
s32 func_00289380(u32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287f90(s32) asm("func_00287f90");
void func_00287c30(void) asm("func_00287c30");
s32 func_00289310(u32) asm("func_00289310");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00287da0(void) asm("func_00287da0");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
// global_zero_4dwords
void func_0028f6f0(s32) asm("func_0028f6f0");
void func_00287c00(s32) asm("func_00287c00");
void func_00287cc0(s32) asm("func_00287cc0");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f024 asm("D_0035f024");
extern u8 D_0035f0f0 asm("D_0035f0f0");
s32 func_002938e0(void) asm("func_002938e0");
s32 func_002938f0(void) asm("func_002938f0");
void func_0026c140(void) asm("func_0026c140");
s32 func_00287dc0(void) asm("func_00287dc0");
s32 func_0026cda0(void) asm("func_0026cda0");
s32 func_00139d78(s32) asm("func_00139d78");
s32 func_0028f930(s32) asm("func_0028f930");
void func_0026cc30(void) asm("func_0026cc30");
void func_0028b1e8(u32, s32) asm("func_0028b1e8");
void func_0028f7e8(s32) asm("func_0028f7e8");
void func_00257708(s32) asm("func_00257708");
void func_002551b8(void) asm("func_002551b8");
void func_0026d828(void) asm("func_0026d828");
s32 func_0026d560(void) asm("func_0026d560");
void func_0026d5c0(void) asm("func_0026d5c0");
void func_0028fa98(s32) asm("func_0028fa98");
s32 func_0028afa8(u32) asm("func_0028afa8");
void func_0026d960(void) asm("func_0026d960");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_0026c760(void) asm("func_0026c760");
void func_0023d820(s32) asm("func_0023d820");
void func_00288e88(u32) asm("func_00288e88");
void func_00263c60(void) asm("func_00263c60");
// sync_global_index_if_changed
void func_0026cb90(void) asm("func_0026cb90");
/*TARGET 0026c470*/
void func_0026c470(void) asm("func_0026c470");
void func_0026c470(void)
{
    s32 sel = func_00289380(D_0035f01c);
    s32 st = func_00287cd0();
    if (st != 2 && func_002938e0() && func_002938f0() && D_0035f0f0) func_0026c140();
    if (func_00287bc0() != 20) return;
    s32 item = func_00287dc0();
    if (st == 2) {
        if (func_0026cda0() || func_00139d78(item) || func_0028f930(0)) {
            if (sel != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                func_0026cc30();
            }
            return;
        }
        func_0028b1e8(D_0035f024, 0);
        func_00287c30();
        func_0028f7e8(0);
        func_00257708(0);
        func_002551b8();
        func_0026d828();
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f01c)) && !func_0026d560()) {
        func_0026d5c0();
        func_0028fa98(-1);
    }
    if (st == 0 && func_0026d560()) func_00287c90(1);
    s32 n = func_0028afa8(D_0035f01c);
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f01c), 1, (s32)func_0026d960, 1)) == 0) {
        switch (sel) {
        case -1: break;
        case -4:
            func_00287da0();
            if (func_002938e0() && !func_002938f0()) func_0023d820(item);
            break;
        case -2:
            func_00288e88(D_0035f024);
            func_00263c60();  // sync_global_index_if_changed
            func_0028f6f0(0);  // record884_refresh_by_index
            func_0026cb90();
            func_00287cc0(2);
            func_00287c00(0);
            if (func_002938e0() && !func_002938f0()) func_0023d820(item);
            break;
        default:
            if (sel >= 0 && sel < n) {
                func_00287bd0(22, 0);
                func_0026c760();
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0026c470

// 0026c760 (was src/anon/batch_wcx.cpp)
namespace n0026c760 {
s32 func_002891e8(u8*) asm("func_002891e8");
s32 func_002892f8(u8*) asm("func_002892f8");
extern u8* D_0035f01c asm("D_0035f01c");
extern u8* D_0035f024 asm("D_0035f024");
u32 func_0028b1b8(u8*) asm("func_0028b1b8");
void func_0028b1b0(u8*, u32) asm("func_0028b1b0");
s32 func_0028b1c0(u8*, s32) asm("func_0028b1c0");
// test_bit_field32
void func_002891f0(u8*, s32, s32, s32, s32) asm("func_002891f0");
void func_00287cc0(s32) asm("func_00287cc0");
void func_0026cb38(void) asm("func_0026cb38");
/*TARGET 0026c760*/
void func_0026c760(void) asm("func_0026c760");
void func_0026c760(void)
{
    s32 j = 1;
    s32 i = func_002891e8(D_0035f01c);
    j = (j << i) | func_0028b1b8(D_0035f01c);
    func_0028b1b0(D_0035f024, j);
    j = i + 1;
    if (!(j < func_002892f8(D_0035f024)) || func_0028b1c0(D_0035f024, j)) j = i - 1;
    func_002891f0(D_0035f024, j, 0, -1, -1);
    func_00287cc0(0);
    func_0026cb38();
}
}  // namespace n0026c760

// 0026c818 (was src/anon/batch_w111.cpp)
namespace n0026c818 {
extern void* D_0035f024 asm("D_0035f024");
extern u8 D_0035f0f0 asm("D_0035f0f0");
s32 func_00289380(void*) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_002938e0(void) asm("func_002938e0");
s32 func_002938f0(void) asm("func_002938f0");
void func_0026c140(void) asm("func_0026c140");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
void func_0026cb38(void) asm("func_0026cb38");
void func_00287c90(s32) asm("func_00287c90");
s32 func_002892f8(void*) asm("func_002892f8");
s32 func_00289310(void*) asm("func_00289310");
s32 func_00287df0(s32, s32, s32, void (*)(void), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_0026d748(void) asm("func_0026d748");
void func_00287da0(void) asm("func_00287da0");
s32 func_00287dc0(void) asm("func_00287dc0");
void func_0023d820(s32) asm("func_0023d820");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
// global_zero_4dwords
void func_0026d960(void) asm("func_0026d960");
/*TARGET 0026c818*/
// Menu update for this list: close handling, cursor feedback and entry dispatch.
void func_0026c818(void) asm("func_0026c818");
// Menu update for this list: close handling, cursor feedback and entry dispatch.
void func_0026c818(void)
{
    s32 sel = func_00289380(D_0035f024);
    s32 st = func_00287cd0();
    if (func_002938e0() && func_002938f0() && D_0035f0f0) func_0026c140();
    if (st == 2) {
        func_00287bd0(20, 0);
        func_00287cc0(1);
        func_0026cb38();
        return;
    }
    if (st == 0) func_00287c90(1);
    s32 n = func_002892f8(D_0035f024);
    if (!func_00242848(func_00287df0(sel, func_00289310(D_0035f024), 1, func_0026d960, 1))) {
        switch (sel) {
        case -2:
            func_00287c90(1);
            break;
        case -4:
            func_00287da0();
            if (func_002938e0() && !func_002938f0()) func_0023d820(func_00287dc0());
            break;
        case -1:
            break;
        default:
            if (sel >= 0 && sel < n) {
                func_0026d748();
                func_00287c90(1);
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0026c818

// 0026c9c8 (was src/anon/batch_w5.cpp)
namespace Tz { // method 0026c9c8
// namespace YS

extern "C" void func_0026bc10(void) asm("func_0026bc10");
void func_00257708(u32) asm("func_00257708");
void func_0026ceb0(void) asm("func_0026ceb0");
/*TARGET 0026c9c8*/
void Tz_CmParty_CreateInfo() asm("_ZN2Tz7CmParty10CreateInfoEv");
void Tz_CmParty_CreateInfo() {
    func_0026bc10();
    func_00257708(0);
    func_0026ceb0();
}
}  // Tz

// 0026c9f0 (was src/anon/batch_w446.cpp)
namespace n0026c9f0 {
extern s32 D_0035f024 asm("D_0035f024");
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
void func_0026c470(void) asm("func_0026c470");
s32 func_0026d180(void) asm("func_0026d180");
void func_00287c30(void) asm("func_00287c30");
void func_0026c048(void) asm("func_0026c048");
void func_0028af18(s32, s32) asm("func_0028af18");
s32 func_00257610(s32) asm("func_00257610");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00289310(s32) asm("func_00289310");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_0026d168(void) asm("func_0026d168");
void func_00287c00(s32) asm("func_00287c00");
/*TARGET 0026c9f0*/
void func_0026c9f0(void) asm("func_0026c9f0");
void func_0026c9f0(void) {
    s32 a = func_00289380(D_0035f024);
    s32 b = func_00287cd0();
    func_0026c470();
    if (b == 2) {
        if (func_0026d180() == 0) {
            func_00287c30();
            func_0026c048();
            func_0028af18(D_0035f024, 115);
        }
        return;
    }
    if (b == 0) {
        if (func_00257610(1)) func_00287c90(1);
    }
    if (b != 1) return;
    if (func_00242848(func_00287df0(a, func_00289310(D_0035f024), 0, 0, 1))) return;
    if (a == -2) goto L;
    if (a < -1) return;
    if (a == -1) return;
    if (a != 0) return;
L:
        func_0026d168();
        func_00287c00(20);
        func_00287c90(1);
}
}  // namespace n0026c9f0

// 0026cb38 (was src/anon/auto80_199_queue.cpp)
namespace n0026cb38 {
/*TARGET 0026cb38*/
u32 func_0026cb38() asm("_Z13func_0026cb38v");
u32 func_0026cb38() {
    u32 a0 = 0x846C;
    if (func_00287bc0() == 20) {
        if ((s32)func_002892f8(D_0035f01c) < 3) {
            a0 = D_00373838;
        } else {
            a0 = D_00373834;
        }
    }
    return func_00263a58(a0, 1);
}
}  // namespace n0026cb38

// 0026cb90 (was src/anon/auto80_199_queue.cpp)
namespace n0026cb90 {
/*TARGET 0026cb90*/
void func_0026cb90() asm("_Z13func_0026cb90v");
void func_0026cb90() {
    u32 v = func_00287bc0();
    if (v == 20 || v == 22) {
        u32 h = func_00256b68(1);
        func_0028dac8(h, 314);

        if (func_0028acc8(D_0035f01c) != 0) {
            if (func_0028acb8(D_0035f01c) == 0) {
                func_0028aa40(D_0035f01c);
            }
        }

        if (func_0028acc8(D_0035f024) != 0) {
            func_00288e88(D_0035f024);
        }
    }
}
}  // namespace n0026cb90

// 0026cc30 (was src/anon/batch_w1601.cpp)
namespace n0026cc30 {
// 0028f280: moved to src/anon/unit_0028f1e0.cpp

// ---- g1.cpp
typedef void (*VFn26cc30)(u8*);
#define VCALL26cc30(p) (*(VFn26cc30*)(*(u8**)(p) + 20))(p)
extern u8* D_0035f0f4 asm("D_0035f0f4");
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f024 asm("D_0035f024");
s32 func_00287bc0(void) asm("func_00287bc0");
u8* func_00256b68(s32) asm("func_00256b68");
s32 func_00139d78(u8*) asm("func_00139d78");
void func_00139510(u8*) asm("func_00139510");
s32 func_0028acc8(s32) asm("func_0028acc8");
void func_0028abe0(s32) asm("func_0028abe0");
void func_00288e88(s32) asm("func_00288e88");
void func_0026c450(void) asm("func_0026c450");
void func_0026d828(void) asm("func_0026d828");
void Tz_CmParty_LeaveList_26cc30(void) asm("_ZN2Tz7CmParty9LeaveListEv");
/*TARGET 0026cc30*/
void Tz_CmParty_LeaveList_26cc30(void) asm("_ZN2Tz7CmParty9LeaveListEv");
void Tz_CmParty_LeaveList_26cc30(void)
{
    s32 i;
    if (func_00287bc0() == 20) {
        u8* o = func_00256b68(1);
        if (func_00139d78(o)) VCALL26cc30(o);
        if (func_00139d78(D_0035f0f4)) func_00139510(D_0035f0f4);
        for (i = 0; i < 4; i++) {
            if (func_00139d78(D_0035f0f4 + i * 408 + 408)) VCALL26cc30(D_0035f0f4 + i * 408 + 408);
        }
        for (i = 0; i < 4; i++) {
            if (func_00139d78(D_0035f0f4 + i * 436 + 2040)) VCALL26cc30(D_0035f0f4 + i * 436 + 2040);
        }
        if (func_0028acc8(D_0035f01c)) func_0028abe0(D_0035f01c);
        if (func_0028acc8(D_0035f024)) func_00288e88(D_0035f024);
        func_0026c450();
        func_0026d828();
    }
}
}  // namespace n0026cc30

// 0026cda0 (was src/anon/batch_w95.cpp)
namespace n0026cda0 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& s) {
        if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq operator*(const Vq& a, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
struct MPartA { u8 d[408]; };
struct MPartB { u8 d[436]; };
struct MenuParts { MPartA a[5]; MPartB b[4]; };
extern MenuParts* D_0035f0f4 asm("D_0035f0f4");
extern u32 D_0035f01c asm("D_0035f01c");
u8* func_00256b68(u32) asm("func_00256b68");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028acc8(u32) asm("func_0028acc8");
/*TARGET 0026cda0*/
// Non-zero while any of the menu's animated parts is still busy.
s32 func_0026cda0(void) asm("func_0026cda0");
// Non-zero while any of the menu's animated parts is still busy.
s32 func_0026cda0(void) {
    s32 i;
    s32 busy = func_00139d78(func_00256b68(1));
    if (busy) return busy;
    busy = func_00139d78(D_0035f0f4) != 0;
    if (busy) return busy;
    for (i = 0; i < 4; i++) {
        if (func_00139d78(&D_0035f0f4->a[i + 1])) busy = 1;
    }
    if (busy) return busy;
    for (i = 0; i < 4; i++) {
        if (func_00139d78(&D_0035f0f4->b[i])) {
            busy = 1;
            break;
        }
    }
    if (busy) return busy;
    if (D_0035f01c) busy = func_0028acc8(D_0035f01c) != 0;
    return busy;
}
}  // namespace n0026cda0

// 0026ceb0 (was src/anon/batch_w3903_nsamam.cpp)
namespace n0026ceb0 {
struct Big26c;
struct Item26c { u8 p0[0x18]; u8 sub[0x198 - 0x18]; union { Big26c* b; s32 v; } f198; u8 p19c[0x1b0 - 0x19c]; s32 state; };
struct Big26c { u8 p0[0xee8]; Item26c items[5]; u8 a[0x80]; u8 b[0x80]; };
extern "C" Big26c* D_0035f0f4;
extern Big26c* D_f0f4b asm("D_0035f0f4");
extern u8* D_0035f034 asm("D_0035f034");
extern s32 D_0035ef68 asm("D_0035ef68");
extern s32 D_0035ef64 asm("D_0035ef64");
extern s32 D_0035f03c asm("D_0035f03c");
extern const s16 D_00373848[] asm("D_00373848");
extern s32 D_0037383c asm("D_0037383c");
extern s32 D_00373840 asm("D_00373840");
extern s32 D_0035eeb8 asm("D_0035eeb8");
extern u16 D_00373858[] asm("D_00373858");
void func_00257388(s32, s32) asm("func_00257388");
void func_002571e0(s32) asm("func_002571e0");
s32 func_0023aa78(void*) asm("func_0023aa78");
void func_0028d980(Item26c*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void func_00138c68(Item26c*, s32, s32) asm("func_00138c68");
void func_0028dcc0(Item26c*, void*) asm("func_0028dcc0");
void func_0026d208(void) asm("func_0026d208");
s32 func_00192048(u32) asm("func_00192048");
s32 func_00293bc0(void) asm("func_00293bc0");
s32 func_001a8c78(s32, s32) asm("func_001a8c78");
s32 func_001a8c10(s32, s32) asm("func_001a8c10");
s32 func_001d6e60(void) asm("func_001d6e60");
static inline void setState26c(Item26c* p) { p->state = 2; }
/*TARGET 0026ceb0*/
void func_0026ceb0(void) asm("func_0026ceb0");
void func_0026ceb0(void)
{
    s32 i, j;
    s32 n;
    u8* o;
    func_00257388(0x846d, 1);
    func_002571e0(0);
    o = D_0035f034;
    n = func_0023aa78(o + 24);
    for (i = 0; i < 3; i++) {
        func_0028d980(&D_0035f0f4->items[i], 30023, D_0035ef68, D_0035ef64, D_0035f03c, D_00373848[i], -1, -1, 0);
        func_00138c68(&D_0035f0f4->items[i], 0, n);
        setState26c(&D_0035f0f4->items[i]);
        func_0028dcc0(&D_0035f0f4->items[i], o);
        n += func_0023aa78(D_0035f0f4->items[i].sub);
    }
    j = 0;
    i = 3;
    do {
        s32 a = D_0037383c, c = D_00373840; s32 v = i != 3 ? c : a;
        func_0028d980(&D_0035f0f4->items[i], 30023, D_0035ef68, D_0035ef64, D_0035f03c, D_00373848[i], -1, v, 0);
        func_0028dcc0(&D_0035f0f4->items[i], &D_0035f0f4->items[j]);
        setState26c(&D_0035f0f4->items[i]);
        i++; j++;
    } while (i < 5);
    func_0026d208();
    D_0035f0f4->items[0].f198.b = (Big26c*)D_0035f0f4->a;
    D_0035f0f4->items[1].f198.b = (Big26c*)D_0035f0f4->b;
    if (D_0035eeb8 == 2) {
        Item26c* p = &D_0035f0f4->items[2];
        p->f198.v = func_00192048(0xcc69);
    } else {
        s32 h = func_00293bc0();
        for (i = 0; i < 4; i++) {
            if (i && func_001a8c78(h, i)) {
                s32 k = func_001a8c10(h, i);
                u16 id = D_00373858[k];
                if (k == 15) id = func_001d6e60() ? 0xcc9f : id;
                Item26c* p = &D_f0f4b->items[2];
                p->f198.v = func_00192048(id);
            }
        }
    }
}
}  // namespace n0026ceb0

// 0026d168 (was src/anon/tiny.cpp)
namespace n0026d168 {
void func_00257530(s32) asm("_Z13func_00257530i");
/*TARGET 0026d168*/
// 0x0025f698: definition moved into src/anon/unit_0025da20.cpp
void func_0026d168(BD_VALUE* bd) asm("_Z13func_0026d168P8BD_VALUE");
// 0x0025f698: definition moved into src/anon/unit_0025da20.cpp
void func_0026d168(BD_VALUE* bd) { func_00257530(1); }
}  // namespace n0026d168

// 0026d180 (was src/anon/batch_w51.cpp)
namespace n0026d180 {
s32 func_002576d0(void) asm("func_002576d0");
s32 func_00139d78(void*) asm("func_00139d78");
extern u8* D_0035f0f4 asm("D_0035f0f4");
/*TARGET 0026d180*/
s32 func_0026d180(void) asm("func_0026d180");
s32 func_0026d180(void) {
    s32 r = func_002576d0();
    if (!r) {
        for (s32 i = 0; i < 5; i++) {
            if (func_00139d78(D_0035f0f4 + i * 436 + 3816)) {
                r = 1;
                break;
            }
        }
    }
    return r;
}
}  // namespace n0026d180

// 0026d208 (was src/anon/batch_w8022.c)
namespace n0026d208 {
/* 0026d208 */


extern s32 D_0035f0f8 asm("D_0035f0f8");
extern u8* D_0035f0f4 asm("D_0035f0f4");
extern char D_00373828[] asm("D_00373828");
s32 func_00293bc0(void) asm("func_00293bc0");
u32 func_001a8c10(s32, s32) asm("func_001a8c10");
s32 func_001a8c78(s32, s32) asm("func_001a8c78");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
char* func_00192cc0(char*, char*) asm("func_00192cc0");
s32 func_002595e8(char*, char*) asm("func_002595e8");
s32 func_00192b30(char*) asm("func_00192b30");
void func_002595b8(s32, char*, s32) asm("func_002595b8");
s32 func_002595e0(void) asm("func_002595e0");
char* func_001b77a8(u32) asm("func_001b77a8");
/*TARGET 0026d208*/
void func_0026d208(void) asm("func_0026d208");
void func_0026d208(void) {
    u32 a[2][4];
    char buf[16];
    s32 i, k, n, found;
    u32 v;
    char* d;
    char* sep;
    s32 me = func_00293bc0();
    for (i = 0; i < 4; i++) { a[1][i] = 0; a[0][i] = 0; }
    n = 0;
    for (i = 0; i < 4; i++) {
        v = func_001a8c10(me, i);
        found = 0;
        if (v == 0) continue;
        for (k = 0; k < 4; k++) {
            if (func_001a8c10(D_0035f0f8, k) == v) { found = 1; break; }
        }
        if (found) continue;
        a[0][n] = v;
        if (func_001a8c78(me, i)) a[0][n] |= 0x80000000;
        n++;
    }
    func_002fde18(D_0035f0f4 + 5996, 0, 128);
    i = 0;
    sep = func_00192cc0(buf, D_00373828);
    d = (char*)D_0035f0f4 + 5996;
    for (; i < n; i++) {
        if (i != 0) { func_002595e8(d, sep); d += func_00192b30(sep); }
        if (a[0][i] & 0x80000000) { func_002595b8(10, d, 1); d += func_002595e0(); }
        char* s = func_001b77a8(a[0][i] & 0x7fffffff);
        func_002595e8(d, s);
        d += func_00192b30(s);
    }
    n = 0;
    for (i = 0; i < 4; i++) {
        v = func_001a8c10(D_0035f0f8, i);
        found = 0;
        if (v == 0) continue;
        for (k = 0; k < 4; k++) {
            if (func_001a8c10(me, k) == v) { found = 1; break; }
        }
        if (found) continue;
        a[1][n] = v;
        if (func_001a8c78(D_0035f0f8, i)) a[1][n] |= 0x80000000;
        n++;
    }
    func_002fde18(D_0035f0f4 + 6124, 0, 128);
    i = 0;
    d = (char*)D_0035f0f4 + 6124;
    for (; i < n; i++) {
        if (i != 0) { func_002595e8(d, sep); d += func_00192b30(sep); }
        if (a[1][i] & 0x80000000) { func_002595b8(10, d, 1); d += func_002595e0(); }
        char* s = func_001b77a8(a[1][i] & 0x7fffffff);
        func_002595e8(d, s);
        d += func_00192b30(s);
    }
}
}  // namespace n0026d208

// 0026d560 (was src/anon/auto80_199_queue.cpp)
namespace n0026d560 {
/*TARGET 0026d560*/
u32 func_0026d560() asm("_Z13func_0026d560v");
u32 func_0026d560() {
    u32 s1 = 0;
    u32 s0 = func_00256b68(1);
    if (s0 != 0) {
        if (func_00139d78(s0) != 0) {
            u32 v = *(u32*)(s0 + 388);
            s1 = ((v ^ 0x139) < 1);
        }
    }
    return s1;
}
}  // namespace n0026d560

// 0026d5c0 (was src/anon/auto80_199_queue.cpp)
namespace n0026d5c0 {
/*TARGET 0026d5c0*/
void func_0026d5c0() asm("_Z13func_0026d5c0v");
void func_0026d5c0() {
    u32 s0 = func_00256b68(1);
    if (s0 != 0) {
        if (func_00139d78(s0) != 0) {
            if (*(u32*)(s0 + 388) != 313) {
                func_00138c10(s0, 313);
                *(u32*)(s0 + 392) = 0xFFFFFFFF;
            }
        }
    }
}
}  // namespace n0026d5c0

// 0026d620 (was src/anon/batch_wcx2.cpp)
namespace n0026d620 {
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
extern u8* D_0035f0f4 asm("D_0035f0f4");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035f03c asm("D_0035f03c");
s32 func_00139d78(void*) asm("func_00139d78");
u32 func_00256b68(s32) asm("func_00256b68");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028d008(u32) asm("func_0028d008");
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0(u8*, u32) asm("func_0028dcc0");
u8* func_0028d0e0(u32) asm("func_0028d0e0");
void func_00138c78(u32, u32*, u32*) asm("func_00138c78");
void func_00138c68(u8*, u32, u32) asm("func_00138c68");
void func_00139510(u8*) asm("func_00139510");
/*TARGET 0026d620*/
void func_0026d620(u32 w, u8 sync) asm("func_0026d620");
void func_0026d620(u32 w, u8 sync)
{
    s32 busy = func_00139d78(D_0035f0f4);
    u32 snd = func_00256b68(1);
    func_00287bc0();
    u32 a, b;
    if (func_0028d008(w)) {
        if (!busy) {
            func_0028d8c0(D_0035f0f4, 30015, D_0035ef68, D_0035ef64, D_0035f03c, 317, -1, 0);
            func_0028dcc0(D_0035f0f4, snd);
            func_00138c78(*(u32*)(func_0028d0e0(w) + 396), &a, &b);
            func_00138c68(D_0035f0f4, a, b);
        }
        if (sync) {
            func_00138c78(*(u32*)(func_0028d0e0(w) + 396), &a, &b);
            func_00138c68(D_0035f0f4, a, b);
        }
    } else if (busy) {
        func_00139510(D_0035f0f4);
    }
}
}  // namespace n0026d620

// 0026d748 (was src/anon/batch_w1793.cpp)
namespace n0026d748 {
struct E436 { u8 pad[408]; u32 x; u8 pad2[24]; };
struct B0f4 { u8 pad[2040]; E436 e[8]; };
union U0f4 { B0f4* p; u32 u; };
extern U0f4 D_0035f0f4 asm("D_0035f0f4");
extern u32 D_0035f010 asm("D_0035f010");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f024 asm("D_0035f024");
s32 func_002891e8(u32) asm("func_002891e8");
u32 func_00293bc0() asm("func_00293bc0");
void func_001a8ff8(u32, s32, s32) asm("func_001a8ff8");
void func_002810c8(u32, u32) asm("func_002810c8");
u32 func_00287dc0() asm("func_00287dc0");
void func_0023ebe0(u32, s32, s32) asm("func_0023ebe0");
/*TARGET 0026d748*/
void func_0026d748(void) asm("func_0026d748");
void func_0026d748(void) {
    s32 a = func_002891e8(D_0035f01c);
    s32 b = func_002891e8(D_0035f024);
    u32 o = func_00293bc0();
    u32 t;
    func_001a8ff8(o, a, b);
    func_002810c8(D_0035f010, o);
    E436* pa = &D_0035f0f4.p->e[a];
    t = pa->x;
    E436* pb0 = &D_0035f0f4.p->e[b];
    pa->x = pb0->x;
    E436* pb = &D_0035f0f4.p->e[b];
    pb->x = t;
    func_0023ebe0(func_00287dc0(), a, b);
}
}  // namespace n0026d748

// 0026d808 (was src/anon/tiny.cpp)
namespace n0026d808 {
/*TARGET 0026d808*/
// 0x00264318: definition moved into src/anon/unit_002640a8.cpp

void func_0026d808(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0026d808jjjj");
// 0x00264318: definition moved into src/anon/unit_002640a8.cpp

void func_0026d808(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u32*)((u32)b + (-3848)) = (u32)a0;
}
}  // namespace n0026d808

// 0026d818 (was src/anon/batch_w1666.cpp)
namespace n0026d818 {
extern s32 D_0035f0f8 asm("D_0035f0f8");
/*TARGET 0026d818*/
// 0x0025f578: definition moved into src/anon/unit_0025da20.cpp
s32 func_0026d818(void) asm("func_0026d818");
// 0x0025f578: definition moved into src/anon/unit_0025da20.cpp
s32 func_0026d818(void) { return D_0035f0f8; }
}  // namespace n0026d818

// 0026d828 (was src/anon/auto80_199_queue.cpp)
namespace n0026d828 {
/*TARGET 0026d828*/
void func_0026d828() asm("_Z13func_0026d828v");
void func_0026d828() {
    s32 s1 = 0;
    u32 s2 = func_00293bc0();

    while (1) {
        u32 s0 = func_001a8bf8(D_0035f0fc, (u32)s1);  // get_bits5_at
        u32 v = func_001a8bf8(s2, (u32)s1);  // get_bits5_at
        s1 = s1 + 1;
        if (s0 != v) {
            func_00257000();
            return;
        }
        if (s1 >= 4) {
            return;
        }
    }
}
}  // namespace n0026d828

// 0026d8c0 (was src/anon/batch_wcx.cpp)
namespace n0026d8c0 {
extern u32 D_0035f0fc asm("D_0035f0fc");
u32 func_00293bc0(void) asm("func_00293bc0");
s32 func_001a8bf8(u32, s32) asm("func_001a8bf8");
/*TARGET 0026d8c0*/
// get_bits5_at
s32 func_0026d8c0(s32 x) asm("func_0026d8c0");
// get_bits5_at
s32 func_0026d8c0(s32 x)
{
    s32 r = -1;
    u32 a = func_00293bc0();
    for (s32 i = 0; i < 4; i++)
        if (func_001a8bf8(D_0035f0fc, i) == func_001a8bf8(a, x)) { r = i; break; }
    return r;
}
}  // namespace n0026d8c0

// 0026d960 (gap, written for the unit)
namespace n0026d960 {
s32 func_0026d960(void) asm("func_0026d960");
s32 func_0026d960(void) { return 1; }
}  // namespace n0026d960

// 0026d968 (was src/anon/batch_w1934_nsa.cpp)
namespace n0026d968 {
struct W1934Heap;
typedef void* (*W1934AllocFn)(W1934Heap*, u32, s32);
struct W1934Heap { W1934AllocFn* vt; };
struct W1934Mgr { u8 p0[20]; W1934Heap* heap; };
extern void* D_00347f80 asm("D_00347f80");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
extern s32 D_0035f100 asm("D_0035f100");
extern void* D_0035f104 asm("D_0035f104");
extern void* D_0035f108 asm("D_0035f108");
extern void* D_0035f10c asm("D_0035f10c");
extern void* D_0035f110 asm("D_0035f110");
union W1934U114 { s16* p; s16 h; };
extern W1934U114 D_0035f114 asm("D_0035f114");
extern s8 D_0035f120 asm("D_0035f120");
extern void* D_0035f124 asm("D_0035f124");
void func_00287b18(s32, s32) asm("func_00287b18");
void func_00242618(s32, s32) asm("func_00242618");
void func_0028d068(s32, s32) asm("func_0028d068");
void* func_00288be8(s32) asm("func_00288be8");
void func_00239700(void*) asm("func_00239700");
s32 func_00103570(void) asm("func_00103570");
s16* func_001063f0(s32, s32) asm("func_001063f0");
static inline void* W1934Alloc(u32 n) { W1934Heap* h = ((W1934Mgr*)D_00347f80)->heap; return h->vt[0](h, n, 0); }
struct W1934B408 {
    void* vt; u8 p4[8]; u32 f0c; u8 p10[8]; u8 m[384];
    W1934B408() { f0c = 0; vt = D_00347e60; func_00239700(m); }
    static void* operator new(unsigned int n) { return W1934Alloc(n); }
};
struct W1934C436 : W1934B408 {
    u32 f198; u8 p19c[24];
    W1934C436() { vt = D_00347e40; f198 = 0; }
    ~W1934C436() {}
    static void* operator new[](unsigned int n) { return W1934Alloc(n); }
};
void func_0028d140(void*) asm("func_0028d140");
void func_00290610(void*) asm("func_00290610");
void func_002889f0(void*, s32, s32) asm("func_002889f0");
struct W1934X444 { u8 d[444]; W1934X444() { func_0028d140(this); } static void* operator new(unsigned int n) { return W1934Alloc(n); } };
struct W1934X832 { u8 d[832]; W1934X832() { func_00290610(this); } static void* operator new(unsigned int n) { return W1934Alloc(n); } };
struct W1934X56 { u8 d[56]; W1934X56(s32 a, s32 b) { func_002889f0(this, a, b); } static void* operator new(unsigned int n) { return func_00288be8(n); } };
/*TARGET 0026d968*/
void func_0026d968(void) asm("func_0026d968");
void func_0026d968(void)
{
    func_00287b18(2, 3);
    func_00242618(11, 1);
    func_0028d068(30026, -1);
    D_0035f100 = 0;
    D_0035f10c = new W1934X56(8, 0);
    D_0035f104 = new W1934C436[3];
    D_0035f108 = new W1934B408;
    D_0035f110 = new W1934X444;
    D_0035f124 = new W1934X832;
    D_0035f114.p = func_001063f0(18, func_00103570());
    for (s32 i = 0; i < 9; i++) D_0035f114.p[i] = -1;
    if (D_0035f120 < 0) D_0035f120 = 0;
}
}  // namespace n0026d968

// 0026db60 (was src/anon/batch_w270.cpp)
namespace n0026db60 {
struct W270Heap { virtual void f0(); virtual void Free(void*); };
struct W270Mgr { u8 pad[20]; W270Heap* heap; };
extern W270Mgr* D_00347f80 asm("D_00347f80");
struct W270Vo { virtual void f0(); virtual void f1(); virtual void f2(); virtual ~W270Vo(); };
struct W270Ae {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual ~W270Ae();
    u8 pad[432];
    void operator delete[](void* p) { D_00347f80->heap->Free(p); }
};
struct W270Sel;
extern W270Vo* D_0035f100 asm("D_0035f100");
extern W270Ae* D_0035f104 asm("D_0035f104");
extern W270Vo* D_0035f108 asm("D_0035f108");
extern W270Sel* D_0035f10c asm("D_0035f10c");
extern W270Vo* D_0035f110 asm("D_0035f110");
extern u8* D_0035f114 asm("D_0035f114");
extern W270Vo* D_0035f124 asm("D_0035f124");
// 0x0018a970: definition moved into src/anon/unit_00189d38.cpp
void W270_SelDtor(W270Sel*) asm("_ZN2Tz6SelectD1Ev");
void func_00288c20(W270Sel*) asm("func_00288c20");
void W270_dela(void*) asm("_ZdaPv");
u32 W270_SelExitImpl(...) asm("_ZN2Tz8Selector11SelExitImplEz");
/*TARGET 0026db60*/
u32 W270_SelExitImpl(...) asm("_ZN2Tz8Selector11SelExitImplEz");
u32 W270_SelExitImpl(...) {
    if (D_0035f100) { delete D_0035f100; D_0035f100 = 0; }
    if (D_0035f104) { delete[] D_0035f104; D_0035f104 = 0; }
    if (D_0035f108) { delete D_0035f108; D_0035f108 = 0; }
    if (D_0035f10c) { W270Sel* p = D_0035f10c; W270_SelDtor(p); func_00288c20(p); D_0035f10c = 0; }
    if (D_0035f110) { delete D_0035f110; D_0035f110 = 0; }
    if (D_0035f114) { W270_dela(D_0035f114); D_0035f114 = 0; }
    if (D_0035f124) { delete D_0035f124; D_0035f124 = 0; }
}
}  // namespace n0026db60

// 0026dcb8 (was src/anon/batch_w24.cpp)
namespace n0026dcb8 {
void func_0026d968(void) asm("func_0026d968");
void func_00287bd0(s32, s32) asm("func_00287bd0");
u32* func_00103eb0(void) asm("func_00103eb0");
void func_00102818(u32, s32, s32, void (*)(void), s32) asm("func_00102818");
void func_0026dd40(void) asm("func_0026dd40");
/*TARGET 0026dcb8*/
void func_0026dcb8(void) asm("func_0026dcb8");
void func_0026dcb8(void) {
    func_0026d968();
    func_00287bd0(0, 0);
    func_00102818(func_00103eb0()[1], 0, 2000, func_0026dd40, 4096);
}
}  // namespace n0026dcb8

// 0026dd00 (was src/tozawa/cmenu_selector.cpp)
namespace Tz { // method 0026dd00
/*TARGET 0026dd00*/
// 0028d0c8: moved to src/anon/unit_0028c878.cpp

// 0028d0e0: moved to src/anon/unit_0028c878.cpp

// 0028cbf8: moved to src/anon/unit_0028c878.cpp

// 0028cf98: moved to src/anon/unit_0028c878.cpp

u32 Tz_Selector_SelExit() asm("_ZN2Tz8Selector7SelExitEv");
u32 Tz_Selector_SelExit() { return Selector::SelExitImpl(); }
}  // Tz

// 0026dd18 (was src/anon/batch_w1.cpp)
namespace n0026dd18 {
extern s32 D_0035f118 asm("D_0035f118");
extern s32 D_0035f11c asm("D_0035f11c");
extern u8 D_0035f120 asm("D_0035f120");
/*TARGET 0026dd18*/
// 0x00263188: definition moved into src/anon/unit_0025f6b8.cpp

void func_0026dd18(s32 a0, s32 a1, s32 a2) asm("func_0026dd18");
// 0x00263188: definition moved into src/anon/unit_0025f6b8.cpp

void func_0026dd18(s32 a0, s32 a1, s32 a2) {  // store_session_globals
    D_0035f118 = a0;
    D_0035f11c = a1;
    if (a2 >= 0) D_0035f120 = a2;
}
}  // namespace n0026dd18

// 0026dd40 (was src/tozawa/cmenu_selector.cpp)
namespace Tz { // method 0026dd40
/*TARGET 0026dd40*/
void Tz_Selector_PauseThread(TASK* task) asm("_ZN2Tz8Selector11PauseThreadEP4TASK");
void Tz_Selector_PauseThread(TASK* task) {
    u32 s0 = (u32)task;
    PauseTaskSetup(s0);
    TaskYield(s0, 1);
    PauseTaskBegin();
    while (1) {
        if (PauseTaskIsDone(s0) != 0) {
            return;
        }
        PauseTaskUpdate();
        TaskYield(s0, 0);
    }
}
}  // Tz

// 0026dda0 (was src/anon/batch_w281.cpp)
namespace n0026dda0 {
// 0x0011b250: definition moved into src/anon/unit_0011a660.cpp

u8* func_0023ee30(s32) asm("func_0023ee30");
void func_0031a838(void*) asm("func_0031a838");
void func_002369a0(void*) asm("func_002369a0");
void func_0023c008(void*) asm("func_0023c008");
// obj_ctor_36eae8
void func_0028d7f0(void*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d7f0");
void func_0026e1e0(void) asm("func_0026e1e0");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0026df30(void) asm("func_0026df30");
void* func_0023f1b0(void*) asm("func_0023f1b0");
void* func_0023c3e0(void*, s32, s32) asm("func_0023c3e0");
s32 func_00139d78(void*) asm("func_00139d78");
void func_0028dd28(void*, void*) asm("func_0028dd28");
s32 func_002892f8(void*) asm("func_002892f8");
void* func_002891b8(void*, s32) asm("func_002891b8");
void func_0026e3b0(void) asm("func_0026e3b0");
void func_0028af28(void*, s32) asm("func_0028af28");
void func_00287cc0(s32) asm("func_00287cc0");
extern u8* D_0035f100 asm("D_0035f100");
extern u8* D_0035f104 asm("D_0035f104");
extern void* D_0035f10c asm("D_0035f10c");
extern u8* D_0035f118 asm("D_0035f118");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
void PauseTaskBegin_impl(void) asm("_ZN2Tz14PauseTaskBeginEv");
/*TARGET 0026dda0*/
void PauseTaskBegin_impl(void) asm("_ZN2Tz14PauseTaskBeginEv");
void PauseTaskBegin_impl(void) {
    u8* t = func_0023ee30(160);
    void* seq;
    s32 i;
    s32 off;
    s32 n;
    *(u32*)t = (u32)D_00347f98;
    func_0031a838(t + 12);
    *(u32*)t = (u32)D_0035eb98;
    func_002369a0(t + 24);  // obj_ctor_36eac8
    func_0023c008(t + 48);  // obj_ctor_36eae8
    D_0035f100 = t;
    func_0028d7f0(t, 30002, 0, 0, 0, -1, 0, 0, 0);
    func_0026e1e0();
    if (!func_00287bc0()) func_0026df30();
    seq = func_0023c3e0(func_0023f1b0(D_0035f100), 10, 0);
    for (i = 0, off = 0; i < 3; i++, off += 436) {
        if (func_00139d78(D_0035f104 + off)) func_0028dd28(D_0035f104 + off, seq);
    }
    n = func_002892f8(D_0035f10c);
    for (i = 0; i < n; i++) func_0028dd28(func_002891b8(D_0035f10c, i), seq);
    func_0026e3b0();
    {
        u32 t = !(D_0035f118[37] & 1);
        s32 m = 32;
        if (t == 0) m = 96;
        func_0028af28(D_0035f10c, m);
    }
    func_00287cc0(1);
}
}  // namespace n0026dda0

// 0026df30 (was src/anon/batch_w316.cpp)
namespace n0026df30 {
struct I1E { u16 id; u16 h2; };
struct I1 { u8 b0; u8 b1; u8 n; u8 b3; I1E e[4]; u8 pad20[2]; s16 h22; u32 w24; };
extern u32 D_0035f118 asm("D_0035f118");
#define G118 ((I1*)D_0035f118)
extern u32 D_0035f104 asm("D_0035f104");
extern u32* D_0035f11c asm("D_0035f11c");
extern u32 D_0035f100 asm("D_0035f100");
extern u32 D_0035f10c asm("D_0035f10c");
extern u16* D_0035f114 asm("D_0035f114");
extern s8 D_0035f120 asm("D_0035f120");
void func_0026e140(s32, s32, s32) asm("func_0026e140");
void gspxy_x(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void SetDisableButton_x(void*, u32) asm("_ZN2Tz6Select16SetDisableButtonEj");
u8* func_0028c198(s32, s32, s32, u32, u32, u32) asm("func_0028c198");
void func_00288ce0(void*, void*, s32, s16*, s16*) asm("func_00288ce0");
void func_002891f0(void*, s32, s32, s32, s32) asm("func_002891f0");
/*TARGET 0026df30*/
void func_0026df30(void) asm("func_0026df30");
void func_0026df30(void) {
  s16 a[4];
  s16 b[4];
  s32 i, n, k;
  if (G118->h22 >= 0) func_0026e140(0, G118->h22, -1);
  if (G118->w24) {
    func_0026e140(1, 14, -1);
    gspxy_x((u8*)D_0035f104 + 436);
    *(u32*)((u8*)D_0035f104 + 868) = 3;
    *(u32*)((u8*)D_0035f104 + 844) = G118->w24;
  }
  if (D_0035f11c && *D_0035f11c) func_0026e140(2, 13, -1);
  for (i = 0; i < 4; i++) { a[i] = 12; b[i] = 11; }
  n = G118->n;
  k = 0;
  for (i = 0; i < n; i++) {
    if (G118->e[i].id) {
      u8* v = func_0028c198(12, 0, 0, D_0035f100, G118->e[i].h2, 0);
      gspxy_x(v);
      *(u32*)(v + 432) = 2;
      func_00288ce0((void*)D_0035f10c, v, k, a, b);
      D_0035f114[k++] = G118->e[i].id;
    }
  }
  if (k) {
    s32 x = D_0035f120;
    func_002891f0((void*)D_0035f10c, x < 0 ? 0 : x, 1, 2, 2);
  } else {
    SetDisableButton_x((void*)D_0035f10c, 16);
  }
}
}  // namespace n0026df30

// 0026e140 (was src/anon/batch_w66.cpp)
namespace n0026e140 {
// 0x0010b568: definition moved into src/anon/unit_0010b450.cpp
// ---- 0013793c
s32 func_00139d78(u8*) asm("func_00139d78");
// ---- 0026e140
extern u8* D_0035f104 asm("D_0035f104");
extern u32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035f100 asm("D_0035f100");
void func_0028d980(u8*, u32, s32, s32, u32, u32, s32, s32, s32) asm("func_0028d980");
u32 func_00192048(s32) asm("func_00192048");
/*TARGET 0026e140*/
void func_0026e140(s32 i, u32 b, s32 c) asm("func_0026e140");
void func_0026e140(s32 i, u32 b, s32 c) {
    func_00139d78(D_0035f104 + i * 436);
    func_0028d980(D_0035f104 + i * 436, D_0035f3d4, 0, 0, D_0035f100, b, -1, -1, 0);
    if (c >= 0) {
        u8* e = D_0035f104 + i * 436;
        *(u32*)(e + 408) = func_00192048(c);
    }
}
}  // namespace n0026e140

// 0026e1e0 (was src/anon/batch_w273.cpp)
namespace n0026e1e0 {
struct Obj273;
struct Obj273Vt { void* p[6]; void (*f6)(Obj273*, s32, u32, s32, s32, s32, s32); };
struct Obj273 { Obj273Vt* vt; };
struct Pair273 { u32 a; s32 b; };
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern Pair273* D_0035f11c asm("D_0035f11c");
extern s32 D_0035f108 asm("D_0035f108");
extern s32 D_0035f100 asm("D_0035f100");
void func_0028d8c0(s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
Obj273* func_00287dc0(void) asm("func_00287dc0");
void func_0023d808(Obj273*, s32) asm("func_0023d808");
void func_0023e5d0(Obj273*, s32, s32) asm("func_0023e5d0");
void func_0023e858(Obj273*, s32, f32) asm("func_0023e858");
void func_0023e8b8(Obj273*, s32, f32) asm("func_0023e8b8");
void func_0023e8d8(Obj273*, s32, f32) asm("func_0023e8d8");
void func_0023e9c8(Obj273*, s32, s32) asm("func_0023e9c8");
/*TARGET 0026e1e0*/
void func_0026e1e0(void) asm("func_0026e1e0");
void func_0026e1e0(void) {
  s32 n = D_0035f3d4 - 1;
  if (D_0035f11c == 0 || D_0035f11c->a == 0 || D_0035f11c->b == 0) return;
  func_0028d8c0(D_0035f108, n, 0, 0, D_0035f100, 16, 17, 0);
  Obj273* o = func_00287dc0();
  func_0023d808(o, n);
  o->vt->f6(o, 0, D_0035f11c->a | 0x20000000, -1, 2, 0, 0);
  func_0023e5d0(o, 0, D_0035f11c->b);
  func_0023e858(o, 0, -100.0f);
  func_0023e8b8(o, 0, 0.0f);
  func_0023e8d8(o, 0, 0.0f);
  func_0023e9c8(o, 0, D_0035f108);
}
}  // namespace n0026e1e0

// 0026e340 (was src/anon/auto80_199_queue.cpp)
namespace n0026e340 {
/*TARGET 0026e340*/
u32 func_0026e340() asm("_Z13func_0026e340v");
u32 func_0026e340() {
    if (func_00139d78((u32)D_0035f108) != 0) {
        call_f5(D_0035f108);
    }

    if (func_00139d78((u32)D_0035f108) != 0) {
        call_f5(D_0035f108);
    }

    return func_0023d820(func_00287dc0());
}
}  // namespace n0026e340

// 0026e3b0 (was src/anon/batch_w316.cpp)
namespace n0026e3b0 {
extern u32 D_0035f104 asm("D_0035f104");
extern u32 D_0035f10c asm("D_0035f10c");
void setOffsetPos_x(void*, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
s32 u_call4_00139d78_x(void*) asm("_Z16u_call4_00139d78jjjj");
s32 GetParamEx_x(void*) asm("_ZN2YI8SEQUENCE10GetParamExEv");
u8* GetItemPtr_x(void*, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
s32 GetItemMax_x(void*) asm("_ZN2Tz6Select10GetItemMaxEv");
/*TARGET 0026e3b0*/
void func_0026e3b0(void) asm("func_0026e3b0");
void func_0026e3b0(void) {
  s32 w[11];
  s32 i, k, n, sum, x;
  for (i = 0; i < 11; i++) w[i] = 0;
  k = 0;
  for (i = 0; i < 3; i++) {
    if (u_call4_00139d78_x((u8*)D_0035f104 + i * 436)) {
      w[k] = GetParamEx_x((u8*)D_0035f104 + i * 436 + 24);
      k++;
    }
  }
  n = GetItemMax_x((void*)D_0035f10c);
  for (i = 0; i < n; i++) {
    w[k] = GetParamEx_x(GetItemPtr_x((void*)D_0035f10c, i) + 24);
    k++;
  }
  if (k < 2) return;
  sum = 0;
  for (i = 0; i < 11; i++) sum += w[i];
  x = -(sum / 2);
  k = 0;
  for (i = 0; i < 3; i++) {
    if (u_call4_00139d78_x((u8*)D_0035f104 + i * 436)) {
      setOffsetPos_x((u8*)D_0035f104 + i * 436, 0, x);
      x += w[k];
      k++;
    }
  }
  for (i = 0; i < n; i++) {
    setOffsetPos_x(GetItemPtr_x((void*)D_0035f10c, i), 0, x);
    x += w[k];
      k++;
  }
}
}  // namespace n0026e3b0

// 0026e5b8 (was src/anon/batch_w58.cpp)
namespace n0026e5b8 {
// Tz::PauseTaskIsDone
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00287db0(void) asm("func_00287db0");
void func_001039f8(void) asm("func_001039f8");
void func_0026e638(void*) asm("func_0026e638");
void func_0026e8a0(void) asm("func_0026e8a0");
s32 PauseTaskIsDone(void* a) asm("_ZN2Tz15PauseTaskIsDoneEz");
/*TARGET 0026e5b8*/
s32 PauseTaskIsDone(void* a) asm("_ZN2Tz15PauseTaskIsDoneEz");
s32 PauseTaskIsDone(void* a) {
    s32 m = func_00287bc0();
    if (func_00287db0()) {
        func_001039f8();
        return 1;
    }
    switch (m) {
    case 0: func_0026e638(a); break;
    case 1: func_0026e8a0(); break;
    }
    return 0;
}
}  // namespace n0026e5b8

// .rodata 0x37387c
extern const u32 R_0037387c[1] asm("D_0037387c") __attribute__((aligned(4))) = { 0xb };

// 0026e638 (was src/anon/batch_w1605.cpp)
namespace n0026e638 {
struct F11c { u8 pad[24]; void (*fn)(s32, s32); };
s32 func_00289380(u32) asm("func_00289380");
void func_002892f8(u32) asm("func_002892f8");
s32 func_00289310(u32) asm("func_00289310");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_00258af0(s32) asm("func_00258af0");
void func_001bbba8(s32) asm("func_001bbba8");
void func_00242790(void) asm("func_00242790");
s32 func_001bba88(void) asm("func_001bba88");
void func_0026e840(void) asm("func_0026e840");
void func_00225e28(void) asm("func_00225e28");
void func_00136a18(void) asm("func_00136a18");
void func_002427c0(void) asm("func_002427c0");
void func_00197e68(void) asm("func_00197e68");
void func_00287da0(void) asm("func_00287da0");
void func_00242660(s32) asm("func_00242660");
extern u32 D_0035f10c asm("D_0035f10c");
extern s16* D_0035f114 asm("D_0035f114");
extern F11c* D_0035f11c asm("D_0035f11c");
extern s8 D_0035f120 asm("D_0035f120");
/*TARGET 0026e638*/
void func_0026e638(s32 a0) asm("func_0026e638");
void func_0026e638(s32 a0) {
    s32 r = func_00289380(D_0035f10c);
    func_002892f8(D_0035f10c);
    s32 ret = func_00287df0(r, func_00289310(D_0035f10c), 1, 0, 0);
    switch (r) {
    case -4:
    case -2:
        func_00242790();
        func_00287da0();
        break;
    case -1:
        break;
    default:
        switch ((u16)D_0035f114[r]) {
        case 1:
            func_00258af0(3);
            break;
        case 3:
        case 4:
            func_001bbba8(D_0035f114[r]);
            break;
        case 6:
            func_00242790();
            break;
        case 10:
            func_00258af0(4);
            break;
        case 12:
            if (func_001bba88()) func_0026e840();
            break;
        case 17:
            func_00258af0(1);
            break;
        default:
            if (D_0035f11c && D_0035f11c->fn) D_0035f11c->fn(D_0035f114[r], a0);
            break;
        case 5:
        case 19:
            func_00225e28();
            func_00136a18();
            func_00242790();
            func_002427c0();
            func_00197e68();
            break;
        }
        D_0035f120 = r;
        if (D_0035f114[r] != 12) func_00287da0();
        break;
    }
    if (ret) func_00242660(ret);
}
}  // namespace n0026e638

// 0026e840 (was src/tozawa/cmenu_selector.cpp)
namespace Tz { // method 0026e840
extern u32 D_0035f124 asm("D_0035f124");
/*TARGET 0026e840*/
// 00290738: moved to src/anon/unit_0028f1e0.cpp

void Tz_Selector_SetupHelpGra() asm("_ZN2Tz8Selector12SetupHelpGraEv");
void Tz_Selector_SetupHelpGra() {
    u32 a;
    u32 b;
    Selector::GetHelpGraPos((u32)&a, (u32)&b);
    Selector::SetHelpGraMsg(D_0035f124, 30027);
    Selector::CreateHelpGra(D_0035f124, a, b, 0);
    MenuBase::NextModeToMode(1, 0);
    Selector::SetState(1);
}
}  // Tz

// 0026e8a0 (was src/tozawa/cmenu_selector.cpp)
namespace Tz { // method 0026e8a0
extern u32 D_0035f124 asm("D_0035f124");
void func_0028dac8(...) asm("func_0028dac8");
/*TARGET 0026e8a0*/
void Tz_Selector_Control(TASK*) asm("_ZN2Tz8Selector7ControlEP4TASK");
void Tz_Selector_Control(TASK*) {
    u32 s0 = MenuCursor::GetInputState(0);
    u32 v = Selector::GetState();
    if (v == 2) {
        if (Selector::HelpGraDone(D_0035f124) == 0) {
            MenuBase::NextModeToMode(0, 0);
            Selector::SetState(1);
        }
        return;
    }
    u64 f = *(u64*)(s0 + 8);
    if ((f & 0xC) == 0) {
        return;
    }
    MenuSound::PlaySE(9, true);
    func_0028dac8(D_0035f124, 1);
    Selector::SetState(2);
}
}  // Tz

// 0026e940 (was src/anon/batch_w285.cpp)
namespace n0026e940 {
struct TzObj285 { void (**vt)(TzObj285*); };
// 0x2c6eb8: moved to src/anon/unit_002c6eb8.cpp



extern TzObj285* D_0035f100 asm("D_0035f100");
extern void* D_0035f10c asm("D_0035f10c");
extern void* D_0035f110 asm("D_0035f110");
extern u8 D_003738d8[] asm("D_003738d8");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287db0(void) asm("func_00287db0");
s32 func_00139d78(void*) asm("func_00139d78");
void func_0028ce38(void) asm("func_0028ce38");
void func_0026ebc0(void) asm("func_0026ebc0");
s32 func_0028acc8(void*) asm("func_0028acc8");
s32 func_0028d008(s32) asm("func_0028d008");
void func_0028cc78(s32, s32, s32, void*, s32, s32) asm("func_0028cc78");
s32 func_002891d0(void*) asm("func_002891d0");
void func_0028cf28(s32, s32) asm("func_0028cf28");
// record408_set_and_refresh
s32 func_0028d6e8(void*) asm("func_0028d6e8");
void func_0028d1c0(void*, s32, s32, s32, void*, void*, s32) asm("func_0028d1c0");
void func_0028d660(void*, s32) asm("func_0028d660");
// record_set_value_refresh
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0026eae8(void*, s32) asm("func_0026eae8");
void func_0028cdb8(s32) asm("func_0028cdb8");
// record408_alloc_init
void func_0028d5d0(void*) asm("func_0028d5d0");
void PauseTaskUpdate_impl(void) asm("_ZN2Tz15PauseTaskUpdateEv");
/*TARGET 0026e940*/
void PauseTaskUpdate_impl(void) asm("_ZN2Tz15PauseTaskUpdateEv");
void PauseTaskUpdate_impl(void) {
    s32 s = func_00287cd0();
    if (func_00287db0()) {
        if (func_00139d78(D_0035f100)) D_0035f100->vt[5](D_0035f100);
        func_0028ce38();
        func_0026ebc0();
    }
    if (func_00287db0()) return;
    if (func_0028acc8(D_0035f10c) && s == 1) {
        if (func_0028d008(0) == 0) {
            func_0028cc78(0, 0, 0, D_0035f100, 6, 6);
            func_0028cf28(0, func_002891d0(D_0035f10c));  // record408_set_and_refresh
            if (func_0028d6e8(D_0035f110) == 0) {
                func_0028d1c0(D_0035f110, 30026, 0, 0, D_0035f100, D_003738d8, 0);
            }
            func_0028d660(D_0035f110, func_002891d0(D_0035f10c));  // record_set_value_refresh
        }
    } else if (s == 2) {
        if (func_0028d008(0)) {
            func_0028cdb8(0);  // record408_alloc_init
            func_0028d5d0(D_0035f110);
        } else if (func_0028d6e8(D_0035f110)) {
            func_0028d5d0(D_0035f110);
        }
    }
    func_0026eae8(D_0035f10c, func_00287bc0());
}
}  // namespace n0026e940

// 0026eae8 (was src/anon/batch_w84.cpp)
namespace n0026eae8 {
s32 func_00289310(u32) asm("func_00289310");
u32 func_002891e8(u32) asm("func_002891e8");
void func_002890e0(u32, s32, s32, s32, s32) asm("func_002890e0");
void func_00289038(u32, u32, s32, s32, s32, s32, s32) asm("func_00289038");
s32 func_0028d008(u32) asm("func_0028d008");
u32 func_002891d0(u32) asm("func_002891d0");
void func_0028cf28(u32, u32) asm("func_0028cf28");
// record408_set_and_refresh
s32 func_0028d6e8(u32) asm("func_0028d6e8");
void func_0028d660(u32, u32) asm("func_0028d660");
// record_set_value_refresh
extern u32 D_0035f110 asm("D_0035f110");
/*TARGET 0026eae8*/
void func_0026eae8(u32 a) asm("func_0026eae8");
void func_0026eae8(u32 a) {
    if (!func_00289310(a)) return;
    u32 s = func_002891e8(a);
    func_002890e0(a, 1, 2, 0, -1);
    func_00289038(a, s, 1, 1, 2, 0, -1);
    if (func_0028d008(0)) func_0028cf28(0, func_002891d0(a));
    if (func_0028d6e8(D_0035f110)) func_0028d660(D_0035f110, func_002891d0(a));
}
}  // namespace n0026eae8

// 0026ebc0 (was src/anon/batch_w1593.cpp)
namespace n0026ebc0 {
typedef void (*VF1593)(void*);
struct VT1593 { void* f[8]; };
struct Obj1593 { VT1593* vt; };
// ---- 0026ebc0
struct Big1593 { Obj1593 o; u8 pad[0x1b4 - 4]; };
s32 func_00139d78(void*) asm("func_00139d78");
void func_0026e340() asm("func_0026e340");
void func_0028abe0(void*) asm("func_0028abe0");
s32 func_0028acc8(void*) asm("func_0028acc8");
s32 func_0028d6e8(void*) asm("func_0028d6e8");
extern Big1593* D_0035f104 asm("D_0035f104");
extern void* D_0035f10c asm("D_0035f10c");
extern Obj1593* D_0035f110 asm("D_0035f110");
/*TARGET 0026ebc0*/
void func_0026ebc0(void) asm("func_0026ebc0");
void func_0026ebc0(void) {
    s32 i;
    if (func_0028acc8(D_0035f10c)) func_0028abe0(D_0035f10c);
    for (i = 0; i < 3; i++) {
        if (func_00139d78(&D_0035f104[i])) {
            ((VF1593)D_0035f104[i].o.vt->f[5])(&D_0035f104[i]);
        }
    }
    if (func_0028d6e8(D_0035f110)) ((VF1593)D_0035f110->vt->f[5])(D_0035f110);
    func_0026e340();
}
}  // namespace n0026ebc0

// 0026ec70 (was src/anon/batch_w18.cpp)
namespace n0026ec70 {
void func_0023fa08(void*, void*) asm("func_0023fa08");
// 0x00263d70: definition moved into src/anon/unit_002632d0.cpp


extern u8 D_0035f3a8[] asm("D_0035f3a8");
void* func_002537c8(u32) asm("func_002537c8");
void PauseTaskSetup(...) asm("_ZN2Tz14PauseTaskSetupEz");
/*TARGET 0026ec70*/
void PauseTaskSetup(...) asm("_ZN2Tz14PauseTaskSetupEz");
void PauseTaskSetup(...) {
    func_0023fa08(D_0035f3a8, func_002537c8(0));
}
}  // namespace n0026ec70

// 0026ec98 (was src/anon/batch_w2434.c)
namespace n0026ec98 {
// 0x0016f610: definition moved into src/anon/unit_0016e8f8.cpp

extern s32 D_0035f12c asm("D_0035f12c");
extern u8 D_0035f130 asm("D_0035f130");
extern s8 D_0035f129 asm("D_0035f129");
extern u8 D_0035f128 asm("D_0035f128");
extern s16 D_01e21ec0[2][4] asm("D_01e21ec0");
void func_0026ed48(void) asm("func_0026ed48");
/*TARGET 0026ec98*/
void func_0026ec98(void) asm("func_0026ec98");
void func_0026ec98(void) {
    s32 i, j;
    D_0035f12c = 0;
    D_0035f130 = 0;
    D_0035f128 = 0;
    D_0035f129 = -1;
    for (i = 0; i < 2; i++) {
        s32 k = (i != 0);
        for (j = 0; j < 4; j++) {
            D_01e21ec0[i][j] = 0x130 - k;
        }
    }
    func_0026ed48();
}
}  // namespace n0026ec98

// 0026ed20 (was src/anon/tiny_jal_wrappers.cpp)
namespace n0026ed20 {
u32 func_0026eda8(u32, u32, u32, u32) asm("_Z13func_0026eda8jjjj");
/*TARGET 0026ed20*/
// 0x00263660: definition moved into src/anon/unit_002632d0.cpp

u32 func_0026ed20(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0026ed20jjjj");
// 0x00263660: definition moved into src/anon/unit_002632d0.cpp

u32 func_0026ed20(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r2 = func_0026eda8(r4, r5, r6, r7);
    r14 = (u32)((s32)0u + (-1));
    r15 = (u32)(0x0036u << 16);
    *(u8*)((u32)r15 + (s32)(-3799)) = (u8)r14;
    return r2;
}
}  // namespace n0026ed20

// 0026ed48 (was src/anon/auto80_199_queue.cpp)
namespace n0026ed48 {
/*TARGET 0026ed48*/
void func_0026ed48() asm("_Z13func_0026ed48v");
void func_0026ed48() {
    if (D_0035f12c != 0) {
        return;
    }

    u32 p = func_00103570();
    u32 obj = func_001063c0(152, p);
    D_0035f12c = obj;
    func_002fde18(obj, 0, 152);
}
}  // namespace n0026ed48

// 0026eda8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0026eda8 {
u32 func_00106420(...) asm("func_00106420");
/*TARGET 0026eda8*/
void func_0026eda8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0026eda8jjjjjjjj");
void func_0026eda8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = (u32)(0x0036u << 16);
    r15 = *(u32*)((u32)r16 + (s32)(-3796));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00106420)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(u32*)((u32)r16 + (s32)(-3796)) = 0u;
    }
}
}  // namespace n0026eda8

// 0026ede0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0026ede0 {
void func_00271e08(...) asm("func_00271e08");
void func_00272340(...) asm("func_00272340");
u32 func_00287db0(...) asm("func_00287db0");
u32 func_00287bc0(...) asm("func_00287bc0");
// 0x00263eb8: definition moved into src/anon/unit_002632d0.cpp

extern "C" u32 func_00256e80(...) asm("func_00256e80");
/*TARGET 0026ede0*/
void func_0026ede0() asm("_Z13func_0026ede0v");
void func_0026ede0() {
    if ((u32)(func_00287bc0() - 25u) >= 9u) {
        return;
    }
    func_00271e08();
    func_00272340();
    if (func_00287db0() == 0u) {
        return;
    }
    func_00256e80();
}
}  // namespace n0026ede0

// 0026ee30 (was src/tozawa/cmenu_custom.cpp)
namespace Tz { // method 0026ee30
u32 func_00287bc0() asm("func_00287bc0");
void func_00271e80() asm("func_00271e80");
void func_002723e0() asm("func_002723e0");
void func_00256ea8() asm("func_00256ea8");
/*TARGET 0026ee30*/
void Tz_CmCustom_LeaveAll() asm("_ZN2Tz8CmCustom8LeaveAllEv");
void Tz_CmCustom_LeaveAll() {
    if ((u32)(func_00287bc0() - 25u) >= 9u) {
        return;
    }
    func_00271e80();
    func_002723e0();
    func_00256ea8();
}
}  // Tz

// .rodata 0x3738d0-0x3738e0
extern const u32 R_003738d0[2] asm("D_003738d0") __attribute__((aligned(4))) = { 0xc, 0x0 };
extern const u32 R_003738d8[2] asm("D_003738d8") __attribute__((aligned(4))) = { 0x90007, 0x8 };
