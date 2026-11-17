/* exit.c: newlib libc (libc/stdlib/exit.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2fd348-0x2fd3d0. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "newlib.h"
asm("_exit = func_001002a0");
void _exit(int) __attribute__((noreturn));

void exit(int code)
{
    register struct _atexit *p;
    register int n;

    for (p = _impure_ptr->_atexit; p; p = p->_next)
        for (n = p->_ind; --n >= 0;)
            (*p->_fns[n])();
    if (_impure_ptr->__cleanup)
        (*_impure_ptr->__cleanup)(_impure_ptr);
    _exit(code);
}
