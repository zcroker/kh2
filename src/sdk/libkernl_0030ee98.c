/* libkernl_0030ee98.c: Sony PS2 Runtime Library 3.0.0 libkernl: a word copy and a word search, 0x30ee98-0x30ef10.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs around it stay
 * separate units). The kernel-patch code in libkernl_0030ef20.c searches kernel memory for these two
 * functions' code (D_0030ee98 / D_0030eed0), so the kernel holds the same two routines.
 * Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */

/* ---- 0x30ee98 (gap) */
int func_0030ee98(unsigned int *dst, unsigned int *src, unsigned int size)
{
    unsigned int i;
    size >>= 2;
    for (i = 0; i < size; i++)
        *dst++ = *src++;
    return 0;
}

/* ---- 0x30eed0 (gap) */
unsigned int *func_0030eed0(unsigned int *p, unsigned int *end, unsigned int v)
{
    while (*p != v && p < end)
        p++;
    return p < end ? p : 0;
}
