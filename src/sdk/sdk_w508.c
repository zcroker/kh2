/* Sony PS2 Runtime Library 3.0.0: libkernl (EE kernel wrappers). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef unsigned int u32;

extern int* func_00316d08(void);
int func_00305e48(void);  // 0x00305e48: definition moved into src/sdk/glue.c

extern void func_00305650(int);
int func_003068d8(int a, int b, int c, int d);  // 0x003068d8: definition moved into src/sdk/libkernl_00306698.c

extern void func_00306e80(int);
int func_00307f40(int a, int b, int c);  // 0x00307f40: definition moved into src/sdk/kprintf.c

extern void func_00306f30(int);
int func_00307f68(int a, int b, int c);  // 0x00307f68: definition moved into src/sdk/kprintf.c

extern int func_00305a30(int);
int func_0030ec28(void);  // 0x0030ec28: definition moved into src/sdk/iopreset.c

extern void func_0030f3a8(int);
extern void func_00305240(int);
void func_0030f468(int a);  // 0x0030f468: definition moved into src/sdk/libkernl_0030f290.c

extern void func_0030a278(void);
extern void func_00305660(int);
extern int D_0036616c;
int func_0030a2d0(void);  // 0x0030a2d0: definition moved into src/sdk/libkernl_00309860.c

typedef struct { char d[64]; } Entry;
typedef struct { char pad0[0x14]; Entry *base; int n; char pad1[8]; int idx; } EntryRing;
Entry* func_00308dc0(EntryRing *q);  // 0x00308dc0: definition moved into src/sdk/libkernl_00308b30.c

extern int func_00305a50(int, void *);
int func_00311050(int a, char b);  // 0x00311050: definition moved into src/sdk/libkernl_00310fe0.c
int func_003110a8(unsigned char a, int b, int c);  // 0x003110a8: definition moved into src/sdk/libkernl_00310fe0.c

extern int func_00311450(int);
int func_00311460(int x);  // 0x00311460: definition moved into src/sdk/libkernl_00311460.c
