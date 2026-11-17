/* stdio.c: newlib libc (libc/stdio/stdio.c: __sread, __swrite, __sseek, __sclose), the copy the game links from
 * the toolchain's libc.a. Linked unit 0x304de8-0x304f50. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Copyright (c) 1990 The Regents of the
 * University of California (BSD license). */
#include "local.h"
typedef long _ssize_t;
_ssize_t _read_r(struct _reent *, int, void *, size_t);
_ssize_t _write_r(struct _reent *, int, const void *, size_t);
_fpos_t _lseek_r(struct _reent *, int, _fpos_t, int);
int _close_r(struct _reent *, int);
#define SEEK_END 2

int __sread(void *cookie, char *buf, int n)
{
    register FILE *fp = (FILE *)cookie;
    register int ret;

    ret = _read_r(fp->_data, fp->_file, buf, n);

    /* If the read succeeded, update the current offset. */
    if (ret >= 0)
        fp->_offset += ret;
    else
        fp->_flags &= ~__SOFF; /* paranoia */
    return ret;
}

int __swrite(void *cookie, char const *buf, int n)
{
    register FILE *fp = (FILE *)cookie;

    if (fp->_flags & __SAPP)
        (void)_lseek_r(fp->_data, fp->_file, (_fpos_t)0, SEEK_END);
    fp->_flags &= ~__SOFF; /* in case O_APPEND mode is set */
    return _write_r(fp->_data, fp->_file, buf, n);
}

_fpos_t __sseek(void *cookie, _fpos_t offset, int whence)
{
    register FILE *fp = (FILE *)cookie;
    register _fpos_t ret;

    ret = _lseek_r(fp->_data, fp->_file, offset, whence);
    if (ret == -1L)
        fp->_flags &= ~__SOFF;
    else {
        fp->_flags |= __SOFF;
        fp->_offset = ret;
    }
    return ret;
}

int __sclose(void *cookie)
{
    FILE *fp = (FILE *)cookie;

    return _close_r(fp->_data, fp->_file);
}
