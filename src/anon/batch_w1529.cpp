#include "../common/types.h"

extern "C" {
void func_002ef028(f32, void*);
void func_0011ea40(s32, f32);
void func_0011c4e8(s32, void*, s32, s32, s32, s32, f32);
s32 func_0019ba60(void*);
void func_0019d358(s32);
s32 func_001871c8(s32, s32, f32);
extern u8* D_0034e948;
extern f32 D_00349e10;

struct W1529Sub { u8 pad[8]; s32 x8; u8 p2[4]; f32 x10; };
struct W1529Obj { u8 pad[0x44]; s32 x44; u8 p2[0x150 - 0x48]; u8 x150[0x78]; W1529Sub s; };

s32 func_002eedf0(W1529Obj* p) {
    f32 t = D_00349e10;
    W1529Sub* s = &p->s;
    func_002ef028(t, s);
    func_0011ea40(p->x44, t);
    f32 y = s->x10;
    s32 x = s->x8;
    func_0011c4e8(p->x44, p->x150, x, 0, 0, 0, y);
    return 1;
}

s32 func_00187420(s32 a, f32 f) {
    u8* s = D_0034e948;
    s32 ok = func_0019ba60(s);
    s32 r = 0;
    if (ok != 0) {
        if (*(s32*)(s + 0xb40) != 0) {
            func_0019d358(*(s32*)(s + 0xb40));
            r = func_001871c8(a, *(s32*)(s + 0xb40) + 4, f);
        }
    }
    return r;
}
}
