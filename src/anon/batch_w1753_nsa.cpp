#include "../common/types.h"

struct W1753Obj { u8 pad[48]; u8 m30[16]; f32 f40; f32 f44; u32 w48; };
struct W1753Rec { u32 p; u32 v; void* fn; f32 b; f32 a; void* q; };

extern "C" {
void func_0021f620(W1753Rec*, u32);
extern u8 D_01d9e8c0;

// Needs -fno-strict-aliasing for the original store order.
void func_001fb6c8(W1753Obj* o) {
    W1753Rec r;
    r.a = o->f40;
    r.p = (u32)o;
    r.v = o->w48;
    r.b = o->f44;
    r.fn = &D_01d9e8c0;
    r.q = o->m30;
    func_0021f620(&r, 0);
}
}
