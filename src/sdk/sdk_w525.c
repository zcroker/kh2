/* Sony PS2 Runtime Library 3.0.0: libkernl (timers, stdio sema, sif cmd), libdma, libmc, libcdvd-ish RPC wrappers. */
typedef struct { int p0, p4; int id; int flags; long start; long acc; } Tm;
extern long func_0030ff08(void);
long func_003105b0(int id);  // 0x003105b0: definition moved into src/sdk/libkernl_00310048.c

extern int func_003080d0(const char *, ...);
extern void func_002f3c28(volatile int *);
void func_002f3490(volatile int *d);  // 0x002f3490: definition moved into src/sdk/libdma.c

extern char D_01e33480[], D_01e33500[];
extern int D_01e34a40;
extern void func_002fbba8(void *);
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
int sceMcUdCheckNewCard(void);  // 0x002fc618: definition moved into src/sdk/libmc.c

typedef struct { int x; int pad[3]; } Arg;
extern int DIntr(void);
extern void EIntr(void);
extern void func_00307f40(void);
extern int func_003071d0(void (*)(void), void *, unsigned int, int, int);
void func_00308060(int a, int b);  // 0x00308060: definition moved into src/sdk/kprintf.c

typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr, option; } SemaParam;
extern int func_00305620(SemaParam *);
extern int D_00366170, D_00366174;
void func_00309be8(void);  // 0x00309be8: definition moved into src/sdk/libkernl_00309860.c

extern int D_0036617c;
extern char D_01e38a80[];
extern int D_01e38ac0, D_01e38b00;
int func_0030d8a8(int a);  // 0x0030d8a8: definition moved into src/sdk/iopheap.c

unsigned int func_0030db20(void);  // 0x0030db20: definition moved into src/sdk/iopheap.c

unsigned int func_0030db90(void);  // 0x0030db90: definition moved into src/sdk/iopheap.c

unsigned int func_0030dc00(void);  // 0x0030dc00: definition moved into src/sdk/iopheap.c

extern unsigned long func_00312db8(unsigned long, unsigned long);
unsigned long func_00310890(unsigned int s, unsigned int u);  // 0x00310890: definition moved into src/sdk/libkernl_00310048.c
