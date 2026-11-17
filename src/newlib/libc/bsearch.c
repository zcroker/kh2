/* bsearch.c: newlib libc (libc/stdlib/bsearch.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2fd248-0x2fd310. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. bsearch, Copyright (c) 1990 Jim Kingdon (public domain in newlib). */
#include "newlib.h"

void *bsearch(const void *key, const void *base, size_t nmemb, size_t size,
              int (*compar)(const void *, const void *))
{
    void *current;
    size_t lower = 0;
    size_t upper = nmemb;
    size_t index;
    int result;

    if (nmemb == 0 || size == 0)
        return NULL;
    while (lower < upper) {
        index = (lower + upper) / 2;
        current = (void *)(((char *)base) + (index * size));

        result = compar(key, current);
        if (result < 0)
            upper = index;
        else if (result > 0)
            lower = index + 1;
        else
            return current;
    }
    return NULL;
}
