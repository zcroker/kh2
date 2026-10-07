#include "../common/types.h"

u32 wtarget_002b72e4(u32, u32, u32) asm("_Z16wtarget_002b72e4jjjj");

extern "C" {
u32 func_002b6708(u32, u32, ...);

u32 func_002b7ca4(u32 a, u32 b) {
    return func_002b6708(3, 30, a, b);
}
}

u32 wtarget_002b72e4(u32 a, u32 b, u32 c) {
    return func_002b6708(4, 20, a, b, c);
}
