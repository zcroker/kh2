/* libkernl_00308f00.c: Sony PS2 Runtime Library 3.0.0 libkernl: sifrpc (handlers, GetOtherData, BindRpc), 0x308f00-0x3094b4.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
extern int isceSifSendCmd(unsigned int, void *, int, int, int, int);
extern int sceSifSendCmd(unsigned int, void *, int, void *, void *, int);
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } SemaParam;
extern int func_00305620(SemaParam *);
extern int func_00305630(int);
extern int func_00305660(int);
extern char D_01e37200[];
extern void func_00308da0(void *);

/* ---- 0x308f00 */
typedef struct { char pad[0x24]; int x, y, z; } Arg;
int func_00308f00(int a, int b, int c, Arg *d)
{
    if (isceSifSendCmd(0x80000008, d, 64, d->x, d->y, d->z)) return 0;
    return 0x800;
}

/* ---- 0x308f40 */
typedef struct { int pad[4]; unsigned int x10; int x14; int x18; int x1c; int x20; int x24; int x28; } R1328;
typedef struct { int pad[5]; int x14; int x18; int x1c; int x20; int x24; int x28; int x2c; } P1328;
extern P1328 *func_00308df0_p(int, unsigned int) asm("func_00308df0");
extern P1328 *func_00308dc0_p(int) asm("func_00308dc0");
extern void func_00310b70_p(int, void *, P1328 *) asm("func_00310b70");
extern void D_00308f00(void);
void func_00308f40(R1328 *r, int a)
{
    P1328 *p;
    if (r->x10 & 4)
        p = func_00308df0_p(a, r->x10 >> 16);
    else
        p = func_00308dc0_p(a);
    {int t14 = r->x14, t1c = r->x1c;
    p->x14 = t14;
    p->x1c = t1c;}
    p->x20 = 0x8000000c;
    p->x24 = r->x20;
    p->x28 = r->x24;
    p->x2c = r->x28;
    if (isceSifSendCmd(0x80000008, p, 0x40, r->x20, r->x24, r->x28) == 0)
        func_00310b70_p(0x800, D_00308f00, p);
}

/* ---- 0x309010: sceSifGetOtherData */
typedef struct { int x0, x4, x8, xc, x10; void *pkt_addr; int rec_id; void *paddr; int a, b, c; } RpcPkt;
typedef struct { RpcPkt *pkt; int rec_id; int sema; } RpcCmd;
extern RpcPkt *func_00308cf8_r(void *) asm("func_00308cf8");
int sceSifGetOtherData(RpcCmd *cd, int a, int b, int c, int mode)
{
    SemaParam sp;
    RpcPkt *p = func_00308cf8_r(D_01e37200);
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
        sp.option = (unsigned int)"SceSifrpcGod";
        cd->sema = func_00305620(&sp);
        if (cd->sema < 0) {
            func_00308da0(p);
            return -3;
        }
        if (sceSifSendCmd(0x8000000c, p, 64, 0, 0, 0) == 0) {
            func_00308da0(p);
            func_00305630(cd->sema);
            return -2;
        }
        func_00305660(cd->sema);
        func_00305630(cd->sema);
        return 0;
    }
    cd->sema = -1;
    if (sceSifSendCmd(0x8000000c, p, 64, 0, 0, 0) == 0) {
        func_00308da0(p);
        return -2;
    }
    return 0;
}

/* ---- 0x309178 */
typedef struct N { int k; char pad[0x34]; struct N *next; } Nd;
typedef struct L { int p0, p4; Nd *head; int pc, p10; struct L *next; char pad[0x10]; struct L *sub; } Ls;
Nd* func_00309178(int k, Ls *l)
{
    Nd *n;
    for (l = l->sub; l; l = l->next)
        for (n = l->head; n; n = n->next)
            if (n->k == k) return n;
    return 0;
}

