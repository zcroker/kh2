/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"
/* libgcc2.c __floatdidf (gcc 3.2-ee-040921, soft-float double): GCC library code.
 * The soft-double libcalls bind to the game's copies. */
asm("dpadd = func_00313e80");
asm("dpmul = func_00313f40");
asm("litodp = func_00314330");

#define WORD_SIZE 32
#define HIGH_HALFWORD_COEFF (((u64) 1) << (WORD_SIZE / 2))
#define HIGH_WORD_COEFF (((u64) 1) << WORD_SIZE)

double func_003145a8(s64 u)
{
    double d;

    d = (s32) (u >> WORD_SIZE);
    d *= HIGH_HALFWORD_COEFF;
    d *= HIGH_HALFWORD_COEFF;
    d += (u32) (u & (HIGH_WORD_COEFF - 1));

    return d;
}
