/* Sony PS2 Runtime Library 3.0.0: libkernl. Built with ee-gcc 2.9-991111 -O2 -G0. */
extern int* func_00316d08(void);
int func_00305ce0(void);  // 0x00305ce0: definition moved into src/sdk/glue.c

typedef struct { int size; int count; int pad8; char *wp; char buf[1]; } Ring;
void func_00306928(Ring *r);  // 0x00306928: definition moved into src/sdk/libkernl_00306698.c

extern int D_003660d8;
extern int func_00308248(int, int, int);
extern int func_003059f0(int, int);
int func_00308398(int a, int b);  // 0x00308398: definition moved into src/sdk/libkernl_003081d0.c

typedef struct Node { char pad[60]; struct Node *next; } Node;
typedef struct { int pad0; int ok; int pad8; Node *free; } Pool;
extern void DIntr(void);
extern void EIntr(void);
Node* func_00309988(Pool *q);  // 0x00309988: definition moved into src/sdk/libkernl_00309860.c

