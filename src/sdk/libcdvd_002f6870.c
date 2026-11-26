/* Sony PS2 Runtime Library 3.0.0: libcdvd (libcdvd.a), 0x2f6870-0x2f77b0: the C run after the whole-asm callback
 * thread (0x2f67a0): sceCdInitEeCB, the read-end copy, semaphore setup, the callback helpers, sceCdSearchFile,
 * the N/S command checks and sceCdInit. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv): a part of the object, compiled as one file. Its .rodata (thread and semaphore
 * names, messages) is at 0x376b70; the object's .data and .bss stay outside, reached by name. The functions were
 * matched one by one with slightly different declarations of the shared names; each keeps its own (suffixed
 * aliases). Partial inline asm only for the $gp save/switch around the user callback (asm_review.tsv). */
typedef unsigned int u32;
#define UC(p) ((void *)((unsigned int)(p) | 0x20000000))

typedef struct { int pad[9]; void *serve; int pad2[6]; } CdClient;
typedef struct { int x[9]; int serve; int pad[32]; } CdRpc;

extern int DIntr(void);
extern int EIntr(void);
extern int scePrintf(const char *fmt, ...) asm("func_003080d0");
extern int sceSifBindRpc(void *cd, unsigned int rpc, int mode);
extern int sceSifCallRpc(void *cd, int fno, int mode, void *sb, int ss, void *rb, int rs, void *ef, void *ea);
extern int func_00305630(int s);
extern int func_00305640(int s);
extern void func_00305640_v(int s) asm("func_00305640");
extern int func_00305670(int s);
extern void func_00306698(int);
extern int func_003096b8(void *);
extern void func_00308730(int);
extern void func_00308b30(int m);
extern int func_00308a80(void *p, int n);
extern int func_002f6700(void *);

extern int D_00363d90;
extern int D_00363d94;
extern int D_00363d98;
extern int D_00363d9c;
extern int D_00363da4;
extern int D_00363da8;
extern int D_00363dac;
extern int D_00363db4;
extern int D_00363dbc;
extern int D_00363dc8;
extern int D_00363dcc;
extern int D_00363dd4;
extern int D_00363de0;
extern int D_01e331c8;
extern int D_01e331cc;
extern int D_01e331d0;

/* ---- sceCdInitEeCB: starts the callback thread (whole-asm 0x2f67a0). */
typedef struct { int status; void *func; void *stack; int size; void *gp; int prio; int cur; u32 attr; void *option; } TP;
extern TP D_01e331d8;
extern char D_002f67a0[];
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
        D_01e331d8.option = "SceCdCallbackThread";
        D_01e331d8.gp = 0;
        D_00363d94 = func_00305420(&D_01e331d8);
        func_00306760(D_00363d94, 0);
    } else {
        func_003054b0(D_00363d94, prio);
        r = 0;
    }
    return r;
}

/* ---- Read end (RPC end function of sceCdRead): copies the unaligned head and tail bytes to the cached and
 * uncached views of the user buffer, then runs the end-of-command callback. */
typedef struct { int size1; int size2; char *dest1; char *dest2; char buf1[64]; char buf2[64]; } RD;
extern int D_00363de0_a asm("D_00363de0");
void func_002f6910(RD *d)
{
    RD *u = UC(d);
    int i;
    if (u->size1 > 0) {
        char *dst = u->dest1;
        char *udst = UC(dst);
        for (i = 0; i < u->size1; i++)
            dst[i] = udst[i] = u->buf1[i];
    }
    if (u->size2 > 0) {
        char *dst = u->dest2;
        char *udst = UC(dst);
        for (i = 0; i < u->size2; i++)
            dst[i] = udst[i] = u->buf2[i];
    }
    func_002f6700(&D_00363de0_a);
}

/* ---- Creates the N/S/R command and callback semaphores once. */
typedef struct { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; } SemaParam;
extern int func_00305620(SemaParam *);
extern int D_00363da8_v asm("D_00363da8");
extern int D_00363dac_v asm("D_00363dac");
extern volatile int D_00363db0_v asm("D_00363db0");
extern volatile int D_00363da0_v asm("D_00363da0");
extern volatile int D_00363db4_v asm("D_00363db4");
void func_002f69c8(void)
{
    SemaParam s;
    if (D_00363da8_v != -1 && D_00363dac_v != -1 && D_00363db0_v != -1) return;
    s.initCount = 1;
    s.maxCount = 1;
    s.option = (unsigned int)"SceCdNcmdSema";
    D_00363da8_v = func_00305620(&s);
    s.option = (unsigned int)"SceCdScmdSema";
    D_00363dac_v = func_00305620(&s);
    s.option = (unsigned int)"SceCdRcmdSema";
    D_00363db0_v = func_00305620(&s);
    s.initCount = 0;
    s.option = (unsigned int)"SceCdCallbackSema";
    D_00363da0_v = func_00305620(&s);
    D_00363db4_v = 0;
}

