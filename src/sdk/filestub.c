/* Sony PS2 Runtime Library 3.0.0: libkernl filestub (EE side of the IOP file I/O RPC), 0x30a3f8-0x30d820:
 * the fileio RPC init, sceOpen .. sceReadlink and their semaphores. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv). The file's earlier part (0x309be8-0x30a3b0: iob/fd semaphores,
 * the gp-swapping callbacks 0x30a310 and 0x30a3b0) is not in this unit. Strings are .rodata at 0x3781a0;
 * globals stay retail data. Each function keeps the declarations its old matched file used, with a
 * _ADDR suffix and an asm label to the real symbol, so their types do not clash. */
/* EABI varargs: ee-gcc 2.9 has no stdarg.h. */
#define va_start(v,l) (v = (char *)__builtin_next_arg(l) - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
#define UC(p) ((void *)((unsigned int)(p) | 0x20000000))

/* 0030a3f8 func_0030a3f8 (was src/sdk/sdk_w3707.c) */
typedef struct { int fd; int busy; int x8; int xc; } FdEnt_0a3f8;
typedef struct { int a; void *b; } Pair_0a3f8; /* b is a pointer: its store must not alias the int store of a */
typedef struct { void *a; void *b; } PPair_0a3f8;
extern FdEnt_0a3f8 D_01e38780_0a3f8[] asm("D_01e38780");
extern char D_01e38980_0a3f8[] asm("D_01e38980");
extern char D_01e37ec0_0a3f8[] asm("D_01e37ec0");
extern Pair_0a3f8 D_01e38a00_0a3f8 asm("D_01e38a00");
extern char D_01e389c0_0a3f8[] asm("D_01e389c0");
extern char D_01e37f00_0a3f8[] asm("D_01e37f00");
extern PPair_0a3f8 D_01e37240_0a3f8 asm("D_01e37240");
extern int D_01e389a8_0a3f8 asm("D_01e389a8");
extern int D_00366164_0a3f8 asm("D_00366164");
extern int D_00366168_0a3f8 asm("D_00366168");
extern int D_00366170_0a3f8 asm("D_00366170");
extern char D_00309ec0_0a3f8[] asm("D_00309ec0");
extern char D_0030a3b0_0a3f8[] asm("D_0030a3b0");
extern void func_00308b30_0a3f8(int) asm("func_00308b30");
extern int DIntr_0a3f8(void) asm("DIntr");
extern int EIntr_0a3f8(void) asm("EIntr");
extern void func_003086b8_0a3f8(unsigned int, void *, void *) asm("func_003086b8");
extern int sceSifBindRpc_0a3f8(void *, unsigned int, int) asm("sceSifBindRpc");
extern void func_00309be8_0a3f8(void) asm("func_00309be8");
extern int func_00305640_0a3f8(int) asm("func_00305640");
extern int func_00305660_0a3f8(int) asm("func_00305660");
extern int func_00309d60_0a3f8(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry) asm("func_00309d60");
int func_0030a3f8(void)
{
    int s, i;
    FdEnt_0a3f8 *p;
    int t;
    Pair_0a3f8 *q = &D_01e38a00_0a3f8;
    func_00308b30_0a3f8(0);
    D_01e38a00_0a3f8.a = 0;
    q->b = 0;
    s = DIntr_0a3f8();
    func_003086b8_0a3f8(0x80000011, D_00309ec0_0a3f8, D_01e389c0_0a3f8);
    func_003086b8_0a3f8(0x80000013, D_0030a3b0_0a3f8, q);
    if (s)
        EIntr_0a3f8();
    while (1) {
        if (sceSifBindRpc_0a3f8(D_01e38980_0a3f8, 0x80000001, 0) < 0)
            return -22;
        if (*(int *)(D_01e38980_0a3f8 + 36) != 0)
            break;
        i = 0x100000;
        while (i-- != 0)
            ;
    }
    func_00309be8_0a3f8();
    func_00305660_0a3f8(D_00366170_0a3f8);
    for (p = D_01e38780_0a3f8; p < D_01e38780_0a3f8 + 32; p++)
        p->busy = 0;
    func_00305640_0a3f8(D_00366170_0a3f8);
    D_01e37240_0a3f8.a = D_01e37f00_0a3f8;
    D_01e37240_0a3f8.b = D_01e37f00_0a3f8 + 1088;
    if (func_00309d60_0a3f8(D_01e38980_0a3f8, 255, 0, &D_01e37240_0a3f8, 8, D_01e37ec0_0a3f8, 8, 0, 0, 0) < 0)
        return 0xfffeffff;
    __builtin_memcpy(&D_01e389a8_0a3f8, (char *)((unsigned int)D_01e37ec0_0a3f8 | 0x20000000), 4);
    __builtin_memcpy(&t, (char *)((unsigned int)(D_01e37ec0_0a3f8 + 4) | 0x20000000), 4);
    D_00366168_0a3f8 = t == 2;
    D_00366164_0a3f8 = 1;
    return 0;
}

/* 0030a600 func_0030a600 (was src/sdk/sdk_w1057.c) */
extern int memcmp_0a600(void *, void *, int) asm("memcmp");
extern char D_003660c4_0a600[] asm("D_003660c4");
extern char *D_00366178_0a600 asm("D_00366178");
extern char D_01e389a8_0a600[] asm("D_01e389a8");
int func_0030a600(void)
{
    int r = 0;
    char *q = D_003660c4_0a600; char *p = D_01e389a8_0a600;
    if (memcmp_0a600(p, q, 4) && memcmp_0a600(p, D_00366178_0a600, 4))
        r = memcmp_0a600(q, D_00366178_0a600, 4) != 0;
    return r;
}

/* 0030a690 func_0030a690 (was src/sdk/sdk_w509.c) */
extern int D_00366164_0a690 asm("D_00366164");
extern char D_01e389a8_0a690[] asm("D_01e389a8");
extern void func_002fde18_0a690(void *, int, int) asm("func_002fde18");
int func_0030a690(void)
{
    D_00366164_0a690 = 0;
    func_002fde18_0a690(D_01e389a8_0a690, 0, 4);
    return 0;
}

/* 0030a6c8 func_0030a6c8 (was src/sdk/sdk_w1331.c) */
extern int func_00309c58_0a6c8(void) asm("func_00309c58");
extern int func_0030a2d0_0a6c8(int) asm("func_0030a2d0");
extern void func_0030a300_0a6c8(void) asm("func_0030a300");
extern void func_0030a3f8_0a6c8(void) asm("func_0030a3f8");
extern int func_0030a600_0a6c8(void) asm("func_0030a600");
extern int func_00309d60_0a6c8(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry) asm("func_00309d60");
extern int D_00366164_0a6c8 asm("D_00366164");
extern int D_01e37280_0a6c8[] asm("D_01e37280");
extern char D_01e37ec0_0a6c8[] asm("D_01e37ec0");
extern char D_01e38980_0a6c8[] asm("D_01e38980");
int func_0030a6c8(unsigned int addr, unsigned int size)
{
    int r;
    func_0030a2d0_0a6c8(0xfe);
    if (D_00366164_0a6c8 == 0)
        func_0030a3f8_0a6c8();
    if (func_0030a600_0a6c8()) {
        func_0030a300_0a6c8();
        return 0xfffefffc;
    }
    if (func_00309c58_0a6c8()) {
        func_0030a300_0a6c8();
        return -16;
    }
    if ((addr & 0x3fff) || addr == 0 || addr > 0xfffff || size == 0 || size > 32) {
        func_0030a300_0a6c8();
        return -22;
    }
    D_01e37280_0a6c8[0] = addr;
    D_01e37280_0a6c8[1] = size;
    if (func_00309d60_0a6c8(D_01e38980_0a6c8, 0xfe, 0, D_01e37280_0a6c8, 8, D_01e37ec0_0a6c8, 4, 0, 0, 0) < 0) {
        func_0030a300_0a6c8();
        return -11;
    }
    r = *(int *)((unsigned int)D_01e37ec0_0a6c8 | 0x20000000);
    func_0030a300_0a6c8();
    return r;
}

/* 0030a808 func_0030a808 (was src/sdk/sdk_w1329.c) */
int func_00309d60_0a808(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry) asm("func_00309d60");
extern int func_00309c58_0a808(void) asm("func_00309c58");
extern int func_0030a2d0_0a808(int) asm("func_0030a2d0");
extern void func_0030a300_0a808(void) asm("func_0030a300");
extern void func_0030a3f8_0a808(void) asm("func_0030a3f8");
extern int func_0030a600_0a808(void) asm("func_0030a600");
extern int D_00366164_0a808 asm("D_00366164");
extern int D_01e37280_0a808[] asm("D_01e37280");
extern char D_01e37ec0_0a808[] asm("D_01e37ec0");
extern char D_01e38980_0a808[] asm("D_01e38980");
int func_0030a808(int arg)
{
    int r;
    r = func_0030a2d0_0a808(0xfd);
    if (D_00366164_0a808 == 0)
        func_0030a3f8_0a808();
    if (func_0030a600_0a808()) {
        func_0030a300_0a808();
        return 0xfffefffc;
    }
    if (func_00309c58_0a808()) {
        func_0030a300_0a808();
        return -16;
    }
    D_01e37280_0a808[0] = arg;
    if (func_00309d60_0a808(D_01e38980_0a808, 0xfd, 0, D_01e37280_0a808, 8, D_01e37ec0_0a808, 4, 0, 0, 0) < 0) {
        func_0030a300_0a808();
        return -11;
    }
    r = *(int *)((unsigned int)D_01e37ec0_0a808 | 0x20000000);
    func_0030a300_0a808();
    return r;
}

