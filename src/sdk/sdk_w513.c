/* Sony PS2 Runtime Library 3.0.0: libkernl (0x3050xx-0x311xxx) and libc/libdbc helpers (0x2f5c70). ee-gcc 2.9-991111 -O2 -G0. */
extern int D_00366180;
extern char D_01e38e68[];
extern int func_002fde18(void *, int, int);
int func_0030df00(void);  // 0x0030df00: definition moved into src/sdk/eeloadfile.c

typedef struct Lnk { struct Lnk *next; struct Lnk *prev; } Lnk;
extern Lnk *D_00367130;
Lnk* func_0030fc28(Lnk *n);  // 0x0030fc28: definition moved into src/sdk/libkernl_0030f688.c

typedef struct { int size; int count; char *rd; int pad; char buf[1]; } Ring;
void func_00306968(Ring *r);  // 0x00306968: definition moved into src/sdk/libkernl_00306698.c

extern int func_00308780(int, int, int, int, int, int, int);
int sceSifSendCmd(int a, int b, int c, int d, int e, int f);  // 0x003088b8: definition moved into src/sdk/libkernl_00308730.c
int isceSifSendCmd(int a, int b, int c, int d, int e, int f);  // 0x003088f8: definition moved into src/sdk/libkernl_00308730.c

typedef struct { int p0, p4, p8, pc; unsigned int flags; int p14; int id; } Sem2;
typedef struct { Sem2 *s; int id; } Ref;
int func_003096b8(Ref *r);  // 0x003096b8: definition moved into src/sdk/libkernl_003096b8.c

typedef struct { int a, b, c, d; char pad[804]; } Ent;
extern int D_00363d28;
extern Ent D_01e2fe48[16];
int func_002f5c70(void);  // 0x002f5c70: definition moved into src/sdk/libpad2.c

typedef struct { char pad[0x1c]; char *tab; int n; } Tbl;
extern void* func_00308dc0(Tbl *, int);
void* func_00308df0(Tbl *t, int i);  // 0x00308df0: definition moved into src/sdk/libkernl_00308b30.c

typedef struct { char pad[0x24]; int x, y, z; } Arg;
int func_00308f00(int a, int b, int c, Arg *d);  // 0x00308f00: definition moved into src/sdk/libkernl_00308f00.c
int func_003091c8(int a, int b, int c, int d);  // 0x003091c8: definition moved into src/sdk/libkernl_00308f00.c

extern int func_00309988(int);
extern void sceSifExecRequest(int);
extern void func_00305540(void);
void func_00309ba8(int a);  // 0x00309ba8: definition moved into src/sdk/libkernl_00309860.c

extern int func_00305a80(void);
extern int func_00311530(void);
extern int func_00305a90(void);
int func_003114f0(void);  // 0x003114f0: definition moved into src/sdk/libkernl_003114f0.c
