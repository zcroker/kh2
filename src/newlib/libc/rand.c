/* rand.c: newlib libc (libc/stdlib/rand.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2fea00-0x2fea70 with its .rodata (the 64-bit multiplier) at 0x3778e0. Third-party code notice:
 * rebuilt to match; not covered by this project's MIT License. newlib, Copyright (c) 1990 The Regents of the
 * University of California (BSD license). */
#include "newlib.h"
#define RAND_MAX 0x7fffffff

void srand(unsigned int seed)
{
    _impure_ptr->_new._reent._rand_next = seed;
}

int rand(void)
{
    _impure_ptr->_new._reent._rand_next =
        _impure_ptr->_new._reent._rand_next * __extension__ 6364136223846793005LL + 1;
    return (int)((_impure_ptr->_new._reent._rand_next >> 32) & RAND_MAX);
}
