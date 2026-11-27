// Linked unit 0x0025da20-0x0025f6b8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/cmenu_pause.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tz/ui_accessors.hpp"
#include "../tozawa/item_info.hpp"
#include "../tozawa/multi_seq.hpp"
#include "../tozawa/party_info.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 0025da20 (was src/anon/batch_w2412_g.cpp)
namespace n0025da20 {
extern s32 D_0035f650 asm("D_0035f650");
extern s32 D_0035f664 asm("D_0035f664");
void func_001039f8(void) asm("func_001039f8");
s32 func_00139d78(s32) asm("func_00139d78");
s32 func_00233e60(void) asm("func_00233e60");
void func_00233e70(s32) asm("func_00233e70");
s32 func_0023f0c0(s32) asm("func_0023f0c0");
void func_0025dbd8(void) asm("func_0025dbd8");
void Tz__CmLoad__CtrlSlotCheck(void) asm("Tz__CmLoad__CtrlSlotCheck");
void func_0025dfb0(void) asm("func_0025dfb0");
void func_0025e370(void) asm("func_0025e370");
void func_0025e450(void) asm("func_0025e450");
void Tz__CmLoad__CtrlList(void) asm("Tz__CmLoad__CtrlList");
void func_0025ebb0(void) asm("func_0025ebb0");
void func_0025ee88(void) asm("func_0025ee88");
void func_0025f550(void) asm("func_0025f550");
u32 func_00287bc0(void) asm("func_00287bc0");
void Tz__MenuBase__SaveMode(void) asm("Tz__MenuBase__SaveMode");
s32 func_00287db0(void) asm("func_00287db0");
s32 func_0028acc8(s32) asm("func_0028acc8");
s32 func_002b55e0(void) asm("func_002b55e0");
void func_002b5af0(void) asm("func_002b5af0");
void func_002b6418(void) asm("func_002b6418");
/*TARGET 0025da20*/
s32 Tz__CmLoad__Control(void) asm("Tz__CmLoad__Control");
s32 Tz__CmLoad__Control(void) {
    Tz__MenuBase__SaveMode();
    func_002b6418();
    if (func_00287db0()) {
        func_00233e70(0);
        if (!func_00233e60()) return 0;
        if (func_00139d78(D_0035f664) || func_002b55e0() || func_0028acc8(D_0035f650)) return 0;
        func_002b5af0();
        func_0025f550();
        func_001039f8();
        return 1;
    } else {
        if (func_00139d78(D_0035f664) == 0 || func_0023f0c0(D_0035f664) == 1) {
            switch (func_00287bc0()) {
            case 1: func_0025dbd8(); break;
            case 2: Tz__CmLoad__CtrlSlotCheck(); break;
            case 4: func_0025e450(); break;
            case 5: case 7: func_0025dfb0(); break;
            case 11: func_0025e370(); break;
            case 12: Tz__CmLoad__CtrlList(); break;
            case 18: func_0025ebb0(); break;
            case 23: func_0025ee88(); break;
            }
        }
    }
    return 0;
}
}  // namespace n0025da20

// 0025dba8 (was src/anon/batch_w16.cpp)
namespace n0025dba8 {
void OvlShop__ItemShop__SetupConfirm(void) asm("OvlShop__ItemShop__SetupConfirm");
void func_00240be0(void) asm("func_00240be0");
void func_0028f4d8(u32, u32, u32) asm("func_0028f4d8");
/*TARGET 0025dba8*/
void func_0025dba8(void) asm("func_0025dba8");
void func_0025dba8(void) {
    OvlShop__ItemShop__SetupConfirm();
    func_00240be0();
    func_0028f4d8(0, 0x8a7f, 0);
}
}  // namespace n0025dba8

