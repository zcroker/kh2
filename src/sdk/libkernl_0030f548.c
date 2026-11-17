/* libkernl_0030f548.c: Sony PS2 Runtime Library 3.0.0 libkernl: kernel patch (0x80076000 area), 0x30f548-0x30f61c.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
typedef struct { int a; int b; } G1328;
extern G1328 D_003670d8[];
extern char D_00366970[];
extern char D_003670b0[];
extern void func_0030f4e0(int, int);
extern void func_0030f4f0(int, void *, int);
extern int func_0030f538(int);
extern void func_003058a0(int);
void func_0030f548(void)
{
    unsigned int i;
    if (*(volatile int *)0x10001810 & 0x100) return;
    func_0030f4e0(D_003670d8[0].a, D_003670d8[0].b);
    func_0030f4f0(0x80076000, D_00366970, 0x740);
    func_0030f4f0(0x82000, D_003670b0, 0x28);
    func_003058a0(0);
    func_003058a0(2);
    func_0030f4e0(D_003670d8[1].a, D_003670d8[1].b);
    for (i = 2; i < 8; i++)
        func_0030f4e0(D_003670d8[i].a, func_0030f538(D_003670d8[i].a));
}
