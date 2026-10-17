/* libgcc2.c (gcc 3.2-ee-040921) __udivmoddi4 (copied from batch_w1626_nce.c), byte-identical to the toolchain's own libgcc.a.
 * libgcc builds its divide/modulo helpers (LIB2_DIVMOD_FUNCS) with -fnon-call-exceptions,
 * which this file gets from the *_nce.c rule in the Makefile.
 * The table at 0x3784b0 is libgcc's __clz_tab. */
#include "../common/types.h"

typedef int W1627SItype;
typedef unsigned int W1627USItype;
typedef long long W1627DItype;
typedef unsigned long long W1627UDItype;

struct W1627DWstruct { W1627SItype low, high; };
typedef union { struct W1627DWstruct s; W1627DItype ll; } W1627DWunion;

#define UWtype W1627USItype
#define UHWtype W1627USItype
#define UDWtype W1627UDItype
#define DWunion W1627DWunion
#define W_TYPE_SIZE 32
#define __BITS4 (W_TYPE_SIZE / 4)
#define __ll_B ((UWtype) 1 << (W_TYPE_SIZE / 2))
#define __ll_lowpart(t) ((UWtype) (t) & (__ll_B - 1))
#define __ll_highpart(t) ((UWtype) (t) >> (W_TYPE_SIZE / 2))

#define sub_ddmmss(sh, sl, ah, al, bh, bl) \
  do {									\
    UWtype __x;								\
    __x = (al) - (bl);							\
    (sh) = (ah) - (bh) - (__x > (al));					\
    (sl) = __x;								\
  } while (0)

#define umul_ppmm(w1, w0, u, v)						\
  do {									\
    UWtype __x0, __x1, __x2, __x3;					\
    UHWtype __ul, __vl, __uh, __vh;					\
    __ul = __ll_lowpart (u);						\
    __uh = __ll_highpart (u);						\
    __vl = __ll_lowpart (v);						\
    __vh = __ll_highpart (v);						\
    __x0 = (UWtype) __ul * __vl;					\
    __x1 = (UWtype) __ul * __vh;					\
    __x2 = (UWtype) __uh * __vl;					\
    __x3 = (UWtype) __uh * __vh;					\
    __x1 += __ll_highpart (__x0);					\
    __x1 += __x2;							\
    if (__x1 < __x2)							\
      __x3 += __ll_B;							\
    (w1) = __x3 + __ll_highpart (__x1);					\
    (w0) = __ll_lowpart (__x1) * __ll_B + __ll_lowpart (__x0);		\
  } while (0)

#define udiv_qrnnd(q, r, n1, n0, d) \
  do {									\
    UWtype __d1, __d0, __q1, __q0;					\
    UWtype __r1, __r0, __m;						\
    __d1 = __ll_highpart (d);						\
    __d0 = __ll_lowpart (d);						\
    __r1 = (n1) % __d1;							\
    __q1 = (n1) / __d1;							\
    __m = (UWtype) __q1 * __d0;						\
    __r1 = __r1 * __ll_B | __ll_highpart (n0);				\
    if (__r1 < __m)							\
      {									\
	__q1--, __r1 += (d);						\
	if (__r1 >= (d))						\
	  if (__r1 < __m)						\
	    __q1--, __r1 += (d);					\
      }									\
    __r1 -= __m;							\
    __r0 = __r1 % __d1;							\
    __q0 = __r1 / __d1;							\
    __m = (UWtype) __q0 * __d0;						\
    __r0 = __r0 * __ll_B | __ll_lowpart (n0);				\
    if (__r0 < __m)							\
      {									\
	__q0--, __r0 += (d);						\
	if (__r0 >= (d))						\
	  if (__r0 < __m)						\
	    __q0--, __r0 += (d);					\
      }									\
    __r0 -= __m;							\
    (q) = (UWtype) __q1 * __ll_B | __q0;				\
    (r) = __r0;								\
  } while (0)

#define count_leading_zeros(count, x) \
  do {									\
    UWtype __xr = (x);							\
    UWtype __a;								\
    if (W_TYPE_SIZE <= 32)						\
      {									\
	__a = __xr < ((UWtype)1<<2*__BITS4)				\
	  ? (__xr < ((UWtype)1<<__BITS4) ? 0 : __BITS4)		\
	  : (__xr < ((UWtype)1<<3*__BITS4) ?  2*__BITS4 : 3*__BITS4);	\
      }									\
    else								\
      {									\
	for (__a = W_TYPE_SIZE - 8; __a > 0; __a -= 8)			\
	  if (((__xr >> __a) & 0xff) != 0)				\
	    break;							\
      }									\
    (count) = W_TYPE_SIZE - (D_003784b0[__xr >> __a] + __a);		\
  } while (0)


