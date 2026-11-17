// Linked unit 0x0025f6b8-0x002632d0 (one namespace per old matched source; class methods in their own namespace).
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

// 0025f6b8 (was src/tozawa/cmenu_item.cpp)
namespace Tz { // method 0025f6b8
u32 CmItem::isPadHelpVisible() asm("_ZN2Tz6CmItem16isPadHelpVisibleEv");
/*TARGET 0025f6b8*/
void CmItem::FadeOutAll() {
    u32 v0 = (u32)MenuBase::GetMode();
    if (v0 != 1 && v0 != 10 && v0 != 11 && v0 != 12 && v0 != 13 && v0 != 14) {
        return;
    }
    FadeOutTop();
    FadeOutCategory();
    ScrollBar::FadeOut();
    FadeOutWarn();
    FadeOutStock();
    FadeOutHelp();
    if (isPadHelpVisible() != 0) {
        CmTop::FadeOutPadHelp();
    }
}
}  // Tz

// 0025f750 (was src/tozawa/cmenu_item.cpp)
namespace Tz { // method 0025f750
/*TARGET 0025f750*/
void CmItem::LeaveAll() {
    u32 v0 = (u32)MenuBase::GetMode();
    if (v0 != 1 && v0 != 10 && v0 != 11 && v0 != 12 && v0 != 13 && v0 != 14) {
        return;
    }
    LeaveTop();
    LeaveCategory();
    LeaveStock();
    LeaveWarn();
    LeaveHelp();
    LeavePopup();
    CmTop::LeavePadHelp();
}
}  // Tz

// 0025f7d8 (was src/anon/tiny_wrappers_more.cpp)
namespace n0025f7d8 {
u32 func_002817b8(u32, u32, u32, u32) asm("_Z13func_002817b8jjjj");
/*TARGET 0025f7d8*/
u32 func_0025f7d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0025f7d8jjjj");
u32 func_0025f7d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002817b8(a0, a1, a2, a3);
}
}  // namespace n0025f7d8

// 0025f7f0 (was src/anon/batch_w1612.cpp)
namespace n0025f7f0 {
struct E { u8 pad[408]; s32 f408; };
struct F { u8 pad[408]; };
struct Base { u8 pad[0x87d0]; F e[8]; };
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern void* D_0035f010 asm("D_0035f010");
extern void* D_0035f01c asm("D_0035f01c");
extern s32 D_0035ef68 asm("D_0035ef68");
extern s32 D_0035ef64 asm("D_0035ef64");
extern s32 D_0035f03c asm("D_0035f03c");
extern s32 D_0037327c asm("D_0037327c");
extern s32 D_00373278 asm("D_00373278");
Base* func_00257770(void) asm("func_00257770");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
s32 func_00281180(void*, s32) asm("func_00281180");
s32 func_00281140(void*, s32) asm("func_00281140");
s32 func_00257100(s32) asm("func_00257100");
void func_00288d80(void*, s32, s32, s32, s32, s32, s32, s32) asm("func_00288d80");
void func_00288e08(void*, s32, s32, s32) asm("func_00288e08");
E* func_002891b8(void*, s32) asm("func_002891b8");
void func_00139620(void*) asm("func_00139620");
void func_001395f8(void*) asm("func_001395f8");
s32 func_00192048(s32) asm("func_00192048");
s32 func_00285d58(s32) asm("func_00285d58");
s32 func_00285e30(s32) asm("func_00285e30");
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
s32 func_0023aa18(void*) asm("func_0023aa18");
s32 func_0023aa38(void*) asm("func_0023aa38");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
s32 func_00257070(s32) asm("func_00257070");
void func_00257050(s32, s32, s32) asm("func_00257050");
void func_002891f0(void*, s32, s32, s32, s32) asm("func_002891f0");
u32 func_0028af88(void*) asm("func_0028af88");
s32 func_00258068(s32) asm("func_00258068");
void func_0028af18(void*, u32) asm("func_0028af18");
void func_0025f7d8(void) asm("func_0025f7d8");
void func_00261b30(void) asm("func_00261b30");
void func_00261d48(void) asm("func_00261d48");
void func_00262af8(void) asm("func_00262af8");
void func_00256cc0(s32, s32, s32) asm("func_00256cc0");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 0025f7f0*/
void func_0025f7f0(s32 sel) asm("func_0025f7f0");
void func_0025f7f0(s32 sel) {
    s32 i, k;
    E* p;
    s32 save;
    Base* b = func_00257770();
    func_0028f4d8(0, -1, 0);
    save = D_0035f3d4;
    D_0035f3d4 = 30017;
    k = 0;
    for (i = 0; i < 4; i++) {
        if (func_00281180(D_0035f010, i)) {
            s32 x = func_00257100(0);
            func_00288d80(D_0035f01c, k, D_0035ef68, D_0035ef64, D_0035f03c, -1, x, func_00257100(1));
            func_00288e08(D_0035f01c, k, 0, -1);
            p = func_002891b8(D_0035f01c, k++);
            func_00139620(p);
            p->f408 = func_00281140(D_0035f010, i);
            func_001395f8(p);
        }
    }
    s32 x = func_00257100(0);
    func_00288d80(D_0035f01c, k, D_0035ef68, D_0035ef64, D_0035f03c, -1, x, func_00257100(1));
    func_00288e08(D_0035f01c, k, 0, -1);
    p = func_002891b8(D_0035f01c, k);
    func_00139620(p);
    p->f408 = func_00192048(0x8455);
    func_001395f8(p);
    i = D_0035f3d4 + 1;
    if (func_00285d58(-1)) {
        s32 t = func_00285e30(-1) ? D_0037327c : D_00373278;
        F* e = &b->e[k];
        func_0028d8c0(e, i, D_0035ef68, D_0035ef64, D_0035f03c, t, -1, 0);
        func_0028dcc0(e, p);
        s32 y = func_0023aa18((u8*)p + 24);
        func_00138c68(e, y, func_0023aa38((u8*)p + 24));
    }
    D_0035f3d4 = save;
    s32 v = func_00257070(1);
    if (sel >= 0 && sel != v) {
        func_00257050(2, 0, 0);
        func_00257050(1, sel, 0);
        v = sel;
    }
    func_002891f0(D_0035f01c, v, 1, 0, 2);
    u32 f = func_0028af88(D_0035f01c);
    if (func_00258068(1)) f |= 0x100;
    func_0028af18(D_0035f01c, f);
    func_0025f7d8();
    func_00261b30();
    func_00261d48();
    func_00262af8();
    if (func_00258068(1)) func_00256cc0(0xb619, -1, -1);
    func_00287cc0(0);
}
}  // namespace n0025f7f0

