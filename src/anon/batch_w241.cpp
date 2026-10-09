#include "../common/types.h"
extern "C" {
u32 func_001b9bc8(u32);
u32 func_0016bba8(u32, u32, u32);
void func_0018a818(u8*, u32, u32);
s32 func_0016c3a8(u8* arr, s32 n) {
    s32 cnt = 0;
    u32 it = 0;
    while ((it = func_001b9bc8(it))) {
        u8* dst = (u8*)((cnt << 5) + (u32)arr);
        u32 x = 0;
        while ((x = func_0016bba8(it, 18, x)) != 0) {
            func_0018a818(dst, it, x);
            dst += 32;
            cnt++;
            if (cnt >= n) return cnt;
        }
    }
    return cnt;
}
}
