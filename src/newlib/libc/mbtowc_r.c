/* mbtowc_r.c: newlib libc (libc/stdlib/mbtowc_r.c, without MB_CAPABLE), the copy the game links from the
 * toolchain's libc.a. Linked unit 0x303958-0x303988. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Cygnus Support. */
#include "newlib.h"
typedef int wchar_t;
typedef int mbstate_t;

int _mbtowc_r(struct _reent *r, wchar_t *pwc, const char *s, size_t n, mbstate_t *state)
{
    wchar_t dummy;
    unsigned char *t = (unsigned char *)s;

    if (pwc == NULL)
        pwc = &dummy;

    if (s != NULL && n == 0)
        return -1;

    if (s == NULL)
        return 0;  /* not state-dependent */

    *pwc = (wchar_t)*t;
    return (*t != '\0');
}
