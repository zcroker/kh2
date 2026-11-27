/* libkernl_00309860.c: Sony PS2 Runtime Library 3.0.0 libkernl: sifrpc (request queue, ExecRequest) and the stdio/fileio client, 0x309860-0x30a3b0.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
extern int DIntr(void);
extern int EIntr(void);

/* ---- 0x309860 */
typedef struct M { char pad[0x38]; struct M *next; } M;
typedef struct { int a, b; M *head; } MH;
M* func_00309860(M *a, MH *l)
{
    M *p;
    DIntr();
    p = l->head;
    if (p == a) {
        l->head = p->next;
    } else {
        while (p) {
            if (p->next == a) { p->next = a->next; break; }
            p = p->next;
        }
    }
    EIntr();
    return p;
}

/* ---- 0x3098f8 */
typedef struct L2 { int pad[5]; struct L2 *next; } L2;
typedef struct { int pad[10]; L2 *head; } LH2;
extern LH2 D_01e37200_m asm("D_01e37200");
L2* func_003098f8(L2 *n)
{
    L2 *p;
    DIntr();
    p = D_01e37200_m.head;
    if (p == n) {
        D_01e37200_m.head = p->next;
    } else {
        while (p) {
            if (p->next == n) { p->next = n->next; break; }
            p = p->next;
        }
    }
    EIntr();
    return p;
}

/* ---- 0x309988 */
typedef struct Node { char pad[60]; struct Node *next; } Node;
typedef struct { int pad0; int ok; int pad8; Node *free; } Pool;
Node* func_00309988(Pool *q)
{
    Node *p;
    DIntr();
    p = q->free;
    if (p == 0)
        q->ok = 0;
    else {
        q->ok = 1;
        q->free = p->next;
    }
    EIntr();
    return p;
}

/* ---- 0x3099e0: sceSifExecRequest */
typedef struct { unsigned int data; unsigned int addr; unsigned int size; unsigned int mode; } DmaData_w3766;
typedef struct { int hdr[4]; int x10; int x14; int x18; void *client; int cid; } Rend_w3766;
typedef struct SD_w3766 {
    int command; void *(*func)(int, void *, int); void *buff; int size;
    void *cfunc; void *cbuff; int csize; void *client; void *paddr; int fno;
    void *receive; int rsize; int rmode; unsigned int rid;
} SD_w3766;
extern char D_01e37200_c[] asm("D_01e37200");
extern Rend_w3766 *func_00308df0_r(void *, int) asm("func_00308df0");
extern Rend_w3766 *func_00308dc0_r(void *) asm("func_00308dc0");
extern void func_00308a80(void *, int);
extern int sceSifSendCmd(int, void *, int, void *, void *, int);
extern int func_00308310_d(DmaData_w3766 *, int) asm("func_00308310");
/* sceSifExecRequest: run an RPC server function, write back its buffers, then send the reply packet (and receive data) to the IOP by DMA. */
void sceSifExecRequest(SD_w3766 *sd)
{
    Rend_w3766 *rend; int size = 0; void *rec; DmaData_w3766 dma[2]; int i, j, id;
    rec = sd->func(sd->fno, sd->buff, sd->size);
    if (rec)
        size = sd->rsize;
    if (sd->size > 0)
        func_00308a80(sd->buff, sd->size);
    if (size > 0)
        func_00308a80(rec, size);
    DIntr();
    if (sd->rid & 4)
        rend = func_00308df0_r(D_01e37200_c, sd->rid >> 16);
    else
        rend = func_00308dc0_r(D_01e37200_c);
    EIntr();
    rend->cid = 0x8000000a;
    rend->client = sd->client;
    if (sd->rmode) {
        while (!sceSifSendCmd(0x80000008, rend, 64, rec, sd->receive, size))
            ;
        return;
    }
    rend->x18 = 0;
    rend->x10 = 0;
    i = 0;
    if (size > 0) {
        i = 1;
        dma[0].data = (unsigned int)rec;
        dma[0].addr = (unsigned int)sd->receive;
        dma[0].size = size;
        dma[0].mode = 0;
    }
    dma[i].data = (unsigned int)rend;
    dma[i].addr = (unsigned int)sd->paddr;
    dma[i].size = 64;
    dma[i].mode = 0;
    i++;
    do { id = func_00308310_d(dma, i); if (id) break; j = 0x100000; while (--j != -1) ; } while (!id);
}

