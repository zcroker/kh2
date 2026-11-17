// Linked unit 0x00267e00-0x00268460 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/cmenu_stat.hpp"
#include "../tozawa/cmenu_equip.hpp"
#include "../tozawa/cmenu_top.hpp"

// 00267e00 (was src/anon/batch_w1710.cpp)
namespace n00267e00 {
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f018 asm("D_0035f018");
extern s16 D_003736c0[6] asm("D_003736c0");
extern u16 D_00373768[] asm("D_00373768");
extern u16 D_00373788[] asm("D_00373788");
s32 func_00289380(u32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287c10(void) asm("func_00287c10");
s32 func_0028f930(s32) asm("func_0028f930");
s32 func_00256ef0(void) asm("func_00256ef0");
s32 func_00269f58(void) asm("func_00269f58");
s32 func_002911f8(u32) asm("func_002911f8");
s32 func_00289310(u32) asm("func_00289310");
void func_00287f90(s32) asm("func_00287f90");
void func_00256ea8(void) asm("func_00256ea8");
void func_00269ef8(void) asm("func_00269ef8");
void func_00291288(u32) asm("func_00291288");
void func_0028f7e8(s32) asm("func_0028f7e8");
void func_0028f878(void) asm("func_0028f878");
void func_00287c30(void) asm("func_00287c30");
void func_0028d068(u32, s32) asm("func_0028d068");
void func_0026b448(void) asm("func_0026b448");
void func_0025f7f0(s32) asm("func_0025f7f0");
s32 func_00257070(s32) asm("func_00257070");
void func_00261ce8(s32) asm("func_00261ce8");
void func_002678a8(void) asm("func_002678a8");
void func_00277178(s32, s32) asm("func_00277178");
void func_00268460(void) asm("func_00268460");
s32 func_00269fc0(void) asm("func_00269fc0");
void func_0026a060(void) asm("func_0026a060");
void func_00256e30(void) asm("func_00256e30");
void func_0028fa98(s32) asm("func_0028fa98");
void func_00269a60(void) asm("func_00269a60");
void func_00287c90(s32) asm("func_00287c90");
s32 func_0028afa8(u32) asm("func_0028afa8");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_0026b8f0(void) asm("func_0026b8f0");
void func_00256c40(void) asm("func_00256c40");
s32 func_002891e8(u32) asm("func_002891e8");
s32 func_0028b038(u32) asm("func_0028b038");
void func_00257050(s32, s32, s32) asm("func_00257050");
void func_00287da0(void) asm("func_00287da0");
void func_0026b860(s32) asm("func_0026b860");
void func_00263c60(void) asm("func_00263c60");
void func_0028f6f0(s32) asm("func_0028f6f0");
void func_00269e20(void) asm("func_00269e20");
void func_00281b30(void) asm("func_00281b30");
void func_00287cc0(s32) asm("func_00287cc0");
void func_00287c00(s32) asm("func_00287c00");
s32 func_0028b040(u32) asm("func_0028b040");
s32 func_00269508(s32) asm("func_00269508");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_002831e0(s32, s32) asm("func_002831e0");
s32 func_0026b200(void) asm("func_0026b200");
void func_002691c8(void) asm("func_002691c8");
void func_0026b0f8(void) asm("func_0026b0f8");
void func_00269658(void) asm("func_00269658");
void func_00256e80(void) asm("func_00256e80");
s32 func_002695a0(s32) asm("func_002695a0");
void func_0028fb28(s32, s32) asm("func_0028fb28");
void func_00281d48(void) asm("func_00281d48");
void func_00281e20(void) asm("func_00281e20");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
/*TARGET 00267e00*/
void func_00267e00(void) asm("func_00267e00");
void func_00267e00(void)
{
    s32 sel = func_00289380(D_0035f01c);
    s32 st = func_00287cd0();
    s32 mode;
    if (st == 2) {
        s32 move = 0;
        s32 next = func_00287c10();
        if (next == 1 || next == 2) move = func_0028f930(1);
        else if (next == 16) move = func_0028f930(-1);
        if (!(next == 1 || next == 2)) move = move || func_00256ef0();
        if (func_00269f58() || move || func_002911f8(D_0035f018)) {
            if (sel != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                if (!(next == 1 || next == 2)) func_00256ea8();
                func_00269ef8();
                func_00291288(D_0035f018);
                if (next == 1) {
                    func_0028f7e8(1);
                    return;
                }
                if (next == 16) {
                    func_0028f878();
                    return;
                }
            }
            return;
        }
        mode = func_00287c10();
        func_00287c30();
        func_0028d068(0x754a, -1);
        if (mode == 1) {
            func_0028f7e8(1);
            func_0026b448();
            func_0025f7f0(-1);
            return;
        }
        if (mode == 2) {
            func_00261ce8(func_00257070(1));
            func_002678a8();
            return;
        }
        if (mode == 16) {
            func_00277178(16, func_00257070(1));
            return;
        }
        s32 i;
        for (i = 0; i < 6; i++) {
            if (D_003736c0[i] == mode) break;
        }
        func_00268460();
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f01c)) && !func_00269fc0()) {
        func_0026a060();
        func_00256e30();
        func_0028fa98(-1);
    }
    if (st == 0 && func_00269fc0()) {
        func_00269a60();
        func_00287c90(1);
    }
    s32 n = func_0028afa8(D_0035f01c);
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f01c), 1, (s32)func_0026b8f0, 1)) == 0) {
        switch (sel) {
        case -1:
            break;
        case -4: {
            func_00291288(D_0035f018);
            func_0026b448();
            func_00256c40();
            s32 cur = func_002891e8(D_0035f01c);
            func_00257050(2, cur, func_0028b038(D_0035f01c));
            func_00287da0();
            break;
        }
        case -11:
        case -10:
            func_0026b448();
            func_0026b860(sel == -10);
            func_00263c60();
            func_0028f6f0(1);
            func_00269e20();
            func_00256c40();
            func_00281b30();
            func_00287cc0(2);
            func_00287c00(2);
            func_00257050(2, 0, 0);
            break;
        case -7: {
            s32 k = func_00269508(func_0028b040(D_0035f01c));
            mode = func_00287bc0();
            func_00287bd0(37, 0);
            if (k == 4) func_002831e0(0, mode);
            else if (k == 1) func_002831e0(3, mode);
            break;
        }
        case -6:
            if (func_0026b200()) {
                func_002691c8();
                func_00287bd0(3, 0);
            } else {
                func_0026b0f8();
                func_00269658();
            }
            break;
        case -5: {
            func_0026b448();
            func_00263c60();
            func_0028f6f0(1);
            func_0028f6f0(0);
            func_00269e20();
            func_00256e80();
            func_00256c40();
            func_00281b30();
            func_00287cc0(2);
            func_00287c00(16);
            s32 cur = func_002891e8(D_0035f01c);
            func_00257050(2, cur, func_0028b038(D_0035f01c));
            break;
        }
        default:
            if (sel >= 0 && sel < n) {
                s16 t = D_003736c0[func_00269508(sel)];
                if (t == 6) func_0028fb28(2, D_00373788[func_002695a0(sel)]);
                else func_0028fb28(2, D_00373768[func_00269508(sel)]);
                func_00256e80();
                func_00263c60();
                func_00269e20();
                func_00287c90(1);
                func_00287c00(t);
                s32 cur = func_002891e8(D_0035f01c);
                func_00257050(2, cur, func_0028b038(D_0035f01c));
            }
            break;
        case -2: {
            func_00263c60();
            func_0028f6f0(1);
            func_00269e20();
            func_00256c40();
            func_00281b30();
            func_00287cc0(2);
            func_00287c00(1);
            s32 cur = func_002891e8(D_0035f01c);
            func_00257050(2, cur, func_0028b038(D_0035f01c));
            break;
        }
        }
    }
    if (func_00287cd0() == 1) {
        func_00281d48();
        func_00281e20();
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n00267e00

