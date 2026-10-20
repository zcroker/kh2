#include "../common/types.h"
struct S2 { u16 a; u16 id; };
struct B { u8 pad[6]; u16 h; u8 pad2[4]; s32 v; };
struct A { u8 pad[0xb44]; B* b; };
extern "C" {
void func_00178bf0(A*, S2*);
void func_00178cf8(A*);
void func_00179648(A*, s32);
void func_001991a8(u32, s32);
void func_001a6e88(s32, A*, void*);
void func_001a70a0(s32, A*, void*);
void func_001a8778(s32, A*);
void func_00178ae8(A* a, S2* m) {
    switch (m->id) {
    case 0x1f:
        func_00178cf8(a);
        func_001a70a0(a->b->v + 0x500, a, &a->b->v);
        return;
    case 0x1e:
        func_00178cf8(a);
        func_001a6e88(a->b->v + 0x500, a, &a->b->v);
        return;
    case 0x7f:
        func_001991a8(a->b->h, 0);
        return;
    case 0x37:
        func_00179648(a, a->b->v);
        return;
    case 0x20:
        func_001a8778(a->b->v, a);
        return;
    default:
        func_00178bf0(a, m);
        return;
    }
}
}
