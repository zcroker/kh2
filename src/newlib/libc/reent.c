/* reent.c: newlib libc (libc/reent/reent.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x304b60-0x304d68. Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Cygnus Support.
 * The object also has the common symbol errno (0x378ae4 in .bss); it is left to the other files' D_00378ae4. */
#include "newlib.h"
void _free_r(struct _reent *, void *);
struct _Bigint { struct _Bigint *_next; };

void cleanup_glue(struct _reent *ptr, struct _glue *glue)
{
    /* Have to reclaim these in reverse order: */
    if (glue->_next)
        cleanup_glue(ptr, glue->_next);

    _free_r(ptr, glue);
}

void _reclaim_reent(struct _reent *ptr)
{
    if (ptr != _impure_ptr) {
        /* used by mprec routines. */
        if (ptr->_freelist) {
            int i;
            for (i = 0; i < 15 /* _Kmax */; i++) {
                struct _Bigint *thisone, *nextone;

                nextone = ptr->_freelist[i];
                while (nextone) {
                    thisone = nextone;
                    nextone = nextone->_next;
                    _free_r(ptr, thisone);
                }
            }

            _free_r(ptr, ptr->_freelist);
        }

        /* atexit stuff */
        if ((ptr->_atexit) && (ptr->_atexit != &ptr->_atexit0)) {
            struct _atexit *p, *q;
            for (p = ptr->_atexit; p != &ptr->_atexit0;) {
                q = p;
                p = p->_next;
                _free_r(ptr, q);
            }
        }

        if (ptr->_cvtbuf)
            _free_r(ptr, ptr->_cvtbuf);

        if (ptr->__sdidinit) {
            /* cleanup won't reclaim memory 'coz usually it's run
               before the program exits, and who wants to wait for that? */
            ptr->__cleanup(ptr);

            if (ptr->__sglue._next)
                cleanup_glue(ptr, ptr->__sglue._next);
        }

        /* Malloc memory not reclaimed; no good way to return memory anyway. */
    }
}

/*
 *  Do atexit() processing and cleanup
 *
 *  NOTE:  This is to be executed at task exit.  It does not tear anything
 *         down which is used on a global basis.
 */
void _wrapup_reent(struct _reent *ptr)
{
    register struct _atexit *p;
    register int n;

    if (ptr == 0)
        ptr = _impure_ptr;

    for (p = ptr->_atexit; p; p = p->_next)
        for (n = p->_ind; --n >= 0;)
            (*p->_fns[n])();
    if (ptr->__cleanup)
        (*ptr->__cleanup)(ptr);
}
