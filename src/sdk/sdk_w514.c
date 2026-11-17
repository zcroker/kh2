/* Sony PS2 Runtime Library 3.0.0: libkernl (sprintf family, kernel-table helpers; 0x2f3a70 is from the 0x2f3xxx lib block). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef char *va_list;
/* gcc 2.9 EABI va-mips.h va_start: register save area starts below the incoming args */
#define va_start(v,l) (v = (va_list)__builtin_next_arg(l) - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))

typedef struct { int f0; int f4, f8, fc, f10, f14, f18, f1c, f20; } Q;
extern void func_002f3490(Q *);
void func_002f3a70(Q *q);  // 0x002f3a70: definition moved into src/sdk/libdma.c

extern int D_01e3b508;
extern int func_00305a50(int, void *);
int func_00310fe0(unsigned int a, int b, int c);  // 0x00310fe0: definition moved into src/sdk/libkernl_00310fe0.c

extern int func_003071d0(void *, void *, int, const char *, va_list);
extern int func_00307ee8();
int func_00308018(char *buf, int n, const char *fmt, ...);  // 0x00308018: definition moved into src/sdk/kprintf.c

int func_00307f90(void *a, void *b, int *n, const char *fmt, ...);  // 0x00307f90: definition moved into src/sdk/kprintf.c

extern int DIntr(void);
extern int func_0030ffd8(void);
extern void EIntr(void);
int func_00310048(void);  // 0x00310048: definition moved into src/sdk/libkernl_00310048.c

typedef struct { int f0, f4, f8, fc; long f10, f18; } T;
long func_00310518(int id);  // 0x00310518: definition moved into src/sdk/libkernl_00310048.c

typedef struct { int a, b, c; } E;
extern E *D_01e357e4;
extern E *D_01e357ec;
void func_00308730(int x);  // 0x00308730: definition moved into src/sdk/libkernl_00308730.c

typedef struct N { int k; char pad[0x34]; struct N *next; } Nd;
typedef struct L { int p0, p4; Nd *head; int pc, p10; struct L *next; char pad[0x10]; struct L *sub; } Ls;
Nd* func_00309178(int k, Ls *l);  // 0x00309178: definition moved into src/sdk/libkernl_00308f00.c
