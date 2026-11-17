/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc unwind-dw2-fde.o (gcc 3.2-ee-040921), 0x1003c8-0x101ce0: subroutines for exception
 * handling that find the FDE of a pc, with the static helpers of unwind-pe.h first. The EE build
 * guards the object lists with DIntr/EIntr. Linked unit (linked_units.tsv), C with -fexceptions
 * like the original libgcc build. */

/* tsystem.h */
typedef unsigned int size_t;
extern void *malloc (size_t);
extern void free (void *);
extern void abort (void) __attribute__ ((__noreturn__));
extern size_t strlen (const char *);
#define NULL ((void *) 0)
asm ("abort = func_002fd160");
asm ("free = func_002fd408");

/* EE kernel: DIntr returns whether interrupts were enabled. */
extern int DIntr (void);
extern int EIntr (void);

/* unwind.h */
typedef unsigned _Unwind_Word __attribute__ ((__mode__ (__word__)));
typedef signed _Unwind_Sword __attribute__ ((__mode__ (__word__)));
typedef unsigned _Unwind_Ptr __attribute__ ((__mode__ (__pointer__)));

/* dwarf2.h */
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

/* gthr (EE): the lock disables interrupts and remembers whether they were on. */
typedef int __gthread_mutex_t;
#define __GTHREAD_MUTEX_INIT 0
static int interupt_was_enabled;

static inline int
__gthread_mutex_lock (__gthread_mutex_t *mutex __attribute__ ((__unused__)))
{
  interupt_was_enabled = DIntr ();
  return 0;
}

static inline int
__gthread_mutex_unlock (__gthread_mutex_t *mutex __attribute__ ((__unused__)))
{
  if (interupt_was_enabled)
    EIntr ();
  return 0;
}

/* unwind-pe.h */
#define NO_BASE_OF_ENCODED_VALUE

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
  abort ();
}

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

  union unaligned *u = (union unaligned *) p;
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
	  abort ();
	}

      if (result != 0)
	{
	  result += ((encoding & 0x70) == DW_EH_PE_pcrel
		     ? (_Unwind_Ptr) u : base);
	  if (encoding & DW_EH_PE_indirect)
	    result = *(_Unwind_Ptr *) result;
	}
    }

  *val = result;
  return p;
}

/* unwind-dw2-fde.h */
struct fde_vector
{
  void *orig_data;
  size_t count;
  struct dwarf_fde *array[];
};

struct object
{
  void *pc_begin;
  void *tbase;
  void *dbase;
  union {
    struct dwarf_fde *single;
    struct dwarf_fde **array;
    struct fde_vector *sort;
  } u;

  union {
    struct {
      unsigned long sorted : 1;
      unsigned long from_array : 1;
      unsigned long mixed_encoding : 1;
      unsigned long encoding : 8;
      /* ??? Wish there was an easy way to detect a 64-bit host here;
	 we've got 32 bits left to play with...  */
      unsigned long count : 21;
    } b;
    size_t i;
  } s;

  struct object *next;
};

struct dwarf_eh_bases
{
  void *tbase;
  void *dbase;
  void *func;
};

typedef          int  sword __attribute__ ((mode (SI)));
typedef unsigned int  uword __attribute__ ((mode (SI)));
typedef unsigned int  uaddr __attribute__ ((mode (pointer)));
typedef          int  saddr __attribute__ ((mode (pointer)));
typedef unsigned char ubyte;

struct dwarf_cie
{
  uword length;
  sword CIE_id;
  ubyte version;
  unsigned char augmentation[];
} __attribute__ ((packed, aligned (__alignof__ (void *))));

struct dwarf_fde
{
  uword length;
  sword CIE_delta;
  unsigned char pc_begin[];
} __attribute__ ((packed, aligned (__alignof__ (void *))));

typedef struct dwarf_fde fde;

