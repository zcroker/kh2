#include "../common/types.h"
struct W2029_O68 { u8 p0[8]; u8* f8; u16* fc; u8 p10[4]; u8* f14; u32 f18; u8 p1c[0x4c]; s32 f68; };
extern "C" {
void func_00237698(W2029_O68* o, s32 n) {
    if (o->f68 != n) {
        u16* e = o->fc + n * 2;
        o->f68 = n;
        o->f14 = o->f8 + e[0] * 0x14;
        o->f18 = e[1];
    }
}
}
