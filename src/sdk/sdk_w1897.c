/* Sony PS2 Runtime Library 3.0.0: libkernl (deci2 kputs). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { volatile int id; volatile int size; int x8; volatile int busy; char *buf; } Kp;
extern Kp D_01e353d0;
extern char D_01e35400[];
extern int DIntr(void);
extern void EIntr(void);
extern int func_00311050(int, char);
extern void func_00311080(int);
int func_00306b40(const char *src, int n);  // 0x00306b40: definition moved into src/sdk/libkernl_00306698.c
