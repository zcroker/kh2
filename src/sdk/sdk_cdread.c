/* Sony PS2 Runtime Library 3.0.0: libcdvd sceCdRead. ee-gcc 2.9-991111 -O2 -G0. One empty asm memory barrier on the failure path keeps the original store order. */
typedef struct { unsigned char trycount, spindlctrl, datapattern, pad; } RMode;
typedef struct { unsigned int lsn, sec; void *buf; unsigned char t, s, d, p; void *ee; void *rd; } RArg;
extern int D_00363db8;
extern int D_00363d90;
extern int D_00363de0;
extern int D_00363db4;
extern int D_00363da8;
extern int D_00364f40;
extern RArg D_00363e80;
extern char D_00364e80[];
extern char D_00364f50[];
extern char D_00376d78[];
extern char D_00376d90[];
extern int func_002f7118(void);
extern int func_002f6fc0(int);
extern void func_00308a80(void *, int);
extern void func_003080d0(void *);
extern int func_00305640(int s);
extern void func_002f6910(void *);
extern int sceSifCallRpc(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
int func_002f7be8(unsigned int lsn, unsigned int sec, void *buf, RMode *mode);  // 0x002f7be8: definition moved into src/sdk/libcdvd_002f77b0.c
