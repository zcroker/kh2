/* Sony PS2 Runtime Library 3.0.0: libdbc (sceDbc*Socket/GetDeviceStatus), libvu0 (CameraMatrix), libpad2, libkernl (sbrk, printf buffer, thread/sema helpers). ee-gcc 2.9-991111 -O2 -G0. */
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
extern int func_002f5c48(const char *, ...);
extern int func_00305660(int);
extern int func_00305640(int);
extern int D_01e2fe40;
extern char D_01e2d980[];
extern int D_01e2da80[];
int sceDbcInitSocket(int x);  // 0x002f5288: definition moved into src/sdk/libdbc.c

int sceDbcResetSocket(int x);  // 0x002f5338: definition moved into src/sdk/libdbc.c

int sceDbcGetDeviceStatus(int x);  // 0x002f53e8: definition moved into src/sdk/libdbc.c

typedef struct { int on, kind, x8, xc; } E;
int func_002f6440(unsigned char *bits, E *e);  // 0x002f6440: definition moved into src/sdk/libpad2.c

typedef float V4[4] __attribute__((aligned(16)));
extern void sceVu0UnitMatrix(V4 *);
extern void sceVu0OuterProduct(float *, float *, float *);
extern void sceVu0Normalize(float *, float *);
extern void sceVu0TransMatrix(V4 *, V4 *, float *);
extern void sceVu0InversMatrix(V4 *, V4 *);
void func_002f4310(V4 *m, float *p, float *zd, float *yd);  // 0x002f4310: definition moved into src/sdk/libvu0_002f4310.c

typedef struct { int a, b; } P;
extern P D_00366950[];
extern char D_003661a8[];
extern int func_0030f128(void);
extern void func_0030f0c0(int, int);
extern void func_0030f0d0(int, void *, int);
extern int func_0030f118(int);
extern void func_003058a0(int);
void func_0030f190(void);  // 0x0030f190: definition moved into src/sdk/libkernl_0030f128.c

typedef struct { int x0, x4, x8, xc; long x10; } T;
typedef struct { char pad[0x1c]; int x1c; } G;
extern G D_00367118;
extern long func_0030ff08(void);
extern void func_0030fba0(T *);
extern void func_0030fa10(long);
int func_00310230(int id);  // 0x00310230: definition moved into src/sdk/libkernl_00310048.c

extern int D_003660d4;
extern char D_01e35680[];
extern void func_003111f0(char *);
void func_00306e80(int c);  // 0x00306e80: definition moved into src/sdk/kprintf.c

extern char *D_003660cc;
extern unsigned int func_00305600(void);
extern int* func_00316d08(void);
void* func_00305d20(int incr);  // 0x00305d20: definition moved into src/sdk/glue.c
