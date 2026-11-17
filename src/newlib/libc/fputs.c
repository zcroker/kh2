/* fputs.c: newlib libc (libc/stdio/fputs.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x316d18-0x316d68. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "newlib.h"
size_t strlen(const char *);
int __sfvwrite(FILE *, struct __suio *);

int fputs(const char *s, FILE *fp)
{
    struct __suio uio;
    struct __siov iov;

    iov.iov_base = s;
    iov.iov_len = uio.uio_resid = strlen(s);
    uio.uio_iov = &iov;
    uio.uio_iovcnt = 1;
    return __sfvwrite(fp, &uio);
}
