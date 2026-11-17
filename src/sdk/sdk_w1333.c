/* Sony PS2 Runtime Library 3.0.0: libmc-style rpc client (002fc498), libdbc (sceDbcSRData), libgraph (sceGsResetGraph), libkernl (deci2 TTY handler, sceSifInitRpc, stdio rpc open/mkdir/getstat/u_call4). ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int pad0; int a; int b; int c; int d; int e; int pad18; void *buf; } Rpc;
typedef struct { char pad[0x24]; int serve; } Cd;
extern Cd D_01e33480;
extern Rpc D_01e33500;
extern char D_01e33980[];
extern char D_01e34a40[];
extern int D_01e334a8, D_01e334ac, D_01e334b0;
extern int D_0036594c;
extern int D_00365948;
extern int func_00305670(int);
extern int func_00305640(int);
extern void func_00308a80(void *, int);
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
extern char D_002fc440[];
int func_002fc498(int a0, int a1, int a2, int a3, int a4);  // 0x002fc498: definition moved into src/sdk/libmc.c

typedef struct { int a; int b; int n1; int n2; char s[128]; char r[128]; int res; } Pk;
extern Pk D_01e2da80;
extern char D_01e2d980[];

extern int D_01e2fe40;
extern int func_00305660(int);
extern int func_00305640(int);

extern int func_002f5c48(const char *, ...);
int sceDbcSRData(int a, int b, int *n1, char *s, int *n2, char *r);  // 0x002f5558: definition moved into src/sdk/libdbc.c

typedef struct { short inter; short omode; short ffmode; short version; int f8; int fc; } GP;
extern GP *sceGsGetGParam(void);
extern void func_00305220(short, short, short);
extern int func_00305320(int, int);
extern int func_00305960(int);
extern int DisableIntc(int);
#define CSR ((volatile unsigned long *)0x12001000)
void func_002f1e18(short mode, short inter, short omode, short ffmode)
{
    GP *p;
    switch (mode) {
    case 0:
        p = sceGsGetGParam();
        *CSR = 0x200;
        p->inter = inter;
        p->omode = omode;
        p->version = (*CSR >> 16) & 0xff;
        func_00305960(0xff00);
        p->ffmode = ffmode != 0;
        if (p->f8) {
            DisableIntc(2);
            func_00305320(2, p->fc);
            p->f8 = 0;
            p->fc = 0;
        }
        func_00305220(inter & 1, omode & 0xff, ffmode & 1);
        break;
    case 1:
        *CSR = 0x100;
        break;
    case 5:
        p = sceGsGetGParam();
        p->ffmode = ffmode != 0;
        p->inter = inter;
        p->omode = omode;
        p->version = (*CSR >> 16) & 0xff;
        func_00305220(inter & 1, omode & 0xff, ffmode & 1);
        break;
    }
}

typedef struct { int size; int count; int pad8; char *wp; char buf[1]; } Ring;
typedef struct { int sock; volatile int wlen; volatile int rlen; volatile int busy; char *wbuf; char *rbuf; Ring *ring; } TI;
extern void func_00306928(Ring *r);
extern void func_00308150(const char *fmt, ...);
extern int func_00311100(int, char *, unsigned short);
extern int func_00311138(int, char *, unsigned short);
void func_003069a8(int ev, int param, TI *ti);  // 0x003069a8: definition moved into src/sdk/libkernl_00306698.c


typedef struct { int pid; void *pkt; int pktlen; int u0c; int u10; void *rdata; int rdlen; void *client; int cllen; int u24; } RD;
extern RD D_01e37200;
extern char D_01e35a00[], D_01e36200[], D_01e36a00[];
extern char D_00308e30[], D_00309208[], D_00309428[], D_00308f40[];
extern int D_003660dc;
extern int DIntr(void);
extern int EIntr(void);
extern void func_003083d0(void);
extern int func_003086b8(int, void *, void *);
extern int func_00305a30(int);
extern int func_00305a20(int, int);
extern int sceSifSendCmd(int, void *, int, void *, void *, int);
extern int func_00308200(int);
#define UC(p) ((void *)((unsigned int)(p) | 0x20000000))
void func_00308b30(void);  // 0x00308b30: definition moved into src/sdk/libkernl_00308b30.c

typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam;
typedef struct { int sema; int *res; int rsize; int pad; int mode; char name[1024]; } OpenPk;
extern OpenPk D_01e37280;
extern char D_01e38980[];
extern char D_01e37ec0[];
extern int D_00366164;
extern int func_0030a2d0(int);
extern int func_0030a300(void);
extern int func_0030a3f8(void);
extern int func_00305620(SemaParam *);
extern int func_00305630(int);
extern int func_00305660(int);
extern int func_00309d60(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry);
typedef struct { int sema; int *res; int rsize; char name[1024]; } NamePk;
typedef struct { int sema; int *res; int rsize; int mode; unsigned char name[1024]; } ModePk;
typedef struct { int sema; int *res; int rsize; int mode; char name[1024]; } ModePk2;
int sceSync(const char *name, int mode);  // 0x0030cb10: definition moved into src/sdk/filestub.c

int u_call4_0030b9e0(const char *name, int fno) asm("_Z16u_call4_0030b9e0jjjj");
int u_call4_0030b9e0(const char *name, int fno);  // 0x0030b9e0: definition moved into src/sdk/filestub.c

int sceGetstat(const unsigned char *name, int mode);  // 0x0030c4e0: definition moved into src/sdk/filestub.c

int sceMkdir(const char *name, int mode);  // 0x0030bbb0: definition moved into src/sdk/filestub.c
