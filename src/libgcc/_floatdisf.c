/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc2.c _floatdisf.o (gcc 3.2-ee-040921), 0x311af0-0x311bb8: __floatdisf. Linked unit (linked_units.tsv). */
#include "libgcc2.h"

SFtype
__floatdisf (DWtype u)
{
  /* Do the calculation in DFmode
     so that we don't lose any of the precision of the high word
     while multiplying it.  */
  DFtype f;

  /* Protect against double-rounding error.
     Represent any low-order bits, that might be truncated in DFmode,
     by a bit that won't be lost.  The bit can go in anywhere below the
     rounding position of the SFmode.  A fixed mask and bit position
     handles all usual configurations.  It doesn't handle the case
     of 128-bit DImode, however.  */
  if (DF_SIZE < DI_SIZE
      && DF_SIZE > (DI_SIZE - DF_SIZE + SF_SIZE))
    {
#define REP_BIT ((UDWtype) 1 << (DI_SIZE - DF_SIZE))
      if (! (- ((DWtype) 1 << DF_SIZE) < u
	     && u < ((DWtype) 1 << DF_SIZE)))
	{
	  if ((UDWtype) u & (REP_BIT - 1))
	    u |= REP_BIT;
	}
    }
  f = (Wtype) (u >> WORD_SIZE);
  f *= HIGH_HALFWORD_COEFF;
  f *= HIGH_HALFWORD_COEFF;
  f += (UWtype) (u & (HIGH_WORD_COEFF - 1));

  return (SFtype) f;
}