/* 0030a8f8 sceOpen (was src/sdk/sdk_w3788.c) */
typedef char *va_list_0a8f8;
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0a8f8;
typedef struct { int fd; int mode; int x8; int xc; } FdEnt_0a8f8;
typedef struct { int sema; int *res; int rsize; int flags; int mode; char name[1024]; int idx; } OpenPk_0a8f8;
extern OpenPk_0a8f8 D_01e37280_0a8f8 asm("D_01e37280");
extern FdEnt_0a8f8 D_01e38780_0a8f8[] asm("D_01e38780");
extern char D_01e37ec0_0a8f8[] asm("D_01e37ec0");
extern char D_01e38980_0a8f8[] asm("D_01e38980");
extern int D_00366164_0a8f8 asm("D_00366164");
extern int D_00366170_0a8f8 asm("D_00366170");
extern int func_0030a2d0_0a8f8(int) asm("func_0030a2d0");
extern void func_0030a300_0a8f8(void) asm("func_0030a300");
extern int func_0030a3f8_0a8f8(void) asm("func_0030a3f8");
extern int func_0030a600_0a8f8(void) asm("func_0030a600");
extern FdEnt_0a8f8 *func_00309cd8_0a8f8(void) asm("func_00309cd8");
extern int func_00305620_0a8f8(SemaParam_0a8f8 *) asm("func_00305620");
extern int func_00305630_0a8f8(int) asm("func_00305630");
extern int func_00305640_0a8f8(int) asm("func_00305640");
extern int func_00305660_0a8f8(int) asm("func_00305660");
extern int func_00309d60_0a8f8(void *, int, int, void *, int, void *, int, void *, void *, int) asm("func_00309d60");
int sceOpen(const char *name, int flags, ...)
{
    OpenPk_0a8f8 *p = &D_01e37280_0a8f8;
    SemaParam_0a8f8 sp;
    va_list_0a8f8 ap;
    int res;
    int i, s, v, idx, mode;
    FdEnt_0a8f8 *e;
    func_0030a2d0_0a8f8(0);
    if (D_00366164_0a8f8 == 0)
        func_0030a3f8_0a8f8();
    if (func_0030a600_0a8f8()) {
        func_0030a300_0a8f8();
        return -0x10004;
    }
    e = func_00309cd8_0a8f8();
    if (e == 0) {
        func_0030a300_0a8f8();
        return -19;
    }
    va_start(ap, flags);
    mode = *(int *)ap;
    for (i = 0; i < 1024; i++)
        if ((p->name[i] = name[i]) == 0)
            break;
    if (i == 1024)
        p->name[1023] = 0;
    idx = e - D_01e38780_0a8f8;
    p->flags = flags & 0x7fffffff;
    p->mode = mode;
    sp.max_count = 1;
    p->idx = idx;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioOpenSema";
    s = func_00305620_0a8f8(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    if (func_00309d60_0a8f8(D_01e38980_0a8f8, 0, 0, &D_01e37280_0a8f8, 1048, D_01e37ec0_0a8f8, 4, 0, 0, 0) < 0) {
        func_00305630_0a8f8(s);
        func_0030a300_0a8f8();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0_0a8f8 | 0x20000000);
    func_0030a300_0a8f8();
    if (v == 0) {
        func_00305630_0a8f8(s);
        return -11;
    }
    func_00305660_0a8f8(s);
    func_00305630_0a8f8(s);
    if (res < 0) {
        func_00305660_0a8f8(D_00366170_0a8f8);
        e->mode = 0;
        func_00305640_0a8f8(D_00366170_0a8f8);
        return res;
    }
    v = idx;
    func_00305660_0a8f8(D_00366170_0a8f8);
    e->fd = res;
    e->mode |= flags;
    func_00305640_0a8f8(D_00366170_0a8f8);
    return v;
}

/* 0030ab88 sceClose (was src/sdk/sdk_w1332.c) */
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } SemaParam_0ab88;
extern int func_00305660_0ab88(int) asm("func_00305660");
extern int func_00305620_0ab88(SemaParam_0ab88 *) asm("func_00305620");
extern int func_00305630_0ab88(int) asm("func_00305630");
typedef struct { int fd; int busy; int x8; int xc; } FdEnt_0ab88;
extern FdEnt_0ab88 D_01e38780_0ab88[] asm("D_01e38780");
typedef struct { int sema; int *res; int size; int fd; int idx; } Req10_0ab88;
extern int D_00366164_0ab88 asm("D_00366164");
extern Req10_0ab88 D_01e37280_0ab88 asm("D_01e37280");
extern char D_01e37ec0_0ab88[] asm("D_01e37ec0");
extern char D_01e38980_0ab88[] asm("D_01e38980");
extern FdEnt_0ab88 *func_00309e50_0ab88(int) asm("func_00309e50");
extern int func_0030a2d0_0ab88(int) asm("func_0030a2d0");
extern void func_0030a300_0ab88(void) asm("func_0030a300");
extern int func_00309d60_0ab88(void *, int, int, void *, int, void *, int, void *, void *, int) asm("func_00309d60");
int sceClose(int fd)
{
    SemaParam_0ab88 sp;
    int res;
    int sema;
    int r;
    Req10_0ab88 *q = &D_01e37280_0ab88;
    FdEnt_0ab88 *e = func_00309e50_0ab88(fd);
    func_0030a2d0_0ab88(1);
    if (D_00366164_0ab88 == 0 || e == 0 || e->busy == 0) {
        func_0030a300_0ab88();
        return -9;
    }
    q->fd = e->fd;
    q->idx = e - D_01e38780_0ab88;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioCloseSema";
    sema = func_00305620_0ab88(&sp);
    D_01e37280_0ab88.sema = sema;
    q->res = &res;
    q->size = 4;
    if (func_00309d60_0ab88(D_01e38980_0ab88, 1, 0, q, 20, D_01e37ec0_0ab88, 4, 0, 0, 0) < 0) {
        func_00305630_0ab88(sema);
        func_0030a300_0ab88();
        return -11;
    }
    e->busy = 0;
    r = *(int *)((unsigned int)D_01e37ec0_0ab88 | 0x20000000);
    func_0030a300_0ab88();
    if (r == 0) {
        func_00305630_0ab88(sema);
        return -11;
    }
    func_00305660_0ab88(sema);
    func_00305630_0ab88(sema);
    if (res < 0) return res;
    return 0;
}

