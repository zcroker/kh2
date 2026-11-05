/* Sony PS2 Runtime Library: libkernl sceRead (0030af40) and sceWrite (0030b1b0). Third-party Sony SDK code rebuilt to match; not covered by this project's MIT License. ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam;
typedef struct { int fd; int mode; int x8; int xc; } FdEnt;
typedef struct { int sema; int *res; int rsize; int fd; void *buf; int len; int x18; int idx; } RwPk;
typedef struct { int sema; int *res; int rsize; int fd; void *buf; int len; int n; char data[16]; int idx; } WrPk;
extern FdEnt D_01e38780[];
extern RwPk D_01e37280;
extern WrPk D_01e37280_w asm("D_01e37280");
extern char D_01e37ec0[];
extern char D_01e38980[];
extern int D_00366164;
extern int D_00366174;
extern int D_003660e0[32];
extern FdEnt *func_00309e50(int);
extern int func_0030a2d0(int);
extern void func_0030a300(void);
extern int func_00305620(SemaParam *);
extern int func_00305630(int);
extern int func_00305640(int);
extern int func_00305660(int);
extern void func_00308a80(void *, int);
extern int func_00309d60(void *, int, int, void *, int, void *, int, void *, void *, int);

int func_0030af40(int fd, void *buf, int len)
{
    SemaParam sp;
    int res;
    int nr;
    register int sema asm("$19");
    int nw;
    int mode;
    int r;
    int i;
    RwPk *q = &D_01e37280;
    FdEnt *e = func_00309e50(fd);
    func_0030a2d0(2);
    if (D_00366164 == 0 || e == 0 || (mode = e->mode) == 0) {
        func_0030a300();
        return -9;
    }
    q->fd = e->fd;
    q->idx = e - D_01e38780;
    sp.max_count = 1;
    sp.option = (unsigned int)"SceStdioReadSema";
    nw = mode & 0x8000;
    q->buf = buf;
    q->len = len;
    sp.init_count = 0;
    sema = func_00305620(&sp);
    q->res = &res;
    q->rsize = 4;
    D_01e37280.sema = sema;
    if (nw) {
        func_00305660(D_00366174);
        asm volatile("");
        { int *t = D_003660e0; asm("" : "+r"(t)); i = 0; asm volatile(""); nr = nw; } /* Partial asm: pins, tie and barrier order i = 0 before the copy after the call. */
        for (; i < 32; i++) {
            if (D_003660e0[i] == -1) {
                D_003660e0[i] = q->sema;
                q->sema = -q->sema;
                break;
            }
        }
        func_00305640(D_00366174);
    } else
        { int z = 0; do { } while (z); nr = z; } /* note puts the copy after the PRE lui */
    if (!(mode & 0x20000000))
        func_00308a80(buf, len);
    func_00308a80(q, 32);
    if (func_00309d60(D_01e38980, 2, 0, &D_01e37280, 32, D_01e37ec0, 4, 0, 0, nr) < 0) {
        func_00305630(sema);
        func_0030a300();
        return -11;
    }
    r = *(int *)((unsigned int)D_01e37ec0 | 0x20000000);
    func_0030a300();
    if (r == 0) {
        func_00305630(sema);
        return -11;
    }
    if (nr) {
        func_00305630(sema);
        return 0;
    }
    func_00305660(sema);
    func_00305630(sema);
    return res;
}

int func_0030b1b0(int fd, void *buf, int len)
{
    SemaParam sp;
    int res;
    int sema;
    int r;
    register int nw asm("$16");
    register int nr asm("$20");
    int mode;
    int i, j, n;
    char *u;
    WrPk *q = &D_01e37280_w;
    FdEnt *e = func_00309e50(fd);
    func_0030a2d0(3);
    if (D_00366164 == 0 || e == 0 || (mode = e->mode) == 0) {
        func_0030a300();
        return -9;
    }
    q->fd = e->fd;
    q->idx = e - D_01e38780;
    sp.max_count = 1;
    sp.option = (unsigned int)"SceStdioWriteSema";
    nw = mode & 0x8000;
    q->len = len;
    q->buf = buf;
    sp.init_count = 0;
    sema = func_00305620(&sp);
    q->res = &res;
    q->rsize = 4;
    D_01e37280_w.sema = sema;
    if (nw) {
        func_00305660(D_00366174);
        asm volatile("");
        { int *t = D_003660e0; asm("" : "+r"(t)); i = 0; asm volatile(""); nr = nw; } /* Partial asm: see func_0030af40. */
        for (; i < 32; i++) {
            if (D_003660e0[i] == -1) {
                D_003660e0[i] = q->sema;
                q->sema = -q->sema;
                break;
            }
        }
        func_00305640(D_00366174);
    } else
        { unsigned int t = (unsigned int)buf & 0xf; register int z asm("$0"); asm("" :: "r"(t)); nr = z; } /* Partial asm: empty use keeps the andi before the copy; PRE reuses it. */
    if (((unsigned int)buf & 0xf) == 0)
        n = 0;
    else
        n = (unsigned int)buf / 16 * 16 + 16 - (unsigned int)buf;
    if (len < n)
        n = len;
    if (!(mode & 0x20000000))
        func_00308a80(buf, len);
    buf = (void *)((unsigned int)buf | 0x20000000);
    q->n = n;
    for (j = 0; j < n; j++)
        q->data[j] = ((char *)buf)[j];
    if (func_00309d60(D_01e38980, 3, 0, &D_01e37280_w, 48, D_01e37ec0, 4, 0, 0, nr) < 0) {
        func_00305630(sema);
        func_0030a300();
        return -11;
    }
    r = *(int *)((unsigned int)D_01e37ec0 | 0x20000000);
    func_0030a300();
    if (r == 0) {
        func_00305630(sema);
        return -11;
    }
    if (nr) {
        func_00305630(sema);
        return 0;
    }
    func_00305660(sema);
    func_00305630(sema);
    return res;
}
