/* abort.c: newlib libc (libc/stdlib/abort.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2fd160-0x2fd178. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "newlib.h"
asm("raise = func_002fed10");
asm("_exit = func_001002a0");
int raise(int);
void _exit(int) __attribute__((noreturn));

void abort(void)
{
    while (1) {
        raise(6 /* SIGABRT */);
        _exit(1);
    }
}
