/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc2.c _floatdidf.o (gcc 3.2-ee-040921), 0x3145a8-0x314640: __floatdidf. Linked unit (linked_units.tsv). */
#include "libgcc2.h"

DFtype
__floatdidf (DWtype u)
{
  DFtype d;

  d = (Wtype) (u >> WORD_SIZE);
  d *= HIGH_HALFWORD_COEFF;
  d *= HIGH_HALFWORD_COEFF;
  d += (UWtype) (u & (HIGH_WORD_COEFF - 1));

  return d;
}
