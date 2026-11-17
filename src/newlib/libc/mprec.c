/* Original license notice of newlib/libc/stdlib/mprec.c, retained as it requires: */
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

/* mprec.c: newlib libc (libc/stdlib/mprec.c, the Bigint helpers of David M. Gay's dtoa/strtod), the copy the game
 * links from the toolchain's libc.a. Linked unit 0x303b70-0x304b60 with its .rodata at 0x377d00 (p05, then
 * __mprec_tens, __mprec_bigtens, __mprec_tinytens). IEEE_8087 little-endian, Pack_32, not Sudden_Underflow.
 * Soft-float double arithmetic becomes libcalls to the game's own fp-bit routines (aliased below).
 * Third-party code notice: rebuilt to match; not covered by this project's MIT License. */
#include "newlib.h"

asm("dpmul = func_00313f40");
asm("dpdiv = func_00314190");

typedef int __Long;
typedef unsigned int __ULong;

struct _Bigint {
    struct _Bigint *_next;
    int _k, _maxwds, _sign, _wds;
    __ULong _x[1];
};
typedef struct _Bigint _Bigint;

union double_union { double d; __ULong i[2]; };
#define word0(x) ((x).i[1])
#define word1(x) ((x).i[0])

#define Storeinc(a, b, c) (((unsigned short *)a)[1] = (unsigned short)b, ((unsigned short *)a)[0] = (unsigned short)c, a++)
#define Sign_Extend(a, b) /* no-op */

#define Exp_shift  20
#define Exp_shift1 20
#define Exp_msk1   0x100000
#define Exp_mask   0x7ff00000
#define P          53
#define Bias       1023
#define Exp_1      0x3ff00000
#define Ebits      11
#define Frac_mask  0xfffff

void *memcpy(void *, const void *, size_t);
void *_calloc_r(struct _reent *, size_t, size_t);

#define Balloc _Balloc
#define Bfree _Bfree
#define multadd _multadd
#define s2b _s2b
#define lo0bits _lo0bits
#define hi0bits _hi0bits
#define i2b _i2b
#define mult _multiply
#define pow5mult _pow5mult
#define lshift _lshift
#define cmp __mcmp
#define diff __mdiff
#define ulp _ulp
#define b2d _b2d
#define d2b _d2b
#define ratio _ratio
#define tens __mprec_tens
#define bigtens __mprec_bigtens
#define tinytens __mprec_tinytens
#define Bcopy(x, y) memcpy((char *)&x->_sign, (char *)&y->_sign, y->_wds * sizeof(__Long) + 2 * sizeof(int))

_Bigint *Balloc(struct _reent *ptr, int k)
{
  int x;
  _Bigint *rv ;

  if (ptr->_freelist == NULL)
    {
      /* Allocate a list of pointers to the mprec objects */
      ptr->_freelist = (struct _Bigint **) _calloc_r (ptr,
						      sizeof (struct _Bigint *),
						      16);
      if (ptr->_freelist == NULL)
	{
	  return NULL;
	}
    }

  if ((rv = ptr->_freelist[k]) != 0)
    {
      ptr->_freelist[k] = rv->_next;
    }
  else
    {
      x = 1 << k;
      /* Allocate an mprec Bigint and stick in in the freelist */
      rv = (_Bigint *) _calloc_r (ptr,
				  1,
				  sizeof (_Bigint) +
				  (x-1) * sizeof(rv->_x));
      if (rv == NULL) return NULL;
      rv->_k = k;
      rv->_maxwds = x;
    }
  rv->_sign = rv->_wds = 0;
  return rv;
}

void Bfree(struct _reent *ptr, _Bigint *v)
{
  if (v)
    {
      v->_next = ptr->_freelist[v->_k];
      ptr->_freelist[v->_k] = v;
    }
}

_Bigint *multadd(struct _reent *ptr, _Bigint *b, int m, int a)
{
  int i, wds;
  __ULong *x, y;
  __ULong xi, z;
  _Bigint *b1;

  wds = b->_wds;
  x = b->_x;
  i = 0;
  do
    {
      xi = *x;
      y = (xi & 0xffff) * m + a;
      z = (xi >> 16) * m + (y >> 16);
      a = (int) (z >> 16);
      *x++ = (z << 16) + (y & 0xffff);
    }
  while (++i < wds);
  if (a)
    {
      if (wds >= b->_maxwds)
	{
	  b1 = Balloc (ptr, b->_k + 1);
	  Bcopy (b1, b);
	  Bfree (ptr, b);
	  b = b1;
	}
      b->_x[wds++] = a;
      b->_wds = wds;
    }
  return b;
}

