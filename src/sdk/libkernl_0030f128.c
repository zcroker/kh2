/* libkernl_0030f128.c: Sony PS2 Runtime Library 3.0.0 libkernl: kernel patch (0x80074000 area), 0x30f128-0x30f23c.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */

/* ---- 0x30f128 */
extern void func_003056d0(unsigned int *);
extern void func_003056c0(unsigned int *);
int func_0030f128(void)
{
    unsigned int old, v;
    func_003056d0(&old);
    v = (old & 0xffff1fff) | 0x2000;
    func_003056c0(&v);
    func_003056d0(&v);
    func_003056c0(&old);
    return ((v >> 13) & 7) == 0;
}

/* ---- 0x30f190 */
typedef struct { int a, b; } P;
extern P D_00366950[];
extern char D_003661a8[];
extern void func_0030f0c0(int, int);
extern void func_0030f0d0(int, void *, int);
extern int func_0030f118(int);
extern void func_003058a0(int);
void func_0030f190(void)
{
    unsigned int i;
    if (func_0030f128() == 0)
        return;
    func_0030f0c0(D_00366950[0].a, D_00366950[0].b);
    func_0030f0d0(0x80074000, D_003661a8, 1960);
    func_003058a0(0);
    func_003058a0(2);
    func_0030f0c0(D_00366950[1].a, D_00366950[1].b);
    for (i = 2; i < 3; i++)
        func_0030f0c0(D_00366950[i].a, func_0030f118(D_00366950[i].a));
}