/* ---- 0x309ba8 */
extern int func_00309988_i(int) asm("func_00309988");
extern void sceSifExecRequest_i(int) asm("sceSifExecRequest");
extern void func_00305540(void);
void func_00309ba8(int a)
{
    int r;
    for (;;) {
        while ((r = func_00309988_i(a)) != 0) sceSifExecRequest_i(r);
        func_00305540();
    }
}

/* ---- 0x309be8 */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr, option; } SemaParam;
extern int func_00305620(SemaParam *);
extern int D_00366170, D_00366174;
void func_00309be8(void)
{
    SemaParam p;
    if (D_00366170 == -1) {
        p.init_count = 1;
        p.max_count = 1;
        p.option = (unsigned int)"SceStdioIobSema";
        D_00366170 = func_00305620(&p);
        p.option = (unsigned int)"SceStdioQueSema";
        D_00366174 = func_00305620(&p);
    }
}

/* ---- 0x309c58 */
extern int func_00305660(int);
extern int func_00305640(int);
typedef struct { int a; int b; int c; int d; } Ent;
extern Ent D_01e38780[];
int func_00309c58(void)
{
    int n = 0;
    Ent *p;
    func_00309be8();
    func_00305660(D_00366170);
    for (p = D_01e38780; p < D_01e38780 + 32; p++)
        if (p->b) n++;
    func_00305640(D_00366170);
    return n;
}

/* ---- 0x309cd8 */
Ent* func_00309cd8(void)
{
    Ent *e, *end;
    func_00309be8();
    func_00305660(D_00366170);
    e = D_01e38780;
    end = e + 32;
    for (; e < end; e++) {
        if (e->b == 0) {
            e->b = 0x10000000;
            func_00305640(D_00366170);
            return e;
        }
    }
    func_00305640(D_00366170);
    return 0;
}

/* ---- 0x309d60 */
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern int func_00306698(int) asm("_Z13func_00306698i");
int func_00309d60(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry)
{
    int i, d, r;
    i = 0;
    d = 1;
    do {
        r = (unsigned int)sceSifCallRpc(cd, fno, mode, send, ssize, recv, rsize, end, endp) >> 31;
        if (r == 0)
            break;
        if (noretry)
            break;
        func_00306698(d * 1000);
        if (d < 127)
            d *= 2;
        i++;
    } while (i < 101);
    return r;
}

/* ---- 0x309e50 */
extern int func_00309be8_i(void) asm("func_00309be8");
Ent* func_00309e50(unsigned int n) {
    Ent* p;
    int r;
    r = func_00309be8_i();
    func_00305660(D_00366170);
    if (n >= 32) {
        func_00305640(D_00366170);
        return 0;
    }
    p = &D_01e38780[n];
    func_00305640(D_00366170);
    return p;
}

/* ---- 0x309ec0: sce fileio RPC end callback (see the note below) */
typedef struct { int sema; int fno; void *dst; int size; void *p; unsigned int len; } EndHdr;
typedef struct { int n1; int n2; char *p1; char *p2; char d1[64]; char d2[64]; } RdTail;
typedef struct { void *dst; int len; } DstLen;
typedef struct { char b[1088]; } B1088;
extern B1088 D_01e37f00[];
extern int D_00366160;
extern int D_00366168;
extern int D_003660e0[32];
extern void *memcpy(void *, const void *, unsigned int);
extern int func_00305650(int);

