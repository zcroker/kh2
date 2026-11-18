/* libkernl_00311310.c: Sony PS2 Runtime Library 3.0.0 libkernl: a word copy (the object's own static copy helper),
 * 0x311310. ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and C
 * functions around it are separate units). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */

/* ---- 0x311310 (gap) */
int func_00311310(unsigned int *dst, unsigned int *src, unsigned int size)
{
    unsigned int i;
    size >>= 2;
    for (i = 0; i < size; i++)
        *dst++ = *src++;
    return 0;
}
