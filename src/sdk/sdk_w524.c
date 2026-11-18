/* Sony PS2 Runtime Library 3.0.0: libkernl. Built with ee-gcc 2.9-991111 -O2 -G0. */
extern int DIntr(void);
extern void EIntr(void);
extern int func_00305370(int);
int DisableIntc(int a);  // 0x00306100: definition moved into src/sdk/libkernl_00306058.c

extern int func_00305360(int);
int EnableIntc(int a);  // 0x00306168: definition moved into src/sdk/libkernl_00306058.c

extern int func_00305390(int);
int DisableDmac(int a);  // 0x003061d0: definition moved into src/sdk/libkernl_00306058.c

extern int func_00305380(int);
int EnableDmac(int a);  // 0x00306238: definition moved into src/sdk/libkernl_00306058.c

extern int func_002f3588(int);
extern void func_002f3490(int *);
void func_002f3918(int *p, int b);  // 0x002f3918: definition moved into src/sdk/libdma.c

extern void sceVu0CopyVector(int, int);
void func_002f4480(int p, int a, int b, int c, int d);  // 0x002f4480: definition moved into src/sdk/libvu0_002f4310.c

extern void func_003056d0(unsigned int *);
extern void func_003056c0(unsigned int *);
int func_0030f128(void);  // 0x0030f128: definition moved into src/sdk/libkernl_0030f128.c

extern int D_00363d28;
extern int D_01e2fe48[];
extern int func_002f5e20(int);
int func_002f5cb0(void);  // 0x002f5cb0: definition moved into src/sdk/libpad2.c

extern int func_002f71b0(int);
extern int D_01e331c0;
extern int D_01e331c4;
int func_002f6698(int a);  // 0x002f6698: definition moved into src/sdk/libcdvd_002f6698.c

extern int D_00363d90;
extern int D_00376c90;
extern int D_00365900;
extern void func_003080d0(int *);
extern void func_00306698(int);
extern int func_003096b8(int *);
int func_002f7250(int a);  // 0x002f7250: definition moved into src/sdk/libcdvd_002f6870.c
