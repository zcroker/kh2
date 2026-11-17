/* libkernl / libpad2 / libmc misc (Sony PS2 Runtime Library 3.0.0) */
extern int func_002f3588(int a);
extern void func_002f3490(void *p);
extern void func_002fde18(void *, int, int);
extern int DIntr(void);
extern void EIntr(void);
extern void func_003086b8(int n, void *fn, void *arg);
extern int sceSifCallRpc(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern int func_00310090(int a);
extern void func_00305e70(unsigned int a, unsigned int b);
extern void func_00305fb0(unsigned int a, unsigned int b);
extern int D_00363da4;
extern int D_00363dc8;
extern void D_002f6bd0(void);
extern int D_0036617c;
extern char D_01e38a80[];
extern int D_01e38ac0[];
extern int D_01e38b00[];
extern int D_01e3b300;

typedef struct { int flags; int pad[3]; unsigned int x10; int pad2[3]; int x20; } Ch_w1055;

void func_002f3980(Ch_w1055 *c, int a, int b);  // 0x002f3980: definition moved into src/sdk/libdma.c

void func_002f39f8(Ch_w1055 *c, int a, int b);  // 0x002f39f8: definition moved into src/sdk/libdma.c

void func_002f3ab8(Ch_w1055 *c, int a, int b);  // 0x002f3ab8: definition moved into src/sdk/libdma.c

typedef struct { unsigned char a, b, c, d; int x4; char pad[20]; char buf[96]; int x7c; } Ent_w1055;
typedef struct { char pad[16]; Ent_w1055 *ent; char pad2[820 - 20]; } Port_w1055;
extern Port_w1055 D_01e2fe48[];

void func_002f6240(int n);  // 0x002f6240: definition moved into src/sdk/libpad2.c

int func_002f6c28(void);  // 0x002f6c28: definition moved into src/sdk/libcdvd_002f6870.c

int u_call4_0030d998(int a) asm("_Z16u_call4_0030d998jjjj");
int u_call4_0030d998(int a);  // 0x0030d998: definition moved into src/sdk/iopheap.c

typedef struct { int next; volatile int id; } Sem_w1055;

int func_00310d08(unsigned int id);  // 0x00310d08: definition moved into src/sdk/libkernl_00310048.c

void func_00305f18(unsigned int a, unsigned int b);  // 0x00305f18: definition moved into src/sdk/libkernl_00305f18.c

void func_00306058(unsigned int a, unsigned int b);  // 0x00306058: definition moved into src/sdk/libkernl_00306058.c
