// Linked unit 0x00285070-0x002853b8 (one namespace per old matched source; class methods in their own namespace).
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

// 00285070 (was src/anon/batch_w1583_g.cpp)
namespace n00285070 {
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00285728(void) asm("func_00285728");
s32 func_00287c10(void) asm("func_00287c10");
void func_00287da0(void) asm("func_00287da0");
void func_00288658(s32, s32) asm("func_00288658");
void func_00288670(void (*)(void)) asm("func_00288670");
void Tz__Ending__LeaveAll(void) asm("Tz__Ending__LeaveAll");
void func_00103c80(s32) asm("func_00103c80");
s32 func_0014aba8(void) asm("func_0014aba8");
void func_0014aa58(s32, s32, s32) asm("func_0014aa58");
void func_002bd760(s32) asm("func_002bd760");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 Tz__Ending__SelCtrl(void) asm("Tz__Ending__SelCtrl");
s32 func_0028ae28(s32, s32) asm("func_0028ae28");
void func_00287c00(s32) asm("func_00287c00");
void func_002856c8(void) asm("func_002856c8");
extern s32 D_0035f2d4 asm("D_0035f2d4");
extern s32 D_0035f2dc asm("D_0035f2dc");
/*TARGET 00285070*/
void func_00285070(void) asm("func_00285070");
void func_00285070(void) {
    s32 s2 = func_00287bc0();
    s32 s0 = func_00287cd0();
    if (s0 == 2) {
        if (func_00285728()) return;
        if (func_00287c10()) {
            func_00287da0();
            if (s2 == 1) {
                func_00288658(4, 10);
                func_00288670(Tz__Ending__LeaveAll);
                D_0035f2d4 = s2;
            } else {
                func_00103c80(3);
                func_0014aa58(func_0014aba8(), 0xF, 0);
                func_002bd760(0x3C);
                D_0035f2d4 = s0;
            }
        }
        func_00287bd0(0, 0);
        func_00287cc0(1);
    } else {
        s32 s1 = Tz__Ending__SelCtrl();
        if (func_0028ae28(D_0035f2dc, 0) && s0 != 1) func_00287cc0(1);
        if (s1 == -1) return;
        if (s1 == 1) func_00287c00(3);
        else if (s2 == 1) func_00287c00(3);
        else func_00287c00(0);
        func_002856c8();
        func_00287cc0(2);
    }
}
}  // namespace n00285070

// 002851e0 (was src/anon/batch_w1583_g.cpp)
namespace n002851e0 {
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00287cd0(void) asm("func_00287cd0");
extern s32 D_0035f2dc asm("D_0035f2dc");
s32 func_0028d008(s32) asm("func_0028d008");
void Tz__MenuCursor__Create(s32, s32, s32, s32, s32, s32) asm("Tz__MenuCursor__Create");
s32 func_002891d0(s32) asm("func_002891d0");
void Tz__MenuCursor__SetParent(s32, s32) asm("Tz__MenuCursor__SetParent");
s32 func_0028d6e8(s32) asm("func_0028d6e8");
void Tz__LightCur__Create(s32, s32, s32, s32, s32, void*, s32) asm("Tz__LightCur__Create");
void func_0028d660(s32, s32) asm("func_0028d660");
s32 func_00289310(s32) asm("func_00289310");
s32 func_002891e8(s32) asm("func_002891e8");
void func_002890e0(s32, s32, s32, s32, s32) asm("func_002890e0");
void func_00289038(s32, s32, s32, s32, s32, s32, s32) asm("func_00289038");
void func_0028ce38(void) asm("func_0028ce38");
void func_0028d5d0(s32) asm("func_0028d5d0");
extern s32 D_0035f2c8 asm("D_0035f2c8");
extern s32 D_0035f2e0 asm("D_0035f2e0");
extern u8 D_00374380[] asm("D_00374380");
/*TARGET 002851e0*/
void Tz__Ending__Draw(void) asm("Tz__Ending__Draw");
void Tz__Ending__Draw(void) {
    s32 a = func_00287bc0();
    s32 st = func_00287cd0();
    if ((u32)(a - 1) >= 2) return;
    if (st == 1) {
        if (!func_0028d008(0)) {
            Tz__MenuCursor__Create(0, 0, 0, D_0035f2c8, 8, 8);
            Tz__MenuCursor__SetParent(0, func_002891d0(D_0035f2dc));
            if (!func_0028d6e8(D_0035f2e0)) {
                Tz__LightCur__Create(D_0035f2e0, 0x754A, 0, 0, D_0035f2c8, D_00374380, 0);
                func_0028d660(D_0035f2e0, func_002891d0(D_0035f2dc));
            }
        }
        if (func_00289310(D_0035f2dc)) {
            s32 n = func_002891e8(D_0035f2dc);
            func_002890e0(D_0035f2dc, 1, 2, 0, -1);
            func_00289038(D_0035f2dc, n, 1, 1, 2, 0, -1);
            if (func_0028d008(0)) Tz__MenuCursor__SetParent(0, func_002891d0(D_0035f2dc));
            if (func_0028d6e8(D_0035f2e0)) func_0028d660(D_0035f2e0, func_002891d0(D_0035f2dc));
        }
    } else if (st == 2) {
        if (func_0028d008(0)) {
            func_0028ce38();
            func_0028d5d0(D_0035f2e0);
        }
    }
}
}  // namespace n002851e0

