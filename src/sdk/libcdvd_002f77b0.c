/* Sony PS2 Runtime Library 3.0.0: libcdvd (libcdvd.a), 0x2f77b0-0x2f8010: the end of the object after
 * sceCdInit (0x2f74c8): sceCdDiskReady (old and new RPC versions), sceCdRead, the S-command
 * wrappers and sceCdChgSys. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv): a part of the object, compiled as one file. Its .rodata (the messages) is at
 * 0x376d10; the object's .data and .bss stay outside, reached by name. */
typedef unsigned int u32;
typedef struct { int pad[9]; void *serve; int pad2[6]; } CdClient;
typedef struct { unsigned char trycount, spindlctrl, datapattern, pad; } RMode;
typedef struct { unsigned int lsn, sec; void *buf; unsigned char t, s, d, p; void *ee; void *rd; } RArg;

extern int scePrintf(const char *fmt, ...) asm("func_003080d0");
extern int DIntr(void);
extern int EIntr(void);
extern int sceSifBindRpc(CdClient *cd, unsigned int rpc, int mode);
extern int sceSifCallRpc(void *cd, int fno, int mode, void *sb, int ss, void *rb, int rs, void *ef, void *ea);
extern void func_00308a80(void *p, int n);
extern void func_00308b30(int m);
extern int func_00305670(int s);
extern int func_00305640(int s);
extern int func_002f69c8(void);
extern int func_002f6fc0(int);
extern int func_002f7118(void);
extern int func_002f7250(int m);
extern int func_002f72c0(int);
extern void func_002f6910(void *);

extern int D_00363d90;
extern volatile int D_00363da8;
extern volatile int D_00363dac;
extern volatile int D_00363db0;
extern int D_00363db4;
extern int D_00363db8;
extern int D_00363dc0;
extern int D_00363dd0;
extern int D_00363de0;
extern volatile int D_00363de0_v asm("D_00363de0");
extern RArg D_00363e80;
extern char D_00364e80[];
extern int D_00364f40;
extern char D_00364f50[];
extern int D_00364f80[4];
extern int D_003653c0[];
extern int D_00365800[4];
extern char D_00365900[];
extern int D_00365928;
extern int D_0036592c;
extern int D_00365930;
extern CdClient D_01e33410;
extern int D_01e33450[4];

int func_002f77b0(int mode)
{
    int i;
    int r;
    if (D_00363d90 > 0)
        scePrintf("OLD DiskReady Call\n");
    i = DIntr();
    D_00363dc0 = 1;
    if (i)
        EIntr();
    func_002f69c8();
    if (D_00363dac != func_00305670(D_00363dac))
        return 6;
    if (func_002f7250(1)) {
        func_00305640(D_00363dac);
        if (mode == 8)
            return -1;
        return 6;
    }
    func_00308b30(0);
    if (D_00363dd0 < 0) {
        while (1) {
            if (sceSifBindRpc(&D_01e33410, 0x8000059a, 0) < 0) {
                if (D_00363d90 > 0)
                    scePrintf("Libcdvd bind err CdDiskReady\n");
                i = 0x100000;
                while (i--)
                    ;
                continue;
            }
            if (D_01e33410.serve != 0) {
                D_00363dd0 = 0;
                break;
            }
            i = 0x100000;
            while (i--)
                ;
        }
    }
    D_01e33450[0] = mode;
    func_00308a80(D_01e33450, 4);
    if (sceSifCallRpc(&D_01e33410, 0, 0, D_01e33450, 4, D_00364f80, 4, 0, 0) < 0) {
        func_00305640(D_00363dac);
        if (mode == 8)
            return -1;
        return 6;
    }
    if (D_00363d90 > 0)
        scePrintf("DiskReady ended\n");
    r = *(int *)((unsigned int)D_00364f80 | 0x20000000);
    func_00305640(D_00363dac);
    return r;
}

