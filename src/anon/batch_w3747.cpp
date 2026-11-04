// 00132d90: for(;;) makes the bnez a jump out of a loop, so reorg predicts it not taken and fills the slot from the fallthrough. h is pinned to $10 (partial asm).
#include "../common/types.h"
extern "C" {
typedef struct H6 { u8 pad[6]; u16 x6; u8 pad2[0x14 - 8]; u16 x14; u16 x16; u8 pad3[8]; s32 x20; } H6;
typedef struct O6 { u8 pad[0x27c]; u16* t; } O6;
H6* func_00132c68(O6*);
u8* func_00132d90(O6* o, s32 i) {
    register H6* h asm("$10") = func_00132c68(o);
    u8* r = 0;
    if (h) {
        u16* t;
t = o->t; if (t) for (;;) { if (t[0] & 0xf) break;             r = (u8*)h + (h->x20 + t[i + 3] * (((u32)(h->x14 * h->x6) >> 3) * h->x16));
 break; }
    }
    return r;
}
}

