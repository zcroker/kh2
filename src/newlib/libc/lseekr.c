/* lseekr.c: newlib libc (libc/reent/lseekr.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x305110-0x305168. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. Reentrant system call wrapper, written by Cygnus Support for newlib. */
#include "newlib.h"
asm("errno = D_00378ae4");
asm("lseek = func_00305d18");
extern int errno;
typedef long _off_t;
_off_t lseek(int, _off_t, int);

_off_t _lseek_r(struct _reent *ptr, int fd, _off_t pos, int whence)
{
    _off_t ret;

    errno = 0;
    if ((ret = lseek(fd, pos, whence)) == (_off_t)-1 && errno != 0)
        ptr->_errno = errno;
    return ret;
}
