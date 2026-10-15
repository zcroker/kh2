/* Sony PS2 Runtime Library 3.0.0: libkernl (sce fileio client, mc/sif rpc helpers). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam;
typedef struct { int sema; int *res; int rsize; char name[1024]; char name2[1024]; } SymPk;
typedef struct { int sema; int *res; int rsize; int len; void *buf; char name[1024]; } RlPk;
typedef struct { int sema; int *res; int rsize; int fd; int req; char arg[1024]; void *buf; int buflen; int arglen; } IoPk;
typedef struct { int fd; int valid; } Fdd;
typedef struct { char b[252]; } B252;
typedef struct { int v; int len; char pad[252]; char data[252]; } MP;
extern MP D_01e38c40;
extern char D_01e38e40[];
extern int func_0030dd70(void);
extern int func_0030de70(void);
extern int func_003094b8(void *, int, int, void *, int, void *, int, void *, void *);

extern SymPk D_01e37280;
extern char D_01e38980[];
extern char D_01e37ec0[];
extern int D_00366164;
extern int func_0030a2d0(int);
extern int func_0030a300(void);
extern int func_0030a3f8(void);
extern int func_00305620(SemaParam *);
extern int func_00305630(int);
extern int func_00305660(int);
extern void func_00308a80(void *, int);
extern void *func_002fdd68(void *, const void *, int);
extern Fdd *func_00309e50(int);
extern int func_00309d60(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry);

int func_0030d448(const char *a, const char *b)
{
    SymPk *p = &D_01e37280;
    SemaParam sp;
    int res;
    int i, s, v;
    func_0030a2d0(17);
    if (D_00366164 == 0)
        func_0030a3f8();
    for (i = 0; i < 1024; i++)
        if ((p->name[i] = a[i]) == 0)
            break;
    if (i == 1024)
        p->name[1023] = 0;
    for (i = 0; i < 1024; i++)
        if ((p->name2[i] = b[i]) == 0)
            break;
    if (i == 1024)
        p->name2[1023] = 0;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioSymlinkSema";
    s = func_00305620(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    if (func_00309d60(D_01e38980, 24, 0, &D_01e37280, 2060, D_01e37ec0, 4, 0, 0, 0) < 0) {
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

int func_0030d640(const char *a, void *buf, unsigned int len)
{
    RlPk *p = (RlPk *)&D_01e37280;
    SemaParam sp;
    int res;
    int i, s, v;
    func_0030a2d0(17);
    if (D_00366164 == 0)
        func_0030a3f8();
    for (i = 0; i < 1024; i++)
        if ((p->name[i] = a[i]) == 0)
            break;
    if (i == 1024)
        p->name[1023] = 0;
    if (len >= 1024)
        len = 1023;
    p->buf = buf;
    p->len = len;
    func_00308a80(buf, len);
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioReadlinkSema";
    s = func_00305620(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    if (func_00309d60(D_01e38980, 25, 0, &D_01e37280, 2060, D_01e37ec0, 4, 0, 0, 0) < 0) {
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

int func_0030b7f8(int fd, int req, void *arg, unsigned int arglen, void *buf, unsigned int buflen)
{
    IoPk *p = (IoPk *)&D_01e37280;
    SemaParam sp;
    int res;
    int s, v;
    Fdd *f = func_00309e50(fd);
    func_0030a2d0(26);
    if (D_00366164 == 0)
        func_0030a3f8();
    if (f == 0 || f->valid == 0) {
        func_0030a300();
        return -9;
    }
    if (arglen > 1024 || buflen > 1024) {
        func_0030a300();
        return -22;
    }
    if (arg == 0)
        p->arglen = 0;
    else
        func_002fdd68(p->arg, arg, arglen);
    p->fd = f->fd;
    p->req = req;
    p->arglen = arglen;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioIoctl2Sema";
    s = func_00305620(&sp);
    p->buflen = buflen;
    p->res = &res;
    p->rsize = 4;
    p->buf = buf;
    p->sema = s;
    func_00308a80(&D_01e37280, 1056);
    if (func_00309d60(D_01e38980, 26, 0, &D_01e37280, 1056, D_01e37ec0, 4, 0, 0, 0) < 0) {
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

int func_0030c8e8(const char *a, const char *b)
{
    SymPk *p = &D_01e37280;
    SemaParam sp;
    int res;
    int i, s, v;
    func_0030a2d0(17);
    if (D_00366164 == 0)
        func_0030a3f8();
    for (i = 0; i < 1024; i++)
        if ((p->name[i] = a[i]) == 0)
            break;
    if (i == 1024)
        p->name[1023] = 0;
    for (i = 0; i < 1024; i++)
        if ((p->name2[i] = b[i]) == 0)
            break;
    if (i == 1024)
        p->name2[1023] = 0;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioRenameSema";
    s = func_00305620(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    func_00308a80(&D_01e37280, 2060);
    if (func_00309d60(D_01e38980, 17, 0, &D_01e37280, 2060, D_01e37ec0, 4, 0, 0, 0) < 0) {
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


int u_call4_0030df38(int a, int len, void *data, int *out) asm("_Z16u_call4_0030df38jjjj");
int u_call4_0030df38(int a, int len, void *data, int *out)
{
    if (func_0030dd70() < 0) return 0xffff0000;
    if (func_0030de70()) return 0xfffefffc;
    D_01e38c40.v = a;
    if (data) {
        if (len > 252) {
            *(B252 *)D_01e38c40.data = *(B252 *)data;
            D_01e38c40.len = 252;
        } else {
            func_002fdd68(D_01e38c40.data, data, len);
            D_01e38c40.len = len;
        }
    } else
        D_01e38c40.len = 0;
    if (func_003094b8(D_01e38e40, 6, 0, &D_01e38c40, 512, &D_01e38c40, 8, 0, 0) < 0) return 0xfffeffff;
    {
        int r = D_01e38c40.v;
        *out = D_01e38c40.len;
        return r;
    }
}
int func_0030e140(int a, int len, void *data, int *out)
{
    if (func_0030dd70() < 0) return 0xffff0000;
    if (func_0030de70()) return 0xfffefffc;
    D_01e38c40.v = a;
    if (data) {
        if (len > 252) {
            *(B252 *)D_01e38c40.data = *(B252 *)data;
            D_01e38c40.len = 252;
        } else {
            func_002fdd68(D_01e38c40.data, data, len);
            D_01e38c40.len = len;
        }
    } else
        D_01e38c40.len = 0;
    if (func_003094b8(D_01e38e40, 7, 0, &D_01e38c40, 512, &D_01e38c40, 8, 0, 0) < 0) return 0xfffeffff;
    {
        int r = D_01e38c40.v;
        *out = D_01e38c40.len;
        return r;
    }
}

typedef struct { unsigned int w[16]; } Stat64;
typedef struct { int sema; int *res; int rsize; int cbit; Stat64 st; unsigned char name[1024]; } ChPk;
int func_0030c698(const unsigned char *name, Stat64 *st, int cbit)
{
    ChPk *p = (ChPk *)&D_01e37280;
    SemaParam sp;
    int res;
    int i, s, v;
    func_0030a2d0(13);
    if (D_00366164 == 0)
        func_0030a3f8();
    for (i = 0; i < 1024; i++)
        if ((p->name[i] = name[i]) == 0)
            break;
    if (i == 1024) {
        p->name[1023] = 0;
        i = 1023;
    }
    p->st = *st;
    p->cbit = cbit;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioChstatSema";
    s = func_00305620(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    func_00308a80(&D_01e37280, 1104);
    if (func_00309d60(D_01e38980, 13, 0, &D_01e37280, i + 81, D_01e37ec0, 4, 0, 0, 0) < 0) {
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

extern char *func_002ff6f0(char *, const char *, int);
int func_0030e548(const char *name, int len, void *data, int *out, int fno)
{
    if (func_0030dd70() < 0) return 0xffff0000;
    if (func_0030de70()) return 0xfffefffc;
    func_002ff6f0(D_01e38c40.pad, name, 252);
    D_01e38c40.pad[251] = 0;
    if (data) {
        if (len > 252) {
            *(B252 *)D_01e38c40.data = *(B252 *)data;
            D_01e38c40.v = 252;
        } else {
            func_002fdd68(D_01e38c40.data, data, len);
            D_01e38c40.v = len;
        }
    } else {
        D_01e38c40.data[0] = 0;
        D_01e38c40.v = 0;
    }
    if (func_003094b8(D_01e38e40, fno, 0, &D_01e38c40, 512, &D_01e38c40, 8, 0, 0) < 0) return 0xfffeffff;
    {
        int r = D_01e38c40.v;
        *out = D_01e38c40.len;
        return r;
    }
}

/* libkernl printf helper: %e-style double output (soft-float helpers called directly) */
extern int func_003142e0(double, double);
extern double func_00313ed8(double, double);
extern double func_00313f40(double, double);
extern double func_00314190(double, double);
extern int func_00311bb8(double);
extern int func_00306f68(int);
extern int func_00307f90(void *a, void *b, int *n, const char *fmt, ...);
int func_00306ff8(int (*out)(void *, int *, int), void *arg, int *n, double d)
{
    int len = 0;
    int e = 0;
    int x;
    if (*n == 0)
        return 0;
    if (func_003142e0(d, 0.0) < 0) {
        d = func_00313ed8(0.0, d);
        len = 1;
        out(arg, n, '-');
        (*n)--;
    }
    if (func_003142e0(d, 0.1) < 0) {
        while (func_003142e0(d, 0.1) < 0) {
            d = func_00313f40(d, 10.0);
            e--;
        }
    } else if (func_003142e0(d, 1.0) >= 0) {
        while (func_003142e0(d, 1.0) >= 0) {
            d = func_00314190(d, 10.0);
            e++;
        }
    }
    x = func_00306f68(func_00311bb8(func_00313f40(d, 1000000.0)));
    len += func_00307f90(out, arg, n, "0.%d", x);
    if (e >= 0)
        len += func_00307f90(out, arg, n, "e+%d", e);
    else
        len += func_00307f90(out, arg, n, "e%d", e);
    return len;
}
