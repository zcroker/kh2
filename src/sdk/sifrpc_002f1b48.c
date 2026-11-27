/* Sony PS2 Runtime Library: a SIF RPC client (server id 0x80000210), 0x2f1b48-0x2f1e18: bind (0x2f1b48), three
 * calls (0x2f1c60, 0x2f1cc0, 0x2f1d30), the sync/check entry (0x2f1da0) and the end-of-call callback (0x2f1e00).
 * Built with ee-gcc 2.96 -O2 -G8 (branch-likely, the `i = 0x10000; while (i--);` delay unrolled by 4), not 2.9.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv, cc=ee-gcc2.96), the first part of the object: 0x2f1b48-0x2f1cc0. 0x2f1cc0 and
 * 0x2f1d30 are sifrpc_002f1cc0.c / sifrpc_002f1d30.c (-G8 rows) and 0x2f1da0-0x2f1e18 is sifrpc_002f1da0.c. Its .rodata (the two error strings)
 * is at 0x3762a0. The semaphore id is a small-data (-G8) variable at gp-0x1d20 (0x378ae0); the link has its own
 * _gp, so it is reached through $gp here (sema(): the read written as one load, as a $28 MEM read cannot be
 * scheduled past the prologue saves). The client data (0x1e2d900) and the send buffer (0x1e2d940) by name. */
typedef struct { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; } SemaParam;
typedef struct { int pad[9]; int serve; } ClientData;

extern int CreateSema(SemaParam *);
extern int WaitSema(int);
extern int func_002fdfc8(const char *, ...);
extern void func_00308b30(int);
extern int func_003092d8(ClientData *, unsigned int, int);
extern int func_003094b8(ClientData *, int, int, void *, int, void *, int, void (*)(void *), void *);

extern ClientData D_01e2d900;
extern int D_01e2d940[16];

static inline int sema(void) { int r; __asm__("lw %0,-7456($28)" : "=r"(r)); return r; }

void func_002f1e00(void *);

int func_002f1b48(void)
{
    register int *gp asm("$28");
    SemaParam s;
    int i;
    s.initCount = 1;
    s.maxCount = 1;
    gp[-1864] = CreateSema(&s);
    if (gp[-1864] == -1) {
        func_002fdfc8("CreateSema Error\n");
        while (1) ;
    }
    func_00308b30(0);
    while (1) {
        if (func_003092d8(&D_01e2d900, 0x80000210, 0) < 0) {
            func_002fdfc8("bind errr\n");
            while (1) ;
        }
        if (D_01e2d900.serve != 0) break;
        i = 0x10000;
        while (i--) ;
    }
    return 0;
}

int func_002f1c60(void *r)
{
    WaitSema(sema());
    return func_003094b8(&D_01e2d900, 1, 1, D_01e2d940, 32, r, 32, func_002f1e00, 0);
}
