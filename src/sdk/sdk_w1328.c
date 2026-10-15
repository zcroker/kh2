/* libcdvd / libmc / libpad / libkernl / libdma misc (Sony PS2 Runtime Library 3.0.0) */
typedef unsigned int u32;

extern int func_003094b8(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
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
int func_002f7f18(int a)
{
    int r;
    int *p = D_003653c0;
    if (!func_002f72c0(34)) return 0;
    *p = a;
    func_00308a80(p, 4);
    if (func_003094b8(D_00365900, D_00365928, 0, p, D_0036592c, D_00364f80, D_00365930, 0, 0) < 0) {
        func_00305640(D_00363dac);
        return 0;
    }
    r = *(int *)((u32)D_00364f80 | 0x20000000);
    func_00305640(D_00363dac);
    return r;
}

typedef struct { int x0; volatile int x4; unsigned char *x8; } Q1328;
typedef struct { int pad[6]; Q1328 *x18; } S1328;
extern S1328 D_01e353d0;
extern void func_00306968(Q1328 *);
int func_00306cb8(char *buf, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        while (D_01e353d0.x18->x4 == 0)
            ;
        buf[i] = *D_01e353d0.x18->x8;
        func_00306968(D_01e353d0.x18);
        if (buf[i] == '\n' || buf[i] == '\r')
            return i + 1;
    }
    return i;
}

typedef struct { int pad[4]; unsigned int x10; int x14; int x18; int x1c; int x20; int x24; int x28; } R1328;
typedef struct { int pad[5]; int x14; int x18; int x1c; int x20; int x24; int x28; int x2c; } P1328;
extern P1328 *func_00308df0(int, unsigned int);
extern P1328 *func_00308dc0(int);
extern int func_003088f8(int, P1328 *, int, int, int, int);
extern void func_00310b70(int, void *, P1328 *);
extern void D_00308f00(void);
void func_00308f40(R1328 *r, int a)
{
    P1328 *p;
    if (r->x10 & 4)
        p = func_00308df0(a, r->x10 >> 16);
    else
        p = func_00308dc0(a);
    {int t14 = r->x14, t1c = r->x1c;
    p->x14 = t14;
    p->x1c = t1c;}
    p->x20 = 0x8000000c;
    p->x24 = r->x20;
    p->x28 = r->x24;
    p->x2c = r->x28;
    if (func_003088f8(0x80000008, p, 0x40, r->x20, r->x24, r->x28) == 0)
        func_00310b70(0x800, D_00308f00, p);
}

typedef struct { int x0; int x4; int pad[3]; char x14[0x334 - 0x14]; } E1328;
typedef struct { unsigned char x0, x1, x2, x3; int x4; int pad[5]; unsigned char x1c[1]; } F1328;
extern E1328 D_01e2fe48[];
extern int func_002f62b8(int);
extern F1328 *func_002f6310(int);
extern void *func_002fdd68(void *, void *, int);
extern int func_002f6440(void *, void *);
int func_002f5e78(int port, void *buf)
{
    F1328 *p;
    int n;
    if (D_01e2fe48[port].x0 == 0) return -1;
    if (D_01e2fe48[port].x4 == 0 && func_002f62b8(port) < 0) return -1;
    p = func_002f6310(port);
    n = p->x2;
    if (n != 0 && p->x1c != 0) {
        func_002fdd68(buf, p->x1c, n);
        func_002f6440(p->x1c + p->x2, D_01e2fe48[port].x14);
    }
    if (p->x4 == 0) return -1;
    return p->x2;
}

typedef struct { int a; int b; } G1328;
extern G1328 D_003670d8[];
extern char D_00366970[];
extern char D_003670b0[];
extern void func_0030f4e0(int, int);
extern void func_0030f4f0(int, void *, int);
extern int func_0030f538(int);
extern void func_003058a0(int);
void func_0030f548(void)
{
    unsigned int i;
    if (*(volatile int *)0x10001810 & 0x100) return;
    func_0030f4e0(D_003670d8[0].a, D_003670d8[0].b);
    func_0030f4f0(0x80076000, D_00366970, 0x740);
    func_0030f4f0(0x82000, D_003670b0, 0x28);
    func_003058a0(0);
    func_003058a0(2);
    func_0030f4e0(D_003670d8[1].a, D_003670d8[1].b);
    for (i = 2; i < 8; i++)
        func_0030f4e0(D_003670d8[i].a, func_0030f538(D_003670d8[i].a));
}

typedef struct { int a; int type; union { unsigned char b; unsigned short h; int w; } v; } I1328;
extern I1328 D_01e38c40;
extern char D_01e38e40[];
extern int func_0030dd70(void);
extern int func_003094b8(void *, int, int, void *, int, void *, int, void *, void *);
int func_0030e9f0(int a, void *val, int type)
{
    if (func_0030dd70() < 0) return 0xffff0000;
    D_01e38c40.a = a;
    D_01e38c40.type = type;
    if (type == 0) D_01e38c40.v.b = *(unsigned char *)val;
    else if (type == 1) D_01e38c40.v.h = *(unsigned short *)val;
    else if (type == 2) D_01e38c40.v.w = *(int *)val;
    else return 0xfffefffe;
    if (func_003094b8(D_01e38e40, 2, 0, &D_01e38c40, 32, &D_01e38c40, 16, 0, 0) < 0) return 0xfffeffff;
    return 0;
}

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
extern int func_003094b8(void *, int, int, void *, int, void *, int, void *, void *);
int func_002fbf58(int a, int b, int c)
{
    if (D_01e33480.x24 == 0) return -100;
    if (func_00305670(D_0036594c) < 0) return -200;
    D_01e33500.x0 = a;
    D_01e33500.x10 = b;
    D_01e33500.x14 = c;
    if (func_003094b8(&D_01e33480, 4, 1, &D_01e33500, 48, D_01e34a40, 4, D_002fbba8, 0) != 0) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 4;
    return 0;
}
