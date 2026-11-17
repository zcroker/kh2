/* vsprintf.c: newlib libc (libc/stdio/vsprintf.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x301550-0x3015f8. Third-party code notice: rebuilt to match; not covered by this project's MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "local.h"
#include <stdarg.h>
#define INT_MAX 0x7fffffff
asm("vfprintf = func_002ffd00");
int vfprintf(FILE *, const char *, va_list);
int _vfprintf_r(struct _reent *, FILE *, const char *, va_list);

int vsprintf(char *str, const char *fmt, va_list ap)
{
    int ret;
    FILE f;

    f._flags = __SWR | __SSTR;
    f._bf._base = f._p = (unsigned char *)str;
    f._bf._size = f._w = INT_MAX;
    f._data = _REENT;
    ret = vfprintf(&f, fmt, ap);
    *f._p = 0;
    return ret;
}

int _vsprintf_r(struct _reent *ptr, char *str, const char *fmt, va_list ap)
{
    int ret;
    FILE f;

    f._flags = __SWR | __SSTR;
    f._bf._base = f._p = (unsigned char *)str;
    f._bf._size = f._w = INT_MAX;
    f._data = ptr;
    ret = _vfprintf_r(ptr, &f, fmt, ap);
    *f._p = 0;
    return ret;
}
