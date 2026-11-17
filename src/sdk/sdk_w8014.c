/* Sony PS2 Runtime Library 3.0.0: libdma (sceDmaReset), libcdvd (semaphore init, N/S command checks). ee-gcc 2.9-991111 -O2 -G0. */
typedef unsigned int u_int;
typedef struct { int x0; int p0[3]; int x10; int p1[7]; int x30; int p2[3]; int x40; int p3[3]; int x50; int p4[11]; int x80; } Ch1328;
extern Ch1328 *D_00363c90[];
extern int D_003767e8[];
extern void func_002f35b0(void *, int);
extern int func_002f36f0(void *);
int func_002f3610(int mode);  // 0x002f3610: definition moved into src/sdk/libdma.c

typedef struct { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; } SemaParam1328;
extern int func_00305620(SemaParam1328 *);
extern volatile int D_00363da8;
extern volatile int D_00363dac;
extern volatile int D_00363db0;
extern volatile int D_00363da0;
extern volatile int D_00363db4;
void func_002f69c8(void);  // 0x002f69c8: definition moved into src/sdk/libcdvd_002f6870.c

typedef struct { int x[9]; int serve; int pad[32]; } CdRpc;
extern int D_00363d90;
extern int D_00363d9c;
extern int D_00363dbc;
extern CdRpc D_00364f50;
extern void func_002f69c8(void);
extern int func_00305670(int);
extern void func_00305640(int);
extern int func_002f5c48(const char *, ...);
extern int func_003080d0(const char *, ...);
extern int func_002f71b0(int);
extern void func_00308b30(int);
extern int sceSifBindRpc(CdRpc *, unsigned int, int);

int func_002f6fc0(int cmd);  // 0x002f6fc0: definition moved into src/sdk/libcdvd_002f6870.c

extern int D_00363d98;
extern int D_00363dd4;
extern CdRpc D_00365900;
extern int func_002f7250(int);

int func_002f72c0(int cmd);  // 0x002f72c0: definition moved into src/sdk/libcdvd_002f6870.c

