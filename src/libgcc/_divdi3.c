/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc2.c _divdi3.o (gcc 3.2-ee-040921), 0x311dd0-0x3125c0: __divdi3 (func_00311dd0) and its static __udivmoddi4 copy
 * (func_00311ef8). Linked unit (linked_units.tsv), built with -fnon-call-exceptions (gcc's
 * LIB2_DIVMOD_EXCEPTION_FLAGS). The old global names from functions.tsv are kept. */
#include "udivmoddi4.h"

UDWtype func_00311ef8(UDWtype n, UDWtype d, UDWtype *rp);
static inline DItype __negdi2(DItype u)
{
    DWunion w;
    DWunion uu;
    uu.ll = u;
    w.s.low = -uu.s.low;
    w.s.high = -uu.s.high - ((USItype) w.s.low > 0);
    return w.ll;
}

DItype func_00311dd0(DItype u, DItype v)
{
    int c = 0;
    DWunion uu, vv;
    DItype w;

    uu.ll = u;
    vv.ll = v;

    if (uu.s.high < 0)
        c = ~c, uu.ll = __negdi2(uu.ll);
    if (vv.s.high < 0)
        c = ~c, vv.ll = __negdi2(vv.ll);

    w = func_00311ef8(uu.ll, vv.ll, (UDWtype *) 0);
    if (c)
        w = __negdi2(w);

    return w;
}

UDWtype func_00311ef8(UDWtype n, UDWtype d, UDWtype *rp)
{
    UDIVMODDI4_BODY
}