// 0025fb48 (was src/anon/batch_wcx2.cpp)
namespace n0025fb48 {
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
// ---- 0025fb48
extern void* D_0035f01c_fb48 asm("D_0035f01c");
extern void* D_0035f010_fb48 asm("D_0035f010");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00289380(void* s) asm("func_00289380");
s32 func_00289310_fb48(void* s) asm("func_00289310");
s32 func_00287c10(void) asm("func_00287c10");
s32 func_00262160(void) asm("func_00262160");
s32 func_00257970(void) asm("func_00257970");
s32 func_00256ef0(void) asm("func_00256ef0");
s32 func_0028f930(s32 a) asm("func_0028f930");
void func_00287f90(s32 a) asm("func_00287f90");
void func_00256ea8(void) asm("func_00256ea8");
void func_00262118(void) asm("func_00262118");
void func_0028f878(void) asm("func_0028f878");
void func_00287c30(void) asm("func_00287c30");
void func_0028af18_fb48(void* s, u32 a) asm("func_0028af18");
void func_0028f7e8(s32 a) asm("func_0028f7e8");
void func_002551b8(void) asm("func_002551b8");
void func_002678a8(void) asm("func_002678a8");
s32 func_002570a0(s32 a) asm("func_002570a0");
s32 func_00281100_fb48(void* p) asm("func_00281100");
void func_00277178(s32 a, s32 b) asm("func_00277178");
void func_002634c8(s32 a) asm("func_002634c8");
void func_00257050_fb48(s32 a, s32 b, s32 c) asm("func_00257050");
void func_0025ffd0(void) asm("func_0025ffd0");
s32 func_0028ae28(void* s, s32 a) asm("func_0028ae28");
void func_0028ab20(void* s) asm("func_0028ab20");
void func_00256e30(void) asm("func_00256e30");
void func_0028fa98(s32 a) asm("func_0028fa98");
void func_00287c90(s32 a) asm("func_00287c90");
s32 func_0028afa8_fb48(void* s) asm("func_0028afa8");
void func_002638e0(void) asm("func_002638e0");
s32 func_00287df0_fb48(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a) asm("func_00242848");
s32 func_00257070(s32 a) asm("func_00257070");
s32 func_002891e8_fb48(void* s) asm("func_002891e8");
void func_00287da0(void) asm("func_00287da0");
void func_00256e80(void) asm("func_00256e80");
void func_00263c60(void) asm("func_00263c60");
// sync_global_index_if_changed
void func_0028f6f0(s32 a) asm("func_0028f6f0");
// record884_refresh_by_index
void func_002620a0(void) asm("func_002620a0");
void func_00287c00(s32 m) asm("func_00287c00");
u8* func_002891b8_fb48(void* p, s32 n) asm("func_002891b8");
void func_0028fb68(s32 a, u32 b) asm("func_0028fb68");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
/*TARGET 0025fb48*/
// global_zero_4dwords

void func_0025fb48(void) asm("func_0025fb48");
// global_zero_4dwords

void func_0025fb48(void) {
    s32 cur = func_00289380(D_0035f01c_fb48);
    s32 st = func_00287cd0();
    if (st == 2) {
        s32 busy = 0;
        s32 next = func_00287c10();
        if (func_00262160() || func_00257970()) busy = 1;
        if (next != 2) busy = busy || func_00256ef0();
        if (busy || ((next == 0 || next == 15) && func_0028f930(0))) {
            if (cur == -1 && !func_00289310_fb48(D_0035f01c_fb48)) return;
            func_00287f90(0);
            if (next != 2) func_00256ea8();
            func_00262118();
            if (next == 0 || next == 15) func_0028f878();
            return;
        }
        func_00287c30();
        func_0028af18_fb48(D_0035f01c_fb48, 115);
        if (next == 0) {
            func_0028f7e8(0);
            func_002551b8();
        } else if (next == 2) {
            func_002678a8();
        } else if (next == 15) {
            s32 c = func_002570a0(1);
            if (!(c < func_00281100_fb48(D_0035f010_fb48))) c = 0;
            func_00277178(15, c);
        } else {
            func_00256ea8();
            func_002634c8(0);
            func_00257050_fb48(10, 0, 0);
            func_0025ffd0();
        }
        return;
    }
    if (cur != -1 || func_00289310_fb48(D_0035f01c_fb48)) {
        if (!func_0028ae28(D_0035f01c_fb48, 0)) {
            func_0028ab20(D_0035f01c_fb48);
            func_00256e30();
            func_0028fa98(-1);
        }
    }
    if (st == 0 && func_0028ae28(D_0035f01c_fb48, 0)) func_00287c90(1);
    s32 max = func_0028afa8_fb48(D_0035f01c_fb48);
    if (!func_00242848(func_00287df0_fb48(cur, func_00289310_fb48(D_0035f01c_fb48), 1, func_002638e0, 1))) {
        s32 m;
        switch (cur) {
        case -4: {
            s32 c = func_00257070(1);
            if (func_002891e8_fb48(D_0035f01c_fb48) != c) func_00257050_fb48(2, 0, 0);
            func_00257050_fb48(1, func_002891e8_fb48(D_0035f01c_fb48), 0);
            func_00287da0();
            break;
        }
        case -5:
            func_00256e80();
            func_00263c60();  // sync_global_index_if_changed
            func_0028f6f0(0);  // record884_refresh_by_index
            func_002620a0();
            func_00287c90(1);
            func_00287c00(15);
            {
                s32 c = func_00257070(1);
                if (func_002891e8_fb48(D_0035f01c_fb48) != c) func_00257050_fb48(2, 0, 0);
                func_00257050_fb48(1, func_002891e8_fb48(D_0035f01c_fb48), 0);
            }
            break;
        case -2:
            func_00256e80();
            func_00263c60();  // sync_global_index_if_changed
            func_0028f6f0(0);  // record884_refresh_by_index
            func_002620a0();
            func_00287c90(1);
            func_00287c00(0);
            {
                s32 c = func_00257070(1);
                if (func_002891e8_fb48(D_0035f01c_fb48) != c) func_00257050_fb48(2, 0, 0);
                func_00257050_fb48(1, func_002891e8_fb48(D_0035f01c_fb48), 0);
            }
            break;
        case -1:
            break;
        default:
            if (cur >= 0 && cur < max) {
                if (cur == max - 1) {
                    func_00256e80();
                    m = 10;
                } else {
                    m = 2;
                }
                func_0028fb68(1, *(u32*)(func_002891b8_fb48(D_0035f01c_fb48, cur) + 408));
                func_00263c60();  // sync_global_index_if_changed
                func_002620a0();
                func_00287c90(1);
                func_00287c00(m);
                s32 c = func_00257070(1);
                if (func_002891e8_fb48(D_0035f01c_fb48) != c) func_00257050_fb48(2, 0, 0);
                func_00257050_fb48(1, func_002891e8_fb48(D_0035f01c_fb48), 0);
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0025fb48

// 0025ffd0 (was src/anon/batch_w3909.cpp)
namespace n0025ffd0 {
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f03c asm("D_0035f03c");
extern u32 D_0035f04c asm("D_0035f04c");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef64 asm("D_0035ef64");
extern s32 D_0035ef6c asm("D_0035ef6c");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u8 D_00373280 asm("D_00373280");
u8* func_00257770(void) asm("func_00257770");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
u8* func_00256b68(s32) asm("func_00256b68");
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_002817d8(s32, u32, u32, u32, s32, u8*, s32) asm("func_002817d8");
void func_002634d8(s32) asm("func_002634d8");
s32 func_00257130(void) asm("func_00257130");
s32 func_00281f18(s32) asm("func_00281f18");
void func_00288d80(u32, s32, u32, u32, u32, s32, s16*, s16*) asm("func_00288d80");
u8* func_002891b8(u32, s32) asm("func_002891b8");
void func_00138c10(u8*, s32) asm("func_00138c10");
s32 func_0023aa98(u8*) asm("func_0023aa98");
s32 func_0023aa78(u8*) asm("func_0023aa78");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_00139620(u8*) asm("func_00139620");
void func_00263210(void) asm("func_00263210");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
u8* func_0023f1b0(u32) asm("func_0023f1b0");
s32 func_0023c4b8(u8*, u32) asm("func_0023c4b8");
s32 func_00236ca8(s32, u32) asm("func_00236ca8");
s32 func_002570f0(void) asm("func_002570f0");
void func_0028bae0(u32, s32, s32, s32, s32, s32, s32, u8*, s32) asm("func_0028bae0");
void func_00263858(s32) asm("func_00263858");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00257070(s32) asm("func_00257070");
s32 func_00257088(s32) asm("func_00257088");
void func_002891f0(u32, s32, s32, s32, s32) asm("func_002891f0");
void func_0028af90(u32, s32) asm("func_0028af90");
void func_0028afd0(u32, s32) asm("func_0028afd0");
void func_0028b078(u32, s32, s32) asm("func_0028b078");
void func_0028b218(u32, s32) asm("func_0028b218");
void func_0028b248(u32, s32) asm("func_0028b248");
s32 func_0028af88(u32) asm("func_0028af88");
void func_0028af18(u32, s32) asm("func_0028af18");
void func_0025f7d8(void) asm("func_0025f7d8");
void func_00262820(void) asm("func_00262820");
void func_00262a30(void) asm("func_00262a30");
void func_00257708(s32) asm("func_00257708");
s32 func_00262650(void) asm("func_00262650");
void func_002623c8(void) asm("func_002623c8");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 0025ffd0*/
void func_0025ffd0(void) asm("func_0025ffd0");
void func_0025ffd0(void)
{
    s16 tab[2][4];
    s32 cnt;
    s32 saved;
    s32 i = 0;
    u8* p;
    u8* base = func_00257770();
    func_0028f4d8(1, -1, 0);
    for (; i < 2; i++) {
        for (s32 k = 0; k < 4; k++) tab[i][k] = (i == 0) + 303;
    }
    u8* h = func_00256b68(1);
    func_0028d8c0(h, 0x753d, D_0035ef68, D_0035ef64, D_0035f03c, 293, 294, 0);
    u8* t = h + 24;
    *(s32*)(t + 184) |= 8;
    func_002817d8(0x753f, D_0035ef68, D_0035ef64, D_0035f03c, 0, &D_00373280, 0);
    saved = D_0035f3d4;
    D_0035f3d4 = 0x753e;
    func_002634d8(-1);
    cnt = func_00281f18(func_00257130());
    u8* q = base + 0x87d0;
    for (i = 0; i < 18; ) {
        func_00288d80(D_0035f01c, i, D_0035ef68, D_0035ef64, D_0035f03c, -1, tab[0], tab[1]);
        p = func_002891b8(D_0035f01c, i);
        func_00138c10(p, 304);
        *(s32*)(p + 392) = -1;
        u8* b = p + 24;
        s32 w = func_0023aa98(b);
        s32 hh = func_0023aa78(b);
        s32 x = func_0023aa18(b);
        s32 y = func_0023aa38(b);
        func_00138c68(p, (i % 2) * w, (i / 2) * hh);
        func_00139620(p);
        if (i++ < cnt) *(void (**)(void))(p + 436) = func_00263210;
        func_0028dcc0(p, h);
        func_0028d8c0(q, 0x7540, D_0035ef68, D_0035ef64, D_0035f03c, D_0035ef6c, -1, 0);
        func_0028dcc0(q, p);
        func_00138c68(q, x, y);
        q += 408;
    }
    D_0035f3d4 = saved;
    s32 n = cnt ? cnt : 1;
    h = func_00256b68(1);
    s32 c = func_0023c4b8(func_0023f1b0(D_0035f03c), D_0035ef68);
    s32 d = func_00236ca8(*(s32*)(func_0023f1b0(D_0035f03c) + 40), D_0035ef64);
    // p is reused for the half count (one pseudo for p and half gives the original registers)
    p = (u8*)(n / 2);
    p += n & 1;
    func_0028bae0(D_0035f04c, 0x753e, c, d, func_002570f0(), (s32)p, 9, h, 0);
    func_00263858(n);
    d = func_00287bc0();
    func_002891f0(D_0035f01c, func_00257070(d), 1, 0, 2);
    func_0028af90(D_0035f01c, n);
    func_0028afd0(D_0035f01c, func_00257088(d));
    func_0028b078(D_0035f01c, 2, 9);
    func_0028b218(D_0035f01c, 1);
    func_0028b248(D_0035f01c, 18);
    s32 fl = func_0028af88(D_0035f01c);
    fl |= 0xc000;
    if (!cnt) fl &= ~0x10;
    func_0028af18(D_0035f01c, fl);
    func_0025f7d8();
    func_00262820();
    func_00262a30();
    if (!cnt) func_00257708(1);
    if (!func_00262650()) func_002623c8();
    func_00287cc0(0);
}
}  // namespace n0025ffd0

// 00260418 (was src/anon/batch_w1614.cpp)
namespace n00260418 {
extern u32 D_0035f01c asm("D_0035f01c");
// 0x0025aa10: definition moved into src/anon/unit_002588e8.cpp
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287c10(void) asm("func_00287c10");
s32 func_00262650(void) asm("func_00262650");
s32 func_0028f930(s32) asm("func_0028f930");
s32 func_00262290(void) asm("func_00262290");
s32 func_00257970(void) asm("func_00257970");
s32 func_00281c30(void) asm("func_00281c30");
s32 func_00289310(s32) asm("func_00289310");
void func_00287f90(s32) asm("func_00287f90");
void func_00262208(void) asm("func_00262208");
void func_00262588(void) asm("func_00262588");
void func_00257708(s32) asm("func_00257708");
void func_00287c30(void) asm("func_00287c30");
void func_0028b0e0(s32) asm("func_0028b0e0");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0028af18(s32, s32) asm("func_0028af18");
void func_0028f7e8(s32) asm("func_0028f7e8");
void func_0025f7f0(s32) asm("func_0025f7f0");
void func_0025ffd0(void) asm("func_0025ffd0");
void func_00260808(void) asm("func_00260808");
s32 func_00262300(void) asm("func_00262300");
void func_00262360(void) asm("func_00262360");
void func_00262730(void) asm("func_00262730");
void func_0028fa98(s32) asm("func_0028fa98");
void func_00287c90(s32) asm("func_00287c90");
void func_002638e0(void) asm("func_002638e0");
s32 func_00287df0_p(s32, s32, s32, void (*)(void), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00287da0(void) asm("func_00287da0");
void func_00263570(s32) asm("func_00263570");
void func_00263c60(void) asm("func_00263c60");
void func_002621a0(void) asm("func_002621a0");
void func_00281b30(void) asm("func_00281b30");
void func_00287c00(s32) asm("func_00287c00");
void func_00257050(s32, s32, s32) asm("func_00257050");
void func_0025f7d8(void) asm("func_0025f7d8");
void func_00262538(void) asm("func_00262538");
s32 func_002891e8(s32) asm("func_002891e8");
s32 func_0028b038(s32) asm("func_0028b038");
void func_0028f6f0(s32) asm("func_0028f6f0");
void func_00281d48(void) asm("func_00281d48");
void func_00281e20(void) asm("func_00281e20");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
/*TARGET 00260418*/
void func_00260418(void) asm("func_00260418");
void func_00260418(void)
{
    s32 x = 0;
    s32 r = func_00289380(D_0035f01c);
    s32 st = func_00287cd0();
    if (st == 2) {
        st = func_00287c10();
        if (st != 10) {
            x = func_00262650();
            if (st == 1) x = x || func_0028f930(1);
        }
        if (func_00262290() || x || func_00257970() || func_00281c30()) {
            if (r != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                func_00262208();
                if (st != 10) func_00262588();
            }
            return;
        }
        func_00257708(0);
        func_00287c30();
        func_0028b0e0(D_0035f01c);
        s32 m = func_00287bc0();
        func_0028af18(D_0035f01c, 115);
        if (m == 1) {
            func_0028f7e8(1);
            func_0025f7f0(-1);
        } else if (m == 10) {
            func_0025ffd0();
        } else if (m == 11) {
            func_00260808();
        }
        return;
    }
    if ((r != -1 || func_00289310(D_0035f01c)) && !func_00262300()) {
        func_00262360();
        func_00262730();
        func_0028fa98(-1);
    }
    if (st == 0 && func_00262300()) func_00287c90(1);
    if (!func_00242848(func_00287df0_p(r, func_00289310(D_0035f01c), 1, func_002638e0, 1))) {
        switch (r) {
        case -4:
            func_00287da0();
            break;
        case -1:
            break;
        case -11:
        case -10:
            func_00263570(r);
            func_00263c60();
            func_002621a0();
            func_00281b30();
            func_00287c90(1);
            func_00287c00(func_00287bc0());
            func_00257050(10, 0, 0);
            func_0025f7d8();
            break;
        default:
            func_00263c60();
            func_002621a0();
            func_00262538();
            func_00281b30();
            func_00287c90(1);
            func_00287c00(11);
            {
                s32 a = func_002891e8(D_0035f01c);
                func_00257050(10, a, func_0028b038(D_0035f01c));
            }
            func_0025f7d8();
            break;
        case -2:
            func_00263c60();
            func_00262538();
            func_0028f6f0(1);
            func_002621a0();
            func_00281b30();
            func_00287c90(1);
            func_00287c00(1);
            func_0025f7d8();
            func_00257050(10, 0, 0);
            break;
        }
    }
    if (func_00287cd0() == 1) {
        func_00281d48();
        func_00281e20();
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n00260418

// 00260808 (was src/anon/batch_w3819.cpp)
namespace n00260808 {
u8* func_00257770(void) asm("func_00257770");
s32 func_00139d78(void*) asm("func_00139d78");
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void func_002817d8(s32, s32, s32, s32, s32, s32, s32) asm("func_002817d8");
void func_00281e70(void*) asm("func_00281e70");
void func_0025f7d8(void) asm("func_0025f7d8");
s32 func_00257070(s32) asm("func_00257070");
s32 func_00257130(void) asm("func_00257130");
s32 func_00281f30(s32) asm("func_00281f30");
void func_00139620(void*) asm("func_00139620");
void func_001395f8(void*) asm("func_001395f8");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
s32 func_00257140(s32) asm("func_00257140");
s32 func_0023aa18(void*) asm("func_0023aa18");
s32 func_0023aa38(void*) asm("func_0023aa38");
s32 func_0023aa78(void*) asm("func_0023aa78");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
s32 func_002570a0(s32) asm("func_002570a0");
s32 func_002635d8(s32) asm("func_002635d8");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_00288d80(void*, s32, s32, s32, s32, s32, s16*, s16*) asm("func_00288d80");
u8* func_002891b8(void*, s32) asm("func_002891b8");
s32 func_00263660(s32) asm("func_00263660");
s32 func_002637e8(s32) asm("func_002637e8");
u32 func_00192048(u16) asm("func_00192048");
void func_002891f0(void*, s32, s32, s32, s32) asm("func_002891f0");
u16* func_002632d0(s32) asm("func_002632d0");
void func_00291068(void*, s32, u16, void*, s32, s32) asm("func_00291068");
void func_00262af8(void) asm("func_00262af8");
s32 func_00281c30(void) asm("func_00281c30");
void func_00281cf0(u16) asm("func_00281cf0");
void func_00287cc0(s32) asm("func_00287cc0");
extern "C" s32 D_0035f3d4;
/* The asm label only changes the symbol text gcse hashes: with it the three
   high-part pseudos get the original stack slot order (sp+32/36/40). */
extern s32 D_0035ef68 asm("D_0035ef68");
extern "C" s32 D_0035ef64;
extern "C" s32 D_0035f03c;
extern "C" void* D_0035f01c;
extern "C" void* D_0035f018;
extern "C" u16 D_00373298[];
/*TARGET 00260808*/
/* Sets up the menu objects for the current level, then one or two entries
   (436-byte objects at base+24304) in a loop. */
void func_00260808(void) asm("func_00260808");
/* Sets up the menu objects for the current level, then one or two entries
   (436-byte objects at base+24304) in a loop. */
void func_00260808(void) {
    s16 tbl[2][4];
    u8* base;
    s32 i;
    s32 j;
    s32 r;
    s32 h;
    s32 lvl;
    s32 lm;
    u8* p;
    u8* q;
    u8* q2;
    u8* e;
    u8* o;
    u8* m;
    s32 x;
    s32 y;
    s32 k;
    s32 mo = -1;
    s32 n;
    s32 r2;

    i = 0;
    r = 0;
    base = func_00257770();
    for (; i < 2; i++) {
        for (j = 0; j < 4; j++) tbl[i][j] = 0x123;
    }
    lvl = D_0035f3d4;
    lm = lvl - 1;
    if (!func_00139d78(base)) func_0028d8c0(base, lm, D_0035ef68, D_0035ef64, D_0035f03c, 296, 297, 0);
    p = base + 0xb350;
    if (!func_00139d78(p)) func_0028d980(p, lm, D_0035ef68, D_0035ef64, D_0035f03c, 305, 306, -1, 0);
    q = base + 0x660;
    func_002817d8(lvl, D_0035ef68, D_0035ef64, D_0035f03c, 0, 0, 0);
    func_00281e70(p);
    func_0025f7d8();
    h = func_00257070(10);
    if (!func_00139d78(q)) {
        func_0028d980(q, lvl, D_0035ef68, D_0035ef64, D_0035f03c, 292, -1, -1, 0);
        r = func_00281f30(func_00257130());
        func_00139620(q);
        func_0028dcc0(q, base);
        *(s32*)(q + 408) = r + h * 80 + 16;
    }
    q2 = base + 0xd30;
    if (!func_00139d78(q2)) {
        func_0028d980(q2, lvl + 1, D_0035ef68, D_0035ef64, D_0035f03c, func_00257140(2), -1, -1, 0);
        func_00139620(q2);
        func_001395f8(q2);
        func_0028dcc0(q2, q);
        m = base + 1656;
        x = func_0023aa18(m);
        y = func_0023aa38(m);
        func_00138c68(q2, x, y);
        *(s32*)(q2 + 432) = 1;
        *(s32*)(q2 + 408) = r + h * 80;
    }
    h = func_002570a0(10);
    r2 = func_002635d8(h) ? 2 : 1;
    if (!func_0028acc8(D_0035f01c)) {
        i = 0;
        if (i < r2) { o = base + 24304; do {
            func_00288d80(D_0035f01c, i, D_0035ef68, D_0035ef64, D_0035f03c, mo, tbl[0], tbl[1]);
            e = func_002891b8(D_0035f01c, i);
            *(s32*)(e + 392) = mo;
            func_00138c68(e, 0, func_0023aa78(e + 24) * i);
            func_00139620(e);
            func_0028dcc0(e, base);
            if (!func_00263660(h) && func_002637e8(i)) k = 1; else k = 0;
            func_0028d980(o, lvl + 1, D_0035ef68, D_0035ef64, D_0035f03c,
                          func_00257140(k), -1, -1, 0);
            func_00139620(o);
            func_001395f8(o);
            func_0028dcc0(o, e);
            n = i;
            n++;
            if (!func_002635d8(h)) i = n;
            *(u32*)(o + 408) = func_00192048(D_00373298[i]);
            i = n;
            o += 436;
        } while (i < r2); }
        func_002891f0(D_0035f01c, 0, 1, 0, 2);
    }
    func_00291068(D_0035f018, 0, *func_002632d0(h), base + 0xb350, -1, 0);
    func_00262af8();
    if (!func_00281c30()) func_00281cf0(func_002632d0(h)[10]);
    func_00287cc0(0);
}
}  // namespace n00260808

// 00260ce0 (was src/anon/batch_w1611.cpp)
namespace n00260ce0 {
s32 func_00242848(s32) asm("func_00242848");
s32 func_00287bc0() asm("func_00287bc0");
void func_00287c00(s32) asm("func_00287c00");
void func_00287c30() asm("func_00287c30");
void func_00287c90(s32) asm("func_00287c90");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00287cd0() asm("func_00287cd0");
void func_00287da0() asm("func_00287da0");
s32 func_00287df0(s32, s32, s32, void*, s32) asm("func_00287df0");
void func_00287f90(s32) asm("func_00287f90");
void func_00288018() asm("func_00288018");
s32 func_00288040() asm("func_00288040");
s32 func_00289310(void*) asm("func_00289310");
s32 func_00289380(void*) asm("func_00289380");
void func_0028af18(void*, s32) asm("func_0028af18");
extern void* D_0035f01c asm("D_0035f01c");
extern void* D_0035f018 asm("D_0035f018");
s32 func_00287c10() asm("func_00287c10");
s32 func_002631d8() asm("func_002631d8");
s32 func_00262e30() asm("func_00262e30");
s32 func_00281c30() asm("func_00281c30");
s32 func_002911f8(void*) asm("func_002911f8");
void func_00281c50() asm("func_00281c50");
void func_00291288(void*) asm("func_00291288");
void func_00262cb8() asm("func_00262cb8");
void func_002631f8() asm("func_002631f8");
void func_0025ffd0() asm("func_0025ffd0");
void func_00261000() asm("func_00261000");
void func_00257718(s32) asm("func_00257718");
s32 func_00262f18() asm("func_00262f18");
void func_00262f58() asm("func_00262f58");
s32 func_002637e8(s32) asm("func_002637e8");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00261820() asm("func_00261820");
void func_00281b30() asm("func_00281b30");
void func_0025f7d8() asm("func_0025f7d8");
void func_002631b0() asm("func_002631b0");
void func_00263c60() asm("func_00263c60");
void func_00262c40() asm("func_00262c40");
void func_00281d48() asm("func_00281d48");
void func_00281e20() asm("func_00281e20");
extern char D_002638e0[] asm("D_002638e0");
/*TARGET 00260ce0*/
void func_00260ce0(void) asm("func_00260ce0");
void func_00260ce0(void) {
    s32 sel = func_00289380(D_0035f01c);
    s32 st = func_00287cd0();
    if (st == 2) {
        s32 m, f, mode;
        m = func_00287c10();
        if (m != 10) goto L1;
        f = func_00262e30();
    L2:
        if (!f) {
            if (func_00281c30() || func_002911f8(D_0035f018)) f = 1;
        }
        if (f) {
            if (sel == -1 && !func_00289310(D_0035f01c)) return;
            func_00287f90(0);
            func_00281c50();
            func_00291288(D_0035f018);
            if (m == 10) func_00262cb8();
            else func_002631f8();
            return;
        }
        func_00287c30();
        mode = func_00287bc0();
        func_0028af18(D_0035f01c, 0x73);
        if (mode == 10) func_0025ffd0();
        else func_00261000();
        func_00257718(1);
        return;
    L1:
        f = func_002631d8();
        goto L2;
    }
    if ((sel != -1 || func_00289310(D_0035f01c)) && !func_00262f18()) {
        func_00262f58();
    }
    if (st == 0 && func_00262f18()) {
        func_00287c90(1);
    }
    if (!func_00242848(func_00287df0(sel, func_00289310(D_0035f01c), 1, D_002638e0, 1))) {
        switch (sel) {
        default:
            if (!func_002637e8(sel)) {
                func_00257718(0);
                func_00281b30();
                func_0025f7d8();
                func_002631b0();
                func_00287c00(12);
                func_00287c90(1);
            } else {
                func_00287bd0(14, 0);
                func_00261820();
                func_00287cc0(1);
            }
            break;
        case -4:
            func_00287da0();
            break;
        case -1:
            break;
        case -2:
            func_00263c60();
            func_00262c40();
            func_00281b30();
            func_00287c90(1);
            func_00287c00(10);
            func_0025f7d8();
            break;
        }
    }
    if (func_00287cd0() == 1) {
        func_00281d48();
        func_00281e20();
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n00260ce0

// 00261000 (was src/anon/batch_w1609.cpp)
namespace n00261000 {
s32 func_00192048(u32) asm("func_00192048");
void func_00287cc0(s32) asm("func_00287cc0");
// 0x00259998: definition moved into src/anon/unit_002588e8.cpp
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035ef68 asm("D_0035ef68");
extern s32 D_0035ef64 asm("D_0035ef64");
extern s32 D_0035f03c asm("D_0035f03c");
extern s32 D_0035f020 asm("D_0035f020");
extern s32 D_0035f010 asm("D_0035f010");
u8* func_00257770(void) asm("func_00257770");
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
s32 func_00257130(void) asm("func_00257130");
void func_00281f30(s32) asm("func_00281f30");
void func_00139620(u8*) asm("func_00139620");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
s32 func_002570a0(s32) asm("func_002570a0");
s32 func_00263688(s32) asm("func_00263688");
s32 func_002636b0(s32) asm("func_002636b0");
s32 func_00281100(s32) asm("func_00281100");
s32 func_00281140(s32, s32) asm("func_00281140");
void func_00288d80(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("func_00288d80");
u8* func_002891b8(s32, s32) asm("func_002891b8");
s32 func_0023aa78(u8*) asm("func_0023aa78");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_0028b1e8(s32, s32) asm("func_0028b1e8");
void func_002891f0(s32, s32, s32, s32, s32) asm("func_002891f0");
void func_00288f48(s32, s32, s32, s32, s32) asm("func_00288f48");
u8* func_00281f20(s32) asm("func_00281f20");
s32 func_0027ed48(u16) asm("func_0027ed48");
void func_0027dee8(s32, s32, s32) asm("func_0027dee8");
/*TARGET 00261000*/
void func_00261000(void) asm("func_00261000");
void func_00261000(void)
{
    s16 h[2][4];
    s32 i, j, n, k, cnt;
    u8* base = func_00257770();
    for (i = 0; i < 2; i++)
        for (j = 0; j < 4; j++)
            h[i][j] = 291;
    n = D_0035f3d4;
    u8* a = base + 408;
    u8* b = base + 2068;
    func_0028d8c0(a, n - 1, D_0035ef68, D_0035ef64, D_0035f03c, 299, 300, 0);
    func_0028d980(b, n, D_0035ef68, D_0035ef64, D_0035f03c, 292, -1, -1, 0);
    func_00281f30(func_00257130());
    func_00139620(b);
    func_0028dcc0(b, a);
    *(s32*)(b + 408) = func_00192048(0xb943);
    k = func_002570a0(10);
    if (func_00263688(k) || func_002636b0(k)) cnt = 1;
    else cnt = func_00281100(D_0035f010);
    for (i = 0; i < cnt; i++) {
        func_00288d80(D_0035f020, i, D_0035ef68, D_0035ef64, D_0035f03c, -1, h[0], h[1]);
        u8* p = func_002891b8(D_0035f020, i);
        *(s32*)(p + 392) = -1;
        func_00138c68(p, 0, func_0023aa78(p + 24) * i);
        func_00139620(p);
        func_0028dcc0(p, a);
        *(s32*)(p + 408) = func_00263688(k) ? func_00192048(0xb944) : func_00281140(D_0035f010, i);
    }
    func_0028b1e8(D_0035f020, 1);
    func_002891f0(D_0035f020, 0, 1, 0, 2);
    func_00288f48(D_0035f020, 16, 32, 0, 0);
    s32 t = func_0027ed48(*(u16*)(func_00281f20(func_00257130()) + k * 6));
    func_0027dee8(1, t, func_002636b0(k) ? 0 : 4);
    func_00287cc0(0);
}
}  // namespace n00261000

// 002612c8 (was src/anon/batch_w1610.cpp)
namespace n002612c8 {
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287c10(void) asm("func_00287c10");
s32 func_00289310(s32) asm("func_00289310");
void func_00287f90(s32) asm("func_00287f90");
void func_00287c30(void) asm("func_00287c30");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, void (*)(void), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00287c00(s32) asm("func_00287c00");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
void func_00287da0(void) asm("func_00287da0");
extern s32 D_0035f020 asm("D_0035f020");
s32 func_002630d8(void) asm("func_002630d8");
s32 func_00262e30(void) asm("func_00262e30");
void func_00262ff8(void) asm("func_00262ff8");
void func_00262cb8(void) asm("func_00262cb8");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0028b1e8(s32, s32) asm("func_0028b1e8");
void func_0028af18(s32, s32) asm("func_0028af18");
void func_0025ffd0(void) asm("func_0025ffd0");
void func_00260808(void) asm("func_00260808");
s32 func_00263160(void) asm("func_00263160");
void func_00263188(void) asm("func_00263188");
s32 func_002638e0(s32) asm("func_002638e0");
s32 func_00263720(s32) asm("func_00263720");
void func_00242618(s32, s32) asm("func_00242618");
void func_00263778(s32) asm("func_00263778");
void func_00262fa0(void) asm("func_00262fa0");
void func_00262c40(void) asm("func_00262c40");
void func_00257728(void) asm("func_00257728");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_002615b0(void) asm("func_002615b0");
void func_00287cc0(s32) asm("func_00287cc0");
void func_0027e6e0(void) asm("func_0027e6e0");
/*TARGET 002612c8*/
void func_002612c8(void) asm("func_002612c8");
void func_002612c8(void) {
    s32 r = func_00289380(D_0035f020);
    s32 st = func_00287cd0();
    if (st == 2) {
        s32 m = func_00287c10();
        s32 v = func_002630d8();
        if (!v && m == 10) v = func_00262e30();
        if (v) {
            if (r != -1 || func_00289310(D_0035f020)) {
                func_00287f90(0);
                func_00262ff8();
                if (m == 10) func_00262cb8();
            }
        } else {
            func_00287c30();
            r = func_00287bc0();
            func_0028b1e8(D_0035f020, 0);
            func_0028af18(D_0035f020, 115);
            if (r == 10) func_0025ffd0();
            else if (r == 11) func_00260808();
        }
        return;
    }
    if ((r != -1 || func_00289310(D_0035f020)) && func_00263160() == 0) {
        func_00263188();
    }
    if (st == 0 && func_00263160()) {
        func_00287c90(1);
    }
    if ((r >= 0 && func_002638e0(r)) || func_00242848(func_00287df0(r, func_00289310(D_0035f020), 1, (void (*)(void))func_002638e0, 1)) == 0) {
        switch (r) {
        case -2:
            func_00262fa0();
            func_00287c90(1);
            func_00287c00(11);
            break;
        default:
            if (func_00263720(r)) {
                func_00242618(17, 1);
                func_00263778(r);
                func_00262fa0();
                func_00262c40();
                func_00287c90(1);
                func_00257728();
                func_00287c00(10);
            } else {
                func_00242618(8, 1);
                func_00287bd0(13, 0);
                func_002615b0();
                func_00287cc0(1);
            }
            break;
        case -4:
            func_0027e6e0();
            func_00287da0();
            break;
        case -1:
            break;
        }
    }
    if (func_00288040()) {
        func_00288018();
    }
}
}  // namespace n002612c8

// 002615b0 (was src/anon/batch_w1580_g.cpp)
namespace n002615b0 {
s32 func_00192048(s32) asm("func_00192048");
void func_00192e50(s32, s32, s32, s32, s32) asm("func_00192e50");
s32 func_002570a0(s32) asm("func_002570a0");
void func_002571e0(s32) asm("func_002571e0");
void func_00257458(s32, s32) asm("func_00257458");
u8* func_00257770(void) asm("func_00257770");
u16 func_002594b8(u8) asm("func_002594b8");
u8* func_002632d0(s32) asm("func_002632d0");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 002615b0*/
void func_002615b0(void) asm("func_002615b0");
void func_002615b0(void) {
    s32 base = (s32)func_00257770();
    u8* p = func_002632d0(func_002570a0(10));
    s32 a = func_00192048(0xBB90);
    s32 b = func_00192048(func_002594b8(p[2]));
    s32 c = func_00192048(*(u16*)(p + 8));
    base += 0xB290;
    func_00192e50(a, base, 0xC0, b, c);
    func_00257458(base, 0);
    func_002571e0(0);
    func_00287cc0(0);
}
}  // namespace n002615b0

// 00261668 (was src/anon/batch_wcx2.cpp)
namespace n00261668 {
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
// 0x0025dbd8: definition moved into src/anon/unit_0025da20.cpp

// --------------------
extern s32 D_0035f024_261b asm("D_0035f024");
s32 func_00289380_x10550(s32) asm("func_00289380");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00287c10() asm("func_00287c10");
s32 func_002576d0() asm("func_002576d0");
s32 func_00289310_x10554(s32) asm("func_00289310");
void func_00287f90(s32) asm("func_00287f90");
void func_002575a8() asm("func_002575a8");
void func_00287c30() asm("func_00287c30");
s32 func_00287bc0() asm("func_00287bc0");
void func_0028af18_x10559(s32, s32) asm("func_0028af18");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00257610(s32) asm("func_00257610");
void func_00257670(s32) asm("func_00257670");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00257530(s32) asm("func_00257530");
void func_00287c00(s32) asm("func_00287c00");
/*TARGET 00261668*/
void func_00261668() asm("func_00261668");
void func_00261668() {
    s32 r = func_00289380_x10550(D_0035f024_261b);
    s32 a = func_00287cd0();
    if (a == 2) {
        func_00287c10();
        if (!func_002576d0()) goto idle;
        if (r != -1 || func_00289310_x10554(D_0035f024_261b)) {
            func_00287f90(0);
            func_002575a8();
        }
        return;
    idle:
        func_00287c30();
        func_00287bc0();
        func_0028af18_x10559(D_0035f024_261b, 115);
        func_00287cc0(1);
        return;
    }
    if (r != -1 || func_00289310_x10554(D_0035f024_261b)) {
        if (!func_00257610(0)) func_00257670(0);
    }
    if (!a && func_00257610(0)) func_00287c90(1);
    if (func_00242848(func_00287df0(r, func_00289310_x10554(D_0035f024_261b), 0, 0, 1))) return;
    switch (r) {
    case -4: case -3: case -1:
        break;
    case -2: case 0: case 1:
        func_00257530(0);
        func_00287c90(1);
        func_00287c00(12);
        break;
    }
}
}  // namespace n00261668

// 00261820 (was src/anon/batch_w1580_g.cpp)
namespace n00261820 {
s32 func_00192048(s32) asm("func_00192048");
void func_00192e50(s32, s32, s32, s32, s32) asm("func_00192e50");
s32 func_002570a0(s32) asm("func_002570a0");
void func_002571e0(s32) asm("func_002571e0");
void func_00257458(s32, s32) asm("func_00257458");
u8* func_00257770(void) asm("func_00257770");
u16 func_002594b8(u8) asm("func_002594b8");
u8* func_002632d0(s32) asm("func_002632d0");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 00261820*/
void func_00261820(void) asm("func_00261820");
void func_00261820(void) {
    s32 base = (s32)func_00257770();
    u8* p = func_002632d0(func_002570a0(10));
    s32 a = func_00192048(0xB94F);
    s32 b = func_00192048(func_002594b8(p[2]));
    s32 c = func_00192048(*(u16*)(p + 8));
    base += 0xB290;
    func_00192e50(a, base, 0xC0, b, c);
    func_00257458(base, 0);
    func_002571e0(1);
    func_00287cc0(0);
}
}  // namespace n00261820

// 002618d8 (was src/anon/batch_wcx2.cpp)
namespace n002618d8 {
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
// 0x00259fb8: definition moved into src/anon/unit_002588e8.cpp

// --------------------
extern s32 D_0035f024_261 asm("D_0035f024");
s32 func_00289380_x9720(s32) asm("func_00289380");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00287c10() asm("func_00287c10");
s32 func_002576d0() asm("func_002576d0");
s32 func_00262e30() asm("func_00262e30");
s32 func_00289310_x9725(s32) asm("func_00289310");
void func_00287f90(s32) asm("func_00287f90");
void func_002575a8() asm("func_002575a8");
void func_00262cb8() asm("func_00262cb8");
void func_00287c30() asm("func_00287c30");
s32 func_00287bc0() asm("func_00287bc0");
void func_0028af18_x9731(s32, s32) asm("func_0028af18");
void func_0025ffd0() asm("func_0025ffd0");
void func_00260808() asm("func_00260808");
s32 func_00257610(s32) asm("func_00257610");
void func_00257670(s32) asm("func_00257670");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00257530(s32) asm("func_00257530");
void func_00287c00(s32) asm("func_00287c00");
s32 func_002570a0(s32) asm("func_002570a0");
u16* func_002632d0(s32) asm("func_002632d0");
void func_001a3458(s32, s32) asm("func_001a3458");
void func_00262c40() asm("func_00262c40");
/*TARGET 002618d8*/
void func_002618d8() asm("func_002618d8");
void func_002618d8() {
    s32 r = func_00289380_x9720(D_0035f024_261);
    s32 a = func_00287cd0();
    if (a == 2) {
        s32 st = func_00287c10();
        s32 v = func_002576d0();
        if (v == 0) {
            if (st == 10) v = func_00262e30();
            if (v == 0) goto idle;
        }
        if (r != -1 || func_00289310_x9725(D_0035f024_261)) {
            func_00287f90(0);
            func_002575a8();
            if (st == 10) func_00262cb8();
        }
        return;
    idle: {
        func_00287c30();
        s32 s = func_00287bc0();
        func_0028af18_x9731(D_0035f024_261, 115);
        if (s == 10) func_0025ffd0();
        else if (s == 11) func_00260808();
        return;
    }
    }
    if (r != -1 || func_00289310_x9725(D_0035f024_261)) {
        if (!func_00257610(0)) func_00257670(0);
    }
    if (!a && func_00257610(0)) func_00287c90(1);
    if (func_00242848(func_00287df0(r, func_00289310_x9725(D_0035f024_261), 0, 0, 1))) return;
    switch (r) {
    case -2: case 0:
        func_00257530(0);
        func_00287c90(1);
        func_00287c00(11);
        break;
    case 1:
        func_001a3458(*func_002632d0(func_002570a0(10)), 100);
        func_00257530(0);
        func_00262c40();
        func_00287c90(1);
        func_00287c00(10);
        break;
    case -4: case -3: case -1:
        break;
    }
}
}  // namespace n002618d8

// 00261b30 (was src/anon/batch_w110.cpp)
namespace n00261b30 {
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef6c asm("D_0035ef6c");
extern u32 D_0035f03c asm("D_0035f03c");
u8* func_00257770(void) asm("func_00257770");
s32 func_00139d78(u8*) asm("func_00139d78");
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028d980(u8*, s32, u32, u32, u32, s32, s32, s32, s32) asm("func_0028d980");
s32 func_0023aa98(u8*) asm("func_0023aa98");
s32 func_0023aa78(u8*) asm("func_0023aa78");
void func_00138c10(u8*, u32) asm("func_00138c10");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_00139688(u8*) asm("func_00139688");
void func_00139620(u8*) asm("func_00139620");
s32 func_00257140(s32) asm("func_00257140");
void func_001395f8(u8*) asm("func_001395f8");
/*TARGET 00261b30*/
// Builds the 20 grid cells (2 columns) of the window and their labels.
void func_00261b30(void) asm("func_00261b30");
// Builds the 20 grid cells (2 columns) of the window and their labels.
void func_00261b30(void) {
    u8* w = func_00257770();
    func_00139d78(w);
    func_0028d8c0(w, 30013, D_0035ef68, D_0035ef64, D_0035f03c, 140, 141, 100);
    u8* p = w;
    s32 i = 0;
    do {
        u8* cell = p + 13840;
        func_0028d980(cell, 30014, D_0035ef68, D_0035ef64, D_0035f03c, 150, -1, -1, 100);
        u8* label = p + 24304;
        s32 h = func_0023aa98(p + 13864);
        s32 wd = func_0023aa78(p + 13864);
        p += 436;
        func_00138c10(cell, D_0035ef6c);
        func_00138c68(cell, (i % 2) * h, (i / 2) * wd);
        func_0028dcc0(cell, w);
        func_00139688(cell);
        func_00139620(cell);
        func_0028d980(label, 30015, D_0035ef68, D_0035ef64, D_0035f03c, func_00257140(0), -1, -1, 100);
        func_0028dcc0(label, cell);
        func_00139620(label);
        func_001395f8(label);
        i++;
    } while (i < 20);
}
}  // namespace n00261b30

// 00261ce8 (was src/anon/batch_w1580_g.cpp)
namespace n00261ce8 {
extern s32 D_0035f010 asm("D_0035f010");
s32 func_00257130(void) asm("func_00257130");
s32 func_00281198(s32, s32) asm("func_00281198");
void func_00282240(s32, s32, s32) asm("func_00282240");
void func_002827f0(s32, s32, s32) asm("func_002827f0");
/*TARGET 00261ce8*/
void func_00261ce8(s32 a) asm("func_00261ce8");
void func_00261ce8(s32 a) {
    s32 n = func_00281198(D_0035f010, a) + 5;
    func_00282240(func_00257130(), n, 0);
    func_002827f0(func_00257130(), 0, 0);
}
}  // namespace n00261ce8

// 00261d48 (was src/anon/match_00261d48_mam.cpp)
namespace n00261d48 {
extern s32 D_0035ef6c asm("D_0035ef6c");
extern s32 D_0035f01c asm("D_0035f01c");
extern s16 D_00373240[] asm("D_00373240");
struct Slot261 { u8 pad[408]; u8* ptr; u8 pad2[24]; };
struct G261 { u8 pad[13840]; Slot261 a[24]; Slot261 b[20]; };
struct E261d48 { u16 id; u8 a; u8 b; u16 pad; };
u8* func_00257770(void) asm("func_00257770");
void func_00139d78(u8*) asm("func_00139d78");
s32 func_00257140(s32) asm("func_00257140");
s32 func_00257130(void) asm("func_00257130");
s32 func_00257158(u16, u8, s32) asm("func_00257158");
void func_00138c10(u8*, s32) asm("func_00138c10");
s32 func_002891e8(s32) asm("func_002891e8");
s32 func_00289300(s32) asm("func_00289300");
void func_00261fb8(void) asm("func_00261fb8");
void func_00261ce8(s32) asm("func_00261ce8");
s32 func_002827e0(s32, s32) asm("func_002827e0");
u8* func_00281f30(s32) asm("func_00281f30");
E261d48* func_00281f20(s32) asm("func_00281f20");
/*TARGET 00261d48*/
void func_00261d48(void) asm("func_00261d48");
void func_00261d48(void) {
    s32 cnt[5];
    s32 pos;
    G261* g = (G261*)func_00257770();
    s32 i, j, n, k, sel, c;
    s16 col;
    u8* b;
    E261d48* l;
    func_00139d78((u8*)g);
    c = func_00257140(0);
    for (i = 0; i < 20; i++) {
        func_00138c10((u8*)&g->a[i], D_0035ef6c);
        func_00138c10((u8*)&g->b[i], c);
        g->b[i].ptr = 0;
    }
    sel = func_002891e8(D_0035f01c);
    if (sel >= func_00289300(D_0035f01c)) {
        func_00261fb8();
        return;
    }
    func_00261ce8(sel);
    for (i = 0; i < 5; i++) {
        cnt[i] = func_002827e0(func_00257130(), i);
    }
    pos = 0;
    b = func_00281f30(func_00257130());
    l = func_00281f20(func_00257130());
    k = 0;
    for (i = 0; i < 5; i++) {
        if (i == 1) continue;
        col = D_00373240[i];
        n = cnt[i];
        if (i == 0) n += cnt[1];
        for (j = 0; j < n; j++) {
            if (i == 0) col = (j == 0) ? col : 151;
            func_00138c10((u8*)&g->a[pos + j], col);
            c = func_00257140(0);
            if (i == 4) c = func_00257140(func_00257158(l[k].id, l[k].a, l[k].b != 0));
            Slot261* s = &g->b[pos + j];
            func_00138c10((u8*)s, c);
            s->ptr = b + 16 + k * 80;
            k++;
        }
        pos += n;
        pos += n & 1;
    }
}
}  // namespace n00261d48

// 00261fb8 (was src/anon/batch_w1580_g.cpp)
namespace n00261fb8 {
void func_00138c10(u8*, s32) asm("func_00138c10");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_00257130(void) asm("func_00257130");
s32 func_00257140(s32) asm("func_00257140");
u8* func_00257770(void) asm("func_00257770");
void func_002634d8(s32) asm("func_002634d8");
s32 func_00281f18(s32) asm("func_00281f18");
s32 func_00281f30(s32) asm("func_00281f30");
void func_002827f0(s32, s32, s32) asm("func_002827f0");
/*TARGET 00261fb8*/
void func_00261fb8(void) asm("func_00261fb8");
void func_00261fb8(void) {
    u8* p = func_00257770();
    func_00139d78(p);
    func_002634d8(0);
    s32 k = func_00257140(0);
    s32 q = func_00281f30(func_00257130());
    s32 n = func_00281f18(func_00257130()) < 20 ? func_00281f18(func_00257130()) : 20;
    func_002827f0(func_00257130(), 0, n);
    for (s32 i = 0; i < n; i++) {
        u8* e = p + i * 0x1B4;
        func_00138c10(e + 0x3610, 0x8F);
        func_00138c10(e + 0x5EF0, k);
        *(s32*)(e + 0x6088) = q + 16 + i * 0x50;
    }
}
}  // namespace n00261fb8

// 002620a0 (was src/anon/batch_w38.cpp)
namespace n002620a0 {
void CmItem_FadeOutTop(void*) asm("_ZN2Tz6CmItem10FadeOutTopEv");
u8* func_00257770(void) asm("func_00257770");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0028dac8(void*, s32) asm("func_0028dac8");
s32 func_0028acc8(void*) asm("func_0028acc8");
s32 func_0028acb8(void*) asm("func_0028acb8");
void func_0028aa40(void*) asm("func_0028aa40");
extern void* D_0035f01c asm("D_0035f01c");
/*TARGET 002620a0*/
void CmItem_FadeOutTop(void*) asm("_ZN2Tz6CmItem10FadeOutTopEv");
void CmItem_FadeOutTop(void*) {
    u8* b = func_00257770();
    if (func_00287bc0() == 1) {
        func_0028dac8(b, 142);
        if (func_0028acc8(D_0035f01c) && !func_0028acb8(D_0035f01c)) func_0028aa40(D_0035f01c);
    }
}
}  // namespace n002620a0

// 00262118 (was src/anon/tiny_auto80_queue.cpp)
namespace n00262118 {
extern u32 D_0035f01c asm("D_0035f01c");
void func_002579e0(...) asm("func_002579e0");
void func_0028abe0(...) asm("func_0028abe0");
u32 func_0028acc8(...) asm("func_0028acc8");
/*TARGET 00262118*/
void func_00262118() asm("_Z13func_00262118v");
void func_00262118() {
    func_002579e0();
    if (func_0028acc8(D_0035f01c) != 0) {
        func_0028abe0(D_0035f01c);
    }
}
}  // namespace n00262118

// 00262160 (was src/anon/tiny_auto80_queue.cpp)
namespace n00262160 {
extern u32 D_0035f01c asm("D_0035f01c");
u32 func_0028acc8(...) asm("func_0028acc8");
u32 func_00257780(...) asm("func_00257780");
/*TARGET 00262160*/
u32 func_00262160() asm("_Z13func_00262160v");
u32 func_00262160() {
    u32 v0 = func_00257780();
    if (v0 == 0) {
        u32 t6 = D_0035f01c;
        if (t6 != 0) {
            v0 = func_0028acc8(t6);
            v0 = (u32)(0 < v0);
        }
    }
    return v0;
}
}  // namespace n00262160

// 002621a0 (was src/anon/batch_w48.cpp)
namespace n002621a0 {
s32 GetMode287bc0(void) asm("_ZN2Tz8MenuBase7GetModeEv");
void* func_00256b68(s32) asm("func_00256b68");
void func_0028dac8(void*, s32) asm("func_0028dac8");
s32 func_0028be58(void*) asm("func_0028be58");
void func_0028bdb8(void*) asm("func_0028bdb8");
extern void* D_0035f04c asm("D_0035f04c");
void FadeOutCategory2621a0(void) asm("_ZN2Tz6CmItem15FadeOutCategoryEv");
/*TARGET 002621a0*/
void FadeOutCategory2621a0(void) asm("_ZN2Tz6CmItem15FadeOutCategoryEv");
void FadeOutCategory2621a0(void) {
    if (GetMode287bc0() != 10) return;
    func_0028dac8(func_00256b68(1), 295);
    if (func_0028be58(D_0035f04c)) func_0028bdb8(D_0035f04c);
}
}  // namespace n002621a0

// 00262208 (was src/anon/batch_w63.cpp)
namespace n00262208 {
typedef void (*VFn)(void*);
u8* func_00256b68(s32) asm("func_00256b68");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028acc8(u32) asm("func_0028acc8");
void func_0028abe0(u32) asm("func_0028abe0");
s32 func_0028be58(u32) asm("func_0028be58");
void func_0028be18(u32) asm("func_0028be18");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f04c asm("D_0035f04c");
void cmitem_leave(void) asm("_ZN2Tz6CmItem13LeaveCategoryEv");
/*TARGET 00262208*/
void cmitem_leave(void) asm("_ZN2Tz6CmItem13LeaveCategoryEv");
void cmitem_leave(void) {
    u8* o = func_00256b68(1);
    if (func_00139d78(o)) (*(VFn*)(*(u8**)o + 20))(o);
    if (func_0028acc8(D_0035f01c)) func_0028abe0(D_0035f01c);
    if (func_0028be58(D_0035f04c)) func_0028be18(D_0035f04c);
}
}  // namespace n00262208

// 00262290 (was src/anon/batch_w36.cpp)
namespace n00262290 {
s32 func_00139d78(u32) asm("func_00139d78");
u32 func_00256b68(u32) asm("func_00256b68");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f04c asm("D_0035f04c");
s32 func_0028acc8(u32) asm("func_0028acc8");
s32 func_0028be58(u32) asm("func_0028be58");
/*TARGET 00262290*/
s32 func_00262290(void) asm("func_00262290");
s32 func_00262290(void) {
    s32 r = func_00139d78(func_00256b68(1));
    if (r) return r;
    if (D_0035f01c) r = func_0028acc8(D_0035f01c) != 0;
    if (r) return r;
    if (D_0035f04c) r = func_0028be58(D_0035f04c) != 0;
    return r;
}
}  // namespace n00262290

// 00262300 (was src/anon/auto80_199_queue.cpp)
namespace n00262300 {
/*TARGET 00262300*/
// 0x0025f588: definition moved into src/anon/unit_0025da20.cpp

u32 func_00262300(void) asm("_Z13func_00262300v");
// 0x0025f588: definition moved into src/anon/unit_0025da20.cpp

u32 func_00262300(void) {
    u32 s1 = 0;
    S_00262300* s0 = func_00256b68(1);

    if (s0 != 0) {
        if (func_00139d78((void*)s0) != 0) {
            s1 = (((u32)s0->v388 ^ 0x126) < 1);
        }
    }

    return s1;
}
}  // namespace n00262300

// 00262360 (was src/anon/auto80_199_queue.cpp)
namespace n00262360 {
/*TARGET 00262360*/
void func_00262360(void) asm("_Z13func_00262360v");
void func_00262360(void) {
    S_00262360* s0 = func_00256b68(1);
    if (s0 == 0) {
        return;
    }
    if (func_00139d78((void*)s0) == 0) {
        return;
    }
    if (s0->v388 == 294) {
        return;
    }
    func_00138c10((void*)s0, 294);
}
}  // namespace n00262360

// 002623c8 (was src/anon/perm_002623c8.cpp)
namespace n002623c8 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035f03c asm("D_0035f03c");
extern u16 D_00373288[] asm("D_00373288");
u8 *func_00257770(void) asm("_ZN2Tz5CmTop13GetListBufferEv");
s32 func_00139d78(u8 *) asm("_Z16u_call4_00139d78jjjj");
void func_0028d980(u8 *, s32, u32, u32, u32, s32, s32, s32, s32) asm("_ZN2Tz10MenuCursor6CreateEz");
s32 func_0023aa98(u8 *) asm("_ZN2YI8SEQUENCE10GetParamExEv");
s32 func_0023aa58(u8 *) asm("_ZN2YI8SEQUENCE12GetParamSizeEv");
s32 func_00257140(s32) asm("_ZN2Tz5CmTop18GetFontColorSeqNumEi");
void func_0028dcc0(u8 *, u8 *) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
void func_00139620(u8 *) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void func_00138c68(u8 *, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
s32 func_00192048(s32) asm("_Z16u_tail4_00192048jjjj");
void func_00262768(void) asm("_ZN2Tz6CmItem11ChgCategoryEi");
/*TARGET 002623c8*/
void func_002623c8(void) asm("func_002623c8");
void func_002623c8(void)
{
  unsigned short new_var2;
  s32 y = 0;
  u8 *p = func_00257770();
  u8 *new_var;
  u8 *hdr = p + 2504;
  u8 *sz;
  func_00139d78(hdr);
  new_var = hdr;
  new_var2 = 241;
  u8 *e = p + 3376;
  s32 id = D_0035f3d4;
  func_0028d980(new_var, id++, D_0035ef68, D_0035ef64, D_0035f03c, new_var2, 242, -1, 0);
  s32 step = func_0023aa98(p + 2528);
  s32 i = 4;
  s32 w = func_0023aa58(p + 2528);
  s32 k = func_00257140(0);
  u16 *t = D_00373288;
  do
  {
    if (1)
    {
      func_0028d980(e, id, D_0035ef68, D_0035ef64, D_0035f03c, k, -1, -1, 0);
      func_0028dcc0(e, hdr);
      func_00139620(e);
      *((s32 *) (e + 432)) = 2;
    }
    new_var = e;
    func_00138c68(new_var, y, 0);
    y += step;
    *((s32 *) (e + 408)) = func_00192048(*(t++));
    *((s32 *) (e + 424)) = w;
    i--;
    e += 436;
  }
  while (i >= 0);
  func_00262768();
}
}  // namespace n002623c8

// 00262538 (was src/yw/scrollbar.cpp)
namespace Tz { // method 00262538
u32 func_00257770() asm("func_00257770");
u32 func_00139d78(u32) asm("func_00139d78");
void func_0028dac8(...) asm("func_0028dac8");
/*TARGET 00262538*/
void ScrollBar::FadeOut() {
    u32 s0 = func_00257770() + 2504;
    if (func_00139d78(s0) != 0) {
        func_0028dac8(s0, 243);
    }
}
}  // Tz

// 00262588 (was src/anon/batch_w91.cpp)
namespace n00262588 {
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00139510(void*) asm("func_00139510");
// --- 00262588  Tz::CmItem::LeaveStock
u8* cmtop_list_buffer(void) asm("_ZN2Tz5CmTop13GetListBufferEv");
void LeaveStock(void*) asm("_ZN2Tz6CmItem10LeaveStockEv");
/*TARGET 00262588*/
void LeaveStock(void*) asm("_ZN2Tz6CmItem10LeaveStockEv");
void LeaveStock(void*) {
    u8* b = cmtop_list_buffer();
    if (u_call4_00139d78(b + 2504)) func_00139510(b + 2504);
    for (s32 i = 0; i < 5; i++) {
        u8* o = b + 3376 + i * 436;
        if (u_call4_00139d78(o)) (*(void (**)(u8*))(*(u8**)o + 20))(o);
    }
    if (u_call4_00139d78(b + 816)) func_00139510(b + 816);
}
}  // namespace n00262588

// 00262650 (was src/anon/batch_w1581_g.cpp)
namespace n00262650 {
u32 func_00257770() asm("func_00257770");
u32 func_00139d78(u32) asm("func_00139d78");
/*TARGET 00262650*/
u32 func_00262650(void) asm("func_00262650");
u32 func_00262650(void) {
    u32 base = func_00257770();
    u32 r = func_00139d78(base + 0x9C8);
    if (r == 0) {
        s32 i;
        for (i = 0; i < 5; i++) {
            if (func_00139d78(base + 0xD30 + i * 0x1B4) != 0) { r = 1; break; }
        }
        if (r == 0) r = func_00139d78(base + 0x330);
    }
    return r;
}
}  // namespace n00262650

// 002626f0 (was gap)
namespace n002626f0 {
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

s32 func_002626f0() asm("func_002626f0");
s32 func_002626f0() {
    u8* o = func_00257770() + 2504;
    func_00139d78(o);
    return *(s32*)(o + 388) == 0xf2;
}

}  // namespace n002626f0

// 00262730 (was src/anon/batch_w1581_g.cpp)
namespace n00262730 {
u32 func_00257770() asm("func_00257770");
u32 func_00139d78(u32) asm("func_00139d78");
void func_0028da70(u32, s32) asm("func_0028da70");
/*TARGET 00262730*/
void func_00262730(void) asm("func_00262730");
void func_00262730(void) {
    u32 p = func_00257770() + 0x9C8;
    func_00139d78(p);
    func_0028da70(p, 0xF2);
}
}  // namespace n00262730

// 00262768 (was src/anon/auto80_199_queue.cpp)
namespace n00262768 {
/*TARGET 00262768*/
void func_00262768(void) asm("_Z13func_00262768v");
void func_00262768(void) {
    u32 s1 = func_00257770();
    u32 s0 = s1 + 816;

    if (func_00139d78(s0) == 0) {
        func_0028d8c0(s0, (u32)(D_0035f3d4 + 2), (u32)D_0035ef68, (u32)D_0035ef64, (u32)D_0035f03c, 240, (u32)-1, 0);
    }

    func_0028dcc0(s0, s1 + 2504);

    s32 v0;
    s32 v1;
    s32 idx = (s32)D_0035f0b5;
    u32 p = s1 + 3376 + (u32)(idx * 436);

    func_00138c78(p, (u32)&v0, (u32)&v1);
    ((dk::Sprite*)(u32)s0)->setOffsetPos((u32)v0, (u32)v1);
}
}  // namespace n00262768

// 00262820 (was src/anon/batch_w109.cpp)
namespace n00262820 {
// ---- f19.cpp
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035ef6c asm("D_0035ef6c");
extern s32 D_0035f04c asm("D_0035f04c");
extern s32 D_00373278 asm("D_00373278");
extern s32 D_0037327c asm("D_0037327c");
u8* func_00257770(void) asm("func_00257770");
s32 func_00257130(void) asm("func_00257130");
s32 func_00281f18(s32) asm("func_00281f18");
s32 func_002892f8(s32) asm("func_002892f8");
u8* func_002891b8(s32, s32) asm("func_002891b8");
void func_00138c10(u8*, s32) asm("func_00138c10");
s32 func_00192048(s32) asm("func_00192048");
void func_00262af8(void) asm("func_00262af8");
s32 func_0028b038(s32) asm("func_0028b038");
void func_002827f0(s32, s32, s32) asm("func_002827f0");
u8* func_00281f30(s32) asm("func_00281f30");
struct E262820 { u16 id; u16 pad[2]; };
E262820* func_00281f20(s32) asm("func_00281f20");
void func_0028be78(s32, s32) asm("func_0028be78");
s32 func_00285d58(u16) asm("func_00285d58");
s32 func_00285e30(u16) asm("func_00285e30");
/*TARGET 00262820*/
void func_00262820(void) asm("func_00262820");
void func_00262820(void) {
    s32 i;
    u8* g = func_00257770();
    s32 cnt = func_00281f18(func_00257130());
    s32 n = func_002892f8(D_0035f01c);
    for (i = 0; i < n; i++) {
        *(s32*)(func_002891b8(D_0035f01c, i) + 408) = 0;
        func_00138c10(g + 0x87d0 + i * 408, D_0035ef6c);
    }
    if (cnt == 0) {
        func_00138c10(func_002891b8(D_0035f01c, 0), 302);
        u8* p = func_002891b8(D_0035f01c, 0);
        *(s32*)(p + 408) = func_00192048(0x845a);
        *(s32*)(func_002891b8(D_0035f01c, 0) + 432) = 2;
    } else {
        s32 sel = func_0028b038(D_0035f01c);
        func_002827f0(func_00257130(), sel, 18);
        u8* b = func_00281f30(func_00257130());
        E262820* l = func_00281f20(func_00257130());
        func_0028be78(D_0035f04c, sel / 2);
        u8* q = g + 0x87d0;
        for (i = 0; i < 18; i++) {
            if (i + sel >= cnt) break;
            *(u8**)(func_002891b8(D_0035f01c, i) + 408) = b + 16 + i * 80;
            if (func_00285d58(l[sel + i].id)) func_00138c10(q, func_00285e30(l[sel + i].id) ? D_0037327c : D_00373278);
            q += 408;
        }
    }
    func_00262af8();
}
}  // namespace n00262820

// 00262a30 (was src/anon/batch_w1581_g.cpp)
namespace n00262a30 {
u32 func_00257770() asm("func_00257770");
u32 func_00257130() asm("func_00257130");
u32 func_00281f20(u32) asm("func_00281f20");
s32 func_0028b040(u32) asm("func_0028b040");
s32 func_00285d58(u32) asm("func_00285d58");
s32 func_00285e30(u32) asm("func_00285e30");
void func_00285f50(u32) asm("func_00285f50");
s32 func_002891e8(u32) asm("func_002891e8");
void func_00138c10(u32, s32) asm("func_00138c10");
extern u32 D_0035f01c asm("D_0035f01c");
extern s32 D_00373278 asm("D_00373278");
extern s32 D_0037327c asm("D_0037327c");
/*TARGET 00262a30*/
void func_00262a30(void) asm("func_00262a30");
void func_00262a30(void) {
    u32 base = func_00257770();
    u32 info = func_00281f20(func_00257130());
    u16* e = (u16*)(func_0028b040(D_0035f01c) * 6 + info);
    s32 n;
    if (func_00285d58(*e) == 0) return;
    func_00285f50(*e);
    if (func_00285e30(*e) != 0) n = D_0037327c;
    else n = D_00373278;
    func_00138c10(base + func_002891e8(D_0035f01c) * 0x198 + 0x87D0, n);
}
}  // namespace n00262a30

// 00262af8 (was src/anon/batch_w92.cpp)
namespace n00262af8 {
struct I262 { u16 h0; u16 pad[4]; u16 h10; u16 pad2[4]; u16 h20; };
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_002891e8(u32) asm("func_002891e8");
s32 func_00289300(u32) asm("func_00289300");
void func_00263a58(s32, s32) asm("func_00263a58");
u32 func_00257130(void) asm("func_00257130");
s32 func_00281f18(u32) asm("func_00281f18");
u32 func_0028b040(u32) asm("func_0028b040");
I262* func_002632d0(u32) asm("func_002632d0");
void func_00281cf0(u16) asm("func_00281cf0");
s32 func_002570a0(s32) asm("func_002570a0");
extern u32 D_0035f01c asm("D_0035f01c");
/*TARGET 00262af8*/
void func_00262af8(void) asm("func_00262af8");
void func_00262af8(void) {
    s32 m = func_00287bc0();
    u32 t;
    if (m == 1) {
        t = func_002891e8(D_0035f01c);
        func_00263a58((s32)t >= func_00289300(D_0035f01c) ? 0xbb87 : 0xbb86, 1);
    } else if (m == 10) {
        if (!func_00281f18(func_00257130())) {
            func_00263a58(-1, 1);
            return;
        }
        t = func_0028b040(D_0035f01c);
        if (!func_002632d0(t)) return;
        if (!func_002632d0(t)->h0) return;
        func_00263a58((u16)(func_002632d0(t)->h10 | 0x8000), 1);
        func_00281cf0(func_002632d0(t)->h20);
    } else if ((u32)(m - 11) < 2) {
        func_00263a58((u16)(func_002632d0(func_002570a0(10))->h10 | 0x8000), 1);
    }
}
}  // namespace n00262af8

// 00262c40 (was src/anon/batch_w38.cpp)
namespace n00262c40 {
void CmItem_FadeOutWarn(void*) asm("_ZN2Tz6CmItem11FadeOutWarnEv");
u8* func_00257770(void) asm("func_00257770");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0028dac8(void*, s32) asm("func_0028dac8");
/*TARGET 00262c40*/
void CmItem_FadeOutWarn(void*) asm("_ZN2Tz6CmItem11FadeOutWarnEv");
void CmItem_FadeOutWarn(void*) {
    s32 m = func_00287bc0();
    u8* b = func_00257770();
    if ((u32)(m - 11) < 4) {
        func_0028dac8(b, 298);
        func_0028dac8(b + 0xb350, 307);
    }
}
}  // namespace n00262c40

// 00262cb8 (was src/anon/batch_wcx2.cpp)
namespace n00262cb8 {
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
struct ObB74 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    u8 pad[432];
};
struct Sys74 {
    u8 w0[816];
    u8 w1[816];
    u8 w2[3376 - 1632];
    ObB74 a[24];
    u8 pad[24304 - 3376 - 24 * 436];
    ObB74 b[24];
};
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f020 asm("D_0035f020");
extern u32 D_0035f024 asm("D_0035f024");
Sys74* func_00257770(void) asm("func_00257770");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00139510__97494(void*) asm("func_00139510");
s32 func_0028acc8(u32) asm("func_0028acc8");
void func_0028abe0(u32) asm("func_0028abe0");
void LeaveWarn74(void) asm("_ZN2Tz6CmItem9LeaveWarnEv");
/*TARGET 00262cb8*/
void LeaveWarn74(void) asm("_ZN2Tz6CmItem9LeaveWarnEv");
void LeaveWarn74(void)
{
    Sys74* s = func_00257770();
    if (func_00139d78(s)) func_00139510__97494(s);
    if (func_00139d78(s->w2)) func_00139510__97494(s->w2);
    u8* x = (u8*)s + 0xb350;
    if (func_00139d78(x)) func_00139510__97494(x);
    if (func_0028acc8(D_0035f01c)) func_0028abe0(D_0035f01c);
    if (func_0028acc8(D_0035f020)) func_0028abe0(D_0035f020);
    if (func_0028acc8(D_0035f024)) func_0028abe0(D_0035f024);
    for (s32 i = 0; i < 24; i++) {
        if (func_00139d78(&s->a[i])) s->a[i].v5();
        if (func_00139d78(&s->b[i])) s->b[i].v5();
    }
    if (func_00139d78(s->w1)) func_00139510__97494(s->w1);
}
}  // namespace n00262cb8

// 00262e30 (was src/anon/batch_w83.cpp)
namespace n00262e30 {
u8* func_00257770(void) asm("func_00257770");
extern void* D_0035f01c asm("D_0035f01c");
extern void* D_0035f020 asm("D_0035f020");
extern void* D_0035f024 asm("D_0035f024");
u8 func_00139d78c(void*) asm("func_00139d78");
u8 func_0028acc8c(void*) asm("func_0028acc8");
/*TARGET 00262e30*/
// Is anything in this menu still busy?
u8 func_00262e30(void) asm("func_00262e30");
// Is anything in this menu still busy?
u8 func_00262e30(void) {
    u8 r;
    u8* s = func_00257770();
    if ((r = func_00139d78c(s))) return r;
    if ((r = func_00139d78c(s + 1632))) return r;
    if ((r = func_00139d78c(s + 0xb350))) return r;
    if ((r = func_0028acc8c(D_0035f01c))) return r;
    if ((r = func_0028acc8c(D_0035f020))) return r;
    if ((r = func_0028acc8c(D_0035f024))) return r;
    s32 i;
    u8* e;
    for (i = 0, e = s; i < 24; i++, e += 436) {
        if ((r = func_00139d78c(e + 3376))) return r;
        if ((r = func_00139d78c(e + 24304))) return r;
    }
    r = func_00139d78c(s + 816);
    return r;
}
}  // namespace n00262e30

// 00262f18 (was src/anon/tiny_auto80_queue.cpp)
namespace n00262f18 {
u32 func_00257770(...) asm("func_00257770");
/*TARGET 00262f18*/
u32 func_00262f18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00262f18jjjjjjjj");
u32 func_00262f18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r2 = ((u32(*)())func_00257770)();
    r15 = ((u32*)(u32)r2)[97];
    r14 = (u32)(0u | 0xb350u);
    r14 = (u32)(r2 + r14);
    r15 = (u32)(r15 ^ 0x0129u);
    r2 = ((u32)r15 < 0x00000001u);
    if (r2 == 0u) {
        r15 = ((u32*)(u32)r14)[97];
        r15 = (u32)(r15 ^ 0x0132u);
        r2 = ((u32)r15 < 0x00000001u);
    }
    return r2;
}
}  // namespace n00262f18

// 00262f58 (was src/anon/batch_w1581_g.cpp)
namespace n00262f58 {
u32 func_00257770() asm("func_00257770");
void func_0028da70(u32, s32) asm("func_0028da70");
/*TARGET 00262f58*/
void func_00262f58(void) asm("func_00262f58");
void func_00262f58(void) {
    u32 p = func_00257770();
    func_0028da70(p, 0x129);
    func_0028da70(p + 0xB350, 0x132);
}
}  // namespace n00262f58

// 00262fa0 (was src/anon/batch_w62.cpp)
namespace n00262fa0 {
s32 func_00287bc0(void) asm("func_00287bc0");
u8* func_00257770(void) asm("func_00257770");
void func_0028dac8(u8*, u32) asm("func_0028dac8");
void func_0027e6e0(void) asm("func_0027e6e0");
void cm_FadeOutStock(void* self) asm("_ZN2Tz6CmItem12FadeOutStockEv");
/*TARGET 00262fa0*/
void cm_FadeOutStock(void* self) asm("_ZN2Tz6CmItem12FadeOutStockEv");
void cm_FadeOutStock(void* self) {
    s32 m = func_00287bc0();
    u8* o = func_00257770();
    if (m == 12) {
        func_0028dac8(o + 408, 301);
        func_0027e6e0();
    }
}
}  // namespace n00262fa0

// 00262ff8 (was src/anon/batch_w83.cpp)
namespace n00262ff8 {
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_0028abe0(void*) asm("func_0028abe0");
u8* func_00257770(void) asm("func_00257770");
extern void* D_0035f020 asm("D_0035f020");
extern void* D_0035f024 asm("D_0035f024");
void func_00139510(void*) asm("func_00139510");
s32 func_0027e920(void) asm("func_0027e920");
void func_0027e770(void) asm("func_0027e770");
// Tz CmItem LeaveHelp
void LeaveHelp(void*) asm("_ZN2Tz6CmItem9LeaveHelpEv");
/*TARGET 00262ff8*/
void LeaveHelp(void*) asm("_ZN2Tz6CmItem9LeaveHelpEv");
void LeaveHelp(void*) {
    u8* s = func_00257770();
    u8* w = s + 408;
    if (func_00139d78(w)) func_00139510(w);
    w = s + 2068;
    if (func_00139d78(w)) func_00139510(w);
    if (func_0028acc8(D_0035f020)) func_0028abe0(D_0035f020);
    if (func_0028acc8(D_0035f024)) func_0028abe0(D_0035f024);
    if (func_0027e920()) func_0027e770();
    w = s + 1224;
    if (func_00139d78(w)) func_00139510(w);
}
}  // namespace n00262ff8

// 002630d8 (was src/anon/batch_w64.cpp)
namespace n002630d8 {
// Disables sibling calls (empty destructor keeps a cleanup pending).
struct NoTail { ~NoTail() {} };
// ---------------------------------------------------------------------------
u8* func_00257770(void) asm("func_00257770");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028acc8(u32) asm("func_0028acc8");
extern u32 D_0035f020 asm("D_0035f020");
extern u32 D_0035f024 asm("D_0035f024");
void func_0027e920(void) asm("func_0027e920");
/*TARGET 002630d8*/
void func_002630d8(void) asm("func_002630d8");
void func_002630d8(void) {
    NoTail nt;
    u8* o = func_00257770();
    if (func_00139d78(o + 408)) return;
    if (func_00139d78(o + 2068)) return;
    if (func_00139d78(o + 1224)) return;
    if (func_0028acc8(D_0035f020)) return;
    if (func_0028acc8(D_0035f024)) return;
    func_0027e920();
}
}  // namespace n002630d8

// 00263160 (was src/anon/tiny_jal_wrappers.cpp)
namespace n00263160 {
u32 func_00257770(u32, u32, u32, u32) asm("_Z13func_00257770jjjj");
/*TARGET 00263160*/
u32 func_00263160(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00263160jjjj");
u32 func_00263160(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_00257770(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(796));
    r2 = (u32)(r2 ^ 0x012cu);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
}  // namespace n00263160

// 00263188 (was src/anon/batch_w1.cpp)
namespace n00263188 {
void* func_00257770(void) asm("func_00257770");
void func_0028da70(void*, s32) asm("func_0028da70");
/*TARGET 00263188*/
void func_00263188(void) asm("func_00263188");
void func_00263188(void) {
    func_0028da70((u8*)func_00257770() + 408, 300);
}
}  // namespace n00263188

// 002631b0 (was src/anon/batch_w9.cpp)
namespace n002631b0 {
u8* func_00257770(void) asm("func_00257770");
void func_0028da70(void*, u32) asm("func_0028da70");
/*TARGET 002631b0*/
// 0x0025a1d0: definition moved into src/anon/unit_002588e8.cpp

void func_002631b0(void) asm("func_002631b0");
// 0x0025a1d0: definition moved into src/anon/unit_002588e8.cpp

void func_002631b0(void) {
    func_0028da70(func_00257770() + 0xb350, 307);
}
}  // namespace n002631b0

// 002631d8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002631d8 {
u32 func_00257910(u32, u32, u32, u32) asm("_Z13func_00257910jjjj");
/*TARGET 002631d8*/
// 0x002595b8: definition moved into src/anon/unit_002588e8.cpp

u32 func_002631d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002631d8jjjj");
// 0x002595b8: definition moved into src/anon/unit_002588e8.cpp

u32 func_002631d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_00257910)(u32, u32, u32, u32) = func_00257910;
    r2 = fp_call4_00257910(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002631d8

// 002631f8 (was src/anon/tiny.cpp)
namespace n002631f8 {
void func_00257be0(void*) asm("_Z13func_00257be0Pv");
/*TARGET 002631f8*/
// 0x0025f550: definition moved into src/anon/unit_0025da20.cpp
void func_002631f8(BD_VALUE* bd) asm("_Z13func_002631f8P8BD_VALUE");
// 0x0025f550: definition moved into src/anon/unit_0025da20.cpp
void func_002631f8(BD_VALUE* bd) { func_00257be0(bd); }
}  // namespace n002631f8


// 00263210 (was gap): item name draw: printer set-up from the sequence position, then draw at it.
namespace n00263210 {
extern u32 D_0035f01c asm("D_0035f01c");
s32 func_0028b160(u32, u8*) asm("func_0028b160");
u32 func_00257130() asm("func_00257130");
s32 func_00281f30(u32) asm("func_00281f30");
void func_001a98e8(u8*, s32, s32, u32, s32) asm("func_001a98e8");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
u32 func_0023a918(u8*) asm("func_0023a918");
void func_001a9ae8(u8*, s32, s32, u32) asm("func_001a9ae8");
static inline u32 Get(u8* p, s32 off) { return *(u32*)(p + off); }
void func_00263210(s32 x, s32 y, s32 a2, s32 a3, u8* o) asm("func_00263210");
void func_00263210(s32 x, s32 y, s32 a2, s32 a3, u8* o) {
    u8 buf[96];
    s32 n = func_0028b160(D_0035f01c, o);
    s32 w = func_00281f30(func_00257130()) + n * 80;
    func_001a98e8(buf, 1, w, Get(o, 424), 1);
    func_001a9ae8(buf, func_0023aa18(o + 24) + x, func_0023aa38(o + 24) + y, func_0023a918(o + 24));
}
}  // namespace n00263210
