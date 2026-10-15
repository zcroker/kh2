/* libkernl (sifcmd) and misc Sony PS2 Runtime Library 3.0.0 */
typedef struct { unsigned int src; unsigned int dest; int size; unsigned int attr; } Dma;
typedef struct { unsigned int size; unsigned int dest; int cid; unsigned int opt; } Hdr;
extern void func_00308a80(void *, int);
extern int func_003059f0(Dma *, int);
extern int func_003059e0(Dma *, int);
extern unsigned int D_01e357e0;
unsigned int func_00308780(int cid, int mode, Hdr *pkt, unsigned int pktsize, void *src, void *dest, int size)
{
    Dma dma[2];
    int count;
    if (pktsize - 16 > 96)
        return 0;
    count = 0;
    if (size > 0) {
        pkt->size = (pkt->size & 0xff) | (size << 8);
        dma[count].src = (unsigned int)src;
        dma[count].dest = (unsigned int)dest;
        dma[count].size = size;
        dma[count].attr = 0;
        pkt->dest = (unsigned int)dest;
        count++;
        if (mode & 4)
            func_00308a80(src, size);
    } else {
        pkt->size = pkt->size & 0xff;
        pkt->dest = 0;
    }
    dma[count].src = (unsigned int)pkt;
    dma[count].dest = D_01e357e0;
    dma[count].size = pktsize;
    pkt->cid = cid;
    *(unsigned char *)pkt = pktsize;
    dma[count].attr = 0x44;
    count++;
    func_00308a80(pkt, pktsize);
    if (mode & 1)
        return func_003059f0(dma, count);
    else
        return func_003059e0(dma, count);
}

/* libkernl sifrpc: sceSifBindRpc */
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } SemaParam;
typedef struct { void *pkt_addr; int rpc_id; int sema_id; int mode; int command; int buf; int cbuf; int end_func; int end_param; int server; } RpcClient;
typedef struct { int hdr[4]; int rec_id; int pkt_addr; int rpc_id; int client; int fno; } BindPkt;
extern BindPkt *func_00308cf8(void *);
extern void func_00308da0(void *);
extern int func_003088b8(unsigned int, void *, int, void *, void *, int);
extern int func_00305630(int);
extern int func_00305660(int);
extern char D_01e37200[];
extern int func_00305620(SemaParam *);
int func_003092d8(RpcClient *cd, int sid, int mode)
{
    SemaParam sp;
    BindPkt *bind;
    cd->command = 0;
    cd->server = 0;
    bind = func_00308cf8(D_01e37200);
    if (bind == 0)
        return -1;
    cd->pkt_addr = bind;
    cd->rpc_id = bind->rpc_id;
    bind->fno = sid;
    bind->pkt_addr = (int)bind;
    bind->client = (int)cd;
    if (!(mode & 1)) {
        sp.max_count = 1;
        sp.init_count = 0;
        sp.option = (unsigned int)"SceSifrpcBind";
        cd->sema_id = func_00305620(&sp);
        if (cd->sema_id < 0) {
            func_00308da0(bind);
            return -3;
        }
        if (func_003088b8(0x80000009, bind, 64, 0, 0, 0) == 0) {
            func_00308da0(bind);
            func_00305630(cd->sema_id);
            return -2;
        }
        func_00305660(cd->sema_id);
        func_00305630(cd->sema_id);
        return 0;
    }
    cd->sema_id = -1;
    if (func_003088b8(0x80000009, bind, 64, 0, 0, 0) == 0) {
        func_00308da0(bind);
        return -2;
    }
    return 0;
}

/* libkernl fileio (sif rpc client) */
extern int func_00309c58(void);
extern int func_0030a2d0(int);
extern void func_0030a300(void);
extern void func_0030a3f8(void);
extern int func_0030a600(void);
extern int func_00309d60(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry);
extern int D_00366164;
extern int D_01e37280[];
extern char D_01e37ec0[];
extern char D_01e38980[];
int func_0030a6c8(unsigned int addr, unsigned int size)
{
    int r;
    func_0030a2d0(0xfe);
    if (D_00366164 == 0)
        func_0030a3f8();
    if (func_0030a600()) {
        func_0030a300();
        return 0xfffefffc;
    }
    if (func_00309c58()) {
        func_0030a300();
        return -16;
    }
    if ((addr & 0x3fff) || addr == 0 || addr > 0xfffff || size == 0 || size > 32) {
        func_0030a300();
        return -22;
    }
    D_01e37280[0] = addr;
    D_01e37280[1] = size;
    if (func_00309d60(D_01e38980, 0xfe, 0, D_01e37280, 8, D_01e37ec0, 4, 0, 0, 0) < 0) {
        func_0030a300();
        return -11;
    }
    r = *(int *)((unsigned int)D_01e37ec0 | 0x20000000);
    func_0030a300();
    return r;
}

