/* 001f6eb8: diff 0 ONLY with -O2 -fno-schedule-insns (verified with tools/mv.sh); under default -O2 diff 15-17
   (zero constant gets $f0 and x*y gets $f1: sched1 moves the y>0 compare above r=pi/2, so r and the
   zero pseudo stop conflicting). Same body as 001f6868 / 001f6eb8 / 002223f0 (three copies, own
   literal pools). Needs a Makefile rule *_nosched.c: CFLAGS += -fno-schedule-insns. Plain C. */
#include "../common/types.h"
double atan(double); /* atan */
double func_00313b80(f32) __attribute__((const));            /* __extendsfdf2 */
double func_00313e80(double, double) __attribute__((const)); /* __adddf3 */
double __subdf3(double, double) __attribute__((const)); /* __subdf3 */
f32 __truncdfsf2(double) __attribute__((const));            /* __truncdfsf2 */
typedef struct { f32 x, y; } V2_001f6eb8;
/* atan2 of (y, x) written into *out; returns 0 for (0, 0). */
s32 func_001f6eb8(V2_001f6eb8* p, f32* out) {
    f32 y = p->y; f32 x = p->x;
    f32 m = x * y;
    f32 r;
    if (m > 0.0f) {
        if (x > 0.0f) r = 0.0f; else r = -0x1.921fb4p+1f;
        r = __truncdfsf2(func_00313e80(func_00313b80(r), atan(func_00313b80(y / x))));
    } else if (m < 0.0f) {
        r = y > 0.0f ? 0x1.921fb4p+0f : -0x1.921fb4p+0f;
        r = __truncdfsf2(__subdf3(func_00313b80(r), atan(func_00313b80(x / y))));
    } else if (x != 0.0f) {
        if (x > 0.0f) r = 0.0f; else r = 0x1.921fb4p+1f;
    } else if (y != 0.0f) {
        r = y > 0.0f ? 0x1.921fb4p+0f : -0x1.921fb4p+0f;
    } else {
        return 0;
    }
    *out = r;
    return 1;
}
