/* Sony PS2 Runtime Library 3.0.0: libkernl printf (kprintf.o), 0x306e48-0x3081d0. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: these functions were rebuilt to match Sony Computer Entertainment's
 * PS2 runtime libraries that the game links. That code is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv). Output goes to the SIO port, the Deci2 console (a 128-byte line
 * buffer) or a string; func_003071d0 is the formatter, func_00306ff8 its %e/%f helper. */
typedef char *va_list;
/* gcc 2.9 EABI va-mips.h va_start: register save area starts below the incoming args */
#define va_start(v,l) (v = (va_list)__builtin_next_arg(l) - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
typedef int (*OutFn)(void *, int *, int);

extern int DIntr(void);
extern int EIntr(void);
extern void func_003111f0(char *);

/* SIO putc: wait while the TX FIFO is full, then write the byte. */
int func_00306e48(int c)
{
    char *txfifo;
    while (*(volatile int *)0x1000f130 & 0x8000)
        ;
    txfifo = (char *)0x1000f180;
    asm("" : "+r"(txfifo));
    *txfifo = c;
    return c;
}

int D_003660d4 = 0;
extern char D_01e35680[];
void func_00306e80(int c)
{
    int n = D_003660d4;
    if (n >= 126) {
        D_003660d4 = 0;
        D_01e35680[127] = 0;
        func_003111f0(D_01e35680);
        n = D_003660d4;
    }
    if (c == '\n') {
        D_01e35680[n] = c;
        D_003660d4 = 0;
        D_01e35680[n + 1] = 0;
        func_003111f0(D_01e35680);
    } else {
        D_003660d4 = n + 1;
        D_01e35680[n] = c;
    }
}

void func_00306f30(int c)
{
    if (c == '\n') {
        func_00306e48('\r');
        func_00306e48('\n');
    } else
        func_00306e48(c);
}

/* double bits -> int, clamped to [0, 9999], rounded. */
typedef unsigned long u64;
long func_00306f68(u64 a)
{
    long e;
    e = (a << 1) >> 53;
    e -= 1075;
    if (e < -53) return 0;
    if (e >= 13) return 9999;
    a = (a << 12) >> 12;
    a |= (1UL << 52);
    if (e < 0) {
        e = -e;
        a >>= e - 2;
        if ((a & 3) == 3) a = (a >> 2) + 1;
        else a >>= 2;
    } else {
        a <<= e;
    }
    {
        long t = a << 32;
        asm("" : "+r"(t));
        return t >> 32;
    }
}

/* %e-style double output (soft-float helpers called directly) */
extern int func_003142e0(double, double);
extern double __subdf3(double, double);
extern double func_00313f40(double, double);
extern double func_00314190(double, double);
extern int __fixunsdfdi(double);
extern int func_00306f68_i(int) asm("func_00306f68");
int func_00307f90(void *a, void *b, int *n, const char *fmt, ...);
int func_00306ff8(int (*out)(void *, int *, int), void *arg, int *n, double d)
{
    int len = 0;
    int e = 0;
    int x;
    if (*n == 0)
        return 0;
    if (func_003142e0(d, 0.0) < 0) {
        d = __subdf3(0.0, d);
        len = 1;
        out(arg, n, '-');
        (*n)--;
    }
    if (func_003142e0(d, 0.1) < 0) {
        while (func_003142e0(d, 0.1) < 0) {
            d = func_00313f40(d, 10.0);
            e--;
        }
    } else if (func_003142e0(d, 1.0) >= 0) {
        while (func_003142e0(d, 1.0) >= 0) {
            d = func_00314190(d, 10.0);
            e++;
        }
    }
    x = func_00306f68_i(__fixunsdfdi(func_00313f40(d, 1000000.0)));
    len += func_00307f90(out, arg, n, "0.%d", x);
    if (e >= 0)
        len += func_00307f90(out, arg, n, "e+%d", e);
    else
        len += func_00307f90(out, arg, n, "e%d", e);
    return len;
}

