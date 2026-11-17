/* newlib.h: the parts of newlib's headers (sys/reent.h, stdlib.h, string.h) that the libc objects in this folder
 * use, for the toolchain's EE build of libc.a (gcc 3.2-ee-040921: int and pointers 32-bit, long 64-bit). The
 * game links libc.a unchanged, so each original object is its own linked unit (one row each in linked_units.tsv),
 * built with ee-gcc 3.2 -O2 -G0 -fno-builtin. Callees outside these units are bound to their game addresses with
 * asm aliases (`asm("raise = func_002fed10");`), so the plain newlib names stay in the source.
 * Third-party code notice: newlib is not covered by this project's MIT License; see each file's notice. */
#ifndef KH2_NEWLIB_H
#define KH2_NEWLIB_H
typedef unsigned int size_t;
#define NULL ((void *)0)

struct _atexit {
    struct _atexit *_next;
    int _ind;
    void (*_fns[32])(void);
};

struct __sbuf {
    unsigned char *_base;
    int _size;
};

typedef long _fpos_t;
struct __sFILE {
    unsigned char *_p;          /* 0: current position in (some) buffer */
    int _r;                     /* 4: read space left for getc() */
    int _w;                     /* 8: write space left for putc() */
    short _flags;               /* 12 */
    short _file;                /* 14 */
    struct __sbuf _bf;          /* 16: the buffer */
    int _lbfsize;               /* 24 */
    void *_cookie;              /* 28 */
    int (*_read)(void *, char *, int);           /* 32 */
    int (*_write)(void *, const char *, int);    /* 36 */
    _fpos_t (*_seek)(void *, _fpos_t, int);      /* 40 */
    int (*_close)(void *);                       /* 44 */
    struct __sbuf _ub;          /* 48: ungetc buffer */
    unsigned char *_up;         /* 56 */
    int _ur;                    /* 60 */
    unsigned char _ubuf[3];     /* 64 */
    unsigned char _nbuf[1];     /* 67 */
    struct __sbuf _lb;          /* 68: fgetline buffer */
    int _blksize;               /* 76 */
    int _offset;                /* 80 */
    struct _reent *_data;       /* 84 */
};
typedef struct __sFILE FILE;

struct __siov {
    const void *iov_base;
    size_t iov_len;
};
struct __suio {
    struct __siov *uio_iov;
    int uio_iovcnt;
    int uio_resid;
};
#define EOF (-1)

struct __tm {
    int __tm_sec, __tm_min, __tm_hour, __tm_mday, __tm_mon, __tm_year, __tm_wday, __tm_yday, __tm_isdst;
};

struct _reent {
    int _errno;                 /* 0 */
    struct __sFILE *_stdin, *_stdout, *_stderr; /* 4 */
    int _inc;                   /* 16 */
    char _emergency[25];        /* 20 */
    int _current_category;      /* 48 */
    const char *_current_locale; /* 52 */
    int __sdidinit;             /* 56 */
    void (*__cleanup)(struct _reent *); /* 60 */
    struct _Bigint *_result;    /* 64 */
    int _result_k;
    struct _Bigint *_p5s;
    struct _Bigint **_freelist;
    int _cvtlen;
    char *_cvtbuf;
    union {                     /* 88 */
        struct {
            unsigned int _unused_rand;
            char *_strtok_last;
            char _asctime_buf[26];
            struct __tm _localtime_buf;
            int _gamma_signgam;
            unsigned long long _rand_next; /* 168 */
        } _reent;
        char _pad[240];
    } _new;
    struct _atexit *_atexit;    /* 328 */
    struct _atexit _atexit0;    /* 332 */
    void (**_sig_func)(int);    /* 468 */
    struct _glue {              /* 472 */
        struct _glue *_next;
        int _niobs;
        struct __sFILE *_iobs;
    } __sglue;
    struct __sFILE __sf[3];     /* 484 */
};

extern struct _reent *_impure_ptr;
#define _stdout_r(x) ((x)->_stdout)
asm("_impure_ptr = D_00365c48"); /* libc/reent/impure.c, not linked as a unit yet */
#endif
