/* 002231b8 (w3690): hand-written VU0 packet builder (VF regs preloaded by 00222f88, lb v0 scratch, nops,
   trapping add). The VU0 stretch stays one asm block; its end also loads the 128 clip-flag constant into t6
   (li $14,128), so gcc's p+608 lands in t7 and dbr puts it in the beq delay slot like the original.
   Asm share 132/142 instructions. */
#include "../common/types.h"
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Req {
    V4 a;           /* 00 position */
    V4 col;         /* 10 colour */
    void* p32;      /* 20 */
    u8* pkt;        /* 24 packet write pointer */
    void* p40;      /* 28 */
    s32 w44;        /* 2c */
    V4 b;           /* 30 */
};
extern "C" {

s32 func_002231b8(Req* r);  // 0x002231b8: definition moved into src/anon/unit_00222aa8.cpp


}
