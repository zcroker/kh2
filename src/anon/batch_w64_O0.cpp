#include "../common/types.h"

extern "C" {

s32 func_002b9404(u32, u32, u32*, u32*);
s32 func_002b6708(s32, s32, s32);

s32 func_002b96a4(u32 a, u32 b) {
    s32 r;
    u32 x;
    u32 y;
    r = func_002b9404(a, b, &x, &y);
    if (r < 0) return -1;
    return func_002b6708(2, 26, r);
}

}
