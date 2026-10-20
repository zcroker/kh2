#include "../common/types.h"
extern "C" {
struct W216Obj { char p[0x24]; s32 cnt; char q[0x30]; float f58; };
struct W216Holder { s32 p0; W216Obj* o; };
s32 func_001317a8(W216Holder* a, float x) {
    W216Obj* o = a->o;
    float v = x * o->f58 / 60.0f + 0.5f;
    s32 r = (s32)v;
    if (r < 0) r = 0;
    if (r >= o->cnt) r = o->cnt - 1;
    return r;
}

struct W216Pair { s16 k; s16 v; };
extern W216Pair D_00374a08[];
s32 func_0029e7b0(s32 k) {  // short_table_lookup
    s32 r = -1;
    for (s32 i = 0; D_00374a08[i].k > 0; i++) {
        if (D_00374a08[i].k == k) { r = D_00374a08[i].v; break; }
    }
    return r;
}
}
