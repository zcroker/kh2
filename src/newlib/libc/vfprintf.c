/* vfprintf.c: newlib libc (libc/stdio/vfprintf.c, the 4.4BSD-derived one), the copy the game links from the
 * toolchain's libc.a. Linked unit 0x2ffc08-0x301550 with its .rodata at 0x3778e8 (blanks, zeroes, the strings and
 * the format switch table): __sprint, __sbprintf, vfprintf, _vfprintf_r, cvt, exponent. Built with _NO_LONGLONG
 * (long is 64-bit here, so QUADINT == LONGINT) and _NO_LONGDBL.
 * Third-party code notice: rebuilt to match; not covered by this project's MIT License.
 * Copyright (c) 1990 The Regents of the University of California. All rights reserved.
 * This code is derived from software contributed to Berkeley by Chris Torek. Redistribution and use in source
 * and binary forms, with or without modification, are permitted under the BSD license (see COPYING.NEWLIB). */
#include "local.h"
#include <stdarg.h>
asm("localeconv = func_003037e8");
asm("_mbtowc_r = func_00303958");
asm("__mb_cur_max = D_003660b4");
asm("isinf = func_00304d68");
asm("isnan = func_00304db0");
/* The soft-float double routines live in the game itself (libgcc's fp-bit copies). */
asm("dpcmp = func_003142e0");
asm("dpsub = __subdf3");

#define BUFSIZ 1024
#define MAXEXP 40
#define quad_t long
#define u_quad_t unsigned long
typedef unsigned long u_long;
typedef unsigned short u_short;
typedef unsigned int u_int;

struct lconv { char *decimal_point; };
struct lconv *localeconv(void);
extern int __mb_cur_max;
#define MB_CUR_MAX __mb_cur_max
int _mbtowc_r(struct _reent *, int *, const char *, size_t, int *);
int __sfvwrite(FILE *, struct __suio *);
int fflush(FILE *);
int __swsetup(FILE *);
size_t strlen(const char *);
void *memchr(const void *, int, size_t);
int isinf(double);
int isnan(double);
char *_dtoa_r(struct _reent *, double, int, int, int *, int *, char **);
int _vfprintf_r(struct _reent *, FILE *, const char *, va_list);
int vfprintf(FILE *, const char *, va_list);
static char *cvt(struct _reent *, double, int, int, char *, int *, int, int *);
static int exponent(char *, int, int);

#define cantwrite(fp) \
    ((((fp)->_flags & __SWR) == 0 || (fp)->_bf._base == NULL) && __swsetup(fp))

/*
 * Flush out all the vectors defined by the given uio,
 * then reset it so that it can be reused.
 */
static int __sprint(FILE *fp, register struct __suio *uio)
{
    register int err;

    if (uio->uio_resid == 0) {
        uio->uio_iovcnt = 0;
        return (0);
    }
    err = __sfvwrite(fp, uio);
    uio->uio_resid = 0;
    uio->uio_iovcnt = 0;
    return (err);
}

/*
 * Helper function for `fprintf to unbuffered unix file': creates a
 * temporary buffer.  We only work on write-only files; this avoids
 * worries about ungetc buffers and so forth.
 */
static int __sbprintf(register FILE *fp, const char *fmt, va_list ap)
{
    int ret;
    FILE fake;
    unsigned char buf[BUFSIZ];

    /* copy the important variables */
    fake._data = fp->_data;
    fake._flags = fp->_flags & ~__SNBF;
    fake._file = fp->_file;
    fake._cookie = fp->_cookie;
    fake._write = fp->_write;

    /* set up the buffer */
    fake._bf._base = fake._p = buf;
    fake._bf._size = fake._w = sizeof(buf);
    fake._lbfsize = 0;          /* not actually used, but Just In Case */

    /* do the work, then copy any error status */
    ret = vfprintf(&fake, fmt, ap);
    if (ret >= 0 && fflush(&fake))
        ret = EOF;
    if (fake._flags & __SERR)
        fp->_flags |= __SERR;
    return (ret);
}

int vfprintf(FILE *fp, const char *fmt0, va_list ap)
{
    CHECK_INIT(fp);
    return _vfprintf_r(fp->_data, fp, fmt0, ap);
}

#define BUF 348
#define DEFPREC 6
#define NIOV 8
#define PADSIZE 16

#define to_digit(c) ((c) - '0')
#define is_digit(c) ((unsigned)to_digit(c) <= 9)
#define to_char(n)  ((n) + '0')

