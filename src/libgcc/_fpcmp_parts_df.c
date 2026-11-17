/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc _fpcmp_parts_df (gcc 3.2-ee-040921), 0x314830-0x314930: __fpcmp_parts_d. Linked unit (linked_units.tsv). */
#include "fp-bit.h"

int
__fpcmp_parts (fp_number_type * a, fp_number_type * b)
{
  if (isnan (a) || isnan (b))
    {
      return 1;			/* how to indicate unordered compare? */
    }
  if (isinf (a) && isinf (b))
    {
      /* +inf > -inf, but +inf != +inf */
      return b->sign - a->sign;
    }
  /* but not both...  */
  if (isinf (a))
    {
      return a->sign ? -1 : 1;
    }
  if (isinf (b))
    {
      return b->sign ? 1 : -1;
    }
  if (iszero (a) && iszero (b))
    {
      return 0;
    }
  if (iszero (a))
    {
      return b->sign ? 1 : -1;
    }
  if (iszero (b))
    {
      return a->sign ? -1 : 1;
    }
  /* now both are "normal".  */
  if (a->sign != b->sign)
    {
      /* opposite signs */
      return a->sign ? -1 : 1;
    }
  /* same sign; exponents? */
  if (a->normal_exp > b->normal_exp)
    {
      return a->sign ? -1 : 1;
    }
  if (a->normal_exp < b->normal_exp)
    {
      return a->sign ? 1 : -1;
    }
  /* same exponents; check size.  */
  if (a->fraction.ll > b->fraction.ll)
    {
      return a->sign ? -1 : 1;
    }
  if (a->fraction.ll < b->fraction.ll)
    {
      return a->sign ? 1 : -1;
    }
  /* after all that, they're equal.  */
  return 0;
}
