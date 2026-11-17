/* fstatr.c: newlib libc (libc/reent/fstatr.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x3050b8-0x305110. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. Reentrant system call wrapper, written by Cygnus Support for newlib. */
#include "newlib.h"
asm("errno = D_00378ae4");
asm("fstat = func_00305dd8");
extern int errno;
struct stat;
int fstat(int, struct stat *);

int _fstat_r(struct _reent *ptr, int fd, struct stat *pstat)
{
    int ret;

    errno = 0;
    if ((ret = fstat(fd, pstat)) == -1 && errno != 0)
        ptr->_errno = errno;
    return ret;
}
