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
extern void DIntr(void);
extern void EIntr(void);
extern void func_003058a0(int);
extern void func_00305a00(void);
extern int func_00305330(int, void *, int);
extern int EnableDmac(int);
extern unsigned int func_00305a30(unsigned int);
extern void func_00305a20(unsigned int, unsigned int);
extern int sceSifSendCmd(unsigned int, void *, int, void *, void *, int);

void func_003083d0(void);  // 0x003083d0: definition moved into src/sdk/libkernl_003081d0.c