static inline struct dwarf_cie *
get_cie (struct dwarf_fde *f)
{
  return (void *)&f->CIE_delta - f->CIE_delta;
}

static inline fde *
next_fde (fde *f)
{
  return (fde *)((char *)f + f->length + sizeof (f->length));
}

/* unwind-dw2-fde.c */

/* The unseen_objects list contains objects that have been registered
   but not yet categorized in any way.  The seen_objects list has had
   it's pc_begin and count fields initialized at minimum, and is sorted
   by decreasing value of pc_begin.  */
static struct object *unseen_objects;
static struct object *seen_objects;

static __gthread_mutex_t object_mutex = __GTHREAD_MUTEX_INIT;

#define init_object_mutex_once()

/* Called from crtbegin.o to register the unwind info for an object.  */

void
__register_frame_info_bases (void *begin, struct object *ob,
			     void *tbase, void *dbase)
{
  /* If .eh_frame is empty, don't register at all.  */
  if (*(uword *) begin == 0)
    return;

  ob->pc_begin = (void *)-1;
  ob->tbase = tbase;
  ob->dbase = dbase;
  ob->u.single = begin;
  ob->s.i = 0;
  ob->s.b.encoding = DW_EH_PE_omit;

  init_object_mutex_once ();
  __gthread_mutex_lock (&object_mutex);

  ob->next = unseen_objects;
  unseen_objects = ob;

  __gthread_mutex_unlock (&object_mutex);
}

void
__register_frame_info (void *begin, struct object *ob)
{
  __register_frame_info_bases (begin, ob, 0, 0);
}

void
__register_frame (void *begin)
{
  struct object *ob;

  /* If .eh_frame is empty, don't register at all.  */
  if (*(uword *) begin == 0)
    return;

  ob = (struct object *) malloc (sizeof (struct object));
  __register_frame_info (begin, ob);
}

/* Similar, but BEGIN is actually a pointer to a table of unwind entries
   for different translation units.  Called from the file generated by
   collect2.  */

void
__register_frame_info_table_bases (void *begin, struct object *ob,
				   void *tbase, void *dbase)
{
  ob->pc_begin = (void *)-1;
  ob->tbase = tbase;
  ob->dbase = dbase;
  ob->u.array = begin;
  ob->s.i = 0;
  ob->s.b.from_array = 1;
  ob->s.b.encoding = DW_EH_PE_omit;

  init_object_mutex_once ();
  __gthread_mutex_lock (&object_mutex);

  ob->next = unseen_objects;
  unseen_objects = ob;

  __gthread_mutex_unlock (&object_mutex);
}

void
__register_frame_info_table (void *begin, struct object *ob)
{
  __register_frame_info_table_bases (begin, ob, 0, 0);
}

void
__register_frame_table (void *begin)
{
  struct object *ob = (struct object *) malloc (sizeof (struct object));
  __register_frame_info_table (begin, ob);
}

/* Called from crtbegin.o to deregister the unwind info for an object.  */

void *
__deregister_frame_info_bases (void *begin)
{
  struct object **p;
  struct object *ob = 0;

  /* If .eh_frame is empty, we haven't registered.  */
  if (*(uword *) begin == 0)
    return ob;

  init_object_mutex_once ();
  __gthread_mutex_lock (&object_mutex);

  for (p = &unseen_objects; *p ; p = &(*p)->next)
    if ((*p)->u.single == begin)
      {
	ob = *p;
	*p = ob->next;
	goto out;
      }

  for (p = &seen_objects; *p ; p = &(*p)->next)
    if ((*p)->s.b.sorted)
      {
	if ((*p)->u.sort->orig_data == begin)
	  {
	    ob = *p;
	    *p = ob->next;
	    free (ob->u.sort);
	    goto out;
	  }
      }
    else
      {
	if ((*p)->u.single == begin)
	  {
	    ob = *p;
	    *p = ob->next;
	    goto out;
	  }
      }

  __gthread_mutex_unlock (&object_mutex);
  abort ();

 out:
  __gthread_mutex_unlock (&object_mutex);
  return (void *) ob;
}

