// Linked unit 0x0026f0a0-0x002713c8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/menu_sound.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/cmenu_custom.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 0026f0a0 (was src/anon/batch_w1610.cpp)
namespace n0026f0a0 {
struct W1610Ob { u8 pad[408]; s32 id; };
extern s32 D_0035f01c asm("D_0035f01c");
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287c10(void) asm("func_00287c10");
s32 func_00271ec8(void) asm("func_00271ec8");
s32 func_0028f930(s32) asm("func_0028f930");
s32 func_00257970(void) asm("func_00257970");
s32 func_00289310(s32) asm("func_00289310");
void func_00287f90(s32) asm("func_00287f90");
void func_00271e80(void) asm("func_00271e80");
void func_00287c30(void) asm("func_00287c30");
void func_0028f7e8(s32) asm("func_0028f7e8");
void func_002551b8(void) asm("func_002551b8");
void func_0026f388(void) asm("func_0026f388");
s32 func_0028ae28(s32, s32) asm("func_0028ae28");
void func_0028ab20(s32) asm("func_0028ab20");
void func_0028fa98(s32) asm("func_0028fa98");
void func_00272c90(s32) asm("func_00272c90");
void func_00287c90(s32) asm("func_00287c90");
s32 func_0028afa8(s32) asm("func_0028afa8");
void func_00273e88(void) asm("func_00273e88");
s32 func_00287df0(s32, s32, s32, void (*)(void), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
W1610Ob* func_002891b8(s32, s32) asm("func_002891b8");
void func_0028fb68(s32, s32) asm("func_0028fb68");
void func_00263c60(void) asm("func_00263c60");
void func_00271e08(void) asm("func_00271e08");
void func_00287c00(s32) asm("func_00287c00");
s32 func_00257070(s32) asm("func_00257070");
s32 func_002891e8(s32) asm("func_002891e8");
void func_00257050(s32, s32, s32) asm("func_00257050");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
void func_00287da0(void) asm("func_00287da0");
void func_0028f6f0(s32) asm("func_0028f6f0");
/*TARGET 0026f0a0*/
void func_0026f0a0(void) asm("func_0026f0a0");
void func_0026f0a0(void) {
    s32 r = func_00289380(D_0035f01c);
    s32 v;
    s32 st = func_00287cd0();
    if (st == 2) {
        v = func_00287c10();
        if (func_00271ec8() || (v == 0 && func_0028f930(0)) || func_00257970()) {
            if (r != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                func_00271e80();
            }
        } else {
            func_00287c30();
            if (v == 0) {
                func_0028f7e8(0);
                func_002551b8();
            } else if ((u32)(v - 26) < 2) {
                func_0026f388();
            }
        }
        return;
    }
    if ((r != -1 || func_00289310(D_0035f01c)) && func_0028ae28(D_0035f01c, 0) == 0) {
        func_0028ab20(D_0035f01c);
        func_0028fa98(-1);
    }
    if (st == 0 && func_0028ae28(D_0035f01c, 0)) {
        func_00272c90(1);
        func_00287c90(1);
    }
    {
        v = func_0028afa8(D_0035f01c);
        if (func_00242848(func_00287df0(r, func_00289310(D_0035f01c), 1, func_00273e88, 1)) == 0) {
            switch (r) {
            case -2: {
                func_00263c60();
                func_0028f6f0(0);
                func_00271e08();
                func_00287c90(1);
                func_00287c00(0);
                v = func_00257070(25);
                if (func_002891e8(D_0035f01c) != v) func_00257050(26, 0, 0);
                func_00257050(25, func_002891e8(D_0035f01c), 0);
                break;
            }
            default: {
                if (r < 0 || r >= v) break;
                v = 26;
                if (r) v = 27;
                func_0028fb68(1, func_002891b8(D_0035f01c, r)->id);
                func_00263c60();
                func_00271e08();
                func_00287c90(1);
                func_00287c00(v);
                v = func_00257070(25);
                if (func_002891e8(D_0035f01c) != v) func_00257050(26, 0, 0);
                func_00257050(25, func_002891e8(D_0035f01c), 0);
                break;
            }
            case -4: {
                func_00287da0();
                v = func_00257070(25);
                if (func_002891e8(D_0035f01c) != v) func_00257050(26, 0, 0);
                func_00257050(25, func_002891e8(D_0035f01c), 0);
                break;
            }
            case -1:
                break;
            }
        }
    }
    if (func_00288040()) {
        func_00288018();
    }
}
}  // namespace n0026f0a0

// 0026f388 (was src/anon/batch_w3809_nsamam.cpp)
namespace n0026f388 {
struct Node { u8 pad[392]; s32 f392; u8 pad2[40]; void (*cb)(void); };
struct Cfg { u8 pad[4]; s8 count; };
extern u8 D_0035f128 asm("D_0035f128");
extern s8 D_0035f129 asm("D_0035f129");
extern "C" u32 D_0035ef64, D_0035ef68, D_0035ef6c, D_0035f03c;
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u16 D_01e21ec0[2][4] asm("D_01e21ec0");
extern void* D_0035f01c asm("D_0035f01c");
extern void* D_0035f04c asm("D_0035f04c");
extern Cfg* D_0035f12c asm("D_0035f12c");
u8* func_00257770(void) asm("func_00257770");
void func_0028d068(s32, s32) asm("func_0028d068");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028d980(u8*, s32, u32, u32, u32, s32, s32, s32, s32) asm("func_0028d980");
void func_00288d80(void*, s32, u32, u32, u32, s32, u16*, u16*) asm("func_00288d80");
Node* func_002891b8(void*, s32) asm("func_002891b8");
void func_00138c10(void*, u32) asm("func_00138c10");
s32 func_0023aa78(void*) asm("func_0023aa78");
s32 func_0023aa18(void*) asm("func_0023aa18");
s32 func_0023aa38(void*) asm("func_0023aa38");
void func_00288e08(void*, s32, s32, s32) asm("func_00288e08");
void func_00139620(void*) asm("func_00139620");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
s32 func_00257140(s32) asm("func_00257140");
void func_001395f8(void*) asm("func_001395f8");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
void func_00272f48(void) asm("func_00272f48");
s32 func_00257070(s32) asm("func_00257070");
s32 func_00257088(s32) asm("func_00257088");
void* func_0023f1b0(u32) asm("func_0023f1b0");
s32 func_0023c4b8(void*, u32) asm("func_0023c4b8");
s32 func_00236ca8(u32, u32) asm("func_00236ca8");
s32 func_002570f0(void) asm("func_002570f0");
void func_0028bae0(void*, s32, s32, s32, s32, s32, s32, u8*, s32) asm("func_0028bae0");
void func_0028af90(void*, s32) asm("func_0028af90");
s32 func_002892f8(void*) asm("func_002892f8");
void func_002891f0(void*, s32, s32, s32, s32) asm("func_002891f0");
void func_0028afd0(void*, s32) asm("func_0028afd0");
void func_0028b218(void*, s32) asm("func_0028b218");
void func_0028b248(void*, s32) asm("func_0028b248");
s32 func_0028b040(void*) asm("func_0028b040");
s32 func_00272b60(s32) asm("func_00272b60");
void func_0028af40(void*, s32) asm("func_0028af40");
u32 func_0028af88(void*) asm("func_0028af88");
void func_0028af18(void*, u32) asm("func_0028af18");
void func_002713c8(void) asm("func_002713c8");
void func_00272ae0(void) asm("func_00272ae0");
void func_00271ee8(void) asm("func_00271ee8");
s32 func_00283ab8(s32) asm("func_00283ab8");
void func_00256cc0(s32, s32, s32) asm("func_00256cc0");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 0026f388*/
void func_0026f388(void) asm("func_0026f388");
void func_0026f388(void) {
    s32 id;
    s32 h;
    u8* w = func_00257770();
    s32 i, j;
    D_0035f128 = 0;
    D_0035f129 = -1;
    func_0028d068(30021, 0);
    for (i = 0; i < 2; i++)
        for (j = 0; j < 4; j++) D_01e21ec0[i][j] = D_0035ef6c;
    func_0028f4d8(1, -1, 0);
    u32 va = D_0035ef68;
    u32 vb = D_0035ef64;
    u32 vc = D_0035f03c;
    id = D_0035f3d4;
    func_0028d8c0(w, id++, va, vb, vc, 227, 228, 0);
    u8* box = w + 34768;
    s32 id1 = id + 1;
    s32 id2 = id + 2;
    u8* lab = w + 24304;
    for (i = 0; i < 9;) {
        u32 lb = D_0035ef64;
        asm("" : "+r"(lb));
        func_00288d80(D_0035f01c, i, D_0035ef68, lb, D_0035f03c, -1, D_01e21ec0[0], D_01e21ec0[1]);
        Node* n = func_002891b8(D_0035f01c, i);
        func_00138c10(n, 264);
        h = func_0023aa78((u8*)n + 24);
        asm("" : "+r"(h));
        s32 x = func_0023aa18((u8*)n + 24);
        s32 y = func_0023aa38((u8*)n + 24);
        func_00288e08(D_0035f01c, i, 0, h);
        i++;
        func_00139620(n);
        func_00138c10(n, D_0035ef6c);
        n->f392 = -1;
        n->cb = func_00272f48;
        func_0028dcc0(n, w);
        func_0028d980(lab, id1, D_0035ef68, D_0035ef64, D_0035f03c, func_00257140(0), -1, -1, 0);
        func_0028dcc0(lab, n);
        func_00139620(lab);
        func_001395f8(lab);
        lab += 436;
        { u32 c3c = D_0035f03c; u32 c64 = D_0035ef64; asm volatile(""); u32 c6c = D_0035ef6c;
u8* ra0; asm volatile("move %0,%1" : "=r"(ra0) : "r"(box));
        func_0028d8c0(ra0, id2, D_0035ef68, c64, c3c, c6c, -1, 0);
        }
        func_0028dcc0(box, n);
        func_00138c68(box, x, y);
        box += 408;
    }
    u8* p = w;
    register s32 ph asm("$19"); asm("" : "=r"(ph));
    for (i = 0; i < 9;) {
        u8* e = p + 3376;
        func_0028d980(e, id, D_0035ef68, D_0035ef64, D_0035f03c, 282, -1, -1, 0);
        func_00138c68(e, 0, func_0023aa78(p + 3400) * i);
        func_00138c10(e, D_0035ef6c);
        func_001395f8(e);
        func_0028dcc0(e, w);
        *(s32*)(p + 3808) = 2;
        i++;
        p += 436;
    }
    s32 cnt = D_0035f12c->count;
    if (func_00257070(25)) cnt++;
    s32 a = func_0023c4b8(func_0023f1b0(D_0035f03c), D_0035ef68);
    s32 b = func_00236ca8(*(u32*)((u8*)func_0023f1b0(D_0035f03c) + 40), D_0035ef64);
    s32 vis = cnt < 10 ? cnt : 9;
    func_0028bae0(D_0035f04c, id, a, b, func_002570f0(), cnt, vis, w, 0);
    func_0028af90(D_0035f01c, cnt);
    s32 cur = func_00257070(26);
    s32 top = func_00257088(26);
    s32 rows = func_002892f8(D_0035f01c);
    s32 abs = cur + top;
        asm("" :: "r"(ph));
    if (abs >= cnt || cnt < top + rows) {
        while (top > 0) {
            if (cnt >= top + rows) break;
            top--;
        }
        cur = abs - top;
        if (cur < 0) cur = 0;
        if (cur >= rows) cur = rows - 1;
        if (cur + top >= cnt) {
            top = 0;
            cur = 0;
        }
    }
    func_002891f0(D_0035f01c, cur, 0, -1, -1);
    func_0028afd0(D_0035f01c, top);
    func_0028b218(D_0035f01c, 1);
    func_0028b248(D_0035f01c, 9);
    s32 k = func_00272b60(func_0028b040(D_0035f01c));
    if (k) func_0028af40(D_0035f01c, 512);
    h = -1;
    { register u32 f asm("$2") = func_0028af88(D_0035f01c) | 0xc000; asm("" : "+r"(f)); func_0028af18(D_0035f01c, f); }
    func_002713c8();
    func_00272ae0();
    func_00271ee8();
    if ((k == 2 && func_00283ab8(0)) || (k == 1 && func_00283ab8(1))) {
        h = 0xcbdd;
        { register u32 f asm("$2") = func_0028af88(D_0035f01c) | 0x400; asm("" : "+r"(f)); func_0028af18(D_0035f01c, f); }
    }
    func_00256cc0(0xb61a, h, -1);
    func_00287cc0(0);
}
}  // namespace n0026f388

// 0026f920 (was src/anon/batch_w1711.cpp)
namespace n0026f920 {
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f010 asm("D_0035f010");
extern s8 D_0035f129 asm("D_0035f129");
extern u16 D_00373a18[] asm("D_00373a18");
extern u16 D_00373a28[] asm("D_00373a28");
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287c10(void) asm("func_00287c10");
s32 func_0028f930(s32) asm("func_0028f930");
s32 func_00256ef0(void) asm("func_00256ef0");
s32 func_00272428(void) asm("func_00272428");
s32 func_00257970(void) asm("func_00257970");
s32 func_00289310(s32) asm("func_00289310");
void func_00287f90(s32) asm("func_00287f90");
void func_002723e0(void) asm("func_002723e0");
void func_00256ea8(void) asm("func_00256ea8");
void func_00287c30(void) asm("func_00287c30");
void func_0028af18(s32, s32) asm("func_0028af18");
void func_0028f7e8(s32) asm("func_0028f7e8");
void func_0026ee78(void) asm("func_0026ee78");
void func_00257050(s32, s32, s32) asm("func_00257050");
s32 func_00281140(s32, s32) asm("func_00281140");
void func_0028fb68(s32, s32) asm("func_0028fb68");
s32 func_00257070(s32) asm("func_00257070");
void func_00271b58(s32) asm("func_00271b58");
void func_0026f388(void) asm("func_0026f388");
void func_002700f0(void) asm("func_002700f0");
s32 func_00272538(void) asm("func_00272538");
void func_00272468(void) asm("func_00272468");
void func_0028fa98(s32) asm("func_0028fa98");
void func_00256e30(void) asm("func_00256e30");
void func_00272c90(s32) asm("func_00272c90");
void func_00287c90(s32) asm("func_00287c90");
s32 func_0028afa8(s32) asm("func_0028afa8");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00287da0(void) asm("func_00287da0");
s32 func_002891e8(s32) asm("func_002891e8");
s32 func_0028b038(s32) asm("func_0028b038");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
s8 func_00273de0(s32, s32) asm("func_00273de0");
void func_00263c60(void) asm("func_00263c60");
void func_00256e80(void) asm("func_00256e80");
void func_0028f6f0(s32) asm("func_0028f6f0");
void func_00272340(void) asm("func_00272340");
void func_00287c00(s32) asm("func_00287c00");
s32 func_0028b040(s32) asm("func_0028b040");
s32 func_00272b60(s32) asm("func_00272b60");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_002831e0(s32, s32) asm("func_002831e0");
void func_002713c8(void) asm("func_002713c8");
void func_002736f8(void) asm("func_002736f8");
void func_00273cb8(s32) asm("func_00273cb8");
void func_00273c40(s32) asm("func_00273c40");
s32 func_00273b30(void) asm("func_00273b30");
void func_0026ff30(void) asm("func_0026ff30");
void func_00273818(void) asm("func_00273818");
void func_0028fb28(s32, s32) asm("func_0028fb28");
void func_00273e88(void) asm("func_00273e88");
/*TARGET 0026f920*/
void func_0026f920(void) asm("func_0026f920");
void func_0026f920(void)
{
    s32 flag = 0;
    s32 sel = func_00289380(D_0035f01c);
    s32 st = func_00287cd0();
    if (st == 2) {
        s32 next = func_00287c10();
        if (next >= 25 && next <= 27) flag = func_0028f930(1);
        if (next != 26 && next != 27) flag = flag || func_00256ef0();
        if (func_00272428() || flag || func_00257970()) {
            if (sel != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                func_002723e0();
                if (next != 26 && next != 27) func_00256ea8();
            }
            return;
        }
        func_00287c30();
        func_0028af18(D_0035f01c, 0x73);
        if (next == 25) {
            func_0028f7e8(1);
            func_0026ee78();
            return;
        }
        if (next == 26 || next == 27) {
            func_00257050(25, D_0035f129, 0);
            func_0028fb68(1, func_00281140(D_0035f010, D_0035f129));
            D_0035f129 = -1;
            func_00271b58(func_00257070(25));
            func_0026f388();
            return;
        }
        func_002700f0();
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f01c)) && !func_00272538()) {
        func_00272468();
        func_0028fa98(-1);
        func_00256e30();
    }
    if (st == 0 && func_00272538()) {
        func_00272c90(1);
        func_00287c90(1);
    }
    s32 type;
    s32 n = func_0028afa8(D_0035f01c);
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f01c), 1, (s32)func_00273e88, 1)) == 0) {
        switch (sel) {
        case -1:
            break;
        case -4: {
            func_00287da0();
            s32 cur = func_002891e8(D_0035f01c);
            func_00257050(26, cur, func_0028b038(D_0035f01c));
            break;
        }
        case -11:
        case -10:
            D_0035f129 = func_00273de0(sel == -10, 0);
            func_00263c60();
            func_00256e80();
            func_0028f6f0(1);
            func_00272340();
            func_00287c90(1);
            func_00287c00(D_0035f129 == 0 ? 26 : 27);
            func_00257050(26, 0, 0);
            break;
        case -7: {
            type = func_00272b60(func_0028b040(D_0035f01c));
            n = func_00287bc0();
            func_00287bd0(37, 0);
            if (type == 2) func_002831e0(0, n);
            else if (type == 1) func_002831e0(1, n);
            break;
        }
        case -6:
            switch (func_00272b60(func_0028b040(D_0035f01c))) {
            case 1:
                func_002736f8();
                break;
            case 2:
                if (func_00273b30()) {
                    func_0026ff30();
                    func_00287bd0(28, 0);
                } else {
                    func_00273818();
                }
                break;
            case 3:
                func_00273c40(-1);
                break;
            case 4:
                func_00273cb8(-1);
                break;
            }
            func_002713c8();
            func_00272c90(0);
            break;
        case -2: {
            func_00263c60();
            func_00256e80();
            func_0028f6f0(1);
            func_00272340();
            func_00287c90(1);
            func_00287c00(25);
            s32 cur = func_002891e8(D_0035f01c);
            func_00257050(26, cur, func_0028b038(D_0035f01c));
            break;
        }
        default:
            if (sel >= 0 && sel < n) {
                s32 id = -1;
                type = func_00272b60(sel);
                switch (type) {
                case 0: id = 29; break;
                case 1: id = 30; break;
                case 2: id = 31; break;
                case 3: id = 32; break;
                case 4: id = 33; break;
                }
                if (type == 0) func_0028fb28(2, D_00373a28[sel]);
                else func_0028fb28(2, D_00373a18[type]);
                func_00256e80();
                func_00263c60();
                func_00272340();
                func_00287c90(1);
                func_00287c00(id);
                id = func_00257070(25);
                if (func_002891e8(D_0035f01c) != id) func_00257050(26, 0, 0);
                s32 cur = func_002891e8(D_0035f01c);
                func_00257050(26, cur, func_0028b038(D_0035f01c));
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0026f920

// 0026ff30 (was src/anon/batch_w1736.cpp)
namespace n0026ff30 {
// 0x001c0410: definition moved into src/anon/unit_001bff88.cpp

/* 0026ff30 */
s32 w1736_GetMode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
void w1736_SetState(s32) asm("_ZN2Tz8Selector8SetStateEi");
void func_00257388(s32, s32) asm("func_00257388");
void func_002571e0(s32) asm("func_002571e0");
struct w1736_B { u8 b; };
extern w1736_B D_0035f128 asm("D_0035f128");
extern w1736_B D_0035f130 asm("D_0035f130");
/*TARGET 0026ff30*/
void func_0026ff30(void) asm("func_0026ff30");
void func_0026ff30(void) {
    D_0035f130.b = w1736_GetMode();
    D_0035f128.b = 0;
    func_00257388(0x846a, 0);
    func_002571e0(1);
    w1736_SetState(0);
}
}  // namespace n0026ff30

// 0026ff78 (was src/anon/batch_w1582_g.cpp)
namespace n0026ff78 {
s32 func_00287bc0(void) asm("func_00287bc0");
// 0x0026a060: definition moved into src/anon/unit_00269a60.cpp
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_002576d0(void) asm("func_002576d0");
void func_002575a8(void) asm("func_002575a8");
void func_00287c30(void) asm("func_00287c30");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00257610(s32) asm("func_00257610");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00289380(u32) asm("func_00289380");
s32 func_00289310(u32) asm("func_00289310");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00273818(void) asm("func_00273818");
void func_00271ee8(void) asm("func_00271ee8");
void func_00257530(s32) asm("func_00257530");
void func_00287c00(s32) asm("func_00287c00");
extern u32 D_0035f024 asm("D_0035f024");
extern u8 D_0035f128 asm("D_0035f128");
extern u8 D_0035f130 asm("D_0035f130");
/*TARGET 0026ff78*/
void func_0026ff78(void) asm("func_0026ff78");
void func_0026ff78(void) {
    s32 m = func_00287cd0();
    func_00287bc0();
    if (m == 2) {
        if (!func_002576d0()) {
            func_002575a8();
            func_00287c30();
            func_00287cc0(1);
        }
        return;
    }
    if (m == 0) {
        if (func_00257610(0)) func_00287c90(1);
    }
    if (m == 1) {
        s32 r = func_00289380(D_0035f024);
        if (func_00242848(func_00287df0(r, func_00289310(D_0035f024), 0, 0, 1))) return;
        switch (r) {
        case -4:
        case -3:
        case -1:
            break;
        case 1:
            if (D_0035f130 == 26 || D_0035f130 == 27) {
                func_00273818();
                func_00271ee8();
            }
            D_0035f128 = 1;
        case -2:
        case 0:
            func_00257530(0);
            func_00287cc0(2);
            func_00287c00((s8)D_0035f130);
            break;
        }
    }
}
}  // namespace n0026ff78

// 002700f0 (was src/anon/batch_w3824_mam.cpp)
namespace n002700f0 {
u8* func_00257770(void) asm("func_00257770");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_002570a0(s32) asm("func_002570a0");
s32 func_00272b60(s32) asm("func_00272b60");
void func_00282240(s32, s32, s32) asm("func_00282240");
void func_00282620(s32) asm("func_00282620");
void func_00282cb8(s32, s32) asm("func_00282cb8");
void func_00282d70(s32) asm("func_00282d70");
s32 func_00281f18(s32) asm("func_00281f18");
void func_00282940(s32, s32, s32) asm("func_00282940");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void func_00139620(u8*) asm("func_00139620");
void func_001395f8(u8*) asm("func_001395f8");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
s32 func_00257158(s32, s32, s32) asm("func_00257158");
s32 func_00257140(s32) asm("func_00257140");
void func_00288d80(s32, s32, s32, s32, s32, s32, u16*, u16*) asm("func_00288d80");
u8* func_002891b8(s32, s32) asm("func_002891b8");
s32 func_0023aa78(u8*) asm("func_0023aa78");
void func_00288e08(s32, s32, s32, s32) asm("func_00288e08");
void func_00273078(void) asm("func_00273078");
u8* func_0023f1b0(s32) asm("func_0023f1b0");
s32 func_0023c4b8(u8*, s32) asm("func_0023c4b8");
s32 func_00236ca8(s32, s32) asm("func_00236ca8");
s32 func_002570f0(void) asm("func_002570f0");
void func_0028bae0(s32, s32, s32, s32, s32, s32, s32, u8*, s32) asm("func_0028bae0");
void func_0028b218(s32, s32) asm("func_0028b218");
void func_0028b248(s32, s32) asm("func_0028b248");
void func_0028af90(s32, s32) asm("func_0028af90");
void func_00270648(void) asm("func_00270648");
s32 func_00283ab8(s32) asm("func_00283ab8");
s32 func_0028af88(s32) asm("func_0028af88");
void func_0028af18(s32, s32) asm("func_0028af18");
void func_00256cc0(s32, s32, s32) asm("func_00256cc0");
void func_00287cc0(s32) asm("func_00287cc0");
void func_002725d8(void) asm("func_002725d8");
extern u8 D_0035f128 asm("D_0035f128");
extern u16 D_00373a60[] asm("D_00373a60");
extern u16 D_01e21ec0[2][4] asm("D_01e21ec0");
extern s16 D_00373a30[][3] asm("D_00373a30");
extern s16 D_00373a50[] asm("D_00373a50");
extern u8* D_0035f12c asm("D_0035f12c");
extern s32 D_0035f014 asm("D_0035f014");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035ef68 asm("D_0035ef68");
extern s32 D_0035ef64 asm("D_0035ef64");
extern s32 D_0035f03c asm("D_0035f03c");
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f04c asm("D_0035f04c");
/*TARGET 002700f0*/
/* Sets up the level menu: header objects, then up to 8 entries (436-byte
   objects at base+24740), then the list control. */
void func_002700f0(void) asm("func_002700f0");
/* Sets up the level menu: header objects, then up to 8 entries (436-byte
   objects at base+24740), then the list control. */
void func_002700f0(void) {
    s32 id, t, cnt, k, mode, id1, big;
    u8* m;
    s32 i, j, n, r;
    u8* a;
    u8* b;
    u8* o;
    u8* q;
    i = 0;
    m = func_00257770();
    D_0035f128 = 0;
    mode = func_00287bc0();
    k = func_002570a0(26);
    t = func_00272b60(k);
    for (; i < 2; i++) {
        for (j = 0; j < 4; j++) D_01e21ec0[i][j] = D_00373a60[t];
    }
    if (t == 0) {
        func_00282240(D_0035f014, 0, 10);
        func_00282620(D_0035f014);
        func_00282cb8(D_0035f014, -1);
        func_00282d70(D_0035f014);
        cnt = func_00281f18(D_0035f014);
        func_00282940(D_0035f014, 0, cnt++);
    } else if (t == 1) {
        cnt = 2;
    } else if (t == 2) {
        cnt = 2;
        if (func_002570a0(25)) cnt = 4;
    } else {
        cnt = 6;
        if (t != 3) cnt = 3;
    }
    func_0028f4d8(2, -1, 0);
    big = cnt < 9;
    a = m + 1632;
    b = m + 24304;
    n = 8;
    id = D_0035f3d4;
    func_0028d8c0(m, id, D_0035ef68, D_0035ef64, D_0035f03c, D_00373a30[t][0], D_00373a30[t][2], 0);
    id++;
    id1 = id + 1;
    func_0028d980(a, id, D_0035ef68, D_0035ef64, D_0035f03c, D_00373a50[t], -1, -1, 0);
    func_00139620(a);
    func_0028dcc0(a, m);
    if (big) n = cnt;
    r = func_00257140(func_00257158(*(s16*)(D_0035f12c + k * 8 + 8), 1, t == 1));
    func_0028d980(b, id1, D_0035ef68, D_0035ef64, D_0035f03c, r, -1, -1, 0);
    *(u8**)(b + 408) = m + k * 32 + 0xae10;
    func_0028dcc0(b, a);
    func_00139620(b);
    func_001395f8(b);
    r = func_00257140(0);
    for (i = 0; i < n; i++) {
        q = m + 24740 + i * 436;
        func_00288d80(D_0035f01c, i, D_0035ef68, D_0035ef64, D_0035f03c, -1, D_01e21ec0[0], D_01e21ec0[1]);
        o = func_002891b8(D_0035f01c, i);
        func_00288e08(D_0035f01c, i, 0, func_0023aa78(o + 24));
        func_00139620(o);
        if (mode == 31 && func_002570a0(25)) {
            *(void (**)(void))(func_002891b8(D_0035f01c, i) + 436) = func_00273078;
        }
        func_0028dcc0(o, m);
        func_0028d980(q, id1, D_0035ef68, D_0035ef64, D_0035f03c, r, -1, -1, 0);
        func_0028dcc0(q, o);
        func_00139620(q);
        func_001395f8(q);
    }
    big = cnt < 9;
    n = 8; if (big) n = cnt;
    func_0028bae0(D_0035f04c, id, func_0023c4b8(func_0023f1b0(D_0035f03c), D_0035ef68),
                  func_00236ca8(*(s32*)(func_0023f1b0(D_0035f03c) + 40), D_0035ef64),
                  func_002570f0(), cnt, n, m, 0);
    func_0028b218(D_0035f01c, 1);
    func_0028b248(D_0035f01c, n);
    if (!big) func_0028af90(D_0035f01c, cnt);
    func_00270648();
    if ((t == 2 && func_00283ab8(0)) || (t == 1 && func_00283ab8(1))) {
        func_0028af18(D_0035f01c, func_0028af88(D_0035f01c) | 0x400);
        func_00256cc0(0xcbdd, -1, -1);
    }
    func_00287cc0(0);
    func_002725d8();
}
}  // namespace n002700f0

// 00270648 (was src/anon/batch_w1607.cpp)
namespace n00270648 {
struct E270 { s16 id; s8 a; s8 b; u8 pad[4]; };
struct T270 { u8 pad[3]; s8 h3; u8 pad2[4]; E270 e[1]; };
struct L270 { u16 id; u16 pad[2]; };
struct R270 { u8 pad[5]; u8 f5; };
extern s32 D_0035f01c asm("D_0035f01c");
extern T270* D_0035f12c asm("D_0035f12c");
extern s32 D_0035f014 asm("D_0035f014");
extern s32 D_0035f04c asm("D_0035f04c");
s32 func_002570a0(s32) asm("func_002570a0");
u32 func_00272b60(s32) asm("func_00272b60");
s32 func_00281f18(s32) asm("func_00281f18");
L270* func_00281f20(s32) asm("func_00281f20");
R270* func_00273180(s32, s32) asm("func_00273180");
void func_002891f0(s32, s32, s32, s32, s32) asm("func_002891f0");
void func_0028afd0(s32, s32) asm("func_0028afd0");
void func_0028be78(s32, s32) asm("func_0028be78");
/*TARGET 00270648*/
void func_00270648(void) asm("func_00270648");
void func_00270648(void) {
    s32 max = 0;
    s32 cur = 0;
    s32 top = 0;
    s32 idx = func_002570a0(26);
    s32 i;
    switch (func_00272b60(idx)) {
    case 0: {
        s32 n = func_00281f18(D_0035f014);
        s16 id = D_0035f12c->e[idx].id;
        if (id == 0) {
            cur = 0;
        } else {
            L270* l = func_00281f20(D_0035f014);
            for (i = 0; i < n; i++) {
                if (l[i].id == id) {
                    cur = i + 1;
                    break;
                }
            }
        }
        max = n + 1;
        break;
    }
    case 1:
        max = 2;
        cur = D_0035f12c->e[idx].a != 0;
        break;
    case 2:
        max = 2;
        if (func_002570a0(25)) {
            idx--;
            max = 4;
        }
        cur = D_0035f12c->e[idx].a != 0;
        if (func_002570a0(25) && D_0035f12c->e[idx].b == 2) cur += 2;
        break;
    case 3:
        max = 6;
        for (i = 0; i < 6; i++) {
            if (D_0035f12c->h3 == func_00273180(3, i)->f5) {
                cur = i;
                break;
            }
        }
        break;
    case 4:
        max = 3;
        if (func_002570a0(25)) idx--;
        for (i = 0; i < 3; i++) {
            if (D_0035f12c->e[idx].b == func_00273180(4, i)->f5) {
                cur = i;
                break;
            }
        }
        break;
    }
    if (cur >= 8) {
        top = cur - 7;
        cur = 7;
    }
    if (top + cur >= max) {
        top = cur - max + 1;
        cur = max - 1;
    }
    func_002891f0(D_0035f01c, cur, 0, -1, -1);
    func_0028afd0(D_0035f01c, top);
    func_0028be78(D_0035f04c, top);
}
}  // namespace n00270648

// 002708c0 (was src/anon/batch_w3682.cpp)
namespace n002708c0 {
s32 func_00242848(s32) asm("func_00242848");
s32 func_00256e80(void) asm("func_00256e80");
s32 func_00256ef0(void) asm("func_00256ef0");
s32 func_002570a0(s32) asm("func_002570a0");
void func_00263c60(void) asm("func_00263c60");
void func_0026f388(void) asm("func_0026f388");
void func_0026ff30(void) asm("func_0026ff30");
void func_00270c70(s32) asm("func_00270c70");
void func_00272340(void) asm("func_00272340");
void func_002723e0(void) asm("func_002723e0");
s32 func_00272428(void) asm("func_00272428");
void func_00272468(void) asm("func_00272468");
s32 func_00272538(void) asm("func_00272538");
s32 func_00272b60(s32) asm("func_00272b60");
void func_00272c90(s32) asm("func_00272c90");
void func_00273530(void) asm("func_00273530");
s32 func_00273818(void) asm("func_00273818");
s32 func_00273b30(void) asm("func_00273b30");
void func_002831e0(s32, s32) asm("func_002831e0");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287c00(s32) asm("func_00287c00");
void func_00287c30(void) asm("func_00287c30");
void func_00287c90(s32) asm("func_00287c90");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00287cd0(void) asm("func_00287cd0");
void func_00287da0(void) asm("func_00287da0");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_00287f90(s32) asm("func_00287f90");
void func_00288018(void) asm("func_00288018");
s32 func_00288040(void) asm("func_00288040");
s32 func_00289310(s32) asm("func_00289310");
s32 func_00289380(s32) asm("func_00289380");
s32 func_0028afa8(s32) asm("func_0028afa8");
void func_0028f6f0(s32) asm("func_0028f6f0");
void func_0028f7e8(s32) asm("func_0028f7e8");
s32 func_0028f930(s32) asm("func_0028f930");
void func_0028fa98(s32) asm("func_0028fa98");
void func_00273e88(void) asm("func_00273e88");
extern s32 D_0035f01c asm("D_0035f01c");
extern s8 D_0035f128 asm("D_0035f128");
extern s8* D_0035f12c asm("D_0035f12c");
/*TARGET 002708c0*/
void func_002708c0(void) asm("func_002708c0");
void func_002708c0(void)
{
    s32 sel = func_00289380(D_0035f01c);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00272428() || func_0028f930(2) || func_00256ef0()) {
            if (sel != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                func_002723e0();
            }
            return;
        }
        if (D_0035f128) {
            func_00273818();
            func_00270c70(func_002570a0(25));
            D_0035f128 = 0;
        }
        func_00287c30();
        func_0028f7e8(2);
        func_0026f388();
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f01c)) && !func_00272538()) {
        func_00272468();
        func_0028fa98(-1);
    }
    if (st == 0 && func_00272538()) {
        func_00272c90(1);
        func_00287c90(1);
    }
    s32 n = func_0028afa8(D_0035f01c);
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f01c), 1, (s32)func_00273e88, 1)) == 0) {
        s32 off;
        if (D_0035f128) sel = -2;
        switch (sel) {
        case -1: break;
        case -7: {
            s32 r = func_00272b60(func_002570a0(26));
            n = func_00287bc0();
            func_00287bd0(37, 0);
            if (r == 2) func_002831e0(0, n);
            else if (r == 1) func_002831e0(1, n);
            break;
        }
        case -2:
            func_00263c60();
            func_0028f6f0(2);
            func_00256e80();
            goto C;
        case -4:
            func_00287da0();
            break;
        default:
            if (sel >= 0 && sel < n) {
                n = func_002570a0(26);
                if (func_00272b60(n) == 2) {
                    if (func_002570a0(25)) n--;
                    off = n * 8;
                    n = *(s8*)(off + (s32)D_0035f12c + 10) != 0;
                    if (func_002570a0(25)) {
                        if (*(s8*)(off + (s32)D_0035f12c + 11) == 2) n += 2;
                    }
                    if (n == sel) goto B;
                    if (func_00273b30()) {
                        func_0026ff30();
                        func_00287bd0(28, 0);
                        break;
                    }
                }
                func_00273530();
            B:
                func_00263c60();
                func_00256e80();
                func_0028f6f0(2);
            C:
                func_00272340();
                func_00287cc0(2);
                {
                    s32 r = func_002570a0(25);
                    s32 v = 26;
                    if (r) v = 27;
                    func_00287c00(v);
                }
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n002708c0

// .rodata 0x37394c-0x373958
extern const u32 R_0037394c[3] asm("D_0037394c") __attribute__((aligned(4))) = { 0xffff, 0x80000000, 0x50 };

// 00270c70 (was src/anon/batch_w3839_nsa.cpp)
namespace n00270c70 {
struct W1712Entry {
    s16 id;
    s8 flag;
    u8 level;
    u8 pad[4];
};
struct W1712List {
    s8 numDrive;
    s8 numParty;
    s8 numSummon;
    u8 b3;
    s8 total;
    u8 pad[3];
    W1712Entry e[18];
};
struct W1712Sheet {
    u8 pad0[0x12];
    u8 count;
    u8 pad13[0x34 - 0x13];
    u16 a34[8];
    u16 a44[8];
    struct { u16 id : 15; u16 on : 1; } a54[80];
    u8 xf4;
    u8 xf5[1];
};
struct W1712Item {
    u16 id;
    u8 type;
};
struct W1712Rec {
    u8 pad[6];
    u8 kind;
};
void func_002713a0(s32, s8**, s32*) asm("func_002713a0");
s16 func_00271870(u16) asm("func_00271870");
s32 func_001a36f8(s32) asm("func_001a36f8");
W1712Rec* func_001a80c8(s32) asm("func_001a80c8");
s32 func_001145b0(s16, s32) asm("func_001145b0");
u8* W1712_getSaveRam(void) asm("_Z10getSaveRamv");
void W1712_memset(void*, s32, u32) asm("_Z16wtarget_002fde18jjjj");
u8* W1712_GetSheet(void*, s32) asm("_ZN2Tz9PartyInfo8GetSheetEi");
s32 W1712_HasAnsemEntry(u32) asm("_ZN2Tz6JmInfo13HasAnsemEntryEj");
W1712Item* W1712_ItemEach(W1712Item*) asm("_ZN2YS10ITEM_TABLE4EachEPKS0_");
u8 W1712_GetMpDriveStatus(s32) asm("_ZN2YS5MAGIC16GetMpDriveStatusEi");
extern void* D_0035f010 asm("D_0035f010");
extern W1712List* D_0035f12c asm("D_0035f12c");
void W1712_func(s32 arg0) asm("_Z17ctarget0_00270c70v");
/*TARGET 00270c70*/
void W1712_func(s32 arg0) asm("_Z17ctarget0_00270c70v");
void W1712_func(s32 arg0)
{
    s32 buf[80];
    s8* list;
    s32 num;
    W1712Sheet* sheet;
    W1712Item* item = 0;
    s32 n = 0;
    s32 k;
    s32 i;
    s32 j;
    s32 cnt;
    u32 id;
    s32 x;

    func_002713a0(arg0, &list, &num);
    W1712_memset(D_0035f12c, 0, sizeof(W1712List));
    sheet = *(W1712Sheet**)(W1712_GetSheet(D_0035f010, arg0) + 0x244);
    for (k = 0; k < num; k++) {
        switch (list[k]) {
        case 0:
            for (i = 0; i < 4; i++) {
                u16 v = ((u16*)(W1712_getSaveRam() + 0x36f8))[i];
                D_0035f12c->e[n++].id = func_00271870(v);
            }
            break;
        case 1: {
            s32 mask = 0;
            for (i = 0; i < 6; i++) {
                buf[i] = func_001a36f8(i);
            }
            while ((item = W1712_ItemEach(item)) != 0) {
                if (item->type == 0x12 && W1712_HasAnsemEntry(item->id) > 0) {
                    for (i = 0; i < 6; i++) {
                        if (buf[i] == item->id) {
                            mask |= 1 << i;
                            break;
                        }
                    }
                }
            }
            cnt = 0;
            for (i = 0; i < 6; i++) {
                if ((u8)((mask >> i) & 1)) {
                    cnt++;
                    D_0035f12c->e[n].id = buf[i];
                    D_0035f12c->e[n++].flag = W1712_GetMpDriveStatus(i);
                }
            }
            D_0035f12c->numDrive = cnt;
            break;
        }
        case 2:
            cnt = 0;
            W1712_memset(buf, 0, sizeof(buf));
            for (i = 0; i < sheet->count; i++) {
                id = sheet->a34[i];
                if (id == 0) {
                    id = sheet->a44[i];
                    if (id == 0) {
                        continue;
                    }
                }
                for (j = 0; j < cnt; j++) {
                    if ((u16)buf[j] == id) {
                        break;
                    }
                }
                if (j < cnt) {
                    continue;
                }
                if (sheet->a44[i] == id) {
                    id |= 0x80000000;
                }
                buf[cnt++] = id;
            }
            for (i = 0; i < cnt; i++) {
                D_0035f12c->e[n].id = buf[i];
                if (arg0 != 0) {
                    u8 lv = sheet->xf5[func_001145b0(D_0035f12c->e[n].id, arg0)];
                    D_0035f12c->e[n].level = lv;
                }
                if (buf[i] & 0x80000000) {
                    D_0035f12c->e[n].flag = 1;
                }
                n++;
            }
            D_0035f12c->numParty = cnt;
            break;
        case 3:
            D_0035f12c->b3 = sheet->xf4;
            break;
        case 4: {
            s32 idx;
            cnt = 0;
            W1712_memset(buf, 0, sizeof(buf));
            for (i = 0; i < 80; i++) {
                id = sheet->a54[i].id;
                if (id != 0 && sheet->a54[i].on && func_001a80c8(id)->kind == 2) {
                    buf[cnt++] = id;
                }
            }
            for (i = 0; i < cnt; i++) {
                D_0035f12c->e[n].id = buf[i];
                D_0035f12c->e[n].flag = 1;
                if (arg0 != 0) {
                    u8 lv = sheet->xf5[func_001145b0(D_0035f12c->e[n].id, arg0)];
                    D_0035f12c->e[n].level = lv;
                }
                n++;
            }
            item = 0;
            W1712_memset(buf, 0, sizeof(buf));
            idx = 0;
            for (;;) {
                item = W1712_ItemEach(item);
                if (item == 0) break;
                if (item->type == 0x13) {
                    for (i = 0; i < cnt; i++) {
                        if (D_0035f12c->e[i].id == item->id) {
                            buf[i] = idx;
                        }
                    }
                }
                idx++;
            }
            for (i = 0; i < cnt; i++) {
                for (j = i + 1; j < cnt; j++) {
                    if (buf[i] > buf[j]) {
                        W1712Entry t = D_0035f12c->e[i];
                        D_0035f12c->e[i] = D_0035f12c->e[j];
                        D_0035f12c->e[j] = t;
                        register s32 x asm("$4") = buf[i]; // pin: orig keeps the swap temp in a0
                        buf[i] = buf[j];
                        buf[j] = x;
                    }
                }
            }
            D_0035f12c->numSummon = cnt;
            break;
        }
        }
    }
    D_0035f12c->total = n;
    if (list[0] == 0) {
        for (k = 0; k < 4; k++) {
            if (D_0035f12c->e[k].id != 0) {
                for (i = 4; i < D_0035f12c->total; i++) {
                    if (D_0035f12c->e[k].id == D_0035f12c->e[i].id) {
                        D_0035f12c->e[k].flag = D_0035f12c->e[i].flag;
                    }
                }
            }
        }
    }
}
}  // namespace n00270c70

// 002712d8 (gap, written for the unit)
namespace n002712d8 {
extern u32 D_0035f010 asm("D_0035f010");
u8* func_001a80c8(s32) asm("func_001a80c8");
s32 func_001a3570(s32) asm("func_001a3570");
u8* func_00281180(u32, s32) asm("func_00281180");
void func_002712d8(s32 who, s32 id, s32* num, s32* val) asm("func_002712d8");
void func_002712d8(s32 who, s32 id, s32* num, s32* val) {
    if (id == 0) {
        *num = 0;
        *val = 0;
        return;
    }
    u8* it = func_001a80c8(id);
    *val = func_001a3570(id);
    if (it[2]) return;
    u8* t = *(u8**)(func_00281180(D_0035f010, who) + 580);
    s32 n = 0;
    for (s32 i = 0; i < t[18]; i++) {
        if (((u16*)(t + 52))[i] == id) n++;
    }
    *num = n;
}
}  // namespace n002712d8

// 002713a0 (was src/anon/batch_w1727_nsa.cpp)
namespace n002713a0 {
extern u8 D_00373a98[] asm("D_00373a98");
extern u8 D_00373aa0[] asm("D_00373aa0");
static inline void set_ptr_len(u8** out_p, s32* out_n, u8* p, s32 n) {
    *out_p = p;
    *out_n = n;
}
/*TARGET 002713a0*/
void func_002713a0(s32 a0, u8** a1, s32* a2) asm("func_002713a0");
void func_002713a0(s32 a0, u8** a1, s32* a2) {
    if (a0 == 0)
        set_ptr_len(a1, a2, D_00373a98, 3);
    else
        set_ptr_len(a1, a2, D_00373aa0, 3);
}
}  // namespace n002713a0

