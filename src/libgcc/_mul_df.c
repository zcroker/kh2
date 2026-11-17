/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc _mul_df (gcc 3.2-ee-040921), 0x313f40-0x314190: multiply (dpmul), _fpmul_parts. Linked unit (linked_units.tsv). */
#include "fp-bit.h"

static INLINE fp_number_type *
_fpmul_parts ( fp_number_type *  a,
	       fp_number_type *  b,
	       fp_number_type * tmp)
{
  fractype low = 0;
  fractype high = 0;

  if (isnan (a))
    {
      a->sign = a->sign != b->sign;
      return a;
    }
  if (isnan (b))
    {
      b->sign = a->sign != b->sign;
      return b;
    }
  if (isinf (a))
    {
      if (iszero (b))
	return nan ();
      a->sign = a->sign != b->sign;
      return a;
    }
  if (isinf (b))
    {
      if (iszero (a))
	{
	  return nan ();
	}
      b->sign = a->sign != b->sign;
      return b;
    }
  if (iszero (a))
    {
      a->sign = a->sign != b->sign;
      return a;
    }
  if (iszero (b))
    {
      b->sign = a->sign != b->sign;
      return b;
    }

  /* Calculate the mantissa by multiplying both numbers to get a
     twice-as-wide number.  */
  {
    /* fractype is DImode, but we need the result to be twice as wide.
       Assuming a widening multiply from DImode to TImode is not
       available, build one by hand.  */
    {
      USItype nl = a->fraction.ll;
      USItype nh = a->fraction.ll >> BITS_PER_SI;
      USItype ml = b->fraction.ll;
      USItype mh = b->fraction.ll >> BITS_PER_SI;
      UDItype pp_ll = (UDItype) ml * nl;
      UDItype pp_hl = (UDItype) mh * nl;
      UDItype pp_lh = (UDItype) ml * nh;
      UDItype pp_hh = (UDItype) mh * nh;
      UDItype res2 = 0;
      UDItype res0 = 0;
      UDItype ps_hh__ = pp_hl + pp_lh;
      if (ps_hh__ < pp_hl)
	res2 += (UDItype)1 << BITS_PER_SI;
      pp_hl = (UDItype)(USItype)ps_hh__ << BITS_PER_SI;
      res0 = pp_ll + pp_hl;
      if (res0 < pp_ll)
	res2++;
      res2 += (ps_hh__ >> BITS_PER_SI) + pp_hh;
      high = res2;
      low = res0;
    }
  }

  tmp->normal_exp = a->normal_exp + b->normal_exp;
  tmp->sign = a->sign != b->sign;
  tmp->normal_exp += 4;		/* ??????????????? */
  while (high >= IMPLICIT_2)
    {
      tmp->normal_exp++;
      if (high & 1)
	{
	  low >>= 1;
	  low |= FRACHIGH;
	}
      high >>= 1;
    }
  while (high < IMPLICIT_1)
    {
      tmp->normal_exp--;

      high <<= 1;
      if (low & FRACHIGH)
	high |= 1;
      low <<= 1;
    }
  /* No rounding: the fraction is truncated.  */
  tmp->fraction.ll = high;
  tmp->class = CLASS_NUMBER;
  return tmp;
}

FLO_type
multiply (FLO_type arg_a, FLO_type arg_b)
{
  fp_number_type a;
  fp_number_type b;
  fp_number_type tmp;
  fp_number_type *res;
  FLO_union_type au, bu;

  au.value = arg_a;
  bu.value = arg_b;

  unpack_d (&au, &a);
  unpack_d (&bu, &b);

  res = _fpmul_parts (&a, &b, &tmp);

  return pack_d (res);
}
