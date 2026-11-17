/* libkernl_0030ff58.c: Sony PS2 Runtime Library 3.0.0 libkernl: iGetTimerSystemTime-style read, 0x30ff58-0x30ffd4.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
extern int DIntr(void);
extern void EIntr(void);
extern unsigned long D_00367118;
unsigned long func_0030ff58(void)
{
    int s;
    unsigned long r;
    s = DIntr();
    /* hand-written timer read (original inline asm block) */
    asm volatile(
        ".set noreorder\n\t"
        "lwu %0,0(%1)\n\t"
        "lw $8,16(%1)\n\t"
        "ld $10,%2\n\t"
        "andi $9,$8,0x800\n\t"
        "beqz $9,1f\n\t"
        "li $9,2\n\t"
        "lwu %0,0(%1)\n\t"
        "daddiu $10,$10,1\n"
        "1:\tandi $8,$8,3\n\t"
        "dsll $10,$10,16\n\t"
        "movz $9,$0,$8\n\t"
        "or %0,%0,$10\n\t"
        "dsllv $9,$9,$8\n\t"
        "dsllv %0,%0,$9\n\t"
        ".set reorder"
        : "=&r"(r) : "r"((volatile unsigned int *)0x10001000), "m"(D_00367118) : "$8", "$9", "$10");
    if (s) EIntr();
    return r;
}
