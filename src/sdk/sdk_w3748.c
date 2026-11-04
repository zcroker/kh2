/* Sony PS2 Runtime Library: libkernl sceLseek64 (0030cf60). Third-party Sony SDK code rebuilt to match; not covered by this project's MIT License. ee-gcc 2.9-991111 -O2 -G0. */
typedef long long s64 __attribute__((mode(DI)));
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam;
typedef struct { int fd; int busy; int x8; int xc; } FdEnt;
extern FdEnt D_01e38780[];
typedef struct { int sema; int *res; int rsize; int fd; int off; int whence; int idx; } LsPk;
typedef struct { int sema; void *res; int rsize; int fd; s64 off; int whence; int idx; } Ls64Pk;
extern LsPk D_01e37280;
extern char D_01e38980[];
extern char D_01e37ec0[];
extern int D_00366164;
extern int D_00366174;
extern int D_003660e0[];
extern int func_0030a2d0(int);
extern int func_0030a300(void);
extern int func_00305620(SemaParam *);
extern int func_00305630(int);
extern int func_00305640(int);
extern int func_00305660(int);
extern FdEnt *func_00309e50(int);
extern int func_00309d60(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry);

s64 func_0030cf60(int fd, s64 off, int whence)
{
    Ls64Pk *q = (Ls64Pk *)&D_01e37280;
    SemaParam sp;
    s64 res;
    int busy, nw, i, m, s, v;
    FdEnt *e = func_00309e50(fd);
    func_0030a2d0(22);
    if (D_00366164 == 0 || e == 0 || (busy = e->busy) == 0) {
        func_0030a300();
        return -9;
    }
    q->fd = e->fd;
    q->off = off;
    q->whence = whence;
    q->idx = e - D_01e38780;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioLseek64Sema";
    s = func_00305620(&sp);
    q->res = &res;
    q->rsize = 8;
    nw = busy & 0x8000;
    D_01e37280.sema = s;
    if (nw) {
        func_00305660(D_00366174);
        /* Partial asm: empty tie, orders i = 0 before busy = nw and keeps the copy after the call. */
        { register int n asm("$16") = nw; i = 0; asm("" : "+r"(n) : "r"(i)); busy = n; }
        for (; i < 32; i++) {
            if (D_003660e0[i] == -1) {
                D_003660e0[i] = q->sema;
                q->sema = -q->sema;
                break;
            }
        }
        func_00305640(D_00366174);
    } else {
        int z = 0; do { } while (z); busy = z; /* note puts the copy after the PRE luis */
    }
    if (func_00309d60(D_01e38980, 22, 0, &D_01e37280, 32, D_01e37ec0, 4, 0, 0, busy) < 0) {
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
    if (busy) {
        func_00305630(s);
        return 0;
    }
    func_00305660(s);
    func_00305630(s);
    return res;
}
