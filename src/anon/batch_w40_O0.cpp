#include "../common/types.h"

extern "C" {

s32 func_002b6708(s32, s32, s32, s32, s32, s32, s32);
s32 func_002b726c(s32 a, s32 b, s32 c, s32 d, s32 e) {
    if (d >= 14848) e = 64;
    return func_002b6708(6, 19, a, b, c, d, e);
}

struct S2b8984 { u8 pad[0x4801c]; u32 a; u32 b; };
s32 func_002b8984(S2b8984* p, u32 a, u32 b) {
    p->a = a;
    p->b = b;
    return 0;
}

}
