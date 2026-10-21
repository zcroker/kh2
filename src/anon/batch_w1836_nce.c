/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"
/* libgcc2.c __moddi3 (gcc 3.2-ee-040921): GCC library code, byte-identical to the toolchain's libgcc.a.
 * __negdi2 is inlined (static inline in libgcc2.c); 0x3126f0 is the static __udivmoddi4 copy.
 * Built with -fnon-call-exceptions like the rest of libgcc's divide helpers. */
typedef int W1836SItype;
typedef unsigned int W1836USItype;
typedef long long W1836DItype;
typedef unsigned long long W1836UDItype;
struct W1836DWstruct { W1836SItype low, high; };
typedef union { struct W1836DWstruct s; W1836DItype ll; } W1836DWunion;

W1836UDItype func_003126f0(W1836UDItype n, W1836UDItype d, W1836UDItype* rp);

static inline W1836DItype w1836_negdi2(W1836DItype u)
{
    W1836DWunion w;
    W1836DWunion uu;
    uu.ll = u;
    w.s.low = -uu.s.low;
    w.s.high = -uu.s.high - ((W1836USItype) w.s.low > 0);
    return w.ll;
}

W1836DItype func_003125c0(W1836DItype u, W1836DItype v)
{
    int c = 0;
    W1836DWunion uu, vv;
    W1836DItype w;

    uu.ll = u;
    vv.ll = v;

    if (uu.s.high < 0)
        c = ~c,
        uu.ll = w1836_negdi2(uu.ll);
    if (vv.s.high < 0)
        vv.ll = w1836_negdi2(vv.ll);

    (void) func_003126f0(uu.ll, vv.ll, (W1836UDItype*) &w);
    if (c)
        w = w1836_negdi2(w);

    return w;
}
