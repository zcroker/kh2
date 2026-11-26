// Linked unit 0x002713c8-0x00271900 (one namespace per old matched source; class methods in their own namespace).
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

// .rodata 0x37396c-0x37399c: tables that old code reads as extern D_
extern const u32 R_0037396c[1] asm("D_0037396c") __attribute__((aligned(4))) = { 0x0 };
extern const u32 R_00373970[8] asm("D_00373970") __attribute__((aligned(4))) = { 0x8486, 0x8487, 0x8488, 0x8489, 0x848a, 0x848b, 0x96, 0x0 };
extern const u32 R_00373990[3] asm("D_00373990") __attribute__((aligned(4))) = { 0x900095, 0x8a008f, 0x89 };

// 002713c8 (was src/anon/batch_w3808_g.cpp)
namespace n002713c8 {
s32 func_00287bc0(void) asm("func_00287bc0");
u8* func_00257770(void) asm("func_00257770");
s32 func_0028b040(u32) asm("func_0028b040");
s32 func_00257070(s32) asm("func_00257070");
void func_002713a0(s32, s8**, s32*) asm("func_002713a0");
s32 func_00272c20(s32) asm("func_00272c20");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
u8* func_00273140(s32) asm("func_00273140");
void Tz__CmCustom__MakeItemMess(s32, u8*, s32, s32, s32) asm("Tz__CmCustom__MakeItemMess");
void func_00271828(s32, u8*) asm("func_00271828");
u8* func_00273180(s32, s32) asm("func_00273180");
void func_002595b8(s32, u8*, s32) asm("func_002595b8");
extern u32 D_0035f01c asm("D_0035f01c");
extern u8* D_0035f12c asm("D_0035f12c");
extern s8* D_01e21ed0 asm("D_01e21ed0");
extern s8 D_00373aa8[] asm("D_00373aa8");
// 002713c8: fills the menu entry list (32-byte entries at base+0xae10) for each target type,
// marking the default selection, and loads icons for types 2 and 4 when flag is set.
void ttarget0_002713c8() asm("_Z17ttarget0_002713c8v");
/*TARGET 002713c8*/
void ttarget0_002713c8() asm("_Z17ttarget0_002713c8v");
void ttarget0_002713c8() {
    s32 arr[8];
    s32 count;
    s32 mode;
    s32 flag;
    s32 n;
    s32 k;
    s32 j;
    u8* base;
    s32 sel;
    s32 i;
    s32 m;
    mode = func_00287bc0();
    base = func_00257770();
    if (mode == 25) flag = func_0028b040(D_0035f01c);
    else flag = func_00257070(25);
    func_002713a0(flag, &D_01e21ed0, &count);
    for (i = 0; i < count; i++) {
        arr[i] = func_00272c20(D_01e21ed0[i]);
    }
    j = 0;
    func_002fde18(base + 0xae10, 0, 0x300);
    k = 0;
    func_002fde18(base + 0xb110, 0, 0x60);
    for (i = 0; i < count; i++) {
        n = arr[i];
        for (m = 0; m < n; m++, k++) {
            s32 on = 0;
            s32 t = D_01e21ed0[i];
            sel = -1;
            // switch (t) { case 0: ... case 1: ... } as the compiler's compare tree
            if (t == 1) goto type1;
            if (t >= 2) goto done;
            if (t != 0) goto done;
            on = 1;
            if (mode == 25) sel = D_00373aa8[m];
            goto done;
        type1:
            on = 1;
        done:
            if (D_01e21ed0[i] != 3) {
                s32 a3;
                if (*(s16*)(D_0035f12c + j * 8 + 8) != 0 && func_00273140(j)[2] == 18) {
                    a3 = *(s8*)(D_0035f12c + j * 8 + 10) == 0;
                } else {
                    a3 = *(s8*)(D_0035f12c + j * 8 + 10) == 1;
                }
                Tz__CmCustom__MakeItemMess(*(s16*)(D_0035f12c + j * 8 + 8), base + k * 32 + 0xae10, on, a3, sel);
                j++;
            } else {
                func_00271828(*(s8*)(D_0035f12c + 3), base + k * 32 + 0xae10);
            }
            if (flag) {
                s32 a0 = D_01e21ed0[i];
                if (a0 == 2 || a0 == 4) {
                    func_002595b8(func_00273180(a0, *(s8*)(D_0035f12c + j * 8 + 3))[4], base + k * 4 + 0xb110, 1);
                }
            }
        }
    }
}
}  // namespace n002713c8

