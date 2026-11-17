/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc _si_to_df (gcc 3.2-ee-040921), 0x314330-0x3143e0: si_to_float (litodp). Linked unit (linked_units.tsv). */
#include "fp-bit.h"

FLO_type
si_to_float (SItype arg_a)
{
  fp_number_type in;

  in.class = CLASS_NUMBER;
  in.sign = arg_a < 0;
  if (!arg_a)
    {
      in.class = CLASS_ZERO;
    }
  else
    {
      in.normal_exp = FRACBITS + NGARDS;
      if (in.sign)
	{
	  /* Special case for minint, since there is no +ve integer
	     representation for it */
	  if (arg_a == (- MAX_SI_INT - 1))
	    {
	      return (FLO_type)(- MAX_SI_INT - 1);
	    }
	  in.fraction.ll = (-arg_a);
	}
      else
	in.fraction.ll = arg_a;

      while (in.fraction.ll < ((fractype)1 << (FRACBITS + NGARDS)))
	{
	  in.fraction.ll <<= 1;
	  in.normal_exp -= 1;
	}
    }
  return pack_d (&in);
}
