// Built with -fno-strict-aliasing (see Makefile *_nsa rule).
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
struct BPkt { u32 a, b; u128* p; };
struct BObj {
    u8 pad0[4];
    u16 w, h;
    s16 x, y;
    u32 z;
    u8 r, g, b, a;
    u8 pad14[0xc];
    u128 q20[13];
    u8 padf0[0x10];
    u128 q100[2];
    u128 q120[2];
    s16 sx, sy;
    u16 sw, sh;
};
extern "C" {
void func_001b7e68(BPkt*, s32);
void func_001b80d8(BPkt*);
void func_001b7f30(BPkt*);

void func_0014bb30(BObj* o);  // 0x0014bb30: definition moved into src/anon/unit_0014b838.cpp
}
