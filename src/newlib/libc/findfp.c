/* findfp.c: newlib libc (libc/stdio/findfp.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x302c28-0x302e90 (std, __sfmoreglue, __sfp, _cleanup_r, _cleanup, __sinit). Third-party code notice: rebuilt to match; not covered by this project's MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#define KH2_DEFINES_SINIT
#include "local.h"
asm("__swrite = func_00304e48");
asm("__sseek = func_00304ec8");
asm("__sclose = func_00304f30");
asm("_fwalk = func_00303698");
asm("memset = func_002fde18");
#define NDYNAMIC 4
#define ENOMEM 12
int __sread(void *, char *, int);
int __swrite(void *, const char *, int);
_fpos_t __sseek(void *, _fpos_t, int);
int __sclose(void *);
int _fwalk(struct _reent *, int (*)(FILE *));
int fflush(FILE *);
void *_malloc_r(struct _reent *, size_t);
void *memset(void *, int, size_t);

static void std(FILE *ptr, int flags, int file, struct _reent *data)
{
    ptr->_p = 0;
    ptr->_r = 0;
    ptr->_w = 0;
    ptr->_flags = flags;
    ptr->_file = file;
    ptr->_bf._base = 0;
    ptr->_bf._size = 0;
    ptr->_lbfsize = 0;
    ptr->_cookie = ptr;
    ptr->_read = __sread;
    ptr->_write = __swrite;
    ptr->_seek = __sseek;
    ptr->_close = __sclose;
    ptr->_data = data;
}

struct _glue *__sfmoreglue(struct _reent *d, register int n)
{
    struct _glue *g;
    FILE *p;

    g = (struct _glue *)_malloc_r(d, sizeof(*g) + n * sizeof(FILE));
    if (g == NULL)
        return NULL;
    p = (FILE *)(g + 1);
    g->_next = NULL;
    g->_niobs = n;
    g->_iobs = p;
    memset(p, 0, n * sizeof(FILE));
    return g;
}

/*
 * Find a free FILE for fopen et al.
 */
FILE *__sfp(struct _reent *d)
{
    FILE *fp;
    int n;
    struct _glue *g;

    if (!d->__sdidinit)
        __sinit(d);
    for (g = &d->__sglue;; g = g->_next) {
        for (fp = g->_iobs, n = g->_niobs; --n >= 0; fp++)
            if (fp->_flags == 0)
                goto found;
        if (g->_next == NULL &&
            (g->_next = __sfmoreglue(d, NDYNAMIC)) == NULL)
            break;
    }
    d->_errno = ENOMEM;
    return NULL;

found:
    fp->_flags = 1;             /* reserve this slot; caller sets real flags */
    fp->_p = NULL;              /* no current pointer */
    fp->_w = 0;                 /* nothing to read or write */
    fp->_r = 0;
    fp->_bf._base = NULL;       /* no buffer */
    fp->_bf._size = 0;
    fp->_lbfsize = 0;           /* not line buffered */
    fp->_file = -1;             /* no file */
    fp->_ub._base = NULL;       /* no ungetc buffer */
    fp->_ub._size = 0;
    fp->_lb._base = NULL;       /* no line buffer */
    fp->_lb._size = 0;
    fp->_data = d;
    return fp;
}

/*
 * exit() calls _cleanup() through *__cleanup, set whenever we
 * open or buffer a file.
 */
void _cleanup_r(struct _reent *ptr)
{
    (void)_fwalk(ptr, fflush);
}

void _cleanup(void)
{
    _cleanup_r(_impure_ptr);
}

/*
 * __sinit() is called whenever stdio's state variables must be initialized.
 */
void __sinit(struct _reent *s)
{
    /* make sure we clean up on exit */
    s->__cleanup = _cleanup_r;  /* conservative */
    s->__sdidinit = 1;

    s->__sglue._next = NULL;
    s->__sglue._niobs = 3;
    s->__sglue._iobs = &s->__sf[0];

    std(s->_stdin, __SRD, 0, s);
    std(s->_stdout, __SWR | __SLBF, 1, s);
    std(s->_stderr, __SWR | __SNBF, 2, s);
}