void *
__deregister_frame_info (void *begin)
{
  return __deregister_frame_info_bases (begin);
}

void
__deregister_frame (void *begin)
{
  /* If .eh_frame is empty, we haven't registered.  */
  if (*(uword *) begin != 0)
    free (__deregister_frame_info (begin));
}


/* Like base_of_encoded_value, but take the base from a struct object
   instead of an _Unwind_Context.  */

static _Unwind_Ptr
base_from_object (unsigned char encoding, struct object *ob)
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
      return (_Unwind_Ptr) ob->tbase;
    case DW_EH_PE_datarel:
      return (_Unwind_Ptr) ob->dbase;
    }
  abort ();
}

/* Return the FDE pointer encoding from the CIE.  */
/* ??? This is a subset of extract_cie_info from unwind-dw2.c.  */

static int
get_cie_encoding (struct dwarf_cie *cie)
{
  const unsigned char *aug, *p;
  _Unwind_Ptr dummy;
  _Unwind_Word utmp;
  _Unwind_Sword stmp;

  aug = cie->augmentation;
  if (aug[0] != 'z')
    return DW_EH_PE_absptr;

  p = aug + strlen (aug) + 1;		/* Skip the augmentation string.  */
  p = read_uleb128 (p, &utmp);		/* Skip code alignment.  */
  p = read_sleb128 (p, &stmp);		/* Skip data alignment.  */
  p++;					/* Skip return address column.  */

  aug++;				/* Skip 'z' */
  p = read_uleb128 (p, &utmp);		/* Skip augmentation length.  */
  while (1)
    {
      /* This is what we're looking for.  */
      if (*aug == 'R')
	return *p;
      /* Personality encoding and pointer.  */
      else if (*aug == 'P')
	{
	  /* ??? Avoid dereferencing indirect pointers, since we're
	     faking the base address.  Gotta keep DW_EH_PE_aligned
	     intact, however.  */
	  p = read_encoded_value_with_base (*p & 0x7F, 0, p + 1, &dummy);
	}
      /* LSDA encoding.  */
      else if (*aug == 'L')
	p++;
      /* Otherwise end of string, or unknown augmentation.  */
      else
	return DW_EH_PE_absptr;
      aug++;
    }
}

static inline int
get_fde_encoding (struct dwarf_fde *f)
{
  return get_cie_encoding (get_cie (f));
}


/* Sorting an array of FDEs by address.
   (Ideally we would have the linker sort the FDEs so we don't have to do
   it at run time. But the linkers are not yet prepared for this.)  */

/* Comparison routines.  Three variants of increasing complexity.  */

static int
fde_unencoded_compare (struct object *ob __attribute__((unused)),
		       fde *x, fde *y)
{
  _Unwind_Ptr x_ptr = *(_Unwind_Ptr *) x->pc_begin;
  _Unwind_Ptr y_ptr = *(_Unwind_Ptr *) y->pc_begin;

  if (x_ptr > y_ptr)
    return 1;
  if (x_ptr < y_ptr)
    return -1;
  return 0;
}

static int
fde_single_encoding_compare (struct object *ob, fde *x, fde *y)
{
  _Unwind_Ptr base, x_ptr, y_ptr;

  base = base_from_object (ob->s.b.encoding, ob);
  read_encoded_value_with_base (ob->s.b.encoding, base, x->pc_begin, &x_ptr);
  read_encoded_value_with_base (ob->s.b.encoding, base, y->pc_begin, &y_ptr);

  if (x_ptr > y_ptr)
    return 1;
  if (x_ptr < y_ptr)
    return -1;
  return 0;
}

