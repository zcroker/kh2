/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc _make_sf (gcc 3.2-ee-040921), 0x314698-0x3146c8: __make_fp. Linked unit (linked_units.tsv). */
#define FLOAT
#include "fp-bit.h"

SFtype
__make_fp (fp_class_type class, unsigned int sign, int exp, USItype frac)
{
  fp_number_type in;

  in.class = class;
  in.sign = sign;
  in.normal_exp = exp;
  in.fraction.ll = frac;
  return pack_d (&in);
}
