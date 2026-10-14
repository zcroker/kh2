/* Sony PS2 Runtime Library 3.0.0: libkernl (sprintf family, kernel-table helpers; 0x2f3a70 is from the 0x2f3xxx lib block). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef char *va_list;
/* gcc 2.9 EABI va-mips.h va_start: register save area starts below the incoming args */
#define va_start(v,l) (v = (va_list)__builtin_next_arg(l) - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))

typedef struct { int f0; int f4, f8, fc, f10, f14, f18, f1c, f20; } Q;
extern void func_002f3490(Q *);
void func_002f3a70(Q *q)
{
    func_002f3490(q);
    q->f20 = 0;
    q->f0 = (((q->f0 & ~0xc) | 4) & ~1) | 0x100;
}

extern int D_01e3b508;
extern int func_00305a50(int, void *);
int func_00310fe0(unsigned int a, int b, int c)
{
    int s[4];
    s[0] = a & 0xffff; s[1] = b; s[2] = c;
    s[3] = (int)&D_01e3b508 | 0x20000000;
    return func_00305a50(1, s);
}

extern int func_003071d0(void *, void *, int, const char *, va_list);
extern int func_00307ee8();
int func_00308018(char *buf, int n, const char *fmt, ...)
{
    va_list ap; int r;
    va_start(ap, fmt);
    r = func_003071d0(func_00307ee8, &buf, n, fmt, ap);
    return r;
}

int func_00307f90(void *a, void *b, int *n, const char *fmt, ...)
{
    va_list ap; int r;
    va_start(ap, fmt);
    r = func_003071d0(a, b, *n, fmt, ap);
    *n -= r;
    return r;
}

extern int func_0030edb0(void);
extern int func_0030ffd8(void);
extern void func_0030ee00(void);
int func_00310048(void)
{
    int s = func_0030edb0();
    int r = func_0030ffd8();
    if (s) func_0030ee00();
    return r;
}

typedef struct { int f0, f4, f8, fc; long f10, f18; } T;
long func_00310518(int id)
{
    T *t = (T *)(((unsigned)id >> 10) << 6);
    if (id < 0 || (id & 0x3ff) != t->f8) return -1;
    if (t->fc & 1) return t->f10 - t->f18;
    return 0;
}

typedef struct { int a, b, c; } E;
extern E *D_01e357e4;
extern E *D_01e357ec;
void func_00308730(int x)
{
    if (x < 0) D_01e357e4[x & 0x7fffffff].a = 0;
    else D_01e357ec[x].a = 0;
}

typedef struct N { int k; char pad[0x34]; struct N *next; } Nd;
typedef struct L { int p0, p4; Nd *head; int pc, p10; struct L *next; char pad[0x10]; struct L *sub; } Ls;
Nd* func_00309178(int k, Ls *l)
{
    Nd *n;
    for (l = l->sub; l; l = l->next)
        for (n = l->head; n; n = n->next)
            if (n->k == k) return n;
    return 0;
}
