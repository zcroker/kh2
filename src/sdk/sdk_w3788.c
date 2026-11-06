/* sceOpen-like fileio open (libkernl), built with ee-gcc 2.9-991111. w3788 */
typedef char *va_list;
#define va_start(v,l) (v = (va_list)__builtin_next_arg(l) - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam;
typedef struct { int fd; int mode; int x8; int xc; } FdEnt;
typedef struct { int sema; int *res; int rsize; int flags; int mode; char name[1024]; int idx; } OpenPk;
extern OpenPk D_01e37280;
extern FdEnt D_01e38780[];
extern char D_01e37ec0[];
extern char D_01e38980[];
extern int D_00366164;
extern int D_00366170;
extern int func_0030a2d0(int);
extern void func_0030a300(void);
extern int func_0030a3f8(void);
extern int func_0030a600(void);
extern FdEnt *func_00309cd8(void);
extern int func_00305620(SemaParam *);
extern int func_00305630(int);
extern int func_00305640(int);
extern int func_00305660(int);
extern int func_00309d60(void *, int, int, void *, int, void *, int, void *, void *, int);

int func_0030a8f8(const char *name, int flags, ...)
{
    OpenPk *p = &D_01e37280;
    SemaParam sp;
    va_list ap;
    int res;
    int i, s, v, idx, mode;
    FdEnt *e;
    func_0030a2d0(0);
    if (D_00366164 == 0)
        func_0030a3f8();
    if (func_0030a600()) {
        func_0030a300();
        return -0x10004;
    }
    e = func_00309cd8();
    if (e == 0) {
        func_0030a300();
        return -19;
    }
    va_start(ap, flags);
    mode = *(int *)ap;
    for (i = 0; i < 1024; i++)
        if ((p->name[i] = name[i]) == 0)
            break;
    if (i == 1024)
        p->name[1023] = 0;
    idx = e - D_01e38780;
    p->flags = flags & 0x7fffffff;
    p->mode = mode;
    sp.max_count = 1;
    p->idx = idx;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioOpenSema";
    s = func_00305620(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    if (func_00309d60(D_01e38980, 0, 0, &D_01e37280, 1048, D_01e37ec0, 4, 0, 0, 0) < 0) {
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
    if (res < 0) {
        func_00305660(D_00366170);
        e->mode = 0;
        func_00305640(D_00366170);
        return res;
    }
    v = idx;
    func_00305660(D_00366170);
    e->fd = res;
    e->mode |= flags;
    func_00305640(D_00366170);
    return v;
}
