/* Sony PS2 Runtime Library 3.0.0: libdbc (SendData3), libcdvd (stream/async rpc), libkernl (sif cmd/rpc, deci2 kprintf), iop file rpc. ee-gcc 2.9-991111 -O2 -G0. */
typedef unsigned char u8;
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } SemaParam;
struct SifClient { u8 pad[0x24]; void *serve; };
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
extern int func_002f5c48(const char *, ...);
extern int func_00305660(int);
extern int func_00305640(int);
extern int func_00305670(int);
extern int func_003058a0(int);
extern int func_00305620(SemaParam *);
extern int func_00305630(int);
extern int DIntr(void);
extern void EIntr(void);

/* libdbc: sceDbcSendData3 */
extern int func_003096b8(void *);
extern char D_01e2d9d0[];
extern int D_01e2fe40;
typedef struct { int a; int b; int size; unsigned char data[8324]; } DbcSend3;
extern DbcSend3 D_01e2db40;
int sceDbcSendData3(int a, int b, int *size, unsigned char *buf, void *end);  // 0x002f59c8: definition moved into src/sdk/libdbc.c

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
extern char *strncpy(char *, const char *, unsigned int);
extern void func_002fbba8(void *);
int func_002fc200(int a, u8 *buf, int size);  // 0x002fc200: definition moved into src/sdk/libmc.c

int func_002fce28(int a, int b, const char *name, const char *name2);  // 0x002fce28: definition moved into src/sdk/libmc.c

/* libkernl: sif rpc packet send (sceSifGetOtherData-style) */
typedef struct { int x0, x4, x8, xc, x10; void *pkt_addr; int rec_id; void *paddr; int a, b, c; } RpcPkt;
typedef struct { RpcPkt *pkt; int rec_id; int sema; } RpcCmd;
extern char D_01e37200[];
extern char D_003780d0[];
extern RpcPkt *func_00308cf8(void *);
extern void func_00308da0(void *);
extern int sceSifSendCmd(unsigned int, void *, int, void *, int, void *);
int sceSifGetOtherData(RpcCmd *cd, int a, int b, int c, int mode);  // 0x00309010: definition moved into src/sdk/libkernl_00308f00.c

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
int sceDclose(int fd);  // 0x0030c220: definition moved into src/sdk/filestub.c

int sceClose(int fd);  // 0x0030ab88: definition moved into src/sdk/filestub.c

/* libgraph: sceGsExecLoadImage */
typedef unsigned long u64 __attribute__((mode(DI)));
extern int func_003080d0(const char *, ...);
typedef struct { u64 w[10]; u64 giftag1; u64 x58; } GsLoadImage;
#define D2_CHCR ((volatile unsigned int *)0x1000a000)
#define D2_MADR ((volatile unsigned int *)0x1000a010)
#define D2_QWC  ((volatile unsigned int *)0x1000a020)
/* 0x002f2be0 sceGsExecLoadImage: definition moved into src/sdk/libgraph2.c */
