#include "../common/types.h"
extern "C" {

/* matches only with -fno-strict-aliasing (last lui register) */
extern s32 D_0034af20;
extern u32 D_0034af24;
extern u64 D_0034af30;
void func_0015c228(s32* p)
{
    if (p == 0) {
        D_0034af24 = 0;
        D_0034af20 = 0;
        return;
    }
    D_0034af20 = (s32)p + p[0];
    D_0034af24 = (u32)p[1] / 104;
    D_0034af30 = 0;
}

}
