/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"
extern "C" {
// libsupc++ eh_catch.cc: std::uncaught_exception()
struct EhGlobals3167d0 { void* caughtExceptions; u32 uncaughtExceptions; };
EhGlobals3167d0* func_00316af8(void); // __cxa_get_globals
bool func_003167d0(void)
{
    EhGlobals3167d0* g = func_00316af8();
    return g->uncaughtExceptions != 0;
}
}
