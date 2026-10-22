#include "../common/types.h"
extern "C" {
s32 Jm_GetSram_w8028(void) asm("_ZN2Tz9JmNewInfo7GetSramEv");
s32 Jm_GetData_w8028(s32) asm("_ZN2Tz6JmInfo7GetDataEi");
u32 func_002abf40(s32, s32);
extern s32 D_0035f610;

s32 func_002ac110(s32 a, s32 id) {
    s32 base = Jm_GetSram_w8028();
    s32 r = 1;
    s32 t = Jm_GetData_w8028(1);
    if (id < 0) {
        s32 i;
        for (i = 0; i < *(s32*)(t + 8); i++) {
            s32 bit = func_002abf40(a, i);
            if (bit >= 0) {
                s32 q = D_0035f610 + a * 4;
                q += ((u32)bit >> 5) * 4;
                u32 m = 1 << (bit & 0x1f);
                if (*(u32*)(q + 0xac) & m) {
                    s32 q2 = base + a * 4;
                    q2 += ((u32)bit >> 5) * 4;
                    r = (*(u32*)(q2 + 0xac) & m) != 0;
                    if (!r) return r;
                }
            }
        }
    } else {
        id = func_002abf40(a, id);
        u32 m = 1 << (id & 0x1f);
        s32 q = D_0035f610 + a * 4;
        q += ((u32)id >> 5) * 4;
        s32 k = 0;
        if (*(u32*)(q + 0xac) & m) {
            s32 q2 = base + a * 4;
            q2 += ((u32)id >> 5) * 4;
            k = (*(u32*)(q2 + 0xac) & m) != 0;
        }
        r = k;
    }
    return r;
}
}
