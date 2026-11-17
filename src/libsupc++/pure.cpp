/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libsupc++ pure.cc (gcc 3.2-ee-040921), 0x3155c0-0x3155e8: __cxa_pure_virtual (.rodata 0x3785f8). Linked unit (linked_units.tsv). */
#include <bits/c++config.h>
#include <cstdio>
#include "unwind-cxx.h"

#define writestr(str)	std::fputs(str, stderr)

extern "C" void
__cxa_pure_virtual (void)
{
  writestr ("pure virtual method called\n");
  std::terminate ();
}
