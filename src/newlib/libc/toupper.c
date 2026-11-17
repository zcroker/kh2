/* toupper.c: newlib libc (libc/ctype/toupper.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2ffbe0-0x2ffc08. Third-party code notice: rebuilt to match; not covered by this project's MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "ctype.h"

int toupper(int c)
{
    return islower(c) ? c - 'a' + 'A' : c;
}