/* ---- Deletes the semaphores and the callback handler. */
extern int D_00363da0;
extern int D_00363db0;
void func_002f6ab0(void)
{
    int s;
    if (D_00363d94 != 0) {
        D_00363de0 = -1;
        __asm__ volatile("" ::: "memory");
        func_00305640(D_00363da0);
    }
    func_00305630(D_00363da8);
    func_00305630(D_00363dac);
    func_00305630(D_00363db0);
    func_00305630(D_00363da0);
    s = DIntr();
    func_00308730(0x80000012);
    if (s != 0)
        EIntr();
}

/* ---- Installs the user callback and the caller's $gp. */
extern void func_002f6c28_v(void) asm("func_002f6c28");
int func_002f6b50(int a, int b)
{
    int old, s;
    if (D_00363dc8 < 0)
        func_002f6c28_v();
    s = DIntr();
    old = D_01e331c8;
    D_01e331d0 = b;
    D_01e331c8 = a;
    /* save the caller's $gp: C has no way to read it */
    asm volatile("sw $28,%0" : "=m"(D_01e331cc));
    if (s) EIntr();
    return old;
}

/* ---- Runs the callback registered by func_002f6b50 with the $gp it saved. */
void func_002f6bd0(void)
{
    void (*cb)(int) = (void (*)(int))D_01e331c8;
    if (cb && !D_00363da4) {
        int old;
        /* switch to the callback's $gp; C has no way to read or set it */
        asm volatile("move %0,$28\n\tlw $28,%1" : "=r"(old) : "m"(D_01e331cc));
        cb(D_01e331d0);
        asm volatile("move $28,%0" : : "r"(old));
    }
}

/* ---- Registers func_002f6bd0 as the interrupt-time callback handler. */
extern void func_003086b8(int n, void *fn, void *arg);
extern void EIntr_v(void) asm("EIntr");
int func_002f6c28(void)
{
    int st;
    D_00363da4 = 1;
    st = DIntr();
    func_003086b8(0x80000012, func_002f6bd0, 0);
    if (st)
        EIntr_v();
    D_00363da4 = 0;
    D_00363dc8 = 1;
    return 1;
}

/* ---- sceCdSearchFile */
typedef struct { unsigned int lsn; unsigned int size; char name[16]; unsigned char date[8]; unsigned int flag; } CdlFILE;
typedef struct { int pad[9]; char name[256]; void *buf; int x128; } SearchArg;
extern void scePrintf_v(const char *fmt, ...) asm("func_003080d0");
extern void func_002f69c8_v(void) asm("func_002f69c8");
extern int func_002f71b0(int m);
extern volatile int D_00363da8_s asm("D_00363da8");
extern SearchArg D_01e33240;
extern int D_01e33380[4];
extern CdClient D_01e333c0;
int sceCdSearchFile(CdlFILE *fp, const char *name, int x) asm("_Z15sceCdSearchFilejjjj");
int sceCdSearchFile(CdlFILE *fp, const char *name, int x)
{
    int i;
    int j;
    int r;
    func_002f69c8_v();
    if (D_00363da8_s != func_00305670(D_00363da8_s))
        return 0;
    D_00363d9c = 1;
    if (func_002f71b0(1)) {
        func_00305640(D_00363da8_s);
        return 0;
    }
    func_00308b30(0);
    if (D_00363dcc < 0) {
        while (1) {
            if (sceSifBindRpc(&D_01e333c0, 0x80000597, 0) < 0) {
                if (D_00363d90 > 0)
                    scePrintf_v("Libcdvd bind err CdSearchFile\n");
                j = 0x100000;
                while (j--)
                    ;
                continue;
            }
            if (D_01e333c0.serve != 0) {
                D_00363dcc = 0;
                break;
            }
            j = 0x100000;
            while (j--)
                ;
        }
    }
    for (i = 0; i < 256; i++)
        if ((D_01e33240.name[i] = name[i]) == 0)
            break;
    if (i == 256)
        D_01e33240.name[255] = 0;
    if (D_00363d90 > 0)
        scePrintf_v("ee call cmd search %s\n", D_01e33240.name);
    D_01e33240.x128 = x;
    D_01e33240.buf = &D_01e33240;
    func_00308a80(&D_01e33240, 300);
    if (sceSifCallRpc(&D_01e333c0, 0, 0, &D_01e33240, 300, D_01e33380, 4, 0, 0) < 0) {
        func_00305640(D_00363da8_s);
        return 0;
    }
    __builtin_memcpy(fp, (void *)((unsigned int)&D_01e33240 | 0x20000000), sizeof(CdlFILE));
    if (D_00363d90 > 0)
        scePrintf_v("search name %s\n", fp->name);
    if (D_00363d90 > 0)
        scePrintf_v("search size %d\n", fp->size);
    if (D_00363d90 > 0)
        scePrintf_v("search loc lbn %d\n", fp->lsn);
    r = *(int *)((unsigned int)D_01e33380 | 0x20000000);
    func_00305640(D_00363da8_s);
    return r;
}

