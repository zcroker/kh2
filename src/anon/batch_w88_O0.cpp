#include "../common/types.h"

extern "C" {
s32 func_002b9404(u32, u32, u32*, u16*);
s32 func_002b6708(u32, u32, s32, u32, u32, u32, u32, u32);

// Look up an entry; on success forward it to func_002b6708 (flag bit 0 forces 16383).
s32 func_002b95e8(u32 a, u32 b, u32 c, u32 d) {
    s32 r;
    u32 x;
    u16 fl;
    r = func_002b9404(a, b, &x, &fl);
    if (r < 0) return -1;
    if (fl & 1) c = 16383;
    return func_002b6708(7, 25, r, x, c, d, 1, 1);
}
}
