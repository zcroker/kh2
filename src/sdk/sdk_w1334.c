/* Sony PS2 Runtime Library 3.0.0: libkernl (sce fileio client, mc/sif rpc helpers). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam;
typedef struct { int sema; int *res; int rsize; char name[1024]; char name2[1024]; } SymPk;
typedef struct { int sema; int *res; int rsize; int len; void *buf; char name[1024]; } RlPk;
typedef struct { int sema; int *res; int rsize; int fd; int req; char arg[1024]; void *buf; int buflen; int arglen; } IoPk;
typedef struct { int fd; int valid; } Fdd;
typedef struct { char b[252]; } B252;
typedef struct { int v; int len; char pad[252]; char data[252]; } MP;
extern MP D_01e38c40;
extern char D_01e38e40[];
extern int func_0030dd70(void);
extern int func_0030de70(void);
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);

extern SymPk D_01e37280;
extern char D_01e38980[];
extern char D_01e37ec0[];
extern int D_00366164;
extern int func_0030a2d0(int);
extern int func_0030a300(void);
extern int func_0030a3f8(void);
extern int func_00305620(SemaParam *);
extern int func_00305630(int);
extern int func_00305660(int);
extern void func_00308a80(void *, int);
extern void *memcpy(void *, const void *, int);
extern Fdd *func_00309e50(int);
extern int func_00309d60(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry);

int sceSymlink(const char *a, const char *b);  // 0x0030d448: definition moved into src/sdk/filestub.c

int sceReadlink(const char *a, void *buf, unsigned int len);  // 0x0030d640: definition moved into src/sdk/filestub.c

int sceIoctl2(int fd, int req, void *arg, unsigned int arglen, void *buf, unsigned int buflen);  // 0x0030b7f8: definition moved into src/sdk/filestub.c

int sceRename(const char *a, const char *b);  // 0x0030c8e8: definition moved into src/sdk/filestub.c


int u_call4_0030df38(int a, int len, void *data, int *out) asm("_Z16u_call4_0030df38jjjj");
int u_call4_0030df38(int a, int len, void *data, int *out);  // 0x0030df38: definition moved into src/sdk/eeloadfile.c
int func_0030e140(int a, int len, void *data, int *out);  // 0x0030e140: definition moved into src/sdk/eeloadfile.c

typedef struct { unsigned int w[16]; } Stat64;
typedef struct { int sema; int *res; int rsize; int cbit; Stat64 st; unsigned char name[1024]; } ChPk;
int sceChstat(const unsigned char *name, Stat64 *st, int cbit);  // 0x0030c698: definition moved into src/sdk/filestub.c

extern char *strncpy(char *, const char *, int);
int func_0030e548(const char *name, int len, void *data, int *out, int fno);  // 0x0030e548: definition moved into src/sdk/eeloadfile.c

/* libkernl printf helper: %e-style double output (soft-float helpers called directly) */
extern int func_003142e0(double, double);
extern double __subdf3(double, double);
extern double func_00313f40(double, double);
extern double func_00314190(double, double);
extern int __fixunsdfdi(double);
extern int func_00306f68(int);
extern int func_00307f90(void *a, void *b, int *n, const char *fmt, ...);
int func_00306ff8(int (*out)(void *, int *, int), void *arg, int *n, double d)
{
    int len = 0;
    int e = 0;
    int x;
    if (*n == 0)
        return 0;
    if (func_003142e0(d, 0.0) < 0) {
        d = __subdf3(0.0, d);
        len = 1;
        out(arg, n, '-');
        (*n)--;
    }
    if (func_003142e0(d, 0.1) < 0) {
        while (func_003142e0(d, 0.1) < 0) {
            d = func_00313f40(d, 10.0);
            e--;
        }
    } else if (func_003142e0(d, 1.0) >= 0) {
        while (func_003142e0(d, 1.0) >= 0) {
            d = func_00314190(d, 10.0);
            e++;
        }
    }
    x = func_00306f68(__fixunsdfdi(func_00313f40(d, 1000000.0)));
    len += func_00307f90(out, arg, n, "0.%d", x);
    if (e >= 0)
        len += func_00307f90(out, arg, n, "e+%d", e);
    else
        len += func_00307f90(out, arg, n, "e%d", e);
    return len;
}
