/* fwalk.c: newlib libc (libc/stdio/fwalk.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x303698-0x303728. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "local.h"

int _fwalk(struct _reent *ptr, register int (*function)(FILE *))
{
    register FILE *fp;
    register int n, ret = 0;
    register struct _glue *g;

    for (g = &ptr->__sglue; g != NULL; g = g->_next)
        for (fp = g->_iobs, n = g->_niobs; --n >= 0; fp++)
            if (fp->_flags != 0)
                ret |= (*function)(fp);
    return ret;
}
