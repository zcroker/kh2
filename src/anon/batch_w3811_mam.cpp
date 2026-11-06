// 002a3648: built with -fmove-all-movables (*_mam.cpp). One function-scope index j is reused by every
// inner loop, and one address variable d is shared by both draw loops (keeps D_0035f5e8 out of a0).
#include "../common/types.h"
extern "C" {
struct It2a3 { u8 a; u8 on; u8 p[6]; };
struct Grp2a3 { u8 n; u8 cnt; u8 p[2]; It2a3* items; };
struct Big2a3 { u8 p0[0x1000]; Grp2a3 g[16]; u8 p1080[4]; s32 sel; };
extern Big2a3* D_0035f5e4;
extern u8* D_0035f5e8;
void func_00138c10(u8*, s32);
s32 func_002a4430(void);
s32 func_002a43f0(void);

// Redraws a 9-row list of 8 cells: clears every cell, finds the group holding the selected item,
// then draws the items from that group onwards, highlighted ones with a second style.
void func_002a3648(void)
{
    s32 i, j;
    s32 on, off;
    s32 pos, k, g;
    It2a3* items;
    u8* d;
    for (i = 0; i < 9; i++)
        for (j = 0; j < 8; j++) {
            d = (u8*)(i * 0xcc0 + j * 0x198 + (u32)D_0035f5e8);
            func_00138c10(d, 2);
        }
    if (func_002a4430()) {
        off = 68;
        on = 67;
    } else if (func_002a43f0()) {
        off = 74;
        on = 73;
    } else {
        off = 62;
        on = 61;
    }
    pos = 0;
    k = 0;
    for (i = 0; i < 15; i++) {
        if (D_0035f5e4->g[i].cnt) {
            pos = 0;
            for (j = 0; j < D_0035f5e4->g[i].cnt; j++, k++) {
                if (D_0035f5e4->sel == k) break;
                if (j == D_0035f5e4->g[i].cnt - 1) pos += D_0035f5e4->g[i].n & 7;
                else pos += 8;
            }
            if (j < D_0035f5e4->g[i].cnt) break;
        }
    }
    g = i;
    items = D_0035f5e4->g[g].items;
    for (i = 0; i < 9 && g < 15; i++) {
        s32 n = D_0035f5e4->g[g].n;
        s32 cnt = 8;
        if (n < pos + 8) cnt = n - pos;
        for (j = 0; j < cnt; j++, pos++) {
            d = (u8*)(i * 0xcc0 + j * 0x198 + (u32)D_0035f5e8);
            func_00138c10(d, items[pos].on ? off : on);
        }
        if (pos >= D_0035f5e4->g[g].n) {
            for (j = g + 1; j < 15; j++)
                if (D_0035f5e4->g[j].cnt) break;
            g = j;
            pos = 0;
            items = D_0035f5e4->g[g].items;
        }
    }
}
}
