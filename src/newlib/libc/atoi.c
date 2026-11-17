/* atoi.c: newlib libc (libc/stdlib/atoi.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2fd220-0x2fd248. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "newlib.h"
long strtol(const char *, char **, int);

int atoi(const char *s)
{
    return (int)strtol(s, NULL, 10);
}
