/* Sony PS2 Runtime Library 3.0.0: libdbc (SendData3), libcdvd (stream/async rpc), libkernl (sif cmd/rpc, deci2 kprintf), iop file rpc. ee-gcc 2.9-991111 -O2 -G0. */
typedef unsigned char u8;
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } SemaParam;
struct SifClient { u8 pad[0x24]; void *serve; };
extern int func_003094b8(void *, int, int, void *, int, void *, int, void *, void *);
extern int func_002f5c48(const char *, ...);
extern int func_00305660(int);
extern int func_00305640(int);
extern int func_00305670(int);
extern int func_003058a0(int);
extern int func_00305620(SemaParam *);
extern int func_00305630(int);
extern int func_0030edb0(void);
extern void func_0030ee00(void);

/* libdbc: sceDbcSendData3 */
extern int func_003096b8(void *);
extern char D_01e2d9d0[];
extern int D_01e2fe40;
typedef struct { int a; int b; int size; unsigned char data[8324]; } DbcSend3;
extern DbcSend3 D_01e2db40;
int func_002f59c8(int a, int b, int *size, unsigned char *buf, void *end)
{
    DbcSend3 *s;
    int i;
    if (*size > 8320) {
        func_002f5c48("libdbc: SendData3 data length too long [%d]\n", *size);
        return 0;
    }
    func_00305660(D_01e2fe40);
    if (func_003096b8(D_01e2d9d0) == 1) {
        func_002f5c48("dbcman : SendData3 BUSY\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    s = &D_01e2db40;
    D_01e2db40.a = a;
    s->b = b;
    s->size = *size;
    for (i = 0; i < *size; i++)
        s->data[i] = buf[i];
    if (func_003094b8(D_01e2d9d0, 0x8000131c, 1, &D_01e2db40, 8336, &D_01e2db40, 8336, end, 0) < 0) {
        func_00305640(D_01e2fe40);
        return 0;
    }
    func_00305640(D_01e2fe40);
    return 1;
}

/* libcdvd: stream/async rpc requests */
struct StRq { int a; int x4; int x8; int rest; int x10; unsigned int n; u8 *ptr; int x1c; u8 data[16]; };
struct RpcSend2 { int a; int b; int c; int pad; void *ptr; char name[1024]; };
struct Name32 { u8 pad[32]; char name[32]; };
extern struct SifClient D_01e33480;
extern struct StRq D_01e33500;
extern struct RpcSend2 D_01e33530;
extern struct Name32 D_01e334c0;
extern u8 D_01e34a40[];
extern int D_00365948;
extern int D_0036594c;
extern char *func_002ff6f0(char *, const char *, unsigned int);
extern void func_002fbba8(void *);
int func_002fc200(int a, u8 *buf, int size)
{
    unsigned int i;
    struct StRq *q;
    if (D_01e33480.serve == 0) return -100;
    if (func_00305670(D_0036594c) < 0) return -200;
    q = &D_01e33500;
    D_01e33500.a = a;
    if (size <= 16) {
        q->n = size;
        q->rest = 0;
        q->ptr = 0;
    } else {
        int n = ((unsigned int)(buf - 1) & 0xfffffff0) + 16 - (unsigned int)buf;
        q->n = n;
        q->rest = size - n;
        q->ptr = buf + n;
    }
    for (i = 0; i < D_01e33500.n; i++)
        D_01e33500.data[i] = buf[i];
    func_003058a0(0);
    if (func_003094b8(&D_01e33480, 6, 1, &D_01e33500, 48, D_01e34a40, 4, func_002fbba8, 0) != 0) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 6;
    return 0;
}

int func_002fce28(int a, int b, const char *name, const char *name2)
{
    struct SifClient *cd = &D_01e33480;
    struct RpcSend2 *s;
    if (cd->serve == 0) return -100;
    if (func_00305670(D_0036594c) < 0) return -200;
    if (name == 0 || *name == 0 || name2 == 0) { func_00305640(D_0036594c); return -210; }
    s = &D_01e33530;
    D_01e33530.a = a;
    s->b = b;
    s->c = 16;
    func_002ff6f0(s->name, name, 1023);
    s->name[1023] = 0;
    func_002ff6f0(D_01e334c0.name, name2, 32);
    s->ptr = &D_01e334c0;
    func_003058a0(0);
    if (func_003094b8(cd, 14, 1, s, 1044, D_01e34a40, 4, func_002fbba8, 0) != 0) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 19;
    return 0;
}

/* libkernl: sif rpc packet send (sceSifGetOtherData-style) */
typedef struct { int x0, x4, x8, xc, x10; void *pkt_addr; int rec_id; void *paddr; int a, b, c; } RpcPkt;
typedef struct { RpcPkt *pkt; int rec_id; int sema; } RpcCmd;
extern char D_01e37200[];
extern char D_003780d0[];
extern RpcPkt *func_00308cf8(void *);
extern void func_00308da0(void *);
extern int func_003088b8(unsigned int, void *, int, void *, int, void *);
int func_00309010(RpcCmd *cd, int a, int b, int c, int mode)
{
    SemaParam sp;
    RpcPkt *p = func_00308cf8(D_01e37200);
    if (p == 0)
        return -1;
    cd->pkt = p;
    cd->rec_id = p->rec_id;
    p->a = a;
    p->b = b;
    p->c = c;
    p->pkt_addr = p;
    p->paddr = cd;
    if (!(mode & 1)) {
        sp.max_count = 1;
        sp.init_count = 0;
        sp.option = (unsigned int)D_003780d0;
        cd->sema = func_00305620(&sp);
        if (cd->sema < 0) {
            func_00308da0(p);
            return -3;
        }
        if (func_003088b8(0x8000000c, p, 64, 0, 0, 0) == 0) {
            func_00308da0(p);
            func_00305630(cd->sema);
            return -2;
        }
        func_00305660(cd->sema);
        func_00305630(cd->sema);
        return 0;
    }
    cd->sema = -1;
    if (func_003088b8(0x8000000c, p, 64, 0, 0, 0) == 0) {
        func_00308da0(p);
        return -2;
    }
    return 0;
}

/* iop file rpc (fd request 10) */
typedef struct { int fd; int busy; int x8; int xc; } FdEnt;
extern FdEnt D_01e38780[];
typedef struct { int sema; int *res; int size; int fd; int idx; } Req10;
extern int D_00366164;
extern Req10 D_01e37280;
extern char D_01e37ec0[];
extern char D_01e38980[];
extern char D_003782a8[];
extern char D_003781b8[];
extern FdEnt *func_00309e50(int);
extern int func_0030a2d0(int);
extern void func_0030a300(void);
extern int func_00309d60(void *, int, int, void *, int, void *, int, void *, void *, int);
int func_0030c220(int fd)
{
    SemaParam sp;
    int res;
    int sema;
    int r;
    Req10 *q = &D_01e37280;
    FdEnt *e = func_00309e50(fd);
    func_0030a2d0(10);
    if (D_00366164 == 0 || e == 0 || e->busy == 0) {
        func_0030a300();
        return -9;
    }
    q->fd = e->fd;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)D_003782a8;
    sema = func_00305620(&sp);
    D_01e37280.sema = sema;
    q->res = &res;
    q->size = 4;
    if (func_00309d60(D_01e38980, 10, 0, q, 20, D_01e37ec0, 4, 0, 0, 0) < 0) {
        func_00305630(sema);
        func_0030a300();
        return -11;
    }
    e->busy = 0;
    r = *(int *)((unsigned int)D_01e37ec0 | 0x20000000);
    func_0030a300();
    if (r == 0) {
        func_00305630(sema);
        return -11;
    }
    func_00305660(sema);
    func_00305630(sema);
    if (res < 0) return res;
    return 0;
}

int func_0030ab88(int fd)
{
    SemaParam sp;
    int res;
    int sema;
    int r;
    Req10 *q = &D_01e37280;
    FdEnt *e = func_00309e50(fd);
    func_0030a2d0(1);
    if (D_00366164 == 0 || e == 0 || e->busy == 0) {
        func_0030a300();
        return -9;
    }
    q->fd = e->fd;
    q->idx = e - D_01e38780;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)D_003781b8;
    sema = func_00305620(&sp);
    D_01e37280.sema = sema;
    q->res = &res;
    q->size = 4;
    if (func_00309d60(D_01e38980, 1, 0, q, 20, D_01e37ec0, 4, 0, 0, 0) < 0) {
        func_00305630(sema);
        func_0030a300();
        return -11;
    }
    e->busy = 0;
    r = *(int *)((unsigned int)D_01e37ec0 | 0x20000000);
    func_0030a300();
    if (r == 0) {
        func_00305630(sema);
        return -11;
    }
    func_00305660(sema);
    func_00305630(sema);
    if (res < 0) return res;
    return 0;
}

