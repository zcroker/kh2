/* Sony PS2 Runtime Library 3.0.0: libmc-style rpc client (002fc498), libdbc (sceDbcSRData), libgraph (sceGsResetGraph), libkernl (deci2 TTY handler, sceSifInitRpc, stdio rpc open/mkdir/getstat/u_call4). ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int pad0; int a; int b; int c; int d; int e; int pad18; void *buf; } Rpc;
typedef struct { char pad[0x24]; int serve; } Cd;
extern Cd D_01e33480;
extern Rpc D_01e33500;
extern char D_01e33980[];
extern char D_01e34a40[];
extern int D_01e334a8, D_01e334ac, D_01e334b0;
extern int D_0036594c;
extern int D_00365948;
extern int func_00305670(int);
extern int func_00305640(int);
extern void func_00308a80(void *, int);
extern int func_003094b8(void *, int, int, void *, int, void *, int, void *, void *);
extern char D_002fc440[];
int func_002fc498(int a0, int a1, int a2, int a3, int a4)
{
    if (D_01e33480.serve == 0)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    D_01e33500.a = a0;
    D_01e33500.b = a1;
    D_01e33500.buf = D_01e33980;
    if (a2) D_01e33500.e = 1; else D_01e33500.e = 0;
    if (a3) D_01e33500.d = 1; else D_01e33500.d = 0;
    if (a4) D_01e33500.c = 1; else D_01e33500.c = 0;
    D_01e334a8 = a2;
    D_01e334ac = a3;
    D_01e334b0 = a4;
    func_00308a80(D_01e33980, 192);
    if (func_003094b8(&D_01e33480, 1, 1, &D_01e33500, 48, D_01e34a40, 4, D_002fc440, D_01e33980) != 0) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 1;
    return 0;
}

typedef struct { int a; int b; int n1; int n2; char s[128]; char r[128]; int res; } Pk;
extern Pk D_01e2da80;
extern char D_01e2d980[];

extern int D_01e2fe40;
extern int func_00305660(int);
extern int func_00305640(int);

extern int func_002f5c48(const char *, ...);
int func_002f5558(int a, int b, int *n1, char *s, int *n2, char *r)
{
    int i;
    int res;
    Pk *p;
    func_00305660(D_01e2fe40);
    p = &D_01e2da80;
    p->a = a;
    p->b = b;
    p->n1 = *n1;
    p->n2 = *n2;
    for (i = 0; i < *n1; i++)
        p->s[i] = s[i];
    if (func_003094b8(D_01e2d980, 0x80001318, 0, &D_01e2da80, 144, &D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcSRData: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    if (p->res >= 0) {
        *n1 = p->n1;
        *n2 = p->n2;
        for (i = 0; i < p->n2; i++)
            r[i] = p->r[i];
    }
    res = p->res;
    func_00305640(D_01e2fe40);
    return res;
}

typedef struct { short inter; short omode; short ffmode; short version; int f8; int fc; } GP;
extern GP *func_002f1fa8(void);
extern void func_00305220(short, short, short);
extern int func_00305320(int, int);
extern int func_00305960(int);
extern int func_00306100(int);
#define CSR ((volatile unsigned long *)0x12001000)
void func_002f1e18(short mode, short inter, short omode, short ffmode)
{
    GP *p;
    switch (mode) {
    case 0:
        p = func_002f1fa8();
        *CSR = 0x200;
        p->inter = inter;
        p->omode = omode;
        p->version = (*CSR >> 16) & 0xff;
        func_00305960(0xff00);
        p->ffmode = ffmode != 0;
        if (p->f8) {
            func_00306100(2);
            func_00305320(2, p->fc);
            p->f8 = 0;
            p->fc = 0;
        }
        func_00305220(inter & 1, omode & 0xff, ffmode & 1);
        break;
    case 1:
        *CSR = 0x100;
        break;
    case 5:
        p = func_002f1fa8();
        p->ffmode = ffmode != 0;
        p->inter = inter;
        p->omode = omode;
        p->version = (*CSR >> 16) & 0xff;
        func_00305220(inter & 1, omode & 0xff, ffmode & 1);
        break;
    }
}

typedef struct { int size; int count; int pad8; char *wp; char buf[1]; } Ring;
typedef struct { int sock; volatile int wlen; volatile int rlen; volatile int busy; char *wbuf; char *rbuf; Ring *ring; } TI;
extern void func_00306928(Ring *r);
extern void func_00308150(const char *fmt, ...);
extern int func_00311100(int, char *, unsigned short);
extern int func_00311138(int, char *, unsigned short);
void func_003069a8(int ev, int param, TI *ti)
{
    int i;
    unsigned short *hdr;
    int n, k;
    switch (ev) {
    case 1:
    case 2:
        if (param) {
            if ((unsigned)(ti->rlen + param) > 320)
                func_00308150("TTY: packet size larger than expect\n");
            k = ti->rlen;
            i = func_00311100(ti->sock, ti->rbuf + k, param);
            if (i < 0)
                func_00308150("TTY: receive error");
            ti->rlen += i;
        } else {
            hdr = (unsigned short *)ti->rbuf;
            for (i = 12; i < *hdr; i++) {
                *ti->ring->wp = ti->rbuf[i];
                func_00306928(ti->ring);
            }
            ti->rlen = 0;
        }
        break;
    case 3:
        n = func_00311138(ti->sock, ti->wbuf, ti->wlen);
        if (n < 0) {
            func_00308150("TTY: send err %d\n", n);
            ti->busy = 0;
        } else {
            ti->wbuf += n;
            ti->wlen -= n;
        }
        break;
    case 4:
        if (ti->wlen)
            func_00308150("TTY: err ti->wlen=%08x\n", ti->wlen);
        ti->busy = 0;
        break;
    }
}


typedef struct { int pid; void *pkt; int pktlen; int u0c; int u10; void *rdata; int rdlen; void *client; int cllen; int u24; } RD;
extern RD D_01e37200;
extern char D_01e35a00[], D_01e36200[], D_01e36a00[];
extern char D_00308e30[], D_00309208[], D_00309428[], D_00308f40[];
extern int D_003660dc;
extern int func_0030edb0(void);
extern int func_0030ee00(void);
extern void func_003083d0(void);
extern int func_003086b8(int, void *, void *);
extern int func_00305a30(int);
extern int func_00305a20(int, int);
extern int func_003088b8(int, void *, int, void *, void *, int);
extern int func_00308200(int);
#define UC(p) ((void *)((unsigned int)(p) | 0x20000000))
void func_00308b30(void)
{
    int *cmd;
    func_0030edb0();
    if (D_003660dc) {
        func_0030ee00();
        return;
    }
    D_003660dc = 1;
    func_0030ee00();
    func_003083d0();
    func_0030edb0();
    D_01e37200.pkt = UC(D_01e35a00);
    D_01e37200.pktlen = 32;
    D_01e37200.u0c = 0;
    D_01e37200.u10 = 0;
    D_01e37200.rdata = UC(D_01e36200);
    D_01e37200.rdlen = 32;
    D_01e37200.client = UC(D_01e36a00);
    D_01e37200.cllen = 32;
    D_01e37200.u24 = 0;
    D_01e37200.pid = 1;
    func_003086b8(0x80000008, D_00308e30, &D_01e37200);
    func_003086b8(0x80000009, D_00309208, &D_01e37200);
    func_003086b8(0x8000000a, D_00309428, &D_01e37200);
    func_003086b8(0x8000000c, D_00308f40, &D_01e37200);
    func_0030ee00();
    if (func_00305a30(0x80000002))
        return;
    cmd = (int *)(D_01e35a00 + 64);
    cmd[3] = 1;
    func_003088b8(0x80000002, cmd, 16, 0, 0, 0);
    while (!func_00308200(0))
        ;
    func_00305a20(0x80000002, 1);
}

typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam;
typedef struct { int sema; int *res; int rsize; int pad; int mode; char name[1024]; } OpenPk;
extern OpenPk D_01e37280;
extern char D_01e38980[];
extern char D_01e37ec0[];
extern int D_00366164;
extern int func_0030a2d0(int);
extern int func_0030a300(void);
extern int func_0030a3f8(void);
extern int func_00305620(SemaParam *);
extern int func_00305630(int);
extern int func_00305660(int);
extern int func_00309d60(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry);
typedef struct { int sema; int *res; int rsize; char name[1024]; } NamePk;
typedef struct { int sema; int *res; int rsize; int mode; unsigned char name[1024]; } ModePk;
typedef struct { int sema; int *res; int rsize; int mode; char name[1024]; } ModePk2;
int func_0030cb10(const char *name, int mode)
{
    OpenPk *p = &D_01e37280;
    SemaParam sp;
    int res;
    int i, s, v;
    func_0030a2d0(19);
    if (D_00366164 == 0)
        func_0030a3f8();
    for (i = 0; i < 1024; i++)
        if ((p->name[i] = name[i]) == 0)
            break;
    if (i == 1024)
        p->name[1023] = 0;
    p->mode = mode;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioSyncSema";
    s = func_00305620(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    if (func_00309d60(D_01e38980, 19, 0, &D_01e37280, 1044, D_01e37ec0, 4, 0, 0, 0) < 0) {
        func_00305630(s);
        func_0030a300();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0 | 0x20000000);
    func_0030a300();
    if (v == 0) {
        func_00305630(s);
        return -11;
    }
    func_00305660(s);
    func_00305630(s);
    return res;
}

int u_call4_0030b9e0(const char *name, int fno) asm("_Z16u_call4_0030b9e0jjjj");
int u_call4_0030b9e0(const char *name, int fno)
{
    NamePk *p = (NamePk *)&D_01e37280;
    SemaParam sp;
    int res;
    int i, s, v;
    func_0030a2d0(fno);
    if (D_00366164 == 0)
        func_0030a3f8();
    for (i = 0; i < 1024; i++)
        if ((p->name[i] = name[i]) == 0)
            break;
    if (i == 1024) {
        p->name[1023] = 0;
        i = 1023;
    }
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioCCodeSema";
    s = func_00305620(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    if (func_00309d60(D_01e38980, fno, 0, &D_01e37280, i + 13, D_01e37ec0, 4, 0, 0, 0) < 0) {
        func_00305630(s);
        func_0030a300();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0 | 0x20000000);
    func_0030a300();
    if (v == 0) {
        func_00305630(s);
        return -11;
    }
    func_00305660(s);
    func_00305630(s);
    return res;
}

int func_0030c4e0(const unsigned char *name, int mode)
{
    ModePk *p = (ModePk *)&D_01e37280;
    SemaParam sp;
    int res;
    int i, s, v;
    func_0030a2d0(12);
    if (D_00366164 == 0)
        func_0030a3f8();
    for (i = 0; i < 1024; i++)
        if ((p->name[i] = name[i]) == 0)
            break;
    if (i == 1024) {
        p->name[1023] = 0;
        i = 1023;
    }
    p->mode = mode;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioGetstatSema";
    s = func_00305620(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    if (func_00309d60(D_01e38980, 12, 0, &D_01e37280, i + 17, D_01e37ec0, 4, 0, 0, 0) < 0) {
        func_00305630(s);
        func_0030a300();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0 | 0x20000000);
    func_0030a300();
    if (v == 0) {
        func_00305630(s);
        return -11;
    }
    func_00305660(s);
    func_00305630(s);
    return res;
}

int func_0030bbb0(const char *name, int mode)
{
    ModePk2 *p = (ModePk2 *)&D_01e37280;
    SemaParam sp;
    int res;
    int i, s, v;
    func_0030a2d0(7);
    if (D_00366164 == 0)
        func_0030a3f8();
    for (i = 0; i < 1024; i++)
        if ((p->name[i] = name[i]) == 0)
            break;
    if (i == 1024) {
        p->name[1023] = 0;
        i = 1023;
    }
    p->mode = mode;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioMkdirSema";
    s = func_00305620(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    if (func_00309d60(D_01e38980, 7, 0, &D_01e37280, i + 17, D_01e37ec0, 4, 0, 0, 0) < 0) {
        func_00305630(s);
        func_0030a300();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0 | 0x20000000);
    func_0030a300();
    if (v == 0) {
        func_00305630(s);
        return -11;
    }
    func_00305660(s);
    func_00305630(s);
    return res;
}
