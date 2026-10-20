/* Sony PS2 Runtime Library 3.0.0: libkernl (sce stdio/fileio rpc client: sceFormat, sceMount, sceDevctl). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam;
typedef struct { int sema; int *res; int rsize; char name[1024]; char name2[1024]; char arg[1024]; int arglen; } DevPk;
typedef struct { int sema; int *res; int rsize; char name[1024]; char name2[1024]; char arg[1024]; int flag; int arglen; } MntPk;
typedef struct { int sema; int *res; int rsize; char name[1024]; char arg[1024]; int cmd; unsigned int arglen; void *buf; unsigned int buflen; } DctlPk;
typedef union { DevPk dev; MntPk mnt; DctlPk dctl; } StdioPk;
extern StdioPk D_01e37280;
extern char D_01e37ec0[];
extern char D_01e38980[];
extern int D_00366164;
extern int func_0030a2d0(int);
extern void func_0030a300(void);
extern int func_0030a3f8(void);
extern int func_00305620(SemaParam *);
extern int func_00305630(int);
extern int func_00305660(int);
extern void func_00308a80(void *, int);
extern int func_00309d60(void *, int, int, void *, int, void *, int, void *, void *, int);

int func_0030bd88(const char *name, const char *name2, const char *arg, int arglen)
{
    DevPk *p = &D_01e37280.dev;
    SemaParam sp;
    int res;
    int i, s, v;
    func_0030a2d0(14);
    if (D_00366164 == 0)
        func_0030a3f8();
    for (i = 0; i < 1024; i++)
        if ((p->name[i] = name[i]) == 0)
            break;
    if (i == 1024)
        p->name[1023] = 0;
    if (name2 == 0)
        p->name2[0] = 0;
    else {
        for (i = 0; i < 1024; i++)
            if ((p->name2[i] = name2[i]) == 0)
                break;
        if (i == 1024)
            p->name2[1023] = 0;
    }
    if (arglen > 1024) {
        func_0030a300();
        return -7;
    }
    for (i = 0; i < arglen; i++)
        p->arg[i] = arg[i];
    p->arglen = arglen;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioFormatSema";
    s = func_00305620(&sp);
    p->sema = s;
    p->res = &res;
    p->rsize = 4;
    func_00308a80(&D_01e37280.dev, 3088);
    if (func_00309d60(D_01e38980, 14, 0, &D_01e37280.dev, 3088, D_01e37ec0, 4, 0, 0, 0) < 0) {
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

int func_0030ccc0(const char *name, const char *name2, int flag, const char *arg, int arglen)
{
    MntPk *p = &D_01e37280.mnt;
    SemaParam sp;
    int res;
    int i, s, v;
    func_0030a2d0(20);
    if (D_00366164 == 0)
        func_0030a3f8();
    for (i = 0; i < 1024; i++)
        if ((p->name[i] = name[i]) == 0)
            break;
    if (i == 1024)
        p->name[1023] = 0;
    for (i = 0; i < 1024; i++)
        if ((p->name2[i] = name2[i]) == 0)
            break;
    if (i == 1024)
        p->name2[1023] = 0;
    if (arglen > 1024) {
        func_0030a300();
        return -7;
    }
    for (i = 0; i < arglen; i++)
        p->arg[i] = arg[i];
    p->arglen = arglen;
    p->flag = flag;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioMountSema";
    s = func_00305620(&sp);
    p->sema = s;
    p->res = &res;
    p->rsize = 4;
    func_00308a80(&D_01e37280.mnt, 3092);
    if (func_00309d60(D_01e38980, 20, 0, &D_01e37280.mnt, 3092, D_01e37ec0, 4, 0, 0, 0) < 0) {
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

int func_0030d1a0(const char *name, int cmd, void *arg, unsigned int arglen, void *buf, unsigned int buflen)
{
    DctlPk *p = &D_01e37280.dctl;
    SemaParam sp;
    int res;
    int i, s, v, fno;
    unsigned int j;
    func_0030a2d0(23);
    if (D_00366164 == 0)
        func_0030a3f8();
    for (i = 0; i < 1024; i++)
        if ((p->name[i] = name[i]) == 0)
            break;
    if (i == 1024)
        p->name[1023] = 0;
    if (arglen > 1024 || buflen > 1024) {
        func_0030a300();
        return -22;
    }
    if (cmd == 0x4601) {
        if (((int *)arg)[1] == 0) {
            func_0030a300();
            return 0;
        }
        if (((int *)arg)[3] == 0) {
            func_0030a300();
            return -22;
        }
    }
    for (j = 0; j < arglen; j++)
        p->arg[j] = ((char *)arg)[j];
    p->arglen = arglen;
    p->cmd = cmd;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioDevctlSema";
    s = func_00305620(&sp);
    p->buflen = buflen;
    p->res = &res;
    p->rsize = 4;
    p->buf = buf;
    p->sema = s;
    if (cmd == 0x4601) {
        fno = 28;
        func_00308a80(((void **)arg)[2], ((int *)arg)[1] * ((int *)arg)[3]);
    } else
        fno = 23;
    func_00308a80(&D_01e37280.dctl, 2076);
    if (func_00309d60(D_01e38980, fno, 0, &D_01e37280.dctl, 2076, D_01e37ec0, 4, 0, 0, 0) < 0) {
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