typedef struct { int fd; int valid; } FioFile;
extern FioFile *func_00309e50(int);
int func_0030c388(int fd, void *buf)
{
    SemaParam sp;
    int res;
    int sema;
    int r;
    FioFile *f;
    int *p = D_01e37280;

    f = func_00309e50(fd);
    func_0030a2d0(11);
    if (D_00366164 == 0 || f == 0 || f->valid == 0) {
        func_0030a300();
        return -9;
    }
    p[3] = f->fd;
    p[4] = (int)buf;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = (unsigned int)"SceStdioDreadSema";
    sema = func_00305620(&sp);
    p[0] = sema;
    p[1] = (int)&res;
    p[2] = 4;
    if (func_00309d60(D_01e38980, 11, 0, p, 32, D_01e37ec0, 4, 0, 0, 0) < 0) {
        func_00305660(sema);
        func_0030a300();
        return -11;
    }
    r = *(int *)((unsigned int)D_01e37ec0 | 0x20000000);
    func_0030a300();
    if (r == 0) {
        func_00305630(sema);
        return -11;
    }
    func_00305660(sema);
    func_00305630(sema);
    return res;
}

/* libkernl timer: InitTimer */
typedef struct TBlk { struct TBlk *next; int pad[15]; } TBlk;
typedef struct { unsigned long long x0; int handler; int xc; int count; TBlk *free; int x18; } TMgr;
extern TMgr D_00367118;
extern TBlk D_01e38f00[128];
extern void func_002fde18(void *, int, int);
extern void func_00310990(void);
extern int func_00305310(int, void *, int, void *);
extern int func_0030fc60();
extern int func_0030edb0(void);
extern void func_0030ee00(void);
extern void func_0030f690(int);
extern void func_0030f6a0(int);
extern void func_0030f6b0(int);
extern void func_00306168(int);
int func_0030f6c0(int mode)
{
    TMgr *m = &D_00367118;
    int i;
    int h;
    int intr;
    unsigned int t;

    if (m->handler >= 0)
        return 0x80008001;
    D_00367118.x0 = 0;
    m->count = 0;
    func_002fde18(D_01e38f00, 0, 8192);
    m->free = D_01e38f00;
    for (i = 127; i >= 0; i--)
        D_01e38f00[i].next = &D_01e38f00[i + 1];
    D_01e38f00[127].next = 0;
    func_00310990();
    h = func_00305310(11, func_0030fc60, 0, 0);
    if (h < 0)
        return 0x80009021;
    D_00367118.handler = h;
    intr = func_0030edb0();
    t = *(volatile unsigned int *)0x10001010;
    t = (t & ~3) | mode;
    t |= 0x300;
    if (!(t & 0x80)) {
        func_0030f690(0);
        t |= 0xc80;
        func_0030f6b0(0xffff);
    }
    func_0030f6a0(t);
    func_00306168(11);
    if (intr)
        func_0030ee00();
    return 0;
}

