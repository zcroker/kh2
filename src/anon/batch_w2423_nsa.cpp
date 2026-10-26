#include "../common/types.h"
// 002a4620 matched under -fno-strict-aliasing (w2423)
extern "C" {
void func_00138c10(u8*, s32);
void func_00138c68(u8*, u32, u32);
void func_00138c78(u8*, u32*, u32*);
void func_00242618(s32, s32);
void func_002a3aa8(void);
s32 func_002a4990(s32);
s32 func_002a4a00(s32);
extern u8* D_0035f5e4;
extern u8* D_0035f5e8;
struct Pad2a { u8 p0[8]; u64 trig; u8 p1[8]; u64 rep; };

void func_002a4620(Pad2a* pad) {
    s32 sel = *(s32*)(D_0035f5e4 + 4232);
    s32 top = *(s32*)(D_0035f5e4 + 4228);
    s32 total = *(s32*)(D_0035f5e4 + 4224);
    s32 vis = total;
    s32 col = sel % 8;
    s32 row = sel / 8;
    s32 idx = row + top;
    s32 n = func_002a4a00(idx);
    if (vis >= 10) vis = 9;
    if (pad->rep & 0x10) {
        if (row != 0) { row--; goto calc; }
        if (top != 0) { top--; idx = top; goto recount; }
        if (pad->trig & 0x10) { top = total - vis; row = vis - 1; goto calc; }
        goto recount;
    } else if (pad->rep & 0x20) {
        if (row < vis - 1) { row++; goto calc; }
        if (top + 9 < total) { top++; goto calc; }
        if (pad->trig & 0x20) { top = 0; row = 0; idx = 0; }
        goto recount;
    } else if (pad->rep & 0x8000) {
        if (vis < top) { top -= vis; goto calc; }
        if (top != 0) { top = 0; row = 0; idx = 0; goto recount; }
        if (col != 0) { col = 0; goto recount; }
        if (pad->trig & 0x8000) {
            top = total - vis; row = vis - 1; idx = row + top;
            col = func_002a4a00(idx) - 1;
        }
        goto recount;
    calc:
        idx = row + top;
    recount:
        n = func_002a4a00(idx);
        if (col >= n) col = n - 1;
    } else if (pad->rep & 0x4000) {
        s32 lim = total - vis;
        s32 nt = top + vis;
        if (nt < lim) { top = nt; goto calc2; }
        if (top < lim) { top = lim; row = vis - 1; goto calc2; }
        if (col < n - 1) { top = lim; col = n - 1; goto calc2; }
        if (pad->trig & 0x4000) { top = 0; row = 0; col = 0; idx = 0; }
        goto recount2;
    calc2:
        idx = row + top;
    recount2:
        n = func_002a4a00(idx);
        if (col >= n) col = n - 1;
    }
    if (pad->rep & 0x40) col = col == 0 ? n - 1 : col - 1;
    else if (pad->rep & 0x80) col = col < n - 1 ? col + 1 : 0;
    sel = row * 8 + col;
    if (top != *(s32*)(D_0035f5e4 + 4228) || sel != *(s32*)(D_0035f5e4 + 4232)) {
        func_00242618(1, 1);
        u8* o = D_0035f5e8 + row * 3264 + col * 408;
        u32 t0, t1;
        func_00138c78(o, &t0, &t1);
        o = D_0035f5e8 + 29376;
        func_00138c68(o, t0, t1);
        s32 k = func_002a4990(idx);
        if (!D_0035f5e4[k * 8 + 4096] && *(s32*)(o + 388) != 66) func_00138c10(o, 66);
        else if (D_0035f5e4[k * 8 + 4096] && *(s32*)(o + 388) == 66) func_00138c10(o, 65);
        *(s32*)(D_0035f5e4 + 4228) = top;
        *(s32*)(D_0035f5e4 + 4232) = sel;
        func_002a3aa8();
    }
}

}
