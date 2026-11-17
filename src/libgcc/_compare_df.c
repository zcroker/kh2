/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc _compare_df (gcc 3.2-ee-040921), 0x3142e0-0x314330: compare (dpcmp). Linked unit (linked_units.tsv). */
#include "fp-bit.h"

CMPtype
compare (FLO_type arg_a, FLO_type arg_b)
{
  fp_number_type a;
  fp_number_type b;
  FLO_union_type au, bu;

  au.value = arg_a;
  bu.value = arg_b;

  unpack_d (&au, &a);
  unpack_d (&bu, &b);

  return __fpcmp_parts (&a, &b);
}
