#include "../common/types.h"
/* newlib routines the game links: _b2d (newlib/libc/stdlib/mprec.c) and __ieee754_sqrt
 * (newlib/libm/math/e_sqrt.c, from fdlibm). Their original notices follow, unchanged. */

/* Notice from mprec.c: */
/****************************************************************
 *
 * The author of this software is David M. Gay.
 *
 * Copyright (c) 1991 by AT&T.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose without fee is hereby granted, provided that this entire notice
 * is included in all copies of any software which is or includes a copy
 * or modification of this software and in all copies of the supporting
 * documentation for such software.
 *
 * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTY.  IN PARTICULAR, NEITHER THE AUTHOR NOR AT&T MAKES ANY
 * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
 * OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 ***************************************************************/

/* Notice from e_sqrt.c: */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice 
 * is preserved.
 * ====================================================
 */

struct _Bigint {
    struct _Bigint* _next;
    s32 _k, _maxwds, _sign, _wds;
    u32 _x[1];
};
typedef struct _Bigint _Bigint;
union double_union { double d; u32 i[2]; };
#define word0(x) ((x).i[1])
#define word1(x) ((x).i[0])
#define Ebits 11
#define Exp_1 0x3ff00000
s32 func_00303e80(u32 x); // hi0bits
#define hi0bits func_00303e80

double func_00304710(_Bigint* a, s32* e)
{
    u32 *xa, *xa0, w, y, z;
    s32 k;
    union double_union d;
#define d0 word0(d)
#define d1 word1(d)
    xa0 = a->_x;
    xa = xa0 + a->_wds;
    y = *--xa;
    k = hi0bits(y);
    *e = 32 - k;
    if (k < Ebits) {
        d0 = Exp_1 | y >> (Ebits - k);
        w = xa > xa0 ? *--xa : 0;
        d1 = y << ((32 - Ebits) + k) | w >> (Ebits - k);
        goto ret_d;
    }
    z = xa > xa0 ? *--xa : 0;
    if (k -= Ebits) {
        d0 = Exp_1 | y << k | z >> (32 - k);
        y = xa > xa0 ? *--xa : 0;
        d1 = z << k | y >> (32 - k);
    } else {
        d0 = Exp_1 | y;
        d1 = z;
    }
ret_d:
#undef d0
#undef d1
    return d.d;
}

asm("dpcmp = func_003142e0");
asm("dpsub = func_00313ed8");
asm("dpadd = func_00313e80");
asm("dpmul = func_00313f40");
asm("dpdiv = func_00314190");

typedef union {
    double value;
    struct { u32 lsw; u32 msw; } parts;
} ieee_double_shape_type;
#define EXTRACT_WORDS(ix0,ix1,d) do { ieee_double_shape_type ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)
#define INSERT_WORDS(d,ix0,ix1) do { ieee_double_shape_type iw_u; iw_u.parts.msw = (ix0); iw_u.parts.lsw = (ix1); (d) = iw_u.value; } while (0)

static const double one = 1.0, tiny = 1.0e-300;

double func_002f8b48(double x)
{
    double z;
    s32 sign = (int)0x80000000;
    u32 r, t1, s1, ix1, q1;
    s32 ix0, s0, q, m, t, i;

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
            if (((t1 & sign) == (u32)sign) && (s1 & sign) == 0) s0 += 1;
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
            if (q1 == (u32)0xffffffff) { q1 = 0; q += 1; }
            else if (z > one) {
                if (q1 == (u32)0xfffffffe) q += 1;
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
