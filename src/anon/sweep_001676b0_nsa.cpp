#include "../common/types.h"
extern f32 D_00349e10; extern f32 D_004f526c; extern f32 D_004f5270;
typedef struct S2 { s64 cur, trg, rel, rep; u8 pad[0x20]; f32 t; } S2;
void func_001676b0(S2* p, s64 v) {
    s64 x;
    p->rep = 0;
    x = p->cur ^ v;
    p->cur = v;
    p->trg = x & v;
    p->rel = x & ~v;
    if (p->trg) { p->t = D_004f526c; p->rep = p->trg; return; }
    if (v) {
        p->t -= D_00349e10;
        if (p->t <= 0.0f) { p->t = D_004f5270; p->rep = v; }
    }
}
