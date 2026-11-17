/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc _sf_to_df (gcc 3.2-ee-040921), 0x313b80-0x313bc0: sf_to_df (fptodp). Linked unit (linked_units.tsv). */
#define FLOAT
#include "fp-bit.h"

DFtype
sf_to_df (SFtype arg_a)
{
  fp_number_type in;
  FLO_union_type au;

  au.value = arg_a;
  unpack_d (&au, &in);

  return __make_dp (in.class, in.sign, in.normal_exp,
		    ((UDItype) in.fraction.ll) << F_D_BITOFF);
}
