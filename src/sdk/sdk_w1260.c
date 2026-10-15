/* libkernl / libmc misc (Sony PS2 Runtime Library 3.0.0) */
extern int func_00305650(int s);
extern int func_00305640(int s);
extern int func_00305630(int s);
extern int func_0030edb0(void);
extern int func_0030ee00(void);
extern void func_00308730(int);
extern void func_003080d0(void *);
extern int func_003096b8(void *);
extern void func_00306698(int);
extern int func_0030dd70(void);
extern int func_0030de70(void);
extern char* func_002ff6f0(char *d, const char *s, int n);
extern int func_003094b8(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern unsigned long func_00312db8(unsigned long a, unsigned long b);
extern int D_00363de0;
extern int D_00363de4;
extern int D_00363db4;
extern int D_00363da8;
extern int D_00363dac;
extern int D_00363db0;
extern int D_00363da0;
extern int D_00363d94;
extern int D_00363d90;
extern int D_01e331c0;
extern char D_00376c80[];
extern char D_00364f50[];

#define V_w1260(x) (*(volatile int *)&(x))

void func_002f6700(int *p)
{
    V_w1260(D_00363de0) = *p;
    V_w1260(D_00363de4) = V_w1260(D_00363de0);
    if (V_w1260(D_00363de0) == 11) {
        V_w1260(D_00363de0) = 0;
        V_w1260(D_00363db4) = 0;
        return;
    }
    func_00305650(V_w1260(D_00363da8));
    if (V_w1260(D_00363d94) != 0 && V_w1260(D_01e331c0) != 0) {
        func_00305650(V_w1260(D_00363da0));
    } else {
        V_w1260(D_00363db4) = 0;
    }
    V_w1260(D_00363de0) = 0;
}

void func_002f6ab0(void)
{
    int s;
    if (D_00363d94 != 0) {
        D_00363de0 = -1;
        __asm__ volatile("" ::: "memory");
        func_00305640(D_00363da0);
    }
    func_00305630(D_00363da8);
    func_00305630(D_00363dac);
    func_00305630(D_00363db0);
    func_00305630(D_00363da0);
    s = func_0030edb0();
    func_00308730(0x80000012);
    if (s != 0)
        func_0030ee00();
}

int func_002f71b0(int mode)
{
    if (mode == 0) {
        if (D_00363d90 > 0)
            func_003080d0(D_00376c80);
        while (D_00363db4 != 0 || func_003096b8(D_00364f50) != 0)
            func_00306698(4000);
        return 0;
    }
    if (D_00363db4 || func_003096b8(D_00364f50))
        return 1;
    return 0;
}

typedef struct { int ret; int pad; char name[252]; } Buf_w1260;
extern Buf_w1260 D_01e38c40;
extern char D_01e38e40[];

int func_0030e3d8(const char *name)
{
    if (func_0030dd70() < 0)
        return 0xffff0000;
    if (func_0030de70() != 0)
        return 0xfffefffc;
    func_002ff6f0(D_01e38c40.name, name, 252);
    D_01e38c40.name[251] = 0;
    if (func_003094b8(D_01e38e40, 9, 0, &D_01e38c40, 512, &D_01e38c40, 4, 0, 0) < 0)
        return 0xfffeffff;
    return D_01e38c40.ret;
}

typedef struct Blk_w1260 { struct Blk_w1260 *next; int x4; volatile unsigned int id; int flags; } Blk_w1260;
typedef struct { int x0, x4, x8, xc; int count; Blk_w1260 *free; int x18; unsigned int cur; } Mgr_w1260;
extern Mgr_w1260 D_00367118;
extern void func_0030fc28(Blk_w1260 *b);

int func_00310090(unsigned int id)
{
    Blk_w1260 *b = (Blk_w1260 *)((id >> 10) << 6);
    if ((int)id < 0 || (id & 0x3ff) != b->id)
        return 0x80008002;
    if (D_00367118.cur == id)
        return 0x80000010;
    if (b->flags & 2)
        func_0030fc28(b);
    b->id = 0;
    b->flags = 0;
    b->next = D_00367118.free;
    D_00367118.free = b;
    D_00367118.count--;
    return 0;
}

void func_003107e8(unsigned long clock, int *sec, int *usec)
{
    int s = func_00312db8(clock, 147456000);
    if (sec)
        *sec = s;
    if (usec)
        *usec = func_00312db8((clock - (unsigned long)(unsigned int)s * 147456000) * 1000000, 147456000);
}
