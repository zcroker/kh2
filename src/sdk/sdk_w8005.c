/* Sony PS2 Runtime Library 3.0.0: libkernl stdio (fd table lookup, AddDrv). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int a, b, c, d; } Q;
extern int func_00305640(int);
extern int func_00305660(int);
extern int func_00309be8(void);
extern int D_00366170;
extern Q D_01e38780[];

Q* func_00309e50(unsigned int n) {
    Q* p;
    int r;
    r = func_00309be8();
    func_00305660(D_00366170);
    if (n >= 32) {
        func_00305640(D_00366170);
        return 0;
    }
    p = &D_01e38780[n];
    func_00305640(D_00366170);
    return p;
}

typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam;
typedef struct { int sema; int *ret; int size; int arg; } AddDrvSend;
extern int func_00305620(SemaParam *);
extern int func_00305630(int);
extern int func_00305660(int);
extern int func_0030a2d0(int);
extern void func_0030a300(void);
extern void func_0030a3f8(void);
extern int D_00366164;
extern AddDrvSend D_01e37280;
extern int D_01e37ec0;
extern char D_01e38980[];
extern int func_00309d60(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int x);
int func_0030c008(int arg)
{
    SemaParam p;
    int ret;
    int sema;
    int r;
    AddDrvSend *snd = &D_01e37280;
    r = func_0030a2d0(15);
    if (!D_00366164)
        func_0030a3f8();
    snd->arg = arg;
    p.max_count = 1;
    p.option = (unsigned int)"SceStdioAddDrvSema";
    p.init_count = 0;
    sema = func_00305620(&p);
    D_01e37280.sema = sema;
    D_01e37280.ret = &ret;
    D_01e37280.size = 4;
    if (func_00309d60(D_01e38980, 15, 0, &D_01e37280, 16, &D_01e37ec0, 4, 0, 0, 0) < 0) {
        func_00305630(sema);
        func_0030a300();
        return -11;
    }
    r = *(int *)((unsigned int)&D_01e37ec0 | 0x20000000);
    func_0030a300();
    if (!r) {
        func_00305630(sema);
        return -11;
    }
    func_00305660(sema);
    func_00305630(sema);
    return ret;
}
