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
int sceAddDrv(int arg);  // 0x0030c008: definition moved into src/sdk/filestub.c
