/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc2.h (gcc 3.2-ee-040921): the types of the libgcc2.c conversion objects (_floatdidf.c,
 * _floatdisf.c, _fixunsdfdi.c, _fixunssfdi.c). Doubles are software (the dp-bit objects). */
#ifndef LIBGCC_LIBGCC2_H
#define LIBGCC_LIBGCC2_H
typedef int SItype __attribute__ ((mode (SI)));
typedef unsigned int USItype __attribute__ ((mode (SI)));
typedef int DItype __attribute__ ((mode (DI)));
typedef unsigned int UDItype __attribute__ ((mode (DI)));
typedef float SFtype __attribute__ ((mode (SF)));
typedef float DFtype __attribute__ ((mode (DF)));

#define W_TYPE_SIZE 32
#define Wtype	SItype
#define UWtype	USItype
#define DWtype	DItype
#define UDWtype	UDItype

#define WORD_SIZE (sizeof (Wtype) * 8)
#define HIGH_HALFWORD_COEFF (((UDWtype) 1) << (WORD_SIZE / 2))
#define HIGH_WORD_COEFF (((UDWtype) 1) << WORD_SIZE)

#define DI_SIZE (sizeof (DWtype) * 8)
#define SF_SIZE 24
#define DF_SIZE 53
#endif
