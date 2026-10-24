/* Third-party code notice: this file contains a function rebuilt from newlib's libm
 * (libm/math/ef_fmod.c, fdlibm), which the game links from the toolchain's libm.a.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely granted,
 * provided that this notice is preserved. It is not covered by this project's MIT License. */

/* 002f9a38 is __ieee754_fmodf (newlib ef_fmod.c, R5900 build: no infinities/NaNs/denormals),
 * byte-identical to ef_fmod.o in the toolchain's libm.a. */
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef union { float value; __uint32_t word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
#define FLT_UWORD_IS_FINITE(x) 1
#define FLT_UWORD_IS_NAN(x) 0
#define FLT_UWORD_IS_ZERO(x) ((x)<0x00800000L)
#define FLT_UWORD_IS_SUBNORMAL(x) 0

/* __ieee754_fmodf; the game symbol is a C++-style placeholder name, bound with an asm label. */
float wtarget_002f9a38(float x, float y) __asm__("_Z16wtarget_002f9a38jjjj");

static const float one = 1.0;
/* Zero[] = {0.0, -0.0} is the original table at 0x377140 */
extern const float D_00377140[];
#define Zero D_00377140

float wtarget_002f9a38(float x, float y)
{
	__int32_t n,hx,hy,hz,ix,iy,sx,i;

	GET_FLOAT_WORD(hx,x);
	GET_FLOAT_WORD(hy,y);
	sx = hx&0x80000000;
	hx ^=sx;
	hy &= 0x7fffffff;

	if(FLT_UWORD_IS_ZERO(hy)||
	   !FLT_UWORD_IS_FINITE(hx)||
	   FLT_UWORD_IS_NAN(hy))
	    return (x*y)/(x*y);
	if(hx<hy) return x;
	if(hx==hy)
	    return Zero[(__uint32_t)sx>>31];

	if(FLT_UWORD_IS_SUBNORMAL(hx)) {
	    for (ix = -126,i=(hx<<8); i>0; i<<=1) ix -=1;
	} else ix = (hx>>23)-127;

	if(FLT_UWORD_IS_SUBNORMAL(hy)) {
	    for (iy = -126,i=(hy<<8); i>=0; i<<=1) iy -=1;
	} else iy = (hy>>23)-127;

	if(ix >= -126)
	    hx = 0x00800000|(0x007fffff&hx);
	else {
	    n = -126-ix;
	    hx = hx<<n;
	}
	if(iy >= -126)
	    hy = 0x00800000|(0x007fffff&hy);
	else {
	    n = -126-iy;
	    hy = hy<<n;
	}

	n = ix - iy;
	while(n--) {
	    hz=hx-hy;
	    if(hz<0){hx = hx+hx;}
	    else {
	    	if(hz==0)
		    return Zero[(__uint32_t)sx>>31];
	    	hx = hz+hz;
	    }
	}
	hz=hx-hy;
	if(hz>=0) {hx=hz;}

	if(hx==0)
	    return Zero[(__uint32_t)sx>>31];
	while(hx<0x00800000) {
	    hx = hx+hx;
	    iy -= 1;
	}
	if(iy>= -126) {
	    hx = ((hx-0x00800000)|((iy+127)<<23));
	    SET_FLOAT_WORD(x,hx|sx);
	} else {
	    n = -126 - iy;
	    hx >>= n;
	    SET_FLOAT_WORD(x,hx|sx);
	    x *= one;
	}
	return x;
}
