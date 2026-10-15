/* Sony PS2 Runtime Library 3.0.0: libkernl (EE kernel wrappers). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef unsigned int u32;

extern int* func_00316d08(void);
int func_00305e48(void) { *func_00316d08() = 5; return -1; }

extern void func_00305650(int);
int func_003068d8(int a, int b, int c, int d) { func_00305650(d); asm volatile("sync.l; ei"); return 0; }

extern void func_00306e80(int);
int func_00307f40(int a, int b, int c) { if (c) func_00306e80(c); return 1; }

extern void func_00306f30(int);
int func_00307f68(int a, int b, int c) { if (c) func_00306f30(c); return 1; }

extern int func_00305a30(int);
int func_0030ec28(void) { int r = func_00305a30(4); if (r & 0x10000) return 1; return 0; }

extern void func_0030f3a8(int);
extern void func_00305240(int);
void func_0030f468(int a) { func_0030f3a8(a); func_00305240(a); }

extern void func_0030a278(void);
extern void func_00305660(int);
extern int D_0036616c;
int func_0030a2d0(void) { func_0030a278(); func_00305660(D_0036616c); return 0; }

typedef struct { char d[64]; } Entry;
typedef struct { char pad0[0x14]; Entry *base; int n; char pad1[8]; int idx; } EntryRing;
Entry* func_00308dc0(EntryRing *q) { int i = q->idx % q->n; Entry *e = &q->base[i]; q->idx = i + 1; return e; }

extern int func_00305a50(int, void *);
int func_00311050(int a, char b) { int s[2]; s[0] = a; s[1] = b; return func_00305a50(3, s); }
int func_003110a8(unsigned char a, int b, int c) { int s[8]; s[0] = a; s[1] = b; s[2] = c; return func_00305a50(0x20, s); }

extern int func_00311450(int);
int func_00311460(int x) { if ((u32)(x - 13) >= 35) return -1; return func_00311450(x); }
