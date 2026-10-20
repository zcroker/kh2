#include "../common/types.h"

extern "C" {
extern s32 D_00348808;
void func_00141c18(s32, s32, s32, s32, s32);
s32 func_00141ff0(s32, s32, s32, void*, s32);
s32 func_00143d10(s32 a, s32 b, u16* out, s32* flag) {
    s32 ret = 0;
    *flag = 0;
    if (D_00348808 != 0) {
        u16 buf[8];
        func_00141c18(D_00348808, 0, 0, 0, 0);
        if (func_00141ff0(D_00348808, a, b, buf, 15) != 0) {
            *flag = 0;
            *out = buf[0];
            ret = 1;
        }
        return ret;
    }
    return 0;
}
}