/* 0030ad00 sceLseek (was src/sdk/sdk_w3747.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0ad00;
typedef struct { int fd; int busy; int x8; int xc; } FdEnt_0ad00;
extern FdEnt_0ad00 D_01e38780_0ad00[] asm("D_01e38780");
typedef struct { int sema; int *res; int rsize; int fd; int off; int whence; int idx; } LsPk_0ad00;
extern LsPk_0ad00 D_01e37280_0ad00 asm("D_01e37280");
extern char D_01e38980_0ad00[] asm("D_01e38980");
extern char D_01e37ec0_0ad00[] asm("D_01e37ec0");
extern int D_00366164_0ad00 asm("D_00366164");
extern int D_00366174_0ad00 asm("D_00366174");
extern int D_003660e0_0ad00[] asm("D_003660e0");
extern int func_0030a2d0_0ad00(int) asm("func_0030a2d0");
extern int func_0030a300_0ad00(void) asm("func_0030a300");
extern int func_00305620_0ad00(SemaParam_0ad00 *) asm("func_00305620");
extern int func_00305630_0ad00(int) asm("func_00305630");
extern int func_00305640_0ad00(int) asm("func_00305640");
extern int func_00305660_0ad00(int) asm("func_00305660");
extern FdEnt_0ad00 *func_00309e50_0ad00(int) asm("func_00309e50");
extern int func_00309d60_0ad00(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry) asm("func_00309d60");
int sceLseek(int fd, int off, int whence)
{
    LsPk_0ad00 *q = &D_01e37280_0ad00;
    SemaParam_0ad00 sp;
    int res;
    int busy, nw, i, m, s, v;
    FdEnt_0ad00 *e = func_00309e50_0ad00(fd);
    func_0030a2d0_0ad00(4);
    if (D_00366164_0ad00 == 0 || e == 0 || (busy = e->busy) == 0) {
        func_0030a300_0ad00();
        return -9;
    }
    q->fd = e->fd;
    q->off = off;
    q->whence = whence;
    q->idx = e - D_01e38780_0ad00;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioLseekSema";
    s = func_00305620_0ad00(&sp);
    q->res = &res;
    q->rsize = 4;
    nw = busy & 0x8000;
    D_01e37280_0ad00.sema = s;
    if (nw) {
        func_00305660_0ad00(D_00366174_0ad00);
        
        { register int n asm("$16") = nw; i = 0; asm("" : "+r"(n) : "r"(i)); busy = n; }
        for (; i < 32; i++) {
            if (D_003660e0_0ad00[i] == -1) {
                D_003660e0_0ad00[i] = q->sema;
                q->sema = -q->sema;
                break;
            }
        }
        func_00305640_0ad00(D_00366174_0ad00);
    } else {
       int z = 0; do { } while (z); busy = z; 
    }
    if (func_00309d60_0ad00(D_01e38980_0ad00, 4, 0, &D_01e37280_0ad00, 28, D_01e37ec0_0ad00, 4, 0, 0, busy) < 0) {
        func_00305630_0ad00(s);
        func_0030a300_0ad00();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0_0ad00 | 0x20000000);
    func_0030a300_0ad00();
    if (v == 0) {
        func_00305630_0ad00(s);
        return -11;
    }
    if (busy) {
        func_00305630_0ad00(s);
        return 0;
    }
    func_00305660_0ad00(s);
    func_00305630_0ad00(s);
    return res;
}

/* 0030af40 sceRead (was src/sdk/sdk_w3768.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0af40;
typedef struct { int fd; int mode; int x8; int xc; } FdEnt_0af40;
typedef struct { int sema; int *res; int rsize; int fd; void *buf; int len; int x18; int idx; } RwPk_0af40;
extern FdEnt_0af40 D_01e38780_0af40[] asm("D_01e38780");
extern RwPk_0af40 D_01e37280_0af40 asm("D_01e37280");
extern char D_01e37ec0_0af40[] asm("D_01e37ec0");
extern char D_01e38980_0af40[] asm("D_01e38980");
extern int D_00366164_0af40 asm("D_00366164");
extern int D_00366174_0af40 asm("D_00366174");
extern int D_003660e0_0af40[32] asm("D_003660e0");
extern FdEnt_0af40 *func_00309e50_0af40(int) asm("func_00309e50");
extern int func_0030a2d0_0af40(int) asm("func_0030a2d0");
extern void func_0030a300_0af40(void) asm("func_0030a300");
extern int func_00305620_0af40(SemaParam_0af40 *) asm("func_00305620");
extern int func_00305630_0af40(int) asm("func_00305630");
extern int func_00305640_0af40(int) asm("func_00305640");
extern int func_00305660_0af40(int) asm("func_00305660");
extern void func_00308a80_0af40(void *, int) asm("func_00308a80");
extern int func_00309d60_0af40(void *, int, int, void *, int, void *, int, void *, void *, int) asm("func_00309d60");
int sceRead(int fd, void *buf, int len)
{
    SemaParam_0af40 sp;
    int res;
    int nr;
    register int sema asm("$19");
    int nw;
    int mode;
    int r;
    int i;
    RwPk_0af40 *q = &D_01e37280_0af40;
    FdEnt_0af40 *e = func_00309e50_0af40(fd);
    func_0030a2d0_0af40(2);
    if (D_00366164_0af40 == 0 || e == 0 || (mode = e->mode) == 0) {
        func_0030a300_0af40();
        return -9;
    }
    q->fd = e->fd;
    q->idx = e - D_01e38780_0af40;
    sp.max_count = 1;
    sp.option = (unsigned int)"SceStdioReadSema";
    nw = mode & 0x8000;
    q->buf = buf;
    q->len = len;
    sp.init_count = 0;
    sema = func_00305620_0af40(&sp);
    q->res = &res;
    q->rsize = 4;
    D_01e37280_0af40.sema = sema;
    if (nw) {
        func_00305660_0af40(D_00366174_0af40);
        asm volatile("");
        { int *t = D_003660e0_0af40; asm("" : "+r"(t)); i = 0; asm volatile(""); nr = nw; } 
        for (; i < 32; i++) {
            if (D_003660e0_0af40[i] == -1) {
                D_003660e0_0af40[i] = q->sema;
                q->sema = -q->sema;
                break;
            }
        }
        func_00305640_0af40(D_00366174_0af40);
    } else
        { int z = 0; do { } while (z); nr = z; } 
    if (!(mode & 0x20000000))
        func_00308a80_0af40(buf, len);
    func_00308a80_0af40(q, 32);
    if (func_00309d60_0af40(D_01e38980_0af40, 2, 0, &D_01e37280_0af40, 32, D_01e37ec0_0af40, 4, 0, 0, nr) < 0) {
        func_00305630_0af40(sema);
        func_0030a300_0af40();
        return -11;
    }
    r = *(int *)((unsigned int)D_01e37ec0_0af40 | 0x20000000);
    func_0030a300_0af40();
    if (r == 0) {
        func_00305630_0af40(sema);
        return -11;
    }
    if (nr) {
        func_00305630_0af40(sema);
        return 0;
    }
    func_00305660_0af40(sema);
    func_00305630_0af40(sema);
    return res;
}

/* 0030b1b0 sceWrite (was src/sdk/sdk_w3768.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0b1b0;
typedef struct { int fd; int mode; int x8; int xc; } FdEnt_0b1b0;
typedef struct { int sema; int *res; int rsize; int fd; void *buf; int len; int n; char data[16]; int idx; } WrPk_0b1b0;
extern FdEnt_0b1b0 D_01e38780_0b1b0[] asm("D_01e38780");
extern WrPk_0b1b0 D_01e37280_w_0b1b0 asm("D_01e37280");
extern char D_01e37ec0_0b1b0[] asm("D_01e37ec0");
extern char D_01e38980_0b1b0[] asm("D_01e38980");
extern int D_00366164_0b1b0 asm("D_00366164");
extern int D_00366174_0b1b0 asm("D_00366174");
extern int D_003660e0_0b1b0[32] asm("D_003660e0");
extern FdEnt_0b1b0 *func_00309e50_0b1b0(int) asm("func_00309e50");
extern int func_0030a2d0_0b1b0(int) asm("func_0030a2d0");
extern void func_0030a300_0b1b0(void) asm("func_0030a300");
extern int func_00305620_0b1b0(SemaParam_0b1b0 *) asm("func_00305620");
extern int func_00305630_0b1b0(int) asm("func_00305630");
extern int func_00305640_0b1b0(int) asm("func_00305640");
extern int func_00305660_0b1b0(int) asm("func_00305660");
extern void func_00308a80_0b1b0(void *, int) asm("func_00308a80");
extern int func_00309d60_0b1b0(void *, int, int, void *, int, void *, int, void *, void *, int) asm("func_00309d60");
int sceWrite(int fd, void *buf, int len)
{
    SemaParam_0b1b0 sp;
    int res;
    int sema;
    int r;
    register int nw asm("$16");
    register int nr asm("$20");
    int mode;
    int i, j, n;
    char *u;
    WrPk_0b1b0 *q = &D_01e37280_w_0b1b0;
    FdEnt_0b1b0 *e = func_00309e50_0b1b0(fd);
    func_0030a2d0_0b1b0(3);
    if (D_00366164_0b1b0 == 0 || e == 0 || (mode = e->mode) == 0) {
        func_0030a300_0b1b0();
        return -9;
    }
    q->fd = e->fd;
    q->idx = e - D_01e38780_0b1b0;
    sp.max_count = 1;
    sp.option = (unsigned int)"SceStdioWriteSema";
    nw = mode & 0x8000;
    q->len = len;
    q->buf = buf;
    sp.init_count = 0;
    sema = func_00305620_0b1b0(&sp);
    q->res = &res;
    q->rsize = 4;
    D_01e37280_w_0b1b0.sema = sema;
    if (nw) {
        func_00305660_0b1b0(D_00366174_0b1b0);
        asm volatile("");
        { int *t = D_003660e0_0b1b0; asm("" : "+r"(t)); i = 0; asm volatile(""); nr = nw; } 
        for (; i < 32; i++) {
            if (D_003660e0_0b1b0[i] == -1) {
                D_003660e0_0b1b0[i] = q->sema;
                q->sema = -q->sema;
                break;
            }
        }
        func_00305640_0b1b0(D_00366174_0b1b0);
    } else
        { unsigned int t = (unsigned int)buf & 0xf; register int z asm("$0"); asm("" :: "r"(t)); nr = z; } 
    if (((unsigned int)buf & 0xf) == 0)
        n = 0;
    else
        n = (unsigned int)buf / 16 * 16 + 16 - (unsigned int)buf;
    if (len < n)
        n = len;
    if (!(mode & 0x20000000))
        func_00308a80_0b1b0(buf, len);
    buf = (void *)((unsigned int)buf | 0x20000000);
    q->n = n;
    for (j = 0; j < n; j++)
        q->data[j] = ((char *)buf)[j];
    if (func_00309d60_0b1b0(D_01e38980_0b1b0, 3, 0, &D_01e37280_w_0b1b0, 48, D_01e37ec0_0b1b0, 4, 0, 0, nr) < 0) {
        func_00305630_0b1b0(sema);
        func_0030a300_0b1b0();
        return -11;
    }
    r = *(int *)((unsigned int)D_01e37ec0_0b1b0 | 0x20000000);
    func_0030a300_0b1b0();
    if (r == 0) {
        func_00305630_0b1b0(sema);
        return -11;
    }
    if (nr) {
        func_00305630_0b1b0(sema);
        return 0;
    }
    func_00305660_0b1b0(sema);
    func_00305630_0b1b0(sema);
    return res;
}

/* 0030b470 sceIoctl (was src/sdk/sdk_w3790.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0b470;
typedef struct { int fd; int mode; int x8; int xc; } FdEnt_0b470;
typedef struct { char b[1024]; } B1024_0b470;
typedef struct { int sema; int *res; int rsize; int fd; int req; B1024_0b470 arg; int x414; int x418; int arglen; } IoctlPk_0b470;
typedef struct { char b[1088]; } B1088_0b470;
extern IoctlPk_0b470 D_01e37280_0b470 asm("D_01e37280");
extern void *D_01e37248_0b470 asm("D_01e37248");
extern B1088_0b470 D_01e37f10_0b470[] asm("D_01e37f10");
extern int D_00366160_0b470 asm("D_00366160");
extern char D_01e37ec0_0b470[] asm("D_01e37ec0");
extern char D_01e38980_0b470[] asm("D_01e38980");
extern int D_00366164_0b470 asm("D_00366164");
extern int D_00366174_0b470 asm("D_00366174");
extern int D_003660e0_0b470[32] asm("D_003660e0");
extern FdEnt_0b470 *func_00309e50_0b470(int) asm("func_00309e50");
extern int func_0030a2d0_0b470(int) asm("func_0030a2d0");
extern void func_0030a300_0b470(void) asm("func_0030a300");
extern int func_0030a3f8_0b470(void) asm("func_0030a3f8");
extern int func_00305620_0b470(SemaParam_0b470 *) asm("func_00305620");
extern int func_00305630_0b470(int) asm("func_00305630");
extern int func_00305640_0b470(int) asm("func_00305640");
extern int func_00305660_0b470(int) asm("func_00305660");
extern void func_00308a80_0b470(void *, int) asm("func_00308a80");
extern int func_00309d60_0b470(void *, int, int, void *, int, void *, int, void *, void *, int) asm("func_00309d60");
int sceIoctl(int fd, int req, void *arg)
{
    IoctlPk_0b470 *p = &D_01e37280_0b470;
    SemaParam_0b470 sp;
    int res;
    int i, s, v;
    int ret = 1;
    FdEnt_0b470 *e = func_00309e50_0b470(fd);
    func_0030a2d0_0b470(5);
    D_01e37248_0b470 = arg;
    if (D_00366164_0b470 == 0)
        func_0030a3f8_0b470();
    if (e == 0 || e->mode == 0) {
        func_0030a300_0b470();
        return -9;
    }
    p->x414 = 0;
    p->x418 = 0;
    switch (req) {
    case 1:
        func_00305660_0b470(D_00366174_0b470);
        { int *t = D_003660e0_0b470; asm("" : "+r"(t)); i = 0; asm volatile(""); } 
        for (; i < 32; i++)
            if (D_003660e0_0b470[i] != -1)
                break;
        if (i == 32)
            *(int *)D_01e37248_0b470 = 0;
        else
            *(int *)D_01e37248_0b470 = 1;
        func_00305640_0b470(D_00366174_0b470);
        func_0030a300_0b470();
        return 0;
    case 2:
        *(int *)arg = *(int *)((unsigned int)&D_01e37f10_0b470[D_00366160_0b470] | 0x20000000);
        func_0030a300_0b470();
        return 0;
    case 3:
        *(long *)arg = *(long *)((unsigned int)&D_01e37f10_0b470[D_00366160_0b470] | 0x20000000);
        func_0030a300_0b470();
        return 0;
    }
    p->fd = e->fd;
    p->req = req;
    if (arg == 0)
        p->arglen = 0;
    else {
        p->arglen = 1024;
        p->arg = *(B1024_0b470 *)arg;
    }
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioIoctlSema";
    s = func_00305620_0b470(&sp);
    p->sema = s;
    p->res = &res;
    p->rsize = 4;
    func_00308a80_0b470(&D_01e37280_0b470, 1056);
    if (func_00309d60_0b470(D_01e38980_0b470, 5, 0, &D_01e37280_0b470, 1056, D_01e37ec0_0b470, 4, 0, 0, 0) < 0) {
        func_00305630_0b470(s);
        func_0030a300_0b470();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0_0b470 | 0x20000000);
    func_0030a300_0b470();
    if (v == 0) {
        func_00305630_0b470(s);
        return -11;
    }
    func_00305660_0b470(s);
    func_00305630_0b470(s);
    ret = res;
    return ret;
}

/* 0030b7f8 sceIoctl2 (was src/sdk/sdk_w1334.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0b7f8;
typedef struct { int sema; int *res; int rsize; char name[1024]; char name2[1024]; } SymPk_0b7f8;
typedef struct { int sema; int *res; int rsize; int fd; int req; char arg[1024]; void *buf; int buflen; int arglen; } IoPk_0b7f8;
typedef struct { int fd; int valid; } Fdd_0b7f8;
extern SymPk_0b7f8 D_01e37280_0b7f8 asm("D_01e37280");
extern char D_01e38980_0b7f8[] asm("D_01e38980");
extern char D_01e37ec0_0b7f8[] asm("D_01e37ec0");
extern int D_00366164_0b7f8 asm("D_00366164");
extern int func_0030a2d0_0b7f8(int) asm("func_0030a2d0");
extern int func_0030a300_0b7f8(void) asm("func_0030a300");
extern int func_0030a3f8_0b7f8(void) asm("func_0030a3f8");
extern int func_00305620_0b7f8(SemaParam_0b7f8 *) asm("func_00305620");
extern int func_00305630_0b7f8(int) asm("func_00305630");
extern int func_00305660_0b7f8(int) asm("func_00305660");
extern void func_00308a80_0b7f8(void *, int) asm("func_00308a80");
extern void *memcpy_0b7f8(void *, const void *, int) asm("memcpy");
extern Fdd_0b7f8 *func_00309e50_0b7f8(int) asm("func_00309e50");
extern int func_00309d60_0b7f8(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry) asm("func_00309d60");
int sceIoctl2(int fd, int req, void *arg, unsigned int arglen, void *buf, unsigned int buflen)
{
    IoPk_0b7f8 *p = (IoPk_0b7f8 *)&D_01e37280_0b7f8;
    SemaParam_0b7f8 sp;
    int res;
    int s, v;
    Fdd_0b7f8 *f = func_00309e50_0b7f8(fd);
    func_0030a2d0_0b7f8(26);
    if (D_00366164_0b7f8 == 0)
        func_0030a3f8_0b7f8();
    if (f == 0 || f->valid == 0) {
        func_0030a300_0b7f8();
        return -9;
    }
    if (arglen > 1024 || buflen > 1024) {
        func_0030a300_0b7f8();
        return -22;
    }
    if (arg == 0)
        p->arglen = 0;
    else
        memcpy_0b7f8(p->arg, arg, arglen);
    p->fd = f->fd;
    p->req = req;
    p->arglen = arglen;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioIoctl2Sema";
    s = func_00305620_0b7f8(&sp);
    p->buflen = buflen;
    p->res = &res;
    p->rsize = 4;
    p->buf = buf;
    p->sema = s;
    func_00308a80_0b7f8(&D_01e37280_0b7f8, 1056);
    if (func_00309d60_0b7f8(D_01e38980_0b7f8, 26, 0, &D_01e37280_0b7f8, 1056, D_01e37ec0_0b7f8, 4, 0, 0, 0) < 0) {
        func_00305630_0b7f8(s);
        func_0030a300_0b7f8();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0_0b7f8 | 0x20000000);
    func_0030a300_0b7f8();
    if (v == 0) {
        func_00305630_0b7f8(s);
        return -11;
    }
    func_00305660_0b7f8(s);
    func_00305630_0b7f8(s);
    return res;
}

/* 0030b9e0 u_call4_0030b9e0 (was src/sdk/sdk_w1333.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0b9e0;
typedef struct { int sema; int *res; int rsize; int pad; int mode; char name[1024]; } OpenPk_0b9e0;
extern OpenPk_0b9e0 D_01e37280_0b9e0 asm("D_01e37280");
extern char D_01e38980_0b9e0[] asm("D_01e38980");
extern char D_01e37ec0_0b9e0[] asm("D_01e37ec0");
extern int D_00366164_0b9e0 asm("D_00366164");
extern int func_0030a2d0_0b9e0(int) asm("func_0030a2d0");
extern int func_0030a300_0b9e0(void) asm("func_0030a300");
extern int func_0030a3f8_0b9e0(void) asm("func_0030a3f8");
extern int func_00305620_0b9e0(SemaParam_0b9e0 *) asm("func_00305620");
extern int func_00305630_0b9e0(int) asm("func_00305630");
extern int func_00305660_0b9e0(int) asm("func_00305660");
extern int func_00309d60_0b9e0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry) asm("func_00309d60");
typedef struct { int sema; int *res; int rsize; char name[1024]; } NamePk_0b9e0;
int u_call4_0030b9e0(const char *name, int fno) asm("_Z16u_call4_0030b9e0jjjj");
int u_call4_0030b9e0(const char *name, int fno)
{
    NamePk_0b9e0 *p = (NamePk_0b9e0 *)&D_01e37280_0b9e0;
    SemaParam_0b9e0 sp;
    int res;
    int i, s, v;
    func_0030a2d0_0b9e0(fno);
    if (D_00366164_0b9e0 == 0)
        func_0030a3f8_0b9e0();
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
    s = func_00305620_0b9e0(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    if (func_00309d60_0b9e0(D_01e38980_0b9e0, fno, 0, &D_01e37280_0b9e0, i + 13, D_01e37ec0_0b9e0, 4, 0, 0, 0) < 0) {
        func_00305630_0b9e0(s);
        func_0030a300_0b9e0();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0_0b9e0 | 0x20000000);
    func_0030a300_0b9e0();
    if (v == 0) {
        func_00305630_0b9e0(s);
        return -11;
    }
    func_00305660_0b9e0(s);
    func_00305630_0b9e0(s);
    return res;
}

/* 0030bb90 func_0030bb90 (was src/anon/tiny_auto80_fptr4.cpp, gcc 3.2 copy; now C) */
extern int u_call4_0030b9e0_0bb90(const char *name, int fno) asm("_Z16u_call4_0030b9e0jjjj");
int func_0030bb90(const char *name)
{
    return u_call4_0030b9e0_0bb90(name, 6);
}

