#include "../common/types.h"

extern "C" {
s32 func_002b6708(s32, s32, ...);

s32 func_002b792c(u32 a, u32 b, u32 c) {
    return func_002b6708(4, 27, a, b, c);
}

s32 func_002b7e74(u32 a, u32 b) {
    return func_002b6708(3, 45, b, a);
}
}
