#include "../common/types.h"

extern "C" {
struct Pad { u8 p0[8]; u64 trig; u8 p16[8]; u64 rep; };
struct Cur { u8 p0[4]; s8 count; s8 sel; };
extern Cur* D_0035f260;
Pad* func_00167f18(s32);
s32 func_00287cd0(void);
s32 func_00280290(void);
void func_002802e8(void);
void func_00287bd0(s32, s32);
void func_00280458(void);
void func_00280528(void);
s32 func_00280368(void);
void func_002803e0(void);
void func_00287cc0(s32);
void func_00242618(s32, s32);
void func_00280240(void);
void func_002800d0(void);

void func_0027f9d8(void) {
    Pad* pad = func_00167f18(0);
    s32 st = func_00287cd0();
    if (st == 2) {
        if (func_00280290()) {
            if (pad->trig & 0xf8) func_002802e8();
            return;
        }
        func_00287bd0(0, 0);
        return;
    }
    func_00280458();
    func_00280528();
    if (st == 0) {
        if (pad->rep & 0xf8) {
            if (!func_00280368()) func_002803e0();
        }
        if (func_00280368()) func_00287cc0(1);
    }
    u64 b = pad->trig;
    s32 d;
    if (b & 0x10) d = -5;
    else if (b & 0x20) d = 5;
    else if (b & 0x40) d = -1;
    else if (b & 0x80) d = 1;
    else {
        if (!(b & 8)) return;
        func_00242618(9, 1);
        func_00280240();
        func_00287cc0(2);
        return;
    }
    if (d) func_00242618(7, 1);
    s32 cur = D_0035f260->sel;
    s32 n = cur + d;
    if (n < 0) {
        if (cur != 0) cur = 0;
        else cur = D_0035f260->count - 1;
    } else if (n >= D_0035f260->count) {
        s32 last = D_0035f260->count - 1;
        cur = cur < last ? last : 0;
    } else {
        cur = n;
    }
    D_0035f260->sel = cur;
    func_002800d0();
}

}
