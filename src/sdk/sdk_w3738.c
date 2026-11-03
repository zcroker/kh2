/* Sony PS2 Runtime Library: libkernl (sifcmd). Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License. */
/* 003083d0 is sceSifInitCmd. Field types matter: ee-gcc 2.9 -O2 uses type-based aliasing, so the
 * handler/data and cmdbuf/iopbuf types decide which stores the scheduler may move. */
typedef void (*CmdHandler)(void *, void *);
typedef struct { CmdHandler func; void *data; int x8; } SysCmd;
typedef struct { unsigned int pktbuf; void *cmdbuf; void *iopbuf; SysCmd *sys; int nsys; SysCmd *usr; int nusr; int *sregs; } CmdData;
typedef struct { unsigned int size; unsigned int dest; int cid; unsigned int opt; void *buf; } CaPkt;
extern int D_003660d8;
extern CmdData D_01e357d8;
extern SysCmd D_01e35800[];
extern int D_01e35980[];
extern char D_01e35700[];
extern char D_01e35780[];
extern CaPkt D_01e357c0;
extern int D_01e357d4;
extern void func_003081f0(void *, void *);
extern void func_003081d0(void *, void *);
extern int func_00308938(int);
extern void func_0030edb0(void);
extern void func_0030ee00(void);
extern void func_003058a0(int);
extern void func_00305a00(void);
extern int func_00305330(int, void *, int);
extern int func_00306238(int);
extern unsigned int func_00305a30(unsigned int);
extern void func_00305a20(unsigned int, unsigned int);
extern int func_003088b8(unsigned int, void *, int, void *, void *, int);

void func_003083d0(void)
{
    int i;
    unsigned int r;
    func_0030edb0();
    if (D_003660d8) {
        func_0030ee00();
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
    func_0030ee00();
    func_003058a0(0);
    if (*(volatile unsigned int *)0x1000e010 & 0x20)
        *(volatile unsigned int *)0x1000e010 = 0x20;
    if (!(*(volatile unsigned int *)0x1000c000 & 0x100))
        func_00305a00();
    D_01e357d4 = func_00305330(5, func_00308938, 0);
    func_00306238(5);
    r = func_00305a30(0x80000000);
    D_01e357d8.iopbuf = (void *)r;
    if (r) {
        D_01e357c0.buf = D_01e35700;
        func_003088b8(0x80000000, &D_01e357c0, 20, 0, 0, 0);
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
    func_003088b8(0x80000002, &D_01e357c0, 20, 0, 0, 0);
    }
}
