/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc _df_to_sf (gcc 3.2-ee-040921), 0x3144b0-0x314508: df_to_sf (dptofp). Linked unit (linked_units.tsv). */
#include "fp-bit.h"

SFtype
df_to_sf (DFtype arg_a)
{
  fp_number_type in;
  USItype sffrac;
  FLO_union_type au;

  au.value = arg_a;
  unpack_d (&au, &in);

  sffrac = in.fraction.ll >> F_D_BITOFF;

  /* We set the lowest guard bit in SFFRAC if we discarded any non-zero
     bits.  */
  if ((in.fraction.ll & (((USItype) 1 << F_D_BITOFF) - 1)) != 0)
    sffrac |= 1;

  return __make_fp (in.class, in.sign, in.normal_exp, sffrac);
}
