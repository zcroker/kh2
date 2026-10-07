#include "../common/types.h"

extern "C" {
s32 func_003094b8(void*, s32, s32, void*, s32, void*, s32, s32, s32);
extern u8 D_01e22040;
extern u32 D_01e21f40[64];

// Retries an RPC call (send/receive through the same 256-byte buffer) until it succeeds.
u32 func_002b8434(u32 a) {
    s32 r;
    D_01e21f40[0] = a;
    do {
        r = func_003094b8(&D_01e22040, 3, 0, D_01e21f40, 256, D_01e21f40, 256, 0, 0);
    } while (r != 0);
    return a;
}
}