/* sceCdDiskReady, new RPC version; falls back to the old one. */
int ctarget_002f79c8(int mode) asm("_Z16ctarget_002f79c8jjjj");
int ctarget_002f79c8(int mode)
{
    int i, cnt;
    int r;
    if (D_00363d90 > 0)
        scePrintf("NEW DiskReady Call\n");
    func_002f69c8();
    if (D_00363db0 != func_00305670(D_00363db0)) {
        if (mode == 8)
            return -1;
        return 6;
    }
    func_00308b30(0);
    cnt = 0;
    if (D_00363dd0 < 0) {
        while (1) {
            if (sceSifBindRpc(&D_01e33410, 0x8000059c, 0) < 0) {
                if (D_00363d90 > 0)
                    scePrintf("Libcdvd bind err CdDiskReady\n");
                i = 0x100000;
                while (i--)
                    ;
                continue;
            }
            if (D_01e33410.serve != 0) {
                D_00363dd0 = 0;
                break;
            }
            if (cnt >= 17) {
                func_00305640(D_00363db0);
                return func_002f77b0(mode);
            }
            i = 0x100000;
            while (i--)
                ;
            cnt++;
        }
    }
    i = DIntr();
    D_00363dc0 = 0;
    if (i)
        EIntr();
    D_01e33450[0] = mode;
    func_00308a80(D_01e33450, 4);
    if (sceSifCallRpc(&D_01e33410, 0, 0, D_01e33450, 4, D_00365800, 4, 0, 0) < 0) {
        func_00305640(D_00363db0);
        if (mode == 8)
            return -1;
        return 6;
    }
    if (D_00363d90 > 0)
        scePrintf("DiskReady ended\n");
    r = *(int *)((unsigned int)D_00365800 | 0x20000000);
    func_00305640(D_00363db0);
    return r;
}

/* sceCdRead. The semaphore id D_00363da8 is volatile like the flags around it: its load on the failure path stays
 * after both flag stores, and the assembler (as=ee-as row) moves it into the SignalSema jal delay slot. */
int func_002f7be8(unsigned int lsn, unsigned int sec, void *buf, RMode *mode)
{
    int size;
    RArg *p = &D_00363e80;
    if (!((*(int*)&D_00363db8) & 1) && func_002f7118() == 6)
        return 0;
    if (!func_002f6fc0(4))
        return 0;
    p->lsn = lsn;
    p->sec = sec;
    p->buf = buf;
    p->t = mode->trycount;
    p->s = mode->spindlctrl;
    p->d = mode->datapattern;
    p->ee = D_00364e80;
    p->rd = &D_00364f40;
    switch (mode->datapattern) {
    case 1: size = sec * 2328; break;
    case 2: size = sec * 2340; break;
    case 0: default: size = sec << 11; break;
    }
    D_00364f40 = 0;
    if (!((*(volatile int*)&D_00363db8) & 2))
        func_00308a80(buf, size);
    func_00308a80(D_00364e80, 144);
    func_00308a80(p, 24);
    func_00308a80(&D_00364f40, 4);
    if (D_00363d90 > 0)
        scePrintf("call cdread cmd\n");
    (*(volatile int*)&D_00363de0) = 1;
    (*(volatile int*)&D_00363db4) = 1;
    if (sceSifCallRpc(D_00364f50, 1, 1, p, 24, 0, 0, func_002f6910, D_00364e80) < 0) {
        (*(volatile int*)&D_00363de0) = 0;
        (*(volatile int*)&D_00363db4) = 0;
        func_00305640(D_00363da8);
        return 0;
    }
    if (D_00363d90 > 0)
        scePrintf("cdread end\n");
    return 1;
}

/* The old separate files declared some of the shared names differently; the code follows those types. */
extern void func_00305640_v(int s) asm("func_00305640");
extern int D_00363dac_nv asm("D_00363dac");

int func_002f7dc8(void)
{
    int r;
    if (!func_002f72c0(3)) return -1;
    if (sceSifCallRpc(D_00365900, 4, 0, 0, 0, D_00364f80, 4, 0, 0) < 0) {
        func_00305640_v(D_00363dac_nv);
        return -1;
    }
    r = *(int *)((u32)D_00364f80 | 0x20000000);
    func_00305640_v(D_00363dac_nv);
    return r;
}

int func_002f7e60(void)
{
    int r;
    if (!func_002f72c0(30))
        return 0;
    D_00363de0_v = 8;
    if (sceSifCallRpc(D_00365900, 22, 0, 0, 0, D_00364f80, 4, 0, 0) < 0) {
        func_00305640(D_00363dac);
        D_00363de0_v = 0;
        return 0;
    }
    D_00363de0_v = 0;
    r = *(int *)((int)D_00364f80 | 0x20000000);
    func_00305640(D_00363dac);
    return r;
}

int func_002f7f18(int a)
{
    int r;
    int *p = D_003653c0;
    if (!func_002f72c0(34)) return 0;
    *p = a;
    func_00308a80(p, 4);
    if (sceSifCallRpc(D_00365900, D_00365928, 0, p, D_0036592c, D_00364f80, D_00365930, 0, 0) < 0) {
        func_00305640(D_00363dac_nv);
        return 0;
    }
    r = *(int *)((u32)D_00364f80 | 0x20000000);
    func_00305640(D_00363dac_nv);
    return r;
}

int sceCdChgSys(int a)
{
    scePrintf("sceCdChgSys: Illegal_function_call\n");
    return 2;
}