/* 0030bbb0 sceMkdir (was src/sdk/sdk_w1333.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0bbb0;
typedef struct { int sema; int *res; int rsize; int pad; int mode; char name[1024]; } OpenPk_0bbb0;
extern OpenPk_0bbb0 D_01e37280_0bbb0 asm("D_01e37280");
extern char D_01e38980_0bbb0[] asm("D_01e38980");
extern char D_01e37ec0_0bbb0[] asm("D_01e37ec0");
extern int D_00366164_0bbb0 asm("D_00366164");
extern int func_0030a2d0_0bbb0(int) asm("func_0030a2d0");
extern int func_0030a300_0bbb0(void) asm("func_0030a300");
extern int func_0030a3f8_0bbb0(void) asm("func_0030a3f8");
extern int func_00305620_0bbb0(SemaParam_0bbb0 *) asm("func_00305620");
extern int func_00305630_0bbb0(int) asm("func_00305630");
extern int func_00305660_0bbb0(int) asm("func_00305660");
extern int func_00309d60_0bbb0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry) asm("func_00309d60");
typedef struct { int sema; int *res; int rsize; int mode; char name[1024]; } ModePk2_0bbb0;
int sceMkdir(const char *name, int mode)
{
    ModePk2_0bbb0 *p = (ModePk2_0bbb0 *)&D_01e37280_0bbb0;
    SemaParam_0bbb0 sp;
    int res;
    int i, s, v;
    func_0030a2d0_0bbb0(7);
    if (D_00366164_0bbb0 == 0)
        func_0030a3f8_0bbb0();
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
    s = func_00305620_0bbb0(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    if (func_00309d60_0bbb0(D_01e38980_0bbb0, 7, 0, &D_01e37280_0bbb0, i + 17, D_01e37ec0_0bbb0, 4, 0, 0, 0) < 0) {
        func_00305630_0bbb0(s);
        func_0030a300_0bbb0();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0_0bbb0 | 0x20000000);
    func_0030a300_0bbb0();
    if (v == 0) {
        func_00305630_0bbb0(s);
        return -11;
    }
    func_00305660_0bbb0(s);
    func_00305630_0bbb0(s);
    return res;
}

/* 0030bd68 func_0030bd68 (was src/anon/tiny_auto80_fptr4.cpp, gcc 3.2 copy; now C) */
extern int u_call4_0030b9e0_0bd68(const char *name, int fno) asm("_Z16u_call4_0030b9e0jjjj");
int func_0030bd68(const char *name)
{
    return u_call4_0030b9e0_0bd68(name, 8);
}

