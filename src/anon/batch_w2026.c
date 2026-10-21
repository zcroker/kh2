/* Third-party code notice: this file contains functions rebuilt to match the fdlibm / newlib
 * math library (s_fabs.c) that the game links, compiled with GCC 3.2-ee-040921 as plain C.
 * Copyright (C) 1993 by Sun Microsystems, Inc. Permission to use, copy, modify, and distribute
 * that software is freely granted, provided that this notice is preserved. It is not covered
 * by this project's MIT License. */
#include "../common/types.h"
typedef union { double value; struct { u32 lsw; u32 msw; } parts; } ieee_double_shape_type;

/* fabs(double): clear the sign bit of the high word (GET_HIGH_WORD / SET_HIGH_WORD). */
double func_002f83f0(double x) {
    u32 high;
    ieee_double_shape_type gh;
    gh.value = x;
    high = gh.parts.msw;
    {
        ieee_double_shape_type sh;
        sh.value = x;
        sh.parts.msw = high & 0x7fffffff;
        x = sh.value;
    }
    return x;
}
