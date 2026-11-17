/* Sony PS2 Runtime Library 3.0.0: libkernl, 0x305aa0-0x305b40: the start of the object that ends with the newlib
 * glue (glue.c): the TTY-ready flag reset and the vsync wait on INTC_STAT, before whole-asm 0x305b40.
 * Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv): a part of the object, compiled as one file. Its .data (0x3660c8, 0x3660cc)
 * stays outside with the whole-asm function, reached by name. Partial inline asm only where the original is
 * hand-written: sync after the INTC_STAT writes and the nop in the poll loop (asm_review.tsv). */
typedef unsigned int u32;
extern int DIntr(void);
extern int EIntr(void);
extern int D_003660c8;

void func_00305aa0(void) { D_003660c8 = 0; }

void func_00305ab0(void)
{
    int s;
    u32 x;
    s = DIntr();
    *(volatile u32 *)0x1000f000 = 4;
    asm volatile("sync");
    if (s) EIntr();
    /* hand-written: sync after the INTC_STAT write, nop padding in the poll loop */
    do {
        x = *(volatile u32 *)0x1000f000 & 4;
        asm volatile("nop");
    } while (!x);
    s = DIntr();
    *(volatile u32 *)0x1000f000 = 4;
    asm volatile("sync");
    if (s) EIntr();
}