/* 0030bd88 sceFormat (was src/sdk/sdk_w1724.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0bd88;
typedef struct { int sema; int *res; int rsize; char name[1024]; char name2[1024]; char arg[1024]; int arglen; } DevPk_0bd88;
typedef struct { int sema; int *res; int rsize; char name[1024]; char name2[1024]; char arg[1024]; int flag; int arglen; } MntPk_0bd88;
typedef struct { int sema; int *res; int rsize; char name[1024]; char arg[1024]; int cmd; unsigned int arglen; void *buf; unsigned int buflen; } DctlPk_0bd88;
typedef union { DevPk_0bd88 dev; MntPk_0bd88 mnt; DctlPk_0bd88 dctl; } StdioPk_0bd88;
extern StdioPk_0bd88 D_01e37280_0bd88 asm("D_01e37280");
extern char D_01e37ec0_0bd88[] asm("D_01e37ec0");
extern char D_01e38980_0bd88[] asm("D_01e38980");
extern int D_00366164_0bd88 asm("D_00366164");
extern int func_0030a2d0_0bd88(int) asm("func_0030a2d0");
extern void func_0030a300_0bd88(void) asm("func_0030a300");
extern int func_0030a3f8_0bd88(void) asm("func_0030a3f8");
extern int func_00305620_0bd88(SemaParam_0bd88 *) asm("func_00305620");
extern int func_00305630_0bd88(int) asm("func_00305630");
extern int func_00305660_0bd88(int) asm("func_00305660");
extern void func_00308a80_0bd88(void *, int) asm("func_00308a80");
extern int func_00309d60_0bd88(void *, int, int, void *, int, void *, int, void *, void *, int) asm("func_00309d60");
int sceFormat(const char *name, const char *name2, const char *arg, int arglen)
{
    DevPk_0bd88 *p = &D_01e37280_0bd88.dev;
    SemaParam_0bd88 sp;
    int res;
    int i, s, v;
    func_0030a2d0_0bd88(14);
    if (D_00366164_0bd88 == 0)
        func_0030a3f8_0bd88();
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
        func_0030a300_0bd88();
        return -7;
    }
    for (i = 0; i < arglen; i++)
        p->arg[i] = arg[i];
    p->arglen = arglen;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioFormatSema";
    s = func_00305620_0bd88(&sp);
    p->sema = s;
    p->res = &res;
    p->rsize = 4;
    func_00308a80_0bd88(&D_01e37280_0bd88.dev, 3088);
    if (func_00309d60_0bd88(D_01e38980_0bd88, 14, 0, &D_01e37280_0bd88.dev, 3088, D_01e37ec0_0bd88, 4, 0, 0, 0) < 0) {
        func_00305630_0bd88(s);
        func_0030a300_0bd88();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0_0bd88 | 0x20000000);
    func_0030a300_0bd88();
    if (v == 0) {
        func_00305630_0bd88(s);
        return -11;
    }
    func_00305660_0bd88(s);
    func_00305630_0bd88(s);
    return res;
}

/* 0030c008 sceAddDrv (was src/sdk/sdk_w8005.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0c008;
typedef struct { int sema; int *ret; int size; int arg; } AddDrvSend_0c008;
extern int func_00305620_0c008(SemaParam_0c008 *) asm("func_00305620");
extern int func_00305630_0c008(int) asm("func_00305630");
extern int func_00305660_0c008(int) asm("func_00305660");
extern int func_0030a2d0_0c008(int) asm("func_0030a2d0");
extern void func_0030a300_0c008(void) asm("func_0030a300");
extern void func_0030a3f8_0c008(void) asm("func_0030a3f8");
extern int D_00366164_0c008 asm("D_00366164");
extern AddDrvSend_0c008 D_01e37280_0c008 asm("D_01e37280");
extern int D_01e37ec0_0c008 asm("D_01e37ec0");
extern char D_01e38980_0c008[] asm("D_01e38980");
extern int func_00309d60_0c008(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int x) asm("func_00309d60");
int sceAddDrv(int arg)
{
    SemaParam_0c008 p;
    int ret;
    int sema;
    int r;
    AddDrvSend_0c008 *snd = &D_01e37280_0c008;
    r = func_0030a2d0_0c008(15);
    if (!D_00366164_0c008)
        func_0030a3f8_0c008();
    snd->arg = arg;
    p.max_count = 1;
    p.option = (unsigned int)"SceStdioAddDrvSema";
    p.init_count = 0;
    sema = func_00305620_0c008(&p);
    D_01e37280_0c008.sema = sema;
    D_01e37280_0c008.ret = &ret;
    D_01e37280_0c008.size = 4;
    if (func_00309d60_0c008(D_01e38980_0c008, 15, 0, &D_01e37280_0c008, 16, &D_01e37ec0_0c008, 4, 0, 0, 0) < 0) {
        func_00305630_0c008(sema);
        func_0030a300_0c008();
        return -11;
    }
    r = *(int *)((unsigned int)&D_01e37ec0_0c008 | 0x20000000);
    func_0030a300_0c008();
    if (!r) {
        func_00305630_0c008(sema);
        return -11;
    }
    func_00305660_0c008(sema);
    func_00305630_0c008(sema);
    return ret;
}

/* 0030c138 func_0030c138 (was src/anon/tiny_auto80_fptr4.cpp, gcc 3.2 copy; now C) */
extern int u_call4_0030b9e0_0c138(const char *name, int fno) asm("_Z16u_call4_0030b9e0jjjj");
int func_0030c138(const char *name)
{
    return u_call4_0030b9e0_0c138(name, 16);
}

/* 0030c158 func_0030c158 (was src/sdk/sdk_w3759.c) */
typedef struct { int x0, x4, x8, xc; } E_0c158;
extern E_0c158 D_01e38780_0c158[] asm("D_01e38780");
extern int D_00366164_0c158 asm("D_00366164");
extern int D_00366170_0c158 asm("D_00366170");
extern int func_0030a2d0_0c158(int) asm("func_0030a2d0");
extern void func_0030a3f8_0c158(void) asm("func_0030a3f8");
extern void func_0030a300_0c158(void) asm("func_0030a300");
extern E_0c158 *func_00309cd8_0c158(void) asm("func_00309cd8");
extern int func_0030b9e0_0c158(int, int) asm("func_0030b9e0");
extern int func_00305660_0c158(int) asm("func_00305660");
extern int func_00305640_0c158(int) asm("func_00305640");
int func_0030c158(int a)
{
    int r;
    E_0c158 *p;
    func_0030a2d0_0c158(9);
    if (D_00366164_0c158 == 0)
        func_0030a3f8_0c158();
    func_0030a300_0c158();
    p = func_00309cd8_0c158();
    if (p == 0)
        return -19;
    r = func_0030b9e0_0c158(a, 9);
    if (r < 0) {
        func_00305660_0c158(D_00366170_0c158);
        p->x4 = 0;
        func_00305640_0c158(D_00366170_0c158);
        return r;
    }
    func_00305660_0c158(D_00366170_0c158);
    p->x0 = r;
    r = p - D_01e38780_0c158;
    func_00305640_0c158(D_00366170_0c158);
    return r;
}