extern long __moddi3(long, long);
extern long func_00311dd0(long, long);
extern unsigned long __umoddi3(unsigned long, unsigned long);
extern unsigned long func_00312db8(unsigned long, unsigned long);
extern float __truncdfsf2(double);
extern double func_00313b80(float);
int func_003071d0(OutFn fn, void *arg, int size, const char *fmt, va_list ap)
{
    char buf[32];
    char pre[32];
    char *end;
    char *p, *s, *q;
    const char *tab;
    int len, flags, width, prec, plen, count, n, padc, left, isstr;
    unsigned long uv;
    float f;
    register float z asm("$f0");
    int c;

    end = &buf[31];
    count = 0;
    while (*fmt) {
        flags = 0;
        width = 0;
        prec = 0;
        plen = 0;
        if (*fmt != '%')
            goto plain;
    flag:
        ++fmt;
        switch (*fmt) {
        case '-':
            flags |= 1;
            goto flag;
        case '+':
            flags |= 2;
            goto flag;
        case '0':
            flags |= 4;
            goto flag;
        case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9':
            n = 0;
            do {
                n = n * 10 + (*fmt - '0');
                fmt++;
            } while (*fmt >= '0' && *fmt <= '9');
            width = n;
        chk:
            if (*fmt == 0)
                goto next;
            fmt--;
            goto flag;
        case '.':
            flags |= 0x20;
            if (*++fmt == '*') {
                n = *(int *)((ap += 8) - 8);
                prec = n > -2 ? n : -1;
                goto flag;
            }

            n = 0;
            while (*fmt >= '0' && *fmt <= '9') {
                n = n * 10 + (*fmt - '0');
                fmt++;
            }
            prec = n > -2 ? n : -1;
            goto chk;
        case ' ':
            flags |= 8;
            goto flag;
        case '#':
            flags |= 0x10;
            goto flag;
        case 'l':
            flags |= 0x40;
            goto flag;
        case 'h':
            flags |= 0x80;
            goto flag;
        case 'o':
            if (flags & 0x40)
                uv = *(unsigned long *)((ap += 8) - 8);
            else if (flags & 0x80)
                uv = *(unsigned short *)((ap += 8) - 8);
            else
                uv = *(unsigned int *)((ap += 8) - 8);
            p = end;
            if (uv == 0) {
                if (!(flags & 0x20) || prec != 0)
                    *p-- = '0';
            } else {
                do {
                    *p-- = (uv & 7) + '0';
                    uv >>= 3;
                } while (uv != 0);
                if (flags & 0x10)
                    *p-- = '0';
            }
            s = p + 1;
            len = end - p;
            goto outn;
        case 'x':
            tab = "0123456789abcdef";
            if (flags & 0x10) {
                pre[0] = '0';
                pre[1] = 'x';
                plen = 2;
            }
            goto hex;
        case 'X':
            tab = "0123456789ABCDEF";
            if (flags & 0x10) {
                pre[0] = '0';
                pre[1] = 'X';
                plen = 2;
            }
        hex:
            if (flags & 0x40)
                uv = *(unsigned long *)((ap += 8) - 8);
            else if (flags & 0x80)
                uv = *(unsigned short *)((ap += 8) - 8);
            else
                uv = *(unsigned int *)((ap += 8) - 8);
            p = end;
            if (uv == 0) {
                plen = 0;
                if (!(flags & 0x20) || prec != 0)
                    *p-- = '0';
            } else {
                do {
                    *p-- = tab[(int)(uv & 0xf)];
                    uv >>= 4;
                } while (uv != 0);
            }
            s = p + 1;
            len = end - p;
            goto outn;
        case 'd':
        case 'i':
            if (flags & 0x40)
                uv = *(long *)((ap += 8) - 8);
            else if (flags & 0x80)
                uv = *(short *)((ap += 8) - 8);
            else
                uv = *(int *)((ap += 8) - 8);
            p = end;
            if ((long)uv >= 0) {
                if (flags & 2) {
                    pre[0] = '+';
                    plen = 1;
                } else if (flags & 8) {
                    pre[0] = ' ';
                    plen = 1;
                }
            } else {
                pre[0] = '-';
                plen = 1;
            }
            if (uv == 0) {
                if (!(flags & 0x20) || prec != 0)
                    *p-- = '0';
            } else {
                if ((long)uv < 0)
                    uv = -uv;
                while (uv != 0) {
                    *p-- = __moddi3(uv, 10) + '0';
                    uv = func_00311dd0(uv, 10);
                }
            }
            s = p + 1;
            len = end - p;
            goto outn;
        case 'u':
            if (flags & 0x40)
                uv = *(unsigned long *)((ap += 8) - 8);
            else if (flags & 0x80)
                uv = *(unsigned short *)((ap += 8) - 8);
            else
                uv = *(unsigned int *)((ap += 8) - 8);
            p = end;
            if (uv == 0) {
                if (!(flags & 0x20) || prec != 0)
                    *p-- = '0';
            } else {
                do {
                    *p-- = __umoddi3(uv, 10) + '0';
                    uv = func_00312db8(uv, 10);
                } while (uv != 0);
            }
            s = p + 1;
            len = end - p;
            goto outn;
        case 'e':
        case 'f':
            f = __truncdfsf2(*(double *)((ap += 8) - 8));
            /* the original's assembler emitted no hazard nop between mtc1 and c.eq.s here */
            __asm__ volatile (".set noreorder\n\tmtc1 $0,%0\n\t.set reorder" : "=f"(z));
            if (f == z) {
                count += fn(arg, &size, '0');
                goto next;
            }
            count += func_00306ff8(fn, arg, &size, func_00313b80(f));
            goto next;
        case 's':
            q = *(char **)((ap += 8) - 8);
            if (q == 0) {
                fn(arg, &size, '(');
                fn(arg, &size, 'n');
                fn(arg, &size, 'u');
                fn(arg, &size, 'l');
                fn(arg, &size, 'l');
                fn(arg, &size, ')');
                goto next;
            }
            p = q;
            if (flags & 0x20) {
                for (n = 0; n < prec && *p++; n++)
                    ;
                len = n;
            } else {
                len = 0;
                while (*p) {
                    p++;
                    len++;
                }
            }
            s = q;
            goto outn;
        case 'c':
            flags |= 0x100;
            prec = 1;
            p = end;
            uv = *(char *)((ap += 8) - 8);
            *p-- = uv;
            s = p + 1;
            len = end - p;
            goto outn;
        case 'p':
            uv = *(unsigned int *)((ap += 8) - 8);
            tab = "0123456789abcdef";
            p = end;
            if (uv == 0) {
                if (!(flags & 0x20) || prec != 0)
                    *p-- = '0';
            } else {
                do {
                    *p-- = tab[(int)(uv & 0xf)];
                    uv >>= 4;
                } while (uv != 0);
            }
            pre[0] = '0';
            pre[1] = 'x';
            s = p + 1;
            len = end - p;
            plen = 2;
            goto outn;
        default:
            if (*fmt == 0)
                goto next;
            flags |= 0x100;
            prec = 1;
            p = end;
            *p-- = *fmt;
            s = p + 1;
            len = end - p;
            goto outn;
        }
    outn:
        isstr = flags & 0x100;
        left = flags & 1;
        if (len < prec)
            prec -= len;
        else
            prec = 0;
        p = s + len;
        width = width - len - plen - prec;
        if (isstr) {
            padc = ' ';
            if (flags & 4) {
                if (width >= 1)
                    padc = '0';
            }
        } else {
            padc = ' ';
            if ((flags & 0x24) == 4) {
                if (width >= 1)
                    padc = '0';
            }
        }
        if (left) {
            for (n = 0; n < plen; n++)
                count += fn(arg, &size, pre[n]);
            for (n = 0; n < prec; n++)
                count += fn(arg, &size, '0');
            while (s < p)
                count += fn(arg, &size, *s++);
            for (n = 0; n < width; n++)
                count += fn(arg, &size, ' ');
        } else if (flags & 4) {
            if (padc == '0') {
                for (n = 0; n < plen; n++)
                    count += fn(arg, &size, pre[n]);
                for (n = 0; n < width; n++)
                    count += fn(arg, &size, padc);
            } else {
                for (n = 0; n < width; n++)
                    count += fn(arg, &size, padc);
                for (n = 0; n < plen; n++)
                    count += fn(arg, &size, pre[n]);
            }
            for (n = 0; n < prec; n++)
                count += fn(arg, &size, '0');
            while (s < p)
                count += fn(arg, &size, *s++);
        } else {
            for (n = 0; n < width; n++)
                count += fn(arg, &size, padc);
            for (n = 0; n < plen; n++)
                count += fn(arg, &size, pre[n]);
            for (n = 0; n < prec; n++)
                count += fn(arg, &size, '0');
            while (s < p)
                count += fn(arg, &size, *s++);
        }
        goto next;
    plain:
        if (*fmt == 0)
            goto next;
        c = *fmt;
        count += fn(arg, &size, c);
    next:
        if (*fmt)
            fmt++;
    }
    fn(arg, &size, 0);
    return count;
}

