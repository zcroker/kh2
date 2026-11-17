/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* unwind-pe.h (gcc 3.2-ee-040921): reading DWARF EH pointer encodings. Used by the C++ linked
 * unit src/libsupc++/eh_personality.cc (unwind-dw2-fde.c carries its own C copy). */
#ifndef LIBSUPCXX_UNWIND_PE_H
#define LIBSUPCXX_UNWIND_PE_H

#define DW_EH_PE_absptr		0x00
#define DW_EH_PE_omit		0xff

#define DW_EH_PE_uleb128	0x01
#define DW_EH_PE_udata2		0x02
#define DW_EH_PE_udata4		0x03
#define DW_EH_PE_udata8		0x04
#define DW_EH_PE_sleb128	0x09
#define DW_EH_PE_sdata2		0x0A
#define DW_EH_PE_sdata4		0x0B
#define DW_EH_PE_sdata8		0x0C
#define DW_EH_PE_signed		0x08

#define DW_EH_PE_pcrel		0x10
#define DW_EH_PE_textrel	0x20
#define DW_EH_PE_datarel	0x30
#define DW_EH_PE_funcrel	0x40
#define DW_EH_PE_aligned	0x50

#define DW_EH_PE_indirect	0x80

static unsigned int
size_of_encoded_value (unsigned char encoding)
{
  if (encoding == DW_EH_PE_omit)
    return 0;

  switch (encoding & 0x07)
    {
    case DW_EH_PE_absptr:
      return sizeof (void *);
    case DW_EH_PE_udata2:
      return 2;
    case DW_EH_PE_udata4:
      return 4;
    case DW_EH_PE_udata8:
      return 8;
    }
  __gxx_abort ();
}

#ifndef NO_BASE_OF_ENCODED_VALUE
static _Unwind_Ptr
base_of_encoded_value (unsigned char encoding, struct _Unwind_Context *context)
{
  if (encoding == DW_EH_PE_omit)
    return 0;

  switch (encoding & 0x70)
    {
    case DW_EH_PE_absptr:
    case DW_EH_PE_pcrel:
    case DW_EH_PE_aligned:
      return 0;

    case DW_EH_PE_textrel:
      return _Unwind_GetTextRelBase (context);
    case DW_EH_PE_datarel:
      return _Unwind_GetDataRelBase (context);
    case DW_EH_PE_funcrel:
      return _Unwind_GetRegionStart (context);
    }
  __gxx_abort ();
}
#endif

static const unsigned char *
read_uleb128 (const unsigned char *p, _Unwind_Word *val)
{
  unsigned int shift = 0;
  unsigned char byte;
  _Unwind_Word result;

  result = 0;
  do
    {
      byte = *p++;
      result |= (byte & 0x7f) << shift;
      shift += 7;
    }
  while (byte & 0x80);

  *val = result;
  return p;
}

static const unsigned char *
read_sleb128 (const unsigned char *p, _Unwind_Sword *val)
{
  unsigned int shift = 0;
  unsigned char byte;
  _Unwind_Word result;

  result = 0;
  do
    {
      byte = *p++;
      result |= (byte & 0x7f) << shift;
      shift += 7;
    }
  while (byte & 0x80);

  /* Sign-extend a negative value.  */
  if (shift < 8 * sizeof(result) && (byte & 0x40) != 0)
    result |= -(1L << shift);

  *val = (_Unwind_Sword) result;
  return p;
}

static const unsigned char *
read_encoded_value_with_base (unsigned char encoding, _Unwind_Ptr base,
			      const unsigned char *p, _Unwind_Ptr *val)
{
  union unaligned
    {
      void *ptr;
      unsigned u2 __attribute__ ((mode (HI)));
      unsigned u4 __attribute__ ((mode (SI)));
      unsigned u8 __attribute__ ((mode (DI)));
      signed s2 __attribute__ ((mode (HI)));
      signed s4 __attribute__ ((mode (SI)));
      signed s8 __attribute__ ((mode (DI)));
    } __attribute__((__packed__));

  const union unaligned *u = (const union unaligned *) p;
  _Unwind_Ptr result;

  if (encoding == DW_EH_PE_aligned)
    {
      _Unwind_Ptr a = (_Unwind_Ptr) p;
      a = (a + sizeof (void *) - 1) & - sizeof(void *);
      result = *(_Unwind_Ptr *) a;
      p = (const unsigned char *) (a + sizeof (void *));
    }
  else
    {
      switch (encoding & 0x0f)
	{
	case DW_EH_PE_absptr:
	  result = (_Unwind_Ptr) u->ptr;
	  p += sizeof (void *);
	  break;

	case DW_EH_PE_uleb128:
	  {
	    _Unwind_Word tmp;
	    p = read_uleb128 (p, &tmp);
	    result = (_Unwind_Ptr) tmp;
	  }
	  break;

	case DW_EH_PE_sleb128:
	  {
	    _Unwind_Sword tmp;
	    p = read_sleb128 (p, &tmp);
	    result = (_Unwind_Ptr) tmp;
	  }
	  break;

	case DW_EH_PE_udata2:
	  result = u->u2;
	  p += 2;
	  break;
	case DW_EH_PE_udata4:
	  result = u->u4;
	  p += 4;
	  break;
	case DW_EH_PE_udata8:
	  result = u->u8;
	  p += 8;
	  break;

	case DW_EH_PE_sdata2:
	  result = u->s2;
	  p += 2;
	  break;
	case DW_EH_PE_sdata4:
	  result = u->s4;
	  p += 4;
	  break;
	case DW_EH_PE_sdata8:
	  result = u->s8;
	  p += 8;
	  break;

	default:
	  __gxx_abort ();
	}

      if (result != 0)
	{
	  if ((encoding & 0x70) != DW_EH_PE_pcrel)
	    result += base;
	  else
	    result += (_Unwind_Ptr) u;
	  if (encoding & DW_EH_PE_indirect)
	    result = *(_Unwind_Ptr *) result;
	}
    }

  *val = result;
  return p;
}

#ifndef NO_BASE_OF_ENCODED_VALUE
static inline const unsigned char *
read_encoded_value (struct _Unwind_Context *context, unsigned char encoding,
		    const unsigned char *p, _Unwind_Ptr *val)
{
  return read_encoded_value_with_base (encoding,
		base_of_encoded_value (encoding, context),
		p, val);
}
#endif

#endif
