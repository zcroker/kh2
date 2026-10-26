/* w2438 (zl90 retry batch). Plain C (the particle/partMng-style C modules). */
#include "../common/types.h"
extern s32 D_00352bec;
extern s32 D_00352bf0;

static inline int inr_001f4640(s32 v, s32 lo, s32 hi)
{
    if (v < lo) return 0;
    if (v > hi) return 0;
    return 1;
}

/* VU0 project + screen clip test. The __builtin_expect on the y < ymin test sets the block
   frequencies that make global-alloc give ymin<<4 t2 and ymax<<4 t3 like the original. */
s32 func_001f4640(f32* v, s32* o, f32* m)
{
    s32 cx = D_00352bec;
    s32 cy = D_00352bf0;
    s32 xmin, ymin, xmax, ymax, r;
    xmax = cx + 2048;
    xmin = 2048 - cx;
    ymax = cy + 2048;
    ymin = 2048 - cy;
    asm volatile(
        "lqc2 $vf12,0(%0)\n"
        "lqc2 $vf4,0(%2)\n"
        "lqc2 $vf5,16(%2)\n"
        "lqc2 $vf6,32(%2)\n"
        "lqc2 $vf7,48(%2)\n"
        "vmulax.xyzw ACC,$vf4,$vf12x\n"
        "vmadday.xyzw ACC,$vf5,$vf12y\n"
        "vmaddaz.xyzw ACC,$vf6,$vf12z\n"
        "vmaddw.xyzw $vf14,$vf7,$vf12w\n"
        "vdiv Q,$vf0w,$vf14w\n"
        "vmove.xyzw $vf15,$vf14\n"
        "vsub.w $vf15,$vf15,$vf15\n"
        "vwaitq\n"
        "vmulq.xyz $vf15,$vf15,Q\n"
        "vftoi4.xyz $vf15,$vf15\n"
        "sqc2 $vf15,0(%1)\n"
        : : "r"(v), "r"(o), "r"(m) : "memory");
    r = inr_001f4640(o[0], xmin << 4, xmax << 4);
    if (__builtin_expect(o[1] < (ymin << 4), 1)) r = 0;
    else if (o[1] > (ymax << 4)) r = 0;
    if (o[2] <= 0) r = 0;
    return r;
}
