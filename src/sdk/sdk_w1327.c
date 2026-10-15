/* Sony PS2 Runtime Library 3.0.0: libkernl (alarm/counters, DelayThread, sifcmd), libmc rpc wrappers, libpad. ee-gcc 2.9-991111 -O2 -G0. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct { int x0, x4; volatile unsigned int id; unsigned int flags; long start; long total; } Ctr;
typedef struct { int x0, x4, x8, xc; int count; Ctr *free; int x18; volatile unsigned int cur; } Mgr;
extern Mgr D_00367118;
extern long func_0030ff08(void);
extern void func_0030fc28(Ctr *c);
extern void func_0030fa10(long);

int func_00310330(unsigned int id)
{
    Ctr *c = (Ctr *)((id >> 10) << 6);
    long now;
    unsigned int f;
    if ((int)id < 0 || (id & 0x3ff) != c->id)
        return 0x80008002;
    if (D_00367118.cur == id)
        return 0x80000010;
    if (!(c->flags & 1))
        return 0;
    now = func_0030ff08();
    f = c->flags;
    c->total += now - c->start;
    c->flags = f & ~1;
    if (f & 2) {
        func_0030fc28(c);
        func_0030fa10(now);
    }
    return 1;
}

extern int func_0030edb0(void);
extern void func_0030ee00(void);

long func_00310448(unsigned int id, long val)
{
    Ctr *c = (Ctr *)((id >> 10) << 6);
    int st = func_0030edb0();
    long old, now;
    if ((int)id < 0 || (id & 0x3ff) != c->id || D_00367118.cur == id) {
        if (st)
            func_0030ee00();
        return -1;
    }
    old = c->total;
    if (c->flags & 1) {
        now = func_0030ff08();
        old += now - c->start;
        c->start = now;
        c->total = val;
    } else
        c->total = val;
    if (st)
        func_0030ee00();
    return old;
}

typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam;
extern int func_00305620(SemaParam *);
extern int func_00305630(int);
extern int func_00305660(int);
extern long func_00310890(int, int);
extern int func_00310a40(long, void *, int);
extern void func_003068d8(void);

int func_00306698(int usec) asm("_Z13func_00306698i") __attribute__((section(".text._Z13func_00306698i")));
int func_00306698(int usec)
{
    SemaParam p;
    int st, s, r;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    if (!(st & 0x10000))
        return 0x80008008;
    p.max_count = 1;
    p.option = (unsigned int)"SceKernelDelayThread";
    p.init_count = 0;
    s = func_00305620(&p);
    if (s < 0)
        return 0x80008003;
    r = func_00310a40(func_00310890(0, usec), func_003068d8, s);
    if (r < 0) {
        func_00305630(s);
        return r;
    }
    func_00305660(s);
    func_00305630(s);
    return 0;
}

typedef struct { u32 a, v; } AV;
extern AV D_003674c0[];
extern int D_00367140;
extern u32 D_003674b8;
extern void func_00311358(u32, u32);
extern u32 func_00311348(u32);
extern void func_00311300(u32, void *, int);
extern void func_003058a0(int);

void func_00311368(void)
{
    u32 i;
    func_00311358(D_003674c0[0].a, D_003674c0[0].v);
    func_00311300(0x80075000, &D_00367140, 0x330);
    func_003058a0(0);
    func_003058a0(2);
    func_00311358(D_003674c0[1].a, D_003674c0[1].v);
    func_00311358(D_003674c0[2].a, D_003674c0[2].v);
    for (i = 3; i < 8; i++)
        func_00311358(D_003674c0[i].a, func_00311348(D_003674c0[i].a));
    D_003674b8 = func_00311348(3);
}

typedef struct { int x[9]; void *server; int pad[6]; } RpcCD;
typedef struct { int x0, a, b; int pad[9]; } McArg;
extern RpcCD D_01e33480;
extern McArg D_01e33500;
extern char D_01e34a40[];
extern int D_0036594c;
extern int D_00365948;
extern int func_00305670(int);
extern int func_00305640(int);
extern int func_003094b8(void *, int, int, void *, int, void *, int, void (*)(void *), void *);
extern void func_002fbba8(void *);

int func_002fc9a8(int a, int b)
{
    if (D_01e33480.server == 0)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    D_01e33500.a = a;
    D_01e33500.b = b;
    if (func_003094b8(&D_01e33480, 16, 1, &D_01e33500, 48, D_01e34a40, 4, func_002fbba8, 0) != 0) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 16;
    return 0;
}

int func_002fcf80(int a, int b)
{
    if (D_01e33480.server == 0)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    D_01e33500.a = a;
    D_01e33500.b = b;
    if (func_003094b8(&D_01e33480, 17, 1, &D_01e33500, 48, D_01e34a40, 4, func_002fbba8, 0) != 0) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 17;
    return 0;
}

extern void *func_002fdd68(void *, const void *, int);
typedef struct { u8 b0, b1, off, len; int x4; int pad[5]; u8 data[1]; } Pkt;
typedef struct { int x0, x4, x8, xc, x10; u8 rest[800]; } Port;
extern Port D_01e2fe48[];
extern void func_002f6020(int);
extern int func_002f62b8(int);
extern Pkt *func_002f6378(int);
extern void func_002f6440(u8 *, void *);

int func_002f5f50(int port, void *buf)
{
    Pkt *p;
    int n;
    func_002f6020(port);
    if (D_01e2fe48[port].x4 == 0) {
        if (func_002f62b8(port) < 0)
            return -1;
    }
    p = func_002f6378(port);
    n = p->len;
    if (n && p->data) {
        func_002fdd68(buf, (u8 *)(p->off + (int)p) + 28, n);
        func_002f6440(p->data + p->off, &D_01e2fe48[port].x10 + 1);
    }
    if (p->x4 == 0)
        return -1;
    return p->len;
}

typedef struct { int x0, x4, x8, xc, x10, x14, x18, x1c, x20, x24, x28; } Pk;
extern Pk *func_00308dc0(int);
extern Pk *func_00309178(int, int);
extern int func_003088f8(unsigned int, Pk *, int, int, int, int);
extern int func_00310b70(int, void (*)(void), Pk *);
extern void func_003091c8(void);

void func_00309208(Pk *r, int a)
{
    Pk *p = func_00308dc0(a);
    Pk *q;
    int t14 = r->x14, t1c = r->x1c;
    p->x1c = t1c;
    p->x14 = t14;
    p->x20 = 0x80000009;
    q = func_00309178(r->x20, a);
    if (q == 0) {
        p->x24 = 0;
        p->x28 = 0;
    } else {
        p->x24 = (int)q;
        p->x28 = q->x8;
    }
    if (func_003088f8(0x80000008, p, 64, 0, 0, 0) == 0)
        func_00310b70(2048, func_003091c8, p);
}
