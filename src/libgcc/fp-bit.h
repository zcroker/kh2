/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc fp-bit.c / dp-bit.c (gcc 3.2-ee-040921): software floating point, shared by the linked
 * units src/libgcc/_*_df.c and _*_sf.c (one per libgcc.a object, like the original fine-grained
 * build). The EE build is little-endian (FLOAT_BIT_ORDER_MISMATCH: bitfields), uses the GOFAST
 * names (dpadd, fptodp, ...), flushes denormals and does not round (results are truncated).
 * Single floats have no NaN or infinity (the largest exponent is a normal number).
 * Define FLOAT before including this for the SFmode objects. */
#ifndef LIBGCC_FP_BIT_H
#define LIBGCC_FP_BIT_H

typedef float SFtype __attribute__ ((mode (SF)));
typedef float DFtype __attribute__ ((mode (DF)));
typedef int SItype __attribute__ ((mode (SI)));
typedef int DItype __attribute__ ((mode (DI)));
typedef unsigned int USItype __attribute__ ((mode (SI)));
typedef unsigned int UDItype __attribute__ ((mode (DI)));
#define CMPtype SItype

#define MAX_USI_INT  (~(USItype)0)
#define MAX_SI_INT   ((SItype) (MAX_USI_INT >> 1))
#define BITS_PER_SI  32

#ifdef FLOAT
#	define NGARDS    7L
#	define EXPBITS 8
#	define EXPBIAS 127
#	define FRACBITS 23
#	define EXPMAX (0xff)
#	define FRAC_NBITS 32
	typedef USItype fractype;
	typedef SFtype FLO_type;
	typedef SItype intfrac;
#else
#	define NGARDS 8L
#	define EXPBITS 11
#	define EXPBIAS 1023
#	define FRACBITS 52
#	define EXPMAX (0x7ff)
#	define QUIET_NAN 0x8000000000000LL
#	define FRACHIGH  0x8000000000000000LL
#	define FRAC_NBITS 64
	typedef UDItype fractype;
	typedef DFtype FLO_type;
	typedef DItype intfrac;
#endif

/* GOFAST names (US_SOFTWARE_GOFAST). */
#define add		dpadd
#define sub		dpsub
#define multiply	dpmul
#define divide		dpdiv
#define compare		dpcmp
#define si_to_float	litodp
#define float_to_si	dptoli
#define df_to_sf	dptofp
#define sf_to_df	fptodp
#ifdef FLOAT
#	define float_to_usi	fptoui
#	define pack_d		__pack_f
#	define unpack_d		__unpack_f
#else
#	define float_to_usi	dptoul
#	define pack_d		__pack_d
#	define unpack_d		__unpack_d
#	define __fpcmp_parts	__fpcmp_parts_d
#endif

#define INLINE __inline__

/* Preserve the sticky-bit when shifting fractions to the right.  */
#define LSHIFT(a) { a = (a & 1) | (a >> 1); }

#define F_D_BITOFF (52+8-(23+7))
#define NORMAL_EXPMIN (-(EXPBIAS)+1)
#define IMPLICIT_1 ((fractype)1<<(FRACBITS+NGARDS))
#define IMPLICIT_2 ((fractype)1<<(FRACBITS+1+NGARDS))

typedef enum
{
  CLASS_SNAN,
  CLASS_QNAN,
  CLASS_ZERO,
  CLASS_NUMBER,
  CLASS_INFINITY
} fp_class_type;

typedef struct
{
  fp_class_type class;
  unsigned int sign;
  int normal_exp;
  union
    {
      fractype ll;
    } fraction;
} fp_number_type;

typedef union
{
  FLO_type value;
  fractype value_raw;
  struct
    {
      fractype fraction:FRACBITS __attribute__ ((packed));
      unsigned int exp:EXPBITS __attribute__ ((packed));
      unsigned int sign:1 __attribute__ ((packed));
    }
  bits;
}
FLO_union_type;

/* __thenan_df lives in its own object (_thenan_df.o, .rodata 0x378498). */
extern const fp_number_type __thenan_df;
asm ("__thenan_df = D_00378498");

INLINE static fp_number_type *
nan (void)
{
  return (fp_number_type *) (& __thenan_df);
}

INLINE static int
isnan (fp_number_type *x)
{
  return x->class == CLASS_SNAN || x->class == CLASS_QNAN;
}

INLINE static int
isinf (fp_number_type *x)
{
  return x->class == CLASS_INFINITY;
}

INLINE static int
iszero (fp_number_type *x)
{
  return x->class == CLASS_ZERO;
}

extern FLO_type pack_d (fp_number_type *);
extern void unpack_d (FLO_union_type *, fp_number_type *);
extern CMPtype __fpcmp_parts (fp_number_type *, fp_number_type *);
extern SFtype __make_fp (fp_class_type, unsigned int, int, USItype);
extern DFtype __make_dp (fp_class_type, unsigned int, int, UDItype);

#endif
