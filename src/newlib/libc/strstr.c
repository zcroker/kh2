/* strstr.c: newlib libc (libc/string/strstr.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2ff918-0x2ff970. Third-party code notice: rebuilt to match; not covered by this project's MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "newlib.h"

char *strstr(const char *searchee, const char *lookfor)
{
    if (*searchee == 0) {
        if (*lookfor)
            return (char *)NULL;
        return (char *)searchee;
    }

    while (*searchee) {
        size_t i;
        i = 0;

        while (1) {
            if (lookfor[i] == 0)
                return (char *)searchee;

            if (lookfor[i] != searchee[i])
                break;
            i++;
        }
        searchee++;
    }

    return (char *)NULL;
}
