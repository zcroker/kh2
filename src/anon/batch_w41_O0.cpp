#include "../common/types.h"

extern "C" {
s32 func_002b6708(s32, s32, s32, s32, s32, s32, s32);
s32 func_002b7334(s32 a, s32 b, s32 c, s32 d, s32 e) {
    if (d >= 14848) e = 64;
    return func_002b6708(6, 21, a, b, c, d, e);
}
}
