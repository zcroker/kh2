#include "../common/types.h"
typedef struct { s32 lvl; s32 id; } W1572_Cand;
extern u32 D_003638d0;
s32 func_0019ba60(s32) __asm__("_Z16ctarget_0019ba60jjjj");
u64 func_00312db8(u64, u64);
static inline u8 W1572_Invalid(s32 id) {
    u8 r = 0;
    if (id == 0 || func_0019ba60(id) == 0) r = 1;
    return r;
}
s32 func_001cd7a8(W1572_Cand* arg) {
    s32 n = 0;
    W1572_Cand c[8];
    s32 i;
    { W1572_Cand* q = c; s32 k = 7; do { q->id = 0; q++; } while (--k != -1); }
    for (i = 0; i < 8; i++) {
        if (W1572_Invalid(arg[i].id)) continue;
        if (func_0019ba60(arg[i].id) == 0) continue;
        if (arg[i].lvl == 0) return arg[i].id;
        if (W1572_Invalid(c[0].id) || arg[i].lvl < c[0].lvl) {
            c[0] = arg[i];
            n = 1;
        } else if (c[0].lvl == arg[i].lvl) {
            c[n++] = arg[i];
        }
    }
    if (n > 0) {
        u32 r;
        u64 d;
        r = D_003638d0 * 0x10dcd;
        D_003638d0 = r;
        d = func_00312db8((u64)(u32)(n - 1) + 0x100000000ULL, (u64)(u32)n);
        return c[(s32)func_00312db8((u64)r, d)].id;
    }
    return 0;
}
