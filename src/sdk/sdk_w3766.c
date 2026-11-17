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
void sceSifExecRequest(SD_w3766 *sd);  // 0x003099e0: definition moved into src/sdk/libkernl_00309860.c
