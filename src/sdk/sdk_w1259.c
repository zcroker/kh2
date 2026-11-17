/* Sony PS2 Runtime Library 3.0.0: libkernl (DMA/intc/thread lists), libpad2/libdbc helpers, libcdvd/sif rpc wrappers. ee-gcc 2.9-991111 -O2 -G0. */
typedef unsigned int u32;
extern int DIntr(void);
extern void EIntr(void);
extern void func_0030f6a0(int);
extern int func_0030ff08(void);
extern void func_0030fa10(int);

int func_0030f900(void);  // 0x0030f900: definition moved into src/sdk/libkernl_0030f688.c

int func_002f3c28(volatile u32 *p);  // 0x002f3c28: definition moved into src/sdk/libdma.c

typedef struct L { int f0, f4, f8, fc, f10; struct L *next; } L;
typedef struct { char pad[0x28]; L *head; } LH;
extern LH D_01e37200;
void func_003096f8(L *a, int b);  // 0x003096f8: definition moved into src/sdk/libkernl_003096b8.c

typedef struct M { char pad[0x38]; struct M *next; } M;
typedef struct { int a, b; M *head; } MH;
M* func_00309860(M *a, MH *l);  // 0x00309860: definition moved into src/sdk/libkernl_00309860.c

typedef struct { short s0; short s2; int f4; int f8; int fc; } P;
extern P* sceGsGetGParam(void);
extern void DisableIntc(int);
extern void func_00305320(int, int);
extern int func_00305300(int, int, int);
extern void EnableIntc(int);
/* 0x002f33f0 sceGsSyncVCallback: definition moved into src/sdk/libgraph3.c */

extern void func_00305ab0(void);
extern long func_00305b40(void);
int sceGsSyncV(int x) asm("_Z10sceGsSyncVi") __attribute__((section(".text._Z13func_002f2508i")));
/* 0x002f2508 sceGsSyncV: definition moved into src/sdk/libgraph2.c */

extern int func_002f6fc0(int);
extern int func_002f72c0(int);
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
extern void func_00305640(int);
extern char D_00364f50[];
extern char D_00363e00[];
extern int D_00363da8;
int func_002f7118(void);  // 0x002f7118: definition moved into src/sdk/libcdvd_002f6870.c

extern char D_00365900[];
extern char D_00364f80[];
extern int D_00363dac;
int func_002f7dc8(void);  // 0x002f7dc8: definition moved into src/sdk/libcdvd_002f77b0.c

typedef struct { int status; void *func; void *stack; int size; void *gp; int prio; int cur; u32 attr; void *option; } TP;
extern TP D_01e331d8;
extern int D_00363d94;
extern char D_002f67a0[];
extern char D_00376b70[];
extern int func_00305420(TP *);
extern void func_00306760(int, int);
extern void func_003054b0(int, int);
int sceCdInitEeCB(int prio, void *stack, int size);  // 0x002f6870: definition moved into src/sdk/libcdvd_002f6870.c

extern int sceOpen(void *, int);
extern int sceRead(int, void *, int);
extern int sceClose(int);
extern int atoi(char *);
extern char D_003762c8[];
int func_002f2020(void);  // 0x002f2020: definition moved into src/sdk/libgraph_002f1e18.c
