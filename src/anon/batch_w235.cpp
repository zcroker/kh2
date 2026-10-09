#include "../common/types.h"

extern "C" {
f32 func_002f8a18(f32);
f32 func_002f8420(f32);
struct W235A { u8 p[76]; f32 w; f32 h; };
f32 func_00106f40(W235A* o, f32 x) {
    f32 a = 512.0f / o->w;
    f32 t = func_002f8a18(x * 0.5f);
    a = a * 0.5f;
    a = a / t;
    f32 b = 416.0f / o->h;
    b = b * 0.5f;
    b = b / a;
    f32 r = func_002f8420(b);
    return r + r;
}

struct W235B { u8 p[352]; u32 fl; u8 q[1060]; u32 fl2; u8 r[644]; W235B* o2064; u8 r2[712]; f32 f; };
s32 func_0016a040(W235B*);
static inline bool w235_pos(f32 x) { return 0.0f < x; }
s32 func_0019c170(W235B* o) {
    s32 r = 0;
    W235B* p;
    if (o->fl & 0x800000) goto set;
    p = o->o2064;
    if (p) {
        if (!(p->fl & 0x10000000)) {
            if (!(p->fl2 & 0x8000)) goto set;
        }
    }
    if (o->fl2 & 2) {
        bool b = w235_pos(o->f);
        if (b) goto set;
    }
    if (func_0016a040(o) == 15) {
        set:
        r = 1;
    }
    return r;
}
}
