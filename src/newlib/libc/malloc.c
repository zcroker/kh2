/* malloc.c: newlib libc (libc/stdlib/malloc.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2fd3e8-0x2fd428. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "newlib.h"
void *_malloc_r(struct _reent *, size_t);
void _free_r(struct _reent *, void *);

void *malloc(size_t nbytes)
{
    return _malloc_r(_impure_ptr, nbytes);
}

void free(void *aptr)
{
    _free_r(_impure_ptr, aptr);
}
