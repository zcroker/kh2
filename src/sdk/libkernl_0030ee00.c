/* libkernl_0030ee00.c: Sony PS2 Runtime Library 3.0.0 libkernl: EIntr and the libc semaphores, 0x30ee00-0x30ee84.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */

/* ---- 0x30ee00 */
int EIntr(void)
{
    int st;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    asm volatile("ei");
    return st != 0;
}

/* ---- 0x30ee18 */
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } SemaParam;
extern int func_00305620(SemaParam *p);
extern int D_003661a0;
extern int D_003661a4;
void func_0030ee18(void)
{
    SemaParam s1, s2;
    s1.max_count = 1;
    s1.init_count = 1;
    s1.option = (unsigned int)"SceKernelLibc";
    s2.max_count = 1;
    s2.init_count = 1;
    s2.option = (unsigned int)"SceKernelLibcEh";
    D_003661a0 = func_00305620(&s1);
    D_003661a4 = func_00305620(&s2);
}

/* ---- 0x30ee78 (gap) */
int func_0030ee78(void)
{
    return D_003661a4;
}