_Bigint *s2b(struct _reent *ptr, const char *s, int nd0, int nd, __ULong y9)
{
  _Bigint *b;
  int i, k;
  __Long x, y;

  x = (nd + 8) / 9;
  for (k = 0, y = 1; x > y; y <<= 1, k++);
  b = Balloc (ptr, k);
  b->_x[0] = y9;
  b->_wds = 1;

  i = 9;
  if (9 < nd0)
    {
      s += 9;
      do
	b = multadd (ptr, b, 10, *s++ - '0');
      while (++i < nd0);
      s++;
    }
  else
    s += 10;
  for (; i < nd; i++)
    b = multadd (ptr, b, 10, *s++ - '0');
  return b;
}

int hi0bits(register __ULong x)
{
  register int k = 0;

  if (!(x & 0xffff0000))
    {
      k = 16;
      x <<= 16;
    }
  if (!(x & 0xff000000))
    {
      k += 8;
      x <<= 8;
    }
  if (!(x & 0xf0000000))
    {
      k += 4;
      x <<= 4;
    }
  if (!(x & 0xc0000000))
    {
      k += 2;
      x <<= 2;
    }
  if (!(x & 0x80000000))
    {
      k++;
      if (!(x & 0x40000000))
	return 32;
    }
  return k;
}

int lo0bits(__ULong *y)
{
  register int k;
  register __ULong x = *y;

  if (x & 7)
    {
      if (x & 1)
	return 0;
      if (x & 2)
	{
	  *y = x >> 1;
	  return 1;
	}
      *y = x >> 2;
      return 2;
    }
  k = 0;
  if (!(x & 0xffff))
    {
      k = 16;
      x >>= 16;
    }
  if (!(x & 0xff))
    {
      k += 8;
      x >>= 8;
    }
  if (!(x & 0xf))
    {
      k += 4;
      x >>= 4;
    }
  if (!(x & 0x3))
    {
      k += 2;
      x >>= 2;
    }
  if (!(x & 1))
    {
      k++;
      x >>= 1;
      if (!x & 1)
	return 32;
    }
  *y = x;
  return k;
}

_Bigint *i2b(struct _reent *ptr, int i)
{
  _Bigint *b;

  b = Balloc (ptr, 1);
  b->_x[0] = i;
  b->_wds = 1;
  return b;
}

_Bigint *mult(struct _reent *ptr, _Bigint *a, _Bigint *b)
{
  _Bigint *c;
  int k, wa, wb, wc;
  __ULong carry, y, z;
  __ULong *x, *xa, *xae, *xb, *xbe, *xc, *xc0;
  __ULong z2;

  if (a->_wds < b->_wds)
    {
      c = a;
      a = b;
      b = c;
    }
  k = a->_k;
  wa = a->_wds;
  wb = b->_wds;
  wc = wa + wb;
  if (wc > a->_maxwds)
    k++;
  c = Balloc (ptr, k);
  for (x = c->_x, xa = x + wc; x < xa; x++)
    *x = 0;
  xa = a->_x;
  xae = xa + wa;
  xb = b->_x;
  xbe = xb + wb;
  xc0 = c->_x;
  for (; xb < xbe; xb++, xc0++)
    {
      if ((y = *xb & 0xffff) != 0)
	{
	  x = xa;
	  xc = xc0;
	  carry = 0;
	  do
	    {
	      z = (*x & 0xffff) * y + (*xc & 0xffff) + carry;
	      carry = z >> 16;
	      z2 = (*x++ >> 16) * y + (*xc >> 16) + carry;
	      carry = z2 >> 16;
	      Storeinc (xc, z2, z);
	    }
	  while (x < xae);
	  *xc = carry;
	}
      if ((y = *xb >> 16) != 0)
	{
	  x = xa;
	  xc = xc0;
	  carry = 0;
	  z2 = *xc;
	  do
	    {
	      z = (*x & 0xffff) * y + (*xc >> 16) + carry;
	      carry = z >> 16;
	      Storeinc (xc, z, z2);
	      z2 = (*x++ >> 16) * y + (*xc & 0xffff) + carry;
	      carry = z2 >> 16;
	    }
	  while (x < xae);
	  *xc = z2;
	}
    }
  for (xc0 = c->_x, xc = xc0 + wc; wc > 0 && !*--xc; --wc);
  c->_wds = wc;
  return c;
}