#define ALT       0x001
#define HEXPREFIX 0x002
#define LADJUST   0x004
#define LONGDBL   0x008
#define LONGINT   0x010
#define QUADINT   LONGINT
#define SHORTINT  0x040
#define ZEROPAD   0x080
#define FPT       0x100

#define PRINT(ptr, len) { \
    iovp->iov_base = (ptr); \
    iovp->iov_len = (len); \
    uio.uio_resid += (len); \
    iovp++; \
    if (++uio.uio_iovcnt >= NIOV) { \
        if (__sprint(fp, &uio)) \
            goto error; \
        iovp = iov; \
    } \
}
#define PAD(howmany, with) { \
    if ((n = (howmany)) > 0) { \
        while (n > PADSIZE) { \
            PRINT(with, PADSIZE); \
            n -= PADSIZE; \
        } \
        PRINT(with, n); \
    } \
}
#define FLUSH() { \
    if (uio.uio_resid && __sprint(fp, &uio)) \
        goto error; \
    uio.uio_iovcnt = 0; \
    iovp = iov; \
}

#define SARG() \
    (flags & LONGINT ? va_arg(ap, long) : \
     flags & SHORTINT ? (long)(short)va_arg(ap, int) : \
     (long)va_arg(ap, int))
#define UARG() \
    (flags & LONGINT ? va_arg(ap, u_long) : \
     flags & SHORTINT ? (u_long)(u_short)va_arg(ap, int) : \
     (u_long)va_arg(ap, u_int))