/* sce fileio RPC end callback: copies each request's results back to the caller (by fno, jump
 * table 2..26), then either signals the request's semaphore or, for async requests (negated sema),
 * frees its slot. The compare value is pinned to a1 (one register asm) to reproduce the original's
 * negu v0 + move a1,v0 copy; the slot table is read through a pointer, which keeps its
 * stores out of the branch delay slots like the original. */
void func_00309ec0(int *arg)
{
    EndHdr h;
    char *b;
    int idx, i, s;
    D_00366160 = idx = D_00366168 ? arg[3] : 0;
    b = (char *)((unsigned int)&D_01e37f00[idx] | 0x20000000);
    __builtin_memcpy(&h.sema, b, 4);
    __builtin_memcpy(&h.fno, b + 4, 4);
    __builtin_memcpy(&h.dst, b + 8, 4);
    __builtin_memcpy(&h.size, b + 12, 4);
    if (h.sema >= 0)
        memcpy(h.dst, b + 16, h.size);
    switch (h.fno) {
    case 2: {
        RdTail *t = (RdTail *)(b + 20);
        char *d, *u;
        if (t->n1 > 0) {
            d = t->p1;
            u = (char *)((unsigned int)d | 0x20000000);
            for (i = 0; i < t->n1; i++) {
                d[i] = u[i] = t->d1[i];
            }
        }
        if (t->n2 > 0) {
            d = t->p2;
            u = (char *)((unsigned int)d | 0x20000000);
            for (i = 0; i < t->n2; i++) {
                d[i] = u[i] = t->d2[i];
            }
        }
        break;
    }
    case 11:
        if (*(int *)h.dst > 0) {
            __builtin_memcpy(&h.p, b + 20, 4);
            __builtin_memcpy(h.p, b + 24, 324);
        }
        break;
    case 12:
        __builtin_memcpy(&h.p, b + 20, 4);
        __builtin_memcpy(h.p, b + 24, 64);
        break;
    case 23:
    case 25:
    case 26:
        __builtin_memcpy(&h.p, b + 20, 4);
        __builtin_memcpy(&h.len, b + 24, 4);
        s = h.len;
        if (h.len > 1024) {
            h.len = 1024;
            s = 1024;
        }
        memcpy(h.p, b + 28, s);
        break;
    }
    if (h.sema < 0) {
        register int k asm("$5");
        h.sema = -h.sema;
        k = h.sema;
        for (i = 0; i < 32; i++) {
            if (((int *)D_003660e0)[i] == k) {
                ((volatile int *)D_003660e0)[i] = -1;
                break;
            }
        }
    } else
        func_00305650(h.sema);
}


/* ---- 0x30a278 */
extern int D_0036616c;
void func_0030a278(void)
{
    SemaParam s;
    if (D_0036616c == -1) {
        s.init_count = 1;
        s.max_count = 1;
        s.option = (unsigned int)"SceStdioFioSema";
        D_0036616c = func_00305620(&s);
    }
}

/* ---- 0x30a2d0 */
int func_0030a2d0(void) { func_0030a278(); func_00305660(D_0036616c); return 0; }

/* ---- 0x30a300 */
extern int SignalSema(int sid);
void func_0030a300(void) { SignalSema(D_0036616c); }

/* ---- 0x30a310 (gap) */
typedef struct { int func; int arg; } FioCb;
extern FioCb D_01e38a00;
extern int D_01e38a40;
extern int D_00366164;
extern void func_0030a3f8(void);
extern int func_0030a2d0_i(int) asm("func_0030a2d0");
int func_0030a310(int func, int arg)
{
    FioCb *cb = &D_01e38a00;
    register int gp asm("$28");
    int st, old;
    func_0030a2d0_i(27);
    if (D_00366164 == 0)
        func_0030a3f8();
    st = DIntr();
    old = D_01e38a00.func;
    cb->arg = arg;
    D_01e38a00.func = func;
    D_01e38a40 = gp;
    if (st)
        EIntr();
    func_0030a300();
    return old;
}
