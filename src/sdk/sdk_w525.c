/* Sony PS2 Runtime Library 3.0.0: libkernl (timers, stdio sema, sif cmd), libdma, libmc, libcdvd-ish RPC wrappers. */
typedef struct { int p0, p4; int id; int flags; long start; long acc; } Tm;
extern long func_0030ff08(void);
long func_003105b0(int id)
{
    Tm *t = (Tm *)(((unsigned int)id >> 10) << 6);
    long r;
    if (id < 0 || (id & 0x3ff) != t->id)
        return -1;
    r = t->acc;
    if (t->flags & 1)
        r += func_0030ff08() - t->start;
    return r;
}

extern int func_003080d0(const char *, ...);
extern void func_002f3c28(volatile int *);
void func_002f3490(volatile int *d)
{
    int i = 0x1000000;
    while (*d & 0x100) {
        if (--i < 0) {
            func_003080d0("libdma: sync timeout\n");
            func_002f3c28(d);
        }
    }
}

extern char D_01e33480[], D_01e33500[];
extern int D_01e34a40;
extern void func_002fbba8(void *);
extern int func_003094b8(void *, int, int, void *, int, void *, int, void *, void *);
int func_002fc618(void)
{
    if (func_003094b8(D_01e33480, 0x35, 0, D_01e33500, 0x30, &D_01e34a40, 4, func_002fbba8, 0) != 0) {
        func_003080d0("sceMcUdCheckNewCard RPC faild\n");
        return -91;
    }
    return D_01e34a40;
}

typedef struct { int x; int pad[3]; } Arg;
extern int func_0030edb0(void);
extern void func_0030ee00(void);
extern void func_00307f40(void);
extern int func_003071d0(void (*)(void), void *, unsigned int, int, int);
void func_00308060(int a, int b)
{
    Arg s;
    int st;
    s.x = 0;
    st = func_0030edb0();
    func_003071d0(func_00307f40, &s, 0xffffffff, a, b);
    if (st)
        func_0030ee00();
}

typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr, option; } SemaParam;
extern int func_00305620(SemaParam *);
extern int D_00366170, D_00366174;
void func_00309be8(void)
{
    SemaParam p;
    if (D_00366170 == -1) {
        p.init_count = 1;
        p.max_count = 1;
        p.option = (unsigned int)"SceStdioIobSema";
        D_00366170 = func_00305620(&p);
        p.option = (unsigned int)"SceStdioQueSema";
        D_00366174 = func_00305620(&p);
    }
}

extern int D_0036617c;
extern char D_01e38a80[];
extern int D_01e38ac0, D_01e38b00;
int func_0030d8a8(int a)
{
    if (D_0036617c < 0)
        return 0;
    D_01e38b00 = a;
    if (func_003094b8(D_01e38a80, 1, 0, &D_01e38b00, 4, &D_01e38ac0, 4, 0, 0) < 0)
        return 0;
    return D_01e38ac0;
}

unsigned int func_0030db20(void)
{
    if (D_0036617c < 0)
        return 0;
    if (func_003094b8(D_01e38a80, 5, 0, 0, 0, &D_01e38ac0, 4, 0, 0) < 0)
        return 0xffffffff;
    return D_01e38ac0;
}

unsigned int func_0030db90(void)
{
    if (D_0036617c < 0)
        return 0;
    if (func_003094b8(D_01e38a80, 6, 0, 0, 0, &D_01e38ac0, 4, 0, 0) < 0)
        return 0xffffffff;
    return D_01e38ac0;
}

unsigned int func_0030dc00(void)
{
    if (D_0036617c < 0)
        return 0;
    if (func_003094b8(D_01e38a80, 7, 0, 0, 0, &D_01e38ac0, 4, 0, 0) < 0)
        return 0xffffffff;
    return D_01e38ac0;
}

extern unsigned long func_00312db8(unsigned long, unsigned long);
unsigned long func_00310890(unsigned int s, unsigned int u)
{
    unsigned long x = (unsigned long)s * 147456000;
    return x + func_00312db8((unsigned long)u * 147456000, 1000000);
}
