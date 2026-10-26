/* Third-party code notice: this file contains a function rebuilt from newlib's libm
 * (libm/math/ef_sqrt.c, fdlibm), which the game links from the toolchain's libm.a.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely granted,
 * provided that this notice is preserved. It is not covered by this project's MIT License. */

/* 002faa10 is __ieee754_sqrtf (newlib ef_sqrt.c), byte-identical to ef_sqrt.o in the
 * toolchain's libm.a (/opt/ps2/gcc/ee/lib/libm.a). newlib's PS2 configuration has no
 * denormals and no Inf/NaN, so FLT_UWORD_IS_FINITE is 1 and FLT_UWORD_IS_SUBNORMAL is 0. */
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef union { float value; __uint32_t word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
#define FLT_UWORD_IS_FINITE(x) 1
#define FLT_UWORD_IS_ZERO(x) ((x)<0x00800000L)
#define FLT_UWORD_IS_SUBNORMAL(x) 0
static	const float	one	= 1.0, tiny=1.0e-30;

float func_002faa10(float x)
{
	float z;
	__uint32_t r,hx;
	__int32_t ix,s,q,m,t,i;

	GET_FLOAT_WORD(ix,x);
	hx = ix&0x7fffffff;

    /* take care of Inf and NaN */
	if(!FLT_UWORD_IS_FINITE(hx))
	    return x*x+x;		/* sqrt(NaN)=NaN, sqrt(+inf)=+inf
					   sqrt(-inf)=sNaN */

    /* take care of zero and -ves */
	if(FLT_UWORD_IS_ZERO(hx)) return x;/* sqrt(+-0) = +-0 */
	if(ix<0) return (x-x)/(x-x);		/* sqrt(-ve) = sNaN */

    /* normalize x */
	m = (ix>>23);
	if(FLT_UWORD_IS_SUBNORMAL(hx)) {		/* subnormal x */
	    for(i=0;(ix&0x00800000L)==0;i++) ix<<=1;
	    m -= i-1;
	}
	m -= 127;	/* unbias exponent */
	ix = (ix&0x007fffffL)|0x00800000L;
	if(m&1)	/* odd m, double x to make it even */
	    ix += ix;
	m >>= 1;	/* m = [m/2] */

    /* generate sqrt(x) bit by bit */
	ix += ix;
	q = s = 0;		/* q = sqrt(x) */
	r = 0x01000000L;		/* r = moving bit from right to left */

	while(r!=0) {
	    t = s+r;
	    if(t<=ix) {
		s    = t+r;
		ix  -= t;
		q   += r;
	    }
	    ix += ix;
	    r>>=1;
	}

    /* use floating add to find out rounding direction */
	if(ix!=0) {
	    z = one-tiny; /* trigger inexact flag */
	    if (z>=one) {
	        z = one+tiny;
		if (z>one)
		    q += 2;
		else
		    q += (q&1);
	    }
	}
	ix = (q>>1)+0x3f000000L;
	ix += (m <<23);
	SET_FLOAT_WORD(z,ix);
	return z;
}
