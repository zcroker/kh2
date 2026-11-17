/* strrchr.c: newlib libc (libc/string/strrchr.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2ff8b0-0x2ff918. Third-party code notice: rebuilt to match; not covered by this project's MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "newlib.h"
char *strchr(const char *, int);

char *strrchr(const char *s, int i)
{
    const char *last = NULL;

    if (i) {
        while ((s = strchr(s, i))) {
            last = s;
            s++;
        }
    } else {
        last = strchr(s, i);
    }

    return (char *)last;
}
