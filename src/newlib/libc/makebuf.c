/* makebuf.c: newlib libc (libc/stdio/makebuf.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x303808-0x303958. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "local.h"
asm("isatty = func_00305dd0");
#define BUFSIZ 1024
#define S_IFMT 0170000
#define S_IFCHR 0020000
#define S_IFREG 0100000
struct stat {
    short st_dev;
    unsigned short st_ino;
    unsigned int st_mode;
    unsigned short st_nlink;
    unsigned short st_uid;
    unsigned short st_gid;
    short st_rdev;
    long st_size;
    long st_atime;
    long st_spare1;
    long st_mtime;
    long st_spare2;
    long st_ctime;
    long st_spare3;
    long st_blksize;
    long st_blocks;
    long st_spare4[2];
};
int _fstat_r(struct _reent *, int, struct stat *);
void *_malloc_r(struct _reent *, size_t);
int isatty(int);
void _cleanup_r(struct _reent *);
_fpos_t __sseek(void *, _fpos_t, int);

/*
 * Allocate a file buffer, or switch to unbuffered I/O.
 * Per the ANSI C standard, ALL tty devices default to line buffered.
 *
 * As a side effect, we set __SOPT or __SNPT (en/dis-able fseek
 * optimization) right after the _fstat() that finds the buffer size.
 */
void __smakebuf(register FILE *fp)
{
    register size_t size, couldbetty;
    register void *p;
    struct stat st;

    if (fp->_flags & __SNBF) {
        fp->_bf._base = fp->_p = fp->_nbuf;
        fp->_bf._size = 1;
        return;
    }
    if (fp->_file < 0 || _fstat_r(fp->_data, fp->_file, &st) < 0) {
        couldbetty = 0;
        size = BUFSIZ;
        /* do not try to optimise fseek() */
        fp->_flags |= __SNPT;
    } else {
        couldbetty = (st.st_mode & S_IFMT) == S_IFCHR;
        size = BUFSIZ;
        /*
         * Optimize fseek() only if it is a regular file.
         * (The test for __sseek is mainly paranoia.)
         */
        if ((st.st_mode & S_IFMT) == S_IFREG && fp->_seek == __sseek) {
            fp->_flags |= __SOPT;
            fp->_blksize = 1024;
        } else
            fp->_flags |= __SNPT;
    }
    if ((p = _malloc_r(fp->_data, size)) == NULL) {
        fp->_flags |= __SNBF;
        fp->_bf._base = fp->_p = fp->_nbuf;
        fp->_bf._size = 1;
    } else {
        fp->_data->__cleanup = _cleanup_r;
        fp->_flags |= __SMBF;
        fp->_bf._base = fp->_p = (unsigned char *)p;
        fp->_bf._size = size;
        if (couldbetty && isatty(fp->_file))
            fp->_flags |= __SLBF;
    }
}
