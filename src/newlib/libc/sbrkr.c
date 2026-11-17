/* sbrkr.c: newlib libc (libc/reent/sbrkr.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2fea70-0x2feac0. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. Reentrant system call wrapper, written by Cygnus Support for newlib. */
#include "newlib.h"
asm("errno = D_00378ae4");
asm("sbrk = func_00305d20");
extern int errno;
void *sbrk(int);

void *_sbrk_r(struct _reent *ptr, int incr)
{
    char *ret;

    errno = 0;
    if ((ret = (char *)(sbrk(incr))) == (void *)-1 && errno != 0)
        ptr->_errno = errno;
    return ret;
}
