/* s_isnan.c: newlib libc (libm/common/s_isnan.c as built into libc.a), the copy the game links from the
 * toolchain's libc.a. Linked unit 0x304db0-0x304de8. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. Copyright (C) 1993 by Sun Microsystems, Inc.
 * Permission to use, copy, modify, and distribute this software is freely granted, provided that this notice is preserved. */
#include "../libm/fdlibm.h"

int isnan(double x)
{
    __int32_t hx, lx;
    EXTRACT_WORDS(hx, lx, x);
    hx &= 0x7fffffff;
    hx |= (__uint32_t)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return (int)(((__uint32_t)(hx)) >> 31);
}
