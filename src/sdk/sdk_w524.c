/* Sony PS2 Runtime Library 3.0.0: libkernl. Built with ee-gcc 2.9-991111 -O2 -G0. */
extern int func_0030edb0(void);
extern void func_0030ee00(void);
extern int func_00305370(int);
int func_00306100(int a)
{
    int st, r;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st)
        func_0030edb0();
    r = func_00305370(a);
    asm volatile("sync");
    if (st)
        func_0030ee00();
    return r;
}

extern int func_00305360(int);
int func_00306168(int a)
{
    int st, r;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st)
        func_0030edb0();
    r = func_00305360(a);
    asm volatile("sync");
    if (st)
        func_0030ee00();
    return r;
}

extern int func_00305390(int);
int func_003061d0(int a)
{
    int st, r;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st)
        func_0030edb0();
    r = func_00305390(a);
    asm volatile("sync");
    if (st)
        func_0030ee00();
    return r;
}

extern int func_00305380(int);
int func_00306238(int a)
{
    int st, r;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st)
        func_0030edb0();
    r = func_00305380(a);
    asm volatile("sync");
    if (st)
        func_0030ee00();
    return r;
}

extern int func_002f3588(int);
extern void func_002f3490(int *);
void func_002f3918(int *p, int b)
{
    int r = func_002f3588(b);
    func_002f3490(p);
    if ((unsigned int)p[12] != 0xffffffff)
        p[12] = r;
    p[8] = 0;
    p[0] = (p[0] & ~0xc) | 0x105;
}

extern void func_002f3f88(int, int);
void func_002f4480(int p, int a, int b, int c, int d)
{
    func_002f3f88(p, a);
    func_002f3f88(p + 16, b);
    func_002f3f88(p + 32, c);
    func_002f3f88(p + 48, d);
}

extern void func_003056d0(unsigned int *);
extern void func_003056c0(unsigned int *);
int func_0030f128(void)
{
    unsigned int old, v;
    func_003056d0(&old);
    v = (old & 0xffff1fff) | 0x2000;
    func_003056c0(&v);
    func_003056d0(&v);
    func_003056c0(&old);
    return ((v >> 13) & 7) == 0;
}

extern int D_00363d28;
extern int D_01e2fe48[];
extern int func_002f5e20(int);
int func_002f5cb0(void)
{
    int i, r;
    int *p = D_01e2fe48;
    D_00363d28 = 0;
    for (i = 0; i < 16; i++, p += 205) {
        if (*p) {
            r = func_002f5e20(i);
            if (r < 0)
                return r;
        }
    }
    return 1;
}

extern int func_002f71b0(int);
extern int D_01e331c0;
extern int D_01e331c4;
int func_002f6698(int a)
{
    int old, s;
    if (func_002f71b0(1) != 0)
        return 0;
    s = func_0030edb0();
    old = D_01e331c0;
    D_01e331c0 = a;
    asm volatile("sw $gp, %0" : "=m"(D_01e331c4));
    if (s)
        func_0030ee00();
    return old;
}

extern int D_00363d90;
extern int D_00376c90;
extern int D_00365900;
extern void func_003080d0(int *);
extern void func_00306698(int);
extern int func_003096b8(int *);
int func_002f7250(int a)
{
    if (a == 0) {
        if (D_00363d90 > 0)
            func_003080d0(&D_00376c90);
        while (func_003096b8(&D_00365900))
            func_00306698(4000);
        return 0;
    }
    return func_003096b8(&D_00365900);
}
