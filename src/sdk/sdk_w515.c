/* Sony PS2 Runtime Library 3.0.0: libkernl (0x30xxxx/0x310xxx) plus libvu0/RPC-client helpers (0x2f4xxx-0x2f6xxx). ee-gcc 2.9-991111 -O2 -G0. */
extern int DIntr(void);
extern int EIntr(void);

extern int func_00310090(int);
int func_00310130(int a);  // 0x00310130: definition moved into src/sdk/libkernl_00310048.c

extern int func_00310230(int);
int func_003102e0(int a);  // 0x003102e0: definition moved into src/sdk/libkernl_00310048.c

extern int func_00310330(int);
int func_003103f8(int a);  // 0x003103f8: definition moved into src/sdk/libkernl_00310048.c

extern int func_00310518(int);
int func_00310560(int a);  // 0x00310560: definition moved into src/sdk/libkernl_00310048.c

extern int func_003105b0(int);
int func_00310620(int a);  // 0x00310620: definition moved into src/sdk/libkernl_00310048.c

typedef struct E { struct E *next; int a, b, c; } E;
extern E D_01e3af00[64];
extern E *D_01e3b300;
int func_00310990(void);  // 0x00310990: definition moved into src/sdk/libkernl_00310048.c

extern void sceVu0RotMatrixZ(void *, float);
extern void* sceVu0RotMatrixY(void *, void *, float);
extern void sceVu0RotMatrixX(void *, void *, float);
void sceVu0RotMatrix(void *a, void *b, float *v);  // 0x002f4298: definition moved into src/sdk/libvu0_002f4298.c

extern int func_00305a30(int);
extern int func_00305aa0(void);
extern int func_00310f38(int, int);
int func_0030ec50(void);  // 0x0030ec50: definition moved into src/sdk/iopreset.c

struct S7118 { int a, b, c, d, e; };
extern struct S7118 D_00367118;
int func_00310180(int *p, int *q);  // 0x00310180: definition moved into src/sdk/libkernl_00310048.c

extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, int, int);
extern char D_01e2d980[];
extern int D_01e2da80[];
int func_002f4a20(void);  // 0x002f4a20: definition moved into src/sdk/libdbc.c

typedef struct { int a; int b; int c; int d; char pad[820 - 16]; } Ent;
extern Ent D_01e2fe48[];
extern int sceDbcGetDepNumber(int);
int func_002f62b8(int i);  // 0x002f62b8: definition moved into src/sdk/libpad2.c
