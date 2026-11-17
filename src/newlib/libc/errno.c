/* errno.c: newlib libc (libc/reent/errno.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x316d08-0x316d18. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "newlib.h"

int *__errno(void)
{
    return &_impure_ptr->_errno;
}
