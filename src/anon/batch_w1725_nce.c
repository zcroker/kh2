/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc2.c __udivdi3 (gcc 3.2-ee-040921): calls its static __udivmoddi4 copy at 0x312dd0.
 * Built with -fnon-call-exceptions like the rest of libgcc's divide helpers. */
#include "../common/types.h"

u64 func_00312dd0(u64 n, u64 d, u64* rp);

u64 func_00312db8(u64 n, u64 d) { return func_00312dd0(n, d, (u64*)0); }
