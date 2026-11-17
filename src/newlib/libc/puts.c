/* puts.c: newlib libc (libc/stdio/puts.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2fe018-0x2fe0c0 with its .rodata ("\n") at 0x3778d8. Third-party code notice: rebuilt to match;
 * not covered by this project's MIT License. newlib, Copyright (c) 1990 The Regents of the University of
 * California (BSD license). */
#include "newlib.h"
size_t strlen(const char *);
int __sfvwrite(FILE *, struct __suio *);

int _puts_r(struct _reent *ptr, const char *s)
{
    size_t c = strlen(s);
    struct __suio uio;
    struct __siov iov[2];

    iov[0].iov_base = s;
    iov[0].iov_len = c;
    iov[1].iov_base = "\n";
    iov[1].iov_len = 1;
    uio.uio_resid = c + 1;
    uio.uio_iov = &iov[0];
    uio.uio_iovcnt = 2;
    return (__sfvwrite(_stdout_r(ptr), &uio) ? EOF : '\n');
}

int puts(const char *s)
{
    return _puts_r(_impure_ptr, s);
}
