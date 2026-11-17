/* libkernl_003081d0.c: Sony PS2 Runtime Library 3.0.0 libkernl: sifcmd (first part), 0x3081d0-0x3086b8.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
typedef unsigned int u_int;
extern int DIntr(void);
extern int EIntr(void);

typedef void (*CmdHandler)(void *, void *);
typedef struct { CmdHandler func; void *data; int x8; } SysCmd;
typedef struct { unsigned int pktbuf; void *cmdbuf; void *iopbuf; SysCmd *sys; int nsys; SysCmd *usr; int nusr; int *sregs; } CmdData;
typedef struct { unsigned int size; unsigned int dest; int cid; unsigned int opt; int a; int b; } CmdPkt;
extern CmdData D_01e357d8;
extern int D_01e35980[];

/* ---- 0x3081d0 (gap) */
void func_003081d0(CmdPkt *pkt, CmdData *c)
{
    c->sregs[pkt->a] = pkt->b;
}

/* ---- 0x3081f0 (gap) */
void func_003081f0(CmdPkt *pkt, CmdData *c)
{
    c->iopbuf = (void *)pkt->a;
}

/* ---- 0x308200 */
int func_00308200(int i)
{
    return D_01e35980[i];
}

/* ---- 0x308218 (gap) */
int func_00308218(int i, int v)
{
    return D_01e35980[i] = v;
}

/* ---- 0x308238 (gap) */
CmdData *func_00308238(void)
{
    return &D_01e357d8;
}

/* ---- 0x308248 */
typedef struct { u_int data, addr; int size, mode; } SifDmaData_w3695;
extern void *memcpy(void *, const void *, int);
extern int func_003059e0(SifDmaData_w3695 *, int);
extern int func_003059f0(SifDmaData_w3695 *, int);
extern int D_003780c0;
/* const: the load carries no anti-dependences on the stack stores, which gives sched2 the original order. */
extern const u_int D_01e357e0;
int func_00308248(SifDmaData_w3695 *src, int n, int mode)
{
    SifDmaData_w3695 d[32];
    if (n < 32) {
        memcpy(d, src, n * 16);
        d[n].data = (u_int)&D_003780c0;
        d[n].addr = D_01e357e0;
        d[n].size = 16;
        d[n].mode = 0x44;
        n++;
        if (mode == 0)
            return func_003059e0(d, n);
        return func_003059f0(d, n);
    }
    return 0;
}

/* ---- 0x308310 */
extern int D_003660d8;
extern unsigned char func_00308248_u(int, int, int) asm("func_00308248");
extern unsigned char func_003059e0_u(int, int) asm("func_003059e0");
int func_00308310(int a, int b)
{
    int s = DIntr();
    if (D_003660d8) {
        if (s) EIntr();
        return func_00308248_u(a, b, 0);
    } else {
        if (s) EIntr();
        return func_003059e0_u(a, b);
    }
}

/* ---- 0x308398 */
extern int func_00308248_i(int, int, int) asm("func_00308248");
extern int func_003059f0_i(int, int) asm("func_003059f0");
int func_00308398(int a, int b)
{
    if (D_003660d8)
        return func_00308248_i(a, b, 1);
    return func_003059f0_i(a, b);
}

/* ---- 0x3083d0: sceSifInitCmd. Field types matter: ee-gcc 2.9 -O2 uses type-based aliasing, so the
 * handler/data and cmdbuf/iopbuf types decide which stores the scheduler may move. */
typedef struct { unsigned int size; unsigned int dest; int cid; unsigned int opt; void *buf; } CaPkt;
extern SysCmd D_01e35800[];
extern char D_01e35700[];
extern char D_01e35780[];
extern CaPkt D_01e357c0;
extern int D_01e357d4;
extern int func_00308938(int);
extern void func_003058a0(int);
extern void func_00305a00(void);
extern int func_00305330(int, void *, int);
extern int EnableDmac(int);
extern unsigned int func_00305a30(unsigned int);
extern void func_00305a20(unsigned int, unsigned int);
extern int sceSifSendCmd(unsigned int, void *, int, void *, void *, int);
void func_003083d0(void)
{
    int i;
    unsigned int r;
    DIntr();
    if (D_003660d8) {
        EIntr();
        return;
    }
    D_003660d8 = 1;
    D_01e357d8.pktbuf = (unsigned int)D_01e35700 | 0x20000000;
    D_01e357d8.cmdbuf = (void *)((unsigned int)D_01e35780 | 0x20000000);
    D_01e357d8.iopbuf = 0;
    D_01e357d8.sys = D_01e35800;
    D_01e357d8.nsys = 32;
    D_01e357d8.usr = 0;
    D_01e357d8.nusr = 0;
    D_01e357d8.sregs = D_01e35980;
    for (i = 0; i < 32; i++) {
        D_01e35800[i].func = 0;
        D_01e35800[i].data = 0;
    }
    for (i = 0; i < 32; i++)
        D_01e35980[i] = 0;
    D_01e35800[0].func = (CmdHandler)func_003081f0;
    D_01e35800[0].data = &D_01e357d8;
    D_01e35800[1].func = (CmdHandler)func_003081d0;
    D_01e35800[1].data = &D_01e357d8;
    EIntr();
    func_003058a0(0);
    if (*(volatile unsigned int *)0x1000e010 & 0x20)
        *(volatile unsigned int *)0x1000e010 = 0x20;
    if (!(*(volatile unsigned int *)0x1000c000 & 0x100))
        func_00305a00();
    D_01e357d4 = func_00305330(5, func_00308938, 0);
    EnableDmac(5);
    r = func_00305a30(0x80000000);
    D_01e357d8.iopbuf = (void *)r;
    if (r) {
        D_01e357c0.buf = D_01e35700;
        sceSifSendCmd(0x80000000, &D_01e357c0, 20, 0, 0, 0);
        return;
    }
    while (!(func_00305a30(4) & 0x20000))
        ;
    r = func_00305a30(2);
    D_01e357d8.iopbuf = (void *)r;
    func_00305a20(0x80000000, r);
    func_00305a20(0x80000001, (unsigned int)&D_01e357d8);
    {
    /* register pin: the original keeps the buffer address in v0 and the packet address in v1 */
    register void *b asm("$2") = D_01e35700;
    D_01e357c0.buf = b;
    D_01e357c0.opt = 0;
    sceSifSendCmd(0x80000002, &D_01e357c0, 20, 0, 0, 0);
    }
}

/* ---- 0x308650 */
extern int DisableDmac(int);
extern int func_00305350(int, int);
void func_00308650(void)
{
    DisableDmac(5);
    func_00305350(5, D_01e357d4);
    D_003660d8 = 0;
}

/* ---- 0x308688 (gap) */
SysCmd *func_00308688(SysCmd *tbl, int n)
{
    SysCmd *old = D_01e357d8.usr;
    D_01e357d8.usr = tbl;
    D_01e357d8.nusr = n;
    return old;
}

/* ---- 0x3086a0 (gap) */
SysCmd *func_003086a0(SysCmd *tbl, int n)
{
    SysCmd *old = D_01e357d8.sys;
    D_01e357d8.sys = tbl;
    D_01e357d8.nsys = n;
    return old;
}
