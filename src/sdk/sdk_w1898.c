/* libkernl (Sony PS2 Runtime Library 3.0.0): pooled entry alloc */
typedef struct { int x0, x4, x8, xc; int flags; void *self; int id; int pad[9]; } Ent_w1898;
typedef struct { int seq; Ent_w1898 *ents; int n; } Pool_w1898;
extern int DIntr(void);
extern int EIntr(void);

Ent_w1898* func_00308cf8(Pool_w1898 *p);  // 0x00308cf8: definition moved into src/sdk/libkernl_00308b30.c
