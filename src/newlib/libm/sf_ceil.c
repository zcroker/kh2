/* sf_ceil.c: newlib libm (libm/math/sf_ceil.c, fdlibm), the copy the game links from the toolchain's libm.a.
 * Linked unit 0x2f86f0-0x2f87c0, .rodata at 0x376f78. Built with ee-gcc 3.2 -O2 -G0 -fno-builtin (see fdlibm.h).
 * Third-party code notice: rebuilt to match; it is not covered by this project's MIT License.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely granted,
 * provided that this notice is preserved.
 */
#include "fdlibm.h"

static const float huge = 1.0e30;

float ceilf(float x)
{
	__int32_t i0,j0;
	__uint32_t i,ix;
	GET_FLOAT_WORD(i0,x);
	ix = (i0&0x7fffffff);
	j0 = (ix>>23)-0x7f;
	if(j0<23) {
	    if(j0<0) { 	/* raise inexact if x != 0 */
		if(huge+x>(float)0.0) {/* return 0*sign(x) if |x|<1 */
		    if(i0<0) {i0=0x80000000;}
		    else if(!FLT_UWORD_IS_ZERO(ix)) { i0=0x3f800000;}
		}
	    } else {
		i = (0x007fffff)>>j0;
		if((i0&i)==0) return x; /* x is integral */
		if(huge+x>(float)0.0) {	/* raise inexact flag */
		    if(i0>0) i0 += (0x00800000)>>j0;
		    i0 &= (~i);
		}
	    }
	} else {
	    if(!FLT_UWORD_IS_FINITE(ix)) return x+x; /* inf or NaN */
	    else return x;		/* x is integral */
	}
	SET_FLOAT_WORD(x,i0);
	return x;
}
