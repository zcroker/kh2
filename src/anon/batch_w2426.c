/* Third-party code notice: this file contains a function rebuilt from newlib's libm
 * (libm/math/ef_asin.c, fdlibm), which the game links from the toolchain's libm.a.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely granted,
 * provided that this notice is preserved. It is not covered by this project's MIT License. */

/* 002f9268 is __ieee754_asinf (newlib ef_asin.c), byte-identical to ef_asin.o in the
 * toolchain's libm.a. Callees: fabsf (0x2f8870) and __ieee754_sqrtf (0x2faa10). */
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef union { float value; __uint32_t word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)

float fabsf(float) asm("func_002f8870");
float __ieee754_sqrtf(float) asm("_Z13func_002faa10f");

/* __ieee754_asinf; the game symbol is a C++-style placeholder name, bound with an asm label. */
float func_002f9268(float x) asm("_Z13func_002f9268Pv");

static const float
one = 1.000000000e+00f,
huge = 9.999999395e+29f,
pio2_hi = 1.570796371e+00f,
pio2_lo = -4.371138829e-08f,
pio4_hi = 7.853981853e-01f,
pS0 = 1.666666567e-01f,
pS1 = -3.255657852e-01f,
pS2 = 2.012125254e-01f,
pS3 = -4.005553573e-02f,
pS4 = 7.915350143e-04f,
pS5 = 3.479330917e-05f,
qS1 = -2.403394699e+00f,
qS2 = 2.020945549e+00f,
qS3 = -6.882839203e-01f,
qS4 = 7.703814656e-02f;

float func_002f9268(float x)
{
	float t,w,p,q,c,r,s;
	__int32_t hx,ix;
	GET_FLOAT_WORD(hx,x);
	ix = hx&0x7fffffff;
	if(ix==0x3f800000) {
	    return x*pio2_hi+x*pio2_lo;
	} else if(ix> 0x3f800000) {
	    return (x-x)/(x-x);
	} else if (ix<0x3f000000) {
	    if(ix<0x32000000) {
		if(huge+x>one) return x;
	    } else {
		t = x*x;
		p = t*(pS0+t*(pS1+t*(pS2+t*(pS3+t*(pS4+t*pS5)))));
		q = one+t*(qS1+t*(qS2+t*(qS3+t*qS4)));
		w = p/q;
		return x+x*w;
	    }
	}
	w = one-fabsf(x);
	t = w*(float)0.5;
	p = t*(pS0+t*(pS1+t*(pS2+t*(pS3+t*(pS4+t*pS5)))));
	q = one+t*(qS1+t*(qS2+t*(qS3+t*qS4)));
	s = __ieee754_sqrtf(t);
	if(ix>=0x3F79999A) {
	    w = p/q;
	    t = pio2_hi-((float)2.0*(s+s*w)-pio2_lo);
	} else {
	    __int32_t iw;
	    w  = s;
	    GET_FLOAT_WORD(iw,w);
	    SET_FLOAT_WORD(w,iw&0xfffff000);
	    c  = (t-w*w)/(s+w);
	    r  = p/q;
	    p  = (float)2.0*s*r-(pio2_lo-(float)2.0*c);
	    q  = pio4_hi-(float)2.0*w;
	    t  = pio4_hi-(p-q);
	}
	if(hx>0) return t; else return -t;
}
