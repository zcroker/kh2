/* printf.c: newlib libc (libc/stdio/printf.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2fdf88-0x2fe018. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "newlib.h"
#include <stdarg.h>
asm("vfprintf = func_002ffd00");
int _vfprintf_r(struct _reent *, FILE *, const char *, va_list);
int vfprintf(FILE *, const char *, va_list);

int _printf_r(struct _reent *ptr, const char *fmt, ...)
{
    int ret;
    va_list ap;

    va_start(ap, fmt);
    ret = _vfprintf_r(ptr, _stdout_r(ptr), fmt, ap);
    va_end(ap);
    return ret;
}

int printf(const char *fmt, ...)
{
    int ret;
    va_list ap;

    va_start(ap, fmt);
    _stdout_r(_impure_ptr)->_data = _impure_ptr;
    ret = vfprintf(_stdout_r(_impure_ptr), fmt, ap);
    va_end(ap);
    return ret;
}
