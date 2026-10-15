/* Sony PS2 Runtime Library 3.0.0: libkernl (DMA/intc/thread lists), libpad2/libdbc helpers, libcdvd/sif rpc wrappers. ee-gcc 2.9-991111 -O2 -G0. */
typedef unsigned int u32;
extern int func_0030edb0(void);
extern void func_0030ee00(void);
extern void func_0030f6a0(int);
extern int func_0030ff08(void);
extern void func_0030fa10(int);

int func_0030f900(void)
{
    int st = func_0030edb0();
    u32 v = *(volatile u32 *)0x10001010;
    if (v & 0x80) {
        if (st) func_0030ee00();
        return 1;
    }
    func_0030f6a0((v & ~0xc00) | 0x80);
    func_0030fa10(func_0030ff08());
    if (st) func_0030ee00();
    return 0;
}

int func_002f3c28(volatile u32 *p)
{
    int st; u32 v, old, c, m;
    st = func_0030edb0();
    v = *(volatile u32 *)0x1000f520;
    if (!(v & 0x10000)) *(volatile u32 *)0x1000f590 = v | 0x10000;
    m = 0xfffffeff;
    c = *(volatile u32 *)0x1000e000;
    old = *p;
    *p = old & m;
    *(volatile u32 *)0x1000f590 = v;
    if (st) func_0030ee00();
    return old;
}

typedef struct L { int f0, f4, f8, fc, f10; struct L *next; } L;
typedef struct { char pad[0x28]; L *head; } LH;
extern LH D_01e37200;
void func_003096f8(L *a, int b)
{
    L *p;
    func_0030edb0();
    a->f0 = b; a->f4 = 0; a->f8 = 0; a->fc = 0; a->f10 = 0; a->next = 0;
    if (D_01e37200.head == 0) {
        D_01e37200.head = a;
    } else {
        p = D_01e37200.head;
        while (p->next) p = p->next;
        p->next = a;
    }
    func_0030ee00();
}

typedef struct M { char pad[0x38]; struct M *next; } M;
typedef struct { int a, b; M *head; } MH;
M *func_00309860(M *a, MH *l)
{
    M *p;
    func_0030edb0();
    p = l->head;
    if (p == a) {
        l->head = p->next;
    } else {
        while (p) {
            if (p->next == a) { p->next = a->next; break; }
            p = p->next;
        }
    }
    func_0030ee00();
    return p;
}

typedef struct { short s0; short s2; int f4; int f8; int fc; } P;
extern P *func_002f1fa8(void);
extern void func_00306100(int);
extern void func_00305320(int, int);
extern int func_00305300(int, int, int);
extern void func_00306168(int);
int func_002f33f0(int a)
{
    P *p = func_002f1fa8();
    int old = p->f8;
    if (a == 0) {
        func_00306100(2);
        func_00305320(2, p->fc);
        p->fc = 0;
        p->f8 = 0;
    } else {
        if (old) {
            func_00306100(2);
            func_00305320(2, p->fc);
        }
        p->f8 = a;
        p->fc = func_00305300(2, a, -1);
        func_00306168(2);
    }
    return old;
}

extern void func_00305ab0(void);
extern long func_00305b40(void);
int func_002f2508(int x) asm("_Z13func_002f2508i") __attribute__((section(".text._Z13func_002f2508i")));
int func_002f2508(int x)
{
    P *p = func_002f1fa8();
    long r;
    if (p->f8 == 0) {
        func_00305ab0();
        if (p->s0 != 1) return 1;
        return (*(volatile unsigned long *)0x12001000 >> 13) & 1;
    }
    r = (func_00305b40() >> 13) & 1;
    if (p->s0 != 1) return 1;
    return r;
}

extern int func_002f6fc0(int);
extern int func_002f72c0(int);
extern int func_003094b8(void *, int, int, void *, int, void *, int, void *, void *);
extern void func_00305640(int);
extern char D_00364f50[];
extern char D_00363e00[];
extern int D_00363da8;
int func_002f7118(void)
{
    int r;
    if (!func_002f6fc0(2)) return 0;
    if (func_003094b8(D_00364f50, 14, 0, 0, 0, D_00363e00, 4, 0, 0) < 0) {
        func_00305640(D_00363da8);
        return 0;
    }
    r = *(int *)((u32)D_00363e00 | 0x20000000);
    func_00305640(D_00363da8);
    return r;
}

extern char D_00365900[];
extern char D_00364f80[];
extern int D_00363dac;
int func_002f7dc8(void)
{
    int r;
    if (!func_002f72c0(3)) return -1;
    if (func_003094b8(D_00365900, 4, 0, 0, 0, D_00364f80, 4, 0, 0) < 0) {
        func_00305640(D_00363dac);
        return -1;
    }
    r = *(int *)((u32)D_00364f80 | 0x20000000);
    func_00305640(D_00363dac);
    return r;
}

typedef struct { int status; void *func; void *stack; int size; void *gp; int prio; int cur; u32 attr; void *option; } TP;
extern TP D_01e331d8;
extern int D_00363d94;
extern char D_002f67a0[];
extern char D_00376b70[];
extern int func_00305420(TP *);
extern void func_00306760(int, int);
extern void func_003054b0(int, int);
int func_002f6870(int prio, void *stack, int size)
{
    int r;
    r = 1;
    if (D_00363d94 == 0) {
        D_01e331d8.size = size;
        D_01e331d8.func = D_002f67a0;
        D_01e331d8.stack = stack;
        D_01e331d8.prio = prio;
        D_01e331d8.option = D_00376b70;
        D_01e331d8.gp = 0;
        D_00363d94 = func_00305420(&D_01e331d8);
        func_00306760(D_00363d94, 0);
    } else {
        func_003054b0(D_00363d94, prio);
        r = 0;
    }
    return r;
}

extern int func_0030a8f8(void *, int);
extern int func_0030af40(int, void *, int);
extern int func_0030ab88(int);
extern int func_002fd220(char *);
extern char D_003762c8[];
int func_002f2020(void)
{
    char buf[256];
    char *p;
    u32 i;
    int fd;
    fd = func_0030a8f8(D_003762c8, 1);
    if (fd < 0) return -1;
    for (i = 0, p = buf; i < 256; i++) {
        func_0030af40(fd, p, 1);
        if (*p++ == 0) break;
    }
    func_0030ab88(fd);
    return func_002fd220(&buf[i - 9]) > 0x1315670;
}
