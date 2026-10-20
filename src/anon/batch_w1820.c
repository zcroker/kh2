/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"
/* libgcc2.c __fixunsdfdi (gcc 3.2-ee-040921, soft double): GCC library code.
 * The soft-double libcalls bind to the game's copies. */
asm("dpcmp = func_003142e0");
asm("dpmul = func_00313f40");
asm("dpsub = func_00313ed8");
asm("dpadd = func_00313e80");
asm("dptoul = func_00314508");
asm("__floatdidf = func_003145a8");

#define WORD_SIZE 32
#define HIGH_WORD_COEFF (((u64) 1) << WORD_SIZE)

u64 func_00311bb8(double a)
{
    double b;
    u64 v;

    if (a < 0)
        return 0;

    /* Compute high word of result, as a flonum.  */
    b = (a / HIGH_WORD_COEFF);
    /* Convert that to fixed (but not to DWtype!), and shift it into the high word.  */
    v = (u32) b;
    v <<= WORD_SIZE;
    /* Remove high part from the DFtype, leaving the low part as flonum.  */
    a -= (double) v;
    /* Convert that to fixed and add it in. Sometimes A comes out negative.  */
    if (a < 0)
        v -= (u32) (- a);
    else
        v += (u32) a;
    return v;
}
