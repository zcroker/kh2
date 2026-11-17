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
unsigned long func_0030ff58(void);  // 0x0030ff58: definition moved into src/sdk/libkernl_0030ff58.c

typedef struct { int status; int f4; char *stack; int stackSize; int pad[8]; } ThreadStat;
extern int func_003060f0(void);
extern int func_00305520(int, ThreadStat *);
extern int func_00305440(int, int);
int func_00306760(int tid, int arg);  // 0x00306760: definition moved into src/sdk/libkernl_00306698.c