/* 0030c220 sceDclose (was src/sdk/sdk_w1332.c) */
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } SemaParam_0c220;
extern int func_00305660_0c220(int) asm("func_00305660");
extern int func_00305620_0c220(SemaParam_0c220 *) asm("func_00305620");
extern int func_00305630_0c220(int) asm("func_00305630");
typedef struct { int fd; int busy; int x8; int xc; } FdEnt_0c220;
typedef struct { int sema; int *res; int size; int fd; int idx; } Req10_0c220;
extern int D_00366164_0c220 asm("D_00366164");
extern Req10_0c220 D_01e37280_0c220 asm("D_01e37280");
extern char D_01e37ec0_0c220[] asm("D_01e37ec0");
extern char D_01e38980_0c220[] asm("D_01e38980");
extern FdEnt_0c220 *func_00309e50_0c220(int) asm("func_00309e50");
extern int func_0030a2d0_0c220(int) asm("func_0030a2d0");
extern void func_0030a300_0c220(void) asm("func_0030a300");
extern int func_00309d60_0c220(void *, int, int, void *, int, void *, int, void *, void *, int) asm("func_00309d60");
int sceDclose(int fd)
{
    SemaParam_0c220 sp;
    int res;
    int sema;
    int r;
    Req10_0c220 *q = &D_01e37280_0c220;
    FdEnt_0c220 *e = func_00309e50_0c220(fd);
    func_0030a2d0_0c220(10);
    if (D_00366164_0c220 == 0 || e == 0 || e->busy == 0) {
        func_0030a300_0c220();
        return -9;
    }
    q->fd = e->fd;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioDcloseSema";
    sema = func_00305620_0c220(&sp);
    D_01e37280_0c220.sema = sema;
    q->res = &res;
    q->size = 4;
    if (func_00309d60_0c220(D_01e38980_0c220, 10, 0, q, 20, D_01e37ec0_0c220, 4, 0, 0, 0) < 0) {
        func_00305630_0c220(sema);
        func_0030a300_0c220();
        return -11;
    }
    e->busy = 0;
    r = *(int *)((unsigned int)D_01e37ec0_0c220 | 0x20000000);
    func_0030a300_0c220();
    if (r == 0) {
        func_00305630_0c220(sema);
        return -11;
    }
    func_00305660_0c220(sema);
    func_00305630_0c220(sema);
    if (res < 0) return res;
    return 0;
}

/* 0030c388 sceDread (was src/sdk/sdk_w1331.c) */
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } SemaParam_0c388;
extern int func_00305630_0c388(int) asm("func_00305630");
extern int func_00305660_0c388(int) asm("func_00305660");
extern int func_00305620_0c388(SemaParam_0c388 *) asm("func_00305620");
extern int func_0030a2d0_0c388(int) asm("func_0030a2d0");
extern void func_0030a300_0c388(void) asm("func_0030a300");
extern int func_00309d60_0c388(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry) asm("func_00309d60");
extern int D_00366164_0c388 asm("D_00366164");
extern int D_01e37280_0c388[] asm("D_01e37280");
extern char D_01e37ec0_0c388[] asm("D_01e37ec0");
extern char D_01e38980_0c388[] asm("D_01e38980");
typedef struct { int fd; int valid; } FioFile_0c388;
extern FioFile_0c388 *func_00309e50_0c388(int) asm("func_00309e50");
int sceDread(int fd, void *buf)
{
    SemaParam_0c388 sp;
    int res;
    int sema;
    int r;
    FioFile_0c388 *f;
    int *p = D_01e37280_0c388;

    f = func_00309e50_0c388(fd);
    func_0030a2d0_0c388(11);
    if (D_00366164_0c388 == 0 || f == 0 || f->valid == 0) {
        func_0030a300_0c388();
        return -9;
    }
    p[3] = f->fd;
    p[4] = (int)buf;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioDreadSema";
    sema = func_00305620_0c388(&sp);
    p[0] = sema;
    p[1] = (int)&res;
    p[2] = 4;
    if (func_00309d60_0c388(D_01e38980_0c388, 11, 0, p, 32, D_01e37ec0_0c388, 4, 0, 0, 0) < 0) {
        func_00305660_0c388(sema);
        func_0030a300_0c388();
        return -11;
    }
    r = *(int *)((unsigned int)D_01e37ec0_0c388 | 0x20000000);
    func_0030a300_0c388();
    if (r == 0) {
        func_00305630_0c388(sema);
        return -11;
    }
    func_00305660_0c388(sema);
    func_00305630_0c388(sema);
    return res;
}

/* 0030c4e0 sceGetstat (was src/sdk/sdk_w1333.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0c4e0;
typedef struct { int sema; int *res; int rsize; int pad; int mode; char name[1024]; } OpenPk_0c4e0;
extern OpenPk_0c4e0 D_01e37280_0c4e0 asm("D_01e37280");
extern char D_01e38980_0c4e0[] asm("D_01e38980");
extern char D_01e37ec0_0c4e0[] asm("D_01e37ec0");
extern int D_00366164_0c4e0 asm("D_00366164");
extern int func_0030a2d0_0c4e0(int) asm("func_0030a2d0");
extern int func_0030a300_0c4e0(void) asm("func_0030a300");
extern int func_0030a3f8_0c4e0(void) asm("func_0030a3f8");
extern int func_00305620_0c4e0(SemaParam_0c4e0 *) asm("func_00305620");
extern int func_00305630_0c4e0(int) asm("func_00305630");
extern int func_00305660_0c4e0(int) asm("func_00305660");
extern int func_00309d60_0c4e0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry) asm("func_00309d60");
typedef struct { int sema; int *res; int rsize; int mode; unsigned char name[1024]; } ModePk_0c4e0;
int sceGetstat(const unsigned char *name, int mode)
{
    ModePk_0c4e0 *p = (ModePk_0c4e0 *)&D_01e37280_0c4e0;
    SemaParam_0c4e0 sp;
    int res;
    int i, s, v;
    func_0030a2d0_0c4e0(12);
    if (D_00366164_0c4e0 == 0)
        func_0030a3f8_0c4e0();
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
    s = func_00305620_0c4e0(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    if (func_00309d60_0c4e0(D_01e38980_0c4e0, 12, 0, &D_01e37280_0c4e0, i + 17, D_01e37ec0_0c4e0, 4, 0, 0, 0) < 0) {
        func_00305630_0c4e0(s);
        func_0030a300_0c4e0();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0_0c4e0 | 0x20000000);
    func_0030a300_0c4e0();
    if (v == 0) {
        func_00305630_0c4e0(s);
        return -11;
    }
    func_00305660_0c4e0(s);
    func_00305630_0c4e0(s);
    return res;
}

/* 0030c698 sceChstat (was src/sdk/sdk_w1334.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0c698;
typedef struct { int sema; int *res; int rsize; char name[1024]; char name2[1024]; } SymPk_0c698;
extern SymPk_0c698 D_01e37280_0c698 asm("D_01e37280");
extern char D_01e38980_0c698[] asm("D_01e38980");
extern char D_01e37ec0_0c698[] asm("D_01e37ec0");
extern int D_00366164_0c698 asm("D_00366164");
extern int func_0030a2d0_0c698(int) asm("func_0030a2d0");
extern int func_0030a300_0c698(void) asm("func_0030a300");
extern int func_0030a3f8_0c698(void) asm("func_0030a3f8");
extern int func_00305620_0c698(SemaParam_0c698 *) asm("func_00305620");
extern int func_00305630_0c698(int) asm("func_00305630");
extern int func_00305660_0c698(int) asm("func_00305660");
extern void func_00308a80_0c698(void *, int) asm("func_00308a80");
extern int func_00309d60_0c698(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry) asm("func_00309d60");
typedef struct { unsigned int w[16]; } Stat64_0c698;
typedef struct { int sema; int *res; int rsize; int cbit; Stat64_0c698 st; unsigned char name[1024]; } ChPk_0c698;
int sceChstat(const unsigned char *name, Stat64_0c698 *st, int cbit)
{
    ChPk_0c698 *p = (ChPk_0c698 *)&D_01e37280_0c698;
    SemaParam_0c698 sp;
    int res;
    int i, s, v;
    func_0030a2d0_0c698(13);
    if (D_00366164_0c698 == 0)
        func_0030a3f8_0c698();
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
    s = func_00305620_0c698(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    func_00308a80_0c698(&D_01e37280_0c698, 1104);
    if (func_00309d60_0c698(D_01e38980_0c698, 13, 0, &D_01e37280_0c698, i + 81, D_01e37ec0_0c698, 4, 0, 0, 0) < 0) {
        func_00305630_0c698(s);
        func_0030a300_0c698();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0_0c698 | 0x20000000);
    func_0030a300_0c698();
    if (v == 0) {
        func_00305630_0c698(s);
        return -11;
    }
    func_00305660_0c698(s);
    func_00305630_0c698(s);
    return res;
}

/* 0030c8e8 sceRename (was src/sdk/sdk_w1334.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0c8e8;
typedef struct { int sema; int *res; int rsize; char name[1024]; char name2[1024]; } SymPk_0c8e8;
extern SymPk_0c8e8 D_01e37280_0c8e8 asm("D_01e37280");
extern char D_01e38980_0c8e8[] asm("D_01e38980");
extern char D_01e37ec0_0c8e8[] asm("D_01e37ec0");
extern int D_00366164_0c8e8 asm("D_00366164");
extern int func_0030a2d0_0c8e8(int) asm("func_0030a2d0");
extern int func_0030a300_0c8e8(void) asm("func_0030a300");
extern int func_0030a3f8_0c8e8(void) asm("func_0030a3f8");
extern int func_00305620_0c8e8(SemaParam_0c8e8 *) asm("func_00305620");
extern int func_00305630_0c8e8(int) asm("func_00305630");
extern int func_00305660_0c8e8(int) asm("func_00305660");
extern void func_00308a80_0c8e8(void *, int) asm("func_00308a80");
extern int func_00309d60_0c8e8(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry) asm("func_00309d60");
int sceRename(const char *a, const char *b)
{
    SymPk_0c8e8 *p = &D_01e37280_0c8e8;
    SemaParam_0c8e8 sp;
    int res;
    int i, s, v;
    func_0030a2d0_0c8e8(17);
    if (D_00366164_0c8e8 == 0)
        func_0030a3f8_0c8e8();
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
    s = func_00305620_0c8e8(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    func_00308a80_0c8e8(&D_01e37280_0c8e8, 2060);
    if (func_00309d60_0c8e8(D_01e38980_0c8e8, 17, 0, &D_01e37280_0c8e8, 2060, D_01e37ec0_0c8e8, 4, 0, 0, 0) < 0) {
        func_00305630_0c8e8(s);
        func_0030a300_0c8e8();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0_0c8e8 | 0x20000000);
    func_0030a300_0c8e8();
    if (v == 0) {
        func_00305630_0c8e8(s);
        return -11;
    }
    func_00305660_0c8e8(s);
    func_00305630_0c8e8(s);
    return res;
}

/* 0030caf0 func_0030caf0 (was src/anon/tiny_auto80_fptr4.cpp, gcc 3.2 copy; now C) */
extern int u_call4_0030b9e0_0caf0(const char *name, int fno) asm("_Z16u_call4_0030b9e0jjjj");
int func_0030caf0(const char *name)
{
    return u_call4_0030b9e0_0caf0(name, 18);
}

