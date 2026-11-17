/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc _df_to_usi (gcc 3.2-ee-040921), 0x314508-0x3145a8: float_to_usi (dptoul). Linked unit (linked_units.tsv). */
#include "fp-bit.h"

USItype
float_to_usi (FLO_type arg_a)
{
  fp_number_type a;
  FLO_union_type au;

  au.value = arg_a;
  unpack_d (&au, &a);

  if (iszero (&a))
    return 0;
  if (isnan (&a))
    return 0;
  /* it is a negative number */
  if (a.sign)
    return 0;
  /* get reasonable MAX_USI_INT...  */
  if (isinf (&a))
    return MAX_USI_INT;
  /* it is a number, but a small one */
  if (a.normal_exp < 0)
    return 0;
  if (a.normal_exp > BITS_PER_SI - 1)
    return MAX_USI_INT;
  else if (a.normal_exp > (FRACBITS + NGARDS))
    return a.fraction.ll << (a.normal_exp - (FRACBITS + NGARDS));
  else
    return a.fraction.ll >> ((FRACBITS + NGARDS) - a.normal_exp);
}
