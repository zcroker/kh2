#include "../common/types.h"
extern "C" {
s32 func_002b6708(s32, s32, s32, s32, s32, s32);
// Forwards to func_002b6708(5, 29, ...), capping d at 64 for large c.
s32 func_002b7c34(s32 a, s32 b, s32 c, s32 d) {
    if (c >= 14848) d = 64;
    return func_002b6708(5, 29, a, b, c, d);
}
}
