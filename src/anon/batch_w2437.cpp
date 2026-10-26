#include "../common/types.h"

struct T2437Tbl { u8 pad[8]; u16 lo; u16 hi; u16 n; u16 pad2; u8 pad3[8]; s32 off; };

extern "C" {
T2437Tbl* func_00132c68(s32);

// The shared fail block sits in the mask == 0 arm, so that arm's compare falls into it
// (bnez -> out, b fail), and the two failure tests of the mask arm are separate gotos.
s32 func_001325c8(s32 a0, u32 mask, u32 id) {
    T2437Tbl* t = func_00132c68(a0);
    s32 r = -1;
    u32 v;
    if (t) {
        if (mask) {
            id &= mask;
            if (id >= t->lo && id <= t->hi) {
                v = *(u16*)((u8*)t + t->off + (id - t->lo) * 2);
                r = v - 1;
                if (v == 0) goto fail;
                if (t->n < v) goto fail;
            }
        } else {
            r = id;
            if (id >= t->n) {
            fail:
                r = -1;
            }
        }
    }
    return r;
}
}
