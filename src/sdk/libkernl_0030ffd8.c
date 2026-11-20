/* libkernl_0030ffd8.c: Sony PS2 Runtime Library 3.0.0 libkernl: timer allocator (takes a block off the free list), 0x30ffd8-0x310048.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
typedef struct Blk_w30ffd8 {
    struct Blk_w30ffd8 *next;
    int x4;
    volatile unsigned int id;
    int flags;
    int x10, x14;
    long x18;
    int x20, x24;
    void *x28;
} Blk_w30ffd8;
typedef struct {
    int x0, x4, x8;
    volatile int serial;
    volatile int count;
    Blk_w30ffd8 *free;
} Mgr_w30ffd8;
extern Mgr_w30ffd8 D_00367118_c asm("D_00367118");

/* ---- 0x30ffd8 */
int func_0030ffd8(void)
{
    Blk_w30ffd8 *b = D_00367118_c.free;
    int n;
    if (!b)
        return 0x80008005;
    n = D_00367118_c.count + 1;
    b->x28 = 0;
    D_00367118_c.count = n;
    b->flags = 0;
    D_00367118_c.free = b->next;
    D_00367118_c.serial++;
    b->x18 = 0;
    b->id = ((D_00367118_c.serial << 1) & 0x3fe) | 1;
    return ((unsigned)b << 4) | b->id;
}
