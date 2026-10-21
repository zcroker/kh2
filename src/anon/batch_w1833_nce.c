/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc2.c __divdi3 (gcc 3.2-ee-040921): GCC library code. It calls the static
 * __udivmoddi4 copy at 0x311ef8. Built with -fnon-call-exceptions (*_nce.c rule),
 * like libgcc's other divide helpers. */
#include "../common/types.h"

typedef int W1833SItype;
typedef unsigned int W1833USItype;
typedef long long W1833DItype;
typedef unsigned long long W1833UDItype;
struct W1833DWstruct { W1833SItype low, high; };
typedef union { struct W1833DWstruct s; W1833DItype ll; } W1833DWunion;

W1833UDItype func_00311ef8(W1833UDItype n, W1833UDItype d, W1833UDItype* rp);

static inline W1833DItype w1833_negdi2(W1833DItype u)
{
    W1833DWunion w;
    W1833DWunion uu;
    uu.ll = u;
    w.s.low = -uu.s.low;
    w.s.high = -uu.s.high - ((W1833USItype) w.s.low > 0);
    return w.ll;
}

W1833DItype func_00311dd0(W1833DItype u, W1833DItype v)
{
    int c = 0;
    W1833DWunion uu, vv;
    W1833DItype w;

    uu.ll = u;
    vv.ll = v;

    if (uu.s.high < 0)
        c = ~c, uu.ll = w1833_negdi2(uu.ll);
    if (vv.s.high < 0)
        c = ~c, vv.ll = w1833_negdi2(vv.ll);

    w = func_00311ef8(uu.ll, vv.ll, (W1833UDItype*) 0);
    if (c)
        w = w1833_negdi2(w);

    return w;
}
