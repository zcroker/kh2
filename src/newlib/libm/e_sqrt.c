/* e_sqrt.c: newlib libm (libm/math/e_sqrt.c, fdlibm), the copy the game links from the toolchain's libm.a.
 * Linked unit 0x2f8b48-0x2f8e58, .rodata at 0x376f98. Built with ee-gcc 3.2 -O2 -G0 -fno-builtin (see fdlibm.h).
 * Third-party code notice: rebuilt to match; it is not covered by this project's MIT License.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely granted,
 * provided that this notice is preserved.
 */
#include "fdlibm.h"

/* Double arithmetic is soft-float: gcc calls dpadd/dpsub/dpmul/dpdiv/dpcmp, the game's libgcc copies. */
asm("dpcmp = func_003142e0");
asm("dpsub = __subdf3");
asm("dpadd = func_00313e80");
asm("dpmul = func_00313f40");
asm("dpdiv = func_00314190");

static const double one = 1.0, tiny = 1.0e-300;
double __ieee754_sqrt(double x)
{
    double z;
    __int32_t sign = (int)0x80000000;
    __uint32_t r, t1, s1, ix1, q1;
    __int32_t ix0, s0, q, m, t, i;

    EXTRACT_WORDS(ix0, ix1, x);

    if ((ix0 & 0x7ff00000) == 0x7ff00000) {
        return x * x + x;
    }
    if (ix0 <= 0) {
        if (((ix0 & (~sign)) | ix1) == 0) return x;
        else if (ix0 < 0)
            return (x - x) / (x - x);
    }
    m = (ix0 >> 20);
    if (m == 0) {
        while (ix0 == 0) {
            m -= 21;
            ix0 |= (ix1 >> 11); ix1 <<= 21;
        }
        for (i = 0; (ix0 & 0x00100000) == 0; i++) ix0 <<= 1;
        m -= i - 1;
        ix0 |= (ix1 >> (32 - i));
        ix1 <<= i;
    }
    m -= 1023;
    ix0 = (ix0 & 0x000fffff) | 0x00100000;
    if (m & 1) {
        ix0 += ix0 + ((ix1 & sign) >> 31);
        ix1 += ix1;
    }
    m >>= 1;

    ix0 += ix0 + ((ix1 & sign) >> 31);
    ix1 += ix1;
    q = q1 = s0 = s1 = 0;
    r = 0x00200000;

    while (r != 0) {
        t = s0 + r;
        if (t <= ix0) {
            s0 = t + r;
            ix0 -= t;
            q += r;
        }
        ix0 += ix0 + ((ix1 & sign) >> 31);
        ix1 += ix1;
        r >>= 1;
    }

    r = sign;
    while (r != 0) {
        t1 = s1 + r;
        t = s0;
        if ((t < ix0) || ((t == ix0) && (t1 <= ix1))) {
            s1 = t1 + r;
            if (((t1 & sign) == (__uint32_t)sign) && (s1 & sign) == 0) s0 += 1;
            ix0 -= t;
            if (ix1 < t1) ix0 -= 1;
            ix1 -= t1;
            q1 += r;
        }
        ix0 += ix0 + ((ix1 & sign) >> 31);
        ix1 += ix1;
        r >>= 1;
    }

    if ((ix0 | ix1) != 0) {
        z = one - tiny;
        if (z >= one) {
            z = one + tiny;
            if (q1 == (__uint32_t)0xffffffff) { q1 = 0; q += 1; }
            else if (z > one) {
                if (q1 == (__uint32_t)0xfffffffe) q += 1;
                q1 += 2;
            } else
                q1 += (q1 & 1);
        }
    }
    ix0 = (q >> 1) + 0x3fe00000;
    ix1 = q1 >> 1;
    if ((q & 1) == 1) ix1 |= sign;
    ix0 += (m << 20);
    INSERT_WORDS(z, ix0, ix1);
    return z;
}

