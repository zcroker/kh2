// Linked unit 0x00277708-0x002788c0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/jiminy.hpp"
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
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/cmenu_stat.hpp"
#include "../tozawa/cmenu_ability.hpp"

// 00277708 (was src/anon/batch_w320.cpp)
namespace n00277708 {
extern u16* D_0035f230 asm("D_0035f230");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f03c asm("D_0035f03c");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef64 asm("D_0035ef64");
u16* func_0026b850(void) asm("func_0026b850");
s32 func_002813b8(void) asm("func_002813b8");
s32 func_00257118(s32) asm("func_00257118");
void Tz__Select__SetItem(u32, s32, u32, u32, u32, s32, s32, s32) asm("Tz__Select__SetItem");
void Tz__Select__SetExOffset(u32, s32, s32, s32) asm("Tz__Select__SetExOffset");
u8* func_002891b8(u32, s32) asm("func_002891b8");
void func_00139620(u8*) asm("func_00139620");
void func_001395f8(u8*) asm("func_001395f8");
s32 func_00192048(u32) asm("func_00192048");
s32 func_0027aa78(void) asm("func_0027aa78");
/*TARGET 00277708*/
s32 func_00277708(s32 start) asm("func_00277708");
s32 func_00277708(s32 start)
{
    u16* t0 = func_0026b850();
    s32 mask = func_002813b8();
    *D_0035f230 = mask;
    s32 n = 0;
    s32 j = start;
    u16* tbl = t0;
    for (s32 i = 0; i < 7; i++, tbl++) {
        if (i == 6) continue;
        u8 off = ((mask >> i) ^ 1) & 1;
        if (off) continue;
        n++;
        s32 a = func_00257118(0);
        s32 b = func_00257118(1);
        Tz__Select__SetItem(D_0035f01c, j, D_0035ef68, D_0035ef64, D_0035f03c, -1, a, b);
        Tz__Select__SetExOffset(D_0035f01c, j, 0, -1);
        func_00139620(func_002891b8(D_0035f01c, j));
        u8* nd = func_002891b8(D_0035f01c, j);
        *(s32*)(nd + 408) = func_00192048(*tbl);
        func_001395f8(func_002891b8(D_0035f01c, j++));
    }
    if (!func_0027aa78()) return n;
    n++;
    s32 a = func_00257118(0);
    s32 b = func_00257118(1);
    Tz__Select__SetItem(D_0035f01c, j, D_0035ef68, D_0035ef64, D_0035f03c, -1, a, b);
    Tz__Select__SetExOffset(D_0035f01c, j, 0, -1);
    func_00139620(func_002891b8(D_0035f01c, j));
    u8* nd = func_002891b8(D_0035f01c, j);
    *(s32*)(nd + 408) = func_00192048(0xb2ec);
    func_001395f8(func_002891b8(D_0035f01c, j));
    *D_0035f230 |= 0x80;
    return n;
}
}  // namespace n00277708

