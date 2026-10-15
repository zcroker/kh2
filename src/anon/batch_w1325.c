/* Original license notice of newlib/libc/stdlib/dtoa.c, retained as it requires: */
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

/* Reconstruction of newlib's _dtoa_r (newlib/libc/stdlib/dtoa.c, newlib 1.10-era, David M. Gay's
 * dtoa adapted for newlib), which the game links. newlib is (c) The Regents of the University of
 * California, David M. Gay / AT&T and other contributors, BSD-style licensed; see
 * https://sourceware.org/newlib/ for its license terms. */
#include "../common/types.h"

// 00301938: newlib's _dtoa_r, built as C by the game's gcc 3.2 (IEEE_8087 little-endian,
// Pack_32, not Sudden_Underflow, __Long = int). Soft-float double arithmetic becomes libcalls
// to the game's own fp-bit routines, aliased below.

struct _Bigint {
    struct _Bigint* _next;
    s32 _k, _maxwds, _sign, _wds;
    u32 _x[1];
};
typedef struct _Bigint _Bigint;

struct _reent_dtoa {           // newlib struct _reent, only the fields dtoa touches
    u8 pad[0x40];
    _Bigint* _result;          // 0x40
    s32 _result_k;             // 0x44
};

union double_union { double d; u32 i[2]; };
#define word0(x) ((x).i[1])
#define word1(x) ((x).i[0])

#define Exp_shift1 20
#define Exp_msk1   0x100000
#define Exp_mask   0x7ff00000
#define P          53
#define Bias       1023
#define Exp_11     0x3ff00000
#define Frac_mask  0xfffff
#define Frac_mask1 0xfffff
#define Ten_pmax   22
#define Bletch     0x10
#define Bndry_mask 0xfffff
#define Sign_bit   0x80000000
#define Log2P      1
#define Quick_max  14
#define Int_max    14
#define n_bigtens  5

_Bigint* func_00303b70(struct _reent_dtoa* p, s32 k) asm("_Z16ctarget_00303b70jjjj"); // Balloc
void     func_00303c18(struct _reent_dtoa* p, _Bigint* v);                 // Bfree
_Bigint* func_00303c48(struct _reent_dtoa* p, _Bigint* b, s32 m, s32 a);  // multadd
s32      func_00303e80(u32 x);                                             // hi0bits
_Bigint* func_00303fc0(struct _reent_dtoa* p, s32 i);                      // i2b
_Bigint* func_00303ff8(struct _reent_dtoa* p, _Bigint* a, _Bigint* b);    // mult
_Bigint* func_00304200(struct _reent_dtoa* p, _Bigint* b, s32 k);         // pow5mult
_Bigint* func_00304308(struct _reent_dtoa* p, _Bigint* b, s32 k);         // lshift
s32      func_00304468(_Bigint* a, _Bigint* b);                            // cmp
_Bigint* func_003044d0(struct _reent_dtoa* p, _Bigint* a, _Bigint* b);    // diff
_Bigint* func_003048b8(struct _reent_dtoa* p, double d, s32* e, s32* bits); // d2b
s32      func_00301708(_Bigint* b, _Bigint* S);                            // quorem
void*    func_002fdd68(void* dst, const void* src, u32 n);                 // memcpy

#define Balloc   func_00303b70
#define Bfree    func_00303c18
#define multadd  func_00303c48
#define hi0bits  func_00303e80
#define i2b      func_00303fc0
#define mult     func_00303ff8
#define pow5mult func_00304200
#define lshift   func_00304308
#define cmp      func_00304468
#define diff     func_003044d0
#define d2b      func_003048b8
#define quorem   func_00301708
#define Bcopy(x,y) func_002fdd68((char *)&x->_sign, (char *)&y->_sign, y->_wds*sizeof(s32) + 2*sizeof(int))

asm("dpcmp = func_003142e0");
asm("dpsub = func_00313ed8");
asm("dpadd = func_00313e80");
asm("dpmul = func_00313f40");
asm("dpdiv = func_00314190");
asm("litodp = func_00314330");
asm("dptoli = func_003143e0");