// 00271710 (was src/anon/batch_w1597.cpp)
namespace n00271710 {
// 00271710: refresh a message slot; returns a1
struct W1597It { u16 h0; u8 b2; u8 pad[5]; u16 h8; };
struct W1597Rec { u8 pad[8]; s32 f8; };
W1597It* func_001a80c8(s32) asm("func_001a80c8");
void func_00259570(u8, s32, u8, s32) asm("func_00259570");
void func_002595b8(s32, s32, s32) asm("func_002595b8");
s32 func_001a3820(u16) asm("func_001a3820");
W1597Rec* YS__COMMAND_ELEM__Get(s32) asm("YS__COMMAND_ELEM__Get");
s32 func_002595e0() asm("func_002595e0");
u32 func_00192048(u32) asm("func_00192048");
u32 func_002595e8(u32, u32) asm("func_002595e8");
/*TARGET 00271710*/
s32 Tz__CmCustom__MakeItemMess(s32 a0, u32 a1, u8 a2, u8 a3, s32 t0) asm("Tz__CmCustom__MakeItemMess");
s32 Tz__CmCustom__MakeItemMess(s32 a0, u32 a1, u8 a2, u8 a3, s32 t0)
{
    W1597It* p;
    if (a0) p = func_001a80c8(a0); else p = 0;
    u32 v = 0x8448;
    if (t0 < 0) {
        if (p) func_00259570(p->b2, a1, a3, 1);
    } else {
        func_002595b8(t0, a1, 1);
    }
    if (a2) {
        if (a0) v = YS__COMMAND_ELEM__Get(func_001a3820(p->h0))->f8;
    } else if (a0) {
        v = p->h8;
    }
    u32 x;
    if (t0 < 0 && !p) x = a1; else x = a1 + func_002595e0();
    func_002595e8(x, func_00192048(v));
    return a1;
}
}  // namespace n00271710

// 00271828 (was src/anon/batch_w210.cpp)
namespace n00271828 {
extern u32 D_00373970[] asm("D_00373970");
u32 u_tail4_00192048(u32) asm("_Z16u_tail4_00192048jjjj");
u32 CopyMessage(u32, u32) asm("_ZN2Tz6CmComm11CopyMessageEPcPKN2YS7MESSAGEE");
/*TARGET 00271828*/
// 0x001712b0: definition moved into src/anon/unit_00170f58.cpp

// 00178570: moved to src/yasui/libys/player.cpp

u32 func_00271828(u32 i, u32 b) asm("func_00271828");
// 0x001712b0: definition moved into src/anon/unit_00170f58.cpp

// 00178570: moved to src/yasui/libys/player.cpp

u32 func_00271828(u32 i, u32 b) {
    u32 s = b;
    CopyMessage(s, u_tail4_00192048(D_00373970[i]));
    return s;
}
}  // namespace n00271828

// 00271870 (was src/anon/batch_w52.cpp)
namespace n00271870 {
u8* func_001a8110(u8*) asm("func_001a8110");
u32 func_001a3820(u16) asm("func_001a3820");
/*TARGET 00271870*/
u32 Tz__CmCustom__Command2Item(u32 key) asm("Tz__CmCustom__Command2Item");
u32 Tz__CmCustom__Command2Item(u32 key) {
    u8* e = 0;
    u32 r = 0;
    if (!key) return 0;
    while ((e = func_001a8110(e)) != 0) {
        if (e[2] == 18 || e[2] == 0) {
            if (func_001a3820(*(u16*)e) == key) {
                r = *(u16*)e;
                break;
            }
        }
    }
    return r;
}
}  // namespace n00271870

