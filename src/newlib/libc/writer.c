/* writer.c: newlib libc (libc/reent/writer.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x304f50-0x304fb0. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. Reentrant system call wrapper, written by Cygnus Support for newlib. */
#include "newlib.h"
asm("errno = D_00378ae4");
asm("write = func_00305be8");
extern int errno;
typedef long _ssize_t;
int write(int, const void *, size_t);

_ssize_t _write_r(struct _reent *ptr, int fd, const void *buf, size_t cnt)
{
    _ssize_t ret;

    errno = 0;
    if ((ret = (_ssize_t)write(fd, buf, cnt)) == -1 && errno != 0)
        ptr->_errno = errno;
    return ret;
}