static int
fde_mixed_encoding_compare (struct object *ob, fde *x, fde *y)
{
  int x_encoding, y_encoding;
  _Unwind_Ptr x_ptr, y_ptr;

  x_encoding = get_fde_encoding (x);
  read_encoded_value_with_base (x_encoding, base_from_object (x_encoding, ob),
				x->pc_begin, &x_ptr);

  y_encoding = get_fde_encoding (y);
  read_encoded_value_with_base (y_encoding, base_from_object (y_encoding, ob),
				y->pc_begin, &y_ptr);

  if (x_ptr > y_ptr)
    return 1;
  if (x_ptr < y_ptr)
    return -1;
  return 0;
}

typedef int (*fde_compare_t) (struct object *, fde *, fde *);


/* This is a special mix of insertion sort and heap sort, optimized for
   the data sets that actually occur.  */

struct fde_accumulator
{
  struct fde_vector *linear;
  struct fde_vector *erratic;
};

static inline int
start_fde_sort (struct fde_accumulator *accu, size_t count)
{
  size_t size;
  if (! count)
    return 0;

  size = sizeof (struct fde_vector) + sizeof (fde *) * count;
  if ((accu->linear = (struct fde_vector *) malloc (size)))
    {
      accu->linear->count = 0;
      if ((accu->erratic = (struct fde_vector *) malloc (size)))
	accu->erratic->count = 0;
      return 1;
    }
  else
    return 0;
}

static inline void
fde_insert (struct fde_accumulator *accu, fde *this_fde)
{
  if (accu->linear)
    accu->linear->array[accu->linear->count++] = this_fde;
}

/* Split LINEAR into a linear sequence with low values and an erratic
   sequence with high values, put the linear one (of longest possible
   length) into LINEAR and the erratic one into ERRATIC. This is O(N).  */

static inline void
fde_split (struct object *ob, fde_compare_t fde_compare,
	   struct fde_vector *linear, struct fde_vector *erratic)
{
  static fde *marker;
  size_t count = linear->count;
  fde **chain_end = &marker;
  size_t i, j, k;

  /* This should optimize out, but it is wise to make sure this assumption
     is correct. Should these have different sizes, we cannot cast between
     them and the overlaying onto ERRATIC will not work.  */
  if (sizeof (fde *) != sizeof (fde **))
    abort ();

