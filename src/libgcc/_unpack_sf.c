/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc _unpack_sf (gcc 3.2-ee-040921), 0x314640-0x314698: unpack_d (SFmode, __unpack_f). Linked unit (linked_units.tsv). */
#define FLOAT
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
      dst->class = CLASS_ZERO;
    }
  else
    {
      /* The largest exponent is a normal number too.  */
      dst->normal_exp = exp - EXPBIAS;
      dst->class = CLASS_NUMBER;
      dst->fraction.ll = (fraction << NGARDS) | IMPLICIT_1;
    }
}
