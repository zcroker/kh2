/* Sony PS2 Runtime Library 3.0.0: libkernl deci2 TTY read/write hooks (fd 0 read, fd 1/2 write). ee-gcc 2.9-991111 -O2 -G0. */
extern int func_00306d88(void);
extern int func_00306b40(int a, int b);
extern int func_00306cb8(int a, int b);
extern int D_003660c8;

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
