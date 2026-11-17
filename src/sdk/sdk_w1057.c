/* Sony PS2 Runtime Library 3.0.0: libkernl / libcdvd / libmc helpers. Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int p0, p4, p8, pc; volatile unsigned int p10; } Q;
extern int D_003767d0;
extern void func_003080d0(void *);
extern void func_002f3c28(Q *);
void func_002f3500(Q *q, unsigned int n, int t);  // 0x002f3500: definition moved into src/sdk/libdma.c

typedef struct N { struct N *next; struct N *prev; int p8, pc; unsigned long long a; unsigned long long b; unsigned long long c; } N;
typedef struct { int pad[6]; N *head; } NL;
extern NL D_00367118;
void func_0030fba0(N *n);  // 0x0030fba0: definition moved into src/sdk/libkernl_0030f688.c

extern int DIntr(void);
extern void EIntr();
extern unsigned char func_00308248(int, int, int);
extern unsigned char func_003059e0(int, int);
extern int D_003660d8;
int func_00308310(int a, int b);  // 0x00308310: definition moved into src/sdk/libkernl_003081d0.c

extern char D_01e33a40[];
extern int D_00365950;
extern unsigned int strlen(char *);
extern char* memcpy(char *, char *, unsigned int);
extern void func_00305650(int);
void func_002fc7d8(char *buf);  // 0x002fc7d8: definition moved into src/sdk/libmc.c

extern int memcmp(void *, void *, int);
extern char D_003660c4[];
extern char *D_00366178;
extern char D_01e389a8[];
int func_0030a600(void);  // 0x0030a600: definition moved into src/sdk/filestub.c

extern char *D_00366184;
extern char D_01e38e68[];
int func_0030de70(void);  // 0x0030de70: definition moved into src/sdk/eeloadfile.c

typedef struct L { int pad[5]; struct L *next; } L;
typedef struct { int pad[10]; L *head; } LH;
extern LH D_01e37200;
L* func_003098f8(L *n);  // 0x003098f8: definition moved into src/sdk/libkernl_00309860.c

extern int func_0030dd70(void);
extern int sceSifCallRpc(void *, int, int, int *, int, int *, int, int, int);
extern int D_01e38c40;
extern char D_01e38e40[];
int func_0030e348(int a);  // 0x0030e348: definition moved into src/sdk/eeloadfile.c
int func_0030e478(int a);  // 0x0030e478: definition moved into src/sdk/eeloadfile.c