extern const u8 D_003784b0[];

#define UDIVMODDI4_BODY \
  DWunion ww;								\
  DWunion nn, dd;							\
  DWunion rr;								\
  UWtype d0, d1, n0, n1, n2;						\
  UWtype q0, q1;							\
  UWtype b, bm;								\
  nn.ll = n;								\
  dd.ll = d;								\
  d0 = dd.s.low;							\
  d1 = dd.s.high;							\
  n0 = nn.s.low;							\
  n1 = nn.s.high;							\
  if (d1 == 0)								\
    {									\
      if (d0 > n1)							\
	{								\
	  count_leading_zeros (bm, d0);					\
	  if (bm != 0)							\
	    {								\
	      d0 = d0 << bm;						\
	      n1 = (n1 << bm) | (n0 >> (W_TYPE_SIZE - bm));		\
	      n0 = n0 << bm;						\
	    }								\
	  udiv_qrnnd (q0, n0, n1, n0, d0);				\
	  q1 = 0;							\
	}								\
      else								\
	{								\
	  if (d0 == 0)							\
	    d0 = 1 / d0;						\
	  count_leading_zeros (bm, d0);					\
	  if (bm == 0)							\
	    {								\
	      n1 -= d0;							\
	      q1 = 1;							\
	    }								\
	  else								\
	    {								\
	      b = W_TYPE_SIZE - bm;					\
	      d0 = d0 << bm;						\
	      n2 = n1 >> b;						\
	      n1 = (n1 << bm) | (n0 >> b);				\
	      n0 = n0 << bm;						\
	      udiv_qrnnd (q1, n1, n2, n1, d0);				\
	    }								\
	  udiv_qrnnd (q0, n0, n1, n0, d0);				\
	}								\
      if (rp != 0)							\
	{								\
	  rr.s.low = n0 >> bm;						\
	  rr.s.high = 0;						\
	  *rp = rr.ll;							\
	}								\
    }									\
  else									\
    {									\
      if (d1 > n1)							\
	{								\
	  q0 = 0;							\
	  q1 = 0;							\
	  if (rp != 0)							\
	    {								\
	      rr.s.low = n0;						\
	      rr.s.high = n1;						\
	      *rp = rr.ll;						\
	    }								\
	}								\
      else								\
	{								\
	  count_leading_zeros (bm, d1);					\
	  if (bm == 0)							\
	    {								\
	      if (n1 > d1 || n0 >= d0)					\
		{							\
		  q0 = 1;						\
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);			\
		}							\
	      else							\
		q0 = 0;							\
	      q1 = 0;							\
	      if (rp != 0)						\
		{							\
		  rr.s.low = n0;					\
		  rr.s.high = n1;					\
		  *rp = rr.ll;						\
		}							\
	    }								\
	  else								\
	    {								\
	      UWtype m1, m0;						\
	      b = W_TYPE_SIZE - bm;					\
	      d1 = (d1 << bm) | (d0 >> b);				\
	      d0 = d0 << bm;						\
	      n2 = n1 >> b;						\
	      n1 = (n1 << bm) | (n0 >> b);				\
	      n0 = n0 << bm;						\
	      udiv_qrnnd (q0, n1, n2, n1, d1);				\
	      umul_ppmm (m1, m0, q0, d0);				\
	      if (m1 > n1 || (m1 == n1 && m0 > n0))			\
		{							\
		  q0--;							\
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);			\
		}							\
	      q1 = 0;							\
	      if (rp != 0)						\
		{							\
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);			\
		  rr.s.low = (n1 << b) | (n0 >> bm);			\
		  rr.s.high = n1 >> bm;					\
		  *rp = rr.ll;						\
		}							\
	    }								\
	}								\
    }									\
  ww.s.low = q0;							\
  ww.s.high = q1;							\
  return ww.ll;

/* libgcc2.c __udivmoddi4: static copies in _udivdi3.o (0x312dd0, called by __udivdi3 at 0x312db8)
 * and _umoddi3.o (0x3134b8, called by __umoddi3 at 0x313498). */
UDWtype func_00312dd0(UDWtype n, UDWtype d, UDWtype* rp)
{
    UDIVMODDI4_BODY
}

UDWtype func_003134b8(UDWtype n, UDWtype d, UDWtype* rp)
{
    UDIVMODDI4_BODY
}
