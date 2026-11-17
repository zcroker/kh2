/* sprintf.c: newlib libc (libc/stdio/sprintf.c: _sprintf_r, sprintf), the copy the game links from the toolchain's
 * libc.a. Linked unit 0x2fee08-0x2feee8. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "local.h"
#include <stdarg.h>
#define INT_MAX 0x7fffffff
asm("vfprintf = func_002ffd00");
int vfprintf(FILE *, const char *, va_list);

int _sprintf_r(struct _reent *ptr, char *str, const char *fmt, ...)
{
    int ret;
    va_list ap;
    FILE f;

    f._flags = __SWR | __SSTR;
    f._bf._base = f._p = (unsigned char *)str;
    f._bf._size = f._w = INT_MAX;
    f._data = ptr;
    va_start(ap, fmt);
    ret = vfprintf(&f, fmt, ap);
    va_end(ap);
    *f._p = 0;
    return (ret);
}

int sprintf(char *str, const char *fmt, ...)
{
    int ret;
    va_list ap;
    FILE f;

    f._flags = __SWR | __SSTR;
    f._bf._base = f._p = (unsigned char *)str;
    f._bf._size = f._w = INT_MAX;
    f._data = _REENT;
    va_start(ap, fmt);
    ret = vfprintf(&f, fmt, ap);
    va_end(ap);
    *f._p = 0;
    return (ret);
}
