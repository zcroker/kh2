/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* unwind-dw2-fde.c fde_split (gcc 3.2-ee-040921 libgcc, unwind-dw2-fde.o), verbatim.
 * The function-local "static fde *marker" is the game's .bss word at 0x37aa28. */
#include "../common/types.h"

#define NULL ((void *) 0)
typedef unsigned int size_t_fde;
typedef unsigned int uword __attribute__ ((mode (SI)));
typedef int sword __attribute__ ((mode (SI)));

struct dwarf_fde
{
  uword length;
  sword CIE_delta;
  unsigned char pc_begin[];
} __attribute__ ((packed, aligned (__alignof__ (void *))));
typedef struct dwarf_fde fde;

struct object;
typedef int (*fde_compare_t) (struct object *, fde *, fde *);

/* This is a vector of FDEs (the linear and erratic arrays of fde_accumulator). */
struct fde_vector
{
  void *orig_data;
  size_t_fde count;
  fde *array[];
};

struct fde_accumulator
{
  struct fde_vector *linear;
  struct fde_vector *erratic;
};

extern fde *fde_split_marker __asm__ ("D_0037aa28");
extern void abort (void);

void func_00101b98 (struct object *ob, fde_compare_t fde_compare, struct fde_vector *linear, struct fde_vector *erratic)
{
  size_t_fde count = linear->count;
  fde **chain_end = &fde_split_marker;
  size_t_fde i, j, k;

  /* This should optimize out, but it is wise to make sure this assumption
     is correct. Should these have different sizes, we cannot cast between
     them and the overlaying onto ERRATIC will not work.  */
  if (sizeof (fde *) != sizeof (fde **))
    abort ();

  for (i = 0; i < count; i++)
    {
      fde **probe;

      for (probe = chain_end;
	   probe != &fde_split_marker && fde_compare (ob, linear->array[i], *probe) < 0;
	   probe = chain_end)
	{
	  chain_end = (fde **) erratic->array[probe - linear->array];
	  erratic->array[probe - linear->array] = NULL;
	}
      erratic->array[i] = (fde *) chain_end;
      chain_end = &linear->array[i];
    }

  /* Each entry in LINEAR which is part of the linear sequence we have
     discovered will correspond to a non-NULL entry in the chain we built in
     the ERRATIC array.  */
  for (i = j = k = 0; i < count; i++)
    if (erratic->array[i])
      linear->array[j++] = linear->array[i];
    else
      erratic->array[k++] = linear->array[i];
  linear->count = j;
  erratic->count = k;
}
