/* libkernl_00306580.c: Sony PS2 Runtime Library 3.0.0 libkernl: top-thread request, 0x306580-0x3065fc.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
typedef unsigned int u32;
typedef char *va_list;
#define va_start(v,l) (v = (va_list)__builtin_next_arg(l) - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
extern int DIntr(void);
extern int EIntr(void);

extern int D_003660d0;
extern int D_01e34e80;
typedef struct { int p0; u32 idx; struct { unsigned char a, b; } q[512]; } Ring;
extern Ring D_01e34e88;
extern int func_00305650(int);
int func_00306580(u32 c)
{
    int i;
    if (c >= 128 || D_003660d0 == 0)
        return -1;
    i = D_01e34e88.idx & 0x1ff;
    D_01e34e88.idx = i + 1;
    D_01e34e88.q[i].a = 1;
    D_01e34e88.q[i].b = c;
    func_00305650(D_01e34e80);
    return c;
}

