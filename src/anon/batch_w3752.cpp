#include "../common/types.h"
static inline bool TB(u32* b, u32 i) { return (b[i >> 5] & (1 << (i & 31))) != 0; }
extern "C" {
s32 func_002a9d68();
extern s32 D_0035f610;

s32 func_002abce8(s32 x)
{
    s32 base = func_002a9d68();
    s32 r = 1;
    s32 k;
    if (x < 0) {
        for (s32 i = 0; i < 4; i++) {
            k = i;
            if (TB((u32*)(D_0035f610 + 320), k)) {
                r = TB((u32*)(base + 320), k);
                if (!r) break;
            }
        }
    } else {
        k = x;
        s32 t = 0;
        if (TB((u32*)(D_0035f610 + 320), k)) t = TB((u32*)(base + 320), k);
        r = t;
    }
    return r;
}
}
