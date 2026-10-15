/* Sony PS2 Runtime Library 3.0.0: libkernl (0x305xxx-0x310xxx: SIF RPC, timers, deci2/printf) and 0x2f3xxx/0x2f6xxx lib helpers. Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef unsigned int u32;
typedef char *va_list;
#define va_start(v,l) (v = (va_list)__builtin_next_arg(l) - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
extern int func_0030edb0(void);
extern int func_0030ee00(void);

extern int D_003660d0;
extern int D_01e34e80;
typedef struct { int p0; u32 idx; struct { unsigned char a, b; } q[512]; } Ring;
extern Ring D_01e34e88;
extern int func_00305650(int);
int func_00306580(u32 c)
{
    int i;
    if (c >= 128 || D_003660d0 == 0)
        return -1;
    i = D_01e34e88.idx & 0x1ff;
    D_01e34e88.idx = i + 1;
    D_01e34e88.q[i].a = 1;
    D_01e34e88.q[i].b = c;
    func_00305650(D_01e34e80);
    return c;
}

extern void func_00309be8(void);
extern int func_00305660(int);
extern int func_00305640(int);
extern int D_00366170;
typedef struct { int a; int b; int c; int d; } Ent;
extern Ent D_01e38780[];
int func_00309c58(void)
{
    int n = 0;
    Ent *p;
    func_00309be8();
    func_00305660(D_00366170);
    for (p = D_01e38780; p < D_01e38780 + 32; p++)
        if (p->b) n++;
    func_00305640(D_00366170);
    return n;
}

extern int D_0036617c;
extern int D_01e38b00;
extern char D_01e38a80[];
extern int D_01e38ac0;
extern int func_003094b8(void *, int, int, void *, int, void *, int, void *, void *);
u32 func_0030dc70(int a)
{
    if (D_0036617c < 0)
        return 0;
    D_01e38b00 = a;
    if (func_003094b8(D_01e38a80, 8, 0, &D_01e38b00, 4, &D_01e38ac0, 4, 0, 0) < 0)
        return 0xffffffff;
    return D_01e38ac0;
}
u32 func_0030dcf0(int a)
{
    if (D_0036617c < 0)
        return 0;
    D_01e38b00 = a;
    if (func_003094b8(D_01e38a80, 9, 0, &D_01e38b00, 4, &D_01e38ac0, 4, 0, 0) < 0)
        return 0xffffffff;
    return D_01e38ac0;
}

extern void func_0030f6a0(u32);
int func_0030f990(void)
{
    int s = func_0030edb0();
    u32 v = *(volatile u32 *)0x10001010;
    if (!(v & 0x80)) {
        if (s) func_0030ee00();
        return 0;
    }
    func_0030f6a0(v & 0xfffff37f);
    if (s) func_0030ee00();
    return 1;
}

extern int func_00310670(int, int, int, int);
int func_00310768(int a, int b, int c, int d)
{
    int s = func_0030edb0();
    int r = func_00310670(a, b, c, d);
    if (s) func_0030ee00();
    return r;
}

typedef struct { int flags; int p4, p8, pc; u32 x10; int p14, p18, p1c; int x20; } Fd;
extern int func_002f3588(int);
extern void func_002f3490(Fd *);
void func_002f3b38(Fd *f, int a, int b)
{
    int r = func_002f3588(a);
    func_002f3490(f);
    if (f->x10 != 0xffffffff)
        f->x10 = r;
    f->x20 = b;
    f->flags = (((f->flags & ~0xc) | 8) & ~1) | 0x100;
}

extern int D_00363dc8;
extern int D_01e331c8;
extern int D_01e331cc;
extern int D_01e331d0;
extern void func_002f6c28(void);
int func_002f6b50(int a, int b)
{
    int old, s;
    if (D_00363dc8 < 0)
        func_002f6c28();
    s = func_0030edb0();
    old = D_01e331c8;
    D_01e331d0 = b;
    D_01e331c8 = a;
    /* save the caller's $gp: C has no way to read it */
    asm volatile("sw $28,%0" : "=m"(D_01e331cc));
    if (s) func_0030ee00();
    return old;
}

extern int func_003071d0(void *, void *, u32, const char *, va_list);
extern int func_00307f40();
extern int func_00307f68();
void ctarget_003080d0(const char *fmt, ...) asm("_Z16ctarget_003080d0jjjj");
void ctarget_003080d0(const char *fmt, ...)
{
    va_list ap; int buf; int s;
    buf = 0;
    s = func_0030edb0();
    va_start(ap, fmt);
    func_003071d0(func_00307f40, &buf, 0xffffffff, fmt, ap);
    if (s) func_0030ee00();
}
void func_00308150(const char *fmt, ...)
{
    va_list ap; int buf; int s;
    buf = 0;
    s = func_0030edb0();
    va_start(ap, fmt);
    func_003071d0(func_00307f68, &buf, 0xffffffff, fmt, ap);
    if (s) func_0030ee00();
}

typedef struct { int a, b, c; } Arg3;
extern Arg3 D_01e38b00x asm("D_01e38b00");
int func_0030d918(int a, int b, int c)
{
    if (D_0036617c < 0)
        return 0;
    D_01e38b00x.a = b;
    D_01e38b00x.b = a;
    D_01e38b00x.c = c;
    if (func_003094b8(D_01e38a80, 4, 0, &D_01e38b00x, 12, &D_01e38ac0, 4, 0, 0) < 0)
        return 0;
    return D_01e38ac0;
}