/* sprintf output: store c while room is left (the last byte becomes the NUL). */
int func_00307ee8(char **buf, int *n, int c)
{
    if (*n == 0)
        return 1;
    if (c < 256) {
        if (*n == 1)
            c = 0;
        *(*buf)++ = c;
        (*n)--;
        return 1;
    }
    **buf = 0;
    return 0;
}

int func_00307f40(int a, int b, int c) { if (c) func_00306e80(c); return 1; }

int func_00307f68(int a, int b, int c) { if (c) func_00306f30(c); return 1; }

extern int func_003071d0_v(void *, void *, int, const char *, va_list) asm("func_003071d0");
int func_00307f90(void *a, void *b, int *n, const char *fmt, ...)
{
    va_list ap; int r;
    va_start(ap, fmt);
    r = func_003071d0_v(a, b, *n, fmt, ap);
    *n -= r;
    return r;
}

extern int func_003071d0_i(void *, void *, int, int, int) asm("func_003071d0");
int func_00307fe0(int a, int b, int c, int d)
{
    int x = a;
    return func_003071d0_i(func_00307ee8, &x, b, c, d);
}

int func_00308018(char *buf, int n, const char *fmt, ...)
{
    va_list ap; int r;
    va_start(ap, fmt);
    r = func_003071d0_v(func_00307ee8, &buf, n, fmt, ap);
    return r;
}

typedef struct { int x; int pad[3]; } Arg;
extern int func_003071d0_a(void *, void *, unsigned int, int, int) asm("func_003071d0");
void func_00308060(int a, int b)
{
    Arg s;
    int st;
    s.x = 0;
    st = DIntr();
    func_003071d0_a(func_00307f40, &s, 0xffffffff, a, b);
    if (st)
        EIntr();
}

extern int func_003071d0_u(void *, void *, unsigned int, const char *, va_list) asm("func_003071d0");
void func_003080d0(const char *fmt, ...)
{
    va_list ap; int buf; int s;
    buf = 0;
    s = DIntr();
    va_start(ap, fmt);
    func_003071d0_u(func_00307f40, &buf, 0xffffffff, fmt, ap);
    if (s) EIntr();
}

void func_00308150(const char *fmt, ...)
{
    va_list ap; int buf; int s;
    buf = 0;
    s = DIntr();
    va_start(ap, fmt);
    func_003071d0_u(func_00307f68, &buf, 0xffffffff, fmt, ap);
    if (s) EIntr();
}
