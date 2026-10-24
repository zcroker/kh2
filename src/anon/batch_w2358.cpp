#include "../common/types.h"
extern "C" {
struct Ent { u8* base; s32 ofs; s32 pad; };
struct Cmd { u16 size; s16 type; };
extern u8 D_0035de44;
extern s32 D_0035db10;
extern u8 D_0035de24;
extern s32 D_0035de40;
extern u8 D_0035de55;
extern u8 D_0035de56;
extern Ent D_0035db50[];
void func_00102448(void*, s32);
s32 func_00197800(void);
void func_00197828(f32);
void func_001397d8(s32);
s32 func_00228378(void);
void func_0015f278(void);
void* func_0014ac08(void);
void* func_0014abd8(void);
void func_0014aa80(void*, s32, s32);
void func_0015cdb0(void);
void func_0022f7c0(Cmd*, void*);
void func_00230d78(Cmd*);
void func_0022dd80(Cmd*, void*);
void func_0022f018(Cmd*, void*);
void func_0022e3e8(Cmd*, void*);
void func_0022f200(Cmd*, void*);
void func_0022ef50(Cmd*, void*);
void func_0022efb8(Cmd*, void*);
void func_0022cc38(Cmd*, void*);
void func_0022d880(Cmd*, void*);
void func_0022d618(Cmd*, void*);
void func_0022cd48(Cmd*, void*);
void func_0022cea0(Cmd*, void*);
void func_0022f280(Cmd*, void*);
void func_0022f308(Cmd*, void*);
void func_00231948(Cmd*, void*);
void func_0022e468(Cmd*, void*);
void func_002308c8(Cmd*);
void func_0022d3c8(Cmd*, void*);
void func_0022e5f8(Cmd*, void*);
void func_0022d728(Cmd*, void*);
void func_0022cf60(Cmd*, void*);
void func_0022e818(Cmd*, void*);
void func_0022ea28(Cmd*, void*);
void func_00232c88(Cmd*, void*);
void func_002332a8(Cmd*, void*);
void func_0022d9b0(Cmd*, void*);
void func_002253a0(Cmd*, void*);
void func_00225898(Cmd*, void*);
void func_00232070(Cmd*, void*);
void func_00224fa0(Cmd*, void*);
void func_00224ea0(Cmd*, void*);
void func_0022cae8(Cmd*, void*);
void func_0022eb80(Cmd*, void*);
void func_0022ee30(Cmd*, void*);
void func_0022e4f0(Cmd*, void*);
void func_0022c998(Cmd*, void*);
void func_0022c590(Cmd*, void*);
void func_0022c530(Cmd*, void*);
void func_0022dd40(Cmd*, void*);
void func_0022d598(Cmd*, void*);
void func_0022ce00(Cmd*, void*);
void func_00232d60(Cmd*, void*);
void func_0022ce50(Cmd*, void*);
void func_0022bc08(Cmd*, void*);
void func_00233410(Cmd*, void*);
void func_00230b50(Cmd*, void*);
void func_0022d098(Cmd*, void*);
void func_0022d1d8(Cmd*, void*);
void func_002322b8(Cmd*, void*);
void func_0022d238(Cmd*, void*);
void func_0022d288(Cmd*, void*);
void func_00233490(Cmd*, void*);
void func_0022bef8(Cmd*, void*);
void func_0022c7c0(Cmd*, void*);
void func_0022d778(Cmd*, void*);
void func_002328c0(Cmd*, void*);

// Event-script thread: waits for the event system to be ready, then runs the
// command stream of D_0035db50 (u16 size, s16 opcode) one command per step.
void func_002272b8(void* th) {
    for (;;) {
        for (;;) { if (D_0035de44 == 1) break; func_00102448(th, 0); }
        for (;;) { if (D_0035db10 == 2 && D_0035de24 && func_00197800()) break; func_00102448(th, 0); }
        func_00197828((f32)(D_0035de40 * 2));
        func_001397d8(16);
        if (func_00228378()) {
            func_0015f278();
            func_0014aa80(func_0014ac08(), 0, 0);
            func_0014aa80(func_0014abd8(), 0, 0);
        }
        D_0035db10 = 3;
        if (D_0035de55 == 1) func_0015cdb0();
        s32 i = 0;
    next:
          {
            if (D_0035db50[i].base) {
                Cmd* c = (Cmd*)(D_0035db50[i].base + D_0035db50[i].ofs);
                u32 size = c->size;
                if (size == 0) {
                    D_0035de56 = 1;
                    for (;;) func_00102448(th, 0);
                }
                switch (c->type + 0) {
        case 2: func_0022f7c0(c, th); break;
        case 6: func_00230d78(c); break;
        case 9: func_0022dd80(c, th); break;
        case 10: func_0022f018(c, th); break;
        case 11: func_0022e3e8(c, th); break;
        case 12: func_0022f200(c, th); break;
        case 13: func_0022ef50(c, th); break;
        case 14: func_0022efb8(c, th); break;
        case 18: func_0022cc38(c, th); break;
        case 21: func_0022d880(c, th); break;
        case 22: func_0022d618(c, th); break;
        case 23: func_0022cd48(c, th); break;
        case 24: func_0022cea0(c, th); break;
        case 25: func_0022f280(c, th); break;
        case 26: func_0022f308(c, th); break;
        case 27: func_00231948(c, th); break;
        case 28: func_0022e468(c, th); break;
        case 31: func_002308c8(c); break;
        case 32: func_0022d3c8(c, th); break;
        case 33: func_0022e5f8(c, th); break;
        case 34: func_0022d728(c, th); break;
        case 39: func_0022cf60(c, th); break;
        case 40: func_0022e818(c, th); break;
        case 41: func_0022ea28(c, th); break;
        case 43: func_00232c88(c, th); break;
        case 44: func_002332a8(c, th); break;
        case 45: func_0022d9b0(c, th); break;
        case 46: func_002253a0(c, th); break;
        case 48: func_00225898(c, th); break;
        case 49: func_00232070(c, th); break;
        case 51: func_00224fa0(c, th); break;
        case 52: func_00224ea0(c, th); break;
        case 53: func_0022cae8(c, th); break;
        case 54: func_0022eb80(c, th); break;
        case 55: func_0022ee30(c, th); break;
        case 58: func_0022e4f0(c, th); break;
        case 59: func_0022c998(c, th); break;
        case 60: func_0022c590(c, th); break;
        case 61: func_0022c530(c, th); break;
        case 63: func_0022dd40(c, th); break;
        case 64: func_0022d598(c, th); break;
        case 65: func_0022ce00(c, th); break;
        case 66: func_00232d60(c, th); break;
        case 67: func_0022ce50(c, th); break;
        case 68: func_0022bc08(c, th); break;
        case 69: func_00233410(c, th); break;
        case 71: func_00230b50(c, th); break;
        case 72: func_0022d098(c, th); break;
        case 73: func_0022d1d8(c, th); break;
        case 74: func_002322b8(c, th); break;
        case 75: func_0022d238(c, th); break;
        case 77: func_0022d288(c, th); break;
        case 79: func_00233490(c, th); break;
        case 80: func_0022bef8(c, th); break;
        case 81: func_0022c7c0(c, th); break;
        case 82: func_0022d778(c, th); break;
        case 83: func_002328c0(c, th); break;
                }
                D_0035db50[i].ofs += size;
            }
            if (D_0035db10 != 3) continue;
            if (++i >= 1) i = 0;
            goto next;
          }
    }
}
}

