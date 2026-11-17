/* sf_scalbn.c: newlib libm (libm/math/sf_scalbn.c, fdlibm), the copy the game links from the toolchain's libm.a.
 * Linked unit 0x2fb850-0x2fb900, .rodata at 0x377808. Built with ee-gcc 3.2 -O2 -G0 -fno-builtin (see fdlibm.h).
 * Third-party code notice: rebuilt to match; it is not covered by this project's MIT License.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely granted,
 * provided that this notice is preserved.
 */
#include "fdlibm.h"

static const float
two25   =  3.355443200e+07,	/* 0x4c000000 */
twom25  =  2.9802322388e-08,	/* 0x33000000 */
huge   = 1.0e+30,
tiny   = 1.0e-30;

float scalbnf (float x, int n)
{
	__int32_t  k,ix;
	__uint32_t hx;

	GET_FLOAT_WORD(ix,x);
	hx = ix&0x7fffffff;
        k = hx>>23;		/* extract exponent */
	if (FLT_UWORD_IS_ZERO(hx))
	    return x;
        if (!FLT_UWORD_IS_FINITE(hx))
	    return x+x;		/* NaN or Inf */
        if (FLT_UWORD_IS_SUBNORMAL(hx)) {
	    x *= two25;
	    GET_FLOAT_WORD(ix,x);
	    k = ((ix&0x7f800000)>>23) - 25;
            if (n< -50000) return tiny*x; 	/*underflow*/
        }
        k = k+n;
        if (k > FLT_LARGEST_EXP) return huge*copysignf(huge,x); /* overflow  */
        if (k > 0) 				/* normal result */
	    {SET_FLOAT_WORD(x,(ix&0x807fffff)|(k<<23)); return x;}
        if (k < FLT_SMALLEST_EXP) {
            if (n > 50000) 	/* in case integer overflow in n+k */
		return huge*copysignf(huge,x);	/*overflow*/
	    else return tiny*copysignf(tiny,x);	/*underflow*/
        }
        k += 25;				/* subnormal result */
	SET_FLOAT_WORD(x,(ix&0x807fffff)|(k<<23));
        return x*twom25;
}
