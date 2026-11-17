/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc _unpack_df (gcc 3.2-ee-040921), 0x3147a0-0x314830: unpack_d (DFmode). Linked unit (linked_units.tsv). */
#include "fp-bit.h"

void
unpack_d (FLO_union_type *src, fp_number_type *dst)
{
  fractype fraction;
  int exp;
  int sign;

  fraction = src->bits.fraction;
  exp = src->bits.exp;
  sign = src->bits.sign;

  dst->sign = sign;
  if (exp == 0)
    {
      /* No denormals: anything with a zero exponent is zero.  */
      dst->class = CLASS_ZERO;
    }
  else if (exp == EXPMAX)
    {
      /* Huge exponent*/
      if (fraction == 0)
	{
	  /* Attached to a zero fraction - means infinity */
	  dst->class = CLASS_INFINITY;
	}
      else
	{
	  /* Nonzero fraction, means nan */
	  if (fraction & QUIET_NAN)
	    {
	      dst->class = CLASS_QNAN;
	    }
	  else
	    {
	      dst->class = CLASS_SNAN;
	    }
	  /* Keep the fraction part as the nan number */
	  dst->fraction.ll = fraction;
	}
    }
  else
    {
      /* Nothing strange about this number */
      dst->normal_exp = exp - EXPBIAS;
      dst->class = CLASS_NUMBER;
      dst->fraction.ll = (fraction << NGARDS) | IMPLICIT_1;
    }
}
