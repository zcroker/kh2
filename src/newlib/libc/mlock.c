/* mlock.c: newlib libc (libc/machine/r5900/mlock.c), the copy the game links from the toolchain's libc.a.
 * Linked unit 0x2fded8-0x2fdf88 with its .data at 0x3660a8. Malloc locking for the EE: interrupts are switched
 * off while the heap is in use, unless the caller is an interrupt handler. Third-party code notice: rebuilt to
 * match; not covered by this project's MIT License. */
#include "newlib.h"
asm("QueryIntrContext = func_003060f0");
int QueryIntrContext(void);
int DIntr(void);
int EIntr(void);

static int call_count = 0;
static int interupt_was_enable = 0;

void __malloc_lock(struct _reent *ptr)
{
    if (QueryIntrContext() != 1) {
        if (call_count == 0)
            interupt_was_enable = DIntr();
        call_count++;
    }
}

void __malloc_unlock(struct _reent *ptr)
{
    if (QueryIntrContext() != 1) {
        if (--call_count == 0) {
            if (interupt_was_enable) {
                interupt_was_enable = 0;
                EIntr();
            }
        }
    }
}
