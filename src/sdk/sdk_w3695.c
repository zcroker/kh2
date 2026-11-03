/* Sony PS2 Runtime Library 3.0.0: libkernl (SIO putc, SIF DMA with a trailing 16-byte packet). Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: these functions were rebuilt to match Sony Computer Entertainment's
 * PS2 runtime libraries that the game links. That code is not covered by this project's MIT License. */
typedef unsigned int u_int;

/* SIO putc: wait while the TX FIFO is full, then write the byte.
 * The empty asm hides the FIFO address from gcc so the store is a plain sb through a
 * register (lui/ori) that gcc can put in the jr delay slot, like the original. */
int func_00306e48(int c)
{
    char *txfifo;
    while (*(volatile int *)0x1000f130 & 0x8000)
        ;
    txfifo = (char *)0x1000f180;
    asm("" : "+r"(txfifo));
    *txfifo = c;
    return c;
}

typedef struct { u_int data, addr; int size, mode; } SifDmaData_w3695;
extern void *func_002fdd68(void *, const void *, int);
extern int func_003059e0(SifDmaData_w3695 *, int);
extern int func_003059f0(SifDmaData_w3695 *, int);
extern int D_003780c0;
/* const: the load carries no anti-dependences on the stack stores, which gives sched2 the original order. */
extern const u_int D_01e357e0;

/* Copies n DMA entries, appends a 16-byte transfer of D_003780c0 to the IOP address in
 * D_01e357e0, then starts the list (mode 0: normal, else the interrupt-safe variant). */
int func_00308248(SifDmaData_w3695 *src, int n, int mode)
{
    SifDmaData_w3695 d[32];
    if (n < 32) {
        func_002fdd68(d, src, n * 16);
        d[n].data = (u_int)&D_003780c0;
        d[n].addr = D_01e357e0;
        d[n].size = 16;
        d[n].mode = 0x44;
        n++;
        if (mode == 0)
            return func_003059e0(d, n);
        return func_003059f0(d, n);
    }
    return 0;
}
