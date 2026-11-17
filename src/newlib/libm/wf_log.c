/* wf_log.c: newlib libm (libm/math/wf_log.c, fdlibm), the copy the game links from the toolchain's libm.a.
 * Linked unit 0x2f8b18-0x2f8b30. Built with ee-gcc 3.2 -O2 -G0 -fno-builtin (see fdlibm.h).
 * Third-party code notice: rebuilt to match; it is not covered by this project's MIT License.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely granted,
 * provided that this notice is preserved.
 */
#include "fdlibm.h"

float logf(float x)
{
	return __ieee754_logf(x);
}
