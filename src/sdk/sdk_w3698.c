/* Sony PS2 Runtime Library: libkernl (RPC bind wait). Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License. */
typedef struct { int pad[9]; int p24; } R0030d820;
extern R0030d820 D_01e38a80;
extern int D_0036617c;
extern int sceSifBindRpc(void *, int, int);

/* Waits until the RPC server is bound (p24 set), then clears D_0036617c. */
int func_0030d820(void)
{
    int i;
    while (1) {
        if (sceSifBindRpc(&D_01e38a80, 0x80000003, 0) < 0) return -1;
        if (D_01e38a80.p24) break;
        i = 0x100000;
        do {
            i--;
            asm volatile("nop"); asm volatile("nop"); asm volatile("nop"); asm volatile("nop");
        } while (i != -1);
    }
    D_0036617c = 0;
    /* empty barrier: keeps sched1 from hoisting the return value above the store (v0 then holds the address) */
    asm volatile("");
    return 0;
}
