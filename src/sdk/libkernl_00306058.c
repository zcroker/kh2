/* libkernl_00306058.c: Sony PS2 Runtime Library 3.0.0 libkernl: cache/interrupt helpers and the top thread, 0x306058-0x3064e4.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
extern int DIntr(void);
extern int EIntr(void);
extern void func_00305fb0(unsigned int, unsigned int);

/* ---- 0x306058 */
void func_00306058(unsigned int a, unsigned int b)
{
    int st;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st)
        DIntr();
    func_00305fb0(a & 0xffffffc0, b & 0xffffffc0);
    if (st)
        EIntr();
}

/* ---- 0x3060d8 (gap) */
void func_003060d8(unsigned int a, unsigned int b)
{
    func_00305fb0(a & 0xffffffc0, b & 0xffffffc0);
}

/* ---- 0x3060f0 */
int func_003060f0(void)
{
    int r;
    asm volatile(".set noreorder\n\tmfc0 %0, $12\n\t.set reorder" : "=r"(r));
    return (r ^ 1) & 1;
}

/* ---- 0x306100 */
extern int func_00305370(int);
int DisableIntc(int a)
{
    int st, r;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st)
        DIntr();
    r = func_00305370(a);
    asm volatile("sync");
    if (st)
        EIntr();
    return r;
}

extern int func_00305360(int);
int EnableIntc(int a)
{
    int st, r;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st)
        DIntr();
    r = func_00305360(a);
    asm volatile("sync");
    if (st)
        EIntr();
    return r;
}

extern int func_00305390(int);
int DisableDmac(int a)
{
    int st, r;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st)
        DIntr();
    r = func_00305390(a);
    asm volatile("sync");
    if (st)
        EIntr();
    return r;
}

extern int func_00305380(int);
int EnableDmac(int a)
{
    int st, r;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st)
        DIntr();
    r = func_00305380(a);
    asm volatile("sync");
    if (st)
        EIntr();
    return r;
}

/* ---- 0x3062a0 */
extern int func_003053c0(int);
int iEnableIntc(int n)
{
    int r = func_003053c0(n);
    asm volatile("sync");
    return r;
}
extern int func_003053d0(int);
int iDisableIntc(int n)
{
    int r = func_003053d0(n);
    asm volatile("sync");
    return r;
}
extern int func_003053e0(int);
int iEnableDmac(int n)
{
    int r = func_003053e0(n);
    asm volatile("sync");
    return r;
}
extern int func_003053f0(int);
int iDisableDmac(int n)
{
    int r = func_003053f0(n);
    asm volatile("sync");
    return r;
}
/* Sony PS2 Runtime Library: libkernl request-queue service thread (00306320). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { unsigned int count; int pad; unsigned char type[1]; unsigned char arg[1]; } Queue_w3754;
extern int D_01e34e80;
extern char D_00377e28[]; /* "## internel error in libkernl.a!\n" */
extern void func_00305660(int);
extern void func_003054d0(int);
extern void func_00305550(int);
extern void func_00305590(int);
extern void func_00308150(const char *);
void func_00306320(Queue_w3754 *s)
{
    unsigned char *b = s->type;
    unsigned char *a = s->arg;
    int i;
    /* partial asm: pin and empty barrier steer allocation and scheduling only */
    register int j asm("$4");
    int t;
    unsigned char *p;
    for (;;) {
        func_00305660(D_01e34e80);
        i = s->count;
        i &= 0x1ff;
        j = i + 1;
        i <<= 1;
        asm volatile("");
        s->count = j;
        p = i + b;
        t = *p;
        switch (t) {
        case 0: func_00305550(a[i]); break;
        case 1: func_003054d0(a[i]); break;
        case 2: func_00305590(a[i]); break;
        default: func_00308150(D_00377e28); break;
        }
    }
}

/* libkernl / sifrpc / libmc / libcdvd / deci2 misc (Sony PS2 Runtime Library 3.0.0) */
extern int func_0030dd70(void);

struct ThreadParam { int status; void (*entry)(void*); void *stack; int stackSize; void *gpReg; int initPriority; int currentPriority; unsigned int attr; unsigned int option; int waitType; int waitId; int wakeupCount; };
struct SemaParam { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; };
extern int func_00305420(struct ThreadParam *);
extern int func_003054b0(int, int);
extern int func_00305510(void);
extern int func_00305620(struct SemaParam *);
extern int func_00305630(int);
extern int func_00306760(int, void *);
extern void func_00306320_v(void *) asm("func_00306320");
extern int D_003660d0;
extern char D_0037a800[];
extern int D_01e34e80;
extern int D_01e34e88[2];
extern char D_01e34a80[];
int func_003063f8(void)
{
    struct ThreadParam tp;
    struct SemaParam sp;
    if (D_003660d0 > 0)
        return -1;
    sp.maxCount = 255;
    sp.initCount = 0;
    sp.option = (unsigned int)"SceKerneltopThread";
    D_01e34e80 = func_00305620(&sp);
    if (D_01e34e80 < 0)
        return -1;
    tp.entry = func_00306320_v;
    tp.stack = D_01e34a80;
    tp.stackSize = 0x400;
    tp.gpReg = D_0037a800;
    tp.option = (unsigned int)"SceKerneltopThread";
    tp.initPriority = 0;
    D_003660d0 = func_00305420(&tp);
    if (D_003660d0 < 0) {
        func_00305630(D_01e34e80);
        return -1;
    }
    D_01e34e88[0] = 0;
    D_01e34e88[1] = 0;
    func_00306760(D_003660d0, D_01e34e88);
    func_003054b0(func_00305510(), 1);
    return D_003660d0;
}