extern "C" {
extern s32 D_0035f01c;
extern u16 D_00373e28[];
u8* func_00257770(void);
s32 func_00289380(s32);
s32 func_00287cd0(void);
s32 func_00287c10(void);
s32 func_0028f930(s32);
s32 func_00256ef0(void);
s32 func_00257970(void);
s32 func_0027a908(s32);
s32 func_00289310(s32);
void func_00287f90(s32);
void func_00256ea8(void);
void func_0027a898(s32);
void func_0028f7e8(s32);
void func_0028f878(void);
void func_00287c30(void);
void func_0028af18(s32, s32);
void func_00257708(s32);
void func_002772c8(s32);
void func_00279040(void);
void func_00277d20(void);
void func_002788c0(void);
s32 func_002570a0(s32);
void func_0027aed8(s32, s32*, s32*);
void func_00257050(s32, s32, s32);
void func_002677f0(s32, s32);
s32 func_0027a990(void);
void func_0027aa10(void);
void func_0028da70(u8*, s32);
void func_0028fa98(s32);
void func_00256e30(void);
void func_0027b6b8(void);
void func_00287c90(s32);
s32 func_0028afa8(s32);
s32 func_00287df0(s32, s32, s32, void (*)(void), s32);
void func_0027c3e0(void);
s32 func_00242848(s32);
void func_00287da0(void);
s32 func_002891e8(s32);
s32 func_0028b038(s32);
s32 func_00288040(void);
void func_00288018(void);
void func_0027b548(s32);
void func_00263c60(void);
void func_0028f6f0(s32);
void func_0027a7e0(s32);
void func_00287c00(s32);
s32 func_00287bc0(void);
void func_00287bd0(s32, s32);
void func_002831e0(s32, s32);
void func_0027bf68(void);
void func_002799b0(void);
void func_0027a6d8(void);
void func_0027a208(void);
void func_0027b248(s32);
void func_00256e80(void);
s32 func_0027af58(void);
void func_0028fb28(s32, u16);
s32 func_00258068(s32);
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
                else if (m == 2) func_0028f878();
            }
        } else {
            func_00287c30();
            func_0028af18(D_0035f01c, 115);
            func_00257708(0);
            if (m == 15) {
                func_0028f7e8(1);
                func_002772c8(-1);
            } else if (m == 16) {
                func_00279040();
                func_00277d20();
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
    if (func_00242848(func_00287df0(r, func_00289310(D_0035f01c), 1, func_0027c3e0, 1)) == 0) {
        switch (r) {
        case -4:
            func_00287da0();
            func_00257050(16, func_002891e8(D_0035f01c), func_0028b038(D_0035f01c));
            break;
        case -11:
        case -10:
            func_0027b548(r == -10);
            func_00263c60();
            func_0028f6f0(1);
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
            func_0027bf68();
            func_002799b0();
            func_0027a6d8();
            func_0027a208();
            func_0027b248(1);
            func_0027b6b8();
            break;
        case -5:
            func_00263c60();
            func_0028f6f0(1);
            func_0028f6f0(0);
            func_00256e80();
            func_0027a7e0(1);
            func_00287c90(1);
            func_00287c00(2);
            func_00257050(16, func_002891e8(D_0035f01c), func_0028b038(D_0035f01c));
            break;
        default: {
            if (r < 0 || r >= n) break;
            a = 17;
            s32 v = func_0027af58();
            switch (v) {
            case 0: a = 17; break;
            case 1: a = 18; break;
            case 2: a = 19; break;
            }
            func_0028fb28(2, D_00373e28[v]);
            func_00256e80();
            func_00263c60();
            func_0027a7e0(0);
            func_00287c90(1);
            func_00287c00(a);
            func_00257050(16, func_002891e8(D_0035f01c), func_0028b038(D_0035f01c));
            break;
        }
        case -2:
            func_00263c60();
            func_0028f6f0(1);
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
}