_Bigint *pow5mult(struct _reent *ptr, _Bigint *b, int k)
{
  _Bigint *b1, *p5, *p51;
  int i;
  static const int p05[3] = {5, 25, 125};

  if ((i = k & 3) != 0)
    b = multadd (ptr, b, p05[i - 1], 0);

  if (!(k >>= 2))
    return b;
  if (!(p5 = ptr->_p5s))
    {
      /* first time */
      p5 = ptr->_p5s = i2b (ptr, 625);
      p5->_next = 0;
    }
  for (;;)
    {
      if (k & 1)
	{
	  b1 = mult (ptr, b, p5);
	  Bfree (ptr, b);
	  b = b1;
	}
      if (!(k >>= 1))
	break;
      if (!(p51 = p5->_next))
	{
	  p51 = p5->_next = mult (ptr, p5, p5);
	  p51->_next = 0;
	}
      p5 = p51;
    }
  return b;
}

_Bigint *lshift(struct _reent *ptr, _Bigint *b, int k)
{
  int i, k1, n, n1;
  _Bigint *b1;
  __ULong *x, *x1, *xe, z;

  n = k >> 5;
  k1 = b->_k;
  n1 = n + b->_wds + 1;
  for (i = b->_maxwds; n1 > i; i <<= 1)
    k1++;
  b1 = Balloc (ptr, k1);
  x1 = b1->_x;
  for (i = 0; i < n; i++)
    *x1++ = 0;
  x = b->_x;
  xe = x + b->_wds;
  if (k &= 0x1f)
    {
      k1 = 32 - k;
      z = 0;
      do
	{
	  *x1++ = *x << k | z;
	  z = *x++ >> k1;
	}
      while (x < xe);
      if ((*x1 = z) != 0)
	++n1;
    }
  else
    do
      *x1++ = *x++;
    while (x < xe);
  b1->_wds = n1 - 1;
  Bfree (ptr, b);
  return b1;
}

int cmp(_Bigint *a, _Bigint *b)
{
  __ULong *xa, *xa0, *xb, *xb0;
  int i, j;

  i = a->_wds;
  j = b->_wds;
  if (i -= j)
    return i;
  xa0 = a->_x;
  xa = xa0 + j;
  xb0 = b->_x;
  xb = xb0 + j;
  for (;;)
    {
      if (*--xa != *--xb)
	return *xa < *xb ? -1 : 1;
      if (xa <= xa0)
	break;
    }
  return 0;
}

_Bigint *diff(struct _reent *ptr, _Bigint *a, _Bigint *b)
{
  _Bigint *c;
  int i, wa, wb;
  __Long borrow, y;		/* We need signed shifts here. */
  __ULong *xa, *xae, *xb, *xbe, *xc;
  __Long z;

  i = cmp (a, b);
  if (!i)
    {
      c = Balloc (ptr, 0);
      c->_wds = 1;
      c->_x[0] = 0;
      return c;
    }
  if (i < 0)
    {
      c = a;
      a = b;
      b = c;
      i = 1;
    }
  else
    i = 0;
  c = Balloc (ptr, a->_k);
  c->_sign = i;
  wa = a->_wds;
  xa = a->_x;
  xae = xa + wa;
  wb = b->_wds;
  xb = b->_x;
  xbe = xb + wb;
  xc = c->_x;
  borrow = 0;
  do
    {
      y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
      borrow = y >> 16;
      Sign_Extend (borrow, y);
      z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
      borrow = z >> 16;
      Sign_Extend (borrow, z);
      Storeinc (xc, z, y);
    }
  while (xb < xbe);
  while (xa < xae)
    {
      y = (*xa & 0xffff) + borrow;
      borrow = y >> 16;
      Sign_Extend (borrow, y);
      z = (*xa++ >> 16) + borrow;
      borrow = z >> 16;
      Sign_Extend (borrow, z);
      Storeinc (xc, z, y);
    }
  while (!*--xc)
    wa--;
  c->_wds = wa;
  return c;
}

