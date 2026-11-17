/* libkernl_003114f0.c: Sony PS2 Runtime Library 3.0.0 libkernl: TLB init dispatch, 0x3114f0-0x311530.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
extern int func_00305a80(void);
extern int func_00311530(void);
extern int func_00305a90(void);
int func_003114f0(void)
{
    if (func_00305a80() == 0x2000000) return func_00311530();
    return func_00305a90();
}