/* 0030cb10 sceSync (was src/sdk/sdk_w1333.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0cb10;
typedef struct { int sema; int *res; int rsize; int pad; int mode; char name[1024]; } OpenPk_0cb10;
extern OpenPk_0cb10 D_01e37280_0cb10 asm("D_01e37280");
extern char D_01e38980_0cb10[] asm("D_01e38980");
extern char D_01e37ec0_0cb10[] asm("D_01e37ec0");
extern int D_00366164_0cb10 asm("D_00366164");
extern int func_0030a2d0_0cb10(int) asm("func_0030a2d0");
extern int func_0030a300_0cb10(void) asm("func_0030a300");
extern int func_0030a3f8_0cb10(void) asm("func_0030a3f8");
extern int func_00305620_0cb10(SemaParam_0cb10 *) asm("func_00305620");
extern int func_00305630_0cb10(int) asm("func_00305630");
extern int func_00305660_0cb10(int) asm("func_00305660");
extern int func_00309d60_0cb10(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry) asm("func_00309d60");
int sceSync(const char *name, int mode)
{
    OpenPk_0cb10 *p = &D_01e37280_0cb10;
    SemaParam_0cb10 sp;
    int res;
    int i, s, v;
    func_0030a2d0_0cb10(19);
    if (D_00366164_0cb10 == 0)
        func_0030a3f8_0cb10();
    for (i = 0; i < 1024; i++)
        if ((p->name[i] = name[i]) == 0)
            break;
    if (i == 1024)
        p->name[1023] = 0;
    p->mode = mode;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioSyncSema";
    s = func_00305620_0cb10(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    if (func_00309d60_0cb10(D_01e38980_0cb10, 19, 0, &D_01e37280_0cb10, 1044, D_01e37ec0_0cb10, 4, 0, 0, 0) < 0) {
        func_00305630_0cb10(s);
        func_0030a300_0cb10();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0_0cb10 | 0x20000000);
    func_0030a300_0cb10();
    if (v == 0) {
        func_00305630_0cb10(s);
        return -11;
    }
    func_00305660_0cb10(s);
    func_00305630_0cb10(s);
    return res;
}

/* 0030ccc0 sceMount (was src/sdk/sdk_w1724.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0ccc0;
typedef struct { int sema; int *res; int rsize; char name[1024]; char name2[1024]; char arg[1024]; int arglen; } DevPk_0ccc0;
typedef struct { int sema; int *res; int rsize; char name[1024]; char name2[1024]; char arg[1024]; int flag; int arglen; } MntPk_0ccc0;
typedef struct { int sema; int *res; int rsize; char name[1024]; char arg[1024]; int cmd; unsigned int arglen; void *buf; unsigned int buflen; } DctlPk_0ccc0;
typedef union { DevPk_0ccc0 dev; MntPk_0ccc0 mnt; DctlPk_0ccc0 dctl; } StdioPk_0ccc0;
extern StdioPk_0ccc0 D_01e37280_0ccc0 asm("D_01e37280");
extern char D_01e37ec0_0ccc0[] asm("D_01e37ec0");
extern char D_01e38980_0ccc0[] asm("D_01e38980");
extern int D_00366164_0ccc0 asm("D_00366164");
extern int func_0030a2d0_0ccc0(int) asm("func_0030a2d0");
extern void func_0030a300_0ccc0(void) asm("func_0030a300");
extern int func_0030a3f8_0ccc0(void) asm("func_0030a3f8");
extern int func_00305620_0ccc0(SemaParam_0ccc0 *) asm("func_00305620");
extern int func_00305630_0ccc0(int) asm("func_00305630");
extern int func_00305660_0ccc0(int) asm("func_00305660");
extern void func_00308a80_0ccc0(void *, int) asm("func_00308a80");
extern int func_00309d60_0ccc0(void *, int, int, void *, int, void *, int, void *, void *, int) asm("func_00309d60");
int sceMount(const char *name, const char *name2, int flag, const char *arg, int arglen)
{
    MntPk_0ccc0 *p = &D_01e37280_0ccc0.mnt;
    SemaParam_0ccc0 sp;
    int res;
    int i, s, v;
    func_0030a2d0_0ccc0(20);
    if (D_00366164_0ccc0 == 0)
        func_0030a3f8_0ccc0();
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
        func_0030a300_0ccc0();
        return -7;
    }
    for (i = 0; i < arglen; i++)
        p->arg[i] = arg[i];
    p->arglen = arglen;
    p->flag = flag;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioMountSema";
    s = func_00305620_0ccc0(&sp);
    p->sema = s;
    p->res = &res;
    p->rsize = 4;
    func_00308a80_0ccc0(&D_01e37280_0ccc0.mnt, 3092);
    if (func_00309d60_0ccc0(D_01e38980_0ccc0, 20, 0, &D_01e37280_0ccc0.mnt, 3092, D_01e37ec0_0ccc0, 4, 0, 0, 0) < 0) {
        func_00305630_0ccc0(s);
        func_0030a300_0ccc0();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0_0ccc0 | 0x20000000);
    func_0030a300_0ccc0();
    if (v == 0) {
        func_00305630_0ccc0(s);
        return -11;
    }
    func_00305660_0ccc0(s);
    func_00305630_0ccc0(s);
    return res;
}

/* 0030cf40 func_0030cf40 (was src/anon/tiny_auto80_fptr4.cpp, gcc 3.2 copy; now C) */
extern int u_call4_0030b9e0_0cf40(const char *name, int fno) asm("_Z16u_call4_0030b9e0jjjj");
int func_0030cf40(const char *name)
{
    return u_call4_0030b9e0_0cf40(name, 21);
}

/* 0030cf60 sceLseek64 (was src/sdk/sdk_w3748.c) */
typedef long long s64_0cf60 __attribute__((mode(DI)));
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0cf60;
typedef struct { int fd; int busy; int x8; int xc; } FdEnt_0cf60;
extern FdEnt_0cf60 D_01e38780_0cf60[] asm("D_01e38780");
typedef struct { int sema; int *res; int rsize; int fd; int off; int whence; int idx; } LsPk_0cf60;
typedef struct { int sema; void *res; int rsize; int fd; s64_0cf60 off; int whence; int idx; } Ls64Pk_0cf60;
extern LsPk_0cf60 D_01e37280_0cf60 asm("D_01e37280");
extern char D_01e38980_0cf60[] asm("D_01e38980");
extern char D_01e37ec0_0cf60[] asm("D_01e37ec0");
extern int D_00366164_0cf60 asm("D_00366164");
extern int D_00366174_0cf60 asm("D_00366174");
extern int D_003660e0_0cf60[] asm("D_003660e0");
extern int func_0030a2d0_0cf60(int) asm("func_0030a2d0");
extern int func_0030a300_0cf60(void) asm("func_0030a300");
extern int func_00305620_0cf60(SemaParam_0cf60 *) asm("func_00305620");
extern int func_00305630_0cf60(int) asm("func_00305630");
extern int func_00305640_0cf60(int) asm("func_00305640");
extern int func_00305660_0cf60(int) asm("func_00305660");
extern FdEnt_0cf60 *func_00309e50_0cf60(int) asm("func_00309e50");
extern int func_00309d60_0cf60(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry) asm("func_00309d60");
s64_0cf60 sceLseek64(int fd, s64_0cf60 off, int whence)
{
    Ls64Pk_0cf60 *q = (Ls64Pk_0cf60 *)&D_01e37280_0cf60;
    SemaParam_0cf60 sp;
    s64_0cf60 res;
    int busy, nw, i, m, s, v;
    FdEnt_0cf60 *e = func_00309e50_0cf60(fd);
    func_0030a2d0_0cf60(22);
    if (D_00366164_0cf60 == 0 || e == 0 || (busy = e->busy) == 0) {
        func_0030a300_0cf60();
        return -9;
    }
    q->fd = e->fd;
    q->off = off;
    q->whence = whence;
    q->idx = e - D_01e38780_0cf60;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioLseek64Sema";
    s = func_00305620_0cf60(&sp);
    q->res = &res;
    q->rsize = 8;
    nw = busy & 0x8000;
    D_01e37280_0cf60.sema = s;
    if (nw) {
        func_00305660_0cf60(D_00366174_0cf60);
        
        { register int n asm("$16") = nw; i = 0; asm("" : "+r"(n) : "r"(i)); busy = n; }
        for (; i < 32; i++) {
            if (D_003660e0_0cf60[i] == -1) {
                D_003660e0_0cf60[i] = q->sema;
                q->sema = -q->sema;
                break;
            }
        }
        func_00305640_0cf60(D_00366174_0cf60);
    } else {
        int z = 0; do { } while (z); busy = z; 
    }
    if (func_00309d60_0cf60(D_01e38980_0cf60, 22, 0, &D_01e37280_0cf60, 32, D_01e37ec0_0cf60, 4, 0, 0, busy) < 0) {
        func_00305630_0cf60(s);
        func_0030a300_0cf60();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0_0cf60 | 0x20000000);
    func_0030a300_0cf60();
    if (v == 0) {
        func_00305630_0cf60(s);
        return -11;
    }
    if (busy) {
        func_00305630_0cf60(s);
        return 0;
    }
    func_00305660_0cf60(s);
    func_00305630_0cf60(s);
    return res;
}

