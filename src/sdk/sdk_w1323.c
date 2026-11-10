/* Sony PS2 Runtime Library 3.0.0: libdbc (sceDbc*Socket/GetDeviceStatus), libvu0 (CameraMatrix), libpad2, libkernl (sbrk, printf buffer, thread/sema helpers). ee-gcc 2.9-991111 -O2 -G0. */
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
extern int func_002f5c48(const char *, ...);
extern int func_00305660(int);
extern int func_00305640(int);
extern int D_01e2fe40;
extern char D_01e2d980[];
extern int D_01e2da80[];
int sceDbcInitSocket(int x)
{
    int r;
    func_00305660(D_01e2fe40);
    D_01e2da80[0] = x;
    if (sceSifCallRpc(D_01e2d980, 0x80001315, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcInitSocket: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    r = D_01e2da80[1];
    func_00305640(D_01e2fe40);
    return r;
}

int sceDbcResetSocket(int x)
{
    int r;
    func_00305660(D_01e2fe40);
    D_01e2da80[0] = x;
    if (sceSifCallRpc(D_01e2d980, 0x80001316, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcResetSocket: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    r = D_01e2da80[1];
    func_00305640(D_01e2fe40);
    return r;
}

int sceDbcGetDeviceStatus(int x)
{
    int r;
    func_00305660(D_01e2fe40);
    D_01e2da80[0] = x;
    if (sceSifCallRpc(D_01e2d980, 0x80001317, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcGetDeviceStatus: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    r = D_01e2da80[1];
    func_00305640(D_01e2fe40);
    return r;
}

typedef struct { int on, kind, x8, xc; } E;
int func_002f6440(unsigned char *bits, E *e)
{
    int i, bit = 0, t1 = 0, a3 = 0;
    for (i = 0; i < 40; i++, e++) {
        if ((*bits >> bit) & 1) {
            e->on = 1;
            e->x8 = t1;
            e->xc = a3;
            if ((i >= 16 && i < 32) || (i >= 35 && i < 39)) {
                e->kind = 8;
                t1++;
            } else {
                a3++;
                e->kind = 1;
                if ((a3 & 7) == 0) {
                    t1++;
                    a3 = 0;
                }
            }
        } else {
            e->on = 0;
            e->x8 = 0;
            e->xc = 0;
        }
        bit++;
        if ((bit & 7) == 0) {
            bits++;
            bit = 0;
        }
    }
    return 1;
}

typedef float V4[4] __attribute__((aligned(16)));
extern void sceVu0UnitMatrix(V4 *);
extern void sceVu0OuterProduct(float *, float *, float *);
extern void sceVu0Normalize(float *, float *);
extern void sceVu0TransMatrix(V4 *, V4 *, float *);
extern void sceVu0InversMatrix(V4 *, V4 *);
void func_002f4310(V4 *m, float *p, float *zd, float *yd)
{
    V4 m0[4];
    V4 xd;
    sceVu0UnitMatrix(m0);
    sceVu0OuterProduct(xd, yd, zd);
    sceVu0Normalize(m0[0], xd);
    sceVu0Normalize(m0[2], zd);
    sceVu0OuterProduct(m0[1], m0[2], m0[0]);
    sceVu0TransMatrix(m0, m0, p);
    sceVu0InversMatrix(m, m0);
}

typedef struct { int a, b; } P;
extern P D_00366950[];
extern char D_003661a8[];
extern int func_0030f128(void);
extern void func_0030f0c0(int, int);
extern void func_0030f0d0(int, void *, int);
extern int func_0030f118(int);
extern void func_003058a0(int);
void func_0030f190(void)
{
    unsigned int i;
    if (func_0030f128() == 0)
        return;
    func_0030f0c0(D_00366950[0].a, D_00366950[0].b);
    func_0030f0d0(0x80074000, D_003661a8, 1960);
    func_003058a0(0);
    func_003058a0(2);
    func_0030f0c0(D_00366950[1].a, D_00366950[1].b);
    for (i = 2; i < 3; i++)
        func_0030f0c0(D_00366950[i].a, func_0030f118(D_00366950[i].a));
}

typedef struct { int x0, x4, x8, xc; long x10; } T;
typedef struct { char pad[0x1c]; int x1c; } G;
extern G D_00367118;
extern long func_0030ff08(void);
extern void func_0030fba0(T *);
extern void func_0030fa10(long);
int func_00310230(int id)
{
    T *p = (T *)(((unsigned int)id >> 10) << 6);
    long s;
    if (id < 0 || (id & 0x3ff) != p->x8)
        return 0x80008002;
    if (((volatile G *)&D_00367118)->x1c == id)
        return 0x80000010;
    if (p->xc & 1)
        return 1;
    s = func_0030ff08();
    p->x10 = s;
    p->xc |= 1;
    if (p->xc & 2) {
        func_0030fba0(p);
        func_0030fa10(s);
    }
    return 0;
}

extern int D_003660d4;
extern char D_01e35680[];
extern void func_003111f0(char *);
void func_00306e80(int c)
{
    int n = D_003660d4;
    if (n >= 126) {
        D_003660d4 = 0;
        D_01e35680[127] = 0;
        func_003111f0(D_01e35680);
        n = D_003660d4;
    }
    if (c == '\n') {
        D_01e35680[n] = c;
        D_003660d4 = 0;
        D_01e35680[n + 1] = 0;
        func_003111f0(D_01e35680);
    } else {
        D_003660d4 = n + 1;
        D_01e35680[n] = c;
    }
}

extern char *D_003660cc;
extern unsigned int func_00305600(void);
extern int* func_00316d08(void);
void* func_00305d20(int incr)
{
    int st, x;
    char *old, *nw;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st) {
        do {
            asm volatile("di");
            asm volatile("sync.p");
            asm volatile("mfc0 %0, $12" : "=r"(x));
        } while (x & 0x10000);
    }
    nw = D_003660cc + incr;
    if (func_00305600() < (unsigned int)nw) {
        *func_00316d08() = 12;
        if (st)
            asm volatile("ei");
        return (void *)-1;
    }
    old = D_003660cc;
    D_003660cc = nw;
    if (st)
        asm volatile("ei");
    return old;
}