/* ---- 0x3091c8 */
int func_003091c8(int a, int b, int c, int d)
{
    if (isceSifSendCmd(0x80000008, (void *)d, 64, 0, 0, 0)) return 0;
    return 0x800;
}

/* ---- 0x309208 */
typedef struct { int x0, x4, x8, xc, x10, x14, x18, x1c, x20, x24, x28; } Pk;
extern Pk *func_00308dc0_k(int) asm("func_00308dc0");
extern Pk *func_00309178_k(int, int) asm("func_00309178");
extern int func_00310b70_k(int, void (*)(void), Pk *) asm("func_00310b70");
extern void func_003091c8_v(void) asm("func_003091c8");
void func_00309208(Pk *r, int a)
{
    Pk *p = func_00308dc0_k(a);
    Pk *q;
    int t14 = r->x14, t1c = r->x1c;
    p->x1c = t1c;
    p->x14 = t14;
    p->x20 = 0x80000009;
    q = func_00309178_k(r->x20, a);
    if (q == 0) {
        p->x24 = 0;
        p->x28 = 0;
    } else {
        p->x24 = (int)q;
        p->x28 = q->x8;
    }
    if (isceSifSendCmd(0x80000008, p, 64, 0, 0, 0) == 0)
        func_00310b70_k(2048, func_003091c8_v, p);
}

/* ---- 0x3092d8: sceSifBindRpc */
typedef struct { void *pkt_addr; int rpc_id; int sema_id; int mode; int command; int buf; int cbuf; int end_func; int end_param; int server; } RpcClient;
typedef struct { int hdr[4]; int rec_id; int pkt_addr; int rpc_id; int client; int fno; } BindPkt;
extern BindPkt *func_00308cf8_b(void *) asm("func_00308cf8");
int sceSifBindRpc(RpcClient *cd, int sid, int mode)
{
    SemaParam sp;
    BindPkt *bind;
    cd->command = 0;
    cd->server = 0;
    bind = func_00308cf8_b(D_01e37200);
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
        if (sceSifSendCmd(0x80000009, bind, 64, 0, 0, 0) == 0) {
            func_00308da0(bind);
            func_00305630(cd->sema_id);
            return -2;
        }
        func_00305660(cd->sema_id);
        func_00305630(cd->sema_id);
        return 0;
    }
    cd->sema_id = -1;
    if (sceSifSendCmd(0x80000009, bind, 64, 0, 0, 0) == 0) {
        func_00308da0(bind);
        return -2;
    }
    return 0;
}

/* ---- 0x309428 (gap): the server side of an rpc call request. The queue end is an int: its store then
 * stays before the int field copies (type-based aliasing), like the original. */
typedef struct SD {
    int x0, x4, x8; int size; int xc_10[3]; int client; int pkt_addr; int rpc_number; int receive; int rsize; int rmode;
    int rid; int x38; struct SD *link; struct QD *base;
} SD;
typedef struct { int x0, x4, x8, xc; int rid; int pkt_addr; int x18; int client; int rpc_number; int size; int receive; int rsize; int rmode; SD *sd; } CallPkt;
extern void func_003064e8(int);
typedef struct QD { int thread_id; int active; int x8; SD *start; int end; } QD;
void func_00309428(CallPkt *req, void *data)
{
    SD *sd = req->sd;
    QD *qd = sd->base;
    if (qd->start == 0) qd->start = sd; else ((SD *)qd->end)->link = sd;
    qd->end = (int)sd;

    {
    int pa = req->pkt_addr, cl = req->client;
    sd->pkt_addr = pa;
    sd->client = cl;
    }
    sd->rpc_number = req->rpc_number;
    sd->size = req->size;
    sd->receive = req->receive;
    sd->rsize = req->rsize;
    sd->rmode = req->rmode;
    sd->rid = req->rid;
    if (qd->thread_id >= 0 && !qd->active) func_003064e8(qd->thread_id);
}
