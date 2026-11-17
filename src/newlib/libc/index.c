/* index.c: newlib libc (libc/string/index.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2fd3d0-0x2fd3e8. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
char *strchr(const char *, int);

char *index(const char *s, int c)
{
    return strchr(s, c);
}
