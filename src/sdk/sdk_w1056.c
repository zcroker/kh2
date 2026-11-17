/* Sony PS2 Runtime Library 3.0.0: libkernl (0x305xxx-0x310xxx: SIF RPC, timers, deci2/printf) and 0x2f3xxx/0x2f6xxx lib helpers. Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef unsigned int u32;
typedef char *va_list;
#define va_start(v,l) (v = (va_list)__builtin_next_arg(l) - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
extern int DIntr(void);
extern int EIntr(void);

extern int D_003660d0;
extern int D_01e34e80;
typedef struct { int p0; u32 idx; struct { unsigned char a, b; } q[512]; } Ring;
extern Ring D_01e34e88;
extern int func_00305650(int);
int func_00306580(u32 c);  // 0x00306580: definition moved into src/sdk/libkernl_00306580.c

extern void func_00309be8(void);
extern int func_00305660(int);
extern int func_00305640(int);
extern int D_00366170;
typedef struct { int a; int b; int c; int d; } Ent;
extern Ent D_01e38780[];
int func_00309c58(void);  // 0x00309c58: definition moved into src/sdk/libkernl_00309860.c

extern int D_0036617c;
extern int D_01e38b00;
extern char D_01e38a80[];
extern int D_01e38ac0;
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
u32 func_0030dc70(int a);  // 0x0030dc70: definition moved into src/sdk/iopheap.c
u32 func_0030dcf0(int a);  // 0x0030dcf0: definition moved into src/sdk/iopheap.c

extern void func_0030f6a0(u32);
int func_0030f990(void);  // 0x0030f990: definition moved into src/sdk/libkernl_0030f688.c

extern int func_00310670(int, int, int, int);
int func_00310768(int a, int b, int c, int d);  // 0x00310768: definition moved into src/sdk/libkernl_00310048.c

typedef struct { int flags; int p4, p8, pc; u32 x10; int p14, p18, p1c; int x20; } Fd;
extern int func_002f3588(int);
extern void func_002f3490(Fd *);
void func_002f3b38(Fd *f, int a, int b);  // 0x002f3b38: definition moved into src/sdk/libdma.c

extern int D_00363dc8;
extern int D_01e331c8;
extern int D_01e331cc;
extern int D_01e331d0;
extern void func_002f6c28(void);
int func_002f6b50(int a, int b);  // 0x002f6b50: definition moved into src/sdk/libcdvd_002f6870.c

extern int func_003071d0(void *, void *, u32, const char *, va_list);
extern int func_00307f40();
extern int func_00307f68();
void ctarget_003080d0(const char *fmt, ...) asm("_Z16ctarget_003080d0jjjj");
void ctarget_003080d0(const char *fmt, ...);  // 0x003080d0: definition moved into src/sdk/kprintf.c
void func_00308150(const char *fmt, ...);  // 0x00308150: definition moved into src/sdk/kprintf.c

typedef struct { int a, b, c; } Arg3;
extern Arg3 D_01e38b00x asm("D_01e38b00");
int func_0030d918(int a, int b, int c);  // 0x0030d918: definition moved into src/sdk/iopheap.c