double ulp(double _x)
{
  union double_union x, a;
  register __Long L;

  x.d = _x;

  L = (word0 (x) & Exp_mask) - (P - 1) * Exp_msk1;
  if (L > 0)
    {
      word0 (a) = L;
      word1 (a) = 0;
    }
  else
    {
      L = -L >> Exp_shift;
      if (L < Exp_shift)
	{
	  word0 (a) = 0x80000 >> L;
	  word1 (a) = 0;
	}
      else
	{
	  word0 (a) = 0;
	  L -= Exp_shift;
	  word1 (a) = L >= 31 ? 1 : 1 << (31 - L);
	}
    }
  return a.d;
}

double b2d(_Bigint *a, int *e)
{
  __ULong *xa, *xa0, w, y, z;
  int k;
  union double_union d;
#define d0 word0(d)
#define d1 word1(d)

  xa0 = a->_x;
  xa = xa0 + a->_wds;
  y = *--xa;
  k = hi0bits (y);
  *e = 32 - k;
  if (k < Ebits)
    {
      d0 = Exp_1 | y >> (Ebits - k);
      w = xa > xa0 ? *--xa : 0;
      d1 = y << ((32 - Ebits) + k) | w >> (Ebits - k);
      goto ret_d;
    }
  z = xa > xa0 ? *--xa : 0;
  if (k -= Ebits)
    {
      d0 = Exp_1 | y << k | z >> (32 - k);
      y = xa > xa0 ? *--xa : 0;
      d1 = z << k | y >> (32 - k);
    }
  else
    {
      d0 = Exp_1 | y;
      d1 = z;
    }
ret_d:
#undef d0
#undef d1
  return d.d;
}

_Bigint *d2b(struct _reent *ptr, double _d, int *e, int *bits)
{
  union double_union d;
  _Bigint *b;
  int de, i, k;
  __ULong *x, y, z;
  d.d = _d;
#define d0 word0(d)
#define d1 word1(d)

  b = Balloc (ptr, 1);
  x = b->_x;

  z = d0 & Frac_mask;
  d0 &= 0x7fffffff;		/* clear sign bit, which we ignore */
  if ((de = (int) (d0 >> Exp_shift)) != 0)
    z |= Exp_msk1;
  if (d1)
    {
      y = d1;
      k = lo0bits (&y);
      if (k)
	{
	  x[0] = y | z << (32 - k);
	  z >>= k;
	}
      else
	x[0] = y;
      i = b->_wds = (x[1] = z) ? 2 : 1;
    }
  else
    {
      k = lo0bits (&z);
      x[0] = z;
      i = b->_wds = 1;
      k += 32;
    }
  if (de)
    {
      *e = de - Bias - (P - 1) + k;
      *bits = P - k;
    }
  else
    {
      *e = de - Bias - (P - 1) + 1 + k;
      *bits = 32 * i - hi0bits (x[i - 1]);
    }
  return b;
}
#undef d0
#undef d1

double ratio(_Bigint *a, _Bigint *b)
{
  union double_union da, db;
  int k, ka, kb;

  da.d = b2d (a, &ka);
  db.d = b2d (b, &kb);
  k = ka - kb + 32 * (a->_wds - b->_wds);
  if (k > 0)
    word0 (da) += k * Exp_msk1;
  else
    {
      k = -k;
      word0 (db) += k * Exp_msk1;
    }
  return da.d / db.d;
}


const double
  tens[] =
{
  1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9,
  1e10, 1e11, 1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18, 1e19,
  1e20, 1e21, 1e22, 1e23, 1e24

};

const double bigtens[] =
{1e16, 1e32, 1e64, 1e128, 1e256};

const double tinytens[] =
{1e-16, 1e-32, 1e-64, 1e-128, 1e-256};

double _mprec_log10(int dig)
{
  double v = 1.0;
  if (dig < 24)
    return tens[dig];
  while (dig > 0)
    {
      v *= 10;
      dig--;
    }
  return v;
}
