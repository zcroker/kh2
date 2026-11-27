/* Sony PS2 Runtime Library 3.0.0: libkernl printf (kprintf.o), 0x306e48-0x306e80: the SIO putc.
 * Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 runtime library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv, as=ee-as), kept apart from kprintf.c: here the assembler moves the volatile
 * TX FIFO store into the jr delay slot, as in the original, while the rest of kprintf.o needs the 2.9
 * toolchain's own assembler (it keeps the nop after c.eq.s). */

/* SIO putc: wait while the TX FIFO is full, then write the byte. */
int func_00306e48(int c)
{
    while (*(volatile int *)0x1000f130 & 0x8000)
        ;
    *(volatile char *)0x1000f180 = c;
    return c;
}
