/* libkernl_0030f250.c: Sony PS2 Runtime Library 3.0.0 libkernl: a byte copy (the object's own static copy
 * helper), 0x30f250. ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and
 * C functions around it are separate units). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */

/* ---- 0x30f250 (gap) */
int func_0030f250(unsigned char *dst, unsigned char *src, unsigned int size)
{
    unsigned int i;
    for (i = 0; i < size; i++)
        *dst++ = *src++;
    return 0;
}
