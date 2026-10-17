#include "../common/types.h"
extern "C" {
struct W1590Obj;
struct W1590VT { void* f[5]; void (*fn)(W1590Obj*); };
struct W1590Obj { W1590VT* vt; };
s32 func_00139d78(W1590Obj*);
extern W1590Obj* D_0035f078;
extern W1590Obj* D_0035f07c;
void func_00281f48(s32, s32, s32);
s32 func_00281fe0(s32, s32, s32);
void func_002822c0(s32, s32, s32);
void func_002823b0(s32, s32, s32);

void func_002589b0(void) {
    if (D_0035f07c && func_00139d78(D_0035f07c)) {
        D_0035f07c->vt->fn(D_0035f07c);
    }
    if (D_0035f078 && func_00139d78(D_0035f078)) {
        D_0035f078->vt->fn(D_0035f078);
    }
}

void func_00282240(s32 a, s32 b, s32 c) {
    s32 r;
    func_00281f48(a, b, c);
    r = func_00281fe0(a, b, c);
    if (b < 5) {
        func_002822c0(a, b, r);
    } else {
        func_002823b0(a, b, r);
    }
}
}
