// Linked unit 0x00264be0-0x002653a0 (one namespace per old matched source; class methods in their own namespace).
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

// 00264be0 (was src/anon/batch_wcx2_gnsa.cpp)
namespace n00264be0 {
u32 func_00257770() asm("func_00257770");
u32 func_00139d78(u32) asm("func_00139d78");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
u32 func_00257070(s32) asm("func_00257070");
void func_00266df8(u32) asm("func_00266df8");
void func_0028d8c0(u32, s32, u32, u32, u32, u32, s32, s32) asm("func_0028d8c0");
void func_0028d980(u32, s32, u32, u32, u32, u32, s32, s32, s32) asm("func_0028d980");
void Tz__Select__SetItem(u32, s32, u32, u32, u32, s32, s16*, s16*) asm("Tz__Select__SetItem");
void func_002fde18(u32, u32, u32) asm("func_002fde18");
u32 func_002891b8(u32, s32) asm("func_002891b8");
void func_0028dcc0(u32, u32) asm("func_0028dcc0");
void func_00139620(u32) asm("func_00139620");
void func_001395f8(u32) asm("func_001395f8");
void func_00138c10(u32, s32) asm("func_00138c10");
void func_00138c68(u32, s32, s32) asm("func_00138c68");
s32 func_0023aa18(u32) asm("func_0023aa18");
s32 func_0023aa38(u32) asm("func_0023aa38");
u32 func_00257140(s32) asm("func_00257140");
void Tz__Select__SetSelectMax(u32, s32) asm("Tz__Select__SetSelectMax");
void Tz__Select__SetCurrent(u32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
u32 func_0028af88(u32) asm("func_0028af88");
void func_0028af18(u32, u32) asm("func_0028af18");
void Tz__Select__SetPageMode(u32, s32) asm("Tz__Select__SetPageMode");
void func_0028b248(u32, s32) asm("func_0028b248");
void func_00266248(void) asm("func_00266248");
void func_00265c78(void) asm("func_00265c78");
void func_002666a8(void) asm("func_002666a8");
void Tz__CmTop__CreatePadHelp(s32, s32, s32) asm("Tz__CmTop__CreatePadHelp");
void func_00287cc0(s32) asm("func_00287cc0");
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035f03c asm("D_0035f03c");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f020 asm("D_0035f020");
extern u32 D_0035f0e4 asm("D_0035f0e4");
extern u32 D_0035ef6c asm("D_0035ef6c");
extern u16 D_0035ef6c_h asm("D_0035ef6c");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s16 D_00373502 asm("D_00373502");
extern u8 D_0035f0e8 asm("D_0035f0e8");
struct Num { s16 n;  };
/*TARGET 00264be0*/
void Tz__CmStat__SetupHelp(void) asm("Tz__CmStat__SetupHelp");
void Tz__CmStat__SetupHelp(void) {
    s32 i = 3;
    s32 cnt, col, i10, curId, fadeId;
    Num nums[4];
    u32 base = func_00257770();
    func_00139d78(base);
    func_0028f4d8(1, -1, 0);
    func_00266df8(func_00257070(0x17));
    { s16* p = &nums[0].n; while (i >= 0) { *p++ = D_0035ef6c_h; i--; } }
    s32 top = D_0035f3d4;
    func_0028d8c0(base, top - 1, D_0035ef68, D_0035ef64, D_0035f03c, 320, 321, 0);
    curId = top + 1;
    fadeId = top + 2;
    *(u8*)(D_0035f0e4 + 0x20) = 0;
    func_002fde18(D_0035f0e4 + 0x524, 0, 0x280);
    col = D_00373502;
    for (i = 0; i < 2; i++) {
        u32 sel = i ? D_0035f020 : D_0035f01c;
        cnt = 0;
        i10 = i * 10;
        s32 j;
        for (j = 0; j < 10; j++) {
            Tz__Select__SetItem(sel, j, D_0035ef68, D_0035ef64, D_0035f03c, -1, &nums[0].n, &nums[0].n);
            s32 idx = i10 + j;
            u32 item = func_002891b8(sel, j);
            func_0028dcc0(item, base);
            func_00139620(item);
            u32 cur = base + idx * 0x1B4 + 0x5EF0;
            func_001395f8(item);
            func_00138c10(item, col);
            s32 px = func_0023aa18(item + 0x18);
            s32 py = func_0023aa38(item + 0x18);
            func_00138c10(item, nums[0].n);
            *(u32*)(item + 0x198) = 0;
            func_0028d980(cur, curId, D_0035ef68, D_0035ef64, D_0035f03c, func_00257140(2), -1, -1, 0);
            func_0028dcc0(cur, item);
            func_00139620(cur);
            func_001395f8(cur);
            *(u32*)(cur + 0x1B0) = 1;
            func_00138c68(cur, px, py);
            *(void**)(cur + 0x198) = (void*)(D_0035f0e4 + idx * 32 + 0x524);
            u32 fade = base + idx * 0x198 + 0x87D0;
            func_0028d8c0(fade, fadeId, D_0035ef68, D_0035ef64, D_0035f03c, D_0035ef6c, -1, 0);
            func_0028dcc0(fade, item);
            func_00138c68(fade, px, py);
            if (*(u32*)(D_0035f0e4 + 0x18) & (1 << idx)) cnt++;
        }
        Tz__Select__SetSelectMax(sel, cnt);
    }
    Tz__Select__SetCurrent(D_0035f01c, 0, 1, 0, 2);
    Tz__Select__SetCurrent(D_0035f020, 0, 1, 0, 2);
    u32 en = func_0028af88(D_0035f01c);
    en |= 0xC0000;
    en |= 0xC000;
    en &= ~0x10;
    func_0028af18(D_0035f01c, en);
    func_0028af18(D_0035f020, en);
    Tz__Select__SetPageMode(D_0035f01c, 1);
    func_0028b248(D_0035f01c, 10);
    Tz__Select__SetPageMode(D_0035f020, 1);
    func_0028b248(D_0035f020, 10);
    func_00266248();
    func_00265c78();
    func_002666a8();
    D_0035f0e8 = 0;
    Tz__CmTop__CreatePadHelp(0xB61A, -1, -1);
    func_00287cc0(0);
}
}  // namespace n00264be0

// 00265018 (was src/anon/batch_w3692_g.cpp)
namespace n00265018 {
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00287bc0() asm("func_00287bc0");
void func_00287f90(s32) asm("func_00287f90");
void func_00287c30() asm("func_00287c30");
void func_0028af18(s32, s32) asm("func_0028af18");
s32 func_00289310(s32) asm("func_00289310");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, void*, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00287da0() asm("func_00287da0");
s32 func_00288040() asm("func_00288040");
void func_00288018() asm("func_00288018");
void func_00287c00(s32) asm("func_00287c00");
void func_00287cc0(s32) asm("func_00287cc0");
u32 func_00267248() asm("func_00267248");
s32 func_00287c10() asm("func_00287c10");
s32 func_00265b88() asm("func_00265b88");
s32 func_0028f930(s32) asm("func_0028f930");
s32 func_00257970() asm("func_00257970");
s32 func_00256ef0() asm("func_00256ef0");
void func_00265ab8() asm("func_00265ab8");
void func_00256ea8() asm("func_00256ea8");
void func_0028f7e8(s32) asm("func_0028f7e8");
void Tz__CmStat__SetupTop(s32) asm("Tz__CmStat__SetupTop");
void Tz__CmStat__SetupHelp() asm("Tz__CmStat__SetupHelp");
s32 func_0028ae28(u32, s32) asm("func_0028ae28");
s32 func_00265c10() asm("func_00265c10");
void func_0028ab20(u32) asm("func_0028ab20");
void func_00265c50() asm("func_00265c50");
void func_0028fa98(s32) asm("func_0028fa98");
void func_00256e30() asm("func_00256e30");
void func_00267398() asm("func_00267398");
void func_00267280() asm("func_00267280");
void func_002674f8(s32) asm("func_002674f8");
void Tz__CMenuHelp__FadeOut() asm("Tz__CMenuHelp__FadeOut");
void Tz__SelHist__FadeOut(s32) asm("Tz__SelHist__FadeOut");
void Tz__CmAbility__FadeOutAll() asm("Tz__CmAbility__FadeOutAll");
void func_00256e80() asm("func_00256e80");
extern u8 D_00267590[] asm("D_00267590");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f020 asm("D_0035f020");
extern u8 D_0035f0e8 asm("D_0035f0e8");
/*TARGET 00265018*/
void Tz__CmStat__CtrlHelp(void) asm("Tz__CmStat__CtrlHelp");
void Tz__CmStat__CtrlHelp(void) {
    u32 sel = func_00267248();
    D_0035f0e8 = 0;
    s32 st = func_00289380(sel);
    s32 mode = func_00287cd0();
    if (mode == 2) {
        s32 f = 0;
        s32 cur = func_00287c10();
        if (func_00265b88() || func_0028f930(1) || func_00257970()) f = 1;
        if (cur == 23) f = f || func_00256ef0();
        if (f) {
            if (st != -1 || func_00289310(sel)) {
                func_00287f90(0);
                func_00265ab8();
                if (cur == 23) func_00256ea8();
            }
        } else {
            func_00265ab8();
            func_00287c30();
            register s32 t asm("$2") = func_00287bc0();
            s32 n;
            {
                /* sched2 tie: gcc puts li a1 in the jal delay slot; the original keeps n's copy there. */
                u32 g = D_0035f01c;
                register u32 a0 asm("$4") = g;
                register u32 a1 asm("$5") = 0x73;
                asm volatile(".set noreorder\n\tjal func_0028af18\n\tmove %0,%1\n\t.set reorder"
                             : "=r"(n) : "r"(t), "r"(a0), "r"(a1)
                             : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13",
                               "$14", "$15", "$24", "$25", "$31", "hi", "lo", "memory");
            }
            func_0028af18(D_0035f020, 0x73);
            func_0028f7e8(1);
            if (n == 23) Tz__CmStat__SetupTop(0);
            else if (n == 24) Tz__CmStat__SetupHelp();
        }
    } else {
        if (st != -1 || func_00289310(sel)) {
            if (!func_0028ae28(sel, 0) || !func_00265c10()) {
                func_0028ab20(D_0035f01c);
                func_0028ab20(D_0035f020);
                func_00265c50();
                func_0028fa98(-1);
                func_00256e30();
            }
        }
        if (mode == 0 && func_0028ae28(sel, 0) && func_00265c10()) func_00287cc0(1);
        if (!func_00242848(func_00287df0(st, func_00289310(sel), 1, D_00267590, 1))) {
            switch (st) {
            case -4:
                func_00267398();
                func_00287da0();
                break;
            case -13:
            case -12:
                func_00267280();
                break;
            case -11:
            case -10:
                func_002674f8(st == -10);
                Tz__CMenuHelp__FadeOut();
                Tz__SelHist__FadeOut(1);
                Tz__CmAbility__FadeOutAll();
                func_00287c00(func_00287bc0());
                func_00287cc0(2);
                break;
            case -1:
                break;
            case -2:
                Tz__CMenuHelp__FadeOut();
                Tz__SelHist__FadeOut(1);
                Tz__CmAbility__FadeOutAll();
                func_00256e80();
                func_00287c00(23);
                func_00287c90(1);
                break;
            }
        }
        if (func_00288040()) func_00288018();
    }
}
}  // namespace n00265018

