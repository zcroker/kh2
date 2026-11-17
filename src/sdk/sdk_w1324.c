/* libcdvd / libdbc / libvu0 / libgraph / libkernl misc (Sony PS2 Runtime Library 3.0.0) */
typedef unsigned long long u64;

extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern int func_002f5c48(const char *, ...);
extern int func_00305640(int);
extern int func_00305660(int);
extern int func_00305670(int);
extern int DIntr(void);
extern void EIntr(void);

/* libcdvd */
extern int func_002f72c0(int);
extern volatile int D_00363dac;
extern volatile int D_00363de0;
extern char D_00365900[];
extern char D_00364f80[];
int func_002f7e60(void)
{
    int r;
    if (!func_002f72c0(30))
        return 0;
    D_00363de0 = 8;
    if (sceSifCallRpc(D_00365900, 22, 0, 0, 0, D_00364f80, 4, 0, 0) < 0) {
        func_00305640(D_00363dac);
        D_00363de0 = 0;
        return 0;
    }
    D_00363de0 = 0;
    r = *(int *)((int)D_00364f80 | 0x20000000);
    func_00305640(D_00363dac);
    return r;
}

/* libkernl */
extern int func_00305320(int, int);
extern void DisableIntc(int);
extern void func_0030f6a0(int);
extern void func_0030f690(int);
struct S1324 { long long a; int b; int pad; volatile int c; };
extern struct S1324 D_00367118;
int func_0030f818(void)
{
    int s;
    struct S1324 *p = &D_00367118;
    if (p->b < 0)
        return 0x80008001;
    if (p->c != 0)
        return 0x80000010;
    s = DIntr();
    if (func_00305320(11, p->b) == 0) {
        DisableIntc(11);
        func_0030f6a0(0xc00);
        func_0030f690(0);
    }
    D_00367118.a = 0;
    p->b = -1;
    if (s)
        EIntr();
    return 0;
}

struct E1324 { int a; int b; int gp; int pad; };
extern struct E1324 *D_00367138;
extern unsigned int D_0036713c;
extern struct E1324 D_01e3b308[];
int func_00310e28(int id, int a, int b)
{
    struct E1324 *t, *p;
    unsigned int n;
    int s;
    if (id < 0) {
        t = D_01e3b308;
        id &= 0x7fffffff;
        n = 32;
    } else {
        t = D_00367138;
        n = D_0036713c;
    }
    if ((unsigned int)id >= n)
        return 0x80000069;
    s = DIntr();
    p = (struct E1324 *)((id << 4) + (int)t);
    p->a = a;
    p->b = b;
    { int g; asm volatile("move %0,$gp" : "=r"(g)); p->gp = g; }
    if (s)
        EIntr();
    return 0;
}

/* libdbc */
extern int D_00363d10;
extern int D_01e2fe40;
extern char D_01e2d980[];
extern int D_01e2da80[];
int sceDbcDeleteSocket(int x);  // 0x002f4f60: definition moved into src/sdk/libdbc.c

int func_002f5498(int *p);  // 0x002f5498: definition moved into src/sdk/libdbc.c

/* libcdvd (streaming/async rpc) */
struct C1324 { int pad[9]; int f; int rest[26]; };
extern struct C1324 D_01e33480;
extern int D_0036594c;
extern int D_00365948;
extern int D_00365950;
extern int D_01e33500[];
extern int D_01e34a40[];
extern void func_002fbba8(void *);
int func_002fbe98(int x);  // 0x002fbe98: definition moved into src/sdk/libmc.c

int func_002fcb98(int x);  // 0x002fcb98: definition moved into src/sdk/libmc.c

int func_002fbc78(int x);  // 0x002fbc78: definition moved into src/sdk/libmc.c

int func_002fc378(int mode, int *cmd, int *result);  // 0x002fc378: definition moved into src/sdk/libmc.c

/* libvu0 */
typedef float VEC1324[4] __attribute__((aligned(16)));
extern void sceVu0ScaleVector(float *, float *, float);
extern void sceVu0Normalize(float *, float *);
extern void sceVu0TransposeMatrix(VEC1324 *, VEC1324 *);
void func_002f43c0(VEC1324 *m, float *a, float *b, float *c)
{
    VEC1324 w;
    sceVu0ScaleVector(w, a, -1.0f);
    sceVu0Normalize(m[0], w);
    sceVu0ScaleVector(w, b, -1.0f);
    sceVu0Normalize(m[1], w);
    sceVu0ScaleVector(w, c, -1.0f);
    sceVu0Normalize(m[2], w);
    m[3][0] = m[3][1] = m[3][2] = 0.0f;
    m[3][3] = 1.0f;
    sceVu0TransposeMatrix(m, m);
}

/* libgraph */
struct GP1324 { short a, b, c, mode; };
extern struct GP1324 *sceGsGetGParam(void);
struct DE1324 { u64 pmode, smode2, dispfb, display, bgcolor; };
#define GSR(x) (*(volatile u64 *)(x))
/* 0x002f2448 sceGsPutDispEnv: definition moved into src/sdk/libgraph2.c */