  for (i = 0; i < count; i++)
    {
      fde **probe;

      for (probe = chain_end;
	   probe != &marker && fde_compare (ob, linear->array[i], *probe) < 0;
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

/* This is O(n log(n)).  BSD/OS defines heapsort in stdlib.h, so we must
   use a name that does not conflict.  */

static void
frame_heapsort (struct object *ob, fde_compare_t fde_compare,
		struct fde_vector *erratic)
{
  /* For a description of this algorithm, see:
     Samuel P. Harbison, Guy L. Steele Jr.: C, a reference manual, 2nd ed.,
     p. 60-61.  */
  fde ** a = erratic->array;
  /* A portion of the array is called a "heap" if for all i>=0:
     If i and 2i+1 are valid indices, then a[i] >= a[2i+1].
     If i and 2i+2 are valid indices, then a[i] >= a[2i+2].  */
#define SWAP(x,y) do { fde * tmp = x; x = y; y = tmp; } while (0)
  size_t n = erratic->count;
  size_t m = n;
  size_t i;

  while (m > 0)
    {
      /* Invariant: a[m..n-1] is a heap.  */
      m--;
      for (i = m; 2*i+1 < n; )
	{
	  if (2*i+2 < n
	      && fde_compare (ob, a[2*i+2], a[2*i+1]) > 0
	      && fde_compare (ob, a[2*i+2], a[i]) > 0)
	    {
	      SWAP (a[i], a[2*i+2]);
	      i = 2*i+2;
	    }
	  else if (fde_compare (ob, a[2*i+1], a[i]) > 0)
	    {
	      SWAP (a[i], a[2*i+1]);
	      i = 2*i+1;
	    }
	  else
	    break;
	}
    }
  while (n > 1)
    {
      /* Invariant: a[0..n-1] is a heap.  */
      n--;
      SWAP (a[0], a[n]);
      for (i = 0; 2*i+1 < n; )
	{
	  if (2*i+2 < n
	      && fde_compare (ob, a[2*i+2], a[2*i+1]) > 0
	      && fde_compare (ob, a[2*i+2], a[i]) > 0)
	    {
	      SWAP (a[i], a[2*i+2]);
	      i = 2*i+2;
	    }
	  else if (fde_compare (ob, a[2*i+1], a[i]) > 0)
	    {
	      SWAP (a[i], a[2*i+1]);
	      i = 2*i+1;
	    }
	  else
	    break;
	}
    }
#undef SWAP
}

/* Merge V1 and V2, both sorted, and put the result into V1.  */
static inline void
fde_merge (struct object *ob, fde_compare_t fde_compare,
	   struct fde_vector *v1, struct fde_vector *v2)
{
  size_t i1, i2;
  fde * fde2;

  i2 = v2->count;
  if (i2 > 0)
    {
      i1 = v1->count;
      do
	{
	  i2--;
	  fde2 = v2->array[i2];
	  while (i1 > 0 && fde_compare (ob, v1->array[i1-1], fde2) > 0)
	    {
	      v1->array[i1+i2] = v1->array[i1-1];
	      i1--;
	    }
	  v1->array[i1+i2] = fde2;
	}
      while (i2 > 0);
      v1->count += v2->count;
    }
}

static inline void
end_fde_sort (struct object *ob, struct fde_accumulator *accu, size_t count)
{
  fde_compare_t fde_compare;

  if (accu->linear && accu->linear->count != count)
    abort ();

  if (ob->s.b.mixed_encoding)
    fde_compare = fde_mixed_encoding_compare;
  else if (ob->s.b.encoding == DW_EH_PE_absptr)
    fde_compare = fde_unencoded_compare;
  else
    fde_compare = fde_single_encoding_compare;

  if (accu->erratic)
    {
      fde_split (ob, fde_compare, accu->linear, accu->erratic);
      if (accu->linear->count + accu->erratic->count != count)
	abort ();
      frame_heapsort (ob, fde_compare, accu->erratic);
      fde_merge (ob, fde_compare, accu->linear, accu->erratic);
      free (accu->erratic);
    }
  else
    {
      /* We've not managed to malloc an erratic array,
	 so heap sort in the linear one.  */
      frame_heapsort (ob, fde_compare, accu->linear);
    }
}


/* Update encoding, mixed_encoding, and pc_begin for OB for the
   fde array beginning at THIS_FDE.  Return the number of fdes
   encountered along the way.  */

static size_t
classify_object_over_fdes (struct object *ob, fde *this_fde)
{
  struct dwarf_cie *last_cie = 0;
  size_t count = 0;
  int encoding = DW_EH_PE_absptr;
  _Unwind_Ptr base = 0;

  for (; this_fde->length != 0; this_fde = next_fde (this_fde))
    {
      struct dwarf_cie *this_cie;
      _Unwind_Ptr mask, pc_begin;

      /* Skip CIEs.  */
      if (this_fde->CIE_delta == 0)
	continue;

      /* Determine the encoding for this FDE.  Note mixed encoded
	 objects for later.  */
      this_cie = get_cie (this_fde);
      if (this_cie != last_cie)
	{
	  last_cie = this_cie;
	  encoding = get_cie_encoding (this_cie);
	  base = base_from_object (encoding, ob);
	  if (ob->s.b.encoding == DW_EH_PE_omit)
	    ob->s.b.encoding = encoding;
	  else if (ob->s.b.encoding != encoding)
	    ob->s.b.mixed_encoding = 1;
	}

      read_encoded_value_with_base (encoding, base, this_fde->pc_begin,
				    &pc_begin);

      /* Take care to ignore link-once functions that were removed.
	 In these cases, the function address will be NULL, but if
	 the encoding is smaller than a pointer a true NULL may not
	 be representable.  Assume 0 in the representable bits is NULL.  */
      mask = size_of_encoded_value (encoding);
      if (mask < sizeof (void *))
	mask = (1L << (mask << 3)) - 1;
      else
	mask = -1;

      if ((pc_begin & mask) == 0)
	continue;

      count += 1;
      if ((void *) pc_begin < ob->pc_begin)
	ob->pc_begin = (void *) pc_begin;
    }

  return count;
}

static void
add_fdes (struct object *ob, struct fde_accumulator *accu, fde *this_fde)
{
  struct dwarf_cie *last_cie = 0;
  int encoding = ob->s.b.encoding;
  _Unwind_Ptr base = base_from_object (ob->s.b.encoding, ob);

  for (; this_fde->length != 0; this_fde = next_fde (this_fde))
    {
      struct dwarf_cie *this_cie;

      /* Skip CIEs.  */
      if (this_fde->CIE_delta == 0)
	continue;

      if (ob->s.b.mixed_encoding)
	{
	  /* Determine the encoding for this FDE.  Note mixed encoded
	     objects for later.  */
	  this_cie = get_cie (this_fde);
	  if (this_cie != last_cie)
	    {
	      last_cie = this_cie;
	      encoding = get_cie_encoding (this_cie);
	      base = base_from_object (encoding, ob);
	    }
	}

      if (encoding == DW_EH_PE_absptr)
	{
	  if (*(_Unwind_Ptr *) this_fde->pc_begin == 0)
	    continue;
	}
      else
	{
	  _Unwind_Ptr pc_begin, mask;

	  read_encoded_value_with_base (encoding, base, this_fde->pc_begin,
					&pc_begin);

	  /* Take care to ignore link-once functions that were removed.
	     In these cases, the function address will be NULL, but if
	     the encoding is smaller than a pointer a true NULL may not
	     be representable.  Assume 0 in the representable bits is NULL.  */
	  mask = size_of_encoded_value (encoding);
	  if (mask < sizeof (void *))
	    mask = (1L << (mask << 3)) - 1;
	  else
	    mask = -1;

	  if ((pc_begin & mask) == 0)
	    continue;
	}

      fde_insert (accu, this_fde);
    }
}

/* Set up a sorted array of pointers to FDEs for a loaded object.  We
   count up the entries before allocating the array because it's likely to
   be faster.  We can be called multiple times, should we have failed to
   allocate a sorted fde array on a previous occasion.  */

static inline void
init_object (struct object* ob)
{
  struct fde_accumulator accu;
  size_t count;

  count = ob->s.b.count;
  if (count == 0)
    {
      if (ob->s.b.from_array)
	{
	  fde **p = ob->u.array;
	  for (count = 0; *p; ++p)
	    count += classify_object_over_fdes (ob, *p);
	}
      else
	count = classify_object_over_fdes (ob, ob->u.single);

      /* The count field we have in the main struct object is somewhat
	 limited, but should suffice for virtually all cases.  If the
	 counted value doesn't fit, re-write a zero.  The worst that
	 happens is that we re-count next time -- admittedly non-trivial
	 in that this implies some 2M fdes, but at least we function.  */
      ob->s.b.count = count;
      if (ob->s.b.count != count)
	ob->s.b.count = 0;
    }

  if (!start_fde_sort (&accu, count))
    return;

  if (ob->s.b.from_array)
    {
      fde **p;
      for (p = ob->u.array; *p; ++p)
	add_fdes (ob, &accu, *p);
    }
  else
    add_fdes (ob, &accu, ob->u.single);

  end_fde_sort (ob, &accu, count);

  /* Save the original fde pointer, since this is the key by which the
     DSO will deregister the object.  */
  accu.linear->orig_data = ob->u.single;
  ob->u.sort = accu.linear;

  ob->s.b.sorted = 1;
}

/* A linear search through a set of FDEs for the given PC.  This is
   used when there was insufficient memory to allocate and sort an
   array.  */

static fde *
linear_search_fdes (struct object *ob, fde *this_fde, void *pc)
{
  struct dwarf_cie *last_cie = 0;
  int encoding = ob->s.b.encoding;
  _Unwind_Ptr base = base_from_object (ob->s.b.encoding, ob);

  for (; this_fde->length != 0; this_fde = next_fde (this_fde))
    {
      struct dwarf_cie *this_cie;
      _Unwind_Ptr pc_begin, pc_range;

      /* Skip CIEs.  */
      if (this_fde->CIE_delta == 0)
	continue;

      if (ob->s.b.mixed_encoding)
	{
	  /* Determine the encoding for this FDE.  Note mixed encoded
	     objects for later.  */
	  this_cie = get_cie (this_fde);
	  if (this_cie != last_cie)
	    {
	      last_cie = this_cie;
	      encoding = get_cie_encoding (this_cie);
	      base = base_from_object (encoding, ob);
	    }
	}

      if (encoding == DW_EH_PE_absptr)
	{
	  pc_begin = ((_Unwind_Ptr *) this_fde->pc_begin)[0];
	  pc_range = ((_Unwind_Ptr *) this_fde->pc_begin)[1];
	  if (pc_begin == 0)
	    continue;
	}
      else
	{
	  _Unwind_Ptr mask;
	  const char *p;

	  p = read_encoded_value_with_base (encoding, base,
					    this_fde->pc_begin, &pc_begin);
	  read_encoded_value_with_base (encoding & 0x0F, 0, p, &pc_range);

	  /* Take care to ignore link-once functions that were removed.
	     In these cases, the function address will be NULL, but if
	     the encoding is smaller than a pointer a true NULL may not
	     be representable.  Assume 0 in the representable bits is NULL.  */
	  mask = size_of_encoded_value (encoding);
	  if (mask < sizeof (void *))
	    mask = (1L << (mask << 3)) - 1;
	  else
	    mask = -1;

	  if ((pc_begin & mask) == 0)
	    continue;
	}

      if ((_Unwind_Ptr) pc - pc_begin < pc_range)
	return this_fde;
    }

  return NULL;
}

/* Binary search for an FDE containing the given PC.  Here are three
   implementations of increasing complexity.  */

static inline fde *
binary_search_unencoded_fdes (struct object *ob, void *pc)
{
  struct fde_vector *vec = ob->u.sort;
  size_t lo, hi;

  for (lo = 0, hi = vec->count; lo < hi; )
    {
      size_t i = (lo + hi) / 2;
      fde *f = vec->array[i];
      void *pc_begin;
      uaddr pc_range;

      pc_begin = ((void **) f->pc_begin)[0];
      pc_range = ((uaddr *) f->pc_begin)[1];

      if (pc < pc_begin)
	hi = i;
      else if (pc >= pc_begin + pc_range)
	lo = i + 1;
      else
	return f;
    }

  return NULL;
}

static inline fde *
binary_search_single_encoding_fdes (struct object *ob, void *pc)
{
  struct fde_vector *vec = ob->u.sort;
  int encoding = ob->s.b.encoding;
  _Unwind_Ptr base = base_from_object (encoding, ob);
  size_t lo, hi;

  for (lo = 0, hi = vec->count; lo < hi; )
    {
      size_t i = (lo + hi) / 2;
      fde *f = vec->array[i];
      _Unwind_Ptr pc_begin, pc_range;
      const char *p;

      p = read_encoded_value_with_base (encoding, base, f->pc_begin,
					&pc_begin);
      read_encoded_value_with_base (encoding & 0x0F, 0, p, &pc_range);

      if ((_Unwind_Ptr) pc < pc_begin)
	hi = i;
      else if ((_Unwind_Ptr) pc >= pc_begin + pc_range)
	lo = i + 1;
      else
	return f;
    }

  return NULL;
}

static inline fde *
binary_search_mixed_encoding_fdes (struct object *ob, void *pc)
{
  struct fde_vector *vec = ob->u.sort;
  size_t lo, hi;

  for (lo = 0, hi = vec->count; lo < hi; )
    {
      size_t i = (lo + hi) / 2;
      fde *f = vec->array[i];
      _Unwind_Ptr pc_begin, pc_range;
      const char *p;
      int encoding;

      encoding = get_fde_encoding (f);
      p = read_encoded_value_with_base (encoding,
					base_from_object (encoding, ob),
					f->pc_begin, &pc_begin);
      read_encoded_value_with_base (encoding & 0x0F, 0, p, &pc_range);

      if ((_Unwind_Ptr) pc < pc_begin)
	hi = i;
      else if ((_Unwind_Ptr) pc >= pc_begin + pc_range)
	lo = i + 1;
      else
	return f;
    }

  return NULL;
}

static fde *
search_object (struct object* ob, void *pc)
{
  /* If the data hasn't been sorted, try to do this now.  We may have
     more memory available than last time we tried.  */
  if (! ob->s.b.sorted)
    {
      init_object (ob);

      /* Despite the above comment, the normal reason to get here is
	 that we've not processed this object before.  A quick range
	 check is in order.  */
      if (pc < ob->pc_begin)
	return NULL;
    }

  if (ob->s.b.sorted)
    {
      if (ob->s.b.mixed_encoding)
	return binary_search_mixed_encoding_fdes (ob, pc);
      else if (ob->s.b.encoding == DW_EH_PE_absptr)
	return binary_search_unencoded_fdes (ob, pc);
      else
	return binary_search_single_encoding_fdes (ob, pc);
    }
  else
    {
      /* Long slow labourious linear search, cos we've no memory.  */
      if (ob->s.b.from_array)
	{
	  fde **p;
	  for (p = ob->u.array; *p ; p++)
	    {
	      fde *f = linear_search_fdes (ob, *p, pc);
	      if (f)
		return f;
	    }
	  return NULL;
	}
      else
	return linear_search_fdes (ob, ob->u.single, pc);
    }
}

fde *
_Unwind_Find_FDE (void *pc, struct dwarf_eh_bases *bases)
{
  struct object *ob;
  fde *f = NULL;

  init_object_mutex_once ();
  __gthread_mutex_lock (&object_mutex);

  /* Linear search through the classified objects, to find the one
     containing the pc.  Note that pc_begin is sorted descending, and
     we expect objects to be non-overlapping.  */
  for (ob = seen_objects; ob; ob = ob->next)
    if (pc >= ob->pc_begin)
      {
	f = search_object (ob, pc);
	if (f)
	  goto fini;
	break;
      }

  /* Classify and search the objects we've not yet processed.  */
  while ((ob = unseen_objects))
    {
      struct object **p;

      unseen_objects = ob->next;
      f = search_object (ob, pc);

      /* Insert the object into the classified list.  */
      for (p = &seen_objects; *p ; p = &(*p)->next)
	if ((*p)->pc_begin < ob->pc_begin)
	  break;
      ob->next = *p;
      *p = ob;

      if (f)
	goto fini;
    }

 fini:
  __gthread_mutex_unlock (&object_mutex);

  if (f)
    {
      int encoding;

      bases->tbase = ob->tbase;
      bases->dbase = ob->dbase;

      encoding = ob->s.b.encoding;
      if (ob->s.b.mixed_encoding)
	encoding = get_fde_encoding (f);
      read_encoded_value_with_base (encoding, base_from_object (encoding, ob),
				    f->pc_begin, (_Unwind_Ptr *)&bases->func);
    }

  return f;
}
