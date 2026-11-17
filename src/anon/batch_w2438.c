/* w2438 (helper retry batch). Plain C (the particle/partMng-style C modules). */
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
s32 func_001f4640(f32* v, s32* o, f32* m);  // 0x001f4640: definition moved into src/anon/unit_001f45f8.cpp
