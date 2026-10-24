/* Sony PS2 Runtime Library: libkernl kernel-mode helper (0x366xxx). ee-gcc 2.9-991111 -O2 -G0. */
/* Kernel function table at 0x8007474c..0x80074764. */
extern void (*D_80074760)(void);
extern void (*D_80074764)(int, int, int);
extern void (*D_8007474c)(int);
extern void (*D_80074750)(void);
extern void (*D_8007475c)(int);
extern void (*D_80074754)(void);
extern void (*D_80074758)(void);

/* 00366570: acknowledge INTC bit 2 (0x1000f000), wait for it to be raised again, ack it, then run the kernel hooks. */
void func_00366570(void)
{
    *(volatile int *)0x1000f000 = 4;
    while (!(*(volatile int *)0x1000f000 & 4))
        ;
    *(volatile int *)0x1000f000 = 4;
    D_80074760();
    D_80074764(1, 2, 1);
    D_8007474c(0xdffd);
    D_80074750();
    D_8007475c(127);
    D_80074754();
    D_80074758();
}
