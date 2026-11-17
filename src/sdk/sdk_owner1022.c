/* Sony PS2 Runtime Library 3.0.0: libkernl (sifcmd). Built with ee-gcc 2.9-991111 -O2 -G0. */

/* sifcmd/sifrpc (libkernl) */
struct H1324 { unsigned short a; unsigned short b; unsigned short size; unsigned char c; unsigned char d; int e; };
struct D1324 { volatile int id; volatile int a; volatile int b; volatile int c; struct H1324 *h; void *buf; int x; };
extern struct D1324 D_01e353d0;
extern char D_01e35400[];
extern char D_01e35540[];
extern void func_003058a0(int);
extern int func_00310fe0(int, void *, void *);
extern int func_00306900(int);
extern void func_003069a8(void);
int func_00306d88(void);  // 0x00306d88: definition moved into src/sdk/libkernl_00306698.c
