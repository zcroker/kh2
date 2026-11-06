#include "../common/types.h"
extern u8* D_0035f2e4;
extern "C" {
u8* func_002859a0(void);
s32 func_002813b8(void);
s32 func_0027aa78(void);

// Returns 0 if any bit that is set in D_0035f2e4's 48-bit-per-slot table (slots 1..7, 6 skipped,
// filtered by a0/a1 when >= 0) is clear in func_002859a0()'s table; 1 otherwise.
s32 func_00287218(s32 a0, s32 a1) {
    u8* p = func_002859a0();
    s32 bits = func_002813b8();
    s32 ret = 1;
    s32 i, k, j;
    u8* q;
    if (func_0027aa78()) bits |= 0x80;
    q = D_0035f2e4;
    for (i = 1, j = 0; i < 8; i++, j++) {
        u8 clr;
        if (i == 6) { j--; continue; }
        if (a0 >= 0 && i != a0) continue;
        clr = !((bits >> i) & 1);
        if (clr) continue;
        {
            k = 0;
            s32 off = j * 48;
            u32* qa = (u32*)(q + 164);
            for (; k < 48; k++) {
                u32 b;
                u32 m;
                if (a1 >= 0 && k != a1) continue;
                b = off + k;
                m = 1 << (b & 31);
                if (qa[b >> 5] & m) {
                    u32* pa = (u32*)(p + 164);
                    ret = (pa[b >> 5] & m) != 0;
                    if (!ret) break;
                }
            }
        }
        if (!ret) break;
    }
    return ret;
}
}
