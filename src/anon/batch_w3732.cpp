#include "../common/types.h"
extern "C" {
s32 func_00139d78(u8*);
extern u8* D_0035f038;

// 002577b0: runs check func_00139d78 over every slot of the D_0035f038 block (7 singles, then 24 rows of 4);
// returns the first nonzero result. The loop result lives in its own variable and leaves by break: that keeps
// a return copy at the loop exit until register allocation, so the exits lose their loop-exit mark and reorg
// fills them from the epilogue (bnezl + ld s0) like the original.
s32 func_002577b0(void) {
    s32 i;
    s32 r = 0;
    s32 t;
    if (D_0035f038) {
        r = func_00139d78(D_0035f038);
        if (r) return r;
        r = func_00139d78(D_0035f038 + 0x198);
        if (r) return r;
        r = func_00139d78(D_0035f038 + 0x330);
        if (r) return r;
        r = func_00139d78(D_0035f038 + 0x4c8);
        if (r) return r;
        r = func_00139d78(D_0035f038 + 0x660);
        if (r) return r;
        r = func_00139d78(D_0035f038 + 0x814);
        if (r) return r;
        r = func_00139d78(D_0035f038 + 0x9c8);
        if (r) return r;
        for (i = 0; i < 24; i++) {
            t = func_00139d78(D_0035f038 + i * 0x1b4 + 0xd30);
            if (t) break;
            t = func_00139d78(D_0035f038 + i * 0x1b4 + 0x3610);
            if (t) break;
            t = func_00139d78(D_0035f038 + i * 0x1b4 + 0x5ef0);
            if (t) break;
            t = func_00139d78(D_0035f038 + i * 0x198 + 0x87d0);
            if (t) break;
        }
        return t;
    }
    return r;
}
}
