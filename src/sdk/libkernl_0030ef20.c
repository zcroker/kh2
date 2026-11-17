/* libkernl_0030ef20.c: Sony PS2 Runtime Library 3.0.0 libkernl: kernel patch helpers, 0x30ef20-0x30f054.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */

/* ---- 0x30ef20 */
extern int *D_00366188_p asm("D_00366188");
extern void func_0030ee88(void *, void *, int);
int func_0030ef20(int i)
{
    int v;
    func_0030ee88(&v, D_00366188_p + i, 4);
    return v;
}

/* ---- 0x30ef58 */
extern unsigned int func_0030ef10(unsigned int, unsigned int, void *);
extern void func_0030f058(int, int);
extern int D_0030eed0[];
extern int D_0030ee98[];
extern int D_00366190[4];
extern unsigned int D_00366188;
void func_0030ef58(void)
{
    unsigned int a, b, pa, pb;
    func_0030f058(D_00366190[0], D_00366190[1]);
    func_0030f058(D_00366190[2], D_00366190[3]);
    a = func_0030ef10(0x80000000, 0x80080000, D_0030eed0);
    b = func_0030ef10(0x80000000, 0x80080000, D_0030ee98);
    pa = a - 0x20c;
    pb = b - 0x168;
    while (pa != pb) {
        if (pa < pb) {
            a = func_0030ef10(a + 4, 0x80080000, D_0030eed0);
            pa = a - 0x20c;
        } else {
            b = func_0030ef10(b + 4, 0x80080000, D_0030ee98);
            pb = b - 0x168;
        }
    }
    D_00366188 = pa;
}
