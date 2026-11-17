/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc _pack_sf (gcc 3.2-ee-040921), 0x314930-0x3149e8: pack_d (SFmode, __pack_f). Linked unit (linked_units.tsv). */
#define FLOAT
#include "fp-bit.h"

FLO_type
pack_d (fp_number_type *src)
{
  FLO_union_type dst;
  fractype fraction = src->fraction.ll;
  int sign = src->sign;
  int exp = 0;

  if (isnan (src))
    {
      /* No NaN in single precision: the largest number.  */
      exp = EXPMAX;
      fraction = ((fractype) 1 << FRACBITS) - 1;
    }
  else if (isinf (src))
    {
      exp = EXPMAX;
      fraction = ((fractype) 1 << FRACBITS) - 1;
    }
  else if (iszero (src))
    {
      exp = 0;
      fraction = 0;
    }
  else if (fraction == 0)
    {
      exp = 0;
    }
  else
    {
      if (src->normal_exp < NORMAL_EXPMIN)
	{
	  exp = 0;
	  fraction = 0;
	}
      else
	{
	  exp = src->normal_exp + EXPBIAS;
	  fraction >>= NGARDS;
	  /* Saturate instead of overflowing to infinity.  */
	  if (exp > EXPMAX)
	    {
	      exp = EXPMAX;
	      fraction = ((fractype) 1 << FRACBITS) - 1;
	    }
	}
    }

  dst.bits.fraction = fraction;
  dst.bits.exp = exp;
  dst.bits.sign = sign;
  return dst.value;
}
