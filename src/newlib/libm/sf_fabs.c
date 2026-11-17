/* sf_fabs.c: newlib libm (libm/math/sf_fabs.c, fdlibm), the copy the game links from the toolchain's libm.a.
 * Linked unit 0x2f8870-0x2f8888. Built with ee-gcc 3.2 -O2 -G0 -fno-builtin (see fdlibm.h).
 * Third-party code notice: rebuilt to match; it is not covered by this project's MIT License.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely granted,
 * provided that this notice is preserved.
 */
#include "fdlibm.h"

float fabsf(float x)
{
	__uint32_t ix;
	GET_FLOAT_WORD(ix,x);
	SET_FLOAT_WORD(x,ix&0x7fffffff);
        return x;
}
