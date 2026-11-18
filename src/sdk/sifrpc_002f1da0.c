/* Sony PS2 Runtime Library: the SIF RPC client of sifrpc_002f1b48.c, its last part 0x2f1da0-0x2f1e18: the
 * sync/check entry and the end-of-call callback. Built with ee-gcc 2.96 -O2.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv, cc=ee-gcc2.96). The semaphore id is read through $gp (gp-0x1d20), as in
 * sifrpc_002f1b48.c; sema() is the one-load read the callback needs. */
typedef struct { int pad[9]; int serve; } ClientData;

extern int SignalSema(int);
extern int iSignalSema(int);
extern int WaitSema(int);
extern int func_003096b8(ClientData *);

extern ClientData D_01e2d900;

static inline int sema(void) { int r; __asm__("lw %0,-7456($28)" : "=r"(r)); return r; }

int func_002f1da0(int mode)
{
    register int *gp asm("$28");
    switch (mode) {
    case 0:
        WaitSema(gp[-1864]);
        SignalSema(gp[-1864]);
        return 0;
    case 1:
        return func_003096b8(&D_01e2d900);
    }
    return -1;
}

void func_002f1e00(void *p)
{
    iSignalSema(sema());
}
