/* signalr.c: newlib libc (libc/reent/signalr.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2fed98-0x2fee08. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. Reentrant system call wrapper, written by Cygnus Support for newlib. */
#include "newlib.h"
asm("errno = D_00378ae4");
asm("kill = func_00305df8");
asm("getpid = func_00305df0");
extern int errno;
int kill(int, int);
int getpid(void);

int _kill_r(struct _reent *ptr, int pid, int sig)
{
    int ret;

    errno = 0;
    if ((ret = kill(pid, sig)) == -1 && errno != 0)
        ptr->_errno = errno;
    return ret;
}

int _getpid_r(struct _reent *ptr)
{
    int ret;

    ret = getpid();
    return ret;
}