/* libkernl sif: sceSifResetIop */
typedef struct { unsigned int psize:8; unsigned int dsize:24; unsigned int dest; unsigned int cid; unsigned int opt; } RHdr;
typedef struct { RHdr hdr; int arglen; int mode; char arg[80]; } ResetPkt;
extern ResetPkt D_01e38e80 __attribute__((aligned(64)));
extern void func_00310f38(int, int);
extern void func_003058f0(void);
extern unsigned int func_00305a30(int);
extern void func_00305a20(unsigned int, unsigned int);
int func_0030ead0(char *arg, int mode)
{
    Dma dma;
    unsigned int dest;
    int i;

    func_00310f38(0, 0);
    func_00310f38(1, 0);
    func_003058f0();
    dest = func_00305a30(0x80000000);
    D_01e38e80.mode = mode;
    for (i = 0; arg[i]; i++)
        D_01e38e80.arg[i] = arg[i];
    D_01e38e80.hdr.dest = 0;
    D_01e38e80.arglen = i;
    D_01e38e80.hdr.cid = 0x80000003;
    D_01e38e80.hdr.dsize = 0;
    D_01e38e80.hdr.psize = 104;
    dma.src = (unsigned int)&D_01e38e80;
    dma.dest = dest;
    dma.size = 104;
    dma.attr = 0x44;
    func_00308a80(&D_01e38e80, 104);
    func_00305a20(4, 0x40000);
    if (func_003059e0(&dma, 1) != 0) {
        func_00305a20(4, 0x10000);
        func_00305a20(4, 0x20000);
        func_00305a20(0x80000002, 0);
        func_00305a20(0x80000000, 0);
        return 1;
    }
    return 0;
}

/* libmc */
typedef struct { int pad[9]; int f; } McCd;
typedef struct { int port; int slot; int mode; int maxent; void *table; char name[1024]; } McArg;
extern McCd D_01e33480;
extern McArg D_01e33530;
extern char D_01e33a40[];
extern int D_01e34a40[];
extern int D_0036594c;
extern int D_00365948;
extern int func_00305670(int);
extern int func_00305640(int);
extern char *func_002ff6f0(char *, const char *, int);
extern int func_003094b8(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern void func_002fbba8(void *);
extern void func_002fc7d8(void *);
int func_002fc688(int port, int slot, const char *name, int mode, int maxent, void *table)
{
    if (!D_01e33480.f)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    if (name == 0 || *name == 0) {
        func_00305640(D_0036594c);
        return -210;
    }
    D_01e33530.port = port;
    D_01e33530.slot = slot;
    D_01e33530.mode = mode;
    D_01e33530.maxent = maxent;
    D_01e33530.table = table;
    func_002ff6f0(D_01e33530.name, name, 1023);
    D_01e33530.name[1023] = 0;
    if (maxent >= 0)
        func_00308a80(table, maxent << 6);
    if (func_003094b8(&D_01e33480, 13, 1, &D_01e33530, 1044, D_01e34a40, 4, func_002fbba8, 0)) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 13;
    return 0;
}

int func_002fc868(int port, int slot, const char *name, void *endp)
{
    if (!D_01e33480.f)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    if (name == 0 || *name == 0) {
        func_00305640(D_0036594c);
        return -210;
    }
    D_01e33530.port = port;
    D_01e33530.slot = slot;
    D_01e33530.table = D_01e33a40;
    func_002ff6f0(D_01e33530.name, name, 1023);
    D_01e33530.name[1023] = 0;
    func_00308a80(D_01e33a40, 1024);
    if (func_003094b8(&D_01e33480, 12, 1, &D_01e33530, 1044, D_01e34a40, 4, func_002fc7d8, endp)) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 12;
    return 0;
}

/* libpad2 */
typedef union { struct { unsigned long a:14; unsigned long b:2; unsigned long c:8; unsigned long d:8; } s; int i; } PadCmd;
typedef struct { int x0; int active; char pad[812]; } PadEnt;
extern PadEnt D_01e2fe48[];
extern int func_002f62b8(int);
extern int func_002f63e0(int);
extern unsigned char *func_002f6378(int);
extern void func_002f6240(int);
extern int func_002f5b20(int, int, int *, unsigned char *);
int func_002f6020(int port)
{
    PadCmd cmd;
    unsigned char res;
    int tmp;
    unsigned char *p;

    if (D_01e2fe48[port].active == 0) {
        if (func_002f62b8(port) < 0)
            return 0;
    }
    if (func_002f63e0(port)) {
        p = func_002f6378(port);
        if (((int *)p)[1] == 0) {
            if (func_002f62b8(port) < 0)
                goto fail;
        }
        res = *p;
        goto out;
    } else {
        cmd.s.a = 12;
        cmd.s.b = 2;
        cmd.s.c = 1;
        cmd.s.d = 1;
        if (func_002f5b20(port, cmd.i, &tmp, &res) >= 0)
            goto out;
    }
fail:
    D_01e2fe48[port].active = 0;
    func_002f6240(port);
    return 0;
out:
    return res;
}
