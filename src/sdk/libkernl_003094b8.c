/* libkernl_003094b8.c: Sony PS2 Runtime Library 3.0.0 libkernl: sifrpc (client side), sceSifCallRpc, 0x3094b8-0x3096b8.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } SemaParam;
extern int sceSifSendCmd(unsigned int, void *, int, void *, void *, int);
extern int CreateSema(SemaParam *);
extern int DeleteSema(int);
extern int WaitSema(int);
extern char D_01e37200[];
extern void func_00308da0(void *);
extern void func_00308a80(void *, int);

/* The packet and client words are plain 32-bit ints here: the loads of cd->buff and cd->serve then conflict with the
 * stores to the packet, which pins the retail schedule. The gp store is a asm in retail too (move v0,$28). */
typedef void (*EndFn)(void *);
typedef struct {
    void *paddr;
    unsigned int pid;
    int tid;
    unsigned int mode;
    unsigned int command;
    unsigned int buff;
    unsigned int gp;
    EndFn func;
    void *para;
    unsigned int serve;
} ClientData;
typedef struct {
    int hdr[4];
    int rec_id;
    unsigned int pkt_addr;
    int rpc_id;
    unsigned int client;
    unsigned int fno;
    int ssize;
    unsigned int recv;
    int rsize;
    unsigned int rmode;
    unsigned int server;
} CallPkt;
extern CallPkt *func_00308cf8(void *);

static inline unsigned int get_gp(void)
{
    unsigned int g;
    __asm__ volatile("move %0,$28" : "=r"(g));
    return g;
}

/* ---- 0x3094b8 */
int sceSifCallRpc(ClientData *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize,
                  EndFn endf, void *endp)
{
    SemaParam sp;
    CallPkt *call;
    call = func_00308cf8(D_01e37200);
    if (call == 0)
        return -1;
    cd->para = endp;
    cd->pid = call->rpc_id;
    cd->paddr = call;
    cd->func = endf;
    cd->gp = get_gp();
    call->fno = fno;
    call->ssize = ssize;
    call->recv = (unsigned int)recv;
    call->rsize = rsize;
    call->pkt_addr = (unsigned int)call;
    call->server = cd->serve;
    call->client = (unsigned int)cd;
    if (!(mode & 2)) {
        if (send == recv) {
            func_00308a80(send, ssize < rsize ? rsize : ssize);
        } else {
            if (ssize > 0)
                func_00308a80(send, ssize);
            if (rsize > 0)
                func_00308a80(recv, rsize);
        }
    }
    if (mode & 1) {
        if (endf == 0)
            call->rmode = 0;
        else
            call->rmode = 1;
        cd->tid = -1;
        if (sceSifSendCmd(0x8000000a, call, 64, send, (void *)cd->buff, ssize))
            return 0;
        func_00308da0(call);
        return -2;
    }
    sp.init_count = 0;
    sp.option = (unsigned int)"SceSifrpcCall";
    sp.max_count = 1;
    cd->tid = CreateSema(&sp);
    if (cd->tid < 0) {
        func_00308da0(call);
        return -3;
    }
    call->rmode = 1;
    if (sceSifSendCmd(0x8000000a, call, 64, send, (void *)cd->buff, ssize) == 0) {
        DeleteSema(cd->tid);
        func_00308da0(call);
        return -2;
    }
    WaitSema(cd->tid);
    DeleteSema(cd->tid);
    return 0;
}