/* libgraph: sceGsExecLoadImage */
typedef unsigned long u64 __attribute__((mode(DI)));
extern int func_003080d0(const char *, ...);
typedef struct { u64 w[10]; u64 giftag1; u64 x58; } GsLoadImage;
#define D2_CHCR ((volatile unsigned int *)0x1000a000)
#define D2_MADR ((volatile unsigned int *)0x1000a010)
#define D2_QWC  ((volatile unsigned int *)0x1000a020)
int func_002f2be0(GsLoadImage *lp, void *src)
{
    unsigned int i = 0;
    while (*D2_CHCR & 0x100) {
        if (i++ > 0x1000000)
            goto err;
    }
    *D2_QWC = 6;
    if (((unsigned int)lp & 0x70000000) == 0x70000000)
        *D2_MADR = ((unsigned int)lp & 0x0fffffff) | 0x80000000;
    else
        *D2_MADR = (unsigned int)lp & 0x0fffffff;
    *D2_CHCR = 0x101;
    while (*D2_CHCR & 0x100) {
        if (i++ > 0x1000000)
            goto err;
    }
    *D2_QWC = (int)(lp->giftag1 & 0x7fff);
    if (((unsigned int)src & 0x70000000) != 0x70000000)
        goto els;
    *D2_MADR = ((unsigned int)src & 0x0fffffff) | 0x80000000;
    goto done;
err:
    func_003080d0("sceGsExecLoadImage: DMA Ch.2 does not terminate\r\n");
    return -1;
els:
    *D2_MADR = (unsigned int)src & 0x0fffffff;
done:
    *D2_CHCR = 0x101;
    return 0;
}
