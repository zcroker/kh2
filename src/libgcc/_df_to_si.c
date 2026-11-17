/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc _df_to_si (gcc 3.2-ee-040921), 0x3143e0-0x314480: float_to_si (dptoli). Linked unit (linked_units.tsv). */
#include "fp-bit.h"

SItype
float_to_si (FLO_type arg_a)
{
  fp_number_type a;
  SItype tmp;
  FLO_union_type au;

  au.value = arg_a;
  unpack_d (&au, &a);

  if (iszero (&a))
    return 0;
  if (isnan (&a))
    return 0;
  /* get reasonable MAX_SI_INT...  */
  if (isinf (&a))
    return a.sign ? (-MAX_SI_INT)-1 : MAX_SI_INT;
  /* it is a number, but a small one */
  if (a.normal_exp < 0)
    return 0;
  if (a.normal_exp > BITS_PER_SI - 2)
    return a.sign ? (-MAX_SI_INT)-1 : MAX_SI_INT;
  tmp = a.fraction.ll >> ((FRACBITS + NGARDS) - a.normal_exp);
  return a.sign ? (-tmp) : (tmp);
}
