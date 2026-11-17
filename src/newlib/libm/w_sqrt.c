/* w_sqrt.c: newlib libm (libm/math/w_sqrt.c, fdlibm), the copy the game links from the toolchain's libm.a.
 * Linked unit 0x2f8a88-0x2f8aa0. Built with ee-gcc 3.2 -O2 -G0 -fno-builtin (see fdlibm.h).
 * Third-party code notice: rebuilt to match; it is not covered by this project's MIT License.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely granted,
 * provided that this notice is preserved.
 */
#include "fdlibm.h"

double sqrt(double x)
{
	return __ieee754_sqrt(x);
}
