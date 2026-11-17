/* readr.c: newlib libc (libc/reent/readr.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x305168-0x3051c8. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. Reentrant system call wrapper, written by Cygnus Support for newlib. */
#include "newlib.h"
asm("errno = D_00378ae4");
asm("read = func_00305c68");
extern int errno;
typedef long _ssize_t;
int read(int, void *, size_t);

_ssize_t _read_r(struct _reent *ptr, int fd, void *buf, size_t cnt)
{
    _ssize_t ret;

    errno = 0;
    if ((ret = (_ssize_t)read(fd, buf, cnt)) == -1 && errno != 0)
        ptr->_errno = errno;
    return ret;
}
