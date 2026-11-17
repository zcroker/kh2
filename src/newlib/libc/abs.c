/* abs.c: newlib libc (libc/stdlib/abs.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2fd178-0x2fd188. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
int abs(int i)
{
    return (i < 0) ? -i : i;
}
