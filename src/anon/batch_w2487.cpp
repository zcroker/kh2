#include "../common/types.h"
struct W1575Hdr { u16 f0, f2, f4, f6, lo, hi, max, fe, f10, f12, f14, f16; s32 off; };
struct W1575Obj { u8 pad[8]; s32 f8; };
extern "C" {
// Compare two resources: same header fields and the same set of valid table entries.
s32 func_00132338(W1575Obj*);
W1575Hdr* func_00132c68(W1575Obj*);
s32 func_00132ab0(W1575Obj* a, W1575Obj* b) {
    if (a == b) return 1;
    if (a->f8 != func_00132338(b)) return 0;
    W1575Hdr* x = func_00132c68(a);
    W1575Hdr* y = func_00132c68(b);
    if (!x) return 0;
    if (!y) return 0;
    if (x->f0 != y->f0) return 0;
    if (x->f2 != y->f2) return 0;
    if (x->max != y->max) return 0;
    if (x->lo != y->lo) return 0;
    if (x->hi != y->hi) return 0;
    if (x->f10 != y->f10) return 0;
    if (x->f12 != y->f12) return 0;
    if (x->f14 != y->f14) return 0;
    if (x->f16 != y->f16) return 0;
    u16* ta = (u16*)((u8*)x + x->off);
    u16* tb = (u16*)((u8*)y + y->off);
    for (u16 i = x->lo; i <= x->hi; i++) {
        u16 va = ta[i - x->lo];
        if (va != 0 && va <= x->max) {
            u16 vb = tb[i - y->lo];
            if (vb == 0 || vb > y->max) return 0;
        } else {
            u16 vb = tb[i - y->lo];
            if (vb != 0 && vb <= y->max) return 0;
        }
    }
    return 1;
}
}
