/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc2.c _umoddi3.o (gcc 3.2-ee-040921), 0x313498-0x313b80: __umoddi3 and its static __udivmoddi4 copy
 * (func_003134b8). Linked unit (linked_units.tsv), built with -fnon-call-exceptions (gcc's
 * LIB2_DIVMOD_EXCEPTION_FLAGS). The old global names from functions.tsv are kept. */
#include "udivmoddi4.h"

UDWtype func_003134b8(UDWtype n, UDWtype d, UDWtype *rp);

UDWtype __umoddi3(UDWtype u, UDWtype v)
{
    UDWtype w;

    (void) func_003134b8(u, v, &w);

    return w;
}

UDWtype func_003134b8(UDWtype n, UDWtype d, UDWtype *rp)
{
    UDIVMODDI4_BODY
}