int _vfprintf_r(struct _reent *data, FILE *fp, const char *fmt0, va_list ap)
{
    char *fmt;
    int ch;
    int n, m;
    char *cp;
    struct __siov* iovp;
    int flags;
    int ret;
    int width;
    int prec;
    char sign;
    int wc;
    char *decimal_point = localeconv()->decimal_point;
    char softsign;
    union { int i; double d; } _double_ = {0};
    int expt;
    int expsize = 0;
    int ndig;
    char expstr[7];
    u_quad_t _uquad;
    enum { OCT, DEC, HEX } base;
    int dprec;
    int realsz;
    int size;
    const char *xdigs = 0;
    struct __suio uio;
    struct __siov iov[NIOV];
    char buf[BUF];
    char ox[2];
    int state = 0;
    static const char blanks[PADSIZE] =
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    static const char zeroes[PADSIZE] =
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};

    if (cantwrite(fp))
        return (EOF);

    if ((fp->_flags & (__SNBF | __SWR | __SRW)) == (__SNBF | __SWR) && fp->_file >= 0)
        return __sbprintf(fp, fmt0, ap);

    fmt = (char*)fmt0;
    uio.uio_iov = iovp = iov;
    uio.uio_resid = 0;
    uio.uio_iovcnt = 0;
    ret = 0;

    for (;;) {
        cp = fmt;
        while ((n = _mbtowc_r(_REENT, &wc, fmt, MB_CUR_MAX, &state)) > 0) {
            fmt += n;
            if (wc == '%') {
                fmt--;
                break;
            }
        }
        if ((m = fmt - cp) != 0) {
            PRINT(cp, m);
            ret += m;
        }
        if (n <= 0)
            goto done;
        fmt++;

        flags = 0;
        dprec = 0;
        width = 0;
        prec = -1;
        sign = '\0';

rflag:  ch = *fmt++;
reswitch:
        switch (ch) {
        case ' ':
            if (!sign)
                sign = ' ';
            goto rflag;
        case '#':
            flags |= ALT;
            goto rflag;
        case '*':
            if ((width = va_arg(ap, int)) >= 0)
                goto rflag;
            width = -width;
            /* FALLTHROUGH */
        case '-':
            flags |= LADJUST;
            goto rflag;
        case '+':
            sign = '+';
            goto rflag;
        case '.':
            if ((ch = *fmt++) == '*') {
                n = va_arg(ap, int);
                prec = n < 0 ? -1 : n;
                goto rflag;
            }
            n = 0;
            while (is_digit(ch)) {
                n = 10 * n + to_digit(ch);
                ch = *fmt++;
            }
            prec = n < 0 ? -1 : n;
            goto reswitch;
        case '0':
            flags |= ZEROPAD;
            goto rflag;
        case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            n = 0;
            do {
                n = 10 * n + to_digit(ch);
                ch = *fmt++;
            } while (is_digit(ch));
            width = n;
            goto reswitch;
        case 'L':
            flags |= LONGDBL;
            goto rflag;
        case 'h':
            flags |= SHORTINT;
            goto rflag;
        case 'l':
            if (*fmt == 'l') {
                fmt++;
                flags |= QUADINT;
            } else {
                flags |= LONGINT;
            }
            goto rflag;
        case 'q':
            flags |= QUADINT;
            goto rflag;
        case 'c':
            *(cp = buf) = va_arg(ap, int);
            size = 1;
            sign = '\0';
            break;
        case 'D':
            flags |= LONGINT;
            /*FALLTHROUGH*/
        case 'd':
        case 'i':
            _uquad = SARG();
            if ((quad_t)_uquad < 0) {
                _uquad = -_uquad;
                sign = '-';
            }
            base = DEC;
            goto number;
        case 'e':
        case 'E':
        case 'f':
        case 'g':
        case 'G':
            if (prec == -1) {
                prec = DEFPREC;
            } else if ((ch == 'g' || ch == 'G') && prec == 0) {
                prec = 1;
            }

            if (flags & LONGDBL) {
                _double_.d = (double)va_arg(ap, long double);
            } else {
                _double_.d = va_arg(ap, double);
            }

            if (isinf(_double_.d)) {
                if (_double_.d < 0)
                    sign = '-';
                cp = "Inf";
                size = 3;
                break;
            }
            if (isnan(_double_.d)) {
                cp = "NaN";
                size = 3;
                break;
            }

            flags |= FPT;
            cp = cvt(data, _double_.d, prec, flags, &softsign,
                               &expt, ch, &ndig);
            if (ch == 'g' || ch == 'G') {
                if (expt <= -4 || expt > prec)
                    ch = (ch == 'g') ? 'e' : 'E';
                else
                    ch = 'g';
            }
            if (ch <= 'e') {
                --expt;
                expsize = exponent(expstr, expt, ch);
                size = expsize + ndig;
                if (ndig > 1 || flags & ALT)
                    ++size;
            } else if (ch == 'f') {
                if (expt > 0) {
                    size = expt;
                    if (prec || flags & ALT)
                        size += prec + 1;
                } else
                    size = prec + 2;
            } else if (expt >= ndig) {
                size = expt;
                if (flags & ALT)
                    ++size;
            } else
                size = ndig + (expt > 0 ? 1 : 2 - expt);

            if (softsign)
                sign = '-';
            break;
        case 'n':
            if (flags & LONGINT)
                *va_arg(ap, long *) = ret;
            else if (flags & SHORTINT)
                *va_arg(ap, short *) = ret;
            else
                *va_arg(ap, int *) = ret;
            continue;
        case 'O':
            flags |= LONGINT;
            /*FALLTHROUGH*/
        case 'o':
            _uquad = UARG();
            base = OCT;
            goto nosign;
        case 'p':
            _uquad = (u_quad_t)(unsigned long)va_arg(ap, void *);
            base = HEX;
            xdigs = "0123456789abcdef";
            flags |= HEXPREFIX;
            ch = 'x';
            goto nosign;
        case 's':
            if ((cp = va_arg(ap, char *)) == 0)
                cp = "(null)";
            if (prec >= 0) {
                char *p = (char*)memchr(cp, 0, prec);
                if (p != 0) {
                    size = p - cp;
                    if (size > prec)
                        size = prec;
                } else
                    size = prec;
            } else
                size = strlen(cp);
            sign = '\0';
            break;
        case 'U':
            flags |= LONGINT;
            /*FALLTHROUGH*/
        case 'u':
            _uquad = UARG();
            base = DEC;
            goto nosign;
        case 'X':
            xdigs = "0123456789ABCDEF";
            goto hex;
        case 'x':
            xdigs = "0123456789abcdef";
hex:        _uquad = UARG();
            base = HEX;
            if (flags & ALT && _uquad != 0)
                flags |= HEXPREFIX;
nosign:     sign = '\0';
number:     if ((dprec = prec) >= 0)
                flags &= ~ZEROPAD;

            cp = buf + BUF;
            if (_uquad != 0 || prec != 0) {
                switch (base) {
                case OCT:
                    do {
                        *--cp = to_char(_uquad & 7);
                        _uquad >>= 3;
                    } while (_uquad);
                    if (flags & ALT && *cp != '0')
                        *--cp = '0';
                    break;
                case DEC:
                    while (_uquad >= 10) {
                        *--cp = to_char(_uquad % 10);
                        _uquad = _uquad / 10;
                    }
                    *--cp = to_char(_uquad);
                    break;
                case HEX:
                    do {
                        *--cp = xdigs[_uquad & 15];
                        _uquad >>= 4;
                    } while (_uquad);
                    break;
                default:
                    cp = "bug in vfprintf: bad base";
                    size = strlen(cp);
                    goto skipsize;
                }
            } else if (base == OCT && (flags & ALT))
                *--cp = '0';

            size = buf + BUF - cp;
skipsize:
            break;
        default:
            if (ch == '\0')
                goto done;
            cp = buf;
            *cp = ch;
            size = 1;
            sign = '\0';
            break;
        }

        realsz = dprec > size ? dprec : size;
        if (sign)
            realsz++;
        else if (flags & HEXPREFIX)
            realsz += 2;

        if ((flags & (LADJUST | ZEROPAD)) == 0)
            PAD(width - realsz, blanks);

        if (sign) {
            PRINT(&sign, 1);
        } else if (flags & HEXPREFIX) {
            ox[0] = '0';
            ox[1] = ch;
            PRINT(ox, 2);
        }

        if ((flags & (LADJUST | ZEROPAD)) == ZEROPAD)
            PAD(width - realsz, zeroes);

        PAD(dprec - size, zeroes);

        if ((flags & FPT) == 0) {
            PRINT(cp, size);
        } else {
            if (ch >= 'f') {
                if (_double_.d == 0) {
                    PRINT("0", 1);
                    if (expt < ndig || (flags & ALT) != 0) {
                        PRINT(decimal_point, 1);
                        PAD(ndig - 1, zeroes);
                    }
                } else if (expt <= 0) {
                    PRINT("0", 1);
                    if (expt || ndig) {
                        PRINT(decimal_point, 1);
                        PAD(-expt, zeroes);
                        PRINT(cp, ndig);
                    }
                } else if (expt >= ndig) {
                    PRINT(cp, ndig);
                    PAD(expt - ndig, zeroes);
                    if (flags & ALT)
                        PRINT(".", 1);
                } else {
                    PRINT(cp, expt);
                    cp += expt;
                    PRINT(".", 1);
                    PRINT(cp, ndig - expt);
                }
            } else {
                if (ndig > 1 || flags & ALT) {
                    ox[0] = *cp++;
                    ox[1] = '.';
                    PRINT(ox, 2);
                    if (_double_.d) {
                        PRINT(cp, ndig - 1);
                    } else
                        PAD(ndig - 1, zeroes);
                } else
                    PRINT(cp, 1);
                PRINT(expstr, expsize);
            }
        }

        if (flags & LADJUST)
            PAD(width - realsz, blanks);

        ret += width > realsz ? width : realsz;

        FLUSH();
    }
