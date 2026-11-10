/* Sony PS2 Runtime Library 3.0.0: libkernl. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Partial inline asm only where the original is hand-written: sync/nop around the INTC_STAT wait,
 * the 128-bit sq clear of a new thread's saved context, and the t0-t2 timer read. */
typedef unsigned int u32;
extern int DIntr(void);
extern int EIntr(void);

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

typedef struct { int status; int f4; char *stack; int stackSize; int pad[8]; } ThreadStat;
extern int func_003060f0(void);
extern int func_00305520(int, ThreadStat *);
extern int func_00305440(int, int);
int func_00306760(int tid, int arg)
{
    ThreadStat st;
    int r;
    char *p;
    if (func_003060f0())
        return -1;
    if (!DIntr())
        return -1;
    r = func_00305520(tid, &st);
    if (r < 0) {
        EIntr();
        return r;
    }
    if (st.status != 16) {
        EIntr();
        return -1;
    }
    p = st.stack + st.stackSize - 0x2a0;
    /* hand-written: clear the new thread's saved context with 128-bit stores */
    asm volatile(
        "sq $0,0(%0)\n\t"
        "sq $0,16(%0)\n\t"
        "sq $0,32(%0)\n\t"
        "sq $0,48(%0)\n\t"
        "sq $0,64(%0)\n\t"
        "sq $0,80(%0)\n\t"
        "sq $0,96(%0)\n\t"
        "sq $0,112(%0)\n\t"
        "sq $0,128(%0)\n\t"
        "sq $0,144(%0)\n\t"
        "sq $0,160(%0)\n\t"
        "sq $0,176(%0)\n\t"
        "sq $0,192(%0)\n\t"
        "sq $0,208(%0)\n\t"
        "sq $0,224(%0)\n\t"
        "sq $0,240(%0)\n\t"
        "sq $0,256(%0)\n\t"
        "sq $0,272(%0)\n\t"
        "sq $0,288(%0)\n\t"
        "sq $0,304(%0)\n\t"
        "sq $0,320(%0)\n\t"
        "sq $0,336(%0)\n\t"
        "sq $0,352(%0)\n\t"
        "sq $0,368(%0)\n\t"
        "sq $0,384(%0)\n\t"
        "sq $0,400(%0)\n\t"
        "sq $0,416(%0)\n\t"
        "sq $0,432(%0)\n\t"
        "sq $0,512(%0)\n\t"
        "sq $0,528(%0)\n\t"
        "sq $0,544(%0)\n\t"
        "sq $0,560(%0)\n\t"
        "sq $0,576(%0)\n\t"
        "sq $0,592(%0)\n\t"
        "sq $0,608(%0)\n\t"
        "sq $0,624(%0)\n\t"
        "sll $8,%1,0\n\t"
        "sd $8,64(%0)\n\t"
        "lw $8,448(%0)\n\t"
        "sd $8,448(%0)\n\t"
        "sd $0,456(%0)\n\t"
        "lw $8,464(%0)\n\t"
        "sd $8,464(%0)\n\t"
        "sd $0,472(%0)\n\t"
        "lw $8,480(%0)\n\t"
        "sd $8,480(%0)\n\t"
        "sd $0,488(%0)\n\t"
        "lw $8,496(%0)\n\t"
        "sd $8,496(%0)\n\t"
        "sd $0,504(%0)\n\t"
        : : "r"(p), "r"(arg) : "$8", "memory");
    EIntr();
    return func_00305440(tid, arg);
}
