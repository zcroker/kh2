/* atexit.c: newlib libc (libc/stdlib/atexit.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2fd188-0x2fd220. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#include "newlib.h"
void *malloc(size_t);

int atexit(void (*fn)(void))
{
    register struct _atexit *p;

    if ((p = _impure_ptr->_atexit) == NULL)
        _impure_ptr->_atexit = p = &_impure_ptr->_atexit0;
    if (p->_ind >= 32) {
        if ((p = (struct _atexit *)malloc(sizeof *p)) == NULL)
            return -1;
        p->_ind = 0;
        p->_next = _impure_ptr->_atexit;
        _impure_ptr->_atexit = p;
    }
    p->_fns[p->_ind++] = fn;
    return 0;
}
