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
asm("dpsub = __subdf3");
asm("dpadd = func_00313e80");
asm("dpmul = func_00313f40");
asm("dpdiv = func_00314190");

/* 0x002f8b48 __ieee754_sqrt: definition moved into src/newlib/libm/e_sqrt.c */
