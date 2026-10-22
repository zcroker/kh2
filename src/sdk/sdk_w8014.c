/* Sony PS2 Runtime Library 3.0.0: libdma (sceDmaReset), libcdvd (semaphore init, N/S command checks). ee-gcc 2.9-991111 -O2 -G0. */
typedef unsigned int u_int;
typedef struct { int x0; int p0[3]; int x10; int p1[7]; int x30; int p2[3]; int x40; int p3[3]; int x50; int p4[11]; int x80; } Ch1328;
extern Ch1328 *D_00363c90[];
extern int D_003767e8[];
extern void func_002f35b0(void *, int);
extern int func_002f36f0(void *);
int func_002f3610(int mode)
{
    int buf[8];
    int r;
    int i;
    r = *(volatile u_int *)0x1000e000 & 1;
    for (i = 0; i < 10; i++) {
        if (D_003767e8[i]) {
            D_00363c90[i]->x0 = 0;
            D_00363c90[i]->x30 = 0;
            D_00363c90[i]->x10 = 0;
            D_00363c90[i]->x50 = 0;
            D_00363c90[i]->x40 = 0;
            D_00363c90[i]->x80 = 0;
        }
    }
    *(volatile u_int *)0x1000e010 = 0xff1f;
    *(u_int *)0x1000e010 = *(volatile u_int *)0x1000e010 & 0xff1f0000;
    func_002f35b0(buf, 20);
    func_002f36f0(buf);
    if (mode == 1)
        *(volatile u_int *)0x1000e000 = *(volatile u_int *)0x1000e000 | 1;
    return r;
}

typedef struct { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; } SemaParam1328;
extern int func_00305620(SemaParam1328 *);
extern volatile int D_00363da8;
extern volatile int D_00363dac;
extern volatile int D_00363db0;
extern volatile int D_00363da0;
extern volatile int D_00363db4;
void func_002f69c8(void)
{
    SemaParam1328 s;
    if (D_00363da8 != -1 && D_00363dac != -1 && D_00363db0 != -1) return;
    s.initCount = 1;
    s.maxCount = 1;
    s.option = (unsigned int)"SceCdNcmdSema";
    D_00363da8 = func_00305620(&s);
    s.option = (unsigned int)"SceCdScmdSema";
    D_00363dac = func_00305620(&s);
    s.option = (unsigned int)"SceCdRcmdSema";
    D_00363db0 = func_00305620(&s);
    s.initCount = 0;
    s.option = (unsigned int)"SceCdCallbackSema";
    D_00363da0 = func_00305620(&s);
    D_00363db4 = 0;
}

typedef struct { int x[9]; int serve; int pad[32]; } CdRpc;
extern int D_00363d90;
extern int D_00363d9c;
extern int D_00363dbc;
extern CdRpc D_00364f50;
extern void func_002f69c8(void);
extern int func_00305670(int);
extern void func_00305640(int);
extern int func_002f5c48(const char *, ...);
extern int func_003080d0(const char *, ...);
extern int func_002f71b0(int);
extern void func_00308b30(int);
extern int func_003092d8(CdRpc *, unsigned int, int);

int func_002f6fc0(int cmd)
{
    int i;
    func_002f69c8();
    if (D_00363da8 != func_00305670(D_00363da8)) {
        if (D_00363d90 > 0)
            func_003080d0("Ncmd fail sema cur_cmd:%d keep_cmd:%d\n", cmd, D_00363d9c);
        return 0;
    }
    D_00363d9c = cmd;
    if (func_002f71b0(1)) {
        func_00305640(D_00363da8);
        return 0;
    }
    func_00308b30(0);
    if (D_00363dbc < 0) {
        while (1) {
            if (func_003092d8(&D_00364f50, 0x80000595, 0) < 0) {
                if (D_00363d90 > 0) func_003080d0("Libcdvd bind err N CMD\n");
                i = 0x100000; while (i--) ;
                continue;
            }
            if (D_00364f50.serve != 0) break;
            i = 0x100000; while (i--) ;
        }
        D_00363dbc = 0;
    }
    return 1;
}

extern int D_00363d98;
extern int D_00363dd4;
extern CdRpc D_00365900;
extern int func_002f7250(int);

int func_002f72c0(int cmd)
{
    int i;
    func_002f69c8();
    if (D_00363dac != func_00305670(D_00363dac)) {
        if (D_00363d90 > 0)
            func_003080d0("Scmd fail sema cur_cmd:%d keep_cmd:%d\n", cmd, D_00363d98);
        return 0;
    }
    D_00363d98 = cmd;
    if (func_002f7250(1)) {
        func_00305640(D_00363dac);
        return 0;
    }
    func_00308b30(0);
    if (D_00363dd4 < 0) {
        while (1) {
            if (func_003092d8(&D_00365900, 0x80000593, 0) < 0) {
                if (D_00363d90 > 0) func_003080d0("Libcdvd bind err S cmd\n");
                i = 0x100000; while (i--) ;
                continue;
            }
            if (D_00365900.serve != 0) break;
            i = 0x100000; while (i--) ;
        }
        D_00363dd4 = 0;
    }
    return 1;
}

