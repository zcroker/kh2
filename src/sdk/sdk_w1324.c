/* libcdvd / libdbc / libvu0 / libgraph / libkernl misc (Sony PS2 Runtime Library 3.0.0) */
typedef unsigned long long u64;

extern int func_003094b8(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern int func_002f5c48(const char *, ...);
extern int func_00305640(int);
extern int func_00305660(int);
extern int func_00305670(int);
extern int func_0030edb0(void);
extern void func_0030ee00(void);

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
    if (func_003094b8(D_00365900, 22, 0, 0, 0, D_00364f80, 4, 0, 0) < 0) {
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
extern void func_00306100(int);
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
    s = func_0030edb0();
    if (func_00305320(11, p->b) == 0) {
        func_00306100(11);
        func_0030f6a0(0xc00);
        func_0030f690(0);
    }
    D_00367118.a = 0;
    p->b = -1;
    if (s)
        func_0030ee00();
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
    s = func_0030edb0();
    p = (struct E1324 *)((id << 4) + (int)t);
    p->a = a;
    p->b = b;
    { int g; asm volatile("move %0,$gp" : "=r"(g)); p->gp = g; }
    if (s)
        func_0030ee00();
    return 0;
}

/* libdbc */
extern int D_00363d10;
extern int D_01e2fe40;
extern char D_01e2d980[];
extern int D_01e2da80[];
int func_002f4f60(int x)
{
    int r;
    if (!D_00363d10)
        return 0;
    func_00305660(D_01e2fe40);
    D_01e2da80[0] = x;
    if (func_003094b8(D_01e2d980, 0x80001302, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcDeleteSocket: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    r = D_01e2da80[1];
    func_00305640(D_01e2fe40);
    return r;
}

int func_002f5498(int *p)
{
    int r;
    func_00305660(D_01e2fe40);
    D_01e2da80[2] = 2;
    D_01e2da80[4] = p[2];
    D_01e2da80[5] = p[3];
    if (func_003094b8(D_01e2d980, 0x8000131d, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcGetDeviceStatus: rpc error\n");
        func_00305640(D_01e2fe40);
        return -1;
    }
    r = D_01e2da80[1];
    func_00305640(D_01e2fe40);
    return r;
}

/* libcdvd (streaming/async rpc) */
struct C1324 { int pad[9]; int f; int rest[26]; };
extern struct C1324 D_01e33480;
extern int D_0036594c;
extern int D_00365948;
extern int D_00365950;
extern int D_01e33500[];
extern int D_01e34a40[];
extern void func_002fbba8(void *);
int func_002fbe98(int x)
{
    if (!D_01e33480.f)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    D_01e33500[0] = x;
    if (func_003094b8(&D_01e33480, 3, 1, D_01e33500, 48, D_01e34a40, 4, func_002fbba8, 0)) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 3;
    return 0;
}

int func_002fcb98(int x)
{
    if (!D_01e33480.f)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    D_01e33500[0] = x;
    if (func_003094b8(&D_01e33480, 10, 1, D_01e33500, 48, D_01e34a40, 4, func_002fbba8, 0)) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 10;
    return 0;
}

int func_002fbc78(int x)
{
    if (!D_01e33480.f)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    D_01e33500[1] = x;
    if (func_003094b8(&D_01e33480, 21, 0, D_01e33500, 48, D_01e34a40, 4, 0, 0)) {
        func_00305640(D_0036594c);
        return -91;
    }
    func_00305640(D_0036594c);
    return D_01e34a40[0];
}

int func_002fc378(int mode, int *cmd, int *result)
{
    int busy;
    if (!D_00365948)
        return -1;
    busy = 0;
    if (func_00305670(D_00365950) < 0)
        busy = 1;
    if (mode == 0 && busy) {
        func_00305660(D_00365950);
        busy = 0;
    }
    busy = !busy;
    if (cmd)
        *cmd = D_00365948;
    if (busy) {
        D_00365948 = 0;
        if (result)
            *result = D_01e34a40[0];
        func_00305640(D_0036594c);
    }
    return busy;
}

/* libvu0 */
typedef float VEC1324[4] __attribute__((aligned(16)));
extern void func_002f3f40(float *, float *, float);
extern void func_002f3d98(float *, float *);
extern void func_002f3dd8(VEC1324 *, VEC1324 *);
void func_002f43c0(VEC1324 *m, float *a, float *b, float *c)
{
    VEC1324 w;
    func_002f3f40(w, a, -1.0f);
    func_002f3d98(m[0], w);
    func_002f3f40(w, b, -1.0f);
    func_002f3d98(m[1], w);
    func_002f3f40(w, c, -1.0f);
    func_002f3d98(m[2], w);
    m[3][0] = m[3][1] = m[3][2] = 0.0f;
    m[3][3] = 1.0f;
    func_002f3dd8(m, m);
}

/* libgraph */
struct GP1324 { short a, b, c, mode; };
extern struct GP1324 *func_002f1fa8(void);
struct DE1324 { u64 pmode, smode2, dispfb, display, bgcolor; };
#define GSR(x) (*(volatile u64 *)(x))
void func_002f2448(struct DE1324 *e)
{
    if (func_002f1fa8()->mode == 1) {
        GSR(0x12000000) = e->pmode;
        GSR(0x12000070) = e->dispfb;
        GSR(0x12000080) = e->display;
        GSR(0x120000c0) = e->bgcolor;
    } else {
        GSR(0x12000000) = e->pmode;
        GSR(0x12000020) = e->smode2;
        GSR(0x12000090) = e->dispfb;
        GSR(0x120000a0) = e->display;
        GSR(0x120000e0) = e->bgcolor;
    }
}