extern const double D_00377d10[];   // __mprec_tens
extern const double D_00377dd8[];   // __mprec_bigtens
extern const char D_00377c68[];     // "Infinity"
extern const char D_00377c78[];     // "NaN"
extern const char D_00377c80[];     // "0"
#define tens D_00377d10
#define bigtens D_00377dd8

char* func_00301938(struct _reent_dtoa* ptr, double _d, s32 mode, s32 ndigits,
                    s32* decpt, s32* sign, char** rve)
{
    s32 bbits, b2, b5, be, dig, i, ieps, ilim, ilim0, ilim1, j, j1, k, k0,
        k_check, leftright, m2, m5, s2, s5, spec_case, try_quick;
    union double_union d, d2, eps;
    s32 L;
    s32 denorm;
    u32 x;
    _Bigint *b, *b1, *delta, *mlo = 0, *mhi, *S;
    double ds;
    char *s, *s0;

    d.d = _d;

    if (ptr->_result) {
        ptr->_result->_k = ptr->_result_k;
        ptr->_result->_maxwds = 1 << ptr->_result_k;
        Bfree(ptr, ptr->_result);
        ptr->_result = 0;
    }

    if (word0(d) & Sign_bit) {
        *sign = 1;
        word0(d) &= ~Sign_bit;
    } else
        *sign = 0;

    if ((word0(d) & Exp_mask) == Exp_mask) {
        *decpt = 9999;
        s = !word1(d) && !(word0(d) & 0xfffff) ? (char*)D_00377c68 : (char*)D_00377c78;
        if (rve)
            *rve = s[3] ? s + 8 : s + 3;
        return s;
    }
    if (!d.d) {
        *decpt = 1;
        s = (char*)D_00377c80;
        if (rve)
            *rve = s + 1;
        return s;
    }

    b = d2b(ptr, d.d, &be, &bbits);
    if ((i = (s32)(word0(d) >> Exp_shift1 & (Exp_mask >> Exp_shift1))) != 0) {
        d2.d = d.d;
        word0(d2) &= Frac_mask1;
        word0(d2) |= Exp_11;
        i -= Bias;
        denorm = 0;
    } else {
        i = bbits + be + (Bias + (P - 1) - 1);
        x = (i > 32) ? (word0(d) << (64 - i)) | (word1(d) >> (i - 32))
                     : (word1(d) << (32 - i));
        d2.d = x;
        word0(d2) -= 31 * Exp_msk1;
        i -= (Bias + (P - 1) - 1) + 1;
        denorm = 1;
    }
    ds = (d2.d - 1.5) * 0.289529654602168 + 0.1760912590558 + i * 0.301029995663981;
    k = (s32)ds;
    if (ds < 0. && ds != k)
        k--;
    k_check = 1;
    if (k >= 0 && k <= Ten_pmax) {
        if (d.d < tens[k])
            k--;
        k_check = 0;
    }
    j = bbits - i - 1;
    if (j >= 0) {
        b2 = 0;
        s2 = j;
    } else {
        b2 = -j;
        s2 = 0;
    }
    if (k >= 0) {
        b5 = 0;
        s5 = k;
        s2 += k;
    } else {
        b2 -= k;
        b5 = -k;
        s5 = 0;
    }
    if (mode < 0 || mode > 9)
        mode = 0;
    try_quick = 1;
    if (mode > 5) {
        mode -= 4;
        try_quick = 0;
    }
    leftright = 1;
    ilim = ilim1 = -1;
    switch (mode) {
    case 0:
    case 1:
        i = 18;
        ndigits = 0;
        break;
    case 2:
        leftright = 0;
        /* no break */
    case 4:
        if (ndigits <= 0)
            ndigits = 1;
        ilim = ilim1 = i = ndigits;
        break;
    case 3:
        leftright = 0;
        /* no break */
    case 5:
        i = ndigits + k + 1;
        ilim = i;
        ilim1 = i - 1;
        if (i <= 0)
            i = 1;
    }
    j = sizeof(u32);
    for (ptr->_result_k = 0; sizeof(_Bigint) - sizeof(u32) + j <= i; j <<= 1)
        ptr->_result_k++;
    ptr->_result = Balloc(ptr, ptr->_result_k);
    s = s0 = (char*)ptr->_result;

    if (ilim >= 0 && ilim <= Quick_max && try_quick) {
        i = 0;
        d2.d = d.d;
        k0 = k;
        ilim0 = ilim;
        ieps = 2;
        if (k > 0) {
            ds = tens[k & 0xf];
            j = k >> 4;
            if (j & Bletch) {
                j &= Bletch - 1;
                d.d /= bigtens[n_bigtens - 1];
                ieps++;
            }
            for (; j; j >>= 1, i++)
                if (j & 1) {
                    ieps++;
                    ds *= bigtens[i];
                }
            d.d /= ds;
        } else if ((j1 = -k) != 0) {
            d.d *= tens[j1 & 0xf];
            for (j = j1 >> 4; j; j >>= 1, i++)
                if (j & 1) {
                    ieps++;
                    d.d *= bigtens[i];
                }
        }
        if (k_check && d.d < 1. && ilim > 0) {
            if (ilim1 <= 0)
                goto fast_failed;
            ilim = ilim1;
            k--;
            d.d *= 10.;
            ieps++;
        }
        eps.d = ieps * d.d + 7.;
        word0(eps) -= (P - 1) * Exp_msk1;
        if (ilim == 0) {
            S = mhi = 0;
            d.d -= 5.;
            if (d.d > eps.d)
                goto one_digit;
            if (d.d < -eps.d)
                goto no_digits;
            goto fast_failed;
        }
        if (leftright) {
            eps.d = 0.5 / tens[ilim - 1] - eps.d;
            for (i = 0;;) {
                L = d.d;
                d.d -= L;
                *s++ = '0' + (int)L;
                if (d.d < eps.d)
                    goto ret1;
                if (1. - d.d < eps.d)
                    goto bump_up;
                if (++i >= ilim)
                    break;
                eps.d *= 10.;
                d.d *= 10.;
            }
        } else {
            eps.d *= tens[ilim - 1];
            for (i = 1;; i++, d.d *= 10.) {
                L = d.d;
                d.d -= L;
                *s++ = '0' + (int)L;
                if (i == ilim) {
                    if (d.d > 0.5 + eps.d)
                        goto bump_up;
                    else if (d.d < 0.5 - eps.d) {
                        while (*--s == '0')
                            ;
                        s++;
                        goto ret1;
                    }
                    break;
                }
            }
        }
    fast_failed:
        s = s0;
        d.d = d2.d;
        k = k0;
        ilim = ilim0;
    }

    if (be >= 0 && k <= Int_max) {
        ds = tens[k];
        if (ndigits < 0 && ilim <= 0) {
            S = mhi = 0;
            if (ilim < 0 || d.d <= 5 * ds)
                goto no_digits;
            goto one_digit;
        }
        for (i = 1;; i++) {
            L = d.d / ds;
            d.d -= L * ds;
            *s++ = '0' + (int)L;
            if (i == ilim) {
                d.d += d.d;
                if ((d.d > ds) || ((d.d == ds) && (L & 1))) {
                bump_up:
                    while (*--s == '9')
                        if (s == s0) {
                            k++;
                            *s = '0';
                            break;
                        }
                    ++*s++;
                }
                break;
            }
            if (!(d.d *= 10.))
                break;
        }
        goto ret1;
    }

    m2 = b2;
    m5 = b5;
    mhi = mlo = 0;
    if (leftright) {
        if (mode < 2) {
            i = denorm ? be + (Bias + (P - 1) - 1 + 1) : 1 + P - bbits;
        } else {
            j = ilim - 1;
            if (m5 >= j)
                m5 -= j;
            else {
                s5 += j -= m5;
                b5 += j;
                m5 = 0;
            }
            if ((i = ilim) < 0) {
                m2 -= i;
                i = 0;
            }
        }
        b2 += i;
        s2 += i;
        mhi = i2b(ptr, 1);
    }
    if (m2 > 0 && s2 > 0) {
        i = m2 < s2 ? m2 : s2;
        b2 -= i;
        m2 -= i;
        s2 -= i;
    }
    if (b5 > 0) {
        if (leftright) {
            if (m5 > 0) {
                mhi = pow5mult(ptr, mhi, m5);
                b1 = mult(ptr, mhi, b);
                Bfree(ptr, b);
                b = b1;
            }
            if ((j = b5 - m5) != 0)
                b = pow5mult(ptr, b, j);
        } else
            b = pow5mult(ptr, b, b5);
    }
    S = i2b(ptr, 1);
    if (s5 > 0)
        S = pow5mult(ptr, S, s5);

    spec_case = 0;
    if (mode < 2) {
        if (!word1(d) && !(word0(d) & Bndry_mask) && word0(d) & Exp_mask) {
            b2 += Log2P;
            s2 += Log2P;
            spec_case = 1;
        }
    }

    if ((i = ((s5 ? 32 - hi0bits(S->_x[S->_wds - 1]) : 1) + s2) & 0x1f) != 0)
        i = 32 - i;
    if (i > 4) {
        i -= 4;
        b2 += i;
        m2 += i;
        s2 += i;
    } else if (i < 4) {
        i += 28;
        b2 += i;
        m2 += i;
        s2 += i;
    }
    if (b2 > 0)
        b = lshift(ptr, b, b2);
    if (s2 > 0)
        S = lshift(ptr, S, s2);
    if (k_check) {
        if (cmp(b, S) < 0) {
            k--;
            b = multadd(ptr, b, 10, 0);
            if (leftright)
                mhi = multadd(ptr, mhi, 10, 0);
            ilim = ilim1;
        }
    }
    if (ilim <= 0 && mode > 2) {
        if (ilim < 0 || cmp(b, S = multadd(ptr, S, 5, 0)) <= 0) {
        no_digits:
            k = -1 - ndigits;
            goto ret;
        }
    one_digit:
        *s++ = '1';
        k++;
        goto ret;
    }
    if (leftright) {
        if (m2 > 0)
            mhi = lshift(ptr, mhi, m2);

        mlo = mhi;
        if (spec_case) {
            mhi = Balloc(ptr, mhi->_k);
            Bcopy(mhi, mlo);
            mhi = lshift(ptr, mhi, Log2P);
        }

        for (i = 1;; i++) {
            dig = quorem(b, S) + '0';
            j = cmp(b, mlo);
            delta = diff(ptr, S, mhi);
            j1 = delta->_sign ? 1 : cmp(b, delta);
            Bfree(ptr, delta);
            if (j1 == 0 && !mode && !(word1(d) & 1)) {
                if (dig == '9')
                    goto round_9_up;
                if (j > 0)
                    dig++;
                *s++ = dig;
                goto ret;
            }
            if ((j < 0) || ((j == 0) && !mode && !(word1(d) & 1))) {
                if (j1 > 0) {
                    b = lshift(ptr, b, 1);
                    j1 = cmp(b, S);
                    if (((j1 > 0) || ((j1 == 0) && (dig & 1))) && dig++ == '9')
                        goto round_9_up;
                }
                *s++ = dig;
                goto ret;
            }
            if (j1 > 0) {
                if (dig == '9') {
                round_9_up:
                    *s++ = '9';
                    goto roundoff;
                }
                *s++ = dig + 1;
                goto ret;
            }
            *s++ = dig;
            if (i == ilim)
                break;
            b = multadd(ptr, b, 10, 0);
            if (mlo == mhi)
                mlo = mhi = multadd(ptr, mhi, 10, 0);
            else {
                mlo = multadd(ptr, mlo, 10, 0);
                mhi = multadd(ptr, mhi, 10, 0);
            }
        }
    } else
        for (i = 1;; i++) {
            *s++ = dig = quorem(b, S) + '0';
            if (i >= ilim)
                break;
            b = multadd(ptr, b, 10, 0);
        }

    b = lshift(ptr, b, 1);
    j = cmp(b, S);
    if ((j > 0) || ((j == 0) && (dig & 1))) {
    roundoff:
        while (*--s == '9')
            if (s == s0) {
                k++;
                *s++ = '1';
                goto ret;
            }
        ++*s++;
    } else {
        while (*--s == '0')
            ;
        s++;
    }
ret:
    Bfree(ptr, S);
    if (mhi) {
        if (mlo && mlo != mhi)
            Bfree(ptr, mlo);
        Bfree(ptr, mhi);
    }
ret1:
    Bfree(ptr, b);
    *s = 0;
    *decpt = k + 1;
    if (rve)
        *rve = s;
    return s0;
}
