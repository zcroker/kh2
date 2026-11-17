/* glue.c: Sony PS2 Runtime Library 3.0.0 libkernl, the newlib system-call glue (part of the object from 0x305be8:
 * write/read through the Deci2 TTY, the stubs, sbrk, isatty, fstat, getpid, kill). ee-gcc 2.9-991111 -O2 -G0.
 * Linked unit 0x305be8-0x305e70 (the object starts earlier: 0x305aa0, 0x305ab0 and whole-asm 0x305b40 stay outside).
 * Third-party code notice: this is a routine from Sony Computer Entertainment's PlayStation 2 Runtime Library that
 * the game links, rebuilt to match. It is not covered by this project's MIT License. */
extern int func_00306d88(void);
extern int func_00306b40(int a, int b);
extern int func_00306cb8(int a, int b);
extern int *func_00316d08(void);
extern unsigned int func_00305600(void);
extern void func_0030f468(int);
extern int D_003660c8;
extern char *D_003660cc;

int func_00305be8(int fd, int a, int b)
{
    if (fd != 1 && fd != 2)
        goto fail;
    if (D_003660c8 == 0) {
        if (func_00306d88() == 0)
            goto fail;
        D_003660c8 = 1;
    }
    return func_00306b40(a, b);
fail:
    return -1;
}

int func_00305c68(int fd, int a, int b)
{
    if (fd != 0)
        goto fail;
    if (D_003660c8 == 0) {
        if (func_00306d88() == 0)
            goto fail;
        D_003660c8 = 1;
    }
    return func_00306cb8(a, b);
fail:
    return -1;
}

int func_00305ce0(void) { *func_00316d08() = 5; return -1; }

int func_00305d08(int fd) { return -1; }

int func_00305d10(void) { return -1; }

int func_00305d18(int fd, int off, int whence) { return -1; }

void *func_00305d20(int incr)
{
    int st, x;
    char *old, *nw;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    st &= 0x10000;
    if (st) {
        do {
            asm volatile("di");
            asm volatile("sync.p");
            asm volatile("mfc0 %0, $12" : "=r"(x));
        } while (x & 0x10000);
    }
    nw = D_003660cc + incr;
    if (func_00305600() < (unsigned int)nw) {
        *func_00316d08() = 12;
        if (st)
            asm volatile("ei");
        return (void *)-1;
    }
    old = D_003660cc;
    D_003660cc = nw;
    if (st)
        asm volatile("ei");
    return old;
}

int func_00305dd0(int fd) { return 1; }

struct stat_ { short st_dev; unsigned short st_ino; unsigned int st_mode; char pad[64]; long st_blksize; };
int func_00305dd8(int fd, struct stat_ *st)
{
    st->st_mode = 0x2000;
    st->st_blksize = 0;
    return 0;
}

int func_00305df0(void) { return 1; }

int func_00305df8(int a, int b)
{
    if (a == 1)
        func_0030f468(b);
    return 0;
}

int func_00305e20(void) { *func_00316d08() = 5; return -1; }

int func_00305e48(void) { *func_00316d08() = 5; return -1; }