// 00277938 (was src/anon/batch_w3792.cpp)
namespace n00277938 {
extern s32 D_0035f01c asm("D_0035f01c");
s32 func_00257770(void) asm("func_00257770");
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287c10(void) asm("func_00287c10");
s32 func_00256ef0(void) asm("func_00256ef0");
s32 func_0027a1c8(void) asm("func_0027a1c8");
s32 func_0028f930(s32) asm("func_0028f930");
s32 func_00257970(void) asm("func_00257970");
s32 func_00289310(s32) asm("func_00289310");
void func_00287f90(s32) asm("func_00287f90");
void func_0027a180(void) asm("func_0027a180");
void func_00256ea8(void) asm("func_00256ea8");
void Tz__SelHist__LeaveAll(void) asm("Tz__SelHist__LeaveAll");
void func_00287c30(void) asm("func_00287c30");
void func_0028af18(s32, s32) asm("func_0028af18");
void func_0028f7e8(s32) asm("func_0028f7e8");
void func_002551b8(void) asm("func_002551b8");
void Tz__CmAbility__SetupSel(void) asm("Tz__CmAbility__SetupSel");
s32 func_002570a0(s32) asm("func_002570a0");
void func_0027aed8(s32, s32*, s32*) asm("func_0027aed8");
void func_002677f0(s32, s32) asm("func_002677f0");
s32 func_0028ae28(s32, s32) asm("func_0028ae28");
void func_0028da70(s32, s32) asm("func_0028da70");
void func_0028ab20(s32) asm("func_0028ab20");
void func_00256e30(void) asm("func_00256e30");
void func_0028fa98(s32) asm("func_0028fa98");
void func_0027b6b8(void) asm("func_0027b6b8");
void func_00287c90(s32) asm("func_00287c90");
s32 func_0028afa8(s32) asm("func_0028afa8");
void Tz__CmAbility__SelCheck(void) asm("Tz__CmAbility__SelCheck");
s32 func_00287df0(s32, s32, s32, void (*)(void), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00287da0(void) asm("func_00287da0");
void Tz__CMenuHelp__FadeOut(void) asm("Tz__CMenuHelp__FadeOut");
void func_00256e80(void) asm("func_00256e80");
void Tz__SelHist__FadeOut(s32) asm("Tz__SelHist__FadeOut");
void Tz__CmAbility__FadeOutSelList(void) asm("Tz__CmAbility__FadeOutSelList");
void func_00287c00(s32) asm("func_00287c00");
struct W408 { u8 pad[408]; s32 f408; };
W408* func_002891b8(s32, s32) asm("func_002891b8");
void func_0028fb68(s32, s32) asm("func_0028fb68");
s32 func_002891e8(s32) asm("func_002891e8");
void func_00257050(s32, s32, s32) asm("func_00257050");
s32 func_00257070(s32) asm("func_00257070");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
/*TARGET 00277938*/
// 00277938: the common tail is written out in every switch case (cross-jumped back into one block).
void func_00277938(void) asm("func_00277938");
// 00277938: the common tail is written out in every switch case (cross-jumped back into one block).
void func_00277938(void)
{
    s32 v;
    s32 w;
    s32 h = func_00257770();
    s32 r = func_00289380(D_0035f01c);
    s32 st = func_00287cd0();
    if (st == 2) {
        s32 h2 = 0;
        s32 m = func_00287c10();
        if (m == 0) h2 = func_00256ef0();
        if (func_0027a1c8() || h2 || (m < 2u && func_0028f930(0)) || func_00257970()) {
            if (r != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                func_0027a180();
                if (m == 0) func_00256ea8();
                if (m < 2u) Tz__SelHist__LeaveAll();
            }
            return;
        }
        func_00287c30();
        func_0028af18(D_0035f01c, 115);
        if (m == 0) {
            func_0028f7e8(0);
            func_002551b8();
        } else if (m == 16) {
            Tz__CmAbility__SetupSel();
        } else if (m == 1) {
            func_0027aed8(func_002570a0(15), &v, &w);
            if (v) w = 0;
            func_002677f0(1, w);
        }
        return;
    }
    if ((r != -1 || func_00289310(D_0035f01c)) && !func_0028ae28(D_0035f01c, 0)) {
        func_0028da70(h, 141);
        func_0028ab20(D_0035f01c);
        func_00256e30();
        func_0028fa98(-1);
    }
    if (st == 0 && func_0028ae28(D_0035f01c, 0)) {
        func_0027b6b8();
        func_00287c90(1);
    }
    s32 n = func_0028afa8(D_0035f01c);
    if (func_00242848(func_00287df0(r, func_00289310(D_0035f01c), 1, Tz__CmAbility__SelCheck, 1)) == 0) {
        switch (r) {
        case -4:
            func_00287da0();
            { v = func_00257070(15); if (v != func_002891e8(D_0035f01c)) func_00257050(16, 0, 0); func_00257050(15, func_002891e8(D_0035f01c), 0); }
            break;
        case -5:
            Tz__CMenuHelp__FadeOut();
            func_00256e80();
            Tz__SelHist__FadeOut(0);
            Tz__CmAbility__FadeOutSelList();
            func_00287c90(1);
            func_00287c00(1);
            { v = func_00257070(15); if (v != func_002891e8(D_0035f01c)) func_00257050(16, 0, 0); func_00257050(15, func_002891e8(D_0035f01c), 0); }
            break;
        case -2:
            Tz__CMenuHelp__FadeOut();
            func_00256e80();
            Tz__SelHist__FadeOut(0);
            Tz__CmAbility__FadeOutSelList();
            func_00287c90(1);
            func_00287c00(0);
            { v = func_00257070(15); if (v != func_002891e8(D_0035f01c)) func_00257050(16, 0, 0); func_00257050(15, func_002891e8(D_0035f01c), 0); }
            break;
        case -1:
            goto end;
        default:
            if (r < 0 || r >= n) goto end;
            v = 16;
            Tz__CMenuHelp__FadeOut();
            Tz__CmAbility__FadeOutSelList();
            func_00287c90(1);
            func_00287c00(v);
            func_0028fb68(1, func_002891b8(D_0035f01c, r)->f408);
            v = func_002570a0(15);
            if (func_002891e8(D_0035f01c) != v) func_00257050(16, 0, 0);
            { v = func_00257070(15); if (v != func_002891e8(D_0035f01c)) func_00257050(16, 0, 0); func_00257050(15, func_002891e8(D_0035f01c), 0); }
            break;
        }
    }
end:
    if (func_00288040()) func_00288018();
}
}  // namespace n00277938

// 00277d20 (was src/anon/batch_w1713_nsa.cpp)
namespace n00277d20 {
struct W1713Sub { u8 pad[1]; };
struct W1713Item {
    u8 pad0[0x18];
    W1713Sub sub;              /* 0x18 */
    u8 pad19[0x1b0 - 0x19];
    s32 mode;                  /* 0x1b0 */
};
struct W1713Item2 { u8 pad[0x198]; };
struct W1713Obj {
    u8 pad0[0x18];
    W1713Sub sub;              /* 0x18 */
    u8 pad19[0x1b4 - 0x19];
    void* callback;            /* 0x1b4 */
};
struct W1713Menu {
    u8 pad0[0xd30];
    W1713Item tabs[24];        /* 0x0d30 */
    W1713Item frames[24];      /* 0x3610 */
    W1713Item labels[24];      /* 0x5ef0 */
    W1713Item2 icons[24];      /* 0x87d0 */
};
struct W1713Slot { s8 a; s8 flag; u8 pad[6]; };
struct W1713Save {
    u8 pad0[7];
    s8 count;                  /* 0x07 */
    u8 pad8[8];
    W1713Slot slots[1];        /* 0x10 */
};
struct W1713Tex { u8 pad[0x28]; s32 id; };
extern s32 D_0035ef64 asm("D_0035ef64");
extern s32 D_0035ef68 asm("D_0035ef68");
extern s32 D_0035ef6c asm("D_0035ef6c");
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f03c asm("D_0035f03c");
extern s32 D_0035f04c asm("D_0035f04c");
extern W1713Save* D_0035f230 asm("D_0035f230");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s16 D_01e21ee0[2][4] asm("D_01e21ee0");
W1713Menu* func_00257770(void) asm("func_00257770");
s32 func_0028f930(s32) asm("func_0028f930");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
s32 func_002570a0(s32) asm("func_002570a0");
void func_0027aed8(s32, s32*, s32*) asm("func_0027aed8");
void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("Tz__Select__SetItem");
W1713Obj* func_002891b8(s32, s32) asm("func_002891b8");
void func_00138c10(void*, s32) asm("func_00138c10");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
s32 func_0023aa78(void*) asm("func_0023aa78");
s32 func_0023aa18(void*) asm("func_0023aa18");
s32 func_0023aa38(void*) asm("func_0023aa38");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
void func_00139620(void*) asm("func_00139620");
void func_001395f8(void*) asm("func_001395f8");
s32 func_00257140(s32) asm("func_00257140");
void func_0027b960(void) asm("func_0027b960");
W1713Tex* func_0023f1b0(s32) asm("func_0023f1b0");
s32 func_0023c4b8(W1713Tex*, s32) asm("func_0023c4b8");
s32 func_00236ca8(s32, s32) asm("func_00236ca8");
void func_00257708(s32) asm("func_00257708");
s32 func_002570f0(void) asm("func_002570f0");
void func_0028bae0(s32, s32, s32, s32, s32, s32, s32, W1713Menu*, s32) asm("func_0028bae0");
void Tz__Select__SetSelectMax(s32, s32) asm("Tz__Select__SetSelectMax");
void func_0027c2f8(void) asm("func_0027c2f8");
void Tz__Select__SetPageMode(s32, s32) asm("Tz__Select__SetPageMode");
void func_0028b248(s32, s32) asm("func_0028b248");
void func_00257050(s32, s32, s32) asm("func_00257050");
s32 func_0028af88(s32) asm("func_0028af88");
s32 func_00258068(s32) asm("func_00258068");
s32 func_0028b040(s32) asm("func_0028b040");
void func_0028af18(s32, s32) asm("func_0028af18");
void func_0028af28(s32, s32) asm("func_0028af28");
s32 func_00283ab8(s32) asm("func_00283ab8");
void Tz__CmTop__CreatePadHelp(s32, s32, s32) asm("Tz__CmTop__CreatePadHelp");
void func_0027b0f8(void) asm("func_0027b0f8");
void Tz__CmAbility__UpdateNew(void) asm("Tz__CmAbility__UpdateNew");
void func_0027a208(void) asm("func_0027a208");
void func_00287cc0(s32) asm("func_00287cc0");
/* The original passes the colour before the shared screen globals. */
static inline __attribute__((always_inline)) void W1713InitIcon(void* p, s32 id, s32 color, s32 w, s32 h, s32 tex) {
    func_0028d8c0(p, id, w, h, tex, color, -1, 0);
}
/*TARGET 00277d20*/
void Tz__CmAbility__SetupSel(void) asm("Tz__CmAbility__SetupSel");
void Tz__CmAbility__SetupSel(void) {
    W1713Menu* menu = func_00257770();
    s32 i;
    s32 j;
    s32 n;
    s32 base;
    s32 noSave;
    s32 hasData;
    s32 w;
    s32 x;
    s32 y;
    s32 a;
    s32 b;
    s32 cur;
    s32 slot;
    s32 val;      /* selected count, then menu flags, then the second sound id */

    if (func_0028f930(0) == 0) {
        func_0028f4d8(0, -1, 0);
    }
    if (func_0028f930(1) == 0) {
        func_0028f4d8(1, -1, 0);
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            D_01e21ee0[i][j] = D_0035ef6c;
        }
    }
    base = D_0035f3d4;
    func_0028d8c0(menu, base, D_0035ef68, D_0035ef64, D_0035f03c, 230, 231, 0);
    n = D_0035f230->count < 10 ? D_0035f230->count : 9;
    if (n == 0) n = 1;
    func_0027aed8(func_002570a0(15), &noSave, &hasData);
    base = D_0035f3d4;
    for (i = 0; i < n; i++) {
        W1713Obj* obj;
        W1713Item* p;
        W1713Item* q;
        W1713Item2* ic;
        Tz__Select__SetItem(D_0035f01c, i, D_0035ef68, D_0035ef64, D_0035f03c, -1, D_01e21ee0[0], D_01e21ee0[1]);
        obj = func_002891b8(D_0035f01c, i);
        func_00138c10(obj, 0xf8);
        w = func_0023aa78(&obj->sub);
        x = func_0023aa18(&obj->sub);
        y = func_0023aa38(&obj->sub);
        func_00138c10(obj, D_0035ef6c);
        func_00138c68(obj, 0, i * w);
        func_0028dcc0(obj, menu);
        func_00139620(obj);
        if (noSave == 0 && hasData != 0) {
            obj->callback = (void*)func_0027b960;
        }
        p = &menu->labels[i];
        func_0028d980(p, base, D_0035ef68, D_0035ef64, D_0035f03c, func_00257140(0), -1, -1, 0);
        func_0028dcc0(p, obj);
        func_00139620(p);
        func_001395f8(p);
        q = &menu->frames[i];
        func_0028d980(q, base, D_0035ef68, D_0035ef64, D_0035f03c, 251, -1, -1, 0);
        func_0028dcc0(q, obj);
        func_00138c10(q, D_0035ef6c);
        func_00139620(q);
        q->mode = 1;
        ic = &menu->icons[i];
        W1713InitIcon(ic, base + 2, D_0035ef6c, D_0035ef68, D_0035ef64, D_0035f03c);
        func_0028dcc0(ic, obj);
        func_00138c68(ic, x, y);
    }
    for (i = 0; i < n; i++) {
        W1713Item* p = &menu->tabs[i];
        func_0028d980(p, base, D_0035ef68, D_0035ef64, D_0035f03c, 276, -1, -1, 0);
        w = func_0023aa78(&p->sub);
        func_00138c68(p, 0, w * i);
        func_00138c10(p, D_0035ef6c);
        func_001395f8(p);
        func_0028dcc0(p, menu);
        p->mode = 2;
    }
    a = func_0023c4b8(func_0023f1b0(D_0035f03c), D_0035ef68);
    b = func_00236ca8(func_0023f1b0(D_0035f03c)->id, D_0035ef64);
    val = D_0035f230->count;
    if (val == 0) {
        func_00257708(1);
        val = n;
    }
    func_0028bae0(D_0035f04c, base, a, b, func_002570f0(), val, n, menu, 0);
    n = D_0035f230->count;
    if (n == 0) n = 1;
    Tz__Select__SetSelectMax(D_0035f01c, n);
    func_0027c2f8();
    Tz__Select__SetPageMode(D_0035f01c, 1);
    func_0028b248(D_0035f01c, 9);
    func_00257050(16, 0, 0);
    cur = func_0028af88(D_0035f01c);
    val = 0xc000;
    if (func_00258068(0) != 0) val = 0xc100;
    slot = func_0028b040(D_0035f01c);
    if (noSave == 0 && D_0035f230->count != 0) {
        if (D_0035f230->slots[slot].flag != 0) val |= 0x200;
    }
    func_0028af18(D_0035f01c, cur | val);
    if (D_0035f230->count == 0) {
        func_0028af28(D_0035f01c, 16);
    }
    val = -1;
    if (func_00283ab8(2) != 0) {
        val = 0xcbdd;
        cur = func_0028af88(D_0035f01c) | 0x400;
        func_0028af18(D_0035f01c, cur);
    }
    if (func_00258068(0) != 0) {
        Tz__CmTop__CreatePadHelp(0xb373, 0xb61a, val);
    } else {
        Tz__CmTop__CreatePadHelp(0xb61a, val, -1);
    }
    if (noSave == 0) {
        func_0027b0f8();
    }
    Tz__CmAbility__UpdateNew();
    func_0027a208();
    func_00287cc0(0);
}
}  // namespace n00277d20