done:
    FLUSH();
error:
    return (fp->_flags & __SERR) ? EOF : ret;
}


static char *cvt(struct _reent *data, double value, int ndigits, int flags, char *sign, int *decpt, int ch,
                 int *length)
{
    int mode, dsgn;
    char *digits, *bp, *rve;
    union { double d; struct { unsigned int lo, hi; } w; } tmp;

    if (ch == 'f') {
        mode = 3;               /* ndigits after the decimal point */
    } else {
        /* To obtain ndigits after the decimal point for the 'e'
         * and 'E' formats, round to ndigits + 1 significant
         * figures.
         */
        if (ch == 'e' || ch == 'E') {
            ndigits++;
        }
        mode = 2;               /* ndigits significant digits */
    }

    tmp.d = value;
    if (tmp.w.hi & 0x80000000) { /* this will check for < 0 and -0.0 */
        value = -value;
        *sign = '-';
    } else
        *sign = '\000';
    digits = _dtoa_r(data, value, mode, ndigits, decpt, &dsgn, &rve);
    if ((ch != 'g' && ch != 'G') || flags & ALT) { /* Print trailing zeros */
        bp = digits + ndigits;
        if (ch == 'f') {
            if (*digits == '0' && value)
                *decpt = -ndigits + 1;
            bp += *decpt;
        }
        if (value == 0)         /* kludge for __dtoa irregularity */
            rve = bp;
        while (rve < bp)
            *rve++ = '0';
    }
    *length = rve - digits;
    return (digits);
}

static int exponent(char *p0, int exp, int fmtch)
{
    register char *p, *t;
    char expbuf[MAXEXP];

    p = p0;
    *p++ = fmtch;
    if (exp < 0) {
        exp = -exp;
        *p++ = '-';
    } else
        *p++ = '+';
    t = expbuf + MAXEXP;
    if (exp > 9) {
        do {
            *--t = to_char(exp % 10);
        } while ((exp /= 10) > 9);
        *--t = to_char(exp);
        for (; t < expbuf + MAXEXP; *p++ = *t++)
            ;
    } else {
        *p++ = '0';
        *p++ = to_char(exp);
    }
    return (p - p0);
}