int func_002f6fa0(CdlFILE *fp, const char *name)
{
    return sceCdSearchFile(fp, name, 0);
}

/* ---- N command check: waits for the N-command semaphore and binds the RPC server once. */
extern CdRpc D_00364f50_r asm("D_00364f50");
extern volatile int D_00363da8_n asm("D_00363da8");
int func_002f6fc0(int cmd)
{
    int i;
    func_002f69c8_v();
    if (D_00363da8_n != func_00305670(D_00363da8_n)) {
        if (D_00363d90 > 0)
            scePrintf("Ncmd fail sema cur_cmd:%d keep_cmd:%d\n", cmd, D_00363d9c);
        return 0;
    }
    D_00363d9c = cmd;
    if (func_002f71b0(1)) {
        func_00305640_v(D_00363da8_n);
        return 0;
    }
    func_00308b30(0);
    if (D_00363dbc < 0) {
        while (1) {
            if (sceSifBindRpc(&D_00364f50_r, 0x80000595, 0) < 0) {
                if (D_00363d90 > 0) scePrintf("Libcdvd bind err N CMD\n");
                i = 0x100000; while (i--) ;
                continue;
            }
            if (D_00364f50_r.serve != 0) break;
            i = 0x100000; while (i--) ;
        }
        D_00363dbc = 0;
    }
    return 1;
}

/* ---- N command 14 (status). */
extern char D_00364f50[];
extern char D_00363e00[];
int func_002f7118(void)
{
    int r;
    if (!func_002f6fc0(2)) return 0;
    if (sceSifCallRpc(D_00364f50, 14, 0, 0, 0, D_00363e00, 4, 0, 0) < 0) {
        func_00305640_v(D_00363da8);
        return 0;
    }
    r = *(int *)((u32)D_00363e00 | 0x20000000);
    func_00305640_v(D_00363da8);
    return r;
}

/* ---- N command busy check / wait. */
extern void scePrintf_p(void *) asm("func_003080d0");
int func_002f71b0(int mode)
{
    if (mode == 0) {
        if (D_00363d90 > 0)
            scePrintf_p("N cmd wait\n");
        while (D_00363db4 != 0 || func_003096b8(D_00364f50) != 0)
            func_00306698(4000);
        return 0;
    }
    if (D_00363db4 || func_003096b8(D_00364f50))
        return 1;
    return 0;
}

/* ---- S command busy check / wait. */
extern int D_00365900_i asm("D_00365900");
extern void scePrintf_i(const char *) asm("func_003080d0");
extern int func_003096b8_i(int *) asm("func_003096b8");
int func_002f7250(int a)
{
    if (a == 0) {
        if (D_00363d90 > 0)
            scePrintf_i("S cmd wait\n");
        while (func_003096b8_i(&D_00365900_i))
            func_00306698(4000);
        return 0;
    }
    return func_003096b8_i(&D_00365900_i);
}

/* ---- S command check: waits for the S-command semaphore and binds the RPC server once. */
extern CdRpc D_00365900_r asm("D_00365900");
extern volatile int D_00363dac_n asm("D_00363dac");
int func_002f72c0(int cmd)
{
    int i;
    func_002f69c8_v();
    if (D_00363dac_n != func_00305670(D_00363dac_n)) {
        if (D_00363d90 > 0)
            scePrintf("Scmd fail sema cur_cmd:%d keep_cmd:%d\n", cmd, D_00363d98);
        return 0;
    }
    D_00363d98 = cmd;
    if (func_002f7250(1)) {
        func_00305640_v(D_00363dac_n);
        return 0;
    }
    func_00308b30(0);
    if (D_00363dd4 < 0) {
        while (1) {
            if (sceSifBindRpc(&D_00365900_r, 0x80000593, 0) < 0) {
                if (D_00363d90 > 0) scePrintf("Libcdvd bind err S cmd\n");
                i = 0x100000; while (i--) ;
                continue;
            }
            if (D_00365900_r.serve != 0) break;
            i = 0x100000; while (i--) ;
        }
        D_00363dd4 = 0;
    }
    return 1;
}

