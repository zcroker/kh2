/* Sony PS2 Runtime Library: libkernl request-queue service thread (00306320). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { unsigned int count; int pad; unsigned char type[1]; unsigned char arg[1]; } Queue_w3754;
extern int D_01e34e80;
extern char D_00377e28[]; /* "## internel error in libkernl.a!\n" */
extern void func_00305660(int);
extern void func_003054d0(int);
extern void func_00305550(int);
extern void func_00305590(int);
extern void func_00308150(const char *);

void func_00306320(Queue_w3754 *s);  // 0x00306320: definition moved into src/sdk/libkernl_00306058.c
