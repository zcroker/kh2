// 00265c78: -g build. func_00192cc0 returns s32 (printf-like); that is what fixes the case 1-5 load order (rank_for_schedule dep count).
#include "../common/types.h"
extern "C" {
u8* func_001058e8();
s32 func_00287bc0();
s32 func_0028b040(u32);
u32 func_002670a0(s32);
u32 func_00257070(s32);
u8* func_00281180(u32, s32);
s32 func_00192cc0(u8*, const char*, ...);
s32 func_00188bb0(u32, u32);
u8 func_00267150(s32);
u8* func_00189200(u8*, u32);
u8 func_001d5c70(u32, u8*);
u8* func_001d5c10(u32, u8*);
u8 func_001d5d20();
u8* func_001d5cd0();
extern u32 D_0035f01c;
extern u32 D_0035f010;
extern u8* D_0035f0e4;
extern const char D_00373370[];
extern const char D_00373378[];
extern const char D_00373380[];

void func_00265c78(void) {
    u8* sv;
    u32 v;
    s32 d;
    u8 lv;
    u8* nx;
    sv = func_001058e8() + 0x24F0;
    if (func_00287bc0() == 23) v = func_002670a0(func_0028b040(D_0035f01c));
    else v = func_00257070(23);
    switch (v) {
    case 0: case 7: case 8: case 9: {
        s32 k = v ? v - 6 : 0;
        u8* o;
        if (v) o = func_00281180(D_0035f010, k);
        else o = *(u8**)D_0035f0e4;
        func_00192cc0(D_0035f0e4 + 0x524, D_00373370, *(u8*)(*(u32*)(o + 0x244) + 0xF));
        func_00192cc0(D_0035f0e4 + 0x544, D_00373370, *(s32*)(sv + 0x11F0));
        u32 y = *(u32*)(o + 0x254);
        func_00192cc0(D_0035f0e4 + 0x564, D_00373370, func_00188bb0(*(u32*)(o + 0x244), y));
        { s32 b = *(s32*)(o + 4); func_00192cc0(D_0035f0e4 + 0x584, D_00373378, *(s32*)(o + 0), b); }
        func_00192cc0(D_0035f0e4 + 0x5A4, D_00373378, *(s32*)(o + 0x180), *(s32*)(o + 0x184));
        func_00192cc0(D_0035f0e4 + 0x5C4, D_00373378, func_00267150(k), *(u16*)(o + 0x18E));
        func_00192cc0(D_0035f0e4 + 0x664, D_00373370, *(u16*)(o + 0x188));
        func_00192cc0(D_0035f0e4 + 0x684, D_00373370, *(u16*)(o + 0x18A));
        func_00192cc0(D_0035f0e4 + 0x6A4, D_00373370, *(u16*)(o + 0x18C));
        func_00192cc0(D_0035f0e4 + 0x6C4, D_00373380, 100 - o[0x1A9]);
        func_00192cc0(D_0035f0e4 + 0x6E4, D_00373380, 100 - o[0x1AA]);
        func_00192cc0(D_0035f0e4 + 0x704, D_00373380, 100 - o[0x1AB]);
        func_00192cc0(D_0035f0e4 + 0x724, D_00373380, 100 - o[0x1AC]);
        if (v == 0) {
            if (*(u32*)(D_0035f0e4 + 0x18) & 0x40) func_00192cc0(D_0035f0e4 + 0x5E4, D_00373378, o[0x1B1], o[0x1B2]);
            if (*(u32*)(D_0035f0e4 + 0x18) & 0x80) func_00192cc0(D_0035f0e4 + 0x604, D_00373370, sv[0x1210]);
            if (*(u32*)(D_0035f0e4 + 0x18) & 0x20000) func_00192cc0(D_0035f0e4 + 0x744, D_00373370, func_00189200(sv, 1)[2]);
            if (*(u32*)(D_0035f0e4 + 0x18) & 0x100) func_00192cc0(D_0035f0e4 + 0x624, D_00373370, func_00189200(sv, 2)[2]);
            if (*(u32*)(D_0035f0e4 + 0x18) & 0x40000) func_00192cc0(D_0035f0e4 + 0x764, D_00373370, func_00189200(sv, 3)[2]);
            if (*(u32*)(D_0035f0e4 + 0x18) & 0x200) func_00192cc0(D_0035f0e4 + 0x644, D_00373370, func_00189200(sv, 4)[2]);
            if (*(u32*)(D_0035f0e4 + 0x18) & 0x80000) func_00192cc0(D_0035f0e4 + 0x784, D_00373370, func_00189200(sv, 5)[2]);
        }
        break;
    }
    case 1: case 2: case 3: case 4: case 5: {
        u8* o = ((u8**)D_0035f0e4)[v];
        u8* inf = func_00189200(sv, v);
        d = 0;
        func_00192cc0(D_0035f0e4 + 0x524, D_00373370, lv = inf[2]);
        func_00192cc0(D_0035f0e4 + 0x544, D_00373370, func_001d5c70(v, inf));
        nx = func_001d5c10(v, inf);
        if (nx) d = *(s32*)(nx + 4) - *(s32*)(inf + 4);
        func_00192cc0(D_0035f0e4 + 0x564, D_00373370, d);
        func_00192cc0(D_0035f0e4 + 0x584, D_00373370, lv + 2);
        func_00192cc0(D_0035f0e4 + 0x664, D_00373370, *(u16*)(o + 0x188));
        func_00192cc0(D_0035f0e4 + 0x684, D_00373370, *(u16*)(o + 0x18A));
        func_00192cc0(D_0035f0e4 + 0x6A4, D_00373370, *(u16*)(o + 0x18C));
        func_00192cc0(D_0035f0e4 + 0x6C4, D_00373380, 100 - o[0x1A9]);
        func_00192cc0(D_0035f0e4 + 0x6E4, D_00373380, 100 - o[0x1AA]);
        func_00192cc0(D_0035f0e4 + 0x704, D_00373380, 100 - o[0x1AB]);
        func_00192cc0(D_0035f0e4 + 0x724, D_00373380, 100 - o[0x1AC]);
        break;
    }
    case 6: {
        d = 0;
        func_00281180(D_0035f010, 0);
        lv = sv[0x1036];
        func_00192cc0(D_0035f0e4 + 0x524, D_00373370, lv);
        func_00192cc0(D_0035f0e4 + 0x544, D_00373370, func_001d5d20());
        nx = func_001d5cd0();
        if (nx) d = *(s32*)(nx + 4) - *(s32*)(sv + 0x11F4);
        func_00192cc0(D_0035f0e4 + 0x564, D_00373370, d);
        func_00192cc0(D_0035f0e4 + 0x584, D_00373370, lv + 2);
        break;
    }
    }
}
}
