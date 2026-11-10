/* Sony PS2 Runtime Library (libkernl printf core). Third-party code: Sony Computer Entertainment's
 * library, rebuilt here only to match the game's executable; it is not covered by this project's license. */

/* vprintf-style formatter: each output character goes through fn(arg, &size, c). Supports the
 * flags - + 0 space #, width, .prec / .*, the l and h modifiers and %o %x %X %d %i %u %e %f %s %c %p.
 * %e/%f converts through float and hands the value to func_00306ff8. 64-bit division calls the
 * libgcc copies directly. */
typedef char *va_list;
typedef int (*OutFn)(void *, int *, int);
extern long __moddi3(long, long);
extern long func_00311dd0(long, long);
extern unsigned long __umoddi3(unsigned long, unsigned long);
extern unsigned long func_00312db8(unsigned long, unsigned long);
extern float __truncdfsf2(double);
extern double func_00313b80(float);
extern int func_00306ff8(OutFn, void *, int *, double);

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
