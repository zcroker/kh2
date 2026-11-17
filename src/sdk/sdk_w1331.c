/* libkernl (sifcmd) and misc Sony PS2 Runtime Library 3.0.0 */
typedef struct { unsigned int src; unsigned int dest; int size; unsigned int attr; } Dma;
typedef struct { unsigned int size; unsigned int dest; int cid; unsigned int opt; } Hdr;
extern void func_00308a80(void *, int);
extern int func_003059f0(Dma *, int);
extern int func_003059e0(Dma *, int);
extern unsigned int D_01e357e0;
unsigned int func_00308780(int cid, int mode, Hdr *pkt, unsigned int pktsize, void *src, void *dest, int size);  // 0x00308780: definition moved into src/sdk/libkernl_00308730.c

/* libkernl sifrpc: sceSifBindRpc */
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } SemaParam;
typedef struct { void *pkt_addr; int rpc_id; int sema_id; int mode; int command; int buf; int cbuf; int end_func; int end_param; int server; } RpcClient;
typedef struct { int hdr[4]; int rec_id; int pkt_addr; int rpc_id; int client; int fno; } BindPkt;
extern BindPkt *func_00308cf8(void *);
extern void func_00308da0(void *);
extern int sceSifSendCmd(unsigned int, void *, int, void *, void *, int);
extern int func_00305630(int);
extern int func_00305660(int);
extern char D_01e37200[];
extern int func_00305620(SemaParam *);
int sceSifBindRpc(RpcClient *cd, int sid, int mode);  // 0x003092d8: definition moved into src/sdk/libkernl_00308f00.c

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
int func_0030a6c8(unsigned int addr, unsigned int size);  // 0x0030a6c8: definition moved into src/sdk/filestub.c

typedef struct { int fd; int valid; } FioFile;
extern FioFile *func_00309e50(int);
int sceDread(int fd, void *buf);  // 0x0030c388: definition moved into src/sdk/filestub.c

/* libkernl timer: InitTimer */
typedef struct TBlk { struct TBlk *next; int pad[15]; } TBlk;
typedef struct { unsigned long long x0; int handler; int xc; int count; TBlk *free; int x18; } TMgr;
extern TMgr D_00367118;
extern TBlk D_01e38f00[128];
extern void func_002fde18(void *, int, int);
extern void func_00310990(void);
extern int func_00305310(int, void *, int, void *);
extern int func_0030fc60();
extern int DIntr(void);
extern void EIntr(void);
extern void func_0030f690(int);
extern void func_0030f6a0(int);
extern void func_0030f6b0(int);
extern void EnableIntc(int);
int func_0030f6c0(int mode);  // 0x0030f6c0: definition moved into src/sdk/libkernl_0030f688.c

/* libkernl sif: sceSifResetIop */
typedef struct { unsigned int psize:8; unsigned int dsize:24; unsigned int dest; unsigned int cid; unsigned int opt; } RHdr;
typedef struct { RHdr hdr; int arglen; int mode; char arg[80]; } ResetPkt;
extern ResetPkt D_01e38e80 __attribute__((aligned(64)));
extern void func_00310f38(int, int);
extern void func_003058f0(void);
extern unsigned int func_00305a30(int);
extern void func_00305a20(unsigned int, unsigned int);
int func_0030ead0(char *arg, int mode);  // 0x0030ead0: definition moved into src/sdk/iopreset.c

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
extern char *strncpy(char *, const char *, int);
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern void func_002fbba8(void *);
extern void func_002fc7d8(void *);
int func_002fc688(int port, int slot, const char *name, int mode, int maxent, void *table);  // 0x002fc688: definition moved into src/sdk/libmc.c

int func_002fc868(int port, int slot, const char *name, void *endp);  // 0x002fc868: definition moved into src/sdk/libmc.c

/* libpad2 */
typedef union { struct { unsigned long a:14; unsigned long b:2; unsigned long c:8; unsigned long d:8; } s; int i; } PadCmd;
typedef struct { int x0; int active; char pad[812]; } PadEnt;
extern PadEnt D_01e2fe48[];
extern int func_002f62b8(int);
extern int func_002f63e0(int);
extern unsigned char *func_002f6378(int);
extern void func_002f6240(int);
extern int sceDbcReceiveData(int, int, int *, unsigned char *);
int func_002f6020(int port);  // 0x002f6020: definition moved into src/sdk/libpad2.c
