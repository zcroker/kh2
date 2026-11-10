/* Sony PS2 Runtime Library 3.0.0: libkernl sceSifExecRequest (003099e0). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { unsigned int data; unsigned int addr; unsigned int size; unsigned int mode; } DmaData_w3766;
typedef struct { int hdr[4]; int x10; int x14; int x18; void *client; int cid; } Rend_w3766;
typedef struct SD_w3766 {
    int command; void *(*func)(int, void *, int); void *buff; int size;
    void *cfunc; void *cbuff; int csize; void *client; void *paddr; int fno;
    void *receive; int rsize; int rmode; unsigned int rid;
} SD_w3766;
extern char D_01e37200[];
extern Rend_w3766 *func_00308df0(void *, int);
extern Rend_w3766 *func_00308dc0(void *);
extern int DIntr(void);
extern int EIntr(void);
extern void func_00308a80(void *, int);
extern int sceSifSendCmd(int, void *, int, void *, void *, int);
extern int func_00308310(DmaData_w3766 *, int);
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
        rend = func_00308df0(D_01e37200, sd->rid >> 16);
    else
        rend = func_00308dc0(D_01e37200);
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
    do { id = func_00308310(dma, i); if (id) break; j = 0x100000; while (--j != -1) ; } while (!id);
}