/* 0030d1a0 sceDevctl (was src/sdk/sdk_w1724.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0d1a0;
typedef struct { int sema; int *res; int rsize; char name[1024]; char name2[1024]; char arg[1024]; int arglen; } DevPk_0d1a0;
typedef struct { int sema; int *res; int rsize; char name[1024]; char name2[1024]; char arg[1024]; int flag; int arglen; } MntPk_0d1a0;
typedef struct { int sema; int *res; int rsize; char name[1024]; char arg[1024]; int cmd; unsigned int arglen; void *buf; unsigned int buflen; } DctlPk_0d1a0;
typedef union { DevPk_0d1a0 dev; MntPk_0d1a0 mnt; DctlPk_0d1a0 dctl; } StdioPk_0d1a0;
extern StdioPk_0d1a0 D_01e37280_0d1a0 asm("D_01e37280");
extern char D_01e37ec0_0d1a0[] asm("D_01e37ec0");
extern char D_01e38980_0d1a0[] asm("D_01e38980");
extern int D_00366164_0d1a0 asm("D_00366164");
extern int func_0030a2d0_0d1a0(int) asm("func_0030a2d0");
extern void func_0030a300_0d1a0(void) asm("func_0030a300");
extern int func_0030a3f8_0d1a0(void) asm("func_0030a3f8");
extern int func_00305620_0d1a0(SemaParam_0d1a0 *) asm("func_00305620");
extern int func_00305630_0d1a0(int) asm("func_00305630");
extern int func_00305660_0d1a0(int) asm("func_00305660");
extern void func_00308a80_0d1a0(void *, int) asm("func_00308a80");
extern int func_00309d60_0d1a0(void *, int, int, void *, int, void *, int, void *, void *, int) asm("func_00309d60");
int sceDevctl(const char *name, int cmd, void *arg, unsigned int arglen, void *buf, unsigned int buflen)
{
    DctlPk_0d1a0 *p = &D_01e37280_0d1a0.dctl;
    SemaParam_0d1a0 sp;
    int res;
    int i, s, v, fno;
    unsigned int j;
    func_0030a2d0_0d1a0(23);
    if (D_00366164_0d1a0 == 0)
        func_0030a3f8_0d1a0();
    for (i = 0; i < 1024; i++)
        if ((p->name[i] = name[i]) == 0)
            break;
    if (i == 1024)
        p->name[1023] = 0;
    if (arglen > 1024 || buflen > 1024) {
        func_0030a300_0d1a0();
        return -22;
    }
    if (cmd == 0x4601) {
        if (((int *)arg)[1] == 0) {
            func_0030a300_0d1a0();
            return 0;
        }
        if (((int *)arg)[3] == 0) {
            func_0030a300_0d1a0();
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
    s = func_00305620_0d1a0(&sp);
    p->buflen = buflen;
    p->res = &res;
    p->rsize = 4;
    p->buf = buf;
    p->sema = s;
    if (cmd == 0x4601) {
        fno = 28;
        func_00308a80_0d1a0(((void **)arg)[2], ((int *)arg)[1] * ((int *)arg)[3]);
    } else
        fno = 23;
    func_00308a80_0d1a0(&D_01e37280_0d1a0.dctl, 2076);
    if (func_00309d60_0d1a0(D_01e38980_0d1a0, fno, 0, &D_01e37280_0d1a0.dctl, 2076, D_01e37ec0_0d1a0, 4, 0, 0, 0) < 0) {
        func_00305630_0d1a0(s);
        func_0030a300_0d1a0();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0_0d1a0 | 0x20000000);
    func_0030a300_0d1a0();
    if (v == 0) {
        func_00305630_0d1a0(s);
        return -11;
    }
    func_00305660_0d1a0(s);
    func_00305630_0d1a0(s);
    return res;
}

/* 0030d448 sceSymlink (was src/sdk/sdk_w1334.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0d448;
typedef struct { int sema; int *res; int rsize; char name[1024]; char name2[1024]; } SymPk_0d448;
extern SymPk_0d448 D_01e37280_0d448 asm("D_01e37280");
extern char D_01e38980_0d448[] asm("D_01e38980");
extern char D_01e37ec0_0d448[] asm("D_01e37ec0");
extern int D_00366164_0d448 asm("D_00366164");
extern int func_0030a2d0_0d448(int) asm("func_0030a2d0");
extern int func_0030a300_0d448(void) asm("func_0030a300");
extern int func_0030a3f8_0d448(void) asm("func_0030a3f8");
extern int func_00305620_0d448(SemaParam_0d448 *) asm("func_00305620");
extern int func_00305630_0d448(int) asm("func_00305630");
extern int func_00305660_0d448(int) asm("func_00305660");
extern int func_00309d60_0d448(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry) asm("func_00309d60");
int sceSymlink(const char *a, const char *b)
{
    SymPk_0d448 *p = &D_01e37280_0d448;
    SemaParam_0d448 sp;
    int res;
    int i, s, v;
    func_0030a2d0_0d448(17);
    if (D_00366164_0d448 == 0)
        func_0030a3f8_0d448();
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
    s = func_00305620_0d448(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    if (func_00309d60_0d448(D_01e38980_0d448, 24, 0, &D_01e37280_0d448, 2060, D_01e37ec0_0d448, 4, 0, 0, 0) < 0) {
        func_00305630_0d448(s);
        func_0030a300_0d448();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0_0d448 | 0x20000000);
    func_0030a300_0d448();
    if (v == 0) {
        func_00305630_0d448(s);
        return -11;
    }
    func_00305660_0d448(s);
    func_00305630_0d448(s);
    return res;
}

/* 0030d640 sceReadlink (was src/sdk/sdk_w1334.c) */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam_0d640;
typedef struct { int sema; int *res; int rsize; char name[1024]; char name2[1024]; } SymPk_0d640;
typedef struct { int sema; int *res; int rsize; int len; void *buf; char name[1024]; } RlPk_0d640;
extern SymPk_0d640 D_01e37280_0d640 asm("D_01e37280");
extern char D_01e38980_0d640[] asm("D_01e38980");
extern char D_01e37ec0_0d640[] asm("D_01e37ec0");
extern int D_00366164_0d640 asm("D_00366164");
extern int func_0030a2d0_0d640(int) asm("func_0030a2d0");
extern int func_0030a300_0d640(void) asm("func_0030a300");
extern int func_0030a3f8_0d640(void) asm("func_0030a3f8");
extern int func_00305620_0d640(SemaParam_0d640 *) asm("func_00305620");
extern int func_00305630_0d640(int) asm("func_00305630");
extern int func_00305660_0d640(int) asm("func_00305660");
extern void func_00308a80_0d640(void *, int) asm("func_00308a80");
extern int func_00309d60_0d640(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry) asm("func_00309d60");
int sceReadlink(const char *a, void *buf, unsigned int len)
{
    RlPk_0d640 *p = (RlPk_0d640 *)&D_01e37280_0d640;
    SemaParam_0d640 sp;
    int res;
    int i, s, v;
    func_0030a2d0_0d640(17);
    if (D_00366164_0d640 == 0)
        func_0030a3f8_0d640();
    for (i = 0; i < 1024; i++)
        if ((p->name[i] = a[i]) == 0)
            break;
    if (i == 1024)
        p->name[1023] = 0;
    if (len >= 1024)
        len = 1023;
    p->buf = buf;
    p->len = len;
    func_00308a80_0d640(buf, len);
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioReadlinkSema";
    s = func_00305620_0d640(&sp);
    p->res = &res;
    p->sema = s;
    p->rsize = 4;
    if (func_00309d60_0d640(D_01e38980_0d640, 25, 0, &D_01e37280_0d640, 2060, D_01e37ec0_0d640, 4, 0, 0, 0) < 0) {
        func_00305630_0d640(s);
        func_0030a300_0d640();
        return -11;
    }
    v = *(int *)((unsigned int)D_01e37ec0_0d640 | 0x20000000);
    func_0030a300_0d640();
    if (v == 0) {
        func_00305630_0d640(s);
        return -11;
    }
    func_00305660_0d640(s);
    func_00305630_0d640(s);
    return res;
}

