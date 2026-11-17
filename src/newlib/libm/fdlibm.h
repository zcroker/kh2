/* fdlibm.h: the parts of newlib's libm/common/fdlibm.h that these objects use, for the toolchain's EE build
 * of libm.a: _IEEE_LIBM (the wrappers call the __ieee754 functions directly), _FLT_LARGEST_EXPONENT_IS_NORMAL
 * and _FLT_NO_DENORMALS (the R5900 FPU has no infinities, NaNs or denormals). The library was built with
 * -fno-builtin: fabs/fabsf are real calls. Each libm object is its own linked unit (one row each in
 * linked_units.tsv) because each has its own .rodata (static tables first, then gcc's literals).
 * Third-party code notice: not covered by this project's MIT License.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely granted,
 * provided that this notice is preserved.
 */
typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union { double value; struct { __uint32_t lsw; __uint32_t msw; } parts; } ieee_double_shape_type;
#define EXTRACT_WORDS(ix0,ix1,d) do { ieee_double_shape_type ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)
#define GET_HIGH_WORD(i,d) do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
#define GET_LOW_WORD(i,d) do { ieee_double_shape_type gl_u; gl_u.value = (d); (i) = gl_u.parts.lsw; } while (0)
#define INSERT_WORDS(d,ix0,ix1) do { ieee_double_shape_type iw_u; iw_u.parts.msw = (ix0); iw_u.parts.lsw = (ix1); (d) = iw_u.value; } while (0)
#define SET_HIGH_WORD(d,v) do { ieee_double_shape_type sh_u; sh_u.value = (d); sh_u.parts.msw = (v); (d) = sh_u.value; } while (0)
#define SET_LOW_WORD(d,v) do { ieee_double_shape_type sl_u; sl_u.value = (d); sl_u.parts.lsw = (v); (d) = sl_u.value; } while (0)

typedef union { float value; __uint32_t word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)

/* EE build: _FLT_LARGEST_EXPONENT_IS_NORMAL and _FLT_NO_DENORMALS. */
#define FLT_UWORD_IS_FINITE(x) 1
#define FLT_UWORD_IS_NAN(x) 0
#define FLT_UWORD_IS_INFINITE(x) 0
#define FLT_UWORD_MAX 0x7fffffff
#define FLT_UWORD_EXP_MAX 0x43010000
#define FLT_UWORD_LOG_MAX 0x42b2d4fc
#define FLT_UWORD_LOG_2MAX 0x42b437e0
#define FLT_UWORD_IS_ZERO(x) ((x)<0x00800000L)
#define FLT_UWORD_IS_SUBNORMAL(x) 0
#define FLT_UWORD_MIN 0x00800000
#define FLT_UWORD_EXP_MIN 0x42fc0000
#define FLT_UWORD_LOG_MIN 0x42aeac50
#define FLT_SMALLEST_EXP 1
#define FLT_UWORD_HALF_MAX (FLT_UWORD_MAX-(1L<<23))
#define FLT_LARGEST_EXP (FLT_UWORD_MAX>>23)

double __ieee754_sqrt(double);
float __ieee754_acosf(float);
float __ieee754_asinf(float);
float __ieee754_atan2f(float,float);
float __ieee754_expf(float);
float __ieee754_fmodf(float,float);
float __ieee754_logf(float);
float __ieee754_powf(float,float);
float __ieee754_sqrtf(float);
__int32_t __ieee754_rem_pio2f(float,float*);
float __kernel_sinf(float,float,int);
float __kernel_cosf(float,float);
float __kernel_tanf(float,float,int);
int __kernel_rem_pio2f(float*,float*,int,int,int,const __int32_t*);
float fabsf(float);
float scalbnf(float,int);
float copysignf(float,float);
float floorf(float);
float atanf(float);
