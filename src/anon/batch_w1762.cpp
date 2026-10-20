#include "../common/types.h"

struct T9_1762 { u8 pad[8]; u32 f:1; bool F() { return f; } };
struct RB1762 { u32 r0:24; u32 r24:1; u32 r25:7; };
struct T10_1762 {
    u8 pad[12]; T9_1762* p; u8 pad2[0x108 - 16];
    u32 q0:23; u32 q23:1; u32 q24:8;
    u8 p3[0x160 - 0x10c];
    u32 r0:5; u32 r5:1; u32 r6:18; u32 r24:1; u32 r25:7;
    // r24 read through a second view so gcc does not merge the two bit tests into one mask.
    bool A() { bool b = false; if (r5 || ((RB1762*)&p3[0x160 - 0x10c])->r24) b = true; return b; }
};

extern "C" {
s32 func_0019c090(T10_1762* a0) {
    s32 r = 0;
    if (a0->p->F() || a0->A() || a0->q23) r = 1;
    return r;
}
}
