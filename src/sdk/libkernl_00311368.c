/* libkernl_00311368.c: Sony PS2 Runtime Library 3.0.0 libkernl: kernel patch (0x80075000 area), 0x311368-0x31142c.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
typedef unsigned int u32;
typedef struct { u32 a, v; } AV;
extern AV D_003674c0[];
extern int D_00367140;
extern u32 D_003674b8;
extern void func_00311358(u32, u32);
extern u32 func_00311348(u32);
extern void func_00311300(u32, void *, int);
extern void func_003058a0(int);
void func_00311368(void)
{
    u32 i;
    func_00311358(D_003674c0[0].a, D_003674c0[0].v);
    func_00311300(0x80075000, &D_00367140, 0x330);
    func_003058a0(0);
    func_003058a0(2);
    func_00311358(D_003674c0[1].a, D_003674c0[1].v);
    func_00311358(D_003674c0[2].a, D_003674c0[2].v);
    for (i = 3; i < 8; i++)
        func_00311358(D_003674c0[i].a, func_00311348(D_003674c0[i].a));
    D_003674b8 = func_00311348(3);
}
