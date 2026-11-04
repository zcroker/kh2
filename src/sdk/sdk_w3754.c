/* Sony PS2 Runtime Library: libkernl request-queue service thread (00306320). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { unsigned int count; int pad; unsigned char type[1]; unsigned char arg[1]; } Queue_w3754;
extern int D_01e34e80;
extern char D_00377e28[]; /* "## internel error in libkernl.a!\n" */
extern void func_00305660(int);
extern void func_003054d0(int);
extern void func_00305550(int);
extern void func_00305590(int);
extern void func_00308150(const char *);

void func_00306320(Queue_w3754 *s)
{
    unsigned char *b = s->type;
    unsigned char *a = s->arg;
    int i;
    /* partial asm: pin and empty barrier steer allocation and scheduling only */
    register int j asm("$4");
    int t;
    unsigned char *p;
    for (;;) {
        func_00305660(D_01e34e80);
        i = s->count;
        i &= 0x1ff;
        j = i + 1;
        i <<= 1;
        asm volatile("");
        s->count = j;
        p = i + b;
        t = *p;
        switch (t) {
        case 0: func_00305550(a[i]); break;
        case 1: func_003054d0(a[i]); break;
        case 2: func_00305590(a[i]); break;
        default: func_00308150(D_00377e28); break;
        }
    }
}
