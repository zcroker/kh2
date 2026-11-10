/* sceIoctl (libkernl fileio), built with ee-gcc 2.9-991111. w3790 */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam;
typedef struct { int fd; int mode; int x8; int xc; } FdEnt;
typedef struct { char b[1024]; } B1024;
typedef struct { int sema; int *res; int rsize; int fd; int req; B1024 arg; int x414; int x418; int arglen; } IoctlPk;
typedef struct { char b[1088]; } B1088;
extern IoctlPk D_01e37280;
extern void *D_01e37248;
extern B1088 D_01e37f10[];
extern int D_00366160;
extern char D_01e37ec0[];
extern char D_01e38980[];
extern int D_00366164;
extern int D_00366174;
extern int D_003660e0[32];
extern FdEnt *func_00309e50(int);
extern int func_0030a2d0(int);
extern void func_0030a300(void);
extern int func_0030a3f8(void);
extern int func_00305620(SemaParam *);
extern int func_00305630(int);
extern int func_00305640(int);
extern int func_00305660(int);
extern void func_00308a80(void *, int);
extern int func_00309d60(void *, int, int, void *, int, void *, int, void *, void *, int);

int sceIoctl(int fd, int req, void *arg)
{
    IoctlPk *p = &D_01e37280;
    SemaParam sp;
    int res;
    int i, s, v;
    int ret = 1;
    FdEnt *e = func_00309e50(fd);
    func_0030a2d0(5);
    D_01e37248 = arg;
    if (D_00366164 == 0)
        func_0030a3f8();
    if (e == 0 || e->mode == 0) {
        func_0030a300();
        return -9;
    }
    p->x414 = 0;
    p->x418 = 0;
    switch (req) {
    case 1:
        func_00305660(D_00366174);
        { int *t = D_003660e0; asm("" : "+r"(t)); i = 0; asm volatile(""); } /* Partial asm: tie + barrier keep i = 0 before the first load, out of the bne delay slot. */
        for (; i < 32; i++)
            if (D_003660e0[i] != -1)
                break;
        if (i == 32)
            *(int *)D_01e37248 = 0;
        else
            *(int *)D_01e37248 = 1;
        func_00305640(D_00366174);
        func_0030a300();
        return 0;
    case 2:
        *(int *)arg = *(int *)((unsigned int)&D_01e37f10[D_00366160] | 0x20000000);
        func_0030a300();
        return 0;
    case 3:
        *(long *)arg = *(long *)((unsigned int)&D_01e37f10[D_00366160] | 0x20000000);
        func_0030a300();
        return 0;
    }
    p->fd = e->fd;
    p->req = req;
    if (arg == 0)
        p->arglen = 0;
    else {
        p->arglen = 1024;
        p->arg = *(B1024 *)arg;
    }
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioIoctlSema";
    s = func_00305620(&sp);
    p->sema = s;
    p->res = &res;
    p->rsize = 4;
    func_00308a80(&D_01e37280, 1056);
    if (func_00309d60(D_01e38980, 5, 0, &D_01e37280, 1056, D_01e37ec0, 4, 0, 0, 0) < 0) {
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
    ret = res;
    return ret;
}



