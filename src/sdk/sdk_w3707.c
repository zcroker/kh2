/* Sony PS2 Runtime Library: libkernl (sce fileio client init). Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License. */
typedef struct { int fd; int busy; int x8; int xc; } FdEnt;
typedef struct { int a; int b; } Pair;
typedef struct { void *a; void *b; } PPair;
extern FdEnt D_01e38780[];
extern char D_01e38980[];
extern char D_01e37ec0[];
extern Pair D_01e38a00;
extern char D_01e389c0[];
extern char D_01e37f00[];
extern PPair D_01e37240;
extern int D_01e389a8;
extern int D_00366164;
extern int D_00366168;
extern int D_00366170;
extern char D_00309ec0[];
extern char D_0030a3b0[];
extern void func_00308b30(int);
extern int func_0030edb0(void);
extern int func_0030ee00(void);
extern void func_003086b8(unsigned int, void *, void *);
extern int func_003092d8(void *, unsigned int, int);
extern void func_00309be8(void);
extern int func_00305640(int);
extern int func_00305660(int);
extern int func_00309d60(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry);
/* sceFsInit-style fileio client init: binds the fileio RPC server, clears the fd table, sends the
 * init request and reads the reply. The empty asm on q keeps the lui of D_01e38a00 shared between the
 * direct D.a store and q (s0/s1), which gives the original's prologue schedule. */
int func_0030a3f8(void)
{
    int s, i;
    FdEnt *p;
    int t;
    Pair *q = &D_01e38a00;
    asm("" : "+r"(q));
    func_00308b30(0);
    D_01e38a00.a = 0;
    q->b = 0;
    s = func_0030edb0();
    func_003086b8(0x80000011, D_00309ec0, D_01e389c0);
    func_003086b8(0x80000013, D_0030a3b0, q);
    if (s)
        func_0030ee00();
    while (1) {
        if (func_003092d8(D_01e38980, 0x80000001, 0) < 0)
            return -22;
        if (*(int *)(D_01e38980 + 36) != 0)
            break;
        i = 0x100000;
        while (i-- != 0)
            ;
    }
    func_00309be8();
    func_00305660(D_00366170);
    for (p = D_01e38780; p < D_01e38780 + 32; p++)
        p->busy = 0;
    func_00305640(D_00366170);
    D_01e37240.a = D_01e37f00;
    D_01e37240.b = D_01e37f00 + 1088;
    if (func_00309d60(D_01e38980, 255, 0, &D_01e37240, 8, D_01e37ec0, 8, 0, 0, 0) < 0)
        return 0xfffeffff;
    __builtin_memcpy(&D_01e389a8, (char *)((unsigned int)D_01e37ec0 | 0x20000000), 4);
    __builtin_memcpy(&t, (char *)((unsigned int)(D_01e37ec0 + 4) | 0x20000000), 4);
    D_00366168 = t == 2;
    D_00366164 = 1;
    return 0;
}
