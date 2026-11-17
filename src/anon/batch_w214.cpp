#include "../common/types.h"
extern "C" {

// VU0 macro sequence (hand-written original): length of the vector at +0x20 scaled by a global factor.
void func_0019fb70(u32 a0, u8* a1);  // 0x0019fb70: definition moved into src/anon/unit_0019fb70.cpp

extern f32 func_001065a8();
struct W214O { u8 pad[24]; f32 f; };
void func_002deac0(W214O* o, f32 a, f32 b);  // 0x002deac0: definition moved into src/anon/unit_002de3c8.cpp

s32 func_002e64e8(u32 a0, u32 a1, u8* a2) {
    s32 n = *(s32*)(a2 + 12);
    a0 &= 0xff; a1 &= 0xff;
    s32 i = 0;
    u8* p = a2 + 16;
    if (n > 0) {
        s32 m = n; asm("" : "+r"(m));
        do {
            if (p[0] == a0) { if (p[1] == a1) return i; }
            i++;
            p += *(s32*)(p + 12);
        } while (i < m);
    }
    return -1;
}
}
