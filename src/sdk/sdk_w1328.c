/* libcdvd / libmc / libpad / libkernl / libdma misc (Sony PS2 Runtime Library 3.0.0) */
typedef unsigned int u32;

extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern int func_00305640(int);
extern void func_00308a80(void *, int);
extern int func_002f72c0(int);
extern int D_00363dac;
extern char D_00365900[];
extern char D_00364f80[];
extern int D_003653c0[];
extern int D_00365928;
extern int D_0036592c;
extern int D_00365930;
int func_002f7f18(int a);  // 0x002f7f18: definition moved into src/sdk/libcdvd_002f77b0.c

typedef struct { int x0; volatile int x4; unsigned char *x8; } Q1328;
typedef struct { int pad[6]; Q1328 *x18; } S1328;
extern S1328 D_01e353d0;
extern void func_00306968(Q1328 *);
int func_00306cb8(char *buf, int n);  // 0x00306cb8: definition moved into src/sdk/libkernl_00306698.c

typedef struct { int pad[4]; unsigned int x10; int x14; int x18; int x1c; int x20; int x24; int x28; } R1328;
typedef struct { int pad[5]; int x14; int x18; int x1c; int x20; int x24; int x28; int x2c; } P1328;
extern P1328 *func_00308df0(int, unsigned int);
extern P1328 *func_00308dc0(int);
extern int isceSifSendCmd(int, P1328 *, int, int, int, int);
extern void func_00310b70(int, void *, P1328 *);
extern void D_00308f00(void);
void func_00308f40(R1328 *r, int a);  // 0x00308f40: definition moved into src/sdk/libkernl_00308f00.c

typedef struct { int x0; int x4; int pad[3]; char x14[0x334 - 0x14]; } E1328;
typedef struct { unsigned char x0, x1, x2, x3; int x4; int pad[5]; unsigned char x1c[1]; } F1328;
extern E1328 D_01e2fe48[];
extern int func_002f62b8(int);
extern F1328 *func_002f6310(int);
extern void *memcpy(void *, void *, int);
extern int func_002f6440(void *, void *);
int func_002f5e78(int port, void *buf);  // 0x002f5e78: definition moved into src/sdk/libpad2.c

typedef struct { int a; int b; } G1328;
extern G1328 D_003670d8[];
extern char D_00366970[];
extern char D_003670b0[];
extern void func_0030f4e0(int, int);
extern void func_0030f4f0(int, void *, int);
extern int func_0030f538(int);
extern void func_003058a0(int);
void func_0030f548(void);  // 0x0030f548: definition moved into src/sdk/libkernl_0030f548.c

typedef struct { int a; int type; union { unsigned char b; unsigned short h; int w; } v; } I1328;
extern I1328 D_01e38c40;
extern char D_01e38e40[];
extern int func_0030dd70(void);
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
int func_0030e9f0(int a, void *val, int type);  // 0x0030e9f0: definition moved into src/sdk/eeloadfile.c

typedef struct { int pad[9]; int x24; } J1328;
typedef struct { int x0; int pad[3]; int x10; int x14; } K1328;
extern J1328 D_01e33480;
extern K1328 D_01e33500;
extern char D_01e34a40[];
extern int D_0036594c;
extern int D_00365948;
extern void D_002fbba8(void *);
extern int func_00305670(int);
extern int func_00305640(int);
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
int func_002fbf58(int a, int b, int c);  // 0x002fbf58: definition moved into src/sdk/libmc.c
