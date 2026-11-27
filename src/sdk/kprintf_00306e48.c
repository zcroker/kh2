/* Sony PS2 Runtime Library 3.0.0: libkernl printf (kprintf.o), 0x306e48-0x306ff8: the SIO putc, the Deci2
 * and SIO character outputs and the double-to-int helper of the %e/%f output.
 * Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 runtime library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv, as=ee-as), kept apart from kprintf.c: here the assembler moves the instruction
 * before a `jr ra` into its delay slot, as in the original (the volatile TX FIFO store in func_00306e48, the
 * second half of the 64-to-32-bit truncation in func_00306f68), while the rest of kprintf.o needs the 2.9
 * toolchain's own assembler (it keeps the nop after c.eq.s). */

extern void func_003111f0(char *);

/* SIO putc: wait while the TX FIFO is full, then write the byte. */
int func_00306e48(int c)
{
    while (*(volatile int *)0x1000f130 & 0x8000)
        ;
    *(volatile char *)0x1000f180 = c;
    return c;
}

int D_003660d4 = 0;
extern char D_01e35680[];
void func_00306e80(int c)
{
    int n = D_003660d4;
    if (n >= 126) {
        D_003660d4 = 0;
        D_01e35680[127] = 0;
        func_003111f0(D_01e35680);
        n = D_003660d4;
    }
    if (c == '\n') {
        D_01e35680[n] = c;
        D_003660d4 = 0;
        D_01e35680[n + 1] = 0;
        func_003111f0(D_01e35680);
    } else {
        D_003660d4 = n + 1;
        D_01e35680[n] = c;
    }
}

void func_00306f30(int c)
{
    if (c == '\n') {
        func_00306e48('\r');
        func_00306e48('\n');
    } else
        func_00306e48(c);
}

/* double bits -> int, clamped to [0, 9999], rounded. */
typedef unsigned long u64;
int func_00306f68(u64 a)
{
    long e;
    e = (a << 1) >> 53;
    e -= 1075;
    if (e < -53) return 0;
    if (e >= 13) return 9999;
    a = (a << 12) >> 12;
    a |= (1UL << 52);
    if (e < 0) {
        e = -e;
        a >>= e - 2;
        if ((a & 3) == 3) a = (a >> 2) + 1;
        else a >>= 2;
    } else {
        a <<= e;
    }
    return a;
}