// 0025dbd8 (was src/anon/batch_wcx2.cpp)
namespace n0025dbd8 {
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
// --------------------
extern s32 D_0035f64c_25d asm("D_0035f64c");
s32 func_00289380_x10468(s32) asm("func_00289380");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_0028acc8_x10470(s32) asm("func_0028acc8");
s32 func_00289310_x10471(s32) asm("func_00289310");
void func_00287f90(s32) asm("func_00287f90");
void func_0028abe0_x10473(s32) asm("func_0028abe0");
void func_00287c30() asm("func_00287c30");
s32 func_00287bc0() asm("func_00287bc0");
void func_002b5af0() asm("func_002b5af0");
void func_0028f7e8(s32) asm("func_0028f7e8");
void func_00240be0() asm("func_00240be0");
void Tz__CmSLBase__SetupSlotCheck() asm("Tz__CmSLBase__SetupSlotCheck");
void Tz__SelHist__FadeOut(s32) asm("Tz__SelHist__FadeOut");
void func_00240b90(s32) asm("func_00240b90");
s32 func_0028ae28_x10484(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10485(s32) asm("func_0028ab20");
void func_00287c90(s32) asm("func_00287c90");
void func_0025f588() asm("func_0025f588");
void func_0025f610() asm("func_0025f610");
s32 func_00287df0_25d(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void Tz__CMenuHelp__FadeOut() asm("Tz__CMenuHelp__FadeOut");
void func_00287da0() asm("func_00287da0");
void func_0028aa40(s32) asm("func_0028aa40");
void func_00287c00(s32) asm("func_00287c00");
s32 func_00288040() asm("func_00288040");
void func_00288018() asm("func_00288018");
/*TARGET 0025dbd8*/
void func_0025dbd8() asm("func_0025dbd8");
void func_0025dbd8() {
    s32 r = func_00289380_x10468(D_0035f64c_25d);
    s32 a = func_00287cd0();
    if (a == 2) {
        if (func_0028acc8_x10470(D_0035f64c_25d)) {
            if (r != -1 || func_00289310_x10471(D_0035f64c_25d)) {
                func_00287f90(0);
                func_0028abe0_x10473(D_0035f64c_25d);
            }
            return;
        }
        func_00287c30();
        if (func_00287bc0() == 2) {
            func_002b5af0();
            func_0028f7e8(1);
            func_00240be0();
            Tz__CmSLBase__SetupSlotCheck();
        }
        return;
    }
    if (r != -1 || func_00289310_x10471(D_0035f64c_25d)) {
        if (!func_0028ae28_x10484(D_0035f64c_25d, 0)) func_0028ab20_x10485(D_0035f64c_25d);
    }
    if (!a && func_0028ae28_x10484(D_0035f64c_25d, 0)) {
        func_00287c90(1);
        func_0025f588();
    }
    if (!func_00242848(func_00287df0_25d(r, func_00289310_x10471(D_0035f64c_25d), 1, func_0025f610, 1))) {
        switch (r) {
        case -4: case -2:
            Tz__SelHist__FadeOut(0);
            Tz__CMenuHelp__FadeOut();
            func_00287da0();
            break;
        case -3: case -1:
            break;
        case 0: case 1:
            func_00240b90(r);
            func_00287c00(2);
            func_0028aa40(D_0035f64c_25d);
            func_00287c90(1);
            Tz__CMenuHelp__FadeOut();
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0025dbd8

// 0025dde8 (was src/anon/batch_w1602.cpp)
namespace n0025dde8 {
extern u32 D_0035f654 asm("D_0035f654");
s32 Tz__MenuUtil__SprtIsLoop(u32) asm("Tz__MenuUtil__SprtIsLoop");
s32 func_00287cd0(void) asm("func_00287cd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00240ba0(void) asm("func_00240ba0");
s32 func_00287d30(void) asm("func_00287d30");
s32 func_00233e70(s32) asm("func_00233e70");
s32 func_00234888(s32, s32) asm("func_00234888");
s32 func_002348a8(s32, s32) asm("func_002348a8");
s32 func_00234848(s32, s32) asm("func_00234848");
s32 func_00234868(s32, s32) asm("func_00234868");
void func_002b5108(s32, s32) asm("func_002b5108");
void func_00287d20(s32) asm("func_00287d20");
void func_00240bb0(s32) asm("func_00240bb0");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00241450(s32) asm("func_00241450");
void Tz__CmSLBase__SetupWarningConfirm(s32) asm("Tz__CmSLBase__SetupWarningConfirm");
void func_00234570(s32, s32) asm("func_00234570");
/*TARGET 0025dde8*/
void Tz__CmLoad__CtrlSlotCheck(void) asm("Tz__CmLoad__CtrlSlotCheck");
void Tz__CmLoad__CtrlSlotCheck(void) {
    if (!Tz__MenuUtil__SprtIsLoop(D_0035f654)) return;
    if (func_00287cd0() == 0) func_00287cc0(1);
    s32 slot = func_00240ba0();
    switch (func_00287d30()) {
    case 0:
        if (!func_00233e70(0)) {
            s32 n = func_00234888(slot, 0);
            s32 m;
            switch (func_002348a8(slot, 0)) {
            case 4:
                func_002b5108(0x8aae, slot);
                n = -1;
                m = 6;
                break;
            default:
                if (func_00234848(slot, 0) == 2) goto ok;
            case 3:
                func_002b5108(0xb85d, slot);
                n = -1;
                m = 2;
                break;
            ok:
                m = 5;
                if (func_00234868(slot, 0)) {
                    func_002b5108(0x8a89, slot);
                    m = 1;
                }
                break;
            }
            func_00287d20(m);
            func_00240bb0(n);
        }
        break;
    case 1:
        func_00287bd0(4, 0);
        func_00287d20(10);
        func_00241450(1);
        break;
    case 2:
        Tz__CmSLBase__SetupWarningConfirm(0);
        func_00287bd0(5, 0);
        func_00234570(slot, 0);
        break;
    case 5:
        func_00287bd0(11, 0);
        break;
    case 6:
        Tz__CmSLBase__SetupWarningConfirm(0);
        func_00287bd0(7, 0);
        func_00234570(slot, 0);
        break;
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0025dde8

// 0025dfb0 (was src/anon/batch_w1613.cpp)
namespace n0025dfb0 {
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00289310(s32) asm("func_00289310");
s32 func_00242848(s32) asm("func_00242848");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287c00(s32) asm("func_00287c00");
void func_00287c30(void) asm("func_00287c30");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_00288018(void) asm("func_00288018");
s32 func_00288040(void) asm("func_00288040");
s32 func_00289380(s32) asm("func_00289380");
s32 func_0028acc8(s32) asm("func_0028acc8");
void Tz__SelHist__FadeOut(s32) asm("Tz__SelHist__FadeOut");
// 0x002af0a0: definition moved into src/anon/unit_002aeba0.cpp

s32 func_00233e60(void) asm("func_00233e60");
s32 func_00233e70(s32) asm("func_00233e70");
s32 func_002348a8(s32, s32) asm("func_002348a8");
void func_00234570(s32, s32) asm("func_00234570");
s32 func_00240ba0(void) asm("func_00240ba0");
void func_00240be0(void) asm("func_00240be0");
void func_0025dba8(void) asm("func_0025dba8");
void func_00287bd0(s32, s32) asm("func_00287bd0");
s32 func_00287c10(void) asm("func_00287c10");
void func_00287d20(s32) asm("func_00287d20");
s32 func_0028abe0(s32) asm("func_0028abe0");
s32 func_0028ae28(s32, s32) asm("func_0028ae28");
void func_0028f7e8(s32) asm("func_0028f7e8");
void func_002b4ee0(void) asm("func_002b4ee0");
void func_002b4f50(void) asm("func_002b4f50");
s32 func_002b4fb8(void) asm("func_002b4fb8");
s32 func_002b50e8(void) asm("func_002b50e8");
void func_002b50f8(void) asm("func_002b50f8");
void func_002b5108(s32, s32) asm("func_002b5108");
void func_002b5188(void*, s32) asm("func_002b5188");
void func_002b5558(void) asm("func_002b5558");
bool func_002b55e0(void) asm("func_002b55e0");
void func_002b5af0(void) asm("func_002b5af0");
extern u8 D_0035f0b3 asm("D_0035f0b3");
extern s32 D_0035f650 asm("D_0035f650");
extern u8 D_00373110[] asm("D_00373110");
/*TARGET 0025dfb0*/
void func_0025dfb0(void) asm("func_0025dfb0");
void func_0025dfb0(void)
{
    s32 sel;
    s32 st = func_00287cd0();
    if (st == 2) {
        sel = func_00289380(D_0035f650);
        s32 m = func_00287c10();
        s32 r;
        if (m == st) r = func_0028acc8(D_0035f650);
        else r = func_002b4fb8();
        if (r) {
            if (sel != -1 || func_00289310(D_0035f650)) {
                if (m == 2) {
                    func_0028abe0(D_0035f650);
                    return;
                }
                func_002b4f50();
            }
            return;
        }
        bool ok = 1;
        if ((u32)(m - 1) < 2) ok = !func_002b55e0();
        if (ok) {
            sel = 1;
            if (m == sel) {
                func_00233e70(0);
                if (!func_00233e60()) return;
            }
            func_00287c30();
            func_00287d20(0);
            s32 t = func_00287bc0();
            if (t == sel) {
                func_002b5af0();
                func_0028f7e8(1);
                func_0025dba8();
            } else if (t == 12) {
                func_002b5188(D_00373110, 1);
            } else if (t == 2) {
                func_00240be0();
            }
            func_00288018();
        }
        D_0035f0b3 = 1;
        return;
    }
    if (!func_00233e70(0)) {
        if (D_0035f0b3) {
            s32 h = func_00240ba0();
            if (func_002348a8(h, 0) != 3) {
                if (func_00287bc0() == 5) {
                    func_002b5108(0x8a89, h);
                    func_00287c00(2);
                    func_0028abe0(D_0035f650);
                    func_002b5558();
                    func_00287cc0(2);
                }
                func_00234570(h, 0);
                return;
            }
            if (func_00287bc0() != 5) {
                func_002b5108(0xb85d, h);
                func_00287bd0(5, func_00287cd0());
                func_00234570(h, 0);
                return;
            }
            func_00234570(h, 0);
        }
        func_002b50f8();
    }
    if (func_002b50e8()) return;
    if (st == 0) {
        if (func_0028ae28(D_0035f650, 0)) func_00287cc0(1);
        sel = -1;
    } else {
        sel = func_00289380(D_0035f650);
    }
    s32 k = func_00287bc0();
    if (!func_00242848(func_00287df0(sel, func_00289310(D_0035f650), 0, 0, 1))) {
        switch (sel) {
        case -1: break;
        case -2:
        case 0:
            if (k == 10) {
                func_00287c00(12);
            } else {
                func_002b5558();
                func_00287c00(1);
                Tz__SelHist__FadeOut(1);
            }
            func_002b4ee0();
            func_00287cc0(2);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0025dfb0

// 0025e370 (was src/anon/batch_w82.cpp)
namespace n0025e370 {
extern u8 D_00373110[] asm("D_00373110");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_002b4fb8(void) asm("func_002b4fb8");
s32 func_00287c10(void) asm("func_00287c10");
void func_00233e70(s32) asm("func_00233e70");
s32 func_00233e60(void) asm("func_00233e60");
void func_00287c30(void) asm("func_00287c30");
void func_00287d20(s32) asm("func_00287d20");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_002b5188(u8*, s32) asm("func_002b5188");
void func_00287cc0(s32) asm("func_00287cc0");
void func_00240bb0(s32) asm("func_00240bb0");
// global_store_half2
void func_002417a0(void) asm("func_002417a0");
void func_002b4ee0(void) asm("func_002b4ee0");
void func_00287c00(s32) asm("func_00287c00");
/*TARGET 0025e370*/
void func_0025e370(void) asm("func_0025e370");
void func_0025e370(void)
{
    s32 v = func_00287cd0();
    if (v == 2) {
        if (func_002b4fb8()) return;
        if (func_00287c10() == 1) {
            func_00233e70(0);
            if (!func_00233e60()) return;
        }
        func_00287c30();
        func_00287d20(0);
        if (func_00287bc0() == 12) func_002b5188(D_00373110, 1);
        return;
    }
    if (v == 0) func_00287cc0(1);
    func_00240bb0(8000);  // global_store_half2
    func_002417a0();
    func_002b4ee0();
    func_00287c00(12);
    func_00287cc0(2);
}
}  // namespace n0025e370

// 0025e450 (was src/anon/batch_w3698.cpp)
namespace n0025e450 {
s32 func_00233e60(void) asm("func_00233e60");
s32 func_00233e70(s32) asm("func_00233e70");
s32 func_00234758(void) asm("func_00234758");
s32 func_00234798(void) asm("func_00234798");
s32 YI__MCARD__GetResultRead(void) asm("YI__MCARD__GetResultRead");
void func_002349c8(s32, s32) asm("func_002349c8");
void Tz__MCard__MakeFname(s32) asm("Tz__MCard__MakeFname");
s32 func_00240a08(s32) asm("func_00240a08");
s32 func_00240ba0(void) asm("func_00240ba0");
void func_00240bc0(s32) asm("func_00240bc0");
s32 Tz__MCard__GetPos(void) asm("Tz__MCard__GetPos");
void func_00240c08(s32, s32, s32) asm("func_00240c08");
void Tz__MCard__GetDirInfo(s32) asm("Tz__MCard__GetDirInfo");
s32 Tz__MCard__UpdateDirInfo(void) asm("Tz__MCard__UpdateDirInfo");
void func_00240fd8(s32, s32) asm("func_00240fd8");
s32 func_002413f0(void) asm("func_002413f0");
void func_00241450(s32) asm("func_00241450");
void func_002415a0(s32, s32, s32) asm("func_002415a0");
void func_002417a0(void) asm("func_002417a0");
void func_00241850(s32, s32) asm("func_00241850");
s32 Tz__MCard__ChkFileSize(s32) asm("Tz__MCard__ChkFileSize");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287c00(s32) asm("func_00287c00");
s32 func_00287c10(void) asm("func_00287c10");
void func_00287c30(void) asm("func_00287c30");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287cd0(void) asm("func_00287cd0");
void func_00287d20(s32) asm("func_00287d20");
s32 func_00287d30(void) asm("func_00287d30");
void func_00288018(void) asm("func_00288018");
s32 func_00288040(void) asm("func_00288040");
void func_0028f7e8(s32) asm("func_0028f7e8");
void func_0025dba8(void) asm("func_0025dba8");
void Tz__CmSLBase__SetupWarningConfirm(s32) asm("Tz__CmSLBase__SetupWarningConfirm");
void func_002b4ee0(void) asm("func_002b4ee0");
s32 func_002b4fb8(void) asm("func_002b4fb8");
s32 func_002b4ff8(void) asm("func_002b4ff8");
void func_002b5108(s32, s32) asm("func_002b5108");
void func_002b5188(void*, s32) asm("func_002b5188");
void func_002b5af0(void) asm("func_002b5af0");
extern u8 D_00373110 asm("D_00373110");
extern s8 D_0035f0b3 asm("D_0035f0b3");
/*TARGET 0025e450*/
void func_0025e450(void) asm("func_0025e450");
void func_0025e450(void)
{
    s32 h = func_00240ba0();
    s32 st = func_00287cd0();
    s32 r;
    if (st == 2) {
        if (func_002b4fb8()) return;
        if (func_00287c10() == 1) {
            func_00233e70(0);
            if (!func_00233e60()) return;
        }
        func_00287c30();
        func_00287d20(0);
        r = func_00287bc0();
        if (r == 1) {
            func_002b5af0();
            func_0028f7e8(1);
            func_0025dba8();
            return;
        }
        if (r == 12) {
            func_002417a0();
            func_002b5188(&D_00373110, 1);
        }
        return;
    }
    if (!func_002b4ff8()) return;
    if (st == 0) func_00287c90(1);
    switch (func_00287d30()) {
    case 10:
        if (func_00233e70(0)) break;
        if (func_00234798()) goto E;
        Tz__MCard__GetDirInfo(-1);
        func_00287d20(11);
        break;
    case 11:
        if (func_00233e70(0)) break;
        if (func_00234758()) goto E;
        if (Tz__MCard__UpdateDirInfo() > 0) {
            func_00287d20(12);
            break;
        }
    F:
        func_002b4ee0();
        func_00287c00(12);
        func_00287c90(1);
        break;
    case 12:
        func_00241450(1);
        func_00287d20(13);
        break;
    case 13:
        if (func_00233e70(0)) goto C14;
        if (func_00234798()) goto E2;
        func_00287d20(14);
    case 14:
    C14:
        st = func_002413f0();
        if (st < 0) goto F;
        func_00240bc0(st);
        Tz__MCard__MakeFname(st);
        func_00241450(0);
        func_00287d20(15);
        break;
    E2:
        func_002b5108(0x8a8c, h);
        func_00287bd0(7, 0);
        Tz__CmSLBase__SetupWarningConfirm(0);
        D_0035f0b3 = 0;
        goto C14;
    case 15:
        if (func_00233e70(0)) break;
        r = func_00234798();
        if (r == 0) {
            Tz__MCard__GetDirInfo(-5);
            func_00287d20(16);
            break;
        }
        if (r == 2) goto E;
        func_00240fd8(-1, 2);
        func_00240c08(Tz__MCard__GetPos(), 0, 32);
        func_00287d20(12);
        break;
    G:
        func_00240c08(Tz__MCard__GetPos(), 0, 32);
        func_00287d20(12);
        break;
    case 16:
        if (func_00233e70(0)) break;
        st = func_00234758();
        if (st == 0) {
            st = func_002413f0();
            func_00240bc0(st);
            Tz__MCard__MakeFname(st);
            func_00241850(Tz__MCard__GetPos(), 0);
            func_002415a0(2, 0, 0);
            func_00287d20(17);
            break;
        }
    K:
        if (st == 1) goto G;
        goto E;
    case 17:
        if (func_00233e70(0)) break;
        func_00240fd8(-1, 2);
        r = YI__MCARD__GetResultRead();
        if (r == 0) {
            func_00287d20(18);
            break;
        }
        if (r == 1) goto G;
        if (r != 3) goto E;
    H:
        func_00240c08(Tz__MCard__GetPos(), 0, 32);
        func_00287d20(14);
        break;
    case 18:
        if (!func_00240a08(0)) goto H;
        Tz__MCard__GetDirInfo(-4);
        func_00287d20(19);
        break;
    case 19:
        if (func_00233e70(0)) break;
        st = func_00234758();
        if (st != 0) {
            if (st == 1) goto G;
            goto E;
        }
        func_002349c8(h, 0);
        st = Tz__MCard__ChkFileSize(1) ? 16 : 32;
        func_00240c08(Tz__MCard__GetPos(), 0, st);
        func_00287d20(14);
        break;
    E:
        func_002b5108(0x8a8c, h);
        func_00287bd0(7, 0);
        Tz__CmSLBase__SetupWarningConfirm(0);
        D_0035f0b3 = 0;
        break;
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0025e450

// 0025e8a0 (was src/anon/batch_w120.cpp)
namespace n0025e8a0 {
s32 func_00289380(u32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287c30(void) asm("func_00287c30");
void func_0028af18(u32, s32) asm("func_0028af18");
s32 func_00289310(u32) asm("func_00289310");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00287da0(void) asm("func_00287da0");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
// global_zero_4dwords
void Tz__SelHist__FadeOut(s32) asm("Tz__SelHist__FadeOut");
void func_00287c00(s32) asm("func_00287c00");
void func_0028f7e8(s32) asm("func_0028f7e8");
s32 func_0028afa8(u32) asm("func_0028afa8");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void Tz__CMenuHelp__FadeOut(void) asm("Tz__CMenuHelp__FadeOut");
extern u32 D_0035f64c asm("D_0035f64c");
s32 func_00240ba0(void) asm("func_00240ba0");
s32 func_002b55e0(void) asm("func_002b55e0");
void func_002b5658(void) asm("func_002b5658");
void func_002b5af0(void) asm("func_002b5af0");
void func_0025dba8(void) asm("func_0025dba8");
s32 func_002b5490(void) asm("func_002b5490");
void func_002b54f8(void) asm("func_002b54f8");
void func_0025f588(void) asm("func_0025f588");
s32 func_00233e70(s32) asm("func_00233e70");
s32 func_002348a8(s32, s32) asm("func_002348a8");
void func_00234570(s32, s32) asm("func_00234570");
void Tz__CmSLBase__SetupWarningWin(s32) asm("Tz__CmSLBase__SetupWarningWin");
void Tz__CmSLBase__SetupWarningConfirm(s32) asm("Tz__CmSLBase__SetupWarningConfirm");
void func_002b5108(s32, s32) asm("func_002b5108");
void func_0025f610(void) asm("func_0025f610");
void func_002b5558(void) asm("func_002b5558");
void func_00240bc0(s32) asm("func_00240bc0");
s32 func_00241770(s32) asm("func_00241770");
void func_00241450(s32) asm("func_00241450");
void func_00287d20(s32) asm("func_00287d20");
/*TARGET 0025e8a0*/
void Tz__CmLoad__CtrlList(void) asm("Tz__CmLoad__CtrlList");
void Tz__CmLoad__CtrlList(void)
{
    s32 sel = func_00289380(D_0035f64c);
    s32 st = func_00287cd0();
    s32 w = func_00240ba0();
    if (st == 2) {
        if (func_002b55e0()) {
            if (sel != -1 || func_00289310(D_0035f64c)) func_002b5658();
            return;
        }
        func_00287c30();
        s32 k = func_00287bc0();
        func_0028af18(D_0035f64c, 115);
        if (k != 1) return;
        func_002b5af0();
        func_0028f7e8(1);
        func_0025dba8();
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f64c)) && !func_002b5490()) func_002b54f8();
    if (st == 0 && func_002b5490()) {
        func_00287c90(1);
        func_0025f588();
    }
    if (!func_00233e70(0)) {
        if (func_002348a8(w, 0) != 3) {
            func_00234570(w, 0);
        } else {
            Tz__CmSLBase__SetupWarningWin(-1);
            Tz__CmSLBase__SetupWarningConfirm(0);
            func_002b5108(0xb85d, w);
            func_00287bd0(5, 0);
            func_00234570(w, 0);
            Tz__CMenuHelp__FadeOut();  // sync_global_index_if_changed
            return;
        }
    }
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f64c), 1, (s32)func_0025f610, 1)) == 0) {
        switch (sel) {
        case -1: break;
        case -4:
            Tz__CMenuHelp__FadeOut();  // sync_global_index_if_changed
            func_00287da0();
            break;
        case -2:
            func_002b5558();
            func_00287c90(1);
            func_00287c00(1);
            Tz__SelHist__FadeOut(1);  // record884_refresh_by_index
            Tz__CMenuHelp__FadeOut();  // sync_global_index_if_changed
            break;
        default:
            if (sel >= 0 && sel < func_0028afa8(D_0035f64c)) {
                func_00240bc0(sel);
                Tz__CmSLBase__SetupWarningWin(-1);
                if (func_00241770(sel)) {
                    func_00241450(1);
                    func_002b5108(0x8a91, w);
                    func_00287bd0(18, 0);
                    func_00287d20(50);
                    func_00234570(w, 0);
                }
                Tz__CMenuHelp__FadeOut();  // sync_global_index_if_changed
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0025e8a0

// 0025ebb0 (was src/anon/batch_w1609.cpp)
namespace n0025ebb0 {
extern u8 D_0035f0b3 asm("D_0035f0b3");
void func_001cd2b8(void) asm("func_001cd2b8");
s32 func_00233e60(void) asm("func_00233e60");
s32 func_00233e70(s32) asm("func_00233e70");
void func_00234570(s32, s32) asm("func_00234570");
s32 func_00234798(void) asm("func_00234798");
s32 YI__MCARD__GetResultRead(void) asm("YI__MCARD__GetResultRead");
void func_0023d2c8(s32, s32) asm("func_0023d2c8");
void Tz__MCard__MakeFname(s32) asm("Tz__MCard__MakeFname");
void func_00240b48(s32) asm("func_00240b48");
s32 func_00240ba0(void) asm("func_00240ba0");
s32 Tz__MCard__GetPos(void) asm("Tz__MCard__GetPos");
void func_00241450(s32) asm("func_00241450");
void func_002415a0(s32, s32, s32) asm("func_002415a0");
void func_00242618(s32, s32) asm("func_00242618");
void func_00242908(void) asm("func_00242908");
void func_00257000(void) asm("func_00257000");
void func_0025ee58(void) asm("func_0025ee58");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287c00(s32) asm("func_00287c00");
s32 func_00287c10(void) asm("func_00287c10");
void func_00287c30(void) asm("func_00287c30");
void func_00287c90(s32) asm("func_00287c90");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00287cd0(void) asm("func_00287cd0");
void func_00287d20(s32) asm("func_00287d20");
s32 func_00287d30(void) asm("func_00287d30");
void Tz__CmSLBase__SetupWarningConfirm(s32) asm("Tz__CmSLBase__SetupWarningConfirm");
void func_002b4ee0(void) asm("func_002b4ee0");
s32 func_002b4fb8(void) asm("func_002b4fb8");
s32 func_002b4ff8(void) asm("func_002b4ff8");
void func_002b5108(s32, s32) asm("func_002b5108");
void Tz__CmSLBase__UpdateListMess(s32) asm("Tz__CmSLBase__UpdateListMess");
/*TARGET 0025ebb0*/
void func_0025ebb0(void) asm("func_0025ebb0");
void func_0025ebb0(void)
{
    s32 flag = 0;
    s32 h = func_00240ba0();
    if (func_00287cd0() == 2) {
        if (func_002b4fb8()) return;
        if (func_00287c10() == 1) {
            func_00233e70(0);
            if (!func_00233e60()) return;
        }
        func_00287c30();
        func_00287d20(0);
        s32 r = func_00287bc0();
        if (r == 12) {
            Tz__CmSLBase__UpdateListMess(1);
            func_00287cc0(0);
        } else if (r == 23) {
            func_0025ee58();
        }
        return;
    }
    if (!func_002b4ff8()) return;
    if (func_00287cd0() == 0) func_00287c90(1);
    switch (func_00287d30()) {
    case 50:
        if (func_00233e70(0) == 0) {
            if (func_00234798()) flag = 1;
            else {
                Tz__MCard__MakeFname(Tz__MCard__GetPos());
                func_00241450(0);
                func_00287d20(51);
            }
        }
        break;
    case 52:
        if (func_00233e70(0) == 0) {
            if (YI__MCARD__GetResultRead()) flag = 1;
            else {
                func_00240b48(0);
                func_00242908();
                s32 a = func_00240ba0();
                func_0023d2c8(a, Tz__MCard__GetPos());
                func_00242618(13, 1);
                func_002b4ee0();
                func_00287c00(23);
                func_00287c90(1);
                func_00287d20(0);
                func_00257000();
                func_001cd2b8();
            }
        }
        break;
    case 51:
        if (func_00233e70(0) == 0) {
            if (func_00234798()) flag = 1;
            else {
                Tz__MCard__MakeFname(Tz__MCard__GetPos());
                func_002415a0(2, 0, 0);
                func_00287d20(52);
            }
        }
        break;
    }
    if (flag) {
        Tz__CmSLBase__SetupWarningConfirm(0);
        func_002b5108(0x8a8d, h);
        func_00287bd0(7, 0);
        func_00234570(h, 0);
        D_0035f0b3 = 0;
    }
}
}  // namespace n0025ebb0

// 0025ee58 (was src/anon/batch_w1587.cpp)
namespace n0025ee58 {
u8* func_0014aba8(void) asm("func_0014aba8");
void func_0014aa58(void*, s32, s32) asm("func_0014aa58");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 0025ee58*/
void func_0025ee58(void) asm("func_0025ee58");
void func_0025ee58(void) {
    func_0014aa58(func_0014aba8(), 15, 0);
    func_00287cc0(0);
}
}  // namespace n0025ee58

// 0025ee88 (was src/anon/auto80_199_queue.cpp)
namespace n0025ee88 {
u32 func_0025d748(void) asm("_Z13func_0025d748v");
/*TARGET 0025ee88*/
void func_0025ee88(void) asm("_Z13func_0025ee88v");
void func_0025ee88(void) {
    if ((func_0014aba8()->v252 ^ 4) != 0) {
        return;
    }

    func_00103c80(2);
    D_0035f0b4 = 1;
    func_00287cc0(2);
    func_00287da0();
    func_0025d748();
}
}  // namespace n0025ee88

// 0025eee8 (was src/anon/batch_w3862.cpp)
namespace n0025eee8 {
struct W3862Layout;
struct W3862Select;
struct W3862LightCur { u8 pad[0x18c]; s32 item; };
extern W3862Select* D_0035f64c asm("D_0035f64c");
extern W3862Select* D_0035f650 asm("D_0035f650");
extern W3862Layout* D_0035f664 asm("D_0035f664");
extern W3862LightCur* D_0035f67c asm("D_0035f67c");
extern s32 D_0035f640 asm("D_0035f640");
extern s32 D_0035f644 asm("D_0035f644");
extern u16 D_00373130[] asm("D_00373130");
u32 mb_GetMode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
s32 mb_GetNextMode(void) asm("_ZN2Tz8MenuBase11GetNextModeEv");
u32 ci_isPadHelpVisible(void) asm("_ZN2Tz6CmItem16isPadHelpVisibleEv");
s32 obj_isActive(W3862Layout*) asm("_Z16u_call4_00139d78jjjj");
s32 lay_getNum(W3862Layout*) asm("_ZN2Tz6Layout6getNumEv");
void lay_setNum(W3862Layout*, s32, s32) asm("_ZN2Tz6Layout6setNumEii");
s32 sel_isCreated(W3862Select*) asm("_ZN2Tz6Select9isCreatedEz");
s32 sel_isFadeOut(W3862Select*) asm("_ZN2Tz6Select9isFadeOutEv");
void sel_Start(W3862Select*) asm("_ZN2Tz6Select5StartEz");
s32 sel_GetCurrentItemPtr(W3862Select*) asm("_ZN2Tz6Select17GetCurrentItemPtrEv");
void cmsl_FadeOutWarningWin(void) asm("_ZN2Tz8CmSLBase17FadeOutWarningWinEv");
void cmsl_FadeOutList(void) asm("_ZN2Tz8CmSLBase11FadeOutListEv");
void sh_FadeOutAll(void) asm("_ZN2Tz7SelHist10FadeOutAllEv");
void lc_FadeOut(W3862LightCur*) asm("_ZN2Tz8LightCur7FadeOutEv");
void lc_Leave(W3862LightCur*) asm("_ZN2Tz8LightCur5LeaveEv");
s32 lc_isExist(W3862LightCur*) asm("_ZN2Tz8LightCur7isExistEv");
void help_Leave(void) asm("_ZN2Tz9CMenuHelp5LeaveEv");
void mc_DeleteAll(...) asm("_ZN2Tz10MenuCursor9DeleteAllEz");
s32 slr_GetState(void) asm("_ZN2Tz8Selector8GetStateEv");
void func_002b6418(void) asm("func_002b6418");
s32 func_0028d008(s32) asm("func_0028d008");
void func_0028cdb8(s32) asm("func_0028cdb8");
void Tz__MenuCursor__Create(s32, s32, s32, W3862Layout*, s32, s32) asm("Tz__MenuCursor__Create");
void Tz__MenuCursor__SetParent(s32, s32) asm("Tz__MenuCursor__SetParent");
void Tz__MenuCursor__SetType(s32, s32) asm("Tz__MenuCursor__SetType");
s32 func_0028cf10(s32) asm("func_0028cf10");
void Tz__LightCur__Create(W3862LightCur*, s32, s32, s32, W3862Layout*, u16*, s32) asm("Tz__LightCur__Create");
void func_0028d660(W3862LightCur*, s32) asm("func_0028d660");
void func_0025f430(W3862Select*, u32, s32) asm("func_0025f430");
static inline s32 W3862_UseSubCursor(W3862Select* sel) {
    if (sel != D_0035f64c && sel_isCreated(D_0035f64c)) return 1;
    return 0;
}
/*TARGET 0025eee8*/
// Menu cursor/light-cursor upkeep for the current menu mode (sibling of Tz__CmSave__Draw).
void Tz__CmLoad__Draw(void) asm("Tz__CmLoad__Draw");
// Menu cursor/light-cursor upkeep for the current menu mode (sibling of Tz__CmSave__Draw).
void Tz__CmLoad__Draw(void) {
    u32 mode = mb_GetMode();
    W3862Select* sel;
    s32 sub;

    if (ci_isPadHelpVisible()) {
        if (obj_isActive(D_0035f664)) {
            if (lay_getNum(D_0035f664) != 2) lay_setNum(D_0035f664, 2, -1);
        }
        if (sel_isCreated(D_0035f64c) && !sel_isFadeOut(D_0035f64c)) sel_Start(D_0035f64c);
        if (sel_isCreated(D_0035f650) && !sel_isFadeOut(D_0035f650)) sel_Start(D_0035f650);
        cmsl_FadeOutList();
        cmsl_FadeOutWarningWin();
        sh_FadeOutAll();
        lc_FadeOut(D_0035f67c);
        help_Leave();
        mc_DeleteAll();
    }
    func_002b6418();
    if (ci_isPadHelpVisible()) return;

    switch (mode) {
    case 1: case 12:
        sel = D_0035f64c;
        break;
    default:
        sel = 0;
        break;
    case 5: case 7: case 11: case 16:
        sel = D_0035f650;
        break;
    }

    if (sel == 0) {
        if (mode == 18) {
            func_0028cdb8(1);
        } else {
            mc_DeleteAll();
        }
        lc_Leave(D_0035f67c);
        return;
    }

    sub = W3862_UseSubCursor(sel);

    if (sel_isCreated(sel) && slr_GetState() == 1) {
        if (!func_0028d008(sub)) {
            Tz__MenuCursor__Create(sub, 0, 0, D_0035f664, 12, 10);
            Tz__MenuCursor__SetParent(sub, sel_GetCurrentItemPtr(sel));
            if (!lc_isExist(D_0035f67c))
                Tz__LightCur__Create(D_0035f67c, 0x7571, 0, 0, D_0035f664, D_00373130, 0);
            if (sub) {
                if (func_0028d008(0)) {
                    Tz__MenuCursor__SetType(0, 1);
                } else {
                    Tz__MenuCursor__Create(0, D_0035f644, D_0035f640, D_0035f664, 12, 10);
                    Tz__MenuCursor__SetParent(0, sel_GetCurrentItemPtr(D_0035f64c));
                }
            }
            func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(sel));
        } else {
            if (func_0028cf10(sub) == 1) Tz__MenuCursor__SetType(sub, 0);
            if (!lc_isExist(D_0035f67c)) {
                Tz__LightCur__Create(D_0035f67c, 0x7571, 0, 0, D_0035f664, D_00373130, 0);
                func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(sel));
            }
        }
    } else if (slr_GetState() == 2) {
        if (mb_GetMode() == 16 && mb_GetNextMode() != 12) {
            if (func_0028d008(sub)) func_0028cdb8(sub);
            if (lc_isExist(D_0035f67c)) lc_FadeOut(D_0035f67c);
        } else {
            if (func_0028d008(sub)) {
                func_0028cdb8(sub);
                if (sub) {
                    Tz__MenuCursor__SetType(0, 0);
                    func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(D_0035f64c));
                } else {
                    lc_FadeOut(D_0035f67c);
                }
            } else if (lc_isExist(D_0035f67c)) {
                if (sub) {
                    func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(D_0035f64c));
                } else {
                    lc_FadeOut(D_0035f67c);
                }
            }
            if (sub && sel_isFadeOut(D_0035f64c) && func_0028d008(0)) {
                func_0028cdb8(0);
                lc_FadeOut(D_0035f67c);
            }
        }
    }

    if (sub && sel_isCreated(sel) && slr_GetState() == 0 && lc_isExist(D_0035f67c)) {
        s32 item = D_0035f67c->item;
        if (item != sel_GetCurrentItemPtr(sel))
            func_0028d660(D_0035f67c, sel_GetCurrentItemPtr(sel));
    }

    switch (mode) {
    case 0: case 1: case 5: case 7: case 11: case 12: case 16:
        func_0025f430(sel, mode, sub);
        break;
    }
}
}  // namespace n0025eee8

// 0025f430 (was src/anon/batch_w1598.cpp)
namespace n0025f430 {
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00289310(u32) asm("func_00289310");
void func_002890e0(u32, s32, s32, s32, s32) asm("func_002890e0");
u32 func_002891e8(u32) asm("func_002891e8");
void func_00289038(u32, u32, s32, s32, s32, s32, s32) asm("func_00289038");
s32 func_00289358(u32) asm("func_00289358");
void Tz__CmSLBase__UpdateListMess(s32) asm("Tz__CmSLBase__UpdateListMess");
s32 func_0028d008(u32) asm("func_0028d008");
u32 func_002891d0(u32) asm("func_002891d0");
void Tz__MenuCursor__SetParent(u32, u32) asm("Tz__MenuCursor__SetParent");
s32 func_0028d6e8(u32) asm("func_0028d6e8");
void func_0028d660(u32, u32) asm("func_0028d660");
void func_0025f588(void) asm("func_0025f588");
extern u32 D_0035f67c asm("D_0035f67c");
extern u32 D_0035f64c asm("D_0035f64c");
/*TARGET 0025f430*/
void func_0025f430(u32 a0, s32 a1, u32 a2) asm("func_0025f430");
void func_0025f430(u32 a0, s32 a1, u32 a2) {
    if (func_00287cd0() != 1) return;
    if (!func_00289310(a0)) return;
    func_002890e0(a0, 1, 2, 0, -1);
    func_00289038(a0, func_002891e8(a0), 1, 1, 2, 0, -1);
    if (a1 == 12 && func_00289358(D_0035f64c)) Tz__CmSLBase__UpdateListMess(1);
    if (func_0028d008(a2)) Tz__MenuCursor__SetParent(a2, func_002891d0(a0));
    if (func_0028d6e8(D_0035f67c)) func_0028d660(D_0035f67c, func_002891d0(a0));
    func_0025f588();
}
}  // namespace n0025f430

// 0025f550 (was src/anon/tiny.cpp)
namespace n0025f550 {
void Tz__SelHist__LeaveAll(void*) asm("_Z21Tz__SelHist__LeaveAllPv");
/*TARGET 0025f550*/
void func_0025f550(BD_VALUE* bd) asm("_Z13func_0025f550P8BD_VALUE");
void func_0025f550(BD_VALUE* bd) { Tz__SelHist__LeaveAll(bd); }
}  // namespace n0025f550

// 0025f568 (was src/anon/batch_w1666.cpp)
namespace n0025f568 {
extern u8 D_0035f0b4 asm("D_0035f0b4");
/*TARGET 0025f568*/
u8 func_0025f568(void) asm("func_0025f568");
u8 func_0025f568(void) { return D_0035f0b4; }
}  // namespace n0025f568

// 0025f578 (was src/anon/batch_w1666.cpp)
namespace n0025f578 {
extern u8 D_0035f0b4 asm("D_0035f0b4");
/*TARGET 0025f578*/
void func_0025f578(void) asm("func_0025f578");
void func_0025f578(void) { D_0035f0b4 = 0; }
}  // namespace n0025f578

// 0025f588 (was src/anon/auto80_199_queue.cpp)
namespace n0025f588 {
/*TARGET 0025f588*/
u32 func_0025f588(void) asm("_Z13func_0025f588v");
u32 func_0025f588(void) {
    u32 v0 = func_00287bc0();

    if (v0 == 1) {
        u32 a3 = func_0028b040(D_0035f64c);
        func_002b6338(D_0035f6c4, 512, 0xB85B, a3);  // hash_with_seed_choice
        return Tz__CMenuHelp__Create_2(D_0035f6c4, 1);
    }

    if (v0 == 12) {
        return func_00263a58(0x8AA2, 1);
    }

    return func_00263d28();
}
}  // namespace n0025f588

// 0025f610 (was gap)
namespace n0025f610 {
extern u8 D_0035f070 asm("D_0035f070");
extern u8 D_0035f0b0 asm("D_0035f0b0");
extern u8 D_0035f0b1 asm("D_0035f0b1");
extern u8 D_0035f0b2 asm("D_0035f0b2");
extern u32 D_0035eca4 asm("D_0035eca4");
extern u32 D_0035f64c asm("D_0035f64c");
extern u8 D_00372f20[] asm("D_00372f20");
extern u8 D_00372eb8[] asm("D_00372eb8");
void func_002b4ac8(s32, s32) asm("func_002b4ac8");
void func_002b4ae0(s32) asm("func_002b4ae0");
void func_002b4af0(void*) asm("func_002b4af0");
void func_00258ce8(void*) asm("func_00258ce8");
void Tz__CmSLBase__Init() asm("Tz__CmSLBase__Init");
void func_002420d8(u32, s32) asm("func_002420d8");
u8* func_00103eb0() asm("func_00103eb0");
void TASK_MANAGER__create_thread(u32, u32, u32, u32, u32) asm("TASK_MANAGER__create_thread");
void func_0014a248() asm("func_0014a248");
void func_002b47a0() asm("func_002b47a0");
s32 YS__CACHE_BUFF__IsFlushing() asm("YS__CACHE_BUFF__IsFlushing");
void func_00170888(u32) asm("func_00170888");
void func_00253818(s32) asm("func_00253818");
void Tz__CmComm__DataLoad(s32) asm("Tz__CmComm__DataLoad");
void Tz__CmComm__DataLoadWait(s32, u32) asm("Tz__CmComm__DataLoadWait");
void func_002b63a8() asm("_ZN2Tz8CmSLBase11SetLeadDataEv");
void func_0014a238() asm("func_0014a238");
void func_00102448(u32, s32) asm("func_00102448");
void Tz__CmSave__Setup() asm("Tz__CmSave__Setup");
void func_00242618(s32, s32) asm("func_00242618");
void YI__IMAGE_CACHE__Clear() asm("YI__IMAGE_CACHE__Clear");
void func_00236148() asm("func_00236148");
s32 func_00259c60() asm("func_00259c60");
void Tz__CmSave__Draw() asm("Tz__CmSave__Draw");
void func_002b6298(u32) asm("func_002b6298");
void func_00233e70(s32) asm("func_00233e70");
s32 func_00233e60() asm("func_00233e60");
void Tz__CmLoad__Setup() asm("Tz__CmLoad__Setup");
s32 Tz__CmLoad__Control() asm("Tz__CmLoad__Control");
void Tz__CmLoad__Draw() asm("Tz__CmLoad__Draw");
s64 func_00287bc0_l() asm("func_00287bc0");
s32 func_0028b040(u32) asm("func_0028b040");
struct E32 { u32 a, b, flags; u8 pad[20]; };
E32* func_00241f10() asm("func_00241f10");
void func_002598b8(u32) asm("func_002598b8");
void func_0025d7f8(u32) asm("func_0025d7f8");

s32 func_0025f610() asm("func_0025f610");
s32 func_0025f610() {
    s32 r = 1;
    s64 m = func_00287bc0_l();
    if (m != 1) {
        if (m == 12) {
            func_0028b040(D_0035f64c);
            u8* t = (u8*)func_00241f10();
            t += func_0028b040(D_0035f64c) << 5;
            if (!(*(u32*)(t + 8) & 0x10)) r = 0;
        } else r = 0;
    }
    return r;
}

}  // namespace n0025f610

// 0025f698 (was src/anon/tiny.cpp)
namespace n0025f698 {
void func_002634c8(s32) asm("func_002634c8");
/*TARGET 0025f698*/
// 0022b930: moved to src/sasa/musical_2d.cpp (linked unit)
void func_0025f698(BD_VALUE* bd) asm("_Z13func_0025f698P8BD_VALUE");
// 0022b930: moved to src/sasa/musical_2d.cpp (linked unit)
void func_0025f698(BD_VALUE* bd) { func_002634c8(0); }
}  // namespace n0025f698

// 0025f6b0 (was src/anon/misc_2.cpp)
namespace n0025f6b0 {
/*TARGET 0025f6b0*/
void func_0025f6b0(void* self) asm("_Z13func_0025f6b0Pv");
void func_0025f6b0(void* self) {}
}  // namespace n0025f6b0

