/* wf_exp.c: newlib libm (libm/math/wf_exp.c, fdlibm), the copy the game links from the toolchain's libm.a.
 * Linked unit 0x2f8ae8-0x2f8b00, .rodata at 0x376f8c. Built with ee-gcc 3.2 -O2 -G0 -fno-builtin (see fdlibm.h).
 * Third-party code notice: rebuilt to match; it is not covered by this project's MIT License.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely granted,
 * provided that this notice is preserved.
 */
#include "fdlibm.h"

static const float
o_threshold=  8.8721679688e+01,  /* 0x42b17180 */
u_threshold= -1.0397208405e+02;  /* 0xc2cff1b5 */

float expf(float x)
{
	return __ieee754_expf(x);
}