// 00278318 (was src/anon/batch_w2358.cpp)
namespace n00278318 {
extern s32 D_0035f01c asm("D_0035f01c");
extern u16 D_00373e28[] asm("D_00373e28");
u8* func_00257770(void) asm("func_00257770");
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287c10(void) asm("func_00287c10");
s32 func_0028f930(s32) asm("func_0028f930");
s32 func_00256ef0(void) asm("func_00256ef0");
s32 func_00257970(void) asm("func_00257970");
s32 func_0027a908(s32) asm("func_0027a908");
s32 func_00289310(s32) asm("func_00289310");
void func_00287f90(s32) asm("func_00287f90");
void func_00256ea8(void) asm("func_00256ea8");
void func_0027a898(s32) asm("func_0027a898");
void func_0028f7e8(s32) asm("func_0028f7e8");
void Tz__SelHist__LeaveAll(void) asm("Tz__SelHist__LeaveAll");
void func_00287c30(void) asm("func_00287c30");
void func_0028af18(s32, s32) asm("func_0028af18");
void func_00257708(s32) asm("func_00257708");
void Tz__CmAbility__SetupTop(s32) asm("Tz__CmAbility__SetupTop");
void func_00279040(void) asm("func_00279040");
void Tz__CmAbility__SetupSel(void) asm("Tz__CmAbility__SetupSel");
void func_002788c0(void) asm("func_002788c0");
s32 func_002570a0(s32) asm("func_002570a0");
void func_0027aed8(s32, s32*, s32*) asm("func_0027aed8");
void func_00257050(s32, s32, s32) asm("func_00257050");
void func_002677f0(s32, s32) asm("func_002677f0");
s32 func_0027a990(void) asm("func_0027a990");
void func_0027aa10(void) asm("func_0027aa10");
void func_0028da70(u8*, s32) asm("func_0028da70");
void func_0028fa98(s32) asm("func_0028fa98");
void func_00256e30(void) asm("func_00256e30");
void func_0027b6b8(void) asm("func_0027b6b8");
void func_00287c90(s32) asm("func_00287c90");
s32 func_0028afa8(s32) asm("func_0028afa8");
s32 func_00287df0(s32, s32, s32, void (*)(void), s32) asm("func_00287df0");
void Tz__CmAbility__SelCheck(void) asm("Tz__CmAbility__SelCheck");
s32 func_00242848(s32) asm("func_00242848");
void func_00287da0(void) asm("func_00287da0");
s32 func_002891e8(s32) asm("func_002891e8");
s32 func_0028b038(s32) asm("func_0028b038");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
void func_0027b548(s32) asm("func_0027b548");
void Tz__CMenuHelp__FadeOut(void) asm("Tz__CMenuHelp__FadeOut");
void Tz__SelHist__FadeOut(s32) asm("Tz__SelHist__FadeOut");
void func_0027a7e0(s32) asm("func_0027a7e0");
void func_00287c00(s32) asm("func_00287c00");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_002831e0(s32, s32) asm("func_002831e0");
void Tz__CmAbility__ChgEquip(void) asm("Tz__CmAbility__ChgEquip");
void func_002799b0(void) asm("func_002799b0");
void Tz__CmAbility__UpdateNew(void) asm("Tz__CmAbility__UpdateNew");
void func_0027a208(void) asm("func_0027a208");
void func_0027b248(s32) asm("func_0027b248");
void func_00256e80(void) asm("func_00256e80");
s32 Tz__CmAbility__Cur2AbiltyType(void) asm("Tz__CmAbility__Cur2AbiltyType");
void func_0028fb28(s32, u16) asm("func_0028fb28");
s32 func_00258068(s32) asm("func_00258068");
/*TARGET 00278318*/
// Menu state handler: runs the sub-menu selected by func_00287c10 while the menu
// is open (state 2), otherwise handles the list result r (cancel / special ids / row).
void func_00278318(void) asm("func_00278318");
// Menu state handler: runs the sub-menu selected by func_00287c10 while the menu
// is open (state 2), otherwise handles the list result r (cancel / special ids / row).
void func_00278318(void) {
    s32 c = 0;
    u8* w = func_00257770();
    s32 r = func_00289380(D_0035f01c);
    s32 st = func_00287cd0();
    s32 a, b;
    if (st == 2) {
        s32 m = func_00287c10();
        s32 isA = m >= 17 && m <= 19;
        s32 notA = !isA;
        do {
            s32 k;
            if (m == 15 || m == 16) k = 1;
            else if (m == 2) k = -1;
            else break;
            c = func_0028f930(k);
        } while (0);
        if (m >= 17 && m <= 19) c = c || func_00256ef0();
        s32 ok = c || func_00257970();
        if (ok || func_0027a908(notA) || (m == 15 && func_0028f930(1)) || (m == 2 && func_0028f930(-1))) {
            if (r != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                if (m >= 17 && m <= 19) func_00256ea8();
                func_0027a898(notA);
                if (m == 15 || m == 16) func_0028f7e8(1);
                else if (m == 2) Tz__SelHist__LeaveAll();
            }
        } else {
            func_00287c30();
            func_0028af18(D_0035f01c, 115);
            func_00257708(0);
            if (m == 15) {
                func_0028f7e8(1);
                Tz__CmAbility__SetupTop(-1);
            } else if (m == 16) {
                func_00279040();
                Tz__CmAbility__SetupSel();
            } else if (m >= 17 && m <= 19) {
                func_002788c0();
            } else if (m == 2) {
                func_0027aed8(func_002570a0(15), &a, &b);
                if (a) {
                    b = 0;
                    func_00257050(15, 0, 0);
                    func_00257050(16, 0, 0);
                }
                func_002677f0(2, b);
            }
        }
        return;
    }
    if ((r != -1 || func_00289310(D_0035f01c)) && !func_0027a990()) {
        func_0027aa10();
        func_0028da70(w + 0xb350, 273);
        func_0028fa98(-1);
        func_00256e30();
    }
    if (st == 0 && func_0027a990()) {
        func_0027b6b8();
        func_00287c90(1);
    }
    s32 n = func_0028afa8(D_0035f01c);
    if (func_00242848(func_00287df0(r, func_00289310(D_0035f01c), 1, Tz__CmAbility__SelCheck, 1)) == 0) {
        switch (r) {
        case -4:
            func_00287da0();
            func_00257050(16, func_002891e8(D_0035f01c), func_0028b038(D_0035f01c));
            break;
        case -11:
        case -10:
            func_0027b548(r == -10);
            Tz__CMenuHelp__FadeOut();
            Tz__SelHist__FadeOut(1);
            func_0027a7e0(1);
            func_00287c90(1);
            func_00287c00(16);
            func_00257050(16, 0, 0);
            break;
        case -7:
            a = func_00287bc0();
            func_00287bd0(37, 0);
            func_002831e0(2, a);
            break;
        case -6:
            Tz__CmAbility__ChgEquip();
            func_002799b0();
            Tz__CmAbility__UpdateNew();
            func_0027a208();
            func_0027b248(1);
            func_0027b6b8();
            break;
        case -5:
            Tz__CMenuHelp__FadeOut();
            Tz__SelHist__FadeOut(1);
            Tz__SelHist__FadeOut(0);
            func_00256e80();
            func_0027a7e0(1);
            func_00287c90(1);
            func_00287c00(2);
            func_00257050(16, func_002891e8(D_0035f01c), func_0028b038(D_0035f01c));
            break;
        default: {
            if (r < 0 || r >= n) break;
            a = 17;
            s32 v = Tz__CmAbility__Cur2AbiltyType();
            switch (v) {
            case 0: a = 17; break;
            case 1: a = 18; break;
            case 2: a = 19; break;
            }
            func_0028fb28(2, D_00373e28[v]);
            func_00256e80();
            Tz__CMenuHelp__FadeOut();
            func_0027a7e0(0);
            func_00287c90(1);
            func_00287c00(a);
            func_00257050(16, func_002891e8(D_0035f01c), func_0028b038(D_0035f01c));
            break;
        }
        case -2:
            Tz__CMenuHelp__FadeOut();
            Tz__SelHist__FadeOut(1);
            func_0027a7e0(1);
            func_00287c90(1);
            func_00287c00(15);
            if (!func_00258068(0)) func_00256e80();
            func_00257050(16, func_002891e8(D_0035f01c), func_0028b038(D_0035f01c));
            break;
        case -1:
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n00278318

