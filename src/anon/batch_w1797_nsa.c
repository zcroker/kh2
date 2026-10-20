/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"
/* libgcc2.c __floatdisf (gcc 3.2-ee-040921, single float in hardware, double in software):
 * GCC library code. The soft-double libcalls bind to the game's copies. */
asm("dpadd = func_00313e80");
asm("dpmul = func_00313f40");
asm("litodp = func_00314330");
asm("dptofp = func_003144b0");

#define WORD_SIZE 32
#define HIGH_HALFWORD_COEFF (((u64) 1) << (WORD_SIZE / 2))
#define HIGH_WORD_COEFF (((u64) 1) << WORD_SIZE)
#define DI_SIZE 64
#define DF_SIZE 53
#define SF_SIZE 24
#define REP_BIT ((u64) 1 << (DI_SIZE - DF_SIZE))

float func_00311af0(s64 u)
{
    double f;

    if (DF_SIZE < DI_SIZE
        && DF_SIZE > (DI_SIZE - DF_SIZE + SF_SIZE))
    {
        if (! (- ((s64) 1 << DF_SIZE) < u
               && u < ((s64) 1 << DF_SIZE)))
        {
            if ((u64) u & (REP_BIT - 1))
                u |= REP_BIT;
        }
    }
    f = (s32) (u >> WORD_SIZE);
    f *= HIGH_HALFWORD_COEFF;
    f *= HIGH_HALFWORD_COEFF;
    f += (u32) (u & (HIGH_WORD_COEFF - 1));

    return (float) f;
}
