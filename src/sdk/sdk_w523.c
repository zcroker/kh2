/* Sony PS2 Runtime Library 3.0.0: libkernl (stdio/libc semaphores, intc helpers) and RPC-client/pad helpers (0x2f4xxx-0x2fbxxx). ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } SemaParam;
extern int func_00305620(SemaParam *p);
extern int func_00305630(int id);
extern int func_002fc378(int a, int b, int c);
extern int func_00305f18(void *a, void *b);
extern int sceSifCallRpc(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern int func_003052d0(int n, void *h);
extern void func_00311740(void);
extern int DIntr(void);
extern int EIntr(void);
extern int func_00310180(int a, int b);

typedef struct { char pad[0x7c]; int x7c; } Pad;
typedef struct { char pad0[8]; int f8; int pad1; Pad *f10; char rest[820 - 20]; } PortT;
extern PortT D_01e2fe48[];

extern int D_0036616c;
extern int D_003661a0;
extern int D_003661a4;
extern int D_0036594c;
extern int D_00365950;
extern int D_00367470;
extern int D_01e2d980[];
extern int D_01e2da80[];
extern int D_01e3b300;

void func_0030a278(void);  // 0x0030a278: definition moved into src/sdk/libkernl_00309860.c

int func_002fbb50(void);  // 0x002fbb50: definition moved into src/sdk/libmc.c

Pad* func_002f6310(int port);  // 0x002f6310: definition moved into src/sdk/libpad2.c

Pad* func_002f6378(int port);  // 0x002f6378: definition moved into src/sdk/libpad2.c

int func_002f63e0(int port);  // 0x002f63e0: definition moved into src/sdk/libpad2.c

int func_003101d0(int a, int b);  // 0x003101d0: definition moved into src/sdk/libkernl_00310048.c

typedef struct Node { struct Node *next; int x4; int (*fn)(unsigned int, int, int, int); int arg; } Node;

int func_003109e0(unsigned int a, int b, int c, Node* n);  // 0x003109e0: definition moved into src/sdk/libkernl_00310048.c

int func_002f4d60(void);  // 0x002f4d60: definition moved into src/sdk/libdbc.c

void func_0030ee18(void);  // 0x0030ee18: definition moved into src/sdk/libkernl_0030ee00.c

int func_00311218(int a);  // 0x00311218: definition moved into src/sdk/libkernl_00310fe0.c
