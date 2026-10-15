#include "../common/types.h"
#include <stdarg.h>

// 002ffd78: newlib's _vfprintf_r (libc/stdio/vfprintf.c, the 4.4BSD-derived one with
// _mbtowc_r format scanning), built as C by the game's gcc 3.2. Configured with
// _NO_LONGLONG (long is 64-bit here, so QUADINT == LONGINT) and _NO_LONGDBL.
// Compiled as C: C++ turns the `a || flags & ALT` tests into bools (extra andi 0xff).

// newlib stdio FILE (only the fields vfprintf touches)
struct __sbuf { u8* _base; s32 _size; };
struct __sFILE {
    u8* _p; s32 _r; s32 _w;
    s16 _flags; s16 _file;
    struct __sbuf _bf;
};
struct __siov { const void* iov_base; s32 iov_len; };
struct __suio { struct __siov* uio_iov; s32 uio_iovcnt; s32 uio_resid; };
struct lconv { char* decimal_point; };

struct lconv* func_003037e8(void);                              // localeconv
s32 func_003015f8(struct __sFILE* fp);                          // __swsetup
s32 func_002ffc50(struct __sFILE* fp, const char* fmt, va_list ap); // __sbprintf
s32 func_002ffc08(struct __sFILE* fp, struct __suio* uio);      // __sprint
s32 func_00303958(void* r, s32* pwc, const char* s, s32 n, s32* state); // _mbtowc_r
u32 func_002ff3fc(const char* s);                               // strlen
void* func_00303988(const void* s, s32 c, u32 n);               // memchr
char* func_003012d8(void* data, double value, s32 ndigits, s32 flags, char* sign,
                    s32* decpt, s32 ch, s32* length);           // cvt
s32 func_00301480(char* p0, s32 exp, s32 fmtch);                // exponent
s32 func_00304d68(double d);                                    // isinf
s32 func_00304db0(double d);                                    // isnan

// The soft-float double compares (_fpvalue < 0, == 0, if (_fpvalue)) become libcalls to
// dpcmp, which lives in the game itself at 0x3142e0.
asm("dpcmp = func_003142e0");

extern void* D_00365c48;            // _impure_ptr
extern s32 D_003660b4;              // __mb_cur_max
extern const char D_003778e8[16];   // blanks
extern const char D_003778f8[16];   // zeroes
extern const char D_00377908[];     // "bug in vfprintf: bad base"
extern const char D_00377928[];     // "0"
extern const char D_00377930[];     // "."
extern const char D_00377938[];     // "0123456789ABCDEF"
extern const char D_00377950[];     // "Inf"
extern const char D_00377958[];     // "NaN"
extern const char D_00377960[];     // "0123456789abcdef"
extern const char D_00377978[];     // "(null)"

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
        if (func_002ffc08(fp, &uio)) \
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
    if (uio.uio_resid && func_002ffc08(fp, &uio)) \
        goto error; \
    uio.uio_iovcnt = 0; \
    iovp = iov; \
}

#define SARG() \
    (flags & LONGINT ? va_arg(ap, s64) : \
     flags & SHORTINT ? (s64)(s16)va_arg(ap, s32) : \
     (s64)va_arg(ap, s32))
#define UARG() \
    (flags & LONGINT ? va_arg(ap, u64) : \
     flags & SHORTINT ? (u64)(u16)va_arg(ap, s32) : \
     (u64)va_arg(ap, u32))

