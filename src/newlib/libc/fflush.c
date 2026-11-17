/* fflush.c: newlib libc (libc/stdio/fflush.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x302b18-0x302c28. Third-party code notice: rebuilt to match; not covered by this project's MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "local.h"
asm("_fwalk = func_00303698");
int _fwalk(struct _reent *, int (*)(FILE *));

int fflush(register FILE *fp)
{
    register unsigned char *p;
    register int n, t;

    if (fp == NULL)
        return (_fwalk(_REENT, fflush));

    CHECK_INIT(fp);

    t = fp->_flags;
    if ((t & __SWR) == 0 || (p = fp->_bf._base) == NULL)
        return 0;
    n = fp->_p - p;             /* write this much */

    /*
     * Set these immediately to avoid problems with longjmp
     * and to allow exchange buffering (via setvbuf) in user
     * write function.
     */
    fp->_p = p;
    fp->_w = t & (__SLBF | __SNBF) ? 0 : fp->_bf._size;

    while (n > 0) {
        t = (*fp->_write)(fp->_cookie, (char *)p, n);
        if (t <= 0) {
            fp->_flags |= __SERR;
            return EOF;
        }
        p += t;
        n -= t;
    }
    return 0;
}
