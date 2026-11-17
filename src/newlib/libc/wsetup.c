/* wsetup.c: newlib libc (libc/stdio/wsetup.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x3015f8-0x301708 (this version has no __SSTR test). Third-party code notice: rebuilt to match; not covered by this project's MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "local.h"
asm("__smakebuf = func_00303808");
void __smakebuf(FILE *);
void _free_r(struct _reent *, void *);

/*
 * Various output routines call wsetup to be sure it is safe to write,
 * because either _flags does not include __SWR, or _buf is NULL.
 * _wsetup returns 0 if OK to write, nonzero otherwise.
 */
int __swsetup(register FILE *fp)
{
    /* make sure stdio is set up */

    CHECK_INIT(fp);

    /*
     * If we are not writing, we had better be reading and writing.
     */

    if ((fp->_flags & __SWR) == 0) {
        if ((fp->_flags & __SRW) == 0)
            return EOF;
        if (fp->_flags & __SRD) {
            /* clobber any ungetc data */
            if (HASUB(fp))
                FREEUB(fp);
            fp->_flags &= ~(__SRD | __SEOF);
            fp->_r = 0;
            fp->_p = fp->_bf._base;
        }
        fp->_flags |= __SWR;
    }

    /*
     * Make a buffer if necessary, then set _w.
     */
    if (fp->_bf._base == NULL)
        __smakebuf(fp);

    if (fp->_flags & __SLBF) {
        /*
         * It is line buffered, so make _lbfsize be -_bufsize
         * for the putc() macro.  We will change _lbfsize back
         * to 0 whenever we turn off __SWR.
         */
        fp->_w = 0;
        fp->_lbfsize = -fp->_bf._size;
    } else
        fp->_w = fp->_flags & __SNBF ? 0 : fp->_bf._size;
    return 0;
}