s32 func_002ffd78(void* data, struct __sFILE* fp, const char* fmt0, va_list ap)
{
    char* fmt;
    s32 ch;
    s32 n, m;
    char* cp;
    struct __siov* iovp;
    s32 flags;
    s32 ret;
    s32 width;
    s32 prec;
    char sign;
    s32 wc;
    char* decimal_point = func_003037e8()->decimal_point;
    char softsign;
    union { s32 i; double d; } _double_ = {0};
    s32 expt;
    s32 expsize = 0;
    s32 ndig;
    char expstr[7];
    u64 _uquad;
    enum { OCT, DEC, HEX } base;
    s32 dprec;
    s32 realsz;
    s32 size;
    const char* xdigs = 0;
    struct __suio uio;
    struct __siov iov[NIOV];
    char buf[BUF];
    char ox[2];
    s32 state = 0;

    if (((fp->_flags & 0x8) == 0 || fp->_bf._base == 0) && func_003015f8(fp))
        return -1;

    if ((fp->_flags & 0x1a) == 0x0a && fp->_file >= 0)
        return func_002ffc50(fp, fmt0, ap);

    fmt = (char*)fmt0;
    uio.uio_iov = iovp = iov;
    uio.uio_resid = 0;
    uio.uio_iovcnt = 0;
    ret = 0;

    for (;;) {
        cp = fmt;
        while ((n = func_00303958(D_00365c48, &wc, fmt, D_003660b4, &state)) > 0) {
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
            if ((width = va_arg(ap, s32)) >= 0)
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
                n = va_arg(ap, s32);
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
            *(cp = buf) = va_arg(ap, s32);
            size = 1;
            sign = '\0';
            break;
        case 'D':
            flags |= LONGINT;
            /*FALLTHROUGH*/
        case 'd':
        case 'i':
            _uquad = SARG();
            if ((s64)_uquad < 0) {
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

            if (func_00304d68(_double_.d)) {
                if (_double_.d < 0)
                    sign = '-';
                cp = (char*)D_00377950;
                size = 3;
                break;
            }
            if (func_00304db0(_double_.d)) {
                cp = (char*)D_00377958;
                size = 3;
                break;
            }

            flags |= FPT;
            cp = func_003012d8(data, _double_.d, prec, flags, &softsign,
                               &expt, ch, &ndig);
            if (ch == 'g' || ch == 'G') {
                if (expt <= -4 || expt > prec)
                    ch = (ch == 'g') ? 'e' : 'E';
                else
                    ch = 'g';
            }
            if (ch <= 'e') {
                --expt;
                expsize = func_00301480(expstr, expt, ch);
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
                *va_arg(ap, s64*) = ret;
            else if (flags & SHORTINT)
                *va_arg(ap, s16*) = ret;
            else
                *va_arg(ap, s32*) = ret;
            continue;
        case 'O':
            flags |= LONGINT;
            /*FALLTHROUGH*/
        case 'o':
            _uquad = UARG();
            base = OCT;
            goto nosign;
        case 'p':
            _uquad = (u64)(s64)(s32)va_arg(ap, void*);
            base = HEX;
            xdigs = D_00377960;
            flags |= HEXPREFIX;
            ch = 'x';
            goto nosign;
        case 's':
            if ((cp = va_arg(ap, char*)) == 0)
                cp = (char*)D_00377978;
            if (prec >= 0) {
                char* p = (char*)func_00303988(cp, 0, prec);
                if (p != 0) {
                    size = p - cp;
                    if (size > prec)
                        size = prec;
                } else
                    size = prec;
            } else
                size = func_002ff3fc(cp);
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
            xdigs = D_00377938;
            goto hex;
        case 'x':
            xdigs = D_00377960;
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
                    cp = (char*)D_00377908;
                    size = func_002ff3fc(cp);
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
            PAD(width - realsz, D_003778e8);

        if (sign) {
            PRINT(&sign, 1);
        } else if (flags & HEXPREFIX) {
            ox[0] = '0';
            ox[1] = ch;
            PRINT(ox, 2);
        }

        if ((flags & (LADJUST | ZEROPAD)) == ZEROPAD)
            PAD(width - realsz, D_003778f8);

        PAD(dprec - size, D_003778f8);

        if ((flags & FPT) == 0) {
            PRINT(cp, size);
        } else {
            if (ch >= 'f') {
                if (_double_.d == 0) {
                    PRINT(D_00377928, 1);
                    if (expt < ndig || (flags & ALT) != 0) {
                        PRINT(decimal_point, 1);
                        PAD(ndig - 1, D_003778f8);
                    }
                } else if (expt <= 0) {
                    PRINT(D_00377928, 1);
                    if (expt || ndig) {
                        PRINT(decimal_point, 1);
                        PAD(-expt, D_003778f8);
                        PRINT(cp, ndig);
                    }
                } else if (expt >= ndig) {
                    PRINT(cp, ndig);
                    PAD(expt - ndig, D_003778f8);
                    if (flags & ALT)
                        PRINT(D_00377930, 1);
                } else {
                    PRINT(cp, expt);
                    cp += expt;
                    PRINT(D_00377930, 1);
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
                        PAD(ndig - 1, D_003778f8);
                } else
                    PRINT(cp, 1);
                PRINT(expstr, expsize);
            }
        }

        if (flags & LADJUST)
            PAD(width - realsz, D_003778e8);

        ret += width > realsz ? width : realsz;

        FLUSH();
    }
done:
    FLUSH();
error:
    return (fp->_flags & 0x40) ? -1 : ret;
}

