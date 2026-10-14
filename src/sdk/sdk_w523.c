/* Sony PS2 Runtime Library 3.0.0: libkernl (stdio/libc semaphores, intc helpers) and RPC-client/pad helpers (0x2f4xxx-0x2fbxxx). ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } SemaParam;
extern int func_00305620(SemaParam *p);
extern int func_00305630(int id);
extern int func_002fc378(int a, int b, int c);
extern int func_00305f18(void *a, void *b);
extern int func_003094b8(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern int func_003052d0(int n, void *h);
extern void func_00311740(void);
extern int func_0030edb0(void);
extern int func_0030ee00(void);
extern int func_00310180(int a, int b);

typedef struct { char pad[0x7c]; int x7c; } Pad;
typedef struct { char pad0[8]; int f8; int pad1; Pad *f10; char rest[820 - 20]; } PortT;
extern PortT D_01e2fe48[];

extern int D_0036616c;
extern int D_003661a0;
extern int D_003661a4;
extern int D_0036594c;
extern int D_00365950;
extern int D_00367470;
extern int D_01e2d980[];
extern int D_01e2da80[];
extern int D_01e3b300;

void func_0030a278(void)
{
    SemaParam s;
    if (D_0036616c == -1) {
        s.init_count = 1;
        s.max_count = 1;
        s.option = (unsigned int)"SceStdioFioSema";
        D_0036616c = func_00305620(&s);
    }
}

int func_002fbb50(void)
{
    if (D_0036594c >= 0) {
        func_002fc378(0, 0, 0);
        func_00305630(D_0036594c);
        D_0036594c = -1;
        func_00305630(D_00365950);
    }
    return 1;
}

Pad* func_002f6310(int port)
{
    Pad *a[2];
    Pad *p = D_01e2fe48[port].f10;
    a[0] = p;
    a[1] = p + 1;
    func_00305f18(p, (char *)p + 255);
    return a[a[0]->x7c < a[1]->x7c];
}

Pad* func_002f6378(int port)
{
    Pad *a[2];
    Pad *p = D_01e2fe48[port].f10;
    a[0] = p;
    a[1] = p + 1;
    func_00305f18(p, (char *)p + 256);
    return a[a[0]->x7c < a[1]->x7c];
}

int func_002f63e0(int port)
{
    int v = func_002f6310(port)->x7c;
    if (v == 0)
        return 0;
    if (v == D_01e2fe48[port].f8)
        return 0;
    D_01e2fe48[port].f8 = v;
    return 1;
}

int func_003101d0(int a, int b)
{
    int s = func_0030edb0();
    int r = func_00310180(a, b);
    if (s)
        func_0030ee00();
    return r;
}

typedef struct Node { struct Node *next; int x4; int (*fn)(unsigned int, int, int, int); int arg; } Node;

int func_003109e0(unsigned int a, int b, int c, Node* n)
{
    int r = n->fn(((unsigned int)n << 4) | (a & 0xfe) | 1, b, c, n->arg);
    if (r == 0) {
        asm volatile("");
        n->next = (Node *)D_01e3b300;
        D_01e3b300 = (int)n;
        n->x4 = 0;
        return -1;
    }
    return r;
}

int func_002f4d60(void)
{
    if (func_003094b8(D_01e2d980, 0x80001305, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0) < 0)
        return 0;
    return D_01e2da80[1];
}

void func_0030ee18(void)
{
    SemaParam s1, s2;
    s1.max_count = 1;
    s1.init_count = 1;
    s1.option = (unsigned int)"SceKernelLibc";
    s2.max_count = 1;
    s2.init_count = 1;
    s2.option = (unsigned int)"SceKernelLibcEh";
    D_003661a0 = func_00305620(&s1);
    D_003661a4 = func_00305620(&s2);
}

int func_00311218(int a)
{
    D_00367470 = a;
    func_003052d0(1, func_00311740);
    func_003052d0(2, func_00311740);
    func_003052d0(3, func_00311740);
    return a;
}
