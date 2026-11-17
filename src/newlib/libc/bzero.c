/* bzero.c: newlib libc (libc/string/bzero.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2fd310-0x2fd348. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
void bzero(char *b, int length)
{
    while (length--)
        *b++ = 0;
}
