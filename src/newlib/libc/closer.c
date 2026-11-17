/* closer.c: newlib libc (libc/reent/closer.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x305068-0x3050b8. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. Reentrant system call wrapper, written by Cygnus Support for newlib. */
#include "newlib.h"
asm("errno = D_00378ae4");
asm("close = func_00305d08");
extern int errno;
int close(int);

int _close_r(struct _reent *ptr, int fd)
{
    int ret;

    errno = 0;
    if ((ret = close(fd)) == -1 && errno != 0)
        ptr->_errno = errno;
    return ret;
}