/* 0x2f7418: maps an RPC function number to its result buffer; stores it through out. */
extern int D_00363da8_p asm("D_00363da8");
extern volatile int D_00363dac_p asm("D_00363dac");
extern char D_00363e00_p[] asm("D_00363e00");
extern char D_00363e80_p[] asm("D_00363e80");
extern char D_00364f50_p[] asm("D_00364f50");
extern char D_00364f80_p[] asm("D_00364f80");
extern char D_003653c0_p[] asm("D_003653c0");
extern char D_00365900_p[] asm("D_00365900");
int func_002f7418(int fno, void **out)
{
    *out = fno == 0x8001 ? (void *)D_00363da8_p
         : fno == 0x8003 ? (void *)D_00363e00_p
         : fno == 0x8002 ? (void *)D_00363e80_p
         : fno == 0x8004 ? (void *)D_00364f50_p
         : fno == 0x8011 ? (void *)D_00363dac_p
         : fno == 0x8013 ? (void *)D_00364f80_p
         : fno == 0x8012 ? (void *)D_003653c0_p
         : fno == 0x8014 ? (void *)D_00365900_p : 0;
    return 1;
}

/* 0x2f74c8: sceCdInit. Plain C (F41, 2026-11-20). The order of the init stores is what the register allocation
 * needs: the -1 store written last (0x363dc8) is issued first by the scheduler (the -1 register dies there) and its
 * address gets v0; the 0x363dd8 store written before it keeps its address register live to the end, so it is stored
 * last. Log: experiments/F41_002f74c8.md in the ledger. */
extern volatile int D_00363da0_ci asm("D_00363da0");
extern volatile int D_00363da4_ci asm("D_00363da4");
extern volatile int D_00363da8_ci asm("D_00363da8");
extern volatile int D_00363dac_ci asm("D_00363dac");
extern volatile int D_00363db8_ci asm("D_00363db8");
extern int D_00363dbc_ci asm("D_00363dbc");
extern int D_00363dc4_ci asm("D_00363dc4");
extern int D_00363dc8_ci asm("D_00363dc8");
extern int D_00363dcc_ci asm("D_00363dcc");
extern int D_00363dd0_ci asm("D_00363dd0");
extern int D_00363dd4_ci asm("D_00363dd4");
extern int D_00363dd8_ci asm("D_00363dd8");
extern int D_00363ddc_ci asm("D_00363ddc");
extern CdClient D_01e333e8_ci asm("D_01e333e8");
extern int D_01e33440_ci[4] asm("D_01e33440");
extern int D_00364f80_ci[4] asm("D_00364f80");
int sceCdInit(int mode)
{
    int i;
    int r;
    int ret;
    if (func_002f7250(1))
        return 0;
    func_00308b30(0);
    D_00363da4_ci = 1;
    D_00363dcc_ci = -1;
    D_00363dbc_ci = -1;
    D_00363dd4_ci = -1;
    D_00363dd0_ci = -1;
    D_00363dd8_ci = -1;
    D_00363dc8_ci = -1;
    D_00363db8_ci = 0;
    D_00363ddc_ci++;
    while (1) {
        if ((r = sceSifBindRpc(&D_01e333e8_ci, 0x80000592, 0)) < 0) {
            if (D_00363d90 > 0)
                scePrintf("Libcdvd bind err %d CD_Init %d\n", r, D_00363ddc_ci);
            i = 0x100000;
            while (i--)
                ;
            continue;
        }
        if (D_01e333e8_ci.serve != 0) {
            D_00363dd8_ci = 0;
            D_01e33440_ci[0] = mode;
            func_00308a80(D_01e33440_ci, 4);
            r = sceSifCallRpc(&D_01e333e8_ci, 0, 0, D_01e33440_ci, 4, D_00364f80_ci, 16, 0, 0);
            break;
        }
        i = 0x100000;
        while (i--)
            ;
    }
    if (r < 0) {
        D_00363da4_ci = 0;
        return 0;
    }
    {
        int a = *(int *)((unsigned int)&D_00364f80_ci[1] | 0x20000000);
        int b = *(int *)((unsigned int)&D_00364f80_ci[2] | 0x20000000);
        int c = *(int *)((unsigned int)&D_00364f80_ci[3] | 0x20000000);
        ret = 1;
        if (c != 255) {
            if (c == 254)
                D_00363d90 = 1;
            else if (a / 256 < 2 || b / 256 < 2)
                ret = 2;
        }
    }
    D_00363da4_ci = 0;
    switch (mode) {
    case 0:
    case 1:
        func_002f69c8();
        func_002f6c28();
        D_00363dc4_ci = 1;
        break;
    case 5:
        if (D_00363d90 > 0)
            scePrintf("Libcdvd Exit\n");
        func_002f6ab0();
        D_00363da8_ci = -1;
        D_00363dac_ci = -1;
        D_00363da0_ci = -1;
        D_00363dc4_ci = 0;
        break;
    default:
        func_002f69c8();
        func_002f6c28();
        D_00363dc4_ci = 1;
        break;
    }
    return ret;
}
