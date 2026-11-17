// Linked unit 0x00278dd0-0x002793b0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 00278dd0 (was src/anon/batch_w1607.cpp)
namespace n00278dd0 {
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287c00(s32) asm("func_00287c00");
void func_00287c30(void) asm("func_00287c30");
s32 func_00287cd0(void) asm("func_00287cd0");
void func_00287da0(void) asm("func_00287da0");
void func_00287f90(s32) asm("func_00287f90");
void func_00288018(void) asm("func_00288018");
s32 func_00288040(void) asm("func_00288040");
void func_0028f6f0(s32) asm("func_0028f6f0");
extern s32 D_0035f01c asm("D_0035f01c");
void func_0027c3e0(void) asm("func_0027c3e0");
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287c10(void) asm("func_00287c10");
s32 func_0027ad80(void) asm("func_0027ad80");
s32 func_0028f930(s32) asm("func_0028f930");
s32 func_00256ef0(void) asm("func_00256ef0");
s32 func_00289310(s32) asm("func_00289310");
void func_0027acf8(void) asm("func_0027acf8");
void func_00279040(void) asm("func_00279040");
void func_00277d20(void) asm("func_00277d20");
s32 func_0027a990(void) asm("func_0027a990");
void func_0027aa10(void) asm("func_0027aa10");
void func_0028fa98(s32) asm("func_0028fa98");
void func_0027b6b8(void) asm("func_0027b6b8");
void func_00287c90(s32) asm("func_00287c90");
s32 func_0028afa8(s32) asm("func_0028afa8");
s32 func_00287df0(s32, s32, s32, void (*)(void), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_0027c1c0(void) asm("func_0027c1c0");
void func_00263c60(void) asm("func_00263c60");
void func_00256e80(void) asm("func_00256e80");
void func_0027ac38(void) asm("func_0027ac38");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_002831e0(s32, s32) asm("func_002831e0");
/*TARGET 00278dd0*/
void func_00278dd0(void) asm("func_00278dd0");
void func_00278dd0(void) {
    s32 r = func_00289380(D_0035f01c);
    s32 st = func_00287cd0();
    if (st == 2) {
        s32 m = func_00287c10();
        if (func_0027ad80() || func_0028f930(2) || func_00256ef0()) {
            if (r != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                func_0027acf8();
            }
        } else {
            func_00287c30();
            if (m == 16) {
                func_00279040();
                func_00277d20();
            }
        }
        return;
    }
    if ((r != -1 || func_00289310(D_0035f01c)) && func_0027a990() == 0) {
        func_0027aa10();
        func_0028fa98(-1);
    }
    if (st == 0 && func_0027a990()) {
        func_0027b6b8();
        func_00287c90(1);
    }
    {
        s32 n = func_0028afa8(D_0035f01c);
        if (func_00242848(func_00287df0(r, func_00289310(D_0035f01c), 1, func_0027c3e0, 1)) == 0) {
            switch (r) {
            case -1:
                break;
            default:
                if (r < 0 || r >= n) break;
                func_0027c1c0();
            case -2:
                func_00263c60();
                func_00256e80();
                func_0028f6f0(2);
                func_0027ac38();
                func_00287c90(1);
                func_00287c00(16);
                break;
            case -7: {
                s32 m = func_00287bc0();
                func_00287bd0(37, 0);
                func_002831e0(2, m);
                break;
            }
            case -4:
                func_00287da0();
                break;
            }
        }
    }
    if (func_00288040()) {
        func_00288018();
    }
}
}  // namespace n00278dd0

// 00279040 (was src/anon/batch_w3809b_gnsa.c)
namespace n00279040 {
u8* func_002859a0(void) asm("func_002859a0");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028b040(u32) asm("func_0028b040");
s32 func_002570a0(s32) asm("func_002570a0");
void func_0027aed8(s32, s32*, s32*) asm("func_0027aed8");
u8* func_00281180(u32, s32) asm("func_00281180");
u8* func_001a80c8(s32) asm("func_001a80c8");
s32 func_002811b0(u32, s32) asm("func_002811b0");
s32 func_001b7818(s32) asm("func_001b7818");
void func_00279620(void) asm("func_00279620");
void func_002793b0(void) asm("func_002793b0");
void func_00279860(void) asm("func_00279860");
void func_002799b0(void) asm("func_002799b0");
void func_00279a10(void) asm("func_00279a10");
typedef struct Ent_00279040 { u16 id; u8 hi; u8 idx; s8 cat; u8 b5; s8 b6; s8 pos; } Ent_00279040;
typedef struct Hdr_00279040 { u16 h0; u16 h2; u8 pad4[3]; s8 count; u8 cnt[4]; Ent_00279040 e[1]; } Hdr_00279040;
extern Hdr_00279040* D_0035f230 asm("D_0035f230");
extern u32 D_0035f010 asm("D_0035f010");
extern u32 D_0035f01c asm("D_0035f01c");
/*TARGET 00279040*/
void func_00279040(void) asm("func_00279040");
void func_00279040(void) {
    s32 sp0, sp4;
    u8* base = func_002859a0();
    s32 v;
    s32 who;
    u16* src;
    s32 i, n, k;
    if (func_00287bc0() == 15) v = func_0028b040(D_0035f01c);
    else v = func_002570a0(15);
    func_0027aed8(v, &sp0, &sp4);
    who = 0;
    if (sp0 == 0) who = sp4;
    n = 0;
    i = 0;
    src = (u16*)(*(u32*)(func_00281180(D_0035f010, who) + 580) + 80);
    D_0035f230->h2 = *(u16*)(func_00281180(D_0035f010, who) + 398);
    for (i = 0; i < 80; i++, src++) {
        u16 id = src[2] & 0x7fff;
        u8* info;
        Ent_00279040* e;
        if (id == 0) continue;
        info = func_001a80c8(id);
        if (sp0 != 0) {
            if (info[6] != 0) continue;
            if (!(src[2] >> 15)) continue;
            asm("" ::: "memory");
        }
        D_0035f230->e[n].id = src[2] & 0x7fff;
        D_0035f230->e[n].hi = src[2] >> 15;
        D_0035f230->e[n].idx = i;
        if (who == 0) {
            u16* t = (u16*)(base + 208);
            for (k = 0; k < 80; k++) {
                if (t[k] == D_0035f230->e[n].id) break;
            }
            if (k < 80) D_0035f230->e[n].pos = k; else D_0035f230->e[n].pos = -1;
        } else {
            s32 row = func_001b7818(func_002811b0(D_0035f010, who)) - 2;
            u16* t = (u16*)(row * 96 + (u32)base + 368);
            for (k = 0; k < 48; k++) {
                if (t[k] == D_0035f230->e[n].id) break;
            }
            if (k < 48) D_0035f230->e[n].pos = k; else D_0035f230->e[n].pos = -1;
        }
        switch (info[6]) {
        case 0: D_0035f230->e[n].cat = 2; break;
        case 1: case 2: D_0035f230->e[n].cat = 0; break;
        case 3: D_0035f230->e[n].cat = 1; break;
        }
        D_0035f230->e[n].b5 = info[7];
        D_0035f230->e[n].b6 = -1;
        n++;
    }
    asm("" :: "r"(n));
    D_0035f230->count = n;
    func_00279620();
    func_002793b0();
    func_00279860();
    func_002799b0();
    for (i = 0; i < 4; i++) D_0035f230->cnt[i] = 0;
    for (i = 0; i < D_0035f230->count; i++) D_0035f230->cnt[D_0035f230->e[i].cat]++;
    func_00279a10();
}
}  // namespace n00279040

