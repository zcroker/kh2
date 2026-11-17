/* Sony PS2 Runtime Library 3.0.0: libkernl (DMA/intc/thread lists), libpad2/libdbc helpers, libcdvd/sif rpc wrappers. ee-gcc 2.9-991111 -O2 -G0. */
typedef unsigned int u32;
extern int DIntr(void);
extern void EIntr(void);
extern void func_0030f6a0(int);
extern int func_0030ff08(void);
extern void func_0030fa10(int);

int func_0030f900(void);  // 0x0030f900: definition moved into src/sdk/libkernl_0030f688.c

int func_002f3c28(volatile u32 *p);  // 0x002f3c28: definition moved into src/sdk/libdma.c

typedef struct L { int f0, f4, f8, fc, f10; struct L *next; } L;
typedef struct { char pad[0x28]; L *head; } LH;
extern LH D_01e37200;
void func_003096f8(L *a, int b)
{
    L *p;
    DIntr();
    a->f0 = b; a->f4 = 0; a->f8 = 0; a->fc = 0; a->f10 = 0; a->next = 0;
    if (D_01e37200.head == 0) {
        D_01e37200.head = a;
    } else {
        p = D_01e37200.head;
        while (p->next) p = p->next;
        p->next = a;
    }
    EIntr();
}

typedef struct M { char pad[0x38]; struct M *next; } M;
typedef struct { int a, b; M *head; } MH;
M* func_00309860(M *a, MH *l)
{
    M *p;
    DIntr();
    p = l->head;
    if (p == a) {
        l->head = p->next;
    } else {
        while (p) {
            if (p->next == a) { p->next = a->next; break; }
            p = p->next;
        }
    }
    EIntr();
    return p;
}

typedef struct { short s0; short s2; int f4; int f8; int fc; } P;
extern P* sceGsGetGParam(void);
extern void DisableIntc(int);
extern void func_00305320(int, int);
extern int func_00305300(int, int, int);
extern void EnableIntc(int);
/* 0x002f33f0 sceGsSyncVCallback: definition moved into src/sdk/libgraph3.c */

extern void func_00305ab0(void);
extern long func_00305b40(void);
int sceGsSyncV(int x) asm("_Z10sceGsSyncVi") __attribute__((section(".text._Z13func_002f2508i")));
/* 0x002f2508 sceGsSyncV: definition moved into src/sdk/libgraph2.c */

extern int func_002f6fc0(int);
extern int func_002f72c0(int);
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
extern void func_00305640(int);
extern char D_00364f50[];
extern char D_00363e00[];
extern int D_00363da8;
int func_002f7118(void)
{
    int r;
    if (!func_002f6fc0(2)) return 0;
    if (sceSifCallRpc(D_00364f50, 14, 0, 0, 0, D_00363e00, 4, 0, 0) < 0) {
        func_00305640(D_00363da8);
        return 0;
    }
    r = *(int *)((u32)D_00363e00 | 0x20000000);
    func_00305640(D_00363da8);
    return r;
}

extern char D_00365900[];
extern char D_00364f80[];
extern int D_00363dac;
int func_002f7dc8(void)
{
    int r;
    if (!func_002f72c0(3)) return -1;
    if (sceSifCallRpc(D_00365900, 4, 0, 0, 0, D_00364f80, 4, 0, 0) < 0) {
        func_00305640(D_00363dac);
        return -1;
    }
    r = *(int *)((u32)D_00364f80 | 0x20000000);
    func_00305640(D_00363dac);
    return r;
}

typedef struct { int status; void *func; void *stack; int size; void *gp; int prio; int cur; u32 attr; void *option; } TP;
extern TP D_01e331d8;
extern int D_00363d94;
extern char D_002f67a0[];
extern char D_00376b70[];
extern int func_00305420(TP *);
extern void func_00306760(int, int);
extern void func_003054b0(int, int);
int sceCdInitEeCB(int prio, void *stack, int size)
{
    int r;
    r = 1;
    if (D_00363d94 == 0) {
        D_01e331d8.size = size;
        D_01e331d8.func = D_002f67a0;
        D_01e331d8.stack = stack;
        D_01e331d8.prio = prio;
        D_01e331d8.option = D_00376b70;
        D_01e331d8.gp = 0;
        D_00363d94 = func_00305420(&D_01e331d8);
        func_00306760(D_00363d94, 0);
    } else {
        func_003054b0(D_00363d94, prio);
        r = 0;
    }
    return r;
}

extern int sceOpen(void *, int);
extern int sceRead(int, void *, int);
extern int sceClose(int);
extern int atoi(char *);
extern char D_003762c8[];
int func_002f2020(void)
{
    char buf[256];
    char *p;
    u32 i;
    int fd;
    fd = sceOpen(D_003762c8, 1);
    if (fd < 0) return -1;
    for (i = 0, p = buf; i < 256; i++) {
        sceRead(fd, p, 1);
        if (*p++ == 0) break;
    }
    sceClose(fd);
    return atoi(&buf[i - 9]) > 0x1315670;
}
