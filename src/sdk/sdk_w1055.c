/* libkernl / libpad2 / libmc misc (Sony PS2 Runtime Library 3.0.0) */
extern int func_002f3588(int a);
extern void func_002f3490(void *p);
extern void func_002fde18(void *, int, int);
extern int func_0030edb0(void);
extern void func_0030ee00(void);
extern void func_003086b8(int n, void *fn, void *arg);
extern int func_003094b8(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern int func_00310090(int a);
extern void func_00305e70(unsigned int a, unsigned int b);
extern void func_00305fb0(unsigned int a, unsigned int b);
extern int D_00363da4;
extern int D_00363dc8;
extern void D_002f6bd0(void);
extern int D_0036617c;
extern char D_01e38a80[];
extern int D_01e38ac0[];
extern int D_01e38b00[];
extern int D_01e3b300;

typedef struct { int flags; int pad[3]; unsigned int x10; int pad2[3]; int x20; } Ch_w1055;

void func_002f3980(Ch_w1055 *c, int a, int b)
{
    int v = func_002f3588(a);
    func_002f3490(c);
    if (c->x10 != 0xffffffff)
        c->x10 = v;
    c->x20 = b;
    c->flags = (c->flags & ~0xc) | 0x101;
}

void func_002f39f8(Ch_w1055 *c, int a, int b)
{
    int v = func_002f3588(a);
    func_002f3490(c);
    if (c->x10 != 0xffffffff)
        c->x10 = v;
    c->x20 = b;
    c->flags = (c->flags & ~0xc) | 0x109;
}

void func_002f3ab8(Ch_w1055 *c, int a, int b)
{
    int v = func_002f3588(a);
    unsigned int f;
    func_002f3490(c);
    if (c->x10 != 0xffffffff)
        c->x10 = v;
    c->x20 = b;
    f = c->flags & ~0xc;
    c->flags = f;
    c->flags = (c->flags & ~1) | 0x100;
}

typedef struct { unsigned char a, b, c, d; int x4; char pad[20]; char buf[96]; int x7c; } Ent_w1055;
typedef struct { char pad[16]; Ent_w1055 *ent; char pad2[820 - 20]; } Port_w1055;
extern Port_w1055 D_01e2fe48[];

void func_002f6240(int n)
{
    int i;
    Ent_w1055 *e = D_01e2fe48[n].ent;
    for (i = 1; i >= 0; i--) {
        e->a = 0;
        e->x7c = 0;
        e->b = 0;
        e->d = 0;
        e->c = 0;
        e->x4 = 0;
        func_002fde18(e->buf, 0xff, 0x20);
        e++;
    }
}

int func_002f6c28(void)
{
    int st;
    D_00363da4 = 1;
    st = func_0030edb0();
    func_003086b8(0x80000012, D_002f6bd0, 0);
    if (st)
        func_0030ee00();
    D_00363da4 = 0;
    D_00363dc8 = 1;
    return 1;
}

int u_call4_0030d998(int a) asm("_Z16u_call4_0030d998jjjj");
int u_call4_0030d998(int a)
{
    if (D_0036617c < 0)
        return 0;
    D_01e38b00[0] = a;
    if (func_003094b8(D_01e38a80, 2, 0, D_01e38b00, 4, D_01e38ac0, 4, 0, 0) < 0)
        return -1;
    return D_01e38ac0[0];
}

typedef struct { int next; volatile int id; } Sem_w1055;

int func_00310d08(unsigned int id)
{
    Sem_w1055 *s = (Sem_w1055 *)((id >> 8) << 4);
    int r, t;
    if ((int)id < 0 || ((id ^ s->id) & 0xff))
        return 0x80008002;
    r = func_00310090(s->id);
    if (r == 0) {
        t = D_01e3b300;
        D_01e3b300 = (int)s;
        s->next = t;
        s->id = 0;
    }
    return r;
}

void func_00305f18(unsigned int a, unsigned int b)
{
    int st;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st)
        func_0030edb0();
    func_00305e70(a & 0xffffffc0, b & 0xffffffc0);
    if (st)
        func_0030ee00();
}

void func_00306058(unsigned int a, unsigned int b)
{
    int st;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st)
        func_0030edb0();
    func_00305fb0(a & 0xffffffc0, b & 0xffffffc0);
    if (st)
        func_0030ee00();
}
