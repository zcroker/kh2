/* libkernl_00305f18.c: Sony PS2 Runtime Library 3.0.0 libkernl: cache helpers (SyncDCache/InvalidDCache wrappers), 0x305f18-0x305fac.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
extern int DIntr(void);
extern int EIntr(void);
extern void func_00305e70(unsigned int, unsigned int);

/* ---- 0x305f18 */
void func_00305f18(unsigned int a, unsigned int b)
{
    int st;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st)
        DIntr();
    func_00305e70(a & 0xffffffc0, b & 0xffffffc0);
    if (st)
        EIntr();
}

/* ---- 0x305f98 (gap) */
void func_00305f98(unsigned int a, unsigned int b)
{
    func_00305e70(a & 0xffffffc0, b & 0xffffffc0);
}
