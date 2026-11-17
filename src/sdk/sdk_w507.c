/* Sony PS2 Runtime Library 3.0.0: libkernl. Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int p0, p4, p8, pc; unsigned int flags; int p14; int p18; } Sem;
void func_00308da0(Sem *s) { s->p18 = 0; s->flags &= ~1; }

typedef struct { int a; int b; int *c; int *d; int buf[1]; } Hdr;
extern Hdr D_01e352c0;
Hdr* func_00306900(int x)
{
    Hdr *h = &D_01e352c0;
    h->a = x;
    h->b = 0;
    h->d = h->buf;
    h->c = h->buf;
    return h;
}

extern int D_003660dc;
extern void func_00308650(void);
void func_00308cd0(void) { func_00308650(); D_003660dc = 0; }

unsigned int func_002f3588(unsigned int a);  // 0x002f3588: definition moved into src/sdk/libdma.c

extern int D_00363c90[];
int ctarget_002f35e8(unsigned int a) asm("_Z16ctarget_002f35e8jjjj");
int ctarget_002f35e8(unsigned int a);  // 0x002f35e8: definition moved into src/sdk/libdma.c

extern void func_0030f468(int);
int func_00305df8(int a, int b);  // 0x00305df8: definition moved into src/sdk/glue.c

extern int* func_00316d08(void);
int func_00305e20(void);  // 0x00305e20: definition moved into src/sdk/glue.c
